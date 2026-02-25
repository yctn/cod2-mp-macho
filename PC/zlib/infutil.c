/* ASM dump from: infutil.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/zlib/infutil.c */

#include "common_types.h"
#include "imports.h"

extern uInt inflate_mask[17]; /* 0x0 */

int inflate_flush(inflate_blocks_statef *s, z_streamp z, int r);

/* line 29 */
__attribute__((naked))
int inflate_flush(inflate_blocks_statef *s, z_streamp z, int r)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 29 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x20, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* line 35 | z */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0xc(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 36 | s */
        "movl 0x30(%edx), %edi\n"
        "movl 0x34(%edx), %eax\n" /* line 39 */
        "cmpl %eax, %edi\n"
        "jbe .Lf201188_002011a9\n"
        "movl 0x2c(%edx), %eax\n"
        ".Lf201188_002011a9:\n"
        "movl %eax, %esi\n" /* n */
        "subl %edi, %esi\n" /* n */
        "movl 0xc(%ebp), %ecx\n" /* line 40 | z */
        "movl 0x10(%ecx), %eax\n"
        "cmpl %eax, %esi\n" /* n */
        "jbe .Lf201188_00201248\n"
        "movl %eax, %esi\n" /* n */
        "xorl %edx, %edx\n"
        ".Lf201188_002011bf:\n"
        "testl %esi, %esi\n" /* line 41 | n */
        "je .Lf201188_002011d3\n"
        "cmpl $-5, 0x10(%ebp)\n" /* r */
        "movl $0, %eax\n"
        "cmovnel 0x10(%ebp), %eax\n" /* r */
        "movl %eax, 0x10(%ebp)\n" /* r */
        ".Lf201188_002011d3:\n"
        "movl 0xc(%ebp), %eax\n" /* line 44 | z */
        "movl %edx, 0x10(%eax)\n"
        "addl %esi, 0x14(%eax)\n" /* line 45 | n */
        "movl 8(%ebp), %ecx\n" /* line 48 | s */
        "movl 0x38(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf201188_00201202\n"
        "movl %esi, 8(%esp)\n" /* line 49 | n */
        "movl %edi, 4(%esp)\n"
        "movl 0x3c(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *%edx\n"
        "movl 8(%ebp), %edx\n" /* s */
        "movl %eax, 0x3c(%edx)\n"
        "movl 0xc(%ebp), %ecx\n" /* z */
        "movl %eax, 0x30(%ecx)\n"
        ".Lf201188_00201202:\n"
        "movl -0xc(%ebp), %edx\n" /* line 53 */
        "testl %edx, %edx\n"
        "je .Lf201188_00201251\n"
        "movl %esi, 8(%esp)\n" /* line 56 | n */
        "movl %edi, 4(%esp)\n"
        "movl -0xc(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl -0xc(%ebp), %edx\n" /* line 57 */
        "addl %esi, %edx\n" /* n */
        "movl %edx, -0x10(%ebp)\n" /* p */
        "leal (%edi, %esi), %eax\n" /* line 61 */
        "movl 8(%ebp), %ecx\n" /* line 64 | s */
        "cmpl 0x2c(%ecx), %eax\n"
        "je .Lf201188_00201263\n"
        ".Lf201188_0020122f:\n"
        "movl -0x10(%ebp), %ecx\n" /* line 98 | p */
        "movl 0xc(%ebp), %edx\n" /* z */
        "movl %ecx, 0xc(%edx)\n"
        "movl 8(%ebp), %edx\n" /* line 99 | s */
        "movl %eax, 0x30(%edx)\n"
        "movl 0x10(%ebp), %eax\n" /* line 103 | r */
        "addl $0x20, %esp\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf201188_00201248:\n"
        "movl %eax, %edx\n" /* line 40 */
        "subl %esi, %edx\n" /* n */
        "jmp .Lf201188_002011bf\n"
        ".Lf201188_00201251:\n"
        "movl $0, -0x10(%ebp)\n" /* line 53 | p */
        "leal (%edi, %esi), %eax\n" /* line 61 */
        "movl 8(%ebp), %ecx\n" /* line 64 | s */
        "cmpl 0x2c(%ecx), %eax\n"
        "jne .Lf201188_0020122f\n"
        ".Lf201188_00201263:\n"
        "movl 0x28(%ecx), %edi\n" /* line 67 */
        "cmpl 0x34(%ecx), %eax\n" /* line 68 */
        "je .Lf201188_0020130e\n"
        ".Lf201188_0020126f:\n"
        "movl 8(%ebp), %eax\n" /* line 72 | s */
        "movl 0x34(%eax), %esi\n" /* n */
        "subl %edi, %esi\n" /* n */
        "movl 0xc(%ebp), %edx\n" /* line 73 | z */
        "movl 0x10(%edx), %eax\n"
        "cmpl %eax, %esi\n" /* n */
        "jbe .Lf201188_00201305\n"
        "movl %eax, %esi\n" /* n */
        "xorl %edx, %edx\n"
        ".Lf201188_00201289:\n"
        "testl %esi, %esi\n" /* line 74 | n */
        "je .Lf201188_0020129d\n"
        "cmpl $-5, 0x10(%ebp)\n" /* r */
        "movl $0, %eax\n"
        "cmovnel 0x10(%ebp), %eax\n" /* r */
        "movl %eax, 0x10(%ebp)\n" /* r */
        ".Lf201188_0020129d:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 77 | z */
        "movl %edx, 0x10(%ecx)\n"
        "addl %esi, 0x14(%ecx)\n" /* line 78 | n */
        "movl 8(%ebp), %eax\n" /* line 81 | s */
        "movl 0x38(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf201188_002012cc\n"
        "movl %esi, 8(%esp)\n" /* line 82 | n */
        "movl %edi, 4(%esp)\n"
        "movl 0x3c(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *%edx\n"
        "movl 8(%ebp), %edx\n" /* s */
        "movl %eax, 0x3c(%edx)\n"
        "movl 0xc(%ebp), %ecx\n" /* z */
        "movl %eax, 0x30(%ecx)\n"
        ".Lf201188_002012cc:\n"
        "movl -0x10(%ebp), %eax\n" /* line 86 | p */
        "testl %eax, %eax\n"
        "je .Lf201188_002012e9\n"
        "movl %esi, 8(%esp)\n" /* line 89 | n */
        "movl %edi, 4(%esp)\n"
        "movl -0x10(%ebp), %eax\n" /* p */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "addl %esi, -0x10(%ebp)\n" /* line 90 | n, p */
        ".Lf201188_002012e9:\n"
        "leal (%edi, %esi), %eax\n" /* line 94 */
        "movl -0x10(%ebp), %ecx\n" /* line 98 | p */
        "movl 0xc(%ebp), %edx\n" /* z */
        "movl %ecx, 0xc(%edx)\n"
        "movl 8(%ebp), %edx\n" /* line 99 | s */
        "movl %eax, 0x30(%edx)\n"
        "movl 0x10(%ebp), %eax\n" /* line 103 | r */
        "addl $0x20, %esp\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf201188_00201305:\n"
        "movl %eax, %edx\n" /* line 73 */
        "subl %esi, %edx\n" /* n */
        "jmp .Lf201188_00201289\n"
        ".Lf201188_0020130e:\n"
        "movl %edi, 0x34(%ecx)\n" /* line 69 */
        "jmp .Lf201188_0020126f\n"
    );
}

