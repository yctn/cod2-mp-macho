/* ASM dump from: cm_test.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/cm_test.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

byte * CM_ClusterPVS(int cluster);
void CM_BoxLeafnums_r(leafList_t *ll, int nodenum);
int CM_BoxLeafnums(const vec_t *mins, const vec_t *maxs, int *list, int listsize, int *lastLeaf);
int CM_PointLeafnum(const vec_t *p);
static int CM_PointContentsLeafBrushNode_r(cLeafBrushNode_t *node);
int CM_PointContents(const vec_t *p, clipHandle_t model);
int CM_TransformedPointContents(const vec_t *p, clipHandle_t model, const vec_t *origin, const vec_t *angles);

/* line 288 */
__attribute__((naked))
byte * CM_ClusterPVS(int cluster)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 288 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* cluster */
        "testl %eax, %eax\n" /* line 290 */
        "js .Lf68b2c_00068b65\n"
        "movl 0x195eda4, %edx\n"
        "cmpl 0x84(%edx), %eax\n"
        "jl .Lf68b2c_00068b4c\n"
        ".Lf68b2c_00068b44:\n"
        "movl 0x8c(%edx), %eax\n" /* line 292 */
        ".Lf68b2c_00068b4a:\n"
        "popl %ebp\n" /* line 296 */
        "retl\n"
        ".Lf68b2c_00068b4c:\n"
        "movl 0x90(%edx), %ecx\n" /* line 290 */
        "testl %ecx, %ecx\n"
        "je .Lf68b2c_00068b44\n"
        "imull 0x88(%edx), %eax\n" /* line 295 */
        "addl 0x8c(%edx), %eax\n"
        "popl %ebp\n" /* line 296 */
        "retl\n"
        ".Lf68b2c_00068b65:\n"
        "movl 0x195eda4, %edx\n"
        "movl 0x8c(%edx), %eax\n" /* line 292 */
        "jmp .Lf68b2c_00068b4a\n"
    );
}

/* line 79 */
__attribute__((naked))
void CM_BoxLeafnums_r(leafList_t *ll, int nodenum)
{
    __asm__ __volatile__ (
        ".Lf68b76_00068b76:\n"
        "pushl %ebp\n" /* line 79 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* ll */
        "movl 0xc(%ebp), %edx\n" /* nodenum */
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 87 */
        "js .Lf68b76_00068bd4\n"
        "leal 0x1c(%esi), %eax\n" /* ll */
        "movl %eax, -0x1c(%ebp)\n"
        "leal 0x10(%esi), %edi\n" /* ll */
        ".Lf68b76_00068b92:\n"
        "movl 0x195eda4, %eax\n" /* line 93 */
        "movl 0x20(%eax), %eax\n"
        "leal (%eax, %edx, 8), %ebx\n" /* node */
        "movl (%ebx), %eax\n" /* line 95 | node */
        "movl %eax, 8(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll BoxOnPlaneSide\n"
        "cmpl $1, %eax\n" /* line 96 */
        "je .Lf68b76_00068c07\n"
        "cmpl $2, %eax\n" /* line 100 */
        "je .Lf68b76_00068bcc\n"
        "movswl 4(%ebx), %eax\n" /* line 107 | node */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* ll */
        "calll CM_BoxLeafnums_r\n"
        ".Lf68b76_00068bcc:\n"
        "movswl 6(%ebx), %edx\n" /* line 108 | node */
        ".Lf68b76_00068bd0:\n"
        "testl %edx, %edx\n" /* line 87 */
        "jns .Lf68b76_00068b92\n"
        /* { scope 2 */
        ".Lf68b76_00068bd4:\n"
        "movl %edx, %ecx\n" /* line 55 */
        "notl %ecx\n"
        "movl 0x195eda4, %eax\n" /* line 59 */
        "movl 0x28(%eax), %edx\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "cmpw $-1, 0x28(%edx, %eax, 4)\n"
        "je .Lf68b76_00068bf1\n"
        "movl %ecx, 0x28(%esi)\n" /* line 60 */
        ".Lf68b76_00068bf1:\n"
        "movl (%esi), %edx\n" /* line 63 */
        "cmpl 4(%esi), %edx\n"
        "jl .Lf68b76_00068c0d\n"
        "movl $1, 8(%esi)\n" /* line 65 */
        /* } scope */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 112 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf68b76_00068c07:\n"
        "movswl 4(%ebx), %edx\n" /* line 98 | node */
        "jmp .Lf68b76_00068bd0\n"
        /* { scope 2 */
        ".Lf68b76_00068c0d:\n"
        "movl 0xc(%esi), %eax\n" /* line 68 */
        "movl %ecx, (%eax, %edx, 4)\n"
        "leal 1(%edx), %eax\n"
        "movl %eax, (%esi)\n"
        /* } scope */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 112 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 121 */
__attribute__((naked))
int CM_BoxLeafnums(const vec_t *mins, const vec_t *maxs, int *list, int listsize, int *lastLeaf)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 121 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x44, %esp\n"
        "movl 8(%ebp), %edx\n" /* mins */
        "movl 0xc(%ebp), %ecx\n" /* maxs */
        /* { scope 1 */
        "movl (%edx), %eax\n" /* line 199 */
        "movl %eax, -0x24(%ebp)\n"
        "leal -0x34(%ebp), %ebx\n" /* line 200 | ll */
        "movl 4(%edx), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 199 */
        "movl %eax, -0x18(%ebp)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, -0x14(%ebp)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, -0x10(%ebp)\n"
        "movl $0, -0x34(%ebp)\n" /* line 127 | ll */
        "movl 0x14(%ebp), %eax\n" /* line 128 | listsize */
        "movl %eax, -0x30(%ebp)\n"
        "movl 0x10(%ebp), %eax\n" /* line 129 | list */
        "movl %eax, -0x28(%ebp)\n"
        "movl $0, -0xc(%ebp)\n" /* line 130 */
        "movl $0, -0x2c(%ebp)\n" /* line 131 */
        "movl $0, 4(%esp)\n" /* line 133 */
        "movl %ebx, (%esp)\n"
        "calll CM_BoxLeafnums_r\n"
        "movl -0xc(%ebp), %edx\n" /* line 135 */
        "movl 0x18(%ebp), %eax\n" /* lastLeaf */
        "movl %edx, (%eax)\n"
        "movl -0x34(%ebp), %eax\n" /* ll */
        /* } scope */
        "addl $0x44, %esp\n" /* line 137 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 35 */
__attribute__((naked))
int CM_PointLeafnum(const vec_t *p)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 35 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* p */
        /* { scope 1 */
        /* { scope 2 */
        "movl 0x195eda4, %eax\n" /* line 17 */
        "movl 0x20(%eax), %esi\n"
        "xorl %eax, %eax\n"
        "pxor %xmm2, %xmm2\n"
        "jmp .Lf68c94_00068cc6\n"
        ".Lf68c94_00068cac:\n"
        "movzbl %al, %eax\n" /* line 21 */
        "movss (%ebx, %eax, 4), %xmm1\n"
        "subss 0xc(%edx), %xmm1\n"
        "ucomiss %xmm1, %xmm2\n" /* line 24 */
        "ja .Lf68c94_00068d01\n"
        ".Lf68c94_00068cbe:\n"
        "movswl 4(%ecx), %eax\n" /* line 27 */
        "testl %eax, %eax\n" /* line 15 */
        "js .Lf68c94_00068d09\n"
        ".Lf68c94_00068cc6:\n"
        "leal (%esi, %eax, 8), %ecx\n" /* line 17 */
        "movl (%ecx), %edx\n" /* line 18 */
        "movzbl 0x10(%edx), %eax\n" /* line 20 */
        "cmpb $2, %al\n"
        "jbe .Lf68c94_00068cac\n"
        "movss (%edx), %xmm1\n" /* line 23 */
        "mulss (%ebx), %xmm1\n"
        "movss 4(%edx), %xmm0\n"
        "mulss 4(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "mulss 8(%ebx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "subss 0xc(%edx), %xmm1\n"
        "ucomiss %xmm1, %xmm2\n" /* line 24 */
        "jbe .Lf68c94_00068cbe\n"
        ".Lf68c94_00068d01:\n"
        "movswl 6(%ecx), %eax\n" /* line 25 */
        "testl %eax, %eax\n" /* line 15 */
        "jns .Lf68c94_00068cc6\n"
        ".Lf68c94_00068d09:\n"
        "notl %eax\n"
        /* } scope */
        /* } scope */
        "popl %ebx\n" /* line 39 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 149 */
static __attribute__((naked))
int CM_PointContentsLeafBrushNode_r(cLeafBrushNode_t *node)
{
    __asm__ __volatile__ (
        ".Lf68d10_00068d10:\n"
        "pushl %ebp\n" /* line 149 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xcc, %esp\n"
        "movl %eax, %edi\n" /* p */
        "movl %edx, -0xd4(%ebp)\n"
        "movl $0, -0xc0(%ebp)\n" /* contents */
        /* { scope 1: node */
        ".Lf68d10_00068d2e:\n"
        "movl -0xd4(%ebp), %edx\n" /* line 163 */
        "movzwl 2(%edx), %eax\n"
        "cmpw $0, %ax\n"
        "je .Lf68d10_00069681\n"
        "jg .Lf68d10_000696b0\n" /* line 165 */
        "movl -0xd4(%ebp), %ecx\n" /* line 198 */
        "addl $0x14, %ecx\n"
        "movl %ecx, -0xbc(%ebp)\n" /* node */
        "movl $0, -0xa8(%ebp)\n" /* contents */
        /* { scope 2: k, contents */
        /* { scope 3: node */
        ".Lf68d10_00068d61:\n"
        "movl -0xbc(%ebp), %edx\n" /* line 163 | node */
        "movzwl 2(%edx), %eax\n"
        "cmpw $0, %ax\n"
        "je .Lf68d10_00069624\n"
        "jg .Lf68d10_000694ea\n" /* line 165 */
        "movl -0xbc(%ebp), %eax\n" /* line 198 | node */
        "addl $0x14, %eax\n"
        "movl %eax, -0xa4(%ebp)\n" /* node */
        "movl $0, -0x90(%ebp)\n" /* contents */
        /* { scope 4: k, contents */
        /* { scope 5: node */
        ".Lf68d10_00068d94:\n"
        "movl -0xa4(%ebp), %edx\n" /* line 163 | node */
        "movzwl 2(%edx), %eax\n"
        "cmpw $0, %ax\n"
        "je .Lf68d10_000694bb\n"
        "jg .Lf68d10_0006938a\n" /* line 165 */
        "movl -0xa4(%ebp), %eax\n" /* line 198 | node */
        "addl $0x14, %eax\n"
        "movl %eax, -0x8c(%ebp)\n" /* node */
        "movl $0, -0x78(%ebp)\n" /* contents */
        /* { scope 6: k, contents */
        /* { scope 7: node */
        ".Lf68d10_00068dc4:\n"
        "movl -0x8c(%ebp), %edx\n" /* line 163 | node */
        "movzwl 2(%edx), %eax\n"
        "cmpw $0, %ax\n"
        "je .Lf68d10_0006935b\n"
        "jg .Lf68d10_000697bf\n" /* line 165 */
        "movl -0x8c(%ebp), %eax\n" /* line 198 | node */
        "addl $0x14, %eax\n"
        "movl %eax, -0x74(%ebp)\n" /* node */
        "movl $0, -0x60(%ebp)\n" /* contents */
        "movl %eax, %edx\n"
        /* { scope 8: k, contents */
        /* { scope 9: node */
        ".Lf68d10_00068df3:\n"
        "movzwl 2(%edx), %eax\n" /* line 163 */
        "cmpw $0, %ax\n"
        "je .Lf68d10_00069110\n"
        "jg .Lf68d10_00069257\n" /* line 165 */
        "movl -0x74(%ebp), %eax\n" /* line 198 | node */
        "addl $0x14, %eax\n"
        "movl %eax, -0x5c(%ebp)\n" /* node */
        "movl $0, -0x48(%ebp)\n" /* contents */
        "movl %eax, %edx\n"
        /* { scope 10: k, contents */
        /* { scope 11: node */
        ".Lf68d10_00068e19:\n"
        "movzwl 2(%edx), %eax\n" /* line 163 */
        "cmpw $0, %ax\n"
        "je .Lf68d10_00068fe3\n"
        "jg .Lf68d10_0006913a\n" /* line 165 */
        "movl -0x5c(%ebp), %eax\n" /* line 198 | node */
        "addl $0x14, %eax\n"
        "movl %eax, -0x44(%ebp)\n" /* node */
        "movl $0, -0x30(%ebp)\n" /* contents */
        "movl %eax, %edx\n"
        /* { scope 12: k, contents */
        /* { scope 13 */
        ".Lf68d10_00068e3f:\n"
        "movzwl 2(%edx), %eax\n" /* line 163 */
        "cmpw $0, %ax\n"
        "je .Lf68d10_00068fb0\n"
        "jg .Lf68d10_00069009\n" /* line 165 */
        "movl -0x44(%ebp), %ebx\n" /* line 198 | node */
        "addl $0x14, %ebx\n" /* node */
        "movl $0, -0x1c(%ebp)\n" /* contents */
        "jmp .Lf68d10_00068e8d\n"
        /* { scope 14: k, contents */
        /* { scope 15 */
        ".Lf68d10_00068e62:\n"
        "leal 0x14(%ebx), %edx\n" /* node */
        "movl %edi, %eax\n" /* p */
        "calll CM_PointContentsLeafBrushNode_r\n"
        "orl %eax, -0x1c(%ebp)\n" /* contents */
        ".Lf68d10_00068e6f:\n"
        "movzbl (%ebx), %eax\n" /* line 201 | node */
        "movss 8(%ebx), %xmm0\n" /* node */
        "ucomiss (%edi, %eax, 4), %xmm0\n" /* p */
        "sbbl %eax, %eax\n"
        "notl %eax\n"
        "andl $2, %eax\n"
        "movzwl 0x10(%ebx, %eax), %eax\n" /* node */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%ebx, %eax, 4), %ebx\n" /* node */
        ".Lf68d10_00068e8d:\n"
        "movzwl 2(%ebx), %eax\n" /* line 163 | b */
        "cmpw $0, %ax\n"
        "je .Lf68d10_00068e6f\n"
        "jle .Lf68d10_00068e62\n" /* line 165 */
        "cwtl\n" /* line 167 */
        "movl %eax, -0x2c(%ebp)\n"
        "testl %eax, %eax\n"
        "jle .Lf68d10_00068fa5\n"
        "movl 8(%ebx), %ebx\n" /* line 169 | b */
        "movl %ebx, -0x28(%ebp)\n" /* b */
        "movl 0x195eda4, %eax\n" /* line 170 */
        "movl 0x80(%eax), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl $0, -0x20(%ebp)\n" /* k */
        "movl %ebx, %edx\n" /* b */
        ".Lf68d10_00068ec2:\n"
        "movl -0x20(%ebp), %ecx\n" /* k */
        "movzwl (%edx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "shll $4, %eax\n"
        "movl -0x24(%ebp), %edx\n"
        "addl %eax, %edx\n"
        "movl %edx, %eax\n"
        "movl $1, %ecx\n"
        ".Lf68d10_00068edb:\n"
        "movss -4(%edi, %ecx, 4), %xmm1\n" /* line 174 | p */
        "movss (%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf68d10_00068f7f\n"
        "ucomiss 0x10(%eax), %xmm1\n" /* line 176 */
        "ja .Lf68d10_00068f7f\n"
        "addl $1, %ecx\n" /* line 177 */
        "addl $4, %eax\n"
        "cmpl $4, %ecx\n" /* line 172 */
        "jne .Lf68d10_00068edb\n"
        "movl 0x20(%edx), %ecx\n" /* line 180 */
        "movl 0x1c(%edx), %esi\n" /* line 181 | i */
        "testl %esi, %esi\n" /* line 185 | i */
        "je .Lf68d10_00068f93\n"
        "movl (%ecx), %eax\n" /* line 187 */
        "movss (%edi), %xmm5\n" /* line 304 | p */
        "movss 4(%edi), %xmm4\n" /* p */
        "movss 8(%edi), %xmm3\n" /* p */
        "movaps %xmm3, %xmm2\n" /* line 187 */
        "mulss 8(%eax), %xmm2\n"
        "movaps %xmm4, %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "movaps %xmm5, %xmm1\n"
        "mulss (%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "ucomiss 0xc(%eax), %xmm2\n"
        "ja .Lf68d10_00068f7f\n"
        "addl $8, %ecx\n" /* line 188 */
        "xorl %ebx, %ebx\n" /* b */
        "subl $1, %esi\n" /* i */
        ".Lf68d10_00068f4e:\n"
        "cmpl %ebx, %esi\n" /* line 185 | b, i */
        "je .Lf68d10_00068f93\n"
        "movl (%ecx), %eax\n" /* line 187 */
        "addl $1, %ebx\n" /* b */
        "addl $8, %ecx\n"
        "movaps %xmm3, %xmm2\n"
        "mulss 8(%eax), %xmm2\n"
        "movaps %xmm4, %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "movaps %xmm5, %xmm1\n"
        "mulss (%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "ucomiss 0xc(%eax), %xmm2\n"
        "jbe .Lf68d10_00068f4e\n"
        ".Lf68d10_00068f7f:\n"
        "addl $1, -0x20(%ebp)\n" /* line 167 | k */
        "movl -0x2c(%ebp), %eax\n"
        "cmpl %eax, -0x20(%ebp)\n" /* k */
        "je .Lf68d10_00068fa5\n"
        ".Lf68d10_00068f8b:\n"
        "movl -0x28(%ebp), %edx\n"
        "jmp .Lf68d10_00068ec2\n"
        ".Lf68d10_00068f93:\n"
        "movl 0xc(%edx), %ecx\n" /* line 191 */
        "orl %ecx, -0x1c(%ebp)\n" /* contents */
        "addl $1, -0x20(%ebp)\n" /* line 167 | k */
        "movl -0x2c(%ebp), %eax\n"
        "cmpl %eax, -0x20(%ebp)\n" /* k */
        "jne .Lf68d10_00068f8b\n"
        /* } scope */
        /* } scope */
        ".Lf68d10_00068fa5:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 198 | contents */
        "orl %edx, -0x30(%ebp)\n" /* contents */
        "movl -0x44(%ebp), %ecx\n" /* node */
        "jmp .Lf68d10_00068fb2\n"
        ".Lf68d10_00068fb0:\n"
        "movl %edx, %ecx\n"
        ".Lf68d10_00068fb2:\n"
        "movzbl (%ecx), %eax\n" /* line 201 */
        "movss 8(%ecx), %xmm0\n"
        "ucomiss (%edi, %eax, 4), %xmm0\n" /* p */
        "sbbl %eax, %eax\n"
        "notl %eax\n"
        "andl $2, %eax\n"
        "movzwl 0x10(%ecx, %eax), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%ecx, %eax, 4), %ecx\n"
        "movl %ecx, -0x44(%ebp)\n" /* node */
        "movl %ecx, %edx\n"
        "jmp .Lf68d10_00068e3f\n"
        /* } scope */
        /* } scope */
        ".Lf68d10_00068fda:\n"
        "movl -0x30(%ebp), %edx\n" /* line 198 | contents */
        "orl %edx, -0x48(%ebp)\n" /* contents */
        "movl -0x5c(%ebp), %edx\n" /* node */
        ".Lf68d10_00068fe3:\n"
        "movzbl (%edx), %eax\n" /* line 201 */
        "movss 8(%edx), %xmm0\n"
        "ucomiss (%edi, %eax, 4), %xmm0\n" /* p */
        "sbbl %eax, %eax\n"
        "notl %eax\n"
        "andl $2, %eax\n"
        "movzwl 0x10(%edx, %eax), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%edx, %eax, 4), %edx\n"
        "movl %edx, -0x5c(%ebp)\n" /* node */
        "jmp .Lf68d10_00068e19\n"
        /* { scope 12: k, contents */
        /* { scope 13 */
        ".Lf68d10_00069009:\n"
        "cwtl\n" /* line 167 */
        "movl %eax, -0x40(%ebp)\n"
        "testl %eax, %eax\n"
        "jle .Lf68d10_00068fda\n"
        "movl -0x44(%ebp), %ecx\n" /* line 169 | node */
        "movl 8(%ecx), %ecx\n"
        "movl %ecx, -0x3c(%ebp)\n"
        "movl 0x195eda4, %eax\n" /* line 170 */
        "movl 0x80(%eax), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl $0, -0x34(%ebp)\n" /* k */
        "movl %ecx, %edx\n"
        "movl %eax, %ebx\n" /* b */
        ".Lf68d10_00069033:\n"
        "movl -0x34(%ebp), %ecx\n" /* k */
        "movzwl (%edx, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "shll $4, %eax\n"
        "addl %eax, %ebx\n" /* b */
        "movl %ebx, %eax\n" /* b */
        "movl $1, %edx\n"
        ".Lf68d10_00069049:\n"
        "movss -4(%edi, %edx, 4), %xmm1\n" /* line 174 | p */
        "movss (%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf68d10_000690ed\n"
        "ucomiss 0x10(%eax), %xmm1\n" /* line 176 */
        "ja .Lf68d10_000690ed\n"
        "addl $1, %edx\n" /* line 177 */
        "addl $4, %eax\n"
        "cmpl $4, %edx\n" /* line 172 */
        "jne .Lf68d10_00069049\n"
        "movl 0x20(%ebx), %edx\n" /* line 180 | b */
        "movl 0x1c(%ebx), %esi\n" /* line 181 | b, i */
        "testl %esi, %esi\n" /* line 185 | i */
        "je .Lf68d10_00069108\n"
        "movl (%edx), %eax\n" /* line 187 */
        "movss (%edi), %xmm4\n" /* line 304 | p */
        "movss 4(%edi), %xmm3\n" /* p */
        "movss 8(%edi), %xmm2\n" /* p */
        "movaps %xmm4, %xmm0\n" /* line 187 */
        "mulss (%eax), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 4(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "ucomiss 0xc(%eax), %xmm0\n"
        "ja .Lf68d10_000690ed\n"
        "addl $8, %edx\n" /* line 188 */
        "xorl %ecx, %ecx\n"
        "subl $1, %esi\n" /* i */
        ".Lf68d10_000690bc:\n"
        "cmpl %ecx, %esi\n" /* line 185 | i */
        "je .Lf68d10_00069108\n"
        "movl (%edx), %eax\n" /* line 187 */
        "addl $1, %ecx\n"
        "addl $8, %edx\n"
        "movaps %xmm3, %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss (%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "ucomiss 0xc(%eax), %xmm0\n"
        "jbe .Lf68d10_000690bc\n"
        ".Lf68d10_000690ed:\n"
        "addl $1, -0x34(%ebp)\n" /* line 167 | k */
        "movl -0x40(%ebp), %eax\n"
        "cmpl %eax, -0x34(%ebp)\n" /* k */
        "je .Lf68d10_00068fda\n"
        "movl -0x3c(%ebp), %edx\n"
        "movl -0x38(%ebp), %ebx\n" /* b */
        "jmp .Lf68d10_00069033\n"
        ".Lf68d10_00069108:\n"
        "movl 0xc(%ebx), %ecx\n" /* line 191 | b */
        "orl %ecx, -0x30(%ebp)\n" /* contents */
        "jmp .Lf68d10_000690ed\n"
        ".Lf68d10_00069110:\n"
        "movl %edx, %ecx\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf68d10_00069112:\n"
        "movzbl (%ecx), %eax\n" /* line 201 */
        "movss 8(%ecx), %xmm0\n"
        "ucomiss (%edi, %eax, 4), %xmm0\n" /* p */
        "sbbl %eax, %eax\n"
        "notl %eax\n"
        "andl $2, %eax\n"
        "movzwl 0x10(%ecx, %eax), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%ecx, %eax, 4), %ecx\n"
        "movl %ecx, -0x74(%ebp)\n" /* node */
        "movl %ecx, %edx\n"
        "jmp .Lf68d10_00068df3\n"
        /* { scope 10: k, contents */
        /* { scope 11: node */
        ".Lf68d10_0006913a:\n"
        "cwtl\n" /* line 167 */
        "movl %eax, -0x58(%ebp)\n"
        "testl %eax, %eax\n"
        "jle .Lf68d10_00069249\n"
        "movl -0x5c(%ebp), %ecx\n" /* line 169 | node */
        "movl 8(%ecx), %ecx\n"
        "movl %ecx, -0x54(%ebp)\n"
        "movl 0x195eda4, %eax\n" /* line 170 */
        "movl 0x80(%eax), %eax\n"
        "movl %eax, -0x50(%ebp)\n"
        "movl $0, -0x4c(%ebp)\n" /* k */
        "movl -0x4c(%ebp), %edx\n" /* k */
        "movl %eax, %ebx\n" /* b */
        ".Lf68d10_00069169:\n"
        "movzwl (%ecx, %edx, 2), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "shll $4, %eax\n"
        "addl %eax, %ebx\n" /* b */
        "movl %ebx, %eax\n" /* b */
        "movl $1, %edx\n"
        ".Lf68d10_0006917c:\n"
        "movss -4(%edi, %edx, 4), %xmm1\n" /* line 174 | p */
        "movss (%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf68d10_00069220\n"
        "ucomiss 0x10(%eax), %xmm1\n" /* line 176 */
        "ja .Lf68d10_00069220\n"
        "addl $1, %edx\n" /* line 177 */
        "addl $4, %eax\n"
        "cmpl $4, %edx\n" /* line 172 */
        "jne .Lf68d10_0006917c\n"
        "movl 0x20(%ebx), %edx\n" /* line 180 | b */
        "movl 0x1c(%ebx), %esi\n" /* line 181 | b, i */
        "testl %esi, %esi\n" /* line 185 | i */
        "je .Lf68d10_00069237\n"
        "movl (%edx), %eax\n" /* line 187 */
        "movss (%edi), %xmm5\n" /* line 304 | p */
        "movss 4(%edi), %xmm4\n" /* p */
        "movss 8(%edi), %xmm3\n" /* p */
        "movaps %xmm5, %xmm0\n" /* line 187 */
        "mulss (%eax), %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss 4(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "ucomiss 0xc(%eax), %xmm0\n"
        "ja .Lf68d10_00069220\n"
        "addl $8, %edx\n" /* line 188 */
        "xorl %ecx, %ecx\n"
        "subl $1, %esi\n" /* i */
        ".Lf68d10_000691ef:\n"
        "cmpl %ecx, %esi\n" /* line 185 | i */
        "je .Lf68d10_00069237\n"
        "movl (%edx), %eax\n" /* line 187 */
        "addl $1, %ecx\n"
        "addl $8, %edx\n"
        "movaps %xmm3, %xmm2\n"
        "mulss 8(%eax), %xmm2\n"
        "movaps %xmm4, %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "movaps %xmm5, %xmm1\n"
        "mulss (%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "ucomiss 0xc(%eax), %xmm2\n"
        "jbe .Lf68d10_000691ef\n"
        ".Lf68d10_00069220:\n"
        "addl $1, -0x4c(%ebp)\n" /* line 167 | k */
        "movl -0x4c(%ebp), %edx\n" /* k */
        "cmpl %edx, -0x58(%ebp)\n"
        "je .Lf68d10_00069249\n"
        ".Lf68d10_0006922c:\n"
        "movl -0x54(%ebp), %ecx\n"
        "movl -0x50(%ebp), %ebx\n" /* b */
        "jmp .Lf68d10_00069169\n"
        ".Lf68d10_00069237:\n"
        "movl 0xc(%ebx), %eax\n" /* line 191 | b */
        "orl %eax, -0x48(%ebp)\n" /* contents */
        "addl $1, -0x4c(%ebp)\n" /* line 167 | k */
        "movl -0x4c(%ebp), %edx\n" /* k */
        "cmpl %edx, -0x58(%ebp)\n"
        "jne .Lf68d10_0006922c\n"
        /* } scope */
        /* } scope */
        ".Lf68d10_00069249:\n"
        "movl -0x48(%ebp), %ecx\n" /* line 198 | contents */
        "orl %ecx, -0x60(%ebp)\n" /* contents */
        "movl -0x74(%ebp), %ecx\n" /* node */
        "jmp .Lf68d10_00069112\n"
        ".Lf68d10_00069257:\n"
        "cwtl\n" /* line 167 */
        "movl %eax, -0x70(%ebp)\n"
        "testl %eax, %eax\n"
        "jle .Lf68d10_00069355\n"
        "movl -0x74(%ebp), %ecx\n" /* line 169 | node */
        "movl 8(%ecx), %ecx\n"
        "movl %ecx, -0x6c(%ebp)\n"
        "movl 0x195eda4, %eax\n" /* line 170 */
        "movl 0x80(%eax), %eax\n"
        "movl %eax, -0x68(%ebp)\n"
        "movl $0, -0x64(%ebp)\n" /* k */
        ".Lf68d10_00069281:\n"
        "movl -0x64(%ebp), %edx\n" /* k */
        "movl -0x6c(%ebp), %ecx\n"
        "movzwl (%ecx, %edx, 2), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "shll $4, %eax\n"
        "movl -0x68(%ebp), %ebx\n" /* b */
        "addl %eax, %ebx\n" /* b */
        "movl %ebx, %eax\n" /* b */
        "movl $1, %edx\n"
        ".Lf68d10_0006929d:\n"
        "movss -4(%edi, %edx, 4), %xmm1\n" /* line 174 | p */
        "movss (%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf68d10_00069345\n"
        "ucomiss 0x10(%eax), %xmm1\n" /* line 176 */
        "ja .Lf68d10_00069345\n"
        "addl $1, %edx\n" /* line 177 */
        "addl $4, %eax\n"
        "cmpl $4, %edx\n" /* line 172 */
        "jne .Lf68d10_0006929d\n"
        "movl 0x20(%ebx), %edx\n" /* line 180 | b */
        "movl 0x1c(%ebx), %esi\n" /* line 181 | b, i */
        "testl %esi, %esi\n" /* line 185 | i */
        "je .Lf68d10_0006933f\n"
        "movl (%edx), %eax\n" /* line 187 */
        "movss (%edi), %xmm4\n" /* line 304 | p */
        "movss 4(%edi), %xmm3\n" /* p */
        "movss 8(%edi), %xmm2\n" /* p */
        "movaps %xmm4, %xmm0\n" /* line 187 */
        "mulss (%eax), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 4(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "ucomiss 0xc(%eax), %xmm0\n"
        "ja .Lf68d10_00069345\n"
        "addl $8, %edx\n" /* line 188 */
        "xorl %ecx, %ecx\n"
        "subl $1, %esi\n" /* i */
        "jmp .Lf68d10_0006933b\n"
        ".Lf68d10_0006930e:\n"
        "movl (%edx), %eax\n" /* line 187 */
        "addl $1, %ecx\n"
        "addl $8, %edx\n"
        "movaps %xmm4, %xmm0\n"
        "mulss (%eax), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 4(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "ucomiss 0xc(%eax), %xmm0\n"
        "ja .Lf68d10_00069345\n"
        ".Lf68d10_0006933b:\n"
        "cmpl %ecx, %esi\n" /* line 185 | i */
        "jne .Lf68d10_0006930e\n"
        ".Lf68d10_0006933f:\n"
        "movl 0xc(%ebx), %eax\n" /* line 191 | b */
        "orl %eax, -0x60(%ebp)\n" /* contents */
        ".Lf68d10_00069345:\n"
        "addl $1, -0x64(%ebp)\n" /* line 167 | k */
        "movl -0x70(%ebp), %edx\n"
        "cmpl %edx, -0x64(%ebp)\n" /* k */
        "jne .Lf68d10_00069281\n"
        /* } scope */
        /* } scope */
        ".Lf68d10_00069355:\n"
        "movl -0x60(%ebp), %ecx\n" /* line 198 | contents */
        "orl %ecx, -0x78(%ebp)\n" /* contents */
        ".Lf68d10_0006935b:\n"
        "movl -0x8c(%ebp), %edx\n" /* line 201 | node */
        "movzbl (%edx), %eax\n"
        "movss 8(%edx), %xmm0\n"
        "ucomiss (%edi, %eax, 4), %xmm0\n" /* p */
        "sbbl %eax, %eax\n"
        "notl %eax\n"
        "andl $2, %eax\n"
        "movzwl 0x10(%edx, %eax), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%edx, %eax, 4), %edx\n"
        "movl %edx, -0x8c(%ebp)\n" /* node */
        "jmp .Lf68d10_00068dc4\n"
        /* } scope */
        /* } scope */
        ".Lf68d10_0006938a:\n"
        "cwtl\n" /* line 167 */
        "movl %eax, -0xa0(%ebp)\n"
        "testl %eax, %eax\n"
        "jle .Lf68d10_00069618\n"
        "movl -0xa4(%ebp), %ecx\n" /* line 169 | node */
        "movl 8(%ecx), %ecx\n"
        "movl %ecx, -0x9c(%ebp)\n"
        "movl 0x195eda4, %eax\n" /* line 170 */
        "movl 0x80(%eax), %eax\n"
        "movl %eax, -0x98(%ebp)\n"
        "movl $0, -0x94(%ebp)\n" /* k */
        ".Lf68d10_000693c3:\n"
        "movl -0x94(%ebp), %edx\n" /* k */
        "movl -0x9c(%ebp), %ecx\n"
        "movzwl (%ecx, %edx, 2), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "shll $4, %eax\n"
        "movl -0x98(%ebp), %ebx\n" /* b */
        "addl %eax, %ebx\n" /* b */
        "movl %ebx, %eax\n" /* b */
        "movl $1, %edx\n"
        ".Lf68d10_000693e8:\n"
        "movss -4(%edi, %edx, 4), %xmm1\n" /* line 174 | p */
        "movss (%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf68d10_000695ff\n"
        "ucomiss 0x10(%eax), %xmm1\n" /* line 176 */
        "ja .Lf68d10_000695ff\n"
        "addl $1, %edx\n" /* line 177 */
        "addl $4, %eax\n"
        "cmpl $4, %edx\n" /* line 172 */
        "jne .Lf68d10_000693e8\n"
        "movl 0x20(%ebx), %edx\n" /* line 180 | b */
        "movl 0x1c(%ebx), %esi\n" /* line 181 | b, i */
        "testl %esi, %esi\n" /* line 185 | i */
        "je .Lf68d10_000695f6\n"
        "movl (%edx), %eax\n" /* line 187 */
        "movss (%edi), %xmm4\n" /* line 304 | p */
        "movss 4(%edi), %xmm3\n" /* p */
        "movss 8(%edi), %xmm2\n" /* p */
        "movaps %xmm4, %xmm0\n" /* line 187 */
        "mulss (%eax), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 4(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "ucomiss 0xc(%eax), %xmm0\n"
        "ja .Lf68d10_000695ff\n"
        "addl $8, %edx\n" /* line 188 */
        "xorl %ecx, %ecx\n"
        "subl $1, %esi\n" /* i */
        ".Lf68d10_0006945f:\n"
        "cmpl %esi, %ecx\n" /* line 185 | i */
        "je .Lf68d10_000695f6\n"
        "movl (%edx), %eax\n" /* line 187 */
        "addl $1, %ecx\n"
        "addl $8, %edx\n"
        "movaps %xmm4, %xmm0\n"
        "mulss (%eax), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 4(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "ucomiss 0xc(%eax), %xmm0\n"
        "jbe .Lf68d10_0006945f\n"
        "jmp .Lf68d10_000695ff\n"
        /* { scope 6: k, contents */
        /* { scope 7: node */
        ".Lf68d10_00069499:\n"
        "movl 0xc(%ebx), %eax\n" /* line 191 | b */
        "orl %eax, -0x78(%ebp)\n" /* contents */
        ".Lf68d10_0006949f:\n"
        "addl $1, -0x7c(%ebp)\n" /* line 167 | k */
        "movl -0x88(%ebp), %edx\n"
        "cmpl %edx, -0x7c(%ebp)\n" /* k */
        "jne .Lf68d10_000697f2\n"
        /* } scope */
        /* } scope */
        ".Lf68d10_000694b2:\n"
        "movl -0x78(%ebp), %ecx\n" /* line 198 | contents */
        "orl %ecx, -0x90(%ebp)\n" /* contents */
        ".Lf68d10_000694bb:\n"
        "movl -0xa4(%ebp), %ecx\n" /* line 201 | node */
        "movzbl (%ecx), %eax\n"
        "movss 8(%ecx), %xmm0\n"
        "ucomiss (%edi, %eax, 4), %xmm0\n" /* p */
        "sbbl %eax, %eax\n"
        "notl %eax\n"
        "andl $2, %eax\n"
        "movzwl 0x10(%ecx, %eax), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%ecx, %eax, 4), %ecx\n"
        "movl %ecx, -0xa4(%ebp)\n" /* node */
        "jmp .Lf68d10_00068d94\n"
        /* } scope */
        /* } scope */
        ".Lf68d10_000694ea:\n"
        "cwtl\n" /* line 167 */
        "movl %eax, -0xb8(%ebp)\n"
        "testl %eax, %eax\n"
        "jle .Lf68d10_00069675\n"
        "movl -0xbc(%ebp), %ecx\n" /* line 169 | node */
        "movl 8(%ecx), %ecx\n"
        "movl %ecx, -0xb4(%ebp)\n"
        "movl 0x195eda4, %eax\n" /* line 170 */
        "movl 0x80(%eax), %eax\n"
        "movl %eax, -0xb0(%ebp)\n"
        "movl $0, -0xac(%ebp)\n" /* k */
        ".Lf68d10_00069523:\n"
        "movl -0xac(%ebp), %edx\n" /* k */
        "movl -0xb4(%ebp), %ecx\n"
        "movzwl (%ecx, %edx, 2), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "shll $4, %eax\n"
        "movl -0xb0(%ebp), %ecx\n"
        "addl %eax, %ecx\n"
        "movl %ecx, %eax\n"
        "movl $1, %edx\n"
        ".Lf68d10_00069548:\n"
        "movss -4(%edi, %edx, 4), %xmm1\n" /* line 174 | p */
        "movss (%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf68d10_0006965c\n"
        "ucomiss 0x10(%eax), %xmm1\n" /* line 176 */
        "ja .Lf68d10_0006965c\n"
        "addl $1, %edx\n" /* line 177 */
        "addl $4, %eax\n"
        "cmpl $4, %edx\n" /* line 172 */
        "jne .Lf68d10_00069548\n"
        "movl 0x20(%ecx), %edx\n" /* line 180 */
        "movl 0x1c(%ecx), %esi\n" /* line 181 | i */
        "testl %esi, %esi\n" /* line 185 | i */
        "je .Lf68d10_00069653\n"
        "movl (%edx), %eax\n" /* line 187 */
        "movss (%edi), %xmm4\n" /* line 304 | p */
        "movss 4(%edi), %xmm3\n" /* p */
        "movss 8(%edi), %xmm2\n" /* p */
        "movaps %xmm4, %xmm0\n" /* line 187 */
        "mulss (%eax), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 4(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "ucomiss 0xc(%eax), %xmm0\n"
        "ja .Lf68d10_0006965c\n"
        "addl $8, %edx\n" /* line 188 */
        "xorl %ebx, %ebx\n" /* b */
        "subl $1, %esi\n" /* i */
        ".Lf68d10_000695bf:\n"
        "cmpl %esi, %ebx\n" /* line 185 | i, b */
        "je .Lf68d10_00069653\n"
        "movl (%edx), %eax\n" /* line 187 */
        "addl $1, %ebx\n" /* b */
        "addl $8, %edx\n"
        "movaps %xmm4, %xmm0\n"
        "mulss (%eax), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 4(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "ucomiss 0xc(%eax), %xmm0\n"
        "jbe .Lf68d10_000695bf\n"
        "jmp .Lf68d10_0006965c\n"
        /* { scope 4: k, contents */
        /* { scope 5: node */
        ".Lf68d10_000695f6:\n"
        "movl 0xc(%ebx), %eax\n" /* line 191 | b */
        "orl %eax, -0x90(%ebp)\n" /* contents */
        ".Lf68d10_000695ff:\n"
        "addl $1, -0x94(%ebp)\n" /* line 167 | k */
        "movl -0xa0(%ebp), %edx\n"
        "cmpl %edx, -0x94(%ebp)\n" /* k */
        "jne .Lf68d10_000693c3\n"
        /* } scope */
        /* } scope */
        ".Lf68d10_00069618:\n"
        "movl -0x90(%ebp), %ecx\n" /* line 198 | contents */
        "orl %ecx, -0xa8(%ebp)\n" /* contents */
        ".Lf68d10_00069624:\n"
        "movl -0xbc(%ebp), %edx\n" /* line 201 | node */
        "movzbl (%edx), %eax\n"
        "movss 8(%edx), %xmm0\n"
        "ucomiss (%edi, %eax, 4), %xmm0\n" /* p */
        "sbbl %eax, %eax\n"
        "notl %eax\n"
        "andl $2, %eax\n"
        "movzwl 0x10(%edx, %eax), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%edx, %eax, 4), %edx\n"
        "movl %edx, -0xbc(%ebp)\n" /* node */
        "jmp .Lf68d10_00068d61\n"
        ".Lf68d10_00069653:\n"
        "movl 0xc(%ecx), %eax\n" /* line 191 */
        "orl %eax, -0xa8(%ebp)\n" /* contents */
        ".Lf68d10_0006965c:\n"
        "addl $1, -0xac(%ebp)\n" /* line 167 | k */
        "movl -0xb8(%ebp), %edx\n"
        "cmpl %edx, -0xac(%ebp)\n" /* k */
        "jne .Lf68d10_00069523\n"
        /* } scope */
        /* } scope */
        ".Lf68d10_00069675:\n"
        "movl -0xa8(%ebp), %ecx\n" /* line 198 | contents */
        "orl %ecx, -0xc0(%ebp)\n" /* contents */
        ".Lf68d10_00069681:\n"
        "movl -0xd4(%ebp), %ecx\n" /* line 201 */
        "movzbl (%ecx), %eax\n"
        "movss 8(%ecx), %xmm0\n"
        "ucomiss (%edi, %eax, 4), %xmm0\n" /* p */
        "sbbl %eax, %eax\n"
        "notl %eax\n"
        "andl $2, %eax\n"
        "movzwl 0x10(%ecx, %eax), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%ecx, %eax, 4), %ecx\n"
        "movl %ecx, -0xd4(%ebp)\n"
        "jmp .Lf68d10_00068d2e\n"
        ".Lf68d10_000696b0:\n"
        "cwtl\n" /* line 167 */
        "movl %eax, -0xd0(%ebp)\n"
        "testl %eax, %eax\n"
        "jle .Lf68d10_000698e7\n"
        "movl -0xd4(%ebp), %eax\n" /* line 169 */
        "movl 8(%eax), %eax\n"
        "movl %eax, -0xcc(%ebp)\n"
        "movl 0x195eda4, %eax\n" /* line 170 */
        "movl 0x80(%eax), %eax\n"
        "movl %eax, -0xc8(%ebp)\n"
        "movl $0, -0xc4(%ebp)\n" /* k */
        ".Lf68d10_000696e9:\n"
        "movl -0xc4(%ebp), %edx\n" /* k */
        "movl -0xcc(%ebp), %ecx\n"
        "movzwl (%ecx, %edx, 2), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "shll $4, %eax\n"
        "movl -0xc8(%ebp), %ebx\n" /* b */
        "addl %eax, %ebx\n" /* b */
        "movl %ebx, %eax\n" /* b */
        "movl $1, %ecx\n"
        ".Lf68d10_0006970e:\n"
        "movss -4(%edi, %ecx, 4), %xmm1\n" /* line 174 | p */
        "movss (%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf68d10_000698ce\n"
        "ucomiss 0x10(%eax), %xmm1\n" /* line 176 */
        "ja .Lf68d10_000698ce\n"
        "addl $1, %ecx\n" /* line 177 */
        "addl $4, %eax\n"
        "cmpl $4, %ecx\n" /* line 172 */
        "jne .Lf68d10_0006970e\n"
        "movl 0x20(%ebx), %ecx\n" /* line 180 | b */
        "movl 0x1c(%ebx), %edx\n" /* line 181 | b */
        "testl %edx, %edx\n" /* line 185 */
        "je .Lf68d10_000698c5\n"
        "movl (%ecx), %eax\n" /* line 187 */
        "movss (%edi), %xmm4\n" /* line 304 | p */
        "movss 4(%edi), %xmm3\n" /* p */
        "movss 8(%edi), %xmm2\n" /* p */
        "movaps %xmm4, %xmm0\n" /* line 187 */
        "mulss (%eax), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 4(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "ucomiss 0xc(%eax), %xmm0\n"
        "ja .Lf68d10_000698ce\n"
        "addl $8, %ecx\n" /* line 188 */
        "xorl %esi, %esi\n" /* i */
        "subl $1, %edx\n"
        ".Lf68d10_00069785:\n"
        "cmpl %esi, %edx\n" /* line 185 | i */
        "je .Lf68d10_000698c5\n"
        "movl (%ecx), %eax\n" /* line 187 */
        "addl $1, %esi\n" /* i */
        "addl $8, %ecx\n"
        "movaps %xmm4, %xmm0\n"
        "mulss (%eax), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 4(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "ucomiss 0xc(%eax), %xmm0\n"
        "jbe .Lf68d10_00069785\n"
        "jmp .Lf68d10_000698ce\n"
        /* { scope 2: k, contents */
        /* { scope 3: node */
        /* { scope 4: k, contents */
        /* { scope 5: node */
        /* { scope 6: k, contents */
        /* { scope 7: node */
        ".Lf68d10_000697bf:\n"
        "cwtl\n" /* line 167 */
        "movl %eax, -0x88(%ebp)\n"
        "testl %eax, %eax\n"
        "jle .Lf68d10_000694b2\n"
        "movl -0x8c(%ebp), %ecx\n" /* line 169 | node */
        "movl 8(%ecx), %ecx\n"
        "movl %ecx, -0x84(%ebp)\n"
        "movl 0x195eda4, %eax\n" /* line 170 */
        "movl 0x80(%eax), %eax\n"
        "movl %eax, -0x80(%ebp)\n"
        "movl $0, -0x7c(%ebp)\n" /* k */
        ".Lf68d10_000697f2:\n"
        "movl -0x7c(%ebp), %edx\n" /* k */
        "movl -0x84(%ebp), %ecx\n"
        "movzwl (%ecx, %edx, 2), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "shll $4, %eax\n"
        "movl -0x80(%ebp), %ebx\n" /* b */
        "addl %eax, %ebx\n" /* b */
        "movl %ebx, %eax\n" /* b */
        "movl $1, %edx\n"
        "jmp .Lf68d10_00069828\n"
        ".Lf68d10_00069813:\n"
        "ucomiss 0x10(%eax), %xmm1\n" /* line 176 */
        "ja .Lf68d10_0006949f\n"
        "addl $1, %edx\n" /* line 177 */
        "addl $4, %eax\n"
        "cmpl $4, %edx\n" /* line 172 */
        "je .Lf68d10_0006983c\n"
        ".Lf68d10_00069828:\n"
        "movss -4(%edi, %edx, 4), %xmm1\n" /* line 174 | p */
        "movss (%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf68d10_00069813\n"
        "jmp .Lf68d10_0006949f\n"
        ".Lf68d10_0006983c:\n"
        "movl 0x20(%ebx), %edx\n" /* line 180 | b */
        "movl 0x1c(%ebx), %esi\n" /* line 181 | b, i */
        "testl %esi, %esi\n" /* line 185 | i */
        "je .Lf68d10_00069499\n"
        "movl (%edx), %eax\n" /* line 187 */
        "movss (%edi), %xmm4\n" /* line 304 | p */
        "movss 4(%edi), %xmm3\n" /* p */
        "movss 8(%edi), %xmm2\n" /* p */
        "movaps %xmm4, %xmm0\n" /* line 187 */
        "mulss (%eax), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 4(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "ucomiss 0xc(%eax), %xmm0\n"
        "ja .Lf68d10_0006949f\n"
        "addl $8, %edx\n" /* line 188 */
        "xorl %ecx, %ecx\n"
        "subl $1, %esi\n" /* i */
        ".Lf68d10_0006988b:\n"
        "cmpl %esi, %ecx\n" /* line 185 | i */
        "je .Lf68d10_00069499\n"
        "movl (%edx), %eax\n" /* line 187 */
        "addl $1, %ecx\n"
        "addl $8, %edx\n"
        "movaps %xmm4, %xmm0\n"
        "mulss (%eax), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 4(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "ucomiss 0xc(%eax), %xmm0\n"
        "jbe .Lf68d10_0006988b\n"
        "jmp .Lf68d10_0006949f\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf68d10_000698c5:\n"
        "movl 0xc(%ebx), %eax\n" /* line 191 | b */
        "orl %eax, -0xc0(%ebp)\n" /* contents */
        ".Lf68d10_000698ce:\n"
        "addl $1, -0xc4(%ebp)\n" /* line 167 | k */
        "movl -0xd0(%ebp), %edx\n"
        "cmpl %edx, -0xc4(%ebp)\n" /* k */
        "jne .Lf68d10_000696e9\n"
        /* } scope */
        ".Lf68d10_000698e7:\n"
        "movl -0xc0(%ebp), %eax\n" /* line 203 | contents */
        "addl $0xcc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 212 */
__attribute__((naked))
int CM_PointContents(const vec_t *p, clipHandle_t model)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 212 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %esi\n" /* p */
        "movl 0xc(%ebp), %eax\n" /* model */
        /* { scope 1 */
        "testl %eax, %eax\n" /* line 221 */
        "jne .Lf698f8_00069b25\n"
        /* { scope 2: i, contents */
        /* { scope 3 */
        "movl 0x195eda4, %edi\n" /* line 17 */
        "movl 0x20(%edi), %ebx\n"
        "xorl %eax, %eax\n"
        "pxor %xmm2, %xmm2\n"
        "jmp .Lf698f8_0006993a\n"
        ".Lf698f8_00069920:\n"
        "movzbl %al, %eax\n" /* line 21 */
        "movss (%esi, %eax, 4), %xmm1\n"
        "subss 0xc(%edx), %xmm1\n"
        "ucomiss %xmm1, %xmm2\n" /* line 24 */
        "ja .Lf698f8_00069975\n"
        ".Lf698f8_00069932:\n"
        "movswl 4(%ecx), %eax\n" /* line 27 */
        "testl %eax, %eax\n" /* line 15 */
        "js .Lf698f8_0006997d\n"
        ".Lf698f8_0006993a:\n"
        "leal (%ebx, %eax, 8), %ecx\n" /* line 17 */
        "movl (%ecx), %edx\n" /* line 18 */
        "movzbl 0x10(%edx), %eax\n" /* line 20 */
        "cmpb $2, %al\n"
        "jbe .Lf698f8_00069920\n"
        "movss (%edx), %xmm1\n" /* line 23 */
        "mulss (%esi), %xmm1\n"
        "movss 4(%edx), %xmm0\n"
        "mulss 4(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%edx), %xmm0\n"
        "mulss 8(%esi), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "subss 0xc(%edx), %xmm1\n"
        "ucomiss %xmm1, %xmm2\n" /* line 24 */
        "jbe .Lf698f8_00069932\n"
        ".Lf698f8_00069975:\n"
        "movswl 6(%ecx), %eax\n" /* line 25 */
        "testl %eax, %eax\n" /* line 15 */
        "jns .Lf698f8_0006993a\n"
        /* } scope */
        /* } scope */
        ".Lf698f8_0006997d:\n"
        "notl %eax\n" /* line 229 */
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "movl 0x28(%edi), %eax\n" /* k */
        "leal (%eax, %edx, 4), %eax\n"
        ".Lf698f8_0006998b:\n"
        "movl 0x24(%eax), %ecx\n" /* line 232 */
        "testl %ecx, %ecx\n"
        "je .Lf698f8_00069b0b\n"
        "movl $1, %edx\n"
        ".Lf698f8_0006999b:\n"
        "movss -4(%esi, %edx, 4), %xmm1\n" /* line 237 | p */
        "movss 0xc(%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jae .Lf698f8_00069b0b\n"
        "ucomiss 0x18(%eax), %xmm1\n" /* line 239 */
        "jae .Lf698f8_00069b0b\n"
        "addl $1, %edx\n"
        "addl $4, %eax\n"
        "cmpl $4, %edx\n" /* line 235 */
        "jne .Lf698f8_0006999b\n"
        "leal (%ecx, %ecx, 4), %eax\n" /* line 243 */
        "movl 0x195eda4, %edx\n"
        "movl 0x30(%edx), %edx\n"
        "leal (%edx, %eax, 4), %ebx\n" /* node */
        "movl $0, -0x1c(%ebp)\n" /* contents */
        "jmp .Lf698f8_00069a07\n"
        /* { scope 2: i, contents */
        /* { scope 3 */
        ".Lf698f8_000699dc:\n"
        "leal 0x14(%ebx), %edx\n" /* line 198 */
        "movl %esi, %eax\n"
        "calll CM_PointContentsLeafBrushNode_r\n"
        "orl %eax, -0x1c(%ebp)\n" /* contents */
        ".Lf698f8_000699e9:\n"
        "movzbl (%ebx), %eax\n" /* line 201 */
        "movss 8(%ebx), %xmm0\n"
        "ucomiss (%esi, %eax, 4), %xmm0\n"
        "sbbl %eax, %eax\n"
        "notl %eax\n"
        "andl $2, %eax\n"
        "movzwl 0x10(%ebx, %eax), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%ebx, %eax, 4), %ebx\n"
        ".Lf698f8_00069a07:\n"
        "movzwl 2(%ebx), %eax\n" /* line 163 */
        "cmpw $0, %ax\n"
        "je .Lf698f8_000699e9\n"
        "jle .Lf698f8_000699dc\n" /* line 165 */
        "cwtl\n" /* line 167 */
        "movl %eax, -0x2c(%ebp)\n"
        "testl %eax, %eax\n"
        "jle .Lf698f8_00069b12\n"
        "movl 8(%ebx), %ebx\n" /* line 169 */
        "movl %ebx, -0x28(%ebp)\n"
        "movl 0x195eda4, %eax\n" /* line 170 */
        "movl 0x80(%eax), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "xorl %edi, %edi\n" /* k */
        "movl %ebx, %edx\n"
        ".Lf698f8_00069a37:\n"
        "movzwl (%edx, %edi, 2), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "shll $4, %eax\n"
        "movl -0x24(%ebp), %edx\n"
        "addl %eax, %edx\n"
        "movl %edx, %eax\n"
        "movl $1, %ecx\n"
        ".Lf698f8_00069a4d:\n"
        "movss -4(%esi, %ecx, 4), %xmm1\n" /* line 174 */
        "movss (%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf698f8_00069afb\n"
        "ucomiss 0x10(%eax), %xmm1\n" /* line 176 */
        "ja .Lf698f8_00069afb\n"
        "addl $1, %ecx\n" /* line 177 */
        "addl $4, %eax\n"
        "cmpl $4, %ecx\n" /* line 172 */
        "jne .Lf698f8_00069a4d\n"
        "movl 0x20(%edx), %ecx\n" /* line 180 */
        "movl 0x1c(%edx), %eax\n" /* line 181 */
        "movl %eax, -0x20(%ebp)\n" /* i */
        "testl %eax, %eax\n" /* line 185 */
        "je .Lf698f8_00069b1d\n"
        "movl (%ecx), %eax\n" /* line 187 */
        "movss (%esi), %xmm4\n" /* line 304 | p */
        "movss 4(%esi), %xmm3\n" /* p */
        "movss 8(%esi), %xmm2\n" /* p */
        "movaps %xmm3, %xmm0\n" /* line 187 */
        "mulss 4(%eax), %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss (%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "ucomiss 0xc(%eax), %xmm0\n"
        "ja .Lf698f8_00069afb\n"
        "addl $8, %ecx\n" /* line 188 */
        "xorl %ebx, %ebx\n"
        "movl -0x20(%ebp), %eax\n" /* i */
        "subl $1, %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        ".Lf698f8_00069ac9:\n"
        "cmpl -0x30(%ebp), %ebx\n" /* line 185 */
        "je .Lf698f8_00069b1d\n"
        "movl (%ecx), %eax\n" /* line 187 */
        "addl $1, %ebx\n"
        "addl $8, %ecx\n"
        "movaps %xmm4, %xmm0\n"
        "mulss (%eax), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 4(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "ucomiss 0xc(%eax), %xmm0\n"
        "jbe .Lf698f8_00069ac9\n"
        ".Lf698f8_00069afb:\n"
        "addl $1, %edi\n" /* line 167 | k */
        "cmpl %edi, -0x2c(%ebp)\n" /* k */
        "je .Lf698f8_00069b12\n"
        "movl -0x28(%ebp), %edx\n"
        "jmp .Lf698f8_00069a37\n"
        ".Lf698f8_00069b0b:\n"
        "movl $0, -0x1c(%ebp)\n" /* line 202 | contents */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf698f8_00069b12:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 244 | contents */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: i, contents */
        /* { scope 3 */
        ".Lf698f8_00069b1d:\n"
        "movl 0xc(%edx), %eax\n" /* line 191 */
        "orl %eax, -0x1c(%ebp)\n" /* contents */
        "jmp .Lf698f8_00069afb\n"
        /* } scope */
        /* } scope */
        ".Lf698f8_00069b25:\n"
        "movl %eax, (%esp)\n" /* line 223 */
        "calll CM_ClipHandleToModel\n"
        "addl $0x1c, %eax\n" /* line 224 */
        "jmp .Lf698f8_0006998b\n"
    );
}

/* line 255 */
__attribute__((naked))
int CM_TransformedPointContents(const vec_t *p, clipHandle_t model, const vec_t *origin, const vec_t *angles)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 255 */
        "movl %esp, %ebp\n"
        "subl $0x48, %esp\n"
        "movl 8(%ebp), %eax\n" /* p */
        "movl 0x10(%ebp), %edx\n" /* origin */
        "movl 0x14(%ebp), %ecx\n" /* angles */
        /* { scope 1 */
        "movss (%eax), %xmm0\n" /* line 248 */
        "subss (%edx), %xmm0\n"
        "movss %xmm0, -0x14(%ebp)\n" /* p_l */
        "movss 4(%eax), %xmm0\n" /* line 249 */
        "subss 4(%edx), %xmm0\n"
        "movss %xmm0, -0x10(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 250 */
        "subss 8(%edx), %xmm0\n"
        "movss %xmm0, -0xc(%ebp)\n"
        "pxor %xmm0, %xmm0\n" /* line 265 */
        "ucomiss (%ecx), %xmm0\n"
        "jne .Lf69b36_00069b8f\n"
        "jp .Lf69b36_00069b8f\n"
        "ucomiss 4(%ecx), %xmm0\n"
        "jne .Lf69b36_00069b8f\n"
        "jp .Lf69b36_00069b8f\n"
        "ucomiss 8(%ecx), %xmm0\n"
        "jp .Lf69b36_00069b8f\n"
        "je .Lf69b36_00069c28\n"
        ".Lf69b36_00069b8f:\n"
        "leal -0x38(%ebp), %eax\n" /* line 267 | up */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* right */
        "movl %eax, 8(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* forward */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll AngleVectors\n"
        "movss -0x14(%ebp), %xmm2\n" /* line 199 | p_l */
        "movss -0x10(%ebp), %xmm3\n" /* line 200 */
        "movss -0xc(%ebp), %xmm4\n" /* line 201 */
        "movaps %xmm2, %xmm0\n" /* line 270 */
        "mulss -0x20(%ebp), %xmm0\n" /* forward */
        "movaps %xmm3, %xmm1\n"
        "mulss -0x1c(%ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss -0x18(%ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x14(%ebp)\n" /* p_l */
        "movaps %xmm2, %xmm0\n" /* line 271 */
        "mulss -0x2c(%ebp), %xmm0\n" /* right */
        "movaps %xmm3, %xmm1\n"
        "mulss -0x28(%ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss -0x24(%ebp), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "xorps 0x2f0640, %xmm0\n"
        "movss %xmm0, -0x10(%ebp)\n"
        "mulss -0x38(%ebp), %xmm2\n" /* line 272 | up */
        "mulss -0x34(%ebp), %xmm3\n"
        "addss %xmm3, %xmm2\n"
        "mulss -0x30(%ebp), %xmm4\n"
        "addss %xmm4, %xmm2\n"
        "movss %xmm2, -0xc(%ebp)\n"
        ".Lf69b36_00069c28:\n"
        "movl 0xc(%ebp), %eax\n" /* line 275 | model */
        "movl %eax, 4(%esp)\n"
        "leal -0x14(%ebp), %eax\n" /* p_l */
        "movl %eax, (%esp)\n"
        "calll CM_PointContents\n"
        /* } scope */
        "leave\n" /* line 276 */
        "retl\n"
    );
}

