/* ASM dump from: sb_celp.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/speex/sb_celp.c */

#include "common_types.h"
#include "imports.h"

static const float h0[64]; /* 0x3053e0 */
static const float h1[64]; /* 0x3052e0 */

int * sb_encoder_init(const SpeexMode *m);
int sb_encoder_destroy(int *state);
int sb_encode(int *state, int *vin, SpeexBits *bits);
int * sb_decoder_init(const SpeexMode *m);
int sb_decoder_destroy(int *state);
int sb_encoder_ctl(int *state, int request, int *ptr);
int sb_decoder_ctl(int *state, int request, int *ptr);
static int sb_decode_lost(char * (*out)[16], int dtx, char *stack);
int sb_decode(int *state, SpeexBits *bits, int *vout);

/* line 224 */
__attribute__((naked))
int * sb_encoder_init(const SpeexMode *m)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 224 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* m */
        /* { scope 1 */
        "movl $0x1098, (%esp)\n" /* line 236 */
        "calll speex_alloc\n"
        "movl %eax, %edi\n" /* st */
        "testl %eax, %eax\n" /* line 237 */
        "je .Lf1ea314_001ea843\n"
        "leal 0xf8(%eax), %eax\n" /* line 239 */
        "movl %eax, 0x38(%edi)\n" /* st */
        "movl %ebx, (%edi)\n" /* line 241 | mode, st */
        "movl (%ebx), %ebx\n" /* line 242 | mode */
        "movl (%ebx), %eax\n" /* line 245 | mode */
        "movl %eax, (%esp)\n"
        "calll speex_encoder_init\n"
        "movl %eax, 4(%edi)\n" /* st */
        "movl 4(%ebx), %eax\n" /* line 246 | mode */
        "addl %eax, %eax\n"
        "movl %eax, 8(%edi)\n" /* st */
        "movl 4(%ebx), %esi\n" /* line 247 | mode */
        "movl %esi, 0xc(%edi)\n" /* st */
        "movl 8(%ebx), %eax\n" /* line 248 | mode */
        "movl %eax, 0x10(%edi)\n" /* st */
        "movl 4(%ebx), %eax\n" /* line 249 | mode */
        "cltd\n"
        "idivl 8(%ebx)\n" /* mode */
        "movl %eax, 0x14(%edi)\n" /* st */
        "leal (%esi, %esi, 2), %edx\n" /* line 250 */
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "movl %eax, 0x18(%edi)\n" /* st */
        "movl 0xc(%ebx), %eax\n" /* line 251 | mode */
        "movl %eax, 0x1c(%edi)\n" /* st */
        "movl 0x10(%ebx), %eax\n" /* line 252 | mode */
        "movl %eax, 0x20(%edi)\n" /* st */
        "movl $1, 0xe0(%edi)\n" /* line 254 | st */
        "leal 0x28(%ebx), %eax\n" /* line 255 | mode */
        "movl %eax, 0xe4(%edi)\n" /* st */
        "movl 0x48(%ebx), %eax\n" /* line 256 | mode */
        "movl %eax, 0xe8(%edi)\n" /* st */
        "movl %eax, 0xec(%edi)\n" /* st */
        "movl $9, -0x1c(%ebp)\n" /* line 258 | i */
        "leal -0x1c(%ebp), %eax\n" /* line 259 | i */
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* st */
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        "movl 0x1c(%ebx), %eax\n" /* line 261 | mode */
        "movl %eax, 0x28(%edi)\n" /* st */
        "movl 0x20(%ebx), %eax\n" /* line 262 | mode */
        "movl %eax, 0x2c(%edi)\n" /* st */
        "movl 0x14(%ebx), %eax\n" /* line 263 | mode */
        "movl %eax, 0x30(%edi)\n" /* st */
        "movl 0x18(%ebx), %eax\n" /* line 264 | mode */
        "movl %eax, 0x34(%edi)\n" /* st */
        "movl $1, 0x24(%edi)\n" /* line 265 | st */
        "movl 0xc(%edi), %eax\n" /* line 268 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x3c(%edi)\n" /* st */
        "movl 0xc(%edi), %eax\n" /* line 269 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x40(%edi)\n" /* st */
        "movl 8(%edi), %eax\n" /* line 270 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x44(%edi)\n" /* st */
        "movl 8(%edi), %eax\n" /* line 271 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x48(%edi)\n" /* st */
        "movl 8(%edi), %eax\n" /* line 272 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x4c(%edi)\n" /* st */
        "movl $0x100, (%esp)\n" /* line 274 */
        "calll speex_alloc\n"
        "movl %eax, 0x50(%edi)\n" /* st */
        "movl $0x100, (%esp)\n" /* line 275 */
        "calll speex_alloc\n"
        "movl %eax, 0x54(%edi)\n" /* st */
        "movl $0x100, (%esp)\n" /* line 276 */
        "calll speex_alloc\n"
        "movl %eax, 0x58(%edi)\n" /* st */
        "movl $0x100, (%esp)\n" /* line 277 */
        "calll speex_alloc\n"
        "movl %eax, 0x5c(%edi)\n" /* st */
        "movl 0x18(%edi), %eax\n" /* line 279 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x68(%edi)\n" /* st */
        "movl 0x20(%edi), %eax\n" /* line 280 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x60(%edi)\n" /* st */
        "movl 0x20(%edi), %edx\n" /* line 281 | st */
        "leal (%eax, %edx, 4), %edx\n"
        "movl 0x18(%edi), %eax\n" /* st */
        "shll $2, %eax\n"
        "subl %eax, %edx\n"
        "movl %edx, 0x64(%edi)\n" /* st */
        "movl 0xc(%edi), %eax\n" /* line 283 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x6c(%edi)\n" /* st */
        "movl 0xc(%edi), %eax\n" /* line 284 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x70(%edi)\n" /* st */
        "movl 0xc(%edi), %eax\n" /* line 285 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x74(%edi)\n" /* st */
        "movl 0x10(%edi), %edx\n" /* line 289 | st */
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, %ecx\n"
        "shrl $0x1f, %ecx\n"
        "addl %eax, %ecx\n"
        "movl %ecx, -0x3c(%ebp)\n"
        "sarl -0x3c(%ebp)\n"
        "leal (%edx, %edx, 4), %edx\n" /* line 290 */
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "sarl -0x40(%ebp)\n"
        "movl 0x18(%edi), %eax\n" /* line 291 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x78(%edi)\n" /* st */
        "movl $0, -0x1c(%ebp)\n" /* line 292 | i */
        "movl -0x3c(%ebp), %edx\n"
        "testl %edx, %edx\n"
        "jg .Lf1ea314_001ea714\n"
        "movl $0, -0x1c(%ebp)\n" /* line 294 | i */
        "movl -0x40(%ebp), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf1ea314_001ea77f\n"
        ".Lf1ea314_001ea540:\n"
        "movl 0x1c(%edi), %eax\n" /* line 298 | st */
        "leal 4(, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x7c(%edi)\n" /* st */
        "movl $0, -0x1c(%ebp)\n" /* line 299 | i */
        "movl 0x1c(%edi), %edx\n" /* st */
        "leal 1(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf1ea314_001ea7e2\n"
        ".Lf1ea314_001ea56a:\n"
        "leal 4(, %edx, 4), %eax\n" /* line 302 */
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x80(%edi)\n" /* st */
        "movl 0x1c(%edi), %eax\n" /* line 303 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x84(%edi)\n" /* st */
        "movl 0x1c(%edi), %eax\n" /* line 304 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0xa8(%edi)\n" /* st */
        "movl 0x1c(%edi), %eax\n" /* line 305 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0xac(%edi)\n" /* st */
        "movl 0x1c(%edi), %eax\n" /* line 306 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x88(%edi)\n" /* st */
        "movl 0x1c(%edi), %eax\n" /* line 307 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x8c(%edi)\n" /* st */
        "movl 0x1c(%edi), %eax\n" /* line 308 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x90(%edi)\n" /* st */
        "movl 0x1c(%edi), %eax\n" /* line 309 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x94(%edi)\n" /* st */
        "movl 0x1c(%edi), %eax\n" /* line 310 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x98(%edi)\n" /* st */
        "movl 0x1c(%edi), %eax\n" /* line 311 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x9c(%edi)\n" /* st */
        "movl 0x1c(%edi), %eax\n" /* line 312 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0xa0(%edi)\n" /* st */
        "movl 0x1c(%edi), %eax\n" /* line 313 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0xa4(%edi)\n" /* st */
        "movl 0x14(%edi), %eax\n" /* line 314 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0xbc(%edi)\n" /* st */
        "movl 0x1c(%edi), %eax\n" /* line 316 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0xb0(%edi)\n" /* st */
        "movl 0x1c(%edi), %eax\n" /* line 317 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0xb4(%edi)\n" /* st */
        "movl 0x1c(%edi), %eax\n" /* line 318 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0xb8(%edi)\n" /* st */
        "movl $0x41000000, 0xc0(%edi)\n" /* line 320 | st */
        "movl $0, 0xc4(%edi)\n" /* line 321 | st */
        "movl $0, 0xd8(%edi)\n" /* line 322 | st */
        "movl $0, 0xc8(%edi)\n" /* line 323 | st */
        "movl $0, 0xdc(%edi)\n" /* line 324 | st */
        "movl $2, 0xf0(%edi)\n" /* line 326 | st */
        "leal 0xf4(%edi), %eax\n" /* line 327 | st */
        "movl %eax, 8(%esp)\n"
        "movl $0x19, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* st */
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        "shll 0xf4(%edi)\n" /* line 328 | st */
        "movl %edi, %eax\n" /* line 333 | st */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 334 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1ea314_001ea714:\n"
        "cvtsi2sdl -0x3c(%ebp), %xmm0\n" /* line 292 */
        "movsd %xmm0, -0x38(%ebp)\n"
        "xorl %esi, %esi\n"
        ".Lf1ea314_001ea720:\n"
        "movl 0x78(%edi), %ebx\n" /* line 293 | st, mode */
        "cvtsi2sdl %esi, %xmm0\n"
        "mulsd 0x307c28, %xmm0\n" /* 3.141592653589793 */
        "divsd -0x38(%ebp), %xmm0\n"
        "movsd %xmm0, (%esp)\n"
        "calll cos\n"
        "fstpl -0x50(%ebp)\n"
        "movsd -0x50(%ebp), %xmm0\n"
        "mulsd 0x307dc0, %xmm0\n" /* -0.46 */
        "addsd 0x307dc8, %xmm0\n" /* 0.54 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%ebx, %esi, 4)\n" /* mode */
        "movl -0x1c(%ebp), %esi\n" /* line 292 | i */
        "addl $1, %esi\n"
        "movl %esi, -0x1c(%ebp)\n" /* i */
        "cmpl %esi, -0x3c(%ebp)\n"
        "jg .Lf1ea314_001ea720\n"
        "movl $0, -0x1c(%ebp)\n" /* line 294 | i */
        "movl -0x40(%ebp), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf1ea314_001ea540\n"
        ".Lf1ea314_001ea77f:\n"
        "cvtsi2sdl -0x40(%ebp), %xmm0\n"
        "movsd %xmm0, -0x30(%ebp)\n"
        "xorl %eax, %eax\n"
        ".Lf1ea314_001ea78b:\n"
        "movl -0x3c(%ebp), %esi\n" /* line 295 */
        "addl %eax, %esi\n"
        "movl 0x78(%edi), %ebx\n" /* st, mode */
        "cvtsi2sdl %eax, %xmm0\n"
        "mulsd 0x307c28, %xmm0\n" /* 3.141592653589793 */
        "divsd -0x30(%ebp), %xmm0\n"
        "movsd %xmm0, (%esp)\n"
        "calll cos\n"
        "fstpl -0x50(%ebp)\n"
        "movsd -0x50(%ebp), %xmm0\n"
        "mulsd 0x307dd0, %xmm0\n" /* 0.46 */
        "addsd 0x307dc8, %xmm0\n" /* 0.54 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%ebx, %esi, 4)\n" /* mode */
        "movl -0x1c(%ebp), %eax\n" /* line 294 | i */
        "addl $1, %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        "cmpl %eax, -0x40(%ebp)\n"
        "jg .Lf1ea314_001ea78b\n"
        "jmp .Lf1ea314_001ea540\n"
        ".Lf1ea314_001ea7e2:\n"
        "xorl %esi, %esi\n" /* line 299 */
        ".Lf1ea314_001ea7e4:\n"
        "cvtss2sd 0x28(%edi), %xmm0\n" /* line 300 | st */
        "mulsd 0x307c98, %xmm0\n" /* 6.283185307179586 */
        "cvtsi2sdl %esi, %xmm1\n"
        "mulsd %xmm1, %xmm0\n"
        "movl 0x7c(%edi), %ebx\n" /* st, mode */
        "mulsd %xmm0, %xmm0\n"
        "mulsd 0x307dd8, %xmm0\n" /* -0.5 */
        "movsd %xmm0, (%esp)\n"
        "calll exp\n"
        "fstpl -0x50(%ebp)\n"
        "movsd -0x50(%ebp), %xmm0\n"
        "mulsd 0x307de0, %xmm0\n" /* 16384.0 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%ebx, %esi, 4)\n" /* mode */
        "movl -0x1c(%ebp), %esi\n" /* line 299 | i */
        "addl $1, %esi\n"
        "movl %esi, -0x1c(%ebp)\n" /* i */
        "movl 0x1c(%edi), %edx\n" /* st */
        "leal 1(%edx), %eax\n"
        "cmpl %esi, %eax\n"
        "jg .Lf1ea314_001ea7e4\n"
        "jmp .Lf1ea314_001ea56a\n"
        ".Lf1ea314_001ea843:\n"
        "xorl %eax, %eax\n" /* line 237 */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 334 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 336 */
__attribute__((naked))
int sb_encoder_destroy(int *state)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 336 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* state */
        "movl 4(%ebx), %eax\n" /* line 340 | state */
        "movl %eax, (%esp)\n"
        "calll speex_encoder_destroy\n"
        "movl %ebx, 8(%ebp)\n" /* line 342 | state */
        "addl $0x14, %esp\n" /* line 343 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp speex_free\n" /* line 342 */
    );
}

/* line 346 */
__attribute__((naked))
int sb_encode(int *state, int *vin, SpeexBits *bits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 346 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x11c, %esp\n"
        "movl 8(%ebp), %edi\n" /* state */
        /* { scope 1: e_low, exc, sp, res, ... */
        "movl 0x38(%edi), %edx\n" /* line 362 | state */
        "movl (%edi), %eax\n" /* line 363 | state */
        "movl (%eax), %eax\n"
        "movl %eax, -0x70(%ebp)\n" /* mode */
        /* { scope 2: modeid, scale, el */
        "movl %edx, %eax\n" /* line 367 */
        "negl %eax\n"
        "andl $3, %eax\n"
        "addl %eax, %edx\n"
        "movl 0xc(%edi), %eax\n" /* state */
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl %edx, %esi\n" /* low */
        "movl %eax, 0x1c(%esp)\n" /* line 370 */
        "movl 0x50(%edi), %eax\n" /* state */
        "movl %eax, 0x18(%esp)\n"
        "movl $0x40, 0x14(%esp)\n"
        "movl 8(%edi), %eax\n" /* state */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x40(%edi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x3c(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl $h0, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* vin */
        "movl %eax, (%esp)\n"
        "calll qmf_decomp\n"
        "movl 0xc(%edi), %eax\n" /* line 372 | state */
        "testl %eax, %eax\n"
        "jle .Lf1ea870_001ea8f9\n"
        "xorl %ecx, %ecx\n"
        ".Lf1ea870_001ea8e1:\n"
        "leal (, %ecx, 4), %eax\n"
        "movl 0x3c(%edi), %edx\n" /* line 373 | state */
        "movl (%edx, %eax), %edx\n"
        "movl %edx, (%esi, %eax)\n" /* low */
        "addl $1, %ecx\n" /* line 372 */
        "cmpl 0xc(%edi), %ecx\n" /* state */
        "jl .Lf1ea870_001ea8e1\n"
        ".Lf1ea870_001ea8f9:\n"
        "movl 0x10(%ebp), %eax\n" /* line 376 | bits */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* low */
        "movl 4(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_encode_native\n"
        "movl 0xc(%edi), %ebx\n" /* line 378 | state */
        "testl %ebx, %ebx\n"
        "jle .Lf1ea870_001ea930\n"
        "xorl %ebx, %ebx\n"
        ".Lf1ea870_001ea918:\n"
        "leal (, %ebx, 4), %eax\n"
        "movl 0x3c(%edi), %ecx\n" /* line 379 | state */
        "movl (%esi, %eax), %edx\n" /* low */
        "movl %edx, (%ecx, %eax)\n"
        "addl $1, %ebx\n" /* line 378 */
        "cmpl 0xc(%edi), %ebx\n" /* state */
        "jl .Lf1ea870_001ea918\n"
        /* } scope */
        ".Lf1ea870_001ea930:\n"
        "movl 0xc(%edi), %ecx\n" /* line 382 | state */
        "movl 0x18(%edi), %edx\n" /* state */
        "movl %edx, %eax\n"
        "subl %ecx, %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf1ea870_001ea95d\n"
        "xorl %ebx, %ebx\n"
        ".Lf1ea870_001ea940:\n"
        "movl 0x44(%edi), %edx\n" /* line 383 | state */
        "leal (%ebx, %ecx), %eax\n"
        "movl (%edx, %eax, 4), %eax\n"
        "movl %eax, (%edx, %ebx, 4)\n"
        "addl $1, %ebx\n" /* line 382 */
        "movl 0xc(%edi), %ecx\n" /* state */
        "movl 0x18(%edi), %edx\n" /* state */
        "movl %edx, %eax\n"
        "subl %ecx, %eax\n"
        "cmpl %eax, %ebx\n"
        "jl .Lf1ea870_001ea940\n"
        ".Lf1ea870_001ea95d:\n"
        "testl %ecx, %ecx\n" /* line 384 */
        "jle .Lf1ea870_001ea983\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf1ea870_001ea968\n"
        ".Lf1ea870_001ea965:\n"
        "movl 0x18(%edi), %edx\n" /* state */
        ".Lf1ea870_001ea968:\n"
        "subl %ecx, %edx\n" /* line 385 */
        "leal (%ebx, %edx), %ecx\n"
        "movl 0x44(%edi), %edx\n" /* state */
        "movl 0x40(%edi), %eax\n" /* state */
        "movl (%eax, %ebx, 4), %eax\n"
        "movl %eax, (%edx, %ecx, 4)\n"
        "addl $1, %ebx\n" /* line 384 */
        "movl 0xc(%edi), %ecx\n" /* state */
        "cmpl %ebx, %ecx\n"
        "jg .Lf1ea870_001ea965\n"
        ".Lf1ea870_001ea983:\n"
        "movl 0x60(%edi), %edx\n" /* line 387 | state */
        "movl 0x20(%edi), %eax\n" /* state */
        "subl %ecx, %eax\n"
        "shll $2, %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal (%edx, %ecx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll speex_move\n"
        "movl $4, %esi\n" /* line 390 | low */
        "movl %esi, %eax\n" /* low */
        "subl -0x38(%ebp), %eax\n"
        "andl $3, %eax\n"
        "addl -0x38(%ebp), %eax\n"
        "movl 0x14(%edi), %ebx\n" /* state */
        "leal (%eax, %ebx, 4), %ebx\n"
        "movl %eax, -0x7c(%ebp)\n" /* low_pi_gain */
        "movl %esi, %eax\n" /* line 391 | low */
        "subl %ebx, %eax\n"
        "andl $3, %eax\n"
        "addl %eax, %ebx\n"
        "movl 0xc(%edi), %edx\n" /* state */
        "shll $2, %edx\n"
        "addl %edx, %ebx\n"
        "movl %ebx, %ecx\n"
        "subl %edx, %ecx\n"
        "movl %ecx, -0x78(%ebp)\n" /* low_exc */
        "movl %esi, %eax\n" /* line 392 | low */
        "subl %ebx, %eax\n"
        "andl $3, %eax\n"
        "addl %eax, %ebx\n"
        "leal (%edx, %ebx), %ebx\n"
        "movl %ebx, %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, -0x74(%ebp)\n" /* low_innov */
        "movl -0x7c(%ebp), %edx\n" /* line 393 | low_pi_gain */
        "movl %edx, 8(%esp)\n"
        "movl $0x64, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        "movl -0x78(%ebp), %ecx\n" /* line 394 | low_exc */
        "movl %ecx, 8(%esp)\n"
        "movl $0x65, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        "movl -0x74(%ebp), %eax\n" /* line 395 | low_innov */
        "movl %eax, 8(%esp)\n"
        "movl $0x66, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        "leal -0x1c(%ebp), %eax\n" /* line 397 | dtx */
        "movl %eax, 8(%esp)\n"
        "movl $9, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        "xorl %eax, %eax\n" /* line 400 */
        "cmpl $0, -0x1c(%ebp)\n" /* dtx */
        "sete %al\n"
        "movl %eax, -0x1c(%ebp)\n" /* dtx */
        /* { scope 2: modeid, scale, el */
        "subl %ebx, %esi\n" /* line 406 | w_sig, low */
        "andl $3, %esi\n" /* low */
        "addl %esi, %ebx\n" /* low, w_sig */
        "movl 0x18(%edi), %eax\n" /* state */
        "leal (%ebx, %eax, 4), %edx\n" /* w_sig */
        "movl %edx, -0x34(%ebp)\n"
        "testl %eax, %eax\n" /* line 408 */
        "jle .Lf1ea870_001eaa95\n"
        "xorl %esi, %esi\n" /* low */
        ".Lf1ea870_001eaa6f:\n"
        "leal (, %esi, 4), %eax\n"
        "movl 0x44(%edi), %edx\n" /* line 409 | state */
        "movl 0x78(%edi), %ecx\n" /* state */
        "movss (%edx, %eax), %xmm0\n"
        "mulss (%ecx, %eax), %xmm0\n"
        "movss %xmm0, (%ebx, %eax)\n" /* w_sig */
        "addl $1, %esi\n" /* line 408 | low */
        "movl 0x18(%edi), %eax\n" /* state */
        "cmpl %esi, %eax\n" /* low */
        "jg .Lf1ea870_001eaa6f\n"
        ".Lf1ea870_001eaa95:\n"
        "movl %eax, 0xc(%esp)\n" /* line 412 */
        "movl 0x1c(%edi), %eax\n" /* state */
        "addl $1, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x80(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* w_sig */
        "calll _spx_autocorr\n"
        /* } scope */
        "movl 0x80(%edi), %eax\n" /* line 415 | state */
        "movss (%eax), %xmm0\n"
        "mulss 0x2c(%edi), %xmm0\n" /* state */
        "movss %xmm0, (%eax)\n"
        "movl 0x1c(%edi), %edx\n" /* line 418 | state */
        "leal 1(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf1ea870_001eab00\n"
        "xorl %ebx, %ebx\n" /* w_sig */
        ".Lf1ea870_001eaad4:\n"
        "leal (, %ebx, 4), %edx\n"
        "movl %edx, %ecx\n" /* line 419 */
        "addl 0x80(%edi), %ecx\n" /* state */
        "movl 0x7c(%edi), %eax\n" /* state */
        "movss (%ecx), %xmm0\n"
        "mulss (%eax, %edx), %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "addl $1, %ebx\n" /* line 418 | w_sig */
        "movl 0x1c(%edi), %edx\n" /* state */
        "leal 1(%edx), %eax\n"
        "cmpl %ebx, %eax\n" /* w_sig */
        "jg .Lf1ea870_001eaad4\n"
        ".Lf1ea870_001eab00:\n"
        "movl %edx, 8(%esp)\n" /* line 422 */
        "movl 0x80(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x84(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll _spx_lpc\n"
        "fstp %st(0)\n"
        "movl -0x34(%ebp), %ecx\n" /* line 425 */
        "movl %ecx, 0x14(%esp)\n"
        "movl $0x3e4ccccd, 0x10(%esp)\n"
        "movl $0xf, 0xc(%esp)\n"
        "movl 0x88(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x1c(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x84(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll lpc_to_lsp\n"
        "movl 0x1c(%edi), %edx\n" /* line 426 | state */
        "cmpl %edx, %eax\n"
        "je .Lf1ea870_001eab9d\n"
        "movl -0x34(%ebp), %ebx\n" /* line 428 | w_sig */
        "movl %ebx, 0x14(%esp)\n" /* w_sig */
        "movl $0x3d4ccccd, 0x10(%esp)\n"
        "movl $0xb, 0xc(%esp)\n"
        "movl 0x88(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl 0x84(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll lpc_to_lsp\n"
        "movl 0x1c(%edi), %ebx\n" /* line 429 | state, w_sig */
        "cmpl %ebx, %eax\n" /* w_sig */
        "je .Lf1ea870_001eab9d\n"
        "testl %ebx, %ebx\n" /* line 431 | w_sig */
        "jg .Lf1ea870_001eb094\n"
        ".Lf1ea870_001eab9d:\n"
        "movl 0xc4(%edi), %ecx\n" /* line 439 | state */
        "testl %ecx, %ecx\n"
        "jne .Lf1ea870_001ead27\n"
        "movl 0xd8(%edi), %edx\n" /* state */
        "testl %edx, %edx\n"
        "jne .Lf1ea870_001ead27\n"
        ".Lf1ea870_001eabb9:\n"
        "movl 0xe0(%edi), %eax\n" /* line 519 | state */
        "testl %eax, %eax\n"
        "jne .Lf1ea870_001eb02f\n"
        ".Lf1ea870_001eabc7:\n"
        "movl -0x1c(%ebp), %esi\n" /* line 529 | dtx, low */
        "testl %esi, %esi\n" /* low */
        "jne .Lf1ea870_001eaf93\n"
        "movl 0xe8(%edi), %edx\n" /* state */
        "movl 0xe4(%edi), %eax\n" /* state */
        "movl (%eax, %edx, 4), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1ea870_001eaf93\n"
        "movl 0x10(%ebp), %ebx\n" /* line 558 | bits, w_sig */
        "movl %ebx, 0xc(%esp)\n" /* w_sig */
        "movl 0x1c(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x8c(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x88(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll *0x10(%edx)\n"
        "movl 0x24(%edi), %ecx\n" /* line 560 | state */
        "testl %ecx, %ecx\n"
        "je .Lf1ea870_001eac68\n"
        "movl 0x1c(%edi), %ebx\n" /* line 562 | state, w_sig */
        "testl %ebx, %ebx\n" /* w_sig */
        "jle .Lf1ea870_001eac68\n"
        "xorl %ebx, %ebx\n" /* w_sig */
        ".Lf1ea870_001eac1d:\n"
        "leal (, %ebx, 4), %edx\n" /* line 560 */
        "movl 0x90(%edi), %ecx\n" /* line 563 | state */
        "movl 0x88(%edi), %eax\n" /* state */
        "movl (%eax, %edx), %eax\n"
        "movl %eax, (%ecx, %edx)\n"
        "addl $1, %ebx\n" /* line 562 | w_sig */
        "cmpl %ebx, 0x1c(%edi)\n" /* w_sig, state */
        "jg .Lf1ea870_001eac1d\n"
        "movl 0x1c(%edi), %edx\n" /* line 564 | state */
        "testl %edx, %edx\n"
        "jle .Lf1ea870_001eac68\n"
        "xorl %ebx, %ebx\n" /* w_sig */
        ".Lf1ea870_001eac47:\n"
        "leal (, %ebx, 4), %edx\n"
        "movl 0x94(%edi), %ecx\n" /* line 565 | state */
        "movl 0x8c(%edi), %eax\n" /* state */
        "movl (%eax, %edx), %eax\n"
        "movl %eax, (%ecx, %edx)\n"
        "addl $1, %ebx\n" /* line 564 | w_sig */
        "cmpl %ebx, 0x1c(%edi)\n" /* w_sig, state */
        "jg .Lf1ea870_001eac47\n"
        ".Lf1ea870_001eac68:\n"
        "movl $4, %ecx\n" /* line 568 */
        "movl %ecx, %eax\n"
        "subl -0x34(%ebp), %eax\n"
        "andl $3, %eax\n"
        "addl -0x34(%ebp), %eax\n"
        "movl 0x1c(%edi), %ebx\n" /* state, w_sig */
        "leal (%eax, %ebx, 4), %edx\n"
        "movl %eax, -0x88(%ebp)\n" /* mem */
        "movl %ecx, %eax\n" /* line 569 */
        "subl %edx, %eax\n"
        "andl $3, %eax\n"
        "addl %eax, %edx\n"
        "movl 0x10(%edi), %eax\n" /* state */
        "shll $2, %eax\n"
        "addl %eax, %edx\n"
        "movl %edx, %esi\n" /* low */
        "subl %eax, %esi\n" /* low */
        "movl %esi, -0x80(%ebp)\n" /* low, syn_resp */
        "subl %edx, %ecx\n" /* line 570 */
        "andl $3, %ecx\n"
        "addl %ecx, %edx\n"
        "leal (%eax, %edx), %edx\n"
        "movl %edx, -0x30(%ebp)\n"
        "subl %eax, %edx\n"
        "movl %edx, -0x84(%ebp)\n" /* innov */
        "movl 0x14(%edi), %edx\n" /* line 572 | state */
        "testl %edx, %edx\n"
        "jg .Lf1ea870_001eb112\n"
        ".Lf1ea870_001eacbc:\n"
        "movl 0x1c(%edi), %eax\n" /* line 782 | state */
        "testl %eax, %eax\n"
        "jle .Lf1ea870_001ead10\n"
        "xorl %ebx, %ebx\n" /* w_sig */
        ".Lf1ea870_001eacc5:\n"
        "leal (, %ebx, 4), %edx\n"
        "movl 0x90(%edi), %ecx\n" /* line 783 | state */
        "movl 0x88(%edi), %eax\n" /* state */
        "movl (%eax, %edx), %eax\n"
        "movl %eax, (%ecx, %edx)\n"
        "addl $1, %ebx\n" /* line 782 | w_sig */
        "cmpl 0x1c(%edi), %ebx\n" /* state, w_sig */
        "jl .Lf1ea870_001eacc5\n"
        "movl 0x1c(%edi), %esi\n" /* line 784 | state, low */
        "testl %esi, %esi\n" /* low */
        "jle .Lf1ea870_001ead10\n"
        "xorl %ebx, %ebx\n" /* w_sig */
        ".Lf1ea870_001eacef:\n"
        "leal (, %ebx, 4), %edx\n"
        "movl 0x94(%edi), %ecx\n" /* line 785 | state */
        "movl 0x8c(%edi), %eax\n" /* state */
        "movl (%eax, %edx), %eax\n"
        "movl %eax, (%ecx, %edx)\n"
        "addl $1, %ebx\n" /* line 784 | w_sig */
        "cmpl 0x1c(%edi), %ebx\n" /* state, w_sig */
        "jl .Lf1ea870_001eacef\n"
        ".Lf1ea870_001ead10:\n"
        "movl $0, 0x24(%edi)\n" /* line 787 | state */
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x11c, %esp\n" /* line 790 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: e_low, exc, sp, res, ... */
        ".Lf1ea870_001ead27:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 439 | dtx */
        "testl %eax, %eax\n"
        "jne .Lf1ea870_001eabb9\n"
        /* { scope 2: modeid, scale, el */
        "movl 0xc8(%edi), %eax\n" /* line 443 | state */
        "testl %eax, %eax\n"
        "je .Lf1ea870_001eadea\n"
        /* { scope 3: bitrate, innov2 */
        "movss 0xcc(%edi), %xmm1\n" /* line 446 | state */
        "movaps %xmm1, %xmm0\n"
        "mulss 0xd0(%edi), %xmm0\n" /* state */
        "pxor %xmm3, %xmm3\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lf1ea870_001ebbec\n"
        "cvtss2sd %xmm1, %xmm1\n" /* line 449 */
        "mulsd 0x307de8, %xmm1\n" /* -1e-05 */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "addss 0xd4(%edi), %xmm0\n" /* state */
        "cvtss2sd %xmm0, %xmm0\n"
        "divsd %xmm0, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm0\n"
        "cvtss2sd %xmm0, %xmm2\n" /* line 450 */
        "ucomisd 0x307d10, %xmm2\n" /* 0.1 */
        "jbe .Lf1ea870_001eada6\n"
        "movss 0x2ed7d0, %xmm0\n" /* 0.10000000149011612f */
        "movsd 0x307df0, %xmm2\n" /* 0.10000000149011612 */
        ".Lf1ea870_001eada6:\n"
        "ucomisd 0x307df8, %xmm2\n" /* line 452 | -0.1 */
        "jae .Lf1ea870_001eadba\n"
        "jp .Lf1ea870_001eadba\n"
        "movss 0x2ed7d4, %xmm0\n" /* -0.10000000149011612f */
        ".Lf1ea870_001eadba:\n"
        "addss 0xc0(%edi), %xmm0\n" /* line 455 | state */
        "movss %xmm0, 0xc0(%edi)\n" /* state */
        "ucomiss 0x2ed6b4, %xmm0\n" /* line 456 | 10.0f */
        "jbe .Lf1ea870_001eaddd\n"
        "movl $0x41200000, 0xc0(%edi)\n" /* line 457 | state */
        ".Lf1ea870_001eaddd:\n"
        "ucomiss 0xc0(%edi), %xmm3\n" /* line 458 | state */
        "ja .Lf1ea870_001ebbdd\n"
        /* } scope */
        ".Lf1ea870_001eadea:\n"
        "movl 0xc(%edi), %eax\n" /* line 464 | state */
        "movl %eax, 4(%esp)\n"
        "movl 0x3c(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll compute_rms\n"
        "fstps -0x6c(%ebp)\n" /* e_low */
        "movl 0xc(%edi), %eax\n" /* line 465 | state */
        "movl %eax, 4(%esp)\n"
        "movl 0x44(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll compute_rms\n"
        "fstps -0xcc(%ebp)\n"
        "movss -0xcc(%ebp), %xmm0\n"
        "movss 0x2ed5d0, %xmm1\n" /* line 466 | 1.0f */
        "addss %xmm1, %xmm0\n"
        "addss -0x6c(%ebp), %xmm1\n" /* e_low */
        "divss %xmm1, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, (%esp)\n"
        "calll log\n"
        "fstpl -0xd8(%ebp)\n"
        "movsd -0xd8(%ebp), %xmm0\n"
        "addsd %xmm0, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "leal 0xdc(%edi), %eax\n" /* line 468 | state */
        "movl %eax, 8(%esp)\n"
        "movl $0x1d, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0xc8(%ebp)\n"
        "calll speex_encoder_ctl\n"
        "movss -0xc8(%ebp), %xmm0\n" /* line 469 */
        "ucomiss 0x2ed794, %xmm0\n" /* -4.0f */
        "jae .Lf1ea870_001eb077\n"
        "jp .Lf1ea870_001eb077\n"
        "movss 0x2ed794, %xmm0\n" /* -4.0f */
        ".Lf1ea870_001eaea0:\n"
        "movss 0x2ed62c, %xmm1\n" /* 2.0f */
        ".Lf1ea870_001eaea8:\n"
        "movl 0xc4(%edi), %eax\n" /* line 474 | state */
        "testl %eax, %eax\n"
        "je .Lf1ea870_001eb0f5\n"
        /* { scope 3: bitrate, innov2 */
        "movl -0x70(%ebp), %esi\n" /* line 477 | mode, low */
        "movl 0xa8(%esi), %eax\n" /* low */
        "subl $1, %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* modeid */
        "addss %xmm1, %xmm0\n" /* line 478 */
        "addss 0xdc(%edi), %xmm0\n" /* state */
        "movss %xmm0, 0xdc(%edi)\n" /* state */
        "ucomiss 0x2ed5dc, %xmm0\n" /* line 479 | -1.0f */
        "jb .Lf1ea870_001ebbf4\n"
        ".Lf1ea870_001eaee6:\n"
        "movl -0x20(%ebp), %ebx\n" /* line 481 | modeid, w_sig */
        "testl %ebx, %ebx\n" /* w_sig */
        "jne .Lf1ea870_001ebae6\n"
        ".Lf1ea870_001eaef1:\n"
        "leal -0x20(%ebp), %eax\n" /* line 495 | modeid */
        "movl %eax, 8(%esp)\n"
        "movl $0xa, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* state */
        "calll speex_encoder_ctl\n"
        "movl 0xc8(%edi), %eax\n" /* line 496 | state */
        "testl %eax, %eax\n"
        "je .Lf1ea870_001eabb9\n"
        /* { scope 4 */
        "leal -0x24(%ebp), %eax\n" /* line 499 | bitrate */
        "movl %eax, 8(%esp)\n"
        "movl $0x13, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* state */
        "calll speex_encoder_ctl\n"
        "movl -0x24(%ebp), %eax\n" /* line 500 | bitrate */
        "subl 0xc8(%edi), %eax\n" /* state */
        "cvtsi2ssl %eax, %xmm0\n"
        "addss 0xcc(%edi), %xmm0\n" /* state */
        "movss %xmm0, 0xcc(%edi)\n" /* state */
        "cvtss2sd 0xd0(%edi), %xmm1\n" /* line 501 | state */
        "mulsd 0x307e00, %xmm1\n" /* 0.95 */
        "cvtsi2sdl %eax, %xmm0\n"
        "mulsd 0x307e08, %xmm0\n" /* 0.05 */
        "addsd %xmm0, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm1\n"
        "movss %xmm1, 0xd0(%edi)\n" /* state */
        "movss 0x2ed5d0, %xmm0\n" /* line 502 | 1.0f */
        "addss 0xd4(%edi), %xmm0\n" /* state */
        "movss %xmm0, 0xd4(%edi)\n" /* state */
        "jmp .Lf1ea870_001eabb9\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1ea870_001eaf93:\n"
        "movl 0xc(%edi), %ecx\n" /* line 531 | state */
        "testl %ecx, %ecx\n"
        "jle .Lf1ea870_001eafc0\n"
        "xorl %ebx, %ebx\n" /* w_sig */
        ".Lf1ea870_001eaf9c:\n"
        "leal (, %ebx, 4), %eax\n" /* line 529 */
        "movl %eax, %ecx\n" /* line 532 */
        "addl 0x64(%edi), %ecx\n" /* state */
        "movl 0x70(%edi), %edx\n" /* state */
        "movl $0x26901d7d, (%edx, %eax)\n"
        "movl $0x26901d7d, (%ecx)\n"
        "addl $1, %ebx\n" /* line 531 | w_sig */
        "cmpl %ebx, 0xc(%edi)\n" /* w_sig, state */
        "jg .Lf1ea870_001eaf9c\n"
        ".Lf1ea870_001eafc0:\n"
        "movl 0x1c(%edi), %ebx\n" /* line 534 | state, w_sig */
        "testl %ebx, %ebx\n" /* w_sig */
        "jg .Lf1ea870_001eb016\n"
        ".Lf1ea870_001eafc7:\n"
        "movl $1, 0x24(%edi)\n" /* line 536 | state */
        "movl 0xb0(%edi), %eax\n" /* line 539 | state */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x1c(%edi), %eax\n" /* state */
        "movl %eax, 0x10(%esp)\n"
        "movl 0xc(%edi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x44(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0xa4(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x64(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll iir_mem2\n"
        "xorl %eax, %eax\n" /* line 550 */
        "cmpl $0, -0x1c(%ebp)\n" /* dtx */
        "sete %al\n"
        /* } scope */
        "addl $0x11c, %esp\n" /* line 790 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: e_low, exc, sp, res, ... */
        ".Lf1ea870_001eb016:\n"
        "xorl %edx, %edx\n" /* line 534 */
        ".Lf1ea870_001eb018:\n"
        "movl 0xb8(%edi), %eax\n" /* line 535 | state */
        "movl $0, (%eax, %edx, 4)\n"
        "addl $1, %edx\n" /* line 534 */
        "cmpl %edx, 0x1c(%edi)\n" /* state */
        "jg .Lf1ea870_001eb018\n"
        "jmp .Lf1ea870_001eafc7\n"
        ".Lf1ea870_001eb02f:\n"
        "movl $1, 8(%esp)\n" /* line 521 */
        "movl $1, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* bits */
        "movl %eax, (%esp)\n"
        "calll speex_bits_pack\n"
        "movl -0x1c(%ebp), %eax\n" /* line 522 | dtx */
        "testl %eax, %eax\n"
        "jne .Lf1ea870_001eb0d5\n"
        "movl $3, 8(%esp)\n" /* line 525 */
        "movl 0xe8(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x10(%ebp), %ecx\n" /* bits */
        "movl %ecx, (%esp)\n"
        "calll speex_bits_pack\n"
        "jmp .Lf1ea870_001eabc7\n"
        /* { scope 2: modeid, scale, el */
        ".Lf1ea870_001eb077:\n"
        "ucomiss 0x2ed62c, %xmm0\n" /* line 471 | 2.0f */
        "jbe .Lf1ea870_001eaea0\n"
        "movss 0x2ed62c, %xmm1\n" /* 2.0f */
        "movaps %xmm1, %xmm0\n"
        "jmp .Lf1ea870_001eaea8\n"
        /* } scope */
        ".Lf1ea870_001eb094:\n"
        "xorl %ecx, %ecx\n" /* line 431 */
        "movsd 0x307c28, %xmm2\n" /* 3.141592653589793 */
        ".Lf1ea870_001eb09e:\n"
        "movl 0x88(%edi), %eax\n" /* line 433 | state */
        "leal (%eax, %ecx, 4), %edx\n"
        "addl $1, %ecx\n"
        "cvtsi2ssl %ecx, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "mulsd %xmm2, %xmm0\n"
        "leal 1(%ebx), %eax\n" /* w_sig */
        "cvtsi2sdl %eax, %xmm1\n"
        "divsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movl 0x1c(%edi), %ebx\n" /* line 431 | state, w_sig */
        "cmpl %ecx, %ebx\n" /* w_sig */
        "jg .Lf1ea870_001eb09e\n"
        "jmp .Lf1ea870_001eab9d\n"
        ".Lf1ea870_001eb0d5:\n"
        "movl $3, 8(%esp)\n" /* line 523 */
        "movl $0, 4(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* bits */
        "movl %edx, (%esp)\n"
        "calll speex_bits_pack\n"
        "jmp .Lf1ea870_001eabc7\n"
        /* { scope 2: modeid, scale, el */
        /* { scope 3: bitrate, innov2 */
        ".Lf1ea870_001eb0f5:\n"
        "ucomiss 0xdc(%edi), %xmm1\n" /* line 508 | state */
        "jbe .Lf1ea870_001ebadb\n"
        "movl $1, %eax\n"
        ".Lf1ea870_001eb107:\n"
        "movl %eax, 0xe8(%edi)\n" /* line 513 | state */
        "jmp .Lf1ea870_001eabb9\n"
        /* } scope */
        /* } scope */
        ".Lf1ea870_001eb112:\n"
        "movl $0, -0x8c(%ebp)\n" /* line 572 | sub */
        /* { scope 2: modeid, scale, el */
        ".Lf1ea870_001eb11c:\n"
        "movl -0x8c(%ebp), %eax\n" /* line 581 | sub */
        "imull 0x10(%edi), %eax\n" /* state */
        "shll $2, %eax\n"
        "movl %eax, -0x94(%ebp)\n"
        "addl 0x44(%edi), %eax\n" /* state */
        "movl %eax, -0x64(%ebp)\n" /* sp */
        "movl -0x94(%ebp), %eax\n" /* line 582 */
        "addl 0x64(%edi), %eax\n" /* state */
        "movl %eax, -0x68(%ebp)\n" /* exc */
        "movl -0x94(%ebp), %ecx\n" /* line 583 */
        "addl 0x6c(%edi), %ecx\n" /* state */
        "movl %ecx, -0x60(%ebp)\n" /* res */
        "movl -0x94(%ebp), %esi\n" /* line 584 | low */
        "addl 0x74(%edi), %esi\n" /* state, low */
        "movl %esi, -0x5c(%ebp)\n" /* low, target */
        "movl -0x94(%ebp), %eax\n" /* line 585 */
        "addl 0x70(%edi), %eax\n" /* state */
        "movl %eax, -0x58(%ebp)\n" /* sw */
        "movl %edx, 0x14(%esp)\n" /* line 588 */
        "movl -0x8c(%ebp), %edx\n" /* sub */
        "movl %edx, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* w_sig */
        "movl 0x98(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x88(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x90(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll lsp_interpolate\n"
        "movl 0x14(%edi), %eax\n" /* line 589 | state */
        "movl %eax, 0x14(%esp)\n"
        "movl -0x8c(%ebp), %ecx\n" /* sub */
        "movl %ecx, 0x10(%esp)\n"
        "movl 0x1c(%edi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x9c(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x8c(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x94(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll lsp_interpolate\n"
        "movl $0x3d4ccccd, %ebx\n" /* line 591 | w_sig */
        "movl %ebx, 8(%esp)\n" /* w_sig */
        "movl 0x1c(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x98(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll lsp_enforce_margin\n"
        "movl %ebx, 8(%esp)\n" /* line 592 | w_sig */
        "movl 0x1c(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x9c(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll lsp_enforce_margin\n"
        "movl -0x30(%ebp), %ebx\n" /* line 594 | w_sig */
        "movl %ebx, 0xc(%esp)\n" /* w_sig */
        "movl 0x1c(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0xa0(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x98(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll lsp_to_lpc\n"
        "movl %ebx, 0xc(%esp)\n" /* line 595 | w_sig */
        "movl 0x1c(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0xa4(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x9c(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll lsp_to_lpc\n"
        "movl 0x1c(%edi), %eax\n" /* line 597 | state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0xa8(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0xa0(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x30(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll bw_lpc\n"
        "movl 0x1c(%edi), %eax\n" /* line 598 | state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0xac(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0xa0(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x34(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll bw_lpc\n"
        "movl -0x8c(%ebp), %esi\n" /* sub, low */
        "shll $2, %esi\n" /* low */
        "movl 0xbc(%edi), %eax\n" /* line 602 | state */
        "movl $0x3f800000, %ecx\n"
        "movl %ecx, (%eax, %esi)\n"
        "movl 0x1c(%edi), %edx\n" /* line 604 | state */
        "testl %edx, %edx\n"
        "jg .Lf1ea870_001eb98b\n"
        "movsd 0x307c10, %xmm1\n" /* 1.0 */
        ".Lf1ea870_001eb2c9:\n"
        "movl -0x7c(%ebp), %eax\n" /* line 614 | low_pi_gain */
        "cvtss2sd (%eax, %esi), %xmm0\n"
        "addsd 0x307e10, %xmm0\n" /* 0.01 */
        "addsd 0x307e10, %xmm1\n" /* 0.01 */
        "divsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x54(%ebp)\n" /* filter_ratio */
        "movl 0xb4(%edi), %eax\n" /* line 618 | state */
        "movl %eax, 0x14(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl 0x10(%edi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x68(%ebp), %edx\n" /* exc */
        "movl %edx, 8(%esp)\n"
        "movl 0xa4(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl -0x64(%ebp), %ecx\n" /* sp */
        "movl %ecx, (%esp)\n"
        "calll fir_mem2\n"
        "movl 0x10(%edi), %eax\n" /* line 621 | state */
        "movl %eax, 4(%esp)\n"
        "movl -0x68(%ebp), %ebx\n" /* exc, w_sig */
        "movl %ebx, (%esp)\n" /* w_sig */
        "calll compute_rms\n"
        "fstps -0x50(%ebp)\n" /* eh */
        "movl 0xe8(%edi), %edx\n" /* line 623 | state */
        "movl 0xe4(%edi), %eax\n" /* state */
        "movl (%eax, %edx, 4), %eax\n"
        "movl 0x24(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1ea870_001eba16\n"
        /* { scope 3: bitrate, innov2 */
        "movl 0x10(%edi), %eax\n" /* line 668 | state */
        "movl %eax, 4(%esp)\n"
        "movl -0x78(%ebp), %eax\n" /* low_exc */
        "addl -0x94(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll compute_rms\n"
        "fstps -0x90(%ebp)\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 670 | 1.0f */
        "movss -0x90(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x90(%ebp)\n"
        "addss -0x50(%ebp), %xmm0\n" /* eh */
        "mulss -0x54(%ebp), %xmm0\n" /* filter_ratio */
        "divss %xmm1, %xmm0\n"
        "cmpl $0x50, 0x10(%edi)\n" /* line 673 | state */
        "je .Lf1ea870_001eba01\n"
        /* { scope 4 */
        ".Lf1ea870_001eb3a0:\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 684 */
        "movsd %xmm0, (%esp)\n"
        "calll log\n"
        "fstpl -0xd8(%ebp)\n"
        "movsd -0xd8(%ebp), %xmm0\n"
        "addsd 0x307e30, %xmm0\n" /* 0.15556 */
        "mulsd 0x307e38, %xmm0\n" /* 3.7 */
        "addsd 0x307ce0, %xmm0\n" /* 0.5 */
        "movsd %xmm0, (%esp)\n"
        "calll floor\n"
        "fstpl -0xa8(%ebp)\n"
        "cvttsd2si -0xa8(%ebp), %eax\n" /* qgc */
        "testl %eax, %eax\n" /* line 685 */
        "js .Lf1ea870_001ebad0\n"
        "cmpl $0xf, %eax\n" /* line 687 */
        "jle .Lf1ea870_001eb9e3\n"
        "movl $0xf, %eax\n"
        "movsd 0x307e40, %xmm0\n" /* 15.0 */
        ".Lf1ea870_001eb40a:\n"
        "movl $4, 8(%esp)\n" /* line 689 */
        "movl %eax, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* bits */
        "movl %eax, (%esp)\n"
        "movsd %xmm0, -0xc8(%ebp)\n"
        "calll speex_bits_pack\n"
        "movsd -0xc8(%ebp), %xmm0\n" /* line 690 */
        "mulsd 0x307e48, %xmm0\n" /* 0.27027027027027023 */
        "subsd 0x307e30, %xmm0\n" /* 0.15556 */
        "movsd %xmm0, (%esp)\n"
        "calll exp\n"
        "fstpl -0xb0(%ebp)\n"
        "cvtsd2ss -0xb0(%ebp), %xmm0\n"
        /* } scope */
        "movl 0x10(%edi), %edx\n" /* line 693 | state */
        "cmpl $0x50, %edx\n"
        "je .Lf1ea870_001eb9ec\n"
        ".Lf1ea870_001eb465:\n"
        "divss -0x54(%ebp), %xmm0\n" /* line 696 | filter_ratio */
        "movss -0x90(%ebp), %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x48(%ebp)\n" /* scale */
        "movl -0x30(%ebp), %eax\n" /* line 698 */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x1c(%edi), %eax\n" /* state */
        "movl %eax, 0x14(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl -0x80(%ebp), %edx\n" /* syn_resp */
        "movl %edx, 0xc(%esp)\n"
        "movl 0xac(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0xa8(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0xa4(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll compute_impulse_response\n"
        "movl 0x10(%edi), %eax\n" /* line 702 | state */
        "testl %eax, %eax\n"
        "jle .Lf1ea870_001eb4d1\n"
        "xorl %eax, %eax\n"
        ".Lf1ea870_001eb4bf:\n"
        "movl -0x68(%ebp), %ecx\n" /* line 703 | exc */
        "movl $0x26901d7d, (%ecx, %eax, 4)\n"
        "addl $1, %eax\n" /* line 702 */
        "cmpl %eax, 0x10(%edi)\n" /* state */
        "jg .Lf1ea870_001eb4bf\n"
        ".Lf1ea870_001eb4d1:\n"
        "movl 0x1c(%edi), %eax\n" /* line 706 | state */
        "testl %eax, %eax\n"
        "jle .Lf1ea870_001eb4fd\n"
        "xorl %ecx, %ecx\n"
        ".Lf1ea870_001eb4da:\n"
        "leal (, %ecx, 4), %eax\n"
        "movl 0xb0(%edi), %edx\n" /* line 707 | state */
        "movl (%edx, %eax), %edx\n"
        "movl -0x88(%ebp), %ebx\n" /* mem, w_sig */
        "movl %edx, (%ebx, %eax)\n" /* w_sig */
        "addl $1, %ecx\n" /* line 706 */
        "movl 0x1c(%edi), %eax\n" /* state */
        "cmpl %ecx, %eax\n"
        "jg .Lf1ea870_001eb4da\n"
        ".Lf1ea870_001eb4fd:\n"
        "movl -0x88(%ebp), %esi\n" /* line 708 | mem, low */
        "movl %esi, 0x14(%esp)\n" /* low */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x10(%edi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x68(%ebp), %eax\n" /* exc */
        "movl %eax, 8(%esp)\n"
        "movl 0xa4(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl -0x68(%ebp), %edx\n" /* exc */
        "movl %edx, (%esp)\n"
        "calll iir_mem2\n"
        "movl 0x1c(%edi), %eax\n" /* line 710 | state */
        "testl %eax, %eax\n"
        "jle .Lf1ea870_001eb55a\n"
        "xorl %ecx, %ecx\n"
        ".Lf1ea870_001eb537:\n"
        "leal (, %ecx, 4), %eax\n"
        "movl 0xb8(%edi), %edx\n" /* line 711 | state */
        "movl (%edx, %eax), %edx\n"
        "movl -0x88(%ebp), %ebx\n" /* mem, w_sig */
        "movl %edx, (%ebx, %eax)\n" /* w_sig */
        "addl $1, %ecx\n" /* line 710 */
        "movl 0x1c(%edi), %eax\n" /* state */
        "cmpl %eax, %ecx\n"
        "jl .Lf1ea870_001eb537\n"
        ".Lf1ea870_001eb55a:\n"
        "movl -0x88(%ebp), %esi\n" /* line 712 | mem, low */
        "movl %esi, 0x18(%esp)\n" /* low */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edi), %eax\n" /* state */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x60(%ebp), %eax\n" /* res */
        "movl %eax, 0xc(%esp)\n"
        "movl 0xac(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0xa8(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl -0x68(%ebp), %edx\n" /* exc */
        "movl %edx, (%esp)\n"
        "calll filter_mem2\n"
        "movl 0x1c(%edi), %eax\n" /* line 715 | state */
        "testl %eax, %eax\n"
        "jle .Lf1ea870_001eb5c1\n"
        "xorl %ecx, %ecx\n"
        ".Lf1ea870_001eb59e:\n"
        "leal (, %ecx, 4), %eax\n"
        "movl 0xb8(%edi), %edx\n" /* line 716 | state */
        "movl (%edx, %eax), %edx\n"
        "movl -0x88(%ebp), %ebx\n" /* mem, w_sig */
        "movl %edx, (%ebx, %eax)\n" /* w_sig */
        "addl $1, %ecx\n" /* line 715 */
        "movl 0x1c(%edi), %eax\n" /* state */
        "cmpl %ecx, %eax\n"
        "jg .Lf1ea870_001eb59e\n"
        ".Lf1ea870_001eb5c1:\n"
        "movl -0x88(%ebp), %esi\n" /* line 717 | mem, low */
        "movl %esi, 0x18(%esp)\n" /* low */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edi), %eax\n" /* state */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x58(%ebp), %eax\n" /* sw */
        "movl %eax, 0xc(%esp)\n"
        "movl 0xac(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0xa8(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl -0x64(%ebp), %edx\n" /* sp */
        "movl %edx, (%esp)\n"
        "calll filter_mem2\n"
        "movl 0x10(%edi), %edx\n" /* line 720 | state */
        "testl %edx, %edx\n"
        "jle .Lf1ea870_001eb651\n"
        "movl $1, %edx\n"
        ".Lf1ea870_001eb608:\n"
        "leal (, %edx, 4), %eax\n" /* line 346 | vin */
        "movl -0x58(%ebp), %ecx\n" /* line 721 | sw */
        "movss -4(%ecx, %eax), %xmm0\n"
        "movl -0x60(%ebp), %ebx\n" /* res, w_sig */
        "subss -4(%ebx, %eax), %xmm0\n" /* w_sig */
        "movl -0x5c(%ebp), %esi\n" /* target, low */
        "movss %xmm0, -4(%esi, %eax)\n" /* low */
        "movl %edx, %eax\n"
        "addl $1, %edx\n"
        "cmpl %eax, 0x10(%edi)\n" /* line 720 | state */
        "jg .Lf1ea870_001eb608\n"
        "movl 0x10(%edi), %edx\n" /* line 723 | state */
        "testl %edx, %edx\n"
        "jle .Lf1ea870_001eb651\n"
        "xorl %eax, %eax\n"
        ".Lf1ea870_001eb63d:\n"
        "movl -0x68(%ebp), %edx\n" /* line 724 | exc */
        "movl $0, (%edx, %eax, 4)\n"
        "addl $1, %eax\n" /* line 723 */
        "movl 0x10(%edi), %edx\n" /* state */
        "cmpl %eax, %edx\n"
        "jg .Lf1ea870_001eb63d\n"
        ".Lf1ea870_001eb651:\n"
        "movl %edx, 0xc(%esp)\n" /* line 726 */
        "movss -0x48(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 8(%esp)\n"
        "movl -0x5c(%ebp), %eax\n" /* target */
        "movl %eax, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll signal_div\n"
        "movl 0x10(%edi), %ecx\n" /* line 729 | state */
        "testl %ecx, %ecx\n"
        "jle .Lf1ea870_001eb68f\n"
        "xorl %eax, %eax\n"
        ".Lf1ea870_001eb678:\n"
        "movl -0x84(%ebp), %edx\n" /* line 730 | innov */
        "movl $0, (%edx, %eax, 4)\n"
        "addl $1, %eax\n" /* line 729 */
        "movl 0x10(%edi), %ecx\n" /* state */
        "cmpl %ecx, %eax\n"
        "jl .Lf1ea870_001eb678\n"
        ".Lf1ea870_001eb68f:\n"
        "movl 0xe8(%edi), %edx\n" /* line 735 | state */
        "movl 0xe4(%edi), %eax\n" /* state */
        "movl (%eax, %edx, 4), %edx\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0x30(%esp)\n"
        "movl 0xf0(%edi), %eax\n" /* state */
        "addl $1, %eax\n"
        "sarl $1, %eax\n"
        "movl %eax, 0x2c(%esp)\n"
        "movl -0x30(%ebp), %ebx\n" /* w_sig */
        "movl %ebx, 0x28(%esp)\n" /* w_sig */
        "movl 0x10(%ebp), %esi\n" /* bits, low */
        "movl %esi, 0x24(%esp)\n" /* low */
        "movl -0x80(%ebp), %eax\n" /* syn_resp */
        "movl %eax, 0x20(%esp)\n"
        "movl -0x84(%ebp), %ebx\n" /* innov, w_sig */
        "movl %ebx, 0x1c(%esp)\n" /* w_sig */
        "movl %ecx, 0x18(%esp)\n"
        "movl 0x1c(%edi), %eax\n" /* state */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x2c(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0xac(%edi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0xa8(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0xa4(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl -0x5c(%ebp), %esi\n" /* target, low */
        "movl %esi, (%esp)\n" /* low */
        "calll *0x24(%edx)\n"
        "movl 0x10(%edi), %eax\n" /* line 738 | state */
        "movl %eax, 0xc(%esp)\n"
        "movss -0x48(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* w_sig */
        "movl %ebx, (%esp)\n" /* w_sig */
        "calll signal_mul\n"
        "movl 0x10(%edi), %edx\n" /* line 740 | state */
        "testl %edx, %edx\n"
        "jle .Lf1ea870_001eb765\n"
        "movl $1, %ecx\n"
        ".Lf1ea870_001eb736:\n"
        "leal (, %ecx, 4), %eax\n" /* line 346 | vin */
        "movl -0x68(%ebp), %ebx\n" /* exc */
        "leal (%eax, %ebx), %edx\n"
        "movss -4(%edx), %xmm0\n" /* line 741 */
        "movl -0x84(%ebp), %esi\n" /* innov, low */
        "addss -4(%eax, %esi), %xmm0\n"
        "movss %xmm0, -4(%edx)\n"
        "movl %ecx, %eax\n"
        "movl 0x10(%edi), %edx\n" /* line 740 | state */
        "addl $1, %ecx\n"
        "cmpl %edx, %eax\n"
        "jl .Lf1ea870_001eb736\n"
        ".Lf1ea870_001eb765:\n"
        "movl 0xe8(%edi), %esi\n" /* line 743 | state, low */
        "movl 0xe4(%edi), %ecx\n" /* state */
        "movl (%ecx, %esi, 4), %eax\n"
        "movl 0xc(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1ea870_001eb8d2\n"
        /* { scope 4 */
        "movl -0x30(%ebp), %eax\n" /* line 746 */
        "negl %eax\n"
        "andl $3, %eax\n"
        "addl -0x30(%ebp), %eax\n"
        "leal (%eax, %edx, 4), %ebx\n" /* w_sig */
        "movl %ebx, -0x2c(%ebp)\n" /* w_sig */
        "movl %eax, -0x44(%ebp)\n" /* innov2 */
        "movl %edx, %ebx\n" /* line 747 | w_sig */
        "testl %edx, %edx\n"
        "jle .Lf1ea870_001eb7f0\n"
        "xorl %eax, %eax\n"
        ".Lf1ea870_001eb79b:\n"
        "movl -0x44(%ebp), %esi\n" /* line 748 | innov2, low */
        "movl $0, (%esi, %eax, 4)\n" /* low */
        "addl $1, %eax\n" /* line 747 */
        "cmpl 0x10(%edi), %eax\n" /* state */
        "jl .Lf1ea870_001eb79b\n"
        "movl 0x10(%edi), %ebx\n" /* line 749 | state, w_sig */
        "testl %ebx, %ebx\n" /* w_sig */
        "jle .Lf1ea870_001eb7e4\n"
        "movl $1, %ecx\n"
        "movss 0x2ed6c0, %xmm1\n" /* 2.5f */
        "movl -0x5c(%ebp), %edx\n" /* target */
        "addl $4, %edx\n"
        ".Lf1ea870_001eb7c7:\n"
        "movss -4(%edx), %xmm0\n" /* line 750 */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -4(%edx)\n"
        "movl %ecx, %eax\n"
        "movl 0x10(%edi), %ebx\n" /* line 749 | state, w_sig */
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "cmpl %ebx, %eax\n" /* w_sig */
        "jl .Lf1ea870_001eb7c7\n"
        ".Lf1ea870_001eb7e4:\n"
        "movl 0xe8(%edi), %esi\n" /* state, low */
        "movl 0xe4(%edi), %ecx\n" /* state */
        ".Lf1ea870_001eb7f0:\n"
        "movl (%ecx, %esi, 4), %edx\n" /* line 753 */
        "movl $0, 0x30(%esp)\n"
        "movl 0xf0(%edi), %eax\n" /* state */
        "addl $1, %eax\n"
        "sarl $1, %eax\n"
        "movl %eax, 0x2c(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 0x28(%esp)\n"
        "movl 0x10(%ebp), %ecx\n" /* bits */
        "movl %ecx, 0x24(%esp)\n"
        "movl -0x80(%ebp), %esi\n" /* syn_resp, low */
        "movl %esi, 0x20(%esp)\n" /* low */
        "movl -0x44(%ebp), %eax\n" /* innov2 */
        "movl %eax, 0x1c(%esp)\n"
        "movl %ebx, 0x18(%esp)\n" /* w_sig */
        "movl 0x1c(%edi), %eax\n" /* state */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x2c(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0xac(%edi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0xa8(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0xa4(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl -0x5c(%ebp), %ecx\n" /* target */
        "movl %ecx, (%esp)\n"
        "calll *0x24(%edx)\n"
        "movl 0x10(%edi), %eax\n" /* line 754 | state */
        "testl %eax, %eax\n"
        "jle .Lf1ea870_001eb8d2\n"
        "cvtss2sd -0x48(%ebp), %xmm1\n" /* scale */
        "mulsd 0x307e58, %xmm1\n" /* 0.4 */
        "movl $1, %ecx\n"
        "movl -0x44(%ebp), %edx\n" /* innov2 */
        "addl $4, %edx\n"
        ".Lf1ea870_001eb87e:\n"
        "cvtss2sd -4(%edx), %xmm0\n" /* line 755 */
        "mulsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -4(%edx)\n"
        "movl %ecx, %eax\n"
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "cmpl %eax, 0x10(%edi)\n" /* line 754 | state */
        "jg .Lf1ea870_001eb87e\n"
        "movl 0x10(%edi), %eax\n" /* line 756 | state */
        "testl %eax, %eax\n"
        "jle .Lf1ea870_001eb8d2\n"
        "movl $1, %ecx\n"
        ".Lf1ea870_001eb8a9:\n"
        "leal (, %ecx, 4), %eax\n" /* line 346 | vin */
        "movl -0x68(%ebp), %edx\n" /* exc */
        "addl %eax, %edx\n" /* vin */
        "movss -4(%edx), %xmm0\n" /* line 757 */
        "movl -0x44(%ebp), %ebx\n" /* innov2, w_sig */
        "addss -4(%ebx, %eax), %xmm0\n" /* w_sig */
        "movss %xmm0, -4(%edx)\n"
        "movl %ecx, %eax\n"
        "addl $1, %ecx\n"
        "cmpl 0x10(%edi), %eax\n" /* line 756 | state */
        "jl .Lf1ea870_001eb8a9\n"
        /* } scope */
        /* } scope */
        ".Lf1ea870_001eb8d2:\n"
        "movl 0x1c(%edi), %edx\n" /* line 764 | state */
        "testl %edx, %edx\n"
        "jle .Lf1ea870_001eb8fe\n"
        "xorl %ecx, %ecx\n"
        ".Lf1ea870_001eb8db:\n"
        "leal (, %ecx, 4), %eax\n"
        "movl 0xb0(%edi), %edx\n" /* line 765 | state */
        "movl (%edx, %eax), %edx\n"
        "movl -0x88(%ebp), %esi\n" /* mem, low */
        "movl %edx, (%esi, %eax)\n" /* low */
        "addl $1, %ecx\n" /* line 764 */
        "movl 0x1c(%edi), %edx\n" /* state */
        "cmpl %ecx, %edx\n"
        "jg .Lf1ea870_001eb8db\n"
        ".Lf1ea870_001eb8fe:\n"
        "movl 0xb0(%edi), %eax\n" /* line 767 | state */
        "movl %eax, 0x14(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl 0x10(%edi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x64(%ebp), %eax\n" /* sp */
        "movl %eax, 8(%esp)\n"
        "movl 0xa4(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl -0x68(%ebp), %edx\n" /* exc */
        "movl %edx, (%esp)\n"
        "calll iir_mem2\n"
        "movl 0xb8(%edi), %eax\n" /* line 770 | state */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x1c(%edi), %eax\n" /* state */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edi), %eax\n" /* state */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x58(%ebp), %ecx\n" /* sw */
        "movl %ecx, 0xc(%esp)\n"
        "movl 0xac(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0xa8(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl -0x64(%ebp), %ebx\n" /* sp, w_sig */
        "movl %ebx, (%esp)\n" /* w_sig */
        "calll filter_mem2\n"
        /* } scope */
        "addl $1, -0x8c(%ebp)\n" /* line 572 | sub */
        "movl 0x14(%edi), %edx\n" /* state */
        "cmpl %edx, -0x8c(%ebp)\n" /* sub */
        "jge .Lf1ea870_001eacbc\n"
        "movl 0x1c(%edi), %ebx\n" /* state, w_sig */
        "jmp .Lf1ea870_001eb11c\n"
        /* { scope 2: modeid, scale, el */
        ".Lf1ea870_001eb98b:\n"
        "xorl %ebx, %ebx\n" /* line 604 | w_sig */
        "movl %ecx, -0xcc(%ebp)\n"
        "movss -0xcc(%ebp), %xmm3\n"
        "xorl %ecx, %ecx\n"
        ".Lf1ea870_001eb99d:\n"
        "movl %ecx, %eax\n" /* line 606 */
        "addl 0xa4(%edi), %eax\n" /* state */
        "movss 4(%eax), %xmm0\n"
        "movss (%eax), %xmm2\n"
        "movaps %xmm0, %xmm1\n"
        "subss %xmm2, %xmm1\n"
        "addss %xmm1, %xmm3\n"
        "movl %esi, %eax\n" /* line 607 | low */
        "addl 0xbc(%edi), %eax\n" /* state */
        "addss %xmm2, %xmm0\n"
        "addss (%eax), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "addl $2, %ebx\n" /* line 604 | w_sig */
        "movl 0x1c(%edi), %edx\n" /* state */
        "addl $8, %ecx\n"
        "cmpl %ebx, %edx\n" /* w_sig */
        "jg .Lf1ea870_001eb99d\n"
        "cvtss2sd %xmm3, %xmm1\n"
        "jmp .Lf1ea870_001eb2c9\n"
        /* { scope 3: bitrate, innov2 */
        /* { scope 4 */
        ".Lf1ea870_001eb9e3:\n"
        "cvtsi2sdl %eax, %xmm0\n" /* line 687 */
        "jmp .Lf1ea870_001eb40a\n"
        /* } scope */
        ".Lf1ea870_001eb9ec:\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 694 */
        "mulsd 0x307e50, %xmm0\n" /* 1.4142 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "jmp .Lf1ea870_001eb465\n"
        ".Lf1ea870_001eba01:\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 674 */
        "mulsd 0x307e28, %xmm0\n" /* 0.70711 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "jmp .Lf1ea870_001eb3a0\n"
        /* } scope */
        /* { scope 3: bitrate, innov2 */
        ".Lf1ea870_001eba16:\n"
        "movl 0x10(%edi), %eax\n" /* line 626 | state */
        "movl %eax, 4(%esp)\n"
        "movl -0x74(%ebp), %eax\n" /* low_innov */
        "addl -0x94(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll compute_rms\n"
        "fstps -0x4c(%ebp)\n" /* el */
        "cvtss2sd -0x50(%ebp), %xmm0\n" /* line 629 | eh */
        "cvtss2sd -0x4c(%ebp), %xmm1\n" /* el */
        "addsd 0x307e10, %xmm1\n" /* 0.01 */
        "divsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        /* { scope 4 */
        "mulss -0x54(%ebp), %xmm0\n" /* line 655 | filter_ratio */
        "movss %xmm0, -0x54(%ebp)\n" /* filter_ratio */
        "cvtss2sd %xmm0, %xmm0\n"
        "addsd 0x307c90, %xmm0\n" /* 0.0001 */
        "movsd %xmm0, (%esp)\n"
        "calll log\n"
        "fstpl -0xd8(%ebp)\n"
        "movsd -0xd8(%ebp), %xmm0\n"
        "mulsd 0x307e18, %xmm0\n" /* 8.0 */
        "addsd 0x307e20, %xmm0\n" /* 10.5 */
        "movsd %xmm0, (%esp)\n"
        "calll floor\n"
        "fstpl -0xa0(%ebp)\n"
        "cvttsd2si -0xa0(%ebp), %edx\n" /* quant */
        "testl %edx, %edx\n" /* line 657 */
        "js .Lf1ea870_001ebc0a\n"
        "cmpl $0x20, %edx\n" /* line 659 */
        "movl $0x1f, %eax\n"
        "cmovgel %eax, %edx\n"
        ".Lf1ea870_001ebab4:\n"
        "movl $5, 8(%esp)\n" /* line 661 */
        "movl %edx, 4(%esp)\n"
        "movl 0x10(%ebp), %esi\n" /* bits, low */
        "movl %esi, (%esp)\n" /* low */
        "calll speex_bits_pack\n"
        "jmp .Lf1ea870_001eb8d2\n"
        /* } scope */
        /* } scope */
        /* { scope 3: bitrate, innov2 */
        /* { scope 4 */
        ".Lf1ea870_001ebad0:\n"
        "xorl %eax, %eax\n" /* line 685 */
        "pxor %xmm0, %xmm0\n"
        "jmp .Lf1ea870_001eb40a\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: modeid, scale, el */
        /* { scope 3: bitrate, innov2 */
        ".Lf1ea870_001ebadb:\n"
        "movl 0xec(%edi), %eax\n" /* line 511 | state */
        "jmp .Lf1ea870_001eb107\n"
        /* } scope */
        /* { scope 3: bitrate, innov2 */
        ".Lf1ea870_001ebae6:\n"
        "movl %ebx, -0x3c(%ebp)\n" /* line 346 */
        "leal (%ebx, %ebx, 4), %eax\n" /* vin */
        "leal (%ebx, %eax, 2), %eax\n" /* vin */
        "shll $2, %eax\n" /* vin */
        "movl %eax, -0x40(%ebp)\n" /* vin */
        "xorl %esi, %esi\n"
        "movss 0xc0(%edi), %xmm1\n" /* state */
        "movss %xmm1, -0xb4(%ebp)\n"
        "movss 0xdc(%edi), %xmm0\n" /* state */
        "movss %xmm0, -0xb8(%ebp)\n"
        "movss %xmm1, (%esp)\n"
        "calll floorf\n"
        "fstps -0x98(%ebp)\n"
        "cvttss2si -0x98(%ebp), %edx\n"
        "leal 1(%edx), %eax\n" /* vin */
        "movl %eax, -0xdc(%ebp)\n" /* vin */
        "cvtsi2ssl %edx, %xmm0\n"
        "movss -0xb4(%ebp), %xmm3\n"
        "subss %xmm0, %xmm3\n"
        "cvtsi2ssl %eax, %xmm2\n" /* vin */
        "subss -0xb4(%ebp), %xmm2\n"
        "cmpl $0xa, %edx\n"
        "je .Lf1ea870_001ebba7\n"
        /* { scope 4 */
        ".Lf1ea870_001ebb59:\n"
        "movl -0x40(%ebp), %eax\n" /* line 490 */
        "movl -0x70(%ebp), %ecx\n" /* mode */
        "addl 0xa4(%ecx), %eax\n"
        "movaps %xmm3, %xmm0\n"
        "movl -0xdc(%ebp), %ecx\n"
        "mulss (%eax, %ecx, 4), %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "mulss (%eax, %edx, 4), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss -0xb8(%ebp), %xmm1\n" /* line 491 */
        "ucomiss %xmm0, %xmm1\n"
        "jae .Lf1ea870_001eaef1\n"
        "subl $1, %ebx\n" /* line 493 | w_sig */
        "movl %ebx, -0x20(%ebp)\n" /* w_sig, modeid */
        "addl $1, %esi\n" /* low */
        "subl $0x2c, -0x40(%ebp)\n"
        /* } scope */
        "cmpl -0x3c(%ebp), %esi\n" /* line 481 | low */
        "jne .Lf1ea870_001ebb59\n"
        "jmp .Lf1ea870_001eaef1\n"
        /* { scope 4 */
        ".Lf1ea870_001ebba7:\n"
        "movl -0x70(%ebp), %edx\n" /* line 487 | mode */
        "movl 0xa4(%edx), %eax\n"
        "movss -0xb8(%ebp), %xmm0\n" /* line 491 */
        "movl -0x40(%ebp), %ecx\n"
        "ucomiss 0x28(%eax, %ecx), %xmm0\n"
        "jae .Lf1ea870_001eaef1\n"
        "subl $1, %ebx\n" /* line 493 | w_sig */
        "movl %ebx, -0x20(%ebp)\n" /* w_sig, modeid */
        "addl $1, %esi\n" /* low */
        "subl $0x2c, -0x40(%ebp)\n"
        /* } scope */
        "cmpl -0x3c(%ebp), %esi\n" /* line 481 | low */
        "jne .Lf1ea870_001ebba7\n"
        "jmp .Lf1ea870_001eaef1\n"
        /* } scope */
        /* { scope 3: bitrate, innov2 */
        ".Lf1ea870_001ebbdd:\n"
        "movl $0, 0xc0(%edi)\n" /* line 459 | state */
        "jmp .Lf1ea870_001eadea\n"
        ".Lf1ea870_001ebbec:\n"
        "movaps %xmm3, %xmm0\n" /* line 446 */
        "jmp .Lf1ea870_001eadba\n"
        /* } scope */
        /* { scope 3: bitrate, innov2 */
        ".Lf1ea870_001ebbf4:\n"
        "jp .Lf1ea870_001eaee6\n" /* line 479 */
        "movl $0xbf800000, %eax\n" /* line 480 */
        "movl %eax, 0xdc(%edi)\n" /* state */
        "jmp .Lf1ea870_001eaee6\n"
        /* } scope */
        /* } scope */
        /* { scope 2: modeid, scale, el */
        /* { scope 3: bitrate, innov2 */
        /* { scope 4 */
        ".Lf1ea870_001ebc0a:\n"
        "xorl %edx, %edx\n" /* line 657 */
        "jmp .Lf1ea870_001ebab4\n"
    );
}

/* line 796 */
__attribute__((naked))
int * sb_decoder_init(const SpeexMode *m)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 796 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* m */
        /* { scope 1 */
        "movl $0x5e30, (%esp)\n" /* line 806 */
        "calll speex_alloc\n"
        "movl %eax, %esi\n" /* st */
        "testl %eax, %eax\n" /* line 807 */
        "je .Lf1ebc12_001ebd9f\n"
        "leal 0x70(%eax), %eax\n" /* line 809 */
        "movl %eax, 0x28(%esi)\n" /* st */
        "movl %ebx, (%esi)\n" /* line 811 | mode, st */
        "movl (%ebx), %ebx\n" /* line 812 | mode */
        "movl $1, 0x64(%esi)\n" /* line 814 | st */
        "movl (%ebx), %eax\n" /* line 819 | mode */
        "movl %eax, (%esp)\n"
        "calll speex_decoder_init\n"
        "movl %eax, 4(%esi)\n" /* st */
        "movl 4(%ebx), %eax\n" /* line 820 | mode */
        "addl %eax, %eax\n"
        "movl %eax, 8(%esi)\n" /* st */
        "movl 4(%ebx), %eax\n" /* line 821 | mode */
        "movl %eax, 0xc(%esi)\n" /* st */
        "movl 8(%ebx), %eax\n" /* line 822 | mode */
        "movl %eax, 0x10(%esi)\n" /* st */
        "movl 4(%ebx), %eax\n" /* line 823 | mode */
        "cltd\n"
        "idivl 8(%ebx)\n" /* mode */
        "movl %eax, 0x14(%esi)\n" /* st */
        "movl 0xc(%ebx), %eax\n" /* line 824 | mode */
        "movl %eax, 0x18(%esi)\n" /* st */
        "leal 0x20(%esi), %eax\n" /* line 825 | st */
        "movl %eax, 8(%esp)\n"
        "movl $0x19, 4(%esp)\n"
        "movl 4(%esi), %eax\n" /* st */
        "movl %eax, (%esp)\n"
        "calll speex_decoder_ctl\n"
        "shll 0x20(%esi)\n" /* line 826 | st */
        "leal 0x28(%ebx), %eax\n" /* line 828 | mode */
        "movl %eax, 0x68(%esi)\n" /* st */
        "movl 0x48(%ebx), %eax\n" /* line 829 | mode */
        "movl %eax, 0x6c(%esi)\n" /* st */
        "movl $1, 0x1c(%esi)\n" /* line 831 | st */
        "movl 0xc(%esi), %eax\n" /* line 834 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x2c(%esi)\n" /* st */
        "movl 0xc(%esi), %eax\n" /* line 835 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x30(%esi)\n" /* st */
        "movl 8(%esi), %eax\n" /* line 836 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x34(%esi)\n" /* st */
        "movl 8(%esi), %eax\n" /* line 837 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x38(%esi)\n" /* st */
        "movl 8(%esi), %eax\n" /* line 838 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x3c(%esi)\n" /* st */
        "movl $0x100, (%esp)\n" /* line 840 */
        "calll speex_alloc\n"
        "movl %eax, 0x40(%esi)\n" /* st */
        "movl $0x100, (%esp)\n" /* line 841 */
        "calll speex_alloc\n"
        "movl %eax, 0x44(%esi)\n" /* st */
        "movl 0xc(%esi), %eax\n" /* line 843 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x48(%esi)\n" /* st */
        "movl 0x18(%esi), %eax\n" /* line 845 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x4c(%esi)\n" /* st */
        "movl 0x18(%esi), %eax\n" /* line 846 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x50(%esi)\n" /* st */
        "movl 0x18(%esi), %eax\n" /* line 847 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x54(%esi)\n" /* st */
        "movl 0x18(%esi), %eax\n" /* line 848 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x58(%esi)\n" /* st */
        "movl 0x14(%esi), %eax\n" /* line 850 | st */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x60(%esi)\n" /* st */
        "movl 0x18(%esi), %eax\n" /* line 851 | st */
        "shll $3, %eax\n"
        "movl %eax, (%esp)\n"
        "calll speex_alloc\n"
        "movl %eax, 0x5c(%esi)\n" /* st */
        "movl $0, 0x24(%esi)\n" /* line 853 | st */
        "movl %esi, %eax\n" /* line 858 | st */
        /* } scope */
        "addl $0x10, %esp\n" /* line 859 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1ebc12_001ebd9f:\n"
        "xorl %eax, %eax\n" /* line 807 */
        /* } scope */
        "addl $0x10, %esp\n" /* line 859 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 861 */
__attribute__((naked))
int sb_decoder_destroy(int *state)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 861 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* state */
        "movl 4(%ebx), %eax\n" /* line 865 | state */
        "movl %eax, (%esp)\n"
        "calll speex_decoder_destroy\n"
        "movl %ebx, 8(%ebp)\n" /* line 867 | state */
        "addl $0x14, %esp\n" /* line 868 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp speex_free\n" /* line 867 */
    );
}

/* line 1216 */
__attribute__((naked))
int sb_encoder_ctl(int *state, int request, int *ptr)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1216 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %edi\n" /* state */
        "movl 0xc(%ebp), %edx\n" /* request */
        "leal -3(%edx), %eax\n" /* line 1220 */
        "cmpl $0x63, %eax\n"
        "ja .Lf1ebdca_001ebde8\n"
        "jmpl *0x3054e0(, %eax, 4)\n"
        ".Lf1ebdca_001ebde8:\n"
        "movl %edx, 4(%esp)\n" /* line 1413 */
        "movl $0x2b90e4, (%esp)\n" /* "Unknown nb_ctl request: " */
        "calll speex_warning_int\n"
        "movl $0xffffffff, %eax\n"
        ".Lf1ebdca_001ebdfd:\n"
        "addl $0x4c, %esp\n" /* line 1417 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl 8(%edi), %edx\n" /* line 1223 | state */
        "movl 0x10(%ebp), %eax\n" /* ptr */
        "movl %edx, (%eax)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ebdca_001ebdfd\n"
        /* { scope 1 */
        "movl 0x10(%ebp), %eax\n" /* line 1303 | ptr */
        "movl (%eax), %ecx\n" /* quality */
        "testl %ecx, %ecx\n" /* line 1304 */
        "js .Lf1ebdca_001ec471\n"
        "cmpl $0xb, %ecx\n" /* line 1306 */
        "movl $0xa, %eax\n"
        "cmovgel %eax, %ecx\n"
        ".Lf1ebdca_001ebe29:\n"
        "movl (%edi), %edx\n" /* line 1308 | state */
        "movl (%edx), %eax\n"
        "movl 0x78(%eax, %ecx, 4), %eax\n"
        "movl %eax, 0xe8(%edi)\n" /* state */
        "movl %eax, 0xec(%edi)\n" /* state */
        "movl (%edx), %eax\n" /* line 1309 */
        "movl 0x4c(%eax, %ecx, 4), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* nb_qual */
        "leal -0x20(%ebp), %eax\n" /* line 1310 | nb_qual */
        "movl %eax, 8(%esp)\n"
        "movl $6, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ebdca_001ebdfd\n"
        /* } scope */
        "movl 0x10(%ebp), %eax\n" /* line 1241 | ptr */
        /* { scope 1 */
        ".Lf1ebdca_001ebe67:\n"
        "movl %eax, 8(%esp)\n" /* line 1268 */
        "movl $4, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* state */
        "calll speex_encoder_ctl\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ebdca_001ebdfd\n"
        /* } scope */
        "movl 0x10(%ebp), %eax\n" /* line 1229 | ptr */
        "movl %eax, 8(%esp)\n"
        "movl $8, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ebdca_001ebdfd\n"
        "movl 0x10(%ebp), %eax\n" /* line 1238 | ptr */
        "movl %eax, 8(%esp)\n"
        "movl $9, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ebdca_001ebdfd\n"
        "movl 0x10(%ebp), %eax\n" /* line 1226 | ptr */
        "movl (%eax), %eax\n"
        "movl %eax, 0xe8(%edi)\n" /* state */
        "movl %eax, 0xec(%edi)\n" /* state */
        "xorl %eax, %eax\n"
        "jmp .Lf1ebdca_001ebdfd\n"
        "movl 0x10(%ebp), %eax\n" /* line 1244 | ptr */
        "movl (%eax), %edx\n"
        "movl %edx, 0xc4(%edi)\n" /* state */
        "movl %eax, 8(%esp)\n" /* line 1245 */
        "movl $0xc, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ebdca_001ebdfd\n"
        "movl 0xc4(%edi), %edx\n" /* line 1248 | state */
        "movl 0x10(%ebp), %eax\n" /* ptr */
        "movl %edx, (%eax)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ebdca_001ebdfd\n"
        /* { scope 1 */
        "movl 0x10(%ebp), %edx\n" /* line 1260 | ptr */
        "cvtss2sd (%edx), %xmm0\n"
        "addsd 0x307e60, %xmm0\n" /* 0.6 */
        "cvtsd2ss %xmm0, %xmm3\n"
        "movss %xmm3, -0x1c(%ebp)\n" /* qual */
        "movl (%edx), %eax\n" /* line 1261 */
        "movl %eax, 0xc0(%edi)\n" /* state */
        "movss 0x2ed6b4, %xmm0\n" /* line 1263 | 10.0f */
        "movss -0x1c(%ebp), %xmm2\n" /* qual */
        "movaps %xmm0, %xmm1\n"
        "movaps %xmm2, %xmm4\n"
        "cmpnltss %xmm3, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n" /* qual */
        "cvtss2sd (%edx), %xmm0\n" /* line 1264 */
        "addsd 0x307ce0, %xmm0\n" /* 0.5 */
        "movsd %xmm0, (%esp)\n"
        "calll floor\n"
        "fstpl -0x30(%ebp)\n"
        "cvttsd2si -0x30(%ebp), %edx\n"
        "movl $0xa, %eax\n" /* line 1266 */
        "cmpl $0xb, %edx\n"
        "cmovll %edx, %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* q */
        "leal -0x1c(%ebp), %eax\n" /* line 1267 | qual */
        "movl %eax, 8(%esp)\n"
        "movl $0xe, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        "leal -0x24(%ebp), %eax\n" /* line 1268 | q */
        "jmp .Lf1ebdca_001ebe67\n"
        /* } scope */
        "movl 0x10(%ebp), %eax\n" /* line 1314 | ptr */
        "movl %eax, 8(%esp)\n"
        "movl $0x10, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        "movl 0x10(%ebp), %eax\n" /* line 1315 | ptr */
        "movl (%eax), %eax\n"
        "movl %eax, 0xf0(%edi)\n" /* state */
        "testl %eax, %eax\n" /* line 1316 */
        "jle .Lf1ebdca_001ec460\n"
        ".Lf1ebdca_001ebfd8:\n"
        "xorl %eax, %eax\n" /* line 1252 */
        ".Lf1ebdca_001ebfda:\n"
        "addl $0x4c, %esp\n" /* line 1417 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl 0xf0(%edi), %edx\n" /* line 1320 | state */
        "movl 0x10(%ebp), %eax\n" /* ptr */
        "movl %edx, (%eax)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ebdca_001ebdfd\n"
        /* { scope 1 */
        "movl $0xa, -0x20(%ebp)\n" /* line 1324 | nb_qual */
        "movl 0x10(%ebp), %eax\n" /* line 1325 | ptr */
        "movl (%eax), %ebx\n" /* target */
        "leal -0x20(%ebp), %esi\n" /* nb_qual */
        ".Lf1ebdca_001ec003:\n"
        "movl %esi, 8(%esp)\n" /* line 1328 */
        "movl $4, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* state */
        "calll speex_encoder_ctl\n"
        "leal -0x24(%ebp), %eax\n" /* line 1329 | q */
        "movl %eax, 8(%esp)\n"
        "movl $0x13, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* state */
        "calll speex_encoder_ctl\n"
        "cmpl -0x24(%ebp), %ebx\n" /* line 1330 | q, target */
        "jge .Lf1ebdca_001ebfd8\n"
        "movl -0x20(%ebp), %eax\n" /* line 1332 | nb_qual */
        "subl $1, %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* nb_qual */
        "testl %eax, %eax\n" /* line 1326 */
        "jns .Lf1ebdca_001ec003\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 1252 */
        "jmp .Lf1ebdca_001ebfda\n"
        "movl 0x10(%ebp), %eax\n" /* line 1337 | ptr */
        "movl %eax, 8(%esp)\n"
        "movl $0x13, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        "movl 0xe8(%edi), %edx\n" /* line 1339 | state */
        "movl 0xe4(%edi), %eax\n" /* state */
        "movl (%eax, %edx, 4), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf1ebdca_001ec478\n"
        "movl 0x10(%ebp), %ebx\n" /* line 1340 | ptr, target */
        "movl 0xf4(%edi), %esi\n" /* state */
        "imull 0x40(%ecx), %esi\n"
        "movl %esi, %eax\n"
        "cltd\n"
        "idivl 8(%edi)\n" /* state */
        "addl %eax, (%ebx)\n" /* target */
        "xorl %eax, %eax\n"
        "jmp .Lf1ebdca_001ebdfd\n"
        /* { scope 1 */
        "movl 0x10(%ebp), %eax\n" /* line 1347 | ptr */
        "movl (%eax), %eax\n"
        "movl %eax, 0xf4(%edi)\n" /* line 1348 | state */
        "sarl $1, %eax\n" /* line 1349 */
        "movl %eax, -0x1c(%ebp)\n" /* qual */
        "leal -0x1c(%ebp), %eax\n" /* line 1350 | qual */
        "movl %eax, 8(%esp)\n"
        "movl $0x18, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ebdca_001ebdfd\n"
        /* } scope */
        "movl 0x10(%ebp), %eax\n" /* line 1232 | ptr */
        "movl %eax, 8(%esp)\n"
        "movl $0x22, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ebdca_001ebdfd\n"
        "movl 0x10(%ebp), %eax\n" /* line 1235 | ptr */
        "movl %eax, 8(%esp)\n"
        "movl $0x23, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ebdca_001ebdfd\n"
        "movl 0x10(%ebp), %eax\n" /* line 1371 | ptr */
        "movl (%eax), %eax\n"
        "movl %eax, 0xe0(%edi)\n" /* state */
        "leal 0x10(%ebp), %eax\n" /* line 1372 | ptr */
        "movl %eax, 8(%esp)\n"
        "movl $0x24, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ebdca_001ebdfd\n"
        "movl 0xe0(%edi), %edx\n" /* line 1375 | state */
        "movl 0x10(%ebp), %eax\n" /* ptr */
        "movl %edx, (%eax)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ebdca_001ebdfd\n"
        "movl 0x10(%ebp), %eax\n" /* line 1378 | ptr */
        "movl %eax, 8(%esp)\n"
        "movl $0x27, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        "movl 0x10(%ebp), %edx\n" /* line 1379 | ptr */
        "movl (%edx), %eax\n"
        "leal 0x3f(%eax, %eax), %eax\n"
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ebdca_001ebdfd\n"
        /* { scope 1 */
        "movl 0x10(%ebp), %ebx\n" /* line 1384 | ptr, g */
        "movl 0x14(%edi), %eax\n" /* line 1385 | state */
        "testl %eax, %eax\n"
        "jle .Lf1ebdca_001ebfd8\n"
        "xorl %ecx, %ecx\n"
        ".Lf1ebdca_001ec17e:\n"
        "leal (, %ecx, 4), %eax\n"
        "movl 0xbc(%edi), %edx\n" /* line 1386 | state */
        "movl (%edx, %eax), %edx\n"
        "movl %edx, (%ebx, %eax)\n" /* g */
        "addl $1, %ecx\n" /* line 1385 */
        "cmpl 0x14(%edi), %ecx\n" /* state */
        "jl .Lf1ebdca_001ec17e\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 1252 */
        "jmp .Lf1ebdca_001ebfda\n"
        /* { scope 1 */
        "movl 0x10(%ebp), %ecx\n" /* line 1392 | ptr, e */
        "movl 8(%edi), %eax\n" /* line 1393 | state */
        "testl %eax, %eax\n"
        "jle .Lf1ebdca_001ec1bb\n"
        "xorl %eax, %eax\n"
        ".Lf1ebdca_001ec1ac:\n"
        "movl $0, (%ecx, %eax, 4)\n" /* line 1394 */
        "addl $1, %eax\n" /* line 1393 */
        "cmpl 8(%edi), %eax\n" /* state */
        "jl .Lf1ebdca_001ec1ac\n"
        ".Lf1ebdca_001ec1bb:\n"
        "movl 0xc(%edi), %eax\n" /* line 1395 | state */
        "testl %eax, %eax\n"
        "jle .Lf1ebdca_001ebfd8\n"
        "xorl %edx, %edx\n"
        ".Lf1ebdca_001ec1c8:\n"
        "movl 0x64(%edi), %eax\n" /* line 1396 | state */
        "movss (%eax, %edx, 4), %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "movss %xmm0, (%ecx, %edx, 8)\n"
        "addl $1, %edx\n" /* line 1395 */
        "cmpl 0xc(%edi), %edx\n" /* state */
        "jl .Lf1ebdca_001ec1c8\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 1252 */
        "jmp .Lf1ebdca_001ebfda\n"
        /* { scope 1 */
        "movl 0x10(%ebp), %ecx\n" /* line 1402 | ptr, e */
        "movl 8(%edi), %eax\n" /* line 1403 | state */
        "testl %eax, %eax\n"
        "jle .Lf1ebdca_001ec203\n"
        "xorl %eax, %eax\n"
        ".Lf1ebdca_001ec1f4:\n"
        "movl $0, (%ecx, %eax, 4)\n" /* line 1404 */
        "addl $1, %eax\n" /* line 1403 */
        "cmpl 8(%edi), %eax\n" /* state */
        "jl .Lf1ebdca_001ec1f4\n"
        ".Lf1ebdca_001ec203:\n"
        "movl 0xc(%edi), %eax\n" /* line 1405 | state */
        "testl %eax, %eax\n"
        "jle .Lf1ebdca_001ebfd8\n"
        "xorl %edx, %edx\n"
        ".Lf1ebdca_001ec210:\n"
        "movl 0x64(%edi), %eax\n" /* line 1406 | state */
        "movss (%eax, %edx, 4), %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "movss %xmm0, (%ecx, %edx, 8)\n"
        "addl $1, %edx\n" /* line 1405 */
        "cmpl 0xc(%edi), %edx\n" /* state */
        "jl .Lf1ebdca_001ec210\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 1252 */
        "jmp .Lf1ebdca_001ebfda\n"
        "movl 0x10(%ebp), %eax\n" /* line 1251 | ptr */
        "movl (%eax), %edx\n"
        "movl %edx, 0xd8(%edi)\n" /* state */
        "movl %eax, 8(%esp)\n" /* line 1252 */
        "movl $0x1e, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ebdca_001ebfda\n"
        /* { scope 1 */
        "movl $1, 0x24(%edi)\n" /* line 1359 | state */
        "movl 0x1c(%edi), %ecx\n" /* line 1360 | state */
        "testl %ecx, %ecx\n"
        "jle .Lf1ebdca_001ec2e1\n"
        "xorl %ebx, %ebx\n" /* i */
        "movsd 0x307c28, %xmm2\n" /* 3.141592653589793 */
        ".Lf1ebdca_001ec271:\n"
        "movl 0x88(%edi), %eax\n" /* line 1361 | state */
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
        "movl 0x1c(%edi), %ecx\n" /* line 1360 | state */
        "cmpl %ecx, %ebx\n" /* i */
        "jl .Lf1ebdca_001ec271\n"
        "testl %ecx, %ecx\n" /* line 1362 */
        "jle .Lf1ebdca_001ec2e1\n"
        "xorl %esi, %esi\n"
        ".Lf1ebdca_001ec2a9:\n"
        "leal (, %esi, 4), %eax\n"
        "movl %eax, %ebx\n" /* line 1363 | i */
        "addl 0xb8(%edi), %ebx\n" /* state, i */
        "movl %eax, %ecx\n"
        "addl 0xb0(%edi), %ecx\n" /* state */
        "movl 0xb4(%edi), %edx\n" /* state */
        "movl $0, (%edx, %eax)\n"
        "movl $0, (%ecx)\n"
        "movl $0, (%ebx)\n" /* i */
        "addl $1, %esi\n" /* line 1362 */
        "cmpl 0x1c(%edi), %esi\n" /* state */
        "jl .Lf1ebdca_001ec2a9\n"
        ".Lf1ebdca_001ec2e1:\n"
        "movl 0x20(%edi), %edx\n" /* line 1364 | state */
        "testl %edx, %edx\n"
        "jle .Lf1ebdca_001ec2fc\n"
        "xorl %edx, %edx\n"
        ".Lf1ebdca_001ec2ea:\n"
        "movl 0x60(%edi), %eax\n" /* line 1365 | state */
        "movl $0, (%eax, %edx, 4)\n"
        "addl $1, %edx\n" /* line 1364 */
        "cmpl 0x20(%edi), %edx\n" /* state */
        "jl .Lf1ebdca_001ec2ea\n"
        ".Lf1ebdca_001ec2fc:\n"
        "xorl %esi, %esi\n"
        ".Lf1ebdca_001ec2fe:\n"
        "movl %esi, %ebx\n" /* line 1367 | i */
        "addl 0x50(%edi), %ebx\n" /* state, i */
        "movl %esi, %ecx\n"
        "addl 0x54(%edi), %ecx\n" /* state */
        "movl %esi, %edx\n"
        "addl 0x58(%edi), %edx\n" /* state */
        "movl 0x5c(%edi), %eax\n" /* state */
        "movl $0, (%eax, %esi)\n"
        "movl $0, (%edx)\n"
        "movl $0, (%ecx)\n"
        "movl $0, (%ebx)\n" /* i */
        "addl $4, %esi\n"
        "cmpl $0x100, %esi\n" /* line 1366 */
        "jne .Lf1ebdca_001ec2fe\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 1252 */
        "jmp .Lf1ebdca_001ebfda\n"
        "movl 0xdc(%edi), %edx\n" /* line 1410 | state */
        "movl 0x10(%ebp), %eax\n" /* ptr */
        "movl %edx, (%eax)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ebdca_001ebdfd\n"
        "movl 0x10(%ebp), %eax\n" /* line 1272 | ptr */
        "movl (%eax), %eax\n"
        "movl %eax, 0xc8(%edi)\n" /* state */
        "movl $1, 0xc4(%edi)\n" /* line 1273 | state */
        "leal 0xc4(%edi), %eax\n" /* line 1274 | state */
        "movl %eax, 8(%esp)\n"
        "movl $0xc, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_encoder_ctl\n"
        /* { scope 1 */
        "movl $0xa, -0x1c(%ebp)\n" /* line 1276 | qual */
        "movl 0x10(%ebp), %eax\n" /* line 1278 | ptr */
        "movl (%eax), %ebx\n" /* target */
        "leal -0x1c(%ebp), %esi\n" /* qual */
        ".Lf1ebdca_001ec38e:\n"
        "movl %esi, 8(%esp)\n" /* line 1281 */
        "movl $4, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* state */
        "calll speex_encoder_ctl\n"
        "leal -0x24(%ebp), %eax\n" /* line 1282 | q */
        "movl %eax, 8(%esp)\n"
        "movl $0x13, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* state */
        "calll speex_encoder_ctl\n"
        "cmpl -0x24(%ebp), %ebx\n" /* line 1283 | q, target */
        "jge .Lf1ebdca_001ec3cb\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1285 | qual */
        "subl $1, %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* qual */
        "testl %eax, %eax\n" /* line 1279 */
        "jns .Lf1ebdca_001ec38e\n"
        ".Lf1ebdca_001ec3cb:\n"
        "cvtsi2ssl -0x1c(%ebp), %xmm0\n" /* line 1287 | qual */
        "pxor %xmm1, %xmm1\n" /* line 1288 */
        "movaps %xmm0, %xmm2\n" /* line 1289 */
        "cmpnltss %xmm1, %xmm0\n"
        "andps %xmm0, %xmm2\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm2, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n" /* nb_qual */
        "leal -0x20(%ebp), %eax\n" /* line 1290 | nb_qual */
        "movl %eax, 8(%esp)\n"
        "movl $0xe, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* state */
        "movss %xmm1, -0x48(%ebp)\n"
        "calll speex_encoder_ctl\n"
        "movss -0x48(%ebp), %xmm1\n" /* line 1291 */
        "movss %xmm1, 0xd4(%edi)\n" /* state */
        "movss %xmm1, 0xcc(%edi)\n" /* line 1292 | state */
        "movss %xmm1, 0xd0(%edi)\n" /* line 1293 | state */
        "xorl %eax, %eax\n"
        "jmp .Lf1ebdca_001ebdfd\n"
        /* } scope */
        "movl 0xc8(%edi), %edx\n" /* line 1298 | state */
        "movl 0x10(%ebp), %eax\n" /* ptr */
        "movl %edx, (%eax)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ebdca_001ebdfd\n"
        "movl 0xf4(%edi), %edx\n" /* line 1354 | state */
        "movl 0x10(%ebp), %eax\n" /* ptr */
        "movl %edx, (%eax)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ebdca_001ebdfd\n"
        "movl 0xd8(%edi), %edx\n" /* line 1255 | state */
        "movl 0x10(%ebp), %eax\n" /* ptr */
        "movl %edx, (%eax)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ebdca_001ebdfd\n"
        ".Lf1ebdca_001ec460:\n"
        "movl $1, 0xf0(%edi)\n" /* line 1317 | state */
        "xorl %eax, %eax\n"
        "jmp .Lf1ebdca_001ebdfd\n"
        /* { scope 1 */
        ".Lf1ebdca_001ec471:\n"
        "xorl %ecx, %ecx\n" /* line 1304 */
        "jmp .Lf1ebdca_001ebe29\n"
        /* } scope */
        ".Lf1ebdca_001ec478:\n"
        "movl 0x10(%ebp), %ebx\n" /* line 1342 | ptr, target */
        "movl 0xf4(%edi), %edx\n" /* state */
        "shll $2, %edx\n"
        "movl %edx, %eax\n"
        "cltd\n"
        "idivl 8(%edi)\n" /* state */
        "addl %eax, (%ebx)\n" /* target */
        "xorl %eax, %eax\n"
        "jmp .Lf1ebdca_001ebdfd\n"
    );
}

/* line 1419 */
__attribute__((naked))
int sb_decoder_ctl(int *state, int request, int *ptr)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1419 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* state */
        "movl 0xc(%ebp), %eax\n" /* request */
        "cmpl $0x67, %eax\n" /* line 1423 */
        "ja .Lf1ec494_001ec4af\n"
        "jmpl *0x305670(, %eax, 4)\n"
        ".Lf1ec494_001ec4af:\n"
        "movl %eax, 4(%esp)\n" /* line 1527 */
        "movl $0x2b90e4, (%esp)\n" /* "Unknown nb_ctl request: " */
        "calll speex_warning_int\n"
        "movl $0xffffffff, %eax\n"
        ".Lf1ec494_001ec4c4:\n"
        "addl $0x2c, %esp\n" /* line 1531 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl 0x10(%ebp), %eax\n" /* line 1438 | ptr */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl 4(%ebx), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_decoder_ctl\n"
        "movl 0x10(%ebp), %eax\n" /* line 1439 | ptr */
        "movl (%eax), %eax\n"
        "movl %eax, 0x24(%ebx)\n" /* state */
        "xorl %eax, %eax\n"
        "jmp .Lf1ec494_001ec4c4\n"
        "movl 8(%ebx), %edx\n" /* line 1435 | state */
        "movl 0x10(%ebp), %eax\n" /* ptr */
        "movl %edx, (%eax)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ec494_001ec4c4\n"
        /* { scope 1 */
        "movl 0x10(%ebp), %eax\n" /* line 1445 | ptr */
        "movl (%eax), %ecx\n" /* quality */
        "testl %ecx, %ecx\n" /* line 1446 */
        "js .Lf1ec494_001ec7b9\n"
        "cmpl $0xb, %ecx\n" /* line 1448 */
        "movl $0xa, %eax\n"
        "cmovgel %eax, %ecx\n"
        ".Lf1ec494_001ec516:\n"
        "movl (%ebx), %edx\n" /* line 1450 | state */
        "movl (%edx), %eax\n"
        "movl 0x78(%eax, %ecx, 4), %eax\n"
        "movl %eax, 0x6c(%ebx)\n" /* state */
        "movl (%edx), %eax\n" /* line 1451 */
        "movl 0x4c(%eax, %ecx, 4), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* nb_qual */
        "leal -0x1c(%ebp), %eax\n" /* line 1452 | nb_qual */
        "movl %eax, 8(%esp)\n"
        "movl $6, 4(%esp)\n"
        "movl 4(%ebx), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_decoder_ctl\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ec494_001ec4c4\n"
        /* } scope */
        "movl 0x10(%ebp), %eax\n" /* line 1429 | ptr */
        "movl %eax, 8(%esp)\n"
        "movl $8, 4(%esp)\n"
        "movl 4(%ebx), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_decoder_ctl\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ec494_001ec4c4\n"
        "movl 0x10(%ebp), %eax\n" /* line 1432 | ptr */
        "movl %eax, 8(%esp)\n"
        "movl $9, 4(%esp)\n"
        "movl 4(%ebx), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_decoder_ctl\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ec494_001ec4c4\n"
        "movl 0x10(%ebp), %eax\n" /* line 1426 | ptr */
        "movl (%eax), %eax\n"
        "movl %eax, 0x6c(%ebx)\n" /* state */
        "xorl %eax, %eax\n"
        "jmp .Lf1ec494_001ec4c4\n"
        "movl 0x10(%ebp), %eax\n" /* line 1456 | ptr */
        "movl %eax, 8(%esp)\n"
        "movl $0x13, 4(%esp)\n"
        "movl 4(%ebx), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_decoder_ctl\n"
        "movl 0x6c(%ebx), %edx\n" /* line 1457 | state */
        "movl 0x68(%ebx), %eax\n" /* state */
        "movl (%eax, %edx, 4), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf1ec494_001ec7c0\n"
        "movl 0x10(%ebp), %esi\n" /* line 1458 | ptr */
        "movl 0x20(%ebx), %edi\n" /* state */
        "imull 0x40(%ecx), %edi\n"
        "movl %edi, %eax\n"
        "cltd\n"
        "idivl 8(%ebx)\n" /* state */
        "addl %eax, (%esi)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ec494_001ec4c4\n"
        "movl 0x10(%ebp), %eax\n" /* line 1474 | ptr */
        "movl %eax, 8(%esp)\n"
        "movl $0x14, 4(%esp)\n"
        "movl 4(%ebx), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_decoder_ctl\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ec494_001ec4c4\n"
        "movl 0x10(%ebp), %eax\n" /* line 1477 | ptr */
        "movl %eax, 8(%esp)\n"
        "movl $0x16, 4(%esp)\n"
        "movl 4(%ebx), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_decoder_ctl\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ec494_001ec4c4\n"
        /* { scope 1 */
        "movl 0x10(%ebp), %eax\n" /* line 1464 | ptr */
        "movl (%eax), %eax\n"
        "movl %eax, 0x20(%ebx)\n" /* line 1465 | state */
        "sarl $1, %eax\n" /* line 1466 */
        "movl %eax, -0x1c(%ebp)\n" /* nb_qual */
        "leal -0x1c(%ebp), %eax\n" /* line 1467 | nb_qual */
        "movl %eax, 8(%esp)\n"
        "movl $0x18, 4(%esp)\n"
        "movl 4(%ebx), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_decoder_ctl\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ec494_001ec4c4\n"
        /* } scope */
        "movl 0x20(%ebx), %edx\n" /* line 1471 | state */
        "movl 0x10(%ebp), %eax\n" /* ptr */
        "movl %edx, (%eax)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ec494_001ec4c4\n"
        /* { scope 1 */
        "movl 0x18(%ebx), %eax\n" /* line 1482 | state */
        "addl %eax, %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf1ec494_001ec680\n"
        "xorl %edx, %edx\n"
        ".Lf1ec494_001ec66a:\n"
        "movl 0x5c(%ebx), %eax\n" /* line 1483 | state */
        "movl $0, (%eax, %edx, 4)\n"
        "addl $1, %edx\n" /* line 1482 */
        "movl 0x18(%ebx), %eax\n" /* state */
        "addl %eax, %eax\n"
        "cmpl %eax, %edx\n"
        "jl .Lf1ec494_001ec66a\n"
        ".Lf1ec494_001ec680:\n"
        "xorl %ecx, %ecx\n"
        ".Lf1ec494_001ec682:\n"
        "movl %ecx, %edx\n" /* line 1485 */
        "addl 0x40(%ebx), %edx\n" /* state */
        "movl 0x44(%ebx), %eax\n" /* state */
        "movl $0, (%eax, %ecx)\n"
        "movl $0, (%edx)\n"
        "addl $4, %ecx\n"
        "cmpl $0x100, %ecx\n" /* line 1484 */
        "jne .Lf1ec494_001ec682\n"
        /* } scope */
        ".Lf1ec494_001ec6a2:\n"
        "xorl %eax, %eax\n" /* line 1528 */
        ".Lf1ec494_001ec6a4:\n"
        "addl $0x2c, %esp\n" /* line 1531 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl 0x10(%ebp), %eax\n" /* line 1489 | ptr */
        "movl (%eax), %eax\n"
        "movl %eax, 0x64(%ebx)\n" /* state */
        "leal 0x10(%ebp), %eax\n" /* line 1490 | ptr */
        "movl %eax, 8(%esp)\n"
        "movl $0x24, 4(%esp)\n"
        "movl 4(%ebx), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_decoder_ctl\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ec494_001ec4c4\n"
        /* { scope 1 */
        "movl 0x10(%ebp), %esi\n" /* line 1498 | ptr, g */
        "movl 0x14(%ebx), %eax\n" /* line 1499 | state */
        "testl %eax, %eax\n"
        "jle .Lf1ec494_001ec6a2\n"
        "xorl %ecx, %ecx\n"
        ".Lf1ec494_001ec6e1:\n"
        "leal (, %ecx, 4), %eax\n"
        "movl 0x60(%ebx), %edx\n" /* line 1500 | state */
        "movl (%edx, %eax), %edx\n"
        "movl %edx, (%esi, %eax)\n" /* g */
        "addl $1, %ecx\n" /* line 1499 */
        "cmpl 0x14(%ebx), %ecx\n" /* state */
        "jl .Lf1ec494_001ec6e1\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 1528 */
        "jmp .Lf1ec494_001ec6a4\n"
        /* { scope 1 */
        "movl 0x10(%ebp), %ecx\n" /* line 1506 | ptr, e */
        "movl 8(%ebx), %eax\n" /* line 1507 | state */
        "testl %eax, %eax\n"
        "jle .Lf1ec494_001ec718\n"
        "xorl %eax, %eax\n"
        ".Lf1ec494_001ec709:\n"
        "movl $0, (%ecx, %eax, 4)\n" /* line 1508 */
        "addl $1, %eax\n" /* line 1507 */
        "cmpl 8(%ebx), %eax\n" /* state */
        "jl .Lf1ec494_001ec709\n"
        ".Lf1ec494_001ec718:\n"
        "movl 0xc(%ebx), %eax\n" /* line 1509 | state */
        "testl %eax, %eax\n"
        "jle .Lf1ec494_001ec6a2\n"
        "xorl %edx, %edx\n"
        ".Lf1ec494_001ec721:\n"
        "movl 0x48(%ebx), %eax\n" /* line 1510 | state */
        "movss (%eax, %edx, 4), %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "movss %xmm0, (%ecx, %edx, 8)\n"
        "addl $1, %edx\n" /* line 1509 */
        "cmpl 0xc(%ebx), %edx\n" /* state */
        "jl .Lf1ec494_001ec721\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 1528 */
        "jmp .Lf1ec494_001ec6a4\n"
        /* { scope 1 */
        "movl 0x10(%ebp), %ecx\n" /* line 1516 | ptr, e */
        "movl 8(%ebx), %edi\n" /* line 1517 | state */
        "testl %edi, %edi\n"
        "jle .Lf1ec494_001ec75c\n"
        "xorl %eax, %eax\n"
        ".Lf1ec494_001ec74d:\n"
        "movl $0, (%ecx, %eax, 4)\n" /* line 1518 */
        "addl $1, %eax\n" /* line 1517 */
        "cmpl 8(%ebx), %eax\n" /* state */
        "jl .Lf1ec494_001ec74d\n"
        ".Lf1ec494_001ec75c:\n"
        "movl 0xc(%ebx), %esi\n" /* line 1519 | state, g */
        "testl %esi, %esi\n" /* g */
        "jle .Lf1ec494_001ec6a2\n"
        "xorl %edx, %edx\n"
        ".Lf1ec494_001ec769:\n"
        "movl 0x48(%ebx), %eax\n" /* line 1520 | state */
        "movss (%eax, %edx, 4), %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "movss %xmm0, (%ecx, %edx, 8)\n"
        "addl $1, %edx\n" /* line 1519 */
        "cmpl 0xc(%ebx), %edx\n" /* state */
        "jl .Lf1ec494_001ec769\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 1528 */
        "jmp .Lf1ec494_001ec6a4\n"
        "movl 0x10(%ebp), %eax\n" /* line 1524 | ptr */
        "movl %eax, 8(%esp)\n"
        "movl $0x67, 4(%esp)\n"
        "movl 4(%ebx), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_decoder_ctl\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ec494_001ec4c4\n"
        "movl 0x64(%ebx), %edx\n" /* line 1493 | state */
        "movl 0x10(%ebp), %eax\n" /* ptr */
        "movl %edx, (%eax)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ec494_001ec4c4\n"
        /* { scope 1 */
        ".Lf1ec494_001ec7b9:\n"
        "xorl %ecx, %ecx\n" /* line 1446 */
        "jmp .Lf1ec494_001ec516\n"
        /* } scope */
        ".Lf1ec494_001ec7c0:\n"
        "movl 0x10(%ebp), %esi\n" /* line 1460 | ptr */
        "movl 0x20(%ebx), %edx\n" /* state */
        "shll $2, %edx\n"
        "movl %edx, %eax\n"
        "cltd\n"
        "idivl 8(%ebx)\n" /* state */
        "addl %eax, (%esi)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1ec494_001ec4c4\n"
    );
}

/* line 870 */
static __attribute__((naked))
int sb_decode_lost(char * (*out)[16], int dtx, char *stack)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 870 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, %edi\n" /* st */
        "movl %edx, -0x34(%ebp)\n"
        "movl %ecx, -0x38(%ebp)\n"
        "movl 8(%ebp), %ebx\n" /* stack */
        /* { scope 1: x0 */
        "testl %ecx, %ecx\n" /* line 878 */
        "je .Lf1ec7d8_001ecb07\n"
        "movl 0x6c(%eax), %eax\n" /* line 880 */
        "movl %eax, -0x20(%ebp)\n" /* saved_modeid */
        "movl $1, 0x6c(%edi)\n" /* line 881 | st */
        ".Lf1ec7d8_001ec801:\n"
        "movl $1, 0x1c(%edi)\n" /* line 886 | st */
        "movl 0x18(%edi), %edx\n" /* line 888 | st */
        "movl %edx, -0x30(%ebp)\n"
        "movl %edx, %esi\n"
        "shll $2, %esi\n"
        "movl $4, %ecx\n"
        "movl %ecx, %eax\n"
        "subl %ebx, %eax\n" /* stack */
        "andl $3, %eax\n"
        "leal (%ebx, %eax), %eax\n" /* stack */
        "leal 4(%eax, %esi), %eax\n"
        "movl %esi, %ebx\n" /* stack */
        "negl %ebx\n" /* stack */
        "leal -4(%eax, %ebx), %edx\n"
        "movl %edx, -0x2c(%ebp)\n" /* awk1 */
        "movl %ecx, %edx\n" /* line 889 */
        "subl %eax, %edx\n"
        "andl $3, %edx\n"
        "addl %edx, %eax\n"
        "leal 4(%esi, %eax), %eax\n"
        "leal -4(%ebx, %eax), %edx\n" /* stack */
        "movl %edx, -0x28(%ebp)\n" /* awk2 */
        "subl %eax, %ecx\n" /* line 890 */
        "andl $3, %ecx\n"
        "addl %ecx, %eax\n"
        "leal 4(%esi, %eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "leal -4(%ebx, %eax), %ebx\n" /* stack */
        "movl %ebx, -0x24(%ebp)\n" /* stack, awk3 */
        "movl 0x24(%edi), %edx\n" /* line 892 | st */
        "testl %edx, %edx\n"
        "je .Lf1ec7d8_001ec8d2\n"
        /* { scope 2 */
        "movl 0x6c(%edi), %edx\n" /* line 895 | st */
        "movl 0x68(%edi), %eax\n" /* st */
        "movl (%eax, %edx, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1ec7d8_001ecb31\n"
        "movl 0x30(%eax), %edx\n" /* line 897 */
        "movl 0x34(%eax), %ebx\n" /* line 898 | k2 */
        "movl 0x38(%eax), %esi\n" /* line 899 | k3 */
        ".Lf1ec7d8_001ec87b:\n"
        "movl -0x30(%ebp), %eax\n" /* line 904 */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x2c(%ebp), %eax\n" /* awk1 */
        "movl %eax, 8(%esp)\n"
        "movl 0x58(%edi), %eax\n" /* st */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll bw_lpc\n"
        "movl 0x18(%edi), %eax\n" /* line 905 | st */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x28(%ebp), %edx\n" /* awk2 */
        "movl %edx, 8(%esp)\n"
        "movl 0x58(%edi), %eax\n" /* st */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* k2 */
        "calll bw_lpc\n"
        "movl 0x18(%edi), %eax\n" /* line 906 | st */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x24(%ebp), %ebx\n" /* awk3, k2 */
        "movl %ebx, 8(%esp)\n" /* k2 */
        "movl 0x58(%edi), %eax\n" /* st */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* k3 */
        "calll bw_lpc\n"
        /* } scope */
        ".Lf1ec7d8_001ec8d2:\n"
        "movl -0x38(%ebp), %eax\n" /* line 912 */
        "testl %eax, %eax\n"
        "jne .Lf1ec7d8_001eca48\n"
        "movl 0xc(%edi), %esi\n" /* line 914 | st, k3 */
        "testl %esi, %esi\n" /* k3 */
        "jg .Lf1ec7d8_001eca20\n"
        ".Lf1ec7d8_001ec8e8:\n"
        "movl 0x24(%edi), %eax\n" /* line 921 | st */
        "testl %eax, %eax\n"
        "jne .Lf1ec7d8_001eca7d\n"
        ".Lf1ec7d8_001ec8f3:\n"
        "movl 0x18(%edi), %ebx\n" /* line 930 | st, k2 */
        "testl %ebx, %ebx\n" /* k2 */
        "jg .Lf1ec7d8_001ecae6\n"
        ".Lf1ec7d8_001ec8fe:\n"
        "movl 0x34(%edi), %eax\n" /* line 933 | st */
        "movl 0x5c(%edi), %edx\n" /* st */
        "movl %edx, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n" /* k2 */
        "movl %esi, 0xc(%esp)\n" /* k3 */
        "movl %eax, 8(%esp)\n"
        "movl 0x58(%edi), %edx\n" /* st */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll iir_mem2\n"
        ".Lf1ec7d8_001ec923:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 939 */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x40(%edi), %eax\n" /* st */
        "movl %eax, 0x14(%esp)\n"
        "movl $0x40, 0x10(%esp)\n"
        "movl 8(%edi), %eax\n" /* st */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x38(%edi), %eax\n" /* st */
        "movl %eax, 8(%esp)\n"
        "movl $h0, 4(%esp)\n"
        "movl 0x2c(%edi), %eax\n" /* st */
        "movl %eax, (%esp)\n"
        "calll fir_mem_up\n"
        "movl -0x1c(%ebp), %edx\n" /* line 940 */
        "movl %edx, 0x18(%esp)\n"
        "movl 0x44(%edi), %eax\n" /* st */
        "movl %eax, 0x14(%esp)\n"
        "movl $0x40, 0x10(%esp)\n"
        "movl 8(%edi), %eax\n" /* st */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x3c(%edi), %eax\n" /* st */
        "movl %eax, 8(%esp)\n"
        "movl $h1, 4(%esp)\n"
        "movl 0x34(%edi), %eax\n" /* st */
        "movl %eax, (%esp)\n"
        "calll fir_mem_up\n"
        "movl 8(%edi), %ecx\n" /* line 942 | st, len */
        "movl 0x3c(%edi), %esi\n" /* st, x1 */
        "movl 0x38(%edi), %ebx\n" /* st, k2 */
        "movl %ebx, -0x3c(%ebp)\n" /* k2, x0 */
        /* { scope 2 */
        /* { scope 3 */
        "testl %ecx, %ecx\n" /* line 207 */
        "jle .Lf1ec7d8_001eca0b\n"
        "xorl %edx, %edx\n"
        "movss 0x2edaa8, %xmm3\n" /* -32767.0f */
        "movss 0x2edaa4, %xmm2\n" /* 32767.0f */
        "jmp .Lf1ec7d8_001ec9c6\n"
        /* { scope 4 */
        ".Lf1ec7d8_001ec9b5:\n"
        "movl -0x34(%ebp), %ebx\n" /* line 216 */
        "movl $0x46fffe00, (%ebx, %eax)\n"
        /* } scope */
        "addl $1, %edx\n" /* line 207 */
        "cmpl %edx, %ecx\n"
        "je .Lf1ec7d8_001eca0b\n"
        ".Lf1ec7d8_001ec9c6:\n"
        "leal (, %edx, 4), %eax\n" /* line 870 */
        /* { scope 4 */
        "movl -0x3c(%ebp), %ebx\n" /* line 213 | x0 */
        "movss (%ebx, %eax), %xmm1\n"
        "subss (%esi, %eax), %xmm1\n"
        "addss %xmm1, %xmm1\n"
        "ucomiss %xmm2, %xmm1\n" /* line 215 */
        "ja .Lf1ec7d8_001ec9b5\n"
        "movss 0x2edaa8, %xmm0\n" /* line 218 | -32767.0f */
        "movaps %xmm1, %xmm4\n"
        "cmpnltss %xmm3, %xmm1\n"
        "andps %xmm1, %xmm4\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm4, %xmm1\n"
        "movl -0x34(%ebp), %ebx\n"
        "movss %xmm1, (%ebx, %eax)\n"
        /* } scope */
        "addl $1, %edx\n" /* line 207 */
        "cmpl %edx, %ecx\n"
        "jne .Lf1ec7d8_001ec9c6\n"
        /* } scope */
        /* } scope */
        ".Lf1ec7d8_001eca0b:\n"
        "movl -0x38(%ebp), %eax\n" /* line 944 */
        "testl %eax, %eax\n"
        "je .Lf1ec7d8_001eca18\n"
        "movl -0x20(%ebp), %eax\n" /* line 946 | saved_modeid */
        "movl %eax, 0x6c(%edi)\n" /* st */
        /* } scope */
        ".Lf1ec7d8_001eca18:\n"
        "addl $0x5c, %esp\n" /* line 950 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: x0 */
        ".Lf1ec7d8_001eca20:\n"
        "xorl %edx, %edx\n" /* line 914 */
        "movsd 0x307e68, %xmm1\n" /* 0.9 */
        ".Lf1ec7d8_001eca2a:\n"
        "movl 0x48(%edi), %eax\n" /* line 915 | st */
        "leal (%eax, %edx, 4), %eax\n"
        "cvtss2sd (%eax), %xmm0\n"
        "mulsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "addl $1, %edx\n" /* line 914 */
        "cmpl 0xc(%edi), %edx\n" /* st */
        "jl .Lf1ec7d8_001eca2a\n"
        ".Lf1ec7d8_001eca48:\n"
        "movl 0xc(%edi), %esi\n" /* line 918 | st, k3 */
        "testl %esi, %esi\n" /* k3 */
        "jle .Lf1ec7d8_001ec8e8\n"
        "xorl %ebx, %ebx\n" /* k2 */
        ".Lf1ec7d8_001eca55:\n"
        "leal (, %ebx, 4), %edx\n"
        "movl 0x34(%edi), %ecx\n" /* line 919 | st */
        "movl 0x48(%edi), %eax\n" /* st */
        "movl (%edx, %eax), %eax\n"
        "movl %eax, (%edx, %ecx)\n"
        "addl $1, %ebx\n" /* line 918 | k2 */
        "movl 0xc(%edi), %esi\n" /* st, k3 */
        "cmpl %ebx, %esi\n" /* k2, k3 */
        "jg .Lf1ec7d8_001eca55\n"
        "movl 0x24(%edi), %eax\n" /* line 921 | st */
        "testl %eax, %eax\n"
        "je .Lf1ec7d8_001ec8f3\n"
        ".Lf1ec7d8_001eca7d:\n"
        "movl 0x18(%edi), %edx\n" /* line 925 | st */
        "movl 0x34(%edi), %ecx\n" /* st */
        "movl 0x5c(%edi), %eax\n" /* st */
        "leal (%eax, %edx, 4), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl %edx, 0x14(%esp)\n"
        "movl %esi, 0x10(%esp)\n" /* k3 */
        "movl %ecx, 0xc(%esp)\n"
        "movl -0x2c(%ebp), %eax\n" /* awk1 */
        "movl %eax, 8(%esp)\n"
        "movl -0x28(%ebp), %edx\n" /* awk2 */
        "movl %edx, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll filter_mem2\n"
        "movl 0x34(%edi), %edx\n" /* line 927 | st */
        "movl 0x5c(%edi), %eax\n" /* st */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x18(%edi), %eax\n" /* st */
        "movl %eax, 0x14(%esp)\n"
        "movl 0xc(%edi), %eax\n" /* st */
        "movl %eax, 0x10(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl 0x58(%edi), %eax\n" /* st */
        "movl %eax, 8(%esp)\n"
        "movl -0x24(%ebp), %ebx\n" /* awk3, k2 */
        "movl %ebx, 4(%esp)\n" /* k2 */
        "movl %edx, (%esp)\n"
        "calll filter_mem2\n"
        "jmp .Lf1ec7d8_001ec923\n"
        ".Lf1ec7d8_001ecae6:\n"
        "xorl %ecx, %ecx\n" /* line 930 */
        ".Lf1ec7d8_001ecae8:\n"
        "leal (%ecx, %ebx), %edx\n" /* line 931 */
        "movl 0x5c(%edi), %eax\n" /* st */
        "movl $0, (%eax, %edx, 4)\n"
        "addl $1, %ecx\n" /* line 930 */
        "movl 0x18(%edi), %ebx\n" /* st, k2 */
        "cmpl %ebx, %ecx\n" /* k2 */
        "jl .Lf1ec7d8_001ecae8\n"
        "movl 0xc(%edi), %esi\n" /* st, k3 */
        "jmp .Lf1ec7d8_001ec8fe\n"
        ".Lf1ec7d8_001ecb07:\n"
        "movl 0x58(%eax), %edx\n" /* line 883 */
        "movl 0x18(%eax), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl $0x3f7d70a4, (%esp)\n"
        "calll bw_lpc\n"
        "movl $0, -0x20(%ebp)\n" /* saved_modeid */
        "jmp .Lf1ec7d8_001ec801\n"
        /* { scope 2 */
        ".Lf1ec7d8_001ecb31:\n"
        "movl $0x3f333333, %ebx\n" /* line 895 | k2 */
        "movl %ebx, %edx\n" /* k2 */
        "xorl %esi, %esi\n" /* k3 */
        "jmp .Lf1ec7d8_001ec87b\n"
    );
}

/* line 952 */
__attribute__((naked))
int sb_decode(int *state, SpeexBits *bits, int *vout)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 952 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        "movl 8(%ebp), %edi\n" /* state */
        /* { scope 1: x0, exc, sp, filter_ratio, ... */
        "movl 0x28(%edi), %edx\n" /* line 970 | state */
        "movl (%edi), %eax\n" /* line 971 | state */
        "movl (%eax), %eax\n"
        "movl %eax, -0x50(%ebp)\n" /* mode */
        /* { scope 2: scale */
        "movl %edx, %eax\n" /* line 975 */
        "negl %eax\n"
        "andl $3, %eax\n"
        "addl %eax, %edx\n"
        "movl 0xc(%edi), %eax\n" /* state */
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl %edx, %esi\n" /* low */
        "movl %edx, 8(%esp)\n" /* line 978 */
        "movl 0xc(%ebp), %eax\n" /* bits */
        "movl %eax, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_decode_native\n"
        "movl %eax, -0x6c(%ebp)\n" /* ret */
        "movl 0xc(%edi), %edx\n" /* line 980 | state */
        "testl %edx, %edx\n"
        "jle .Lf1ecb40_001ecba7\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf1ecb40_001ecb8f:\n"
        "leal (, %ebx, 4), %eax\n"
        "movl 0x2c(%edi), %ecx\n" /* line 981 | state */
        "movl (%esi, %eax), %edx\n" /* low */
        "movl %edx, (%ecx, %eax)\n"
        "addl $1, %ebx\n" /* line 980 | i */
        "cmpl 0xc(%edi), %ebx\n" /* state, i */
        "jl .Lf1ecb40_001ecb8f\n"
        /* } scope */
        ".Lf1ecb40_001ecba7:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 984 | dtx */
        "movl %eax, 8(%esp)\n"
        "movl $0x67, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_decoder_ctl\n"
        "movl -0x6c(%ebp), %eax\n" /* line 987 | ret */
        "testl %eax, %eax\n"
        "jne .Lf1ecb40_001ece3a\n"
        "movl 0xc(%ebp), %eax\n" /* line 992 | bits */
        "testl %eax, %eax\n"
        "je .Lf1ecb40_001ed556\n"
        "movl 0x64(%edi), %eax\n" /* line 998 | state */
        "testl %eax, %eax\n"
        "jne .Lf1ecb40_001ece5f\n"
        "movl 0x6c(%edi), %edx\n" /* state */
        ".Lf1ecb40_001ecbe5:\n"
        "movl 0x68(%edi), %eax\n" /* line 1024 | state */
        "movl (%eax, %edx, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1ecb40_001eced5\n"
        ".Lf1ecb40_001ecbf3:\n"
        "movl 0xc(%edi), %ebx\n" /* line 1049 | state, len */
        "testl %ebx, %ebx\n" /* len */
        "jle .Lf1ecb40_001ecc10\n"
        "xorl %edx, %edx\n"
        ".Lf1ecb40_001ecbfc:\n"
        "movl 0x48(%edi), %eax\n" /* line 1050 | state */
        "movl $0, (%eax, %edx, 4)\n"
        "addl $1, %edx\n" /* line 1049 */
        "movl 0xc(%edi), %ebx\n" /* state, len */
        "cmpl %ebx, %edx\n" /* len */
        "jl .Lf1ecb40_001ecbfc\n"
        ".Lf1ecb40_001ecc10:\n"
        "movl $4, %ecx\n" /* line 1052 */
        "movl %ecx, %eax\n"
        "subl -0x38(%ebp), %eax\n"
        "andl $3, %eax\n"
        "addl -0x38(%ebp), %eax\n"
        "movl 0x14(%edi), %edx\n" /* state */
        "leal (%eax, %edx, 4), %edx\n"
        "movl %eax, -0x68(%ebp)\n" /* low_pi_gain */
        "movl %ecx, %eax\n" /* line 1053 */
        "subl %edx, %eax\n"
        "andl $3, %eax\n"
        "addl %eax, %edx\n"
        "leal (, %ebx, 4), %eax\n"
        "addl %eax, %edx\n"
        "movl %edx, %ebx\n" /* len */
        "subl %eax, %ebx\n" /* len */
        "movl %ebx, -0x64(%ebp)\n" /* len, low_exc */
        "subl %edx, %ecx\n" /* line 1054 */
        "andl $3, %ecx\n"
        "addl %ecx, %edx\n"
        "leal (%eax, %edx), %edx\n"
        "movl %edx, -0x34(%ebp)\n"
        "subl %eax, %edx\n"
        "movl %edx, -0x60(%ebp)\n" /* low_innov */
        "movl -0x68(%ebp), %esi\n" /* line 1055 | low_pi_gain, x1 */
        "movl %esi, 8(%esp)\n" /* x1 */
        "movl $0x64, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_decoder_ctl\n"
        "movl %ebx, 8(%esp)\n" /* line 1056 | len */
        "movl $0x65, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_decoder_ctl\n"
        "movl -0x60(%ebp), %eax\n" /* line 1057 | low_innov */
        "movl %eax, 8(%esp)\n"
        "movl $0x66, 4(%esp)\n"
        "movl 4(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll speex_decoder_ctl\n"
        "movl 0x6c(%edi), %edx\n" /* line 1059 | state */
        "movl 0x68(%edi), %eax\n" /* state */
        "movl (%eax, %edx, 4), %edx\n"
        "movl 0xc(%ebp), %ebx\n" /* bits, len */
        "movl %ebx, 8(%esp)\n" /* len */
        "movl 0x18(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x4c(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll *0x14(%edx)\n"
        "movl 0x1c(%edi), %esi\n" /* line 1061 | state, x1 */
        "testl %esi, %esi\n" /* x1 */
        "je .Lf1ecb40_001eccd1\n"
        "movl 0x18(%edi), %ebx\n" /* line 1063 | state, len */
        "testl %ebx, %ebx\n" /* len */
        "jg .Lf1ecb40_001eceb3\n"
        ".Lf1ecb40_001eccd1:\n"
        "movl 0x18(%edi), %esi\n" /* line 1067 | state, x1 */
        "movl %esi, -0x8c(%ebp)\n" /* x1 */
        "shll $2, %esi\n" /* x1 */
        "movl $4, %ecx\n"
        "movl %ecx, %eax\n"
        "subl -0x34(%ebp), %eax\n"
        "andl $3, %eax\n"
        "addl -0x34(%ebp), %eax\n"
        "leal 4(%eax, %esi), %eax\n"
        "movl %esi, %ebx\n" /* x1, len */
        "negl %ebx\n" /* len */
        "leal -4(%eax, %ebx), %edx\n"
        "movl %edx, -0x5c(%ebp)\n" /* awk1 */
        "movl %ecx, %edx\n" /* line 1068 */
        "subl %eax, %edx\n"
        "andl $3, %edx\n"
        "addl %edx, %eax\n"
        "leal 4(%esi, %eax), %eax\n" /* x1 */
        "leal -4(%ebx, %eax), %edx\n" /* len */
        "movl %edx, -0x58(%ebp)\n" /* awk2 */
        "subl %eax, %ecx\n" /* line 1069 */
        "andl $3, %ecx\n"
        "addl %ecx, %eax\n"
        "leal 4(%esi, %eax), %eax\n" /* x1 */
        "movl %eax, -0x30(%ebp)\n"
        "leal -4(%ebx, %eax), %ebx\n" /* len */
        "movl %ebx, -0x54(%ebp)\n" /* len, awk3 */
        "movl 0x14(%edi), %edx\n" /* line 1071 | state */
        "testl %edx, %edx\n"
        "jg .Lf1ecb40_001ed015\n"
        ".Lf1ecb40_001ecd30:\n"
        "movl %eax, 0x18(%esp)\n" /* line 1202 */
        "movl 0x40(%edi), %eax\n" /* state */
        "movl %eax, 0x14(%esp)\n"
        "movl $0x40, 0x10(%esp)\n"
        "movl 8(%edi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x38(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl $h0, 4(%esp)\n"
        "movl 0x2c(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll fir_mem_up\n"
        "movl -0x30(%ebp), %edx\n" /* line 1203 */
        "movl %edx, 0x18(%esp)\n"
        "movl 0x44(%edi), %eax\n" /* state */
        "movl %eax, 0x14(%esp)\n"
        "movl $0x40, 0x10(%esp)\n"
        "movl 8(%edi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x3c(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl $h1, 4(%esp)\n"
        "movl 0x34(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll fir_mem_up\n"
        "movl 8(%edi), %ecx\n" /* line 1205 | state, len */
        "movl 0x3c(%edi), %esi\n" /* state, x1 */
        "movl 0x38(%edi), %ebx\n" /* state, k2 */
        "movl %ebx, -0xa0(%ebp)\n" /* k2, x0 */
        /* { scope 2: scale */
        /* { scope 3 */
        "testl %ecx, %ecx\n" /* line 207 */
        "jle .Lf1ecb40_001ece08\n"
        "xorl %edx, %edx\n"
        "movss 0x2edaa8, %xmm3\n" /* -32767.0f */
        "movss 0x2edaa4, %xmm2\n" /* 32767.0f */
        ".Lf1ecb40_001ecdc0:\n"
        "leal (, %edx, 4), %eax\n" /* line 952 */
        /* { scope 4 */
        "movl -0xa0(%ebp), %ebx\n" /* line 213 | x0 */
        "movss (%ebx, %eax), %xmm1\n"
        "subss (%esi, %eax), %xmm1\n"
        "addss %xmm1, %xmm1\n"
        "ucomiss %xmm2, %xmm1\n" /* line 215 */
        "ja .Lf1ecb40_001ece48\n"
        "movss 0x2edaa8, %xmm0\n" /* line 218 | -32767.0f */
        "movaps %xmm1, %xmm4\n"
        "cmpnltss %xmm3, %xmm1\n"
        "andps %xmm1, %xmm4\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm4, %xmm1\n"
        "movl 0x10(%ebp), %ebx\n" /* vout */
        "movss %xmm1, (%ebx, %eax)\n"
        /* } scope */
        "addl $1, %edx\n" /* line 207 */
        "cmpl %edx, %ecx\n"
        "jne .Lf1ecb40_001ecdc0\n"
        /* } scope */
        /* } scope */
        ".Lf1ecb40_001ece08:\n"
        "movl 0x18(%edi), %esi\n" /* line 1207 | state, x1 */
        "testl %esi, %esi\n" /* x1 */
        "jle .Lf1ecb40_001ece2c\n"
        "xorl %ebx, %ebx\n" /* k2 */
        ".Lf1ecb40_001ece11:\n"
        "leal (, %ebx, 4), %edx\n"
        "movl 0x50(%edi), %ecx\n" /* line 1208 | state */
        "movl 0x4c(%edi), %eax\n" /* state */
        "movl (%eax, %edx), %eax\n"
        "movl %eax, (%ecx, %edx)\n"
        "addl $1, %ebx\n" /* line 1207 | k2 */
        "cmpl 0x18(%edi), %ebx\n" /* state, k2 */
        "jl .Lf1ecb40_001ece11\n"
        ".Lf1ecb40_001ece2c:\n"
        "movl $0, 0x1c(%edi)\n" /* line 1210 | state */
        "movl $0, -0x6c(%ebp)\n" /* ret */
        /* } scope */
        ".Lf1ecb40_001ece3a:\n"
        "movl -0x6c(%ebp), %eax\n" /* line 1213 | ret */
        "addl $0xbc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: x0, exc, sp, filter_ratio, ... */
        /* { scope 2: scale */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf1ecb40_001ece48:\n"
        "movl 0x10(%ebp), %ebx\n" /* line 216 | vout */
        "movl $0x46fffe00, (%ebx, %eax)\n"
        /* } scope */
        "addl $1, %edx\n" /* line 207 */
        "cmpl %edx, %ecx\n"
        "jne .Lf1ecb40_001ecdc0\n"
        "jmp .Lf1ecb40_001ece08\n"
        /* } scope */
        /* } scope */
        ".Lf1ecb40_001ece5f:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 1002 | bits, i */
        "movl %ebx, (%esp)\n" /* i */
        "calll speex_bits_remaining\n"
        "testl %eax, %eax\n"
        "jle .Lf1ecb40_001ece7e\n"
        "movl %ebx, (%esp)\n" /* line 1003 | i */
        "calll speex_bits_peek\n"
        "testl %eax, %eax\n" /* line 1006 */
        "jne .Lf1ecb40_001ed58f\n"
        ".Lf1ecb40_001ece7e:\n"
        "movl $0, 0x6c(%edi)\n" /* line 1014 | state */
        "movl 0x6c(%edi), %edx\n" /* state */
        ".Lf1ecb40_001ece88:\n"
        "testl %edx, %edx\n" /* line 1016 */
        "je .Lf1ecb40_001ecbe5\n"
        "movl 0x68(%edi), %eax\n" /* state */
        "movl (%eax, %edx, 4), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1ecb40_001ecbf3\n"
        "movl $0x2b9100, (%esp)\n" /* line 1018 */
        "calll speex_warning\n"
        "movl $0xfffffffe, -0x6c(%ebp)\n" /* ret */
        "jmp .Lf1ecb40_001ece3a\n"
        ".Lf1ecb40_001eceb3:\n"
        "xorl %ebx, %ebx\n" /* line 1063 | len */
        ".Lf1ecb40_001eceb5:\n"
        "leal (, %ebx, 4), %edx\n" /* line 1061 */
        "movl 0x50(%edi), %ecx\n" /* line 1064 | state */
        "movl 0x4c(%edi), %eax\n" /* state */
        "movl (%edx, %eax), %eax\n"
        "movl %eax, (%edx, %ecx)\n"
        "addl $1, %ebx\n" /* line 1063 | len */
        "cmpl %ebx, 0x18(%edi)\n" /* len, state */
        "jg .Lf1ecb40_001eceb5\n"
        "jmp .Lf1ecb40_001eccd1\n"
        ".Lf1ecb40_001eced5:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1026 | dtx */
        "testl %eax, %eax\n"
        "jne .Lf1ecb40_001ed56e\n"
        "movl 0xc(%edi), %ecx\n" /* line 1032 | state */
        "testl %ecx, %ecx\n"
        "jle .Lf1ecb40_001ecefb\n"
        "xorl %edx, %edx\n"
        ".Lf1ecb40_001ecee9:\n"
        "movl 0x48(%edi), %eax\n" /* line 1033 | state */
        "movl $0x26901d7d, (%eax, %edx, 4)\n"
        "addl $1, %edx\n" /* line 1032 */
        "cmpl %edx, 0xc(%edi)\n" /* state */
        "jg .Lf1ecb40_001ecee9\n"
        ".Lf1ecb40_001ecefb:\n"
        "movl $1, 0x1c(%edi)\n" /* line 1035 | state */
        "movl 0x5c(%edi), %eax\n" /* line 1038 | state */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x18(%edi), %eax\n" /* state */
        "movl %eax, 0x10(%esp)\n"
        "movl 0xc(%edi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x34(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x58(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x48(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll iir_mem2\n"
        "movl -0x38(%ebp), %eax\n" /* line 1040 */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x40(%edi), %eax\n" /* state */
        "movl %eax, 0x14(%esp)\n"
        "movl $0x40, 0x10(%esp)\n"
        "movl 8(%edi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x38(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl $h0, 4(%esp)\n"
        "movl 0x2c(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll fir_mem_up\n"
        "movl -0x38(%ebp), %edx\n" /* line 1041 */
        "movl %edx, 0x18(%esp)\n"
        "movl 0x44(%edi), %eax\n" /* state */
        "movl %eax, 0x14(%esp)\n"
        "movl $0x40, 0x10(%esp)\n"
        "movl 8(%edi), %eax\n" /* state */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x3c(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl $h1, 4(%esp)\n"
        "movl 0x34(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll fir_mem_up\n"
        "movl 8(%edi), %ebx\n" /* line 1043 | state, len */
        "movl 0x3c(%edi), %esi\n" /* state, x1 */
        "movl 0x38(%edi), %eax\n" /* state, x0 */
        /* { scope 2: scale */
        /* { scope 3 */
        "testl %ebx, %ebx\n" /* line 207 */
        "jle .Lf1ecb40_001ed539\n"
        "xorl %ecx, %ecx\n"
        "movss 0x2edaa8, %xmm3\n" /* -32767.0f */
        "movss 0x2edaa4, %xmm2\n" /* 32767.0f */
        "jmp .Lf1ecb40_001ecfef\n"
        /* { scope 4 */
        ".Lf1ecb40_001ecfc3:\n"
        "movss 0x2edaa8, %xmm0\n" /* line 218 | -32767.0f */
        "movaps %xmm1, %xmm4\n"
        "cmpnltss %xmm3, %xmm1\n"
        "andps %xmm1, %xmm4\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm4, %xmm1\n"
        "movl 0x10(%ebp), %edi\n" /* vout */
        "movss %xmm1, (%edi, %edx)\n"
        /* } scope */
        ".Lf1ecb40_001ecfe4:\n"
        "addl $1, %ecx\n" /* line 207 */
        "cmpl %ecx, %ebx\n"
        "je .Lf1ecb40_001ed539\n"
        ".Lf1ecb40_001ecfef:\n"
        "leal (, %ecx, 4), %edx\n" /* line 952 */
        /* { scope 4 */
        "movss (%eax, %edx), %xmm1\n" /* line 213 */
        "subss (%esi, %edx), %xmm1\n"
        "addss %xmm1, %xmm1\n"
        "ucomiss %xmm2, %xmm1\n" /* line 215 */
        "jbe .Lf1ecb40_001ecfc3\n"
        "movl 0x10(%ebp), %edi\n" /* line 216 | vout */
        "movl $0x46fffe00, (%edi, %edx)\n"
        "jmp .Lf1ecb40_001ecfe4\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1ecb40_001ed015:\n"
        "movl $0, -0x70(%ebp)\n" /* line 1071 | sub */
        /* { scope 2: scale */
        ".Lf1ecb40_001ed01c:\n"
        "movl -0x70(%ebp), %eax\n" /* line 1080 | sub */
        "imull 0x10(%edi), %eax\n" /* state */
        "shll $2, %eax\n"
        "movl %eax, -0x74(%ebp)\n"
        "addl 0x34(%edi), %eax\n" /* state */
        "movl %eax, -0x48(%ebp)\n" /* sp */
        "movl -0x74(%ebp), %esi\n" /* line 1081 | x1 */
        "addl 0x48(%edi), %esi\n" /* state, x1 */
        "movl %esi, -0x4c(%ebp)\n" /* x1, exc */
        "movl %edx, 0x14(%esp)\n" /* line 1084 */
        "movl -0x70(%ebp), %eax\n" /* sub */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x8c(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl 0x54(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x4c(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x50(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll lsp_interpolate\n"
        "movl $0x3d4ccccd, 8(%esp)\n" /* line 1086 */
        "movl 0x18(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x54(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll lsp_enforce_margin\n"
        "movl -0x30(%ebp), %ebx\n" /* line 1089 | len */
        "movl %ebx, 0xc(%esp)\n" /* len */
        "movl 0x18(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl 0x58(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x54(%edi), %eax\n" /* state */
        "movl %eax, (%esp)\n"
        "calll lsp_to_lpc\n"
        "movl 0x24(%edi), %ebx\n" /* line 1092 | state, len */
        "testl %ebx, %ebx\n" /* len */
        "jne .Lf1ecb40_001ed438\n"
        /* { scope 3 */
        ".Lf1ecb40_001ed0ab:\n"
        "movl -0x70(%ebp), %ebx\n" /* line 1100 | sub, k2 */
        "shll $2, %ebx\n" /* k2 */
        /* } scope */
        "movl 0x60(%edi), %eax\n" /* line 1108 | state */
        "movl $0x3f800000, %edx\n"
        "movl %edx, (%eax, %ebx)\n"
        "movl 0x18(%edi), %ecx\n" /* line 1110 | state */
        "testl %ecx, %ecx\n"
        "jg .Lf1ecb40_001ed36f\n"
        "movsd 0x307c10, %xmm2\n" /* 1.0 */
        ".Lf1ecb40_001ed0cf:\n"
        "movl -0x68(%ebp), %esi\n" /* line 1120 | low_pi_gain, k3 */
        "cvtss2sd (%esi, %ebx), %xmm0\n" /* k3 */
        "movsd 0x307e10, %xmm1\n" /* 0.01 */
        "addsd %xmm1, %xmm0\n"
        "addsd %xmm1, %xmm2\n"
        "divsd %xmm2, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n" /* filter_ratio */
        "movl 0x10(%edi), %edx\n" /* line 1123 | state */
        "testl %edx, %edx\n"
        "jle .Lf1ecb40_001ed10f\n"
        "xorl %eax, %eax\n"
        ".Lf1ecb40_001ed0fd:\n"
        "movl -0x4c(%ebp), %edx\n" /* line 1124 | exc */
        "movl $0, (%edx, %eax, 4)\n"
        "addl $1, %eax\n" /* line 1123 */
        "cmpl %eax, 0x10(%edi)\n" /* state */
        "jg .Lf1ecb40_001ed0fd\n"
        ".Lf1ecb40_001ed10f:\n"
        "movl 0x6c(%edi), %eax\n" /* line 1125 | state */
        "movl 0x68(%edi), %edx\n" /* state */
        "movl (%edx, %eax, 4), %eax\n"
        "movl 0x28(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1ecb40_001ed4bb\n"
        /* { scope 3 */
        "movl $4, 4(%esp)\n" /* line 1145 */
        "movl 0xc(%ebp), %edx\n" /* bits */
        "movl %edx, (%esp)\n"
        "calll speex_bits_unpack_unsigned\n"
        "movl %eax, %ebx\n" /* k2 */
        "movl 0x10(%edi), %eax\n" /* line 1147 | state */
        "movl %eax, 4(%esp)\n"
        "movl -0x64(%ebp), %eax\n" /* low_exc */
        "addl -0x74(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll compute_rms\n"
        "fstps -0x40(%ebp)\n" /* el */
        "cvtsi2sdl %ebx, %xmm0\n" /* line 1152 | k2 */
        "mulsd 0x307e48, %xmm0\n" /* 0.27027027027027023 */
        "subsd 0x307e30, %xmm0\n" /* 0.15556 */
        "movsd %xmm0, (%esp)\n"
        "calll exp\n"
        "fstpl -0x88(%ebp)\n"
        "cvtsd2ss -0x88(%ebp), %xmm0\n"
        "movl 0x10(%edi), %ecx\n" /* line 1155 | state */
        "cmpl $0x50, %ecx\n"
        "je .Lf1ecb40_001ed4a6\n"
        ".Lf1ecb40_001ed188:\n"
        "divss -0x44(%ebp), %xmm0\n" /* line 1158 | filter_ratio */
        "movss %xmm0, -0x3c(%ebp)\n" /* scale */
        "movss -0x40(%ebp), %xmm0\n" /* el */
        "addss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movss -0x3c(%ebp), %xmm4\n" /* scale */
        "mulss %xmm0, %xmm4\n"
        "movss %xmm4, -0x3c(%ebp)\n" /* scale */
        "movl 0x6c(%edi), %edx\n" /* line 1161 | state */
        "movl 0x68(%edi), %eax\n" /* state */
        "movl (%eax, %edx, 4), %edx\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0xc(%ebp), %ebx\n" /* bits, k2 */
        "movl %ebx, 0xc(%esp)\n" /* k2 */
        "movl %ecx, 8(%esp)\n"
        "movl 0x2c(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x4c(%ebp), %esi\n" /* exc, k3 */
        "movl %esi, (%esp)\n" /* k3 */
        "calll *0x28(%edx)\n"
        "movl 0x10(%edi), %eax\n" /* line 1163 | state */
        "movl %eax, 0xc(%esp)\n"
        "movss -0x3c(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* k3 */
        "movl %esi, (%esp)\n" /* k3 */
        "calll signal_mul\n"
        "movl 0x6c(%edi), %edx\n" /* line 1165 | state */
        "movl 0x68(%edi), %ebx\n" /* state, k2 */
        "movl (%ebx, %edx, 4), %eax\n" /* k2 */
        "movl 0xc(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1ecb40_001ed2d1\n"
        /* { scope 4 */
        "movl -0x30(%ebp), %eax\n" /* line 1168 */
        "negl %eax\n"
        "andl $3, %eax\n"
        "addl -0x30(%ebp), %eax\n"
        "movl 0x10(%edi), %ecx\n" /* state */
        "leal (%eax, %ecx, 4), %esi\n" /* innov2 */
        "movl %esi, -0x2c(%ebp)\n" /* innov2 */
        "movl %eax, %esi\n" /* innov2 */
        "testl %ecx, %ecx\n" /* line 1169 */
        "jle .Lf1ecb40_001ed23d\n"
        "xorl %eax, %eax\n"
        ".Lf1ecb40_001ed226:\n"
        "movl $0, (%esi, %eax, 4)\n" /* line 1170 | innov2 */
        "addl $1, %eax\n" /* line 1169 */
        "movl 0x10(%edi), %ecx\n" /* state */
        "cmpl %ecx, %eax\n"
        "jl .Lf1ecb40_001ed226\n"
        "movl 0x6c(%edi), %edx\n" /* state */
        "movl 0x68(%edi), %ebx\n" /* state, k2 */
        ".Lf1ecb40_001ed23d:\n"
        "movl (%ebx, %edx, 4), %edx\n" /* line 1172 | k2 */
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0xc(%ebp), %ebx\n" /* bits, k2 */
        "movl %ebx, 0xc(%esp)\n" /* k2 */
        "movl %ecx, 8(%esp)\n"
        "movl 0x2c(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* innov2 */
        "calll *0x28(%edx)\n"
        "movl 0x10(%edi), %eax\n" /* line 1173 | state */
        "testl %eax, %eax\n"
        "jle .Lf1ecb40_001ed2d1\n"
        "cvtss2sd -0x3c(%ebp), %xmm1\n" /* scale */
        "mulsd 0x307e58, %xmm1\n" /* 0.4 */
        "movl $1, %ecx\n"
        "leal 4(%esi), %edx\n" /* innov2 */
        ".Lf1ecb40_001ed27b:\n"
        "cvtss2sd -4(%edx), %xmm0\n" /* line 1174 */
        "mulsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -4(%edx)\n"
        "movl %ecx, %eax\n"
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "cmpl %eax, 0x10(%edi)\n" /* line 1173 | state */
        "jg .Lf1ecb40_001ed27b\n"
        "movl 0x10(%edi), %eax\n" /* line 1175 | state */
        "testl %eax, %eax\n"
        "jle .Lf1ecb40_001ed54e\n"
        "movl $1, %ecx\n"
        ".Lf1ecb40_001ed2aa:\n"
        "leal (, %ecx, 4), %eax\n" /* line 952 */
        "movl -0x4c(%ebp), %ebx\n" /* exc */
        "leal (%eax, %ebx), %edx\n"
        "movss -4(%edx), %xmm0\n" /* line 1176 */
        "addss -4(%eax, %esi), %xmm0\n"
        "movss %xmm0, -4(%edx)\n"
        "movl %ecx, %eax\n"
        "addl $1, %ecx\n"
        "cmpl %eax, 0x10(%edi)\n" /* line 1175 | state */
        "jg .Lf1ecb40_001ed2aa\n"
        /* } scope */
        /* } scope */
        ".Lf1ecb40_001ed2d1:\n"
        "movl 0x10(%edi), %ebx\n" /* line 1182 | state, k2 */
        "testl %ebx, %ebx\n" /* k2 */
        "jle .Lf1ecb40_001ed2fe\n"
        "movl $1, %ecx\n"
        ".Lf1ecb40_001ed2dd:\n"
        "leal (, %ecx, 4), %eax\n" /* line 952 */
        "movl -0x4c(%ebp), %esi\n" /* line 1183 | exc, innov2 */
        "movl -4(%esi, %eax), %edx\n" /* innov2 */
        "movl -0x48(%ebp), %ebx\n" /* sp, k2 */
        "movl %edx, -4(%ebx, %eax)\n" /* k2 */
        "movl %ecx, %eax\n"
        "movl 0x10(%edi), %ebx\n" /* line 1182 | state, k2 */
        "addl $1, %ecx\n"
        "cmpl %ebx, %eax\n" /* k2 */
        "jl .Lf1ecb40_001ed2dd\n"
        ".Lf1ecb40_001ed2fe:\n"
        "movl 0x24(%edi), %eax\n" /* line 1184 | state */
        "testl %eax, %eax\n"
        "jne .Lf1ecb40_001ed3bf\n"
        "movl 0x18(%edi), %edx\n" /* line 1193 | state */
        "testl %edx, %edx\n"
        "jle .Lf1ecb40_001ed32c\n"
        "xorl %ecx, %ecx\n"
        ".Lf1ecb40_001ed312:\n"
        "leal (%ecx, %edx), %edx\n" /* line 1194 */
        "movl 0x5c(%edi), %eax\n" /* state */
        "movl $0, (%eax, %edx, 4)\n"
        "addl $1, %ecx\n" /* line 1193 */
        "movl 0x18(%edi), %edx\n" /* state */
        "cmpl %edx, %ecx\n"
        "jl .Lf1ecb40_001ed312\n"
        "movl 0x10(%edi), %ebx\n" /* state, k2 */
        ".Lf1ecb40_001ed32c:\n"
        "movl 0x5c(%edi), %eax\n" /* line 1196 | state */
        "movl %eax, 0x14(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* k2 */
        "movl -0x48(%ebp), %esi\n" /* sp, innov2 */
        "movl %esi, 8(%esp)\n" /* innov2 */
        "movl 0x58(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* innov2 */
        "calll iir_mem2\n"
        /* } scope */
        "addl $1, -0x70(%ebp)\n" /* line 1071 | sub */
        "movl 0x14(%edi), %edx\n" /* state */
        "cmpl %edx, -0x70(%ebp)\n" /* sub */
        "jge .Lf1ecb40_001ed430\n"
        ".Lf1ecb40_001ed361:\n"
        "movl 0x18(%edi), %ebx\n" /* state, len */
        "movl %ebx, -0x8c(%ebp)\n" /* len */
        "jmp .Lf1ecb40_001ed01c\n"
        /* { scope 2: scale */
        ".Lf1ecb40_001ed36f:\n"
        "xorl %ecx, %ecx\n" /* line 1110 */
        "movl %edx, -0x9c(%ebp)\n"
        "movss -0x9c(%ebp), %xmm3\n"
        "xorl %edx, %edx\n"
        ".Lf1ecb40_001ed381:\n"
        "movl %edx, %eax\n" /* line 1112 */
        "addl 0x58(%edi), %eax\n" /* state */
        "movss 4(%eax), %xmm0\n"
        "movss (%eax), %xmm2\n"
        "movaps %xmm0, %xmm1\n"
        "subss %xmm2, %xmm1\n"
        "addss %xmm1, %xmm3\n"
        "movl %ebx, %eax\n" /* line 1113 | k2 */
        "addl 0x60(%edi), %eax\n" /* state */
        "addss %xmm2, %xmm0\n"
        "addss (%eax), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "addl $2, %ecx\n" /* line 1110 */
        "addl $8, %edx\n"
        "cmpl %ecx, 0x18(%edi)\n" /* state */
        "jg .Lf1ecb40_001ed381\n"
        "cvtss2sd %xmm3, %xmm2\n"
        "jmp .Lf1ecb40_001ed0cf\n"
        ".Lf1ecb40_001ed3bf:\n"
        "movl 0x18(%edi), %edx\n" /* line 1188 | state */
        "movl 0x5c(%edi), %eax\n" /* state */
        "leal (%eax, %edx, 4), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl %edx, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n" /* k2 */
        "movl -0x48(%ebp), %esi\n" /* sp, innov2 */
        "movl %esi, 0xc(%esp)\n" /* innov2 */
        "movl -0x5c(%ebp), %eax\n" /* awk1 */
        "movl %eax, 8(%esp)\n"
        "movl -0x58(%ebp), %edx\n" /* awk2 */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* innov2 */
        "calll filter_mem2\n"
        "movl 0x5c(%edi), %eax\n" /* line 1190 | state */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x18(%edi), %eax\n" /* state */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edi), %eax\n" /* state */
        "movl %eax, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n" /* innov2 */
        "movl 0x58(%edi), %eax\n" /* state */
        "movl %eax, 8(%esp)\n"
        "movl -0x54(%ebp), %ebx\n" /* awk3, k2 */
        "movl %ebx, 4(%esp)\n" /* k2 */
        "movl %esi, (%esp)\n" /* innov2 */
        "calll filter_mem2\n"
        /* } scope */
        "addl $1, -0x70(%ebp)\n" /* line 1071 | sub */
        "movl 0x14(%edi), %edx\n" /* state */
        "cmpl %edx, -0x70(%ebp)\n" /* sub */
        "jl .Lf1ecb40_001ed361\n"
        ".Lf1ecb40_001ed430:\n"
        "movl -0x30(%ebp), %eax\n"
        "jmp .Lf1ecb40_001ecd30\n"
        /* { scope 2: scale */
        /* { scope 3 */
        ".Lf1ecb40_001ed438:\n"
        "movl 0x6c(%edi), %edx\n" /* line 1095 | state */
        "movl 0x68(%edi), %eax\n" /* state */
        "movl (%eax, %edx, 4), %edx\n"
        "movl 0x34(%edx), %ebx\n" /* line 1096 | k2 */
        "movl 0x38(%edx), %esi\n" /* line 1097 | k3 */
        "movl 0x18(%edi), %eax\n" /* line 1098 | state */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x5c(%ebp), %eax\n" /* awk1 */
        "movl %eax, 8(%esp)\n"
        "movl 0x58(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl 0x30(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll bw_lpc\n"
        "movl 0x18(%edi), %eax\n" /* line 1099 | state */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x58(%ebp), %edx\n" /* awk2 */
        "movl %edx, 8(%esp)\n"
        "movl 0x58(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* k2 */
        "calll bw_lpc\n"
        "movl 0x18(%edi), %eax\n" /* line 1100 | state */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x54(%ebp), %ebx\n" /* awk3, k2 */
        "movl %ebx, 8(%esp)\n" /* k2 */
        "movl 0x58(%edi), %eax\n" /* state */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* k3 */
        "calll bw_lpc\n"
        "jmp .Lf1ecb40_001ed0ab\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1ecb40_001ed4a6:\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 1156 */
        "mulsd 0x307e50, %xmm0\n" /* 1.4142 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "jmp .Lf1ecb40_001ed188\n"
        /* } scope */
        ".Lf1ecb40_001ed4bb:\n"
        "movl $5, 4(%esp)\n" /* line 1130 */
        "movl 0xc(%ebp), %ebx\n" /* bits, k2 */
        "movl %ebx, (%esp)\n" /* k2 */
        "calll speex_bits_unpack_unsigned\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 1131 */
        "subss 0x2ed6b4, %xmm0\n" /* 10.0f */
        "cvtss2sd %xmm0, %xmm0\n"
        "mulsd 0x307e70, %xmm0\n" /* 0.125 */
        "movsd %xmm0, (%esp)\n"
        "calll exp\n"
        "fstpl -0x80(%ebp)\n"
        "cvtsd2ss -0x80(%ebp), %xmm1\n"
        "divss -0x44(%ebp), %xmm1\n" /* line 1136 | filter_ratio */
        "movl 0x10(%edi), %eax\n" /* line 1139 | state */
        "testl %eax, %eax\n"
        "jle .Lf1ecb40_001ed54e\n"
        "movl -0x60(%ebp), %edx\n" /* low_innov */
        "addl -0x74(%ebp), %edx\n"
        "movl $1, %ecx\n"
        ".Lf1ecb40_001ed50f:\n"
        "movaps %xmm1, %xmm0\n" /* line 1140 */
        "movl -0x50(%ebp), %esi\n" /* mode, k3 */
        "mulss 0x24(%esi), %xmm0\n" /* k3 */
        "mulss (%edx), %xmm0\n"
        "movl -0x4c(%ebp), %eax\n" /* exc */
        "movss %xmm0, -4(%eax, %ecx, 4)\n"
        "movl %ecx, %eax\n"
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "cmpl 0x10(%edi), %eax\n" /* line 1139 | state */
        "jl .Lf1ecb40_001ed50f\n"
        "jmp .Lf1ecb40_001ed2d1\n"
        /* } scope */
        ".Lf1ecb40_001ed539:\n"
        "movl $0, -0x6c(%ebp)\n" /* line 1212 | ret */
        /* } scope */
        "movl -0x6c(%ebp), %eax\n" /* line 1213 | ret */
        "addl $0xbc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: x0, exc, sp, filter_ratio, ... */
        /* { scope 2: scale */
        ".Lf1ecb40_001ed54e:\n"
        "movl 0x10(%edi), %ebx\n" /* line 1182 | state, k2 */
        "jmp .Lf1ecb40_001ed2fe\n"
        /* } scope */
        ".Lf1ecb40_001ed556:\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 994 | dtx */
        "movl -0x38(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* vout */
        "movl %edi, %eax\n" /* state */
        "calll sb_decode_lost\n"
        "jmp .Lf1ecb40_001ece3a\n"
        ".Lf1ecb40_001ed56e:\n"
        "movl -0x38(%ebp), %esi\n" /* line 1028 | low */
        "movl %esi, (%esp)\n" /* low */
        "movl $1, %ecx\n"
        "movl 0x10(%ebp), %edx\n" /* vout */
        "movl %edi, %eax\n" /* state */
        "calll sb_decode_lost\n"
        "movl $0, -0x6c(%ebp)\n" /* ret */
        "jmp .Lf1ecb40_001ece3a\n"
        ".Lf1ecb40_001ed58f:\n"
        "movl $1, 4(%esp)\n" /* line 1009 */
        "movl %ebx, (%esp)\n" /* i */
        "calll speex_bits_unpack_unsigned\n"
        "movl $3, 4(%esp)\n" /* line 1010 */
        "movl %ebx, (%esp)\n" /* i */
        "calll speex_bits_unpack_unsigned\n"
        "movl %eax, %edx\n"
        "movl %eax, 0x6c(%edi)\n" /* state */
        "jmp .Lf1ecb40_001ece88\n"
    );
}

