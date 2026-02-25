/* ASM dump from: jdmaster.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jdmaster.c */

#include "common_types.h"
#include "imports.h"

static void prepare_for_output_pass(j_decompress_ptr cinfo);
static void finish_output_pass(j_decompress_ptr cinfo, j_decompress_ptr cinfo_1);
void jpeg_calc_output_dimensions(j_decompress_ptr cinfo);
void jinit_master_decompress(j_decompress_ptr cinfo);

/* line 439 */
static __attribute__((naked))
void prepare_for_output_pass(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 439 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 0x188(%esi), %edi\n" /* line 440 | cinfo, master */
        "cmpb $0, 8(%edi)\n" /* line 442 | master */
        "jne .Lf1ffc9c_001ffda5\n"
        "cmpb $0, 0x52(%esi)\n" /* line 453 | cinfo */
        "jne .Lf1ffc9c_001ffd78\n"
        ".Lf1ffc9c_001ffcc1:\n"
        "movl 0x1a4(%esi), %eax\n" /* line 464 | cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "movl 0x190(%esi), %eax\n" /* line 465 | cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *8(%eax)\n"
        "cmpb $0, 0x49(%esi)\n" /* line 466 | cinfo */
        "je .Lf1ffc9c_001ffd25\n"
        ".Lf1ffc9c_001ffcde:\n"
        "movl 8(%esi), %edx\n" /* line 479 | cinfo */
        "testl %edx, %edx\n"
        "je .Lf1ffc9c_001ffd1e\n"
        "movl 0xc(%edi), %eax\n" /* line 480 | master */
        "movl %eax, 0xc(%edx)\n"
        "movl 8(%esi), %edx\n" /* line 481 | cinfo */
        "cmpb $1, 8(%edi)\n" /* master */
        "sbbl %eax, %eax\n"
        "addl $2, %eax\n"
        "addl 0xc(%edi), %eax\n" /* master */
        "movl %eax, 0x10(%edx)\n"
        "cmpb $0, 0x48(%esi)\n" /* line 486 | cinfo */
        "je .Lf1ffc9c_001ffd1e\n"
        "movl 0x198(%esi), %eax\n" /* cinfo */
        "cmpb $0, 0x11(%eax)\n"
        "jne .Lf1ffc9c_001ffd1e\n"
        "movl 8(%esi), %edx\n" /* line 487 | cinfo */
        "cmpb $1, 0x62(%esi)\n" /* cinfo */
        "sbbl %eax, %eax\n"
        "addl $2, %eax\n"
        "addl %eax, 0x10(%edx)\n"
        ".Lf1ffc9c_001ffd1e:\n"
        "addl $0x10, %esp\n" /* line 490 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1ffc9c_001ffd25:\n"
        "cmpb $0, 0x10(%edi)\n" /* line 467 | master */
        "je .Lf1ffc9c_001ffdff\n"
        ".Lf1ffc9c_001ffd2f:\n"
        "movl 0x1a8(%esi), %eax\n" /* line 469 | cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "cmpb $0, 0x52(%esi)\n" /* line 470 | cinfo */
        "jne .Lf1ffc9c_001ffde7\n"
        ".Lf1ffc9c_001ffd44:\n"
        "movl 0x194(%esi), %eax\n" /* line 472 | cinfo */
        "movl (%eax), %edx\n"
        "cmpb $1, 8(%edi)\n" /* master */
        "sbbl %eax, %eax\n"
        "notl %eax\n"
        "andl $3, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *%edx\n"
        "movl 0x18c(%esi), %eax\n" /* line 474 | cinfo */
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "jmp .Lf1ffc9c_001ffcde\n"
        ".Lf1ffc9c_001ffd78:\n"
        "movl 0x7c(%esi), %eax\n" /* line 453 | cinfo */
        "testl %eax, %eax\n"
        "jne .Lf1ffc9c_001ffcc1\n"
        "cmpb $0, 0x58(%esi)\n" /* line 455 | cinfo */
        "jne .Lf1ffc9c_001ffe0f\n"
        ".Lf1ffc9c_001ffd8d:\n"
        "cmpb $0, 0x60(%esi)\n" /* line 458 | cinfo */
        "je .Lf1ffc9c_001ffe2b\n"
        "movl 0x14(%edi), %eax\n" /* line 459 | master */
        "movl %eax, 0x1b0(%esi)\n" /* cinfo */
        "jmp .Lf1ffc9c_001ffcc1\n"
        ".Lf1ffc9c_001ffda5:\n"
        "movb $0, 8(%edi)\n" /* line 445 | master */
        "movl 0x1b0(%esi), %eax\n" /* line 446 | cinfo */
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "movl 0x194(%esi), %eax\n" /* line 447 | cinfo */
        "movl $2, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "movl 0x18c(%esi), %eax\n" /* line 448 | cinfo */
        "movl $2, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "jmp .Lf1ffc9c_001ffcde\n"
        ".Lf1ffc9c_001ffde7:\n"
        "movl 0x1b0(%esi), %edx\n" /* line 471 | cinfo */
        "movzbl 8(%edi), %eax\n" /* master */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%edx)\n"
        "jmp .Lf1ffc9c_001ffd44\n"
        ".Lf1ffc9c_001ffdff:\n"
        "movl 0x1ac(%esi), %eax\n" /* line 468 | cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "jmp .Lf1ffc9c_001ffd2f\n"
        ".Lf1ffc9c_001ffe0f:\n"
        "cmpb $0, 0x62(%esi)\n" /* line 455 | cinfo */
        "je .Lf1ffc9c_001ffd8d\n"
        "movl 0x18(%edi), %eax\n" /* line 456 | master */
        "movl %eax, 0x1b0(%esi)\n" /* cinfo */
        "movb $1, 8(%edi)\n" /* line 457 | master */
        "jmp .Lf1ffc9c_001ffcc1\n"
        ".Lf1ffc9c_001ffe2b:\n"
        "movl (%esi), %eax\n" /* line 461 | cinfo */
        "movl $0x2e, 0x14(%eax)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "jmp .Lf1ffc9c_001ffcc1\n"
    );
}

/* line 499 */
static __attribute__((naked))
void finish_output_pass(j_decompress_ptr cinfo, j_decompress_ptr cinfo_1)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 499 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 0x188(%edx), %esi\n" /* line 500 | master */
        "cmpb $0, 0x52(%edx)\n" /* line 502 */
        "je .Lf1ffe40_001ffe62\n"
        "movl 0x1b0(%edx), %eax\n" /* line 503 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        ".Lf1ffe40_001ffe62:\n"
        "addl $1, 0xc(%esi)\n" /* line 504 | master */
        "addl $0x14, %esp\n" /* line 505 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "addb %al, (%eax)\n"
        "addb %dl, -0x77(%ebp)\n"
        "inl $0x57, %eax\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %edi\n" /* cinfo */
        "cmpl $0xca, 0x14(%edi)\n"
        "je .Lf1ffe40_001ffea1\n"
        "movl (%edi), %eax\n"
        "movl $0x14, 0x14(%eax)\n"
        "movl (%edi), %edx\n"
        "movl 0x14(%edi), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf1ffe40_001ffea1:\n"
        "movl 0x38(%edi), %ecx\n"
        "movl 0x3c(%edi), %edx\n"
        "leal (, %ecx, 8), %eax\n"
        "cmpl %edx, %eax\n"
        "jbe 0x200086\n"
    );
}

/* line 86 */
__attribute__((naked))
void jpeg_calc_output_dimensions(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 86 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %edi\n" /* cinfo */
        "cmpl $0xca, 0x14(%edi)\n" /* line 93 | cinfo */
        "je .Lf1ffe6f_001ffea1\n"
        "movl (%edi), %eax\n" /* line 94 | cinfo */
        "movl $0x14, 0x14(%eax)\n"
        "movl (%edi), %edx\n" /* cinfo */
        "movl 0x14(%edi), %eax\n" /* cinfo */
        "movl %eax, 0x18(%edx)\n"
        "movl (%edi), %eax\n" /* cinfo */
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        ".Lf1ffe6f_001ffea1:\n"
        "movl 0x38(%edi), %ecx\n" /* line 99 | cinfo */
        "movl 0x3c(%edi), %edx\n" /* cinfo */
        "leal (, %ecx, 8), %eax\n"
        "cmpl %edx, %eax\n"
        "jbe .Lf1ffe6f_00200086\n"
        "leal (, %ecx, 4), %eax\n" /* line 106 */
        "cmpl %eax, %edx\n"
        "jae .Lf1ffe6f_001ffffc\n"
        "leal (%ecx, %ecx), %eax\n" /* line 113 */
        "cmpl %eax, %edx\n"
        "jae .Lf1ffe6f_00200172\n"
        "movl 0x24(%edi), %eax\n" /* line 122 | cinfo */
        "movl %eax, 0x64(%edi)\n" /* cinfo */
        "movl 0x28(%edi), %eax\n" /* line 123 | cinfo */
        "movl %eax, 0x68(%edi)\n" /* cinfo */
        "movl $8, 0x120(%edi)\n" /* line 124 | cinfo */
        ".Lf1ffe6f_001ffee6:\n"
        "movl 0xcc(%edi), %ecx\n" /* line 131 | cinfo */
        "movl 0x2c(%edi), %esi\n" /* cinfo, ci */
        "testl %esi, %esi\n" /* ci */
        "jle .Lf1ffe6f_00200043\n"
        ".Lf1ffe6f_001ffef7:\n"
        "xorl %esi, %esi\n" /* ci */
        /* { scope 2 */
        ".Lf1ffe6f_001ffef9:\n"
        "movl 0x120(%edi), %edx\n" /* line 133 | cinfo, ssize */
        "cmpl $7, %edx\n" /* line 134 */
        "jg .Lf1ffe6f_001fff56\n"
        "movl 8(%ecx), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl %edx, %eax\n"
        "imull 0x118(%edi), %eax\n" /* cinfo */
        "movl %eax, -0x2c(%ebp)\n"
        "movl -0x20(%ebp), %eax\n"
        "imull %edx, %eax\n"
        "addl %eax, %eax\n"
        "cmpl -0x2c(%ebp), %eax\n"
        "jg .Lf1ffe6f_001fff56\n"
        "movl 0xc(%ecx), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl %edx, %eax\n"
        "imull 0x11c(%edi), %eax\n" /* cinfo */
        "movl %eax, -0x28(%ebp)\n"
        ".Lf1ffe6f_001fff35:\n"
        "movl -0x24(%ebp), %eax\n"
        "imull %edx, %eax\n"
        "addl %eax, %eax\n"
        "cmpl -0x28(%ebp), %eax\n"
        "jg .Lf1ffe6f_001fff56\n"
        "addl %edx, %edx\n" /* line 139 */
        "cmpl $7, %edx\n" /* line 134 */
        "jg .Lf1ffe6f_001fff56\n"
        "movl -0x20(%ebp), %eax\n"
        "imull %edx, %eax\n"
        "addl %eax, %eax\n"
        "cmpl -0x2c(%ebp), %eax\n"
        "jle .Lf1ffe6f_001fff35\n"
        ".Lf1ffe6f_001fff56:\n"
        "movl %edx, 0x24(%ecx)\n" /* line 141 */
        /* } scope */
        "addl $1, %esi\n" /* line 132 | ci */
        "addl $0x54, %ecx\n"
        "cmpl %esi, 0x2c(%edi)\n" /* line 131 | ci, cinfo */
        "jg .Lf1ffe6f_001ffef9\n"
        "movl 0xcc(%edi), %esi\n" /* line 147 | cinfo, ci */
        "movl 0x2c(%edi), %edx\n" /* cinfo */
        "testl %edx, %edx\n"
        "jle .Lf1ffe6f_001fffcd\n"
        "movl $0, -0x1c(%ebp)\n"
        ".Lf1ffe6f_001fff78:\n"
        "movl 0x118(%edi), %eax\n" /* line 150 | cinfo */
        "shll $3, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%esi), %eax\n" /* ci */
        "imull 0x24(%esi), %eax\n" /* ci */
        "imull 0x24(%edi), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll jdiv_round_up\n"
        "movl %eax, 0x28(%esi)\n" /* ci */
        "movl 0x11c(%edi), %eax\n" /* line 154 | cinfo */
        "shll $3, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%esi), %eax\n" /* ci */
        "imull 0x24(%esi), %eax\n" /* ci */
        "imull 0x28(%edi), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll jdiv_round_up\n"
        "movl %eax, 0x2c(%esi)\n" /* ci */
        "addl $1, -0x1c(%ebp)\n" /* line 148 */
        "addl $0x54, %esi\n" /* ci */
        "movl 0x2c(%edi), %edx\n" /* line 147 | cinfo */
        "cmpl -0x1c(%ebp), %edx\n"
        "jg .Lf1ffe6f_001fff78\n"
        ".Lf1ffe6f_001fffcd:\n"
        "cmpl $5, 0x34(%edi)\n" /* line 173 | cinfo */
        "ja .Lf1ffe6f_0020004c\n"
        ".Lf1ffe6f_001fffd3:\n"
        "movl 0x34(%edi), %eax\n" /* cinfo */
        "movl 0x167(%ebx, %eax, 4), %eax\n"
        "addl %ebx, %eax\n"
        "jmpl *%eax\n"
        "nop\n"
        "nop\n"
        "nop\n"
        "iretl\n"
        "addl %eax, (%eax)\n"
        "addb %al, (%edx, %eax)\n"
        "addb %cl, 2(%ebp)\n"
        "addb %al, (%eax)\n"
        "decl %ebp\n"
        "addb (%eax), %al\n"
        "addb %bl, 2(%ecx)\n"
        "addb %al, (%eax)\n"
        "popl %ecx\n"
        "addb (%eax), %al\n"
        "addb %al, %bh\n"
        ".Lf1ffe6f_001ffffc:\n"
        "incl %esp\n" /* line 108 */
        "andb $4, %al\n"
        "addb $0, %al\n"
        "addb %al, (%eax)\n"
        "movl 0x24(%edi), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll jdiv_round_up\n"
        "movl %eax, 0x64(%edi)\n" /* cinfo */
        "movl $4, 4(%esp)\n" /* line 110 */
        "movl 0x28(%edi), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll jdiv_round_up\n"
        "movl %eax, 0x68(%edi)\n" /* cinfo */
        "movl $2, 0x120(%edi)\n" /* line 112 | cinfo */
        "movl 0xcc(%edi), %ecx\n" /* line 131 | cinfo */
        "movl 0x2c(%edi), %esi\n" /* cinfo, ci */
        "testl %esi, %esi\n" /* ci */
        "jg .Lf1ffe6f_001ffef7\n"
        ".Lf1ffe6f_00200043:\n"
        "movl 0x2c(%edi), %edx\n" /* line 147 | cinfo */
        "cmpl $5, 0x34(%edi)\n" /* line 173 | cinfo */
        "jbe .Lf1ffe6f_001fffd3\n"
        ".Lf1ffe6f_0020004c:\n"
        "movl %edx, 0x6c(%edi)\n" /* line 190 | cinfo */
        ".Lf1ffe6f_0020004f:\n"
        "cmpb $0, 0x52(%edi)\n" /* line 193 | cinfo */
        "je .Lf1ffe6f_00200081\n"
        "movl $1, %eax\n"
        ".Lf1ffe6f_0020005a:\n"
        "movl %eax, 0x70(%edi)\n" /* cinfo */
        "cmpb $0, 0x50(%edi)\n" /* line 48 */
        "jne .Lf1ffe6f_00200072\n"
        "cmpb $0, 0x112(%edi)\n"
        "jne .Lf1ffe6f_00200072\n"
        "cmpl $3, 0x30(%edi)\n" /* line 51 */
        "je .Lf1ffe6f_002000e2\n"
        ".Lf1ffe6f_00200072:\n"
        "movl $1, 0x74(%edi)\n" /* line 200 | cinfo */
        ".Lf1ffe6f_00200079:\n"
        "addl $0x3c, %esp\n" /* line 201 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1ffe6f_00200081:\n"
        "movl 0x6c(%edi), %eax\n" /* line 193 | cinfo */
        "jmp .Lf1ffe6f_0020005a\n"
        ".Lf1ffe6f_00200086:\n"
        "movl $8, 4(%esp)\n" /* line 101 */
        "movl 0x24(%edi), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll jdiv_round_up\n"
        "movl %eax, 0x64(%edi)\n" /* cinfo */
        "movl $8, 4(%esp)\n" /* line 103 */
        "movl 0x28(%edi), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll jdiv_round_up\n"
        "movl %eax, 0x68(%edi)\n" /* cinfo */
        "movl $1, 0x120(%edi)\n" /* line 105 | cinfo */
        "jmp .Lf1ffe6f_001ffee6\n"
        "movl $1, 0x6c(%edi)\n" /* line 175 | cinfo */
        "jmp .Lf1ffe6f_0020004f\n"
        "movl $3, 0x6c(%edi)\n" /* line 183 | cinfo */
        "jmp .Lf1ffe6f_0020004f\n"
        "movl $4, 0x6c(%edi)\n" /* line 187 | cinfo */
        "jmp .Lf1ffe6f_0020004f\n"
        ".Lf1ffe6f_002000e2:\n"
        "cmpl $3, 0x2c(%edi)\n" /* line 51 */
        "jne .Lf1ffe6f_00200072\n"
        "cmpl $2, 0x34(%edi)\n"
        "jne .Lf1ffe6f_00200072\n"
        "cmpl $3, 0x6c(%edi)\n"
        "jne .Lf1ffe6f_00200072\n"
        "movl 0xcc(%edi), %eax\n" /* line 56 */
        "cmpl $2, 8(%eax)\n"
        "jne .Lf1ffe6f_00200072\n"
        "leal 0x54(%eax), %ecx\n"
        "cmpl $1, 8(%ecx)\n"
        "jne .Lf1ffe6f_00200072\n"
        "leal 0xa8(%eax), %edx\n"
        "cmpl $1, 8(%edx)\n"
        "jne .Lf1ffe6f_00200072\n"
        "cmpl $2, 0xc(%eax)\n"
        "jg .Lf1ffe6f_00200072\n"
        "cmpl $1, 0xc(%ecx)\n"
        "jne .Lf1ffe6f_00200072\n"
        "cmpl $1, 0xc(%edx)\n"
        "jne .Lf1ffe6f_00200072\n"
        "movl 0x24(%eax), %eax\n" /* line 64 */
        "cmpl 0x120(%edi), %eax\n"
        "jne .Lf1ffe6f_00200072\n"
        "cmpl 0x24(%ecx), %eax\n"
        "jne .Lf1ffe6f_00200072\n"
        "cmpl 0x24(%edx), %eax\n"
        "jne .Lf1ffe6f_00200072\n"
        "movl 0x11c(%edi), %eax\n" /* line 198 | cinfo */
        "movl %eax, 0x74(%edi)\n" /* cinfo */
        "jmp .Lf1ffe6f_00200079\n"
        ".Lf1ffe6f_00200172:\n"
        "movl $2, 4(%esp)\n" /* line 115 */
        "movl 0x24(%edi), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll jdiv_round_up\n"
        "movl %eax, 0x64(%edi)\n" /* cinfo */
        "movl $2, 4(%esp)\n" /* line 117 */
        "movl 0x28(%edi), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll jdiv_round_up\n"
        "movl %eax, 0x68(%edi)\n" /* cinfo */
        "movl $4, 0x120(%edi)\n" /* line 119 | cinfo */
        "jmp .Lf1ffe6f_001ffee6\n"
    );
}

/* line 544 */
__attribute__((naked))
void jinit_master_decompress(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 544 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %edi\n" /* cinfo */
        "movl 4(%edi), %eax\n" /* line 547 | cinfo */
        "movl $0x1c, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "movl %eax, 0x188(%edi)\n" /* line 550 | cinfo */
        "leal -0x51f(%ebx), %edx\n" /* line 551 */
        "movl %edx, (%eax)\n"
        "leal -0x37b(%ebx), %edx\n" /* line 552 */
        "movl %edx, 4(%eax)\n"
        "movb $0, 8(%eax)\n" /* line 554 */
        /* { scope 1: table */
        "movl 0x188(%edi), %eax\n" /* line 290 */
        "movl %eax, -0x20(%ebp)\n" /* master */
        "movl %edi, (%esp)\n" /* line 296 */
        "calll jpeg_calc_output_dimensions\n"
        /* { scope 2 */
        "movl 4(%edi), %eax\n" /* line 254 */
        "movl $0x580, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "movl %eax, -0x1c(%ebp)\n" /* table */
        "movl %eax, %esi\n" /* line 257 */
        "addl $0x100, %esi\n"
        "movl %esi, 0x128(%edi)\n" /* line 258 */
        "movl $0x100, 8(%esp)\n" /* line 260 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "xorl %eax, %eax\n"
        ".Lf2001ad_00200245:\n"
        "movb %al, (%esi, %eax)\n" /* line 263 */
        "addl $1, %eax\n" /* line 262 */
        "cmpl $0x100, %eax\n"
        "jne .Lf2001ad_00200245\n"
        "movl -0x1c(%ebp), %edx\n" /* line 264 | table */
        "addl $0x180, %edx\n"
        "xorw %ax, %ax\n"
        ".Lf2001ad_0020025e:\n"
        "movb $0xff, 0x80(%edx, %eax)\n" /* line 267 */
        "addl $1, %eax\n"
        "cmpl $0x180, %eax\n" /* line 266 */
        "jne .Lf2001ad_0020025e\n"
        "movl -0x1c(%ebp), %eax\n" /* line 269 | table */
        "addl $0x380, %eax\n"
        "movl $0x180, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl -0x1c(%ebp), %edx\n" /* line 271 | table */
        "addl $0x500, %edx\n"
        "movl 0x128(%edi), %eax\n"
        "movl $0x80, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        /* } scope */
        "movl -0x20(%ebp), %edx\n" /* line 306 | master */
        "movl $0, 0xc(%edx)\n"
        "cmpb $0, 0x50(%edi)\n" /* line 48 */
        "jne .Lf2001ad_002002d0\n"
        "cmpb $0, 0x112(%edi)\n"
        "je .Lf2001ad_002004c0\n"
        ".Lf2001ad_002002d0:\n"
        "xorl %eax, %eax\n" /* line 64 */
        ".Lf2001ad_002002d2:\n"
        "movl -0x20(%ebp), %edx\n" /* line 307 | master */
        "movb %al, 0x10(%edx)\n"
        "movl $0, 0x14(%edx)\n" /* line 310 */
        "movl $0, 0x18(%edx)\n" /* line 311 */
        "cmpb $0, 0x52(%edi)\n" /* line 313 */
        "je .Lf2001ad_00200450\n"
        "cmpb $0, 0x48(%edi)\n"
        "je .Lf2001ad_00200450\n"
        "cmpb $0, 0x49(%edi)\n" /* line 319 */
        "jne .Lf2001ad_002005a1\n"
        ".Lf2001ad_00200304:\n"
        "cmpl $3, 0x6c(%edi)\n" /* line 322 */
        "je .Lf2001ad_00200573\n"
        ".Lf2001ad_0020030e:\n"
        "movb $1, 0x60(%edi)\n" /* line 323 */
        "movb $0, 0x61(%edi)\n" /* line 324 */
        "movb $0, 0x62(%edi)\n" /* line 325 */
        "movl $0, 0x7c(%edi)\n" /* line 326 */
        ".Lf2001ad_00200321:\n"
        "cmpb $0, 0x60(%edi)\n" /* line 335 */
        "jne .Lf2001ad_00200588\n"
        ".Lf2001ad_0020032b:\n"
        "testl $0xffff00, 0x60(%edi)\n" /* line 345 */
        "je .Lf2001ad_00200348\n"
        "movl %edi, (%esp)\n" /* line 347 */
        "calll jinit_2pass_quantizer\n"
        "movl 0x1b0(%edi), %eax\n" /* line 348 */
        "movl -0x20(%ebp), %edx\n" /* master */
        "movl %eax, 0x18(%edx)\n"
        ".Lf2001ad_00200348:\n"
        "cmpb $0, 0x49(%edi)\n" /* line 359 */
        "jne .Lf2001ad_00200373\n"
        "movl -0x20(%ebp), %eax\n" /* line 360 | master */
        "cmpb $0, 0x10(%eax)\n"
        "je .Lf2001ad_0020055e\n"
        "movl %edi, (%esp)\n" /* line 362 */
        "calll jinit_merged_upsampler\n"
        ".Lf2001ad_00200363:\n"
        "movzbl 0x62(%edi), %eax\n" /* line 370 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll jinit_d_post_controller\n"
        ".Lf2001ad_00200373:\n"
        "movl %edi, (%esp)\n" /* line 373 */
        "calll jinit_inverse_dct\n"
        "cmpb $0, 0xd1(%edi)\n" /* line 375 */
        "jne .Lf2001ad_002005bd\n"
        "cmpb $0, 0xd0(%edi)\n" /* line 378 */
        "je .Lf2001ad_00200475\n"
        "movl %edi, (%esp)\n" /* line 380 */
        "calll jinit_phuff_decoder\n"
        ".Lf2001ad_0020039d:\n"
        "movl 0x198(%edi), %eax\n" /* line 389 */
        "cmpb $0, 0x10(%eax)\n"
        "jne .Lf2001ad_0020048d\n"
        ".Lf2001ad_002003ad:\n"
        "cmpb $0, 0x48(%edi)\n"
        "jne .Lf2001ad_0020048d\n"
        "xorl %eax, %eax\n"
        "movzbl %al, %eax\n" /* line 390 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll jinit_d_coef_controller\n"
        "cmpb $0, 0x49(%edi)\n" /* line 392 */
        "je .Lf2001ad_002004ab\n"
        ".Lf2001ad_002003d2:\n"
        "movl 4(%edi), %eax\n" /* line 396 */
        "movl %edi, (%esp)\n"
        "calll *0x18(%eax)\n"
        "movl 0x198(%edi), %eax\n" /* line 399 */
        "movl %edi, (%esp)\n"
        "calll *8(%eax)\n"
        "movl 8(%edi), %ecx\n" /* line 406 */
        "testl %ecx, %ecx\n"
        "je .Lf2001ad_00200448\n"
        "cmpb $0, 0x48(%edi)\n"
        "jne .Lf2001ad_00200448\n"
        "movl 0x198(%edi), %eax\n"
        "cmpb $0, 0x10(%eax)\n"
        "je .Lf2001ad_00200448\n"
        /* { scope 2 */
        "cmpb $0, 0xd0(%edi)\n" /* line 410 */
        "je .Lf2001ad_002005d2\n"
        "movl 0x2c(%edi), %eax\n" /* line 412 */
        "leal 2(%eax, %eax, 2), %edx\n"
        ".Lf2001ad_00200414:\n"
        "movl $0, 4(%ecx)\n" /* line 417 */
        "movl 8(%edi), %eax\n" /* line 418 */
        "imull 0x124(%edi), %edx\n"
        "movl %edx, 8(%eax)\n"
        "movl 8(%edi), %eax\n" /* line 419 */
        "movl $0, 0xc(%eax)\n"
        "movl 8(%edi), %edx\n" /* line 420 */
        "cmpb $1, 0x62(%edi)\n"
        "sbbl %eax, %eax\n"
        "addl $3, %eax\n"
        "movl %eax, 0x10(%edx)\n"
        "movl -0x20(%ebp), %edx\n" /* line 422 | master */
        "addl $1, 0xc(%edx)\n"
        /* } scope */
        /* } scope */
        ".Lf2001ad_00200448:\n"
        "addl $0x2c, %esp\n" /* line 557 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: table */
        ".Lf2001ad_00200450:\n"
        "movb $0, 0x60(%edi)\n" /* line 314 */
        "movb $0, 0x61(%edi)\n" /* line 315 */
        "movb $0, 0x62(%edi)\n" /* line 316 */
        "cmpb $0, 0x52(%edi)\n" /* line 318 */
        "je .Lf2001ad_00200348\n"
        "cmpb $0, 0x49(%edi)\n" /* line 319 */
        "je .Lf2001ad_00200304\n"
        "jmp .Lf2001ad_002005a1\n"
        ".Lf2001ad_00200475:\n"
        "movl %edi, (%esp)\n" /* line 385 */
        "calll jinit_huff_decoder\n"
        "movl 0x198(%edi), %eax\n" /* line 389 */
        "cmpb $0, 0x10(%eax)\n"
        "je .Lf2001ad_002003ad\n"
        ".Lf2001ad_0020048d:\n"
        "movl $1, %eax\n"
        "movzbl %al, %eax\n" /* line 390 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll jinit_d_coef_controller\n"
        "cmpb $0, 0x49(%edi)\n" /* line 392 */
        "jne .Lf2001ad_002003d2\n"
        ".Lf2001ad_002004ab:\n"
        "movl $0, 4(%esp)\n" /* line 393 */
        "movl %edi, (%esp)\n"
        "calll jinit_d_main_controller\n"
        "jmp .Lf2001ad_002003d2\n"
        ".Lf2001ad_002004c0:\n"
        "cmpl $3, 0x30(%edi)\n" /* line 51 */
        "jne .Lf2001ad_002002d0\n"
        "cmpl $3, 0x2c(%edi)\n"
        "jne .Lf2001ad_002002d0\n"
        "cmpl $2, 0x34(%edi)\n"
        "jne .Lf2001ad_002002d0\n"
        "cmpl $3, 0x6c(%edi)\n"
        "jne .Lf2001ad_002002d0\n"
        "movl 0xcc(%edi), %eax\n" /* line 56 */
        "cmpl $2, 8(%eax)\n"
        "jne .Lf2001ad_002002d0\n"
        "leal 0x54(%eax), %ecx\n"
        "cmpl $1, 8(%ecx)\n"
        "jne .Lf2001ad_002002d0\n"
        "leal 0xa8(%eax), %edx\n"
        "cmpl $1, 8(%edx)\n"
        "jne .Lf2001ad_002002d0\n"
        "cmpl $2, 0xc(%eax)\n"
        "jg .Lf2001ad_002002d0\n"
        "cmpl $1, 0xc(%ecx)\n"
        "jne .Lf2001ad_002002d0\n"
        "cmpl $1, 0xc(%edx)\n"
        "jne .Lf2001ad_002002d0\n"
        "movl 0x24(%eax), %eax\n" /* line 64 */
        "cmpl 0x120(%edi), %eax\n"
        "jne .Lf2001ad_002002d0\n"
        "cmpl 0x24(%ecx), %eax\n"
        "jne .Lf2001ad_002002d0\n"
        "cmpl 0x24(%edx), %eax\n"
        "jne .Lf2001ad_002002d0\n"
        "movl $1, %eax\n"
        "jmp .Lf2001ad_002002d2\n"
        ".Lf2001ad_0020055e:\n"
        "movl %edi, (%esp)\n" /* line 367 */
        "calll jinit_color_deconverter\n"
        "movl %edi, (%esp)\n" /* line 368 */
        "calll jinit_upsampler\n"
        "jmp .Lf2001ad_00200363\n"
        ".Lf2001ad_00200573:\n"
        "movl 0x7c(%edi), %eax\n" /* line 327 */
        "testl %eax, %eax\n"
        "je .Lf2001ad_002005da\n"
        "movb $1, 0x61(%edi)\n" /* line 328 */
        "cmpb $0, 0x60(%edi)\n" /* line 335 */
        "je .Lf2001ad_0020032b\n"
        ".Lf2001ad_00200588:\n"
        "movl %edi, (%esp)\n" /* line 337 */
        "calll jinit_1pass_quantizer\n"
        "movl 0x1b0(%edi), %eax\n" /* line 338 */
        "movl -0x20(%ebp), %edx\n" /* master */
        "movl %eax, 0x14(%edx)\n"
        "jmp .Lf2001ad_0020032b\n"
        ".Lf2001ad_002005a1:\n"
        "movl (%edi), %eax\n" /* line 320 */
        "movl $0x2f, 0x14(%eax)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "cmpl $3, 0x6c(%edi)\n" /* line 322 */
        "jne .Lf2001ad_0020030e\n"
        "jmp .Lf2001ad_00200573\n"
        ".Lf2001ad_002005bd:\n"
        "movl (%edi), %eax\n" /* line 376 */
        "movl $1, 0x14(%eax)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf2001ad_0020039d\n"
        /* { scope 2 */
        ".Lf2001ad_002005d2:\n"
        "movl 0x2c(%edi), %edx\n" /* line 415 */
        "jmp .Lf2001ad_00200414\n"
        /* } scope */
        ".Lf2001ad_002005da:\n"
        "cmpb $0, 0x58(%edi)\n" /* line 329 */
        "je .Lf2001ad_002005e9\n"
        "movb $1, 0x62(%edi)\n" /* line 330 */
        "jmp .Lf2001ad_00200321\n"
        ".Lf2001ad_002005e9:\n"
        "movb $1, 0x60(%edi)\n" /* line 332 */
        "jmp .Lf2001ad_00200321\n"
    );
}

