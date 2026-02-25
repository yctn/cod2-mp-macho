/* ASM dump from: cm_mesh.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/cm_mesh.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

static Bool CM_CullBox(void);
static short int CM_PositionTestCapsuleInTriangle(trace_t *trace);
static short int CM_TraceCapsuleThroughTriangle(void);
static short int CM_TraceThroughAabbTree_r(const traceWork_t *tw, trace_t *trace);
short int CM_TraceThroughAabbTree(const traceWork_t *tw, CollisionAabbTree *aabbTree, trace_t *trace);
short int CM_SightTraceThroughAabbTree(const traceWork_t *tw, CollisionAabbTree *aabbTree, trace_t *trace);
static short int CM_PositionTestInAabbTree_r(const traceWork_t *tw, CollisionAabbTree *aabbTree, trace_t *trace);
short int CM_MeshTestInLeaf(const traceWork_t *tw, cLeaf_t *leaf, trace_t *trace);

/* line 9 */
static __attribute__((naked))
Bool CM_CullBox(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 9 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl %eax, %ebx\n" /* tw */
        "leal 0x38(%eax), %eax\n" /* line 14 | a */
        /* { scope 1 */
        "movss 0x38(%ebx), %xmm0\n" /* line 248 | tw */
        "subss (%edx), %xmm0\n" /* origin */
        "movss %xmm0, -8(%ebp)\n"
        "movss 4(%eax), %xmm1\n" /* line 249 */
        "subss 4(%edx), %xmm1\n" /* origin */
        "movss %xmm1, -0xc(%ebp)\n"
        "movss 8(%eax), %xmm5\n" /* line 250 */
        "subss 8(%edx), %xmm5\n" /* origin */
        /* } scope */
        "leal 0x5c(%ebx), %eax\n" /* line 15 | tw, b */
        /* { scope 1 */
        "movss (%ecx), %xmm6\n" /* line 240 | halfSize */
        "addss 0x5c(%ebx), %xmm6\n" /* tw */
        "movss 4(%ecx), %xmm7\n" /* line 241 | halfSize */
        "addss 4(%eax), %xmm7\n"
        "movss 8(%ecx), %xmm4\n" /* line 242 | halfSize */
        "addss 8(%eax), %xmm4\n"
        /* } scope */
        "movss 0x50(%ebx), %xmm0\n" /* line 17 | tw */
        "movss %xmm0, -0x20(%ebp)\n"
        "movss 0x2f05e0, %xmm3\n"
        "movss -8(%ebp), %xmm1\n"
        "andps %xmm3, %xmm1\n"
        "addss %xmm6, %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf66c18_00066dac\n"
        "movss 0x54(%ebx), %xmm1\n" /* line 19 | tw */
        "movss %xmm1, -0x1c(%ebp)\n"
        "movss -0xc(%ebp), %xmm1\n"
        "andps %xmm3, %xmm1\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "addss %xmm7, %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf66c18_00066dac\n"
        "movss 0x58(%ebx), %xmm0\n" /* line 21 | tw */
        "movss %xmm0, -0x18(%ebp)\n"
        "movaps %xmm5, %xmm1\n"
        "andps %xmm3, %xmm1\n"
        "addss %xmm4, %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf66c18_00066dac\n"
        "movl 0x88(%ebx), %eax\n" /* line 24 | tw */
        "testl %eax, %eax\n"
        "jne .Lf66c18_00066db7\n"
        "movss 0x48(%ebx), %xmm1\n" /* line 27 | tw */
        "movss %xmm1, -0x14(%ebp)\n"
        "movss 0x4c(%ebx), %xmm0\n" /* tw */
        "movss %xmm0, -0x10(%ebp)\n"
        "movaps %xmm1, %xmm2\n"
        "mulss %xmm5, %xmm2\n"
        "movss -0xc(%ebp), %xmm0\n"
        "mulss -0x10(%ebp), %xmm0\n"
        "subss %xmm0, %xmm2\n"
        "andps %xmm3, %xmm2\n"
        "movss -0x18(%ebp), %xmm0\n"
        "mulss %xmm7, %xmm0\n"
        "movss -0x1c(%ebp), %xmm1\n"
        "mulss %xmm4, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf66c18_00066dac\n"
        "movss 0x44(%ebx), %xmm0\n" /* line 29 | tw */
        "movss -8(%ebp), %xmm1\n"
        "mulss -0x10(%ebp), %xmm1\n"
        "mulss %xmm0, %xmm5\n"
        "subss %xmm5, %xmm1\n"
        "movss %xmm1, -0x10(%ebp)\n"
        "andl $0x7fffffff, -0x10(%ebp)\n"
        "mulss -0x20(%ebp), %xmm4\n"
        "movss -0x18(%ebp), %xmm1\n"
        "mulss %xmm6, %xmm1\n"
        "addss %xmm1, %xmm4\n"
        "movss -0x10(%ebp), %xmm1\n"
        "ucomiss %xmm4, %xmm1\n"
        "ja .Lf66c18_00066dac\n"
        "mulss -0xc(%ebp), %xmm0\n" /* line 31 */
        "movss %xmm0, -0xc(%ebp)\n"
        "movss -8(%ebp), %xmm0\n"
        "mulss -0x14(%ebp), %xmm0\n"
        "movss -0xc(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0xc(%ebp)\n"
        "andl $0x7fffffff, -0xc(%ebp)\n"
        "mulss -0x1c(%ebp), %xmm6\n"
        "mulss -0x20(%ebp), %xmm7\n"
        "addss %xmm7, %xmm6\n"
        "movss -0xc(%ebp), %xmm0\n"
        "ucomiss %xmm6, %xmm0\n"
        "jbe .Lf66c18_00066db7\n"
        ".Lf66c18_00066dac:\n"
        "movl $1, %eax\n"
        "addl $0x1c, %esp\n" /* line 35 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf66c18_00066db7:\n"
        "xorl %eax, %eax\n" /* line 31 */
        "addl $0x1c, %esp\n" /* line 35 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 92 */
static __attribute__((naked))
short int CM_PositionTestCapsuleInTriangle(trace_t *trace)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 92 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x28, %esp\n"
        "movl %edx, %ebx\n" /* triangle */
        "movl %ecx, -0x34(%ebp)\n"
        /* { scope 1 */
        "movss 0x90(%eax), %xmm2\n" /* line 118 */
        "movss 8(%edx), %xmm6\n" /* line 119 */
        "ucomiss 0x2ed5e8, %xmm6\n" /* 0.0f */
        "jb .Lf66dc0_000671b6\n"
        ".Lf66dc0_00066de8:\n"
        "movss (%eax), %xmm0\n" /* line 199 */
        "movss %xmm0, -0x10(%ebp)\n"
        "movss 4(%eax), %xmm1\n" /* line 200 */
        "movss %xmm1, -0x14(%ebp)\n"
        "movss 8(%eax), %xmm7\n" /* line 201 */
        "subss %xmm2, %xmm7\n" /* line 123 */
        "movss 0x8c(%eax), %xmm0\n" /* line 125 */
        "movss %xmm0, -0x24(%ebp)\n" /* cullEndRadius */
        "movss (%ebx), %xmm3\n" /* line 304 | edge */
        "movss 4(%ebx), %xmm4\n" /* edge */
        "movss -0x10(%ebp), %xmm1\n" /* line 128 */
        "mulss %xmm3, %xmm1\n"
        "movss -0x14(%ebp), %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movaps %xmm7, %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "subss 0xc(%ebx), %xmm1\n" /* edge */
        "ucomiss -0x24(%ebp), %xmm1\n" /* line 129 | cullEndRadius */
        "jae .Lf66dc0_00066f71\n"
        "movss -0x24(%ebp), %xmm0\n" /* line 132 | cullEndRadius */
        "xorps 0x2f05f0, %xmm0\n"
        "ucomiss %xmm1, %xmm0\n" /* line 134 */
        "jb .Lf66dc0_00066f79\n"
        "addss %xmm2, %xmm2\n" /* line 136 */
        "movss %xmm2, -0x1c(%ebp)\n" /* height */
        "mulss %xmm6, %xmm2\n" /* line 138 */
        "addss %xmm1, %xmm2\n"
        "movss %xmm2, -0x20(%ebp)\n" /* distAlt */
        "ucomiss %xmm2, %xmm0\n" /* line 139 */
        "jae .Lf66dc0_00066f71\n"
        "movaps %xmm0, %xmm5\n" /* line 145 */
        "subss %xmm1, %xmm5\n"
        "divss %xmm6, %xmm5\n"
        "leal 0x10(%ebx), %eax\n" /* line 147 | edge */
        "movss -0x10(%ebp), %xmm4\n"
        "mulss 0x10(%ebx), %xmm4\n" /* edge */
        "movss -0x14(%ebp), %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "movaps %xmm7, %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "subss 0x1c(%ebx), %xmm4\n" /* edge */
        "leal 0x20(%ebx), %eax\n" /* line 148 | edge */
        "movss -0x10(%ebp), %xmm3\n"
        "mulss 0x20(%ebx), %xmm3\n" /* edge */
        "movss -0x14(%ebp), %xmm2\n"
        "mulss 4(%eax), %xmm2\n"
        "addss %xmm2, %xmm3\n"
        "mulss 8(%eax), %xmm7\n"
        "addss %xmm7, %xmm3\n"
        "subss 0x2c(%ebx), %xmm3\n" /* edge */
        "movss 0x18(%ebx), %xmm7\n" /* line 152 | edge */
        "movaps %xmm5, %xmm2\n"
        "mulss %xmm7, %xmm2\n"
        "addss %xmm4, %xmm2\n"
        "ucomiss 0x2ed5e8, %xmm2\n" /* line 153 | 0.0f */
        "jb .Lf66dc0_00066f1d\n"
        "movaps %xmm5, %xmm0\n" /* line 155 */
        "mulss 0x28(%ebx), %xmm0\n" /* edge */
        "addss %xmm3, %xmm0\n"
        "ucomiss 0x2ed5e8, %xmm0\n" /* line 156 | 0.0f */
        "jb .Lf66dc0_00066f1d\n"
        "addss %xmm2, %xmm0\n" /* line 158 */
        "ucomiss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jbe .Lf66dc0_000671f2\n"
        ".Lf66dc0_00066f1d:\n"
        "movss -0x24(%ebp), %xmm2\n" /* line 169 | cullEndRadius */
        "ucomiss -0x20(%ebp), %xmm2\n" /* distAlt */
        "jbe .Lf66dc0_000671df\n"
        "movss -0x1c(%ebp), %xmm1\n" /* height */
        ".Lf66dc0_00066f31:\n"
        "movaps %xmm1, %xmm0\n" /* line 181 */
        "mulss %xmm7, %xmm0\n"
        "addss %xmm4, %xmm0\n"
        "pxor %xmm2, %xmm2\n" /* line 182 */
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf66dc0_00066f71\n"
        "mulss 0x28(%ebx), %xmm1\n" /* line 185 | edge */
        "addss %xmm3, %xmm1\n"
        "ucomiss %xmm1, %xmm2\n" /* line 186 */
        "ja .Lf66dc0_00066f71\n"
        "addss %xmm1, %xmm0\n" /* line 189 */
        "ucomiss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "ja .Lf66dc0_00066f71\n"
        ".Lf66dc0_00066f60:\n"
        "movl -0x34(%ebp), %eax\n" /* line 255 */
        "movb $1, 0x23(%eax)\n"
        "movb $1, 0x22(%eax)\n" /* line 256 */
        "movl $0, (%eax)\n" /* line 257 */
        /* } scope */
        ".Lf66dc0_00066f71:\n"
        "addl $0x28, %esp\n" /* line 280 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf66dc0_00066f79:\n"
        "xorps 0x2f05f0, %xmm1\n" /* line 213 | scale */
        /* { scope 2 */
        "mulss %xmm1, %xmm3\n" /* line 288 */
        "addss -0x10(%ebp), %xmm3\n"
        "mulss %xmm1, %xmm4\n" /* line 289 */
        "addss -0x14(%ebp), %xmm4\n"
        "mulss %xmm6, %xmm1\n" /* line 290 */
        "addss %xmm7, %xmm1\n"
        /* } scope */
        "leal 0x10(%ebx), %eax\n" /* line 214 | edge */
        "movaps %xmm3, %xmm2\n"
        "mulss 0x10(%ebx), %xmm2\n" /* edge */
        "movaps %xmm4, %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movaps %xmm1, %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "subss 0x1c(%ebx), %xmm2\n" /* edge */
        "leal 0x20(%ebx), %eax\n" /* line 215 | edge */
        "mulss 0x20(%ebx), %xmm3\n" /* edge */
        "mulss 4(%eax), %xmm4\n"
        "addss %xmm4, %xmm3\n"
        "mulss 8(%eax), %xmm1\n"
        "addss %xmm1, %xmm3\n"
        "subss 0x2c(%ebx), %xmm3\n" /* edge */
        "movaps %xmm2, %xmm0\n" /* line 218 */
        "addss %xmm3, %xmm0\n"
        "xorl %eax, %eax\n"
        "ucomiss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "seta %al\n"
        "pxor %xmm0, %xmm0\n" /* line 219 */
        "xorl %edx, %edx\n"
        "ucomiss %xmm2, %xmm0\n"
        "seta %dl\n"
        "addl %edx, %edx\n"
        "orl %eax, %edx\n"
        "xorl %eax, %eax\n" /* line 220 */
        "ucomiss %xmm3, %xmm0\n"
        "seta %al\n"
        "shll $2, %eax\n"
        "movl %eax, %edi\n" /* line 223 */
        "orl %edx, %edi\n"
        "je .Lf66dc0_000671c8\n"
        "movl 0x195eda4, %eax\n" /* line 268 */
        "movl 0x48(%eax), %ecx\n"
        "movl %ecx, -0x28(%ebp)\n"
        "movss -0x24(%ebp), %xmm0\n" /* line 270 | cullEndRadius */
        "mulss %xmm0, %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movl 0x50(%eax), %eax\n" /* line 244 */
        "movl %eax, -0x30(%ebp)\n"
        "movl %ebx, %edx\n" /* edge */
        "xorl %esi, %esi\n" /* sideIndex */
        "movl %edi, %eax\n" /* line 236 */
        "movl %esi, %ecx\n" /* sideIndex */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf66dc0_00067157\n"
        ".Lf66dc0_0006704a:\n"
        "movl 0x3c(%edx), %eax\n" /* line 241 */
        "testl %eax, %eax\n" /* line 242 */
        "js .Lf66dc0_0006713a\n"
        "leal (%eax, %eax, 2), %eax\n" /* line 244 */
        "shll $4, %eax\n"
        "movl -0x30(%ebp), %ebx\n" /* edge */
        "addl %eax, %ebx\n" /* edge */
        "movss -0x10(%ebp), %xmm3\n" /* line 248 */
        "subss (%ebx), %xmm3\n" /* edge */
        "movss -0x14(%ebp), %xmm4\n" /* line 249 */
        "subss 4(%ebx), %xmm4\n" /* edge */
        "movaps %xmm7, %xmm5\n" /* line 250 */
        "subss 8(%ebx), %xmm5\n" /* edge */
        "leal 0x24(%ebx), %eax\n" /* line 246 | edge */
        "movss 4(%eax), %xmm6\n" /* line 304 */
        "movss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x18(%ebp)\n"
        "movaps %xmm3, %xmm2\n"
        "mulss 0x24(%ebx), %xmm2\n" /* edge */
        "movaps %xmm4, %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movss -0x18(%ebp), %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movaps %xmm2, %xmm0\n" /* line 247 */
        "subss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "andps 0x2f0600, %xmm0\n"
        "movss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf66dc0_0006713a\n"
        "movss 0x24(%ebx), %xmm0\n" /* line 316 | edge */
        "mulss %xmm0, %xmm0\n" /* line 252 | scale */
        "movaps %xmm6, %xmm1\n"
        "mulss %xmm6, %xmm1\n"
        "addss %xmm1, %xmm0\n" /* scale */
        "movss -0x18(%ebp), %xmm1\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n" /* scale */
        "divss %xmm0, %xmm2\n" /* scale */
        "movaps %xmm2, %xmm0\n" /* scale */
        "xorps 0x2f05f0, %xmm0\n" /* scale */
        /* { scope 2 */
        "movaps %xmm0, %xmm1\n" /* line 288 */
        "mulss 0x24(%ebx), %xmm1\n" /* edge */
        "addss %xmm1, %xmm3\n"
        "mulss %xmm0, %xmm6\n" /* line 289 */
        "addss %xmm6, %xmm4\n"
        "mulss -0x18(%ebp), %xmm0\n" /* line 290 */
        "addss %xmm0, %xmm5\n"
        /* } scope */
        "mulss %xmm3, %xmm3\n" /* line 253 */
        "mulss %xmm4, %xmm4\n"
        "addss %xmm4, %xmm3\n"
        "mulss %xmm5, %xmm5\n"
        "addss %xmm5, %xmm3\n"
        "movss -0x2c(%ebp), %xmm2\n"
        "ucomiss %xmm3, %xmm2\n"
        "ja .Lf66dc0_00066f60\n"
        ".Lf66dc0_0006713a:\n"
        "addl $1, %esi\n" /* line 234 | sideIndex */
        "addl $4, %edx\n"
        "cmpl $3, %esi\n" /* sideIndex */
        "je .Lf66dc0_00066f71\n"
        "movl %edi, %eax\n" /* line 236 */
        "movl %esi, %ecx\n" /* sideIndex */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf66dc0_0006704a\n"
        ".Lf66dc0_00067157:\n"
        "movl 0x30(%edx), %eax\n" /* line 265 */
        "testl %eax, %eax\n" /* line 266 */
        "js .Lf66dc0_0006713a\n"
        "leal (%eax, %eax, 2), %eax\n" /* line 267 */
        "movl -0x28(%ebp), %ecx\n"
        "leal (%ecx, %eax, 4), %eax\n"
        /* { scope 2 */
        "movss -0x10(%ebp), %xmm0\n" /* line 248 */
        "subss (%eax), %xmm0\n"
        "movss -0x14(%ebp), %xmm1\n" /* line 249 */
        "subss 4(%eax), %xmm1\n"
        "movaps %xmm7, %xmm2\n" /* line 250 */
        "subss 8(%eax), %xmm2\n"
        /* } scope */
        "mulss %xmm0, %xmm0\n" /* line 270 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss -0x2c(%ebp), %xmm1\n"
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf66dc0_0006713a\n"
        "movl -0x34(%ebp), %edx\n" /* line 272 */
        "movb $1, 0x23(%edx)\n"
        "movb $1, 0x22(%edx)\n" /* line 273 */
        "movl $0, (%edx)\n" /* line 274 */
        "jmp .Lf66dc0_00066f71\n"
        ".Lf66dc0_000671b6:\n"
        "jp .Lf66dc0_00066de8\n" /* line 119 */
        "xorps 0x2f05f0, %xmm2\n" /* line 120 */
        "jmp .Lf66dc0_00066de8\n"
        ".Lf66dc0_000671c8:\n"
        "movl -0x34(%ebp), %eax\n" /* line 226 */
        "movb $1, 0x23(%eax)\n"
        "movb $1, 0x22(%eax)\n" /* line 227 */
        "movss %xmm0, (%eax)\n" /* line 228 */
        /* } scope */
        "addl $0x28, %esp\n" /* line 280 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf66dc0_000671df:\n"
        "movaps %xmm2, %xmm0\n"
        /* { scope 1 */
        "subss %xmm1, %xmm0\n" /* line 176 */
        "movaps %xmm0, %xmm1\n"
        "divss %xmm6, %xmm1\n"
        "jmp .Lf66dc0_00066f31\n"
        ".Lf66dc0_000671f2:\n"
        "jp .Lf66dc0_00066f1d\n" /* line 158 */
        "movl -0x34(%ebp), %eax\n" /* line 160 */
        "movb $1, 0x23(%eax)\n"
        "movb $1, 0x22(%eax)\n" /* line 161 */
        "pxor %xmm0, %xmm0\n" /* line 162 */
        "movss %xmm0, (%eax)\n"
        "jmp .Lf66dc0_00066f71\n"
    );
}

/* line 295 */
static __attribute__((naked))
short int CM_TraceCapsuleThroughTriangle(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 295 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl %eax, %esi\n" /* tw */
        "movl %edx, %ebx\n" /* triangle */
        "movaps %xmm0, %xmm4\n" /* offsetZ */
        "movl %ecx, %edi\n" /* trace */
        /* { scope 1: result */
        "leal 0xc(%eax), %eax\n" /* line 329 | from */
        /* { scope 2 */
        "movss 8(%eax), %xmm7\n" /* line 201 */
        /* } scope */
        "subss %xmm0, %xmm7\n" /* line 330 */
        "movss 0x2ed610, %xmm0\n" /* line 332 | 0.125f */
        "addss 0x8c(%esi), %xmm0\n" /* tw */
        "movss %xmm0, -0x6c(%ebp)\n" /* cullEndRadius */
        "movss (%edx), %xmm1\n" /* line 304 | s */
        "movss %xmm1, -0x5c(%ebp)\n" /* s */
        "leal 4(%edx), %edx\n"
        "movl %edx, -0x58(%ebp)\n"
        "movss 4(%ebx), %xmm2\n" /* triangle */
        "leal 8(%ebx), %ecx\n" /* triangle */
        "movl %ecx, -0x54(%ebp)\n"
        "movss 8(%ebx), %xmm6\n" /* triangle */
        "movss 0xc(%ebx), %xmm5\n" /* line 336 | triangle */
        "mulss 0xc(%esi), %xmm1\n" /* tw */
        "movaps %xmm2, %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movaps %xmm7, %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "subss %xmm5, %xmm1\n"
        "ucomiss -0x6c(%ebp), %xmm1\n" /* line 337 | cullEndRadius */
        "jae .Lf67210_00067415\n"
        "movss (%esi), %xmm0\n" /* line 199 */
        "movss %xmm0, -0x3c(%ebp)\n"
        "movss 4(%esi), %xmm3\n" /* line 200 */
        "movss %xmm3, -0x40(%ebp)\n"
        "movss 8(%esi), %xmm0\n" /* line 201 */
        "subss %xmm4, %xmm0\n" /* line 341 */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movss -0x5c(%ebp), %xmm3\n" /* line 343 */
        "mulss -0x3c(%ebp), %xmm3\n"
        "mulss -0x40(%ebp), %xmm2\n"
        "addss %xmm2, %xmm3\n"
        "mulss %xmm6, %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "subss %xmm5, %xmm3\n"
        "movaps %xmm3, %xmm2\n" /* line 344 */
        "subss %xmm1, %xmm2\n"
        "movaps %xmm2, %xmm1\n"
        "ucomiss 0x2ed5f0, %xmm2\n" /* line 345 | 9.999999747378752e-05f */
        "jp .Lf67210_000672ed\n"
        "jbe .Lf67210_00067415\n"
        ".Lf67210_000672ed:\n"
        "movss -0x6c(%ebp), %xmm0\n" /* line 348 | cullEndRadius */
        "xorps 0x2f0610, %xmm0\n"
        "ucomiss %xmm3, %xmm0\n" /* line 350 */
        "jb .Lf67210_00067420\n"
        "addss %xmm4, %xmm4\n" /* line 352 */
        "movss %xmm4, -0x60(%ebp)\n" /* height */
        "movaps %xmm4, %xmm7\n" /* line 354 */
        "mulss %xmm6, %xmm7\n"
        "addss %xmm3, %xmm7\n"
        "ucomiss %xmm7, %xmm0\n" /* line 355 */
        "jae .Lf67210_00067415\n"
        "movaps %xmm0, %xmm5\n" /* line 360 */
        "subss %xmm3, %xmm5\n"
        "divss %xmm6, %xmm5\n"
        "leal 0x10(%ebx), %eax\n" /* line 362 | triangle */
        "movss -0x3c(%ebp), %xmm4\n"
        "mulss 0x10(%ebx), %xmm4\n" /* triangle */
        "movss -0x40(%ebp), %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "subss 0x1c(%ebx), %xmm4\n" /* triangle */
        "leal 0x20(%ebx), %eax\n" /* line 363 | triangle */
        "movss -0x3c(%ebp), %xmm2\n"
        "mulss 0x20(%ebx), %xmm2\n" /* triangle */
        "movss -0x40(%ebp), %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movss -0x1c(%ebp), %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "subss 0x2c(%ebx), %xmm2\n" /* triangle */
        "movss 0x18(%ebx), %xmm0\n" /* line 367 | triangle */
        "movss %xmm0, -0x78(%ebp)\n"
        "movaps %xmm0, %xmm1\n"
        "mulss %xmm5, %xmm1\n"
        "addss %xmm4, %xmm1\n"
        "pxor %xmm0, %xmm0\n" /* line 368 */
        "movss %xmm0, -0x7c(%ebp)\n"
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf67210_000673cc\n"
        "movaps %xmm5, %xmm0\n" /* line 370 */
        "mulss 0x28(%ebx), %xmm0\n" /* triangle */
        "addss %xmm2, %xmm0\n"
        "ucomiss -0x7c(%ebp), %xmm0\n" /* line 371 */
        "jb .Lf67210_000673cc\n"
        "addss %xmm1, %xmm0\n" /* line 373 */
        "ucomiss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jbe .Lf67210_000678b5\n"
        ".Lf67210_000673cc:\n"
        "movss -0x6c(%ebp), %xmm0\n" /* line 384 | cullEndRadius */
        "ucomiss %xmm7, %xmm0\n"
        "jbe .Lf67210_00067865\n"
        "movss -0x60(%ebp), %xmm0\n" /* height */
        ".Lf67210_000673df:\n"
        "movss -0x78(%ebp), %xmm1\n" /* line 396 */
        "mulss %xmm0, %xmm1\n"
        "addss %xmm4, %xmm1\n"
        "movss -0x7c(%ebp), %xmm3\n" /* line 397 */
        "ucomiss %xmm1, %xmm3\n"
        "ja .Lf67210_00067415\n"
        "mulss 0x28(%ebx), %xmm0\n" /* line 400 | triangle */
        "addss %xmm2, %xmm0\n"
        "ucomiss %xmm0, %xmm3\n" /* line 401 */
        "ja .Lf67210_00067415\n"
        "addss %xmm0, %xmm1\n" /* line 404 */
        "ucomiss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "jbe .Lf67210_00067889\n"
        /* } scope */
        ".Lf67210_00067415:\n"
        "addl $0xac, %esp\n" /* line 651 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: result */
        ".Lf67210_00067420:\n"
        "movaps %xmm3, %xmm0\n" /* line 417 */
        "subss -0x6c(%ebp), %xmm0\n" /* cullEndRadius */
        "pxor %xmm2, %xmm2\n"
        "movss %xmm2, -0x7c(%ebp)\n"
        "ucomiss %xmm0, %xmm2\n"
        "jae .Lf67210_00067872\n"
        "movaps %xmm0, %xmm6\n" /* line 425 */
        "divss %xmm1, %xmm6\n"
        "ucomiss (%edi), %xmm6\n" /* line 426 | trace */
        "ja .Lf67210_00067415\n"
        "leal 0x24(%esi), %eax\n" /* line 430 | tw, dir */
        /* { scope 2 */
        "movaps %xmm6, %xmm5\n" /* line 288 */
        "mulss 0x24(%esi), %xmm5\n"
        "addss -0x3c(%ebp), %xmm5\n"
        "movaps %xmm6, %xmm2\n" /* line 289 */
        "mulss 4(%eax), %xmm2\n"
        "addss -0x40(%ebp), %xmm2\n"
        "movaps %xmm6, %xmm4\n" /* line 290 */
        "mulss 8(%eax), %xmm4\n"
        "addss -0x1c(%ebp), %xmm4\n"
        /* } scope */
        ".Lf67210_00067470:\n"
        "leal 0x10(%ebx), %eax\n" /* line 433 | triangle */
        "movaps %xmm5, %xmm1\n"
        "mulss 0x10(%ebx), %xmm1\n" /* triangle */
        "movaps %xmm2, %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movaps %xmm4, %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "subss 0x1c(%ebx), %xmm1\n" /* triangle */
        "leal 0x20(%ebx), %eax\n" /* line 434 | triangle */
        "movaps %xmm5, %xmm0\n"
        "mulss 0x20(%ebx), %xmm0\n" /* triangle */
        "mulss 4(%eax), %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "mulss 8(%eax), %xmm4\n"
        "addss %xmm4, %xmm0\n"
        "subss 0x2c(%ebx), %xmm0\n" /* triangle */
        "movaps %xmm1, %xmm2\n" /* line 454 */
        "addss %xmm0, %xmm2\n"
        "xorl %eax, %eax\n"
        "ucomiss 0x2ed5d0, %xmm2\n" /* 1.0f */
        "seta %al\n"
        "movss -0x7c(%ebp), %xmm2\n" /* line 455 */
        "xorl %edx, %edx\n"
        "ucomiss %xmm1, %xmm2\n"
        "seta %dl\n"
        "addl %edx, %edx\n"
        "orl %eax, %edx\n"
        "xorl %eax, %eax\n" /* line 456 */
        "ucomiss %xmm0, %xmm2\n"
        "seta %al\n"
        "shll $2, %eax\n"
        "orl %edx, %eax\n" /* line 459 */
        "movl %eax, -0x20(%ebp)\n"
        "jne .Lf67210_0006752b\n"
        "leal 4(%edi), %edx\n" /* line 462 | trace, to */
        /* { scope 2 */
        "movss -0x5c(%ebp), %xmm0\n" /* line 199 */
        "movss %xmm0, 4(%edi)\n"
        "movl -0x58(%ebp), %ecx\n" /* line 200 */
        "movl (%ecx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl -0x54(%ebp), %ecx\n" /* line 201 */
        "movl (%ecx), %eax\n"
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movss %xmm6, (%edi)\n" /* line 463 | trace */
        "movss 0x8c(%esi), %xmm0\n" /* line 465 | tw */
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lf67210_00067415\n"
        "movb $1, 0x23(%edi)\n" /* line 623 | trace */
        "jmp .Lf67210_00067415\n"
        ".Lf67210_0006752b:\n"
        "movss -0x6c(%ebp), %xmm0\n" /* line 613 | cullEndRadius */
        "mulss %xmm0, %xmm0\n"
        "movss %xmm0, -0x74(%ebp)\n"
        "movl %ebx, -0x34(%ebp)\n" /* triangle */
        "movl $0, -0x70(%ebp)\n" /* sideIndex */
        "leal 4(%edi), %eax\n" /* trace */
        "movl %eax, -0x44(%ebp)\n" /* result */
        "movl -0x20(%ebp), %eax\n" /* line 474 */
        "movzbl -0x70(%ebp), %ecx\n" /* sideIndex */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf67210_000676b8\n"
        ".Lf67210_0006755a:\n"
        "movl -0x34(%ebp), %eax\n" /* line 476 */
        "movl 0x3c(%eax), %edx\n"
        "testl %edx, %edx\n" /* line 477 */
        "js .Lf67210_00067695\n"
        "movl 0xa4(%esi), %eax\n" /* line 479 | tw */
        "leal (%eax, %edx, 4), %ecx\n"
        "movl 0xa0(%esi), %eax\n" /* tw */
        "cmpl %eax, (%ecx)\n"
        "je .Lf67210_00067695\n"
        "movl %eax, (%ecx)\n" /* line 481 */
        "leal (%edx, %edx, 2), %edx\n" /* line 514 */
        "shll $4, %edx\n"
        "movl 0x195eda4, %ecx\n"
        "addl 0x50(%ecx), %edx\n"
        "movss -0x3c(%ebp), %xmm0\n" /* line 248 */
        "subss (%edx), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        "movss -0x40(%ebp), %xmm1\n" /* line 249 */
        "subss 4(%edx), %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "movss -0x1c(%ebp), %xmm2\n" /* line 250 */
        "subss 8(%edx), %xmm2\n"
        "movss %xmm2, -0x2c(%ebp)\n"
        "movss 0x10(%edx), %xmm3\n" /* line 304 */
        "movss 0x14(%edx), %xmm4\n" /* offsetZ */
        "mulss 0xc(%edx), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "movaps %xmm1, %xmm0\n" /* s */
        "mulss %xmm3, %xmm0\n"
        "addss -0x38(%ebp), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "movaps %xmm2, %xmm0\n"
        "mulss %xmm4, %xmm0\n" /* offsetZ */
        "addss -0x38(%ebp), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "movss 0x1c(%edx), %xmm1\n" /* s */
        "movss 0x20(%edx), %xmm2\n"
        "movss -0x24(%ebp), %xmm6\n"
        "mulss 0x18(%edx), %xmm6\n"
        "movss -0x28(%ebp), %xmm0\n"
        "mulss %xmm1, %xmm0\n" /* s */
        "addss %xmm0, %xmm6\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm6\n"
        "leal 0x24(%esi), %eax\n" /* line 525 | tw, a */
        /* { scope 2 */
        "movss 0x24(%esi), %xmm0\n" /* line 304 | tw */
        "movss %xmm0, -0x50(%ebp)\n"
        "movss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n"
        "movss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x48(%ebp)\n"
        "movss -0x50(%ebp), %xmm5\n"
        "mulss 0xc(%edx), %xmm5\n"
        "mulss -0x4c(%ebp), %xmm3\n"
        "addss %xmm3, %xmm5\n"
        "mulss %xmm0, %xmm4\n" /* offsetZ */
        "addss %xmm4, %xmm5\n" /* offsetZ */
        /* } scope */
        "movss -0x50(%ebp), %xmm3\n"
        "mulss 0x18(%edx), %xmm3\n"
        "mulss -0x4c(%ebp), %xmm1\n" /* s */
        "addss %xmm1, %xmm3\n" /* s */
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm3\n"
        "movss -0x38(%ebp), %xmm1\n" /* line 114 */
        "mulss %xmm5, %xmm1\n"
        "movaps %xmm6, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "ucomiss -0x7c(%ebp), %xmm1\n" /* line 528 */
        "jb .Lf67210_000678e6\n"
        ".Lf67210_00067695:\n"
        "addl $1, -0x70(%ebp)\n" /* line 472 | sideIndex */
        "addl $4, -0x34(%ebp)\n"
        "cmpl $3, -0x70(%ebp)\n" /* sideIndex */
        "je .Lf67210_00067415\n"
        "movl -0x20(%ebp), %eax\n" /* line 474 */
        "movzbl -0x70(%ebp), %ecx\n" /* sideIndex */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf67210_0006755a\n"
        ".Lf67210_000676b8:\n"
        "movl -0x34(%ebp), %eax\n" /* line 593 */
        "movl 0x30(%eax), %edx\n"
        "testl %edx, %edx\n" /* line 594 */
        "js .Lf67210_00067695\n"
        "movl 0xa8(%esi), %eax\n" /* line 596 | tw */
        "leal (%eax, %edx, 4), %ecx\n"
        "movl 0xa0(%esi), %eax\n" /* tw */
        "cmpl %eax, (%ecx)\n"
        "je .Lf67210_00067695\n"
        "movl %eax, (%ecx)\n" /* line 598 */
        "leal (%edx, %edx, 2), %eax\n"
        "movl 0x195eda4, %ecx\n"
        "movl 0x48(%ecx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        /* { scope 2 */
        "movss -0x3c(%ebp), %xmm3\n" /* line 248 */
        "subss (%eax), %xmm3\n"
        "movss -0x40(%ebp), %xmm4\n" /* line 249 */
        "subss 4(%eax), %xmm4\n"
        "movss -0x1c(%ebp), %xmm5\n" /* line 250 */
        "subss 8(%eax), %xmm5\n"
        /* } scope */
        "movss 0x24(%esi), %xmm6\n" /* line 304 | tw */
        "movaps %xmm3, %xmm1\n" /* s */
        "mulss %xmm6, %xmm1\n" /* s */
        "movaps %xmm4, %xmm0\n" /* offsetZ */
        "mulss 0x28(%esi), %xmm0\n" /* tw */
        "addss %xmm0, %xmm1\n" /* s */
        "movaps %xmm5, %xmm0\n"
        "mulss 0x2c(%esi), %xmm0\n" /* tw */
        "addss %xmm0, %xmm1\n" /* s */
        "pxor %xmm0, %xmm0\n" /* line 608 */
        "ucomiss %xmm0, %xmm1\n"
        "jae .Lf67210_00067695\n"
        "movaps %xmm3, %xmm2\n" /* line 304 */
        "mulss %xmm3, %xmm2\n"
        "movaps %xmm4, %xmm0\n" /* offsetZ */
        "mulss %xmm4, %xmm0\n" /* offsetZ */
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -0x68(%ebp)\n" /* deltaLenSq */
        "movaps %xmm5, %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "addss -0x68(%ebp), %xmm0\n" /* deltaLenSq */
        "movss %xmm0, -0x68(%ebp)\n" /* deltaLenSq */
        "movaps %xmm0, %xmm2\n" /* line 613 */
        "subss -0x74(%ebp), %xmm2\n"
        "pxor %xmm0, %xmm0\n" /* line 614 */
        "ucomiss %xmm2, %xmm0\n"
        "jae .Lf67210_00067c22\n"
        "movss 0x34(%esi), %xmm0\n" /* line 628 | tw */
        "movss %xmm0, -0x64(%ebp)\n" /* a */
        "movaps %xmm1, %xmm0\n" /* line 630 */
        "mulss %xmm1, %xmm0\n"
        "mulss -0x64(%ebp), %xmm2\n" /* a */
        "subss %xmm2, %xmm0\n"
        "movss -0x7c(%ebp), %xmm2\n" /* line 631 */
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf67210_00067695\n"
        "sqrtss %xmm0, %xmm2\n" /* line 81 */
        "xorps 0x2f0610, %xmm2\n"
        "subss %xmm1, %xmm2\n"
        "divss -0x64(%ebp), %xmm2\n" /* a */
        "movss (%edi), %xmm0\n" /* line 635 | trace */
        "ucomiss %xmm2, %xmm0\n"
        "jbe .Lf67210_00067695\n"
        "mulss %xmm2, %xmm6\n" /* line 288 */
        "addss %xmm6, %xmm3\n"
        "movss %xmm3, 4(%edi)\n"
        "movaps %xmm2, %xmm0\n" /* line 289 */
        "mulss 0x28(%esi), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "movss %xmm4, 8(%edi)\n"
        "movaps %xmm2, %xmm0\n" /* line 290 */
        "mulss 0x2c(%esi), %xmm0\n"
        "addss %xmm0, %xmm5\n"
        "movss %xmm5, 0xc(%edi)\n"
        "movss 0x2ed5d0, %xmm1\n" /* line 642 | 1.0f, scale */
        "divss -0x6c(%ebp), %xmm1\n" /* cullEndRadius, scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 272 */
        "mulss %xmm3, %xmm0\n"
        "movss %xmm0, 4(%edi)\n"
        "movaps %xmm1, %xmm0\n" /* line 273 */
        "movl -0x44(%ebp), %eax\n" /* result */
        "mulss 4(%eax), %xmm0\n"
        "movss %xmm0, 8(%edi)\n"
        "mulss 8(%eax), %xmm1\n" /* line 274 */
        "movss %xmm1, 0xc(%edi)\n"
        /* } scope */
        "movss 8(%ebx), %xmm0\n" /* line 643 | triangle */
        "ucomiss 0x2ed6ac, %xmm0\n" /* 0.699999988079071f */
        "jb .Lf67210_0006785c\n"
        "ucomiss -0x7c(%ebp), %xmm1\n"
        "jb .Lf67210_0006785c\n"
        "movss 0x2ed6ac, %xmm0\n" /* 0.699999988079071f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf67210_0006785c\n"
        "movss -0x1c(%ebp), %xmm1\n"
        "ucomiss %xmm7, %xmm1\n"
        "jbe .Lf67210_0006785c\n"
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, 4(%edi)\n"
        "movl -0x58(%ebp), %edx\n" /* line 200 */
        "movl (%edx), %eax\n"
        "movl %eax, 8(%edi)\n"
        "movl -0x54(%ebp), %ecx\n" /* line 201 */
        "movl (%ecx), %eax\n"
        "movl %eax, 0xc(%edi)\n"
        ".Lf67210_0006785c:\n"
        "movss %xmm2, (%edi)\n" /* line 646 | trace */
        "jmp .Lf67210_00067695\n"
        ".Lf67210_00067865:\n"
        "subss %xmm3, %xmm0\n" /* line 391 */
        "divss %xmm6, %xmm0\n"
        "jmp .Lf67210_000673df\n"
        ".Lf67210_00067872:\n"
        "movaps %xmm2, %xmm6\n"
        "movss -0x1c(%ebp), %xmm4\n" /* line 417 */
        "movss -0x40(%ebp), %xmm2\n"
        "movss -0x3c(%ebp), %xmm5\n"
        "jmp .Lf67210_00067470\n"
        ".Lf67210_00067889:\n"
        "leal 4(%edi), %eax\n" /* line 407 | trace, to */
        /* { scope 2 */
        "movss -0x5c(%ebp), %xmm0\n" /* line 199 */
        "movss %xmm0, 4(%edi)\n"
        "movl -0x58(%ebp), %ecx\n" /* line 200 */
        "movl (%ecx), %edx\n"
        "movl %edx, 4(%eax)\n"
        "movl -0x54(%ebp), %ecx\n" /* line 201 */
        "movl (%ecx), %edx\n"
        "movl %edx, 8(%eax)\n"
        /* } scope */
        "movl $0, (%edi)\n" /* line 408 | trace */
        "movb $1, 0x23(%edi)\n" /* line 409 | trace */
        "jmp .Lf67210_00067415\n"
        ".Lf67210_000678b5:\n"
        "jp .Lf67210_000673cc\n" /* line 373 */
        "leal 4(%edi), %eax\n" /* line 375 | trace, to */
        /* { scope 2 */
        "movss -0x5c(%ebp), %xmm1\n" /* line 199 */
        "movss %xmm1, 4(%edi)\n"
        "movl 4(%ebx), %edx\n" /* line 200 */
        "movl %edx, 4(%eax)\n"
        "movl 8(%ebx), %edx\n" /* line 201 */
        "movl %edx, 8(%eax)\n"
        /* } scope */
        "movss -0x7c(%ebp), %xmm2\n" /* line 376 */
        "movss %xmm2, (%edi)\n" /* trace */
        "movb $1, 0x23(%edi)\n" /* line 377 | trace */
        "jmp .Lf67210_00067415\n"
        ".Lf67210_000678e6:\n"
        "movss -0x38(%ebp), %xmm4\n" /* line 114 */
        "mulss %xmm4, %xmm4\n"
        "movaps %xmm6, %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "movaps %xmm4, %xmm2\n" /* line 532 */
        "subss -0x74(%ebp), %xmm2\n"
        "movss -0x7c(%ebp), %xmm0\n" /* line 533 */
        "ucomiss %xmm2, %xmm0\n"
        "jae .Lf67210_00067ad3\n"
        "movaps %xmm5, %xmm4\n" /* line 126 */
        "mulss %xmm5, %xmm4\n"
        "movaps %xmm3, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "movaps %xmm1, %xmm0\n" /* line 555 */
        "mulss %xmm1, %xmm0\n"
        "mulss %xmm4, %xmm2\n"
        "subss %xmm2, %xmm0\n"
        "movss -0x7c(%ebp), %xmm2\n" /* line 556 */
        "ucomiss %xmm0, %xmm2\n"
        "jae .Lf67210_00067695\n"
        "sqrtss %xmm0, %xmm0\n" /* line 81 */
        "movss %xmm0, -0x30(%ebp)\n"
        "xorl $0x80000000, -0x30(%ebp)\n"
        "movss -0x30(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "divss %xmm4, %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "movss (%edi), %xmm0\n" /* line 560 | trace */
        "ucomiss -0x30(%ebp), %xmm0\n"
        "jbe .Lf67210_00067695\n"
        "leal 0x24(%edx), %eax\n"
        "movss -0x50(%ebp), %xmm1\n" /* line 565 */
        "mulss -0x30(%ebp), %xmm1\n"
        "movss -0x24(%ebp), %xmm2\n"
        "addss %xmm1, %xmm2\n"
        "movss %xmm2, -0x24(%ebp)\n"
        "mulss 0x24(%edx), %xmm2\n"
        "movss %xmm2, -0x24(%ebp)\n"
        "movss -0x4c(%ebp), %xmm0\n"
        "mulss -0x30(%ebp), %xmm0\n"
        "movss -0x28(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "mulss 4(%eax), %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "movss %xmm2, -0x24(%ebp)\n"
        "movss -0x48(%ebp), %xmm2\n"
        "mulss -0x30(%ebp), %xmm2\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "mulss 8(%eax), %xmm0\n"
        "movss -0x24(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "subss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "movss %xmm1, -0x24(%ebp)\n"
        "andl $0x7fffffff, -0x24(%ebp)\n"
        "movss -0x24(%ebp), %xmm2\n"
        "ucomiss 0x2ed5d8, %xmm2\n" /* 0.5f */
        "ja .Lf67210_00067695\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 580 */
        "mulss %xmm5, %xmm0\n"
        "addss -0x38(%ebp), %xmm0\n"
        "divss -0x6c(%ebp), %xmm0\n" /* cullEndRadius */
        "movss -0x30(%ebp), %xmm2\n" /* line 581 */
        "mulss %xmm3, %xmm2\n"
        "addss %xmm6, %xmm2\n"
        "divss -0x6c(%ebp), %xmm2\n" /* cullEndRadius */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss 0xc(%edx), %xmm1\n"
        "movss %xmm1, 4(%edi)\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss 0x10(%edx), %xmm1\n"
        "movss %xmm1, 8(%edi)\n"
        "mulss 0x14(%edx), %xmm0\n" /* line 274 */
        "movss %xmm0, 0xc(%edi)\n"
        "movaps %xmm2, %xmm0\n" /* line 288 */
        "mulss 0x18(%edx), %xmm0\n"
        "addss 4(%edi), %xmm0\n"
        "movss %xmm0, 4(%edi)\n"
        "movaps %xmm2, %xmm0\n" /* line 289 */
        "mulss 0x1c(%edx), %xmm0\n"
        "movl -0x44(%ebp), %eax\n" /* result */
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, 8(%edi)\n"
        "mulss 0x20(%edx), %xmm2\n" /* line 290 */
        "addss 8(%eax), %xmm2\n"
        "movss %xmm2, 0xc(%edi)\n"
        "movss 8(%ebx), %xmm0\n" /* line 584 | triangle */
        "ucomiss 0x2ed6ac, %xmm0\n" /* 0.699999988079071f */
        "jb .Lf67210_00067ac5\n"
        "ucomiss -0x7c(%ebp), %xmm2\n"
        "jb .Lf67210_00067ac5\n"
        "movss 0x2ed6ac, %xmm0\n" /* 0.699999988079071f */
        "ucomiss %xmm2, %xmm0\n"
        "jbe .Lf67210_00067ac5\n"
        "movss -0x1c(%ebp), %xmm1\n"
        "ucomiss %xmm7, %xmm1\n"
        "jbe .Lf67210_00067ac5\n"
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, 4(%edi)\n"
        "movl -0x58(%ebp), %edx\n" /* line 200 */
        "movl (%edx), %eax\n"
        "movl %eax, 8(%edi)\n"
        "movl -0x54(%ebp), %ecx\n" /* line 201 */
        "movl (%ecx), %eax\n"
        "movl %eax, 0xc(%edi)\n"
        ".Lf67210_00067ac5:\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 587 */
        "movss %xmm0, (%edi)\n" /* trace */
        "jmp .Lf67210_00067695\n"
        ".Lf67210_00067ad3:\n"
        "leal 0x24(%edx), %eax\n" /* line 533 */
        "movss -0x24(%ebp), %xmm1\n" /* line 538 */
        "mulss 0x24(%edx), %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n"
        "movss -0x28(%ebp), %xmm2\n"
        "mulss 4(%eax), %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n"
        "movss -0x2c(%ebp), %xmm3\n"
        "mulss 8(%eax), %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "subss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "movss %xmm1, -0x24(%ebp)\n"
        "andl $0x7fffffff, -0x24(%ebp)\n"
        "movss -0x24(%ebp), %xmm0\n"
        "ucomiss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "ja .Lf67210_00067695\n"
        /* { scope 2 */
        "movss -0x38(%ebp), %xmm0\n" /* line 272 */
        "mulss 0xc(%edx), %xmm0\n"
        "movss %xmm0, 4(%edi)\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 273 */
        "mulss 0x10(%edx), %xmm0\n"
        "movss %xmm0, 8(%edi)\n"
        "movss -0x38(%ebp), %xmm1\n" /* line 274 */
        "mulss 0x14(%edx), %xmm1\n"
        "movss %xmm1, 0xc(%edi)\n"
        /* } scope */
        "movaps %xmm6, %xmm0\n" /* line 288 */
        "mulss 0x18(%edx), %xmm0\n"
        "addss 4(%edi), %xmm0\n"
        "movss %xmm0, 4(%edi)\n"
        "movaps %xmm6, %xmm0\n" /* line 289 */
        "mulss 0x1c(%edx), %xmm0\n"
        "movl -0x44(%ebp), %eax\n" /* result */
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, 8(%edi)\n"
        "mulss 0x20(%edx), %xmm6\n" /* line 290 */
        "addss 8(%eax), %xmm6\n"
        "movss %xmm6, 0xc(%edi)\n"
        "movl %eax, (%esp)\n" /* line 543 */
        "movss %xmm4, -0x98(%ebp)\n"
        "movss %xmm7, -0xa8(%ebp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movss 8(%ebx), %xmm0\n" /* line 544 | triangle */
        "ucomiss 0x2ed6ac, %xmm0\n" /* 0.699999988079071f */
        "movss -0x98(%ebp), %xmm4\n"
        "movss -0xa8(%ebp), %xmm7\n"
        "jb .Lf67210_00067bfe\n"
        "movss 0xc(%edi), %xmm0\n" /* trace */
        "ucomiss -0x7c(%ebp), %xmm0\n"
        "jb .Lf67210_00067bfe\n"
        "movss 0x2ed6ac, %xmm1\n" /* 0.699999988079071f */
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf67210_00067bfe\n"
        "movss -0x1c(%ebp), %xmm2\n"
        "ucomiss %xmm7, %xmm2\n"
        "jbe .Lf67210_00067bfe\n"
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, 4(%edi)\n"
        "movl -0x58(%ebp), %edx\n" /* line 200 */
        "movl (%edx), %eax\n"
        "movl %eax, 8(%edi)\n"
        "movl -0x54(%ebp), %ecx\n" /* line 201 */
        "movl (%ecx), %eax\n"
        "movl %eax, 0xc(%edi)\n"
        ".Lf67210_00067bfe:\n"
        "movl $0, (%edi)\n" /* line 547 | trace */
        "movss 0x8c(%esi), %xmm0\n" /* line 548 | tw */
        "mulss %xmm0, %xmm0\n"
        "ucomiss %xmm4, %xmm0\n"
        "jbe .Lf67210_00067415\n"
        "movb $1, 0x23(%edi)\n" /* line 623 | trace */
        "jmp .Lf67210_00067415\n"
        ".Lf67210_00067c22:\n"
        "sqrtss -0x68(%ebp), %xmm0\n" /* line 81 | deltaLenSq */
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "divss %xmm0, %xmm1\n"
        "mulss %xmm1, %xmm3\n" /* line 272 */
        "movss %xmm3, 4(%edi)\n"
        "mulss %xmm1, %xmm4\n" /* line 273 */
        "movss %xmm4, 8(%edi)\n"
        "mulss %xmm5, %xmm1\n" /* line 274 */
        "movss %xmm1, 0xc(%edi)\n"
        "movss 8(%ebx), %xmm0\n" /* line 618 | triangle */
        "ucomiss 0x2ed6ac, %xmm0\n" /* 0.699999988079071f */
        "jb .Lf67210_00067c91\n"
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm2, %xmm1\n"
        "jb .Lf67210_00067c91\n"
        "movss 0x2ed6ac, %xmm3\n" /* 0.699999988079071f */
        "ucomiss %xmm1, %xmm3\n"
        "jbe .Lf67210_00067c91\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "ucomiss %xmm7, %xmm0\n"
        "jbe .Lf67210_00067c91\n"
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, 4(%edi)\n"
        "movl -0x58(%ebp), %edx\n" /* line 200 */
        "movl (%edx), %eax\n"
        "movl %eax, 8(%edi)\n"
        "movl -0x54(%ebp), %ecx\n" /* line 201 */
        "movl (%ecx), %eax\n"
        "movl %eax, 0xc(%edi)\n"
        ".Lf67210_00067c91:\n"
        "movl $0, (%edi)\n" /* line 621 | trace */
        "movss 0x8c(%esi), %xmm0\n" /* line 622 | tw */
        "mulss %xmm0, %xmm0\n"
        "ucomiss -0x68(%ebp), %xmm0\n" /* deltaLenSq */
        "jbe .Lf67210_00067415\n"
        "movb $1, 0x23(%edi)\n" /* line 623 | trace */
        "jmp .Lf67210_00067415\n"
    );
}

/* line 900 */
static __attribute__((naked))
short int CM_TraceThroughAabbTree_r(const traceWork_t *tw, trace_t *trace)
{
    __asm__ __volatile__ (
        ".Lf67cb6_00067cb6:\n"
        "pushl %ebp\n" /* line 900 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, -0x48(%ebp)\n"
        "movl %edx, %esi\n" /* aabbTree */
        "movl %ecx, -0x4c(%ebp)\n"
        /* { scope 1 */
        "leal 0xc(%edx), %ecx\n" /* line 911 */
        "calll CM_CullBox\n"
        "testb %al, %al\n"
        "jne .Lf67cb6_00067eef\n"
        "movzwl 0x1a(%esi), %edx\n" /* line 914 | triIndex */
        "testw %dx, %dx\n"
        "jne .Lf67cb6_00067ef7\n"
        "movl -0x48(%ebp), %eax\n" /* line 923 */
        "movl 0xa0(%eax), %edi\n" /* childIndex */
        "movl 0x1c(%esi), %ecx\n" /* line 924 | triIndex */
        "leal (%ecx, %ecx), %esi\n" /* triIndex */
        "movl %esi, %ebx\n" /* triIndex, triangle */
        "addl 0xac(%eax), %ebx\n" /* triangle */
        "movzwl (%ebx), %edx\n" /* triangle */
        "movswl %di, %eax\n" /* childIndex */
        "cmpl %eax, %edx\n"
        "je .Lf67cb6_00067eef\n"
        "movw %di, (%ebx)\n" /* line 926 | childIndex, triangle */
        "leal (%esi, %ecx), %eax\n" /* line 928 | triIndex */
        "movl 0x195eda4, %edx\n"
        "movl 0x68(%edx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0x44(%ebp)\n" /* partition */
        "movl -0x48(%ebp), %edx\n" /* line 929 */
        "movl 0x84(%edx), %ebx\n" /* triangle */
        "testl %ebx, %ebx\n" /* triangle */
        "je .Lf67cb6_00067f2f\n"
        "cmpb $0, (%eax)\n" /* line 931 */
        "je .Lf67cb6_00067eef\n"
        "xorl %esi, %esi\n" /* triIndex */
        "xorl %ebx, %ebx\n" /* triangle */
        "movl -0x48(%ebp), %eax\n"
        "leal 0xc(%eax), %edi\n" /* childIndex */
        "movl %eax, %edx\n"
        "jmp .Lf67cb6_00067d5c\n"
        ".Lf67cb6_00067d46:\n"
        "movl %eax, %edx\n"
        ".Lf67cb6_00067d48:\n"
        "addl $1, %esi\n" /* triIndex */
        "addl $0x48, %ebx\n" /* triangle */
        "movzbl (%edx), %eax\n"
        "cmpl %esi, %eax\n" /* triIndex */
        "jle .Lf67cb6_00067eef\n"
        "movl -0x48(%ebp), %edx\n"
        ".Lf67cb6_00067d5c:\n"
        "movl %ebx, %ecx\n" /* line 929 | triangle */
        "movl -0x44(%ebp), %eax\n" /* partition */
        "addl 4(%eax), %ecx\n"
        /* { scope 2: radius */
        /* { scope 3 */
        "movss (%ecx), %xmm4\n" /* line 304 */
        "movss 4(%ecx), %xmm2\n"
        "movss 8(%ecx), %xmm3\n"
        "movss 0xc(%ecx), %xmm5\n" /* line 48 */
        "movaps %xmm4, %xmm1\n"
        "mulss 0xc(%edx), %xmm1\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 4(%edi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movaps %xmm3, %xmm0\n"
        "mulss 8(%edi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "subss %xmm5, %xmm1\n"
        "pxor %xmm0, %xmm0\n" /* line 49 */
        "ucomiss %xmm0, %xmm1\n"
        "jae .Lf67cb6_00067d46\n"
        "movss (%edx), %xmm6\n" /* line 304 */
        "movss 4(%edx), %xmm7\n"
        "movss 8(%edx), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        "movaps %xmm4, %xmm0\n" /* line 52 */
        "mulss %xmm6, %xmm0\n"
        "mulss %xmm7, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "mulss -0x40(%ebp), %xmm3\n"
        "addss %xmm3, %xmm0\n"
        "subss %xmm5, %xmm0\n"
        "pxor %xmm2, %xmm2\n" /* line 53 */
        "ucomiss %xmm0, %xmm2\n"
        "jae .Lf67cb6_00068200\n"
        "movaps %xmm0, %xmm2\n" /* line 58 */
        "subss %xmm1, %xmm2\n"
        "movaps %xmm0, %xmm1\n"
        "subss 0x2ed610, %xmm1\n" /* 0.125f */
        "divss %xmm2, %xmm1\n"
        "pxor %xmm3, %xmm3\n" /* line 45 */
        "maxss %xmm1, %xmm3\n"
        "movaps %xmm3, %xmm1\n"
        "movl -0x4c(%ebp), %eax\n" /* line 61 */
        "ucomiss (%eax), %xmm3\n"
        "jae .Lf67cb6_00068200\n"
        "divss %xmm2, %xmm0\n" /* line 65 */
        "movl %edx, %eax\n" /* line 66 | dir */
        "addl $0x24, %eax\n" /* dir */
        /* { scope 4 */
        "movaps %xmm0, %xmm3\n" /* line 288 */
        "mulss 0x24(%edx), %xmm3\n"
        "addss %xmm6, %xmm3\n"
        "movaps %xmm0, %xmm4\n" /* line 289 */
        "mulss 4(%eax), %xmm4\n"
        "addss %xmm7, %xmm4\n"
        "movaps %xmm0, %xmm5\n" /* line 290 */
        "mulss 8(%eax), %xmm5\n"
        "addss -0x40(%ebp), %xmm5\n"
        /* } scope */
        "leal 0x10(%ecx), %eax\n" /* line 68 */
        "movaps %xmm3, %xmm2\n"
        "mulss 0x10(%ecx), %xmm2\n"
        "movaps %xmm4, %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movaps %xmm5, %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "subss 0x1c(%ecx), %xmm2\n"
        "ucomiss 0x2ed670, %xmm2\n" /* line 69 | -0.0010000000474974513f */
        "jp .Lf67cb6_00067e72\n"
        "jb .Lf67cb6_00068200\n"
        ".Lf67cb6_00067e72:\n"
        "ucomiss 0x2ed674, %xmm2\n" /* 1.0010000467300415f */
        "ja .Lf67cb6_00068200\n"
        "leal 0x20(%ecx), %eax\n" /* line 72 */
        "mulss 0x20(%ecx), %xmm3\n"
        "mulss 4(%eax), %xmm4\n"
        "addss %xmm4, %xmm3\n"
        "mulss 8(%eax), %xmm5\n"
        "addss %xmm5, %xmm3\n"
        "subss 0x2c(%ecx), %xmm3\n"
        "movss 0x2ed670, %xmm0\n" /* line 73 | -0.0010000000474974513f */
        "ucomiss %xmm3, %xmm0\n"
        "ja .Lf67cb6_00068200\n"
        "addss %xmm3, %xmm2\n"
        "ucomiss 0x2ed674, %xmm2\n" /* 1.0010000467300415f */
        "ja .Lf67cb6_00068200\n"
        "movl -0x4c(%ebp), %edx\n" /* line 77 */
        "movss %xmm1, (%edx)\n"
        "movl -0x4c(%ebp), %edx\n" /* line 80 | to */
        "addl $4, %edx\n" /* to */
        /* { scope 4 */
        "movss (%ecx), %xmm0\n" /* line 199 */
        "movl -0x4c(%ebp), %eax\n"
        "movss %xmm0, 4(%eax)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "movl -0x44(%ebp), %edx\n" /* partition */
        "jmp .Lf67cb6_00067d48\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf67cb6_00067eed:\n"
        "jp .Lf67cb6_00067f62\n" /* line 948 */
        /* } scope */
        ".Lf67cb6_00067eef:\n"
        "addl $0x5c, %esp\n" /* line 963 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf67cb6_00067ef7:\n"
        "movl 0x1c(%esi), %ebx\n" /* line 916 | triIndex, triangle */
        "shll $5, %ebx\n" /* triangle */
        "movl 0x195eda4, %eax\n"
        "addl 0x70(%eax), %ebx\n" /* triangle */
        "testw %dx, %dx\n"
        "je .Lf67cb6_00067eef\n"
        "xorl %edi, %edi\n" /* childIndex */
        ".Lf67cb6_00067f0c:\n"
        "movl -0x4c(%ebp), %ecx\n" /* line 917 */
        "movl %ebx, %edx\n" /* triangle */
        "movl -0x48(%ebp), %eax\n"
        "calll CM_TraceThroughAabbTree_r\n"
        "addl $1, %edi\n" /* line 916 | childIndex */
        "addl $0x20, %ebx\n" /* triangle */
        "movzwl 0x1a(%esi), %eax\n" /* triIndex */
        "cmpl %edi, %eax\n" /* childIndex */
        "jg .Lf67cb6_00067f0c\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 963 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf67cb6_00067f2f:\n"
        "movl -0x44(%ebp), %eax\n" /* line 936 | partition */
        "cmpb $0, (%eax)\n"
        "jne .Lf67cb6_00068208\n"
        ".Lf67cb6_00067f3b:\n"
        "pxor %xmm0, %xmm0\n" /* line 946 */
        "movl -0x48(%ebp), %eax\n"
        "ucomiss 0x24(%eax), %xmm0\n"
        "jne .Lf67cb6_00067f55\n"
        "jp .Lf67cb6_00067f55\n"
        "ucomiss 0x28(%eax), %xmm0\n"
        "jp .Lf67cb6_00067f52\n"
        "je .Lf67cb6_00067eef\n"
        ".Lf67cb6_00067f52:\n"
        "movl -0x48(%ebp), %eax\n"
        ".Lf67cb6_00067f55:\n"
        "pxor %xmm0, %xmm0\n" /* line 948 */
        "ucomiss 0x90(%eax), %xmm0\n"
        "je .Lf67cb6_00067eed\n"
        ".Lf67cb6_00067f62:\n"
        "movl -0x44(%ebp), %edx\n" /* line 950 | partition */
        "cmpb $0, 1(%edx)\n"
        "je .Lf67cb6_00067eef\n"
        "xorl %esi, %esi\n" /* triIndex */
        "xorl %ebx, %ebx\n" /* triangle */
        "movl -0x48(%ebp), %eax\n"
        "leal 0x24(%eax), %edi\n" /* childIndex */
        "jmp .Lf67cb6_00067f8c\n"
        ".Lf67cb6_00067f77:\n"
        "addl $1, %esi\n" /* triIndex */
        "addl $0x1c, %ebx\n" /* triangle */
        "movl -0x44(%ebp), %edx\n" /* partition */
        "movzbl 1(%edx), %eax\n"
        "cmpl %eax, %esi\n" /* triIndex */
        "jge .Lf67cb6_00067eef\n"
        ".Lf67cb6_00067f8c:\n"
        "movl %ebx, %eax\n" /* line 951 | triangle, border */
        "movl -0x44(%ebp), %edx\n" /* partition */
        "addl 8(%edx), %eax\n" /* border */
        /* { scope 2: radius */
        /* { scope 3 */
        "movl -0x48(%ebp), %edx\n" /* line 114 */
        "movss 0x24(%edx), %xmm6\n"
        "movss 4(%edi), %xmm3\n"
        "movss 4(%eax), %xmm5\n"
        "movaps %xmm6, %xmm2\n"
        "mulss (%eax), %xmm2\n"
        "movaps %xmm3, %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "pxor %xmm0, %xmm0\n" /* line 799 */
        "ucomiss %xmm0, %xmm2\n"
        "jae .Lf67cb6_00067f77\n"
        "movss 0x2ed610, %xmm0\n" /* line 802 | 0.125f */
        "movss %xmm0, -0x30(%ebp)\n" /* radius */
        "addss 0x8c(%edx), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* radius */
        "movss (%edx), %xmm0\n" /* line 114 */
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss 4(%edx), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "movss 8(%eax), %xmm7\n" /* line 803 */
        "movss -0x2c(%ebp), %xmm0\n" /* line 804 */
        "mulss (%eax), %xmm0\n"
        "movss -0x28(%ebp), %xmm1\n"
        "mulss %xmm5, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "subss %xmm7, %xmm0\n"
        "movss -0x30(%ebp), %xmm4\n" /* radius */
        "subss %xmm0, %xmm4\n"
        "divss %xmm2, %xmm4\n"
        "movl -0x4c(%ebp), %edx\n" /* line 805 */
        "movss (%edx), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "ucomiss %xmm0, %xmm4\n"
        "jae .Lf67cb6_00067f77\n"
        "movaps %xmm4, %xmm1\n"
        "movl -0x48(%ebp), %edx\n"
        "mulss 0x30(%edx), %xmm1\n"
        "movss -0x30(%ebp), %xmm0\n" /* radius */
        "xorps 0x2f0620, %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf67cb6_00067f77\n"
        "movss 8(%edx), %xmm0\n" /* line 290 */
        "movss %xmm0, -0x24(%ebp)\n"
        "movss 8(%edi), %xmm2\n"
        "movss %xmm2, -0x20(%ebp)\n"
        "mulss %xmm4, %xmm2\n"
        "addss %xmm0, %xmm2\n"
        "movss (%eax), %xmm0\n" /* line 809 */
        "movss %xmm0, -0x38(%ebp)\n"
        "movss 0x14(%eax), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "movaps %xmm6, %xmm1\n"
        "mulss %xmm4, %xmm1\n"
        "addss -0x2c(%ebp), %xmm1\n"
        "mulss %xmm5, %xmm1\n"
        "movaps %xmm3, %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "addss -0x28(%ebp), %xmm0\n"
        "mulss -0x38(%ebp), %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "subss -0x34(%ebp), %xmm1\n"
        "pxor %xmm0, %xmm0\n" /* line 810 */
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf67cb6_0006827c\n"
        "movss 0x18(%eax), %xmm0\n" /* line 847 */
        "movss %xmm0, -0x1c(%ebp)\n"
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf67cb6_0006826c\n"
        "movss -0x34(%ebp), %xmm0\n" /* line 849 */
        "addss -0x1c(%ebp), %xmm0\n"
        "movaps %xmm5, %xmm1\n" /* line 65 */
        "mulss %xmm0, %xmm1\n"
        "movss -0x38(%ebp), %xmm2\n"
        "mulss %xmm7, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss -0x2c(%ebp), %xmm2\n"
        "subss %xmm1, %xmm2\n"
        "mulss %xmm5, %xmm7\n" /* line 66 */
        "mulss -0x38(%ebp), %xmm0\n" /* scale */
        "subss %xmm0, %xmm7\n" /* scale */
        "movss -0x28(%ebp), %xmm0\n" /* scale */
        "subss %xmm7, %xmm0\n" /* scale */
        "movaps %xmm6, %xmm1\n" /* line 114 */
        "mulss %xmm2, %xmm1\n"
        "mulss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "pxor %xmm3, %xmm3\n" /* line 853 */
        "ucomiss %xmm3, %xmm1\n"
        "jae .Lf67cb6_00067f77\n"
        "mulss %xmm2, %xmm2\n" /* line 114 */
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 857 | radius */
        "mulss %xmm0, %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* radius */
        "movaps %xmm2, %xmm0\n"
        "subss -0x30(%ebp), %xmm0\n" /* radius */
        "ucomiss %xmm0, %xmm3\n" /* line 858 */
        "ja .Lf67cb6_00068365\n"
        "movl -0x48(%ebp), %edx\n" /* line 872 */
        "movss 0x34(%edx), %xmm3\n"
        "movaps %xmm1, %xmm2\n"
        "mulss %xmm1, %xmm2\n"
        "mulss %xmm3, %xmm0\n"
        "subss %xmm0, %xmm2\n"
        "pxor %xmm0, %xmm0\n" /* line 873 */
        "ucomiss %xmm2, %xmm0\n"
        "ja .Lf67cb6_00067f77\n"
        "movaps %xmm1, %xmm4\n" /* line 877 */
        "xorps 0x2f0620, %xmm4\n"
        "sqrtss %xmm2, %xmm0\n" /* line 81 */
        "subss %xmm0, %xmm4\n"
        "divss %xmm3, %xmm4\n"
        "ucomiss -0x3c(%ebp), %xmm4\n" /* line 878 */
        "jae .Lf67cb6_00067f77\n"
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm4, %xmm2\n"
        "jae .Lf67cb6_00067f77\n"
        "movss -0x20(%ebp), %xmm2\n" /* line 290 */
        "mulss %xmm4, %xmm2\n"
        "addss -0x24(%ebp), %xmm2\n"
        "movss -0x1c(%ebp), %xmm1\n"
        ".Lf67cb6_000681b0:\n"
        "mulss 0x10(%eax), %xmm1\n" /* line 891 */
        "addss 0xc(%eax), %xmm1\n"
        "subss %xmm1, %xmm2\n"
        "andps 0x2f0630, %xmm2\n"
        "movl -0x48(%ebp), %edx\n"
        "ucomiss 0x90(%edx), %xmm2\n"
        "ja .Lf67cb6_00067f77\n"
        "movl -0x4c(%ebp), %edx\n" /* line 894 */
        "movss %xmm4, (%edx)\n"
        "movl 4(%eax), %ecx\n" /* line 896 | y */
        "movl -0x4c(%ebp), %edx\n" /* v */
        "addl $4, %edx\n" /* v */
        /* { scope 4 */
        "movss (%eax), %xmm0\n" /* line 191 */
        "movl -0x4c(%ebp), %eax\n"
        "movss %xmm0, 4(%eax)\n"
        "movl %ecx, 4(%edx)\n" /* line 192 */
        "movl $0, 8(%edx)\n" /* line 193 */
        "jmp .Lf67cb6_00067f77\n"
        ".Lf67cb6_00068200:\n"
        "movl -0x44(%ebp), %edx\n" /* partition */
        "jmp .Lf67cb6_00067d48\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf67cb6_00068208:\n"
        "xorl %edi, %edi\n" /* line 936 | childIndex */
        "xorl %esi, %esi\n" /* triIndex */
        "movl -0x44(%ebp), %eax\n" /* partition */
        "jmp .Lf67cb6_00068227\n"
        ".Lf67cb6_00068211:\n"
        "addl $1, %edi\n" /* childIndex */
        "addl $0x48, %esi\n" /* triIndex */
        "movl -0x44(%ebp), %edx\n" /* partition */
        "movzbl (%edx), %eax\n"
        "cmpl %edi, %eax\n" /* childIndex */
        "jle .Lf67cb6_00067f3b\n"
        "movl %edx, %eax\n"
        ".Lf67cb6_00068227:\n"
        "movl %esi, %ebx\n" /* line 940 | triIndex, triangle */
        "addl 4(%eax), %ebx\n" /* triangle */
        "movl -0x4c(%ebp), %ecx\n" /* line 941 */
        "movl -0x48(%ebp), %edx\n"
        "movss 0x90(%edx), %xmm0\n"
        "movl %ebx, %edx\n" /* triangle */
        "movl -0x48(%ebp), %eax\n"
        "calll CM_TraceCapsuleThroughTriangle\n"
        "pxor %xmm0, %xmm0\n" /* line 942 */
        "ucomiss 8(%ebx), %xmm0\n" /* triangle */
        "jbe .Lf67cb6_00068211\n"
        "movl -0x48(%ebp), %eax\n" /* line 943 */
        "movss 0x90(%eax), %xmm0\n"
        "xorps 0x2f0620, %xmm0\n"
        "movl -0x4c(%ebp), %ecx\n"
        "movl %ebx, %edx\n" /* triangle */
        "calll CM_TraceCapsuleThroughTriangle\n"
        "jmp .Lf67cb6_00068211\n"
        /* { scope 2: radius */
        /* { scope 3 */
        ".Lf67cb6_0006826c:\n"
        "pxor %xmm3, %xmm3\n" /* line 883 */
        "maxss %xmm4, %xmm3\n"
        "movaps %xmm3, %xmm4\n"
        "jmp .Lf67cb6_000681b0\n"
        ".Lf67cb6_0006827c:\n"
        "movss -0x34(%ebp), %xmm0\n" /* line 65 */
        "mulss %xmm5, %xmm0\n"
        "movss -0x38(%ebp), %xmm1\n"
        "mulss %xmm7, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss -0x2c(%ebp), %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "mulss %xmm5, %xmm7\n" /* line 66 */
        "movss -0x38(%ebp), %xmm0\n" /* scale */
        "mulss -0x34(%ebp), %xmm0\n" /* scale */
        "subss %xmm0, %xmm7\n" /* scale */
        "movss -0x28(%ebp), %xmm0\n" /* scale */
        "subss %xmm7, %xmm0\n" /* scale */
        "movaps %xmm6, %xmm1\n" /* line 114 */
        "mulss %xmm2, %xmm1\n"
        "mulss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "pxor %xmm3, %xmm3\n" /* line 816 */
        "ucomiss %xmm3, %xmm1\n"
        "jae .Lf67cb6_00067f77\n"
        "mulss %xmm2, %xmm2\n" /* line 114 */
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 820 | radius */
        "mulss %xmm0, %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* radius */
        "movaps %xmm2, %xmm0\n"
        "subss -0x30(%ebp), %xmm0\n" /* radius */
        "ucomiss %xmm0, %xmm3\n" /* line 821 */
        "ja .Lf67cb6_000683e9\n"
        "movl -0x48(%ebp), %edx\n" /* line 836 */
        "movss 0x34(%edx), %xmm3\n"
        "movaps %xmm1, %xmm2\n"
        "mulss %xmm1, %xmm2\n"
        "mulss %xmm3, %xmm0\n"
        "subss %xmm0, %xmm2\n"
        "pxor %xmm0, %xmm0\n" /* line 837 */
        "ucomiss %xmm2, %xmm0\n"
        "ja .Lf67cb6_00067f77\n"
        "movaps %xmm1, %xmm4\n" /* line 841 */
        "xorps 0x2f0620, %xmm4\n"
        "sqrtss %xmm2, %xmm0\n" /* line 81 */
        "subss %xmm0, %xmm4\n"
        "divss %xmm3, %xmm4\n"
        "ucomiss -0x3c(%ebp), %xmm4\n" /* line 842 */
        "jae .Lf67cb6_00067f77\n"
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm4, %xmm2\n"
        "jae .Lf67cb6_00067f77\n"
        "movss -0x20(%ebp), %xmm2\n" /* line 290 */
        "mulss %xmm4, %xmm2\n"
        "addss -0x24(%ebp), %xmm2\n"
        "pxor %xmm1, %xmm1\n"
        "jmp .Lf67cb6_000681b0\n"
        ".Lf67cb6_00068365:\n"
        "movss -0x1c(%ebp), %xmm3\n" /* line 863 */
        "mulss 0x10(%eax), %xmm3\n"
        "movss %xmm3, -0x1c(%ebp)\n"
        "addss 0xc(%eax), %xmm3\n"
        "movss -0x24(%ebp), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        "andl $0x7fffffff, -0x24(%ebp)\n"
        "movss -0x24(%ebp), %xmm0\n"
        "movl -0x48(%ebp), %eax\n"
        "ucomiss 0x90(%eax), %xmm0\n"
        "ja .Lf67cb6_00067f77\n"
        ".Lf67cb6_000683a3:\n"
        "movl -0x4c(%ebp), %eax\n" /* line 866 | v */
        "addl $4, %eax\n" /* v */
        /* { scope 4 */
        "movss -0x38(%ebp), %xmm0\n" /* line 191 */
        "movl -0x4c(%ebp), %edx\n"
        "movss %xmm0, 4(%edx)\n"
        "movss %xmm5, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "movl $0, (%edx)\n" /* line 867 */
        "movl -0x48(%ebp), %eax\n" /* line 868 */
        "movss 0x8c(%eax), %xmm0\n"
        "mulss %xmm0, %xmm0\n"
        "ucomiss %xmm2, %xmm0\n"
        "jbe .Lf67cb6_00067f77\n"
        "movb $1, 0x23(%edx)\n" /* line 869 */
        "jmp .Lf67cb6_00067f77\n"
        ".Lf67cb6_000683e9:\n"
        "movss 0xc(%eax), %xmm0\n" /* line 826 */
        "subss 8(%edx), %xmm0\n"
        "andps 0x2f0630, %xmm0\n"
        "ucomiss 0x90(%edx), %xmm0\n"
        "ja .Lf67cb6_00067f77\n"
        "jmp .Lf67cb6_000683a3\n"
    );
}

/* line 1000 */
__attribute__((naked))
short int CM_TraceThroughAabbTree(const traceWork_t *tw, CollisionAabbTree *aabbTree, trace_t *trace)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1000 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* tw */
        "movl 0xc(%ebp), %esi\n" /* aabbTree */
        /* { scope 1 */
        "movzwl 0x18(%esi), %eax\n" /* line 1005 | aabbTree */
        "leal (%eax, %eax, 8), %eax\n"
        "movl 0x195eda4, %edx\n"
        "movl 0x10(%edx), %edx\n"
        "leal (%edx, %eax, 8), %ebx\n" /* materialInfo */
        "movl 0x80(%edi), %eax\n" /* line 1006 | tw */
        "testl %eax, 0x44(%ebx)\n" /* materialInfo */
        "jne .Lf6840a_0006843f\n"
        /* } scope */
        ".Lf6840a_00068437:\n"
        "addl $0x1c, %esp\n" /* line 1017 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf6840a_0006843f:\n"
        "movl 0x10(%ebp), %eax\n" /* line 1009 | trace */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n" /* oldFraction */
        "movl %eax, %ecx\n" /* line 1010 */
        "movl %esi, %edx\n" /* aabbTree */
        "movl %edi, %eax\n" /* tw */
        "calll CM_TraceThroughAabbTree_r\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 1011 | oldFraction */
        "movl 0x10(%ebp), %eax\n" /* trace */
        "ucomiss (%eax), %xmm0\n"
        "jbe .Lf6840a_00068437\n"
        "movl %eax, %edx\n"
        "movl 0x40(%ebx), %eax\n" /* line 1013 | materialInfo */
        "movl %eax, 0x10(%edx)\n"
        "movl 0x44(%ebx), %eax\n" /* line 1014 | materialInfo */
        "movl %eax, 0x14(%edx)\n"
        "movl %ebx, 0x18(%edx)\n" /* line 1015 | materialInfo */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1017 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1020 */
__attribute__((naked))
short int CM_SightTraceThroughAabbTree(const traceWork_t *tw, CollisionAabbTree *aabbTree, trace_t *trace)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1020 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* tw */
        "movl 0xc(%ebp), %esi\n" /* aabbTree */
        "movzwl 0x18(%esi), %eax\n" /* line 1022 | aabbTree */
        "leal (%eax, %eax, 8), %eax\n"
        "movl 0x195eda4, %edx\n"
        "movl 0x10(%edx), %edx\n"
        "leal (%edx, %eax, 8), %ebx\n"
        "movl 0x80(%edi), %eax\n" /* tw */
        "testl %eax, 0x44(%ebx)\n"
        "jne .Lf6847c_000684b1\n"
        ".Lf6847c_000684a9:\n"
        "addl $0x1c, %esp\n" /* line 1026 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf6847c_000684b1:\n"
        "movl 0x10(%ebp), %eax\n" /* line 1009 | trace */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n" /* oldFraction */
        "movl %eax, %ecx\n" /* line 1010 */
        "movl %esi, %edx\n"
        "movl %edi, %eax\n"
        "calll CM_TraceThroughAabbTree_r\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 1011 | oldFraction */
        "movl 0x10(%ebp), %eax\n" /* trace */
        "ucomiss (%eax), %xmm0\n"
        "jbe .Lf6847c_000684a9\n"
        "movl %eax, %edx\n"
        "movl 0x40(%ebx), %eax\n" /* line 1013 */
        "movl %eax, 0x10(%edx)\n"
        "movl 0x44(%ebx), %eax\n" /* line 1014 */
        "movl %eax, 0x14(%edx)\n"
        "movl %ebx, 0x18(%edx)\n" /* line 1015 */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1026 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 966 */
static __attribute__((naked))
short int CM_PositionTestInAabbTree_r(const traceWork_t *tw, CollisionAabbTree *aabbTree, trace_t *trace)
{
    __asm__ __volatile__ (
        ".Lf684ee_000684ee:\n"
        "pushl %ebp\n" /* line 966 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl %eax, -0x68(%ebp)\n"
        "movl %edx, -0x6c(%ebp)\n"
        "movl %ecx, -0x70(%ebp)\n"
        /* { scope 1: childIndex */
        "movl %edx, %ecx\n" /* line 975 */
        "addl $0xc, %ecx\n"
        "calll CM_CullBox\n"
        "testb %al, %al\n"
        "jne .Lf684ee_00068559\n"
        "movl -0x6c(%ebp), %edx\n" /* line 978 */
        "movzwl 0x1a(%edx), %eax\n"
        "testw %ax, %ax\n"
        "jne .Lf684ee_00068561\n"
        "movl -0x68(%ebp), %ecx\n" /* line 987 */
        "movl 0xa0(%ecx), %esi\n" /* aabbTree */
        "movl 0x1c(%edx), %ecx\n" /* line 988 */
        "leal (%ecx, %ecx), %edi\n" /* aabbTree */
        "movl %edi, %ebx\n" /* aabbTree, partition */
        "movl -0x68(%ebp), %edx\n"
        "addl 0xac(%edx), %ebx\n" /* partition */
        "movzwl (%ebx), %edx\n" /* partition */
        "movswl %si, %eax\n" /* aabbTree */
        "cmpl %eax, %edx\n"
        "je .Lf684ee_00068559\n"
        "movw %si, (%ebx)\n" /* line 990 | aabbTree, partition */
        "leal (%edi, %ecx), %eax\n" /* line 992 | aabbTree */
        "movl 0x195eda4, %edx\n"
        "movl 0x68(%edx), %edx\n"
        "leal (%edx, %eax, 4), %ebx\n" /* partition */
        "cmpb $0, (%ebx)\n" /* line 993 | partition */
        "jne .Lf684ee_0006864b\n"
        /* } scope */
        ".Lf684ee_00068559:\n"
        "addl $0x7c, %esp\n" /* line 997 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf684ee_00068561:\n"
        "movl %edx, %ecx\n"
        /* { scope 1: childIndex */
        "movl 0x195eda4, %edx\n" /* line 980 */
        "movl 0x1c(%ecx), %ecx\n"
        "shll $5, %ecx\n"
        "movl %ecx, -0x60(%ebp)\n" /* child */
        "movl 0x70(%edx), %ecx\n"
        "addl %ecx, -0x60(%ebp)\n" /* child */
        "testw %ax, %ax\n"
        "je .Lf684ee_00068559\n"
        "movl $0, -0x64(%ebp)\n" /* childIndex */
        "movl %edx, -0x74(%ebp)\n"
        "movl %edx, -0x84(%ebp)\n"
        "movl %edx, -0x88(%ebp)\n"
        "jmp .Lf684ee_000685c3\n"
        /* { scope 2: aabbTree */
        ".Lf684ee_00068595:\n"
        "movl 0x1c(%edx), %ecx\n"
        "shll $5, %ecx\n"
        "movl -0x74(%ebp), %edx\n"
        "movl 0x70(%edx), %edx\n"
        "addl %edx, %ecx\n"
        "movl %ecx, -0x58(%ebp)\n" /* aabbTree */
        "testw %ax, %ax\n"
        "jne .Lf684ee_00068674\n"
        /* } scope */
        ".Lf684ee_000685af:\n"
        "addl $1, -0x64(%ebp)\n" /* childIndex */
        "addl $0x20, -0x60(%ebp)\n" /* child */
        "movl -0x6c(%ebp), %edx\n"
        "movzwl 0x1a(%edx), %eax\n"
        "cmpl %eax, -0x64(%ebp)\n" /* childIndex */
        "jge .Lf684ee_00068559\n"
        /* { scope 2: aabbTree */
        ".Lf684ee_000685c3:\n"
        "movl -0x60(%ebp), %ecx\n" /* line 975 | child */
        "addl $0xc, %ecx\n"
        "movl -0x60(%ebp), %edx\n" /* child */
        "movl -0x68(%ebp), %eax\n"
        "calll CM_CullBox\n"
        "testb %al, %al\n"
        "jne .Lf684ee_000685af\n"
        "movl -0x60(%ebp), %eax\n" /* line 966 | child */
        "addl $0x1a, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x60(%ebp), %edx\n" /* line 978 | child */
        "movzwl 0x1a(%edx), %eax\n"
        "testw %ax, %ax\n"
        "jne .Lf684ee_00068595\n"
        "movl -0x68(%ebp), %ecx\n" /* line 987 */
        "movl 0xa0(%ecx), %edi\n" /* aabbTree */
        "movl 0x1c(%edx), %esi\n" /* line 988 | aabbTree */
        "leal (%esi, %esi), %ebx\n" /* aabbTree, partition */
        "movl %ebx, %ecx\n" /* partition */
        "movl -0x68(%ebp), %edx\n"
        "addl 0xac(%edx), %ecx\n"
        "movzwl (%ecx), %edx\n"
        "movswl %di, %eax\n" /* aabbTree */
        "cmpl %eax, %edx\n"
        "je .Lf684ee_000685af\n"
        "movw %di, (%ecx)\n" /* line 990 | aabbTree */
        "leal (%ebx, %esi), %edx\n" /* line 992 | partition */
        "movl -0x74(%ebp), %ecx\n"
        "movl 0x68(%ecx), %eax\n"
        "leal (%eax, %edx, 4), %ebx\n" /* partition */
        "cmpb $0, (%ebx)\n" /* line 993 | partition */
        "je .Lf684ee_000685af\n"
        "xorl %edi, %edi\n" /* aabbTree */
        "xorl %esi, %esi\n" /* aabbTree */
        ".Lf684ee_00068629:\n"
        "movl %esi, %edx\n" /* line 994 | aabbTree */
        "addl 4(%ebx), %edx\n" /* partition */
        "movl -0x70(%ebp), %ecx\n"
        "movl -0x68(%ebp), %eax\n"
        "calll CM_PositionTestCapsuleInTriangle\n"
        "addl $1, %edi\n" /* line 993 | aabbTree */
        "addl $0x48, %esi\n" /* aabbTree */
        "movzbl (%ebx), %eax\n" /* partition */
        "cmpl %eax, %edi\n" /* aabbTree */
        "jl .Lf684ee_00068629\n"
        "jmp .Lf684ee_000685af\n"
        /* } scope */
        ".Lf684ee_0006864b:\n"
        "xorl %edi, %edi\n" /* aabbTree */
        "xorl %esi, %esi\n" /* aabbTree */
        ".Lf684ee_0006864f:\n"
        "movl %esi, %edx\n" /* line 994 | aabbTree */
        "addl 4(%ebx), %edx\n" /* partition */
        "movl -0x70(%ebp), %ecx\n"
        "movl -0x68(%ebp), %eax\n"
        "calll CM_PositionTestCapsuleInTriangle\n"
        "addl $1, %edi\n" /* line 993 | aabbTree */
        "addl $0x48, %esi\n" /* aabbTree */
        "movzbl (%ebx), %eax\n" /* partition */
        "cmpl %edi, %eax\n" /* aabbTree */
        "jg .Lf684ee_0006864f\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 997 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: childIndex */
        /* { scope 2: aabbTree */
        ".Lf684ee_00068674:\n"
        "movl $0, -0x5c(%ebp)\n" /* line 980 | childIndex */
        "jmp .Lf684ee_000686ac\n"
        /* { scope 3: childIndex */
        /* { scope 4 */
        ".Lf684ee_0006867d:\n"
        "movl 0x1c(%edx), %edi\n" /* triIndex */
        "shll $5, %edi\n" /* triIndex */
        "movl -0x84(%ebp), %ecx\n"
        "addl 0x70(%ecx), %edi\n" /* triIndex */
        "testw %ax, %ax\n"
        "jne .Lf684ee_00068737\n"
        /* } scope */
        /* } scope */
        ".Lf684ee_00068695:\n"
        "addl $1, -0x5c(%ebp)\n" /* childIndex */
        "addl $0x20, -0x58(%ebp)\n" /* aabbTree */
        "movl -0x1c(%ebp), %edx\n"
        "movzwl (%edx), %eax\n"
        "cmpl %eax, -0x5c(%ebp)\n" /* childIndex */
        "jge .Lf684ee_000685af\n"
        /* { scope 3: childIndex */
        /* { scope 4 */
        ".Lf684ee_000686ac:\n"
        "movl -0x58(%ebp), %ecx\n" /* line 975 | aabbTree */
        "addl $0xc, %ecx\n"
        "movl -0x58(%ebp), %edx\n" /* aabbTree */
        "movl -0x68(%ebp), %eax\n"
        "calll CM_CullBox\n"
        "testb %al, %al\n"
        "jne .Lf684ee_00068695\n"
        "movl -0x58(%ebp), %ecx\n" /* line 966 | aabbTree */
        "addl $0x1a, %ecx\n"
        "movl %ecx, -0x20(%ebp)\n"
        "movl -0x58(%ebp), %edx\n" /* line 978 | aabbTree */
        "movzwl 0x1a(%edx), %eax\n"
        "testw %ax, %ax\n"
        "jne .Lf684ee_0006867d\n"
        "movl -0x68(%ebp), %ecx\n" /* line 987 */
        "movl 0xa0(%ecx), %edi\n" /* aabbTree */
        "movl 0x1c(%edx), %esi\n" /* line 988 | aabbTree */
        "leal (%esi, %esi), %ebx\n" /* aabbTree, partition */
        "movl %ebx, %ecx\n" /* partition */
        "movl -0x68(%ebp), %edx\n"
        "addl 0xac(%edx), %ecx\n"
        "movzwl (%ecx), %edx\n"
        "movswl %di, %eax\n" /* aabbTree */
        "cmpl %eax, %edx\n"
        "je .Lf684ee_00068695\n"
        "movw %di, (%ecx)\n" /* line 990 | aabbTree */
        "leal (%ebx, %esi), %edx\n" /* line 992 | partition */
        "movl -0x84(%ebp), %ecx\n"
        "movl 0x68(%ecx), %eax\n"
        "leal (%eax, %edx, 4), %ebx\n" /* partition */
        "cmpb $0, (%ebx)\n" /* line 993 | partition */
        "je .Lf684ee_00068695\n"
        "xorl %edi, %edi\n" /* aabbTree */
        "xorl %esi, %esi\n" /* aabbTree */
        ".Lf684ee_00068715:\n"
        "movl %esi, %edx\n" /* line 994 | aabbTree */
        "addl 4(%ebx), %edx\n" /* partition */
        "movl -0x70(%ebp), %ecx\n"
        "movl -0x68(%ebp), %eax\n"
        "calll CM_PositionTestCapsuleInTriangle\n"
        "addl $1, %edi\n" /* line 993 | aabbTree */
        "addl $0x48, %esi\n" /* aabbTree */
        "movzbl (%ebx), %eax\n" /* partition */
        "cmpl %eax, %edi\n" /* aabbTree */
        "jl .Lf684ee_00068715\n"
        "jmp .Lf684ee_00068695\n"
        ".Lf684ee_00068737:\n"
        "movl $0, -0x54(%ebp)\n" /* line 980 | childIndex */
        "jmp .Lf684ee_00068773\n"
        /* { scope 5: childIndex, triIndex */
        /* { scope 6: aabbTree */
        ".Lf684ee_00068740:\n"
        "movl 0x1c(%edi), %edx\n" /* triIndex */
        "shll $5, %edx\n"
        "movl -0x88(%ebp), %ecx\n"
        "movl 0x70(%ecx), %ecx\n"
        "addl %ecx, %edx\n"
        "movl %edx, -0x48(%ebp)\n" /* aabbTree */
        "testw %ax, %ax\n"
        "jne .Lf684ee_00068802\n"
        /* } scope */
        /* } scope */
        ".Lf684ee_0006875d:\n"
        "addl $1, -0x54(%ebp)\n" /* childIndex */
        "addl $0x20, %edi\n" /* triIndex */
        "movl -0x20(%ebp), %edx\n"
        "movzwl (%edx), %eax\n"
        "cmpl %eax, -0x54(%ebp)\n" /* childIndex */
        "jge .Lf684ee_00068695\n"
        /* { scope 5: childIndex, triIndex */
        /* { scope 6: aabbTree */
        ".Lf684ee_00068773:\n"
        "leal 0xc(%edi), %ecx\n" /* line 975 | triIndex */
        "movl %edi, %edx\n" /* triIndex */
        "movl -0x68(%ebp), %eax\n"
        "calll CM_CullBox\n"
        "testb %al, %al\n"
        "jne .Lf684ee_0006875d\n"
        "leal 0x1a(%edi), %eax\n" /* line 966 */
        "movl %eax, -0x24(%ebp)\n"
        "movzwl 0x1a(%edi), %eax\n" /* line 978 | triIndex */
        "testw %ax, %ax\n"
        "jne .Lf684ee_00068740\n"
        "movl -0x68(%ebp), %ecx\n" /* line 987 */
        "movl 0xa0(%ecx), %ecx\n"
        "movl %ecx, -0x80(%ebp)\n"
        "movl 0x1c(%edi), %esi\n" /* line 988 | aabbTree */
        "leal (%esi, %esi), %ebx\n" /* aabbTree, partition */
        "movl %ebx, %ecx\n" /* partition */
        "movl -0x68(%ebp), %eax\n"
        "addl 0xac(%eax), %ecx\n"
        "movzwl (%ecx), %edx\n"
        "movswl -0x80(%ebp), %eax\n"
        "cmpl %eax, %edx\n"
        "je .Lf684ee_0006875d\n"
        "movl -0x80(%ebp), %edx\n" /* line 990 */
        "movw %dx, (%ecx)\n"
        "leal (%ebx, %esi), %edx\n" /* line 992 | partition */
        "movl -0x88(%ebp), %ecx\n"
        "movl 0x68(%ecx), %eax\n"
        "leal (%eax, %edx, 4), %ebx\n" /* partition */
        "cmpb $0, (%ebx)\n" /* line 993 | partition */
        "je .Lf684ee_0006875d\n"
        "movl $0, -0x4c(%ebp)\n" /* triIndex */
        "xorl %esi, %esi\n" /* aabbTree */
        ".Lf684ee_000687de:\n"
        "movl %esi, %edx\n" /* line 994 | aabbTree */
        "addl 4(%ebx), %edx\n" /* partition */
        "movl -0x70(%ebp), %ecx\n"
        "movl -0x68(%ebp), %eax\n"
        "calll CM_PositionTestCapsuleInTriangle\n"
        "addl $1, -0x4c(%ebp)\n" /* line 993 | triIndex */
        "addl $0x48, %esi\n" /* aabbTree */
        "movzbl (%ebx), %eax\n" /* partition */
        "cmpl -0x4c(%ebp), %eax\n" /* triIndex */
        "jg .Lf684ee_000687de\n"
        "jmp .Lf684ee_0006875d\n"
        ".Lf684ee_00068802:\n"
        "movl $0, -0x50(%ebp)\n" /* line 980 | childIndex */
        "jmp .Lf684ee_0006883a\n"
        /* { scope 7: childIndex, triIndex */
        /* { scope 8 */
        ".Lf684ee_0006880b:\n"
        "movl 0x1c(%edx), %esi\n"
        "shll $5, %esi\n"
        "movl 0x195eda4, %ecx\n"
        "addl 0x70(%ecx), %esi\n"
        "testw %ax, %ax\n"
        "jne .Lf684ee_000688d7\n"
        /* } scope */
        /* } scope */
        ".Lf684ee_00068823:\n"
        "addl $1, -0x50(%ebp)\n" /* childIndex */
        "addl $0x20, -0x48(%ebp)\n" /* aabbTree */
        "movl -0x24(%ebp), %edx\n"
        "movzwl (%edx), %eax\n"
        "cmpl %eax, -0x50(%ebp)\n" /* childIndex */
        "jge .Lf684ee_0006875d\n"
        /* { scope 7: childIndex, triIndex */
        /* { scope 8 */
        ".Lf684ee_0006883a:\n"
        "movl -0x48(%ebp), %ecx\n" /* line 975 | aabbTree */
        "addl $0xc, %ecx\n"
        "movl -0x48(%ebp), %edx\n" /* aabbTree */
        "movl -0x68(%ebp), %eax\n"
        "calll CM_CullBox\n"
        "testb %al, %al\n"
        "jne .Lf684ee_00068823\n"
        "movl -0x48(%ebp), %eax\n" /* line 966 | aabbTree */
        "addl $0x1a, %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl -0x48(%ebp), %edx\n" /* line 978 | aabbTree */
        "movzwl 0x1a(%edx), %eax\n"
        "testw %ax, %ax\n"
        "jne .Lf684ee_0006880b\n"
        "movl -0x68(%ebp), %ecx\n" /* line 987 */
        "movl 0xa0(%ecx), %ecx\n"
        "movl %ecx, -0x7c(%ebp)\n"
        "movl 0x1c(%edx), %esi\n" /* line 988 | aabbTree */
        "leal (%esi, %esi), %ebx\n" /* aabbTree, partition */
        "movl %ebx, %ecx\n" /* partition */
        "movl -0x68(%ebp), %edx\n"
        "addl 0xac(%edx), %ecx\n"
        "movzwl (%ecx), %edx\n"
        "movswl -0x7c(%ebp), %eax\n"
        "cmpl %eax, %edx\n"
        "je .Lf684ee_00068823\n"
        "movl -0x7c(%ebp), %eax\n" /* line 990 */
        "movw %ax, (%ecx)\n"
        "leal (%ebx, %esi), %edx\n" /* line 992 | partition */
        "movl 0x195eda4, %ecx\n"
        "movl 0x68(%ecx), %eax\n"
        "leal (%eax, %edx, 4), %ebx\n" /* partition */
        "cmpb $0, (%ebx)\n" /* line 993 | partition */
        "je .Lf684ee_00068823\n"
        "movl $0, -0x40(%ebp)\n" /* triIndex */
        "xorl %esi, %esi\n" /* aabbTree */
        ".Lf684ee_000688b3:\n"
        "movl %esi, %edx\n" /* line 994 | aabbTree */
        "addl 4(%ebx), %edx\n" /* partition */
        "movl -0x70(%ebp), %ecx\n"
        "movl -0x68(%ebp), %eax\n"
        "calll CM_PositionTestCapsuleInTriangle\n"
        "addl $1, -0x40(%ebp)\n" /* line 993 | triIndex */
        "addl $0x48, %esi\n" /* aabbTree */
        "movzbl (%ebx), %eax\n" /* partition */
        "cmpl %eax, -0x40(%ebp)\n" /* triIndex */
        "jl .Lf684ee_000688b3\n"
        "jmp .Lf684ee_00068823\n"
        ".Lf684ee_000688d7:\n"
        "movl $0, -0x44(%ebp)\n" /* line 980 | childIndex */
        "jmp .Lf684ee_0006890e\n"
        /* { scope 9: childIndex, triIndex */
        /* { scope 10 */
        ".Lf684ee_000688e0:\n"
        "movl 0x1c(%esi), %ebx\n" /* partition */
        "shll $5, %ebx\n" /* partition */
        "movl 0x195eda4, %edx\n"
        "addl 0x70(%edx), %ebx\n" /* partition */
        "testw %ax, %ax\n"
        "jne .Lf684ee_000689ab\n"
        /* } scope */
        /* } scope */
        ".Lf684ee_000688f8:\n"
        "addl $1, -0x44(%ebp)\n" /* childIndex */
        "addl $0x20, %esi\n"
        "movl -0x28(%ebp), %edx\n"
        "movzwl (%edx), %eax\n"
        "cmpl %eax, -0x44(%ebp)\n" /* childIndex */
        "jge .Lf684ee_00068823\n"
        /* { scope 9: childIndex, triIndex */
        /* { scope 10 */
        ".Lf684ee_0006890e:\n"
        "leal 0xc(%esi), %ecx\n" /* line 975 */
        "movl %esi, %edx\n"
        "movl -0x68(%ebp), %eax\n"
        "calll CM_CullBox\n"
        "testb %al, %al\n"
        "jne .Lf684ee_000688f8\n"
        "leal 0x1a(%esi), %eax\n" /* line 966 */
        "movl %eax, -0x2c(%ebp)\n"
        "movzwl 0x1a(%esi), %eax\n" /* line 978 */
        "testw %ax, %ax\n"
        "jne .Lf684ee_000688e0\n"
        "movl -0x68(%ebp), %eax\n" /* line 987 */
        "movl 0xa0(%eax), %eax\n"
        "movl %eax, -0x78(%ebp)\n"
        "movl 0x1c(%esi), %edx\n" /* line 988 | aabbTree */
        "movl %edx, -0x3c(%ebp)\n"
        "movl %edx, %ebx\n" /* partition */
        "addl %ebx, %ebx\n" /* partition */
        "movl %ebx, %ecx\n" /* partition */
        "movl -0x68(%ebp), %eax\n"
        "addl 0xac(%eax), %ecx\n"
        "movzwl (%ecx), %edx\n"
        "movswl -0x78(%ebp), %eax\n"
        "cmpl %eax, %edx\n"
        "je .Lf684ee_000688f8\n"
        "movl -0x78(%ebp), %edx\n" /* line 990 */
        "movw %dx, (%ecx)\n"
        "movl -0x3c(%ebp), %ecx\n" /* line 992 */
        "leal (%ebx, %ecx), %edx\n" /* partition */
        "movl 0x195eda4, %ecx\n"
        "movl 0x68(%ecx), %eax\n"
        "leal (%eax, %edx, 4), %ebx\n" /* partition */
        "cmpb $0, (%ebx)\n" /* line 993 | partition */
        "je .Lf684ee_000688f8\n"
        "movl $0, -0x34(%ebp)\n" /* triIndex */
        "movl $0, -0x30(%ebp)\n"
        ".Lf684ee_00068985:\n"
        "movl -0x30(%ebp), %edx\n" /* line 994 */
        "addl 4(%ebx), %edx\n" /* partition */
        "movl -0x70(%ebp), %ecx\n"
        "movl -0x68(%ebp), %eax\n"
        "calll CM_PositionTestCapsuleInTriangle\n"
        "addl $1, -0x34(%ebp)\n" /* line 993 | triIndex */
        "addl $0x48, -0x30(%ebp)\n"
        "movzbl (%ebx), %eax\n" /* partition */
        "cmpl %eax, -0x34(%ebp)\n" /* triIndex */
        "jl .Lf684ee_00068985\n"
        "jmp .Lf684ee_000688f8\n"
        ".Lf684ee_000689ab:\n"
        "movl $0, -0x38(%ebp)\n" /* line 980 | childIndex */
        ".Lf684ee_000689b2:\n"
        "movl -0x70(%ebp), %ecx\n" /* line 981 */
        "movl %ebx, %edx\n" /* partition */
        "movl -0x68(%ebp), %eax\n"
        "calll CM_PositionTestInAabbTree_r\n"
        "addl $1, -0x38(%ebp)\n" /* line 980 | childIndex */
        "addl $0x20, %ebx\n" /* partition */
        "movl -0x2c(%ebp), %ecx\n"
        "movzwl (%ecx), %eax\n"
        "cmpl %eax, -0x38(%ebp)\n" /* childIndex */
        "jl .Lf684ee_000689b2\n"
        "jmp .Lf684ee_000688f8\n"
    );
}

/* line 1029 */
__attribute__((naked))
short int CM_MeshTestInLeaf(const traceWork_t *tw, cLeaf_t *leaf, trace_t *trace)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1029 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1: childIndex, triIndex */
        "movl 0xc(%ebp), %eax\n" /* line 1038 | leaf */
        "movzwl 2(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lf689d6_00068aaf\n"
        "movl $0, -0x24(%ebp)\n" /* k */
        "jmp .Lf689d6_00068a04\n"
        ".Lf689d6_000689f7:\n"
        "addl $1, -0x24(%ebp)\n" /* k */
        "cmpl %ecx, -0x24(%ebp)\n" /* k */
        "jge .Lf689d6_00068aaf\n"
        ".Lf689d6_00068a04:\n"
        "movl 0x195eda4, %edx\n" /* line 1040 */
        "movl 0x70(%edx), %esi\n" /* child */
        "movl 0xc(%ebp), %edi\n" /* leaf, materialInfo */
        "movzwl (%edi), %eax\n" /* materialInfo */
        "addl -0x24(%ebp), %eax\n" /* k */
        "shll $5, %eax\n"
        "leal (%esi, %eax), %ebx\n" /* child, aabbTree */
        "movzwl 0x18(%ebx), %eax\n" /* line 1041 | aabbTree */
        "leal (%eax, %eax, 8), %eax\n"
        "movl 0x10(%edx), %edx\n"
        "leal (%edx, %eax, 8), %edi\n" /* materialInfo */
        "movl 8(%ebp), %edx\n" /* line 1042 | tw */
        "movl 0x80(%edx), %eax\n"
        "testl %eax, 0x44(%edi)\n" /* materialInfo */
        "je .Lf689d6_000689f7\n"
        "movl %edx, %eax\n"
        /* { scope 2 */
        "leal 0xc(%ebx), %ecx\n" /* line 975 | partition */
        "movl %ebx, %edx\n" /* partition */
        "calll CM_CullBox\n"
        "testb %al, %al\n"
        "jne .Lf689d6_00068a92\n"
        "movzwl 0x1a(%ebx), %edx\n" /* line 978 | partition */
        "testw %dx, %dx\n"
        "jne .Lf689d6_00068ab7\n"
        "movl 8(%ebp), %ecx\n" /* line 987 | tw */
        "movl 0xa0(%ecx), %ecx\n"
        "movl %ecx, -0x28(%ebp)\n"
        "movl 0x1c(%ebx), %ecx\n" /* line 988 | partition */
        "leal (%ecx, %ecx), %esi\n" /* child */
        "movl %esi, %ebx\n" /* child, partition */
        "movl 8(%ebp), %eax\n" /* tw */
        "addl 0xac(%eax), %ebx\n" /* partition */
        "movzwl (%ebx), %edx\n" /* partition */
        "movswl -0x28(%ebp), %eax\n"
        "cmpl %eax, %edx\n"
        "je .Lf689d6_00068a92\n"
        "movl -0x28(%ebp), %edx\n" /* line 990 */
        "movw %dx, (%ebx)\n" /* partition */
        "leal (%esi, %ecx), %edx\n" /* line 992 | child */
        "movl 0x195eda4, %ecx\n"
        "movl 0x68(%ecx), %eax\n"
        "leal (%eax, %edx, 4), %ebx\n" /* partition */
        "cmpb $0, (%ebx)\n" /* line 993 | partition */
        "jne .Lf689d6_00068aea\n"
        /* } scope */
        ".Lf689d6_00068a92:\n"
        "movl 0x10(%ebp), %eax\n" /* line 1046 | trace */
        "cmpb $0, 0x22(%eax)\n"
        "jne .Lf689d6_00068b17\n"
        "movl 0xc(%ebp), %edi\n" /* leaf, materialInfo */
        "movzwl 2(%edi), %ecx\n" /* materialInfo */
        "addl $1, -0x24(%ebp)\n" /* line 1038 | k */
        "cmpl %ecx, -0x24(%ebp)\n" /* k */
        "jl .Lf689d6_00068a04\n"
        /* } scope */
        ".Lf689d6_00068aaf:\n"
        "addl $0x1c, %esp\n" /* line 1054 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: childIndex, triIndex */
        /* { scope 2 */
        ".Lf689d6_00068ab7:\n"
        "movl 0x1c(%ebx), %eax\n" /* line 980 | partition */
        "shll $5, %eax\n"
        "addl %eax, %esi\n" /* child */
        "testw %dx, %dx\n"
        "je .Lf689d6_00068a92\n"
        "movl $0, -0x20(%ebp)\n" /* childIndex */
        ".Lf689d6_00068acb:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 981 | trace */
        "movl %esi, %edx\n" /* child */
        "movl 8(%ebp), %eax\n" /* tw */
        "calll CM_PositionTestInAabbTree_r\n"
        "addl $1, -0x20(%ebp)\n" /* line 980 | childIndex */
        "addl $0x20, %esi\n" /* child */
        "movzwl 0x1a(%ebx), %eax\n" /* partition */
        "cmpl %eax, -0x20(%ebp)\n" /* childIndex */
        "jl .Lf689d6_00068acb\n"
        "jmp .Lf689d6_00068a92\n"
        ".Lf689d6_00068aea:\n"
        "movl $0, -0x1c(%ebp)\n" /* line 993 | triIndex */
        "xorl %esi, %esi\n" /* child */
        ".Lf689d6_00068af3:\n"
        "movl %esi, %edx\n" /* line 994 | child */
        "addl 4(%ebx), %edx\n" /* partition */
        "movl 0x10(%ebp), %ecx\n" /* trace */
        "movl 8(%ebp), %eax\n" /* tw */
        "calll CM_PositionTestCapsuleInTriangle\n"
        "addl $1, -0x1c(%ebp)\n" /* line 993 | triIndex */
        "addl $0x48, %esi\n" /* child */
        "movzbl (%ebx), %eax\n" /* partition */
        "cmpl -0x1c(%ebp), %eax\n" /* triIndex */
        "jg .Lf689d6_00068af3\n"
        "jmp .Lf689d6_00068a92\n"
        ".Lf689d6_00068b17:\n"
        "movl %eax, %edx\n"
        /* } scope */
        "movl 0x40(%edi), %eax\n" /* line 1049 | materialInfo */
        "movl %eax, 0x10(%edx)\n"
        "movl 0x44(%edi), %eax\n" /* line 1050 | materialInfo */
        "movl %eax, 0x14(%edx)\n"
        "movl %edi, 0x18(%edx)\n" /* line 1051 | materialInfo */
        "jmp .Lf689d6_00068aaf\n"
    );
}

