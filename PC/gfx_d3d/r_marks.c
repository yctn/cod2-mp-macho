/* ASM dump from: r_marks.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_marks.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

static void R_AABBTreeSurfaces_r(GfxSurface * *surfList, int surfListSize, int *surfCount);
static void R_CellSurfaces(const vec_t *mins, const vec_t *maxs, GfxSurface * *surfList, int surfListSize, int *surfCount);
static void R_BoxSurfaces_r(mnode_t *node, const vec_t *mins, const vec_t *maxs, GfxSurface * *surfList, int surfListSize, int *surfCount);
int R_MarkFragments(vec3_t *points, const vec_t *origin, vec3_t *axis, float radius, int maxPoints, GfxWorldVertex *verts, int maxFragments, GfxMarkFragment *fragmentBuffer, MaterialHandle markMaterial);

/* line 125 */
static __attribute__((naked))
void R_AABBTreeSurfaces_r(GfxSurface * *surfList, int surfListSize, int *surfCount)
{
    __asm__ __volatile__ (
        ".Lff3c9c_000f3c9c:\n"
        "pushl %ebp\n" /* line 125 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl %eax, %esi\n" /* tree */
        "movl %edx, %ebx\n" /* mins */
        "movl %ecx, %edi\n" /* maxs */
        /* { scope 1: tree */
        "movss (%edx), %xmm1\n" /* line 132 */
        "ucomiss 0xc(%eax), %xmm1\n"
        "ja .Lff3c9c_000f4132\n"
        "movss (%eax), %xmm0\n"
        "ucomiss (%ecx), %xmm0\n"
        "ja .Lff3c9c_000f4132\n"
        "leal 4(%edx), %eax\n" /* line 134 */
        "movl %eax, -0x78(%ebp)\n"
        "movss 4(%edx), %xmm0\n"
        "ucomiss 0x10(%esi), %xmm0\n" /* tree */
        "ja .Lff3c9c_000f4132\n"
        "leal 4(%ecx), %edx\n"
        "movl %edx, -0x74(%ebp)\n"
        "movss 4(%esi), %xmm0\n" /* tree */
        "ucomiss 4(%ecx), %xmm0\n"
        "ja .Lff3c9c_000f4132\n"
        "leal 8(%ebx), %ecx\n" /* line 136 | mins */
        "movl %ecx, -0x70(%ebp)\n"
        "movss 8(%ebx), %xmm0\n" /* mins */
        "ucomiss 0x14(%esi), %xmm0\n" /* tree */
        "ja .Lff3c9c_000f4132\n"
        "leal 8(%edi), %eax\n" /* maxs */
        "movl %eax, -0x6c(%ebp)\n"
        "movss 8(%esi), %xmm0\n" /* tree */
        "ucomiss 8(%edi), %xmm0\n" /* maxs */
        "ja .Lff3c9c_000f4132\n"
        "cmpl $0, 0x28(%esi)\n" /* line 139 | tree */
        "je .Lff3c9c_000f405f\n"
        "jle .Lff3c9c_000f4132\n" /* line 141 */
        "movl $0, -0x68(%ebp)\n" /* childIndex */
        "movl $0, -0x1c(%ebp)\n"
        ".Lff3c9c_000f3d3b:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 142 */
        "addl 0x2c(%esi), %edx\n" /* tree */
        "movl %edx, -0x64(%ebp)\n" /* tree */
        /* { scope 2: childIndex, surfNodeIndex, tris */
        /* { scope 3: tree */
        "ucomiss 0xc(%edx), %xmm1\n" /* line 132 */
        "ja .Lff3c9c_000f4216\n"
        "movss (%edx), %xmm0\n"
        "ucomiss (%edi), %xmm0\n" /* maxs */
        "ja .Lff3c9c_000f4216\n"
        "movl -0x78(%ebp), %ecx\n" /* line 134 */
        "movss (%ecx), %xmm0\n"
        "ucomiss 0x10(%edx), %xmm0\n"
        "ja .Lff3c9c_000f4216\n"
        "movss 4(%edx), %xmm0\n"
        "movl -0x74(%ebp), %eax\n"
        "ucomiss (%eax), %xmm0\n"
        "ja .Lff3c9c_000f4216\n"
        "movl -0x70(%ebp), %edx\n" /* line 136 */
        "movss (%edx), %xmm0\n"
        "movl -0x64(%ebp), %ecx\n" /* tree */
        "ucomiss 0x14(%ecx), %xmm0\n"
        "ja .Lff3c9c_000f4216\n"
        "movss 8(%ecx), %xmm0\n"
        "movl -0x6c(%ebp), %eax\n"
        "ucomiss (%eax), %xmm0\n"
        "ja .Lff3c9c_000f4216\n"
        "cmpl $0, 0x28(%ecx)\n" /* line 139 */
        "je .Lff3c9c_000f413d\n"
        "jle .Lff3c9c_000f4216\n" /* line 141 */
        "movl $0, -0x60(%ebp)\n" /* childIndex */
        "movl $0, -0x20(%ebp)\n"
        ".Lff3c9c_000f3dc0:\n"
        "movl -0x20(%ebp), %edx\n" /* line 142 */
        "movl -0x64(%ebp), %eax\n" /* tree */
        "addl 0x2c(%eax), %edx\n"
        "movl %edx, -0x5c(%ebp)\n" /* tree */
        /* { scope 4: childIndex, surfNodeIndex */
        /* { scope 5: tree */
        "ucomiss 0xc(%edx), %xmm1\n" /* line 132 */
        "ja .Lff3c9c_000f4309\n"
        "movss (%edx), %xmm0\n"
        "ucomiss (%edi), %xmm0\n" /* maxs */
        "ja .Lff3c9c_000f4306\n"
        "movl -0x78(%ebp), %ecx\n" /* line 134 */
        "movss (%ecx), %xmm0\n"
        "ucomiss 0x10(%edx), %xmm0\n"
        "ja .Lff3c9c_000f4306\n"
        "movss 4(%edx), %xmm0\n"
        "movl -0x74(%ebp), %eax\n"
        "ucomiss (%eax), %xmm0\n"
        "ja .Lff3c9c_000f4306\n"
        "movl -0x70(%ebp), %edx\n" /* line 136 */
        "movss (%edx), %xmm0\n"
        "movl -0x5c(%ebp), %ecx\n" /* tree */
        "ucomiss 0x14(%ecx), %xmm0\n"
        "ja .Lff3c9c_000f4306\n"
        "movss 8(%ecx), %xmm0\n"
        "movl -0x6c(%ebp), %eax\n"
        "ucomiss (%eax), %xmm0\n"
        "ja .Lff3c9c_000f4306\n"
        "cmpl $0, 0x28(%ecx)\n" /* line 139 */
        "je .Lff3c9c_000f4233\n"
        "jle .Lff3c9c_000f4306\n" /* line 141 */
        "movl $0, -0x58(%ebp)\n" /* childIndex */
        "movl $0, -0x24(%ebp)\n"
        ".Lff3c9c_000f3e48:\n"
        "movl -0x24(%ebp), %edx\n" /* line 142 */
        "movl -0x5c(%ebp), %eax\n" /* tree */
        "addl 0x2c(%eax), %edx\n"
        "movl %edx, -0x54(%ebp)\n" /* tree */
        /* { scope 6: childIndex, surfNodeIndex */
        /* { scope 7: tree */
        "ucomiss 0xc(%edx), %xmm1\n" /* line 132 */
        "ja .Lff3c9c_000f43f3\n"
        "movss (%edx), %xmm0\n"
        "ucomiss (%edi), %xmm0\n" /* maxs */
        "ja .Lff3c9c_000f43f3\n"
        "movl -0x78(%ebp), %ecx\n" /* line 134 */
        "movss (%ecx), %xmm0\n"
        "ucomiss 0x10(%edx), %xmm0\n"
        "ja .Lff3c9c_000f43f3\n"
        "movss 4(%edx), %xmm0\n"
        "movl -0x74(%ebp), %eax\n"
        "ucomiss (%eax), %xmm0\n"
        "ja .Lff3c9c_000f43f3\n"
        "movl -0x70(%ebp), %edx\n" /* line 136 */
        "movss (%edx), %xmm0\n"
        "movl -0x54(%ebp), %ecx\n" /* tree */
        "ucomiss 0x14(%ecx), %xmm0\n"
        "ja .Lff3c9c_000f43f3\n"
        "movss 8(%ecx), %xmm0\n"
        "movl -0x6c(%ebp), %eax\n"
        "ucomiss (%eax), %xmm0\n"
        "ja .Lff3c9c_000f43f3\n"
        "cmpl $0, 0x28(%ecx)\n" /* line 139 */
        "je .Lff3c9c_000f4326\n"
        "jle .Lff3c9c_000f43f3\n" /* line 141 */
        "movl $0, -0x50(%ebp)\n" /* childIndex */
        "movl $0, -0x28(%ebp)\n"
        ".Lff3c9c_000f3ed0:\n"
        "movl -0x28(%ebp), %edx\n" /* line 142 */
        "movl -0x54(%ebp), %eax\n" /* tree */
        "addl 0x2c(%eax), %edx\n"
        "movl %edx, -0x4c(%ebp)\n" /* tree */
        /* { scope 8: childIndex, surfNodeIndex */
        /* { scope 9: tree */
        "ucomiss 0xc(%edx), %xmm1\n" /* line 132 */
        "ja .Lff3c9c_000f464a\n"
        "movss (%edx), %xmm0\n"
        "ucomiss (%edi), %xmm0\n" /* maxs */
        "ja .Lff3c9c_000f464a\n"
        "movl -0x78(%ebp), %ecx\n" /* line 134 */
        "movss (%ecx), %xmm0\n"
        "ucomiss 0x10(%edx), %xmm0\n"
        "ja .Lff3c9c_000f464a\n"
        "movss 4(%edx), %xmm0\n"
        "movl -0x74(%ebp), %eax\n"
        "ucomiss (%eax), %xmm0\n"
        "ja .Lff3c9c_000f464a\n"
        "movl -0x70(%ebp), %edx\n" /* line 136 */
        "movss (%edx), %xmm0\n"
        "movl -0x4c(%ebp), %ecx\n" /* tree */
        "ucomiss 0x14(%ecx), %xmm0\n"
        "ja .Lff3c9c_000f464a\n"
        "movss 8(%ecx), %xmm0\n"
        "movl -0x6c(%ebp), %eax\n"
        "ucomiss (%eax), %xmm0\n"
        "ja .Lff3c9c_000f464a\n"
        "cmpl $0, 0x28(%ecx)\n" /* line 139 */
        "je .Lff3c9c_000f457c\n"
        "jle .Lff3c9c_000f464a\n" /* line 141 */
        "movl $0, -0x48(%ebp)\n" /* childIndex */
        "movl $0, -0x2c(%ebp)\n"
        ".Lff3c9c_000f3f58:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 142 */
        "movl -0x4c(%ebp), %eax\n" /* tree */
        "addl 0x2c(%eax), %edx\n"
        "movl %edx, -0x44(%ebp)\n" /* tree */
        /* { scope 10: childIndex, surfNodeIndex */
        /* { scope 11: tree */
        "ucomiss 0xc(%edx), %xmm1\n" /* line 132 */
        "ja .Lff3c9c_000f4439\n"
        "movss (%edx), %xmm0\n"
        "ucomiss (%edi), %xmm0\n" /* maxs */
        "ja .Lff3c9c_000f4439\n"
        "movl -0x78(%ebp), %ecx\n" /* line 134 */
        "movss (%ecx), %xmm0\n"
        "ucomiss 0x10(%edx), %xmm0\n"
        "ja .Lff3c9c_000f4439\n"
        "movss 4(%edx), %xmm0\n"
        "movl -0x74(%ebp), %eax\n"
        "ucomiss (%eax), %xmm0\n"
        "ja .Lff3c9c_000f4439\n"
        "movl -0x70(%ebp), %edx\n" /* line 136 */
        "movss (%edx), %xmm0\n"
        "movl -0x44(%ebp), %ecx\n" /* tree */
        "ucomiss 0x14(%ecx), %xmm0\n"
        "ja .Lff3c9c_000f4439\n"
        "movss 8(%ecx), %xmm0\n"
        "movl -0x6c(%ebp), %eax\n"
        "ucomiss (%eax), %xmm0\n"
        "ja .Lff3c9c_000f4439\n"
        "cmpl $0, 0x28(%ecx)\n" /* line 139 */
        "je .Lff3c9c_000f4413\n"
        "jle .Lff3c9c_000f4439\n" /* line 141 */
        "movl $0, -0x40(%ebp)\n" /* childIndex */
        "movl $0, -0x30(%ebp)\n"
        ".Lff3c9c_000f3fe0:\n"
        "movl -0x30(%ebp), %edx\n" /* line 142 */
        "movl -0x44(%ebp), %eax\n" /* tree */
        "addl 0x2c(%eax), %edx\n"
        "movl %edx, -0x3c(%ebp)\n" /* tree */
        /* { scope 12: childIndex, surfNodeIndex */
        /* { scope 13 */
        "ucomiss 0xc(%edx), %xmm1\n" /* line 132 */
        "ja .Lff3c9c_000f4042\n"
        "movss (%edx), %xmm0\n"
        "ucomiss (%edi), %xmm0\n" /* maxs */
        "ja .Lff3c9c_000f4042\n"
        "movl -0x78(%ebp), %ecx\n" /* line 134 */
        "movss (%ecx), %xmm0\n"
        "ucomiss 0x10(%edx), %xmm0\n"
        "ja .Lff3c9c_000f4042\n"
        "movss 4(%edx), %xmm0\n"
        "movl -0x74(%ebp), %eax\n"
        "ucomiss (%eax), %xmm0\n"
        "ja .Lff3c9c_000f4042\n"
        "movl -0x70(%ebp), %edx\n" /* line 136 */
        "movss (%edx), %xmm0\n"
        "movl -0x3c(%ebp), %ecx\n" /* tree */
        "ucomiss 0x14(%ecx), %xmm0\n"
        "ja .Lff3c9c_000f4042\n"
        "movss 8(%ecx), %xmm0\n"
        "movl -0x6c(%ebp), %eax\n"
        "ucomiss (%eax), %xmm0\n"
        "ja .Lff3c9c_000f4042\n"
        "cmpl $0, 0x28(%ecx)\n" /* line 139 */
        "je .Lff3c9c_000f44a5\n"
        "jg .Lff3c9c_000f4459\n" /* line 141 */
        /* } scope */
        /* } scope */
        ".Lff3c9c_000f4042:\n"
        "addl $1, -0x40(%ebp)\n" /* childIndex */
        "addl $0x30, -0x30(%ebp)\n"
        "movl -0x40(%ebp), %edx\n" /* childIndex */
        "movl -0x44(%ebp), %eax\n" /* tree */
        "cmpl %edx, 0x28(%eax)\n"
        "jle .Lff3c9c_000f4439\n"
        "movss (%ebx), %xmm1\n" /* mins */
        "jmp .Lff3c9c_000f3fe0\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lff3c9c_000f405f:\n"
        "movl 0x195eebc, %eax\n" /* line 146 */
        "movl 0x109c(%eax), %edx\n"
        "movl 0x1c(%esi), %eax\n" /* tree */
        "leal (%eax, %eax, 2), %eax\n"
        "movl 0x14(%edx), %edx\n"
        "leal (%edx, %eax, 4), %edx\n"
        "movl 0x18(%esi), %eax\n" /* tree */
        "testl %eax, %eax\n"
        "jle .Lff3c9c_000f4132\n"
        "movl 0x10(%ebp), %ecx\n" /* surfCount */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x7c(%ebp)\n"
        "cmpl %ecx, 0xc(%ebp)\n" /* surfListSize */
        "jle .Lff3c9c_000f4132\n"
        "movl $0, -0x8c(%ebp)\n" /* surfNodeIndex */
        ".Lff3c9c_000f409c:\n"
        "movl (%edx), %eax\n" /* line 148 */
        "testb $4, 0xc(%eax)\n"
        "jne .Lff3c9c_000f4111\n"
        "movl 8(%edx), %ecx\n" /* line 150 */
        "movl %ecx, -0x90(%ebp)\n" /* tris */
        "movss (%ebx), %xmm0\n" /* line 151 | mins */
        "ucomiss 0x10(%ecx), %xmm0\n"
        "ja .Lff3c9c_000f4111\n"
        "movss 4(%ecx), %xmm0\n"
        "ucomiss (%edi), %xmm0\n" /* maxs */
        "ja .Lff3c9c_000f4111\n"
        "movl -0x78(%ebp), %eax\n" /* line 153 */
        "movss (%eax), %xmm0\n"
        "ucomiss 0x14(%ecx), %xmm0\n"
        "ja .Lff3c9c_000f4111\n"
        "movss 8(%ecx), %xmm0\n"
        "movl -0x74(%ebp), %ecx\n"
        "ucomiss (%ecx), %xmm0\n"
        "ja .Lff3c9c_000f4111\n"
        "movl -0x70(%ebp), %eax\n" /* line 155 */
        "movss (%eax), %xmm0\n"
        "movl -0x90(%ebp), %ecx\n" /* tris */
        "ucomiss 0x18(%ecx), %xmm0\n"
        "ja .Lff3c9c_000f4111\n"
        "movss 0xc(%ecx), %xmm0\n"
        "movl -0x6c(%ebp), %eax\n"
        "ucomiss (%eax), %xmm0\n"
        "ja .Lff3c9c_000f4111\n"
        "movl -0x7c(%ebp), %ecx\n" /* line 158 */
        "movl 8(%ebp), %eax\n" /* surfList */
        "movl %edx, (%eax, %ecx, 4)\n"
        "movl 0x10(%ebp), %ecx\n" /* line 159 | surfCount */
        "movl (%ecx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, -0x7c(%ebp)\n"
        "movl %eax, (%ecx)\n"
        ".Lff3c9c_000f4111:\n"
        "addl $1, -0x8c(%ebp)\n" /* line 146 | surfNodeIndex */
        "addl $0xc, %edx\n"
        "movl -0x8c(%ebp), %ecx\n" /* surfNodeIndex */
        "cmpl 0x18(%esi), %ecx\n" /* tree */
        "jge .Lff3c9c_000f4132\n"
        "movl -0x7c(%ebp), %eax\n"
        "cmpl %eax, 0xc(%ebp)\n" /* surfListSize */
        "jg .Lff3c9c_000f409c\n"
        /* } scope */
        ".Lff3c9c_000f4132:\n"
        "addl $0x9c, %esp\n" /* line 161 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: tree */
        /* { scope 2: childIndex, surfNodeIndex, tris */
        /* { scope 3: tree */
        ".Lff3c9c_000f413d:\n"
        "movl 0x195eebc, %eax\n" /* line 146 */
        "movl 0x109c(%eax), %edx\n"
        "movl -0x64(%ebp), %ecx\n" /* tree */
        "movl 0x1c(%ecx), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl 0x14(%edx), %edx\n"
        "leal (%edx, %eax, 4), %edx\n"
        "movl 0x18(%ecx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lff3c9c_000f4216\n"
        "movl 0x10(%ebp), %ecx\n" /* surfCount */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x7c(%ebp)\n"
        "cmpl %ecx, 0xc(%ebp)\n" /* surfListSize */
        "jle .Lff3c9c_000f4216\n"
        "movl $0, -0x8c(%ebp)\n" /* surfNodeIndex */
        ".Lff3c9c_000f417d:\n"
        "movl (%edx), %eax\n" /* line 148 */
        "testb $4, 0xc(%eax)\n"
        "jne .Lff3c9c_000f41f2\n"
        "movl 8(%edx), %eax\n" /* line 150 */
        "movl %eax, -0x90(%ebp)\n" /* tris */
        "movss (%ebx), %xmm1\n" /* line 151 | mins */
        "ucomiss 0x10(%eax), %xmm1\n"
        "ja .Lff3c9c_000f41f2\n"
        "movss 4(%eax), %xmm0\n"
        "ucomiss (%edi), %xmm0\n" /* maxs */
        "ja .Lff3c9c_000f41f2\n"
        "movl -0x78(%ebp), %ecx\n" /* line 153 */
        "movss (%ecx), %xmm0\n"
        "ucomiss 0x14(%eax), %xmm0\n"
        "ja .Lff3c9c_000f41f2\n"
        "movss 8(%eax), %xmm0\n"
        "movl -0x74(%ebp), %eax\n"
        "ucomiss (%eax), %xmm0\n"
        "ja .Lff3c9c_000f41f2\n"
        "movl -0x70(%ebp), %ecx\n" /* line 155 */
        "movss (%ecx), %xmm0\n"
        "movl -0x90(%ebp), %eax\n" /* tris */
        "ucomiss 0x18(%eax), %xmm0\n"
        "ja .Lff3c9c_000f41f2\n"
        "movss 0xc(%eax), %xmm0\n"
        "movl -0x6c(%ebp), %ecx\n"
        "ucomiss (%ecx), %xmm0\n"
        "ja .Lff3c9c_000f41f2\n"
        "movl -0x7c(%ebp), %eax\n" /* line 158 */
        "movl 8(%ebp), %ecx\n" /* surfList */
        "movl %edx, (%ecx, %eax, 4)\n"
        "movl 0x10(%ebp), %eax\n" /* line 159 | surfCount */
        "movl (%eax), %ecx\n"
        "addl $1, %ecx\n"
        "movl %ecx, -0x7c(%ebp)\n"
        "movl %ecx, (%eax)\n"
        ".Lff3c9c_000f41f2:\n"
        "addl $1, -0x8c(%ebp)\n" /* line 146 | surfNodeIndex */
        "addl $0xc, %edx\n"
        "movl -0x8c(%ebp), %ecx\n" /* surfNodeIndex */
        "movl -0x64(%ebp), %eax\n" /* tree */
        "cmpl 0x18(%eax), %ecx\n"
        "jge .Lff3c9c_000f4216\n"
        "movl -0x7c(%ebp), %eax\n"
        "cmpl %eax, 0xc(%ebp)\n" /* surfListSize */
        "jg .Lff3c9c_000f417d\n"
        /* } scope */
        /* } scope */
        ".Lff3c9c_000f4216:\n"
        "addl $1, -0x68(%ebp)\n" /* line 141 | childIndex */
        "addl $0x30, -0x1c(%ebp)\n"
        "movl -0x68(%ebp), %edx\n" /* childIndex */
        "cmpl %edx, 0x28(%esi)\n" /* tree */
        "jle .Lff3c9c_000f4132\n"
        "movss (%ebx), %xmm1\n" /* mins */
        "jmp .Lff3c9c_000f3d3b\n"
        /* { scope 2: childIndex, surfNodeIndex, tris */
        /* { scope 3: tree */
        /* { scope 4: childIndex, surfNodeIndex */
        /* { scope 5: tree */
        ".Lff3c9c_000f4233:\n"
        "movl 0x195eebc, %eax\n" /* line 146 */
        "movl 0x109c(%eax), %edx\n"
        "movl -0x5c(%ebp), %ecx\n" /* tree */
        "movl 0x1c(%ecx), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl 0x14(%edx), %edx\n"
        "leal (%edx, %eax, 4), %edx\n"
        "movl 0x18(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lff3c9c_000f4306\n"
        "movl 0x10(%ebp), %ecx\n" /* surfCount */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x7c(%ebp)\n"
        "cmpl %ecx, 0xc(%ebp)\n" /* surfListSize */
        "jle .Lff3c9c_000f4306\n"
        "movl $0, -0x8c(%ebp)\n" /* surfNodeIndex */
        "jmp .Lff3c9c_000f4281\n"
        ".Lff3c9c_000f4275:\n"
        "movl -0x7c(%ebp), %ecx\n"
        "cmpl %ecx, 0xc(%ebp)\n" /* surfListSize */
        "jle .Lff3c9c_000f4306\n"
        ".Lff3c9c_000f4281:\n"
        "movl (%edx), %eax\n" /* line 148 */
        "testb $4, 0xc(%eax)\n"
        "jne .Lff3c9c_000f42ea\n"
        "movl 8(%edx), %eax\n" /* line 150 */
        "movss (%ebx), %xmm1\n" /* line 151 | mins */
        "ucomiss 0x10(%eax), %xmm1\n"
        "ja .Lff3c9c_000f42ea\n"
        "movss 4(%eax), %xmm0\n"
        "ucomiss (%edi), %xmm0\n" /* maxs */
        "ja .Lff3c9c_000f42ea\n"
        "movl -0x78(%ebp), %ecx\n" /* line 153 */
        "movss (%ecx), %xmm0\n"
        "ucomiss 0x14(%eax), %xmm0\n"
        "ja .Lff3c9c_000f42ea\n"
        "movss 8(%eax), %xmm0\n"
        "movl -0x74(%ebp), %ecx\n"
        "ucomiss (%ecx), %xmm0\n"
        "ja .Lff3c9c_000f42ea\n"
        "movl -0x70(%ebp), %ecx\n" /* line 155 */
        "movss (%ecx), %xmm0\n"
        "ucomiss 0x18(%eax), %xmm0\n"
        "ja .Lff3c9c_000f42ea\n"
        "movss 0xc(%eax), %xmm0\n"
        "movl -0x6c(%ebp), %eax\n"
        "ucomiss (%eax), %xmm0\n"
        "ja .Lff3c9c_000f42ea\n"
        "movl -0x7c(%ebp), %ecx\n" /* line 158 */
        "movl 8(%ebp), %eax\n" /* surfList */
        "movl %edx, (%eax, %ecx, 4)\n"
        "movl 0x10(%ebp), %ecx\n" /* line 159 | surfCount */
        "movl (%ecx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, -0x7c(%ebp)\n"
        "movl %eax, (%ecx)\n"
        ".Lff3c9c_000f42ea:\n"
        "addl $1, -0x8c(%ebp)\n" /* line 146 | surfNodeIndex */
        "addl $0xc, %edx\n"
        "movl -0x8c(%ebp), %eax\n" /* surfNodeIndex */
        "movl -0x5c(%ebp), %ecx\n" /* tree */
        "cmpl 0x18(%ecx), %eax\n"
        "jl .Lff3c9c_000f4275\n"
        ".Lff3c9c_000f4306:\n"
        "movl -0x64(%ebp), %eax\n" /* tree */
        /* } scope */
        /* } scope */
        ".Lff3c9c_000f4309:\n"
        "addl $1, -0x60(%ebp)\n" /* line 141 | childIndex */
        "addl $0x30, -0x20(%ebp)\n"
        "movl -0x60(%ebp), %edx\n" /* childIndex */
        "cmpl 0x28(%eax), %edx\n"
        "jge .Lff3c9c_000f4216\n"
        "movss (%ebx), %xmm1\n" /* mins */
        "jmp .Lff3c9c_000f3dc0\n"
        /* { scope 4: childIndex, surfNodeIndex */
        /* { scope 5: tree */
        /* { scope 6: childIndex, surfNodeIndex */
        /* { scope 7: tree */
        ".Lff3c9c_000f4326:\n"
        "movl 0x195eebc, %eax\n" /* line 146 */
        "movl 0x109c(%eax), %edx\n"
        "movl -0x54(%ebp), %ecx\n" /* tree */
        "movl 0x1c(%ecx), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl 0x14(%edx), %edx\n"
        "leal (%edx, %eax, 4), %edx\n"
        "movl 0x18(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lff3c9c_000f43f3\n"
        "movl 0x10(%ebp), %ecx\n" /* surfCount */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x7c(%ebp)\n"
        "cmpl %ecx, 0xc(%ebp)\n" /* surfListSize */
        "jle .Lff3c9c_000f43f3\n"
        "movl $0, -0x8c(%ebp)\n" /* surfNodeIndex */
        ".Lff3c9c_000f4366:\n"
        "movl (%edx), %eax\n" /* line 148 */
        "testb $4, 0xc(%eax)\n"
        "jne .Lff3c9c_000f43cf\n"
        "movl 8(%edx), %eax\n" /* line 150 */
        "movss (%ebx), %xmm1\n" /* line 151 | mins */
        "ucomiss 0x10(%eax), %xmm1\n"
        "ja .Lff3c9c_000f43cf\n"
        "movss 4(%eax), %xmm0\n"
        "ucomiss (%edi), %xmm0\n" /* maxs */
        "ja .Lff3c9c_000f43cf\n"
        "movl -0x78(%ebp), %ecx\n" /* line 153 */
        "movss (%ecx), %xmm0\n"
        "ucomiss 0x14(%eax), %xmm0\n"
        "ja .Lff3c9c_000f43cf\n"
        "movss 8(%eax), %xmm0\n"
        "movl -0x74(%ebp), %ecx\n"
        "ucomiss (%ecx), %xmm0\n"
        "ja .Lff3c9c_000f43cf\n"
        "movl -0x70(%ebp), %ecx\n" /* line 155 */
        "movss (%ecx), %xmm0\n"
        "ucomiss 0x18(%eax), %xmm0\n"
        "ja .Lff3c9c_000f43cf\n"
        "movss 0xc(%eax), %xmm0\n"
        "movl -0x6c(%ebp), %eax\n"
        "ucomiss (%eax), %xmm0\n"
        "ja .Lff3c9c_000f43cf\n"
        "movl -0x7c(%ebp), %ecx\n" /* line 158 */
        "movl 8(%ebp), %eax\n" /* surfList */
        "movl %edx, (%eax, %ecx, 4)\n"
        "movl 0x10(%ebp), %ecx\n" /* line 159 | surfCount */
        "movl (%ecx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, -0x7c(%ebp)\n"
        "movl %eax, (%ecx)\n"
        ".Lff3c9c_000f43cf:\n"
        "addl $1, -0x8c(%ebp)\n" /* line 146 | surfNodeIndex */
        "addl $0xc, %edx\n"
        "movl -0x8c(%ebp), %eax\n" /* surfNodeIndex */
        "movl -0x54(%ebp), %ecx\n" /* tree */
        "cmpl 0x18(%ecx), %eax\n"
        "jge .Lff3c9c_000f43f3\n"
        "movl -0x7c(%ebp), %ecx\n"
        "cmpl %ecx, 0xc(%ebp)\n" /* surfListSize */
        "jg .Lff3c9c_000f4366\n"
        /* } scope */
        /* } scope */
        ".Lff3c9c_000f43f3:\n"
        "addl $1, -0x58(%ebp)\n" /* line 141 | childIndex */
        "addl $0x30, -0x24(%ebp)\n"
        "movl -0x58(%ebp), %edx\n" /* childIndex */
        "movl -0x5c(%ebp), %eax\n" /* tree */
        "cmpl 0x28(%eax), %edx\n"
        "jge .Lff3c9c_000f4306\n"
        "movss (%ebx), %xmm1\n" /* mins */
        "jmp .Lff3c9c_000f3e48\n"
        /* { scope 6: childIndex, surfNodeIndex */
        /* { scope 7: tree */
        /* { scope 8: childIndex, surfNodeIndex */
        /* { scope 9: tree */
        /* { scope 10: childIndex, surfNodeIndex */
        /* { scope 11: tree */
        ".Lff3c9c_000f4413:\n"
        "movl 0x195eebc, %ecx\n" /* line 146 */
        "movl 0x109c(%ecx), %eax\n"
        "movl -0x44(%ebp), %ecx\n" /* tree */
        "movl 0x1c(%ecx), %edx\n"
        "leal (%edx, %edx, 2), %edx\n"
        "movl 0x14(%eax), %eax\n"
        "leal (%eax, %edx, 4), %edx\n"
        "movl 0x18(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lff3c9c_000f466a\n"
        /* } scope */
        /* } scope */
        ".Lff3c9c_000f4439:\n"
        "addl $1, -0x48(%ebp)\n" /* line 141 | childIndex */
        "addl $0x30, -0x2c(%ebp)\n"
        "movl -0x48(%ebp), %edx\n" /* childIndex */
        "movl -0x4c(%ebp), %eax\n" /* tree */
        "cmpl %edx, 0x28(%eax)\n"
        "jle .Lff3c9c_000f464a\n"
        "movss (%ebx), %xmm1\n" /* mins */
        "jmp .Lff3c9c_000f3f58\n"
        /* { scope 10: childIndex, surfNodeIndex */
        /* { scope 11: tree */
        /* { scope 12: childIndex, surfNodeIndex */
        /* { scope 13 */
        ".Lff3c9c_000f4459:\n"
        "movl $0, -0x38(%ebp)\n" /* childIndex */
        "movl $0, -0x34(%ebp)\n"
        ".Lff3c9c_000f4467:\n"
        "movl -0x34(%ebp), %eax\n" /* line 142 */
        "movl -0x3c(%ebp), %edx\n" /* tree */
        "addl 0x2c(%edx), %eax\n"
        "movl 0x10(%ebp), %ecx\n" /* surfCount */
        "movl %ecx, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* surfListSize */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* surfList */
        "movl %ecx, (%esp)\n"
        "movl %edi, %ecx\n" /* maxs */
        "movl %ebx, %edx\n" /* mins */
        "calll R_AABBTreeSurfaces_r\n"
        "addl $1, -0x38(%ebp)\n" /* line 141 | childIndex */
        "addl $0x30, -0x34(%ebp)\n"
        "movl -0x38(%ebp), %edx\n" /* childIndex */
        "movl -0x3c(%ebp), %eax\n" /* tree */
        "cmpl %edx, 0x28(%eax)\n"
        "jg .Lff3c9c_000f4467\n"
        "jmp .Lff3c9c_000f4042\n"
        ".Lff3c9c_000f44a5:\n"
        "movl 0x195eebc, %ecx\n" /* line 146 */
        "movl 0x109c(%ecx), %eax\n"
        "movl -0x3c(%ebp), %ecx\n" /* tree */
        "movl 0x1c(%ecx), %edx\n"
        "leal (%edx, %edx, 2), %edx\n"
        "movl 0x14(%eax), %eax\n"
        "leal (%eax, %edx, 4), %edx\n"
        "movl 0x18(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lff3c9c_000f4042\n"
        "movl 0x10(%ebp), %ecx\n" /* surfCount */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x7c(%ebp)\n"
        "cmpl %ecx, 0xc(%ebp)\n" /* surfListSize */
        "jle .Lff3c9c_000f4042\n"
        "movl $0, -0x8c(%ebp)\n" /* surfNodeIndex */
        ".Lff3c9c_000f44e6:\n"
        "movl (%edx), %eax\n" /* line 148 */
        "testb $4, 0xc(%eax)\n"
        "jne .Lff3c9c_000f454f\n"
        "movl 8(%edx), %eax\n" /* line 150 */
        "movss (%ebx), %xmm1\n" /* line 151 | mins */
        "ucomiss 0x10(%eax), %xmm1\n"
        "ja .Lff3c9c_000f454f\n"
        "movss 4(%eax), %xmm0\n"
        "ucomiss (%edi), %xmm0\n" /* maxs */
        "ja .Lff3c9c_000f454f\n"
        "movl -0x78(%ebp), %ecx\n" /* line 153 */
        "movss (%ecx), %xmm0\n"
        "ucomiss 0x14(%eax), %xmm0\n"
        "ja .Lff3c9c_000f454f\n"
        "movss 8(%eax), %xmm0\n"
        "movl -0x74(%ebp), %ecx\n"
        "ucomiss (%ecx), %xmm0\n"
        "ja .Lff3c9c_000f454f\n"
        "movl -0x70(%ebp), %ecx\n" /* line 155 */
        "movss (%ecx), %xmm0\n"
        "ucomiss 0x18(%eax), %xmm0\n"
        "ja .Lff3c9c_000f454f\n"
        "movss 0xc(%eax), %xmm0\n"
        "movl -0x6c(%ebp), %eax\n"
        "ucomiss (%eax), %xmm0\n"
        "ja .Lff3c9c_000f454f\n"
        "movl -0x7c(%ebp), %ecx\n" /* line 158 */
        "movl 8(%ebp), %eax\n" /* surfList */
        "movl %edx, (%eax, %ecx, 4)\n"
        "movl 0x10(%ebp), %ecx\n" /* line 159 | surfCount */
        "movl (%ecx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, -0x7c(%ebp)\n"
        "movl %eax, (%ecx)\n"
        ".Lff3c9c_000f454f:\n"
        "addl $1, -0x8c(%ebp)\n" /* line 146 | surfNodeIndex */
        "addl $0xc, %edx\n"
        "movl -0x8c(%ebp), %eax\n" /* surfNodeIndex */
        "movl -0x3c(%ebp), %ecx\n" /* tree */
        "cmpl %eax, 0x18(%ecx)\n"
        "jle .Lff3c9c_000f4042\n"
        "movl -0x7c(%ebp), %ecx\n"
        "cmpl %ecx, 0xc(%ebp)\n" /* surfListSize */
        "jg .Lff3c9c_000f44e6\n"
        "jmp .Lff3c9c_000f4042\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lff3c9c_000f457c:\n"
        "movl 0x195eebc, %ecx\n"
        "movl 0x109c(%ecx), %eax\n"
        "movl -0x4c(%ebp), %ecx\n" /* tree */
        "movl 0x1c(%ecx), %edx\n"
        "leal (%edx, %edx, 2), %edx\n"
        "movl 0x14(%eax), %eax\n"
        "leal (%eax, %edx, 4), %edx\n"
        "movl 0x18(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lff3c9c_000f464a\n"
        "movl 0x10(%ebp), %ecx\n" /* surfCount */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x7c(%ebp)\n"
        "cmpl %ecx, 0xc(%ebp)\n" /* surfListSize */
        "jle .Lff3c9c_000f464a\n"
        "movl $0, -0x8c(%ebp)\n" /* surfNodeIndex */
        ".Lff3c9c_000f45bd:\n"
        "movl (%edx), %eax\n" /* line 148 */
        "testb $4, 0xc(%eax)\n"
        "jne .Lff3c9c_000f4626\n"
        "movl 8(%edx), %eax\n" /* line 150 */
        "movss (%ebx), %xmm1\n" /* line 151 | mins */
        "ucomiss 0x10(%eax), %xmm1\n"
        "ja .Lff3c9c_000f4626\n"
        "movss 4(%eax), %xmm0\n"
        "ucomiss (%edi), %xmm0\n" /* maxs */
        "ja .Lff3c9c_000f4626\n"
        "movl -0x78(%ebp), %ecx\n" /* line 153 */
        "movss (%ecx), %xmm0\n"
        "ucomiss 0x14(%eax), %xmm0\n"
        "ja .Lff3c9c_000f4626\n"
        "movss 8(%eax), %xmm0\n"
        "movl -0x74(%ebp), %ecx\n"
        "ucomiss (%ecx), %xmm0\n"
        "ja .Lff3c9c_000f4626\n"
        "movl -0x70(%ebp), %ecx\n" /* line 155 */
        "movss (%ecx), %xmm0\n"
        "ucomiss 0x18(%eax), %xmm0\n"
        "ja .Lff3c9c_000f4626\n"
        "movss 0xc(%eax), %xmm0\n"
        "movl -0x6c(%ebp), %eax\n"
        "ucomiss (%eax), %xmm0\n"
        "ja .Lff3c9c_000f4626\n"
        "movl -0x7c(%ebp), %ecx\n" /* line 158 */
        "movl 8(%ebp), %eax\n" /* surfList */
        "movl %edx, (%eax, %ecx, 4)\n"
        "movl 0x10(%ebp), %ecx\n" /* line 159 | surfCount */
        "movl (%ecx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, -0x7c(%ebp)\n"
        "movl %eax, (%ecx)\n"
        ".Lff3c9c_000f4626:\n"
        "addl $1, -0x8c(%ebp)\n" /* line 146 | surfNodeIndex */
        "addl $0xc, %edx\n"
        "movl -0x8c(%ebp), %eax\n" /* surfNodeIndex */
        "movl -0x4c(%ebp), %ecx\n" /* tree */
        "cmpl %eax, 0x18(%ecx)\n"
        "jle .Lff3c9c_000f464a\n"
        "movl -0x7c(%ebp), %ecx\n"
        "cmpl %ecx, 0xc(%ebp)\n" /* surfListSize */
        "jg .Lff3c9c_000f45bd\n"
        /* } scope */
        /* } scope */
        ".Lff3c9c_000f464a:\n"
        "addl $1, -0x50(%ebp)\n" /* line 141 | childIndex */
        "addl $0x30, -0x28(%ebp)\n"
        "movl -0x50(%ebp), %edx\n" /* childIndex */
        "movl -0x54(%ebp), %eax\n" /* tree */
        "cmpl 0x28(%eax), %edx\n"
        "jge .Lff3c9c_000f43f3\n"
        "movss (%ebx), %xmm1\n" /* mins */
        "jmp .Lff3c9c_000f3ed0\n"
        /* { scope 8: childIndex, surfNodeIndex */
        /* { scope 9: tree */
        /* { scope 10: childIndex, surfNodeIndex */
        /* { scope 11: tree */
        ".Lff3c9c_000f466a:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 146 | surfCount */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x7c(%ebp)\n"
        "cmpl %ecx, 0xc(%ebp)\n" /* surfListSize */
        "jle .Lff3c9c_000f4439\n"
        "movl $0, -0x8c(%ebp)\n" /* surfNodeIndex */
        ".Lff3c9c_000f4685:\n"
        "movl (%edx), %eax\n" /* line 148 */
        "testb $4, 0xc(%eax)\n"
        "jne .Lff3c9c_000f46ee\n"
        "movl 8(%edx), %eax\n" /* line 150 */
        "movss (%ebx), %xmm1\n" /* line 151 | mins */
        "ucomiss 0x10(%eax), %xmm1\n"
        "ja .Lff3c9c_000f46ee\n"
        "movss 4(%eax), %xmm0\n"
        "ucomiss (%edi), %xmm0\n" /* maxs */
        "ja .Lff3c9c_000f46ee\n"
        "movl -0x78(%ebp), %ecx\n" /* line 153 */
        "movss (%ecx), %xmm0\n"
        "ucomiss 0x14(%eax), %xmm0\n"
        "ja .Lff3c9c_000f46ee\n"
        "movss 8(%eax), %xmm0\n"
        "movl -0x74(%ebp), %ecx\n"
        "ucomiss (%ecx), %xmm0\n"
        "ja .Lff3c9c_000f46ee\n"
        "movl -0x70(%ebp), %ecx\n" /* line 155 */
        "movss (%ecx), %xmm0\n"
        "ucomiss 0x18(%eax), %xmm0\n"
        "ja .Lff3c9c_000f46ee\n"
        "movss 0xc(%eax), %xmm0\n"
        "movl -0x6c(%ebp), %eax\n"
        "ucomiss (%eax), %xmm0\n"
        "ja .Lff3c9c_000f46ee\n"
        "movl -0x7c(%ebp), %ecx\n" /* line 158 */
        "movl 8(%ebp), %eax\n" /* surfList */
        "movl %edx, (%eax, %ecx, 4)\n"
        "movl 0x10(%ebp), %ecx\n" /* line 159 | surfCount */
        "movl (%ecx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, -0x7c(%ebp)\n"
        "movl %eax, (%ecx)\n"
        ".Lff3c9c_000f46ee:\n"
        "addl $1, -0x8c(%ebp)\n" /* line 146 | surfNodeIndex */
        "addl $0xc, %edx\n"
        "movl -0x8c(%ebp), %eax\n" /* surfNodeIndex */
        "movl -0x44(%ebp), %ecx\n" /* tree */
        "cmpl %eax, 0x18(%ecx)\n"
        "jle .Lff3c9c_000f4439\n"
        "movl -0x7c(%ebp), %ecx\n"
        "cmpl %ecx, 0xc(%ebp)\n" /* surfListSize */
        "jg .Lff3c9c_000f4685\n"
        "jmp .Lff3c9c_000f4439\n"
    );
}

/* line 178 */
static __attribute__((naked))
void R_CellSurfaces(const vec_t *mins, const vec_t *maxs, GfxSurface * *surfList, int surfListSize, int *surfCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 178 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl %eax, %ebx\n" /* cell */
        "movl %edx, -0x30(%ebp)\n"
        "movl %ecx, -0x5c(%ebp)\n"
        /* { scope 1: listIndex */
        "movl 0x195eec8, %eax\n" /* line 186 */
        "movl 0x20(%eax), %eax\n"
        "cmpl %eax, (%ebx)\n" /* cell */
        "je .Lff471c_000f48de\n"
        "movl %eax, (%ebx)\n" /* line 188 | cell */
        "movl 0x28(%ebx), %eax\n" /* line 190 | cell */
        "testl %eax, %eax\n"
        "jle .Lff471c_000f48e6\n"
        "xorl %esi, %esi\n" /* cullGroupIndex */
        "movss (%edx), %xmm1\n"
        "addl $4, %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "addl $4, %ecx\n"
        "movl %ecx, -0x3c(%ebp)\n"
        "movl -0x30(%ebp), %eax\n"
        "addl $8, %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl -0x5c(%ebp), %edx\n"
        "addl $8, %edx\n"
        "movl %edx, -0x44(%ebp)\n"
        ".Lff471c_000f476e:\n"
        "movl 0x195eebc, %ecx\n" /* line 192 */
        "movl 0x109c(%ecx), %edx\n"
        "movl 0x2c(%ebx), %eax\n" /* cell */
        "movl (%eax, %esi, 4), %ecx\n"
        "shll $5, %ecx\n"
        "addl 0xf0(%edx), %ecx\n"
        "ucomiss 0xc(%ecx), %xmm1\n" /* line 193 */
        "ja .Lff471c_000f48c9\n"
        "movss (%ecx), %xmm0\n"
        "movl -0x5c(%ebp), %edi\n"
        "ucomiss (%edi), %xmm0\n"
        "ja .Lff471c_000f48c9\n"
        "movl -0x30(%ebp), %eax\n" /* line 195 */
        "movss 4(%eax), %xmm0\n"
        "ucomiss 0x10(%ecx), %xmm0\n"
        "ja .Lff471c_000f48c9\n"
        "movss 4(%ecx), %xmm0\n"
        "ucomiss 4(%edi), %xmm0\n"
        "ja .Lff471c_000f48c9\n"
        "movss 8(%eax), %xmm0\n" /* line 197 */
        "ucomiss 0x14(%ecx), %xmm0\n"
        "ja .Lff471c_000f48c9\n"
        "movss 8(%ecx), %xmm0\n"
        "ucomiss 8(%edi), %xmm0\n"
        "ja .Lff471c_000f48c9\n"
        "movl 0x1c(%ecx), %eax\n" /* line 200 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl 0x14(%edx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0x54(%ebp)\n" /* surf */
        "movl 0x18(%ecx), %edi\n"
        "testl %edi, %edi\n"
        "jle .Lff471c_000f48c9\n"
        "movl 0x10(%ebp), %edx\n" /* surfCount */
        "movl (%edx), %edx\n"
        "movl %edx, -0x34(%ebp)\n"
        "cmpl %edx, 0xc(%ebp)\n" /* surfListSize */
        "jle .Lff471c_000f48c9\n"
        "movl $0, -0x2c(%ebp)\n" /* triSurfIndex */
        ".Lff471c_000f4814:\n"
        "movl -0x54(%ebp), %edi\n" /* line 202 | surf */
        "movl (%edi), %eax\n"
        "testb $4, 0xc(%eax)\n"
        "jne .Lff471c_000f48ad\n"
        "movl 8(%edi), %eax\n" /* line 204 */
        "movl %eax, -0x4c(%ebp)\n" /* tris */
        "ucomiss 0x10(%eax), %xmm1\n" /* line 205 */
        "ja .Lff471c_000f48ad\n"
        "movss 4(%eax), %xmm0\n"
        "movl -0x5c(%ebp), %edx\n"
        "ucomiss (%edx), %xmm0\n"
        "ja .Lff471c_000f48ad\n"
        "movl -0x38(%ebp), %edi\n" /* line 207 */
        "movss (%edi), %xmm0\n"
        "ucomiss 0x14(%eax), %xmm0\n"
        "ja .Lff471c_000f48ad\n"
        "movss 8(%eax), %xmm0\n"
        "movl -0x3c(%ebp), %eax\n"
        "ucomiss (%eax), %xmm0\n"
        "ja .Lff471c_000f48ad\n"
        "movl -0x40(%ebp), %edx\n" /* line 209 */
        "movss (%edx), %xmm0\n"
        "movl -0x4c(%ebp), %edi\n" /* tris */
        "ucomiss 0x18(%edi), %xmm0\n"
        "ja .Lff471c_000f48ad\n"
        "movss 0xc(%edi), %xmm0\n"
        "movl -0x44(%ebp), %eax\n"
        "ucomiss (%eax), %xmm0\n"
        "ja .Lff471c_000f48ad\n"
        /* { scope 2: childIndex, surfNodeIndex, tris */
        "movl -0x34(%ebp), %edx\n" /* line 168 */
        "testl %edx, %edx\n"
        "jle .Lff471c_000f4a73\n"
        "movl -0x54(%ebp), %edi\n" /* line 170 | surf */
        "movl 8(%ebp), %edx\n" /* surfList */
        "cmpl (%edx), %edi\n"
        "je .Lff471c_000f48ad\n"
        "movl $0, -0x4c(%ebp)\n" /* tris */
        ".Lff471c_000f488f:\n"
        "addl $1, -0x4c(%ebp)\n" /* line 168 | tris */
        "movl -0x4c(%ebp), %eax\n" /* tris */
        "cmpl %eax, -0x34(%ebp)\n"
        "je .Lff471c_000f4a73\n"
        "movl -0x54(%ebp), %edi\n" /* line 170 | surf */
        "movl -0x4c(%ebp), %eax\n" /* tris */
        "movl 8(%ebp), %edx\n" /* surfList */
        "cmpl (%edx, %eax, 4), %edi\n"
        "jne .Lff471c_000f488f\n"
        /* } scope */
        ".Lff471c_000f48ad:\n"
        "addl $1, -0x2c(%ebp)\n" /* line 200 | triSurfIndex */
        "addl $0xc, -0x54(%ebp)\n" /* surf */
        "movl -0x2c(%ebp), %edx\n" /* triSurfIndex */
        "cmpl 0x18(%ecx), %edx\n"
        "jge .Lff471c_000f48c9\n"
        "movl -0x34(%ebp), %edi\n"
        "cmpl %edi, 0xc(%ebp)\n" /* surfListSize */
        "jg .Lff471c_000f4814\n"
        ".Lff471c_000f48c9:\n"
        "addl $1, %esi\n" /* line 190 | cullGroupIndex */
        "cmpl 0x28(%ebx), %esi\n" /* cell, cullGroupIndex */
        "jl .Lff471c_000f476e\n"
        "movl 0x1c(%ebx), %ebx\n" /* line 216 | tree */
        /* { scope 2: childIndex, surfNodeIndex, tris */
        /* { scope 3 */
        "ucomiss 0xc(%ebx), %xmm1\n" /* line 132 */
        "jbe .Lff471c_000f48f6\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lff471c_000f48de:\n"
        "addl $0x6c, %esp\n" /* line 217 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lff471c_000f48e6:\n"
        "movl -0x30(%ebp), %eax\n"
        "movss (%eax), %xmm1\n"
        /* { scope 1: listIndex */
        "movl 0x1c(%ebx), %ebx\n" /* line 216 | tree */
        /* { scope 2: childIndex, surfNodeIndex, tris */
        /* { scope 3 */
        "ucomiss 0xc(%ebx), %xmm1\n" /* line 132 */
        "ja .Lff471c_000f48de\n"
        ".Lff471c_000f48f6:\n"
        "movss (%ebx), %xmm0\n"
        "movl -0x5c(%ebp), %edx\n"
        "ucomiss (%edx), %xmm0\n"
        "ja .Lff471c_000f48de\n"
        "movl -0x30(%ebp), %esi\n" /* line 134 */
        "addl $4, %esi\n"
        "movl -0x30(%ebp), %ecx\n"
        "movss 4(%ecx), %xmm0\n"
        "ucomiss 0x10(%ebx), %xmm0\n"
        "ja .Lff471c_000f48de\n"
        "addl $4, %edx\n"
        "movl %edx, -0x28(%ebp)\n"
        "movss 4(%ebx), %xmm0\n"
        "movl -0x5c(%ebp), %edi\n"
        "ucomiss 4(%edi), %xmm0\n"
        "ja .Lff471c_000f48de\n"
        "addl $8, %ecx\n" /* line 136 */
        "movl %ecx, -0x24(%ebp)\n"
        "movl -0x30(%ebp), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "ucomiss 0x14(%ebx), %xmm0\n"
        "ja .Lff471c_000f48de\n"
        "addl $8, %edi\n"
        "movl %edi, -0x20(%ebp)\n"
        "movss 8(%ebx), %xmm0\n"
        "movl -0x5c(%ebp), %edx\n"
        "ucomiss 8(%edx), %xmm0\n"
        "ja .Lff471c_000f48de\n"
        "cmpl $0, 0x28(%ebx)\n" /* line 139 */
        "jne .Lff471c_000f4a2c\n"
        "movl 0x195eebc, %eax\n" /* line 146 */
        "movl 0x109c(%eax), %edx\n"
        "movl 0x1c(%ebx), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl 0x14(%edx), %edx\n"
        "leal (%edx, %eax, 4), %edx\n"
        "movl 0x18(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lff471c_000f48de\n"
        "movl 0x10(%ebp), %eax\n" /* surfCount */
        "movl (%eax), %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "cmpl %eax, 0xc(%ebp)\n" /* surfListSize */
        "jle .Lff471c_000f48de\n"
        "movl $0, -0x50(%ebp)\n" /* surfNodeIndex */
        ".Lff471c_000f4996:\n"
        "movl (%edx), %eax\n" /* line 148 */
        "testb $4, 0xc(%eax)\n"
        "jne .Lff471c_000f4a08\n"
        "movl 8(%edx), %edi\n" /* line 150 */
        "movl %edi, -0x4c(%ebp)\n" /* tris */
        "movl -0x30(%ebp), %eax\n" /* line 151 */
        "movss (%eax), %xmm0\n"
        "ucomiss 0x10(%edi), %xmm0\n"
        "ja .Lff471c_000f4a08\n"
        "movss 4(%edi), %xmm0\n"
        "movl -0x5c(%ebp), %ecx\n"
        "ucomiss (%ecx), %xmm0\n"
        "ja .Lff471c_000f4a08\n"
        "movss (%esi), %xmm0\n" /* line 153 */
        "ucomiss 0x14(%edi), %xmm0\n"
        "ja .Lff471c_000f4a08\n"
        "movss 8(%edi), %xmm0\n"
        "movl -0x28(%ebp), %edi\n"
        "ucomiss (%edi), %xmm0\n"
        "ja .Lff471c_000f4a08\n"
        "movl -0x24(%ebp), %eax\n" /* line 155 */
        "movss (%eax), %xmm0\n"
        "movl -0x4c(%ebp), %ecx\n" /* tris */
        "ucomiss 0x18(%ecx), %xmm0\n"
        "ja .Lff471c_000f4a08\n"
        "movss 0xc(%ecx), %xmm0\n"
        "movl -0x20(%ebp), %edi\n"
        "ucomiss (%edi), %xmm0\n"
        "ja .Lff471c_000f4a08\n"
        "movl -0x34(%ebp), %eax\n" /* line 158 */
        "movl 8(%ebp), %ecx\n" /* surfList */
        "movl %edx, (%ecx, %eax, 4)\n"
        "movl 0x10(%ebp), %edi\n" /* line 159 | surfCount */
        "movl (%edi), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl %eax, (%edi)\n"
        ".Lff471c_000f4a08:\n"
        "addl $1, -0x50(%ebp)\n" /* line 146 | surfNodeIndex */
        "addl $0xc, %edx\n"
        "movl -0x50(%ebp), %ecx\n" /* surfNodeIndex */
        "cmpl %ecx, 0x18(%ebx)\n"
        "jle .Lff471c_000f48de\n"
        "movl -0x34(%ebp), %edi\n"
        "cmpl %edi, 0xc(%ebp)\n" /* surfListSize */
        "jg .Lff471c_000f4996\n"
        "jmp .Lff471c_000f48de\n"
        ".Lff471c_000f4a2c:\n"
        "jle .Lff471c_000f48de\n" /* line 141 */
        "movl $0, -0x1c(%ebp)\n" /* childIndex */
        "xorl %esi, %esi\n"
        ".Lff471c_000f4a3b:\n"
        "movl %esi, %eax\n" /* line 142 */
        "addl 0x2c(%ebx), %eax\n"
        "movl 0x10(%ebp), %ecx\n" /* surfCount */
        "movl %ecx, 8(%esp)\n"
        "movl 0xc(%ebp), %edi\n" /* surfListSize */
        "movl %edi, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* surfList */
        "movl %edx, (%esp)\n"
        "movl -0x5c(%ebp), %ecx\n"
        "movl -0x30(%ebp), %edx\n"
        "calll R_AABBTreeSurfaces_r\n"
        "addl $1, -0x1c(%ebp)\n" /* line 141 | childIndex */
        "addl $0x30, %esi\n"
        "movl -0x1c(%ebp), %ecx\n" /* childIndex */
        "cmpl 0x28(%ebx), %ecx\n"
        "jl .Lff471c_000f4a3b\n"
        "jmp .Lff471c_000f48de\n"
        /* } scope */
        /* } scope */
        /* { scope 2: childIndex, surfNodeIndex, tris */
        ".Lff471c_000f4a73:\n"
        "movl -0x54(%ebp), %eax\n" /* line 173 | surf */
        "movl -0x34(%ebp), %edx\n"
        "movl 8(%ebp), %edi\n" /* surfList */
        "movl %eax, (%edi, %edx, 4)\n"
        "movl 0x10(%ebp), %edx\n" /* line 174 | surfCount */
        "movl (%edx), %edi\n"
        "addl $1, %edi\n"
        "movl %edi, -0x34(%ebp)\n"
        "movl %edi, (%edx)\n"
        "movl -0x30(%ebp), %eax\n"
        "movss (%eax), %xmm1\n"
        "jmp .Lff471c_000f48ad\n"
    );
}

/* line 220 */
static __attribute__((naked))
void R_BoxSurfaces_r(mnode_t *node, const vec_t *mins, const vec_t *maxs, GfxSurface * *surfList, int surfListSize, int *surfCount)
{
    __asm__ __volatile__ (
        ".Lff4a98_000f4a98:\n"
        "pushl %ebp\n" /* line 220 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl %edx, -0x34(%ebp)\n"
        "movl %ecx, -0x38(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* surfList */
        "movl %eax, -0x3c(%ebp)\n" /* surfList */
        "movl 0xc(%ebp), %edx\n" /* surfListSize */
        "movl %edx, -0x40(%ebp)\n" /* surfListSize */
        "movl 0x10(%ebp), %eax\n" /* surfCount */
        "movl %eax, -0x44(%ebp)\n" /* surfCount */
        /* { scope 1: node */
        ".Lff4a98_000f4abc:\n"
        "movl -0x30(%ebp), %edx\n" /* line 225 */
        "movl 8(%edx), %ebx\n"
        "cmpl $-2, %ebx\n"
        "jne .Lff4a98_000f4fea\n"
        "movl -0x30(%ebp), %edx\n" /* line 227 */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll BoxOnPlaneSide\n"
        "cmpl $1, %eax\n" /* line 228 */
        "je .Lff4a98_000f4fdc\n"
        "cmpl $2, %eax\n" /* line 232 */
        "je .Lff4a98_000f4fce\n"
        "movl -0x30(%ebp), %eax\n" /* line 238 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* node */
        /* { scope 2 */
        /* { scope 3: node */
        ".Lff4a98_000f4b02:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 225 | node */
        "movl 8(%eax), %ebx\n"
        "cmpl $-2, %ebx\n"
        "jne .Lff4a98_000f4f7d\n"
        "movl -0x2c(%ebp), %edx\n" /* line 227 | node */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll BoxOnPlaneSide\n"
        "cmpl $1, %eax\n" /* line 228 */
        "je .Lff4a98_000f4f6f\n"
        "cmpl $2, %eax\n" /* line 232 */
        "je .Lff4a98_000f4f61\n"
        "movl -0x2c(%ebp), %eax\n" /* line 238 | node */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* node */
        /* { scope 4 */
        /* { scope 5: node */
        ".Lff4a98_000f4b48:\n"
        "movl -0x28(%ebp), %edx\n" /* line 225 | node */
        "movl 8(%edx), %ebx\n"
        "cmpl $-2, %ebx\n"
        "jne .Lff4a98_000f4f1e\n"
        "movl -0x28(%ebp), %edx\n" /* line 227 | node */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll BoxOnPlaneSide\n"
        "cmpl $1, %eax\n" /* line 228 */
        "je .Lff4a98_000f4f10\n"
        "cmpl $2, %eax\n" /* line 232 */
        "je .Lff4a98_000f4f02\n"
        "movl -0x28(%ebp), %eax\n" /* line 238 | node */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* node */
        "movl %eax, %edx\n"
        /* { scope 6 */
        /* { scope 7: node */
        ".Lff4a98_000f4b90:\n"
        "movl 8(%edx), %ebx\n" /* line 225 */
        "cmpl $-2, %ebx\n"
        "jne .Lff4a98_000f4e47\n"
        ".Lff4a98_000f4b9c:\n"
        "movl 0xc(%edx), %eax\n" /* line 227 */
        "movl %eax, 8(%esp)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll BoxOnPlaneSide\n"
        "cmpl $1, %eax\n" /* line 228 */
        "je .Lff4a98_000f4ee4\n"
        "cmpl $2, %eax\n" /* line 232 */
        "je .Lff4a98_000f4ef4\n"
        "movl -0x24(%ebp), %eax\n" /* line 238 | node */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* node */
        "movl %eax, %edx\n"
        /* { scope 8 */
        /* { scope 9: node */
        ".Lff4a98_000f4bd2:\n"
        "movl 8(%edx), %ebx\n" /* line 225 */
        "cmpl $-2, %ebx\n"
        "jne .Lff4a98_000f4ded\n"
        ".Lff4a98_000f4bde:\n"
        "movl 0xc(%edx), %eax\n" /* line 227 */
        "movl %eax, 8(%esp)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll BoxOnPlaneSide\n"
        "cmpl $1, %eax\n" /* line 228 */
        "je .Lff4a98_000f4ec6\n"
        "cmpl $2, %eax\n" /* line 232 */
        "je .Lff4a98_000f4ed6\n"
        "movl -0x20(%ebp), %eax\n" /* line 238 | node */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* node */
        "movl %eax, %edx\n"
        /* { scope 10 */
        /* { scope 11 */
        ".Lff4a98_000f4c14:\n"
        "movl 8(%edx), %ebx\n" /* line 225 */
        "cmpl $-2, %ebx\n"
        "jne .Lff4a98_000f4d93\n"
        ".Lff4a98_000f4c20:\n"
        "movl 0xc(%edx), %eax\n" /* line 227 */
        "movl %eax, 8(%esp)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll BoxOnPlaneSide\n"
        "cmpl $1, %eax\n" /* line 228 */
        "je .Lff4a98_000f4ea8\n"
        "cmpl $2, %eax\n" /* line 232 */
        "je .Lff4a98_000f4eb8\n"
        "movl -0x1c(%ebp), %eax\n" /* line 238 | node */
        "movl 0x10(%eax), %edi\n" /* node */
        /* { scope 12 */
        /* { scope 13 */
        ".Lff4a98_000f4c51:\n"
        "movl 8(%edi), %ebx\n" /* line 225 */
        "cmpl $-2, %ebx\n"
        "jne .Lff4a98_000f4d39\n"
        ".Lff4a98_000f4c5d:\n"
        "movl 0xc(%edi), %eax\n" /* line 227 */
        "movl %eax, 8(%esp)\n"
        "movl -0x38(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BoxOnPlaneSide\n"
        "cmpl $1, %eax\n" /* line 228 */
        "je .Lff4a98_000f4ea0\n"
        "cmpl $2, %eax\n" /* line 232 */
        "je .Lff4a98_000f4d2a\n"
        "movl 0x10(%edi), %ebx\n" /* line 238 | node */
        /* { scope 14 */
        /* { scope 15 */
        ".Lff4a98_000f4c8b:\n"
        "movl 8(%ebx), %esi\n" /* line 225 */
        "cmpl $-2, %esi\n"
        "jne .Lff4a98_000f4ce7\n"
        ".Lff4a98_000f4c93:\n"
        "movl 0xc(%ebx), %eax\n" /* line 227 */
        "movl %eax, 8(%esp)\n"
        "movl -0x38(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BoxOnPlaneSide\n"
        "cmpl $1, %eax\n" /* line 228 */
        "je .Lff4a98_000f4e98\n"
        "cmpl $2, %eax\n" /* line 232 */
        "je .Lff4a98_000f4cdc\n"
        "movl 0x10(%ebx), %eax\n" /* line 238 | node */
        "movl -0x44(%ebp), %edx\n" /* surfCount */
        "movl %edx, 8(%esp)\n"
        "movl -0x40(%ebp), %edx\n" /* surfListSize */
        "movl %edx, 4(%esp)\n"
        "movl -0x3c(%ebp), %edx\n" /* surfList */
        "movl %edx, (%esp)\n"
        "movl -0x38(%ebp), %ecx\n"
        "movl -0x34(%ebp), %edx\n"
        "calll R_BoxSurfaces_r\n"
        ".Lff4a98_000f4cdc:\n"
        "movl 0x14(%ebx), %ebx\n" /* line 239 | node */
        "movl 8(%ebx), %esi\n" /* line 225 */
        "cmpl $-2, %esi\n"
        "je .Lff4a98_000f4c93\n"
        ".Lff4a98_000f4ce7:\n"
        "cmpl $-1, %esi\n" /* line 243 */
        "je .Lff4a98_000f4d2a\n"
        "movl 0x195eebc, %eax\n" /* line 246 */
        "movl 0x109c(%eax), %edx\n"
        "leal (, %esi, 4), %eax\n"
        "shll $6, %esi\n"
        "subl %eax, %esi\n"
        "addl 0x100(%edx), %esi\n"
        "movl -0x44(%ebp), %edx\n" /* surfCount */
        "movl %edx, 8(%esp)\n"
        "movl -0x40(%ebp), %eax\n" /* surfListSize */
        "movl %eax, 4(%esp)\n"
        "movl -0x3c(%ebp), %edx\n" /* surfList */
        "movl %edx, (%esp)\n"
        "movl -0x38(%ebp), %ecx\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %esi, %eax\n"
        "calll R_CellSurfaces\n"
        /* } scope */
        /* } scope */
        ".Lff4a98_000f4d2a:\n"
        "movl 0x14(%edi), %edi\n" /* line 239 | node */
        "movl 8(%edi), %ebx\n" /* line 225 */
        "cmpl $-2, %ebx\n"
        "je .Lff4a98_000f4c5d\n"
        ".Lff4a98_000f4d39:\n"
        "cmpl $-1, %ebx\n" /* line 243 | node */
        "je .Lff4a98_000f4d7c\n"
        "movl 0x195eebc, %eax\n" /* line 246 */
        "movl 0x109c(%eax), %edx\n"
        "leal (, %ebx, 4), %eax\n"
        "shll $6, %ebx\n" /* node */
        "subl %eax, %ebx\n" /* node */
        "addl 0x100(%edx), %ebx\n" /* node */
        "movl -0x44(%ebp), %edx\n" /* surfCount */
        "movl %edx, 8(%esp)\n"
        "movl -0x40(%ebp), %eax\n" /* surfListSize */
        "movl %eax, 4(%esp)\n"
        "movl -0x3c(%ebp), %edx\n" /* surfList */
        "movl %edx, (%esp)\n"
        "movl -0x38(%ebp), %ecx\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %ebx, %eax\n" /* node */
        "calll R_CellSurfaces\n"
        /* } scope */
        /* } scope */
        ".Lff4a98_000f4d7c:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 239 | node */
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* node */
        "movl %eax, %edx\n"
        "movl 8(%edx), %ebx\n" /* line 225 */
        "cmpl $-2, %ebx\n"
        "je .Lff4a98_000f4c20\n"
        ".Lff4a98_000f4d93:\n"
        "cmpl $-1, %ebx\n" /* line 243 | node */
        "je .Lff4a98_000f4dd6\n"
        "movl 0x195eebc, %eax\n" /* line 246 */
        "movl 0x109c(%eax), %edx\n"
        "leal (, %ebx, 4), %eax\n"
        "shll $6, %ebx\n" /* node */
        "subl %eax, %ebx\n" /* node */
        "addl 0x100(%edx), %ebx\n" /* node */
        "movl -0x44(%ebp), %edx\n" /* surfCount */
        "movl %edx, 8(%esp)\n"
        "movl -0x40(%ebp), %eax\n" /* surfListSize */
        "movl %eax, 4(%esp)\n"
        "movl -0x3c(%ebp), %edx\n" /* surfList */
        "movl %edx, (%esp)\n"
        "movl -0x38(%ebp), %ecx\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %ebx, %eax\n" /* node */
        "calll R_CellSurfaces\n"
        /* } scope */
        /* } scope */
        ".Lff4a98_000f4dd6:\n"
        "movl -0x20(%ebp), %eax\n" /* line 239 | node */
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* node */
        "movl %eax, %edx\n"
        "movl 8(%edx), %ebx\n" /* line 225 */
        "cmpl $-2, %ebx\n"
        "je .Lff4a98_000f4bde\n"
        ".Lff4a98_000f4ded:\n"
        "cmpl $-1, %ebx\n" /* line 243 | node */
        "je .Lff4a98_000f4e30\n"
        "movl 0x195eebc, %eax\n" /* line 246 */
        "movl 0x109c(%eax), %edx\n"
        "leal (, %ebx, 4), %eax\n"
        "shll $6, %ebx\n" /* node */
        "subl %eax, %ebx\n" /* node */
        "addl 0x100(%edx), %ebx\n" /* node */
        "movl -0x44(%ebp), %edx\n" /* surfCount */
        "movl %edx, 8(%esp)\n"
        "movl -0x40(%ebp), %eax\n" /* surfListSize */
        "movl %eax, 4(%esp)\n"
        "movl -0x3c(%ebp), %edx\n" /* surfList */
        "movl %edx, (%esp)\n"
        "movl -0x38(%ebp), %ecx\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %ebx, %eax\n" /* node */
        "calll R_CellSurfaces\n"
        /* } scope */
        /* } scope */
        ".Lff4a98_000f4e30:\n"
        "movl -0x24(%ebp), %eax\n" /* line 239 | node */
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* node */
        "movl %eax, %edx\n"
        "movl 8(%edx), %ebx\n" /* line 225 */
        "cmpl $-2, %ebx\n"
        "je .Lff4a98_000f4b9c\n"
        ".Lff4a98_000f4e47:\n"
        "cmpl $-1, %ebx\n" /* line 243 | node */
        "je .Lff4a98_000f4e8a\n"
        "movl 0x195eebc, %eax\n" /* line 246 */
        "movl 0x109c(%eax), %edx\n"
        "leal (, %ebx, 4), %eax\n"
        "shll $6, %ebx\n" /* node */
        "subl %eax, %ebx\n" /* node */
        "addl 0x100(%edx), %ebx\n" /* node */
        "movl -0x44(%ebp), %edx\n" /* surfCount */
        "movl %edx, 8(%esp)\n"
        "movl -0x40(%ebp), %eax\n" /* surfListSize */
        "movl %eax, 4(%esp)\n"
        "movl -0x3c(%ebp), %edx\n" /* surfList */
        "movl %edx, (%esp)\n"
        "movl -0x38(%ebp), %ecx\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %ebx, %eax\n" /* node */
        "calll R_CellSurfaces\n"
        /* } scope */
        /* } scope */
        ".Lff4a98_000f4e8a:\n"
        "movl -0x28(%ebp), %eax\n" /* line 239 | node */
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* node */
        "jmp .Lff4a98_000f4b48\n"
        /* { scope 6 */
        /* { scope 7: node */
        /* { scope 8 */
        /* { scope 9: node */
        /* { scope 10 */
        /* { scope 11 */
        /* { scope 12 */
        /* { scope 13 */
        /* { scope 14 */
        /* { scope 15 */
        ".Lff4a98_000f4e98:\n"
        "movl 0x10(%ebx), %ebx\n" /* line 230 */
        "jmp .Lff4a98_000f4c8b\n"
        /* } scope */
        /* } scope */
        ".Lff4a98_000f4ea0:\n"
        "movl 0x10(%edi), %edi\n"
        "jmp .Lff4a98_000f4c51\n"
        /* } scope */
        /* } scope */
        ".Lff4a98_000f4ea8:\n"
        "movl -0x1c(%ebp), %eax\n" /* node */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* node */
        "movl %eax, %edx\n"
        "jmp .Lff4a98_000f4c14\n"
        ".Lff4a98_000f4eb8:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 234 | node */
        "movl 0x14(%edx), %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* node */
        "jmp .Lff4a98_000f4c14\n"
        /* } scope */
        /* } scope */
        ".Lff4a98_000f4ec6:\n"
        "movl -0x20(%ebp), %eax\n" /* line 230 | node */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* node */
        "movl %eax, %edx\n"
        "jmp .Lff4a98_000f4bd2\n"
        ".Lff4a98_000f4ed6:\n"
        "movl -0x20(%ebp), %edx\n" /* line 234 | node */
        "movl 0x14(%edx), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* node */
        "jmp .Lff4a98_000f4bd2\n"
        /* } scope */
        /* } scope */
        ".Lff4a98_000f4ee4:\n"
        "movl -0x24(%ebp), %eax\n" /* line 230 | node */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* node */
        "movl %eax, %edx\n"
        "jmp .Lff4a98_000f4b90\n"
        ".Lff4a98_000f4ef4:\n"
        "movl -0x24(%ebp), %edx\n" /* line 234 | node */
        "movl 0x14(%edx), %edx\n"
        "movl %edx, -0x24(%ebp)\n" /* node */
        "jmp .Lff4a98_000f4b90\n"
        /* } scope */
        /* } scope */
        ".Lff4a98_000f4f02:\n"
        "movl -0x28(%ebp), %edx\n" /* node */
        "movl 0x14(%edx), %edx\n"
        "movl %edx, -0x28(%ebp)\n" /* node */
        "jmp .Lff4a98_000f4b48\n"
        ".Lff4a98_000f4f10:\n"
        "movl -0x28(%ebp), %eax\n" /* line 230 | node */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* node */
        "jmp .Lff4a98_000f4b48\n"
        ".Lff4a98_000f4f1e:\n"
        "cmpl $-1, %ebx\n" /* line 243 | node */
        "je .Lff4a98_000f4f61\n"
        "movl 0x195eebc, %eax\n" /* line 246 */
        "movl 0x109c(%eax), %edx\n"
        "leal (, %ebx, 4), %eax\n"
        "shll $6, %ebx\n" /* node */
        "subl %eax, %ebx\n" /* node */
        "addl 0x100(%edx), %ebx\n" /* node */
        "movl -0x44(%ebp), %eax\n" /* surfCount */
        "movl %eax, 8(%esp)\n"
        "movl -0x40(%ebp), %edx\n" /* surfListSize */
        "movl %edx, 4(%esp)\n"
        "movl -0x3c(%ebp), %eax\n" /* surfList */
        "movl %eax, (%esp)\n"
        "movl -0x38(%ebp), %ecx\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %ebx, %eax\n" /* node */
        "calll R_CellSurfaces\n"
        /* } scope */
        /* } scope */
        ".Lff4a98_000f4f61:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 239 | node */
        "movl 0x14(%edx), %edx\n"
        "movl %edx, -0x2c(%ebp)\n" /* node */
        "jmp .Lff4a98_000f4b02\n"
        ".Lff4a98_000f4f6f:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 230 | node */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* node */
        "jmp .Lff4a98_000f4b02\n"
        ".Lff4a98_000f4f7d:\n"
        "cmpl $-1, %ebx\n" /* line 243 | node */
        "je .Lff4a98_000f4fc0\n"
        "movl 0x195eebc, %eax\n" /* line 246 */
        "movl 0x109c(%eax), %edx\n"
        "leal (, %ebx, 4), %eax\n"
        "shll $6, %ebx\n" /* node */
        "subl %eax, %ebx\n" /* node */
        "addl 0x100(%edx), %ebx\n" /* node */
        "movl -0x44(%ebp), %edx\n" /* surfCount */
        "movl %edx, 8(%esp)\n"
        "movl -0x40(%ebp), %eax\n" /* surfListSize */
        "movl %eax, 4(%esp)\n"
        "movl -0x3c(%ebp), %edx\n" /* surfList */
        "movl %edx, (%esp)\n"
        "movl -0x38(%ebp), %ecx\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %ebx, %eax\n" /* node */
        "calll R_CellSurfaces\n"
        /* } scope */
        /* } scope */
        ".Lff4a98_000f4fc0:\n"
        "movl -0x30(%ebp), %eax\n" /* line 239 */
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "jmp .Lff4a98_000f4abc\n"
        ".Lff4a98_000f4fce:\n"
        "movl -0x30(%ebp), %edx\n" /* line 234 */
        "movl 0x14(%edx), %edx\n"
        "movl %edx, -0x30(%ebp)\n"
        "jmp .Lff4a98_000f4abc\n"
        ".Lff4a98_000f4fdc:\n"
        "movl -0x30(%ebp), %eax\n" /* line 230 */
        "movl 0x10(%eax), %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "jmp .Lff4a98_000f4abc\n"
        ".Lff4a98_000f4fea:\n"
        "cmpl $-1, %ebx\n" /* line 243 | node */
        "je .Lff4a98_000f5032\n"
        "movl 0x195eebc, %eax\n" /* line 246 */
        "movl 0x109c(%eax), %edx\n"
        "leal (, %ebx, 4), %eax\n"
        "shll $6, %ebx\n" /* node */
        "subl %eax, %ebx\n" /* node */
        "addl 0x100(%edx), %ebx\n" /* node */
        "movl -0x44(%ebp), %eax\n" /* surfCount */
        "movl %eax, 0x10(%ebp)\n" /* surfCount */
        "movl -0x40(%ebp), %edx\n" /* surfListSize */
        "movl %edx, 0xc(%ebp)\n" /* surfListSize */
        "movl -0x3c(%ebp), %eax\n" /* surfList */
        "movl %eax, 8(%ebp)\n" /* surfList */
        "movl -0x38(%ebp), %ecx\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %ebx, %eax\n" /* node */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 247 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1: node */
        "jmp R_CellSurfaces\n" /* line 246 */
        /* } scope */
        ".Lff4a98_000f5032:\n"
        "addl $0x4c, %esp\n" /* line 247 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 322 */
__attribute__((naked))
int R_MarkFragments(vec3_t *points, const vec_t *origin, vec3_t *axis, float radius, int maxPoints, GfxWorldVertex *verts, int maxFragments, GfxMarkFragment *fragmentBuffer, MaterialHandle markMaterial)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 322 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x43ec, %esp\n"
        /* { scope 1: xyz, surfCount, maxPoints */
        /* { scope 2 */
        "leal -0x34(%ebp), %edi\n" /* line 309 | maxs */
        "movl %edi, 4(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* mins */
        "movl %eax, (%esp)\n"
        "calll ClearBounds\n"
        "movss 0x14(%ebp), %xmm0\n" /* line 272 | radius */
        "movl 0x10(%ebp), %edx\n" /* axis */
        "mulss (%edx), %xmm0\n"
        "movss %xmm0, -0x4378(%ebp)\n"
        "addl $4, %edx\n" /* line 273 */
        "movl %edx, -0x4394(%ebp)\n"
        "movss 0x14(%ebp), %xmm0\n" /* radius */
        "movl 0x10(%ebp), %eax\n" /* axis */
        "mulss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x437c(%ebp)\n"
        "addl $8, %eax\n" /* line 274 */
        "movl %eax, -0x4390(%ebp)\n"
        "movss 0x14(%ebp), %xmm0\n" /* radius */
        "movl 0x10(%ebp), %eax\n" /* axis */
        "mulss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x4380(%ebp)\n"
        "xorl %esi, %esi\n" /* pointIndex */
        ".Lff503a_000f50aa:\n"
        "movl 8(%ebp), %eax\n" /* line 322 | points */
        "leal (%esi, %eax), %ebx\n" /* pointIndex */
        "movss -0x4378(%ebp), %xmm0\n" /* line 240 */
        "addss (%ebx), %xmm0\n" /* from */
        "movss %xmm0, -0x64(%ebp)\n" /* xyz */
        "movss -0x437c(%ebp), %xmm0\n" /* line 241 */
        "addss 4(%ebx), %xmm0\n" /* from */
        "movss %xmm0, -0x60(%ebp)\n"
        "movss -0x4380(%ebp), %xmm0\n" /* line 242 */
        "addss 8(%ebx), %xmm0\n" /* from */
        "movss %xmm0, -0x5c(%ebp)\n"
        "movl %edi, 8(%esp)\n" /* line 315 */
        "leal -0x28(%ebp), %edx\n" /* mins */
        "movl %edx, 4(%esp)\n"
        "leal -0x64(%ebp), %ecx\n" /* xyz */
        "movl %ecx, (%esp)\n"
        "calll AddPointToBounds\n"
        "movss (%ebx), %xmm0\n" /* line 248 | from */
        "subss -0x4378(%ebp), %xmm0\n"
        "movss %xmm0, -0x64(%ebp)\n" /* xyz */
        "movss 4(%ebx), %xmm0\n" /* line 249 | from */
        "subss -0x437c(%ebp), %xmm0\n"
        "movss %xmm0, -0x60(%ebp)\n"
        "movss 8(%ebx), %xmm0\n" /* line 250 | from */
        "subss -0x4380(%ebp), %xmm0\n"
        "movss %xmm0, -0x5c(%ebp)\n"
        "movl %edi, 8(%esp)\n" /* line 317 */
        "leal -0x28(%ebp), %ebx\n" /* mins, pointIndex */
        "movl %ebx, 4(%esp)\n" /* pointIndex */
        "leal -0x64(%ebp), %eax\n" /* xyz */
        "movl %eax, (%esp)\n"
        "calll AddPointToBounds\n"
        "addl $0xc, %esi\n" /* pointIndex */
        "cmpl $0x30, %esi\n" /* line 312 | pointIndex */
        "jne .Lff503a_000f50aa\n"
        /* } scope */
        /* { scope 2 */
        "movl 0x195eec8, %eax\n" /* line 254 */
        "addl $1, 0x20(%eax)\n"
        "movl $0, -0x1c(%ebp)\n" /* line 256 | surfCount */
        "movl 0x195eebc, %eax\n" /* line 258 */
        "movl 0x109c(%eax), %eax\n"
        "movl 0xc(%eax), %ebx\n" /* node */
        /* { scope 3: inPoints */
        /* { scope 4: dists, sides, sideCount */
        ".Lff503a_000f5170:\n"
        "movl 8(%ebx), %esi\n" /* line 225 | from, pointIndex */
        "cmpl $-2, %esi\n" /* pointIndex */
        "jne .Lff503a_000f51cc\n"
        ".Lff503a_000f5178:\n"
        "movl 0xc(%ebx), %eax\n" /* line 227 | from */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "leal -0x28(%ebp), %edx\n" /* mins */
        "movl %edx, (%esp)\n"
        "calll BoxOnPlaneSide\n"
        "cmpl $1, %eax\n" /* line 228 */
        "je .Lff503a_000f52e0\n"
        "cmpl $2, %eax\n" /* line 232 */
        "je .Lff503a_000f51c1\n"
        "movl 0x10(%ebx), %eax\n" /* line 238 | from */
        "leal -0x1c(%ebp), %ecx\n" /* surfCount */
        "movl %ecx, 8(%esp)\n"
        "movl $__mh_execute_header, 4(%esp)\n"
        "leal -0x4354(%ebp), %edx\n" /* surfaces */
        "movl %edx, (%esp)\n"
        "movl %edi, %ecx\n"
        "leal -0x28(%ebp), %edx\n" /* mins */
        "calll R_BoxSurfaces_r\n"
        ".Lff503a_000f51c1:\n"
        "movl 0x14(%ebx), %ebx\n" /* line 239 | from */
        "movl 8(%ebx), %esi\n" /* line 225 | from, pointIndex */
        "cmpl $-2, %esi\n" /* pointIndex */
        "je .Lff503a_000f5178\n"
        ".Lff503a_000f51cc:\n"
        "cmpl $-1, %esi\n" /* line 243 | pointIndex */
        "je .Lff503a_000f5212\n"
        "movl 0x195eebc, %eax\n" /* line 246 */
        "movl 0x109c(%eax), %edx\n"
        "leal (, %esi, 4), %eax\n"
        "shll $6, %esi\n" /* pointIndex */
        "subl %eax, %esi\n" /* pointIndex */
        "addl 0x100(%edx), %esi\n" /* pointIndex */
        "leal -0x1c(%ebp), %eax\n" /* surfCount */
        "movl %eax, 8(%esp)\n"
        "movl $__mh_execute_header, 4(%esp)\n"
        "leal -0x4354(%ebp), %eax\n" /* surfaces */
        "movl %eax, (%esp)\n"
        "movl %edi, %ecx\n"
        "leal -0x28(%ebp), %edx\n" /* mins */
        "movl %esi, %eax\n" /* pointIndex */
        "calll R_CellSurfaces\n"
        /* } scope */
        /* } scope */
        ".Lff503a_000f5212:\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 260 | surfCount */
        "movl %ecx, -0x43bc(%ebp)\n" /* surfCount */
        "movl 8(%ebp), %esi\n" /* points, pointIndex */
        "xorl %edx, %edx\n"
        /* } scope */
        "leal 1(%edx), %edi\n" /* line 358 | pointIndex */
        "movl %edi, %eax\n" /* pointIndex, a */
        "andl $0x80000003, %eax\n" /* a */
        "js .Lff503a_000f52d2\n"
        ".Lff503a_000f5230:\n"
        "leal (%eax, %eax, 2), %eax\n" /* a */
        "movl 8(%ebp), %ebx\n" /* points, pointIndex */
        "leal (%ebx, %eax, 4), %eax\n" /* pointIndex, a */
        /* { scope 2 */
        "movss (%eax), %xmm0\n" /* line 248 */
        "subss (%esi), %xmm0\n" /* pointIndex */
        "movss %xmm0, -0x4c(%ebp)\n" /* edge01 */
        "movss 4(%eax), %xmm0\n" /* line 249 */
        "subss 4(%esi), %xmm0\n" /* pointIndex */
        "movss %xmm0, -0x48(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 250 */
        "subss 8(%esi), %xmm0\n" /* pointIndex */
        "movss %xmm0, -0x44(%ebp)\n"
        /* } scope */
        "leal (%edx, %edx, 2), %ebx\n" /* line 359 | pointIndex */
        "leal -0x114(%ebp, %ebx, 4), %ebx\n" /* pointIndex */
        "movl %ebx, 8(%esp)\n" /* pointIndex */
        "movl 0x10(%ebp), %eax\n" /* axis */
        "movl %eax, 4(%esp)\n"
        "leal -0x4c(%ebp), %edx\n" /* edge01 */
        "movl %edx, (%esp)\n"
        "calll Vec3Cross\n"
        "movl %ebx, (%esp)\n" /* line 360 | pointIndex */
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movss (%ebx), %xmm1\n" /* line 361 | pointIndex */
        "mulss (%esi), %xmm1\n" /* pointIndex */
        "movss 4(%ebx), %xmm0\n" /* pointIndex */
        "mulss 4(%esi), %xmm0\n" /* pointIndex */
        "addss %xmm0, %xmm1\n"
        "movss 8(%ebx), %xmm0\n" /* pointIndex */
        "mulss 8(%esi), %xmm0\n" /* pointIndex */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x80(%ebp, %edi, 4)\n"
        "addl $0xc, %esi\n" /* pointIndex */
        "cmpl $4, %edi\n" /* line 356 | pointIndex */
        "je .Lff503a_000f52e8\n"
        "movl %edi, %edx\n" /* pointIndex */
        "leal 1(%edx), %edi\n" /* line 358 | pointIndex */
        "movl %edi, %eax\n" /* pointIndex, a */
        "andl $0x80000003, %eax\n" /* a */
        "jns .Lff503a_000f5230\n"
        ".Lff503a_000f52d2:\n"
        "subl $1, %eax\n" /* a */
        "orl $0xfffffffc, %eax\n" /* a */
        "addl $1, %eax\n" /* a */
        "jmp .Lff503a_000f5230\n"
        /* { scope 2 */
        /* { scope 3: inPoints */
        /* { scope 4: dists, sides, sideCount */
        ".Lff503a_000f52e0:\n"
        "movl 0x10(%ebx), %ebx\n" /* line 230 | from */
        "jmp .Lff503a_000f5170\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lff503a_000f52e8:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 199 | axis */
        "movss (%ecx), %xmm1\n"
        "movss %xmm1, -0xe4(%ebp)\n"
        "movl -0x4394(%ebp), %ebx\n" /* line 200 | from */
        "movss (%ebx), %xmm3\n" /* from */
        "movss %xmm3, -0xe0(%ebp)\n"
        "movl -0x4390(%ebp), %edi\n" /* line 201 */
        "movss (%edi), %xmm4\n"
        "movss %xmm4, -0xdc(%ebp)\n"
        "movaps %xmm1, %xmm0\n" /* line 367 */
        "movl 8(%ebp), %eax\n" /* points */
        "mulss (%eax), %xmm0\n"
        "movaps %xmm3, %xmm2\n"
        "mulss 4(%eax), %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movaps %xmm4, %xmm2\n"
        "mulss 8(%eax), %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "subss 0x14(%ebp), %xmm0\n" /* radius */
        "movss %xmm0, -0x6c(%ebp)\n"
        "movss 0x2f2ba0, %xmm0\n" /* line 216 */
        "xorps %xmm0, %xmm1\n"
        "movss %xmm1, -0xd8(%ebp)\n"
        "xorps %xmm0, %xmm3\n" /* line 217 */
        "movss %xmm3, -0xd4(%ebp)\n"
        "xorps %xmm0, %xmm4\n" /* line 218 */
        "movss %xmm4, -0xd0(%ebp)\n"
        "mulss (%eax), %xmm1\n" /* line 369 */
        "mulss 4(%eax), %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%eax), %xmm4\n"
        "addss %xmm4, %xmm1\n"
        "subss 0x14(%ebp), %xmm1\n" /* radius */
        "movss %xmm1, -0x68(%ebp)\n"
        "movss 0x2ed5d8, %xmm0\n" /* line 371 | 0.5f */
        "movaps %xmm0, %xmm1\n"
        "divss 0x14(%ebp), %xmm1\n" /* radius */
        "movss %xmm1, -0x439c(%ebp)\n" /* texCoordScale */
        "movl -0x43bc(%ebp), %esi\n" /* line 375 | surfCount, pointIndex */
        "testl %esi, %esi\n" /* pointIndex */
        "jle .Lff503a_000f5cad\n"
        "movl %ecx, %eax\n"
        "movl %ecx, %ebx\n" /* pointIndex */
        "movl %ecx, %edi\n" /* pointIndex */
        "movl $0, -0x43b8(%ebp)\n" /* surfIndex */
        "movl $0, -0x43ac(%ebp)\n" /* returnedPoints */
        "movl $0, -0x43b0(%ebp)\n" /* returnedFragments */
        "addl $0x1c, %eax\n"
        "movl %eax, -0x43c4(%ebp)\n"
        "leal -0x4354(%ebp), %edx\n" /* surfaces */
        "movl %edx, -0x43c8(%ebp)\n"
        "movl 0xc(%ebp), %ecx\n" /* origin */
        "addl $8, %ecx\n"
        "movl %ecx, -0x43d4(%ebp)\n"
        "addl $0xc, %ebx\n" /* pointIndex */
        "movl %ebx, -0x43d8(%ebp)\n" /* pointIndex */
        "addl $0x18, %edi\n" /* pointIndex */
        "movl %edi, -0x43dc(%ebp)\n" /* pointIndex */
        "movl 0x10(%ebp), %eax\n" /* axis */
        "addl $0x20, %eax\n"
        "movl %eax, -0x43e0(%ebp)\n"
        "movl $0, -0x43e4(%ebp)\n"
        "movl %edx, %ecx\n"
        "jmp .Lff503a_000f544d\n"
        ".Lff503a_000f5427:\n"
        "addl $1, -0x43b8(%ebp)\n" /* surfIndex */
        "addl $4, -0x43c8(%ebp)\n"
        "movl -0x43b8(%ebp), %ebx\n" /* surfIndex, pointIndex */
        "cmpl %ebx, -0x43bc(%ebp)\n" /* pointIndex, surfCount */
        "je .Lff503a_000f5cb7\n"
        "movl -0x43c8(%ebp), %ecx\n"
        ".Lff503a_000f544d:\n"
        "movl (%ecx), %edx\n" /* line 377 */
        "movl (%edx), %eax\n"
        "testb $0x30, 0x30(%eax)\n"
        "jne .Lff503a_000f5427\n"
        "movl 8(%edx), %edx\n" /* line 381 */
        "movl %edx, -0x43a0(%ebp)\n" /* tris */
        "movl 0x195eebc, %eax\n" /* line 382 */
        "movl 0x109c(%eax), %ecx\n"
        "movl %edx, %ebx\n" /* pointIndex */
        "movl 0x1c(%edx), %edx\n"
        "movl %edx, %eax\n"
        "shll $6, %eax\n"
        "leal (%eax, %edx, 4), %edx\n"
        "movl %edx, -0x43a4(%ebp)\n" /* triVerts */
        "movl 0x2c(%ecx), %edi\n" /* pointIndex */
        "addl %edi, %edx\n" /* pointIndex */
        "movl %edx, -0x43a4(%ebp)\n" /* triVerts */
        "cmpw $0, 0x22(%ebx)\n" /* line 384 | pointIndex */
        "je .Lff503a_000f5427\n"
        "movl $0, -0x43b4(%ebp)\n" /* triIndex */
        "movl $0, -0x4364(%ebp)\n"
        "movl -0x43e4(%ebp), %eax\n"
        "addl 0x24(%ebp), %eax\n" /* fragmentBuffer */
        "movl %eax, -0x43c0(%ebp)\n"
        "movl 0xc(%ebp), %edx\n" /* origin */
        "addl $4, %edx\n"
        "movl %edx, -0x43cc(%ebp)\n"
        "movl 0x10(%ebp), %ecx\n" /* axis */
        "addl $0x10, %ecx\n"
        "movl %ecx, -0x43d0(%ebp)\n"
        "movl -0x43a0(%ebp), %ebx\n" /* tris, pointIndex */
        ".Lff503a_000f54d1:\n"
        "movl -0x4364(%ebp), %edx\n" /* line 386 */
        "addl 0x24(%ebx), %edx\n" /* pointIndex */
        "movzwl 2(%edx), %ecx\n" /* b */
        "movl %ecx, %eax\n" /* b, a */
        "shll $6, %eax\n" /* a */
        "leal (%eax, %ecx, 4), %ecx\n" /* b */
        "addl -0x43a4(%ebp), %ecx\n" /* triVerts, b */
        "movzwl (%edx), %eax\n" /* a */
        "movl %eax, %edx\n" /* a */
        "shll $6, %edx\n"
        "leal (%edx, %eax, 4), %eax\n" /* a */
        "addl -0x43a4(%ebp), %eax\n" /* triVerts, a */
        /* { scope 2 */
        "movss (%eax), %xmm0\n" /* line 248 */
        "subss (%ecx), %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n" /* edge01 */
        "movss 4(%eax), %xmm0\n" /* line 249 */
        "subss 4(%ecx), %xmm0\n"
        "movss %xmm0, -0x48(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 250 */
        "subss 8(%ecx), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        /* } scope */
        "movl -0x4364(%ebp), %edx\n" /* line 387 */
        "addl 0x24(%ebx), %edx\n" /* pointIndex */
        "movzwl 2(%edx), %ecx\n" /* b */
        "movl %ecx, %eax\n" /* b, a */
        "shll $6, %eax\n" /* a */
        "leal (%eax, %ecx, 4), %ecx\n" /* b */
        "addl -0x43a4(%ebp), %ecx\n" /* triVerts, b */
        "movzwl 4(%edx), %eax\n" /* a */
        "movl %eax, %edx\n" /* a */
        "shll $6, %edx\n"
        "leal (%edx, %eax, 4), %eax\n" /* a */
        "addl -0x43a4(%ebp), %eax\n" /* triVerts, a */
        /* { scope 2 */
        "movss (%eax), %xmm0\n" /* line 248 */
        "subss (%ecx), %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n" /* edge21 */
        "movss 4(%eax), %xmm0\n" /* line 249 */
        "subss 4(%ecx), %xmm0\n"
        "movss %xmm0, -0x54(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 250 */
        "subss 8(%ecx), %xmm0\n"
        "movss %xmm0, -0x50(%ebp)\n"
        /* } scope */
        "leal -0x40(%ebp), %edi\n" /* line 388 | scaledNormal, pointIndex */
        "movl %edi, 8(%esp)\n" /* pointIndex */
        "leal -0x58(%ebp), %eax\n" /* edge21 */
        "movl %eax, 4(%esp)\n"
        "leal -0x4c(%ebp), %edx\n" /* edge01 */
        "movl %edx, (%esp)\n"
        "calll Vec3Cross\n"
        "movss -0x40(%ebp), %xmm2\n" /* line 304 | scaledNormal */
        "movss -0x3c(%ebp), %xmm3\n"
        "movss -0x38(%ebp), %xmm4\n"
        "movaps %xmm2, %xmm1\n"
        "movl 0x10(%ebp), %ecx\n" /* axis */
        "mulss (%ecx), %xmm1\n"
        "movaps %xmm3, %xmm0\n"
        "movl -0x4394(%ebp), %ebx\n" /* pointIndex */
        "mulss (%ebx), %xmm0\n" /* pointIndex */
        "addss %xmm0, %xmm1\n"
        "movaps %xmm4, %xmm0\n"
        "movl -0x4390(%ebp), %edi\n"
        "mulss (%edi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "ucomiss 0x2ed5e8, %xmm1\n" /* line 390 | 0.0f */
        "jp .Lff503a_000f55e3\n"
        "jb .Lff503a_000f58bd\n"
        ".Lff503a_000f55e3:\n"
        "mulss %xmm1, %xmm1\n" /* line 392 */
        "mulss %xmm2, %xmm2\n"
        "mulss %xmm3, %xmm3\n"
        "addss %xmm3, %xmm2\n"
        "mulss %xmm4, %xmm4\n"
        "addss %xmm4, %xmm2\n"
        "mulss 0x2ed604, %xmm2\n" /* 0.25f */
        "ucomiss %xmm1, %xmm2\n"
        "ja .Lff503a_000f58bd\n"
        "movl -0x4364(%ebp), %ebx\n" /* line 393 | pointIndex */
        "xorl %esi, %esi\n" /* pointIndex */
        "leal -0x354(%ebp), %ecx\n" /* clipPoints */
        "addl $0x10, %ecx\n"
        ".Lff503a_000f561d:\n"
        "movl -0x43a0(%ebp), %edx\n" /* line 397 | tris */
        "movl 0x24(%edx), %eax\n" /* from */
        "movzwl (%eax, %ebx), %eax\n" /* from */
        "movl %eax, %edx\n" /* from */
        "shll $6, %edx\n"
        "leal (%edx, %eax, 4), %eax\n" /* from */
        "addl -0x43a4(%ebp), %eax\n" /* triVerts, from */
        /* { scope 2 */
        "movl (%eax), %edx\n" /* line 199 */
        "movl %edx, -0x10(%ecx)\n"
        "movl 4(%eax), %edx\n" /* line 200 */
        "movl %edx, -0xc(%ecx)\n"
        "movl 8(%eax), %eax\n" /* line 201 */
        "movl %eax, -8(%ecx)\n"
        /* } scope */
        "movl -0x43a0(%ebp), %edi\n" /* line 398 | tris, pointIndex */
        "movl 0x24(%edi), %eax\n" /* pointIndex */
        "movzwl (%eax, %ebx), %eax\n"
        "movl %eax, %edx\n"
        "shll $6, %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "addl -0x43a4(%ebp), %eax\n" /* triVerts */
        "movl 0x24(%eax), %edx\n" /* line 37 */
        "movl %edx, -4(%ecx)\n"
        "movl 0x28(%eax), %eax\n" /* line 38 */
        "movl %eax, (%ecx)\n"
        "movl 0x24(%edi), %eax\n" /* line 400 | pointIndex */
        "movzwl (%ebx, %eax), %eax\n" /* pointIndex */
        "movl %eax, %edx\n" /* from */
        "shll $6, %edx\n" /* from */
        "leal (%edx, %eax, 4), %eax\n"
        "addl -0x43a4(%ebp), %eax\n" /* triVerts */
        "leal 0xc(%eax), %edx\n" /* from */
        /* { scope 2 */
        "movl 0xc(%eax), %eax\n" /* line 199 */
        "movl %eax, 4(%ecx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 8(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 0xc(%ecx)\n"
        /* } scope */
        "addl $1, %esi\n" /* line 395 | pointIndex */
        "addl $0x20, %ecx\n"
        "addl $2, %ebx\n" /* pointIndex */
        "cmpl $3, %esi\n" /* pointIndex */
        "jne .Lff503a_000f561d\n"
        "movl -0x43ac(%ebp), %eax\n" /* line 408 | returnedPoints */
        "shll $6, %eax\n"
        "movl -0x43ac(%ebp), %edx\n" /* returnedPoints */
        "leal (%eax, %edx, 4), %eax\n"
        "addl 0x1c(%ebp), %eax\n" /* verts */
        "movl %eax, -0x4398(%ebp)\n" /* outVerts */
        "movl 0x18(%ebp), %ecx\n" /* line 409 | maxPoints */
        "subl %edx, %ecx\n"
        "movl %ecx, -0x438c(%ebp)\n" /* maxPoints */
        "movl $0, -0x43a8(%ebp)\n" /* pingPong */
        "movl $3, -0x435c(%ebp)\n"
        "movl $1, -0x436c(%ebp)\n"
        "leal -0x114(%ebp), %ebx\n" /* normals, pointIndex */
        "movl %ebx, -0x4368(%ebp)\n" /* pointIndex */
        /* { scope 2 */
        /* { scope 3: inPoints */
        ".Lff503a_000f56fb:\n"
        "movl -0x436c(%ebp), %edi\n" /* line 276 */
        "movss -0x80(%ebp, %edi, 4), %xmm5\n" /* planeDist */
        "movl -0x43a8(%ebp), %ebx\n" /* pingPong, pointIndex */
        "testl %ebx, %ebx\n" /* pointIndex */
        "je .Lff503a_000f59d0\n"
        "leal -0x354(%ebp), %eax\n" /* clipPoints */
        "movl %eax, -0x4374(%ebp)\n"
        ".Lff503a_000f5721:\n"
        "movl -0x43a8(%ebp), %ecx\n" /* pingPong */
        "leal (%ecx, %ecx, 8), %eax\n"
        "shll $5, %eax\n"
        "leal -0x354(%ebp), %ebx\n" /* clipPoints, pointIndex */
        "addl %eax, %ebx\n" /* pointIndex */
        "movl %ebx, -0x4388(%ebp)\n" /* pointIndex, inPoints */
        /* { scope 4: dists, sides, sideCount */
        /* { scope 5 */
        "movl $0, -0x64(%ebp)\n" /* line 59 | xyz */
        "movl $0, -0x60(%ebp)\n" /* line 60 */
        "movl $0, -0x5c(%ebp)\n" /* line 61 */
        "movl -0x435c(%ebp), %edx\n" /* line 64 */
        "testl %edx, %edx\n"
        "jg .Lff503a_000f591c\n"
        "xorl %edx, %edx\n"
        ".Lff503a_000f5760:\n"
        "movl -0xa4(%ebp), %eax\n" /* line 75 | sides */
        "movl %eax, -0xa4(%ebp, %edx, 4)\n"
        "movl -0xcc(%ebp), %eax\n" /* line 76 | dists */
        "movl %eax, -0xcc(%ebp, %edx, 4)\n"
        "movl -0x64(%ebp), %eax\n" /* line 78 | xyz */
        "testl %eax, %eax\n"
        "jne .Lff503a_000f58e8\n"
        "movl $0, -0x435c(%ebp)\n"
        /* } scope */
        /* } scope */
        ".Lff503a_000f578f:\n"
        "xorl $1, -0x43a8(%ebp)\n" /* line 278 | pingPong */
        "movl -0x435c(%ebp), %eax\n" /* line 279 */
        "testl %eax, %eax\n"
        "je .Lff503a_000f58bd\n"
        "addl $1, -0x436c(%ebp)\n"
        "addl $0xc, -0x4368(%ebp)\n"
        "cmpl $7, -0x436c(%ebp)\n" /* line 274 */
        "jne .Lff503a_000f56fb\n"
        "movl -0x435c(%ebp), %ecx\n" /* line 284 */
        "cmpl %ecx, -0x438c(%ebp)\n" /* maxPoints */
        "jl .Lff503a_000f58bd\n"
        "movl -0x43c0(%ebp), %ebx\n" /* line 287 | pointIndex */
        "movb %cl, 6(%ebx)\n" /* pointIndex */
        "movl -0x435c(%ebp), %eax\n" /* line 288 */
        "testl %eax, %eax\n"
        "jle .Lff503a_000f5841\n"
        "movl -0x43a8(%ebp), %edi\n" /* pingPong */
        "leal (%edi, %edi, 8), %eax\n"
        "shll $5, %eax\n"
        "xorl %ebx, %ebx\n" /* pointIndex */
        "movl -0x4398(%ebp), %ecx\n" /* outVerts */
        "addl $0xc, %ecx\n"
        "leal -0x344(%ebp, %eax), %edx\n"
        ".Lff503a_000f5802:\n"
        "movl -0x10(%edx), %eax\n" /* line 199 */
        "movl %eax, -0xc(%ecx)\n"
        "movl -0xc(%edx), %eax\n" /* line 200 */
        "movl %eax, -8(%ecx)\n"
        "movl -8(%edx), %eax\n" /* line 201 */
        "movl %eax, -4(%ecx)\n"
        "movl -4(%edx), %eax\n" /* line 37 */
        "movl %eax, 0x18(%ecx)\n"
        "movl (%edx), %eax\n" /* line 38 */
        "movl %eax, 0x1c(%ecx)\n"
        "movl 4(%edx), %eax\n" /* line 199 */
        "movl %eax, (%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 0xc(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        "addl $1, %ebx\n" /* line 288 | pointIndex */
        "addl $0x20, %edx\n"
        "addl $0x44, %ecx\n"
        "cmpl -0x435c(%ebp), %ebx\n" /* pointIndex */
        "jne .Lff503a_000f5802\n"
        /* } scope */
        /* } scope */
        ".Lff503a_000f5841:\n"
        "movl -0x43a8(%ebp), %eax\n" /* line 410 | pingPong */
        "testl %eax, %eax\n"
        "js .Lff503a_000f58bd\n"
        "movl -0x43c0(%ebp), %eax\n" /* line 413 */
        "cmpb $0, 6(%eax)\n"
        "jne .Lff503a_000f5cc8\n"
        "movl %eax, %ecx\n"
        ".Lff503a_000f585d:\n"
        "movl 0x28(%ebp), %ebx\n" /* line 430 | markMaterial, pointIndex */
        "movl %ebx, (%ecx)\n" /* pointIndex */
        "movl -0x43c8(%ebp), %edi\n" /* line 431 | pointIndex */
        "movl (%edi), %eax\n" /* pointIndex */
        "movzwl 4(%eax), %eax\n"
        "movw %ax, 4(%ecx)\n"
        "movl -0x43ac(%ebp), %eax\n" /* line 432 | returnedPoints */
        "movl %eax, 8(%ecx)\n"
        "movzbl 6(%ecx), %eax\n" /* line 433 */
        "addl %eax, -0x43ac(%ebp)\n" /* returnedPoints */
        "addl $1, -0x43b0(%ebp)\n" /* line 434 | returnedFragments */
        "addl $0xc, -0x43e4(%ebp)\n"
        "addl $0xc, %ecx\n"
        "movl %ecx, -0x43c0(%ebp)\n"
        "movl 0x20(%ebp), %edx\n" /* line 435 | maxFragments */
        "cmpl %edx, -0x43b0(%ebp)\n" /* returnedFragments */
        "je .Lff503a_000f5cb7\n"
        "movl 0x18(%ebp), %eax\n" /* maxPoints */
        "subl $3, %eax\n"
        "cmpl %eax, -0x43ac(%ebp)\n" /* returnedPoints */
        "jg .Lff503a_000f5cb7\n"
        ".Lff503a_000f58bd:\n"
        "addl $3, -0x43b4(%ebp)\n" /* line 384 | triIndex */
        "addl $6, -0x4364(%ebp)\n"
        "movl -0x43a0(%ebp), %ecx\n" /* tris */
        "movzwl 0x22(%ecx), %eax\n"
        "cmpl %eax, -0x43b4(%ebp)\n" /* triIndex */
        "jge .Lff503a_000f5427\n"
        "movl %ecx, %ebx\n" /* pointIndex */
        "jmp .Lff503a_000f54d1\n"
        /* { scope 2 */
        /* { scope 3: inPoints */
        /* { scope 4: dists, sides, sideCount */
        /* { scope 5 */
        ".Lff503a_000f58e8:\n"
        "movl -0x60(%ebp), %eax\n" /* line 81 */
        "testl %eax, %eax\n"
        "je .Lff503a_000f5c83\n"
        "movl -0x435c(%ebp), %ecx\n" /* line 91 */
        "testl %ecx, %ecx\n"
        "jg .Lff503a_000f59e1\n"
        "movl $0, -0x4360(%ebp)\n"
        ".Lff503a_000f590b:\n"
        "movl -0x4360(%ebp), %edx\n"
        "movl %edx, -0x435c(%ebp)\n"
        "jmp .Lff503a_000f578f\n"
        ".Lff503a_000f591c:\n"
        "movl %ebx, %edx\n" /* from */
        "movl -0x4368(%ebp), %edi\n" /* line 304 */
        "movss (%edi), %xmm4\n"
        "movss 4(%edi), %xmm3\n"
        "movss 8(%edi), %xmm2\n"
        "xorl %ebx, %ebx\n" /* pointIndex */
        "movss 0x2ed63c, %xmm6\n" /* -0.5f */
        "xorl %ecx, %ecx\n"
        "jmp .Lff503a_000f5968\n"
        ".Lff503a_000f5940:\n"
        "xorl %eax, %eax\n" /* line 70 */
        "ucomiss %xmm1, %xmm6\n"
        "setbe %al\n"
        "addl $1, %eax\n"
        "movl %eax, -0xa4(%ecx, %ebp)\n"
        "addl $1, -0x64(%ebp, %eax, 4)\n" /* line 73 */
        "addl $1, %ebx\n" /* line 64 | from */
        "addl $4, %ecx\n"
        "addl $0x20, %edx\n"
        "cmpl -0x435c(%ebp), %ebx\n" /* from */
        "je .Lff503a_000f59c5\n"
        ".Lff503a_000f5968:\n"
        "movaps %xmm4, %xmm1\n" /* line 66 */
        "mulss (%edx), %xmm1\n"
        "movaps %xmm3, %xmm0\n"
        "mulss 4(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 8(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "subss %xmm5, %xmm1\n"
        "movss %xmm1, -0xcc(%ecx, %ebp)\n"
        "ucomiss 0x2ed5d8, %xmm1\n" /* line 67 | 0.5f */
        "jbe .Lff503a_000f5940\n"
        "movl $0, -0xa4(%ecx, %ebp)\n" /* line 68 */
        "movl -0xa4(%ecx, %ebp), %eax\n"
        "addl $1, -0x64(%ebp, %eax, 4)\n" /* line 73 */
        "addl $1, %ebx\n" /* line 64 | from */
        "addl $4, %ecx\n"
        "addl $0x20, %edx\n"
        "cmpl -0x435c(%ebp), %ebx\n" /* from */
        "jne .Lff503a_000f5968\n"
        ".Lff503a_000f59c5:\n"
        "movl -0x435c(%ebp), %edx\n"
        "jmp .Lff503a_000f5760\n"
        /* } scope */
        /* } scope */
        ".Lff503a_000f59d0:\n"
        "leal -0x234(%ebp), %edx\n" /* line 276 */
        "movl %edx, -0x4374(%ebp)\n"
        "jmp .Lff503a_000f5721\n"
        /* { scope 4: dists, sides, sideCount */
        /* { scope 5 */
        ".Lff503a_000f59e1:\n"
        "xorl %esi, %esi\n" /* line 91 | pointIndex */
        "movl $0, -0x4360(%ebp)\n"
        "jmp .Lff503a_000f5c0c\n"
        ".Lff503a_000f59f2:\n"
        "testl %ebx, %ebx\n" /* line 101 | from */
        "jne .Lff503a_000f5aad\n"
        "movl -0x4360(%ebp), %ecx\n" /* line 104 */
        "shll $5, %ecx\n"
        "movl %esi, %edx\n" /* pointIndex */
        "shll $5, %edx\n"
        "movl -0x4388(%ebp), %edi\n" /* inPoints */
        "movl (%edx, %edi), %eax\n"
        "movl -0x4374(%ebp), %edi\n"
        "movl %eax, (%ecx, %edi)\n"
        "movl -0x4388(%ebp), %edi\n" /* inPoints */
        "movl 4(%edx, %edi), %eax\n"
        "movl -0x4374(%ebp), %edi\n"
        "movl %eax, 4(%ecx, %edi)\n"
        "movl -0x4388(%ebp), %edi\n" /* inPoints */
        "movl 8(%edx, %edi), %eax\n"
        "movl -0x4374(%ebp), %edi\n"
        "movl %eax, 8(%ecx, %edi)\n"
        "movl -0x4388(%ebp), %edi\n" /* inPoints */
        "movl 0xc(%edx, %edi), %eax\n"
        "movl -0x4374(%ebp), %edi\n"
        "movl %eax, 0xc(%ecx, %edi)\n"
        "movl -0x4388(%ebp), %edi\n" /* inPoints */
        "movl 0x10(%edx, %edi), %eax\n"
        "movl -0x4374(%ebp), %edi\n"
        "movl %eax, 0x10(%ecx, %edi)\n"
        "movl -0x4388(%ebp), %edi\n" /* inPoints */
        "movl 0x14(%edx, %edi), %eax\n"
        "movl -0x4374(%ebp), %edi\n"
        "movl %eax, 0x14(%ecx, %edi)\n"
        "movl -0x4388(%ebp), %edi\n" /* inPoints */
        "movl 0x18(%edx, %edi), %eax\n"
        "movl -0x4374(%ebp), %edi\n"
        "movl %eax, 0x18(%ecx, %edi)\n"
        "movl -0x4388(%ebp), %edi\n" /* inPoints */
        "movl 0x1c(%edx, %edi), %eax\n"
        "movl -0x4374(%ebp), %edx\n"
        "movl %eax, 0x1c(%ecx, %edx)\n"
        "addl $1, -0x4360(%ebp)\n" /* line 105 */
        ".Lff503a_000f5aad:\n"
        "leal 1(%esi), %edi\n" /* line 108 | pointIndex */
        "movl -0xa4(%ebp, %edi, 4), %eax\n"
        "cmpl $2, %eax\n"
        "je .Lff503a_000f5bfe\n"
        "cmpl %eax, %ebx\n" /* from */
        "je .Lff503a_000f5bfe\n"
        "movss -0xcc(%ebp, %esi, 4), %xmm2\n" /* line 114 */
        "movaps %xmm2, %xmm0\n"
        "subss -0xcc(%ebp, %edi, 4), %xmm0\n"
        "divss %xmm0, %xmm2\n"
        "movl -0x4360(%ebp), %ecx\n" /* line 117 | out */
        "shll $5, %ecx\n" /* out */
        "addl -0x4374(%ebp), %ecx\n" /* out */
        "movl %edi, %eax\n" /* from */
        "cltd\n"
        "idivl -0x435c(%ebp)\n"
        "shll $5, %edx\n" /* to */
        "addl -0x4388(%ebp), %edx\n" /* inPoints, to */
        "shll $5, %esi\n" /* pointIndex */
        "movl -0x4388(%ebp), %eax\n" /* inPoints, from */
        "addl %esi, %eax\n" /* pointIndex, from */
        /* { scope 6: result */
        "movss (%eax), %xmm1\n" /* line 264 */
        "movss (%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%ecx)\n"
        "movss 4(%eax), %xmm1\n" /* line 265 */
        "movss 4(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%ecx)\n"
        "movss 8(%eax), %xmm1\n" /* line 266 */
        "movss 8(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%ecx)\n"
        "movss 0xc(%eax), %xmm1\n" /* line 79 */
        "movss 0xc(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0xc(%ecx)\n"
        "movss 0x10(%eax), %xmm1\n" /* line 80 */
        "movss 0x10(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x10(%ecx)\n"
        "leal 0x14(%ecx), %ebx\n" /* line 36 | from */
        "movl %ebx, -0x4384(%ebp)\n" /* from, result */
        "leal 0x14(%edx), %esi\n" /* to */
        "leal 0x14(%eax), %ebx\n" /* from */
        /* { scope 7 */
        "movss 0x14(%eax), %xmm1\n" /* line 264 */
        "movss 0x14(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x14(%ecx)\n"
        "movss 4(%ebx), %xmm1\n" /* line 265 | node */
        "movss 4(%esi), %xmm0\n" /* pointIndex */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movl -0x4384(%ebp), %eax\n" /* result */
        "movss %xmm1, 4(%eax)\n"
        "movss 8(%ebx), %xmm1\n" /* line 266 | node */
        "movss 8(%esi), %xmm0\n" /* pointIndex */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, 8(%eax)\n"
        /* } scope */
        /* } scope */
        "addl $1, -0x4360(%ebp)\n" /* line 118 */
        ".Lff503a_000f5bfe:\n"
        "cmpl -0x435c(%ebp), %edi\n" /* line 91 */
        "jge .Lff503a_000f590b\n"
        "movl %edi, %esi\n" /* line 84 | pointIndex */
        ".Lff503a_000f5c0c:\n"
        "movl -0xa4(%ebp, %esi, 4), %ebx\n" /* line 93 | from */
        "cmpl $2, %ebx\n" /* from */
        "jne .Lff503a_000f59f2\n"
        "movl -0x4360(%ebp), %ecx\n" /* line 96 */
        "shll $5, %ecx\n"
        "movl %esi, %edx\n" /* pointIndex */
        "shll $5, %edx\n"
        "movl -0x4388(%ebp), %ebx\n" /* inPoints, from */
        "movl (%edx, %ebx), %eax\n"
        "movl -0x4374(%ebp), %edi\n"
        "movl %eax, (%ecx, %edi)\n"
        "movl 4(%edx, %ebx), %eax\n"
        "movl %eax, 4(%ecx, %edi)\n"
        "movl 8(%edx, %ebx), %eax\n"
        "movl %eax, 8(%ecx, %edi)\n"
        "movl 0xc(%edx, %ebx), %eax\n"
        "movl %eax, 0xc(%ecx, %edi)\n"
        "movl 0x10(%edx, %ebx), %eax\n"
        "movl %eax, 0x10(%ecx, %edi)\n"
        "movl 0x14(%edx, %ebx), %eax\n"
        "movl %eax, 0x14(%ecx, %edi)\n"
        "movl 0x18(%edx, %ebx), %eax\n"
        "movl %eax, 0x18(%ecx, %edi)\n"
        "movl 0x1c(%edx, %ebx), %eax\n"
        "movl %eax, 0x1c(%ecx, %edi)\n"
        "addl $1, -0x4360(%ebp)\n" /* line 97 */
        "leal 1(%esi), %edi\n" /* pointIndex */
        "jmp .Lff503a_000f5bfe\n"
        ".Lff503a_000f5c83:\n"
        "movl -0x435c(%ebp), %eax\n" /* line 84 */
        "shll $5, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x4388(%ebp), %eax\n" /* inPoints */
        "movl %eax, 4(%esp)\n"
        "movl -0x4374(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "jmp .Lff503a_000f578f\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lff503a_000f5cad:\n"
        "movl $0, -0x43b0(%ebp)\n" /* line 375 | returnedFragments */
        /* } scope */
        ".Lff503a_000f5cb7:\n"
        "movl -0x43b0(%ebp), %eax\n" /* line 440 | returnedFragments */
        "addl $0x43ec, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: xyz, surfCount, maxPoints */
        ".Lff503a_000f5cc8:\n"
        "movl 0x10(%ebp), %edx\n" /* line 413 | axis */
        "addl $0x14, %edx\n"
        "movl %edx, -0x4370(%ebp)\n"
        "xorl %edi, %edi\n" /* pointIndex */
        "movl -0x4398(%ebp), %esi\n" /* outVerts, pointIndex */
        "addl $0xc, %esi\n" /* pointIndex */
        ".Lff503a_000f5cdf:\n"
        "movss -0xc(%esi), %xmm1\n" /* line 248 | pointIndex */
        "movl 0xc(%ebp), %ecx\n" /* origin */
        "subss (%ecx), %xmm1\n"
        "movss -8(%esi), %xmm3\n" /* line 249 | pointIndex */
        "movl -0x43cc(%ebp), %ebx\n" /* from */
        "subss (%ebx), %xmm3\n" /* from */
        "movss -4(%esi), %xmm4\n" /* line 250 | pointIndex */
        "movl -0x43d4(%ebp), %eax\n"
        "subss (%eax), %xmm4\n"
        "movaps %xmm1, %xmm0\n" /* line 416 */
        "movl -0x43d8(%ebp), %edx\n"
        "mulss (%edx), %xmm0\n"
        "movaps %xmm3, %xmm2\n"
        "movl -0x43d0(%ebp), %ecx\n"
        "mulss (%ecx), %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movaps %xmm4, %xmm2\n"
        "movl -0x4370(%ebp), %ebx\n" /* pointIndex */
        "mulss (%ebx), %xmm2\n" /* pointIndex */
        "addss %xmm2, %xmm0\n"
        "mulss -0x439c(%ebp), %xmm0\n" /* texCoordScale */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, 0x10(%esi)\n" /* pointIndex */
        "movl -0x43dc(%ebp), %eax\n" /* line 417 */
        "mulss (%eax), %xmm1\n"
        "movl -0x43c4(%ebp), %edx\n"
        "mulss (%edx), %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "movl -0x43e0(%ebp), %ecx\n"
        "mulss (%ecx), %xmm4\n"
        "addss %xmm4, %xmm1\n"
        "mulss -0x439c(%ebp), %xmm1\n" /* texCoordScale */
        "addss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "movss %xmm1, 0x14(%esi)\n" /* pointIndex */
        "movl -0x4398(%ebp), %ebx\n" /* line 419 | outVerts, pointIndex */
        "addl $0x2c, %ebx\n" /* pointIndex */
        "movl %ebx, 8(%esp)\n" /* pointIndex */
        "movl -0x43d8(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* pointIndex */
        "calll Vec3Cross\n"
        "movl -0x4398(%ebp), %eax\n" /* line 420 | outVerts */
        "addl $0x38, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* pointIndex */
        "movl %ebx, (%esp)\n" /* pointIndex */
        "calll Vec3Cross\n"
        "addl $1, %edi\n" /* line 413 | pointIndex */
        "addl $0x44, -0x4398(%ebp)\n" /* outVerts */
        "addl $0x44, %esi\n" /* pointIndex */
        "movl -0x43c0(%ebp), %edx\n"
        "movzbl 6(%edx), %eax\n"
        "cmpl %eax, %edi\n" /* pointIndex */
        "jl .Lff503a_000f5cdf\n"
        "movl %edx, %ecx\n"
        "jmp .Lff503a_000f585d\n"
    );
}

