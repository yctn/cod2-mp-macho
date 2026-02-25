/* ASM dump from: jidctred.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jidctred.c */

#include "common_types.h"
#include "imports.h"

void jpeg_idct_4x4(j_decompress_ptr cinfo, jpeg_component_info *compptr, JCOEFPTR coef_block, JSAMPARRAY output_buf, JDIMENSION output_col);
void jpeg_idct_2x2(j_decompress_ptr cinfo, jpeg_component_info *compptr, JCOEFPTR coef_block, JSAMPARRAY output_buf, JDIMENSION output_col);
void jpeg_idct_1x1(j_decompress_ptr cinfo, jpeg_component_info *compptr, JCOEFPTR coef_block, JSAMPARRAY output_buf, JDIMENSION output_col);

/* line 121 */
__attribute__((naked))
void jpeg_idct_4x4(j_decompress_ptr cinfo, jpeg_component_info *compptr, JCOEFPTR coef_block, JSAMPARRAY output_buf, JDIMENSION output_col)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 121 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x100, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 128 | cinfo */
        "movl 0x128(%eax), %eax\n"
        "subl $-0x80, %eax\n"
        "movl %eax, -0xc0(%ebp)\n" /* range_limit */
        "movl 0xc(%ebp), %eax\n" /* line 136 | compptr */
        "movl 0x50(%eax), %eax\n"
        "movl %eax, -0xcc(%ebp)\n" /* quantptr */
        "movl 0x10(%ebp), %eax\n" /* coef_block */
        "movl %eax, -0xd0(%ebp)\n" /* inptr */
        "movl $8, -0xbc(%ebp)\n" /* ctr */
        "leal -0x88(%ebp), %edx\n" /* workspace */
        "movl %edx, -0xf0(%ebp)\n"
        "movl %edx, -0x9c(%ebp)\n"
        "movl %eax, %ecx\n"
        "jmp .Lf212a88_00212d2f\n"
        ".Lf212a88_00212add:\n"
        "movl -0xd0(%ebp), %eax\n" /* line 142 | inptr */
        "addl $0x20, %eax\n"
        "movl -0xd0(%ebp), %edi\n" /* inptr, z4 */
        "cmpw $0, 0x20(%edi)\n" /* z4 */
        "je .Lf212a88_00212d8d\n"
        "movl %edi, %edx\n" /* z4 */
        "movl %edi, %ecx\n" /* z4 */
        "addl $0x60, %edi\n" /* z4 */
        "addl $0x70, %edx\n"
        "movl %edx, -0xac(%ebp)\n"
        "addl $0x50, %ecx\n"
        "movl %ecx, -0xa8(%ebp)\n"
        "movl -0xd0(%ebp), %edx\n" /* inptr */
        "addl $0x30, %edx\n"
        "movl %edx, -0xa4(%ebp)\n"
        "movl -0xd0(%ebp), %edx\n" /* inptr */
        ".Lf212a88_00212b25:\n"
        "movswl (%edx), %esi\n" /* line 158 | z2 */
        "movl -0xcc(%ebp), %ecx\n" /* quantptr */
        "imull (%ecx), %esi\n" /* z2 */
        "shll $0xe, %esi\n" /* line 159 | z2 */
        "movswl (%eax), %eax\n" /* line 164 */
        "imull 0x40(%ecx), %eax\n"
        "leal (, %eax, 4), %edx\n"
        "movl %eax, %ecx\n"
        "shll $6, %ecx\n"
        "subl %edx, %ecx\n"
        "subl %eax, %ecx\n"
        "leal (%eax, %ecx, 8), %ecx\n"
        "shll $5, %ecx\n"
        "addl %eax, %ecx\n"
        "movswl (%edi), %edx\n" /* z4 */
        "movl -0xcc(%ebp), %edi\n" /* quantptr, z4 */
        "imull 0xc0(%edi), %edx\n" /* z4 */
        "leal (%edx, %edx, 2), %eax\n"
        "shll $5, %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "addl %edx, %eax\n"
        "addl %eax, %eax\n"
        "subl %eax, %ecx\n"
        "leal (%esi, %ecx), %eax\n" /* line 166 | z2 */
        "movl %eax, -0x8c(%ebp)\n"
        "subl %ecx, %esi\n" /* line 167 | z2 */
        "movl %esi, -0x90(%ebp)\n" /* z2 */
        "movl -0xac(%ebp), %edx\n" /* line 171 */
        "movswl (%edx), %edx\n"
        "movl %edx, -0x94(%ebp)\n"
        "imull 0xe0(%edi), %edx\n" /* z4 */
        "movl %edx, -0x94(%ebp)\n"
        "movl -0xa8(%ebp), %ecx\n" /* line 172 */
        "movswl (%ecx), %esi\n" /* z2 */
        "imull 0xa0(%edi), %esi\n" /* z4, z2 */
        "movl -0xa4(%ebp), %edi\n" /* line 173 | z4 */
        "movswl (%edi), %edi\n" /* z4 */
        "movl %edi, -0x98(%ebp)\n" /* z4 */
        "movl -0xcc(%ebp), %eax\n" /* quantptr */
        "imull 0x60(%eax), %edi\n" /* z4 */
        "movl %edi, -0x98(%ebp)\n" /* z4 */
        "movswl -0xe2(%ebp), %edi\n" /* line 174 | z4 */
        "imull 0x20(%eax), %edi\n" /* z4 */
        "movl %edx, %ecx\n" /* line 176 */
        "leal (%edx, %edx, 2), %edx\n"
        "leal (%edx, %edx, 8), %edx\n"
        "shll $5, %edx\n"
        "addl %ecx, %edx\n"
        "addl %edx, %edx\n"
        "movl %esi, %ecx\n" /* z2 */
        "shll $5, %ecx\n"
        "movl %esi, %eax\n" /* z2 */
        "shll $0xa, %eax\n"
        "subl %ecx, %eax\n"
        "subl %esi, %eax\n" /* z2 */
        "leal (, %eax, 4), %ecx\n"
        "subl %eax, %ecx\n"
        "leal (%esi, %ecx, 4), %ecx\n" /* z2 */
        "subl %edx, %ecx\n"
        "movl %ecx, -0xe8(%ebp)\n"
        "movl %edi, %edx\n" /* z4 */
        "shll $6, %edx\n"
        "movl %edi, %eax\n" /* z4 */
        "shll $0xa, %eax\n"
        "addl %eax, %edx\n"
        "subl %edi, %edx\n" /* z4 */
        "leal (%edi, %edx, 8), %edx\n" /* z4 */
        "movl -0x98(%ebp), %eax\n"
        "shll $6, %eax\n"
        "addl -0x98(%ebp), %eax\n"
        "movl -0x98(%ebp), %ecx\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "subl %ecx, %eax\n"
        "movl %eax, %ecx\n"
        "shll $4, %ecx\n"
        "addl %ecx, %eax\n"
        "subl %eax, %edx\n"
        "movl -0xe8(%ebp), %ecx\n"
        "addl %edx, %ecx\n"
        "movl -0x94(%ebp), %edx\n" /* line 181 */
        "shll $6, %edx\n"
        "addl -0x94(%ebp), %edx\n"
        "movl -0x94(%ebp), %eax\n"
        "leal (%eax, %edx, 4), %edx\n"
        "shll $4, %edx\n"
        "leal (%esi, %esi, 8), %eax\n" /* z2 */
        "leal (%esi, %eax, 2), %eax\n" /* z2 */
        "leal (%esi, %eax, 4), %eax\n" /* z2 */
        "shll $5, %eax\n"
        "subl %eax, %esi\n" /* z2 */
        "addl %esi, %esi\n" /* z2 */
        "subl %edx, %esi\n" /* z2 */
        "leal (%edi, %edi, 4), %edx\n" /* z4 */
        "leal (%edi, %edx, 8), %edx\n" /* z4 */
        "shll $8, %edx\n"
        "addl %edi, %edx\n" /* z4 */
        "leal (%edi, %edx, 2), %edx\n" /* z4 */
        "movl -0x98(%ebp), %edi\n" /* z4 */
        "leal (%edi, %edi, 2), %eax\n" /* z4 */
        "shll $3, %eax\n"
        "subl %edi, %eax\n" /* z4 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%edi, %eax, 8), %eax\n" /* z4 */
        "leal (%edi, %eax, 2), %eax\n" /* z4 */
        "leal (%edi, %eax, 4), %eax\n" /* z4 */
        "addl %eax, %edx\n"
        "addl %edx, %esi\n" /* z2 */
        "movl -0x8c(%ebp), %edx\n" /* line 188 */
        "leal 0x800(%edx, %esi), %eax\n"
        "sarl $0xc, %eax\n"
        "movl -0x9c(%ebp), %edi\n" /* z4 */
        "movl %eax, (%edi)\n" /* z4 */
        "subl %esi, %edx\n" /* line 189 | z2 */
        "movl %edx, %eax\n"
        "addl $0x800, %eax\n"
        "sarl $0xc, %eax\n"
        "movl %eax, 0x60(%edi)\n" /* z4 */
        "movl -0x90(%ebp), %edx\n" /* line 190 */
        "leal 0x800(%edx, %ecx), %eax\n"
        "sarl $0xc, %eax\n"
        "movl %eax, 0x20(%edi)\n" /* z4 */
        "subl %ecx, %edx\n" /* line 191 */
        "movl %edx, %eax\n"
        "addl $0x800, %eax\n"
        "sarl $0xc, %eax\n"
        "movl %eax, 0x40(%edi)\n" /* z4 */
        ".Lf212a88_00212cef:\n"
        "movl -0xbc(%ebp), %eax\n" /* ctr */
        ".Lf212a88_00212cf5:\n"
        "addl $2, -0xd0(%ebp)\n" /* line 138 | inptr */
        "addl $4, -0xcc(%ebp)\n" /* quantptr */
        "addl $4, -0x9c(%ebp)\n"
        "subl $1, %eax\n"
        "movl %eax, -0xbc(%ebp)\n" /* ctr */
        "testl %eax, %eax\n"
        "jle .Lf212a88_00212dcd\n"
        "movl $4, %eax\n"
        "cmpl $4, -0xbc(%ebp)\n" /* line 140 | ctr */
        "je .Lf212a88_00212cf5\n"
        "movl -0xd0(%ebp), %ecx\n" /* inptr */
        ".Lf212a88_00212d2f:\n"
        "movzwl 0x10(%ecx), %ecx\n" /* line 142 */
        "movw %cx, -0xe2(%ebp)\n"
        "testw %cx, %cx\n"
        "je .Lf212a88_00212add\n"
        /* { scope 2 */
        "movl -0xd0(%ebp), %eax\n" /* line 153 | inptr */
        "addl $0x20, %eax\n"
        "movl -0xd0(%ebp), %edi\n" /* inptr, z4 */
        "addl $0x60, %edi\n" /* z4 */
        "movl -0xd0(%ebp), %ecx\n" /* inptr */
        "addl $0x70, %ecx\n"
        "movl %ecx, -0xac(%ebp)\n"
        "movl -0xd0(%ebp), %edx\n" /* inptr */
        "addl $0x50, %edx\n"
        "movl %edx, -0xa8(%ebp)\n"
        "movl -0xd0(%ebp), %ecx\n" /* inptr */
        "addl $0x30, %ecx\n"
        "movl %ecx, -0xa4(%ebp)\n"
        "movl -0xd0(%ebp), %edx\n" /* inptr */
        "jmp .Lf212a88_00212b25\n"
        ".Lf212a88_00212d8d:\n"
        "movl %edi, %ecx\n" /* z4 */
        /* } scope */
        "addl $0x30, %ecx\n" /* line 142 */
        "movl %ecx, -0xa4(%ebp)\n"
        "movl -0xd0(%ebp), %edi\n" /* inptr, z4 */
        "cmpw $0, 0x30(%edi)\n" /* z4 */
        "je .Lf212a88_00213111\n"
        "movl %edi, %edx\n" /* z4 */
        "movl %edi, %ecx\n" /* z4 */
        "addl $0x60, %edi\n" /* z4 */
        "addl $0x70, %edx\n"
        "movl %edx, -0xac(%ebp)\n"
        "addl $0x50, %ecx\n"
        "movl %ecx, -0xa8(%ebp)\n"
        "movl -0xd0(%ebp), %edx\n" /* inptr */
        "jmp .Lf212a88_00212b25\n"
        ".Lf212a88_00212dcd:\n"
        "movl -0xf0(%ebp), %ecx\n" /* line 138 */
        "movl %ecx, -0xc8(%ebp)\n" /* wsptr */
        "movl $1, -0xa0(%ebp)\n"
        "movl 0x18(%ebp), %edx\n" /* line 198 | output_col */
        "movl -0xa0(%ebp), %edi\n" /* z4 */
        "movl 0x14(%ebp), %eax\n" /* output_buf */
        "addl -4(%eax, %edi, 4), %edx\n"
        "movl %edx, -0xc4(%ebp)\n" /* outptr */
        "movl 4(%ecx), %ecx\n" /* line 202 */
        "movl %ecx, -0xe0(%ebp)\n"
        "testl %ecx, %ecx\n"
        "jne .Lf212a88_0021307f\n"
        ".Lf212a88_00212e0a:\n"
        "movl -0xc8(%ebp), %eax\n" /* wsptr */
        "addl $8, %eax\n"
        "movl -0xc8(%ebp), %edi\n" /* wsptr, z4 */
        "movl 8(%edi), %edx\n" /* z4 */
        "testl %edx, %edx\n"
        "je .Lf212a88_002130d3\n"
        "movl %edi, %edx\n" /* z4 */
        "movl %edi, %ecx\n" /* z4 */
        "movl %edi, %esi\n" /* z4, z2 */
        "addl $0x18, %esi\n" /* z2 */
        "addl $0x1c, %edi\n" /* z4 */
        "movl %edi, -0xb8(%ebp)\n" /* z4 */
        "addl $0x14, %edx\n"
        "movl %edx, -0xb4(%ebp)\n"
        "addl $0xc, %ecx\n"
        "movl %ecx, -0xb0(%ebp)\n"
        "movl -0xc8(%ebp), %edx\n" /* wsptr */
        ".Lf212a88_00212e4e:\n"
        "movl (%edx), %edi\n" /* line 220 | z4 */
        "shll $0xe, %edi\n" /* z4 */
        "movl (%eax), %eax\n" /* line 222 */
        "leal (, %eax, 4), %ecx\n"
        "movl %eax, %edx\n"
        "shll $6, %edx\n"
        "subl %ecx, %edx\n"
        "subl %eax, %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "shll $5, %edx\n"
        "addl %eax, %edx\n"
        "movl (%esi), %ecx\n" /* z2 */
        "leal (%ecx, %ecx, 2), %eax\n"
        "shll $5, %eax\n"
        "subl %ecx, %eax\n"
        "movl %eax, %ecx\n"
        "shll $5, %ecx\n"
        "addl %ecx, %eax\n"
        "addl %eax, %eax\n"
        "subl %eax, %edx\n"
        "leal (%edi, %edx), %ecx\n" /* line 225 | z4 */
        "movl %ecx, -0xdc(%ebp)\n" /* tmp10 */
        "subl %edx, %edi\n" /* line 226 | z4 */
        "movl -0xb8(%ebp), %eax\n" /* line 230 */
        "movl (%eax), %eax\n"
        "movl %eax, -0xd8(%ebp)\n" /* z1 */
        "movl -0xb4(%ebp), %edx\n" /* line 231 */
        "movl (%edx), %esi\n" /* z2 */
        "movl -0xb0(%ebp), %ecx\n" /* line 232 */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0xd4(%ebp)\n" /* z3 */
        "leal (%eax, %eax, 2), %edx\n" /* line 235 */
        "leal (%edx, %edx, 8), %edx\n"
        "shll $5, %edx\n"
        "addl %eax, %edx\n"
        "addl %edx, %edx\n"
        "movl %esi, %ecx\n" /* z2 */
        "shll $5, %ecx\n"
        "movl %esi, %eax\n" /* z2 */
        "shll $0xa, %eax\n"
        "subl %ecx, %eax\n"
        "subl %esi, %eax\n" /* z2 */
        "leal (, %eax, 4), %ecx\n"
        "subl %eax, %ecx\n"
        "leal (%esi, %ecx, 4), %ecx\n" /* z2 */
        "subl %edx, %ecx\n"
        "movl %ecx, -0xec(%ebp)\n"
        "movl -0xe0(%ebp), %edx\n"
        "shll $6, %edx\n"
        "movl -0xe0(%ebp), %eax\n"
        "shll $0xa, %eax\n"
        "addl %eax, %edx\n"
        "subl -0xe0(%ebp), %edx\n"
        "movl -0xe0(%ebp), %eax\n"
        "leal (%eax, %edx, 8), %edx\n"
        "movl -0xd4(%ebp), %eax\n" /* z3 */
        "shll $6, %eax\n"
        "addl -0xd4(%ebp), %eax\n" /* z3 */
        "movl -0xd4(%ebp), %ecx\n" /* z3 */
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "subl %ecx, %eax\n"
        "movl %eax, %ecx\n"
        "shll $4, %ecx\n"
        "addl %ecx, %eax\n"
        "subl %eax, %edx\n"
        "movl -0xec(%ebp), %ecx\n"
        "addl %edx, %ecx\n"
        "movl -0xd8(%ebp), %edx\n" /* line 240 | z1 */
        "shll $6, %edx\n"
        "addl -0xd8(%ebp), %edx\n" /* z1 */
        "movl -0xd8(%ebp), %eax\n" /* z1 */
        "leal (%eax, %edx, 4), %edx\n"
        "shll $4, %edx\n"
        "leal (%esi, %esi, 8), %eax\n" /* z2 */
        "leal (%esi, %eax, 2), %eax\n" /* z2 */
        "leal (%esi, %eax, 4), %eax\n" /* z2 */
        "shll $5, %eax\n"
        "subl %eax, %esi\n" /* z2 */
        "addl %esi, %esi\n" /* z2 */
        "subl %edx, %esi\n" /* z2 */
        "movl -0xe0(%ebp), %eax\n"
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "shll $8, %edx\n"
        "addl %eax, %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "movl %edx, -0xfc(%ebp)\n"
        "movl -0xd4(%ebp), %edx\n" /* z3 */
        "leal (%edx, %edx, 2), %edx\n"
        "movl %edx, %eax\n"
        "shll $3, %eax\n"
        "subl -0xd4(%ebp), %eax\n" /* z3 */
        "leal (%eax, %eax, 4), %eax\n"
        "movl -0xd4(%ebp), %edx\n" /* z3 */
        "leal (%edx, %eax, 8), %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl -0xfc(%ebp), %edx\n"
        "addl %eax, %edx\n"
        "addl %edx, %esi\n" /* z2 */
        "movl -0xdc(%ebp), %edx\n" /* line 247 | tmp10 */
        "leal 0x40000(%edx, %esi), %eax\n"
        "sarl $0x13, %eax\n"
        "andl $0x3ff, %eax\n"
        "movl -0xc0(%ebp), %edx\n" /* range_limit */
        "movzbl (%edx, %eax), %eax\n"
        "movl -0xc4(%ebp), %edx\n" /* outptr */
        "movb %al, (%edx)\n"
        "subl %esi, -0xdc(%ebp)\n" /* line 250 | z2, tmp10 */
        "movl -0xdc(%ebp), %eax\n" /* tmp10 */
        "addl $0x40000, %eax\n"
        "sarl $0x13, %eax\n"
        "andl $0x3ff, %eax\n"
        "movl -0xc0(%ebp), %edx\n" /* range_limit */
        "movzbl (%edx, %eax), %eax\n"
        "movl -0xc4(%ebp), %edx\n" /* outptr */
        "movb %al, 3(%edx)\n"
        "leal 0x40000(%edi, %ecx), %eax\n" /* line 253 | z4 */
        "sarl $0x13, %eax\n"
        "andl $0x3ff, %eax\n"
        "movl -0xc0(%ebp), %edx\n" /* range_limit */
        "movzbl (%edx, %eax), %eax\n"
        "movl -0xc4(%ebp), %edx\n" /* outptr */
        "movb %al, 1(%edx)\n"
        "subl %ecx, %edi\n" /* line 256 | z4 */
        "addl $0x40000, %edi\n" /* z4 */
        "sarl $0x13, %edi\n" /* z4 */
        "andl $0x3ff, %edi\n" /* z4 */
        "movl -0xc0(%ebp), %ecx\n" /* range_limit */
        "movzbl (%ecx, %edi), %eax\n"
        "movb %al, 2(%edx)\n"
        "addl $0x20, -0xc8(%ebp)\n" /* line 260 | wsptr */
        ".Lf212a88_00213042:\n"
        "addl $1, -0xa0(%ebp)\n"
        "cmpl $5, -0xa0(%ebp)\n" /* line 197 */
        "je .Lf212a88_002130c9\n"
        "movl -0xc8(%ebp), %ecx\n" /* wsptr */
        "movl 0x18(%ebp), %edx\n" /* line 198 | output_col */
        "movl -0xa0(%ebp), %edi\n" /* z4 */
        "movl 0x14(%ebp), %eax\n" /* output_buf */
        "addl -4(%eax, %edi, 4), %edx\n"
        "movl %edx, -0xc4(%ebp)\n" /* outptr */
        "movl 4(%ecx), %ecx\n" /* line 202 */
        "movl %ecx, -0xe0(%ebp)\n"
        "testl %ecx, %ecx\n"
        "je .Lf212a88_00212e0a\n"
        /* { scope 2 */
        ".Lf212a88_0021307f:\n"
        "movl -0xc8(%ebp), %eax\n" /* line 214 | wsptr */
        "addl $8, %eax\n"
        "movl -0xc8(%ebp), %esi\n" /* wsptr, z2 */
        "addl $0x18, %esi\n" /* z2 */
        "movl -0xc8(%ebp), %edx\n" /* wsptr */
        "addl $0x1c, %edx\n"
        "movl %edx, -0xb8(%ebp)\n"
        "movl -0xc8(%ebp), %ecx\n" /* wsptr */
        "addl $0x14, %ecx\n"
        "movl %ecx, -0xb4(%ebp)\n"
        "movl -0xc8(%ebp), %edi\n" /* wsptr, z4 */
        "addl $0xc, %edi\n" /* z4 */
        "movl %edi, -0xb0(%ebp)\n" /* z4 */
        "movl -0xc8(%ebp), %edx\n" /* wsptr */
        "jmp .Lf212a88_00212e4e\n"
        /* } scope */
        ".Lf212a88_002130c9:\n"
        "addl $0x100, %esp\n" /* line 262 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf212a88_002130d3:\n"
        "addl $0xc, %edi\n" /* line 202 | z4 */
        "movl %edi, -0xb0(%ebp)\n" /* z4 */
        "movl -0xc8(%ebp), %edx\n" /* wsptr */
        "movl 0xc(%edx), %esi\n" /* z2 */
        "testl %esi, %esi\n" /* z2 */
        "je .Lf212a88_0021317c\n"
        "movl %edx, %ecx\n"
        "movl %edx, %esi\n" /* z2 */
        "addl $0x18, %esi\n" /* z2 */
        "addl $0x1c, %edx\n"
        "movl %edx, -0xb8(%ebp)\n"
        "addl $0x14, %ecx\n"
        "movl %ecx, -0xb4(%ebp)\n"
        "movl -0xc8(%ebp), %edx\n" /* wsptr */
        "jmp .Lf212a88_00212e4e\n"
        ".Lf212a88_00213111:\n"
        "addl $0x50, %edi\n" /* line 142 | z4 */
        "movl %edi, -0xa8(%ebp)\n" /* z4 */
        "movl -0xd0(%ebp), %edx\n" /* inptr */
        "cmpw $0, 0x50(%edx)\n"
        "jne .Lf212a88_002131f2\n"
        "movl %edx, %edi\n" /* z4 */
        "movl %edx, %ecx\n"
        "addl $0x60, %edi\n" /* z4 */
        "cmpw $0, 0x60(%edx)\n"
        "jne .Lf212a88_00213224\n"
        "addl $0x70, %edx\n"
        "movl %edx, -0xac(%ebp)\n"
        "movl -0xd0(%ebp), %ecx\n" /* inptr */
        "cmpw $0, 0x70(%ecx)\n"
        "jne .Lf212a88_0021324c\n"
        /* { scope 2 */
        "movswl (%ecx), %eax\n" /* line 146 | dcval */
        "movl -0xcc(%ebp), %edi\n" /* quantptr, z4 */
        "imull (%edi), %eax\n" /* z4, dcval */
        "shll $2, %eax\n" /* dcval */
        "movl -0x9c(%ebp), %edx\n" /* line 148 */
        "movl %eax, (%edx)\n"
        "movl %eax, 0x20(%edx)\n" /* line 149 */
        "movl %eax, 0x40(%edx)\n" /* line 150 */
        "movl %eax, 0x60(%edx)\n" /* line 151 */
        "jmp .Lf212a88_00212cef\n"
        ".Lf212a88_0021317c:\n"
        "movl %edx, %edi\n" /* z4 */
        /* } scope */
        "addl $0x14, %edi\n" /* line 202 | z4 */
        "movl %edi, -0xb4(%ebp)\n" /* z4 */
        "movl -0xc8(%ebp), %edx\n" /* wsptr */
        "movl 0x14(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf212a88_0021320b\n"
        "movl %edx, %esi\n" /* z2 */
        "movl %edx, %ecx\n"
        "addl $0x18, %esi\n" /* z2 */
        "movl 0x18(%edx), %edi\n" /* z4 */
        "testl %edi, %edi\n" /* z4 */
        "jne .Lf212a88_00213238\n"
        "movl %edx, %edi\n" /* z4 */
        "addl $0x1c, %edi\n" /* z4 */
        "movl %edi, -0xb8(%ebp)\n" /* z4 */
        "movl 0x1c(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf212a88_00212e4e\n"
        /* { scope 2 */
        "movl (%edx), %eax\n" /* line 206 */
        "addl $0x10, %eax\n"
        "sarl $5, %eax\n"
        "andl $0x3ff, %eax\n"
        "movl -0xc0(%ebp), %ecx\n" /* range_limit */
        "movzbl (%ecx, %eax), %eax\n"
        "movl -0xc4(%ebp), %edi\n" /* line 208 | outptr, z4 */
        "movb %al, (%edi)\n" /* z4 */
        "movb %al, 1(%edi)\n" /* line 209 | z4 */
        "movb %al, 2(%edi)\n" /* line 210 | z4 */
        "movb %al, 3(%edi)\n" /* line 211 | z4 */
        "addl $0x20, %edx\n" /* line 213 */
        "movl %edx, -0xc8(%ebp)\n" /* wsptr */
        "jmp .Lf212a88_00213042\n"
        /* } scope */
        ".Lf212a88_002131f2:\n"
        "movl %edx, %edi\n" /* line 142 | z4 */
        "addl $0x60, %edi\n" /* z4 */
        "addl $0x70, %edx\n"
        "movl %edx, -0xac(%ebp)\n"
        "movl -0xd0(%ebp), %edx\n" /* inptr */
        "jmp .Lf212a88_00212b25\n"
        ".Lf212a88_0021320b:\n"
        "movl %edx, %esi\n" /* line 202 | z2 */
        "addl $0x18, %esi\n" /* z2 */
        "addl $0x1c, %edx\n"
        "movl %edx, -0xb8(%ebp)\n"
        "movl -0xc8(%ebp), %edx\n" /* wsptr */
        "jmp .Lf212a88_00212e4e\n"
        ".Lf212a88_00213224:\n"
        "addl $0x70, %ecx\n" /* line 142 */
        "movl %ecx, -0xac(%ebp)\n"
        "movl -0xd0(%ebp), %edx\n" /* inptr */
        "jmp .Lf212a88_00212b25\n"
        ".Lf212a88_00213238:\n"
        "addl $0x1c, %ecx\n" /* line 202 */
        "movl %ecx, -0xb8(%ebp)\n"
        "movl -0xc8(%ebp), %edx\n" /* wsptr */
        "jmp .Lf212a88_00212e4e\n"
        ".Lf212a88_0021324c:\n"
        "movl %ecx, %edx\n"
        "jmp .Lf212a88_00212b25\n"
    );
}

/* line 274 */
__attribute__((naked))
void jpeg_idct_2x2(j_decompress_ptr cinfo, jpeg_component_info *compptr, JCOEFPTR coef_block, JSAMPARRAY output_buf, JDIMENSION output_col)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 274 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "addl $-0x80, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 280 | cinfo */
        "movl 0x128(%eax), %eax\n"
        "subl $-0x80, %eax\n"
        "movl %eax, -0x60(%ebp)\n" /* range_limit */
        "movl 0xc(%ebp), %eax\n" /* line 288 | compptr */
        "movl 0x50(%eax), %eax\n"
        "movl %eax, -0x6c(%ebp)\n" /* quantptr */
        "movl 0x10(%ebp), %eax\n" /* coef_block */
        "movl %eax, -0x70(%ebp)\n" /* inptr */
        "movl $8, -0x5c(%ebp)\n" /* ctr */
        "leal -0x48(%ebp), %edx\n" /* workspace */
        "movl %edx, -0x7c(%ebp)\n"
        "movl %edx, -0x4c(%ebp)\n"
        "movl %eax, %ecx\n"
        "movzwl 0x10(%ecx), %ecx\n" /* line 294 */
        "movw %cx, -0x76(%ebp)\n"
        "testw %cx, %cx\n"
        "jne .Lf213253_002133a0\n"
        ".Lf213253_0021329c:\n"
        "movl -0x70(%ebp), %eax\n" /* inptr */
        "addl $0x30, %eax\n"
        "movl %eax, -0x54(%ebp)\n"
        "movl -0x70(%ebp), %edx\n" /* inptr */
        "cmpw $0, 0x30(%edx)\n"
        "je .Lf213253_002134cf\n"
        "movl %edx, %eax\n"
        "addl $0x70, %eax\n"
        "movl %edx, %ecx\n"
        "addl $0x50, %ecx\n"
        "movl -0x70(%ebp), %edx\n" /* inptr */
        ".Lf213253_002132c0:\n"
        "movswl (%edx), %edi\n" /* line 308 | tmp0 */
        "movl -0x6c(%ebp), %edx\n" /* quantptr */
        "imull (%edx), %edi\n" /* tmp0 */
        "shll $0xf, %edi\n" /* tmp0 */
        "movswl (%eax), %eax\n" /* line 313 */
        "imull 0xe0(%edx), %eax\n"
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "leal (%edx, %edx, 8), %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "addl %edx, %edx\n"
        "movswl (%ecx), %eax\n" /* line 315 */
        "movl -0x6c(%ebp), %ecx\n" /* quantptr */
        "imull 0xa0(%ecx), %eax\n"
        "leal (%eax, %eax, 2), %esi\n"
        "leal (%esi, %esi, 8), %esi\n"
        "movl %esi, %ecx\n"
        "shll $7, %ecx\n"
        "addl %ecx, %esi\n"
        "leal (%eax, %esi, 2), %esi\n"
        "subl %edx, %esi\n"
        "movl -0x54(%ebp), %eax\n" /* line 317 */
        "movswl (%eax), %edx\n"
        "movl -0x6c(%ebp), %ecx\n" /* quantptr */
        "imull 0x60(%ecx), %edx\n"
        "leal (%edx, %edx, 4), %ecx\n"
        "leal (%edx, %ecx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $5, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "addl %eax, %eax\n"
        "subl %eax, %esi\n"
        "movswl -0x76(%ebp), %edx\n" /* line 319 */
        "movl -0x6c(%ebp), %eax\n" /* quantptr */
        "imull 0x20(%eax), %edx\n"
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "shll $8, %eax\n"
        "subl %edx, %eax\n"
        "leal (%esi, %eax, 4), %eax\n"
        "leal 0x1000(%edi, %eax), %edx\n" /* line 323 | tmp0 */
        "sarl $0xd, %edx\n"
        "movl -0x4c(%ebp), %ecx\n"
        "movl %edx, (%ecx)\n"
        "subl %eax, %edi\n" /* line 324 | tmp0 */
        "addl $__mh_execute_header, %edi\n" /* tmp0 */
        "sarl $0xd, %edi\n" /* tmp0 */
        "movl %edi, 0x20(%ecx)\n" /* tmp0 */
        ".Lf213253_00213363:\n"
        "addl $2, -0x70(%ebp)\n" /* line 290 | inptr */
        "addl $4, -0x6c(%ebp)\n" /* quantptr */
        "addl $4, -0x4c(%ebp)\n"
        "subl $1, -0x5c(%ebp)\n" /* ctr */
        "movl -0x5c(%ebp), %eax\n" /* ctr */
        "testl %eax, %eax\n"
        "jle .Lf213253_002133bd\n"
        "cmpl $6, -0x5c(%ebp)\n" /* line 292 | ctr */
        "je .Lf213253_00213363\n"
        "cmpl $4, -0x5c(%ebp)\n" /* ctr */
        "je .Lf213253_00213363\n"
        "cmpl $2, -0x5c(%ebp)\n" /* ctr */
        "je .Lf213253_00213363\n"
        "movl -0x70(%ebp), %ecx\n" /* inptr */
        "movzwl 0x10(%ecx), %ecx\n" /* line 294 */
        "movw %cx, -0x76(%ebp)\n"
        "testw %cx, %cx\n"
        "je .Lf213253_0021329c\n"
        /* { scope 2 */
        ".Lf213253_002133a0:\n"
        "movl -0x70(%ebp), %eax\n" /* line 302 | inptr */
        "addl $0x70, %eax\n"
        "movl -0x70(%ebp), %ecx\n" /* inptr */
        "addl $0x50, %ecx\n"
        "movl -0x70(%ebp), %edx\n" /* inptr */
        "addl $0x30, %edx\n"
        "movl %edx, -0x54(%ebp)\n"
        "movl -0x70(%ebp), %edx\n" /* inptr */
        "jmp .Lf213253_002132c0\n"
        /* } scope */
        ".Lf213253_002133bd:\n"
        "movl -0x7c(%ebp), %eax\n" /* line 290 */
        "movl %eax, -0x68(%ebp)\n" /* wsptr */
        "movl $1, -0x50(%ebp)\n"
        ".Lf213253_002133ca:\n"
        "movl 0x18(%ebp), %eax\n" /* line 331 | output_col */
        "movl -0x50(%ebp), %edx\n"
        "movl 0x14(%ebp), %ecx\n" /* output_buf */
        "addl -4(%ecx, %edx, 4), %eax\n"
        "movl %eax, -0x64(%ebp)\n" /* outptr */
        "movl -0x68(%ebp), %edx\n" /* line 335 | wsptr */
        "movl 4(%edx), %esi\n"
        "testl %esi, %esi\n"
        "jne .Lf213253_002134b4\n"
        "movl %edx, %ecx\n"
        "addl $0xc, %edx\n"
        "movl %edx, -0x58(%ebp)\n"
        "movl 0xc(%ecx), %edi\n" /* tmp0 */
        "testl %edi, %edi\n" /* tmp0 */
        "je .Lf213253_00213507\n"
        "movl %ecx, %eax\n"
        "addl $0x1c, %eax\n"
        "addl $0x14, %ecx\n"
        "movl -0x68(%ebp), %edx\n" /* wsptr */
        ".Lf213253_00213406:\n"
        "movl (%edx), %edx\n" /* line 350 */
        "shll $0xf, %edx\n"
        "movl %edx, -0x74(%ebp)\n" /* tmp10 */
        "movl (%eax), %edx\n" /* line 354 */
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "addl %eax, %eax\n"
        "movl (%ecx), %ecx\n"
        "leal (%ecx, %ecx, 2), %edi\n" /* tmp0 */
        "leal (%edi, %edi, 8), %edi\n" /* tmp0 */
        "movl %edi, %edx\n" /* tmp0 */
        "shll $7, %edx\n"
        "addl %edx, %edi\n" /* tmp0 */
        "leal (%ecx, %edi, 2), %edi\n" /* tmp0 */
        "subl %eax, %edi\n" /* tmp0 */
        "leal (, %esi, 8), %ecx\n"
        "subl %esi, %ecx\n"
        "leal (%esi, %ecx, 4), %ecx\n"
        "shll $8, %ecx\n"
        "subl %esi, %ecx\n"
        "movl -0x58(%ebp), %eax\n"
        "movl (%eax), %esi\n"
        "leal (%esi, %esi, 4), %edx\n"
        "leal (%esi, %edx, 4), %edx\n"
        "movl %edx, %eax\n"
        "shll $5, %eax\n"
        "subl %edx, %eax\n"
        "leal (%esi, %eax, 2), %eax\n"
        "leal (%esi, %eax, 4), %eax\n"
        "addl %eax, %eax\n"
        "negl %eax\n"
        "leal (%eax, %ecx, 4), %ecx\n"
        "addl %ecx, %edi\n" /* tmp0 */
        "movl -0x74(%ebp), %edx\n" /* line 361 | tmp10 */
        "leal 0x80000(%edx, %edi), %eax\n"
        "sarl $0x14, %eax\n"
        "andl $0x3ff, %eax\n"
        "movl -0x60(%ebp), %ecx\n" /* range_limit */
        "movzbl (%ecx, %eax), %eax\n"
        "movl -0x64(%ebp), %edx\n" /* outptr */
        "movb %al, (%edx)\n"
        "movl -0x74(%ebp), %eax\n" /* line 364 | tmp10 */
        "subl %edi, %eax\n" /* tmp0 */
        "addl $0x80000, %eax\n"
        "sarl $0x14, %eax\n"
        "andl $0x3ff, %eax\n"
        "movzbl (%ecx, %eax), %eax\n"
        "movb %al, 1(%edx)\n"
        "addl $0x20, -0x68(%ebp)\n" /* line 368 | wsptr */
        ".Lf213253_0021349f:\n"
        "addl $1, -0x50(%ebp)\n"
        "cmpl $3, -0x50(%ebp)\n" /* line 330 */
        "jne .Lf213253_002133ca\n"
        "subl $-0x80, %esp\n" /* line 370 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf213253_002134b4:\n"
        "movl %edx, %eax\n"
        "movl %edx, %ecx\n"
        /* { scope 2 */
        "addl $0x1c, %eax\n" /* line 344 */
        "addl $0x14, %ecx\n"
        "movl -0x68(%ebp), %edx\n" /* wsptr */
        "addl $0xc, %edx\n"
        "movl %edx, -0x58(%ebp)\n"
        "movl -0x68(%ebp), %edx\n" /* wsptr */
        "jmp .Lf213253_00213406\n"
        ".Lf213253_002134cf:\n"
        "movl %edx, %ecx\n"
        "movl %edx, %eax\n"
        /* } scope */
        "addl $0x50, %ecx\n" /* line 294 */
        "cmpw $0, 0x50(%edx)\n"
        "jne .Lf213253_0021354a\n"
        "addl $0x70, %eax\n"
        "movl -0x70(%ebp), %edx\n" /* inptr */
        "cmpw $0, 0x70(%edx)\n"
        "jne .Lf213253_002132c0\n"
        /* { scope 2 */
        "movswl (%edx), %eax\n" /* line 297 | dcval */
        "movl -0x6c(%ebp), %ecx\n" /* quantptr */
        "imull (%ecx), %eax\n" /* dcval */
        "shll $2, %eax\n" /* dcval */
        "movl -0x4c(%ebp), %edx\n" /* line 299 */
        "movl %eax, (%edx)\n"
        "movl %eax, 0x20(%edx)\n" /* line 300 */
        "jmp .Lf213253_00213363\n"
        /* } scope */
        ".Lf213253_00213507:\n"
        "addl $0x14, %ecx\n" /* line 335 */
        "movl -0x68(%ebp), %eax\n" /* wsptr */
        "movl 0x14(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf213253_00213555\n"
        "addl $0x1c, %eax\n"
        "movl -0x68(%ebp), %edx\n" /* wsptr */
        "movl 0x1c(%edx), %edi\n" /* tmp0 */
        "testl %edi, %edi\n" /* tmp0 */
        "jne .Lf213253_00213406\n"
        /* { scope 2 */
        "movl (%edx), %eax\n" /* line 338 */
        "addl $0x10, %eax\n"
        "sarl $5, %eax\n"
        "andl $0x3ff, %eax\n"
        "movl -0x60(%ebp), %ecx\n" /* range_limit */
        "movzbl (%ecx, %eax), %eax\n"
        "movl -0x64(%ebp), %edx\n" /* line 340 | outptr */
        "movb %al, (%edx)\n"
        "movb %al, 1(%edx)\n" /* line 341 */
        "addl $0x20, -0x68(%ebp)\n" /* line 343 | wsptr */
        "jmp .Lf213253_0021349f\n"
        /* } scope */
        ".Lf213253_0021354a:\n"
        "addl $0x70, %eax\n" /* line 294 */
        "movl -0x70(%ebp), %edx\n" /* inptr */
        "jmp .Lf213253_002132c0\n"
        ".Lf213253_00213555:\n"
        "addl $0x1c, %eax\n" /* line 335 */
        "movl -0x68(%ebp), %edx\n" /* wsptr */
        "jmp .Lf213253_00213406\n"
    );
}

/* line 382 */
__attribute__((naked))
void jpeg_idct_1x1(j_decompress_ptr cinfo, jpeg_component_info *compptr, JCOEFPTR coef_block, JSAMPARRAY output_buf, JDIMENSION output_col)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 382 */
        "movl %esp, %ebp\n"
        "movl 0x14(%ebp), %eax\n" /* line 395 | output_buf */
        "movl (%eax), %ecx\n"
        "movl 0x10(%ebp), %eax\n" /* coef_block */
        "movswl (%eax), %eax\n"
        "movl 0xc(%ebp), %edx\n" /* compptr */
        "movl 0x50(%edx), %edx\n"
        "imull (%edx), %eax\n"
        "addl $4, %eax\n"
        "sarl $3, %eax\n"
        "andl $0x3ff, %eax\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 0x128(%edx), %edx\n"
        "movzbl 0x80(%edx, %eax), %edx\n"
        "movl 0x18(%ebp), %eax\n" /* output_col */
        "movb %dl, (%ecx, %eax)\n"
        "popl %ebp\n" /* line 396 */
        "retl\n"
    );
}

