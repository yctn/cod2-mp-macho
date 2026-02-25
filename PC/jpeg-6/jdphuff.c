/* ASM dump from: jdphuff.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jdphuff.c */

#include "common_types.h"
#include "imports.h"

static const int extend_test[16]; /* 0x307520 */
static const int extend_offset[16]; /* 0x3074e0 */

static void start_pass_phuff_decoder(j_decompress_ptr cinfo);
static boolean decode_mcu_AC_refine(j_decompress_ptr cinfo, JBLOCKROW *MCU_data);
void jinit_phuff_decoder(j_decompress_ptr cinfo);
static boolean decode_mcu_DC_first(j_decompress_ptr cinfo, JBLOCKROW *MCU_data);
static boolean decode_mcu_AC_first(j_decompress_ptr cinfo, JBLOCKROW *MCU_data);
static boolean decode_mcu_DC_refine(j_decompress_ptr cinfo, JBLOCKROW *MCU_data);

/* line 93 */
static __attribute__((naked))
void start_pass_phuff_decoder(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1: cindex */
        "pushl %ebp\n" /* line 93 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %eax\n" /* line 94 | cinfo */
        "movl 0x1a0(%eax), %eax\n"
        "movl %eax, -0x38(%ebp)\n" /* entropy */
        "movl 8(%ebp), %edx\n" /* line 100 | cinfo */
        "movl 0x174(%edx), %eax\n"
        "testl %eax, %eax\n"
        "sete -0x31(%ebp)\n" /* is_DC_band */
        "cmpb $0, -0x31(%ebp)\n" /* line 104 | is_DC_band */
        "je .Lf208b28_00208d9b\n"
        "movl 0x178(%edx), %ecx\n" /* line 105 */
        "testl %ecx, %ecx\n"
        "je .Lf208b28_00208e08\n"
        ".Lf208b28_00208b69:\n"
        "movl $1, %edx\n" /* line 112 */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        ".Lf208b28_00208b71:\n"
        "movl 0x17c(%ecx), %eax\n" /* line 115 */
        "testl %eax, %eax\n"
        "je .Lf208b28_00208d88\n"
        "subl $1, %eax\n" /* line 117 */
        "cmpl %eax, 0x180(%ecx)\n"
        "movl $1, %eax\n"
        "cmovnel %eax, %edx\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "cmpl $0xd, 0x180(%eax)\n" /* line 120 */
        "jg .Lf208b28_00208d97\n"
        ".Lf208b28_00208ba0:\n"
        "testb %dl, %dl\n" /* line 128 */
        "jne .Lf208b28_00208dc1\n"
        ".Lf208b28_00208ba8:\n"
        "movl 8(%ebp), %eax\n" /* line 135 | cinfo */
        "movl 0x12c(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf208b28_00208c77\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl $0, -0x30(%ebp)\n" /* ci */
        "movl %eax, %edx\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        /* { scope 2 */
        ".Lf208b28_00208bc8:\n"
        "movl 0x130(%edx), %eax\n" /* line 136 */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* cindex */
        "movl %eax, %esi\n" /* line 137 | coef_bit_ptr */
        "shll $8, %esi\n" /* coef_bit_ptr */
        "addl 0x94(%ecx), %esi\n" /* coef_bit_ptr */
        "cmpb $0, -0x31(%ebp)\n" /* line 138 | is_DC_band */
        "jne .Lf208b28_00208bf2\n"
        "movl (%esi), %edi\n" /* coef_bit_ptr, coefi */
        "testl %edi, %edi\n" /* coefi */
        "js .Lf208b28_00208e3d\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        ".Lf208b28_00208bf2:\n"
        "movl 0x174(%ecx), %edi\n" /* line 140 | coefi */
        "cmpl 0x178(%ecx), %edi\n" /* coefi */
        "jg .Lf208b28_00208c5c\n"
        "leal (%esi, %edi, 4), %esi\n" /* coef_bit_ptr */
        ".Lf208b28_00208c03:\n"
        "movl (%esi), %eax\n" /* line 142 | coef_bit_ptr */
        "testl %eax, %eax\n"
        "movl $0, %edx\n"
        "cmovsl %edx, %eax\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "cmpl 0x17c(%edx), %eax\n"
        "je .Lf208b28_00208c43\n"
        "movl (%edx), %eax\n" /* line 143 */
        "movl $0x73, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl -0x2c(%ebp), %ecx\n" /* cindex */
        "movl %ecx, 0x18(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edi, 0x1c(%eax)\n" /* coefi */
        "movl (%edx), %eax\n"
        "movl $0xffffffff, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        ".Lf208b28_00208c43:\n"
        "movl 0x180(%edx), %eax\n" /* line 144 */
        "movl %eax, (%esi)\n" /* coef_bit_ptr */
        "addl $1, %edi\n" /* line 140 | coefi */
        "addl $4, %esi\n" /* coef_bit_ptr */
        "cmpl 0x178(%edx), %edi\n" /* coefi */
        "jle .Lf208b28_00208c03\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        /* } scope */
        ".Lf208b28_00208c5c:\n"
        "addl $1, -0x30(%ebp)\n" /* line 135 | ci */
        "addl $4, -0x24(%ebp)\n"
        "movl -0x30(%ebp), %eax\n" /* ci */
        "cmpl 0x12c(%ecx), %eax\n"
        "jge .Lf208b28_00208cd9\n"
        "movl -0x24(%ebp), %edx\n"
        "jmp .Lf208b28_00208bc8\n"
        ".Lf208b28_00208c77:\n"
        "movl %eax, %edx\n"
        "movl 0x17c(%edx), %esi\n" /* line 149 | coef_bit_ptr */
        "testl %esi, %esi\n" /* coef_bit_ptr */
        "jne .Lf208b28_00208ce5\n"
        ".Lf208b28_00208c83:\n"
        "cmpb $0, -0x31(%ebp)\n" /* line 150 | is_DC_band */
        "jne .Lf208b28_00208e2c\n"
        "leal 0xe71(%ebx), %eax\n" /* line 153 */
        "movl -0x38(%ebp), %edx\n" /* entropy */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebp), %ecx\n" /* line 161 | cinfo */
        "movl 0x12c(%ecx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jg .Lf208b28_00208d08\n"
        ".Lf208b28_00208ca6:\n"
        "movl -0x38(%ebp), %eax\n" /* line 184 | entropy */
        "movl $0, 0x10(%eax)\n"
        "movl $0, 0xc(%eax)\n" /* line 185 */
        "movb $0, 8(%eax)\n" /* line 186 */
        "movl $0, 0x14(%eax)\n" /* line 189 */
        "movl 8(%ebp), %edx\n" /* line 192 | cinfo */
        "movl 0x104(%edx), %eax\n"
        "movl -0x38(%ebp), %ecx\n" /* entropy */
        "movl %eax, 0x28(%ecx)\n"
        "addl $0x4c, %esp\n" /* line 193 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf208b28_00208cd9:\n"
        "movl %ecx, %edx\n"
        "movl 0x17c(%edx), %esi\n" /* line 149 | coef_bit_ptr */
        "testl %esi, %esi\n" /* coef_bit_ptr */
        "je .Lf208b28_00208c83\n"
        ".Lf208b28_00208ce5:\n"
        "cmpb $0, -0x31(%ebp)\n" /* line 155 | is_DC_band */
        "je .Lf208b28_00208e1b\n"
        "leal 0x11dc(%ebx), %eax\n" /* line 156 */
        "movl -0x38(%ebp), %ecx\n" /* entropy */
        "movl %eax, 4(%ecx)\n"
        ".Lf208b28_00208cfb:\n"
        "movl 8(%ebp), %ecx\n" /* line 161 | cinfo */
        "movl 0x12c(%ecx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lf208b28_00208ca6\n"
        ".Lf208b28_00208d08:\n"
        "cmpb $0, -0x31(%ebp)\n" /* line 193 | is_DC_band */
        "jne .Lf208b28_00208e6f\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, -0x28(%ebp)\n"
        "movl -0x38(%ebp), %edi\n" /* entropy, coefi */
        "movl $0, -0x1c(%ebp)\n"
        "leal 0x2c(%edi), %edx\n" /* coefi */
        "movl %edx, -0x3c(%ebp)\n"
        "movl %eax, %ecx\n"
        "jmp .Lf208b28_00208d32\n"
        ".Lf208b28_00208d2c:\n"
        "movl -0x28(%ebp), %ecx\n"
        "movl -0x3c(%ebp), %edx\n"
        ".Lf208b28_00208d32:\n"
        "movl 0x130(%ecx), %eax\n" /* line 173 */
        "movl 0x18(%eax), %esi\n" /* coef_bit_ptr */
        "leal (%edx, %esi, 4), %eax\n" /* line 174 */
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* coef_bit_ptr */
        "movl $0, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %ecx, (%esp)\n"
        "calll jpeg_make_d_derived_tbl\n"
        "movl -0x38(%ebp), %edx\n" /* line 177 | entropy */
        "movl 0x2c(%edx, %esi, 4), %eax\n"
        "movl %eax, 0x3c(%edx)\n"
        "movl $0, 0x18(%edi)\n" /* line 180 | coefi */
        "addl $1, -0x1c(%ebp)\n" /* line 161 */
        "addl $4, -0x28(%ebp)\n"
        "addl $4, %edi\n" /* coefi */
        "movl -0x1c(%ebp), %eax\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "cmpl 0x12c(%ecx), %eax\n"
        "jl .Lf208b28_00208d2c\n"
        "jmp .Lf208b28_00208ca6\n"
        ".Lf208b28_00208d88:\n"
        "movl %ecx, %eax\n"
        "cmpl $0xd, 0x180(%eax)\n" /* line 120 */
        "jle .Lf208b28_00208ba0\n"
        ".Lf208b28_00208d97:\n"
        "movl %eax, %edx\n"
        "jmp .Lf208b28_00208dc4\n"
        ".Lf208b28_00208d9b:\n"
        "movl 0x178(%edx), %edx\n" /* line 109 */
        "cmpl %edx, %eax\n"
        "jle .Lf208b28_00208e12\n"
        ".Lf208b28_00208da5:\n"
        "movl $1, %edx\n"
        ".Lf208b28_00208daa:\n"
        "movl 8(%ebp), %eax\n" /* line 112 | cinfo */
        "cmpl $1, 0x12c(%eax)\n"
        "jne .Lf208b28_00208b69\n"
        "movl %eax, %ecx\n"
        "jmp .Lf208b28_00208b71\n"
        ".Lf208b28_00208dc1:\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        ".Lf208b28_00208dc4:\n"
        "movl (%edx), %eax\n" /* line 129 */
        "movl $0x10, 0x14(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl (%ecx), %edx\n"
        "movl 0x174(%ecx), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl (%ecx), %edx\n"
        "movl 0x178(%ecx), %eax\n"
        "movl %eax, 0x1c(%edx)\n"
        "movl (%ecx), %edx\n"
        "movl 0x17c(%ecx), %eax\n"
        "movl %eax, 0x20(%edx)\n"
        "movl (%ecx), %edx\n"
        "movl 0x180(%ecx), %eax\n"
        "movl %eax, 0x24(%edx)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf208b28_00208ba8\n"
        ".Lf208b28_00208e08:\n"
        "xorl %edx, %edx\n" /* line 105 */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "jmp .Lf208b28_00208b71\n"
        ".Lf208b28_00208e12:\n"
        "cmpl $0x3f, %edx\n" /* line 109 */
        "jg .Lf208b28_00208da5\n"
        "xorl %edx, %edx\n"
        "jmp .Lf208b28_00208daa\n"
        ".Lf208b28_00208e1b:\n"
        "leal 0x3a2(%ebx), %eax\n" /* line 158 */
        "movl -0x38(%ebp), %edx\n" /* entropy */
        "movl %eax, 4(%edx)\n"
        "jmp .Lf208b28_00208cfb\n"
        ".Lf208b28_00208e2c:\n"
        "leal 0xb5b(%ebx), %eax\n" /* line 151 */
        "movl -0x38(%ebp), %ecx\n" /* entropy */
        "movl %eax, 4(%ecx)\n"
        "jmp .Lf208b28_00208cfb\n"
        /* { scope 2 */
        ".Lf208b28_00208e3d:\n"
        "movl (%ecx), %eax\n" /* line 139 */
        "movl $0x73, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl -0x2c(%ebp), %edx\n" /* cindex */
        "movl %edx, 0x18(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl $0, 0x1c(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl $0xffffffff, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *4(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "jmp .Lf208b28_00208bf2\n"
        /* } scope */
        ".Lf208b28_00208e6f:\n"
        "movl 8(%ebp), %edi\n" /* line 161 | cinfo, coefi */
        "movl -0x38(%ebp), %esi\n" /* entropy, coef_bit_ptr */
        "movl $0, -0x20(%ebp)\n"
        ".Lf208b28_00208e7c:\n"
        "movl 0x130(%edi), %eax\n" /* line 162 | coefi */
        "movl 8(%ebp), %edx\n" /* line 167 | cinfo */
        "movl 0x17c(%edx), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf208b28_00208eb4\n"
        "movl 0x14(%eax), %edx\n" /* line 168 */
        "movl -0x38(%ebp), %ecx\n" /* line 169 | entropy */
        "leal 0x2c(%ecx, %edx, 4), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll jpeg_make_d_derived_tbl\n"
        ".Lf208b28_00208eb4:\n"
        "movl $0, 0x18(%esi)\n" /* line 180 | coef_bit_ptr */
        "addl $1, -0x20(%ebp)\n" /* line 161 */
        "addl $4, %edi\n" /* coefi */
        "addl $4, %esi\n" /* coef_bit_ptr */
        "movl -0x20(%ebp), %ecx\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "cmpl 0x12c(%edx), %ecx\n"
        "jl .Lf208b28_00208e7c\n"
        "jmp .Lf208b28_00208ca6\n"
    );
}

/* line 492 */
static __attribute__((naked))
boolean decode_mcu_AC_refine(j_decompress_ptr cinfo, JBLOCKROW *MCU_data)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 492 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x18c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %eax\n" /* line 493 | cinfo */
        "movl 0x1a0(%eax), %eax\n"
        "movl %eax, -0x13c(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 494 | cinfo */
        "movl 0x178(%edx), %edx\n"
        "movl %edx, -0x16c(%ebp)\n" /* Se */
        "movl 8(%ebp), %edi\n" /* line 495 | cinfo */
        "movl 0x180(%edi), %ecx\n"
        "movl $1, -0x168(%ebp)\n" /* p1 */
        "shll %cl, -0x168(%ebp)\n" /* p1 */
        "movl $0xffffffff, -0x164(%ebp)\n" /* line 496 | m1 */
        "shll %cl, -0x164(%ebp)\n" /* m1 */
        "movl 0x104(%edi), %ecx\n" /* line 507 | thiscoef */
        "testl %ecx, %ecx\n"
        "je .Lf208ed8_00208f67\n"
        "movl 0x28(%eax), %edx\n" /* line 508 */
        "testl %edx, %edx\n"
        "je .Lf208ed8_002092c7\n"
        ".Lf208ed8_00208f45:\n"
        "movl -0x13c(%ebp), %edi\n" /* thiscoef */
        "cmpb $0, 8(%edi)\n" /* line 515 | thiscoef */
        "je .Lf208ed8_00208f6f\n"
        ".Lf208ed8_00208f51:\n"
        "movl %edi, %eax\n" /* thiscoef */
        ".Lf208ed8_00208f53:\n"
        "subl $1, 0x28(%eax)\n" /* line 623 */
        "movl $1, %eax\n"
        "addl $0x18c, %esp\n" /* line 633 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf208ed8_00208f67:\n"
        "movl %eax, %edi\n" /* thiscoef */
        ".Lf208ed8_00208f69:\n"
        "cmpb $0, 8(%edi)\n" /* line 515 | thiscoef */
        "jne .Lf208ed8_00208f51\n"
        ".Lf208ed8_00208f6f:\n"
        "movl 8(%ebp), %eax\n" /* line 518 | cinfo */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0x20(%eax), %edx\n"
        "movl (%edx), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* br_state */
        "movl 4(%edx), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl 0xc(%edi), %ecx\n" /* thiscoef */
        "movl %ecx, -0x150(%ebp)\n" /* get_buffer */
        "movl 0x10(%edi), %edi\n" /* thiscoef */
        "movl %edi, -0x14c(%ebp)\n" /* thiscoef, bits_left */
        "movl -0x13c(%ebp), %eax\n" /* line 519 */
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x158(%ebp)\n" /* EOBRUN */
        "movl 0xc(%ebp), %ecx\n" /* line 522 | MCU_data */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x154(%ebp)\n" /* block */
        "movl -0x13c(%ebp), %edi\n" /* line 523 | thiscoef */
        "movl 0x3c(%edi), %edi\n" /* thiscoef */
        "movl %edi, -0x148(%ebp)\n" /* thiscoef, tbl */
        "movl 8(%ebp), %eax\n" /* line 534 | cinfo */
        "movl 0x174(%eax), %eax\n"
        "movl %eax, -0x160(%ebp)\n" /* k */
        "movl -0x158(%ebp), %ecx\n" /* line 536 | EOBRUN */
        "testl %ecx, %ecx\n"
        "je .Lf208ed8_002090bc\n"
        "movl $0, -0x144(%ebp)\n" /* num_newnz */
        ".Lf208ed8_00208fe5:\n"
        "movl -0x160(%ebp), %eax\n" /* line 599 | k */
        "cmpl %eax, -0x16c(%ebp)\n" /* Se */
        "jl .Lf208ed8_00209072\n"
        "movl %eax, %edx\n"
        "movl 0x1756adf(%ebx), %eax\n"
        "leal (%eax, %edx, 4), %esi\n"
        ".Lf208ed8_00208ffe:\n"
        "movl (%esi), %eax\n" /* line 600 */
        "movl -0x154(%ebp), %ecx\n" /* block */
        "leal (%ecx, %eax, 2), %edi\n" /* thiscoef */
        "cmpw $0, (%edi)\n" /* line 601 | thiscoef */
        "je .Lf208ed8_0020905a\n"
        "movl -0x14c(%ebp), %eax\n" /* line 602 | bits_left */
        "testl %eax, %eax\n"
        "jle .Lf208ed8_002094a0\n"
        "movl -0x150(%ebp), %eax\n" /* get_buffer */
        ".Lf208ed8_00209023:\n"
        "subl $1, -0x14c(%ebp)\n" /* line 603 | bits_left */
        "movzbl -0x14c(%ebp), %ecx\n" /* bits_left */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf208ed8_0020905a\n"
        "movzwl (%edi), %edx\n" /* line 604 | thiscoef */
        "movswl %dx, %eax\n"
        "testl %eax, -0x168(%ebp)\n" /* p1 */
        "jne .Lf208ed8_0020905a\n"
        "testw %dx, %dx\n" /* line 605 */
        "js .Lf208ed8_0020952c\n"
        "movl -0x168(%ebp), %ecx\n" /* line 606 | p1 */
        "leal (%edx, %ecx), %eax\n"
        "movw %ax, (%edi)\n" /* thiscoef */
        ".Lf208ed8_0020905a:\n"
        "addl $1, -0x160(%ebp)\n" /* line 599 | k */
        "addl $4, %esi\n"
        "movl -0x160(%ebp), %edi\n" /* k, thiscoef */
        "cmpl %edi, -0x16c(%ebp)\n" /* thiscoef, Se */
        "jge .Lf208ed8_00208ffe\n"
        ".Lf208ed8_00209072:\n"
        "subl $1, -0x158(%ebp)\n" /* line 614 | EOBRUN */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 0x20(%eax), %edx\n"
        ".Lf208ed8_0020907f:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 618 | br_state */
        "movl %eax, (%edx)\n"
        "movl 8(%ebp), %edi\n" /* cinfo, thiscoef */
        "movl 0x20(%edi), %edx\n" /* thiscoef */
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl -0x150(%ebp), %edx\n" /* get_buffer */
        "movl -0x13c(%ebp), %eax\n"
        "movl %edx, 0xc(%eax)\n"
        "movl -0x14c(%ebp), %ecx\n" /* bits_left */
        "movl %ecx, 0x10(%eax)\n"
        "movl -0x158(%ebp), %edi\n" /* line 619 | EOBRUN, thiscoef */
        "movl %edi, 0x14(%eax)\n" /* thiscoef */
        "movl -0x13c(%ebp), %eax\n"
        "jmp .Lf208ed8_00208f53\n"
        ".Lf208ed8_002090bc:\n"
        "cmpl %eax, -0x16c(%ebp)\n" /* line 537 | Se */
        "jl .Lf208ed8_002092b8\n"
        "movl $0, -0x144(%ebp)\n" /* num_newnz */
        /* { scope 2 */
        ".Lf208ed8_002090d2:\n"
        "cmpl $7, -0x14c(%ebp)\n" /* line 538 | bits_left */
        "jle .Lf208ed8_002093e3\n"
        "movl -0x14c(%ebp), %ecx\n" /* bits_left */
        ".Lf208ed8_002090e5:\n"
        "subl $8, %ecx\n"
        "movl -0x150(%ebp), %eax\n" /* get_buffer, nb */
        "sarl %cl, %eax\n" /* nb */
        "andl $0xff, %eax\n" /* nb */
        "movl -0x148(%ebp), %ecx\n" /* tbl */
        "movl 0x90(%ecx, %eax, 4), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf208ed8_00209385\n"
        "movl $9, %eax\n" /* nb */
        "leal -0x2c(%ebp), %esi\n" /* br_state */
        ".Lf208ed8_00209112:\n"
        "movl %eax, 0x10(%esp)\n" /* nb */
        "movl -0x148(%ebp), %eax\n" /* tbl, nb */
        "movl %eax, 0xc(%esp)\n" /* nb */
        "movl -0x14c(%ebp), %edx\n" /* bits_left */
        "movl %edx, 8(%esp)\n"
        "movl -0x150(%ebp), %ecx\n" /* get_buffer */
        "movl %ecx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll jpeg_huff_decode\n"
        "testl %eax, %eax\n" /* nb */
        "js .Lf208ed8_00209458\n"
        "movl -0x24(%ebp), %edi\n" /* thiscoef */
        "movl %edi, -0x150(%ebp)\n" /* thiscoef, get_buffer */
        "movl -0x20(%ebp), %edx\n"
        "movl %edx, -0x14c(%ebp)\n" /* bits_left */
        /* } scope */
        ".Lf208ed8_00209156:\n"
        "movl %eax, %ecx\n" /* line 539 */
        "sarl $4, %ecx\n"
        "movl %ecx, -0x15c(%ebp)\n" /* r */
        "andl $0xf, %eax\n" /* line 541 */
        "je .Lf208ed8_00209369\n"
        "subl $1, %eax\n" /* line 542 */
        "je .Lf208ed8_0020918b\n"
        "movl 8(%ebp), %edi\n" /* line 543 | cinfo, thiscoef */
        "movl (%edi), %eax\n" /* thiscoef */
        "movl $0x76, 0x14(%eax)\n"
        "movl (%edi), %eax\n" /* thiscoef */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* thiscoef */
        "calll *4(%eax)\n"
        ".Lf208ed8_0020918b:\n"
        "movl -0x14c(%ebp), %eax\n" /* line 544 | bits_left */
        "testl %eax, %eax\n"
        "jle .Lf208ed8_002094e4\n"
        "movl -0x150(%ebp), %eax\n" /* get_buffer */
        ".Lf208ed8_0020919f:\n"
        "subl $1, -0x14c(%ebp)\n" /* line 545 | bits_left */
        "movzbl -0x14c(%ebp), %ecx\n" /* bits_left */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf208ed8_0020942c\n"
        "movl -0x168(%ebp), %edi\n" /* p1, thiscoef */
        "movl %edi, -0x140(%ebp)\n" /* thiscoef */
        ".Lf208ed8_002091c3:\n"
        "movl 0x1756adf(%ebx), %eax\n" /* line 555 */
        "movl -0x160(%ebp), %edx\n" /* k */
        "leal (%eax, %edx, 4), %edi\n" /* thiscoef */
        "leal -0x2c(%ebp), %ecx\n" /* br_state */
        "movl %ecx, -0x170(%ebp)\n"
        "jmp .Lf208ed8_00209240\n"
        ".Lf208ed8_002091dd:\n"
        "movl -0x14c(%ebp), %eax\n" /* line 568 | bits_left */
        "testl %eax, %eax\n"
        "jle .Lf208ed8_00209398\n"
        "movl -0x150(%ebp), %eax\n" /* get_buffer */
        ".Lf208ed8_002091f1:\n"
        "subl $1, -0x14c(%ebp)\n" /* line 569 | bits_left */
        "movzbl -0x14c(%ebp), %ecx\n" /* bits_left */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf208ed8_00209228\n"
        "movzwl (%esi), %edx\n" /* line 570 */
        "movswl %dx, %eax\n"
        "testl %eax, -0x168(%ebp)\n" /* p1 */
        "jne .Lf208ed8_00209228\n"
        "testw %dx, %dx\n" /* line 571 */
        "js .Lf208ed8_0020943d\n"
        "movl -0x168(%ebp), %ecx\n" /* line 572 | p1 */
        "leal (%edx, %ecx), %eax\n"
        "movw %ax, (%esi)\n"
        ".Lf208ed8_00209228:\n"
        "addl $1, -0x160(%ebp)\n" /* line 581 | k */
        "addl $4, %edi\n" /* thiscoef */
        "movl -0x160(%ebp), %eax\n" /* line 582 | k */
        "cmpl %eax, -0x16c(%ebp)\n" /* Se */
        "jl .Lf208ed8_0020925a\n"
        ".Lf208ed8_00209240:\n"
        "movl (%edi), %eax\n" /* line 566 | thiscoef */
        "movl -0x154(%ebp), %edx\n" /* block */
        "leal (%edx, %eax, 2), %esi\n"
        "cmpw $0, (%esi)\n" /* line 567 */
        "jne .Lf208ed8_002091dd\n"
        "subl $1, -0x15c(%ebp)\n" /* line 578 | r */
        "jns .Lf208ed8_00209228\n"
        ".Lf208ed8_0020925a:\n"
        "movl -0x140(%ebp), %eax\n" /* line 583 */
        "testl %eax, %eax\n"
        "je .Lf208ed8_00209299\n"
        /* { scope 2 */
        "movl 0x1756adf(%ebx), %eax\n" /* line 584 | pos */
        "movl -0x160(%ebp), %edx\n" /* k */
        "movl (%eax, %edx, 4), %eax\n" /* pos */
        "movl -0x140(%ebp), %edi\n" /* line 586 | thiscoef */
        "movl -0x154(%ebp), %ecx\n" /* block */
        "movw %di, (%ecx, %eax, 2)\n" /* thiscoef */
        "movl -0x144(%ebp), %edx\n" /* line 588 | num_newnz */
        "movl %eax, -0x12c(%ebp, %edx, 4)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x144(%ebp)\n" /* num_newnz */
        /* } scope */
        ".Lf208ed8_00209299:\n"
        "addl $1, -0x160(%ebp)\n" /* line 537 | k */
        "movl -0x160(%ebp), %ecx\n" /* k */
        "cmpl %ecx, -0x16c(%ebp)\n" /* Se */
        "jge .Lf208ed8_002090d2\n"
        "movl 8(%ebp), %edi\n" /* cinfo, thiscoef */
        "movl 0x20(%edi), %edx\n" /* thiscoef */
        ".Lf208ed8_002092b8:\n"
        "movl $0, -0x158(%ebp)\n" /* line 614 | EOBRUN */
        "jmp .Lf208ed8_0020907f\n"
        /* { scope 2 */
        ".Lf208ed8_002092c7:\n"
        "movl 0x19c(%edi), %ecx\n" /* line 235 */
        "movl 0x10(%eax), %eax\n"
        "leal 7(%eax), %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "sarl $3, %eax\n"
        "addl %eax, 0x14(%ecx)\n"
        "movl -0x13c(%ebp), %ecx\n" /* line 236 */
        "movl $0, 0x10(%ecx)\n"
        "movl 0x19c(%edi), %eax\n" /* line 239 */
        "movl %edi, (%esp)\n"
        "calll *8(%eax)\n"
        "testb %al, %al\n"
        "je .Lf208ed8_00209493\n"
        "movl 8(%ebp), %eax\n" /* line 243 | cinfo */
        "movl 0x12c(%eax), %esi\n"
        "testl %esi, %esi\n"
        "jle .Lf208ed8_0020932d\n"
        "movl -0x13c(%ebp), %edx\n"
        "xorl %eax, %eax\n"
        ".Lf208ed8_00209315:\n"
        "movl $0, 0x18(%edx)\n" /* line 244 */
        "addl $1, %eax\n" /* line 243 */
        "addl $4, %edx\n"
        "movl 8(%ebp), %edi\n" /* cinfo */
        "cmpl 0x12c(%edi), %eax\n"
        "jl .Lf208ed8_00209315\n"
        ".Lf208ed8_0020932d:\n"
        "movl -0x13c(%ebp), %eax\n" /* line 246 */
        "movl $0, 0x14(%eax)\n"
        "movl 8(%ebp), %edx\n" /* line 249 | cinfo */
        "movl 0x104(%edx), %eax\n"
        "movl -0x13c(%ebp), %ecx\n"
        "movl %eax, 0x28(%ecx)\n"
        "movl 0x184(%edx), %esi\n" /* line 256 */
        "testl %esi, %esi\n"
        "jne .Lf208ed8_00208f45\n"
        "movb $0, 8(%ecx)\n" /* line 257 */
        "movl -0x13c(%ebp), %edi\n"
        "jmp .Lf208ed8_00208f69\n"
        /* } scope */
        ".Lf208ed8_00209369:\n"
        "cmpl $0xf, -0x15c(%ebp)\n" /* line 550 | r */
        "jne .Lf208ed8_0020953d\n"
        "movl $0, -0x140(%ebp)\n"
        "jmp .Lf208ed8_002091c3\n"
        /* { scope 2 */
        ".Lf208ed8_00209385:\n"
        "subl %edx, -0x14c(%ebp)\n" /* line 538 | bits_left */
        "movzbl 0x490(%eax, %ecx), %eax\n" /* nb */
        "jmp .Lf208ed8_00209156\n"
        /* } scope */
        ".Lf208ed8_00209398:\n"
        "movl $1, 0xc(%esp)\n" /* line 568 */
        "movl -0x14c(%ebp), %ecx\n" /* bits_left */
        "movl %ecx, 8(%esp)\n"
        "movl -0x150(%ebp), %eax\n" /* get_buffer */
        "movl %eax, 4(%esp)\n"
        "movl -0x170(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll jpeg_fill_bit_buffer\n"
        "testb %al, %al\n"
        "je .Lf208ed8_00209458\n"
        "movl -0x24(%ebp), %ecx\n"
        "movl %ecx, -0x150(%ebp)\n" /* get_buffer */
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, -0x14c(%ebp)\n" /* bits_left */
        "movl %ecx, %eax\n"
        "jmp .Lf208ed8_002091f1\n"
        /* { scope 2 */
        ".Lf208ed8_002093e3:\n"
        "movl $0, 0xc(%esp)\n" /* line 538 */
        "movl -0x14c(%ebp), %edx\n" /* bits_left */
        "movl %edx, 8(%esp)\n"
        "movl -0x150(%ebp), %ecx\n" /* get_buffer */
        "movl %ecx, 4(%esp)\n"
        "leal -0x2c(%ebp), %esi\n" /* br_state */
        "movl %esi, (%esp)\n"
        "calll jpeg_fill_bit_buffer\n"
        "testb %al, %al\n" /* nb */
        "je .Lf208ed8_00209458\n"
        "movl -0x24(%ebp), %edi\n" /* thiscoef */
        "movl %edi, -0x150(%ebp)\n" /* thiscoef, get_buffer */
        "movl -0x20(%ebp), %eax\n" /* nb */
        "movl %eax, -0x14c(%ebp)\n" /* nb, bits_left */
        "cmpl $7, %eax\n" /* nb */
        "jle .Lf208ed8_0020944e\n"
        "movl %eax, %ecx\n" /* nb */
        "jmp .Lf208ed8_002090e5\n"
        /* } scope */
        ".Lf208ed8_0020942c:\n"
        "movl -0x164(%ebp), %edi\n" /* line 555 | m1, thiscoef */
        "movl %edi, -0x140(%ebp)\n" /* thiscoef */
        "jmp .Lf208ed8_002091c3\n"
        ".Lf208ed8_0020943d:\n"
        "movl -0x164(%ebp), %ecx\n" /* line 574 | m1 */
        "leal (%edx, %ecx), %eax\n"
        "movw %ax, (%esi)\n"
        "jmp .Lf208ed8_00209228\n"
        /* { scope 2 */
        ".Lf208ed8_0020944e:\n"
        "movl $1, %eax\n" /* line 538 | nb */
        "jmp .Lf208ed8_00209112\n"
        /* } scope */
        ".Lf208ed8_00209458:\n"
        "movl -0x144(%ebp), %edx\n" /* line 629 | num_newnz */
        "testl %edx, %edx\n"
        "jle .Lf208ed8_00209493\n"
        "xorl %ecx, %ecx\n" /* line 625 */
        "movl -0x144(%ebp), %edi\n" /* num_newnz, thiscoef */
        "leal -0x12c(%ebp, %edi, 4), %edx\n"
        "movl $0xfffffffc, %esi\n"
        ".Lf208ed8_00209476:\n"
        "movl (%esi, %edx), %eax\n" /* line 630 */
        "movl -0x154(%ebp), %edi\n" /* block, thiscoef */
        "movw $0, (%edi, %eax, 2)\n" /* thiscoef */
        "addl $1, %ecx\n"
        "subl $4, %edx\n"
        "cmpl %ecx, -0x144(%ebp)\n" /* line 629 | num_newnz */
        "jne .Lf208ed8_00209476\n"
        ".Lf208ed8_00209493:\n"
        "xorl %eax, %eax\n"
        "addl $0x18c, %esp\n" /* line 633 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf208ed8_002094a0:\n"
        "movl $1, 0xc(%esp)\n" /* line 602 */
        "movl -0x14c(%ebp), %eax\n" /* bits_left */
        "movl %eax, 8(%esp)\n"
        "movl -0x150(%ebp), %edx\n" /* get_buffer */
        "movl %edx, 4(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* br_state */
        "movl %eax, (%esp)\n"
        "calll jpeg_fill_bit_buffer\n"
        "testb %al, %al\n"
        "je .Lf208ed8_00209458\n"
        "movl -0x24(%ebp), %ecx\n"
        "movl %ecx, -0x150(%ebp)\n" /* get_buffer */
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, -0x14c(%ebp)\n" /* bits_left */
        "movl %ecx, %eax\n"
        "jmp .Lf208ed8_00209023\n"
        ".Lf208ed8_002094e4:\n"
        "movl $1, 0xc(%esp)\n" /* line 544 */
        "movl -0x14c(%ebp), %eax\n" /* bits_left */
        "movl %eax, 8(%esp)\n"
        "movl -0x150(%ebp), %edx\n" /* get_buffer */
        "movl %edx, 4(%esp)\n"
        "leal -0x2c(%ebp), %esi\n" /* br_state */
        "movl %esi, (%esp)\n"
        "calll jpeg_fill_bit_buffer\n"
        "testb %al, %al\n"
        "je .Lf208ed8_00209458\n"
        "movl -0x24(%ebp), %ecx\n"
        "movl %ecx, -0x150(%ebp)\n" /* get_buffer */
        "movl -0x20(%ebp), %edi\n" /* thiscoef */
        "movl %edi, -0x14c(%ebp)\n" /* thiscoef, bits_left */
        "movl %ecx, %eax\n"
        "jmp .Lf208ed8_0020919f\n"
        ".Lf208ed8_0020952c:\n"
        "movl -0x164(%ebp), %ecx\n" /* line 608 | m1 */
        "leal (%edx, %ecx), %eax\n"
        "movw %ax, (%edi)\n" /* thiscoef */
        "jmp .Lf208ed8_0020905a\n"
        ".Lf208ed8_0020953d:\n"
        "movl $1, -0x158(%ebp)\n" /* line 551 | EOBRUN */
        "movzbl -0x15c(%ebp), %ecx\n" /* r */
        "shll %cl, -0x158(%ebp)\n" /* EOBRUN */
        "movl -0x15c(%ebp), %eax\n" /* line 552 | r */
        "testl %eax, %eax\n"
        "je .Lf208ed8_00209598\n"
        "movl -0x14c(%ebp), %edi\n" /* line 553 | bits_left, thiscoef */
        "cmpl %edi, -0x15c(%ebp)\n" /* thiscoef, r */
        "jg .Lf208ed8_002095b1\n"
        ".Lf208ed8_0020956c:\n"
        "movl -0x15c(%ebp), %eax\n" /* line 554 | r */
        "subl %eax, -0x14c(%ebp)\n" /* bits_left */
        "movl -0x150(%ebp), %eax\n" /* line 555 | get_buffer */
        "movzbl -0x14c(%ebp), %ecx\n" /* bits_left */
        "sarl %cl, %eax\n"
        "movl -0x158(%ebp), %edx\n" /* EOBRUN */
        "subl $1, %edx\n"
        "andl %edx, %eax\n"
        "addl %eax, -0x158(%ebp)\n" /* EOBRUN */
        ".Lf208ed8_00209598:\n"
        "movl -0x158(%ebp), %eax\n" /* line 593 | EOBRUN */
        "testl %eax, %eax\n"
        "jne .Lf208ed8_00208fe5\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl 0x20(%ecx), %edx\n"
        "jmp .Lf208ed8_0020907f\n"
        ".Lf208ed8_002095b1:\n"
        "movl -0x15c(%ebp), %eax\n" /* line 553 | r */
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* thiscoef */
        "movl -0x150(%ebp), %edx\n" /* get_buffer */
        "movl %edx, 4(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* br_state */
        "movl %eax, (%esp)\n"
        "calll jpeg_fill_bit_buffer\n"
        "testb %al, %al\n"
        "je .Lf208ed8_00209458\n"
        "movl -0x24(%ebp), %ecx\n"
        "movl %ecx, -0x150(%ebp)\n" /* get_buffer */
        "movl -0x20(%ebp), %edi\n" /* thiscoef */
        "movl %edi, -0x14c(%ebp)\n" /* thiscoef, bits_left */
        "jmp .Lf208ed8_0020956c\n"
    );
}

/* line 642 */
__attribute__((naked))
void jinit_phuff_decoder(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 642 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %edi\n" /* cinfo */
        "movl 4(%edi), %eax\n" /* line 647 | cinfo */
        "movl $0x40, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "movl %eax, 0x1a0(%edi)\n" /* line 650 | cinfo */
        "leal -0xad9(%ebx), %edx\n" /* line 651 */
        "movl %edx, (%eax)\n"
        "movl $4, %edx\n"
        ".Lf2095f3_0020962f:\n"
        "movl $0, 0x2c(%eax)\n" /* line 655 */
        "addl $4, %eax\n"
        "subl $1, %edx\n" /* line 654 */
        "jne .Lf2095f3_0020962f\n"
        "movl 4(%edi), %edx\n" /* line 659 | cinfo */
        "movl 0x2c(%edi), %eax\n" /* cinfo */
        "shll $8, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *(%edx)\n"
        "movl %eax, 0x94(%edi)\n" /* cinfo */
        "movl 0x2c(%edi), %esi\n" /* line 663 | cinfo, ci */
        "testl %esi, %esi\n" /* ci */
        "jle .Lf2095f3_00209689\n"
        "xorl %esi, %esi\n" /* ci */
        ".Lf2095f3_00209667:\n"
        "movl %eax, %edx\n"
        "movl $0x40, %ecx\n"
        ".Lf2095f3_0020966e:\n"
        "movl $0xffffffff, (%edx)\n" /* line 665 */
        "addl $4, %edx\n"
        "subl $1, %ecx\n" /* line 664 */
        "jne .Lf2095f3_0020966e\n"
        "addl $1, %esi\n" /* line 663 | ci */
        "addl $0x100, %eax\n"
        "cmpl 0x2c(%edi), %esi\n" /* cinfo, ci */
        "jl .Lf2095f3_00209667\n"
        ".Lf2095f3_00209689:\n"
        "addl $0x1c, %esp\n" /* line 666 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 287 */
static __attribute__((naked))
boolean decode_mcu_DC_first(j_decompress_ptr cinfo, JBLOCKROW *MCU_data)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 287 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %eax\n" /* line 288 | cinfo */
        "movl 0x1a0(%eax), %eax\n"
        "movl %eax, -0x60(%ebp)\n" /* entropy */
        "movl 8(%ebp), %edx\n" /* line 289 | cinfo */
        "movl 0x180(%edx), %edx\n"
        "movl %edx, -0x5c(%ebp)\n" /* Al */
        "movl 8(%ebp), %ecx\n" /* line 299 | cinfo */
        "movl 0x104(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf209691_002096d2\n"
        "movl 0x28(%eax), %edi\n" /* line 300 | bits_left */
        "testl %edi, %edi\n" /* bits_left */
        "je .Lf209691_00209908\n"
        ".Lf209691_002096cf:\n"
        "movl -0x60(%ebp), %eax\n" /* entropy */
        ".Lf209691_002096d2:\n"
        "cmpb $0, 8(%eax)\n" /* line 308 */
        "jne .Lf209691_00209870\n"
        "movl 8(%ebp), %edx\n" /* line 311 | cinfo */
        "movl %edx, -0x1c(%ebp)\n"
        "movl 0x20(%edx), %edx\n"
        "movl (%edx), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* br_state */
        "movl 4(%edx), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl -0x60(%ebp), %eax\n" /* entropy */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0x50(%ebp)\n" /* get_buffer */
        "movl -0x60(%ebp), %ecx\n" /* entropy */
        "movl 0x10(%ecx), %edi\n" /* bits_left */
        "movl 0x14(%ecx), %eax\n" /* line 312 */
        "movl %eax, -0x40(%ebp)\n" /* state */
        "movl 0x18(%ecx), %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl 0x1c(%ecx), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl 0x20(%ecx), %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl 0x24(%ecx), %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* line 316 | cinfo */
        "movl 0x148(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lf209691_00209832\n"
        "movl $1, -0x4c(%ebp)\n"
        "addl $0x14c, %eax\n"
        "movl %eax, -0x68(%ebp)\n"
        ".Lf209691_0020973d:\n"
        "movl -0x4c(%ebp), %edx\n" /* line 317 */
        "movl 0xc(%ebp), %ecx\n" /* MCU_data */
        "movl -4(%ecx, %edx, 4), %edx\n"
        "movl %edx, -0x54(%ebp)\n" /* block */
        "movl -0x68(%ebp), %ecx\n" /* line 318 */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x58(%ebp)\n" /* ci */
        "movl 8(%ebp), %edx\n" /* line 320 | cinfo */
        "movl 0x130(%edx, %ecx, 4), %eax\n"
        "movl 0x14(%eax), %eax\n"
        "movl -0x60(%ebp), %ecx\n" /* entropy */
        "movl 0x2c(%ecx, %eax, 4), %esi\n" /* tbl */
        /* { scope 2 */
        "cmpl $7, %edi\n" /* line 325 | bits_left */
        "jle .Lf209691_00209890\n"
        "movl -0x50(%ebp), %eax\n" /* get_buffer, nb */
        ".Lf209691_00209772:\n"
        "leal -8(%edi), %ecx\n" /* bits_left */
        "sarl %cl, %eax\n" /* nb */
        "andl $0xff, %eax\n" /* nb */
        "movl 0x90(%esi, %eax, 4), %edx\n" /* tbl */
        "testl %edx, %edx\n"
        "jne .Lf209691_00209881\n"
        "movl $9, %eax\n" /* nb */
        "leal -0x2c(%ebp), %edx\n" /* br_state */
        "movl %edx, -0x64(%ebp)\n"
        ".Lf209691_00209796:\n"
        "movl %eax, 0x10(%esp)\n" /* nb */
        "movl %esi, 0xc(%esp)\n" /* tbl */
        "movl %edi, 8(%esp)\n" /* bits_left */
        "movl -0x50(%ebp), %ecx\n" /* get_buffer */
        "movl %ecx, 4(%esp)\n"
        "movl -0x64(%ebp), %eax\n" /* nb */
        "movl %eax, (%esp)\n" /* nb */
        "calll jpeg_huff_decode\n"
        "movl %eax, %esi\n" /* nb, tbl */
        "testl %eax, %eax\n" /* nb */
        "js .Lf209691_0020999d\n"
        "movl -0x24(%ebp), %edx\n"
        "movl %edx, -0x50(%ebp)\n" /* get_buffer */
        "movl -0x20(%ebp), %edi\n" /* bits_left */
        /* } scope */
        ".Lf209691_002097c7:\n"
        "testl %esi, %esi\n" /* line 326 | tbl */
        "je .Lf209691_002097fc\n"
        "cmpl %esi, %edi\n" /* line 327 | tbl, bits_left */
        "jl .Lf209691_002098ce\n"
        "movl -0x50(%ebp), %edx\n" /* get_buffer */
        ".Lf209691_002097d6:\n"
        "subl %esi, %edi\n" /* line 328 | tbl, bits_left */
        "movl %edi, %ecx\n" /* bits_left */
        "sarl %cl, %edx\n"
        "movl $1, %eax\n"
        "movl %esi, %ecx\n" /* tbl */
        "shll %cl, %eax\n"
        "subl $1, %eax\n"
        "andl %eax, %edx\n"
        "cmpl 0xfde81(%ebx, %esi, 4), %edx\n" /* line 329 */
        "jge .Lf209691_002097fa\n"
        "addl 0xfde41(%ebx, %esi, 4), %edx\n"
        ".Lf209691_002097fa:\n"
        "movl %edx, %esi\n" /* tbl */
        ".Lf209691_002097fc:\n"
        "movl %esi, %eax\n" /* line 333 | tbl */
        "movl -0x58(%ebp), %edx\n" /* ci */
        "addl -0x3c(%ebp, %edx, 4), %eax\n"
        "movl %eax, -0x3c(%ebp, %edx, 4)\n" /* line 334 */
        "movzbl -0x5c(%ebp), %ecx\n" /* line 336 | Al */
        "shll %cl, %eax\n"
        "movl -0x54(%ebp), %edx\n" /* block */
        "movw %ax, (%edx)\n"
        "movl -0x4c(%ebp), %eax\n"
        "addl $1, -0x4c(%ebp)\n"
        "addl $4, -0x68(%ebp)\n"
        "movl 8(%ebp), %ecx\n" /* line 316 | cinfo */
        "cmpl 0x148(%ecx), %eax\n"
        "jl .Lf209691_0020973d\n"
        "movl 0x20(%ecx), %edx\n"
        ".Lf209691_00209832:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 340 | br_state */
        "movl %eax, (%edx)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 0x20(%eax), %edx\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl -0x50(%ebp), %ecx\n" /* get_buffer */
        "movl -0x60(%ebp), %edx\n" /* entropy */
        "movl %ecx, 0xc(%edx)\n"
        "movl %edi, 0x10(%edx)\n" /* bits_left */
        "movl -0x40(%ebp), %eax\n" /* line 341 | state */
        "movl %eax, 0x14(%edx)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 0x1c(%edx)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, 0x20(%edx)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 0x24(%edx)\n"
        "movl -0x60(%ebp), %eax\n" /* entropy */
        ".Lf209691_00209870:\n"
        "subl $1, 0x28(%eax)\n" /* line 345 */
        "movl $1, %eax\n"
        "addl $0x7c, %esp\n" /* line 348 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2 */
        ".Lf209691_00209881:\n"
        "subl %edx, %edi\n" /* line 325 | bits_left */
        "movzbl 0x490(%eax, %esi), %esi\n" /* tbl */
        "jmp .Lf209691_002097c7\n"
        ".Lf209691_00209890:\n"
        "movl $0, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* bits_left */
        "movl -0x50(%ebp), %eax\n" /* get_buffer, nb */
        "movl %eax, 4(%esp)\n" /* nb */
        "leal -0x2c(%ebp), %edx\n" /* br_state */
        "movl %edx, -0x64(%ebp)\n"
        "movl %edx, (%esp)\n"
        "calll jpeg_fill_bit_buffer\n"
        "testb %al, %al\n" /* nb */
        "je .Lf209691_0020999d\n"
        "movl -0x24(%ebp), %ecx\n"
        "movl %ecx, -0x50(%ebp)\n" /* get_buffer */
        "movl -0x20(%ebp), %edi\n" /* bits_left */
        "cmpl $7, %edi\n" /* bits_left */
        "jle .Lf209691_002098fe\n"
        "movl %ecx, %eax\n" /* nb */
        "jmp .Lf209691_00209772\n"
        /* } scope */
        ".Lf209691_002098ce:\n"
        "movl %esi, 0xc(%esp)\n" /* line 327 | tbl */
        "movl %edi, 8(%esp)\n" /* bits_left */
        "movl -0x50(%ebp), %ecx\n" /* get_buffer */
        "movl %ecx, 4(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* br_state */
        "movl %eax, (%esp)\n"
        "calll jpeg_fill_bit_buffer\n"
        "testb %al, %al\n"
        "je .Lf209691_0020999d\n"
        "movl -0x24(%ebp), %edx\n"
        "movl %edx, -0x50(%ebp)\n" /* get_buffer */
        "movl -0x20(%ebp), %edi\n" /* bits_left */
        "jmp .Lf209691_002097d6\n"
        /* { scope 2 */
        ".Lf209691_002098fe:\n"
        "movl $1, %eax\n" /* line 325 | nb */
        "jmp .Lf209691_00209796\n"
        /* } scope */
        /* { scope 2 */
        ".Lf209691_00209908:\n"
        "movl 0x19c(%ecx), %ecx\n" /* line 235 */
        "movl -0x60(%ebp), %edx\n" /* entropy */
        "movl 0x10(%edx), %eax\n"
        "leal 7(%eax), %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "sarl $3, %eax\n"
        "addl %eax, 0x14(%ecx)\n"
        "movl -0x60(%ebp), %ecx\n" /* line 236 | entropy */
        "movl $0, 0x10(%ecx)\n"
        "movl 8(%ebp), %edx\n" /* line 239 | cinfo */
        "movl 0x19c(%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        "testb %al, %al\n"
        "je .Lf209691_0020999d\n"
        "movl 8(%ebp), %edx\n" /* line 243 | cinfo */
        "movl 0x12c(%edx), %edi\n"
        "testl %edi, %edi\n"
        "jle .Lf209691_0020996a\n"
        "movl -0x60(%ebp), %edx\n" /* entropy */
        "xorl %eax, %eax\n"
        ".Lf209691_00209952:\n"
        "movl $0, 0x18(%edx)\n" /* line 244 */
        "addl $1, %eax\n" /* line 243 */
        "addl $4, %edx\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "cmpl 0x12c(%ecx), %eax\n"
        "jl .Lf209691_00209952\n"
        ".Lf209691_0020996a:\n"
        "movl -0x60(%ebp), %eax\n" /* line 246 | entropy */
        "movl $0, 0x14(%eax)\n"
        "movl 8(%ebp), %edx\n" /* line 249 | cinfo */
        "movl 0x104(%edx), %eax\n"
        "movl -0x60(%ebp), %ecx\n" /* entropy */
        "movl %eax, 0x28(%ecx)\n"
        "movl 0x184(%edx), %esi\n" /* line 256 */
        "testl %esi, %esi\n"
        "jne .Lf209691_002096cf\n"
        "movb $0, 8(%ecx)\n" /* line 257 */
        "movl -0x60(%ebp), %eax\n" /* entropy */
        "jmp .Lf209691_002096d2\n"
        /* } scope */
        ".Lf209691_0020999d:\n"
        "xorl %eax, %eax\n" /* line 347 */
        "addl $0x7c, %esp\n" /* line 348 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 358 */
static __attribute__((naked))
boolean decode_mcu_AC_first(j_decompress_ptr cinfo, JBLOCKROW *MCU_data)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 358 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %eax\n" /* line 359 | cinfo */
        "movl 0x1a0(%eax), %eax\n"
        "movl %eax, -0x5c(%ebp)\n" /* entropy */
        "movl 8(%ebp), %edx\n" /* line 360 | cinfo */
        "movl 0x178(%edx), %edx\n"
        "movl %edx, -0x58(%ebp)\n" /* Se */
        "movl 8(%ebp), %ecx\n" /* line 361 | cinfo */
        "movl 0x180(%ecx), %ecx\n"
        "movl %ecx, -0x54(%ebp)\n" /* Al */
        "movl 8(%ebp), %edi\n" /* line 369 | cinfo, EOBRUN */
        "movl 0x104(%edi), %ecx\n" /* EOBRUN */
        "testl %ecx, %ecx\n"
        "je .Lf2099a7_00209a1e\n"
        "movl 0x28(%eax), %edx\n" /* line 370 */
        "testl %edx, %edx\n"
        "je .Lf2099a7_00209bd4\n"
        ".Lf2099a7_002099f1:\n"
        "movl -0x5c(%ebp), %edi\n" /* entropy, EOBRUN */
        "cmpb $0, 8(%edi)\n" /* line 378 | EOBRUN */
        "jne .Lf2099a7_00209a26\n"
        ".Lf2099a7_002099fa:\n"
        "movl 0x14(%edi), %eax\n" /* line 383 | EOBRUN */
        "testl %eax, %eax\n" /* line 387 */
        "je .Lf2099a7_00209a2a\n"
        "leal -1(%eax), %ecx\n" /* line 388 */
        ".Lf2099a7_00209a04:\n"
        "movl -0x5c(%ebp), %edi\n" /* line 425 | entropy, EOBRUN */
        "movl %ecx, 0x14(%edi)\n" /* EOBRUN */
        "movl -0x5c(%ebp), %eax\n" /* entropy */
        ".Lf2099a7_00209a0d:\n"
        "subl $1, 0x28(%eax)\n" /* line 429 */
        "movl $1, %eax\n"
        ".Lf2099a7_00209a16:\n"
        "addl $0x7c, %esp\n" /* line 432 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2099a7_00209a1e:\n"
        "movl %eax, %edi\n" /* EOBRUN */
        ".Lf2099a7_00209a20:\n"
        "cmpb $0, 8(%edi)\n" /* line 378 | EOBRUN */
        "je .Lf2099a7_002099fa\n"
        ".Lf2099a7_00209a26:\n"
        "movl %edi, %eax\n" /* EOBRUN */
        "jmp .Lf2099a7_00209a0d\n"
        ".Lf2099a7_00209a2a:\n"
        "movl 8(%ebp), %eax\n" /* line 390 | cinfo */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0x20(%eax), %edx\n"
        "movl (%edx), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* br_state */
        "movl 4(%edx), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl -0x5c(%ebp), %ecx\n" /* entropy */
        "movl 0xc(%ecx), %ecx\n"
        "movl %ecx, -0x48(%ebp)\n" /* get_buffer */
        "movl -0x5c(%ebp), %edi\n" /* entropy, EOBRUN */
        "movl 0x10(%edi), %esi\n" /* EOBRUN, bits_left */
        "movl 0xc(%ebp), %eax\n" /* line 391 | MCU_data */
        "movl (%eax), %eax\n"
        "movl %eax, -0x4c(%ebp)\n" /* block */
        "movl 0x3c(%edi), %ecx\n" /* line 392 | EOBRUN */
        "movl %ecx, -0x44(%ebp)\n" /* tbl */
        "movl 8(%ebp), %edi\n" /* line 394 | cinfo, EOBRUN */
        "movl 0x174(%edi), %edi\n" /* EOBRUN */
        "movl %edi, -0x3c(%ebp)\n" /* EOBRUN */
        "cmpl %edi, -0x58(%ebp)\n" /* EOBRUN, Se */
        "jge .Lf2099a7_00209af7\n"
        ".Lf2099a7_00209a70:\n"
        "xorl %ecx, %ecx\n"
        ".Lf2099a7_00209a72:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 421 | br_state */
        "movl %eax, (%edx)\n"
        "movl 8(%ebp), %edi\n" /* cinfo, EOBRUN */
        "movl 0x20(%edi), %edx\n" /* EOBRUN */
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl -0x48(%ebp), %edx\n" /* get_buffer */
        "movl -0x5c(%ebp), %eax\n" /* entropy */
        "movl %edx, 0xc(%eax)\n"
        "movl %esi, 0x10(%eax)\n" /* bits_left */
        "jmp .Lf2099a7_00209a04\n"
        ".Lf2099a7_00209a94:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 399 */
        "addl -0x40(%ebp), %eax\n"
        "movl %eax, -0x50(%ebp)\n" /* k */
        "cmpl %edi, %esi\n" /* line 400 | EOBRUN, bits_left */
        "jl .Lf2099a7_00209c6e\n"
        "movl -0x48(%ebp), %edx\n" /* get_buffer */
        ".Lf2099a7_00209aa8:\n"
        "subl %edi, %esi\n" /* line 401 | EOBRUN, bits_left */
        "movl %esi, %ecx\n" /* bits_left */
        "sarl %cl, %edx\n"
        "movl $1, %eax\n"
        "movl %edi, %ecx\n" /* EOBRUN */
        "shll %cl, %eax\n"
        "subl $1, %eax\n"
        "andl %eax, %edx\n"
        "cmpl 0xfdb6b(%ebx, %edi, 4), %edx\n" /* line 402 */
        "jge .Lf2099a7_00209acc\n"
        "addl 0xfdb2b(%ebx, %edi, 4), %edx\n"
        ".Lf2099a7_00209acc:\n"
        "movl -0x50(%ebp), %edi\n" /* line 404 | k, EOBRUN */
        "movl 0x1756013(%ebx), %ecx\n"
        "movl (%ecx, %edi, 4), %eax\n"
        "movzbl -0x54(%ebp), %ecx\n" /* Al */
        "shll %cl, %edx\n"
        "movl -0x4c(%ebp), %edi\n" /* block, EOBRUN */
        "movw %dx, (%edi, %eax, 2)\n" /* EOBRUN */
        "movl -0x50(%ebp), %eax\n" /* k */
        ".Lf2099a7_00209ae8:\n"
        "addl $1, %eax\n" /* line 394 */
        "movl %eax, -0x3c(%ebp)\n"
        "cmpl %eax, -0x58(%ebp)\n" /* Se */
        "jl .Lf2099a7_00209ca3\n"
        /* { scope 2 */
        ".Lf2099a7_00209af7:\n"
        "cmpl $7, %esi\n" /* line 395 | bits_left */
        "jle .Lf2099a7_00209b8c\n"
        "movl -0x48(%ebp), %eax\n" /* get_buffer, nb */
        ".Lf2099a7_00209b03:\n"
        "leal -8(%esi), %ecx\n" /* bits_left */
        "sarl %cl, %eax\n" /* nb */
        "andl $0xff, %eax\n" /* nb */
        "movl -0x44(%ebp), %edi\n" /* tbl, EOBRUN */
        "movl 0x90(%edi, %eax, 4), %edx\n" /* EOBRUN */
        "testl %edx, %edx\n"
        "jne .Lf2099a7_00209b80\n"
        "movl $9, %eax\n" /* nb */
        "leal -0x2c(%ebp), %edx\n" /* br_state */
        "movl %edx, -0x60(%ebp)\n"
        ".Lf2099a7_00209b26:\n"
        "movl %eax, 0x10(%esp)\n" /* nb */
        "movl -0x44(%ebp), %edi\n" /* tbl, EOBRUN */
        "movl %edi, 0xc(%esp)\n" /* EOBRUN */
        "movl %esi, 8(%esp)\n" /* bits_left */
        "movl -0x48(%ebp), %eax\n" /* get_buffer, nb */
        "movl %eax, 4(%esp)\n" /* nb */
        "movl %edx, (%esp)\n"
        "calll jpeg_huff_decode\n"
        "testl %eax, %eax\n" /* nb */
        "js .Lf2099a7_00209c9c\n"
        "movl -0x24(%ebp), %ecx\n"
        "movl %ecx, -0x48(%ebp)\n" /* get_buffer */
        "movl -0x20(%ebp), %esi\n" /* bits_left */
        /* } scope */
        ".Lf2099a7_00209b55:\n"
        "movl %eax, %edi\n" /* line 396 | EOBRUN */
        "sarl $4, %edi\n" /* EOBRUN */
        "movl %edi, -0x40(%ebp)\n" /* EOBRUN */
        "movl %eax, %edi\n" /* line 398 | EOBRUN */
        "andl $0xf, %edi\n" /* EOBRUN */
        "jne .Lf2099a7_00209a94\n"
        "cmpl $0xf, -0x40(%ebp)\n" /* line 406 */
        "jne .Lf2099a7_00209cae\n"
        "movl -0x3c(%ebp), %eax\n" /* line 407 */
        "addl $0xf, %eax\n"
        "movl %eax, -0x50(%ebp)\n" /* k */
        "jmp .Lf2099a7_00209ae8\n"
        /* { scope 2 */
        ".Lf2099a7_00209b80:\n"
        "subl %edx, %esi\n" /* line 395 | bits_left */
        "movzbl 0x490(%eax, %edi), %eax\n" /* nb */
        "jmp .Lf2099a7_00209b55\n"
        ".Lf2099a7_00209b8c:\n"
        "movl $0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* bits_left */
        "movl -0x48(%ebp), %eax\n" /* get_buffer, nb */
        "movl %eax, 4(%esp)\n" /* nb */
        "leal -0x2c(%ebp), %edx\n" /* br_state */
        "movl %edx, -0x60(%ebp)\n"
        "movl %edx, (%esp)\n"
        "calll jpeg_fill_bit_buffer\n"
        "testb %al, %al\n" /* nb */
        "je .Lf2099a7_00209c9c\n"
        "movl -0x24(%ebp), %ecx\n"
        "movl %ecx, -0x48(%ebp)\n" /* get_buffer */
        "movl -0x20(%ebp), %esi\n" /* bits_left */
        "cmpl $7, %esi\n" /* bits_left */
        "jg .Lf2099a7_00209c67\n"
        "movl $1, %eax\n" /* nb */
        "movl -0x60(%ebp), %edx\n"
        "jmp .Lf2099a7_00209b26\n"
        /* } scope */
        /* { scope 2 */
        ".Lf2099a7_00209bd4:\n"
        "movl 0x19c(%edi), %ecx\n" /* line 235 */
        "movl 0x10(%eax), %eax\n"
        "leal 7(%eax), %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "sarl $3, %eax\n"
        "addl %eax, 0x14(%ecx)\n"
        "movl -0x5c(%ebp), %ecx\n" /* line 236 | entropy */
        "movl $0, 0x10(%ecx)\n"
        "movl 0x19c(%edi), %eax\n" /* line 239 */
        "movl %edi, (%esp)\n"
        "calll *8(%eax)\n"
        "testb %al, %al\n"
        "je .Lf2099a7_00209c9c\n"
        "movl 8(%ebp), %edx\n" /* line 243 | cinfo */
        "movl 0x12c(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lf2099a7_00209c34\n"
        "movl -0x5c(%ebp), %edx\n" /* entropy */
        "xorl %eax, %eax\n"
        ".Lf2099a7_00209c1c:\n"
        "movl $0, 0x18(%edx)\n" /* line 244 */
        "addl $1, %eax\n" /* line 243 */
        "addl $4, %edx\n"
        "movl 8(%ebp), %edi\n" /* cinfo */
        "cmpl 0x12c(%edi), %eax\n"
        "jl .Lf2099a7_00209c1c\n"
        ".Lf2099a7_00209c34:\n"
        "movl -0x5c(%ebp), %eax\n" /* line 246 | entropy */
        "movl $0, 0x14(%eax)\n"
        "movl 8(%ebp), %edx\n" /* line 249 | cinfo */
        "movl 0x104(%edx), %eax\n"
        "movl -0x5c(%ebp), %ecx\n" /* entropy */
        "movl %eax, 0x28(%ecx)\n"
        "movl 0x184(%edx), %eax\n" /* line 256 */
        "testl %eax, %eax\n"
        "jne .Lf2099a7_002099f1\n"
        "movb $0, 8(%ecx)\n" /* line 257 */
        "movl -0x5c(%ebp), %edi\n" /* entropy */
        "jmp .Lf2099a7_00209a20\n"
        ".Lf2099a7_00209c67:\n"
        "movl %ecx, %eax\n"
        "jmp .Lf2099a7_00209b03\n"
        /* } scope */
        ".Lf2099a7_00209c6e:\n"
        "movl %edi, 0xc(%esp)\n" /* line 400 | EOBRUN */
        "movl %esi, 8(%esp)\n" /* bits_left */
        "movl -0x48(%ebp), %edx\n" /* get_buffer */
        "movl %edx, 4(%esp)\n"
        "leal -0x2c(%ebp), %ecx\n" /* br_state */
        "movl %ecx, (%esp)\n"
        "calll jpeg_fill_bit_buffer\n"
        "testb %al, %al\n"
        "je .Lf2099a7_00209c9c\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, -0x48(%ebp)\n" /* get_buffer */
        "movl -0x20(%ebp), %esi\n" /* bits_left */
        "movl %eax, %edx\n"
        "jmp .Lf2099a7_00209aa8\n"
        ".Lf2099a7_00209c9c:\n"
        "xorl %eax, %eax\n" /* line 431 */
        "jmp .Lf2099a7_00209a16\n"
        ".Lf2099a7_00209ca3:\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl 0x20(%ecx), %edx\n"
        "jmp .Lf2099a7_00209a70\n"
        ".Lf2099a7_00209cae:\n"
        "movl $1, %edi\n" /* line 409 | EOBRUN */
        "movzbl -0x40(%ebp), %ecx\n"
        "shll %cl, %edi\n" /* EOBRUN */
        "movl -0x40(%ebp), %eax\n" /* line 410 */
        "testl %eax, %eax\n"
        "je .Lf2099a7_00209cd6\n"
        "cmpl %esi, -0x40(%ebp)\n" /* line 411 | bits_left */
        "jg .Lf2099a7_00209ce4\n"
        "movl -0x48(%ebp), %eax\n" /* get_buffer */
        ".Lf2099a7_00209cc8:\n"
        "subl -0x40(%ebp), %esi\n" /* line 412 | bits_left */
        "movl %esi, %ecx\n" /* line 413 | bits_left */
        "sarl %cl, %eax\n"
        "leal -1(%edi), %edx\n" /* EOBRUN */
        "andl %edx, %eax\n"
        "addl %eax, %edi\n" /* EOBRUN */
        ".Lf2099a7_00209cd6:\n"
        "leal -1(%edi), %ecx\n" /* line 415 | EOBRUN */
        "movl 8(%ebp), %edi\n" /* cinfo, EOBRUN */
        "movl 0x20(%edi), %edx\n" /* EOBRUN */
        "jmp .Lf2099a7_00209a72\n"
        ".Lf2099a7_00209ce4:\n"
        "movl -0x40(%ebp), %eax\n" /* line 411 */
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* bits_left */
        "movl -0x48(%ebp), %edx\n" /* get_buffer */
        "movl %edx, 4(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* br_state */
        "movl %eax, (%esp)\n"
        "calll jpeg_fill_bit_buffer\n"
        "testb %al, %al\n"
        "je .Lf2099a7_00209c9c\n"
        "movl -0x24(%ebp), %ecx\n"
        "movl %ecx, -0x48(%ebp)\n" /* get_buffer */
        "movl -0x20(%ebp), %esi\n" /* bits_left */
        "movl %ecx, %eax\n"
        "jmp .Lf2099a7_00209cc8\n"
    );
}

/* line 443 */
static __attribute__((naked))
boolean decode_mcu_DC_refine(j_decompress_ptr cinfo, JBLOCKROW *MCU_data)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 443 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x40, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 444 | cinfo */
        "movl 0x1a0(%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 445 | cinfo */
        "movl 0x180(%edx), %ecx\n"
        "movl $1, -0x34(%ebp)\n" /* p1 */
        "shll %cl, -0x34(%ebp)\n" /* p1 */
        "movl 0x104(%edx), %esi\n" /* line 451 | blkn */
        "testl %esi, %esi\n" /* blkn */
        "je .Lf209d12_00209d53\n"
        "movl 0x28(%eax), %ecx\n" /* line 452 */
        "testl %ecx, %ecx\n"
        "je .Lf209d12_00209e0b\n"
        ".Lf209d12_00209d4e:\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "jmp .Lf209d12_00209d55\n"
        ".Lf209d12_00209d53:\n"
        "movl %edx, %eax\n"
        ".Lf209d12_00209d55:\n"
        "movl %eax, -0xc(%ebp)\n" /* line 462 */
        "movl 0x20(%eax), %edx\n"
        "movl (%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* br_state */
        "movl 4(%edx), %eax\n"
        "movl %eax, -0x18(%ebp)\n"
        "movl -0x2c(%ebp), %ecx\n"
        "movl 0xc(%ecx), %edi\n" /* get_buffer */
        "movl 0x10(%ecx), %ecx\n"
        "movl 8(%ebp), %eax\n" /* line 466 | cinfo */
        "movl 0x148(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf209d12_00209db6\n"
        "xorl %esi, %esi\n" /* blkn */
        "leal -0x1c(%ebp), %edx\n" /* br_state */
        "movl %edx, -0x38(%ebp)\n"
        ".Lf209d12_00209d84:\n"
        "movl 0xc(%ebp), %eax\n" /* line 467 | MCU_data */
        "movl (%eax, %esi, 4), %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* block */
        "testl %ecx, %ecx\n" /* line 470 */
        "jle .Lf209d12_00209de0\n"
        ".Lf209d12_00209d91:\n"
        "subl $1, %ecx\n" /* line 471 */
        "movl %edi, %eax\n" /* get_buffer */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf209d12_00209da5\n"
        "movl -0x34(%ebp), %edx\n" /* line 472 | p1 */
        "movl -0x30(%ebp), %eax\n" /* block */
        "orw %dx, (%eax)\n"
        ".Lf209d12_00209da5:\n"
        "addl $1, %esi\n" /* line 466 | blkn */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "cmpl 0x148(%eax), %esi\n" /* blkn */
        "jl .Lf209d12_00209d84\n"
        "movl 0x20(%eax), %edx\n"
        ".Lf209d12_00209db6:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 477 | br_state */
        "movl %eax, (%edx)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 0x20(%eax), %edx\n"
        "movl -0x18(%ebp), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl -0x2c(%ebp), %edx\n"
        "movl %edi, 0xc(%edx)\n" /* get_buffer */
        "movl %ecx, 0x10(%edx)\n"
        "subl $1, 0x28(%edx)\n" /* line 480 */
        "movl $1, %eax\n"
        ".Lf209d12_00209dd9:\n"
        "addl $0x40, %esp\n" /* line 483 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf209d12_00209de0:\n"
        "movl $1, 0xc(%esp)\n" /* line 470 */
        "movl %ecx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* get_buffer */
        "movl -0x38(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll jpeg_fill_bit_buffer\n"
        "testb %al, %al\n"
        "je .Lf209d12_00209e9d\n"
        "movl -0x14(%ebp), %edi\n" /* get_buffer */
        "movl -0x10(%ebp), %ecx\n"
        "jmp .Lf209d12_00209d91\n"
        /* { scope 2 */
        ".Lf209d12_00209e0b:\n"
        "movl 0x19c(%edx), %ecx\n" /* line 235 */
        "movl 0x10(%eax), %eax\n"
        "leal 7(%eax), %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "sarl $3, %eax\n"
        "addl %eax, 0x14(%ecx)\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 236 */
        "movl $0, 0x10(%ecx)\n"
        "movl 8(%ebp), %edx\n" /* line 239 | cinfo */
        "movl 0x19c(%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        "testb %al, %al\n"
        "je .Lf209d12_00209e9d\n"
        "movl 8(%ebp), %ecx\n" /* line 243 | cinfo */
        "movl 0x12c(%ecx), %esi\n"
        "testl %esi, %esi\n"
        "jle .Lf209d12_00209e6a\n"
        "movl -0x2c(%ebp), %edx\n"
        "xorl %eax, %eax\n"
        ".Lf209d12_00209e52:\n"
        "movl $0, 0x18(%edx)\n" /* line 244 */
        "addl $1, %eax\n" /* line 243 */
        "addl $4, %edx\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "cmpl 0x12c(%ecx), %eax\n"
        "jl .Lf209d12_00209e52\n"
        ".Lf209d12_00209e6a:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 246 */
        "movl $0, 0x14(%eax)\n"
        "movl 8(%ebp), %edx\n" /* line 249 | cinfo */
        "movl 0x104(%edx), %eax\n"
        "movl -0x2c(%ebp), %ecx\n"
        "movl %eax, 0x28(%ecx)\n"
        "movl 0x184(%edx), %eax\n" /* line 256 */
        "testl %eax, %eax\n"
        "jne .Lf209d12_00209d4e\n"
        "movb $0, 8(%ecx)\n" /* line 257 */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "jmp .Lf209d12_00209d55\n"
        /* } scope */
        ".Lf209d12_00209e9d:\n"
        "xorl %eax, %eax\n" /* line 482 */
        "jmp .Lf209d12_00209dd9\n"
    );
}

