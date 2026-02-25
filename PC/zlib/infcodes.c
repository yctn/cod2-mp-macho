/* ASM dump from: infcodes.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/zlib/infcodes.c */

#include "common_types.h"
#include "imports.h"

inflate_codes_statef * inflate_codes_new(uInt bl, uInt bd, inflate_huft *tl, inflate_huft *td, z_streamp z);
int inflate_codes(inflate_blocks_statef *s, z_streamp z, int r);
short unsigned int inflate_codes_free(inflate_codes_statef *c, z_streamp z);

/* line 67 */
__attribute__((naked))
inflate_codes_statef * inflate_codes_new(uInt bl, uInt bd, inflate_huft *tl, inflate_huft *td, z_streamp z)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 67 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x18(%ebp), %edx\n" /* z */
        "movl $0x1c, 8(%esp)\n" /* line 70 */
        "movl $1, 4(%esp)\n"
        "movl 0x28(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x20(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf2006e4_0020072a\n"
        "movl $0, (%eax)\n" /* line 73 */
        "movzbl 8(%ebp), %edx\n" /* line 74 | bl */
        "movb %dl, 0x10(%eax)\n"
        "movzbl 0xc(%ebp), %edx\n" /* line 75 | bd */
        "movb %dl, 0x11(%eax)\n"
        "movl 0x10(%ebp), %edx\n" /* line 76 | tl */
        "movl %edx, 0x14(%eax)\n"
        "movl 0x14(%ebp), %edx\n" /* line 77 | td */
        "movl %edx, 0x18(%eax)\n"
        ".Lf2006e4_0020072a:\n"
        "leave\n" /* line 81 */
        "retl\n"
    );
}

/* line 88 */
__attribute__((naked))
int inflate_codes(inflate_blocks_statef *s, z_streamp z, int r)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 88 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %esi\n" /* s */
        "movl 0xc(%ebp), %eax\n" /* z */
        "movl %eax, -0x44(%ebp)\n" /* z */
        "movl 0x10(%ebp), %edx\n" /* r */
        "movl %edx, -0x48(%ebp)\n" /* r */
        "movl 4(%esi), %ecx\n" /* line 99 | s */
        "movl %ecx, -0x30(%ebp)\n" /* c */
        "movl (%eax), %eax\n" /* line 102 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl -0x44(%ebp), %edx\n" /* z */
        "movl 4(%edx), %edx\n"
        "movl %edx, -0x38(%ebp)\n" /* n */
        "movl 0x20(%esi), %ecx\n" /* s */
        "movl %ecx, -0x40(%ebp)\n" /* b */
        "movl 0x1c(%esi), %eax\n" /* s */
        "movl %eax, -0x3c(%ebp)\n" /* k */
        "movl 0x34(%esi), %edx\n" /* s */
        "movl %edx, -0x1c(%ebp)\n"
        "movl 0x30(%esi), %eax\n" /* s */
        "cmpl %eax, %edx\n"
        "jae .Lf20072c_00200804\n"
        "subl %edx, %eax\n"
        "subl $1, %eax\n"
        "movl %eax, -0x34(%ebp)\n" /* m */
        ".Lf20072c_00200782:\n"
        "movl -0x30(%ebp), %edx\n" /* line 105 | c */
        "cmpl $9, (%edx)\n"
        "ja .Lf20072c_002007c0\n"
        "movl (%edx), %eax\n"
        "movl 0x5e(%ebx, %eax, 4), %eax\n"
        "addl %ebx, %eax\n"
        "jmpl *%eax\n"
        "nop\n"
        "xlatb\n"
        "addb %al, (%eax)\n"
        "addb %al, (%eax)\n"
        "addl %eax, (%eax)\n"
        "addb %cl, 0x3f10000(%esp, %eax)\n"
        "addb %al, (%eax)\n"
        "addl %fs:(%eax), %eax\n"
        "addb %dl, 0x12000002(%esi)\n" /* s */
        "addb (%eax), %al\n"
        "addb %dl, -0x27ffffff(%eax)\n"
        "addl %eax, (%eax)\n"
        "addb %dl, 4(%edx)\n"
        "addb %al, (%eax)\n"
        ".Lf20072c_002007c0:\n"
        "movl -0x40(%ebp), %edx\n" /* line 240 | b */
        "movl %edx, 0x20(%esi)\n" /* s */
        "movl -0x3c(%ebp), %ecx\n" /* k */
        "movl %ecx, 0x1c(%esi)\n" /* s */
        "movl -0x38(%ebp), %edx\n" /* n */
        "movl -0x44(%ebp), %eax\n" /* z */
        "movl %edx, 4(%eax)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl -0x44(%ebp), %ecx\n" /* z */
        "subl (%ecx), %eax\n"
        "addl %eax, 8(%ecx)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%ecx)\n"
        "movl -0x1c(%ebp), %edx\n"
        "movl %edx, 0x34(%esi)\n" /* s */
        "movl $0xfffffffe, 0x10(%ebp)\n" /* r */
        ".Lf20072c_002007f2:\n"
        "movl %ecx, 0xc(%ebp)\n" /* line 161 | z */
        ".Lf20072c_002007f5:\n"
        "movl %esi, 8(%ebp)\n" /* s */
        "addl $0x6c, %esp\n" /* line 245 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp inflate_flush\n" /* line 161 */
        ".Lf20072c_00200804:\n"
        "movl 0x2c(%esi), %ecx\n" /* line 102 | s */
        "subl %edx, %ecx\n"
        "movl %ecx, -0x34(%ebp)\n" /* m */
        "jmp .Lf20072c_00200782\n"
        "cmpl $0x101, -0x34(%ebp)\n" /* line 109 | m */
        "ja .Lf20072c_00200e00\n"
        ".Lf20072c_0020081e:\n"
        "movl -0x30(%ebp), %ecx\n" /* line 121 | c */
        "movzbl 0x10(%ecx), %ecx\n"
        "movl -0x30(%ebp), %eax\n" /* c */
        "movl %ecx, 0xc(%eax)\n"
        "movl -0x30(%ebp), %edx\n" /* line 122 | c */
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl $1, (%edx)\n" /* line 123 */
        "movl -0x2c(%ebp), %ecx\n"
        "movl %ecx, -0x28(%ebp)\n"
        "movl -0x30(%ebp), %eax\n" /* line 125 | c */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0x4c(%ebp)\n"
        "cmpl %eax, -0x3c(%ebp)\n" /* line 126 | k */
        "jae .Lf20072c_00200c96\n"
        "movl -0x38(%ebp), %eax\n" /* n */
        "testl %eax, %eax\n"
        "je .Lf20072c_00201099\n"
        "movl -0x38(%ebp), %edi\n" /* n, f */
        ".Lf20072c_00200860:\n"
        "subl $1, %edi\n" /* f */
        "movl -0x2c(%ebp), %edx\n"
        "movzbl (%edx), %eax\n"
        "movzbl -0x3c(%ebp), %ecx\n" /* k */
        "shll %cl, %eax\n"
        "orl %eax, -0x40(%ebp)\n" /* b */
        "addl $1, %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "addl $8, -0x3c(%ebp)\n" /* k */
        "movl -0x3c(%ebp), %eax\n" /* k */
        "cmpl %eax, -0x4c(%ebp)\n"
        "jbe .Lf20072c_00200c8c\n"
        "movl -0x38(%ebp), %edx\n" /* line 88 | n */
        "addl -0x28(%ebp), %edx\n"
        "cmpl -0x2c(%ebp), %edx\n" /* line 126 */
        "jne .Lf20072c_00200860\n"
        "movl $0, -0x48(%ebp)\n" /* r */
        ".Lf20072c_0020089a:\n"
        "movl -0x40(%ebp), %ecx\n" /* b */
        "movl %ecx, 0x20(%esi)\n" /* s */
        "movl -0x3c(%ebp), %eax\n" /* k */
        "movl %eax, 0x1c(%esi)\n" /* s */
        "movl -0x44(%ebp), %ecx\n" /* z */
        "movl $0, 4(%ecx)\n"
        "movl %edx, %eax\n"
        "subl (%ecx), %eax\n"
        "addl %eax, 8(%ecx)\n"
        "movl %edx, (%ecx)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0x34(%esi)\n" /* s */
        "movl -0x48(%ebp), %edx\n" /* r */
        "movl %edx, 0x10(%ebp)\n" /* r */
        "jmp .Lf20072c_002007f2\n"
        "cmpl $7, -0x3c(%ebp)\n" /* line 221 | k */
        "jbe .Lf20072c_002008dc\n"
        "subl $8, -0x3c(%ebp)\n" /* line 224 | k */
        "addl $1, -0x38(%ebp)\n" /* line 225 | n */
        "subl $1, -0x2c(%ebp)\n" /* line 226 */
        ".Lf20072c_002008dc:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 228 */
        "movl %eax, 0x34(%esi)\n" /* s */
        "movl -0x48(%ebp), %edx\n" /* r */
        "movl %edx, 8(%esp)\n"
        "movl -0x44(%ebp), %ecx\n" /* z */
        "movl %ecx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* s */
        "calll inflate_flush\n"
        "movl %eax, %edx\n"
        "movl 0x34(%esi), %eax\n" /* s */
        "movl %eax, -0x1c(%ebp)\n"
        "cmpl 0x30(%esi), %eax\n" /* line 229 | s */
        "jne .Lf20072c_00200d7b\n"
        "movl -0x30(%ebp), %edx\n" /* line 231 | c */
        "movl $8, (%edx)\n"
        "movl -0x40(%ebp), %ecx\n" /* line 234 | b */
        "movl %ecx, 0x20(%esi)\n" /* s */
        "movl -0x3c(%ebp), %eax\n" /* k */
        "movl %eax, 0x1c(%esi)\n" /* s */
        "movl -0x38(%ebp), %ecx\n" /* n */
        "movl -0x44(%ebp), %edx\n" /* z */
        "movl %ecx, 4(%edx)\n"
        "movl -0x2c(%ebp), %eax\n"
        "subl (%edx), %eax\n"
        "addl %eax, 8(%edx)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%edx)\n"
        "movl -0x1c(%ebp), %edx\n"
        "movl %edx, 0x34(%esi)\n" /* s */
        "movl $1, 0x10(%ebp)\n" /* r */
        "movl -0x44(%ebp), %ecx\n" /* z */
        "movl %ecx, 0xc(%ebp)\n" /* z */
        "jmp .Lf20072c_002007f5\n"
        "movl -0x34(%ebp), %eax\n" /* line 216 | m */
        "testl %eax, %eax\n"
        "jne .Lf20072c_00200f36\n"
        "movl -0x1c(%ebp), %edx\n"
        "cmpl 0x2c(%esi), %edx\n" /* s */
        "je .Lf20072c_00200fa7\n"
        "movl %edx, %eax\n"
        ".Lf20072c_00200965:\n"
        "movl %eax, 0x34(%esi)\n" /* s */
        "movl -0x48(%ebp), %edx\n" /* r */
        "movl %edx, 8(%esp)\n"
        "movl -0x44(%ebp), %ecx\n" /* z */
        "movl %ecx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* s */
        "calll inflate_flush\n"
        "movl %eax, %edi\n" /* f */
        "movl 0x34(%esi), %edx\n" /* s */
        "movl 0x30(%esi), %ecx\n" /* s */
        "cmpl %ecx, %edx\n"
        "jae .Lf20072c_00200f8f\n"
        "movl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "subl $1, %eax\n"
        "movl %eax, -0x34(%ebp)\n" /* m */
        ".Lf20072c_00200998:\n"
        "cmpl 0x2c(%esi), %edx\n" /* s */
        "je .Lf20072c_0020104c\n"
        ".Lf20072c_002009a1:\n"
        "movl -0x34(%ebp), %eax\n" /* m */
        "testl %eax, %eax\n"
        "je .Lf20072c_002010f5\n"
        ".Lf20072c_002009ac:\n"
        "movl -0x30(%ebp), %ecx\n" /* line 217 | c */
        "movl 8(%ecx), %eax\n"
        "movb %al, (%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "subl $1, -0x34(%ebp)\n" /* m */
        "movl $0, (%ecx)\n" /* line 218 */
        "movl $0, -0x48(%ebp)\n" /* r */
        "jmp .Lf20072c_00200782\n"
        "movl -0x30(%ebp), %eax\n" /* c */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0x4c(%ebp)\n"
        ".Lf20072c_002009d9:\n"
        "movl -0x1c(%ebp), %edi\n" /* line 202 | f */
        "subl -0x4c(%ebp), %edi\n" /* f */
        "movl 0x28(%esi), %edx\n" /* line 203 | s */
        "cmpl %edi, %edx\n" /* f */
        "jbe .Lf20072c_002009f1\n"
        "movl 0x2c(%esi), %eax\n" /* line 204 | s */
        "subl %edx, %eax\n"
        ".Lf20072c_002009eb:\n"
        "addl %eax, %edi\n" /* f */
        "cmpl %edi, %edx\n" /* line 203 | f */
        "ja .Lf20072c_002009eb\n"
        ".Lf20072c_002009f1:\n"
        "movl -0x30(%ebp), %edx\n" /* line 205 | c */
        "movl 4(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf20072c_00200d6e\n"
        ".Lf20072c_002009ff:\n"
        "movl -0x34(%ebp), %eax\n" /* line 207 | m */
        "testl %eax, %eax\n"
        "jne .Lf20072c_00200a60\n"
        "movl 0x2c(%esi), %eax\n" /* s */
        "cmpl -0x1c(%ebp), %eax\n"
        "je .Lf20072c_00200c4f\n"
        ".Lf20072c_00200a12:\n"
        "movl -0x1c(%ebp), %eax\n"
        ".Lf20072c_00200a15:\n"
        "movl %eax, 0x34(%esi)\n" /* s */
        "movl -0x48(%ebp), %edx\n" /* r */
        "movl %edx, 8(%esp)\n"
        "movl -0x44(%ebp), %ecx\n" /* z */
        "movl %ecx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* s */
        "calll inflate_flush\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl 0x34(%esi), %edx\n" /* s */
        "movl 0x30(%esi), %ecx\n" /* s */
        "cmpl %ecx, %edx\n"
        "jae .Lf20072c_00200c7f\n"
        "movl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "subl $1, %eax\n"
        "movl %eax, -0x34(%ebp)\n" /* m */
        ".Lf20072c_00200a49:\n"
        "cmpl 0x2c(%esi), %edx\n" /* s */
        "je .Lf20072c_00200ddf\n"
        ".Lf20072c_00200a52:\n"
        "movl %edx, -0x1c(%ebp)\n"
        ".Lf20072c_00200a55:\n"
        "movl -0x34(%ebp), %eax\n" /* m */
        "testl %eax, %eax\n"
        "je .Lf20072c_00201010\n"
        ".Lf20072c_00200a60:\n"
        "movzbl (%edi), %eax\n" /* line 208 | f */
        "movl -0x1c(%ebp), %edx\n"
        "movb %al, (%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "addl $1, %edi\n" /* f */
        "subl $1, -0x34(%ebp)\n" /* m */
        "cmpl 0x2c(%esi), %edi\n" /* line 209 | s, f */
        "je .Lf20072c_00200ce9\n"
        ".Lf20072c_00200a7e:\n"
        "movl -0x30(%ebp), %ecx\n" /* line 211 | c */
        "movl 4(%ecx), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 4(%ecx)\n"
        "testl %eax, %eax\n" /* line 205 */
        "je .Lf20072c_00200f49\n"
        "movl $0, -0x48(%ebp)\n" /* r */
        "jmp .Lf20072c_002009ff\n"
        "movl -0x30(%ebp), %eax\n" /* line 195 | c */
        "movl 8(%eax), %edi\n" /* f */
        "cmpl %edi, -0x3c(%ebp)\n" /* line 196 | f, k */
        "jae .Lf20072c_00200ebf\n"
        "movl -0x38(%ebp), %ecx\n" /* n */
        "testl %ecx, %ecx\n"
        "je .Lf20072c_00200af1\n"
        "movl -0x2c(%ebp), %edx\n"
        "movl -0x38(%ebp), %ecx\n" /* n */
        "movl %ecx, -0x4c(%ebp)\n"
        ".Lf20072c_00200abd:\n"
        "subl $1, -0x4c(%ebp)\n"
        "movzbl (%edx), %eax\n"
        "movzbl -0x3c(%ebp), %ecx\n" /* k */
        "shll %cl, %eax\n"
        "orl %eax, -0x40(%ebp)\n" /* b */
        "addl $1, %edx\n"
        "addl $8, -0x3c(%ebp)\n" /* k */
        "cmpl -0x3c(%ebp), %edi\n" /* k, f */
        "jbe .Lf20072c_00200fd8\n"
        "movl -0x38(%ebp), %eax\n" /* n */
        "addl -0x2c(%ebp), %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf20072c_00200abd\n"
        "movl %edx, -0x2c(%ebp)\n"
        "movl $0, -0x48(%ebp)\n" /* r */
        ".Lf20072c_00200af1:\n"
        "movl -0x40(%ebp), %eax\n" /* b */
        "movl %eax, 0x20(%esi)\n" /* s */
        "movl -0x3c(%ebp), %edx\n" /* k */
        "movl %edx, 0x1c(%esi)\n" /* s */
        "movl -0x44(%ebp), %ecx\n" /* z */
        "movl $0, 4(%ecx)\n"
        "movl -0x2c(%ebp), %eax\n"
        "subl (%ecx), %eax\n"
        "addl %eax, 8(%ecx)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%ecx)\n"
        "movl -0x1c(%ebp), %edx\n"
        "movl %edx, 0x34(%esi)\n" /* s */
        "movl -0x48(%ebp), %ecx\n" /* r */
        "movl %ecx, 0x10(%ebp)\n" /* r */
        "movl -0x44(%ebp), %eax\n" /* z */
        "movl %eax, 0xc(%ebp)\n" /* z */
        "jmp .Lf20072c_002007f5\n"
        "movl -0x38(%ebp), %edi\n" /* line 105 | n, f */
        ".Lf20072c_00200b2e:\n"
        "movl -0x30(%ebp), %ecx\n" /* line 172 | c */
        "movl 0xc(%ecx), %ecx\n"
        "movl %ecx, -0x4c(%ebp)\n"
        "cmpl %ecx, -0x3c(%ebp)\n" /* line 173 | k */
        "jb .Lf20072c_00200cf1\n"
        "movl %edi, -0x38(%ebp)\n" /* f, n */
        ".Lf20072c_00200b43:\n"
        "movl 0x175f28a(%ebx), %eax\n" /* line 174 */
        "movl -0x40(%ebp), %edx\n" /* b */
        "movl -0x4c(%ebp), %ecx\n"
        "andl (%eax, %ecx, 4), %edx\n"
        "movl -0x30(%ebp), %ecx\n" /* c */
        "movl 8(%ecx), %eax\n"
        "leal (%eax, %edx, 8), %edx\n"
        "movzbl 1(%edx), %ecx\n" /* line 175 */
        "shrl %cl, -0x40(%ebp)\n" /* b */
        "subl %ecx, -0x3c(%ebp)\n" /* k */
        "movzbl (%edx), %eax\n" /* line 176 */
        "testb $0x10, %al\n" /* line 177 */
        "jne .Lf20072c_00200dc5\n"
        "testb $0x40, %al\n" /* line 184 */
        "jne .Lf20072c_002010a9\n"
        "movl -0x30(%ebp), %ecx\n" /* line 186 | c */
        "movl %eax, 0xc(%ecx)\n"
        "movl 4(%edx), %eax\n" /* line 187 */
        "leal (%edx, %eax, 8), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "jmp .Lf20072c_00200782\n"
        "movl -0x40(%ebp), %eax\n" /* line 237 | b */
        "movl %eax, 0x20(%esi)\n" /* s */
        "movl -0x3c(%ebp), %edx\n" /* k */
        "movl %edx, 0x1c(%esi)\n" /* s */
        "movl -0x38(%ebp), %eax\n" /* n */
        "movl -0x44(%ebp), %ecx\n" /* z */
        "movl %eax, 4(%ecx)\n"
        "movl -0x2c(%ebp), %eax\n"
        "subl (%ecx), %eax\n"
        "addl %eax, 8(%ecx)\n"
        "movl -0x2c(%ebp), %edx\n"
        "movl %edx, (%ecx)\n"
        "movl -0x1c(%ebp), %ecx\n"
        "movl %ecx, 0x34(%esi)\n" /* s */
        "movl $0xfffffffd, 0x10(%ebp)\n" /* r */
        "movl -0x44(%ebp), %eax\n" /* z */
        "movl %eax, 0xc(%ebp)\n" /* z */
        "jmp .Lf20072c_002007f5\n"
        "movl -0x30(%ebp), %eax\n" /* line 163 | c */
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "cmpl %eax, -0x3c(%ebp)\n" /* line 164 | k */
        "jae .Lf20072c_00200ef8\n"
        "movl -0x38(%ebp), %edx\n" /* n */
        "testl %edx, %edx\n"
        "je .Lf20072c_002010a1\n"
        "movl -0x38(%ebp), %edi\n" /* n, f */
        "movl -0x2c(%ebp), %edx\n"
        ".Lf20072c_00200be9:\n"
        "subl $1, %edi\n" /* f */
        "movzbl (%edx), %eax\n"
        "movzbl -0x3c(%ebp), %ecx\n" /* k */
        "shll %cl, %eax\n"
        "orl %eax, -0x40(%ebp)\n" /* b */
        "addl $1, %edx\n"
        "addl $8, -0x3c(%ebp)\n" /* k */
        "movl -0x3c(%ebp), %eax\n" /* k */
        "cmpl %eax, -0x20(%ebp)\n"
        "jbe .Lf20072c_00201001\n"
        "movl -0x38(%ebp), %ecx\n" /* line 88 | n */
        "addl -0x2c(%ebp), %ecx\n"
        "cmpl %edx, %ecx\n" /* line 164 */
        "jne .Lf20072c_00200be9\n"
        "movl $0, -0x48(%ebp)\n" /* r */
        ".Lf20072c_00200c1c:\n"
        "movl -0x40(%ebp), %edx\n" /* b */
        "movl %edx, 0x20(%esi)\n" /* s */
        "movl -0x3c(%ebp), %eax\n" /* k */
        "movl %eax, 0x1c(%esi)\n" /* s */
        "movl -0x44(%ebp), %edx\n" /* z */
        "movl $0, 4(%edx)\n"
        "movl %ecx, %eax\n"
        "subl (%edx), %eax\n"
        "addl %eax, 8(%edx)\n"
        "movl %ecx, (%edx)\n"
        "movl -0x1c(%ebp), %ecx\n"
        "movl %ecx, 0x34(%esi)\n" /* s */
        "movl -0x48(%ebp), %eax\n" /* r */
        "movl %eax, 0x10(%ebp)\n" /* r */
        "movl %edx, 0xc(%ebp)\n" /* z */
        "jmp .Lf20072c_002007f5\n"
        ".Lf20072c_00200c4f:\n"
        "movl 0x30(%esi), %edx\n" /* line 207 | s */
        "movl 0x28(%esi), %ecx\n" /* s */
        "movl %ecx, -0x1c(%ebp)\n"
        "cmpl %ecx, %edx\n"
        "je .Lf20072c_00200f87\n"
        "jbe .Lf20072c_00200f3e\n"
        "subl -0x1c(%ebp), %edx\n"
        "subl $1, %edx\n"
        "movl %edx, -0x34(%ebp)\n" /* m */
        ".Lf20072c_00200c6f:\n"
        "movl -0x34(%ebp), %eax\n" /* m */
        "testl %eax, %eax\n"
        "jne .Lf20072c_00200a60\n"
        "jmp .Lf20072c_00200a12\n"
        ".Lf20072c_00200c7f:\n"
        "movl 0x2c(%esi), %eax\n" /* s */
        "subl %edx, %eax\n"
        "movl %eax, -0x34(%ebp)\n" /* m */
        "jmp .Lf20072c_00200a49\n"
        ".Lf20072c_00200c8c:\n"
        "movl %edi, -0x38(%ebp)\n" /* line 126 | f, n */
        "movl $0, -0x48(%ebp)\n" /* r */
        ".Lf20072c_00200c96:\n"
        "movl 0x175f28a(%ebx), %eax\n" /* line 127 */
        "movl -0x40(%ebp), %edx\n" /* b */
        "movl -0x4c(%ebp), %ecx\n"
        "andl (%eax, %ecx, 4), %edx\n"
        "movl -0x30(%ebp), %ecx\n" /* c */
        "movl 8(%ecx), %eax\n"
        "leal (%eax, %edx, 8), %edi\n" /* f */
        "movzbl 1(%edi), %ecx\n" /* line 128 | f */
        "shrl %cl, -0x40(%ebp)\n" /* b */
        "subl %ecx, -0x3c(%ebp)\n" /* k */
        "movzbl (%edi), %eax\n" /* line 129 | f */
        "movzbl %al, %edx\n"
        "testb %al, %al\n" /* line 130 */
        "je .Lf20072c_00200db1\n"
        "testb $0x10, %dl\n" /* line 139 */
        "je .Lf20072c_00200f58\n"
        "andl $0xf, %edx\n" /* line 141 */
        "movl -0x30(%ebp), %ecx\n" /* c */
        "movl %edx, 8(%ecx)\n"
        "movl 4(%edi), %eax\n" /* line 142 | f */
        "movl %eax, 4(%ecx)\n"
        "movl $2, (%ecx)\n" /* line 143 */
        "jmp .Lf20072c_00200782\n"
        ".Lf20072c_00200ce9:\n"
        "movl 0x28(%esi), %edi\n" /* line 210 | s, f */
        "jmp .Lf20072c_00200a7e\n"
        ".Lf20072c_00200cf1:\n"
        "testl %edi, %edi\n" /* line 173 | f */
        "je .Lf20072c_00200d31\n"
        "movl %edi, -0x38(%ebp)\n" /* f, n */
        "movl -0x2c(%ebp), %edx\n"
        ".Lf20072c_00200cfb:\n"
        "subl $1, -0x38(%ebp)\n" /* n */
        "movzbl (%edx), %eax\n"
        "movzbl -0x3c(%ebp), %ecx\n" /* k */
        "shll %cl, %eax\n"
        "orl %eax, -0x40(%ebp)\n" /* b */
        "addl $1, %edx\n"
        "addl $8, -0x3c(%ebp)\n" /* k */
        "movl -0x4c(%ebp), %eax\n"
        "cmpl %eax, -0x3c(%ebp)\n" /* k */
        "jae .Lf20072c_00200f78\n"
        "movl -0x2c(%ebp), %eax\n"
        "addl %edi, %eax\n" /* f */
        "cmpl %eax, %edx\n"
        "jne .Lf20072c_00200cfb\n"
        "movl %edx, -0x2c(%ebp)\n"
        "movl $0, -0x48(%ebp)\n" /* r */
        ".Lf20072c_00200d31:\n"
        "movl -0x40(%ebp), %edx\n" /* b */
        "movl %edx, 0x20(%esi)\n" /* s */
        "movl -0x3c(%ebp), %ecx\n" /* k */
        "movl %ecx, 0x1c(%esi)\n" /* s */
        "movl -0x44(%ebp), %eax\n" /* z */
        "movl $0, 4(%eax)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl -0x44(%ebp), %edx\n" /* z */
        "subl (%edx), %eax\n"
        "addl %eax, 8(%edx)\n"
        "movl -0x2c(%ebp), %ecx\n"
        "movl %ecx, (%edx)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0x34(%esi)\n" /* s */
        "movl -0x48(%ebp), %edx\n" /* r */
        "movl %edx, 0x10(%ebp)\n" /* r */
        "movl -0x44(%ebp), %ecx\n" /* z */
        "movl %ecx, 0xc(%ebp)\n" /* z */
        "jmp .Lf20072c_002007f5\n"
        ".Lf20072c_00200d6e:\n"
        "movl %edx, %eax\n"
        ".Lf20072c_00200d70:\n"
        "movl $0, (%eax)\n" /* line 213 */
        "jmp .Lf20072c_00200782\n"
        ".Lf20072c_00200d7b:\n"
        "movl -0x40(%ebp), %ecx\n" /* line 230 | b */
        "movl %ecx, 0x20(%esi)\n" /* s */
        "movl -0x3c(%ebp), %eax\n" /* k */
        "movl %eax, 0x1c(%esi)\n" /* s */
        "movl -0x38(%ebp), %eax\n" /* n */
        "movl -0x44(%ebp), %ecx\n" /* z */
        "movl %eax, 4(%ecx)\n"
        "movl -0x2c(%ebp), %eax\n"
        "subl (%ecx), %eax\n"
        "addl %eax, 8(%ecx)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%ecx)\n"
        "movl -0x1c(%ebp), %ecx\n"
        "movl %ecx, 0x34(%esi)\n" /* s */
        "movl %edx, 0x10(%ebp)\n" /* r */
        "movl -0x44(%ebp), %eax\n" /* z */
        "movl %eax, 0xc(%ebp)\n" /* z */
        "jmp .Lf20072c_002007f5\n"
        ".Lf20072c_00200db1:\n"
        "movl 4(%edi), %eax\n" /* line 132 | f */
        "movl -0x30(%ebp), %edx\n" /* c */
        "movl %eax, 8(%edx)\n"
        "movl $6, (%edx)\n" /* line 136 */
        "jmp .Lf20072c_00200782\n"
        ".Lf20072c_00200dc5:\n"
        "andl $0xf, %eax\n" /* line 179 */
        "movl -0x30(%ebp), %ecx\n" /* c */
        "movl %eax, 8(%ecx)\n"
        "movl 4(%edx), %edx\n" /* line 180 */
        "movl %edx, 0xc(%ecx)\n"
        "movl $4, (%ecx)\n" /* line 181 */
        "jmp .Lf20072c_00200782\n"
        ".Lf20072c_00200ddf:\n"
        "movl 0x28(%esi), %eax\n" /* line 207 | s */
        "movl %eax, -0x1c(%ebp)\n"
        "cmpl %eax, %ecx\n"
        "je .Lf20072c_00200a52\n"
        "jbe .Lf20072c_00200f9c\n"
        "subl %eax, %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x34(%ebp)\n" /* m */
        "jmp .Lf20072c_00200a55\n"
        ".Lf20072c_00200e00:\n"
        "cmpl $9, -0x38(%ebp)\n" /* line 109 | n */
        "jbe .Lf20072c_0020081e\n"
        "movl -0x40(%ebp), %eax\n" /* line 111 | b */
        "movl %eax, 0x20(%esi)\n" /* s */
        "movl -0x3c(%ebp), %edx\n" /* k */
        "movl %edx, 0x1c(%esi)\n" /* s */
        "movl -0x38(%ebp), %eax\n" /* n */
        "movl -0x44(%ebp), %ecx\n" /* z */
        "movl %eax, 4(%ecx)\n"
        "movl -0x2c(%ebp), %eax\n"
        "subl (%ecx), %eax\n"
        "addl %eax, 8(%ecx)\n"
        "movl -0x2c(%ebp), %edx\n"
        "movl %edx, (%ecx)\n"
        "movl -0x1c(%ebp), %ecx\n"
        "movl %ecx, 0x34(%esi)\n" /* s */
        "movl -0x44(%ebp), %eax\n" /* line 112 | z */
        "movl %eax, 0x14(%esp)\n"
        "movl %esi, 0x10(%esp)\n" /* s */
        "movl -0x30(%ebp), %edx\n" /* c */
        "movl 0x18(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movzbl 0x11(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movzbl 0x10(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll inflate_fast\n"
        "movl %eax, -0x48(%ebp)\n" /* r */
        "movl -0x44(%ebp), %ecx\n" /* line 113 | z */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x2c(%ebp)\n"
        "movl -0x44(%ebp), %eax\n" /* z */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x38(%ebp)\n" /* n */
        "movl 0x20(%esi), %edx\n" /* s */
        "movl %edx, -0x40(%ebp)\n" /* b */
        "movl 0x1c(%esi), %ecx\n" /* s */
        "movl %ecx, -0x3c(%ebp)\n" /* k */
        "movl 0x34(%esi), %eax\n" /* s */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0x30(%esi), %eax\n" /* s */
        "cmpl %eax, -0x1c(%ebp)\n"
        "jae .Lf20072c_00201068\n"
        "subl -0x1c(%ebp), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, -0x34(%ebp)\n" /* m */
        ".Lf20072c_00200e9d:\n"
        "movl -0x48(%ebp), %edi\n" /* line 114 | r, f */
        "testl %edi, %edi\n" /* f */
        "je .Lf20072c_0020081e\n"
        "xorl %eax, %eax\n" /* line 116 */
        "cmpl $1, -0x48(%ebp)\n" /* r */
        "setne %al\n"
        "leal 7(%eax, %eax), %eax\n"
        "movl -0x30(%ebp), %edx\n" /* c */
        "movl %eax, (%edx)\n"
        "jmp .Lf20072c_00200782\n"
        ".Lf20072c_00200ebf:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 196 */
        ".Lf20072c_00200ec2:\n"
        "movl 0x175f28a(%ebx), %eax\n" /* line 197 */
        "movl -0x40(%ebp), %ecx\n" /* b */
        "andl (%eax, %edi, 4), %ecx\n"
        "movl %ecx, -0x4c(%ebp)\n"
        "movl -0x30(%ebp), %eax\n" /* c */
        "movl 0xc(%eax), %eax\n"
        "addl %eax, %ecx\n"
        "movl %ecx, -0x4c(%ebp)\n"
        "movl -0x30(%ebp), %eax\n" /* c */
        "movl %ecx, 0xc(%eax)\n"
        "movl %edi, %ecx\n" /* line 198 | f */
        "shrl %cl, -0x40(%ebp)\n" /* b */
        "subl %edi, -0x3c(%ebp)\n" /* f, k */
        "movl $5, (%eax)\n" /* line 200 */
        "movl %edx, -0x2c(%ebp)\n"
        "jmp .Lf20072c_002009d9\n"
        ".Lf20072c_00200ef8:\n"
        "movl -0x38(%ebp), %edi\n" /* line 164 | n, f */
        ".Lf20072c_00200efb:\n"
        "movl 0x175f28a(%ebx), %eax\n" /* line 165 */
        "movl -0x20(%ebp), %edx\n"
        "movl (%eax, %edx, 4), %eax\n"
        "andl -0x40(%ebp), %eax\n" /* b */
        "movl -0x30(%ebp), %ecx\n" /* c */
        "addl %eax, 4(%ecx)\n"
        "movl %edx, %ecx\n" /* line 166 */
        "shrl %cl, -0x40(%ebp)\n" /* b */
        "subl %edx, -0x3c(%ebp)\n" /* k */
        "movl -0x30(%ebp), %eax\n" /* line 167 | c */
        "movzbl 0x11(%eax), %eax\n"
        "movl -0x30(%ebp), %edx\n" /* c */
        "movl %eax, 0xc(%edx)\n"
        "movl 0x18(%edx), %eax\n" /* line 168 */
        "movl %eax, 8(%edx)\n"
        "movl $3, (%edx)\n" /* line 170 */
        "jmp .Lf20072c_00200b2e\n"
        ".Lf20072c_00200f36:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 216 */
        "jmp .Lf20072c_002009ac\n"
        ".Lf20072c_00200f3e:\n"
        "subl -0x1c(%ebp), %eax\n" /* line 207 */
        "movl %eax, -0x34(%ebp)\n" /* m */
        "jmp .Lf20072c_00200c6f\n"
        ".Lf20072c_00200f49:\n"
        "movl $0, -0x48(%ebp)\n" /* line 205 | r */
        "movl -0x30(%ebp), %eax\n" /* c */
        "jmp .Lf20072c_00200d70\n"
        ".Lf20072c_00200f58:\n"
        "testb $0x40, %dl\n" /* line 146 */
        "jne .Lf20072c_00200fea\n"
        "movl -0x30(%ebp), %eax\n" /* line 148 | c */
        "movl %edx, 0xc(%eax)\n"
        "movl 4(%edi), %eax\n" /* line 149 | f */
        "leal (%edi, %eax, 8), %eax\n" /* f */
        "movl -0x30(%ebp), %edx\n" /* c */
        "movl %eax, 8(%edx)\n"
        "jmp .Lf20072c_00200782\n"
        ".Lf20072c_00200f78:\n"
        "movl %edx, -0x2c(%ebp)\n" /* line 173 */
        "movl $0, -0x48(%ebp)\n" /* r */
        "jmp .Lf20072c_00200b43\n"
        ".Lf20072c_00200f87:\n"
        "movl %eax, -0x1c(%ebp)\n" /* line 207 */
        "jmp .Lf20072c_00200a15\n"
        ".Lf20072c_00200f8f:\n"
        "movl 0x2c(%esi), %eax\n" /* line 216 | s */
        "subl %edx, %eax\n"
        "movl %eax, -0x34(%ebp)\n" /* m */
        "jmp .Lf20072c_00200998\n"
        ".Lf20072c_00200f9c:\n"
        "subl -0x1c(%ebp), %edx\n" /* line 207 */
        "movl %edx, -0x34(%ebp)\n" /* m */
        "jmp .Lf20072c_00200a55\n"
        ".Lf20072c_00200fa7:\n"
        "movl 0x30(%esi), %eax\n" /* line 216 | s */
        "movl 0x28(%esi), %edx\n" /* s */
        "cmpl %edx, %eax\n"
        "je .Lf20072c_00201085\n"
        "jbe .Lf20072c_00201078\n"
        "subl %edx, %eax\n"
        "subl $1, %eax\n"
        "movl %eax, -0x34(%ebp)\n" /* m */
        ".Lf20072c_00200fc3:\n"
        "movl -0x34(%ebp), %eax\n" /* m */
        "testl %eax, %eax\n"
        "jne .Lf20072c_002009ac\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl %edx, %eax\n"
        "jmp .Lf20072c_00200965\n"
        ".Lf20072c_00200fd8:\n"
        "movl -0x4c(%ebp), %ecx\n" /* line 196 */
        "movl %ecx, -0x38(%ebp)\n" /* n */
        "movl $0, -0x48(%ebp)\n" /* r */
        "jmp .Lf20072c_00200ec2\n"
        ".Lf20072c_00200fea:\n"
        "andb $0x20, %dl\n" /* line 152 */
        "je .Lf20072c_00201125\n"
        "movl -0x30(%ebp), %ecx\n" /* line 155 | c */
        "movl $7, (%ecx)\n"
        "jmp .Lf20072c_00200782\n"
        ".Lf20072c_00201001:\n"
        "movl %edx, -0x2c(%ebp)\n" /* line 164 */
        "movl $0, -0x48(%ebp)\n" /* r */
        "jmp .Lf20072c_00200efb\n"
        ".Lf20072c_00201010:\n"
        "movl -0x40(%ebp), %edx\n" /* line 207 | b */
        "movl %edx, 0x20(%esi)\n" /* s */
        "movl -0x3c(%ebp), %ecx\n" /* k */
        "movl %ecx, 0x1c(%esi)\n" /* s */
        "movl -0x38(%ebp), %edx\n" /* n */
        "movl -0x44(%ebp), %eax\n" /* z */
        "movl %edx, 4(%eax)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl -0x44(%ebp), %ecx\n" /* z */
        "subl (%ecx), %eax\n"
        "addl %eax, 8(%ecx)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%ecx)\n"
        "movl -0x1c(%ebp), %edx\n"
        "movl %edx, 0x34(%esi)\n" /* s */
        "movl -0x24(%ebp), %ecx\n"
        "movl %ecx, 0x10(%ebp)\n" /* r */
        "movl -0x44(%ebp), %eax\n" /* z */
        "movl %eax, 0xc(%ebp)\n" /* z */
        "jmp .Lf20072c_002007f5\n"
        ".Lf20072c_0020104c:\n"
        "movl 0x28(%esi), %eax\n" /* line 216 | s */
        "cmpl %eax, %ecx\n"
        "je .Lf20072c_002009a1\n"
        "jbe .Lf20072c_0020108d\n"
        "subl %eax, %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x34(%ebp)\n" /* m */
        "movl %eax, %edx\n"
        "jmp .Lf20072c_002009a1\n"
        ".Lf20072c_00201068:\n"
        "movl 0x2c(%esi), %edx\n" /* line 113 | s */
        "movl -0x1c(%ebp), %ecx\n"
        "subl %ecx, %edx\n"
        "movl %edx, -0x34(%ebp)\n" /* m */
        "jmp .Lf20072c_00200e9d\n"
        ".Lf20072c_00201078:\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 216 */
        "subl %edx, %ecx\n"
        "movl %ecx, -0x34(%ebp)\n" /* m */
        "jmp .Lf20072c_00200fc3\n"
        ".Lf20072c_00201085:\n"
        "movl -0x1c(%ebp), %eax\n"
        "jmp .Lf20072c_00200965\n"
        ".Lf20072c_0020108d:\n"
        "subl %eax, %edx\n"
        "movl %edx, -0x34(%ebp)\n" /* m */
        "movl %eax, %edx\n"
        "jmp .Lf20072c_002009a1\n"
        ".Lf20072c_00201099:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 126 */
        "jmp .Lf20072c_0020089a\n"
        ".Lf20072c_002010a1:\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 164 */
        "jmp .Lf20072c_00200c1c\n"
        ".Lf20072c_002010a9:\n"
        "movl -0x30(%ebp), %eax\n" /* line 190 | c */
        "movl $9, (%eax)\n"
        "leal 0xb9e82(%ebx), %eax\n" /* line 191 */
        "movl -0x44(%ebp), %edx\n" /* z */
        "movl %eax, 0x18(%edx)\n"
        "movl -0x40(%ebp), %ecx\n" /* line 193 | b */
        "movl %ecx, 0x20(%esi)\n" /* s */
        "movl -0x3c(%ebp), %eax\n" /* k */
        "movl %eax, 0x1c(%esi)\n" /* s */
        "movl -0x38(%ebp), %ecx\n" /* n */
        "movl %ecx, 4(%edx)\n"
        "movl -0x2c(%ebp), %eax\n"
        "subl (%edx), %eax\n"
        "addl %eax, 8(%edx)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%edx)\n"
        "movl -0x1c(%ebp), %edx\n"
        "movl %edx, 0x34(%esi)\n" /* s */
        "movl $0xfffffffd, 0x10(%ebp)\n" /* r */
        "movl -0x44(%ebp), %ecx\n" /* z */
        "movl %ecx, 0xc(%ebp)\n" /* z */
        "jmp .Lf20072c_002007f5\n"
        ".Lf20072c_002010f5:\n"
        "movl -0x40(%ebp), %ecx\n" /* line 216 | b */
        "movl %ecx, 0x20(%esi)\n" /* s */
        "movl -0x3c(%ebp), %eax\n" /* k */
        "movl %eax, 0x1c(%esi)\n" /* s */
        "movl -0x38(%ebp), %eax\n" /* n */
        "movl -0x44(%ebp), %ecx\n" /* z */
        "movl %eax, 4(%ecx)\n"
        "movl -0x2c(%ebp), %eax\n"
        "subl (%ecx), %eax\n"
        "addl %eax, 8(%ecx)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%ecx)\n"
        "movl %edx, 0x34(%esi)\n" /* s */
        "movl %edi, 0x10(%ebp)\n" /* f, r */
        "movl %ecx, 0xc(%ebp)\n" /* z */
        "jmp .Lf20072c_002007f5\n"
        ".Lf20072c_00201125:\n"
        "movl -0x30(%ebp), %eax\n" /* line 158 | c */
        "movl $9, (%eax)\n"
        "leal 0xb9e66(%ebx), %eax\n" /* line 159 */
        "movl -0x44(%ebp), %edx\n" /* z */
        "movl %eax, 0x18(%edx)\n"
        "movl -0x40(%ebp), %ecx\n" /* line 161 | b */
        "movl %ecx, 0x20(%esi)\n" /* s */
        "movl -0x3c(%ebp), %eax\n" /* k */
        "movl %eax, 0x1c(%esi)\n" /* s */
        "movl -0x38(%ebp), %ecx\n" /* n */
        "movl %ecx, 4(%edx)\n"
        "movl -0x2c(%ebp), %eax\n"
        "subl (%edx), %eax\n"
        "addl %eax, 8(%edx)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%edx)\n"
        "movl -0x1c(%ebp), %edx\n"
        "movl %edx, 0x34(%esi)\n" /* s */
        "movl $0xfffffffd, 0x10(%ebp)\n" /* r */
        "movl -0x44(%ebp), %ecx\n" /* z */
        "jmp .Lf20072c_002007f2\n"
    );
}

/* line 251 */
__attribute__((naked))
short unsigned int inflate_codes_free(inflate_codes_statef *c, z_streamp z)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 251 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %edx\n" /* z */
        "movl 8(%ebp), %eax\n" /* line 252 | c */
        "movl %eax, 0xc(%ebp)\n" /* z */
        "movl 0x28(%edx), %eax\n"
        "movl %eax, 8(%ebp)\n" /* c */
        "movl 0x24(%edx), %ecx\n"
        "popl %ebp\n" /* line 254 */
        "jmpl *%ecx\n" /* line 252 */
    );
}

