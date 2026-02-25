/* ASM dump from: inffast.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/zlib/inffast.c */

#include "common_types.h"
#include "imports.h"

int inflate_fast(uInt bl, uInt bd, inflate_huft *tl, inflate_huft *td, inflate_blocks_statef *s, z_streamp z);

/* line 37 */
__attribute__((naked))
int inflate_fast(uInt bl, uInt bd, inflate_huft *tl, inflate_huft *td, inflate_blocks_statef *s, z_streamp z)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 37 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x38, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 0x1c(%ebp), %eax\n" /* line 53 | z */
        "movl (%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl 0x1c(%ebp), %edx\n" /* z */
        "movl 4(%edx), %edx\n"
        "movl %edx, -0x28(%ebp)\n"
        "movl 0x18(%ebp), %ecx\n" /* s */
        "movl 0x20(%ecx), %edi\n"
        "movl 0x1c(%ecx), %esi\n" /* e */
        "movl %esi, -0x24(%ebp)\n" /* e */
        "movl 0x34(%ecx), %eax\n"
        "movl %eax, -0x3c(%ebp)\n" /* q */
        "movl 0x30(%ecx), %eax\n"
        "cmpl %eax, -0x3c(%ebp)\n" /* q */
        "jae .Lf2125ec_00212998\n"
        "subl -0x3c(%ebp), %eax\n" /* q */
        "subl $1, %eax\n"
        "movl %eax, -0x38(%ebp)\n" /* m */
        ".Lf2125ec_00212632:\n"
        "movl 8(%ebp), %eax\n" /* line 56 | bl */
        "movl 0x174d3ca(%ebx), %esi\n" /* e */
        "movl (%esi, %eax, 4), %eax\n" /* e */
        "movl %eax, -0x34(%ebp)\n" /* ml */
        "movl 0xc(%ebp), %eax\n" /* line 57 | bd */
        "movl (%esi, %eax, 4), %eax\n" /* e */
        "movl %eax, -0x30(%ebp)\n" /* md */
        ".Lf2125ec_0021264a:\n"
        "cmpl $0x13, -0x24(%ebp)\n" /* line 62 */
        "jbe .Lf2125ec_00212742\n"
        "movl -0x34(%ebp), %eax\n" /* line 63 | ml */
        "andl %edi, %eax\n"
        "movl 0x10(%ebp), %esi\n" /* tl, e */
        "leal (%esi, %eax, 8), %edx\n" /* e */
        "movzbl (%edx), %eax\n"
        "movzbl %al, %esi\n" /* e */
        "testb %al, %al\n"
        "jne .Lf2125ec_002126e7\n"
        "movzbl 1(%edx), %ecx\n" /* line 65 */
        "shrl %cl, %edi\n"
        "subl %ecx, -0x24(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 69 */
        "movl -0x3c(%ebp), %edx\n" /* q */
        "movb %al, (%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x3c(%ebp)\n" /* q */
        "subl $1, -0x38(%ebp)\n" /* line 70 | m */
        ".Lf2125ec_00212684:\n"
        "cmpl $0x101, -0x38(%ebp)\n" /* line 180 | m */
        "jbe .Lf2125ec_00212693\n"
        "cmpl $9, -0x28(%ebp)\n"
        "ja .Lf2125ec_0021264a\n"
        ".Lf2125ec_00212693:\n"
        "movl 0x1c(%ebp), %ecx\n" /* line 183 | z */
        "movl 4(%ecx), %eax\n"
        "subl -0x28(%ebp), %eax\n"
        "movl -0x24(%ebp), %edx\n"
        "shrl $3, %edx\n"
        "cmpl %edx, %eax\n"
        "cmoval %edx, %eax\n"
        "movl -0x2c(%ebp), %ecx\n"
        "subl %eax, %ecx\n"
        "movl 0x18(%ebp), %esi\n" /* line 184 | s, e */
        "movl %edi, 0x20(%esi)\n" /* e */
        "leal (, %eax, 8), %edx\n"
        "subl %edx, -0x24(%ebp)\n"
        "movl -0x24(%ebp), %edx\n"
        "movl %edx, 0x1c(%esi)\n" /* e */
        "addl -0x28(%ebp), %eax\n"
        "movl 0x1c(%ebp), %esi\n" /* z, e */
        "movl %eax, 4(%esi)\n" /* e */
        "movl %ecx, %eax\n"
        "subl (%esi), %eax\n" /* e */
        "addl %eax, 8(%esi)\n" /* e */
        "movl %ecx, (%esi)\n" /* e */
        "movl -0x3c(%ebp), %edx\n" /* q */
        "movl 0x18(%ebp), %eax\n" /* s */
        "movl %edx, 0x34(%eax)\n"
        "xorl %eax, %eax\n"
        "addl $0x38, %esp\n" /* line 186 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2125ec_002126e7:\n"
        "movzbl 1(%edx), %ecx\n" /* line 74 */
        "shrl %cl, %edi\n"
        "subl %ecx, -0x24(%ebp)\n"
        "testl $0x10, %esi\n" /* line 75 | e */
        "jne .Lf2125ec_00212763\n"
        "testl $0x40, %esi\n" /* line 151 | e */
        "jne .Lf2125ec_00212938\n"
        "movl 4(%edx), %eax\n" /* line 153 */
        "leal (%edx, %eax, 8), %eax\n"
        "movl %edi, %edx\n" /* line 154 */
        "movl 0x174d3ca(%ebx), %ecx\n"
        "andl (%ecx, %esi, 4), %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "movzbl (%edx), %eax\n"
        "movzbl %al, %esi\n" /* e */
        "testb %al, %al\n"
        "jne .Lf2125ec_002126e7\n"
        "movzbl 1(%edx), %ecx\n" /* line 156 */
        "shrl %cl, %edi\n"
        "subl %ecx, -0x24(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 160 */
        "movl -0x3c(%ebp), %esi\n" /* q, e */
        "movb %al, (%esi)\n" /* e */
        "addl $1, %esi\n" /* e */
        "movl %esi, -0x3c(%ebp)\n" /* e, q */
        "subl $1, -0x38(%ebp)\n" /* line 161 | m */
        "jmp .Lf2125ec_00212684\n"
        ".Lf2125ec_00212742:\n"
        "subl $1, -0x28(%ebp)\n" /* line 62 */
        "movl -0x2c(%ebp), %edx\n"
        "movzbl (%edx), %eax\n"
        "movzbl -0x24(%ebp), %ecx\n"
        "shll %cl, %eax\n"
        "orl %eax, %edi\n"
        "addl $1, %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "addl $8, -0x24(%ebp)\n"
        "jmp .Lf2125ec_0021264a\n"
        ".Lf2125ec_00212763:\n"
        "movl %esi, %ecx\n" /* line 78 | e */
        "andl $0xf, %ecx\n"
        "movl 0x174d3ca(%ebx), %esi\n" /* line 79 | e */
        "movl (%esi, %ecx, 4), %eax\n" /* e */
        "andl %edi, %eax\n"
        "movl %eax, -0x14(%ebp)\n"
        "movl 4(%edx), %esi\n" /* e */
        "addl %esi, %eax\n" /* e */
        "movl %eax, -0x14(%ebp)\n"
        "movl %edi, %edx\n" /* line 80 */
        "shrl %cl, %edx\n"
        "movl -0x24(%ebp), %edi\n"
        "subl %ecx, %edi\n"
        "cmpl $0xe, %edi\n" /* line 84 */
        "ja .Lf2125ec_002127af\n"
        "movl -0x2c(%ebp), %esi\n" /* e */
        ".Lf2125ec_0021278f:\n"
        "movzbl (%esi), %eax\n" /* e */
        "movl %edi, %ecx\n"
        "shll %cl, %eax\n"
        "orl %eax, %edx\n"
        "addl $1, %esi\n" /* e */
        "addl $8, %edi\n"
        "cmpl $0xe, %edi\n"
        "jbe .Lf2125ec_0021278f\n"
        "movl -0x2c(%ebp), %eax\n"
        "addl %eax, -0x28(%ebp)\n"
        "subl %esi, -0x28(%ebp)\n" /* e */
        "movl %esi, -0x2c(%ebp)\n" /* e */
        ".Lf2125ec_002127af:\n"
        "movl -0x30(%ebp), %eax\n" /* line 85 | md */
        "andl %edx, %eax\n"
        "movl 0x14(%ebp), %ecx\n" /* td */
        "leal (%ecx, %eax, 8), %eax\n"
        "movl %eax, -0x18(%ebp)\n"
        "movzbl (%eax), %esi\n" /* e */
        "movzbl 1(%eax), %ecx\n" /* line 87 */
        "shrl %cl, %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "subl %ecx, %edi\n"
        "movl %edi, -0x20(%ebp)\n"
        "testl $0x10, %esi\n" /* line 88 | e */
        "je .Lf2125ec_002128ca\n"
        ".Lf2125ec_002127da:\n"
        "andl $0xf, %esi\n" /* line 91 | e */
        "cmpl -0x20(%ebp), %esi\n" /* line 92 | e */
        "jbe .Lf2125ec_00212809\n"
        "movl -0x2c(%ebp), %edx\n"
        ".Lf2125ec_002127e5:\n"
        "movzbl (%edx), %eax\n"
        "movzbl -0x20(%ebp), %ecx\n"
        "shll %cl, %eax\n"
        "orl %eax, -0x1c(%ebp)\n"
        "addl $1, %edx\n"
        "addl $8, -0x20(%ebp)\n"
        "cmpl -0x20(%ebp), %esi\n" /* e */
        "ja .Lf2125ec_002127e5\n"
        "movl -0x2c(%ebp), %eax\n"
        "addl %eax, -0x28(%ebp)\n"
        "subl %edx, -0x28(%ebp)\n"
        "movl %edx, -0x2c(%ebp)\n"
        ".Lf2125ec_00212809:\n"
        "movl -0x1c(%ebp), %edi\n" /* line 94 */
        "movl %esi, %ecx\n" /* e */
        "shrl %cl, %edi\n"
        "movl -0x20(%ebp), %eax\n"
        "subl %esi, %eax\n" /* e */
        "movl %eax, -0x24(%ebp)\n"
        "movl -0x14(%ebp), %edx\n" /* line 98 */
        "subl %edx, -0x38(%ebp)\n" /* m */
        "movl 0x174d3ca(%ebx), %ecx\n" /* line 99 */
        "movl (%ecx, %esi, 4), %ecx\n"
        "andl %ecx, -0x1c(%ebp)\n"
        "movl -0x18(%ebp), %esi\n" /* e */
        "movl 4(%esi), %esi\n" /* e */
        "addl %esi, -0x1c(%ebp)\n" /* e */
        "movl -0x3c(%ebp), %edx\n" /* q */
        "subl -0x1c(%ebp), %edx\n"
        "movl 0x18(%ebp), %ecx\n" /* line 100 | s */
        "movl 0x28(%ecx), %eax\n"
        "cmpl %eax, %edx\n"
        "jae .Lf2125ec_002129a8\n"
        "movl 0x2c(%ecx), %esi\n" /* line 103 | e */
        "movl %esi, %ecx\n" /* e */
        "subl %eax, %ecx\n"
        ".Lf2125ec_0021284e:\n"
        "addl %ecx, %edx\n"
        "cmpl %edx, %eax\n" /* line 104 */
        "ja .Lf2125ec_0021284e\n"
        "movl %esi, %eax\n" /* line 105 | e */
        "subl %edx, %eax\n"
        "cmpl %eax, -0x14(%ebp)\n" /* line 106 */
        "ja .Lf2125ec_002129e0\n"
        "movzbl (%edx), %eax\n" /* line 119 */
        "movl -0x3c(%ebp), %esi\n" /* q, e */
        "movb %al, (%esi)\n" /* e */
        "movzbl 1(%edx), %eax\n" /* line 120 */
        "movb %al, 1(%esi)\n" /* e */
        "addl $2, %edx\n"
        "leal 2(%esi), %ecx\n" /* e */
        "movl -0x14(%ebp), %eax\n"
        "leal -2(%eax, %ecx), %eax\n"
        "movl %eax, -0x3c(%ebp)\n" /* q */
        "movl %eax, %esi\n" /* e */
        ".Lf2125ec_00212882:\n"
        "movzbl (%edx), %eax\n" /* line 122 */
        "movb %al, (%ecx)\n"
        "addl $1, %ecx\n"
        "addl $1, %edx\n"
        "cmpl %ecx, %esi\n" /* line 123 | e */
        "jne .Lf2125ec_00212882\n"
        "jmp .Lf2125ec_00212684\n"
        ".Lf2125ec_00212896:\n"
        "movl -0x18(%ebp), %edx\n" /* line 138 */
        "movl 4(%edx), %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl -0x1c(%ebp), %edx\n" /* line 139 */
        "movl 0x174d3ca(%ebx), %ecx\n"
        "andl (%ecx, %esi, 4), %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "movl %edx, -0x18(%ebp)\n"
        "movzbl (%edx), %esi\n" /* e */
        "movzbl 1(%edx), %ecx\n" /* line 87 */
        "shrl %cl, -0x1c(%ebp)\n"
        "subl %ecx, -0x20(%ebp)\n"
        "testl $0x10, %esi\n" /* line 88 | e */
        "jne .Lf2125ec_002127da\n"
        ".Lf2125ec_002128ca:\n"
        "testl $0x40, %esi\n" /* line 136 | e */
        "je .Lf2125ec_00212896\n"
        "leal 0xa7fc2(%ebx), %eax\n" /* line 143 */
        "movl 0x1c(%ebp), %esi\n" /* z, e */
        "movl %eax, 0x18(%esi)\n" /* e */
        "movl 4(%esi), %eax\n" /* line 144 | e */
        "subl -0x28(%ebp), %eax\n"
        "movl -0x20(%ebp), %edx\n"
        "shrl $3, %edx\n"
        "cmpl %edx, %eax\n"
        "cmoval %edx, %eax\n"
        "movl -0x2c(%ebp), %ecx\n"
        "subl %eax, %ecx\n"
        "movl -0x1c(%ebp), %esi\n" /* line 145 | e */
        "movl 0x18(%ebp), %edx\n" /* s */
        "movl %esi, 0x20(%edx)\n" /* e */
        "leal (, %eax, 8), %edx\n"
        "subl %edx, -0x20(%ebp)\n"
        "movl -0x20(%ebp), %esi\n" /* e */
        "movl 0x18(%ebp), %edx\n" /* s */
        "movl %esi, 0x1c(%edx)\n" /* e */
        "addl -0x28(%ebp), %eax\n"
        "movl 0x1c(%ebp), %edx\n" /* z */
        "movl %eax, 4(%edx)\n"
        "movl %ecx, %eax\n"
        "subl (%edx), %eax\n"
        "addl %eax, 8(%edx)\n"
        "movl %ecx, (%edx)\n"
        "movl -0x3c(%ebp), %esi\n" /* q, e */
        "movl 0x18(%ebp), %ecx\n" /* s */
        "movl %esi, 0x34(%ecx)\n" /* e */
        "movl $0xfffffffd, %eax\n"
        "addl $0x38, %esp\n" /* line 186 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2125ec_00212938:\n"
        "andl $0x20, %esi\n" /* line 165 | e */
        "je .Lf2125ec_00212a2a\n"
        "movl 0x1c(%ebp), %edx\n" /* line 168 | z */
        "movl 4(%edx), %eax\n"
        "subl -0x28(%ebp), %eax\n"
        "movl -0x24(%ebp), %edx\n"
        "shrl $3, %edx\n"
        "cmpl %edx, %eax\n"
        "cmoval %edx, %eax\n"
        "movl -0x2c(%ebp), %ecx\n"
        "subl %eax, %ecx\n"
        "movl 0x18(%ebp), %esi\n" /* line 169 | s, e */
        "movl %edi, 0x20(%esi)\n" /* e */
        "leal (, %eax, 8), %edx\n"
        "subl %edx, -0x24(%ebp)\n"
        "movl -0x24(%ebp), %edx\n"
        "movl %edx, 0x1c(%esi)\n" /* e */
        "addl -0x28(%ebp), %eax\n"
        "movl 0x1c(%ebp), %esi\n" /* z, e */
        "movl %eax, 4(%esi)\n" /* e */
        "movl %ecx, %eax\n"
        "subl (%esi), %eax\n" /* e */
        "addl %eax, 8(%esi)\n" /* e */
        "movl %ecx, (%esi)\n" /* e */
        "movl -0x3c(%ebp), %edx\n" /* q */
        "movl 0x18(%ebp), %eax\n" /* s */
        "movl %edx, 0x34(%eax)\n"
        "movl $1, %eax\n"
        ".Lf2125ec_00212990:\n"
        "addl $0x38, %esp\n" /* line 186 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2125ec_00212998:\n"
        "movl 0x2c(%ecx), %edx\n" /* line 53 */
        "movl -0x3c(%ebp), %ecx\n" /* q */
        "subl %ecx, %edx\n"
        "movl %edx, -0x38(%ebp)\n" /* m */
        "jmp .Lf2125ec_00212632\n"
        ".Lf2125ec_002129a8:\n"
        "movzbl (%edx), %eax\n" /* line 128 */
        "movl -0x3c(%ebp), %ecx\n" /* q */
        "movb %al, (%ecx)\n"
        "movzbl 1(%edx), %eax\n" /* line 129 */
        "movb %al, 1(%ecx)\n"
        "addl $2, %edx\n"
        "movl -0x3c(%ebp), %esi\n" /* q, e */
        "leal 2(%esi), %ecx\n" /* e */
        "movl -0x14(%ebp), %eax\n"
        "leal -2(%eax, %ecx), %eax\n"
        "movl %eax, -0x3c(%ebp)\n" /* q */
        "movl %eax, %esi\n" /* e */
        ".Lf2125ec_002129cc:\n"
        "movzbl (%edx), %eax\n" /* line 131 */
        "movb %al, (%ecx)\n"
        "addl $1, %ecx\n"
        "addl $1, %edx\n"
        "cmpl %ecx, %esi\n" /* line 132 | e */
        "jne .Lf2125ec_002129cc\n"
        "jmp .Lf2125ec_00212684\n"
        ".Lf2125ec_002129e0:\n"
        "movl -0x14(%ebp), %esi\n" /* line 108 | e */
        "subl %eax, %esi\n" /* e */
        "movl %esi, -0x10(%ebp)\n" /* e */
        "movl -0x3c(%ebp), %ecx\n" /* q */
        "leal (%ecx, %eax), %esi\n" /* e */
        "movl %esi, -0x40(%ebp)\n" /* e */
        ".Lf2125ec_002129f1:\n"
        "movzbl (%edx), %eax\n" /* line 110 */
        "movb %al, (%ecx)\n"
        "addl $1, %ecx\n"
        "addl $1, %edx\n"
        "cmpl %ecx, -0x40(%ebp)\n" /* line 111 */
        "jne .Lf2125ec_002129f1\n"
        "movl 0x18(%ebp), %eax\n" /* line 112 | s */
        "movl 0x28(%eax), %edx\n"
        "movl -0x40(%ebp), %ecx\n"
        "movl -0x10(%ebp), %eax\n"
        "addl %eax, %ecx\n"
        "movl %ecx, -0x44(%ebp)\n"
        ".Lf2125ec_00212a12:\n"
        "movzbl (%edx), %eax\n" /* line 114 */
        "movb %al, (%esi)\n" /* e */
        "addl $1, %esi\n" /* e */
        "addl $1, %edx\n"
        "cmpl -0x44(%ebp), %esi\n" /* line 115 | e */
        "jne .Lf2125ec_00212a12\n"
        "movl %esi, -0x3c(%ebp)\n" /* line 177 | e, q */
        "jmp .Lf2125ec_00212684\n"
        ".Lf2125ec_00212a2a:\n"
        "leal 0xa7fa6(%ebx), %eax\n" /* line 174 */
        "movl 0x1c(%ebp), %ecx\n" /* z */
        "movl %eax, 0x18(%ecx)\n"
        "movl 4(%ecx), %eax\n" /* line 175 */
        "subl -0x28(%ebp), %eax\n"
        "movl -0x24(%ebp), %edx\n"
        "shrl $3, %edx\n"
        "cmpl %edx, %eax\n"
        "cmoval %edx, %eax\n"
        "movl -0x2c(%ebp), %ecx\n"
        "subl %eax, %ecx\n"
        "movl 0x18(%ebp), %esi\n" /* line 176 | s, e */
        "movl %edi, 0x20(%esi)\n" /* e */
        "leal (, %eax, 8), %edx\n"
        "subl %edx, -0x24(%ebp)\n"
        "movl -0x24(%ebp), %edx\n"
        "movl %edx, 0x1c(%esi)\n" /* e */
        "addl -0x28(%ebp), %eax\n"
        "movl 0x1c(%ebp), %esi\n" /* z, e */
        "movl %eax, 4(%esi)\n" /* e */
        "movl %ecx, %eax\n"
        "subl (%esi), %eax\n" /* e */
        "addl %eax, 8(%esi)\n" /* e */
        "movl %ecx, (%esi)\n" /* e */
        "movl -0x3c(%ebp), %edx\n" /* q */
        "movl 0x18(%ebp), %eax\n" /* s */
        "movl %edx, 0x34(%eax)\n"
        "movl $0xfffffffd, %eax\n"
        "jmp .Lf2125ec_00212990\n"
    );
}

