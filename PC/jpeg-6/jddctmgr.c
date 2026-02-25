/* ASM dump from: jddctmgr.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jddctmgr.c */

#include "common_types.h"
#include "imports.h"

static const INT16 aanscales[64]; /* 0x307460 */
static const double aanscalefactor[8]; /* 0x307420 */

static void start_pass(j_decompress_ptr cinfo);
void jinit_inverse_dct(j_decompress_ptr cinfo);

/* line 90 */
static __attribute__((naked))
void start_pass(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1: ifmtbl */
        "pushl %ebp\n" /* line 90 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %edx\n" /* line 91 | cinfo */
        "movl 0x1a4(%edx), %eax\n" /* idct */
        "movl 0xcc(%edx), %edx\n" /* line 98 */
        "movl %edx, -0x38(%ebp)\n" /* compptr */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl 0x2c(%edx), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf208128_00208240\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl $0, -0x34(%ebp)\n" /* method */
        "movl $0, -0x30(%ebp)\n" /* method_ptr */
        "movl $0, -0x40(%ebp)\n" /* ci */
        "leal 0xff32a(%ebx), %eax\n"
        "movl %eax, -0x48(%ebp)\n"
        ".Lf208128_00208177:\n"
        "movl -0x38(%ebp), %ecx\n" /* line 90 | compptr */
        "addl $0x24, %ecx\n"
        "movl -0x38(%ebp), %edx\n" /* line 101 | compptr */
        "movl 0x24(%edx), %eax\n"
        "cmpl $2, %eax\n"
        "je .Lf208128_00208293\n"
        "jg .Lf208128_00208248\n"
        "subl $1, %eax\n"
        "je .Lf208128_002082f2\n"
        ".Lf208128_0020819b:\n"
        "movl 8(%ebp), %edx\n" /* line 142 | cinfo */
        "movl (%edx), %eax\n"
        "movl $7, 0x14(%eax)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl (%eax), %edx\n"
        "movl (%ecx), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl -0x30(%ebp), %edx\n" /* method_ptr */
        ".Lf208128_002081be:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 145 */
        "movl %edx, 4(%eax)\n"
        "movl -0x38(%ebp), %eax\n" /* line 153 | compptr */
        "cmpb $0, 0x30(%eax)\n"
        "je .Lf208128_00208225\n"
        "movl -0x34(%ebp), %eax\n" /* method */
        "movl -0x1c(%ebp), %edx\n"
        "cmpl 0x2c(%edx), %eax\n"
        "je .Lf208128_00208225\n"
        "movl -0x38(%ebp), %edx\n" /* line 155 | compptr */
        "movl 0x4c(%edx), %edx\n"
        "movl %edx, -0x2c(%ebp)\n" /* qtbl */
        "testl %edx, %edx\n" /* line 156 */
        "je .Lf208128_00208225\n"
        "movl -0x1c(%ebp), %edx\n" /* line 158 */
        "movl %eax, 0x2c(%edx)\n"
        "cmpl $1, %eax\n" /* line 159 */
        "je .Lf208128_00208309\n"
        "cmpl $2, %eax\n"
        "je .Lf208128_00208366\n"
        "testl %eax, %eax\n"
        "jne .Lf208128_002082aa\n"
        /* { scope 2 */
        "movl -0x38(%ebp), %eax\n" /* line 166 | compptr */
        "movl 0x50(%eax), %esi\n" /* ismtbl */
        "movl -0x2c(%ebp), %edx\n" /* qtbl */
        "movl $1, %ecx\n"
        ".Lf208128_00208213:\n"
        "movzwl (%edx), %eax\n" /* line 168 */
        "movl %eax, -4(%esi, %ecx, 4)\n" /* ismtbl */
        "addl $1, %ecx\n"
        "addl $2, %edx\n"
        "cmpl $0x41, %ecx\n" /* line 167 */
        "jne .Lf208128_00208213\n"
        /* } scope */
        ".Lf208128_00208225:\n"
        "addl $1, -0x40(%ebp)\n" /* line 99 | ci */
        "addl $0x54, -0x38(%ebp)\n" /* compptr */
        "addl $4, -0x1c(%ebp)\n"
        "movl -0x40(%ebp), %edx\n" /* line 98 | ci */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "cmpl 0x2c(%eax), %edx\n"
        "jl .Lf208128_00208177\n"
        ".Lf208128_00208240:\n"
        "addl $0x4c, %esp\n" /* line 239 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf208128_00208248:\n"
        "cmpl $4, %eax\n" /* line 101 */
        "je .Lf208128_002082dd\n"
        "cmpl $8, %eax\n"
        "jne .Lf208128_0020819b\n"
        "movl 8(%ebp), %edx\n" /* line 117 | cinfo */
        "movl 0x4c(%edx), %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf208128_002083f3\n"
        "jb .Lf208128_002083dc\n"
        "cmpl $2, %eax\n"
        "je .Lf208128_0020840a\n"
        "movl 8(%ebp), %edx\n" /* line 137 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x30, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl -0x30(%ebp), %edx\n" /* method_ptr */
        "jmp .Lf208128_002081be\n"
        ".Lf208128_00208293:\n"
        "movl $0, -0x34(%ebp)\n" /* line 101 | method */
        "movl 0x17578a2(%ebx), %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* method_ptr */
        "movl %eax, %edx\n"
        "jmp .Lf208128_002081be\n"
        ".Lf208128_002082aa:\n"
        "movl 8(%ebp), %edx\n" /* line 235 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x30, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "addl $1, -0x40(%ebp)\n" /* line 99 | ci */
        "addl $0x54, -0x38(%ebp)\n" /* compptr */
        "addl $4, -0x1c(%ebp)\n"
        "movl -0x40(%ebp), %edx\n" /* line 98 | ci */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "cmpl 0x2c(%eax), %edx\n"
        "jl .Lf208128_00208177\n"
        "jmp .Lf208128_00208240\n"
        ".Lf208128_002082dd:\n"
        "movl $0, -0x34(%ebp)\n" /* line 101 | method */
        "movl 0x17578a6(%ebx), %edx\n"
        "movl %edx, -0x30(%ebp)\n" /* method_ptr */
        "jmp .Lf208128_002081be\n"
        ".Lf208128_002082f2:\n"
        "movl $0, -0x34(%ebp)\n" /* method */
        "movl 0x1757896(%ebx), %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* method_ptr */
        "movl %eax, %edx\n"
        "jmp .Lf208128_002081be\n"
        /* { scope 2 */
        ".Lf208128_00208309:\n"
        "movl -0x38(%ebp), %edx\n" /* line 183 | compptr */
        "movl 0x50(%edx), %edx\n"
        "movl %edx, -0x28(%ebp)\n" /* ifmtbl */
        "movl -0x2c(%ebp), %ecx\n" /* qtbl */
        "movl $1, %esi\n" /* ismtbl */
        "leal 0xff32a(%ebx), %edi\n"
        ".Lf208128_00208320:\n"
        "movzwl (%ecx), %eax\n" /* line 199 */
        "movswl (%edi), %edx\n"
        "imull %edx, %eax\n"
        "addl $0x800, %eax\n"
        "sarl $0xc, %eax\n"
        "movl -0x28(%ebp), %edx\n" /* ifmtbl */
        "movl %eax, -4(%edx, %esi, 4)\n"
        "addl $1, %esi\n" /* ismtbl */
        "addl $2, %ecx\n"
        "addl $2, %edi\n"
        "cmpl $0x41, %esi\n" /* line 198 | ismtbl */
        "jne .Lf208128_00208320\n"
        /* } scope */
        "addl $1, -0x40(%ebp)\n" /* line 99 | ci */
        "addl $0x54, -0x38(%ebp)\n" /* compptr */
        "addl $4, -0x1c(%ebp)\n"
        "movl -0x40(%ebp), %edx\n" /* line 98 | ci */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "cmpl 0x2c(%eax), %edx\n"
        "jl .Lf208128_00208177\n"
        "jmp .Lf208128_00208240\n"
        /* { scope 2 */
        ".Lf208128_00208366:\n"
        "movl -0x38(%ebp), %eax\n" /* line 198 | compptr */
        "movl 0x50(%eax), %edi\n"
        "movl $0, -0x3c(%ebp)\n" /* i */
        "leal 0xff2ea(%ebx), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl %edx, -0x44(%ebp)\n"
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl %edx, %esi\n" /* ismtbl */
        ".Lf208128_00208387:\n"
        "movl -0x3c(%ebp), %edx\n" /* i */
        "movl -0x2c(%ebp), %eax\n" /* qtbl */
        "leal (%eax, %edx, 2), %ecx\n"
        "movl %edi, %edx\n"
        "movl -0x20(%ebp), %eax\n"
        "movsd (%eax), %xmm1\n"
        /* } scope */
        /* { scope 2 */
        ".Lf208128_00208399:\n"
        "movzwl (%ecx), %eax\n" /* line 225 */
        "cvtsi2sdl %eax, %xmm0\n"
        "mulsd %xmm1, %xmm0\n"
        "mulsd (%esi), %xmm0\n" /* ismtbl */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "addl $2, %ecx\n"
        "addl $8, %esi\n" /* ismtbl */
        "addl $4, %edx\n"
        "cmpl %esi, -0x24(%ebp)\n" /* line 224 | ismtbl */
        "jne .Lf208128_00208399\n"
        "movl -0x3c(%ebp), %eax\n" /* line 90 | i */
        "addl $8, %eax\n"
        "movl %eax, -0x3c(%ebp)\n" /* i */
        "addl $0x20, %edi\n"
        "addl $8, -0x20(%ebp)\n"
        "cmpl $0x40, %eax\n" /* line 223 */
        "je .Lf208128_00208225\n"
        "movl -0x44(%ebp), %esi\n" /* ismtbl */
        "jmp .Lf208128_00208387\n"
        /* } scope */
        ".Lf208128_002083dc:\n"
        "movl $0, -0x34(%ebp)\n" /* line 117 | method */
        "movl 0x175789a(%ebx), %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* method_ptr */
        "movl %eax, %edx\n"
        "jmp .Lf208128_002081be\n"
        ".Lf208128_002083f3:\n"
        "movl $1, -0x34(%ebp)\n" /* method */
        "movl 0x17578aa(%ebx), %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* method_ptr */
        "movl %eax, %edx\n"
        "jmp .Lf208128_002081be\n"
        ".Lf208128_0020840a:\n"
        "movl $2, -0x34(%ebp)\n" /* method */
        "movl 0x175789e(%ebx), %edx\n"
        "movl %edx, -0x30(%ebp)\n" /* method_ptr */
        "jmp .Lf208128_002081be\n"
    );
}

/* line 248 */
__attribute__((naked))
void jinit_inverse_dct(j_decompress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 248 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %edx\n" /* line 253 | cinfo */
        "movl 4(%edx), %eax\n"
        "movl $0x54, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl %eax, %edx\n"
        "movl 8(%ebp), %eax\n" /* line 256 | cinfo */
        "movl %edx, 0x1a4(%eax)\n"
        "leal -0x305(%ebx), %eax\n" /* line 257 */
        "movl %eax, (%edx)\n"
        "movl 8(%ebp), %eax\n" /* line 259 | cinfo */
        "movl 0xcc(%eax), %edi\n" /* compptr */
        "movl 0x2c(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jg .Lf20841f_00208473\n"
        "addl $0x2c, %esp\n" /* line 269 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20841f_00208473:\n"
        "movl %edx, %esi\n" /* line 259 */
        "movl $0, -0x1c(%ebp)\n" /* ci */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "jmp .Lf20841f_00208483\n"
        ".Lf20841f_00208481:\n"
        "movl %eax, %edx\n"
        ".Lf20841f_00208483:\n"
        "movl 4(%edx), %eax\n" /* line 262 */
        "movl $0x100, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl %eax, 0x50(%edi)\n" /* compptr */
        "movl $0x100, 8(%esp)\n" /* line 265 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $0xffffffff, 0x2c(%esi)\n" /* line 267 */
        "addl $1, -0x1c(%ebp)\n" /* line 260 | ci */
        "addl $0x54, %edi\n" /* compptr */
        "addl $4, %esi\n"
        "movl -0x1c(%ebp), %edx\n" /* line 259 | ci */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "cmpl %edx, 0x2c(%eax)\n"
        "jg .Lf20841f_00208481\n"
        "addl $0x2c, %esp\n" /* line 269 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

