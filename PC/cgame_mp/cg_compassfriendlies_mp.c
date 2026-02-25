/* ASM dump from: cg_compassfriendlies_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_compassfriendlies_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

void CG_ApplyCompassPointerRadiusScale(float *radiusScale);
void CG_CompassAddWeaponPingInfo(centity_t *cent, const vec_t *origin, int msec);
void CG_DrawCompassFriendlies(rectDef_t *rect, MaterialHandle material, vec_t *color);

/* line 51 */
__attribute__((naked))
void CG_ApplyCompassPointerRadiusScale(float *radiusScale)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 51 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* radiusScale */
        "movl 0x195f640, %eax\n" /* line 55 */
        "movl (%eax), %eax\n"
        "cvtss2sd 8(%eax), %xmm0\n"
        "mulsd 0x307d60, %xmm0\n" /* 43.75 */
        "cvtss2sd (%edx), %xmm1\n"
        "mulsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "popl %ebp\n" /* line 56 */
        "retl\n"
    );
}

/* line 15 */
__attribute__((naked))
void CG_CompassAddWeaponPingInfo(centity_t *cent, const vec_t *origin, int msec)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 15 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %edi\n" /* cent */
        "movl 0x10(%ebp), %esi\n" /* msec */
        /* { scope 1 */
        "cmpl $2, 0xf4(%edi)\n" /* line 22 | cent */
        "je .Lf18cecc_0018cf98\n"
        "movl 0x195f584, %eax\n" /* line 26 */
        "movl (%eax), %ebx\n"
        "movl 4(%ebx), %edx\n"
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "leal 0xe0914(%ebx, %eax, 8), %eax\n"
        "movl %eax, -0x10(%ebp)\n" /* localClientInfo */
        "movl 0xf0(%edi), %ecx\n" /* line 27 | cent */
        "leal (, %ecx, 4), %edi\n" /* cent */
        "leal (%edi, %ecx), %edx\n" /* cent */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "leal 0xe0914(%ebx, %eax, 8), %eax\n"
        "cmpl %eax, -0x10(%ebp)\n" /* line 29 | localClientInfo */
        "je .Lf18cecc_0018cf98\n"
        "movl 0x2c(%eax), %edx\n" /* line 33 */
        "cmpl $3, %edx\n" /* line 35 */
        "je .Lf18cecc_0018cf98\n"
        "movl %ecx, %eax\n" /* line 40 */
        "shll $5, %eax\n"
        "subl %edi, %eax\n" /* cent */
        "addl 0x25bb0(%ebx), %esi\n" /* msec */
        "movl %esi, 0x2c5ec(%eax, %ebx)\n" /* msec */
        "movl -0x10(%ebp), %esi\n" /* line 41 | localClientInfo, msec */
        "movl 0x2c(%esi), %eax\n" /* msec */
        "testl %eax, %eax\n"
        "jne .Lf18cecc_0018cfa0\n"
        ".Lf18cecc_0018cf55:\n"
        "movl $1, %esi\n" /* msec */
        ".Lf18cecc_0018cf5a:\n"
        "leal (, %ecx, 4), %eax\n"
        "movl %ecx, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl %esi, %eax\n" /* msec */
        "movb %al, 0x2c5f0(%edx, %ebx)\n"
        "movl 0x195f584, %ecx\n" /* line 43 */
        "movl (%ecx), %eax\n"
        "cmpb $0, 0x2c5f0(%edx, %eax)\n"
        "je .Lf18cecc_0018cf98\n"
        "leal 0x2c5d0(%edx, %eax), %eax\n" /* line 44 */
        "movl 0xc(%ebp), %esi\n" /* line 37 | origin, msec */
        "movl (%esi), %edx\n" /* msec */
        "movl %edx, 0xc(%eax)\n"
        "movl 4(%esi), %edx\n" /* line 38 | msec */
        "movl %edx, 0x10(%eax)\n"
        /* } scope */
        ".Lf18cecc_0018cf98:\n"
        "addl $4, %esp\n" /* line 45 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf18cecc_0018cfa0:\n"
        "cmpl %eax, %edx\n" /* line 41 */
        "jne .Lf18cecc_0018cf55\n"
        "xorl %esi, %esi\n" /* msec */
        "jmp .Lf18cecc_0018cf5a\n"
    );
}

/* line 95 */
__attribute__((naked))
void CG_DrawCompassFriendlies(rectDef_t *rect, MaterialHandle material, vec_t *color)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 95 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x11c, %esp\n"
        /* { scope 1: radians, radians */
        "movl 0x195f678, %eax\n" /* line 124 */
        "movl (%eax), %ebx\n" /* drawMaterial */
        "movss 0x2ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "mulss 8(%ebx), %xmm0\n" /* drawMaterial */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x9c(%ebp)\n"
        "cvttss2si -0x9c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x195f584, %edi\n"
        "movl (%edi), %esi\n" /* cent */
        "movl 0x2c5c0(%esi), %eax\n" /* cent */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* drawMaterial */
        "calll CG_FadeHudMenu\n"
        "fstps -0x8c(%ebp)\n" /* compassFadeOutAlpha */
        "movss -0x8c(%ebp), %xmm0\n" /* line 125 | compassFadeOutAlpha */
        "ucomiss 0x2ed5e8, %xmm0\n" /* 0.0f */
        "jp .Lf18cfaa_0018d025\n"
        "je .Lf18cfaa_0018d3b6\n"
        ".Lf18cfaa_0018d025:\n"
        "movl 0x24(%esi), %eax\n" /* line 128 | cent */
        "movl 0xd8(%eax), %edx\n"
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "leal (%esi, %eax, 8), %eax\n" /* cent */
        "movl 0xe0914(%eax), %ebx\n" /* drawMaterial */
        "testl %ebx, %ebx\n" /* drawMaterial */
        "je .Lf18cfaa_0018d3b6\n"
        "movl 0xe0940(%eax), %eax\n" /* line 130 */
        "movl %eax, -0x88(%ebp)\n" /* team */
        "cmpl $3, %eax\n" /* line 132 */
        "je .Lf18cfaa_0018d3b6\n"
        "calll CG_UpdateCompPointerOrientation\n" /* line 135 */
        "movl 0x195f640, %eax\n" /* line 137 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "movl 8(%ebp), %eax\n" /* rect */
        "mulss 8(%eax), %xmm1\n"
        "movss 0x2ed5d8, %xmm2\n" /* 0.5f */
        "mulss %xmm1, %xmm2\n"
        "movss %xmm2, -0x98(%ebp)\n" /* centerX */
        "addss (%eax), %xmm2\n"
        "movss %xmm2, -0x98(%ebp)\n" /* centerX */
        "movss 0xc(%eax), %xmm1\n" /* line 138 */
        "movaps %xmm1, %xmm3\n"
        "addss 4(%eax), %xmm3\n"
        "mulss %xmm1, %xmm0\n"
        "mulss 0x2ed63c, %xmm0\n" /* -0.5f */
        "addss %xmm3, %xmm0\n"
        "movss %xmm0, -0x94(%ebp)\n" /* centerY */
        "movl 0x10(%ebp), %edx\n" /* line 456 | color */
        "movl (%edx), %eax\n"
        "movl %eax, -0x50(%ebp)\n" /* fadedColor */
        "addl $4, %edx\n" /* line 457 */
        "movl %edx, -0x84(%ebp)\n"
        "movl 0x10(%ebp), %ecx\n" /* color */
        "movl 4(%ecx), %eax\n"
        "movl %eax, -0x4c(%ebp)\n"
        "addl $8, %ecx\n" /* line 458 */
        "movl %ecx, -0x80(%ebp)\n"
        "movl 0x10(%ebp), %ebx\n" /* color, drawMaterial */
        "movl 8(%ebx), %eax\n" /* drawMaterial */
        "movl %eax, -0x48(%ebp)\n"
        "addl $0xc, %ebx\n" /* line 459 | drawMaterial */
        "movl %ebx, -0x7c(%ebp)\n" /* drawMaterial */
        "movl 0x10(%ebp), %edx\n" /* color */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        "movl -0x88(%ebp), %ecx\n" /* line 142 | team */
        "testl %ecx, %ecx\n"
        "jne .Lf18cfaa_0018d3f2\n"
        ".Lf18cfaa_0018d108:\n"
        "movl (%edi), %ebx\n" /* line 309 | drawMaterial */
        "addl $0x2c5d8, %ebx\n" /* drawMaterial */
        "movl $0x40, %edi\n"
        "jmp .Lf18cfaa_0018d123\n"
        ".Lf18cfaa_0018d117:\n"
        "addl $0x1c, %ebx\n" /* line 310 | drawMaterial */
        "subl $1, %edi\n"
        "je .Lf18cfaa_0018d3b6\n"
        ".Lf18cfaa_0018d123:\n"
        "cmpb $0, 0x18(%ebx)\n" /* line 312 | drawMaterial */
        "je .Lf18cfaa_0018d117\n"
        "movl 0x14(%ebx), %edx\n" /* line 314 | drawMaterial */
        "movl 0x195f584, %eax\n"
        "movl (%eax), %esi\n" /* cent */
        "cvtsi2ssl %edx, %xmm1\n"
        "movl 0x195f674, %ecx\n"
        "movl (%ecx), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "addss %xmm0, %xmm1\n"
        "cvtsi2ssl 0x25bb0(%esi), %xmm0\n" /* cent */
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf18cfaa_0018d117\n"
        "testl %edx, %edx\n"
        "je .Lf18cfaa_0018d117\n"
        "movss 4(%ebx), %xmm0\n" /* line 65 */
        "subss 0x28588(%esi), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* posDelta */
        "movss 8(%ebx), %xmm0\n" /* line 66 */
        "subss 0x2858c(%esi), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "leal -0x30(%ebp), %eax\n" /* line 318 | posDelta */
        "movl %eax, (%esp)\n"
        "calll vectoyaw\n"
        "fstps -0xec(%ebp)\n"
        "movss -0xec(%ebp), %xmm0\n"
        "subss 0x2c5b8(%esi), %xmm0\n" /* cent */
        "movss %xmm0, (%esp)\n"
        "calll AngleNormalize360\n"
        "fstps -0x6c(%ebp)\n"
        "movss -0x30(%ebp), %xmm2\n" /* line 134 | posDelta */
        "movss -0x2c(%ebp), %xmm0\n"
        "mulss %xmm2, %xmm2\n" /* line 81 */
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "sqrtss %xmm2, %xmm2\n"
        "movl 0x195f654, %eax\n" /* line 321 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "minss %xmm2, %xmm1\n"
        "movaps %xmm1, %xmm2\n"
        "movl 0x195f644, %eax\n" /* line 66 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "subss %xmm1, %xmm2\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm2\n"
        "movl 0x195f650, %eax\n" /* line 67 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "movl 0x195f640, %edx\n" /* line 55 */
        "movl (%edx), %eax\n"
        "movss 8(%eax), %xmm3\n"
        "cvtss2sd %xmm3, %xmm0\n"
        "mulsd 0x307d60, %xmm0\n" /* 43.75 */
        "addss %xmm2, %xmm1\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "mulsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x64(%ebp)\n"
        "cvtss2sd -0x6c(%ebp), %xmm0\n" /* line 327 */
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x74(%ebp)\n" /* radians */
        /* { scope 2 */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "movss %xmm3, -0xe8(%ebp)\n"
        "calll sinf\n"
        "fstps -0xb0(%ebp)\n"
        "movss -0x74(%ebp), %xmm0\n" /* line 486 | radians */
        "movss %xmm0, (%esp)\n"
        "calll cosf\n"
        "fstps -0xb4(%ebp)\n"
        /* } scope */
        "movss -0xe8(%ebp), %xmm3\n" /* line 82 */
        "mulss 0x2ed6b4, %xmm3\n" /* 10.0f */
        "movss %xmm3, -0x24(%ebp)\n" /* w */
        "movl 0x195f640, %edx\n" /* line 83 */
        "movl (%edx), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "mulss 0x2ed6b4, %xmm0\n" /* 10.0f */
        "movss %xmm0, -0x1c(%ebp)\n" /* h */
        "mulss 0x2ed63c, %xmm3\n" /* line 329 | -0.5f */
        "addss -0x98(%ebp), %xmm3\n" /* centerX */
        "movss -0x64(%ebp), %xmm1\n"
        "mulss -0xb0(%ebp), %xmm1\n"
        "subss %xmm1, %xmm3\n"
        "movss %xmm3, -0x28(%ebp)\n" /* x */
        "mulss 0x2ed63c, %xmm0\n" /* line 330 | -0.5f */
        "addss -0x94(%ebp), %xmm0\n" /* centerY */
        "movss -0x64(%ebp), %xmm2\n"
        "mulss -0xb4(%ebp), %xmm2\n"
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n" /* y */
        "leal -0x1c(%ebp), %eax\n" /* line 332 | h */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* w */
        "movl %eax, 8(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* y */
        "movl %eax, 4(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* x */
        "movl %eax, (%esp)\n"
        "calll CG_ApplySplitScreenCompassScale\n"
        "movl 0x14(%ebx), %edx\n" /* line 334 | drawMaterial */
        "movl 0x25bb0(%esi), %eax\n" /* cent */
        "cmpl %eax, %edx\n"
        "jl .Lf18cfaa_0018d3c1\n"
        "movl $0x3f800000, -0x44(%ebp)\n" /* line 335 */
        "movss -0x44(%ebp), %xmm0\n"
        ".Lf18cfaa_0018d340:\n"
        "movss -0x8c(%ebp), %xmm1\n" /* line 341 | compassFadeOutAlpha */
        "movaps %xmm1, %xmm2\n"
        "cmpltss %xmm0, %xmm1\n"
        "andps %xmm1, %xmm2\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm2, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "movl 0x195f5c4, %eax\n" /* line 343 */
        "movl (%eax), %eax\n"
        "movl 0xc1e8(%eax), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "leal -0x50(%ebp), %eax\n" /* fadedColor */
        "movl %eax, 0x18(%esp)\n"
        "movl 8(%ebp), %edx\n" /* rect */
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* h */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* w */
        "movl %eax, 8(%esp)\n"
        "movl -0x20(%ebp), %eax\n" /* y */
        "movl %eax, 4(%esp)\n"
        "movl -0x28(%ebp), %eax\n" /* x */
        "movl %eax, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        "addl $0x1c, %ebx\n" /* line 310 | drawMaterial */
        "subl $1, %edi\n"
        "jne .Lf18cfaa_0018d123\n"
        /* } scope */
        ".Lf18cfaa_0018d3b6:\n"
        "addl $0x11c, %esp\n" /* line 345 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: radians, radians */
        ".Lf18cfaa_0018d3c1:\n"
        "subl %edx, %eax\n" /* line 337 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movl 0x195f674, %edx\n"
        "movl (%edx), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "mulss 0x2ed96c, %xmm1\n" /* -1000.0f */
        "divss %xmm1, %xmm0\n"
        "addss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x44(%ebp)\n"
        "jmp .Lf18cfaa_0018d340\n"
        ".Lf18cfaa_0018d3f2:\n"
        "movl %esi, -0x70(%ebp)\n" /* line 145 | cent */
        "movl 0x24(%esi), %ecx\n" /* cent */
        "movl 0x26b4(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf18cfaa_0018d525\n"
        "xorl %ebx, %ebx\n" /* drawMaterial */
        "jmp .Lf18cfaa_0018d423\n"
        ".Lf18cfaa_0018d40a:\n"
        "addl $1, %ebx\n" /* drawMaterial */
        "movl (%edi), %esi\n" /* cent */
        "movl %esi, -0x70(%ebp)\n" /* cent */
        "movl 0x24(%esi), %ecx\n" /* cent */
        "movl %ecx, %eax\n"
        "cmpl %ebx, 0x26b4(%ecx)\n" /* drawMaterial */
        "jle .Lf18cfaa_0018d52d\n"
        ".Lf18cfaa_0018d423:\n"
        "movl %ebx, %edx\n" /* line 147 | drawMaterial */
        "shll $4, %edx\n"
        "movl %ebx, %eax\n" /* drawMaterial */
        "shll $8, %eax\n"
        "subl %edx, %eax\n"
        "movl 0x26bc(%eax, %ecx), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "addl %ecx, %eax\n"
        "leal (%ecx, %eax, 8), %eax\n"
        "movl 0x195f5cc, %esi\n" /* cent */
        "movl (%esi), %edx\n" /* cent */
        "leal (%edx, %eax, 4), %esi\n" /* cent */
        "cmpl $1, 0xf4(%esi)\n" /* line 148 | cent */
        "jne .Lf18cfaa_0018d40a\n"
        "testb $2, 0xfa(%esi)\n" /* line 150 | cent */
        "jne .Lf18cfaa_0018d40a\n"
        "testl %ecx, %ecx\n" /* line 154 */
        "js .Lf18cfaa_0018d40a\n"
        "leal (, %ecx, 4), %eax\n" /* line 157 */
        "movl %eax, -0xa0(%ebp)\n"
        "movl %eax, %edx\n"
        "addl %ecx, %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "movl -0x70(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl 0xe0914(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf18cfaa_0018d40a\n"
        "movl -0x88(%ebp), %edx\n" /* line 159 | team */
        "cmpl 0xe0940(%eax), %edx\n"
        "jne .Lf18cfaa_0018d40a\n"
        "movl %ecx, %edx\n" /* line 165 */
        "shll $5, %edx\n"
        "subl -0xa0(%ebp), %edx\n"
        "movl -0x70(%ebp), %ecx\n"
        "movl 0x25bb0(%ecx), %eax\n"
        "movl %eax, 0x2c5d8(%edx, %ecx)\n"
        "movl (%edi), %eax\n" /* line 166 */
        "movl %eax, -0xa4(%ebp)\n"
        "leal 0x2c5d0(%edx, %eax), %ecx\n"
        "movl 0x1ec(%esi), %eax\n" /* line 37 */
        "movl %eax, 0xc(%ecx)\n"
        "movl 0x1f0(%esi), %eax\n" /* line 38 */
        "movl %eax, 0x10(%ecx)\n"
        "addl -0xa4(%ebp), %edx\n" /* line 167 */
        "movl 0x1fc(%esi), %eax\n" /* cent */
        "movl %eax, 0x2c5e4(%edx)\n"
        "testb $0x40, 0xfa(%esi)\n" /* line 169 | cent */
        "je .Lf18cfaa_0018d40a\n"
        "movl -0xa4(%ebp), %ecx\n"
        "movl 0x25bb0(%ecx), %eax\n"
        "cmpl %eax, 0x2c5e8(%edx)\n"
        "jg .Lf18cfaa_0018d40a\n"
        "addl $0xbb8, %eax\n" /* line 170 */
        "movl %eax, 0x2c5e8(%edx)\n"
        "jmp .Lf18cfaa_0018d40a\n"
        ".Lf18cfaa_0018d525:\n"
        "movl %ecx, %eax\n"
        "movl 0x195f584, %edi\n"
        ".Lf18cfaa_0018d52d:\n"
        "movl 0x5b0(%eax), %eax\n" /* line 174 */
        "testl %eax, %eax\n"
        "je .Lf18cfaa_0018d67e\n"
        "movl %eax, %esi\n" /* line 176 | cent */
        "andl $0x3f, %esi\n" /* cent */
        "leal (, %esi, 4), %edx\n" /* line 179 */
        "movl %esi, %eax\n" /* cent */
        "shll $5, %eax\n"
        "subl %edx, %eax\n"
        "movl -0x70(%ebp), %ecx\n"
        "movl 0x25bb0(%ecx), %edx\n"
        "movl %edx, 0x2c5d8(%eax, %ecx)\n"
        "movl (%edi), %edx\n" /* line 181 */
        "movl 0x24(%edx), %eax\n"
        "movl 0x5b0(%eax), %eax\n"
        "andl $0x7fc0, %eax\n"
        "shrl $4, %eax\n"
        "subl $0x3fc, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n" /* posDelta */
        "movl 0x24(%edx), %eax\n" /* line 182 */
        "movl 0x5b0(%eax), %eax\n"
        "andl $0xff8000, %eax\n"
        "shrl $0xd, %eax\n"
        "subl $0x3fc, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "ucomiss 0x2ed960, %xmm1\n" /* line 184 | 1024.0f */
        "jp .Lf18cfaa_0018d5a9\n"
        "je .Lf18cfaa_0018d609\n"
        ".Lf18cfaa_0018d5a9:\n"
        "ucomiss 0x2ed964, %xmm1\n" /* -1020.0f */
        "jp .Lf18cfaa_0018d5b4\n"
        "je .Lf18cfaa_0018d609\n"
        ".Lf18cfaa_0018d5b4:\n"
        "ucomiss 0x2ed960, %xmm0\n" /* 1024.0f */
        "jp .Lf18cfaa_0018d5bf\n"
        "je .Lf18cfaa_0018d609\n"
        ".Lf18cfaa_0018d5bf:\n"
        "ucomiss 0x2ed964, %xmm0\n" /* -1020.0f */
        "jne .Lf18cfaa_0018d5ca\n"
        "jnp .Lf18cfaa_0018d609\n"
        ".Lf18cfaa_0018d5ca:\n"
        "movl (%edi), %edx\n" /* line 191 */
        "movss 0x2858c(%edx), %xmm1\n" /* line 200 */
        "leal (, %esi, 4), %ecx\n" /* line 192 */
        "movl %esi, %eax\n" /* cent */
        "shll $5, %eax\n"
        "subl %ecx, %eax\n"
        "leal 0x2c5d0(%eax, %edx), %eax\n"
        "movss 0x28588(%edx), %xmm0\n" /* line 58 */
        "addss -0x30(%ebp), %xmm0\n" /* posDelta */
        "movss %xmm0, 0xc(%eax)\n"
        "addss -0x2c(%ebp), %xmm1\n" /* line 59 */
        "movss %xmm1, 0x10(%eax)\n"
        "movl %edx, %ebx\n"
        "jmp .Lf18cfaa_0018d641\n"
        ".Lf18cfaa_0018d609:\n"
        "leal -0x30(%ebp), %eax\n" /* line 186 | posDelta */
        "movl %eax, (%esp)\n"
        "calll Vec2Normalize\n"
        "fstp %st(0)\n"
        "movl 0x195f584, %edi\n" /* line 187 */
        "leal (, %esi, 4), %edx\n"
        "movl %esi, %eax\n" /* cent */
        "shll $5, %eax\n"
        "subl %edx, %eax\n"
        "movl (%edi), %edx\n"
        "leal 0x2c5d0(%eax, %edx), %eax\n"
        "movl -0x30(%ebp), %edx\n" /* line 37 | posDelta */
        "movl %edx, 0xc(%eax)\n"
        "movl -0x2c(%ebp), %edx\n" /* line 38 */
        "movl %edx, 0x10(%eax)\n"
        "movl (%edi), %ebx\n"
        ".Lf18cfaa_0018d641:\n"
        "leal (, %esi, 4), %eax\n" /* line 195 */
        "shll $5, %esi\n" /* cent */
        "subl %eax, %esi\n" /* cent */
        "leal (%esi, %ebx), %edx\n" /* cent */
        "movl 0x24(%ebx), %eax\n" /* drawMaterial */
        "movsbl 0x5b3(%eax), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x2ed968, %xmm0\n" /* 1.40625f */
        "movss %xmm0, 0x2c5e4(%edx)\n"
        "movl 0x24(%ebx), %eax\n" /* line 197 | drawMaterial */
        "testb $0x80, 0xae(%eax)\n"
        "jne .Lf18cfaa_0018dced\n"
        ".Lf18cfaa_0018d67e:\n"
        "movl 0x10(%ebp), %ebx\n" /* line 202 | color, drawMaterial */
        "movss 0xc(%ebx), %xmm0\n" /* drawMaterial */
        "ucomiss -0x8c(%ebp), %xmm0\n" /* compassFadeOutAlpha */
        "jbe .Lf18cfaa_0018d69c\n"
        "movss -0x8c(%ebp), %xmm0\n" /* line 203 | compassFadeOutAlpha */
        "movss %xmm0, 0xc(%ebx)\n" /* drawMaterial */
        ".Lf18cfaa_0018d69c:\n"
        "movss -0x44(%ebp), %xmm0\n" /* line 204 */
        "movss -0x8c(%ebp), %xmm1\n" /* line 205 | compassFadeOutAlpha */
        "movaps %xmm1, %xmm2\n"
        "cmpltss %xmm0, %xmm1\n"
        "andps %xmm1, %xmm2\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm2, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "movl (%edi), %esi\n" /* cent */
        "addl $0x2c5f4, %esi\n" /* cent */
        "movl $0, -0x5c(%ebp)\n"
        "movl $0x2c5d0, -0xb8(%ebp)\n"
        "movl $0, -0xbc(%ebp)\n"
        ".Lf18cfaa_0018d6e5:\n"
        "movl (%edi), %ebx\n" /* line 211 | drawMaterial */
        "movl -0x1c(%esi), %eax\n" /* cent */
        "cmpl 0x25bb0(%ebx), %eax\n" /* drawMaterial */
        "jle .Lf18cfaa_0018d6f9\n"
        "movl $0, -0x1c(%esi)\n" /* line 212 | cent */
        ".Lf18cfaa_0018d6f9:\n"
        "movl 0x25bb0(%ebx), %eax\n" /* line 213 | drawMaterial */
        "subl $0x320, %eax\n"
        "cmpl %eax, -0x1c(%esi)\n" /* cent */
        "jl .Lf18cfaa_0018db2a\n"
        "movl 0x24(%ebx), %eax\n" /* line 216 | drawMaterial */
        "movl -0x5c(%ebp), %edx\n"
        "cmpl 0xd8(%eax), %edx\n"
        "je .Lf18cfaa_0018db2a\n"
        "movl -0xbc(%ebp), %eax\n" /* line 220 */
        "addl %ebx, %eax\n" /* drawMaterial */
        "movss 0x302fe0, %xmm1\n"
        "movss 0x2c5dc(%eax), %xmm0\n"
        "andps %xmm1, %xmm0\n"
        "movss 0x2ed5d0, %xmm2\n" /* 1.0f */
        "ucomiss %xmm0, %xmm2\n"
        "jb .Lf18cfaa_0018d75b\n"
        "movss 0x2c5e0(%eax), %xmm0\n"
        "andps %xmm1, %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "jae .Lf18cfaa_0018dc13\n"
        ".Lf18cfaa_0018d75b:\n"
        "movl -0xb8(%ebp), %ecx\n" /* line 310 */
        "leal (%ebx, %ecx), %eax\n" /* drawMaterial */
        "movss 0xc(%eax), %xmm0\n" /* line 65 */
        "subss 0x28588(%ebx), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* posDelta */
        "movss 0x10(%eax), %xmm0\n" /* line 66 */
        "subss 0x2858c(%ebx), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "leal -0x30(%ebp), %eax\n" /* line 233 | posDelta */
        "movl %eax, (%esp)\n"
        "calll vectoyaw\n"
        "fstps -0xec(%ebp)\n"
        "movss -0xec(%ebp), %xmm0\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "subss 0x2c5b8(%eax), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll AngleNormalize360\n"
        "fstps -0x90(%ebp)\n" /* yawTo */
        "movss -0x30(%ebp), %xmm1\n" /* line 134 | posDelta */
        "movss -0x2c(%ebp), %xmm0\n"
        "mulss %xmm1, %xmm1\n" /* line 81 */
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "sqrtss %xmm1, %xmm2\n"
        "movss %xmm2, -0x44(%ebp)\n" /* line 237 */
        "movl 0x195f660, %ebx\n" /* line 238 | drawMaterial */
        "movl (%ebx), %eax\n" /* drawMaterial */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf18cfaa_0018dbbf\n"
        "movss %xmm0, -0x44(%ebp)\n" /* line 239 */
        "movl 0x195f654, %ecx\n"
        "movl (%ecx), %edx\n"
        "movaps %xmm0, %xmm1\n"
        ".Lf18cfaa_0018d805:\n"
        "subss 8(%edx), %xmm1\n" /* line 243 */
        "movss %xmm1, -0x44(%ebp)\n"
        "movl 0x195f660, %ebx\n" /* line 244 | drawMaterial */
        "movl (%ebx), %eax\n" /* drawMaterial */
        "movss 8(%eax), %xmm0\n"
        "subss 8(%edx), %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, -0x44(%ebp)\n"
        "movl 0x195f664, %eax\n" /* line 245 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "subss %xmm3, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "addss %xmm3, %xmm1\n"
        "movss %xmm1, -0x44(%ebp)\n"
        "movss 8(%edx), %xmm0\n" /* line 248 */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf18cfaa_0018dba6\n"
        "movaps %xmm0, %xmm2\n"
        "movl 0x195f644, %edx\n"
        "movl (%edx), %eax\n"
        ".Lf18cfaa_0018d868:\n"
        "movss 8(%eax), %xmm1\n" /* line 66 */
        "subss %xmm1, %xmm2\n"
        "movl (%ecx), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm0, %xmm2\n"
        "movl 0x195f650, %eax\n" /* line 67 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "subss %xmm1, %xmm3\n"
        "mulss %xmm2, %xmm3\n"
        "movl 0x195f640, %edx\n" /* line 55 */
        "movl (%edx), %eax\n"
        "movss 8(%eax), %xmm2\n"
        "cvtss2sd %xmm2, %xmm0\n"
        "mulsd 0x307d60, %xmm0\n" /* 43.75 */
        "addss %xmm3, %xmm1\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "mulsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x60(%ebp)\n"
        "cvtss2sd -0x90(%ebp), %xmm0\n" /* line 257 | yawTo */
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x78(%ebp)\n" /* radians */
        /* { scope 2 */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "movss %xmm2, -0xd8(%ebp)\n"
        "calll sinf\n"
        "fstps -0xa8(%ebp)\n"
        "movss -0x78(%ebp), %xmm0\n" /* line 486 | radians */
        "movss %xmm0, (%esp)\n"
        "calll cosf\n"
        "fstps -0xac(%ebp)\n"
        /* } scope */
        "movss 0x2ed6b4, %xmm0\n" /* line 82 | 10.0f */
        "movss -0xd8(%ebp), %xmm2\n"
        "mulss %xmm0, %xmm2\n"
        "movss %xmm2, -0x24(%ebp)\n" /* w */
        "movl 0x195f640, %edx\n" /* line 83 */
        "movl (%edx), %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n" /* h */
        "movss 0x2ed63c, %xmm1\n" /* line 259 | -0.5f */
        "mulss %xmm1, %xmm2\n"
        "addss -0x98(%ebp), %xmm2\n" /* centerX */
        "movss -0x60(%ebp), %xmm3\n"
        "mulss -0xa8(%ebp), %xmm3\n"
        "subss %xmm3, %xmm2\n"
        "movss %xmm2, -0x28(%ebp)\n" /* x */
        "mulss %xmm1, %xmm0\n" /* line 260 */
        "addss -0x94(%ebp), %xmm0\n" /* centerY */
        "movss -0x60(%ebp), %xmm1\n"
        "mulss -0xac(%ebp), %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n" /* y */
        "leal -0x1c(%ebp), %eax\n" /* line 262 | h */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* w */
        "movl %eax, 8(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* y */
        "movl %eax, 4(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* x */
        "movl %eax, (%esp)\n"
        "calll CG_ApplySplitScreenCompassScale\n"
        "movl 0x195f584, %eax\n" /* line 265 */
        "movl (%eax), %ebx\n" /* drawMaterial */
        "movss 0x285cc(%ebx), %xmm0\n" /* drawMaterial */
        "movl -0xbc(%ebp), %eax\n"
        "subss 0x2c5e4(%eax, %ebx), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll AngleNormalize360\n"
        "fstps -0x68(%ebp)\n"
        "movl -0xc(%esi), %eax\n" /* line 267 | cent */
        "movl 0x25bb0(%ebx), %ebx\n" /* drawMaterial */
        "cmpl %ebx, %eax\n" /* drawMaterial */
        "jg .Lf18cfaa_0018db4e\n"
        ".Lf18cfaa_0018d9db:\n"
        "xorl %ecx, %ecx\n" /* line 270 */
        ".Lf18cfaa_0018d9dd:\n"
        "movl -8(%esi), %edx\n" /* line 276 | cent */
        "movl 0x195f674, %eax\n"
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm2\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "mulss 0x2ed5c8, %xmm1\n" /* 1000.0f */
        "addss %xmm1, %xmm0\n"
        "cvtsi2ssl %ebx, %xmm1\n" /* drawMaterial */
        "ucomiss %xmm1, %xmm0\n"
        "jae .Lf18cfaa_0018db89\n"
        "xorl %ebx, %ebx\n" /* drawMaterial */
        ".Lf18cfaa_0018da0e:\n"
        "movl 0x10(%ebp), %edx\n" /* line 456 | color */
        "movl (%edx), %eax\n"
        "movl %eax, -0x40(%ebp)\n" /* baseColorModdedByComapassFadeOut */
        "movl -0x84(%ebp), %edx\n" /* line 457 */
        "movl (%edx), %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl -0x80(%ebp), %edx\n" /* line 458 */
        "movl (%edx), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl -0x7c(%ebp), %eax\n" /* line 459 */
        "movss (%eax), %xmm0\n"
        "movss -0x8c(%ebp), %xmm1\n" /* line 289 | compassFadeOutAlpha */
        "minss %xmm0, %xmm1\n"
        "movss %xmm1, -0x34(%ebp)\n"
        "movss -0x44(%ebp), %xmm0\n" /* line 290 */
        "movss -0x8c(%ebp), %xmm2\n" /* line 291 | compassFadeOutAlpha */
        "movaps %xmm2, %xmm3\n"
        "cmpltss %xmm0, %xmm2\n"
        "andps %xmm2, %xmm3\n"
        "andnps %xmm0, %xmm2\n"
        "orps %xmm3, %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "cmpl $1, %ecx\n" /* line 293 */
        "je .Lf18cfaa_0018dc99\n"
        "testl %ebx, %ebx\n" /* line 299 | drawMaterial */
        "je .Lf18cfaa_0018da84\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "ucomiss -0x44(%ebp), %xmm0\n"
        "jp .Lf18cfaa_0018da84\n"
        "je .Lf18cfaa_0018dadd\n"
        ".Lf18cfaa_0018da84:\n"
        "movl 0x195f5c4, %eax\n" /* line 300 */
        "movl (%eax), %eax\n"
        "movl 0xbc6c(%eax, %ecx, 4), %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "leal -0x40(%ebp), %eax\n" /* baseColorModdedByComapassFadeOut */
        "movl %eax, 0x1c(%esp)\n"
        "movss -0x68(%ebp), %xmm0\n"
        "movss %xmm0, 0x18(%esp)\n"
        "movl 8(%ebp), %edx\n" /* rect */
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* h */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* w */
        "movl %eax, 8(%esp)\n"
        "movl -0x20(%ebp), %eax\n" /* y */
        "movl %eax, 4(%esp)\n"
        "movl -0x28(%ebp), %eax\n" /* x */
        "movl %eax, (%esp)\n"
        "calll CG_DrawRotatedPic\n"
        "testl %ebx, %ebx\n" /* line 302 | drawMaterial */
        "je .Lf18cfaa_0018db24\n"
        ".Lf18cfaa_0018dadd:\n"
        "movl %ebx, 0x20(%esp)\n" /* line 303 | drawMaterial */
        "leal -0x50(%ebp), %eax\n" /* fadedColor */
        "movl %eax, 0x1c(%esp)\n"
        "movss -0x68(%ebp), %xmm0\n"
        "movss %xmm0, 0x18(%esp)\n"
        "movl 8(%ebp), %edx\n" /* rect */
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* h */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* w */
        "movl %eax, 8(%esp)\n"
        "movl -0x20(%ebp), %eax\n" /* y */
        "movl %eax, 4(%esp)\n"
        "movl -0x28(%ebp), %eax\n" /* x */
        "movl %eax, (%esp)\n"
        "calll CG_DrawRotatedPic\n"
        ".Lf18cfaa_0018db24:\n"
        "movl 0x195f584, %edi\n"
        ".Lf18cfaa_0018db2a:\n"
        "addl $1, -0x5c(%ebp)\n" /* line 209 */
        "addl $0x1c, -0xbc(%ebp)\n"
        "addl $0x1c, -0xb8(%ebp)\n"
        "addl $0x1c, %esi\n" /* cent */
        "cmpl $0x40, -0x5c(%ebp)\n"
        "jne .Lf18cfaa_0018d6e5\n"
        "jmp .Lf18cfaa_0018d108\n"
        ".Lf18cfaa_0018db4e:\n"
        "movl %eax, %edi\n" /* line 270 */
        "subl %ebx, %edi\n" /* drawMaterial */
        "movl $0x10624dd3, %edx\n"
        "movl %edi, %eax\n"
        "imull %edx\n"
        "sarl $5, %edx\n"
        "movl %edi, %ecx\n"
        "sarl $0x1f, %ecx\n"
        "subl %ecx, %edx\n"
        "leal (%edx, %edx, 4), %edx\n"
        "leal (%edx, %edx, 4), %edx\n"
        "leal (%edx, %edx, 4), %edx\n"
        "shll $2, %edx\n"
        "subl %edx, %edi\n"
        "cmpl $0xf9, %edi\n"
        "jle .Lf18cfaa_0018d9db\n"
        "movl $1, %ecx\n"
        "jmp .Lf18cfaa_0018d9dd\n"
        ".Lf18cfaa_0018db89:\n"
        "cmpl %edx, %ebx\n" /* line 278 | drawMaterial */
        "jg .Lf18cfaa_0018dbf2\n"
        "movl $0x3f800000, -0x44(%ebp)\n" /* line 279 */
        ".Lf18cfaa_0018db94:\n"
        "movl 0x195f5c4, %eax\n" /* line 283 */
        "movl (%eax), %eax\n"
        "movl 0xc1e0(%eax), %ebx\n" /* drawMaterial */
        "jmp .Lf18cfaa_0018da0e\n"
        ".Lf18cfaa_0018dba6:\n"
        "movl 0x195f644, %edx\n" /* line 250 */
        "movl (%edx), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "maxss %xmm2, %xmm0\n"
        "movaps %xmm0, %xmm2\n"
        "jmp .Lf18cfaa_0018d868\n"
        ".Lf18cfaa_0018dbbf:\n"
        "movl 0x195f654, %ecx\n" /* line 240 */
        "movl (%ecx), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "movaps %xmm2, %xmm1\n" /* line 241 */
        "movaps %xmm2, %xmm3\n"
        "cmpnltss %xmm0, %xmm1\n"
        "andps %xmm1, %xmm3\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm3, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "movl %eax, %edx\n"
        "movaps %xmm0, %xmm1\n"
        "jmp .Lf18cfaa_0018d805\n"
        ".Lf18cfaa_0018dbf2:\n"
        "subl %edx, %ebx\n" /* line 281 | drawMaterial */
        "cvtsi2ssl %ebx, %xmm0\n" /* drawMaterial */
        "mulss 0x2ed96c, %xmm2\n" /* -1000.0f */
        "divss %xmm2, %xmm0\n"
        "addss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x44(%ebp)\n"
        "jmp .Lf18cfaa_0018db94\n"
        ".Lf18cfaa_0018dc13:\n"
        "movl -0xbc(%ebp), %edx\n" /* line 223 */
        "leal 0x2c5dc(%edx, %ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll vectoyaw\n"
        "fstps -0xec(%ebp)\n"
        "movss -0xec(%ebp), %xmm0\n"
        "subss 0x2c5b8(%ebx), %xmm0\n" /* drawMaterial */
        "movss %xmm0, (%esp)\n"
        "calll AngleNormalize360\n"
        "fstps -0x90(%ebp)\n" /* yawTo */
        "movl 0x195f654, %ecx\n" /* line 224 */
        "movl (%ecx), %eax\n"
        "movss 8(%eax), %xmm2\n"
        "movl 0x195f664, %eax\n" /* line 227 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "subss %xmm1, %xmm0\n"
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x44(%ebp)\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "movl 0x195f644, %edx\n"
        "movl (%edx), %eax\n"
        "jmp .Lf18cfaa_0018d868\n"
        ".Lf18cfaa_0018dc99:\n"
        "movl 0x195f5c4, %eax\n" /* line 295 */
        "movl (%eax), %eax\n"
        "movl 0xbc70(%eax), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "leal -0x50(%ebp), %eax\n" /* fadedColor */
        "movl %eax, 0x18(%esp)\n"
        "movl 8(%ebp), %edx\n" /* rect */
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* h */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* w */
        "movl %eax, 8(%esp)\n"
        "movl -0x20(%ebp), %eax\n" /* y */
        "movl %eax, 4(%esp)\n"
        "movl -0x28(%ebp), %eax\n" /* x */
        "movl %eax, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        "movl 0x195f584, %edi\n"
        "jmp .Lf18cfaa_0018db2a\n"
        ".Lf18cfaa_0018dced:\n"
        "movl 0x25bb0(%ebx), %eax\n" /* line 197 | drawMaterial */
        "cmpl %eax, 0x2c5e8(%edx)\n"
        "jg .Lf18cfaa_0018d67e\n"
        "addl $0xbb8, %eax\n" /* line 198 */
        "movl %eax, 0x2c5e8(%edx)\n"
        "jmp .Lf18cfaa_0018d67e\n"
    );
}

