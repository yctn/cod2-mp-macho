/* ASM dump from: nb_celp.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/speex/nb_celp.c */

#include "common_types.h"
#include "imports.h"

static const float exc_gain_quant_scal3_bound[7]; /* 0x306464 */
static const float exc_gain_quant_scal3[8]; /* 0x306440 */
static const float exc_gain_quant_scal1_bound[1]; /* 0x306460 */
static const float exc_gain_quant_scal1[2]; /* 0x306420 */

double * nb_encoder_init(const SpeexMode *m);
double nb_encoder_destroy(double *state);
int nb_encode(double *state, double *vin, SpeexBits *bits);
double * nb_decoder_init(const SpeexMode *m);
double nb_decoder_destroy(double *state);
int nb_decode(double *state, SpeexBits *bits, double *vout);
int nb_encoder_ctl(double *state, int request, double *ptr);
int nb_decoder_ctl(double *state, int request, double *ptr);

/* line 101 */
__attribute__((naked))
double * nb_encoder_init(const SpeexMode *m)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 101 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %edi\n" /* m */
        /* { scope 1: part1, part2 */
        "movl (%edi), %ebx\n" /* line 107 | i, mode */
        "movl $0x7dfc, (%esp)\n" /* line 114 */
        "calll speex_alloc\n"
        "movl %eax, %esi\n" /* st */
        "testl %eax, %eax\n" /* line 115 */
        "je .Lf1f09a4_001f0e60\n"
        "leal 0xfc(%eax), %eax\n" /* line 117 */
        "movl %eax, 0x48(%esi)\n" /* st */
        "movl %edi, (%esi)\n" /* line 120 | i, st */
        "movl (%ebx), %eax\n" /* line 122 | mode */
        "movl %eax, 8(%esi)\n" /* st */
        "leal (%eax, %eax, 2), %eax\n" /* line 123 */
        "movl %eax, %edx\n"
        "shrl $0x1f, %edx\n"
        "leal (%edx, %eax), %edi\n" /* i */
        "sarl $1, %edi\n" /* i */
        "movl %edi, 0x14(%esi)\n" /* i, st */
        "movl (%ebx), %eax\n" /* line 124 | mode */
        "cltd\n"
        "idivl 4(%ebx)\n" /* mode */
        "movl %eax, 0x10(%esi)\n" /* st */
        "movl 4(%ebx), %eax\n" /* line 125 | mode */
        "movl %eax, 0xc(%esi)\n" /* st */
        "movl 8(%ebx), %eax\n" /* line 126 | mode */
        "movl %eax, 0x18(%esi)\n" /* st */
        "movl 0x14(%ebx), %eax\n" /* line 127 | mode */
        "movl %eax, 0x38(%esi)\n" /* st */
        "movl 0x18(%ebx), %eax\n" /* line 128 | mode */
        "movl %eax, 0x3c(%esi)\n" /* st */
        "movl 0xc(%ebx), %eax\n" /* line 129 | mode */
        "movl %eax, 0x1c(%esi)\n" /* st */
        "movl 0x10(%ebx), %eax\n" /* line 130 | mode */
        "movl %eax, 0x20(%esi)\n" /* st */
        "movl 0x1c(%ebx), %eax\n" /* line 131 | mode */
        "movl %eax, 0x40(%esi)\n" /* st */
        "movl 0x20(%ebx), %eax\n" /* line 132 | mode */
        "movl %eax, 0x44(%esi)\n" /* st */
        "leal 0x24(%ebx), %eax\n" /* line 134 | mode */
        "movl %eax, 0xf0(%esi)\n" /* st */
        "movl 0x64(%ebx), %eax\n" /* line 135 | mode */
        "movl %eax, 0xf8(%esi)\n" /* st */
        "movl %eax, 0xf4(%esi)\n" /* st */
        "movl $1, 0x28(%esi)\n" /* line 136 | st */
        "movl $1, 0xec(%esi)\n" /* line 138 | st */
        "leal (, %edi, 4), %edx\n" /* line 145 */
        "movl %edx, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x4c(%esi)\n" /* st */
        "movl %eax, 0x50(%esi)\n" /* line 146 | st */
        "movl (%ebx), %eax\n" /* line 148 | mode */
        "addl 0x10(%ebx), %eax\n" /* mode */
        "leal 4(, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x54(%esi)\n" /* st */
        "movl 0x10(%ebx), %edx\n" /* line 149 | mode */
        "leal 4(%eax, %edx, 4), %edx\n"
        "movl %edx, 0x58(%esi)\n" /* st */
        "movl (%ebx), %eax\n" /* line 150 | mode */
        "addl 0x10(%ebx), %eax\n" /* mode */
        "leal 4(, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x5c(%esi)\n" /* st */
        "movl 0x10(%ebx), %edx\n" /* line 151 | mode */
        "leal 4(%eax, %edx, 4), %edx\n"
        "movl %edx, 0x60(%esi)\n" /* st */
        "movl 8(%esi), %eax\n" /* line 153 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x64(%esi)\n" /* st */
        /* { scope 2 */
        "movl 8(%esi), %edx\n" /* line 158 | st */
        "movl 0xc(%esi), %eax\n" /* st */
        "sarl $1, %eax\n"
        "movl %edx, %ecx\n"
        "subl %eax, %ecx\n"
        "movl %ecx, -0x38(%ebp)\n" /* part1 */
        "sarl $1, %edx\n" /* line 159 */
        "leal (%eax, %edx), %edx\n"
        "movl %edx, -0x34(%ebp)\n" /* part2 */
        "movl 0x14(%esi), %eax\n" /* line 160 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x68(%esi)\n" /* st */
        "movl -0x38(%ebp), %edx\n" /* line 161 | part1 */
        "testl %edx, %edx\n"
        "jg .Lf1f09a4_001f0e08\n"
        ".Lf1f09a4_001f0ae5:\n"
        "movl -0x34(%ebp), %eax\n" /* line 163 | part2 */
        "testl %eax, %eax\n"
        "jg .Lf1f09a4_001f0d9d\n"
        /* } scope */
        ".Lf1f09a4_001f0af0:\n"
        "movl 0x18(%esi), %eax\n" /* line 167 | st */
        "leal 4(, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x70(%esi)\n" /* st */
        "movl 0x18(%esi), %edx\n" /* line 168 | st */
        "leal 1(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf1f09a4_001f0d42\n"
        ".Lf1f09a4_001f0b13:\n"
        "leal 4(, %edx, 4), %eax\n" /* line 171 */
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x6c(%esi)\n" /* st */
        "movl 0x18(%esi), %eax\n" /* line 173 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x74(%esi)\n" /* st */
        "movl 0x18(%esi), %eax\n" /* line 174 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x90(%esi)\n" /* st */
        "movl 0x18(%esi), %eax\n" /* line 175 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x94(%esi)\n" /* st */
        "movl 0x18(%esi), %eax\n" /* line 176 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x98(%esi)\n" /* st */
        "movl 0x18(%esi), %eax\n" /* line 177 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x9c(%esi)\n" /* st */
        "movl 0x18(%esi), %eax\n" /* line 179 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x78(%esi)\n" /* st */
        "movl 0x18(%esi), %eax\n" /* line 180 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x7c(%esi)\n" /* st */
        "movl 0x18(%esi), %eax\n" /* line 181 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x80(%esi)\n" /* st */
        "movl 0x18(%esi), %eax\n" /* line 182 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x84(%esi)\n" /* st */
        "movl 0x18(%esi), %eax\n" /* line 183 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x88(%esi)\n" /* st */
        "movl 0x18(%esi), %eax\n" /* line 184 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x8c(%esi)\n" /* st */
        "movl $1, 4(%esi)\n" /* line 186 | st */
        "movl 0x18(%esi), %ecx\n" /* line 187 | st */
        "testl %ecx, %ecx\n"
        "jg .Lf1f09a4_001f0d08\n"
        ".Lf1f09a4_001f0c0a:\n"
        "leal (, %ecx, 4), %eax\n" /* line 192 */
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0xa0(%esi)\n" /* st */
        "movl 0x18(%esi), %eax\n" /* line 193 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0xa4(%esi)\n" /* st */
        "movl 0x18(%esi), %eax\n" /* line 194 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0xa8(%esi)\n" /* st */
        "movl 0x18(%esi), %eax\n" /* line 195 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0xac(%esi)\n" /* st */
        "movl 0x10(%esi), %eax\n" /* line 197 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0xb0(%esi)\n" /* st */
        "movl 0x10(%esi), %eax\n" /* line 199 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x34(%esi)\n" /* st */
        "movl $0x40, (%esp)\n" /* line 201 */
        "calll speex_alloc\n"
        "movl %eax, 0xb4(%esi)\n" /* st */
        "movl %eax, (%esp)\n" /* line 202 */
        "calll vbr_init\n"
        "movl $0x41000000, 0xb8(%esi)\n" /* line 203 | st */
        "movl $0, 0xc0(%esi)\n" /* line 204 | st */
        "movl $0, 0xc4(%esi)\n" /* line 205 | st */
        "movl $0, 0xc8(%esi)\n" /* line 206 | st */
        "movl $0, 0xd0(%esi)\n" /* line 207 | st */
        "movl $0, 0xd4(%esi)\n" /* line 208 | st */
        "movl $2, 0xe8(%esi)\n" /* line 210 | st */
        "movl $2, 0xe0(%esi)\n" /* line 211 | st */
        "movl $0x1f40, 0xe4(%esi)\n" /* line 212 | st */
        "movl $0, 0xcc(%esi)\n" /* line 213 | st */
        "movl %esi, %eax\n" /* line 218 | st */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 219 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: part1, part2 */
        ".Lf1f09a4_001f0d08:\n"
        "xorl %ebx, %ebx\n" /* line 187 | mode */
        ".Lf1f09a4_001f0d0a:\n"
        "movl 0x78(%esi), %eax\n" /* line 189 | st */
        "leal (%eax, %ebx, 4), %edx\n"
        "addl $1, %ebx\n" /* mode */
        "cvtsi2ssl %ebx, %xmm0\n" /* mode */
        "cvtss2sd %xmm0, %xmm0\n"
        "mulsd 0x307c28, %xmm0\n" /* 3.141592653589793 */
        "leal 1(%ecx), %eax\n"
        "cvtsi2sdl %eax, %xmm1\n"
        "divsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movl 0x18(%esi), %ecx\n" /* line 187 | st */
        "cmpl %ecx, %ebx\n" /* mode */
        "jl .Lf1f09a4_001f0d0a\n"
        "jmp .Lf1f09a4_001f0c0a\n"
        ".Lf1f09a4_001f0d42:\n"
        "xorl %edi, %edi\n" /* line 168 | i */
        ".Lf1f09a4_001f0d44:\n"
        "cvtss2sd 0x40(%esi), %xmm0\n" /* line 169 | st */
        "mulsd 0x307c98, %xmm0\n" /* 6.283185307179586 */
        "cvtsi2sdl %edi, %xmm1\n" /* i */
        "mulsd %xmm1, %xmm0\n"
        "movl 0x70(%esi), %ebx\n" /* st, mode */
        "mulsd %xmm0, %xmm0\n"
        "mulsd 0x307dd8, %xmm0\n" /* -0.5 */
        "movsd %xmm0, (%esp)\n"
        "calll exp\n"
        "fstpl -0x40(%ebp)\n"
        "movsd -0x40(%ebp), %xmm0\n"
        "mulsd 0x307de0, %xmm0\n" /* 16384.0 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%ebx, %edi, 4)\n" /* mode */
        "addl $1, %edi\n" /* line 168 | i */
        "movl 0x18(%esi), %edx\n" /* st */
        "leal 1(%edx), %eax\n"
        "cmpl %edi, %eax\n" /* i */
        "jg .Lf1f09a4_001f0d44\n"
        "jmp .Lf1f09a4_001f0b13\n"
        /* { scope 2 */
        ".Lf1f09a4_001f0d9d:\n"
        "cvtsi2sdl -0x34(%ebp), %xmm0\n" /* line 163 | part2 */
        "movsd %xmm0, -0x28(%ebp)\n"
        "movl -0x38(%ebp), %edi\n" /* part1, i */
        "shll $2, %edi\n" /* i */
        "movl $0, -0x1c(%ebp)\n"
        ".Lf1f09a4_001f0db4:\n"
        "movl 0x68(%esi), %ebx\n" /* line 164 | st, mode */
        "cvtsi2sdl -0x1c(%ebp), %xmm0\n"
        "mulsd 0x307c28, %xmm0\n" /* 3.141592653589793 */
        "divsd -0x28(%ebp), %xmm0\n"
        "movsd %xmm0, (%esp)\n"
        "calll cos\n"
        "fstpl -0x40(%ebp)\n"
        "movsd -0x40(%ebp), %xmm0\n"
        "mulsd 0x307dd0, %xmm0\n" /* 0.46 */
        "addsd 0x307dc8, %xmm0\n" /* 0.54 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%ebx, %edi)\n" /* mode */
        "addl $1, -0x1c(%ebp)\n" /* line 163 */
        "addl $4, %edi\n" /* i */
        "movl -0x1c(%ebp), %eax\n"
        "cmpl %eax, -0x34(%ebp)\n" /* part2 */
        "jne .Lf1f09a4_001f0db4\n"
        "jmp .Lf1f09a4_001f0af0\n"
        ".Lf1f09a4_001f0e08:\n"
        "cvtsi2sdl -0x38(%ebp), %xmm0\n" /* line 161 | part1 */
        "movsd %xmm0, -0x30(%ebp)\n"
        "xorl %edi, %edi\n" /* i */
        ".Lf1f09a4_001f0e14:\n"
        "movl 0x68(%esi), %ebx\n" /* line 162 | st, mode */
        "cvtsi2sdl %edi, %xmm0\n" /* i */
        "mulsd 0x307c28, %xmm0\n" /* 3.141592653589793 */
        "divsd -0x30(%ebp), %xmm0\n"
        "movsd %xmm0, (%esp)\n"
        "calll cos\n"
        "fstpl -0x40(%ebp)\n"
        "movsd -0x40(%ebp), %xmm0\n"
        "mulsd 0x307dc0, %xmm0\n" /* -0.46 */
        "addsd 0x307dc8, %xmm0\n" /* 0.54 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%ebx, %edi, 4)\n" /* mode */
        "addl $1, %edi\n" /* line 161 | i */
        "cmpl %edi, -0x38(%ebp)\n" /* i, part1 */
        "jne .Lf1f09a4_001f0e14\n"
        "jmp .Lf1f09a4_001f0ae5\n"
        /* } scope */
        ".Lf1f09a4_001f0e60:\n"
        "xorl %eax, %eax\n" /* line 115 */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 219 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 221 */
__attribute__((naked))
double nb_encoder_destroy(double *state)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 221 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* state */
        "movl 0x4c(%ebx), %eax\n" /* line 226 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0x54(%ebx), %eax\n" /* line 227 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0x64(%ebx), %eax\n" /* line 228 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0x94(%ebx), %eax\n" /* line 229 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0x7c(%ebx), %eax\n" /* line 230 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0x84(%ebx), %eax\n" /* line 231 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0x8c(%ebx), %eax\n" /* line 232 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0x5c(%ebx), %eax\n" /* line 233 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0x68(%ebx), %eax\n" /* line 235 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0x70(%ebx), %eax\n" /* line 236 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0x6c(%ebx), %eax\n" /* line 237 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0x74(%ebx), %eax\n" /* line 238 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0x78(%ebx), %eax\n" /* line 239 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0x90(%ebx), %eax\n" /* line 241 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0x98(%ebx), %eax\n" /* line 242 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0x9c(%ebx), %eax\n" /* line 243 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0x80(%ebx), %eax\n" /* line 244 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0x88(%ebx), %eax\n" /* line 245 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0xa0(%ebx), %eax\n" /* line 246 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0xa4(%ebx), %eax\n" /* line 247 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0xa8(%ebx), %eax\n" /* line 248 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0xac(%ebx), %eax\n" /* line 249 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0xb0(%ebx), %eax\n" /* line 250 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0x34(%ebx), %eax\n" /* line 251 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0xb4(%ebx), %eax\n" /* line 253 | state */
        "movl %eax, (%esp)\n"
        "calll vbr_destroy\n"
        "movl 0xb4(%ebx), %eax\n" /* line 254 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl %ebx, 8(%ebp)\n" /* line 257 | state */
        "addl $0x14, %esp\n" /* line 258 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp speex_free\n" /* line 257 */
    );
}

/* line 260 */
__attribute__((naked))
int nb_encode(double *state, double *vin, SpeexBits *bits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 260 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x16c, %esp\n"
        "movl 8(%ebp), %esi\n" /* state */
        /* { scope 1: nol_pitch, nol_pitch_coef, lsp_dist, offset, ... */
        "movl 0x48(%esi), %eax\n" /* line 280 | state */
        "movl %eax, -0x11c(%ebp)\n" /* stack */
        "movl 8(%esi), %eax\n" /* line 283 | state */
        "movl 0x4c(%esi), %ecx\n" /* state */
        "movl 0x14(%esi), %edx\n" /* state */
        "subl %eax, %edx\n"
        "shll $2, %edx\n"
        "movl %edx, 8(%esp)\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll speex_move\n"
        "movl 8(%esi), %ecx\n" /* line 284 | state */
        "testl %ecx, %ecx\n"
        "jle .Lf1f0fcc_001f102c\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf1f0fcc_001f100e:\n"
        "movl 0x14(%esi), %eax\n" /* line 285 | state */
        "subl %ecx, %eax\n"
        "leal (%ebx, %eax), %eax\n" /* i */
        "movl 0x4c(%esi), %ecx\n" /* state */
        "movl 0xc(%ebp), %edi\n" /* vin */
        "movl (%edi, %ebx, 4), %edx\n"
        "movl %edx, (%ecx, %eax, 4)\n"
        "addl $1, %ebx\n" /* line 284 | i */
        "movl 8(%esi), %ecx\n" /* state */
        "cmpl %ecx, %ebx\n" /* i */
        "jl .Lf1f0fcc_001f100e\n"
        ".Lf1f0fcc_001f102c:\n"
        "movl 0x54(%esi), %edx\n" /* line 288 | state */
        "movl 0x20(%esi), %eax\n" /* state */
        "leal 4(, %eax, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal (%edx, %ecx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll speex_move\n"
        "movl 0x5c(%esi), %edx\n" /* line 289 | state */
        "movl 0x20(%esi), %eax\n" /* state */
        "leal 4(, %eax, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 8(%esi), %eax\n" /* state */
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll speex_move\n"
        /* { scope 2: mode, choice, ener */
        "movl -0x11c(%ebp), %eax\n" /* line 293 | stack */
        "negl %eax\n"
        "andl $3, %eax\n"
        "addl -0x11c(%ebp), %eax\n" /* stack */
        "movl 0x14(%esi), %edx\n" /* state */
        "leal (%eax, %edx, 4), %ecx\n"
        "movl %ecx, -0x68(%ebp)\n"
        "movl %eax, %edi\n" /* w_sig */
        "testl %edx, %edx\n" /* line 295 */
        "jle .Lf1f0fcc_001f10b7\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf1f0fcc_001f1091:\n"
        "leal (, %ebx, 4), %eax\n"
        "movl 0x50(%esi), %edx\n" /* line 296 | state */
        "movl 0x68(%esi), %ecx\n" /* state */
        "movss (%edx, %eax), %xmm0\n"
        "mulss (%ecx, %eax), %xmm0\n"
        "movss %xmm0, (%edi, %eax)\n" /* w_sig */
        "addl $1, %ebx\n" /* line 295 | i */
        "movl 0x14(%esi), %edx\n" /* state */
        "cmpl %edx, %ebx\n" /* i */
        "jl .Lf1f0fcc_001f1091\n"
        ".Lf1f0fcc_001f10b7:\n"
        "movl %edx, 0xc(%esp)\n" /* line 299 */
        "movl 0x18(%esi), %eax\n" /* state */
        "addl $1, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x6c(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* w_sig */
        "calll _spx_autocorr\n"
        /* } scope */
        "movl 0x6c(%esi), %eax\n" /* line 301 | state */
        "movss (%eax), %xmm0\n"
        "mulss 0x44(%esi), %xmm0\n" /* state */
        "movss %xmm0, (%eax)\n"
        "movl 0x18(%esi), %edx\n" /* line 304 | state */
        "leal 1(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf1f0fcc_001f1119\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf1f0fcc_001f10f0:\n"
        "leal (, %ebx, 4), %edx\n"
        "movl %edx, %ecx\n" /* line 305 */
        "addl 0x6c(%esi), %ecx\n" /* state */
        "movl 0x70(%esi), %eax\n" /* state */
        "movss (%ecx), %xmm0\n"
        "mulss (%eax, %edx), %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "addl $1, %ebx\n" /* line 304 | i */
        "movl 0x18(%esi), %edx\n" /* state */
        "leal 1(%edx), %eax\n"
        "cmpl %eax, %ebx\n" /* i */
        "jl .Lf1f0fcc_001f10f0\n"
        ".Lf1f0fcc_001f1119:\n"
        "movl %edx, 8(%esp)\n" /* line 308 */
        "movl 0x6c(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x74(%esi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll _spx_lpc\n"
        "fstp %st(0)\n"
        "movl -0x68(%ebp), %ebx\n" /* line 311 | i */
        "movl %ebx, 0x14(%esp)\n" /* i */
        "movl $0x3e4ccccd, 0x10(%esp)\n"
        "movl $0xf, 0xc(%esp)\n"
        "movl 0x78(%esi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x18(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x74(%esi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll lpc_to_lsp\n"
        "movl 0x18(%esi), %edx\n" /* line 313 | state */
        "cmpl %edx, %eax\n"
        "je .Lf1f0fcc_001f11ab\n"
        "cmpl $1, 0xe0(%esi)\n" /* line 316 | state */
        "jle .Lf1f0fcc_001f11a0\n"
        "movl %ebx, 0x14(%esp)\n" /* line 317 | i */
        "movl $0x3d4ccccd, 0x10(%esp)\n"
        "movl $0xb, 0xc(%esp)\n"
        "movl 0x78(%esi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl 0x74(%esi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll lpc_to_lsp\n"
        "cmpl %eax, 0x18(%esi)\n" /* line 318 | state */
        "je .Lf1f0fcc_001f11ab\n"
        ".Lf1f0fcc_001f11a0:\n"
        "movl 0x18(%esi), %eax\n" /* line 321 | state */
        "testl %eax, %eax\n"
        "jg .Lf1f0fcc_001f1913\n"
        ".Lf1f0fcc_001f11ab:\n"
        "movl 4(%esi), %edi\n" /* line 332 | state, w_sig */
        "testl %edi, %edi\n" /* w_sig */
        "je .Lf1f0fcc_001f193e\n"
        ".Lf1f0fcc_001f11b6:\n"
        "movl 0x18(%esi), %eax\n" /* line 333 | state */
        "testl %eax, %eax\n"
        "jg .Lf1f0fcc_001f18ad\n"
        ".Lf1f0fcc_001f11c1:\n"
        "movl $0x3b03126f, 8(%esp)\n" /* line 338 */
        "movl 0x18(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x88(%esi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll lsp_enforce_margin\n"
        "movl -0x68(%ebp), %edi\n" /* line 341 | w_sig */
        "movl %edi, 0xc(%esp)\n" /* w_sig */
        "movl 0x18(%esi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x90(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x88(%esi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll lsp_to_lpc\n"
        "movl 0xf4(%esi), %edx\n" /* line 345 | state */
        "movl 0xf0(%esi), %eax\n" /* state */
        "movl (%eax, %edx, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1f0fcc_001f1225\n"
        "movl 0xc0(%esi), %ebx\n" /* state, i */
        "testl %ebx, %ebx\n" /* i */
        "je .Lf1f0fcc_001f1873\n"
        /* { scope 2: mode, choice, ener */
        ".Lf1f0fcc_001f1225:\n"
        "movl 0x18(%esi), %eax\n" /* line 351 | state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x98(%esi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x90(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x38(%esi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll bw_lpc\n"
        "movl 0x18(%esi), %eax\n" /* line 352 | state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x9c(%esi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x90(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x3c(%esi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll bw_lpc\n"
        "movl 0xa8(%esi), %eax\n" /* line 354 | state */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x18(%esi), %eax\n" /* state */
        "movl %eax, 0x14(%esp)\n"
        "movl 8(%esi), %eax\n" /* state */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x60(%esi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x9c(%esi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x98(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x50(%esi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll filter_mem2\n"
        "movl -0x68(%ebp), %eax\n" /* line 357 */
        "movl %eax, 0x1c(%esp)\n"
        "movl $6, 0x18(%esp)\n"
        "leal -0x50(%ebp), %eax\n" /* nol_pitch_coef */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x38(%ebp), %eax\n" /* nol_pitch */
        "movl %eax, 0x10(%esp)\n"
        "movl 8(%esi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x20(%esi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x1c(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x60(%esi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll open_loop_nbest_pitch\n"
        "movl -0x38(%ebp), %ecx\n" /* line 358 | nol_pitch */
        "movss -0x50(%ebp), %xmm0\n" /* line 359 | nol_pitch_coef */
        "movss %xmm0, -0xa4(%ebp)\n" /* ol_pitch_coef */
        "cvtss2sd %xmm0, %xmm1\n"
        "mulsd 0x307f00, %xmm1\n" /* 0.85 */
        "xorl %eax, %eax\n"
        "leal 1(%eax), %ebx\n" /* line 260 */
        "leal (, %ebx, 4), %eax\n" /* line 366 */
        "cvtss2sd -0x50(%ebp, %eax), %xmm0\n"
        "ucomisd %xmm1, %xmm0\n"
        "jbe .Lf1f0fcc_001f135c\n"
        ".Lf1f0fcc_001f1320:\n"
        "movl -0x38(%ebp, %eax), %eax\n"
        "movl %eax, -0x6c(%ebp)\n"
        "addl %eax, %eax\n"
        "movl %eax, %edx\n"
        "subl %ecx, %edx\n"
        "js .Lf1f0fcc_001f186a\n"
        ".Lf1f0fcc_001f1333:\n"
        "cmpl $2, %edx\n"
        "jg .Lf1f0fcc_001f16ab\n"
        ".Lf1f0fcc_001f133c:\n"
        "movl %ebx, %eax\n" /* i */
        "cmpl $5, %ebx\n" /* line 361 | i */
        "je .Lf1f0fcc_001f1366\n"
        ".Lf1f0fcc_001f1343:\n"
        "movl -0x6c(%ebp), %ecx\n"
        "leal 1(%eax), %ebx\n" /* line 260 */
        "leal (, %ebx, 4), %eax\n" /* line 366 */
        "cvtss2sd -0x50(%ebp, %eax), %xmm0\n"
        "ucomisd %xmm1, %xmm0\n"
        "ja .Lf1f0fcc_001f1320\n"
        ".Lf1f0fcc_001f135c:\n"
        "movl %ecx, -0x6c(%ebp)\n"
        ".Lf1f0fcc_001f135f:\n"
        "movl %ebx, %eax\n" /* i */
        "cmpl $5, %ebx\n" /* line 361 | i */
        "jne .Lf1f0fcc_001f1343\n"
        /* } scope */
        ".Lf1f0fcc_001f1366:\n"
        "movl 0xac(%esi), %eax\n" /* line 397 | state */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x18(%esi), %eax\n" /* state */
        "movl %eax, 0x10(%esp)\n"
        "movl 8(%esi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x58(%esi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x90(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x50(%esi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll fir_mem2\n"
        "movl 8(%esi), %eax\n" /* line 419 | state */
        "movl %eax, 4(%esp)\n"
        "movl 0x58(%esi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll compute_rms\n"
        "fstps -0xa0(%ebp)\n" /* ol_gain */
        "movl 0xb4(%esi), %eax\n" /* line 426 | state */
        "testl %eax, %eax\n"
        "je .Lf1f0fcc_001f13d8\n"
        "movl 0xc0(%esi), %eax\n" /* state */
        "testl %eax, %eax\n"
        "jne .Lf1f0fcc_001f16fe\n"
        "movl 0xc4(%esi), %eax\n" /* state */
        "testl %eax, %eax\n"
        "jne .Lf1f0fcc_001f16fe\n"
        ".Lf1f0fcc_001f13d8:\n"
        "movl $0xbf800000, 0xbc(%esi)\n" /* line 525 | state */
        ".Lf1f0fcc_001f13e2:\n"
        "movl 0xec(%esi), %eax\n" /* line 528 | state */
        "testl %eax, %eax\n"
        "jne .Lf1f0fcc_001f1b59\n"
        "movl 0xf4(%esi), %ebx\n" /* line 546 | state, i */
        "movl 0xf0(%esi), %edx\n" /* state */
        "movl (%edx, %ebx, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1f0fcc_001f1ba5\n"
        ".Lf1f0fcc_001f1407:\n"
        "movl 4(%esi), %edi\n" /* line 568 | state, w_sig */
        "testl %edi, %edi\n" /* w_sig */
        "je .Lf1f0fcc_001f1441\n"
        "movl 0x18(%esi), %eax\n" /* line 570 | state */
        "testl %eax, %eax\n"
        "jle .Lf1f0fcc_001f1441\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf1f0fcc_001f1417:\n"
        "leal (, %ebx, 4), %edx\n" /* line 568 */
        "movl 0x80(%esi), %ecx\n" /* line 571 | state */
        "movl 0x78(%esi), %eax\n" /* state */
        "movl (%edx, %eax), %eax\n"
        "movl %eax, (%edx, %ecx)\n"
        "addl $1, %ebx\n" /* line 570 | i */
        "cmpl %ebx, 0x18(%esi)\n" /* i, state */
        "jg .Lf1f0fcc_001f1417\n"
        "movl 0xf4(%esi), %ebx\n" /* state, i */
        "movl 0xf0(%esi), %edx\n" /* state */
        ".Lf1f0fcc_001f1441:\n"
        "movl (%edx, %ebx, 4), %edx\n" /* line 577 */
        "movl 0x10(%ebp), %edi\n" /* bits, w_sig */
        "movl %edi, 0xc(%esp)\n" /* w_sig */
        "movl 0x18(%esi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x7c(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x78(%esi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll *0x10(%edx)\n"
        "movl 0xf4(%esi), %ebx\n" /* line 613 | state, i */
        "movl 0xf0(%esi), %edx\n" /* state */
        "movl (%edx, %ebx, 4), %eax\n"
        "cmpl $-1, (%eax)\n"
        "je .Lf1f0fcc_001f149f\n"
        "movl $7, 8(%esp)\n" /* line 615 */
        "movl -0x6c(%ebp), %eax\n"
        "subl 0x1c(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* w_sig */
        "calll speex_bits_pack\n"
        "movl 0xf4(%esi), %ebx\n" /* state, i */
        "movl 0xf0(%esi), %edx\n" /* state */
        "movl (%edx, %ebx, 4), %eax\n"
        ".Lf1f0fcc_001f149f:\n"
        "movl 4(%eax), %ebx\n" /* line 618 | i */
        "testl %ebx, %ebx\n" /* i */
        "jne .Lf1f0fcc_001f1c48\n"
        /* { scope 2: mode, choice, ener */
        ".Lf1f0fcc_001f14aa:\n"
        "cvtss2sd -0xa0(%ebp), %xmm0\n" /* line 641 | ol_gain */
        "movsd %xmm0, (%esp)\n"
        "calll log\n"
        "fstpl -0x118(%ebp)\n"
        "movsd -0x118(%ebp), %xmm0\n"
        "mulsd 0x307f20, %xmm0\n" /* 3.5 */
        "addsd 0x307ce0, %xmm0\n" /* 0.5 */
        "movsd %xmm0, (%esp)\n"
        "calll floor\n"
        "fstpl -0xc0(%ebp)\n"
        "cvttsd2si -0xc0(%ebp), %ebx\n" /* qe */
        "testl %ebx, %ebx\n" /* line 642 | qe */
        "js .Lf1f0fcc_001f2810\n"
        "cmpl $0x1f, %ebx\n" /* line 644 | qe */
        "jle .Lf1f0fcc_001f1983\n"
        "movl $0x1f, %ebx\n" /* qe */
        "movsd 0x307f28, %xmm0\n" /* 31.0 */
        ".Lf1f0fcc_001f1510:\n"
        "divsd 0x307f20, %xmm0\n" /* line 646 | 3.5 */
        "movsd %xmm0, (%esp)\n"
        "calll exp\n"
        "fstpl -0xc8(%ebp)\n"
        "cvtsd2ss -0xc8(%ebp), %xmm0\n"
        "movss %xmm0, -0x5c(%ebp)\n"
        "movl $5, 8(%esp)\n" /* line 647 */
        "movl %ebx, 4(%esp)\n" /* qe */
        "movl 0x10(%ebp), %eax\n" /* bits */
        "movl %eax, (%esp)\n"
        "calll speex_bits_pack\n"
        /* } scope */
        "movl 4(%esi), %ecx\n" /* line 658 | state */
        "testl %ecx, %ecx\n"
        "je .Lf1f0fcc_001f157a\n"
        "movl 0x18(%esi), %edi\n" /* line 660 | state, w_sig */
        "testl %edi, %edi\n" /* w_sig */
        "jle .Lf1f0fcc_001f157a\n"
        "xorl %ebx, %ebx\n" /* qe */
        ".Lf1f0fcc_001f155c:\n"
        "leal (, %ebx, 4), %edx\n" /* line 658 */
        "movl 0x84(%esi), %ecx\n" /* line 661 | state */
        "movl 0x7c(%esi), %eax\n" /* state */
        "movl (%edx, %eax), %eax\n"
        "movl %eax, (%edx, %ecx)\n"
        "addl $1, %ebx\n" /* line 660 | qe */
        "cmpl %ebx, 0x18(%esi)\n" /* qe, state */
        "jg .Lf1f0fcc_001f155c\n"
        ".Lf1f0fcc_001f157a:\n"
        "movl $4, %ebx\n" /* line 665 | qe */
        "movl %ebx, %eax\n" /* qe */
        "subl -0x68(%ebp), %eax\n"
        "andl $3, %eax\n"
        "addl -0x68(%ebp), %eax\n"
        "movl 0xc(%esi), %edx\n" /* state */
        "movl %edx, -0xd0(%ebp)\n"
        "movl %edx, %ecx\n"
        "shll $2, %ecx\n"
        "addl %ecx, %eax\n"
        "movl %eax, %edi\n" /* w_sig */
        "subl %ecx, %edi\n" /* w_sig */
        "movl %edi, -0x9c(%ebp)\n" /* w_sig, res */
        "movl %ebx, %edx\n" /* line 667 | qe */
        "subl %eax, %edx\n"
        "andl $3, %edx\n"
        "addl %edx, %eax\n"
        "leal (%ecx, %eax), %eax\n"
        "movl %eax, %edx\n"
        "subl %ecx, %edx\n"
        "movl %edx, -0x98(%ebp)\n" /* target */
        "movl %ebx, %edx\n" /* line 668 | qe */
        "subl %eax, %edx\n"
        "andl $3, %edx\n"
        "addl %edx, %eax\n"
        "leal (%ecx, %eax), %eax\n"
        "movl %eax, %edi\n" /* w_sig */
        "subl %ecx, %edi\n" /* w_sig */
        "movl %edi, -0x90(%ebp)\n" /* w_sig, syn_resp */
        "movl %ebx, %edx\n" /* line 669 | qe */
        "subl %eax, %edx\n"
        "andl $3, %edx\n"
        "addl %edx, %eax\n"
        "leal (%ecx, %eax), %eax\n"
        "movl %eax, %edx\n"
        "subl %ecx, %edx\n"
        "movl %edx, -0x8c(%ebp)\n" /* real_exc */
        "subl %eax, %ebx\n" /* line 670 | qe */
        "andl $3, %ebx\n" /* qe */
        "addl %ebx, %eax\n" /* qe */
        "movl 0x18(%esi), %ecx\n" /* state */
        "leal (%eax, %ecx, 4), %ebx\n" /* qe */
        "movl %ebx, -0x64(%ebp)\n" /* qe */
        "movl %eax, -0x94(%ebp)\n" /* mem */
        "movl 0x10(%esi), %edx\n" /* line 673 | state */
        "testl %edx, %edx\n"
        "jg .Lf1f0fcc_001f1c9e\n"
        ".Lf1f0fcc_001f1607:\n"
        "movl 0xf4(%esi), %eax\n" /* line 931 | state */
        "testl %eax, %eax\n"
        "jle .Lf1f0fcc_001f165f\n"
        "movl 0x18(%esi), %ebx\n" /* line 933 | state, qe */
        "testl %ebx, %ebx\n" /* qe */
        "jle .Lf1f0fcc_001f165f\n"
        "xorl %ebx, %ebx\n" /* qe */
        ".Lf1f0fcc_001f161a:\n"
        "leal (, %ebx, 4), %edx\n" /* line 931 */
        "movl 0x80(%esi), %ecx\n" /* line 934 | state */
        "movl 0x78(%esi), %eax\n" /* state */
        "movl (%eax, %edx), %eax\n"
        "movl %eax, (%ecx, %edx)\n"
        "addl $1, %ebx\n" /* line 933 | qe */
        "cmpl 0x18(%esi), %ebx\n" /* state, qe */
        "jl .Lf1f0fcc_001f161a\n"
        "movl 0x18(%esi), %eax\n" /* line 935 | state */
        "testl %eax, %eax\n"
        "jle .Lf1f0fcc_001f165f\n"
        "xorl %ebx, %ebx\n" /* qe */
        ".Lf1f0fcc_001f1641:\n"
        "leal (, %ebx, 4), %edx\n"
        "movl 0x84(%esi), %ecx\n" /* line 936 | state */
        "movl 0x7c(%esi), %eax\n" /* state */
        "movl (%eax, %edx), %eax\n"
        "movl %eax, (%ecx, %edx)\n"
        "addl $1, %ebx\n" /* line 935 | qe */
        "cmpl 0x18(%esi), %ebx\n" /* state, qe */
        "jl .Lf1f0fcc_001f1641\n"
        ".Lf1f0fcc_001f165f:\n"
        "cmpl $1, 0xf4(%esi)\n" /* line 939 | state */
        "je .Lf1f0fcc_001f268b\n"
        ".Lf1f0fcc_001f166c:\n"
        "movl $0, 4(%esi)\n" /* line 948 | state */
        "movl 0xf4(%esi), %ecx\n" /* line 963 | state */
        "movl 0xf0(%esi), %eax\n" /* state */
        "movl (%eax, %ecx, 4), %edx\n"
        "movl 0x195f9ac, %eax\n"
        "cmpl %eax, 0x24(%edx)\n"
        "je .Lf1f0fcc_001f1694\n"
        "testl %ecx, %ecx\n"
        "jne .Lf1f0fcc_001f1977\n"
        ".Lf1f0fcc_001f1694:\n"
        "movl $1, 0x28(%esi)\n" /* line 964 | state */
        ".Lf1f0fcc_001f169b:\n"
        "movl $1, %eax\n" /* line 966 */
        /* } scope */
        "addl $0x16c, %esp\n" /* line 969 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: nol_pitch, nol_pitch_coef, lsp_dist, offset, ... */
        /* { scope 2: mode, choice, ener */
        ".Lf1f0fcc_001f16ab:\n"
        "movl -0x6c(%ebp), %edi\n" /* line 366 | w_sig */
        "leal (%edi, %edi, 2), %eax\n" /* w_sig */
        "movl %eax, %edx\n"
        "subl %ecx, %edx\n"
        "js .Lf1f0fcc_001f1c3f\n"
        ".Lf1f0fcc_001f16bb:\n"
        "cmpl $3, %edx\n"
        "jle .Lf1f0fcc_001f133c\n"
        "movl -0x6c(%ebp), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, %edx\n"
        "subl %ecx, %edx\n"
        "js .Lf1f0fcc_001f2744\n"
        "cmpl $4, %edx\n"
        "jle .Lf1f0fcc_001f133c\n"
        ".Lf1f0fcc_001f16dd:\n"
        "movl -0x6c(%ebp), %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "movl %eax, %edx\n"
        "subl %ecx, %edx\n"
        "js .Lf1f0fcc_001f2832\n"
        "cmpl $5, %edx\n"
        "jle .Lf1f0fcc_001f133c\n"
        "movl %ecx, -0x6c(%ebp)\n"
        "jmp .Lf1f0fcc_001f135f\n"
        /* } scope */
        /* { scope 2: mode, choice, ener */
        ".Lf1f0fcc_001f16fe:\n"
        "movl 0x18(%esi), %ecx\n" /* line 429 | state */
        "testl %ecx, %ecx\n"
        "jg .Lf1f0fcc_001f18d2\n"
        "pxor %xmm3, %xmm3\n"
        "movss %xmm3, -0x88(%ebp)\n" /* lsp_dist */
        ".Lf1f0fcc_001f1715:\n"
        "movl 0xd0(%esi), %eax\n" /* line 433 | state */
        "testl %eax, %eax\n"
        "je .Lf1f0fcc_001f17b7\n"
        /* { scope 3: bitrate */
        "movss 0xd4(%esi), %xmm1\n" /* line 436 | state */
        "movaps %xmm1, %xmm0\n"
        "mulss 0xd8(%esi), %xmm0\n" /* state */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lf1f0fcc_001f281b\n"
        "cvtss2sd %xmm1, %xmm1\n" /* line 439 */
        "mulsd 0x307de8, %xmm1\n" /* -1e-05 */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "addss 0xdc(%esi), %xmm0\n" /* state */
        "cvtss2sd %xmm0, %xmm0\n"
        "divsd %xmm0, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm0\n"
        "cvtss2sd %xmm0, %xmm2\n" /* line 440 */
        "ucomisd 0x307e08, %xmm2\n" /* 0.05 */
        "ja .Lf1f0fcc_001f27a3\n"
        "ucomisd 0x307f10, %xmm2\n" /* line 442 | -0.05 */
        "jae .Lf1f0fcc_001f178d\n"
        ".Lf1f0fcc_001f1783:\n"
        "jp .Lf1f0fcc_001f178d\n"
        "movss 0x2edab0, %xmm0\n" /* -0.05000000074505806f */
        ".Lf1f0fcc_001f178d:\n"
        "addss 0xb8(%esi), %xmm0\n" /* line 445 | state */
        "movss %xmm0, 0xb8(%esi)\n" /* state */
        "ucomiss 0x2ed6b4, %xmm0\n" /* line 446 | 10.0f */
        "ja .Lf1f0fcc_001f26e5\n"
        ".Lf1f0fcc_001f17aa:\n"
        "ucomiss 0xb8(%esi), %xmm3\n" /* line 448 | state */
        "ja .Lf1f0fcc_001f2823\n"
        /* } scope */
        ".Lf1f0fcc_001f17b7:\n"
        "movss -0xa4(%ebp), %xmm0\n" /* line 452 | ol_pitch_coef */
        "movss %xmm0, 0x10(%esp)\n"
        "movl -0x6c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 8(%esi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* vin */
        "movl %edx, 4(%esp)\n"
        "movl 0xb4(%esi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll vbr_analysis\n"
        "fstps -0x10c(%ebp)\n"
        "movss -0x10c(%ebp), %xmm2\n"
        "movss %xmm2, 0xbc(%esi)\n" /* state */
        "movl 0xc0(%esi), %edi\n" /* line 455 | state, w_sig */
        "testl %edi, %edi\n" /* w_sig */
        "jne .Lf1f0fcc_001f198c\n"
        /* { scope 3: bitrate */
        "ucomiss 0x2ed62c, %xmm2\n" /* line 507 | 2.0f */
        "jae .Lf1f0fcc_001f26ca\n"
        "jp .Lf1f0fcc_001f26ca\n"
        "movl 0xcc(%esi), %eax\n" /* line 509 | state */
        "testl %eax, %eax\n"
        "je .Lf1f0fcc_001f27e6\n"
        "cvtss2sd -0x88(%ebp), %xmm0\n" /* lsp_dist */
        "ucomisd 0x307e08, %xmm0\n" /* 0.05 */
        "ja .Lf1f0fcc_001f27e6\n"
        "movl 0xc8(%esi), %edx\n" /* state */
        "testl %edx, %edx\n"
        "je .Lf1f0fcc_001f27e6\n"
        "cmpl $0x14, %eax\n"
        "jg .Lf1f0fcc_001f27e6\n"
        "addl $1, %eax\n" /* line 515 */
        "movl %eax, 0xcc(%esi)\n" /* state */
        "xorl %eax, %eax\n"
        "jmp .Lf1f0fcc_001f26da\n"
        /* } scope */
        /* } scope */
        /* { scope 2: mode, choice, ener */
        ".Lf1f0fcc_001f186a:\n"
        "movl %ecx, %edx\n" /* line 366 */
        "subl %eax, %edx\n"
        "jmp .Lf1f0fcc_001f1333\n"
        /* } scope */
        ".Lf1f0fcc_001f1873:\n"
        "movl 0xc4(%esi), %ecx\n" /* line 345 | state */
        "testl %ecx, %ecx\n"
        "jne .Lf1f0fcc_001f1225\n"
        "movl 4(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf1f0fcc_001f1225\n"
        "cmpl $-1, (%eax)\n"
        "jne .Lf1f0fcc_001f1225\n"
        /* { scope 2: mode, choice, ener */
        "movl $0, -0x6c(%ebp)\n" /* line 361 */
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0xa4(%ebp)\n" /* ol_pitch_coef */
        "jmp .Lf1f0fcc_001f1366\n"
        /* } scope */
        ".Lf1f0fcc_001f18ad:\n"
        "xorl %ebx, %ebx\n" /* line 333 | i */
        ".Lf1f0fcc_001f18af:\n"
        "leal (, %ebx, 4), %edx\n" /* line 332 */
        "movl 0x88(%esi), %ecx\n" /* line 334 | state */
        "movl 0x78(%esi), %eax\n" /* state */
        "movl (%eax, %edx), %eax\n"
        "movl %eax, (%ecx, %edx)\n"
        "addl $1, %ebx\n" /* line 333 | i */
        "cmpl %ebx, 0x18(%esi)\n" /* i, state */
        "jg .Lf1f0fcc_001f18af\n"
        "jmp .Lf1f0fcc_001f11c1\n"
        /* { scope 2: mode, choice, ener */
        ".Lf1f0fcc_001f18d2:\n"
        "movl 0x80(%esi), %ebx\n" /* line 430 | state, i */
        "movl 0x78(%esi), %edx\n" /* state */
        "xorl %eax, %eax\n"
        "pxor %xmm3, %xmm3\n"
        "movss %xmm3, -0x88(%ebp)\n" /* lsp_dist */
        ".Lf1f0fcc_001f18e9:\n"
        "movss (%ebx, %eax, 4), %xmm0\n" /* i */
        "subss (%edx, %eax, 4), %xmm0\n"
        "mulss %xmm0, %xmm0\n"
        "addss -0x88(%ebp), %xmm0\n" /* lsp_dist */
        "movss %xmm0, -0x88(%ebp)\n" /* lsp_dist */
        "addl $1, %eax\n" /* line 429 */
        "cmpl %eax, %ecx\n"
        "jne .Lf1f0fcc_001f18e9\n"
        "jmp .Lf1f0fcc_001f1715\n"
        /* } scope */
        ".Lf1f0fcc_001f1913:\n"
        "xorl %ebx, %ebx\n" /* line 321 | i */
        ".Lf1f0fcc_001f1915:\n"
        "leal (, %ebx, 4), %edx\n"
        "movl 0x78(%esi), %ecx\n" /* line 323 | state */
        "movl 0x80(%esi), %eax\n" /* state */
        "movl (%eax, %edx), %eax\n"
        "movl %eax, (%ecx, %edx)\n"
        "addl $1, %ebx\n" /* line 321 | i */
        "cmpl %ebx, 0x18(%esi)\n" /* i, state */
        "jg .Lf1f0fcc_001f1915\n"
        "movl 4(%esi), %edi\n" /* line 332 | state, w_sig */
        "testl %edi, %edi\n" /* w_sig */
        "jne .Lf1f0fcc_001f11b6\n"
        ".Lf1f0fcc_001f193e:\n"
        "movl 0x10(%esi), %edx\n" /* line 336 | state */
        "leal (%edx, %edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl 0x18(%esi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x88(%esi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x78(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x80(%esi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll lsp_interpolate\n"
        "jmp .Lf1f0fcc_001f11c1\n"
        ".Lf1f0fcc_001f1977:\n"
        "movl $0, 0x28(%esi)\n" /* line 966 | state */
        "jmp .Lf1f0fcc_001f169b\n"
        /* { scope 2: mode, choice, ener */
        ".Lf1f0fcc_001f1983:\n"
        "cvtsi2sdl %ebx, %xmm0\n" /* line 644 | qe */
        "jmp .Lf1f0fcc_001f1510\n"
        /* } scope */
        /* { scope 2: mode, choice, ener */
        /* { scope 3: bitrate */
        ".Lf1f0fcc_001f198c:\n"
        "movl $8, -0x1c(%ebp)\n" /* line 460 | mode */
        "movss 0x2ed798, %xmm4\n" /* 100.0f */
        "movl $0, -0x84(%ebp)\n" /* choice */
        "movl $8, %ebx\n" /* i */
        "movl 0x195f9b0, %edi\n" /* w_sig */
        "movss 0xb8(%esi), %xmm0\n" /* state */
        "movss %xmm0, -0xcc(%ebp)\n"
        "movss %xmm0, (%esp)\n"
        "movss %xmm2, -0xf8(%ebp)\n"
        "movss %xmm4, -0x108(%ebp)\n"
        "calll floorf\n"
        "fstps -0xb0(%ebp)\n"
        "cvttss2si -0xb0(%ebp), %eax\n"
        "leal 1(%eax), %edx\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0xcc(%ebp), %xmm5\n"
        "subss %xmm0, %xmm5\n"
        "cvtsi2ssl %edx, %xmm3\n"
        "subss -0xcc(%ebp), %xmm3\n"
        "leal 0x160(%edi, %eax, 4), %edx\n" /* w_sig */
        "cmpl $0xa, %eax\n"
        "movss -0xf8(%ebp), %xmm2\n"
        "movss -0x108(%ebp), %xmm4\n"
        "je .Lf1f0fcc_001f1b19\n"
        /* { scope 4 */
        ".Lf1f0fcc_001f1a27:\n"
        "movaps %xmm5, %xmm1\n" /* line 469 */
        "mulss 4(%edx), %xmm1\n"
        "movaps %xmm3, %xmm0\n"
        "mulss (%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "ucomiss %xmm1, %xmm2\n" /* line 470 */
        "jbe .Lf1f0fcc_001f1a54\n"
        "movaps %xmm2, %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "ucomiss %xmm0, %xmm4\n"
        "jbe .Lf1f0fcc_001f1a54\n"
        "movl %ebx, -0x84(%ebp)\n" /* i, choice */
        "movaps %xmm0, %xmm4\n"
        ".Lf1f0fcc_001f1a54:\n"
        "subl $0x2c, %edx\n" /* line 476 */
        /* } scope */
        "subl $1, %ebx\n" /* line 461 | i */
        "jne .Lf1f0fcc_001f1a27\n"
        "movl -0x84(%ebp), %ecx\n" /* line 478 | choice */
        "movl %ecx, -0x1c(%ebp)\n" /* mode */
        "testl %ecx, %ecx\n" /* line 479 */
        "je .Lf1f0fcc_001f26f4\n"
        ".Lf1f0fcc_001f1a6d:\n"
        "movl $0, 0xcc(%esi)\n" /* line 490 | state */
        ".Lf1f0fcc_001f1a77:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 493 | mode */
        "movl %eax, 8(%esp)\n"
        "movl $6, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* state */
        "calll speex_encoder_ctl\n"
        "movl 0xd0(%esi), %ecx\n" /* line 495 | state */
        "testl %ecx, %ecx\n"
        "je .Lf1f0fcc_001f13e2\n"
        /* { scope 4 */
        "leal -0x20(%ebp), %eax\n" /* line 498 | bitrate */
        "movl %eax, 8(%esp)\n"
        "movl $0x13, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* state */
        "calll speex_encoder_ctl\n"
        "movl -0x20(%ebp), %eax\n" /* line 499 | bitrate */
        "subl 0xd0(%esi), %eax\n" /* state */
        "cvtsi2ssl %eax, %xmm0\n"
        "addss 0xd4(%esi), %xmm0\n" /* state */
        "movss %xmm0, 0xd4(%esi)\n" /* state */
        "cvtss2sd 0xd8(%esi), %xmm1\n" /* line 500 | state */
        "mulsd 0x307e00, %xmm1\n" /* 0.95 */
        "cvtsi2sdl %eax, %xmm0\n"
        "mulsd 0x307e08, %xmm0\n" /* 0.05 */
        "addsd %xmm0, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm1\n"
        "movss %xmm1, 0xd8(%esi)\n" /* state */
        "movss 0x2ed5d0, %xmm0\n" /* line 501 | 1.0f */
        "addss 0xdc(%esi), %xmm0\n" /* state */
        "movss %xmm0, 0xdc(%esi)\n" /* state */
        "jmp .Lf1f0fcc_001f13e2\n"
        /* } scope */
        /* { scope 4 */
        ".Lf1f0fcc_001f1b19:\n"
        "movss 0x188(%edi), %xmm1\n" /* line 467 | w_sig */
        "ucomiss %xmm1, %xmm2\n" /* line 470 */
        "jbe .Lf1f0fcc_001f1b3b\n"
        "movaps %xmm2, %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "ucomiss %xmm0, %xmm4\n"
        "jbe .Lf1f0fcc_001f1b3b\n"
        "movl %ebx, -0x84(%ebp)\n" /* i, choice */
        "movaps %xmm0, %xmm4\n"
        ".Lf1f0fcc_001f1b3b:\n"
        "subl $0x2c, %edi\n" /* line 476 | w_sig */
        /* } scope */
        "subl $1, %ebx\n" /* line 461 | i */
        "jne .Lf1f0fcc_001f1b19\n"
        "movl -0x84(%ebp), %ecx\n" /* line 478 | choice */
        "movl %ecx, -0x1c(%ebp)\n" /* mode */
        "testl %ecx, %ecx\n" /* line 479 */
        "je .Lf1f0fcc_001f26f4\n"
        "jmp .Lf1f0fcc_001f1a6d\n"
        /* } scope */
        /* } scope */
        ".Lf1f0fcc_001f1b59:\n"
        "movl $1, 8(%esp)\n" /* line 535 */
        "movl $0, 4(%esp)\n"
        "movl 0x10(%ebp), %ebx\n" /* bits, i */
        "movl %ebx, (%esp)\n" /* i */
        "calll speex_bits_pack\n"
        "movl $4, 8(%esp)\n" /* line 538 */
        "movl 0xf4(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* i */
        "calll speex_bits_pack\n"
        "movl 0xf4(%esi), %ebx\n" /* line 546 | state, i */
        "movl 0xf0(%esi), %edx\n" /* state */
        "movl (%edx, %ebx, 4), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1f0fcc_001f1407\n"
        ".Lf1f0fcc_001f1ba5:\n"
        "movl 8(%esi), %ecx\n" /* line 548 | state */
        "testl %ecx, %ecx\n"
        "jle .Lf1f0fcc_001f1bd2\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf1f0fcc_001f1bae:\n"
        "leal (, %ebx, 4), %eax\n" /* line 546 */
        "movl %eax, %ecx\n" /* line 549 */
        "addl 0x58(%esi), %ecx\n" /* state */
        "movl 0x60(%esi), %edx\n" /* state */
        "movl $0x26901d7d, (%edx, %eax)\n"
        "movl $0x26901d7d, (%ecx)\n"
        "addl $1, %ebx\n" /* line 548 | i */
        "cmpl 8(%esi), %ebx\n" /* state, i */
        "jl .Lf1f0fcc_001f1bae\n"
        ".Lf1f0fcc_001f1bd2:\n"
        "movl 0x18(%esi), %eax\n" /* line 551 | state */
        "testl %eax, %eax\n"
        "jle .Lf1f0fcc_001f1bf0\n"
        "xorl %edx, %edx\n"
        ".Lf1f0fcc_001f1bdb:\n"
        "movl 0xa4(%esi), %eax\n" /* line 552 | state */
        "movl $0, (%eax, %edx, 4)\n"
        "addl $1, %edx\n" /* line 551 */
        "cmpl 0x18(%esi), %edx\n" /* state */
        "jl .Lf1f0fcc_001f1bdb\n"
        ".Lf1f0fcc_001f1bf0:\n"
        "movl $1, 4(%esi)\n" /* line 553 | state */
        "movl $1, 0x28(%esi)\n" /* line 554 | state */
        "movl 0xa0(%esi), %eax\n" /* line 557 | state */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x18(%esi), %eax\n" /* state */
        "movl %eax, 0x10(%esp)\n"
        "movl 8(%esi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x50(%esi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x94(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x58(%esi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll iir_mem2\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x16c, %esp\n" /* line 969 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: nol_pitch, nol_pitch_coef, lsp_dist, offset, ... */
        /* { scope 2: mode, choice, ener */
        ".Lf1f0fcc_001f1c3f:\n"
        "movl %ecx, %edx\n" /* line 366 */
        "subl %eax, %edx\n"
        "jmp .Lf1f0fcc_001f16bb\n"
        /* } scope */
        /* { scope 2: mode, choice, ener */
        ".Lf1f0fcc_001f1c48:\n"
        "movss -0xa4(%ebp), %xmm0\n" /* line 621 | ol_pitch_coef */
        "mulss 0x2ed908, %xmm0\n" /* 15.0f */
        "movss %xmm0, -0xa4(%ebp)\n" /* ol_pitch_coef */
        "cvtss2sd %xmm0, %xmm0\n"
        "addsd 0x307ce0, %xmm0\n" /* 0.5 */
        "movsd %xmm0, (%esp)\n"
        "calll floor\n"
        "fstpl -0xb8(%ebp)\n"
        "cvttsd2si -0xb8(%ebp), %eax\n"
        "cmpl $0xf, %eax\n" /* line 622 */
        "jg .Lf1f0fcc_001f2756\n"
        "testl %eax, %eax\n" /* line 624 */
        "js .Lf1f0fcc_001f2847\n"
        "cvtsi2sdl %eax, %xmm0\n"
        "jmp .Lf1f0fcc_001f2763\n"
        /* } scope */
        ".Lf1f0fcc_001f1c9e:\n"
        "movl $0, -0xa8(%ebp)\n" /* line 673 | sub */
        "movl -0xd0(%ebp), %edi\n" /* w_sig */
        /* { scope 2: mode, choice, ener */
        ".Lf1f0fcc_001f1cae:\n"
        "movl -0xa8(%ebp), %eax\n" /* line 690 | sub */
        "imull %edi, %eax\n" /* response_bound */
        "movl %eax, -0x80(%ebp)\n" /* offset */
        "shll $2, %eax\n" /* line 692 */
        "movl 0x50(%esi), %ebx\n" /* state, qe */
        "addl %eax, %ebx\n" /* qe */
        "movl %ebx, -0x7c(%ebp)\n" /* qe, sp */
        "movl 0x58(%esi), %ebx\n" /* line 694 | state, qe */
        "addl %eax, %ebx\n" /* qe */
        "movl %ebx, -0x74(%ebp)\n" /* qe, exc */
        "addl 0x60(%esi), %eax\n" /* line 696 | state */
        "movl %eax, -0x78(%ebp)\n" /* sw */
        "movl %edx, 0x14(%esp)\n" /* line 699 */
        "movl -0xa8(%ebp), %eax\n" /* sub */
        "movl %eax, 0x10(%esp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl 0x88(%esi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x78(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x80(%esi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll lsp_interpolate\n"
        "movl 0x10(%esi), %eax\n" /* line 700 | state */
        "movl %eax, 0x14(%esp)\n"
        "movl -0xa8(%ebp), %edx\n" /* sub */
        "movl %edx, 0x10(%esp)\n"
        "movl 0x18(%esi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x8c(%esi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x7c(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x84(%esi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll lsp_interpolate\n"
        "movl $0x3b03126f, %ebx\n" /* line 703 | qe */
        "movl %ebx, 8(%esp)\n" /* qe */
        "movl 0x18(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x88(%esi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll lsp_enforce_margin\n"
        "movl %ebx, 8(%esp)\n" /* line 704 | qe */
        "movl 0x18(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x8c(%esi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll lsp_enforce_margin\n"
        "movl -0x64(%ebp), %ecx\n" /* line 707 */
        "movl %ecx, 0xc(%esp)\n"
        "movl 0x18(%esi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x90(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x88(%esi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll lsp_to_lpc\n"
        "movl -0x64(%ebp), %ebx\n" /* line 709 | qe */
        "movl %ebx, 0xc(%esp)\n" /* qe */
        "movl 0x18(%esi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x94(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x8c(%esi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll lsp_to_lpc\n"
        /* { scope 3: bitrate */
        "movl 0x18(%esi), %ecx\n" /* line 714 | state */
        "testl %ecx, %ecx\n"
        "jle .Lf1f0fcc_001f2578\n"
        "xorl %edx, %edx\n" /* line 717 */
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "movl 0x94(%esi), %eax\n" /* state */
        ".Lf1f0fcc_001f1dd9:\n"
        "movss 4(%eax), %xmm0\n"
        "subss (%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addl $2, %edx\n" /* line 714 */
        "addl $8, %eax\n"
        "cmpl %edx, %ecx\n"
        "jg .Lf1f0fcc_001f1dd9\n"
        ".Lf1f0fcc_001f1df0:\n"
        "movl 0xb0(%esi), %eax\n" /* line 719 | state */
        "movl -0xa8(%ebp), %edx\n" /* sub */
        "movss %xmm1, (%eax, %edx, 4)\n"
        /* } scope */
        "movl 0x18(%esi), %eax\n" /* line 724 | state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x98(%esi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x90(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x38(%esi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll bw_lpc\n"
        "movss 0x3c(%esi), %xmm0\n" /* line 725 | state */
        "ucomiss 0x2ed5e8, %xmm0\n" /* 0.0f */
        "jb .Lf1f0fcc_001f2585\n"
        "movl 0x18(%esi), %eax\n" /* line 726 | state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x9c(%esi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x90(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movss %xmm0, (%esp)\n"
        "calll bw_lpc\n"
        ".Lf1f0fcc_001f1e5e:\n"
        "movl 0xc(%esi), %eax\n" /* line 734 | state */
        "testl %eax, %eax\n"
        "jle .Lf1f0fcc_001f1e8c\n"
        "movl $1, %ecx\n"
        ".Lf1f0fcc_001f1e6a:\n"
        "leal (, %ecx, 4), %eax\n" /* line 260 */
        "movl -0x74(%ebp), %ebx\n" /* line 735 | exc, qe */
        "movl -4(%ebx, %eax), %edx\n" /* qe */
        "movl -0x8c(%ebp), %ebx\n" /* real_exc, qe */
        "movl %edx, -4(%ebx, %eax)\n" /* qe */
        "movl %ecx, %eax\n"
        "addl $1, %ecx\n"
        "cmpl %eax, 0xc(%esi)\n" /* line 734 | state */
        "jg .Lf1f0fcc_001f1e6a\n"
        ".Lf1f0fcc_001f1e8c:\n"
        "sarl -0xd0(%ebp)\n" /* line 738 */
        "movl 0xe0(%esi), %eax\n" /* state */
        "testl %eax, %eax\n"
        "cmovel -0xd0(%ebp), %edi\n" /* response_bound */
        "movl -0x64(%ebp), %eax\n" /* line 739 */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x18(%esi), %eax\n" /* state */
        "movl %eax, 0x14(%esp)\n"
        "movl %edi, 0x10(%esp)\n" /* response_bound */
        "movl -0x90(%ebp), %edx\n" /* syn_resp */
        "movl %edx, 0xc(%esp)\n"
        "movl 0x9c(%esi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x98(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x94(%esi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll compute_impulse_response\n"
        "cmpl 0xc(%esi), %edi\n" /* line 740 | state, response_bound */
        "jge .Lf1f0fcc_001f1f00\n"
        "movl -0x90(%ebp), %ecx\n" /* syn_resp */
        "leal (%ecx, %edi, 4), %edx\n"
        "movl %edi, %eax\n" /* response_bound */
        ".Lf1f0fcc_001f1eef:\n"
        "movl $0x26901d7d, (%edx)\n" /* line 741 */
        "addl $1, %eax\n" /* line 740 */
        "addl $4, %edx\n"
        "cmpl %eax, 0xc(%esi)\n" /* state */
        "jg .Lf1f0fcc_001f1eef\n"
        ".Lf1f0fcc_001f1f00:\n"
        "movl 0xc(%esi), %eax\n" /* line 744 | state */
        "testl %eax, %eax\n"
        "jle .Lf1f0fcc_001f1f1b\n"
        "xorl %eax, %eax\n"
        ".Lf1f0fcc_001f1f09:\n"
        "movl -0x74(%ebp), %ebx\n" /* line 745 | exc, qe */
        "movl $0x26901d7d, (%ebx, %eax, 4)\n" /* qe */
        "addl $1, %eax\n" /* line 744 */
        "cmpl %eax, 0xc(%esi)\n" /* state */
        "jg .Lf1f0fcc_001f1f09\n"
        ".Lf1f0fcc_001f1f1b:\n"
        "movl 0x18(%esi), %eax\n" /* line 748 | state */
        "testl %eax, %eax\n"
        "jle .Lf1f0fcc_001f1f47\n"
        "xorl %ecx, %ecx\n"
        ".Lf1f0fcc_001f1f24:\n"
        "leal (, %ecx, 4), %eax\n"
        "movl 0xa0(%esi), %edx\n" /* line 749 | state */
        "movl (%edx, %eax), %edx\n"
        "movl -0x94(%ebp), %edi\n" /* mem, response_bound */
        "movl %edx, (%edi, %eax)\n" /* response_bound */
        "addl $1, %ecx\n" /* line 748 */
        "movl 0x18(%esi), %eax\n" /* state */
        "cmpl %ecx, %eax\n"
        "jg .Lf1f0fcc_001f1f24\n"
        ".Lf1f0fcc_001f1f47:\n"
        "movl -0x94(%ebp), %edx\n" /* line 758 | mem */
        "movl %edx, 0x14(%esp)\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0xc(%esi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x74(%ebp), %ecx\n" /* exc */
        "movl %ecx, 8(%esp)\n"
        "movl 0x94(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll iir_mem2\n"
        "movl 0x18(%esi), %eax\n" /* line 759 | state */
        "testl %eax, %eax\n"
        "jle .Lf1f0fcc_001f1fa1\n"
        "xorl %ecx, %ecx\n"
        ".Lf1f0fcc_001f1f7e:\n"
        "leal (, %ecx, 4), %eax\n"
        "movl 0xa4(%esi), %edx\n" /* line 760 | state */
        "movl (%edx, %eax), %edx\n"
        "movl -0x94(%ebp), %ebx\n" /* mem, qe */
        "movl %edx, (%ebx, %eax)\n" /* qe */
        "addl $1, %ecx\n" /* line 759 */
        "movl 0x18(%esi), %eax\n" /* state */
        "cmpl %eax, %ecx\n"
        "jl .Lf1f0fcc_001f1f7e\n"
        ".Lf1f0fcc_001f1fa1:\n"
        "movl -0x94(%ebp), %edi\n" /* line 761 | mem, response_bound */
        "movl %edi, 0x18(%esp)\n" /* response_bound */
        "movl %eax, 0x14(%esp)\n"
        "movl 0xc(%esi), %eax\n" /* state */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x9c(%ebp), %eax\n" /* res */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x9c(%esi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x98(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl -0x74(%ebp), %edx\n" /* exc */
        "movl %edx, (%esp)\n"
        "calll filter_mem2\n"
        "movl 0x18(%esi), %eax\n" /* line 765 | state */
        "testl %eax, %eax\n"
        "jle .Lf1f0fcc_001f200b\n"
        "xorl %ecx, %ecx\n"
        ".Lf1f0fcc_001f1fe8:\n"
        "leal (, %ecx, 4), %eax\n"
        "movl 0xa4(%esi), %edx\n" /* line 766 | state */
        "movl (%edx, %eax), %edx\n"
        "movl -0x94(%ebp), %ebx\n" /* mem, qe */
        "movl %edx, (%ebx, %eax)\n" /* qe */
        "addl $1, %ecx\n" /* line 765 */
        "movl 0x18(%esi), %eax\n" /* state */
        "cmpl %ecx, %eax\n"
        "jg .Lf1f0fcc_001f1fe8\n"
        ".Lf1f0fcc_001f200b:\n"
        "movl -0x94(%ebp), %edi\n" /* line 767 | mem, response_bound */
        "movl %edi, 0x18(%esp)\n" /* response_bound */
        "movl %eax, 0x14(%esp)\n"
        "movl 0xc(%esi), %eax\n" /* state */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x78(%ebp), %eax\n" /* sw */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x9c(%esi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x98(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl -0x7c(%ebp), %edx\n" /* sp */
        "movl %edx, (%esp)\n"
        "calll filter_mem2\n"
        "movl 0xe0(%esi), %eax\n" /* line 769 | state */
        "testl %eax, %eax\n"
        "jne .Lf1f0fcc_001f207a\n"
        "movl 0x18(%esi), %edx\n" /* line 770 | state */
        "testl %edx, %edx\n"
        "jle .Lf1f0fcc_001f207a\n"
        "xorl %ebx, %ebx\n" /* qe */
        ".Lf1f0fcc_001f2059:\n"
        "leal (, %ebx, 4), %eax\n" /* line 769 */
        "movl 0xa4(%esi), %ecx\n" /* line 771 | state */
        "movl -0x94(%ebp), %edi\n" /* mem, response_bound */
        "movl (%edi, %eax), %edx\n" /* response_bound */
        "movl %edx, (%ecx, %eax)\n"
        "addl $1, %ebx\n" /* line 770 | qe */
        "cmpl %ebx, 0x18(%esi)\n" /* qe, state */
        "jg .Lf1f0fcc_001f2059\n"
        ".Lf1f0fcc_001f207a:\n"
        "movl 0xc(%esi), %ecx\n" /* line 774 | state */
        "testl %ecx, %ecx\n"
        "jle .Lf1f0fcc_001f20d5\n"
        "movl $1, %edx\n"
        ".Lf1f0fcc_001f2086:\n"
        "leal (, %edx, 4), %eax\n" /* line 260 */
        "movl -0x78(%ebp), %ecx\n" /* line 775 | sw */
        "movss -4(%eax, %ecx), %xmm0\n"
        "movl -0x9c(%ebp), %ebx\n" /* res, qe */
        "subss -4(%ebx, %eax), %xmm0\n" /* qe */
        "movl -0x98(%ebp), %edi\n" /* target, response_bound */
        "movss %xmm0, -4(%edi, %eax)\n" /* response_bound */
        "movl %edx, %eax\n"
        "addl $1, %edx\n"
        "cmpl %eax, 0xc(%esi)\n" /* line 774 | state */
        "jg .Lf1f0fcc_001f2086\n"
        "movl 0xc(%esi), %ecx\n" /* line 777 | state */
        "testl %ecx, %ecx\n"
        "jle .Lf1f0fcc_001f20d5\n"
        "xorl %eax, %eax\n"
        ".Lf1f0fcc_001f20c1:\n"
        "movl -0x74(%ebp), %edx\n" /* line 778 | exc */
        "movl $0, (%edx, %eax, 4)\n"
        "addl $1, %eax\n" /* line 777 */
        "movl 0xc(%esi), %ecx\n" /* state */
        "cmpl %eax, %ecx\n"
        "jg .Lf1f0fcc_001f20c1\n"
        ".Lf1f0fcc_001f20d5:\n"
        "movl 0xf4(%esi), %edx\n" /* line 781 | state */
        "movl 0xf0(%esi), %eax\n" /* state */
        "movl (%eax, %edx, 4), %ebx\n" /* qe */
        "movl 0x18(%ebx), %edi\n" /* qe, response_bound */
        "movl %edi, -0xac(%ebp)\n" /* response_bound */
        "testl %edi, %edi\n" /* response_bound */
        "je .Lf1f0fcc_001f26b9\n"
        /* { scope 3: bitrate */
        "movl (%ebx), %edx\n" /* line 785 | qe */
        "cmpl $-1, %edx\n"
        "je .Lf1f0fcc_001f2624\n"
        "testl %edx, %edx\n" /* line 790 */
        "jne .Lf1f0fcc_001f25bb\n"
        "movl -0x6c(%ebp), %edi\n" /* pit_min */
        "movl %edi, %edx\n" /* pit_min */
        ".Lf1f0fcc_001f210d:\n"
        "movl 0x28(%esi), %eax\n" /* line 807 | state */
        "testl %eax, %eax\n"
        "je .Lf1f0fcc_001f211b\n"
        "cmpl -0x80(%ebp), %edx\n" /* offset */
        "cmovgl -0x80(%ebp), %edx\n" /* offset */
        ".Lf1f0fcc_001f211b:\n"
        "movl 0xe8(%esi), %eax\n" /* line 824 | state */
        "movl %eax, 0x48(%esp)\n"
        "movl $0, 0x44(%esp)\n"
        "movl 0xe0(%esi), %eax\n" /* state */
        "movl %eax, 0x40(%esp)\n"
        "movl -0x90(%ebp), %eax\n" /* syn_resp */
        "movl %eax, 0x3c(%esp)\n"
        "movl -0x74(%ebp), %eax\n" /* exc */
        "movl %eax, 0x38(%esp)\n"
        "movl -0x64(%ebp), %eax\n"
        "movl %eax, 0x34(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* bits */
        "movl %eax, 0x30(%esp)\n"
        "movl %ecx, 0x2c(%esp)\n"
        "movl 0x18(%esi), %eax\n" /* state */
        "movl %eax, 0x28(%esp)\n"
        "movss -0xa4(%ebp), %xmm0\n" /* ol_pitch_coef */
        "movss %xmm0, 0x24(%esp)\n"
        "movl %edx, 0x20(%esp)\n"
        "movl %edi, 0x1c(%esp)\n" /* pit_min */
        "movl 0x20(%ebx), %eax\n" /* qe */
        "movl %eax, 0x18(%esp)\n"
        "movl -0x74(%ebp), %eax\n" /* exc */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x9c(%esi), %eax\n" /* state */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x98(%esi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x94(%esi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl -0x78(%ebp), %edx\n" /* sw */
        "movl %edx, 4(%esp)\n"
        "movl -0x98(%ebp), %ecx\n" /* target */
        "movl %ecx, (%esp)\n"
        "calll *-0xac(%ebp)\n"
        "movl 0x34(%esi), %edx\n" /* line 829 | state */
        "movl -0xa8(%ebp), %ebx\n" /* sub, qe */
        "movl %eax, (%edx, %ebx, 4)\n"
        /* } scope */
        /* { scope 3: bitrate */
        ".Lf1f0fcc_001f21c5:\n"
        "movl 0xc(%esi), %ecx\n" /* line 840 | state */
        "movl -0xa8(%ebp), %edx\n" /* sub */
        "imull %ecx, %edx\n"
        "movl 0x64(%esi), %eax\n" /* state */
        "leal (%eax, %edx, 4), %edi\n" /* innov */
        "testl %ecx, %ecx\n" /* line 841 */
        "jle .Lf1f0fcc_001f2226\n"
        "xorl %eax, %eax\n"
        ".Lf1f0fcc_001f21dd:\n"
        "movl $0, (%edi, %eax, 4)\n" /* line 842 | innov */
        "addl $1, %eax\n" /* line 841 */
        "cmpl %eax, 0xc(%esi)\n" /* state */
        "jg .Lf1f0fcc_001f21dd\n"
        "movl 0xc(%esi), %ecx\n" /* line 844 | state */
        "testl %ecx, %ecx\n"
        "jle .Lf1f0fcc_001f2226\n"
        "movl $1, %ebx\n" /* qe */
        ".Lf1f0fcc_001f21f8:\n"
        "leal (, %ebx, 4), %eax\n" /* line 260 */
        "movl -0x8c(%ebp), %edx\n" /* real_exc */
        "addl %eax, %edx\n"
        "movss -4(%edx), %xmm0\n" /* line 845 */
        "movl -0x74(%ebp), %ecx\n" /* exc */
        "subss -4(%ecx, %eax), %xmm0\n"
        "movss %xmm0, -4(%edx)\n"
        "movl %ebx, %eax\n" /* qe */
        "movl 0xc(%esi), %ecx\n" /* line 844 | state */
        "addl $1, %ebx\n" /* qe */
        "cmpl %ecx, %eax\n"
        "jl .Lf1f0fcc_001f21f8\n"
        ".Lf1f0fcc_001f2226:\n"
        "movl %ecx, 4(%esp)\n" /* line 847 */
        "movl -0x8c(%ebp), %ebx\n" /* real_exc, qe */
        "movl %ebx, (%esp)\n" /* qe */
        "calll compute_rms\n"
        "fstps -0x10c(%ebp)\n"
        "movss -0x10c(%ebp), %xmm0\n"
        "divss -0x5c(%ebp), %xmm0\n" /* line 859 */
        "movl 0xf4(%esi), %eax\n" /* line 862 | state */
        "movl 0xf0(%esi), %edx\n" /* state */
        "movl (%edx, %eax, 4), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1f0fcc_001f2524\n"
        "movss -0x5c(%ebp), %xmm0\n"
        "movss %xmm0, -0x70(%ebp)\n" /* ener */
        ".Lf1f0fcc_001f226f:\n"
        "movl 0xc(%esi), %eax\n" /* line 882 | state */
        "movl %eax, 0xc(%esp)\n"
        "movss %xmm0, 8(%esp)\n"
        "movl -0x98(%ebp), %eax\n" /* target */
        "movl %eax, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll signal_div\n"
        "movl 0xf4(%esi), %edx\n" /* line 885 | state */
        "movl 0xf0(%esi), %eax\n" /* state */
        "movl (%eax, %edx, 4), %edx\n"
        "movl 0x24(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf1f0fcc_001f262f\n"
        "movl 0xc(%edx), %eax\n" /* line 890 */
        "movl %eax, 0x30(%esp)\n"
        "movl 0xe0(%esi), %eax\n" /* state */
        "movl %eax, 0x2c(%esp)\n"
        "movl -0x64(%ebp), %ebx\n" /* qe */
        "movl %ebx, 0x28(%esp)\n" /* qe */
        "movl 0x10(%ebp), %eax\n" /* bits */
        "movl %eax, 0x24(%esp)\n"
        "movl -0x90(%ebp), %ebx\n" /* syn_resp, qe */
        "movl %ebx, 0x20(%esp)\n" /* qe */
        "movl %edi, 0x1c(%esp)\n" /* innov */
        "movl 0xc(%esi), %eax\n" /* state */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x18(%esi), %eax\n" /* state */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x2c(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x9c(%esi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x98(%esi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x94(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl -0x98(%ebp), %eax\n" /* target */
        "movl %eax, (%esp)\n"
        "calll *%ecx\n"
        "movl 0xc(%esi), %eax\n" /* line 893 | state */
        "movl %eax, 0xc(%esp)\n"
        "movss -0x70(%ebp), %xmm0\n" /* ener */
        "movss %xmm0, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* innov */
        "movl %edi, (%esp)\n" /* innov */
        "calll signal_mul\n"
        "movl 0xc(%esi), %ebx\n" /* line 895 | state, qe */
        "testl %ebx, %ebx\n" /* qe */
        "jle .Lf1f0fcc_001f2363\n"
        "movl $1, %ecx\n"
        ".Lf1f0fcc_001f233d:\n"
        "leal (, %ecx, 4), %eax\n" /* line 260 */
        "movl -0x74(%ebp), %edx\n" /* exc */
        "addl %eax, %edx\n"
        "movss -4(%edx), %xmm0\n" /* line 896 */
        "addss -4(%edi, %eax), %xmm0\n" /* innov */
        "movss %xmm0, -4(%edx)\n"
        "movl %ecx, %eax\n"
        "addl $1, %ecx\n"
        "cmpl %eax, 0xc(%esi)\n" /* line 895 | state */
        "jg .Lf1f0fcc_001f233d\n"
        ".Lf1f0fcc_001f2363:\n"
        "movl 0xf4(%esi), %ebx\n" /* line 902 | state, qe */
        "movl 0xf0(%esi), %edx\n" /* state */
        "movl (%edx, %ebx, 4), %eax\n"
        "movl 0xc(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf1f0fcc_001f24bb\n"
        /* { scope 4 */
        "movl -0x64(%ebp), %eax\n" /* line 905 */
        "negl %eax\n"
        "andl $3, %eax\n"
        "addl -0x64(%ebp), %eax\n"
        "movl 0xc(%esi), %ecx\n" /* state */
        "leal (%eax, %ecx, 4), %edi\n" /* innov2 */
        "movl %edi, -0x60(%ebp)\n" /* innov2 */
        "movl %eax, %edi\n" /* innov2 */
        "testl %ecx, %ecx\n" /* line 906 */
        "jle .Lf1f0fcc_001f23f2\n"
        "xorl %eax, %eax\n"
        ".Lf1f0fcc_001f2399:\n"
        "movl $0, (%edi, %eax, 4)\n" /* line 907 | innov2 */
        "addl $1, %eax\n" /* line 906 */
        "cmpl 0xc(%esi), %eax\n" /* state */
        "jl .Lf1f0fcc_001f2399\n"
        "movl 0xc(%esi), %ecx\n" /* line 908 | state */
        "testl %ecx, %ecx\n"
        "jle .Lf1f0fcc_001f23e6\n"
        "movl $1, %ebx\n" /* qe */
        "movsd 0x307f30, %xmm1\n" /* 2.2 */
        "movl -0x98(%ebp), %edx\n" /* target */
        "addl $4, %edx\n"
        ".Lf1f0fcc_001f23c5:\n"
        "cvtss2sd -4(%edx), %xmm0\n" /* line 909 */
        "mulsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -4(%edx)\n"
        "movl %ebx, %eax\n" /* qe */
        "movl 0xc(%esi), %ecx\n" /* line 908 | state */
        "addl $1, %ebx\n" /* qe */
        "addl $4, %edx\n"
        "cmpl %ecx, %eax\n"
        "jl .Lf1f0fcc_001f23c5\n"
        ".Lf1f0fcc_001f23e6:\n"
        "movl 0xf4(%esi), %ebx\n" /* state, qe */
        "movl 0xf0(%esi), %edx\n" /* state */
        ".Lf1f0fcc_001f23f2:\n"
        "movl (%edx, %ebx, 4), %edx\n" /* line 912 */
        "movl $0, 0x30(%esp)\n"
        "movl 0xe0(%esi), %eax\n" /* state */
        "movl %eax, 0x2c(%esp)\n"
        "movl -0x60(%ebp), %eax\n"
        "movl %eax, 0x28(%esp)\n"
        "movl 0x10(%ebp), %ebx\n" /* bits, qe */
        "movl %ebx, 0x24(%esp)\n" /* qe */
        "movl -0x90(%ebp), %eax\n" /* syn_resp */
        "movl %eax, 0x20(%esp)\n"
        "movl %edi, 0x1c(%esp)\n" /* innov2 */
        "movl %ecx, 0x18(%esp)\n"
        "movl 0x18(%esi), %eax\n" /* state */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x2c(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x9c(%esi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x98(%esi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x94(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl -0x98(%ebp), %ecx\n" /* target */
        "movl %ecx, (%esp)\n"
        "calll *0x24(%edx)\n"
        "movl 0xc(%esi), %eax\n" /* line 913 | state */
        "movl %eax, 0xc(%esp)\n"
        "cvtss2sd -0x70(%ebp), %xmm0\n" /* ener */
        "mulsd 0x307f38, %xmm0\n" /* 0.45454545454545453 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* innov2 */
        "movl %edi, (%esp)\n" /* innov2 */
        "calll signal_mul\n"
        "movl 0xc(%esi), %edx\n" /* line 914 | state */
        "testl %edx, %edx\n"
        "jle .Lf1f0fcc_001f24bb\n"
        "movl $1, %ecx\n"
        ".Lf1f0fcc_001f2495:\n"
        "leal (, %ecx, 4), %eax\n" /* line 260 */
        "movl -0x74(%ebp), %edx\n" /* exc */
        "addl %eax, %edx\n"
        "movss -4(%edx), %xmm0\n" /* line 915 */
        "addss -4(%edi, %eax), %xmm0\n" /* innov2 */
        "movss %xmm0, -4(%edx)\n"
        "movl %ecx, %eax\n"
        "addl $1, %ecx\n"
        "cmpl 0xc(%esi), %eax\n" /* line 914 | state */
        "jl .Lf1f0fcc_001f2495\n"
        /* } scope */
        /* } scope */
        ".Lf1f0fcc_001f24bb:\n"
        "movl 0xa0(%esi), %eax\n" /* line 922 | state */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x18(%esi), %eax\n" /* state */
        "movl %eax, 0x10(%esp)\n"
        "movl 0xc(%esi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x7c(%ebp), %ebx\n" /* sp, qe */
        "movl %ebx, 8(%esp)\n" /* qe */
        "movl 0x94(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl -0x74(%ebp), %edi\n" /* exc, innov2 */
        "movl %edi, (%esp)\n" /* innov2 */
        "calll iir_mem2\n"
        "movl 0xe0(%esi), %eax\n" /* line 925 | state */
        "testl %eax, %eax\n"
        "jne .Lf1f0fcc_001f25e4\n"
        /* } scope */
        ".Lf1f0fcc_001f24fd:\n"
        "addl $1, -0xa8(%ebp)\n" /* line 673 | sub */
        "movl 0x10(%esi), %edx\n" /* state */
        "cmpl %edx, -0xa8(%ebp)\n" /* sub */
        "jge .Lf1f0fcc_001f1607\n"
        "movl 0x18(%esi), %ecx\n" /* state */
        "movl 0xc(%esi), %edi\n" /* state, w_sig */
        "movl %edi, -0xd0(%ebp)\n" /* w_sig */
        "jmp .Lf1f0fcc_001f1cae\n"
        /* { scope 2: mode, choice, ener */
        /* { scope 3: bitrate */
        /* { scope 4 */
        ".Lf1f0fcc_001f2524:\n"
        "cmpl $3, %eax\n" /* line 865 */
        "je .Lf1f0fcc_001f2640\n"
        "movl $2, 8(%esp)\n" /* line 871 */
        "movl $exc_gain_quant_scal1_bound, 4(%esp)\n"
        "movss %xmm0, (%esp)\n"
        "calll scal_quant\n"
        "movl %eax, %ebx\n" /* qe */
        "movl $1, 8(%esp)\n" /* line 872 */
        "movl %eax, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* bits */
        "movl %eax, (%esp)\n"
        "calll speex_bits_pack\n"
        "movss -0x5c(%ebp), %xmm0\n" /* line 873 */
        "mulss exc_gain_quant_scal1(, %ebx, 4), %xmm0\n"
        "movss %xmm0, -0x70(%ebp)\n" /* ener */
        "jmp .Lf1f0fcc_001f226f\n"
        /* } scope */
        /* } scope */
        /* { scope 3: bitrate */
        ".Lf1f0fcc_001f2578:\n"
        "movss 0x2ed5d0, %xmm1\n" /* line 714 | 1.0f */
        "jmp .Lf1f0fcc_001f1df0\n"
        /* } scope */
        ".Lf1f0fcc_001f2585:\n"
        "movl 0x9c(%esi), %eax\n" /* line 729 | state */
        "movl $0x3f800000, (%eax)\n"
        "movl 0x18(%esi), %eax\n" /* line 730 | state */
        "testl %eax, %eax\n"
        "jle .Lf1f0fcc_001f1e5e\n"
        "movl $1, %edx\n"
        ".Lf1f0fcc_001f25a1:\n"
        "movl 0x9c(%esi), %eax\n" /* line 731 | state */
        "movl $0, (%eax, %edx, 4)\n"
        "addl $1, %edx\n" /* line 730 */
        "cmpl %edx, 0x18(%esi)\n" /* state */
        "jge .Lf1f0fcc_001f25a1\n"
        "jmp .Lf1f0fcc_001f1e5e\n"
        /* { scope 3: bitrate */
        ".Lf1f0fcc_001f25bb:\n"
        "movl %edx, %eax\n" /* line 792 */
        "addl 0x1c(%esi), %eax\n" /* state */
        "subl $1, %eax\n"
        "cmpl %eax, -0x6c(%ebp)\n"
        "cmovgel -0x6c(%ebp), %eax\n"
        "movl 0x20(%esi), %edi\n" /* line 794 | state, pit_min */
        "subl %edx, %edi\n" /* pit_min */
        "cmpl %edi, %eax\n" /* pit_min */
        "cmovgl %edi, %eax\n" /* pit_min */
        "movl %eax, -0x6c(%ebp)\n"
        "subl %edx, %eax\n" /* line 796 */
        "leal 1(%eax), %edi\n" /* pit_min */
        "addl -0x6c(%ebp), %edx\n" /* line 797 */
        "jmp .Lf1f0fcc_001f210d\n"
        /* } scope */
        ".Lf1f0fcc_001f25e4:\n"
        "movl 0xa4(%esi), %eax\n" /* line 926 | state */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x18(%esi), %eax\n" /* state */
        "movl %eax, 0x14(%esp)\n"
        "movl 0xc(%esi), %eax\n" /* state */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x78(%ebp), %eax\n" /* sw */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x9c(%esi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x98(%esi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* qe */
        "calll filter_mem2\n"
        "jmp .Lf1f0fcc_001f24fd\n"
        /* { scope 3: bitrate */
        ".Lf1f0fcc_001f2624:\n"
        "movl 0x1c(%esi), %edi\n" /* line 802 | state, pit_min */
        "movl 0x20(%esi), %edx\n" /* line 803 | state */
        "jmp .Lf1f0fcc_001f210d\n"
        /* } scope */
        /* { scope 3: bitrate */
        ".Lf1f0fcc_001f262f:\n"
        "movl $0x2b9150, (%esp)\n" /* line 898 */
        "calll speex_error\n"
        "jmp .Lf1f0fcc_001f2363\n"
        /* { scope 4 */
        ".Lf1f0fcc_001f2640:\n"
        "movl $8, 8(%esp)\n" /* line 867 */
        "movl $exc_gain_quant_scal3_bound, 4(%esp)\n"
        "movss %xmm0, (%esp)\n"
        "calll scal_quant\n"
        "movl %eax, %ebx\n" /* qe */
        "movl $3, 8(%esp)\n" /* line 868 */
        "movl %eax, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* bits */
        "movl %eax, (%esp)\n"
        "calll speex_bits_pack\n"
        "movss -0x5c(%ebp), %xmm0\n" /* line 869 */
        "mulss exc_gain_quant_scal3(, %ebx, 4), %xmm0\n"
        "movss %xmm0, -0x70(%ebp)\n" /* ener */
        "jmp .Lf1f0fcc_001f226f\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1f0fcc_001f268b:\n"
        "movl 0xcc(%esi), %eax\n" /* line 941 | state */
        "testl %eax, %eax\n"
        "jne .Lf1f0fcc_001f27c6\n"
        "movl $4, 8(%esp)\n" /* line 944 */
        "movl $0, 4(%esp)\n"
        "movl 0x10(%ebp), %ecx\n" /* bits */
        "movl %ecx, (%esp)\n"
        "calll speex_bits_pack\n"
        "jmp .Lf1f0fcc_001f166c\n"
        /* { scope 2: mode, choice, ener */
        ".Lf1f0fcc_001f26b9:\n"
        "movl $0x2b912c, (%esp)\n" /* line 831 */
        "calll speex_error\n"
        "jmp .Lf1f0fcc_001f21c5\n"
        /* } scope */
        /* { scope 2: mode, choice, ener */
        /* { scope 3: bitrate */
        ".Lf1f0fcc_001f26ca:\n"
        "movl $0, 0xcc(%esi)\n" /* line 518 | state */
        "movl 0xf8(%esi), %eax\n" /* line 519 | state */
        ".Lf1f0fcc_001f26da:\n"
        "movl %eax, 0xf4(%esi)\n" /* line 522 | state */
        "jmp .Lf1f0fcc_001f13e2\n"
        /* } scope */
        /* { scope 3: bitrate */
        ".Lf1f0fcc_001f26e5:\n"
        "movl $0x41200000, 0xb8(%esi)\n" /* line 447 | state */
        "jmp .Lf1f0fcc_001f17aa\n"
        /* } scope */
        /* { scope 3: bitrate */
        ".Lf1f0fcc_001f26f4:\n"
        "movl 0xcc(%esi), %eax\n" /* line 481 | state */
        "testl %eax, %eax\n"
        "je .Lf1f0fcc_001f27fa\n"
        "cvtss2sd -0x88(%ebp), %xmm0\n" /* lsp_dist */
        "ucomisd 0x307e08, %xmm0\n" /* 0.05 */
        "ja .Lf1f0fcc_001f27fa\n"
        "movl 0xc8(%esi), %ebx\n" /* state, i */
        "testl %ebx, %ebx\n" /* i */
        "je .Lf1f0fcc_001f27fa\n"
        "cmpl $0x14, %eax\n"
        "jg .Lf1f0fcc_001f27fa\n"
        "movl $0, -0x1c(%ebp)\n" /* line 486 | mode */
        "addl $1, %eax\n" /* line 487 */
        "movl %eax, 0xcc(%esi)\n" /* state */
        "jmp .Lf1f0fcc_001f1a77\n"
        /* } scope */
        /* } scope */
        /* { scope 2: mode, choice, ener */
        ".Lf1f0fcc_001f2744:\n"
        "movl %ecx, %edi\n" /* line 366 | w_sig */
        "subl %eax, %edi\n" /* w_sig */
        "cmpl $4, %edi\n" /* w_sig */
        "jle .Lf1f0fcc_001f133c\n"
        "jmp .Lf1f0fcc_001f16dd\n"
        /* } scope */
        /* { scope 2: mode, choice, ener */
        ".Lf1f0fcc_001f2756:\n"
        "movl $0xf, %eax\n" /* line 622 */
        "movsd 0x307e40, %xmm0\n" /* 15.0 */
        ".Lf1f0fcc_001f2763:\n"
        "movl $4, 8(%esp)\n" /* line 626 */
        "movl %eax, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* bits */
        "movl %eax, (%esp)\n"
        "movsd %xmm0, -0xe8(%ebp)\n"
        "calll speex_bits_pack\n"
        "movsd -0xe8(%ebp), %xmm0\n" /* line 627 */
        "mulsd 0x307f18, %xmm0\n" /* 0.066667 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0xa4(%ebp)\n" /* ol_pitch_coef */
        "jmp .Lf1f0fcc_001f14aa\n"
        /* } scope */
        /* { scope 2: mode, choice, ener */
        /* { scope 3: bitrate */
        ".Lf1f0fcc_001f27a3:\n"
        "movss 0x2ed72c, %xmm0\n" /* line 440 | 0.05000000074505806f */
        "movsd 0x307f08, %xmm2\n" /* 0.05000000074505806 */
        "ucomisd 0x307f10, %xmm2\n" /* line 442 | -0.05 */
        "jae .Lf1f0fcc_001f178d\n"
        "jmp .Lf1f0fcc_001f1783\n"
        /* } scope */
        /* } scope */
        ".Lf1f0fcc_001f27c6:\n"
        "movl $4, 8(%esp)\n" /* line 942 */
        "movl $0xf, 4(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* bits */
        "movl %edx, (%esp)\n"
        "calll speex_bits_pack\n"
        "jmp .Lf1f0fcc_001f166c\n"
        /* { scope 2: mode, choice, ener */
        /* { scope 3: bitrate */
        ".Lf1f0fcc_001f27e6:\n"
        "movl $1, 0xcc(%esi)\n" /* line 511 | state */
        "movl $1, %eax\n"
        "jmp .Lf1f0fcc_001f26da\n"
        /* } scope */
        /* { scope 3: bitrate */
        ".Lf1f0fcc_001f27fa:\n"
        "movl $1, -0x1c(%ebp)\n" /* line 483 | mode */
        "movl $1, 0xcc(%esi)\n" /* line 484 | state */
        "jmp .Lf1f0fcc_001f1a77\n"
        /* } scope */
        /* } scope */
        /* { scope 2: mode, choice, ener */
        ".Lf1f0fcc_001f2810:\n"
        "xorl %ebx, %ebx\n" /* line 642 | qe */
        "pxor %xmm0, %xmm0\n"
        "jmp .Lf1f0fcc_001f1510\n"
        /* } scope */
        /* { scope 2: mode, choice, ener */
        /* { scope 3: bitrate */
        ".Lf1f0fcc_001f281b:\n"
        "movaps %xmm3, %xmm0\n" /* line 436 */
        "jmp .Lf1f0fcc_001f178d\n"
        ".Lf1f0fcc_001f2823:\n"
        "movl $0, 0xb8(%esi)\n" /* line 449 | state */
        "jmp .Lf1f0fcc_001f17b7\n"
        /* } scope */
        /* } scope */
        /* { scope 2: mode, choice, ener */
        ".Lf1f0fcc_001f2832:\n"
        "movl %ecx, %edi\n" /* line 366 | w_sig */
        "subl %eax, %edi\n" /* w_sig */
        "cmpl $5, %edi\n" /* w_sig */
        "jle .Lf1f0fcc_001f133c\n"
        "movl %ecx, -0x6c(%ebp)\n"
        "jmp .Lf1f0fcc_001f135f\n"
        /* } scope */
        /* { scope 2: mode, choice, ener */
        ".Lf1f0fcc_001f2847:\n"
        "xorl %eax, %eax\n" /* line 624 */
        "pxor %xmm0, %xmm0\n"
        "jmp .Lf1f0fcc_001f2763\n"
    );
}

/* line 972 */
__attribute__((naked))
double * nb_decoder_init(const SpeexMode *m)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 972 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* m */
        /* { scope 1 */
        "movl (%edi), %esi\n" /* line 978 | m, mode */
        "movl $0x4070, (%esp)\n" /* line 985 */
        "calll speex_alloc\n"
        "movl %eax, %ebx\n" /* st */
        "testl %eax, %eax\n" /* line 986 */
        "je .Lf1f2852_001f2a7b\n"
        "leal 0x1f0(%eax), %eax\n" /* line 988 */
        "movl %eax, 0x2c(%ebx)\n" /* st */
        "movl %edi, (%ebx)\n" /* line 991 | m, st */
        "movl $1, 0x74(%ebx)\n" /* line 994 | st */
        "movl $1, 4(%ebx)\n" /* line 999 | st */
        "movl (%esi), %edi\n" /* line 1001 | mode, m */
        "movl %edi, 0xc(%ebx)\n" /* m, st */
        "movl (%esi), %eax\n" /* line 1002 | mode */
        "cltd\n"
        "idivl 4(%esi)\n" /* mode */
        "movl %eax, 0x14(%ebx)\n" /* st */
        "movl 4(%esi), %eax\n" /* line 1003 | mode */
        "movl %eax, 0x10(%ebx)\n" /* st */
        "movl 8(%esi), %eax\n" /* line 1004 | mode */
        "movl %eax, 0x18(%ebx)\n" /* st */
        "movl 0xc(%esi), %eax\n" /* line 1005 | mode */
        "movl %eax, 0x1c(%ebx)\n" /* st */
        "movl 0x10(%esi), %ecx\n" /* line 1006 | mode */
        "movl %ecx, 0x20(%ebx)\n" /* st */
        "leal 0x24(%esi), %eax\n" /* line 1008 | mode */
        "movl %eax, 0x78(%ebx)\n" /* st */
        "movl 0x64(%esi), %eax\n" /* line 1009 | mode */
        "movl %eax, 0x7c(%ebx)\n" /* st */
        "movl $0, 0x80(%ebx)\n" /* line 1011 | st */
        "leal (, %edi, 4), %edx\n" /* line 1014 */
        "movl %edx, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x30(%ebx)\n" /* st */
        "movl %eax, 0x34(%ebx)\n" /* line 1015 | st */
        "movl 0xc(%ebx), %eax\n" /* line 1016 | st */
        "addl 0x20(%ebx), %eax\n" /* st */
        "leal 4(, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x38(%ebx)\n" /* st */
        "movl 0x20(%ebx), %ecx\n" /* line 1017 | st */
        "leal 4(%eax, %ecx, 4), %eax\n"
        "movl %eax, 0x3c(%ebx)\n" /* st */
        "movl 0xc(%ebx), %eax\n" /* line 1018 | st */
        "testl %eax, %eax\n"
        "jle .Lf1f2852_001f2920\n"
        "xorl %edx, %edx\n"
        ".Lf1f2852_001f290b:\n"
        "movl 0x30(%ebx), %eax\n" /* line 1019 | st */
        "movl $0, (%eax, %edx, 4)\n"
        "addl $1, %edx\n" /* line 1018 */
        "cmpl 0xc(%ebx), %edx\n" /* st */
        "jl .Lf1f2852_001f290b\n"
        "movl 0x20(%ebx), %ecx\n" /* st */
        ".Lf1f2852_001f2920:\n"
        "movl 0xc(%ebx), %edx\n" /* line 1020 | st */
        "leal 1(%edx, %ecx), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf1f2852_001f2a58\n"
        ".Lf1f2852_001f292f:\n"
        "leal (, %edx, 4), %eax\n" /* line 1022 */
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x40(%ebx)\n" /* st */
        "movl 0x18(%ebx), %eax\n" /* line 1024 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x50(%ebx)\n" /* st */
        "movl 0x18(%ebx), %eax\n" /* line 1025 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x44(%ebx)\n" /* st */
        "movl 0x18(%ebx), %eax\n" /* line 1026 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x48(%ebx)\n" /* st */
        "movl 0x18(%ebx), %eax\n" /* line 1027 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x4c(%ebx)\n" /* st */
        "movl 0x18(%ebx), %eax\n" /* line 1028 | st */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x54(%ebx)\n" /* st */
        "movl $0x14, (%esp)\n" /* line 1029 */
        "calll speex_alloc\n"
        "movl %eax, 0x84(%ebx)\n" /* st */
        "movl %eax, (%esp)\n" /* line 1030 */
        "calll comb_filter_mem_init\n"
        "movl 0x14(%ebx), %eax\n" /* line 1032 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x58(%ebx)\n" /* st */
        "movl $0x28, 0x5c(%ebx)\n" /* line 1033 | st */
        "movl $0, 8(%ebx)\n" /* line 1034 | st */
        "xorl %eax, %eax\n" /* line 1035 */
        "movl %eax, 0x6c(%ebx)\n" /* st */
        "movl %eax, 0x68(%ebx)\n" /* st */
        "movl %eax, 0x64(%ebx)\n" /* st */
        "movl $0, 0x70(%ebx)\n" /* line 1036 | st */
        "movl $0x1f40, 0x24(%ebx)\n" /* line 1038 | st */
        "movl %eax, 0x28(%ebx)\n" /* line 1039 | st */
        "movl 0x195f9a8, %eax\n" /* line 1041 */
        "movl %eax, 0x1cc(%ebx)\n" /* st */
        "movl $0, 0x1d0(%ebx)\n" /* line 1042 | st */
        "movl %ebx, %eax\n" /* st */
        "movl $0x10, %edx\n"
        ".Lf1f2852_001f2a0a:\n"
        "movl $0, 0x8c(%eax)\n" /* line 1044 */
        "addl $0x14, %eax\n"
        "subl $1, %edx\n" /* line 1043 */
        "jne .Lf1f2852_001f2a0a\n"
        "movl $0, 0x1e4(%ebx)\n" /* line 1046 | st */
        "movl $0, 0x1e0(%ebx)\n" /* st */
        "movl $0, 0x1dc(%ebx)\n" /* st */
        "movl $0, 0x1e8(%ebx)\n" /* line 1047 | st */
        "movl $0, 0x1ec(%ebx)\n" /* line 1048 | st */
        "movl %ebx, %eax\n" /* line 1052 | st */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1053 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1f2852_001f2a58:\n"
        "xorl %ecx, %ecx\n" /* line 1020 */
        ".Lf1f2852_001f2a5a:\n"
        "movl 0x38(%ebx), %eax\n" /* line 1021 | st */
        "movl $0, (%eax, %ecx, 4)\n"
        "addl $1, %ecx\n" /* line 1020 */
        "movl 0xc(%ebx), %edx\n" /* st */
        "movl %edx, %eax\n"
        "addl 0x20(%ebx), %eax\n" /* st */
        "addl $1, %eax\n"
        "cmpl %eax, %ecx\n"
        "jl .Lf1f2852_001f2a5a\n"
        "jmp .Lf1f2852_001f292f\n"
        ".Lf1f2852_001f2a7b:\n"
        "xorl %eax, %eax\n" /* line 986 */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1053 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1055 */
__attribute__((naked))
double nb_decoder_destroy(double *state)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1055 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* state */
        "movl 0x30(%ebx), %eax\n" /* line 1060 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0x38(%ebx), %eax\n" /* line 1061 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0x40(%ebx), %eax\n" /* line 1062 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0x50(%ebx), %eax\n" /* line 1063 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0x44(%ebx), %eax\n" /* line 1064 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0x48(%ebx), %eax\n" /* line 1065 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0x4c(%ebx), %eax\n" /* line 1066 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0x54(%ebx), %eax\n" /* line 1067 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0x84(%ebx), %eax\n" /* line 1068 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl 0x58(%ebx), %eax\n" /* line 1069 | state */
        "movl %eax, (%esp)\n"
        "calll speex_free\n"
        "movl %ebx, 8(%ebp)\n" /* line 1071 | state */
        "addl $0x14, %esp\n" /* line 1072 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp speex_free\n" /* line 1071 */
    );
}

/* line 1189 */
__attribute__((naked))
int nb_decode(double *state, SpeexBits *bits, double *vout)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1189 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x13c, %esp\n"
        "movl 8(%ebp), %edi\n" /* state */
        /* { scope 1: advance, sub, awk1, awk2, ... */
        "movl 0x2c(%edi), %eax\n" /* line 1214 | state */
        "movl %eax, -0x9c(%ebp)\n" /* stack */
        "movl 0x74(%edi), %edx\n" /* line 1216 | state */
        "testl %edx, %edx\n"
        "je .Lf1f2b0e_001f2b4d\n"
        "movl 0xc(%ebp), %eax\n" /* line 1223 | bits */
        "testl %eax, %eax\n"
        "jne .Lf1f2b0e_001f2e65\n"
        "movl 0x1ec(%edi), %eax\n" /* state */
        "testl %eax, %eax\n"
        "je .Lf1f2b0e_001f3076\n"
        "movl $0, 0x7c(%edi)\n" /* line 1225 | state */
        ".Lf1f2b0e_001f2b4d:\n"
        "movl 0x38(%edi), %edx\n" /* line 1312 | state */
        "movl 0x20(%edi), %eax\n" /* state */
        "leal 4(, %eax, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%edi), %eax\n" /* state */
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll speex_move\n"
        "movl 0x7c(%edi), %edx\n" /* line 1315 | state */
        "movl 0x78(%edi), %eax\n" /* state */
        "movl (%eax, %edx, 4), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1f2b0e_001f3d9d\n"
        "movl 0xc(%ebp), %ecx\n" /* line 1352 | bits */
        "movl %ecx, 8(%esp)\n"
        "movl 0x18(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x44(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll *0x14(%edx)\n"
        "movl 8(%edi), %ebx\n" /* line 1355 | state, i */
        "testl %ebx, %ebx\n" /* i */
        "je .Lf1f2b0e_001f2c30\n"
        /* { scope 2: sp, ener, innov */
        "movl 0x18(%edi), %ebx\n" /* line 1358 | state, i */
        "pxor %xmm0, %xmm0\n"
        "testl %ebx, %ebx\n" /* i */
        "jle .Lf1f2b0e_001f2bde\n"
        "movl 0x48(%edi), %ecx\n" /* line 1359 | state */
        "movl 0x44(%edi), %edx\n" /* state */
        "xorl %eax, %eax\n"
        "pxor %xmm1, %xmm1\n"
        "movss 0x306480, %xmm2\n"
        ".Lf1f2b0e_001f2bc2:\n"
        "movss (%ecx, %eax, 4), %xmm0\n"
        "subss (%edx, %eax, 4), %xmm0\n"
        "andps %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addl $1, %eax\n" /* line 1358 */
        "cmpl %eax, %ebx\n" /* i */
        "jne .Lf1f2b0e_001f2bc2\n"
        "cvtss2sd %xmm1, %xmm0\n"
        ".Lf1f2b0e_001f2bde:\n"
        "mulsd 0x307f48, %xmm0\n" /* line 1361 | -0.2 */
        "movsd %xmm0, (%esp)\n"
        "calll exp\n"
        "fstpl -0x100(%ebp)\n"
        "movsd -0x100(%ebp), %xmm0\n"
        "mulsd 0x307e60, %xmm0\n" /* 0.6 */
        "cvtsd2ss %xmm0, %xmm1\n"
        "leal (%ebx, %ebx), %eax\n" /* line 1362 | i */
        "testl %eax, %eax\n"
        "jle .Lf1f2b0e_001f2c30\n"
        "xorl %edx, %edx\n"
        ".Lf1f2b0e_001f2c13:\n"
        "movl 0x54(%edi), %eax\n" /* line 1363 | state */
        "leal (%eax, %edx, 4), %eax\n"
        "movaps %xmm1, %xmm0\n"
        "mulss (%eax), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "addl $1, %edx\n" /* line 1362 */
        "movl 0x18(%edi), %eax\n" /* state */
        "addl %eax, %eax\n"
        "cmpl %edx, %eax\n"
        "jg .Lf1f2b0e_001f2c13\n"
        /* } scope */
        ".Lf1f2b0e_001f2c30:\n"
        "movl 4(%edi), %ecx\n" /* line 1368 | state */
        "testl %ecx, %ecx\n"
        "je .Lf1f2b0e_001f2f7c\n"
        ".Lf1f2b0e_001f2c3b:\n"
        "movl 0x18(%edi), %eax\n" /* line 1370 | state */
        "testl %eax, %eax\n"
        "jle .Lf1f2b0e_001f2c5f\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf1f2b0e_001f2c44:\n"
        "leal (, %ebx, 4), %edx\n" /* line 1368 */
        "movl 0x48(%edi), %ecx\n" /* line 1371 | state */
        "movl 0x44(%edi), %eax\n" /* state */
        "movl (%eax, %edx), %eax\n"
        "movl %eax, (%ecx, %edx)\n"
        "addl $1, %ebx\n" /* line 1370 | i */
        "cmpl %ebx, 0x18(%edi)\n" /* i, state */
        "jg .Lf1f2b0e_001f2c44\n"
        ".Lf1f2b0e_001f2c5f:\n"
        "movl 0x7c(%edi), %esi\n" /* line 1392 | state, exc */
        "movl 0x78(%edi), %edx\n" /* state */
        "movl (%edx, %esi, 4), %eax\n"
        "cmpl $-1, (%eax)\n"
        "jne .Lf1f2b0e_001f2f99\n"
        ".Lf1f2b0e_001f2c71:\n"
        "movl $0, -0xac(%ebp)\n" /* ol_pitch */
        "movl (%edx, %esi, 4), %eax\n" /* line 1397 */
        "movl 4(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1f2b0e_001f2fcb\n"
        ".Lf1f2b0e_001f2c89:\n"
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0xa8(%ebp)\n" /* ol_pitch_coef */
        ".Lf1f2b0e_001f2c95:\n"
        "movl $5, 4(%esp)\n" /* line 1407 */
        "movl 0xc(%ebp), %edx\n" /* bits */
        "movl %edx, (%esp)\n"
        "calll speex_bits_unpack_unsigned\n"
        "cvtsi2sdl %eax, %xmm0\n" /* line 1411 */
        "divsd 0x307f20, %xmm0\n" /* 3.5 */
        "movsd %xmm0, (%esp)\n"
        "calll exp\n"
        "fstpl -0xc8(%ebp)\n"
        "cvtsd2ss -0xc8(%ebp), %xmm0\n"
        "movss %xmm0, -0xb0(%ebp)\n" /* ol_gain */
        "movl 0x18(%edi), %ecx\n" /* line 1418 | state */
        "shll $2, %ecx\n"
        "movl $4, %esi\n" /* exc */
        "movl %esi, %eax\n" /* exc */
        "subl -0x9c(%ebp), %eax\n" /* stack */
        "andl $3, %eax\n"
        "addl -0x9c(%ebp), %eax\n" /* stack */
        "leal 4(%eax, %ecx), %eax\n"
        "movl %ecx, %ebx\n" /* i */
        "negl %ebx\n" /* i */
        "leal -4(%eax, %ebx), %edx\n"
        "movl %edx, -0x98(%ebp)\n" /* awk1 */
        "movl %esi, %edx\n" /* line 1419 | exc */
        "subl %eax, %edx\n"
        "andl $3, %edx\n"
        "addl %edx, %eax\n"
        "leal 4(%ecx, %eax), %edx\n"
        "leal -4(%ebx, %edx), %eax\n" /* i */
        "movl %eax, -0x94(%ebp)\n" /* awk2 */
        "movl %esi, %eax\n" /* line 1420 | exc */
        "subl %edx, %eax\n"
        "andl $3, %eax\n"
        "addl %eax, %edx\n"
        "leal 4(%ecx, %edx), %edx\n"
        "movl %edx, -0x44(%ebp)\n"
        "leal -4(%ebx, %edx), %ebx\n" /* i */
        "movl %ebx, -0x90(%ebp)\n" /* i, awk3 */
        "cmpl $1, 0x7c(%edi)\n" /* line 1422 | state */
        "je .Lf1f2b0e_001f3ecc\n"
        ".Lf1f2b0e_001f2d3d:\n"
        "cmpl $1, 0x7c(%edi)\n" /* line 1432 | state */
        "jle .Lf1f2b0e_001f2d4d\n"
        "movl $0, 0x1ec(%edi)\n" /* line 1433 | state */
        ".Lf1f2b0e_001f2d4d:\n"
        "movl 0x14(%edi), %edx\n" /* line 1436 | state */
        "testl %edx, %edx\n"
        "jg .Lf1f2b0e_001f3487\n"
        "movl $0x28, -0xa4(%ebp)\n" /* best_pitch */
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0x8c(%ebp)\n" /* pitch_average */
        ".Lf1f2b0e_001f2d6e:\n"
        "movl 0xc(%edi), %eax\n" /* line 1679 | state */
        "testl %eax, %eax\n"
        "jle .Lf1f2b0e_001f2dca\n"
        "xorl %ecx, %ecx\n"
        "movss 0x2edaa8, %xmm2\n" /* -32767.0f */
        "movss 0x2edaa4, %xmm1\n" /* 32767.0f */
        "jmp .Lf1f2b0e_001f2da3\n"
        /* { scope 2: sp, ener, innov */
        ".Lf1f2b0e_001f2d89:\n"
        "movaps %xmm2, %xmm3\n" /* line 1684 */
        "maxss %xmm0, %xmm3\n"
        "movaps %xmm3, %xmm0\n"
        "movl 0x10(%ebp), %eax\n" /* line 1686 | vout */
        "movss %xmm0, (%eax, %edx)\n"
        /* } scope */
        "addl $1, %ecx\n" /* line 1679 */
        "cmpl 0xc(%edi), %ecx\n" /* state */
        "jge .Lf1f2b0e_001f2dca\n"
        ".Lf1f2b0e_001f2da3:\n"
        "leal (, %ecx, 4), %edx\n"
        /* { scope 2: sp, ener, innov */
        "movl 0x34(%edi), %eax\n" /* line 1681 | state */
        "movss (%eax, %edx), %xmm0\n" /* sig */
        "ucomiss %xmm1, %xmm0\n" /* line 1682 */
        "jbe .Lf1f2b0e_001f2d89\n"
        "movaps %xmm1, %xmm0\n"
        "movl 0x10(%ebp), %eax\n" /* line 1686 | vout */
        "movss %xmm0, (%eax, %edx)\n"
        /* } scope */
        "addl $1, %ecx\n" /* line 1679 */
        "cmpl 0xc(%edi), %ecx\n" /* state */
        "jl .Lf1f2b0e_001f2da3\n"
        ".Lf1f2b0e_001f2dca:\n"
        "movl 0x18(%edi), %eax\n" /* line 1693 | state */
        "testl %eax, %eax\n"
        "jle .Lf1f2b0e_001f2dee\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf1f2b0e_001f2dd3:\n"
        "leal (, %ebx, 4), %edx\n"
        "movl 0x48(%edi), %ecx\n" /* line 1694 | state */
        "movl 0x44(%edi), %eax\n" /* state */
        "movl (%eax, %edx), %eax\n"
        "movl %eax, (%ecx, %edx)\n"
        "addl $1, %ebx\n" /* line 1693 | i */
        "cmpl 0x18(%edi), %ebx\n" /* state, i */
        "jl .Lf1f2b0e_001f2dd3\n"
        ".Lf1f2b0e_001f2dee:\n"
        "movl $0, 4(%edi)\n" /* line 1697 | state */
        "movl $0, 8(%edi)\n" /* line 1698 | state */
        "movl -0xa4(%ebp), %edx\n" /* line 1699 | best_pitch */
        "movl %edx, 0x5c(%edi)\n" /* state */
        "movss -0x8c(%ebp), %xmm0\n" /* line 1703 | pitch_average */
        "mulss 0x2ed604, %xmm0\n" /* 0.25f */
        "movss %xmm0, 0x60(%edi)\n" /* state */
        "movl 0x70(%edi), %edx\n" /* line 1705 | state */
        "movss %xmm0, 0x64(%edi, %edx, 4)\n" /* state */
        "addl $1, %edx\n"
        "xorl %eax, %eax\n" /* line 1707 */
        "cmpl $3, %edx\n"
        "cmovll %edx, %eax\n"
        "movl %eax, 0x70(%edi)\n" /* state */
        "movss -0xb0(%ebp), %xmm0\n" /* line 1709 | ol_gain */
        "movss %xmm0, 0x28(%edi)\n" /* state */
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf1f2b0e_001f2e40:\n"
        "addl $0x13c, %esp\n" /* line 1712 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: advance, sub, awk1, awk2, ... */
        /* { scope 2: sp, ener, innov */
        ".Lf1f2b0e_001f2e4b:\n"
        "movl %edi, 8(%esp)\n" /* line 1286 | state */
        "leal 0x88(%edi), %eax\n" /* state, ret */
        "movl %eax, 4(%esp)\n" /* ret */
        "movl %ebx, (%esp)\n" /* i */
        "calll speex_inband_handler\n"
        "testl %eax, %eax\n" /* line 1287 */
        "jne .Lf1f2b0e_001f2e40\n"
        /* } scope */
        ".Lf1f2b0e_001f2e65:\n"
        "movl 0xc(%ebp), %eax\n" /* line 1237 | bits */
        "movl %eax, (%esp)\n"
        "calll speex_bits_remaining\n"
        "cmpl $4, %eax\n"
        "jle .Lf1f2b0e_001f3f19\n"
        "movl $1, 4(%esp)\n" /* line 1239 */
        "movl 0xc(%ebp), %edx\n" /* bits */
        "movl %edx, (%esp)\n"
        "calll speex_bits_unpack_unsigned\n"
        "testl %eax, %eax\n" /* line 1240 */
        "je .Lf1f2b0e_001f2f16\n"
        /* { scope 2: sp, ener, innov */
        "movl $3, 4(%esp)\n" /* line 1244 */
        "movl 0xc(%ebp), %ecx\n" /* bits */
        "movl %ecx, (%esp)\n"
        "calll speex_bits_unpack_unsigned\n"
        "movl %eax, -0x20(%ebp)\n" /* advance */
        "leal -0x20(%ebp), %esi\n" /* line 1245 | advance, exc */
        "movl %esi, 8(%esp)\n" /* exc */
        "movl $1, 4(%esp)\n"
        "movl 0x195f998, %ebx\n" /* i */
        "movl %ebx, (%esp)\n" /* i */
        "calll speex_mode_query\n"
        "movl -0x20(%ebp), %eax\n" /* line 1246 | advance */
        "testl %eax, %eax\n"
        "js .Lf1f2b0e_001f3f23\n"
        "subl $4, %eax\n" /* line 1251 */
        "movl %eax, -0x20(%ebp)\n" /* advance */
        "movl %eax, 4(%esp)\n" /* line 1252 */
        "movl 0xc(%ebp), %eax\n" /* bits */
        "movl %eax, (%esp)\n"
        "calll speex_bits_advance\n"
        "movl 0xc(%ebp), %edx\n" /* line 1254 | bits */
        "movl %edx, (%esp)\n"
        "calll speex_bits_remaining\n"
        "cmpl $4, %eax\n"
        "jle .Lf1f2b0e_001f3f19\n"
        "movl $1, 4(%esp)\n" /* line 1256 */
        "movl 0xc(%ebp), %ecx\n" /* bits */
        "movl %ecx, (%esp)\n"
        "calll speex_bits_unpack_unsigned\n"
        "testl %eax, %eax\n" /* line 1257 */
        "jne .Lf1f2b0e_001f2ffb\n"
        /* } scope */
        ".Lf1f2b0e_001f2f16:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 1277 | bits, i */
        "movl %ebx, (%esp)\n" /* i */
        "calll speex_bits_remaining\n"
        "cmpl $3, %eax\n"
        "jle .Lf1f2b0e_001f3f19\n"
        "movl $4, 4(%esp)\n" /* line 1280 */
        "movl %ebx, (%esp)\n" /* i */
        "calll speex_bits_unpack_unsigned\n"
        "cmpl $0xf, %eax\n" /* line 1281 */
        "je .Lf1f2b0e_001f3f19\n"
        "cmpl $0xe, %eax\n" /* line 1284 */
        "je .Lf1f2b0e_001f2e4b\n"
        "cmpl $0xd, %eax\n" /* line 1289 */
        "jne .Lf1f2b0e_001f3f39\n"
        /* { scope 2: sp, ener, innov */
        "movl 0x1d0(%edi), %eax\n" /* line 1291 | state, ret */
        "movl %eax, 8(%esp)\n" /* ret */
        "movl %edi, 4(%esp)\n" /* state */
        "movl 0xc(%ebp), %eax\n" /* bits, ret */
        "movl %eax, (%esp)\n" /* ret */
        "calll *0x1cc(%edi)\n" /* state */
        "testl %eax, %eax\n" /* line 1292 */
        "je .Lf1f2b0e_001f2e65\n"
        "jmp .Lf1f2b0e_001f2e40\n"
        /* } scope */
        ".Lf1f2b0e_001f2f7c:\n"
        "movl 8(%edi), %edx\n" /* line 1368 | state */
        "testl %edx, %edx\n"
        "jne .Lf1f2b0e_001f2c3b\n"
        "movl 0x7c(%edi), %esi\n" /* line 1392 | state, exc */
        "movl 0x78(%edi), %edx\n" /* state */
        "movl (%edx, %esi, 4), %eax\n"
        "cmpl $-1, (%eax)\n"
        "je .Lf1f2b0e_001f2c71\n"
        ".Lf1f2b0e_001f2f99:\n"
        "movl 0x1c(%edi), %ebx\n" /* line 1394 | state, i */
        "movl $7, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* bits */
        "movl %eax, (%esp)\n"
        "calll speex_bits_unpack_unsigned\n"
        "addl %eax, %ebx\n" /* i */
        "movl %ebx, -0xac(%ebp)\n" /* i, ol_pitch */
        "movl 0x7c(%edi), %esi\n" /* state, exc */
        "movl 0x78(%edi), %edx\n" /* state */
        "movl (%edx, %esi, 4), %eax\n" /* line 1397 */
        "movl 4(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1f2b0e_001f2c89\n"
        ".Lf1f2b0e_001f2fcb:\n"
        "movl $4, 4(%esp)\n" /* line 1400 */
        "movl 0xc(%ebp), %eax\n" /* bits */
        "movl %eax, (%esp)\n"
        "calll speex_bits_unpack_unsigned\n"
        "cvtsi2sdl %eax, %xmm0\n" /* line 1401 */
        "mulsd 0x307f18, %xmm0\n" /* 0.066667 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0xa8(%ebp)\n" /* ol_pitch_coef */
        "jmp .Lf1f2b0e_001f2c95\n"
        /* { scope 2: sp, ener, innov */
        ".Lf1f2b0e_001f2ffb:\n"
        "movl $3, 4(%esp)\n" /* line 1259 */
        "movl 0xc(%ebp), %eax\n" /* bits */
        "movl %eax, (%esp)\n"
        "calll speex_bits_unpack_unsigned\n"
        "movl %eax, -0x20(%ebp)\n" /* advance */
        "movl %esi, 8(%esp)\n" /* line 1260 | exc */
        "movl $1, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* i */
        "calll speex_mode_query\n"
        "movl -0x20(%ebp), %eax\n" /* line 1261 | advance */
        "testl %eax, %eax\n"
        "js .Lf1f2b0e_001f3f46\n"
        "subl $4, %eax\n" /* line 1266 */
        "movl %eax, -0x20(%ebp)\n" /* advance */
        "movl %eax, 4(%esp)\n" /* line 1267 */
        "movl 0xc(%ebp), %edx\n" /* bits */
        "movl %edx, (%esp)\n"
        "calll speex_bits_advance\n"
        "movl $1, 4(%esp)\n" /* line 1268 */
        "movl 0xc(%ebp), %ecx\n" /* bits */
        "movl %ecx, (%esp)\n"
        "calll speex_bits_unpack_unsigned\n"
        "testl %eax, %eax\n" /* line 1269 */
        "je .Lf1f2b0e_001f2f16\n"
        "movl $0x2b91d4, (%esp)\n" /* line 1271 */
        "calll speex_warning\n"
        "movl $0xfffffffe, %eax\n"
        "jmp .Lf1f2b0e_001f2e40\n"
        /* } scope */
        /* { scope 2: sp, ener, innov */
        ".Lf1f2b0e_001f3076:\n"
        "cvtsi2sdl 8(%edi), %xmm0\n" /* line 1085 */
        "movapd %xmm0, %xmm1\n"
        "mulsd 0x307f40, %xmm1\n" /* -0.04 */
        "mulsd %xmm1, %xmm0\n"
        "movsd %xmm0, (%esp)\n"
        "calll exp\n"
        "fstpl -0xc0(%ebp)\n"
        "cvtsd2ss -0xc0(%ebp), %xmm0\n"
        "movss %xmm0, -0x74(%ebp)\n" /* fact */
        "movss 0x64(%edi), %xmm1\n" /* line 1086 */
        "movss 0x68(%edi), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf1f2b0e_001f3ead\n"
        "movss 0x6c(%edi), %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf1f2b0e_001f3f08\n"
        ".Lf1f2b0e_001f30c9:\n"
        "movaps %xmm0, %xmm1\n"
        ".Lf1f2b0e_001f30cc:\n"
        "movss 0x60(%edi), %xmm0\n" /* line 1087 */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf1f2b0e_001f30de\n"
        "movaps %xmm1, %xmm0\n" /* line 1088 */
        "movss %xmm1, 0x60(%edi)\n"
        ".Lf1f2b0e_001f30de:\n"
        "movaps %xmm0, %xmm1\n" /* line 1090 */
        "cvtss2sd %xmm0, %xmm0\n" /* line 1091 */
        "ucomisd 0x307e00, %xmm0\n" /* 0.95 */
        "jbe .Lf1f2b0e_001f30f7\n"
        "movss 0x2edaac, %xmm1\n" /* 0.949999988079071f */
        ".Lf1f2b0e_001f30f7:\n"
        "mulss -0x74(%ebp), %xmm1\n" /* line 1094 | fact */
        "cvtss2sd %xmm1, %xmm0\n"
        "addsd 0x307e80, %xmm0\n" /* 1e-15 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x48(%ebp)\n"
        "movl 0x38(%edi), %edx\n" /* line 1098 */
        "movl 0x20(%edi), %eax\n"
        "leal 4(, %eax, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%edi), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll speex_move\n"
        "movl 0x18(%edi), %ebx\n" /* line 1100 | i */
        "shll $2, %ebx\n" /* i */
        "movl $4, %ecx\n"
        "movl %ecx, %eax\n"
        "subl -0x9c(%ebp), %eax\n" /* stack */
        "andl $3, %eax\n"
        "addl -0x9c(%ebp), %eax\n" /* stack */
        "leal 4(%eax, %ebx), %eax\n"
        "movl %ebx, %esi\n" /* i */
        "negl %esi\n"
        "leal -4(%eax, %esi), %edx\n"
        "movl %edx, -0x80(%ebp)\n" /* awk1 */
        "movl %ecx, %edx\n" /* line 1101 */
        "subl %eax, %edx\n"
        "andl $3, %edx\n"
        "addl %edx, %eax\n"
        "leal 4(%ebx, %eax), %eax\n" /* i */
        "leal -4(%esi, %eax), %edx\n"
        "movl %edx, -0x7c(%ebp)\n" /* awk2 */
        "subl %eax, %ecx\n" /* line 1102 */
        "andl $3, %ecx\n"
        "addl %ecx, %eax\n"
        "leal 4(%ebx, %eax), %ebx\n" /* i */
        "leal -4(%esi, %ebx), %ebx\n" /* i */
        "movl %ebx, -0x78(%ebp)\n" /* i, awk3 */
        "movl 0x14(%edi), %eax\n" /* line 1104 */
        "testl %eax, %eax\n"
        "jle .Lf1f2b0e_001f3401\n"
        "movl $0, -0x84(%ebp)\n" /* sub */
        "cvtss2sd -0x48(%ebp), %xmm0\n"
        "movsd %xmm0, -0xe0(%ebp)\n"
        "cvtss2sd -0x74(%ebp), %xmm1\n" /* fact */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "subss -0x48(%ebp), %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "sqrtsd %xmm0, %xmm0\n"
        "mulsd %xmm0, %xmm1\n"
        "movsd %xmm1, -0xe8(%ebp)\n"
        "movl -0x84(%ebp), %eax\n" /* sub */
        /* { scope 3: k3, innov_gain, innov2 */
        ".Lf1f2b0e_001f31d3:\n"
        "imull 0x10(%edi), %eax\n" /* line 1111 */
        "shll $2, %eax\n"
        "movl 0x34(%edi), %edx\n"
        "addl %eax, %edx\n"
        "movl %edx, -0x70(%ebp)\n" /* sp */
        "movl %eax, %esi\n" /* line 1113 | exc */
        "addl 0x3c(%edi), %esi\n" /* exc */
        "movl 0x80(%edi), %eax\n" /* line 1117 */
        "testl %eax, %eax\n"
        "je .Lf1f2b0e_001f3270\n"
        /* { scope 4 */
        "movl 0x7c(%edi), %edx\n" /* line 1120 */
        "movl 0x78(%edi), %eax\n"
        "movl (%eax, %edx, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1f2b0e_001f3ef3\n"
        "movl 0x30(%eax), %edx\n" /* line 1122 */
        "movl 0x34(%eax), %ebx\n" /* line 1123 | i */
        "movss 0x38(%eax), %xmm1\n" /* line 1124 */
        "movss %xmm1, -0x6c(%ebp)\n" /* k3 */
        ".Lf1f2b0e_001f3212:\n"
        "movl 0x18(%edi), %eax\n" /* line 1129 */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x80(%ebp), %eax\n" /* awk1 */
        "movl %eax, 8(%esp)\n"
        "movl 0x50(%edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll bw_lpc\n"
        "movl 0x18(%edi), %eax\n" /* line 1130 */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x7c(%ebp), %edx\n" /* awk2 */
        "movl %edx, 8(%esp)\n"
        "movl 0x50(%edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* i */
        "calll bw_lpc\n"
        "movl 0x18(%edi), %eax\n" /* line 1131 */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x78(%ebp), %ecx\n" /* awk3 */
        "movl %ecx, 8(%esp)\n"
        "movl 0x50(%edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movss -0x6c(%ebp), %xmm0\n" /* k3 */
        "movss %xmm0, (%esp)\n"
        "calll bw_lpc\n"
        /* } scope */
        /* { scope 4 */
        ".Lf1f2b0e_001f3270:\n"
        "movl 0xc(%edi), %eax\n" /* line 1140 */
        "movl %eax, 4(%esp)\n"
        "movl 0x40(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll compute_rms\n"
        "fstps -0x68(%ebp)\n" /* innov_gain */
        "movl 0x10(%edi), %ebx\n" /* line 1141 | i */
        "testl %ebx, %ebx\n" /* i */
        "jg .Lf1f2b0e_001f3368\n"
        /* } scope */
        ".Lf1f2b0e_001f3290:\n"
        "movl 0x80(%edi), %eax\n" /* line 1158 */
        "testl %eax, %eax\n"
        "jne .Lf1f2b0e_001f32ff\n"
        "movl 0x18(%edi), %edx\n" /* line 1165 */
        "testl %edx, %edx\n"
        "jle .Lf1f2b0e_001f32bd\n"
        "xorl %ecx, %ecx\n"
        ".Lf1f2b0e_001f32a3:\n"
        "leal (%ecx, %edx), %edx\n" /* line 1166 */
        "movl 0x54(%edi), %eax\n"
        "movl $0, (%eax, %edx, 4)\n"
        "addl $1, %ecx\n" /* line 1165 */
        "movl 0x18(%edi), %edx\n"
        "cmpl %ecx, %edx\n"
        "jg .Lf1f2b0e_001f32a3\n"
        "movl 0x10(%edi), %ebx\n" /* i */
        ".Lf1f2b0e_001f32bd:\n"
        "movl 0x54(%edi), %eax\n" /* line 1168 */
        "movl %eax, 0x14(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* i */
        "movl -0x70(%ebp), %edx\n" /* sp */
        "movl %edx, 8(%esp)\n"
        "movl 0x50(%edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll iir_mem2\n"
        /* } scope */
        ".Lf1f2b0e_001f32e2:\n"
        "addl $1, -0x84(%ebp)\n" /* line 1104 | sub */
        "movl -0x84(%ebp), %ecx\n" /* sub */
        "cmpl 0x14(%edi), %ecx\n"
        "jge .Lf1f2b0e_001f3401\n"
        "movl %ecx, %eax\n"
        "jmp .Lf1f2b0e_001f31d3\n"
        /* { scope 3: k3, innov_gain, innov2 */
        ".Lf1f2b0e_001f32ff:\n"
        "movl 0x18(%edi), %edx\n" /* line 1161 */
        "movl 0x54(%edi), %eax\n"
        "leal (%eax, %edx, 4), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl %edx, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n" /* i */
        "movl -0x70(%ebp), %eax\n" /* sp */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x80(%ebp), %edx\n" /* awk1 */
        "movl %edx, 8(%esp)\n"
        "movl -0x7c(%ebp), %ecx\n" /* awk2 */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll filter_mem2\n"
        "movl 0x54(%edi), %eax\n" /* line 1163 */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x18(%edi), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edi), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x70(%ebp), %ebx\n" /* sp, i */
        "movl %ebx, 0xc(%esp)\n" /* i */
        "movl 0x50(%edi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x78(%ebp), %eax\n" /* awk3 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* i */
        "calll filter_mem2\n"
        "jmp .Lf1f2b0e_001f32e2\n"
        /* { scope 4 */
        ".Lf1f2b0e_001f3368:\n"
        "xorl %ebx, %ebx\n" /* line 1141 | i */
        ".Lf1f2b0e_001f336a:\n"
        "movl %ebx, %eax\n" /* line 1150 | i */
        "subl 0x5c(%edi), %eax\n"
        "cvtss2sd (%esi, %eax, 4), %xmm0\n" /* exc */
        "addsd 0x307e80, %xmm0\n" /* 1e-15 */
        "mulsd -0xe0(%ebp), %xmm0\n"
        "movss -0x68(%ebp), %xmm1\n" /* innov_gain */
        "movss %xmm1, (%esp)\n"
        "movsd %xmm0, -0xf8(%ebp)\n"
        "calll speex_rand\n"
        "fstps -0x88(%ebp)\n"
        "cvtss2sd -0x88(%ebp), %xmm1\n"
        "mulsd -0xe8(%ebp), %xmm1\n"
        "movsd -0xf8(%ebp), %xmm0\n"
        "addsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%esi, %ebx, 4)\n" /* exc */
        "addl $1, %ebx\n" /* line 1141 | i */
        "cmpl 0x10(%edi), %ebx\n" /* i */
        "jl .Lf1f2b0e_001f336a\n"
        /* } scope */
        "movl 0x10(%edi), %ebx\n" /* line 1154 | i */
        "testl %ebx, %ebx\n" /* i */
        "jle .Lf1f2b0e_001f3290\n"
        "movl $1, %ecx\n"
        ".Lf1f2b0e_001f33de:\n"
        "leal (, %ecx, 4), %eax\n" /* line 1189 */
        "movl -4(%eax, %esi), %edx\n" /* line 1155 */
        "movl -0x70(%ebp), %ebx\n" /* sp, i */
        "movl %edx, -4(%eax, %ebx)\n"
        "movl %ecx, %eax\n"
        "movl 0x10(%edi), %ebx\n" /* line 1154 | i */
        "addl $1, %ecx\n"
        "cmpl %ebx, %eax\n" /* i */
        "jl .Lf1f2b0e_001f33de\n"
        "jmp .Lf1f2b0e_001f3290\n"
        /* } scope */
        ".Lf1f2b0e_001f3401:\n"
        "movl 0xc(%edi), %eax\n" /* line 1172 */
        "testl %eax, %eax\n"
        "jle .Lf1f2b0e_001f344f\n"
        "xorl %ecx, %ecx\n"
        "movss 0x2edaa8, %xmm2\n" /* -32767.0f */
        "movss 0x2edaa4, %xmm1\n" /* 32767.0f */
        "jmp .Lf1f2b0e_001f3436\n"
        /* { scope 3: k3, innov_gain, innov2 */
        ".Lf1f2b0e_001f341c:\n"
        "movaps %xmm2, %xmm3\n" /* line 1177 */
        "maxss %xmm0, %xmm3\n"
        "movaps %xmm3, %xmm0\n"
        ".Lf1f2b0e_001f3426:\n"
        "movl 0x10(%ebp), %eax\n" /* line 1179 | vout */
        "movss %xmm0, (%eax, %edx)\n"
        /* } scope */
        "addl $1, %ecx\n" /* line 1172 */
        "cmpl 0xc(%edi), %ecx\n"
        "jge .Lf1f2b0e_001f344f\n"
        ".Lf1f2b0e_001f3436:\n"
        "leal (, %ecx, 4), %edx\n"
        /* { scope 3: k3, innov_gain, innov2 */
        "movl 0x34(%edi), %eax\n" /* line 1174 */
        "movss (%edx, %eax), %xmm0\n" /* sig */
        "ucomiss %xmm1, %xmm0\n" /* line 1175 */
        "jbe .Lf1f2b0e_001f341c\n"
        "movaps %xmm1, %xmm0\n"
        "jmp .Lf1f2b0e_001f3426\n"
        /* } scope */
        ".Lf1f2b0e_001f344f:\n"
        "movl $0, 4(%edi)\n" /* line 1182 */
        "addl $1, 8(%edi)\n" /* line 1183 */
        "movl 0x70(%edi), %eax\n" /* line 1184 */
        "movss -0x48(%ebp), %xmm0\n"
        "movss %xmm0, 0x64(%edi, %eax, 4)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x70(%edi)\n"
        "cmpl $2, %eax\n" /* line 1185 */
        "jle .Lf1f2b0e_001f347a\n"
        "movl $0, 0x70(%edi)\n" /* line 1186 */
        /* } scope */
        ".Lf1f2b0e_001f347a:\n"
        "xorl %eax, %eax\n" /* line 1347 */
        /* } scope */
        "addl $0x13c, %esp\n" /* line 1712 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: advance, sub, awk1, awk2, ... */
        /* { scope 2: sp, ener, innov */
        /* { scope 3: k3, innov_gain, innov2 */
        /* { scope 4 */
        ".Lf1f2b0e_001f3487:\n"
        "cvtss2sd -0xa8(%ebp), %xmm0\n" /* line 1618 | ol_pitch_coef */
        "subsd 0x307e60, %xmm0\n" /* 0.6 */
        "addsd %xmm0, %xmm0\n"
        "addsd 0x307ce0, %xmm0\n" /* 0.5 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0xa0(%ebp)\n" /* best_pitch_gain */
        "movl $0, -0xb4(%ebp)\n" /* sub */
        "movl $0x28, -0xa4(%ebp)\n" /* best_pitch */
        "movss %xmm0, -0x8c(%ebp)\n" /* pitch_average */
        "cvtsi2sdl -0xac(%ebp), %xmm1\n" /* ol_pitch */
        "movsd %xmm1, -0xd0(%ebp)\n"
        "cvtss2sd -0xb0(%ebp), %xmm3\n" /* ol_gain */
        "movsd %xmm3, -0xd8(%ebp)\n"
        "subl -0x44(%ebp), %esi\n" /* pit_min */
        "andl $3, %esi\n" /* pit_min */
        "addl -0x44(%ebp), %esi\n" /* pit_min */
        "movl %esi, -0x40(%ebp)\n" /* pit_min */
        /* } scope */
        /* } scope */
        ".Lf1f2b0e_001f3500:\n"
        "movl -0xb4(%ebp), %eax\n" /* line 1453 | sub */
        "imull 0x10(%edi), %eax\n" /* state */
        "movl %eax, -0x64(%ebp)\n" /* offset */
        "shll $2, %eax\n" /* line 1455 */
        "movl 0x34(%edi), %ecx\n" /* state */
        "addl %eax, %ecx\n"
        "movl %ecx, -0x60(%ebp)\n" /* sp */
        "addl 0x3c(%edi), %eax\n" /* line 1457 | state */
        "movl %eax, -0x5c(%ebp)\n" /* exc */
        "movl %edx, 0x14(%esp)\n" /* line 1461 */
        "movl -0xb4(%ebp), %ebx\n" /* sub, i */
        "movl %ebx, 0x10(%esp)\n" /* i */
        "movl 0x18(%edi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x4c(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x44(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x48(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll lsp_interpolate\n"
        "movl $0x3b03126f, 8(%esp)\n" /* line 1464 */
        "movl 0x18(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x4c(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll lsp_enforce_margin\n"
        "movl -0x44(%ebp), %eax\n" /* line 1468 */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x18(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x50(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x4c(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll lsp_to_lpc\n"
        "movl 0x80(%edi), %eax\n" /* line 1471 | state */
        "testl %eax, %eax\n"
        "jne .Lf1f2b0e_001f3aaf\n"
        /* { scope 3: k3, innov_gain, innov2 */
        ".Lf1f2b0e_001f3594:\n"
        "movl 0x18(%edi), %ecx\n" /* line 1481 | state */
        "testl %ecx, %ecx\n"
        "jle .Lf1f2b0e_001f3a77\n"
        "xorl %edx, %edx\n" /* line 1484 */
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "movl 0x50(%edi), %eax\n" /* state */
        ".Lf1f2b0e_001f35ac:\n"
        "movss 4(%eax), %xmm0\n"
        "subss (%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addl $2, %edx\n" /* line 1481 */
        "addl $8, %eax\n"
        "cmpl %edx, %ecx\n"
        "jg .Lf1f2b0e_001f35ac\n"
        ".Lf1f2b0e_001f35c3:\n"
        "movl 0x58(%edi), %eax\n" /* line 1486 | state */
        "movl -0xb4(%ebp), %edx\n" /* sub */
        "movss %xmm1, (%eax, %edx, 4)\n"
        /* } scope */
        "movl 0x10(%edi), %ecx\n" /* line 1490 | state */
        "testl %ecx, %ecx\n"
        "jle .Lf1f2b0e_001f35ee\n"
        "xorl %eax, %eax\n"
        ".Lf1f2b0e_001f35da:\n"
        "movl -0x5c(%ebp), %ecx\n" /* line 1491 | exc */
        "movl $0, (%ecx, %eax, 4)\n"
        "addl $1, %eax\n" /* line 1490 */
        "movl 0x10(%edi), %ecx\n" /* state */
        "cmpl %eax, %ecx\n"
        "jg .Lf1f2b0e_001f35da\n"
        ".Lf1f2b0e_001f35ee:\n"
        "movl 0x7c(%edi), %edx\n" /* line 1494 | state */
        "movl 0x78(%edi), %eax\n" /* state */
        "movl (%eax, %edx, 4), %ebx\n" /* i */
        "movl 0x1c(%ebx), %eax\n" /* i */
        "movl %eax, -0xb8(%ebp)\n"
        "testl %eax, %eax\n"
        "je .Lf1f2b0e_001f3d8c\n"
        /* { scope 3: k3, innov_gain, innov2 */
        "movl (%ebx), %edx\n" /* line 1498 | i */
        "cmpl $-1, %edx\n"
        "je .Lf1f2b0e_001f3ce6\n"
        "testl %edx, %edx\n" /* line 1502 */
        "jne .Lf1f2b0e_001f3a84\n"
        "movl -0xac(%ebp), %esi\n" /* ol_pitch, pit_min */
        "movl %esi, %edx\n" /* pit_min */
        ".Lf1f2b0e_001f3623:\n"
        "movl $0, 0x34(%esp)\n" /* line 1538 */
        "movl 0x60(%edi), %eax\n" /* state */
        "movl %eax, 0x30(%esp)\n"
        "movl -0x64(%ebp), %eax\n" /* offset */
        "movl %eax, 0x2c(%esp)\n"
        "movl 8(%edi), %eax\n" /* state */
        "movl %eax, 0x28(%esp)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 0x24(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* bits */
        "movl %eax, 0x20(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* pitch_gain */
        "movl %eax, 0x1c(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* pitch */
        "movl %eax, 0x18(%esp)\n"
        "movl %ecx, 0x14(%esp)\n"
        "movl 0x20(%ebx), %eax\n" /* i */
        "movl %eax, 0x10(%esp)\n"
        "movss -0xa8(%ebp), %xmm0\n" /* ol_pitch_coef */
        "movss %xmm0, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* pit_min */
        "movl -0x5c(%ebp), %eax\n" /* exc */
        "movl %eax, (%esp)\n"
        "calll *-0xb8(%ebp)\n"
        "movl 8(%edi), %eax\n" /* line 1546 | state */
        "testl %eax, %eax\n"
        "je .Lf1f2b0e_001f36de\n"
        "movss 0x28(%edi), %xmm0\n" /* state */
        "ucomiss -0xb0(%ebp), %xmm0\n" /* ol_gain */
        "jbe .Lf1f2b0e_001f36de\n"
        /* { scope 4 */
        "addss 0x2ed5d0, %xmm0\n" /* line 1548 | 1.0f */
        "movss -0xb0(%ebp), %xmm1\n" /* ol_gain, fact */
        "divss %xmm0, %xmm1\n" /* fact */
        "movl 0x10(%edi), %eax\n" /* line 1549 | state */
        "testl %eax, %eax\n"
        "jle .Lf1f2b0e_001f36de\n"
        "movl $1, %ecx\n"
        "movl -0x5c(%ebp), %edx\n" /* exc */
        "addl $4, %edx\n"
        ".Lf1f2b0e_001f36c4:\n"
        "movaps %xmm1, %xmm0\n" /* line 1550 */
        "mulss -4(%edx), %xmm0\n"
        "movss %xmm0, -4(%edx)\n"
        "movl %ecx, %eax\n"
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "cmpl %eax, 0x10(%edi)\n" /* line 1549 | state */
        "jg .Lf1f2b0e_001f36c4\n"
        /* } scope */
        ".Lf1f2b0e_001f36de:\n"
        "movss -0x28(%ebp), %xmm0\n" /* line 1553 */
        "pxor %xmm2, %xmm2\n"
        "andps 0x306480, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movss -0x2c(%ebp), %xmm1\n" /* pitch_gain */
        "ucomiss %xmm2, %xmm1\n"
        "jbe .Lf1f2b0e_001f3d02\n"
        "cvtss2sd %xmm1, %xmm1\n"
        ".Lf1f2b0e_001f3704:\n"
        "addsd %xmm1, %xmm0\n"
        "movss -0x24(%ebp), %xmm1\n"
        "ucomiss %xmm2, %xmm1\n"
        "jbe .Lf1f2b0e_001f3cf1\n"
        "cvtss2sd %xmm1, %xmm1\n"
        ".Lf1f2b0e_001f371a:\n"
        "addsd %xmm0, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm0\n"
        "movss -0x8c(%ebp), %xmm1\n" /* line 1555 | pitch_average */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x8c(%ebp)\n" /* pitch_average */
        "ucomiss -0xa0(%ebp), %xmm0\n" /* line 1556 | best_pitch_gain */
        "jbe .Lf1f2b0e_001f3750\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1558 | pitch */
        "movl %eax, -0xa4(%ebp)\n" /* best_pitch */
        "movss %xmm0, -0xa0(%ebp)\n" /* best_pitch_gain */
        /* } scope */
        /* { scope 3: k3, innov_gain, innov2 */
        ".Lf1f2b0e_001f3750:\n"
        "movl 0x10(%edi), %ecx\n" /* line 1571 | state */
        "movl -0xb4(%ebp), %edx\n" /* sub */
        "imull %ecx, %edx\n"
        "movl 0x40(%edi), %eax\n" /* state */
        "leal (%eax, %edx, 4), %edx\n"
        "movl %edx, -0x54(%ebp)\n" /* innov */
        "testl %ecx, %ecx\n" /* line 1572 */
        "jle .Lf1f2b0e_001f377d\n"
        "xorl %eax, %eax\n"
        ".Lf1f2b0e_001f376b:\n"
        "movl -0x54(%ebp), %edx\n" /* line 1573 | innov */
        "movl $0, (%edx, %eax, 4)\n"
        "addl $1, %eax\n" /* line 1572 */
        "cmpl 0x10(%edi), %eax\n" /* state */
        "jl .Lf1f2b0e_001f376b\n"
        ".Lf1f2b0e_001f377d:\n"
        "movl 0x7c(%edi), %esi\n" /* line 1576 | state, pit_min */
        "movl 0x78(%edi), %edx\n" /* state */
        "movl (%edx, %esi, 4), %eax\n"
        "movl 8(%eax), %eax\n"
        "cmpl $3, %eax\n"
        "je .Lf1f2b0e_001f3d24\n"
        "subl $1, %eax\n" /* line 1580 */
        "je .Lf1f2b0e_001f3d58\n"
        "movss -0xb0(%ebp), %xmm1\n" /* ol_gain */
        "movss %xmm1, -0x58(%ebp)\n" /* ener */
        ".Lf1f2b0e_001f37a8:\n"
        "movl (%edx, %esi, 4), %edx\n" /* line 1588 */
        "movl 0x28(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf1f2b0e_001f3d13\n"
        "movl -0x44(%ebp), %eax\n" /* line 1591 */
        "movl %eax, 0x10(%esp)\n"
        "movl 0xc(%ebp), %ebx\n" /* bits, i */
        "movl %ebx, 0xc(%esp)\n" /* i */
        "movl 0x10(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x2c(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x54(%ebp), %eax\n" /* innov */
        "movl %eax, (%esp)\n"
        "calll *%ecx\n"
        ".Lf1f2b0e_001f37da:\n"
        "movl 0x10(%edi), %eax\n" /* line 1600 | state */
        "movl %eax, 0xc(%esp)\n"
        "movss -0x58(%ebp), %xmm0\n" /* ener */
        "movss %xmm0, 8(%esp)\n"
        "movl -0x54(%ebp), %eax\n" /* innov */
        "movl %eax, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll signal_mul\n"
        "cmpl $1, 0x7c(%edi)\n" /* line 1603 | state */
        "je .Lf1f2b0e_001f3b38\n"
        "movl 0x10(%edi), %eax\n" /* line 1633 | state */
        "testl %eax, %eax\n"
        "jle .Lf1f2b0e_001f383a\n"
        "movl $1, %ecx\n"
        /* { scope 4 */
        ".Lf1f2b0e_001f3811:\n"
        "leal (, %ecx, 4), %eax\n" /* line 1189 */
        "movl -0x5c(%ebp), %edx\n" /* exc */
        "addl %eax, %edx\n"
        /* } scope */
        "movss -4(%edx), %xmm0\n" /* line 1634 */
        "movl -0x54(%ebp), %ebx\n" /* innov, i */
        "addss -4(%ebx, %eax), %xmm0\n" /* i */
        "movss %xmm0, -4(%edx)\n"
        "movl %ecx, %eax\n"
        "addl $1, %ecx\n"
        "cmpl %eax, 0x10(%edi)\n" /* line 1633 | state */
        "jg .Lf1f2b0e_001f3811\n"
        ".Lf1f2b0e_001f383a:\n"
        "movl 0x10(%edi), %ebx\n" /* state, i */
        ".Lf1f2b0e_001f383d:\n"
        "movl 0x7c(%edi), %esi\n" /* line 1638 | state, pit_min */
        "movl 0x78(%edi), %edx\n" /* state */
        "movl (%edx, %esi, 4), %eax\n"
        "movl 0xc(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf1f2b0e_001f3903\n"
        /* { scope 4 */
        "movl %ebx, %ecx\n" /* line 1642 | i */
        "movl -0x40(%ebp), %eax\n"
        "leal (%eax, %ebx, 4), %ebx\n" /* i */
        "movl %eax, -0x50(%ebp)\n" /* innov2 */
        "testl %ecx, %ecx\n" /* line 1643 */
        "jle .Lf1f2b0e_001f387c\n"
        "xorl %eax, %eax\n"
        ".Lf1f2b0e_001f3862:\n"
        "movl -0x50(%ebp), %edx\n" /* line 1644 | innov2 */
        "movl $0, (%edx, %eax, 4)\n"
        "addl $1, %eax\n" /* line 1643 */
        "movl 0x10(%edi), %ecx\n" /* state */
        "cmpl %ecx, %eax\n"
        "jl .Lf1f2b0e_001f3862\n"
        "movl 0x7c(%edi), %esi\n" /* state, pit_min */
        "movl 0x78(%edi), %edx\n" /* state */
        ".Lf1f2b0e_001f387c:\n"
        "movl (%edx, %esi, 4), %edx\n" /* line 1645 */
        "movl %ebx, 0x10(%esp)\n" /* i */
        "movl 0xc(%ebp), %ebx\n" /* bits, i */
        "movl %ebx, 0xc(%esp)\n" /* i */
        "movl %ecx, 8(%esp)\n"
        "movl 0x2c(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x50(%ebp), %eax\n" /* innov2 */
        "movl %eax, (%esp)\n"
        "calll *0x28(%edx)\n"
        "movl 0x10(%edi), %eax\n" /* line 1646 | state */
        "movl %eax, 0xc(%esp)\n"
        "cvtss2sd -0x58(%ebp), %xmm0\n" /* ener */
        "mulsd 0x307f38, %xmm0\n" /* 0.45454545454545453 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movl -0x50(%ebp), %edx\n" /* innov2 */
        "movl %edx, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll signal_mul\n"
        "movl 0x10(%edi), %ebx\n" /* line 1647 | state, i */
        "testl %ebx, %ebx\n" /* i */
        "jle .Lf1f2b0e_001f392d\n"
        "movl $1, %ecx\n"
        ".Lf1f2b0e_001f38d7:\n"
        "leal (, %ecx, 4), %eax\n" /* line 1189 */
        "movl -0x5c(%ebp), %edx\n" /* exc */
        "addl %eax, %edx\n"
        "movss -4(%edx), %xmm0\n" /* line 1648 */
        "movl -0x50(%ebp), %ebx\n" /* innov2, i */
        "addss -4(%eax, %ebx), %xmm0\n"
        "movss %xmm0, -4(%edx)\n"
        "movl %ecx, %eax\n"
        "addl $1, %ecx\n"
        "cmpl 0x10(%edi), %eax\n" /* line 1647 | state */
        "jl .Lf1f2b0e_001f38d7\n"
        "movl 0x10(%edi), %ebx\n" /* state, i */
        /* } scope */
        /* } scope */
        ".Lf1f2b0e_001f3903:\n"
        "testl %ebx, %ebx\n" /* line 1654 | i */
        "jle .Lf1f2b0e_001f392d\n"
        "movl $1, %ecx\n"
        ".Lf1f2b0e_001f390c:\n"
        "leal (, %ecx, 4), %eax\n" /* line 1189 */
        "movl -0x5c(%ebp), %ebx\n" /* line 1655 | exc, i */
        "movl -4(%ebx, %eax), %edx\n" /* i */
        "movl -0x60(%ebp), %ebx\n" /* sp, i */
        "movl %edx, -4(%ebx, %eax)\n" /* i */
        "movl %ecx, %eax\n"
        "movl 0x10(%edi), %ebx\n" /* line 1654 | state, i */
        "addl $1, %ecx\n"
        "cmpl %ebx, %eax\n" /* i */
        "jl .Lf1f2b0e_001f390c\n"
        ".Lf1f2b0e_001f392d:\n"
        "movl 0x80(%edi), %edx\n" /* line 1658 | state */
        "testl %edx, %edx\n"
        "je .Lf1f2b0e_001f3a2d\n"
        "movl 0x7c(%edi), %eax\n" /* state */
        "movl 0x78(%edi), %edx\n" /* state */
        "movl (%edx, %eax, 4), %eax\n"
        "movss 0x3c(%eax), %xmm0\n"
        "ucomiss 0x2ed5e8, %xmm0\n" /* 0.0f */
        "jbe .Lf1f2b0e_001f39a5\n"
        "movl 0x84(%edi), %eax\n" /* line 1660 | state */
        "movl %eax, 0x20(%esp)\n"
        "movss %xmm0, 0x1c(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* pitch_gain */
        "movl %eax, 0x18(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* pitch */
        "movl %eax, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n" /* i */
        "movl 0x18(%edi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x50(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl -0x60(%ebp), %eax\n" /* sp */
        "movl %eax, 4(%esp)\n"
        "movl -0x5c(%ebp), %edx\n" /* exc */
        "movl %edx, (%esp)\n"
        "calll comb_filter\n"
        "movl 0x80(%edi), %eax\n" /* line 1662 | state */
        "testl %eax, %eax\n"
        "je .Lf1f2b0e_001f3a2d\n"
        "movl 0x10(%edi), %ebx\n" /* state, i */
        ".Lf1f2b0e_001f39a5:\n"
        "movl 0x18(%edi), %edx\n" /* line 1666 | state */
        "movl 0x54(%edi), %eax\n" /* state */
        "leal (%eax, %edx, 4), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl %edx, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n" /* i */
        "movl -0x60(%ebp), %ecx\n" /* sp */
        "movl %ecx, 0xc(%esp)\n"
        "movl -0x98(%ebp), %ebx\n" /* awk1, i */
        "movl %ebx, 8(%esp)\n" /* i */
        "movl -0x94(%ebp), %eax\n" /* awk2 */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll filter_mem2\n"
        "movl 0x54(%edi), %eax\n" /* line 1668 | state */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x18(%edi), %eax\n" /* state */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edi), %eax\n" /* state */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x60(%ebp), %edx\n" /* sp */
        "movl %edx, 0xc(%esp)\n"
        "movl 0x50(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl -0x90(%ebp), %ecx\n" /* awk3 */
        "movl %ecx, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll filter_mem2\n"
        /* } scope */
        ".Lf1f2b0e_001f3a12:\n"
        "addl $1, -0xb4(%ebp)\n" /* line 1436 | sub */
        "movl 0x14(%edi), %edx\n" /* state */
        "cmpl %edx, -0xb4(%ebp)\n" /* sub */
        "jl .Lf1f2b0e_001f3500\n"
        "jmp .Lf1f2b0e_001f2d6e\n"
        /* { scope 2: sp, ener, innov */
        ".Lf1f2b0e_001f3a2d:\n"
        "movl 0x18(%edi), %edx\n" /* line 1671 | state */
        "testl %edx, %edx\n"
        "jle .Lf1f2b0e_001f3a4d\n"
        "xorl %ecx, %ecx\n"
        ".Lf1f2b0e_001f3a36:\n"
        "leal (%ecx, %edx), %edx\n" /* line 1672 */
        "movl 0x54(%edi), %eax\n" /* state */
        "movl $0, (%eax, %edx, 4)\n"
        "addl $1, %ecx\n" /* line 1671 */
        "movl 0x18(%edi), %edx\n" /* state */
        "cmpl %ecx, %edx\n"
        "jg .Lf1f2b0e_001f3a36\n"
        ".Lf1f2b0e_001f3a4d:\n"
        "movl 0x54(%edi), %eax\n" /* line 1674 | state */
        "movl %eax, 0x14(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl 0x10(%edi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x60(%ebp), %ebx\n" /* sp, i */
        "movl %ebx, 8(%esp)\n" /* i */
        "movl 0x50(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* i */
        "calll iir_mem2\n"
        "jmp .Lf1f2b0e_001f3a12\n"
        /* { scope 3: k3, innov_gain, innov2 */
        ".Lf1f2b0e_001f3a77:\n"
        "movss 0x2ed5d0, %xmm1\n" /* line 1481 | 1.0f */
        "jmp .Lf1f2b0e_001f35c3\n"
        /* } scope */
        /* { scope 3: k3, innov_gain, innov2 */
        ".Lf1f2b0e_001f3a84:\n"
        "movl -0xac(%ebp), %eax\n" /* line 1512 | ol_pitch */
        "subl %edx, %eax\n"
        "leal 1(%eax), %esi\n" /* pit_min */
        "movl 0x1c(%edi), %eax\n" /* line 1513 | state */
        "cmpl %eax, %esi\n" /* pit_min */
        "cmovll %eax, %esi\n" /* pit_min */
        "addl -0xac(%ebp), %edx\n" /* line 1515 | ol_pitch */
        "movl 0x20(%edi), %eax\n" /* line 1516 | state */
        "cmpl %eax, %edx\n"
        "jle .Lf1f2b0e_001f3623\n"
        "movl %eax, %edx\n"
        "jmp .Lf1f2b0e_001f3623\n"
        /* } scope */
        ".Lf1f2b0e_001f3aaf:\n"
        "movl 0x18(%edi), %eax\n" /* line 1473 | state */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x98(%ebp), %edx\n" /* awk1 */
        "movl %edx, 8(%esp)\n"
        "movl 0x50(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x7c(%edi), %edx\n" /* state */
        "movl 0x78(%edi), %eax\n" /* state */
        "movl (%eax, %edx, 4), %eax\n"
        "movl 0x30(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll bw_lpc\n"
        "movl 0x18(%edi), %eax\n" /* line 1474 | state */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x94(%ebp), %ecx\n" /* awk2 */
        "movl %ecx, 8(%esp)\n"
        "movl 0x50(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x7c(%edi), %edx\n" /* state */
        "movl 0x78(%edi), %eax\n" /* state */
        "movl (%eax, %edx, 4), %eax\n"
        "movl 0x34(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll bw_lpc\n"
        "movl 0x18(%edi), %eax\n" /* line 1475 | state */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x90(%ebp), %ebx\n" /* awk3, i */
        "movl %ebx, 8(%esp)\n" /* i */
        "movl 0x50(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x7c(%edi), %edx\n" /* state */
        "movl 0x78(%edi), %eax\n" /* state */
        "movl (%eax, %edx, 4), %eax\n"
        "movl 0x38(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll bw_lpc\n"
        "jmp .Lf1f2b0e_001f3594\n"
        /* { scope 3: k3, innov_gain, innov2 */
        /* { scope 4 */
        ".Lf1f2b0e_001f3b38:\n"
        "movl 0x10(%edi), %eax\n" /* line 1608 | state */
        "pxor %xmm2, %xmm2\n"
        "testl %eax, %eax\n"
        "jle .Lf1f2b0e_001f3b5b\n"
        "xorl %eax, %eax\n"
        "pxor %xmm2, %xmm2\n"
        ".Lf1f2b0e_001f3b49:\n"
        "movl -0x5c(%ebp), %edx\n" /* line 1609 | exc */
        "movl $0, (%edx, %eax, 4)\n"
        "addl $1, %eax\n" /* line 1608 */
        "cmpl 0x10(%edi), %eax\n" /* state */
        "jl .Lf1f2b0e_001f3b49\n"
        ".Lf1f2b0e_001f3b5b:\n"
        "movl 0x1e8(%edi), %eax\n" /* line 1610 | state */
        "movl %eax, %edx\n"
        "movl 0x10(%edi), %ebx\n" /* state, i */
        "cmpl %ebx, %eax\n" /* i */
        "jge .Lf1f2b0e_001f3b9f\n"
        "sqrtsd -0xd0(%ebp), %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        ".Lf1f2b0e_001f3b76:\n"
        "testl %edx, %edx\n" /* line 1612 */
        "js .Lf1f2b0e_001f3b8b\n"
        "movl -0x5c(%ebp), %ecx\n" /* line 1613 | exc */
        "movss %xmm0, (%ecx, %edx, 4)\n"
        "movl 0x10(%edi), %ebx\n" /* state, i */
        "movl 0x1e8(%edi), %eax\n" /* state */
        ".Lf1f2b0e_001f3b8b:\n"
        "movl -0xac(%ebp), %edx\n" /* line 1614 | ol_pitch */
        "addl %eax, %edx\n"
        "movl %edx, %eax\n"
        "movl %edx, 0x1e8(%edi)\n" /* state */
        "cmpl %ebx, %edx\n" /* line 1610 | i */
        "jl .Lf1f2b0e_001f3b76\n"
        ".Lf1f2b0e_001f3b9f:\n"
        "subl %ebx, %edx\n" /* line 1616 | i */
        "movl %edx, 0x1e8(%edi)\n" /* state */
        "ucomiss -0x3c(%ebp), %xmm2\n" /* line 1619 */
        "ja .Lf1f2b0e_001f3ea5\n"
        "movss 0x2ed5d0, %xmm1\n" /* line 1621 | 1.0f */
        "minss -0x3c(%ebp), %xmm1\n"
        ".Lf1f2b0e_001f3bbe:\n"
        "movl 0x10(%edi), %esi\n" /* line 1623 | state, pit_min */
        "testl %esi, %esi\n" /* pit_min */
        "jle .Lf1f2b0e_001f383d\n"
        "cvtss2sd %xmm1, %xmm0\n"
        "movapd %xmm0, %xmm7\n"
        "mulsd 0x307d58, %xmm7\n" /* 0.8 */
        "movapd %xmm0, %xmm6\n"
        "mulsd 0x307e60, %xmm6\n" /* 0.6 */
        "movapd %xmm0, %xmm5\n"
        "mulsd 0x307ce0, %xmm5\n" /* 0.5 */
        "movapd %xmm0, %xmm4\n"
        "mulsd 0x307dd8, %xmm4\n" /* -0.5 */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n"
        "movl $1, %ecx\n"
        ".Lf1f2b0e_001f3c13:\n"
        "leal (, %ecx, 4), %eax\n" /* line 1189 */
        "movl -0x5c(%ebp), %ebx\n" /* exc, i */
        "leal (%eax, %ebx), %edx\n"
        /* { scope 5 */
        "movss -4(%edx), %xmm3\n" /* line 1625 | exci */
        "addl -0x54(%ebp), %eax\n" /* line 1189 | innov */
        "movss -4(%eax), %xmm2\n" /* line 1626 */
        "cvtss2sd %xmm3, %xmm1\n"
        "mulsd %xmm7, %xmm1\n"
        "mulsd -0xd8(%ebp), %xmm1\n"
        "cvtss2sd 0x1dc(%edi), %xmm0\n" /* state */
        "mulsd %xmm6, %xmm0\n"
        "mulsd -0xd8(%ebp), %xmm0\n"
        "addsd %xmm0, %xmm1\n"
        "cvtss2sd %xmm2, %xmm0\n"
        "mulsd %xmm5, %xmm0\n"
        "addsd %xmm0, %xmm1\n"
        "cvtss2sd 0x1e0(%edi), %xmm0\n" /* state */
        "mulsd %xmm4, %xmm0\n"
        "addsd %xmm0, %xmm1\n"
        "mulss -0x4c(%ebp), %xmm2\n"
        "cvtss2sd %xmm2, %xmm2\n"
        "addsd %xmm2, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm1\n"
        "movss %xmm1, -4(%edx)\n"
        "movss %xmm3, 0x1dc(%edi)\n" /* line 1627 | state */
        "movl -4(%eax), %eax\n" /* line 1628 */
        "movl %eax, 0x1e0(%edi)\n" /* state */
        "cvtss2sd 0x1e4(%edi), %xmm1\n" /* line 1629 | state */
        "mulsd 0x307e00, %xmm1\n" /* 0.95 */
        "cvtss2sd -4(%edx), %xmm0\n"
        "mulsd 0x307e08, %xmm0\n" /* 0.05 */
        "addsd %xmm0, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm1\n"
        "movss %xmm1, 0x1e4(%edi)\n" /* state */
        "movss -4(%edx), %xmm0\n" /* line 1630 */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -4(%edx)\n"
        "movl %ecx, %eax\n"
        "addl $1, %ecx\n"
        /* } scope */
        "cmpl %eax, 0x10(%edi)\n" /* line 1623 | state */
        "jg .Lf1f2b0e_001f3c13\n"
        "jmp .Lf1f2b0e_001f383a\n"
        /* } scope */
        /* } scope */
        /* { scope 3: k3, innov_gain, innov2 */
        ".Lf1f2b0e_001f3ce6:\n"
        "movl 0x1c(%edi), %esi\n" /* line 1522 | state, pit_min */
        "movl 0x20(%edi), %edx\n" /* line 1523 | state */
        "jmp .Lf1f2b0e_001f3623\n"
        ".Lf1f2b0e_001f3cf1:\n"
        "cvtss2sd %xmm1, %xmm1\n" /* line 1553 */
        "mulsd 0x307dd8, %xmm1\n" /* -0.5 */
        "jmp .Lf1f2b0e_001f371a\n"
        ".Lf1f2b0e_001f3d02:\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "mulsd 0x307dd8, %xmm1\n" /* -0.5 */
        "jmp .Lf1f2b0e_001f3704\n"
        /* } scope */
        /* { scope 3: k3, innov_gain, innov2 */
        ".Lf1f2b0e_001f3d13:\n"
        "movl $0x2b9150, (%esp)\n" /* line 1593 */
        "calll speex_error\n"
        "jmp .Lf1f2b0e_001f37da\n"
        ".Lf1f2b0e_001f3d24:\n"
        "movl $3, 4(%esp)\n" /* line 1578 */
        "movl 0xc(%ebp), %ecx\n" /* bits */
        "movl %ecx, (%esp)\n"
        "calll speex_bits_unpack_unsigned\n"
        "movss -0xb0(%ebp), %xmm0\n" /* line 1579 | ol_gain */
        "mulss exc_gain_quant_scal3(, %eax, 4), %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n" /* ener */
        "movl 0x7c(%edi), %esi\n" /* state, pit_min */
        "movl 0x78(%edi), %edx\n" /* state */
        "jmp .Lf1f2b0e_001f37a8\n"
        ".Lf1f2b0e_001f3d58:\n"
        "movl $1, 4(%esp)\n" /* line 1582 */
        "movl 0xc(%ebp), %eax\n" /* bits */
        "movl %eax, (%esp)\n"
        "calll speex_bits_unpack_unsigned\n"
        "movss -0xb0(%ebp), %xmm0\n" /* line 1583 | ol_gain */
        "mulss exc_gain_quant_scal1(, %eax, 4), %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n" /* ener */
        "movl 0x7c(%edi), %esi\n" /* state, pit_min */
        "movl 0x78(%edi), %edx\n" /* state */
        "jmp .Lf1f2b0e_001f37a8\n"
        /* } scope */
        ".Lf1f2b0e_001f3d8c:\n"
        "movl $0x2b912c, (%esp)\n" /* line 1562 */
        "calll speex_error\n"
        "jmp .Lf1f2b0e_001f3750\n"
        /* } scope */
        ".Lf1f2b0e_001f3d9d:\n"
        "movl -0x9c(%ebp), %eax\n" /* line 1318 | stack */
        "negl %eax\n"
        "andl $3, %eax\n"
        "movl -0x9c(%ebp), %ebx\n" /* stack, i */
        "addl %eax, %ebx\n" /* i */
        "movl $0xa, 0xc(%esp)\n" /* line 1319 */
        "movl %ebx, 8(%esp)\n" /* i */
        "movl 0x50(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl $0x3f6e147b, (%esp)\n"
        "calll bw_lpc\n"
        /* { scope 2: sp, ener, innov */
        "movl 0xc(%edi), %eax\n" /* line 1325 | state */
        "movl %eax, 4(%esp)\n"
        "movl 0x40(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll compute_rms\n"
        "movl 0xc(%edi), %eax\n" /* line 1326 | state */
        "testl %eax, %eax\n"
        "jle .Lf1f2b0e_001f3dfe\n"
        "xorl %edx, %edx\n"
        ".Lf1f2b0e_001f3dea:\n"
        "movl 0x3c(%edi), %eax\n" /* line 1327 | state */
        "movl $0x26901d7d, (%eax, %edx, 4)\n"
        "addl $1, %edx\n" /* line 1326 */
        "movl 0xc(%edi), %eax\n" /* state */
        "cmpl %edx, %eax\n"
        "jg .Lf1f2b0e_001f3dea\n"
        ".Lf1f2b0e_001f3dfe:\n"
        "movl %eax, 8(%esp)\n" /* line 1328 */
        "movl 0x3c(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "fstps (%esp)\n"
        "calll speex_rand_vec\n"
        /* } scope */
        "movl $1, 4(%edi)\n" /* line 1332 | state */
        "movl 0x54(%edi), %eax\n" /* line 1335 | state */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x18(%edi), %eax\n" /* state */
        "movl %eax, 0x10(%esp)\n"
        "movl 0xc(%edi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x34(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* i */
        "movl 0x3c(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll iir_mem2\n"
        "movl 0xc(%edi), %esi\n" /* line 1337 | state, exc */
        "testl %esi, %esi\n" /* exc */
        "jle .Lf1f2b0e_001f3e91\n"
        "xorl %ecx, %ecx\n"
        "movss 0x2edaa8, %xmm2\n" /* -32767.0f */
        "movss 0x2edaa4, %xmm1\n" /* 32767.0f */
        "jmp .Lf1f2b0e_001f3e78\n"
        /* { scope 2: sp, ener, innov */
        ".Lf1f2b0e_001f3e5e:\n"
        "movaps %xmm2, %xmm3\n" /* line 1342 */
        "maxss %xmm0, %xmm3\n"
        "movaps %xmm3, %xmm0\n"
        ".Lf1f2b0e_001f3e68:\n"
        "movl 0x10(%ebp), %eax\n" /* line 1344 | vout */
        "movss %xmm0, (%eax, %edx)\n"
        /* } scope */
        "addl $1, %ecx\n" /* line 1337 */
        "cmpl %ecx, 0xc(%edi)\n" /* state */
        "jle .Lf1f2b0e_001f3e91\n"
        ".Lf1f2b0e_001f3e78:\n"
        "leal (, %ecx, 4), %edx\n"
        /* { scope 2: sp, ener, innov */
        "movl 0x34(%edi), %eax\n" /* line 1339 | state */
        "movss (%eax, %edx), %xmm0\n" /* sig */
        "ucomiss %xmm1, %xmm0\n" /* line 1340 */
        "jbe .Lf1f2b0e_001f3e5e\n"
        "movaps %xmm1, %xmm0\n"
        "jmp .Lf1f2b0e_001f3e68\n"
        /* } scope */
        ".Lf1f2b0e_001f3e91:\n"
        "movl $0, 8(%edi)\n" /* line 1347 | state */
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x13c, %esp\n" /* line 1712 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: advance, sub, awk1, awk2, ... */
        /* { scope 2: sp, ener, innov */
        /* { scope 3: k3, innov_gain, innov2 */
        /* { scope 4 */
        ".Lf1f2b0e_001f3ea5:\n"
        "movaps %xmm2, %xmm1\n" /* line 1619 */
        "jmp .Lf1f2b0e_001f3bbe\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: sp, ener, innov */
        ".Lf1f2b0e_001f3ead:\n"
        "movss 0x6c(%edi), %xmm2\n" /* line 1086 */
        "ucomiss %xmm2, %xmm0\n"
        "ja .Lf1f2b0e_001f30c9\n"
        "ucomiss %xmm2, %xmm1\n"
        "jbe .Lf1f2b0e_001f30cc\n"
        "movaps %xmm2, %xmm1\n"
        "jmp .Lf1f2b0e_001f30cc\n"
        /* } scope */
        ".Lf1f2b0e_001f3ecc:\n"
        "movl $4, 4(%esp)\n" /* line 1425 */
        "movl 0xc(%ebp), %edx\n" /* bits */
        "movl %edx, (%esp)\n"
        "calll speex_bits_unpack_unsigned\n"
        "cmpl $0xf, %eax\n" /* line 1428 */
        "sete %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, 0x1ec(%edi)\n" /* state */
        "jmp .Lf1f2b0e_001f2d3d\n"
        /* { scope 2: sp, ener, innov */
        /* { scope 3: k3, innov_gain, innov2 */
        /* { scope 4 */
        ".Lf1f2b0e_001f3ef3:\n"
        "movl $0x3f333333, %ebx\n" /* line 1120 | i */
        "movl %ebx, %edx\n" /* i */
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0x6c(%ebp)\n" /* k3 */
        "jmp .Lf1f2b0e_001f3212\n"
        /* } scope */
        /* } scope */
        ".Lf1f2b0e_001f3f08:\n"
        "ucomiss %xmm1, %xmm2\n" /* line 1086 */
        "jbe .Lf1f2b0e_001f30cc\n"
        "movaps %xmm2, %xmm1\n"
        "jmp .Lf1f2b0e_001f30cc\n"
        /* } scope */
        ".Lf1f2b0e_001f3f19:\n"
        "movl $0xffffffff, %eax\n" /* line 1237 */
        "jmp .Lf1f2b0e_001f2e40\n"
        /* { scope 2: sp, ener, innov */
        ".Lf1f2b0e_001f3f23:\n"
        "movl $0x2b9164, (%esp)\n" /* line 1248 */
        "calll speex_warning\n"
        "movl $0xfffffffe, %eax\n"
        "jmp .Lf1f2b0e_001f2e40\n"
        /* } scope */
        ".Lf1f2b0e_001f3f39:\n"
        "cmpl $8, %eax\n" /* line 1294 */
        "jg .Lf1f2b0e_001f3f5c\n"
        "movl %eax, 0x7c(%edi)\n" /* line 1303 | state */
        "jmp .Lf1f2b0e_001f2b4d\n"
        /* { scope 2: sp, ener, innov */
        ".Lf1f2b0e_001f3f46:\n"
        "movl $0x2b919c, (%esp)\n" /* line 1263 */
        "calll speex_warning\n"
        "movl $0xfffffffe, %eax\n"
        "jmp .Lf1f2b0e_001f2e40\n"
        /* } scope */
        ".Lf1f2b0e_001f3f5c:\n"
        "movl $0x2b9100, (%esp)\n" /* line 1296 */
        "calll speex_warning\n"
        "movl $0xfffffffe, %eax\n"
        "jmp .Lf1f2b0e_001f2e40\n"
    );
}

/* line 1714 */
__attribute__((naked))
int nb_encoder_ctl(double *state, int request, double *ptr)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1714 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %edi\n" /* state */
        "movl 0xc(%ebp), %edx\n" /* request */
        "leal -3(%edx), %eax\n" /* line 1718 */
        "cmpl $0x63, %eax\n"
        "ja .Lf1f3f72_001f3f90\n"
        "jmpl *0x306490(, %eax, 4)\n"
        ".Lf1f3f72_001f3f90:\n"
        "movl %edx, 4(%esp)\n" /* line 1887 */
        "movl $0x2b90e4, (%esp)\n" /* "Unknown nb_ctl request: " */
        "calll speex_warning_int\n"
        "movl $0xffffffff, -0x30(%ebp)\n"
        ".Lf1f3f72_001f3fa7:\n"
        "movl -0x30(%ebp), %eax\n" /* line 1891 */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl 8(%edi), %eax\n" /* line 1721 | state */
        "movl 0x10(%ebp), %edx\n" /* ptr */
        "movl %eax, (%edx)\n"
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf1f3f72_001f3fa7\n"
        /* { scope 1 */
        "movl 0x10(%ebp), %ebx\n" /* line 1785 | ptr, target */
        "movl (%ebx), %edx\n" /* target, quality */
        "testl %edx, %edx\n" /* line 1786 */
        "js .Lf1f3f72_001f44e8\n"
        "cmpl $0xb, %edx\n" /* line 1788 */
        "movl $0xa, %eax\n"
        "cmovgel %eax, %edx\n"
        ".Lf1f3f72_001f3fdb:\n"
        "movl (%edi), %eax\n" /* line 1790 | state */
        "movl (%eax), %eax\n"
        "movl 0x68(%eax, %edx, 4), %eax\n"
        "movl %eax, 0xf4(%edi)\n" /* state */
        "movl %eax, 0xf8(%edi)\n" /* state */
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf1f3f72_001f3fa7\n"
        /* } scope */
        "movl 0x10(%ebp), %ebx\n" /* line 1725 | ptr */
        "movl (%ebx), %eax\n"
        "movl %eax, 0xf4(%edi)\n" /* state */
        "movl %eax, 0xf8(%edi)\n" /* state */
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf1f3f72_001f3fa7\n"
        "movl 0x10(%ebp), %ebx\n" /* line 1732 | ptr */
        "movl (%ebx), %eax\n"
        "movl %eax, 0xc0(%edi)\n" /* state */
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf1f3f72_001f3fa7\n"
        "movl 0xc0(%edi), %eax\n" /* line 1735 | state */
        "movl 0x10(%ebp), %edx\n" /* ptr */
        "movl %eax, (%edx)\n"
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf1f3f72_001f3fa7\n"
        "movl 0xf4(%edi), %eax\n" /* line 1729 | state */
        "movl 0x10(%ebp), %edx\n" /* ptr */
        "movl %eax, (%edx)\n"
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf1f3f72_001f3fa7\n"
        "movl 0x10(%ebp), %ebx\n" /* line 1778 | ptr, target */
        "movl (%ebx), %eax\n" /* target */
        "movl %eax, 0xb8(%edi)\n" /* state */
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf1f3f72_001f3fa7\n"
        "movl 0xb8(%edi), %eax\n" /* line 1781 | state */
        "movl 0x10(%ebp), %edx\n" /* ptr */
        "movl %eax, (%edx)\n"
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf1f3f72_001f3fa7\n"
        "movl 0x10(%ebp), %edx\n" /* line 1794 | ptr */
        "movl (%edx), %eax\n"
        "movl %eax, 0xe0(%edi)\n" /* state */
        "testl %eax, %eax\n" /* line 1795 */
        "js .Lf1f3f72_001f44d2\n"
        ".Lf1f3f72_001f4095:\n"
        "movl $0, -0x30(%ebp)\n" /* line 1888 */
        "jmp .Lf1f3f72_001f3fa7\n"
        "movl 0xe0(%edi), %eax\n" /* line 1799 | state */
        "movl 0x10(%ebp), %ebx\n" /* ptr, target */
        "movl %eax, (%ebx)\n" /* target */
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf1f3f72_001f3fa7\n"
        /* { scope 1 */
        "movl $0xa, -0x20(%ebp)\n" /* line 1803 | i */
        "movl 0x10(%ebp), %eax\n" /* line 1804 | ptr */
        "movl (%eax), %ebx\n" /* target */
        "leal -0x24(%ebp), %esi\n" /* rate */
        ".Lf1f3f72_001f40c7:\n"
        "leal -0x20(%ebp), %edx\n" /* line 1807 | i */
        "movl %edx, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* state */
        "calll speex_encoder_ctl\n"
        "movl %esi, 8(%esp)\n" /* line 1808 */
        "movl $0x13, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* state */
        "calll speex_encoder_ctl\n"
        "cmpl -0x24(%ebp), %ebx\n" /* line 1809 | rate, target */
        "jge .Lf1f3f72_001f4095\n"
        "movl -0x20(%ebp), %eax\n" /* line 1811 | i */
        "subl $1, %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* i */
        "testl %eax, %eax\n" /* line 1805 */
        "jns .Lf1f3f72_001f40c7\n"
        "jmp .Lf1f3f72_001f4095\n"
        /* } scope */
        "movl 0xf4(%edi), %edx\n" /* line 1816 | state */
        "movl 0xf0(%edi), %eax\n" /* state */
        "movl (%eax, %edx, 4), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1f3f72_001f44ef\n"
        "movl 0xe4(%edi), %eax\n" /* line 1817 | state */
        "imull 0x40(%edx), %eax\n"
        "cltd\n"
        "idivl 8(%edi)\n" /* state */
        "movl 0x10(%ebp), %ebx\n" /* ptr, target */
        "movl %eax, (%ebx)\n" /* target */
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf1f3f72_001f3fa7\n"
        "movl 0x10(%ebp), %ebx\n" /* line 1822 | ptr, target */
        "movl (%ebx), %eax\n" /* target */
        "movl %eax, 0xe4(%edi)\n" /* state */
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf1f3f72_001f3fa7\n"
        "movl 0xe4(%edi), %eax\n" /* line 1825 | state */
        "movl 0x10(%ebp), %edx\n" /* ptr */
        "movl %eax, (%edx)\n"
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf1f3f72_001f3fa7\n"
        /* { scope 1 */
        "movl $1, 0x28(%edi)\n" /* line 1830 | state */
        "movl $1, 4(%edi)\n" /* line 1831 | state */
        "movl 0x18(%edi), %ecx\n" /* line 1832 | state */
        "testl %ecx, %ecx\n"
        "jle .Lf1f3f72_001f4214\n"
        "xorl %ebx, %ebx\n" /* i */
        "movsd 0x307c28, %xmm2\n" /* 3.141592653589793 */
        ".Lf1f3f72_001f418d:\n"
        "movl 0x78(%edi), %eax\n" /* line 1833 | state */
        "leal (%eax, %ebx, 4), %edx\n"
        "addl $1, %ebx\n" /* i */
        "cvtsi2ssl %ebx, %xmm0\n" /* i */
        "cvtss2sd %xmm0, %xmm0\n"
        "mulsd %xmm2, %xmm0\n"
        "leal 1(%ecx), %eax\n"
        "cvtsi2sdl %eax, %xmm1\n"
        "divsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movl 0x18(%edi), %ecx\n" /* line 1832 | state */
        "cmpl %ebx, %ecx\n" /* i */
        "jg .Lf1f3f72_001f418d\n"
        "testl %ecx, %ecx\n" /* line 1834 */
        "jle .Lf1f3f72_001f4214\n"
        "movl $0, -0x2c(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "jmp .Lf1f3f72_001f41ce\n"
        ".Lf1f3f72_001f41cc:\n"
        "movl %ebx, %eax\n" /* i */
        ".Lf1f3f72_001f41ce:\n"
        "shll $2, %eax\n"
        "movl %eax, %esi\n" /* line 1835 */
        "addl 0xa4(%edi), %esi\n" /* state */
        "movl %eax, %ebx\n" /* i */
        "addl 0xa8(%edi), %ebx\n" /* state, i */
        "movl %eax, %ecx\n"
        "addl 0xa0(%edi), %ecx\n" /* state */
        "movl 0xac(%edi), %edx\n" /* state */
        "movl $0, (%edx, %eax)\n"
        "movl $0, (%ecx)\n"
        "movl $0, (%ebx)\n" /* i */
        "movl $0, (%esi)\n"
        "addl $1, -0x2c(%ebp)\n" /* line 1834 */
        "movl -0x2c(%ebp), %ebx\n" /* i */
        "cmpl %ebx, 0x18(%edi)\n" /* i, state */
        "jg .Lf1f3f72_001f41cc\n"
        ".Lf1f3f72_001f4214:\n"
        "movl 0x20(%edi), %eax\n" /* line 1836 | state */
        "addl 8(%edi), %eax\n" /* state */
        "addl $1, %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf1f3f72_001f424f\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf1f3f72_001f4223:\n"
        "leal (, %ebx, 4), %edx\n"
        "movl %edx, %ecx\n" /* line 1837 */
        "addl 0x54(%edi), %ecx\n" /* state */
        "movl 0x5c(%edi), %eax\n" /* state */
        "movl $0, (%eax, %edx)\n"
        "movl $0, (%ecx)\n"
        "addl $1, %ebx\n" /* line 1836 | i */
        "movl 0x20(%edi), %eax\n" /* state */
        "addl 8(%edi), %eax\n" /* state */
        "addl $1, %eax\n"
        "cmpl %eax, %ebx\n" /* i */
        "jl .Lf1f3f72_001f4223\n"
        ".Lf1f3f72_001f424f:\n"
        "movl 0x14(%edi), %eax\n" /* line 1838 | state */
        "testl %eax, %eax\n"
        "jle .Lf1f3f72_001f4095\n"
        "xorl %edx, %edx\n"
        ".Lf1f3f72_001f425c:\n"
        "movl 0x4c(%edi), %eax\n" /* line 1839 | state */
        "movl $0, (%eax, %edx, 4)\n"
        "addl $1, %edx\n" /* line 1838 */
        "cmpl 0x14(%edi), %edx\n" /* state */
        "jl .Lf1f3f72_001f425c\n"
        "jmp .Lf1f3f72_001f4095\n"
        /* } scope */
        "movl 0xbc(%edi), %eax\n" /* line 1884 | state */
        "movl 0x10(%ebp), %edx\n" /* ptr */
        "movl %eax, (%edx)\n"
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf1f3f72_001f3fa7\n"
        "movl 0x10(%ebp), %edx\n" /* line 1843 | ptr */
        "movl (%edx), %eax\n"
        "movl %eax, 0xec(%edi)\n" /* state */
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf1f3f72_001f3fa7\n"
        "movl 0xec(%edi), %eax\n" /* line 1846 | state */
        "movl 0x10(%ebp), %ebx\n" /* ptr, i */
        "movl %eax, (%ebx)\n" /* i */
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf1f3f72_001f3fa7\n"
        "movl 0x14(%edi), %eax\n" /* line 1849 | state */
        "subl 8(%edi), %eax\n" /* state */
        "movl 0x10(%ebp), %edx\n" /* ptr */
        "movl %eax, (%edx)\n"
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf1f3f72_001f3fa7\n"
        "movl 0x10(%ebp), %ebx\n" /* line 1852 | ptr, i */
        "movl (%ebx), %eax\n" /* i */
        "movl %eax, 0xe8(%edi)\n" /* state */
        "cmpl $0x64, %eax\n" /* line 1853 */
        "jle .Lf1f3f72_001f4095\n"
        "movl $0x64, 0xe8(%edi)\n" /* line 1854 | state */
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf1f3f72_001f3fa7\n"
        "movl 0xe8(%edi), %eax\n" /* line 1857 | state */
        "movl 0x10(%ebp), %edx\n" /* ptr */
        "movl %eax, (%edx)\n"
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf1f3f72_001f3fa7\n"
        /* { scope 1 */
        "movl 0x10(%edi), %esi\n" /* line 1863 | state */
        "testl %esi, %esi\n"
        "jle .Lf1f3f72_001f4095\n"
        "xorl %ecx, %ecx\n"
        ".Lf1f3f72_001f431d:\n"
        "leal (, %ecx, 4), %eax\n"
        "movl 0xb0(%edi), %edx\n" /* line 1864 | state */
        "movl (%edx, %eax), %edx\n"
        "movl 0x10(%ebp), %ebx\n" /* ptr, i */
        "movl %edx, (%ebx, %eax)\n" /* i */
        "addl $1, %ecx\n" /* line 1863 */
        "cmpl 0x10(%edi), %ecx\n" /* state */
        "jl .Lf1f3f72_001f431d\n"
        "jmp .Lf1f3f72_001f4095\n"
        /* } scope */
        /* { scope 1 */
        "movl 8(%edi), %ebx\n" /* line 1871 | state, i */
        "testl %ebx, %ebx\n" /* i */
        "jle .Lf1f3f72_001f4095\n"
        "xorl %ecx, %ecx\n"
        ".Lf1f3f72_001f434d:\n"
        "leal (, %ecx, 4), %eax\n"
        "movl 0x58(%edi), %edx\n" /* line 1872 | state */
        "movl (%edx, %eax), %edx\n"
        "movl 0x10(%ebp), %ebx\n" /* ptr, i */
        "movl %edx, (%ebx, %eax)\n" /* i */
        "addl $1, %ecx\n" /* line 1871 */
        "cmpl 8(%edi), %ecx\n" /* state */
        "jl .Lf1f3f72_001f434d\n"
        "jmp .Lf1f3f72_001f4095\n"
        /* } scope */
        /* { scope 1 */
        "movl 8(%edi), %ecx\n" /* line 1879 | state */
        "testl %ecx, %ecx\n"
        "jle .Lf1f3f72_001f4095\n"
        "xorl %ecx, %ecx\n"
        ".Lf1f3f72_001f437a:\n"
        "leal (, %ecx, 4), %eax\n"
        "movl 0x64(%edi), %edx\n" /* line 1880 | state */
        "movl (%edx, %eax), %edx\n"
        "movl 0x10(%ebp), %ebx\n" /* ptr, i */
        "movl %edx, (%ebx, %eax)\n" /* i */
        "addl $1, %ecx\n" /* line 1879 */
        "cmpl 8(%edi), %ecx\n" /* state */
        "jl .Lf1f3f72_001f437a\n"
        "jmp .Lf1f3f72_001f4095\n"
        /* } scope */
        "movl 0x10(%ebp), %ebx\n" /* line 1750 | ptr */
        "movl (%ebx), %eax\n"
        "movl %eax, 0xd0(%edi)\n" /* state */
        "movl $1, 0xc0(%edi)\n" /* line 1751 | state */
        /* { scope 1 */
        "movl $0xa, -0x1c(%ebp)\n" /* line 1753 | i */
        "movl 0x10(%ebp), %eax\n" /* line 1755 | ptr */
        "movl (%eax), %ebx\n" /* target */
        "leal -0x24(%ebp), %esi\n" /* rate */
        ".Lf1f3f72_001f43be:\n"
        "leal -0x1c(%ebp), %edx\n" /* line 1758 | i */
        "movl %edx, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* state */
        "calll speex_encoder_ctl\n"
        "movl %esi, 8(%esp)\n" /* line 1759 */
        "movl $0x13, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* state */
        "calll speex_encoder_ctl\n"
        "cmpl -0x24(%ebp), %ebx\n" /* line 1760 | rate, target */
        "jge .Lf1f3f72_001f43fb\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1762 | i */
        "subl $1, %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        "testl %eax, %eax\n" /* line 1756 */
        "jns .Lf1f3f72_001f43be\n"
        ".Lf1f3f72_001f43fb:\n"
        "cvtsi2ssl -0x1c(%ebp), %xmm0\n" /* line 1764 | i */
        "pxor %xmm1, %xmm1\n" /* line 1765 */
        "movaps %xmm0, %xmm2\n" /* line 1766 */
        "cmpnltss %xmm1, %xmm0\n"
        "andps %xmm0, %xmm2\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm2, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n" /* i */
        "leal -0x20(%ebp), %eax\n" /* line 1767 | i */
        "movl %eax, 8(%esp)\n"
        "movl $0xe, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* state */
        "movss %xmm1, -0x48(%ebp)\n"
        "calll speex_encoder_ctl\n"
        "movss -0x48(%ebp), %xmm1\n" /* line 1768 */
        "movss %xmm1, 0xdc(%edi)\n" /* state */
        "movss %xmm1, 0xd4(%edi)\n" /* line 1769 | state */
        "movss %xmm1, 0xd8(%edi)\n" /* line 1770 | state */
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf1f3f72_001f3fa7\n"
        /* } scope */
        "movl 0xd0(%edi), %eax\n" /* line 1775 | state */
        "movl 0x10(%ebp), %edx\n" /* ptr */
        "movl %eax, (%edx)\n"
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf1f3f72_001f3fa7\n"
        "movl 0x10(%ebp), %ebx\n" /* line 1738 | ptr */
        "movl (%ebx), %eax\n"
        "movl %eax, 0xc4(%edi)\n" /* state */
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf1f3f72_001f3fa7\n"
        "movl 0xc4(%edi), %eax\n" /* line 1741 | state */
        "movl 0x10(%ebp), %edx\n" /* ptr */
        "movl %eax, (%edx)\n"
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf1f3f72_001f3fa7\n"
        "movl 0x10(%ebp), %ebx\n" /* line 1744 | ptr */
        "movl (%ebx), %eax\n"
        "movl %eax, 0xc8(%edi)\n" /* state */
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf1f3f72_001f3fa7\n"
        "movl 0xc8(%edi), %eax\n" /* line 1747 | state */
        "movl 0x10(%ebp), %edx\n" /* ptr */
        "movl %eax, (%edx)\n"
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf1f3f72_001f3fa7\n"
        ".Lf1f3f72_001f44d2:\n"
        "movl $0, 0xe0(%edi)\n" /* line 1796 | state */
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf1f3f72_001f3fa7\n"
        /* { scope 1 */
        ".Lf1f3f72_001f44e8:\n"
        "xorl %edx, %edx\n" /* line 1786 */
        "jmp .Lf1f3f72_001f3fdb\n"
        /* } scope */
        ".Lf1f3f72_001f44ef:\n"
        "movl 0xe4(%edi), %eax\n" /* line 1819 | state */
        "leal (%eax, %eax, 4), %eax\n"
        "cltd\n"
        "idivl 8(%edi)\n" /* state */
        "movl 0x10(%ebp), %edx\n" /* ptr */
        "movl %eax, (%edx)\n"
        "movl $0, -0x30(%ebp)\n"
        "jmp .Lf1f3f72_001f3fa7\n"
    );
}

/* line 1893 */
__attribute__((naked))
int nb_decoder_ctl(double *state, int request, double *ptr)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1893 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* state */
        "movl 0xc(%ebp), %eax\n" /* request */
        "cmpl $0x67, %eax\n" /* line 1897 */
        "ja .Lf1f450e_001f4528\n"
        "jmpl *0x306620(, %eax, 4)\n"
        ".Lf1f450e_001f4528:\n"
        "movl %eax, 4(%esp)\n" /* line 1989 */
        "movl $0x2b90e4, (%esp)\n" /* "Unknown nb_ctl request: " */
        "calll speex_warning_int\n"
        "movl $0xffffffff, %eax\n"
        ".Lf1f450e_001f453d:\n"
        "addl $0x10, %esp\n" /* line 1993 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "movl 0x10(%ebp), %esi\n" /* line 1908 | ptr */
        "movl (%esi), %eax\n"
        "movl %eax, 0x80(%ebx)\n" /* state */
        "xorl %eax, %eax\n"
        "jmp .Lf1f450e_001f453d\n"
        "movl 0x80(%ebx), %eax\n" /* line 1911 | state */
        "movl 0x10(%ebp), %edx\n" /* ptr */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1f450e_001f453d\n"
        "movl 0xc(%ebx), %eax\n" /* line 1914 | state */
        "movl 0x10(%ebp), %ebx\n" /* ptr, state */
        "movl %eax, (%ebx)\n" /* state */
        "xorl %eax, %eax\n"
        "jmp .Lf1f450e_001f453d\n"
        "movl 0x10(%ebp), %edx\n" /* line 1901 | ptr */
        "movl (%edx), %eax\n"
        "movl %eax, 0x7c(%ebx)\n" /* state */
        "xorl %eax, %eax\n"
        "jmp .Lf1f450e_001f453d\n"
        "movl 0x7c(%ebx), %eax\n" /* line 1905 | state */
        "movl 0x10(%ebp), %ebx\n" /* ptr, state */
        "movl %eax, (%ebx)\n" /* state */
        "xorl %eax, %eax\n"
        "jmp .Lf1f450e_001f453d\n"
        "movl 0x7c(%ebx), %edx\n" /* line 1917 | state */
        "movl 0x78(%ebx), %eax\n" /* state */
        "movl (%eax, %edx, 4), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1f450e_001f4730\n"
        "movl 0x24(%ebx), %eax\n" /* line 1918 | state */
        "imull 0x40(%edx), %eax\n"
        "cltd\n"
        "idivl 0xc(%ebx)\n" /* state */
        "movl 0x10(%ebp), %esi\n" /* ptr */
        "movl %eax, (%esi)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1f450e_001f453d\n"
        "movl 0x10(%ebp), %esi\n" /* line 1931 | ptr */
        "movl (%esi), %ecx\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n" /* state */
        "movl 4(%esi), %edx\n"
        "movl %edx, 0x8c(%eax)\n"
        "movl 8(%esi), %edx\n" /* line 1932 */
        "movl %edx, 0x90(%eax)\n"
        "movl %ecx, 0x88(%eax)\n" /* line 1933 */
        "xorl %eax, %eax\n"
        "jmp .Lf1f450e_001f453d\n"
        "movl 0x10(%ebp), %edx\n" /* line 1939 | ptr */
        "movl 4(%edx), %eax\n"
        "movl %eax, 0x1cc(%ebx)\n" /* state */
        "movl 8(%edx), %eax\n" /* line 1940 */
        "movl %eax, 0x1d0(%ebx)\n" /* state */
        "movl (%edx), %eax\n" /* line 1941 */
        "movl %eax, 0x1c8(%ebx)\n" /* state */
        "xorl %eax, %eax\n"
        "jmp .Lf1f450e_001f453d\n"
        "movl 0x10(%ebp), %esi\n" /* line 1923 | ptr */
        "movl (%esi), %eax\n"
        "movl %eax, 0x24(%ebx)\n" /* state */
        "xorl %eax, %eax\n"
        "jmp .Lf1f450e_001f453d\n"
        "movl 0x24(%ebx), %eax\n" /* line 1926 | state */
        "movl 0x10(%ebp), %edx\n" /* ptr */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1f450e_001f453d\n"
        /* { scope 1 */
        "movl 0x18(%ebx), %eax\n" /* line 1947 | state */
        "addl %eax, %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf1f450e_001f4638\n"
        "xorl %edx, %edx\n"
        ".Lf1f450e_001f4622:\n"
        "movl 0x54(%ebx), %eax\n" /* line 1948 | state */
        "movl $0, (%eax, %edx, 4)\n"
        "addl $1, %edx\n" /* line 1947 */
        "movl 0x18(%ebx), %eax\n" /* state */
        "addl %eax, %eax\n"
        "cmpl %eax, %edx\n"
        "jl .Lf1f450e_001f4622\n"
        ".Lf1f450e_001f4638:\n"
        "movl 0xc(%ebx), %eax\n" /* line 1949 | state */
        "addl 0x20(%ebx), %eax\n" /* state */
        "addl $1, %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf1f450e_001f4661\n"
        "xorl %edx, %edx\n"
        ".Lf1f450e_001f4647:\n"
        "movl 0x38(%ebx), %eax\n" /* line 1950 | state */
        "movl $0, (%eax, %edx, 4)\n"
        "addl $1, %edx\n" /* line 1949 */
        "movl 0xc(%ebx), %eax\n" /* state */
        "addl 0x20(%ebx), %eax\n" /* state */
        "addl $1, %eax\n"
        "cmpl %eax, %edx\n"
        "jl .Lf1f450e_001f4647\n"
        ".Lf1f450e_001f4661:\n"
        "movl 0xc(%ebx), %eax\n" /* line 1951 | state */
        "testl %eax, %eax\n"
        "jle .Lf1f450e_001f467c\n"
        "xorl %edx, %edx\n"
        ".Lf1f450e_001f466a:\n"
        "movl 0x30(%ebx), %eax\n" /* line 1952 | state */
        "movl $0, (%eax, %edx, 4)\n"
        "addl $1, %edx\n" /* line 1951 */
        "cmpl 0xc(%ebx), %edx\n" /* state */
        "jl .Lf1f450e_001f466a\n"
        /* } scope */
        ".Lf1f450e_001f467c:\n"
        "xorl %eax, %eax\n" /* line 1990 */
        ".Lf1f450e_001f467e:\n"
        "addl $0x10, %esp\n" /* line 1993 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "movl 0x10(%ebp), %esi\n" /* line 1956 | ptr */
        "movl (%esi), %eax\n"
        "movl %eax, 0x74(%ebx)\n" /* state */
        "xorl %eax, %eax\n"
        "jmp .Lf1f450e_001f453d\n"
        "movl 0x74(%ebx), %eax\n" /* line 1959 | state */
        "movl 0x10(%ebp), %edx\n" /* ptr */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1f450e_001f453d\n"
        /* { scope 1 */
        "movl 0x14(%ebx), %eax\n" /* line 1965 | state */
        "testl %eax, %eax\n"
        "jle .Lf1f450e_001f467c\n"
        "xorl %ecx, %ecx\n"
        ".Lf1f450e_001f46ac:\n"
        "leal (, %ecx, 4), %eax\n"
        "movl 0x58(%ebx), %edx\n" /* line 1966 | state */
        "movl (%edx, %eax), %edx\n"
        "movl 0x10(%ebp), %esi\n" /* ptr */
        "movl %edx, (%esi, %eax)\n"
        "addl $1, %ecx\n" /* line 1965 */
        "cmpl 0x14(%ebx), %ecx\n" /* state */
        "jl .Lf1f450e_001f46ac\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 1990 */
        "jmp .Lf1f450e_001f467e\n"
        /* { scope 1 */
        "movl 0xc(%ebx), %eax\n" /* line 1973 | state */
        "testl %eax, %eax\n"
        "jle .Lf1f450e_001f467c\n"
        "xorl %ecx, %ecx\n"
        ".Lf1f450e_001f46d4:\n"
        "leal (, %ecx, 4), %eax\n"
        "movl 0x3c(%ebx), %edx\n" /* line 1974 | state */
        "movl (%edx, %eax), %edx\n"
        "movl 0x10(%ebp), %esi\n" /* ptr */
        "movl %edx, (%esi, %eax)\n"
        "addl $1, %ecx\n" /* line 1973 */
        "cmpl %ecx, 0xc(%ebx)\n" /* state */
        "jg .Lf1f450e_001f46d4\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 1990 */
        "jmp .Lf1f450e_001f467e\n"
        /* { scope 1 */
        "movl 0xc(%ebx), %eax\n" /* line 1981 | state */
        "testl %eax, %eax\n"
        "jle .Lf1f450e_001f467c\n"
        "xorl %ecx, %ecx\n"
        ".Lf1f450e_001f46fc:\n"
        "leal (, %ecx, 4), %eax\n"
        "movl 0x40(%ebx), %edx\n" /* line 1982 | state */
        "movl (%edx, %eax), %edx\n"
        "movl 0x10(%ebp), %esi\n" /* ptr */
        "movl %edx, (%esi, %eax)\n"
        "addl $1, %ecx\n" /* line 1981 */
        "cmpl 0xc(%ebx), %ecx\n" /* state */
        "jl .Lf1f450e_001f46fc\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 1990 */
        "jmp .Lf1f450e_001f467e\n"
        "movl 0x1ec(%ebx), %eax\n" /* line 1986 | state */
        "movl 0x10(%ebp), %edx\n" /* ptr */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1f450e_001f453d\n"
        ".Lf1f450e_001f4730:\n"
        "movl 0x24(%ebx), %eax\n" /* line 1920 | state */
        "leal (%eax, %eax, 4), %eax\n"
        "cltd\n"
        "idivl 0xc(%ebx)\n" /* state */
        "movl 0x10(%ebp), %edx\n" /* ptr */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1f450e_001f453d\n"
    );
}

