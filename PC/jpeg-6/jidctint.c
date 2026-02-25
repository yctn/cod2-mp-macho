/* ASM dump from: jidctint.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jidctint.c */

#include "common_types.h"
#include "imports.h"

void jpeg_idct_islow(j_decompress_ptr cinfo, jpeg_component_info *compptr, JCOEFPTR coef_block, JSAMPARRAY output_buf, JDIMENSION output_col);

/* line 151 */
__attribute__((naked))
void jpeg_idct_islow(j_decompress_ptr cinfo, jpeg_component_info *compptr, JCOEFPTR coef_block, JSAMPARRAY output_buf, JDIMENSION output_col)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 151 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x1e0, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 159 | cinfo */
        "movl 0x128(%eax), %eax\n"
        "subl $-0x80, %eax\n"
        "movl %eax, -0x180(%ebp)\n" /* range_limit */
        "movl 0xc(%ebp), %eax\n" /* line 169 | compptr */
        "movl 0x50(%eax), %eax\n"
        "movl %eax, -0x18c(%ebp)\n" /* quantptr */
        "movl 0x10(%ebp), %eax\n" /* coef_block */
        "movl %eax, -0x190(%ebp)\n" /* inptr */
        "leal -0x108(%ebp), %edx\n" /* workspace */
        "movl %edx, -0x1d0(%ebp)\n"
        "movl %edx, -0x188(%ebp)\n" /* wsptr */
        "movl $8, -0x15c(%ebp)\n"
        "movl %eax, %ecx\n"
        "jmp .Lf214354_00214756\n"
        ".Lf214354_002143a9:\n"
        "movl -0x190(%ebp), %edx\n" /* line 181 | inptr */
        "addl $0x20, %edx\n"
        "movl -0x190(%ebp), %esi\n" /* inptr, tmp0 */
        "cmpw $0, 0x20(%esi)\n" /* tmp0 */
        "je .Lf214354_002147bd\n"
        "movl %esi, %edi\n" /* tmp0, z2 */
        "movl %esi, %ecx\n" /* tmp0 */
        "movl %esi, %eax\n" /* tmp0 */
        "addl $0x60, %eax\n"
        "addl $0x40, %esi\n" /* tmp0 */
        "movl %esi, -0x16c(%ebp)\n" /* tmp0 */
        "addl $0x70, %edi\n" /* z2 */
        "movl %edi, -0x168(%ebp)\n" /* z2 */
        "addl $0x50, %ecx\n"
        "movl %ecx, -0x164(%ebp)\n"
        "movl -0x190(%ebp), %esi\n" /* inptr, tmp0 */
        "addl $0x30, %esi\n" /* tmp0 */
        "movl %esi, -0x160(%ebp)\n" /* tmp0 */
        ".Lf214354_002143f6:\n"
        "movswl (%edx), %esi\n" /* line 206 | tmp0 */
        "movl -0x18c(%ebp), %edi\n" /* quantptr, z2 */
        "imull 0x40(%edi), %esi\n" /* z2, tmp0 */
        "movswl (%eax), %ecx\n" /* line 207 */
        "imull 0xc0(%edi), %ecx\n" /* z2 */
        "leal (%esi, %ecx), %edx\n" /* line 209 | tmp0 */
        "leal (%edx, %edx, 8), %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, %edi\n" /* z2 */
        "shll $5, %edi\n" /* z2 */
        "subl %eax, %edi\n" /* z2 */
        "leal (, %ecx, 4), %edx\n" /* line 210 */
        "movl %ecx, %eax\n"
        "shll $6, %eax\n"
        "subl %edx, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%ecx, %eax, 8), %eax\n"
        "shll $5, %eax\n"
        "addl %ecx, %eax\n"
        "movl %edi, %ecx\n" /* z2 */
        "subl %eax, %ecx\n"
        "leal (%esi, %esi, 2), %edx\n" /* line 211 | tmp0 */
        "shll $5, %edx\n"
        "subl %esi, %edx\n" /* tmp0 */
        "movl %edx, %eax\n"
        "shll $5, %eax\n"
        "addl %eax, %edx\n"
        "leal (%edi, %edx, 2), %edx\n" /* z2 */
        "movl -0x190(%ebp), %eax\n" /* line 213 | inptr */
        "movswl (%eax), %edi\n" /* z2 */
        "movl -0x18c(%ebp), %esi\n" /* quantptr, tmp0 */
        "imull (%esi), %edi\n" /* tmp0, z2 */
        "movl -0x16c(%ebp), %esi\n" /* line 214 | tmp0 */
        "movswl (%esi), %eax\n" /* tmp0 */
        "movl -0x18c(%ebp), %esi\n" /* quantptr, tmp0 */
        "imull 0x80(%esi), %eax\n" /* tmp0 */
        "leal (%edi, %eax), %esi\n" /* line 216 | z2, tmp0 */
        "shll $0xd, %esi\n" /* tmp0 */
        "subl %eax, %edi\n" /* line 217 | z2 */
        "movl %edi, %eax\n" /* z2 */
        "shll $0xd, %eax\n"
        "leal (%edx, %esi), %edi\n" /* line 219 | z2 */
        "movl %edi, -0x110(%ebp)\n" /* z2 */
        "subl %edx, %esi\n" /* line 220 | tmp0 */
        "movl %esi, -0x114(%ebp)\n" /* tmp0 */
        "leal (%ecx, %eax), %edx\n" /* line 221 */
        "movl %edx, -0x118(%ebp)\n"
        "subl %ecx, %eax\n" /* line 222 */
        "movl %eax, -0x11c(%ebp)\n"
        "movl -0x168(%ebp), %ecx\n" /* line 228 */
        "movswl (%ecx), %esi\n" /* tmp0 */
        "movl -0x18c(%ebp), %edi\n" /* quantptr, z2 */
        "imull 0xe0(%edi), %esi\n" /* z2, tmp0 */
        "movl -0x164(%ebp), %eax\n" /* line 229 */
        "movswl (%eax), %ecx\n"
        "imull 0xa0(%edi), %ecx\n" /* z2 */
        "movl -0x160(%ebp), %edx\n" /* line 230 */
        "movswl (%edx), %edx\n"
        "movl %edx, -0x14c(%ebp)\n"
        "imull 0x60(%edi), %edx\n" /* z2 */
        "movl %edx, -0x14c(%ebp)\n"
        "movswl -0x1aa(%ebp), %edi\n" /* line 231 | z2 */
        "movl %edi, -0x154(%ebp)\n" /* z2 */
        "movl -0x18c(%ebp), %eax\n" /* quantptr */
        "imull 0x20(%eax), %edi\n" /* z2 */
        "movl %edi, -0x154(%ebp)\n" /* z2 */
        "addl %esi, %edi\n" /* line 233 | tmp0, z2 */
        "movl %edi, -0x120(%ebp)\n" /* z2 */
        "addl %ecx, %edx\n" /* line 234 */
        "movl %edx, -0x128(%ebp)\n"
        "movl -0x14c(%ebp), %edx\n" /* line 235 */
        "addl %esi, %edx\n" /* tmp0 */
        "movl %edx, -0x130(%ebp)\n"
        "movl -0x154(%ebp), %edi\n" /* line 236 | z2 */
        "addl %ecx, %edi\n" /* z2 */
        "movl %edi, -0x13c(%ebp)\n" /* z2 */
        "movl %edx, %eax\n" /* line 237 */
        "addl %edi, %eax\n" /* z2 */
        "leal (%eax, %eax, 4), %edx\n"
        "movl %edx, %edi\n" /* z2 */
        "shll $4, %edi\n" /* z2 */
        "subl %edx, %edi\n" /* z2 */
        "leal (%eax, %edi, 4), %edx\n"
        "shll $5, %edx\n"
        "addl %eax, %edx\n"
        "movl %edx, -0x1b0(%ebp)\n"
        "leal (%esi, %esi, 8), %edx\n" /* line 239 | tmp0 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "leal (%edx, %eax), %eax\n"
        "shll $3, %eax\n"
        "subl %esi, %eax\n" /* tmp0 */
        "movl %eax, -0x1b4(%ebp)\n"
        "leal (%ecx, %ecx, 2), %edi\n" /* line 240 | z2 */
        "leal (%ecx, %edi, 4), %edi\n" /* z2 */
        "leal (%ecx, %edi, 8), %edi\n" /* z2 */
        "leal (%ecx, %edi, 8), %edi\n" /* z2 */
        "leal (%edi, %edi, 4), %edi\n" /* z2 */
        "shll $2, %edi\n" /* z2 */
        "subl %ecx, %edi\n" /* z2 */
        "movl -0x14c(%ebp), %edx\n" /* line 241 */
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "movl %eax, %ecx\n"
        "shll $5, %ecx\n"
        "subl %eax, %ecx\n"
        "movl %ecx, -0x1b8(%ebp)\n"
        "movl -0x154(%ebp), %esi\n" /* line 242 | tmp0 */
        "leal (%esi, %esi, 2), %edx\n" /* tmp0 */
        "movl %edx, %eax\n"
        "shll $0xa, %eax\n"
        "leal (%edx, %eax), %eax\n"
        "shll $2, %eax\n"
        "subl %esi, %eax\n" /* tmp0 */
        "movl %eax, -0x1bc(%ebp)\n"
        "movl -0x120(%ebp), %eax\n" /* line 243 */
        "leal (%eax, %eax, 2), %ecx\n"
        "shll $3, %ecx\n"
        "subl %eax, %ecx\n"
        "leal (%ecx, %ecx, 4), %ecx\n"
        "leal (%eax, %ecx, 8), %ecx\n"
        "leal (%eax, %ecx, 2), %ecx\n"
        "leal (%eax, %ecx, 4), %ecx\n"
        "negl %ecx\n"
        "movl -0x128(%ebp), %edx\n" /* line 244 */
        "leal (%edx, %edx, 4), %esi\n" /* tmp0 */
        "leal (%edx, %esi, 8), %esi\n" /* tmp0 */
        "shll $8, %esi\n" /* tmp0 */
        "addl %edx, %esi\n" /* tmp0 */
        "leal (%edx, %esi, 2), %esi\n" /* tmp0 */
        "negl %esi\n" /* tmp0 */
        "movl -0x130(%ebp), %eax\n" /* line 245 */
        "shll $2, %eax\n"
        "movl -0x130(%ebp), %edx\n"
        "shll $8, %edx\n"
        "subl %eax, %edx\n"
        "subl -0x130(%ebp), %edx\n"
        "shll $4, %edx\n"
        "addl -0x130(%ebp), %edx\n"
        "movl -0x130(%ebp), %eax\n"
        "leal (%eax, %edx, 4), %edx\n"
        "movl %edx, -0x1dc(%ebp)\n"
        "movl -0x13c(%ebp), %edx\n" /* line 246 */
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "shll $5, %eax\n"
        "subl %eax, %edx\n"
        "movl -0x1b0(%ebp), %eax\n" /* line 248 */
        "subl -0x1dc(%ebp), %eax\n"
        "movl %eax, -0x1dc(%ebp)\n"
        "movl -0x1b0(%ebp), %eax\n" /* line 249 */
        "leal (%eax, %edx, 4), %eax\n"
        "movl %eax, -0x138(%ebp)\n"
        "movl -0x1dc(%ebp), %edx\n" /* line 251 */
        "leal (%ecx, %edx), %eax\n"
        "movl -0x1b4(%ebp), %edx\n"
        "leal (%eax, %edx, 2), %eax\n"
        "movl %eax, -0x144(%ebp)\n"
        "movl -0x138(%ebp), %edx\n" /* line 252 */
        "leal (%esi, %edx), %eax\n" /* tmp0 */
        "addl %eax, %edi\n" /* z2 */
        "addl -0x1dc(%ebp), %esi\n" /* line 253 | tmp0 */
        "movl -0x1b8(%ebp), %eax\n"
        "leal (%esi, %eax, 4), %esi\n" /* tmp0 */
        "addl %edx, %ecx\n" /* line 254 */
        "movl -0x1bc(%ebp), %edx\n"
        "addl %ecx, %edx\n"
        "movl -0x110(%ebp), %ecx\n" /* line 258 */
        "leal 0x400(%ecx, %edx), %eax\n"
        "sarl $0xb, %eax\n"
        "movl -0x188(%ebp), %ecx\n" /* wsptr */
        "movl %eax, (%ecx)\n"
        "subl %edx, -0x110(%ebp)\n" /* line 259 */
        "movl -0x110(%ebp), %eax\n"
        "addl $0x400, %eax\n"
        "sarl $0xb, %eax\n"
        "movl %eax, 0xe0(%ecx)\n"
        "movl -0x118(%ebp), %edx\n" /* line 260 */
        "leal 0x400(%edx, %esi), %eax\n"
        "sarl $0xb, %eax\n"
        "movl %eax, 0x20(%ecx)\n"
        "subl %esi, %edx\n" /* line 261 | tmp0 */
        "movl %edx, %eax\n"
        "addl $0x400, %eax\n"
        "sarl $0xb, %eax\n"
        "movl %eax, 0xc0(%ecx)\n"
        "movl -0x11c(%ebp), %ecx\n" /* line 262 */
        "leal 0x400(%ecx, %edi), %eax\n"
        "sarl $0xb, %eax\n"
        "movl -0x188(%ebp), %esi\n" /* wsptr, tmp0 */
        "movl %eax, 0x40(%esi)\n" /* tmp0 */
        "subl %edi, %ecx\n" /* line 263 | z2 */
        "movl %ecx, %eax\n"
        "addl $0x400, %eax\n"
        "sarl $0xb, %eax\n"
        "movl %eax, 0xa0(%esi)\n" /* tmp0 */
        "movl -0x114(%ebp), %edi\n" /* line 264 | z2 */
        "movl -0x144(%ebp), %edx\n"
        "leal 0x400(%edi, %edx), %eax\n" /* z2 */
        "sarl $0xb, %eax\n"
        "movl %eax, 0x60(%esi)\n" /* tmp0 */
        "subl %edx, %edi\n" /* line 265 | z2 */
        "movl %edi, %eax\n" /* z2 */
        "addl $0x400, %eax\n"
        "sarl $0xb, %eax\n"
        "movl %eax, 0x80(%esi)\n" /* tmp0 */
        "addl $2, -0x190(%ebp)\n" /* line 267 | inptr */
        "addl $4, -0x18c(%ebp)\n" /* line 268 | quantptr */
        "addl $4, %esi\n" /* line 269 | tmp0 */
        "movl %esi, -0x188(%ebp)\n" /* tmp0, wsptr */
        ".Lf214354_00214743:\n"
        "subl $1, -0x15c(%ebp)\n" /* line 171 */
        "je .Lf214354_002147fc\n"
        "movl -0x190(%ebp), %ecx\n" /* inptr */
        ".Lf214354_00214756:\n"
        "movzwl 0x10(%ecx), %ecx\n" /* line 181 */
        "movw %cx, -0x1aa(%ebp)\n"
        "testw %cx, %cx\n"
        "je .Lf214354_002143a9\n"
        /* { scope 2 */
        "movl -0x190(%ebp), %edx\n" /* line 200 | inptr */
        "addl $0x20, %edx\n"
        "movl -0x190(%ebp), %eax\n" /* inptr */
        "addl $0x60, %eax\n"
        "movl -0x190(%ebp), %ecx\n" /* inptr */
        "addl $0x40, %ecx\n"
        "movl %ecx, -0x16c(%ebp)\n"
        "movl -0x190(%ebp), %esi\n" /* inptr, tmp0 */
        "addl $0x70, %esi\n" /* tmp0 */
        "movl %esi, -0x168(%ebp)\n" /* tmp0 */
        "movl -0x190(%ebp), %edi\n" /* inptr, z2 */
        "addl $0x50, %edi\n" /* z2 */
        "movl %edi, -0x164(%ebp)\n" /* z2 */
        "movl -0x190(%ebp), %ecx\n" /* inptr */
        "addl $0x30, %ecx\n"
        "movl %ecx, -0x160(%ebp)\n"
        "jmp .Lf214354_002143f6\n"
        ".Lf214354_002147bd:\n"
        "movl %esi, %edi\n" /* tmp0, z2 */
        "movl %esi, %eax\n" /* tmp0 */
        /* } scope */
        "addl $0x30, %edi\n" /* line 181 | z2 */
        "movl %edi, -0x160(%ebp)\n" /* z2 */
        "cmpw $0, 0x30(%esi)\n" /* tmp0 */
        "je .Lf214354_00214c55\n"
        "movl %esi, %ecx\n" /* tmp0 */
        "movl %eax, %edi\n" /* z2 */
        "addl $0x60, %eax\n"
        "addl $0x40, %ecx\n"
        "movl %ecx, -0x16c(%ebp)\n"
        "addl $0x70, %esi\n" /* tmp0 */
        "movl %esi, -0x168(%ebp)\n" /* tmp0 */
        "addl $0x50, %edi\n" /* z2 */
        "movl %edi, -0x164(%ebp)\n" /* z2 */
        "jmp .Lf214354_002143f6\n"
        ".Lf214354_002147fc:\n"
        "movl -0x1d0(%ebp), %ecx\n" /* line 171 */
        "movl %ecx, -0x10c(%ebp)\n"
        "movl $1, -0x158(%ebp)\n"
        "movl %ecx, %edx\n"
        "jmp .Lf214354_00214bb8\n"
        ".Lf214354_00214819:\n"
        "movl -0x10c(%ebp), %edx\n" /* line 288 */
        "addl $8, %edx\n"
        "movl -0x10c(%ebp), %ecx\n"
        "movl 8(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf214354_00214c1a\n"
        "movl %ecx, %esi\n" /* tmp0 */
        "movl %ecx, %edi\n" /* z2 */
        "movl %ecx, %eax\n"
        "addl $0x18, %eax\n"
        "addl $0x10, %ecx\n"
        "movl %ecx, -0x17c(%ebp)\n"
        "addl $0x1c, %esi\n" /* tmp0 */
        "movl %esi, -0x178(%ebp)\n" /* tmp0 */
        /* { scope 2 */
        ".Lf214354_0021484e:\n"
        "addl $0x14, %edi\n" /* line 304 | z2 */
        "movl %edi, -0x174(%ebp)\n" /* z2 */
        "movl -0x10c(%ebp), %ecx\n"
        "addl $0xc, %ecx\n"
        "movl %ecx, -0x170(%ebp)\n"
        /* } scope */
        ".Lf214354_00214866:\n"
        "movl (%edx), %edi\n" /* line 311 | z2 */
        "movl (%eax), %ecx\n" /* line 312 */
        "leal (%edi, %ecx), %edx\n" /* line 314 | z2 */
        "leal (%edx, %edx, 8), %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, %esi\n" /* tmp0 */
        "shll $5, %esi\n" /* tmp0 */
        "subl %eax, %esi\n" /* tmp0 */
        "leal (, %ecx, 4), %edx\n" /* line 315 */
        "movl %ecx, %eax\n"
        "shll $6, %eax\n"
        "subl %edx, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%ecx, %eax, 8), %eax\n"
        "shll $5, %eax\n"
        "addl %ecx, %eax\n"
        "movl %esi, %ecx\n" /* tmp0 */
        "subl %eax, %ecx\n"
        "leal (%edi, %edi, 2), %eax\n" /* line 316 | z2 */
        "shll $5, %eax\n"
        "subl %edi, %eax\n" /* z2 */
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "addl %edx, %eax\n"
        "leal (%esi, %eax, 2), %eax\n" /* tmp0 */
        "movl -0x10c(%ebp), %esi\n" /* line 318 | tmp0 */
        "movl (%esi), %edi\n" /* tmp0, z2 */
        "movl -0x17c(%ebp), %esi\n" /* tmp0 */
        "movl (%esi), %edx\n" /* tmp0 */
        "leal (%edi, %edx), %esi\n" /* z2, tmp0 */
        "shll $0xd, %esi\n" /* tmp0 */
        "subl %edx, %edi\n" /* line 319 | z2 */
        "movl %edi, %edx\n" /* z2 */
        "shll $0xd, %edx\n"
        "leal (%eax, %esi), %edi\n" /* line 321 | z2 */
        "movl %edi, -0x1a4(%ebp)\n" /* z2, tmp10 */
        "subl %eax, %esi\n" /* line 322 | tmp0 */
        "movl %esi, -0x198(%ebp)\n" /* tmp0, tmp13 */
        "leal (%ecx, %edx), %eax\n" /* line 323 */
        "movl %eax, -0x1a0(%ebp)\n" /* tmp11 */
        "subl %ecx, %edx\n" /* line 324 */
        "movl %edx, -0x19c(%ebp)\n" /* tmp12 */
        "movl -0x178(%ebp), %edx\n" /* line 330 */
        "movl (%edx), %esi\n" /* tmp0 */
        "movl -0x174(%ebp), %edi\n" /* line 331 | z2 */
        "movl (%edi), %ecx\n" /* z2 */
        "movl -0x170(%ebp), %eax\n" /* line 332 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x150(%ebp)\n"
        "movl -0x1a8(%ebp), %edx\n" /* line 335 */
        "addl %esi, %edx\n" /* tmp0 */
        "movl %edx, -0x124(%ebp)\n"
        "addl %ecx, %eax\n" /* line 336 */
        "movl %eax, -0x12c(%ebp)\n"
        "movl -0x150(%ebp), %edi\n" /* line 337 | z2 */
        "addl %esi, %edi\n" /* tmp0, z2 */
        "movl %edi, -0x134(%ebp)\n" /* z2 */
        "movl -0x1a8(%ebp), %eax\n" /* line 338 */
        "addl %ecx, %eax\n"
        "movl %eax, -0x194(%ebp)\n" /* z4 */
        "movl %edi, %eax\n" /* line 339 | z2 */
        "addl -0x194(%ebp), %eax\n" /* z4 */
        "leal (%eax, %eax, 4), %edx\n"
        "movl %edx, %edi\n" /* z2 */
        "shll $4, %edi\n" /* z2 */
        "subl %edx, %edi\n" /* z2 */
        "leal (%eax, %edi, 4), %edx\n"
        "shll $5, %edx\n"
        "addl %eax, %edx\n"
        "movl %edx, -0x1c0(%ebp)\n"
        "leal (%esi, %esi, 8), %edx\n" /* line 341 | tmp0 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "leal (%edx, %eax), %eax\n"
        "shll $3, %eax\n"
        "subl %esi, %eax\n" /* tmp0 */
        "movl %eax, -0x1c4(%ebp)\n"
        "leal (%ecx, %ecx, 2), %edi\n" /* line 342 | z2 */
        "leal (%ecx, %edi, 4), %edi\n" /* z2 */
        "leal (%ecx, %edi, 8), %edi\n" /* z2 */
        "leal (%ecx, %edi, 8), %edi\n" /* z2 */
        "leal (%edi, %edi, 4), %edi\n" /* z2 */
        "shll $2, %edi\n" /* z2 */
        "subl %ecx, %edi\n" /* z2 */
        "movl -0x150(%ebp), %edx\n" /* line 343 */
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "movl %eax, %ecx\n"
        "shll $5, %ecx\n"
        "subl %eax, %ecx\n"
        "movl %ecx, -0x1c8(%ebp)\n"
        "movl -0x1a8(%ebp), %esi\n" /* line 344 | tmp0 */
        "leal (%esi, %esi, 2), %edx\n" /* tmp0 */
        "movl %edx, %eax\n"
        "shll $0xa, %eax\n"
        "leal (%edx, %eax), %eax\n"
        "shll $2, %eax\n"
        "subl %esi, %eax\n" /* tmp0 */
        "movl %eax, -0x1cc(%ebp)\n"
        "movl -0x124(%ebp), %eax\n" /* line 345 */
        "leal (%eax, %eax, 2), %ecx\n"
        "shll $3, %ecx\n"
        "subl %eax, %ecx\n"
        "leal (%ecx, %ecx, 4), %ecx\n"
        "leal (%eax, %ecx, 8), %ecx\n"
        "leal (%eax, %ecx, 2), %ecx\n"
        "leal (%eax, %ecx, 4), %ecx\n"
        "negl %ecx\n"
        "movl -0x12c(%ebp), %edx\n" /* line 346 */
        "leal (%edx, %edx, 4), %esi\n" /* tmp0 */
        "leal (%edx, %esi, 8), %esi\n" /* tmp0 */
        "shll $8, %esi\n" /* tmp0 */
        "addl %edx, %esi\n" /* tmp0 */
        "leal (%edx, %esi, 2), %esi\n" /* tmp0 */
        "negl %esi\n" /* tmp0 */
        "movl -0x134(%ebp), %eax\n" /* line 347 */
        "shll $2, %eax\n"
        "movl -0x134(%ebp), %edx\n"
        "shll $8, %edx\n"
        "subl %eax, %edx\n"
        "subl -0x134(%ebp), %edx\n"
        "shll $4, %edx\n"
        "addl -0x134(%ebp), %edx\n"
        "movl -0x134(%ebp), %eax\n"
        "leal (%eax, %edx, 4), %edx\n"
        "movl %edx, -0x1dc(%ebp)\n"
        "movl -0x194(%ebp), %edx\n" /* line 348 | z4 */
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "shll $5, %eax\n"
        "subl %eax, %edx\n"
        "movl -0x1c0(%ebp), %eax\n" /* line 350 */
        "subl -0x1dc(%ebp), %eax\n"
        "movl %eax, -0x1dc(%ebp)\n"
        "movl -0x1c0(%ebp), %eax\n" /* line 351 */
        "leal (%eax, %edx, 4), %eax\n"
        "movl %eax, -0x140(%ebp)\n"
        "movl -0x1dc(%ebp), %edx\n" /* line 353 */
        "leal (%ecx, %edx), %eax\n"
        "movl -0x1c4(%ebp), %edx\n"
        "leal (%eax, %edx, 2), %eax\n"
        "movl %eax, -0x148(%ebp)\n"
        "movl -0x140(%ebp), %edx\n" /* line 354 */
        "leal (%esi, %edx), %eax\n" /* tmp0 */
        "addl %eax, %edi\n" /* z2 */
        "addl -0x1dc(%ebp), %esi\n" /* line 355 | tmp0 */
        "movl -0x1c8(%ebp), %eax\n"
        "leal (%esi, %eax, 4), %esi\n" /* tmp0 */
        "addl %edx, %ecx\n" /* line 356 */
        "movl -0x1cc(%ebp), %edx\n"
        "addl %ecx, %edx\n"
        "movl -0x1a4(%ebp), %ecx\n" /* line 360 | tmp10 */
        "leal 0x20000(%ecx, %edx), %eax\n"
        "sarl $0x12, %eax\n"
        "andl $0x3ff, %eax\n"
        "movl -0x180(%ebp), %ecx\n" /* range_limit */
        "movzbl (%ecx, %eax), %eax\n"
        "movl -0x184(%ebp), %ecx\n" /* outptr */
        "movb %al, (%ecx)\n"
        "subl %edx, -0x1a4(%ebp)\n" /* line 363 | tmp10 */
        "movl -0x1a4(%ebp), %eax\n" /* tmp10 */
        "addl $0x20000, %eax\n"
        "sarl $0x12, %eax\n"
        "andl $0x3ff, %eax\n"
        "movl -0x180(%ebp), %edx\n" /* range_limit */
        "movzbl (%edx, %eax), %eax\n"
        "movb %al, 7(%ecx)\n"
        "movl -0x1a0(%ebp), %ecx\n" /* line 366 | tmp11 */
        "leal 0x20000(%ecx, %esi), %eax\n"
        "sarl $0x12, %eax\n"
        "andl $0x3ff, %eax\n"
        "movzbl (%edx, %eax), %eax\n"
        "movl -0x184(%ebp), %edx\n" /* outptr */
        "movb %al, 1(%edx)\n"
        "subl %esi, %ecx\n" /* line 369 | tmp0 */
        "movl %ecx, %eax\n"
        "addl $0x20000, %eax\n"
        "sarl $0x12, %eax\n"
        "andl $0x3ff, %eax\n"
        "movl -0x180(%ebp), %ecx\n" /* range_limit */
        "movzbl (%ecx, %eax), %eax\n"
        "movb %al, 6(%edx)\n"
        "movl -0x19c(%ebp), %esi\n" /* line 372 | tmp12, tmp0 */
        "leal 0x20000(%esi, %edi), %eax\n" /* tmp0 */
        "sarl $0x12, %eax\n"
        "andl $0x3ff, %eax\n"
        "movzbl (%ecx, %eax), %eax\n"
        "movb %al, 2(%edx)\n"
        "subl %edi, %esi\n" /* line 375 | z2, tmp0 */
        "movl %esi, %eax\n" /* tmp0 */
        "addl $0x20000, %eax\n"
        "sarl $0x12, %eax\n"
        "andl $0x3ff, %eax\n"
        "movzbl (%ecx, %eax), %eax\n"
        "movb %al, 5(%edx)\n"
        "movl -0x198(%ebp), %edi\n" /* line 378 | tmp13, z2 */
        "movl -0x148(%ebp), %edx\n"
        "leal 0x20000(%edi, %edx), %eax\n" /* z2 */
        "sarl $0x12, %eax\n"
        "andl $0x3ff, %eax\n"
        "movzbl (%ecx, %eax), %eax\n"
        "movl -0x184(%ebp), %ecx\n" /* outptr */
        "movb %al, 3(%ecx)\n"
        "subl %edx, %edi\n" /* line 381 | z2 */
        "movl %edi, %eax\n" /* z2 */
        "addl $0x20000, %eax\n"
        "sarl $0x12, %eax\n"
        "andl $0x3ff, %eax\n"
        "movl -0x180(%ebp), %esi\n" /* range_limit, tmp0 */
        "movzbl (%esi, %eax), %eax\n" /* tmp0 */
        "movb %al, 4(%ecx)\n"
        "addl $0x20, -0x10c(%ebp)\n" /* line 385 */
        ".Lf214354_00214b9e:\n"
        "addl $1, -0x158(%ebp)\n"
        "cmpl $9, -0x158(%ebp)\n" /* line 277 */
        "je .Lf214354_00214c89\n"
        "movl -0x10c(%ebp), %edx\n"
        ".Lf214354_00214bb8:\n"
        "movl 0x18(%ebp), %eax\n" /* line 278 | output_col */
        "movl -0x158(%ebp), %esi\n" /* tmp0 */
        "movl 0x14(%ebp), %edi\n" /* output_buf, z2 */
        "addl -4(%edi, %esi, 4), %eax\n" /* z2 */
        "movl %eax, -0x184(%ebp)\n" /* outptr */
        "movl 4(%edx), %edx\n" /* line 288 */
        "movl %edx, -0x1a8(%ebp)\n"
        "testl %edx, %edx\n"
        "je .Lf214354_00214819\n"
        /* { scope 2 */
        "movl -0x10c(%ebp), %edx\n" /* line 304 */
        "addl $8, %edx\n"
        "movl -0x10c(%ebp), %eax\n"
        "addl $0x18, %eax\n"
        "movl -0x10c(%ebp), %ecx\n"
        "addl $0x10, %ecx\n"
        "movl %ecx, -0x17c(%ebp)\n"
        "movl -0x10c(%ebp), %esi\n" /* tmp0 */
        "addl $0x1c, %esi\n" /* tmp0 */
        "movl %esi, -0x178(%ebp)\n" /* tmp0 */
        "movl -0x10c(%ebp), %edi\n" /* z2 */
        "jmp .Lf214354_0021484e\n"
        ".Lf214354_00214c1a:\n"
        "movl %ecx, %esi\n" /* tmp0 */
        "movl %ecx, %edi\n" /* z2 */
        /* } scope */
        "addl $0xc, %esi\n" /* line 288 | tmp0 */
        "movl %esi, -0x170(%ebp)\n" /* tmp0 */
        "movl 0xc(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf214354_00214c93\n"
        "movl %edi, %esi\n" /* z2, tmp0 */
        "movl %edi, %eax\n" /* z2 */
        "addl $0x18, %eax\n"
        "addl $0x10, %edi\n" /* z2 */
        "movl %edi, -0x17c(%ebp)\n" /* z2 */
        "addl $0x1c, %ecx\n"
        "movl %ecx, -0x178(%ebp)\n"
        "addl $0x14, %esi\n" /* tmp0 */
        "movl %esi, -0x174(%ebp)\n" /* tmp0 */
        "jmp .Lf214354_00214866\n"
        ".Lf214354_00214c55:\n"
        "addl $0x40, %eax\n" /* line 181 */
        "movl %eax, -0x16c(%ebp)\n"
        "movl -0x190(%ebp), %ecx\n" /* inptr */
        "cmpw $0, 0x40(%ecx)\n"
        "je .Lf214354_00214ccb\n"
        "movl %ecx, %esi\n" /* tmp0 */
        "movl %ecx, %eax\n"
        "addl $0x60, %eax\n"
        "addl $0x70, %ecx\n"
        "movl %ecx, -0x168(%ebp)\n"
        "addl $0x50, %esi\n" /* tmp0 */
        "movl %esi, -0x164(%ebp)\n" /* tmp0 */
        "jmp .Lf214354_002143f6\n"
        ".Lf214354_00214c89:\n"
        "addl $0x1e0, %esp\n" /* line 387 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf214354_00214c93:\n"
        "addl $0x10, %edi\n" /* line 288 | z2 */
        "movl %edi, -0x17c(%ebp)\n" /* z2 */
        "movl -0x10c(%ebp), %eax\n"
        "movl 0x10(%eax), %esi\n" /* tmp0 */
        "testl %esi, %esi\n" /* tmp0 */
        "je .Lf214354_00214d67\n"
        "movl %eax, %ecx\n"
        "movl %eax, %esi\n" /* tmp0 */
        "addl $0x18, %eax\n"
        "addl $0x1c, %ecx\n"
        "movl %ecx, -0x178(%ebp)\n"
        "addl $0x14, %esi\n" /* tmp0 */
        "movl %esi, -0x174(%ebp)\n" /* tmp0 */
        "jmp .Lf214354_00214866\n"
        ".Lf214354_00214ccb:\n"
        "movl %ecx, %edi\n" /* z2 */
        "movl %ecx, %eax\n"
        "addl $0x50, %edi\n" /* line 181 | z2 */
        "movl %edi, -0x164(%ebp)\n" /* z2 */
        "cmpw $0, 0x50(%ecx)\n"
        "jne .Lf214354_00214ded\n"
        "addl $0x60, %eax\n"
        "movl -0x190(%ebp), %esi\n" /* inptr, tmp0 */
        "cmpw $0, 0x60(%esi)\n" /* tmp0 */
        "jne .Lf214354_00214e11\n"
        "movl %esi, %edi\n" /* tmp0, z2 */
        "movl %esi, %ecx\n" /* tmp0 */
        "addl $0x70, %edi\n" /* z2 */
        "movl %edi, -0x168(%ebp)\n" /* z2 */
        "cmpw $0, 0x70(%esi)\n" /* tmp0 */
        "jne .Lf214354_002143f6\n"
        /* { scope 2 */
        "movswl (%esi), %eax\n" /* line 186 | tmp0, dcval */
        "movl -0x18c(%ebp), %esi\n" /* quantptr, tmp0 */
        "imull (%esi), %eax\n" /* tmp0, dcval */
        "shll $2, %eax\n" /* dcval */
        "movl -0x188(%ebp), %edi\n" /* line 188 | wsptr, z2 */
        "movl %eax, (%edi)\n" /* z2 */
        "movl %eax, 0x20(%edi)\n" /* line 189 | z2 */
        "movl %eax, 0x40(%edi)\n" /* line 190 | z2 */
        "movl %eax, 0x60(%edi)\n" /* line 191 | z2 */
        "movl %eax, 0x80(%edi)\n" /* line 192 | z2 */
        "movl %eax, 0xa0(%edi)\n" /* line 193 | z2 */
        "movl %eax, 0xc0(%edi)\n" /* line 194 | z2 */
        "movl %eax, 0xe0(%edi)\n" /* line 195 | z2 */
        "addl $2, %ecx\n" /* line 197 */
        "movl %ecx, -0x190(%ebp)\n" /* inptr */
        "addl $4, %esi\n" /* line 198 | tmp0 */
        "movl %esi, -0x18c(%ebp)\n" /* tmp0, quantptr */
        "addl $4, %edi\n" /* line 199 | z2 */
        "movl %edi, -0x188(%ebp)\n" /* z2, wsptr */
        "jmp .Lf214354_00214743\n"
        ".Lf214354_00214d67:\n"
        "movl %eax, %edi\n" /* z2 */
        /* } scope */
        "addl $0x14, %edi\n" /* line 288 | z2 */
        "movl %edi, -0x174(%ebp)\n" /* z2 */
        "movl -0x10c(%ebp), %eax\n"
        "movl 0x14(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf214354_00214dfe\n"
        "addl $0x18, %eax\n"
        "movl -0x10c(%ebp), %esi\n" /* tmp0 */
        "movl 0x18(%esi), %edi\n" /* tmp0, z2 */
        "testl %edi, %edi\n" /* z2 */
        "jne .Lf214354_00214e1f\n"
        "movl %esi, %edi\n" /* tmp0, z2 */
        "movl %esi, %ecx\n" /* tmp0 */
        "addl $0x1c, %edi\n" /* z2 */
        "movl %edi, -0x178(%ebp)\n" /* z2 */
        "movl 0x1c(%esi), %esi\n" /* tmp0 */
        "testl %esi, %esi\n" /* tmp0 */
        "jne .Lf214354_00214866\n"
        /* { scope 2 */
        "movl (%ecx), %eax\n" /* line 292 */
        "addl $0x10, %eax\n"
        "sarl $5, %eax\n"
        "andl $0x3ff, %eax\n"
        "movl -0x180(%ebp), %esi\n" /* range_limit, tmp0 */
        "movzbl (%esi, %eax), %eax\n" /* tmp0 */
        "movl -0x184(%ebp), %edi\n" /* line 294 | outptr, z2 */
        "movb %al, (%edi)\n" /* z2 */
        "movb %al, 1(%edi)\n" /* line 295 | z2 */
        "movb %al, 2(%edi)\n" /* line 296 | z2 */
        "movb %al, 3(%edi)\n" /* line 297 | z2 */
        "movb %al, 4(%edi)\n" /* line 298 | z2 */
        "movb %al, 5(%edi)\n" /* line 299 | z2 */
        "movb %al, 6(%edi)\n" /* line 300 | z2 */
        "movb %al, 7(%edi)\n" /* line 301 | z2 */
        "addl $0x20, %ecx\n" /* line 303 */
        "movl %ecx, -0x10c(%ebp)\n"
        "jmp .Lf214354_00214b9e\n"
        /* } scope */
        ".Lf214354_00214ded:\n"
        "addl $0x60, %eax\n" /* line 181 */
        "addl $0x70, %ecx\n"
        "movl %ecx, -0x168(%ebp)\n"
        "jmp .Lf214354_002143f6\n"
        ".Lf214354_00214dfe:\n"
        "movl %eax, %ecx\n"
        "addl $0x18, %eax\n" /* line 288 */
        "addl $0x1c, %ecx\n"
        "movl %ecx, -0x178(%ebp)\n"
        "jmp .Lf214354_00214866\n"
        ".Lf214354_00214e11:\n"
        "addl $0x70, %esi\n" /* line 181 | tmp0 */
        "movl %esi, -0x168(%ebp)\n" /* tmp0 */
        "jmp .Lf214354_002143f6\n"
        ".Lf214354_00214e1f:\n"
        "addl $0x1c, %esi\n" /* line 288 | tmp0 */
        "movl %esi, -0x178(%ebp)\n" /* tmp0 */
        "jmp .Lf214354_00214866\n"
    );
}

