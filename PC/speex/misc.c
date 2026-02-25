/* ASM dump from: misc.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/speex/misc.c */

#include "common_types.h"
#include "imports.h"

void speex_memset_bytes(char *dst, int src, int nbytes);
void * speex_alloc(int size);
void * speex_realloc(void *ptr, int size);
void speex_free(void *ptr);
void * speex_move(void *dest, void *src, int n);
void speex_error(const char *str);
void speex_warning(const char *str);
void speex_warning_int(const char *str, int val);
void speex_rand_vec(float std, spx_sig_t *data, int len);
float speex_rand(float std);

/* line 132 */
__attribute__((naked))
void speex_memset_bytes(char *dst, int src, int nbytes)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 132 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movsbl 0xc(%ebp), %eax\n" /* src */
        "movl 0x10(%ebp), %edx\n" /* line 134 | nbytes */
        "movl %edx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* dst */
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "leave\n" /* line 135 */
        "retl\n"
    );
}

/* line 138 */
__attribute__((naked))
void * speex_alloc(int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 138 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 141 */
        "jmp Z_MallocInternal\n" /* line 140 */
    );
}

/* line 143 */
__attribute__((naked))
void * speex_realloc(void *ptr, int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 143 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n" /* line 147 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 149 */
__attribute__((naked))
void speex_free(void *ptr)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 149 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 152 */
        "jmp Z_FreeInternal\n" /* line 151 */
    );
}

/* line 154 */
__attribute__((naked))
void * speex_move(void *dest, void *src, int n)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 154 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 157 */
        "jmp memmove\n" /* line 156 */
    );
}

/* line 159 */
__attribute__((naked))
void speex_error(const char *str)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 159 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 161 | str */
        "movl %eax, 8(%esp)\n"
        "movl $0x2b9068, 4(%esp)\n" /* "Fatal error: %s
" */
        "movl ___sF, %eax\n"
        "addl $0xb0, %eax\n"
        "movl %eax, (%esp)\n"
        "calll fprintf\n"
        "movl $1, (%esp)\n" /* line 162 */
        "calll exit\n"
    );
}

/* line 165 */
__attribute__((naked))
void speex_warning(const char *str)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 165 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 167 | str */
        "movl %eax, 8(%esp)\n"
        "movl $0x2b907c, 4(%esp)\n" /* "warning: %s
" */
        "movl ___sF, %eax\n"
        "addl $0xb0, %eax\n"
        "movl %eax, (%esp)\n"
        "calll fprintf\n"
        "leave\n" /* line 168 */
        "retl\n"
    );
}

/* line 170 */
__attribute__((naked))
void speex_warning_int(const char *str, int val)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 170 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* line 172 | val */
        "movl %eax, 0xc(%esp)\n"
        "movl 8(%ebp), %eax\n" /* str */
        "movl %eax, 8(%esp)\n"
        "movl $0x2b908c, 4(%esp)\n" /* "warning: %s %d
" */
        "movl ___sF, %eax\n"
        "addl $0xb0, %eax\n"
        "movl %eax, (%esp)\n"
        "calll fprintf\n"
        "leave\n" /* line 173 */
        "retl\n"
    );
}

/* line 175 */
__attribute__((naked))
void speex_rand_vec(float std, spx_sig_t *data, int len)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 175 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0x10(%ebp), %edi\n" /* len */
        /* { scope 1 */
        "testl %edi, %edi\n" /* line 178 | len */
        "jg .Lf1e8d02_001e8d1a\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 180 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e8d02_001e8d1a:\n"
        "cvtss2sd 8(%ebp), %xmm0\n" /* line 178 | std */
        "mulsd 0x307db0, %xmm0\n" /* 3.0 */
        "movsd %xmm0, -0x20(%ebp)\n"
        "xorl %esi, %esi\n" /* i */
        "movl 0xc(%ebp), %ebx\n" /* data */
        ".Lf1e8d02_001e8d31:\n"
        "cvtss2sd (%ebx), %xmm0\n" /* line 179 */
        "movsd %xmm0, -0x28(%ebp)\n"
        "calll rand\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x2ed630, %xmm0\n" /* 4.656612873077393e-10f */
        "cvtss2sd %xmm0, %xmm0\n"
        "subsd 0x307ce0, %xmm0\n" /* 0.5 */
        "mulsd -0x20(%ebp), %xmm0\n"
        "addsd -0x28(%ebp), %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%ebx)\n"
        "addl $1, %esi\n" /* line 178 | i */
        "addl $4, %ebx\n"
        "cmpl %esi, %edi\n" /* i, len */
        "jne .Lf1e8d02_001e8d31\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 180 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 182 */
__attribute__((naked))
float speex_rand(float std)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 182 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movss 8(%ebp), %xmm1\n" /* std */
        "movss %xmm1, -0x28(%ebp)\n" /* line 184 */
        "calll rand\n"
        "movss -0x28(%ebp), %xmm1\n"
        "mulss 0x2ed720, %xmm1\n" /* 3.0f */
        "cvtss2sd %xmm1, %xmm1\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x2ed630, %xmm0\n" /* 4.656612873077393e-10f */
        "cvtss2sd %xmm0, %xmm0\n"
        "subsd 0x307ce0, %xmm0\n" /* 0.5 */
        "mulsd %xmm0, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm1\n"
        "movss %xmm1, -0xc(%ebp)\n"
        "flds -0xc(%ebp)\n" /* line 185 */
        "leave\n"
        "retl\n"
    );
}

