/* ASM dump from: jcmarker.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jcmarker.c */

#include "common_types.h"
#include "imports.h"

static void write_marker_byte(j_compress_ptr cinfo, int val);
void jinit_marker_writer(j_compress_ptr cinfo);
static void write_file_trailer(j_compress_ptr cinfo);
static void write_file_header(j_compress_ptr cinfo);
static void emit_sof(void);
static void emit_dht(j_compress_ptr cinfo);
static void write_scan_header(j_compress_ptr cinfo);
static int emit_dqt(j_compress_ptr cinfo);
static void write_tables_only(j_compress_ptr cinfo);
static void write_frame_header(j_compress_ptr cinfo);
static void write_marker_header(j_compress_ptr cinfo, int marker, unsigned int datalen);

/* line 452 */
static __attribute__((naked))
void write_marker_byte(j_compress_ptr cinfo, int val)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 452 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        /* { scope 1 */
        "movl 0x20(%esi), %ecx\n" /* line 111 | dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movl 0xc(%ebp), %edx\n" /* val */
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa37c_001fa3a8\n"
        /* } scope */
        ".Lf1fa37c_001fa3a2:\n"
        "addl $0x14, %esp\n" /* line 454 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1fa37c_001fa3a8:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa37c_001fa3a2\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, 8(%ebp)\n" /* cinfo */
        "movl (%eax), %ecx\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 454 */
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmpl *%ecx\n" /* line 116 */
    );
}

/* line 646 */
__attribute__((naked))
void jinit_marker_writer(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 646 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 4(%esi), %eax\n" /* line 650 | cinfo */
        "movl $0x20, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "movl %eax, 0x150(%esi)\n" /* line 653 | cinfo */
        "leal 0xee(%ebx), %edx\n" /* line 655 */
        "movl %edx, (%eax)\n"
        "leal 0x1beb(%ebx), %edx\n" /* line 656 */
        "movl %edx, 4(%eax)\n"
        "leal 0x11a7(%ebx), %edx\n" /* line 657 */
        "movl %edx, 8(%eax)\n"
        "leal 0x6d(%ebx), %edx\n" /* line 658 */
        "movl %edx, 0xc(%eax)\n"
        "leal 0x1a50(%ebx), %edx\n" /* line 659 */
        "movl %edx, 0x10(%eax)\n"
        "leal 0x1d1f(%ebx), %edx\n" /* line 660 */
        "movl %edx, 0x14(%eax)\n"
        "leal -0x5a(%ebx), %edx\n" /* line 661 */
        "movl %edx, 0x18(%eax)\n"
        "movl $0, 0x1c(%eax)\n" /* line 663 */
        "addl $0x10, %esp\n" /* line 664 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 603 */
static __attribute__((naked))
void write_file_trailer(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 603 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        /* { scope 1 */
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0xff, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa443_001fa4a8\n"
        /* } scope */
        /* { scope 1 */
        ".Lf1fa443_001fa467:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0xd9, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa443_001fa487\n"
        /* } scope */
        ".Lf1fa443_001fa481:\n"
        "addl $0x14, %esp\n" /* line 605 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1fa443_001fa487:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa443_001fa481\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, 8(%ebp)\n" /* cinfo */
        "movl (%eax), %ecx\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 605 */
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmpl *%ecx\n" /* line 116 */
        /* } scope */
        /* { scope 1 */
        ".Lf1fa443_001fa4a8:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa443_001fa467\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa443_001fa467\n"
    );
}

/* line 470 */
static __attribute__((naked))
void write_file_header(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 470 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 0x150(%esi), %edi\n" /* line 471 | cinfo, marker */
        /* { scope 2 */
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0xff, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001fab9f\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa4f3:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0xd8, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001fab7c\n"
        /* } scope */
        ".Lf1fa4c4_001fa511:\n"
        "movl $0, 0x1c(%edi)\n" /* line 476 | marker */
        "cmpb $0, 0xc8(%esi)\n" /* line 478 | cinfo */
        "je .Lf1fa4c4_001fa76b\n"
        /* { scope 2 */
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0xff, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001fabcf\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa543:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0xe0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001fabf2\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa561:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001fac15\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa57f:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0x10, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001fac38\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa59d:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0x4a, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001fac5b\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa5bb:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0x46, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001fac7e\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa5d9:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0x49, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001faca1\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa5f7:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0x46, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001facc4\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa615:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001face7\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa633:\n"
        "movl 0x20(%esi), %ecx\n" /* line 111 | dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movzbl 0xc9(%esi), %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001fad0a\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa657:\n"
        "movl 0x20(%esi), %ecx\n" /* line 111 | dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movzbl 0xca(%esi), %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001fad2d\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa67b:\n"
        "movl 0x20(%esi), %ecx\n" /* line 111 | dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movzbl 0xcb(%esi), %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001fad50\n"
        /* } scope */
        ".Lf1fa4c4_001fa69f:\n"
        "movzwl 0xcc(%esi), %edi\n" /* line 376 | value */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x20(%esi), %ecx\n" /* line 111 | dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movl %edi, %edx\n"
        "shrl $8, %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001fad73\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1fa4c4_001fa6c8:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movl %edi, %ecx\n"
        "movb %cl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001fad96\n"
        /* } scope */
        /* } scope */
        ".Lf1fa4c4_001fa6e7:\n"
        "movzwl 0xce(%esi), %edi\n" /* line 377 | value */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x20(%esi), %ecx\n" /* line 111 | dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movl %edi, %edx\n"
        "shrl $8, %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001fadb9\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1fa4c4_001fa710:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movl %edi, %ecx\n"
        "movb %cl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001faddc\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa72f:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001fadff\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa74d:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001fae22\n"
        /* } scope */
        ".Lf1fa4c4_001fa76b:\n"
        "cmpb $0, 0xd0(%esi)\n" /* line 480 | cinfo */
        "je .Lf1fa4c4_001fa96f\n"
        /* { scope 2 */
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0xff, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001fab59\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa796:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0xee, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001fab36\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa7b4:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001fab13\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa7d2:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0xe, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001faaf0\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa7f0:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0x41, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001faacd\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa80e:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0x64, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001faaaa\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa82c:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0x6f, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001faa87\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa84a:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0x62, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001faa64\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa868:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0x65, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001faa41\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa886:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001faa1e\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa8a4:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0x64, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001fa9fb\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa8c2:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001fa9d8\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa8e0:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001fa9b5\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa8fe:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001fa992\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa918:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fa4c4_001fa976\n"
        /* } scope */
        ".Lf1fa4c4_001fa932:\n"
        "movl 0x44(%esi), %eax\n" /* line 415 */
        "cmpl $3, %eax\n"
        "je .Lf1fa4c4_001fabc2\n"
        "cmpl $5, %eax\n"
        "je .Lf1fa4c4_001fae5d\n"
        /* { scope 2 */
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0, (%eax)\n"
        ".Lf1fa4c4_001fa94f:\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "jne .Lf1fa4c4_001fa96f\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "je .Lf1fa4c4_001fae45\n"
        /* } scope */
        ".Lf1fa4c4_001fa96f:\n"
        "addl $0x10, %esp\n" /* line 482 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2 */
        ".Lf1fa4c4_001fa976:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa932\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa932\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa992:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa918\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa918\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa9b5:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa8fe\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa8fe\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa9d8:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa8e0\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa8e0\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fa9fb:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa8c2\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa8c2\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001faa1e:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa8a4\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa8a4\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001faa41:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa886\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa886\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001faa64:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa868\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa868\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001faa87:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa84a\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa84a\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001faaaa:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa82c\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa82c\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001faacd:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa80e\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa80e\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001faaf0:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa7f0\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa7f0\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fab13:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa7d2\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa7d2\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fab36:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa7b4\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa7b4\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fab59:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa796\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa796\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fab7c:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa511\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa511\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fab9f:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa4f3\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa4f3\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fabc2:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $1, (%eax)\n"
        "jmp .Lf1fa4c4_001fa94f\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fabcf:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa543\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa543\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fabf2:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa561\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa561\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fac15:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa57f\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa57f\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fac38:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa59d\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa59d\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fac5b:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa5bb\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa5bb\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fac7e:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa5d9\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa5d9\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001faca1:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa5f7\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa5f7\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001facc4:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa615\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa615\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001face7:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa633\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa633\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fad0a:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa657\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa657\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fad2d:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa67b\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa67b\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fad50:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa69f\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa69f\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1fa4c4_001fad73:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa6c8\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa6c8\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1fa4c4_001fad96:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa6e7\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa6e7\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1fa4c4_001fadb9:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa710\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa710\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1fa4c4_001faddc:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa72f\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa72f\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fadff:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa74d\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa74d\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fae22:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fa4c4_001fa76b\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fa4c4_001fa76b\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fae45:\n"
        "movl (%esi), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, 8(%ebp)\n" /* cinfo */
        "movl (%eax), %ecx\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 482 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 2 */
        "jmpl *%ecx\n" /* line 116 */
        /* } scope */
        /* { scope 2 */
        ".Lf1fa4c4_001fae5d:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $2, (%eax)\n"
        "jmp .Lf1fa4c4_001fa94f\n"
    );
}

/* line 279 */
static __attribute__((naked))
void emit_sof(void)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 279 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x30, %esp\n"
        "movl %eax, %esi\n" /* cinfo */
        "movl %edx, %edi\n" /* code */
        /* { scope 2 */
        "movl 0x20(%eax), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0xff, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fae6a_001fb292\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fae6a_001fae94:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movl %edi, %ecx\n"
        "movb %cl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fae6a_001fb26f\n"
        /* } scope */
        ".Lf1fae6a_001faeb3:\n"
        "movl 0x40(%esi), %eax\n" /* line 285 | cinfo */
        "leal 8(%eax, %eax, 2), %edi\n" /* value */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x20(%esi), %ecx\n" /* line 111 | dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movl %edi, %edx\n"
        "movzbl %dh, %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fae6a_001fb24c\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1fae6a_001faedc:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movl %edi, %ecx\n"
        "movb %cl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fae6a_001fb229\n"
        /* } scope */
        /* } scope */
        ".Lf1fae6a_001faefb:\n"
        "cmpl $0xffff, 0x28(%esi)\n" /* line 288 | cinfo */
        "jg .Lf1fae6a_001fb11e\n"
        "cmpl $0xffff, 0x24(%esi)\n" /* cinfo */
        "jg .Lf1fae6a_001fb11e\n"
        /* { scope 2 */
        "movl 0x20(%esi), %ecx\n" /* line 111 | dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movl 0x3c(%esi), %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fae6a_001fb157\n"
        /* } scope */
        ".Lf1fae6a_001faf35:\n"
        "movl 0x28(%esi), %edi\n" /* line 293 | cinfo, value */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x20(%esi), %ecx\n" /* line 111 | dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movl %edi, %edx\n"
        "movzbl %dh, %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fae6a_001fb206\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1fae6a_001faf5a:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movl %edi, %ecx\n"
        "movb %cl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fae6a_001fb1e3\n"
        /* } scope */
        /* } scope */
        ".Lf1fae6a_001faf79:\n"
        "movl 0x24(%esi), %edi\n" /* line 294 | cinfo, value */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x20(%esi), %ecx\n" /* line 111 | dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movl %edi, %edx\n"
        "movzbl %dh, %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fae6a_001fb1c0\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1fae6a_001faf9e:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movl %edi, %ecx\n"
        "movb %cl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fae6a_001fb19d\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf1fae6a_001fafbd:\n"
        "movl 0x20(%esi), %ecx\n" /* line 111 | dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movl 0x40(%esi), %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fae6a_001fb17a\n"
        /* } scope */
        ".Lf1fae6a_001fafdd:\n"
        "movl 0x48(%esi), %edi\n" /* line 298 | cinfo, value */
        "movl 0x40(%esi), %eax\n" /* cinfo */
        "testl %eax, %eax\n"
        "jle .Lf1fae6a_001fb117\n"
        "movl $0, -0xc(%ebp)\n" /* ci */
        "jmp .Lf1fae6a_001fb04d\n"
        /* { scope 2 */
        ".Lf1fae6a_001faff4:\n"
        "movl 0x20(%esi), %ecx\n" /* line 111 | dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movl 8(%edi), %edx\n"
        "shll $4, %edx\n"
        "addl 0xc(%edi), %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fae6a_001fb0a8\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fae6a_001fb01a:\n"
        "movl 0x20(%esi), %ecx\n" /* line 111 | dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movl 0x10(%edi), %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fae6a_001fb0e6\n"
        /* } scope */
        ".Lf1fae6a_001fb03a:\n"
        "addl $1, -0xc(%ebp)\n" /* line 299 | ci */
        "addl $0x54, %edi\n" /* value */
        "movl -0xc(%ebp), %eax\n" /* line 298 | ci */
        "cmpl %eax, 0x40(%esi)\n" /* cinfo */
        "jle .Lf1fae6a_001fb117\n"
        /* { scope 2 */
        ".Lf1fae6a_001fb04d:\n"
        "movl 0x20(%esi), %ecx\n" /* line 111 | dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movl (%edi), %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "jne .Lf1fae6a_001faff4\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fae6a_001faff4\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        /* } scope */
        /* { scope 2 */
        "movl 0x20(%esi), %ecx\n" /* line 111 | dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movl 8(%edi), %edx\n"
        "shll $4, %edx\n"
        "addl 0xc(%edi), %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "jne .Lf1fae6a_001fb01a\n"
        ".Lf1fae6a_001fb0a8:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fae6a_001fb01a\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        /* } scope */
        /* { scope 2 */
        "movl 0x20(%esi), %ecx\n" /* line 111 | dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movl 0x10(%edi), %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "jne .Lf1fae6a_001fb03a\n"
        ".Lf1fae6a_001fb0e6:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fae6a_001fb03a\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        /* } scope */
        "addl $1, -0xc(%ebp)\n" /* line 299 | ci */
        "addl $0x54, %edi\n" /* value */
        "movl -0xc(%ebp), %eax\n" /* line 298 | ci */
        "cmpl %eax, 0x40(%esi)\n" /* cinfo */
        "jg .Lf1fae6a_001fb04d\n"
        ".Lf1fae6a_001fb117:\n"
        "addl $0x30, %esp\n" /* line 304 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1fae6a_001fb11e:\n"
        "movl (%esi), %eax\n" /* line 290 | cinfo */
        "movl $0x29, 0x14(%eax)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl $0xffff, 0x18(%eax)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        /* { scope 2 */
        "movl 0x20(%esi), %ecx\n" /* line 111 | dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movl 0x3c(%esi), %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "jne .Lf1fae6a_001faf35\n"
        ".Lf1fae6a_001fb157:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fae6a_001faf35\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fae6a_001faf35\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fae6a_001fb17a:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fae6a_001fafdd\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fae6a_001fafdd\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1fae6a_001fb19d:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fae6a_001fafbd\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fae6a_001fafbd\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1fae6a_001fb1c0:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fae6a_001faf9e\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fae6a_001faf9e\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1fae6a_001fb1e3:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fae6a_001faf79\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fae6a_001faf79\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1fae6a_001fb206:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fae6a_001faf5a\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fae6a_001faf5a\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1fae6a_001fb229:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fae6a_001faefb\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fae6a_001faefb\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1fae6a_001fb24c:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fae6a_001faedc\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fae6a_001faedc\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf1fae6a_001fb26f:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fae6a_001faeb3\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fae6a_001faeb3\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fae6a_001fb292:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fae6a_001fae94\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fae6a_001fae94\n"
    );
}

/* line 186 */
static __attribute__((naked))
void emit_dht(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 186 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x30, %esp\n"
        "movl %eax, -0x14(%ebp)\n"
        "movl %edx, %edi\n" /* index */
        "testb %cl, %cl\n" /* line 190 | is_ac */
        "je .Lf1fb2b5_001fb48d\n"
        "movl 0x6c(%eax, %edx, 4), %eax\n" /* line 191 */
        "movl %eax, -0x10(%ebp)\n" /* htbl */
        "addl $0x10, %edi\n" /* line 192 | index */
        ".Lf1fb2b5_001fb2d4:\n"
        "movl -0x10(%ebp), %ecx\n" /* line 197 | htbl, is_ac */
        "testl %ecx, %ecx\n" /* is_ac */
        "je .Lf1fb2b5_001fb560\n"
        ".Lf1fb2b5_001fb2df:\n"
        "movl -0x10(%ebp), %eax\n" /* line 200 | htbl */
        "cmpb $0, 0x111(%eax)\n"
        "jne .Lf1fb2b5_001fb486\n"
        /* { scope 2 */
        "movl -0x14(%ebp), %ecx\n" /* line 111 | dest */
        "movl 0x20(%ecx), %edx\n" /* dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0xff, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fb2b5_001fb4bf\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fb2b5_001fb310:\n"
        "movl -0x14(%ebp), %ecx\n" /* line 111 | dest */
        "movl 0x20(%ecx), %edx\n" /* dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0xc4, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fb2b5_001fb499\n"
        ".Lf1fb2b5_001fb331:\n"
        "movl -0x10(%ebp), %edx\n" /* line 116 | htbl */
        "movl $0, -0xc(%ebp)\n" /* length */
        "movl $0x10, %ecx\n"
        /* } scope */
        ".Lf1fb2b5_001fb340:\n"
        "movzbl 1(%edx), %eax\n" /* line 205 */
        "addl %eax, -0xc(%ebp)\n" /* length */
        "addl $1, %edx\n"
        "subl $1, %ecx\n" /* line 204 | is_ac */
        "jne .Lf1fb2b5_001fb340\n"
        "movl -0xc(%ebp), %esi\n" /* line 207 | length, value */
        "addl $0x13, %esi\n" /* value */
        /* { scope 2 */
        /* { scope 3 */
        "movl -0x14(%ebp), %eax\n" /* line 111 */
        "movl 0x20(%eax), %ecx\n" /* dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movl %esi, %edx\n"
        "movzbl %dh, %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fb2b5_001fb4e5\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1fb2b5_001fb37a:\n"
        "movl -0x14(%ebp), %ecx\n" /* line 111 | dest */
        "movl 0x20(%ecx), %edx\n" /* dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movl %esi, %ecx\n"
        "movb %cl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fb2b5_001fb537\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf1fb2b5_001fb39c:\n"
        "movl -0x14(%ebp), %ecx\n" /* line 111 | dest */
        "movl 0x20(%ecx), %edx\n" /* dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movl %edi, %ecx\n"
        "movb %cl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fb2b5_001fb50e\n"
        ".Lf1fb2b5_001fb3be:\n"
        "movl -0x10(%ebp), %esi\n" /* line 116 | htbl */
        "movl $0x10, %edi\n"
        "jmp .Lf1fb2b5_001fb3d0\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fb2b5_001fb3c8:\n"
        "addl $1, %esi\n"
        /* } scope */
        "subl $1, %edi\n" /* line 210 | index */
        "je .Lf1fb2b5_001fb418\n"
        /* { scope 2 */
        ".Lf1fb2b5_001fb3d0:\n"
        "movl -0x14(%ebp), %eax\n" /* line 111 */
        "movl 0x20(%eax), %ecx\n" /* dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movzbl 1(%esi), %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "jne .Lf1fb2b5_001fb3c8\n"
        "movl -0x14(%ebp), %edx\n" /* line 115 */
        "movl %edx, (%esp)\n"
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fb2b5_001fb3c8\n"
        "movl -0x14(%ebp), %ecx\n" /* line 116 */
        "movl (%ecx), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "addl $1, %esi\n"
        /* } scope */
        "subl $1, %edi\n" /* line 210 | index */
        "jne .Lf1fb2b5_001fb3d0\n"
        ".Lf1fb2b5_001fb418:\n"
        "movl -0xc(%ebp), %edx\n" /* line 213 | length */
        "testl %edx, %edx\n"
        "jle .Lf1fb2b5_001fb47c\n"
        "movl -0x10(%ebp), %edi\n" /* htbl, index */
        "xorl %esi, %esi\n" /* value */
        "jmp .Lf1fb2b5_001fb431\n"
        ".Lf1fb2b5_001fb426:\n"
        "addl $1, %esi\n" /* value */
        "addl $1, %edi\n" /* index */
        "cmpl -0xc(%ebp), %esi\n" /* length, value */
        "je .Lf1fb2b5_001fb47c\n"
        /* { scope 2 */
        ".Lf1fb2b5_001fb431:\n"
        "movl -0x14(%ebp), %eax\n" /* line 111 */
        "movl 0x20(%eax), %ecx\n" /* dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movzbl 0x11(%edi), %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "jne .Lf1fb2b5_001fb426\n"
        "movl -0x14(%ebp), %edx\n" /* line 115 */
        "movl %edx, (%esp)\n"
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fb2b5_001fb426\n"
        "movl -0x14(%ebp), %ecx\n" /* line 116 */
        "movl (%ecx), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        /* } scope */
        "addl $1, %esi\n" /* line 213 | value */
        "addl $1, %edi\n" /* index */
        "cmpl -0xc(%ebp), %esi\n" /* length, value */
        "jne .Lf1fb2b5_001fb431\n"
        ".Lf1fb2b5_001fb47c:\n"
        "movl -0x10(%ebp), %eax\n" /* line 216 | htbl */
        "movb $1, 0x111(%eax)\n"
        ".Lf1fb2b5_001fb486:\n"
        "addl $0x30, %esp\n" /* line 218 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1fb2b5_001fb48d:\n"
        "movl 0x5c(%eax, %edi, 4), %edx\n" /* line 194 */
        "movl %edx, -0x10(%ebp)\n" /* htbl */
        "jmp .Lf1fb2b5_001fb2d4\n"
        /* { scope 2 */
        ".Lf1fb2b5_001fb499:\n"
        "movl %ecx, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fb2b5_001fb331\n"
        "movl -0x14(%ebp), %edx\n" /* line 116 */
        "movl (%edx), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fb2b5_001fb331\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fb2b5_001fb4bf:\n"
        "movl %ecx, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fb2b5_001fb310\n"
        "movl -0x14(%ebp), %edx\n" /* line 116 */
        "movl (%edx), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fb2b5_001fb310\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1fb2b5_001fb4e5:\n"
        "movl -0x14(%ebp), %eax\n" /* line 115 */
        "movl %eax, (%esp)\n"
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fb2b5_001fb37a\n"
        "movl -0x14(%ebp), %edx\n" /* line 116 */
        "movl (%edx), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fb2b5_001fb37a\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf1fb2b5_001fb50e:\n"
        "movl -0x14(%ebp), %eax\n" /* line 115 */
        "movl %eax, (%esp)\n"
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fb2b5_001fb3be\n"
        "movl -0x14(%ebp), %edx\n" /* line 116 */
        "movl (%edx), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fb2b5_001fb3be\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1fb2b5_001fb537:\n"
        "movl -0x14(%ebp), %eax\n" /* line 115 */
        "movl %eax, (%esp)\n"
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fb2b5_001fb39c\n"
        "movl -0x14(%ebp), %edx\n" /* line 116 */
        "movl (%edx), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fb2b5_001fb39c\n"
        /* } scope */
        /* } scope */
        ".Lf1fb2b5_001fb560:\n"
        "movl -0x14(%ebp), %ecx\n" /* line 198 | is_ac */
        "movl (%ecx), %eax\n" /* is_ac */
        "movl $0x32, 0x14(%eax)\n"
        "movl (%ecx), %eax\n" /* is_ac */
        "movl %edi, 0x18(%eax)\n" /* index */
        "movl (%ecx), %eax\n" /* is_ac */
        "movl %ecx, (%esp)\n" /* is_ac */
        "calll *(%eax)\n"
        "jmp .Lf1fb2b5_001fb2df\n"
    );
}

/* line 552 */
static __attribute__((naked))
void write_scan_header(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1: i */
        "pushl %ebp\n" /* line 552 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x40, %esp\n"
        "movl 8(%ebp), %edi\n" /* cinfo */
        "movl 0x150(%edi), %eax\n" /* line 553 | cinfo */
        "movl %eax, -0x1c(%ebp)\n" /* marker */
        "cmpb $0, 0xb5(%edi)\n" /* line 557 | cinfo */
        "je .Lf1fb57d_001fb8d9\n"
        "movl %eax, %edx\n"
        ".Lf1fb57d_001fb5a0:\n"
        "movl 0xc0(%edi), %eax\n" /* line 588 | cinfo */
        "cmpl 0x1c(%edx), %eax\n"
        "je .Lf1fb57d_001fb67a\n"
        /* { scope 2 */
        "movl 0x20(%edi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0xff, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fb57d_001fb9cd\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fb57d_001fb5cd:\n"
        "movl 0x20(%edi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0xdd, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fb57d_001fb9aa\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fb57d_001fb5eb:\n"
        "movl 0x20(%edi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fb57d_001fb987\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fb57d_001fb609:\n"
        "movl 0x20(%edi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $4, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fb57d_001fb964\n"
        /* } scope */
        ".Lf1fb57d_001fb627:\n"
        "movl 0xc0(%edi), %esi\n" /* line 272 | value */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x20(%edi), %ecx\n" /* line 111 | dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movl %esi, %edx\n"
        "movzbl %dh, %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fb57d_001fba13\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1fb57d_001fb64f:\n"
        "movl 0x20(%edi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movl %esi, %ecx\n"
        "movb %cl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fb57d_001fb9f0\n"
        /* } scope */
        /* } scope */
        ".Lf1fb57d_001fb66e:\n"
        "movl 0xc0(%edi), %eax\n" /* line 590 | cinfo */
        "movl -0x1c(%ebp), %edx\n" /* marker */
        "movl %eax, 0x1c(%edx)\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1fb57d_001fb67a:\n"
        "movl 0x20(%edi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0xff, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fb57d_001fbb3f\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1fb57d_001fb698:\n"
        "movl 0x20(%edi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0xda, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fb57d_001fbb1c\n"
        /* } scope */
        ".Lf1fb57d_001fb6b6:\n"
        "movl 0xe8(%edi), %eax\n" /* line 316 */
        "leal 6(%eax, %eax), %esi\n" /* value */
        /* { scope 3 */
        /* { scope 4 */
        "movl 0x20(%edi), %ecx\n" /* line 111 | dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movl %esi, %edx\n"
        "movzbl %dh, %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fb57d_001fbaf9\n"
        /* } scope */
        /* { scope 4 */
        ".Lf1fb57d_001fb6e2:\n"
        "movl 0x20(%edi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movl %esi, %ecx\n"
        "movb %cl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fb57d_001fbad6\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        ".Lf1fb57d_001fb701:\n"
        "movl 0x20(%edi), %ecx\n" /* line 111 | dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movl 0xe8(%edi), %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fb57d_001fba6d\n"
        /* } scope */
        ".Lf1fb57d_001fb724:\n"
        "movl 0xe8(%edi), %esi\n" /* line 320 | value */
        "testl %esi, %esi\n" /* value */
        "jle .Lf1fb57d_001fb834\n"
        "movl %edi, -0x10(%ebp)\n"
        "movl $0, -0x14(%ebp)\n" /* i */
        "movl %edi, %eax\n"
        "jmp .Lf1fb57d_001fb77f\n"
        ".Lf1fb57d_001fb740:\n"
        "movl %eax, %edx\n" /* line 325 */
        "shll $4, %edx\n"
        /* { scope 3 */
        ".Lf1fb57d_001fb745:\n"
        "movl 0x20(%edi), %ecx\n" /* line 111 | dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "leal (%esi, %edx), %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fb57d_001fb7ff\n"
        /* } scope */
        ".Lf1fb57d_001fb765:\n"
        "addl $1, -0x14(%ebp)\n" /* line 320 | i */
        "addl $4, -0x10(%ebp)\n"
        "movl -0x14(%ebp), %edx\n" /* i */
        "cmpl %edx, 0xe8(%edi)\n"
        "jle .Lf1fb57d_001fb834\n"
        ".Lf1fb57d_001fb77c:\n"
        "movl -0x10(%ebp), %eax\n"
        ".Lf1fb57d_001fb77f:\n"
        "movl 0xec(%eax), %esi\n" /* line 321 | value */
        /* { scope 3 */
        "movl 0x20(%edi), %ecx\n" /* line 111 | dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movl (%esi), %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fb57d_001fb8b6\n"
        /* } scope */
        ".Lf1fb57d_001fb7a4:\n"
        "movl 0x14(%esi), %eax\n" /* line 323 | value */
        "movl 0x18(%esi), %esi\n" /* line 324 | value */
        "cmpb $0, 0xd8(%edi)\n" /* line 325 */
        "je .Lf1fb57d_001fb740\n"
        "movl 0x130(%edi), %ecx\n" /* line 331 */
        "testl %ecx, %ecx\n"
        "jne .Lf1fb57d_001fb8af\n"
        "movl 0x138(%edi), %edx\n" /* line 333 */
        "testl %edx, %edx\n"
        "je .Lf1fb57d_001fb7d8\n"
        "cmpb $0, 0xb5(%edi)\n"
        "je .Lf1fb57d_001fb8ad\n"
        ".Lf1fb57d_001fb7d8:\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "xorl %esi, %esi\n" /* value */
        /* { scope 3 */
        "movl 0x20(%edi), %ecx\n" /* line 111 | dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "leal (%esi, %edx), %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "jne .Lf1fb57d_001fb765\n"
        ".Lf1fb57d_001fb7ff:\n"
        "movl %edi, (%esp)\n" /* line 115 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fb57d_001fb765\n"
        "movl (%edi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        /* } scope */
        "addl $1, -0x14(%ebp)\n" /* line 320 | i */
        "addl $4, -0x10(%ebp)\n"
        "movl -0x14(%ebp), %edx\n" /* i */
        "cmpl %edx, 0xe8(%edi)\n"
        "jg .Lf1fb57d_001fb77c\n"
        /* { scope 3 */
        ".Lf1fb57d_001fb834:\n"
        "movl 0x20(%edi), %ecx\n" /* line 111 | dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movl 0x130(%edi), %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fb57d_001fbab3\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1fb57d_001fb857:\n"
        "movl 0x20(%edi), %ecx\n" /* line 111 | dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movl 0x134(%edi), %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fb57d_001fba90\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1fb57d_001fb87a:\n"
        "movl 0x20(%edi), %ecx\n" /* line 111 | dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movl 0x138(%edi), %edx\n"
        "shll $4, %edx\n"
        "addl 0x13c(%edi), %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fb57d_001fba36\n"
        /* } scope */
        /* } scope */
        ".Lf1fb57d_001fb8a6:\n"
        "addl $0x40, %esp\n" /* line 594 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2 */
        ".Lf1fb57d_001fb8ad:\n"
        "xorl %esi, %esi\n" /* line 333 | value */
        ".Lf1fb57d_001fb8af:\n"
        "xorl %edx, %edx\n"
        "jmp .Lf1fb57d_001fb745\n"
        /* { scope 3 */
        ".Lf1fb57d_001fb8b6:\n"
        "movl %edi, (%esp)\n" /* line 115 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fb57d_001fb7a4\n"
        "movl (%edi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fb57d_001fb7a4\n"
        /* } scope */
        /* } scope */
        ".Lf1fb57d_001fb8d9:\n"
        "movl 0xe8(%edi), %esi\n" /* line 567 | cinfo, compptr */
        "testl %esi, %esi\n" /* compptr */
        "jle .Lf1fb57d_001fb95c\n"
        "movl %edi, -0xc(%ebp)\n" /* cinfo */
        "movl $0, -0x18(%ebp)\n" /* i */
        "movl %edi, %edx\n" /* cinfo */
        "jmp .Lf1fb57d_001fb91f\n"
        ".Lf1fb57d_001fb8f1:\n"
        "movl 0x130(%edi), %eax\n" /* line 571 | cinfo */
        "testl %eax, %eax\n"
        "jne .Lf1fb57d_001fb93a\n"
        "movl 0x138(%edi), %eax\n" /* line 572 | cinfo */
        "testl %eax, %eax\n"
        "je .Lf1fb57d_001fba5c\n"
        ".Lf1fb57d_001fb909:\n"
        "addl $1, -0x18(%ebp)\n" /* line 567 | i */
        "addl $4, -0xc(%ebp)\n"
        "movl -0x18(%ebp), %ecx\n" /* i */
        "cmpl %ecx, 0xe8(%edi)\n" /* cinfo */
        "jle .Lf1fb57d_001fb95c\n"
        ".Lf1fb57d_001fb91c:\n"
        "movl -0xc(%ebp), %edx\n"
        ".Lf1fb57d_001fb91f:\n"
        "movl 0xec(%edx), %esi\n" /* line 568 | compptr */
        "cmpb $0, 0xd8(%edi)\n" /* line 569 | cinfo */
        "jne .Lf1fb57d_001fb8f1\n"
        "movl 0x14(%esi), %edx\n" /* line 579 | compptr */
        "xorl %ecx, %ecx\n"
        "movl %edi, %eax\n" /* cinfo */
        "calll emit_dht\n"
        ".Lf1fb57d_001fb93a:\n"
        "movl 0x18(%esi), %edx\n" /* line 580 | compptr */
        "movl $1, %ecx\n"
        "movl %edi, %eax\n" /* cinfo */
        "calll emit_dht\n"
        "addl $1, -0x18(%ebp)\n" /* line 567 | i */
        "addl $4, -0xc(%ebp)\n"
        "movl -0x18(%ebp), %ecx\n" /* i */
        "cmpl %ecx, 0xe8(%edi)\n" /* cinfo */
        "jg .Lf1fb57d_001fb91c\n"
        ".Lf1fb57d_001fb95c:\n"
        "movl -0x1c(%ebp), %edx\n" /* marker */
        "jmp .Lf1fb57d_001fb5a0\n"
        /* { scope 2 */
        ".Lf1fb57d_001fb964:\n"
        "movl %edi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fb57d_001fb627\n"
        "movl (%edi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fb57d_001fb627\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fb57d_001fb987:\n"
        "movl %edi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fb57d_001fb609\n"
        "movl (%edi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fb57d_001fb609\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fb57d_001fb9aa:\n"
        "movl %edi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fb57d_001fb5eb\n"
        "movl (%edi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fb57d_001fb5eb\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fb57d_001fb9cd:\n"
        "movl %edi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fb57d_001fb5cd\n"
        "movl (%edi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fb57d_001fb5cd\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1fb57d_001fb9f0:\n"
        "movl %edi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fb57d_001fb66e\n"
        "movl (%edi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fb57d_001fb66e\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1fb57d_001fba13:\n"
        "movl %edi, (%esp)\n" /* line 115 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fb57d_001fb64f\n"
        "movl (%edi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fb57d_001fb64f\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1fb57d_001fba36:\n"
        "movl %edi, (%esp)\n" /* line 115 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fb57d_001fb8a6\n"
        "movl (%edi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edi), %eax\n"
        "movl %edi, 8(%ebp)\n" /* cinfo */
        "movl (%eax), %ecx\n"
        /* } scope */
        /* } scope */
        "addl $0x40, %esp\n" /* line 594 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 2 */
        /* { scope 3 */
        "jmpl *%ecx\n" /* line 116 */
        /* } scope */
        /* } scope */
        ".Lf1fb57d_001fba5c:\n"
        "movl 0x14(%esi), %edx\n" /* line 573 | compptr */
        "xorl %ecx, %ecx\n"
        "movl %edi, %eax\n" /* cinfo */
        "calll emit_dht\n"
        "jmp .Lf1fb57d_001fb909\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1fb57d_001fba6d:\n"
        "movl %edi, (%esp)\n" /* line 115 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fb57d_001fb724\n"
        "movl (%edi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fb57d_001fb724\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1fb57d_001fba90:\n"
        "movl %edi, (%esp)\n" /* line 115 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fb57d_001fb87a\n"
        "movl (%edi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fb57d_001fb87a\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1fb57d_001fbab3:\n"
        "movl %edi, (%esp)\n" /* line 115 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fb57d_001fb857\n"
        "movl (%edi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fb57d_001fb857\n"
        /* } scope */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf1fb57d_001fbad6:\n"
        "movl %edi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fb57d_001fb701\n"
        "movl (%edi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fb57d_001fb701\n"
        /* } scope */
        /* { scope 4 */
        ".Lf1fb57d_001fbaf9:\n"
        "movl %edi, (%esp)\n" /* line 115 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fb57d_001fb6e2\n"
        "movl (%edi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fb57d_001fb6e2\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        ".Lf1fb57d_001fbb1c:\n"
        "movl %edi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fb57d_001fb6b6\n"
        "movl (%edi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fb57d_001fb6b6\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1fb57d_001fbb3f:\n"
        "movl %edi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fb57d_001fb698\n"
        "movl (%edi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fb57d_001fb698\n"
    );
}

/* line 147 */
static __attribute__((naked))
int emit_dqt(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 147 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl %eax, -0x28(%ebp)\n"
        "movl %edx, %edi\n" /* index */
        "movl 0x4c(%eax, %edx, 4), %eax\n" /* line 148 */
        "movl %eax, -0x24(%ebp)\n" /* qtbl */
        "testl %eax, %eax\n" /* line 152 */
        "je .Lf1fbb62_001fbe06\n"
        "movl %eax, %edx\n"
        ".Lf1fbb62_001fbb86:\n"
        "movl $0, -0x20(%ebp)\n" /* line 153 | prec */
        "movl $0x40, %ecx\n"
        ".Lf1fbb62_001fbb92:\n"
        "cmpw $0x100, (%edx)\n" /* line 157 */
        "movl $1, %eax\n"
        "cmovbl -0x20(%ebp), %eax\n" /* prec */
        "movl %eax, -0x20(%ebp)\n" /* prec */
        "addl $2, %edx\n"
        "subl $1, %ecx\n" /* line 156 */
        "jne .Lf1fbb62_001fbb92\n"
        "movl -0x24(%ebp), %ecx\n" /* line 161 | qtbl */
        "cmpb $0, 0x80(%ecx)\n"
        "jne .Lf1fbb62_001fbd12\n"
        /* { scope 2 */
        "movl -0x28(%ebp), %eax\n" /* line 111 */
        "movl 0x20(%eax), %edx\n" /* dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0xff, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fbb62_001fbddd\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fbb62_001fbbdc:\n"
        "movl -0x28(%ebp), %ecx\n" /* line 111 | dest */
        "movl 0x20(%ecx), %edx\n" /* dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0xdb, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fbb62_001fbdb7\n"
        /* } scope */
        ".Lf1fbb62_001fbbfd:\n"
        "cmpl $1, -0x20(%ebp)\n" /* line 164 | prec */
        "sbbl %esi, %esi\n"
        "andl $0xffffffc0, %esi\n"
        "addl $0x83, %esi\n"
        /* { scope 2 */
        "movl -0x28(%ebp), %ecx\n" /* line 111 | dest */
        "movl 0x20(%ecx), %edx\n" /* dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fbb62_001fbd91\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fbb62_001fbc2d:\n"
        "movl -0x28(%ebp), %ecx\n" /* line 111 | dest */
        "movl 0x20(%ecx), %edx\n" /* dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movl %esi, %ecx\n"
        "movb %cl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fbb62_001fbd68\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fbb62_001fbc4f:\n"
        "movl -0x28(%ebp), %eax\n" /* line 111 */
        "movl 0x20(%eax), %ecx\n" /* dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movl -0x20(%ebp), %edx\n" /* prec */
        "shll $4, %edx\n"
        "leal (%edi, %edx), %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fbb62_001fbd3f\n"
        ".Lf1fbb62_001fbc78:\n"
        "movl 0x1763e58(%ebx), %edi\n" /* line 116 */
        "leal 0x100(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "jmp .Lf1fbb62_001fbc91\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1fbb62_001fbc89:\n"
        "addl $4, %edi\n"
        /* } scope */
        /* } scope */
        "cmpl %edi, -0x1c(%ebp)\n" /* line 168 | index */
        "je .Lf1fbb62_001fbd08\n"
        /* { scope 2 */
        ".Lf1fbb62_001fbc91:\n"
        "movl (%edi), %eax\n" /* line 170 | index */
        "movl -0x24(%ebp), %edx\n" /* qtbl */
        "movzwl (%edx, %eax, 2), %esi\n" /* qval */
        "movl -0x20(%ebp), %eax\n" /* line 171 | prec */
        "testl %eax, %eax\n"
        "je .Lf1fbb62_001fbcc2\n"
        /* { scope 3 */
        "movl -0x28(%ebp), %eax\n" /* line 111 */
        "movl 0x20(%eax), %ecx\n" /* dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movl %esi, %edx\n"
        "shrl $8, %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fbb62_001fbd1d\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1fbb62_001fbcc2:\n"
        "movl -0x28(%ebp), %eax\n" /* line 111 */
        "movl 0x20(%eax), %edx\n" /* dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movl %esi, %ecx\n"
        "movb %cl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "jne .Lf1fbb62_001fbc89\n"
        "movl -0x28(%ebp), %eax\n" /* line 115 */
        "movl %eax, (%esp)\n"
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fbb62_001fbc89\n"
        "movl -0x28(%ebp), %edx\n" /* line 116 */
        "movl (%edx), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "addl $4, %edi\n"
        /* } scope */
        /* } scope */
        "cmpl %edi, -0x1c(%ebp)\n" /* line 168 | index */
        "jne .Lf1fbb62_001fbc91\n"
        ".Lf1fbb62_001fbd08:\n"
        "movl -0x24(%ebp), %ecx\n" /* line 176 | qtbl */
        "movb $1, 0x80(%ecx)\n"
        ".Lf1fbb62_001fbd12:\n"
        "movl -0x20(%ebp), %eax\n" /* line 180 | prec */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1fbb62_001fbd1d:\n"
        "movl -0x28(%ebp), %edx\n" /* line 115 */
        "movl %edx, (%esp)\n"
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fbb62_001fbcc2\n"
        "movl -0x28(%ebp), %ecx\n" /* line 116 */
        "movl (%ecx), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fbb62_001fbcc2\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf1fbb62_001fbd3f:\n"
        "movl -0x28(%ebp), %edx\n" /* line 115 */
        "movl %edx, (%esp)\n"
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fbb62_001fbc78\n"
        "movl -0x28(%ebp), %ecx\n" /* line 116 */
        "movl (%ecx), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fbb62_001fbc78\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fbb62_001fbd68:\n"
        "movl -0x28(%ebp), %eax\n" /* line 115 */
        "movl %eax, (%esp)\n"
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fbb62_001fbc4f\n"
        "movl -0x28(%ebp), %edx\n" /* line 116 */
        "movl (%edx), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fbb62_001fbc4f\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fbb62_001fbd91:\n"
        "movl %ecx, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fbb62_001fbc2d\n"
        "movl -0x28(%ebp), %edx\n" /* line 116 */
        "movl (%edx), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fbb62_001fbc2d\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fbb62_001fbdb7:\n"
        "movl %ecx, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fbb62_001fbbfd\n"
        "movl -0x28(%ebp), %edx\n" /* line 116 */
        "movl (%edx), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fbb62_001fbbfd\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fbb62_001fbddd:\n"
        "movl -0x28(%ebp), %ecx\n" /* line 115 */
        "movl %ecx, (%esp)\n"
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fbb62_001fbbdc\n"
        "movl -0x28(%ebp), %edx\n" /* line 116 */
        "movl (%edx), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fbb62_001fbbdc\n"
        /* } scope */
        ".Lf1fbb62_001fbe06:\n"
        "movl -0x28(%ebp), %edx\n" /* line 153 */
        "movl (%edx), %eax\n"
        "movl $0x34, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edi, 0x18(%eax)\n" /* index */
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl -0x24(%ebp), %edx\n" /* qtbl */
        "jmp .Lf1fbb62_001fbb86\n"
    );
}

/* line 617 */
static __attribute__((naked))
void write_tables_only(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 617 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, -0xc(%ebp)\n" /* cinfo */
        /* { scope 2 */
        "movl 0x20(%eax), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0xff, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fbe26_001fbf6f\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fbe26_001fbe52:\n"
        "movl -0xc(%ebp), %eax\n" /* line 111 | cinfo */
        "movl 0x20(%eax), %edx\n" /* dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0xd8, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fbe26_001fbf1e\n"
        ".Lf1fbe26_001fbe73:\n"
        "movl -0xc(%ebp), %esi\n" /* line 116 | cinfo */
        "xorl %edi, %edi\n"
        /* } scope */
        ".Lf1fbe26_001fbe78:\n"
        "movl 0x4c(%esi), %eax\n" /* line 623 */
        "testl %eax, %eax\n"
        "je .Lf1fbe26_001fbe89\n"
        "movl %edi, %edx\n" /* line 624 | i */
        "movl -0xc(%ebp), %eax\n" /* cinfo */
        "calll emit_dqt\n"
        ".Lf1fbe26_001fbe89:\n"
        "addl $1, %edi\n" /* line 622 | i */
        "addl $4, %esi\n"
        "cmpl $4, %edi\n" /* i */
        "jne .Lf1fbe26_001fbe78\n"
        "movl -0xc(%ebp), %eax\n" /* line 627 | cinfo */
        "cmpb $0, 0xb5(%eax)\n"
        "jne .Lf1fbe26_001fbedc\n"
        "movl %eax, %esi\n"
        "xorw %di, %di\n" /* i */
        ".Lf1fbe26_001fbea5:\n"
        "movl 0x5c(%esi), %eax\n" /* line 629 */
        "testl %eax, %eax\n"
        "je .Lf1fbe26_001fbeb8\n"
        "xorl %ecx, %ecx\n" /* line 630 */
        "movl %edi, %edx\n" /* i */
        "movl -0xc(%ebp), %eax\n" /* cinfo */
        "calll emit_dht\n"
        ".Lf1fbe26_001fbeb8:\n"
        "movl 0x6c(%esi), %eax\n" /* line 631 */
        "testl %eax, %eax\n"
        "je .Lf1fbe26_001fbece\n"
        "movl $1, %ecx\n" /* line 632 */
        "movl %edi, %edx\n" /* i */
        "movl -0xc(%ebp), %eax\n" /* cinfo */
        "calll emit_dht\n"
        ".Lf1fbe26_001fbece:\n"
        "addl $1, %edi\n" /* line 628 | i */
        "addl $4, %esi\n"
        "cmpl $4, %edi\n" /* i */
        "jne .Lf1fbe26_001fbea5\n"
        "movl -0xc(%ebp), %eax\n" /* cinfo */
        /* { scope 2 */
        ".Lf1fbe26_001fbedc:\n"
        "movl 0x20(%eax), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0xff, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fbe26_001fbf98\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fbe26_001fbefa:\n"
        "movl -0xc(%ebp), %eax\n" /* line 111 | cinfo */
        "movl 0x20(%eax), %edx\n" /* dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0xd9, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fbe26_001fbf47\n"
        /* } scope */
        ".Lf1fbe26_001fbf17:\n"
        "addl $0x20, %esp\n" /* line 637 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2 */
        ".Lf1fbe26_001fbf1e:\n"
        "movl -0xc(%ebp), %eax\n" /* line 115 | cinfo */
        "movl %eax, (%esp)\n"
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fbe26_001fbe73\n"
        "movl -0xc(%ebp), %edx\n" /* line 116 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fbe26_001fbe73\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fbe26_001fbf47:\n"
        "movl -0xc(%ebp), %eax\n" /* line 115 | cinfo */
        "movl %eax, (%esp)\n"
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fbe26_001fbf17\n"
        "movl -0xc(%ebp), %edx\n" /* line 116 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, 8(%ebp)\n" /* cinfo */
        "movl (%eax), %ecx\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 637 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 2 */
        "jmpl *%ecx\n" /* line 116 */
        /* } scope */
        /* { scope 2 */
        ".Lf1fbe26_001fbf6f:\n"
        "movl -0xc(%ebp), %eax\n" /* line 115 | cinfo */
        "movl %eax, (%esp)\n"
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fbe26_001fbe52\n"
        "movl -0xc(%ebp), %edx\n" /* line 116 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fbe26_001fbe52\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fbe26_001fbf98:\n"
        "movl -0xc(%ebp), %eax\n" /* line 115 | cinfo */
        "movl %eax, (%esp)\n"
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fbe26_001fbefa\n"
        "movl -0xc(%ebp), %edx\n" /* line 116 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fbe26_001fbefa\n"
    );
}

/* line 495 */
static __attribute__((naked))
void write_frame_header(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 495 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %edi\n" /* cinfo */
        "movl 0x48(%edi), %esi\n" /* line 504 | cinfo, compptr */
        "movl 0x40(%edi), %eax\n" /* cinfo */
        "testl %eax, %eax\n"
        "jg .Lf1fbfc1_001fc07c\n"
        "movl $0, -0xc(%ebp)\n" /* prec */
        ".Lf1fbfc1_001fbfe1:\n"
        "cmpb $0, 0xb5(%edi)\n" /* line 513 | cinfo */
        "jne .Lf1fbfc1_001fc027\n"
        "cmpb $0, 0xd8(%edi)\n" /* cinfo */
        "je .Lf1fbfc1_001fc039\n"
        ".Lf1fbfc1_001fbff3:\n"
        "xorl %esi, %esi\n" /* line 526 | compptr */
        ".Lf1fbfc1_001fbff5:\n"
        "cmpb $0, 0xb5(%edi)\n" /* line 531 | cinfo */
        "jne .Lf1fbfc1_001fc027\n"
        "cmpb $0, 0xd8(%edi)\n" /* line 534 | cinfo */
        "jne .Lf1fbfc1_001fc0bd\n"
        "movl %esi, %eax\n" /* line 536 | compptr */
        "testb %al, %al\n"
        "jne .Lf1fbfc1_001fc0ab\n"
        "movl $0xc1, %edx\n" /* line 539 */
        "movl %edi, %eax\n" /* line 535 | cinfo */
        "addl $0x20, %esp\n" /* line 541 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp emit_sof\n" /* line 535 */
        ".Lf1fbfc1_001fc027:\n"
        "movl $0xc9, %edx\n" /* line 532 */
        "movl %edi, %eax\n" /* line 535 | cinfo */
        "addl $0x20, %esp\n" /* line 541 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp emit_sof\n" /* line 535 */
        ".Lf1fbfc1_001fc039:\n"
        "cmpl $8, 0x3c(%edi)\n" /* line 513 | cinfo */
        "jne .Lf1fbfc1_001fbff3\n"
        "movl 0x48(%edi), %edx\n" /* line 518 | cinfo */
        "testl %eax, %eax\n"
        "jg .Lf1fbfc1_001fc0cf\n"
        "movl $1, %esi\n" /* compptr */
        ".Lf1fbfc1_001fc04f:\n"
        "movl -0xc(%ebp), %edx\n" /* line 523 | prec */
        "testl %edx, %edx\n"
        "je .Lf1fbfc1_001fbff5\n"
        "movl %esi, %eax\n" /* compptr */
        "testb %al, %al\n"
        "je .Lf1fbfc1_001fbff5\n"
        "movl (%edi), %eax\n" /* line 526 | cinfo */
        "movl $0x4b, 0x14(%eax)\n"
        "movl (%edi), %eax\n" /* cinfo */
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *4(%eax)\n"
        "xorl %esi, %esi\n" /* compptr */
        "jmp .Lf1fbfc1_001fbff5\n"
        ".Lf1fbfc1_001fc07c:\n"
        "movl $0, -0x10(%ebp)\n" /* line 504 | ci */
        "movl $0, -0xc(%ebp)\n" /* prec */
        ".Lf1fbfc1_001fc08a:\n"
        "movl 0x10(%esi), %edx\n" /* line 506 | compptr */
        "movl %edi, %eax\n" /* cinfo */
        "calll emit_dqt\n"
        "addl %eax, -0xc(%ebp)\n" /* prec */
        "addl $1, -0x10(%ebp)\n" /* line 505 | ci */
        "addl $0x54, %esi\n" /* compptr */
        "movl 0x40(%edi), %eax\n" /* line 504 | cinfo */
        "cmpl %eax, -0x10(%ebp)\n" /* ci */
        "jl .Lf1fbfc1_001fc08a\n"
        "jmp .Lf1fbfc1_001fbfe1\n"
        ".Lf1fbfc1_001fc0ab:\n"
        "movl $0xc0, %edx\n" /* line 537 */
        "movl %edi, %eax\n" /* line 535 | cinfo */
        "addl $0x20, %esp\n" /* line 541 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp emit_sof\n" /* line 535 */
        ".Lf1fbfc1_001fc0bd:\n"
        "movl $0xc2, %edx\n"
        "movl %edi, %eax\n" /* cinfo */
        "addl $0x20, %esp\n" /* line 541 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp emit_sof\n" /* line 535 */
        ".Lf1fbfc1_001fc0cf:\n"
        "xorl %ecx, %ecx\n" /* line 518 */
        "movl $1, %esi\n" /* compptr */
        ".Lf1fbfc1_001fc0d6:\n"
        "cmpl $1, 0x14(%edx)\n" /* line 520 */
        "jle .Lf1fbfc1_001fc0ed\n"
        ".Lf1fbfc1_001fc0dc:\n"
        "xorl %esi, %esi\n" /* compptr */
        ".Lf1fbfc1_001fc0de:\n"
        "addl $1, %ecx\n" /* line 519 */
        "addl $0x54, %edx\n"
        "cmpl %ecx, %eax\n" /* line 518 */
        "jne .Lf1fbfc1_001fc0d6\n"
        "jmp .Lf1fbfc1_001fc04f\n"
        ".Lf1fbfc1_001fc0ed:\n"
        "cmpl $1, 0x18(%edx)\n" /* line 520 */
        "jg .Lf1fbfc1_001fc0dc\n"
        "jmp .Lf1fbfc1_001fc0de\n"
    );
}

/* line 440 */
static __attribute__((naked))
void write_marker_header(j_compress_ptr cinfo, int marker, unsigned int datalen)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 440 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 0xc(%ebp), %edi\n" /* marker */
        "movl 0x10(%ebp), %eax\n" /* datalen */
        "movl %eax, -0xc(%ebp)\n" /* datalen */
        "cmpl $0xfffd, %eax\n" /* line 441 */
        "ja .Lf1fc0f5_001fc21b\n"
        /* { scope 1 */
        ".Lf1fc0f5_001fc114:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movb $0xff, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fc0f5_001fc1f8\n"
        /* } scope */
        /* { scope 1 */
        ".Lf1fc0f5_001fc132:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movl %edi, %ecx\n"
        "movb %cl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fc0f5_001fc1d5\n"
        /* } scope */
        ".Lf1fc0f5_001fc151:\n"
        "movl -0xc(%ebp), %edi\n" /* line 446 | datalen, value */
        "addl $2, %edi\n" /* value */
        /* { scope 1 */
        /* { scope 2 */
        "movl 0x20(%esi), %ecx\n" /* line 111 | dest */
        "movl (%ecx), %eax\n" /* line 113 */
        "movl %edi, %edx\n"
        "movzbl %dh, %edx\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fc0f5_001fc1b9\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1fc0f5_001fc175:\n"
        "movl 0x20(%esi), %edx\n" /* line 111 | dest */
        "movl (%edx), %eax\n" /* line 113 */
        "movl %edi, %ecx\n"
        "movb %cl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 114 */
        "subl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf1fc0f5_001fc197\n"
        /* } scope */
        /* } scope */
        ".Lf1fc0f5_001fc190:\n"
        "addl $0x30, %esp\n" /* line 447 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1fc0f5_001fc197:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fc0f5_001fc190\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, 8(%ebp)\n" /* cinfo */
        "movl (%eax), %ecx\n"
        /* } scope */
        /* } scope */
        "addl $0x30, %esp\n" /* line 447 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        /* { scope 2 */
        "jmpl *%ecx\n" /* line 116 */
        /* } scope */
        /* { scope 2 */
        ".Lf1fc0f5_001fc1b9:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fc0f5_001fc175\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fc0f5_001fc175\n"
        /* } scope */
        /* } scope */
        /* { scope 1 */
        ".Lf1fc0f5_001fc1d5:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fc0f5_001fc151\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fc0f5_001fc151\n"
        /* } scope */
        /* { scope 1 */
        ".Lf1fc0f5_001fc1f8:\n"
        "movl %esi, (%esp)\n" /* line 115 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "jne .Lf1fc0f5_001fc132\n"
        "movl (%esi), %eax\n" /* line 116 */
        "movl $0x18, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fc0f5_001fc132\n"
        /* } scope */
        ".Lf1fc0f5_001fc21b:\n"
        "movl (%esi), %eax\n" /* line 442 | cinfo */
        "movl $0xb, 0x14(%eax)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "jmp .Lf1fc0f5_001fc114\n"
    );
}

