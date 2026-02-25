/* ASM dump from: jcmainct.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jcmainct.c */

#include "common_types.h"
#include "imports.h"

static void start_pass_main(j_compress_ptr cinfo, J_BUF_MODE pass_mode);
static void process_data_simple_main(j_compress_ptr cinfo, JSAMPARRAY input_buf, JDIMENSION *in_row_ctr, JDIMENSION in_rows_avail);
void jinit_c_main_controller(j_compress_ptr cinfo, int need_full_buffer);

/* line 70 */
static __attribute__((naked))
void start_pass_main(j_compress_ptr cinfo, J_BUF_MODE pass_mode)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 70 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl 0xc(%ebp), %eax\n" /* pass_mode */
        "movl 0x144(%ecx), %edx\n" /* line 71 | main */
        "cmpb $0, 0xb4(%ecx)\n" /* line 74 */
        "jne .Lf20b14c_0020b1a0\n"
        "movl $0, 8(%edx)\n" /* line 77 */
        "movl $0, 0xc(%edx)\n" /* line 78 */
        "movb $0, 0x10(%edx)\n" /* line 79 */
        "movl %eax, 0x14(%edx)\n" /* line 80 */
        "testl %eax, %eax\n" /* line 82 */
        "je .Lf20b14c_0020b197\n"
        "movl (%ecx), %eax\n" /* line 100 */
        "movl $4, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, 8(%ebp)\n" /* cinfo */
        "movl (%eax), %ecx\n"
        "popl %ebx\n" /* line 103 */
        "popl %ebp\n"
        "jmpl *%ecx\n" /* line 100 */
        ".Lf20b14c_0020b197:\n"
        "leal 0x4e(%ebx), %eax\n" /* line 88 */
        "movl %eax, 4(%edx)\n"
        ".Lf20b14c_0020b1a0:\n"
        "popl %ebx\n" /* line 103 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 116 */
static __attribute__((naked))
void process_data_simple_main(j_compress_ptr cinfo, JSAMPARRAY input_buf, JDIMENSION *in_row_ctr, JDIMENSION in_rows_avail)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 116 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %edi\n" /* cinfo */
        "movl 0x144(%edi), %esi\n" /* line 117 | cinfo, main */
        "movl 8(%esi), %eax\n" /* line 119 | main */
        "cmpl 0xe4(%edi), %eax\n" /* cinfo */
        "jae .Lf20b1a3_0020b266\n"
        "leal 0x18(%esi), %eax\n" /* main */
        "movl %eax, -0xc(%ebp)\n"
        "jmp .Lf20b1a3_0020b214\n"
        ".Lf20b1a3_0020b1cb:\n"
        "cmpl $8, 0xc(%esi)\n" /* line 131 | main */
        "jne .Lf20b1a3_0020b266\n"
        "movl 0x14c(%edi), %eax\n" /* line 135 | cinfo */
        "movl -0xc(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *4(%eax)\n"
        "testb %al, %al\n"
        "je .Lf20b1a3_0020b256\n"
        "cmpb $0, 0x10(%esi)\n" /* line 151 | main */
        "je .Lf20b1a3_0020b1fc\n"
        "movl 0x10(%ebp), %edx\n" /* line 152 | in_row_ctr */
        "addl $1, (%edx)\n"
        "movb $0, 0x10(%esi)\n" /* line 153 | main */
        ".Lf20b1a3_0020b1fc:\n"
        "movl $0, 0xc(%esi)\n" /* line 155 | main */
        "movl 8(%esi), %eax\n" /* line 156 | main */
        "addl $1, %eax\n"
        "movl %eax, 8(%esi)\n" /* main */
        "cmpl 0xe4(%edi), %eax\n" /* line 119 | cinfo */
        "jae .Lf20b1a3_0020b266\n"
        ".Lf20b1a3_0020b214:\n"
        "cmpl $7, 0xc(%esi)\n" /* line 121 | main */
        "ja .Lf20b1a3_0020b1cb\n"
        "movl 0x148(%edi), %edx\n" /* line 122 | cinfo */
        "movl $8, 0x18(%esp)\n"
        "leal 0xc(%esi), %eax\n" /* main */
        "movl %eax, 0x14(%esp)\n"
        "movl -0xc(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* in_rows_avail */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* in_row_ctr */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* input_buf */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *4(%edx)\n"
        "jmp .Lf20b1a3_0020b1cb\n"
        ".Lf20b1a3_0020b256:\n"
        "cmpb $0, 0x10(%esi)\n" /* line 142 | main */
        "jne .Lf20b1a3_0020b266\n"
        "movl 0x10(%ebp), %eax\n" /* line 143 | in_row_ctr */
        "subl $1, (%eax)\n"
        "movb $1, 0x10(%esi)\n" /* line 144 | main */
        ".Lf20b1a3_0020b266:\n"
        "addl $0x30, %esp\n" /* line 158 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 246 */
__attribute__((naked))
void jinit_c_main_controller(j_compress_ptr cinfo, int need_full_buffer)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 246 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movzbl 0xc(%ebp), %edi\n" /* need_full_buffer */
        "movl 4(%esi), %eax\n" /* line 251 | cinfo */
        "movl $0x40, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "movl %eax, %edx\n"
        "movl %eax, 0x144(%esi)\n" /* line 254 | cinfo */
        "leal -0x12f(%ebx), %eax\n" /* line 255 */
        "movl %eax, (%edx)\n"
        "cmpb $0, 0xb4(%esi)\n" /* line 258 | cinfo */
        "jne .Lf20b26d_0020b2c3\n"
        "movl %edi, %eax\n" /* line 264 | compptr */
        "testb %al, %al\n"
        "jne .Lf20b26d_0020b2cb\n"
        "movl 0x48(%esi), %edi\n" /* line 285 | cinfo, compptr */
        "movl 0x40(%esi), %eax\n" /* cinfo */
        "testl %eax, %eax\n"
        "jg .Lf20b26d_0020b2e4\n"
        ".Lf20b26d_0020b2c3:\n"
        "addl $0x2c, %esp\n" /* line 293 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20b26d_0020b2cb:\n"
        "movl (%esi), %eax\n" /* line 278 | cinfo */
        "movl $4, 0x14(%eax)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl %esi, 8(%ebp)\n" /* cinfo */
        "movl (%eax), %ecx\n"
        "addl $0x2c, %esp\n" /* line 293 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmpl *%ecx\n" /* line 278 */
        ".Lf20b26d_0020b2e4:\n"
        "movl %edx, -0x1c(%ebp)\n" /* line 285 */
        "movl $0, -0x20(%ebp)\n" /* ci */
        ".Lf20b26d_0020b2ee:\n"
        "movl 4(%esi), %edx\n" /* line 287 | cinfo */
        "movl 0xc(%edi), %eax\n" /* compptr */
        "shll $3, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x1c(%edi), %eax\n" /* compptr */
        "shll $3, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *8(%edx)\n"
        "movl -0x1c(%ebp), %edx\n"
        "movl %eax, 0x18(%edx)\n"
        "addl $1, -0x20(%ebp)\n" /* line 286 | ci */
        "addl $0x54, %edi\n" /* compptr */
        "addl $4, %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl -0x20(%ebp), %eax\n" /* line 285 | ci */
        "cmpl %eax, 0x40(%esi)\n" /* cinfo */
        "jg .Lf20b26d_0020b2ee\n"
        "addl $0x2c, %esp\n" /* line 293 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

