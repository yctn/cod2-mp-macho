/* ASM dump from: r_xsurface_optimize.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_xsurface_optimize.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/gfx_d3d/r_local.h"
 */

void XSurfaceOptimizeRigid(XModel *model, XSurface *surface, XVertexBuffer *surfVerts);
void XModelOptimize(XModel *model);
void XModelUnoptimize(XModel *model);

/* line 12 */
__attribute__((naked))
void XSurfaceOptimizeRigid(XModel *model, XSurface *surface, XVertexBuffer *surfVerts)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 12 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* surface */
        /* { scope 1 */
        "leal 0x10(%esi), %edi\n" /* line 21 | surface, surfRigid */
        "movl 0x10(%esi), %eax\n" /* line 29 | surface */
        "testl %eax, %eax\n"
        "je .Lffc318_000fc336\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 79 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lffc318_000fc336:\n"
        "movswl 2(%esi), %ebx\n" /* line 33 | surface */
        "movl 0x195eec0, %edx\n" /* line 1067 */
        "movl (%edx), %eax\n"
        "movl $0x24, %edx\n"
        "cmpl $2, 8(%eax)\n"
        "movl $0x40, %eax\n"
        "cmovnel %eax, %edx\n"
        "movl 0x195eed0, %eax\n" /* line 45 */
        "movl 8(%eax), %eax\n"
        "movl (%eax), %ecx\n"
        "movl $0, 0x18(%esp)\n"
        "movl %edi, 0x14(%esp)\n" /* surfRigid */
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $8, 8(%esp)\n"
        "imull %ebx, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x68(%ecx)\n"
        "testl %eax, %eax\n" /* line 46 */
        "js .Lffc318_000fc405\n"
        "movl 0x10(%esi), %edx\n" /* line 52 | surface */
        "movl (%edx), %ecx\n"
        "movl $0, 0x10(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* vertexBuffer */
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x2c(%ecx)\n"
        "testl %eax, %eax\n" /* line 53 */
        "js .Lffc318_000fc3fa\n"
        "movl 0x195eec0, %edx\n" /* line 62 */
        "movl (%edx), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lffc318_000fc414\n"
        "movswl 2(%esi), %eax\n" /* line 69 | surface */
        "movl %eax, 8(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* vertexBuffer */
        "movl %eax, 4(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* surfVerts */
        "movl %edx, (%esp)\n"
        "calll XSurfaceTransfer\n"
        ".Lffc318_000fc3e8:\n"
        "movl (%edi), %eax\n" /* line 77 | surfRigid */
        "movl %eax, (%esp)\n"
        "calll R_FinishStaticVertexBuffer\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 79 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lffc318_000fc3fa:\n"
        "movl 0x10(%esi), %eax\n" /* line 55 | surface */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        ".Lffc318_000fc405:\n"
        "movl $0, 0x10(%esi)\n" /* line 56 | surface */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 79 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lffc318_000fc414:\n"
        "movswl 2(%esi), %eax\n" /* line 64 | surface */
        "movl %eax, 8(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* vertexBuffer */
        "movl %eax, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* surfVerts */
        "movl %eax, (%esp)\n"
        "calll XSurfaceTransferDx7\n"
        "jmp .Lffc318_000fc3e8\n"
    );
}

/* line 142 */
__attribute__((naked))
void XModelOptimize(XModel *model)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 142 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        /* { scope 1 */
        "movl 0x195eee0, %ebx\n" /* line 153 */
        "movl 8(%ebp), %eax\n" /* model */
        "movl %eax, (%esp)\n"
        "calll *0x174(%ebx)\n"
        "movl %eax, -0x34(%ebp)\n" /* lodCount */
        "testl %eax, %eax\n" /* line 154 */
        "jg .Lffc430_000fc45a\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 160 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lffc430_000fc45a:\n"
        "movl $0, -0x38(%ebp)\n" /* line 154 | lodIndex */
        "movl %ebx, -0x3c(%ebp)\n"
        "movl -0x38(%ebp), %eax\n" /* lodIndex */
        ".Lffc430_000fc467:\n"
        "leal -0x20(%ebp), %edx\n" /* line 156 | partBits */
        "movl %edx, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x1c(%ebp), %edx\n" /* surfaces */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* model */
        "movl %eax, (%esp)\n"
        "movl -0x3c(%ebp), %edx\n"
        "calll *0x168(%edx)\n"
        "movl %eax, -0x2c(%ebp)\n" /* surfCount */
        "testl %eax, %eax\n" /* line 157 */
        "jle .Lffc430_000fc547\n"
        "movl $0, -0x30(%ebp)\n" /* surfIndex */
        "movl -0x30(%ebp), %edx\n" /* surfIndex */
        "jmp .Lffc430_000fc4ce\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lffc430_000fc49f:\n"
        "movl %ebx, (%esp)\n" /* line 123 */
        "calll XSurfaceGetBoneOffset\n"
        "addl $1, %eax\n"
        "je .Lffc430_000fc4c2\n"
        "movl 0xc(%ebx), %eax\n" /* line 124 */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* model */
        "movl %eax, (%esp)\n"
        "calll XSurfaceOptimizeRigid\n"
        /* } scope */
        /* } scope */
        ".Lffc430_000fc4c2:\n"
        "addl $1, -0x30(%ebp)\n" /* line 157 | surfIndex */
        "movl -0x30(%ebp), %edx\n" /* surfIndex */
        "cmpl %edx, -0x2c(%ebp)\n" /* surfCount */
        "je .Lffc430_000fc547\n"
        ".Lffc430_000fc4ce:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 158 | surfaces */
        "movl (%eax, %edx, 4), %ebx\n" /* surf */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x14(%ebx), %edx\n" /* line 99 */
        "testl %edx, %edx\n"
        "jne .Lffc430_000fc49f\n"
        "movswl 4(%ebx), %eax\n" /* line 103 */
        "leal (%eax, %eax, 2), %eax\n"
        "addl %eax, %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl %eax, %edi\n" /* line 104 | indexBytes */
        "addl $0x1f, %edi\n" /* indexBytes */
        "andl $0xffffffe0, %edi\n" /* indexBytes */
        "movl %edi, 4(%esp)\n" /* line 107 | indexBytes */
        "leal 0x14(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_AllocStaticIndexBuffer\n"
        "movl %eax, %esi\n" /* indexBuffer */
        "testl %eax, %eax\n" /* line 108 */
        "je .Lffc430_000fc4c2\n"
        "movl -0x40(%ebp), %eax\n" /* line 115 */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* indexBuffer */
        "calll Com_Memcpy\n"
        "subl -0x40(%ebp), %edi\n" /* line 117 | indexBytes */
        "movl -0x40(%ebp), %edx\n"
        "leal (%esi, %edx), %eax\n" /* indexBuffer */
        "movl %edi, 8(%esp)\n" /* indexBytes */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl 0x14(%ebx), %eax\n" /* line 120 */
        "movl %eax, (%esp)\n"
        "calll R_FinishStaticIndexBuffer\n"
        "jmp .Lffc430_000fc49f\n"
        /* } scope */
        /* } scope */
        ".Lffc430_000fc547:\n"
        "addl $1, -0x38(%ebp)\n" /* line 154 | lodIndex */
        "movl -0x38(%ebp), %eax\n" /* lodIndex */
        "cmpl %eax, -0x34(%ebp)\n" /* lodCount */
        "jne .Lffc430_000fc467\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 160 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 163 */
__attribute__((naked))
void XModelUnoptimize(XModel *model)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 163 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl 0x195eee0, %ebx\n" /* line 174 | surf */
        "movl 8(%ebp), %eax\n" /* model */
        "movl %eax, (%esp)\n"
        "calll *0x174(%ebx)\n" /* surf */
        "movl %eax, -0x30(%ebp)\n" /* lodCount */
        "testl %eax, %eax\n" /* line 175 */
        "jg .Lffc560_000fc58a\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 181 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lffc560_000fc58a:\n"
        "movl $0, -0x34(%ebp)\n" /* line 175 | lodIndex */
        "movl %ebx, -0x38(%ebp)\n" /* surf */
        "movl 0x195f0e0, %edi\n"
        "movl -0x34(%ebp), %eax\n" /* lodIndex */
        ".Lffc560_000fc59d:\n"
        "leal -0x20(%ebp), %edx\n" /* line 177 | partBits */
        "movl %edx, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x1c(%ebp), %edx\n" /* surfaces */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* model */
        "movl %eax, (%esp)\n"
        "movl -0x38(%ebp), %edx\n"
        "calll *0x168(%edx)\n"
        "movl %eax, -0x2c(%ebp)\n" /* surfCount */
        "testl %eax, %eax\n" /* line 178 */
        "jle .Lffc560_000fc60a\n"
        "xorl %esi, %esi\n" /* surfIndex */
        ".Lffc560_000fc5c7:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 179 | surfaces */
        "movl (%eax, %esi, 4), %ebx\n" /* surf */
        "movl 0x14(%ebx), %eax\n" /* line 131 */
        "testl %eax, %eax\n"
        "je .Lffc560_000fc5e3\n"
        "movl %eax, (%esp)\n" /* line 133 */
        "calll R_FreeStaticIndexBuffer\n"
        "movl $0, 0x14(%ebx)\n" /* line 134 */
        ".Lffc560_000fc5e3:\n"
        "movl 0x10(%ebx), %eax\n" /* line 137 */
        "testl %eax, %eax\n"
        "je .Lffc560_000fc602\n"
        /* { scope 2 */
        ".Lffc560_000fc5ea:\n"
        "movl 0x10(%ebx), %eax\n" /* line 88 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        "movl $0, 0x10(%ebx)\n"
        "movl (%edi), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lffc560_000fc5ea\n"
        /* } scope */
        ".Lffc560_000fc602:\n"
        "addl $1, %esi\n" /* line 178 | surfIndex */
        "cmpl %esi, -0x2c(%ebp)\n" /* surfIndex, surfCount */
        "jne .Lffc560_000fc5c7\n"
        ".Lffc560_000fc60a:\n"
        "addl $1, -0x34(%ebp)\n" /* line 175 | lodIndex */
        "movl -0x34(%ebp), %eax\n" /* lodIndex */
        "cmpl %eax, -0x30(%ebp)\n" /* lodCount */
        "jne .Lffc560_000fc59d\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 181 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

