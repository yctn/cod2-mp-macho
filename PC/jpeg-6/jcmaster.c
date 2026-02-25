/* ASM dump from: jcmaster.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jcmaster.c */

#include "common_types.h"
#include "imports.h"

static void per_scan_setup(j_compress_ptr cinfo);
static void pass_startup(j_compress_ptr cinfo);
static void finish_pass_master(j_compress_ptr cinfo);
void jinit_c_master_control(j_compress_ptr cinfo, int transcode_only);
static void prepare_for_pass(j_compress_ptr cinfo);

/* line 311 */
static __attribute__((naked))
void per_scan_setup(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 311 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x20, %esp\n"
        "movl %eax, -0x14(%ebp)\n"
        "movl %eax, %edx\n" /* line 315 */
        "movl 0xe8(%eax), %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf20b338_0020b4ec\n"
        "subl $1, %eax\n" /* line 344 */
        "cmpl $3, %eax\n"
        "ja .Lf20b338_0020b4a7\n"
        ".Lf20b338_0020b360:\n"
        "movl -0x14(%ebp), %edx\n" /* line 349 */
        "movl 0xdc(%edx), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x24(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll jdiv_round_up\n"
        "movl -0x14(%ebp), %ecx\n"
        "movl %eax, 0xfc(%ecx)\n"
        "movl 0xe0(%ecx), %eax\n" /* line 352 */
        "shll $3, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x28(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll jdiv_round_up\n"
        "movl -0x14(%ebp), %esi\n"
        "movl %eax, 0x100(%esi)\n"
        "movl $0, 0x104(%esi)\n" /* line 356 */
        "movl 0xe8(%esi), %eax\n" /* line 358 */
        "testl %eax, %eax\n"
        "jle .Lf20b338_0020b479\n"
        "movl %esi, -0xc(%ebp)\n"
        "movl $0, -0x10(%ebp)\n" /* ci */
        "movl %esi, %eax\n"
        ".Lf20b338_0020b3c9:\n"
        "movl 0xec(%eax), %ecx\n" /* line 359 */
        "movl 8(%ecx), %esi\n" /* line 361 */
        "movl %esi, 0x34(%ecx)\n"
        "movl 0xc(%ecx), %edx\n" /* line 362 */
        "movl %edx, 0x38(%ecx)\n"
        "movl %edx, %edi\n" /* line 363 */
        "imull 0x34(%ecx), %edi\n"
        "movl %edi, 0x3c(%ecx)\n"
        "leal (, %esi, 8), %eax\n" /* line 364 */
        "movl %eax, 0x40(%ecx)\n"
        "movl 0x1c(%ecx), %eax\n" /* line 366 */
        "xorl %edx, %edx\n"
        "divl %esi\n"
        "testl %edx, %edx\n" /* line 367 */
        "cmovel %esi, %edx\n"
        "movl %edx, 0x44(%ecx)\n" /* line 368 */
        "movl 0x20(%ecx), %eax\n" /* line 369 */
        "xorl %edx, %edx\n"
        "divl 0xc(%ecx)\n"
        "testl %edx, %edx\n" /* line 370 */
        "cmovel 0xc(%ecx), %edx\n"
        "movl %edx, 0x48(%ecx)\n" /* line 371 */
        "movl %edi, %eax\n" /* line 374 */
        "movl -0x14(%ebp), %ecx\n"
        "addl 0x104(%ecx), %eax\n"
        "cmpl $0xa, %eax\n"
        "jg .Lf20b338_0020b4d3\n"
        ".Lf20b338_0020b422:\n"
        "leal -1(%edi), %ecx\n" /* line 376 */
        "testl %edi, %edi\n"
        "jle .Lf20b338_0020b45b\n"
        "movl -0x14(%ebp), %esi\n"
        "movl 0x104(%esi), %edx\n"
        "movl %esi, %eax\n"
        "jmp .Lf20b338_0020b439\n"
        ".Lf20b338_0020b436:\n"
        "movl -0x14(%ebp), %eax\n"
        ".Lf20b338_0020b439:\n"
        "movl -0x10(%ebp), %esi\n" /* line 377 | ci */
        "movl %esi, 0x108(%eax, %edx, 4)\n"
        "leal 1(%edx), %esi\n"
        "movl %esi, %edx\n"
        "subl $1, %ecx\n" /* line 376 */
        "leal 1(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf20b338_0020b436\n"
        "movl -0x14(%ebp), %eax\n"
        "movl %esi, 0x104(%eax)\n"
        ".Lf20b338_0020b45b:\n"
        "addl $1, -0x10(%ebp)\n" /* line 358 | ci */
        "addl $4, -0xc(%ebp)\n"
        "movl -0x10(%ebp), %ecx\n" /* ci */
        "movl -0x14(%ebp), %edx\n"
        "cmpl 0xe8(%edx), %ecx\n"
        "jge .Lf20b338_0020b4e8\n"
        "movl -0xc(%ebp), %eax\n"
        "jmp .Lf20b338_0020b3c9\n"
        ".Lf20b338_0020b479:\n"
        "movl -0x14(%ebp), %esi\n"
        ".Lf20b338_0020b47c:\n"
        "movl 0xc4(%esi), %eax\n" /* line 385 */
        "testl %eax, %eax\n"
        "jle .Lf20b338_0020b4a0\n"
        "imull 0xfc(%esi), %eax\n" /* line 387 */
        "cmpl $0x10000, %eax\n"
        "movl $0xffff, %edx\n"
        "cmovgel %edx, %eax\n"
        "movl %eax, 0xc0(%esi)\n"
        ".Lf20b338_0020b4a0:\n"
        "addl $0x20, %esp\n" /* line 389 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20b338_0020b4a7:\n"
        "movl -0x14(%ebp), %esi\n" /* line 345 */
        "movl (%esi), %eax\n"
        "movl $0x1a, 0x14(%eax)\n"
        "movl (%esi), %edx\n"
        "movl 0xe8(%esi), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl (%esi), %eax\n"
        "movl $4, 0x1c(%eax)\n"
        "movl (%esi), %eax\n"
        "movl %esi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf20b338_0020b360\n"
        ".Lf20b338_0020b4d3:\n"
        "movl (%ecx), %eax\n" /* line 375 */
        "movl $0xd, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf20b338_0020b422\n"
        ".Lf20b338_0020b4e8:\n"
        "movl %edx, %esi\n"
        "jmp .Lf20b338_0020b47c\n"
        ".Lf20b338_0020b4ec:\n"
        "movl 0xec(%edx), %ecx\n" /* line 318 */
        "movl 0x1c(%ecx), %eax\n" /* line 321 */
        "movl %eax, 0xfc(%edx)\n"
        "movl 0x20(%ecx), %eax\n" /* line 322 */
        "movl %eax, 0x100(%edx)\n"
        "movl $1, 0x34(%ecx)\n" /* line 325 */
        "movl $1, 0x38(%ecx)\n" /* line 326 */
        "movl $1, 0x3c(%ecx)\n" /* line 327 */
        "movl $8, 0x40(%ecx)\n" /* line 328 */
        "movl $1, 0x44(%ecx)\n" /* line 329 */
        "movl 0xc(%ecx), %edi\n" /* line 333 */
        "movl 0x20(%ecx), %eax\n"
        "xorl %edx, %edx\n"
        "divl %edi\n"
        "testl %edx, %edx\n" /* line 334 */
        "cmovnel %edx, %edi\n"
        "movl %edi, 0x48(%ecx)\n" /* line 335 */
        "movl -0x14(%ebp), %ecx\n" /* line 338 */
        "movl $1, 0x104(%ecx)\n"
        "movl $0, 0x108(%ecx)\n" /* line 339 */
        "movl -0x14(%ebp), %esi\n"
        "jmp .Lf20b338_0020b47c\n"
    );
}

/* line 490 */
static __attribute__((naked))
void pass_startup(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 490 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 0x140(%esi), %eax\n" /* line 491 | cinfo */
        "movb $0, 0xc(%eax)\n"
        "movl 0x150(%esi), %eax\n" /* line 493 | cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *4(%eax)\n"
        "movl 0x150(%esi), %eax\n" /* line 494 | cinfo */
        "movl %esi, 8(%ebp)\n" /* cinfo */
        "movl 8(%eax), %ecx\n"
        "addl $0x14, %esp\n" /* line 495 */
        "popl %esi\n"
        "popl %ebp\n"
        "jmpl *%ecx\n" /* line 494 */
    );
}

/* line 504 */
static __attribute__((naked))
void finish_pass_master(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 504 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %edi\n" /* cinfo */
        "movl 0x140(%edi), %esi\n" /* line 505 | cinfo, master */
        "movl 0x160(%edi), %eax\n" /* line 510 | cinfo */
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *8(%eax)\n"
        "movl 0x10(%esi), %eax\n" /* line 513 | master */
        "cmpl $1, %eax\n"
        "je .Lf20b58b_0020b5e1\n"
        "jb .Lf20b58b_0020b5c2\n"
        "cmpl $2, %eax\n"
        "je .Lf20b58b_0020b5f3\n"
        ".Lf20b58b_0020b5b7:\n"
        "addl $1, 0x14(%esi)\n" /* line 534 | master */
        "addl $0x10, %esp\n" /* line 535 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20b58b_0020b5c2:\n"
        "movl $2, 0x10(%esi)\n" /* line 518 | master */
        "cmpb $0, 0xb6(%edi)\n" /* line 519 | cinfo */
        "jne .Lf20b58b_0020b5b7\n"
        ".Lf20b58b_0020b5d2:\n"
        "addl $1, 0x1c(%esi)\n" /* line 530 | master */
        ".Lf20b58b_0020b5d6:\n"
        "addl $1, 0x14(%esi)\n" /* line 534 | master */
        "addl $0x10, %esp\n" /* line 535 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20b58b_0020b5e1:\n"
        "movl $2, 0x10(%esi)\n" /* line 524 | master */
        "addl $1, 0x14(%esi)\n" /* line 534 | master */
        "addl $0x10, %esp\n" /* line 535 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20b58b_0020b5f3:\n"
        "cmpb $0, 0xb6(%edi)\n" /* line 528 | cinfo */
        "je .Lf20b58b_0020b5d2\n"
        "movl $1, 0x10(%esi)\n" /* line 529 | master */
        "addl $1, 0x1c(%esi)\n" /* line 530 | master */
        "jmp .Lf20b58b_0020b5d6\n"
    );
}

/* line 544 */
__attribute__((naked))
void jinit_c_master_control(j_compress_ptr cinfo, int transcode_only)
{
    __asm__ __volatile__ (
        /* { scope 1: ci, scanptr, scanno, ncomps, ... */
        "pushl %ebp\n" /* line 544 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xa6c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movzbl 0xc(%ebp), %eax\n" /* transcode_only */
        "movb %al, -0xa61(%ebp)\n" /* transcode_only */
        "movl 8(%ebp), %edx\n" /* line 547 | cinfo */
        "movl 4(%edx), %eax\n"
        "movl $0x20, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl %eax, -0xa60(%ebp)\n" /* master */
        "movl 8(%ebp), %ecx\n" /* line 550 | cinfo */
        "movl %eax, 0x140(%ecx)\n"
        "leal 0x971(%ebx), %eax\n" /* line 551 */
        "movl -0xa60(%ebp), %edx\n" /* master */
        "movl %eax, (%edx)\n"
        "leal -0xc2(%ebx), %eax\n" /* line 552 */
        "movl %eax, 4(%edx)\n"
        "leal -0x8f(%ebx), %eax\n" /* line 553 */
        "movl %eax, 8(%edx)\n"
        "movb $0, 0xd(%edx)\n" /* line 554 */
        /* { scope 2 */
        "movl 0x28(%ecx), %edx\n" /* line 55 */
        "testl %edx, %edx\n"
        "je .Lf20b609_0020b684\n"
        "movl 0x24(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf20b609_0020bc18\n"
        ".Lf20b609_0020b684:\n"
        "movl 8(%ebp), %ecx\n" /* line 57 | cinfo */
        "movl (%ecx), %eax\n"
        "movl $0x20, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "movl 8(%ebp), %eax\n" /* line 60 | cinfo */
        "cmpl $0xffdc, 0x28(%eax)\n"
        "jg .Lf20b609_0020bc3e\n"
        ".Lf20b609_0020b6a7:\n"
        "cmpl $0xffdc, 0x24(%eax)\n"
        "jg .Lf20b609_0020bbb7\n"
        "movl 8(%ebp), %ecx\n" /* line 71 | cinfo */
        "cmpl $8, 0x3c(%ecx)\n"
        "je .Lf20b609_0020bbe0\n"
        ".Lf20b609_0020b6c1:\n"
        "movl (%ecx), %eax\n" /* line 72 */
        "movl $0xf, 0x14(%eax)\n"
        "movl (%ecx), %edx\n"
        "movl 0x3c(%ecx), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "cmpl $0xa, 0x40(%eax)\n" /* line 75 */
        "jg .Lf20b609_0020bbec\n"
        ".Lf20b609_0020b6e6:\n"
        "movl $1, 0xdc(%eax)\n" /* line 80 */
        "movl $1, 0xe0(%eax)\n" /* line 81 */
        "movl 0x48(%eax), %esi\n" /* line 82 | compptr */
        "movl 0x40(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf20b609_0020b834\n"
        "movl $0, -0xa5c(%ebp)\n" /* ci */
        ".Lf20b609_0020b712:\n"
        "leal 8(%esi), %edi\n" /* line 544 | last_bitpos_ptr, thisi */
        "movl 8(%esi), %eax\n" /* line 84 | compptr */
        "subl $1, %eax\n"
        "cmpl $3, %eax\n"
        "ja .Lf20b609_0020b72c\n"
        "movl 0xc(%esi), %eax\n" /* compptr */
        "testl %eax, %eax\n"
        "jle .Lf20b609_0020b72c\n"
        "cmpl $4, %eax\n"
        "jle .Lf20b609_0020b73f\n"
        ".Lf20b609_0020b72c:\n"
        "movl 8(%ebp), %edx\n" /* line 86 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x12, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf20b609_0020b73f:\n"
        "movl 8(%ebp), %ecx\n" /* line 87 | cinfo */
        "movl 0xdc(%ecx), %edx\n"
        "movl (%edi), %eax\n"
        "cmpl %edx, %eax\n"
        "cmovll %edx, %eax\n"
        "movl %eax, 0xdc(%ecx)\n"
        "movl 0xe0(%ecx), %edx\n" /* line 89 */
        "movl 0xc(%esi), %eax\n" /* compptr */
        "cmpl %edx, %eax\n"
        "cmovll %edx, %eax\n"
        "movl %eax, 0xe0(%ecx)\n"
        "addl $1, -0xa5c(%ebp)\n" /* line 83 | ci */
        "addl $0x54, %esi\n" /* compptr */
        "movl -0xa5c(%ebp), %eax\n" /* line 82 | ci */
        "cmpl 0x40(%ecx), %eax\n"
        "jl .Lf20b609_0020b712\n"
        "movl 0x48(%ecx), %esi\n" /* line 94 | compptr */
        "movl 0x40(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf20b609_0020b834\n"
        "xorl %edi, %edi\n"
        ".Lf20b609_0020b78e:\n"
        "movl %edi, 4(%esi)\n" /* line 97 | compptr */
        "movl $8, 0x24(%esi)\n" /* line 99 | compptr */
        "movl 8(%ebp), %edx\n" /* line 101 | cinfo */
        "movl 0xdc(%edx), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x24(%edx), %eax\n"
        "imull 8(%esi), %eax\n" /* compptr */
        "movl %eax, (%esp)\n"
        "calll jdiv_round_up\n"
        "movl %eax, 0x1c(%esi)\n" /* compptr */
        "movl 8(%ebp), %ecx\n" /* line 104 | cinfo */
        "movl 0xe0(%ecx), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x28(%ecx), %eax\n"
        "imull 0xc(%esi), %eax\n" /* compptr */
        "movl %eax, (%esp)\n"
        "calll jdiv_round_up\n"
        "movl %eax, 0x20(%esi)\n" /* compptr */
        "movl 8(%ebp), %edx\n" /* line 108 | cinfo */
        "movl 0xdc(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x24(%edx), %eax\n"
        "imull 8(%esi), %eax\n" /* compptr */
        "movl %eax, (%esp)\n"
        "calll jdiv_round_up\n"
        "movl %eax, 0x28(%esi)\n" /* compptr */
        "movl 8(%ebp), %ecx\n" /* line 111 | cinfo */
        "movl 0xe0(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x28(%ecx), %eax\n"
        "imull 0xc(%esi), %eax\n" /* compptr */
        "movl %eax, (%esp)\n"
        "calll jdiv_round_up\n"
        "movl %eax, 0x2c(%esi)\n" /* compptr */
        "movb $1, 0x30(%esi)\n" /* line 115 | compptr */
        "addl $1, %edi\n" /* line 95 */
        "addl $0x54, %esi\n" /* compptr */
        "movl 8(%ebp), %eax\n" /* line 94 | cinfo */
        "cmpl %edi, 0x40(%eax)\n"
        "jg .Lf20b609_0020b78e\n"
        "movl %eax, %edx\n"
        "jmp .Lf20b609_0020b837\n"
        ".Lf20b609_0020b834:\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        ".Lf20b609_0020b837:\n"
        "movl 0xe0(%edx), %eax\n" /* line 121 */
        "shll $3, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x28(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll jdiv_round_up\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %eax, 0xe4(%ecx)\n"
        /* } scope */
        "movl 0xb0(%ecx), %eax\n" /* line 559 */
        "testl %eax, %eax\n"
        "je .Lf20b609_0020bf32\n"
        /* { scope 2 */
        "movl 0xac(%ecx), %edi\n" /* line 145 | thisi */
        "testl %edi, %edi\n" /* thisi */
        "jle .Lf20b609_0020bf66\n"
        ".Lf20b609_0020b874:\n"
        "movl 8(%ebp), %eax\n" /* line 151 | cinfo */
        "movl 0xb0(%eax), %eax\n"
        "movl %eax, -0xa54(%ebp)\n" /* scanptr */
        "movl 0x14(%eax), %esi\n" /* line 152 | last_bitpos_ptr */
        "testl %esi, %esi\n" /* last_bitpos_ptr */
        "je .Lf20b609_0020bb80\n"
        ".Lf20b609_0020b88e:\n"
        "movl 8(%ebp), %edx\n" /* line 154 | cinfo */
        "movb $1, 0xd8(%edx)\n"
        "leal -0xa24(%ebp), %eax\n" /* line 155 | last_bitpos */
        "movl 0x40(%edx), %ecx\n" /* line 156 */
        "testl %ecx, %ecx\n"
        "jg .Lf20b609_0020bc45\n"
        ".Lf20b609_0020b8a9:\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        ".Lf20b609_0020b8ac:\n"
        "movl 0xac(%eax), %edx\n" /* line 168 */
        "testl %edx, %edx\n"
        "jle .Lf20b609_0020bc7d\n"
        ".Lf20b609_0020b8ba:\n"
        "movl $1, -0xa50(%ebp)\n" /* scanno */
        "leal -0xa24(%ebp), %edx\n" /* last_bitpos */
        "movl %edx, -0xa68(%ebp)\n"
        "movl -0xa54(%ebp), %ecx\n" /* line 170 | scanptr */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0xa4c(%ebp)\n" /* ncomps */
        "movl %ecx, %eax\n" /* line 171 */
        "subl $1, %eax\n"
        "cmpl $3, %eax\n"
        "ja .Lf20b609_0020bd6c\n"
        ".Lf20b609_0020b8ec:\n"
        "movl -0xa4c(%ebp), %eax\n" /* line 173 | ncomps */
        "testl %eax, %eax\n"
        "jle .Lf20b609_0020b998\n"
        "movl -0xa54(%ebp), %edi\n" /* scanptr, thisi */
        "movl $0, -0xa34(%ebp)\n"
        "jmp .Lf20b609_0020b924\n"
        ".Lf20b609_0020b90c:\n"
        "addl $1, -0xa34(%ebp)\n"
        "addl $4, %edi\n" /* thisi */
        "movl -0xa34(%ebp), %eax\n"
        "cmpl %eax, -0xa4c(%ebp)\n" /* ncomps */
        "je .Lf20b609_0020b998\n"
        ".Lf20b609_0020b924:\n"
        "movl 4(%edi), %esi\n" /* line 174 | thisi, last_bitpos_ptr */
        "testl %esi, %esi\n" /* line 175 | last_bitpos_ptr */
        "js .Lf20b609_0020be32\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "cmpl 0x40(%ecx), %esi\n" /* last_bitpos_ptr */
        "jl .Lf20b609_0020b954\n"
        "movl %ecx, %edx\n"
        ".Lf20b609_0020b939:\n"
        "movl (%edx), %eax\n" /* line 176 */
        "movl $0x13, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl -0xa50(%ebp), %ecx\n" /* scanno */
        "movl %ecx, 0x18(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf20b609_0020b954:\n"
        "movl -0xa34(%ebp), %eax\n" /* line 178 */
        "testl %eax, %eax\n"
        "jle .Lf20b609_0020b90c\n"
        "cmpl (%edi), %esi\n" /* thisi, last_bitpos_ptr */
        "jg .Lf20b609_0020b90c\n"
        "movl 8(%ebp), %edx\n" /* line 179 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x13, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl -0xa50(%ebp), %ecx\n" /* scanno */
        "movl %ecx, 0x18(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "addl $1, -0xa34(%ebp)\n" /* line 173 */
        "addl $4, %edi\n" /* thisi */
        "movl -0xa34(%ebp), %eax\n"
        "cmpl %eax, -0xa4c(%ebp)\n" /* ncomps */
        "jne .Lf20b609_0020b924\n"
        ".Lf20b609_0020b998:\n"
        "movl -0xa54(%ebp), %edx\n" /* line 182 | scanptr */
        "movl 0x14(%edx), %edx\n"
        "movl %edx, -0xa38(%ebp)\n"
        "movl -0xa54(%ebp), %ecx\n" /* line 183 | scanptr */
        "movl 0x18(%ecx), %ecx\n"
        "movl %ecx, -0xa48(%ebp)\n" /* Se */
        "movl -0xa54(%ebp), %eax\n" /* line 184 | scanptr */
        "movl 0x1c(%eax), %eax\n"
        "movl %eax, -0xa44(%ebp)\n" /* Ah */
        "movl -0xa54(%ebp), %edx\n" /* line 185 | scanptr */
        "movl 0x20(%edx), %edx\n"
        "movl %edx, -0xa40(%ebp)\n" /* Al */
        "movl 8(%ebp), %ecx\n" /* line 186 | cinfo */
        "cmpb $0, 0xd8(%ecx)\n"
        "je .Lf20b609_0020bd92\n"
        "cmpl $0x3f, -0xa38(%ebp)\n" /* line 200 */
        "ja .Lf20b609_0020ba17\n"
        "movl -0xa48(%ebp), %eax\n" /* Se */
        "cmpl %eax, -0xa38(%ebp)\n"
        "jg .Lf20b609_0020ba17\n"
        "cmpl $0x3f, %eax\n"
        "jg .Lf20b609_0020ba17\n"
        "movl -0xa44(%ebp), %eax\n" /* Ah */
        "testl %eax, %eax\n"
        "js .Lf20b609_0020ba17\n"
        "cmpl $0xa, -0xa44(%ebp)\n" /* Ah */
        "jle .Lf20b609_0020bf1c\n"
        ".Lf20b609_0020ba17:\n"
        "movl 8(%ebp), %edx\n" /* line 202 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x11, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl -0xa50(%ebp), %ecx\n" /* scanno */
        "movl %ecx, 0x18(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf20b609_0020ba35:\n"
        "movl -0xa38(%ebp), %edi\n" /* line 203 | thisi */
        "testl %edi, %edi\n" /* thisi */
        "jne .Lf20b609_0020be3a\n"
        "movl -0xa48(%ebp), %esi\n" /* line 204 | Se, last_bitpos_ptr */
        "testl %esi, %esi\n" /* last_bitpos_ptr */
        "jne .Lf20b609_0020be47\n"
        ".Lf20b609_0020ba51:\n"
        "movl -0xa4c(%ebp), %ecx\n" /* line 210 | ncomps */
        "testl %ecx, %ecx\n"
        "jle .Lf20b609_0020bd2d\n"
        "movl -0xa44(%ebp), %eax\n" /* line 221 | Ah */
        "subl $1, %eax\n"
        "movl %eax, -0xa58(%ebp)\n"
        "movl -0xa54(%ebp), %edx\n" /* scanptr */
        "movl %edx, -0xa3c(%ebp)\n"
        "movl $0, -0xa30(%ebp)\n"
        "movl %edx, %ecx\n"
        ".Lf20b609_0020ba86:\n"
        "movl 4(%ecx), %eax\n" /* line 211 */
        "shll $8, %eax\n"
        "movl -0xa68(%ebp), %esi\n" /* last_bitpos_ptr */
        "addl %eax, %esi\n" /* last_bitpos_ptr */
        "movl -0xa38(%ebp), %edx\n" /* line 212 */
        "testl %edx, %edx\n"
        "je .Lf20b609_0020baa8\n"
        "movl (%esi), %eax\n" /* last_bitpos_ptr */
        "testl %eax, %eax\n"
        "js .Lf20b609_0020be96\n"
        ".Lf20b609_0020baa8:\n"
        "movl -0xa48(%ebp), %eax\n" /* line 214 | Se */
        "cmpl %eax, -0xa38(%ebp)\n"
        "jg .Lf20b609_0020bb55\n"
        "movl -0xa38(%ebp), %edx\n"
        "leal (%esi, %edx, 4), %esi\n" /* last_bitpos_ptr */
        "movl %edx, %edi\n" /* thisi */
        "jmp .Lf20b609_0020bb11\n"
        ".Lf20b609_0020bac7:\n"
        "cmpl %eax, -0xa44(%ebp)\n" /* line 221 | Ah */
        "jne .Lf20b609_0020badd\n"
        "movl -0xa58(%ebp), %ecx\n"
        "cmpl %ecx, -0xa40(%ebp)\n" /* Al */
        "je .Lf20b609_0020bafb\n"
        ".Lf20b609_0020badd:\n"
        "movl 8(%ebp), %edx\n" /* line 222 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x11, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl -0xa50(%ebp), %ecx\n" /* scanno */
        "movl %ecx, 0x18(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf20b609_0020bafb:\n"
        "movl -0xa40(%ebp), %eax\n" /* line 224 | Al */
        "movl %eax, (%esi)\n" /* last_bitpos_ptr */
        "addl $1, %edi\n" /* line 214 | thisi */
        "addl $4, %esi\n" /* last_bitpos_ptr */
        "cmpl %edi, -0xa48(%ebp)\n" /* thisi, Se */
        "jl .Lf20b609_0020bb55\n"
        ".Lf20b609_0020bb11:\n"
        "movl (%esi), %eax\n" /* line 215 | last_bitpos_ptr */
        "testl %eax, %eax\n"
        "jns .Lf20b609_0020bac7\n"
        "movl -0xa44(%ebp), %eax\n" /* line 217 | Ah */
        "testl %eax, %eax\n"
        "je .Lf20b609_0020bafb\n"
        "movl 8(%ebp), %ecx\n" /* line 218 | cinfo */
        "movl (%ecx), %eax\n"
        "movl $0x11, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl -0xa50(%ebp), %edx\n" /* scanno */
        "movl %edx, 0x18(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "movl -0xa40(%ebp), %eax\n" /* line 224 | Al */
        "movl %eax, (%esi)\n" /* last_bitpos_ptr */
        "addl $1, %edi\n" /* line 214 | thisi */
        "addl $4, %esi\n" /* last_bitpos_ptr */
        "cmpl %edi, -0xa48(%ebp)\n" /* thisi, Se */
        "jge .Lf20b609_0020bb11\n"
        ".Lf20b609_0020bb55:\n"
        "addl $1, -0xa30(%ebp)\n" /* line 210 */
        "addl $4, -0xa3c(%ebp)\n"
        "movl -0xa30(%ebp), %edx\n"
        "cmpl %edx, -0xa4c(%ebp)\n" /* ncomps */
        "je .Lf20b609_0020bd2d\n"
        "movl -0xa3c(%ebp), %ecx\n"
        "jmp .Lf20b609_0020ba86\n"
        ".Lf20b609_0020bb80:\n"
        "cmpl $0x3f, 0x18(%eax)\n" /* line 152 */
        "jne .Lf20b609_0020b88e\n"
        "movl 8(%ebp), %edx\n" /* line 163 | cinfo */
        "movb $0, 0xd8(%edx)\n"
        "movl 8(%ebp), %ecx\n" /* line 164 | cinfo */
        "movl 0x40(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf20b609_0020bf84\n"
        "xorl %eax, %eax\n"
        "leal -0x22(%ebp), %edi\n" /* component_sent, thisi */
        ".Lf20b609_0020bba7:\n"
        "movb $0, (%eax, %edi)\n" /* line 165 */
        "addl $1, %eax\n" /* line 164 */
        "cmpl %eax, %edx\n"
        "jne .Lf20b609_0020bba7\n"
        "jmp .Lf20b609_0020b8a9\n"
        ".Lf20b609_0020bbb7:\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        /* } scope */
        /* { scope 2 */
        ".Lf20b609_0020bbba:\n"
        "movl (%edx), %eax\n" /* line 62 */
        "movl $0x29, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl $0xffdc, 0x18(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 71 | cinfo */
        "cmpl $8, 0x3c(%ecx)\n"
        "jne .Lf20b609_0020b6c1\n"
        ".Lf20b609_0020bbe0:\n"
        "movl %ecx, %eax\n"
        "cmpl $0xa, 0x40(%eax)\n" /* line 75 */
        "jle .Lf20b609_0020b6e6\n"
        ".Lf20b609_0020bbec:\n"
        "movl (%eax), %eax\n" /* line 76 */
        "movl $0x1a, 0x14(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl (%ecx), %edx\n"
        "movl 0x40(%ecx), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl (%ecx), %eax\n"
        "movl $0xa, 0x1c(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "jmp .Lf20b609_0020b6e6\n"
        ".Lf20b609_0020bc18:\n"
        "movl 0x40(%ecx), %eax\n" /* line 55 */
        "testl %eax, %eax\n"
        "jle .Lf20b609_0020b684\n"
        "movl 0x2c(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf20b609_0020b684\n"
        "movl 8(%ebp), %eax\n" /* line 60 | cinfo */
        "cmpl $0xffdc, 0x28(%eax)\n"
        "jle .Lf20b609_0020b6a7\n"
        ".Lf20b609_0020bc3e:\n"
        "movl %eax, %edx\n"
        "jmp .Lf20b609_0020bbba\n"
        /* } scope */
        /* { scope 2 */
        ".Lf20b609_0020bc45:\n"
        "movl %eax, %esi\n" /* line 156 | last_bitpos_ptr */
        "xorl %ecx, %ecx\n"
        ".Lf20b609_0020bc49:\n"
        "movl %esi, %eax\n" /* last_bitpos_ptr */
        "xorl %edx, %edx\n"
        ".Lf20b609_0020bc4d:\n"
        "movl $0xffffffff, (%eax)\n" /* line 158 */
        "addl $4, %eax\n"
        "addl $1, %edx\n" /* line 157 */
        "cmpl $0x40, %edx\n"
        "jne .Lf20b609_0020bc4d\n"
        "addl $1, %ecx\n" /* line 156 */
        "addl $0x100, %esi\n" /* last_bitpos_ptr */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "cmpl %ecx, 0x40(%eax)\n"
        "jg .Lf20b609_0020bc49\n"
        "movl 0xac(%eax), %edx\n" /* line 168 */
        "testl %edx, %edx\n"
        "jg .Lf20b609_0020b8ba\n"
        ".Lf20b609_0020bc7d:\n"
        "cmpb $0, 0xd8(%eax)\n" /* line 243 */
        "je .Lf20b609_0020beb9\n"
        "movl %eax, %edx\n"
        "movl 0x40(%eax), %ecx\n" /* line 250 */
        "testl %ecx, %ecx\n"
        "jle .Lf20b609_0020bcb6\n"
        "xorl %esi, %esi\n" /* last_bitpos_ptr */
        ".Lf20b609_0020bc95:\n"
        "movl %esi, %eax\n" /* line 251 | last_bitpos_ptr */
        "shll $8, %eax\n"
        "movl -0xa24(%ebp, %eax), %edi\n" /* thisi */
        "testl %edi, %edi\n" /* thisi */
        "js .Lf20b609_0020bf4e\n"
        ".Lf20b609_0020bca9:\n"
        "addl $1, %esi\n" /* line 250 | last_bitpos_ptr */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "cmpl 0x40(%ecx), %esi\n" /* last_bitpos_ptr */
        "jl .Lf20b609_0020bc95\n"
        ".Lf20b609_0020bcb4:\n"
        "movl %ecx, %edx\n"
        /* } scope */
        ".Lf20b609_0020bcb6:\n"
        "cmpb $0, 0xd8(%edx)\n" /* line 570 */
        "je .Lf20b609_0020bcc6\n"
        "movb $1, 0xb6(%edx)\n" /* line 571 */
        ".Lf20b609_0020bcc6:\n"
        "cmpb $0, -0xa61(%ebp)\n" /* line 574 | transcode_only */
        "je .Lf20b609_0020be84\n"
        "movl 8(%ebp), %ecx\n" /* line 577 | cinfo */
        "cmpb $1, 0xb6(%ecx)\n"
        "sbbl %eax, %eax\n"
        "notl %eax\n"
        "addl $2, %eax\n"
        "movl -0xa60(%ebp), %edx\n" /* master */
        "movl %eax, 0x10(%edx)\n"
        ".Lf20b609_0020bced:\n"
        "movl -0xa60(%ebp), %eax\n" /* line 584 | master */
        "movl $0, 0x1c(%eax)\n"
        "movl $0, 0x14(%eax)\n" /* line 585 */
        "movl 8(%ebp), %edx\n" /* line 586 | cinfo */
        "cmpb $0, 0xb6(%edx)\n"
        "je .Lf20b609_0020be6a\n"
        "movl 0xac(%edx), %eax\n" /* line 587 */
        "addl %eax, %eax\n"
        "movl -0xa60(%ebp), %ecx\n" /* master */
        "movl %eax, 0x18(%ecx)\n"
        "addl $0xa6c, %esp\n" /* line 590 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2 */
        ".Lf20b609_0020bd2d:\n"
        "addl $0x24, -0xa54(%ebp)\n" /* line 168 | scanptr */
        "addl $1, -0xa50(%ebp)\n" /* scanno */
        "movl -0xa50(%ebp), %edx\n" /* scanno */
        "movl 8(%ebp), %eax\n" /* cinfo */
        "cmpl 0xac(%eax), %edx\n"
        "jg .Lf20b609_0020bc7d\n"
        "movl -0xa54(%ebp), %ecx\n" /* line 170 | scanptr */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0xa4c(%ebp)\n" /* ncomps */
        "movl %ecx, %eax\n" /* line 171 */
        "subl $1, %eax\n"
        "cmpl $3, %eax\n"
        "jbe .Lf20b609_0020b8ec\n"
        ".Lf20b609_0020bd6c:\n"
        "movl 8(%ebp), %edx\n" /* line 172 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x1a, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %ecx, 0x18(%eax)\n"
        "movl (%edx), %eax\n"
        "movl $4, 0x1c(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf20b609_0020b8ec\n"
        ".Lf20b609_0020bd92:\n"
        "movl -0xa38(%ebp), %eax\n" /* line 230 */
        "testl %eax, %eax\n"
        "jne .Lf20b609_0020bda9\n"
        "cmpl $0x3f, -0xa48(%ebp)\n" /* Se */
        "je .Lf20b609_0020bef4\n"
        ".Lf20b609_0020bda9:\n"
        "movl 8(%ebp), %ecx\n" /* line 231 | cinfo */
        "movl (%ecx), %eax\n"
        "movl $0x11, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl -0xa50(%ebp), %edx\n" /* scanno */
        "movl %edx, 0x18(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf20b609_0020bdc7:\n"
        "movl -0xa4c(%ebp), %eax\n" /* line 233 | ncomps */
        "testl %eax, %eax\n"
        "jle .Lf20b609_0020bd2d\n"
        "movl -0xa54(%ebp), %esi\n" /* scanptr, last_bitpos_ptr */
        "movl $0, -0xa2c(%ebp)\n"
        "jmp .Lf20b609_0020be08\n"
        ".Lf20b609_0020bde7:\n"
        "movb $1, -0x22(%ebp, %edi)\n" /* line 237 */
        "addl $1, -0xa2c(%ebp)\n" /* line 233 */
        "addl $4, %esi\n" /* last_bitpos_ptr */
        "movl -0xa2c(%ebp), %ecx\n"
        "cmpl %ecx, -0xa4c(%ebp)\n" /* ncomps */
        "je .Lf20b609_0020bd2d\n"
        ".Lf20b609_0020be08:\n"
        "movl 4(%esi), %edi\n" /* line 234 | last_bitpos_ptr, thisi */
        "cmpb $0, -0x22(%ebp, %edi)\n" /* line 235 */
        "je .Lf20b609_0020bde7\n"
        "movl 8(%ebp), %ecx\n" /* line 236 | cinfo */
        "movl (%ecx), %eax\n"
        "movl $0x13, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl -0xa50(%ebp), %edx\n" /* scanno */
        "movl %edx, 0x18(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf20b609_0020bde7\n"
        ".Lf20b609_0020be32:\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "jmp .Lf20b609_0020b939\n"
        ".Lf20b609_0020be3a:\n"
        "cmpl $1, -0xa4c(%ebp)\n" /* line 207 | ncomps */
        "je .Lf20b609_0020ba51\n"
        ".Lf20b609_0020be47:\n"
        "movl 8(%ebp), %edx\n" /* line 208 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x11, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl -0xa50(%ebp), %ecx\n" /* scanno */
        "movl %ecx, 0x18(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf20b609_0020ba51\n"
        /* } scope */
        ".Lf20b609_0020be6a:\n"
        "movl 0xac(%edx), %eax\n" /* line 589 */
        "movl -0xa60(%ebp), %ecx\n" /* master */
        "movl %eax, 0x18(%ecx)\n"
        "addl $0xa6c, %esp\n" /* line 590 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf20b609_0020be84:\n"
        "movl -0xa60(%ebp), %ecx\n" /* line 582 | master */
        "movl $0, 0x10(%ecx)\n"
        "jmp .Lf20b609_0020bced\n"
        /* { scope 2 */
        ".Lf20b609_0020be96:\n"
        "movl 8(%ebp), %edx\n" /* line 213 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x11, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl -0xa50(%ebp), %ecx\n" /* scanno */
        "movl %ecx, 0x18(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf20b609_0020baa8\n"
        ".Lf20b609_0020beb9:\n"
        "movl 8(%ebp), %eax\n" /* line 256 | cinfo */
        "movl 0x40(%eax), %esi\n" /* last_bitpos_ptr */
        "testl %esi, %esi\n" /* last_bitpos_ptr */
        "jle .Lf20b609_0020bf15\n"
        "xorl %esi, %esi\n" /* last_bitpos_ptr */
        "leal -0x22(%ebp), %edi\n" /* component_sent, thisi */
        "jmp .Lf20b609_0020bed9\n"
        ".Lf20b609_0020beca:\n"
        "addl $1, %esi\n" /* last_bitpos_ptr */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "cmpl 0x40(%ecx), %esi\n" /* last_bitpos_ptr */
        "jge .Lf20b609_0020bcb4\n"
        ".Lf20b609_0020bed9:\n"
        "cmpb $0, (%esi, %edi)\n" /* line 257 | last_bitpos_ptr */
        "jne .Lf20b609_0020beca\n"
        "movl 8(%ebp), %edx\n" /* line 258 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x2d, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf20b609_0020beca\n"
        ".Lf20b609_0020bef4:\n"
        "movl -0xa44(%ebp), %eax\n" /* line 230 | Ah */
        "testl %eax, %eax\n"
        "jne .Lf20b609_0020bda9\n"
        "movl -0xa40(%ebp), %eax\n" /* Al */
        "testl %eax, %eax\n"
        "je .Lf20b609_0020bdc7\n"
        "jmp .Lf20b609_0020bda9\n"
        ".Lf20b609_0020bf15:\n"
        "movl %eax, %edx\n"
        "jmp .Lf20b609_0020bcb6\n"
        ".Lf20b609_0020bf1c:\n"
        "testl %edx, %edx\n" /* line 200 */
        "js .Lf20b609_0020ba17\n"
        "cmpl $0xa, %edx\n"
        "jle .Lf20b609_0020ba35\n"
        "jmp .Lf20b609_0020ba17\n"
        /* } scope */
        ".Lf20b609_0020bf32:\n"
        "movl 8(%ebp), %eax\n" /* line 566 | cinfo */
        "movb $0, 0xd8(%eax)\n"
        "movl $1, 0xac(%eax)\n" /* line 567 */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "jmp .Lf20b609_0020bcb6\n"
        /* { scope 2 */
        ".Lf20b609_0020bf4e:\n"
        "movl 8(%ebp), %edx\n" /* line 252 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x2d, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf20b609_0020bca9\n"
        ".Lf20b609_0020bf66:\n"
        "movl (%ecx), %eax\n" /* line 146 */
        "movl $0x13, 0x14(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl $0, 0x18(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf20b609_0020b874\n"
        ".Lf20b609_0020bf84:\n"
        "movl %ecx, %eax\n"
        "jmp .Lf20b609_0020b8ac\n"
    );
}

/* line 402 */
static __attribute__((naked))
void prepare_for_pass(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        /* { scope 1: ci, ci, ci */
        "pushl %ebp\n" /* line 402 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x40, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 403 | cinfo */
        "movl 0x140(%eax), %eax\n"
        "movl %eax, -0x18(%ebp)\n" /* master */
        "movl 0x10(%eax), %eax\n" /* line 405 */
        "cmpl $1, %eax\n"
        "je .Lf20bf8b_0020c0d5\n"
        "jb .Lf20bf8b_0020bff9\n"
        "cmpl $2, %eax\n"
        "je .Lf20bf8b_0020c16d\n"
        "movl 8(%ebp), %edx\n" /* line 465 | cinfo */
        "movl (%edx), %eax\n"
        "movl $0x30, 0x14(%eax)\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        ".Lf20bf8b_0020bfc9:\n"
        "movl -0x18(%ebp), %ecx\n" /* line 468 | master */
        "movl 0x18(%ecx), %eax\n"
        "subl $1, %eax\n"
        "cmpl %eax, 0x14(%ecx)\n"
        "sete 0xd(%ecx)\n"
        "movl 8(%ebp), %edi\n" /* line 471 | cinfo, scanptr */
        "movl 8(%edi), %edx\n" /* scanptr */
        "testl %edx, %edx\n"
        "je .Lf20bf8b_0020bff2\n"
        "movl 0x14(%ecx), %eax\n" /* line 472 */
        "movl %eax, 0xc(%edx)\n"
        "movl 8(%edi), %edx\n" /* line 473 | scanptr */
        "movl 0x18(%ecx), %eax\n"
        "movl %eax, 0x10(%edx)\n"
        ".Lf20bf8b_0020bff2:\n"
        "addl $0x40, %esp\n" /* line 475 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 2 */
        ".Lf20bf8b_0020bff9:\n"
        "movl 8(%ebp), %ecx\n" /* line 273 | cinfo */
        "movl 0xb0(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf20bf8b_0020c324\n"
        /* { scope 3 */
        "movl -0x18(%ebp), %edi\n" /* line 276 | master, scanptr */
        "movl 0x1c(%edi), %eax\n" /* scanptr */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%edx, %eax, 4), %edi\n" /* scanptr */
        "movl (%edi), %eax\n" /* line 278 | scanptr */
        "movl %eax, 0xe8(%ecx)\n"
        "movl (%edi), %edx\n" /* line 279 | scanptr */
        "testl %edx, %edx\n"
        "jg .Lf20bf8b_0020c230\n"
        ".Lf20bf8b_0020c028:\n"
        "movl 0x14(%edi), %eax\n" /* line 283 | scanptr */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %eax, 0x130(%ecx)\n"
        "movl 0x18(%edi), %eax\n" /* line 284 | scanptr */
        "movl %eax, 0x134(%ecx)\n"
        "movl 0x1c(%edi), %eax\n" /* line 285 | scanptr */
        "movl %eax, 0x138(%ecx)\n"
        "movl 0x20(%edi), %eax\n" /* line 286 | scanptr */
        "movl %eax, 0x13c(%ecx)\n"
        /* } scope */
        /* } scope */
        ".Lf20bf8b_0020c04f:\n"
        "movl 8(%ebp), %eax\n" /* line 411 | cinfo */
        "calll per_scan_setup\n"
        "movl 8(%ebp), %edx\n" /* line 412 | cinfo */
        "cmpb $0, 0xb4(%edx)\n"
        "je .Lf20bf8b_0020c2e2\n"
        ".Lf20bf8b_0020c067:\n"
        "movl 0x15c(%edx), %eax\n" /* line 417 */
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 418 | cinfo */
        "movl 0x160(%ecx), %edx\n"
        "movzbl 0xb6(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *(%edx)\n"
        "movl 8(%ebp), %edi\n" /* line 419 | cinfo, scanptr */
        "movl 0x14c(%edi), %eax\n" /* scanptr */
        "movl (%eax), %edx\n"
        "movl -0x18(%ebp), %eax\n" /* master */
        "cmpl $2, 0x18(%eax)\n"
        "setge %al\n"
        "movzbl %al, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* scanptr */
        "calll *%edx\n"
        "movl 0x144(%edi), %eax\n" /* line 422 | scanptr */
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* scanptr */
        "calll *(%eax)\n"
        "cmpb $0, 0xb6(%edi)\n" /* line 425 | scanptr */
        "movl -0x18(%ebp), %edx\n" /* master */
        "sete 0xc(%edx)\n"
        "jmp .Lf20bf8b_0020bfc9\n"
        /* { scope 2 */
        ".Lf20bf8b_0020c0d5:\n"
        "movl 8(%ebp), %ecx\n" /* line 273 | cinfo */
        "movl 0xb0(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf20bf8b_0020c39e\n"
        /* { scope 3 */
        "movl -0x18(%ebp), %edi\n" /* line 276 | master, scanptr */
        "movl 0x1c(%edi), %eax\n" /* scanptr */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%edx, %eax, 4), %edi\n" /* scanptr */
        "movl (%edi), %eax\n" /* line 278 | scanptr */
        "movl %eax, 0xe8(%ecx)\n"
        "movl (%edi), %eax\n" /* line 279 | scanptr */
        "testl %eax, %eax\n"
        "jg .Lf20bf8b_0020c26d\n"
        ".Lf20bf8b_0020c104:\n"
        "movl 0x14(%edi), %eax\n" /* line 283 | scanptr */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %eax, 0x130(%ecx)\n"
        "movl 0x18(%edi), %eax\n" /* line 284 | scanptr */
        "movl %eax, 0x134(%ecx)\n"
        "movl 0x1c(%edi), %eax\n" /* line 285 | scanptr */
        "movl %eax, 0x138(%ecx)\n"
        "movl 0x20(%edi), %eax\n" /* line 286 | scanptr */
        "movl %eax, 0x13c(%ecx)\n"
        /* } scope */
        /* } scope */
        ".Lf20bf8b_0020c12b:\n"
        "movl 8(%ebp), %eax\n" /* line 435 | cinfo */
        "calll per_scan_setup\n"
        "movl 8(%ebp), %edx\n" /* line 436 | cinfo */
        "movl 0x130(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf20bf8b_0020c319\n"
        "movl 0x138(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf20bf8b_0020c2aa\n"
        "cmpb $0, 0xb5(%edx)\n"
        "jne .Lf20bf8b_0020c2aa\n"
        "movl -0x18(%ebp), %edx\n" /* line 445 | master */
        "movl $2, 0x10(%edx)\n"
        "addl $1, 0x14(%edx)\n" /* line 446 */
        ".Lf20bf8b_0020c16d:\n"
        "movl 8(%ebp), %ecx\n" /* line 452 | cinfo */
        "cmpb $0, 0xb6(%ecx)\n"
        "jne .Lf20bf8b_0020c31d\n"
        /* { scope 2 */
        "movl 0xb0(%ecx), %edx\n" /* line 273 */
        "testl %edx, %edx\n"
        "je .Lf20bf8b_0020c4c1\n"
        /* { scope 3 */
        "movl 0x140(%ecx), %eax\n" /* line 276 */
        "movl 0x1c(%eax), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%edx, %eax, 4), %edi\n" /* scanptr */
        "movl (%edi), %eax\n" /* line 278 | scanptr */
        "movl %eax, 0xe8(%ecx)\n"
        "movl (%edi), %eax\n" /* line 279 | scanptr */
        "testl %eax, %eax\n"
        "jg .Lf20bf8b_0020c418\n"
        ".Lf20bf8b_0020c1ac:\n"
        "movl 0x14(%edi), %eax\n" /* line 283 | scanptr */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl %eax, 0x130(%ecx)\n"
        "movl 0x18(%edi), %eax\n" /* line 284 | scanptr */
        "movl %eax, 0x134(%ecx)\n"
        "movl 0x1c(%edi), %eax\n" /* line 285 | scanptr */
        "movl %eax, 0x138(%ecx)\n"
        "movl 0x20(%edi), %eax\n" /* line 286 | scanptr */
        "movl %eax, 0x13c(%ecx)\n"
        /* } scope */
        /* } scope */
        ".Lf20bf8b_0020c1d3:\n"
        "movl 8(%ebp), %eax\n" /* line 454 | cinfo */
        "calll per_scan_setup\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        ".Lf20bf8b_0020c1de:\n"
        "movl 0x160(%edx), %eax\n" /* line 456 */
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 457 | cinfo */
        "movl 0x14c(%ecx), %eax\n"
        "movl $2, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "movl -0x18(%ebp), %edi\n" /* line 459 | master, scanptr */
        "movl 0x1c(%edi), %ecx\n" /* scanptr */
        "testl %ecx, %ecx\n"
        "je .Lf20bf8b_0020c4ad\n"
        ".Lf20bf8b_0020c215:\n"
        "movl 8(%ebp), %ecx\n" /* line 461 | cinfo */
        "movl 0x150(%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *8(%eax)\n"
        "movl -0x18(%ebp), %edi\n" /* line 462 | master, scanptr */
        "movb $0, 0xc(%edi)\n" /* scanptr */
        "jmp .Lf20bf8b_0020bfc9\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf20bf8b_0020c230:\n"
        "movl %edi, %esi\n" /* line 279 | scanptr */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl $0, -0x14(%ebp)\n" /* ci */
        "movl 0x48(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        ".Lf20bf8b_0020c242:\n"
        "movl 4(%esi), %eax\n" /* line 280 */
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 4), %edx\n"
        "movl -0x1c(%ebp), %eax\n"
        "leal (%eax, %edx, 4), %edx\n"
        "movl %edx, 0xec(%ecx)\n"
        "addl $1, -0x14(%ebp)\n" /* line 279 | ci */
        "addl $4, %esi\n"
        "addl $4, %ecx\n"
        "movl -0x14(%ebp), %edx\n" /* ci */
        "cmpl (%edi), %edx\n" /* scanptr */
        "jl .Lf20bf8b_0020c242\n"
        "jmp .Lf20bf8b_0020c028\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf20bf8b_0020c26d:\n"
        "movl %edi, %esi\n" /* scanptr */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl $0, -0x10(%ebp)\n" /* ci */
        "movl 0x48(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        ".Lf20bf8b_0020c27f:\n"
        "movl 4(%esi), %eax\n" /* line 280 */
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 4), %edx\n"
        "movl -0x1c(%ebp), %eax\n"
        "leal (%eax, %edx, 4), %edx\n"
        "movl %edx, 0xec(%ecx)\n"
        "addl $1, -0x10(%ebp)\n" /* line 279 | ci */
        "addl $4, %esi\n"
        "addl $4, %ecx\n"
        "movl -0x10(%ebp), %edx\n" /* ci */
        "cmpl %edx, (%edi)\n" /* scanptr */
        "jg .Lf20bf8b_0020c27f\n"
        "jmp .Lf20bf8b_0020c104\n"
        ".Lf20bf8b_0020c2aa:\n"
        "movl 8(%ebp), %ecx\n" /* cinfo */
        /* } scope */
        /* } scope */
        ".Lf20bf8b_0020c2ad:\n"
        "movl 0x160(%ecx), %eax\n" /* line 437 */
        "movl $1, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "movl 8(%ebp), %edi\n" /* line 438 | cinfo, scanptr */
        "movl 0x14c(%edi), %eax\n" /* scanptr */
        "movl $2, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* scanptr */
        "calll *(%eax)\n"
        "movl -0x18(%ebp), %eax\n" /* line 439 | master */
        "movb $0, 0xc(%eax)\n"
        "jmp .Lf20bf8b_0020bfc9\n"
        ".Lf20bf8b_0020c2e2:\n"
        "movl 0x154(%edx), %eax\n" /* line 413 */
        "movl %edx, (%esp)\n"
        "calll *(%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 414 | cinfo */
        "movl 0x158(%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "movl 8(%ebp), %edi\n" /* line 415 | cinfo, scanptr */
        "movl 0x148(%edi), %eax\n" /* scanptr */
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* scanptr */
        "calll *(%eax)\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "jmp .Lf20bf8b_0020c067\n"
        ".Lf20bf8b_0020c319:\n"
        "movl %edx, %ecx\n"
        "jmp .Lf20bf8b_0020c2ad\n"
        ".Lf20bf8b_0020c31d:\n"
        "movl %ecx, %edx\n"
        "jmp .Lf20bf8b_0020c1de\n"
        /* { scope 2 */
        ".Lf20bf8b_0020c324:\n"
        "cmpl $4, 0x40(%ecx)\n" /* line 292 */
        "jg .Lf20bf8b_0020c455\n"
        "movl %ecx, %eax\n"
        "movl %ecx, %edx\n"
        ".Lf20bf8b_0020c332:\n"
        "movl 0x40(%eax), %eax\n" /* line 295 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl %eax, 0xe8(%edx)\n"
        "movl 0x40(%edx), %eax\n" /* line 296 */
        "testl %eax, %eax\n"
        "jle .Lf20bf8b_0020c36e\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "xorl %esi, %esi\n"
        "xorl %ecx, %ecx\n"
        "movl 0x48(%edx), %edi\n" /* scanptr */
        "movl %edi, -0x1c(%ebp)\n" /* scanptr */
        "jmp .Lf20bf8b_0020c357\n"
        ".Lf20bf8b_0020c354:\n"
        "movl -0x1c(%ebp), %edi\n" /* scanptr */
        ".Lf20bf8b_0020c357:\n"
        "leal (%ecx, %edi), %eax\n" /* line 297 */
        "movl %eax, 0xec(%edx)\n"
        "addl $1, %esi\n" /* line 296 */
        "addl $0x54, %ecx\n"
        "addl $4, %edx\n"
        "cmpl -0x2c(%ebp), %esi\n"
        "jl .Lf20bf8b_0020c354\n"
        ".Lf20bf8b_0020c36e:\n"
        "movl 8(%ebp), %eax\n" /* line 299 | cinfo */
        "movl $0, 0x130(%eax)\n"
        "movl $0x3f, 0x134(%eax)\n" /* line 300 */
        "movl $0, 0x138(%eax)\n" /* line 301 */
        "movl $0, 0x13c(%eax)\n" /* line 302 */
        "jmp .Lf20bf8b_0020c04f\n"
        /* } scope */
        /* { scope 2 */
        ".Lf20bf8b_0020c39e:\n"
        "cmpl $4, 0x40(%ecx)\n" /* line 292 */
        "jg .Lf20bf8b_0020c481\n"
        "movl %ecx, %eax\n"
        "movl %ecx, %edx\n"
        ".Lf20bf8b_0020c3ac:\n"
        "movl 0x40(%eax), %eax\n" /* line 295 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl %eax, 0xe8(%edx)\n"
        "movl 0x40(%edx), %eax\n" /* line 296 */
        "testl %eax, %eax\n"
        "jle .Lf20bf8b_0020c3e8\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "xorl %esi, %esi\n"
        "xorl %ecx, %ecx\n"
        "movl 0x48(%edx), %edi\n" /* scanptr */
        "movl %edi, -0x1c(%ebp)\n" /* scanptr */
        "jmp .Lf20bf8b_0020c3d1\n"
        ".Lf20bf8b_0020c3ce:\n"
        "movl -0x1c(%ebp), %edi\n" /* scanptr */
        ".Lf20bf8b_0020c3d1:\n"
        "leal (%ecx, %edi), %eax\n" /* line 297 */
        "movl %eax, 0xec(%edx)\n"
        "addl $1, %esi\n" /* line 296 */
        "addl $0x54, %ecx\n"
        "addl $4, %edx\n"
        "cmpl -0x2c(%ebp), %esi\n"
        "jl .Lf20bf8b_0020c3ce\n"
        ".Lf20bf8b_0020c3e8:\n"
        "movl 8(%ebp), %eax\n" /* line 299 | cinfo */
        "movl $0, 0x130(%eax)\n"
        "movl $0x3f, 0x134(%eax)\n" /* line 300 */
        "movl $0, 0x138(%eax)\n" /* line 301 */
        "movl $0, 0x13c(%eax)\n" /* line 302 */
        "jmp .Lf20bf8b_0020c12b\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf20bf8b_0020c418:\n"
        "movl %edi, %esi\n" /* line 279 | scanptr */
        "movl 8(%ebp), %ecx\n" /* cinfo */
        "movl $0, -0xc(%ebp)\n" /* ci */
        "movl 0x48(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        ".Lf20bf8b_0020c42a:\n"
        "movl 4(%esi), %eax\n" /* line 280 */
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 4), %edx\n"
        "movl -0x1c(%ebp), %eax\n"
        "leal (%eax, %edx, 4), %edx\n"
        "movl %edx, 0xec(%ecx)\n"
        "addl $1, -0xc(%ebp)\n" /* line 279 | ci */
        "addl $4, %esi\n"
        "addl $4, %ecx\n"
        "movl -0xc(%ebp), %edx\n" /* ci */
        "cmpl (%edi), %edx\n" /* scanptr */
        "jl .Lf20bf8b_0020c42a\n"
        "jmp .Lf20bf8b_0020c1ac\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf20bf8b_0020c455:\n"
        "movl (%ecx), %eax\n" /* line 293 */
        "movl $0x1a, 0x14(%eax)\n"
        "movl (%ecx), %edx\n"
        "movl 0x40(%ecx), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl (%ecx), %eax\n"
        "movl $4, 0x1c(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "jmp .Lf20bf8b_0020c332\n"
        /* } scope */
        /* { scope 2 */
        ".Lf20bf8b_0020c481:\n"
        "movl (%ecx), %eax\n"
        "movl $0x1a, 0x14(%eax)\n"
        "movl (%ecx), %edx\n"
        "movl 0x40(%ecx), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl (%ecx), %eax\n"
        "movl $4, 0x1c(%eax)\n"
        "movl (%ecx), %eax\n"
        "movl %ecx, (%esp)\n"
        "calll *(%eax)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "jmp .Lf20bf8b_0020c3ac\n"
        /* } scope */
        ".Lf20bf8b_0020c4ad:\n"
        "movl 8(%ebp), %edx\n" /* line 460 | cinfo */
        "movl 0x150(%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        "jmp .Lf20bf8b_0020c215\n"
        /* { scope 2 */
        ".Lf20bf8b_0020c4c1:\n"
        "movl 8(%ebp), %edi\n" /* line 292 | cinfo, scanptr */
        "cmpl $4, 0x40(%edi)\n" /* scanptr */
        "jg .Lf20bf8b_0020c53a\n"
        "movl %edi, %eax\n" /* scanptr */
        "movl %edi, %edx\n" /* scanptr */
        ".Lf20bf8b_0020c4ce:\n"
        "movl 0x40(%eax), %eax\n" /* line 295 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl %eax, 0xe8(%edx)\n"
        "movl 0x40(%edx), %esi\n" /* line 296 */
        "testl %esi, %esi\n"
        "jle .Lf20bf8b_0020c50a\n"
        "movl 8(%ebp), %edx\n" /* cinfo */
        "xorl %esi, %esi\n"
        "xorl %ecx, %ecx\n"
        "movl 0x48(%edx), %edi\n" /* scanptr */
        "movl %edi, -0x1c(%ebp)\n" /* scanptr */
        "jmp .Lf20bf8b_0020c4f3\n"
        ".Lf20bf8b_0020c4f0:\n"
        "movl -0x1c(%ebp), %edi\n" /* scanptr */
        ".Lf20bf8b_0020c4f3:\n"
        "leal (%ecx, %edi), %eax\n" /* line 297 */
        "movl %eax, 0xec(%edx)\n"
        "addl $1, %esi\n" /* line 296 */
        "addl $0x54, %ecx\n"
        "addl $4, %edx\n"
        "cmpl -0x2c(%ebp), %esi\n"
        "jl .Lf20bf8b_0020c4f0\n"
        ".Lf20bf8b_0020c50a:\n"
        "movl 8(%ebp), %eax\n" /* line 299 | cinfo */
        "movl $0, 0x130(%eax)\n"
        "movl $0x3f, 0x134(%eax)\n" /* line 300 */
        "movl $0, 0x138(%eax)\n" /* line 301 */
        "movl $0, 0x13c(%eax)\n" /* line 302 */
        "jmp .Lf20bf8b_0020c1d3\n"
        ".Lf20bf8b_0020c53a:\n"
        "movl (%edi), %eax\n" /* line 293 | scanptr */
        "movl $0x1a, 0x14(%eax)\n"
        "movl (%edi), %edx\n" /* scanptr */
        "movl 0x40(%edi), %eax\n" /* scanptr */
        "movl %eax, 0x18(%edx)\n"
        "movl (%edi), %eax\n" /* scanptr */
        "movl $4, 0x1c(%eax)\n"
        "movl (%edi), %eax\n" /* scanptr */
        "movl %edi, (%esp)\n" /* scanptr */
        "calll *(%eax)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "jmp .Lf20bf8b_0020c4ce\n"
    );
}

