/* ASM dump from: vbr.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/speex/vbr.c */

#include "common_types.h"
#include "imports.h"

extern const float vbr_nb_thresh[9][11]; /* 0x0 */
extern const float vbr_hb_thresh[5][11]; /* 0x0 */
extern const float vbr_uhb_thresh[2][11]; /* 0x0 */

void vbr_init(VBRState *vbr);
float vbr_analysis(VBRState *vbr, spx_word16_t *sig, int len, int pitch, float pitch_coef);
void vbr_destroy(VBRState *vbr);

/* line 75 */
__attribute__((naked))
void vbr_init(VBRState *vbr)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 75 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %ebx\n" /* vbr */
        "xorl %eax, %eax\n" /* line 79 */
        "movl %eax, 4(%ebx)\n" /* vbr */
        "movl $0x3f800000, 8(%ebx)\n" /* line 80 | vbr */
        "movl %eax, 0x20(%ebx)\n" /* line 81 | vbr */
        "movl $0x3dcccccd, (%ebx)\n" /* line 82 | vbr */
        "movl %eax, 0x28(%ebx)\n" /* line 83 | vbr */
        "movl %eax, 0x24(%ebx)\n" /* line 84 | vbr */
        "movl %eax, 0x2c(%ebx)\n" /* line 85 | vbr */
        "movl $0x33333333, 8(%esp)\n" /* line 87 */
        "movl $0x3fd33333, 0xc(%esp)\n"
        "movl $0, (%esp)\n"
        "movl $0x40b77000, 4(%esp)\n"
        "calll pow\n"
        "fstpl -0x10(%ebp)\n"
        "movsd -0x10(%ebp), %xmm0\n"
        "mulsd 0x307e08, %xmm0\n" /* 0.05 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, 0x34(%ebx)\n" /* vbr */
        "movss 0x2ed72c, %xmm1\n" /* line 88 | 0.05000000074505806f */
        "movss %xmm1, 0x38(%ebx)\n" /* vbr */
        "divss %xmm1, %xmm0\n" /* line 89 */
        "movss %xmm0, 0x30(%ebx)\n" /* vbr */
        "movl $0, 0x3c(%ebx)\n" /* line 90 | vbr */
        "movl $5, %esi\n"
        ".Lf1f4748_001f47d0:\n"
        "movl $0x45bb8000, (%esp)\n" /* line 94 */
        "calll logf\n"
        "fstps 0xc(%ebx)\n" /* vbr */
        "addl $4, %ebx\n" /* vbr */
        "subl $1, %esi\n" /* line 93 */
        "jne .Lf1f4748_001f47d0\n"
        "addl $0x20, %esp\n" /* line 95 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 123 */
__attribute__((naked))
float vbr_analysis(VBRState *vbr, spx_word16_t *sig, int len, int pitch, float pitch_coef)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 123 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xc0, %esp\n"
        "movl 8(%ebp), %ebx\n" /* vbr */
        "movl 0xc(%ebp), %edx\n" /* sig */
        "movl 0x10(%ebp), %esi\n" /* len */
        /* { scope 1: short_diff */
        "movl %esi, %ecx\n" /* line 134 | len */
        "sarl $1, %ecx\n"
        "testl %ecx, %ecx\n"
        "jg .Lf1f47ee_001f4de7\n"
        "movl $0, -0x24(%ebp)\n" /* ener1 */
        ".Lf1f47ee_001f4815:\n"
        "cmpl %esi, %ecx\n" /* line 137 | len */
        "jl .Lf1f47ee_001f4db6\n"
        "movl $0, -0x20(%ebp)\n" /* ener2 */
        "movss -0x20(%ebp), %xmm0\n" /* ener2 */
        ".Lf1f47ee_001f4829:\n"
        "addss -0x24(%ebp), %xmm0\n" /* line 139 | ener1 */
        "movss %xmm0, -0x28(%ebp)\n" /* ener */
        "addss 0x2edab4, %xmm0\n" /* line 141 | 6000.0f */
        "movss %xmm0, (%esp)\n"
        "calll logf\n"
        "fstps -0x1c(%ebp)\n" /* log_energy */
        "movl %ebx, %eax\n" /* vbr */
        "pxor %xmm1, %xmm1\n"
        "xorl %edx, %edx\n"
        ".Lf1f47ee_001f4850:\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 143 | log_energy */
        "subss 0xc(%eax), %xmm0\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addl $1, %edx\n" /* line 142 */
        "addl $4, %eax\n"
        "cmpl $5, %edx\n"
        "jne .Lf1f47ee_001f4850\n"
        "movaps %xmm1, %xmm4\n" /* line 144 */
        "divss 0x2ed93c, %xmm4\n" /* 150.0f */
        "movss 0x2ed5d0, %xmm1\n" /* line 145 | 1.0f */
        "minss %xmm4, %xmm1\n"
        "movaps %xmm1, %xmm4\n"
        "cvtss2sd 0x18(%ebp), %xmm2\n" /* line 148 | pitch_coef */
        "movsd %xmm2, -0x40(%ebp)\n"
        "subsd 0x307e58, %xmm2\n" /* 0.4 */
        "movsd %xmm2, -0x38(%ebp)\n"
        "movapd %xmm2, %xmm0\n"
        "mulsd 0x307db0, %xmm0\n" /* 3.0 */
        "movapd %xmm2, %xmm1\n"
        "andpd 0x306a90, %xmm1\n"
        "mulsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x18(%ebp)\n" /* voicing */
        "movss (%ebx), %xmm1\n" /* line 149 | vbr */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "subss %xmm1, %xmm0\n"
        "mulss 4(%ebx), %xmm0\n" /* vbr */
        "mulss -0x28(%ebp), %xmm1\n" /* ener */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 4(%ebx)\n" /* vbr */
        "movss 0x34(%ebx), %xmm0\n" /* line 150 | vbr */
        "divss 0x38(%ebx), %xmm0\n" /* vbr */
        "movss %xmm0, 0x30(%ebx)\n" /* vbr */
        "cvtss2sd -0x28(%ebp), %xmm0\n" /* line 151 | ener */
        "movsd %xmm0, -0x30(%ebp)\n"
        "movl $0x33333333, 8(%esp)\n"
        "movl $0x3fd33333, 0xc(%esp)\n"
        "movsd %xmm0, (%esp)\n"
        "movss %xmm4, -0xa8(%ebp)\n"
        "calll pow\n"
        "fstpl -0x48(%ebp)\n"
        "cvtsd2ss -0x48(%ebp), %xmm6\n"
        "cvtss2sd 0x38(%ebx), %xmm5\n" /* line 152 | vbr */
        "movss -0xa8(%ebp), %xmm4\n"
        "ucomisd 0x307f58, %xmm5\n" /* 0.06 */
        "jae .Lf1f47ee_001f4954\n"
        "jp .Lf1f47ee_001f4954\n"
        "movss -0x28(%ebp), %xmm1\n" /* ener */
        "ucomiss 0x2edab4, %xmm1\n" /* 6000.0f */
        "ja .Lf1f47ee_001f4e99\n"
        ".Lf1f47ee_001f4954:\n"
        "cvtss2sd -0x18(%ebp), %xmm3\n" /* line 155 | voicing */
        "movsd 0x307f50, %xmm2\n" /* 0.3 */
        "ucomisd %xmm3, %xmm2\n"
        "jbe .Lf1f47ee_001f4c5d\n"
        "cvtss2sd %xmm4, %xmm2\n"
        "ucomisd 0x307f60, %xmm2\n" /* 0.2 */
        "jae .Lf1f47ee_001f4c36\n"
        "jp .Lf1f47ee_001f4c36\n"
        "cvtss2sd %xmm6, %xmm1\n"
        "cvtss2sd 0x30(%ebx), %xmm0\n" /* vbr */
        "mulsd 0x307f68, %xmm0\n" /* 1.2 */
        "ucomisd %xmm1, %xmm0\n"
        "jbe .Lf1f47ee_001f4c36\n"
        /* { scope 2 */
        ".Lf1f47ee_001f499e:\n"
        "movl 0x3c(%ebx), %esi\n" /* line 162 | vbr, len */
        "addl $1, %esi\n" /* len */
        "movl %esi, 0x3c(%ebx)\n" /* len, vbr */
        "movss 0x30(%ebx), %xmm4\n" /* line 163 | vbr */
        "movaps %xmm4, %xmm0\n"
        "mulss 0x2ed720, %xmm0\n" /* 3.0f */
        "minss %xmm6, %xmm0\n"
        "cmpl $3, %esi\n" /* line 167 | len */
        "jle .Lf1f47ee_001f4c8b\n"
        "cvtss2sd 0x34(%ebx), %xmm1\n" /* line 169 | vbr */
        "movsd 0x307e00, %xmm3\n" /* 0.95 */
        "mulsd %xmm3, %xmm1\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd 0x307e08, %xmm2\n" /* 0.05 */
        "mulsd %xmm2, %xmm0\n"
        "addsd %xmm0, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm1\n"
        "movss %xmm1, 0x34(%ebx)\n" /* vbr */
        "mulsd %xmm3, %xmm5\n" /* line 170 */
        "addsd %xmm2, %xmm5\n"
        "cvtsd2ss %xmm5, %xmm5\n"
        "movss %xmm5, 0x38(%ebx)\n" /* vbr */
        /* } scope */
        "ucomiss %xmm6, %xmm4\n" /* line 177 */
        "ja .Lf1f47ee_001f4c94\n"
        ".Lf1f47ee_001f4a0c:\n"
        "movss -0x28(%ebp), %xmm0\n" /* ener */
        "ucomiss 0x2ed984, %xmm0\n" /* line 184 | 30000.0f */
        "jae .Lf1f47ee_001f4cb6\n"
        ".Lf1f47ee_001f4a1e:\n"
        "jp .Lf1f47ee_001f4cb6\n"
        "ucomiss 0x2eda18, %xmm0\n" /* line 187 | 10000.0f */
        "jae .Lf1f47ee_001f4e47\n"
        "jp .Lf1f47ee_001f4e47\n"
        "movsd 0x307f70, %xmm1\n" /* 5.600000381469727 */
        "movss -0x28(%ebp), %xmm2\n" /* line 189 | ener */
        "ucomiss 0x2edab8, %xmm2\n" /* 3000.0f */
        "jb .Lf1f47ee_001f4e61\n"
        ".Lf1f47ee_001f4a51:\n"
        "movsd 0x307e60, %xmm3\n" /* 0.6 */
        ".Lf1f47ee_001f4a59:\n"
        "movss -0x28(%ebp), %xmm2\n" /* line 216 | ener */
        "movss %xmm2, 8(%ebx)\n" /* vbr */
        "cvtss2sd 0x28(%ebx), %xmm0\n" /* line 217 | vbr */
        "mulsd %xmm3, %xmm0\n"
        "movsd 0x307e58, %xmm2\n" /* 0.4 */
        "mulsd -0x40(%ebp), %xmm2\n"
        "addsd %xmm2, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, 0x28(%ebx)\n" /* vbr */
        "cvtss2sd %xmm0, %xmm0\n" /* line 218 */
        "subsd 0x307e58, %xmm0\n" /* 0.4 */
        "addsd -0x38(%ebp), %xmm0\n"
        "movsd %xmm0, -0x38(%ebp)\n"
        "mulsd 0x307f30, %xmm0\n" /* 2.2 */
        "addsd %xmm0, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm2\n"
        "movss 0x2c(%ebx), %xmm1\n" /* line 220 | vbr */
        "ucomiss %xmm2, %xmm1\n"
        "jbe .Lf1f47ee_001f4ad6\n"
        "cvtss2sd %xmm2, %xmm0\n" /* line 221 */
        "movsd 0x307ce0, %xmm2\n" /* 0.5 */
        "mulsd %xmm2, %xmm0\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "mulsd %xmm2, %xmm1\n"
        "addsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm2\n"
        ".Lf1f47ee_001f4ad6:\n"
        "ucomiss 0x2ed608, %xmm2\n" /* line 222 | 4.0f */
        "jae .Lf1f47ee_001f4efc\n"
        "jp .Lf1f47ee_001f4efc\n"
        "movss 0x2ed608, %xmm2\n" /* 4.0f */
        "cmpl $2, %esi\n" /* line 235 | len */
        "jg .Lf1f47ee_001f4f21\n"
        ".Lf1f47ee_001f4afa:\n"
        "testl %esi, %esi\n" /* line 238 | len */
        "je .Lf1f47ee_001f4b4e\n"
        "cvtss2sd %xmm2, %xmm2\n"
        "movsd %xmm2, -0x10(%ebp)\n"
        ".Lf1f47ee_001f4b07:\n"
        "cvtsi2sdl %esi, %xmm0\n" /* line 239 | len */
        "addsd 0x307db0, %xmm0\n" /* 3.0 */
        "movsd %xmm0, (%esp)\n"
        "calll log\n"
        "fstpl -0x50(%ebp)\n"
        "movl $0, (%esp)\n"
        "movl $0x40080000, 4(%esp)\n"
        "calll log\n"
        "fstpl -0x58(%ebp)\n"
        "movsd -0x50(%ebp), %xmm0\n"
        "subsd -0x58(%ebp), %xmm0\n"
        "movsd -0x10(%ebp), %xmm1\n"
        "subsd %xmm0, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm2\n"
        ".Lf1f47ee_001f4b4e:\n"
        "pxor %xmm0, %xmm0\n" /* line 240 */
        "maxss %xmm2, %xmm0\n"
        "movaps %xmm0, %xmm2\n"
        "movss -0x28(%ebp), %xmm1\n" /* line 243 | ener */
        "ucomiss 0x2edabc, %xmm1\n" /* 60000.0f */
        "jae .Lf1f47ee_001f4be1\n"
        "jp .Lf1f47ee_001f4be1\n"
        "cmpl $2, %esi\n" /* line 245 | len */
        "jg .Lf1f47ee_001f4ff1\n"
        ".Lf1f47ee_001f4b72:\n"
        "movss -0x28(%ebp), %xmm0\n" /* line 247 | ener */
        "ucomiss 0x2eda18, %xmm0\n" /* 10000.0f */
        "jae .Lf1f47ee_001f4b8b\n"
        "jp .Lf1f47ee_001f4b8b\n"
        "cmpl $2, %esi\n" /* len */
        "jg .Lf1f47ee_001f4f82\n"
        ".Lf1f47ee_001f4b8b:\n"
        "pxor %xmm1, %xmm1\n" /* line 249 */
        "ucomiss %xmm2, %xmm1\n"
        "ja .Lf1f47ee_001f506a\n"
        "cvtss2sd %xmm2, %xmm1\n"
        ".Lf1f47ee_001f4b9c:\n"
        "movsd -0x30(%ebp), %xmm2\n" /* line 251 */
        "divsd 0x307fa0, %xmm2\n" /* 60000.0 */
        "movsd %xmm2, (%esp)\n"
        "movsd %xmm1, -0x98(%ebp)\n"
        "calll log\n"
        "fstpl -0xb8(%ebp)\n"
        "movsd -0xb8(%ebp), %xmm0\n"
        "mulsd 0x307f50, %xmm0\n" /* 0.3 */
        "movsd -0x98(%ebp), %xmm1\n"
        "addsd %xmm0, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm2\n"
        ".Lf1f47ee_001f4be1:\n"
        "movss 0x2ed5dc, %xmm0\n" /* line 253 | -1.0f */
        "maxss %xmm2, %xmm0\n"
        "movaps %xmm0, %xmm2\n"
        "movss 0x18(%ebp), %xmm0\n" /* line 258 | pitch_coef */
        "movss %xmm0, 0x24(%ebx)\n" /* vbr */
        "movss %xmm2, 0x2c(%ebx)\n" /* line 259 | vbr */
        "movl %ebx, %edx\n" /* vbr */
        "movl $4, %ecx\n"
        ".Lf1f47ee_001f4c06:\n"
        "movl 0x18(%edx), %eax\n" /* line 262 */
        "movl %eax, 0x1c(%edx)\n"
        "subl $4, %edx\n"
        "subl $1, %ecx\n" /* line 261 */
        "jne .Lf1f47ee_001f4c06\n"
        "movss -0x1c(%ebp), %xmm1\n" /* line 263 | log_energy */
        "movss %xmm1, 0xc(%ebx)\n" /* vbr */
        /* } scope */
        "movss %xmm2, -0xac(%ebp)\n" /* line 268 */
        "flds -0xac(%ebp)\n"
        "addl $0xc0, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: short_diff */
        ".Lf1f47ee_001f4c36:\n"
        "ucomisd 0x307e08, %xmm2\n" /* line 155 | 0.05 */
        "jae .Lf1f47ee_001f4c5d\n"
        "jp .Lf1f47ee_001f4c5d\n"
        "cvtss2sd %xmm6, %xmm1\n"
        "cvtss2sd 0x30(%ebx), %xmm0\n" /* vbr */
        "mulsd 0x307c20, %xmm0\n" /* 1.5 */
        "ucomisd %xmm1, %xmm0\n"
        "ja .Lf1f47ee_001f499e\n"
        ".Lf1f47ee_001f4c5d:\n"
        "movsd 0x307e58, %xmm0\n" /* 0.4 */
        "ucomisd %xmm3, %xmm0\n"
        "ja .Lf1f47ee_001f4e0f\n"
        ".Lf1f47ee_001f4c6f:\n"
        "pxor %xmm1, %xmm1\n"
        "ucomiss -0x18(%ebp), %xmm1\n" /* voicing */
        "ja .Lf1f47ee_001f4e7c\n"
        ".Lf1f47ee_001f4c7d:\n"
        "xorl %esi, %esi\n" /* line 174 | len */
        "movl $0, 0x3c(%ebx)\n" /* vbr */
        "movss 0x30(%ebx), %xmm4\n" /* vbr */
        ".Lf1f47ee_001f4c8b:\n"
        "ucomiss %xmm6, %xmm4\n" /* line 177 */
        "jbe .Lf1f47ee_001f4a0c\n"
        ".Lf1f47ee_001f4c94:\n"
        "movss -0x28(%ebp), %xmm2\n" /* ener */
        "ucomiss 0x2edab4, %xmm2\n" /* 6000.0f */
        "ja .Lf1f47ee_001f4eb3\n"
        "movaps %xmm2, %xmm0\n"
        "ucomiss 0x2ed984, %xmm0\n" /* line 184 | 30000.0f */
        "jb .Lf1f47ee_001f4a1e\n"
        ".Lf1f47ee_001f4cb6:\n"
        "movaps %xmm0, %xmm1\n"
        /* { scope 2 */
        "addss 0x2ed5d0, %xmm1\n" /* line 193 | 1.0f */
        "movss 8(%ebx), %xmm0\n" /* vbr */
        "addss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movaps %xmm1, %xmm2\n"
        "divss %xmm0, %xmm2\n"
        "movss %xmm2, (%esp)\n"
        "movss %xmm1, -0x98(%ebp)\n"
        "calll logf\n"
        "fstps -0x14(%ebp)\n" /* short_diff */
        "movss 0x2ed5d0, %xmm0\n" /* line 194 | 1.0f */
        "addss 4(%ebx), %xmm0\n" /* vbr */
        "movss -0x98(%ebp), %xmm1\n"
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, (%esp)\n"
        "calll logf\n"
        "fstps -0xac(%ebp)\n"
        "movss -0xac(%ebp), %xmm1\n"
        "ucomiss 0x2ed920, %xmm1\n" /* line 197 | -5.0f */
        "jae .Lf1f47ee_001f4f33\n"
        "jp .Lf1f47ee_001f4f33\n"
        "movsd 0x307f80, %xmm0\n" /* 7.0 */
        "movsd 0x307f88, %xmm1\n" /* -5.0 */
        "movsd 0x307e60, %xmm3\n" /* 0.6 */
        ".Lf1f47ee_001f4d46:\n"
        "mulsd 0x307ce0, %xmm1\n" /* line 205 | 0.5 */
        "addsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm2\n"
        ".Lf1f47ee_001f4d56:\n"
        "movss -0x14(%ebp), %xmm1\n" /* line 206 | short_diff */
        "pxor %xmm0, %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf1f47ee_001f4d8d\n"
        "ucomiss 0x2ed6d4, %xmm1\n" /* line 208 | 5.0f */
        "jbe .Lf1f47ee_001f5060\n"
        "movsd 0x307f90, %xmm1\n" /* 5.0 */
        ".Lf1f47ee_001f4d79:\n"
        "cvtss2sd %xmm2, %xmm0\n" /* line 210 */
        "mulsd 0x307ce0, %xmm1\n" /* 0.5 */
        "addsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm2\n"
        ".Lf1f47ee_001f4d8d:\n"
        "cvtss2sd -0x20(%ebp), %xmm1\n" /* line 213 | ener2 */
        "cvtss2sd -0x24(%ebp), %xmm0\n" /* ener1 */
        "mulsd 0x307f98, %xmm0\n" /* 1.6 */
        "ucomisd %xmm0, %xmm1\n"
        "jbe .Lf1f47ee_001f4dad\n"
        "addss 0x2ed5d8, %xmm2\n" /* 0.5f */
        ".Lf1f47ee_001f4dad:\n"
        "cvtss2sd %xmm2, %xmm1\n"
        "jmp .Lf1f47ee_001f4a59\n"
        /* } scope */
        ".Lf1f47ee_001f4db6:\n"
        "leal (%edx, %ecx, 4), %eax\n" /* line 137 */
        "movl $0, -0x20(%ebp)\n" /* ener2 */
        "xorl %edx, %edx\n"
        "subl %ecx, %esi\n" /* len */
        "movl %esi, %ecx\n" /* len */
        ".Lf1f47ee_001f4dc6:\n"
        "movss (%eax), %xmm0\n" /* line 138 */
        "mulss %xmm0, %xmm0\n"
        "addss -0x20(%ebp), %xmm0\n" /* ener2 */
        "movss %xmm0, -0x20(%ebp)\n" /* ener2 */
        "addl $1, %edx\n"
        "addl $4, %eax\n"
        "cmpl %ecx, %edx\n" /* line 137 */
        "jne .Lf1f47ee_001f4dc6\n"
        "jmp .Lf1f47ee_001f4829\n"
        ".Lf1f47ee_001f4de7:\n"
        "xorl %eax, %eax\n" /* line 134 */
        "movl $0, -0x24(%ebp)\n" /* ener1 */
        ".Lf1f47ee_001f4df0:\n"
        "movss (%edx, %eax, 4), %xmm0\n" /* line 135 */
        "mulss %xmm0, %xmm0\n"
        "addss -0x24(%ebp), %xmm0\n" /* ener1 */
        "movss %xmm0, -0x24(%ebp)\n" /* ener1 */
        "addl $1, %eax\n" /* line 134 */
        "cmpl %eax, %ecx\n"
        "jne .Lf1f47ee_001f4df0\n"
        "jmp .Lf1f47ee_001f4815\n"
        ".Lf1f47ee_001f4e0f:\n"
        "cvtss2sd %xmm4, %xmm0\n" /* line 155 */
        "ucomisd 0x307e08, %xmm0\n" /* 0.05 */
        "jae .Lf1f47ee_001f4c6f\n"
        "jp .Lf1f47ee_001f4c6f\n"
        "cvtss2sd %xmm6, %xmm1\n"
        "cvtss2sd 0x30(%ebx), %xmm0\n" /* vbr */
        "mulsd 0x307f68, %xmm0\n" /* 1.2 */
        "ucomisd %xmm1, %xmm0\n"
        "ja .Lf1f47ee_001f499e\n"
        "jmp .Lf1f47ee_001f4c6f\n"
        ".Lf1f47ee_001f4e47:\n"
        "movsd 0x307f78, %xmm1\n" /* line 187 | 6.300000190734863 */
        "movss -0x28(%ebp), %xmm2\n" /* line 189 | ener */
        "ucomiss 0x2edab8, %xmm2\n" /* 3000.0f */
        "jae .Lf1f47ee_001f4a51\n"
        ".Lf1f47ee_001f4e61:\n"
        "jp .Lf1f47ee_001f4a51\n"
        "subsd 0x307d70, %xmm1\n" /* 0.7 */
        "cvtsd2ss %xmm1, %xmm0\n"
        "cvtss2sd %xmm0, %xmm1\n"
        "jmp .Lf1f47ee_001f4a51\n"
        ".Lf1f47ee_001f4e7c:\n"
        "cvtss2sd %xmm4, %xmm0\n" /* line 155 */
        "ucomisd 0x307e08, %xmm0\n" /* 0.05 */
        "jae .Lf1f47ee_001f4c7d\n"
        "jnp .Lf1f47ee_001f499e\n"
        "jmp .Lf1f47ee_001f4c7d\n"
        ".Lf1f47ee_001f4e99:\n"
        "cvtss2sd %xmm6, %xmm0\n" /* line 153 */
        "mulsd 0x307e08, %xmm0\n" /* 0.05 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, 0x34(%ebx)\n" /* vbr */
        "jmp .Lf1f47ee_001f4954\n"
        ".Lf1f47ee_001f4eb3:\n"
        "cvtss2sd 0x34(%ebx), %xmm1\n" /* line 179 | vbr */
        "movsd 0x307e00, %xmm3\n" /* 0.95 */
        "mulsd %xmm3, %xmm1\n"
        "cvtss2sd %xmm6, %xmm0\n"
        "movsd 0x307e08, %xmm2\n" /* 0.05 */
        "mulsd %xmm2, %xmm0\n"
        "addsd %xmm0, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm1\n"
        "movss %xmm1, 0x34(%ebx)\n" /* vbr */
        "cvtss2sd 0x38(%ebx), %xmm0\n" /* line 180 | vbr */
        "mulsd %xmm3, %xmm0\n"
        "addsd %xmm2, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, 0x38(%ebx)\n" /* vbr */
        "jmp .Lf1f47ee_001f4a0c\n"
        ".Lf1f47ee_001f4efc:\n"
        "movss 0x2ed6b4, %xmm0\n" /* line 224 | 10.0f */
        "movaps %xmm0, %xmm1\n"
        "cmpltss %xmm2, %xmm0\n"
        "andps %xmm0, %xmm1\n"
        "andnps %xmm2, %xmm0\n"
        "orps %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm2\n"
        "cmpl $2, %esi\n" /* line 235 | len */
        "jle .Lf1f47ee_001f4afa\n"
        ".Lf1f47ee_001f4f21:\n"
        "movsd 0x307d68, %xmm2\n" /* 4.0 */
        "movsd %xmm2, -0x10(%ebp)\n"
        "jmp .Lf1f47ee_001f4b07\n"
        /* { scope 2 */
        ".Lf1f47ee_001f4f33:\n"
        "ucomiss 0x2ed62c, %xmm1\n" /* line 199 | 2.0f */
        "jbe .Lf1f47ee_001f5073\n"
        "movss 0x2ed62c, %xmm1\n" /* 2.0f */
        "movsd 0x307e90, %xmm0\n" /* 2.0 */
        ".Lf1f47ee_001f4f50:\n"
        "movsd 0x307e60, %xmm3\n" /* line 203 | 0.6 */
        "mulsd %xmm3, %xmm0\n"
        "addsd 0x307f80, %xmm0\n" /* 7.0 */
        "cvtsd2ss %xmm0, %xmm2\n"
        ".Lf1f47ee_001f4f68:\n"
        "pxor %xmm0, %xmm0\n" /* line 204 */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf1f47ee_001f4d56\n"
        "cvtss2sd %xmm2, %xmm0\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "jmp .Lf1f47ee_001f4d46\n"
        /* } scope */
        ".Lf1f47ee_001f4f82:\n"
        "cvtss2sd %xmm2, %xmm2\n" /* line 248 */
        "movsd %xmm2, -0x70(%ebp)\n"
        "cvtsi2sdl %esi, %xmm0\n" /* len */
        "addsd 0x307db0, %xmm0\n" /* 3.0 */
        "movsd %xmm0, (%esp)\n"
        "calll log\n"
        "fstpl -0xb8(%ebp)\n"
        "movsd -0xb8(%ebp), %xmm0\n"
        "movl $0, (%esp)\n"
        "movl $0x40080000, 4(%esp)\n"
        "movsd %xmm0, -0x88(%ebp)\n"
        "calll log\n"
        "fstpl -0x78(%ebp)\n"
        "movsd -0x88(%ebp), %xmm0\n"
        "subsd -0x78(%ebp), %xmm0\n"
        "mulsd 0x307dd8, %xmm0\n" /* -0.5 */
        "addsd -0x70(%ebp), %xmm0\n"
        "cvtsd2ss %xmm0, %xmm2\n"
        "jmp .Lf1f47ee_001f4b8b\n"
        ".Lf1f47ee_001f4ff1:\n"
        "cvtss2sd %xmm0, %xmm2\n" /* line 246 */
        "movsd %xmm2, -0x60(%ebp)\n"
        "cvtsi2sdl %esi, %xmm0\n" /* len */
        "addsd 0x307db0, %xmm0\n" /* 3.0 */
        "movsd %xmm0, (%esp)\n"
        "calll log\n"
        "fstpl -0xb8(%ebp)\n"
        "movsd -0xb8(%ebp), %xmm0\n"
        "movl $0, (%esp)\n"
        "movl $0x40080000, 4(%esp)\n"
        "movsd %xmm0, -0x88(%ebp)\n"
        "calll log\n"
        "fstpl -0x68(%ebp)\n"
        "movsd -0x88(%ebp), %xmm0\n"
        "subsd -0x68(%ebp), %xmm0\n"
        "mulsd 0x307dd8, %xmm0\n" /* -0.5 */
        "addsd -0x60(%ebp), %xmm0\n"
        "cvtsd2ss %xmm0, %xmm2\n"
        "jmp .Lf1f47ee_001f4b72\n"
        /* { scope 2 */
        ".Lf1f47ee_001f5060:\n"
        "cvtss2sd -0x14(%ebp), %xmm1\n" /* line 208 | short_diff */
        "jmp .Lf1f47ee_001f4d79\n"
        /* } scope */
        ".Lf1f47ee_001f506a:\n"
        "pxor %xmm1, %xmm1\n" /* line 249 */
        "jmp .Lf1f47ee_001f4b9c\n"
        /* { scope 2 */
        ".Lf1f47ee_001f5073:\n"
        "pxor %xmm0, %xmm0\n" /* line 202 */
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf1f47ee_001f5085\n"
        "cvtss2sd %xmm1, %xmm0\n"
        "jmp .Lf1f47ee_001f4f50\n"
        ".Lf1f47ee_001f5085:\n"
        "movss 0x2ed7fc, %xmm2\n" /* 7.0f */
        "movsd 0x307e60, %xmm3\n" /* 0.6 */
        "jmp .Lf1f47ee_001f4f68\n"
    );
}

/* line 270 */
__attribute__((naked))
void vbr_destroy(VBRState *vbr)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 270 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 272 */
        "retl\n"
    );
}

