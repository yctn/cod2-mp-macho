/* ASM dump from: jdapimin.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jdapimin.c */

#include "common_types.h"
#include "imports.h"

void jpeg_CreateDecompress(j_decompress_ptr cinfo, int version, size_t structsize);
void jpeg_destroy_decompress(j_decompress_ptr cinfo);
int jpeg_consume_input(j_decompress_ptr cinfo);
int jpeg_read_header(j_decompress_ptr cinfo, int require_image);
boolean jpeg_finish_decompress(j_decompress_ptr cinfo);

/* line 31 */
__attribute__((naked))
void jpeg_CreateDecompress(j_decompress_ptr cinfo, int version, size_t structsize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 31 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x20, %esp\n"
        "movl 0xc(%ebp), %edx\n" /* version */
        "movl 0x10(%ebp), %esi\n" /* structsize */
        "movl 8(%ebp), %eax\n" /* line 35 | cinfo */
        "movl $0, 4(%eax)\n"
        "cmpl $0x3e, %edx\n" /* line 36 */
        "je .Lf1f7a14_001f7a52\n"
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
        ".Lf1f7a14_001f7a52:\n"
        "cmpl $0x1b4, %esi\n" /* line 38 | structsize */
        "je .Lf1f7a14_001f7a7b\n"
        "movl 8(%ebp), %edx\n" /* line 39 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x15, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl $0x1b4, 0x18(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %esi, 0x1c(%eax)\n" /* structsize */
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        /* { scope 1 */
        ".Lf1f7a14_001f7a7b:\n"
        "movl 8(%ebp), %ecx\n" /* line 49 | cinfo */
        "movl (%ecx), %esi\n" /* err */
        "movl 0xc(%ecx), %edi\n" /* line 50 | client_data */
        "movl 0x18(%ecx), %eax\n" /* line 53 */
        "movl 0x1c(%ecx), %edx\n"
        "movl %eax, -0x10(%ebp)\n"
        "movl %edx, -0xc(%ebp)\n"
        "movl $0x1b4, 8(%esp)\n" /* line 55 */
        "movl $0, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll memset\n"
        "movl 8(%ebp), %ecx\n" /* line 57 | cinfo */
        "movl %esi, (%ecx)\n" /* err */
        "movl %edi, 0xc(%ecx)\n" /* line 58 | client_data */
        "movl -0x10(%ebp), %eax\n" /* line 59 */
        "movl -0xc(%ebp), %edx\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %eax, 0x18(%ecx)\n"
        "movl %edx, 0x1c(%ecx)\n"
        /* } scope */
        "movb $1, 0x10(%ecx)\n" /* line 61 */
        "movl %ecx, (%esp)\n" /* line 64 */
        "calll jinit_memory_mgr\n"
        "movl 8(%ebp), %eax\n" /* line 67 | cinfo */
        "movl $0, 8(%eax)\n"
        "movl $0, 0x20(%eax)\n" /* line 68 */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl $4, %edx\n"
        ".Lf1f7a14_001f7ae3:\n"
        "movl $0, 0x98(%eax)\n" /* line 71 */
        "addl $4, %eax\n"
        "subl $1, %edx\n" /* line 70 */
        "jne .Lf1f7a14_001f7ae3\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl $4, %edx\n"
        ".Lf1f7a14_001f7afd:\n"
        "movl $0, 0xa8(%eax)\n" /* line 74 */
        "movl $0, 0xb8(%eax)\n" /* line 75 */
        "addl $4, %eax\n"
        "subl $1, %edx\n" /* line 73 */
        "jne .Lf1f7a14_001f7afd\n"
        "movl 8(%ebp), %edx\n" /* line 81 | cinfo */
        "movl $0, 0x114(%edx)\n"
        "movl %edx, (%esp)\n" /* line 82 */
        "calll jinit_marker_reader\n"
        "movl 8(%ebp), %ecx\n" /* line 85 | cinfo */
        "movl %ecx, (%esp)\n"
        "calll jinit_input_controller\n"
        "movl 8(%ebp), %eax\n" /* line 88 | cinfo */
        "movl $0xc8, 0x14(%eax)\n"
        "addl $0x20, %esp\n" /* line 89 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 98 */
__attribute__((naked))
void jpeg_destroy_decompress(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 98 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 100 */
        "jmp jpeg_destroy\n" /* line 99 */
    );
}

/* line 294 */
__attribute__((naked))
int jpeg_consume_input(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1: cid1 */
        "pushl %ebp\n" /* line 294 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 0x14(%esi), %eax\n" /* line 298 | cinfo */
        "subl $0xc8, %eax\n"
        "cmpl $0xa, %eax\n"
        "ja .Lf1f7b54_001f7bac\n"
        "movl 0x1e(%ebx, %eax, 4), %eax\n"
        "addl %ebx, %eax\n"
        "jmpl *%eax\n"
        "nop\n"
        "nop\n"
        "nop\n"
        "insb %dx, %es:(%edi)\n" /* cid2 */
        "addb %al, (%eax)\n"
        "addb %cl, 0x27000000(%eax)\n"
        "addl %eax, (%eax)\n"
        "addb %dh, (%ecx, %eax)\n"
        "addb %al, (%eax)\n"
        "xorb $1, %al\n"
        "addb %al, (%eax)\n"
        "xorb $1, %al\n"
        "addb %al, (%eax)\n"
        "xorb $1, %al\n"
        "addb %al, (%eax)\n"
        "xorb $1, %al\n"
        "addb %al, (%eax)\n"
        "xorb $1, %al\n"
        "addb %al, (%eax)\n"
        "decl %edx\n"
        "addb %al, (%eax)\n"
        "addb %dh, (%ecx, %eax)\n"
        "addb %al, (%eax)\n"
        ".Lf1f7b54_001f7bac:\n"
        "movl (%esi), %eax\n" /* line 329 | cinfo */
        "movl $0x14, 0x14(%eax)\n"
        "movl (%esi), %edx\n" /* cinfo */
        "movl 0x14(%esi), %eax\n" /* cinfo */
        "movl %eax, 0x18(%edx)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "xorl %eax, %eax\n"
        ".Lf1f7b54_001f7bc6:\n"
        "addl $0x2c, %esp\n" /* line 332 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl 0x198(%esi), %eax\n" /* line 301 | cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *4(%eax)\n"
        "movl 0x20(%esi), %eax\n" /* line 303 | cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *8(%eax)\n"
        "movl $0xc9, 0x14(%esi)\n" /* line 304 | cinfo */
        "movl 0x198(%esi), %eax\n" /* line 307 | cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "cmpl $1, %eax\n" /* line 308 */
        "jne .Lf1f7b54_001f7bc6\n"
        "movl 0x2c(%esi), %eax\n" /* line 125 */
        "cmpl $3, %eax\n"
        "je .Lf1f7b54_001f7d02\n"
        "cmpl $4, %eax\n"
        "je .Lf1f7b54_001f7caa\n"
        "subl $1, %eax\n"
        "je .Lf1f7b54_001f7dc4\n"
        "movl $0, 0x30(%esi)\n" /* line 188 */
        "movl $0, 0x34(%esi)\n" /* line 189 */
        ".Lf1f7b54_001f7c26:\n"
        "movl $1, 0x38(%esi)\n" /* line 194 */
        "movl $1, 0x3c(%esi)\n" /* line 195 */
        "movl $0, 0x40(%esi)\n" /* line 196 */
        "movl $0x3ff00000, 0x44(%esi)\n"
        "movb $0, 0x48(%esi)\n" /* line 197 */
        "movb $0, 0x49(%esi)\n" /* line 198 */
        "movl $0, 0x4c(%esi)\n" /* line 199 */
        "movb $1, 0x50(%esi)\n" /* line 200 */
        "movb $1, 0x51(%esi)\n" /* line 201 */
        "movb $0, 0x52(%esi)\n" /* line 202 */
        "movl $2, 0x54(%esi)\n" /* line 204 */
        "movb $1, 0x58(%esi)\n" /* line 206 */
        "movl $0x100, 0x5c(%esi)\n" /* line 210 */
        "movl $0, 0x7c(%esi)\n" /* line 211 */
        "movb $0, 0x60(%esi)\n" /* line 213 */
        "movb $0, 0x61(%esi)\n" /* line 214 */
        "movb $0, 0x62(%esi)\n" /* line 215 */
        "movl $0xca, 0x14(%esi)\n" /* line 312 | cinfo */
        "movl $1, %eax\n"
        "addl $0x2c, %esp\n" /* line 332 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl 0x198(%esi), %eax\n" /* line 326 | cinfo */
        "movl %esi, 8(%ebp)\n" /* cinfo */
        "movl (%eax), %ecx\n"
        "addl $0x2c, %esp\n" /* line 332 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmpl *%ecx\n" /* line 326 */
        ".Lf1f7b54_001f7caa:\n"
        "cmpb $0, 0x110(%esi)\n" /* line 167 */
        "je .Lf1f7b54_001f7db8\n"
        "movzbl 0x111(%esi), %eax\n" /* line 168 */
        "testb %al, %al\n"
        "je .Lf1f7b54_001f7db8\n"
        "cmpb $2, %al\n"
        "je .Lf1f7b54_001f7cef\n"
        "movl (%esi), %eax\n" /* line 176 */
        "movl $0x72, 0x14(%eax)\n"
        "movl (%esi), %edx\n"
        "movzbl 0x111(%esi), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl (%esi), %eax\n"
        "movl $0xffffffff, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll *4(%eax)\n"
        ".Lf1f7b54_001f7cef:\n"
        "movl $5, 0x30(%esi)\n" /* line 177 */
        ".Lf1f7b54_001f7cf6:\n"
        "movl $4, 0x34(%esi)\n" /* line 184 */
        "jmp .Lf1f7b54_001f7c26\n"
        ".Lf1f7b54_001f7d02:\n"
        "cmpb $0, 0x108(%esi)\n" /* line 132 */
        "jne .Lf1f7b54_001f7daf\n"
        "cmpb $0, 0x110(%esi)\n" /* line 134 */
        "je .Lf1f7b54_001f7d67\n"
        "movzbl 0x111(%esi), %eax\n" /* line 135 */
        "testb %al, %al\n"
        "je .Lf1f7b54_001f7de2\n"
        "subb $1, %al\n"
        "je .Lf1f7b54_001f7daf\n"
        "movl (%esi), %eax\n" /* line 143 */
        "movl $0x72, 0x14(%eax)\n"
        "movl (%esi), %edx\n"
        "movzbl 0x111(%esi), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl (%esi), %eax\n"
        "movl $0xffffffff, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll *4(%eax)\n"
        "movl $3, 0x30(%esi)\n" /* line 144 */
        ".Lf1f7b54_001f7d5b:\n"
        "movl $2, 0x34(%esi)\n" /* line 163 */
        "jmp .Lf1f7b54_001f7c26\n"
        /* { scope 2 */
        ".Lf1f7b54_001f7d67:\n"
        "movl 0xcc(%esi), %eax\n" /* line 149 */
        "movl (%eax), %ecx\n" /* cid0 */
        "movl 0x54(%eax), %edx\n" /* line 150 */
        "movl %edx, -0x1c(%ebp)\n" /* cid1 */
        "movl 0xa8(%eax), %edi\n" /* line 151 | cid2 */
        "cmpl $1, %ecx\n" /* line 153 */
        "je .Lf1f7b54_001f7dee\n"
        "cmpl $0x52, %ecx\n" /* line 155 */
        "je .Lf1f7b54_001f7dd7\n"
        /* { scope 3 */
        ".Lf1f7b54_001f7d85:\n"
        "movl (%esi), %eax\n" /* line 158 */
        "leal 0x18(%eax), %edx\n" /* _mp */
        "movl %ecx, 0x18(%eax)\n"
        "movl -0x1c(%ebp), %eax\n" /* cid1 */
        "movl %eax, 4(%edx)\n"
        "movl %edi, 8(%edx)\n" /* cid2 */
        "movl (%esi), %eax\n"
        "movl $0x6f, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll *4(%eax)\n"
        /* } scope */
        ".Lf1f7b54_001f7daf:\n"
        "movl $3, 0x30(%esi)\n" /* line 159 */
        "jmp .Lf1f7b54_001f7d5b\n"
        /* } scope */
        ".Lf1f7b54_001f7db8:\n"
        "movl $4, 0x30(%esi)\n" /* line 182 */
        "jmp .Lf1f7b54_001f7cf6\n"
        ".Lf1f7b54_001f7dc4:\n"
        "movl $1, 0x30(%esi)\n" /* line 127 */
        "movl $1, 0x34(%esi)\n" /* line 128 */
        "jmp .Lf1f7b54_001f7c26\n"
        /* { scope 2 */
        ".Lf1f7b54_001f7dd7:\n"
        "cmpl $0x47, -0x1c(%ebp)\n" /* line 155 | cid1 */
        "jne .Lf1f7b54_001f7d85\n"
        "cmpl $0x42, %edi\n" /* cid2 */
        "jne .Lf1f7b54_001f7d85\n"
        ".Lf1f7b54_001f7de2:\n"
        "movl $2, 0x30(%esi)\n" /* line 156 */
        "jmp .Lf1f7b54_001f7d5b\n"
        ".Lf1f7b54_001f7dee:\n"
        "cmpl $2, %edx\n" /* line 153 */
        "jne .Lf1f7b54_001f7d85\n"
        "cmpl $3, %edi\n" /* cid2 */
        "jne .Lf1f7b54_001f7d85\n"
        "jmp .Lf1f7b54_001f7daf\n"
    );
}

/* line 248 */
__attribute__((naked))
int jpeg_read_header(j_decompress_ptr cinfo, int require_image)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 248 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %edi\n" /* cinfo */
        "movzbl 0xc(%ebp), %eax\n" /* require_image */
        "movb %al, -9(%ebp)\n" /* require_image */
        "movl 0x14(%edi), %eax\n" /* line 251 | cinfo */
        "subl $0xc8, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf1f7dfa_001f7e31\n"
        "movl (%edi), %eax\n" /* line 253 | cinfo */
        "movl $0x14, 0x14(%eax)\n"
        "movl (%edi), %edx\n" /* cinfo */
        "movl 0x14(%edi), %eax\n" /* cinfo */
        "movl %eax, 0x18(%edx)\n"
        "movl (%edi), %eax\n" /* cinfo */
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        ".Lf1f7dfa_001f7e31:\n"
        "movl %edi, (%esp)\n" /* line 255 | cinfo */
        "calll jpeg_consume_input\n"
        "movl %eax, %esi\n" /* retcode */
        "cmpl $1, %eax\n" /* line 257 */
        "je .Lf1f7dfa_001f7e45\n"
        "cmpl $2, %eax\n"
        "je .Lf1f7dfa_001f7e4e\n"
        ".Lf1f7dfa_001f7e45:\n"
        "movl %esi, %eax\n" /* line 277 | retcode */
        "addl $0x20, %esp\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1f7dfa_001f7e4e:\n"
        "cmpb $0, -9(%ebp)\n" /* line 262 | require_image */
        "jne .Lf1f7dfa_001f7e65\n"
        ".Lf1f7dfa_001f7e54:\n"
        "movl %edi, (%esp)\n" /* line 268 | cinfo */
        "calll jpeg_abort\n"
        "movl %esi, %eax\n" /* line 277 | retcode */
        "addl $0x20, %esp\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1f7dfa_001f7e65:\n"
        "movl (%edi), %eax\n" /* line 263 | cinfo */
        "movl $0x33, 0x14(%eax)\n"
        "movl (%edi), %eax\n" /* cinfo */
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "jmp .Lf1f7dfa_001f7e54\n"
    );
}

/* line 376 */
__attribute__((naked))
boolean jpeg_finish_decompress(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 376 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 0x14(%esi), %edx\n" /* line 377 | cinfo */
        "leal -0xcd(%edx), %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf1f7e79_001f7efb\n"
        ".Lf1f7e79_001f7e91:\n"
        "cmpl $0xcf, %edx\n" /* line 384 */
        "je .Lf1f7e79_001f7ef2\n"
        "cmpl $0xd2, %edx\n" /* line 387 */
        "je .Lf1f7e79_001f7eb9\n"
        "movl (%esi), %eax\n" /* line 389 | cinfo */
        "movl $0x14, 0x14(%eax)\n"
        "movl (%esi), %edx\n" /* cinfo */
        "movl 0x14(%esi), %eax\n" /* cinfo */
        "movl %eax, 0x18(%edx)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        ".Lf1f7e79_001f7eb9:\n"
        "movl 0x198(%esi), %eax\n" /* line 392 | cinfo */
        "cmpb $0, 0x11(%eax)\n"
        "jne .Lf1f7e79_001f7ed6\n"
        "movl %esi, (%esp)\n" /* line 393 | cinfo */
        "calll *(%eax)\n"
        "testl %eax, %eax\n"
        "jne .Lf1f7e79_001f7eb9\n"
        "xorl %eax, %eax\n"
        "addl $0x14, %esp\n" /* line 401 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1f7e79_001f7ed6:\n"
        "movl 0x20(%esi), %eax\n" /* line 397 | cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *0x18(%eax)\n"
        "movl %esi, (%esp)\n" /* line 399 | cinfo */
        "calll jpeg_abort\n"
        "movl $1, %eax\n"
        "addl $0x14, %esp\n" /* line 401 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1f7e79_001f7ef2:\n"
        "movl $0xd2, 0x14(%esi)\n" /* line 386 | cinfo */
        "jmp .Lf1f7e79_001f7eb9\n"
        ".Lf1f7e79_001f7efb:\n"
        "cmpb $0, 0x48(%esi)\n" /* line 377 | cinfo */
        "jne .Lf1f7e79_001f7e91\n"
        "movl 0x80(%esi), %eax\n" /* line 380 | cinfo */
        "cmpl 0x68(%esi), %eax\n" /* cinfo */
        "jb .Lf1f7e79_001f7f21\n"
        ".Lf1f7e79_001f7f0c:\n"
        "movl 0x188(%esi), %eax\n" /* line 382 | cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *4(%eax)\n"
        "movl $0xd2, 0x14(%esi)\n" /* line 383 | cinfo */
        "jmp .Lf1f7e79_001f7eb9\n"
        ".Lf1f7e79_001f7f21:\n"
        "movl (%esi), %eax\n" /* line 381 | cinfo */
        "movl $0x43, 0x14(%eax)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "jmp .Lf1f7e79_001f7f0c\n"
    );
}

