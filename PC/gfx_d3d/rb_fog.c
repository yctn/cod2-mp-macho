/* ASM dump from: rb_fog.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/rb_fog.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/gfx_d3d/rb_backend.h"
 *   #include "PC/universal/com_vector.h"
 */

GfxFogOffset RB_FogOffset(void);
int RB_UpdateFogColor(FogColorSrcEnum fogColorSrc);
int RB_SetIteratorFog(void);

/* line 8 */
__attribute__((naked))
GfxFogOffset RB_FogOffset(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 8 */
        "movl %esp, %ebp\n"
        "movl 0x195f234, %eax\n" /* line 13 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lffb30c_000fb32b\n"
        "movl 0x195f188, %eax\n" /* line 19 */
        "movl (%eax), %eax\n"
        "movl 0x219cec(%eax), %eax\n"
        "popl %ebp\n" /* line 20 */
        "retl\n"
        ".Lffb30c_000fb32b:\n"
        "xorl %eax, %eax\n" /* line 13 */
        "popl %ebp\n" /* line 20 */
        "retl\n"
    );
}

/* line 140 */
__attribute__((naked))
int RB_UpdateFogColor(FogColorSrcEnum fogColorSrc)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 140 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl 0x195eec8, %eax\n" /* line 175 */
        "movl 0x150c(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lffb330_000fb3b5\n"
        "movl 8(%ebp), %edx\n" /* line 177 | fogColorSrc */
        "testl %edx, %edx\n"
        "jne .Lffb330_000fb3bd\n"
        "movl 0x195f138, %edx\n" /* line 179 */
        "movl 0x2000(%edx), %eax\n"
        "andl $0xf0, %eax\n"
        "cmpl $0x20, %eax\n"
        "je .Lffb330_000fb3d1\n"
        ".Lffb330_000fb365:\n"
        "movl 0x195f0c8, %eax\n" /* line 192 */
        "movl 0x4c8(%eax), %ebx\n" /* fogColor */
        ".Lffb330_000fb370:\n"
        "orl $0xff000000, %ebx\n" /* line 196 | fogColor */
        "cmpl %ebx, 0x2158(%edx)\n" /* line 198 | fogColor */
        "je .Lffb330_000fb3b5\n"
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %esi\n"
        ".Lffb330_000fb38a:\n"
        "movl 8(%edi), %eax\n" /* line 208 */
        "movl (%eax), %edx\n"
        "movl %ebx, 8(%esp)\n" /* fogColor */
        "movl $0x22, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl (%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lffb330_000fb38a\n"
        "movl 0x195f138, %eax\n" /* line 212 */
        "movl %ebx, 0x2158(%eax)\n" /* fogColor */
        /* } scope */
        ".Lffb330_000fb3b5:\n"
        "addl $0x1c, %esp\n" /* line 215 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lffb330_000fb3bd:\n"
        "cmpl $2, 8(%ebp)\n" /* line 185 | fogColorSrc */
        "je .Lffb330_000fb3cb\n"
        "movl 0x195f138, %edx\n"
        "jmp .Lffb330_000fb365\n"
        ".Lffb330_000fb3cb:\n"
        "movl 0x195f138, %edx\n"
        ".Lffb330_000fb3d1:\n"
        "xorl %ebx, %ebx\n" /* line 187 | fogColor */
        "jmp .Lffb330_000fb370\n"
    );
}

/* line 23 */
__attribute__((naked))
int RB_SetIteratorFog(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 23 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 0x195f160, %eax\n" /* line 44 */
        "cmpl $3, 0x5a7c0(%eax)\n"
        "je .Lffb3d6_000fb568\n"
        "movl 0x195f188, %eax\n" /* line 52 */
        "movl (%eax), %eax\n"
        "leal 0x219cec(%eax), %esi\n" /* fog */
        "movl 0x219cec(%eax), %edi\n" /* line 55 */
        "testl %edi, %edi\n"
        "je .Lffb3d6_000fb568\n"
        "cmpb $0, 0x1c(%esi)\n" /* line 58 | fog */
        "je .Lffb3d6_000fb568\n"
        "movl 0xc(%esi), %edx\n" /* line 66 | fog */
        "movl 0x195f0c8, %ecx\n"
        "movl %edx, 0x4c8(%ecx)\n"
        /* { scope 2 */
        "movl 0x195eec8, %eax\n" /* line 175 */
        "movl 0x150c(%eax), %ebx\n" /* fogColor */
        "testl %ebx, %ebx\n" /* fogColor */
        "je .Lffb3d6_000fb49b\n"
        "movl 0x195f138, %edi\n" /* line 179 */
        "movl 0x2000(%edi), %eax\n"
        "andl $0xf0, %eax\n"
        "cmpl $0x20, %eax\n"
        "je .Lffb3d6_000fb61a\n"
        "movl %edx, %ebx\n" /* line 192 | fogColor */
        ".Lffb3d6_000fb450:\n"
        "orl $0xff000000, %ebx\n" /* line 196 | fogColor */
        "cmpl %ebx, 0x2158(%edi)\n" /* line 198 | fogColor */
        "je .Lffb3d6_000fb49b\n"
        "movl 0x195f0e0, %edi\n"
        ".Lffb3d6_000fb464:\n"
        "movl 0x195eed0, %edx\n" /* line 208 */
        "movl 8(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "movl %ebx, 8(%esp)\n" /* fogColor */
        "movl $0x22, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl (%edi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lffb3d6_000fb464\n"
        "movl 0x195f138, %eax\n" /* line 212 */
        "movl %ebx, 0x2158(%eax)\n" /* fogColor */
        "movl 0x195f0c8, %ecx\n"
        /* } scope */
        ".Lffb3d6_000fb49b:\n"
        "movzbl 0xd(%esi), %eax\n" /* line 79 | fog */
        "cvtsi2ssl %eax, %xmm4\n"
        "movss 0x2ed5cc, %xmm1\n" /* 0.003921568859368563f */
        "mulss %xmm1, %xmm4\n"
        "movzbl 0xc(%esi), %eax\n" /* line 80 | fog */
        "cvtsi2ssl %eax, %xmm3\n"
        "mulss %xmm1, %xmm3\n"
        "movzbl 0xf(%esi), %eax\n" /* line 81 | fog */
        "cvtsi2ssl %eax, %xmm2\n"
        "mulss %xmm1, %xmm2\n"
        "leal 0x1d0(%ecx), %edx\n" /* line 275 | to */
        /* { scope 2 */
        "movzbl 0xe(%esi), %eax\n" /* line 456 | fog */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 0x1d0(%ecx)\n"
        "movss %xmm4, 4(%edx)\n" /* line 457 */
        "movss %xmm3, 8(%edx)\n" /* line 458 */
        "movss %xmm2, 0xc(%edx)\n" /* line 459 */
        /* } scope */
        "movl 0x195f1c4, %eax\n" /* line 89 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm3\n"
        "ucomiss 0x2ed5e8, %xmm3\n" /* 0.0f */
        "jne .Lffb3d6_000fb50c\n"
        "jp .Lffb3d6_000fb50c\n"
        "movss 0x14(%esi), %xmm3\n" /* fog */
        ".Lffb3d6_000fb50c:\n"
        "movss %xmm3, -0x1c(%ebp)\n" /* end */
        "movaps %xmm3, %xmm0\n" /* line 90 */
        "subss 0x10(%esi), %xmm0\n" /* fog */
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "divss %xmm0, %xmm1\n"
        "movss 0x2f2ec0, %xmm0\n" /* line 94 */
        "movss 0x18(%esi), %xmm2\n" /* fog */
        "xorps %xmm0, %xmm2\n"
        "leal 0x1c0(%ecx), %eax\n" /* line 275 | to */
        /* { scope 2 */
        "xorps %xmm1, %xmm0\n" /* line 456 */
        "movss %xmm0, 0x1c0(%ecx)\n"
        "mulss %xmm1, %xmm3\n" /* line 457 */
        "movss %xmm3, 4(%eax)\n"
        "movss %xmm2, 8(%eax)\n" /* line 458 */
        "movl $0, 0xc(%eax)\n" /* line 459 */
        /* } scope */
        "movl 0x195eec0, %eax\n" /* line 99 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lffb3d6_000fb570\n"
        /* } scope */
        ".Lffb3d6_000fb568:\n"
        "addl $0x2c, %esp\n" /* line 136 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lffb3d6_000fb570:\n"
        "cmpl $1, (%esi)\n" /* line 101 | fog */
        "je .Lffb3d6_000fb621\n"
        "movl 0x195f138, %edi\n" /* line 123 */
        "cmpl $1, 0x215c(%edi)\n"
        "je .Lffb3d6_000fb5c8\n"
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %ebx\n"
        ".Lffb3d6_000fb594:\n"
        "movl 8(%edi), %eax\n" /* line 125 */
        "movl (%eax), %edx\n"
        "movl $1, 8(%esp)\n"
        "movl $0x8c, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl (%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lffb3d6_000fb594\n"
        "movl 0x195f138, %edi\n" /* line 126 */
        "movl $1, 0x215c(%edi)\n"
        ".Lffb3d6_000fb5c8:\n"
        "movss 0x2168(%edi), %xmm0\n" /* line 128 */
        "ucomiss 0x18(%esi), %xmm0\n" /* fog */
        "jp .Lffb3d6_000fb5d8\n"
        "je .Lffb3d6_000fb568\n"
        ".Lffb3d6_000fb5d8:\n"
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %ebx\n"
        ".Lffb3d6_000fb5e4:\n"
        "movl 8(%edi), %eax\n" /* line 130 */
        "movl (%eax), %ecx\n"
        "movl 0x18(%esi), %edx\n" /* fog */
        "movl %edx, 8(%esp)\n"
        "movl $0x26, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%ecx)\n"
        "movl (%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lffb3d6_000fb5e4\n"
        "movl 0x18(%esi), %edx\n" /* line 131 | fog */
        "movl 0x195f138, %eax\n"
        "movl %edx, 0x2168(%eax)\n"
        "jmp .Lffb3d6_000fb568\n"
        /* { scope 2 */
        ".Lffb3d6_000fb61a:\n"
        "xorl %ebx, %ebx\n" /* line 187 | fogColor */
        "jmp .Lffb3d6_000fb450\n"
        /* } scope */
        ".Lffb3d6_000fb621:\n"
        "movl 0x195f138, %edi\n" /* line 103 */
        "cmpl $3, 0x215c(%edi)\n"
        "je .Lffb3d6_000fb670\n"
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %ebx\n"
        ".Lffb3d6_000fb63c:\n"
        "movl 8(%edi), %eax\n" /* line 105 */
        "movl (%eax), %edx\n"
        "movl $3, 8(%esp)\n"
        "movl $0x8c, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%edx)\n"
        "movl (%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lffb3d6_000fb63c\n"
        "movl 0x195f138, %edi\n" /* line 106 */
        "movl $3, 0x215c(%edi)\n"
        ".Lffb3d6_000fb670:\n"
        "movss 0x2160(%edi), %xmm0\n" /* line 108 */
        "ucomiss 0x10(%esi), %xmm0\n" /* fog */
        "jp .Lffb3d6_000fb6d8\n"
        "jne .Lffb3d6_000fb6d8\n"
        ".Lffb3d6_000fb680:\n"
        "movss 0x2164(%edi), %xmm0\n" /* line 113 */
        "ucomiss -0x1c(%ebp), %xmm0\n" /* end */
        "jp .Lffb3d6_000fb694\n"
        "je .Lffb3d6_000fb568\n"
        ".Lffb3d6_000fb694:\n"
        "leal -0x1c(%ebp), %edi\n" /* end */
        "movl 0x195eed0, %esi\n" /* fog */
        "movl 0x195f0e0, %ebx\n"
        ".Lffb3d6_000fb6a3:\n"
        "movl 8(%esi), %eax\n" /* line 115 | fog */
        "movl (%eax), %ecx\n"
        "movl (%edi), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $0x25, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%ecx)\n"
        "movl (%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lffb3d6_000fb6a3\n"
        "movl -0x1c(%ebp), %edx\n" /* line 116 | end */
        "movl 0x195f138, %eax\n"
        "movl %edx, 0x2164(%eax)\n"
        "jmp .Lffb3d6_000fb568\n"
        ".Lffb3d6_000fb6d8:\n"
        "movl 0x195eed0, %edi\n"
        "movl 0x195f0e0, %ebx\n"
        ".Lffb3d6_000fb6e4:\n"
        "movl 8(%edi), %eax\n" /* line 110 */
        "movl (%eax), %ecx\n"
        "movl 0x10(%esi), %edx\n" /* fog */
        "movl %edx, 8(%esp)\n"
        "movl $0x24, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%ecx)\n"
        "movl (%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lffb3d6_000fb6e4\n"
        "movl 0x195f138, %edi\n" /* line 111 */
        "movl 0x10(%esi), %eax\n" /* fog */
        "movl %eax, 0x2160(%edi)\n"
        "jmp .Lffb3d6_000fb680\n"
    );
}

