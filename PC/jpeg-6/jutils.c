/* ASM dump from: jutils.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jutils.c */

#include "common_types.h"
#include "imports.h"

extern const int jpeg_natural_order[80]; /* 0x0 */

long int jdiv_round_up(long int a, long int b);
long int jround_up(long int a, long int b);
int jcopy_sample_rows(JSAMPARRAY input_array, int source_row, JSAMPARRAY output_array, int dest_row, int num_rows, JDIMENSION num_cols);
int jcopy_block_row(JBLOCKROW input_row, JBLOCKROW output_row, JDIMENSION num_blocks);
int jzero_far(int *target, size_t bytestozero);

/* line 75 */
__attribute__((naked))
long int jdiv_round_up(long int a, long int b)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 75 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %edx\n" /* b */
        "movl 8(%ebp), %eax\n" /* a */
        "addl %edx, %eax\n"
        "subl $1, %eax\n"
        "movl %edx, %ecx\n"
        "cltd\n"
        "idivl %ecx\n"
        "popl %ebp\n" /* line 77 */
        "retl\n"
    );
}

/* line 84 */
__attribute__((naked))
long int jround_up(long int a, long int b)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 84 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "movl 0xc(%ebp), %edx\n" /* b */
        "movl %edx, %eax\n" /* line 85 */
        "addl 8(%ebp), %eax\n" /* a */
        "leal -1(%eax), %esi\n"
        "movl %esi, %eax\n"
        "movl %edx, %edi\n"
        "cltd\n"
        "idivl %edi\n"
        "subl %edx, %esi\n"
        "movl %esi, %eax\n" /* line 87 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 119 */
__attribute__((naked))
int jcopy_sample_rows(JSAMPARRAY input_array, int source_row, JSAMPARRAY output_array, int dest_row, int num_rows, JDIMENSION num_cols)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 119 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x20, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* line 128 | source_row */
        "shll $2, %edi\n"
        "addl 8(%ebp), %edi\n" /* input_array */
        "movl 0x14(%ebp), %esi\n" /* line 129 | dest_row */
        "shll $2, %esi\n"
        "addl 0x10(%ebp), %esi\n" /* output_array */
        "movl 0x18(%ebp), %eax\n" /* line 131 | num_rows */
        "testl %eax, %eax\n"
        "jle .Lf201d9c_00201ded\n"
        "movl $0, -0xc(%ebp)\n"
        ".Lf201d9c_00201dc4:\n"
        "movl (%edi), %edx\n" /* line 132 */
        "addl $4, %edi\n"
        "movl (%esi), %eax\n" /* line 133 */
        "addl $4, %esi\n"
        "movl 0x1c(%ebp), %ecx\n" /* line 135 | num_cols */
        "movl %ecx, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "addl $1, -0xc(%ebp)\n"
        "movl -0xc(%ebp), %eax\n" /* line 131 */
        "cmpl %eax, 0x18(%ebp)\n" /* num_rows */
        "jne .Lf201d9c_00201dc4\n"
        ".Lf201d9c_00201ded:\n"
        "addl $0x20, %esp\n" /* line 141 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 148 */
__attribute__((naked))
int jcopy_block_row(JBLOCKROW input_row, JBLOCKROW output_row, JDIMENSION num_blocks)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 148 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x10(%ebp), %eax\n" /* num_blocks */
        "shll $7, %eax\n" /* line 150 */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* input_row */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* output_row */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "leave\n" /* line 161 */
        "retl\n"
    );
}

/* line 168 */
__attribute__((naked))
int jzero_far(int *target, size_t bytestozero)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 168 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* line 170 | bytestozero */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* target */
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "leave\n" /* line 179 */
        "retl\n"
    );
}

