/* ASM dump from: infblock.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/zlib/infblock.c */

#include "common_types.h"
#include "imports.h"

static const uInt border[19]; /* 0x306ec0 */

void inflate_blocks_reset(inflate_blocks_statef *s, z_streamp z, uLongf *c);
int inflate_blocks(inflate_blocks_statef *s, z_streamp z, int r);
inflate_blocks_statef * inflate_blocks_new(z_streamp z, check_func c, uInt w);
int inflate_blocks_free(inflate_blocks_statef *s, z_streamp z);

/* line 75 */
__attribute__((naked))
void inflate_blocks_reset(inflate_blocks_statef *s, z_streamp z, uLongf *c)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 75 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* s */
        "movl 0xc(%ebp), %edi\n" /* z */
        "movl 0x10(%ebp), %edx\n" /* c */
        "testl %edx, %edx\n" /* line 76 */
        "je .Lf1f922c_001f9246\n"
        "movl 0x3c(%esi), %eax\n" /* line 77 | s */
        "movl %eax, (%edx)\n"
        ".Lf1f922c_001f9246:\n"
        "movl (%esi), %eax\n" /* line 78 | s */
        "subl $4, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf1f922c_001f92b0\n"
        ".Lf1f922c_001f9250:\n"
        "cmpl $6, (%esi)\n" /* line 80 | s */
        "je .Lf1f922c_001f929f\n"
        ".Lf1f922c_001f9255:\n"
        "movl $0, (%esi)\n" /* line 82 | s */
        "movl $0, 0x1c(%esi)\n" /* line 83 | s */
        "movl $0, 0x20(%esi)\n" /* line 84 | s */
        "movl 0x28(%esi), %eax\n" /* line 85 | s */
        "movl %eax, 0x34(%esi)\n" /* s */
        "movl %eax, 0x30(%esi)\n" /* s */
        "movl 0x38(%esi), %eax\n" /* line 86 | s */
        "testl %eax, %eax\n"
        "je .Lf1f922c_001f9298\n"
        "movl $0, 8(%esp)\n" /* line 87 */
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll *%eax\n"
        "movl %eax, 0x3c(%esi)\n" /* s */
        "movl %eax, 0x30(%edi)\n" /* z */
        ".Lf1f922c_001f9298:\n"
        "addl $0x10, %esp\n" /* line 89 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1f922c_001f929f:\n"
        "movl %edi, 4(%esp)\n" /* line 81 | z */
        "movl 4(%esi), %eax\n" /* s */
        "movl %eax, (%esp)\n"
        "calll inflate_codes_free\n"
        "jmp .Lf1f922c_001f9255\n"
        ".Lf1f922c_001f92b0:\n"
        "movl 0xc(%esi), %eax\n" /* line 79 | s */
        "movl %eax, 4(%esp)\n"
        "movl 0x28(%edi), %eax\n" /* z */
        "movl %eax, (%esp)\n"
        "calll *0x24(%edi)\n" /* z */
        "jmp .Lf1f922c_001f9250\n"
    );
}

/* line 127 */
__attribute__((naked))
int inflate_blocks(inflate_blocks_statef *s, z_streamp z, int r)
{
    __asm__ __volatile__ (
        /* { scope 1: i, j, c, bl, ... */
        "pushl %ebp\n" /* line 127 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 0xc(%ebp), %eax\n" /* line 137 | z */
        "movl (%eax), %eax\n"
        "movl %eax, -0x64(%ebp)\n" /* p */
        "movl 0xc(%ebp), %edx\n" /* z */
        "movl 4(%edx), %edx\n"
        "movl %edx, -0x60(%ebp)\n" /* n */
        "movl 8(%ebp), %ecx\n" /* s */
        "movl 0x20(%ecx), %ecx\n"
        "movl %ecx, -0x34(%ebp)\n"
        "movl 8(%ebp), %esi\n" /* s, t */
        "movl 0x1c(%esi), %edi\n" /* t */
        "movl 0x34(%esi), %eax\n" /* t */
        "movl %eax, -0x5c(%ebp)\n" /* q */
        "movl 0x30(%esi), %eax\n" /* t */
        "cmpl %eax, -0x5c(%ebp)\n" /* q */
        "jae .Lf1f92c2_001f9395\n"
        "subl -0x5c(%ebp), %eax\n" /* q */
        "subl $1, %eax\n"
        "movl %eax, -0x58(%ebp)\n" /* m */
        ".Lf1f92c2_001f930e:\n"
        "movl 8(%ebp), %eax\n" /* line 140 | s */
        "cmpl $9, (%eax)\n"
        "ja .Lf1f92c2_001f934c\n"
        "movl (%eax), %eax\n"
        "movl 0x51(%ebx, %eax, 4), %eax\n"
        "addl %ebx, %eax\n"
        "jmpl *%eax\n"
        "nop\n"
        "hlt\n"
        "addb $0, %al\n"
        "addb %bl, 4(%ebp)\n"
        "addb %al, (%eax)\n"
        "movb %al, 0x5f000003\n"
        "addl %eax, (%eax)\n"
        "addb %ah, (%edi)\n"
        "addb (%eax), %al\n"
        "addb %cl, 0x2e40000(%ebp, %eax)\n"
        "addb %al, (%eax)\n"
        "filds (%eax)\n"
        "addb %al, (%eax)\n"
        "sbbl (%ecx), %eax\n"
        "addb %al, (%eax)\n"
        "jecxz .Lf1f92c2_001f934b\n"
        "addb %al, (%eax)\n"
        ".Lf1f92c2_001f934b:\n"
        ".Lf1f92c2_001f934c:\n"
        "movl %eax, %edx\n"
        "movl -0x34(%ebp), %eax\n" /* line 370 */
        "movl %eax, 0x20(%edx)\n"
        "movl %edi, 0x1c(%edx)\n"
        "movl -0x60(%ebp), %esi\n" /* n, t */
        "movl 0xc(%ebp), %ecx\n" /* z */
        "movl %esi, 4(%ecx)\n" /* t */
        "movl -0x64(%ebp), %eax\n" /* p */
        "subl (%ecx), %eax\n"
        "addl %eax, 8(%ecx)\n"
        "movl -0x64(%ebp), %eax\n" /* p */
        "movl %eax, (%ecx)\n"
        "movl -0x5c(%ebp), %ecx\n" /* q */
        "movl %ecx, 0x34(%edx)\n"
        "movl $0xfffffffe, 8(%esp)\n"
        "movl 0xc(%ebp), %esi\n" /* z, t */
        "movl %esi, 4(%esp)\n" /* t */
        "movl %edx, (%esp)\n"
        "calll inflate_flush\n"
        ".Lf1f92c2_001f938a:\n"
        "addl $0xbc, %esp\n" /* line 372 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1f92c2_001f9395:\n"
        "movl 0x2c(%esi), %edx\n" /* line 137 | t */
        "movl -0x5c(%ebp), %ecx\n" /* q */
        "subl %ecx, %edx\n"
        "movl %edx, -0x58(%ebp)\n" /* m */
        "jmp .Lf1f92c2_001f930e\n"
        ".Lf1f92c2_001f93a5:\n"
        "movl $7, (%edx)\n" /* line 356 */
        "movl $0, 0x10(%ebp)\n" /* r */
        "movl -0x5c(%ebp), %esi\n" /* line 358 | q, t */
        "movl 8(%ebp), %ecx\n" /* s */
        "movl %esi, 0x34(%ecx)\n" /* t */
        "movl 0x10(%ebp), %eax\n" /* r */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* z */
        "movl %edx, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll inflate_flush\n"
        "movl %eax, %edx\n"
        "movl 8(%ebp), %ecx\n" /* s */
        "movl 0x34(%ecx), %ecx\n"
        "movl %ecx, -0x5c(%ebp)\n" /* q */
        "movl 8(%ebp), %esi\n" /* line 359 | s, t */
        "cmpl 0x30(%esi), %ecx\n" /* t */
        "jne .Lf1f92c2_001f9b43\n"
        "movl $8, (%esi)\n" /* line 361 | t */
        "movl -0x34(%ebp), %eax\n" /* line 364 */
        "movl 8(%ebp), %edx\n" /* s */
        "movl %eax, 0x20(%edx)\n"
        "movl %edi, 0x1c(%edx)\n"
        "movl -0x60(%ebp), %esi\n" /* n, t */
        "movl 0xc(%ebp), %ecx\n" /* z */
        "movl %esi, 4(%ecx)\n" /* t */
        "movl -0x64(%ebp), %eax\n" /* p */
        "subl (%ecx), %eax\n"
        "addl %eax, 8(%ecx)\n"
        "movl -0x64(%ebp), %eax\n" /* p */
        "movl %eax, (%ecx)\n"
        "movl -0x5c(%ebp), %ecx\n" /* q */
        "movl %ecx, 0x34(%edx)\n"
        "movl $1, 8(%esp)\n"
        "movl 0xc(%ebp), %esi\n" /* z, t */
        "movl %esi, 4(%esp)\n" /* t */
        "movl %edx, (%esp)\n"
        "calll inflate_flush\n"
        "jmp .Lf1f92c2_001f938a\n"
        "cmpl $0xd, %edi\n" /* line 220 */
        "jbe .Lf1f92c2_001f9bdf\n"
        "movl -0x64(%ebp), %ecx\n" /* p */
        "movl %ecx, -0x40(%ebp)\n"
        "movl -0x60(%ebp), %esi\n" /* n, t */
        "movl %esi, -0x3c(%ebp)\n" /* t */
        ".Lf1f92c2_001f9447:\n"
        "movl -0x34(%ebp), %eax\n" /* line 221 */
        "andl $0x3fff, %eax\n"
        "movl 8(%ebp), %edx\n" /* s */
        "movl %eax, 4(%edx)\n"
        "movl -0x34(%ebp), %edx\n" /* line 223 */
        "andl $0x1f, %edx\n"
        "cmpl $0x1d, %edx\n"
        "ja .Lf1f92c2_001f9fd4\n"
        "shrl $5, %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0x1d, %eax\n"
        "ja .Lf1f92c2_001f9fd4\n"
        "movl $4, 8(%esp)\n" /* line 232 */
        "leal 0x102(%edx, %eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* z */
        "movl 0x28(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x20(%ecx)\n"
        "movl 8(%ebp), %esi\n" /* s, t */
        "movl %eax, 0xc(%esi)\n" /* t */
        "testl %eax, %eax\n"
        "je .Lf1f92c2_001fa0ba\n"
        "shrl $0xe, -0x34(%ebp)\n" /* line 237 */
        "subl $0xe, %edi\n"
        "movl $0, 8(%esi)\n" /* line 238 | t */
        "movl $4, (%esi)\n" /* line 240 | t */
        "jmp .Lf1f92c2_001f9506\n"
        "movl -0x34(%ebp), %eax\n" /* line 367 */
        "movl 8(%ebp), %edx\n" /* s */
        "movl %eax, 0x20(%edx)\n"
        "movl %edi, 0x1c(%edx)\n"
        "movl -0x60(%ebp), %esi\n" /* n, t */
        "movl 0xc(%ebp), %ecx\n" /* z */
        "movl %esi, 4(%ecx)\n" /* t */
        "movl -0x64(%ebp), %eax\n" /* p */
        "subl (%ecx), %eax\n"
        "addl %eax, 8(%ecx)\n"
        "movl -0x64(%ebp), %eax\n" /* p */
        "movl %eax, (%ecx)\n"
        "movl -0x5c(%ebp), %ecx\n" /* q */
        ".Lf1f92c2_001f94db:\n"
        "movl %ecx, 0x34(%edx)\n"
        "movl $0xfffffffd, 8(%esp)\n"
        "movl 0xc(%ebp), %esi\n" /* z, t */
        "movl %esi, 4(%esp)\n" /* t */
        "movl %edx, (%esp)\n"
        "calll inflate_flush\n"
        "jmp .Lf1f92c2_001f938a\n"
        "movl -0x64(%ebp), %ecx\n" /* line 140 | p */
        "movl %ecx, -0x40(%ebp)\n"
        "movl -0x60(%ebp), %esi\n" /* n, t */
        "movl %esi, -0x3c(%ebp)\n" /* t */
        ".Lf1f92c2_001f9506:\n"
        "movl 8(%ebp), %eax\n" /* line 242 | s */
        "movl 8(%eax), %edx\n"
        "movl %edx, -0x70(%ebp)\n"
        "movl 4(%eax), %eax\n"
        "shrl $0xa, %eax\n"
        "addl $4, %eax\n"
        "cmpl %edx, %eax\n"
        "jbe .Lf1f92c2_001f994c\n"
        "leal 0x10dbed(%ebx, %edx, 4), %edx\n"
        "movl %edx, -0x48(%ebp)\n"
        ".Lf1f92c2_001f952a:\n"
        "cmpl $2, %edi\n" /* line 244 */
        "ja .Lf1f92c2_001f990d\n"
        "movl -0x3c(%ebp), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf1f92c2_001f9e84\n"
        "movl -0x40(%ebp), %edx\n"
        "movl -0x3c(%ebp), %esi\n" /* t */
        ".Lf1f92c2_001f9544:\n"
        "subl $1, %esi\n" /* t */
        "movzbl (%edx), %eax\n"
        "movl %edi, %ecx\n"
        "shll %cl, %eax\n"
        "orl %eax, -0x34(%ebp)\n"
        "addl $1, %edx\n"
        "addl $8, %edi\n"
        "cmpl $2, %edi\n"
        "ja .Lf1f92c2_001f9900\n"
        "movl -0x3c(%ebp), %ecx\n" /* line 127 */
        "addl -0x40(%ebp), %ecx\n"
        "cmpl %edx, %ecx\n" /* line 244 */
        "jne .Lf1f92c2_001f9544\n"
        /* { scope 2 */
        ".Lf1f92c2_001f956a:\n"
        "movl $0, 0x10(%ebp)\n" /* line 287 | r */
        ".Lf1f92c2_001f9571:\n"
        "movl -0x34(%ebp), %eax\n"
        "movl 8(%ebp), %edx\n" /* s */
        "movl %eax, 0x20(%edx)\n"
        "movl %edi, 0x1c(%edx)\n"
        "movl 0xc(%ebp), %esi\n" /* z, t */
        "movl $0, 4(%esi)\n" /* t */
        "movl %ecx, %eax\n"
        "subl (%esi), %eax\n" /* t */
        "addl %eax, 8(%esi)\n" /* t */
        "movl %ecx, (%esi)\n" /* t */
        "movl -0x5c(%ebp), %eax\n" /* q */
        "movl %eax, 0x34(%edx)\n"
        "movl 0x10(%ebp), %edx\n" /* r */
        "movl %edx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* t */
        "movl 8(%ebp), %ecx\n" /* s */
        "movl %ecx, (%esp)\n"
        "calll inflate_flush\n"
        /* } scope */
        "addl $0xbc, %esp\n" /* line 372 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl -0x64(%ebp), %ecx\n" /* line 140 | p */
        "movl %ecx, -0x40(%ebp)\n"
        "movl -0x60(%ebp), %esi\n" /* n, t */
        "movl %esi, -0x3c(%ebp)\n" /* t */
        ".Lf1f92c2_001f95c3:\n"
        "movl -0x34(%ebp), %ecx\n" /* line 342 */
        "movl 8(%ebp), %esi\n" /* s, t */
        "movl %ecx, 0x20(%esi)\n" /* t */
        "movl %edi, 0x1c(%esi)\n" /* t */
        "movl -0x3c(%ebp), %edx\n"
        "movl 0xc(%ebp), %eax\n" /* z */
        "movl %edx, 4(%eax)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl 0xc(%ebp), %ecx\n" /* z */
        "subl (%ecx), %eax\n"
        "addl %eax, 8(%ecx)\n"
        "movl -0x40(%ebp), %esi\n" /* t */
        "movl %esi, (%ecx)\n" /* t */
        "movl -0x5c(%ebp), %edx\n" /* q */
        "movl 8(%ebp), %eax\n" /* s */
        "movl %edx, 0x34(%eax)\n"
        "movl 0x10(%ebp), %ecx\n" /* line 343 | r */
        "movl %ecx, 8(%esp)\n"
        "movl 0xc(%ebp), %esi\n" /* z, t */
        "movl %esi, 4(%esp)\n" /* t */
        "movl %eax, (%esp)\n"
        "calll inflate_codes\n"
        "cmpl $1, %eax\n"
        "jne .Lf1f92c2_001fa05b\n"
        "movl %esi, 4(%esp)\n" /* line 346 | t */
        "movl 8(%ebp), %edx\n" /* s */
        "movl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll inflate_codes_free\n"
        "movl (%esi), %ecx\n" /* line 347 | t */
        "movl %ecx, -0x64(%ebp)\n" /* p */
        "movl 4(%esi), %esi\n" /* t */
        "movl %esi, -0x60(%ebp)\n" /* t, n */
        "movl 8(%ebp), %eax\n" /* s */
        "movl 0x20(%eax), %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* s */
        "movl 0x1c(%edx), %edi\n"
        "movl 0x34(%edx), %ecx\n"
        "movl %ecx, -0x5c(%ebp)\n" /* q */
        "movl 0x30(%edx), %eax\n"
        "cmpl %ecx, %eax\n"
        "jbe .Lf1f92c2_001f9b86\n"
        "subl %ecx, %eax\n"
        "subl $1, %eax\n"
        "movl %eax, -0x58(%ebp)\n" /* m */
        ".Lf1f92c2_001f9655:\n"
        "movl 8(%ebp), %edx\n" /* line 351 | s */
        "movl 0x18(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1f92c2_001f93a5\n"
        "movl $0, (%edx)\n" /* line 353 */
        "movl $0, 0x10(%ebp)\n" /* r */
        "jmp .Lf1f92c2_001f930e\n"
        "movl -0x60(%ebp), %ecx\n" /* line 203 | n */
        "testl %ecx, %ecx\n"
        "je .Lf1f92c2_001fa076\n"
        "movl -0x58(%ebp), %edx\n" /* line 205 | m */
        "testl %edx, %edx\n"
        "jne .Lf1f92c2_001f99ac\n"
        "movl -0x5c(%ebp), %ecx\n" /* q */
        "movl 8(%ebp), %edx\n" /* s */
        "cmpl 0x2c(%edx), %ecx\n"
        "je .Lf1f92c2_001f9e2a\n"
        ".Lf1f92c2_001f969a:\n"
        "movl %ecx, 0x34(%edx)\n"
        "movl 0x10(%ebp), %esi\n" /* r, t */
        "movl %esi, 8(%esp)\n" /* t */
        "movl 0xc(%ebp), %eax\n" /* z */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll inflate_flush\n"
        "movl %eax, %esi\n" /* t */
        "movl 8(%ebp), %ecx\n" /* s */
        "movl 0x34(%ecx), %edx\n"
        "movl 0x30(%ecx), %ecx\n"
        "cmpl %ecx, %edx\n"
        "jae .Lf1f92c2_001f9dac\n"
        "movl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "subl $1, %eax\n"
        "movl %eax, -0x58(%ebp)\n" /* m */
        ".Lf1f92c2_001f96d0:\n"
        "movl 8(%ebp), %eax\n" /* s */
        "cmpl 0x2c(%eax), %edx\n"
        "je .Lf1f92c2_001f9d27\n"
        ".Lf1f92c2_001f96dc:\n"
        "movl %edx, -0x5c(%ebp)\n" /* q */
        ".Lf1f92c2_001f96df:\n"
        "movl -0x58(%ebp), %eax\n" /* m */
        "testl %eax, %eax\n"
        "jne .Lf1f92c2_001f99ac\n"
        "movl -0x34(%ebp), %edx\n"
        "movl 8(%ebp), %ecx\n" /* s */
        "movl %edx, 0x20(%ecx)\n"
        "movl %edi, 0x1c(%ecx)\n"
        "movl -0x60(%ebp), %edx\n" /* n */
        "movl 0xc(%ebp), %eax\n" /* z */
        "movl %edx, 4(%eax)\n"
        "movl -0x64(%ebp), %eax\n" /* p */
        "movl 0xc(%ebp), %ecx\n" /* z */
        "subl (%ecx), %eax\n"
        "addl %eax, 8(%ecx)\n"
        "movl -0x64(%ebp), %eax\n" /* p */
        ".Lf1f92c2_001f970d:\n"
        "movl %eax, (%ecx)\n" /* line 261 */
        "movl -0x5c(%ebp), %ecx\n" /* q */
        "movl 8(%ebp), %edx\n" /* s */
        "movl %ecx, 0x34(%edx)\n"
        "movl %esi, 8(%esp)\n" /* t */
        "movl 0xc(%ebp), %esi\n" /* z, t */
        "movl %esi, 4(%esp)\n" /* t */
        "movl %edx, (%esp)\n"
        "calll inflate_flush\n"
        "jmp .Lf1f92c2_001f938a\n"
        "cmpl $0x1f, %edi\n" /* line 189 */
        "ja .Lf1f92c2_001f9b93\n"
        "movl -0x60(%ebp), %edx\n" /* n */
        "testl %edx, %edx\n"
        "je .Lf1f92c2_001fa151\n"
        "movl -0x60(%ebp), %esi\n" /* n, t */
        "movl -0x64(%ebp), %edx\n" /* p */
        "movl %edx, -0x80(%ebp)\n"
        "movl %edx, %ecx\n"
        "jmp .Lf1f92c2_001f9754\n"
        ".Lf1f92c2_001f9751:\n"
        "movl -0x80(%ebp), %ecx\n"
        ".Lf1f92c2_001f9754:\n"
        "subl $1, %esi\n" /* t */
        "movzbl (%ecx), %eax\n"
        "movl %edi, %ecx\n"
        "shll %cl, %eax\n"
        "orl %eax, -0x34(%ebp)\n"
        "addl $1, -0x80(%ebp)\n"
        "addl $8, %edi\n"
        "cmpl $0x1f, %edi\n"
        "ja .Lf1f92c2_001f9e6c\n"
        "movl -0x64(%ebp), %eax\n" /* p */
        "addl -0x60(%ebp), %eax\n" /* n */
        "cmpl %eax, -0x80(%ebp)\n"
        "jne .Lf1f92c2_001f9751\n"
        "movl $0, 0x10(%ebp)\n" /* r */
        ".Lf1f92c2_001f9783:\n"
        "movl -0x34(%ebp), %eax\n"
        "movl 8(%ebp), %edx\n" /* s */
        "movl %eax, 0x20(%edx)\n"
        "movl %edi, 0x1c(%edx)\n"
        "movl 0xc(%ebp), %ecx\n" /* z */
        "movl $0, 4(%ecx)\n"
        "movl -0x80(%ebp), %eax\n"
        "subl (%ecx), %eax\n"
        "addl %eax, 8(%ecx)\n"
        "movl -0x80(%ebp), %esi\n" /* t */
        ".Lf1f92c2_001f97a4:\n"
        "movl %esi, (%ecx)\n" /* t */
        "movl -0x5c(%ebp), %eax\n" /* q */
        "movl %eax, 0x34(%edx)\n"
        "movl 0x10(%ebp), %edx\n" /* r */
        "movl %edx, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* s */
        "movl %ecx, (%esp)\n"
        "calll inflate_flush\n"
        "jmp .Lf1f92c2_001f938a\n"
        "cmpl $2, %edi\n" /* line 143 */
        "jbe .Lf1f92c2_001f9c6a\n"
        ".Lf1f92c2_001f97d0:\n"
        "movl -0x34(%ebp), %eax\n" /* line 145 */
        "andl $1, %eax\n"
        "movl 8(%ebp), %esi\n" /* s, t */
        "movl %eax, 0x18(%esi)\n" /* t */
        "movl -0x34(%ebp), %eax\n" /* line 146 */
        "andl $7, %eax\n"
        "shrl $1, %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf1f92c2_001f9dbc\n"
        "jb .Lf1f92c2_001f9d8b\n"
        "cmpl $2, %eax\n"
        "je .Lf1f92c2_001f9e96\n"
        "cmpl $3, %eax\n"
        "jne .Lf1f92c2_001f930e\n"
        "movl 8(%ebp), %edx\n" /* line 182 | s */
        "movl $9, (%edx)\n"
        "leal 0xc1259(%ebx), %eax\n" /* line 183 */
        "movl 0xc(%ebp), %ecx\n" /* z */
        "movl %eax, 0x18(%ecx)\n"
        "shrl $3, -0x34(%ebp)\n" /* line 185 */
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, 0x20(%edx)\n"
        "leal -3(%edi), %eax\n"
        "movl %eax, 0x1c(%edx)\n"
        "movl -0x60(%ebp), %edx\n" /* n */
        "movl %edx, 4(%ecx)\n"
        "movl -0x64(%ebp), %eax\n" /* p */
        "subl (%ecx), %eax\n"
        "addl %eax, 8(%ecx)\n"
        "movl -0x64(%ebp), %esi\n" /* p, t */
        "movl %esi, (%ecx)\n" /* t */
        "movl -0x5c(%ebp), %edx\n" /* q */
        "movl 8(%ebp), %eax\n" /* s */
        "movl %edx, 0x34(%eax)\n"
        "movl $0xfffffffd, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll inflate_flush\n"
        "jmp .Lf1f92c2_001f938a\n"
        "movl -0x64(%ebp), %eax\n" /* line 140 | p */
        "movl %eax, -0x40(%ebp)\n"
        "movl -0x60(%ebp), %edx\n" /* n */
        "movl %edx, -0x3c(%ebp)\n"
        ".Lf1f92c2_001f986b:\n"
        "movl 8(%ebp), %esi\n" /* line 267 | s, t */
        "movl 4(%esi), %eax\n" /* t */
        "movl 8(%esi), %edx\n" /* t */
        "movl %edx, -0x54(%ebp)\n" /* i */
        "movl %eax, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl %eax, %edx\n"
        "shrl $5, %edx\n"
        "andl $0x1f, %edx\n"
        "leal 0x102(%ecx, %edx), %esi\n" /* t */
        "movl %esi, -0x68(%ebp)\n" /* t */
        "cmpl %esi, -0x54(%ebp)\n" /* t, i */
        "jae .Lf1f92c2_001f9eab\n"
        /* { scope 2 */
        "movl 8(%ebp), %edx\n" /* line 273 | s */
        "movl 0x10(%edx), %esi\n" /* t */
        "cmpl %edi, %esi\n" /* line 274 | t */
        "ja .Lf1f92c2_001f9a17\n"
        "movl -0x3c(%ebp), %ecx\n"
        "movl %ecx, -0x38(%ebp)\n"
        ".Lf1f92c2_001f98ab:\n"
        "movl -0x34(%ebp), %eax\n" /* line 275 */
        "movl 0x17666f1(%ebx), %edx\n"
        "andl (%edx, %esi, 4), %eax\n"
        "movl 8(%ebp), %ecx\n" /* s */
        "movl 0x14(%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movzbl 1(%eax), %esi\n" /* line 276 | t */
        "movl %esi, -0x44(%ebp)\n" /* t */
        "movl 4(%eax), %eax\n" /* line 277 */
        "movl %eax, -0x2c(%ebp)\n"
        "cmpl $0xf, %eax\n" /* line 278 */
        "ja .Lf1f92c2_001f9a56\n"
        "movl %esi, %ecx\n" /* line 280 | t */
        "shrl %cl, -0x34(%ebp)\n"
        "subl %esi, %edi\n" /* t */
        "movl 8(%ebp), %esi\n" /* line 281 | s, t */
        "movl 0xc(%esi), %eax\n" /* t */
        "movl -0x2c(%ebp), %ecx\n"
        "movl -0x54(%ebp), %edx\n" /* i */
        "movl %ecx, (%eax, %edx, 4)\n"
        "movl -0x54(%ebp), %edx\n" /* i */
        "addl $1, %edx\n"
        "movl %edx, 8(%esi)\n" /* t */
        ".Lf1f92c2_001f98f5:\n"
        "movl -0x38(%ebp), %ecx\n" /* line 306 */
        "movl %ecx, -0x3c(%ebp)\n"
        "jmp .Lf1f92c2_001f986b\n"
        /* } scope */
        ".Lf1f92c2_001f9900:\n"
        "movl %edx, -0x40(%ebp)\n" /* line 244 */
        "movl %esi, -0x3c(%ebp)\n" /* t */
        "movl $0, 0x10(%ebp)\n" /* r */
        ".Lf1f92c2_001f990d:\n"
        "movl -0x48(%ebp), %esi\n" /* line 245 | t */
        "movl (%esi), %ecx\n" /* t */
        "movl 8(%ebp), %eax\n" /* s */
        "movl 0xc(%eax), %edx\n"
        "movl -0x34(%ebp), %eax\n"
        "andl $7, %eax\n"
        "movl %eax, (%edx, %ecx, 4)\n"
        "addl $1, -0x70(%ebp)\n"
        "movl -0x70(%ebp), %edx\n"
        "movl 8(%ebp), %ecx\n" /* s */
        "movl %edx, 8(%ecx)\n"
        "shrl $3, -0x34(%ebp)\n" /* line 246 */
        "subl $3, %edi\n"
        "addl $4, %esi\n" /* t */
        "movl %esi, -0x48(%ebp)\n" /* t */
        "movl 4(%ecx), %eax\n" /* line 242 */
        "shrl $0xa, %eax\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n"
        "jb .Lf1f92c2_001f952a\n"
        ".Lf1f92c2_001f994c:\n"
        "movl %edx, %esi\n" /* line 248 | t */
        "cmpl $0x12, %edx\n"
        "jbe .Lf1f92c2_001f9cd5\n"
        ".Lf1f92c2_001f9957:\n"
        "movl 8(%ebp), %edx\n" /* line 250 | s */
        "movl $7, 0x10(%edx)\n"
        "movl 0xc(%ebp), %ecx\n" /* line 251 | z */
        "movl %ecx, 0x10(%esp)\n"
        "movl 0x24(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, %eax\n"
        "addl $0x14, %eax\n"
        "movl %eax, 8(%esp)\n"
        "subl $4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll inflate_trees_bits\n"
        "movl %eax, %esi\n" /* t */
        "testl %eax, %eax\n" /* line 253 */
        "jne .Lf1f92c2_001fa02a\n"
        "movl 8(%ebp), %eax\n" /* line 263 | s */
        "movl $0, 8(%eax)\n"
        "movl $5, (%eax)\n" /* line 265 */
        "jmp .Lf1f92c2_001f986b\n"
        ".Lf1f92c2_001f99a9:\n"
        "movl %edx, -0x5c(%ebp)\n" /* line 205 | q */
        ".Lf1f92c2_001f99ac:\n"
        "movl 8(%ebp), %eax\n" /* line 206 | s */
        "movl 4(%eax), %esi\n" /* t */
        "cmpl %esi, -0x60(%ebp)\n" /* line 207 | t, n */
        "cmovbl -0x60(%ebp), %esi\n" /* n, t */
        "cmpl %esi, -0x58(%ebp)\n" /* line 208 | t, m */
        "jae .Lf1f92c2_001f9ccd\n"
        "movl -0x58(%ebp), %esi\n" /* m, t */
        "movl $0, -0x58(%ebp)\n" /* m */
        ".Lf1f92c2_001f99cc:\n"
        "movl %esi, 8(%esp)\n" /* line 209 | t */
        "movl -0x64(%ebp), %edx\n" /* p */
        "movl %edx, 4(%esp)\n"
        "movl -0x5c(%ebp), %ecx\n" /* q */
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        "addl %esi, -0x64(%ebp)\n" /* line 210 | t, p */
        "subl %esi, -0x60(%ebp)\n" /* t, n */
        "addl %esi, -0x5c(%ebp)\n" /* line 211 | t, q */
        "movl 8(%ebp), %edx\n" /* line 212 | s */
        "movl 4(%edx), %eax\n"
        "subl %esi, %eax\n" /* t */
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "jne .Lf1f92c2_001f9d57\n"
        "cmpl $1, 0x18(%edx)\n" /* line 217 */
        "sbbl %eax, %eax\n"
        "notl %eax\n"
        "andl $7, %eax\n"
        "movl %eax, (%edx)\n"
        "movl $0, 0x10(%ebp)\n" /* r */
        "jmp .Lf1f92c2_001f930e\n"
        /* { scope 2 */
        ".Lf1f92c2_001f9a17:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 274 */
        "testl %eax, %eax\n"
        "je .Lf1f92c2_001f9e84\n"
        "movl -0x3c(%ebp), %ecx\n"
        "movl %ecx, -0x38(%ebp)\n"
        "movl -0x40(%ebp), %edx\n"
        ".Lf1f92c2_001f9a2b:\n"
        "subl $1, -0x38(%ebp)\n"
        "movzbl (%edx), %eax\n"
        "movl %edi, %ecx\n"
        "shll %cl, %eax\n"
        "orl %eax, -0x34(%ebp)\n"
        "addl $1, %edx\n"
        "addl $8, %edi\n"
        "cmpl %edi, %esi\n" /* t */
        "jbe .Lf1f92c2_001f9d48\n"
        "movl -0x40(%ebp), %ecx\n" /* line 127 */
        "addl -0x3c(%ebp), %ecx\n"
        "cmpl %edx, %ecx\n" /* line 274 */
        "jne .Lf1f92c2_001f9a2b\n"
        "jmp .Lf1f92c2_001f956a\n"
        ".Lf1f92c2_001f9a56:\n"
        "cmpl $0x12, -0x2c(%ebp)\n" /* line 285 */
        "je .Lf1f92c2_001f9d63\n"
        "movl -0x2c(%ebp), %esi\n" /* t */
        "subl $0xe, %esi\n" /* t */
        "movl %esi, -0x30(%ebp)\n" /* t */
        "movl $3, -0x50(%ebp)\n" /* j */
        ".Lf1f92c2_001f9a70:\n"
        "movl -0x44(%ebp), %eax\n" /* line 287 */
        "addl -0x30(%ebp), %eax\n"
        "movl %eax, -0x6c(%ebp)\n"
        "cmpl %edi, %eax\n"
        "jbe .Lf1f92c2_001f9ac2\n"
        "movl -0x38(%ebp), %esi\n" /* t */
        "testl %esi, %esi\n" /* t */
        "je .Lf1f92c2_001f9e84\n"
        "movl -0x38(%ebp), %esi\n" /* t */
        "movl -0x40(%ebp), %edx\n"
        ".Lf1f92c2_001f9a8e:\n"
        "subl $1, %esi\n" /* t */
        "movzbl (%edx), %eax\n"
        "movl %edi, %ecx\n"
        "shll %cl, %eax\n"
        "orl %eax, -0x34(%ebp)\n"
        "addl $1, %edx\n"
        "addl $8, %edi\n"
        "cmpl %edi, -0x6c(%ebp)\n"
        "jbe .Lf1f92c2_001f9ab5\n"
        "movl -0x40(%ebp), %ecx\n" /* line 127 */
        "addl -0x38(%ebp), %ecx\n"
        "cmpl %edx, %ecx\n" /* line 287 */
        "jne .Lf1f92c2_001f9a8e\n"
        "jmp .Lf1f92c2_001f956a\n"
        ".Lf1f92c2_001f9ab5:\n"
        "movl %edx, -0x40(%ebp)\n"
        "movl %esi, -0x38(%ebp)\n" /* t */
        "movl $0, 0x10(%ebp)\n" /* r */
        ".Lf1f92c2_001f9ac2:\n"
        "movl -0x34(%ebp), %eax\n" /* line 288 */
        "movzbl -0x44(%ebp), %ecx\n"
        "shrl %cl, %eax\n"
        "subl -0x44(%ebp), %edi\n"
        "movl %eax, %edx\n" /* line 289 */
        "movl -0x30(%ebp), %esi\n" /* t */
        "movl 0x17666f1(%ebx), %ecx\n"
        "andl (%ecx, %esi, 4), %edx\n"
        "addl -0x50(%ebp), %edx\n" /* j */
        "movl %edx, -0x7c(%ebp)\n"
        "movl %esi, %ecx\n" /* line 290 | t */
        "shrl %cl, %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "subl %esi, %edi\n" /* t */
        "movl -0x54(%ebp), %eax\n" /* line 293 | i */
        "addl %edx, %eax\n"
        "cmpl %eax, -0x68(%ebp)\n"
        "jb .Lf1f92c2_001f9f82\n"
        "cmpl $0x10, -0x2c(%ebp)\n"
        "je .Lf1f92c2_001f9d07\n"
        "movl $0, -0x4c(%ebp)\n" /* c */
        "movl 8(%ebp), %esi\n" /* s, t */
        "movl 0xc(%esi), %eax\n" /* t */
        ".Lf1f92c2_001f9b10:\n"
        "movl -0x54(%ebp), %edx\n" /* line 302 | i */
        "shll $2, %edx\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lf1f92c2_001f9b20\n"
        ".Lf1f92c2_001f9b1a:\n"
        "movl 8(%ebp), %esi\n" /* s, t */
        "movl 0xc(%esi), %eax\n" /* t */
        ".Lf1f92c2_001f9b20:\n"
        "movl -0x4c(%ebp), %esi\n" /* line 304 | c, t */
        "movl %esi, (%eax, %edx)\n" /* t */
        "addl $1, -0x54(%ebp)\n" /* i */
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "cmpl %ecx, -0x7c(%ebp)\n" /* line 305 */
        "jne .Lf1f92c2_001f9b1a\n"
        "movl -0x54(%ebp), %eax\n" /* line 306 | i */
        "movl 8(%ebp), %edx\n" /* s */
        "movl %eax, 8(%edx)\n"
        "jmp .Lf1f92c2_001f98f5\n"
        /* } scope */
        ".Lf1f92c2_001f9b43:\n"
        "movl -0x34(%ebp), %ecx\n" /* line 360 */
        "movl %ecx, 0x20(%esi)\n" /* t */
        "movl %edi, 0x1c(%esi)\n" /* t */
        "movl -0x60(%ebp), %ecx\n" /* n */
        "movl 0xc(%ebp), %eax\n" /* z */
        "movl %ecx, 4(%eax)\n"
        "movl -0x64(%ebp), %eax\n" /* p */
        "movl 0xc(%ebp), %esi\n" /* z, t */
        "subl (%esi), %eax\n" /* t */
        "addl %eax, 8(%esi)\n" /* t */
        "movl -0x64(%ebp), %eax\n" /* p */
        "movl %eax, (%esi)\n" /* t */
        "movl -0x5c(%ebp), %esi\n" /* q, t */
        "movl 8(%ebp), %ecx\n" /* s */
        "movl %esi, 0x34(%ecx)\n" /* t */
        "movl %edx, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* z */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll inflate_flush\n"
        "jmp .Lf1f92c2_001f938a\n"
        ".Lf1f92c2_001f9b86:\n"
        "movl 0x2c(%edx), %esi\n" /* line 347 | t */
        "subl %ecx, %esi\n" /* t */
        "movl %esi, -0x58(%ebp)\n" /* t, m */
        "jmp .Lf1f92c2_001f9655\n"
        ".Lf1f92c2_001f9b93:\n"
        "movl -0x64(%ebp), %esi\n" /* line 189 | p, t */
        "movl %esi, -0x80(%ebp)\n" /* t */
        "movl -0x60(%ebp), %esi\n" /* n, t */
        ".Lf1f92c2_001f9b9c:\n"
        "movl -0x34(%ebp), %edx\n" /* line 190 */
        "notl %edx\n"
        "shrl $0x10, %edx\n"
        "movzwl -0x34(%ebp), %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf1f92c2_001fa0fe\n"
        "movl 8(%ebp), %eax\n" /* line 197 | s */
        "movl %edx, 4(%eax)\n"
        "testl %edx, %edx\n" /* line 200 */
        "je .Lf1f92c2_001f9d76\n"
        "movl $2, %eax\n"
        "movl 8(%ebp), %ecx\n" /* s */
        ".Lf1f92c2_001f9bc6:\n"
        "movl %eax, (%ecx)\n"
        "movl -0x80(%ebp), %eax\n"
        "movl %eax, -0x64(%ebp)\n" /* p */
        "movl %esi, -0x60(%ebp)\n" /* t, n */
        "movl $0, -0x34(%ebp)\n"
        "xorl %edi, %edi\n"
        "jmp .Lf1f92c2_001f930e\n"
        ".Lf1f92c2_001f9bdf:\n"
        "movl -0x60(%ebp), %eax\n" /* line 220 | n */
        "testl %eax, %eax\n"
        "je .Lf1f92c2_001fa15c\n"
        "movl -0x64(%ebp), %eax\n" /* p */
        "movl %eax, -0x40(%ebp)\n"
        "movl -0x60(%ebp), %edx\n" /* n */
        "movl %edx, -0x3c(%ebp)\n"
        "movl %eax, %ecx\n"
        "jmp .Lf1f92c2_001f9bfd\n"
        ".Lf1f92c2_001f9bfa:\n"
        "movl -0x40(%ebp), %ecx\n"
        ".Lf1f92c2_001f9bfd:\n"
        "subl $1, -0x3c(%ebp)\n"
        "movzbl (%ecx), %eax\n"
        "movl %edi, %ecx\n"
        "shll %cl, %eax\n"
        "orl %eax, -0x34(%ebp)\n"
        "addl $1, -0x40(%ebp)\n"
        "addl $8, %edi\n"
        "cmpl $0xd, %edi\n"
        "ja .Lf1f92c2_001f9e78\n"
        "movl -0x64(%ebp), %edx\n" /* line 127 | p */
        "addl -0x60(%ebp), %edx\n" /* n */
        "cmpl -0x40(%ebp), %edx\n" /* line 220 */
        "jne .Lf1f92c2_001f9bfa\n"
        "movl $0, 0x10(%ebp)\n" /* r */
        ".Lf1f92c2_001f9c2d:\n"
        "movl -0x34(%ebp), %eax\n"
        "movl 8(%ebp), %ecx\n" /* s */
        "movl %eax, 0x20(%ecx)\n"
        "movl %edi, 0x1c(%ecx)\n"
        "movl 0xc(%ebp), %esi\n" /* z, t */
        "movl $0, 4(%esi)\n" /* t */
        "movl %edx, %eax\n"
        "subl (%esi), %eax\n" /* t */
        "addl %eax, 8(%esi)\n" /* t */
        "movl %edx, (%esi)\n" /* t */
        "movl -0x5c(%ebp), %eax\n" /* q */
        "movl %eax, 0x34(%ecx)\n"
        "movl 0x10(%ebp), %edx\n" /* r */
        "movl %edx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* t */
        "movl %ecx, (%esp)\n"
        "calll inflate_flush\n"
        "jmp .Lf1f92c2_001f938a\n"
        ".Lf1f92c2_001f9c6a:\n"
        "movl -0x60(%ebp), %eax\n" /* line 143 | n */
        "testl %eax, %eax\n"
        "je .Lf1f92c2_001f9ca7\n"
        "movl -0x64(%ebp), %edx\n" /* p */
        "movl -0x60(%ebp), %esi\n" /* n, t */
        ".Lf1f92c2_001f9c77:\n"
        "subl $1, %esi\n" /* t */
        "movzbl (%edx), %eax\n"
        "movl %edi, %ecx\n"
        "shll %cl, %eax\n"
        "orl %eax, -0x34(%ebp)\n"
        "addl $1, %edx\n"
        "addl $8, %edi\n"
        "cmpl $2, %edi\n"
        "ja .Lf1f92c2_001f9e5a\n"
        "movl -0x64(%ebp), %eax\n" /* line 127 | p */
        "addl -0x60(%ebp), %eax\n" /* n */
        "cmpl %edx, %eax\n" /* line 143 */
        "jne .Lf1f92c2_001f9c77\n"
        "movl %edx, -0x64(%ebp)\n" /* p */
        "movl $0, 0x10(%ebp)\n" /* r */
        ".Lf1f92c2_001f9ca7:\n"
        "movl -0x34(%ebp), %eax\n"
        "movl 8(%ebp), %edx\n" /* s */
        "movl %eax, 0x20(%edx)\n"
        "movl %edi, 0x1c(%edx)\n"
        "movl 0xc(%ebp), %ecx\n" /* z */
        "movl $0, 4(%ecx)\n"
        "movl -0x64(%ebp), %eax\n" /* p */
        "subl (%ecx), %eax\n"
        "addl %eax, 8(%ecx)\n"
        "movl -0x64(%ebp), %esi\n" /* p, t */
        "jmp .Lf1f92c2_001f97a4\n"
        ".Lf1f92c2_001f9ccd:\n"
        "subl %esi, -0x58(%ebp)\n" /* line 208 | t, m */
        "jmp .Lf1f92c2_001f99cc\n"
        ".Lf1f92c2_001f9cd5:\n"
        "leal 0x10dbed(%ebx, %edx, 4), %ecx\n" /* line 248 */
        ".Lf1f92c2_001f9cdc:\n"
        "movl (%ecx), %edx\n" /* line 249 */
        "movl 8(%ebp), %eax\n" /* s */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0x8c(%ebp)\n"
        "movl $0, (%eax, %edx, 4)\n"
        "addl $1, %esi\n" /* t */
        "movl 8(%ebp), %eax\n" /* s */
        "movl %esi, 8(%eax)\n" /* t */
        "addl $4, %ecx\n"
        "cmpl $0x13, %esi\n" /* line 248 | t */
        "jne .Lf1f92c2_001f9cdc\n"
        "jmp .Lf1f92c2_001f9957\n"
        /* { scope 2 */
        ".Lf1f92c2_001f9d07:\n"
        "movl -0x54(%ebp), %eax\n" /* line 293 | i */
        "testl %eax, %eax\n"
        "je .Lf1f92c2_001f9f82\n"
        "movl 8(%ebp), %edx\n" /* line 302 | s */
        "movl 0xc(%edx), %eax\n"
        "movl -0x54(%ebp), %ecx\n" /* i */
        "movl -4(%eax, %ecx, 4), %ecx\n"
        "movl %ecx, -0x4c(%ebp)\n" /* c */
        "jmp .Lf1f92c2_001f9b10\n"
        /* } scope */
        ".Lf1f92c2_001f9d27:\n"
        "movl 0x28(%eax), %eax\n" /* line 205 */
        "movl %eax, -0x5c(%ebp)\n" /* q */
        "cmpl %eax, %ecx\n"
        "je .Lf1f92c2_001f96dc\n"
        "jbe .Lf1f92c2_001f9f77\n"
        "subl %eax, %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x58(%ebp)\n" /* m */
        "jmp .Lf1f92c2_001f96df\n"
        /* { scope 2 */
        ".Lf1f92c2_001f9d48:\n"
        "movl %edx, -0x40(%ebp)\n" /* line 274 */
        "movl $0, 0x10(%ebp)\n" /* r */
        "jmp .Lf1f92c2_001f98ab\n"
        /* } scope */
        ".Lf1f92c2_001f9d57:\n"
        "movl $0, 0x10(%ebp)\n" /* line 137 | r */
        "jmp .Lf1f92c2_001f930e\n"
        /* { scope 2 */
        ".Lf1f92c2_001f9d63:\n"
        "movl $0xb, -0x50(%ebp)\n" /* line 285 | j */
        "movl $7, -0x30(%ebp)\n"
        "jmp .Lf1f92c2_001f9a70\n"
        /* } scope */
        ".Lf1f92c2_001f9d76:\n"
        "movl 8(%ebp), %edx\n" /* line 200 | s */
        "cmpl $1, 0x18(%edx)\n"
        "sbbl %eax, %eax\n"
        "notl %eax\n"
        "andl $7, %eax\n"
        "movl %edx, %ecx\n"
        "jmp .Lf1f92c2_001f9bc6\n"
        ".Lf1f92c2_001f9d8b:\n"
        "shrl $3, -0x34(%ebp)\n" /* line 151 */
        "leal -3(%edi), %eax\n"
        "movl %eax, %ecx\n" /* line 152 */
        "andl $7, %ecx\n"
        "shrl %cl, -0x34(%ebp)\n" /* line 153 */
        "movl %eax, %edi\n"
        "subl %ecx, %edi\n"
        "movl 8(%ebp), %eax\n" /* line 154 | s */
        "movl $1, (%eax)\n"
        "jmp .Lf1f92c2_001f930e\n"
        ".Lf1f92c2_001f9dac:\n"
        "movl 8(%ebp), %eax\n" /* line 205 | s */
        "movl 0x2c(%eax), %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, -0x58(%ebp)\n" /* m */
        "jmp .Lf1f92c2_001f96d0\n"
        /* { scope 2 */
        ".Lf1f92c2_001f9dbc:\n"
        "movl 0xc(%ebp), %edx\n" /* line 163 | z */
        "movl %edx, 0x10(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* td */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* tl */
        "movl %eax, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* bd */
        "movl %eax, 4(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* bl */
        "movl %eax, (%esp)\n"
        "calll inflate_trees_fixed\n"
        "movl 0xc(%ebp), %ecx\n" /* line 164 | z */
        "movl %ecx, 0x10(%esp)\n"
        "movl -0x20(%ebp), %eax\n" /* td */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* tl */
        "movl %eax, 8(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* bd */
        "movl %eax, 4(%esp)\n"
        "movl -0x28(%ebp), %eax\n" /* bl */
        "movl %eax, (%esp)\n"
        "calll inflate_codes_new\n"
        "movl 8(%ebp), %esi\n" /* s, t */
        "movl %eax, 4(%esi)\n" /* t */
        "testl %eax, %eax\n" /* line 165 */
        "je .Lf1f92c2_001fa164\n"
        /* } scope */
        "shrl $3, -0x34(%ebp)\n" /* line 171 */
        "subl $3, %edi\n"
        "movl $6, (%esi)\n" /* line 172 | t */
        "jmp .Lf1f92c2_001f930e\n"
        ".Lf1f92c2_001f9e2a:\n"
        "movl 0x30(%edx), %eax\n" /* line 205 */
        "movl 0x28(%edx), %edx\n"
        "cmpl %edx, %eax\n"
        "je .Lf1f92c2_001f9f6c\n"
        "jbe .Lf1f92c2_001f9e8c\n"
        "subl %edx, %eax\n"
        "subl $1, %eax\n"
        "movl %eax, -0x58(%ebp)\n" /* m */
        ".Lf1f92c2_001f9e42:\n"
        "movl -0x58(%ebp), %eax\n" /* m */
        "testl %eax, %eax\n"
        "jne .Lf1f92c2_001f99a9\n"
        "movl %edx, -0x5c(%ebp)\n" /* q */
        "movl %edx, %ecx\n"
        "movl 8(%ebp), %edx\n" /* s */
        "jmp .Lf1f92c2_001f969a\n"
        ".Lf1f92c2_001f9e5a:\n"
        "movl %edx, -0x64(%ebp)\n" /* line 143 | p */
        "movl %esi, -0x60(%ebp)\n" /* t, n */
        "movl $0, 0x10(%ebp)\n" /* r */
        "jmp .Lf1f92c2_001f97d0\n"
        ".Lf1f92c2_001f9e6c:\n"
        "movl $0, 0x10(%ebp)\n" /* line 189 | r */
        "jmp .Lf1f92c2_001f9b9c\n"
        ".Lf1f92c2_001f9e78:\n"
        "movl $0, 0x10(%ebp)\n" /* line 220 | r */
        "jmp .Lf1f92c2_001f9447\n"
        ".Lf1f92c2_001f9e84:\n"
        "movl -0x40(%ebp), %ecx\n" /* line 244 */
        "jmp .Lf1f92c2_001f9571\n"
        ".Lf1f92c2_001f9e8c:\n"
        "movl -0x5c(%ebp), %eax\n" /* line 205 | q */
        "subl %edx, %eax\n"
        "movl %eax, -0x58(%ebp)\n" /* m */
        "jmp .Lf1f92c2_001f9e42\n"
        ".Lf1f92c2_001f9e96:\n"
        "shrl $3, -0x34(%ebp)\n" /* line 177 */
        "subl $3, %edi\n"
        "movl 8(%ebp), %eax\n" /* line 178 | s */
        "movl $3, (%eax)\n"
        "jmp .Lf1f92c2_001f930e\n"
        ".Lf1f92c2_001f9eab:\n"
        "movl 8(%ebp), %eax\n" /* line 309 | s */
        "movl $0, 0x14(%eax)\n"
        /* { scope 2 */
        "movl $9, -0x20(%ebp)\n" /* line 315 | td */
        "movl $6, -0x24(%ebp)\n" /* line 316 | tl */
        "movl 0xc(%ebp), %esi\n" /* line 318 | z, t */
        "movl %esi, 0x20(%esp)\n" /* t */
        "movl 8(%ebp), %esi\n" /* s, t */
        "movl 0x24(%esi), %eax\n" /* t */
        "movl %eax, 0x1c(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* bd */
        "movl %eax, 0x18(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* bl */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* tl */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* td */
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%esi), %eax\n" /* t */
        "movl %eax, 8(%esp)\n"
        "leal 1(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x101(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll inflate_trees_dynamic\n"
        "movl %eax, %esi\n" /* t */
        "testl %eax, %eax\n" /* line 321 */
        "jne .Lf1f92c2_001fa02a\n"
        "movl 8(%ebp), %edx\n" /* line 331 | s */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* z */
        "movl 0x28(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x24(%ecx)\n"
        "movl 0xc(%ebp), %esi\n" /* line 333 | z, t */
        "movl %esi, 0x10(%esp)\n" /* t */
        "movl -0x1c(%ebp), %eax\n" /* bd */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x28(%ebp), %eax\n" /* bl */
        "movl %eax, 8(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* tl */
        "movl %eax, 4(%esp)\n"
        "movl -0x20(%ebp), %eax\n" /* td */
        "movl %eax, (%esp)\n"
        "calll inflate_codes_new\n"
        "testl %eax, %eax\n"
        "je .Lf1f92c2_001fa0ba\n"
        "movl 8(%ebp), %edx\n" /* line 338 | s */
        "movl %eax, 4(%edx)\n"
        /* } scope */
        "movl $6, (%edx)\n" /* line 340 */
        "jmp .Lf1f92c2_001f95c3\n"
        ".Lf1f92c2_001f9f6c:\n"
        "movl -0x5c(%ebp), %ecx\n" /* q */
        "movl 8(%ebp), %edx\n" /* s */
        "jmp .Lf1f92c2_001f969a\n"
        ".Lf1f92c2_001f9f77:\n"
        "subl -0x5c(%ebp), %edx\n" /* line 205 | q */
        "movl %edx, -0x58(%ebp)\n" /* m */
        "jmp .Lf1f92c2_001f96df\n"
        /* { scope 2 */
        ".Lf1f92c2_001f9f82:\n"
        "movl 8(%ebp), %edx\n" /* line 296 | s */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* z */
        "movl 0x28(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x24(%ecx)\n"
        "movl 8(%ebp), %esi\n" /* line 297 | s, t */
        "movl $9, (%esi)\n" /* t */
        "leal 0xc12b1(%ebx), %eax\n" /* line 298 */
        "movl 0xc(%ebp), %edx\n" /* z */
        "movl %eax, 0x18(%edx)\n"
        "movl -0x34(%ebp), %ecx\n" /* line 300 */
        "movl %ecx, 0x20(%esi)\n" /* t */
        "movl %edi, 0x1c(%esi)\n" /* t */
        "movl -0x38(%ebp), %esi\n" /* t */
        "movl %esi, 4(%edx)\n" /* t */
        "movl -0x40(%ebp), %eax\n"
        "subl (%edx), %eax\n"
        "addl %eax, 8(%edx)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, (%edx)\n"
        "movl -0x5c(%ebp), %ecx\n" /* q */
        "movl 8(%ebp), %edx\n" /* s */
        "jmp .Lf1f92c2_001f94db\n"
        /* } scope */
        ".Lf1f92c2_001f9fd4:\n"
        "movl 8(%ebp), %ecx\n" /* line 225 | s */
        "movl $9, (%ecx)\n"
        "leal 0xc128d(%ebx), %eax\n" /* line 226 */
        "movl 0xc(%ebp), %esi\n" /* z, t */
        "movl %eax, 0x18(%esi)\n" /* t */
        "movl -0x34(%ebp), %eax\n" /* line 228 */
        "movl %eax, 0x20(%ecx)\n"
        "movl %edi, 0x1c(%ecx)\n"
        "movl -0x3c(%ebp), %edx\n"
        "movl %edx, 4(%esi)\n" /* t */
        "movl -0x40(%ebp), %eax\n"
        "subl (%esi), %eax\n" /* t */
        "addl %eax, 8(%esi)\n" /* t */
        "movl -0x40(%ebp), %ecx\n"
        "movl %ecx, (%esi)\n" /* t */
        "movl -0x5c(%ebp), %eax\n" /* q */
        "movl 8(%ebp), %esi\n" /* s, t */
        "movl %eax, 0x34(%esi)\n" /* t */
        "movl $0xfffffffd, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* z */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* t */
        "calll inflate_flush\n"
        "jmp .Lf1f92c2_001f938a\n"
        /* { scope 2 */
        ".Lf1f92c2_001fa02a:\n"
        "cmpl $-3, %esi\n" /* line 323 | t */
        "je .Lf1f92c2_001fa1a8\n"
        /* } scope */
        ".Lf1f92c2_001fa033:\n"
        "movl -0x34(%ebp), %edx\n" /* line 261 */
        "movl 8(%ebp), %ecx\n" /* s */
        "movl %edx, 0x20(%ecx)\n"
        "movl %edi, 0x1c(%ecx)\n"
        "movl -0x3c(%ebp), %edx\n"
        "movl 0xc(%ebp), %eax\n" /* z */
        "movl %edx, 4(%eax)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl 0xc(%ebp), %ecx\n" /* z */
        "subl (%ecx), %eax\n"
        "addl %eax, 8(%ecx)\n"
        "movl -0x40(%ebp), %eax\n"
        "jmp .Lf1f92c2_001f970d\n"
        ".Lf1f92c2_001fa05b:\n"
        "movl %eax, 8(%esp)\n" /* line 344 */
        "movl 0xc(%ebp), %eax\n" /* z */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* s */
        "movl %edx, (%esp)\n"
        "calll inflate_flush\n"
        "jmp .Lf1f92c2_001f938a\n"
        ".Lf1f92c2_001fa076:\n"
        "movl -0x34(%ebp), %edx\n" /* line 204 */
        "movl 8(%ebp), %ecx\n" /* s */
        "movl %edx, 0x20(%ecx)\n"
        "movl %edi, 0x1c(%ecx)\n"
        "movl 0xc(%ebp), %esi\n" /* z, t */
        "movl $0, 4(%esi)\n" /* t */
        "movl -0x64(%ebp), %eax\n" /* p */
        "subl (%esi), %eax\n" /* t */
        "addl %eax, 8(%esi)\n" /* t */
        "movl -0x64(%ebp), %eax\n" /* p */
        "movl %eax, (%esi)\n" /* t */
        "movl -0x5c(%ebp), %edx\n" /* q */
        "movl %edx, 0x34(%ecx)\n"
        "movl 0x10(%ebp), %ecx\n" /* r */
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* t */
        "movl 8(%ebp), %esi\n" /* s, t */
        "movl %esi, (%esp)\n" /* t */
        "calll inflate_flush\n"
        "jmp .Lf1f92c2_001f938a\n"
        /* { scope 2 */
        ".Lf1f92c2_001fa0ba:\n"
        "movl -0x34(%ebp), %eax\n" /* line 336 */
        "movl 8(%ebp), %edx\n" /* s */
        "movl %eax, 0x20(%edx)\n"
        "movl %edi, 0x1c(%edx)\n"
        "movl -0x3c(%ebp), %esi\n" /* t */
        "movl 0xc(%ebp), %ecx\n" /* z */
        "movl %esi, 4(%ecx)\n" /* t */
        "movl -0x40(%ebp), %eax\n"
        "subl (%ecx), %eax\n"
        "addl %eax, 8(%ecx)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, (%ecx)\n"
        "movl -0x5c(%ebp), %ecx\n" /* q */
        "movl %ecx, 0x34(%edx)\n"
        "movl $0xfffffffc, 8(%esp)\n"
        "movl 0xc(%ebp), %esi\n" /* z, t */
        "movl %esi, 4(%esp)\n" /* t */
        "movl %edx, (%esp)\n"
        "calll inflate_flush\n"
        "jmp .Lf1f92c2_001f938a\n"
        /* } scope */
        ".Lf1f92c2_001fa0fe:\n"
        "movl 8(%ebp), %edx\n" /* line 192 | s */
        "movl $9, (%edx)\n"
        "leal 0xc126d(%ebx), %eax\n" /* line 193 */
        "movl 0xc(%ebp), %ecx\n" /* z */
        "movl %eax, 0x18(%ecx)\n"
        "movl -0x34(%ebp), %eax\n" /* line 195 */
        "movl %eax, 0x20(%edx)\n"
        "movl %edi, 0x1c(%edx)\n"
        "movl %esi, 4(%ecx)\n" /* t */
        "movl -0x80(%ebp), %eax\n"
        "subl (%ecx), %eax\n"
        "addl %eax, 8(%ecx)\n"
        "movl -0x80(%ebp), %edx\n"
        "movl %edx, (%ecx)\n"
        "movl -0x5c(%ebp), %esi\n" /* q, t */
        "movl 8(%ebp), %ecx\n" /* s */
        "movl %esi, 0x34(%ecx)\n" /* t */
        "movl $0xfffffffd, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* z */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll inflate_flush\n"
        "jmp .Lf1f92c2_001f938a\n"
        ".Lf1f92c2_001fa151:\n"
        "movl -0x64(%ebp), %eax\n" /* line 189 | p */
        "movl %eax, -0x80(%ebp)\n"
        "jmp .Lf1f92c2_001f9783\n"
        ".Lf1f92c2_001fa15c:\n"
        "movl -0x64(%ebp), %edx\n" /* line 220 | p */
        "jmp .Lf1f92c2_001f9c2d\n"
        /* { scope 2 */
        ".Lf1f92c2_001fa164:\n"
        "movl -0x34(%ebp), %edx\n" /* line 168 */
        "movl 8(%ebp), %ecx\n" /* s */
        "movl %edx, 0x20(%ecx)\n"
        "movl %edi, 0x1c(%ecx)\n"
        "movl -0x60(%ebp), %eax\n" /* n */
        "movl 0xc(%ebp), %esi\n" /* z, t */
        "movl %eax, 4(%esi)\n" /* t */
        "movl -0x64(%ebp), %eax\n" /* p */
        "subl (%esi), %eax\n" /* t */
        "addl %eax, 8(%esi)\n" /* t */
        "movl -0x64(%ebp), %edx\n" /* p */
        "movl %edx, (%esi)\n" /* t */
        "movl -0x5c(%ebp), %esi\n" /* q, t */
        "movl %esi, 0x34(%ecx)\n" /* t */
        "movl $0xfffffffc, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* z */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll inflate_flush\n"
        "jmp .Lf1f92c2_001f938a\n"
        /* } scope */
        ".Lf1f92c2_001fa1a8:\n"
        "movl 8(%ebp), %edx\n" /* line 258 | s */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* z */
        "movl 0x28(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x24(%ecx)\n"
        "movl 8(%ebp), %eax\n" /* line 259 | s */
        "movl $9, (%eax)\n"
        "jmp .Lf1f92c2_001fa033\n"
    );
}

/* line 96 */
__attribute__((naked))
inflate_blocks_statef * inflate_blocks_new(z_streamp z, check_func c, uInt w)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 96 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %edi\n" /* z */
        "movl $0x40, 8(%esp)\n" /* line 99 */
        "movl $1, 4(%esp)\n"
        "movl 0x28(%edi), %eax\n" /* z */
        "movl %eax, (%esp)\n"
        "calll *0x20(%edi)\n" /* z */
        "movl %eax, %esi\n" /* s */
        "testl %eax, %eax\n"
        "je .Lf1fa1cd_001fa28d\n"
        "movl $0x5a0, 8(%esp)\n" /* line 102 */
        "movl $8, 4(%esp)\n"
        "movl 0x28(%edi), %eax\n" /* z */
        "movl %eax, (%esp)\n"
        "calll *0x20(%edi)\n" /* z */
        "movl %eax, 0x24(%esi)\n" /* s */
        "testl %eax, %eax\n"
        "je .Lf1fa1cd_001fa2a6\n"
        "movl 0x10(%ebp), %eax\n" /* line 108 | w */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl 0x28(%edi), %eax\n" /* z */
        "movl %eax, (%esp)\n"
        "calll *0x20(%edi)\n" /* z */
        "movl %eax, %edx\n"
        "movl %eax, 0x28(%esi)\n" /* s */
        "testl %eax, %eax\n"
        "je .Lf1fa1cd_001fa296\n"
        "movl 0x10(%ebp), %ecx\n" /* line 114 | w */
        "leal (%eax, %ecx), %eax\n"
        "movl %eax, 0x2c(%esi)\n" /* s */
        "movl 0xc(%ebp), %eax\n" /* line 115 | c */
        "movl %eax, 0x38(%esi)\n" /* s */
        "movl $0, (%esi)\n" /* line 82 */
        "movl $0, 0x1c(%esi)\n" /* line 83 */
        "movl $0, 0x20(%esi)\n" /* line 84 */
        "movl %edx, 0x34(%esi)\n" /* line 85 */
        "movl %edx, 0x30(%esi)\n"
        "testl %eax, %eax\n" /* line 86 */
        "je .Lf1fa1cd_001fa28d\n"
        "movl $0, 8(%esp)\n" /* line 87 */
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll *0xc(%ebp)\n" /* c */
        "movl %eax, 0x3c(%esi)\n"
        "movl %eax, 0x30(%edi)\n"
        ".Lf1fa1cd_001fa28d:\n"
        "movl %esi, %eax\n" /* line 120 | s */
        "addl $0x10, %esp\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1fa1cd_001fa296:\n"
        "movl 0x24(%esi), %eax\n" /* line 110 | s */
        "movl %eax, 4(%esp)\n"
        "movl 0x28(%edi), %eax\n" /* z */
        "movl %eax, (%esp)\n"
        "calll *0x24(%edi)\n" /* z */
        ".Lf1fa1cd_001fa2a6:\n"
        "movl %esi, 4(%esp)\n" /* line 111 | s */
        "movl 0x28(%edi), %eax\n" /* z */
        "movl %eax, (%esp)\n"
        "calll *0x24(%edi)\n" /* z */
        "xorl %esi, %esi\n" /* s */
        "jmp .Lf1fa1cd_001fa28d\n"
    );
}

/* line 378 */
__attribute__((naked))
int inflate_blocks_free(inflate_blocks_statef *s, z_streamp z)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 378 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* s */
        "movl 0xc(%ebp), %edi\n" /* z */
        "movl (%esi), %eax\n" /* line 78 */
        "subl $4, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf1fa2b7_001fa365\n"
        ".Lf1fa2b7_001fa2d3:\n"
        "cmpl $6, (%esi)\n" /* line 80 */
        "je .Lf1fa2b7_001fa351\n"
        ".Lf1fa2b7_001fa2d8:\n"
        "movl $0, (%esi)\n" /* line 82 */
        "movl $0, 0x1c(%esi)\n" /* line 83 */
        "movl $0, 0x20(%esi)\n" /* line 84 */
        "movl 0x28(%esi), %eax\n" /* line 85 */
        "movl %eax, 0x34(%esi)\n"
        "movl %eax, 0x30(%esi)\n"
        "movl 0x38(%esi), %edx\n" /* line 86 */
        "testl %edx, %edx\n"
        "je .Lf1fa2b7_001fa31e\n"
        "movl $0, 8(%esp)\n" /* line 87 */
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll *%edx\n"
        "movl %eax, 0x3c(%esi)\n"
        "movl %eax, 0x30(%edi)\n"
        "movl 0x28(%esi), %eax\n"
        ".Lf1fa2b7_001fa31e:\n"
        "movl %eax, 4(%esp)\n" /* line 380 */
        "movl 0x28(%edi), %eax\n" /* z */
        "movl %eax, (%esp)\n"
        "calll *0x24(%edi)\n" /* z */
        "movl 0x24(%esi), %eax\n" /* line 381 | s */
        "movl %eax, 4(%esp)\n"
        "movl 0x28(%edi), %eax\n" /* z */
        "movl %eax, (%esp)\n"
        "calll *0x24(%edi)\n" /* z */
        "movl %esi, 4(%esp)\n" /* line 382 | s */
        "movl 0x28(%edi), %eax\n" /* z */
        "movl %eax, (%esp)\n"
        "calll *0x24(%edi)\n" /* z */
        "xorl %eax, %eax\n" /* line 385 */
        "addl $0x10, %esp\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1fa2b7_001fa351:\n"
        "movl %edi, 4(%esp)\n" /* line 81 */
        "movl 4(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll inflate_codes_free\n"
        "jmp .Lf1fa2b7_001fa2d8\n"
        ".Lf1fa2b7_001fa365:\n"
        "movl 0xc(%esi), %eax\n" /* line 79 */
        "movl %eax, 4(%esp)\n"
        "movl 0x28(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x24(%edi)\n"
        "jmp .Lf1fa2b7_001fa2d3\n"
    );
}

