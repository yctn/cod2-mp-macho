/* ASM dump from: jchuff.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jchuff.c */

#include "common_types.h"
#include "imports.h"

void jpeg_make_c_derived_tbl(j_compress_ptr cinfo, int isDC, int tblno, c_derived_tbl * *pdtbl);
static void start_pass_huff(j_compress_ptr cinfo, int gather_statistics);
static boolean encode_mcu_gather(j_compress_ptr cinfo, JBLOCKROW *MCU_data);
void jpeg_gen_optimal_table(j_compress_ptr cinfo, JHUFF_TBL *htbl, long int *freq);
static void finish_pass_gather(j_compress_ptr cinfo);
void jinit_huff_encoder(j_compress_ptr cinfo);
static void finish_pass_huff(j_compress_ptr cinfo);
static boolean encode_mcu_huff(j_compress_ptr cinfo, JBLOCKROW *MCU_data);

/* line 181 */
__attribute__((naked))
void jpeg_make_c_derived_tbl(j_compress_ptr cinfo, int isDC, int tblno, c_derived_tbl * *pdtbl)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 181 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x550, %esp\n"
        "movl 0x10(%ebp), %esi\n" /* tblno */
        "movl 0x14(%ebp), %edi\n" /* pdtbl */
        "movzbl 0xc(%ebp), %eax\n" /* isDC */
        "movb %al, -0x535(%ebp)\n" /* isDC */
        "cmpl $3, %esi\n" /* line 194 | si */
        "ja .Lf20e638_0020e93a\n"
        ".Lf20e638_0020e65c:\n"
        "cmpb $0, -0x535(%ebp)\n" /* line 196 | isDC */
        "je .Lf20e638_0020e8d9\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl 0x5c(%ecx, %esi, 4), %ecx\n"
        "movl %ecx, -0x534(%ebp)\n" /* htbl */
        "movl -0x534(%ebp), %ecx\n" /* line 198 | htbl */
        "testl %ecx, %ecx\n"
        "je .Lf20e638_0020e8f4\n"
        ".Lf20e638_0020e684:\n"
        "movl (%edi), %edx\n" /* line 202 | code */
        "testl %edx, %edx\n"
        "je .Lf20e638_0020e916\n"
        ".Lf20e638_0020e68e:\n"
        "movl (%edi), %edi\n" /* code */
        ".Lf20e638_0020e690:\n"
        "movl %edi, -0x530(%ebp)\n" /* line 206 | code, dtbl */
        "movl -0x534(%ebp), %eax\n" /* htbl */
        "movl %eax, -0x524(%ebp)\n"
        "movl $0, -0x51c(%ebp)\n"
        "movl $1, %edi\n" /* code */
        "leal -0x109(%ebp), %edx\n" /* huffsize */
        "movl %edx, -0x540(%ebp)\n"
        "movl %eax, %ecx\n"
        ".Lf20e638_0020e6bf:\n"
        "movzbl 1(%ecx), %esi\n" /* line 212 | si */
        "movl -0x51c(%ebp), %edx\n" /* line 213 */
        "leal (%esi, %edx), %eax\n" /* si */
        "cmpl $0x100, %eax\n"
        "jle .Lf20e638_0020e6e6\n"
        "movl 8(%ebp), %ecx\n" /* line 214 | cinfo */
        "movl (%ecx), %eax\n"
        "movl $8, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf20e638_0020e6e6:\n"
        "testl %esi, %esi\n" /* line 215 | si */
        "je .Lf20e638_0020e70d\n"
        "movl -0x540(%ebp), %eax\n"
        "addl -0x51c(%ebp), %eax\n"
        "xorl %edx, %edx\n"
        ".Lf20e638_0020e6f8:\n"
        "movl %edi, %ecx\n" /* line 216 | code */
        "movb %cl, (%eax)\n"
        "addl $1, -0x51c(%ebp)\n"
        "addl $1, %edx\n"
        "addl $1, %eax\n"
        "cmpl %esi, %edx\n" /* line 215 | si */
        "jne .Lf20e638_0020e6f8\n"
        ".Lf20e638_0020e70d:\n"
        "addl $1, %edi\n" /* line 211 | code */
        "addl $1, -0x524(%ebp)\n"
        "cmpl $0x11, %edi\n" /* code */
        "je .Lf20e638_0020e724\n"
        "movl -0x524(%ebp), %ecx\n"
        "jmp .Lf20e638_0020e6bf\n"
        ".Lf20e638_0020e724:\n"
        "movl -0x51c(%ebp), %eax\n" /* line 218 */
        "movb $0, -0x109(%ebp, %eax)\n"
        "movzbl -0x109(%ebp), %eax\n" /* line 225 | huffsize */
        "movsbl %al, %esi\n" /* si */
        "testb %al, %al\n" /* line 227 */
        "je .Lf20e638_0020e7b1\n"
        "movl $0, -0x52c(%ebp)\n" /* p */
        "xorw %di, %di\n" /* code */
        "movl -0x52c(%ebp), %edx\n" /* p */
        "jmp .Lf20e638_0020e76c\n"
        ".Lf20e638_0020e755:\n"
        "addl %edi, %edi\n" /* line 237 | code */
        "addl $1, %esi\n" /* line 238 | si */
        "movl -0x52c(%ebp), %ecx\n" /* line 227 | p */
        "cmpb $0, -0x109(%ebp, %ecx)\n"
        "je .Lf20e638_0020e7b1\n"
        ".Lf20e638_0020e76a:\n"
        "movl %ecx, %edx\n"
        ".Lf20e638_0020e76c:\n"
        "movsbl -0x109(%ebp, %edx), %eax\n" /* line 228 */
        "cmpl %eax, %esi\n" /* si */
        "je .Lf20e638_0020e890\n"
        ".Lf20e638_0020e77c:\n"
        "movl $1, %eax\n" /* line 235 */
        "movl %esi, %ecx\n" /* si */
        "shll %cl, %eax\n"
        "cmpl %eax, %edi\n" /* code */
        "jl .Lf20e638_0020e755\n"
        "movl 8(%ebp), %edx\n" /* line 236 | cinfo */
        "movl (%edx), %eax\n"
        "movl $8, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "addl %edi, %edi\n" /* line 237 | code */
        "addl $1, %esi\n" /* line 238 | si */
        "movl -0x52c(%ebp), %ecx\n" /* line 227 | p */
        "cmpb $0, -0x109(%ebp, %ecx)\n"
        "jne .Lf20e638_0020e76a\n"
        ".Lf20e638_0020e7b1:\n"
        "movl -0x530(%ebp), %eax\n" /* line 248 | dtbl */
        "addl $0x400, %eax\n"
        "movl $0x100, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "cmpb $1, -0x535(%ebp)\n" /* line 255 | isDC */
        "sbbl %edx, %edx\n"
        "andl $0xf0, %edx\n"
        "addl $0xf, %edx\n"
        "movl %edx, -0x528(%ebp)\n" /* maxsymbol */
        "movl -0x51c(%ebp), %eax\n" /* line 257 */
        "testl %eax, %eax\n"
        "jle .Lf20e638_0020e8cf\n"
        "movl -0x534(%ebp), %edi\n" /* htbl, code */
        "movl $0, -0x520(%ebp)\n"
        "leal -0x109(%ebp), %ecx\n" /* huffsize */
        "movl %ecx, -0x53c(%ebp)\n"
        "jmp .Lf20e638_0020e870\n"
        ".Lf20e638_0020e818:\n"
        "movl 8(%ebp), %edx\n" /* line 260 | cinfo */
        "movl (%edx), %eax\n"
        "movl $8, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl -0x530(%ebp), %edx\n" /* dtbl */
        ".Lf20e638_0020e831:\n"
        "movl -0x520(%ebp), %ecx\n" /* line 261 */
        "movl -0x510(%ebp, %ecx, 4), %eax\n"
        "movl %eax, (%edx, %esi, 4)\n"
        "movl -0x53c(%ebp), %edx\n" /* line 262 */
        "movzbl (%ecx, %edx), %eax\n"
        "movl -0x530(%ebp), %ecx\n" /* dtbl */
        "movb %al, 0x400(%esi, %ecx)\n" /* si */
        "addl $1, -0x520(%ebp)\n" /* line 257 */
        "addl $1, %edi\n" /* code */
        "movl -0x51c(%ebp), %eax\n"
        "cmpl %eax, -0x520(%ebp)\n"
        "je .Lf20e638_0020e8cf\n"
        ".Lf20e638_0020e870:\n"
        "movzbl 0x11(%edi), %esi\n" /* line 258 | code, si */
        "cmpl %esi, -0x528(%ebp)\n" /* line 259 | si, maxsymbol */
        "jl .Lf20e638_0020e818\n"
        "movl -0x530(%ebp), %eax\n" /* dtbl */
        "cmpb $0, 0x400(%esi, %eax)\n" /* si */
        "jne .Lf20e638_0020e818\n"
        "movl %eax, %edx\n"
        "jmp .Lf20e638_0020e831\n"
        ".Lf20e638_0020e890:\n"
        "leal -0x510(%ebp, %edx, 4), %ecx\n" /* line 228 */
        "leal -0x109(%ebp), %eax\n" /* huffsize */
        "movl %eax, -0x53c(%ebp)\n"
        "movl %eax, %edx\n"
        "addl -0x52c(%ebp), %edx\n" /* p */
        ".Lf20e638_0020e8ab:\n"
        "movl %edi, (%ecx)\n" /* line 229 | code */
        "addl $1, %edi\n" /* line 230 | code */
        "movsbl 1(%edx), %eax\n" /* line 228 */
        "addl $4, %ecx\n"
        "addl $1, %edx\n"
        "cmpl %eax, %esi\n" /* si */
        "je .Lf20e638_0020e8ab\n"
        "subl -0x53c(%ebp), %edx\n"
        "movl %edx, -0x52c(%ebp)\n" /* p */
        "jmp .Lf20e638_0020e77c\n"
        ".Lf20e638_0020e8cf:\n"
        "addl $0x550, %esp\n" /* line 264 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20e638_0020e8d9:\n"
        "movl 8(%ebp), %eax\n" /* line 196 | cinfo */
        "movl 0x6c(%eax, %esi, 4), %eax\n"
        "movl %eax, -0x534(%ebp)\n" /* htbl */
        "movl -0x534(%ebp), %ecx\n" /* line 198 | htbl */
        "testl %ecx, %ecx\n"
        "jne .Lf20e638_0020e684\n"
        ".Lf20e638_0020e8f4:\n"
        "movl 8(%ebp), %edx\n" /* line 199 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x32, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %esi, 0x18(%eax)\n" /* si */
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl (%edi), %edx\n" /* line 202 | code */
        "testl %edx, %edx\n"
        "jne .Lf20e638_0020e68e\n"
        ".Lf20e638_0020e916:\n"
        "movl 8(%ebp), %ecx\n" /* line 203 | cinfo */
        "movl 4(%ecx), %eax\n"
        "movl $0x500, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "movl %eax, (%edi)\n" /* code */
        "movl %eax, %edi\n" /* code */
        "jmp .Lf20e638_0020e690\n"
        ".Lf20e638_0020e93a:\n"
        "movl 8(%ebp), %edx\n" /* line 195 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x32, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %esi, 0x18(%eax)\n" /* si */
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf20e638_0020e65c\n"
    );
}

/* line 107 */
static __attribute__((naked))
void start_pass_huff(j_compress_ptr cinfo, int gather_statistics)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 107 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movzbl 0xc(%ebp), %eax\n" /* gather_statistics */
        "movb %al, -0x29(%ebp)\n" /* gather_statistics */
        "movl 8(%ebp), %edx\n" /* line 108 | cinfo */
        "movl 0x160(%edx), %edi\n" /* entropy */
        "testb %al, %al\n" /* line 112 */
        "je .Lf20e957_0020eb84\n"
        "leal 0x236(%ebx), %eax\n" /* line 114 */
        "movl %eax, 4(%edi)\n" /* entropy */
        "leal 0x77d(%ebx), %eax\n" /* line 115 */
        "movl %eax, 8(%edi)\n" /* entropy */
        ".Lf20e957_0020e98f:\n"
        "movl 8(%ebp), %eax\n" /* line 124 | cinfo */
        "movl 0xe8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf20e957_0020eaa4\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl %edi, -0x1c(%ebp)\n" /* entropy */
        "movl $0, -0x28(%ebp)\n" /* ci */
        "movl %eax, %edx\n"
        "jmp .Lf20e957_0020ea45\n"
        ".Lf20e957_0020e9b4:\n"
        "cmpl $3, %esi\n" /* line 132 | dctbl */
        "ja .Lf20e957_0020eb67\n"
        ".Lf20e957_0020e9bd:\n"
        "cmpl $3, -0x24(%ebp)\n" /* line 134 | actbl */
        "ja .Lf20e957_0020eacd\n"
        "movl 0x4c(%edi, %esi, 4), %eax\n" /* line 138 | entropy */
        "testl %eax, %eax\n"
        "je .Lf20e957_0020eaf7\n"
        ".Lf20e957_0020e9d3:\n"
        "movl 0x4c(%edi, %esi, 4), %eax\n" /* entropy */
        "movl $0x404, 8(%esp)\n" /* line 142 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl -0x24(%ebp), %eax\n" /* line 143 | actbl */
        "movl 0x5c(%edi, %eax, 4), %esi\n" /* entropy, dctbl */
        "testl %esi, %esi\n" /* dctbl */
        "je .Lf20e957_0020eb3d\n"
        ".Lf20e957_0020e9fe:\n"
        "movl %eax, %edx\n"
        ".Lf20e957_0020ea00:\n"
        "movl 0x5c(%edi, %edx, 4), %eax\n" /* line 147 | entropy */
        "movl $0x404, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        ".Lf20e957_0020ea1c:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 158 */
        "movl $0, 0x14(%edx)\n"
        "addl $1, -0x28(%ebp)\n" /* line 124 | ci */
        "addl $4, -0x20(%ebp)\n"
        "addl $4, %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl -0x28(%ebp), %edx\n" /* ci */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "cmpl 0xe8(%eax), %edx\n"
        "jge .Lf20e957_0020eaa4\n"
        "movl -0x20(%ebp), %edx\n"
        ".Lf20e957_0020ea45:\n"
        "movl 0xec(%edx), %eax\n" /* line 125 */
        "movl 0x14(%eax), %esi\n" /* line 126 | dctbl */
        "movl 0x18(%eax), %eax\n" /* line 127 */
        "movl %eax, -0x24(%ebp)\n" /* actbl */
        "cmpb $0, -0x29(%ebp)\n" /* line 128 | gather_statistics */
        "jne .Lf20e957_0020e9b4\n"
        "leal 0x2c(%edi, %esi, 4), %eax\n" /* line 152 | entropy */
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* dctbl */
        "movl $1, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll jpeg_make_c_derived_tbl\n"
        "movl -0x24(%ebp), %edx\n" /* line 154 | actbl */
        "leal 0x3c(%edi, %edx, 4), %eax\n" /* entropy */
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll jpeg_make_c_derived_tbl\n"
        "jmp .Lf20e957_0020ea1c\n"
        ".Lf20e957_0020eaa4:\n"
        "movl $0, 0xc(%edi)\n" /* line 162 | entropy */
        "movl $0, 0x10(%edi)\n" /* line 163 | entropy */
        "movl 8(%ebp), %edx\n" /* line 166 | cinfo */
        "movl 0xc0(%edx), %eax\n"
        "movl %eax, 0x24(%edi)\n" /* entropy */
        "movl $0, 0x28(%edi)\n" /* line 167 | entropy */
        "addl $0x3c, %esp\n" /* line 168 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20e957_0020eacd:\n"
        "movl 8(%ebp), %edx\n" /* line 135 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x32, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl -0x24(%ebp), %edx\n" /* actbl */
        "movl %edx, 0x18(%eax)\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl 0x4c(%edi, %esi, 4), %eax\n" /* line 138 | entropy */
        "testl %eax, %eax\n"
        "jne .Lf20e957_0020e9d3\n"
        ".Lf20e957_0020eaf7:\n"
        "movl 8(%ebp), %edx\n" /* line 139 | cinfo */
        "movl 4(%edx), %eax\n"
        "movl $0x404, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl %eax, 0x4c(%edi, %esi, 4)\n" /* entropy */
        "movl $0x404, 8(%esp)\n" /* line 142 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl -0x24(%ebp), %eax\n" /* line 143 | actbl */
        "movl 0x5c(%edi, %eax, 4), %esi\n" /* entropy, dctbl */
        "testl %esi, %esi\n" /* dctbl */
        "jne .Lf20e957_0020e9fe\n"
        ".Lf20e957_0020eb3d:\n"
        "movl 8(%ebp), %edx\n" /* line 144 | cinfo */
        "movl 4(%edx), %eax\n"
        "movl $0x404, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl -0x24(%ebp), %edx\n" /* actbl */
        "movl %eax, 0x5c(%edi, %edx, 4)\n" /* entropy */
        "movl -0x24(%ebp), %edx\n" /* actbl */
        "jmp .Lf20e957_0020ea00\n"
        ".Lf20e957_0020eb67:\n"
        "movl 8(%ebp), %edx\n" /* line 133 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x32, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %esi, 0x18(%eax)\n" /* dctbl */
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf20e957_0020e9bd\n"
        ".Lf20e957_0020eb84:\n"
        "leal 0xa77(%ebx), %eax\n" /* line 120 */
        "movl %eax, 4(%edi)\n" /* entropy */
        "leal 0x90b(%ebx), %eax\n" /* line 121 */
        "movl %eax, 8(%edi)\n" /* entropy */
        "jmp .Lf20e957_0020e98f\n"
    );
}

/* line 646 */
static __attribute__((naked))
boolean encode_mcu_gather(j_compress_ptr cinfo, JBLOCKROW *MCU_data)
{
    __asm__ __volatile__ (
        /* { scope 1: ac_counts, block */
        "pushl %ebp\n" /* line 646 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %eax\n" /* line 647 | cinfo */
        "movl 0x160(%eax), %eax\n"
        "movl %eax, -0x34(%ebp)\n" /* entropy */
        "movl 8(%ebp), %edx\n" /* line 652 | cinfo */
        "movl 0xc0(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf20eb9b_0020ed7f\n"
        "movl 0x24(%eax), %edi\n" /* line 653 */
        "testl %edi, %edi\n"
        "je .Lf20eb9b_0020ed86\n"
        ".Lf20eb9b_0020ebd1:\n"
        "movl -0x34(%ebp), %ecx\n" /* line 660 | entropy */
        "subl $1, 0x24(%ecx)\n"
        "movl 8(%ebp), %edi\n" /* cinfo */
        ".Lf20eb9b_0020ebdb:\n"
        "movl 0x104(%edi), %esi\n" /* line 663 | r */
        "testl %esi, %esi\n" /* r */
        "jle .Lf20eb9b_0020ed72\n"
        "movl %edi, -0x20(%ebp)\n"
        "movl $1, -0x24(%ebp)\n"
        "movl 0xc(%ebp), %eax\n" /* MCU_data */
        "addl $4, %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl %edi, %edx\n"
        ".Lf20eb9b_0020ebfe:\n"
        "movl 0x108(%edx), %edx\n" /* line 664 */
        "movl %edx, -0x1c(%ebp)\n"
        "movl 8(%ebp), %edi\n" /* line 665 | cinfo */
        "movl 0xec(%edi, %edx, 4), %edx\n"
        "movl 0x18(%edx), %eax\n" /* line 666 */
        "movl -0x34(%ebp), %ecx\n" /* entropy */
        "movl 0x5c(%ecx, %eax, 4), %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* ac_counts */
        "movl 0x14(%edx), %eax\n"
        "movl 0x4c(%ecx, %eax, 4), %edi\n" /* dc_counts */
        "movl -0x3c(%ebp), %eax\n"
        "movl -4(%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* block */
        /* { scope 2 */
        /* { scope 3 */
        "movswl (%eax), %eax\n" /* line 581 */
        "movl -0x1c(%ebp), %edx\n"
        "subl 0x14(%ecx, %edx, 4), %eax\n"
        "js .Lf20eb9b_0020ed6b\n"
        ".Lf20eb9b_0020ec3e:\n"
        "testl %eax, %eax\n" /* line 587 */
        "je .Lf20eb9b_0020ec65\n"
        "xorl %esi, %esi\n" /* r */
        ".Lf20eb9b_0020ec44:\n"
        "addl $1, %esi\n" /* line 588 | r */
        "sarl $1, %eax\n" /* line 587 */
        "jne .Lf20eb9b_0020ec44\n"
        "cmpl $0xb, %esi\n" /* line 594 | r */
        "jle .Lf20eb9b_0020ec63\n"
        "movl 8(%ebp), %ecx\n" /* line 595 | cinfo */
        "movl (%ecx), %eax\n"
        "movl $6, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf20eb9b_0020ec63:\n"
        "movl %esi, %eax\n" /* r */
        ".Lf20eb9b_0020ec65:\n"
        "addl $1, (%edi, %eax, 4)\n" /* line 598 */
        "xorl %esi, %esi\n" /* r */
        "movl 0x1750e1f(%ebx), %edi\n"
        "movl %edi, -0x28(%ebp)\n"
        "movl %edi, %ecx\n"
        "movl -0x30(%ebp), %eax\n" /* ac_counts */
        "addl $0x3c0, %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl %edi, %edx\n"
        "jmp .Lf20eb9b_0020ec9a\n"
        ".Lf20eb9b_0020ec85:\n"
        "addl $1, %esi\n" /* line 606 | r */
        "addl $4, -0x28(%ebp)\n" /* line 627 */
        "leal 0xfc(%ecx), %eax\n" /* line 646 */
        "cmpl -0x28(%ebp), %eax\n" /* line 604 */
        "je .Lf20eb9b_0020ecfb\n"
        ".Lf20eb9b_0020ec97:\n"
        "movl -0x28(%ebp), %edx\n"
        ".Lf20eb9b_0020ec9a:\n"
        "movl 4(%edx), %eax\n" /* line 605 */
        "movl -0x2c(%ebp), %edi\n" /* block */
        "movzwl (%edi, %eax, 2), %eax\n"
        "movswl %ax, %edx\n"
        "testw %ax, %ax\n"
        "je .Lf20eb9b_0020ec85\n"
        "cmpl $0xf, %esi\n" /* line 609 | r */
        "jle .Lf20eb9b_0020ecca\n"
        "movl -0x30(%ebp), %edi\n" /* ac_counts */
        "movl 0x3c0(%edi), %eax\n"
        ".Lf20eb9b_0020ecba:\n"
        "addl $1, %eax\n" /* line 606 */
        "subl $0x10, %esi\n" /* line 611 | r */
        "cmpl $0xf, %esi\n" /* line 609 | r */
        "jg .Lf20eb9b_0020ecba\n"
        "movl -0x38(%ebp), %edi\n"
        "movl %eax, (%edi)\n"
        ".Lf20eb9b_0020ecca:\n"
        "movl %edx, %eax\n"
        "negl %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "sarl $1, %eax\n" /* line 620 */
        "jne .Lf20eb9b_0020ed3c\n"
        "movl $1, %edi\n"
        ".Lf20eb9b_0020ecdd:\n"
        "shll $4, %esi\n" /* line 627 | r */
        "leal (%esi, %edi), %eax\n" /* r */
        "movl -0x30(%ebp), %edi\n" /* ac_counts */
        "addl $1, (%edi, %eax, 4)\n"
        "xorl %esi, %esi\n" /* r */
        "addl $4, -0x28(%ebp)\n"
        "leal 0xfc(%ecx), %eax\n" /* line 646 */
        "cmpl -0x28(%ebp), %eax\n" /* line 604 */
        "jne .Lf20eb9b_0020ec97\n"
        ".Lf20eb9b_0020ecfb:\n"
        "testl %esi, %esi\n" /* line 634 | r */
        "jle .Lf20eb9b_0020ed05\n"
        "movl -0x30(%ebp), %eax\n" /* line 635 | ac_counts */
        "addl $1, (%eax)\n"
        /* } scope */
        /* } scope */
        ".Lf20eb9b_0020ed05:\n"
        "movl -0x3c(%ebp), %edx\n" /* line 669 */
        "movl -4(%edx), %eax\n"
        "movswl (%eax), %eax\n"
        "movl -0x1c(%ebp), %ecx\n"
        "movl -0x34(%ebp), %edi\n" /* entropy, dc_counts */
        "movl %eax, 0x14(%edi, %ecx, 4)\n" /* dc_counts */
        "movl -0x24(%ebp), %eax\n"
        "addl $1, -0x24(%ebp)\n"
        "addl $4, %edx\n"
        "movl %edx, -0x3c(%ebp)\n"
        "addl $4, -0x20(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 663 | cinfo */
        "cmpl %eax, 0x104(%edx)\n"
        "jle .Lf20eb9b_0020ed72\n"
        "movl -0x20(%ebp), %edx\n"
        "jmp .Lf20eb9b_0020ebfe\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf20eb9b_0020ed3c:\n"
        "movl $1, %edi\n" /* line 620 */
        ".Lf20eb9b_0020ed41:\n"
        "addl $1, %edi\n" /* line 621 */
        "sarl $1, %eax\n" /* line 620 */
        "jne .Lf20eb9b_0020ed41\n"
        "cmpl $0xa, %edi\n" /* line 623 */
        "jle .Lf20eb9b_0020ecdd\n"
        "movl 8(%ebp), %edx\n" /* line 624 | cinfo */
        "movl (%edx), %eax\n"
        "movl $6, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl 0x1750e1f(%ebx), %ecx\n"
        "jmp .Lf20eb9b_0020ecdd\n"
        ".Lf20eb9b_0020ed6b:\n"
        "negl %eax\n" /* line 581 */
        "jmp .Lf20eb9b_0020ec3e\n"
        /* } scope */
        /* } scope */
        ".Lf20eb9b_0020ed72:\n"
        "movl $1, %eax\n" /* line 673 */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20eb9b_0020ed7f:\n"
        "movl %edx, %edi\n" /* dc_counts */
        "jmp .Lf20eb9b_0020ebdb\n"
        ".Lf20eb9b_0020ed86:\n"
        "movl 8(%ebp), %ecx\n" /* line 655 | cinfo */
        "movl 0xe8(%ecx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lf20eb9b_0020edb0\n"
        "movl -0x34(%ebp), %edx\n" /* entropy */
        "xorl %eax, %eax\n"
        ".Lf20eb9b_0020ed98:\n"
        "movl $0, 0x14(%edx)\n" /* line 656 */
        "addl $1, %eax\n" /* line 655 */
        "addl $4, %edx\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "cmpl 0xe8(%ecx), %eax\n"
        "jl .Lf20eb9b_0020ed98\n"
        ".Lf20eb9b_0020edb0:\n"
        "movl 8(%ebp), %edi\n" /* line 658 | cinfo */
        "movl 0xc0(%edi), %eax\n"
        "movl -0x34(%ebp), %edx\n" /* entropy */
        "movl %eax, 0x24(%edx)\n"
        "jmp .Lf20eb9b_0020ebd1\n"
    );
}

/* line 706 */
__attribute__((naked))
void jpeg_gen_optimal_table(j_compress_ptr cinfo, JHUFF_TBL *htbl, long int *freq)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 706 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x860, %esp\n"
        "movl 0x10(%ebp), %esi\n" /* freq */
        "leal -0x29(%ebp), %eax\n" /* line 717 | bits */
        "movl %eax, -0x850(%ebp)\n"
        "cld\n"
        "xorl %eax, %eax\n"
        "movl $8, %ecx\n"
        "movl -0x850(%ebp), %edi\n"
        "rep stosl %eax, %es:(%edi)\n"
        "stosb %al, %es:(%edi)\n"
        "leal -0x430(%ebp), %edx\n" /* line 718 | codesize */
        "movl %edx, -0x84c(%ebp)\n"
        "movl $0x404, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memset\n"
        "xorl %eax, %eax\n"
        ".Lf20edc4_0020ee12:\n"
        "movl $0xffffffff, -0x834(%ebp, %eax, 4)\n" /* line 720 */
        "addl $1, %eax\n" /* line 719 */
        "cmpl $0x101, %eax\n"
        "jne .Lf20edc4_0020ee12\n"
        "movl $1, 0x400(%esi)\n" /* line 722 | freq */
        ".Lf20edc4_0020ee31:\n"
        "xorl %edx, %edx\n"
        "movl $0xffffffff, %edi\n"
        "movl $0x3b9aca00, %ecx\n"
        ".Lf20edc4_0020ee3d:\n"
        "movl (%esi, %edx, 4), %eax\n" /* line 736 | freq */
        "testl %eax, %eax\n"
        "je .Lf20edc4_0020ee4c\n"
        "cmpl %ecx, %eax\n"
        "jg .Lf20edc4_0020ee4c\n"
        "movl %edx, %edi\n"
        "movl %eax, %ecx\n"
        ".Lf20edc4_0020ee4c:\n"
        "addl $1, %edx\n" /* line 735 */
        "cmpl $0x101, %edx\n"
        "jne .Lf20edc4_0020ee3d\n"
        "xorw %dx, %dx\n"
        "movl $0x3b9aca00, %ecx\n"
        "movl $0xffffffff, -0x83c(%ebp)\n"
        ".Lf20edc4_0020ee69:\n"
        "movl (%esi, %edx, 4), %eax\n" /* line 747 | freq */
        "testl %eax, %eax\n"
        "je .Lf20edc4_0020ee80\n"
        "cmpl %ecx, %eax\n"
        "jg .Lf20edc4_0020ee80\n"
        "cmpl %edx, %edi\n"
        "je .Lf20edc4_0020ee80\n"
        "movl %eax, %ecx\n"
        "movl %edx, -0x83c(%ebp)\n"
        ".Lf20edc4_0020ee80:\n"
        "addl $1, %edx\n" /* line 746 */
        "cmpl $0x101, %edx\n"
        "jne .Lf20edc4_0020ee69\n"
        "movl -0x83c(%ebp), %eax\n" /* line 754 */
        "testl %eax, %eax\n"
        "js .Lf20edc4_0020ef1b\n"
        "leal (%esi, %edi, 4), %eax\n" /* line 758 | freq */
        "movl -0x83c(%ebp), %edx\n"
        "leal (%esi, %edx, 4), %ecx\n" /* freq */
        "movl (%eax), %edx\n"
        "addl (%ecx), %edx\n"
        "movl %edx, (%eax)\n"
        "movl $0, (%ecx)\n" /* line 759 */
        "addl $1, -0x430(%ebp, %edi, 4)\n" /* line 762 */
        "movl -0x834(%ebp, %edi, 4), %eax\n" /* line 763 */
        "testl %eax, %eax\n"
        "jns .Lf20edc4_0020eec8\n"
        "jmp .Lf20edc4_0020ef17\n"
        ".Lf20edc4_0020eec6:\n"
        "movl %edx, %eax\n"
        ".Lf20edc4_0020eec8:\n"
        "addl $1, -0x430(%ebp, %eax, 4)\n" /* line 765 */
        "movl -0x834(%ebp, %eax, 4), %edx\n" /* line 763 */
        "testl %edx, %edx\n"
        "jns .Lf20edc4_0020eec6\n"
        ".Lf20edc4_0020eedb:\n"
        "movl -0x83c(%ebp), %edx\n" /* line 768 */
        "movl %edx, -0x834(%ebp, %eax, 4)\n"
        "addl $1, -0x430(%ebp, %edx, 4)\n" /* line 771 */
        "movl -0x834(%ebp, %edx, 4), %eax\n" /* line 772 */
        "testl %eax, %eax\n"
        "js .Lf20edc4_0020ee31\n"
        ".Lf20edc4_0020eeff:\n"
        "addl $1, -0x430(%ebp, %eax, 4)\n" /* line 774 */
        "movl -0x834(%ebp, %eax, 4), %eax\n" /* line 772 */
        "testl %eax, %eax\n"
        "jns .Lf20edc4_0020eeff\n"
        "jmp .Lf20edc4_0020ee31\n"
        ".Lf20edc4_0020ef17:\n"
        "movl %edi, %eax\n" /* line 763 */
        "jmp .Lf20edc4_0020eedb\n"
        ".Lf20edc4_0020ef1b:\n"
        "movl $1, %esi\n" /* line 772 | freq */
        "movl -0x84c(%ebp), %edi\n"
        "addl $4, %edi\n"
        ".Lf20edc4_0020ef29:\n"
        "movl -4(%edi), %eax\n" /* line 780 */
        "testl %eax, %eax\n"
        "je .Lf20edc4_0020ef3e\n"
        "cmpl $0x20, %eax\n" /* line 783 */
        "jg .Lf20edc4_0020effc\n"
        ".Lf20edc4_0020ef39:\n"
        "addb $1, -0x29(%ebp, %eax)\n" /* line 786 */
        ".Lf20edc4_0020ef3e:\n"
        "addl $1, %esi\n" /* freq */
        "addl $4, %edi\n"
        "cmpl $0x102, %esi\n" /* line 779 | freq */
        "jne .Lf20edc4_0020ef29\n"
        "movl $0x20, -0x844(%ebp)\n"
        "jmp .Lf20edc4_0020ef6e\n"
        ".Lf20edc4_0020ef58:\n"
        "subl $1, %edx\n" /* line 802 */
        "movl %edx, -0x844(%ebp)\n"
        "cmpl $0x10, -0x844(%ebp)\n" /* line 801 */
        "jle .Lf20edc4_0020f02a\n"
        ".Lf20edc4_0020ef6e:\n"
        "movl -0x844(%ebp), %edx\n" /* line 802 */
        "movzbl -0x29(%ebp, %edx), %edi\n"
        "movl %edi, %eax\n"
        "testb %al, %al\n"
        "je .Lf20edc4_0020ef58\n"
        "subl $2, %edx\n"
        "movl %edx, -0x840(%ebp)\n"
        "movl -0x844(%ebp), %esi\n" /* freq */
        "subl $1, %esi\n" /* freq */
        "movl %esi, -0x848(%ebp)\n" /* freq */
        "movl %edx, %esi\n" /* freq */
        "cmpb $0, -0x29(%ebp, %esi)\n" /* line 804 */
        "jne .Lf20edc4_0020eff8\n"
        ".Lf20edc4_0020efa0:\n"
        "movl %esi, %ecx\n" /* freq */
        "movl -0x850(%ebp), %eax\n"
        "leal (%eax, %esi), %edx\n"
        "movl $0xffffffff, %esi\n" /* freq */
        ".Lf20edc4_0020efb0:\n"
        "subl $1, %ecx\n" /* line 805 */
        "movzbl (%esi, %edx), %eax\n" /* line 804 | freq */
        "subl $1, %edx\n"
        "testb %al, %al\n"
        "je .Lf20edc4_0020efb0\n"
        ".Lf20edc4_0020efbe:\n"
        "leal -2(%edi), %eax\n" /* line 807 */
        "movl -0x844(%ebp), %edx\n"
        "movb %al, -0x29(%ebp, %edx)\n"
        "movl -0x848(%ebp), %esi\n" /* line 808 | freq */
        "addb $1, -0x29(%ebp, %esi)\n"
        "addb $2, -0x28(%ecx, %ebp)\n" /* line 809 */
        "subb $1, -0x29(%ebp, %ecx)\n" /* line 810 */
        "movzbl -0x29(%ebp, %edx), %edi\n" /* line 802 */
        "movl %edi, %eax\n"
        "testb %al, %al\n"
        "je .Lf20edc4_0020f017\n"
        "movl -0x840(%ebp), %esi\n" /* freq */
        "cmpb $0, -0x29(%ebp, %esi)\n" /* line 804 */
        "je .Lf20edc4_0020efa0\n"
        ".Lf20edc4_0020eff8:\n"
        "movl %esi, %ecx\n" /* freq */
        "jmp .Lf20edc4_0020efbe\n"
        ".Lf20edc4_0020effc:\n"
        "movl 8(%ebp), %edx\n" /* line 784 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x27, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl -4(%edi), %eax\n"
        "jmp .Lf20edc4_0020ef39\n"
        ".Lf20edc4_0020f017:\n"
        "movl %esi, -0x844(%ebp)\n" /* line 802 | freq */
        "cmpl $0x10, -0x844(%ebp)\n" /* line 801 */
        "jg .Lf20edc4_0020ef6e\n"
        ".Lf20edc4_0020f02a:\n"
        "movl -0x844(%ebp), %edx\n" /* line 815 */
        "cmpb $0, -0x29(%ebp, %edx)\n"
        "jne .Lf20edc4_0020f06e\n"
        "movl -0x850(%ebp), %ecx\n"
        "addl -0x844(%ebp), %ecx\n"
        "movl -0x844(%ebp), %edx\n"
        "movl %edx, %esi\n" /* freq */
        "subl $1, %esi\n" /* freq */
        "movl %esi, -0x848(%ebp)\n" /* freq */
        ".Lf20edc4_0020f054:\n"
        "subl $1, %edx\n" /* line 816 */
        "movl -0x848(%ebp), %eax\n" /* line 815 */
        "subl -0x844(%ebp), %eax\n"
        "movzbl (%ecx, %eax), %eax\n"
        "subl $1, %ecx\n"
        "testb %al, %al\n"
        "je .Lf20edc4_0020f054\n"
        ".Lf20edc4_0020f06e:\n"
        "subb $1, -0x29(%ebp, %edx)\n" /* line 817 */
        "movl -0x29(%ebp), %eax\n" /* line 820 | bits */
        "movl 0xc(%ebp), %edx\n" /* htbl */
        "movl %eax, (%edx)\n"
        "movl -0x25(%ebp), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl -0x21(%ebp), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl -0x1d(%ebp), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "movzbl -0x19(%ebp), %eax\n"
        "movb %al, 0x10(%edx)\n"
        "movl $1, %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf20edc4_0020f09b:\n"
        "xorl %eax, %eax\n"
        "jmp .Lf20edc4_0020f0a9\n"
        ".Lf20edc4_0020f09f:\n"
        "addl $1, %eax\n" /* line 828 */
        "cmpl $0x100, %eax\n"
        "je .Lf20edc4_0020f0c6\n"
        ".Lf20edc4_0020f0a9:\n"
        "cmpl %edx, -0x430(%ebp, %eax, 4)\n" /* line 829 */
        "jne .Lf20edc4_0020f09f\n"
        "movl 0xc(%ebp), %esi\n" /* line 830 | htbl, freq */
        "movb %al, 0x11(%esi, %ecx)\n" /* freq */
        "addl $1, %ecx\n" /* line 831 */
        "addl $1, %eax\n" /* line 828 */
        "cmpl $0x100, %eax\n"
        "jne .Lf20edc4_0020f0a9\n"
        ".Lf20edc4_0020f0c6:\n"
        "addl $1, %edx\n" /* line 827 */
        "cmpl $0x21, %edx\n"
        "jne .Lf20edc4_0020f09b\n"
        "movl 0xc(%ebp), %eax\n" /* line 837 | htbl */
        "movb $0, 0x111(%eax)\n"
        "addl $0x860, %esp\n" /* line 838 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 847 */
static __attribute__((naked))
void finish_pass_gather(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 847 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 848 | cinfo */
        "movl 0x160(%eax), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* entropy */
        "movl $0, -0xc(%ebp)\n" /* line 858 | did_dc */
        "movl $0, -0x10(%ebp)\n" /* line 859 | did_ac */
        "movl 8(%ebp), %edx\n" /* line 861 | cinfo */
        "movl 0xe8(%edx), %esi\n" /* dctbl */
        "testl %esi, %esi\n" /* dctbl */
        "jle .Lf20f0e2_0020f1d8\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl $0, -0x24(%ebp)\n" /* ci */
        "movl %edx, %ecx\n"
        "jmp .Lf20f0e2_0020f1ba\n"
        ".Lf20f0e2_0020f126:\n"
        "leal (, %esi, 4), %edi\n" /* line 866 */
        "movl 8(%ebp), %eax\n" /* line 867 | cinfo */
        "movl 0x5c(%eax, %edi), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf20f0e2_0020f1df\n"
        "movl %eax, %edx\n"
        ".Lf20f0e2_0020f13e:\n"
        "movl -0x28(%ebp), %ecx\n" /* line 869 | entropy */
        "movl 0x4c(%ecx, %esi, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x5c(%edx, %edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll jpeg_gen_optimal_table\n"
        "movb $1, -0xc(%ebp, %esi)\n" /* line 870 */
        "movl -0x20(%ebp), %ecx\n" /* actbl */
        ".Lf20f0e2_0020f161:\n"
        "cmpb $0, -0x10(%ebp, %ecx)\n" /* line 872 */
        "jne .Lf20f0e2_0020f1a1\n"
        "movl %ecx, %esi\n" /* line 873 | dctbl */
        "shll $2, %esi\n" /* dctbl */
        "movl 8(%ebp), %eax\n" /* line 874 | cinfo */
        "movl 0x6c(%eax, %esi), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf20f0e2_0020f1f6\n"
        ".Lf20f0e2_0020f178:\n"
        "movl -0x20(%ebp), %ecx\n" /* line 876 | actbl */
        "movl -0x28(%ebp), %edx\n" /* entropy */
        "movl 0x5c(%edx, %ecx, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl 0x6c(%ecx, %esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll jpeg_gen_optimal_table\n"
        "movl -0x20(%ebp), %eax\n" /* line 877 | actbl */
        "movb $1, -0x10(%ebp, %eax)\n"
        ".Lf20f0e2_0020f1a1:\n"
        "addl $1, -0x24(%ebp)\n" /* line 861 | ci */
        "addl $4, -0x1c(%ebp)\n"
        "movl -0x24(%ebp), %ecx\n" /* ci */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "cmpl %ecx, 0xe8(%edx)\n"
        "jle .Lf20f0e2_0020f1d8\n"
        "movl -0x1c(%ebp), %ecx\n"
        ".Lf20f0e2_0020f1ba:\n"
        "movl 0xec(%ecx), %eax\n" /* line 862 */
        "movl 0x14(%eax), %esi\n" /* line 863 | dctbl */
        "movl 0x18(%eax), %eax\n" /* line 864 */
        "movl %eax, -0x20(%ebp)\n" /* actbl */
        "cmpb $0, -0xc(%ebp, %esi)\n" /* line 865 */
        "je .Lf20f0e2_0020f126\n"
        "movl %eax, %ecx\n"
        "jmp .Lf20f0e2_0020f161\n"
        ".Lf20f0e2_0020f1d8:\n"
        "addl $0x30, %esp\n" /* line 880 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20f0e2_0020f1df:\n"
        "movl %eax, (%esp)\n" /* line 868 */
        "calll jpeg_alloc_huff_table\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl %eax, 0x5c(%edx, %edi)\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "jmp .Lf20f0e2_0020f13e\n"
        ".Lf20f0e2_0020f1f6:\n"
        "movl %eax, (%esp)\n" /* line 875 */
        "calll jpeg_alloc_huff_table\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl %eax, 0x6c(%edx, %esi)\n"
        "jmp .Lf20f0e2_0020f178\n"
    );
}

/* line 892 */
__attribute__((naked))
void jinit_huff_encoder(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 892 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 4(%esi), %eax\n" /* line 896 | cinfo */
        "movl $0x6c, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "movl %eax, 0x160(%esi)\n" /* line 899 | cinfo */
        "leal -0x8c0(%ebx), %edx\n" /* line 900 */
        "movl %edx, (%eax)\n"
        "movl $4, %edx\n"
        ".Lf20f20a_0020f245:\n"
        "movl $0, 0x3c(%eax)\n" /* line 904 */
        "movl $0, 0x2c(%eax)\n"
        "movl $0, 0x5c(%eax)\n" /* line 906 */
        "movl $0, 0x4c(%eax)\n"
        "addl $4, %eax\n"
        "subl $1, %edx\n" /* line 903 */
        "jne .Lf20f20a_0020f245\n"
        "addl $0x10, %esp\n" /* line 909 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 534 */
static __attribute__((naked))
void finish_pass_huff(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1: c */
        "pushl %ebp\n" /* line 534 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x40, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 535 | cinfo */
        "movl 0x160(%eax), %esi\n" /* entropy */
        "movl 0x20(%eax), %eax\n" /* line 539 */
        "movl (%eax), %edx\n"
        "movl %edx, -0x24(%ebp)\n"
        "movl 4(%eax), %edi\n" /* line 540 */
        "movl 0x20(%esi), %eax\n" /* line 541 | entropy */
        "movl %eax, -0x14(%ebp)\n"
        "movl 0x1c(%esi), %edx\n" /* entropy */
        "movl %edx, -0x18(%ebp)\n"
        "movl 0x18(%esi), %eax\n" /* entropy */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0x14(%esi), %edx\n" /* entropy */
        "movl %edx, -0x20(%ebp)\n"
        "movl 0xc(%esi), %eax\n" /* entropy */
        "movl %eax, -0x10(%ebp)\n"
        "movl 0x10(%esi), %edx\n" /* entropy */
        "movl %edx, -0x28(%ebp)\n"
        "addl $7, %edx\n" /* line 315 */
        "movl %edx, -0xc(%ebp)\n"
        "movl $0x18, %ecx\n" /* line 319 */
        "subl %edx, %ecx\n"
        "movl $0x7f, -0x2c(%ebp)\n"
        "shll %cl, -0x2c(%ebp)\n"
        "orl %eax, -0x2c(%ebp)\n"
        "cmpl $7, %edx\n" /* line 321 */
        "jle .Lf20f270_0020f308\n"
        /* { scope 2: dest, dest */
        ".Lf20f270_0020f2cf:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 322 */
        "sarl $0x10, %eax\n"
        "andl $0xff, %eax\n"
        "movl %eax, -0x38(%ebp)\n" /* c */
        "movl -0x24(%ebp), %edx\n" /* line 324 */
        "movb %al, (%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x24(%ebp)\n"
        "subl $1, %edi\n"
        "je .Lf20f270_0020f355\n"
        "cmpl $0xff, -0x38(%ebp)\n" /* line 325 | c */
        "je .Lf20f270_0020f386\n"
        ".Lf20f270_0020f2fa:\n"
        "shll $8, -0x2c(%ebp)\n" /* line 328 */
        "subl $8, -0xc(%ebp)\n" /* line 329 */
        /* } scope */
        "cmpl $7, -0xc(%ebp)\n" /* line 321 */
        "jg .Lf20f270_0020f2cf\n"
        ".Lf20f270_0020f308:\n"
        "movl $0, -0x10(%ebp)\n" /* line 342 */
        "movl $0, -0x28(%ebp)\n"
        ".Lf20f270_0020f316:\n"
        "movl 8(%ebp), %edx\n" /* line 549 | cinfo */
        "movl 0x20(%edx), %eax\n"
        "movl -0x24(%ebp), %edx\n"
        "movl %edx, (%eax)\n"
        "movl 8(%ebp), %edx\n" /* line 550 | cinfo */
        "movl 0x20(%edx), %eax\n"
        "movl %edi, 4(%eax)\n"
        "movl -0x14(%ebp), %eax\n" /* line 551 */
        "movl %eax, 0x20(%esi)\n" /* entropy */
        "movl -0x18(%ebp), %edx\n"
        "movl %edx, 0x1c(%esi)\n" /* entropy */
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0x18(%esi)\n" /* entropy */
        "movl -0x20(%ebp), %edx\n"
        "movl %edx, 0x14(%esi)\n" /* entropy */
        "movl -0x10(%ebp), %eax\n"
        "movl %eax, 0xc(%esi)\n" /* entropy */
        "movl -0x28(%ebp), %edx\n"
        "movl %edx, 0x10(%esi)\n" /* entropy */
        "addl $0x40, %esp\n" /* line 552 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2: dest, dest */
        /* { scope 3 */
        ".Lf20f270_0020f355:\n"
        "movl 8(%ebp), %eax\n" /* line 281 | cinfo */
        "movl 0x20(%eax), %eax\n"
        "movl %eax, -0x34(%ebp)\n" /* dest */
        "movl 8(%ebp), %edx\n" /* line 283 | cinfo */
        "movl %edx, (%esp)\n"
        "calll *0xc(%eax)\n"
        "testb %al, %al\n"
        "je .Lf20f270_0020f3c4\n"
        "movl -0x34(%ebp), %eax\n" /* line 286 | dest */
        "movl (%eax), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl -0x34(%ebp), %edx\n" /* line 287 | dest */
        "movl 4(%edx), %edi\n"
        /* } scope */
        "cmpl $0xff, -0x38(%ebp)\n" /* line 325 | c */
        "jne .Lf20f270_0020f2fa\n"
        ".Lf20f270_0020f386:\n"
        "movl -0x24(%ebp), %eax\n" /* line 326 */
        "movb $0, (%eax)\n"
        "addl $1, %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "subl $1, %edi\n"
        "jne .Lf20f270_0020f2fa\n"
        /* { scope 3 */
        "movl 8(%ebp), %edx\n" /* line 281 | cinfo */
        "movl 0x20(%edx), %edx\n"
        "movl %edx, -0x30(%ebp)\n" /* dest */
        "movl 8(%ebp), %eax\n" /* line 283 | cinfo */
        "movl %eax, (%esp)\n"
        "calll *0xc(%edx)\n"
        "testb %al, %al\n"
        "je .Lf20f270_0020f3c4\n"
        "movl -0x30(%ebp), %edx\n" /* line 286 | dest */
        "movl (%edx), %edx\n"
        "movl %edx, -0x24(%ebp)\n"
        "movl -0x30(%ebp), %eax\n" /* line 287 | dest */
        "movl 4(%eax), %edi\n"
        "jmp .Lf20f270_0020f2fa\n"
        /* } scope */
        /* } scope */
        ".Lf20f270_0020f3c4:\n"
        "movl 8(%ebp), %edx\n" /* line 546 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x18, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf20f270_0020f316\n"
    );
}

/* line 477 */
static __attribute__((naked))
boolean encode_mcu_huff(j_compress_ptr cinfo, JBLOCKROW *MCU_data)
{
    __asm__ __volatile__ (
        /* { scope 1: actbl, block, restart_num */
        "pushl %ebp\n" /* line 477 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xec, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %eax\n" /* line 478 | cinfo */
        "movl 0x160(%eax), %eax\n"
        "movl %eax, -0xe4(%ebp)\n" /* entropy */
        "movl 8(%ebp), %edx\n" /* line 484 | cinfo */
        "movl 0x20(%edx), %eax\n"
        "movl (%eax), %ecx\n"
        "movl %ecx, -0x80(%ebp)\n"
        "movl 4(%eax), %edi\n" /* line 485 | dest */
        "movl -0xe4(%ebp), %esi\n" /* line 486 | entropy, dest */
        "movl 0xc(%esi), %ecx\n" /* dest */
        "movl %ecx, -0x34(%ebp)\n"
        "movl 0x10(%esi), %edx\n" /* dest */
        "movl %edx, -0x30(%ebp)\n"
        "movl 0x14(%esi), %eax\n" /* dest */
        "movl %eax, -0x2c(%ebp)\n"
        "movl 0x18(%esi), %eax\n" /* dest */
        "movl %eax, -0x28(%ebp)\n"
        "movl 0x1c(%esi), %eax\n" /* dest */
        "movl %eax, -0x24(%ebp)\n"
        "movl 0x20(%esi), %eax\n" /* dest */
        "movl %eax, -0x20(%ebp)\n"
        "movl %ecx, -0x70(%ebp)\n"
        "movl %edx, -0x58(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* line 490 | cinfo */
        "movl 0xc0(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf20f3dc_0020f596\n"
        "movl 0x24(%esi), %eax\n" /* line 491 | dest */
        "testl %eax, %eax\n"
        "je .Lf20f3dc_0020f638\n"
        "movl 8(%ebp), %esi\n" /* cinfo, dest */
        ".Lf20f3dc_0020f459:\n"
        "movl 0x104(%esi), %eax\n" /* line 497 | dest */
        "testl %eax, %eax\n"
        "jle .Lf20f3dc_0020f5a6\n"
        ".Lf20f3dc_0020f467:\n"
        "movl $1, -0x78(%ebp)\n"
        "movl $4, -0xe8(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        ".Lf20f3dc_0020f47b:\n"
        "movl -0xe8(%ebp), %eax\n" /* line 498 */
        "movl 0x104(%eax, %edx), %eax\n"
        "movl %eax, -0xe0(%ebp)\n" /* ci */
        "movl 0xec(%edx, %eax, 4), %edx\n" /* line 499 */
        "movl 0x18(%edx), %eax\n" /* line 500 */
        "movl -0xe4(%ebp), %esi\n" /* entropy, dctbl */
        "movl 0x3c(%esi, %eax, 4), %eax\n" /* dctbl */
        "movl %eax, -0xd4(%ebp)\n" /* actbl */
        "movl 0x14(%edx), %eax\n"
        "movl 0x2c(%esi, %eax, 4), %esi\n" /* dctbl */
        "movl -0xe8(%ebp), %ecx\n"
        "movl 0xc(%ebp), %eax\n" /* MCU_data */
        "movl -4(%ecx, %eax), %ecx\n"
        "movl %ecx, -0xd0(%ebp)\n" /* block */
        /* { scope 2: temp, r */
        /* { scope 3: size, c, size, size, ... */
        "movswl (%ecx), %eax\n" /* line 362 */
        "movl -0xe0(%ebp), %edx\n" /* line 364 | ci */
        "subl -0x2c(%ebp, %edx, 4), %eax\n"
        "js .Lf20f3dc_0020fca2\n"
        "movl %eax, -0xcc(%ebp)\n" /* temp */
        ".Lf20f3dc_0020f4db:\n"
        "testl %eax, %eax\n" /* line 373 */
        "jne .Lf20f3dc_0020f8a3\n"
        "movl $0, -0xb8(%ebp)\n" /* size */
        ".Lf20f3dc_0020f4ed:\n"
        "movl -0xb8(%ebp), %ecx\n" /* line 384 | size */
        "movzbl 0x400(%ecx, %esi), %eax\n"
        "movsbl %al, %edx\n"
        "movl %edx, -0xc4(%ebp)\n" /* size */
        /* { scope 4: put_buffer, put_buffer, put_buffer, c, ... */
        /* { scope 5: c, c, c, c */
        "movl (%esi, %ecx, 4), %esi\n" /* line 306 | dest */
        "movl %esi, -0xc0(%ebp)\n" /* dest, put_buffer */
        "testb %al, %al\n" /* line 310 */
        "je .Lf20f3dc_0020f900\n"
        ".Lf20f3dc_0020f515:\n"
        "movl $1, %eax\n" /* line 313 */
        "movzbl -0xc4(%ebp), %ecx\n" /* size */
        "shll %cl, %eax\n"
        "leal -1(%eax), %esi\n" /* dest */
        "andl -0xc0(%ebp), %esi\n" /* put_buffer, dest */
        "movl -0xc4(%ebp), %eax\n" /* line 315 | size */
        "addl -0x58(%ebp), %eax\n"
        "movl %eax, -0x6c(%ebp)\n"
        "movl $0x18, %ecx\n" /* line 319 */
        "subl %eax, %ecx\n"
        "shll %cl, %esi\n" /* dest */
        "orl -0x70(%ebp), %esi\n" /* dest */
        "cmpl $7, %eax\n" /* line 321 */
        "jle .Lf20f3dc_0020f771\n"
        /* { scope 6 */
        ".Lf20f3dc_0020f54d:\n"
        "movl %esi, %eax\n" /* line 322 | dest */
        "sarl $0x10, %eax\n"
        "andl $0xff, %eax\n"
        "movl %eax, -0xbc(%ebp)\n" /* c */
        "movl -0x80(%ebp), %edx\n" /* line 324 */
        "movb %al, (%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x80(%ebp)\n"
        "subl $1, %edi\n" /* dest */
        "je .Lf20f3dc_0020f750\n"
        "cmpl $0xff, -0xbc(%ebp)\n" /* line 325 | c */
        "je .Lf20f3dc_0020fb22\n"
        ".Lf20f3dc_0020f581:\n"
        "shll $8, %esi\n" /* line 328 | dest */
        "subl $8, -0x6c(%ebp)\n" /* line 329 */
        /* } scope */
        "cmpl $7, -0x6c(%ebp)\n" /* line 321 */
        "jg .Lf20f3dc_0020f54d\n"
        "movl -0x6c(%ebp), %edx\n"
        "jmp .Lf20f3dc_0020f773\n"
        ".Lf20f3dc_0020f596:\n"
        "movl %eax, %esi\n" /* dest */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf20f3dc_0020f598:\n"
        "movl 0x104(%esi), %eax\n" /* line 497 | dest */
        "testl %eax, %eax\n"
        "jg .Lf20f3dc_0020f467\n"
        ".Lf20f3dc_0020f5a6:\n"
        "movl 0x20(%esi), %eax\n" /* line 510 | dctbl */
        "movl -0x80(%ebp), %edx\n"
        "movl %edx, (%eax)\n"
        "movl 0x20(%esi), %eax\n" /* line 511 | dctbl */
        "movl %edi, 4(%eax)\n" /* dest */
        "movl -0x70(%ebp), %ecx\n" /* line 512 */
        "movl %ecx, -0x34(%ebp)\n"
        "movl -0x58(%ebp), %esi\n" /* dctbl */
        "movl %esi, -0x30(%ebp)\n" /* dctbl */
        "movl -0xe4(%ebp), %eax\n" /* entropy */
        "movl %ecx, 0xc(%eax)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl -0xe4(%ebp), %edx\n" /* entropy */
        "movl %eax, 0x10(%edx)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 0x14(%edx)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 0x1c(%edx)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 0x20(%edx)\n"
        "movl 8(%ebp), %ecx\n" /* line 515 | cinfo */
        "movl 0xc0(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf20f3dc_0020fb58\n"
        "movl -0xe4(%ebp), %esi\n" /* line 516 | entropy, dctbl */
        "movl 0x24(%esi), %edi\n" /* dctbl, dest */
        "testl %edi, %edi\n" /* dest */
        "jne .Lf20f3dc_0020fa77\n"
        "movl %eax, 0x24(%esi)\n" /* line 517 | dctbl */
        "movl 0x28(%esi), %eax\n" /* line 519 | dctbl */
        "addl $1, %eax\n"
        "andl $7, %eax\n"
        "movl %eax, 0x28(%esi)\n" /* dctbl */
        "movl -0xe4(%ebp), %eax\n" /* entropy */
        ".Lf20f3dc_0020f624:\n"
        "subl $1, 0x24(%eax)\n" /* line 521 */
        "movl $1, %eax\n"
        "addl $0xec, %esp\n" /* line 525 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20f3dc_0020f638:\n"
        "movl 0x28(%esi), %edx\n" /* line 492 | dest */
        "movl %edx, -0xdc(%ebp)\n" /* restart_num */
        /* { scope 2: temp, r */
        /* { scope 3: size, c, size, size, ... */
        "movl -0x58(%ebp), %ecx\n" /* line 315 */
        "addl $7, %ecx\n"
        "movl %ecx, -0x54(%ebp)\n"
        "movl $0x18, %ecx\n" /* line 319 */
        "subl -0x54(%ebp), %ecx\n"
        "movl $0x7f, -0x74(%ebp)\n"
        "shll %cl, -0x74(%ebp)\n"
        "movl -0x70(%ebp), %esi\n" /* dest */
        "orl %esi, -0x74(%ebp)\n" /* dest */
        "cmpl $7, -0x54(%ebp)\n" /* line 321 */
        "jg .Lf20f3dc_0020f6d2\n"
        ".Lf20f3dc_0020f668:\n"
        "movl $0, -0x70(%ebp)\n" /* line 342 */
        "movl $0, -0x58(%ebp)\n"
        "movl -0x80(%ebp), %edx\n" /* line 458 */
        "movb $0xff, (%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x80(%ebp)\n"
        "subl $1, %edi\n" /* dest */
        "je .Lf20f3dc_0020fddf\n"
        ".Lf20f3dc_0020f68b:\n"
        "movzbl -0xdc(%ebp), %eax\n" /* line 459 | restart_num */
        "subb $0x30, %al\n"
        "movb %al, (%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x80(%ebp)\n"
        "subl $1, %edi\n" /* dest */
        "je .Lf20f3dc_0020fe02\n"
        ".Lf20f3dc_0020f6a5:\n"
        "movl 8(%ebp), %ecx\n" /* line 462 | cinfo */
        "movl 0xe8(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf20f3dc_0020fd8a\n"
        "xorl %eax, %eax\n"
        "leal -0x3c(%ebp), %ecx\n" /* state */
        ".Lf20f3dc_0020f6bb:\n"
        "movl $0, 0x10(%ecx, %eax, 4)\n" /* line 463 */
        "addl $1, %eax\n" /* line 462 */
        "cmpl %eax, %edx\n"
        "jne .Lf20f3dc_0020f6bb\n"
        "movl 8(%ebp), %esi\n" /* cinfo, dest */
        "jmp .Lf20f3dc_0020f459\n"
        /* { scope 4: put_buffer, put_buffer, put_buffer, c, ... */
        ".Lf20f3dc_0020f6d2:\n"
        "movl -0x74(%ebp), %eax\n" /* line 322 */
        "sarl $0x10, %eax\n"
        "andl $0xff, %eax\n"
        "movl %eax, -0xd8(%ebp)\n" /* c */
        "movl -0x80(%ebp), %edx\n" /* line 324 */
        "movb %al, (%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x80(%ebp)\n"
        "subl $1, %edi\n" /* dest */
        "je .Lf20f3dc_0020f736\n"
        ".Lf20f3dc_0020f6f3:\n"
        "cmpl $0xff, -0xd8(%ebp)\n" /* line 325 | c */
        "je .Lf20f3dc_0020fb7d\n"
        ".Lf20f3dc_0020f703:\n"
        "shll $8, -0x74(%ebp)\n" /* line 328 */
        "subl $8, -0x54(%ebp)\n" /* line 329 */
        /* } scope */
        "cmpl $7, -0x54(%ebp)\n" /* line 321 */
        "jle .Lf20f3dc_0020f668\n"
        /* { scope 4: put_buffer, put_buffer, put_buffer, c, ... */
        "movl -0x74(%ebp), %eax\n" /* line 322 */
        "sarl $0x10, %eax\n"
        "andl $0xff, %eax\n"
        "movl %eax, -0xd8(%ebp)\n" /* c */
        "movl -0x80(%ebp), %edx\n" /* line 324 */
        "movb %al, (%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x80(%ebp)\n"
        "subl $1, %edi\n" /* dest */
        "jne .Lf20f3dc_0020f6f3\n"
        /* { scope 5: c, c, c, c */
        ".Lf20f3dc_0020f736:\n"
        "movl 8(%ebp), %ecx\n" /* line 281 | cinfo */
        "movl 0x20(%ecx), %esi\n" /* dest */
        "movl %ecx, (%esp)\n" /* line 283 */
        "calll *0xc(%esi)\n" /* dest */
        "testb %al, %al\n"
        "je .Lf20f3dc_0020f764\n"
        "movl (%esi), %eax\n" /* line 286 | dest */
        "movl %eax, -0x80(%ebp)\n"
        "movl 4(%esi), %edi\n" /* line 287 | dest */
        "jmp .Lf20f3dc_0020f6f3\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: temp, r */
        /* { scope 3: size, c, size, size, ... */
        /* { scope 4: put_buffer, put_buffer, put_buffer, c, ... */
        /* { scope 5: c, c, c, c */
        /* { scope 6 */
        /* { scope 7 */
        ".Lf20f3dc_0020f750:\n"
        "movl 8(%ebp), %ecx\n" /* line 281 | cinfo */
        "movl 0x20(%ecx), %edi\n" /* dest */
        "movl %ecx, (%esp)\n" /* line 283 */
        "calll *0xc(%edi)\n" /* dest */
        "testb %al, %al\n"
        "jne .Lf20f3dc_0020fb0a\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf20f3dc_0020f764:\n"
        "xorl %eax, %eax\n" /* line 521 */
        "addl $0xec, %esp\n" /* line 525 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20f3dc_0020f771:\n"
        "movl %eax, %edx\n"
        /* { scope 2: temp, r */
        /* { scope 3: size, c, size, size, ... */
        /* { scope 4: put_buffer, put_buffer, put_buffer, c, ... */
        /* { scope 5: c, c, c, c */
        ".Lf20f3dc_0020f773:\n"
        "movl %esi, -0x70(%ebp)\n" /* line 321 | dest */
        "movl %edx, -0x58(%ebp)\n"
        /* } scope */
        /* } scope */
        "movl -0xb8(%ebp), %eax\n" /* line 389 | size */
        "testl %eax, %eax\n"
        "jne .Lf20f3dc_0020fa7e\n"
        ".Lf20f3dc_0020f787:\n"
        "movl $0, -0xc8(%ebp)\n" /* line 390 | r */
        "movl 0x17505db(%ebx), %ecx\n"
        "movl %ecx, -0x7c(%ebp)\n"
        "movl %ecx, %edx\n"
        "movl %ecx, %esi\n" /* dest */
        "movl 4(%esi), %eax\n" /* line 398 | dest */
        "movl -0xd0(%ebp), %ecx\n" /* block */
        "movzwl (%ecx, %eax, 2), %eax\n"
        "movswl %ax, %esi\n" /* dest */
        "movl %esi, -0x4c(%ebp)\n" /* dest */
        "testw %ax, %ax\n"
        "jne .Lf20f3dc_0020f7eb\n"
        ".Lf20f3dc_0020f7b6:\n"
        "addl $1, -0xc8(%ebp)\n" /* line 399 | r */
        ".Lf20f3dc_0020f7bd:\n"
        "addl $4, -0x7c(%ebp)\n" /* line 430 */
        "leal 0xfc(%edx), %eax\n" /* line 477 */
        "cmpl -0x7c(%ebp), %eax\n" /* line 397 */
        "je .Lf20f3dc_0020fe4f\n"
        "movl -0x7c(%ebp), %esi\n" /* dest */
        "movl 4(%esi), %eax\n" /* line 398 | dest */
        "movl -0xd0(%ebp), %ecx\n" /* block */
        "movzwl (%ecx, %eax, 2), %eax\n"
        "movswl %ax, %esi\n" /* dest */
        "movl %esi, -0x4c(%ebp)\n" /* dest */
        "testw %ax, %ax\n"
        "je .Lf20f3dc_0020f7b6\n"
        ".Lf20f3dc_0020f7eb:\n"
        "cmpl $0xf, -0xc8(%ebp)\n" /* line 402 | r */
        "jle .Lf20f3dc_0020f996\n"
        ".Lf20f3dc_0020f7f8:\n"
        "movl -0xd4(%ebp), %edx\n" /* line 403 | actbl */
        "movzbl 0x4f0(%edx), %eax\n"
        "movsbl %al, %ecx\n"
        "movl %ecx, -0xb0(%ebp)\n" /* size */
        /* { scope 4: put_buffer, put_buffer, put_buffer, c, ... */
        /* { scope 5: c, c, c, c */
        "movl 0x3c0(%edx), %esi\n" /* line 306 | dest */
        "movl %esi, -0xac(%ebp)\n" /* dest, put_buffer */
        "testb %al, %al\n" /* line 310 */
        "je .Lf20f3dc_0020fb65\n"
        ".Lf20f3dc_0020f822:\n"
        "movl $1, %eax\n" /* line 313 */
        "movzbl -0xb0(%ebp), %ecx\n" /* size */
        "shll %cl, %eax\n"
        "leal -1(%eax), %esi\n" /* dest */
        "andl -0xac(%ebp), %esi\n" /* put_buffer, dest */
        "movl -0xb0(%ebp), %eax\n" /* line 315 | size */
        "addl -0x58(%ebp), %eax\n"
        "movl %eax, -0x64(%ebp)\n"
        "movl $0x18, %ecx\n" /* line 319 */
        "subl %eax, %ecx\n"
        "shll %cl, %esi\n" /* dest */
        "orl -0x70(%ebp), %esi\n" /* dest */
        "cmpl $7, %eax\n" /* line 321 */
        "jle .Lf20f3dc_0020f97a\n"
        /* { scope 6 */
        ".Lf20f3dc_0020f85a:\n"
        "movl %esi, %eax\n" /* line 322 | dest */
        "sarl $0x10, %eax\n"
        "andl $0xff, %eax\n"
        "movl %eax, -0xa8(%ebp)\n" /* c */
        "movl -0x80(%ebp), %edx\n" /* line 324 */
        "movb %al, (%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x80(%ebp)\n"
        "subl $1, %edi\n" /* dest */
        "je .Lf20f3dc_0020f918\n"
        "cmpl $0xff, -0xa8(%ebp)\n" /* line 325 | c */
        "je .Lf20f3dc_0020f944\n"
        ".Lf20f3dc_0020f88e:\n"
        "shll $8, %esi\n" /* line 328 | dest */
        "subl $8, -0x64(%ebp)\n" /* line 329 */
        /* } scope */
        "cmpl $7, -0x64(%ebp)\n" /* line 321 */
        "jg .Lf20f3dc_0020f85a\n"
        "movl -0x64(%ebp), %edx\n"
        "jmp .Lf20f3dc_0020f97c\n"
        /* } scope */
        /* } scope */
        ".Lf20f3dc_0020f8a3:\n"
        "movl $0, -0xb8(%ebp)\n" /* line 373 | size */
        ".Lf20f3dc_0020f8ad:\n"
        "addl $1, -0xb8(%ebp)\n" /* line 374 | size */
        "sarl $1, %eax\n" /* line 373 */
        "jne .Lf20f3dc_0020f8ad\n"
        "cmpl $0xb, -0xb8(%ebp)\n" /* line 380 | size */
        "jle .Lf20f3dc_0020f4ed\n"
        "movl 8(%ebp), %edx\n" /* line 381 | cinfo */
        "movl (%edx), %eax\n"
        "movl $6, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl -0xb8(%ebp), %ecx\n" /* line 384 | size */
        "movzbl 0x400(%ecx, %esi), %eax\n"
        "movsbl %al, %edx\n"
        "movl %edx, -0xc4(%ebp)\n" /* size */
        /* { scope 4: put_buffer, put_buffer, put_buffer, c, ... */
        /* { scope 5: c, c, c, c */
        "movl (%esi, %ecx, 4), %esi\n" /* line 306 | dest */
        "movl %esi, -0xc0(%ebp)\n" /* dest, put_buffer */
        "testb %al, %al\n" /* line 310 */
        "jne .Lf20f3dc_0020f515\n"
        ".Lf20f3dc_0020f900:\n"
        "movl 8(%ebp), %ecx\n" /* line 311 | cinfo */
        "movl (%ecx), %eax\n"
        "movl $0x28, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf20f3dc_0020f515\n"
        /* } scope */
        /* } scope */
        /* { scope 4: put_buffer, put_buffer, put_buffer, c, ... */
        /* { scope 5: c, c, c, c */
        /* { scope 6 */
        /* { scope 7 */
        ".Lf20f3dc_0020f918:\n"
        "movl 8(%ebp), %ecx\n" /* line 281 | cinfo */
        "movl 0x20(%ecx), %edi\n" /* dest */
        "movl %ecx, (%esp)\n" /* line 283 */
        "calll *0xc(%edi)\n" /* dest */
        "testb %al, %al\n"
        "je .Lf20f3dc_0020f764\n"
        "movl (%edi), %eax\n" /* line 286 | dest */
        "movl %eax, -0x80(%ebp)\n"
        "movl 4(%edi), %edi\n" /* line 287 | dest */
        /* } scope */
        "cmpl $0xff, -0xa8(%ebp)\n" /* line 325 | c */
        "jne .Lf20f3dc_0020f88e\n"
        ".Lf20f3dc_0020f944:\n"
        "movl -0x80(%ebp), %edx\n" /* line 326 */
        "movb $0, (%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x80(%ebp)\n"
        "subl $1, %edi\n" /* dest */
        "jne .Lf20f3dc_0020f88e\n"
        /* { scope 7 */
        "movl 8(%ebp), %ecx\n" /* line 281 | cinfo */
        "movl 0x20(%ecx), %edi\n" /* dest */
        "movl %ecx, (%esp)\n" /* line 283 */
        "calll *0xc(%edi)\n" /* dest */
        "testb %al, %al\n"
        "je .Lf20f3dc_0020f764\n"
        "movl (%edi), %eax\n" /* line 286 | dest */
        "movl %eax, -0x80(%ebp)\n"
        "movl 4(%edi), %edi\n" /* line 287 | dest */
        "jmp .Lf20f3dc_0020f88e\n"
        ".Lf20f3dc_0020f97a:\n"
        "movl %eax, %edx\n"
        /* } scope */
        /* } scope */
        ".Lf20f3dc_0020f97c:\n"
        "movl %esi, -0x70(%ebp)\n" /* line 321 | dest */
        "movl %edx, -0x58(%ebp)\n"
        /* } scope */
        /* } scope */
        "subl $0x10, -0xc8(%ebp)\n" /* line 405 | r */
        "cmpl $0xf, -0xc8(%ebp)\n" /* line 402 | r */
        "jg .Lf20f3dc_0020f7f8\n"
        ".Lf20f3dc_0020f996:\n"
        "movl -0x4c(%ebp), %eax\n" /* line 409 */
        "testl %eax, %eax\n"
        "js .Lf20f3dc_0020fe23\n"
        "movl -0x4c(%ebp), %ecx\n"
        "movl %ecx, -0x50(%ebp)\n"
        "movl %ecx, %eax\n"
        ".Lf20f3dc_0020f9a9:\n"
        "sarl $1, %eax\n" /* line 417 */
        "jne .Lf20f3dc_0020fc68\n"
        "movl $1, -0x98(%ebp)\n" /* size */
        ".Lf20f3dc_0020f9bb:\n"
        "shll $4, -0xc8(%ebp)\n" /* line 424 | r */
        "movl -0xc8(%ebp), %eax\n" /* r */
        "addl -0x98(%ebp), %eax\n" /* size */
        "movl -0xd4(%ebp), %ecx\n" /* line 425 | actbl */
        "movzbl 0x400(%eax, %ecx), %edx\n"
        "movsbl %dl, %esi\n" /* dest */
        "movl %esi, -0xa4(%ebp)\n" /* dest, size */
        /* { scope 4: put_buffer, put_buffer, put_buffer, c, ... */
        /* { scope 5: c, c, c, c */
        "movl (%ecx, %eax, 4), %eax\n" /* line 306 */
        "movl %eax, -0xa0(%ebp)\n" /* put_buffer */
        "testb %dl, %dl\n" /* line 310 */
        "je .Lf20f3dc_0020fd91\n"
        ".Lf20f3dc_0020f9f6:\n"
        "movl $1, %eax\n" /* line 313 */
        "movzbl -0xa4(%ebp), %ecx\n" /* size */
        "shll %cl, %eax\n"
        "leal -1(%eax), %esi\n" /* dest */
        "andl -0xa0(%ebp), %esi\n" /* put_buffer, dest */
        "movl -0xa4(%ebp), %eax\n" /* line 315 | size */
        "addl -0x58(%ebp), %eax\n"
        "movl %eax, -0x60(%ebp)\n"
        "movl $0x18, %ecx\n" /* line 319 */
        "subl %eax, %ecx\n"
        "shll %cl, %esi\n" /* dest */
        "orl -0x70(%ebp), %esi\n" /* dest */
        "cmpl $7, %eax\n" /* line 321 */
        "jle .Lf20f3dc_0020fbd4\n"
        /* { scope 6 */
        ".Lf20f3dc_0020fa2e:\n"
        "movl %esi, %eax\n" /* line 322 | dest */
        "sarl $0x10, %eax\n"
        "andl $0xff, %eax\n"
        "movl %eax, -0x9c(%ebp)\n" /* c */
        "movl -0x80(%ebp), %edx\n" /* line 324 */
        "movb %al, (%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x80(%ebp)\n"
        "subl $1, %edi\n" /* dest */
        "je .Lf20f3dc_0020fbb3\n"
        ".Lf20f3dc_0020fa52:\n"
        "cmpl $0xff, -0x9c(%ebp)\n" /* line 325 | c */
        "je .Lf20f3dc_0020fcb2\n"
        ".Lf20f3dc_0020fa62:\n"
        "shll $8, %esi\n" /* line 328 | dest */
        "subl $8, -0x60(%ebp)\n" /* line 329 */
        /* } scope */
        "cmpl $7, -0x60(%ebp)\n" /* line 321 */
        "jg .Lf20f3dc_0020fa2e\n"
        "movl -0x60(%ebp), %edx\n"
        "jmp .Lf20f3dc_0020fbd6\n"
        ".Lf20f3dc_0020fa77:\n"
        "movl %esi, %eax\n" /* dest */
        "jmp .Lf20f3dc_0020f624\n"
        /* } scope */
        /* } scope */
        /* { scope 4: put_buffer, put_buffer, put_buffer, c, ... */
        ".Lf20f3dc_0020fa7e:\n"
        "movl $1, %eax\n" /* line 313 */
        "movzbl -0xb8(%ebp), %ecx\n" /* size */
        "shll %cl, %eax\n"
        "leal -1(%eax), %esi\n" /* dest */
        "andl -0xcc(%ebp), %esi\n" /* temp, dest */
        "movl -0xb8(%ebp), %eax\n" /* line 315 | size */
        "addl %edx, %eax\n"
        "movl %eax, -0x84(%ebp)\n"
        "movl $0x18, %ecx\n" /* line 319 */
        "subl %eax, %ecx\n"
        "shll %cl, %esi\n" /* dest */
        "orl -0x70(%ebp), %esi\n" /* dest */
        "cmpl $7, %eax\n" /* line 321 */
        "jle .Lf20f3dc_0020fd09\n"
        /* { scope 5: c, c, c, c */
        ".Lf20f3dc_0020fab8:\n"
        "movl %esi, %eax\n" /* line 322 | dest */
        "sarl $0x10, %eax\n"
        "andl $0xff, %eax\n"
        "movl %eax, -0xb4(%ebp)\n" /* c */
        "movl -0x80(%ebp), %edx\n" /* line 324 */
        "movb %al, (%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x80(%ebp)\n"
        "subl $1, %edi\n" /* dest */
        "je .Lf20f3dc_0020fce8\n"
        ".Lf20f3dc_0020fadc:\n"
        "cmpl $0xff, -0xb4(%ebp)\n" /* line 325 | c */
        "je .Lf20f3dc_0020fd37\n"
        ".Lf20f3dc_0020faec:\n"
        "shll $8, %esi\n" /* line 328 | dest */
        "subl $8, -0x84(%ebp)\n" /* line 329 */
        /* } scope */
        "cmpl $7, -0x84(%ebp)\n" /* line 321 */
        "jg .Lf20f3dc_0020fab8\n"
        "movl -0x84(%ebp), %edx\n"
        "jmp .Lf20f3dc_0020fd0b\n"
        /* } scope */
        /* { scope 4: put_buffer, put_buffer, put_buffer, c, ... */
        /* { scope 5: c, c, c, c */
        /* { scope 6 */
        /* { scope 7 */
        ".Lf20f3dc_0020fb0a:\n"
        "movl (%edi), %eax\n" /* line 286 | dest */
        "movl %eax, -0x80(%ebp)\n"
        "movl 4(%edi), %edi\n" /* line 287 | dest */
        /* } scope */
        "cmpl $0xff, -0xbc(%ebp)\n" /* line 325 | c */
        "jne .Lf20f3dc_0020f581\n"
        ".Lf20f3dc_0020fb22:\n"
        "movl -0x80(%ebp), %edx\n" /* line 326 */
        "movb $0, (%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x80(%ebp)\n"
        "subl $1, %edi\n" /* dest */
        "jne .Lf20f3dc_0020f581\n"
        /* { scope 7 */
        "movl 8(%ebp), %ecx\n" /* line 281 | cinfo */
        "movl 0x20(%ecx), %edi\n" /* dest */
        "movl %ecx, (%esp)\n" /* line 283 */
        "calll *0xc(%edi)\n" /* dest */
        "testb %al, %al\n"
        "je .Lf20f3dc_0020f764\n"
        "movl (%edi), %eax\n" /* line 286 | dest */
        "movl %eax, -0x80(%ebp)\n"
        "movl 4(%edi), %edi\n" /* line 287 | dest */
        "jmp .Lf20f3dc_0020f581\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf20f3dc_0020fb58:\n"
        "movb $1, %al\n" /* line 515 */
        "addl $0xec, %esp\n" /* line 525 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2: temp, r */
        /* { scope 3: size, c, size, size, ... */
        /* { scope 4: put_buffer, put_buffer, put_buffer, c, ... */
        /* { scope 5: c, c, c, c */
        ".Lf20f3dc_0020fb65:\n"
        "movl 8(%ebp), %edx\n" /* line 311 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x28, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf20f3dc_0020f822\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: temp, r */
        /* { scope 3: size, c, size, size, ... */
        /* { scope 4: put_buffer, put_buffer, put_buffer, c, ... */
        ".Lf20f3dc_0020fb7d:\n"
        "movl -0x80(%ebp), %edx\n" /* line 326 */
        "movb $0, (%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x80(%ebp)\n"
        "subl $1, %edi\n" /* dest */
        "jne .Lf20f3dc_0020f703\n"
        /* { scope 5: c, c, c, c */
        "movl 8(%ebp), %ecx\n" /* line 281 | cinfo */
        "movl 0x20(%ecx), %esi\n" /* dest */
        "movl %ecx, (%esp)\n" /* line 283 */
        "calll *0xc(%esi)\n" /* dest */
        "testb %al, %al\n"
        "je .Lf20f3dc_0020f764\n"
        "movl (%esi), %eax\n" /* line 286 | dest */
        "movl %eax, -0x80(%ebp)\n"
        "movl 4(%esi), %edi\n" /* line 287 | dest */
        "jmp .Lf20f3dc_0020f703\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: temp, r */
        /* { scope 3: size, c, size, size, ... */
        /* { scope 4: put_buffer, put_buffer, put_buffer, c, ... */
        /* { scope 5: c, c, c, c */
        /* { scope 6 */
        /* { scope 7 */
        ".Lf20f3dc_0020fbb3:\n"
        "movl 8(%ebp), %ecx\n" /* line 281 | cinfo */
        "movl 0x20(%ecx), %edi\n" /* dest */
        "movl %ecx, (%esp)\n" /* line 283 */
        "calll *0xc(%edi)\n" /* dest */
        "testb %al, %al\n"
        "je .Lf20f3dc_0020f764\n"
        "movl (%edi), %eax\n" /* line 286 | dest */
        "movl %eax, -0x80(%ebp)\n"
        "movl 4(%edi), %edi\n" /* line 287 | dest */
        "jmp .Lf20f3dc_0020fa52\n"
        ".Lf20f3dc_0020fbd4:\n"
        "movl %eax, %edx\n"
        /* } scope */
        /* } scope */
        ".Lf20f3dc_0020fbd6:\n"
        "movl %esi, -0x70(%ebp)\n" /* line 321 | dest */
        "movl %edx, -0x58(%ebp)\n"
        /* } scope */
        /* } scope */
        /* { scope 4: put_buffer, put_buffer, put_buffer, c, ... */
        "movl -0x98(%ebp), %eax\n" /* line 310 | size */
        "testl %eax, %eax\n"
        "je .Lf20f3dc_0020fe37\n"
        ".Lf20f3dc_0020fbea:\n"
        "movl $1, %eax\n" /* line 313 */
        "movzbl -0x98(%ebp), %ecx\n" /* size */
        "shll %cl, %eax\n"
        "leal -1(%eax), %esi\n" /* dest */
        "andl -0x50(%ebp), %esi\n" /* dest */
        "movl -0x98(%ebp), %eax\n" /* line 315 | size */
        "addl -0x58(%ebp), %eax\n"
        "movl %eax, -0x68(%ebp)\n"
        "movl $0x18, %ecx\n" /* line 319 */
        "subl %eax, %ecx\n"
        "shll %cl, %esi\n" /* dest */
        "orl -0x70(%ebp), %esi\n" /* dest */
        "cmpl $7, %eax\n" /* line 321 */
        "jle .Lf20f3dc_0020fd6d\n"
        /* { scope 5: c, c, c, c */
        ".Lf20f3dc_0020fc1f:\n"
        "movl %esi, %eax\n" /* line 322 | dest */
        "sarl $0x10, %eax\n"
        "andl $0xff, %eax\n"
        "movl %eax, -0x94(%ebp)\n" /* c */
        "movl -0x80(%ebp), %edx\n" /* line 324 */
        "movb %al, (%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x80(%ebp)\n"
        "subl $1, %edi\n" /* dest */
        "je .Lf20f3dc_0020fd16\n"
        ".Lf20f3dc_0020fc43:\n"
        "cmpl $0xff, -0x94(%ebp)\n" /* line 325 | c */
        "je .Lf20f3dc_0020fda9\n"
        ".Lf20f3dc_0020fc53:\n"
        "shll $8, %esi\n" /* line 328 | dest */
        "subl $8, -0x68(%ebp)\n" /* line 329 */
        /* } scope */
        "cmpl $7, -0x68(%ebp)\n" /* line 321 */
        "jg .Lf20f3dc_0020fc1f\n"
        "movl -0x68(%ebp), %edx\n"
        "jmp .Lf20f3dc_0020fd6f\n"
        /* } scope */
        ".Lf20f3dc_0020fc68:\n"
        "movl $1, -0x98(%ebp)\n" /* line 417 | size */
        ".Lf20f3dc_0020fc72:\n"
        "addl $1, -0x98(%ebp)\n" /* line 418 | size */
        "sarl $1, %eax\n" /* line 417 */
        "jne .Lf20f3dc_0020fc72\n"
        "cmpl $0xa, -0x98(%ebp)\n" /* line 420 | size */
        "jle .Lf20f3dc_0020f9bb\n"
        "movl 8(%ebp), %edx\n" /* line 421 | cinfo */
        "movl (%edx), %eax\n"
        "movl $6, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf20f3dc_0020f9bb\n"
        ".Lf20f3dc_0020fca2:\n"
        "leal -1(%eax), %ecx\n" /* line 368 */
        "movl %ecx, -0xcc(%ebp)\n" /* temp */
        "negl %eax\n"
        "jmp .Lf20f3dc_0020f4db\n"
        /* { scope 4: put_buffer, put_buffer, put_buffer, c, ... */
        /* { scope 5: c, c, c, c */
        /* { scope 6 */
        ".Lf20f3dc_0020fcb2:\n"
        "movl -0x80(%ebp), %edx\n" /* line 326 */
        "movb $0, (%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x80(%ebp)\n"
        "subl $1, %edi\n" /* dest */
        "jne .Lf20f3dc_0020fa62\n"
        /* { scope 7 */
        "movl 8(%ebp), %ecx\n" /* line 281 | cinfo */
        "movl 0x20(%ecx), %edi\n" /* dest */
        "movl %ecx, (%esp)\n" /* line 283 */
        "calll *0xc(%edi)\n" /* dest */
        "testb %al, %al\n"
        "je .Lf20f3dc_0020f764\n"
        "movl (%edi), %eax\n" /* line 286 | dest */
        "movl %eax, -0x80(%ebp)\n"
        "movl 4(%edi), %edi\n" /* line 287 | dest */
        "jmp .Lf20f3dc_0020fa62\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: put_buffer, put_buffer, put_buffer, c, ... */
        /* { scope 5: c, c, c, c */
        /* { scope 6 */
        ".Lf20f3dc_0020fce8:\n"
        "movl 8(%ebp), %ecx\n" /* line 281 | cinfo */
        "movl 0x20(%ecx), %edi\n" /* dest */
        "movl %ecx, (%esp)\n" /* line 283 */
        "calll *0xc(%edi)\n" /* dest */
        "testb %al, %al\n"
        "je .Lf20f3dc_0020f764\n"
        "movl (%edi), %eax\n" /* line 286 | dest */
        "movl %eax, -0x80(%ebp)\n"
        "movl 4(%edi), %edi\n" /* line 287 | dest */
        "jmp .Lf20f3dc_0020fadc\n"
        ".Lf20f3dc_0020fd09:\n"
        "movl %eax, %edx\n"
        /* } scope */
        /* } scope */
        ".Lf20f3dc_0020fd0b:\n"
        "movl %edx, -0x58(%ebp)\n" /* line 321 */
        "movl %esi, -0x70(%ebp)\n" /* dest */
        "jmp .Lf20f3dc_0020f787\n"
        /* } scope */
        /* { scope 4: put_buffer, put_buffer, put_buffer, c, ... */
        /* { scope 5: c, c, c, c */
        /* { scope 6 */
        ".Lf20f3dc_0020fd16:\n"
        "movl 8(%ebp), %ecx\n" /* line 281 | cinfo */
        "movl 0x20(%ecx), %edi\n" /* dest */
        "movl %ecx, (%esp)\n" /* line 283 */
        "calll *0xc(%edi)\n" /* dest */
        "testb %al, %al\n"
        "je .Lf20f3dc_0020f764\n"
        "movl (%edi), %eax\n" /* line 286 | dest */
        "movl %eax, -0x80(%ebp)\n"
        "movl 4(%edi), %edi\n" /* line 287 | dest */
        "jmp .Lf20f3dc_0020fc43\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: put_buffer, put_buffer, put_buffer, c, ... */
        /* { scope 5: c, c, c, c */
        ".Lf20f3dc_0020fd37:\n"
        "movl -0x80(%ebp), %edx\n" /* line 326 */
        "movb $0, (%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x80(%ebp)\n"
        "subl $1, %edi\n" /* dest */
        "jne .Lf20f3dc_0020faec\n"
        /* { scope 6 */
        "movl 8(%ebp), %ecx\n" /* line 281 | cinfo */
        "movl 0x20(%ecx), %edi\n" /* dest */
        "movl %ecx, (%esp)\n" /* line 283 */
        "calll *0xc(%edi)\n" /* dest */
        "testb %al, %al\n"
        "je .Lf20f3dc_0020f764\n"
        "movl (%edi), %eax\n" /* line 286 | dest */
        "movl %eax, -0x80(%ebp)\n"
        "movl 4(%edi), %edi\n" /* line 287 | dest */
        "jmp .Lf20f3dc_0020faec\n"
        ".Lf20f3dc_0020fd6d:\n"
        "movl %eax, %edx\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: put_buffer, put_buffer, put_buffer, c, ... */
        ".Lf20f3dc_0020fd6f:\n"
        "movl %esi, -0x70(%ebp)\n" /* line 321 | dest */
        "movl %edx, -0x58(%ebp)\n"
        /* } scope */
        "movl $0, -0xc8(%ebp)\n" /* line 430 | r */
        "movl 0x17505db(%ebx), %edx\n"
        "jmp .Lf20f3dc_0020f7bd\n"
        ".Lf20f3dc_0020fd8a:\n"
        "movl %ecx, %esi\n" /* dest */
        "jmp .Lf20f3dc_0020f598\n"
        /* { scope 4: put_buffer, put_buffer, put_buffer, c, ... */
        /* { scope 5: c, c, c, c */
        ".Lf20f3dc_0020fd91:\n"
        "movl 8(%ebp), %edx\n" /* line 311 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x28, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf20f3dc_0020f9f6\n"
        /* } scope */
        /* } scope */
        /* { scope 4: put_buffer, put_buffer, put_buffer, c, ... */
        /* { scope 5: c, c, c, c */
        ".Lf20f3dc_0020fda9:\n"
        "movl -0x80(%ebp), %edx\n" /* line 326 */
        "movb $0, (%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x80(%ebp)\n"
        "subl $1, %edi\n" /* dest */
        "jne .Lf20f3dc_0020fc53\n"
        /* { scope 6 */
        "movl 8(%ebp), %ecx\n" /* line 281 | cinfo */
        "movl 0x20(%ecx), %edi\n" /* dest */
        "movl %ecx, (%esp)\n" /* line 283 */
        "calll *0xc(%edi)\n" /* dest */
        "testb %al, %al\n"
        "je .Lf20f3dc_0020f764\n"
        "movl (%edi), %eax\n" /* line 286 | dest */
        "movl %eax, -0x80(%ebp)\n"
        "movl 4(%edi), %edi\n" /* line 287 | dest */
        "jmp .Lf20f3dc_0020fc53\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: temp, r */
        /* { scope 3: size, c, size, size, ... */
        /* { scope 4: put_buffer, put_buffer, put_buffer, c, ... */
        ".Lf20f3dc_0020fddf:\n"
        "movl 8(%ebp), %ecx\n" /* line 281 | cinfo */
        "movl 0x20(%ecx), %esi\n" /* dest */
        "movl %ecx, (%esp)\n" /* line 283 */
        "calll *0xc(%esi)\n" /* dest */
        "testb %al, %al\n"
        "je .Lf20f3dc_0020f764\n"
        "movl (%esi), %eax\n" /* line 286 | dest */
        "movl %eax, -0x80(%ebp)\n"
        "movl 4(%esi), %edi\n" /* line 287 | dest */
        "movl %eax, %edx\n"
        "jmp .Lf20f3dc_0020f68b\n"
        /* } scope */
        /* { scope 4: put_buffer, put_buffer, put_buffer, c, ... */
        ".Lf20f3dc_0020fe02:\n"
        "movl 8(%ebp), %ecx\n" /* line 281 | cinfo */
        "movl 0x20(%ecx), %esi\n" /* dest */
        "movl %ecx, (%esp)\n" /* line 283 */
        "calll *0xc(%esi)\n" /* dest */
        "testb %al, %al\n"
        "je .Lf20f3dc_0020f764\n"
        "movl (%esi), %eax\n" /* line 286 | dest */
        "movl %eax, -0x80(%ebp)\n"
        "movl 4(%esi), %edi\n" /* line 287 | dest */
        "jmp .Lf20f3dc_0020f6a5\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: temp, r */
        /* { scope 3: size, c, size, size, ... */
        ".Lf20f3dc_0020fe23:\n"
        "movl -0x4c(%ebp), %esi\n" /* line 412 | dest */
        "subl $1, %esi\n" /* dest */
        "movl %esi, -0x50(%ebp)\n" /* dest */
        "negl -0x4c(%ebp)\n"
        "movl -0x4c(%ebp), %eax\n"
        "jmp .Lf20f3dc_0020f9a9\n"
        /* { scope 4: put_buffer, put_buffer, put_buffer, c, ... */
        ".Lf20f3dc_0020fe37:\n"
        "movl 8(%ebp), %ecx\n" /* line 311 | cinfo */
        "movl (%ecx), %eax\n"
        "movl $0x28, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf20f3dc_0020fbea\n"
        /* } scope */
        ".Lf20f3dc_0020fe4f:\n"
        "movl -0xc8(%ebp), %eax\n" /* line 438 | r */
        "testl %eax, %eax\n"
        "jle .Lf20f3dc_0020fefd\n"
        "movl -0xd4(%ebp), %ecx\n" /* line 439 | actbl */
        "movzbl 0x400(%ecx), %eax\n"
        "movsbl %al, %esi\n" /* dest */
        "movl %esi, -0x90(%ebp)\n" /* dest, size */
        /* { scope 4: put_buffer, put_buffer, put_buffer, c, ... */
        /* { scope 5: c, c, c, c */
        "movl (%ecx), %edx\n" /* line 306 */
        "movl %edx, -0x8c(%ebp)\n" /* put_buffer */
        "testb %al, %al\n" /* line 310 */
        "je .Lf20f3dc_0020ff91\n"
        ".Lf20f3dc_0020fe83:\n"
        "movl $1, %eax\n" /* line 313 */
        "movzbl -0x90(%ebp), %ecx\n" /* size */
        "shll %cl, %eax\n"
        "leal -1(%eax), %esi\n" /* dest */
        "andl -0x8c(%ebp), %esi\n" /* put_buffer, dest */
        "movl -0x90(%ebp), %eax\n" /* line 315 | size */
        "addl -0x58(%ebp), %eax\n"
        "movl %eax, -0x5c(%ebp)\n"
        "movl $0x18, %ecx\n" /* line 319 */
        "subl %eax, %ecx\n"
        "shll %cl, %esi\n" /* dest */
        "orl -0x70(%ebp), %esi\n" /* dest */
        "cmpl $7, %eax\n" /* line 321 */
        "jle .Lf20f3dc_0020ff57\n"
        /* { scope 6 */
        ".Lf20f3dc_0020febb:\n"
        "movl %esi, %eax\n" /* line 322 | dest */
        "sarl $0x10, %eax\n"
        "andl $0xff, %eax\n"
        "movl %eax, -0x88(%ebp)\n" /* c */
        "movl -0x80(%ebp), %edx\n" /* line 324 */
        "movb %al, (%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x80(%ebp)\n"
        "subl $1, %edi\n" /* dest */
        "je .Lf20f3dc_0020ff39\n"
        ".Lf20f3dc_0020fedb:\n"
        "cmpl $0xff, -0x88(%ebp)\n" /* line 325 | c */
        "je .Lf20f3dc_0020ff5b\n"
        ".Lf20f3dc_0020fee7:\n"
        "shll $8, %esi\n" /* line 328 | dest */
        "subl $8, -0x5c(%ebp)\n" /* line 329 */
        /* } scope */
        "cmpl $7, -0x5c(%ebp)\n" /* line 321 */
        "jg .Lf20f3dc_0020febb\n"
        "movl -0x5c(%ebp), %edx\n"
        ".Lf20f3dc_0020fef7:\n"
        "movl %esi, -0x70(%ebp)\n" /* dest */
        "movl %edx, -0x58(%ebp)\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf20f3dc_0020fefd:\n"
        "movl -0xe8(%ebp), %ecx\n" /* line 506 */
        "movl 0xc(%ebp), %esi\n" /* MCU_data, dctbl */
        "movl -4(%ecx, %esi), %eax\n"
        "movswl (%eax), %eax\n"
        "movl -0xe0(%ebp), %edx\n" /* ci */
        "movl %eax, -0x2c(%ebp, %edx, 4)\n"
        "movl -0x78(%ebp), %eax\n"
        "addl $1, -0x78(%ebp)\n"
        "addl $4, %ecx\n"
        "movl %ecx, -0xe8(%ebp)\n"
        "movl 8(%ebp), %ecx\n" /* line 497 | cinfo */
        "cmpl %eax, 0x104(%ecx)\n"
        "jle .Lf20f3dc_0020ffa9\n"
        "movl %ecx, %edx\n"
        "jmp .Lf20f3dc_0020f47b\n"
        /* { scope 2: temp, r */
        /* { scope 3: size, c, size, size, ... */
        /* { scope 4: put_buffer, put_buffer, put_buffer, c, ... */
        /* { scope 5: c, c, c, c */
        /* { scope 6 */
        /* { scope 7 */
        ".Lf20f3dc_0020ff39:\n"
        "movl 8(%ebp), %ecx\n" /* line 281 | cinfo */
        "movl 0x20(%ecx), %edi\n" /* dest */
        "movl %ecx, (%esp)\n" /* line 283 */
        "calll *0xc(%edi)\n" /* dest */
        "testb %al, %al\n"
        "je .Lf20f3dc_0020f764\n"
        "movl (%edi), %eax\n" /* line 286 | dest */
        "movl %eax, -0x80(%ebp)\n"
        "movl 4(%edi), %edi\n" /* line 287 | dest */
        "jmp .Lf20f3dc_0020fedb\n"
        ".Lf20f3dc_0020ff57:\n"
        "movl %eax, %edx\n"
        "jmp .Lf20f3dc_0020fef7\n"
        /* } scope */
        ".Lf20f3dc_0020ff5b:\n"
        "movl -0x80(%ebp), %edx\n" /* line 326 */
        "movb $0, (%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x80(%ebp)\n"
        "subl $1, %edi\n" /* dest */
        "jne .Lf20f3dc_0020fee7\n"
        /* { scope 7 */
        "movl 8(%ebp), %ecx\n" /* line 281 | cinfo */
        "movl 0x20(%ecx), %edi\n" /* dest */
        "movl %ecx, (%esp)\n" /* line 283 */
        "calll *0xc(%edi)\n" /* dest */
        "testb %al, %al\n"
        "je .Lf20f3dc_0020f764\n"
        "movl (%edi), %eax\n" /* line 286 | dest */
        "movl %eax, -0x80(%ebp)\n"
        "movl 4(%edi), %edi\n" /* line 287 | dest */
        "jmp .Lf20f3dc_0020fee7\n"
        /* } scope */
        /* } scope */
        ".Lf20f3dc_0020ff91:\n"
        "movl 8(%ebp), %ecx\n" /* line 311 | cinfo */
        "movl (%ecx), %eax\n"
        "movl $0x28, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf20f3dc_0020fe83\n"
        ".Lf20f3dc_0020ffa9:\n"
        "movl %ecx, %esi\n" /* dest */
        "jmp .Lf20f3dc_0020f5a6\n"
    );
}

