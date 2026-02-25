/* ASM dump from: jccoefct.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jccoefct.c */

#include "common_types.h"
#include "imports.h"

static void start_pass_coef(j_compress_ptr cinfo, J_BUF_MODE pass_mode);
void jinit_c_coef_controller(j_compress_ptr cinfo, int need_full_buffer);
static boolean compress_data(j_compress_ptr cinfo, JSAMPIMAGE input_buf);
static boolean compress_output(j_compress_ptr cinfo, JSAMPIMAGE input_buf);
static boolean compress_first_pass(j_compress_ptr cinfo, JSAMPIMAGE input_buf);

/* line 101 */
static __attribute__((naked))
void start_pass_coef(j_compress_ptr cinfo, J_BUF_MODE pass_mode)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 101 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl 0xc(%ebp), %esi\n" /* pass_mode */
        "movl 0x14c(%ecx), %edi\n" /* line 102 | coef */
        "movl $0, 8(%edi)\n" /* line 104 | coef */
        /* { scope 2 */
        "movl 0x14c(%ecx), %edx\n" /* line 75 | coef */
        "cmpl $1, 0xe8(%ecx)\n" /* line 81 */
        "jle .Lf20a6b0_0020a75c\n"
        "movl $1, 0x14(%edx)\n" /* line 82 */
        ".Lf20a6b0_0020a6e7:\n"
        "movl $0, 0xc(%edx)\n" /* line 90 */
        "movl $0, 0x10(%edx)\n" /* line 91 */
        /* } scope */
        "cmpl $2, %esi\n" /* line 107 | pass_mode */
        "je .Lf20a6b0_0020a744\n"
        "cmpl $3, %esi\n" /* pass_mode */
        "je .Lf20a6b0_0020a77b\n"
        "testl %esi, %esi\n" /* pass_mode */
        "je .Lf20a6b0_0020a71c\n"
        "movl (%ecx), %eax\n" /* line 126 */
        "movl $4, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, 8(%ebp)\n" /* cinfo */
        "movl (%eax), %ecx\n"
        "addl $0x1c, %esp\n" /* line 129 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmpl *%ecx\n" /* line 126 */
        ".Lf20a6b0_0020a71c:\n"
        "movl 0x40(%edi), %esi\n" /* line 109 | coef, pass_mode */
        "testl %esi, %esi\n" /* pass_mode */
        "je .Lf20a6b0_0020a733\n"
        "movl (%ecx), %eax\n" /* line 110 */
        "movl $4, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf20a6b0_0020a733:\n"
        "leal 0x23d(%ebx), %eax\n" /* line 111 */
        "movl %eax, 4(%edi)\n" /* coef */
        "addl $0x1c, %esp\n" /* line 129 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20a6b0_0020a744:\n"
        "movl 0x40(%edi), %eax\n" /* line 120 | coef */
        "testl %eax, %eax\n"
        "je .Lf20a6b0_0020a7b6\n"
        ".Lf20a6b0_0020a74b:\n"
        "leal 0x56f(%ebx), %eax\n" /* line 122 */
        "movl %eax, 4(%edi)\n" /* coef */
        "addl $0x1c, %esp\n" /* line 129 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2 */
        ".Lf20a6b0_0020a75c:\n"
        "movl 0xe4(%ecx), %eax\n" /* line 84 */
        "subl $1, %eax\n"
        "cmpl %eax, 8(%edx)\n"
        "jb .Lf20a6b0_0020a793\n"
        "movl 0xec(%ecx), %eax\n" /* line 87 */
        "movl 0x48(%eax), %eax\n"
        "movl %eax, 0x14(%edx)\n"
        "jmp .Lf20a6b0_0020a6e7\n"
        /* } scope */
        ".Lf20a6b0_0020a77b:\n"
        "movl 0x40(%edi), %edx\n" /* line 115 | coef */
        "testl %edx, %edx\n"
        "je .Lf20a6b0_0020a7a4\n"
        ".Lf20a6b0_0020a782:\n"
        "leal 0x7e5(%ebx), %eax\n" /* line 117 */
        "movl %eax, 4(%edi)\n" /* coef */
        "addl $0x1c, %esp\n" /* line 129 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2 */
        ".Lf20a6b0_0020a793:\n"
        "movl 0xec(%ecx), %eax\n" /* line 85 */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, 0x14(%edx)\n"
        "jmp .Lf20a6b0_0020a6e7\n"
        /* } scope */
        ".Lf20a6b0_0020a7a4:\n"
        "movl (%ecx), %eax\n" /* line 116 */
        "movl $4, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf20a6b0_0020a782\n"
        ".Lf20a6b0_0020a7b6:\n"
        "movl (%ecx), %eax\n" /* line 121 */
        "movl $4, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf20a6b0_0020a74b\n"
    );
}

/* line 406 */
__attribute__((naked))
void jinit_c_coef_controller(j_compress_ptr cinfo, int need_full_buffer)
{
    __asm__ __volatile__ (
        /* { scope 1: ci, compptr */
        "pushl %ebp\n" /* line 406 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movzbl 0xc(%ebp), %esi\n" /* need_full_buffer */
        "movl 8(%ebp), %edx\n" /* line 409 | cinfo */
        "movl 4(%edx), %eax\n"
        "movl $0x68, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl %eax, %edi\n" /* coef */
        "movl 8(%ebp), %eax\n" /* line 412 | cinfo */
        "movl %edi, 0x14c(%eax)\n" /* coef */
        "leal -0x126(%ebx), %eax\n" /* line 413 */
        "movl %eax, (%edi)\n" /* coef */
        "movl %esi, %edx\n" /* line 416 | need_full_buffer */
        "testb %dl, %dl\n"
        "je .Lf20a7c8_0020a8bb\n"
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 423 | cinfo */
        "movl 0x48(%eax), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* compptr */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 0x40(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf20a7c8_0020a82d\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 449 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2 */
        ".Lf20a7c8_0020a82d:\n"
        "movl %edi, -0x1c(%ebp)\n" /* line 423 | coef */
        "movl $0, -0x24(%ebp)\n" /* ci */
        ".Lf20a7c8_0020a837:\n"
        "movl 8(%ebp), %edx\n" /* line 425 | cinfo */
        "movl 4(%edx), %eax\n"
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl -0x20(%ebp), %eax\n" /* compptr */
        "movl 0xc(%eax), %esi\n" /* need_full_buffer */
        "movl %esi, 4(%esp)\n" /* need_full_buffer */
        "movl 0x20(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll jround_up\n"
        "movl %eax, %edi\n" /* coef */
        "movl -0x20(%ebp), %edx\n" /* compptr */
        "movl 8(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x1c(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll jround_up\n"
        "movl %esi, 0x14(%esp)\n" /* need_full_buffer */
        "movl %edi, 0x10(%esp)\n" /* coef */
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll *-0x28(%ebp)\n"
        "movl -0x1c(%ebp), %edx\n"
        "movl %eax, 0x40(%edx)\n"
        "addl $1, -0x24(%ebp)\n" /* line 424 | ci */
        "addl $0x54, -0x20(%ebp)\n" /* compptr */
        "addl $4, %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl -0x24(%ebp), %edx\n" /* line 423 | ci */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "cmpl %edx, 0x40(%eax)\n"
        "jg .Lf20a7c8_0020a837\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 449 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20a7c8_0020a8bb:\n"
        "movl 8(%ebp), %edx\n" /* line 441 | cinfo */
        "movl 4(%edx), %eax\n"
        "movl $0x500, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        "movl %edi, %edx\n" /* coef */
        "movl $0xa, %ecx\n"
        ".Lf20a7c8_0020a8de:\n"
        "movl %eax, 0x18(%edx)\n" /* line 445 */
        "addl $4, %edx\n"
        "subl $-0x80, %eax\n"
        "subl $1, %ecx\n" /* line 444 */
        "jne .Lf20a7c8_0020a8de\n"
        "movl $0, 0x40(%edi)\n" /* line 447 | coef */
        "addl $0x3c, %esp\n" /* line 449 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 144 */
static __attribute__((naked))
boolean compress_data(j_compress_ptr cinfo, JSAMPIMAGE input_buf)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 144 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x70, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 145 | cinfo */
        "movl 0x14c(%eax), %eax\n"
        "movl %eax, -0x40(%ebp)\n" /* coef */
        "movl 8(%ebp), %edx\n" /* line 147 | cinfo */
        "movl 0xfc(%edx), %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x38(%ebp)\n" /* last_MCU_col */
        "movl 0xe4(%edx), %esi\n" /* line 148 */
        "subl $1, %esi\n"
        "movl %esi, -0x34(%ebp)\n" /* last_iMCU_row */
        "movl 0x10(%eax), %eax\n" /* line 154 */
        "movl %eax, -0x24(%ebp)\n" /* yoffset */
        "movl -0x40(%ebp), %edx\n" /* coef */
        "cmpl 0x14(%edx), %eax\n"
        "jge .Lf20a8fb_0020abe3\n"
        "shll $3, %eax\n"
        "movl %eax, -0xc(%ebp)\n"
        "leal 0x18(%edx), %ecx\n"
        "movl %ecx, -0x48(%ebp)\n"
        ".Lf20a8fb_0020a948:\n"
        "movl -0x40(%ebp), %esi\n" /* line 156 | coef, bi */
        "movl 0xc(%esi), %esi\n" /* bi */
        "movl %esi, -0x3c(%ebp)\n" /* bi, MCU_col_num */
        "cmpl %esi, -0x38(%ebp)\n" /* bi, last_MCU_col */
        "jb .Lf20a8fb_0020ab5d\n"
        ".Lf20a8fb_0020a95a:\n"
        "movl 8(%ebp), %eax\n" /* line 168 | cinfo */
        "movl 0xe8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf20a8fb_0020ab34\n"
        "movl %eax, -0x10(%ebp)\n"
        "movl $0, -0x30(%ebp)\n" /* blkn */
        "movl $0, -0x2c(%ebp)\n" /* ci */
        "movl 0xec(%eax), %edi\n" /* line 169 | compptr */
        "movl -0x3c(%ebp), %edx\n" /* line 170 | MCU_col_num */
        "cmpl %edx, -0x38(%ebp)\n" /* last_MCU_col */
        "jbe .Lf20a8fb_0020aaca\n"
        ".Lf20a8fb_0020a98e:\n"
        "movl 0x34(%edi), %ecx\n" /* compptr */
        "movl %ecx, -0x20(%ebp)\n" /* blockcnt */
        ".Lf20a8fb_0020a994:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 172 | MCU_col_num */
        "imull 0x40(%edi), %eax\n" /* compptr */
        "movl %eax, -0x18(%ebp)\n" /* xpos */
        "movl 0x38(%edi), %esi\n" /* line 174 | compptr, bi */
        "testl %esi, %esi\n" /* bi */
        "jle .Lf20a8fb_0020aa9b\n"
        "movl -0xc(%ebp), %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* ypos */
        "movl $0, -0x28(%ebp)\n" /* yindex */
        "jmp .Lf20a8fb_0020a9cf\n"
        ".Lf20a8fb_0020a9b8:\n"
        "addl %eax, -0x30(%ebp)\n" /* line 197 | blkn */
        "addl $8, -0x1c(%ebp)\n" /* line 198 | ypos */
        "addl $1, -0x28(%ebp)\n" /* line 174 | yindex */
        "movl -0x28(%ebp), %edx\n" /* yindex */
        "cmpl 0x38(%edi), %edx\n" /* compptr */
        "jge .Lf20a8fb_0020aa9b\n"
        ".Lf20a8fb_0020a9cf:\n"
        "movl -0x34(%ebp), %esi\n" /* line 175 | last_iMCU_row, bi */
        "movl -0x40(%ebp), %ecx\n" /* coef */
        "cmpl 8(%ecx), %esi\n" /* bi */
        "ja .Lf20a8fb_0020a9e9\n"
        "movl -0x28(%ebp), %eax\n" /* yindex */
        "addl -0x24(%ebp), %eax\n" /* yoffset */
        "cmpl 0x48(%edi), %eax\n" /* compptr */
        "jge .Lf20a8fb_0020aad5\n"
        ".Lf20a8fb_0020a9e9:\n"
        "movl 8(%ebp), %eax\n" /* line 177 | cinfo */
        "movl 0x15c(%eax), %edx\n"
        "movl -0x20(%ebp), %ecx\n" /* blockcnt */
        "movl %ecx, 0x18(%esp)\n"
        "movl -0x18(%ebp), %esi\n" /* xpos, bi */
        "movl %esi, 0x14(%esp)\n" /* bi */
        "movl -0x1c(%ebp), %eax\n" /* ypos */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x30(%ebp), %ecx\n" /* blkn */
        "movl -0x40(%ebp), %esi\n" /* coef, bi */
        "movl 0x18(%esi, %ecx, 4), %eax\n" /* bi */
        "movl %eax, 0xc(%esp)\n"
        "movl 4(%edi), %eax\n" /* compptr */
        "movl 0xc(%ebp), %ecx\n" /* input_buf */
        "movl (%ecx, %eax, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* compptr */
        "movl 8(%ebp), %esi\n" /* cinfo, bi */
        "movl %esi, (%esp)\n" /* bi */
        "calll *4(%edx)\n"
        "movl 0x34(%edi), %eax\n" /* line 181 | compptr */
        "cmpl %eax, -0x20(%ebp)\n" /* blockcnt */
        "jge .Lf20a8fb_0020a9b8\n"
        "movl -0x20(%ebp), %edx\n" /* line 183 | blockcnt */
        "addl -0x30(%ebp), %edx\n" /* blkn */
        "movl %edx, -0x44(%ebp)\n"
        "subl -0x20(%ebp), %eax\n" /* blockcnt */
        "shll $7, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x40(%ebp), %ecx\n" /* coef */
        "movl 0x18(%ecx, %edx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll jzero_far\n"
        "movl -0x20(%ebp), %esi\n" /* line 185 | blockcnt, bi */
        "cmpl 0x34(%edi), %esi\n" /* compptr, bi */
        "jge .Lf20a8fb_0020aa81\n"
        "movl -0x44(%ebp), %eax\n"
        "movl -0x40(%ebp), %edx\n" /* coef */
        "leal 0x18(%edx, %eax, 4), %ecx\n"
        ".Lf20a8fb_0020aa6b:\n"
        "movl (%ecx), %eax\n" /* line 186 */
        "movl -4(%ecx), %edx\n"
        "movzwl (%edx), %edx\n"
        "movw %dx, (%eax)\n"
        "addl $1, %esi\n" /* line 185 | bi */
        "addl $4, %ecx\n"
        "cmpl 0x34(%edi), %esi\n" /* compptr, bi */
        "jl .Lf20a8fb_0020aa6b\n"
        ".Lf20a8fb_0020aa81:\n"
        "movl 0x34(%edi), %eax\n" /* compptr */
        ".Lf20a8fb_0020aa84:\n"
        "addl %eax, -0x30(%ebp)\n" /* line 197 | blkn */
        "addl $8, -0x1c(%ebp)\n" /* line 198 | ypos */
        "addl $1, -0x28(%ebp)\n" /* line 174 | yindex */
        "movl -0x28(%ebp), %edx\n" /* yindex */
        "cmpl 0x38(%edi), %edx\n" /* compptr */
        "jl .Lf20a8fb_0020a9cf\n"
        ".Lf20a8fb_0020aa9b:\n"
        "addl $1, -0x2c(%ebp)\n" /* line 168 | ci */
        "addl $4, -0x10(%ebp)\n"
        "movl -0x2c(%ebp), %esi\n" /* ci, bi */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "cmpl 0xe8(%ecx), %esi\n" /* bi */
        "jge .Lf20a8fb_0020abb2\n"
        "movl -0x10(%ebp), %eax\n"
        "movl 0xec(%eax), %edi\n" /* line 169 | compptr */
        "movl -0x3c(%ebp), %edx\n" /* line 170 | MCU_col_num */
        "cmpl %edx, -0x38(%ebp)\n" /* last_MCU_col */
        "ja .Lf20a8fb_0020a98e\n"
        ".Lf20a8fb_0020aaca:\n"
        "movl 0x44(%edi), %esi\n" /* compptr, bi */
        "movl %esi, -0x20(%ebp)\n" /* bi, blockcnt */
        "jmp .Lf20a8fb_0020a994\n"
        ".Lf20a8fb_0020aad5:\n"
        "movl 0x34(%edi), %eax\n" /* line 191 | compptr */
        "shll $7, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x30(%ebp), %ecx\n" /* blkn */
        "movl -0x40(%ebp), %esi\n" /* coef, bi */
        "movl 0x18(%esi, %ecx, 4), %eax\n" /* bi */
        "movl %eax, (%esp)\n"
        "calll jzero_far\n"
        "movl 0x34(%edi), %ecx\n" /* line 193 | compptr */
        "testl %ecx, %ecx\n"
        "jle .Lf20a8fb_0020aa81\n"
        "movl -0x30(%ebp), %eax\n" /* blkn */
        "subl $1, %eax\n"
        "movl %eax, -0x14(%ebp)\n"
        "movl -0x30(%ebp), %edx\n" /* blkn */
        "leal 0x18(%esi, %edx, 4), %ecx\n" /* bi */
        "xorl %esi, %esi\n" /* bi */
        "jmp .Lf20a8fb_0020ab0f\n"
        ".Lf20a8fb_0020ab0c:\n"
        "movl -0x14(%ebp), %eax\n"
        ".Lf20a8fb_0020ab0f:\n"
        "movl -0x40(%ebp), %edx\n" /* line 194 | coef */
        "movl 0x18(%edx, %eax, 4), %eax\n"
        "movl %eax, -0x4c(%ebp)\n"
        "movzwl (%eax), %edx\n"
        "movl (%ecx), %eax\n"
        "movw %dx, (%eax)\n"
        "addl $1, %esi\n" /* line 193 | bi */
        "addl $4, %ecx\n"
        "cmpl 0x34(%edi), %esi\n" /* compptr, bi */
        "jl .Lf20a8fb_0020ab0c\n"
        "movl 0x34(%edi), %eax\n" /* compptr */
        "jmp .Lf20a8fb_0020aa84\n"
        ".Lf20a8fb_0020ab34:\n"
        "movl %eax, %edx\n"
        "movl 0x160(%edx), %eax\n" /* line 204 */
        "movl -0x48(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        "testb %al, %al\n"
        "je .Lf20a8fb_0020abcb\n"
        ".Lf20a8fb_0020ab4d:\n"
        "addl $1, -0x3c(%ebp)\n" /* line 157 | MCU_col_num */
        "movl -0x3c(%ebp), %esi\n" /* line 156 | MCU_col_num, bi */
        "cmpl %esi, -0x38(%ebp)\n" /* bi, last_MCU_col */
        "jae .Lf20a8fb_0020a95a\n"
        ".Lf20a8fb_0020ab5d:\n"
        "movl -0x40(%ebp), %edx\n" /* line 212 | coef */
        "movl $0, 0xc(%edx)\n"
        "addl $1, -0x24(%ebp)\n" /* line 155 | yoffset */
        "addl $8, -0xc(%ebp)\n"
        "movl -0x24(%ebp), %ecx\n" /* line 154 | yoffset */
        "cmpl 0x14(%edx), %ecx\n"
        "jl .Lf20a8fb_0020a948\n"
        "movl -0x40(%ebp), %esi\n" /* coef, bi */
        "addl $1, 8(%esi)\n" /* line 215 | bi */
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 75 | cinfo */
        "movl 0x14c(%eax), %edx\n" /* coef */
        "cmpl $1, 0xe8(%eax)\n" /* line 81 */
        "jg .Lf20a8fb_0020abfb\n"
        ".Lf20a8fb_0020ab94:\n"
        "movl %eax, %ecx\n"
        "movl 0xe4(%eax), %eax\n" /* line 84 */
        "subl $1, %eax\n"
        "cmpl %eax, 8(%edx)\n"
        "jae .Lf20a8fb_0020ac1c\n"
        "movl 0xec(%ecx), %eax\n" /* line 85 */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, 0x14(%edx)\n"
        "jmp .Lf20a8fb_0020ac02\n"
        ".Lf20a8fb_0020abb2:\n"
        "movl %ecx, %edx\n"
        /* } scope */
        "movl 0x160(%edx), %eax\n" /* line 204 */
        "movl -0x48(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        "testb %al, %al\n"
        "jne .Lf20a8fb_0020ab4d\n"
        ".Lf20a8fb_0020abcb:\n"
        "movl -0x24(%ebp), %esi\n" /* line 206 | yoffset, bi */
        "movl -0x40(%ebp), %eax\n" /* coef */
        "movl %esi, 0x10(%eax)\n" /* bi */
        "movl -0x3c(%ebp), %edx\n" /* line 207 | MCU_col_num */
        "movl %edx, 0xc(%eax)\n"
        "xorl %eax, %eax\n"
        "addl $0x70, %esp\n" /* line 218 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20a8fb_0020abe3:\n"
        "movl %edx, %esi\n" /* bi */
        "addl $1, 8(%esi)\n" /* line 215 | bi */
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 75 | cinfo */
        "movl 0x14c(%eax), %edx\n" /* coef */
        "cmpl $1, 0xe8(%eax)\n" /* line 81 */
        "jle .Lf20a8fb_0020ab94\n"
        ".Lf20a8fb_0020abfb:\n"
        "movl $1, 0x14(%edx)\n" /* line 82 */
        ".Lf20a8fb_0020ac02:\n"
        "movl $0, 0xc(%edx)\n" /* line 90 */
        "movl $0, 0x10(%edx)\n" /* line 91 */
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x70, %esp\n" /* line 218 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2 */
        ".Lf20a8fb_0020ac1c:\n"
        "movl 8(%ebp), %ecx\n" /* line 87 | cinfo */
        "movl 0xec(%ecx), %eax\n"
        "movl 0x48(%eax), %eax\n"
        "movl %eax, 0x14(%edx)\n"
        "jmp .Lf20a8fb_0020ac02\n"
    );
}

/* line 342 */
static __attribute__((naked))
boolean compress_output(j_compress_ptr cinfo, JSAMPIMAGE input_buf)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 342 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "addl $-0x80, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 343 | cinfo */
        "movl 0x14c(%eax), %eax\n"
        "movl %eax, -0x3c(%ebp)\n" /* coef */
        "movl 8(%ebp), %edx\n" /* line 355 | cinfo */
        "movl 0xe8(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jg .Lf20ac2d_0020ae19\n"
        "movl %eax, %ecx\n"
        "movl %eax, %edi\n"
        ".Lf20ac2d_0020ac56:\n"
        "movl 0x10(%ecx), %ecx\n" /* line 364 */
        "movl %ecx, -0x28(%ebp)\n" /* yoffset */
        "cmpl %ecx, 0x14(%edi)\n"
        "jle .Lf20ac2d_0020adc8\n"
        "shll $2, %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "leal 0x18(%edi), %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        ".Lf20ac2d_0020ac71:\n"
        "movl -0x3c(%ebp), %edx\n" /* line 366 | coef */
        "movl 0xc(%edx), %edx\n"
        "movl %edx, -0x38(%ebp)\n" /* MCU_col_num */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "cmpl 0xfc(%ecx), %edx\n"
        "jae .Lf20ac2d_0020ad6e\n"
        ".Lf20ac2d_0020ac89:\n"
        "movl 0xe8(%ecx), %edi\n" /* line 370 */
        "testl %edi, %edi\n"
        "jle .Lf20ac2d_0020ad3a\n"
        "movl %ecx, -0x20(%ebp)\n"
        "movl $0, -0x30(%ebp)\n" /* ci */
        "movl $0, -0x34(%ebp)\n" /* blkn */
        "movl %ecx, %edi\n"
        ".Lf20ac2d_0020acaa:\n"
        "movl 0xec(%edi), %esi\n" /* line 371 | compptr */
        "movl -0x38(%ebp), %eax\n" /* line 372 | MCU_col_num */
        "imull 0x34(%esi), %eax\n" /* compptr */
        "movl 0x38(%esi), %edx\n" /* line 373 | compptr */
        "testl %edx, %edx\n"
        "jle .Lf20ac2d_0020ad1a\n"
        "shll $7, %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl -0x1c(%ebp), %edx\n"
        "movl -0x30(%ebp), %eax\n" /* ci */
        "addl -0x18(%ebp, %eax, 4), %edx\n"
        "movl %edx, -0x4c(%ebp)\n"
        "movl $0, -0x2c(%ebp)\n" /* yindex */
        "movl %edx, %ecx\n"
        ".Lf20ac2d_0020acda:\n"
        "movl -0x24(%ebp), %edx\n" /* line 374 */
        "addl (%ecx), %edx\n"
        "movl 0x34(%esi), %eax\n" /* line 375 | compptr */
        "testl %eax, %eax\n"
        "jle .Lf20ac2d_0020ad05\n"
        "movl -0x34(%ebp), %edi\n" /* blkn */
        "movl -0x3c(%ebp), %ecx\n" /* coef */
        "leal 0x18(%ecx, %edi, 4), %eax\n"
        "xorl %ecx, %ecx\n"
        ".Lf20ac2d_0020acf2:\n"
        "movl %edx, (%eax)\n" /* line 376 */
        "subl $-0x80, %edx\n"
        "addl $1, %ecx\n" /* line 375 */
        "addl $4, %eax\n"
        "cmpl 0x34(%esi), %ecx\n" /* compptr */
        "jl .Lf20ac2d_0020acf2\n"
        "addl %ecx, -0x34(%ebp)\n" /* blkn */
        ".Lf20ac2d_0020ad05:\n"
        "addl $1, -0x2c(%ebp)\n" /* line 373 | yindex */
        "addl $4, -0x4c(%ebp)\n"
        "movl -0x2c(%ebp), %edi\n" /* yindex */
        "cmpl 0x38(%esi), %edi\n" /* compptr */
        "jge .Lf20ac2d_0020ad1a\n"
        "movl -0x4c(%ebp), %ecx\n"
        "jmp .Lf20ac2d_0020acda\n"
        ".Lf20ac2d_0020ad1a:\n"
        "addl $1, -0x30(%ebp)\n" /* line 370 | ci */
        "addl $4, -0x20(%ebp)\n"
        "movl -0x30(%ebp), %eax\n" /* ci */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "cmpl 0xe8(%edx), %eax\n"
        "jge .Lf20ac2d_0020ad38\n"
        "movl -0x20(%ebp), %edi\n"
        "jmp .Lf20ac2d_0020acaa\n"
        ".Lf20ac2d_0020ad38:\n"
        "movl %edx, %ecx\n"
        ".Lf20ac2d_0020ad3a:\n"
        "movl 0x160(%ecx), %eax\n" /* line 381 */
        "movl -0x44(%ebp), %edi\n"
        "movl %edi, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *4(%eax)\n"
        "testb %al, %al\n"
        "je .Lf20ac2d_0020ae01\n"
        "addl $1, -0x38(%ebp)\n" /* line 367 | MCU_col_num */
        "movl -0x38(%ebp), %edx\n" /* line 366 | MCU_col_num */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "cmpl 0xfc(%eax), %edx\n"
        "jae .Lf20ac2d_0020ad6e\n"
        "movl %eax, %ecx\n"
        "jmp .Lf20ac2d_0020ac89\n"
        ".Lf20ac2d_0020ad6e:\n"
        "movl -0x3c(%ebp), %edi\n" /* line 389 | coef */
        "movl $0, 0xc(%edi)\n"
        "addl $1, -0x28(%ebp)\n" /* line 365 | yoffset */
        "addl $4, -0x1c(%ebp)\n"
        "movl -0x28(%ebp), %eax\n" /* line 364 | yoffset */
        "cmpl %eax, 0x14(%edi)\n"
        "jg .Lf20ac2d_0020ac71\n"
        "movl -0x3c(%ebp), %edx\n" /* coef */
        "addl $1, 8(%edx)\n" /* line 392 */
        /* { scope 2 */
        "movl 8(%ebp), %ecx\n" /* line 75 | cinfo */
        "movl 0x14c(%ecx), %edx\n" /* coef */
        "cmpl $1, 0xe8(%ecx)\n" /* line 81 */
        "jg .Lf20ac2d_0020ade0\n"
        ".Lf20ac2d_0020ada5:\n"
        "movl 8(%ebp), %edi\n" /* line 84 | cinfo */
        "movl 0xe4(%edi), %eax\n"
        "subl $1, %eax\n"
        "cmpl %eax, 8(%edx)\n"
        "jae .Lf20ac2d_0020ae8f\n"
        "movl 0xec(%edi), %eax\n" /* line 85 */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, 0x14(%edx)\n"
        "jmp .Lf20ac2d_0020ade7\n"
        ".Lf20ac2d_0020adc8:\n"
        "movl %edi, %edx\n"
        /* } scope */
        "addl $1, 8(%edx)\n" /* line 392 */
        /* { scope 2 */
        "movl 8(%ebp), %ecx\n" /* line 75 | cinfo */
        "movl 0x14c(%ecx), %edx\n" /* coef */
        "cmpl $1, 0xe8(%ecx)\n" /* line 81 */
        "jle .Lf20ac2d_0020ada5\n"
        ".Lf20ac2d_0020ade0:\n"
        "movl $1, 0x14(%edx)\n" /* line 82 */
        ".Lf20ac2d_0020ade7:\n"
        "movl $0, 0xc(%edx)\n" /* line 90 */
        "movl $0, 0x10(%edx)\n" /* line 91 */
        "movl $1, %eax\n"
        /* } scope */
        "subl $-0x80, %esp\n" /* line 395 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20ac2d_0020ae01:\n"
        "movl -0x28(%ebp), %eax\n" /* line 383 | yoffset */
        "movl -0x3c(%ebp), %edx\n" /* coef */
        "movl %eax, 0x10(%edx)\n"
        "movl -0x38(%ebp), %ecx\n" /* line 384 | MCU_col_num */
        "movl %ecx, 0xc(%edx)\n"
        "xorl %eax, %eax\n"
        "subl $-0x80, %esp\n" /* line 395 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20ac2d_0020ae19:\n"
        "movl %edx, %esi\n" /* line 355 | compptr */
        "movl $1, %edi\n"
        "leal -0x18(%ebp), %ecx\n" /* buffer */
        "movl %ecx, -0x40(%ebp)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "jmp .Lf20ac2d_0020ae2d\n"
        ".Lf20ac2d_0020ae2b:\n"
        "movl %edx, %ecx\n"
        ".Lf20ac2d_0020ae2d:\n"
        "movl 0xec(%esi), %edx\n" /* line 356 | compptr */
        "movl 0xc(%edx), %eax\n" /* line 357 */
        "movl 4(%ecx), %ecx\n"
        "movl %ecx, -0x5c(%ebp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x3c(%ebp), %ecx\n" /* coef */
        "imull 8(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl 0x40(%ecx, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "movl -0x5c(%ebp), %edx\n"
        "calll *0x20(%edx)\n"
        "movl -0x40(%ebp), %ecx\n"
        "movl %eax, -4(%ecx, %edi, 4)\n"
        "movl %edi, %eax\n"
        "addl $1, %edi\n"
        "addl $4, %esi\n" /* compptr */
        "movl 8(%ebp), %edx\n" /* line 355 | cinfo */
        "cmpl %eax, 0xe8(%edx)\n"
        "jg .Lf20ac2d_0020ae2b\n"
        "movl -0x3c(%ebp), %ecx\n" /* coef */
        "movl -0x3c(%ebp), %edi\n" /* coef */
        "jmp .Lf20ac2d_0020ac56\n"
        /* { scope 2 */
        ".Lf20ac2d_0020ae8f:\n"
        "movl 8(%ebp), %edi\n" /* line 87 | cinfo */
        "movl 0xec(%edi), %eax\n"
        "movl 0x48(%eax), %eax\n"
        "movl %eax, 0x14(%edx)\n"
        "jmp .Lf20ac2d_0020ade7\n"
    );
}

/* line 246 */
static __attribute__((naked))
boolean compress_first_pass(j_compress_ptr cinfo, JSAMPIMAGE input_buf)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 246 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "addl $-0x80, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 247 | cinfo */
        "movl 0x14c(%eax), %eax\n"
        "movl %eax, -0x48(%ebp)\n" /* coef */
        "movl 8(%ebp), %edx\n" /* line 248 | cinfo */
        "movl 0xe4(%edx), %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x44(%ebp)\n" /* last_iMCU_row */
        "movl 0x48(%edx), %eax\n" /* line 256 */
        "movl %eax, -0x28(%ebp)\n" /* compptr */
        "movl 0x40(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf20aea3_0020aeec\n"
        "movl 0xc(%ebp), %eax\n" /* line 326 | input_buf */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll compress_output\n"
        "movzbl %al, %eax\n"
        "subl $-0x80, %esp\n" /* line 327 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20aea3_0020aeec:\n"
        "movl -0x48(%ebp), %edx\n" /* line 256 | coef */
        "movl %edx, -0x14(%ebp)\n"
        "movl $0, -0x38(%ebp)\n" /* ci */
        "jmp .Lf20aea3_0020af5d\n"
        ".Lf20aea3_0020aefb:\n"
        "movl -0x28(%ebp), %eax\n" /* line 265 | compptr */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* block_rows */
        "movl -0x28(%ebp), %eax\n" /* compptr */
        "movl -0x28(%ebp), %edx\n" /* compptr */
        ".Lf20aea3_0020af0a:\n"
        "movl 0x1c(%eax), %eax\n" /* line 271 */
        "movl %eax, -0x40(%ebp)\n" /* blocks_across */
        "movl 8(%edx), %edx\n" /* line 272 */
        "movl %edx, -0x34(%ebp)\n" /* h_samp_factor */
        "xorl %edx, %edx\n" /* line 274 */
        "divl -0x34(%ebp)\n" /* h_samp_factor */
        "movl %edx, %edi\n" /* thisblockrow */
        "movl -0x34(%ebp), %eax\n" /* line 276 | h_samp_factor */
        "subl %edx, %eax\n"
        "cmpl $1, %edx\n"
        "cmovgel %eax, %edi\n" /* thisblockrow */
        "movl -0x2c(%ebp), %eax\n" /* line 280 | block_rows */
        "testl %eax, %eax\n"
        "jg .Lf20aea3_0020afd4\n"
        ".Lf20aea3_0020af33:\n"
        "movl -0x44(%ebp), %edx\n" /* line 301 | last_iMCU_row */
        "movl -0x48(%ebp), %eax\n" /* coef */
        "cmpl 8(%eax), %edx\n"
        "je .Lf20aea3_0020b080\n"
        ".Lf20aea3_0020af42:\n"
        "addl $1, -0x38(%ebp)\n" /* line 257 | ci */
        "addl $0x54, -0x28(%ebp)\n" /* compptr */
        "addl $4, -0x14(%ebp)\n"
        "movl -0x38(%ebp), %edx\n" /* line 256 | ci */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "cmpl 0x40(%ecx), %edx\n"
        "jge .Lf20aea3_0020b130\n"
        ".Lf20aea3_0020af5d:\n"
        "movl -0x28(%ebp), %ecx\n" /* line 246 | compptr */
        "addl $0xc, %ecx\n"
        "movl %ecx, -0x10(%ebp)\n"
        "movl -0x28(%ebp), %edx\n" /* line 259 | compptr */
        "movl 0xc(%edx), %eax\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl 4(%ecx), %edx\n"
        "movl $1, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x48(%ebp), %ecx\n" /* coef */
        "imull 8(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x14(%ebp), %ecx\n"
        "movl 0x40(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll *0x20(%edx)\n"
        "movl %eax, -0x24(%ebp)\n" /* buffer */
        "movl -0x44(%ebp), %ecx\n" /* line 264 | last_iMCU_row */
        "movl -0x48(%ebp), %edx\n" /* coef */
        "cmpl 8(%edx), %ecx\n"
        "ja .Lf20aea3_0020aefb\n"
        "movl -0x28(%ebp), %edx\n" /* line 268 | compptr */
        "movl 0xc(%edx), %edx\n"
        "movl %edx, -0x2c(%ebp)\n" /* block_rows */
        "movl -0x28(%ebp), %ecx\n" /* compptr */
        "movl 0x20(%ecx), %eax\n"
        "xorl %edx, %edx\n"
        "divl -0x2c(%ebp)\n" /* block_rows */
        "testl %edx, %edx\n" /* line 269 */
        "cmovel -0x2c(%ebp), %edx\n" /* block_rows */
        "movl %edx, -0x2c(%ebp)\n" /* block_rows */
        "movl %ecx, %eax\n"
        "movl %ecx, %edx\n"
        "jmp .Lf20aea3_0020af0a\n"
        ".Lf20aea3_0020afd4:\n"
        "movl -0x40(%ebp), %ecx\n" /* line 288 | blocks_across */
        "shll $7, %ecx\n"
        "movl %ecx, -0x50(%ebp)\n"
        "movl %edi, %eax\n" /* line 289 | thisblockrow */
        "shll $7, %eax\n"
        "movl %eax, -0x4c(%ebp)\n"
        "movl $0, -0x30(%ebp)\n" /* block_row */
        "movl -0x30(%ebp), %edx\n" /* block_row */
        ".Lf20aea3_0020afef:\n"
        "movl -0x24(%ebp), %ecx\n" /* line 281 | buffer */
        "movl (%ecx, %edx, 4), %esi\n" /* lastblockrow */
        "movl 8(%ebp), %eax\n" /* line 282 | cinfo */
        "movl 0x15c(%eax), %eax\n"
        "movl %eax, -0x5c(%ebp)\n"
        "movl -0x40(%ebp), %edx\n" /* blocks_across */
        "movl %edx, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl -0x30(%ebp), %edx\n" /* block_row */
        "shll $3, %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n" /* lastblockrow */
        "movl -0x38(%ebp), %ecx\n" /* ci */
        "movl 0xc(%ebp), %eax\n" /* input_buf */
        "movl (%eax, %ecx, 4), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl -0x28(%ebp), %edx\n" /* compptr */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %ecx, (%esp)\n"
        "movl -0x5c(%ebp), %eax\n"
        "calll *4(%eax)\n"
        "testl %edi, %edi\n" /* line 286 | thisblockrow */
        "jle .Lf20aea3_0020b069\n"
        "addl -0x50(%ebp), %esi\n" /* line 288 | lastblockrow */
        "movl -0x4c(%ebp), %edx\n" /* line 289 */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* lastblockrow */
        "calll jzero_far\n"
        "movzwl -0x80(%esi), %ecx\n" /* line 290 | lastblockrow */
        "movl %esi, %eax\n" /* lastblockrow */
        "xorl %edx, %edx\n"
        ".Lf20aea3_0020b05c:\n"
        "movw %cx, (%eax)\n" /* line 292 */
        "addl $1, %edx\n" /* line 291 */
        "subl $-0x80, %eax\n"
        "cmpl %edx, %edi\n" /* thisblockrow */
        "jne .Lf20aea3_0020b05c\n"
        ".Lf20aea3_0020b069:\n"
        "addl $1, -0x30(%ebp)\n" /* line 280 | block_row */
        "movl -0x30(%ebp), %ecx\n" /* block_row */
        "cmpl %ecx, -0x2c(%ebp)\n" /* block_rows */
        "je .Lf20aea3_0020af33\n"
        "movl %ecx, %edx\n"
        "jmp .Lf20aea3_0020afef\n"
        ".Lf20aea3_0020b080:\n"
        "movl -0x40(%ebp), %ecx\n" /* line 302 | blocks_across */
        "addl %edi, %ecx\n" /* thisblockrow */
        "movl %ecx, %eax\n" /* line 303 */
        "xorl %edx, %edx\n"
        "divl -0x34(%ebp)\n" /* h_samp_factor */
        "movl %eax, -0x54(%ebp)\n"
        "movl -0x2c(%ebp), %edx\n" /* line 304 | block_rows */
        "movl -0x10(%ebp), %eax\n"
        "cmpl (%eax), %edx\n"
        "jge .Lf20aea3_0020af42\n"
        "shll $7, %ecx\n"
        "movl %ecx, -0x20(%ebp)\n"
        "movl -0x34(%ebp), %edx\n" /* h_samp_factor */
        "shll $7, %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 246 | block_rows */
        "movl -0x24(%ebp), %eax\n" /* buffer */
        "leal (%eax, %ecx, 4), %ecx\n"
        "movl %ecx, -0x18(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n" /* block_rows */
        "movl %eax, -0xc(%ebp)\n"
        "movl %ecx, %edx\n"
        ".Lf20aea3_0020b0c0:\n"
        "movl (%edx), %edi\n" /* line 306 | thisblockrow */
        "movl -4(%edx), %esi\n" /* line 307 | lastblockrow */
        "movl -0x20(%ebp), %ecx\n" /* line 308 */
        "movl %ecx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* thisblockrow */
        "calll jzero_far\n"
        "movl -0x54(%ebp), %eax\n" /* line 310 */
        "testl %eax, %eax\n"
        "je .Lf20aea3_0020b115\n"
        "movl $0, -0x3c(%ebp)\n" /* MCUindex */
        ".Lf20aea3_0020b0e2:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 311 */
        "movzwl -0x80(%esi, %eax), %ecx\n" /* lastblockrow */
        "movl -0x34(%ebp), %eax\n" /* line 312 | h_samp_factor */
        "testl %eax, %eax\n"
        "jle .Lf20aea3_0020b103\n"
        "movl %edi, %eax\n" /* thisblockrow */
        "xorl %edx, %edx\n"
        ".Lf20aea3_0020b0f5:\n"
        "movw %cx, (%eax)\n" /* line 313 */
        "addl $1, %edx\n" /* line 312 */
        "subl $-0x80, %eax\n"
        "cmpl %edx, -0x34(%ebp)\n" /* h_samp_factor */
        "jne .Lf20aea3_0020b0f5\n"
        ".Lf20aea3_0020b103:\n"
        "addl -0x1c(%ebp), %edi\n" /* line 315 | thisblockrow */
        "addl -0x1c(%ebp), %esi\n" /* line 316 | lastblockrow */
        "addl $1, -0x3c(%ebp)\n" /* line 310 | MCUindex */
        "movl -0x3c(%ebp), %edx\n" /* MCUindex */
        "cmpl %edx, -0x54(%ebp)\n"
        "jne .Lf20aea3_0020b0e2\n"
        ".Lf20aea3_0020b115:\n"
        "addl $1, -0xc(%ebp)\n" /* line 305 */
        "addl $4, -0x18(%ebp)\n"
        "movl -0xc(%ebp), %eax\n" /* line 304 */
        "movl -0x10(%ebp), %ecx\n"
        "cmpl %eax, (%ecx)\n"
        "jle .Lf20aea3_0020af42\n"
        "movl -0x18(%ebp), %edx\n"
        "jmp .Lf20aea3_0020b0c0\n"
        ".Lf20aea3_0020b130:\n"
        "movl %ecx, %edx\n"
        "movl 0xc(%ebp), %eax\n" /* line 326 | input_buf */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll compress_output\n"
        "movzbl %al, %eax\n"
        "subl $-0x80, %esp\n" /* line 327 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

