/* ASM dump from: adler32.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/zlib/adler32.c */

#include "common_types.h"
#include "imports.h"

uLong adler32(uLong adler, const Bytef *buf, uInt len);

/* line 27 */
__attribute__((naked))
uLong adler32(uLong adler, const Bytef *buf, uInt len)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 27 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $8, %esp\n"
        "movl 8(%ebp), %eax\n" /* adler */
        "movl 0xc(%ebp), %esi\n" /* buf */
        "movzwl %ax, %edi\n" /* line 28 | s1 */
        "shrl $0x10, %eax\n" /* line 29 */
        "movl %eax, -0xc(%ebp)\n"
        "testl %esi, %esi\n" /* line 32 | buf */
        "je .Lf1f90c8_001f921f\n"
        "movl 0x10(%ebp), %eax\n" /* line 34 | len */
        "testl %eax, %eax\n"
        "je .Lf1f90c8_001f9210\n"
        ".Lf1f90c8_001f90f2:\n"
        "cmpl $0x15b1, 0x10(%ebp)\n" /* line 35 | len */
        "movl $0x15b0, %eax\n"
        "cmovbl 0x10(%ebp), %eax\n" /* len */
        "movl %eax, -0x10(%ebp)\n" /* k */
        "subl %eax, 0x10(%ebp)\n" /* line 36 | len */
        "cmpl $0xf, %eax\n" /* line 37 */
        "jle .Lf1f90c8_001f91ad\n"
        "movl -0xc(%ebp), %ecx\n"
        "jmp .Lf1f90c8_001f9118\n"
        ".Lf1f90c8_001f9116:\n"
        "movl %edx, %ecx\n"
        ".Lf1f90c8_001f9118:\n"
        "movzbl (%esi), %eax\n" /* line 38 | buf */
        "addl %edi, %eax\n"
        "leal (%eax, %ecx), %edx\n"
        "movzbl 1(%esi), %ecx\n" /* buf */
        "addl %ecx, %eax\n"
        "addl %eax, %edx\n"
        "movzbl 2(%esi), %ecx\n" /* buf */
        "addl %ecx, %eax\n"
        "addl %eax, %edx\n"
        "movzbl 3(%esi), %ecx\n" /* buf */
        "addl %ecx, %eax\n"
        "addl %eax, %edx\n"
        "movzbl 4(%esi), %ecx\n" /* buf */
        "addl %ecx, %eax\n"
        "addl %eax, %edx\n"
        "movzbl 5(%esi), %ecx\n" /* buf */
        "addl %ecx, %eax\n"
        "addl %eax, %edx\n"
        "movzbl 6(%esi), %ecx\n" /* buf */
        "addl %ecx, %eax\n"
        "addl %eax, %edx\n"
        "movzbl 7(%esi), %ecx\n" /* buf */
        "addl %ecx, %eax\n"
        "addl %eax, %edx\n"
        "movzbl 8(%esi), %ecx\n" /* buf */
        "addl %ecx, %eax\n"
        "addl %eax, %edx\n"
        "movzbl 9(%esi), %ecx\n" /* buf */
        "addl %ecx, %eax\n"
        "addl %eax, %edx\n"
        "movzbl 0xa(%esi), %ecx\n" /* buf */
        "addl %ecx, %eax\n"
        "addl %eax, %edx\n"
        "movzbl 0xb(%esi), %ecx\n" /* buf */
        "addl %ecx, %eax\n"
        "addl %eax, %edx\n"
        "movzbl 0xc(%esi), %ecx\n" /* buf */
        "addl %ecx, %eax\n"
        "addl %eax, %edx\n"
        "movzbl 0xd(%esi), %ecx\n" /* buf */
        "addl %ecx, %eax\n"
        "addl %eax, %edx\n"
        "movzbl 0xe(%esi), %ecx\n" /* buf */
        "addl %ecx, %eax\n"
        "addl %eax, %edx\n"
        "movzbl 0xf(%esi), %ecx\n" /* buf */
        "leal (%eax, %ecx), %edi\n"
        "addl %edi, %edx\n"
        "movl %edx, -0xc(%ebp)\n"
        "addl $0x10, %esi\n" /* line 39 | buf */
        "subl $0x10, -0x10(%ebp)\n" /* line 40 | k */
        "cmpl $0xf, -0x10(%ebp)\n" /* line 37 | k */
        "jg .Lf1f90c8_001f9116\n"
        ".Lf1f90c8_001f91ad:\n"
        "movl -0x10(%ebp), %edx\n" /* line 42 | k */
        "testl %edx, %edx\n"
        "je .Lf1f90c8_001f91cd\n"
        "movl %esi, %edx\n" /* buf */
        "movl -0x10(%ebp), %eax\n" /* k */
        "leal (%eax, %esi), %ecx\n"
        ".Lf1f90c8_001f91bc:\n"
        "movzbl (%edx), %eax\n" /* line 43 */
        "addl %eax, %edi\n"
        "addl $1, %edx\n"
        "addl %edi, -0xc(%ebp)\n" /* line 44 */
        "cmpl %edx, %ecx\n" /* line 45 */
        "jne .Lf1f90c8_001f91bc\n"
        "movl %ecx, %esi\n" /* buf */
        ".Lf1f90c8_001f91cd:\n"
        "movl $0x80078071, %eax\n" /* line 46 */
        "mull %edi\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "movl %edx, %eax\n"
        "shll $0x10, %eax\n"
        "subl %ecx, %eax\n"
        "addl %edx, %eax\n"
        "subl %eax, %edi\n"
        "movl $0x80078071, %eax\n" /* line 47 */
        "mull -0xc(%ebp)\n"
        "movl %edx, %ecx\n"
        "shrl $0xf, %ecx\n"
        "movl %ecx, %edx\n"
        "shll $4, %edx\n"
        "movl %ecx, %eax\n"
        "shll $0x10, %eax\n"
        "subl %edx, %eax\n"
        "addl %ecx, %eax\n"
        "subl %eax, -0xc(%ebp)\n"
        "movl 0x10(%ebp), %eax\n" /* line 34 | len */
        "testl %eax, %eax\n"
        "jne .Lf1f90c8_001f90f2\n"
        ".Lf1f90c8_001f9210:\n"
        "movl -0xc(%ebp), %eax\n" /* line 49 */
        "shll $0x10, %eax\n"
        "orl %edi, %eax\n"
        "addl $8, %esp\n" /* line 50 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1f90c8_001f921f:\n"
        "movl $1, %eax\n" /* line 32 */
        "addl $8, %esp\n" /* line 50 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

