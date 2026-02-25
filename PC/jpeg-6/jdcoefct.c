/* ASM dump from: jdcoefct.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jdcoefct.c */

#include "common_types.h"
#include "imports.h"

static void start_output_pass(j_decompress_ptr cinfo);
static int decompress_onepass(j_decompress_ptr cinfo, JSAMPIMAGE output_buf);
static int dummy_consume_data(j_decompress_ptr cinfo);
static int decompress_data(j_decompress_ptr cinfo, JSAMPIMAGE output_buf);
static int decompress_smooth_data(j_decompress_ptr cinfo, JSAMPIMAGE output_buf);
void jinit_d_coef_controller(j_decompress_ptr cinfo, int need_full_buffer);
static void start_input_pass(j_decompress_ptr cinfo);
static int consume_data(j_decompress_ptr cinfo);

/* line 120 */
static __attribute__((naked))
void start_output_pass(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1: smoothing_useful, ci, coef_bits, coef_bits_latch */
        "pushl %ebp\n" /* line 120 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 0x190(%esi), %edi\n" /* line 122 | cinfo, coef */
        "movl 0x10(%edi), %eax\n" /* line 125 | coef */
        "testl %eax, %eax\n"
        "je .Lf204d08_00204d35\n"
        "cmpb $0, 0x51(%esi)\n" /* line 126 | cinfo */
        "jne .Lf204d08_00204d47\n"
        ".Lf204d08_00204d2c:\n"
        "leal 0x4b7(%ebx), %eax\n" /* line 129 */
        "movl %eax, 0xc(%edi)\n" /* coef */
        ".Lf204d08_00204d35:\n"
        "movl $0, 0x90(%esi)\n" /* line 132 | cinfo */
        "addl $0x6c, %esp\n" /* line 133 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2 */
        ".Lf204d08_00204d47:\n"
        "cmpb $0, 0xd0(%esi)\n" /* line 415 | cinfo */
        "je .Lf204d08_00204d2c\n"
        "movl 0x94(%esi), %eax\n" /* cinfo */
        "testl %eax, %eax\n"
        "je .Lf204d08_00204d2c\n"
        "movl 0x70(%edi), %eax\n" /* line 419 | coef */
        "testl %eax, %eax\n"
        "je .Lf204d08_00204ea1\n"
        "movl 0x70(%edi), %eax\n" /* coef */
        ".Lf204d08_00204d68:\n"
        "movl %eax, -0x24(%ebp)\n" /* line 424 | coef_bits_latch */
        "movl 0xcc(%esi), %edx\n" /* line 426 | cinfo */
        "movl 0x2c(%esi), %ecx\n" /* cinfo */
        "testl %ecx, %ecx\n"
        "jg .Lf204d08_00204d89\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf204d08_00204d7a:\n"
        "testl %eax, %eax\n" /* line 126 */
        "je .Lf204d08_00204d2c\n"
        "leal 0x68d(%ebx), %eax\n" /* line 127 */
        "movl %eax, 0xc(%edi)\n" /* coef */
        "jmp .Lf204d08_00204d35\n"
        /* { scope 2 */
        ".Lf204d08_00204d89:\n"
        "movl 0x4c(%edx), %eax\n" /* line 429 */
        "testl %eax, %eax\n"
        "je .Lf204d08_00204d2c\n"
        "cmpw $0, (%eax)\n" /* line 432 */
        "je .Lf204d08_00204d2c\n"
        "cmpw $0, 2(%eax)\n"
        "je .Lf204d08_00204d2c\n"
        "cmpw $0, 0x10(%eax)\n"
        "je .Lf204d08_00204d2c\n"
        "cmpw $0, 0x20(%eax)\n"
        "je .Lf204d08_00204d2c\n"
        "cmpw $0, 0x12(%eax)\n"
        "je .Lf204d08_00204d2c\n"
        "cmpw $0, 4(%eax)\n"
        "je .Lf204d08_00204d2c\n"
        "addl $0xa0, %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl $0, -0x2c(%ebp)\n" /* ci */
        "movb $0, -0x2d(%ebp)\n" /* smoothing_useful */
        ".Lf204d08_00204dd5:\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 440 | ci */
        "shll $8, %ecx\n"
        "movl %ecx, -0x28(%ebp)\n" /* coef_bits */
        "movl 0x94(%esi), %eax\n" /* cinfo */
        "addl %eax, %ecx\n"
        "movl %ecx, -0x28(%ebp)\n" /* coef_bits */
        "movl (%ecx), %edx\n" /* line 441 */
        "testl %edx, %edx\n"
        "js .Lf204d08_00204d2c\n"
        "movl $0, -0x20(%ebp)\n"
        ".Lf204d08_00204dfa:\n"
        "movl -0x20(%ebp), %edx\n" /* line 120 */
        "shll $2, %edx\n"
        "movl %edx, -0x3c(%ebp)\n"
        "movl -0x28(%ebp), %ecx\n" /* coef_bits */
        "addl %edx, %ecx\n"
        "movl %ecx, -0x4c(%ebp)\n"
        "movl 4(%ecx), %eax\n" /* line 445 */
        "movl -0x24(%ebp), %ecx\n" /* coef_bits_latch */
        "movl %eax, 4(%ecx, %edx)\n"
        "movl -0x4c(%ebp), %eax\n" /* line 446 */
        "movl 4(%eax), %eax\n"
        "testl %eax, %eax\n"
        "movl $1, %eax\n"
        "movzbl -0x2d(%ebp), %edx\n" /* smoothing_useful */
        "cmovnel %eax, %edx\n"
        "movb %dl, -0x2d(%ebp)\n" /* smoothing_useful */
        "addl $1, -0x20(%ebp)\n"
        "cmpl $5, -0x20(%ebp)\n" /* line 444 */
        "jne .Lf204d08_00204dfa\n"
        "addl $0x18, %ecx\n" /* line 449 */
        "movl %ecx, -0x24(%ebp)\n" /* coef_bits_latch */
        "addl $1, -0x2c(%ebp)\n" /* line 427 | ci */
        "movl -0x2c(%ebp), %ecx\n" /* line 426 | ci */
        "cmpl %ecx, 0x2c(%esi)\n" /* cinfo */
        "jle .Lf204d08_00204ec6\n"
        "movl -0x1c(%ebp), %edx\n" /* line 429 */
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf204d08_00204d2c\n"
        "cmpw $0, (%eax)\n" /* line 432 */
        "je .Lf204d08_00204d2c\n"
        "cmpw $0, 2(%eax)\n"
        "je .Lf204d08_00204d2c\n"
        "cmpw $0, 0x10(%eax)\n"
        "je .Lf204d08_00204d2c\n"
        "cmpw $0, 0x20(%eax)\n"
        "je .Lf204d08_00204d2c\n"
        "cmpw $0, 0x12(%eax)\n"
        "je .Lf204d08_00204d2c\n"
        "addl $0x54, %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "cmpw $0, 4(%eax)\n"
        "jne .Lf204d08_00204dd5\n"
        "jmp .Lf204d08_00204d2c\n"
        ".Lf204d08_00204ea1:\n"
        "movl 4(%esi), %eax\n" /* line 420 | cinfo */
        "movl 0x2c(%esi), %edx\n" /* cinfo */
        "leal (%edx, %edx, 2), %edx\n"
        "shll $3, %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "movl %eax, 0x70(%edi)\n" /* coef */
        "jmp .Lf204d08_00204d68\n"
        ".Lf204d08_00204ec6:\n"
        "movzbl %dl, %eax\n" /* line 426 */
        "jmp .Lf204d08_00204d7a\n"
    );
}

/* line 148 */
static __attribute__((naked))
int decompress_onepass(j_decompress_ptr cinfo, JSAMPIMAGE output_buf)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 148 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x60, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 149 | cinfo */
        "movl 0x190(%eax), %eax\n"
        "movl %eax, -0x44(%ebp)\n" /* coef */
        "movl 8(%ebp), %edx\n" /* line 151 | cinfo */
        "movl 0x140(%edx), %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x3c(%ebp)\n" /* last_MCU_col */
        "movl 0x124(%edx), %eax\n" /* line 152 */
        "leal -1(%eax), %esi\n"
        "movl %esi, -0x38(%ebp)\n" /* last_iMCU_row */
        "movl -0x44(%ebp), %edi\n" /* line 160 | coef, output_col */
        "movl 0x18(%edi), %edi\n" /* output_col */
        "movl %edi, -0x24(%ebp)\n" /* output_col, yoffset */
        "movl -0x44(%ebp), %edx\n" /* coef */
        "cmpl 0x1c(%edx), %edi\n" /* output_col */
        "jge .Lf204ece_002050ef\n"
        "movl %edx, %ecx\n"
        "jmp .Lf204ece_00204f33\n"
        ".Lf204ece_00204f16:\n"
        "movl -0x44(%ebp), %edi\n" /* line 209 | coef, output_col */
        "movl $0, 0x14(%edi)\n" /* output_col */
        "addl $1, -0x24(%ebp)\n" /* line 161 | yoffset */
        "movl -0x24(%ebp), %eax\n" /* line 160 | yoffset */
        "cmpl 0x1c(%edi), %eax\n" /* output_col */
        "jge .Lf204ece_00205157\n"
        "movl -0x44(%ebp), %ecx\n" /* coef */
        ".Lf204ece_00204f33:\n"
        "movl 0x14(%ecx), %ecx\n" /* line 162 */
        "movl %ecx, -0x40(%ebp)\n" /* MCU_col_num */
        "cmpl %ecx, -0x3c(%ebp)\n" /* last_MCU_col */
        "jb .Lf204ece_00204f16\n"
        "movl -0x44(%ebp), %esi\n" /* coef, compptr */
        "addl $0x20, %esi\n" /* compptr */
        "movl %esi, -0x48(%ebp)\n" /* compptr */
        ".Lf204ece_00204f47:\n"
        "movl 8(%ebp), %edi\n" /* line 165 | cinfo, output_col */
        "movl 0x148(%edi), %eax\n" /* output_col */
        "shll $7, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x44(%ebp), %edx\n" /* coef */
        "movl 0x20(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll jzero_far\n"
        "movl 0x1a0(%edi), %eax\n" /* line 167 | output_col */
        "movl -0x48(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* output_col */
        "calll *4(%eax)\n"
        "testb %al, %al\n"
        "je .Lf204ece_0020513f\n"
        "movl 8(%ebp), %esi\n" /* line 179 | cinfo, compptr */
        "movl 0x12c(%esi), %eax\n" /* compptr */
        "testl %eax, %eax\n"
        "jle .Lf204ece_0020507d\n"
        "movl %esi, -0xc(%ebp)\n" /* compptr */
        "movl $0, -0x34(%ebp)\n" /* blkn */
        "movl $0, -0x30(%ebp)\n" /* ci */
        "movl %esi, %edx\n" /* compptr */
        "jmp .Lf204ece_00204fc9\n"
        ".Lf204ece_00204fa6:\n"
        "movl 0x3c(%esi), %ecx\n" /* line 183 | compptr */
        "addl %ecx, -0x34(%ebp)\n" /* blkn */
        ".Lf204ece_00204fac:\n"
        "addl $1, -0x30(%ebp)\n" /* line 179 | ci */
        "addl $4, -0xc(%ebp)\n"
        "movl -0x30(%ebp), %ecx\n" /* ci */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "cmpl 0x12c(%edx), %ecx\n"
        "jge .Lf204ece_0020507d\n"
        ".Lf204ece_00204fc6:\n"
        "movl -0xc(%ebp), %edx\n"
        ".Lf204ece_00204fc9:\n"
        "movl 0x130(%edx), %esi\n" /* line 180 | compptr */
        "cmpb $0, 0x30(%esi)\n" /* line 182 | compptr */
        "je .Lf204ece_00204fa6\n"
        "movl 4(%esi), %ecx\n" /* line 186 | compptr */
        "movl 8(%ebp), %edi\n" /* cinfo, output_col */
        "movl 0x1a4(%edi), %eax\n" /* output_col */
        "movl 4(%eax, %ecx, 4), %eax\n"
        "movl %eax, -0x14(%ebp)\n" /* inverse_DCT */
        "movl -0x40(%ebp), %eax\n" /* line 187 | MCU_col_num */
        "cmpl %eax, -0x3c(%ebp)\n" /* last_MCU_col */
        "jbe .Lf204ece_002050e4\n"
        "movl 0x34(%esi), %edx\n" /* compptr */
        "movl %edx, -0x20(%ebp)\n" /* useful_width */
        ".Lf204ece_00204ffa:\n"
        "movl -0x24(%ebp), %edx\n" /* line 189 | yoffset */
        "imull 0x24(%esi), %edx\n" /* compptr */
        "movl 0xc(%ebp), %edi\n" /* output_buf, output_col */
        "movl (%edi, %ecx, 4), %eax\n" /* output_col */
        "leal (%eax, %edx, 4), %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* output_ptr */
        "movl -0x40(%ebp), %eax\n" /* line 191 | MCU_col_num */
        "imull 0x40(%esi), %eax\n" /* compptr */
        "movl %eax, -0x18(%ebp)\n" /* start_col */
        "movl 0x38(%esi), %eax\n" /* line 192 | compptr */
        "testl %eax, %eax\n"
        "jle .Lf204ece_00204fac\n"
        "movl $0, -0x28(%ebp)\n" /* yindex */
        ".Lf204ece_00205025:\n"
        "movl -0x38(%ebp), %ecx\n" /* line 193 | last_iMCU_row */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "cmpl 0x88(%edx), %ecx\n"
        "ja .Lf204ece_0020503e\n"
        "movl -0x28(%ebp), %eax\n" /* yindex */
        "addl -0x24(%ebp), %eax\n" /* yoffset */
        "cmpl 0x48(%esi), %eax\n" /* compptr */
        "jge .Lf204ece_00205045\n"
        ".Lf204ece_0020503e:\n"
        "movl -0x20(%ebp), %eax\n" /* line 196 | useful_width */
        "testl %eax, %eax\n"
        "jg .Lf204ece_00205092\n"
        ".Lf204ece_00205045:\n"
        "movl 0x24(%esi), %eax\n" /* compptr */
        ".Lf204ece_00205048:\n"
        "movl 0x34(%esi), %ecx\n" /* line 203 | compptr */
        "addl %ecx, -0x34(%ebp)\n" /* blkn */
        "movl -0x1c(%ebp), %edi\n" /* line 204 | output_ptr, output_col */
        "leal (%edi, %eax, 4), %edi\n" /* output_col */
        "movl %edi, -0x1c(%ebp)\n" /* output_col, output_ptr */
        "addl $1, -0x28(%ebp)\n" /* line 192 | yindex */
        "movl -0x28(%ebp), %eax\n" /* yindex */
        "cmpl 0x38(%esi), %eax\n" /* compptr */
        "jl .Lf204ece_00205025\n"
        "addl $1, -0x30(%ebp)\n" /* line 179 | ci */
        "addl $4, -0xc(%ebp)\n"
        "movl -0x30(%ebp), %ecx\n" /* ci */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "cmpl 0x12c(%edx), %ecx\n"
        "jl .Lf204ece_00204fc6\n"
        ".Lf204ece_0020507d:\n"
        "addl $1, -0x40(%ebp)\n" /* line 163 | MCU_col_num */
        "movl -0x40(%ebp), %esi\n" /* line 162 | MCU_col_num, compptr */
        "cmpl %esi, -0x3c(%ebp)\n" /* compptr, last_MCU_col */
        "jae .Lf204ece_00204f47\n"
        "jmp .Lf204ece_00204f16\n"
        ".Lf204ece_00205092:\n"
        "movl -0x34(%ebp), %edi\n" /* line 196 | blkn, output_col */
        "movl -0x44(%ebp), %eax\n" /* coef */
        "leal 0x20(%eax, %edi, 4), %edi\n" /* output_col */
        "movl %edi, -0x10(%ebp)\n" /* output_col */
        "movl -0x18(%ebp), %edi\n" /* start_col, output_col */
        "movl $0, -0x2c(%ebp)\n" /* xindex */
        ".Lf204ece_002050a9:\n"
        "movl %edi, 0x10(%esp)\n" /* line 197 | output_col */
        "movl -0x1c(%ebp), %eax\n" /* output_ptr */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x10(%ebp), %edx\n"
        "movl (%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* compptr */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %ecx, (%esp)\n"
        "calll *-0x14(%ebp)\n" /* inverse_DCT */
        "movl 0x24(%esi), %eax\n" /* line 200 | compptr */
        "addl %eax, %edi\n" /* output_col */
        "addl $1, -0x2c(%ebp)\n" /* line 196 | xindex */
        "addl $4, -0x10(%ebp)\n"
        "movl -0x2c(%ebp), %edx\n" /* xindex */
        "cmpl %edx, -0x20(%ebp)\n" /* useful_width */
        "jne .Lf204ece_002050a9\n"
        "jmp .Lf204ece_00205048\n"
        ".Lf204ece_002050e4:\n"
        "movl 0x44(%esi), %edi\n" /* line 187 | compptr, output_col */
        "movl %edi, -0x20(%ebp)\n" /* output_col, useful_width */
        "jmp .Lf204ece_00204ffa\n"
        ".Lf204ece_002050ef:\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "addl $1, 0x90(%ecx)\n" /* line 212 */
        "movl 0x88(%ecx), %edx\n" /* line 213 */
        "addl $1, %edx\n"
        "movl %edx, 0x88(%ecx)\n"
        "cmpl %eax, %edx\n"
        "jae .Lf204ece_0020517c\n"
        /* { scope 2 */
        ".Lf204ece_0020510c:\n"
        "movl 8(%ebp), %esi\n" /* line 82 | cinfo */
        "movl 0x190(%esi), %ecx\n" /* coef */
        "cmpl $1, 0x12c(%esi)\n" /* line 88 */
        "jle .Lf204ece_00205197\n"
        "movl $1, 0x1c(%ecx)\n" /* line 89 */
        ".Lf204ece_00205125:\n"
        "movl $0, 0x14(%ecx)\n" /* line 97 */
        "movl $0, 0x18(%ecx)\n" /* line 98 */
        "movl $3, %eax\n"
        /* } scope */
        "addl $0x60, %esp\n" /* line 220 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf204ece_0020513f:\n"
        "movl -0x24(%ebp), %edi\n" /* line 169 | yoffset, output_col */
        "movl -0x44(%ebp), %esi\n" /* coef, compptr */
        "movl %edi, 0x18(%esi)\n" /* output_col, compptr */
        "movl -0x40(%ebp), %eax\n" /* line 170 | MCU_col_num */
        "movl %eax, 0x14(%esi)\n" /* compptr */
        "xorl %eax, %eax\n"
        "addl $0x60, %esp\n" /* line 220 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf204ece_00205157:\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 0x124(%edx), %eax\n"
        "movl %edx, %ecx\n"
        "addl $1, 0x90(%ecx)\n" /* line 212 */
        "movl 0x88(%ecx), %edx\n" /* line 213 */
        "addl $1, %edx\n"
        "movl %edx, 0x88(%ecx)\n"
        "cmpl %eax, %edx\n"
        "jb .Lf204ece_0020510c\n"
        ".Lf204ece_0020517c:\n"
        "movl 8(%ebp), %ecx\n" /* line 218 | cinfo */
        "movl 0x198(%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *0xc(%eax)\n"
        "movl $4, %eax\n"
        "addl $0x60, %esp\n" /* line 220 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2 */
        ".Lf204ece_00205197:\n"
        "subl $1, %eax\n" /* line 91 */
        "cmpl %eax, %edx\n"
        "jae .Lf204ece_002051b2\n"
        "movl 8(%ebp), %edi\n" /* line 92 | cinfo */
        "movl 0x130(%edi), %eax\n"
        "movl 0xc(%eax), %eax\n"
        "movl %eax, 0x1c(%ecx)\n"
        "jmp .Lf204ece_00205125\n"
        ".Lf204ece_002051b2:\n"
        "movl 8(%ebp), %edx\n" /* line 94 | cinfo */
        "movl 0x130(%edx), %eax\n"
        "movl 0x48(%eax), %eax\n"
        "movl %eax, 0x1c(%ecx)\n"
        "jmp .Lf204ece_00205125\n"
    );
}

/* line 229 */
static __attribute__((naked))
int dummy_consume_data(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 229 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n" /* line 231 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 316 */
static __attribute__((naked))
int decompress_data(j_decompress_ptr cinfo, JSAMPIMAGE output_buf)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 316 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x50, %esp\n"
        "movl 8(%ebp), %edi\n" /* cinfo */
        "movl 0x190(%edi), %esi\n" /* line 317 | cinfo, coef */
        "movl 0x124(%edi), %eax\n" /* line 318 | cinfo */
        "subl $1, %eax\n"
        "movl %eax, -0x34(%ebp)\n" /* last_iMCU_row */
        ".Lf2051cd_002051ea:\n"
        "movl 0x8c(%edi), %eax\n" /* line 329 | cinfo */
        "cmpl %eax, 0x84(%edi)\n" /* cinfo */
        "jl .Lf2051cd_00205208\n"
        "jne .Lf2051cd_00205220\n"
        "movl 0x88(%edi), %eax\n" /* cinfo */
        "cmpl 0x90(%edi), %eax\n" /* cinfo */
        "ja .Lf2051cd_00205220\n"
        ".Lf2051cd_00205208:\n"
        "movl 0x198(%edi), %eax\n" /* line 332 | cinfo */
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "testl %eax, %eax\n"
        "jne .Lf2051cd_002051ea\n"
        "xorl %eax, %eax\n"
        ".Lf2051cd_00205219:\n"
        "addl $0x50, %esp\n" /* line 374 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2051cd_00205220:\n"
        "movl 0xcc(%edi), %edx\n" /* line 337 | cinfo */
        "movl %edx, -0x14(%ebp)\n" /* compptr */
        "movl 0x2c(%edi), %eax\n" /* cinfo */
        "testl %eax, %eax\n"
        "jle .Lf2051cd_00205359\n"
        "movl %esi, -0xc(%ebp)\n" /* buffer_ptr */
        "movl $0, -0x2c(%ebp)\n" /* ci */
        "jmp .Lf2051cd_00205258\n"
        ".Lf2051cd_00205240:\n"
        "addl $1, -0x2c(%ebp)\n" /* line 338 | ci */
        "addl $0x54, -0x14(%ebp)\n" /* compptr */
        "addl $4, -0xc(%ebp)\n"
        "movl -0x2c(%ebp), %edx\n" /* line 337 | ci */
        "cmpl 0x2c(%edi), %edx\n" /* cinfo */
        "jge .Lf2051cd_00205359\n"
        ".Lf2051cd_00205258:\n"
        "movl -0x14(%ebp), %ecx\n" /* line 340 | compptr */
        "cmpb $0, 0x30(%ecx)\n"
        "je .Lf2051cd_00205240\n"
        "movl 0xc(%ecx), %eax\n" /* line 343 */
        "movl 4(%edi), %edx\n" /* cinfo */
        "movl $0, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "imull 0x90(%edi), %eax\n" /* cinfo */
        "movl %eax, 8(%esp)\n"
        "movl -0xc(%ebp), %ecx\n"
        "movl 0x48(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *0x20(%edx)\n"
        "movl %eax, -0x20(%ebp)\n" /* buffer */
        "movl -0x34(%ebp), %eax\n" /* line 348 | last_iMCU_row */
        "cmpl 0x90(%edi), %eax\n" /* cinfo */
        "jbe .Lf2051cd_0020537c\n"
        "movl -0x14(%ebp), %edx\n" /* line 349 | compptr */
        "movl 0xc(%edx), %edx\n"
        "movl %edx, -0x24(%ebp)\n" /* block_rows */
        ".Lf2051cd_002052a9:\n"
        "movl 0x1a4(%edi), %eax\n" /* line 355 | cinfo */
        "movl -0x2c(%ebp), %ecx\n" /* ci */
        "movl 4(%eax, %ecx, 4), %eax\n"
        "movl %eax, -0x10(%ebp)\n" /* inverse_DCT */
        "movl 0xc(%ebp), %eax\n" /* line 356 | output_buf */
        "movl (%eax, %ecx, 4), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* output_ptr */
        "movl -0x24(%ebp), %esi\n" /* line 358 | block_rows, buffer_ptr */
        "testl %esi, %esi\n" /* buffer_ptr */
        "jle .Lf2051cd_00205240\n"
        "movl $0, -0x28(%ebp)\n" /* block_row */
        "movl -0x14(%ebp), %edx\n" /* compptr */
        "addl $0x1c, %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "movl -0x28(%ebp), %ecx\n" /* block_row */
        "jmp .Lf2051cd_00205300\n"
        ".Lf2051cd_002052e2:\n"
        "movl 0x24(%edx), %eax\n"
        ".Lf2051cd_002052e5:\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 367 | output_ptr */
        "leal (%ecx, %eax, 4), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n" /* output_ptr */
        "addl $1, -0x28(%ebp)\n" /* line 358 | block_row */
        "movl -0x28(%ebp), %eax\n" /* block_row */
        "cmpl %eax, -0x24(%ebp)\n" /* block_rows */
        "je .Lf2051cd_00205240\n"
        "movl %eax, %ecx\n"
        ".Lf2051cd_00205300:\n"
        "movl -0x20(%ebp), %eax\n" /* line 359 | buffer */
        "movl (%eax, %ecx, 4), %esi\n" /* buffer_ptr */
        "movl -0x14(%ebp), %edx\n" /* line 361 | compptr */
        "movl 0x1c(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf2051cd_002052e2\n"
        "movl $0, -0x18(%ebp)\n" /* output_col */
        "movl $0, -0x30(%ebp)\n" /* block_num */
        ".Lf2051cd_0020531e:\n"
        "movl -0x18(%ebp), %ecx\n" /* line 362 | output_col */
        "movl %ecx, 0x10(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* output_ptr */
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* buffer_ptr */
        "movl -0x14(%ebp), %edx\n" /* compptr */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *-0x10(%ebp)\n" /* inverse_DCT */
        "subl $-0x80, %esi\n" /* line 364 | buffer_ptr */
        "movl -0x14(%ebp), %ecx\n" /* line 365 | compptr */
        "movl 0x24(%ecx), %eax\n"
        "addl %eax, -0x18(%ebp)\n" /* output_col */
        "addl $1, -0x30(%ebp)\n" /* line 361 | block_num */
        "movl -0x30(%ebp), %ecx\n" /* block_num */
        "movl -0x38(%ebp), %edx\n"
        "cmpl (%edx), %ecx\n"
        "jb .Lf2051cd_0020531e\n"
        "jmp .Lf2051cd_002052e5\n"
        ".Lf2051cd_00205359:\n"
        "movl 0x90(%edi), %eax\n" /* line 371 | cinfo */
        "addl $1, %eax\n"
        "movl %eax, 0x90(%edi)\n" /* cinfo */
        "cmpl 0x124(%edi), %eax\n" /* cinfo */
        "jae .Lf2051cd_00205399\n"
        "movl $3, %eax\n"
        "addl $0x50, %esp\n" /* line 374 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2051cd_0020537c:\n"
        "movl -0x14(%ebp), %ecx\n" /* line 352 | compptr */
        "movl 0xc(%ecx), %ecx\n"
        "movl -0x14(%ebp), %edx\n" /* compptr */
        "movl 0x20(%edx), %eax\n"
        "xorl %edx, %edx\n"
        "divl %ecx\n"
        "testl %edx, %edx\n" /* line 353 */
        "cmovel %ecx, %edx\n"
        "movl %edx, -0x24(%ebp)\n" /* block_rows */
        "jmp .Lf2051cd_002052a9\n"
        ".Lf2051cd_00205399:\n"
        "movl $4, %eax\n" /* line 371 */
        "jmp .Lf2051cd_00205219\n"
    );
}

/* line 462 */
static __attribute__((naked))
int decompress_smooth_data(j_decompress_ptr cinfo, JSAMPIMAGE output_buf)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 462 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x150, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 463 | cinfo */
        "movl 0x190(%eax), %eax\n"
        "movl %eax, -0x118(%ebp)\n" /* coef */
        "movl 8(%ebp), %edx\n" /* line 464 | cinfo */
        "movl 0x124(%edx), %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x114(%ebp)\n" /* last_iMCU_row */
        "movl %edx, %eax\n"
        "jmp .Lf2053a3_002053d6\n"
        ".Lf2053a3_002053d3:\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        ".Lf2053a3_002053d6:\n"
        "movl 0x84(%eax), %edx\n" /* line 482 */
        "movl %eax, %ecx\n"
        "movl 0x8c(%eax), %eax\n"
        "cmpl %eax, %edx\n"
        "jg .Lf2053a3_0020543b\n"
        "movl %ecx, %esi\n" /* pred */
        "movl 0x198(%ecx), %ecx\n"
        "cmpb $0, 0x11(%ecx)\n"
        "jne .Lf2053a3_00205c81\n"
        "cmpl %eax, %edx\n" /* line 484 */
        "jne .Lf2053a3_00205423\n"
        "movl 8(%ebp), %esi\n" /* line 491 | cinfo, pred */
        "xorl %eax, %eax\n"
        "cmpl $0, 0x174(%esi)\n" /* pred */
        "sete %al\n"
        "movl %esi, %edx\n" /* pred */
        "movl 0x90(%esi), %esi\n" /* pred */
        "addl %esi, %eax\n" /* pred */
        "cmpl %eax, 0x88(%edx)\n"
        "ja .Lf2053a3_00205c92\n"
        ".Lf2053a3_00205423:\n"
        "movl 8(%ebp), %esi\n" /* line 494 | cinfo, pred */
        "movl %esi, (%esp)\n" /* pred */
        "calll *(%ecx)\n"
        "testl %eax, %eax\n"
        "jne .Lf2053a3_002053d3\n"
        "xorl %eax, %eax\n"
        ".Lf2053a3_00205431:\n"
        "addl $0x150, %esp\n" /* line 666 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2053a3_0020543b:\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 0x90(%edx), %esi\n" /* pred */
        "movl %edx, %ecx\n"
        "movl %edx, %eax\n"
        ".Lf2053a3_00205448:\n"
        "movl 0xcc(%ecx), %ecx\n" /* line 499 */
        "movl %ecx, -0xec(%ebp)\n" /* compptr */
        "movl 0x2c(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf2053a3_00205bb9\n"
        "movl -0x118(%ebp), %edx\n" /* coef */
        "movl %edx, -0x8c(%ebp)\n"
        "movl $0, -0x108(%ebp)\n" /* ci */
        "movl $0, -0x90(%ebp)\n"
        "leal -0x88(%ebp), %ecx\n" /* workspace */
        "movl %ecx, -0x120(%ebp)\n"
        ".Lf2053a3_0020548b:\n"
        "movl -0xec(%ebp), %eax\n" /* line 502 | compptr */
        "cmpb $0, 0x30(%eax)\n"
        "je .Lf2053a3_00205b8b\n"
        "cmpl %esi, -0x114(%ebp)\n" /* line 505 | pred, last_iMCU_row */
        "jbe .Lf2053a3_00205bf7\n"
        "movl 0xc(%eax), %edx\n" /* line 506 */
        "movl %edx, -0x100(%ebp)\n" /* block_rows */
        "movl %edx, %edi\n" /* buffer_ptr */
        "movl %edx, %ecx\n" /* line 507 */
        "addl %ecx, %ecx\n"
        "movb $0, -0xe1(%ebp)\n" /* last_row */
        ".Lf2053a3_002054bd:\n"
        "testl %esi, %esi\n" /* line 517 | pred */
        "je .Lf2053a3_00205c28\n"
        ".Lf2053a3_002054c5:\n"
        "movl 8(%ebp), %eax\n" /* line 519 | cinfo */
        "movl 4(%eax), %edx\n"
        "movl $0, 0x10(%esp)\n"
        "leal (%ecx, %edi), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -1(%esi), %eax\n" /* pred */
        "imull %edi, %eax\n" /* buffer_ptr */
        "movl %eax, 8(%esp)\n"
        "movl -0x8c(%ebp), %ecx\n"
        "movl 0x48(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %esi\n" /* cinfo, pred */
        "movl %esi, (%esp)\n" /* pred */
        "calll *0x20(%edx)\n"
        "movl -0xec(%ebp), %ecx\n" /* line 523 | compptr */
        "movl 0xc(%ecx), %edx\n"
        "leal (%eax, %edx, 4), %ecx\n"
        "movb $0, -0xe2(%ebp)\n" /* first_row */
        ".Lf2053a3_0020550d:\n"
        "movl -0x90(%ebp), %edx\n" /* line 532 */
        "movl -0x118(%ebp), %esi\n" /* coef, pred */
        "addl 0x70(%esi), %edx\n" /* pred */
        "movl -0xec(%ebp), %esi\n" /* line 533 | compptr, pred */
        "movl 0x4c(%esi), %eax\n" /* pred */
        "movzwl (%eax), %esi\n" /* line 534 | pred */
        "movl %esi, -0xe0(%ebp)\n" /* pred, Q00 */
        "movzwl 2(%eax), %esi\n" /* line 535 | pred */
        "movl %esi, -0xdc(%ebp)\n" /* pred, Q01 */
        "movzwl 0x10(%eax), %esi\n" /* line 536 | pred */
        "movl %esi, -0xd4(%ebp)\n" /* pred, Q10 */
        "movzwl 0x20(%eax), %esi\n" /* line 537 | pred */
        "movl %esi, -0xcc(%ebp)\n" /* pred, Q20 */
        "movzwl 0x12(%eax), %esi\n" /* line 538 | pred */
        "movl %esi, -0xd0(%ebp)\n" /* pred, Q11 */
        "movzwl 4(%eax), %eax\n" /* line 539 */
        "movl %eax, -0xd8(%ebp)\n" /* Q02 */
        "movl 8(%ebp), %esi\n" /* line 540 | cinfo, pred */
        "movl 0x1a4(%esi), %eax\n" /* pred */
        "movl -0x108(%ebp), %esi\n" /* ci, pred */
        "movl 4(%eax, %esi, 4), %eax\n"
        "movl %eax, -0xe8(%ebp)\n" /* inverse_DCT */
        "movl 0xc(%ebp), %eax\n" /* line 541 | output_buf */
        "movl (%eax, %esi, 4), %eax\n"
        "movl %eax, -0xf4(%ebp)\n" /* output_ptr */
        "movl -0x100(%ebp), %eax\n" /* line 543 | block_rows */
        "testl %eax, %eax\n"
        "jle .Lf2053a3_00205c63\n"
        "leal 4(%edx), %esi\n" /* pred */
        "movl %esi, -0xa4(%ebp)\n" /* pred */
        "leal 8(%edx), %eax\n"
        "movl %eax, -0xa0(%ebp)\n"
        "leal 0xc(%edx), %esi\n" /* pred */
        "movl %esi, -0x9c(%ebp)\n" /* pred */
        "leal 0x10(%edx), %eax\n"
        "movl %eax, -0x98(%ebp)\n"
        "addl $0x14, %edx\n"
        "movl %edx, -0x94(%ebp)\n"
        "movl $0, -0x104(%ebp)\n" /* block_row */
        "movl %ecx, -0x11c(%ebp)\n"
        "movl %ecx, %edx\n"
        "movl (%edx), %edi\n" /* line 544 | buffer_ptr */
        "cmpb $0, -0xe2(%ebp)\n" /* line 545 | first_row */
        "je .Lf2053a3_00205a2b\n"
        ".Lf2053a3_002055e1:\n"
        "movl -0x104(%ebp), %eax\n" /* block_row */
        "testl %eax, %eax\n"
        "jne .Lf2053a3_00205b80\n"
        "movl %edi, -0xfc(%ebp)\n" /* buffer_ptr, prev_block_row */
        ".Lf2053a3_002055f5:\n"
        "cmpb $0, -0xe1(%ebp)\n" /* line 549 | last_row */
        "je .Lf2053a3_00205613\n"
        "movl -0x100(%ebp), %eax\n" /* block_rows */
        "subl $1, %eax\n"
        "cmpl %eax, -0x104(%ebp)\n" /* block_row */
        "je .Lf2053a3_00205bdf\n"
        ".Lf2053a3_00205613:\n"
        "movl -0x11c(%ebp), %esi\n" /* line 552 | pred */
        "movl 4(%esi), %esi\n" /* pred */
        "movl %esi, -0xf8(%ebp)\n" /* pred, next_block_row */
        "movl %esi, %ecx\n" /* pred */
        ".Lf2053a3_00205624:\n"
        "movl -0xfc(%ebp), %eax\n" /* line 556 | prev_block_row */
        "movswl (%eax), %eax\n"
        "movl %eax, -0xc0(%ebp)\n" /* DC3 */
        "movswl (%edi), %edx\n" /* line 557 | buffer_ptr */
        "movl %edx, -0xb4(%ebp)\n" /* DC6 */
        "movswl (%ecx), %ecx\n" /* line 558 */
        "movl %ecx, -0xa8(%ebp)\n" /* DC9 */
        "movl -0xec(%ebp), %esi\n" /* line 560 | compptr, pred */
        "movl 0x1c(%esi), %eax\n" /* pred */
        "subl $1, %eax\n"
        "movl %eax, -0x10c(%ebp)\n" /* last_block_column */
        "movl -0xc0(%ebp), %edx\n" /* DC3 */
        "movl %edx, -0xc4(%ebp)\n" /* DC2 */
        "movl %edx, -0xc8(%ebp)\n" /* DC1 */
        "movl -0xb4(%ebp), %ecx\n" /* DC6 */
        "movl %ecx, -0xb8(%ebp)\n" /* DC5 */
        "movl %ecx, -0xbc(%ebp)\n" /* DC4 */
        "movl -0xa8(%ebp), %esi\n" /* DC9, pred */
        "movl %esi, -0xac(%ebp)\n" /* pred, DC8 */
        "movl %esi, -0xb0(%ebp)\n" /* pred, DC7 */
        "movl $0, -0xf0(%ebp)\n" /* output_col */
        "movl $0, -0x110(%ebp)\n" /* block_num */
        ".Lf2053a3_002056a1:\n"
        "movl $1, 8(%esp)\n" /* line 563 */
        "movl -0x120(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* buffer_ptr */
        "calll jcopy_block_row\n"
        "movl -0x110(%ebp), %edx\n" /* line 565 | block_num */
        "cmpl %edx, -0x10c(%ebp)\n" /* last_block_column */
        "ja .Lf2053a3_002059aa\n"
        "subl $-0x80, %edi\n" /* buffer_ptr */
        "subl $-0x80, -0xfc(%ebp)\n" /* prev_block_row */
        "subl $-0x80, -0xf8(%ebp)\n" /* next_block_row */
        ".Lf2053a3_002056de:\n"
        "movl -0xa4(%ebp), %edx\n" /* line 575 */
        "movl (%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf2053a3_00205748\n"
        "cmpw $0, -0x86(%ebp)\n"
        "jne .Lf2053a3_00205748\n"
        "movl -0xbc(%ebp), %eax\n" /* line 576 | DC4 */
        "subl -0xb4(%ebp), %eax\n" /* DC6 */
        "imull -0xe0(%ebp), %eax\n" /* Q00 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n" /* line 577 */
        "shll $2, %edx\n"
        "js .Lf2053a3_00205a3b\n"
        "movl -0xdc(%ebp), %eax\n" /* line 578 | Q01 */
        "shll $7, %eax\n"
        "leal (%edx, %eax), %eax\n"
        "movl -0xdc(%ebp), %edx\n" /* Q01 */
        "shll $8, %edx\n"
        "movl %edx, %esi\n" /* pred */
        "cltd\n"
        "idivl %esi\n" /* pred */
        "testl %ecx, %ecx\n" /* line 579 */
        "jle .Lf2053a3_00205741\n"
        "movl $1, %edx\n"
        "shll %cl, %edx\n"
        "cmpl %edx, %eax\n"
        "jl .Lf2053a3_00205741\n"
        "leal -1(%edx), %eax\n" /* line 580 */
        ".Lf2053a3_00205741:\n"
        "movw %ax, -0x86(%ebp)\n" /* line 587 */
        ".Lf2053a3_00205748:\n"
        "movl -0xa0(%ebp), %esi\n" /* line 590 | pred */
        "movl (%esi), %ecx\n" /* pred */
        "testl %ecx, %ecx\n"
        "je .Lf2053a3_002057ac\n"
        "cmpw $0, -0x78(%ebp)\n"
        "jne .Lf2053a3_002057ac\n"
        "movl -0xc4(%ebp), %eax\n" /* line 591 | DC2 */
        "subl -0xac(%ebp), %eax\n" /* DC8 */
        "imull -0xe0(%ebp), %eax\n" /* Q00 */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n" /* line 592 */
        "shll $2, %edx\n"
        "js .Lf2053a3_00205b3f\n"
        "movl -0xd4(%ebp), %eax\n" /* line 593 | Q10 */
        "shll $7, %eax\n"
        "leal (%edx, %eax), %eax\n"
        "movl -0xd4(%ebp), %edx\n" /* Q10 */
        "shll $8, %edx\n"
        "movl %edx, %esi\n" /* pred */
        "cltd\n"
        "idivl %esi\n" /* pred */
        "testl %ecx, %ecx\n" /* line 594 */
        "jle .Lf2053a3_002057a8\n"
        "movl $1, %edx\n"
        "shll %cl, %edx\n"
        "cmpl %edx, %eax\n"
        "jl .Lf2053a3_002057a8\n"
        "leal -1(%edx), %eax\n" /* line 595 */
        ".Lf2053a3_002057a8:\n"
        "movw %ax, -0x78(%ebp)\n" /* line 602 */
        ".Lf2053a3_002057ac:\n"
        "movl -0x9c(%ebp), %esi\n" /* line 605 | pred */
        "movl (%esi), %ecx\n" /* pred */
        "testl %ecx, %ecx\n"
        "je .Lf2053a3_00205817\n"
        "cmpw $0, -0x68(%ebp)\n"
        "jne .Lf2053a3_00205817\n"
        "movl -0xac(%ebp), %eax\n" /* line 606 | DC8 */
        "addl -0xc4(%ebp), %eax\n" /* DC2 */
        "movl -0xb8(%ebp), %edx\n" /* DC5 */
        "addl %edx, %edx\n"
        "subl %edx, %eax\n"
        "imull -0xe0(%ebp), %eax\n" /* Q00 */
        "leal (%eax, %eax, 8), %edx\n"
        "testl %edx, %edx\n" /* line 607 */
        "js .Lf2053a3_00205afe\n"
        "movl -0xcc(%ebp), %eax\n" /* line 608 | Q20 */
        "shll $7, %eax\n"
        "leal (%edx, %eax), %eax\n"
        "movl -0xcc(%ebp), %edx\n" /* Q20 */
        "shll $8, %edx\n"
        "movl %edx, %esi\n" /* pred */
        "cltd\n"
        "idivl %esi\n" /* pred */
        "testl %ecx, %ecx\n" /* line 609 */
        "jle .Lf2053a3_00205813\n"
        "movl $1, %edx\n"
        "shll %cl, %edx\n"
        "cmpl %edx, %eax\n"
        "jl .Lf2053a3_00205813\n"
        "leal -1(%edx), %eax\n" /* line 610 */
        ".Lf2053a3_00205813:\n"
        "movw %ax, -0x68(%ebp)\n" /* line 617 */
        ".Lf2053a3_00205817:\n"
        "movl -0x98(%ebp), %esi\n" /* line 620 | pred */
        "movl (%esi), %ecx\n" /* pred */
        "testl %ecx, %ecx\n"
        "je .Lf2053a3_00205890\n"
        "cmpw $0, -0x76(%ebp)\n"
        "jne .Lf2053a3_00205890\n"
        "movl -0xc0(%ebp), %eax\n" /* line 621 | DC3 */
        "subl %eax, -0xc8(%ebp)\n" /* DC1 */
        "movl -0xb0(%ebp), %edx\n" /* DC7 */
        "subl %edx, -0xc8(%ebp)\n" /* DC1 */
        "movl -0xa8(%ebp), %eax\n" /* DC9 */
        "addl -0xc8(%ebp), %eax\n" /* DC1 */
        "imull -0xe0(%ebp), %eax\n" /* Q00 */
        "leal (%eax, %eax, 4), %edx\n"
        "testl %edx, %edx\n" /* line 622 */
        "js .Lf2053a3_00205abd\n"
        "movl -0xd0(%ebp), %eax\n" /* line 623 | Q11 */
        "shll $7, %eax\n"
        "leal (%edx, %eax), %eax\n"
        "movl -0xd0(%ebp), %edx\n" /* Q11 */
        "shll $8, %edx\n"
        "movl %edx, %esi\n" /* pred */
        "cltd\n"
        "idivl %esi\n" /* pred */
        "testl %ecx, %ecx\n" /* line 624 */
        "jle .Lf2053a3_0020588c\n"
        "movl $1, %edx\n"
        "shll %cl, %edx\n"
        "cmpl %edx, %eax\n"
        "jl .Lf2053a3_0020588c\n"
        "leal -1(%edx), %eax\n" /* line 625 */
        ".Lf2053a3_0020588c:\n"
        "movw %ax, -0x76(%ebp)\n" /* line 632 */
        ".Lf2053a3_00205890:\n"
        "movl -0x94(%ebp), %esi\n" /* line 635 | pred */
        "movl (%esi), %ecx\n" /* pred */
        "testl %ecx, %ecx\n"
        "je .Lf2053a3_00205901\n"
        "cmpw $0, -0x84(%ebp)\n"
        "jne .Lf2053a3_00205901\n"
        "movl -0xb4(%ebp), %eax\n" /* line 636 | DC6 */
        "addl -0xbc(%ebp), %eax\n" /* DC4 */
        "movl -0xb8(%ebp), %edx\n" /* DC5 */
        "addl %edx, %edx\n"
        "subl %edx, %eax\n"
        "imull -0xe0(%ebp), %eax\n" /* Q00 */
        "leal (%eax, %eax, 8), %edx\n"
        "testl %edx, %edx\n" /* line 637 */
        "js .Lf2053a3_00205a7c\n"
        "movl -0xd8(%ebp), %eax\n" /* line 638 | Q02 */
        "shll $7, %eax\n"
        "leal (%edx, %eax), %eax\n"
        "movl -0xd8(%ebp), %edx\n" /* Q02 */
        "shll $8, %edx\n"
        "movl %edx, %esi\n" /* pred */
        "cltd\n"
        "idivl %esi\n" /* pred */
        "testl %ecx, %ecx\n" /* line 639 */
        "jle .Lf2053a3_002058fa\n"
        "movl $1, %edx\n"
        "shll %cl, %edx\n"
        "cmpl %edx, %eax\n"
        "jl .Lf2053a3_002058fa\n"
        "leal -1(%edx), %eax\n" /* line 640 */
        ".Lf2053a3_002058fa:\n"
        "movw %ax, -0x84(%ebp)\n" /* line 647 */
        ".Lf2053a3_00205901:\n"
        "movl -0xf0(%ebp), %ecx\n" /* line 650 | output_col */
        "movl %ecx, 0x10(%esp)\n"
        "movl -0xf4(%ebp), %esi\n" /* output_ptr, pred */
        "movl %esi, 0xc(%esp)\n" /* pred */
        "movl -0x120(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0xec(%ebp), %edx\n" /* compptr */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %ecx, (%esp)\n"
        "calll *-0xe8(%ebp)\n" /* inverse_DCT */
        "movl -0xec(%ebp), %esi\n" /* line 657 | compptr, pred */
        "movl 0x24(%esi), %eax\n" /* pred */
        "addl %eax, -0xf0(%ebp)\n" /* output_col */
        "addl $1, -0x110(%ebp)\n" /* line 561 | block_num */
        "movl -0x110(%ebp), %edx\n" /* block_num */
        "cmpl %edx, -0x10c(%ebp)\n" /* last_block_column */
        "jb .Lf2053a3_002059e7\n"
        "movl -0xac(%ebp), %ecx\n" /* DC8 */
        "movl %ecx, -0xb0(%ebp)\n" /* DC7 */
        "movl -0xa8(%ebp), %esi\n" /* DC9, pred */
        "movl %esi, -0xac(%ebp)\n" /* pred, DC8 */
        "movl -0xb8(%ebp), %eax\n" /* DC5 */
        "movl %eax, -0xbc(%ebp)\n" /* DC4 */
        "movl -0xb4(%ebp), %edx\n" /* DC6 */
        "movl %edx, -0xb8(%ebp)\n" /* DC5 */
        "movl -0xc4(%ebp), %ecx\n" /* DC2 */
        "movl %ecx, -0xc8(%ebp)\n" /* DC1 */
        "movl -0xc0(%ebp), %esi\n" /* DC3, pred */
        "movl %esi, -0xc4(%ebp)\n" /* pred, DC2 */
        "jmp .Lf2053a3_002056a1\n"
        ".Lf2053a3_002059aa:\n"
        "subl $-0x80, -0xfc(%ebp)\n" /* line 566 | prev_block_row */
        "movl -0xfc(%ebp), %ecx\n" /* prev_block_row */
        "movswl (%ecx), %ecx\n"
        "movl %ecx, -0xc0(%ebp)\n" /* DC3 */
        "subl $-0x80, %edi\n" /* line 567 | buffer_ptr */
        "movswl (%edi), %esi\n" /* buffer_ptr, pred */
        "movl %esi, -0xb4(%ebp)\n" /* pred, DC6 */
        "subl $-0x80, -0xf8(%ebp)\n" /* line 568 | next_block_row */
        "movl -0xf8(%ebp), %eax\n" /* next_block_row */
        "movswl (%eax), %eax\n"
        "movl %eax, -0xa8(%ebp)\n" /* DC9 */
        "jmp .Lf2053a3_002056de\n"
        ".Lf2053a3_002059e7:\n"
        "movl -0xf4(%ebp), %edx\n" /* line 659 | output_ptr */
        "leal (%edx, %eax, 4), %edx\n"
        "movl %edx, -0xf4(%ebp)\n" /* output_ptr */
        "addl $1, -0x104(%ebp)\n" /* line 543 | block_row */
        "addl $4, -0x11c(%ebp)\n"
        "movl -0x104(%ebp), %ecx\n" /* block_row */
        "cmpl %ecx, -0x100(%ebp)\n" /* block_rows */
        "je .Lf2053a3_00205bec\n"
        "movl -0x11c(%ebp), %edx\n"
        "movl (%edx), %edi\n" /* line 544 | buffer_ptr */
        "cmpb $0, -0xe2(%ebp)\n" /* line 545 | first_row */
        "jne .Lf2053a3_002055e1\n"
        ".Lf2053a3_00205a2b:\n"
        "movl %edx, %ecx\n"
        ".Lf2053a3_00205a2d:\n"
        "movl -4(%ecx), %ecx\n" /* line 548 */
        "movl %ecx, -0xfc(%ebp)\n" /* prev_block_row */
        "jmp .Lf2053a3_002055f5\n"
        ".Lf2053a3_00205a3b:\n"
        "movl -0xdc(%ebp), %esi\n" /* line 582 | Q01, pred */
        "shll $7, %esi\n" /* pred */
        "subl %edx, %esi\n" /* pred */
        "movl -0xdc(%ebp), %eax\n" /* Q01 */
        "shll $8, %eax\n"
        "movl %eax, -0x12c(%ebp)\n"
        "movl %esi, %eax\n" /* pred */
        "cltd\n"
        "idivl -0x12c(%ebp)\n"
        "movl %eax, %esi\n" /* pred */
        "testl %ecx, %ecx\n" /* line 583 */
        "jle .Lf2053a3_00205a73\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "leal -1(%eax), %edx\n" /* line 584 */
        "cmpl %eax, %esi\n" /* pred */
        "cmovgel %edx, %esi\n" /* pred */
        ".Lf2053a3_00205a73:\n"
        "movl %esi, %eax\n" /* line 585 | pred */
        "negl %eax\n"
        "jmp .Lf2053a3_00205741\n"
        ".Lf2053a3_00205a7c:\n"
        "movl -0xd8(%ebp), %esi\n" /* line 642 | Q02, pred */
        "shll $7, %esi\n" /* pred */
        "subl %edx, %esi\n" /* pred */
        "movl -0xd8(%ebp), %eax\n" /* Q02 */
        "shll $8, %eax\n"
        "movl %eax, -0x12c(%ebp)\n"
        "movl %esi, %eax\n" /* pred */
        "cltd\n"
        "idivl -0x12c(%ebp)\n"
        "movl %eax, %esi\n" /* pred */
        "testl %ecx, %ecx\n" /* line 643 */
        "jle .Lf2053a3_00205ab4\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "leal -1(%eax), %edx\n" /* line 644 */
        "cmpl %eax, %esi\n" /* pred */
        "cmovgel %edx, %esi\n" /* pred */
        ".Lf2053a3_00205ab4:\n"
        "movl %esi, %eax\n" /* line 645 | pred */
        "negl %eax\n"
        "jmp .Lf2053a3_002058fa\n"
        ".Lf2053a3_00205abd:\n"
        "movl -0xd0(%ebp), %esi\n" /* line 627 | Q11, pred */
        "shll $7, %esi\n" /* pred */
        "subl %edx, %esi\n" /* pred */
        "movl -0xd0(%ebp), %eax\n" /* Q11 */
        "shll $8, %eax\n"
        "movl %eax, -0x12c(%ebp)\n"
        "movl %esi, %eax\n" /* pred */
        "cltd\n"
        "idivl -0x12c(%ebp)\n"
        "movl %eax, %esi\n" /* pred */
        "testl %ecx, %ecx\n" /* line 628 */
        "jle .Lf2053a3_00205af5\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "leal -1(%eax), %edx\n" /* line 629 */
        "cmpl %eax, %esi\n" /* pred */
        "cmovgel %edx, %esi\n" /* pred */
        ".Lf2053a3_00205af5:\n"
        "movl %esi, %eax\n" /* line 630 | pred */
        "negl %eax\n"
        "jmp .Lf2053a3_0020588c\n"
        ".Lf2053a3_00205afe:\n"
        "movl -0xcc(%ebp), %esi\n" /* line 612 | Q20, pred */
        "shll $7, %esi\n" /* pred */
        "subl %edx, %esi\n" /* pred */
        "movl -0xcc(%ebp), %eax\n" /* Q20 */
        "shll $8, %eax\n"
        "movl %eax, -0x12c(%ebp)\n"
        "movl %esi, %eax\n" /* pred */
        "cltd\n"
        "idivl -0x12c(%ebp)\n"
        "movl %eax, %esi\n" /* pred */
        "testl %ecx, %ecx\n" /* line 613 */
        "jle .Lf2053a3_00205b36\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "leal -1(%eax), %edx\n" /* line 614 */
        "cmpl %eax, %esi\n" /* pred */
        "cmovgel %edx, %esi\n" /* pred */
        ".Lf2053a3_00205b36:\n"
        "movl %esi, %eax\n" /* line 615 | pred */
        "negl %eax\n"
        "jmp .Lf2053a3_00205813\n"
        ".Lf2053a3_00205b3f:\n"
        "movl -0xd4(%ebp), %esi\n" /* line 597 | Q10, pred */
        "shll $7, %esi\n" /* pred */
        "subl %edx, %esi\n" /* pred */
        "movl -0xd4(%ebp), %eax\n" /* Q10 */
        "shll $8, %eax\n"
        "movl %eax, -0x12c(%ebp)\n"
        "movl %esi, %eax\n" /* pred */
        "cltd\n"
        "idivl -0x12c(%ebp)\n"
        "movl %eax, %esi\n" /* pred */
        "testl %ecx, %ecx\n" /* line 598 */
        "jle .Lf2053a3_00205b77\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "leal -1(%eax), %edx\n" /* line 599 */
        "cmpl %eax, %esi\n" /* pred */
        "cmovgel %edx, %esi\n" /* pred */
        ".Lf2053a3_00205b77:\n"
        "movl %esi, %eax\n" /* line 600 | pred */
        "negl %eax\n"
        "jmp .Lf2053a3_002057a8\n"
        ".Lf2053a3_00205b80:\n"
        "movl -0x11c(%ebp), %ecx\n"
        "jmp .Lf2053a3_00205a2d\n"
        ".Lf2053a3_00205b8b:\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        ".Lf2053a3_00205b8e:\n"
        "addl $1, -0x108(%ebp)\n" /* line 500 | ci */
        "addl $0x54, -0xec(%ebp)\n" /* compptr */
        "addl $0x18, -0x90(%ebp)\n"
        "addl $4, -0x8c(%ebp)\n"
        "movl -0x108(%ebp), %ecx\n" /* line 499 | ci */
        "cmpl 0x2c(%eax), %ecx\n"
        "jl .Lf2053a3_0020548b\n"
        ".Lf2053a3_00205bb9:\n"
        "movl %eax, %edx\n"
        "leal 1(%esi), %eax\n" /* line 663 | pred */
        "movl %eax, 0x90(%edx)\n"
        "cmpl 0x124(%edx), %eax\n"
        "jae .Lf2053a3_00205c9d\n"
        "movl $3, %eax\n"
        "addl $0x150, %esp\n" /* line 666 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2053a3_00205bdf:\n"
        "movl %edi, -0xf8(%ebp)\n" /* line 549 | buffer_ptr, next_block_row */
        "movl %edi, %ecx\n" /* buffer_ptr */
        "jmp .Lf2053a3_00205624\n"
        ".Lf2053a3_00205bec:\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 0x90(%eax), %esi\n" /* pred */
        "jmp .Lf2053a3_00205b8e\n"
        ".Lf2053a3_00205bf7:\n"
        "movl -0xec(%ebp), %eax\n" /* line 511 | compptr */
        "movl 0xc(%eax), %ecx\n"
        "movl %ecx, %edi\n" /* buffer_ptr */
        "movl 0x20(%eax), %eax\n"
        "xorl %edx, %edx\n"
        "divl %ecx\n"
        "movl %edx, -0x100(%ebp)\n" /* block_rows */
        "testl %edx, %edx\n" /* line 512 */
        "jne .Lf2053a3_00205c73\n"
        "movl %ecx, -0x100(%ebp)\n" /* block_rows */
        "movb $1, -0xe1(%ebp)\n" /* last_row */
        "testl %esi, %esi\n" /* line 517 | pred */
        "jne .Lf2053a3_002054c5\n"
        ".Lf2053a3_00205c28:\n"
        "movl 8(%ebp), %esi\n" /* line 526 | cinfo, pred */
        "movl 4(%esi), %edx\n" /* pred */
        "movl $0, 0x10(%esp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl -0x8c(%ebp), %ecx\n"
        "movl 0x48(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* pred */
        "calll *0x20(%edx)\n"
        "movl %eax, %ecx\n"
        "movb $1, -0xe2(%ebp)\n" /* first_row */
        "jmp .Lf2053a3_0020550d\n"
        ".Lf2053a3_00205c63:\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 0x90(%edx), %esi\n" /* pred */
        "movl %edx, %eax\n"
        "jmp .Lf2053a3_00205b8e\n"
        ".Lf2053a3_00205c73:\n"
        "movl %edx, %ecx\n"
        "movb $1, -0xe1(%ebp)\n" /* line 512 | last_row */
        "jmp .Lf2053a3_002054bd\n"
        ".Lf2053a3_00205c81:\n"
        "movl 0x90(%esi), %esi\n" /* pred */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "jmp .Lf2053a3_00205448\n"
        ".Lf2053a3_00205c92:\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "jmp .Lf2053a3_00205448\n"
        ".Lf2053a3_00205c9d:\n"
        "movl $4, %eax\n" /* line 663 */
        "jmp .Lf2053a3_00205431\n"
    );
}

/* line 677 */
__attribute__((naked))
void jinit_d_coef_controller(j_decompress_ptr cinfo, int need_full_buffer)
{
    __asm__ __volatile__ (
        /* { scope 1: ci, access_rows */
        "pushl %ebp\n" /* line 677 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movzbl 0xc(%ebp), %esi\n" /* need_full_buffer */
        "movl 8(%ebp), %edx\n" /* line 680 | cinfo */
        "movl 4(%edx), %eax\n"
        "movl $0x74, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl %eax, -0x28(%ebp)\n" /* coef */
        "movl 8(%ebp), %ecx\n" /* line 683 | cinfo */
        "movl %eax, 0x190(%ecx)\n"
        "leal 0x181(%ebx), %eax\n" /* line 684 */
        "movl -0x28(%ebp), %edx\n" /* coef */
        "movl %eax, (%edx)\n"
        "leal -0xfad(%ebx), %eax\n" /* line 685 */
        "movl %eax, 8(%edx)\n"
        "movl $0, 0x70(%edx)\n" /* line 687 */
        "movl %esi, %ecx\n" /* line 691 | need_full_buffer */
        "testb %cl, %cl\n"
        "je .Lf205ca7_00205de0\n"
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 699 | cinfo */
        "movl 0xcc(%eax), %edi\n" /* compptr */
        "movl 0x2c(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lf205ca7_00205dbb\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl $0, -0x24(%ebp)\n" /* ci */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "jmp .Lf205ca7_00205da0\n"
        ".Lf205ca7_00205d28:\n"
        "movl %edx, -0x20(%ebp)\n" /* line 704 | access_rows */
        ".Lf205ca7_00205d2b:\n"
        "movl 8(%ebp), %ecx\n" /* line 707 | cinfo */
        "movl 4(%ecx), %eax\n"
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl %edx, 4(%esp)\n"
        "movl 0x20(%edi), %eax\n" /* compptr */
        "movl %eax, (%esp)\n"
        "calll jround_up\n"
        "movl %eax, %esi\n" /* need_full_buffer */
        "movl 8(%edi), %eax\n" /* compptr */
        "movl %eax, 4(%esp)\n"
        "movl 0x1c(%edi), %eax\n" /* compptr */
        "movl %eax, (%esp)\n"
        "calll jround_up\n"
        "movl -0x20(%ebp), %edx\n" /* access_rows */
        "movl %edx, 0x14(%esp)\n"
        "movl %esi, 0x10(%esp)\n" /* need_full_buffer */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %ecx, (%esp)\n"
        "calll *-0x2c(%ebp)\n"
        "movl -0x1c(%ebp), %edx\n"
        "movl %eax, 0x48(%edx)\n"
        "addl $1, -0x24(%ebp)\n" /* line 700 | ci */
        "addl $0x54, %edi\n" /* compptr */
        "addl $4, %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl -0x24(%ebp), %eax\n" /* line 699 | ci */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "cmpl %eax, 0x2c(%ecx)\n"
        "jle .Lf205ca7_00205dbb\n"
        ".Lf205ca7_00205da0:\n"
        "movl 0xc(%edi), %edx\n" /* line 701 | compptr */
        "cmpb $0, 0xd0(%ecx)\n" /* line 704 */
        "je .Lf205ca7_00205d28\n"
        "leal (%edx, %edx, 2), %eax\n" /* line 705 */
        "movl %eax, -0x20(%ebp)\n" /* access_rows */
        "jmp .Lf205ca7_00205d2b\n"
        ".Lf205ca7_00205dbb:\n"
        "leal 0x1ea(%ebx), %eax\n" /* line 715 */
        "movl -0x28(%ebp), %edx\n" /* coef */
        "movl %eax, 4(%edx)\n"
        "leal -0xae8(%ebx), %eax\n" /* line 716 */
        "movl %eax, 0xc(%edx)\n"
        "movl %edx, %eax\n" /* line 717 */
        "addl $0x48, %eax\n"
        "movl %eax, 0x10(%edx)\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 736 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf205ca7_00205de0:\n"
        "movl 8(%ebp), %ecx\n" /* line 726 | cinfo */
        "movl 4(%ecx), %eax\n"
        "movl $0x500, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *4(%eax)\n"
        "movl -0x28(%ebp), %edx\n" /* coef */
        "movl $0xa, %ecx\n"
        ".Lf205ca7_00205e04:\n"
        "movl %eax, 0x20(%edx)\n" /* line 730 */
        "addl $4, %edx\n"
        "subl $-0x80, %eax\n"
        "subl $1, %ecx\n" /* line 729 */
        "jne .Lf205ca7_00205e04\n"
        "leal -0xaef(%ebx), %eax\n" /* line 732 */
        "movl -0x28(%ebp), %edx\n" /* coef */
        "movl %eax, 4(%edx)\n"
        "leal -0xde7(%ebx), %eax\n" /* line 733 */
        "movl %eax, 0xc(%edx)\n"
        "movl $0, 0x10(%edx)\n" /* line 734 */
        "addl $0x4c, %esp\n" /* line 736 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 108 */
static __attribute__((naked))
void start_input_pass(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 108 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl $0, 0x88(%eax)\n" /* line 109 */
        /* { scope 1 */
        "movl 0x190(%eax), %edx\n" /* line 82 | coef */
        "cmpl $1, 0x12c(%eax)\n" /* line 88 */
        "jle .Lf205e36_00205e6c\n"
        "movl $1, 0x1c(%edx)\n" /* line 89 */
        ".Lf205e36_00205e5c:\n"
        "movl $0, 0x14(%edx)\n" /* line 97 */
        "movl $0, 0x18(%edx)\n" /* line 98 */
        /* } scope */
        "popl %ebp\n" /* line 111 */
        "retl\n"
        /* { scope 1 */
        ".Lf205e36_00205e6c:\n"
        "cmpl $1, 0x124(%eax)\n" /* line 91 */
        "je .Lf205e36_00205e91\n"
        "movl 0x130(%eax), %eax\n" /* line 92 */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, 0x1c(%edx)\n"
        "movl $0, 0x14(%edx)\n" /* line 97 */
        "movl $0, 0x18(%edx)\n" /* line 98 */
        /* } scope */
        "popl %ebp\n" /* line 111 */
        "retl\n"
        /* { scope 1 */
        ".Lf205e36_00205e91:\n"
        "movl 0x130(%eax), %eax\n" /* line 94 */
        "movl 0x48(%eax), %eax\n"
        "movl %eax, 0x1c(%edx)\n"
        "jmp .Lf205e36_00205e5c\n"
    );
}

/* line 245 */
static __attribute__((naked))
int consume_data(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 245 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "addl $-0x80, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 246 | cinfo */
        "movl 0x190(%eax), %eax\n"
        "movl %eax, -0x3c(%ebp)\n" /* coef */
        "movl 8(%ebp), %edx\n" /* line 255 | cinfo */
        "movl 0x12c(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jg .Lf205e9f_0020606a\n"
        "movl %eax, %esi\n" /* compptr */
        "movl %eax, %edi\n"
        ".Lf205e9f_00205ec8:\n"
        "movl 0x18(%esi), %esi\n" /* line 268 | compptr */
        "movl %esi, -0x28(%ebp)\n" /* compptr, yoffset */
        "cmpl %esi, 0x1c(%edi)\n" /* compptr */
        "jle .Lf205e9f_00205ffe\n"
        "shll $2, %esi\n" /* compptr */
        "movl %esi, -0x1c(%ebp)\n" /* compptr */
        "leal 0x20(%edi), %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        ".Lf205e9f_00205ee3:\n"
        "movl -0x3c(%ebp), %edx\n" /* line 270 | coef */
        "movl 0x14(%edx), %edx\n"
        "movl %edx, -0x38(%ebp)\n" /* MCU_col_num */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "cmpl 0x140(%ecx), %edx\n"
        "jae .Lf205e9f_00205fe0\n"
        "movl %ecx, %edx\n"
        ".Lf205e9f_00205efd:\n"
        "movl 0x12c(%edx), %esi\n" /* line 274 | compptr */
        "testl %esi, %esi\n" /* compptr */
        "jle .Lf205e9f_00205fac\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl $0, -0x30(%ebp)\n" /* ci */
        "movl $0, -0x34(%ebp)\n" /* blkn */
        "movl %edx, %edi\n"
        ".Lf205e9f_00205f1e:\n"
        "movl 0x130(%edi), %esi\n" /* line 275 | compptr */
        "movl -0x38(%ebp), %eax\n" /* line 276 | MCU_col_num */
        "imull 0x34(%esi), %eax\n" /* compptr */
        "movl 0x38(%esi), %edx\n" /* line 277 | compptr */
        "testl %edx, %edx\n"
        "jle .Lf205e9f_00205f8e\n"
        "shll $7, %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl -0x1c(%ebp), %edx\n"
        "movl -0x30(%ebp), %eax\n" /* ci */
        "addl -0x18(%ebp, %eax, 4), %edx\n"
        "movl %edx, -0x4c(%ebp)\n"
        "movl $0, -0x2c(%ebp)\n" /* yindex */
        "movl %edx, %ecx\n"
        ".Lf205e9f_00205f4e:\n"
        "movl -0x24(%ebp), %edx\n" /* line 278 */
        "addl (%ecx), %edx\n"
        "movl 0x34(%esi), %edi\n" /* line 279 | compptr */
        "testl %edi, %edi\n"
        "jle .Lf205e9f_00205f79\n"
        "movl -0x34(%ebp), %edi\n" /* blkn */
        "movl -0x3c(%ebp), %ecx\n" /* coef */
        "leal 0x20(%ecx, %edi, 4), %eax\n"
        "xorl %ecx, %ecx\n"
        ".Lf205e9f_00205f66:\n"
        "movl %edx, (%eax)\n" /* line 280 */
        "subl $-0x80, %edx\n"
        "addl $1, %ecx\n" /* line 279 */
        "addl $4, %eax\n"
        "cmpl 0x34(%esi), %ecx\n" /* compptr */
        "jl .Lf205e9f_00205f66\n"
        "addl %ecx, -0x34(%ebp)\n" /* blkn */
        ".Lf205e9f_00205f79:\n"
        "addl $1, -0x2c(%ebp)\n" /* line 277 | yindex */
        "addl $4, -0x4c(%ebp)\n"
        "movl -0x2c(%ebp), %edi\n" /* yindex */
        "cmpl 0x38(%esi), %edi\n" /* compptr */
        "jge .Lf205e9f_00205f8e\n"
        "movl -0x4c(%ebp), %ecx\n"
        "jmp .Lf205e9f_00205f4e\n"
        ".Lf205e9f_00205f8e:\n"
        "addl $1, -0x30(%ebp)\n" /* line 274 | ci */
        "addl $4, -0x20(%ebp)\n"
        "movl -0x30(%ebp), %eax\n" /* ci */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "cmpl 0x12c(%edx), %eax\n"
        "jge .Lf205e9f_00205fac\n"
        "movl -0x20(%ebp), %edi\n"
        "jmp .Lf205e9f_00205f1e\n"
        ".Lf205e9f_00205fac:\n"
        "movl 0x1a0(%edx), %eax\n" /* line 285 */
        "movl -0x44(%ebp), %esi\n" /* compptr */
        "movl %esi, 4(%esp)\n" /* compptr */
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        "testb %al, %al\n"
        "je .Lf205e9f_00206052\n"
        "addl $1, -0x38(%ebp)\n" /* line 271 | MCU_col_num */
        "movl -0x38(%ebp), %eax\n" /* line 270 | MCU_col_num */
        "movl 8(%ebp), %edi\n" /* cinfo */
        "cmpl 0x140(%edi), %eax\n"
        "jae .Lf205e9f_00205fe0\n"
        "movl %edi, %edx\n"
        "jmp .Lf205e9f_00205efd\n"
        ".Lf205e9f_00205fe0:\n"
        "movl -0x3c(%ebp), %ecx\n" /* line 293 | coef */
        "movl $0, 0x14(%ecx)\n"
        "addl $1, -0x28(%ebp)\n" /* line 269 | yoffset */
        "addl $4, -0x1c(%ebp)\n"
        "movl -0x28(%ebp), %esi\n" /* line 268 | yoffset, compptr */
        "cmpl %esi, 0x1c(%ecx)\n" /* compptr */
        "jg .Lf205e9f_00205ee3\n"
        ".Lf205e9f_00205ffe:\n"
        "movl 8(%ebp), %edi\n" /* line 296 | cinfo */
        "movl 0x88(%edi), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, 0x88(%edi)\n"
        "movl 0x124(%edi), %eax\n"
        "cmpl %eax, %edx\n"
        "jae .Lf205e9f_002060df\n"
        /* { scope 2 */
        "movl 0x190(%edi), %ecx\n" /* line 82 | coef */
        "cmpl $1, 0x12c(%edi)\n" /* line 88 */
        "jle .Lf205e9f_002060fa\n"
        "movl $1, 0x1c(%ecx)\n" /* line 89 */
        ".Lf205e9f_00206038:\n"
        "movl $0, 0x14(%ecx)\n" /* line 97 */
        "movl $0, 0x18(%ecx)\n" /* line 98 */
        "movl $3, %eax\n"
        /* } scope */
        "subl $-0x80, %esp\n" /* line 303 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf205e9f_00206052:\n"
        "movl -0x28(%ebp), %edi\n" /* line 287 | yoffset */
        "movl -0x3c(%ebp), %eax\n" /* coef */
        "movl %edi, 0x18(%eax)\n"
        "movl -0x38(%ebp), %edx\n" /* line 288 | MCU_col_num */
        "movl %edx, 0x14(%eax)\n"
        "xorl %eax, %eax\n"
        "subl $-0x80, %esp\n" /* line 303 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf205e9f_0020606a:\n"
        "movl %edx, %esi\n" /* line 255 | compptr */
        "movl $1, %edi\n"
        "leal -0x18(%ebp), %ecx\n" /* buffer */
        "movl %ecx, -0x40(%ebp)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        ".Lf205e9f_0020607a:\n"
        "movl 0x130(%esi), %edx\n" /* line 256 | compptr */
        "movl 0xc(%edx), %eax\n" /* line 257 */
        "movl 4(%ecx), %ecx\n"
        "movl %ecx, -0x5c(%ebp)\n"
        "movl $1, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "imull 0x88(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl -0x3c(%ebp), %edx\n" /* coef */
        "movl 0x48(%edx, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "movl -0x5c(%ebp), %ecx\n"
        "calll *0x20(%ecx)\n"
        "movl -0x40(%ebp), %edx\n"
        "movl %eax, -4(%edx, %edi, 4)\n"
        "movl %edi, %eax\n"
        "addl $1, %edi\n"
        "addl $4, %esi\n" /* compptr */
        "movl 8(%ebp), %ecx\n" /* line 255 | cinfo */
        "cmpl %eax, 0x12c(%ecx)\n"
        "jg .Lf205e9f_0020607a\n"
        "movl -0x3c(%ebp), %esi\n" /* coef, compptr */
        "movl -0x3c(%ebp), %edi\n" /* coef */
        "jmp .Lf205e9f_00205ec8\n"
        ".Lf205e9f_002060df:\n"
        "movl 8(%ebp), %ecx\n" /* line 301 | cinfo */
        "movl 0x198(%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *0xc(%eax)\n"
        "movl $4, %eax\n"
        "subl $-0x80, %esp\n" /* line 303 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2 */
        ".Lf205e9f_002060fa:\n"
        "subl $1, %eax\n" /* line 91 */
        "cmpl %eax, %edx\n"
        "jae .Lf205e9f_00206115\n"
        "movl 8(%ebp), %edx\n" /* line 92 | cinfo */
        "movl 0x130(%edx), %eax\n"
        "movl 0xc(%eax), %eax\n"
        "movl %eax, 0x1c(%ecx)\n"
        "jmp .Lf205e9f_00206038\n"
        ".Lf205e9f_00206115:\n"
        "movl 8(%ebp), %esi\n" /* line 94 | cinfo */
        "movl 0x130(%esi), %eax\n"
        "movl 0x48(%eax), %eax\n"
        "movl %eax, 0x1c(%ecx)\n"
        "jmp .Lf205e9f_00206038\n"
    );
}

