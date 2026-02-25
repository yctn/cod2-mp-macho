/* ASM dump from: r_xsurface_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_xsurface_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/consumedata.h"
 */

XSurface * XModelReadSurface(XModel *model, int *partBits, const byte * *pos, Alloc_t Alloc);

/* line 32 */
__attribute__((naked))
XSurface * XModelReadSurface(XModel *model, int *partBits, const byte * *pos, Alloc_t Alloc)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 32 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %esi\n" /* model */
        "movl 0x10(%ebp), %edi\n" /* pos */
        /* { scope 1: u */
        "movl $0x18, (%esp)\n" /* line 54 */
        "calll *0x14(%ebp)\n" /* Alloc */
        "movl %eax, -0x38(%ebp)\n" /* surface */
        "addl $0x18, 0x84(%esi)\n" /* line 55 | allocCount */
        "movl (%edi), %eax\n" /* line 57 | pos */
        "movzbl (%eax), %eax\n"
        "movl -0x38(%ebp), %edx\n" /* surface */
        "movb %al, (%edx)\n"
        "movl (%edi), %eax\n" /* line 58 | pos */
        "leal 1(%eax), %ecx\n"
        "movl %ecx, (%edi)\n" /* pos */
        /* { scope 2 */
        "movzwl 1(%eax), %edx\n" /* line 104 */
        "movw %dx, -0x1c(%ebp)\n" /* u */
        "leal 3(%eax), %ecx\n" /* line 105 */
        "movl %ecx, (%edi)\n" /* pos */
        /* } scope */
        "movl -0x38(%ebp), %ecx\n" /* line 60 | surface */
        "movw %dx, 2(%ecx)\n"
        /* { scope 2 */
        "movl (%edi), %eax\n" /* line 104 | pos */
        "movzwl (%eax), %edx\n"
        "movw %dx, -0x1c(%ebp)\n" /* u */
        "leal 2(%eax), %ecx\n" /* line 105 */
        "movl %ecx, (%edi)\n" /* pos */
        /* } scope */
        "movl -0x38(%ebp), %eax\n" /* line 61 | surface */
        "movw %dx, 4(%eax)\n"
        /* { scope 2 */
        "movl (%edi), %edx\n" /* line 104 | pos */
        "movzwl (%edx), %ecx\n"
        "movw %cx, -0x3e(%ebp)\n"
        "movw %cx, -0x1c(%ebp)\n" /* u */
        "leal 2(%edx), %ecx\n" /* line 105 */
        "movl %ecx, (%edi)\n" /* pos */
        "movswl -0x3e(%ebp), %ecx\n" /* line 106 */
        /* } scope */
        "cmpw $-1, -0x3e(%ebp)\n" /* line 65 */
        "je .Lfc78f8_000c7ce5\n"
        "movl %ecx, %eax\n" /* line 82 */
        "shll $6, %eax\n"
        "movl -0x38(%ebp), %edx\n" /* surface */
        "movw %ax, 6(%edx)\n"
        "movl %ecx, %edx\n" /* line 83 */
        "sarl $5, %edx\n"
        "andl $0x1f, %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "movl 0xc(%ebp), %ecx\n" /* partBits */
        "orl %eax, (%ecx, %edx, 4)\n"
        "movl -0x38(%ebp), %eax\n" /* line 85 | surface */
        "movswl 2(%eax), %ebx\n" /* size */
        "shll $6, %ebx\n" /* size */
        "movl %ebx, (%esp)\n" /* line 92 | size */
        "calll *0x14(%ebp)\n" /* Alloc */
        "addl %ebx, 0x84(%esi)\n" /* line 93 | size, allocCount */
        "movl -0x38(%ebp), %edx\n" /* line 95 | surface */
        "movl %eax, 0xc(%edx)\n"
        ".Lfc78f8_000c79b3:\n"
        "movl %eax, %esi\n" /* line 100 | allocCount */
        "movl -0x38(%ebp), %ecx\n" /* line 102 | surface */
        "cmpw $0, 2(%ecx)\n"
        "jg .Lfc78f8_000c7a34\n"
        ".Lfc78f8_000c79bf:\n"
        "movswl 4(%ecx), %eax\n" /* line 176 */
        "leal 1(%eax), %esi\n" /* allocCount */
        "andl $0xfffffffe, %esi\n" /* allocCount */
        "leal (%eax, %eax, 2), %eax\n" /* line 181 */
        "leal 6(%eax, %eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x14(%ebp)\n" /* Alloc */
        "movl -0x38(%ebp), %edx\n" /* surface */
        "movl %eax, 8(%edx)\n"
        "movl -0x38(%ebp), %ecx\n" /* line 194 | surface */
        "movswl 4(%ecx), %edx\n"
        "leal (%edx, %edx, 2), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lfc78f8_000c7cb5\n"
        "xorl %ebx, %ebx\n" /* size */
        ".Lfc78f8_000c79f0:\n"
        "cmpl %edx, %esi\n" /* line 197 | allocCount */
        "je .Lfc78f8_000c7a29\n"
        "movl -0x38(%ebp), %eax\n" /* line 200 | surface */
        "movl 8(%eax), %ecx\n"
        "leal (%ebx, %ebx), %eax\n" /* size */
        "movzwl -2(%ecx, %eax), %edx\n"
        "movw %dx, (%ecx, %eax)\n"
        "movl %eax, %ecx\n" /* line 201 */
        "movl -0x38(%ebp), %edx\n" /* surface */
        "addl 8(%edx), %ecx\n"
        "movzwl -2(%ecx), %edx\n"
        "movw %dx, 2(%ecx)\n"
        "movl -0x38(%ebp), %ecx\n" /* line 202 | surface */
        "addl 8(%ecx), %eax\n"
        "movzwl -2(%eax), %edx\n"
        "movw %dx, 4(%eax)\n"
        "addw $1, 4(%ecx)\n" /* line 203 */
        /* } scope */
        ".Lfc78f8_000c7a29:\n"
        "movl -0x38(%ebp), %eax\n" /* line 221 | surface */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: u */
        ".Lfc78f8_000c7a34:\n"
        "movl $0, -0x30(%ebp)\n" /* line 102 | j */
        /* { scope 2 */
        ".Lfc78f8_000c7a3b:\n"
        "movl (%edi), %edx\n" /* line 149 | pos */
        "movl (%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* u */
        "leal 4(%edx), %ecx\n" /* line 150 */
        "movl %ecx, (%edi)\n" /* pos */
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 104 | u */
        "movl %eax, (%esi)\n" /* allocCount */
        /* { scope 2 */
        "movl (%edi), %edx\n" /* line 149 | pos */
        "movl (%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* u */
        "leal 4(%edx), %ecx\n" /* line 150 */
        "movl %ecx, (%edi)\n" /* pos */
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 105 | u */
        "movl %eax, 4(%esi)\n" /* allocCount */
        /* { scope 2 */
        "movl (%edi), %edx\n" /* line 149 | pos */
        "movl (%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* u */
        "leal 4(%edx), %ecx\n" /* line 150 */
        "movl %ecx, (%edi)\n" /* pos */
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 106 | u */
        "movl %eax, 8(%esi)\n" /* allocCount */
        "movl (%edi), %eax\n" /* line 108 | pos */
        "movzbl (%eax), %eax\n"
        "movb %al, 0xc(%esi)\n" /* allocCount */
        "movl (%edi), %eax\n" /* line 109 | pos */
        "movzbl 1(%eax), %eax\n"
        "movb %al, 0xd(%esi)\n" /* allocCount */
        "movl (%edi), %eax\n" /* line 110 | pos */
        "movzbl 2(%eax), %eax\n"
        "movb %al, 0xe(%esi)\n" /* allocCount */
        "movl (%edi), %eax\n" /* line 111 | pos */
        "movzbl 3(%eax), %eax\n"
        "movb %al, 0xf(%esi)\n" /* allocCount */
        "movl (%edi), %edx\n" /* line 112 | pos */
        "leal 4(%edx), %ecx\n"
        "movl %ecx, (%edi)\n" /* pos */
        /* { scope 2 */
        "movl 4(%edx), %eax\n" /* line 149 */
        "movl %eax, -0x1c(%ebp)\n" /* u */
        "leal 8(%edx), %ecx\n" /* line 150 */
        "movl %ecx, (%edi)\n" /* pos */
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 114 | u */
        "movl %eax, 0x1c(%esi)\n" /* allocCount */
        /* { scope 2 */
        "movl (%edi), %edx\n" /* line 149 | pos */
        "movl (%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* u */
        "leal 4(%edx), %ecx\n" /* line 150 */
        "movl %ecx, (%edi)\n" /* pos */
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 115 | u */
        "movl %eax, 0x2c(%esi)\n" /* allocCount */
        /* { scope 2 */
        "movl (%edi), %edx\n" /* line 149 | pos */
        "movl (%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* u */
        "leal 4(%edx), %ecx\n" /* line 150 */
        "movl %ecx, (%edi)\n" /* pos */
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 117 | u */
        "movl %eax, 0x10(%esi)\n" /* allocCount */
        /* { scope 2 */
        "movl (%edi), %edx\n" /* line 149 | pos */
        "movl (%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* u */
        "leal 4(%edx), %ecx\n" /* line 150 */
        "movl %ecx, (%edi)\n" /* pos */
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 118 | u */
        "movl %eax, 0x14(%esi)\n" /* allocCount */
        /* { scope 2 */
        "movl (%edi), %edx\n" /* line 149 | pos */
        "movl (%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* u */
        "leal 4(%edx), %ecx\n" /* line 150 */
        "movl %ecx, (%edi)\n" /* pos */
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 119 | u */
        "movl %eax, 0x18(%esi)\n" /* allocCount */
        /* { scope 2 */
        "movl (%edi), %edx\n" /* line 149 | pos */
        "movl (%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* u */
        "leal 4(%edx), %ecx\n" /* line 150 */
        "movl %ecx, (%edi)\n" /* pos */
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 121 | u */
        "movl %eax, 0x20(%esi)\n" /* allocCount */
        /* { scope 2 */
        "movl (%edi), %edx\n" /* line 149 | pos */
        "movl (%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* u */
        "leal 4(%edx), %ecx\n" /* line 150 */
        "movl %ecx, (%edi)\n" /* pos */
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 122 | u */
        "movl %eax, 0x24(%esi)\n" /* allocCount */
        /* { scope 2 */
        "movl (%edi), %edx\n" /* line 149 | pos */
        "movl (%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* u */
        "leal 4(%edx), %ecx\n" /* line 150 */
        "movl %ecx, (%edi)\n" /* pos */
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 123 | u */
        "movl %eax, 0x28(%esi)\n" /* allocCount */
        "cmpw $-1, -0x3e(%ebp)\n" /* line 133 */
        "je .Lfc78f8_000c7b84\n"
        /* { scope 2 */
        "movl (%edi), %edx\n" /* line 149 | pos */
        "movl (%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* u */
        "leal 4(%edx), %ecx\n" /* line 150 */
        "movl %ecx, (%edi)\n" /* pos */
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 168 | u */
        "movl %eax, 0x30(%esi)\n" /* allocCount */
        /* { scope 2 */
        "movl (%edi), %edx\n" /* line 149 | pos */
        "movl (%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* u */
        "leal 4(%edx), %ecx\n" /* line 150 */
        "movl %ecx, (%edi)\n" /* pos */
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 169 | u */
        "movl %eax, 0x34(%esi)\n" /* allocCount */
        /* { scope 2 */
        "movl (%edi), %edx\n" /* line 149 | pos */
        "movl (%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* u */
        "leal 4(%edx), %ecx\n" /* line 150 */
        "movl %ecx, (%edi)\n" /* pos */
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 170 | u */
        "movl %eax, 0x38(%esi)\n" /* allocCount */
        ".Lfc78f8_000c7b66:\n"
        "addl $0x40, %esi\n" /* line 171 | allocCount */
        ".Lfc78f8_000c7b69:\n"
        "addl $1, -0x30(%ebp)\n" /* line 102 | j */
        "movl -0x38(%ebp), %edx\n" /* surface */
        "movswl 2(%edx), %eax\n"
        "cmpl -0x30(%ebp), %eax\n" /* j */
        "jg .Lfc78f8_000c7a3b\n"
        "movl %edx, %ecx\n"
        "jmp .Lfc78f8_000c79bf\n"
        ".Lfc78f8_000c7b84:\n"
        "movl (%edi), %eax\n" /* line 135 | pos */
        "movzbl (%eax), %edx\n"
        "movb %dl, -0x29(%ebp)\n" /* numWeights */
        "leal 1(%eax), %ecx\n" /* line 136 */
        "movl %ecx, (%edi)\n" /* pos */
        "movb %dl, 0x3c(%esi)\n" /* line 137 | allocCount */
        /* { scope 2 */
        "movl (%edi), %eax\n" /* line 104 | pos */
        "movswl (%eax), %edx\n"
        "movw %dx, -0x1c(%ebp)\n" /* u */
        "leal 2(%eax), %ecx\n" /* line 105 */
        "movl %ecx, (%edi)\n" /* pos */
        /* } scope */
        "movl %edx, %ebx\n" /* line 140 | size */
        "sarl $5, %ebx\n" /* size */
        "movl %edx, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "movl 0xc(%ebp), %ecx\n" /* partBits */
        "orl %eax, (%ecx, %ebx, 4)\n"
        "shll $6, %edx\n" /* line 142 */
        "movw %dx, 0x3e(%esi)\n" /* allocCount */
        /* { scope 2 */
        "movl (%edi), %edx\n" /* line 149 | pos */
        "movl (%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* u */
        "leal 4(%edx), %ecx\n" /* line 150 */
        "movl %ecx, (%edi)\n" /* pos */
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 145 | u */
        "movl %eax, 0x30(%esi)\n" /* allocCount */
        /* { scope 2 */
        "movl (%edi), %edx\n" /* line 149 | pos */
        "movl (%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* u */
        "leal 4(%edx), %ecx\n" /* line 150 */
        "movl %ecx, (%edi)\n" /* pos */
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 146 | u */
        "movl %eax, 0x34(%esi)\n" /* allocCount */
        /* { scope 2 */
        "movl (%edi), %edx\n" /* line 149 | pos */
        "movl (%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* u */
        "leal 4(%edx), %ecx\n" /* line 150 */
        "movl %ecx, (%edi)\n" /* pos */
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 147 | u */
        "movl %eax, 0x38(%esi)\n" /* allocCount */
        "cmpb $0, -0x29(%ebp)\n" /* line 149 | numWeights */
        "je .Lfc78f8_000c7b66\n"
        "movl (%edi), %eax\n" /* line 151 | pos */
        "movzbl (%eax), %eax\n"
        "movb %al, 0x3d(%esi)\n" /* allocCount */
        "movl (%edi), %ecx\n" /* line 152 | pos */
        "addl $1, %ecx\n"
        "movl %ecx, (%edi)\n" /* pos */
        "addl $0x40, %esi\n" /* line 153 | allocCount */
        "movzbl -0x29(%ebp), %eax\n" /* line 155 | numWeights */
        "movl %eax, -0x3c(%ebp)\n"
        "testl %eax, %eax\n"
        "jle .Lfc78f8_000c7b69\n"
        "movl $0, -0x34(%ebp)\n" /* i */
        "jmp .Lfc78f8_000c7c2c\n"
        ".Lfc78f8_000c7c2a:\n"
        "movl (%edi), %ecx\n" /* pos */
        /* { scope 2 */
        ".Lfc78f8_000c7c2c:\n"
        "movswl (%ecx), %edx\n" /* line 104 */
        "movw %dx, -0x1c(%ebp)\n" /* u */
        "addl $2, %ecx\n" /* line 105 */
        "movl %ecx, (%edi)\n" /* pos */
        /* } scope */
        "movl %edx, %ebx\n" /* line 19 */
        "sarl $5, %ebx\n"
        "movl %edx, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "movl 0xc(%ebp), %ecx\n" /* partBits */
        "orl %eax, (%ecx, %ebx, 4)\n"
        "shll $6, %edx\n" /* line 21 */
        "movw %dx, 0xc(%esi)\n"
        /* { scope 2 */
        "movl (%edi), %edx\n" /* line 149 | pos */
        "movl (%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* u */
        "leal 4(%edx), %ecx\n" /* line 150 */
        "movl %ecx, (%edi)\n" /* pos */
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 24 | u */
        "movl %eax, (%esi)\n"
        /* { scope 2 */
        "movl (%edi), %edx\n" /* line 149 | pos */
        "movl (%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* u */
        "leal 4(%edx), %ecx\n" /* line 150 */
        "movl %ecx, (%edi)\n" /* pos */
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 25 | u */
        "movl %eax, 4(%esi)\n"
        /* { scope 2 */
        "movl (%edi), %edx\n" /* line 149 | pos */
        "movl (%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* u */
        "leal 4(%edx), %ecx\n" /* line 150 */
        "movl %ecx, (%edi)\n" /* pos */
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 26 | u */
        "movl %eax, 8(%esi)\n"
        /* { scope 2 */
        "movl (%edi), %eax\n" /* line 119 | pos */
        "movzwl (%eax), %edx\n"
        "movw %dx, -0x1c(%ebp)\n" /* u */
        "leal 2(%eax), %ecx\n" /* line 120 */
        "movl %ecx, (%edi)\n" /* pos */
        /* } scope */
        "movw %dx, 0xe(%esi)\n" /* line 28 */
        "addl $0x10, %esi\n"
        "addl $1, -0x34(%ebp)\n" /* line 155 | i */
        "movl -0x34(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x3c(%ebp)\n"
        "jne .Lfc78f8_000c7c2a\n"
        "jmp .Lfc78f8_000c7b69\n"
        ".Lfc78f8_000c7cb5:\n"
        "xorl %ebx, %ebx\n" /* line 194 | size */
        ".Lfc78f8_000c7cb7:\n"
        "movl -0x38(%ebp), %eax\n" /* line 195 | surface */
        "movl 8(%eax), %ecx\n"
        /* { scope 2 */
        "movl (%edi), %eax\n" /* line 104 | pos */
        "movzwl (%eax), %edx\n"
        "movw %dx, -0x1c(%ebp)\n" /* u */
        "addl $2, %eax\n" /* line 105 */
        "movl %eax, (%edi)\n" /* pos */
        /* } scope */
        "movw %dx, (%ecx, %ebx, 2)\n" /* line 195 */
        "addl $1, %ebx\n" /* line 194 | size */
        "movl -0x38(%ebp), %ecx\n" /* surface */
        "movswl 4(%ecx), %edx\n"
        "leal (%edx, %edx, 2), %eax\n"
        "cmpl %ebx, %eax\n" /* size */
        "jg .Lfc78f8_000c7cb7\n"
        "jmp .Lfc78f8_000c79f0\n"
        /* { scope 2 */
        ".Lfc78f8_000c7ce5:\n"
        "movswl 2(%edx), %eax\n" /* line 104 */
        "movw %ax, -0x1c(%ebp)\n" /* u */
        "leal 4(%edx), %ecx\n" /* line 105 */
        "movl %ecx, (%edi)\n" /* pos */
        /* } scope */
        "movl -0x38(%ebp), %edx\n" /* line 69 | surface */
        "movw $0xffff, 6(%edx)\n"
        "movswl 2(%edx), %ebx\n" /* line 71 | size */
        "leal (%eax, %ebx, 4), %ebx\n" /* size */
        "shll $4, %ebx\n" /* size */
        "movl %ebx, (%esp)\n" /* line 72 | size */
        "calll *0x14(%ebp)\n" /* Alloc */
        "addl %ebx, 0x84(%esi)\n" /* line 73 | size, allocCount */
        "movl -0x38(%ebp), %ecx\n" /* line 75 | surface */
        "movl %eax, 0xc(%ecx)\n"
        "jmp .Lfc78f8_000c79b3\n"
    );
}

