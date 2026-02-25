/* ASM dump from: jfdctint.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jfdctint.c */

#include "common_types.h"
#include "imports.h"

void jpeg_fdct_islow(DCTELEM *data);

/* line 141 */
__attribute__((naked))
void jpeg_fdct_islow(DCTELEM *data)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 141 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x64, %esp\n"
        "movl 8(%ebp), %eax\n" /* data */
        "movl %eax, -0x34(%ebp)\n"
        "movl $8, -0x3c(%ebp)\n"
        "movl %eax, %ecx\n"
        "jmp .Lf215358_00215373\n"
        ".Lf215358_00215371:\n"
        "movl %edx, %ecx\n"
        ".Lf215358_00215373:\n"
        "movl (%ecx), %edx\n" /* line 155 */
        "movl 0x1c(%ecx), %eax\n"
        "leal (%edx, %eax), %esi\n" /* tmp12 */
        "subl %eax, %edx\n" /* line 156 */
        "movl %edx, -0x1c(%ebp)\n"
        "movl 4(%ecx), %edx\n" /* line 157 */
        "movl 0x18(%ecx), %eax\n"
        "leal (%edx, %eax), %edi\n" /* tmp13 */
        "subl %eax, %edx\n" /* line 158 */
        "movl %edx, -0x18(%ebp)\n"
        "movl 8(%ecx), %edx\n" /* line 159 */
        "movl 0x14(%ecx), %eax\n"
        "leal (%edx, %eax), %ecx\n"
        "movl %ecx, -0xc(%ebp)\n"
        "subl %eax, %edx\n" /* line 160 */
        "movl %edx, -0x14(%ebp)\n"
        "movl -0x34(%ebp), %eax\n" /* line 161 */
        "movl 0xc(%eax), %edx\n"
        "movl 0x10(%eax), %eax\n"
        "leal (%edx, %eax), %ecx\n"
        "subl %eax, %edx\n" /* line 162 */
        "movl %edx, -0x10(%ebp)\n"
        "leal (%esi, %ecx), %edx\n" /* line 168 | tmp12 */
        "subl %ecx, %esi\n" /* line 169 | tmp12 */
        "movl -0xc(%ebp), %eax\n" /* line 170 */
        "addl %edi, %eax\n" /* tmp13 */
        "movl %eax, -0x64(%ebp)\n" /* tmp11 */
        "subl -0xc(%ebp), %edi\n" /* line 171 | tmp13 */
        "leal (%edx, %eax), %eax\n" /* line 173 */
        "shll $2, %eax\n"
        "movl -0x34(%ebp), %ecx\n"
        "movl %eax, (%ecx)\n"
        "subl -0x64(%ebp), %edx\n" /* line 174 | tmp11 */
        "shll $2, %edx\n"
        "movl %edx, 0x10(%ecx)\n"
        "leal (%esi, %edi), %edx\n" /* line 176 | tmp12 */
        "leal (%edx, %edx, 8), %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, %ecx\n"
        "shll $5, %ecx\n"
        "subl %eax, %ecx\n"
        "leal (%esi, %esi, 2), %eax\n" /* line 177 | tmp12 */
        "shll $5, %eax\n"
        "subl %esi, %eax\n" /* tmp12 */
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "addl %edx, %eax\n"
        "leal 0x400(%ecx, %eax, 2), %eax\n"
        "sarl $0xb, %eax\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %eax, 8(%edx)\n"
        "leal (, %edi, 4), %edx\n" /* line 179 */
        "movl %edi, %eax\n" /* tmp13 */
        "shll $6, %eax\n"
        "subl %edx, %eax\n"
        "subl %edi, %eax\n" /* tmp13 */
        "leal (%edi, %eax, 8), %eax\n" /* tmp13 */
        "shll $5, %eax\n"
        "addl %edi, %eax\n" /* tmp13 */
        "subl %eax, %ecx\n"
        "addl $0x400, %ecx\n"
        "sarl $0xb, %ecx\n"
        "movl -0x34(%ebp), %edi\n" /* tmp13 */
        "movl %ecx, 0x18(%edi)\n" /* tmp13 */
        "movl -0x1c(%ebp), %edi\n" /* line 187 | tmp13 */
        "addl -0x10(%ebp), %edi\n" /* tmp13 */
        "movl -0x18(%ebp), %eax\n" /* line 188 */
        "addl -0x14(%ebp), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl -0x18(%ebp), %edx\n" /* line 189 */
        "addl -0x10(%ebp), %edx\n"
        "movl %edx, -0x28(%ebp)\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 190 */
        "addl -0x14(%ebp), %ecx\n"
        "movl %ecx, -0x30(%ebp)\n"
        "movl %edx, %eax\n" /* line 191 */
        "addl %ecx, %eax\n"
        "leal (%eax, %eax, 4), %edx\n"
        "movl %edx, %esi\n" /* tmp12 */
        "shll $4, %esi\n" /* tmp12 */
        "subl %edx, %esi\n" /* tmp12 */
        "leal (%eax, %esi, 4), %esi\n" /* tmp12 */
        "shll $5, %esi\n" /* tmp12 */
        "addl %eax, %esi\n" /* tmp12 */
        "leal (%edi, %edi, 2), %ecx\n" /* line 197 | tmp13 */
        "shll $3, %ecx\n"
        "subl %edi, %ecx\n" /* tmp13 */
        "leal (%ecx, %ecx, 4), %ecx\n"
        "leal (%edi, %ecx, 8), %ecx\n" /* tmp13 */
        "leal (%edi, %ecx, 2), %ecx\n" /* tmp13 */
        "leal (%edi, %ecx, 4), %ecx\n" /* tmp13 */
        "negl %ecx\n"
        "movl -0x20(%ebp), %eax\n" /* line 198 */
        "leal (%eax, %eax, 4), %edi\n" /* tmp13 */
        "leal (%eax, %edi, 8), %edi\n" /* tmp13 */
        "shll $8, %edi\n" /* tmp13 */
        "addl %eax, %edi\n" /* tmp13 */
        "leal (%eax, %edi, 2), %edi\n" /* tmp13 */
        "negl %edi\n" /* tmp13 */
        "movl -0x28(%ebp), %eax\n" /* line 199 */
        "shll $2, %eax\n"
        "movl -0x28(%ebp), %edx\n"
        "shll $8, %edx\n"
        "subl %eax, %edx\n"
        "subl -0x28(%ebp), %edx\n"
        "shll $4, %edx\n"
        "addl -0x28(%ebp), %edx\n"
        "movl -0x28(%ebp), %eax\n"
        "leal (%eax, %edx, 4), %edx\n"
        "movl %edx, -0x68(%ebp)\n"
        "movl -0x30(%ebp), %edx\n" /* line 200 */
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "shll $5, %eax\n"
        "subl %eax, %edx\n"
        "movl %esi, %eax\n" /* line 202 | tmp12 */
        "subl -0x68(%ebp), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "leal (%esi, %edx, 4), %esi\n" /* line 203 | tmp12 */
        "movl -0x10(%ebp), %edx\n" /* line 205 */
        "leal (%edx, %edx, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "shll $3, %eax\n"
        "subl -0x10(%ebp), %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "movl -0x24(%ebp), %edx\n"
        "leal 0x400(%edx, %eax), %eax\n"
        "sarl $0xb, %eax\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %eax, 0x1c(%edx)\n"
        "movl -0x14(%ebp), %edx\n" /* line 206 */
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "subl %edx, %eax\n"
        "addl %edi, %eax\n" /* tmp13 */
        "leal 0x400(%esi, %eax), %eax\n" /* tmp12 */
        "sarl $0xb, %eax\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %eax, 0x14(%edx)\n"
        "movl -0x18(%ebp), %edx\n" /* line 207 */
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "leal (%edi, %edx, 4), %edx\n" /* tmp13 */
        "movl -0x24(%ebp), %edi\n" /* tmp13 */
        "leal 0x400(%edi, %edx), %eax\n" /* tmp13 */
        "sarl $0xb, %eax\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %eax, 0xc(%edx)\n"
        "movl -0x1c(%ebp), %edi\n" /* line 208 | tmp13 */
        "leal (%edi, %edi, 2), %eax\n" /* tmp13 */
        "movl %eax, %edx\n"
        "shll $0xa, %edx\n"
        "addl %edx, %eax\n"
        "shll $2, %eax\n"
        "subl %edi, %eax\n" /* tmp13 */
        "addl %ecx, %eax\n"
        "leal 0x400(%esi, %eax), %eax\n" /* tmp12 */
        "sarl $0xb, %eax\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %eax, 4(%edx)\n"
        "addl $0x20, %edx\n" /* line 210 */
        "movl %edx, -0x34(%ebp)\n"
        "subl $1, -0x3c(%ebp)\n" /* line 154 */
        "jne .Lf215358_00215371\n"
        "movl 8(%ebp), %ecx\n" /* data */
        "movl %ecx, -0x40(%ebp)\n" /* dataptr */
        "movl $8, -0x38(%ebp)\n"
        "movl %ecx, %edi\n" /* tmp13 */
        "jmp .Lf215358_0021558c\n"
        ".Lf215358_0021558a:\n"
        "movl %edx, %edi\n" /* tmp13 */
        ".Lf215358_0021558c:\n"
        "movl (%edi), %edx\n" /* line 220 | tmp13 */
        "movl 0xe0(%edi), %eax\n" /* tmp13 */
        "leal (%edx, %eax), %edi\n" /* tmp13 */
        "subl %eax, %edx\n" /* line 221 */
        "movl %edx, -0x50(%ebp)\n" /* tmp7 */
        "movl -0x40(%ebp), %eax\n" /* line 222 | dataptr */
        "movl 0x20(%eax), %edx\n"
        "movl %eax, %ecx\n"
        "movl 0xc0(%eax), %eax\n"
        "leal (%edx, %eax), %esi\n" /* tmp12 */
        "subl %eax, %edx\n" /* line 223 */
        "movl %edx, -0x54(%ebp)\n" /* tmp6 */
        "movl 0x40(%ecx), %edx\n" /* line 224 */
        "movl 0xa0(%ecx), %eax\n"
        "leal (%edx, %eax), %ecx\n"
        "movl %ecx, -0x60(%ebp)\n" /* tmp2 */
        "subl %eax, %edx\n" /* line 225 */
        "movl %edx, -0x58(%ebp)\n" /* tmp5 */
        "movl -0x40(%ebp), %eax\n" /* line 226 | dataptr */
        "movl 0x60(%eax), %edx\n"
        "movl 0x80(%eax), %eax\n"
        "leal (%edx, %eax), %ecx\n"
        "subl %eax, %edx\n" /* line 227 */
        "movl %edx, -0x5c(%ebp)\n" /* tmp4 */
        "leal (%edi, %ecx), %edx\n" /* line 233 | tmp13 */
        "subl %ecx, %edi\n" /* line 234 | tmp13 */
        "movl -0x60(%ebp), %eax\n" /* line 235 | tmp2 */
        "addl %esi, %eax\n" /* tmp12 */
        "movl %eax, -0x64(%ebp)\n" /* tmp11 */
        "subl -0x60(%ebp), %esi\n" /* line 236 | tmp2, tmp12 */
        "leal 2(%edx, %eax), %eax\n" /* line 238 */
        "sarl $2, %eax\n"
        "movl -0x40(%ebp), %ecx\n" /* dataptr */
        "movl %eax, (%ecx)\n"
        "subl -0x64(%ebp), %edx\n" /* line 239 | tmp11 */
        "addl $2, %edx\n"
        "sarl $2, %edx\n"
        "movl %edx, 0x80(%ecx)\n"
        "leal (%edi, %esi), %edx\n" /* line 241 | tmp13 */
        "leal (%edx, %edx, 8), %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, %ecx\n"
        "shll $5, %ecx\n"
        "subl %eax, %ecx\n"
        "leal (%edi, %edi, 2), %eax\n" /* line 242 | tmp13 */
        "shll $5, %eax\n"
        "subl %edi, %eax\n" /* tmp13 */
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "addl %edx, %eax\n"
        "leal 0x4000(%ecx, %eax, 2), %eax\n"
        "sarl $0xf, %eax\n"
        "movl -0x40(%ebp), %edi\n" /* dataptr, tmp13 */
        "movl %eax, 0x40(%edi)\n" /* tmp13 */
        "leal (, %esi, 4), %edx\n" /* line 244 */
        "movl %esi, %eax\n" /* tmp12 */
        "shll $6, %eax\n"
        "subl %edx, %eax\n"
        "subl %esi, %eax\n" /* tmp12 */
        "leal (%esi, %eax, 8), %eax\n" /* tmp12 */
        "shll $5, %eax\n"
        "addl %esi, %eax\n" /* tmp12 */
        "subl %eax, %ecx\n"
        "addl $0x4000, %ecx\n"
        "sarl $0xf, %ecx\n"
        "movl %ecx, 0xc0(%edi)\n" /* tmp13 */
        "movl -0x50(%ebp), %edi\n" /* line 252 | tmp7, tmp13 */
        "addl -0x5c(%ebp), %edi\n" /* tmp4, tmp13 */
        "movl -0x54(%ebp), %eax\n" /* line 253 | tmp6 */
        "addl -0x58(%ebp), %eax\n" /* tmp5 */
        "movl %eax, -0x4c(%ebp)\n" /* z2 */
        "movl -0x54(%ebp), %edx\n" /* line 254 | tmp6 */
        "addl -0x5c(%ebp), %edx\n" /* tmp4 */
        "movl %edx, -0x48(%ebp)\n" /* z3 */
        "movl -0x50(%ebp), %ecx\n" /* line 255 | tmp7 */
        "addl -0x58(%ebp), %ecx\n" /* tmp5 */
        "movl %ecx, -0x44(%ebp)\n" /* z4 */
        "movl %edx, %eax\n" /* line 256 */
        "addl %ecx, %eax\n"
        "leal (%eax, %eax, 4), %edx\n"
        "movl %edx, %esi\n" /* tmp12 */
        "shll $4, %esi\n" /* tmp12 */
        "subl %edx, %esi\n" /* tmp12 */
        "leal (%eax, %esi, 4), %esi\n" /* tmp12 */
        "shll $5, %esi\n" /* tmp12 */
        "addl %eax, %esi\n" /* tmp12 */
        "leal (%edi, %edi, 2), %ecx\n" /* line 262 | tmp13 */
        "shll $3, %ecx\n"
        "subl %edi, %ecx\n" /* tmp13 */
        "leal (%ecx, %ecx, 4), %ecx\n"
        "leal (%edi, %ecx, 8), %ecx\n" /* tmp13 */
        "leal (%edi, %ecx, 2), %ecx\n" /* tmp13 */
        "leal (%edi, %ecx, 4), %ecx\n" /* tmp13 */
        "negl %ecx\n"
        "movl -0x4c(%ebp), %eax\n" /* line 263 | z2 */
        "leal (%eax, %eax, 4), %edi\n" /* tmp13 */
        "leal (%eax, %edi, 8), %edi\n" /* tmp13 */
        "shll $8, %edi\n" /* tmp13 */
        "addl %eax, %edi\n" /* tmp13 */
        "leal (%eax, %edi, 2), %edi\n" /* tmp13 */
        "negl %edi\n" /* tmp13 */
        "movl -0x48(%ebp), %eax\n" /* line 264 | z3 */
        "shll $2, %eax\n"
        "movl -0x48(%ebp), %edx\n" /* z3 */
        "shll $8, %edx\n"
        "subl %eax, %edx\n"
        "subl -0x48(%ebp), %edx\n" /* z3 */
        "shll $4, %edx\n"
        "addl -0x48(%ebp), %edx\n" /* z3 */
        "movl -0x48(%ebp), %eax\n" /* z3 */
        "leal (%eax, %edx, 4), %edx\n"
        "movl %edx, -0x68(%ebp)\n"
        "movl -0x44(%ebp), %edx\n" /* line 265 | z4 */
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "shll $5, %eax\n"
        "subl %eax, %edx\n"
        "movl %esi, %eax\n" /* line 267 | tmp12 */
        "subl -0x68(%ebp), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "leal (%esi, %edx, 4), %esi\n" /* line 268 | tmp12 */
        "movl -0x5c(%ebp), %edx\n" /* line 270 | tmp4 */
        "leal (%edx, %edx, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "shll $3, %eax\n"
        "subl -0x5c(%ebp), %eax\n" /* tmp4 */
        "leal (%ecx, %eax, 2), %eax\n"
        "movl -0x2c(%ebp), %edx\n"
        "leal 0x4000(%edx, %eax), %eax\n"
        "sarl $0xf, %eax\n"
        "movl -0x40(%ebp), %edx\n" /* dataptr */
        "movl %eax, 0xe0(%edx)\n"
        "movl -0x58(%ebp), %edx\n" /* line 272 | tmp5 */
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "subl %edx, %eax\n"
        "addl %edi, %eax\n" /* tmp13 */
        "leal 0x4000(%esi, %eax), %eax\n" /* tmp12 */
        "sarl $0xf, %eax\n"
        "movl -0x40(%ebp), %edx\n" /* dataptr */
        "movl %eax, 0xa0(%edx)\n"
        "movl -0x54(%ebp), %edx\n" /* line 274 | tmp6 */
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "leal (%edi, %edx, 4), %edx\n" /* tmp13 */
        "movl -0x2c(%ebp), %edi\n" /* tmp13 */
        "leal 0x4000(%edi, %edx), %eax\n" /* tmp13 */
        "sarl $0xf, %eax\n"
        "movl -0x40(%ebp), %edx\n" /* dataptr */
        "movl %eax, 0x60(%edx)\n"
        "movl -0x50(%ebp), %edi\n" /* line 276 | tmp7, tmp13 */
        "leal (%edi, %edi, 2), %eax\n" /* tmp13 */
        "movl %eax, %edx\n"
        "shll $0xa, %edx\n"
        "addl %edx, %eax\n"
        "shll $2, %eax\n"
        "subl %edi, %eax\n" /* tmp13 */
        "addl %ecx, %eax\n"
        "leal 0x4000(%esi, %eax), %eax\n" /* tmp12 */
        "sarl $0xf, %eax\n"
        "movl -0x40(%ebp), %edx\n" /* dataptr */
        "movl %eax, 0x20(%edx)\n"
        "addl $4, %edx\n" /* line 279 */
        "movl %edx, -0x40(%ebp)\n" /* dataptr */
        "subl $1, -0x38(%ebp)\n" /* line 219 */
        "jne .Lf215358_0021558a\n"
        "addl $0x64, %esp\n" /* line 281 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

