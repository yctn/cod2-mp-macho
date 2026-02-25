/* ASM dump from: com_convexhull.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/universal/com_convexhull.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

static int Com_RecursivelyGrowHull(vec2_t *points, int firstIndex, int secondIndex, vec2_t *hull, int hullPointCount);
int Com_ConvexHull(vec2_t *points, int pointCount, vec2_t *hull);

/* line 75 */
static __attribute__((naked))
int Com_RecursivelyGrowHull(vec2_t *points, int firstIndex, int secondIndex, vec2_t *hull, int hullPointCount)
{
    __asm__ __volatile__ (
        ".Lffb844_000fb844:\n"
        "pushl %ebp\n" /* line 75 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl %edx, %esi\n" /* pointCount */
        "movl %ecx, -0x44(%ebp)\n"
        /* { scope 1: newIndex */
        "movl 0xc(%ebp), %eax\n" /* line 86 | hull */
        "leal (%eax, %ecx, 8), %ebx\n"
        "movl 8(%ebp), %edx\n" /* secondIndex */
        "leal (%eax, %edx, 8), %eax\n"
        "movss 4(%ebx), %xmm0\n"
        "subss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* edgeEq */
        "movss (%eax), %xmm0\n" /* line 87 */
        "subss (%ebx), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "leal -0x24(%ebp), %eax\n" /* line 88 | edgeEq */
        "movl %eax, (%esp)\n"
        "calll Vec2Normalize\n"
        "fstp %st(0)\n"
        "movss -0x24(%ebp), %xmm3\n" /* line 89 | edgeEq */
        "movaps %xmm3, %xmm0\n"
        "mulss (%ebx), %xmm0\n"
        "movss -0x20(%ebp), %xmm2\n"
        "movaps %xmm2, %xmm1\n"
        "mulss 4(%ebx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl %esi, %edi\n" /* line 95 | pointCount, topIndex */
        "subl $1, %edi\n" /* topIndex */
        "js .Lffb844_000fb9f0\n"
        "movl $0, -0x3c(%ebp)\n" /* botIndex */
        "movss 0x2ed658, %xmm5\n" /* 0.0010000000474974513f */
        "movl $0xffffffff, -0x38(%ebp)\n" /* frontIndex */
        "pxor %xmm6, %xmm6\n"
        ".Lffb844_000fb8d1:\n"
        "movss -0x1c(%ebp), %xmm4\n" /* line 99 */
        "movl -0x3c(%ebp), %eax\n" /* botIndex */
        "movl -0x40(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %ebx\n"
        ".Lffb844_000fb8df:\n"
        "leal 4(%ebx), %eax\n"
        "movaps %xmm3, %xmm1\n"
        "mulss (%ebx), %xmm1\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 4(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "ucomiss %xmm1, %xmm6\n" /* line 100 */
        "jae .Lffb844_000fba0c\n"
        "ucomiss %xmm5, %xmm1\n" /* line 102 */
        "jbe .Lffb844_000fb910\n"
        "movaps %xmm1, %xmm5\n"
        "movl -0x3c(%ebp), %ecx\n" /* botIndex */
        "movl %ecx, -0x38(%ebp)\n" /* frontIndex */
        ".Lffb844_000fb910:\n"
        "addl $1, -0x3c(%ebp)\n" /* line 107 | botIndex */
        "addl $8, %ebx\n"
        "cmpl -0x3c(%ebp), %edi\n" /* line 108 | botIndex, topIndex */
        "jge .Lffb844_000fb8df\n"
        ".Lffb844_000fb91c:\n"
        "movl -0x38(%ebp), %ecx\n" /* line 140 | frontIndex */
        "testl %ecx, %ecx\n"
        "js .Lffb844_000fb9f0\n"
        "cmpl -0x38(%ebp), %edi\n" /* line 11 | frontIndex */
        "je .Lffb844_000fb9fb\n"
        "movl -0x38(%ebp), %ecx\n" /* line 13 | frontIndex */
        "movl -0x40(%ebp), %eax\n"
        "leal (%eax, %ecx, 8), %edx\n"
        "movl (%edx), %ecx\n" /* line 37 */
        "movl 4(%edx), %ebx\n" /* line 38 */
        "leal (%eax, %edi, 8), %esi\n" /* line 14 */
        "movl (%esi), %eax\n" /* line 37 */
        "movl %eax, (%edx)\n"
        "leal 4(%esi), %eax\n" /* line 38 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl %ecx, (%esi)\n" /* line 37 */
        "movl %ebx, 4(%esi)\n" /* line 38 */
        ".Lffb844_000fb956:\n"
        "movl -0x44(%ebp), %edx\n" /* line 145 */
        "addl $1, %edx\n"
        "movl %edx, -0x30(%ebp)\n" /* newIndex */
        /* { scope 2 */
        "movl 0xc(%ebp), %ecx\n" /* line 68 | hull */
        "leal (%ecx, %edx, 8), %ebx\n"
        "movl 0x10(%ebp), %eax\n" /* hullPointCount */
        "subl %edx, %eax\n"
        "shll $3, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "leal 8(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll memmove\n"
        "movl (%esi), %eax\n" /* line 37 */
        "movl %eax, (%ebx)\n"
        "movl -0x2c(%ebp), %edx\n" /* line 38 */
        "movl (%edx), %eax\n"
        "movl %eax, 4(%ebx)\n"
        "addl $1, 0x10(%ebp)\n" /* line 70 | hullPointCount */
        /* } scope */
        "testl %edi, %edi\n" /* line 147 | topIndex */
        "je .Lffb844_000fb9f0\n"
        "movl -0x44(%ebp), %eax\n" /* line 152 */
        "addl $2, %eax\n"
        "movl 8(%ebp), %edx\n" /* secondIndex */
        "testl %edx, %edx\n"
        "cmovel 8(%ebp), %eax\n" /* secondIndex */
        "movl %eax, 8(%ebp)\n" /* secondIndex */
        "movl 0x10(%ebp), %ecx\n" /* line 153 | hullPointCount */
        "movl %ecx, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* hull */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* secondIndex */
        "movl %edx, (%esp)\n"
        "movl -0x30(%ebp), %ecx\n" /* newIndex */
        "movl %edi, %edx\n" /* topIndex */
        "movl -0x40(%ebp), %eax\n"
        "calll Com_RecursivelyGrowHull\n"
        "movl %eax, 8(%esp)\n" /* line 154 */
        "movl 0xc(%ebp), %ecx\n" /* hull */
        "movl %ecx, 4(%esp)\n"
        "movl -0x30(%ebp), %eax\n" /* newIndex */
        "movl %eax, (%esp)\n"
        "movl -0x44(%ebp), %ecx\n"
        "movl %edi, %edx\n" /* topIndex */
        "movl -0x40(%ebp), %eax\n"
        "calll Com_RecursivelyGrowHull\n"
        "movl %eax, 0x10(%ebp)\n" /* hullPointCount */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 156 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lffb844_000fb9f0:\n"
        "movl 0x10(%ebp), %eax\n" /* hullPointCount */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: newIndex */
        ".Lffb844_000fb9fb:\n"
        "movl -0x40(%ebp), %eax\n" /* line 11 */
        "leal (%eax, %edi, 8), %esi\n"
        "leal 4(%esi), %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "jmp .Lffb844_000fb956\n"
        ".Lffb844_000fba0c:\n"
        "movl -0x40(%ebp), %edx\n" /* line 109 */
        "leal (%edx, %edi, 8), %esi\n" /* pointCount */
        ".Lffb844_000fba12:\n"
        "leal 4(%esi), %ecx\n" /* pointCount */
        "movl %ecx, -0x34(%ebp)\n"
        "movaps %xmm3, %xmm1\n" /* line 115 */
        "mulss (%esi), %xmm1\n" /* pointCount */
        "movaps %xmm2, %xmm0\n"
        "mulss 4(%esi), %xmm0\n" /* pointCount */
        "addss %xmm0, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "ucomiss %xmm6, %xmm1\n" /* line 116 */
        "ja .Lffb844_000fba44\n"
        "subl $1, %edi\n" /* line 125 | topIndex */
        "subl $8, %esi\n" /* pointCount */
        "cmpl -0x3c(%ebp), %edi\n" /* line 126 | botIndex, topIndex */
        "jge .Lffb844_000fba12\n"
        "jmp .Lffb844_000fb91c\n"
        ".Lffb844_000fba44:\n"
        "ucomiss %xmm5, %xmm1\n" /* line 118 */
        "ja .Lffb844_000fba86\n"
        ".Lffb844_000fba49:\n"
        "cmpl -0x3c(%ebp), %edi\n" /* line 11 | botIndex */
        "je .Lffb844_000fba67\n"
        "movl (%ebx), %edx\n" /* line 37 */
        "movl (%eax), %ecx\n" /* line 38 */
        "movl (%esi), %eax\n" /* line 37 */
        "movl %eax, (%ebx)\n"
        "movl -0x34(%ebp), %eax\n" /* line 38 */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, 4(%ebx)\n"
        "movl %edx, (%esi)\n" /* line 37 */
        "movl %ecx, 4(%esi)\n" /* line 38 */
        ".Lffb844_000fba67:\n"
        "addl $1, -0x3c(%ebp)\n" /* line 132 | botIndex */
        "subl $1, %edi\n" /* line 133 | topIndex */
        "cmpl %edi, -0x3c(%ebp)\n" /* line 95 | topIndex, botIndex */
        "jg .Lffb844_000fb91c\n"
        "movss -0x24(%ebp), %xmm3\n" /* edgeEq */
        "movss -0x20(%ebp), %xmm2\n"
        "jmp .Lffb844_000fb8d1\n"
        ".Lffb844_000fba86:\n"
        "movaps %xmm1, %xmm5\n" /* line 118 */
        "movl -0x3c(%ebp), %edx\n" /* botIndex */
        "movl %edx, -0x38(%ebp)\n" /* frontIndex */
        "jmp .Lffb844_000fba49\n"
    );
}

/* line 285 */
__attribute__((naked))
int Com_ConvexHull(vec2_t *points, int pointCount, vec2_t *hull)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 285 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        /* { scope 1: pointIndex1, pointIndex1 */
        "cmpl $1, 0xc(%ebp)\n" /* line 32 | pointCount */
        "jg .Lffba92_000fbdf4\n"
        "movl 8(%ebp), %esi\n" /* points */
        "movl %esi, %edi\n"
        "movl $0, -0x30(%ebp)\n"
        "movl $0, -0x2c(%ebp)\n"
        ".Lffba92_000fbab8:\n"
        "movl (%edi), %eax\n" /* line 37 */
        "movl 0x10(%ebp), %ecx\n" /* hull */
        "movl %eax, (%ecx)\n"
        "movl 4(%edi), %eax\n" /* line 38 */
        "movl %eax, 4(%ecx)\n"
        "addl $8, %ecx\n" /* line 42 */
        "movl %ecx, -0x5c(%ebp)\n"
        "movl (%esi), %eax\n" /* line 37 */
        "movl 0x10(%ebp), %edx\n" /* hull */
        "movl %eax, 8(%edx)\n"
        "addl $0xc, %edx\n" /* line 38 */
        "movl %edx, -0x58(%ebp)\n"
        "movl 4(%esi), %eax\n"
        "movl 0x10(%ebp), %ecx\n" /* hull */
        "movl %eax, 0xc(%ecx)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 44 */
        "cmpl %eax, -0x30(%ebp)\n"
        "jle .Lffba92_000fbd9a\n"
        "movl 0xc(%ebp), %eax\n" /* line 49 | pointCount, pointIndex1 */
        "subl $1, %eax\n" /* pointIndex1 */
        /* { scope 2 */
        "cmpl %eax, -0x30(%ebp)\n" /* line 11 */
        "je .Lffba92_000fbb17\n"
        "movss (%edi), %xmm0\n" /* line 37 */
        "movl 4(%edi), %ebx\n" /* line 38 */
        "movl 8(%ebp), %ecx\n" /* line 14 | points */
        "leal (%ecx, %eax, 8), %edx\n"
        "movl (%edx), %eax\n" /* line 37 */
        "movl %eax, (%edi)\n"
        "movl 4(%edx), %eax\n" /* line 38 */
        "movl %eax, 4(%edi)\n"
        "movss %xmm0, (%edx)\n" /* line 37 */
        "movl %ebx, 4(%edx)\n" /* line 38 */
        /* } scope */
        ".Lffba92_000fbb17:\n"
        "movl 0xc(%ebp), %edi\n" /* line 50 | pointCount */
        "subl $2, %edi\n"
        "movl %edi, -0x54(%ebp)\n" /* pointIndex1 */
        /* { scope 2 */
        "cmpl %edi, -0x2c(%ebp)\n" /* line 11 */
        "je .Lffba92_000fbb3f\n"
        "movl (%esi), %ecx\n" /* line 37 */
        "movl 4(%esi), %ebx\n" /* line 38 */
        "movl 8(%ebp), %eax\n" /* line 14 | points */
        "leal (%eax, %edi, 8), %edx\n"
        "movl (%edx), %eax\n" /* line 37 */
        "movl %eax, (%esi)\n"
        "movl 4(%edx), %eax\n" /* line 38 */
        "movl %eax, 4(%esi)\n"
        "movl %ecx, (%edx)\n" /* line 37 */
        "movl %ebx, 4(%edx)\n" /* line 38 */
        /* } scope */
        /* } scope */
        /* { scope 1: pointIndex1, pointIndex1 */
        ".Lffba92_000fbb3f:\n"
        "movl -0x5c(%ebp), %edx\n" /* line 179 */
        "movss 4(%edx), %xmm0\n"
        "movl 0x10(%ebp), %ecx\n" /* hull */
        "subss 4(%ecx), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* edgeEq */
        "movss (%ecx), %xmm0\n" /* line 180 */
        "subss (%edx), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "leal -0x24(%ebp), %eax\n" /* line 181 | edgeEq */
        "movl %eax, (%esp)\n"
        "calll Vec2Normalize\n"
        "fstp %st(0)\n"
        "movss -0x24(%ebp), %xmm3\n" /* line 182 | edgeEq */
        "movaps %xmm3, %xmm0\n"
        "movl 0x10(%ebp), %esi\n" /* hull */
        "mulss (%esi), %xmm0\n"
        "movss -0x20(%ebp), %xmm2\n"
        "movaps %xmm2, %xmm1\n"
        "mulss 4(%esi), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl 0xc(%ebp), %edi\n" /* line 190 | pointCount */
        "subl $3, %edi\n"
        "js .Lffba92_000fbd88\n"
        "movl $0, -0x38(%ebp)\n"
        "movss 0x2ed658, %xmm5\n" /* 0.0010000000474974513f */
        "movl $0xffffffff, -0x48(%ebp)\n" /* pointIndex1 */
        "movss 0x2ed670, %xmm6\n" /* -0.0010000000474974513f */
        "movl $0xffffffff, -0x34(%ebp)\n"
        "pxor %xmm7, %xmm7\n"
        ".Lffba92_000fbbc8:\n"
        "movss -0x1c(%ebp), %xmm4\n" /* line 194 */
        "movl -0x38(%ebp), %eax\n"
        "movl 8(%ebp), %edx\n" /* points */
        "leal (%edx, %eax, 8), %ebx\n"
        ".Lffba92_000fbbd6:\n"
        "leal 4(%ebx), %eax\n"
        "movaps %xmm3, %xmm1\n"
        "mulss (%ebx), %xmm1\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 4(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "ucomiss %xmm1, %xmm7\n" /* line 195 */
        "ja .Lffba92_000fbe94\n"
        "ucomiss %xmm5, %xmm1\n" /* line 204 */
        "jbe .Lffba92_000fbc07\n"
        "movaps %xmm1, %xmm5\n"
        "movl -0x38(%ebp), %esi\n"
        "movl %esi, -0x48(%ebp)\n" /* pointIndex1 */
        ".Lffba92_000fbc07:\n"
        "addl $1, -0x38(%ebp)\n" /* line 209 */
        "addl $8, %ebx\n"
        "cmpl %edi, -0x38(%ebp)\n" /* line 210 */
        "jle .Lffba92_000fbbd6\n"
        ".Lffba92_000fbc13:\n"
        "movl -0x48(%ebp), %eax\n" /* line 247 | pointIndex1 */
        "testl %eax, %eax\n"
        "js .Lffba92_000fbe6d\n"
        ".Lffba92_000fbc1e:\n"
        "cmpl -0x48(%ebp), %edi\n" /* line 11 | pointIndex1 */
        "je .Lffba92_000fbf11\n"
        "movl -0x48(%ebp), %ecx\n" /* line 13 | pointIndex1 */
        "movl 8(%ebp), %esi\n" /* points */
        "leal (%esi, %ecx, 8), %edx\n"
        "movl (%edx), %ecx\n" /* line 37 */
        "movl 4(%edx), %ebx\n" /* line 38 */
        "leal (%esi, %edi, 8), %esi\n" /* line 14 */
        "movl (%esi), %eax\n" /* line 37 */
        "movl %eax, (%edx)\n"
        "leal 4(%esi), %eax\n" /* line 38 */
        "movl %eax, -0x3c(%ebp)\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl %ecx, (%esi)\n" /* line 37 */
        "movl %ebx, 4(%esi)\n" /* line 38 */
        ".Lffba92_000fbc4d:\n"
        "movl 0x10(%ebp), %edx\n" /* line 68 | hull */
        "addl $0x10, %edx\n"
        "movl %edx, -0x40(%ebp)\n"
        "movl (%esi), %eax\n" /* line 37 */
        "movl 0x10(%ebp), %ecx\n" /* hull */
        "movl %eax, 0x10(%ecx)\n"
        "movl -0x3c(%ebp), %esi\n" /* line 38 */
        "movl (%esi), %eax\n"
        "movl %eax, 4(%edx)\n"
        "testl %edi, %edi\n" /* line 259 */
        "jle .Lffba92_000fbef4\n"
        "movl $3, 8(%esp)\n" /* line 261 */
        "movl 0x10(%ebp), %eax\n" /* hull */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "movl $2, %ecx\n"
        "movl %edi, %edx\n"
        "movl 8(%ebp), %eax\n" /* points */
        "calll Com_RecursivelyGrowHull\n"
        "movl %eax, 8(%esp)\n" /* line 262 */
        "movl 0x10(%ebp), %edx\n" /* hull */
        "movl %edx, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "movl $1, %ecx\n"
        "movl %edi, %edx\n"
        "movl 8(%ebp), %eax\n" /* points */
        "calll Com_RecursivelyGrowHull\n"
        "movl %eax, -0x50(%ebp)\n" /* hullPointCount */
        ".Lffba92_000fbcb7:\n"
        "movl -0x34(%ebp), %ebx\n" /* line 265 */
        "testl %ebx, %ebx\n"
        "js .Lffba92_000fbd8f\n"
        "movl -0x50(%ebp), %ecx\n" /* hullPointCount */
        "subl $1, %ecx\n"
        "movl %ecx, -0x44(%ebp)\n"
        "addl $1, -0x50(%ebp)\n" /* hullPointCount */
        /* { scope 2 */
        ".Lffba92_000fbccf:\n"
        "movl -0x34(%ebp), %esi\n" /* line 11 */
        "cmpl %esi, -0x38(%ebp)\n"
        "je .Lffba92_000fbf00\n"
        "movl %esi, %ecx\n"
        "movl 8(%ebp), %esi\n" /* line 13 | points */
        "leal (%esi, %ecx, 8), %edx\n"
        "movl (%edx), %ecx\n" /* line 37 */
        "movl 4(%edx), %ebx\n" /* line 38 */
        "movl -0x38(%ebp), %edi\n" /* line 14 */
        "leal (%esi, %edi, 8), %esi\n"
        "movl (%esi), %eax\n" /* line 37 */
        "movl %eax, (%edx)\n"
        "leal 4(%esi), %edi\n" /* line 38 */
        "movl 4(%esi), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl %ecx, (%esi)\n" /* line 37 */
        "movl %ebx, 4(%esi)\n" /* line 38 */
        /* } scope */
        ".Lffba92_000fbd00:\n"
        "movl -0x44(%ebp), %eax\n" /* line 68 */
        "shll $3, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x5c(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x40(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll memmove\n"
        "movl (%esi), %eax\n" /* line 37 */
        "movl -0x5c(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "movl (%edi), %eax\n" /* line 38 */
        "movl -0x58(%ebp), %ecx\n"
        "movl %eax, (%ecx)\n"
        "movl -0x38(%ebp), %edi\n" /* line 273 */
        "subl %edi, -0x54(%ebp)\n" /* pointIndex1 */
        "movl -0x54(%ebp), %edi\n" /* pointIndex1 */
        "subl $1, %edi\n"
        "testl %edi, %edi\n"
        "jle .Lffba92_000fbd8f\n"
        "leal 8(%esi), %ebx\n" /* line 275 */
        "movl -0x50(%ebp), %eax\n" /* hullPointCount */
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* hull */
        "movl %edx, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "movl $1, %ecx\n"
        "movl %edi, %edx\n"
        "movl %ebx, %eax\n"
        "calll Com_RecursivelyGrowHull\n"
        "movl %eax, 8(%esp)\n" /* line 276 */
        "movl 0x10(%ebp), %ecx\n" /* hull */
        "movl %ecx, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "xorl %ecx, %ecx\n"
        "movl %edi, %edx\n"
        "movl %ebx, %eax\n"
        "calll Com_RecursivelyGrowHull\n"
        "movl %eax, -0x50(%ebp)\n" /* hullPointCount */
        /* } scope */
        "addl $0x7c, %esp\n" /* line 289 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: pointIndex1, pointIndex1 */
        ".Lffba92_000fbd88:\n"
        "movl $0, -0x50(%ebp)\n" /* line 276 | hullPointCount */
        ".Lffba92_000fbd8f:\n"
        "movl -0x50(%ebp), %eax\n" /* hullPointCount */
        /* } scope */
        "addl $0x7c, %esp\n" /* line 289 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: pointIndex1, pointIndex1 */
        ".Lffba92_000fbd9a:\n"
        "movl 0xc(%ebp), %eax\n" /* line 55 | pointCount, pointIndex1 */
        "subl $1, %eax\n" /* pointIndex1 */
        /* { scope 2 */
        "cmpl %eax, -0x2c(%ebp)\n" /* line 11 */
        "je .Lffba92_000fbdc3\n"
        "movss (%esi), %xmm0\n" /* line 37 */
        "movl 4(%esi), %ebx\n" /* line 38 */
        "movl 8(%ebp), %ecx\n" /* line 14 | points */
        "leal (%ecx, %eax, 8), %edx\n"
        "movl (%edx), %eax\n" /* line 37 */
        "movl %eax, (%esi)\n"
        "movl 4(%edx), %eax\n" /* line 38 */
        "movl %eax, 4(%esi)\n"
        "movss %xmm0, (%edx)\n" /* line 37 */
        "movl %ebx, 4(%edx)\n" /* line 38 */
        /* } scope */
        ".Lffba92_000fbdc3:\n"
        "movl 0xc(%ebp), %esi\n" /* line 56 | pointCount */
        "subl $2, %esi\n"
        "movl %esi, -0x54(%ebp)\n" /* pointIndex1 */
        "cmpl %esi, -0x30(%ebp)\n" /* line 11 */
        "je .Lffba92_000fbb3f\n"
        "movl (%edi), %ecx\n" /* line 37 */
        "movl 4(%edi), %ebx\n" /* line 38 */
        "movl 8(%ebp), %eax\n" /* line 14 | points */
        "leal (%eax, %esi, 8), %edx\n"
        "movl (%edx), %eax\n" /* line 37 */
        "movl %eax, (%edi)\n"
        "movl 4(%edx), %eax\n" /* line 38 */
        "movl %eax, 4(%edi)\n"
        "movl %ecx, (%edx)\n" /* line 37 */
        "movl %ebx, 4(%edx)\n" /* line 38 */
        "jmp .Lffba92_000fbb3f\n"
        ".Lffba92_000fbdf4:\n"
        "movl 8(%ebp), %eax\n" /* line 32 | points */
        "addl $8, %eax\n"
        "movl $1, %ecx\n"
        "movl $0, -0x30(%ebp)\n"
        "movl $0, -0x2c(%ebp)\n"
        "movl $8, %ebx\n"
        "jmp .Lffba92_000fbe34\n"
        ".Lffba92_000fbe14:\n"
        "movl -0x30(%ebp), %edx\n" /* line 36 */
        "movss 4(%edi, %edx, 8), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "cmoval %ecx, %edx\n"
        "movl %edx, -0x30(%ebp)\n"
        "addl $1, %ecx\n" /* line 32 */
        "addl $8, %eax\n"
        "addl $8, %ebx\n"
        "cmpl %ecx, 0xc(%ebp)\n" /* pointCount */
        "je .Lffba92_000fbe5f\n"
        ".Lffba92_000fbe34:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 34 */
        "movl 8(%ebp), %edi\n" /* points */
        "leal (%edi, %edx, 8), %esi\n"
        "movl %edi, %edx\n"
        "addl %ebx, %edx\n"
        "movss 4(%eax), %xmm1\n"
        "ucomiss 4(%esi), %xmm1\n"
        "jb .Lffba92_000fbe14\n"
        "movl %ecx, -0x2c(%ebp)\n"
        "movl %edx, %esi\n"
        "addl $1, %ecx\n" /* line 32 */
        "addl $8, %eax\n"
        "addl $8, %ebx\n"
        "cmpl %ecx, 0xc(%ebp)\n" /* pointCount */
        "jne .Lffba92_000fbe34\n"
        ".Lffba92_000fbe5f:\n"
        "movl -0x30(%ebp), %eax\n"
        "movl 8(%ebp), %edx\n" /* points */
        "leal (%edx, %eax, 8), %edi\n"
        "jmp .Lffba92_000fbab8\n"
        /* } scope */
        /* { scope 1: pointIndex1, pointIndex1 */
        ".Lffba92_000fbe6d:\n"
        "movl -0x34(%ebp), %esi\n" /* line 247 */
        "testl %esi, %esi\n"
        "js .Lffba92_000fbd88\n"
        "movl 0x10(%ebp), %ecx\n" /* hull */
        "addl $0x10, %ecx\n"
        "movl %ecx, -0x40(%ebp)\n"
        "movl $1, -0x44(%ebp)\n"
        "movl $3, -0x50(%ebp)\n" /* hullPointCount */
        "jmp .Lffba92_000fbccf\n"
        ".Lffba92_000fbe94:\n"
        "ucomiss %xmm1, %xmm6\n" /* line 197 */
        "jbe .Lffba92_000fbf22\n"
        "movl -0x38(%ebp), %ecx\n"
        "movl %ecx, -0x34(%ebp)\n"
        ".Lffba92_000fbea3:\n"
        "movl 8(%ebp), %edx\n" /* line 211 | points */
        "leal (%edx, %edi, 8), %esi\n"
        "movaps %xmm1, %xmm6\n"
        ".Lffba92_000fbeac:\n"
        "leal 4(%esi), %ecx\n"
        "movl %ecx, -0x4c(%ebp)\n"
        "movaps %xmm3, %xmm1\n" /* line 217 */
        "mulss (%esi), %xmm1\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 4(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "ucomiss %xmm7, %xmm1\n" /* line 218 */
        "ja .Lffba92_000fbf2a\n"
        "ucomiss %xmm1, %xmm6\n" /* line 227 */
        "jbe .Lffba92_000fbed9\n"
        "movaps %xmm1, %xmm6\n"
        "movl %edi, -0x34(%ebp)\n"
        ".Lffba92_000fbed9:\n"
        "subl $1, %edi\n" /* line 232 */
        "subl $8, %esi\n"
        "cmpl -0x38(%ebp), %edi\n" /* line 233 */
        "jge .Lffba92_000fbeac\n"
        "movl -0x48(%ebp), %eax\n" /* line 247 | pointIndex1 */
        "testl %eax, %eax\n"
        "jns .Lffba92_000fbc1e\n"
        "jmp .Lffba92_000fbe6d\n"
        ".Lffba92_000fbef4:\n"
        "movl $3, -0x50(%ebp)\n" /* line 259 | hullPointCount */
        "jmp .Lffba92_000fbcb7\n"
        /* { scope 2 */
        ".Lffba92_000fbf00:\n"
        "movl -0x38(%ebp), %edi\n" /* line 11 */
        "movl 8(%ebp), %eax\n" /* points */
        "leal (%eax, %edi, 8), %esi\n"
        "leal 4(%esi), %edi\n"
        "jmp .Lffba92_000fbd00\n"
        /* } scope */
        ".Lffba92_000fbf11:\n"
        "movl 8(%ebp), %eax\n" /* points */
        "leal (%eax, %edi, 8), %esi\n"
        "leal 4(%esi), %edx\n"
        "movl %edx, -0x3c(%ebp)\n"
        "jmp .Lffba92_000fbc4d\n"
        ".Lffba92_000fbf22:\n"
        "movaps %xmm6, %xmm1\n" /* line 211 */
        "jmp .Lffba92_000fbea3\n"
        ".Lffba92_000fbf2a:\n"
        "ucomiss %xmm5, %xmm1\n" /* line 220 */
        "ja .Lffba92_000fbf7c\n"
        ".Lffba92_000fbf2f:\n"
        "cmpl -0x38(%ebp), %edi\n" /* line 11 */
        "je .Lffba92_000fbf4d\n"
        "movl (%ebx), %edx\n" /* line 37 */
        "movl (%eax), %ecx\n" /* line 38 */
        "movl (%esi), %eax\n" /* line 37 */
        "movl %eax, (%ebx)\n"
        "movl -0x4c(%ebp), %eax\n" /* line 38 */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, 4(%ebx)\n"
        "movl %edx, (%esi)\n" /* line 37 */
        "movl %ecx, 4(%esi)\n" /* line 38 */
        ".Lffba92_000fbf4d:\n"
        "movl -0x38(%ebp), %eax\n" /* line 239 */
        "cmpl %eax, -0x34(%ebp)\n"
        "movl -0x34(%ebp), %edx\n"
        "cmovel %edi, %edx\n"
        "movl %edx, -0x34(%ebp)\n"
        "addl $1, %eax\n" /* line 241 */
        "movl %eax, -0x38(%ebp)\n"
        "subl $1, %edi\n" /* line 242 */
        "cmpl %edi, %eax\n" /* line 190 */
        "jg .Lffba92_000fbc13\n"
        "movss -0x24(%ebp), %xmm3\n" /* edgeEq */
        "movss -0x20(%ebp), %xmm2\n"
        "jmp .Lffba92_000fbbc8\n"
        ".Lffba92_000fbf7c:\n"
        "movaps %xmm1, %xmm5\n" /* line 220 */
        "movl -0x38(%ebp), %edx\n"
        "movl %edx, -0x48(%ebp)\n" /* pointIndex1 */
        "jmp .Lffba92_000fbf2f\n"
    );
}

