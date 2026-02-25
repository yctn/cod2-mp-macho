/* ASM dump from: inflate.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/zlib/inflate.c */

#include "common_types.h"
#include "imports.h"

int inflateEnd(z_streamp z);
int inflate(z_streamp z, int f, z_streamp z_2, const Bytef *dictionary, uInt dictLength, z_streamp z_5);
int inflateInit2_(z_streamp z, int w, const char *version, int stream_size);

/* line 72 */
__attribute__((naked))
int inflateEnd(z_streamp z)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 72 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %esi\n" /* z */
        "testl %esi, %esi\n" /* line 73 | z */
        "jne .Lf1f70ae_001f70c7\n"
        ".Lf1f70ae_001f70bc:\n"
        "movl $0xfffffffe, %eax\n" /* line 80 */
        ".Lf1f70ae_001f70c1:\n"
        "addl $0x14, %esp\n" /* line 81 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1f70ae_001f70c7:\n"
        "movl 0x1c(%esi), %eax\n" /* line 73 | z */
        "testl %eax, %eax\n"
        "je .Lf1f70ae_001f70bc\n"
        "movl 0x24(%esi), %edx\n" /* z */
        "testl %edx, %edx\n"
        "je .Lf1f70ae_001f70bc\n"
        "movl 0x14(%eax), %edx\n" /* line 75 */
        "testl %edx, %edx\n"
        "je .Lf1f70ae_001f70eb\n"
        "movl %esi, 4(%esp)\n" /* line 76 | z */
        "movl %edx, (%esp)\n"
        "calll inflate_blocks_free\n"
        "movl 0x1c(%esi), %eax\n" /* z */
        ".Lf1f70ae_001f70eb:\n"
        "movl %eax, 4(%esp)\n" /* line 77 */
        "movl 0x28(%esi), %eax\n" /* z */
        "movl %eax, (%esp)\n"
        "calll *0x24(%esi)\n" /* z */
        "movl $0, 0x1c(%esi)\n" /* line 78 | z */
        "xorl %eax, %eax\n"
        "jmp .Lf1f70ae_001f70c1\n"
    );
}

/* line 156 */
__attribute__((naked))
int inflate(z_streamp z, int f, z_streamp z_2, const Bytef *dictionary, uInt dictLength, z_streamp z_5)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 156 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %esi\n" /* z */
        "testl %esi, %esi\n" /* line 160 | z */
        "jne .Lf1f7103_001f7127\n"
        ".Lf1f7103_001f7118:\n"
        "movl $0xfffffffe, %edx\n" /* line 267 */
        "movl %edx, %eax\n" /* line 278 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1f7103_001f7127:\n"
        "movl 0x1c(%esi), %eax\n" /* line 160 | z */
        "testl %eax, %eax\n"
        "je .Lf1f7103_001f7118\n"
        "movl (%esi), %edi\n" /* z */
        "testl %edi, %edi\n"
        "je .Lf1f7103_001f7118\n"
        "xorl %eax, %eax\n" /* line 162 */
        "cmpl $4, 0xc(%ebp)\n" /* f */
        "setne %al\n"
        "leal -5(%eax, %eax, 4), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* r */
        "movl $0xfffffffb, %edx\n"
        "movl 0x1c(%esi), %ecx\n" /* line 164 | z */
        "cmpl $0xd, (%ecx)\n"
        "ja .Lf1f7103_001f7118\n"
        "movl (%ecx), %eax\n"
        "movl 0x4f(%ebx, %eax, 4), %eax\n"
        "addl %ebx, %eax\n"
        "jmpl *%eax\n"
        "nop\n"
        "nop\n"
        "rolb (%edx)\n"
        "addb %al, (%eax)\n"
        "subl (%ebx), %eax\n"
        "addb %al, (%eax)\n"
        "movb (%ecx), %al\n"
        "addb %al, (%eax)\n"
        "movl $0xf2000001, %esi\n" /* z */
        "addl %eax, (%eax)\n"
        "addb %ah, (%esi)\n" /* z */
        "addb (%eax), %al\n"
        "addb %ch, 0x64000003(%eax)\n"
        "addb (%eax), %al\n"
        "addb %dl, -0x3c000000(%eax)\n"
        "addb %al, (%eax)\n"
        "addb %bh, %al\n"
        "addb %al, (%eax)\n"
        "addb %ch, (%ecx, %eax)\n"
        "addb %al, (%eax)\n"
        "sahf\n"
        "addl (%eax), %eax\n"
        "addb %al, %dh\n"
        "addb (%eax), %al\n"
        "addb %al, %bh\n"
        "addb %cl, (%eax)\n" /* line 242 */
        "addb %al, (%eax)\n"
        "addb %cl, 0x468be455(%ebx)\n"
        "addb $0x85, %al\n" /* line 244 */
        "rorb $0x84, (%edi)\n"
        "jno .Lf1f7103_001f71a9\n"
    );
}

/* line 89 */
__attribute__((naked))
int inflateInit2_(z_streamp z, int w, const char *version, int stream_size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 89 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 0x10(%ebp), %eax\n" /* version */
        "testl %eax, %eax\n" /* line 90 */
        "jne .Lf1f7544_001f7564\n"
        ".Lf1f7544_001f7558:\n"
        "movl $0xfffffffa, %eax\n" /* line 64 */
        ".Lf1f7544_001f755d:\n"
        "addl $0x10, %esp\n" /* line 138 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1f7544_001f7564:\n"
        "cmpb $0x31, (%eax)\n" /* line 90 */
        "jne .Lf1f7544_001f7558\n"
        "cmpl $0x38, 0x14(%ebp)\n" /* stream_size */
        "jne .Lf1f7544_001f7558\n"
        "movl 8(%ebp), %eax\n" /* line 95 | z */
        "testl %eax, %eax\n"
        "jne .Lf1f7544_001f757d\n"
        ".Lf1f7544_001f7576:\n"
        "movl $0xfffffffe, %eax\n" /* line 64 */
        "jmp .Lf1f7544_001f755d\n"
        ".Lf1f7544_001f757d:\n"
        "movl 8(%ebp), %eax\n" /* line 97 | z */
        "movl $0, 0x18(%eax)\n"
        "movl 0x20(%eax), %eax\n" /* line 98 */
        "testl %eax, %eax\n"
        "jne .Lf1f7544_001f75a1\n"
        "movl 0x176846b(%ebx), %eax\n" /* line 100 */
        "movl 8(%ebp), %edx\n" /* z */
        "movl %eax, 0x20(%edx)\n"
        "movl $0, 0x28(%edx)\n" /* line 101 */
        ".Lf1f7544_001f75a1:\n"
        "movl 8(%ebp), %ecx\n" /* line 103 | z */
        "movl 0x24(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1f7544_001f75b4\n"
        "movl 0x1768467(%ebx), %eax\n"
        "movl %eax, 0x24(%ecx)\n"
        ".Lf1f7544_001f75b4:\n"
        "movl $0x18, 8(%esp)\n" /* line 104 */
        "movl $1, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* z */
        "movl 0x28(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x20(%edx)\n"
        "movl 8(%ebp), %ecx\n" /* z */
        "movl %eax, 0x1c(%ecx)\n"
        "testl %eax, %eax\n"
        "je .Lf1f7544_001f76b0\n"
        "movl $0, 0x14(%eax)\n" /* line 107 */
        "movl 0x1c(%ecx), %eax\n" /* line 110 */
        "movl $0, 0xc(%eax)\n"
        "movl 0xc(%ebp), %eax\n" /* line 111 | w */
        "testl %eax, %eax\n"
        "jns .Lf1f7544_001f7603\n"
        "negl 0xc(%ebp)\n" /* line 113 | w */
        "movl 0x1c(%ecx), %eax\n" /* line 114 */
        "movl $1, 0xc(%eax)\n"
        ".Lf1f7544_001f7603:\n"
        "movl 0xc(%ebp), %eax\n" /* line 118 | w */
        "subl $8, %eax\n"
        "cmpl $7, %eax\n"
        "ja .Lf1f7544_001f7701\n"
        "movl 8(%ebp), %edx\n" /* line 123 | z */
        "movl 0x1c(%edx), %eax\n"
        "movl 0xc(%ebp), %ecx\n" /* w */
        "movl %ecx, 0x10(%eax)\n"
        "movl $1, %eax\n" /* line 126 */
        "shll %cl, %eax\n"
        "movl 0x1c(%edx), %esi\n"
        "movl 0xc(%esi), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf1f7544_001f775a\n"
        "movl 0x1768463(%ebx), %edx\n"
        ".Lf1f7544_001f7639:\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* z */
        "movl %eax, (%esp)\n"
        "calll inflate_blocks_new\n"
        "movl %eax, 0x14(%esi)\n"
        "testl %eax, %eax\n"
        "je .Lf1f7544_001f76a6\n"
        "movl 8(%ebp), %edx\n" /* line 59 | z */
        "movl 0x1c(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1f7544_001f769f\n"
        "movl 8(%ebp), %ecx\n" /* line 61 | z */
        "movl $0, 0x14(%ecx)\n"
        "movl $0, 8(%ecx)\n"
        "movl $0, 0x18(%ecx)\n" /* line 62 */
        "movl 0x1c(%ecx), %edx\n" /* line 63 */
        "cmpl $1, 0xc(%edx)\n"
        "sbbl %eax, %eax\n"
        "notl %eax\n"
        "andl $7, %eax\n"
        "movl %eax, (%edx)\n"
        "movl $0, 8(%esp)\n" /* line 64 */
        "movl %ecx, 4(%esp)\n"
        "movl 0x1c(%ecx), %eax\n"
        "movl 0x14(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll inflate_blocks_reset\n"
        ".Lf1f7544_001f769f:\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1f7544_001f755d\n"
        ".Lf1f7544_001f76a6:\n"
        "movl 8(%ebp), %edx\n" /* line 73 | z */
        "movl 0x1c(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1f7544_001f76ba\n"
        ".Lf1f7544_001f76b0:\n"
        "movl $0xfffffffc, %eax\n" /* line 64 */
        "jmp .Lf1f7544_001f755d\n"
        ".Lf1f7544_001f76ba:\n"
        "movl 0x24(%edx), %edx\n" /* line 73 */
        "testl %edx, %edx\n"
        "je .Lf1f7544_001f76b0\n"
        "movl 0x14(%eax), %edx\n" /* line 75 */
        "testl %edx, %edx\n"
        "je .Lf1f7544_001f76dd\n"
        "movl 8(%ebp), %ecx\n" /* line 76 | z */
        "movl %ecx, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll inflate_blocks_free\n"
        "movl 8(%ebp), %edx\n" /* z */
        "movl 0x1c(%edx), %eax\n"
        ".Lf1f7544_001f76dd:\n"
        "movl %eax, 4(%esp)\n" /* line 77 */
        "movl 8(%ebp), %ecx\n" /* z */
        "movl 0x28(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x24(%ecx)\n"
        "movl 8(%ebp), %eax\n" /* line 78 | z */
        "movl $0, 0x1c(%eax)\n"
        "movl $0xfffffffc, %eax\n"
        "jmp .Lf1f7544_001f755d\n"
        ".Lf1f7544_001f7701:\n"
        "movl 8(%ebp), %edx\n" /* line 73 | z */
        "movl 0x1c(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1f7544_001f7576\n"
        "movl 0x24(%edx), %esi\n"
        "testl %esi, %esi\n"
        "je .Lf1f7544_001f7576\n"
        "movl 0x14(%eax), %edx\n" /* line 75 */
        "testl %edx, %edx\n"
        "je .Lf1f7544_001f7736\n"
        "movl 8(%ebp), %ecx\n" /* line 76 | z */
        "movl %ecx, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll inflate_blocks_free\n"
        "movl 8(%ebp), %edx\n" /* z */
        "movl 0x1c(%edx), %eax\n"
        ".Lf1f7544_001f7736:\n"
        "movl %eax, 4(%esp)\n" /* line 77 */
        "movl 8(%ebp), %ecx\n" /* z */
        "movl 0x28(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x24(%ecx)\n"
        "movl 8(%ebp), %eax\n" /* line 78 | z */
        "movl $0, 0x1c(%eax)\n"
        "movl $0xfffffffe, %eax\n"
        "jmp .Lf1f7544_001f755d\n"
        ".Lf1f7544_001f775a:\n"
        "xorl %edx, %edx\n" /* line 126 */
        "jmp .Lf1f7544_001f7639\n"
    );
}

