/* ASM dump from: r_outdoor.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_outdoor.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/com_vector.h"
 */

static const int outdoorMapSize[3]; /* 0x2f30a0 */
static struct OutdoorGlob outdoorGlob; /* 0xce7180 */

void R_RegisterOutdoorImage(GfxWorld *world);
void R_GenerateOutdoorImage(GfxImage *outdoorImage);

/* line 204 */
__attribute__((naked))
void R_RegisterOutdoorImage(GfxWorld *world)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 204 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %edi\n" /* world */
        "movl 0x195eec0, %eax\n" /* line 209 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lf108aec_00108cd6\n"
        /* { scope 1 */
        "movl $0xce718c, 4(%esp)\n" /* line 86 */
        "movl $outdoorGlob, (%esp)\n"
        "calll ClearBounds\n"
        "movl 0x10(%edi), %eax\n" /* line 88 */
        "testl %eax, %eax\n"
        "je .Lf108aec_00108b72\n"
        "xorl %esi, %esi\n" /* surfIter */
        "xorl %ebx, %ebx\n"
        "jmp .Lf108aec_00108b35\n"
        ".Lf108aec_00108b2a:\n"
        "addl $1, %esi\n" /* surfIter */
        "addl $0xc, %ebx\n"
        "cmpl 0x10(%edi), %esi\n" /* surfIter */
        "je .Lf108aec_00108b72\n"
        ".Lf108aec_00108b35:\n"
        "movl %ebx, %edx\n" /* line 90 */
        "addl 0x14(%edi), %edx\n"
        "movl (%edx), %eax\n" /* line 93 */
        "testb $8, 0xc(%eax)\n"
        "jne .Lf108aec_00108b2a\n"
        "movl 8(%edx), %edx\n" /* line 96 */
        "movl $0xce718c, 0xc(%esp)\n" /* line 97 */
        "movl $outdoorGlob, 8(%esp)\n"
        "leal 0x10(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "addl $4, %edx\n"
        "movl %edx, (%esp)\n"
        "calll ExpandBounds\n"
        "addl $1, %esi\n" /* line 88 | surfIter */
        "addl $0xc, %ebx\n"
        "cmpl 0x10(%edi), %esi\n" /* surfIter */
        "jne .Lf108aec_00108b35\n"
        ".Lf108aec_00108b72:\n"
        "movl $outdoorGlob, %eax\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "movss 0x2ed5d8, %xmm5\n" /* 0.5f */
        "movss 0x2ed688, %xmm2\n" /* 131072.0f */
        "pxor %xmm4, %xmm4\n"
        ".Lf108aec_00108b93:\n"
        "movss (%eax), %xmm1\n" /* line 102 */
        "ucomiss %xmm2, %xmm1\n"
        "jne .Lf108aec_00108bab\n"
        "jp .Lf108aec_00108bab\n"
        "movss %xmm4, (%eax)\n" /* line 105 */
        "movss %xmm4, 0xc(%eax)\n" /* line 106 */
        "movss (%eax), %xmm1\n"
        ".Lf108aec_00108bab:\n"
        "movss 0xc(%eax), %xmm0\n" /* line 109 */
        "subss %xmm1, %xmm0\n"
        "ucomiss %xmm0, %xmm3\n"
        "ja .Lf108aec_00108ce8\n"
        ".Lf108aec_00108bbd:\n"
        "addl $4, %eax\n" /* line 112 */
        "cmpl $0xce718c, %eax\n" /* line 100 */
        "jne .Lf108aec_00108b93\n"
        "movl $outdoorMapSize, %ecx\n"
        "movl $0xce718c, %edx\n"
        "movss 0x2f30b0, %xmm2\n"
        /* } scope */
        ".Lf108aec_00108bd9:\n"
        "movl (%ecx), %eax\n" /* line 125 */
        "subl $1, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movss (%edx), %xmm0\n"
        "subss -0xc(%edx), %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, 0xc(%edx)\n"
        "movaps %xmm3, %xmm0\n" /* line 126 */
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0x18(%edx)\n"
        "movss -0xc(%edx), %xmm0\n" /* line 127 */
        "xorps %xmm2, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 0x24(%edx)\n"
        "addl $4, %ecx\n"
        "addl $4, %edx\n"
        "cmpl $0x2f30ac, %ecx\n" /* line 123 */
        "jne .Lf108aec_00108bd9\n"
        "movl $1, %ecx\n"
        "movl $0xce718c, %edx\n"
        "leal -0x24(%ebp), %esi\n" /* outdoorScale, surfIter */
        "leal -0x30(%ebp), %ebx\n" /* outdoorTranslate */
        /* { scope 1 */
        ".Lf108aec_00108c2f:\n"
        "movss -0xc(%edx), %xmm1\n" /* line 140 */
        "movss (%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movaps %xmm3, %xmm4\n"
        "divss %xmm0, %xmm4\n"
        "leal (, %ecx, 4), %eax\n"
        "movss %xmm4, -4(%esi, %eax)\n" /* surfIter */
        "xorps %xmm2, %xmm1\n" /* line 141 */
        "mulss %xmm4, %xmm1\n"
        "movss %xmm1, -4(%ebx, %eax)\n"
        "addl $1, %ecx\n"
        "addl $4, %edx\n"
        "cmpl $4, %ecx\n" /* line 138 */
        "jne .Lf108aec_00108c2f\n"
        "leal 0x1c0(%edi), %eax\n" /* line 144 */
        "movl %eax, (%esp)\n"
        "calll MatrixIdentity44\n"
        "movl -0x24(%ebp), %eax\n" /* line 145 | outdoorScale */
        "movl %eax, 0x1c0(%edi)\n"
        "movl -0x20(%ebp), %eax\n" /* line 146 */
        "movl %eax, 0x1d4(%edi)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 147 */
        "movl %eax, 0x1e8(%edi)\n"
        "movl -0x30(%ebp), %eax\n" /* line 148 | outdoorTranslate */
        "movl %eax, 0x1f0(%edi)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 149 */
        "movl %eax, 0x1f4(%edi)\n"
        "movl -0x28(%ebp), %eax\n" /* line 150 */
        "movl %eax, 0x1f8(%edi)\n"
        /* } scope */
        "movl $0, 8(%esp)\n" /* line 220 */
        "movl $1, 4(%esp)\n"
        "movl $0x226a88, (%esp)\n" /* "$outdoor" */
        "calll Image_Register\n"
        "movl %eax, 0x200(%edi)\n" /* world */
        "addl $0x3c, %esp\n" /* line 222 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf108aec_00108cd6:\n"
        "movl $0, 0x200(%edi)\n" /* line 211 | world */
        "addl $0x3c, %esp\n" /* line 222 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf108aec_00108ce8:\n"
        "subss %xmm5, %xmm1\n" /* line 111 */
        "movss %xmm1, (%eax)\n"
        "movss 0xc(%eax), %xmm0\n" /* line 112 */
        "addss %xmm5, %xmm0\n"
        "movss %xmm0, 0xc(%eax)\n"
        "jmp .Lf108aec_00108bbd\n"
    );
}

/* line 225 */
__attribute__((naked))
void R_GenerateOutdoorImage(GfxImage *outdoorImage)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 225 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl $0x40000, (%esp)\n" /* line 38 */
        "calll Hunk_AllocateTempMemoryInternal\n"
        "movl %eax, -0x5c(%ebp)\n"
        "movl %eax, 0xce71bc\n"
        "movl $0, -0x60(%ebp)\n" /* line 190 */
        "leal -0x54(%ebp), %esi\n"
        ".Lf108d04_00108d2e:\n"
        "cvtsi2ssl -0x60(%ebp), %xmm3\n" /* line 156 */
        "movss 0x2ed5d8, %xmm4\n" /* 0.5f */
        "addss %xmm4, %xmm3\n"
        "subss 0xce71b4, %xmm3\n"
        "mulss 0xce71a8, %xmm3\n"
        "xorl %ebx, %ebx\n" /* line 193 */
        "jmp .Lf108d04_00108d7d\n"
        ".Lf108d04_00108d53:\n"
        "movl $0xffffffff, %edx\n" /* line 381 */
        "cmpl $0xff, %eax\n"
        "cmovlel %eax, %edx\n"
        "movl -0x5c(%ebp), %eax\n" /* line 176 */
        "movb %dl, (%eax, %ebx)\n"
        "addl $1, %ebx\n" /* line 193 */
        "cmpl $0x200, %ebx\n"
        "je .Lf108d04_00108e91\n"
        ".Lf108d04_00108d75:\n"
        "movss 0x2ed5d8, %xmm4\n" /* 0.5f */
        ".Lf108d04_00108d7d:\n"
        "movss 0xce7194, %xmm2\n" /* line 64 */
        "addss 0x2ed5d0, %xmm2\n" /* 1.0f */
        "movss 0xce7188, %xmm1\n" /* line 65 */
        "subss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "cvtsi2ssl %ebx, %xmm0\n" /* line 191 */
        "addss %xmm4, %xmm0\n"
        "subss 0xce71b0, %xmm0\n"
        "mulss 0xce71a4, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        "movss %xmm3, -0x20(%ebp)\n" /* line 192 */
        "movss %xmm2, -0x1c(%ebp)\n" /* line 193 */
        "movss %xmm0, -0x30(%ebp)\n" /* line 199 */
        "movss %xmm3, -0x2c(%ebp)\n" /* line 200 */
        "movss %xmm1, -0x28(%ebp)\n" /* line 69 */
        "cld\n" /* line 71 */
        "movl $9, %ecx\n"
        "movl %esi, %edi\n"
        "xorl %eax, %eax\n"
        "rep stosl %eax, %es:(%edi)\n"
        "movl $0x3f800000, -0x54(%ebp)\n" /* line 72 */
        "movl $0x2001, 0x18(%esp)\n" /* line 73 */
        "movl $0, 0x14(%esp)\n"
        "movl 0x195ed4c, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "movss %xmm1, -0x78(%ebp)\n"
        "movss %xmm2, -0x88(%ebp)\n"
        "movss %xmm3, -0x98(%ebp)\n"
        "calll CM_BoxTrace\n"
        "movss -0x78(%ebp), %xmm1\n" /* line 443 */
        "movss -0x88(%ebp), %xmm2\n"
        "subss %xmm2, %xmm1\n"
        "mulss -0x54(%ebp), %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "mulss 0xce71a0, %xmm2\n"
        "addss 0xce71b8, %xmm2\n"
        "movss %xmm2, (%esp)\n"
        "calll floorf\n"
        "fstps -0x64(%ebp)\n"
        "cvttss2si -0x64(%ebp), %eax\n"
        "testl %eax, %eax\n" /* line 379 */
        "movss -0x98(%ebp), %xmm3\n"
        "jns .Lf108d04_00108d53\n"
        "xorl %edx, %edx\n"
        "movl -0x5c(%ebp), %eax\n" /* line 176 */
        "movb %dl, (%eax, %ebx)\n"
        "addl $1, %ebx\n" /* line 193 */
        "cmpl $0x200, %ebx\n"
        "jne .Lf108d04_00108d75\n"
        ".Lf108d04_00108e91:\n"
        "addl $0x200, %eax\n"
        "movl %eax, -0x5c(%ebp)\n"
        "addl $1, -0x60(%ebp)\n" /* line 190 */
        "cmpl $0x200, -0x60(%ebp)\n"
        "jne .Lf108d04_00108d2e\n"
        "movl $0x32, 0x10(%esp)\n" /* line 239 */
        "movl $0x200, 0xc(%esp)\n"
        "movl $0x200, 8(%esp)\n"
        "movl 0xce71bc, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* outdoorImage */
        "movl %eax, (%esp)\n"
        "calll Image_Generate2D\n"
        "movl 0xce71bc, %eax\n" /* line 52 */
        "movl %eax, (%esp)\n"
        "calll Hunk_FreeTempMemory\n"
        "addl $0xac, %esp\n" /* line 241 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

