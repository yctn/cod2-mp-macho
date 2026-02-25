/* ASM dump from: jcparam.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/jpeg-6/jcparam.c */

#include "common_types.h"
#include "imports.h"

static const unsigned int std_luminance_quant_tbl[64]; /* 0x306c00 */
static const unsigned int std_chrominance_quant_tbl[64]; /* 0x306b00 */

void jpeg_add_quant_table(j_compress_ptr cinfo, int which_tbl, const unsigned int *basic_table, int scale_factor, int force_baseline, j_compress_ptr cinfo_5, int scale_factor_6, int force_baseline_7);
void jpeg_set_colorspace(j_compress_ptr cinfo, J_COLOR_SPACE colorspace);
void jpeg_default_colorspace(j_compress_ptr cinfo);
void jpeg_set_quality(j_compress_ptr cinfo, int quality, int force_baseline);
void jpeg_set_defaults(j_compress_ptr cinfo);

/* line 31 */
__attribute__((naked))
void jpeg_add_quant_table(j_compress_ptr cinfo, int which_tbl, const unsigned int *basic_table, int scale_factor, int force_baseline, j_compress_ptr cinfo_5, int scale_factor_6, int force_baseline_7)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 31 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %edi\n" /* cinfo */
        "movl 0xc(%ebp), %esi\n" /* which_tbl */
        "movzbl 0x18(%ebp), %eax\n" /* force_baseline */
        "movb %al, -9(%ebp)\n" /* force_baseline */
        "cmpl $0x64, 0x14(%edi)\n" /* line 37 | cinfo */
        "je .Lf1f8254_001f8287\n"
        "movl (%edi), %eax\n" /* line 38 | cinfo */
        "movl $0x14, 0x14(%eax)\n"
        "movl (%edi), %edx\n" /* cinfo */
        "movl 0x14(%edi), %eax\n" /* cinfo */
        "movl %eax, 0x18(%edx)\n"
        "movl (%edi), %eax\n" /* cinfo */
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        ".Lf1f8254_001f8287:\n"
        "cmpl $3, %esi\n" /* line 40 | qtblptr */
        "ja 0x1f8310\n"
        "leal 0x4c(%edi, %esi, 4), %esi\n" /* line 43 | cinfo, qtblptr */
        "movl (%esi), %eax\n" /* line 45 | qtblptr */
        "testl %eax, %eax\n"
        "je 0x1f832a\n"
        "cmpb $0, -9(%ebp)\n" /* line 46 | force_baseline */
        "jne 0x1f8339\n"
        "xorl %ecx, %ecx\n" /* line 60 */
        "movl $0x51eb851f, %edi\n" /* cinfo */
        "jmp 0x1f82cc\n"
        "cmpl $0x7fff, %edx\n" /* line 52 */
        "jle 0x1f82be\n"
    );
}

/* line 392 */
__attribute__((naked))
void jpeg_set_colorspace(j_compress_ptr cinfo, J_COLOR_SPACE colorspace)
{
    __asm__ __volatile__ (
        /* { scope 1 */
        "pushl %ebp\n" /* line 392 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl 0xc(%ebp), %edi\n" /* colorspace */
        "cmpl $0x64, 0x14(%esi)\n" /* line 406 | cinfo */
        "je .Lf1f8390_001f83c2\n"
        "movl (%esi), %eax\n" /* line 407 | cinfo */
        "movl $0x14, 0x14(%eax)\n"
        "movl (%esi), %edx\n" /* cinfo */
        "movl 0x14(%esi), %eax\n" /* cinfo */
        "movl %eax, 0x18(%edx)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        ".Lf1f8390_001f83c2:\n"
        "movl %edi, 0x44(%esi)\n" /* line 413 | colorspace, cinfo */
        "movb $0, 0xc8(%esi)\n" /* line 415 | cinfo */
        "movb $0, 0xd0(%esi)\n" /* line 416 | cinfo */
        "cmpl $5, %edi\n" /* line 418 | colorspace */
        "ja .Lf1f8390_001f83fc\n"
        "movl 0x46(%ebx, %edi, 4), %eax\n"
        "addl %ebx, %eax\n"
        "jmpl *%eax\n"
        "nop\n"
        "ja .Lf1f8390_001f83e6\n"
        ".Lf1f8390_001f83e6:\n"
        "addb %al, (%eax)\n"
        "movb $3, %ch\n"
        "addb %al, (%eax)\n"
        "xorl (%ebx), %eax\n"
        "addb %al, (%eax)\n"
        "movw (%edx), %es\n"
        "addb %al, (%eax)\n"
        "movb $1, %al\n"
        "addb %al, (%eax)\n"
        "rolb %cl, (%eax)\n"
        "addb %al, (%eax)\n"
        ".Lf1f8390_001f83fc:\n"
        "movl (%esi), %eax\n" /* line 467 | cinfo */
        "movl $0xa, 0x14(%eax)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl %esi, 8(%ebp)\n" /* cinfo */
        "movl (%eax), %ecx\n"
        "addl $0x1c, %esp\n" /* line 469 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmpl *%ecx\n" /* line 467 */
        "movl 0x2c(%esi), %eax\n" /* line 458 | cinfo */
        "movl %eax, 0x40(%esi)\n" /* cinfo */
        "subl $1, %eax\n" /* line 459 */
        "cmpl $9, %eax\n"
        "ja .Lf1f8390_001f876f\n"
        ".Lf1f8390_001f8427:\n"
        "movl 0x40(%esi), %edx\n" /* line 462 | cinfo */
        "testl %edx, %edx\n"
        "jle .Lf1f8390_001f8546\n"
        "xorl %edx, %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf1f8390_001f8436:\n"
        "movl %ecx, %eax\n" /* line 463 */
        "addl 0x48(%esi), %eax\n" /* cinfo */
        "movl %edx, (%eax)\n"
        "movl $1, 8(%eax)\n"
        "movl $1, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n"
        "movl $0, 0x14(%eax)\n"
        "movl $0, 0x18(%eax)\n"
        "addl $1, %edx\n" /* line 462 */
        "addl $0x54, %ecx\n"
        "cmpl %edx, 0x40(%esi)\n" /* cinfo */
        "jg .Lf1f8390_001f8436\n"
        "jmp .Lf1f8390_001f8546\n"
        "movb $1, 0xd0(%esi)\n" /* line 450 | cinfo */
        "movl $4, 0x40(%esi)\n" /* line 451 | cinfo */
        "movl 0x48(%esi), %eax\n" /* line 452 | cinfo */
        "movl $1, (%eax)\n"
        "movl $2, 8(%eax)\n"
        "movl $2, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n"
        "movl $0, 0x14(%eax)\n"
        "movl $0, 0x18(%eax)\n"
        "movl 0x48(%esi), %edx\n" /* line 453 | cinfo */
        "leal 0x54(%edx), %eax\n"
        "movl $2, 0x54(%edx)\n"
        "movl $1, 8(%eax)\n"
        "movl $1, 0xc(%eax)\n"
        "movl $1, 0x10(%eax)\n"
        "movl $1, 0x14(%eax)\n"
        "movl $1, 0x18(%eax)\n"
        "movl 0x48(%esi), %edx\n" /* line 454 | cinfo */
        "leal 0xa8(%edx), %eax\n"
        "movl $3, 0xa8(%edx)\n"
        "movl $1, 8(%eax)\n"
        "movl $1, 0xc(%eax)\n"
        "movl $1, 0x10(%eax)\n"
        "movl $1, 0x14(%eax)\n"
        "movl $1, 0x18(%eax)\n"
        "movl 0x48(%esi), %edx\n" /* line 455 | cinfo */
        "leal 0xfc(%edx), %eax\n"
        "movl $4, 0xfc(%edx)\n"
        "movl $2, 8(%eax)\n"
        "movl $2, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n"
        "movl $0, 0x14(%eax)\n"
        "movl $0, 0x18(%eax)\n"
        ".Lf1f8390_001f8546:\n"
        "addl $0x1c, %esp\n" /* line 469 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movb $1, 0xd0(%esi)\n" /* line 442 | cinfo */
        "movl $4, 0x40(%esi)\n" /* line 443 | cinfo */
        "movl 0x48(%esi), %eax\n" /* line 444 | cinfo */
        "movl $0x43, (%eax)\n"
        "movl $1, 8(%eax)\n"
        "movl $1, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n"
        "movl $0, 0x14(%eax)\n"
        "movl $0, 0x18(%eax)\n"
        "movl 0x48(%esi), %edx\n" /* line 445 | cinfo */
        "leal 0x54(%edx), %eax\n"
        "movl $0x4d, 0x54(%edx)\n"
        "movl $1, 8(%eax)\n"
        "movl $1, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n"
        "movl $0, 0x14(%eax)\n"
        "movl $0, 0x18(%eax)\n"
        "movl 0x48(%esi), %edx\n" /* line 446 | cinfo */
        "leal 0xa8(%edx), %eax\n"
        "movl $0x59, 0xa8(%edx)\n"
        "movl $1, 8(%eax)\n"
        "movl $1, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n"
        "movl $0, 0x14(%eax)\n"
        "movl $0, 0x18(%eax)\n"
        "movl 0x48(%esi), %edx\n" /* line 447 | cinfo */
        "leal 0xfc(%edx), %eax\n"
        "movl $0x4b, 0xfc(%edx)\n"
        ".Lf1f8390_001f8601:\n"
        "movl $1, 8(%eax)\n" /* line 430 */
        "movl $1, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n"
        "movl $0, 0x14(%eax)\n"
        "movl $0, 0x18(%eax)\n"
        "addl $0x1c, %esp\n" /* line 469 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movb $1, 0xc8(%esi)\n" /* line 433 | cinfo */
        "movl $3, 0x40(%esi)\n" /* line 434 | cinfo */
        "movl 0x48(%esi), %eax\n" /* line 437 | cinfo */
        "movl $1, (%eax)\n"
        "movl $2, 8(%eax)\n"
        "movl $2, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n"
        "movl $0, 0x14(%eax)\n"
        "movl $0, 0x18(%eax)\n"
        "movl 0x48(%esi), %edx\n" /* line 438 | cinfo */
        "leal 0x54(%edx), %eax\n"
        "movl $2, 0x54(%edx)\n"
        "movl $1, 8(%eax)\n"
        "movl $1, 0xc(%eax)\n"
        "movl $1, 0x10(%eax)\n"
        "movl $1, 0x14(%eax)\n"
        "movl $1, 0x18(%eax)\n"
        "movl 0x48(%esi), %edx\n" /* line 439 | cinfo */
        "leal 0xa8(%edx), %eax\n"
        "movl $3, 0xa8(%edx)\n"
        "movl $1, 8(%eax)\n"
        "movl $1, 0xc(%eax)\n"
        "movl $1, 0x10(%eax)\n"
        "movl $1, 0x14(%eax)\n"
        "movl $1, 0x18(%eax)\n"
        "jmp .Lf1f8390_001f8546\n"
        "movb $1, 0xd0(%esi)\n" /* line 426 | cinfo */
        "movl $3, 0x40(%esi)\n" /* line 427 | cinfo */
        "movl 0x48(%esi), %eax\n" /* line 428 | cinfo */
        "movl $0x52, (%eax)\n"
        "movl $1, 8(%eax)\n"
        "movl $1, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n"
        "movl $0, 0x14(%eax)\n"
        "movl $0, 0x18(%eax)\n"
        "movl 0x48(%esi), %edx\n" /* line 429 | cinfo */
        "leal 0x54(%edx), %eax\n"
        "movl $0x47, 0x54(%edx)\n"
        "movl $1, 8(%eax)\n"
        "movl $1, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n"
        "movl $0, 0x14(%eax)\n"
        "movl $0, 0x18(%eax)\n"
        "movl 0x48(%esi), %edx\n" /* line 430 | cinfo */
        "leal 0xa8(%edx), %eax\n"
        "movl $0x42, 0xa8(%edx)\n"
        "jmp .Lf1f8390_001f8601\n"
        "movb $1, 0xc8(%esi)\n" /* line 420 | cinfo */
        "movl $1, 0x40(%esi)\n" /* line 421 | cinfo */
        "movl 0x48(%esi), %eax\n" /* line 423 | cinfo */
        "movl $1, (%eax)\n"
        "jmp .Lf1f8390_001f8601\n"
        ".Lf1f8390_001f876f:\n"
        "movl (%esi), %eax\n" /* line 460 | cinfo */
        "movl $0x1a, 0x14(%eax)\n"
        "movl (%esi), %edx\n" /* cinfo */
        "movl 0x40(%esi), %eax\n" /* cinfo */
        "movl %eax, 0x18(%edx)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl $0xa, 0x1c(%eax)\n"
        "movl (%esi), %eax\n" /* cinfo */
        "movl %esi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "jmp .Lf1f8390_001f8427\n"
    );
}

/* line 360 */
__attribute__((naked))
void jpeg_default_colorspace(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 360 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %edx\n" /* cinfo */
        "cmpl $5, 0x30(%edx)\n" /* line 361 */
        "ja .Lf1f8795_001f87d0\n"
        "movl 0x30(%edx), %eax\n"
        "movl 0x17(%ebx, %eax, 4), %eax\n"
        "addl %ebx, %eax\n"
        "jmpl *%eax\n"
        "popl %esp\n"
        "addb %al, (%eax)\n"
        "addb %ch, (%esi)\n"
        "addb %al, (%eax)\n"
        "incl %esi\n"
        "addb %al, (%eax)\n"
        "addb %al, (%esi)\n"
        "addb %al, (%eax)\n"
        "xchgl %eax, %edx\n"
        "addb %al, (%eax)\n"
        "addb %al, -0x75000000(%eax)\n"
        ".Lf1f8795_001f87d0:\n"
        "addb %bh, %al\n" /* line 381 */
        "incl %eax\n"
        "adcb $9, %al\n"
        "addb %al, (%eax)\n"
        "addb %cl, 0x8558902(%ebx)\n"
        "movl (%eax), %ecx\n"
        "addl $0x14, %esp\n" /* line 383 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmpl *%ecx\n" /* line 381 */
        "movl $3, 4(%esp)\n" /* line 369 */
        "movl %edx, (%esp)\n"
        "calll jpeg_set_colorspace\n"
        ".Lf1f8795_001f87f7:\n"
        "addl $0x14, %esp\n" /* line 383 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        "movl $0, 4(%esp)\n" /* line 378 */
        "movl %edx, (%esp)\n"
        "calll jpeg_set_colorspace\n"
        "jmp .Lf1f8795_001f87f7\n"
        "movl $1, 4(%esp)\n" /* line 363 */
        "movl %edx, (%esp)\n"
        "calll jpeg_set_colorspace\n"
        "jmp .Lf1f8795_001f87f7\n"
        "movl $5, 4(%esp)\n" /* line 375 */
        "movl %edx, (%esp)\n"
        "calll jpeg_set_colorspace\n"
        "jmp .Lf1f8795_001f87f7\n"
        "movl $4, 4(%esp)\n" /* line 372 */
        "movl %edx, (%esp)\n"
        "calll jpeg_set_colorspace\n"
        "jmp .Lf1f8795_001f87f7\n"
    );
}

/* line 138 */
__attribute__((naked))
void jpeg_set_quality(j_compress_ptr cinfo, int quality, int force_baseline)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 138 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 0xc(%ebp), %edx\n" /* quality */
        "movzbl 0x10(%ebp), %ecx\n" /* force_baseline */
        "testl %edx, %edx\n" /* line 113 */
        "jle .Lf1f8848_001f88d1\n"
        "cmpl $0x64, %edx\n" /* line 114 */
        "jg .Lf1f8848_001f88ca\n"
        "cmpl $0x31, %edx\n" /* line 122 */
        "jle .Lf1f8848_001f88d8\n"
        "leal (%edx, %edx), %eax\n"
        ".Lf1f8848_001f886e:\n"
        "movl $0xc8, %edi\n" /* line 125 */
        "subl %eax, %edi\n"
        ".Lf1f8848_001f8875:\n"
        "movzbl %cl, %esi\n" /* line 98 */
        "movl %esi, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n"
        "leal 0x10e3aa(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* cinfo */
        "movl %eax, (%esp)\n"
        "calll jpeg_add_quant_table\n"
        "movl %esi, 0x10(%esp)\n" /* line 100 */
        "movl %edi, 0xc(%esp)\n"
        "leal 0x10e2aa(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl 8(%ebp), %esi\n" /* cinfo */
        "movl %esi, (%esp)\n"
        "calll jpeg_add_quant_table\n"
        "addl $0x2c, %esp\n" /* line 144 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1f8848_001f88ca:\n"
        "movl $0xc8, %eax\n" /* line 122 */
        "jmp .Lf1f8848_001f886e\n"
        ".Lf1f8848_001f88d1:\n"
        "movl $0x1388, %edi\n" /* line 113 */
        "jmp .Lf1f8848_001f8875\n"
        ".Lf1f8848_001f88d8:\n"
        "movl $0x1388, %edi\n" /* line 122 */
        "movl %edi, %eax\n"
        "movl %edx, %esi\n"
        "cltd\n"
        "idivl %esi\n"
        "movl %eax, %edi\n"
        "jmp .Lf1f8848_001f8875\n"
    );
}

/* line 269 */
__attribute__((naked))
void jpeg_set_defaults(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 269 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "nop\n" /* PIC thunk - removed */
        "movl 8(%ebp), %edi\n" /* cinfo */
        "cmpl $0x64, 0x14(%edi)\n" /* line 273 | cinfo */
        "je .Lf1f88e8_001f8917\n"
        "movl (%edi), %eax\n" /* line 274 | cinfo */
        "movl $0x14, 0x14(%eax)\n"
        "movl (%edi), %edx\n" /* cinfo */
        "movl 0x14(%edi), %eax\n" /* cinfo */
        "movl %eax, 0x18(%edx)\n"
        "movl (%edi), %eax\n" /* cinfo */
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        ".Lf1f88e8_001f8917:\n"
        "movl 0x48(%edi), %eax\n" /* line 280 | cinfo */
        "testl %eax, %eax\n"
        "je .Lf1f88e8_001f8d1f\n"
        ".Lf1f88e8_001f8922:\n"
        "movl $8, 0x3c(%edi)\n" /* line 287 | cinfo */
        "movl $1, 0x10(%esp)\n" /* line 98 */
        "movl $0x32, 0xc(%esp)\n"
        "leal 0x10e30a(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll jpeg_add_quant_table\n"
        "movl $1, 0x10(%esp)\n" /* line 100 */
        "movl $0x32, 0xc(%esp)\n"
        "leal 0x10e20a(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll jpeg_add_quant_table\n"
        "leal 0x5c(%edi), %eax\n" /* line 246 */
        "movl %eax, -0x28(%ebp)\n" /* htblptr */
        /* { scope 1 */
        /* { scope 2 */
        "movl 0x5c(%edi), %eax\n" /* line 158 */
        "testl %eax, %eax\n"
        "je .Lf1f88e8_001f8d3f\n"
        "movl 0x5c(%edi), %edx\n"
        ".Lf1f88e8_001f8991:\n"
        "movl 0x10e5a6(%ebx), %eax\n" /* line 162 */
        "movl %eax, (%edx)\n"
        "movl 0x10e5aa(%ebx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl 0x10e5ae(%ebx), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl 0x10e5b2(%ebx), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "movzbl 0x10e5b6(%ebx), %eax\n"
        "movb %al, 0x10(%edx)\n"
        "xorl %esi, %esi\n" /* nsymbols */
        "leal 0x10e5a6(%ebx), %edx\n"
        "leal 0x10(%edx), %ecx\n"
        ".Lf1f88e8_001f89c9:\n"
        "movzbl 1(%edx), %eax\n" /* line 170 */
        "addl %eax, %esi\n" /* nsymbols */
        "addl $1, %edx\n"
        "cmpl %ecx, %edx\n" /* line 169 */
        "jne .Lf1f88e8_001f89c9\n"
        "leal -1(%esi), %eax\n" /* line 171 | nsymbols */
        "cmpl $0xff, %eax\n"
        "ja .Lf1f88e8_001f8c8d\n"
        ".Lf1f88e8_001f89e4:\n"
        "movl -0x28(%ebp), %edx\n" /* line 174 | htblptr */
        "movl (%edx), %eax\n"
        "addl $0x11, %eax\n"
        "movl %esi, 8(%esp)\n" /* nsymbols */
        "leal 0x10e59a(%ebx), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl -0x28(%ebp), %edx\n" /* line 177 | htblptr */
        "movl (%edx), %eax\n"
        "movb $0, 0x111(%eax)\n"
        /* } scope */
        /* } scope */
        "leal 0x6c(%edi), %eax\n" /* line 248 */
        "movl %eax, -0x24(%ebp)\n" /* htblptr */
        /* { scope 1 */
        /* { scope 2 */
        "movl 0x6c(%edi), %eax\n" /* line 158 */
        "testl %eax, %eax\n"
        "je .Lf1f88e8_001f8ce1\n"
        "movl 0x6c(%edi), %edx\n"
        ".Lf1f88e8_001f8a22:\n"
        "movl 0x10e56c(%ebx), %eax\n" /* line 162 */
        "movl %eax, (%edx)\n"
        "movl 0x10e570(%ebx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl 0x10e574(%ebx), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl 0x10e578(%ebx), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "movzbl 0x10e57c(%ebx), %eax\n"
        "movb %al, 0x10(%edx)\n"
        "xorl %esi, %esi\n" /* nsymbols */
        "leal 0x10e56c(%ebx), %edx\n"
        "leal 0x10(%edx), %ecx\n"
        ".Lf1f88e8_001f8a5a:\n"
        "movzbl 1(%edx), %eax\n" /* line 170 */
        "addl %eax, %esi\n" /* nsymbols */
        "addl $1, %edx\n"
        "cmpl %ecx, %edx\n" /* line 169 */
        "jne .Lf1f88e8_001f8a5a\n"
        "leal -1(%esi), %eax\n" /* line 171 | nsymbols */
        "cmpl $0xff, %eax\n"
        "ja .Lf1f88e8_001f8ccc\n"
        ".Lf1f88e8_001f8a75:\n"
        "movl -0x24(%ebp), %edx\n" /* line 174 | htblptr */
        "movl (%edx), %eax\n"
        "addl $0x11, %eax\n"
        "movl %esi, 8(%esp)\n" /* nsymbols */
        "leal 0x10e4ca(%ebx), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl -0x24(%ebp), %edx\n" /* line 177 | htblptr */
        "movl (%edx), %eax\n"
        "movb $0, 0x111(%eax)\n"
        /* } scope */
        /* } scope */
        "movl -0x28(%ebp), %eax\n" /* line 250 | htblptr */
        "addl $4, %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* htblptr */
        /* { scope 1 */
        /* { scope 2 */
        "movl -0x28(%ebp), %edx\n" /* line 158 | htblptr */
        "movl 4(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1f88e8_001f8cf3\n"
        "movl %edx, %eax\n"
        ".Lf1f88e8_001f8ab8:\n"
        "movl 4(%eax), %edx\n" /* line 162 */
        "movl 0x10e589(%ebx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl 0x10e58d(%ebx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl 0x10e591(%ebx), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl 0x10e595(%ebx), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "movzbl 0x10e599(%ebx), %eax\n"
        "movb %al, 0x10(%edx)\n"
        "xorl %esi, %esi\n" /* nsymbols */
        "leal 0x10e589(%ebx), %edx\n"
        "leal 0x10(%edx), %ecx\n"
        ".Lf1f88e8_001f8af3:\n"
        "movzbl 1(%edx), %eax\n" /* line 170 */
        "addl %eax, %esi\n" /* nsymbols */
        "addl $1, %edx\n"
        "cmpl %ecx, %edx\n" /* line 169 */
        "jne .Lf1f88e8_001f8af3\n"
        "leal -1(%esi), %eax\n" /* line 171 | nsymbols */
        "cmpl $0xff, %eax\n"
        "ja .Lf1f88e8_001f8cb7\n"
        ".Lf1f88e8_001f8b0e:\n"
        "movl -0x20(%ebp), %edx\n" /* line 174 | htblptr */
        "movl (%edx), %eax\n"
        "addl $0x11, %eax\n"
        "movl %esi, 8(%esp)\n" /* nsymbols */
        "leal 0x10e57d(%ebx), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl -0x20(%ebp), %edx\n" /* line 177 | htblptr */
        "movl (%edx), %eax\n"
        "movb $0, 0x111(%eax)\n"
        /* } scope */
        /* } scope */
        "movl -0x24(%ebp), %eax\n" /* line 252 | htblptr */
        "addl $4, %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* htblptr */
        /* { scope 1 */
        /* { scope 2 */
        "movl -0x24(%ebp), %edx\n" /* line 158 | htblptr */
        "movl 4(%edx), %esi\n" /* nsymbols */
        "testl %esi, %esi\n" /* nsymbols */
        "je .Lf1f88e8_001f8d09\n"
        "movl %edx, %eax\n"
        ".Lf1f88e8_001f8b51:\n"
        "movl 4(%eax), %edx\n" /* line 162 */
        "movl 0x10e4ac(%ebx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl 0x10e4b0(%ebx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl 0x10e4b4(%ebx), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl 0x10e4b8(%ebx), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "movzbl 0x10e4bc(%ebx), %eax\n"
        "movb %al, 0x10(%edx)\n"
        "xorl %esi, %esi\n" /* nsymbols */
        "leal 0x10e4ac(%ebx), %edx\n"
        "leal 0x10(%edx), %ecx\n"
        ".Lf1f88e8_001f8b8c:\n"
        "movzbl 1(%edx), %eax\n" /* line 170 */
        "addl %eax, %esi\n" /* nsymbols */
        "addl $1, %edx\n"
        "cmpl %ecx, %edx\n" /* line 169 */
        "jne .Lf1f88e8_001f8b8c\n"
        "leal -1(%esi), %eax\n" /* line 171 | nsymbols */
        "cmpl $0xff, %eax\n"
        "ja .Lf1f88e8_001f8ca2\n"
        ".Lf1f88e8_001f8ba7:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 174 | htblptr */
        "movl (%edx), %eax\n"
        "addl $0x11, %eax\n"
        "movl %esi, 8(%esp)\n" /* nsymbols */
        "leal 0x10e40a(%ebx), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl -0x1c(%ebp), %edx\n" /* line 177 | htblptr */
        "movl (%edx), %eax\n"
        "movb $0, 0x111(%eax)\n"
        "movl %edi, %eax\n"
        "movl $0x10, %edx\n"
        /* } scope */
        /* } scope */
        ".Lf1f88e8_001f8bd8:\n"
        "movb $0, 0x7c(%eax)\n" /* line 295 */
        "movb $1, 0x8c(%eax)\n" /* line 296 */
        "movb $5, 0x9c(%eax)\n" /* line 297 */
        "addl $1, %eax\n"
        "subl $1, %edx\n" /* line 294 */
        "jne .Lf1f88e8_001f8bd8\n"
        "movl $0, 0xb0(%edi)\n" /* line 301 | cinfo */
        "movl $0, 0xac(%edi)\n" /* line 302 | cinfo */
        "movb $0, 0xb4(%edi)\n" /* line 305 | cinfo */
        "movb $0, 0xb5(%edi)\n" /* line 308 | cinfo */
        "movb $0, 0xb6(%edi)\n" /* line 311 | cinfo */
        "cmpl $8, 0x3c(%edi)\n" /* line 317 | cinfo */
        "jle .Lf1f88e8_001f8c28\n"
        "movb $1, 0xb6(%edi)\n" /* line 318 | cinfo */
        ".Lf1f88e8_001f8c28:\n"
        "movb $0, 0xb7(%edi)\n" /* line 321 | cinfo */
        "movl $0, 0xb8(%edi)\n" /* line 324 | cinfo */
        "movl $0, 0xbc(%edi)\n" /* line 327 | cinfo */
        "movl $0, 0xc0(%edi)\n" /* line 330 | cinfo */
        "movl $0, 0xc4(%edi)\n" /* line 331 | cinfo */
        "movb $1, 0xc9(%edi)\n" /* line 342 | cinfo */
        "movb $1, 0xca(%edi)\n" /* line 343 | cinfo */
        "movb $0, 0xcb(%edi)\n" /* line 344 | cinfo */
        "movw $1, 0xcc(%edi)\n" /* line 345 | cinfo */
        "movw $1, 0xce(%edi)\n" /* line 346 | cinfo */
        "movl %edi, 8(%ebp)\n" /* line 350 | cinfo */
        "addl $0x3c, %esp\n" /* line 351 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp jpeg_default_colorspace\n" /* line 350 */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1f88e8_001f8c8d:\n"
        "movl (%edi), %eax\n" /* line 172 */
        "movl $8, 0x14(%eax)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1f88e8_001f89e4\n"
        /* } scope */
        /* } scope */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1f88e8_001f8ca2:\n"
        "movl (%edi), %eax\n"
        "movl $8, 0x14(%eax)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1f88e8_001f8ba7\n"
        /* } scope */
        /* } scope */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1f88e8_001f8cb7:\n"
        "movl (%edi), %eax\n"
        "movl $8, 0x14(%eax)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1f88e8_001f8b0e\n"
        /* } scope */
        /* } scope */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1f88e8_001f8ccc:\n"
        "movl (%edi), %eax\n"
        "movl $8, 0x14(%eax)\n"
        "movl (%edi), %eax\n"
        "movl %edi, (%esp)\n"
        "calll *(%eax)\n"
        "jmp .Lf1f88e8_001f8a75\n"
        ".Lf1f88e8_001f8ce1:\n"
        "movl %edi, (%esp)\n" /* line 159 */
        "calll jpeg_alloc_huff_table\n"
        "movl %eax, 0x6c(%edi)\n"
        "movl %eax, %edx\n"
        "jmp .Lf1f88e8_001f8a22\n"
        /* } scope */
        /* } scope */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1f88e8_001f8cf3:\n"
        "movl %edi, (%esp)\n"
        "calll jpeg_alloc_huff_table\n"
        "movl -0x28(%ebp), %edx\n" /* htblptr */
        "movl %eax, 4(%edx)\n"
        "movl -0x28(%ebp), %eax\n" /* htblptr */
        "jmp .Lf1f88e8_001f8ab8\n"
        /* } scope */
        /* } scope */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1f88e8_001f8d09:\n"
        "movl %edi, (%esp)\n"
        "calll jpeg_alloc_huff_table\n"
        "movl -0x24(%ebp), %edx\n" /* htblptr */
        "movl %eax, 4(%edx)\n"
        "movl -0x24(%ebp), %eax\n" /* htblptr */
        "jmp .Lf1f88e8_001f8b51\n"
        /* } scope */
        /* } scope */
        ".Lf1f88e8_001f8d1f:\n"
        "movl 4(%edi), %eax\n" /* line 281 | cinfo */
        "movl $0x348, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* cinfo */
        "calll *(%eax)\n"
        "movl %eax, 0x48(%edi)\n" /* cinfo */
        "jmp .Lf1f88e8_001f8922\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1f88e8_001f8d3f:\n"
        "movl %edi, (%esp)\n" /* line 159 */
        "calll jpeg_alloc_huff_table\n"
        "movl %eax, 0x5c(%edi)\n"
        "movl %eax, %edx\n"
        "jmp .Lf1f88e8_001f8991\n"
    );
}

