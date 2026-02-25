/* ASM dump from: jfdctfst.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jfdctfst.c */

#include "common_types.h"
#include "imports.h"

void jpeg_fdct_ifast(DCTELEM *data);

/* line 115 */
__attribute__((naked))
void jpeg_fdct_ifast(DCTELEM *data)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 115 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x58, %esp\n"
        "movl 8(%ebp), %eax\n" /* data */
        "movl %eax, -0x20(%ebp)\n"
        "movl $8, -0x28(%ebp)\n"
        "movl %eax, %ecx\n"
        "movl %eax, %edi\n"
        "jmp .Lf2150e0_002150ff\n"
        ".Lf2150e0_002150fb:\n"
        "movl %edx, %ecx\n"
        "movl %edx, %edi\n"
        ".Lf2150e0_002150ff:\n"
        "movl (%ecx), %edx\n" /* line 127 */
        "movl 0x1c(%ecx), %eax\n"
        "leal (%edx, %eax), %esi\n" /* z5 */
        "subl %eax, %edx\n" /* line 128 */
        "movl %edx, -0xc(%ebp)\n"
        "movl 4(%ecx), %edx\n" /* line 129 */
        "movl 0x18(%ecx), %eax\n"
        "leal (%edx, %eax), %ecx\n"
        "subl %eax, %edx\n" /* line 130 */
        "movl %edx, -0x10(%ebp)\n"
        "movl 8(%edi), %edx\n" /* line 131 | z13 */
        "movl 0x14(%edi), %eax\n" /* z13 */
        "leal (%edx, %eax), %edi\n" /* z13 */
        "movl %edi, -0x14(%ebp)\n" /* z13 */
        "subl %eax, %edx\n" /* line 132 */
        "movl %edx, -0x18(%ebp)\n"
        "movl -0x20(%ebp), %eax\n" /* line 133 */
        "movl 0xc(%eax), %edi\n" /* z13 */
        "movl 0x10(%eax), %edx\n"
        "movl %edx, -0x48(%ebp)\n"
        "leal (%edi, %edx), %eax\n" /* z13 */
        "leal (%esi, %eax), %edx\n" /* line 138 | z5 */
        "subl %eax, %esi\n" /* line 139 | z5 */
        "movl %esi, -0x1c(%ebp)\n" /* z5 */
        "movl -0x14(%ebp), %esi\n" /* line 140 | z5 */
        "addl %ecx, %esi\n" /* z5 */
        "movl %esi, -0x5c(%ebp)\n" /* z5, tmp11 */
        "addl %edx, %esi\n" /* line 143 | z5 */
        "movl -0x20(%ebp), %eax\n"
        "movl %esi, (%eax)\n" /* z5 */
        "subl -0x5c(%ebp), %edx\n" /* line 144 | tmp11 */
        "movl %edx, 0x10(%eax)\n"
        "subl -0x14(%ebp), %ecx\n" /* line 146 */
        "addl -0x1c(%ebp), %ecx\n"
        "leal (%ecx, %ecx, 2), %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "sarl $8, %eax\n"
        "movl -0x1c(%ebp), %edx\n" /* line 147 */
        "addl %eax, %edx\n"
        "movl -0x20(%ebp), %ecx\n"
        "movl %edx, 8(%ecx)\n"
        "subl %eax, -0x1c(%ebp)\n" /* line 148 */
        "movl -0x1c(%ebp), %esi\n" /* z5 */
        "movl %esi, 0x18(%ecx)\n" /* z5 */
        "subl -0x48(%ebp), %edi\n" /* line 152 | z13 */
        "addl -0x18(%ebp), %edi\n" /* z13 */
        "movl -0xc(%ebp), %ecx\n" /* line 154 */
        "addl -0x10(%ebp), %ecx\n"
        "movl %edi, %eax\n" /* line 157 | z13 */
        "subl %ecx, %eax\n"
        "leal (%eax, %eax, 2), %esi\n" /* z5 */
        "shll $4, %esi\n" /* z5 */
        "addl %eax, %esi\n" /* z5 */
        "addl %esi, %esi\n" /* z5 */
        "sarl $8, %esi\n" /* z5 */
        "movl %edi, %edx\n" /* line 158 | z13 */
        "shll $4, %edx\n"
        "addl %edi, %edx\n" /* z13 */
        "leal (%edi, %edx, 4), %edx\n" /* z13 */
        "leal (%edi, %edx, 2), %edx\n" /* z13 */
        "sarl $8, %edx\n"
        "leal (%esi, %edx), %edx\n" /* z5 */
        "movl %edx, -0x60(%ebp)\n" /* z2 */
        "leal (%ecx, %ecx, 8), %eax\n" /* line 159 */
        "leal (%ecx, %eax, 4), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "addl %ecx, %eax\n"
        "sarl $8, %eax\n"
        "addl %eax, %esi\n" /* z5 */
        "movl -0x10(%ebp), %edi\n" /* line 160 | z13 */
        "addl -0x18(%ebp), %edi\n" /* z13 */
        "leal (%edi, %edi, 2), %ecx\n" /* z13 */
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edi, %eax, 4), %eax\n" /* z13 */
        "sarl $8, %eax\n"
        "movl -0xc(%ebp), %ecx\n" /* line 162 */
        "addl %eax, %ecx\n"
        "movl -0xc(%ebp), %edi\n" /* line 163 | z13 */
        "subl %eax, %edi\n" /* z13 */
        "addl %edi, %edx\n" /* line 165 | z13 */
        "movl -0x20(%ebp), %eax\n"
        "movl %edx, 0x14(%eax)\n"
        "subl -0x60(%ebp), %edi\n" /* line 166 | z2, z13 */
        "movl %edi, 0xc(%eax)\n" /* z13 */
        "leal (%esi, %ecx), %eax\n" /* line 167 | z5 */
        "movl -0x20(%ebp), %edx\n"
        "movl %eax, 4(%edx)\n"
        "subl %esi, %ecx\n" /* line 168 | z5 */
        "movl %ecx, 0x1c(%edx)\n"
        "addl $0x20, %edx\n" /* line 170 */
        "movl %edx, -0x20(%ebp)\n"
        "subl $1, -0x28(%ebp)\n" /* line 126 */
        "jne .Lf2150e0_002150fb\n"
        "movl 8(%ebp), %ecx\n" /* data */
        "movl %ecx, -0x2c(%ebp)\n" /* dataptr */
        "movl $8, -0x24(%ebp)\n"
        "movl %ecx, %esi\n" /* z5 */
        "movl %ecx, %edi\n" /* z13 */
        "jmp .Lf2150e0_00215227\n"
        ".Lf2150e0_00215223:\n"
        "movl %edx, %esi\n" /* z5 */
        "movl %edx, %edi\n" /* z13 */
        ".Lf2150e0_00215227:\n"
        "movl (%esi), %edx\n" /* line 177 | z5 */
        "movl 0xe0(%esi), %eax\n" /* z5 */
        "leal (%edx, %eax), %esi\n" /* z5 */
        "subl %eax, %edx\n" /* line 178 */
        "movl %edx, -0x34(%ebp)\n" /* tmp7 */
        "movl 0x20(%edi), %edx\n" /* line 179 | z13 */
        "movl 0xc0(%edi), %eax\n" /* z13 */
        "leal (%edx, %eax), %ecx\n"
        "subl %eax, %edx\n" /* line 180 */
        "movl %edx, -0x38(%ebp)\n" /* tmp6 */
        "movl 0x40(%edi), %edx\n" /* line 181 | z13 */
        "movl 0xa0(%edi), %eax\n" /* z13 */
        "leal (%edx, %eax), %edi\n" /* z13 */
        "movl %edi, -0x40(%ebp)\n" /* z13, tmp2 */
        "subl %eax, %edx\n" /* line 182 */
        "movl %edx, -0x3c(%ebp)\n" /* tmp5 */
        "movl -0x2c(%ebp), %eax\n" /* line 183 | dataptr */
        "movl 0x60(%eax), %edi\n" /* z13 */
        "movl 0x80(%eax), %edx\n"
        "movl %edx, -0x44(%ebp)\n"
        "leal (%edi, %edx), %eax\n" /* z13 */
        "leal (%esi, %eax), %edx\n" /* line 188 | z5 */
        "subl %eax, %esi\n" /* line 189 | z5 */
        "movl %esi, -0x30(%ebp)\n" /* z5, tmp13 */
        "movl -0x40(%ebp), %esi\n" /* line 190 | tmp2, z5 */
        "addl %ecx, %esi\n" /* z5 */
        "movl %esi, -0x5c(%ebp)\n" /* z5, tmp11 */
        "addl %edx, %esi\n" /* line 193 | z5 */
        "movl -0x2c(%ebp), %eax\n" /* dataptr */
        "movl %esi, (%eax)\n" /* z5 */
        "subl -0x5c(%ebp), %edx\n" /* line 194 | tmp11 */
        "movl %edx, 0x80(%eax)\n"
        "subl -0x40(%ebp), %ecx\n" /* line 196 | tmp2 */
        "addl -0x30(%ebp), %ecx\n" /* tmp13 */
        "leal (%ecx, %ecx, 2), %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "sarl $8, %eax\n"
        "movl -0x30(%ebp), %edx\n" /* line 197 | tmp13 */
        "addl %eax, %edx\n"
        "movl -0x2c(%ebp), %ecx\n" /* dataptr */
        "movl %edx, 0x40(%ecx)\n"
        "subl %eax, -0x30(%ebp)\n" /* line 198 | tmp13 */
        "movl -0x30(%ebp), %esi\n" /* tmp13, z5 */
        "movl %esi, 0xc0(%ecx)\n" /* z5 */
        "subl -0x44(%ebp), %edi\n" /* line 202 | z13 */
        "addl -0x3c(%ebp), %edi\n" /* tmp5, z13 */
        "movl -0x34(%ebp), %ecx\n" /* line 204 | tmp7 */
        "addl -0x38(%ebp), %ecx\n" /* tmp6 */
        "movl %edi, %eax\n" /* line 207 | z13 */
        "subl %ecx, %eax\n"
        "leal (%eax, %eax, 2), %esi\n" /* z5 */
        "shll $4, %esi\n" /* z5 */
        "addl %eax, %esi\n" /* z5 */
        "addl %esi, %esi\n" /* z5 */
        "sarl $8, %esi\n" /* z5 */
        "movl %edi, %edx\n" /* line 208 | z13 */
        "shll $4, %edx\n"
        "addl %edi, %edx\n" /* z13 */
        "leal (%edi, %edx, 4), %edx\n" /* z13 */
        "leal (%edi, %edx, 2), %edx\n" /* z13 */
        "sarl $8, %edx\n"
        "leal (%esi, %edx), %edx\n" /* z5 */
        "movl %edx, -0x60(%ebp)\n" /* z2 */
        "leal (%ecx, %ecx, 8), %eax\n" /* line 209 */
        "leal (%ecx, %eax, 4), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "addl %ecx, %eax\n"
        "sarl $8, %eax\n"
        "addl %eax, %esi\n" /* z5 */
        "movl -0x38(%ebp), %edi\n" /* line 210 | tmp6, z13 */
        "addl -0x3c(%ebp), %edi\n" /* tmp5, z13 */
        "leal (%edi, %edi, 2), %ecx\n" /* z13 */
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edi, %eax, 4), %eax\n" /* z13 */
        "sarl $8, %eax\n"
        "movl -0x34(%ebp), %ecx\n" /* line 212 | tmp7 */
        "addl %eax, %ecx\n"
        "movl -0x34(%ebp), %edi\n" /* line 213 | tmp7, z13 */
        "subl %eax, %edi\n" /* z13 */
        "addl %edi, %edx\n" /* line 215 | z13 */
        "movl -0x2c(%ebp), %eax\n" /* dataptr */
        "movl %edx, 0xa0(%eax)\n"
        "subl -0x60(%ebp), %edi\n" /* line 216 | z2, z13 */
        "movl %edi, 0x60(%eax)\n" /* z13 */
        "leal (%esi, %ecx), %eax\n" /* line 217 | z5 */
        "movl -0x2c(%ebp), %edx\n" /* dataptr */
        "movl %eax, 0x20(%edx)\n"
        "subl %esi, %ecx\n" /* line 218 | z5 */
        "movl %ecx, 0xe0(%edx)\n"
        "addl $4, %edx\n" /* line 220 */
        "movl %edx, -0x2c(%ebp)\n" /* dataptr */
        "subl $1, -0x24(%ebp)\n" /* line 176 */
        "jne .Lf2150e0_00215223\n"
        "addl $0x58, %esp\n" /* line 222 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

