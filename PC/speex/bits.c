/* ASM dump from: bits.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/speex/bits.c */

#include "common_types.h"
#include "imports.h"

void speex_bits_init(SpeexBits *bits);
void speex_bits_destroy(SpeexBits *bits);
void speex_bits_reset(SpeexBits *bits);
void speex_bits_read_from(SpeexBits *bits, char *chars, int len);
void speex_bits_pack(SpeexBits *bits, int data, int nbBits);
unsigned int speex_bits_unpack_unsigned(SpeexBits *bits, int nbBits);
int speex_bits_peek(SpeexBits *bits);
void speex_bits_advance(SpeexBits *bits, int n);
int speex_bits_remaining(SpeexBits *bits);
int speex_bits_write(SpeexBits *bits, char *chars, int max_nbytes);

/* line 45 */
__attribute__((naked))
void speex_bits_init(SpeexBits *bits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 45 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* bits */
        "movl $0x7d0, (%esp)\n" /* line 47 */
        "calll speex_alloc\n"
        "movl %eax, (%ebx)\n" /* bits */
        "movl $0x7d0, 0x18(%ebx)\n" /* line 48 | bits */
        "movb $0, (%eax)\n" /* line 50 */
        "movl $0, 4(%ebx)\n" /* line 51 | bits */
        "movl $0, 8(%ebx)\n" /* line 52 | bits */
        "movl $0, 0xc(%ebx)\n" /* line 53 | bits */
        "movl $1, 0x10(%ebx)\n" /* line 54 | bits */
        "movl $0, 0x14(%ebx)\n" /* line 55 | bits */
        "addl $0x14, %esp\n" /* line 56 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 71 */
__attribute__((naked))
void speex_bits_destroy(SpeexBits *bits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 71 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* bits */
        "movl 0x10(%eax), %edx\n" /* line 73 */
        "testl %edx, %edx\n"
        "jne .Lf1e883e_001e884d\n"
        "popl %ebp\n" /* line 76 */
        "retl\n"
        ".Lf1e883e_001e884d:\n"
        "movl (%eax), %eax\n" /* line 74 */
        "movl %eax, 8(%ebp)\n" /* bits */
        "popl %ebp\n" /* line 76 */
        "jmp speex_free\n" /* line 74 */
    );
}

/* line 78 */
__attribute__((naked))
void speex_bits_reset(SpeexBits *bits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 78 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* bits */
        "movl (%eax), %edx\n" /* line 80 */
        "movb $0, (%edx)\n"
        "movl $0, 4(%eax)\n" /* line 81 */
        "movl $0, 8(%eax)\n" /* line 82 */
        "movl $0, 0xc(%eax)\n" /* line 83 */
        "movl $0, 0x14(%eax)\n" /* line 84 */
        "popl %ebp\n" /* line 85 */
        "retl\n"
    );
}

/* line 94 */
__attribute__((naked))
void speex_bits_read_from(SpeexBits *bits, char *chars, int len)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 94 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* bits */
        "movl 0xc(%ebp), %edi\n" /* chars */
        "movl 0x10(%ebp), %ebx\n" /* len */
        /* { scope 1 */
        "cmpl %ebx, 0x18(%esi)\n" /* line 97 | len, bits */
        "jl .Lf1e8884_001e88d8\n"
        ".Lf1e8884_001e889b:\n"
        "testl %ebx, %ebx\n" /* line 116 | len */
        "jle .Lf1e8884_001e88b1\n"
        "xorl %ecx, %ecx\n"
        ".Lf1e8884_001e88a1:\n"
        "movl (%esi), %edx\n" /* line 117 | bits */
        "movzbl (%edi, %ecx), %eax\n" /* chars */
        "movb %al, (%edx, %ecx)\n"
        "addl $1, %ecx\n" /* line 116 */
        "cmpl %ecx, %ebx\n" /* len */
        "jne .Lf1e8884_001e88a1\n"
        ".Lf1e8884_001e88b1:\n"
        "leal (, %ebx, 8), %eax\n" /* line 118 */
        "movl %eax, 4(%esi)\n" /* bits */
        "movl $0, 8(%esi)\n" /* line 119 | bits */
        "movl $0, 0xc(%esi)\n" /* line 120 | bits */
        "movl $0, 0x14(%esi)\n" /* line 121 | bits */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 122 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e8884_001e88d8:\n"
        "movl %ebx, 4(%esp)\n" /* line 99 | len */
        "movl $0x2b8f6c, (%esp)\n" /* "Packet if larger than allocated buffer: " */
        "calll speex_warning_int\n"
        "movl 0x10(%esi), %ecx\n" /* line 100 | bits */
        "testl %ecx, %ecx\n"
        "je .Lf1e8884_001e8908\n"
        "movl %ebx, 4(%esp)\n" /* line 102 | len */
        "movl (%esi), %eax\n" /* bits */
        "movl %eax, (%esp)\n"
        "calll speex_realloc\n"
        "testl %eax, %eax\n" /* line 103 */
        "je .Lf1e8884_001e8919\n"
        "movl %ebx, 0x18(%esi)\n" /* line 105 | len, bits */
        "movl %eax, (%esi)\n" /* line 106 | bits */
        "jmp .Lf1e8884_001e889b\n"
        ".Lf1e8884_001e8908:\n"
        "movl $0x2b8fc8, (%esp)\n" /* line 112 */
        "calll speex_warning\n"
        "movl 0x18(%esi), %ebx\n" /* line 113 | bits, len */
        "jmp .Lf1e8884_001e889b\n"
        ".Lf1e8884_001e8919:\n"
        "movl 0x18(%esi), %ebx\n" /* line 108 | bits, len */
        "movl $0x2b8f98, (%esp)\n" /* line 109 */
        "calll speex_warning\n"
        "jmp .Lf1e8884_001e889b\n"
    );
}

/* line 216 */
__attribute__((naked))
void speex_bits_pack(SpeexBits *bits, int data, int nbBits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 216 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* bits */
        "movl 0xc(%ebp), %eax\n" /* data */
        "movl %eax, -0x1c(%ebp)\n" /* data */
        "movl 0x10(%ebp), %ecx\n" /* nbBits */
        "movl %ecx, -0x20(%ebp)\n" /* nbBits */
        "movl %ecx, %eax\n" /* line 220 */
        "addl 0xc(%ebx), %eax\n" /* bits */
        "sarl $3, %eax\n"
        "addl 8(%ebx), %eax\n" /* bits */
        "cmpl 0x18(%ebx), %eax\n" /* bits */
        "jge .Lf1e8930_001e89c8\n"
        ".Lf1e8930_001e8958:\n"
        "movl -0x20(%ebp), %eax\n" /* line 242 | nbBits */
        "testl %eax, %eax\n"
        "je .Lf1e8930_001e89c0\n"
        "movl -0x20(%ebp), %esi\n" /* line 237 | nbBits */
        "xorl %edi, %edi\n" /* new_nchars */
        "jmp .Lf1e8930_001e8972\n"
        ".Lf1e8930_001e8966:\n"
        "addl $1, 4(%ebx)\n" /* line 255 | bits */
        "addl $1, %edi\n" /* new_nchars */
        "cmpl %edi, -0x20(%ebp)\n" /* line 242 | new_nchars, nbBits */
        "je .Lf1e8930_001e89c0\n"
        ".Lf1e8930_001e8972:\n"
        "subl $1, %esi\n" /* line 245 */
        "movl (%ebx), %edx\n" /* line 246 | bits */
        "addl 8(%ebx), %edx\n" /* bits */
        "movl -0x1c(%ebp), %eax\n" /* data */
        "movl %esi, %ecx\n"
        "shrl %cl, %eax\n"
        "andl $1, %eax\n"
        "movl $7, %ecx\n"
        "subl 0xc(%ebx), %ecx\n" /* bits */
        "shll %cl, %eax\n"
        "orb %al, (%edx)\n"
        "movl 0xc(%ebx), %eax\n" /* line 247 | bits */
        "addl $1, %eax\n"
        "movl %eax, 0xc(%ebx)\n" /* bits */
        "cmpl $8, %eax\n" /* line 249 */
        "jne .Lf1e8930_001e8966\n"
        "movl $0, 0xc(%ebx)\n" /* line 251 | bits */
        "movl 8(%ebx), %edx\n" /* line 252 | bits */
        "addl $1, %edx\n"
        "movl %edx, 8(%ebx)\n" /* bits */
        "movl (%ebx), %eax\n" /* line 253 | bits */
        "movb $0, (%eax, %edx)\n"
        "addl $1, 4(%ebx)\n" /* line 255 | bits */
        "addl $1, %edi\n" /* new_nchars */
        "cmpl %edi, -0x20(%ebp)\n" /* line 242 | new_nchars, nbBits */
        "jne .Lf1e8930_001e8972\n"
        ".Lf1e8930_001e89c0:\n"
        "addl $0x2c, %esp\n" /* line 258 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1e8930_001e89c8:\n"
        "movl $0x2b8ff4, (%esp)\n" /* line 222 */
        "calll speex_warning\n"
        "movl 0x10(%ebx), %eax\n" /* line 223 | bits */
        "testl %eax, %eax\n"
        "jne .Lf1e8930_001e89ee\n"
        "movl $0x2b9040, 8(%ebp)\n" /* line 237 | bits */
        ".Lf1e8930_001e89e2:\n"
        "addl $0x2c, %esp\n" /* line 258 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp speex_warning\n" /* line 237 */
        /* { scope 1 */
        ".Lf1e8930_001e89ee:\n"
        "movl 0x18(%ebx), %eax\n" /* line 225 | bits */
        "leal 0xf(%eax, %eax, 2), %edi\n" /* new_nchars */
        "sarl $1, %edi\n" /* new_nchars */
        "movl %edi, 4(%esp)\n" /* line 226 | new_nchars */
        "movl (%ebx), %eax\n" /* bits */
        "movl %eax, (%esp)\n"
        "calll speex_realloc\n"
        "movl %eax, %esi\n"
        "testl %eax, %eax\n" /* line 227 */
        "je .Lf1e8930_001e8a29\n"
        "movl %edi, 8(%esp)\n" /* line 229 | new_nchars */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll speex_memset_bytes\n"
        "movl %edi, 0x18(%ebx)\n" /* line 230 | new_nchars, bits */
        "movl %esi, (%ebx)\n" /* line 231 | bits */
        "jmp .Lf1e8930_001e8958\n"
        ".Lf1e8930_001e8a29:\n"
        "movl $0x2b9014, 8(%ebp)\n" /* line 233 | bits */
        "jmp .Lf1e8930_001e89e2\n"
    );
}

/* line 271 */
__attribute__((naked))
unsigned int speex_bits_unpack_unsigned(SpeexBits *bits, int nbBits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 271 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $8, %esp\n"
        "movl 8(%ebp), %ebx\n" /* bits */
        /* { scope 1 */
        "movl 8(%ebx), %esi\n" /* line 274 | bits */
        "movl 0xc(%ebx), %edx\n" /* bits */
        "leal (%edx, %esi, 8), %eax\n"
        "addl 0xc(%ebp), %eax\n" /* nbBits */
        "cmpl 4(%ebx), %eax\n" /* bits */
        "jle .Lf1e8a32_001e8a56\n"
        "movl $1, 0x14(%ebx)\n" /* line 275 | bits */
        ".Lf1e8a32_001e8a56:\n"
        "movl 0x14(%ebx), %eax\n" /* line 276 | bits */
        "testl %eax, %eax\n"
        "jne .Lf1e8a32_001e8ab9\n"
        "movl 0xc(%ebp), %eax\n" /* line 278 | nbBits */
        "testl %eax, %eax\n"
        "je .Lf1e8a32_001e8ab9\n"
        "xorl %edi, %edi\n" /* line 276 | d */
        "movl $0, -0x10(%ebp)\n"
        "movl (%ebx), %eax\n" /* bits */
        "movl %eax, -0x14(%ebp)\n"
        "movl %eax, %ecx\n"
        "jmp .Lf1e8a32_001e8a8b\n"
        ".Lf1e8a32_001e8a76:\n"
        "addl $1, -0x10(%ebp)\n" /* line 286 */
        "movl -0x10(%ebp), %eax\n" /* line 278 */
        "cmpl %eax, 0xc(%ebp)\n" /* nbBits */
        "je .Lf1e8a32_001e8abb\n"
        "movl 8(%ebx), %esi\n" /* bits */
        "movl 0xc(%ebx), %edx\n" /* bits */
        "movl -0x14(%ebp), %ecx\n"
        ".Lf1e8a32_001e8a8b:\n"
        "addl %edi, %edi\n" /* line 280 | d */
        "movsbl (%ecx, %esi), %eax\n" /* line 281 */
        "movl $7, %ecx\n"
        "subl %edx, %ecx\n"
        "sarl %cl, %eax\n"
        "andl $1, %eax\n"
        "orl %eax, %edi\n" /* d */
        "addl $1, %edx\n" /* line 282 */
        "movl %edx, 0xc(%ebx)\n" /* bits */
        "cmpl $8, %edx\n" /* line 283 */
        "jne .Lf1e8a32_001e8a76\n"
        "movl $0, 0xc(%ebx)\n" /* line 285 | bits */
        "leal 1(%esi), %eax\n" /* line 286 */
        "movl %eax, 8(%ebx)\n" /* bits */
        "jmp .Lf1e8a32_001e8a76\n"
        ".Lf1e8a32_001e8ab9:\n"
        "xorl %edi, %edi\n" /* line 278 | d */
        /* } scope */
        ".Lf1e8a32_001e8abb:\n"
        "movl %edi, %eax\n" /* line 291 | d */
        "addl $8, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 322 */
__attribute__((naked))
int speex_bits_peek(SpeexBits *bits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 322 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edx\n" /* bits */
        "movl 8(%edx), %ecx\n" /* line 324 */
        "movl 0xc(%edx), %ebx\n"
        "leal 1(%ebx, %ecx, 8), %eax\n"
        "cmpl 4(%edx), %eax\n"
        "jle .Lf1e8ac8_001e8ae5\n"
        "movl $1, 0x14(%edx)\n" /* line 325 */
        ".Lf1e8ac8_001e8ae5:\n"
        "movl 0x14(%edx), %eax\n" /* line 326 */
        "testl %eax, %eax\n"
        "jne .Lf1e8ac8_001e8b01\n"
        "movl (%edx), %eax\n" /* line 328 */
        "movsbl (%eax, %ecx), %eax\n"
        "movl $7, %ecx\n"
        "subl %ebx, %ecx\n"
        "sarl %cl, %eax\n"
        "andl $1, %eax\n"
        "popl %ebx\n" /* line 329 */
        "popl %ebp\n"
        "retl\n"
        ".Lf1e8ac8_001e8b01:\n"
        "xorl %eax, %eax\n" /* line 326 */
        "popl %ebx\n" /* line 329 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 331 */
__attribute__((naked))
void speex_bits_advance(SpeexBits *bits, int n)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 331 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ecx\n" /* bits */
        "movl 8(%ecx), %ebx\n" /* line 333 */
        "movl 0xc(%ecx), %edx\n"
        "leal (%edx, %ebx, 8), %eax\n"
        "addl 0xc(%ebp), %eax\n" /* n */
        "cmpl 4(%ecx), %eax\n"
        "jg .Lf1e8b06_001e8b3c\n"
        "movl 0x14(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1e8b06_001e8b3c\n"
        "addl 0xc(%ebp), %edx\n" /* line 337 | n */
        "movl %edx, %eax\n"
        "sarl $3, %eax\n"
        "leal (%ebx, %eax), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "andl $7, %edx\n" /* line 338 */
        "movl %edx, 0xc(%ecx)\n"
        "popl %ebx\n" /* line 339 */
        "popl %ebp\n"
        "retl\n"
        ".Lf1e8b06_001e8b3c:\n"
        "movl $1, 0x14(%ecx)\n" /* line 334 */
        "popl %ebx\n" /* line 339 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 341 */
__attribute__((naked))
int speex_bits_remaining(SpeexBits *bits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 341 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* bits */
        "movl 0x14(%ecx), %eax\n" /* line 343 */
        "testl %eax, %eax\n"
        "jne .Lf1e8b46_001e8b65\n"
        "movl 8(%ecx), %eax\n" /* line 346 */
        "movl 0xc(%ecx), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl 4(%ecx), %edx\n"
        "subl %eax, %edx\n"
        "movl %edx, %eax\n" /* line 347 */
        "popl %ebp\n"
        "retl\n"
        ".Lf1e8b46_001e8b65:\n"
        "movl $0xffffffff, %edx\n" /* line 343 */
        "movl %edx, %eax\n" /* line 347 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 169 */
__attribute__((naked))
int speex_bits_write(SpeexBits *bits, char *chars, int max_nbytes)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 169 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* bits */
        /* { scope 1 */
        "movl 0xc(%ebx), %esi\n" /* line 176 | bits, bitPtr */
        "movl 8(%ebx), %eax\n" /* line 177 | bits */
        "movl %eax, -0x1c(%ebp)\n" /* charPtr */
        "movl 4(%ebx), %edi\n" /* line 178 | bits, nbBits */
        "cmpl $6, %esi\n" /* line 356 | bitPtr */
        "jle .Lf1e8b6e_001e8c0f\n"
        ".Lf1e8b6e_001e8b8f:\n"
        "cmpl $6, 0xc(%ebx)\n" /* line 358 | bits */
        "jle .Lf1e8b6e_001e8bd1\n"
        ".Lf1e8b6e_001e8b95:\n"
        "movl %esi, 0xc(%ebx)\n" /* line 180 | bitPtr, bits */
        "movl -0x1c(%ebp), %esi\n" /* line 181 | charPtr, bitPtr */
        "movl %esi, 8(%ebx)\n" /* bitPtr, bits */
        "movl %edi, 4(%ebx)\n" /* line 182 | nbBits, bits */
        "leal 7(%edi), %ecx\n" /* line 184 | nbBits */
        "sarl $3, %ecx\n"
        "cmpl %ecx, 0x10(%ebp)\n" /* max_nbytes */
        "cmovlel 0x10(%ebp), %ecx\n" /* max_nbytes */
        "testl %ecx, %ecx\n" /* line 191 */
        "jle .Lf1e8b6e_001e8bc7\n"
        "xorl %edx, %edx\n"
        ".Lf1e8b6e_001e8bb4:\n"
        "movl (%ebx), %eax\n" /* line 192 | bits */
        "movzbl (%eax, %edx), %eax\n"
        "movl 0xc(%ebp), %esi\n" /* chars, bitPtr */
        "movb %al, (%edx, %esi)\n"
        "addl $1, %edx\n" /* line 191 */
        "cmpl %edx, %ecx\n"
        "jne .Lf1e8b6e_001e8bb4\n"
        /* } scope */
        ".Lf1e8b6e_001e8bc7:\n"
        "movl %ecx, %eax\n" /* line 194 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e8b6e_001e8bd1:\n"
        "movl $1, 8(%esp)\n" /* line 359 */
        "movl $1, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* bits */
        "calll speex_bits_pack\n"
        "cmpl $6, 0xc(%ebx)\n" /* line 358 | bits */
        "jg .Lf1e8b6e_001e8b95\n"
        "movl $1, 8(%esp)\n" /* line 359 */
        "movl $1, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* bits */
        "calll speex_bits_pack\n"
        "cmpl $6, 0xc(%ebx)\n" /* line 358 | bits */
        "jle .Lf1e8b6e_001e8bd1\n"
        "jmp .Lf1e8b6e_001e8b95\n"
        ".Lf1e8b6e_001e8c0f:\n"
        "movl $1, 8(%esp)\n" /* line 357 */
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* bits */
        "calll speex_bits_pack\n"
        "jmp .Lf1e8b6e_001e8b8f\n"
    );
}

