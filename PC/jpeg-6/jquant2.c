/* ASM dump from: jquant2.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jquant2.c */

#include "common_types.h"
#include "imports.h"

static void prescan_quantize(j_decompress_ptr cinfo, JSAMPARRAY input_buf, JSAMPARRAY output_buf, int num_rows);
static void update_box(boxptr boxp);
static void fill_inverse_cmap(j_decompress_ptr cinfo, int c2);
static void pass2_no_dither(j_decompress_ptr cinfo, JSAMPARRAY input_buf, JSAMPARRAY output_buf, int num_rows);
static void pass2_fs_dither(j_decompress_ptr cinfo, JSAMPARRAY input_buf, JSAMPARRAY output_buf, int num_rows);
static void finish_pass1(j_decompress_ptr cinfo);
static void finish_pass2(j_decompress_ptr cinfo);
static void new_color_map_2_quant(j_decompress_ptr cinfo);
void jinit_2pass_quantizer(j_decompress_ptr cinfo);
static void start_pass_2_quant(j_decompress_ptr cinfo, int is_pre_scan);

/* line 226 */
static __attribute__((naked))
void prescan_quantize(j_decompress_ptr cinfo, JSAMPARRAY input_buf, JSAMPARRAY output_buf, int num_rows)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 226 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0xc, %esp\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 0x1b0(%edx), %eax\n" /* line 230 */
        "movl 0x18(%eax), %eax\n"
        "movl %eax, -0x14(%ebp)\n" /* histogram */
        "movl 0x64(%edx), %edx\n" /* line 233 */
        "movl %edx, -0xc(%ebp)\n" /* width */
        "movl 0x14(%ebp), %edx\n" /* line 235 | num_rows */
        "testl %edx, %edx\n"
        "jle .Lf202d14_00202da9\n"
        "movl $0, -0x10(%ebp)\n" /* row */
        "movl -0x10(%ebp), %eax\n" /* row */
        ".Lf202d14_00202d42:\n"
        "movl 0xc(%ebp), %edx\n" /* line 236 | input_buf */
        "movl (%edx, %eax, 4), %esi\n" /* ptr */
        "movl -0xc(%ebp), %eax\n" /* line 237 | width */
        "testl %eax, %eax\n"
        "je .Lf202d14_00202d99\n"
        "xorl %edi, %edi\n"
        ".Lf202d14_00202d51:\n"
        "movzbl (%esi), %ecx\n" /* line 239 | ptr */
        "shrb $3, %cl\n"
        "movzbl %cl, %ecx\n"
        "movzbl 1(%esi), %edx\n" /* ptr */
        "shrb $2, %dl\n"
        "movzbl %dl, %edx\n"
        "shll $5, %edx\n"
        "movzbl 2(%esi), %eax\n" /* ptr */
        "shrb $3, %al\n"
        "movzbl %al, %eax\n"
        "addl %eax, %edx\n"
        "movl -0x14(%ebp), %eax\n" /* histogram */
        "movl (%eax, %ecx, 4), %ecx\n"
        "leal (%ecx, %edx, 2), %edx\n"
        "movl $0xffffffff, %eax\n" /* line 244 */
        "movzwl (%edx), %ecx\n"
        "addw $1, %cx\n"
        "cmovnel %ecx, %eax\n"
        "movw %ax, (%edx)\n"
        "addl $3, %esi\n" /* line 245 | ptr */
        "addl $1, %edi\n"
        "cmpl %edi, -0xc(%ebp)\n" /* line 237 | width */
        "jne .Lf202d14_00202d51\n"
        ".Lf202d14_00202d99:\n"
        "addl $1, -0x10(%ebp)\n" /* line 235 | row */
        "movl -0x10(%ebp), %edx\n" /* row */
        "cmpl %edx, 0x14(%ebp)\n" /* num_rows */
        "je .Lf202d14_00202da9\n"
        "movl %edx, %eax\n"
        "jmp .Lf202d14_00202d42\n"
        ".Lf202d14_00202da9:\n"
        "addl $0xc, %esp\n" /* line 248 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 316 */
static __attribute__((naked))
void update_box(boxptr boxp)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 316 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x74, %esp\n"
        "movl %edx, -0x64(%ebp)\n"
        "movl 0x1b0(%eax), %eax\n" /* line 318 | cinfo */
        "movl 0x18(%eax), %eax\n" /* cinfo */
        "movl %eax, -0x60(%ebp)\n" /* cinfo, histogram */
        "movl (%edx), %eax\n" /* line 325 | cinfo */
        "movl %eax, -0x58(%ebp)\n" /* cinfo, c0min */
        "movl 4(%edx), %edx\n"
        "movl %edx, -0x54(%ebp)\n" /* c0max */
        "movl -0x64(%ebp), %ecx\n" /* line 326 */
        "movl 8(%ecx), %ecx\n"
        "movl %ecx, -0x50(%ebp)\n" /* c1min */
        "movl -0x64(%ebp), %eax\n" /* cinfo */
        "movl 0xc(%eax), %eax\n" /* cinfo */
        "movl %eax, -0x4c(%ebp)\n" /* cinfo, c1max */
        "movl -0x64(%ebp), %edx\n" /* line 327 */
        "movl 0x10(%edx), %edx\n"
        "movl %edx, -0x48(%ebp)\n" /* c2min */
        "movl -0x64(%ebp), %ecx\n"
        "movl 0x14(%ecx), %ecx\n"
        "movl %ecx, -0x44(%ebp)\n" /* c2max */
        "movl -0x54(%ebp), %eax\n" /* line 329 | c0max, cinfo */
        "cmpl %eax, -0x58(%ebp)\n" /* cinfo, c0min */
        "jge .Lf202db0_00202ef4\n"
        "movl -0x58(%ebp), %edx\n" /* c0min */
        "movl -0x60(%ebp), %ecx\n" /* histogram */
        "leal (%ecx, %edx, 4), %edx\n"
        "movl %edx, -0x24(%ebp)\n"
        "movl -0x58(%ebp), %ecx\n" /* c0min */
        "movl %ecx, -0x14(%ebp)\n"
        "movl -0x50(%ebp), %eax\n" /* c1min, cinfo */
        "shll $5, %eax\n" /* cinfo */
        "addl -0x48(%ebp), %eax\n" /* c2min, cinfo */
        "addl %eax, %eax\n" /* cinfo */
        "movl %eax, -0x68(%ebp)\n" /* cinfo */
        ".Lf202db0_00202e22:\n"
        "movl -0x4c(%ebp), %eax\n" /* line 331 | c1max, cinfo */
        "cmpl %eax, -0x50(%ebp)\n" /* cinfo, c1min */
        "jg .Lf202db0_002031b7\n"
        "movl -0x68(%ebp), %eax\n" /* cinfo */
        "movl -0x24(%ebp), %edx\n"
        "addl (%edx), %eax\n" /* cinfo */
        "leal 2(%eax), %esi\n" /* cinfo */
        "movl -0x50(%ebp), %edi\n" /* c1min, ccount */
        ".Lf202db0_00202e3c:\n"
        "movl -0x44(%ebp), %ecx\n" /* line 333 | c2max */
        "cmpl %ecx, -0x48(%ebp)\n" /* c2min */
        "jg .Lf202db0_002031a8\n"
        "movl %esi, %ecx\n" /* line 316 */
        "cmpw $0, -2(%esi)\n" /* line 334 */
        "jne .Lf202db0_00202e6b\n"
        "movl -0x48(%ebp), %edx\n" /* c2min */
        ".Lf202db0_00202e54:\n"
        "addl $1, %edx\n" /* line 333 */
        "cmpl %edx, -0x44(%ebp)\n" /* c2max */
        "jl .Lf202db0_002031a8\n"
        "movzwl (%ecx), %eax\n" /* line 334 | cinfo */
        "addl $2, %ecx\n"
        "testw %ax, %ax\n" /* cinfo */
        "je .Lf202db0_00202e54\n"
        ".Lf202db0_00202e6b:\n"
        "movl -0x14(%ebp), %ecx\n" /* line 335 */
        "movl -0x64(%ebp), %edx\n"
        "movl %ecx, (%edx)\n"
        "cmpl %ecx, -0x54(%ebp)\n" /* line 340 | c0max */
        "jle .Lf202db0_00203287\n"
        "movl %ecx, -0x58(%ebp)\n" /* c0min */
        ".Lf202db0_00202e7f:\n"
        "movl -0x54(%ebp), %eax\n" /* c0max, cinfo */
        "movl -0x60(%ebp), %edx\n" /* histogram */
        "leal (%edx, %eax, 4), %eax\n" /* cinfo */
        "movl %eax, -0x28(%ebp)\n" /* cinfo */
        "movl -0x54(%ebp), %edx\n" /* c0max */
        "movl %edx, -0x18(%ebp)\n"
        "movl -0x50(%ebp), %eax\n" /* c1min, cinfo */
        "shll $5, %eax\n" /* cinfo */
        "addl -0x48(%ebp), %eax\n" /* c2min, cinfo */
        "addl %eax, %eax\n" /* cinfo */
        "movl %eax, -0x6c(%ebp)\n" /* cinfo */
        ".Lf202db0_00202e9f:\n"
        "movl -0x4c(%ebp), %ecx\n" /* line 342 | c1max */
        "cmpl %ecx, -0x50(%ebp)\n" /* c1min */
        "jg .Lf202db0_0020322f\n"
        "movl -0x6c(%ebp), %eax\n" /* cinfo */
        "movl -0x28(%ebp), %edx\n"
        "addl (%edx), %eax\n" /* cinfo */
        "leal 2(%eax), %edi\n" /* cinfo, ccount */
        "movl -0x50(%ebp), %esi\n" /* c1min */
        ".Lf202db0_00202eb9:\n"
        "movl -0x44(%ebp), %ecx\n" /* line 344 | c2max */
        "cmpl %ecx, -0x48(%ebp)\n" /* c2min */
        "jg .Lf202db0_00203220\n"
        "movl %edi, %ecx\n" /* line 316 */
        "cmpw $0, -2(%edi)\n" /* line 345 | ccount */
        "jne .Lf202db0_00202ee8\n"
        "movl -0x48(%ebp), %edx\n" /* c2min */
        ".Lf202db0_00202ed1:\n"
        "addl $1, %edx\n" /* line 344 */
        "cmpl %edx, -0x44(%ebp)\n" /* c2max */
        "jl .Lf202db0_00203220\n"
        "movzwl (%ecx), %eax\n" /* line 345 | cinfo */
        "addl $2, %ecx\n"
        "testw %ax, %ax\n" /* cinfo */
        "je .Lf202db0_00202ed1\n"
        ".Lf202db0_00202ee8:\n"
        "movl -0x18(%ebp), %edx\n" /* line 346 */
        "movl -0x64(%ebp), %eax\n" /* cinfo */
        "movl %edx, 4(%eax)\n" /* cinfo */
        "movl %edx, -0x54(%ebp)\n" /* c0max */
        ".Lf202db0_00202ef4:\n"
        "movl -0x4c(%ebp), %edx\n" /* line 351 | c1max */
        "cmpl %edx, -0x50(%ebp)\n" /* c1min */
        "jge .Lf202db0_00202fe6\n"
        "movl -0x50(%ebp), %eax\n" /* line 316 | c1min, cinfo */
        "shll $5, %eax\n" /* cinfo */
        "addl -0x48(%ebp), %eax\n" /* c2min, cinfo */
        "addl %eax, %eax\n" /* cinfo */
        "movl %eax, -0x2c(%ebp)\n" /* cinfo */
        "movl -0x50(%ebp), %edi\n" /* c1min */
        "movl -0x58(%ebp), %ecx\n" /* c0min */
        "shll $2, %ecx\n"
        "movl %ecx, -0x70(%ebp)\n"
        ".Lf202db0_00202f1a:\n"
        "movl -0x58(%ebp), %eax\n" /* line 353 | c0min, cinfo */
        "cmpl %eax, -0x54(%ebp)\n" /* cinfo, c0max */
        "jl .Lf202db0_002031e3\n"
        "movl -0x60(%ebp), %esi\n" /* histogram */
        "addl -0x70(%ebp), %esi\n"
        "movl %eax, -0x5c(%ebp)\n" /* cinfo, c0 */
        ".Lf202db0_00202f2f:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 354 | cinfo */
        "addl (%esi), %eax\n" /* cinfo */
        "movl -0x44(%ebp), %edx\n" /* line 355 | c2max */
        "cmpl %edx, -0x48(%ebp)\n" /* c2min */
        "jg .Lf202db0_002031d0\n"
        "leal 2(%eax), %ecx\n" /* line 356 | cinfo */
        "cmpw $0, (%eax)\n" /* cinfo */
        "jne .Lf202db0_00202f63\n"
        "movl -0x48(%ebp), %edx\n" /* c2min */
        ".Lf202db0_00202f4c:\n"
        "addl $1, %edx\n" /* line 355 */
        "cmpl %edx, -0x44(%ebp)\n" /* c2max */
        "jl .Lf202db0_002031d0\n"
        "movzwl (%ecx), %eax\n" /* line 356 | cinfo */
        "addl $2, %ecx\n"
        "testw %ax, %ax\n" /* cinfo */
        "je .Lf202db0_00202f4c\n"
        ".Lf202db0_00202f63:\n"
        "movl -0x64(%ebp), %eax\n" /* line 357 | cinfo */
        "movl %edi, 8(%eax)\n" /* ccount, cinfo */
        "cmpl %edi, -0x4c(%ebp)\n" /* line 362 | ccount, c1max */
        "jle .Lf202db0_00203292\n"
        "movl %edi, -0x50(%ebp)\n" /* ccount, c1min */
        ".Lf202db0_00202f75:\n"
        "movl -0x4c(%ebp), %eax\n" /* c1max, cinfo */
        "shll $5, %eax\n" /* cinfo */
        "addl -0x48(%ebp), %eax\n" /* c2min, cinfo */
        "addl %eax, %eax\n" /* cinfo */
        "movl %eax, -0x30(%ebp)\n" /* cinfo */
        "movl -0x4c(%ebp), %edx\n" /* c1max */
        "movl %edx, -0x10(%ebp)\n"
        "movl -0x58(%ebp), %ecx\n" /* c0min */
        "shll $2, %ecx\n"
        "movl %ecx, -0x74(%ebp)\n"
        ".Lf202db0_00202f92:\n"
        "movl -0x58(%ebp), %eax\n" /* line 364 | c0min, cinfo */
        "cmpl %eax, -0x54(%ebp)\n" /* cinfo, c0max */
        "jl .Lf202db0_00203207\n"
        "movl -0x60(%ebp), %esi\n" /* histogram */
        "addl -0x74(%ebp), %esi\n"
        "movl %eax, %edi\n" /* cinfo, ccount */
        ".Lf202db0_00202fa6:\n"
        "movl -0x30(%ebp), %eax\n" /* line 365 | cinfo */
        "addl (%esi), %eax\n" /* cinfo */
        "movl -0x44(%ebp), %edx\n" /* line 366 | c2max */
        "cmpl %edx, -0x48(%ebp)\n" /* c2min */
        "jg .Lf202db0_002031f8\n"
        "leal 2(%eax), %ecx\n" /* line 367 | cinfo */
        "cmpw $0, (%eax)\n" /* cinfo */
        "jne .Lf202db0_00202fda\n"
        "movl -0x48(%ebp), %edx\n" /* c2min */
        ".Lf202db0_00202fc3:\n"
        "addl $1, %edx\n" /* line 366 */
        "cmpl %edx, -0x44(%ebp)\n" /* c2max */
        "jl .Lf202db0_002031f8\n"
        "movzwl (%ecx), %eax\n" /* line 367 | cinfo */
        "addl $2, %ecx\n"
        "testw %ax, %ax\n" /* cinfo */
        "je .Lf202db0_00202fc3\n"
        ".Lf202db0_00202fda:\n"
        "movl -0x10(%ebp), %eax\n" /* line 368 | cinfo */
        "movl -0x64(%ebp), %ecx\n"
        "movl %eax, 0xc(%ecx)\n" /* cinfo */
        "movl %eax, -0x4c(%ebp)\n" /* cinfo, c1max */
        ".Lf202db0_00202fe6:\n"
        "movl -0x44(%ebp), %ecx\n" /* line 373 | c2max */
        "cmpl %ecx, -0x48(%ebp)\n" /* c2min */
        "jge .Lf202db0_002030d2\n"
        "movl -0x50(%ebp), %eax\n" /* c1min, cinfo */
        "shll $5, %eax\n" /* cinfo */
        "movl %eax, -0x40(%ebp)\n" /* cinfo */
        "addl -0x48(%ebp), %eax\n" /* c2min, cinfo */
        "addl %eax, %eax\n" /* cinfo */
        "movl %eax, -0x34(%ebp)\n" /* cinfo */
        "movl -0x48(%ebp), %edi\n" /* c2min, ccount */
        "movl -0x58(%ebp), %edx\n" /* c0min */
        "shll $2, %edx\n"
        "movl %edx, -0x78(%ebp)\n"
        ".Lf202db0_0020300f:\n"
        "movl -0x58(%ebp), %ecx\n" /* line 375 | c0min */
        "cmpl %ecx, -0x54(%ebp)\n" /* c0max */
        "jl .Lf202db0_00203193\n"
        "movl -0x60(%ebp), %esi\n" /* histogram */
        "addl -0x78(%ebp), %esi\n"
        "movl %ecx, -0x20(%ebp)\n"
        ".Lf202db0_00203024:\n"
        "movl -0x34(%ebp), %eax\n" /* line 376 | cinfo */
        "addl (%esi), %eax\n" /* cinfo */
        "movl -0x50(%ebp), %edx\n" /* line 377 | c1min */
        "cmpl %edx, -0x4c(%ebp)\n" /* c1max */
        "jl .Lf202db0_00203180\n"
        "cmpw $0, (%eax)\n" /* line 378 | cinfo */
        "jne .Lf202db0_00203055\n"
        "movl %eax, %ecx\n" /* cinfo */
        ".Lf202db0_0020303d:\n"
        "addl $1, %edx\n" /* line 377 */
        "cmpl %edx, -0x4c(%ebp)\n" /* c1max */
        "jl .Lf202db0_00203180\n"
        "movzwl 0x40(%ecx), %eax\n" /* line 378 | cinfo */
        "addl $0x40, %ecx\n"
        "testw %ax, %ax\n" /* cinfo */
        "je .Lf202db0_0020303d\n"
        ".Lf202db0_00203055:\n"
        "movl -0x64(%ebp), %eax\n" /* line 379 | cinfo */
        "movl %edi, 0x10(%eax)\n" /* ccount, cinfo */
        "cmpl %edi, -0x44(%ebp)\n" /* line 384 | ccount, c2max */
        "jle .Lf202db0_0020327f\n"
        "movl %edi, -0x48(%ebp)\n" /* ccount, c2min */
        ".Lf202db0_00203067:\n"
        "movl -0x44(%ebp), %eax\n" /* c2max, cinfo */
        "addl -0x40(%ebp), %eax\n" /* cinfo */
        "addl %eax, %eax\n" /* cinfo */
        "movl %eax, -0x38(%ebp)\n" /* cinfo */
        "movl -0x44(%ebp), %edx\n" /* c2max */
        "movl %edx, -0xc(%ebp)\n"
        "movl -0x58(%ebp), %ecx\n" /* c0min */
        "shll $2, %ecx\n"
        "movl %ecx, -0x7c(%ebp)\n"
        ".Lf202db0_00203081:\n"
        "movl -0x58(%ebp), %eax\n" /* line 386 | c0min, cinfo */
        "cmpl %eax, -0x54(%ebp)\n" /* cinfo, c0max */
        "jl .Lf202db0_00203257\n"
        "movl -0x60(%ebp), %esi\n" /* histogram */
        "addl -0x7c(%ebp), %esi\n"
        "movl %eax, %edi\n" /* cinfo, ccount */
        ".Lf202db0_00203095:\n"
        "movl -0x38(%ebp), %eax\n" /* line 387 | cinfo */
        "addl (%esi), %eax\n" /* cinfo */
        "movl -0x50(%ebp), %edx\n" /* line 388 | c1min */
        "cmpl %edx, -0x4c(%ebp)\n" /* c1max */
        "jl .Lf202db0_00203248\n"
        "cmpw $0, (%eax)\n" /* line 389 | cinfo */
        "jne .Lf202db0_002030c6\n"
        "movl %eax, %ecx\n" /* cinfo */
        ".Lf202db0_002030ae:\n"
        "addl $1, %edx\n" /* line 388 */
        "cmpl %edx, -0x4c(%ebp)\n" /* c1max */
        "jl .Lf202db0_00203248\n"
        "movzwl 0x40(%ecx), %eax\n" /* line 389 | cinfo */
        "addl $0x40, %ecx\n"
        "testw %ax, %ax\n" /* cinfo */
        "je .Lf202db0_002030ae\n"
        ".Lf202db0_002030c6:\n"
        "movl -0xc(%ebp), %eax\n" /* line 390 | cinfo */
        "movl -0x64(%ebp), %ecx\n"
        "movl %eax, 0x14(%ecx)\n" /* cinfo */
        "movl %eax, -0x44(%ebp)\n" /* cinfo, c2max */
        ".Lf202db0_002030d2:\n"
        "movl -0x54(%ebp), %edx\n" /* line 404 | c0max */
        "subl -0x58(%ebp), %edx\n" /* c0min */
        "shll $3, %edx\n"
        "movl -0x4c(%ebp), %eax\n" /* line 405 | c1max, cinfo */
        "subl -0x50(%ebp), %eax\n" /* c1min, cinfo */
        "leal (, %eax, 8), %ecx\n"
        "leal (%ecx, %eax, 4), %eax\n" /* cinfo */
        "movl -0x44(%ebp), %ecx\n" /* line 406 | c2max */
        "subl -0x48(%ebp), %ecx\n" /* c2min */
        "shll $4, %ecx\n"
        "imull %edx, %edx\n" /* line 407 */
        "imull %eax, %eax\n" /* cinfo */
        "addl %eax, %edx\n" /* cinfo */
        "imull %ecx, %ecx\n"
        "addl %ecx, %edx\n"
        "movl -0x64(%ebp), %ecx\n"
        "movl %edx, 0x18(%ecx)\n"
        "movl -0x58(%ebp), %eax\n" /* line 411 | c0min, cinfo */
        "cmpl %eax, -0x54(%ebp)\n" /* cinfo, c0max */
        "jl .Lf202db0_00203270\n"
        "movl -0x60(%ebp), %edx\n" /* histogram */
        "leal (%edx, %eax, 4), %edx\n"
        "movl %edx, -0x3c(%ebp)\n"
        "movl %eax, -0x1c(%ebp)\n" /* cinfo */
        "xorl %edi, %edi\n" /* ccount */
        ".Lf202db0_00203121:\n"
        "movl -0x50(%ebp), %ecx\n" /* line 412 | c1min */
        "cmpl %ecx, -0x4c(%ebp)\n" /* c1max */
        "jl .Lf202db0_00203163\n"
        "movl %ecx, %eax\n" /* cinfo */
        "shll $5, %eax\n" /* cinfo */
        "addl -0x48(%ebp), %eax\n" /* c2min, cinfo */
        "movl -0x3c(%ebp), %ecx\n"
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 2), %esi\n"
        "movl -0x50(%ebp), %ecx\n" /* c1min */
        ".Lf202db0_0020313c:\n"
        "movl %esi, %edx\n" /* line 411 */
        "movl -0x48(%ebp), %eax\n" /* line 414 | c2min, cinfo */
        "cmpl %eax, -0x44(%ebp)\n" /* cinfo, c2max */
        "jl .Lf202db0_00203158\n"
        ".Lf202db0_00203146:\n"
        "cmpw $1, (%edx)\n" /* line 416 */
        "sbbl $-1, %edi\n" /* ccount */
        "addl $1, %eax\n" /* line 414 | cinfo */
        "addl $2, %edx\n"
        "cmpl %eax, -0x44(%ebp)\n" /* cinfo, c2max */
        "jge .Lf202db0_00203146\n"
        ".Lf202db0_00203158:\n"
        "addl $1, %ecx\n" /* line 412 */
        "addl $0x40, %esi\n"
        "cmpl %ecx, -0x4c(%ebp)\n" /* c1max */
        "jge .Lf202db0_0020313c\n"
        ".Lf202db0_00203163:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 411 */
        "addl $4, -0x3c(%ebp)\n"
        "movl -0x1c(%ebp), %edx\n"
        "cmpl %edx, -0x54(%ebp)\n" /* c0max */
        "jge .Lf202db0_00203121\n"
        "movl -0x64(%ebp), %eax\n" /* line 419 | cinfo */
        "movl %edi, 0x1c(%eax)\n" /* ccount, cinfo */
        "addl $0x74, %esp\n" /* line 420 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf202db0_00203180:\n"
        "addl $1, -0x20(%ebp)\n" /* line 375 */
        "addl $4, %esi\n"
        "movl -0x20(%ebp), %ecx\n"
        "cmpl %ecx, -0x54(%ebp)\n" /* c0max */
        "jge .Lf202db0_00203024\n"
        ".Lf202db0_00203193:\n"
        "addl $1, %edi\n" /* line 374 | ccount */
        "addl $2, -0x34(%ebp)\n"
        "cmpl %edi, -0x44(%ebp)\n" /* ccount, c2max */
        "jge .Lf202db0_0020300f\n"
        "jmp .Lf202db0_00203067\n"
        ".Lf202db0_002031a8:\n"
        "addl $1, %edi\n" /* line 331 | ccount */
        "addl $0x40, %esi\n"
        "cmpl %edi, -0x4c(%ebp)\n" /* ccount, c1max */
        "jge .Lf202db0_00202e3c\n"
        ".Lf202db0_002031b7:\n"
        "addl $1, -0x14(%ebp)\n" /* line 330 */
        "addl $4, -0x24(%ebp)\n"
        "movl -0x14(%ebp), %eax\n" /* cinfo */
        "cmpl %eax, -0x54(%ebp)\n" /* cinfo, c0max */
        "jge .Lf202db0_00202e22\n"
        "jmp .Lf202db0_00202e7f\n"
        ".Lf202db0_002031d0:\n"
        "addl $1, -0x5c(%ebp)\n" /* line 353 | c0 */
        "addl $4, %esi\n"
        "movl -0x5c(%ebp), %ecx\n" /* c0 */
        "cmpl %ecx, -0x54(%ebp)\n" /* c0max */
        "jge .Lf202db0_00202f2f\n"
        ".Lf202db0_002031e3:\n"
        "addl $1, %edi\n" /* line 352 | ccount */
        "addl $0x40, -0x2c(%ebp)\n"
        "cmpl %edi, -0x4c(%ebp)\n" /* ccount, c1max */
        "jge .Lf202db0_00202f1a\n"
        "jmp .Lf202db0_00202f75\n"
        ".Lf202db0_002031f8:\n"
        "addl $1, %edi\n" /* line 364 | ccount */
        "addl $4, %esi\n"
        "cmpl %edi, -0x54(%ebp)\n" /* ccount, c0max */
        "jge .Lf202db0_00202fa6\n"
        ".Lf202db0_00203207:\n"
        "subl $1, -0x10(%ebp)\n" /* line 363 */
        "subl $0x40, -0x30(%ebp)\n"
        "movl -0x50(%ebp), %edx\n" /* c1min */
        "cmpl %edx, -0x10(%ebp)\n"
        "jge .Lf202db0_00202f92\n"
        "jmp .Lf202db0_00202fe6\n"
        ".Lf202db0_00203220:\n"
        "addl $1, %esi\n" /* line 342 */
        "addl $0x40, %edi\n" /* ccount */
        "cmpl %esi, -0x4c(%ebp)\n" /* c1max */
        "jge .Lf202db0_00202eb9\n"
        ".Lf202db0_0020322f:\n"
        "subl $1, -0x18(%ebp)\n" /* line 341 */
        "subl $4, -0x28(%ebp)\n"
        "movl -0x58(%ebp), %ecx\n" /* c0min */
        "cmpl %ecx, -0x18(%ebp)\n"
        "jge .Lf202db0_00202e9f\n"
        "jmp .Lf202db0_00202ef4\n"
        ".Lf202db0_00203248:\n"
        "addl $1, %edi\n" /* line 386 | ccount */
        "addl $4, %esi\n"
        "cmpl %edi, -0x54(%ebp)\n" /* ccount, c0max */
        "jge .Lf202db0_00203095\n"
        ".Lf202db0_00203257:\n"
        "subl $1, -0xc(%ebp)\n" /* line 385 */
        "subl $2, -0x38(%ebp)\n"
        "movl -0x48(%ebp), %edx\n" /* c2min */
        "cmpl %edx, -0xc(%ebp)\n"
        "jge .Lf202db0_00203081\n"
        "jmp .Lf202db0_002030d2\n"
        ".Lf202db0_00203270:\n"
        "xorl %edi, %edi\n" /* line 412 | ccount */
        "movl -0x64(%ebp), %eax\n" /* line 419 | cinfo */
        "movl %edi, 0x1c(%eax)\n" /* ccount, cinfo */
        "addl $0x74, %esp\n" /* line 420 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf202db0_0020327f:\n"
        "movl %edi, -0x48(%ebp)\n" /* line 385 | ccount, c2min */
        "jmp .Lf202db0_002030d2\n"
        ".Lf202db0_00203287:\n"
        "movl -0x14(%ebp), %eax\n" /* line 341 | cinfo */
        "movl %eax, -0x58(%ebp)\n" /* cinfo, c0min */
        "jmp .Lf202db0_00202ef4\n"
        ".Lf202db0_00203292:\n"
        "movl %edi, -0x50(%ebp)\n" /* line 363 | ccount, c1min */
        "jmp .Lf202db0_00202fe6\n"
    );
}

/* line 859 */
static __attribute__((naked))
void fill_inverse_cmap(j_decompress_ptr cinfo, int c2)
{
    __asm__ __volatile__ (
        /* { scope 1: numcolors, maxc0, maxc1, maxc2, ... */
        "pushl %ebp\n" /* line 859 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x640, %esp\n"
        "movl %eax, -0x61c(%ebp)\n"
        "movl %edx, -0x58c(%ebp)\n" /* c0 */
        "movl %ecx, -0x590(%ebp)\n" /* c1 */
        "movl 0x1b0(%eax), %eax\n" /* line 861 */
        "movl 0x18(%eax), %eax\n"
        "movl %eax, -0x618(%ebp)\n" /* histogram */
        "sarl $2, -0x58c(%ebp)\n" /* line 873 */
        "sarl $3, %ecx\n" /* line 874 | c1 */
        "movl %ecx, -0x590(%ebp)\n" /* c1 */
        "sarl $2, 8(%ebp)\n" /* line 875 | c2 */
        "movl -0x58c(%ebp), %eax\n" /* line 881 */
        "shll $5, %eax\n"
        "leal 4(%eax), %ecx\n" /* c1 */
        "movl %ecx, -0x614(%ebp)\n" /* c1, minc0 */
        "movl -0x590(%ebp), %edx\n" /* line 882 | c0 */
        "shll $5, %edx\n" /* c0 */
        "leal 2(%edx), %esi\n" /* c0, cachep */
        "movl %esi, -0x610(%ebp)\n" /* cachep, minc1 */
        "movl 8(%ebp), %ecx\n" /* line 883 | c2, c1 */
        "shll $5, %ecx\n" /* c1 */
        "leal 4(%ecx), %esi\n" /* c1, cachep */
        "movl %esi, -0x60c(%ebp)\n" /* cachep, minc2 */
        /* { scope 2 */
        "movl -0x61c(%ebp), %esi\n" /* line 657 */
        "movl 0x78(%esi), %esi\n"
        "movl %esi, -0x5f4(%ebp)\n" /* numcolors */
        "addl $0x1c, %eax\n" /* line 670 */
        "movl %eax, -0x5f0(%ebp)\n" /* maxc0 */
        "movl -0x614(%ebp), %esi\n" /* line 671 | minc0 */
        "addl %eax, %esi\n"
        "sarl $1, %esi\n"
        "movl %esi, -0x5e4(%ebp)\n" /* centerc0 */
        "addl $0x1e, %edx\n" /* line 672 */
        "movl %edx, -0x5ec(%ebp)\n" /* maxc1 */
        "movl -0x610(%ebp), %eax\n" /* line 673 | minc1 */
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "movl %eax, -0x5e0(%ebp)\n" /* centerc1 */
        "addl $0x1c, %ecx\n" /* line 674 */
        "movl %ecx, -0x5e8(%ebp)\n" /* maxc2 */
        "movl -0x60c(%ebp), %edx\n" /* line 675 | minc2 */
        "addl %ecx, %edx\n"
        "sarl $1, %edx\n"
        "movl %edx, -0x5dc(%ebp)\n" /* centerc2 */
        "movl -0x5f4(%ebp), %esi\n" /* line 687 | numcolors */
        "testl %esi, %esi\n"
        "jg .Lf20329a_00203692\n"
        "movl $0, -0x604(%ebp)\n" /* numcolors */
        ".Lf20329a_0020337f:\n"
        "leal -0x584(%ebp), %eax\n" /* line 766 */
        "leal -0x384(%ebp), %edx\n"
        /* } scope */
        /* { scope 2 */
        ".Lf20329a_0020338b:\n"
        "movl $0x7fffffff, -4(%eax)\n" /* line 799 */
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n" /* line 798 */
        "jne .Lf20329a_0020338b\n"
        "movl -0x604(%ebp), %ecx\n" /* line 811 | numcolors */
        "testl %ecx, %ecx\n"
        "jg .Lf20329a_00203476\n"
        "leal -0x88(%ebp), %ecx\n" /* bestcolor */
        "movl %ecx, -0x628(%ebp)\n"
        "movl %ecx, %esi\n" /* cptr */
        /* } scope */
        ".Lf20329a_002033b5:\n"
        "shll $4, -0x58c(%ebp)\n" /* line 896 */
        "movl -0x618(%ebp), %ecx\n" /* histogram, c1 */
        "addl -0x58c(%ebp), %ecx\n" /* c1 */
        "movl %ecx, -0x5b0(%ebp)\n" /* c1 */
        "movl %esi, -0x5b4(%ebp)\n" /* cachep */
        "shll $8, -0x590(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* c2 */
        "movl -0x590(%ebp), %edx\n" /* c0 */
        "leal (%edx, %eax, 4), %eax\n" /* c0 */
        "movl %eax, -0x620(%ebp)\n"
        "movl %eax, %ecx\n" /* c1 */
        ".Lf20329a_002033ef:\n"
        "addl %ecx, %ecx\n" /* c1 */
        "movl %ecx, -0x5b8(%ebp)\n" /* c1 */
        "movl -0x5b4(%ebp), %ecx\n" /* c1 */
        "movl $0, -0x608(%ebp)\n" /* ic1 */
        ".Lf20329a_00203407:\n"
        "movl %ecx, %edi\n" /* c1, cptr */
        "movl -0x5b8(%ebp), %esi\n" /* line 901 | cachep */
        "movl -0x5b0(%ebp), %eax\n"
        "addl (%eax), %esi\n" /* cachep */
        "movl $4, %edx\n" /* c0 */
        ".Lf20329a_0020341c:\n"
        "movzbw (%edi), %ax\n" /* line 903 | cptr */
        "addl $1, %eax\n"
        "movw %ax, (%esi)\n" /* cachep */
        "addl $2, %esi\n" /* cachep */
        "addl $1, %edi\n" /* cptr */
        "subl $1, %edx\n" /* line 902 | c0 */
        "jne .Lf20329a_0020341c\n"
        "addl $1, -0x608(%ebp)\n" /* line 900 | ic1 */
        "addl $0x40, -0x5b8(%ebp)\n"
        "addl $4, %ecx\n" /* c1 */
        "cmpl $8, -0x608(%ebp)\n" /* ic1 */
        "jne .Lf20329a_00203407\n"
        "addl $0x20, -0x5b4(%ebp)\n"
        "addl $4, -0x5b0(%ebp)\n"
        "leal -8(%ebp), %edx\n" /* line 899 | c0 */
        "cmpl -0x5b4(%ebp), %edx\n" /* c0 */
        "je .Lf20329a_0020346c\n"
        "movl -0x620(%ebp), %ecx\n" /* c1 */
        "jmp .Lf20329a_002033ef\n"
        ".Lf20329a_0020346c:\n"
        "addl $0x640, %esp\n" /* line 907 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2 */
        ".Lf20329a_00203476:\n"
        "movl $0, -0x5d8(%ebp)\n" /* line 798 | i */
        "movl -0x61c(%ebp), %esi\n" /* cptr */
        "movl 0x7c(%esi), %esi\n" /* cptr */
        "movl %esi, -0x624(%ebp)\n" /* cptr */
        "leal -0x188(%ebp), %eax\n" /* colorlist */
        "movl %eax, -0x62c(%ebp)\n"
        "leal -0x588(%ebp), %edx\n" /* mindist */
        "movl %edx, -0x634(%ebp)\n"
        "leal -0x88(%ebp), %ecx\n" /* bestcolor */
        "movl %ecx, -0x628(%ebp)\n"
        "leal -0x388(%ebp), %esi\n" /* cptr */
        "movl %esi, -0x630(%ebp)\n" /* cptr */
        "movl %eax, %edx\n"
        ".Lf20329a_002034c1:\n"
        "movl -0x5d8(%ebp), %eax\n" /* line 812 | i */
        "movzbl (%eax, %edx), %eax\n"
        "movl %eax, -0x5d4(%ebp)\n" /* icolor */
        "movl -0x624(%ebp), %ecx\n" /* line 814 */
        "movl (%ecx), %eax\n"
        "movl -0x5d4(%ebp), %esi\n" /* icolor, cptr */
        "movzbl (%eax, %esi), %eax\n"
        "movl -0x614(%ebp), %edi\n" /* minc0, inc0 */
        "subl %eax, %edi\n" /* inc0 */
        "movl %edi, %eax\n" /* line 815 | inc0 */
        "imull %edi, %eax\n" /* inc0 */
        "movl %eax, -0x5d0(%ebp)\n" /* dist0 */
        "movl 4(%ecx), %eax\n" /* line 816 */
        "movzbl (%esi, %eax), %eax\n" /* cptr */
        "movl -0x610(%ebp), %ecx\n" /* minc1 */
        "subl %eax, %ecx\n"
        "leal (%ecx, %ecx, 2), %edx\n"
        "movl -0x624(%ebp), %esi\n" /* line 818 | cptr */
        "movl 8(%esi), %eax\n" /* cptr */
        "movl -0x5d4(%ebp), %esi\n" /* icolor, cptr */
        "movzbl (%esi, %eax), %eax\n" /* cptr */
        "movl -0x60c(%ebp), %esi\n" /* minc2, cptr */
        "subl %eax, %esi\n" /* cptr */
        "leal (%esi, %esi), %eax\n" /* cptr */
        "imull %edx, %edx\n" /* line 819 */
        "addl -0x5d0(%ebp), %edx\n" /* dist0 */
        "imull %eax, %eax\n"
        "leal (%edx, %eax), %eax\n"
        "movl %eax, -0x5cc(%ebp)\n" /* dist2 */
        "shll $4, %edi\n" /* line 821 | inc0 */
        "addl $0x40, %edi\n" /* inc0 */
        "movl %edi, -0x5c8(%ebp)\n" /* inc0, xx0 */
        "leal (%ecx, %ecx, 8), %ecx\n" /* line 822 */
        "leal 0x90(, %ecx, 8), %ecx\n"
        "movl %ecx, -0x5c4(%ebp)\n" /* xx1 */
        "shll $6, %esi\n" /* line 823 | cptr */
        "addl $0x100, %esi\n" /* cptr */
        "movl %esi, -0x5c0(%ebp)\n" /* cptr, xx2 */
        "movl -0x634(%ebp), %eax\n"
        "movl %eax, -0x5a4(%ebp)\n"
        "movl -0x628(%ebp), %edx\n"
        "movl %edx, -0x5a0(%ebp)\n"
        "movl %edx, %ecx\n"
        "movl %eax, %esi\n" /* cptr */
        ".Lf20329a_00203582:\n"
        "movl %ecx, -0x5ac(%ebp)\n"
        "movl %esi, -0x5a8(%ebp)\n" /* cptr */
        "movl -0x5cc(%ebp), %eax\n" /* dist2 */
        "movl %eax, -0x598(%ebp)\n"
        "movl -0x5c4(%ebp), %edx\n" /* xx1 */
        "movl %edx, -0x594(%ebp)\n"
        "movl $8, -0x5bc(%ebp)\n"
        "movl %esi, %ecx\n" /* cptr */
        ".Lf20329a_002035b2:\n"
        "movl -0x5ac(%ebp), %esi\n" /* cptr */
        "movl -0x5c0(%ebp), %edx\n" /* xx2 */
        "movl %edx, -0x63c(%ebp)\n"
        "movl $4, %edi\n" /* inc0 */
        ".Lf20329a_002035c9:\n"
        "cmpl %eax, (%ecx)\n" /* line 835 */
        "jle .Lf20329a_002035d8\n"
        "movl %eax, (%ecx)\n" /* line 836 */
        "movzbl -0x5d4(%ebp), %edx\n" /* line 837 | icolor */
        "movb %dl, (%esi)\n" /* cptr */
        ".Lf20329a_002035d8:\n"
        "addl -0x63c(%ebp), %eax\n" /* line 839 */
        "addl $0x200, -0x63c(%ebp)\n" /* line 840 */
        "addl $4, %ecx\n" /* line 841 */
        "addl $1, %esi\n" /* line 842 | cptr */
        "subl $1, %edi\n" /* line 834 | inc0 */
        "jne .Lf20329a_002035c9\n"
        "movl -0x594(%ebp), %ecx\n" /* line 844 */
        "addl %ecx, -0x598(%ebp)\n"
        "addl $0x120, %ecx\n" /* line 845 */
        "movl %ecx, -0x594(%ebp)\n"
        "addl $4, -0x5ac(%ebp)\n"
        "addl $0x10, -0x5a8(%ebp)\n"
        "subl $1, -0x5bc(%ebp)\n" /* line 831 */
        "je .Lf20329a_00203630\n"
        "movl -0x5a8(%ebp), %ecx\n"
        "movl -0x598(%ebp), %eax\n"
        "jmp .Lf20329a_002035b2\n"
        ".Lf20329a_00203630:\n"
        "movl -0x5c8(%ebp), %esi\n" /* line 847 | xx0, cptr */
        "addl %esi, -0x5cc(%ebp)\n" /* cptr, dist2 */
        "subl $-0x80, %esi\n" /* line 848 | cptr */
        "movl %esi, -0x5c8(%ebp)\n" /* cptr, xx0 */
        "subl $-0x80, -0x5a4(%ebp)\n"
        "addl $0x20, -0x5a0(%ebp)\n"
        "movl -0x5a4(%ebp), %eax\n" /* line 828 */
        "cmpl %eax, -0x630(%ebp)\n"
        "je .Lf20329a_0020366e\n"
        "movl -0x5a0(%ebp), %ecx\n"
        "movl %eax, %esi\n" /* cptr */
        "jmp .Lf20329a_00203582\n"
        ".Lf20329a_0020366e:\n"
        "addl $1, -0x5d8(%ebp)\n" /* line 811 | i */
        "movl -0x604(%ebp), %edx\n" /* numcolors */
        "cmpl %edx, -0x5d8(%ebp)\n" /* i */
        "je .Lf20329a_002038b6\n"
        "movl -0x62c(%ebp), %edx\n"
        "jmp .Lf20329a_002034c1\n"
        /* } scope */
        /* { scope 2 */
        ".Lf20329a_00203692:\n"
        "movl -0x61c(%ebp), %ecx\n" /* line 689 */
        "movl 0x7c(%ecx), %ecx\n"
        "movl %ecx, -0x624(%ebp)\n"
        "movl (%ecx), %esi\n"
        "movl %esi, -0x600(%ebp)\n"
        "movl 4(%ecx), %eax\n" /* line 712 */
        "movl %eax, -0x5fc(%ebp)\n"
        "movl 8(%ecx), %edx\n" /* line 734 */
        "movl %edx, -0x5f8(%ebp)\n"
        "xorl %ecx, %ecx\n"
        "movl $0x7fffffff, -0x59c(%ebp)\n"
        "jmp .Lf20329a_00203779\n"
        ".Lf20329a_002036cc:\n"
        "movl %eax, %edx\n" /* line 691 */
        "subl -0x614(%ebp), %edx\n" /* minc0 */
        "imull %edx, %edx\n" /* line 692 */
        "movl %eax, %edi\n" /* line 693 | max_dist */
        "subl -0x5f0(%ebp), %edi\n" /* maxc0, max_dist */
        "imull %edi, %edi\n" /* line 694 | max_dist */
        ".Lf20329a_002036e2:\n"
        "movl -0x5fc(%ebp), %eax\n" /* line 712 */
        "movzbl (%eax, %ecx), %esi\n"
        "cmpl %esi, -0x610(%ebp)\n" /* line 713 | minc1 */
        "jle .Lf20329a_002037c1\n"
        ".Lf20329a_002036f8:\n"
        "movl %esi, %eax\n" /* line 714 */
        "subl -0x610(%ebp), %eax\n" /* minc1 */
        "leal (%eax, %eax, 2), %eax\n"
        "imull %eax, %eax\n" /* line 715 */
        "addl %eax, %edx\n"
        "subl -0x5ec(%ebp), %esi\n" /* line 716 | maxc1 */
        "leal (%esi, %esi, 2), %eax\n"
        "imull %eax, %eax\n" /* line 717 */
        "addl %eax, %edi\n" /* max_dist */
        ".Lf20329a_00203716:\n"
        "movl -0x5f8(%ebp), %eax\n" /* line 734 */
        "movzbl (%eax, %ecx), %esi\n"
        "cmpl %esi, -0x60c(%ebp)\n" /* line 735 | minc2 */
        "jle .Lf20329a_00203801\n"
        ".Lf20329a_0020372c:\n"
        "movl %esi, %eax\n" /* line 736 */
        "subl -0x60c(%ebp), %eax\n" /* minc2 */
        "addl %eax, %eax\n"
        "imull %eax, %eax\n" /* line 737 */
        "addl %eax, %edx\n"
        "subl -0x5e8(%ebp), %esi\n" /* line 738 | maxc2 */
        "leal (%esi, %esi), %eax\n"
        "imull %eax, %eax\n" /* line 739 */
        "leal (%edi, %eax), %eax\n" /* max_dist */
        ".Lf20329a_0020374a:\n"
        "movl %edx, -0x588(%ebp, %ecx, 4)\n" /* line 756 */
        "cmpl -0x59c(%ebp), %eax\n" /* line 757 */
        "cmovgel -0x59c(%ebp), %eax\n"
        "movl %eax, -0x59c(%ebp)\n"
        "addl $1, %ecx\n" /* line 687 */
        "cmpl %ecx, -0x5f4(%ebp)\n" /* numcolors */
        "je .Lf20329a_002038c1\n"
        "movl -0x600(%ebp), %esi\n"
        ".Lf20329a_00203779:\n"
        "movzbl (%esi, %ecx), %eax\n" /* line 689 */
        "cmpl %eax, -0x614(%ebp)\n" /* line 690 | minc0 */
        "jg .Lf20329a_002036cc\n"
        "cmpl %eax, -0x5f0(%ebp)\n" /* line 695 | maxc0 */
        "jge .Lf20329a_0020382c\n"
        "movl %eax, %edx\n" /* line 696 */
        "subl -0x5f0(%ebp), %edx\n" /* maxc0 */
        "imull %edx, %edx\n" /* line 697 */
        "movl %eax, %edi\n" /* line 698 | max_dist */
        "subl -0x614(%ebp), %edi\n" /* minc0, max_dist */
        "imull %edi, %edi\n" /* line 699 | max_dist */
        "movl -0x5fc(%ebp), %eax\n" /* line 712 */
        "movzbl (%eax, %ecx), %esi\n"
        "cmpl %esi, -0x610(%ebp)\n" /* line 713 | minc1 */
        "jg .Lf20329a_002036f8\n"
        ".Lf20329a_002037c1:\n"
        "cmpl %esi, -0x5ec(%ebp)\n" /* line 718 | maxc1 */
        "jge .Lf20329a_00203862\n"
        "movl %esi, %eax\n" /* line 719 */
        "subl -0x5ec(%ebp), %eax\n" /* maxc1 */
        "leal (%eax, %eax, 2), %eax\n"
        "imull %eax, %eax\n" /* line 720 */
        "addl %eax, %edx\n"
        "subl -0x610(%ebp), %esi\n" /* line 721 | minc1 */
        "leal (%esi, %esi, 2), %eax\n"
        "imull %eax, %eax\n" /* line 722 */
        "addl %eax, %edi\n" /* max_dist */
        "movl -0x5f8(%ebp), %eax\n" /* line 734 */
        "movzbl (%eax, %ecx), %esi\n"
        "cmpl %esi, -0x60c(%ebp)\n" /* line 735 | minc2 */
        "jg .Lf20329a_0020372c\n"
        ".Lf20329a_00203801:\n"
        "cmpl %esi, -0x5e8(%ebp)\n" /* line 740 | maxc2 */
        "jge .Lf20329a_00203846\n"
        "movl %esi, %eax\n" /* line 741 */
        "subl -0x5e8(%ebp), %eax\n" /* maxc2 */
        "addl %eax, %eax\n"
        "imull %eax, %eax\n" /* line 742 */
        "addl %eax, %edx\n"
        "subl -0x60c(%ebp), %esi\n" /* line 743 | minc2 */
        "leal (%esi, %esi), %eax\n"
        "imull %eax, %eax\n" /* line 744 */
        "leal (%edi, %eax), %eax\n" /* max_dist */
        "jmp .Lf20329a_0020374a\n"
        ".Lf20329a_0020382c:\n"
        "cmpl %eax, -0x5e4(%ebp)\n" /* line 703 | centerc0 */
        "jl .Lf20329a_0020387d\n"
        "movl %eax, %edi\n" /* line 704 | max_dist */
        "subl -0x5f0(%ebp), %edi\n" /* maxc0, max_dist */
        "imull %edi, %edi\n" /* line 705 | max_dist */
        "xorl %edx, %edx\n"
        "jmp .Lf20329a_002036e2\n"
        ".Lf20329a_00203846:\n"
        "cmpl %esi, -0x5dc(%ebp)\n" /* line 747 | centerc2 */
        "jl .Lf20329a_0020388f\n"
        "subl -0x5e8(%ebp), %esi\n" /* line 748 | maxc2 */
        "leal (%esi, %esi), %eax\n"
        "imull %eax, %eax\n" /* line 749 */
        "leal (%edi, %eax), %eax\n" /* max_dist */
        "jmp .Lf20329a_0020374a\n"
        ".Lf20329a_00203862:\n"
        "cmpl %esi, -0x5e0(%ebp)\n" /* line 725 | centerc1 */
        "jl .Lf20329a_002038a3\n"
        "subl -0x5ec(%ebp), %esi\n" /* line 726 | maxc1 */
        "leal (%esi, %esi, 2), %eax\n"
        "imull %eax, %eax\n" /* line 727 */
        "addl %eax, %edi\n" /* max_dist */
        "jmp .Lf20329a_00203716\n"
        ".Lf20329a_0020387d:\n"
        "movl %eax, %edi\n" /* line 707 | max_dist */
        "subl -0x614(%ebp), %edi\n" /* minc0, max_dist */
        "imull %edi, %edi\n" /* line 708 | max_dist */
        "xorl %edx, %edx\n"
        "jmp .Lf20329a_002036e2\n"
        ".Lf20329a_0020388f:\n"
        "subl -0x60c(%ebp), %esi\n" /* line 751 | minc2 */
        "leal (%esi, %esi), %eax\n"
        "imull %eax, %eax\n" /* line 752 */
        "leal (%edi, %eax), %eax\n" /* max_dist */
        "jmp .Lf20329a_0020374a\n"
        ".Lf20329a_002038a3:\n"
        "subl -0x610(%ebp), %esi\n" /* line 729 | minc1 */
        "leal (%esi, %esi, 2), %eax\n"
        "imull %eax, %eax\n" /* line 730 */
        "addl %eax, %edi\n" /* max_dist */
        "jmp .Lf20329a_00203716\n"
        ".Lf20329a_002038b6:\n"
        "movl -0x628(%ebp), %esi\n"
        "jmp .Lf20329a_002033b5\n"
        ".Lf20329a_002038c1:\n"
        "xorl %eax, %eax\n" /* line 687 */
        "movl $0, -0x604(%ebp)\n" /* numcolors */
        ".Lf20329a_002038cd:\n"
        "movl -0x59c(%ebp), %edx\n" /* line 767 */
        "cmpl %edx, -0x588(%ebp, %eax, 4)\n"
        "jg .Lf20329a_002038f2\n"
        "movl -0x604(%ebp), %ecx\n" /* line 768 | numcolors */
        "movb %al, -0x188(%ebp, %ecx)\n"
        "addl $1, %ecx\n"
        "movl %ecx, -0x604(%ebp)\n" /* numcolors */
        ".Lf20329a_002038f2:\n"
        "addl $1, %eax\n" /* line 766 */
        "cmpl %eax, -0x5f4(%ebp)\n" /* numcolors */
        "jne .Lf20329a_002038cd\n"
        "jmp .Lf20329a_0020337f\n"
    );
}

/* line 918 */
static __attribute__((naked))
void pass2_no_dither(j_decompress_ptr cinfo, JSAMPARRAY input_buf, JSAMPARRAY output_buf, int num_rows)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 918 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x40, %esp\n"
        "movl 8(%ebp), %edx\n" /* line 920 | cinfo */
        "movl 0x1b0(%edx), %eax\n"
        "movl 0x18(%eax), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* histogram */
        "movl 0x64(%edx), %esi\n" /* line 926 | cachep */
        "movl %esi, -0xc(%ebp)\n" /* cachep, width */
        "movl 0x14(%ebp), %ecx\n" /* line 928 | num_rows */
        "testl %ecx, %ecx\n"
        "jle .Lf203902_002039f1\n"
        "movl $0, -0x10(%ebp)\n" /* row */
        "movl -0x10(%ebp), %eax\n" /* row */
        ".Lf203902_00203934:\n"
        "shll $2, %eax\n" /* line 918 */
        "movl 0xc(%ebp), %edx\n" /* line 929 | input_buf */
        "movl (%edx, %eax), %edi\n" /* inptr */
        "movl 0x10(%ebp), %esi\n" /* line 930 | output_buf, cachep */
        "movl (%esi, %eax), %eax\n" /* cachep */
        "movl -0xc(%ebp), %edx\n" /* line 931 | width */
        "testl %edx, %edx\n"
        "je .Lf203902_002039e1\n"
        "movl %eax, -0x1c(%ebp)\n" /* outptr */
        "movl -0xc(%ebp), %edx\n" /* width */
        "leal (%eax, %edx), %edx\n"
        "movl %edx, -0x24(%ebp)\n"
        "jmp .Lf203902_00203973\n"
        ".Lf203902_0020395c:\n"
        "movzbl (%esi), %eax\n" /* line 942 | cachep */
        "subb $1, %al\n"
        "movl -0x1c(%ebp), %edx\n" /* outptr */
        "movb %al, (%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* outptr */
        "movl -0x24(%ebp), %esi\n" /* line 931 | cachep */
        "cmpl %esi, %edx\n" /* cachep */
        "je .Lf203902_002039e1\n"
        ".Lf203902_00203973:\n"
        "movzbl (%edi), %eax\n" /* line 933 | inptr */
        "shrb $3, %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, -0x18(%ebp)\n" /* c0 */
        "movzbl 1(%edi), %eax\n" /* line 934 | inptr */
        "shrb $2, %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, -0x14(%ebp)\n" /* c1 */
        "movzbl 2(%edi), %eax\n" /* line 935 | inptr */
        "shrb $3, %al\n"
        "movzbl %al, %ecx\n"
        "addl $3, %edi\n" /* inptr */
        "movl -0x14(%ebp), %eax\n" /* line 936 | c1 */
        "shll $5, %eax\n"
        "addl %ecx, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl -0x18(%ebp), %esi\n" /* c0, cachep */
        "movl -0x20(%ebp), %eax\n" /* histogram */
        "movl (%eax, %esi, 4), %edx\n"
        "movl -0x2c(%ebp), %eax\n"
        "leal (%edx, %eax, 2), %esi\n" /* cachep */
        "cmpw $0, (%esi)\n" /* line 939 | cachep */
        "jne .Lf203902_0020395c\n"
        "movl %ecx, (%esp)\n" /* line 940 */
        "movl -0x14(%ebp), %ecx\n" /* c1 */
        "movl -0x18(%ebp), %edx\n" /* c0 */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "calll fill_inverse_cmap\n"
        "movzbl (%esi), %eax\n" /* line 942 | cachep */
        "subb $1, %al\n"
        "movl -0x1c(%ebp), %edx\n" /* outptr */
        "movb %al, (%edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* outptr */
        "movl -0x24(%ebp), %esi\n" /* line 931 | cachep */
        "cmpl %esi, %edx\n" /* cachep */
        "jne .Lf203902_00203973\n"
        ".Lf203902_002039e1:\n"
        "addl $1, -0x10(%ebp)\n" /* line 928 | row */
        "movl -0x10(%ebp), %eax\n" /* row */
        "cmpl %eax, 0x14(%ebp)\n" /* num_rows */
        "jne .Lf203902_00203934\n"
        ".Lf203902_002039f1:\n"
        "addl $0x40, %esp\n" /* line 945 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 952 */
static __attribute__((naked))
void pass2_fs_dither(j_decompress_ptr cinfo, JSAMPARRAY input_buf, JSAMPARRAY output_buf, int num_rows)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 952 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0xc0, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 953 | cinfo */
        "movl 0x1b0(%eax), %eax\n"
        "movl %eax, -0x80(%ebp)\n" /* cquantize */
        "movl 0x18(%eax), %edx\n" /* line 954 */
        "movl %edx, -0x7c(%ebp)\n" /* histogram */
        "movl 8(%ebp), %ecx\n" /* line 966 | cinfo */
        "movl 0x64(%ecx), %ecx\n"
        "movl %ecx, -0x3c(%ebp)\n" /* width */
        "movl 8(%ebp), %esi\n" /* line 967 | cinfo */
        "movl 0x128(%esi), %esi\n"
        "movl %esi, -0x38(%ebp)\n" /* range_limit */
        "movl 0x28(%eax), %edi\n" /* line 968 | cachep */
        "movl %edi, -0x34(%ebp)\n" /* cachep, error_limit */
        "movl 8(%ebp), %edx\n" /* line 969 | cinfo */
        "movl 0x7c(%edx), %eax\n"
        "movl (%eax), %ecx\n"
        "movl %ecx, -0x30(%ebp)\n" /* colormap0 */
        "movl 4(%eax), %esi\n" /* line 970 */
        "movl %esi, -0x2c(%ebp)\n" /* colormap1 */
        "movl 8(%eax), %eax\n" /* line 971 */
        "movl %eax, -0x28(%ebp)\n" /* colormap2 */
        "movl 0x14(%ebp), %edi\n" /* line 974 | num_rows, cachep */
        "testl %edi, %edi\n" /* cachep */
        "jle .Lf2039f8_00203d56\n"
        "movl -0x3c(%ebp), %edi\n" /* line 979 | width, cachep */
        "leal (%edi, %edi, 2), %edi\n" /* cachep */
        "movl %edi, -0x88(%ebp)\n" /* cachep */
        "addl %edi, %edi\n" /* line 983 | cachep */
        "movl %edi, -0x8c(%ebp)\n" /* cachep */
        "movl $0, -0x40(%ebp)\n" /* row */
        "movl -0x40(%ebp), %eax\n" /* row */
        "jmp .Lf2039f8_00203ad5\n"
        ".Lf2039f8_00203a72:\n"
        "movl -0x88(%ebp), %edi\n" /* line 979 | cachep */
        "leal -3(%edx, %edi), %edi\n" /* cachep */
        "movl %edi, -0x50(%ebp)\n" /* cachep, inptr */
        "movl -0x3c(%ebp), %edx\n" /* line 980 | width */
        "leal -1(%eax, %edx), %edx\n"
        "movl %edx, -0x4c(%ebp)\n" /* outptr */
        "movl -0x8c(%ebp), %eax\n" /* line 983 */
        "addl 0x20(%esi), %eax\n"
        "addl $6, %eax\n"
        "movl %eax, -0x54(%ebp)\n" /* errorptr */
        "movb $0, 0x24(%esi)\n" /* line 984 */
        "movl $0xffffffff, -0x48(%ebp)\n" /* dir */
        "movl $0xfffffffd, -0x44(%ebp)\n" /* dir3 */
        "movl -0x3c(%ebp), %esi\n" /* line 998 | width */
        "testl %esi, %esi\n"
        "jne .Lf2039f8_00203b19\n"
        ".Lf2039f8_00203ab1:\n"
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        "movl -0x54(%ebp), %edi\n" /* line 1083 | errorptr, cachep */
        "movw %cx, (%edi)\n" /* cachep */
        "movw %dx, 2(%edi)\n" /* line 1084 | cachep */
        "movw %ax, 4(%edi)\n" /* line 1085 | cachep */
        "addl $1, -0x40(%ebp)\n" /* line 974 | row */
        "movl -0x40(%ebp), %eax\n" /* row */
        "cmpl %eax, 0x14(%ebp)\n" /* num_rows */
        "je .Lf2039f8_00203d56\n"
        ".Lf2039f8_00203ad5:\n"
        "shll $2, %eax\n" /* line 952 */
        "movl 0xc(%ebp), %edx\n" /* line 975 | input_buf */
        "movl (%edx, %eax), %edx\n"
        "movl %edx, -0x50(%ebp)\n" /* inptr */
        "movl 0x10(%ebp), %ecx\n" /* line 976 | output_buf */
        "movl (%ecx, %eax), %eax\n"
        "movl %eax, -0x4c(%ebp)\n" /* outptr */
        "movl -0x80(%ebp), %esi\n" /* line 977 | cquantize */
        "cmpb $0, 0x24(%esi)\n"
        "jne .Lf2039f8_00203a72\n"
        "movl 0x20(%esi), %ecx\n" /* line 989 */
        "movl %ecx, -0x54(%ebp)\n" /* errorptr */
        "movl -0x80(%ebp), %esi\n" /* line 990 | cquantize */
        "movb $1, 0x24(%esi)\n"
        "movl $1, -0x48(%ebp)\n" /* dir */
        "movl $3, -0x44(%ebp)\n" /* dir3 */
        "movl -0x3c(%ebp), %esi\n" /* line 998 | width */
        "testl %esi, %esi\n"
        "je .Lf2039f8_00203ab1\n"
        ".Lf2039f8_00203b19:\n"
        "movl -0x44(%ebp), %edi\n" /* dir3, cachep */
        "addl %edi, %edi\n" /* cachep */
        "movl %edi, -0x24(%ebp)\n" /* cachep */
        "movl -0x54(%ebp), %eax\n" /* errorptr */
        "movl %eax, -0x1c(%ebp)\n"
        "movl $0, -0x70(%ebp)\n" /* cur2 */
        "movl $0, -0x74(%ebp)\n" /* cur1 */
        "movl $0, -0x78(%ebp)\n" /* cur0 */
        "movl $0, -0x64(%ebp)\n" /* belowerr2 */
        "movl $0, -0x68(%ebp)\n" /* belowerr1 */
        "movl $0, -0x6c(%ebp)\n" /* belowerr0 */
        "movl $0, -0x58(%ebp)\n" /* bpreverr2 */
        "movl $0, -0x5c(%ebp)\n" /* bpreverr1 */
        "movl $0, -0x60(%ebp)\n" /* bpreverr0 */
        "movl $0, -0x20(%ebp)\n"
        "movl %edi, %edx\n" /* cachep */
        "jmp .Lf2039f8_00203c64\n"
        /* { scope 2 */
        ".Lf2039f8_00203b74:\n"
        "movzwl (%edi), %eax\n" /* line 1033 | cachep, pixcode */
        "subl $1, %eax\n" /* pixcode */
        "movl -0x4c(%ebp), %edx\n" /* line 1034 | outptr */
        "movb %al, (%edx)\n"
        "movl -0x30(%ebp), %ecx\n" /* line 1036 | colormap0 */
        "movzbl (%ecx, %eax), %edx\n"
        "movl -0x10(%ebp), %esi\n"
        "subl %edx, %esi\n"
        "movl %esi, -0xc(%ebp)\n"
        "movl -0x2c(%ebp), %edi\n" /* line 1037 | colormap1, cachep */
        "movzbl (%edi, %eax), %edx\n" /* cachep */
        "movl -0x14(%ebp), %edi\n" /* cachep */
        "subl %edx, %edi\n" /* cachep */
        "movl -0x28(%ebp), %edx\n" /* line 1038 | colormap2 */
        "movzbl (%edx, %eax), %eax\n"
        "movl -0x18(%ebp), %esi\n"
        "subl %eax, %esi\n"
        /* } scope */
        /* { scope 2 */
        "movl -0xc(%ebp), %ecx\n" /* line 1047 */
        "addl %ecx, %ecx\n"
        "movl -0xc(%ebp), %eax\n" /* line 1048 */
        "addl %ecx, %eax\n"
        "movl %eax, -0x9c(%ebp)\n"
        "movl -0x60(%ebp), %edx\n" /* line 1049 | bpreverr0 */
        "addl %eax, %edx\n"
        "movl -0x1c(%ebp), %eax\n"
        "movw %dx, (%eax)\n"
        "movl -0x9c(%ebp), %edx\n" /* line 1050 */
        "leal (%ecx, %edx), %eax\n"
        "movl -0x6c(%ebp), %edx\n" /* line 1051 | belowerr0 */
        "addl %eax, %edx\n"
        "movl %edx, -0x60(%ebp)\n" /* bpreverr0 */
        "addl %eax, %ecx\n" /* line 1053 */
        "movl %ecx, -0x78(%ebp)\n" /* cur0 */
        "leal (%edi, %edi), %ecx\n" /* line 1055 | cachep */
        "leal (%edi, %ecx), %eax\n" /* line 1056 | cachep */
        "movl %eax, -0x9c(%ebp)\n"
        "movl -0x5c(%ebp), %edx\n" /* line 1057 | bpreverr1 */
        "addl %eax, %edx\n"
        "movl -0x1c(%ebp), %eax\n"
        "movw %dx, 2(%eax)\n"
        "movl -0x9c(%ebp), %edx\n" /* line 1058 */
        "leal (%ecx, %edx), %eax\n"
        "movl -0x68(%ebp), %edx\n" /* line 1059 | belowerr1 */
        "addl %eax, %edx\n"
        "movl %edx, -0x5c(%ebp)\n" /* bpreverr1 */
        "addl %eax, %ecx\n" /* line 1061 */
        "movl %ecx, -0x74(%ebp)\n" /* cur1 */
        "leal (%esi, %esi), %ecx\n" /* line 1063 */
        "leal (%esi, %ecx), %eax\n" /* line 1064 */
        "movl %eax, -0x9c(%ebp)\n"
        "movl -0x58(%ebp), %edx\n" /* line 1065 | bpreverr2 */
        "addl %eax, %edx\n"
        "movl -0x1c(%ebp), %eax\n"
        "movw %dx, 4(%eax)\n"
        "movl -0x9c(%ebp), %edx\n" /* line 1066 */
        "leal (%ecx, %edx), %eax\n"
        "movl -0x64(%ebp), %edx\n" /* line 1067 | belowerr2 */
        "addl %eax, %edx\n"
        "movl %edx, -0x58(%ebp)\n" /* bpreverr2 */
        "addl %eax, %ecx\n" /* line 1069 */
        "movl %ecx, -0x70(%ebp)\n" /* cur2 */
        /* } scope */
        "movl -0x44(%ebp), %ecx\n" /* line 1075 | dir3 */
        "addl %ecx, -0x50(%ebp)\n" /* inptr */
        "movl -0x48(%ebp), %eax\n" /* line 1076 | dir */
        "addl %eax, -0x4c(%ebp)\n" /* outptr */
        "addl $1, -0x20(%ebp)\n"
        "movl -0xc(%ebp), %edx\n"
        "movl %edx, -0x6c(%ebp)\n" /* belowerr0 */
        "movl %edi, -0x68(%ebp)\n" /* cachep, belowerr1 */
        "movl %esi, -0x64(%ebp)\n" /* belowerr2 */
        "movl -0x20(%ebp), %ecx\n" /* line 998 */
        "cmpl %ecx, -0x3c(%ebp)\n" /* width */
        "je .Lf2039f8_00203d2f\n"
        "movl -0x54(%ebp), %esi\n" /* errorptr */
        "movl %esi, -0x1c(%ebp)\n"
        "movl -0x24(%ebp), %edx\n"
        ".Lf2039f8_00203c64:\n"
        "addl %edx, -0x54(%ebp)\n" /* line 1007 | errorptr */
        "movl -0x1c(%ebp), %edx\n" /* line 1008 */
        "addl -0x24(%ebp), %edx\n"
        "movl -0x54(%ebp), %ecx\n" /* line 1013 | errorptr */
        "movswl (%ecx), %eax\n"
        "movl -0x78(%ebp), %esi\n" /* cur0 */
        "leal 8(%esi, %eax), %ecx\n"
        "sarl $4, %ecx\n"
        "movswl 2(%edx), %eax\n" /* line 1014 */
        "movl -0x74(%ebp), %edi\n" /* cur1, cachep */
        "leal 8(%edi, %eax), %esi\n" /* cachep */
        "sarl $4, %esi\n"
        "movswl 4(%edx), %eax\n" /* line 1015 */
        "movl -0x70(%ebp), %edx\n" /* cur2 */
        "leal 8(%edx, %eax), %edi\n" /* cachep */
        "sarl $4, %edi\n" /* cachep */
        "movl -0x50(%ebp), %eax\n" /* line 1023 | inptr */
        "movzbl (%eax), %edx\n"
        "movl -0x34(%ebp), %eax\n" /* error_limit */
        "movl (%eax, %ecx, 4), %ecx\n"
        "addl -0x38(%ebp), %ecx\n" /* range_limit */
        "movzbl (%ecx, %edx), %ecx\n"
        "movl %ecx, -0x10(%ebp)\n"
        "movl -0x50(%ebp), %ecx\n" /* line 1024 | inptr */
        "movzbl 1(%ecx), %edx\n"
        "movl -0x38(%ebp), %eax\n" /* range_limit */
        "movl -0x34(%ebp), %ecx\n" /* error_limit */
        "addl (%ecx, %esi, 4), %eax\n"
        "movzbl (%eax, %edx), %eax\n"
        "movl %eax, -0x14(%ebp)\n"
        "movl -0x50(%ebp), %esi\n" /* line 1025 | inptr */
        "movzbl 2(%esi), %edx\n"
        "movl -0x38(%ebp), %eax\n" /* range_limit */
        "addl (%ecx, %edi, 4), %eax\n"
        "movzbl (%eax, %edx), %eax\n"
        "movl %eax, -0x18(%ebp)\n"
        "movl -0x10(%ebp), %edi\n" /* line 1027 | cachep */
        "sarl $3, %edi\n" /* cachep */
        "movl %edi, -0x84(%ebp)\n" /* cachep */
        "movl -0x14(%ebp), %esi\n"
        "sarl $2, %esi\n"
        "movl %eax, %ecx\n"
        "sarl $3, %ecx\n"
        "movl %esi, %eax\n"
        "shll $5, %eax\n"
        "addl %ecx, %eax\n"
        "movl %eax, -0x9c(%ebp)\n"
        "movl -0x7c(%ebp), %eax\n" /* histogram */
        "movl (%eax, %edi, 4), %edx\n"
        "movl -0x9c(%ebp), %eax\n"
        "leal (%edx, %eax, 2), %edi\n" /* cachep */
        "cmpw $0, (%edi)\n" /* line 1030 | cachep */
        "jne .Lf2039f8_00203b74\n"
        "movl %ecx, (%esp)\n" /* line 1031 */
        "movl %esi, %ecx\n"
        "movl -0x84(%ebp), %edx\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "calll fill_inverse_cmap\n"
        "jmp .Lf2039f8_00203b74\n"
        ".Lf2039f8_00203d2f:\n"
        "movl -0x60(%ebp), %ecx\n" /* line 998 | bpreverr0 */
        "movl -0x5c(%ebp), %edx\n" /* bpreverr1 */
        "movl -0x58(%ebp), %eax\n" /* bpreverr2 */
        "movl -0x54(%ebp), %edi\n" /* line 1083 | errorptr, cachep */
        "movw %cx, (%edi)\n" /* cachep */
        "movw %dx, 2(%edi)\n" /* line 1084 | cachep */
        "movw %ax, 4(%edi)\n" /* line 1085 | cachep */
        "addl $1, -0x40(%ebp)\n" /* line 974 | row */
        "movl -0x40(%ebp), %eax\n" /* row */
        "cmpl %eax, 0x14(%ebp)\n" /* num_rows */
        "jne .Lf2039f8_00203ad5\n"
        ".Lf2039f8_00203d56:\n"
        "addl $0xc0, %esp\n" /* line 1087 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1144 */
static __attribute__((naked))
void finish_pass1(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1: numboxes */
        "pushl %ebp\n" /* line 1144 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0xa0, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 1145 | cinfo */
        "movl 0x1b0(%eax), %eax\n"
        "movl %eax, -0x84(%ebp)\n" /* cquantize */
        "movl %eax, %edx\n" /* line 1148 */
        "movl 0x10(%eax), %eax\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %eax, 0x7c(%ecx)\n"
        "movl 0x14(%edx), %eax\n" /* line 1149 */
        "movl %eax, -0x80(%ebp)\n" /* numboxes */
        /* { scope 2: c0, icolor */
        "movl 4(%ecx), %edx\n" /* line 547 */
        "shll $5, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *(%edx)\n"
        "movl %eax, %edi\n" /* histp */
        "movl $0, (%eax)\n" /* line 551 */
        "movl $0x1f, 4(%eax)\n" /* line 552 */
        "movl $0, 8(%eax)\n" /* line 553 */
        "movl $0x3f, 0xc(%eax)\n" /* line 554 */
        "movl $0, 0x10(%eax)\n" /* line 555 */
        "movl $0x1f, 0x14(%eax)\n" /* line 556 */
        "movl %eax, %edx\n" /* line 558 */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "calll update_box\n"
        /* { scope 3: maxv, maxc, c0, c1, ... */
        "cmpl $1, -0x80(%ebp)\n" /* line 432 | numboxes */
        "jle .Lf203d60_00203fb1\n"
        "leal 0x20(%edi), %edx\n"
        "movl %edx, -0x3c(%ebp)\n"
        "leal 0x24(%edi), %ecx\n"
        "movl %ecx, -0x38(%ebp)\n"
        "movl $1, -0x28(%ebp)\n"
        "movl -0x28(%ebp), %eax\n" /* line 436 */
        "addl %eax, %eax\n"
        "cmpl %eax, -0x80(%ebp)\n" /* numboxes */
        "jge .Lf203d60_00203f37\n"
        /* { scope 4 */
        ".Lf203d60_00203e02:\n"
        "movl -0x28(%ebp), %edx\n" /* line 302 */
        "testl %edx, %edx\n"
        "jle .Lf203d60_00203f6e\n"
        /* } scope */
        /* { scope 4 */
        "movl %edi, %edx\n" /* line 282 */
        "movl $0, -0x74(%ebp)\n" /* maxv */
        "xorl %ecx, %ecx\n"
        "xorl %esi, %esi\n"
        /* } scope */
        /* { scope 4 */
        ".Lf203d60_00203e1a:\n"
        "movl 0x18(%edx), %eax\n" /* line 303 */
        "cmpl %eax, -0x74(%ebp)\n" /* maxv */
        "jge .Lf203d60_00203e27\n"
        "movl %eax, -0x74(%ebp)\n" /* maxv */
        "movl %edx, %esi\n"
        ".Lf203d60_00203e27:\n"
        "addl $1, %ecx\n" /* line 302 */
        "addl $0x20, %edx\n"
        "cmpl -0x28(%ebp), %ecx\n"
        "jne .Lf203d60_00203e1a\n"
        /* } scope */
        ".Lf203d60_00203e32:\n"
        "testl %esi, %esi\n" /* line 441 */
        "je .Lf203d60_002041bc\n"
        "movl 4(%esi), %eax\n" /* line 445 */
        "movl -0x38(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "movl 0xc(%esi), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl 0x14(%esi), %eax\n"
        "movl %eax, 0x10(%edx)\n"
        "subl $4, %edx\n" /* line 1144 */
        "movl %edx, -0x34(%ebp)\n"
        "movl (%esi), %eax\n" /* line 446 */
        "movl -0x38(%ebp), %ecx\n"
        "movl %eax, -4(%ecx)\n"
        "addl $4, %ecx\n" /* line 1144 */
        "movl %ecx, -0x30(%ebp)\n"
        "movl 8(%esi), %eax\n" /* line 446 */
        "movl -0x38(%ebp), %edx\n"
        "movl %eax, 4(%edx)\n"
        "addl $0xc, %edx\n" /* line 1144 */
        "movl %edx, -0x2c(%ebp)\n"
        "movl 0x10(%esi), %eax\n" /* line 446 */
        "movl -0x38(%ebp), %ecx\n"
        "movl %eax, 0xc(%ecx)\n"
        "movl 4(%esi), %eax\n" /* line 451 */
        "movl %eax, -0x14(%ebp)\n"
        "movl (%esi), %edx\n"
        "movl %edx, -0x18(%ebp)\n"
        "subl %edx, %eax\n"
        "shll $3, %eax\n"
        "movl %eax, -0x7c(%ebp)\n" /* c0 */
        "movl 0xc(%esi), %ecx\n" /* line 452 */
        "movl %ecx, -0x1c(%ebp)\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl %ecx, %edx\n"
        "subl %eax, %edx\n"
        "leal (, %edx, 8), %eax\n"
        "leal (%eax, %edx, 4), %ecx\n"
        "movl 0x14(%esi), %edx\n" /* line 453 */
        "movl 0x10(%esi), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl %edx, %eax\n"
        "subl -0x24(%ebp), %eax\n"
        "shll $4, %eax\n"
        "cmpl %eax, %ecx\n" /* line 463 */
        "jge .Lf203d60_00204177\n"
        "movl %eax, %ecx\n"
        "movl $2, %eax\n"
        ".Lf203d60_00203ec7:\n"
        "cmpl -0x7c(%ebp), %ecx\n" /* line 464 | c0 */
        "jl .Lf203d60_00203ee2\n"
        "cmpl $1, %eax\n" /* line 472 */
        "je .Lf203d60_00204181\n"
        "cmpl $2, %eax\n"
        "je .Lf203d60_002041a0\n"
        "testl %eax, %eax\n"
        "jne .Lf203d60_00203efc\n"
        ".Lf203d60_00203ee2:\n"
        "movl -0x14(%ebp), %edx\n" /* line 474 */
        "addl -0x18(%ebp), %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "movl %eax, 4(%esi)\n" /* line 475 */
        "addl $1, %eax\n" /* line 476 */
        "movl -0x34(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        ".Lf203d60_00203efc:\n"
        "movl %esi, %edx\n" /* line 490 */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "calll update_box\n"
        "movl -0x3c(%ebp), %edx\n" /* line 491 */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "calll update_box\n"
        "addl $1, -0x28(%ebp)\n" /* line 492 */
        "addl $0x20, -0x3c(%ebp)\n"
        "addl $0x20, -0x38(%ebp)\n"
        "movl -0x28(%ebp), %ecx\n" /* line 432 */
        "cmpl %ecx, -0x80(%ebp)\n" /* numboxes */
        "je .Lf203d60_00203fb8\n"
        "movl -0x28(%ebp), %eax\n" /* line 436 */
        "addl %eax, %eax\n"
        "cmpl %eax, -0x80(%ebp)\n" /* numboxes */
        "jl .Lf203d60_00203e02\n"
        /* { scope 4 */
        ".Lf203d60_00203f37:\n"
        "movl -0x28(%ebp), %eax\n" /* line 282 */
        "testl %eax, %eax\n"
        "jle .Lf203d60_00203f6e\n"
        /* } scope */
        "movl %edi, %eax\n" /* line 436 */
        "movl $0, -0x78(%ebp)\n" /* maxc */
        "xorl %ecx, %ecx\n"
        "xorl %esi, %esi\n"
        /* { scope 4 */
        ".Lf203d60_00203f4b:\n"
        "movl 0x1c(%eax), %edx\n" /* line 283 */
        "cmpl %edx, -0x78(%ebp)\n" /* maxc */
        "jge .Lf203d60_00203f5e\n"
        "cmpl $0, 0x18(%eax)\n"
        "jle .Lf203d60_00203f5e\n"
        "movl %edx, -0x78(%ebp)\n" /* maxc */
        "movl %eax, %esi\n"
        ".Lf203d60_00203f5e:\n"
        "addl $1, %ecx\n" /* line 282 */
        "addl $0x20, %eax\n"
        "cmpl -0x28(%ebp), %ecx\n"
        "jne .Lf203d60_00203f4b\n"
        "jmp .Lf203d60_00203e32\n"
        /* } scope */
        /* } scope */
        ".Lf203d60_00203f6e:\n"
        "movl -0x28(%ebp), %eax\n" /* line 562 */
        "movl %eax, -0x80(%ebp)\n" /* numboxes */
        "movl %eax, %edx\n"
        ".Lf203d60_00203f76:\n"
        "movl 8(%ebp), %eax\n" /* line 564 | cinfo */
        "movl %edx, 0x78(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 565 | cinfo */
        "movl (%ecx), %eax\n"
        "movl $0x60, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %edx, 0x18(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl $1, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *4(%eax)\n"
        /* } scope */
        "movl -0x84(%ebp), %eax\n" /* line 1151 | cquantize */
        "movb $1, 0x1c(%eax)\n"
        "addl $0xa0, %esp\n" /* line 1152 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2: c0, icolor */
        /* { scope 3: maxv, maxc, c0, c1, ... */
        /* { scope 4 */
        ".Lf203d60_00203fb1:\n"
        "movl $1, -0x80(%ebp)\n" /* line 282 | numboxes */
        /* } scope */
        /* } scope */
        ".Lf203d60_00203fb8:\n"
        "movl %edi, -0x40(%ebp)\n" /* line 562 | histp */
        "movl $0, -0x70(%ebp)\n" /* icolor */
        "movl %edi, %edx\n" /* histp */
        /* { scope 3: maxv, maxc, c0, c1, ... */
        /* { scope 4 */
        ".Lf203d60_00203fc4:\n"
        "movl 8(%ebp), %ecx\n" /* line 505 | cinfo */
        "movl 0x1b0(%ecx), %eax\n" /* histogram */
        "movl 0x18(%eax), %eax\n" /* histogram */
        "movl (%edx), %edx\n" /* line 515 */
        "movl %edx, -0x6c(%ebp)\n" /* c0 */
        "movl -0x40(%ebp), %ecx\n"
        "movl 4(%ecx), %ecx\n"
        "movl %ecx, -0x64(%ebp)\n" /* c0max */
        "movl -0x40(%ebp), %edx\n" /* line 516 */
        "movl 8(%edx), %edx\n"
        "movl %edx, -0xc(%ebp)\n"
        "movl -0x40(%ebp), %ecx\n"
        "movl 0xc(%ecx), %ecx\n"
        "movl %ecx, -0x60(%ebp)\n" /* c1max */
        "movl -0x40(%ebp), %edx\n" /* line 517 */
        "movl 0x10(%edx), %edx\n"
        "movl %edx, -0x10(%ebp)\n"
        "movl -0x40(%ebp), %ecx\n"
        "movl 0x14(%ecx), %ecx\n"
        "movl %ecx, -0x5c(%ebp)\n" /* c2max */
        "movl -0x64(%ebp), %edx\n" /* line 519 | c0max */
        "cmpl %edx, -0x6c(%ebp)\n" /* c0 */
        "jg .Lf203d60_0020414f\n"
        "movl -0x6c(%ebp), %ecx\n" /* c0 */
        "leal (%eax, %ecx, 4), %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        "movl $0, -0x58(%ebp)\n" /* total */
        "movl $0, -0x54(%ebp)\n" /* c0total */
        "movl $0, -0x50(%ebp)\n" /* c1total */
        "movl $0, -0x4c(%ebp)\n" /* c2total */
        ".Lf203d60_00204033:\n"
        "movl -0x60(%ebp), %edx\n" /* line 520 | c1max */
        "cmpl %edx, -0xc(%ebp)\n"
        "jg .Lf203d60_002040d8\n"
        "movl -0xc(%ebp), %eax\n"
        "shll $5, %eax\n"
        "addl -0x10(%ebp), %eax\n"
        "movl -0x44(%ebp), %ecx\n"
        "movl (%ecx), %edx\n"
        "leal (%edx, %eax, 2), %eax\n"
        "movl %eax, -0x48(%ebp)\n"
        "movl -0xc(%ebp), %eax\n"
        "movl %eax, -0x68(%ebp)\n" /* c1 */
        ".Lf203d60_00204059:\n"
        "movl -0x48(%ebp), %edi\n" /* line 519 | histp */
        "movl -0x5c(%ebp), %eax\n" /* line 522 | c2max */
        "cmpl %eax, -0x10(%ebp)\n"
        "jg .Lf203d60_002040c8\n"
        "movl -0x10(%ebp), %ecx\n"
        "movl -0x6c(%ebp), %edx\n" /* c0 */
        "leal 4(, %edx, 8), %edx\n"
        "movl %edx, -0x88(%ebp)\n"
        "movl -0x68(%ebp), %eax\n" /* c1 */
        "leal 2(, %eax, 4), %eax\n"
        "movl %eax, -0x8c(%ebp)\n"
        "leal 4(, %ecx, 8), %esi\n"
        ".Lf203d60_0020408e:\n"
        "movzwl (%edi), %eax\n" /* line 523 | histp */
        "movzwl %ax, %edx\n"
        "addl $2, %edi\n" /* histp */
        "testw %ax, %ax\n"
        "je .Lf203d60_002040bd\n"
        "addl %edx, -0x58(%ebp)\n" /* line 524 | total */
        "movl -0x88(%ebp), %eax\n" /* line 525 */
        "imull %edx, %eax\n"
        "addl %eax, -0x54(%ebp)\n" /* c0total */
        "movl -0x8c(%ebp), %eax\n" /* line 526 */
        "imull %edx, %eax\n"
        "addl %eax, -0x50(%ebp)\n" /* c1total */
        "imull %esi, %edx\n" /* line 527 */
        "addl %edx, -0x4c(%ebp)\n" /* c2total */
        ".Lf203d60_002040bd:\n"
        "addl $1, %ecx\n" /* line 522 */
        "addl $8, %esi\n"
        "cmpl %ecx, -0x5c(%ebp)\n" /* c2max */
        "jge .Lf203d60_0020408e\n"
        ".Lf203d60_002040c8:\n"
        "addl $1, -0x68(%ebp)\n" /* line 520 | c1 */
        "addl $0x40, -0x48(%ebp)\n"
        "movl -0x68(%ebp), %ecx\n" /* c1 */
        "cmpl %ecx, -0x60(%ebp)\n" /* c1max */
        "jge .Lf203d60_00204059\n"
        ".Lf203d60_002040d8:\n"
        "addl $1, -0x6c(%ebp)\n" /* line 519 | c0 */
        "addl $4, -0x44(%ebp)\n"
        "movl -0x6c(%ebp), %eax\n" /* c0 */
        "cmpl %eax, -0x64(%ebp)\n" /* c0max */
        "jge .Lf203d60_00204033\n"
        "movl -0x58(%ebp), %esi\n" /* total */
        "sarl $1, %esi\n"
        ".Lf203d60_002040f1:\n"
        "movl 8(%ebp), %edx\n" /* line 532 | cinfo */
        "movl 0x7c(%edx), %eax\n"
        "movl (%eax), %edi\n" /* histp */
        "movl -0x54(%ebp), %eax\n" /* c0total */
        "addl %esi, %eax\n"
        "cltd\n"
        "idivl -0x58(%ebp)\n" /* total */
        "movl -0x70(%ebp), %ecx\n" /* icolor */
        "movb %al, (%ecx, %edi)\n"
        "movl 8(%ebp), %edx\n" /* line 533 | cinfo */
        "movl 0x7c(%edx), %eax\n"
        "movl 4(%eax), %edi\n" /* histp */
        "movl -0x50(%ebp), %eax\n" /* c1total */
        "addl %esi, %eax\n"
        "cltd\n"
        "idivl -0x58(%ebp)\n" /* total */
        "movl -0x70(%ebp), %ecx\n" /* icolor */
        "movb %al, (%ecx, %edi)\n"
        "movl 8(%ebp), %edx\n" /* line 534 | cinfo */
        "movl 0x7c(%edx), %eax\n"
        "movl 8(%eax), %edi\n" /* histp */
        "movl -0x4c(%ebp), %eax\n" /* c2total */
        "addl %esi, %eax\n"
        "cltd\n"
        "idivl -0x58(%ebp)\n" /* total */
        "movl -0x70(%ebp), %ecx\n" /* icolor */
        "movb %al, (%ecx, %edi)\n"
        /* } scope */
        /* } scope */
        "addl $1, %ecx\n" /* line 562 */
        "movl %ecx, -0x70(%ebp)\n" /* icolor */
        "addl $0x20, -0x40(%ebp)\n"
        "cmpl %ecx, -0x80(%ebp)\n" /* numboxes */
        "je .Lf203d60_0020416f\n"
        "movl -0x40(%ebp), %edx\n"
        "jmp .Lf203d60_00203fc4\n"
        /* { scope 3: maxv, maxc, c0, c1, ... */
        /* { scope 4 */
        ".Lf203d60_0020414f:\n"
        "movl $0, -0x58(%ebp)\n" /* line 520 | total */
        "movl $0, -0x54(%ebp)\n" /* c0total */
        "movl $0, -0x50(%ebp)\n" /* c1total */
        "movl $0, -0x4c(%ebp)\n" /* c2total */
        "xorl %esi, %esi\n"
        "jmp .Lf203d60_002040f1\n"
        ".Lf203d60_0020416f:\n"
        "movl -0x80(%ebp), %edx\n" /* numboxes */
        "jmp .Lf203d60_00203f76\n"
        /* } scope */
        /* } scope */
        /* { scope 3: maxv, maxc, c0, c1, ... */
        ".Lf203d60_00204177:\n"
        "movl $1, %eax\n" /* line 463 */
        "jmp .Lf203d60_00203ec7\n"
        ".Lf203d60_00204181:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 479 */
        "addl -0x20(%ebp), %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n" /* line 480 */
        "addl $1, %eax\n" /* line 481 */
        "movl -0x30(%ebp), %ecx\n"
        "movl %eax, (%ecx)\n"
        "jmp .Lf203d60_00203efc\n"
        ".Lf203d60_002041a0:\n"
        "addl -0x24(%ebp), %edx\n" /* line 484 */
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "movl %eax, 0x14(%esi)\n" /* line 485 */
        "addl $1, %eax\n" /* line 486 */
        "movl -0x2c(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "jmp .Lf203d60_00203efc\n"
        /* } scope */
        ".Lf203d60_002041bc:\n"
        "movl -0x28(%ebp), %eax\n" /* line 562 */
        "testl %eax, %eax\n"
        "jle .Lf203d60_00203f6e\n"
        "movl -0x28(%ebp), %edx\n"
        "movl %edx, -0x80(%ebp)\n" /* numboxes */
        "jmp .Lf203d60_00203fb8\n"
    );
}

/* line 1157 */
static __attribute__((naked))
void finish_pass2(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1157 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 1159 */
        "retl\n"
    );
}

/* line 1231 */
static __attribute__((naked))
void new_color_map_2_quant(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1231 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 1235 | cinfo */
        "movl 0x1b0(%eax), %eax\n"
        "movb $1, 0x1c(%eax)\n"
        "popl %ebp\n" /* line 1236 */
        "retl\n"
    );
}

/* line 1245 */
__attribute__((naked))
void jinit_2pass_quantizer(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1: in, out */
        "pushl %ebp\n" /* line 1245 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %edx\n" /* line 1249 | cinfo */
        "movl 4(%edx), %eax\n"
        "movl $0x2c, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl %eax, -0x24(%ebp)\n" /* cquantize */
        "movl 8(%ebp), %ecx\n" /* line 1252 | cinfo */
        "movl %eax, 0x1b0(%ecx)\n"
        "leal 0x271(%ebx), %eax\n" /* line 1253 */
        "movl -0x24(%ebp), %edx\n" /* cquantize */
        "movl %eax, (%edx)\n"
        "leal -0x20(%ebx), %eax\n" /* line 1254 */
        "movl %eax, 0xc(%edx)\n"
        "movl $0, 0x20(%edx)\n" /* line 1255 */
        "movl $0, 0x28(%edx)\n" /* line 1256 */
        "cmpl $3, 0x6c(%ecx)\n" /* line 1259 */
        "je .Lf2041e9_00204256\n"
        "movl (%ecx), %eax\n" /* line 1260 */
        "movl $0x2f, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf2041e9_00204256:\n"
        "movl 8(%ebp), %ecx\n" /* line 1263 | cinfo */
        "movl 4(%ecx), %eax\n"
        "movl $0x80, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "movl -0x24(%ebp), %edx\n" /* cquantize */
        "movl %eax, 0x18(%edx)\n"
        "xorl %edi, %edi\n"
        ".Lf2041e9_00204279:\n"
        "movl %edi, %esi\n" /* line 1266 | cquantize */
        "movl -0x24(%ebp), %ecx\n" /* cquantize */
        "addl 0x18(%ecx), %esi\n" /* cquantize */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 4(%edx), %eax\n"
        "movl $__mh_execute_header, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        "movl %eax, (%esi)\n" /* cquantize */
        "addl $4, %edi\n"
        "cmpl $0x80, %edi\n" /* line 1265 */
        "jne .Lf2041e9_00204279\n"
        "movl -0x24(%ebp), %ecx\n" /* line 1270 | cquantize */
        "movb $1, 0x1c(%ecx)\n"
        "movl 8(%ebp), %eax\n" /* line 1276 | cinfo */
        "cmpb $0, 0x62(%eax)\n"
        "je .Lf2041e9_002043f3\n"
        /* { scope 2 */
        "movl 0x5c(%eax), %esi\n" /* line 1278 | desired */
        "cmpl $7, %esi\n" /* line 1280 | desired */
        "jle .Lf2041e9_00204427\n"
        "cmpl $0x100, %esi\n" /* line 1283 | desired */
        "jg .Lf2041e9_00204447\n"
        ".Lf2041e9_002042d6:\n"
        "movl 8(%ebp), %edx\n" /* line 1285 | cinfo */
        "movl 4(%edx), %eax\n"
        "movl $3, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* desired */
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        "movl -0x24(%ebp), %ecx\n" /* cquantize */
        "movl %eax, 0x10(%ecx)\n"
        "movl %esi, 0x14(%ecx)\n" /* line 1287 | desired */
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 1293 | cinfo */
        "movl 0x54(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf2041e9_0020440b\n"
        ".Lf2041e9_0020430d:\n"
        "movl %edx, %ecx\n"
        "cmpl $2, 0x54(%ecx)\n" /* line 1301 */
        "jne .Lf2041e9_0020441f\n"
        ".Lf2041e9_00204319:\n"
        "movl 4(%ecx), %edx\n" /* line 1302 */
        "movl 0x64(%ecx), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "leal 0xc(%eax, %eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *4(%edx)\n"
        "movl -0x24(%ebp), %edx\n" /* cquantize */
        "movl %eax, 0x20(%edx)\n"
        /* { scope 2 */
        "movl 8(%ebp), %ecx\n" /* line 1111 | cinfo */
        "movl 0x1b0(%ecx), %esi\n" /* cquantize */
        "movl 4(%ecx), %eax\n" /* line 1115 */
        "movl $0x7fc, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "leal 0x3fc(%eax), %ecx\n" /* line 1117 */
        "movl %ecx, 0x28(%esi)\n" /* line 1118 | cquantize */
        "xorl %eax, %eax\n"
        "xorl %edx, %edx\n"
        ".Lf2041e9_0020436c:\n"
        "movl %eax, (%ecx, %eax, 4)\n" /* line 1124 */
        "movl %edx, (%ecx, %edx, 4)\n"
        "addl $1, %eax\n" /* line 1123 */
        "subl $1, %edx\n"
        "cmpl $0x10, %eax\n"
        "jne .Lf2041e9_0020436c\n"
        "leal 0x40(%ecx), %esi\n" /* line 1245 | cquantize */
        "leal -0x40(%ecx), %edx\n"
        "movl $0x10, -0x1c(%ebp)\n" /* out */
        "movl $0x10, -0x20(%ebp)\n" /* in */
        "movl $0x20, %edi\n"
        ".Lf2041e9_00204396:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1128 | out */
        "movl %eax, (%esi)\n" /* cquantize */
        "movl -0x1c(%ebp), %eax\n" /* out */
        "negl %eax\n"
        "movl %eax, (%edx)\n"
        "addl $1, -0x20(%ebp)\n" /* line 1127 | in */
        "movl -0x20(%ebp), %eax\n" /* in */
        "notl %eax\n"
        "andl $1, %eax\n"
        "addl %eax, -0x1c(%ebp)\n" /* out */
        "addl $4, %esi\n" /* cquantize */
        "subl $4, %edx\n"
        "subl $1, %edi\n"
        "jne .Lf2041e9_00204396\n"
        "cmpl $0xff, -0x20(%ebp)\n" /* line 1131 | in */
        "jg .Lf2041e9_0020441f\n"
        "movl -0x1c(%ebp), %esi\n" /* out, cquantize */
        "negl %esi\n" /* cquantize */
        "movl -0x20(%ebp), %eax\n" /* line 1245 | in */
        "shll $2, %eax\n"
        "leal (%ecx, %eax), %edx\n"
        "subl %eax, %ecx\n"
        "movl %ecx, %eax\n"
        ".Lf2041e9_002043d7:\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 1132 | out */
        "movl %ecx, (%edx)\n"
        "movl %esi, (%eax)\n" /* cquantize */
        "addl $1, -0x20(%ebp)\n" /* line 1131 | in */
        "addl $4, %edx\n"
        "subl $4, %eax\n"
        "cmpl $0x100, -0x20(%ebp)\n" /* in */
        "jne .Lf2041e9_002043d7\n"
        "jmp .Lf2041e9_0020441f\n"
        /* } scope */
        ".Lf2041e9_002043f3:\n"
        "movl -0x24(%ebp), %eax\n" /* line 1289 | cquantize */
        "movl $0, 0x10(%eax)\n"
        "movl 8(%ebp), %edx\n" /* line 1293 | cinfo */
        "movl 0x54(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf2041e9_0020430d\n"
        ".Lf2041e9_0020440b:\n"
        "movl $2, 0x54(%edx)\n" /* line 1294 */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "cmpl $2, 0x54(%ecx)\n" /* line 1301 */
        "je .Lf2041e9_00204319\n"
        ".Lf2041e9_0020441f:\n"
        "addl $0x2c, %esp\n" /* line 1308 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2 */
        ".Lf2041e9_00204427:\n"
        "movl %eax, %edx\n" /* line 1281 */
        "movl (%eax), %eax\n"
        "movl $0x38, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl $8, 0x18(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf2041e9_002042d6\n"
        ".Lf2041e9_00204447:\n"
        "movl 8(%ebp), %ecx\n" /* line 1284 | cinfo */
        "movl (%ecx), %eax\n"
        "movl $0x39, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl $0x100, 0x18(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf2041e9_002042d6\n"
    );
}

/* line 1168 */
static __attribute__((naked))
void start_pass_2_quant(j_decompress_ptr cinfo, int is_pre_scan)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 1168 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %edi\n" /* cinfo */
        "movzbl 0xc(%ebp), %eax\n" /* is_pre_scan */
        "movl 0x1b0(%edi), %edx\n" /* line 1169 | cinfo */
        "movl %edx, -0x28(%ebp)\n" /* cquantize */
        "movl 0x18(%edx), %ecx\n" /* line 1170 */
        "movl %ecx, -0x24(%ebp)\n" /* histogram */
        "movl 0x54(%edi), %ecx\n" /* line 1175 | cinfo */
        "testl %ecx, %ecx\n"
        "je .Lf204468_0020449a\n"
        "movl $2, 0x54(%edi)\n" /* line 1176 | cinfo */
        ".Lf204468_0020449a:\n"
        "testb %al, %al\n" /* line 1178 */
        "je .Lf204468_002044cc\n"
        "leal -0x1762(%ebx), %eax\n" /* line 1180 */
        "movl -0x28(%ebp), %edx\n" /* cquantize */
        "movl %eax, 4(%edx)\n"
        "leal -0x716(%ebx), %eax\n" /* line 1181 */
        "movl %eax, 8(%edx)\n"
        "movb $1, 0x1c(%edx)\n" /* line 1182 */
        ".Lf204468_002044b7:\n"
        "movl -0x28(%ebp), %edx\n" /* line 1215 | cquantize */
        "cmpb $0, 0x1c(%edx)\n"
        "jne .Lf204468_00204552\n"
        ".Lf204468_002044c4:\n"
        "addl $0x2c, %esp\n" /* line 1222 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf204468_002044cc:\n"
        "cmpl $2, 0x54(%edi)\n" /* line 1185 | cinfo */
        "je .Lf204468_00204585\n"
        "leal -0xb74(%ebx), %eax\n" /* line 1188 */
        "movl -0x28(%ebp), %edx\n" /* cquantize */
        "movl %eax, 4(%edx)\n"
        ".Lf204468_002044e2:\n"
        "leal -0x2a4(%ebx), %eax\n" /* line 1189 */
        "movl -0x28(%ebp), %ecx\n" /* cquantize */
        "movl %eax, 8(%ecx)\n"
        "movl 0x78(%edi), %eax\n" /* line 1192 | cinfo */
        "testl %eax, %eax\n" /* line 1193 */
        "jle .Lf204468_002045b4\n"
        "cmpl $0x100, %eax\n" /* line 1195 */
        "jg .Lf204468_00204596\n"
        ".Lf204468_00204504:\n"
        "cmpl $2, 0x54(%edi)\n" /* line 1198 | cinfo */
        "jne .Lf204468_002044b7\n"
        /* { scope 2: out */
        "movl 0x64(%edi), %eax\n" /* line 1200 | cinfo */
        "leal (%eax, %eax, 2), %eax\n"
        "leal 0xc(%eax, %eax), %esi\n" /* arraysize */
        "movl -0x28(%ebp), %eax\n" /* line 1202 | cquantize */
        "movl 0x20(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf204468_00204662\n"
        "movl %eax, %ecx\n"
        ".Lf204468_00204524:\n"
        "movl %esi, 4(%esp)\n" /* line 1206 | arraysize */
        "movl 0x20(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll jzero_far\n"
        "movl -0x28(%ebp), %eax\n" /* line 1208 | cquantize */
        "movl 0x28(%eax), %esi\n" /* arraysize */
        "testl %esi, %esi\n" /* arraysize */
        "je .Lf204468_002045d2\n"
        "movb $0, 0x24(%eax)\n" /* line 1210 */
        /* } scope */
        ".Lf204468_00204545:\n"
        "movl -0x28(%ebp), %edx\n" /* line 1215 | cquantize */
        "cmpb $0, 0x1c(%edx)\n"
        "je .Lf204468_002044c4\n"
        ".Lf204468_00204552:\n"
        "movl $1, %esi\n" /* arraysize */
        ".Lf204468_00204557:\n"
        "movl $__mh_execute_header, 4(%esp)\n" /* line 1217 */
        "movl -0x24(%ebp), %ecx\n" /* histogram */
        "movl -4(%ecx, %esi, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll jzero_far\n"
        "addl $1, %esi\n" /* arraysize */
        "cmpl $0x21, %esi\n" /* line 1216 | arraysize */
        "jne .Lf204468_00204557\n"
        "movl -0x28(%ebp), %eax\n" /* line 1220 | cquantize */
        "movb $0, 0x1c(%eax)\n"
        "addl $0x2c, %esp\n" /* line 1222 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf204468_00204585:\n"
        "leal -0xa7e(%ebx), %eax\n" /* line 1186 */
        "movl -0x28(%ebp), %ecx\n" /* cquantize */
        "movl %eax, 4(%ecx)\n"
        "jmp .Lf204468_002044e2\n"
        ".Lf204468_00204596:\n"
        "movl (%edi), %eax\n" /* line 1196 | cinfo */
        "movl $0x39, 0x14(%eax)\n"
        "movl (%edi), %eax\n" /* cinfo */
        "movl $0x100, 0x18(%eax)\n"
        "movl (%edi), %eax\n" /* cinfo */
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "jmp .Lf204468_00204504\n"
        ".Lf204468_002045b4:\n"
        "movl (%edi), %eax\n" /* line 1194 | cinfo */
        "movl $0x38, 0x14(%eax)\n"
        "movl (%edi), %eax\n" /* cinfo */
        "movl $1, 0x18(%eax)\n"
        "movl (%edi), %eax\n" /* cinfo */
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "jmp .Lf204468_00204504\n"
        /* { scope 2: out */
        /* { scope 3 */
        ".Lf204468_002045d2:\n"
        "movl 0x1b0(%edi), %esi\n" /* line 1111 | cquantize */
        "movl 4(%edi), %eax\n" /* line 1115 */
        "movl $0x7fc, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "leal 0x3fc(%eax), %ecx\n" /* line 1117 */
        "movl %ecx, 0x28(%esi)\n" /* line 1118 | cquantize */
        "xorl %eax, %eax\n"
        "xorl %edx, %edx\n"
        ".Lf204468_002045fd:\n"
        "movl %eax, (%ecx, %eax, 4)\n" /* line 1124 */
        "movl %edx, (%ecx, %edx, 4)\n"
        "addl $1, %eax\n" /* line 1123 */
        "subl $1, %edx\n"
        "cmpl $0x10, %eax\n"
        "jne .Lf204468_002045fd\n"
        "leal 0x40(%ecx), %esi\n" /* line 1168 | cquantize */
        "leal -0x40(%ecx), %edx\n"
        "movl $0x10, -0x20(%ebp)\n" /* out */
        "movl $0x10, -0x1c(%ebp)\n"
        "movl $0x20, %edi\n" /* cinfo */
        ".Lf204468_00204627:\n"
        "movl -0x20(%ebp), %eax\n" /* line 1128 | out */
        "movl %eax, (%esi)\n" /* cquantize */
        "movl -0x20(%ebp), %eax\n" /* out */
        "negl %eax\n"
        "movl %eax, (%edx)\n"
        "addl $1, -0x1c(%ebp)\n" /* line 1127 */
        "movl -0x1c(%ebp), %eax\n"
        "notl %eax\n"
        "andl $1, %eax\n"
        "addl %eax, -0x20(%ebp)\n" /* out */
        "addl $4, %esi\n" /* cquantize */
        "subl $4, %edx\n"
        "subl $1, %edi\n"
        "jne .Lf204468_00204627\n"
        "cmpl $0xff, -0x1c(%ebp)\n" /* line 1131 */
        "jle .Lf204468_00204685\n"
        "movl -0x28(%ebp), %eax\n" /* cquantize */
        /* } scope */
        ".Lf204468_00204659:\n"
        "movb $0, 0x24(%eax)\n" /* line 1210 */
        "jmp .Lf204468_00204545\n"
        ".Lf204468_00204662:\n"
        "movl 4(%edi), %eax\n" /* line 1203 | cinfo */
        "movl %esi, 8(%esp)\n" /* arraysize */
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *4(%eax)\n"
        "movl -0x28(%ebp), %edx\n" /* cquantize */
        "movl %eax, 0x20(%edx)\n"
        "movl -0x28(%ebp), %ecx\n" /* cquantize */
        "jmp .Lf204468_00204524\n"
        /* { scope 3 */
        ".Lf204468_00204685:\n"
        "movl -0x20(%ebp), %esi\n" /* line 1131 | out, cquantize */
        "negl %esi\n" /* cquantize */
        "movl -0x1c(%ebp), %eax\n" /* line 1168 */
        "shll $2, %eax\n"
        "leal (%ecx, %eax), %edx\n"
        "subl %eax, %ecx\n"
        "movl %ecx, %eax\n"
        ".Lf204468_00204697:\n"
        "movl -0x20(%ebp), %ecx\n" /* line 1132 | out */
        "movl %ecx, (%edx)\n"
        "movl %esi, (%eax)\n" /* cquantize */
        "addl $1, -0x1c(%ebp)\n" /* line 1131 */
        "addl $4, %edx\n"
        "subl $4, %eax\n"
        "cmpl $0x100, -0x1c(%ebp)\n"
        "jne .Lf204468_00204697\n"
        "movl -0x28(%ebp), %eax\n" /* cquantize */
        "jmp .Lf204468_00204659\n"
    );
}

