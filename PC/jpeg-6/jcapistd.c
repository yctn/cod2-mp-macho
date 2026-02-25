/* ASM dump from: jcapistd.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jcapistd.c */

#include "common_types.h"
#include "imports.h"

void jpeg_start_compress(j_compress_ptr cinfo, int write_all_tables);
JDIMENSION jpeg_write_scanlines(j_compress_ptr cinfo, JSAMPARRAY scanlines, JDIMENSION num_lines);

/* line 39 */
__attribute__((naked))
void jpeg_start_compress(j_compress_ptr cinfo, int write_all_tables)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 39 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movzbl 0xc(%ebp), %edi\n" /* write_all_tables */
        "cmpl $0x64, 0x14(%esi)\n" /* line 40 | cinfo */
        "je .Lf1f8d54_001f8d81\n"
        "movl (%esi), %eax\n" /* line 41 | cinfo */
        "movl $0x14, 0x14(%eax)\n"
        "movl (%esi), %edx\n" /* cinfo */
        "movl 0x14(%esi), %eax\n" /* cinfo */
        "movl %eax, 0x18(%edx)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        ".Lf1f8d54_001f8d81:\n"
        "movl %edi, %eax\n" /* line 43 | write_all_tables */
        "testb %al, %al\n"
        "jne .Lf1f8d54_001f8dcb\n"
        ".Lf1f8d54_001f8d87:\n"
        "movl (%esi), %eax\n" /* line 47 | cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *0x10(%eax)\n"
        "movl 0x20(%esi), %eax\n" /* line 48 | cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *8(%eax)\n"
        "movl %esi, (%esp)\n" /* line 50 | cinfo */
        "calll jinit_compress_master\n"
        "movl 0x140(%esi), %eax\n" /* line 52 | cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "movl $0, 0xd4(%esi)\n" /* line 56 | cinfo */
        "cmpb $1, 0xb4(%esi)\n" /* line 57 | cinfo */
        "sbbl %eax, %eax\n"
        "addl $0x66, %eax\n"
        "movl %eax, 0x14(%esi)\n" /* cinfo */
        "addl $0x10, %esp\n" /* line 58 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1f8d54_001f8dcb:\n"
        "movl $0, 4(%esp)\n" /* line 44 */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll jpeg_suppress_tables\n"
        "jmp .Lf1f8d54_001f8d87\n"
    );
}

/* line 79 */
__attribute__((naked))
JDIMENSION jpeg_write_scanlines(j_compress_ptr cinfo, JSAMPARRAY scanlines, JDIMENSION num_lines)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 79 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 0x10(%ebp), %edi\n" /* num_lines */
        "cmpl $0x65, 0x14(%esi)\n" /* line 82 | cinfo */
        "je .Lf1f8ddd_001f8e09\n"
        "movl (%esi), %eax\n" /* line 83 | cinfo */
        "movl $0x14, 0x14(%eax)\n"
        "movl (%esi), %edx\n" /* cinfo */
        "movl 0x14(%esi), %eax\n" /* cinfo */
        "movl %eax, 0x18(%edx)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        ".Lf1f8ddd_001f8e09:\n"
        "movl 0xd4(%esi), %eax\n" /* line 84 | cinfo */
        "cmpl 0x28(%esi), %eax\n" /* cinfo */
        "jae .Lf1f8ddd_001f8e84\n"
        ".Lf1f8ddd_001f8e14:\n"
        "movl 8(%esi), %edx\n" /* line 88 | cinfo */
        "testl %edx, %edx\n"
        "je .Lf1f8ddd_001f8e35\n"
        "movl 0xd4(%esi), %eax\n" /* line 89 | cinfo */
        "movl %eax, 4(%edx)\n"
        "movl 8(%esi), %edx\n" /* line 90 | cinfo */
        "movl 0x28(%esi), %eax\n" /* cinfo */
        "movl %eax, 8(%edx)\n"
        "movl 8(%esi), %eax\n" /* line 91 | cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        ".Lf1f8ddd_001f8e35:\n"
        "movl 0x140(%esi), %eax\n" /* line 99 | cinfo */
        "cmpb $0, 0xc(%eax)\n"
        "jne .Lf1f8ddd_001f8ea2\n"
        ".Lf1f8ddd_001f8e41:\n"
        "movl 0x28(%esi), %eax\n" /* line 103 | cinfo */
        "subl 0xd4(%esi), %eax\n" /* cinfo */
        "cmpl %edi, %eax\n" /* line 104 | num_lines */
        "cmovbl %eax, %edi\n" /* num_lines */
        "movl $0, -0xc(%ebp)\n" /* line 107 | row_ctr */
        "movl 0x144(%esi), %edx\n" /* line 108 | cinfo */
        "movl %edi, 0xc(%esp)\n" /* num_lines */
        "leal -0xc(%ebp), %eax\n" /* row_ctr */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* scanlines */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *4(%edx)\n"
        "movl -0xc(%ebp), %eax\n" /* line 109 | row_ctr */
        "addl %eax, 0xd4(%esi)\n" /* cinfo */
        "addl $0x20, %esp\n" /* line 111 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1f8ddd_001f8e84:\n"
        "movl (%esi), %eax\n" /* line 85 | cinfo */
        "movl $0x7b, 0x14(%eax)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *4(%eax)\n"
        "jmp .Lf1f8ddd_001f8e14\n"
        ".Lf1f8ddd_001f8ea2:\n"
        "movl %esi, (%esp)\n" /* line 100 | cinfo */
        "calll *4(%eax)\n"
        "jmp .Lf1f8ddd_001f8e41\n"
    );
}

