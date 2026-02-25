/* ASM dump from: speex_callbacks.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/speex/speex_callbacks.c */

#include "common_types.h"
#include "imports.h"

int speex_inband_handler(SpeexBits *bits, SpeexCallback *callback_list, my_upsampler *state);
int speex_default_user_handler(SpeexBits *bits, my_upsampler *state, my_upsampler *data);

/* line 42 */
__attribute__((naked))
int speex_inband_handler(SpeexBits *bits, SpeexCallback *callback_list, my_upsampler *state)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 42 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* bits */
        "movl 0xc(%ebp), %ebx\n" /* callback_list */
        "movl 0x10(%ebp), %edi\n" /* state */
        /* { scope 1 */
        "movl $4, 4(%esp)\n" /* line 47 */
        "movl %esi, (%esp)\n" /* bits */
        "calll speex_bits_unpack_unsigned\n"
        "movl %eax, %edx\n"
        "leal (%eax, %eax, 4), %eax\n" /* line 48 */
        "leal (%ebx, %eax, 4), %eax\n" /* callback_list */
        "movl 4(%eax), %ecx\n" /* line 50 */
        "testl %ecx, %ecx\n"
        "je .Lf1f50a0_001f50e6\n"
        "movl 8(%eax), %eax\n" /* line 52 */
        "movl %eax, 0x10(%ebp)\n" /* state */
        "movl %edi, 0xc(%ebp)\n" /* state, callback_list */
        "movl %esi, 8(%ebp)\n" /* bits */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 72 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmpl *%ecx\n" /* line 52 */
        /* { scope 2 */
        ".Lf1f50a0_001f50e6:\n"
        "cmpl $1, %edx\n" /* line 57 */
        "jle .Lf1f50a0_001f5117\n"
        "cmpl $7, %edx\n" /* line 59 */
        "jle .Lf1f50a0_001f50fc\n"
        "cmpl $9, %edx\n" /* line 61 */
        "jg .Lf1f50a0_001f511e\n"
        "movl $8, %ecx\n"
        "jmp .Lf1f50a0_001f5101\n"
        ".Lf1f50a0_001f50fc:\n"
        "movl $4, %ecx\n" /* line 59 */
        ".Lf1f50a0_001f5101:\n"
        "movl %ecx, 4(%esp)\n" /* line 69 */
        "movl %esi, (%esp)\n" /* bits */
        "calll speex_bits_advance\n"
        /* } scope */
        /* } scope */
        "xorl %eax, %eax\n" /* line 72 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1f50a0_001f5117:\n"
        "movl $1, %ecx\n" /* line 57 */
        "jmp .Lf1f50a0_001f5101\n"
        ".Lf1f50a0_001f511e:\n"
        "cmpl $0xb, %edx\n" /* line 63 */
        "jle .Lf1f50a0_001f5135\n"
        "movl $0x20, %ecx\n" /* line 65 */
        "cmpl $0xd, %edx\n"
        "movl $0x40, %eax\n"
        "cmovgl %eax, %ecx\n"
        "jmp .Lf1f50a0_001f5101\n"
        ".Lf1f50a0_001f5135:\n"
        "movl $0x10, %ecx\n" /* line 63 */
        "jmp .Lf1f50a0_001f5101\n"
    );
}

/* line 135 */
__attribute__((naked))
int speex_default_user_handler(SpeexBits *bits, my_upsampler *state, my_upsampler *data)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 135 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* bits */
        "movl $4, 4(%esp)\n" /* line 137 */
        "movl %ebx, (%esp)\n" /* bits */
        "calll speex_bits_unpack_unsigned\n"
        "leal 5(, %eax, 8), %eax\n" /* line 138 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* bits */
        "calll speex_bits_advance\n"
        "xorl %eax, %eax\n" /* line 140 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

