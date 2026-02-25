/* ASM dump from: r_xsurface.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_xsurface.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

int XSurfaceGetNumVerts(const XSurface *surface);
int XSurfaceGetNumTris(const XSurface *surface);
long unsigned int XSurfaceGetTris(const XSurface *surface, r_index_t *dstIndices, int offset);
XVertexInfo * XSurfaceGetVertexInfoArray(const XSurface *surf);
int XSurfaceGetBoneOffset(const XSurface *surf);
long unsigned int XSurfaceTransferDx7(const XVertexBuffer *surfVerts, GfxVertexDx7 *verts, int vertCount);
long unsigned int XSurfaceTransfer(const XVertexBuffer *surfVerts, GfxVertex *verts, int vertCount);
long unsigned int XSurfaceGetVerts(const XSurface *surf, DObjSkelMat *boneMatrix, float *pVert, float *pTexCoord, float *pNormal);

/* line 39 */
__attribute__((naked))
int XSurfaceGetNumVerts(const XSurface *surface)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 39 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* surface */
        "movswl 2(%eax), %eax\n" /* surface */
        "popl %ebp\n" /* line 42 */
        "retl\n"
    );
}

/* line 45 */
__attribute__((naked))
int XSurfaceGetNumTris(const XSurface *surface)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 45 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* surface */
        "movswl 4(%eax), %eax\n" /* surface */
        "popl %ebp\n" /* line 48 */
        "retl\n"
    );
}

/* line 51 */
__attribute__((naked))
long unsigned int XSurfaceGetTris(const XSurface *surface, r_index_t *dstIndices, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 51 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* surface */
        "movl 0x10(%ebp), %eax\n" /* offset */
        "testw %ax, %ax\n" /* line 60 */
        "je .Lffa2d4_000fa32f\n"
        /* { scope 1 */
        "movzwl %ax, %eax\n" /* line 67 */
        "movl %eax, %ebx\n" /* twoOffsets */
        "shll $0x10, %ebx\n" /* twoOffsets */
        "orl %eax, %ebx\n" /* twoOffsets */
        "movl 0xc(%ebp), %ecx\n" /* line 68 | dstIndices */
        "movl 8(%esi), %edx\n" /* line 69 | surface */
        "movzwl 4(%esi), %eax\n" /* line 70 | surface */
        "sarw $1, %ax\n"
        "movswl %ax, %edi\n" /* numMoves */
        "xorl %esi, %esi\n" /* surface */
        ".Lffa2d4_000fa304:\n"
        "movl %ebx, %eax\n" /* line 73 | twoOffsets */
        "addl (%edx), %eax\n"
        "movl %eax, (%ecx)\n"
        "movl %ebx, %eax\n" /* line 74 | twoOffsets */
        "addl 4(%edx), %eax\n"
        "movl %eax, 4(%ecx)\n"
        "movl %ebx, %eax\n" /* line 75 | twoOffsets */
        "addl 8(%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "addl $0xc, %ecx\n"
        "addl $0xc, %edx\n"
        "addl $1, %esi\n" /* surface */
        "cmpl %edi, %esi\n" /* line 71 | numMoves, surface */
        "jne .Lffa2d4_000fa304\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 86 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lffa2d4_000fa32f:\n"
        "movswl 4(%esi), %eax\n" /* line 83 | surface */
        "leal (%eax, %eax, 2), %eax\n"
        "addl %eax, %eax\n"
        "movl 8(%esi), %edx\n" /* surface */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* dstIndices */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "addl $0x1c, %esp\n" /* line 86 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 89 */
__attribute__((naked))
XVertexInfo * XSurfaceGetVertexInfoArray(const XSurface *surf)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 89 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* surf */
        "movl 0xc(%eax), %eax\n" /* surf */
        "popl %ebp\n" /* line 92 */
        "retl\n"
    );
}

/* line 95 */
__attribute__((naked))
int XSurfaceGetBoneOffset(const XSurface *surf)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 95 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* surf */
        "movswl 6(%eax), %eax\n" /* surf */
        "popl %ebp\n" /* line 98 */
        "retl\n"
    );
}

/* line 241 */
__attribute__((naked))
long unsigned int XSurfaceTransferDx7(const XVertexBuffer *surfVerts, GfxVertexDx7 *verts, int vertCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 241 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 0x10(%ebp), %edi\n" /* vertCount */
        /* { scope 1 */
        "movl 8(%ebp), %ebx\n" /* line 247 | surfVerts, v */
        "testl %edi, %edi\n" /* line 248 | vertCount */
        "jle .Lffa36e_000fa3ca\n"
        "movl 0xc(%ebp), %ecx\n" /* verts */
        "xorl %esi, %esi\n" /* vertIndex */
        ".Lffa36e_000fa383:\n"
        "leal 0x30(%ebx), %edx\n" /* line 250 | v, from */
        /* { scope 2 */
        "movl 0x30(%ebx), %eax\n" /* line 199 */
        "movl %eax, (%ecx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0xc(%ecx), %edx\n" /* line 251 | to */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, 0xc(%ecx)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl 0xc(%ebx), %eax\n" /* line 606 | v */
        "movl %eax, 0x18(%ecx)\n"
        "movl 0x1c(%ebx), %eax\n" /* line 253 | v */
        "movl %eax, 0x1c(%ecx)\n"
        "movl 0x2c(%ebx), %eax\n" /* line 254 | v */
        "movl %eax, 0x20(%ecx)\n"
        "addl $0x40, %ebx\n" /* line 255 | v */
        "addl $1, %esi\n" /* line 248 | vertIndex */
        "addl $0x24, %ecx\n"
        "cmpl %esi, %edi\n" /* vertIndex, vertCount */
        "jne .Lffa36e_000fa383\n"
        /* } scope */
        ".Lffa36e_000fa3ca:\n"
        "popl %ebx\n" /* line 257 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 218 */
__attribute__((naked))
long unsigned int XSurfaceTransfer(const XVertexBuffer *surfVerts, GfxVertex *verts, int vertCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 218 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        /* { scope 1 */
        "movl 8(%ebp), %esi\n" /* line 224 | surfVerts, v */
        "movl 0x10(%ebp), %eax\n" /* line 225 | vertCount */
        "testl %eax, %eax\n"
        "jle .Lffa3d0_000fa468\n"
        "movl 0xc(%ebp), %ebx\n" /* verts */
        "xorl %edi, %edi\n" /* vertIndex */
        ".Lffa3d0_000fa3e9:\n"
        "leal 0x30(%esi), %edx\n" /* line 227 | v, from */
        /* { scope 2 */
        "movl 0x30(%esi), %eax\n" /* line 199 */
        "movl %eax, (%ebx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        /* } scope */
        "movl $0x3f800000, 0xc(%ebx)\n" /* line 228 */
        "leal 0x10(%ebx), %edx\n" /* line 229 | to */
        /* { scope 2 */
        "movl (%esi), %eax\n" /* line 199 */
        "movl %eax, 0x10(%ebx)\n"
        "movl 4(%esi), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%esi), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl 0xc(%esi), %eax\n" /* line 606 | v */
        "movl %eax, 0x1c(%ebx)\n"
        "movl 0x1c(%esi), %eax\n" /* line 231 | v */
        "movl %eax, 0x20(%ebx)\n"
        "movl 0x2c(%esi), %eax\n" /* line 232 | v */
        "movl %eax, 0x24(%ebx)\n"
        "leal 0x28(%ebx), %ecx\n" /* line 233 | to */
        "leal 0x10(%esi), %edx\n" /* v, from */
        /* { scope 2 */
        "movl 0x10(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x28(%ebx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x34(%ebx), %ecx\n" /* line 234 | to */
        "leal 0x20(%esi), %edx\n" /* v, from */
        /* { scope 2 */
        "movl 0x20(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x34(%ebx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "addl $0x40, %esi\n" /* line 235 | v */
        "addl $1, %edi\n" /* line 225 | vertIndex */
        "addl $0x40, %ebx\n"
        "cmpl %edi, 0x10(%ebp)\n" /* vertIndex, vertCount */
        "jne .Lffa3d0_000fa3e9\n"
        /* } scope */
        ".Lffa3d0_000fa468:\n"
        "popl %ebx\n" /* line 237 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 106 */
__attribute__((naked))
long unsigned int XSurfaceGetVerts(const XSurface *surf, DObjSkelMat *boneMatrix, float *pVert, float *pTexCoord, float *pNormal)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 106 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0x10(%ebp), %esi\n" /* pVert */
        "movl 0x18(%ebp), %edi\n" /* pNormal */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 122 | surf */
        "movl 0xc(%eax), %edx\n"
        "movl %edx, %ecx\n"
        "movzwl 6(%eax), %eax\n" /* line 97 */
        "movswl %ax, %ebx\n"
        "addw $1, %ax\n" /* line 125 */
        "je .Lffa46e_000fa601\n"
        "movl 0xc(%ebp), %edx\n" /* line 127 | boneMatrix */
        "addl %ebx, %edx\n" /* boneIndex */
        "movl 8(%ebp), %ebx\n" /* line 136 | surf, boneIndex */
        "movzwl 2(%ebx), %eax\n" /* boneIndex */
        "movswl %ax, %ebx\n" /* boneIndex */
        "movl %ebx, -0x10(%ebp)\n" /* boneIndex */
        "testw %ax, %ax\n"
        "je .Lffa46e_000fa5f9\n"
        "xorl %ebx, %ebx\n" /* boneIndex */
        ".Lffa46e_000fa4b3:\n"
        "testl %edi, %edi\n" /* line 138 | pNormal */
        "je .Lffa46e_000fa536\n"
        "movss (%ecx), %xmm1\n" /* line 33 */
        "mulss (%edx), %xmm1\n"
        "movss 4(%ecx), %xmm0\n"
        "mulss 0x10(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%ecx), %xmm0\n"
        "mulss 0x20(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%edi)\n"
        "movss (%ecx), %xmm1\n" /* line 34 */
        "mulss 4(%edx), %xmm1\n"
        "movss 4(%ecx), %xmm0\n"
        "mulss 0x14(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%ecx), %xmm0\n"
        "mulss 0x24(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%edi)\n"
        "movss (%ecx), %xmm1\n" /* line 35 */
        "mulss 8(%edx), %xmm1\n"
        "movss 4(%ecx), %xmm0\n"
        "mulss 0x18(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%ecx), %xmm0\n"
        "mulss 0x28(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%edi)\n"
        "addl $0xc, %edi\n" /* line 141 | pNormal */
        ".Lffa46e_000fa536:\n"
        "movl 0x14(%ebp), %eax\n" /* line 143 | pTexCoord */
        "testl %eax, %eax\n"
        "je .Lffa46e_000fa559\n"
        "movss 0x1c(%ecx), %xmm0\n" /* line 145 */
        "movl 0x14(%ebp), %eax\n" /* pTexCoord */
        "movss %xmm0, (%eax)\n"
        "movss 0x2c(%ecx), %xmm0\n" /* line 146 */
        "movss %xmm0, 4(%eax)\n"
        "addl $8, %eax\n" /* line 147 */
        "movl %eax, 0x14(%ebp)\n" /* pTexCoord */
        ".Lffa46e_000fa559:\n"
        "movss 0x30(%ecx), %xmm1\n" /* line 17 */
        "mulss (%edx), %xmm1\n"
        "movss 0x34(%ecx), %xmm0\n"
        "mulss 0x10(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x38(%ecx), %xmm0\n"
        "mulss 0x20(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0x30(%edx), %xmm1\n"
        "movss %xmm1, (%esi)\n"
        "movss 0x30(%ecx), %xmm1\n" /* line 18 */
        "mulss 4(%edx), %xmm1\n"
        "movss 0x34(%ecx), %xmm0\n"
        "mulss 0x14(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x38(%ecx), %xmm0\n"
        "mulss 0x24(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0x34(%edx), %xmm1\n"
        "movss %xmm1, 4(%esi)\n"
        "movss 0x30(%ecx), %xmm1\n" /* line 19 */
        "mulss 8(%edx), %xmm1\n"
        "movss 0x34(%ecx), %xmm0\n"
        "mulss 0x18(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x38(%ecx), %xmm0\n"
        "mulss 0x28(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0x38(%edx), %xmm1\n"
        "movss %xmm1, 8(%esi)\n"
        "addl $0x40, %ecx\n"
        "addl $0xc, %esi\n" /* line 136 | pVert */
        "addl $1, %ebx\n" /* boneIndex */
        "cmpl %ebx, -0x10(%ebp)\n" /* boneIndex */
        "jne .Lffa46e_000fa4b3\n"
        /* } scope */
        ".Lffa46e_000fa5f9:\n"
        "addl $0x1c, %esp\n" /* line 215 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lffa46e_000fa601:\n"
        "movl 8(%ebp), %ecx\n" /* line 184 | surf */
        "movzwl 2(%ecx), %eax\n"
        "movswl %ax, %ebx\n" /* boneIndex */
        "movl %ebx, -0x28(%ebp)\n" /* boneIndex, render_count */
        "testw %ax, %ax\n"
        "je .Lffa46e_000fa5f9\n"
        "addl $0xc, %esi\n" /* pVert */
        "movl $0, -0x20(%ebp)\n"
        "movss 0x2ed854, %xmm4\n" /* 1.52587890625e-05f */
        "movss 0x2ed5c4, %xmm5\n" /* 0.00390625f */
        ".Lffa46e_000fa62d:\n"
        "testl %edi, %edi\n" /* line 186 | pNormal */
        "je .Lffa46e_000fa6bb\n"
        "movswl 0x3e(%edx), %eax\n" /* line 188 | mat */
        "addl 0xc(%ebp), %eax\n" /* boneMatrix, mat */
        /* { scope 2 */
        "movss (%edx), %xmm1\n" /* line 33 */
        "mulss (%eax), %xmm1\n"
        "movss 4(%edx), %xmm0\n"
        "mulss 0x10(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "mulss 0x20(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%edi)\n"
        "movss (%edx), %xmm1\n" /* line 34 */
        "mulss 4(%eax), %xmm1\n"
        "movss 4(%edx), %xmm0\n"
        "mulss 0x14(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "mulss 0x24(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%edi)\n"
        "movss (%edx), %xmm1\n" /* line 35 */
        "mulss 8(%eax), %xmm1\n"
        "movss 4(%edx), %xmm0\n"
        "mulss 0x18(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "mulss 0x28(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%edi)\n"
        /* } scope */
        "addl $0xc, %edi\n" /* line 189 | pNormal */
        ".Lffa46e_000fa6bb:\n"
        "movswl 0x3e(%edx), %eax\n" /* line 192 | mat */
        "addl 0xc(%ebp), %eax\n" /* boneMatrix, mat */
        /* { scope 2 */
        "leal -0xc(%esi), %ecx\n" /* line 106 | pVert */
        "movl %ecx, -0x1c(%ebp)\n"
        "movss 0x30(%edx), %xmm1\n" /* line 17 */
        "mulss (%eax), %xmm1\n"
        "movss 0x34(%edx), %xmm0\n"
        "mulss 0x10(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x38(%edx), %xmm0\n"
        "mulss 0x20(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0x30(%eax), %xmm1\n"
        "movss %xmm1, -0xc(%esi)\n"
        "leal -8(%esi), %ebx\n" /* line 106 | pVert */
        "movl %ebx, -0x18(%ebp)\n"
        "movss 0x30(%edx), %xmm1\n" /* line 18 */
        "mulss 4(%eax), %xmm1\n"
        "movss 0x34(%edx), %xmm0\n"
        "mulss 0x14(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x38(%edx), %xmm0\n"
        "mulss 0x24(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0x34(%eax), %xmm1\n"
        "movss %xmm1, -8(%esi)\n"
        "leal -4(%esi), %ecx\n" /* line 106 | pVert */
        "movl %ecx, -0x14(%ebp)\n"
        "movss 0x30(%edx), %xmm1\n" /* line 19 */
        "mulss 8(%eax), %xmm1\n"
        "movss 0x34(%edx), %xmm0\n"
        "mulss 0x18(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x38(%edx), %xmm0\n"
        "mulss 0x28(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0x38(%eax), %xmm1\n"
        "movss %xmm1, -4(%esi)\n"
        /* } scope */
        "movzbl 0x3c(%edx), %eax\n" /* line 195 */
        "movzbl %al, %ebx\n" /* boneIndex */
        "movl %ebx, -0x24(%ebp)\n" /* boneIndex, numWeights */
        "testb %al, %al\n" /* line 197 */
        "je .Lffa46e_000fa896\n"
        "movzbl 0x3d(%edx), %eax\n" /* line 199 */
        "cvtsi2ssl %eax, %xmm0\n" /* scale */
        "mulss %xmm5, %xmm0\n" /* scale */
        /* { scope 2 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss -0xc(%esi), %xmm1\n" /* pVert */
        "movss %xmm1, -0xc(%esi)\n" /* pVert */
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -8(%esi), %xmm1\n" /* pVert */
        "movss %xmm1, -8(%esi)\n" /* pVert */
        "mulss -4(%esi), %xmm0\n" /* line 274 | pVert */
        "movss %xmm0, -4(%esi)\n" /* pVert */
        /* } scope */
        "leal 0x40(%edx), %ecx\n" /* line 200 */
        "xorl %ebx, %ebx\n" /* boneIndex */
        "movaps %xmm4, %xmm3\n"
        ".Lffa46e_000fa7ad:\n"
        "movswl 0xc(%ecx), %edx\n" /* line 204 | mat */
        "addl 0xc(%ebp), %edx\n" /* boneMatrix, mat */
        "movzwl 0xe(%ecx), %eax\n"
        "cvtsi2ssl %eax, %xmm2\n" /* s */
        "mulss %xmm3, %xmm2\n" /* s */
        /* { scope 2 */
        "movss (%ecx), %xmm1\n" /* line 25 */
        "mulss (%edx), %xmm1\n"
        "movss 4(%ecx), %xmm0\n"
        "mulss 0x10(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%ecx), %xmm0\n"
        "mulss 0x20(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0x30(%edx), %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "movl -0x1c(%ebp), %eax\n"
        "addss (%eax), %xmm1\n"
        "movss %xmm1, (%eax)\n"
        "movss (%ecx), %xmm1\n" /* line 26 */
        "mulss 4(%edx), %xmm1\n"
        "movss 4(%ecx), %xmm0\n"
        "mulss 0x14(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%ecx), %xmm0\n"
        "mulss 0x24(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0x34(%edx), %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "movl -0x18(%ebp), %eax\n"
        "addss (%eax), %xmm1\n"
        "movss %xmm1, (%eax)\n"
        "movss (%ecx), %xmm1\n" /* line 27 */
        "mulss 8(%edx), %xmm1\n"
        "movss 4(%ecx), %xmm0\n"
        "mulss 0x18(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%ecx), %xmm0\n"
        "mulss 0x28(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss 0x38(%edx), %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "movl -0x14(%ebp), %eax\n"
        "addss (%eax), %xmm1\n"
        "movss %xmm1, (%eax)\n"
        "addl $0x10, %ecx\n"
        "addl $1, %ebx\n"
        /* } scope */
        "cmpl -0x24(%ebp), %ebx\n" /* line 202 | numWeights, boneIndex */
        "jne .Lffa46e_000fa7ad\n"
        "movl %ecx, %edx\n"
        ".Lffa46e_000fa87b:\n"
        "addl $1, -0x20(%ebp)\n" /* line 211 */
        "addl $0xc, %esi\n" /* pVert */
        "movl -0x20(%ebp), %ecx\n" /* line 184 */
        "cmpl %ecx, -0x28(%ebp)\n" /* render_count */
        "jne .Lffa46e_000fa62d\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 215 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lffa46e_000fa896:\n"
        "addl $0x40, %edx\n" /* line 211 */
        "jmp .Lffa46e_000fa87b\n"
    );
}

