/* ASM dump from: jidctfst.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jidctfst.c */

#include "common_types.h"
#include "imports.h"

void jpeg_idct_ifast(j_decompress_ptr cinfo, jpeg_component_info *compptr, JCOEFPTR coef_block, JSAMPARRAY output_buf, JDIMENSION output_col);

/* line 171 */
__attribute__((naked))
void jpeg_idct_ifast(j_decompress_ptr cinfo, jpeg_component_info *compptr, JCOEFPTR coef_block, JSAMPARRAY output_buf, JDIMENSION output_col)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 171 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x1a0, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 179 | cinfo */
        "movl 0x128(%eax), %eax\n"
        "subl $-0x80, %eax\n"
        "movl %eax, -0x150(%ebp)\n" /* range_limit */
        "movl 0xc(%ebp), %eax\n" /* line 188 | compptr */
        "movl 0x50(%eax), %eax\n"
        "movl %eax, -0x15c(%ebp)\n" /* quantptr */
        "movl 0x10(%ebp), %eax\n" /* coef_block */
        "movl %eax, -0x160(%ebp)\n" /* inptr */
        "leal -0x108(%ebp), %edx\n" /* workspace */
        "movl %edx, -0x190(%ebp)\n"
        "movl %edx, -0x158(%ebp)\n" /* wsptr */
        "movl $8, -0x134(%ebp)\n"
        "movl %eax, %ecx\n"
        "jmp .Lf213b18_00213db6\n"
        ".Lf213b18_00213b6d:\n"
        "movl -0x160(%ebp), %edx\n" /* line 200 | inptr */
        "addl $0x20, %edx\n"
        "movl -0x160(%ebp), %esi\n" /* inptr, z5 */
        "cmpw $0, 0x20(%esi)\n" /* z5 */
        "je .Lf213b18_00213dff\n"
        "movl %esi, %edi\n" /* z5, z11 */
        "movl %esi, %eax\n" /* z5 */
        "addl $0x40, %eax\n"
        "movl %esi, %ecx\n" /* z5 */
        "addl $0x60, %ecx\n"
        "addl $0x30, %esi\n" /* z5 */
        "movl %esi, -0x140(%ebp)\n" /* z5 */
        /* { scope 2 */
        ".Lf213b18_00213b9c:\n"
        "addl $0x50, %edi\n" /* line 219 | z11 */
        "movl %edi, -0x13c(%ebp)\n" /* z11 */
        "movl -0x160(%ebp), %esi\n" /* inptr, z5 */
        "addl $0x70, %esi\n" /* z5 */
        "movl %esi, -0x138(%ebp)\n" /* z5 */
        "movl -0x160(%ebp), %edi\n" /* inptr, z11 */
        /* } scope */
        ".Lf213b18_00213bba:\n"
        "movswl (%edi), %esi\n" /* line 224 | z11, z5 */
        "movl -0x15c(%ebp), %edi\n" /* quantptr, z11 */
        "imull (%edi), %esi\n" /* z11, z5 */
        "movswl (%edx), %edx\n" /* line 225 */
        "imull 0x40(%edi), %edx\n" /* z11 */
        "movswl (%eax), %eax\n" /* line 226 */
        "imull 0x80(%edi), %eax\n" /* z11 */
        "movswl (%ecx), %ecx\n" /* line 227 */
        "imull 0xc0(%edi), %ecx\n" /* z11 */
        "leal (%esi, %eax), %edi\n" /* line 229 | z5, z11 */
        "subl %eax, %esi\n" /* line 230 | z5 */
        "movl %esi, -0x12c(%ebp)\n" /* z5 */
        "leal (%edx, %ecx), %esi\n" /* line 232 | z5 */
        "subl %ecx, %edx\n" /* line 233 */
        "leal (%edx, %edx, 2), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "addl %eax, %eax\n"
        "sarl $8, %eax\n"
        "subl %esi, %eax\n" /* z5 */
        "leal (%edi, %esi), %edx\n" /* line 235 | z11 */
        "movl %edx, -0x110(%ebp)\n"
        "subl %esi, %edi\n" /* line 236 | z5, z11 */
        "movl %edi, -0x114(%ebp)\n" /* z11 */
        "movl -0x12c(%ebp), %ecx\n" /* line 237 */
        "addl %eax, %ecx\n"
        "movl %ecx, -0x118(%ebp)\n"
        "movl -0x12c(%ebp), %esi\n" /* line 238 | z5 */
        "subl %eax, %esi\n" /* z5 */
        "movl %esi, -0x11c(%ebp)\n" /* z5 */
        "movswl -0x186(%ebp), %edi\n" /* line 242 | z11 */
        "movl -0x15c(%ebp), %eax\n" /* quantptr */
        "imull 0x20(%eax), %edi\n" /* z11 */
        "movl -0x140(%ebp), %edx\n" /* line 243 */
        "movswl (%edx), %ecx\n"
        "imull 0x60(%eax), %ecx\n"
        "movl -0x13c(%ebp), %esi\n" /* line 244 | z5 */
        "movswl (%esi), %edx\n" /* z5 */
        "imull 0xa0(%eax), %edx\n"
        "movl -0x138(%ebp), %esi\n" /* line 245 | z5 */
        "movswl (%esi), %eax\n" /* z5 */
        "movl -0x15c(%ebp), %esi\n" /* quantptr, z5 */
        "imull 0xe0(%esi), %eax\n" /* z5 */
        "leal (%ecx, %edx), %esi\n" /* line 247 | z5 */
        "movl %esi, -0x120(%ebp)\n" /* z5 */
        "subl %ecx, %edx\n" /* line 248 */
        "leal (%edi, %eax), %ecx\n" /* line 249 | z11 */
        "movl %ecx, -0x124(%ebp)\n"
        "subl %eax, %edi\n" /* line 250 | z11 */
        "addl %ecx, %esi\n" /* line 252 | z5 */
        "movl %esi, -0x128(%ebp)\n" /* z5 */
        "leal (%edx, %edi), %eax\n" /* line 255 */
        "leal (, %eax, 4), %esi\n" /* z5 */
        "movl %eax, %ecx\n"
        "shll $6, %ecx\n"
        "subl %esi, %ecx\n" /* z5 */
        "subl %eax, %ecx\n"
        "leal (%eax, %ecx, 8), %ecx\n"
        "sarl $8, %ecx\n"
        "leal (%edx, %edx, 4), %eax\n" /* line 259 */
        "leal (%edx, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "negl %eax\n"
        "sarl $8, %eax\n"
        "leal (%ecx, %eax), %eax\n"
        "subl -0x128(%ebp), %eax\n"
        "movl -0x124(%ebp), %esi\n" /* line 260 | z5 */
        "subl -0x120(%ebp), %esi\n" /* z5 */
        "movl %esi, -0x18c(%ebp)\n" /* z5 */
        "leal (%esi, %esi, 2), %edx\n" /* z5 */
        "movl %edx, %esi\n" /* z5 */
        "shll $4, %esi\n" /* z5 */
        "subl %edx, %esi\n" /* z5 */
        "movl -0x18c(%ebp), %edx\n"
        "leal (%edx, %esi, 4), %esi\n" /* z5 */
        "addl %esi, %esi\n" /* z5 */
        "sarl $8, %esi\n" /* z5 */
        "subl %eax, %esi\n" /* z5 */
        "movl %edi, %edx\n" /* line 261 | z11 */
        "shll $4, %edx\n"
        "addl %edi, %edx\n" /* z11 */
        "leal (%edi, %edx, 4), %edx\n" /* z11 */
        "leal (%edi, %edx, 4), %edx\n" /* z11 */
        "sarl $8, %edx\n"
        "subl %ecx, %edx\n"
        "addl %esi, %edx\n" /* z5 */
        "movl -0x110(%ebp), %ecx\n" /* line 263 */
        "addl -0x128(%ebp), %ecx\n"
        "movl -0x158(%ebp), %edi\n" /* wsptr, z11 */
        "movl %ecx, (%edi)\n" /* z11 */
        "movl -0x128(%ebp), %ecx\n" /* line 264 */
        "subl %ecx, -0x110(%ebp)\n"
        "movl -0x110(%ebp), %ecx\n"
        "movl %ecx, 0xe0(%edi)\n" /* z11 */
        "movl -0x118(%ebp), %ecx\n" /* line 265 */
        "addl %eax, %ecx\n"
        "movl %ecx, 0x20(%edi)\n" /* z11 */
        "subl %eax, -0x118(%ebp)\n" /* line 266 */
        "movl -0x118(%ebp), %eax\n"
        "movl %eax, 0xc0(%edi)\n" /* z11 */
        "movl -0x11c(%ebp), %eax\n" /* line 267 */
        "addl %esi, %eax\n" /* z5 */
        "movl %eax, 0x40(%edi)\n" /* z11 */
        "subl %esi, -0x11c(%ebp)\n" /* line 268 | z5 */
        "movl -0x11c(%ebp), %ecx\n"
        "movl %ecx, 0xa0(%edi)\n" /* z11 */
        "movl -0x114(%ebp), %eax\n" /* line 269 */
        "addl %edx, %eax\n"
        "movl %eax, 0x80(%edi)\n" /* z11 */
        "subl %edx, -0x114(%ebp)\n" /* line 270 */
        "movl -0x114(%ebp), %esi\n" /* z5 */
        "movl %esi, 0x60(%edi)\n" /* z5, z11 */
        "addl $2, -0x160(%ebp)\n" /* line 272 | inptr */
        "addl $4, -0x15c(%ebp)\n" /* line 273 | quantptr */
        "addl $4, %edi\n" /* line 274 | z11 */
        "movl %edi, -0x158(%ebp)\n" /* z11, wsptr */
        ".Lf213b18_00213da3:\n"
        "subl $1, -0x134(%ebp)\n" /* line 190 */
        "je .Lf213b18_00213e3e\n"
        "movl -0x160(%ebp), %ecx\n" /* inptr */
        ".Lf213b18_00213db6:\n"
        "movzwl 0x10(%ecx), %ecx\n" /* line 200 */
        "movw %cx, -0x186(%ebp)\n"
        "testw %cx, %cx\n"
        "je .Lf213b18_00213b6d\n"
        /* { scope 2 */
        "movl -0x160(%ebp), %edx\n" /* line 219 | inptr */
        "addl $0x20, %edx\n"
        "movl -0x160(%ebp), %eax\n" /* inptr */
        "addl $0x40, %eax\n"
        "movl -0x160(%ebp), %ecx\n" /* inptr */
        "addl $0x60, %ecx\n"
        "movl -0x160(%ebp), %esi\n" /* inptr, z5 */
        "addl $0x30, %esi\n" /* z5 */
        "movl %esi, -0x140(%ebp)\n" /* z5 */
        "movl -0x160(%ebp), %edi\n" /* inptr, z11 */
        "jmp .Lf213b18_00213b9c\n"
        ".Lf213b18_00213dff:\n"
        "movl %esi, %edi\n" /* z5, z11 */
        "movl %esi, %eax\n" /* z5 */
        /* } scope */
        "addl $0x30, %edi\n" /* line 200 | z11 */
        "movl %edi, -0x140(%ebp)\n" /* z11 */
        "cmpw $0, 0x30(%esi)\n" /* z5 */
        "je .Lf213b18_002141bc\n"
        "movl %esi, %ecx\n" /* z5 */
        "movl %eax, %edi\n" /* z11 */
        "addl $0x40, %eax\n"
        ".Lf213b18_00213e1e:\n"
        "addl $0x60, %ecx\n"
        "addl $0x50, %esi\n" /* z5 */
        "movl %esi, -0x13c(%ebp)\n" /* z5 */
        ".Lf213b18_00213e2a:\n"
        "addl $0x70, %edi\n" /* z11 */
        "movl %edi, -0x138(%ebp)\n" /* z11 */
        "movl -0x160(%ebp), %edi\n" /* inptr, z11 */
        "jmp .Lf213b18_00213bba\n"
        ".Lf213b18_00213e3e:\n"
        "movl -0x190(%ebp), %edi\n" /* line 190 | z11 */
        "movl %edi, -0x10c(%ebp)\n" /* z11 */
        "movl $1, -0x130(%ebp)\n"
        "movl %edi, %esi\n" /* z11, z5 */
        "jmp .Lf213b18_00214105\n"
        ".Lf213b18_00213e5b:\n"
        "movl -0x10c(%ebp), %edx\n" /* line 293 */
        "addl $8, %edx\n"
        "movl -0x10c(%ebp), %edi\n" /* z11 */
        "movl 8(%edi), %eax\n" /* z11 */
        "testl %eax, %eax\n"
        "je .Lf213b18_0021417f\n"
        "movl %edi, %ecx\n" /* z11 */
        "movl %edi, %eax\n" /* z11 */
        "addl $0x10, %eax\n"
        "movl %edi, %esi\n" /* z11, z5 */
        "addl $0x18, %esi\n" /* z5 */
        "addl $0x14, %edi\n" /* z11 */
        "movl %edi, -0x14c(%ebp)\n" /* z11 */
        "addl $0xc, %ecx\n"
        "movl %ecx, -0x148(%ebp)\n"
        "movl -0x10c(%ebp), %edi\n" /* z11 */
        "addl $0x1c, %edi\n" /* z11 */
        "movl %edi, -0x144(%ebp)\n" /* z11 */
        "movl -0x10c(%ebp), %edi\n" /* z11 */
        ".Lf213b18_00213ea8:\n"
        "movl (%edi), %ecx\n" /* line 315 | z11 */
        "movl (%eax), %eax\n"
        "leal (%ecx, %eax), %edi\n" /* z11 */
        "subl %eax, %ecx\n" /* line 316 */
        "movl %ecx, -0x16c(%ebp)\n" /* tmp11 */
        "movl (%edx), %edx\n" /* line 318 */
        "movl (%esi), %eax\n" /* z5 */
        "leal (%edx, %eax), %esi\n" /* z5 */
        "subl %eax, %edx\n" /* line 319 */
        "leal (%edx, %edx, 2), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "addl %eax, %eax\n"
        "sarl $8, %eax\n"
        "subl %esi, %eax\n" /* z5 */
        "leal (%edi, %esi), %edx\n" /* line 322 | z11 */
        "movl %edx, -0x180(%ebp)\n" /* tmp0 */
        "subl %esi, %edi\n" /* line 323 | z5, z11 */
        "movl %edi, -0x174(%ebp)\n" /* z11, tmp3 */
        "movl -0x16c(%ebp), %ecx\n" /* line 324 | tmp11 */
        "addl %eax, %ecx\n"
        "movl %ecx, -0x17c(%ebp)\n" /* tmp1 */
        "movl -0x16c(%ebp), %esi\n" /* line 325 | tmp11, z5 */
        "subl %eax, %esi\n" /* z5 */
        "movl %esi, -0x178(%ebp)\n" /* z5, tmp2 */
        "movl -0x14c(%ebp), %edi\n" /* line 329 | z11 */
        "movl (%edi), %ecx\n" /* z11 */
        "movl -0x148(%ebp), %edx\n"
        "movl (%edx), %eax\n"
        "leal (%ecx, %eax), %esi\n" /* z5 */
        "movl %esi, -0x164(%ebp)\n" /* z5, z13 */
        "subl %eax, %ecx\n" /* line 330 */
        "movl -0x144(%ebp), %edi\n" /* line 331 | z11 */
        "movl (%edi), %eax\n" /* z11 */
        "movl -0x184(%ebp), %edi\n" /* z11 */
        "addl %eax, %edi\n" /* z11 */
        "movl -0x184(%ebp), %edx\n" /* line 332 */
        "subl %eax, %edx\n"
        "movl %edx, -0x168(%ebp)\n" /* z12 */
        "addl %edi, %esi\n" /* line 334 | z11, z5 */
        "movl %esi, -0x170(%ebp)\n" /* z5, tmp7 */
        "leal (%ecx, %edx), %eax\n" /* line 337 */
        "leal (, %eax, 4), %edx\n"
        "movl %eax, %esi\n" /* z5 */
        "shll $6, %esi\n" /* z5 */
        "subl %edx, %esi\n" /* z5 */
        "subl %eax, %esi\n" /* z5 */
        "leal (%eax, %esi, 8), %esi\n" /* z5 */
        "sarl $8, %esi\n" /* z5 */
        "leal (%ecx, %ecx, 4), %edx\n" /* line 341 */
        "leal (%ecx, %edx, 4), %edx\n"
        "shll $3, %edx\n"
        "subl %ecx, %edx\n"
        "leal (%ecx, %edx, 4), %edx\n"
        "negl %edx\n"
        "sarl $8, %edx\n"
        "leal (%esi, %edx), %edx\n" /* z5 */
        "subl -0x170(%ebp), %edx\n" /* tmp7 */
        "subl -0x164(%ebp), %edi\n" /* line 342 | z13, z11 */
        "leal (%edi, %edi, 2), %eax\n" /* z11 */
        "movl %eax, %ecx\n"
        "shll $4, %ecx\n"
        "subl %eax, %ecx\n"
        "leal (%edi, %ecx, 4), %ecx\n" /* z11 */
        "addl %ecx, %ecx\n"
        "sarl $8, %ecx\n"
        "subl %edx, %ecx\n"
        "movl -0x168(%ebp), %edi\n" /* line 343 | z12, z11 */
        "shll $4, %edi\n" /* z11 */
        "addl -0x168(%ebp), %edi\n" /* z12, z11 */
        "movl -0x168(%ebp), %eax\n" /* z12 */
        "leal (%eax, %edi, 4), %edi\n" /* z11 */
        "leal (%eax, %edi, 4), %edi\n" /* z11 */
        "sarl $8, %edi\n" /* z11 */
        "subl %esi, %edi\n" /* z5, z11 */
        "addl %ecx, %edi\n" /* z11 */
        "movl -0x180(%ebp), %eax\n" /* line 347 | tmp0 */
        "addl -0x170(%ebp), %eax\n" /* tmp7 */
        "sarl $5, %eax\n"
        "andl $0x3ff, %eax\n"
        "movl -0x150(%ebp), %esi\n" /* range_limit, z5 */
        "movzbl (%esi, %eax), %eax\n" /* z5 */
        "movl -0x154(%ebp), %esi\n" /* outptr, z5 */
        "movb %al, (%esi)\n" /* z5 */
        "movl -0x170(%ebp), %eax\n" /* line 349 | tmp7 */
        "subl %eax, -0x180(%ebp)\n" /* tmp0 */
        "sarl $5, -0x180(%ebp)\n" /* tmp0 */
        "andl $0x3ff, -0x180(%ebp)\n" /* tmp0 */
        "movl -0x150(%ebp), %eax\n" /* range_limit */
        "movl -0x180(%ebp), %esi\n" /* tmp0, z5 */
        "movzbl (%eax, %esi), %eax\n"
        "movl -0x154(%ebp), %esi\n" /* outptr, z5 */
        "movb %al, 7(%esi)\n" /* z5 */
        "movl -0x17c(%ebp), %eax\n" /* line 351 | tmp1 */
        "addl %edx, %eax\n"
        "sarl $5, %eax\n"
        "andl $0x3ff, %eax\n"
        "movl -0x150(%ebp), %esi\n" /* range_limit, z5 */
        "movzbl (%esi, %eax), %eax\n" /* z5 */
        "movl -0x154(%ebp), %esi\n" /* outptr, z5 */
        "movb %al, 1(%esi)\n" /* z5 */
        "subl %edx, -0x17c(%ebp)\n" /* line 353 | tmp1 */
        "sarl $5, -0x17c(%ebp)\n" /* tmp1 */
        "andl $0x3ff, -0x17c(%ebp)\n" /* tmp1 */
        "movl -0x150(%ebp), %edx\n" /* range_limit */
        "movl -0x17c(%ebp), %esi\n" /* tmp1, z5 */
        "movzbl (%edx, %esi), %eax\n"
        "movl -0x154(%ebp), %edx\n" /* outptr */
        "movb %al, 6(%edx)\n"
        "movl -0x178(%ebp), %eax\n" /* line 355 | tmp2 */
        "addl %ecx, %eax\n"
        "sarl $5, %eax\n"
        "andl $0x3ff, %eax\n"
        "movl -0x150(%ebp), %esi\n" /* range_limit, z5 */
        "movzbl (%esi, %eax), %eax\n" /* z5 */
        "movb %al, 2(%edx)\n"
        "subl %ecx, -0x178(%ebp)\n" /* line 357 | tmp2 */
        "sarl $5, -0x178(%ebp)\n" /* tmp2 */
        "andl $0x3ff, -0x178(%ebp)\n" /* tmp2 */
        "movl -0x178(%ebp), %edx\n" /* tmp2 */
        "movzbl (%esi, %edx), %eax\n" /* z5 */
        "movl -0x154(%ebp), %ecx\n" /* outptr */
        "movb %al, 5(%ecx)\n"
        "movl -0x174(%ebp), %eax\n" /* line 359 | tmp3 */
        "addl %edi, %eax\n" /* z11 */
        "sarl $5, %eax\n"
        "andl $0x3ff, %eax\n"
        "movzbl (%esi, %eax), %eax\n" /* z5 */
        "movb %al, 4(%ecx)\n"
        "subl %edi, -0x174(%ebp)\n" /* line 361 | z11, tmp3 */
        "sarl $5, -0x174(%ebp)\n" /* tmp3 */
        "andl $0x3ff, -0x174(%ebp)\n" /* tmp3 */
        "movl -0x174(%ebp), %edi\n" /* tmp3, z11 */
        "movzbl (%esi, %edi), %eax\n" /* z5 */
        "movb %al, 3(%ecx)\n"
        "addl $0x20, -0x10c(%ebp)\n" /* line 364 */
        ".Lf213b18_002140eb:\n"
        "addl $1, -0x130(%ebp)\n"
        "cmpl $9, -0x130(%ebp)\n" /* line 282 */
        "je .Lf213b18_002141d5\n"
        "movl -0x10c(%ebp), %esi\n" /* z5 */
        ".Lf213b18_00214105:\n"
        "movl 0x18(%ebp), %ecx\n" /* line 283 | output_col */
        "movl -0x130(%ebp), %eax\n"
        "movl 0x14(%ebp), %edx\n" /* output_buf */
        "addl -4(%edx, %eax, 4), %ecx\n"
        "movl %ecx, -0x154(%ebp)\n" /* outptr */
        "movl 4(%esi), %esi\n" /* line 293 | z5 */
        "movl %esi, -0x184(%ebp)\n" /* z5 */
        "testl %esi, %esi\n" /* z5 */
        "je .Lf213b18_00213e5b\n"
        /* { scope 2 */
        "movl -0x10c(%ebp), %eax\n" /* line 309 */
        "addl $0x10, %eax\n"
        "movl -0x10c(%ebp), %edx\n"
        "addl $8, %edx\n"
        "movl -0x10c(%ebp), %esi\n" /* z5 */
        "addl $0x18, %esi\n" /* z5 */
        "movl -0x10c(%ebp), %ecx\n"
        "addl $0x14, %ecx\n"
        "movl %ecx, -0x14c(%ebp)\n"
        "movl -0x10c(%ebp), %edi\n" /* z11 */
        "addl $0xc, %edi\n" /* z11 */
        "movl %edi, -0x148(%ebp)\n" /* z11 */
        "movl -0x10c(%ebp), %ecx\n"
        ".Lf213b18_0021416b:\n"
        "addl $0x1c, %ecx\n"
        "movl %ecx, -0x144(%ebp)\n"
        "movl -0x10c(%ebp), %edi\n" /* z11 */
        "jmp .Lf213b18_00213ea8\n"
        ".Lf213b18_0021417f:\n"
        "movl %edi, %eax\n" /* z11 */
        "movl %edi, %ecx\n" /* z11 */
        /* } scope */
        "addl $0xc, %eax\n" /* line 293 */
        "movl %eax, -0x148(%ebp)\n"
        "movl 0xc(%edi), %edi\n" /* z11 */
        "testl %edi, %edi\n" /* z11 */
        "je .Lf213b18_002141df\n"
        "movl %ecx, %edi\n" /* z11 */
        "movl %ecx, %eax\n"
        "addl $0x10, %eax\n"
        ".Lf213b18_0021419a:\n"
        "movl %ecx, %esi\n" /* z5 */
        "addl $0x18, %esi\n" /* z5 */
        "addl $0x14, %ecx\n"
        "movl %ecx, -0x14c(%ebp)\n"
        "addl $0x1c, %edi\n" /* z11 */
        "movl %edi, -0x144(%ebp)\n" /* z11 */
        "movl -0x10c(%ebp), %edi\n" /* z11 */
        "jmp .Lf213b18_00213ea8\n"
        ".Lf213b18_002141bc:\n"
        "addl $0x40, %eax\n" /* line 200 */
        "movl -0x160(%ebp), %ecx\n" /* inptr */
        "cmpw $0, 0x40(%ecx)\n"
        "je .Lf213b18_002141f9\n"
        "movl %ecx, %esi\n" /* z5 */
        "movl %ecx, %edi\n" /* z11 */
        "jmp .Lf213b18_00213e1e\n"
        ".Lf213b18_002141d5:\n"
        "addl $0x1a0, %esp\n" /* line 366 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf213b18_002141df:\n"
        "movl %ecx, %eax\n"
        "addl $0x10, %eax\n" /* line 293 */
        "movl -0x10c(%ebp), %ecx\n"
        "movl 0x10(%ecx), %esi\n" /* z5 */
        "testl %esi, %esi\n" /* z5 */
        "je .Lf213b18_00214294\n"
        "movl %ecx, %edi\n" /* z11 */
        "jmp .Lf213b18_0021419a\n"
        ".Lf213b18_002141f9:\n"
        "addl $0x50, %ecx\n" /* line 200 */
        "movl %ecx, -0x13c(%ebp)\n"
        "movl -0x160(%ebp), %esi\n" /* inptr, z5 */
        "cmpw $0, 0x50(%esi)\n" /* z5 */
        "jne .Lf213b18_00214319\n"
        "movl %esi, %ecx\n" /* z5 */
        "movl %esi, %edi\n" /* z5, z11 */
        "addl $0x60, %ecx\n"
        "cmpw $0, 0x60(%esi)\n" /* z5 */
        "jne .Lf213b18_00213e2a\n"
        "addl $0x70, %esi\n" /* z5 */
        "movl %esi, -0x138(%ebp)\n" /* z5 */
        "movl -0x160(%ebp), %edi\n" /* inptr, z11 */
        "cmpw $0, 0x70(%edi)\n" /* z11 */
        "jne .Lf213b18_00213bba\n"
        /* { scope 2 */
        "movswl (%edi), %eax\n" /* line 205 | z11, dcval */
        "movl -0x15c(%ebp), %edx\n" /* quantptr */
        "imull (%edx), %eax\n" /* dcval */
        "movl -0x158(%ebp), %ecx\n" /* line 207 | wsptr */
        "movl %eax, (%ecx)\n"
        "movl %eax, 0x20(%ecx)\n" /* line 208 */
        "movl %eax, 0x40(%ecx)\n" /* line 209 */
        "movl %eax, 0x60(%ecx)\n" /* line 210 */
        "movl %eax, 0x80(%ecx)\n" /* line 211 */
        "movl %eax, 0xa0(%ecx)\n" /* line 212 */
        "movl %eax, 0xc0(%ecx)\n" /* line 213 */
        "movl %eax, 0xe0(%ecx)\n" /* line 214 */
        "addl $2, %edi\n" /* line 216 | z11 */
        "movl %edi, -0x160(%ebp)\n" /* z11, inptr */
        "addl $4, %edx\n" /* line 217 */
        "movl %edx, -0x15c(%ebp)\n" /* quantptr */
        "addl $4, %ecx\n" /* line 218 */
        "movl %ecx, -0x158(%ebp)\n" /* wsptr */
        "jmp .Lf213b18_00213da3\n"
        /* } scope */
        ".Lf213b18_00214294:\n"
        "addl $0x14, %ecx\n" /* line 293 */
        "movl %ecx, -0x14c(%ebp)\n"
        "movl -0x10c(%ebp), %esi\n" /* z5 */
        "movl 0x14(%esi), %ecx\n" /* z5 */
        "testl %ecx, %ecx\n"
        "jne .Lf213b18_00214332\n"
        "addl $0x18, %esi\n" /* z5 */
        "movl -0x10c(%ebp), %ecx\n"
        "movl 0x18(%ecx), %edi\n" /* z11 */
        "testl %edi, %edi\n" /* z11 */
        "jne .Lf213b18_0021416b\n"
        "movl %ecx, %edi\n" /* z11 */
        "addl $0x1c, %edi\n" /* z11 */
        "movl %edi, -0x144(%ebp)\n" /* z11 */
        "movl -0x10c(%ebp), %ecx\n"
        "movl 0x1c(%ecx), %edi\n" /* z11 */
        "testl %edi, %edi\n" /* z11 */
        "jne .Lf213b18_0021434b\n"
        /* { scope 2 */
        "movl (%ecx), %eax\n" /* line 297 */
        "sarl $5, %eax\n"
        "andl $0x3ff, %eax\n"
        "movl -0x150(%ebp), %esi\n" /* range_limit, z5 */
        "movzbl (%esi, %eax), %eax\n" /* z5 */
        "movl -0x154(%ebp), %edi\n" /* line 299 | outptr, z11 */
        "movb %al, (%edi)\n" /* z11 */
        "movb %al, 1(%edi)\n" /* line 300 | z11 */
        "movb %al, 2(%edi)\n" /* line 301 | z11 */
        "movb %al, 3(%edi)\n" /* line 302 | z11 */
        "movb %al, 4(%edi)\n" /* line 303 | z11 */
        "movb %al, 5(%edi)\n" /* line 304 | z11 */
        "movb %al, 6(%edi)\n" /* line 305 | z11 */
        "movb %al, 7(%edi)\n" /* line 306 | z11 */
        "addl $0x20, %ecx\n" /* line 308 */
        "movl %ecx, -0x10c(%ebp)\n"
        "jmp .Lf213b18_002140eb\n"
        /* } scope */
        ".Lf213b18_00214319:\n"
        "movl %esi, %ecx\n" /* line 200 | z5 */
        "addl $0x60, %ecx\n"
        "addl $0x70, %esi\n" /* z5 */
        "movl %esi, -0x138(%ebp)\n" /* z5 */
        "movl -0x160(%ebp), %edi\n" /* inptr, z11 */
        "jmp .Lf213b18_00213bba\n"
        ".Lf213b18_00214332:\n"
        "movl %esi, %edi\n" /* z5, z11 */
        "addl $0x18, %esi\n" /* line 293 | z5 */
        "addl $0x1c, %edi\n" /* z11 */
        "movl %edi, -0x144(%ebp)\n" /* z11 */
        "movl -0x10c(%ebp), %edi\n" /* z11 */
        "jmp .Lf213b18_00213ea8\n"
        ".Lf213b18_0021434b:\n"
        "movl %ecx, %edi\n" /* z11 */
        "jmp .Lf213b18_00213ea8\n"
    );
}

