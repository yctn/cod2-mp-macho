/* ASM dump from: jdmainct.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jdmainct.c */

#include "common_types.h"
#include "imports.h"

static void start_pass_main(j_decompress_ptr cinfo, J_BUF_MODE pass_mode);
static void process_data_simple_main(j_decompress_ptr cinfo, JSAMPARRAY output_buf, JDIMENSION *out_row_ctr, JDIMENSION out_rows_avail);
static void process_data_context_main(j_decompress_ptr cinfo, JSAMPARRAY output_buf, JDIMENSION *out_row_ctr, JDIMENSION out_rows_avail);
static void process_data_crank_post(j_decompress_ptr cinfo, JSAMPARRAY output_buf, JDIMENSION *out_row_ctr, JDIMENSION out_rows_avail);
void jinit_d_main_controller(j_decompress_ptr cinfo, int need_full_buffer);

/* line 308 */
static __attribute__((naked))
void start_pass_main(j_decompress_ptr cinfo, J_BUF_MODE pass_mode)
{
    __asm__ __volatile__ (
        /* { scope 1: main, ci, M, compptr, ... */
        "pushl %ebp\n" /* line 308 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x38, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, -0x3c(%ebp)\n" /* cinfo */
        "movl 0xc(%ebp), %eax\n" /* pass_mode */
        "movl -0x3c(%ebp), %edx\n" /* line 309 | cinfo */
        "movl 0x18c(%edx), %edx\n"
        "movl %edx, -0x38(%ebp)\n" /* main */
        "testl %eax, %eax\n" /* line 311 */
        "je .Lf20612c_00206178\n"
        "cmpl $2, %eax\n"
        "je .Lf20612c_00206317\n"
        "movl -0x3c(%ebp), %ecx\n" /* line 333 | cinfo */
        "movl (%ecx), %eax\n"
        "movl $4, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, 8(%ebp)\n" /* cinfo */
        "movl (%eax), %ecx\n"
        "addl $0x38, %esp\n" /* line 336 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmpl *%ecx\n" /* line 333 */
        ".Lf20612c_00206178:\n"
        "movl -0x3c(%ebp), %ecx\n" /* line 313 | cinfo */
        "movl 0x1a8(%ecx), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf20612c_002061a9\n"
        "leal 0x1f1(%ebx), %eax\n" /* line 321 */
        "movl -0x38(%ebp), %esi\n" /* main */
        "movl %eax, 4(%esi)\n"
        ".Lf20612c_00206193:\n"
        "movl -0x38(%ebp), %eax\n" /* line 323 | main */
        "movb $0, 0x30(%eax)\n"
        "movl $0, 0x34(%eax)\n" /* line 324 */
        "addl $0x38, %esp\n" /* line 336 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20612c_002061a9:\n"
        "leal 0x287(%ebx), %eax\n" /* line 314 */
        "movl -0x38(%ebp), %esi\n" /* main */
        "movl %eax, 4(%esi)\n"
        /* { scope 2 */
        "movl 0x18c(%ecx), %eax\n" /* line 203 */
        "movl %eax, -0x30(%ebp)\n" /* main */
        "movl 0x120(%ecx), %edx\n" /* line 205 */
        "movl %edx, -0x28(%ebp)\n" /* M */
        "movl 0xcc(%ecx), %ecx\n" /* line 209 */
        "movl %ecx, -0x24(%ebp)\n" /* compptr */
        "movl -0x3c(%ebp), %esi\n" /* cinfo */
        "movl 0x2c(%esi), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lf20612c_002062fa\n"
        "addl $2, %edx\n"
        "movl %edx, -0x18(%ebp)\n"
        "movl %eax, -0x14(%ebp)\n"
        "movl $0, -0x2c(%ebp)\n" /* ci */
        "movl -0x3c(%ebp), %esi\n" /* cinfo */
        ".Lf20612c_002061f1:\n"
        "movl -0x24(%ebp), %eax\n" /* line 211 | compptr */
        "movl 0xc(%eax), %ecx\n"
        "imull 0x24(%eax), %ecx\n"
        "movl %ecx, %eax\n"
        "cltd\n"
        "idivl 0x120(%esi)\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl -0x2c(%ebp), %edx\n" /* ci */
        "shll $2, %edx\n"
        "movl -0x30(%ebp), %ecx\n" /* line 213 | main */
        "movl 0x38(%ecx), %eax\n"
        "movl (%eax, %edx), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* xbuf0 */
        "movl 0x3c(%ecx), %eax\n" /* line 214 */
        "movl (%eax, %edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* xbuf1 */
        "movl -0x14(%ebp), %esi\n" /* line 216 */
        "movl 8(%esi), %esi\n"
        "movl %esi, -0x44(%ebp)\n" /* buf */
        "movl -0x40(%ebp), %edi\n" /* line 217 */
        "imull -0x18(%ebp), %edi\n"
        "testl %edi, %edi\n"
        "jle .Lf20612c_00206258\n"
        "xorl %ecx, %ecx\n"
        ".Lf20612c_00206238:\n"
        "leal (, %ecx, 4), %eax\n" /* line 308 */
        "movl -0x44(%ebp), %esi\n" /* line 218 | buf */
        "movl (%esi, %eax), %edx\n"
        "movl -0x1c(%ebp), %esi\n" /* xbuf1 */
        "movl %edx, (%esi, %eax)\n"
        "movl -0x20(%ebp), %esi\n" /* xbuf0 */
        "movl %edx, (%esi, %eax)\n"
        "addl $1, %ecx\n" /* line 217 */
        "cmpl %ecx, %edi\n"
        "jne .Lf20612c_00206238\n"
        ".Lf20612c_00206258:\n"
        "movl -0x40(%ebp), %eax\n" /* line 221 */
        "addl %eax, %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "testl %eax, %eax\n"
        "jle .Lf20612c_002062b6\n"
        "movl -0x28(%ebp), %edx\n" /* line 308 | M */
        "imull -0x40(%ebp), %edx\n"
        "shll $2, %edx\n"
        "movl -0x44(%ebp), %edi\n" /* buf */
        "addl %edx, %edi\n"
        "movl -0x28(%ebp), %eax\n" /* M */
        "subl $2, %eax\n"
        "imull -0x40(%ebp), %eax\n"
        "leal (, %eax, 4), %ecx\n"
        "movl -0x44(%ebp), %esi\n" /* buf */
        "addl %ecx, %esi\n"
        "movl $0, -0x10(%ebp)\n"
        "addl -0x1c(%ebp), %edx\n" /* xbuf1 */
        "addl -0x1c(%ebp), %ecx\n" /* xbuf1 */
        ".Lf20612c_00206296:\n"
        "movl (%edi), %eax\n" /* line 222 */
        "movl %eax, (%ecx)\n"
        "movl (%esi), %eax\n" /* line 223 */
        "movl %eax, (%edx)\n"
        "addl $1, -0x10(%ebp)\n" /* line 221 */
        "addl $4, %ecx\n"
        "addl $4, %edx\n"
        "addl $4, %edi\n"
        "addl $4, %esi\n"
        "movl -0x10(%ebp), %eax\n"
        "cmpl %eax, -0x34(%ebp)\n"
        "jne .Lf20612c_00206296\n"
        ".Lf20612c_002062b6:\n"
        "movl -0x40(%ebp), %eax\n" /* line 230 */
        "testl %eax, %eax\n"
        "jle .Lf20612c_002062dc\n"
        "movl -0x40(%ebp), %eax\n"
        "shll $2, %eax\n"
        "movl -0x20(%ebp), %edx\n" /* xbuf0 */
        "subl %eax, %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf20612c_002062ca:\n"
        "movl -0x20(%ebp), %esi\n" /* line 231 | xbuf0 */
        "movl (%esi), %eax\n"
        "movl %eax, (%edx)\n"
        "addl $1, %ecx\n" /* line 230 */
        "addl $4, %edx\n"
        "cmpl %ecx, -0x40(%ebp)\n"
        "jne .Lf20612c_002062ca\n"
        ".Lf20612c_002062dc:\n"
        "addl $1, -0x2c(%ebp)\n" /* line 210 | ci */
        "addl $0x54, -0x24(%ebp)\n" /* compptr */
        "addl $4, -0x14(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 209 | ci */
        "movl -0x3c(%ebp), %edx\n" /* cinfo */
        "cmpl 0x2c(%edx), %eax\n"
        "jge .Lf20612c_002062fa\n"
        "movl %edx, %esi\n"
        "jmp .Lf20612c_002061f1\n"
        /* } scope */
        ".Lf20612c_002062fa:\n"
        "movl -0x38(%ebp), %ecx\n" /* line 316 | main */
        "movl $0, 0x40(%ecx)\n"
        "movl $0, 0x44(%ecx)\n" /* line 317 */
        "movl $0, 0x4c(%ecx)\n" /* line 318 */
        "jmp .Lf20612c_00206193\n"
        ".Lf20612c_00206317:\n"
        "leal 0x5f8(%ebx), %eax\n" /* line 329 */
        "movl -0x38(%ebp), %edx\n" /* main */
        "movl %eax, 4(%edx)\n"
        "addl $0x38, %esp\n" /* line 336 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 348 */
static __attribute__((naked))
void process_data_simple_main(j_decompress_ptr cinfo, JSAMPARRAY output_buf, JDIMENSION *out_row_ctr, JDIMENSION out_rows_avail)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 348 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 349 | cinfo */
        "movl 0x18c(%eax), %edi\n" /* main */
        "cmpb $0, 0x30(%edi)\n" /* line 353 | main */
        "jne .Lf20632b_00206365\n"
        "movl 0x190(%eax), %eax\n" /* line 354 */
        "leal 8(%edi), %edx\n" /* main */
        "movl %edx, -0xc(%ebp)\n"
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl %edx, (%esp)\n"
        "calll *0xc(%eax)\n"
        "testl %eax, %eax\n"
        "je .Lf20632b_002063ba\n"
        "movb $1, 0x30(%edi)\n" /* line 356 | main */
        "jmp .Lf20632b_0020636b\n"
        ".Lf20632b_00206365:\n"
        "leal 8(%edi), %eax\n" /* main */
        "movl %eax, -0xc(%ebp)\n"
        ".Lf20632b_0020636b:\n"
        "movl 8(%ebp), %edx\n" /* line 360 | cinfo */
        "movl 0x120(%edx), %esi\n" /* rowgroups_avail */
        "movl 0x194(%edx), %edx\n" /* line 367 */
        "movl 0x14(%ebp), %eax\n" /* out_rows_avail */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* out_row_ctr */
        "movl %eax, 0x14(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* output_buf */
        "movl %eax, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n" /* rowgroups_avail */
        "leal 0x34(%edi), %eax\n" /* main */
        "movl %eax, 8(%esp)\n"
        "movl -0xc(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll *4(%edx)\n"
        "cmpl 0x34(%edi), %esi\n" /* line 372 | main, rowgroups_avail */
        "ja .Lf20632b_002063ba\n"
        "movb $0, 0x30(%edi)\n" /* line 373 | main */
        "movl $0, 0x34(%edi)\n" /* line 374 | main */
        ".Lf20632b_002063ba:\n"
        "addl $0x30, %esp\n" /* line 376 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 388 */
static __attribute__((naked))
void process_data_context_main(j_decompress_ptr cinfo, JSAMPARRAY output_buf, JDIMENSION *out_row_ctr, JDIMENSION out_rows_avail)
{
    __asm__ __volatile__ (
        /* { scope 1: main, ci, i, compptr, ... */
        "pushl %ebp\n" /* line 388 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x90, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 389 | cinfo */
        "movl 0x18c(%eax), %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* main */
        "cmpb $0, 0x30(%eax)\n" /* line 392 */
        "je .Lf2063c1_002064c8\n"
        "movl %eax, %edi\n"
        "movl 0x44(%edi), %eax\n" /* line 405 */
        "cmpl $1, %eax\n"
        "je .Lf2063c1_002064ff\n"
        ".Lf2063c1_002063f0:\n"
        "cmpl $2, %eax\n"
        "je .Lf2063c1_0020650c\n"
        "testl %eax, %eax\n"
        "jne .Lf2063c1_002064be\n"
        "movl -0x30(%ebp), %ecx\n" /* main */
        "addl $0x34, %ecx\n"
        "movl %ecx, -0x40(%ebp)\n"
        ".Lf2063c1_0020640a:\n"
        "movl -0x30(%ebp), %esi\n" /* line 419 | main */
        "movl $0, 0x34(%esi)\n"
        "movl 8(%ebp), %edi\n" /* line 420 | cinfo */
        "movl 0x120(%edi), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0x48(%esi)\n"
        "movl 0x4c(%esi), %eax\n" /* line 424 */
        "cmpl 0x124(%edi), %eax\n"
        "je .Lf2063c1_00206684\n"
        ".Lf2063c1_00206432:\n"
        "movl -0x30(%ebp), %ecx\n" /* line 426 | main */
        "movl $1, 0x44(%ecx)\n"
        ".Lf2063c1_0020643c:\n"
        "movl 8(%ebp), %edi\n" /* line 430 | cinfo */
        "movl 0x194(%edi), %edx\n"
        "movl 0x14(%ebp), %eax\n" /* out_rows_avail */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x10(%ebp), %ecx\n" /* out_row_ctr */
        "movl %ecx, 0x14(%esp)\n"
        "movl 0xc(%ebp), %esi\n" /* output_buf */
        "movl %esi, 0x10(%esp)\n"
        "movl -0x30(%ebp), %edi\n" /* main */
        "movl 0x48(%edi), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x40(%edi), %eax\n"
        "movl 0x38(%edi, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %ecx, (%esp)\n"
        "calll *4(%edx)\n"
        "movl 0x34(%edi), %eax\n" /* line 433 */
        "cmpl 0x48(%edi), %eax\n"
        "jb .Lf2063c1_002064be\n"
        "cmpl $1, 0x4c(%edi)\n" /* line 436 */
        "je .Lf2063c1_0020657b\n"
        ".Lf2063c1_00206491:\n"
        "movl -0x30(%ebp), %edi\n" /* line 439 | main */
        "xorl $1, 0x40(%edi)\n"
        "movb $0, 0x30(%edi)\n" /* line 440 */
        "movl 8(%ebp), %edx\n" /* line 443 | cinfo */
        "movl 0x120(%edx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x34(%edi)\n"
        "movl 0x120(%edx), %eax\n" /* line 444 */
        "addl $2, %eax\n"
        "movl %eax, 0x48(%edi)\n"
        "movl $2, 0x44(%edi)\n" /* line 445 */
        ".Lf2063c1_002064be:\n"
        "addl $0x90, %esp\n" /* line 447 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2063c1_002064c8:\n"
        "movl 8(%ebp), %ecx\n" /* line 393 | cinfo */
        "movl 0x190(%ecx), %edx\n"
        "movl %eax, %esi\n"
        "movl 0x40(%eax), %eax\n"
        "movl 0x38(%esi, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *0xc(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lf2063c1_002064be\n"
        "movb $1, 0x30(%esi)\n" /* line 396 */
        "addl $1, 0x4c(%esi)\n" /* line 397 */
        "movl -0x30(%ebp), %edi\n" /* main */
        "movl 0x44(%edi), %eax\n" /* line 405 */
        "cmpl $1, %eax\n"
        "jne .Lf2063c1_002063f0\n"
        ".Lf2063c1_002064ff:\n"
        "movl %edi, %esi\n"
        "addl $0x34, %esi\n"
        "movl %esi, -0x40(%ebp)\n"
        "jmp .Lf2063c1_0020643c\n"
        ".Lf2063c1_0020650c:\n"
        "movl 8(%ebp), %eax\n" /* line 408 | cinfo */
        "movl 0x194(%eax), %edx\n"
        "movl 0x14(%ebp), %ecx\n" /* out_rows_avail */
        "movl %ecx, 0x18(%esp)\n"
        "movl 0x10(%ebp), %esi\n" /* out_row_ctr */
        "movl %esi, 0x14(%esp)\n"
        "movl 0xc(%ebp), %edi\n" /* output_buf */
        "movl %edi, 0x10(%esp)\n"
        "movl -0x30(%ebp), %ecx\n" /* main */
        "movl 0x48(%ecx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "addl $0x34, %ecx\n"
        "movl %ecx, -0x40(%ebp)\n"
        "movl %ecx, 8(%esp)\n"
        "movl -0x30(%ebp), %esi\n" /* main */
        "movl 0x40(%esi), %eax\n"
        "movl 0x38(%esi, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edi\n" /* cinfo */
        "movl %edi, (%esp)\n"
        "calll *4(%edx)\n"
        "movl 0x34(%esi), %eax\n" /* line 411 */
        "cmpl 0x48(%esi), %eax\n"
        "jb .Lf2063c1_002064be\n"
        "movl $0, 0x44(%esi)\n" /* line 413 */
        "movl 0x14(%ebp), %edx\n" /* line 414 | out_rows_avail */
        "movl 0x10(%ebp), %eax\n" /* out_row_ctr */
        "cmpl (%eax), %edx\n"
        "ja .Lf2063c1_0020640a\n"
        "jmp .Lf2063c1_002064be\n"
        /* { scope 2 */
        ".Lf2063c1_0020657b:\n"
        "movl 8(%ebp), %esi\n" /* line 243 | cinfo */
        "movl 0x18c(%esi), %esi\n"
        "movl %esi, -0x20(%ebp)\n" /* main */
        "movl 8(%ebp), %edi\n" /* line 245 | cinfo */
        "movl 0x120(%edi), %eax\n" /* M */
        "movl 0xcc(%edi), %edx\n" /* line 249 */
        "movl %edx, -0x14(%ebp)\n" /* compptr */
        "movl 0x2c(%edi), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf2063c1_00206491\n"
        "movl $0, -0x1c(%ebp)\n" /* ci */
        "leal 1(%eax), %ecx\n"
        "movl %ecx, -0x38(%ebp)\n"
        "addl $2, %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        ".Lf2063c1_002065b7:\n"
        "movl -0x14(%ebp), %esi\n" /* line 251 | compptr */
        "movl 0xc(%esi), %ecx\n"
        "imull 0x24(%esi), %ecx\n"
        "movl %ecx, %eax\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        "cltd\n"
        "idivl 0x120(%esi)\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl -0x1c(%ebp), %edx\n" /* ci */
        "shll $2, %edx\n"
        "movl -0x20(%ebp), %edi\n" /* line 253 | main */
        "movl 0x38(%edi), %eax\n"
        "movl (%eax, %edx), %eax\n"
        "movl %eax, -0x10(%ebp)\n" /* xbuf0 */
        "movl 0x3c(%edi), %eax\n" /* line 254 */
        "movl (%eax, %edx), %eax\n"
        "movl %eax, -0xc(%ebp)\n" /* xbuf1 */
        "movl -0x34(%ebp), %edi\n" /* line 255 */
        "testl %edi, %edi\n"
        "jle .Lf2063c1_0020666b\n"
        "movl -0x38(%ebp), %edx\n"
        "imull -0x34(%ebp), %edx\n"
        "movl -0x34(%ebp), %eax\n"
        "imull -0x3c(%ebp), %eax\n"
        "movl $0, -0x18(%ebp)\n" /* i */
        "movl -0x34(%ebp), %edi\n"
        "shll $2, %edi\n"
        "leal (, %eax, 4), %esi\n"
        "negl %edi\n"
        "leal (, %edx, 4), %ecx\n"
        ".Lf2063c1_0020661d:\n"
        "movl -0x10(%ebp), %edx\n" /* line 256 | xbuf0 */
        "movl (%ecx, %edx), %eax\n"
        "movl %eax, (%edi, %edx)\n"
        "movl -0xc(%ebp), %edx\n" /* line 257 | xbuf1 */
        "movl (%ecx, %edx), %eax\n"
        "movl %eax, (%edi, %edx)\n"
        "movl -0x18(%ebp), %eax\n" /* line 388 | i */
        "shll $2, %eax\n"
        "movl %eax, -0x5c(%ebp)\n"
        "movl -0x10(%ebp), %edx\n" /* line 258 | xbuf0 */
        "movl (%edx, %eax), %edx\n"
        "movl -0x10(%ebp), %eax\n" /* xbuf0 */
        "movl %edx, (%esi, %eax)\n"
        "movl -0xc(%ebp), %edx\n" /* line 259 | xbuf1 */
        "movl -0x5c(%ebp), %eax\n"
        "movl (%edx, %eax), %edx\n"
        "movl -0xc(%ebp), %eax\n" /* xbuf1 */
        "movl %edx, (%esi, %eax)\n"
        "addl $1, -0x18(%ebp)\n" /* line 255 | i */
        "addl $4, %ecx\n"
        "addl $4, %edi\n"
        "addl $4, %esi\n"
        "movl -0x18(%ebp), %edx\n" /* i */
        "cmpl %edx, -0x34(%ebp)\n"
        "jne .Lf2063c1_0020661d\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        ".Lf2063c1_0020666b:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 250 | ci */
        "addl $0x54, -0x14(%ebp)\n" /* compptr */
        "movl -0x1c(%ebp), %ecx\n" /* line 249 | ci */
        "cmpl 0x2c(%esi), %ecx\n"
        "jl .Lf2063c1_002065b7\n"
        "jmp .Lf2063c1_00206491\n"
        /* } scope */
        /* { scope 2 */
        ".Lf2063c1_00206684:\n"
        "movl 0x18c(%edi), %eax\n" /* line 272 */
        "movl %eax, -0x2c(%ebp)\n" /* main */
        "movl 0xcc(%edi), %edx\n" /* line 277 */
        "movl %edx, -0x24(%ebp)\n" /* compptr */
        "movl 0x2c(%edi), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf2063c1_00206432\n"
        "movl $0, -0x28(%ebp)\n" /* ci */
        "movl 8(%ebp), %edi\n" /* cinfo */
        ".Lf2063c1_002066ab:\n"
        "movl -0x24(%ebp), %esi\n" /* line 280 | compptr */
        "movl 0xc(%esi), %ecx\n"
        "imull 0x24(%esi), %ecx\n"
        "movl %ecx, %eax\n" /* line 281 */
        "cltd\n"
        "idivl 0x120(%edi)\n"
        "movl %eax, %esi\n"
        "movl -0x24(%ebp), %edx\n" /* line 283 | compptr */
        "movl 0x2c(%edx), %eax\n"
        "xorl %edx, %edx\n"
        "divl %ecx\n"
        "testl %edx, %edx\n" /* line 284 */
        "cmovnel %edx, %ecx\n"
        "movl -0x28(%ebp), %edi\n" /* line 288 | ci */
        "testl %edi, %edi\n"
        "jne .Lf2063c1_002066e5\n"
        "leal -1(%ecx), %eax\n" /* line 289 */
        "cltd\n"
        "idivl %esi\n"
        "addl $1, %eax\n"
        "movl -0x2c(%ebp), %edi\n" /* main */
        "movl %eax, 0x48(%edi)\n"
        ".Lf2063c1_002066e5:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 294 | main */
        "movl 0x40(%edx), %eax\n"
        "movl 0x38(%edx, %eax, 4), %eax\n"
        "movl -0x28(%ebp), %edi\n" /* ci */
        "movl (%eax, %edi, 4), %eax\n"
        "leal (%esi, %esi), %edi\n" /* line 295 */
        "testl %edi, %edi\n"
        "jle .Lf2063c1_00206714\n"
        "leal (%eax, %ecx, 4), %eax\n"
        "leal -4(%eax), %esi\n"
        "movl %eax, %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf2063c1_00206706:\n"
        "movl (%esi), %eax\n" /* line 296 */
        "movl %eax, (%edx)\n"
        "addl $1, %ecx\n" /* line 295 */
        "addl $4, %edx\n"
        "cmpl %ecx, %edi\n"
        "jne .Lf2063c1_00206706\n"
        ".Lf2063c1_00206714:\n"
        "addl $1, -0x28(%ebp)\n" /* line 278 | ci */
        "addl $0x54, -0x24(%ebp)\n" /* compptr */
        "movl -0x28(%ebp), %eax\n" /* line 277 | ci */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "cmpl %eax, 0x2c(%edx)\n"
        "jle .Lf2063c1_00206432\n"
        "movl %edx, %edi\n"
        "jmp .Lf2063c1_002066ab\n"
    );
}

/* line 462 */
static __attribute__((naked))
void process_data_crank_post(j_decompress_ptr cinfo, JSAMPARRAY output_buf, JDIMENSION *out_row_ctr, JDIMENSION out_rows_avail)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 462 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 0x194(%edx), %ecx\n" /* line 463 */
        "movl 0x14(%ebp), %eax\n" /* out_rows_avail */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* out_row_ctr */
        "movl %eax, 0x14(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* output_buf */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *4(%ecx)\n"
        "leave\n" /* line 466 */
        "retl\n"
    );
}

/* line 477 */
__attribute__((naked))
void jinit_d_main_controller(j_decompress_ptr cinfo, int need_full_buffer)
{
    __asm__ __volatile__ (
        /* { scope 1: main, ci */
        "pushl %ebp\n" /* line 477 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movzbl 0xc(%ebp), %esi\n" /* need_full_buffer */
        "movl 8(%ebp), %edx\n" /* line 482 | cinfo */
        "movl 4(%edx), %eax\n"
        "movl $0x50, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl %eax, -0x38(%ebp)\n" /* main */
        "movl 8(%ebp), %ecx\n" /* line 485 | cinfo */
        "movl %eax, 0x18c(%ecx)\n"
        "leal -0x658(%ebx), %eax\n" /* line 486 */
        "movl -0x38(%ebp), %edx\n" /* main */
        "movl %eax, (%edx)\n"
        "movl %esi, %ecx\n" /* line 488 | need_full_buffer */
        "testb %cl, %cl\n"
        "jne .Lf206776_002068f0\n"
        ".Lf206776_002067c4:\n"
        "movl 8(%ebp), %edx\n" /* line 494 | cinfo */
        "movl 0x1a8(%edx), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf206776_00206860\n"
        "cmpl $1, 0x120(%edx)\n" /* line 495 */
        "jle .Lf206776_00206996\n"
        /* { scope 2 */
        ".Lf206776_002067e4:\n"
        "movl 8(%ebp), %ecx\n" /* line 162 | cinfo */
        "movl 0x18c(%ecx), %ecx\n"
        "movl %ecx, -0x2c(%ebp)\n" /* main */
        "movl 8(%ebp), %eax\n" /* line 164 | cinfo */
        "movl 0x120(%eax), %esi\n" /* M */
        "movl 4(%eax), %edx\n" /* line 171 */
        "movl %eax, %ecx\n"
        "movl 0x2c(%eax), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *(%edx)\n"
        "movl -0x2c(%ebp), %edx\n" /* main */
        "movl %eax, 0x38(%edx)\n"
        "movl 8(%ebp), %ecx\n" /* line 174 | cinfo */
        "movl 0x2c(%ecx), %edx\n"
        "leal (%eax, %edx, 4), %edx\n"
        "movl -0x2c(%ebp), %eax\n" /* main */
        "movl %edx, 0x3c(%eax)\n"
        "movl 0xcc(%ecx), %eax\n" /* line 176 */
        "movl %eax, %edi\n" /* compptr */
        "movl 0x2c(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "jg .Lf206776_00206908\n"
        /* } scope */
        ".Lf206776_0020683d:\n"
        "movl 8(%ebp), %esi\n" /* line 498 | cinfo, need_full_buffer */
        "movl 0x120(%esi), %edx\n" /* need_full_buffer */
        "addl $2, %edx\n"
        "movl %edx, -0x30(%ebp)\n" /* ngroups */
        "movl %eax, %edi\n" /* line 503 | compptr */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 0x2c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf206776_0020687b\n"
        ".Lf206776_00206858:\n"
        "addl $0x5c, %esp\n" /* line 512 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf206776_00206860:\n"
        "movl 0x120(%edx), %ecx\n" /* line 500 */
        "movl %ecx, -0x30(%ebp)\n" /* ngroups */
        "movl 0xcc(%edx), %eax\n"
        "movl %eax, %edi\n" /* line 503 | compptr */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 0x2c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf206776_00206858\n"
        ".Lf206776_0020687b:\n"
        "movl -0x38(%ebp), %edx\n" /* main */
        "movl %edx, -0x1c(%ebp)\n"
        "movl $0, -0x34(%ebp)\n" /* ci */
        "movl 8(%ebp), %esi\n" /* cinfo, need_full_buffer */
        "jmp .Lf206776_0020688f\n"
        ".Lf206776_0020688d:\n"
        "movl %ecx, %esi\n" /* need_full_buffer */
        ".Lf206776_0020688f:\n"
        "movl 0x24(%edi), %ecx\n" /* line 505 | compptr */
        "movl %ecx, -0x3c(%ebp)\n"
        "movl 4(%esi), %ecx\n" /* line 507 | need_full_buffer */
        "movl -0x3c(%ebp), %eax\n"
        "imull 0xc(%edi), %eax\n" /* compptr */
        "cltd\n"
        "idivl 0x120(%esi)\n" /* need_full_buffer */
        "imull -0x30(%ebp), %eax\n" /* ngroups */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x3c(%ebp), %esi\n" /* need_full_buffer */
        "imull 0x1c(%edi), %esi\n" /* compptr, need_full_buffer */
        "movl %esi, 8(%esp)\n" /* need_full_buffer */
        "movl $1, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll *8(%ecx)\n"
        "movl -0x1c(%ebp), %edx\n"
        "movl %eax, 8(%edx)\n"
        "addl $1, -0x34(%ebp)\n" /* line 504 | ci */
        "addl $0x54, %edi\n" /* compptr */
        "addl $4, %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl -0x34(%ebp), %esi\n" /* line 503 | ci, need_full_buffer */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "cmpl 0x2c(%ecx), %esi\n" /* need_full_buffer */
        "jl .Lf206776_0020688d\n"
        "addl $0x5c, %esp\n" /* line 512 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf206776_002068f0:\n"
        "movl 8(%ebp), %esi\n" /* line 489 | cinfo, need_full_buffer */
        "movl (%esi), %eax\n" /* need_full_buffer */
        "movl $4, 0x14(%eax)\n"
        "movl (%esi), %eax\n" /* need_full_buffer */
        "movl %esi, (%esp)\n" /* need_full_buffer */
        "calll *(%eax)\n"
        "jmp .Lf206776_002067c4\n"
        /* { scope 2 */
        ".Lf206776_00206908:\n"
        "leal 0x20(, %esi, 8), %edx\n" /* line 176 */
        "movl %edx, -0x24(%ebp)\n"
        "leal 0x10(, %esi, 4), %esi\n" /* M */
        "movl %esi, -0x20(%ebp)\n" /* M */
        "movl $0, -0x28(%ebp)\n" /* ci */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        ".Lf206776_00206926:\n"
        "movl 0xc(%edi), %esi\n" /* line 178 | compptr, M */
        "imull 0x24(%edi), %esi\n" /* compptr, M */
        "movl %esi, %eax\n" /* M */
        "cltd\n"
        "idivl 0x120(%ecx)\n"
        "movl %eax, %esi\n" /* M */
        "movl 4(%ecx), %edx\n" /* line 183 */
        "movl -0x24(%ebp), %eax\n"
        "imull %esi, %eax\n" /* M */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *(%edx)\n"
        "leal (%eax, %esi, 4), %edx\n" /* line 186 */
        "movl -0x28(%ebp), %ecx\n" /* ci */
        "shll $2, %ecx\n"
        "movl -0x2c(%ebp), %eax\n" /* line 187 | main */
        "movl 0x38(%eax), %eax\n"
        "movl %eax, -0x4c(%ebp)\n"
        "movl %edx, (%eax, %ecx)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 189 | main */
        "movl 0x3c(%eax), %eax\n"
        "movl %eax, -0x50(%ebp)\n"
        "imull -0x20(%ebp), %esi\n" /* M */
        "addl %esi, %edx\n" /* M */
        "movl %edx, (%eax, %ecx)\n"
        "addl $1, -0x28(%ebp)\n" /* line 177 | ci */
        "addl $0x54, %edi\n" /* compptr */
        "movl -0x28(%ebp), %edx\n" /* line 176 | ci */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "cmpl %edx, 0x2c(%ecx)\n"
        "jg .Lf206776_00206926\n"
        "movl 0xcc(%ecx), %eax\n"
        "jmp .Lf206776_0020683d\n"
        /* } scope */
        ".Lf206776_00206996:\n"
        "movl (%edx), %eax\n" /* line 496 */
        "movl $0x2f, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf206776_002067e4\n"
    );
}

