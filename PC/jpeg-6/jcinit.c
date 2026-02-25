/* ASM dump from: jcinit.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jcinit.c */

#include "common_types.h"
#include "imports.h"

void jinit_compress_master(j_compress_ptr cinfo);

/* line 31 */
__attribute__((naked))
void jinit_compress_master(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 31 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl $0, 4(%esp)\n" /* line 33 */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll jinit_c_master_control\n"
        "cmpb $0, 0xb4(%esi)\n" /* line 36 | cinfo */
        "je .Lf2005f4_002006bd\n"
        ".Lf2005f4_0020061b:\n"
        "movl %esi, (%esp)\n" /* line 42 | cinfo */
        "calll jinit_forward_dct\n"
        "cmpb $0, 0xb5(%esi)\n" /* line 44 | cinfo */
        "jne .Lf2005f4_002006ab\n"
        "cmpb $0, 0xd8(%esi)\n" /* line 47 | cinfo */
        "je .Lf2005f4_0020068d\n"
        "movl %esi, (%esp)\n" /* line 49 | cinfo */
        "calll jinit_phuff_encoder\n"
        ".Lf2005f4_0020063d:\n"
        "cmpl $1, 0xac(%esi)\n" /* line 58 | cinfo */
        "jle .Lf2005f4_0020069e\n"
        ".Lf2005f4_00200646:\n"
        "movl $1, %eax\n"
        ".Lf2005f4_0020064b:\n"
        "movzbl %al, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll jinit_c_coef_controller\n"
        "movl $0, 4(%esp)\n" /* line 60 */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll jinit_c_main_controller\n"
        "movl %esi, (%esp)\n" /* line 62 | cinfo */
        "calll jinit_marker_writer\n"
        "movl 4(%esi), %eax\n" /* line 65 | cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *0x18(%eax)\n"
        "movl 0x150(%esi), %eax\n" /* line 71 | cinfo */
        "movl %esi, 8(%ebp)\n" /* cinfo */
        "movl (%eax), %ecx\n"
        "addl $0x14, %esp\n" /* line 72 */
        "popl %esi\n"
        "popl %ebp\n"
        "jmpl *%ecx\n" /* line 71 */
        ".Lf2005f4_0020068d:\n"
        "movl %esi, (%esp)\n" /* line 54 | cinfo */
        "calll jinit_huff_encoder\n"
        "cmpl $1, 0xac(%esi)\n" /* line 58 | cinfo */
        "jg .Lf2005f4_00200646\n"
        ".Lf2005f4_0020069e:\n"
        "cmpb $0, 0xb6(%esi)\n" /* cinfo */
        "jne .Lf2005f4_00200646\n"
        "xorl %eax, %eax\n"
        "jmp .Lf2005f4_0020064b\n"
        ".Lf2005f4_002006ab:\n"
        "movl (%esi), %eax\n" /* line 45 | cinfo */
        "movl $1, 0x14(%eax)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "jmp .Lf2005f4_0020063d\n"
        ".Lf2005f4_002006bd:\n"
        "movl %esi, (%esp)\n" /* line 37 | cinfo */
        "calll jinit_color_converter\n"
        "movl %esi, (%esp)\n" /* line 38 | cinfo */
        "calll jinit_downsampler\n"
        "movl $0, 4(%esp)\n" /* line 39 */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll jinit_c_prep_controller\n"
        "jmp .Lf2005f4_0020061b\n"
    );
}

