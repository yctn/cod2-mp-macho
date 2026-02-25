/* ASM dump from: r_buffers.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_buffers.cpp */

#include "common_types.h"
#include "imports.h"

void * R_AllocStaticVertexBuffer(IDirect3DVertexBuffer9 * *vb, int sizeInBytes);
void R_FinishStaticVertexBuffer(IDirect3DVertexBuffer9 *vb);
void R_FreeStaticVertexBuffer(IDirect3DVertexBuffer9 *vb);
void * R_AllocStaticIndexBuffer(IDirect3DIndexBuffer9 * *ib, int sizeInBytes);
void R_FinishStaticIndexBuffer(IDirect3DIndexBuffer9 *ib);
void R_FreeStaticIndexBuffer(IDirect3DIndexBuffer9 *ib);

/* line 101 */
__attribute__((naked))
void * R_AllocStaticVertexBuffer(IDirect3DVertexBuffer9 * *vb, int sizeInBytes)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 101 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %ebx\n" /* vb */
        "movl 0xc(%ebp), %esi\n" /* sizeInBytes */
        /* { scope 1 */
        "movl 0x195eed0, %eax\n" /* line 109 */
        "movl 8(%eax), %eax\n"
        "movl (%eax), %edx\n"
        "movl $0, 0x18(%esp)\n"
        "movl %ebx, 0x14(%esp)\n" /* vb */
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $8, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* sizeInBytes */
        "movl %eax, (%esp)\n"
        "calll *0x68(%edx)\n"
        "testl %eax, %eax\n" /* line 110 */
        "js .Lfe27cc_000e2877\n"
        ".Lfe27cc_000e2816:\n"
        "movl (%ebx), %eax\n" /* line 114 | vb */
        "movl (%eax), %ecx\n"
        "movl $0, 0x10(%esp)\n"
        "leal -0xc(%ebp), %edx\n" /* vertexBufferData */
        "movl %edx, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x2c(%ecx)\n"
        "testl %eax, %eax\n" /* line 115 */
        "js .Lfe27cc_000e284d\n"
        "movl -0xc(%ebp), %eax\n" /* line 116 | vertexBufferData */
        /* } scope */
        "addl $0x30, %esp\n" /* line 119 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe27cc_000e284d:\n"
        "movl %eax, (%esp)\n" /* line 116 */
        "calll R_ErrorDescription\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x224b3c, (%esp)\n" /* "DirectX didn't lock a vertex buffer: %s
" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll R_FatalInitError\n"
        "movl -0xc(%ebp), %eax\n" /* vertexBufferData */
        /* } scope */
        "addl $0x30, %esp\n" /* line 119 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe27cc_000e2877:\n"
        "movl %eax, (%esp)\n" /* line 111 */
        "calll R_ErrorDescription\n"
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* sizeInBytes */
        "movl $0x224b08, (%esp)\n" /* "DirectX didn't create a %i-byte vertex buffer: %s
" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll R_FatalInitError\n"
        "jmp .Lfe27cc_000e2816\n"
    );
}

/* line 122 */
__attribute__((naked))
void R_FinishStaticVertexBuffer(IDirect3DVertexBuffer9 *vb)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 122 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* vb */
        "movl 0x195f0e0, %esi\n"
        ".Lfe28a0_000e28b1:\n"
        "movl (%ebx), %eax\n" /* line 124 | vb */
        "movl %ebx, (%esp)\n" /* vb */
        "calll *0x30(%eax)\n"
        "movl (%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfe28a0_000e28b1\n"
        "addl $0x10, %esp\n" /* line 125 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 128 */
__attribute__((naked))
void R_FreeStaticVertexBuffer(IDirect3DVertexBuffer9 *vb)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 128 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* vb */
        "movl 0x195f0e0, %ebx\n"
        "jmp .Lfe28c6_000e28da\n"
        ".Lfe28c6_000e28d8:\n"
        "xorl %edx, %edx\n" /* line 130 */
        ".Lfe28c6_000e28da:\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        "movl (%ebx), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lfe28c6_000e28d8\n"
        "addl $0x14, %esp\n" /* line 131 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 134 */
__attribute__((naked))
void * R_AllocStaticIndexBuffer(IDirect3DIndexBuffer9 * *ib, int sizeInBytes)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 134 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ib */
        /* { scope 1 */
        "movl 0x195eed0, %eax\n" /* line 142 */
        "movl 8(%eax), %edx\n"
        "movl (%edx), %ecx\n"
        "movl $0, 0x18(%esp)\n"
        "movl %ebx, 0x14(%esp)\n" /* ib */
        "movl $0, 0x10(%esp)\n"
        "movl $0x65, 0xc(%esp)\n"
        "movl $8, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* sizeInBytes */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x6c(%ecx)\n"
        "testl %eax, %eax\n" /* line 143 */
        "js .Lfe28ee_000e2977\n"
        "movl (%ebx), %edx\n" /* line 147 | ib */
        "movl (%edx), %ecx\n"
        "movl $0, 0x10(%esp)\n"
        "leal -0xc(%ebp), %eax\n" /* indexBufferData */
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x2c(%ecx)\n"
        "testl %eax, %eax\n" /* line 148 */
        "js .Lfe28ee_000e296d\n"
        "movl -0xc(%ebp), %eax\n" /* line 154 | indexBufferData */
        /* } scope */
        "addl $0x34, %esp\n" /* line 155 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe28ee_000e296d:\n"
        "movl (%ebx), %eax\n" /* line 150 | ib */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        ".Lfe28ee_000e2977:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x34, %esp\n" /* line 155 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 158 */
__attribute__((naked))
void R_FinishStaticIndexBuffer(IDirect3DIndexBuffer9 *ib)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 158 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ib */
        "movl 0x195f0e0, %esi\n"
        ".Lfe2980_000e2991:\n"
        "movl (%ebx), %eax\n" /* line 160 | ib */
        "movl %ebx, (%esp)\n" /* ib */
        "calll *0x30(%eax)\n"
        "movl (%esi), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lfe2980_000e2991\n"
        "addl $0x10, %esp\n" /* line 161 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 164 */
__attribute__((naked))
void R_FreeStaticIndexBuffer(IDirect3DIndexBuffer9 *ib)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 164 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* ib */
        "movl 0x195f0e0, %ebx\n"
        "jmp .Lfe29a6_000e29ba\n"
        ".Lfe29a6_000e29b8:\n"
        "xorl %edx, %edx\n" /* line 166 */
        ".Lfe29a6_000e29ba:\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        "movl (%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfe29a6_000e29b8\n"
        "addl $0x14, %esp\n" /* line 167 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

