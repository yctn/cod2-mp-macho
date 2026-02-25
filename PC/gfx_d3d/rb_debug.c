/* ASM dump from: rb_debug.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/rb_debug.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/gfx_d3d/rb_backend.h"
 */

static int RB_AddDebugLine(const vec_t *end, const vec_t *color, int depthTest, int vertCount, int vertLimit, GfxPointVertex *verts);
static JCOEF RB_DrawDebugStrings(void);
static JCOEF RB_DrawPolyOutlines(void);
static JCOEF RB_DrawDebugLines(int lineCount);
static JCOEF RB_DrawPolyInteriors(void);
JCOEF RB_DrawDebug(const GfxViewParms *viewParms);

/* line 19 */
static __attribute__((naked))
int RB_AddDebugLine(const vec_t *end, const vec_t *color, int depthTest, int vertCount, int vertLimit, GfxPointVertex *verts)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 19 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, %edi\n" /* depthTest, start */
        "movl %edx, -0x1c(%ebp)\n" /* vertCount */
        "movl %ecx, -0x20(%ebp)\n"
        "movl 0xc(%ebp), %edx\n" /* vertCount */
        "movl 0x14(%ebp), %ebx\n" /* verts */
        "movzbl 8(%ebp), %eax\n" /* depthTest */
        "leal 2(%edx), %esi\n" /* line 21 */
        "cmpl 0x10(%ebp), %esi\n" /* vertLimit */
        "jg .Lf108ef0_00108f64\n"
        "movl %edx, %eax\n"
        ".Lf108ef0_00108f15:\n"
        "shll $4, %eax\n" /* line 27 */
        "leal (%eax, %ebx), %ebx\n" /* verts */
        "leal 0xc(%ebx), %eax\n" /* verts */
        "movl %eax, 4(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_ConvertColorToBytes\n"
        "leal 0x10(%ebx), %edx\n" /* line 28 | verts */
        "movl 0xc(%ebx), %eax\n" /* line 606 | verts */
        "movl %eax, 0xc(%edx)\n"
        "movl (%edi), %eax\n" /* line 199 | start */
        "movl %eax, (%ebx)\n" /* verts */
        "movl 4(%edi), %eax\n" /* line 200 | start */
        "movl %eax, 4(%ebx)\n" /* verts */
        "movl 8(%edi), %eax\n" /* line 201 | start */
        "movl %eax, 8(%ebx)\n" /* verts */
        "movl -0x1c(%ebp), %ecx\n" /* line 199 */
        "movl (%ecx), %eax\n"
        "movl %eax, 0x10(%ebx)\n" /* verts */
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "movl %esi, %eax\n" /* line 34 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf108ef0_00108f64:\n"
        "movzbl %al, %eax\n" /* line 23 */
        "movl %eax, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* verts */
        "movl $1, 4(%esp)\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_DrawLines3D\n"
        "xorl %eax, %eax\n"
        "movl $2, %esi\n"
        "jmp .Lf108ef0_00108f15\n"
    );
}

/* line 199 */
static __attribute__((naked))
JCOEF RB_DrawDebugStrings(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 199 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, %ebx\n" /* strings */
        "movl %edx, %esi\n" /* stringCount */
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 206 */
        "je .Lf108f92_00108fd7\n"
        "movl 0x195f0c8, %eax\n" /* line 209 */
        "cmpb $0, 0x4bd(%eax)\n"
        "jne .Lf108f92_001090b9\n"
        "testl %esi, %esi\n" /* line 212 | stringCount */
        "jg .Lf108f92_00108fdf\n"
        ".Lf108f92_00108fb9:\n"
        "movl 0x195f160, %eax\n" /* line 261 */
        "movl 0x5a7d0(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf108f92_00108fd2\n"
        ".Lf108f92_00108fc8:\n"
        "movl 0x5a7e0(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf108f92_00108fd7\n"
        ".Lf108f92_00108fd2:\n"
        "calll RB_EndSurface\n" /* line 262 */
        /* } scope */
        ".Lf108f92_00108fd7:\n"
        "addl $0x5c, %esp\n" /* line 220 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf108f92_00108fdf:\n"
        "xorl %edi, %edi\n" /* line 212 | stringIndex */
        "movl 0x195f0c8, %edx\n"
        "movl %edx, -0x3c(%ebp)\n"
        ".Lf108f92_00108fea:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 214 | color */
        "movl %eax, 4(%esp)\n"
        "leal 0xc(%ebx), %eax\n" /* strings */
        "movl %eax, (%esp)\n"
        "calll R_ConvertColorToBytes\n"
        "movss 0x1c(%ebx), %xmm0\n" /* line 215 | strings, scale */
        "xorps 0x2f30c0, %xmm0\n" /* scale */
        "movl -0x3c(%ebp), %edx\n" /* v */
        "movl 0x3c8(%edx), %eax\n"
        "leal 0x18(%eax), %edx\n" /* v */
        /* { scope 2 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss 0x18(%eax), %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n" /* xStep */
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss 4(%edx), %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n"
        "movaps %xmm0, %xmm1\n" /* line 274 */
        "mulss 8(%edx), %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        /* } scope */
        "leal 0x24(%eax), %edx\n" /* line 216 | v */
        /* { scope 2 */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss 0x24(%eax), %xmm1\n"
        "movss %xmm1, -0x34(%ebp)\n" /* yStep */
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss 4(%edx), %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n"
        "mulss 8(%edx), %xmm0\n" /* line 274 */
        "movss %xmm0, -0x2c(%ebp)\n"
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 217 | color */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* yStep */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x28(%ebp), %edx\n" /* xStep */
        "movl %edx, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* strings */
        "movl -0x3c(%ebp), %edx\n"
        "movl 0x36e88(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x20(%ebx), %eax\n" /* strings */
        "movl %eax, (%esp)\n"
        "calll RB_DrawTextInSpace\n"
        "addl $1, %edi\n" /* line 212 | stringIndex */
        "subl $-0x80, %ebx\n" /* strings */
        "cmpl %edi, %esi\n" /* stringIndex, stringCount */
        "jne .Lf108f92_00108fea\n"
        "movl 0x195f160, %eax\n" /* line 261 */
        "movl 0x5a7d0(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf108f92_00108fc8\n"
        "jmp .Lf108f92_00108fd2\n"
        ".Lf108f92_001090b9:\n"
        "calll RB_Set3D\n" /* line 210 */
        "testl %esi, %esi\n" /* line 212 | stringCount */
        "jle .Lf108f92_00108fb9\n"
        "jmp .Lf108f92_00108fdf\n"
    );
}

/* line 111 */
static __attribute__((naked))
JCOEF RB_DrawPolyOutlines(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 111 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl $0xaa50, (%esp)\n" /* line 123 */
        "movl 0x195eee0, %eax\n"
        "calll *0x14(%eax)\n"
        "movl %eax, -0x20(%ebp)\n" /* verts */
        "movl 0x195f188, %ebx\n" /* line 126 */
        "movl (%ebx), %edx\n"
        "movl 0x249d28(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lf1090cc_001091be\n"
        "movl $0, -0x28(%ebp)\n" /* polyIndex */
        "xorl %ecx, %ecx\n"
        "movl $0, -0x1c(%ebp)\n"
        "movl %ebx, -0x2c(%ebp)\n"
        "jmp .Lf1090cc_0010912b\n"
        ".Lf1090cc_00109112:\n"
        "addl $1, -0x28(%ebp)\n" /* polyIndex */
        "movl (%ebx), %edx\n"
        "addl $0x18, -0x1c(%ebp)\n"
        "movl -0x28(%ebp), %eax\n" /* polyIndex */
        "cmpl 0x249d28(%edx), %eax\n"
        "jge .Lf1090cc_001091b0\n"
        ".Lf1090cc_0010912b:\n"
        "movl -0x1c(%ebp), %esi\n" /* line 128 | poly */
        "addl 0x249d24(%edx), %esi\n" /* poly */
        "movl 0x10(%esi), %eax\n" /* line 129 | poly */
        "leal (%eax, %eax, 2), %eax\n"
        "movl 0x249d18(%edx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* polyVerts */
        "movl 0x14(%esi), %eax\n" /* line 131 | poly */
        "leal -1(%eax), %edx\n"
        "testl %eax, %eax\n"
        "jle .Lf1090cc_00109112\n"
        "movl -0x24(%ebp), %ebx\n" /* polyVerts */
        "xorl %edi, %edi\n" /* vertIndex */
        "jmp .Lf1090cc_0010915b\n"
        ".Lf1090cc_00109157:\n"
        "movl %edi, %edx\n" /* vertIndex */
        "movl %eax, %edi\n" /* vertIndex */
        ".Lf1090cc_0010915b:\n"
        "leal (%edx, %edx, 2), %eax\n" /* line 132 */
        "movl -0x24(%ebp), %edx\n" /* polyVerts */
        "leal (%edx, %eax, 4), %eax\n"
        "movl -0x20(%ebp), %edx\n" /* verts */
        "movl %edx, 0xc(%esp)\n"
        "movl $0xaa5, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "movl %esi, %ecx\n" /* poly */
        "movl %ebx, %edx\n"
        "calll RB_AddDebugLine\n"
        "movl %eax, %ecx\n"
        "leal 1(%edi), %eax\n" /* line 131 | vertIndex */
        "addl $0xc, %ebx\n"
        "cmpl 0x14(%esi), %eax\n" /* poly */
        "jl .Lf1090cc_00109157\n"
        "movl -0x2c(%ebp), %ebx\n"
        "addl $1, -0x28(%ebp)\n" /* line 126 | polyIndex */
        "movl (%ebx), %edx\n"
        "addl $0x18, -0x1c(%ebp)\n"
        "movl -0x28(%ebp), %eax\n" /* polyIndex */
        "cmpl 0x249d28(%edx), %eax\n"
        "jl .Lf1090cc_0010912b\n"
        ".Lf1090cc_001091b0:\n"
        "movl %ecx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %ecx, %eax\n"
        "sarl $1, %eax\n" /* line 39 */
        "jne .Lf1090cc_001091d1\n"
        "movl -0x20(%ebp), %eax\n" /* verts */
        ".Lf1090cc_001091be:\n"
        "movl %eax, (%esp)\n" /* line 136 */
        "movl 0x195eee0, %eax\n"
        "calll *0x18(%eax)\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 137 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1090cc_001091d1:\n"
        "movl $0, 0xc(%esp)\n" /* line 40 */
        "movl -0x20(%ebp), %edx\n" /* verts */
        "movl %edx, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll RB_DrawLines3D\n"
        "movl -0x20(%ebp), %eax\n" /* verts */
        "movl %eax, (%esp)\n" /* line 136 */
        "movl 0x195eee0, %eax\n"
        "calll *0x18(%eax)\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 137 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 154 */
static __attribute__((naked))
JCOEF RB_DrawDebugLines(int lineCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 154 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, %ebx\n" /* lines */
        "movl %edx, -0x28(%ebp)\n"
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 165 */
        "je .Lf109206_0010930a\n"
        "movl 0x195f0c8, %eax\n" /* line 168 */
        "cmpb $0, 0x4bd(%eax)\n"
        "jne .Lf109206_00109312\n"
        "movl $0xaa50, (%esp)\n" /* line 171 */
        "movl 0x195eee0, %eax\n"
        "calll *0x14(%eax)\n"
        "movl %eax, -0x24(%ebp)\n" /* verts */
        "movl 0x28(%ebx), %edi\n" /* line 174 | lineDepthTest, depthTest */
        "testl %edi, %edi\n" /* depthTest */
        "setne %al\n"
        "movl %eax, %edi\n" /* depthTest */
        "movl -0x28(%ebp), %esi\n" /* line 179 */
        "testl %esi, %esi\n"
        "jle .Lf109206_001092f3\n"
        ".Lf109206_00109255:\n"
        "movl %ebx, %esi\n" /* lineDepthTest */
        "movl $0, -0x1c(%ebp)\n" /* lineIndex */
        "movl $0, -0x20(%ebp)\n" /* vertCount */
        "jmp .Lf109206_001092b1\n"
        /* { scope 2 */
        ".Lf109206_00109267:\n"
        "movl %ebx, %edi\n" /* line 40 */
        "movl $0, -0x20(%ebp)\n" /* vertCount */
        /* } scope */
        ".Lf109206_00109270:\n"
        "movl %edi, %ecx\n" /* line 190 | depthTest */
        "movzbl %cl, %ebx\n" /* lineDepthTest */
        "leal 0x18(%esi), %ecx\n"
        "leal 0xc(%esi), %edx\n"
        "movl -0x24(%ebp), %eax\n" /* verts */
        "movl %eax, 0xc(%esp)\n"
        "movl $0xaa5, 8(%esp)\n"
        "movl -0x20(%ebp), %eax\n" /* vertCount */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* lineDepthTest */
        "movl %esi, %eax\n"
        "calll RB_AddDebugLine\n"
        "movl %eax, -0x20(%ebp)\n" /* vertCount */
        "addl $1, -0x1c(%ebp)\n" /* line 179 | lineIndex */
        "addl $0x2c, %esi\n"
        "movl -0x1c(%ebp), %ecx\n" /* lineIndex */
        "cmpl %ecx, -0x28(%ebp)\n"
        "je .Lf109206_00109340\n"
        ".Lf109206_001092b1:\n"
        "movl 0x28(%esi), %ebx\n" /* line 183 | lineDepthTest */
        "testl %ebx, %ebx\n" /* lineDepthTest */
        "setne %bl\n" /* lineDepthTest */
        "movl %edi, %ecx\n" /* line 184 | depthTest */
        "cmpb %cl, %bl\n" /* lineDepthTest */
        "je .Lf109206_00109270\n"
        "movl -0x20(%ebp), %eax\n" /* line 186 | vertCount */
        "shrl $0x1f, %eax\n"
        "addl -0x20(%ebp), %eax\n" /* vertCount */
        "movl %edi, %edx\n" /* depthTest */
        /* { scope 2 */
        "movl %eax, %ecx\n" /* line 39 */
        "sarl $1, %ecx\n"
        "je .Lf109206_00109267\n"
        "movzbl %dl, %eax\n" /* line 40 */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* verts */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll RB_DrawLines3D\n"
        "jmp .Lf109206_00109267\n"
        /* } scope */
        ".Lf109206_001092f3:\n"
        "movzbl %al, %ebx\n" /* line 179 | lineDepthTest */
        "xorl %edx, %edx\n"
        /* { scope 2 */
        "testl %edx, %edx\n" /* line 39 */
        "jne .Lf109206_0010934e\n"
        /* } scope */
        ".Lf109206_001092fc:\n"
        "movl -0x24(%ebp), %ecx\n" /* line 195 | verts */
        "movl %ecx, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *0x18(%eax)\n"
        /* } scope */
        ".Lf109206_0010930a:\n"
        "addl $0x2c, %esp\n" /* line 196 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf109206_00109312:\n"
        "calll RB_Set3D\n" /* line 169 */
        "movl $0xaa50, (%esp)\n" /* line 171 */
        "movl 0x195eee0, %eax\n"
        "calll *0x14(%eax)\n"
        "movl %eax, -0x24(%ebp)\n" /* verts */
        "movl 0x28(%ebx), %edi\n" /* line 174 | lineDepthTest, depthTest */
        "testl %edi, %edi\n" /* depthTest */
        "setne %al\n"
        "movl %eax, %edi\n" /* depthTest */
        "movl -0x28(%ebp), %esi\n" /* line 179 */
        "testl %esi, %esi\n"
        "jg .Lf109206_00109255\n"
        "jmp .Lf109206_001092f3\n"
        ".Lf109206_00109340:\n"
        "movl %eax, %ecx\n"
        "shrl $0x1f, %eax\n"
        "leal (%eax, %ecx), %edx\n"
        "sarl $1, %edx\n"
        /* { scope 2 */
        "testl %edx, %edx\n" /* line 39 */
        "je .Lf109206_001092fc\n"
        ".Lf109206_0010934e:\n"
        "movzbl %bl, %eax\n" /* line 40 */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* verts */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll RB_DrawLines3D\n"
        "jmp .Lf109206_001092fc\n"
    );
}

/* line 68 */
static __attribute__((naked))
JCOEF RB_DrawPolyInteriors(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 68 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        /* { scope 1: color */
        "movl $0, 8(%esp)\n" /* line 79 */
        "movl $3, 4(%esp)\n"
        "movl 0x195eebc, %eax\n"
        "movl 0x1038(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "movl 0x195f188, %eax\n" /* line 81 */
        "movl (%eax), %edx\n"
        "movl 0x249d28(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf10936e_001093b8\n"
        "calll RB_EndSurface\n" /* line 104 */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 105 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: color */
        ".Lf10936e_001093b8:\n"
        "movl $0, -0x34(%ebp)\n" /* line 81 | polyIndex */
        "movl $0, -0x2c(%ebp)\n"
        ".Lf10936e_001093c6:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 83 */
        "addl 0x249d24(%edx), %eax\n"
        "movl %eax, -0x38(%ebp)\n" /* poly */
        "movl %eax, %ecx\n" /* line 84 */
        "movl 0x10(%eax), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl 0x249d18(%edx), %edx\n"
        "leal (%edx, %eax, 4), %edi\n" /* vertIndex */
        "leal -0x1c(%ebp), %eax\n" /* line 85 | color */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll R_ConvertColorToBytes\n"
        "movl -0x38(%ebp), %edx\n" /* line 87 | poly, indexCount */
        "movl 0x14(%edx), %eax\n"
        "leal -6(%eax, %eax, 2), %edx\n" /* indexCount */
        /* { scope 2 */
        "movl 0x195f160, %esi\n" /* line 344 */
        "addl 0x5a7d4(%esi), %eax\n"
        "cmpl $0x154a, %eax\n"
        "jg .Lf10936e_0010941d\n"
        "addl 0x5a7d0(%esi), %edx\n"
        "cmpl $0x100000, %edx\n"
        "jle .Lf10936e_0010947a\n"
        ".Lf10936e_0010941d:\n"
        "movl 0x5a7cc(%esi), %ebx\n" /* line 327 */
        "calll RB_EndSurface\n" /* line 329 */
        "movl 0x5a7c4(%esi), %eax\n" /* line 331 */
        "movl %eax, 8(%esp)\n"
        "movl 0x5a7c0(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x5a7bc(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "cmpl 0x5a7cc(%esi), %ebx\n" /* line 310 */
        "je .Lf10936e_0010947a\n"
        "movl 0x5a7d0(%esi), %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lf10936e_00109640\n"
        "movl 0x5a7e0(%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf10936e_00109640\n"
        ".Lf10936e_0010946e:\n"
        "movl 0x195f160, %esi\n" /* line 313 */
        "movl %ebx, 0x5a7cc(%esi)\n"
        /* } scope */
        ".Lf10936e_0010947a:\n"
        "movl -0x38(%ebp), %ecx\n" /* line 88 | poly */
        "movl 0x14(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf10936e_001095a1\n"
        /* { scope 2 */
        "movl 0x195eec0, %eax\n" /* line 48 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl %edi, %ebx\n"
        "xorl %edi, %edi\n"
        "movl %eax, %ecx\n"
        "jmp .Lf10936e_00109530\n"
        ".Lf10936e_0010949d:\n"
        "movl %eax, %edx\n" /* line 58 */
        "shll $6, %edx\n"
        "leal (%edx, %esi), %ecx\n" /* to */
        /* { scope 3 */
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, (%ecx)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl $0x3f800000, 0xc(%ecx)\n" /* line 59 */
        "leal 0x10(%edx, %esi), %eax\n" /* line 60 | v */
        /* { scope 3 */
        "movl $0, (%eax)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0x3f800000, 8(%eax)\n" /* line 193 */
        /* } scope */
        "movl -0x3c(%ebp), %eax\n" /* line 61 | color */
        "movl %eax, 0x1c(%ecx)\n"
        "leal 0x20(%edx, %esi), %ecx\n" /* line 62 */
        "leal 8(%ecx), %eax\n" /* v */
        /* { scope 3 */
        "movl $0, 8(%ecx)\n" /* line 191 */
        "movl $0x3f800000, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 0x30(%edx, %esi), %edx\n" /* line 63 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movl $0x3f800000, 4(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "movl $0, (%ecx)\n" /* line 30 */
        "movl $0, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $1, %edi\n" /* line 88 | vertIndex */
        "addl $0xc, %ebx\n"
        "movl -0x38(%ebp), %edx\n" /* poly */
        "cmpl 0x14(%edx), %edi\n" /* vertIndex */
        "jge .Lf10936e_0010959f\n"
        ".Lf10936e_0010952d:\n"
        "movl -0x30(%ebp), %ecx\n"
        ".Lf10936e_00109530:\n"
        "movl %edi, %eax\n" /* line 90 | vertIndex */
        "addl 0x5a7d4(%esi), %eax\n"
        "movl -0x1c(%ebp), %edx\n" /* line 91 | color */
        "movl %edx, -0x3c(%ebp)\n" /* color */
        /* { scope 2 */
        "cmpl $2, 8(%ecx)\n" /* line 48 */
        "jne .Lf10936e_0010949d\n"
        "leal (%eax, %eax, 8), %edx\n" /* line 50 */
        "shll $2, %edx\n"
        "leal (%edx, %esi), %ecx\n" /* to */
        /* { scope 3 */
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, (%ecx)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0xc(%ecx), %eax\n" /* line 51 | v */
        /* { scope 3 */
        "movl $0, 0xc(%ecx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0x3f800000, 8(%eax)\n" /* line 193 */
        /* } scope */
        "movl -0x3c(%ebp), %eax\n" /* line 52 | color */
        "movl %eax, 0x18(%ecx)\n"
        "leal 0x10(%edx, %esi), %edx\n" /* line 53 */
        "movl $0, 0xc(%edx)\n" /* line 30 */
        "movl $0, 0x10(%edx)\n" /* line 31 */
        /* } scope */
        "addl $1, %edi\n" /* line 88 | vertIndex */
        "addl $0xc, %ebx\n"
        "movl -0x38(%ebp), %edx\n" /* poly */
        "cmpl 0x14(%edx), %edi\n" /* vertIndex */
        "jl .Lf10936e_0010952d\n"
        ".Lf10936e_0010959f:\n"
        "movl %edx, %ecx\n"
        ".Lf10936e_001095a1:\n"
        "movl 0x14(%ecx), %eax\n" /* line 94 */
        "cmpl $2, %eax\n"
        "jle .Lf10936e_0010960f\n"
        "movl $2, %edi\n" /* vertIndex */
        ".Lf10936e_001095ae:\n"
        "movl 0x5a7d0(%esi), %ecx\n" /* line 96 */
        "movl 0x5a7b0(%esi), %edx\n"
        "movl 0x5a7d4(%esi), %eax\n"
        "movw %ax, (%edx, %ecx, 2)\n"
        "movl %edi, %edx\n" /* vertIndex */
        "movl 0x5a7d0(%esi), %ebx\n" /* line 97 */
        "movl 0x5a7b0(%esi), %ecx\n"
        "movl %edi, %eax\n" /* vertIndex */
        "addw 0x5a7d4(%esi), %ax\n"
        "movw %ax, 2(%ecx, %ebx, 2)\n"
        "movl 0x5a7d0(%esi), %ecx\n" /* line 98 */
        "movl 0x5a7b0(%esi), %eax\n"
        "addw 0x5a7d4(%esi), %dx\n"
        "subl $1, %edx\n"
        "movw %dx, 4(%eax, %ecx, 2)\n"
        "addl $3, 0x5a7d0(%esi)\n" /* line 99 */
        "addl $1, %edi\n" /* line 94 | vertIndex */
        "movl -0x38(%ebp), %edx\n" /* poly */
        "movl 0x14(%edx), %eax\n"
        "cmpl %eax, %edi\n" /* vertIndex */
        "jl .Lf10936e_001095ae\n"
        ".Lf10936e_0010960f:\n"
        "addl %eax, 0x5a7d4(%esi)\n" /* line 102 */
        "addl $1, -0x34(%ebp)\n" /* line 81 | polyIndex */
        "movl 0x195f188, %eax\n"
        "movl (%eax), %edx\n"
        "addl $0x18, -0x2c(%ebp)\n"
        "movl -0x34(%ebp), %ecx\n" /* polyIndex */
        "cmpl 0x249d28(%edx), %ecx\n"
        "jl .Lf10936e_001093c6\n"
        "calll RB_EndSurface\n" /* line 104 */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 105 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: color */
        /* { scope 2 */
        ".Lf10936e_00109640:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lf10936e_0010946e\n"
    );
}

/* line 252 */
__attribute__((naked))
JCOEF RB_DrawDebug(const GfxViewParms *viewParms)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 252 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1: dir */
        "movl 0x195f188, %edi\n" /* line 230 */
        "movl (%edi), %eax\n"
        "movl 0x249d64(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf10964c_001097da\n"
        "movl $0, -0x30(%ebp)\n" /* plumeIndex */
        "xorl %ebx, %ebx\n"
        "movl 8(%ebp), %edx\n" /* viewParms */
        "addl $0x18, %edx\n"
        "movl %edx, -0x2c(%ebp)\n" /* dir */
        "movl %edi, -0x3c(%ebp)\n"
        "jmp .Lf10964c_00109773\n"
        ".Lf10964c_00109685:\n"
        "cvtsi2ssl %ecx, %xmm2\n" /* line 238 */
        ".Lf10964c_00109689:\n"
        "cvtsi2sdl %ecx, %xmm0\n" /* line 242 */
        "mulsd 0x307d08, %xmm0\n" /* 0.012566370614359173 */
        "cvtsi2sdl -0x30(%ebp), %xmm1\n" /* plumeIndex */
        "addsd %xmm1, %xmm0\n"
        "movsd %xmm0, (%esp)\n"
        "movss %xmm2, -0x58(%ebp)\n"
        "calll sin\n"
        "fstpl -0x38(%ebp)\n"
        "cvtsd2ss -0x38(%ebp), %xmm1\n"
        "mulss 0x2ed608, %xmm1\n" /* 4.0f */
        "movl (%edi), %edx\n" /* line 243 */
        "movl %ebx, %eax\n" /* start */
        "addl 0x249d60(%edx), %eax\n" /* start */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "movl 8(%ebp), %ecx\n" /* viewParms */
        "mulss 0x18(%ecx), %xmm0\n"
        "addss (%eax), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* org */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "movl -0x2c(%ebp), %ecx\n" /* dir */
        "mulss 4(%ecx), %xmm0\n"
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "mulss 8(%ecx), %xmm1\n" /* line 290 */
        "addss 8(%eax), %xmm1\n"
        /* } scope */
        "movss -0x58(%ebp), %xmm2\n" /* line 244 */
        "mulss 0x2ed8a8, %xmm2\n" /* 0.06400000303983688f */
        "addss %xmm1, %xmm2\n"
        "movss %xmm2, -0x1c(%ebp)\n"
        "movl 0x249d60(%edx), %eax\n" /* line 247 */
        "movl 0x1c(%ebx, %eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x21785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl (%edi), %edx\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0x3f000000, 0xc(%esp)\n"
        "movl %ebx, %eax\n"
        "addl 0x249d60(%edx), %eax\n"
        "addl $0xc, %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* org */
        "movl %eax, 4(%esp)\n"
        "addl $0x249d18, %edx\n" /* "x;
DP4 oPos.y, v0, c23[1];
MAX r0.w, r0.w, c0.y;
DP4 oPos.z," */
        "movl %edx, (%esp)\n"
        "calll R_AddDebugString\n"
        "movl -0x3c(%ebp), %edi\n"
        ".Lf10964c_0010975f:\n"
        "addl $1, -0x30(%ebp)\n" /* line 230 | plumeIndex */
        "movl (%edi), %eax\n"
        "addl $0x28, %ebx\n"
        "movl -0x30(%ebp), %edx\n" /* plumeIndex */
        "cmpl 0x249d64(%eax), %edx\n"
        "jge .Lf10964c_001097da\n"
        ".Lf10964c_00109773:\n"
        "movl %ebx, %edx\n" /* line 232 */
        "addl 0x249d60(%eax), %edx\n"
        "movl 0x195f0c8, %eax\n"
        "movl 0x3b8(%eax), %eax\n"
        "movl %eax, %ecx\n" /* line 233 */
        "subl 0x20(%edx), %ecx\n"
        "js .Lf10964c_0010975f\n"
        "cmpl 0x24(%edx), %ecx\n"
        "jg .Lf10964c_0010975f\n"
        "movl $0x3f800000, 0x18(%edx)\n" /* line 237 */
        "movl (%edi), %eax\n" /* line 238 */
        "movl %ebx, %esi\n"
        "addl 0x249d60(%eax), %esi\n"
        "movl 0x24(%esi), %edx\n"
        "leal (%ecx, %ecx), %eax\n"
        "cmpl %edx, %eax\n"
        "jle .Lf10964c_00109685\n"
        "cvtsi2ssl %ecx, %xmm2\n" /* line 239 */
        "movaps %xmm2, %xmm0\n"
        "mulss 0x2ed628, %xmm0\n" /* -2.0f */
        "cvtsi2ssl %edx, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "addss 0x2ed62c, %xmm0\n" /* 2.0f */
        "movss %xmm0, 0x18(%esi)\n"
        "jmp .Lf10964c_00109689\n"
        /* } scope */
        ".Lf10964c_001097da:\n"
        "movl 0x249d28(%eax), %eax\n" /* line 142 */
        "testl %eax, %eax\n"
        "je .Lf10964c_0010980e\n"
        "movl 0x195f0c8, %eax\n" /* line 145 */
        "cmpb $0, 0x4bd(%eax)\n"
        "jne .Lf10964c_0010986e\n"
        ".Lf10964c_001097f2:\n"
        "calll RB_DrawPolyInteriors\n" /* line 148 */
        "calll RB_DrawPolyOutlines\n" /* line 149 */
        "movl 0x195f188, %edi\n" /* line 150 */
        "movl (%edi), %eax\n"
        "movl $0, 0x249d28(%eax)\n"
        ".Lf10964c_0010980e:\n"
        "movl (%edi), %eax\n" /* line 261 */
        "movl 0x249d4c(%eax), %edx\n"
        "movl 0x249d48(%eax), %eax\n"
        "calll RB_DrawDebugLines\n"
        "movl (%edi), %eax\n" /* line 262 */
        "movl 0x249d58(%eax), %edx\n"
        "movl 0x249d54(%eax), %eax\n"
        "calll RB_DrawDebugLines\n"
        "movl (%edi), %eax\n" /* line 263 */
        "movl $0, 0x249d4c(%eax)\n"
        "movl (%edi), %eax\n" /* line 266 */
        "movl 0x249d34(%eax), %edx\n"
        "movl 0x249d30(%eax), %eax\n"
        "calll RB_DrawDebugStrings\n"
        "movl (%edi), %eax\n" /* line 267 */
        "movl 0x249d40(%eax), %edx\n"
        "movl 0x249d3c(%eax), %eax\n"
        "calll RB_DrawDebugStrings\n"
        "addl $0x6c, %esp\n" /* line 268 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf10964c_0010986e:\n"
        "calll RB_Set3D\n" /* line 146 */
        "jmp .Lf10964c_001097f2\n"
    );
}

