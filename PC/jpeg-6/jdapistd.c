/* ASM dump from: jdapistd.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jdapistd.c */

#include "common_types.h"
#include "imports.h"

static boolean output_pass_setup(void);
boolean jpeg_start_decompress(j_decompress_ptr cinfo);
JDIMENSION jpeg_read_scanlines(j_decompress_ptr cinfo, JSAMPARRAY scanlines, JDIMENSION max_lines, j_decompress_ptr cinfo_3, JSAMPIMAGE data, JDIMENSION max_lines_5);

/* line 96 */
static __attribute__((naked))
boolean output_pass_setup(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 96 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x10, %esp\n"
        "movl %eax, %esi\n" /* cinfo */
        "cmpl $0xcc, 0x14(%eax)\n" /* line 97 */
        "je .Lf1f7fd8_001f8007\n"
        "movl 0x188(%eax), %eax\n" /* line 99 */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "movl $0, 0x80(%esi)\n" /* line 100 | cinfo */
        "movl $0xcc, 0x14(%esi)\n" /* line 101 | cinfo */
        ".Lf1f7fd8_001f8007:\n"
        "movl 0x188(%esi), %eax\n" /* line 104 | cinfo */
        "cmpb $0, 8(%eax)\n"
        "je .Lf1f7fd8_001f8076\n"
        ".Lf1f7fd8_001f8013:\n"
        "movl 0x80(%esi), %edi\n" /* line 107 | cinfo */
        "cmpl 0x68(%esi), %edi\n" /* cinfo */
        "jae .Lf1f7fd8_001f8097\n"
        "movl 8(%esi), %eax\n" /* line 110 | cinfo */
        "testl %eax, %eax\n"
        "je .Lf1f7fd8_001f803f\n"
        "movl %edi, 4(%eax)\n" /* line 111 */
        "movl 8(%esi), %eax\n" /* line 112 | cinfo */
        "movl 0x68(%esi), %edx\n" /* cinfo */
        "movl %edx, 8(%eax)\n"
        "movl 8(%esi), %eax\n" /* line 113 | cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "movl 0x80(%esi), %edi\n" /* cinfo */
        ".Lf1f7fd8_001f803f:\n"
        "movl 0x18c(%esi), %edx\n" /* line 117 | cinfo */
        "movl $0, 0xc(%esp)\n"
        "leal 0x80(%esi), %eax\n" /* cinfo */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *4(%edx)\n"
        "cmpl 0x80(%esi), %edi\n" /* line 119 | cinfo */
        "jne .Lf1f7fd8_001f8013\n"
        "xorl %eax, %eax\n"
        "addl $0x10, %esp\n" /* line 135 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1f7fd8_001f8076:\n"
        "cmpb $0, 0x49(%esi)\n" /* line 133 | cinfo */
        "je .Lf1f7fd8_001f8090\n"
        "movl $0xce, %eax\n"
        ".Lf1f7fd8_001f8081:\n"
        "movl %eax, 0x14(%esi)\n" /* cinfo */
        "movl $1, %eax\n"
        "addl $0x10, %esp\n" /* line 135 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1f7fd8_001f8090:\n"
        "movl $0xcd, %eax\n" /* line 133 */
        "jmp .Lf1f7fd8_001f8081\n"
        ".Lf1f7fd8_001f8097:\n"
        "movl 0x188(%esi), %eax\n" /* line 123 | cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *4(%eax)\n"
        "movl 0x188(%esi), %eax\n" /* line 124 | cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "movl $0, 0x80(%esi)\n" /* line 125 | cinfo */
        "jmp .Lf1f7fd8_001f8007\n"
    );
}

/* line 39 */
__attribute__((naked))
boolean jpeg_start_decompress(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 39 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        "cmpl $0xca, 0x14(%esi)\n" /* line 40 | cinfo */
        "je .Lf1f80bd_001f8179\n"
        ".Lf1f80bd_001f80d4:\n"
        "movl 0x14(%esi), %eax\n" /* line 50 | cinfo */
        "cmpl $0xcb, %eax\n"
        "je .Lf1f80bd_001f810d\n"
        "cmpl $0xcc, %eax\n" /* line 79 */
        "je .Lf1f80bd_001f80fd\n"
        "movl (%esi), %eax\n" /* line 80 | cinfo */
        "movl $0x14, 0x14(%eax)\n"
        "movl (%esi), %edx\n" /* cinfo */
        "movl 0x14(%esi), %eax\n" /* cinfo */
        "movl %eax, 0x18(%edx)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        ".Lf1f80bd_001f80fd:\n"
        "movl %esi, %eax\n" /* line 82 | cinfo */
        "calll output_pass_setup\n"
        "movzbl %al, %eax\n"
        ".Lf1f80bd_001f8107:\n"
        "addl $0x14, %esp\n" /* line 83 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1f80bd_001f810d:\n"
        "movl 0x198(%esi), %eax\n" /* line 52 | cinfo */
        "cmpb $0, 0x10(%eax)\n"
        "je .Lf1f80bd_001f816b\n"
        "movl 8(%esi), %edx\n" /* cinfo */
        /* { scope 1 */
        ".Lf1f80bd_001f811c:\n"
        "testl %edx, %edx\n" /* line 57 */
        "je .Lf1f80bd_001f8125\n"
        "movl %esi, (%esp)\n" /* line 58 | cinfo */
        "calll *(%edx)\n"
        ".Lf1f80bd_001f8125:\n"
        "movl 0x198(%esi), %eax\n" /* line 60 | cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "testl %eax, %eax\n" /* line 61 */
        "je .Lf1f80bd_001f81a4\n"
        "cmpl $2, %eax\n" /* line 63 */
        "je .Lf1f80bd_001f816b\n"
        "movl 8(%esi), %edx\n" /* line 66 | cinfo */
        "testl %edx, %edx\n"
        "je .Lf1f80bd_001f8125\n"
        "cmpl $3, %eax\n"
        "je .Lf1f80bd_001f814a\n"
        "subl $1, %eax\n"
        "jne .Lf1f80bd_001f811c\n"
        ".Lf1f80bd_001f814a:\n"
        "movl 4(%edx), %eax\n" /* line 68 */
        "addl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl 8(%esi), %edx\n" /* cinfo */
        "movl 8(%edx), %ecx\n"
        "cmpl %ecx, %eax\n"
        "jl .Lf1f80bd_001f811c\n"
        "addl 0x124(%esi), %ecx\n" /* line 70 | cinfo */
        "movl %ecx, 8(%edx)\n"
        "movl 8(%esi), %edx\n" /* cinfo */
        "jmp .Lf1f80bd_001f811c\n"
        /* } scope */
        ".Lf1f80bd_001f816b:\n"
        "movl 0x84(%esi), %eax\n" /* line 78 | cinfo */
        "movl %eax, 0x8c(%esi)\n" /* cinfo */
        "jmp .Lf1f80bd_001f80fd\n"
        ".Lf1f80bd_001f8179:\n"
        "movl %esi, (%esp)\n" /* line 42 | cinfo */
        "calll jinit_master_decompress\n"
        "cmpb $0, 0x48(%esi)\n" /* line 43 | cinfo */
        "je .Lf1f80bd_001f8198\n"
        "movl $0xcf, 0x14(%esi)\n" /* line 45 | cinfo */
        "movl $1, %eax\n"
        "jmp .Lf1f80bd_001f8107\n"
        ".Lf1f80bd_001f8198:\n"
        "movl $0xcb, 0x14(%esi)\n" /* line 48 | cinfo */
        "jmp .Lf1f80bd_001f80d4\n"
        /* { scope 1 */
        ".Lf1f80bd_001f81a4:\n"
        "xorl %eax, %eax\n" /* line 61 */
        "jmp .Lf1f80bd_001f8107\n"
    );
}

/* line 154 */
__attribute__((naked))
JDIMENSION jpeg_read_scanlines(j_decompress_ptr cinfo, JSAMPARRAY scanlines, JDIMENSION max_lines, j_decompress_ptr cinfo_3, JSAMPIMAGE data, JDIMENSION max_lines_5)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 154 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        "cmpl $0xcd, 0x14(%esi)\n" /* line 157 | cinfo */
        "je .Lf1f81ab_001f81d6\n"
        "movl (%esi), %eax\n" /* line 158 | cinfo */
        "movl $0x14, 0x14(%eax)\n"
        "movl (%esi), %edx\n" /* cinfo */
        "movl 0x14(%esi), %eax\n" /* cinfo */
        "movl %eax, 0x18(%edx)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        ".Lf1f81ab_001f81d6:\n"
        "movl 0x80(%esi), %edx\n" /* line 159 | cinfo */
        "cmpl 0x68(%esi), %edx\n" /* cinfo */
        "jae .Lf1f81ab_001f8233\n"
        "movl 8(%esi), %eax\n" /* line 165 | cinfo */
        "testl %eax, %eax\n"
        "je .Lf1f81ab_001f81fc\n"
        "movl %edx, 4(%eax)\n" /* line 166 */
        "movl 8(%esi), %eax\n" /* line 167 | cinfo */
        "movl 0x68(%esi), %edx\n" /* cinfo */
        "movl %edx, 8(%eax)\n"
        "movl 8(%esi), %eax\n" /* line 168 | cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        ".Lf1f81ab_001f81fc:\n"
        "movl $0, -0xc(%ebp)\n" /* line 172 | row_ctr */
        "movl 0x18c(%esi), %edx\n" /* line 173 | cinfo */
        "movl 0x10(%ebp), %eax\n" /* max_lines */
        "movl %eax, 0xc(%esp)\n"
        "leal -0xc(%ebp), %eax\n" /* row_ctr */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* scanlines */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *4(%edx)\n"
        "movl -0xc(%ebp), %eax\n" /* line 174 | row_ctr */
        "addl %eax, 0x80(%esi)\n" /* cinfo */
        "addl $0x24, %esp\n" /* line 176 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1f81ab_001f8233:\n"
        "movl (%esi), %eax\n" /* line 160 | cinfo */
        "movl $0x7b, 0x14(%eax)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *4(%eax)\n"
        "xorl %eax, %eax\n"
        "addl $0x24, %esp\n" /* line 176 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %edi\n" /* cinfo */
        "movl 0xc(%ebp), %esi\n" /* scanlines, cinfo */
        "movzbl 0x18(%ebp), %eax\n"
        "movb %al, -9(%ebp)\n"
        "cmpl $0x64, 0x14(%edi)\n"
        "je .Lf1f81ab_001f8287\n"
        "movl (%edi), %eax\n"
        "movl $0x14, 0x14(%eax)\n"
        "movl (%edi), %edx\n"
        "movl 0x14(%edi), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf1f81ab_001f8287:\n"
        "cmpl $3, %esi\n" /* cinfo */
        "ja 0x1f8310\n"
    );
}

