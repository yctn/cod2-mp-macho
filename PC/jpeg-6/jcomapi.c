/* ASM dump from: jcomapi.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jcomapi.c */

#include "common_types.h"
#include "imports.h"

void jpeg_abort(j_common_ptr cinfo);
void jpeg_destroy(j_common_ptr cinfo);
JQUANT_TBL * jpeg_alloc_quant_table(j_common_ptr cinfo);
JHUFF_TBL * jpeg_alloc_huff_table(j_common_ptr cinfo);

/* line 30 */
__attribute__((naked))
void jpeg_abort(j_common_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 30 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 4(%esi), %eax\n" /* line 34 | cinfo */
        "testl %eax, %eax\n"
        "je .Lf1fd4e0_001fd50c\n"
        "movl $1, 4(%esp)\n" /* line 41 */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *0x24(%eax)\n"
        "cmpb $0, 0x10(%esi)\n" /* line 45 | cinfo */
        "jne .Lf1fd4e0_001fd512\n"
        "movl $0x64, 0x14(%esi)\n" /* line 52 | cinfo */
        ".Lf1fd4e0_001fd50c:\n"
        "addl $0x14, %esp\n" /* line 54 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1fd4e0_001fd512:\n"
        "movl $0xc8, 0x14(%esi)\n" /* line 46 | cinfo */
        "movl $0, 0x114(%esi)\n" /* line 50 | cinfo */
        "addl $0x14, %esp\n" /* line 54 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 70 */
__attribute__((naked))
void jpeg_destroy(j_common_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 70 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 4(%esi), %eax\n" /* line 73 | cinfo */
        "testl %eax, %eax\n"
        "je .Lf1fd529_001fd540\n"
        "movl %esi, (%esp)\n" /* line 74 | cinfo */
        "calll *0x28(%eax)\n"
        ".Lf1fd529_001fd540:\n"
        "movl $0, 4(%esi)\n" /* line 75 | cinfo */
        "movl $0, 0x14(%esi)\n" /* line 76 | cinfo */
        "addl $0x14, %esp\n" /* line 77 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 87 */
__attribute__((naked))
JQUANT_TBL * jpeg_alloc_quant_table(j_common_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 87 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 4(%eax), %edx\n" /* line 90 */
        "movl $0x82, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "movb $0, 0x80(%eax)\n" /* line 92 */
        "leave\n" /* line 94 */
        "retl\n"
    );
}

/* line 99 */
__attribute__((naked))
JHUFF_TBL * jpeg_alloc_huff_table(j_common_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 99 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 4(%eax), %edx\n" /* line 102 */
        "movl $0x112, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "movb $0, 0x111(%eax)\n" /* line 104 */
        "leave\n" /* line 106 */
        "retl\n"
    );
}

