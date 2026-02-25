/* ASM dump from: jdatasrc.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jdatasrc.c */

#include "common_types.h"
#include "imports.h"

static void init_source(j_decompress_ptr cinfo);
static void skip_input_data(j_decompress_ptr cinfo, long int num_bytes);
static void term_source(j_decompress_ptr cinfo);
void jpeg_memory_src(j_decompress_ptr cinfo, const unsigned char *pubData, int iBytes);

/* line 43 */
static __attribute__((naked))
void init_source(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 43 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 50 | cinfo */
        "movl 0x20(%eax), %eax\n"
        "movb $1, 0x1c(%eax)\n"
        "popl %ebp\n" /* line 51 */
        "retl\n"
    );
}

/* line 130 */
static __attribute__((naked))
void skip_input_data(j_decompress_ptr cinfo, long int num_bytes)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 130 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %edx\n" /* num_bytes */
        "movl 8(%ebp), %eax\n" /* line 131 | cinfo, src */
        "movl 0x20(%eax), %eax\n" /* src */
        "testl %edx, %edx\n" /* line 137 */
        "jle .Lf1f7f43_001f7f58\n"
        "addl %edx, (%eax)\n" /* line 147 */
        "subl %edx, 4(%eax)\n" /* line 148 */
        ".Lf1f7f43_001f7f58:\n"
        "popl %ebp\n" /* line 150 */
        "retl\n"
    );
}

/* line 172 */
static __attribute__((naked))
void term_source(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 172 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 174 */
        "retl\n"
    );
}

/* line 227 */
__attribute__((naked))
void jpeg_memory_src(j_decompress_ptr cinfo, const unsigned char *pubData, int iBytes)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 227 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 0x20(%esi), %eax\n" /* line 237 | cinfo */
        "testl %eax, %eax\n"
        "je .Lf1f7f5f_001f7fb6\n"
        "movl 0x20(%esi), %edx\n" /* cinfo */
        ".Lf1f7f5f_001f7f79:\n"
        "leal -0x38(%ebx), %eax\n" /* line 245 */
        "movl %eax, 8(%edx)\n"
        "movl $0, 0xc(%edx)\n" /* line 246 */
        "leal -0x29(%ebx), %eax\n" /* line 247 */
        "movl %eax, 0x10(%edx)\n"
        "movl 0x1767a54(%ebx), %eax\n" /* line 248 */
        "movl %eax, 0x14(%edx)\n"
        "leal -0x12(%ebx), %eax\n" /* line 249 */
        "movl %eax, 0x18(%edx)\n"
        "movl 0x10(%ebp), %eax\n" /* line 250 | iBytes */
        "movl %eax, 4(%edx)\n"
        "movl 0xc(%ebp), %eax\n" /* line 251 | pubData */
        "movl %eax, (%edx)\n"
        "addl $0x10, %esp\n" /* line 252 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1f7f5f_001f7fb6:\n"
        "movl 4(%esi), %eax\n" /* line 238 | cinfo */
        "movl $0x20, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "movl %eax, 0x20(%esi)\n" /* cinfo */
        "movl %eax, %edx\n"
        "jmp .Lf1f7f5f_001f7f79\n"
    );
}

