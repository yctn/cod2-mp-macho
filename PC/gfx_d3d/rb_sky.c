/* ASM dump from: rb_sky.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/rb_sky.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/gfx_d3d/rb_backend.h"
 *   #include "PC/universal/com_math.h"
 */

extern SunFlareDynamic sunFlareArray[4]; /* 0x0 */

int RB_CalcSunSpriteSamples(void);
static GfxVertex * RB_SetTessQuad(union GfxColor color);
static GfxVertexDx7 * RB_SetTessQuadDx7(GfxColor color);
static unsigned char RB_TessSunBillboard(float widthInClipSpace, float heightInClipSpace);
unsigned char RB_DrawSunPostEffects(int viewIndex);
unsigned char RB_DrawSun(int viewIndex);

/* line 27 */
__attribute__((naked))
int RB_CalcSunSpriteSamples(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 27 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        /* { scope 1 */
        "movl 0x12184c4, %ebx\n" /* line 42 | occlusionQuery */
        "testl %ebx, %ebx\n" /* line 43 | occlusionQuery */
        "je .Lfde8b4_000de9ff\n"
        ".Lfde8b4_000de8cb:\n"
        "movl 0x195eed0, %eax\n" /* line 50 */
        "movl 8(%eax), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *0xa4(%edx)\n"
        "movl 0x195f0e0, %esi\n"
        "movl (%esi), %edi\n"
        "testl %edi, %edi\n"
        "jne .Lfde8b4_000de8cb\n"
        "movl $0, 0xc(%esp)\n" /* line 51 */
        "movl $0x3f800000, 8(%esp)\n"
        "movl 0x195ed2c, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll RB_ClearScreen\n"
        ".Lfde8b4_000de90f:\n"
        "movl (%ebx), %eax\n" /* line 53 | occlusionQuery */
        "movl $2, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* occlusionQuery */
        "calll *0x18(%eax)\n"
        "movl (%esi), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lfde8b4_000de90f\n"
        "movl $0xa, 0x28(%esp)\n" /* line 54 */
        "movl $0xffffffff, 0x24(%esp)\n"
        "movl $0x3f800000, %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl %eax, 0x1c(%esp)\n"
        "xorl %edx, %edx\n"
        "movl %edx, 0x18(%esp)\n"
        "movl %edx, 0x14(%esp)\n"
        "movl $0x41800000, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl 0x195eebc, %eax\n"
        "movl 0x1038(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_DrawStretchPic\n"
        "calll RB_EndSurface\n" /* line 55 */
        "movl 0x195f0e0, %esi\n"
        ".Lfde8b4_000de97f:\n"
        "movl (%ebx), %eax\n" /* line 56 | occlusionQuery */
        "movl $1, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* occlusionQuery */
        "calll *0x18(%eax)\n"
        "movl (%esi), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lfde8b4_000de97f\n"
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %esi\n"
        ".Lfde8b4_000de9a1:\n"
        "movl 8(%edi), %eax\n" /* line 58 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *0xa8(%edx)\n"
        "movl (%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfde8b4_000de9a1\n"
        "leal -0x1c(%ebp), %esi\n" /* sampleCount */
        "jmp .Lfde8b4_000de9c6\n"
        ".Lfde8b4_000de9ba:\n"
        "movl $0, (%esp)\n" /* line 65 */
        "calll WinSleep\n"
        ".Lfde8b4_000de9c6:\n"
        "movl (%ebx), %eax\n" /* line 62 | occlusionQuery */
        "movl $1, 0xc(%esp)\n"
        "movl $4, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* occlusionQuery */
        "calll *0x1c(%eax)\n"
        "movl %eax, %edx\n"
        "cmpl $1, %eax\n" /* line 63 */
        "je .Lfde8b4_000de9ba\n"
        "movl $0x100, %eax\n" /* line 70 */
        "testl %edx, %edx\n"
        "cmovel -0x1c(%ebp), %eax\n" /* sampleCount */
        "movl %eax, -0x1c(%ebp)\n" /* sampleCount */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 93 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfde8b4_000de9ff:\n"
        "xorl %eax, %eax\n" /* line 43 */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 93 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 170 */
static __attribute__((naked))
GfxVertex * RB_SetTessQuad(union GfxColor color)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 170 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl %eax, -0x10(%ebp)\n"
        /* { scope 1 */
        "movl 0x195f160, %esi\n" /* line 179 */
        "movl 0x5a7d4(%esi), %edi\n"
        "movl 0x5a7d0(%esi), %ebx\n" /* line 180 */
        "movl 0x5a7b0(%esi), %ecx\n"
        "leal 3(%edi), %edx\n"
        "movw %dx, (%ecx, %ebx, 2)\n"
        "movl 0x5a7d0(%esi), %ecx\n" /* line 181 */
        "movl 0x5a7b0(%esi), %edx\n"
        "movw %di, 2(%edx, %ecx, 2)\n"
        "leal 2(%edi), %ebx\n" /* line 182 */
        "movl 0x5a7d0(%esi), %ecx\n"
        "movl 0x5a7b0(%esi), %edx\n"
        "movw %bx, 4(%edx, %ecx, 2)\n"
        "movl 0x5a7d0(%esi), %ecx\n" /* line 183 */
        "movl 0x5a7b0(%esi), %edx\n"
        "movw %bx, 6(%edx, %ecx, 2)\n"
        "movl 0x5a7d0(%esi), %ecx\n" /* line 184 */
        "movl 0x5a7b0(%esi), %edx\n"
        "movw %di, 8(%edx, %ecx, 2)\n"
        "movl 0x5a7d0(%esi), %ebx\n" /* line 185 */
        "movl 0x5a7b0(%esi), %ecx\n"
        "leal 1(%edi), %edx\n"
        "movw %dx, 0xa(%ecx, %ebx, 2)\n"
        "movzwl %di, %eax\n" /* line 187 */
        "shll $6, %eax\n"
        "addl %esi, %eax\n"
        "leal 0x10(%eax), %ebx\n" /* line 189 | v */
        /* { scope 2 */
        "xorl %edx, %edx\n" /* line 191 */
        "movl %edx, 0x10(%eax)\n"
        "movl %edx, 4(%ebx)\n" /* line 192 | v */
        "movl $0x3f800000, %ecx\n" /* line 193 */
        "movl %ecx, 8(%ebx)\n" /* v */
        /* } scope */
        "movl %edx, 0x20(%eax)\n" /* line 30 */
        "movl %edx, 0x24(%eax)\n" /* line 31 */
        "movl -0x10(%ebp), %ebx\n" /* line 191 | v */
        "movl %ebx, 0x1c(%eax)\n" /* v */
        "leal 0x34(%eax), %ebx\n" /* line 192 | v */
        /* { scope 2 */
        "movl %ecx, 0x34(%eax)\n" /* line 191 */
        "movl %edx, 4(%ebx)\n" /* line 192 | v */
        "movl %edx, 8(%ebx)\n" /* line 193 | v */
        /* } scope */
        "leal 0x28(%eax), %ebx\n" /* v */
        /* { scope 2 */
        "movl %edx, 0x28(%eax)\n" /* line 191 */
        "movl %ecx, 4(%ebx)\n" /* line 192 | v */
        "movl %edx, 8(%ebx)\n" /* line 193 | v */
        /* } scope */
        "leal 0x50(%eax), %ebx\n" /* line 195 | v */
        /* { scope 2 */
        "movl %edx, 0x50(%eax)\n" /* line 191 */
        "movl %edx, 4(%ebx)\n" /* line 192 | v */
        "movl %ecx, 8(%ebx)\n" /* line 193 | v */
        /* } scope */
        "movl %ecx, 0x60(%eax)\n" /* line 30 */
        "movl %edx, 0x64(%eax)\n" /* line 31 */
        "movl -0x10(%ebp), %ebx\n" /* line 197 | v */
        "movl %ebx, 0x5c(%eax)\n" /* v */
        "leal 0x74(%eax), %ebx\n" /* line 198 | v */
        /* { scope 2 */
        "movl %ecx, 0x74(%eax)\n" /* line 191 */
        "movl %edx, 4(%ebx)\n" /* line 192 | v */
        "movl %edx, 8(%ebx)\n" /* line 193 | v */
        /* } scope */
        "leal 0x68(%eax), %ebx\n" /* line 199 | v */
        /* { scope 2 */
        "movl %edx, 0x68(%eax)\n" /* line 191 */
        "movl %ecx, 4(%ebx)\n" /* line 192 | v */
        "movl %edx, 8(%ebx)\n" /* line 193 | v */
        /* } scope */
        "leal 0x90(%eax), %ebx\n" /* line 201 | v */
        /* { scope 2 */
        "movl %edx, 0x90(%eax)\n" /* line 191 */
        "movl %edx, 4(%ebx)\n" /* line 192 | v */
        "movl %ecx, 8(%ebx)\n" /* line 193 | v */
        /* } scope */
        "movl %ecx, 0xa0(%eax)\n" /* line 30 */
        "movl %ecx, 0xa4(%eax)\n" /* line 31 */
        "movl -0x10(%ebp), %ebx\n" /* line 203 | v */
        "movl %ebx, 0x9c(%eax)\n" /* v */
        "leal 0xb4(%eax), %ebx\n" /* line 204 | v */
        /* { scope 2 */
        "movl %ecx, 0xb4(%eax)\n" /* line 191 */
        "movl %edx, 4(%ebx)\n" /* line 192 | v */
        "movl %edx, 8(%ebx)\n" /* line 193 | v */
        /* } scope */
        "leal 0xa8(%eax), %ebx\n" /* line 205 | v */
        /* { scope 2 */
        "movl %edx, 0xa8(%eax)\n" /* line 191 */
        "movl %ecx, 4(%ebx)\n" /* line 192 | v */
        "movl %edx, 8(%ebx)\n" /* line 193 | v */
        /* } scope */
        "leal 0xd0(%eax), %ebx\n" /* line 207 | v */
        /* { scope 2 */
        "movl %edx, 0xd0(%eax)\n" /* line 191 */
        "movl %edx, 4(%ebx)\n" /* line 192 | v */
        "movl %ecx, 8(%ebx)\n" /* line 193 | v */
        /* } scope */
        "movl %edx, 0xe0(%eax)\n" /* line 30 */
        "movl %ecx, 0xe4(%eax)\n" /* line 31 */
        "movl -0x10(%ebp), %ebx\n" /* line 209 | v */
        "movl %ebx, 0xdc(%eax)\n" /* v */
        "leal 0xf4(%eax), %ebx\n" /* line 210 | v */
        /* { scope 2 */
        "movl %ecx, 0xf4(%eax)\n" /* line 191 */
        "movl %edx, 4(%ebx)\n" /* line 192 | v */
        "movl %edx, 8(%ebx)\n" /* line 193 | v */
        /* } scope */
        "leal 0xe8(%eax), %ebx\n" /* line 211 | v */
        /* { scope 2 */
        "movl %edx, 0xe8(%eax)\n" /* line 191 */
        "movl %ecx, 4(%ebx)\n" /* line 192 | v */
        "movl %edx, 8(%ebx)\n" /* line 193 | v */
        /* } scope */
        "addl $4, 0x5a7d4(%esi)\n" /* line 213 */
        "addl $6, 0x5a7d0(%esi)\n" /* line 214 */
        /* } scope */
        "addl $4, %esp\n" /* line 217 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 127 */
static __attribute__((naked))
GfxVertexDx7 * RB_SetTessQuadDx7(GfxColor color)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 127 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl %eax, -0x10(%ebp)\n"
        /* { scope 1 */
        "movl 0x195f160, %ecx\n" /* line 136 */
        "movl 0x5a7d4(%ecx), %edi\n"
        "movl 0x5a7d0(%ecx), %esi\n" /* line 137 */
        "movl 0x5a7b0(%ecx), %ebx\n"
        "leal 3(%edi), %edx\n"
        "movw %dx, (%ebx, %esi, 2)\n"
        "movl 0x5a7d0(%ecx), %ebx\n" /* line 138 */
        "movl 0x5a7b0(%ecx), %edx\n"
        "movw %di, 2(%edx, %ebx, 2)\n"
        "leal 2(%edi), %esi\n" /* line 139 */
        "movl 0x5a7d0(%ecx), %ebx\n"
        "movl 0x5a7b0(%ecx), %edx\n"
        "movw %si, 4(%edx, %ebx, 2)\n"
        "movl 0x5a7d0(%ecx), %ebx\n" /* line 140 */
        "movl 0x5a7b0(%ecx), %edx\n"
        "movw %si, 6(%edx, %ebx, 2)\n"
        "movl 0x5a7d0(%ecx), %ebx\n" /* line 141 */
        "movl 0x5a7b0(%ecx), %edx\n"
        "movw %di, 8(%edx, %ebx, 2)\n"
        "movl 0x5a7d0(%ecx), %esi\n" /* line 142 */
        "movl 0x5a7b0(%ecx), %ebx\n"
        "leal 1(%edi), %edx\n"
        "movw %dx, 0xa(%ebx, %esi, 2)\n"
        "movzwl %di, %eax\n" /* line 144 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "leal 0xc(%eax), %esi\n" /* line 146 | v */
        /* { scope 2 */
        "xorl %edx, %edx\n" /* line 191 */
        "movl %edx, 0xc(%eax)\n"
        "movl %edx, 4(%esi)\n" /* line 192 | v */
        "movl $0x3f800000, %ebx\n" /* line 193 */
        "movl %ebx, 8(%esi)\n" /* v */
        /* } scope */
        "movl %edx, 0x1c(%eax)\n" /* line 30 */
        "movl %edx, 0x20(%eax)\n" /* line 31 */
        "movl -0x10(%ebp), %esi\n" /* line 148 | v */
        "movl %esi, 0x18(%eax)\n" /* v */
        "leal 0x30(%eax), %esi\n" /* line 150 | v */
        /* { scope 2 */
        "movl %edx, 0x30(%eax)\n" /* line 191 */
        "movl %edx, 4(%esi)\n" /* line 192 | v */
        "movl %ebx, 8(%esi)\n" /* line 193 | v */
        /* } scope */
        "movl %ebx, 0x40(%eax)\n" /* line 30 */
        "movl %edx, 0x44(%eax)\n" /* line 31 */
        "movl -0x10(%ebp), %esi\n" /* line 152 | v */
        "movl %esi, 0x3c(%eax)\n" /* v */
        "leal 0x54(%eax), %esi\n" /* line 154 | v */
        /* { scope 2 */
        "movl %edx, 0x54(%eax)\n" /* line 191 */
        "movl %edx, 4(%esi)\n" /* line 192 | v */
        "movl %ebx, 8(%esi)\n" /* line 193 | v */
        /* } scope */
        "movl %ebx, 0x64(%eax)\n" /* line 30 */
        "movl %ebx, 0x68(%eax)\n" /* line 31 */
        "movl -0x10(%ebp), %esi\n" /* line 156 | v */
        "movl %esi, 0x60(%eax)\n" /* v */
        "leal 0x78(%eax), %esi\n" /* line 158 | v */
        /* { scope 2 */
        "movl %edx, 0x78(%eax)\n" /* line 191 */
        "movl %edx, 4(%esi)\n" /* line 192 | v */
        "movl %ebx, 8(%esi)\n" /* line 193 | v */
        /* } scope */
        "movl %edx, 0x88(%eax)\n" /* line 30 */
        "movl %ebx, 0x8c(%eax)\n" /* line 31 */
        "movl -0x10(%ebp), %edx\n" /* line 160 */
        "movl %edx, 0x84(%eax)\n"
        "addl $4, 0x5a7d4(%ecx)\n" /* line 162 */
        "addl $6, 0x5a7d0(%ecx)\n" /* line 163 */
        /* } scope */
        "addl $4, %esp\n" /* line 166 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 272 */
static __attribute__((naked))
unsigned char RB_TessSunBillboard(float widthInClipSpace, float heightInClipSpace)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 272 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xc0, %esp\n"
        "movss %xmm0, -0xa4(%ebp)\n"
        "movss %xmm1, -0xa8(%ebp)\n"
        "movl %eax, %esi\n" /* color */
        /* { scope 1: identity */
        "movl 0x195eec0, %eax\n" /* line 282 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfdecc2_000defda\n"
        "movl 0x195eebc, %eax\n" /* line 292 */
        "movl 0x109c(%eax), %eax\n"
        "leal 0x1b4(%eax), %edx\n"
        "movss 0x1b4(%eax), %xmm1\n" /* line 293 */
        "movss 4(%edx), %xmm2\n"
        "movss 8(%edx), %xmm3\n"
        "movl 0x195f0c8, %eax\n"
        "movaps %xmm1, %xmm0\n"
        "mulss 0x3f0(%eax), %xmm0\n"
        "movss %xmm0, -0x98(%ebp)\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 0x400(%eax), %xmm0\n"
        "addss -0x98(%ebp), %xmm0\n"
        "movss %xmm0, -0x98(%ebp)\n"
        "movaps %xmm3, %xmm0\n"
        "mulss 0x410(%eax), %xmm0\n"
        "addss -0x98(%ebp), %xmm0\n"
        "movss %xmm0, -0x98(%ebp)\n"
        "movaps %xmm1, %xmm0\n" /* line 294 */
        "mulss 0x3f4(%eax), %xmm0\n"
        "movss %xmm0, -0x9c(%ebp)\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 0x404(%eax), %xmm0\n"
        "addss -0x9c(%ebp), %xmm0\n"
        "movss %xmm0, -0x9c(%ebp)\n"
        "movaps %xmm3, %xmm0\n"
        "mulss 0x414(%eax), %xmm0\n"
        "addss -0x9c(%ebp), %xmm0\n"
        "movss %xmm0, -0x9c(%ebp)\n"
        "movaps %xmm1, %xmm0\n" /* line 295 */
        "mulss 0x3f8(%eax), %xmm0\n"
        "movss %xmm0, -0xa0(%ebp)\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 0x408(%eax), %xmm0\n"
        "addss -0xa0(%ebp), %xmm0\n"
        "movss %xmm0, -0xa0(%ebp)\n"
        "movaps %xmm3, %xmm0\n"
        "mulss 0x418(%eax), %xmm0\n"
        "addss -0xa0(%ebp), %xmm0\n"
        "movss %xmm0, -0xa0(%ebp)\n"
        "mulss 0x3fc(%eax), %xmm1\n" /* line 296 */
        "mulss 0x40c(%eax), %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "mulss 0x41c(%eax), %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "leal -0x48(%ebp), %ebx\n" /* line 298 | identity, transform */
        "movl %ebx, (%esp)\n" /* transform */
        "movss %xmm1, -0xb8(%ebp)\n"
        "calll MatrixIdentity44\n"
        "movl %ebx, (%esp)\n" /* line 299 | transform */
        "calll RB_SetProjectionMatrix\n"
        "movl %ebx, (%esp)\n" /* line 300 | transform */
        "calll RB_SetViewMatrix\n"
        "movl %esi, %eax\n" /* line 302 | color */
        "calll RB_SetTessQuad\n"
        "movss -0xb8(%ebp), %xmm1\n" /* line 304 */
        "movaps %xmm1, %xmm3\n"
        "mulss 0x2ed670, %xmm3\n" /* -0.0010000000474974513f */
        "movss -0xa8(%ebp), %xmm2\n"
        "mulss %xmm1, %xmm2\n"
        "movss -0xa4(%ebp), %xmm4\n"
        "mulss %xmm1, %xmm4\n"
        "movss -0x98(%ebp), %xmm0\n" /* line 456 */
        "movss %xmm0, (%eax)\n"
        "movss -0x9c(%ebp), %xmm0\n" /* line 457 */
        "movss %xmm0, 4(%eax)\n"
        "movss -0xa0(%ebp), %xmm0\n" /* line 458 */
        "movss %xmm0, 8(%eax)\n"
        "movss %xmm1, 0xc(%eax)\n" /* line 459 */
        "leal 0x40(%eax), %edx\n" /* line 307 */
        "movss -0x98(%ebp), %xmm0\n" /* line 456 */
        "movss %xmm0, 0x40(%eax)\n"
        "movss -0x9c(%ebp), %xmm0\n" /* line 457 */
        "movss %xmm0, 4(%edx)\n"
        "movss -0xa0(%ebp), %xmm0\n" /* line 458 */
        "movss %xmm0, 8(%edx)\n"
        "movss %xmm1, 0xc(%edx)\n" /* line 459 */
        "leal 0x80(%eax), %ecx\n" /* line 308 */
        "movss -0x98(%ebp), %xmm0\n" /* line 456 */
        "movss %xmm0, 0x80(%eax)\n"
        "movss -0x9c(%ebp), %xmm0\n" /* line 457 */
        "movss %xmm0, 4(%ecx)\n"
        "movss -0xa0(%ebp), %xmm0\n" /* line 458 */
        "movss %xmm0, 8(%ecx)\n"
        "movss %xmm1, 0xc(%ecx)\n" /* line 459 */
        "leal 0xc0(%eax), %ebx\n" /* line 309 | transform */
        "movss -0x98(%ebp), %xmm0\n" /* line 456 */
        "movss %xmm0, 0xc0(%eax)\n"
        "movss -0x9c(%ebp), %xmm0\n" /* line 457 */
        "movss %xmm0, 4(%ebx)\n" /* transform */
        "movss -0xa0(%ebp), %xmm0\n" /* line 458 */
        "movss %xmm0, 8(%ebx)\n" /* transform */
        "movss %xmm1, 0xc(%ebx)\n" /* line 459 | transform */
        "movaps %xmm4, %xmm0\n" /* line 311 */
        "addss (%eax), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "movaps %xmm2, %xmm0\n" /* line 312 */
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movaps %xmm3, %xmm0\n" /* line 313 */
        "addss 8(%eax), %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        "movaps %xmm4, %xmm0\n" /* line 315 */
        "addss 0x40(%eax), %xmm0\n"
        "movss %xmm0, 0x40(%eax)\n"
        "movss 4(%edx), %xmm0\n" /* line 316 */
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "movaps %xmm3, %xmm0\n" /* line 317 */
        "addss 8(%edx), %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        "movss 0x80(%eax), %xmm0\n" /* line 319 */
        "subss %xmm4, %xmm0\n"
        "movss %xmm0, 0x80(%eax)\n"
        "movss 4(%ecx), %xmm0\n" /* line 320 */
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, 4(%ecx)\n"
        "movaps %xmm3, %xmm0\n" /* line 321 */
        "addss 8(%ecx), %xmm0\n"
        "movss %xmm0, 8(%ecx)\n"
        "movss 0xc0(%eax), %xmm0\n" /* line 323 */
        "subss %xmm4, %xmm0\n"
        "movss %xmm0, 0xc0(%eax)\n"
        "addss 4(%ebx), %xmm2\n" /* line 324 | transform */
        "movss %xmm2, 4(%ebx)\n" /* transform */
        "addss 8(%ebx), %xmm3\n" /* line 325 | transform */
        "movss %xmm3, 8(%ebx)\n" /* transform */
        /* } scope */
        "addl $0xc0, %esp\n" /* line 326 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: identity */
        /* { scope 2 */
        ".Lfdecc2_000defda:\n"
        "movl 0x195f0c8, %eax\n" /* line 230 */
        "movl 0x3c8(%eax), %edx\n"
        "leal 0xc8(%edx), %ebx\n" /* transform */
        "movl 0x195eebc, %eax\n" /* line 233 */
        "movl 0x109c(%eax), %eax\n"
        "leal 0x1b4(%eax), %ecx\n"
        "movss 0x1b4(%eax), %xmm1\n" /* line 234 */
        "movss 4(%ecx), %xmm2\n"
        "leal 0xd8(%edx), %eax\n"
        "movss 8(%ecx), %xmm3\n"
        "leal 0xe8(%edx), %ecx\n"
        "movaps %xmm1, %xmm0\n"
        "mulss 0xc8(%edx), %xmm0\n"
        "movss %xmm0, -0x8c(%ebp)\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 0xd8(%edx), %xmm0\n"
        "addss -0x8c(%ebp), %xmm0\n"
        "movss %xmm0, -0x8c(%ebp)\n"
        "movaps %xmm3, %xmm0\n"
        "mulss 0xe8(%edx), %xmm0\n"
        "addss -0x8c(%ebp), %xmm0\n"
        "movss %xmm0, -0x8c(%ebp)\n"
        "movaps %xmm1, %xmm0\n" /* line 235 */
        "mulss 4(%ebx), %xmm0\n" /* transform */
        "movss %xmm0, -0x90(%ebp)\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "addss -0x90(%ebp), %xmm0\n"
        "movss %xmm0, -0x90(%ebp)\n"
        "movaps %xmm3, %xmm0\n"
        "mulss 4(%ecx), %xmm0\n"
        "addss -0x90(%ebp), %xmm0\n"
        "movss %xmm0, -0x90(%ebp)\n"
        "movaps %xmm1, %xmm0\n" /* line 236 */
        "mulss 8(%ebx), %xmm0\n" /* transform */
        "movss %xmm0, -0x94(%ebp)\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "addss -0x94(%ebp), %xmm0\n"
        "movss %xmm0, -0x94(%ebp)\n"
        "movaps %xmm3, %xmm0\n"
        "mulss 8(%ecx), %xmm0\n"
        "addss -0x94(%ebp), %xmm0\n"
        "movss %xmm0, -0x94(%ebp)\n"
        "mulss 0xc(%ebx), %xmm1\n" /* line 239 | transform */
        "mulss 0xc(%eax), %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "mulss 0xc(%ecx), %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f, scale */
        "divss %xmm1, %xmm0\n" /* scale */
        /* { scope 3 */
        "movss -0x8c(%ebp), %xmm1\n" /* line 272 */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x8c(%ebp)\n"
        "movss -0x90(%ebp), %xmm1\n" /* line 273 */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x90(%ebp)\n"
        "mulss -0x94(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, -0x94(%ebp)\n"
        /* } scope */
        "leal -0x88(%ebp), %ebx\n" /* line 242 | identity, transform */
        "movl %ebx, (%esp)\n" /* transform */
        "calll MatrixIdentity44\n"
        "movl %ebx, (%esp)\n" /* line 243 | transform */
        "calll RB_SetProjectionMatrix\n"
        "movl %ebx, (%esp)\n" /* line 244 | transform */
        "calll RB_SetViewMatrix\n"
        "movl %esi, %eax\n" /* line 246 */
        "calll RB_SetTessQuadDx7\n"
        "movss -0x8c(%ebp), %xmm0\n" /* line 199 */
        "movss %xmm0, (%eax)\n"
        "movss -0x90(%ebp), %xmm1\n" /* line 200 */
        "movss %xmm1, 4(%eax)\n"
        "movss -0x94(%ebp), %xmm0\n" /* line 201 */
        "movss %xmm0, 8(%eax)\n"
        "leal 0x24(%eax), %edx\n" /* line 249 */
        "movss -0x8c(%ebp), %xmm1\n" /* line 199 */
        "movss %xmm1, 0x24(%eax)\n"
        "movss -0x90(%ebp), %xmm0\n" /* line 200 */
        "movss %xmm0, 4(%edx)\n"
        "movss -0x94(%ebp), %xmm1\n" /* line 201 */
        "movss %xmm1, 8(%edx)\n"
        "leal 0x48(%eax), %ecx\n" /* line 250 */
        "movss -0x8c(%ebp), %xmm0\n" /* line 199 */
        "movss %xmm0, 0x48(%eax)\n"
        "movss -0x90(%ebp), %xmm1\n" /* line 200 */
        "movss %xmm1, 4(%ecx)\n"
        "movss -0x94(%ebp), %xmm0\n" /* line 201 */
        "movss %xmm0, 8(%ecx)\n"
        "leal 0x6c(%eax), %ebx\n" /* line 251 | transform */
        "movss -0x8c(%ebp), %xmm1\n" /* line 199 */
        "movss %xmm1, 0x6c(%eax)\n"
        "movss -0x90(%ebp), %xmm0\n" /* line 200 */
        "movss %xmm0, 4(%ebx)\n"
        "movss -0x94(%ebp), %xmm1\n" /* line 201 */
        "movss %xmm1, 8(%ebx)\n"
        "movss -0xa4(%ebp), %xmm0\n" /* line 253 */
        "addss (%eax), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "movss -0xa8(%ebp), %xmm0\n" /* line 254 */
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movss 8(%eax), %xmm0\n" /* line 255 */
        "movss 0x2ed658, %xmm1\n" /* 0.0010000000474974513f */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        "movss -0xa4(%ebp), %xmm0\n" /* line 257 */
        "addss 0x24(%eax), %xmm0\n"
        "movss %xmm0, 0x24(%eax)\n"
        "movss 4(%edx), %xmm0\n" /* line 258 */
        "subss -0xa8(%ebp), %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "movss 8(%edx), %xmm0\n" /* line 259 */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        "movss 0x48(%eax), %xmm0\n" /* line 261 */
        "subss -0xa4(%ebp), %xmm0\n"
        "movss %xmm0, 0x48(%eax)\n"
        "movss 4(%ecx), %xmm0\n" /* line 262 */
        "subss -0xa8(%ebp), %xmm0\n"
        "movss %xmm0, 4(%ecx)\n"
        "movss 8(%ecx), %xmm0\n" /* line 263 */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%ecx)\n"
        "movss 0x6c(%eax), %xmm0\n" /* line 265 */
        "subss -0xa4(%ebp), %xmm0\n"
        "movss %xmm0, 0x6c(%eax)\n"
        "movss -0xa8(%ebp), %xmm0\n" /* line 266 */
        "addss 4(%ebx), %xmm0\n" /* transform */
        "movss %xmm0, 4(%ebx)\n" /* transform */
        "movss 8(%ebx), %xmm0\n" /* line 267 | transform */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%ebx)\n" /* transform */
        /* } scope */
        /* } scope */
        "addl $0xc0, %esp\n" /* line 326 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 789 */
__attribute__((naked))
unsigned char RB_DrawSunPostEffects(int viewIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 789 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "xorl %edi, %edi\n" /* color */
        "movl $0, -0x2c(%ebp)\n" /* color */
        "movl 8(%ebp), %eax\n" /* viewIndex */
        /* { scope 1: color */
        "leal (%eax, %eax, 2), %eax\n" /* line 796 */
        "shll $4, %eax\n"
        "leal sunFlareArray(%eax), %esi\n" /* sunFlare */
        "movl 0xc(%esi), %eax\n" /* line 798 | sunFlare */
        "testl %eax, %eax\n"
        "je .Lfdf2e0_000df6b0\n"
        "movl 0x195f0c8, %ecx\n"
        "movl 0x3b8(%ecx), %edx\n"
        "cmpl %edx, %eax\n"
        "jle .Lfdf2e0_000df6bb\n"
        ".Lfdf2e0_000df320:\n"
        "movl $0xa, -0x28(%ebp)\n" /* line 801 | frameTime */
        ".Lfdf2e0_000df327:\n"
        "movl 0x3b8(%ecx), %eax\n" /* line 803 */
        "movl %eax, 0xc(%esi)\n" /* sunFlare */
        "movl 0x195f15c, %eax\n" /* line 806 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfdf2e0_000df6a8\n"
        "movl 0x195eebc, %edx\n"
        "movl 0x109c(%edx), %eax\n"
        "cmpb $0, 0x160(%eax)\n"
        "je .Lfdf2e0_000df6a8\n"
        /* { scope 2: sizeIn640x480, alpha */
        "movl 0x168(%eax), %edx\n" /* line 639 */
        "testl %edx, %edx\n"
        "je .Lfdf2e0_000df502\n"
        "movss 0x1c(%esi), %xmm0\n" /* line 642 */
        "movss 0x174(%eax), %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "jae .Lfdf2e0_000df502\n"
        "movss 0x17c(%eax), %xmm3\n" /* line 645 */
        "ucomiss %xmm3, %xmm0\n"
        "jb .Lfdf2e0_000df76c\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        ".Lfdf2e0_000df397:\n"
        "movaps %xmm0, %xmm4\n" /* line 653 */
        "mulss 0x180(%eax), %xmm4\n"
        "mulss 0x178(%eax), %xmm0\n" /* line 654 */
        "movss %xmm0, -0x24(%ebp)\n" /* sizeIn640x480 */
        "addss 0x170(%eax), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* sizeIn640x480 */
        "movl 0x188(%eax), %edx\n" /* line 659 | iFadeOutTime */
        "movl 0x184(%eax), %eax\n" /* iFadeInTime */
        "movss 0x18(%esi), %xmm2\n" /* fGoal */
        "movss (%esi), %xmm3\n"
        /* { scope 3 */
        "ucomiss %xmm3, %xmm2\n" /* line 104 */
        "jbe .Lfdf2e0_000df741\n"
        "testl %eax, %eax\n" /* line 106 */
        "jle .Lfdf2e0_000df3f8\n"
        "cvtsi2ssl -0x28(%ebp), %xmm1\n" /* line 109 | frameTime */
        "cvtsi2ssl %eax, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "addss %xmm3, %xmm1\n"
        "ucomiss %xmm2, %xmm1\n" /* line 110 */
        "jbe .Lfdf2e0_000df7f6\n"
        /* } scope */
        ".Lfdf2e0_000df3f8:\n"
        "movss %xmm2, (%esi)\n" /* line 659 | fGoal */
        "mulss %xmm4, %xmm2\n" /* line 664 */
        "movss %xmm2, -0x20(%ebp)\n" /* alpha */
        /* { scope 3 */
        /* { scope 4: material */
        "movl 0x195f160, %ebx\n" /* line 261 */
        "movl 0x5a7d0(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfdf2e0_000df6e8\n"
        "movl 0x5a7e0(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfdf2e0_000df6e8\n"
        ".Lfdf2e0_000df427:\n"
        "movl 0x195eebc, %edx\n" /* line 262 */
        "movl 0x109c(%edx), %eax\n"
        "movl 0x168(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* material */
        /* { scope 5 */
        "cmpl 0x5a7bc(%ebx), %eax\n" /* line 300 */
        "je .Lfdf2e0_000df7fe\n"
        ".Lfdf2e0_000df448:\n"
        "movl 0x5a7d0(%ebx), %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lfdf2e0_000df6f2\n"
        "movl 0x5a7e0(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfdf2e0_000df6f2\n"
        ".Lfdf2e0_000df464:\n"
        "movl $0x1f, 8(%esp)\n" /* line 303 */
        "movl $3, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* material */
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        /* } scope */
        ".Lfdf2e0_000df47f:\n"
        "calll RB_PushMatrixStack\n" /* line 611 */
        "movss -0x20(%ebp), %xmm0\n" /* line 428 | alpha */
        "mulss 0x2ed5d4, %xmm0\n" /* 255.0f */
        "movss %xmm0, -0x20(%ebp)\n" /* alpha */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x30(%ebp)\n"
        "cvttss2si -0x30(%ebp), %eax\n"
        "movl %edi, %edx\n" /* line 617 | color */
        "movb $0xff, %dl\n"
        "movb %al, %dh\n" /* line 618 */
        "movl %edx, %edi\n" /* color */
        "movzbl %al, %eax\n" /* line 619 */
        "shll $0x10, %eax\n"
        "andl $0xff00ffff, %edi\n" /* color */
        "orl %eax, %edi\n" /* color */
        "shll $8, %eax\n" /* line 620 */
        "andl $0xffffff, %edi\n" /* color */
        "orl %eax, %edi\n" /* color */
        "movl %edi, %eax\n" /* line 624 | color */
        "movss -0x24(%ebp), %xmm1\n" /* sizeIn640x480 */
        "divss 0x2ed840, %xmm1\n" /* 480.0f */
        "movss -0x24(%ebp), %xmm0\n" /* sizeIn640x480 */
        "divss 0x2ed860, %xmm0\n" /* 640.0f */
        "calll RB_TessSunBillboard\n"
        "calll RB_EndSurface\n" /* line 625 */
        "calll RB_PopMatrixStack\n" /* line 627 */
        "movl 0x195f0c8, %ecx\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: sizeIn640x480, alpha */
        /* { scope 3 */
        ".Lfdf2e0_000df502:\n"
        "movl 0x3c8(%ecx), %eax\n" /* line 677 */
        "leal 0xc(%eax), %ecx\n" /* b */
        "movl 0x195eebc, %edx\n" /* a */
        "movl 0x109c(%edx), %ebx\n"
        "leal 0x1b4(%ebx), %edx\n" /* a */
        /* { scope 4: material */
        "movss 0x1b4(%ebx), %xmm4\n" /* line 304 */
        "mulss 0xc(%eax), %xmm4\n"
        "movss 4(%edx), %xmm0\n"
        "mulss 4(%ecx), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "movss 8(%edx), %xmm0\n"
        "mulss 8(%ecx), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        /* } scope */
        "pxor %xmm5, %xmm5\n" /* line 679 */
        "ucomiss 0x194(%ebx), %xmm5\n"
        "jae .Lfdf2e0_000df734\n"
        "movss 0x18c(%ebx), %xmm0\n" /* line 685 */
        "ucomiss %xmm4, %xmm0\n"
        "jb .Lfdf2e0_000df6c5\n"
        "movaps %xmm5, %xmm2\n"
        "movl $0x3f800000, %ecx\n"
        ".Lfdf2e0_000df570:\n"
        "mulss 0x18(%esi), %xmm2\n" /* line 693 */
        "movl 0x19c(%ebx), %edx\n" /* line 696 | iFadeOutTime */
        "movl 0x198(%ebx), %eax\n" /* iFadeInTime */
        "movss 4(%esi), %xmm3\n"
        /* { scope 4: material */
        "ucomiss %xmm3, %xmm2\n" /* line 104 */
        "jbe .Lfdf2e0_000df727\n"
        "testl %eax, %eax\n" /* line 106 */
        "jle .Lfdf2e0_000df5ac\n"
        "cvtsi2ssl -0x28(%ebp), %xmm1\n" /* line 109 | frameTime */
        "cvtsi2ssl %eax, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "addss %xmm3, %xmm1\n"
        "ucomiss %xmm2, %xmm1\n" /* line 110 */
        "ja .Lfdf2e0_000df5ac\n"
        "movaps %xmm1, %xmm2\n"
        /* } scope */
        ".Lfdf2e0_000df5ac:\n"
        "movss %xmm2, 4(%esi)\n" /* line 696 | fGoal */
        "movaps %xmm2, %xmm6\n" /* fGoal */
        "mulss 0x194(%ebx), %xmm6\n"
        "mulss 0x2ed5d4, %xmm6\n" /* 255.0f */
        ".Lfdf2e0_000df5c4:\n"
        "movaps %xmm5, %xmm0\n" /* line 702 */
        "ucomiss 0x1a8(%ebx), %xmm5\n"
        "jae .Lfdf2e0_000df638\n"
        "movss 0x1a0(%ebx), %xmm0\n" /* line 708 */
        "ucomiss %xmm4, %xmm0\n"
        "jb .Lfdf2e0_000df709\n"
        "movaps %xmm5, %xmm2\n"
        ".Lfdf2e0_000df5e4:\n"
        "mulss 0x18(%esi), %xmm2\n" /* line 714 */
        "movl 0x1b0(%ebx), %edx\n" /* line 715 | iFadeOutTime */
        "movl 0x1ac(%ebx), %eax\n" /* iFadeInTime */
        "movss 8(%esi), %xmm3\n"
        /* { scope 4: material */
        "ucomiss %xmm3, %xmm2\n" /* line 104 */
        "jbe .Lfdf2e0_000df6fc\n"
        "testl %eax, %eax\n" /* line 106 */
        "jle .Lfdf2e0_000df620\n"
        "cvtsi2ssl -0x28(%ebp), %xmm1\n" /* line 109 | frameTime */
        "cvtsi2ssl %eax, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "addss %xmm3, %xmm1\n"
        "ucomiss %xmm2, %xmm1\n" /* line 110 */
        "ja .Lfdf2e0_000df620\n"
        "movaps %xmm1, %xmm2\n"
        /* } scope */
        ".Lfdf2e0_000df620:\n"
        "movss %xmm2, 8(%esi)\n" /* line 715 | fGoal */
        "movaps %xmm2, %xmm0\n" /* fGoal */
        "mulss 0x1a8(%ebx), %xmm0\n"
        "mulss 0x2ed5d4, %xmm0\n" /* 255.0f */
        /* } scope */
        ".Lfdf2e0_000df638:\n"
        "cvttss2si %xmm6, %eax\n" /* line 752 */
        "movb %al, -0x2c(%ebp)\n" /* color */
        "cvttss2si %xmm0, %eax\n" /* line 753 */
        "movl -0x2c(%ebp), %edx\n" /* color */
        "movb %al, %dh\n"
        "movzbl %al, %eax\n" /* line 754 */
        "shll $0x10, %eax\n"
        "andl $0xff00ffff, %edx\n"
        "orl %eax, %edx\n"
        "shll $8, %eax\n" /* line 755 */
        "andl $0xffffff, %edx\n"
        "movl %edx, -0x2c(%ebp)\n" /* color */
        "orl %eax, %edx\n"
        "movl %edx, 0x14(%esp)\n" /* line 763 */
        "movl $0x3f800000, 0x10(%esp)\n"
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl 0x195eebc, %edx\n"
        "movl 0x1058(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_DrawFullScreenColoredQuad\n"
        /* } scope */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 811 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1: color */
        /* { scope 2: sizeIn640x480, alpha */
        "jmp RB_EndSurface\n" /* line 764 */
        /* } scope */
        /* } scope */
        ".Lfdf2e0_000df6a8:\n"
        "addl $0x5c, %esp\n" /* line 811 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfdf2e0_000df6b0:\n"
        "movl 0x195f0c8, %ecx\n"
        "jmp .Lfdf2e0_000df320\n"
        /* { scope 1: color */
        ".Lfdf2e0_000df6bb:\n"
        "subl %eax, %edx\n" /* line 801 */
        "movl %edx, -0x28(%ebp)\n" /* frameTime */
        "jmp .Lfdf2e0_000df327\n"
        /* { scope 2: sizeIn640x480, alpha */
        /* { scope 3 */
        ".Lfdf2e0_000df6c5:\n"
        "movss 0x190(%ebx), %xmm1\n" /* line 687 */
        "ucomiss %xmm1, %xmm4\n"
        "jb .Lfdf2e0_000df7c1\n"
        "movl $0x3f800000, %ecx\n"
        "movl %ecx, -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm2\n"
        "jmp .Lfdf2e0_000df570\n"
        /* } scope */
        /* } scope */
        /* { scope 2: sizeIn640x480, alpha */
        /* { scope 3 */
        /* { scope 4: material */
        ".Lfdf2e0_000df6e8:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lfdf2e0_000df427\n"
        /* { scope 5 */
        ".Lfdf2e0_000df6f2:\n"
        "calll RB_EndSurface\n"
        "jmp .Lfdf2e0_000df464\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: sizeIn640x480, alpha */
        /* { scope 3 */
        /* { scope 4: material */
        ".Lfdf2e0_000df6fc:\n"
        "ucomiss %xmm2, %xmm3\n" /* line 113 */
        "ja .Lfdf2e0_000df77d\n"
        "movaps %xmm3, %xmm2\n"
        "jmp .Lfdf2e0_000df620\n"
        /* } scope */
        ".Lfdf2e0_000df709:\n"
        "movss 0x1a4(%ebx), %xmm1\n" /* line 710 */
        "ucomiss %xmm1, %xmm4\n"
        "jb .Lfdf2e0_000df7da\n"
        "movl %ecx, -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm2\n"
        "jmp .Lfdf2e0_000df5e4\n"
        /* { scope 4: material */
        ".Lfdf2e0_000df727:\n"
        "ucomiss %xmm2, %xmm3\n" /* line 113 */
        "ja .Lfdf2e0_000df79f\n"
        "movaps %xmm3, %xmm2\n"
        "jmp .Lfdf2e0_000df5ac\n"
        /* } scope */
        ".Lfdf2e0_000df734:\n"
        "movaps %xmm5, %xmm6\n" /* line 679 */
        "movl $0x3f800000, %ecx\n"
        "jmp .Lfdf2e0_000df5c4\n"
        /* } scope */
        /* } scope */
        /* { scope 2: sizeIn640x480, alpha */
        /* { scope 3 */
        ".Lfdf2e0_000df741:\n"
        "ucomiss %xmm2, %xmm3\n" /* line 113 */
        "jbe .Lfdf2e0_000df7ee\n"
        "testl %edx, %edx\n" /* line 115 */
        "jle .Lfdf2e0_000df3f8\n"
        "cvtsi2ssl -0x28(%ebp), %xmm0\n" /* line 118 | frameTime */
        "cvtsi2ssl %edx, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "subss %xmm0, %xmm3\n"
        "maxss %xmm3, %xmm2\n" /* line 119 */
        "jmp .Lfdf2e0_000df3f8\n"
        /* } scope */
        ".Lfdf2e0_000df76c:\n"
        "subss %xmm2, %xmm0\n" /* line 648 */
        "subss %xmm2, %xmm3\n"
        "divss %xmm3, %xmm0\n"
        "jmp .Lfdf2e0_000df397\n"
        /* } scope */
        /* { scope 2: sizeIn640x480, alpha */
        /* { scope 3 */
        /* { scope 4: material */
        ".Lfdf2e0_000df77d:\n"
        "testl %edx, %edx\n" /* line 115 */
        "jle .Lfdf2e0_000df620\n"
        "cvtsi2ssl -0x28(%ebp), %xmm0\n" /* line 118 | frameTime */
        "cvtsi2ssl %edx, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "subss %xmm0, %xmm3\n"
        "maxss %xmm3, %xmm2\n" /* line 119 */
        "jmp .Lfdf2e0_000df620\n"
        /* } scope */
        /* { scope 4: material */
        ".Lfdf2e0_000df79f:\n"
        "testl %edx, %edx\n" /* line 115 */
        "jle .Lfdf2e0_000df5ac\n"
        "cvtsi2ssl -0x28(%ebp), %xmm0\n" /* line 118 | frameTime */
        "cvtsi2ssl %edx, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "subss %xmm0, %xmm3\n"
        "maxss %xmm3, %xmm2\n" /* line 119 */
        "jmp .Lfdf2e0_000df5ac\n"
        /* } scope */
        ".Lfdf2e0_000df7c1:\n"
        "movaps %xmm4, %xmm2\n" /* line 690 */
        "subss %xmm0, %xmm2\n"
        "subss %xmm0, %xmm1\n"
        "divss %xmm1, %xmm2\n"
        "movl $0x3f800000, %ecx\n"
        "jmp .Lfdf2e0_000df570\n"
        ".Lfdf2e0_000df7da:\n"
        "movaps %xmm4, %xmm2\n" /* line 713 */
        "subss %xmm0, %xmm2\n"
        "subss %xmm0, %xmm1\n"
        "divss %xmm1, %xmm2\n"
        "jmp .Lfdf2e0_000df5e4\n"
        /* } scope */
        /* } scope */
        /* { scope 2: sizeIn640x480, alpha */
        /* { scope 3 */
        ".Lfdf2e0_000df7ee:\n"
        "movaps %xmm3, %xmm2\n" /* line 113 */
        "jmp .Lfdf2e0_000df3f8\n"
        ".Lfdf2e0_000df7f6:\n"
        "movaps %xmm1, %xmm2\n" /* line 110 */
        "jmp .Lfdf2e0_000df3f8\n"
        /* } scope */
        /* { scope 3 */
        /* { scope 4: material */
        /* { scope 5 */
        ".Lfdf2e0_000df7fe:\n"
        "cmpl $3, 0x5a7c0(%ebx)\n" /* line 300 */
        "jne .Lfdf2e0_000df448\n"
        "jmp .Lfdf2e0_000df47f\n"
    );
}

/* line 768 */
__attribute__((naked))
unsigned char RB_DrawSun(int viewIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 768 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xec, %esp\n"
        /* { scope 1: drawnSampleCount */
        "movl 0x195f15c, %eax\n" /* line 776 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfdf810_000dfcd6\n"
        "movl 0x195eebc, %esi\n" /* material */
        "movl 0x109c(%esi), %eax\n" /* material */
        "cmpb $0, 0x160(%eax)\n"
        "je .Lfdf810_000dfcd6\n"
        "movl 0x195f0c8, %ebx\n" /* line 779 | b */
        "cmpb $0, 0x4bd(%ebx)\n" /* b */
        "jne .Lfdf810_000dfd79\n"
        ".Lfdf810_000df859:\n"
        "movl 8(%ebp), %edx\n" /* line 782 | viewIndex */
        "leal (%edx, %edx, 2), %eax\n"
        "shll $4, %eax\n"
        "addl $sunFlareArray, %eax\n"
        "movl %eax, -0x74(%ebp)\n" /* sunFlare */
        /* { scope 2: sunTraceEnd */
        "movl 0x430(%ebx), %eax\n" /* line 403 */
        "leal (%eax, %eax), %edx\n"
        "movl 0x3b0(%ebx), %eax\n"
        "andl $0x80000001, %eax\n"
        "js .Lfdf810_000dffb9\n"
        ".Lfdf810_000df884:\n"
        "leal (%edx, %eax), %edi\n" /* queryIndex */
        "movl -0x74(%ebp), %eax\n" /* line 407 | sunFlare */
        "movl 0x24(%eax, %edi, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfdf810_000dffc7\n"
        "movl 0x195f160, %ebx\n" /* line 261 */
        "movl 0x5a7d0(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfdf810_000dfce1\n"
        "movl 0x5a7e0(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfdf810_000dfce1\n"
        ".Lfdf810_000df8b8:\n"
        "movl 0x195eebc, %eax\n" /* line 262 */
        "movl 0x103c(%eax), %esi\n"
        /* { scope 3: transform */
        "cmpl 0x5a7bc(%ebx), %esi\n" /* line 300 */
        "je .Lfdf810_000e0276\n"
        ".Lfdf810_000df8cf:\n"
        "movl 0x5a7d0(%ebx), %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lfdf810_000dfceb\n"
        "movl 0x5a7e0(%ebx), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lfdf810_000dfceb\n"
        ".Lfdf810_000df8eb:\n"
        "movl $0x1f, 8(%esp)\n" /* line 303 */
        "movl $3, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll RB_BeginSurface\n"
        /* } scope */
        ".Lfdf810_000df903:\n"
        "calll RB_PushMatrixStack\n" /* line 420 */
        "movl 0x195f0c8, %eax\n" /* line 433 */
        "cvtsi2ssl 0x43c(%eax), %xmm1\n"
        "movss 0x2ed6a8, %xmm0\n" /* 16.0f */
        "cvtsi2ssl 0x438(%eax), %xmm2\n"
        "movl $0xff, %eax\n"
        "movaps %xmm0, %xmm3\n"
        "divss %xmm1, %xmm3\n"
        "movaps %xmm3, %xmm1\n"
        "divss %xmm2, %xmm0\n"
        "calll RB_TessSunBillboard\n"
        "movl -0x74(%ebp), %eax\n" /* line 435 | sunFlare */
        "pxor %xmm0, %xmm0\n"
        "cmpb $0, 0x2c(%edi, %eax)\n" /* queryIndex */
        "je .Lfdf810_000df9c7\n"
        "movl $0, -0x1c(%ebp)\n" /* line 437 | drawnSampleCount */
        "leal -0x1c(%ebp), %ebx\n" /* drawnSampleCount */
        "jmp .Lfdf810_000df963\n"
        ".Lfdf810_000df957:\n"
        "movl $0, (%esp)\n" /* line 443 */
        "calll WinSleep\n"
        ".Lfdf810_000df963:\n"
        "movl -0x74(%ebp), %edx\n" /* line 440 | sunFlare */
        "movl 0x24(%edx, %edi, 4), %eax\n"
        "movl (%eax), %edx\n"
        "movl $1, 0xc(%esp)\n"
        "movl $4, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x1c(%edx)\n"
        "cmpl $1, %eax\n" /* line 441 */
        "je .Lfdf810_000df957\n"
        "testl %eax, %eax\n" /* line 447 */
        "je .Lfdf810_000df996\n"
        "movl -0x74(%ebp), %eax\n" /* line 448 | sunFlare */
        "movb $1, 0x10(%eax)\n"
        ".Lfdf810_000df996:\n"
        "movl 0x195eed0, %eax\n" /* line 454 */
        "movl 0x2c2c(%eax), %ecx\n"
        "cmpl -0x1c(%ebp), %ecx\n" /* line 461 | drawnSampleCount */
        "jae .Lfdf810_000df9ad\n"
        "movl -0x74(%ebp), %edx\n" /* line 462 | sunFlare */
        "movb $1, 0x10(%edx)\n"
        ".Lfdf810_000df9ad:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 464 | drawnSampleCount */
        "testl %edx, %edx\n"
        "js .Lfdf810_000e02c0\n"
        "cvtsi2ssl %edx, %xmm1\n"
        ".Lfdf810_000df9bc:\n"
        "cvtsi2ssl %ecx, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        ".Lfdf810_000df9c7:\n"
        "movl 0x195f0c8, %edx\n" /* line 472 */
        "movl 0x430(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lfdf810_000dfcf5\n"
        "movl -0x74(%ebp), %eax\n" /* line 475 | sunFlare */
        "addss 0x14(%eax), %xmm0\n"
        "movss %xmm0, 0x14(%eax)\n"
        "movl 0x434(%edx), %eax\n" /* line 477 */
        "subl $1, %eax\n"
        "cmpl %eax, 0x430(%edx)\n"
        "je .Lfdf810_000dfd21\n"
        ".Lfdf810_000df9fd:\n"
        "movl -0x74(%ebp), %edx\n" /* line 489 | sunFlare */
        "movl 0x24(%edx, %edi, 4), %eax\n"
        "movl (%eax), %edx\n"
        "movl $2, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x18(%edx)\n"
        "calll RB_EndSurface\n" /* line 490 */
        "movl -0x74(%ebp), %edx\n" /* line 491 | sunFlare */
        "movl 0x24(%edx, %edi, 4), %eax\n"
        "movl (%eax), %edx\n"
        "movl $1, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x18(%edx)\n"
        "movl -0x74(%ebp), %eax\n" /* line 492 | sunFlare */
        "movb $1, 0x2c(%edi, %eax)\n" /* queryIndex */
        "calll RB_PopMatrixStack\n" /* line 494 */
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0x80(%ebp)\n"
        /* } scope */
        ".Lfdf810_000dfa46:\n"
        "movl 0x195f0c8, %eax\n" /* line 726 */
        "movl 0x3c8(%eax), %edx\n"
        "leal 0xc(%edx), %ebx\n" /* b */
        "movl 0x195eebc, %esi\n" /* material */
        "movl 0x109c(%esi), %eax\n" /* material */
        "leal 0x1b4(%eax), %ecx\n" /* a */
        /* { scope 2: sunTraceEnd */
        "movss 0x1b4(%eax), %xmm1\n" /* line 304 */
        "mulss 0xc(%edx), %xmm1\n"
        "movss 4(%ecx), %xmm0\n"
        "mulss 4(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%ecx), %xmm0\n"
        "mulss 8(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        /* } scope */
        "movl -0x74(%ebp), %eax\n" /* line 726 | sunFlare */
        "movss %xmm1, 0x1c(%eax)\n"
        "movss -0x80(%ebp), %xmm0\n" /* line 727 */
        "ucomiss %xmm1, %xmm0\n"
        "jae .Lfdf810_000dfcd6\n"
        "movl 0x195eec0, %eax\n" /* line 731 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfdf810_000dfd83\n"
        "movl 0x109c(%esi), %eax\n" /* line 566 | material */
        "leal 0x1b4(%eax), %esi\n" /* material */
        "movl 0x164(%eax), %ebx\n"
        "movl 0x195f160, %eax\n" /* line 300 */
        "cmpl 0x5a7bc(%eax), %ebx\n"
        "je .Lfdf810_000e02a4\n"
        ".Lfdf810_000dfad9:\n"
        "movl 0x5a7d0(%eax), %edi\n" /* line 261 */
        "testl %edi, %edi\n"
        "jne .Lfdf810_000dfd53\n"
        "movl 0x5a7e0(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lfdf810_000dfd53\n"
        ".Lfdf810_000dfaf5:\n"
        "movl $0x1f, 8(%esp)\n" /* line 303 */
        "movl $1, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll RB_BeginSurface\n"
        ".Lfdf810_000dfb0d:\n"
        "movl $0xffffffff, %eax\n" /* line 572 */
        "calll RB_SetTessQuad\n"
        "movl %eax, %edi\n" /* queryIndex */
        "movl 0x195eebc, %eax\n" /* line 574 */
        "movl 0x109c(%eax), %eax\n"
        "movss 0x2ed868, %xmm0\n" /* 0.0013110929867252707f */
        "movss %xmm0, -0x58(%ebp)\n"
        "mulss 0x16c(%eax), %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "leal 8(%esi), %eax\n" /* line 576 | material */
        "movl %eax, -0x5c(%ebp)\n"
        "movss 8(%esi), %xmm0\n" /* material */
        "mulss %xmm0, %xmm0\n"
        "ucomiss 0x2ed858, %xmm0\n" /* 0.9900000095367432f */
        "jbe .Lfdf810_000dfd5d\n"
        "movl $0x3f800000, -0x28(%ebp)\n" /* line 191 */
        "xorl %eax, %eax\n" /* line 192 */
        "movl %eax, -0x24(%ebp)\n"
        "movl %eax, -0x20(%ebp)\n" /* line 193 */
        ".Lfdf810_000dfb69:\n"
        "leal -0x34(%ebp), %ebx\n" /* line 581 */
        "movl %ebx, 8(%esp)\n"
        "leal -0x28(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* material */
        "calll Vec3Cross\n"
        "movl %ebx, (%esp)\n" /* line 582 */
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movss -0x58(%ebp), %xmm0\n" /* line 272 */
        "mulss -0x34(%ebp), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "movss -0x58(%ebp), %xmm0\n" /* line 273 */
        "mulss -0x30(%ebp), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "movss -0x58(%ebp), %xmm0\n" /* line 274 */
        "mulss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "leal -0x40(%ebp), %eax\n" /* line 584 | sunTraceEnd */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* material */
        "movl %ebx, (%esp)\n"
        "calll Vec3Cross\n"
        "movss -0x34(%ebp), %xmm3\n" /* line 240 */
        "movss -0x40(%ebp), %xmm2\n" /* sunTraceEnd */
        "movaps %xmm3, %xmm6\n"
        "addss %xmm2, %xmm6\n"
        "movss -0x30(%ebp), %xmm4\n" /* line 241 */
        "movss -0x3c(%ebp), %xmm1\n"
        "movaps %xmm4, %xmm7\n"
        "addss %xmm1, %xmm7\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 242 */
        "movss -0x2c(%ebp), %xmm5\n"
        "addss %xmm0, %xmm5\n"
        "movss %xmm5, -0x4c(%ebp)\n"
        "subss %xmm2, %xmm3\n" /* line 248 */
        "subss %xmm1, %xmm4\n" /* line 249 */
        "movss -0x2c(%ebp), %xmm5\n" /* line 250 */
        "subss %xmm0, %xmm5\n"
        "movaps %xmm6, %xmm0\n" /* line 240 */
        "addss (%esi), %xmm0\n"
        "movss %xmm0, (%edi)\n"
        "movaps %xmm7, %xmm0\n" /* line 241 */
        "addss 4(%esi), %xmm0\n"
        "movss %xmm0, 4(%edi)\n"
        "movss -0x4c(%ebp), %xmm0\n" /* line 242 */
        "movl -0x5c(%ebp), %eax\n"
        "addss (%eax), %xmm0\n"
        "movss %xmm0, 8(%edi)\n"
        "leal 0x40(%edi), %ebx\n" /* line 589 | queryIndex */
        "movaps %xmm3, %xmm0\n" /* line 240 */
        "addss (%esi), %xmm0\n"
        "movss %xmm0, 0x40(%edi)\n"
        "movaps %xmm4, %xmm0\n" /* line 241 */
        "addss 4(%esi), %xmm0\n"
        "movss %xmm0, 4(%ebx)\n"
        "movaps %xmm5, %xmm0\n" /* line 242 */
        "addss (%eax), %xmm0\n"
        "movss %xmm0, 8(%ebx)\n"
        "leal 0x80(%edi), %ecx\n" /* line 590 | queryIndex */
        "movss (%esi), %xmm0\n" /* line 248 */
        "subss %xmm6, %xmm0\n"
        "movss %xmm0, 0x80(%edi)\n"
        "movss 4(%esi), %xmm0\n" /* line 249 */
        "subss %xmm7, %xmm0\n"
        "movss %xmm0, 4(%ecx)\n"
        "movss (%eax), %xmm0\n" /* line 250 */
        "subss -0x4c(%ebp), %xmm0\n"
        "movss %xmm0, 8(%ecx)\n"
        "leal 0xc0(%edi), %edx\n" /* line 591 | queryIndex */
        "movss (%esi), %xmm0\n" /* line 248 */
        "subss %xmm3, %xmm0\n"
        "movss %xmm0, 0xc0(%edi)\n"
        "movss 4(%esi), %xmm0\n" /* line 249 */
        "subss %xmm4, %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "movss (%eax), %xmm0\n" /* line 250 */
        "subss %xmm5, %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        "xorl %eax, %eax\n" /* line 593 */
        "movl %eax, 0xc(%edi)\n" /* queryIndex */
        "movl %eax, 0xc(%ebx)\n" /* line 594 */
        "movl %eax, 0xc(%ecx)\n" /* line 595 */
        "movl %eax, 0xc(%edx)\n" /* line 596 */
        "calll RB_EndSurface\n" /* line 598 */
        /* } scope */
        ".Lfdf810_000dfcd6:\n"
        "addl $0xec, %esp\n" /* line 786 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: drawnSampleCount */
        /* { scope 2: sunTraceEnd */
        ".Lfdf810_000dfce1:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lfdf810_000df8b8\n"
        /* { scope 3: transform */
        ".Lfdf810_000dfceb:\n"
        "calll RB_EndSurface\n"
        "jmp .Lfdf810_000df8eb\n"
        /* } scope */
        ".Lfdf810_000dfcf5:\n"
        "movl -0x74(%ebp), %eax\n" /* line 473 | sunFlare */
        "movl $0, 0x14(%eax)\n"
        "movl -0x74(%ebp), %eax\n" /* line 475 | sunFlare */
        "addss 0x14(%eax), %xmm0\n"
        "movss %xmm0, 0x14(%eax)\n"
        "movl 0x434(%edx), %eax\n" /* line 477 */
        "subl $1, %eax\n"
        "cmpl %eax, 0x430(%edx)\n"
        "jne .Lfdf810_000df9fd\n"
        ".Lfdf810_000dfd21:\n"
        "movss 0x2ed5d0, %xmm1\n" /* line 480 | 1.0f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lfdf810_000dfd36\n"
        "movl -0x74(%ebp), %edx\n" /* line 481 | sunFlare */
        "movss %xmm1, 0x14(%edx)\n"
        ".Lfdf810_000dfd36:\n"
        "movl -0x74(%ebp), %eax\n" /* line 483 | sunFlare */
        "cmpb $0, 0x10(%eax)\n"
        "jne .Lfdf810_000dfd4a\n"
        "movl %eax, %edx\n" /* line 484 */
        "movl 0x14(%eax), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl -0x74(%ebp), %eax\n" /* sunFlare */
        ".Lfdf810_000dfd4a:\n"
        "movb $0, 0x10(%eax)\n" /* line 486 */
        "jmp .Lfdf810_000df9fd\n"
        /* } scope */
        ".Lfdf810_000dfd53:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lfdf810_000dfaf5\n"
        ".Lfdf810_000dfd5d:\n"
        "movl (%esi), %eax\n" /* line 579 | material */
        "xorl $0x80000000, %eax\n"
        "movl 4(%esi), %edx\n" /* line 191 */
        "movl %edx, -0x28(%ebp)\n"
        "movl %eax, -0x24(%ebp)\n" /* line 192 */
        "movl $0, -0x20(%ebp)\n" /* line 193 */
        "jmp .Lfdf810_000dfb69\n"
        ".Lfdf810_000dfd79:\n"
        "calll RB_Set3D\n" /* line 780 */
        "jmp .Lfdf810_000df859\n"
        ".Lfdf810_000dfd83:\n"
        "movl 0x109c(%esi), %eax\n" /* line 517 | material */
        "leal 0x1b4(%eax), %esi\n" /* material */
        "movl 0x164(%eax), %ebx\n"
        "movl 0x195f160, %eax\n" /* line 300 */
        "cmpl 0x5a7bc(%eax), %ebx\n"
        "je .Lfdf810_000e02d6\n"
        ".Lfdf810_000dfda6:\n"
        "movl 0x5a7d0(%eax), %edx\n" /* line 261 */
        "testl %edx, %edx\n"
        "jne .Lfdf810_000dffaf\n"
        "movl 0x5a7e0(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfdf810_000dffaf\n"
        ".Lfdf810_000dfdc2:\n"
        "movl $0x1f, 8(%esp)\n" /* line 303 */
        "movl $1, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll RB_BeginSurface\n"
        ".Lfdf810_000dfdda:\n"
        "movl $0xffffffff, %eax\n" /* line 523 */
        "calll RB_SetTessQuadDx7\n"
        "movl %eax, %edi\n" /* queryIndex */
        "movl 0x195eebc, %eax\n" /* line 525 */
        "movl 0x109c(%eax), %eax\n"
        "movss 0x2ed868, %xmm3\n" /* 0.0013110929867252707f */
        "movss %xmm3, -0x60(%ebp)\n"
        "mulss 0x16c(%eax), %xmm3\n"
        "movss %xmm3, -0x60(%ebp)\n"
        "leal 8(%esi), %eax\n" /* line 527 | material */
        "movl %eax, -0x64(%ebp)\n"
        "movss 8(%esi), %xmm0\n" /* material */
        "mulss %xmm0, %xmm0\n"
        "ucomiss 0x2ed858, %xmm0\n" /* 0.9900000095367432f */
        "jbe .Lfdf810_000e0288\n"
        "movl $0x3f800000, -0x40(%ebp)\n" /* line 191 | sunTraceEnd */
        "xorl %eax, %eax\n" /* line 192 */
        "movl %eax, -0x3c(%ebp)\n"
        "movl %eax, -0x38(%ebp)\n" /* line 193 */
        ".Lfdf810_000dfe36:\n"
        "leal -0x34(%ebp), %ebx\n" /* line 532 */
        "movl %ebx, 8(%esp)\n"
        "leal -0x40(%ebp), %eax\n" /* sunTraceEnd */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* material */
        "calll Vec3Cross\n"
        "movl %ebx, (%esp)\n" /* line 533 */
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movss -0x60(%ebp), %xmm0\n" /* line 272 */
        "mulss -0x34(%ebp), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "movss -0x60(%ebp), %xmm0\n" /* line 273 */
        "mulss -0x30(%ebp), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "movss -0x60(%ebp), %xmm0\n" /* line 274 */
        "mulss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "leal -0x28(%ebp), %eax\n" /* line 535 */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* material */
        "movl %ebx, (%esp)\n"
        "calll Vec3Cross\n"
        "movss -0x34(%ebp), %xmm3\n" /* line 240 */
        "movss -0x28(%ebp), %xmm2\n"
        "movaps %xmm3, %xmm6\n"
        "addss %xmm2, %xmm6\n"
        "movss -0x30(%ebp), %xmm4\n" /* line 241 */
        "movss -0x24(%ebp), %xmm1\n"
        "movaps %xmm4, %xmm7\n"
        "addss %xmm1, %xmm7\n"
        "movss -0x20(%ebp), %xmm0\n" /* line 242 */
        "movss -0x2c(%ebp), %xmm5\n"
        "addss %xmm0, %xmm5\n"
        "movss %xmm5, -0x50(%ebp)\n"
        "subss %xmm2, %xmm3\n" /* line 248 */
        "subss %xmm1, %xmm4\n" /* line 249 */
        "movss -0x2c(%ebp), %xmm5\n" /* line 250 */
        "subss %xmm0, %xmm5\n"
        "movaps %xmm6, %xmm0\n" /* line 240 */
        "addss (%esi), %xmm0\n"
        "movss %xmm0, (%edi)\n"
        "movaps %xmm7, %xmm0\n" /* line 241 */
        "addss 4(%esi), %xmm0\n"
        "movss %xmm0, 4(%edi)\n"
        "movss -0x50(%ebp), %xmm0\n" /* line 242 */
        "movl -0x64(%ebp), %eax\n"
        "addss (%eax), %xmm0\n"
        "movss %xmm0, 8(%edi)\n"
        "leal 0x24(%edi), %eax\n" /* line 540 | queryIndex */
        "movaps %xmm3, %xmm0\n" /* line 240 */
        "addss (%esi), %xmm0\n"
        "movss %xmm0, 0x24(%edi)\n"
        "movaps %xmm4, %xmm0\n" /* line 241 */
        "addss 4(%esi), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movaps %xmm5, %xmm0\n" /* line 242 */
        "movl -0x64(%ebp), %edx\n"
        "addss (%edx), %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        "leal 0x48(%edi), %eax\n" /* line 541 | queryIndex */
        "movss (%esi), %xmm0\n" /* line 248 */
        "subss %xmm6, %xmm0\n"
        "movss %xmm0, 0x48(%edi)\n"
        "movss 4(%esi), %xmm0\n" /* line 249 */
        "subss %xmm7, %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movss (%edx), %xmm0\n" /* line 250 */
        "subss -0x50(%ebp), %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        "leal 0x6c(%edi), %eax\n" /* line 542 | queryIndex */
        "movss (%esi), %xmm0\n" /* line 248 */
        "subss %xmm3, %xmm0\n"
        "movss %xmm0, 0x6c(%edi)\n"
        "movss 4(%esi), %xmm0\n" /* line 249 */
        "subss %xmm4, %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movss (%edx), %xmm0\n" /* line 250 */
        "subss %xmm5, %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        "movl $0, (%esp)\n" /* line 544 */
        "calll RB_SetViewMatrixForWDx7\n"
        "calll RB_EndSurface\n" /* line 545 */
        "movl $0x3f800000, (%esp)\n" /* line 546 */
        "calll RB_SetViewMatrixForWDx7\n"
        /* } scope */
        "addl $0xec, %esp\n" /* line 786 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: drawnSampleCount */
        ".Lfdf810_000dffaf:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lfdf810_000dfdc2\n"
        /* { scope 2: sunTraceEnd */
        ".Lfdf810_000dffb9:\n"
        "subl $1, %eax\n" /* line 403 */
        "orl $0xfffffffe, %eax\n"
        "addl $1, %eax\n"
        "jmp .Lfdf810_000df884\n"
        /* { scope 3: transform */
        /* { scope 4 */
        ".Lfdf810_000dffc7:\n"
        "movl 0x3c8(%ebx), %ecx\n" /* line 338 */
        "leal 0xc8(%ecx), %edx\n"
        "movl %edx, -0x68(%ebp)\n" /* transform */
        "movl 0x109c(%esi), %eax\n" /* line 341 | vidWidth */
        "leal 0x1b4(%eax), %edx\n"
        "movss 0x1b4(%eax), %xmm2\n" /* line 342 */
        "movss 4(%edx), %xmm5\n"
        "leal 0xd8(%ecx), %eax\n"
        "movl %eax, -0x70(%ebp)\n"
        "movss 8(%edx), %xmm4\n"
        "leal 0xe8(%ecx), %edx\n"
        "movl %edx, -0x6c(%ebp)\n"
        "movaps %xmm2, %xmm3\n"
        "movl -0x68(%ebp), %eax\n" /* transform */
        "mulss 0xc(%eax), %xmm3\n"
        "movaps %xmm5, %xmm0\n"
        "movl -0x70(%ebp), %edx\n"
        "mulss 0xc(%edx), %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "movaps %xmm4, %xmm0\n"
        "movl -0x6c(%ebp), %eax\n"
        "mulss 0xc(%eax), %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "pxor %xmm0, %xmm0\n" /* line 343 */
        "movss %xmm0, -0x80(%ebp)\n"
        "ucomiss %xmm3, %xmm0\n"
        "jae .Lfdf810_000e01a1\n"
        "movl 0x195eeec, %eax\n" /* line 349 */
        "movl (%eax), %esi\n" /* vidWidth */
        "movl 4(%eax), %edi\n" /* line 350 | vidHeight */
        "movaps %xmm2, %xmm0\n" /* line 428 */
        "mulss 0xc8(%ecx), %xmm0\n"
        "movaps %xmm5, %xmm1\n"
        "mulss 0xd8(%ecx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss 0xe8(%ecx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "divss %xmm3, %xmm0\n"
        "addss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "cvtsi2ssl %esi, %xmm1\n" /* material */
        "mulss %xmm1, %xmm0\n"
        "subss 0x2ed6a8, %xmm0\n" /* 16.0f */
        "movss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "mulss %xmm1, %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "movss %xmm1, -0x98(%ebp)\n"
        "movss %xmm2, -0xa8(%ebp)\n"
        "movss %xmm3, -0xb8(%ebp)\n"
        "movss %xmm4, -0xc8(%ebp)\n"
        "movss %xmm5, -0xd8(%ebp)\n"
        "calll floorf\n"
        "fstps -0x78(%ebp)\n"
        "cvttss2si -0x78(%ebp), %ebx\n"
        "movss -0xa8(%ebp), %xmm2\n"
        "movl -0x68(%ebp), %eax\n" /* transform */
        "mulss 4(%eax), %xmm2\n"
        "movss -0xd8(%ebp), %xmm5\n"
        "movl -0x70(%ebp), %edx\n"
        "mulss 4(%edx), %xmm5\n"
        "addss %xmm5, %xmm2\n"
        "movss -0xc8(%ebp), %xmm4\n"
        "movl -0x6c(%ebp), %eax\n"
        "mulss 4(%eax), %xmm4\n"
        "addss %xmm4, %xmm2\n"
        "movss -0xb8(%ebp), %xmm3\n"
        "divss %xmm3, %xmm2\n"
        "addss 0x2ed5d0, %xmm2\n" /* 1.0f */
        "cvtsi2ssl %edi, %xmm0\n" /* queryIndex */
        "mulss %xmm0, %xmm2\n"
        "subss 0x2ed6a8, %xmm2\n" /* 16.0f */
        "movss -0x98(%ebp), %xmm1\n"
        "mulss %xmm1, %xmm2\n"
        "addss %xmm1, %xmm2\n"
        "movss %xmm2, (%esp)\n"
        "calll floorf\n"
        "fstps -0x7c(%ebp)\n"
        "cvttss2si -0x7c(%ebp), %eax\n"
        "leal 0x10(%ebx), %ecx\n" /* line 353 */
        "leal 0x10(%eax), %edx\n" /* line 354 */
        "movl %edx, -0x54(%ebp)\n"
        "xorl %edx, %edx\n" /* line 356 */
        "testl %ebx, %ebx\n"
        "cmovsl %edx, %ebx\n"
        "cmpl %ecx, %esi\n" /* line 358 | vidWidth */
        "cmovll %esi, %ecx\n" /* vidWidth */
        "testl %eax, %eax\n" /* line 360 */
        "cmovsl %edx, %eax\n"
        "cmpl -0x54(%ebp), %edi\n" /* line 362 | vidHeight */
        "cmovgel -0x54(%ebp), %edi\n" /* vidHeight */
        "movl %edi, -0x54(%ebp)\n" /* vidHeight */
        "cmpl %ecx, %ebx\n" /* line 365 */
        "jge .Lfdf810_000e02b6\n"
        "cmpl %edi, %eax\n" /* vidHeight */
        "jge .Lfdf810_000e02b6\n"
        "subl %ebx, %ecx\n" /* line 368 */
        "subl %eax, -0x54(%ebp)\n"
        "imull -0x54(%ebp), %ecx\n"
        "cvtsi2ssl %ecx, %xmm0\n"
        "mulss 0x2ed5c4, %xmm0\n" /* 0.00390625f */
        /* } scope */
        ".Lfdf810_000e01a1:\n"
        "movl -0x74(%ebp), %eax\n" /* line 378 | sunFlare */
        "movss %xmm0, 0x18(%eax)\n"
        "ucomiss -0x80(%ebp), %xmm0\n" /* line 379 */
        "jp .Lfdf810_000e01b5\n"
        "je .Lfdf810_000dfa46\n"
        ".Lfdf810_000e01b5:\n"
        "movl 0x195f0c8, %ebx\n" /* line 382 */
        "movl 0x3c8(%ebx), %edx\n" /* start */
        "movl 0x195eebc, %eax\n"
        "movl 0x109c(%eax), %eax\n"
        "leal 0x1b4(%eax), %ecx\n" /* dir */
        /* { scope 4 */
        "movss 0x2ed864, %xmm1\n" /* line 288 | 262144.0f */
        "movss 0x1b4(%eax), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss (%edx), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n" /* sunTraceEnd */
        "movss 4(%ecx), %xmm0\n" /* line 289 */
        "mulss %xmm1, %xmm0\n"
        "addss 4(%edx), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "mulss 8(%ecx), %xmm1\n" /* line 290 */
        "addss 8(%edx), %xmm1\n"
        "movss %xmm1, -0x38(%ebp)\n"
        /* } scope */
        "movl $0x2003, 0x18(%esp)\n" /* line 383 */
        "movl $0, 0x14(%esp)\n"
        "movl 0x195ed4c, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x40(%ebp), %eax\n" /* sunTraceEnd */
        "movl %eax, 8(%esp)\n"
        "movl 0x3c8(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x74(%ebp), %edx\n" /* sunFlare */
        "movl 0x20(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *0x15c(%eax)\n"
        "movl -0x74(%ebp), %edx\n" /* sunFlare */
        "movl %eax, 0x20(%edx)\n"
        "testl %eax, %eax\n" /* line 384 */
        "je .Lfdf810_000e02e8\n"
        "movl $0, 0x18(%edx)\n" /* line 385 */
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0x80(%ebp)\n"
        "jmp .Lfdf810_000dfa46\n"
        /* } scope */
        /* { scope 3: transform */
        ".Lfdf810_000e0276:\n"
        "cmpl $3, 0x5a7c0(%ebx)\n" /* line 300 */
        "jne .Lfdf810_000df8cf\n"
        "jmp .Lfdf810_000df903\n"
        /* } scope */
        /* } scope */
        ".Lfdf810_000e0288:\n"
        "movl (%esi), %eax\n" /* line 530 | material */
        "xorl $0x80000000, %eax\n"
        "movl 4(%esi), %edx\n" /* line 191 */
        "movl %edx, -0x40(%ebp)\n" /* sunTraceEnd */
        "movl %eax, -0x3c(%ebp)\n" /* line 192 */
        "movl $0, -0x38(%ebp)\n" /* line 193 */
        "jmp .Lfdf810_000dfe36\n"
        ".Lfdf810_000e02a4:\n"
        "cmpl $1, 0x5a7c0(%eax)\n" /* line 300 */
        "jne .Lfdf810_000dfad9\n"
        "jmp .Lfdf810_000dfb0d\n"
        /* { scope 2: sunTraceEnd */
        /* { scope 3: transform */
        /* { scope 4 */
        ".Lfdf810_000e02b6:\n"
        "movss -0x80(%ebp), %xmm0\n" /* line 368 */
        "jmp .Lfdf810_000e01a1\n"
        /* } scope */
        /* } scope */
        ".Lfdf810_000e02c0:\n"
        "movl %edx, %eax\n" /* line 464 */
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "addss %xmm1, %xmm1\n"
        "jmp .Lfdf810_000df9bc\n"
        /* } scope */
        ".Lfdf810_000e02d6:\n"
        "cmpl $1, 0x5a7c0(%eax)\n" /* line 300 */
        "jne .Lfdf810_000dfda6\n"
        "jmp .Lfdf810_000dfdda\n"
        ".Lfdf810_000e02e8:\n"
        "pxor %xmm3, %xmm3\n"
        "movss %xmm3, -0x80(%ebp)\n"
        "jmp .Lfdf810_000dfa46\n"
    );
}

