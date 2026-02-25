/* ASM dump from: jcapimin.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jcapimin.c */

#include "common_types.h"
#include "imports.h"

void jpeg_CreateCompress(j_compress_ptr cinfo, int version, size_t structsize);
void jpeg_destroy_compress(j_compress_ptr cinfo);
void jpeg_suppress_tables(j_compress_ptr cinfo, int suppress);
void jpeg_finish_compress(j_compress_ptr cinfo, j_compress_ptr cinfo_1, int marker, const JOCTET *dataptr, unsigned int datalen);

/* line 31 */
__attribute__((naked))
void jpeg_CreateCompress(j_compress_ptr cinfo, int version, size_t structsize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 31 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0xc(%ebp), %edx\n" /* version */
        "movl 0x10(%ebp), %esi\n" /* structsize */
        "movl 8(%ebp), %eax\n" /* line 35 | cinfo */
        "movl $0, 4(%eax)\n"
        "cmpl $0x3e, %edx\n" /* line 36 */
        "je .Lf1f7764_001f77a3\n"
        "movl 8(%ebp), %ecx\n" /* line 37 | cinfo */
        "movl (%ecx), %eax\n"
        "movl $0xc, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl $0x3e, 0x18(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %edx, 0x1c(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf1f7764_001f77a3:\n"
        "cmpl $0x16c, %esi\n" /* line 38 | structsize */
        "je .Lf1f7764_001f77cc\n"
        "movl 8(%ebp), %edx\n" /* line 39 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x15, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl $0x16c, 0x18(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %esi, 0x1c(%eax)\n" /* structsize */
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        /* { scope 1 */
        ".Lf1f7764_001f77cc:\n"
        "movl 8(%ebp), %ecx\n" /* line 49 | cinfo */
        "movl (%ecx), %esi\n" /* err */
        "movl 0xc(%ecx), %edi\n" /* line 50 | client_data */
        "movl 0x18(%ecx), %eax\n" /* line 53 */
        "movl 0x1c(%ecx), %edx\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl $0x16c, 8(%esp)\n" /* line 55 */
        "movl $0, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll memset\n"
        "movl 8(%ebp), %ecx\n" /* line 57 | cinfo */
        "movl %esi, (%ecx)\n" /* err */
        "movl %edi, 0xc(%ecx)\n" /* line 58 | client_data */
        "movl -0x20(%ebp), %eax\n" /* line 59 */
        "movl -0x1c(%ebp), %edx\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %eax, 0x18(%ecx)\n"
        "movl %edx, 0x1c(%ecx)\n"
        /* } scope */
        "movb $0, 0x10(%ecx)\n" /* line 61 */
        "movl %ecx, (%esp)\n" /* line 64 */
        "calll jinit_memory_mgr\n"
        "movl 8(%ebp), %eax\n" /* line 67 | cinfo */
        "movl $0, 8(%eax)\n"
        "movl $0, 0x20(%eax)\n" /* line 68 */
        "movl $0, 0x48(%eax)\n" /* line 70 */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl $4, %edx\n"
        ".Lf1f7764_001f783b:\n"
        "movl $0, 0x4c(%eax)\n" /* line 73 */
        "addl $4, %eax\n"
        "subl $1, %edx\n" /* line 72 */
        "jne .Lf1f7764_001f783b\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl $4, %edx\n"
        ".Lf1f7764_001f7852:\n"
        "movl $0, 0x5c(%eax)\n" /* line 76 */
        "movl $0, 0x6c(%eax)\n" /* line 77 */
        "addl $4, %eax\n"
        "subl $1, %edx\n" /* line 75 */
        "jne .Lf1f7764_001f7852\n"
        "movl 8(%ebp), %edx\n" /* line 80 | cinfo */
        "movl $0, 0x164(%edx)\n"
        "movl $0, 0x34(%edx)\n" /* line 82 */
        "movl $0x3ff00000, 0x38(%edx)\n"
        "movl $0x64, 0x14(%edx)\n" /* line 85 */
        "addl $0x2c, %esp\n" /* line 86 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 95 */
__attribute__((naked))
void jpeg_destroy_compress(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 95 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 97 */
        "jmp jpeg_destroy\n" /* line 96 */
    );
}

/* line 126 */
__attribute__((naked))
void jpeg_suppress_tables(j_compress_ptr cinfo, int suppress)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 126 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $4, %esp\n"
        "movzbl 0xc(%ebp), %esi\n" /* suppress */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl $4, %ecx\n"
        ".Lf1f789c_001f78b0:\n"
        "movl 0x4c(%edx), %eax\n" /* line 132 */
        "movl %eax, -0xc(%ebp)\n" /* qtbl */
        "testl %eax, %eax\n"
        "je .Lf1f789c_001f78c4\n"
        "movl %eax, %edi\n" /* htbl */
        "movl %esi, %eax\n" /* line 133 | suppress */
        "movb %al, 0x80(%edi)\n" /* htbl */
        ".Lf1f789c_001f78c4:\n"
        "addl $4, %edx\n"
        "subl $1, %ecx\n" /* line 131 */
        "jne .Lf1f789c_001f78b0\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "xorl %ecx, %ecx\n"
        ".Lf1f789c_001f78d1:\n"
        "movl 0x5c(%edx), %edi\n" /* line 137 | htbl */
        "testl %edi, %edi\n" /* htbl */
        "je .Lf1f789c_001f78e0\n"
        "movl %esi, %eax\n" /* line 138 | suppress */
        "movb %al, 0x111(%edi)\n" /* htbl */
        ".Lf1f789c_001f78e0:\n"
        "movl 0x6c(%edx), %edi\n" /* line 139 | htbl */
        "testl %edi, %edi\n" /* htbl */
        "je .Lf1f789c_001f78ef\n"
        "movl %esi, %eax\n" /* line 140 | suppress */
        "movb %al, 0x111(%edi)\n" /* htbl */
        ".Lf1f789c_001f78ef:\n"
        "addl $1, %ecx\n" /* line 136 */
        "addl $4, %edx\n"
        "cmpl $4, %ecx\n"
        "jne .Lf1f789c_001f78d1\n"
        "addl $4, %esp\n" /* line 142 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 154 */
__attribute__((naked))
void jpeg_finish_compress(j_compress_ptr cinfo, j_compress_ptr cinfo_1, int marker, const JOCTET *dataptr, unsigned int datalen)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 154 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 0x14(%esi), %edx\n" /* line 157 | cinfo */
        "leal -0x65(%edx), %eax\n"
        "cmpl $1, %eax\n"
        "jbe 0x1f79f6\n"
        "cmpl $0x67, %edx\n" /* line 163 */
        "je .Lf1f7901_001f7938\n"
        "movl (%esi), %eax\n" /* line 164 | cinfo */
        "movl $0x14, 0x14(%eax)\n"
        "movl (%esi), %edx\n" /* cinfo */
        "movl 0x14(%esi), %eax\n" /* cinfo */
        "movl %eax, 0x18(%edx)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        ".Lf1f7901_001f7938:\n"
        "movl 0x140(%esi), %eax\n" /* line 166 | cinfo */
        "cmpb $0, 0xd(%eax)\n"
        "jne 0x1f79d3\n"
        "movl %esi, (%esp)\n" /* line 167 | cinfo */
        "calll *(%eax)\n"
        "movl 0xe4(%esi), %eax\n" /* line 168 | cinfo */
        "testl %eax, %eax\n"
        "je 0x1f79b7\n"
        "xorl %edi, %edi\n" /* iMCU_row */
        "jmp .Lf1f7901_001f7966\n"
        ".Lf1f7901_001f795b:\n"
        "addl $1, %edi\n" /* iMCU_row */
        "cmpl 0xe4(%esi), %edi\n" /* cinfo, iMCU_row */
        "jae 0x1f79b7\n"
        ".Lf1f7901_001f7966:\n"
        "movl 8(%esi), %eax\n" /* line 169 | cinfo */
        "testl %eax, %eax\n"
        "je .Lf1f7901_001f7984\n"
        "movl %edi, 4(%eax)\n" /* line 170 | iMCU_row */
        "movl 8(%esi), %eax\n" /* line 171 | cinfo */
        "movl 0xe4(%esi), %edx\n" /* cinfo */
        "movl %edx, 8(%eax)\n"
        "movl 8(%esi), %eax\n" /* line 172 | cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        ".Lf1f7901_001f7984:\n"
        "movl 0x14c(%esi), %eax\n" /* line 177 | cinfo */
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *4(%eax)\n"
        "testb %al, %al\n"
        "jne .Lf1f7901_001f795b\n"
        "movl (%esi), %eax\n" /* line 178 | cinfo */
    );
}

