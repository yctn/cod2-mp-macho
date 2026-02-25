/* ASM dump from: jdmarker.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jdmarker.c */

#include "common_types.h"
#include "imports.h"

static boolean get_sof(j_decompress_ptr cinfo);
static void examine_app0(INT32 remaining);
static boolean get_interesting_appn(j_decompress_ptr cinfo);
static boolean skip_variable(j_decompress_ptr cinfo);
static boolean next_marker(j_decompress_ptr cinfo);
static int read_markers(j_decompress_ptr cinfo);
static boolean read_restart_marker(j_decompress_ptr cinfo);
boolean jpeg_resync_to_restart(j_decompress_ptr cinfo, int desired);
static void reset_marker_reader(j_decompress_ptr cinfo, j_decompress_ptr cinfo_1, int marker_code, unsigned int length_limit, j_decompress_ptr cinfo_4, int marker_code_5, jpeg_marker_parser_method routine);
void jinit_marker_reader(j_decompress_ptr cinfo);

/* line 239 */
static __attribute__((naked))
boolean get_sof(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 239 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x30, %esp\n"
        "movl %eax, -0x18(%ebp)\n"
        "movl 0x20(%eax), %eax\n" /* line 243 | bytes_in_buffer */
        "movl %eax, -0x10(%ebp)\n" /* bytes_in_buffer, datasrc */
        "movl (%eax), %esi\n" /* next_input_byte */
        "movl 4(%eax), %eax\n" /* bytes_in_buffer */
        "movl -0x18(%ebp), %edi\n" /* line 245 | compptr */
        "movb %dl, 0xd0(%edi)\n" /* is_prog, compptr */
        "movb %cl, 0xd1(%edi)\n" /* line 246 | is_arith, compptr */
        "testl %eax, %eax\n" /* line 248 */
        "je .Lf1fdc74_001fdf57\n"
        ".Lf1fdc74_001fdca1:\n"
        "movzbl (%esi), %edi\n" /* next_input_byte, compptr */
        "shll $8, %edi\n" /* compptr */
        "leal 1(%esi), %ecx\n" /* next_input_byte, is_arith */
        "movl %eax, %edx\n" /* is_prog */
        "subl $1, %edx\n" /* is_prog */
        "je .Lf1fdc74_001fdf3a\n"
        ".Lf1fdc74_001fdcb5:\n"
        "movzbl (%ecx), %eax\n" /* is_arith */
        "addl %eax, %edi\n" /* compptr */
        "addl $1, %ecx\n" /* is_arith */
        "subl $1, %edx\n" /* line 250 | is_prog */
        "je .Lf1fdc74_001fdf71\n"
        "movzbl (%ecx), %eax\n" /* is_arith */
        "movl -0x18(%ebp), %esi\n" /* next_input_byte */
        "movl %eax, 0xc8(%esi)\n" /* next_input_byte */
        "addl $1, %ecx\n" /* is_arith */
        "subl $1, %edx\n" /* line 251 | is_prog */
        "je .Lf1fdc74_001fdfa1\n"
        ".Lf1fdc74_001fdcde:\n"
        "movzbl (%ecx), %eax\n" /* is_arith */
        "shll $8, %eax\n"
        "movl -0x18(%ebp), %esi\n" /* next_input_byte */
        "movl %eax, 0x28(%esi)\n" /* next_input_byte */
        "addl $1, %ecx\n" /* is_arith */
        "subl $1, %edx\n" /* is_prog */
        "je .Lf1fdc74_001fdfce\n"
        ".Lf1fdc74_001fdcf6:\n"
        "movzbl (%ecx), %eax\n" /* is_arith */
        "movl -0x18(%ebp), %esi\n" /* next_input_byte */
        "addl %eax, 0x28(%esi)\n" /* next_input_byte */
        "addl $1, %ecx\n" /* is_arith */
        "subl $1, %edx\n" /* line 252 | is_prog */
        "je .Lf1fdc74_001fe00b\n"
        ".Lf1fdc74_001fdd0b:\n"
        "movzbl (%ecx), %eax\n" /* is_arith */
        "shll $8, %eax\n"
        "movl -0x18(%ebp), %esi\n" /* next_input_byte */
        "movl %eax, 0x24(%esi)\n" /* next_input_byte */
        "addl $1, %ecx\n" /* is_arith */
        "subl $1, %edx\n" /* is_prog */
        "je .Lf1fdc74_001fe03c\n"
        ".Lf1fdc74_001fdd23:\n"
        "movzbl (%ecx), %eax\n" /* is_arith */
        "movl -0x18(%ebp), %esi\n" /* next_input_byte */
        "addl %eax, 0x24(%esi)\n" /* next_input_byte */
        "addl $1, %ecx\n" /* is_arith */
        "movl %edx, %eax\n" /* line 253 | is_prog */
        "subl $1, %eax\n"
        "jne .Lf1fdc74_001fdd4f\n"
        "movl %esi, (%esp)\n" /* next_input_byte */
        "movl -0x10(%ebp), %edx\n" /* datasrc, is_prog */
        "calll *0xc(%edx)\n" /* is_prog */
        "testb %al, %al\n"
        "je .Lf1fdc74_001fdf4e\n"
        "movl -0x10(%ebp), %esi\n" /* datasrc, next_input_byte */
        "movl (%esi), %ecx\n" /* next_input_byte, is_arith */
        "movl 4(%esi), %eax\n" /* next_input_byte */
        ".Lf1fdc74_001fdd4f:\n"
        "subl $1, %eax\n"
        "movl %eax, -0xc(%ebp)\n"
        "movzbl (%ecx), %eax\n" /* is_arith */
        "movl -0x18(%ebp), %edx\n" /* is_prog */
        "movl %eax, 0x2c(%edx)\n" /* is_prog */
        "leal 1(%ecx), %esi\n" /* is_arith, next_input_byte */
        "subl $8, %edi\n" /* line 255 | compptr */
        /* { scope 2 */
        "movl -0x18(%ebp), %eax\n" /* line 257 */
        "movl (%eax), %edx\n" /* is_prog */
        "leal 0x18(%edx), %ecx\n" /* is_prog, _mp */
        "movl 0x184(%eax), %eax\n"
        "movl %eax, 0x18(%edx)\n" /* is_prog */
        "movl -0x18(%ebp), %edx\n" /* is_prog */
        "movl 0x24(%edx), %eax\n" /* is_prog */
        "movl %eax, 4(%ecx)\n"
        "movl 0x28(%edx), %eax\n" /* is_prog */
        "movl %eax, 8(%ecx)\n"
        "movl 0x2c(%edx), %eax\n" /* is_prog */
        "movl %eax, 0xc(%ecx)\n"
        "movl (%edx), %eax\n" /* is_prog */
        "movl $0x64, 0x14(%eax)\n"
        "movl (%edx), %eax\n" /* is_prog */
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n" /* is_prog */
        "calll *4(%eax)\n"
        /* } scope */
        "movl -0x18(%ebp), %edx\n" /* line 261 | is_prog */
        "movl 0x19c(%edx), %eax\n" /* is_prog */
        "cmpb $0, 0xd(%eax)\n"
        "jne .Lf1fdc74_001fe0a5\n"
        "movl %edx, %eax\n" /* is_prog */
        ".Lf1fdc74_001fddb8:\n"
        "movl 0x28(%eax), %ecx\n" /* line 267 */
        "testl %ecx, %ecx\n"
        "je .Lf1fdc74_001fe09e\n"
        "movl 0x24(%eax), %edx\n" /* is_prog */
        "testl %edx, %edx\n" /* is_prog */
        "jne .Lf1fdc74_001fe05a\n"
        ".Lf1fdc74_001fddce:\n"
        "movl -0x18(%ebp), %edx\n" /* is_prog */
        ".Lf1fdc74_001fddd1:\n"
        "movl (%edx), %eax\n" /* line 269 | is_prog */
        "movl $0x20, 0x14(%eax)\n"
        "movl (%edx), %eax\n" /* is_prog */
        "movl %edx, (%esp)\n" /* is_prog */
        "calll *(%eax)\n"
        "movl -0x18(%ebp), %edx\n" /* line 271 | is_prog */
        "movl 0x2c(%edx), %eax\n" /* is_prog */
        "leal (%eax, %eax, 2), %eax\n"
        "cmpl %eax, %edi\n" /* compptr */
        "je .Lf1fdc74_001fe076\n"
        ".Lf1fdc74_001fddf2:\n"
        "movl (%edx), %eax\n" /* line 272 | is_prog */
        "movl $0xb, 0x14(%eax)\n"
        "movl (%edx), %eax\n" /* is_prog */
        "movl %edx, (%esp)\n" /* is_prog */
        "calll *(%eax)\n"
        "movl -0x18(%ebp), %edi\n" /* compptr */
        ".Lf1fdc74_001fde05:\n"
        "movl 0xcc(%edi), %ecx\n" /* line 274 | compptr */
        "testl %ecx, %ecx\n"
        "je .Lf1fdc74_001fe0bd\n"
        "movl %edi, %eax\n" /* compptr */
        ".Lf1fdc74_001fde15:\n"
        "movl 0xcc(%eax), %edi\n" /* line 279 | compptr */
        "movl 0x2c(%eax), %edx\n" /* is_prog */
        "testl %edx, %edx\n" /* is_prog */
        "jle .Lf1fdc74_001fe07d\n"
        "movl $0, -0x14(%ebp)\n" /* ci */
        "movl -0x14(%ebp), %edx\n" /* ci, is_prog */
        "jmp .Lf1fdc74_001fdee0\n"
        ".Lf1fdc74_001fde35:\n"
        "movzbl (%esi), %eax\n" /* line 282 | next_input_byte */
        "movl %eax, (%edi)\n" /* compptr */
        "leal 1(%esi), %edx\n" /* next_input_byte, is_prog */
        "movl -0xc(%ebp), %ecx\n" /* line 283 */
        "subl $1, %ecx\n"
        "je .Lf1fdc74_001fdf1d\n"
        ".Lf1fdc74_001fde49:\n"
        "movzbl (%edx), %eax\n" /* is_prog */
        "leal 1(%edx), %esi\n" /* is_prog, next_input_byte */
        "movl %eax, %edx\n" /* line 284 | is_prog */
        "shrl $4, %edx\n" /* is_prog */
        "movl %edx, 8(%edi)\n" /* is_prog, compptr */
        "andl $0xf, %eax\n" /* line 285 */
        "movl %eax, 0xc(%edi)\n" /* compptr */
        "movl %ecx, %eax\n" /* line 286 */
        "subl $1, %eax\n"
        "jne .Lf1fdc74_001fde80\n"
        "movl -0x18(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "movl -0x10(%ebp), %edx\n" /* datasrc, is_prog */
        "calll *0xc(%edx)\n" /* is_prog */
        "testb %al, %al\n"
        "je .Lf1fdc74_001fdf4e\n"
        "movl -0x10(%ebp), %eax\n" /* datasrc */
        "movl (%eax), %esi\n" /* next_input_byte */
        "movl 4(%eax), %eax\n"
        ".Lf1fdc74_001fde80:\n"
        "subl $1, %eax\n"
        "movl %eax, -0xc(%ebp)\n"
        "movzbl (%esi), %eax\n" /* next_input_byte */
        "movl %eax, 0x10(%edi)\n" /* compptr */
        "addl $1, %esi\n" /* next_input_byte */
        /* { scope 2 */
        "movl -0x18(%ebp), %eax\n" /* line 288 */
        "movl (%eax), %edx\n" /* is_prog */
        "leal 0x18(%edx), %ecx\n" /* is_prog, _mp */
        "movl (%edi), %eax\n" /* compptr */
        "movl %eax, 0x18(%edx)\n" /* is_prog */
        "movl 8(%edi), %eax\n" /* compptr */
        "movl %eax, 4(%ecx)\n"
        "movl 0xc(%edi), %eax\n" /* compptr */
        "movl %eax, 8(%ecx)\n"
        "movl 0x10(%edi), %eax\n" /* compptr */
        "movl %eax, 0xc(%ecx)\n"
        "movl -0x18(%ebp), %edx\n" /* is_prog */
        "movl (%edx), %eax\n" /* is_prog */
        "movl $0x65, 0x14(%eax)\n"
        "movl (%edx), %eax\n" /* is_prog */
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n" /* is_prog */
        "calll *4(%eax)\n"
        /* } scope */
        "addl $1, -0x14(%ebp)\n" /* line 280 | ci */
        "addl $0x54, %edi\n" /* compptr */
        "movl -0x14(%ebp), %edx\n" /* line 279 | ci, is_prog */
        "movl -0x18(%ebp), %eax\n"
        "cmpl %edx, 0x2c(%eax)\n" /* is_prog */
        "jle .Lf1fdc74_001fe07d\n"
        ".Lf1fdc74_001fdee0:\n"
        "movl %edx, 4(%edi)\n" /* line 281 | is_prog, compptr */
        "movl -0xc(%ebp), %eax\n" /* line 282 */
        "testl %eax, %eax\n"
        "jne .Lf1fdc74_001fde35\n"
        "movl -0x18(%ebp), %esi\n" /* next_input_byte */
        "movl %esi, (%esp)\n" /* next_input_byte */
        "movl -0x10(%ebp), %edx\n" /* datasrc, is_prog */
        "calll *0xc(%edx)\n" /* is_prog */
        "testb %al, %al\n"
        "je .Lf1fdc74_001fdf4e\n"
        "movl -0x10(%ebp), %eax\n" /* datasrc */
        "movl (%eax), %esi\n" /* next_input_byte */
        "movl 4(%eax), %edx\n" /* is_prog */
        "movl %edx, -0xc(%ebp)\n" /* is_prog */
        "movzbl (%esi), %eax\n" /* next_input_byte */
        "movl %eax, (%edi)\n" /* compptr */
        "leal 1(%esi), %edx\n" /* next_input_byte, is_prog */
        "movl -0xc(%ebp), %ecx\n" /* line 283 */
        "subl $1, %ecx\n"
        "jne .Lf1fdc74_001fde49\n"
        ".Lf1fdc74_001fdf1d:\n"
        "movl -0x18(%ebp), %esi\n" /* next_input_byte */
        "movl %esi, (%esp)\n" /* next_input_byte */
        "movl -0x10(%ebp), %edx\n" /* datasrc, is_prog */
        "calll *0xc(%edx)\n" /* is_prog */
        "testb %al, %al\n"
        "je .Lf1fdc74_001fdf4e\n"
        "movl -0x10(%ebp), %esi\n" /* datasrc, next_input_byte */
        "movl (%esi), %edx\n" /* next_input_byte, is_prog */
        "movl 4(%esi), %ecx\n" /* next_input_byte */
        "jmp .Lf1fdc74_001fde49\n"
        ".Lf1fdc74_001fdf3a:\n"
        "movl -0x18(%ebp), %eax\n" /* line 248 */
        "movl %eax, (%esp)\n"
        "movl -0x10(%ebp), %edx\n" /* datasrc, is_prog */
        "calll *0xc(%edx)\n" /* is_prog */
        "testb %al, %al\n"
        "jne .Lf1fdc74_001fdffe\n"
        ".Lf1fdc74_001fdf4e:\n"
        "xorl %eax, %eax\n" /* line 296 */
        "addl $0x30, %esp\n" /* line 297 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1fdc74_001fdf57:\n"
        "movl %edi, (%esp)\n" /* line 248 | compptr */
        "movl -0x10(%ebp), %edx\n" /* datasrc, is_prog */
        "calll *0xc(%edx)\n" /* is_prog */
        "testb %al, %al\n"
        "je .Lf1fdc74_001fdf4e\n"
        "movl -0x10(%ebp), %edi\n" /* datasrc, compptr */
        "movl (%edi), %esi\n" /* compptr, next_input_byte */
        "movl 4(%edi), %eax\n" /* compptr */
        "jmp .Lf1fdc74_001fdca1\n"
        ".Lf1fdc74_001fdf71:\n"
        "movl -0x18(%ebp), %eax\n" /* line 250 */
        "movl %eax, (%esp)\n"
        "movl -0x10(%ebp), %edx\n" /* datasrc, is_prog */
        "calll *0xc(%edx)\n" /* is_prog */
        "testb %al, %al\n"
        "je .Lf1fdc74_001fdf4e\n"
        "movl -0x10(%ebp), %esi\n" /* datasrc, next_input_byte */
        "movl (%esi), %ecx\n" /* next_input_byte, is_arith */
        "movl 4(%esi), %edx\n" /* next_input_byte, is_prog */
        "movzbl (%ecx), %eax\n" /* is_arith */
        "movl -0x18(%ebp), %esi\n" /* next_input_byte */
        "movl %eax, 0xc8(%esi)\n" /* next_input_byte */
        "addl $1, %ecx\n" /* is_arith */
        "subl $1, %edx\n" /* line 251 | is_prog */
        "jne .Lf1fdc74_001fdcde\n"
        ".Lf1fdc74_001fdfa1:\n"
        "movl %esi, (%esp)\n" /* next_input_byte */
        "movl -0x10(%ebp), %edx\n" /* datasrc, is_prog */
        "calll *0xc(%edx)\n" /* is_prog */
        "testb %al, %al\n"
        "je .Lf1fdc74_001fdf4e\n"
        "movl -0x10(%ebp), %esi\n" /* datasrc, next_input_byte */
        "movl (%esi), %ecx\n" /* next_input_byte, is_arith */
        "movl 4(%esi), %edx\n" /* next_input_byte, is_prog */
        "movzbl (%ecx), %eax\n" /* is_arith */
        "shll $8, %eax\n"
        "movl -0x18(%ebp), %esi\n" /* next_input_byte */
        "movl %eax, 0x28(%esi)\n" /* next_input_byte */
        "addl $1, %ecx\n" /* is_arith */
        "subl $1, %edx\n" /* is_prog */
        "jne .Lf1fdc74_001fdcf6\n"
        ".Lf1fdc74_001fdfce:\n"
        "movl %esi, (%esp)\n" /* next_input_byte */
        "movl -0x10(%ebp), %edx\n" /* datasrc, is_prog */
        "calll *0xc(%edx)\n" /* is_prog */
        "testb %al, %al\n"
        "je .Lf1fdc74_001fdf4e\n"
        "movl -0x10(%ebp), %esi\n" /* datasrc, next_input_byte */
        "movl (%esi), %ecx\n" /* next_input_byte, is_arith */
        "movl 4(%esi), %edx\n" /* next_input_byte, is_prog */
        "movzbl (%ecx), %eax\n" /* is_arith */
        "movl -0x18(%ebp), %esi\n" /* next_input_byte */
        "addl %eax, 0x28(%esi)\n" /* next_input_byte */
        "addl $1, %ecx\n" /* is_arith */
        "subl $1, %edx\n" /* line 252 | is_prog */
        "jne .Lf1fdc74_001fdd0b\n"
        "jmp .Lf1fdc74_001fe00b\n"
        ".Lf1fdc74_001fdffe:\n"
        "movl -0x10(%ebp), %esi\n" /* line 248 | datasrc, next_input_byte */
        "movl (%esi), %ecx\n" /* next_input_byte, is_arith */
        "movl 4(%esi), %edx\n" /* next_input_byte, is_prog */
        "jmp .Lf1fdc74_001fdcb5\n"
        ".Lf1fdc74_001fe00b:\n"
        "movl %esi, (%esp)\n" /* line 252 | next_input_byte */
        "movl -0x10(%ebp), %edx\n" /* datasrc, is_prog */
        "calll *0xc(%edx)\n" /* is_prog */
        "testb %al, %al\n"
        "je .Lf1fdc74_001fdf4e\n"
        "movl -0x10(%ebp), %esi\n" /* datasrc, next_input_byte */
        "movl (%esi), %ecx\n" /* next_input_byte, is_arith */
        "movl 4(%esi), %edx\n" /* next_input_byte, is_prog */
        "movzbl (%ecx), %eax\n" /* is_arith */
        "shll $8, %eax\n"
        "movl -0x18(%ebp), %esi\n" /* next_input_byte */
        "movl %eax, 0x24(%esi)\n" /* next_input_byte */
        "addl $1, %ecx\n" /* is_arith */
        "subl $1, %edx\n" /* is_prog */
        "jne .Lf1fdc74_001fdd23\n"
        ".Lf1fdc74_001fe03c:\n"
        "movl %esi, (%esp)\n" /* next_input_byte */
        "movl -0x10(%ebp), %edx\n" /* datasrc, is_prog */
        "calll *0xc(%edx)\n" /* is_prog */
        "testb %al, %al\n"
        "je .Lf1fdc74_001fdf4e\n"
        "movl -0x10(%ebp), %esi\n" /* datasrc, next_input_byte */
        "movl (%esi), %ecx\n" /* next_input_byte, is_arith */
        "movl 4(%esi), %edx\n" /* next_input_byte, is_prog */
        "jmp .Lf1fdc74_001fdd23\n"
        ".Lf1fdc74_001fe05a:\n"
        "movl 0x2c(%eax), %eax\n" /* line 267 */
        "testl %eax, %eax\n"
        "jle .Lf1fdc74_001fddce\n"
        "movl -0x18(%ebp), %edx\n" /* line 271 | is_prog */
        "movl 0x2c(%edx), %eax\n" /* is_prog */
        "leal (%eax, %eax, 2), %eax\n"
        "cmpl %eax, %edi\n" /* compptr */
        "jne .Lf1fdc74_001fddf2\n"
        ".Lf1fdc74_001fe076:\n"
        "movl %edx, %edi\n" /* is_prog, compptr */
        "jmp .Lf1fdc74_001fde05\n"
        ".Lf1fdc74_001fe07d:\n"
        "movl 0x19c(%eax), %eax\n" /* line 293 */
        "movb $1, 0xd(%eax)\n"
        "movl -0x10(%ebp), %eax\n" /* line 295 | datasrc */
        "movl %esi, (%eax)\n" /* next_input_byte */
        "movl -0xc(%ebp), %edx\n" /* is_prog */
        "movl %edx, 4(%eax)\n" /* is_prog */
        "movl $1, %eax\n"
        "addl $0x30, %esp\n" /* line 297 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1fdc74_001fe09e:\n"
        "movl %eax, %edx\n" /* is_prog */
        "jmp .Lf1fdc74_001fddd1\n"
        ".Lf1fdc74_001fe0a5:\n"
        "movl (%edx), %eax\n" /* line 262 | is_prog */
        "movl $0x3a, 0x14(%eax)\n"
        "movl (%edx), %eax\n" /* is_prog */
        "movl %edx, (%esp)\n" /* is_prog */
        "calll *(%eax)\n"
        "movl -0x18(%ebp), %eax\n"
        "jmp .Lf1fdc74_001fddb8\n"
        ".Lf1fdc74_001fe0bd:\n"
        "movl 4(%edi), %ecx\n" /* line 275 | compptr */
        "movl 0x2c(%edi), %eax\n" /* compptr */
        "leal (%eax, %eax, 4), %edx\n" /* is_prog */
        "leal (%eax, %edx, 4), %edx\n" /* is_prog */
        "shll $2, %edx\n" /* is_prog */
        "movl %edx, 8(%esp)\n" /* is_prog */
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* compptr */
        "calll *(%ecx)\n"
        "movl %eax, 0xcc(%edi)\n" /* compptr */
        "movl -0x18(%ebp), %eax\n"
        "jmp .Lf1fdc74_001fde15\n"
    );
}

/* line 590 */
static __attribute__((naked))
void examine_app0(INT32 remaining)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 590 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x20, %esp\n"
        "movl %eax, %esi\n" /* cinfo */
        "movl %edx, %edi\n" /* data */
        "movl 8(%ebp), %eax\n" /* line 591 | remaining */
        "addl %ecx, %eax\n" /* datalen */
        "movl %eax, -0xc(%ebp)\n" /* totallen */
        "cmpl $0xd, %ecx\n" /* line 593 | datalen */
        "jbe .Lf1fe0eb_001fe135\n"
        "cmpb $0x4a, (%edx)\n"
        "je .Lf1fe0eb_001fe19f\n"
        ".Lf1fe0eb_001fe10d:\n"
        "movl (%esi), %eax\n" /* line 654 | cinfo */
        "movl $0x4d, 0x14(%eax)\n"
        ".Lf1fe0eb_001fe116:\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl -0xc(%ebp), %edx\n" /* totallen */
        "movl %edx, 0x18(%eax)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *4(%eax)\n"
        ".Lf1fe0eb_001fe12e:\n"
        "addl $0x20, %esp\n" /* line 656 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1fe0eb_001fe135:\n"
        "cmpl $5, %ecx\n" /* line 627 */
        "jbe .Lf1fe0eb_001fe10d\n"
        ".Lf1fe0eb_001fe13a:\n"
        "cmpb $0x4a, (%edi)\n" /* data */
        "jne .Lf1fe0eb_001fe10d\n"
        "cmpb $0x46, 1(%edi)\n" /* data */
        "jne .Lf1fe0eb_001fe10d\n"
        "cmpb $0x58, 2(%edi)\n" /* data */
        "jne .Lf1fe0eb_001fe10d\n"
        "cmpb $0x58, 3(%edi)\n" /* data */
        "jne .Lf1fe0eb_001fe10d\n"
        "cmpb $0, 4(%edi)\n" /* data */
        "jne .Lf1fe0eb_001fe10d\n"
        "movzbl 5(%edi), %eax\n" /* line 637 | data */
        "cmpb $0x11, %al\n"
        "je .Lf1fe0eb_001fe305\n"
        "cmpb $0x13, %al\n"
        "je .Lf1fe0eb_001fe313\n"
        "cmpb $0x10, %al\n"
        "je .Lf1fe0eb_001fe321\n"
        "movl (%esi), %eax\n" /* line 648 | cinfo */
        "movl $0x59, 0x14(%eax)\n"
        "movl (%esi), %edx\n" /* cinfo */
        "movzbl 5(%edi), %eax\n" /* data */
        "movl %eax, 0x18(%edx)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl -0xc(%ebp), %edx\n" /* totallen */
        "movl %edx, 0x1c(%eax)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *4(%eax)\n"
        "jmp .Lf1fe0eb_001fe12e\n"
        ".Lf1fe0eb_001fe19f:\n"
        "cmpb $0x46, 1(%edx)\n" /* line 593 */
        "jne .Lf1fe0eb_001fe13a\n"
        "cmpb $0x49, 2(%edx)\n"
        "jne .Lf1fe0eb_001fe13a\n"
        "cmpb $0x46, 3(%edx)\n"
        "jne .Lf1fe0eb_001fe13a\n"
        "cmpb $0, 4(%edx)\n"
        "jne .Lf1fe0eb_001fe13a\n"
        "movb $1, 0x108(%esi)\n" /* line 600 | cinfo */
        "movzbl 5(%edx), %eax\n" /* line 601 */
        "movb %al, 0x109(%esi)\n" /* cinfo */
        "movzbl 6(%edx), %eax\n" /* line 602 */
        "movb %al, 0x10a(%esi)\n" /* cinfo */
        "movzbl 7(%edx), %eax\n" /* line 603 */
        "movb %al, 0x10b(%esi)\n" /* cinfo */
        "movzbl 8(%edx), %edx\n" /* line 604 */
        "shll $8, %edx\n"
        "movzbw 9(%edi), %ax\n" /* data */
        "addl %edx, %eax\n"
        "movw %ax, 0x10c(%esi)\n" /* cinfo */
        "movzbl 0xa(%edi), %edx\n" /* line 605 | data */
        "shll $8, %edx\n"
        "movzbw 0xb(%edi), %ax\n" /* data */
        "addl %edx, %eax\n"
        "movw %ax, 0x10e(%esi)\n" /* cinfo */
        "cmpb $1, 0x109(%esi)\n" /* line 612 | cinfo */
        "je .Lf1fe0eb_001fe240\n"
        "movl (%esi), %eax\n" /* line 613 | cinfo */
        "movl $0x77, 0x14(%eax)\n"
        "movl (%esi), %edx\n" /* cinfo */
        "movzbl 0x109(%esi), %eax\n" /* cinfo */
        "movl %eax, 0x18(%edx)\n"
        "movl (%esi), %edx\n" /* cinfo */
        "movzbl 0x10a(%esi), %eax\n" /* cinfo */
        "movl %eax, 0x1c(%edx)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *4(%eax)\n"
        /* { scope 2 */
        ".Lf1fe0eb_001fe240:\n"
        "movl (%esi), %edx\n" /* line 616 | cinfo */
        "leal 0x18(%edx), %ecx\n" /* _mp */
        "movzbl 0x109(%esi), %eax\n" /* cinfo */
        "movl %eax, 0x18(%edx)\n"
        "movzbl 0x10a(%esi), %eax\n" /* cinfo */
        "movl %eax, 4(%ecx)\n"
        "movzwl 0x10c(%esi), %eax\n" /* cinfo */
        "movl %eax, 8(%ecx)\n"
        "movzwl 0x10e(%esi), %eax\n" /* cinfo */
        "movl %eax, 0xc(%ecx)\n"
        "movzbl 0x10b(%esi), %eax\n" /* cinfo */
        "movl %eax, 0x10(%ecx)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl $0x57, 0x14(%eax)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *4(%eax)\n"
        /* } scope */
        "movzbl 0xc(%edi), %eax\n" /* line 620 | data */
        "orb 0xd(%edi), %al\n" /* data */
        "jne .Lf1fe0eb_001fe2d8\n"
        ".Lf1fe0eb_001fe299:\n"
        "movl -0xc(%ebp), %ecx\n" /* line 623 | totallen */
        "subl $0xe, %ecx\n"
        "movzbl 0xc(%edi), %eax\n" /* line 624 | data */
        "movzbl 0xd(%edi), %edx\n" /* data */
        "imull %edx, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "cmpl %eax, %ecx\n"
        "je .Lf1fe0eb_001fe12e\n"
        "movl (%esi), %eax\n" /* line 626 | cinfo */
        "movl $0x58, 0x14(%eax)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl %ecx, 0x18(%eax)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *4(%eax)\n"
        "jmp .Lf1fe0eb_001fe12e\n"
        ".Lf1fe0eb_001fe2d8:\n"
        "movl (%esi), %eax\n" /* line 621 | cinfo */
        "movl $0x5a, 0x14(%eax)\n"
        "movl (%esi), %edx\n" /* cinfo */
        "movzbl 0xc(%edi), %eax\n" /* data */
        "movl %eax, 0x18(%edx)\n"
        "movl (%esi), %edx\n" /* cinfo */
        "movzbl 0xd(%edi), %eax\n" /* data */
        "movl %eax, 0x1c(%edx)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *4(%eax)\n"
        "jmp .Lf1fe0eb_001fe299\n"
        ".Lf1fe0eb_001fe305:\n"
        "movl (%esi), %eax\n" /* line 642 | cinfo */
        "movl $0x6d, 0x14(%eax)\n"
        "jmp .Lf1fe0eb_001fe116\n"
        ".Lf1fe0eb_001fe313:\n"
        "movl (%esi), %eax\n" /* line 645 | cinfo */
        "movl $0x6e, 0x14(%eax)\n"
        "jmp .Lf1fe0eb_001fe116\n"
        ".Lf1fe0eb_001fe321:\n"
        "movl (%esi), %eax\n" /* line 639 | cinfo */
        "movl $0x6c, 0x14(%eax)\n"
        "jmp .Lf1fe0eb_001fe116\n"
    );
}

/* line 693 */
static __attribute__((naked))
boolean get_interesting_appn(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1: flags0 */
        "pushl %ebp\n" /* line 693 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x50, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 697 | cinfo, bytes_in_buffer */
        "movl 0x20(%eax), %eax\n" /* bytes_in_buffer */
        "movl %eax, -0x30(%ebp)\n" /* bytes_in_buffer, datasrc */
        "movl (%eax), %edx\n" /* next_input_byte */
        "movl %eax, %ecx\n" /* bytes_in_buffer */
        "movl 4(%eax), %eax\n" /* bytes_in_buffer */
        "testl %eax, %eax\n" /* line 699 */
        "je .Lf1fe32f_001fe46a\n"
        "movzbl (%edx), %esi\n" /* i */
        "shll $8, %esi\n" /* i */
        "addl $1, %edx\n"
        "subl $1, %eax\n"
        "je .Lf1fe32f_001fe491\n"
        ".Lf1fe32f_001fe361:\n"
        "subl $1, %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movzbl (%edx), %eax\n"
        "leal 1(%edx), %edi\n"
        "leal -2(%esi, %eax), %eax\n" /* line 700 | i */
        "movl %eax, -0x20(%ebp)\n"
        "cmpl $0xd, %eax\n" /* line 703 */
        "jg .Lf1fe32f_001fe45e\n"
        "movl -0x20(%ebp), %eax\n" /* line 705 */
        "testl %eax, %eax\n"
        "jle .Lf1fe32f_001fe507\n"
        "movl -0x20(%ebp), %eax\n" /* line 706 */
        "movl %eax, -0x34(%ebp)\n" /* numtoread */
        ".Lf1fe32f_001fe38e:\n"
        "xorl %esi, %esi\n" /* i */
        "jmp .Lf1fe32f_001fe3a8\n"
        ".Lf1fe32f_001fe392:\n"
        "subl $1, -0x24(%ebp)\n" /* line 710 */
        "movzbl (%edi), %eax\n"
        "movb %al, -0x16(%ebp, %esi)\n"
        "addl $1, %edi\n"
        "addl $1, %esi\n" /* line 709 | i */
        "cmpl %esi, -0x34(%ebp)\n" /* i, numtoread */
        "je .Lf1fe32f_001fe3e4\n"
        ".Lf1fe32f_001fe3a8:\n"
        "movl -0x24(%ebp), %eax\n" /* line 710 */
        "testl %eax, %eax\n"
        "jne .Lf1fe32f_001fe392\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl %edx, (%esp)\n"
        "movl -0x30(%ebp), %ecx\n" /* datasrc */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf1fe32f_001fe4ae\n"
        "movl -0x30(%ebp), %eax\n" /* datasrc */
        "movl (%eax), %edi\n"
        "movl 4(%eax), %edx\n"
        "movl %edx, -0x24(%ebp)\n"
        "subl $1, -0x24(%ebp)\n"
        "movzbl (%edi), %eax\n"
        "movb %al, -0x16(%ebp, %esi)\n"
        "addl $1, %edi\n"
        "addl $1, %esi\n" /* line 709 | i */
        "cmpl %esi, -0x34(%ebp)\n" /* i, numtoread */
        "jne .Lf1fe32f_001fe3a8\n"
        ".Lf1fe32f_001fe3e4:\n"
        "movl -0x20(%ebp), %ecx\n" /* line 711 */
        "subl -0x34(%ebp), %ecx\n" /* numtoread */
        "movl %ecx, -0x1c(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 714 | cinfo */
        "movl 0x184(%edx), %eax\n"
        "cmpl $0xe0, %eax\n"
        "je .Lf1fe32f_001fe4b7\n"
        "cmpl $0xee, %eax\n"
        "je .Lf1fe32f_001fe4cc\n"
        "movl 8(%ebp), %edx\n" /* line 723 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x44, 0x14(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl (%ecx), %edx\n"
        "movl 0x184(%ecx), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf1fe32f_001fe42d:\n"
        "movl -0x30(%ebp), %eax\n" /* line 728 | datasrc */
        "movl %edi, (%eax)\n"
        "movl -0x24(%ebp), %edx\n"
        "movl %edx, 4(%eax)\n"
        "movl -0x1c(%ebp), %esi\n" /* line 729 | i */
        "testl %esi, %esi\n" /* i */
        "jle .Lf1fe32f_001fe452\n"
        "movl 8(%ebp), %ecx\n" /* line 730 | cinfo */
        "movl 0x20(%ecx), %eax\n"
        "movl -0x1c(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *0x10(%eax)\n"
        ".Lf1fe32f_001fe452:\n"
        "movl $1, %eax\n"
        "addl $0x50, %esp\n" /* line 733 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1fe32f_001fe45e:\n"
        "movl $0xe, -0x34(%ebp)\n" /* line 703 | numtoread */
        "jmp .Lf1fe32f_001fe38e\n"
        ".Lf1fe32f_001fe46a:\n"
        "movl 8(%ebp), %eax\n" /* line 699 | cinfo */
        "movl %eax, (%esp)\n"
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf1fe32f_001fe4ae\n"
        "movl -0x30(%ebp), %ecx\n" /* datasrc */
        "movl (%ecx), %edx\n"
        "movl 4(%ecx), %eax\n"
        "movzbl (%edx), %esi\n" /* i */
        "shll $8, %esi\n" /* i */
        "addl $1, %edx\n"
        "subl $1, %eax\n"
        "jne .Lf1fe32f_001fe361\n"
        ".Lf1fe32f_001fe491:\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "movl -0x30(%ebp), %edx\n" /* datasrc */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "je .Lf1fe32f_001fe4ae\n"
        "movl -0x30(%ebp), %ecx\n" /* datasrc */
        "movl (%ecx), %edx\n"
        "movl 4(%ecx), %eax\n"
        "jmp .Lf1fe32f_001fe361\n"
        ".Lf1fe32f_001fe4ae:\n"
        "xorl %eax, %eax\n" /* line 730 */
        "addl $0x50, %esp\n" /* line 733 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1fe32f_001fe4b7:\n"
        "movl %edx, %eax\n"
        "leal -0x16(%ebp), %edx\n" /* line 716 | b */
        "movl %ecx, (%esp)\n"
        "movl -0x34(%ebp), %ecx\n" /* numtoread */
        "calll examine_app0\n"
        "jmp .Lf1fe32f_001fe42d\n"
        /* { scope 2 */
        ".Lf1fe32f_001fe4cc:\n"
        "cmpl $0xb, -0x34(%ebp)\n" /* line 669 | numtoread */
        "jbe .Lf1fe32f_001fe4d8\n"
        "cmpb $0x41, -0x16(%ebp)\n" /* b */
        "je .Lf1fe32f_001fe513\n"
        ".Lf1fe32f_001fe4d8:\n"
        "movl 8(%ebp), %edx\n" /* line 685 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x4e, 0x14(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl (%ecx), %edx\n"
        "movl -0x34(%ebp), %eax\n" /* numtoread */
        "addl -0x1c(%ebp), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl (%ecx), %eax\n"
        "movl $1, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *4(%eax)\n"
        "jmp .Lf1fe32f_001fe42d\n"
        /* } scope */
        ".Lf1fe32f_001fe507:\n"
        "movl $0, -0x34(%ebp)\n" /* line 705 | numtoread */
        "jmp .Lf1fe32f_001fe3e4\n"
        /* { scope 2 */
        ".Lf1fe32f_001fe513:\n"
        "cmpb $0x64, -0x15(%ebp)\n" /* line 669 */
        "jne .Lf1fe32f_001fe4d8\n"
        "cmpb $0x6f, -0x14(%ebp)\n"
        "jne .Lf1fe32f_001fe4d8\n"
        "cmpb $0x62, -0x13(%ebp)\n"
        "jne .Lf1fe32f_001fe4d8\n"
        "cmpb $0x65, -0x12(%ebp)\n"
        "jne .Lf1fe32f_001fe4d8\n"
        "movzbl -0xf(%ebp), %edx\n" /* line 677 */
        "shll $8, %edx\n"
        "movzbl -0xe(%ebp), %eax\n"
        "addl %eax, %edx\n"
        "movl %edx, -0x28(%ebp)\n" /* flags0 */
        "movzbl -0xd(%ebp), %ecx\n" /* line 678 */
        "shll $8, %ecx\n"
        "movzbl -0xc(%ebp), %eax\n"
        "addl %eax, %ecx\n"
        "movzbl -0xb(%ebp), %eax\n" /* line 679 */
        "movb %al, -0x29(%ebp)\n"
        /* { scope 3 */
        "movl 8(%ebp), %edx\n" /* line 680 | cinfo */
        "movl (%edx), %edx\n"
        "movl %edx, -0x3c(%ebp)\n"
        "movl %edx, %esi\n" /* _mp */
        "addl $0x18, %esi\n" /* _mp */
        "movzbl -0x11(%ebp), %eax\n"
        "shll $8, %eax\n"
        "movzbl -0x10(%ebp), %edx\n"
        "addl %edx, %eax\n"
        "movl -0x3c(%ebp), %edx\n"
        "movl %eax, 0x18(%edx)\n"
        "movl -0x28(%ebp), %eax\n" /* flags0 */
        "movl %eax, 4(%esi)\n" /* _mp */
        "movl %ecx, 8(%esi)\n" /* _mp */
        "movzbl -0x29(%ebp), %eax\n"
        "movl %eax, 0xc(%esi)\n" /* _mp */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl (%edx), %eax\n"
        "movl $0x4c, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        /* } scope */
        "movl 8(%ebp), %ecx\n" /* line 681 | cinfo */
        "movb $1, 0x110(%ecx)\n"
        "movzbl -0x29(%ebp), %eax\n" /* line 682 */
        "movb %al, 0x111(%ecx)\n"
        "jmp .Lf1fe32f_001fe42d\n"
    );
}

/* line 847 */
static __attribute__((naked))
boolean skip_variable(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 847 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 849 | cinfo, next_input_byte */
        "movl 0x20(%eax), %edi\n" /* datasrc */
        "movl (%edi), %eax\n" /* datasrc, next_input_byte */
        "movl 4(%edi), %edx\n" /* datasrc, bytes_in_buffer */
        "testl %edx, %edx\n" /* line 851 */
        "je .Lf1fe5b4_001fe670\n"
        ".Lf1fe5b4_001fe5cf:\n"
        "movzbl (%eax), %esi\n" /* length */
        "shll $8, %esi\n" /* length */
        "addl $1, %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "subl $1, %edx\n"
        "movl %edx, -0xc(%ebp)\n"
        "jne .Lf1fe5b4_001fe66c\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %ecx, (%esp)\n"
        "calll *0xc(%edi)\n" /* datasrc */
        "testb %al, %al\n"
        "je .Lf1fe5b4_001fe687\n"
        "movl (%edi), %eax\n" /* datasrc */
        "movl %eax, -0x10(%ebp)\n"
        "movl 4(%edi), %edx\n" /* datasrc */
        "movl %edx, -0xc(%ebp)\n"
        "movl %eax, %ecx\n"
        ".Lf1fe5b4_001fe605:\n"
        "movzbl (%ecx), %eax\n"
        "leal -2(%esi, %eax), %esi\n" /* line 852 | length */
        "movl 8(%ebp), %edx\n" /* line 854 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x5b, 0x14(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl (%ecx), %edx\n"
        "movl 0x184(%ecx), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl (%ecx), %eax\n"
        "movl %esi, 0x1c(%eax)\n" /* length */
        "movl (%ecx), %eax\n"
        "movl $1, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *4(%eax)\n"
        "movl -0x10(%ebp), %eax\n" /* line 856 */
        "addl $1, %eax\n"
        "movl %eax, (%edi)\n" /* datasrc */
        "movl -0xc(%ebp), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 4(%edi)\n" /* datasrc */
        "testl %esi, %esi\n" /* line 857 | length */
        "jle .Lf1fe5b4_001fe660\n"
        "movl 8(%ebp), %edx\n" /* line 858 | cinfo */
        "movl 0x20(%edx), %eax\n"
        "movl %esi, 4(%esp)\n" /* length */
        "movl %edx, (%esp)\n"
        "calll *0x10(%eax)\n"
        ".Lf1fe5b4_001fe660:\n"
        "movl $1, %eax\n"
        "addl $0x20, %esp\n" /* line 861 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1fe5b4_001fe66c:\n"
        "movl %eax, %ecx\n"
        "jmp .Lf1fe5b4_001fe605\n"
        ".Lf1fe5b4_001fe670:\n"
        "movl 8(%ebp), %edx\n" /* line 851 | cinfo */
        "movl %edx, (%esp)\n"
        "calll *0xc(%edi)\n" /* datasrc */
        "testb %al, %al\n"
        "je .Lf1fe5b4_001fe687\n"
        "movl (%edi), %eax\n" /* datasrc */
        "movl 4(%edi), %edx\n" /* datasrc */
        "jmp .Lf1fe5b4_001fe5cf\n"
        ".Lf1fe5b4_001fe687:\n"
        "xorl %eax, %eax\n" /* line 858 */
        "addl $0x20, %esp\n" /* line 861 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 875 */
static __attribute__((naked))
boolean next_marker(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 875 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x20, %esp\n"
        "movl %eax, -0x14(%ebp)\n"
        "movl 0x20(%eax), %eax\n" /* line 877 */
        "movl %eax, -0xc(%ebp)\n" /* datasrc */
        "movl (%eax), %edi\n" /* next_input_byte */
        "movl 4(%eax), %esi\n" /* bytes_in_buffer */
        "testl %esi, %esi\n" /* line 880 | bytes_in_buffer */
        "je .Lf1fe690_001fe74b\n"
        ".Lf1fe690_001fe6ae:\n"
        "subl $1, %esi\n" /* bytes_in_buffer */
        "movzbl (%edi), %eax\n" /* next_input_byte */
        "addl $1, %edi\n" /* next_input_byte */
        "addb $1, %al\n" /* line 886 */
        "je .Lf1fe690_001fe713\n"
        "movl -0x14(%ebp), %edx\n" /* line 887 */
        "movl 0x19c(%edx), %eax\n"
        "addl $1, 0x14(%eax)\n"
        "movl -0xc(%ebp), %ecx\n" /* line 888 | datasrc */
        "movl %edi, (%ecx)\n" /* next_input_byte */
        "movl %esi, 4(%ecx)\n" /* bytes_in_buffer */
        "testl %esi, %esi\n" /* line 889 | bytes_in_buffer */
        "jne .Lf1fe690_001fe6ae\n"
        "movl %edx, (%esp)\n"
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf1fe690_001fe75b\n"
        ".Lf1fe690_001fe6de:\n"
        "movl -0xc(%ebp), %eax\n" /* line 880 | datasrc */
        "movl (%eax), %edi\n" /* next_input_byte */
        "movl 4(%eax), %esi\n" /* bytes_in_buffer */
        "jmp .Lf1fe690_001fe6ae\n"
        ".Lf1fe690_001fe6e8:\n"
        "movl -0x14(%ebp), %edx\n" /* line 897 */
        "movl %edx, (%esp)\n"
        "movl -0xc(%ebp), %ecx\n" /* datasrc */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf1fe690_001fe75b\n"
        "movl -0xc(%ebp), %eax\n" /* datasrc */
        "movl (%eax), %edi\n" /* next_input_byte */
        "movl 4(%eax), %esi\n" /* bytes_in_buffer */
        "subl $1, %esi\n" /* bytes_in_buffer */
        "movzbl (%edi), %eax\n" /* next_input_byte */
        "movzbl %al, %edx\n"
        "movl %edx, -0x10(%ebp)\n" /* c */
        "addl $1, %edi\n" /* next_input_byte */
        "cmpb $0xff, %al\n" /* line 898 */
        "jne .Lf1fe690_001fe72a\n"
        ".Lf1fe690_001fe713:\n"
        "testl %esi, %esi\n" /* line 897 | bytes_in_buffer */
        "je .Lf1fe690_001fe6e8\n"
        "subl $1, %esi\n" /* bytes_in_buffer */
        "movzbl (%edi), %eax\n" /* next_input_byte */
        "movzbl %al, %edx\n"
        "movl %edx, -0x10(%ebp)\n" /* c */
        "addl $1, %edi\n" /* next_input_byte */
        "cmpb $0xff, %al\n" /* line 898 */
        "je .Lf1fe690_001fe713\n"
        ".Lf1fe690_001fe72a:\n"
        "testb %al, %al\n" /* line 899 */
        "jne .Lf1fe690_001fe764\n"
        "movl -0x14(%ebp), %ecx\n" /* line 904 */
        "movl 0x19c(%ecx), %eax\n"
        "addl $2, 0x14(%eax)\n"
        "movl -0xc(%ebp), %eax\n" /* line 905 | datasrc */
        "movl %edi, (%eax)\n" /* next_input_byte */
        "movl %esi, 4(%eax)\n" /* bytes_in_buffer */
        "testl %esi, %esi\n" /* line 880 | bytes_in_buffer */
        "jne .Lf1fe690_001fe6ae\n"
        ".Lf1fe690_001fe74b:\n"
        "movl -0x14(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "movl -0xc(%ebp), %ecx\n" /* datasrc */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "jne .Lf1fe690_001fe6de\n"
        ".Lf1fe690_001fe75b:\n"
        "xorl %eax, %eax\n" /* line 916 */
        ".Lf1fe690_001fe75d:\n"
        "addl $0x20, %esp\n" /* line 917 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1fe690_001fe764:\n"
        "movl -0x14(%ebp), %edx\n" /* line 908 */
        "movl 0x19c(%edx), %eax\n"
        "movl 0x14(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1fe690_001fe78e\n"
        "movl %edx, %eax\n"
        ".Lf1fe690_001fe776:\n"
        "movl -0x10(%ebp), %edx\n" /* line 913 | c */
        "movl %edx, 0x184(%eax)\n"
        "movl -0xc(%ebp), %ecx\n" /* line 915 | datasrc */
        "movl %edi, (%ecx)\n" /* next_input_byte */
        "movl %esi, 4(%ecx)\n" /* bytes_in_buffer */
        "movl $1, %eax\n"
        "jmp .Lf1fe690_001fe75d\n"
        ".Lf1fe690_001fe78e:\n"
        "movl (%edx), %eax\n" /* line 909 */
        "movl $0x74, 0x14(%eax)\n"
        "movl -0x14(%ebp), %ecx\n"
        "movl (%ecx), %edx\n"
        "movl 0x19c(%ecx), %eax\n"
        "movl 0x14(%eax), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl (%ecx), %eax\n"
        "movl -0x10(%ebp), %edx\n" /* c */
        "movl %edx, 0x1c(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl $0xffffffff, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *4(%eax)\n"
        "movl -0x14(%ebp), %ecx\n" /* line 910 */
        "movl 0x19c(%ecx), %eax\n"
        "movl $0, 0x14(%eax)\n"
        "movl -0x14(%ebp), %eax\n"
        "jmp .Lf1fe690_001fe776\n"
    );
}

/* line 953 */
static __attribute__((naked))
int read_markers(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 953 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1dc, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "leal -0x29(%ebp), %eax\n" /* bits */
        "movl %eax, -0x1c4(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 958 | cinfo */
        "movl 0x184(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1fe7d5_001fe92b\n"
        ".Lf1fe7d5_001fe800:\n"
        "movl 0x19c(%edx), %eax\n" /* line 959 */
        "cmpb $0, 0xc(%eax)\n"
        "jne .Lf1fe7d5_001fecba\n"
        /* { scope 1 */
        "movl 0x20(%edx), %esi\n" /* line 930 | datasrc */
        "movl (%esi), %edx\n" /* datasrc, next_input_byte */
        "movl 4(%esi), %eax\n" /* datasrc, bytes_in_buffer */
        "testl %eax, %eax\n" /* line 932 */
        "je .Lf1fe7d5_001ff088\n"
        ".Lf1fe7d5_001fe820:\n"
        "movzbl (%edx), %edi\n" /* datasrc */
        "movl %edi, %ecx\n" /* datasrc */
        "movzbl %cl, %ecx\n"
        "movl %ecx, -0x1b8(%ebp)\n" /* c */
        "addl $1, %edx\n"
        "subl $1, %eax\n" /* line 933 */
        "je .Lf1fe7d5_001fecce\n"
        ".Lf1fe7d5_001fe83a:\n"
        "subl $1, %eax\n"
        "movl %eax, -0x15c(%ebp)\n"
        "movzbl (%edx), %eax\n"
        "movzbl %al, %ecx\n"
        "movl %ecx, -0x1b4(%ebp)\n" /* c2 */
        "addl $1, %edx\n"
        "movl %edx, -0x160(%ebp)\n"
        "movl %edi, %edx\n" /* line 934 | datasrc */
        "addb $1, %dl\n"
        "je .Lf1fe7d5_001fecec\n"
        ".Lf1fe7d5_001fe863:\n"
        "movl 8(%ebp), %ecx\n" /* line 935 | cinfo */
        "movl (%ecx), %eax\n"
        "movl $0x35, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl -0x1b8(%ebp), %edx\n" /* c */
        "movl %edx, 0x18(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl -0x1b4(%ebp), %ecx\n" /* c2 */
        "movl %ecx, 0x1c(%eax)\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf1fe7d5_001fe88f:\n"
        "movl -0x1b4(%ebp), %eax\n" /* line 937 | c2 */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %eax, 0x184(%ecx)\n"
        "movl -0x160(%ebp), %edx\n" /* line 939 */
        "movl %edx, (%esi)\n" /* datasrc */
        "movl -0x15c(%ebp), %ecx\n"
        "movl %ecx, 4(%esi)\n" /* datasrc */
        "movl 8(%ebp), %esi\n" /* cinfo, datasrc */
        /* } scope */
        ".Lf1fe7d5_001fe8b2:\n"
        "movl 0x184(%esi), %edx\n" /* line 971 | datasrc */
        "cmpl $0xcf, %edx\n"
        "jg .Lf1fe7d5_001fe93b\n"
        ".Lf1fe7d5_001fe8c0:\n"
        "cmpl $0xcd, %edx\n"
        "jge .Lf1fe7d5_001fe8ec\n"
        "cmpl $0xc4, %edx\n"
        "je .Lf1fe7d5_001ff185\n"
        "jle .Lf1fe7d5_001fee1c\n"
        "cmpl $0xc9, %edx\n"
        "je .Lf1fe7d5_001ff763\n"
        "jge .Lf1fe7d5_001ff3ef\n"
        ".Lf1fe7d5_001fe8ec:\n"
        "movl 8(%ebp), %edx\n" /* line 1008 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x3c, 0x14(%eax)\n"
        ".Lf1fe7d5_001fe8f8:\n"
        "movl 8(%ebp), %ecx\n" /* line 1091 | cinfo */
        "movl (%ecx), %edx\n"
        "movl 0x184(%ecx), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf1fe7d5_001fe90d:\n"
        "movl 8(%ebp), %esi\n" /* line 1095 | cinfo, datasrc */
        "movl $0, 0x184(%esi)\n" /* datasrc */
        "movl 8(%ebp), %edx\n" /* line 958 | cinfo */
        "movl 0x184(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1fe7d5_001fe800\n"
        ".Lf1fe7d5_001fe92b:\n"
        "movl %edx, %esi\n" /* datasrc */
        "movl 0x184(%esi), %edx\n" /* line 971 | datasrc */
        "cmpl $0xcf, %edx\n"
        "jle .Lf1fe7d5_001fe8c0\n"
        ".Lf1fe7d5_001fe93b:\n"
        "cmpl $0xdb, %edx\n"
        "je .Lf1fe7d5_001fee45\n"
        "jg .Lf1fe7d5_001fec95\n"
        "cmpl $0xd8, %edx\n"
        "je .Lf1fe7d5_001ff312\n"
        "jl .Lf1fe7d5_001ff2e3\n"
        "cmpl $0xd9, %edx\n"
        "je .Lf1fe7d5_001ff468\n"
        "cmpl $0xda, %edx\n"
        "jne .Lf1fe7d5_001feca9\n"
        /* { scope 1 */
        "movl 8(%ebp), %esi\n" /* line 307 | cinfo, bytes_in_buffer */
        "movl 0x20(%esi), %esi\n" /* bytes_in_buffer */
        "movl %esi, -0x19c(%ebp)\n" /* bytes_in_buffer, datasrc */
        "movl (%esi), %edi\n" /* bytes_in_buffer, next_input_byte */
        "movl 4(%esi), %esi\n" /* bytes_in_buffer */
        "movl 8(%ebp), %edx\n" /* line 309 | cinfo */
        "movl 0x19c(%edx), %eax\n"
        "cmpb $0, 0xd(%eax)\n"
        "je .Lf1fe7d5_001ff8f4\n"
        ".Lf1fe7d5_001fe99b:\n"
        "testl %esi, %esi\n" /* line 312 | bytes_in_buffer */
        "je .Lf1fe7d5_001ff8cd\n"
        ".Lf1fe7d5_001fe9a3:\n"
        "movzbl (%edi), %edx\n" /* next_input_byte */
        "shll $8, %edx\n"
        "movl %edx, -0x1ac(%ebp)\n" /* length */
        "leal 1(%edi), %ecx\n" /* next_input_byte */
        "movl %esi, %edx\n" /* bytes_in_buffer */
        "subl $1, %edx\n"
        "je .Lf1fe7d5_001ff909\n"
        ".Lf1fe7d5_001fe9bd:\n"
        "movzbl (%ecx), %eax\n"
        "movl -0x1ac(%ebp), %esi\n" /* length, bytes_in_buffer */
        "addl %eax, %esi\n" /* bytes_in_buffer */
        "leal 1(%ecx), %eax\n"
        "subl $1, %edx\n" /* line 314 */
        "jne .Lf1fe7d5_001fe9f2\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "movl -0x19c(%ebp), %edx\n" /* datasrc */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "je .Lf1fe7d5_001fecdf\n"
        "movl -0x19c(%ebp), %ecx\n" /* datasrc */
        "movl (%ecx), %eax\n"
        "movl 4(%ecx), %edx\n"
        ".Lf1fe7d5_001fe9f2:\n"
        "subl $1, %edx\n"
        "movl %edx, -0x154(%ebp)\n"
        "movzbl (%eax), %edx\n"
        "movl %edx, -0x1a4(%ebp)\n" /* n */
        "addl $1, %eax\n"
        "movl %eax, -0x158(%ebp)\n"
        "movl 8(%ebp), %ecx\n" /* line 316 | cinfo */
        "movl (%ecx), %eax\n"
        "movl $0x67, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %edx, 0x18(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl $1, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *4(%eax)\n"
        "movl -0x1a4(%ebp), %edx\n" /* line 318 | n */
        "leal 6(%edx, %edx), %eax\n"
        "cmpl %eax, %esi\n" /* bytes_in_buffer */
        "jne .Lf1fe7d5_001fea45\n"
        "testl %edx, %edx\n"
        "jle .Lf1fe7d5_001fea45\n"
        "cmpl $4, %edx\n"
        "jle .Lf1fe7d5_001fea58\n"
        ".Lf1fe7d5_001fea45:\n"
        "movl 8(%ebp), %ecx\n" /* line 319 | cinfo */
        "movl (%ecx), %eax\n"
        "movl $0xb, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf1fe7d5_001fea58:\n"
        "movl -0x1a4(%ebp), %eax\n" /* line 321 | n */
        "movl 8(%ebp), %esi\n" /* cinfo, bytes_in_buffer */
        "movl %eax, 0x12c(%esi)\n" /* bytes_in_buffer */
        "testl %eax, %eax\n" /* line 325 */
        "jle .Lf1fe7d5_001feb8d\n"
        "movl %esi, -0x16c(%ebp)\n" /* bytes_in_buffer */
        "movl $0, -0x1a8(%ebp)\n" /* i */
        ".Lf1fe7d5_001fea7f:\n"
        "movl -0x154(%ebp), %eax\n" /* line 326 */
        "testl %eax, %eax\n"
        "je .Lf1fe7d5_001ff853\n"
        "movl -0x158(%ebp), %edx\n"
        "movl -0x158(%ebp), %eax\n"
        ".Lf1fe7d5_001fea99:\n"
        "movzbl (%edx), %edx\n"
        "movl %edx, -0x1a0(%ebp)\n" /* cc */
        "addl $1, %eax\n"
        "movl -0x154(%ebp), %edx\n" /* line 327 */
        "subl $1, %edx\n"
        "je .Lf1fe7d5_001ff890\n"
        ".Lf1fe7d5_001feab4:\n"
        "subl $1, %edx\n"
        "movl %edx, -0x154(%ebp)\n"
        "movzbl (%eax), %edi\n" /* next_input_byte */
        "addl $1, %eax\n"
        "movl %eax, -0x158(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* line 329 | cinfo */
        "movl 0xcc(%eax), %esi\n" /* bytes_in_buffer */
        "movl 0x2c(%eax), %edx\n"
        "movl %edx, -0x1b0(%ebp)\n"
        "testl %edx, %edx\n"
        "jle .Lf1fe7d5_001ff831\n"
        "movl -0x1a0(%ebp), %ecx\n" /* line 331 | cc */
        "cmpl %ecx, (%esi)\n" /* bytes_in_buffer */
        "je .Lf1fe7d5_001feb1a\n"
        "leal 0x54(%esi), %eax\n" /* line 332 | bytes_in_buffer */
        "movl %eax, %edx\n"
        "movl $1, %ecx\n"
        "jmp .Lf1fe7d5_001feafc\n"
        ".Lf1fe7d5_001feaf9:\n"
        "leal 0x54(%esi), %eax\n" /* bytes_in_buffer */
        ".Lf1fe7d5_001feafc:\n"
        "movl %eax, %esi\n" /* line 330 | bytes_in_buffer */
        "cmpl %ecx, -0x1b0(%ebp)\n" /* line 329 */
        "je .Lf1fe7d5_001ff8c5\n"
        "movl (%edx), %eax\n" /* line 331 */
        "addl $1, %ecx\n"
        "addl $0x54, %edx\n"
        "cmpl -0x1a0(%ebp), %eax\n" /* cc */
        "jne .Lf1fe7d5_001feaf9\n"
        ".Lf1fe7d5_001feb1a:\n"
        "movl -0x16c(%ebp), %eax\n" /* line 339 */
        "movl %esi, 0x130(%eax)\n" /* bytes_in_buffer */
        "movl %edi, %eax\n" /* line 340 | next_input_byte */
        "shrl $4, %eax\n"
        "movl %eax, 0x14(%esi)\n" /* bytes_in_buffer */
        "andl $0xf, %edi\n" /* line 341 | next_input_byte */
        "movl %edi, 0x18(%esi)\n" /* next_input_byte, bytes_in_buffer */
        /* { scope 2 */
        "movl 8(%ebp), %edx\n" /* line 343 | cinfo, _mp */
        "movl (%edx), %eax\n"
        "leal 0x18(%eax), %edx\n" /* _mp */
        "movl -0x1a0(%ebp), %ecx\n" /* cc */
        "movl %ecx, 0x18(%eax)\n"
        "movl 0x14(%esi), %eax\n" /* bytes_in_buffer */
        "movl %eax, 4(%edx)\n"
        "movl 0x18(%esi), %eax\n" /* bytes_in_buffer */
        "movl %eax, 8(%edx)\n"
        "movl 8(%ebp), %esi\n" /* cinfo, bytes_in_buffer */
        "movl (%esi), %eax\n" /* bytes_in_buffer */
        "movl $0x68, 0x14(%eax)\n"
        "movl (%esi), %eax\n" /* bytes_in_buffer */
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* bytes_in_buffer */
        "calll *4(%eax)\n"
        /* } scope */
        "addl $1, -0x1a8(%ebp)\n" /* line 325 | i */
        "addl $4, -0x16c(%ebp)\n"
        "movl -0x1a8(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x1a4(%ebp)\n" /* n */
        "jne .Lf1fe7d5_001fea7f\n"
        ".Lf1fe7d5_001feb8d:\n"
        "movl -0x154(%ebp), %eax\n" /* line 348 */
        "testl %eax, %eax\n"
        "je .Lf1fe7d5_001ff9a2\n"
        ".Lf1fe7d5_001feb9b:\n"
        "movl -0x158(%ebp), %ecx\n"
        "addl $1, %ecx\n"
        "movl -0x158(%ebp), %edx\n" /* line 349 */
        "movzbl (%edx), %eax\n"
        "movl 8(%ebp), %esi\n" /* cinfo, bytes_in_buffer */
        "movl %eax, 0x174(%esi)\n" /* bytes_in_buffer */
        "movl -0x154(%ebp), %edx\n" /* line 350 */
        "subl $1, %edx\n"
        "je .Lf1fe7d5_001ff95d\n"
        ".Lf1fe7d5_001febc5:\n"
        "leal 1(%ecx), %esi\n" /* bytes_in_buffer */
        "movzbl (%ecx), %eax\n" /* line 351 */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %eax, 0x178(%ecx)\n"
        "movl %edx, %edi\n" /* line 352 | next_input_byte */
        "subl $1, %edi\n" /* next_input_byte */
        "jne .Lf1fe7d5_001febfa\n"
        "movl %ecx, (%esp)\n"
        "movl -0x19c(%ebp), %esi\n" /* datasrc, bytes_in_buffer */
        "calll *0xc(%esi)\n" /* bytes_in_buffer */
        "testb %al, %al\n"
        "je .Lf1fe7d5_001fecdf\n"
        "movl -0x19c(%ebp), %eax\n" /* datasrc */
        "movl (%eax), %esi\n" /* bytes_in_buffer */
        "movl 4(%eax), %edi\n" /* next_input_byte */
        ".Lf1fe7d5_001febfa:\n"
        "movzbl (%esi), %eax\n" /* bytes_in_buffer */
        "movl %eax, %edx\n" /* line 353 */
        "shrl $4, %edx\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %edx, 0x17c(%ecx)\n"
        "andl $0xf, %eax\n" /* line 354 */
        "movl %eax, 0x180(%ecx)\n"
        /* { scope 2 */
        "movl (%ecx), %edx\n" /* line 356 */
        "leal 0x18(%edx), %ecx\n" /* _mp */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 0x174(%eax), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 0x178(%edx), %eax\n"
        "movl %eax, 4(%ecx)\n"
        "movl 0x17c(%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movl 0x180(%edx), %eax\n"
        "movl %eax, 0xc(%ecx)\n"
        "movl (%edx), %eax\n"
        "movl $0x69, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        /* } scope */
        "movl 8(%ebp), %ecx\n" /* line 360 | cinfo */
        "movl 0x19c(%ecx), %eax\n"
        "movl $0, 0x10(%eax)\n"
        "addl $1, 0x84(%ecx)\n" /* line 363 */
        "leal 1(%esi), %eax\n" /* line 365 | bytes_in_buffer */
        "movl -0x19c(%ebp), %esi\n" /* datasrc, bytes_in_buffer */
        "movl %eax, (%esi)\n" /* bytes_in_buffer */
        "leal -1(%edi), %eax\n" /* next_input_byte */
        "movl %eax, 4(%esi)\n" /* bytes_in_buffer */
        /* } scope */
        "movl $0, 0x184(%ecx)\n" /* line 1014 */
        "movl $1, %eax\n"
        "jmp .Lf1fe7d5_001fece1\n"
        ".Lf1fe7d5_001fec95:\n"
        "cmpl $0xef, %edx\n" /* line 971 */
        "jle .Lf1fe7d5_001fecf9\n"
        "cmpl $0xfe, %edx\n"
        "je .Lf1fe7d5_001ff77f\n"
        ".Lf1fe7d5_001feca9:\n"
        "movl 8(%ebp), %edx\n" /* line 1091 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x44, 0x14(%eax)\n"
        "jmp .Lf1fe7d5_001fe8f8\n"
        ".Lf1fe7d5_001fecba:\n"
        "movl 8(%ebp), %eax\n" /* line 963 | cinfo */
        "calll next_marker\n"
        "testb %al, %al\n"
        "je .Lf1fe7d5_001fecdf\n"
        "movl 8(%ebp), %esi\n" /* cinfo, datasrc */
        "jmp .Lf1fe7d5_001fe8b2\n"
        /* { scope 1 */
        ".Lf1fe7d5_001fecce:\n"
        "movl 8(%ebp), %eax\n" /* line 933 | cinfo */
        "movl %eax, (%esp)\n"
        "calll *0xc(%esi)\n" /* datasrc */
        "testb %al, %al\n"
        "jne .Lf1fe7d5_001ff3c5\n"
        /* } scope */
        ".Lf1fe7d5_001fecdf:\n"
        "xorl %eax, %eax\n" /* line 1096 */
        ".Lf1fe7d5_001fece1:\n"
        "addl $0x1dc, %esp\n" /* line 1097 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1fe7d5_001fecec:\n"
        "cmpb $0xd8, %al\n" /* line 934 */
        "jne .Lf1fe7d5_001fe863\n"
        "jmp .Lf1fe7d5_001fe88f\n"
        /* } scope */
        ".Lf1fe7d5_001fecf9:\n"
        "cmpl $0xe0, %edx\n" /* line 971 */
        "jge .Lf1fe7d5_001ff3cf\n"
        "cmpl $0xdc, %edx\n"
        "je .Lf1fe7d5_001ff49b\n"
        "cmpl $0xdd, %edx\n"
        "jne .Lf1fe7d5_001feca9\n"
        /* { scope 1 */
        "movl 8(%ebp), %ecx\n" /* line 553 | cinfo */
        "movl 0x20(%ecx), %edi\n" /* datasrc */
        "movl (%edi), %edx\n" /* datasrc, next_input_byte */
        "movl 4(%edi), %eax\n" /* datasrc, bytes_in_buffer */
        "testl %eax, %eax\n" /* line 555 */
        "je .Lf1fe7d5_001ff945\n"
        ".Lf1fe7d5_001fed2c:\n"
        "movzbl (%edx), %esi\n" /* htblptr */
        "shll $8, %esi\n" /* htblptr */
        "movl %esi, -0x178(%ebp)\n" /* htblptr, length */
        "addl $1, %edx\n"
        "subl $1, %eax\n"
        "je .Lf1fe7d5_001ff92a\n"
        ".Lf1fe7d5_001fed44:\n"
        "leal -1(%eax), %esi\n" /* htblptr */
        "leal 1(%edx), %ecx\n"
        "movl %ecx, -0x144(%ebp)\n"
        "movzbl (%edx), %eax\n" /* line 557 */
        "addl -0x178(%ebp), %eax\n" /* length */
        "cmpl $4, %eax\n"
        "je .Lf1fe7d5_001fed71\n"
        "movl 8(%ebp), %edx\n" /* line 558 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0xb, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf1fe7d5_001fed71:\n"
        "testl %esi, %esi\n" /* line 560 | htblptr */
        "je .Lf1fe7d5_001ff981\n"
        ".Lf1fe7d5_001fed79:\n"
        "movl -0x144(%ebp), %eax\n"
        "movzbl (%eax), %eax\n"
        "shll $8, %eax\n"
        "movl %eax, -0x174(%ebp)\n" /* tmp */
        "movl -0x144(%ebp), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, -0x140(%ebp)\n"
        "subl $1, %esi\n" /* htblptr */
        "movl %esi, -0x13c(%ebp)\n" /* htblptr */
        "jne .Lf1fe7d5_001fedc7\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %ecx, (%esp)\n"
        "calll *0xc(%edi)\n" /* datasrc */
        "testb %al, %al\n"
        "je .Lf1fe7d5_001fecdf\n"
        "movl (%edi), %esi\n" /* datasrc, htblptr */
        "movl %esi, -0x140(%ebp)\n" /* htblptr */
        "movl 4(%edi), %eax\n" /* datasrc */
        "movl %eax, -0x13c(%ebp)\n"
        ".Lf1fe7d5_001fedc7:\n"
        "movl -0x140(%ebp), %edx\n"
        "movzbl (%edx), %esi\n" /* htblptr */
        "addl -0x174(%ebp), %esi\n" /* tmp, htblptr */
        "movl 8(%ebp), %ecx\n" /* line 562 | cinfo */
        "movl (%ecx), %eax\n"
        "movl $0x52, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %esi, 0x18(%eax)\n" /* htblptr */
        "movl (%ecx), %eax\n"
        "movl $1, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *4(%eax)\n"
        "movl 8(%ebp), %eax\n" /* line 564 | cinfo */
        "movl %esi, 0x104(%eax)\n" /* htblptr */
        "movl -0x140(%ebp), %eax\n" /* line 566 */
        "addl $1, %eax\n"
        "movl %eax, (%edi)\n" /* datasrc */
        "movl -0x13c(%ebp), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 4(%edi)\n" /* datasrc */
        "jmp .Lf1fe7d5_001fe90d\n"
        /* } scope */
        ".Lf1fe7d5_001fee1c:\n"
        "cmpl $0xc1, %edx\n" /* line 971 */
        "jle .Lf1fe7d5_001ff2ce\n"
        "cmpl $0xc2, %edx\n"
        "je .Lf1fe7d5_001ff7fa\n"
        "cmpl $0xc3, %edx\n"
        "jne .Lf1fe7d5_001feca9\n"
        "jmp .Lf1fe7d5_001fe8ec\n"
        /* { scope 1 */
        ".Lf1fe7d5_001fee45:\n"
        "movl 8(%ebp), %eax\n" /* line 497 | cinfo, bytes_in_buffer */
        "movl 0x20(%eax), %eax\n" /* bytes_in_buffer */
        "movl %eax, -0x17c(%ebp)\n" /* bytes_in_buffer, datasrc */
        "movl (%eax), %edx\n" /* next_input_byte */
        "movl %eax, %ecx\n" /* bytes_in_buffer */
        "movl 4(%eax), %eax\n" /* bytes_in_buffer */
        "testl %eax, %eax\n" /* line 499 */
        "je .Lf1fe7d5_001ff6fb\n"
        ".Lf1fe7d5_001fee60:\n"
        "movzbl (%edx), %esi\n" /* htblptr */
        "shll $8, %esi\n" /* htblptr */
        "addl $1, %edx\n"
        "subl $1, %eax\n"
        "je .Lf1fe7d5_001ff727\n"
        ".Lf1fe7d5_001fee72:\n"
        "leal -1(%eax), %edi\n" /* next_input_byte */
        "movzbl (%edx), %eax\n"
        "addl $1, %edx\n"
        "movl %edx, -0x164(%ebp)\n"
        "leal -2(%esi, %eax), %eax\n" /* line 500 | htblptr */
        "movl %eax, -0x148(%ebp)\n"
        "testl %eax, %eax\n" /* line 502 */
        "jle .Lf1fe7d5_001ff156\n"
        ".Lf1fe7d5_001fee93:\n"
        "movl %eax, -0x188(%ebp)\n" /* length */
        "testl %edi, %edi\n" /* line 503 | next_input_byte */
        "jne .Lf1fe7d5_001ff17a\n"
        "movl 8(%ebp), %esi\n" /* cinfo, htblptr */
        "movl %esi, (%esp)\n" /* htblptr */
        "movl -0x17c(%ebp), %edx\n" /* datasrc */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "je .Lf1fe7d5_001fecdf\n"
        "movl -0x17c(%ebp), %ecx\n" /* datasrc */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x164(%ebp)\n"
        "movl -0x17c(%ebp), %esi\n" /* datasrc, htblptr */
        "movl 4(%esi), %edi\n" /* htblptr, next_input_byte */
        "movl %ecx, %edx\n"
        ".Lf1fe7d5_001feed1:\n"
        "subl $1, %edi\n" /* next_input_byte */
        "movzbl (%edx), %eax\n"
        "addl $1, %edx\n"
        "movl %edx, -0x164(%ebp)\n"
        "movl %eax, %ecx\n" /* line 504 */
        "sarl $4, %ecx\n"
        "movl %ecx, -0x184(%ebp)\n" /* prec */
        "movl %eax, %esi\n" /* line 505 | htblptr */
        "andl $0xf, %esi\n" /* htblptr */
        "movl 8(%ebp), %edx\n" /* line 507 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x51, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %esi, 0x18(%eax)\n" /* htblptr */
        "movl (%edx), %eax\n"
        "movl %ecx, 0x1c(%eax)\n"
        "movl (%edx), %eax\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        "cmpl $3, %esi\n" /* line 509 | htblptr */
        "jg .Lf1fe7d5_001ff6de\n"
        ".Lf1fe7d5_001fef1f:\n"
        "movl 8(%ebp), %eax\n" /* line 512 | cinfo */
        "movl 0x98(%eax, %esi, 4), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1fe7d5_001ff7e0\n"
        "movl %eax, %ecx\n"
        ".Lf1fe7d5_001fef33:\n"
        "movl 0x98(%ecx, %esi, 4), %esi\n" /* line 514 | htblptr */
        "movl %esi, -0x180(%ebp)\n" /* htblptr, quant_ptr */
        "movl 0x17611e2(%ebx), %esi\n" /* htblptr */
        "movl %esi, -0x168(%ebp)\n" /* htblptr */
        "movl %esi, %edx\n" /* htblptr */
        "jmp .Lf1fe7d5_001fefb7\n"
        ".Lf1fe7d5_001fef50:\n"
        "testl %edi, %edi\n" /* line 518 | next_input_byte */
        "je .Lf1fe7d5_001fefe0\n"
        "movl -0x164(%ebp), %eax\n"
        "movzbl (%eax), %esi\n" /* htblptr */
        "shll $8, %esi\n" /* htblptr */
        "movl %eax, %edx\n"
        "addl $1, %edx\n"
        "movl %edi, %eax\n" /* next_input_byte */
        "subl $1, %eax\n"
        "je .Lf1fe7d5_001ff026\n"
        ".Lf1fe7d5_001fef74:\n"
        "leal -1(%eax), %edi\n" /* next_input_byte */
        "movzbl (%edx), %eax\n"
        "leal (%esi, %eax), %ecx\n" /* htblptr */
        "addl $1, %edx\n"
        "movl %edx, -0x164(%ebp)\n"
        "movl 0x17611e2(%ebx), %edx\n"
        ".Lf1fe7d5_001fef8c:\n"
        "movl -0x168(%ebp), %esi\n" /* line 522 | htblptr */
        "movl (%esi), %eax\n" /* htblptr */
        "movl -0x180(%ebp), %esi\n" /* quant_ptr, htblptr */
        "movw %cx, (%esi, %eax, 2)\n" /* htblptr */
        "addl $4, -0x168(%ebp)\n"
        "leal 0x100(%edx), %eax\n" /* line 953 */
        "cmpl -0x168(%ebp), %eax\n" /* line 516 */
        "je .Lf1fe7d5_001ff0a3\n"
        ".Lf1fe7d5_001fefb7:\n"
        "movl -0x184(%ebp), %ecx\n" /* line 517 | prec */
        "testl %ecx, %ecx\n"
        "jne .Lf1fe7d5_001fef50\n"
        "testl %edi, %edi\n" /* line 520 | next_input_byte */
        "je .Lf1fe7d5_001ff04d\n"
        "movl -0x164(%ebp), %eax\n"
        ".Lf1fe7d5_001fefcf:\n"
        "subl $1, %edi\n" /* next_input_byte */
        "movzbl (%eax), %ecx\n"
        "addl $1, %eax\n"
        "movl %eax, -0x164(%ebp)\n"
        "jmp .Lf1fe7d5_001fef8c\n"
        ".Lf1fe7d5_001fefe0:\n"
        "movl 8(%ebp), %eax\n" /* line 518 | cinfo */
        "movl %eax, (%esp)\n"
        "movl -0x17c(%ebp), %edx\n" /* datasrc */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "je .Lf1fe7d5_001fecdf\n"
        "movl -0x17c(%ebp), %ecx\n" /* datasrc */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x164(%ebp)\n"
        "movl -0x17c(%ebp), %esi\n" /* datasrc, htblptr */
        "movl 4(%esi), %edi\n" /* htblptr, next_input_byte */
        "movl %ecx, %eax\n"
        "movzbl (%eax), %esi\n" /* htblptr */
        "shll $8, %esi\n" /* htblptr */
        "movl %eax, %edx\n"
        "addl $1, %edx\n"
        "movl %edi, %eax\n" /* next_input_byte */
        "subl $1, %eax\n"
        "jne .Lf1fe7d5_001fef74\n"
        ".Lf1fe7d5_001ff026:\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl %edx, (%esp)\n"
        "movl -0x17c(%ebp), %ecx\n" /* datasrc */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf1fe7d5_001fecdf\n"
        "movl -0x17c(%ebp), %eax\n" /* datasrc */
        "movl (%eax), %edx\n"
        "movl 4(%eax), %eax\n"
        "jmp .Lf1fe7d5_001fef74\n"
        ".Lf1fe7d5_001ff04d:\n"
        "movl 8(%ebp), %esi\n" /* line 520 | cinfo, htblptr */
        "movl %esi, (%esp)\n" /* htblptr */
        "movl -0x17c(%ebp), %edx\n" /* datasrc */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "je .Lf1fe7d5_001fecdf\n"
        "movl -0x17c(%ebp), %ecx\n" /* datasrc */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x164(%ebp)\n"
        "movl -0x17c(%ebp), %esi\n" /* datasrc, htblptr */
        "movl 4(%esi), %edi\n" /* htblptr, next_input_byte */
        "movl 0x17611e2(%ebx), %edx\n"
        "movl %ecx, %eax\n"
        "jmp .Lf1fe7d5_001fefcf\n"
        /* } scope */
        /* { scope 1 */
        ".Lf1fe7d5_001ff088:\n"
        "movl 8(%ebp), %ecx\n" /* line 932 | cinfo */
        "movl %ecx, (%esp)\n"
        "calll *0xc(%esi)\n" /* datasrc */
        "testb %al, %al\n"
        "je .Lf1fe7d5_001fecdf\n"
        "movl (%esi), %edx\n" /* datasrc */
        "movl 4(%esi), %eax\n" /* datasrc */
        "jmp .Lf1fe7d5_001fe820\n"
        /* } scope */
        /* { scope 1 */
        ".Lf1fe7d5_001ff0a3:\n"
        "movl 8(%ebp), %eax\n" /* line 525 | cinfo */
        "movl (%eax), %ecx\n"
        "cmpl $1, 0x68(%ecx)\n"
        "jle .Lf1fe7d5_001ff127\n"
        "movl -0x180(%ebp), %esi\n" /* quant_ptr, htblptr */
        "movl $8, -0x170(%ebp)\n"
        "jmp .Lf1fe7d5_001ff0c5\n"
        ".Lf1fe7d5_001ff0c0:\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl (%edx), %ecx\n"
        /* { scope 2 */
        ".Lf1fe7d5_001ff0c5:\n"
        "leal 0x18(%ecx), %edx\n" /* line 527 | _mp */
        "movzwl (%esi), %eax\n" /* htblptr */
        "movl %eax, 0x18(%ecx)\n"
        "movzwl 2(%esi), %eax\n" /* htblptr */
        "movl %eax, 4(%edx)\n"
        "movzwl 4(%esi), %eax\n" /* htblptr */
        "movl %eax, 8(%edx)\n"
        "movzwl 6(%esi), %eax\n" /* htblptr */
        "movl %eax, 0xc(%edx)\n"
        "movzwl 8(%esi), %eax\n" /* htblptr */
        "movl %eax, 0x10(%edx)\n"
        "movzwl 0xa(%esi), %eax\n" /* htblptr */
        "movl %eax, 0x14(%edx)\n"
        "movzwl 0xc(%esi), %eax\n" /* htblptr */
        "movl %eax, 0x18(%edx)\n"
        "movzwl 0xe(%esi), %eax\n" /* htblptr */
        "movl %eax, 0x1c(%edx)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl (%ecx), %eax\n"
        "movl $0x5d, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl $2, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *4(%eax)\n"
        "addl $0x10, %esi\n" /* htblptr */
        /* } scope */
        "subl $1, -0x170(%ebp)\n" /* line 526 */
        "jne .Lf1fe7d5_001ff0c0\n"
        ".Lf1fe7d5_001ff127:\n"
        "subl $0x41, -0x148(%ebp)\n" /* line 535 */
        "movl -0x188(%ebp), %eax\n" /* line 536 | length */
        "subl $0x81, %eax\n"
        "movl -0x184(%ebp), %edx\n" /* prec */
        "testl %edx, %edx\n"
        "cmovel -0x148(%ebp), %eax\n"
        "movl %eax, -0x148(%ebp)\n"
        "testl %eax, %eax\n" /* line 502 */
        "jg .Lf1fe7d5_001fee93\n"
        ".Lf1fe7d5_001ff156:\n"
        "movl -0x148(%ebp), %eax\n" /* line 539 */
        "testl %eax, %eax\n"
        "jne .Lf1fe7d5_001ff819\n"
        ".Lf1fe7d5_001ff164:\n"
        "movl -0x164(%ebp), %edx\n" /* line 542 */
        "movl -0x17c(%ebp), %eax\n" /* datasrc */
        "movl %edx, (%eax)\n"
        "movl %edi, 4(%eax)\n" /* next_input_byte */
        "jmp .Lf1fe7d5_001fe90d\n"
        ".Lf1fe7d5_001ff17a:\n"
        "movl -0x164(%ebp), %edx\n"
        "jmp .Lf1fe7d5_001feed1\n"
        /* } scope */
        /* { scope 1 */
        ".Lf1fe7d5_001ff185:\n"
        "movl 8(%ebp), %eax\n" /* line 427 | cinfo, bytes_in_buffer */
        "movl 0x20(%eax), %eax\n" /* bytes_in_buffer */
        "movl %eax, -0x18c(%ebp)\n" /* bytes_in_buffer, datasrc */
        "movl (%eax), %edx\n" /* next_input_byte */
        "movl %eax, %ecx\n" /* bytes_in_buffer */
        "movl 4(%eax), %eax\n" /* bytes_in_buffer */
        "testl %eax, %eax\n" /* line 429 */
        "je .Lf1fe7d5_001ff420\n"
        ".Lf1fe7d5_001ff1a0:\n"
        "movzbl (%edx), %esi\n" /* htblptr */
        "shll $8, %esi\n" /* htblptr */
        "addl $1, %edx\n"
        "subl $1, %eax\n"
        "je .Lf1fe7d5_001ff441\n"
        ".Lf1fe7d5_001ff1b2:\n"
        "leal -1(%eax), %edi\n" /* next_input_byte */
        "movzbl (%edx), %eax\n"
        "addl $1, %edx\n"
        "movl %edx, -0x150(%ebp)\n"
        "leal -2(%esi, %eax), %eax\n" /* line 430 | htblptr */
        "movl %eax, -0x198(%ebp)\n" /* length */
        "cmpl $0x10, %eax\n" /* line 432 */
        "jle .Lf1fe7d5_001ff6ba\n"
        "leal -0x129(%ebp), %esi\n" /* huffval, htblptr */
        "movl %esi, -0x1c0(%ebp)\n" /* htblptr */
        ".Lf1fe7d5_001ff1e0:\n"
        "testl %edi, %edi\n" /* line 433 | next_input_byte */
        "jne .Lf1fe7d5_001ff71c\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "movl -0x18c(%ebp), %edx\n" /* datasrc */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "je .Lf1fe7d5_001fecdf\n"
        "movl -0x18c(%ebp), %ecx\n" /* datasrc */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x150(%ebp)\n"
        "movl -0x18c(%ebp), %esi\n" /* datasrc, htblptr */
        "movl 4(%esi), %edi\n" /* htblptr, next_input_byte */
        "movl %ecx, %eax\n"
        ".Lf1fe7d5_001ff218:\n"
        "subl $1, %edi\n" /* next_input_byte */
        "movzbl (%eax), %eax\n"
        "movl %eax, -0x194(%ebp)\n" /* index */
        "addl $1, -0x150(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 435 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x50, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl -0x194(%ebp), %ecx\n" /* index */
        "movl %ecx, 0x18(%eax)\n"
        "movl (%edx), %eax\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        "movb $0, -0x29(%ebp)\n" /* line 437 | bits */
        "movl $0, -0x190(%ebp)\n" /* count */
        "xorl %esi, %esi\n" /* htblptr */
        "jmp .Lf1fe7d5_001ff298\n"
        ".Lf1fe7d5_001ff264:\n"
        "movl -0x150(%ebp), %edx\n"
        ".Lf1fe7d5_001ff26a:\n"
        "subl $1, %edi\n" /* line 440 | next_input_byte */
        "movzbl (%edx), %eax\n"
        "movl -0x1c4(%ebp), %ecx\n"
        "movb %al, 1(%ecx, %esi)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x150(%ebp)\n"
        "movzbl %al, %eax\n" /* line 441 */
        "addl %eax, -0x190(%ebp)\n" /* count */
        "addl $1, %esi\n" /* htblptr */
        "cmpl $0x10, %esi\n" /* line 439 | htblptr */
        "je .Lf1fe7d5_001ff4b3\n"
        ".Lf1fe7d5_001ff298:\n"
        "testl %edi, %edi\n" /* line 440 | next_input_byte */
        "jne .Lf1fe7d5_001ff264\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "movl -0x18c(%ebp), %edx\n" /* datasrc */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "je .Lf1fe7d5_001fecdf\n"
        "movl -0x18c(%ebp), %ecx\n" /* datasrc */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x150(%ebp)\n"
        "movl -0x18c(%ebp), %eax\n" /* datasrc */
        "movl 4(%eax), %edi\n" /* next_input_byte */
        "movl %ecx, %edx\n"
        "jmp .Lf1fe7d5_001ff26a\n"
        /* } scope */
        ".Lf1fe7d5_001ff2ce:\n"
        "cmpl $0xc0, %edx\n" /* line 971 */
        "jge .Lf1fe7d5_001ff79b\n"
        "subl $1, %edx\n"
        "jne .Lf1fe7d5_001feca9\n"
        ".Lf1fe7d5_001ff2e3:\n"
        "movl 8(%ebp), %edx\n" /* line 1077 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x5c, 0x14(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl (%ecx), %edx\n"
        "movl 0x184(%ecx), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl (%ecx), %eax\n"
        "movl $1, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *4(%eax)\n"
        "jmp .Lf1fe7d5_001fe90d\n"
        ".Lf1fe7d5_001ff312:\n"
        "movl 8(%ebp), %edx\n" /* line 202 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x66, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        "movl 8(%ebp), %esi\n" /* line 204 | cinfo */
        "movl 0x19c(%esi), %ecx\n"
        "cmpb $0, 0xc(%ecx)\n"
        "jne .Lf1fe7d5_001ff7c2\n"
        "movl %esi, %eax\n"
        ".Lf1fe7d5_001ff343:\n"
        "movl $0x10, %edx\n" /* line 205 */
        ".Lf1fe7d5_001ff348:\n"
        "movb $0, 0xd2(%eax)\n" /* line 210 */
        "movb $1, 0xe2(%eax)\n" /* line 211 */
        "movb $5, 0xf2(%eax)\n" /* line 212 */
        "addl $1, %eax\n"
        "subl $1, %edx\n" /* line 209 */
        "jne .Lf1fe7d5_001ff348\n"
        "movl 8(%ebp), %eax\n" /* line 214 | cinfo */
        "movl $0, 0x104(%eax)\n"
        "movl $0, 0x30(%eax)\n" /* line 218 */
        "movb $0, 0x112(%eax)\n" /* line 219 */
        "movb $0, 0x108(%eax)\n" /* line 221 */
        "movb $1, 0x109(%eax)\n" /* line 222 */
        "movb $1, 0x10a(%eax)\n" /* line 223 */
        "movb $0, 0x10b(%eax)\n" /* line 224 */
        "movw $1, 0x10c(%eax)\n" /* line 225 */
        "movw $1, 0x10e(%eax)\n" /* line 226 */
        "movb $0, 0x110(%eax)\n" /* line 227 */
        "movb $0, 0x111(%eax)\n" /* line 228 */
        "movb $1, 0xc(%ecx)\n" /* line 230 */
        "jmp .Lf1fe7d5_001fe90d\n"
        /* { scope 1 */
        ".Lf1fe7d5_001ff3c5:\n"
        "movl (%esi), %edx\n" /* line 933 | datasrc */
        "movl 4(%esi), %eax\n" /* datasrc */
        "jmp .Lf1fe7d5_001fe83a\n"
        /* } scope */
        ".Lf1fe7d5_001ff3cf:\n"
        "movl 8(%ebp), %ecx\n" /* line 1058 | cinfo */
        "movl 0x19c(%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *-0x364(%eax, %edx, 4)\n"
        "testb %al, %al\n"
        "jne .Lf1fe7d5_001fe90d\n"
        "jmp .Lf1fe7d5_001fecdf\n"
        ".Lf1fe7d5_001ff3ef:\n"
        "cmpl $0xcb, %edx\n" /* line 971 */
        "je .Lf1fe7d5_001fe8ec\n"
        "jg .Lf1fe7d5_001ff49b\n"
        "movl $1, %ecx\n" /* line 994 */
        ".Lf1fe7d5_001ff406:\n"
        "movl $1, %edx\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "calll get_sof\n"
        "testb %al, %al\n"
        "jne .Lf1fe7d5_001fe90d\n"
        "jmp .Lf1fe7d5_001fecdf\n"
        /* { scope 1 */
        ".Lf1fe7d5_001ff420:\n"
        "movl 8(%ebp), %esi\n" /* line 429 | cinfo, htblptr */
        "movl %esi, (%esp)\n" /* htblptr */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf1fe7d5_001fecdf\n"
        "movl -0x18c(%ebp), %eax\n" /* datasrc */
        "movl (%eax), %edx\n"
        "movl 4(%eax), %eax\n"
        "jmp .Lf1fe7d5_001ff1a0\n"
        ".Lf1fe7d5_001ff441:\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "movl -0x18c(%ebp), %edx\n" /* datasrc */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "je .Lf1fe7d5_001fecdf\n"
        "movl -0x18c(%ebp), %ecx\n" /* datasrc */
        "movl (%ecx), %edx\n"
        "movl 4(%ecx), %eax\n"
        "jmp .Lf1fe7d5_001ff1b2\n"
        /* } scope */
        ".Lf1fe7d5_001ff468:\n"
        "movl 8(%ebp), %edx\n" /* line 1018 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x55, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 1019 | cinfo */
        "movl $0, 0x184(%ecx)\n"
        "movl $2, %eax\n"
        "jmp .Lf1fe7d5_001fece1\n"
        ".Lf1fe7d5_001ff49b:\n"
        "movl 8(%ebp), %esi\n" /* line 1081 | cinfo, datasrc */
        "movl %esi, (%esp)\n" /* datasrc */
        "calll skip_variable\n"
        "testb %al, %al\n"
        "jne .Lf1fe7d5_001fe90d\n"
        "jmp .Lf1fe7d5_001fecdf\n"
        /* { scope 1 */
        ".Lf1fe7d5_001ff4b3:\n"
        "movl -0x198(%ebp), %esi\n" /* line 444 | length, htblptr */
        "subl $0x11, %esi\n" /* htblptr */
        "movl %esi, -0x14c(%ebp)\n" /* htblptr */
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 446 | cinfo */
        "movl (%eax), %ecx\n"
        "leal 0x18(%ecx), %edx\n" /* _mp */
        "movzbl -0x28(%ebp), %eax\n"
        "movl %eax, 0x18(%ecx)\n"
        "movzbl -0x27(%ebp), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movzbl -0x26(%ebp), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movzbl -0x25(%ebp), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "movzbl -0x24(%ebp), %eax\n"
        "movl %eax, 0x10(%edx)\n"
        "movzbl -0x23(%ebp), %eax\n"
        "movl %eax, 0x14(%edx)\n"
        "movzbl -0x22(%ebp), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movzbl -0x21(%ebp), %eax\n"
        "movl %eax, 0x1c(%edx)\n"
        "movl 8(%ebp), %edx\n" /* cinfo, _mp */
        "movl (%edx), %eax\n"
        "movl $0x56, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl $2, 4(%esp)\n"
        "movl %edx, (%esp)\n" /* _mp */
        "calll *4(%eax)\n"
        /* } scope */
        /* { scope 2 */
        "movl 8(%ebp), %esi\n" /* line 449 | cinfo, htblptr */
        "movl (%esi), %ecx\n" /* htblptr */
        "leal 0x18(%ecx), %edx\n" /* _mp */
        "movzbl -0x20(%ebp), %eax\n"
        "movl %eax, 0x18(%ecx)\n"
        "movzbl -0x1f(%ebp), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movzbl -0x1e(%ebp), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movzbl -0x1d(%ebp), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "movzbl -0x1c(%ebp), %eax\n"
        "movl %eax, 0x10(%edx)\n"
        "movzbl -0x1b(%ebp), %eax\n"
        "movl %eax, 0x14(%edx)\n"
        "movzbl -0x1a(%ebp), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movzbl -0x19(%ebp), %eax\n"
        "movl %eax, 0x1c(%edx)\n"
        "movl (%esi), %eax\n" /* htblptr */
        "movl $0x56, 0x14(%eax)\n"
        "movl (%esi), %eax\n" /* htblptr */
        "movl $2, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* htblptr */
        "calll *4(%eax)\n"
        /* } scope */
        "cmpl $0x100, -0x190(%ebp)\n" /* line 456 | count */
        "jg .Lf1fe7d5_001ff591\n"
        "movl -0x14c(%ebp), %eax\n"
        "cmpl %eax, -0x190(%ebp)\n" /* count */
        "jle .Lf1fe7d5_001ff5a4\n"
        ".Lf1fe7d5_001ff591:\n"
        "movl 8(%ebp), %edx\n" /* line 457 | cinfo */
        "movl (%edx), %eax\n"
        "movl $8, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf1fe7d5_001ff5a4:\n"
        "movl -0x190(%ebp), %eax\n" /* line 459 | count */
        "testl %eax, %eax\n"
        "jle .Lf1fe7d5_001ff615\n"
        "xorl %esi, %esi\n" /* htblptr */
        "jmp .Lf1fe7d5_001ff5e1\n"
        ".Lf1fe7d5_001ff5b2:\n"
        "movl -0x150(%ebp), %ecx\n"
        ".Lf1fe7d5_001ff5b8:\n"
        "subl $1, %edi\n" /* line 460 | next_input_byte */
        "movl -0x1c0(%ebp), %edx\n"
        "movl %edx, -0x1bc(%ebp)\n"
        "movzbl (%ecx), %eax\n"
        "movb %al, (%esi, %edx)\n" /* htblptr */
        "addl $1, %ecx\n"
        "movl %ecx, -0x150(%ebp)\n"
        "addl $1, %esi\n" /* line 459 | htblptr */
        "cmpl %esi, -0x190(%ebp)\n" /* htblptr, count */
        "je .Lf1fe7d5_001ff621\n"
        ".Lf1fe7d5_001ff5e1:\n"
        "testl %edi, %edi\n" /* line 460 | next_input_byte */
        "jne .Lf1fe7d5_001ff5b2\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %ecx, (%esp)\n"
        "movl -0x18c(%ebp), %edx\n" /* datasrc */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "je .Lf1fe7d5_001fecdf\n"
        "movl -0x18c(%ebp), %ecx\n" /* datasrc */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x150(%ebp)\n"
        "movl -0x18c(%ebp), %eax\n" /* datasrc */
        "movl 4(%eax), %edi\n" /* next_input_byte */
        "jmp .Lf1fe7d5_001ff5b8\n"
        ".Lf1fe7d5_001ff615:\n"
        "leal -0x129(%ebp), %esi\n" /* huffval, htblptr */
        "movl %esi, -0x1bc(%ebp)\n" /* htblptr */
        ".Lf1fe7d5_001ff621:\n"
        "movl -0x14c(%ebp), %eax\n" /* line 462 */
        "subl -0x190(%ebp), %eax\n" /* count */
        "movl %eax, -0x198(%ebp)\n" /* length */
        "testb $0x10, -0x194(%ebp)\n" /* line 464 | index */
        "je .Lf1fe7d5_001ff74e\n"
        "subl $0x10, -0x194(%ebp)\n" /* line 465 | index */
        "movl -0x194(%ebp), %edx\n" /* line 466 | index */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "leal 0xb8(%ecx, %edx, 4), %esi\n" /* htblptr */
        ".Lf1fe7d5_001ff657:\n"
        "cmpl $3, -0x194(%ebp)\n" /* line 471 | index */
        "ja .Lf1fe7d5_001ff79f\n"
        ".Lf1fe7d5_001ff664:\n"
        "movl (%esi), %eax\n" /* line 474 | htblptr */
        "testl %eax, %eax\n"
        "je .Lf1fe7d5_001ff8b1\n"
        "movl (%esi), %edx\n" /* htblptr */
        ".Lf1fe7d5_001ff670:\n"
        "movl -0x29(%ebp), %eax\n" /* line 477 | bits */
        "movl %eax, (%edx)\n"
        "movl -0x25(%ebp), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl -0x21(%ebp), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl -0x1d(%ebp), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "movzbl -0x19(%ebp), %eax\n"
        "movb %al, 0x10(%edx)\n"
        "movl (%esi), %eax\n" /* line 478 | htblptr */
        "addl $0x11, %eax\n"
        "movl $0x100, 8(%esp)\n"
        "movl -0x1bc(%ebp), %esi\n" /* htblptr */
        "movl %esi, 4(%esp)\n" /* htblptr */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "cmpl $0x10, -0x198(%ebp)\n" /* line 432 | length */
        "jg .Lf1fe7d5_001ff1e0\n"
        ".Lf1fe7d5_001ff6ba:\n"
        "movl -0x198(%ebp), %ecx\n" /* line 481 | length */
        "testl %ecx, %ecx\n"
        "jne .Lf1fe7d5_001ff801\n"
        ".Lf1fe7d5_001ff6c8:\n"
        "movl -0x150(%ebp), %esi\n" /* line 484 | htblptr */
        "movl -0x18c(%ebp), %ecx\n" /* datasrc */
        "movl %esi, (%ecx)\n" /* htblptr */
        "movl %edi, 4(%ecx)\n" /* next_input_byte */
        "jmp .Lf1fe7d5_001fe90d\n"
        /* } scope */
        /* { scope 1 */
        ".Lf1fe7d5_001ff6de:\n"
        "movl 8(%ebp), %ecx\n" /* line 510 | cinfo */
        "movl (%ecx), %eax\n"
        "movl $0x1f, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %esi, 0x18(%eax)\n" /* htblptr */
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fe7d5_001fef1f\n"
        ".Lf1fe7d5_001ff6fb:\n"
        "movl 8(%ebp), %esi\n" /* line 499 | cinfo, htblptr */
        "movl %esi, (%esp)\n" /* htblptr */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf1fe7d5_001fecdf\n"
        "movl -0x17c(%ebp), %eax\n" /* datasrc */
        "movl (%eax), %edx\n"
        "movl 4(%eax), %eax\n"
        "jmp .Lf1fe7d5_001fee60\n"
        ".Lf1fe7d5_001ff71c:\n"
        "movl -0x150(%ebp), %eax\n"
        "jmp .Lf1fe7d5_001ff218\n"
        ".Lf1fe7d5_001ff727:\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "movl -0x17c(%ebp), %edx\n" /* datasrc */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "je .Lf1fe7d5_001fecdf\n"
        "movl -0x17c(%ebp), %ecx\n" /* datasrc */
        "movl (%ecx), %edx\n"
        "movl 4(%ecx), %eax\n"
        "jmp .Lf1fe7d5_001fee72\n"
        /* } scope */
        /* { scope 1 */
        ".Lf1fe7d5_001ff74e:\n"
        "movl -0x194(%ebp), %eax\n" /* line 468 | index */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "leal 0xa8(%edx, %eax, 4), %esi\n" /* htblptr */
        "jmp .Lf1fe7d5_001ff657\n"
        /* } scope */
        ".Lf1fe7d5_001ff763:\n"
        "movl $1, %ecx\n" /* line 989 */
        ".Lf1fe7d5_001ff768:\n"
        "xorl %edx, %edx\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "calll get_sof\n"
        "testb %al, %al\n"
        "jne .Lf1fe7d5_001fe90d\n"
        "jmp .Lf1fe7d5_001fecdf\n"
        ".Lf1fe7d5_001ff77f:\n"
        "movl 8(%ebp), %esi\n" /* line 1064 | cinfo, datasrc */
        "movl 0x19c(%esi), %eax\n" /* datasrc */
        "movl %esi, (%esp)\n" /* datasrc */
        "calll *0x18(%eax)\n"
        "testb %al, %al\n"
        "jne .Lf1fe7d5_001fe90d\n"
        "jmp .Lf1fe7d5_001fecdf\n"
        ".Lf1fe7d5_001ff79b:\n"
        "xorl %ecx, %ecx\n" /* line 979 */
        "jmp .Lf1fe7d5_001ff768\n"
        /* { scope 1 */
        ".Lf1fe7d5_001ff79f:\n"
        "movl 8(%ebp), %ecx\n" /* line 472 | cinfo */
        "movl (%ecx), %eax\n"
        "movl $0x1e, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl -0x194(%ebp), %edx\n" /* index */
        "movl %edx, 0x18(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fe7d5_001ff664\n"
        /* } scope */
        ".Lf1fe7d5_001ff7c2:\n"
        "movl (%esi), %eax\n" /* line 205 */
        "movl $0x3d, 0x14(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "movl 0x19c(%esi), %ecx\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "jmp .Lf1fe7d5_001ff343\n"
        /* { scope 1 */
        ".Lf1fe7d5_001ff7e0:\n"
        "movl %eax, (%esp)\n" /* line 513 */
        "calll jpeg_alloc_quant_table\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl %eax, 0x98(%edx, %esi, 4)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "jmp .Lf1fe7d5_001fef33\n"
        /* } scope */
        ".Lf1fe7d5_001ff7fa:\n"
        "xorl %ecx, %ecx\n" /* line 984 */
        "jmp .Lf1fe7d5_001ff406\n"
        /* { scope 1 */
        ".Lf1fe7d5_001ff801:\n"
        "movl 8(%ebp), %edx\n" /* line 482 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0xb, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fe7d5_001ff6c8\n"
        /* } scope */
        /* { scope 1 */
        ".Lf1fe7d5_001ff819:\n"
        "movl 8(%ebp), %esi\n" /* line 540 | cinfo, htblptr */
        "movl (%esi), %eax\n" /* htblptr */
        "movl $0xb, 0x14(%eax)\n"
        "movl (%esi), %eax\n" /* htblptr */
        "movl %esi, (%esp)\n" /* htblptr */
        "calll *(%eax)\n"
        "jmp .Lf1fe7d5_001ff164\n"
        ".Lf1fe7d5_001ff831:\n"
        "movl %eax, %edx\n"
        /* } scope */
        /* { scope 1 */
        ".Lf1fe7d5_001ff833:\n"
        "movl (%edx), %eax\n" /* line 335 */
        "movl $5, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl -0x1a0(%ebp), %ecx\n" /* cc */
        "movl %ecx, 0x18(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fe7d5_001feb1a\n"
        ".Lf1fe7d5_001ff853:\n"
        "movl 8(%ebp), %edx\n" /* line 326 | cinfo */
        "movl %edx, (%esp)\n"
        "movl -0x19c(%ebp), %ecx\n" /* datasrc */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf1fe7d5_001fecdf\n"
        "movl -0x19c(%ebp), %esi\n" /* datasrc, bytes_in_buffer */
        "movl (%esi), %esi\n" /* bytes_in_buffer */
        "movl %esi, -0x158(%ebp)\n" /* bytes_in_buffer */
        "movl -0x19c(%ebp), %eax\n" /* datasrc */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x154(%ebp)\n"
        "movl %esi, %edx\n" /* bytes_in_buffer */
        "movl %esi, %eax\n" /* bytes_in_buffer */
        "jmp .Lf1fe7d5_001fea99\n"
        ".Lf1fe7d5_001ff890:\n"
        "movl 8(%ebp), %ecx\n" /* line 327 | cinfo */
        "movl %ecx, (%esp)\n"
        "movl -0x19c(%ebp), %esi\n" /* datasrc, bytes_in_buffer */
        "calll *0xc(%esi)\n" /* bytes_in_buffer */
        "testb %al, %al\n"
        "je .Lf1fe7d5_001fecdf\n"
        "movl (%esi), %eax\n" /* bytes_in_buffer */
        "movl 4(%esi), %edx\n" /* bytes_in_buffer */
        "jmp .Lf1fe7d5_001feab4\n"
        /* } scope */
        /* { scope 1 */
        ".Lf1fe7d5_001ff8b1:\n"
        "movl 8(%ebp), %ecx\n" /* line 475 | cinfo */
        "movl %ecx, (%esp)\n"
        "calll jpeg_alloc_huff_table\n"
        "movl %eax, (%esi)\n" /* htblptr */
        "movl %eax, %edx\n"
        "jmp .Lf1fe7d5_001ff670\n"
        ".Lf1fe7d5_001ff8c5:\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "jmp .Lf1fe7d5_001ff833\n"
        /* } scope */
        /* { scope 1 */
        ".Lf1fe7d5_001ff8cd:\n"
        "movl 8(%ebp), %ecx\n" /* line 312 | cinfo */
        "movl %ecx, (%esp)\n"
        "movl -0x19c(%ebp), %esi\n" /* datasrc, bytes_in_buffer */
        "calll *0xc(%esi)\n" /* bytes_in_buffer */
        "testb %al, %al\n"
        "je .Lf1fe7d5_001fecdf\n"
        "movl (%esi), %edi\n" /* bytes_in_buffer, next_input_byte */
        "movl -0x19c(%ebp), %eax\n" /* datasrc */
        "movl 4(%eax), %esi\n" /* bytes_in_buffer */
        "jmp .Lf1fe7d5_001fe9a3\n"
        ".Lf1fe7d5_001ff8f4:\n"
        "movl (%edx), %eax\n" /* line 310 */
        "movl $0x3e, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1fe7d5_001fe99b\n"
        ".Lf1fe7d5_001ff909:\n"
        "movl 8(%ebp), %ecx\n" /* line 312 | cinfo */
        "movl %ecx, (%esp)\n"
        "movl -0x19c(%ebp), %esi\n" /* datasrc, bytes_in_buffer */
        "calll *0xc(%esi)\n" /* bytes_in_buffer */
        "testb %al, %al\n"
        "je .Lf1fe7d5_001fecdf\n"
        "movl (%esi), %ecx\n" /* bytes_in_buffer */
        "movl 4(%esi), %edx\n" /* bytes_in_buffer */
        "jmp .Lf1fe7d5_001fe9bd\n"
        /* } scope */
        /* { scope 1 */
        ".Lf1fe7d5_001ff92a:\n"
        "movl 8(%ebp), %eax\n" /* line 555 | cinfo */
        "movl %eax, (%esp)\n"
        "calll *0xc(%edi)\n" /* datasrc */
        "testb %al, %al\n"
        "je .Lf1fe7d5_001fecdf\n"
        "movl (%edi), %edx\n" /* datasrc */
        "movl 4(%edi), %eax\n" /* datasrc */
        "jmp .Lf1fe7d5_001fed44\n"
        ".Lf1fe7d5_001ff945:\n"
        "movl %ecx, (%esp)\n"
        "calll *0xc(%edi)\n" /* datasrc */
        "testb %al, %al\n"
        "je .Lf1fe7d5_001fecdf\n"
        "movl (%edi), %edx\n" /* datasrc */
        "movl 4(%edi), %eax\n" /* datasrc */
        "jmp .Lf1fe7d5_001fed2c\n"
        /* } scope */
        /* { scope 1 */
        ".Lf1fe7d5_001ff95d:\n"
        "movl %esi, (%esp)\n" /* line 350 | bytes_in_buffer */
        "movl -0x19c(%ebp), %edx\n" /* datasrc */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "je .Lf1fe7d5_001fecdf\n"
        "movl -0x19c(%ebp), %esi\n" /* datasrc, bytes_in_buffer */
        "movl (%esi), %ecx\n" /* bytes_in_buffer */
        "movl 4(%esi), %edx\n" /* bytes_in_buffer */
        "jmp .Lf1fe7d5_001febc5\n"
        /* } scope */
        /* { scope 1 */
        ".Lf1fe7d5_001ff981:\n"
        "movl 8(%ebp), %ecx\n" /* line 560 | cinfo */
        "movl %ecx, (%esp)\n"
        "calll *0xc(%edi)\n" /* datasrc */
        "testb %al, %al\n"
        "je .Lf1fe7d5_001fecdf\n"
        "movl (%edi), %esi\n" /* datasrc, htblptr */
        "movl %esi, -0x144(%ebp)\n" /* htblptr */
        "movl 4(%edi), %esi\n" /* datasrc, htblptr */
        "jmp .Lf1fe7d5_001fed79\n"
        /* } scope */
        /* { scope 1 */
        ".Lf1fe7d5_001ff9a2:\n"
        "movl 8(%ebp), %edx\n" /* line 348 | cinfo */
        "movl %edx, (%esp)\n"
        "movl -0x19c(%ebp), %ecx\n" /* datasrc */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf1fe7d5_001fecdf\n"
        "movl -0x19c(%ebp), %esi\n" /* datasrc, bytes_in_buffer */
        "movl (%esi), %esi\n" /* bytes_in_buffer */
        "movl %esi, -0x158(%ebp)\n" /* bytes_in_buffer */
        "movl -0x19c(%ebp), %eax\n" /* datasrc */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x154(%ebp)\n"
        "jmp .Lf1fe7d5_001feb9b\n"
    );
}

/* line 1114 */
static __attribute__((naked))
boolean read_restart_marker(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1114 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 0x184(%esi), %eax\n" /* line 1117 | cinfo */
        "testl %eax, %eax\n"
        "je .Lf1ff9db_001ffa34\n"
        ".Lf1ff9db_001ff9ef:\n"
        "movl 0x19c(%esi), %eax\n" /* line 1122 | cinfo */
        "movl 0x10(%eax), %edx\n"
        "leal 0xd0(%edx), %eax\n"
        "cmpl %eax, 0x184(%esi)\n" /* cinfo */
        "je .Lf1ff9db_001ffa47\n"
        "movl 0x20(%esi), %eax\n" /* line 1130 | cinfo */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *0x14(%eax)\n"
        "testb %al, %al\n"
        "je .Lf1ff9db_001ffa3f\n"
        ".Lf1ff9db_001ffa17:\n"
        "movl 0x19c(%esi), %edx\n" /* line 1136 | cinfo */
        "movl 0x10(%edx), %eax\n"
        "addl $1, %eax\n"
        "andl $7, %eax\n"
        "movl %eax, 0x10(%edx)\n"
        "movl $1, %eax\n"
        "addl $0x14, %esp\n" /* line 1139 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1ff9db_001ffa34:\n"
        "movl %esi, %eax\n" /* line 1118 | cinfo */
        "calll next_marker\n"
        "testb %al, %al\n"
        "jne .Lf1ff9db_001ff9ef\n"
        ".Lf1ff9db_001ffa3f:\n"
        "xorl %eax, %eax\n" /* line 1138 */
        "addl $0x14, %esp\n" /* line 1139 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1ff9db_001ffa47:\n"
        "movl (%esi), %eax\n" /* line 1125 | cinfo */
        "movl $0x62, 0x14(%eax)\n"
        "movl (%esi), %edx\n" /* cinfo */
        "movl 0x19c(%esi), %eax\n" /* cinfo */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl $3, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *4(%eax)\n"
        "movl $0, 0x184(%esi)\n" /* line 1126 | cinfo */
        "jmp .Lf1ff9db_001ffa17\n"
    );
}

/* line 1193 */
__attribute__((naked))
boolean jpeg_resync_to_restart(j_decompress_ptr cinfo, int desired)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 1193 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x20, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* desired */
        "movl 8(%ebp), %eax\n" /* line 1194 | cinfo */
        "movl 0x184(%eax), %edi\n" /* marker */
        "movl %eax, %edx\n" /* line 1198 */
        "movl (%eax), %eax\n"
        "movl $0x79, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edi, 0x18(%eax)\n" /* marker */
        "movl (%edx), %eax\n"
        "movl %esi, 0x1c(%eax)\n" /* action */
        "movl (%edx), %eax\n"
        "movl $0xffffffff, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        "leal 1(%esi), %eax\n" /* action */
        "andl $7, %eax\n"
        "addl $0xd0, %eax\n"
        "movl %eax, -0xc(%ebp)\n"
        "leal 2(%esi), %eax\n" /* action */
        "andl $7, %eax\n"
        "addl $0xd0, %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "leal -1(%esi), %eax\n" /* action */
        "andl $7, %eax\n"
        "addl $0xd0, %eax\n"
        "movl %eax, -0x14(%ebp)\n"
        "subl $2, %esi\n" /* action */
        "andl $7, %esi\n" /* action */
        "addl $0xd0, %esi\n" /* action */
        "movl %esi, -0x18(%ebp)\n" /* action */
        ".Lf1ffa7a_001ffaec:\n"
        "cmpl $0xbf, %edi\n" /* line 1202 | marker */
        "jle .Lf1ffa7a_001ffb6d\n"
        "leal -0xd0(%edi), %eax\n" /* line 1204 | marker */
        "cmpl $7, %eax\n"
        "ja .Lf1ffa7a_001ffb1a\n"
        "cmpl -0xc(%ebp), %edi\n" /* line 1207 | marker */
        "je .Lf1ffa7a_001ffb1a\n"
        "cmpl -0x10(%ebp), %edi\n" /* marker */
        "je .Lf1ffa7a_001ffb1a\n"
        "cmpl -0x14(%ebp), %edi\n" /* line 1210 | marker */
        "je .Lf1ffa7a_001ffb6d\n"
        "cmpl -0x18(%ebp), %edi\n" /* marker */
        "je .Lf1ffa7a_001ffb6d\n"
        "movl $1, %esi\n" /* action */
        "jmp .Lf1ffa7a_001ffb1f\n"
        ".Lf1ffa7a_001ffb1a:\n"
        "movl $3, %esi\n" /* action */
        ".Lf1ffa7a_001ffb1f:\n"
        "movl 8(%ebp), %edx\n" /* line 1216 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x61, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edi, 0x18(%eax)\n" /* marker */
        "movl (%edx), %eax\n"
        "movl %esi, 0x1c(%eax)\n" /* action */
        "movl (%edx), %eax\n"
        "movl $4, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        "cmpl $2, %esi\n" /* line 1217 | action */
        "je .Lf1ffa7a_001ffb74\n"
        "cmpl $3, %esi\n" /* action */
        "je .Lf1ffa7a_001ffb61\n"
        "subl $1, %esi\n" /* action */
        "jne .Lf1ffa7a_001ffaec\n"
        "movl 8(%ebp), %eax\n" /* line 1220 | cinfo */
        "movl $0, 0x184(%eax)\n"
        ".Lf1ffa7a_001ffb61:\n"
        "movl $1, %eax\n"
        ".Lf1ffa7a_001ffb66:\n"
        "addl $0x20, %esp\n" /* line 1234 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1ffa7a_001ffb6d:\n"
        "movl $2, %esi\n" /* line 1210 | action */
        "jmp .Lf1ffa7a_001ffb1f\n"
        ".Lf1ffa7a_001ffb74:\n"
        "movl 8(%ebp), %eax\n" /* line 1224 | cinfo */
        "calll next_marker\n"
        "testb %al, %al\n"
        "je .Lf1ffa7a_001ffb8e\n"
        "movl 8(%ebp), %edx\n" /* line 1226 | cinfo */
        "movl 0x184(%edx), %edi\n" /* marker */
        "jmp .Lf1ffa7a_001ffaec\n"
        ".Lf1ffa7a_001ffb8e:\n"
        "xorl %eax, %eax\n" /* line 1227 */
        "jmp .Lf1ffa7a_001ffb66\n"
    );
}

/* line 1243 */
static __attribute__((naked))
void reset_marker_reader(j_decompress_ptr cinfo, j_decompress_ptr cinfo_1, int marker_code, unsigned int length_limit, j_decompress_ptr cinfo_4, int marker_code_5, jpeg_marker_parser_method routine)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 1243 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 0x19c(%eax), %edx\n" /* line 1244 | marker */
        "movl $0, 0xcc(%eax)\n" /* line 1246 */
        "movl $0, 0x84(%eax)\n" /* line 1247 */
        "movl $0, 0x184(%eax)\n" /* line 1248 */
        "movb $0, 0xc(%edx)\n" /* line 1249 */
        "movb $0, 0xd(%edx)\n" /* line 1250 */
        "movl $0, 0x14(%edx)\n" /* line 1251 */
        "movl $0, 0xa0(%edx)\n" /* line 1252 */
        "popl %ebp\n" /* line 1253 */
        "retl\n"
        /* } scope */
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
    );
}

/* line 1263 */
__attribute__((naked))
void jinit_marker_reader(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1263 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %edi\n" /* cinfo */
        "movl 4(%edi), %eax\n" /* line 1268 | cinfo */
        "movl $0xa8, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "movl %eax, %ecx\n"
        "movl %eax, 0x19c(%edi)\n" /* line 1271 | cinfo */
        "leal -0x53(%ebx), %eax\n" /* line 1273 */
        "movl %eax, (%ecx)\n"
        "leal -0x1410(%ebx), %eax\n" /* line 1274 */
        "movl %eax, 4(%ecx)\n"
        "leal -0x20a(%ebx), %eax\n" /* line 1275 */
        "movl %eax, 8(%ecx)\n"
        "leal -0x1631(%ebx), %esi\n" /* line 1280 */
        "movl %esi, 0x18(%ecx)\n"
        "movl $0, 0x5c(%ecx)\n" /* line 1281 */
        "movl %ecx, %eax\n"
        "movl $0x10, %edx\n"
        ".Lf1ffbd7_001ffc39:\n"
        "movl %esi, 0x1c(%eax)\n" /* line 1283 */
        "movl $0, 0x60(%eax)\n" /* line 1284 */
        "addl $4, %eax\n"
        "subl $1, %edx\n" /* line 1282 */
        "jne .Lf1ffbd7_001ffc39\n"
        "leal -0x18b6(%ebx), %eax\n" /* line 1286 */
        "movl %eax, 0x1c(%ecx)\n"
        "movl %eax, 0x54(%ecx)\n" /* line 1287 */
        /* { scope 1 */
        "movl 0x19c(%edi), %eax\n" /* line 1244 | marker */
        "movl $0, 0xcc(%edi)\n" /* line 1246 */
        "movl $0, 0x84(%edi)\n" /* line 1247 */
        "movl $0, 0x184(%edi)\n" /* line 1248 */
        "movb $0, 0xc(%eax)\n" /* line 1249 */
        "movb $0, 0xd(%eax)\n" /* line 1250 */
        "movl $0, 0x14(%eax)\n" /* line 1251 */
        "movl $0, 0xa0(%eax)\n" /* line 1252 */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1290 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

