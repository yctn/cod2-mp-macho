/* ASM dump from: jfdctflt.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jfdctflt.c */

#include "common_types.h"
#include "imports.h"

void jpeg_fdct_float(float *data);

/* line 60 */
__attribute__((naked))
void jpeg_fdct_float(float *data)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 60 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x18, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %ecx\n" /* data */
        "movl %ecx, %eax\n"
        "movl $8, %edx\n"
        ".Lf214e30_00214e47:\n"
        "movss (%eax), %xmm7\n" /* line 71 */
        "movss 0x1c(%eax), %xmm0\n"
        "movaps %xmm7, %xmm4\n"
        "addss %xmm0, %xmm4\n"
        "subss %xmm0, %xmm7\n" /* line 72 */
        "movss 4(%eax), %xmm6\n" /* line 73 */
        "movss 0x18(%eax), %xmm0\n"
        "movaps %xmm6, %xmm2\n"
        "addss %xmm0, %xmm2\n"
        "subss %xmm0, %xmm6\n" /* line 74 */
        "movss 8(%eax), %xmm3\n" /* line 75 */
        "movss 0x14(%eax), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0xc(%ebp)\n"
        "subss %xmm0, %xmm3\n" /* line 76 */
        "movss %xmm3, -0x10(%ebp)\n"
        "movss 0xc(%eax), %xmm3\n" /* line 77 */
        "movss 0x10(%eax), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "addss %xmm3, %xmm0\n"
        "movaps %xmm4, %xmm1\n" /* line 82 */
        "addss %xmm0, %xmm1\n"
        "subss %xmm0, %xmm4\n" /* line 83 */
        "movss -0xc(%ebp), %xmm5\n" /* line 84 */
        "addss %xmm2, %xmm5\n"
        "movaps %xmm1, %xmm0\n" /* line 87 */
        "addss %xmm5, %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "subss %xmm5, %xmm1\n" /* line 88 */
        "movss %xmm1, 0x10(%eax)\n"
        "subss -0xc(%ebp), %xmm2\n" /* line 90 */
        "addss %xmm4, %xmm2\n"
        "leal 0xd8ca3(%ebx), %esi\n" /* 0.7071067690849304f */
        "mulss (%esi), %xmm2\n"
        "movaps %xmm4, %xmm0\n" /* line 91 */
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        "subss %xmm2, %xmm4\n" /* line 92 */
        "movss %xmm4, 0x18(%eax)\n"
        "subss -0x20(%ebp), %xmm3\n" /* line 96 */
        "addss -0x10(%ebp), %xmm3\n"
        "movaps %xmm7, %xmm1\n" /* line 98 */
        "addss %xmm6, %xmm1\n"
        "movaps %xmm3, %xmm0\n" /* line 101 */
        "subss %xmm1, %xmm0\n"
        "leal 0xd8ca7(%ebx), %esi\n" /* 0.3826834261417389f */
        "mulss (%esi), %xmm0\n"
        "leal 0xd8cab(%ebx), %esi\n" /* line 102 | 0.5411961078643799f */
        "mulss (%esi), %xmm3\n"
        "addss %xmm0, %xmm3\n"
        "leal 0xd8caf(%ebx), %esi\n" /* line 103 | 1.3065630197525024f */
        "mulss (%esi), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "addss -0x10(%ebp), %xmm6\n" /* line 104 */
        "leal 0xd8ca3(%ebx), %esi\n" /* 0.7071067690849304f */
        "mulss (%esi), %xmm6\n"
        "movaps %xmm7, %xmm2\n" /* line 106 */
        "addss %xmm6, %xmm2\n"
        "subss %xmm6, %xmm7\n" /* line 107 */
        "movaps %xmm3, %xmm0\n" /* line 109 */
        "addss %xmm7, %xmm0\n"
        "movss %xmm0, 0x14(%eax)\n"
        "subss %xmm3, %xmm7\n" /* line 110 */
        "movss %xmm7, 0xc(%eax)\n"
        "movaps %xmm1, %xmm0\n" /* line 111 */
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "subss %xmm1, %xmm2\n" /* line 112 */
        "movss %xmm2, 0x1c(%eax)\n"
        "addl $0x20, %eax\n" /* line 114 */
        "subl $1, %edx\n" /* line 70 */
        "jne .Lf214e30_00214e47\n"
        "movl %ecx, %eax\n"
        "movl $8, %edx\n"
        ".Lf214e30_00214f87:\n"
        "movss (%eax), %xmm7\n" /* line 121 */
        "movss 0xe0(%eax), %xmm0\n"
        "movaps %xmm7, %xmm4\n"
        "addss %xmm0, %xmm4\n"
        "subss %xmm0, %xmm7\n" /* line 122 */
        "movss 0x20(%eax), %xmm6\n" /* line 123 */
        "movss 0xc0(%eax), %xmm0\n"
        "movaps %xmm6, %xmm2\n"
        "addss %xmm0, %xmm2\n"
        "subss %xmm0, %xmm6\n" /* line 124 */
        "movss 0x40(%eax), %xmm3\n" /* line 125 */
        "movss 0xa0(%eax), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x18(%ebp)\n" /* tmp2 */
        "subss %xmm0, %xmm3\n" /* line 126 */
        "movss %xmm3, -0x14(%ebp)\n" /* tmp5 */
        "movss 0x60(%eax), %xmm3\n" /* line 127 */
        "movss 0x80(%eax), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "addss %xmm3, %xmm0\n"
        "movaps %xmm4, %xmm1\n" /* line 132 */
        "addss %xmm0, %xmm1\n"
        "subss %xmm0, %xmm4\n" /* line 133 */
        "movss -0x18(%ebp), %xmm5\n" /* line 134 | tmp2 */
        "addss %xmm2, %xmm5\n"
        "movaps %xmm1, %xmm0\n" /* line 137 */
        "addss %xmm5, %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "subss %xmm5, %xmm1\n" /* line 138 */
        "movss %xmm1, 0x80(%eax)\n"
        "subss -0x18(%ebp), %xmm2\n" /* line 140 | tmp2 */
        "addss %xmm4, %xmm2\n"
        "leal 0xd8ca3(%ebx), %ecx\n" /* 0.7071067690849304f */
        "mulss (%ecx), %xmm2\n"
        "movaps %xmm4, %xmm0\n" /* line 141 */
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, 0x40(%eax)\n"
        "subss %xmm2, %xmm4\n" /* line 142 */
        "movss %xmm4, 0xc0(%eax)\n"
        "subss -0x1c(%ebp), %xmm3\n" /* line 146 */
        "addss -0x14(%ebp), %xmm3\n" /* tmp5 */
        "movaps %xmm7, %xmm1\n" /* line 148 */
        "addss %xmm6, %xmm1\n"
        "movaps %xmm3, %xmm0\n" /* line 151 */
        "subss %xmm1, %xmm0\n"
        "leal 0xd8ca7(%ebx), %esi\n" /* 0.3826834261417389f */
        "mulss (%esi), %xmm0\n"
        "leal 0xd8cab(%ebx), %ecx\n" /* line 152 | 0.5411961078643799f */
        "mulss (%ecx), %xmm3\n"
        "addss %xmm0, %xmm3\n"
        "leal 0xd8caf(%ebx), %esi\n" /* line 153 | 1.3065630197525024f */
        "mulss (%esi), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "addss -0x14(%ebp), %xmm6\n" /* line 154 | tmp5 */
        "leal 0xd8ca3(%ebx), %ecx\n" /* 0.7071067690849304f */
        "mulss (%ecx), %xmm6\n"
        "movaps %xmm7, %xmm2\n" /* line 156 */
        "addss %xmm6, %xmm2\n"
        "subss %xmm6, %xmm7\n" /* line 157 */
        "movaps %xmm3, %xmm0\n" /* line 159 */
        "addss %xmm7, %xmm0\n"
        "movss %xmm0, 0xa0(%eax)\n"
        "subss %xmm3, %xmm7\n" /* line 160 */
        "movss %xmm7, 0x60(%eax)\n"
        "movaps %xmm1, %xmm0\n" /* line 161 */
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, 0x20(%eax)\n"
        "subss %xmm1, %xmm2\n" /* line 162 */
        "movss %xmm2, 0xe0(%eax)\n"
        "addl $4, %eax\n" /* line 164 */
        "subl $1, %edx\n" /* line 120 */
        "jne .Lf214e30_00214f87\n"
        "addl $0x18, %esp\n" /* line 166 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

