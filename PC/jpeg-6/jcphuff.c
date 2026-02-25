/* ASM dump from: jcphuff.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jcphuff.c */

#include "common_types.h"
#include "imports.h"

static void start_pass_phuff(j_compress_ptr cinfo, int gather_statistics);
void jinit_phuff_encoder(j_compress_ptr cinfo);
static void emit_eobrun(void);
static void finish_pass_phuff(j_compress_ptr cinfo);
static void finish_pass_gather_phuff(j_compress_ptr cinfo);
static void emit_restart(int restart_num);
static boolean encode_mcu_AC_refine(j_compress_ptr cinfo, JBLOCKROW *MCU_data);
static boolean encode_mcu_DC_refine(j_compress_ptr cinfo, JBLOCKROW *MCU_data);
static boolean encode_mcu_DC_first(j_compress_ptr cinfo, JBLOCKROW *MCU_data);
static boolean encode_mcu_AC_first(j_compress_ptr cinfo, JBLOCKROW *MCU_data);

/* line 107 */
static __attribute__((naked))
void start_pass_phuff(j_compress_ptr cinfo, int gather_statistics)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 107 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 0xc(%ebp), %eax\n" /* gather_statistics */
        "movb %al, -0x26(%ebp)\n" /* gather_statistics */
        "movl 8(%ebp), %edx\n" /* line 108 | cinfo */
        "movl 0x160(%edx), %edi\n" /* entropy */
        "movl %edx, 0x20(%edi)\n" /* line 113 | entropy */
        "movb %al, 0xc(%edi)\n" /* line 114 | entropy */
        "movl 0x130(%edx), %eax\n" /* line 116 */
        "testl %eax, %eax\n"
        "sete -0x25(%ebp)\n" /* is_DC_band */
        "movl 0x138(%edx), %eax\n" /* line 121 */
        "testl %eax, %eax\n"
        "jne .Lf20ffb0_002100e0\n"
        "cmpb $0, -0x25(%ebp)\n" /* line 122 | is_DC_band */
        "jne .Lf20ffb0_0021017d\n"
        "leal 0x1f79(%ebx), %eax\n" /* line 125 */
        "movl %eax, 4(%edi)\n" /* entropy */
        "cmpb $0, -0x26(%ebp)\n" /* line 138 | gather_statistics */
        "jne .Lf20ffb0_002100f9\n"
        ".Lf20ffb0_0021000a:\n"
        "leal 0x85c(%ebx), %eax\n" /* line 141 */
        "movl %eax, 8(%edi)\n" /* entropy */
        "movl 8(%ebp), %eax\n" /* line 146 | cinfo */
        "movl 0xe8(%eax), %esi\n" /* tbl */
        "testl %esi, %esi\n" /* tbl */
        "jle .Lf20ffb0_00210113\n"
        ".Lf20ffb0_00210024:\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, -0x20(%ebp)\n"
        "movl %edi, -0x1c(%ebp)\n" /* entropy */
        "movl $0, -0x24(%ebp)\n" /* ci */
        "cmpb $0, -0x25(%ebp)\n" /* is_DC_band */
        "jne .Lf20ffb0_002101e2\n"
        "cmpb $0, -0x26(%ebp)\n" /* gather_statistics */
        "je .Lf20ffb0_0021018b\n"
        "movl -0x20(%ebp), %edx\n" /* line 147 */
        "movl 0xec(%edx), %eax\n"
        "movl -0x1c(%ebp), %edx\n" /* line 149 */
        "movl $0, 0x24(%edx)\n"
        "movl 0x18(%eax), %esi\n" /* line 156 | tbl */
        "movl %esi, 0x34(%edi)\n" /* tbl, entropy */
        "cmpl $3, %esi\n" /* line 161 | tbl */
        "ja .Lf20ffb0_002100c6\n"
        ".Lf20ffb0_00210066:\n"
        "movl 0x5c(%edi, %esi, 4), %eax\n" /* line 165 | entropy */
        "testl %eax, %eax\n"
        "je .Lf20ffb0_002102c5\n"
        "movl 0x5c(%edi, %esi, 4), %eax\n" /* entropy */
        ".Lf20ffb0_00210076:\n"
        "movl $0x404, 8(%esp)\n" /* line 169 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "addl $1, -0x24(%ebp)\n" /* line 146 | ci */
        "addl $4, -0x20(%ebp)\n"
        "addl $4, -0x1c(%ebp)\n"
        "movl -0x24(%ebp), %eax\n" /* ci */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "cmpl 0xe8(%edx), %eax\n"
        "jge .Lf20ffb0_00210113\n"
        "movl -0x20(%ebp), %edx\n" /* line 147 */
        "movl 0xec(%edx), %eax\n"
        "movl -0x1c(%ebp), %edx\n" /* line 149 */
        "movl $0, 0x24(%edx)\n"
        "movl 0x18(%eax), %esi\n" /* line 156 | tbl */
        "movl %esi, 0x34(%edi)\n" /* tbl, entropy */
        "cmpl $3, %esi\n" /* line 161 | tbl */
        "jbe .Lf20ffb0_00210066\n"
        ".Lf20ffb0_002100c6:\n"
        "movl 8(%ebp), %edx\n" /* line 162 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x32, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %esi, 0x18(%eax)\n" /* tbl */
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf20ffb0_00210066\n"
        ".Lf20ffb0_002100e0:\n"
        "cmpb $0, -0x25(%ebp)\n" /* line 127 | is_DC_band */
        "je .Lf20ffb0_0021014a\n"
        "leal 0x191c(%ebx), %eax\n" /* line 128 */
        "movl %eax, 4(%edi)\n" /* entropy */
        ".Lf20ffb0_002100ef:\n"
        "cmpb $0, -0x26(%ebp)\n" /* line 138 | gather_statistics */
        "je .Lf20ffb0_0021000a\n"
        ".Lf20ffb0_002100f9:\n"
        "leal 0x9bd(%ebx), %eax\n" /* line 139 */
        "movl %eax, 8(%edi)\n" /* entropy */
        "movl 8(%ebp), %eax\n" /* line 146 | cinfo */
        "movl 0xe8(%eax), %esi\n" /* tbl */
        "testl %esi, %esi\n" /* tbl */
        "jg .Lf20ffb0_00210024\n"
        ".Lf20ffb0_00210113:\n"
        "movl $0, 0x38(%edi)\n" /* line 179 | entropy */
        "movl $0, 0x3c(%edi)\n" /* line 180 | entropy */
        "movl $0, 0x18(%edi)\n" /* line 183 | entropy */
        "movl $0, 0x1c(%edi)\n" /* line 184 | entropy */
        "movl 8(%ebp), %edx\n" /* line 187 | cinfo */
        "movl 0xc0(%edx), %eax\n"
        "movl %eax, 0x44(%edi)\n" /* entropy */
        "movl $0, 0x48(%edi)\n" /* line 188 | entropy */
        "addl $0x2c, %esp\n" /* line 189 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20ffb0_0021014a:\n"
        "leal 0xd6a(%ebx), %eax\n" /* line 130 */
        "movl %eax, 4(%edi)\n" /* entropy */
        "movl 0x40(%edi), %eax\n" /* line 132 | entropy */
        "testl %eax, %eax\n"
        "jne .Lf20ffb0_002100ef\n"
        "movl 8(%ebp), %edx\n" /* line 133 | cinfo */
        "movl 4(%edx), %eax\n"
        "movl $0x3e8, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl %eax, 0x40(%edi)\n" /* entropy */
        "jmp .Lf20ffb0_002100ef\n"
        ".Lf20ffb0_0021017d:\n"
        "leal 0x1b2b(%ebx), %eax\n" /* line 123 */
        "movl %eax, 4(%edi)\n" /* entropy */
        "jmp .Lf20ffb0_002100ef\n"
        ".Lf20ffb0_0021018b:\n"
        "movl -0x20(%ebp), %edx\n" /* line 147 */
        "movl 0xec(%edx), %eax\n"
        "movl -0x1c(%ebp), %edx\n" /* line 149 */
        "movl $0, 0x24(%edx)\n"
        "movl 0x18(%eax), %esi\n" /* line 156 | tbl */
        "movl %esi, 0x34(%edi)\n" /* tbl, entropy */
        "leal 0x4c(%edi, %esi, 4), %eax\n" /* line 173 | entropy */
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* tbl */
        "movzbl -0x25(%ebp), %eax\n" /* is_DC_band */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll jpeg_make_c_derived_tbl\n"
        "addl $1, -0x24(%ebp)\n" /* line 146 | ci */
        "addl $4, -0x20(%ebp)\n"
        "addl $4, -0x1c(%ebp)\n"
        "movl -0x24(%ebp), %eax\n" /* ci */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "cmpl 0xe8(%edx), %eax\n"
        "jl .Lf20ffb0_0021018b\n"
        "jmp .Lf20ffb0_00210113\n"
        ".Lf20ffb0_002101e2:\n"
        "movl %eax, %edx\n"
        "jmp .Lf20ffb0_00210206\n"
        ".Lf20ffb0_002101e6:\n"
        "movl %edx, %eax\n"
        ".Lf20ffb0_002101e8:\n"
        "addl $1, -0x24(%ebp)\n" /* ci */
        "addl $4, -0x20(%ebp)\n"
        "addl $4, -0x1c(%ebp)\n"
        "movl -0x24(%ebp), %edx\n" /* ci */
        "cmpl 0xe8(%eax), %edx\n"
        "jge .Lf20ffb0_00210113\n"
        "movl -0x20(%ebp), %edx\n"
        ".Lf20ffb0_00210206:\n"
        "movl 0xec(%edx), %eax\n" /* line 147 */
        "movl -0x1c(%ebp), %edx\n" /* line 149 */
        "movl $0, 0x24(%edx)\n"
        "movl 8(%ebp), %edx\n" /* line 152 | cinfo */
        "movl 0x138(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf20ffb0_002101e6\n"
        "movl 0x14(%eax), %esi\n" /* line 154 | tbl */
        "cmpb $0, -0x26(%ebp)\n" /* line 158 | gather_statistics */
        "je .Lf20ffb0_0021025a\n"
        "cmpl $3, %esi\n" /* line 161 | tbl */
        "ja .Lf20ffb0_00210281\n"
        "movl 0x5c(%edi, %esi, 4), %edx\n" /* line 165 | entropy */
        "testl %edx, %edx\n"
        "je .Lf20ffb0_002102a1\n"
        ".Lf20ffb0_00210239:\n"
        "movl 0x5c(%edi, %esi, 4), %eax\n" /* entropy */
        ".Lf20ffb0_0021023d:\n"
        "movl $0x404, 8(%esp)\n" /* line 169 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "jmp .Lf20ffb0_002101e8\n"
        ".Lf20ffb0_0021025a:\n"
        "leal 0x4c(%edi, %esi, 4), %eax\n" /* line 173 | entropy */
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* tbl */
        "movzbl -0x25(%ebp), %eax\n" /* is_DC_band */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll jpeg_make_c_derived_tbl\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "jmp .Lf20ffb0_002101e8\n"
        ".Lf20ffb0_00210281:\n"
        "movl 8(%ebp), %edx\n" /* line 162 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x32, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %esi, 0x18(%eax)\n" /* tbl */
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl 0x5c(%edi, %esi, 4), %edx\n" /* line 165 | entropy */
        "testl %edx, %edx\n"
        "jne .Lf20ffb0_00210239\n"
        ".Lf20ffb0_002102a1:\n"
        "movl 8(%ebp), %edx\n" /* line 166 | cinfo */
        "movl 4(%edx), %eax\n"
        "movl $0x404, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl %eax, 0x5c(%edi, %esi, 4)\n" /* entropy */
        "jmp .Lf20ffb0_0021023d\n"
        ".Lf20ffb0_002102c5:\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 4(%edx), %eax\n"
        "movl $0x404, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl %eax, 0x5c(%edi, %esi, 4)\n" /* entropy */
        "jmp .Lf20ffb0_00210076\n"
    );
}

/* line 815 */
__attribute__((naked))
void jinit_phuff_encoder(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 815 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 4(%esi), %eax\n" /* line 819 | cinfo */
        "movl $0x6c, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "movl %eax, %ecx\n"
        "movl %eax, 0x160(%esi)\n" /* line 822 | cinfo */
        "leal -0x346(%ebx), %eax\n" /* line 823 */
        "movl %eax, (%ecx)\n"
        "movl %ecx, %eax\n"
        "movl $4, %edx\n"
        ".Lf2102e9_00210328:\n"
        "movl $0, 0x4c(%eax)\n" /* line 827 */
        "movl $0, 0x5c(%eax)\n" /* line 828 */
        "addl $4, %eax\n"
        "subl $1, %edx\n" /* line 826 */
        "jne .Lf2102e9_00210328\n"
        "movl $0, 0x40(%ecx)\n" /* line 830 */
        "addl $0x10, %esp\n" /* line 831 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 317 */
static __attribute__((naked))
void emit_eobrun(void)
{
    __asm__ __volatile__ (
        /* { scope 1: put_bits, bufstart */
        "pushl %ebp\n" /* line 317 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x70, %esp\n"
        "movl %eax, %esi\n" /* entropy */
        "movl 0x38(%eax), %eax\n" /* line 320 */
        "testl %eax, %eax\n"
        "je .Lf21034c_002104b1\n"
        "sarl $1, %eax\n" /* line 323 */
        "jne .Lf21034c_002104b8\n"
        "movl $0, -0x4c(%ebp)\n" /* nbits */
        "xorl %ecx, %ecx\n"
        "movl 0x34(%esi), %eax\n" /* line 329 | entropy, tbl_no */
        /* { scope 2: c */
        "cmpb $0, 0xc(%esi)\n" /* line 283 */
        "je .Lf21034c_002104f6\n"
        ".Lf21034c_0021037f:\n"
        "movl 0x5c(%esi, %eax, 4), %eax\n" /* line 284 */
        "addl $1, (%eax, %ecx, 4)\n"
        /* } scope */
        ".Lf21034c_00210387:\n"
        "movl -0x4c(%ebp), %eax\n" /* line 330 | nbits */
        "testl %eax, %eax\n"
        "je .Lf21034c_00210493\n"
        /* { scope 2: c */
        "movl 0x38(%esi), %edi\n" /* line 232 | put_buffer */
        "movl %edi, -0x5c(%ebp)\n" /* put_buffer */
        "movl 0x1c(%esi), %edx\n" /* line 233 | put_bits */
        "cmpb $0, 0xc(%esi)\n" /* line 239 */
        "jne .Lf21034c_00210493\n"
        "movl $1, %eax\n" /* line 242 */
        "movzbl -0x4c(%ebp), %ecx\n" /* nbits */
        "shll %cl, %eax\n"
        "leal -1(%eax), %edi\n" /* put_buffer */
        "andl -0x5c(%ebp), %edi\n" /* put_buffer */
        "addl -0x4c(%ebp), %edx\n" /* line 244 | nbits */
        "movl %edx, -0x34(%ebp)\n" /* put_bits */
        "movl $0x18, %ecx\n" /* line 246 */
        "subl %edx, %ecx\n"
        "shll %cl, %edi\n" /* put_buffer */
        "orl 0x18(%esi), %edi\n" /* line 248 | put_buffer */
        "cmpl $7, %edx\n" /* line 250 */
        "jle .Lf21034c_0021048b\n"
        "jmp .Lf21034c_002103ed\n"
        /* { scope 3: dest, dest, size, c */
        ".Lf21034c_002103d3:\n"
        "cmpl $0xff, -0x30(%ebp)\n" /* line 254 | c */
        "je .Lf21034c_00210444\n"
        ".Lf21034c_002103dc:\n"
        "shll $8, %edi\n" /* line 257 | put_buffer */
        "subl $8, -0x34(%ebp)\n" /* line 258 | put_bits */
        /* } scope */
        "cmpl $7, -0x34(%ebp)\n" /* line 250 | put_bits */
        "jle .Lf21034c_002107a6\n"
        /* { scope 3: dest, dest, size, c */
        ".Lf21034c_002103ed:\n"
        "movl %edi, %eax\n" /* line 251 | put_buffer */
        "sarl $0x10, %eax\n"
        "andl $0xff, %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* c */
        "movl 0x10(%esi), %eax\n" /* line 253 */
        "movzbl -0x30(%ebp), %edx\n" /* c */
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0x14(%esi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%esi)\n"
        "testl %eax, %eax\n"
        "jne .Lf21034c_002103d3\n"
        /* { scope 4: put_bits, dest, dest */
        "movl 0x20(%esi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %ecx\n"
        "movl %ecx, -0x2c(%ebp)\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf21034c_002107ae\n"
        ".Lf21034c_0021042d:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 213 | dest */
        "movl (%edx), %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%esi)\n"
        /* } scope */
        "cmpl $0xff, -0x30(%ebp)\n" /* line 254 | c */
        "jne .Lf21034c_002103dc\n"
        ".Lf21034c_00210444:\n"
        "movl 0x10(%esi), %eax\n" /* line 255 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0x14(%esi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%esi)\n"
        "testl %eax, %eax\n"
        "jne .Lf21034c_002103dc\n"
        /* { scope 4: put_bits, dest, dest */
        "movl 0x20(%esi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %ecx\n"
        "movl %ecx, -0x28(%ebp)\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf21034c_002107e4\n"
        ".Lf21034c_00210478:\n"
        "movl -0x28(%ebp), %edx\n" /* line 213 | dest */
        "movl (%edx), %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%esi)\n"
        "jmp .Lf21034c_002103dc\n"
        ".Lf21034c_0021048b:\n"
        "movl %edx, %ecx\n"
        /* } scope */
        /* } scope */
        ".Lf21034c_0021048d:\n"
        "movl %edi, 0x18(%esi)\n" /* line 261 | put_buffer */
        "movl %ecx, 0x1c(%esi)\n" /* line 262 */
        /* } scope */
        ".Lf21034c_00210493:\n"
        "movl $0, 0x38(%esi)\n" /* line 333 | entropy */
        "movl 0x3c(%esi), %eax\n" /* line 336 | entropy, nbits */
        "movl 0x40(%esi), %edx\n" /* entropy */
        /* { scope 2: c */
        "cmpb $0, 0xc(%esi)\n" /* line 300 */
        "je .Lf21034c_0021060f\n"
        /* } scope */
        ".Lf21034c_002104aa:\n"
        "movl $0, 0x3c(%esi)\n" /* line 337 | entropy */
        ".Lf21034c_002104b1:\n"
        "addl $0x70, %esp\n" /* line 339 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf21034c_002104b8:\n"
        "movl $0, -0x4c(%ebp)\n" /* line 323 | nbits */
        ".Lf21034c_002104bf:\n"
        "addl $1, -0x4c(%ebp)\n" /* line 324 | nbits */
        "sarl $1, %eax\n" /* line 323 */
        "jne .Lf21034c_002104bf\n"
        "cmpl $0xe, -0x4c(%ebp)\n" /* line 326 | nbits */
        "jle .Lf21034c_002104e3\n"
        "movl 0x20(%esi), %eax\n" /* line 327 | entropy */
        "movl (%eax), %eax\n"
        "movl $0x28, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n" /* entropy */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        ".Lf21034c_002104e3:\n"
        "movl -0x4c(%ebp), %ecx\n" /* nbits */
        "shll $4, %ecx\n"
        "movl 0x34(%esi), %eax\n" /* line 329 | entropy, tbl_no */
        /* { scope 2: c */
        "cmpb $0, 0xc(%esi)\n" /* line 283 */
        "jne .Lf21034c_0021037f\n"
        /* { scope 3: dest, dest, size, c */
        ".Lf21034c_002104f6:\n"
        "movl 0x4c(%esi, %eax, 4), %eax\n" /* line 286 | tbl */
        "movzbl 0x400(%ecx, %eax), %edx\n" /* line 287 */
        "movsbl %dl, %edi\n" /* put_buffer */
        "movl %edi, -0x48(%ebp)\n" /* put_buffer, size */
        /* { scope 4: put_bits, dest, dest */
        /* { scope 5: c */
        "movl (%eax, %ecx, 4), %ecx\n" /* line 232 */
        "movl %ecx, -0x14(%ebp)\n"
        "movl 0x1c(%esi), %eax\n" /* line 233 */
        "movl %eax, -0x10(%ebp)\n"
        "testb %dl, %dl\n" /* line 236 */
        "je .Lf21034c_0021075e\n"
        ".Lf21034c_0021051c:\n"
        "cmpb $0, 0xc(%esi)\n" /* line 239 */
        "jne .Lf21034c_00210387\n"
        "movl $1, %eax\n" /* line 242 */
        "movzbl -0x48(%ebp), %ecx\n" /* size */
        "shll %cl, %eax\n"
        "leal -1(%eax), %edi\n" /* put_buffer */
        "andl -0x14(%ebp), %edi\n" /* put_buffer */
        "movl -0x48(%ebp), %eax\n" /* line 244 | size */
        "addl -0x10(%ebp), %eax\n"
        "movl %eax, -0x44(%ebp)\n" /* put_bits */
        "movl $0x18, %ecx\n" /* line 246 */
        "subl %eax, %ecx\n"
        "shll %cl, %edi\n" /* put_buffer */
        "orl 0x18(%esi), %edi\n" /* line 248 | put_buffer */
        "cmpl $7, %eax\n" /* line 250 */
        "jle .Lf21034c_00210794\n"
        "jmp .Lf21034c_00210571\n"
        /* { scope 6: dest, dest */
        ".Lf21034c_00210557:\n"
        "cmpl $0xff, -0x40(%ebp)\n" /* line 254 | c */
        "je .Lf21034c_002105c8\n"
        ".Lf21034c_00210560:\n"
        "shll $8, %edi\n" /* line 257 | put_buffer */
        "subl $8, -0x44(%ebp)\n" /* line 258 | put_bits */
        /* } scope */
        "cmpl $7, -0x44(%ebp)\n" /* line 250 | put_bits */
        "jle .Lf21034c_002107a1\n"
        /* { scope 6: dest, dest */
        ".Lf21034c_00210571:\n"
        "movl %edi, %eax\n" /* line 251 | put_buffer */
        "sarl $0x10, %eax\n"
        "andl $0xff, %eax\n"
        "movl %eax, -0x40(%ebp)\n" /* c */
        "movl 0x10(%esi), %eax\n" /* line 253 */
        "movzbl -0x40(%ebp), %edx\n" /* c */
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0x14(%esi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%esi)\n"
        "testl %eax, %eax\n"
        "jne .Lf21034c_00210557\n"
        /* { scope 7 */
        "movl 0x20(%esi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %ecx\n"
        "movl %ecx, -0x3c(%ebp)\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf21034c_002107c9\n"
        ".Lf21034c_002105b1:\n"
        "movl -0x3c(%ebp), %edx\n" /* line 213 | dest */
        "movl (%edx), %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%esi)\n"
        /* } scope */
        "cmpl $0xff, -0x40(%ebp)\n" /* line 254 | c */
        "jne .Lf21034c_00210560\n"
        ".Lf21034c_002105c8:\n"
        "movl 0x10(%esi), %eax\n" /* line 255 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0x14(%esi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%esi)\n"
        "testl %eax, %eax\n"
        "jne .Lf21034c_00210560\n"
        /* { scope 7 */
        "movl 0x20(%esi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %ecx\n"
        "movl %ecx, -0x38(%ebp)\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf21034c_002107ff\n"
        ".Lf21034c_002105fc:\n"
        "movl -0x38(%ebp), %edx\n" /* line 213 | dest */
        "movl (%edx), %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%esi)\n"
        "jmp .Lf21034c_00210560\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c */
        ".Lf21034c_0021060f:\n"
        "testl %eax, %eax\n" /* line 303 */
        "je .Lf21034c_002104aa\n"
        "movl %edx, -0x24(%ebp)\n" /* line 300 | bufstart */
        "leal (%edx, %eax), %eax\n"
        "movl %eax, -0x50(%ebp)\n"
        "movl %edx, %edi\n" /* put_buffer */
        /* { scope 3: dest, dest, size, c */
        ".Lf21034c_00210622:\n"
        "movsbl (%edi), %eax\n" /* line 232 | put_buffer */
        "movl 0x1c(%esi), %edx\n" /* line 233 | put_bits */
        "cmpb $0, 0xc(%esi)\n" /* line 239 */
        "jne .Lf21034c_00210721\n"
        "movl %eax, %edi\n" /* line 242 | put_buffer */
        "andl $1, %edi\n" /* put_buffer */
        "addl $1, %edx\n" /* line 244 */
        "movl %edx, -0xc(%ebp)\n"
        "movl $0x18, %ecx\n" /* line 246 */
        "subl %edx, %ecx\n"
        "shll %cl, %edi\n" /* put_buffer */
        "orl 0x18(%esi), %edi\n" /* line 248 | put_buffer */
        "cmpl $7, %edx\n" /* line 250 */
        "jle .Lf21034c_00210739\n"
        "jmp .Lf21034c_0021066e\n"
        /* { scope 4: put_bits, dest, dest */
        ".Lf21034c_00210654:\n"
        "cmpl $0xff, -0x20(%ebp)\n" /* line 254 | c */
        "je .Lf21034c_002106c5\n"
        ".Lf21034c_0021065d:\n"
        "shll $8, %edi\n" /* line 257 | put_buffer */
        "subl $8, -0xc(%ebp)\n" /* line 258 */
        /* } scope */
        "cmpl $7, -0xc(%ebp)\n" /* line 250 */
        "jle .Lf21034c_00210718\n"
        /* { scope 4: put_bits, dest, dest */
        ".Lf21034c_0021066e:\n"
        "movl %edi, %eax\n" /* line 251 | put_buffer */
        "sarl $0x10, %eax\n"
        "andl $0xff, %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* c */
        "movl 0x10(%esi), %eax\n" /* line 253 */
        "movzbl -0x20(%ebp), %edx\n" /* c */
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0x14(%esi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%esi)\n"
        "testl %eax, %eax\n"
        "jne .Lf21034c_00210654\n"
        /* { scope 5: c */
        "movl 0x20(%esi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf21034c_00210743\n"
        ".Lf21034c_002106ae:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 213 | dest */
        "movl (%edx), %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%esi)\n"
        /* } scope */
        "cmpl $0xff, -0x20(%ebp)\n" /* line 254 | c */
        "jne .Lf21034c_0021065d\n"
        ".Lf21034c_002106c5:\n"
        "movl 0x10(%esi), %eax\n" /* line 255 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0x14(%esi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%esi)\n"
        "testl %eax, %eax\n"
        "jne .Lf21034c_0021065d\n"
        /* { scope 5: c */
        "movl 0x20(%esi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %ecx\n"
        "movl %ecx, -0x18(%ebp)\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf21034c_00210779\n"
        ".Lf21034c_002106f9:\n"
        "movl -0x18(%ebp), %edx\n" /* line 213 | dest */
        "movl (%edx), %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%esi)\n"
        /* } scope */
        "shll $8, %edi\n" /* line 257 | put_buffer */
        "subl $8, -0xc(%ebp)\n" /* line 258 */
        /* } scope */
        "cmpl $7, -0xc(%ebp)\n" /* line 250 */
        "jg .Lf21034c_0021066e\n"
        ".Lf21034c_00210718:\n"
        "movl -0xc(%ebp), %ecx\n"
        "movl %edi, 0x18(%esi)\n" /* line 261 | put_buffer */
        "movl %ecx, 0x1c(%esi)\n" /* line 262 */
        /* } scope */
        ".Lf21034c_00210721:\n"
        "addl $1, -0x24(%ebp)\n" /* line 305 | bufstart */
        "movl -0x50(%ebp), %edi\n" /* line 303 | put_buffer */
        "cmpl %edi, -0x24(%ebp)\n" /* put_buffer, bufstart */
        "je .Lf21034c_002104aa\n"
        "movl -0x24(%ebp), %edi\n" /* bufstart, put_buffer */
        "jmp .Lf21034c_00210622\n"
        ".Lf21034c_00210739:\n"
        "movl %edx, %ecx\n"
        /* { scope 3: dest, dest, size, c */
        "movl %edi, 0x18(%esi)\n" /* line 261 | put_buffer */
        "movl %ecx, 0x1c(%esi)\n" /* line 262 */
        "jmp .Lf21034c_00210721\n"
        /* { scope 4: put_bits, dest, dest */
        /* { scope 5: c */
        ".Lf21034c_00210743:\n"
        "movl 0x20(%esi), %eax\n" /* line 211 */
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf21034c_002106ae\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c */
        /* { scope 3: dest, dest, size, c */
        /* { scope 4: put_bits, dest, dest */
        /* { scope 5: c */
        ".Lf21034c_0021075e:\n"
        "movl 0x20(%esi), %eax\n" /* line 237 */
        "movl (%eax), %eax\n"
        "movl $0x28, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf21034c_0021051c\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c */
        /* { scope 3: dest, dest, size, c */
        /* { scope 4: put_bits, dest, dest */
        /* { scope 5: c */
        ".Lf21034c_00210779:\n"
        "movl 0x20(%esi), %eax\n" /* line 211 */
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf21034c_002106f9\n"
        ".Lf21034c_00210794:\n"
        "movl %eax, %ecx\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c */
        /* { scope 3: dest, dest, size, c */
        /* { scope 4: put_bits, dest, dest */
        /* { scope 5: c */
        ".Lf21034c_00210796:\n"
        "movl %edi, 0x18(%esi)\n" /* line 261 | put_buffer */
        "movl %ecx, 0x1c(%esi)\n" /* line 262 */
        "jmp .Lf21034c_00210387\n"
        ".Lf21034c_002107a1:\n"
        "movl -0x44(%ebp), %ecx\n" /* put_bits */
        "jmp .Lf21034c_00210796\n"
        ".Lf21034c_002107a6:\n"
        "movl -0x34(%ebp), %ecx\n" /* put_bits */
        "jmp .Lf21034c_0021048d\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c */
        /* { scope 3: dest, dest, size, c */
        /* { scope 4: put_bits, dest, dest */
        ".Lf21034c_002107ae:\n"
        "movl 0x20(%esi), %eax\n" /* line 211 */
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf21034c_0021042d\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c */
        /* { scope 3: dest, dest, size, c */
        /* { scope 4: put_bits, dest, dest */
        /* { scope 5: c */
        /* { scope 6: dest, dest */
        /* { scope 7 */
        ".Lf21034c_002107c9:\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf21034c_002105b1\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c */
        /* { scope 3: dest, dest, size, c */
        /* { scope 4: put_bits, dest, dest */
        ".Lf21034c_002107e4:\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf21034c_00210478\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c */
        /* { scope 3: dest, dest, size, c */
        /* { scope 4: put_bits, dest, dest */
        /* { scope 5: c */
        /* { scope 6: dest, dest */
        /* { scope 7 */
        ".Lf21034c_002107ff:\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf21034c_002105fc\n"
    );
}

/* line 747 */
static __attribute__((naked))
void finish_pass_phuff(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 747 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 748 | cinfo */
        "movl 0x160(%eax), %esi\n" /* entropy */
        "movl %eax, %edx\n" /* line 750 */
        "movl 0x20(%eax), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, 0x10(%esi)\n" /* entropy */
        "movl 0x20(%edx), %eax\n" /* line 751 */
        "movl 4(%eax), %eax\n"
        "movl %eax, 0x14(%esi)\n" /* entropy */
        "movl %esi, %eax\n" /* line 754 | entropy */
        "calll emit_eobrun\n"
        /* { scope 2: c */
        "movl 0x1c(%esi), %eax\n" /* line 233 | put_bits */
        "cmpb $0, 0xc(%esi)\n" /* line 239 */
        "jne .Lf21081a_0021087d\n"
        "addl $7, %eax\n" /* line 244 */
        "movl %eax, -0xc(%ebp)\n"
        "movl $0x18, %ecx\n" /* line 246 */
        "subl %eax, %ecx\n"
        "movl $0x7f, -0x10(%ebp)\n"
        "shll %cl, -0x10(%ebp)\n"
        "movl 0x18(%esi), %eax\n" /* line 248 */
        "orl %eax, -0x10(%ebp)\n"
        "cmpl $7, -0xc(%ebp)\n" /* line 250 */
        "jg .Lf21081a_002108df\n"
        ".Lf21081a_00210871:\n"
        "movl -0x10(%ebp), %eax\n" /* line 261 */
        "movl %eax, 0x18(%esi)\n"
        "movl -0xc(%ebp), %edx\n" /* line 262 */
        "movl %edx, 0x1c(%esi)\n"
        /* } scope */
        ".Lf21081a_0021087d:\n"
        "movl $0, 0x18(%esi)\n" /* line 270 */
        "movl $0, 0x1c(%esi)\n" /* line 271 */
        "movl 8(%ebp), %eax\n" /* line 757 | cinfo */
        "movl 0x20(%eax), %edx\n"
        "movl 0x10(%esi), %eax\n" /* entropy */
        "movl %eax, (%edx)\n"
        "movl 8(%ebp), %eax\n" /* line 758 | cinfo */
        "movl 0x20(%eax), %edx\n"
        "movl 0x14(%esi), %eax\n" /* entropy */
        "movl %eax, 4(%edx)\n"
        "addl $0x20, %esp\n" /* line 759 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2: c */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf21081a_002108a9:\n"
        "movl 0x20(%esi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %edi\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%edi)\n" /* dest */
        "testb %al, %al\n"
        "je .Lf21081a_00210948\n"
        ".Lf21081a_002108bd:\n"
        "movl (%edi), %eax\n" /* line 213 | dest */
        "movl %eax, 0x10(%esi)\n"
        "movl 4(%edi), %eax\n" /* line 214 | dest */
        "movl %eax, 0x14(%esi)\n"
        /* } scope */
        "cmpl $0xff, -0x14(%ebp)\n" /* line 254 | c */
        "je .Lf21081a_00210912\n"
        ".Lf21081a_002108d1:\n"
        "shll $8, -0x10(%ebp)\n" /* line 257 */
        "subl $8, -0xc(%ebp)\n" /* line 258 */
        /* } scope */
        "cmpl $7, -0xc(%ebp)\n" /* line 250 */
        "jle .Lf21081a_00210871\n"
        /* { scope 3 */
        ".Lf21081a_002108df:\n"
        "movl -0x10(%ebp), %eax\n" /* line 251 */
        "sarl $0x10, %eax\n"
        "andl $0xff, %eax\n"
        "movl %eax, -0x14(%ebp)\n" /* c */
        "movl 0x10(%esi), %eax\n" /* line 253 */
        "movzbl -0x14(%ebp), %edx\n" /* c */
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0x14(%esi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%esi)\n"
        "testl %eax, %eax\n"
        "je .Lf21081a_002108a9\n"
        "cmpl $0xff, -0x14(%ebp)\n" /* line 254 | c */
        "jne .Lf21081a_002108d1\n"
        ".Lf21081a_00210912:\n"
        "movl 0x10(%esi), %eax\n" /* line 255 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0x14(%esi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%esi)\n"
        "testl %eax, %eax\n"
        "jne .Lf21081a_002108d1\n"
        /* { scope 4 */
        "movl 0x20(%esi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %edi\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%edi)\n" /* dest */
        "testb %al, %al\n"
        "je .Lf21081a_00210963\n"
        ".Lf21081a_0021093b:\n"
        "movl (%edi), %eax\n" /* line 213 | dest */
        "movl %eax, 0x10(%esi)\n"
        "movl 4(%edi), %eax\n" /* line 214 | dest */
        "movl %eax, 0x14(%esi)\n"
        "jmp .Lf21081a_002108d1\n"
        /* } scope */
        /* { scope 4 */
        ".Lf21081a_00210948:\n"
        "movl 0x20(%esi), %eax\n" /* line 211 */
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf21081a_002108bd\n"
        /* } scope */
        /* { scope 4 */
        ".Lf21081a_00210963:\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf21081a_0021093b\n"
    );
}

/* line 768 */
static __attribute__((naked))
void finish_pass_gather_phuff(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 768 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 769 | cinfo */
        "movl 0x160(%eax), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* entropy */
        "calll emit_eobrun\n" /* line 777 */
        "movl 8(%ebp), %edx\n" /* line 779 | cinfo */
        "movl 0x130(%edx), %eax\n"
        "testl %eax, %eax\n"
        "sete -0x21(%ebp)\n" /* is_DC_band */
        "movl $0, -0xc(%ebp)\n" /* line 784 | did */
        "movl 0xe8(%edx), %eax\n" /* line 786 */
        "testl %eax, %eax\n"
        "jg .Lf21097b_002109bb\n"
        ".Lf21097b_002109b4:\n"
        "addl $0x30, %esp\n" /* line 806 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf21097b_002109bb:\n"
        "movl 8(%ebp), %eax\n" /* line 786 | cinfo */
        "movl %eax, -0x1c(%ebp)\n"
        "movl $0, -0x20(%ebp)\n" /* ci */
        "cmpb $0, -0x21(%ebp)\n" /* is_DC_band */
        "je .Lf21097b_00210a95\n"
        "movl %eax, %edx\n"
        "jmp .Lf21097b_002109ef\n"
        ".Lf21097b_002109d6:\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        ".Lf21097b_002109d9:\n"
        "addl $1, -0x20(%ebp)\n" /* ci */
        "addl $4, -0x1c(%ebp)\n"
        "movl -0x20(%ebp), %eax\n" /* ci */
        "cmpl 0xe8(%edx), %eax\n"
        "jge .Lf21097b_002109b4\n"
        "movl -0x1c(%ebp), %edx\n"
        ".Lf21097b_002109ef:\n"
        "movl 0xec(%edx), %eax\n" /* line 787 */
        "movl 8(%ebp), %edx\n" /* line 789 | cinfo */
        "movl 0x138(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf21097b_002109d9\n"
        "movl 0x14(%eax), %esi\n" /* line 791 | tbl */
        "cmpb $0, -0xc(%ebp, %esi)\n" /* line 795 */
        "jne .Lf21097b_002109d6\n"
        "cmpb $0, -0x21(%ebp)\n" /* line 796 | is_DC_band */
        "jne .Lf21097b_00210ab7\n"
        "movl 8(%ebp), %edx\n" /* line 799 | cinfo */
        "leal 0x6c(%edx, %esi, 4), %edi\n" /* htblptr */
        ".Lf21097b_00210a1d:\n"
        "movl (%edi), %eax\n" /* line 800 | htblptr */
        "testl %eax, %eax\n"
        "je .Lf21097b_00210ad2\n"
        ".Lf21097b_00210a27:\n"
        "movl -0x28(%ebp), %edx\n" /* line 802 | entropy */
        "movl 0x5c(%edx, %esi, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl (%edi), %eax\n" /* htblptr */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll jpeg_gen_optimal_table\n"
        "movb $1, -0xc(%ebp, %esi)\n" /* line 803 */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "jmp .Lf21097b_002109d9\n"
        ".Lf21097b_00210a4d:\n"
        "movl 8(%ebp), %eax\n" /* line 797 | cinfo */
        "leal 0x5c(%eax, %esi, 4), %edi\n" /* htblptr */
        ".Lf21097b_00210a54:\n"
        "movl (%edi), %eax\n" /* line 800 | htblptr */
        "testl %eax, %eax\n"
        "je .Lf21097b_00210ac3\n"
        ".Lf21097b_00210a5a:\n"
        "movl -0x28(%ebp), %edx\n" /* line 802 | entropy */
        "movl 0x5c(%edx, %esi, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl (%edi), %eax\n" /* htblptr */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll jpeg_gen_optimal_table\n"
        "movb $1, -0xc(%ebp, %esi)\n" /* line 803 */
        ".Lf21097b_00210a7b:\n"
        "addl $1, -0x20(%ebp)\n" /* line 786 | ci */
        "addl $4, -0x1c(%ebp)\n"
        "movl -0x20(%ebp), %eax\n" /* ci */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "cmpl 0xe8(%edx), %eax\n"
        "jge .Lf21097b_002109b4\n"
        ".Lf21097b_00210a95:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 787 */
        "movl 0xec(%edx), %eax\n"
        "movl 0x18(%eax), %esi\n" /* line 793 | tbl */
        "cmpb $0, -0xc(%ebp, %esi)\n" /* line 795 */
        "jne .Lf21097b_00210a7b\n"
        "cmpb $0, -0x21(%ebp)\n" /* line 796 | is_DC_band */
        "jne .Lf21097b_00210a4d\n"
        "movl 8(%ebp), %edx\n" /* line 799 | cinfo */
        "leal 0x6c(%edx, %esi, 4), %edi\n" /* htblptr */
        "jmp .Lf21097b_00210a54\n"
        ".Lf21097b_00210ab7:\n"
        "movl 8(%ebp), %eax\n" /* line 797 | cinfo */
        "leal 0x5c(%eax, %esi, 4), %edi\n" /* htblptr */
        "jmp .Lf21097b_00210a1d\n"
        ".Lf21097b_00210ac3:\n"
        "movl 8(%ebp), %eax\n" /* line 801 | cinfo */
        "movl %eax, (%esp)\n"
        "calll jpeg_alloc_huff_table\n"
        "movl %eax, (%edi)\n" /* htblptr */
        "jmp .Lf21097b_00210a5a\n"
        ".Lf21097b_00210ad2:\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl %edx, (%esp)\n"
        "calll jpeg_alloc_huff_table\n"
        "movl %eax, (%edi)\n" /* htblptr */
        "jmp .Lf21097b_00210a27\n"
    );
}

/* line 348 */
static __attribute__((naked))
void emit_restart(int restart_num)
{
    __asm__ __volatile__ (
        /* { scope 1: put_buffer */
        "pushl %ebp\n" /* line 348 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x20, %esp\n"
        "movl %eax, %esi\n" /* entropy */
        "movl %edx, -0x18(%ebp)\n"
        "calll emit_eobrun\n" /* line 351 */
        "cmpb $0, 0xc(%esi)\n" /* line 353 | entropy */
        "jne .Lf210ae4_00210b73\n"
        /* { scope 2: c */
        "movl 0x1c(%esi), %eax\n" /* line 244 */
        "addl $7, %eax\n"
        "movl %eax, -0xc(%ebp)\n"
        "movl $0x18, %ecx\n" /* line 246 */
        "subl %eax, %ecx\n"
        "movl $0x7f, -0x14(%ebp)\n" /* put_buffer */
        "shll %cl, -0x14(%ebp)\n" /* put_buffer */
        "movl 0x18(%esi), %edx\n" /* line 248 */
        "orl %edx, -0x14(%ebp)\n" /* put_buffer */
        "cmpl $7, %eax\n" /* line 250 */
        "jg .Lf210ae4_00210bfa\n"
        /* } scope */
        ".Lf210ae4_00210b25:\n"
        "movl $0, 0x18(%esi)\n" /* line 270 */
        "movl $0, 0x1c(%esi)\n" /* line 271 */
        "movl 0x10(%esi), %eax\n" /* line 355 | entropy */
        "movb $0xff, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n" /* entropy */
        "movl 0x14(%esi), %eax\n" /* entropy */
        "subl $1, %eax\n"
        "movl %eax, 0x14(%esi)\n" /* entropy */
        "testl %eax, %eax\n"
        "je .Lf210ae4_00210c7c\n"
        "movl 0x10(%esi), %eax\n" /* line 356 | entropy */
        "movzbl -0x18(%ebp), %edx\n"
        "subb $0x30, %dl\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n" /* entropy */
        "movl 0x14(%esi), %eax\n" /* entropy */
        "subl $1, %eax\n"
        "movl %eax, 0x14(%esi)\n" /* entropy */
        "testl %eax, %eax\n"
        "je .Lf210ae4_00210cba\n"
        ".Lf210ae4_00210b73:\n"
        "movl 0x20(%esi), %ecx\n" /* line 359 | entropy */
        "movl 0x130(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf210ae4_00210c67\n"
        "movl 0xe8(%ecx), %eax\n" /* line 361 */
        "testl %eax, %eax\n"
        "jle .Lf210ae4_00210ba7\n"
        "movl %esi, %eax\n" /* entropy */
        "xorl %edx, %edx\n"
        ".Lf210ae4_00210b92:\n"
        "movl $0, 0x24(%eax)\n" /* line 362 */
        "addl $1, %edx\n" /* line 361 */
        "addl $4, %eax\n"
        "cmpl 0xe8(%ecx), %edx\n"
        "jl .Lf210ae4_00210b92\n"
        ".Lf210ae4_00210ba7:\n"
        "addl $0x20, %esp\n" /* line 368 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2: c */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf210ae4_00210bae:\n"
        "movl 0x20(%esi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %edi\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%edi)\n" /* dest */
        "testb %al, %al\n"
        "jne .Lf210ae4_00210bd4\n"
        "movl 0x20(%esi), %eax\n" /* line 211 */
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        ".Lf210ae4_00210bd4:\n"
        "movl (%edi), %eax\n" /* line 213 | dest */
        "movl %eax, 0x10(%esi)\n"
        "movl 4(%edi), %eax\n" /* line 214 | dest */
        "movl %eax, 0x14(%esi)\n"
        /* } scope */
        "cmpl $0xff, -0x10(%ebp)\n" /* line 254 | c */
        "je .Lf210ae4_00210c2d\n"
        ".Lf210ae4_00210be8:\n"
        "shll $8, -0x14(%ebp)\n" /* line 257 | put_buffer */
        "subl $8, -0xc(%ebp)\n" /* line 258 */
        /* } scope */
        "cmpl $7, -0xc(%ebp)\n" /* line 250 */
        "jle .Lf210ae4_00210b25\n"
        /* { scope 3 */
        ".Lf210ae4_00210bfa:\n"
        "movl -0x14(%ebp), %eax\n" /* line 251 | put_buffer */
        "sarl $0x10, %eax\n"
        "andl $0xff, %eax\n"
        "movl %eax, -0x10(%ebp)\n" /* c */
        "movl 0x10(%esi), %eax\n" /* line 253 */
        "movzbl -0x10(%ebp), %edx\n" /* c */
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0x14(%esi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%esi)\n"
        "testl %eax, %eax\n"
        "je .Lf210ae4_00210bae\n"
        "cmpl $0xff, -0x10(%ebp)\n" /* line 254 | c */
        "jne .Lf210ae4_00210be8\n"
        ".Lf210ae4_00210c2d:\n"
        "movl 0x10(%esi), %eax\n" /* line 255 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0x14(%esi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%esi)\n"
        "testl %eax, %eax\n"
        "jne .Lf210ae4_00210be8\n"
        /* { scope 4 */
        "movl 0x20(%esi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %edi\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%edi)\n" /* dest */
        "testb %al, %al\n"
        "je .Lf210ae4_00210cda\n"
        ".Lf210ae4_00210c5a:\n"
        "movl (%edi), %eax\n" /* line 213 | dest */
        "movl %eax, 0x10(%esi)\n"
        "movl 4(%edi), %eax\n" /* line 214 | dest */
        "movl %eax, 0x14(%esi)\n"
        "jmp .Lf210ae4_00210be8\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf210ae4_00210c67:\n"
        "movl $0, 0x38(%esi)\n" /* line 365 | entropy */
        "movl $0, 0x3c(%esi)\n" /* line 366 | entropy */
        "addl $0x20, %esp\n" /* line 368 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2: c */
        ".Lf210ae4_00210c7c:\n"
        "movl 0x20(%esi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %edi\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%edi)\n" /* dest */
        "testb %al, %al\n"
        "je .Lf210ae4_00210cf5\n"
        ".Lf210ae4_00210c8c:\n"
        "movl (%edi), %eax\n" /* line 213 | dest */
        "movl %eax, 0x10(%esi)\n"
        "movl 4(%edi), %eax\n" /* line 214 | dest */
        "movl %eax, 0x14(%esi)\n"
        /* } scope */
        "movl 0x10(%esi), %eax\n" /* line 356 | entropy */
        "movzbl -0x18(%ebp), %edx\n"
        "subb $0x30, %dl\n"
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n" /* entropy */
        "movl 0x14(%esi), %eax\n" /* entropy */
        "subl $1, %eax\n"
        "movl %eax, 0x14(%esi)\n" /* entropy */
        "testl %eax, %eax\n"
        "jne .Lf210ae4_00210b73\n"
        /* { scope 2: c */
        ".Lf210ae4_00210cba:\n"
        "movl 0x20(%esi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %edi\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%edi)\n" /* dest */
        "testb %al, %al\n"
        "je .Lf210ae4_00210d10\n"
        ".Lf210ae4_00210cca:\n"
        "movl (%edi), %eax\n" /* line 213 | dest */
        "movl %eax, 0x10(%esi)\n"
        "movl 4(%edi), %eax\n" /* line 214 | dest */
        "movl %eax, 0x14(%esi)\n"
        "jmp .Lf210ae4_00210b73\n"
        /* } scope */
        /* { scope 2: c */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf210ae4_00210cda:\n"
        "movl 0x20(%esi), %eax\n" /* line 211 */
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf210ae4_00210c5a\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c */
        ".Lf210ae4_00210cf5:\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf210ae4_00210c8c\n"
        /* } scope */
        /* { scope 2: c */
        ".Lf210ae4_00210d10:\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf210ae4_00210cca\n"
    );
}

/* line 619 */
static __attribute__((naked))
boolean encode_mcu_AC_refine(j_compress_ptr cinfo, JBLOCKROW *MCU_data)
{
    __asm__ __volatile__ (
        /* { scope 1: put_bits */
        "pushl %ebp\n" /* line 619 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1dc, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %eax\n" /* line 620 | cinfo */
        "movl 0x160(%eax), %edi\n" /* entropy */
        "movl 0x134(%eax), %edx\n" /* line 626 */
        "movl %edx, -0x1a4(%ebp)\n" /* Se */
        "movl 0x13c(%eax), %ecx\n" /* line 627 */
        "movl %ecx, -0x1a0(%ebp)\n" /* Al */
        "movl %eax, %esi\n" /* line 631 | put_buffer */
        "movl 0x20(%eax), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, 0x10(%edi)\n" /* entropy */
        "movl 0x20(%esi), %eax\n" /* line 632 | put_buffer */
        "movl 4(%eax), %eax\n"
        "movl %eax, 0x14(%edi)\n" /* entropy */
        "movl 0xc0(%esi), %eax\n" /* line 635 | put_buffer */
        "testl %eax, %eax\n"
        "je .Lf210d28_00210d82\n"
        "movl 0x44(%edi), %eax\n" /* line 636 | entropy */
        "testl %eax, %eax\n"
        "je .Lf210d28_00211466\n"
        ".Lf210d28_00210d82:\n"
        "movl 0xc(%ebp), %eax\n" /* line 640 | MCU_data */
        "movl (%eax), %eax\n"
        "movl %eax, -0x19c(%ebp)\n" /* block */
        "movl 8(%ebp), %eax\n" /* line 646 | cinfo */
        "movl 0x130(%eax), %eax\n"
        "movl %eax, -0x11c(%ebp)\n"
        "cmpl %eax, -0x1a4(%ebp)\n" /* Se */
        "jl .Lf210d28_00211359\n"
        "movl %eax, %ecx\n"
        "shll $2, %eax\n"
        "movl 0x174ec8f(%ebx), %edx\n"
        "addl %eax, %edx\n"
        "movl %edx, -0x144(%ebp)\n"
        "leal -0x118(%ebp, %eax), %esi\n" /* put_buffer */
        "movl %ecx, -0x1bc(%ebp)\n" /* k */
        "movl $0, -0x1b0(%ebp)\n" /* EOB */
        "movl %edx, %eax\n"
        "jmp .Lf210d28_00210ddc\n"
        ".Lf210d28_00210dd6:\n"
        "movl -0x144(%ebp), %eax\n"
        ".Lf210d28_00210ddc:\n"
        "movl (%eax), %eax\n" /* line 647 */
        "movl %eax, -0x1cc(%ebp)\n"
        "movl -0x19c(%ebp), %ecx\n" /* block */
        "movswl (%ecx, %eax, 2), %edx\n"
        "movl %edx, %eax\n"
        "negl %eax\n"
        "cmpl $-1, %edx\n"
        "cmovgl %edx, %eax\n"
        "movzbl -0x1a0(%ebp), %ecx\n" /* line 654 | Al */
        "sarl %cl, %eax\n"
        "movl %eax, (%esi)\n" /* line 655 | put_buffer */
        "subl $1, %eax\n" /* line 656 */
        "movl -0x1bc(%ebp), %eax\n" /* k */
        "cmovnel -0x1b0(%ebp), %eax\n" /* EOB */
        "movl %eax, -0x1b0(%ebp)\n" /* EOB */
        "addl $1, -0x1bc(%ebp)\n" /* line 646 | k */
        "addl $4, -0x144(%ebp)\n"
        "addl $4, %esi\n" /* put_buffer */
        "movl -0x1bc(%ebp), %edx\n" /* k */
        "cmpl %edx, -0x1a4(%ebp)\n" /* Se */
        "jge .Lf210d28_00210dd6\n"
        ".Lf210d28_00210e38:\n"
        "movl 0x40(%edi), %ecx\n" /* line 664 | entropy */
        "movl %ecx, -0x1ac(%ebp)\n" /* BR_buffer */
        "movl 0x3c(%edi), %esi\n" /* entropy, put_buffer */
        "addl %esi, %ecx\n" /* put_buffer */
        "movl %ecx, -0x1ac(%ebp)\n" /* BR_buffer */
        "movl -0x11c(%ebp), %eax\n" /* line 666 */
        "cmpl %eax, -0x1a4(%ebp)\n" /* Se */
        "jl .Lf210d28_00210f70\n"
        "shll $2, %eax\n"
        "leal -0x118(%ebp, %eax), %edx\n"
        "movl %edx, -0x14c(%ebp)\n"
        "addl 0x174ec8f(%ebx), %eax\n"
        "movl %eax, -0x148(%ebp)\n"
        "movl $0, -0x1b4(%ebp)\n" /* r */
        "movl $0, -0x1a8(%ebp)\n" /* BR */
        "movl %edx, %ecx\n"
        "jmp .Lf210d28_00210ec2\n"
        ".Lf210d28_00210e92:\n"
        "addl $1, -0x1b4(%ebp)\n" /* line 668 | r */
        ".Lf210d28_00210e99:\n"
        "addl $1, -0x11c(%ebp)\n" /* line 666 */
        "addl $4, -0x14c(%ebp)\n"
        "addl $4, -0x148(%ebp)\n"
        "movl -0x11c(%ebp), %edx\n"
        "cmpl %edx, -0x1a4(%ebp)\n" /* Se */
        "jl .Lf210d28_00210f3a\n"
        ".Lf210d28_00210ebc:\n"
        "movl -0x14c(%ebp), %ecx\n"
        ".Lf210d28_00210ec2:\n"
        "movl (%ecx), %ecx\n" /* line 667 */
        "movl %ecx, -0x140(%ebp)\n"
        "testl %ecx, %ecx\n"
        "je .Lf210d28_00210e92\n"
        "cmpl $0xf, -0x1b4(%ebp)\n" /* line 673 | r */
        "jle .Lf210d28_00210ee9\n"
        "movl -0x1b0(%ebp), %esi\n" /* EOB, put_buffer */
        "cmpl %esi, -0x11c(%ebp)\n" /* put_buffer */
        "jle .Lf210d28_00210fe9\n"
        ".Lf210d28_00210ee9:\n"
        "cmpl $1, -0x140(%ebp)\n" /* line 690 */
        "jle .Lf210d28_002113b4\n"
        "movzbl -0x140(%ebp), %eax\n" /* line 692 */
        "andb $1, %al\n"
        "movl -0x1ac(%ebp), %ecx\n" /* BR_buffer */
        "movl -0x1a8(%ebp), %esi\n" /* BR, put_buffer */
        "movb %al, (%ecx, %esi)\n"
        "addl $1, %esi\n" /* put_buffer */
        "movl %esi, -0x1a8(%ebp)\n" /* put_buffer, BR */
        "addl $1, -0x11c(%ebp)\n" /* line 666 */
        "addl $4, -0x14c(%ebp)\n"
        "addl $4, -0x148(%ebp)\n"
        "movl -0x11c(%ebp), %edx\n"
        "cmpl %edx, -0x1a4(%ebp)\n" /* Se */
        "jge .Lf210d28_00210ebc\n"
        ".Lf210d28_00210f3a:\n"
        "movl -0x1b4(%ebp), %esi\n" /* line 713 | r, put_buffer */
        "testl %esi, %esi\n" /* put_buffer */
        "jle .Lf210d28_0021163a\n"
        ".Lf210d28_00210f48:\n"
        "addl $1, 0x38(%edi)\n" /* line 714 | entropy */
        "movl -0x1a8(%ebp), %eax\n" /* line 715 | BR */
        "addl 0x3c(%edi), %eax\n" /* entropy */
        "movl %eax, 0x3c(%edi)\n" /* entropy */
        "cmpl $0x7fff, 0x38(%edi)\n" /* line 720 | entropy */
        "je .Lf210d28_002113a8\n"
        "cmpl $0x3a9, %eax\n"
        "ja .Lf210d28_002113a8\n"
        ".Lf210d28_00210f70:\n"
        "movl 8(%ebp), %ecx\n" /* line 724 | cinfo */
        "movl 0x20(%ecx), %edx\n"
        "movl 0x10(%edi), %eax\n" /* entropy */
        "movl %eax, (%edx)\n"
        "movl 0x20(%ecx), %edx\n" /* line 725 */
        "movl 0x14(%edi), %eax\n" /* entropy */
        "movl %eax, 4(%edx)\n"
        "movl 0xc0(%ecx), %eax\n" /* line 728 */
        "testl %eax, %eax\n"
        "je .Lf210d28_00210f9d\n"
        "movl 0x44(%edi), %edx\n" /* line 729 | entropy */
        "testl %edx, %edx\n"
        "je .Lf210d28_00211368\n"
        ".Lf210d28_00210f99:\n"
        "subl $1, 0x44(%edi)\n" /* line 734 | entropy */
        ".Lf210d28_00210f9d:\n"
        "movl $1, %eax\n" /* line 738 */
        "addl $0x1dc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2: c, c, c */
        ".Lf210d28_00210fad:\n"
        "movl 0x5c(%edi, %eax, 4), %eax\n" /* line 284 */
        "addl $1, 0x3c0(%eax)\n"
        /* } scope */
        ".Lf210d28_00210fb8:\n"
        "subl $0x10, -0x1b4(%ebp)\n" /* line 678 | r */
        "cmpb $0, 0xc(%edi)\n" /* line 300 */
        "je .Lf210d28_00211175\n"
        ".Lf210d28_00210fc9:\n"
        "movl 0x40(%edi), %edx\n" /* line 681 | entropy */
        "movl %edx, -0x1ac(%ebp)\n" /* BR_buffer */
        "movl $0, -0x1a8(%ebp)\n" /* BR */
        "cmpl $0xf, -0x1b4(%ebp)\n" /* line 673 | r */
        "jle .Lf210d28_00210ee9\n"
        ".Lf210d28_00210fe9:\n"
        "movl %edi, %eax\n" /* line 675 | entropy */
        "calll emit_eobrun\n"
        "movl 0x34(%edi), %eax\n" /* line 677 | entropy, tbl_no */
        /* { scope 2: c, c, c */
        "cmpb $0, 0xc(%edi)\n" /* line 283 */
        "jne .Lf210d28_00210fad\n"
        /* { scope 3: size, dest, dest, size, ... */
        "movl 0x4c(%edi, %eax, 4), %eax\n" /* line 286 | tbl */
        "movzbl 0x4f0(%eax), %edx\n" /* line 287 */
        "movsbl %dl, %ecx\n"
        "movl %ecx, -0x198(%ebp)\n" /* size */
        /* { scope 4: put_bits, put_buffer, put_bits */
        /* { scope 5: c, c */
        "movl 0x3c0(%eax), %eax\n" /* line 232 | put_buffer */
        "movl %eax, -0x13c(%ebp)\n" /* put_buffer */
        "movl 0x1c(%edi), %esi\n" /* line 233 | put_buffer */
        "movl %esi, -0x138(%ebp)\n" /* put_buffer */
        "testb %dl, %dl\n" /* line 236 */
        "je .Lf210d28_00211308\n"
        ".Lf210d28_0021102a:\n"
        "cmpb $0, 0xc(%edi)\n" /* line 239 */
        "jne .Lf210d28_00210fb8\n"
        "movl $1, %eax\n" /* line 242 */
        "movzbl -0x198(%ebp), %ecx\n" /* size */
        "shll %cl, %eax\n"
        "leal -1(%eax), %esi\n" /* put_buffer */
        "andl -0x13c(%ebp), %esi\n" /* put_buffer */
        "movl -0x198(%ebp), %eax\n" /* line 244 | size */
        "addl -0x138(%ebp), %eax\n"
        "movl %eax, -0x194(%ebp)\n" /* put_bits */
        "movl $0x18, %ecx\n" /* line 246 */
        "subl %eax, %ecx\n"
        "shll %cl, %esi\n" /* put_buffer */
        "orl 0x18(%edi), %esi\n" /* line 248 | put_buffer */
        "cmpl $7, %eax\n" /* line 250 */
        "jle .Lf210d28_00211158\n"
        "jmp .Lf210d28_00211093\n"
        /* { scope 6: dest, dest, dest, dest */
        ".Lf210d28_00211070:\n"
        "cmpl $0xff, -0x190(%ebp)\n" /* line 254 | c */
        "je .Lf210d28_002110f9\n"
        ".Lf210d28_0021107c:\n"
        "shll $8, %esi\n" /* line 257 | put_buffer */
        "subl $8, -0x194(%ebp)\n" /* line 258 | put_bits */
        /* } scope */
        "cmpl $7, -0x194(%ebp)\n" /* line 250 | put_bits */
        "jle .Lf210d28_00211158\n"
        /* { scope 6: dest, dest, dest, dest */
        ".Lf210d28_00211093:\n"
        "movl %esi, %eax\n" /* line 251 | put_buffer */
        "sarl $0x10, %eax\n"
        "andl $0xff, %eax\n"
        "movl %eax, -0x190(%ebp)\n" /* c */
        "movl 0x10(%edi), %eax\n" /* line 253 */
        "movzbl -0x190(%ebp), %edx\n" /* c */
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%edi)\n"
        "movl 0x14(%edi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%edi)\n"
        "testl %eax, %eax\n"
        "jne .Lf210d28_00211070\n"
        /* { scope 7 */
        "movl 0x20(%edi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %ecx\n"
        "movl %ecx, -0x18c(%ebp)\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf210d28_0021133e\n"
        ".Lf210d28_002110dc:\n"
        "movl -0x18c(%ebp), %edx\n" /* line 213 | dest */
        "movl (%edx), %eax\n"
        "movl %eax, 0x10(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%edi)\n"
        /* } scope */
        "cmpl $0xff, -0x190(%ebp)\n" /* line 254 | c */
        "jne .Lf210d28_0021107c\n"
        ".Lf210d28_002110f9:\n"
        "movl 0x10(%edi), %eax\n" /* line 255 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%edi)\n"
        "movl 0x14(%edi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%edi)\n"
        "testl %eax, %eax\n"
        "jne .Lf210d28_0021107c\n"
        /* { scope 7 */
        "movl 0x20(%edi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %ecx\n"
        "movl %ecx, -0x188(%ebp)\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf210d28_0021137c\n"
        "movl -0x188(%ebp), %edx\n" /* line 213 | dest */
        "movl (%edx), %eax\n"
        "movl %eax, 0x10(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%edi)\n"
        /* } scope */
        ".Lf210d28_00211141:\n"
        "shll $8, %esi\n" /* line 257 | put_buffer */
        "subl $8, -0x194(%ebp)\n" /* line 258 | put_bits */
        /* } scope */
        "cmpl $7, -0x194(%ebp)\n" /* line 250 | put_bits */
        "jg .Lf210d28_00211093\n"
        ".Lf210d28_00211158:\n"
        "movl %esi, 0x18(%edi)\n" /* line 261 | put_buffer */
        "movl -0x194(%ebp), %ecx\n" /* line 262 | put_bits */
        "movl %ecx, 0x1c(%edi)\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        "subl $0x10, -0x1b4(%ebp)\n" /* line 678 | r */
        "cmpb $0, 0xc(%edi)\n" /* line 300 */
        "jne .Lf210d28_00210fc9\n"
        ".Lf210d28_00211175:\n"
        "movl -0x1a8(%ebp), %eax\n" /* line 303 | BR */
        "testl %eax, %eax\n"
        "je .Lf210d28_00210fc9\n"
        "movl -0x1ac(%ebp), %esi\n" /* line 300 | BR_buffer, put_buffer */
        "movl %esi, -0x124(%ebp)\n" /* put_buffer */
        "movl -0x1a8(%ebp), %eax\n" /* BR */
        "leal (%esi, %eax), %eax\n" /* put_buffer */
        "movl %eax, -0x1b8(%ebp)\n"
        "movl %esi, %edx\n" /* put_buffer */
        /* { scope 2: c, c, c */
        ".Lf210d28_002111a0:\n"
        "movsbl (%edx), %eax\n" /* line 232 | put_buffer */
        "movl 0x1c(%edi), %edx\n" /* line 233 | put_bits */
        "cmpb $0, 0xc(%edi)\n" /* line 239 */
        "jne .Lf210d28_002112c9\n"
        "movl %eax, %esi\n" /* line 242 | put_buffer */
        "andl $1, %esi\n" /* put_buffer */
        "addl $1, %edx\n" /* line 244 */
        "movl %edx, -0x184(%ebp)\n" /* put_bits */
        "movl $0x18, %ecx\n" /* line 246 */
        "subl %edx, %ecx\n"
        "shll %cl, %esi\n" /* put_buffer */
        "orl 0x18(%edi), %esi\n" /* line 248 | put_buffer */
        "cmpl $7, %edx\n" /* line 250 */
        "jle .Lf210d28_002112bd\n"
        "jmp .Lf210d28_002111f8\n"
        /* { scope 3: size, dest, dest, size, ... */
        ".Lf210d28_002111d5:\n"
        "cmpl $0xff, -0x180(%ebp)\n" /* line 254 | c */
        "je .Lf210d28_0021125e\n"
        ".Lf210d28_002111e1:\n"
        "shll $8, %esi\n" /* line 257 | put_buffer */
        "subl $8, -0x184(%ebp)\n" /* line 258 | put_bits */
        /* } scope */
        "cmpl $7, -0x184(%ebp)\n" /* line 250 | put_bits */
        "jle .Lf210d28_002112bd\n"
        /* { scope 3: size, dest, dest, size, ... */
        ".Lf210d28_002111f8:\n"
        "movl %esi, %eax\n" /* line 251 | put_buffer */
        "sarl $0x10, %eax\n"
        "andl $0xff, %eax\n"
        "movl %eax, -0x180(%ebp)\n" /* c */
        "movl 0x10(%edi), %eax\n" /* line 253 */
        "movzbl -0x180(%ebp), %ecx\n" /* c */
        "movb %cl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%edi)\n"
        "movl 0x14(%edi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%edi)\n"
        "testl %eax, %eax\n"
        "jne .Lf210d28_002111d5\n"
        /* { scope 4: put_bits, put_buffer, put_bits */
        "movl 0x20(%edi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %edx\n"
        "movl %edx, -0x17c(%ebp)\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "je .Lf210d28_002112ed\n"
        ".Lf210d28_00211241:\n"
        "movl -0x17c(%ebp), %ecx\n" /* line 213 | dest */
        "movl (%ecx), %eax\n"
        "movl %eax, 0x10(%edi)\n"
        "movl 4(%ecx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%edi)\n"
        /* } scope */
        "cmpl $0xff, -0x180(%ebp)\n" /* line 254 | c */
        "jne .Lf210d28_002111e1\n"
        ".Lf210d28_0021125e:\n"
        "movl 0x10(%edi), %eax\n" /* line 255 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%edi)\n"
        "movl 0x14(%edi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%edi)\n"
        "testl %eax, %eax\n"
        "jne .Lf210d28_002111e1\n"
        /* { scope 4: put_bits, put_buffer, put_bits */
        "movl 0x20(%edi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %edx\n"
        "movl %edx, -0x178(%ebp)\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "je .Lf210d28_00211323\n"
        ".Lf210d28_00211295:\n"
        "movl -0x178(%ebp), %ecx\n" /* line 213 | dest */
        "movl (%ecx), %eax\n"
        "movl %eax, 0x10(%edi)\n"
        "movl 4(%ecx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%edi)\n"
        /* } scope */
        "shll $8, %esi\n" /* line 257 | put_buffer */
        "subl $8, -0x184(%ebp)\n" /* line 258 | put_bits */
        /* } scope */
        "cmpl $7, -0x184(%ebp)\n" /* line 250 | put_bits */
        "jg .Lf210d28_002111f8\n"
        ".Lf210d28_002112bd:\n"
        "movl %esi, 0x18(%edi)\n" /* line 261 | put_buffer */
        "movl -0x184(%ebp), %esi\n" /* line 262 | put_bits, put_buffer */
        "movl %esi, 0x1c(%edi)\n" /* put_buffer */
        /* } scope */
        ".Lf210d28_002112c9:\n"
        "addl $1, -0x124(%ebp)\n" /* line 305 */
        "movl -0x1b8(%ebp), %eax\n" /* line 303 */
        "cmpl %eax, -0x124(%ebp)\n"
        "je .Lf210d28_00210fc9\n"
        "movl -0x124(%ebp), %edx\n"
        "jmp .Lf210d28_002111a0\n"
        /* { scope 2: c, c, c */
        /* { scope 3: size, dest, dest, size, ... */
        /* { scope 4: put_bits, put_buffer, put_bits */
        ".Lf210d28_002112ed:\n"
        "movl 0x20(%edi), %eax\n" /* line 211 */
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%edi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf210d28_00211241\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c, c, c */
        /* { scope 3: size, dest, dest, size, ... */
        /* { scope 4: put_bits, put_buffer, put_bits */
        /* { scope 5: c, c */
        ".Lf210d28_00211308:\n"
        "movl 0x20(%edi), %eax\n" /* line 237 */
        "movl (%eax), %eax\n"
        "movl $0x28, 0x14(%eax)\n"
        "movl 0x20(%edi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf210d28_0021102a\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c, c, c */
        /* { scope 3: size, dest, dest, size, ... */
        /* { scope 4: put_bits, put_buffer, put_bits */
        ".Lf210d28_00211323:\n"
        "movl 0x20(%edi), %eax\n" /* line 211 */
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%edi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf210d28_00211295\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c, c, c */
        /* { scope 3: size, dest, dest, size, ... */
        /* { scope 4: put_bits, put_buffer, put_bits */
        /* { scope 5: c, c */
        /* { scope 6: dest, dest, dest, dest */
        /* { scope 7 */
        ".Lf210d28_0021133e:\n"
        "movl 0x20(%edi), %eax\n"
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%edi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf210d28_002110dc\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf210d28_00211359:\n"
        "movl $0, -0x1b0(%ebp)\n" /* line 646 | EOB */
        "jmp .Lf210d28_00210e38\n"
        ".Lf210d28_00211368:\n"
        "movl %eax, 0x44(%edi)\n" /* line 730 | entropy */
        "movl 0x48(%edi), %eax\n" /* line 732 | entropy */
        "addl $1, %eax\n"
        "andl $7, %eax\n"
        "movl %eax, 0x48(%edi)\n" /* entropy */
        "jmp .Lf210d28_00210f99\n"
        /* { scope 2: c, c, c */
        /* { scope 3: size, dest, dest, size, ... */
        /* { scope 4: put_bits, put_buffer, put_bits */
        /* { scope 5: c, c */
        /* { scope 6: dest, dest, dest, dest */
        /* { scope 7 */
        ".Lf210d28_0021137c:\n"
        "movl 0x20(%edi), %eax\n" /* line 211 */
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%edi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "movl -0x188(%ebp), %edx\n" /* line 213 | dest */
        "movl (%edx), %eax\n"
        "movl %eax, 0x10(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%edi)\n"
        "jmp .Lf210d28_00211141\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf210d28_002113a8:\n"
        "movl %edi, %eax\n" /* line 721 | entropy */
        "calll emit_eobrun\n"
        "jmp .Lf210d28_00210f70\n"
        ".Lf210d28_002113b4:\n"
        "movl %edi, %eax\n" /* line 697 | entropy */
        "calll emit_eobrun\n"
        "shll $4, -0x1b4(%ebp)\n" /* line 700 | r */
        "movl -0x1b4(%ebp), %ecx\n" /* r, symbol */
        "addl $1, %ecx\n" /* symbol */
        "movl 0x34(%edi), %eax\n" /* entropy, tbl_no */
        /* { scope 2: c, c, c */
        "cmpb $0, 0xc(%edi)\n" /* line 283 */
        "je .Lf210d28_00211537\n"
        "movl 0x5c(%edi, %eax, 4), %eax\n" /* line 284 */
        "addl $1, (%eax, %ecx, 4)\n"
        /* } scope */
        /* { scope 2: c, c, c */
        ".Lf210d28_002113e0:\n"
        "movl -0x148(%ebp), %esi\n" /* line 232 | put_buffer */
        "movl (%esi), %eax\n" /* put_buffer */
        "movl -0x19c(%ebp), %edx\n" /* block */
        "movswl (%edx, %eax, 2), %eax\n" /* put_buffer */
        "notl %eax\n" /* put_buffer */
        "shrl $0x1f, %eax\n" /* put_buffer */
        "movl 0x1c(%edi), %edx\n" /* line 233 | put_bits */
        "cmpb $0, 0xc(%edi)\n" /* line 239 */
        "jne .Lf210d28_0021143a\n"
        "addl $1, %edx\n" /* line 244 */
        "movl %edx, -0x128(%ebp)\n"
        "movl $0x18, %ecx\n" /* line 246 */
        "subl %edx, %ecx\n"
        "shll %cl, %eax\n"
        "movl %eax, -0x12c(%ebp)\n"
        "movl 0x18(%edi), %ecx\n" /* line 248 */
        "orl %ecx, %eax\n"
        "movl %eax, -0x12c(%ebp)\n"
        "cmpl $7, %edx\n" /* line 250 */
        "jg .Lf210d28_002114c1\n"
        "movl %eax, %ecx\n"
        ".Lf210d28_0021142e:\n"
        "movl %ecx, 0x18(%edi)\n" /* line 261 */
        "movl -0x128(%ebp), %esi\n" /* line 262 | put_buffer */
        "movl %esi, 0x1c(%edi)\n" /* put_buffer */
        /* } scope */
        ".Lf210d28_0021143a:\n"
        "cmpb $0, 0xc(%edi)\n" /* line 300 */
        "je .Lf210d28_0021164d\n"
        ".Lf210d28_00211444:\n"
        "movl 0x40(%edi), %eax\n" /* line 708 | entropy */
        "movl %eax, -0x1ac(%ebp)\n" /* BR_buffer */
        "movl $0, -0x1b4(%ebp)\n" /* r */
        "movl $0, -0x1a8(%ebp)\n" /* BR */
        "jmp .Lf210d28_00210e99\n"
        ".Lf210d28_00211466:\n"
        "movl 0x48(%edi), %edx\n" /* line 637 | entropy */
        "movl %edi, %eax\n" /* entropy */
        "calll emit_restart\n"
        "jmp .Lf210d28_00210d82\n"
        /* { scope 2: c, c, c */
        /* { scope 3: size, dest, dest, size, ... */
        /* { scope 4: put_bits, put_buffer, put_bits */
        ".Lf210d28_00211475:\n"
        "movl 0x20(%edi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %esi\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%esi)\n" /* dest */
        "testb %al, %al\n"
        "je .Lf210d28_00211838\n"
        ".Lf210d28_00211489:\n"
        "movl (%esi), %eax\n" /* line 213 | dest */
        "movl %eax, 0x10(%edi)\n"
        "movl 4(%esi), %eax\n" /* line 214 | dest */
        "movl %eax, 0x14(%edi)\n"
        /* } scope */
        "cmpl $0xff, -0x15c(%ebp)\n" /* line 254 | c */
        "je .Lf210d28_002114fa\n"
        ".Lf210d28_002114a0:\n"
        "shll $8, -0x12c(%ebp)\n" /* line 257 */
        "subl $8, -0x128(%ebp)\n" /* line 258 */
        /* } scope */
        "cmpl $7, -0x128(%ebp)\n" /* line 250 */
        "jle .Lf210d28_0021182d\n"
        "movl -0x12c(%ebp), %eax\n"
        /* { scope 3: size, dest, dest, size, ... */
        ".Lf210d28_002114c1:\n"
        "sarl $0x10, %eax\n" /* line 251 */
        "andl $0xff, %eax\n"
        "movl %eax, -0x15c(%ebp)\n" /* c */
        "movl 0x10(%edi), %eax\n" /* line 253 */
        "movzbl -0x15c(%ebp), %edx\n" /* c */
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%edi)\n"
        "movl 0x14(%edi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%edi)\n"
        "testl %eax, %eax\n"
        "je .Lf210d28_00211475\n"
        "cmpl $0xff, -0x15c(%ebp)\n" /* line 254 | c */
        "jne .Lf210d28_002114a0\n"
        ".Lf210d28_002114fa:\n"
        "movl 0x10(%edi), %eax\n" /* line 255 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%edi)\n"
        "movl 0x14(%edi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%edi)\n"
        "testl %eax, %eax\n"
        "jne .Lf210d28_002114a0\n"
        /* { scope 4: put_bits, put_buffer, put_bits */
        "movl 0x20(%edi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %esi\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%esi)\n" /* dest */
        "testb %al, %al\n"
        "je .Lf210d28_002118a4\n"
        ".Lf210d28_00211527:\n"
        "movl (%esi), %eax\n" /* line 213 | dest */
        "movl %eax, 0x10(%edi)\n"
        "movl 4(%esi), %eax\n" /* line 214 | dest */
        "movl %eax, 0x14(%edi)\n"
        "jmp .Lf210d28_002114a0\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c, c, c */
        /* { scope 3: size, dest, dest, size, ... */
        ".Lf210d28_00211537:\n"
        "movl 0x4c(%edi, %eax, 4), %eax\n" /* line 286 | tbl */
        "movzbl 0x400(%ecx, %eax), %edx\n" /* line 287 */
        "movsbl %dl, %esi\n" /* put_buffer */
        "movl %esi, -0x174(%ebp)\n" /* put_buffer, size */
        /* { scope 4: put_bits, put_buffer, put_bits */
        /* { scope 5: c, c */
        "movl (%eax, %ecx, 4), %ecx\n" /* line 232 */
        "movl %ecx, -0x170(%ebp)\n" /* put_buffer */
        "movl 0x1c(%edi), %eax\n" /* line 233 */
        "movl %eax, -0x16c(%ebp)\n" /* put_bits */
        "testb %dl, %dl\n" /* line 236 */
        "je .Lf210d28_00211853\n"
        ".Lf210d28_00211566:\n"
        "cmpb $0, 0xc(%edi)\n" /* line 239 */
        "jne .Lf210d28_002113e0\n"
        "movl $1, %eax\n" /* line 242 */
        "movzbl -0x174(%ebp), %ecx\n" /* size */
        "shll %cl, %eax\n"
        "leal -1(%eax), %esi\n" /* put_buffer */
        "andl -0x170(%ebp), %esi\n" /* put_buffer */
        "movl -0x174(%ebp), %eax\n" /* line 244 | size */
        "addl -0x16c(%ebp), %eax\n" /* put_bits */
        "movl %eax, -0x130(%ebp)\n"
        "movl $0x18, %ecx\n" /* line 246 */
        "subl %eax, %ecx\n"
        "shll %cl, %esi\n" /* put_buffer */
        "orl 0x18(%edi), %esi\n" /* line 248 | put_buffer */
        "cmpl $7, %eax\n" /* line 250 */
        "jg .Lf210d28_00211609\n"
        ".Lf210d28_002115aa:\n"
        "movl %esi, 0x18(%edi)\n" /* line 261 | put_buffer */
        "movl -0x130(%ebp), %ecx\n" /* line 262 */
        "movl %ecx, 0x1c(%edi)\n"
        "jmp .Lf210d28_002113e0\n"
        /* { scope 6: dest, dest, dest, dest */
        /* { scope 7 */
        ".Lf210d28_002115bb:\n"
        "movl 0x20(%edi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %ecx\n"
        "movl %ecx, -0x164(%ebp)\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf210d28_00211889\n"
        ".Lf210d28_002115d5:\n"
        "movl -0x164(%ebp), %edx\n" /* line 213 | dest */
        "movl (%edx), %eax\n"
        "movl %eax, 0x10(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%edi)\n"
        /* } scope */
        ".Lf210d28_002115e6:\n"
        "cmpl $0xff, -0x168(%ebp)\n" /* line 254 | c */
        "je .Lf210d28_002117e0\n"
        ".Lf210d28_002115f6:\n"
        "shll $8, %esi\n" /* line 257 | put_buffer */
        "subl $8, -0x130(%ebp)\n" /* line 258 */
        /* } scope */
        "cmpl $7, -0x130(%ebp)\n" /* line 250 */
        "jle .Lf210d28_002115aa\n"
        /* { scope 6: dest, dest, dest, dest */
        ".Lf210d28_00211609:\n"
        "movl %esi, %eax\n" /* line 251 | put_buffer */
        "sarl $0x10, %eax\n"
        "andl $0xff, %eax\n"
        "movl %eax, -0x168(%ebp)\n" /* c */
        "movl 0x10(%edi), %eax\n" /* line 253 */
        "movzbl -0x168(%ebp), %edx\n" /* c */
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%edi)\n"
        "movl 0x14(%edi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%edi)\n"
        "testl %eax, %eax\n"
        "jne .Lf210d28_002115e6\n"
        "jmp .Lf210d28_002115bb\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf210d28_0021163a:\n"
        "movl -0x1a8(%ebp), %ecx\n" /* line 713 | BR */
        "testl %ecx, %ecx\n"
        "je .Lf210d28_00210f70\n"
        "jmp .Lf210d28_00210f48\n"
        ".Lf210d28_0021164d:\n"
        "movl -0x1a8(%ebp), %eax\n" /* line 303 | BR */
        "testl %eax, %eax\n"
        "je .Lf210d28_00211444\n"
        "movl -0x1ac(%ebp), %eax\n" /* line 300 | BR_buffer */
        "movl %eax, -0x120(%ebp)\n"
        "movl -0x1a8(%ebp), %edx\n" /* BR */
        "leal (%eax, %edx), %edx\n"
        "movl %edx, -0x1b8(%ebp)\n"
        "movl %eax, %ecx\n"
        /* { scope 2: c, c, c */
        ".Lf210d28_00211678:\n"
        "movsbl (%ecx), %eax\n" /* line 232 | put_buffer */
        "movl 0x1c(%edi), %edx\n" /* line 233 | put_bits */
        "cmpb $0, 0xc(%edi)\n" /* line 239 */
        "jne .Lf210d28_002117a1\n"
        "movl %eax, %esi\n" /* line 242 | put_buffer */
        "andl $1, %esi\n" /* put_buffer */
        "addl $1, %edx\n" /* line 244 */
        "movl %edx, -0x134(%ebp)\n"
        "movl $0x18, %ecx\n" /* line 246 */
        "subl %edx, %ecx\n"
        "shll %cl, %esi\n" /* put_buffer */
        "orl 0x18(%edi), %esi\n" /* line 248 | put_buffer */
        "cmpl $7, %edx\n" /* line 250 */
        "jle .Lf210d28_00211795\n"
        "jmp .Lf210d28_002116d0\n"
        /* { scope 3: size, dest, dest, size, ... */
        ".Lf210d28_002116ad:\n"
        "cmpl $0xff, -0x158(%ebp)\n" /* line 254 | c */
        "je .Lf210d28_00211736\n"
        ".Lf210d28_002116b9:\n"
        "shll $8, %esi\n" /* line 257 | put_buffer */
        "subl $8, -0x134(%ebp)\n" /* line 258 */
        /* } scope */
        "cmpl $7, -0x134(%ebp)\n" /* line 250 */
        "jle .Lf210d28_00211795\n"
        /* { scope 3: size, dest, dest, size, ... */
        ".Lf210d28_002116d0:\n"
        "movl %esi, %eax\n" /* line 251 | put_buffer */
        "sarl $0x10, %eax\n"
        "andl $0xff, %eax\n"
        "movl %eax, -0x158(%ebp)\n" /* c */
        "movl 0x10(%edi), %eax\n" /* line 253 */
        "movzbl -0x158(%ebp), %edx\n" /* c */
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%edi)\n"
        "movl 0x14(%edi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%edi)\n"
        "testl %eax, %eax\n"
        "jne .Lf210d28_002116ad\n"
        /* { scope 4: put_bits, put_buffer, put_bits */
        "movl 0x20(%edi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %ecx\n"
        "movl %ecx, -0x154(%ebp)\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf210d28_002117c5\n"
        ".Lf210d28_00211719:\n"
        "movl -0x154(%ebp), %edx\n" /* line 213 | dest */
        "movl (%edx), %eax\n"
        "movl %eax, 0x10(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%edi)\n"
        /* } scope */
        "cmpl $0xff, -0x158(%ebp)\n" /* line 254 | c */
        "jne .Lf210d28_002116b9\n"
        ".Lf210d28_00211736:\n"
        "movl 0x10(%edi), %eax\n" /* line 255 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%edi)\n"
        "movl 0x14(%edi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%edi)\n"
        "testl %eax, %eax\n"
        "jne .Lf210d28_002116b9\n"
        /* { scope 4: put_bits, put_buffer, put_bits */
        "movl 0x20(%edi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %ecx\n"
        "movl %ecx, -0x150(%ebp)\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf210d28_0021186e\n"
        ".Lf210d28_0021176d:\n"
        "movl -0x150(%ebp), %edx\n" /* line 213 | dest */
        "movl (%edx), %eax\n"
        "movl %eax, 0x10(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%edi)\n"
        /* } scope */
        "shll $8, %esi\n" /* line 257 | put_buffer */
        "subl $8, -0x134(%ebp)\n" /* line 258 */
        /* } scope */
        "cmpl $7, -0x134(%ebp)\n" /* line 250 */
        "jg .Lf210d28_002116d0\n"
        ".Lf210d28_00211795:\n"
        "movl %esi, 0x18(%edi)\n" /* line 261 | put_buffer */
        "movl -0x134(%ebp), %ecx\n" /* line 262 */
        "movl %ecx, 0x1c(%edi)\n"
        /* } scope */
        ".Lf210d28_002117a1:\n"
        "addl $1, -0x120(%ebp)\n" /* line 305 */
        "movl -0x1b8(%ebp), %esi\n" /* line 303 | put_buffer */
        "cmpl %esi, -0x120(%ebp)\n" /* put_buffer */
        "je .Lf210d28_00211444\n"
        "movl -0x120(%ebp), %ecx\n"
        "jmp .Lf210d28_00211678\n"
        /* { scope 2: c, c, c */
        /* { scope 3: size, dest, dest, size, ... */
        /* { scope 4: put_bits, put_buffer, put_bits */
        ".Lf210d28_002117c5:\n"
        "movl 0x20(%edi), %eax\n" /* line 211 */
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%edi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf210d28_00211719\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c, c, c */
        /* { scope 3: size, dest, dest, size, ... */
        /* { scope 4: put_bits, put_buffer, put_bits */
        /* { scope 5: c, c */
        /* { scope 6: dest, dest, dest, dest */
        ".Lf210d28_002117e0:\n"
        "movl 0x10(%edi), %eax\n" /* line 255 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%edi)\n"
        "movl 0x14(%edi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%edi)\n"
        "testl %eax, %eax\n"
        "jne .Lf210d28_002115f6\n"
        /* { scope 7 */
        "movl 0x20(%edi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %ecx\n"
        "movl %ecx, -0x160(%ebp)\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf210d28_002118bf\n"
        ".Lf210d28_00211817:\n"
        "movl -0x160(%ebp), %edx\n" /* line 213 | dest */
        "movl (%edx), %eax\n"
        "movl %eax, 0x10(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%edi)\n"
        "jmp .Lf210d28_002115f6\n"
        ".Lf210d28_0021182d:\n"
        "movl -0x12c(%ebp), %ecx\n"
        "jmp .Lf210d28_0021142e\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c, c, c */
        /* { scope 3: size, dest, dest, size, ... */
        /* { scope 4: put_bits, put_buffer, put_bits */
        ".Lf210d28_00211838:\n"
        "movl 0x20(%edi), %eax\n" /* line 211 */
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%edi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf210d28_00211489\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c, c, c */
        /* { scope 3: size, dest, dest, size, ... */
        /* { scope 4: put_bits, put_buffer, put_bits */
        /* { scope 5: c, c */
        ".Lf210d28_00211853:\n"
        "movl 0x20(%edi), %eax\n" /* line 237 */
        "movl (%eax), %eax\n"
        "movl $0x28, 0x14(%eax)\n"
        "movl 0x20(%edi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf210d28_00211566\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c, c, c */
        /* { scope 3: size, dest, dest, size, ... */
        /* { scope 4: put_bits, put_buffer, put_bits */
        ".Lf210d28_0021186e:\n"
        "movl 0x20(%edi), %eax\n" /* line 211 */
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%edi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf210d28_0021176d\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c, c, c */
        /* { scope 3: size, dest, dest, size, ... */
        /* { scope 4: put_bits, put_buffer, put_bits */
        /* { scope 5: c, c */
        /* { scope 6: dest, dest, dest, dest */
        /* { scope 7 */
        ".Lf210d28_00211889:\n"
        "movl 0x20(%edi), %eax\n"
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%edi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf210d28_002115d5\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c, c, c */
        /* { scope 3: size, dest, dest, size, ... */
        /* { scope 4: put_bits, put_buffer, put_bits */
        ".Lf210d28_002118a4:\n"
        "movl 0x20(%edi), %eax\n"
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%edi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf210d28_00211527\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c, c, c */
        /* { scope 3: size, dest, dest, size, ... */
        /* { scope 4: put_bits, put_buffer, put_bits */
        /* { scope 5: c, c */
        /* { scope 6: dest, dest, dest, dest */
        /* { scope 7 */
        ".Lf210d28_002118bf:\n"
        "movl 0x20(%edi), %eax\n"
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%edi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf210d28_00211817\n"
    );
}

/* line 572 */
static __attribute__((naked))
boolean encode_mcu_DC_refine(j_compress_ptr cinfo, JBLOCKROW *MCU_data)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 572 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 573 | cinfo */
        "movl 0x160(%eax), %esi\n" /* entropy */
        "movl 0x13c(%eax), %edx\n" /* line 576 */
        "movl %edx, -0x1c(%ebp)\n" /* Al */
        "movl %eax, %ecx\n" /* line 579 */
        "movl 0x20(%eax), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, 0x10(%esi)\n" /* entropy */
        "movl 0x20(%ecx), %eax\n" /* line 580 */
        "movl 4(%eax), %eax\n"
        "movl %eax, 0x14(%esi)\n" /* entropy */
        "movl 0xc0(%ecx), %eax\n" /* line 583 */
        "testl %eax, %eax\n"
        "je .Lf2118da_0021191c\n"
        "movl 0x44(%esi), %edi\n" /* line 584 | entropy */
        "testl %edi, %edi\n"
        "je .Lf2118da_00211ada\n"
        ".Lf2118da_0021191c:\n"
        "movl 8(%ebp), %eax\n" /* line 588 | cinfo */
        "movl 0x104(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lf2118da_00211a76\n"
        "movl $0, -0x20(%ebp)\n" /* blkn */
        "movl -0x20(%ebp), %edx\n" /* blkn */
        /* { scope 2: c */
        ".Lf2118da_00211937:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 232 | MCU_data */
        "movl (%ecx, %edx, 4), %eax\n" /* put_buffer */
        "movswl (%eax), %eax\n" /* put_buffer */
        "movzbl -0x1c(%ebp), %ecx\n" /* Al */
        "sarl %cl, %eax\n" /* put_buffer */
        "movl 0x1c(%esi), %edx\n" /* line 233 | put_bits */
        "cmpb $0, 0xc(%esi)\n" /* line 239 */
        "jne .Lf2118da_00211a42\n"
        "movl %eax, %edi\n" /* line 242 */
        "andl $1, %edi\n"
        "addl $1, %edx\n" /* line 244 */
        "movl %edx, -0xc(%ebp)\n"
        "movl $0x18, %ecx\n" /* line 246 */
        "subl %edx, %ecx\n"
        "shll %cl, %edi\n"
        "orl 0x18(%esi), %edi\n" /* line 248 */
        "cmpl $7, %edx\n" /* line 250 */
        "jle .Lf2118da_00211a39\n"
        "jmp .Lf2118da_0021198f\n"
        /* { scope 3: dest, dest */
        ".Lf2118da_00211975:\n"
        "cmpl $0xff, -0x18(%ebp)\n" /* line 254 | c */
        "je .Lf2118da_002119e6\n"
        ".Lf2118da_0021197e:\n"
        "shll $8, %edi\n" /* line 257 */
        "subl $8, -0xc(%ebp)\n" /* line 258 */
        /* } scope */
        "cmpl $7, -0xc(%ebp)\n" /* line 250 */
        "jle .Lf2118da_00211a39\n"
        /* { scope 3: dest, dest */
        ".Lf2118da_0021198f:\n"
        "movl %edi, %eax\n" /* line 251 */
        "sarl $0x10, %eax\n"
        "andl $0xff, %eax\n"
        "movl %eax, -0x18(%ebp)\n" /* c */
        "movl 0x10(%esi), %eax\n" /* line 253 */
        "movzbl -0x18(%ebp), %edx\n" /* c */
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0x14(%esi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%esi)\n"
        "testl %eax, %eax\n"
        "jne .Lf2118da_00211975\n"
        /* { scope 4 */
        "movl 0x20(%esi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %ecx\n"
        "movl %ecx, -0x14(%ebp)\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf2118da_00211a5b\n"
        ".Lf2118da_002119cf:\n"
        "movl -0x14(%ebp), %edx\n" /* line 213 | dest */
        "movl (%edx), %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%esi)\n"
        /* } scope */
        "cmpl $0xff, -0x18(%ebp)\n" /* line 254 | c */
        "jne .Lf2118da_0021197e\n"
        ".Lf2118da_002119e6:\n"
        "movl 0x10(%esi), %eax\n" /* line 255 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0x14(%esi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%esi)\n"
        "testl %eax, %eax\n"
        "jne .Lf2118da_0021197e\n"
        /* { scope 4 */
        "movl 0x20(%esi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %ecx\n"
        "movl %ecx, -0x10(%ebp)\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf2118da_00211abf\n"
        ".Lf2118da_00211a1a:\n"
        "movl -0x10(%ebp), %edx\n" /* line 213 | dest */
        "movl (%edx), %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%esi)\n"
        /* } scope */
        "shll $8, %edi\n" /* line 257 */
        "subl $8, -0xc(%ebp)\n" /* line 258 */
        /* } scope */
        "cmpl $7, -0xc(%ebp)\n" /* line 250 */
        "jg .Lf2118da_0021198f\n"
        ".Lf2118da_00211a39:\n"
        "movl %edi, 0x18(%esi)\n" /* line 261 */
        "movl -0xc(%ebp), %ecx\n" /* line 262 */
        "movl %ecx, 0x1c(%esi)\n"
        /* } scope */
        ".Lf2118da_00211a42:\n"
        "addl $1, -0x20(%ebp)\n" /* line 588 | blkn */
        "movl -0x20(%ebp), %eax\n" /* blkn */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "cmpl 0x104(%edx), %eax\n"
        "jge .Lf2118da_00211aaa\n"
        "movl %eax, %edx\n"
        "jmp .Lf2118da_00211937\n"
        /* { scope 2: c */
        /* { scope 3: dest, dest */
        /* { scope 4 */
        ".Lf2118da_00211a5b:\n"
        "movl 0x20(%esi), %eax\n" /* line 211 */
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf2118da_002119cf\n"
        ".Lf2118da_00211a76:\n"
        "movl %eax, %ecx\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf2118da_00211a78:\n"
        "movl 0x20(%ecx), %edx\n" /* line 596 */
        "movl 0x10(%esi), %eax\n" /* entropy */
        "movl %eax, (%edx)\n"
        "movl 0x20(%ecx), %edx\n" /* line 597 */
        "movl 0x14(%esi), %eax\n" /* entropy */
        "movl %eax, 4(%edx)\n"
        "movl 0xc0(%ecx), %eax\n" /* line 600 */
        "testl %eax, %eax\n"
        "je .Lf2118da_00211a9e\n"
        "movl 0x44(%esi), %edx\n" /* line 601 | entropy */
        "testl %edx, %edx\n"
        "je .Lf2118da_00211aae\n"
        ".Lf2118da_00211a9a:\n"
        "subl $1, 0x44(%esi)\n" /* line 606 | entropy */
        ".Lf2118da_00211a9e:\n"
        "movl $1, %eax\n" /* line 610 */
        "addl $0x30, %esp\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2118da_00211aaa:\n"
        "movl %edx, %ecx\n"
        "jmp .Lf2118da_00211a78\n"
        ".Lf2118da_00211aae:\n"
        "movl %eax, 0x44(%esi)\n" /* line 602 | entropy */
        "movl 0x48(%esi), %eax\n" /* line 604 | entropy */
        "addl $1, %eax\n"
        "andl $7, %eax\n"
        "movl %eax, 0x48(%esi)\n" /* entropy */
        "jmp .Lf2118da_00211a9a\n"
        /* { scope 2: c */
        /* { scope 3: dest, dest */
        /* { scope 4 */
        ".Lf2118da_00211abf:\n"
        "movl 0x20(%esi), %eax\n" /* line 211 */
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf2118da_00211a1a\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf2118da_00211ada:\n"
        "movl 0x48(%esi), %edx\n" /* line 585 | entropy */
        "movl %esi, %eax\n" /* entropy */
        "calll emit_restart\n"
        "jmp .Lf2118da_0021191c\n"
    );
}

/* line 378 */
static __attribute__((naked))
boolean encode_mcu_DC_first(j_compress_ptr cinfo, JBLOCKROW *MCU_data)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 378 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x60, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 379 | cinfo */
        "movl 0x160(%eax), %esi\n" /* entropy */
        "movl 0x13c(%eax), %edx\n" /* line 383 */
        "movl %edx, -0x40(%ebp)\n" /* Al */
        "movl %eax, %ecx\n" /* line 388 */
        "movl 0x20(%eax), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, 0x10(%esi)\n" /* entropy */
        "movl 0x20(%ecx), %eax\n" /* line 389 */
        "movl 4(%eax), %eax\n"
        "movl %eax, 0x14(%esi)\n" /* entropy */
        "movl 0xc0(%ecx), %eax\n" /* line 392 */
        "testl %eax, %eax\n"
        "je .Lf211ae9_00211b2b\n"
        "movl 0x44(%esi), %eax\n" /* line 393 | entropy */
        "testl %eax, %eax\n"
        "je .Lf211ae9_00211ef2\n"
        ".Lf211ae9_00211b2b:\n"
        "movl 8(%ebp), %eax\n" /* line 397 | cinfo */
        "movl 0x104(%eax), %edi\n" /* compptr */
        "testl %edi, %edi\n" /* compptr */
        "jle .Lf211ae9_00211ea7\n"
        "movl %eax, -0x14(%ebp)\n"
        "movl $1, -0x18(%ebp)\n"
        "movl %eax, %ecx\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        ".Lf211ae9_00211b4b:\n"
        "movl 0x108(%ecx), %edx\n" /* line 399 */
        "movl 0xec(%eax, %edx, 4), %edi\n" /* line 400 | compptr */
        "movl -0x18(%ebp), %ecx\n" /* line 405 */
        "movl 0xc(%ebp), %eax\n" /* MCU_data */
        "movl -4(%eax, %ecx, 4), %ecx\n"
        "movl %ecx, -0x4c(%ebp)\n"
        "movswl (%ecx), %eax\n"
        "movzbl -0x40(%ebp), %ecx\n" /* Al */
        "sarl %cl, %eax\n"
        "movl %eax, %ecx\n" /* line 408 */
        "subl 0x24(%esi, %edx, 4), %ecx\n" /* entropy */
        "movl %eax, 0x24(%esi, %edx, 4)\n" /* line 409 | entropy */
        "testl %ecx, %ecx\n" /* line 413 */
        "js .Lf211ae9_00211e4b\n"
        "movl %ecx, -0x48(%ebp)\n" /* temp2 */
        ".Lf211ae9_00211b83:\n"
        "testl %ecx, %ecx\n" /* line 422 */
        "jne .Lf211ae9_00211e1a\n"
        "movl $0, -0x44(%ebp)\n" /* nbits */
        ".Lf211ae9_00211b92:\n"
        "movl 0x14(%edi), %eax\n" /* line 433 | compptr, tbl_no */
        /* { scope 2: c */
        "cmpb $0, 0xc(%esi)\n" /* line 283 */
        "je .Lf211ae9_00211ce1\n"
        "movl 0x5c(%esi, %eax, 4), %eax\n" /* line 284 */
        "movl -0x44(%ebp), %ecx\n" /* nbits */
        "addl $1, (%eax, %ecx, 4)\n"
        /* } scope */
        ".Lf211ae9_00211baa:\n"
        "movl -0x44(%ebp), %ecx\n" /* line 437 | nbits */
        "testl %ecx, %ecx\n"
        "je .Lf211ae9_00211cbd\n"
        /* { scope 2: c */
        "movl 0x1c(%esi), %edx\n" /* line 233 | put_bits */
        "cmpb $0, 0xc(%esi)\n" /* line 239 */
        "jne .Lf211ae9_00211cbd\n"
        "movl $1, %eax\n" /* line 242 */
        "movzbl -0x44(%ebp), %ecx\n" /* nbits */
        "shll %cl, %eax\n"
        "leal -1(%eax), %edi\n"
        "andl -0x48(%ebp), %edi\n" /* temp2 */
        "addl -0x44(%ebp), %edx\n" /* line 244 | nbits */
        "movl %edx, -0xc(%ebp)\n"
        "movl $0x18, %ecx\n" /* line 246 */
        "subl %edx, %ecx\n"
        "shll %cl, %edi\n"
        "orl 0x18(%esi), %edi\n" /* line 248 */
        "cmpl $7, %edx\n" /* line 250 */
        "jle .Lf211ae9_00211cb4\n"
        "jmp .Lf211ae9_00211c0a\n"
        /* { scope 3: dest, dest, size */
        ".Lf211ae9_00211bf0:\n"
        "cmpl $0xff, -0x24(%ebp)\n" /* line 254 | c */
        "je .Lf211ae9_00211c61\n"
        ".Lf211ae9_00211bf9:\n"
        "shll $8, %edi\n" /* line 257 */
        "subl $8, -0xc(%ebp)\n" /* line 258 */
        /* } scope */
        "cmpl $7, -0xc(%ebp)\n" /* line 250 */
        "jle .Lf211ae9_00211cb4\n"
        /* { scope 3: dest, dest, size */
        ".Lf211ae9_00211c0a:\n"
        "movl %edi, %eax\n" /* line 251 */
        "sarl $0x10, %eax\n"
        "andl $0xff, %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* c */
        "movl 0x10(%esi), %eax\n" /* line 253 */
        "movzbl -0x24(%ebp), %edx\n" /* c */
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0x14(%esi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%esi)\n"
        "testl %eax, %eax\n"
        "jne .Lf211ae9_00211bf0\n"
        /* { scope 4: put_buffer, put_bits */
        "movl 0x20(%esi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %ecx\n"
        "movl %ecx, -0x20(%ebp)\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf211ae9_00211ed7\n"
        ".Lf211ae9_00211c4a:\n"
        "movl -0x20(%ebp), %edx\n" /* line 213 | dest */
        "movl (%edx), %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%esi)\n"
        /* } scope */
        "cmpl $0xff, -0x24(%ebp)\n" /* line 254 | c */
        "jne .Lf211ae9_00211bf9\n"
        ".Lf211ae9_00211c61:\n"
        "movl 0x10(%esi), %eax\n" /* line 255 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0x14(%esi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%esi)\n"
        "testl %eax, %eax\n"
        "jne .Lf211ae9_00211bf9\n"
        /* { scope 4: put_buffer, put_bits */
        "movl 0x20(%esi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf211ae9_00211f01\n"
        ".Lf211ae9_00211c95:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 213 | dest */
        "movl (%edx), %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%esi)\n"
        /* } scope */
        "shll $8, %edi\n" /* line 257 */
        "subl $8, -0xc(%ebp)\n" /* line 258 */
        /* } scope */
        "cmpl $7, -0xc(%ebp)\n" /* line 250 */
        "jg .Lf211ae9_00211c0a\n"
        ".Lf211ae9_00211cb4:\n"
        "movl %edi, 0x18(%esi)\n" /* line 261 */
        "movl -0xc(%ebp), %ecx\n" /* line 262 */
        "movl %ecx, 0x1c(%esi)\n"
        ".Lf211ae9_00211cbd:\n"
        "movl -0x18(%ebp), %eax\n"
        "addl $1, -0x18(%ebp)\n"
        "addl $4, -0x14(%ebp)\n"
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 397 | cinfo */
        "cmpl 0x104(%edx), %eax\n"
        "jge .Lf211ae9_00211e73\n"
        "movl -0x14(%ebp), %ecx\n"
        "movl %edx, %eax\n"
        "jmp .Lf211ae9_00211b4b\n"
        /* { scope 2: c */
        /* { scope 3: dest, dest, size */
        ".Lf211ae9_00211ce1:\n"
        "movl 0x4c(%esi, %eax, 4), %eax\n" /* line 286 | tbl */
        "movl -0x44(%ebp), %ecx\n" /* line 287 | nbits */
        "movzbl 0x400(%ecx, %eax), %edx\n"
        "movsbl %dl, %ecx\n"
        "movl %ecx, -0x3c(%ebp)\n" /* size */
        /* { scope 4: put_buffer, put_bits */
        /* { scope 5: c */
        "movl -0x44(%ebp), %ecx\n" /* line 232 | nbits */
        "movl (%eax, %ecx, 4), %eax\n"
        "movl %eax, -0x38(%ebp)\n" /* put_buffer */
        "movl 0x1c(%esi), %eax\n" /* line 233 */
        "movl %eax, -0x34(%ebp)\n" /* put_bits */
        "testb %dl, %dl\n" /* line 236 */
        "je .Lf211ae9_00211e58\n"
        ".Lf211ae9_00211d0d:\n"
        "cmpb $0, 0xc(%esi)\n" /* line 239 */
        "jne .Lf211ae9_00211baa\n"
        "movl $1, %eax\n" /* line 242 */
        "movzbl -0x3c(%ebp), %ecx\n" /* size */
        "shll %cl, %eax\n"
        "leal -1(%eax), %edi\n"
        "andl -0x38(%ebp), %edi\n" /* put_buffer */
        "movl -0x3c(%ebp), %eax\n" /* line 244 | size */
        "addl -0x34(%ebp), %eax\n" /* put_bits */
        "movl %eax, -0x10(%ebp)\n"
        "movl $0x18, %ecx\n" /* line 246 */
        "subl %eax, %ecx\n"
        "shll %cl, %edi\n"
        "orl 0x18(%esi), %edi\n" /* line 248 */
        "cmpl $7, %eax\n" /* line 250 */
        "jle .Lf211ae9_00211e0c\n"
        "jmp .Lf211ae9_00211d62\n"
        /* { scope 6: dest, dest */
        ".Lf211ae9_00211d48:\n"
        "cmpl $0xff, -0x30(%ebp)\n" /* line 254 | c */
        "je .Lf211ae9_00211db9\n"
        ".Lf211ae9_00211d51:\n"
        "shll $8, %edi\n" /* line 257 */
        "subl $8, -0x10(%ebp)\n" /* line 258 */
        /* } scope */
        "cmpl $7, -0x10(%ebp)\n" /* line 250 */
        "jle .Lf211ae9_00211e0c\n"
        /* { scope 6: dest, dest */
        ".Lf211ae9_00211d62:\n"
        "movl %edi, %eax\n" /* line 251 */
        "sarl $0x10, %eax\n"
        "andl $0xff, %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* c */
        "movl 0x10(%esi), %eax\n" /* line 253 */
        "movzbl -0x30(%ebp), %edx\n" /* c */
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0x14(%esi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%esi)\n"
        "testl %eax, %eax\n"
        "jne .Lf211ae9_00211d48\n"
        /* { scope 7 */
        "movl 0x20(%esi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %ecx\n"
        "movl %ecx, -0x2c(%ebp)\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf211ae9_00211ebc\n"
        ".Lf211ae9_00211da2:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 213 | dest */
        "movl (%edx), %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%esi)\n"
        /* } scope */
        "cmpl $0xff, -0x30(%ebp)\n" /* line 254 | c */
        "jne .Lf211ae9_00211d51\n"
        ".Lf211ae9_00211db9:\n"
        "movl 0x10(%esi), %eax\n" /* line 255 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0x14(%esi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%esi)\n"
        "testl %eax, %eax\n"
        "jne .Lf211ae9_00211d51\n"
        /* { scope 7 */
        "movl 0x20(%esi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %ecx\n"
        "movl %ecx, -0x28(%ebp)\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf211ae9_00211f1c\n"
        ".Lf211ae9_00211ded:\n"
        "movl -0x28(%ebp), %edx\n" /* line 213 | dest */
        "movl (%edx), %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%esi)\n"
        /* } scope */
        "shll $8, %edi\n" /* line 257 */
        "subl $8, -0x10(%ebp)\n" /* line 258 */
        /* } scope */
        "cmpl $7, -0x10(%ebp)\n" /* line 250 */
        "jg .Lf211ae9_00211d62\n"
        ".Lf211ae9_00211e0c:\n"
        "movl %edi, 0x18(%esi)\n" /* line 261 */
        "movl -0x10(%ebp), %ecx\n" /* line 262 */
        "movl %ecx, 0x1c(%esi)\n"
        "jmp .Lf211ae9_00211baa\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf211ae9_00211e1a:\n"
        "movl $0, -0x44(%ebp)\n" /* line 422 | nbits */
        ".Lf211ae9_00211e21:\n"
        "addl $1, -0x44(%ebp)\n" /* line 423 | nbits */
        "sarl $1, %ecx\n" /* line 422 */
        "jne .Lf211ae9_00211e21\n"
        "cmpl $0xb, -0x44(%ebp)\n" /* line 429 | nbits */
        "jle .Lf211ae9_00211b92\n"
        "movl 8(%ebp), %edx\n" /* line 430 | cinfo */
        "movl (%edx), %eax\n"
        "movl $6, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf211ae9_00211b92\n"
        ".Lf211ae9_00211e4b:\n"
        "leal -1(%ecx), %eax\n" /* line 417 */
        "movl %eax, -0x48(%ebp)\n" /* temp2 */
        "negl %ecx\n"
        "jmp .Lf211ae9_00211b83\n"
        /* { scope 2: c */
        /* { scope 3: dest, dest, size */
        /* { scope 4: put_buffer, put_bits */
        /* { scope 5: c */
        ".Lf211ae9_00211e58:\n"
        "movl 0x20(%esi), %eax\n" /* line 237 */
        "movl (%eax), %eax\n"
        "movl $0x28, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf211ae9_00211d0d\n"
        ".Lf211ae9_00211e73:\n"
        "movl %edx, %ecx\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf211ae9_00211e75:\n"
        "movl 0x20(%ecx), %edx\n" /* line 441 */
        "movl 0x10(%esi), %eax\n" /* entropy */
        "movl %eax, (%edx)\n"
        "movl 0x20(%ecx), %edx\n" /* line 442 */
        "movl 0x14(%esi), %eax\n" /* entropy */
        "movl %eax, 4(%edx)\n"
        "movl 0xc0(%ecx), %eax\n" /* line 445 */
        "testl %eax, %eax\n"
        "je .Lf211ae9_00211e9b\n"
        "movl 0x44(%esi), %edx\n" /* line 446 | entropy */
        "testl %edx, %edx\n"
        "je .Lf211ae9_00211eab\n"
        ".Lf211ae9_00211e97:\n"
        "subl $1, 0x44(%esi)\n" /* line 451 | entropy */
        ".Lf211ae9_00211e9b:\n"
        "movl $1, %eax\n" /* line 455 */
        "addl $0x60, %esp\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf211ae9_00211ea7:\n"
        "movl %eax, %ecx\n"
        "jmp .Lf211ae9_00211e75\n"
        ".Lf211ae9_00211eab:\n"
        "movl %eax, 0x44(%esi)\n" /* line 447 | entropy */
        "movl 0x48(%esi), %eax\n" /* line 449 | entropy */
        "addl $1, %eax\n"
        "andl $7, %eax\n"
        "movl %eax, 0x48(%esi)\n" /* entropy */
        "jmp .Lf211ae9_00211e97\n"
        /* { scope 2: c */
        /* { scope 3: dest, dest, size */
        /* { scope 4: put_buffer, put_bits */
        /* { scope 5: c */
        /* { scope 6: dest, dest */
        /* { scope 7 */
        ".Lf211ae9_00211ebc:\n"
        "movl 0x20(%esi), %eax\n" /* line 211 */
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf211ae9_00211da2\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c */
        /* { scope 3: dest, dest, size */
        /* { scope 4: put_buffer, put_bits */
        ".Lf211ae9_00211ed7:\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf211ae9_00211c4a\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf211ae9_00211ef2:\n"
        "movl 0x48(%esi), %edx\n" /* line 394 | entropy */
        "movl %esi, %eax\n" /* entropy */
        "calll emit_restart\n"
        "jmp .Lf211ae9_00211b2b\n"
        /* { scope 2: c */
        /* { scope 3: dest, dest, size */
        /* { scope 4: put_buffer, put_bits */
        ".Lf211ae9_00211f01:\n"
        "movl 0x20(%esi), %eax\n" /* line 211 */
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf211ae9_00211c95\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c */
        /* { scope 3: dest, dest, size */
        /* { scope 4: put_buffer, put_bits */
        /* { scope 5: c */
        /* { scope 6: dest, dest */
        /* { scope 7 */
        ".Lf211ae9_00211f1c:\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf211ae9_00211ded\n"
    );
}

/* line 465 */
static __attribute__((naked))
boolean encode_mcu_AC_first(j_compress_ptr cinfo, JBLOCKROW *MCU_data)
{
    __asm__ __volatile__ (
        /* { scope 1: put_bits */
        "pushl %ebp\n" /* line 465 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %eax\n" /* line 466 | cinfo */
        "movl 0x160(%eax), %esi\n" /* entropy */
        "movl 0x134(%eax), %edx\n" /* line 470 */
        "movl %edx, -0x74(%ebp)\n" /* Se */
        "movl 0x13c(%eax), %ecx\n" /* line 471 */
        "movl %ecx, -0x70(%ebp)\n" /* Al */
        "movl %eax, %edi\n" /* line 474 | put_buffer */
        "movl 0x20(%eax), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, 0x10(%esi)\n" /* entropy */
        "movl 0x20(%edi), %eax\n" /* line 475 | put_buffer */
        "movl 4(%eax), %eax\n"
        "movl %eax, 0x14(%esi)\n" /* entropy */
        "movl 0xc0(%edi), %eax\n" /* line 478 | put_buffer */
        "testl %eax, %eax\n"
        "je .Lf211f37_00211f8b\n"
        "movl 0x44(%esi), %eax\n" /* line 479 | entropy */
        "testl %eax, %eax\n"
        "je .Lf211f37_0021257f\n"
        ".Lf211f37_00211f8b:\n"
        "movl 0xc(%ebp), %eax\n" /* line 483 | MCU_data */
        "movl (%eax), %eax\n"
        "movl %eax, -0x6c(%ebp)\n" /* block */
        "movl 8(%ebp), %eax\n" /* line 489 | cinfo */
        "movl 0x130(%eax), %eax\n"
        "movl %eax, -0x78(%ebp)\n" /* k */
        "cmpl %eax, -0x74(%ebp)\n" /* Se */
        "jl .Lf211f37_002120e7\n"
        "movl %eax, %edx\n"
        "movl 0x174da80(%ebx), %eax\n"
        "leal (%eax, %edx, 4), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl $0, -0x7c(%ebp)\n" /* r */
        "movl %eax, %ecx\n"
        ".Lf211f37_00211fbf:\n"
        "movl (%ecx), %eax\n" /* line 490 */
        "movl -0x6c(%ebp), %edi\n" /* block, put_buffer */
        "movzwl (%edi, %eax, 2), %eax\n" /* put_buffer */
        "movswl %ax, %edx\n"
        "testw %ax, %ax\n"
        "je .Lf211f37_00212127\n"
        "testl %edx, %edx\n" /* line 499 */
        "js .Lf211f37_002124ef\n"
        "movzbl -0x70(%ebp), %ecx\n" /* line 505 | Al */
        "sarl %cl, %edx\n"
        "movl %edx, -0x88(%ebp)\n" /* temp */
        "movl %edx, -0x84(%ebp)\n" /* temp2 */
        ".Lf211f37_00211fee:\n"
        "movl -0x88(%ebp), %eax\n" /* line 509 | temp */
        "testl %eax, %eax\n"
        "je .Lf211f37_00212127\n"
        "movl 0x38(%esi), %eax\n" /* line 515 | entropy */
        "testl %eax, %eax\n"
        "jne .Lf211f37_0021250a\n"
        ".Lf211f37_00212007:\n"
        "cmpl $0xf, -0x7c(%ebp)\n" /* line 518 | r */
        "jle .Lf211f37_0021202f\n"
        ".Lf211f37_0021200d:\n"
        "movl 0x34(%esi), %eax\n" /* line 519 | entropy, tbl_no */
        /* { scope 2: c */
        "cmpb $0, 0xc(%esi)\n" /* line 283 */
        "je .Lf211f37_00212143\n"
        "movl 0x5c(%esi, %eax, 4), %eax\n" /* line 284 */
        "addl $1, 0x3c0(%eax)\n"
        /* } scope */
        ".Lf211f37_00212025:\n"
        "subl $0x10, -0x7c(%ebp)\n" /* line 520 | r */
        ".Lf211f37_00212029:\n"
        "cmpl $0xf, -0x7c(%ebp)\n" /* line 518 | r */
        "jg .Lf211f37_0021200d\n"
        ".Lf211f37_0021202f:\n"
        "movl -0x88(%ebp), %eax\n" /* line 525 | temp */
        "sarl $1, %eax\n"
        "jne .Lf211f37_002123a7\n"
        "movl $1, -0x80(%ebp)\n" /* nbits */
        ".Lf211f37_00212044:\n"
        "shll $4, -0x7c(%ebp)\n" /* line 532 | r */
        "movl -0x80(%ebp), %ecx\n" /* nbits, symbol */
        "addl -0x7c(%ebp), %ecx\n" /* r, symbol */
        "movl 0x34(%esi), %eax\n" /* entropy, tbl_no */
        /* { scope 2: c */
        "cmpb $0, 0xc(%esi)\n" /* line 283 */
        "je .Lf211f37_0021234b\n"
        "movl 0x5c(%esi, %eax, 4), %eax\n" /* line 284 */
        "addl $1, (%eax, %ecx, 4)\n"
        "movl 0x1c(%esi), %edi\n" /* put_buffer */
        /* } scope */
        /* { scope 2: c */
        ".Lf211f37_00212066:\n"
        "movl %edi, -0x3c(%ebp)\n" /* line 233 | put_buffer, put_bits */
        "movl -0x80(%ebp), %edi\n" /* line 236 | nbits, put_buffer */
        "testl %edi, %edi\n" /* put_buffer */
        "je .Lf211f37_0021238c\n"
        ".Lf211f37_00212074:\n"
        "cmpb $0, 0xc(%esi)\n" /* line 239 */
        "jne .Lf211f37_002120b5\n"
        "movl $1, %eax\n" /* line 242 */
        "movzbl -0x80(%ebp), %ecx\n" /* nbits */
        "shll %cl, %eax\n"
        "leal -1(%eax), %edi\n" /* put_buffer */
        "andl -0x84(%ebp), %edi\n" /* temp2, put_buffer */
        "movl -0x80(%ebp), %eax\n" /* line 244 | nbits */
        "addl -0x3c(%ebp), %eax\n" /* put_bits */
        "movl %eax, -0x1c(%ebp)\n"
        "movl $0x18, %ecx\n" /* line 246 */
        "subl %eax, %ecx\n"
        "shll %cl, %edi\n" /* put_buffer */
        "orl 0x18(%esi), %edi\n" /* line 248 | put_buffer */
        "cmpl $7, %eax\n" /* line 250 */
        "jg .Lf211f37_002122bb\n"
        ".Lf211f37_002120ac:\n"
        "movl %edi, 0x18(%esi)\n" /* line 261 | put_buffer */
        "movl -0x1c(%ebp), %ecx\n" /* line 262 */
        "movl %ecx, 0x1c(%esi)\n"
        ".Lf211f37_002120b5:\n"
        "movl $0, -0x7c(%ebp)\n" /* r */
        /* } scope */
        "addl $1, -0x78(%ebp)\n" /* line 489 | k */
        "addl $4, -0x2c(%ebp)\n"
        "movl -0x78(%ebp), %edi\n" /* k, put_buffer */
        "cmpl %edi, -0x74(%ebp)\n" /* put_buffer, Se */
        "jge .Lf211f37_0021213b\n"
        ".Lf211f37_002120cc:\n"
        "movl -0x7c(%ebp), %ecx\n" /* line 541 | r */
        "testl %ecx, %ecx\n"
        "jle .Lf211f37_002120e7\n"
        "movl 0x38(%esi), %eax\n" /* line 542 | entropy */
        "addl $1, %eax\n"
        "movl %eax, 0x38(%esi)\n" /* entropy */
        "cmpl $0x7fff, %eax\n" /* line 543 */
        "je .Lf211f37_0021258e\n"
        ".Lf211f37_002120e7:\n"
        "movl 8(%ebp), %eax\n" /* line 547 | cinfo */
        "movl 0x20(%eax), %edx\n"
        "movl 0x10(%esi), %eax\n" /* entropy */
        "movl %eax, (%edx)\n"
        "movl 8(%ebp), %ecx\n" /* line 548 | cinfo */
        "movl 0x20(%ecx), %edx\n"
        "movl 0x14(%esi), %eax\n" /* entropy */
        "movl %eax, 4(%edx)\n"
        "movl 0xc0(%ecx), %eax\n" /* line 551 */
        "testl %eax, %eax\n"
        "je .Lf211f37_00212117\n"
        "movl 0x44(%esi), %edx\n" /* line 552 | entropy */
        "testl %edx, %edx\n"
        "je .Lf211f37_002123f3\n"
        ".Lf211f37_00212113:\n"
        "subl $1, 0x44(%esi)\n" /* line 557 | entropy */
        ".Lf211f37_00212117:\n"
        "movl $1, %eax\n" /* line 561 */
        "addl $0x8c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf211f37_00212127:\n"
        "addl $1, -0x7c(%ebp)\n" /* line 510 | r */
        "addl $1, -0x78(%ebp)\n" /* line 489 | k */
        "addl $4, -0x2c(%ebp)\n"
        "movl -0x78(%ebp), %edi\n" /* k, put_buffer */
        "cmpl %edi, -0x74(%ebp)\n" /* put_buffer, Se */
        "jl .Lf211f37_002120cc\n"
        ".Lf211f37_0021213b:\n"
        "movl -0x2c(%ebp), %ecx\n"
        "jmp .Lf211f37_00211fbf\n"
        /* { scope 2: c */
        /* { scope 3: size, dest, dest, size */
        ".Lf211f37_00212143:\n"
        "movl 0x4c(%esi, %eax, 4), %eax\n" /* line 286 | tbl */
        "movzbl 0x4f0(%eax), %edx\n" /* line 287 */
        "movsbl %dl, %edi\n" /* put_buffer */
        "movl %edi, -0x68(%ebp)\n" /* put_buffer, size */
        /* { scope 4: put_bits, put_buffer, put_bits */
        /* { scope 5: c, c */
        "movl 0x3c0(%eax), %eax\n" /* line 232 */
        "movl %eax, -0x28(%ebp)\n"
        "movl 0x1c(%esi), %eax\n" /* line 233 */
        "movl %eax, -0x24(%ebp)\n"
        "testb %dl, %dl\n" /* line 236 */
        "je .Lf211f37_00212330\n"
        ".Lf211f37_0021216b:\n"
        "cmpb $0, 0xc(%esi)\n" /* line 239 */
        "jne .Lf211f37_00212025\n"
        "movl $1, %eax\n" /* line 242 */
        "movzbl -0x68(%ebp), %ecx\n" /* size */
        "shll %cl, %eax\n"
        "leal -1(%eax), %edi\n" /* put_buffer */
        "andl -0x28(%ebp), %edi\n" /* put_buffer */
        "movl -0x68(%ebp), %eax\n" /* line 244 | size */
        "addl -0x24(%ebp), %eax\n"
        "movl %eax, -0x64(%ebp)\n" /* put_bits */
        "movl $0x18, %ecx\n" /* line 246 */
        "subl %eax, %ecx\n"
        "shll %cl, %edi\n" /* put_buffer */
        "orl 0x18(%esi), %edi\n" /* line 248 | put_buffer */
        "cmpl $7, %eax\n" /* line 250 */
        "jle .Lf211f37_0021226a\n"
        "jmp .Lf211f37_002121c0\n"
        /* { scope 6: dest, dest, dest, dest */
        ".Lf211f37_002121a6:\n"
        "cmpl $0xff, -0x60(%ebp)\n" /* line 254 | c */
        "je .Lf211f37_00212217\n"
        ".Lf211f37_002121af:\n"
        "shll $8, %edi\n" /* line 257 | put_buffer */
        "subl $8, -0x64(%ebp)\n" /* line 258 | put_bits */
        /* } scope */
        "cmpl $7, -0x64(%ebp)\n" /* line 250 | put_bits */
        "jle .Lf211f37_0021226a\n"
        /* { scope 6: dest, dest, dest, dest */
        ".Lf211f37_002121c0:\n"
        "movl %edi, %eax\n" /* line 251 | put_buffer */
        "sarl $0x10, %eax\n"
        "andl $0xff, %eax\n"
        "movl %eax, -0x60(%ebp)\n" /* c */
        "movl 0x10(%esi), %eax\n" /* line 253 */
        "movzbl -0x60(%ebp), %edx\n" /* c */
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0x14(%esi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%esi)\n"
        "testl %eax, %eax\n"
        "jne .Lf211f37_002121a6\n"
        /* { scope 7 */
        "movl 0x20(%esi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %ecx\n"
        "movl %ecx, -0x5c(%ebp)\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf211f37_002123d8\n"
        ".Lf211f37_00212200:\n"
        "movl -0x5c(%ebp), %edx\n" /* line 213 | dest */
        "movl (%edx), %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%esi)\n"
        /* } scope */
        "cmpl $0xff, -0x60(%ebp)\n" /* line 254 | c */
        "jne .Lf211f37_002121af\n"
        ".Lf211f37_00212217:\n"
        "movl 0x10(%esi), %eax\n" /* line 255 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0x14(%esi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%esi)\n"
        "testl %eax, %eax\n"
        "jne .Lf211f37_002121af\n"
        /* { scope 7 */
        "movl 0x20(%esi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %ecx\n"
        "movl %ecx, -0x58(%ebp)\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf211f37_00212556\n"
        "movl -0x58(%ebp), %edx\n" /* line 213 | dest */
        "movl (%edx), %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%esi)\n"
        /* } scope */
        ".Lf211f37_00212259:\n"
        "shll $8, %edi\n" /* line 257 | put_buffer */
        "subl $8, -0x64(%ebp)\n" /* line 258 | put_bits */
        /* } scope */
        "cmpl $7, -0x64(%ebp)\n" /* line 250 | put_bits */
        "jg .Lf211f37_002121c0\n"
        ".Lf211f37_0021226a:\n"
        "movl %edi, 0x18(%esi)\n" /* line 261 | put_buffer */
        "movl -0x64(%ebp), %ecx\n" /* line 262 | put_bits */
        "movl %ecx, 0x1c(%esi)\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        "subl $0x10, -0x7c(%ebp)\n" /* line 520 | r */
        "jmp .Lf211f37_00212029\n"
        /* { scope 2: c */
        /* { scope 3: size, dest, dest, size */
        /* { scope 4: put_bits, put_buffer, put_bits */
        ".Lf211f37_0021227c:\n"
        "movl 0x20(%esi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %ecx\n"
        "movl %ecx, -0x34(%ebp)\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf211f37_00212516\n"
        ".Lf211f37_00212293:\n"
        "movl -0x34(%ebp), %edx\n" /* line 213 | dest */
        "movl (%edx), %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%esi)\n"
        /* } scope */
        "cmpl $0xff, -0x38(%ebp)\n" /* line 254 | c */
        "je .Lf211f37_002122ed\n"
        ".Lf211f37_002122aa:\n"
        "shll $8, %edi\n" /* line 257 | put_buffer */
        "subl $8, -0x1c(%ebp)\n" /* line 258 */
        /* } scope */
        "cmpl $7, -0x1c(%ebp)\n" /* line 250 */
        "jle .Lf211f37_002120ac\n"
        /* { scope 3: size, dest, dest, size */
        ".Lf211f37_002122bb:\n"
        "movl %edi, %eax\n" /* line 251 | put_buffer */
        "sarl $0x10, %eax\n"
        "andl $0xff, %eax\n"
        "movl %eax, -0x38(%ebp)\n" /* c */
        "movl 0x10(%esi), %eax\n" /* line 253 */
        "movzbl -0x38(%ebp), %edx\n" /* c */
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0x14(%esi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%esi)\n"
        "testl %eax, %eax\n"
        "je .Lf211f37_0021227c\n"
        "cmpl $0xff, -0x38(%ebp)\n" /* line 254 | c */
        "jne .Lf211f37_002122aa\n"
        ".Lf211f37_002122ed:\n"
        "movl 0x10(%esi), %eax\n" /* line 255 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0x14(%esi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%esi)\n"
        "testl %eax, %eax\n"
        "jne .Lf211f37_002122aa\n"
        /* { scope 4: put_bits, put_buffer, put_bits */
        "movl 0x20(%esi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %ecx\n"
        "movl %ecx, -0x30(%ebp)\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf211f37_0021259a\n"
        ".Lf211f37_0021231d:\n"
        "movl -0x30(%ebp), %edx\n" /* line 213 | dest */
        "movl (%edx), %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%esi)\n"
        "jmp .Lf211f37_002122aa\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c */
        /* { scope 3: size, dest, dest, size */
        /* { scope 4: put_bits, put_buffer, put_bits */
        /* { scope 5: c, c */
        ".Lf211f37_00212330:\n"
        "movl 0x20(%esi), %eax\n" /* line 237 */
        "movl (%eax), %eax\n"
        "movl $0x28, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf211f37_0021216b\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c */
        /* { scope 3: size, dest, dest, size */
        ".Lf211f37_0021234b:\n"
        "movl 0x4c(%esi, %eax, 4), %eax\n" /* line 286 | tbl */
        "movzbl 0x400(%ecx, %eax), %edx\n" /* line 287 */
        "movsbl %dl, %edi\n" /* put_buffer */
        "movl %edi, -0x54(%ebp)\n" /* put_buffer, size */
        /* { scope 4: put_bits, put_buffer, put_bits */
        /* { scope 5: c, c */
        "movl (%eax, %ecx, 4), %ecx\n" /* line 232 */
        "movl %ecx, -0x50(%ebp)\n" /* put_buffer */
        "movl 0x1c(%esi), %eax\n" /* line 233 */
        "movl %eax, -0x4c(%ebp)\n" /* put_bits */
        "testb %dl, %dl\n" /* line 236 */
        "je .Lf211f37_00212531\n"
        "cmpb $0, 0xc(%esi)\n" /* line 239 */
        "je .Lf211f37_00212407\n"
        ".Lf211f37_0021237b:\n"
        "movl 0x1c(%esi), %edi\n" /* put_buffer */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c */
        "movl %edi, -0x3c(%ebp)\n" /* line 233 | put_buffer, put_bits */
        "movl -0x80(%ebp), %edi\n" /* line 236 | nbits, put_buffer */
        "testl %edi, %edi\n" /* put_buffer */
        "jne .Lf211f37_00212074\n"
        ".Lf211f37_0021238c:\n"
        "movl 0x20(%esi), %eax\n" /* line 237 */
        "movl (%eax), %eax\n"
        "movl $0x28, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf211f37_00212074\n"
        /* } scope */
        ".Lf211f37_002123a7:\n"
        "movl $1, -0x80(%ebp)\n" /* line 525 | nbits */
        ".Lf211f37_002123ae:\n"
        "addl $1, -0x80(%ebp)\n" /* line 526 | nbits */
        "sarl $1, %eax\n" /* line 525 */
        "jne .Lf211f37_002123ae\n"
        "cmpl $0xa, -0x80(%ebp)\n" /* line 528 | nbits */
        "jle .Lf211f37_00212044\n"
        "movl 8(%ebp), %edi\n" /* line 529 | cinfo, put_buffer */
        "movl (%edi), %eax\n" /* put_buffer */
        "movl $6, 0x14(%eax)\n"
        "movl (%edi), %eax\n" /* put_buffer */
        "movl %edi, (%esp)\n" /* put_buffer */
        "calll *(%eax)\n"
        "jmp .Lf211f37_00212044\n"
        /* { scope 2: c */
        /* { scope 3: size, dest, dest, size */
        /* { scope 4: put_bits, put_buffer, put_bits */
        /* { scope 5: c, c */
        /* { scope 6: dest, dest, dest, dest */
        /* { scope 7 */
        ".Lf211f37_002123d8:\n"
        "movl 0x20(%esi), %eax\n" /* line 211 */
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf211f37_00212200\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf211f37_002123f3:\n"
        "movl %eax, 0x44(%esi)\n" /* line 553 | entropy */
        "movl 0x48(%esi), %eax\n" /* line 555 | entropy */
        "addl $1, %eax\n"
        "andl $7, %eax\n"
        "movl %eax, 0x48(%esi)\n" /* entropy */
        "jmp .Lf211f37_00212113\n"
        /* { scope 2: c */
        /* { scope 3: size, dest, dest, size */
        /* { scope 4: put_bits, put_buffer, put_bits */
        /* { scope 5: c, c */
        ".Lf211f37_00212407:\n"
        "movl $1, %eax\n" /* line 242 */
        "movzbl -0x54(%ebp), %ecx\n" /* size */
        "shll %cl, %eax\n"
        "leal -1(%eax), %edi\n" /* put_buffer */
        "andl -0x50(%ebp), %edi\n" /* put_buffer */
        "movl -0x54(%ebp), %eax\n" /* line 244 | size */
        "addl -0x4c(%ebp), %eax\n" /* put_bits */
        "movl %eax, -0x20(%ebp)\n"
        "movl $0x18, %ecx\n" /* line 246 */
        "subl %eax, %ecx\n"
        "shll %cl, %edi\n" /* put_buffer */
        "orl 0x18(%esi), %edi\n" /* line 248 | put_buffer */
        "cmpl $7, %eax\n" /* line 250 */
        "jg .Lf211f37_0021247d\n"
        ".Lf211f37_00212432:\n"
        "movl %edi, 0x18(%esi)\n" /* line 261 | put_buffer */
        "movl -0x20(%ebp), %ecx\n" /* line 262 */
        "movl %ecx, 0x1c(%esi)\n"
        "movl %ecx, %edi\n" /* put_buffer */
        "jmp .Lf211f37_00212066\n"
        /* { scope 6: dest, dest, dest, dest */
        /* { scope 7 */
        ".Lf211f37_00212442:\n"
        "movl 0x20(%esi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %ecx\n"
        "movl %ecx, -0x44(%ebp)\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf211f37_002125b5\n"
        ".Lf211f37_00212459:\n"
        "movl -0x44(%ebp), %edx\n" /* line 213 | dest */
        "movl (%edx), %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%esi)\n"
        /* } scope */
        "cmpl $0xff, -0x48(%ebp)\n" /* line 254 | c */
        "je .Lf211f37_002124af\n"
        ".Lf211f37_00212470:\n"
        "shll $8, %edi\n" /* line 257 | put_buffer */
        "subl $8, -0x20(%ebp)\n" /* line 258 */
        /* } scope */
        "cmpl $7, -0x20(%ebp)\n" /* line 250 */
        "jle .Lf211f37_00212432\n"
        /* { scope 6: dest, dest, dest, dest */
        ".Lf211f37_0021247d:\n"
        "movl %edi, %eax\n" /* line 251 | put_buffer */
        "sarl $0x10, %eax\n"
        "andl $0xff, %eax\n"
        "movl %eax, -0x48(%ebp)\n" /* c */
        "movl 0x10(%esi), %eax\n" /* line 253 */
        "movzbl -0x48(%ebp), %edx\n" /* c */
        "movb %dl, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0x14(%esi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%esi)\n"
        "testl %eax, %eax\n"
        "je .Lf211f37_00212442\n"
        "cmpl $0xff, -0x48(%ebp)\n" /* line 254 | c */
        "jne .Lf211f37_00212470\n"
        ".Lf211f37_002124af:\n"
        "movl 0x10(%esi), %eax\n" /* line 255 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0x14(%esi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x14(%esi)\n"
        "testl %eax, %eax\n"
        "jne .Lf211f37_00212470\n"
        /* { scope 7 */
        "movl 0x20(%esi), %eax\n" /* line 208 */
        "movl 0x20(%eax), %ecx\n"
        "movl %ecx, -0x40(%ebp)\n" /* dest */
        "movl %eax, (%esp)\n" /* line 210 */
        "calll *0xc(%ecx)\n"
        "testb %al, %al\n"
        "je .Lf211f37_002125d0\n"
        ".Lf211f37_002124df:\n"
        "movl -0x40(%ebp), %edx\n" /* line 213 | dest */
        "movl (%edx), %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%esi)\n"
        "jmp .Lf211f37_00212470\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf211f37_002124ef:\n"
        "negl %edx\n" /* line 500 */
        "movzbl -0x70(%ebp), %ecx\n" /* line 501 | Al */
        "sarl %cl, %edx\n"
        "movl %edx, -0x88(%ebp)\n" /* temp */
        "notl %edx\n" /* line 503 */
        "movl %edx, -0x84(%ebp)\n" /* temp2 */
        "jmp .Lf211f37_00211fee\n"
        ".Lf211f37_0021250a:\n"
        "movl %esi, %eax\n" /* line 516 | entropy */
        "calll emit_eobrun\n"
        "jmp .Lf211f37_00212007\n"
        /* { scope 2: c */
        /* { scope 3: size, dest, dest, size */
        /* { scope 4: put_bits, put_buffer, put_bits */
        ".Lf211f37_00212516:\n"
        "movl 0x20(%esi), %eax\n" /* line 211 */
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf211f37_00212293\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c */
        /* { scope 3: size, dest, dest, size */
        /* { scope 4: put_bits, put_buffer, put_bits */
        /* { scope 5: c, c */
        ".Lf211f37_00212531:\n"
        "movl 0x20(%esi), %eax\n" /* line 237 */
        "movl (%eax), %eax\n"
        "movl $0x28, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "cmpb $0, 0xc(%esi)\n" /* line 239 */
        "jne .Lf211f37_0021237b\n"
        "jmp .Lf211f37_00212407\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c */
        /* { scope 3: size, dest, dest, size */
        /* { scope 4: put_bits, put_buffer, put_bits */
        /* { scope 5: c, c */
        /* { scope 6: dest, dest, dest, dest */
        /* { scope 7 */
        ".Lf211f37_00212556:\n"
        "movl 0x20(%esi), %eax\n" /* line 211 */
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "movl -0x58(%ebp), %edx\n" /* line 213 | dest */
        "movl (%edx), %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 214 */
        "movl %eax, 0x14(%esi)\n"
        "jmp .Lf211f37_00212259\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf211f37_0021257f:\n"
        "movl 0x48(%esi), %edx\n" /* line 480 | entropy */
        "movl %esi, %eax\n" /* entropy */
        "calll emit_restart\n"
        "jmp .Lf211f37_00211f8b\n"
        ".Lf211f37_0021258e:\n"
        "movl %esi, %eax\n" /* line 544 | entropy */
        "calll emit_eobrun\n"
        "jmp .Lf211f37_002120e7\n"
        /* { scope 2: c */
        /* { scope 3: size, dest, dest, size */
        /* { scope 4: put_bits, put_buffer, put_bits */
        ".Lf211f37_0021259a:\n"
        "movl 0x20(%esi), %eax\n" /* line 211 */
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf211f37_0021231d\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: c */
        /* { scope 3: size, dest, dest, size */
        /* { scope 4: put_bits, put_buffer, put_bits */
        /* { scope 5: c, c */
        /* { scope 6: dest, dest, dest, dest */
        /* { scope 7 */
        ".Lf211f37_002125b5:\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf211f37_00212459\n"
        /* } scope */
        /* { scope 7 */
        ".Lf211f37_002125d0:\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl 0x20(%esi), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "jmp .Lf211f37_002124df\n"
    );
}

