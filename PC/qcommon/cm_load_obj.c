/* ASM dump from: cm_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/cm_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/com_vector.h"
 */

static int cml; /* 0x4ea684 */

void CM_Cleanup(void);
cplane_t * CM_GetPlaneNum(int planeNum);
void CMod_LoadPlanes(const byte *base, const lump_t *l);
static cLeafBrushNode_t * CMod_PartionLeafBrushes_r(short unsigned int *leafBrushes, int numLeafBrushes, const vec_t *mins, const vec_t *maxs);
static void CMod_PartionLeafBrushes(short unsigned int *leafBrushes, cLeaf_t *leaf);
void CM_LoadMapFromBsp(const char *name, int usePvs);

/* line 1318 */
__attribute__((naked))
void CM_Cleanup(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1318 */
        "movl %esp, %ebp\n"
        "movl $0, 0x4ea68c\n" /* line 1320 */
        "popl %ebp\n" /* line 1321 */
        "retl\n"
    );
}

/* line 1329 */
__attribute__((naked))
cplane_t * CM_GetPlaneNum(int planeNum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1329 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* planeNum */
        "leal (%eax, %eax, 4), %eax\n" /* planeNum */
        "movl 0x4ea688, %edx\n"
        "leal (%edx, %eax, 4), %eax\n" /* planeNum */
        "popl %ebp\n" /* line 1335 */
        "retl\n"
    );
}

/* line 772 */
__attribute__((naked))
void CMod_LoadPlanes(const byte *base, const lump_t *l)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 772 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* l */
        /* { scope 1: i */
        "movl 4(%ebx), %edi\n" /* line 781 | j, in */
        "addl 8(%ebp), %edi\n" /* base, in */
        "movl (%ebx), %eax\n" /* line 782 | j */
        "testb $0xf, %al\n"
        "jne .Lf78542_00078649\n"
        "shrl $4, %eax\n" /* line 784 */
        "movl %eax, -0x30(%ebp)\n" /* count */
        "testl %eax, %eax\n" /* line 786 */
        "jle .Lf78542_0007866d\n"
        ".Lf78542_0007856c:\n"
        "movl %eax, %edx\n"
        ".Lf78542_0007856e:\n"
        "movl $0x17, 8(%esp)\n" /* line 789 */
        "movl $0x21c32c, 4(%esp)\n" /* "CMod_LoadPlanes" */
        "leal (%edx, %edx, 4), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_Hunk_Alloc\n"
        "movl %eax, 0x4ea688\n"
        "movl -0x30(%ebp), %ecx\n" /* line 790 | count */
        "movl %ecx, cml\n"
        "movl %eax, %esi\n" /* line 792 | out */
        "testl %ecx, %ecx\n" /* line 794 */
        "jle .Lf78542_00078614\n"
        "movl $0, -0x34(%ebp)\n" /* i */
        "pxor %xmm2, %xmm2\n"
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        ".Lf78542_000785b3:\n"
        "movl %esi, -0x3c(%ebp)\n" /* out */
        "movb $0, -0x29(%ebp)\n" /* bits */
        "xorl %ebx, %ebx\n" /* j */
        "movl %edi, %edx\n" /* in */
        ".Lf78542_000785be:\n"
        "movl (%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* i */
        /* { scope 2 */
        "movss -0x1c(%ebp), %xmm0\n" /* line 341 | i */
        /* } scope */
        "movl -0x3c(%ebp), %eax\n" /* line 799 */
        "movss %xmm0, (%eax)\n"
        "ucomiss %xmm0, %xmm2\n" /* line 800 */
        "ja .Lf78542_0007861c\n"
        ".Lf78542_000785d4:\n"
        "addl $1, %ebx\n" /* line 797 | j */
        "addl $4, %edx\n"
        "addl $4, -0x3c(%ebp)\n"
        "cmpl $3, %ebx\n" /* j */
        "jne .Lf78542_000785be\n"
        "movl 0xc(%edi), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n" /* i */
        "movl -0x1c(%ebp), %eax\n" /* line 804 | i */
        "movl %eax, 0xc(%esi)\n" /* out */
        "ucomiss (%esi), %xmm1\n" /* line 805 | out */
        "jne .Lf78542_0007862a\n"
        "jp .Lf78542_0007862a\n"
        "xorl %eax, %eax\n"
        ".Lf78542_000785f8:\n"
        "movb %al, 0x10(%esi)\n" /* out */
        "movzbl -0x29(%ebp), %eax\n" /* line 806 | bits */
        "movb %al, 0x11(%esi)\n" /* out */
        "addl $1, -0x34(%ebp)\n" /* line 794 | i */
        "addl $0x10, %edi\n" /* in */
        "addl $0x14, %esi\n" /* out */
        "movl -0x34(%ebp), %edx\n" /* i */
        "cmpl %edx, -0x30(%ebp)\n" /* count */
        "jne .Lf78542_000785b3\n"
        /* } scope */
        ".Lf78542_00078614:\n"
        "addl $0x4c, %esp\n" /* line 808 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: i */
        ".Lf78542_0007861c:\n"
        "movl $1, %eax\n" /* line 801 */
        "movl %ebx, %ecx\n" /* j */
        "shll %cl, %eax\n"
        "orb %al, -0x29(%ebp)\n" /* bits */
        "jmp .Lf78542_000785d4\n"
        ".Lf78542_0007862a:\n"
        "ucomiss 4(%esi), %xmm1\n" /* line 805 | out */
        "jne .Lf78542_00078639\n"
        "jp .Lf78542_00078639\n"
        "movl $1, %eax\n"
        "jmp .Lf78542_000785f8\n"
        ".Lf78542_00078639:\n"
        "ucomiss 8(%esi), %xmm1\n" /* out */
        "setne %al\n"
        "setp %dl\n"
        "orb %dl, %al\n"
        "addb $2, %al\n"
        "jmp .Lf78542_000785f8\n"
        ".Lf78542_00078649:\n"
        "movl $0x21c2f4, 4(%esp)\n" /* line 783 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl (%ebx), %eax\n" /* j */
        "shrl $4, %eax\n" /* line 784 */
        "movl %eax, -0x30(%ebp)\n" /* count */
        "testl %eax, %eax\n" /* line 786 */
        "jg .Lf78542_0007856c\n"
        ".Lf78542_0007866d:\n"
        "movl $0x21c318, 4(%esp)\n" /* line 787 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl -0x30(%ebp), %edx\n" /* count */
        "jmp .Lf78542_0007856e\n"
    );
}

/* line 218 */
static __attribute__((naked))
cLeafBrushNode_t * CMod_PartionLeafBrushes_r(short unsigned int *leafBrushes, int numLeafBrushes, const vec_t *mins, const vec_t *maxs)
{
    __asm__ __volatile__ (
        ".Lf7868a_0007868a:\n"
        "pushl %ebp\n" /* line 218 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl %eax, -0x5c(%ebp)\n"
        "movl %edx, -0x60(%ebp)\n"
        "movl %ecx, -0x64(%ebp)\n"
        /* { scope 1 */
        "movl $0x14, (%esp)\n" /* line 92 */
        "calll TempMalloc\n"
        "movl %eax, -0x4c(%ebp)\n" /* node */
        "movl $0, (%eax)\n" /* line 93 */
        "movl $0, 4(%eax)\n"
        "movl $0, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n"
        "movss 0x2ed680, %xmm6\n" /* line 94 | -3.4028234663852886e+38f */
        "movss %xmm6, 8(%eax)\n"
        "movl 0x195eda4, %eax\n" /* line 254 */
        "movl 0x80(%eax), %esi\n" /* leafBrushesCopy */
        "movl 8(%ebp), %edx\n" /* maxs */
        "movl %edx, -0x44(%ebp)\n"
        "pxor %xmm5, %xmm5\n"
        "movaps %xmm5, %xmm7\n"
        "movl $0xffffffff, -0x50(%ebp)\n" /* axis */
        "movss %xmm5, -0x54(%ebp)\n" /* dist */
        "xorl %ebx, %ebx\n" /* numLeafBrushesChild */
        ".Lf7868a_000786fc:\n"
        "movl -0x60(%ebp), %eax\n" /* line 251 */
        "testl %eax, %eax\n"
        "jle .Lf7868a_000788d3\n"
        "movl $0, -0x58(%ebp)\n" /* k */
        "movl -0x58(%ebp), %ecx\n" /* k */
        ".Lf7868a_00078711:\n"
        "movl -0x5c(%ebp), %edi\n" /* line 254 */
        "movzwl (%edi, %ecx, 2), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "shll $4, %eax\n"
        "leal (%esi, %eax), %eax\n" /* leafBrushesCopy */
        "movl %eax, -0x40(%ebp)\n"
        "movss (%eax, %ebx, 4), %xmm2\n" /* line 256 */
        "xorl %edx, %edx\n"
        "movl $0xffffffff, %ecx\n"
        "movl $0xffffffff, -0x7c(%ebp)\n" /* side */
        "movaps %xmm6, %xmm4\n"
        "movss 0x2ed684, %xmm1\n" /* 3.4028234663852886e+38f */
        "jmp .Lf7868a_0007875a\n"
        /* { scope 2 */
        ".Lf7868a_00078744:\n"
        "addl $1, %ecx\n" /* line 188 */
        "ucomiss %xmm0, %xmm1\n" /* line 189 */
        "jbe .Lf7868a_0007874f\n"
        "movaps %xmm0, %xmm1\n"
        ".Lf7868a_0007874f:\n"
        "addl $1, %edx\n" /* line 182 */
        "cmpl %edx, -0x60(%ebp)\n"
        "je .Lf7868a_0007878f\n"
        ".Lf7868a_00078757:\n"
        "movl -0x5c(%ebp), %edi\n"
        ".Lf7868a_0007875a:\n"
        "movzwl (%edi, %edx, 2), %eax\n" /* line 185 */
        "leal (%eax, %eax, 2), %eax\n"
        "shll $4, %eax\n"
        "leal (%esi, %eax), %eax\n"
        "movss (%eax, %ebx, 4), %xmm0\n" /* line 186 */
        "ucomiss %xmm2, %xmm0\n"
        "jae .Lf7868a_00078744\n"
        "movss 0x10(%eax, %ebx, 4), %xmm0\n" /* line 193 */
        "ucomiss %xmm0, %xmm2\n"
        "jb .Lf7868a_0007874f\n"
        "addl $1, -0x7c(%ebp)\n" /* line 195 | side */
        "maxss %xmm4, %xmm0\n" /* line 196 */
        "movaps %xmm0, %xmm4\n"
        "addl $1, %edx\n" /* line 182 */
        "cmpl %edx, -0x60(%ebp)\n"
        "jne .Lf7868a_00078757\n"
        ".Lf7868a_0007878f:\n"
        "cmpl -0x7c(%ebp), %ecx\n" /* line 154 | side */
        "cmovnsl -0x7c(%ebp), %ecx\n" /* side */
        "movaps %xmm4, %xmm3\n" /* line 207 */
        "addss %xmm1, %xmm3\n"
        "mulss 0x2ed5d8, %xmm3\n" /* 0.5f */
        "testl %ecx, %ecx\n" /* line 209 */
        "jle .Lf7868a_00078a55\n"
        "movl -0x44(%ebp), %eax\n"
        "movss (%eax), %xmm0\n"
        "subss %xmm4, %xmm0\n"
        "movl -0x64(%ebp), %edx\n"
        "subss (%edx, %ebx, 4), %xmm1\n"
        /* { scope 3 */
        "movaps %xmm0, %xmm2\n" /* line 45 */
        "subss %xmm1, %xmm2\n"
        "movaps %xmm0, %xmm4\n"
        "cmpltss %xmm7, %xmm2\n"
        "andps %xmm2, %xmm4\n"
        "andnps %xmm1, %xmm2\n"
        "orps %xmm4, %xmm2\n"
        /* } scope */
        "cvtsi2ssl %ecx, %xmm0\n" /* line 209 */
        "mulss %xmm0, %xmm2\n"
        /* } scope */
        ".Lf7868a_000787e0:\n"
        "ucomiss %xmm5, %xmm2\n" /* line 258 */
        "jbe .Lf7868a_000787f0\n"
        "movaps %xmm2, %xmm5\n"
        "movl %ebx, -0x50(%ebp)\n" /* numLeafBrushesChild, axis */
        "movss %xmm3, -0x54(%ebp)\n" /* dist */
        ".Lf7868a_000787f0:\n"
        "movl -0x40(%ebp), %eax\n" /* line 265 */
        "movss 0x10(%eax, %ebx, 4), %xmm2\n"
        "xorl %edx, %edx\n"
        "movl $0xffffffff, %ecx\n"
        "movl $0xffffffff, -0x7c(%ebp)\n" /* side */
        "movaps %xmm6, %xmm4\n"
        "movss 0x2ed684, %xmm1\n" /* 3.4028234663852886e+38f */
        "jmp .Lf7868a_00078827\n"
        /* { scope 2 */
        ".Lf7868a_00078814:\n"
        "addl $1, %ecx\n" /* line 188 */
        "ucomiss %xmm0, %xmm1\n" /* line 189 */
        "jbe .Lf7868a_0007881f\n"
        "movaps %xmm0, %xmm1\n"
        ".Lf7868a_0007881f:\n"
        "addl $1, %edx\n" /* line 182 */
        "cmpl %edx, -0x60(%ebp)\n"
        "je .Lf7868a_0007885f\n"
        ".Lf7868a_00078827:\n"
        "movl -0x5c(%ebp), %edi\n" /* line 185 */
        "movzwl (%edi, %edx, 2), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "shll $4, %eax\n"
        "leal (%esi, %eax), %eax\n"
        "movss (%eax, %ebx, 4), %xmm0\n" /* line 186 */
        "ucomiss %xmm2, %xmm0\n"
        "jae .Lf7868a_00078814\n"
        "movss 0x10(%eax, %ebx, 4), %xmm0\n" /* line 193 */
        "ucomiss %xmm0, %xmm2\n"
        "jb .Lf7868a_0007881f\n"
        "addl $1, -0x7c(%ebp)\n" /* line 195 | side */
        "maxss %xmm4, %xmm0\n" /* line 196 */
        "movaps %xmm0, %xmm4\n"
        "addl $1, %edx\n" /* line 182 */
        "cmpl %edx, -0x60(%ebp)\n"
        "jne .Lf7868a_00078827\n"
        ".Lf7868a_0007885f:\n"
        "cmpl -0x7c(%ebp), %ecx\n" /* line 154 | side */
        "cmovnsl -0x7c(%ebp), %ecx\n" /* side */
        "movaps %xmm4, %xmm3\n" /* line 207 */
        "addss %xmm1, %xmm3\n"
        "mulss 0x2ed5d8, %xmm3\n" /* 0.5f */
        "testl %ecx, %ecx\n" /* line 209 */
        "jle .Lf7868a_00078a4d\n"
        "movl -0x44(%ebp), %eax\n"
        "movss (%eax), %xmm0\n"
        "subss %xmm4, %xmm0\n"
        "movl -0x64(%ebp), %edx\n"
        "subss (%edx, %ebx, 4), %xmm1\n"
        /* { scope 3 */
        "movaps %xmm0, %xmm2\n" /* line 45 */
        "subss %xmm1, %xmm2\n"
        "movaps %xmm0, %xmm4\n"
        "cmpltss %xmm7, %xmm2\n"
        "andps %xmm2, %xmm4\n"
        "andnps %xmm1, %xmm2\n"
        "orps %xmm4, %xmm2\n"
        /* } scope */
        "cvtsi2ssl %ecx, %xmm0\n" /* line 209 */
        "mulss %xmm0, %xmm2\n"
        /* } scope */
        ".Lf7868a_000788b0:\n"
        "ucomiss %xmm5, %xmm2\n" /* line 267 */
        "jbe .Lf7868a_000788c0\n"
        "movaps %xmm2, %xmm5\n"
        "movl %ebx, -0x50(%ebp)\n" /* numLeafBrushesChild, axis */
        "movss %xmm3, -0x54(%ebp)\n" /* dist */
        ".Lf7868a_000788c0:\n"
        "addl $1, -0x58(%ebp)\n" /* line 251 | k */
        "movl -0x58(%ebp), %eax\n" /* k */
        "cmpl %eax, -0x60(%ebp)\n"
        "je .Lf7868a_000788d3\n"
        "movl %eax, %ecx\n"
        "jmp .Lf7868a_00078711\n"
        ".Lf7868a_000788d3:\n"
        "addl $1, %ebx\n" /* numLeafBrushesChild */
        "addl $4, -0x44(%ebp)\n"
        "cmpl $3, %ebx\n" /* line 249 | numLeafBrushesChild */
        "jne .Lf7868a_000786fc\n"
        "movl -0x50(%ebp), %eax\n" /* line 276 | axis */
        "testl %eax, %eax\n"
        "js .Lf7868a_00078b6f\n"
        "movl -0x60(%ebp), %ebx\n" /* line 295 | numLeafBrushesChild */
        "addl %ebx, %ebx\n" /* numLeafBrushesChild */
        "movl $0x21c370, 4(%esp)\n" /* line 296 */
        "movl %ebx, (%esp)\n" /* numLeafBrushesChild */
        "calll CM_Hunk_AllocateTempMemoryHigh\n"
        "movl %eax, %esi\n" /* leafBrushesCopy */
        "movl %ebx, 8(%esp)\n" /* line 297 | numLeafBrushesChild */
        "movl -0x5c(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl -0x60(%ebp), %edi\n" /* line 301 */
        "testl %edi, %edi\n"
        "jg .Lf7868a_00078aee\n"
        ".Lf7868a_00078923:\n"
        "movzbl -0x50(%ebp), %edx\n" /* line 326 | axis */
        "movl -0x4c(%ebp), %ecx\n" /* node */
        "movb %dl, (%ecx)\n"
        "movss -0x54(%ebp), %xmm0\n" /* line 327 | dist */
        "movss %xmm0, 8(%ecx)\n"
        "movss 0x2ed684, %xmm2\n" /* 3.4028234663852886e+38f */
        "movl $0, -0x7c(%ebp)\n" /* side */
        "movl -0x50(%ebp), %eax\n" /* axis */
        "shll $2, %eax\n"
        "movl %eax, -0x68(%ebp)\n"
        ".Lf7868a_0007894e:\n"
        "movl -0x60(%ebp), %ebx\n" /* line 333 | numLeafBrushesChild */
        "testl %ebx, %ebx\n" /* numLeafBrushesChild */
        "jg .Lf7868a_00078a74\n"
        "xorl %ebx, %ebx\n" /* numLeafBrushesChild */
        "movl $0, -0x48(%ebp)\n"
        ".Lf7868a_00078962:\n"
        "movl -0x64(%ebp), %ecx\n" /* line 199 */
        "movl (%ecx), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* childMins */
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, -0x20(%ebp)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 8(%ebp), %edi\n" /* line 199 | maxs */
        "movl (%edi), %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* childMaxs */
        "movl 4(%edi), %eax\n" /* line 200 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl 8(%edi), %eax\n" /* line 201 */
        "movl %eax, -0x28(%ebp)\n"
        "movl -0x7c(%ebp), %edx\n" /* line 360 | side */
        "testl %edx, %edx\n"
        "jne .Lf7868a_00078a5d\n"
        "movss -0x54(%ebp), %xmm0\n" /* line 361 | dist */
        "addss %xmm2, %xmm0\n"
        "movl -0x50(%ebp), %eax\n" /* axis */
        "movss %xmm0, -0x24(%ebp, %eax, 4)\n"
        ".Lf7868a_000789a7:\n"
        "leal -0x30(%ebp), %ecx\n" /* line 365 | childMaxs */
        "movl %ecx, (%esp)\n"
        "leal -0x24(%ebp), %ecx\n" /* childMins */
        "movl %ebx, %edx\n" /* numLeafBrushesChild */
        "movl -0x5c(%ebp), %eax\n"
        "movss %xmm2, -0x78(%ebp)\n"
        "calll CMod_PartionLeafBrushes_r\n"
        "movl %eax, %ebx\n" /* numLeafBrushesChild */
        "movl %eax, %ecx\n" /* line 366 */
        "subl -0x4c(%ebp), %ecx\n" /* node */
        "sarl $2, %ecx\n"
        "leal (%ecx, %ecx, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $8, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $0x10, %edx\n"
        "addl %edx, %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl -0x7c(%ebp), %edi\n" /* line 367 | side */
        "movl -0x4c(%ebp), %edx\n" /* node */
        "movw %ax, 0x10(%edx, %edi, 2)\n"
        "movzwl %ax, %edx\n" /* line 368 */
        "cmpl %edx, %eax\n"
        "movss -0x78(%ebp), %xmm2\n"
        "je .Lf7868a_00078a14\n"
        "movl $0x21c38c, 4(%esp)\n" /* line 369 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movss -0x78(%ebp), %xmm2\n"
        ".Lf7868a_00078a14:\n"
        "movl -0x4c(%ebp), %ecx\n" /* line 371 | node */
        "movl 4(%ecx), %eax\n"
        "orl 4(%ebx), %eax\n" /* numLeafBrushesChild */
        "movl %eax, 4(%ecx)\n"
        "movl -0x5c(%ebp), %eax\n" /* line 373 */
        "movl -0x48(%ebp), %edi\n"
        "leal (%eax, %edi, 2), %eax\n"
        "movl %eax, -0x5c(%ebp)\n"
        "addl $1, -0x7c(%ebp)\n" /* line 329 | side */
        "cmpl $2, -0x7c(%ebp)\n" /* side */
        "jne .Lf7868a_0007894e\n"
        "movss %xmm2, 0xc(%ecx)\n" /* line 376 */
        /* } scope */
        "movl -0x4c(%ebp), %eax\n" /* line 379 | node */
        "addl $0x8c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf7868a_00078a4d:\n"
        "movaps %xmm7, %xmm2\n" /* line 209 */
        "jmp .Lf7868a_000788b0\n"
        /* } scope */
        /* { scope 2 */
        ".Lf7868a_00078a55:\n"
        "movaps %xmm7, %xmm2\n"
        "jmp .Lf7868a_000787e0\n"
        /* } scope */
        ".Lf7868a_00078a5d:\n"
        "movss -0x54(%ebp), %xmm0\n" /* line 363 | dist */
        "subss %xmm2, %xmm0\n"
        "movl -0x50(%ebp), %edx\n" /* axis */
        "movss %xmm0, -0x30(%ebp, %edx, 4)\n"
        "jmp .Lf7868a_000789a7\n"
        ".Lf7868a_00078a74:\n"
        "movl -0x7c(%ebp), %ecx\n" /* line 376 | side */
        "testl %ecx, %ecx\n"
        "je .Lf7868a_00078be7\n"
        "xorl %ecx, %ecx\n"
        "xorl %ebx, %ebx\n" /* numLeafBrushesChild */
        "jmp .Lf7868a_00078a8d\n"
        ".Lf7868a_00078a85:\n"
        "addl $1, %ecx\n" /* line 333 */
        "cmpl -0x60(%ebp), %ecx\n"
        "je .Lf7868a_00078adf\n"
        ".Lf7868a_00078a8d:\n"
        "movzwl (%esi, %ecx, 2), %edx\n" /* line 335 | leafBrushesCopy */
        "leal (%edx, %edx, 2), %eax\n" /* line 346 */
        "shll $4, %eax\n"
        "movl -0x50(%ebp), %edi\n" /* axis */
        "leal (%eax, %edi, 4), %eax\n"
        "movl 0x195eda4, %edi\n"
        "addl 0x80(%edi), %eax\n"
        "movss 0x10(%eax), %xmm0\n"
        "ucomiss -0x54(%ebp), %xmm0\n" /* dist */
        "ja .Lf7868a_00078a85\n"
        "movss -0x54(%ebp), %xmm1\n" /* line 348 | dist */
        "subss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n" /* line 45 */
        "subss %xmm2, %xmm0\n"
        "ucomiss 0x2ed5e8, %xmm0\n" /* 0.0f */
        "jb .Lf7868a_00078ae7\n"
        ".Lf7868a_00078acd:\n"
        "movl -0x5c(%ebp), %eax\n" /* line 351 */
        "movw %dx, (%eax, %ebx, 2)\n"
        "addl $1, %ebx\n" /* line 352 | numLeafBrushesChild */
        "addl $1, %ecx\n" /* line 333 */
        "cmpl -0x60(%ebp), %ecx\n"
        "jne .Lf7868a_00078a8d\n"
        ".Lf7868a_00078adf:\n"
        "movl %ebx, -0x48(%ebp)\n" /* numLeafBrushesChild */
        "jmp .Lf7868a_00078962\n"
        ".Lf7868a_00078ae7:\n"
        "jp .Lf7868a_00078acd\n" /* line 45 */
        "movaps %xmm1, %xmm2\n" /* line 333 */
        "jmp .Lf7868a_00078acd\n"
        ".Lf7868a_00078aee:\n"
        "xorl %ecx, %ecx\n" /* line 301 */
        "xorl %ebx, %ebx\n" /* numLeafBrushesChild */
        ".Lf7868a_00078af2:\n"
        "movzwl (%esi, %ecx, 2), %edx\n" /* line 303 | leafBrushesCopy */
        "leal (%edx, %edx, 2), %eax\n" /* line 304 */
        "shll $4, %eax\n"
        "movl 0x195eda4, %edi\n"
        "addl 0x80(%edi), %eax\n"
        "movl -0x50(%ebp), %edi\n" /* line 305 | axis */
        "movss (%eax, %edi, 4), %xmm0\n"
        "ucomiss -0x54(%ebp), %xmm0\n" /* dist */
        "jae .Lf7868a_00078b2c\n"
        "movss -0x54(%ebp), %xmm0\n" /* line 307 | dist */
        "ucomiss 0x10(%eax, %edi, 4), %xmm0\n"
        "jae .Lf7868a_00078b2c\n"
        "movl -0x5c(%ebp), %eax\n" /* line 309 */
        "movw %dx, (%eax, %ebx, 2)\n"
        "addl $1, %ebx\n" /* line 310 | numLeafBrushesChild */
        ".Lf7868a_00078b2c:\n"
        "addl $1, %ecx\n" /* line 301 */
        "cmpl %ecx, -0x60(%ebp)\n"
        "jne .Lf7868a_00078af2\n"
        "testl %ebx, %ebx\n" /* line 313 | numLeafBrushesChild */
        "je .Lf7868a_00078923\n"
        "movl 8(%ebp), %edx\n" /* line 315 | maxs */
        "movl %edx, (%esp)\n"
        "movl -0x64(%ebp), %ecx\n"
        "movl %ebx, %edx\n" /* numLeafBrushesChild */
        "movl -0x5c(%ebp), %eax\n"
        "calll CMod_PartionLeafBrushes_r\n"
        "movl -0x4c(%ebp), %ecx\n" /* line 317 | node */
        "movw $0xffff, 2(%ecx)\n"
        "movl 4(%eax), %ecx\n" /* line 319 */
        "movl -0x4c(%ebp), %edi\n" /* node */
        "movl %ecx, 4(%edi)\n"
        "movl -0x5c(%ebp), %eax\n" /* line 321 */
        "leal (%eax, %ebx, 2), %eax\n"
        "movl %eax, -0x5c(%ebp)\n"
        "jmp .Lf7868a_00078923\n"
        ".Lf7868a_00078b6f:\n"
        "movl -0x60(%ebp), %ecx\n" /* line 278 */
        "movl -0x4c(%ebp), %edx\n" /* node */
        "movw %cx, 2(%edx)\n"
        "movswl -0x60(%ebp), %eax\n" /* line 279 */
        "cmpl %eax, -0x60(%ebp)\n"
        "je .Lf7868a_00078b96\n"
        "movl $0x21c33c, 4(%esp)\n" /* line 280 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf7868a_00078b96:\n"
        "movl -0x60(%ebp), %eax\n" /* line 282 */
        "testl %eax, %eax\n"
        "jle .Lf7868a_00078bd0\n"
        "xorl %ebx, %ebx\n" /* numLeafBrushesChild */
        "movl -0x4c(%ebp), %esi\n" /* node, leafBrushesCopy */
        "movl 4(%esi), %ecx\n" /* leafBrushesCopy */
        "movl 0x195eda4, %esi\n" /* leafBrushesCopy */
        ".Lf7868a_00078bab:\n"
        "movl -0x5c(%ebp), %edi\n" /* line 286 */
        "movzwl (%edi, %ebx, 2), %eax\n"
        "movl 0x80(%esi), %edx\n" /* leafBrushesCopy */
        "leal (%eax, %eax, 2), %eax\n"
        "shll $4, %eax\n"
        "orl 0xc(%eax, %edx), %ecx\n"
        "movl -0x4c(%ebp), %edi\n" /* node */
        "movl %ecx, 4(%edi)\n"
        "addl $1, %ebx\n" /* line 282 | numLeafBrushesChild */
        "cmpl %ebx, -0x60(%ebp)\n" /* numLeafBrushesChild */
        "jne .Lf7868a_00078bab\n"
        ".Lf7868a_00078bd0:\n"
        "movl -0x5c(%ebp), %edx\n" /* line 291 */
        "movl -0x4c(%ebp), %eax\n" /* node */
        "movl %edx, 8(%eax)\n"
        /* } scope */
        "movl -0x4c(%ebp), %eax\n" /* line 379 | node */
        "addl $0x8c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7868a_00078be7:\n"
        "movl $0, -0x3c(%ebp)\n" /* line 333 */
        "xorl %ebx, %ebx\n" /* numLeafBrushesChild */
        "pxor %xmm3, %xmm3\n"
        ".Lf7868a_00078bf4:\n"
        "movl -0x3c(%ebp), %edx\n" /* line 335 */
        "movzwl (%esi, %edx, 2), %ecx\n" /* leafBrushesCopy */
        "movl 0x195eda4, %edi\n" /* line 340 */
        "movl 0x80(%edi), %edx\n"
        "leal (%ecx, %ecx, 2), %eax\n"
        "shll $4, %eax\n"
        "addl -0x68(%ebp), %eax\n"
        "movss (%eax, %edx), %xmm1\n"
        "movss -0x54(%ebp), %xmm0\n" /* dist */
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf7868a_00078c48\n"
        "subss %xmm0, %xmm1\n" /* line 342 */
        "movaps %xmm1, %xmm0\n" /* line 45 */
        "subss %xmm2, %xmm0\n"
        "movaps %xmm2, %xmm4\n"
        "cmpnltss %xmm3, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        "movaps %xmm0, %xmm2\n"
        "movl -0x5c(%ebp), %eax\n" /* line 351 */
        "movw %cx, (%eax, %ebx, 2)\n"
        "addl $1, %ebx\n" /* line 352 | numLeafBrushesChild */
        ".Lf7868a_00078c48:\n"
        "addl $1, -0x3c(%ebp)\n" /* line 333 */
        "movl -0x3c(%ebp), %edx\n"
        "cmpl %edx, -0x60(%ebp)\n"
        "jne .Lf7868a_00078bf4\n"
        "movl %ebx, -0x48(%ebp)\n" /* numLeafBrushesChild */
        "jmp .Lf7868a_00078962\n"
    );
}

/* line 387 */
static __attribute__((naked))
void CMod_PartionLeafBrushes(short unsigned int *leafBrushes, cLeaf_t *leaf)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 387 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl %edx, %edi\n" /* numLeafBrushes */
        "movl %ecx, -0x44(%ebp)\n"
        /* { scope 1 */
        "cmpl $0, %edx\n" /* line 396 */
        "je .Lf78c5c_00078db0\n"
        "movl $0x7f7fffff, %eax\n" /* line 191 */
        "movl %eax, -0x24(%ebp)\n" /* mins */
        "movl %eax, -0x20(%ebp)\n" /* line 192 */
        "movl %eax, -0x1c(%ebp)\n" /* line 193 */
        "movl $0xff7fffff, %eax\n" /* line 191 */
        "movl %eax, -0x30(%ebp)\n" /* maxs */
        "movl %eax, -0x2c(%ebp)\n" /* line 192 */
        "movl %eax, -0x28(%ebp)\n" /* line 193 */
        "jle .Lf78c5c_00078d01\n" /* line 405 */
        "movl 0x195eda4, %eax\n" /* line 408 */
        "movl 0x80(%eax), %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "xorl %esi, %esi\n" /* k */
        ".Lf78c5c_00078ca4:\n"
        "movl -0x40(%ebp), %edx\n"
        "movzwl (%edx, %esi, 2), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "shll $4, %eax\n"
        "movl -0x3c(%ebp), %edx\n"
        "addl %eax, %edx\n"
        "movl $1, %ebx\n"
        ".Lf78c5c_00078cbb:\n"
        "leal (, %ebx, 4), %ecx\n" /* line 387 */
        "leal -0x24(%ebp), %eax\n" /* mins */
        "addl %ecx, %eax\n"
        "movss (%edx), %xmm1\n" /* line 411 */
        "movss -4(%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf78c5c_00078cda\n"
        "movss %xmm1, -4(%eax)\n" /* line 412 */
        ".Lf78c5c_00078cda:\n"
        "leal -0x30(%ebp), %eax\n" /* line 387 | maxs */
        "addl %ecx, %eax\n"
        "movss 0x10(%edx), %xmm0\n" /* line 413 */
        "ucomiss -4(%eax), %xmm0\n"
        "jbe .Lf78c5c_00078cef\n"
        "movss %xmm0, -4(%eax)\n" /* line 414 */
        ".Lf78c5c_00078cef:\n"
        "addl $1, %ebx\n"
        "addl $4, %edx\n"
        "cmpl $4, %ebx\n" /* line 409 */
        "jne .Lf78c5c_00078cbb\n"
        "addl $1, %esi\n" /* line 405 | k */
        "cmpl %esi, %edi\n" /* k, numLeafBrushes */
        "jne .Lf78c5c_00078ca4\n"
        ".Lf78c5c_00078d01:\n"
        "movl -0x44(%ebp), %edx\n" /* line 418 | to */
        "addl $0xc, %edx\n" /* to */
        /* { scope 2 */
        "movl -0x24(%ebp), %eax\n" /* line 199 | mins */
        "movl -0x44(%ebp), %ecx\n"
        "movl %eax, 0xc(%ecx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl %ecx, %edx\n" /* line 419 | to */
        "addl $0x18, %edx\n" /* to */
        /* { scope 2 */
        "movl -0x30(%ebp), %eax\n" /* line 199 | maxs */
        "movl %eax, 0x18(%ecx)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "movl %ecx, %eax\n"
        "movl $3, %edx\n"
        "movss 0x2ed610, %xmm1\n" /* 0.125f */
        /* } scope */
        ".Lf78c5c_00078d42:\n"
        "movss 0xc(%eax), %xmm0\n" /* line 423 */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%eax)\n"
        "movss 0x18(%eax), %xmm0\n" /* line 424 */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 0x18(%eax)\n"
        "addl $4, %eax\n"
        "subl $1, %edx\n" /* line 421 */
        "jne .Lf78c5c_00078d42\n"
        "calll CM_Hunk_CheckTempMemoryHighClear\n" /* line 427 */
        "leal -0x30(%ebp), %eax\n" /* line 428 | maxs */
        "movl %eax, (%esp)\n"
        "leal -0x24(%ebp), %ecx\n" /* mins */
        "movl %edi, %edx\n" /* numLeafBrushes */
        "movl -0x40(%ebp), %eax\n"
        "calll CMod_PartionLeafBrushes_r\n"
        "movl 0x195eda4, %edx\n"
        "subl 0x30(%edx), %eax\n"
        "sarl $2, %eax\n"
        "leal (%eax, %eax, 2), %edx\n"
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "addl %ecx, %edx\n"
        "movl %edx, %ecx\n"
        "shll $8, %ecx\n"
        "addl %ecx, %edx\n"
        "movl %edx, %ecx\n"
        "shll $0x10, %ecx\n"
        "addl %ecx, %edx\n"
        "leal (%eax, %edx, 4), %edx\n"
        "movl -0x44(%ebp), %ecx\n"
        "movl %edx, 0x24(%ecx)\n"
        "calll CM_Hunk_ClearTempMemoryHigh\n" /* line 429 */
        /* } scope */
        ".Lf78c5c_00078db0:\n"
        "addl $0x4c, %esp\n" /* line 430 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1228 */
__attribute__((naked))
void CM_LoadMapFromBsp(const char *name, int usePvs)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1228 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xec, %esp\n"
        "movl 8(%ebp), %ebx\n" /* name */
        "movzbl 0xc(%ebp), %eax\n" /* usePvs */
        "movb %al, -0xc1(%ebp)\n" /* usePvs */
        /* { scope 1: in, usePvs, in, out, ... */
        "movl $0x110, 8(%esp)\n" /* line 1232 */
        "movl $0, 4(%esp)\n"
        "movl 0x195eda4, %edx\n"
        "movl %edx, (%esp)\n"
        "calll Com_Memset\n"
        "movl $0xc, 8(%esp)\n" /* line 1233 */
        "movl $0, 4(%esp)\n"
        "movl $cml, (%esp)\n"
        "calll Com_Memset\n"
        "movl $0x17, 8(%esp)\n" /* line 1235 */
        "movl $0x21c3b8, 4(%esp)\n" /* "CM_LoadMapFromBsp" */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n" /* name, count */
        "repne scasb %es:(%edi), %al\n" /* count */
        "notl %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll CM_Hunk_Alloc\n"
        "movl 0x195eda4, %edx\n"
        "movl %eax, (%edx)\n"
        "movl %ebx, 4(%esp)\n" /* line 1236 | name */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl 0x195eda4, %eax\n" /* line 1238 */
        "addl $0x10c, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Com_GetBsp\n"
        "movl %eax, %esi\n" /* usePvs */
        "movl %eax, -0xc0(%ebp)\n" /* line 1242 | header */
        "movl %eax, 0x4ea68c\n"
        /* { scope 2: count, l, l, i, ... */
        "movl 0xc(%eax), %ecx\n" /* line 55 */
        "addl %eax, %ecx\n"
        "movl %ecx, -0xbc(%ebp)\n" /* in */
        "movl 8(%eax), %ecx\n" /* line 56 */
        "movl $0x38e38e39, %ebx\n"
        "movl %ecx, %eax\n"
        "mull %ebx\n"
        "shrl $4, %edx\n"
        "leal (%edx, %edx, 8), %edx\n"
        "shll $3, %edx\n"
        "cmpl %edx, %ecx\n"
        "jne .Lf78db8_0007a4f2\n"
        "movl %ecx, %eax\n" /* line 60 */
        "mull %ebx\n"
        "movl %edx, %edi\n" /* count */
        "shrl $4, %edi\n" /* count */
        "testl %edi, %edi\n" /* line 62 | count */
        "jle .Lf78db8_0007a51a\n"
        ".Lf78db8_00078ea5:\n"
        "movl $0x17, 8(%esp)\n" /* line 66 */
        "movl $0x21c40c, 4(%esp)\n" /* "CMod_LoadMaterials" */
        "leal (%edi, %edi, 8), %ebx\n" /* count */
        "shll $3, %ebx\n"
        "leal 0x48(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_Hunk_Alloc\n"
        "addl $0x48, %eax\n"
        "movl 0x195eda4, %ecx\n"
        "movl %eax, 0x10(%ecx)\n"
        "movl %edi, 0xc(%ecx)\n" /* line 67 | count */
        "movl %ebx, 8(%esp)\n" /* line 69 */
        "movl -0xbc(%ebp), %ebx\n" /* in */
        "movl %ebx, 4(%esp)\n"
        "movl 0x10(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_Memcpy\n"
        /* } scope */
        "leal 0x28(%esi), %eax\n" /* line 1246 | usePvs */
        "movl %eax, 4(%esp)\n"
        "movl 0x4ea68c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CMod_LoadPlanes\n"
        "movzbl -0xc1(%ebp), %eax\n" /* usePvs */
        "movb %al, -0xb5(%ebp)\n" /* usePvs */
        /* { scope 2: count, l, l, i, ... */
        "leal 0x30(%esi), %ebx\n" /* line 1194 | index, sidesLump */
        /* { scope 3: inBrush, inSides, outBrush, outSides, ... */
        /* { scope 4 */
        "movl 0x3c(%esi), %eax\n" /* line 569 | j */
        "movl 0x4ea68c, %esi\n" /* j */
        "leal (%esi, %eax), %eax\n" /* j */
        "movl %eax, -0xb4(%ebp)\n" /* inBrush */
        "movl -0xc0(%ebp), %edx\n" /* line 570 | header */
        "movl 0x38(%edx), %eax\n"
        "testb $3, %al\n"
        "jne .Lf78db8_0007a533\n"
        ".Lf78db8_00078f35:\n"
        "shrl $2, %eax\n" /* line 574 */
        "movl %eax, -0xa0(%ebp)\n" /* brushCount */
        "addl 4(%ebx), %esi\n" /* line 576 | materialNum, j */
        "movl %esi, -0xb0(%ebp)\n" /* j, inSides */
        "movl -0xc0(%ebp), %ebx\n" /* line 577 | header, materialNum */
        "movl 0x30(%ebx), %edx\n" /* materialNum */
        "testb $7, %dl\n"
        "jne .Lf78db8_0007a48b\n"
        "movl %eax, %edi\n" /* index */
        "shrl $3, %edx\n" /* line 581 */
        "leal (%edi, %edi, 2), %eax\n" /* index */
        "addl %eax, %eax\n"
        "movl %edx, %ebx\n" /* line 582 | materialNum */
        "subl %eax, %ebx\n" /* materialNum */
        "js .Lf78db8_0007a4ba\n"
        ".Lf78db8_00078f6d:\n"
        "leal (, %ebx, 8), %eax\n" /* line 585 */
        "testl %ebx, %ebx\n" /* line 586 | materialNum */
        "jne .Lf78db8_0007a3c7\n"
        "xorl %eax, %eax\n"
        ".Lf78db8_00078f7e:\n"
        "movl 0x195eda4, %esi\n" /* j */
        "movl %eax, 0x18(%esi)\n" /* j */
        "movl %ebx, 0x14(%esi)\n" /* line 587 | materialNum, j */
        "movl %eax, -0xa8(%ebp)\n" /* line 589 | outSides */
        "movl $0x18, 8(%esp)\n" /* line 593 */
        "movl $0x21c47c, 4(%esp)\n" /* "CMod_LoadBrushes" */
        "movl -0xa0(%ebp), %edx\n" /* brushCount */
        "leal 3(%edx, %edx, 2), %eax\n"
        "shll $4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_Hunk_Alloc\n"
        "movl %eax, 0x80(%esi)\n" /* j */
        "movl -0xa0(%ebp), %ecx\n" /* line 594 | brushCount */
        "movw %cx, 0x7c(%esi)\n" /* j */
        "movzwl %cx, %eax\n" /* line 595 */
        "cmpl %eax, -0xa0(%ebp)\n" /* brushCount */
        "je .Lf78db8_00078fe4\n"
        "movl $0x21c490, 4(%esp)\n" /* line 596 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf78db8_00078fe4:\n"
        "movl 0x80(%esi), %ebx\n" /* line 598 | j, materialNum */
        "movl %ebx, -0xac(%ebp)\n" /* materialNum, outBrush */
        "movl -0xa0(%ebp), %eax\n" /* line 600 | brushCount */
        "testl %eax, %eax\n"
        "jle .Lf78db8_00079257\n"
        "movl $0, -0xa4(%ebp)\n" /* i */
        "movl %esi, -0xc8(%ebp)\n" /* j */
        "movl -0xac(%ebp), %edx\n" /* outBrush */
        "movl -0xac(%ebp), %ecx\n" /* outBrush */
        "movl -0xb4(%ebp), %edi\n" /* line 603 | inBrush, index */
        "movswl (%edi), %eax\n" /* index */
        "subl $6, %eax\n"
        "addl $0x1c, %edx\n" /* line 1228 */
        "movl %edx, -0x30(%ebp)\n"
        "movl %eax, 0x1c(%ecx)\n" /* line 603 */
        "testl %eax, %eax\n" /* line 604 */
        "js .Lf78db8_00079224\n"
        ".Lf78db8_00079037:\n"
        "movl -0xac(%ebp), %ebx\n" /* line 607 | outBrush, materialNum */
        "movl 0x1c(%ebx), %eax\n" /* materialNum */
        "testl %eax, %eax\n"
        "je .Lf78db8_00079249\n"
        ".Lf78db8_00079048:\n"
        "movl -0xa8(%ebp), %eax\n" /* outSides */
        ".Lf78db8_0007904e:\n"
        "movl -0xac(%ebp), %edx\n" /* outBrush */
        "movl %eax, 0x20(%edx)\n"
        "movl %edx, -0x34(%ebp)\n"
        "movl $0, -0x2c(%ebp)\n"
        "movl %edx, %ebx\n" /* materialNum */
        ".Lf78db8_00079063:\n"
        "movl -0xb0(%ebp), %ecx\n" /* line 614 | inSides */
        "movl (%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 615 */
        "movl %eax, (%ebx)\n" /* materialNum */
        "movl -0x2c(%ebp), %edi\n" /* index */
        "movl -0xac(%ebp), %eax\n" /* outBrush */
        "leal 0x24(%eax, %edi, 2), %esi\n" /* j */
        "xorl %edi, %edi\n" /* index */
        "jmp .Lf78db8_0007909f\n"
        ".Lf78db8_00079084:\n"
        "addl $6, %esi\n" /* line 608 | j */
        "testl %edi, %edi\n" /* line 614 | index */
        "je .Lf78db8_0007910a\n"
        "movl -0xb0(%ebp), %edx\n" /* line 615 | inSides */
        "movl (%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 617 */
        "movl -0x34(%ebp), %ecx\n"
        "movl %eax, 0x10(%ecx)\n"
        ".Lf78db8_0007909f:\n"
        "movl -0xb0(%ebp), %eax\n" /* line 619 | inSides */
        "movl 4(%eax), %ebx\n" /* materialNum */
        "testl %ebx, %ebx\n" /* line 620 | materialNum */
        "js .Lf78db8_000790b7\n"
        "movl -0xc8(%ebp), %edx\n"
        "cmpl 0xc(%edx), %ebx\n" /* materialNum */
        "jl .Lf78db8_000790cf\n"
        ".Lf78db8_000790b7:\n"
        "movl %ebx, 8(%esp)\n" /* line 622 | materialNum */
        "movl $0x21c4ec, 4(%esp)\n" /* "CMod_LoadBrushes: bad materialNum: %i" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf78db8_000790cf:\n"
        "movw %bx, (%esi)\n" /* line 624 | materialNum, j */
        "movswl %bx, %eax\n" /* line 625 | materialNum */
        "cmpl %eax, %ebx\n" /* materialNum */
        "je .Lf78db8_000790ed\n"
        "movl $0x21c514, 4(%esp)\n" /* line 626 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf78db8_000790ed:\n"
        "addl $1, %edi\n" /* line 611 | index */
        "addl $8, -0xb0(%ebp)\n" /* inSides */
        "cmpl $2, %edi\n" /* index */
        "jne .Lf78db8_00079084\n"
        "addl $1, -0x2c(%ebp)\n" /* line 608 */
        "addl $4, -0x34(%ebp)\n"
        "cmpl $3, -0x2c(%ebp)\n"
        "je .Lf78db8_00079112\n"
        ".Lf78db8_0007910a:\n"
        "movl -0x34(%ebp), %ebx\n" /* materialNum */
        "jmp .Lf78db8_00079063\n"
        ".Lf78db8_00079112:\n"
        "movl -0x30(%ebp), %edi\n" /* line 630 | index */
        "movl (%edi), %eax\n" /* index */
        "testl %eax, %eax\n"
        "jle .Lf78db8_0007917e\n"
        "xorl %ebx, %ebx\n" /* materialNum */
        ".Lf78db8_0007911d:\n"
        "movl -0xb0(%ebp), %ecx\n" /* line 634 | inSides */
        "movl (%ecx), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "movl 0x4ea688, %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl -0xa8(%ebp), %edi\n" /* outSides, index */
        "movl %eax, (%edi)\n" /* index */
        "movl 4(%ecx), %eax\n" /* line 636 */
        "movl %eax, 4(%edi)\n" /* index */
        "testl %eax, %eax\n" /* line 637 */
        "js .Lf78db8_0007914e\n"
        "movl -0xc8(%ebp), %edx\n"
        "cmpl 0xc(%edx), %eax\n"
        "jl .Lf78db8_00079166\n"
        ".Lf78db8_0007914e:\n"
        "movl %eax, 8(%esp)\n" /* line 639 */
        "movl $0x21c4ec, 4(%esp)\n" /* "CMod_LoadBrushes: bad materialNum: %i" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf78db8_00079166:\n"
        "addl $1, %ebx\n" /* line 630 | materialNum */
        "addl $8, -0xb0(%ebp)\n" /* inSides */
        "addl $8, -0xa8(%ebp)\n" /* outSides */
        "movl -0x30(%ebp), %ecx\n"
        "cmpl %ebx, (%ecx)\n" /* materialNum */
        "jg .Lf78db8_0007911d\n"
        ".Lf78db8_0007917e:\n"
        "movl -0xb4(%ebp), %edi\n" /* line 643 | inBrush, index */
        "movswl 2(%edi), %ebx\n" /* index, materialNum */
        "testl %ebx, %ebx\n" /* line 644 | materialNum */
        "js .Lf78db8_000791a0\n"
        "movl 0x195eda4, %eax\n"
        "movl %eax, -0xcc(%ebp)\n"
        "cmpl 0xc(%eax), %ebx\n" /* materialNum */
        "jl .Lf78db8_00079250\n"
        ".Lf78db8_000791a0:\n"
        "movl %ebx, 8(%esp)\n" /* line 646 | materialNum */
        "movl $0x21c4ec, 4(%esp)\n" /* "CMod_LoadBrushes: bad materialNum: %i" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0x195eda4, %edx\n"
        "movl %edx, -0xcc(%ebp)\n"
        "movl %edx, %ecx\n"
        ".Lf78db8_000791c6:\n"
        "movl 0x10(%ecx), %eax\n" /* line 648 */
        "leal (%ebx, %ebx, 8), %edx\n" /* materialNum */
        "movl 0x44(%eax, %edx, 8), %eax\n"
        "andl $0xdffffffb, %eax\n"
        "movl -0xac(%ebp), %ebx\n" /* outBrush, materialNum */
        "movl %eax, 0xc(%ebx)\n" /* materialNum */
        "addl $1, -0xa4(%ebp)\n" /* line 600 | i */
        "addl $0x30, %ebx\n" /* materialNum */
        "movl %ebx, -0xac(%ebp)\n" /* materialNum, outBrush */
        "addl $4, -0xb4(%ebp)\n" /* inBrush */
        "movl -0xa4(%ebp), %edi\n" /* i, index */
        "cmpl %edi, -0xa0(%ebp)\n" /* index, brushCount */
        "je .Lf78db8_00079257\n"
        "movl %ebx, %edx\n" /* materialNum */
        "movl %ebx, %ecx\n" /* materialNum */
        "movl -0xb4(%ebp), %edi\n" /* line 603 | inBrush, index */
        "movswl (%edi), %eax\n" /* index */
        "subl $6, %eax\n"
        "addl $0x1c, %edx\n" /* line 1228 */
        "movl %edx, -0x30(%ebp)\n"
        "movl %eax, 0x1c(%ecx)\n" /* line 603 */
        "testl %eax, %eax\n" /* line 604 */
        "jns .Lf78db8_00079037\n"
        ".Lf78db8_00079224:\n"
        "movl $0x21c4bc, 4(%esp)\n" /* line 605 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl -0xac(%ebp), %ebx\n" /* line 607 | outBrush, materialNum */
        "movl 0x1c(%ebx), %eax\n" /* materialNum */
        "testl %eax, %eax\n"
        "jne .Lf78db8_00079048\n"
        ".Lf78db8_00079249:\n"
        "xorl %eax, %eax\n"
        "jmp .Lf78db8_0007904e\n"
        ".Lf78db8_00079250:\n"
        "movl %eax, %ecx\n"
        "jmp .Lf78db8_000791c6\n"
        /* } scope */
        /* } scope */
        /* { scope 3: inBrush, inSides, outBrush, outSides, ... */
        ".Lf78db8_00079257:\n"
        "movl 0x4ea68c, %edi\n" /* line 825 | in */
        "movl -0xc0(%ebp), %eax\n" /* header */
        "addl 0xe4(%eax), %edi\n" /* in */
        "movl 0xe0(%eax), %eax\n" /* line 826 */
        "testb $3, %al\n"
        "jne .Lf78db8_0007a670\n"
        ".Lf78db8_00079277:\n"
        "shrl $2, %eax\n" /* line 828 */
        "movl %eax, -0x9c(%ebp)\n" /* count */
        "movl $0x18, 8(%esp)\n" /* line 831 */
        "movl $0x21c56c, 4(%esp)\n" /* "CMod_LoadLeafBrushes" */
        "movl %eax, %ebx\n" /* out */
        "leal 2(%eax, %eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_Hunk_Alloc\n"
        "movl 0x195eda4, %edx\n"
        "movl %eax, 0x38(%edx)\n"
        "movl %ebx, 0x34(%edx)\n" /* line 832 | out */
        "movl %eax, %ebx\n" /* line 834 | out */
        "movl -0x9c(%ebp), %eax\n" /* line 836 | count */
        "testl %eax, %eax\n"
        "jle .Lf78db8_000792e9\n"
        "xorl %esi, %esi\n" /* i */
        ".Lf78db8_000792b8:\n"
        "movl (%edi), %eax\n" /* line 838 | in */
        "movw %ax, (%ebx)\n" /* line 839 | out */
        "movzwl %ax, %edx\n" /* line 840 */
        "cmpl %edx, %eax\n"
        "je .Lf78db8_000792d8\n"
        "movl $0x21c584, 4(%esp)\n" /* line 841 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf78db8_000792d8:\n"
        "addl $1, %esi\n" /* line 836 | i */
        "addl $4, %edi\n" /* in */
        "addl $2, %ebx\n" /* out */
        "cmpl %esi, -0x9c(%ebp)\n" /* i, count */
        "jne .Lf78db8_000792b8\n"
        /* } scope */
        /* { scope 3: inBrush, inSides, outBrush, outSides, ... */
        ".Lf78db8_000792e9:\n"
        "movl 0x4ea68c, %ebx\n" /* line 1104 | in */
        "movl -0xc0(%ebp), %edi\n" /* header, count */
        "addl 0x11c(%edi), %ebx\n" /* count, in */
        "movl 0x118(%edi), %eax\n" /* line 1105 | count */
        "testb $0x1f, %al\n"
        "jne .Lf78db8_0007a651\n"
        ".Lf78db8_00079309:\n"
        "movl %eax, %edi\n" /* line 1107 | count */
        "shrl $5, %edi\n" /* count */
        "movl $0x1a, 8(%esp)\n" /* line 1110 */
        "movl $0x21c5e0, 4(%esp)\n" /* "CMod_LoadCollisionAabbTrees" */
        "movl %edi, %eax\n" /* count */
        "shll $5, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_Hunk_Alloc\n"
        "movl 0x195eda4, %edx\n"
        "movl %eax, 0x70(%edx)\n"
        "movl %edi, 0x6c(%edx)\n" /* line 1111 | count */
        "movl %eax, %edx\n" /* line 1120 */
        "testl %edi, %edi\n" /* line 1121 | count */
        "jle .Lf78db8_000793a5\n"
        "leal -0x1c(%ebp), %ecx\n"
        "xorl %esi, %esi\n" /* index */
        ".Lf78db8_00079342:\n"
        "movl (%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 1123 */
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 1124 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 1125 */
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 1126 */
        "movl %eax, 0xc(%edx)\n"
        "movl 0x10(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 1127 */
        "movl %eax, 0x10(%edx)\n"
        "movl 0x14(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 1128 */
        "movl %eax, 0x14(%edx)\n"
        "movzwl 0x18(%ebx), %eax\n" /* line 1129 | in */
        "movw %ax, 0x18(%edx)\n"
        "movzwl 0x1a(%ebx), %eax\n" /* line 1130 | in */
        "movw %ax, 0x1a(%edx)\n"
        "movl 0x1c(%ebx), %eax\n" /* line 1131 | in */
        "movl %eax, 0x1c(%edx)\n"
        "addl $1, %esi\n" /* line 1121 | index */
        "addl $0x20, %ebx\n" /* in */
        "addl $0x20, %edx\n"
        "cmpl %esi, %edi\n" /* index, count */
        "jne .Lf78db8_00079342\n"
        /* } scope */
        ".Lf78db8_000793a5:\n"
        "movl -0xc0(%ebp), %eax\n" /* line 1197 | header */
        "addl $0xd8, %eax\n"
        "movl %eax, -0x98(%ebp)\n" /* l */
        "movzbl -0xb5(%ebp), %esi\n" /* usePvs */
        /* { scope 3: inBrush, inSides, outBrush, outSides, ... */
        /* { scope 4 */
        "movl 0x4ea68c, %edi\n" /* line 671 | in */
        "addl 4(%eax), %edi\n" /* in */
        "movl -0xc0(%ebp), %edx\n" /* line 672 | header */
        "movl 0xd8(%edx), %ecx\n"
        "movl $0x38e38e39, %ebx\n" /* out */
        "movl %ecx, %eax\n"
        "mull %ebx\n" /* out */
        "shrl $3, %edx\n"
        "leal (%edx, %edx, 8), %edx\n"
        "shll $2, %edx\n"
        "cmpl %edx, %ecx\n"
        "jne .Lf78db8_0007a5fd\n"
        "movl %ecx, %eax\n" /* line 674 */
        "mull %ebx\n" /* out */
        "shrl $3, %edx\n"
        "movl %edx, -0x90(%ebp)\n" /* count */
        "testl %edx, %edx\n" /* line 676 */
        "jle .Lf78db8_0007a632\n"
        ".Lf78db8_00079401:\n"
        "movl %edx, %ecx\n"
        ".Lf78db8_00079403:\n"
        "movl $0x17, 8(%esp)\n" /* line 680 */
        "movl $0x21c634, 4(%esp)\n" /* "CMod_LoadLeafs" */
        "leal (%ecx, %ecx, 4), %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_Hunk_Alloc\n"
        "movl 0x195eda4, %edx\n"
        "movl %eax, 0x28(%edx)\n"
        "movl -0x90(%ebp), %ebx\n" /* line 681 | count, out */
        "movl %ebx, 0x24(%edx)\n" /* out */
        "movl %eax, %ebx\n" /* line 685 | out */
        "movl -0x90(%ebp), %eax\n" /* line 686 | count */
        "testl %eax, %eax\n"
        "jg .Lf78db8_0007a20b\n"
        /* } scope */
        /* } scope */
        ".Lf78db8_00079446:\n"
        "movl -0xc0(%ebp), %edx\n" /* line 1198 | header */
        "addl $0x120, %edx\n"
        "movl %edx, -0x8c(%ebp)\n" /* l */
        /* { scope 3: inBrush, inSides, outBrush, outSides, ... */
        /* { scope 4 */
        "movl 0x4ea68c, %esi\n" /* line 114 | in */
        "addl 4(%edx), %esi\n" /* in */
        "movl -0xc0(%ebp), %ebx\n" /* line 115 | header, j */
        "movl 0x120(%ebx), %ecx\n" /* j */
        "movl $0xaaaaaaab, %ebx\n" /* j */
        "movl %ecx, %eax\n"
        "mull %ebx\n" /* j */
        "shrl $5, %edx\n"
        "leal (%edx, %edx, 2), %edx\n"
        "shll $4, %edx\n"
        "cmpl %edx, %ecx\n"
        "jne .Lf78db8_0007a5a9\n"
        "movl %ecx, %eax\n" /* line 117 */
        "mull %ebx\n" /* j */
        "shrl $5, %edx\n"
        "movl %edx, -0x84(%ebp)\n" /* count */
        "testl %edx, %edx\n" /* line 119 */
        "jle .Lf78db8_0007a5de\n"
        ".Lf78db8_0007949c:\n"
        "movl %edx, %ecx\n"
        ".Lf78db8_0007949e:\n"
        "movl $0x18, 8(%esp)\n" /* line 123 */
        "movl $0x21c6fc, 4(%esp)\n" /* "CMod_LoadSubmodels" */
        "leal (%ecx, %ecx, 8), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_Hunk_Alloc\n"
        "movl 0x195eda4, %ebx\n" /* j */
        "movl %ebx, -0xcc(%ebp)\n" /* j */
        "movl %eax, 0x78(%ebx)\n" /* j */
        "movl -0x84(%ebp), %edi\n" /* line 124 | count */
        "movl %edi, 0x74(%ebx)\n" /* count, j */
        "cmpl $0x3ff, %edi\n" /* line 126 | count */
        "jg .Lf78db8_0007962b\n"
        "movl -0x84(%ebp), %edi\n" /* line 131 | count */
        "testl %edi, %edi\n" /* count */
        "jg .Lf78db8_0007963f\n"
        /* } scope */
        /* } scope */
        ".Lf78db8_000794ee:\n"
        "calll CM_Hunk_CheckTempMemoryClear\n" /* line 1200 */
        "calll TempMemoryReset\n" /* line 1202 */
        "movl $0, (%esp)\n" /* line 1203 */
        "calll TempMalloc\n"
        "movl 0x195eda4, %edx\n"
        "movl %edx, -0xcc(%ebp)\n"
        "subl $0x14, %eax\n"
        "movl %eax, 0x30(%edx)\n"
        /* { scope 3: inBrush, inSides, outBrush, outSides, ... */
        "movl 0x4ea68c, %esi\n" /* line 736 | contents */
        "movl -0x98(%ebp), %ecx\n" /* l */
        "movl 4(%ecx), %ebx\n" /* j */
        "addl %esi, %ebx\n" /* contents, j */
        "movl %ebx, -0x7c(%ebp)\n" /* j, in */
        "movl 0x28(%edx), %edi\n" /* line 741 | in */
        "movl %edi, -0x70(%ebp)\n" /* in, leaf */
        "movl 0x24(%edx), %ecx\n" /* line 742 */
        "testl %ecx, %ecx\n"
        "jle .Lf78db8_00079782\n"
        "movl $0, -0x80(%ebp)\n" /* i */
        "jmp .Lf78db8_000795a2\n"
        ".Lf78db8_00079544:\n"
        "xorl %esi, %esi\n" /* line 752 | contents */
        "movl -0x70(%ebp), %ecx\n" /* line 758 | leaf */
        "movl %esi, 4(%ecx)\n" /* contents */
        /* { scope 4 */
        /* { scope 5 */
        "movzwl 2(%ecx), %edi\n" /* line 445 | count */
        "testl %edi, %edi\n" /* count */
        "jg .Lf78db8_000795f8\n"
        ".Lf78db8_00079558:\n"
        "xorl %esi, %esi\n" /* contents */
        /* } scope */
        /* } scope */
        ".Lf78db8_0007955a:\n"
        "movl -0x70(%ebp), %edx\n" /* line 760 | leaf */
        "movl %esi, 8(%edx)\n" /* contents */
        "movl -0xcc(%ebp), %ecx\n" /* line 762 */
        "movl 0x38(%ecx), %eax\n"
        "movl -0x74(%ebp), %ebx\n" /* indexFirstLeafBrush, j */
        "leal (%eax, %ebx, 2), %eax\n"
        "movl %edx, %ecx\n"
        "movl -0x78(%ebp), %edx\n" /* numLeafBrushes */
        "calll CMod_PartionLeafBrushes\n"
        "addl $1, -0x80(%ebp)\n" /* line 742 | i */
        "addl $0x24, -0x7c(%ebp)\n" /* in */
        "addl $0x2c, -0x70(%ebp)\n" /* leaf */
        "movl -0x80(%ebp), %eax\n" /* i */
        "movl -0xcc(%ebp), %edi\n" /* in */
        "cmpl %eax, 0x24(%edi)\n" /* in */
        "jle .Lf78db8_0007a1f2\n"
        "movl 0x195eda4, %eax\n"
        "movl %eax, -0xcc(%ebp)\n"
        ".Lf78db8_000795a2:\n"
        "movl -0x7c(%ebp), %edx\n" /* line 745 | in */
        "movl 0x14(%edx), %edx\n"
        "movl %edx, -0x78(%ebp)\n" /* numLeafBrushes */
        "movl -0x7c(%ebp), %ecx\n" /* line 748 | in */
        "movl 0x10(%ecx), %ecx\n"
        "movl %ecx, -0x74(%ebp)\n" /* indexFirstLeafBrush */
        "testl %edx, %edx\n" /* line 752 */
        "jle .Lf78db8_00079544\n"
        "movl -0xcc(%ebp), %ebx\n" /* line 755 | j */
        "movl 0x80(%ebx), %edi\n" /* j, in */
        "movl 0x38(%ebx), %eax\n" /* j */
        "leal (%eax, %ecx, 2), %ecx\n"
        "xorl %ebx, %ebx\n" /* j */
        "xorl %esi, %esi\n" /* contents */
        ".Lf78db8_000795ce:\n"
        "movzwl (%ecx), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "shll $4, %eax\n"
        "orl 0xc(%eax, %edi), %esi\n" /* contents */
        "addl $1, %ebx\n" /* line 752 | j */
        "addl $2, %ecx\n"
        "cmpl %ebx, -0x78(%ebp)\n" /* j, numLeafBrushes */
        "jne .Lf78db8_000795ce\n"
        "movl -0x70(%ebp), %ecx\n" /* line 758 | leaf */
        "movl %esi, 4(%ecx)\n" /* contents */
        /* { scope 4 */
        /* { scope 5 */
        "movzwl 2(%ecx), %edi\n" /* line 445 | count */
        "testl %edi, %edi\n" /* count */
        "jle .Lf78db8_00079558\n"
        ".Lf78db8_000795f8:\n"
        "movl -0xcc(%ebp), %ebx\n" /* line 446 | k */
        "movl 0x10(%ebx), %edx\n" /* k */
        "movl -0x70(%ebp), %eax\n" /* leaf */
        "movzwl (%eax), %ecx\n"
        "shll $5, %ecx\n"
        "addl 0x70(%ebx), %ecx\n" /* k */
        "xorl %ebx, %ebx\n" /* k */
        "xorl %esi, %esi\n" /* contents */
        ".Lf78db8_00079611:\n"
        "movzwl 0x18(%ecx), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "orl 0x44(%edx, %eax, 8), %esi\n" /* contents */
        "addl $1, %ebx\n" /* line 445 | k */
        "addl $0x20, %ecx\n"
        "cmpl %ebx, %edi\n" /* k, count */
        "jne .Lf78db8_00079611\n"
        "jmp .Lf78db8_0007955a\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 3: inBrush, inSides, outBrush, outSides, ... */
        /* { scope 4 */
        ".Lf78db8_0007962b:\n"
        "movl $0x21c710, 4(%esp)\n" /* line 128 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf78db8_0007963f:\n"
        "movl $0, -0x88(%ebp)\n" /* line 131 | i */
        "movl $0, -0x38(%ebp)\n"
        "movl -0xcc(%ebp), %edx\n"
        ".Lf78db8_00079656:\n"
        "movl -0x38(%ebp), %edi\n" /* line 133 | count */
        "addl 0x78(%edx), %edi\n" /* count */
        "movl %edi, %ecx\n" /* count */
        "xorl %ebx, %ebx\n" /* j */
        "movss 0x2ed5d0, %xmm5\n" /* 1.0f */
        "movss 0x2f09a0, %xmm3\n"
        "pxor %xmm4, %xmm4\n"
        ".Lf78db8_00079674:\n"
        "leal (, %ebx, 4), %edx\n"
        "movl (%esi, %edx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 137 */
        "subss %xmm5, %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "movl 0xc(%esi, %edx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movss -0x1c(%ebp), %xmm2\n" /* line 138 */
        "addss %xmm5, %xmm2\n"
        "movss %xmm2, 0xc(%ecx)\n"
        "andps %xmm3, %xmm2\n" /* line 54 */
        "movss (%ecx), %xmm1\n"
        "andps %xmm3, %xmm1\n"
        /* { scope 5 */
        "movaps %xmm1, %xmm0\n" /* line 45 */
        "subss %xmm2, %xmm0\n"
        "movaps %xmm2, %xmm6\n"
        "cmpltss %xmm4, %xmm0\n"
        "andps %xmm0, %xmm6\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm6, %xmm0\n"
        /* } scope */
        "movss %xmm0, -0x28(%ebp, %edx)\n" /* line 139 */
        "addl $1, %ebx\n" /* line 135 | j */
        "addl $4, %ecx\n"
        "cmpl $3, %ebx\n" /* j */
        "jne .Lf78db8_00079674\n"
        "movss -0x28(%ebp), %xmm0\n" /* line 324 | extent */
        "movss -0x24(%ebp), %xmm1\n"
        "movss -0x20(%ebp), %xmm2\n"
        "mulss %xmm0, %xmm0\n" /* line 81 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "sqrtss %xmm0, %xmm0\n"
        "movss %xmm0, 0x18(%edi)\n" /* count */
        "movl -0x88(%ebp), %ebx\n" /* line 144 | i, j */
        "testl %ebx, %ebx\n" /* j */
        "je .Lf78db8_00079750\n"
        "movl 0x24(%esi), %eax\n" /* line 147 | in */
        "movw %ax, 0x1e(%edi)\n" /* line 148 | count */
        "movzwl %ax, %edx\n" /* line 149 */
        "cmpl %edx, %eax\n"
        "je .Lf78db8_0007972e\n"
        "movl $0x21c728, 4(%esp)\n" /* line 150 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf78db8_0007972e:\n"
        "movl 0x20(%esi), %eax\n" /* line 151 | in */
        "movw %ax, 0x1c(%edi)\n" /* line 152 | count */
        "movzwl %ax, %edx\n" /* line 153 */
        "cmpl %edx, %eax\n"
        "je .Lf78db8_00079750\n"
        "movl $0x21c754, 4(%esp)\n" /* line 154 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf78db8_00079750:\n"
        "addl $1, -0x88(%ebp)\n" /* line 131 | i */
        "addl $0x30, %esi\n" /* in */
        "addl $0x48, -0x38(%ebp)\n"
        "movl -0x88(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x84(%ebp)\n" /* count */
        "je .Lf78db8_000794ee\n"
        "movl 0x195eda4, %eax\n"
        "movl %eax, -0xcc(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lf78db8_00079656\n"
        ".Lf78db8_00079782:\n"
        "movl -0xcc(%ebp), %ebx\n" /* j */
        /* } scope */
        /* } scope */
        /* { scope 3: inBrush, inSides, outBrush, outSides, ... */
        ".Lf78db8_00079788:\n"
        "movl %esi, %eax\n" /* line 468 | j */
        "movl -0x8c(%ebp), %ecx\n" /* l */
        "addl 4(%ecx), %eax\n"
        "movl 0x74(%ebx), %edx\n" /* line 471 | firstBrush */
        "testl %edx, %edx\n"
        "jle .Lf78db8_0007986f\n"
        "addl $0x5c, %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl $0, -0x68(%ebp)\n" /* i */
        "movl $0x48, -0x40(%ebp)\n"
        "movl 0x195eda4, %edi\n" /* contents */
        "movl %edi, -0xd0(%ebp)\n" /* contents */
        "movl %edi, -0xd4(%ebp)\n" /* contents */
        "jmp .Lf78db8_000797ce\n"
        ".Lf78db8_000797c6:\n"
        "addl $0x48, -0x40(%ebp)\n" /* line 498 */
        "addl $0x30, -0x3c(%ebp)\n"
        ".Lf78db8_000797ce:\n"
        "addl $1, -0x68(%ebp)\n" /* line 471 | i */
        "movl -0x68(%ebp), %ecx\n" /* i */
        "movl -0xcc(%ebp), %edx\n"
        "cmpl %ecx, 0x74(%edx)\n"
        "jle .Lf78db8_0007986d\n"
        "movl -0x68(%ebp), %eax\n" /* line 473 | i */
        "testl %eax, %eax\n"
        "je .Lf78db8_000797c6\n"
        "movl -0x40(%ebp), %edx\n" /* line 476 */
        "movl -0xcc(%ebp), %eax\n"
        "addl 0x78(%eax), %edx\n"
        "movl %edx, -0x6c(%ebp)\n" /* out */
        "movl -0x3c(%ebp), %ecx\n" /* line 479 */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x60(%ebp)\n" /* numLeafBrushes */
        "movl $0x18, 8(%esp)\n" /* line 481 */
        "movl $0x21c788, 4(%esp)\n" /* "CMod_LoadSubmodelBrushNodes" */
        "movl %ecx, %eax\n"
        "addl %eax, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_Hunk_Alloc\n"
        "movl %eax, -0x64(%ebp)\n" /* indexes */
        "movl -0x60(%ebp), %eax\n" /* line 485 | numLeafBrushes */
        "testl %eax, %eax\n"
        "jg .Lf78db8_0007a113\n"
        "xorl %edi, %edi\n" /* contents */
        ".Lf78db8_0007982e:\n"
        "movl -0x6c(%ebp), %ebx\n" /* line 494 | out, firstBrush */
        "movl %edi, 0x20(%ebx)\n" /* contents, firstBrush */
        "addl $0x1c, %ebx\n" /* line 496 | firstBrush */
        "movl %ebx, -0x5c(%ebp)\n" /* firstBrush, leaf */
        /* { scope 4 */
        /* { scope 5 */
        "movzwl 2(%ebx), %edi\n" /* line 445 | k, count */
        "testl %edi, %edi\n" /* count */
        "jg .Lf78db8_0007a0e0\n"
        "xorl %esi, %esi\n" /* contents */
        /* } scope */
        /* } scope */
        ".Lf78db8_00079848:\n"
        "movl -0x6c(%ebp), %edi\n" /* line 496 | out, contents */
        "movl %esi, 0x24(%edi)\n" /* j, contents */
        "movl -0x5c(%ebp), %ecx\n" /* line 498 | leaf */
        "movl -0x60(%ebp), %edx\n" /* numLeafBrushes */
        "movl -0x64(%ebp), %eax\n" /* indexes */
        "calll CMod_PartionLeafBrushes\n"
        "movl -0xd4(%ebp), %eax\n"
        "movl %eax, -0xcc(%ebp)\n"
        "jmp .Lf78db8_000797c6\n"
        ".Lf78db8_0007986d:\n"
        "movl %edx, %ebx\n" /* firstBrush */
        /* } scope */
        ".Lf78db8_0007986f:\n"
        "movzwl 0x7c(%ebx), %eax\n" /* line 1285 | l */
        "leal (%eax, %eax, 2), %eax\n"
        "shll $4, %eax\n"
        "addl 0x80(%ebx), %eax\n" /* l */
        "movl %eax, 0x9c(%ebx)\n" /* l */
        "movl $0, 0x1c(%eax)\n" /* line 1286 */
        "movl 0x9c(%ebx), %eax\n" /* line 1287 | l */
        "movl $0, 0x20(%eax)\n"
        "movl 0x9c(%ebx), %eax\n" /* line 1288 | l */
        "movl $0xffffffff, 0xc(%eax)\n"
        "movl $0xffffffff, 0xc0(%ebx)\n" /* line 1289 | l */
        "movl $0, 0xc4(%ebx)\n" /* line 1290 | l */
        "movl $0x7f7fffff, %eax\n" /* line 191 */
        "movl %eax, 0xc8(%ebx)\n" /* j */
        "movl %eax, 0xcc(%ebx)\n" /* line 192 | j */
        "movl %eax, 0xd0(%ebx)\n" /* line 193 | j */
        "movl $0xff7fffff, %ebx\n" /* line 191 | j */
        "movl -0xcc(%ebp), %edi\n" /* count */
        "movl %ebx, 0xd4(%edi)\n" /* j, count */
        "movl %ebx, 0xd8(%edi)\n" /* line 192 | j, count */
        "movl %ebx, 0xdc(%edi)\n" /* line 193 | j, count */
        "movl 0x9c(%edi), %eax\n" /* line 1294 | count */
        "movw $0xffff, 0x24(%eax)\n"
        "movl 0x9c(%edi), %eax\n" /* line 1295 | count */
        "movw $0xffff, 0x26(%eax)\n"
        "movl 0x9c(%edi), %eax\n" /* line 1296 | count */
        "movw $0xffff, 0x28(%eax)\n"
        "movl 0x9c(%edi), %eax\n" /* line 1297 | count */
        "movw $0xffff, 0x2a(%eax)\n"
        "movl 0x9c(%edi), %eax\n" /* line 1298 | count */
        "movw $0xffff, 0x2c(%eax)\n"
        "movl 0x9c(%edi), %eax\n" /* line 1299 | count */
        "movw $0xffff, 0x2e(%eax)\n"
        "movl $0x14, (%esp)\n" /* line 92 */
        "calll TempMalloc\n"
        "movl $0, (%eax)\n" /* line 93 */
        "movl $0, 4(%eax)\n"
        "movl $0, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n"
        "movl %ebx, 8(%eax)\n" /* line 94 */
        "movl %eax, %ebx\n" /* line 1303 | l */
        "subl 0x30(%edi), %ebx\n" /* count, l */
        "sarl $2, %ebx\n" /* l */
        "leal (%ebx, %ebx, 2), %edx\n" /* l */
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "addl %ecx, %edx\n"
        "movl %edx, %ecx\n"
        "shll $8, %ecx\n"
        "addl %ecx, %edx\n"
        "movl %edx, %ecx\n"
        "shll $0x10, %ecx\n"
        "addl %ecx, %edx\n"
        "leal (%ebx, %edx, 4), %edx\n" /* l */
        "movl %edx, 0xe0(%edi)\n" /* count */
        "movw $1, 2(%eax)\n" /* line 1304 */
        "movl 0x34(%edi), %edx\n" /* line 1305 | count */
        "movl 0x38(%edi), %ecx\n" /* count */
        "leal (%ecx, %edx, 2), %edx\n"
        "movl %edx, 8(%eax)\n"
        "movl 0x34(%edi), %ecx\n" /* line 1306 | count */
        "movl 0x38(%edi), %edx\n" /* count */
        "movzwl 0x7c(%edi), %eax\n" /* count */
        "movw %ax, (%edx, %ecx, 2)\n"
        "addl $0x14, 0x30(%edi)\n" /* line 1209 | count */
        "movl $0, (%esp)\n" /* line 1210 */
        "calll TempMalloc\n"
        "subl 0x30(%edi), %eax\n" /* count */
        "sarl $2, %eax\n"
        "leal (%eax, %eax, 2), %ebx\n" /* sidesLump */
        "movl %ebx, %edx\n" /* sidesLump */
        "shll $4, %edx\n"
        "addl %edx, %ebx\n" /* sidesLump */
        "movl %ebx, %edx\n" /* sidesLump */
        "shll $8, %edx\n"
        "addl %edx, %ebx\n" /* sidesLump */
        "movl %ebx, %edx\n" /* sidesLump */
        "shll $0x10, %edx\n"
        "addl %edx, %ebx\n" /* sidesLump */
        "leal (%eax, %ebx, 4), %ebx\n" /* sidesLump */
        "leal 1(%ebx), %eax\n" /* line 1212 | sidesLump */
        "movl %eax, 0x2c(%edi)\n" /* count */
        "movl $0x18, 8(%esp)\n" /* line 1213 */
        "movl $0x21c7d8, 4(%esp)\n" /* "CMod_LoadBrushRelated" */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_Hunk_Alloc\n"
        "movl %eax, %esi\n" /* usePvs */
        "leal 0x14(%eax), %edx\n" /* line 1214 */
        "leal (%ebx, %ebx, 4), %ebx\n" /* sidesLump */
        "shll $2, %ebx\n" /* sidesLump */
        "movl 0x30(%edi), %eax\n" /* count */
        "movl %ebx, 8(%esp)\n" /* sidesLump */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl %esi, 0x30(%edi)\n" /* line 1215 | usePvs, count */
        "calll CM_Hunk_ClearTempMemory\n" /* line 1217 */
        /* } scope */
        /* { scope 2: count, l, l, i, ... */
        "movl 0x4ea68c, %eax\n" /* line 517 */
        "movl %eax, -0x58(%ebp)\n" /* in */
        "movl -0xc0(%ebp), %edx\n" /* header */
        "movl 0xd4(%edx), %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, -0x58(%ebp)\n" /* in */
        "movl -0xc0(%ebp), %ebx\n" /* line 518 | header, firstBrush */
        "movl 0xd0(%ebx), %ecx\n" /* firstBrush */
        "movl $0x38e38e39, %ebx\n" /* firstBrush */
        "movl %ecx, %eax\n"
        "mull %ebx\n" /* firstBrush */
        "shrl $3, %edx\n"
        "leal (%edx, %edx, 8), %edx\n"
        "shll $2, %edx\n"
        "cmpl %edx, %ecx\n"
        "jne .Lf78db8_0007a55b\n"
        "movl %ecx, %eax\n" /* line 520 */
        "mull %ebx\n" /* firstBrush */
        "shrl $3, %edx\n"
        "movl %edx, -0x4c(%ebp)\n" /* count */
        "testl %edx, %edx\n" /* line 522 */
        "jle .Lf78db8_0007a58d\n"
        ".Lf78db8_00079a75:\n"
        "movl %edx, %eax\n"
        ".Lf78db8_00079a77:\n"
        "movl $0x17, 8(%esp)\n" /* line 525 */
        "movl $0x21c804, 4(%esp)\n" /* "CMod_LoadNodes" */
        "shll $3, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_Hunk_Alloc\n"
        "movl -0xcc(%ebp), %ecx\n"
        "movl %eax, 0x20(%ecx)\n"
        "movl -0x4c(%ebp), %ebx\n" /* line 526 | count, firstBrush */
        "movl %ebx, 0x1c(%ecx)\n" /* firstBrush */
        "movl %eax, -0x54(%ebp)\n" /* line 528 | out */
        "testl %ebx, %ebx\n" /* line 530 | firstBrush */
        "jle .Lf78db8_00079b0f\n"
        "movl $0, -0x50(%ebp)\n" /* i */
        ".Lf78db8_00079aaf:\n"
        "movl -0x58(%ebp), %edi\n" /* line 532 | in, j */
        "movl (%edi), %eax\n" /* j */
        "leal (%eax, %eax, 4), %eax\n"
        "movl 0x4ea688, %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl -0x54(%ebp), %edx\n" /* out */
        "movl %eax, (%edx)\n"
        "movl %edi, %esi\n" /* j */
        "movl %edx, %ebx\n" /* firstBrush */
        "xorl %edi, %edi\n" /* j */
        ".Lf78db8_00079acb:\n"
        "movl 4(%esi), %eax\n" /* line 536 | j */
        "movw %ax, 4(%ebx)\n" /* line 537 | firstBrush */
        "movswl %ax, %edx\n" /* line 538 */
        "cmpl %edx, %eax\n"
        "je .Lf78db8_00079aed\n"
        "movl $0x21c814, 4(%esp)\n" /* line 539 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf78db8_00079aed:\n"
        "addl $1, %edi\n" /* line 533 | j */
        "addl $4, %esi\n" /* j */
        "addl $2, %ebx\n" /* firstBrush */
        "cmpl $2, %edi\n" /* j */
        "jne .Lf78db8_00079acb\n"
        "addl $1, -0x50(%ebp)\n" /* line 530 | i */
        "addl $8, -0x54(%ebp)\n" /* out */
        "addl $0x24, -0x58(%ebp)\n" /* in */
        "movl -0x50(%ebp), %ecx\n" /* i */
        "cmpl %ecx, -0x4c(%ebp)\n" /* count */
        "jne .Lf78db8_00079aaf\n"
        /* } scope */
        /* { scope 2: count, l, l, i, ... */
        ".Lf78db8_00079b0f:\n"
        "movl 0x4ea68c, %ebx\n" /* line 860 | in */
        "movl -0xc0(%ebp), %edi\n" /* header, in */
        "addl 0xec(%edi), %ebx\n" /* in */
        "movl 0xe8(%edi), %eax\n" /* line 861 | in */
        "testb $3, %al\n"
        "jne .Lf78db8_0007a428\n"
        ".Lf78db8_00079b2f:\n"
        "movl %eax, %esi\n" /* line 863 | count */
        "shrl $2, %esi\n" /* count */
        "movl $0x1a, 8(%esp)\n" /* line 866 */
        "movl $0x21c860, 4(%esp)\n" /* "CMod_LoadLeafSurfaces" */
        "leal (, %esi, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_Hunk_Alloc\n"
        "movl 0x195eda4, %edx\n"
        "movl %eax, 0x40(%edx)\n"
        "movl %esi, 0x3c(%edx)\n" /* line 867 | count */
        "movl %eax, %edx\n" /* line 868 */
        "testl %esi, %esi\n" /* line 870 | count */
        "jle .Lf78db8_00079b78\n"
        "xorl %ecx, %ecx\n"
        ".Lf78db8_00079b67:\n"
        "movl (%ebx), %eax\n" /* line 872 | in */
        "movl %eax, (%edx)\n"
        "addl $1, %ecx\n" /* line 870 */
        "addl $4, %ebx\n" /* in */
        "addl $4, %edx\n"
        "cmpl %ecx, %esi\n" /* count */
        "jne .Lf78db8_00079b67\n"
        /* } scope */
        /* { scope 2: count, l, l, i, ... */
        ".Lf78db8_00079b78:\n"
        "movl 0x4ea68c, %ebx\n" /* line 885 | in */
        "movl -0xc0(%ebp), %eax\n" /* header */
        "addl 0xf4(%eax), %ebx\n" /* in */
        "movl 0xf0(%eax), %eax\n" /* line 886 */
        "testb $0xf, %al\n"
        "jne .Lf78db8_0007a403\n"
        ".Lf78db8_00079b98:\n"
        "movl %eax, %edi\n" /* line 888 | count */
        "shrl $4, %edi\n" /* count */
        "movl $0x1a, 8(%esp)\n" /* line 891 */
        "movl $0x21c8a4, 4(%esp)\n" /* "CMod_LoadCollisionVerts" */
        "leal (%edi, %edi, 2), %eax\n" /* count */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_Hunk_Alloc\n"
        "movl 0x195eda4, %edx\n"
        "movl %eax, 0x48(%edx)\n"
        "movl %edi, 0x44(%edx)\n" /* line 892 | count */
        "movl %eax, %edx\n" /* line 897 */
        "testl %edi, %edi\n" /* line 898 | count */
        "jle .Lf78db8_00079bff\n"
        "leal -0x1c(%ebp), %ecx\n"
        "xorl %esi, %esi\n" /* index */
        ".Lf78db8_00079bd2:\n"
        "movl 4(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 900 */
        "movl %eax, (%edx)\n"
        "movl 8(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 901 */
        "movl %eax, 4(%edx)\n"
        "movl 0xc(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 902 */
        "movl %eax, 8(%edx)\n"
        "addl $1, %esi\n" /* line 898 | index */
        "addl $0x10, %ebx\n" /* in */
        "addl $0xc, %edx\n"
        "cmpl %esi, %edi\n" /* index, count */
        "jne .Lf78db8_00079bd2\n"
        /* } scope */
        /* { scope 2: count, l, l, i, ... */
        ".Lf78db8_00079bff:\n"
        "movl 0x4ea68c, %ebx\n" /* line 917 | in */
        "movl -0xc0(%ebp), %edi\n" /* header, count */
        "addl 0xfc(%edi), %ebx\n" /* count, in */
        "movl 0xf8(%edi), %ecx\n" /* line 918 | count */
        "movl %ecx, %edx\n"
        "shrl $3, %edx\n"
        "movl $0x24924925, %esi\n" /* index */
        "movl %edx, %eax\n"
        "mull %esi\n" /* index */
        "leal (, %edx, 8), %eax\n"
        "shll $6, %edx\n"
        "subl %eax, %edx\n"
        "cmpl %edx, %ecx\n"
        "jne .Lf78db8_0007a3e4\n"
        ".Lf78db8_00079c39:\n"
        "shrl $3, %ecx\n" /* line 920 */
        "movl %ecx, %eax\n"
        "mull %esi\n" /* index */
        "movl %edx, %edi\n" /* count */
        "movl $0x1a, 8(%esp)\n" /* line 923 */
        "movl $0x21c8e8, 4(%esp)\n" /* "CMod_LoadCollisionEdges" */
        "leal (%edx, %edx, 2), %eax\n"
        "shll $4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_Hunk_Alloc\n"
        "movl 0x195eda4, %edx\n"
        "movl %eax, 0x50(%edx)\n"
        "movl %edi, 0x4c(%edx)\n" /* line 924 | count */
        "movl %eax, %edx\n" /* line 941 */
        "testl %edi, %edi\n" /* line 942 | count */
        "jle .Lf78db8_00079d4b\n"
        "leal -0x1c(%ebp), %ecx\n"
        "xorl %esi, %esi\n" /* index */
        "movss 0x2ed5d0, %xmm5\n" /* 1.0f */
        ".Lf78db8_00079c83:\n"
        "movl 4(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 944 */
        "movl %eax, (%edx)\n"
        "movl 8(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 945 */
        "movl %eax, 4(%edx)\n"
        "movl 0xc(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 946 */
        "movl %eax, 8(%edx)\n"
        "movl 0x10(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 947 */
        "movl %eax, 0xc(%edx)\n"
        "movl 0x14(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 948 */
        "movl %eax, 0x10(%edx)\n"
        "movl 0x18(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 949 */
        "movl %eax, 0x14(%edx)\n"
        "movl 0x1c(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 950 */
        "movl %eax, 0x18(%edx)\n"
        "movl 0x20(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 951 */
        "movl %eax, 0x1c(%edx)\n"
        "movl 0x24(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 952 */
        "movl %eax, 0x20(%edx)\n"
        "movl 0x28(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 953 */
        "movl %eax, 0x24(%edx)\n"
        "movl 0x2c(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 954 */
        "movl %eax, 0x28(%edx)\n"
        "movl 0x30(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 955 */
        "movl %eax, 0x2c(%edx)\n"
        "movl 0x34(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movaps %xmm5, %xmm0\n" /* line 959 */
        "divss (%ecx), %xmm0\n"
        "leal 0x24(%edx), %eax\n" /* line 960 | result */
        /* { scope 3: inBrush, inSides, outBrush, outSides, ... */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss 0x24(%edx), %xmm1\n"
        "movss %xmm1, 0x24(%edx)\n"
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss 4(%eax), %xmm1\n"
        "movss %xmm1, 4(%eax)\n"
        "mulss 8(%eax), %xmm0\n" /* line 274 */
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        "addl $1, %esi\n" /* line 942 | index */
        "addl $0x38, %ebx\n" /* in */
        "addl $0x30, %edx\n"
        "cmpl %esi, %edi\n" /* index, count */
        "jne .Lf78db8_00079c83\n"
        /* } scope */
        /* { scope 2: count, l, l, i, ... */
        ".Lf78db8_00079d4b:\n"
        "movl 0x4ea68c, %edi\n" /* line 974 | in */
        "movl -0xc0(%ebp), %ecx\n" /* header */
        "addl 0x104(%ecx), %edi\n" /* in */
        "movl 0x100(%ecx), %ecx\n" /* line 975 */
        "movl $0x38e38e39, %ebx\n" /* sideIndex */
        "movl %ecx, %eax\n"
        "mull %ebx\n" /* sideIndex */
        "shrl $4, %edx\n"
        "leal (%edx, %edx, 8), %edx\n"
        "shll $3, %edx\n"
        "cmpl %edx, %ecx\n"
        "jne .Lf78db8_0007a466\n"
        ".Lf78db8_00079d7d:\n"
        "movl %ecx, %eax\n" /* line 977 */
        "mull %ebx\n" /* sideIndex */
        "shrl $4, %edx\n"
        "movl %edx, -0x44(%ebp)\n" /* count */
        "movl $0x1a, 8(%esp)\n" /* line 980 */
        "movl $0x21c930, 4(%esp)\n" /* "CMod_LoadCollisionTriangles" */
        "leal (%edx, %edx, 8), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_Hunk_Alloc\n"
        "movl 0x195eda4, %edx\n"
        "movl %eax, 0x58(%edx)\n"
        "movl -0x44(%ebp), %ecx\n" /* line 981 | count */
        "movl %ecx, 0x54(%edx)\n"
        "movl %eax, %esi\n" /* line 998 | index */
        "testl %ecx, %ecx\n" /* line 999 */
        "jle .Lf78db8_00079e89\n"
        "movl $0, -0x48(%ebp)\n" /* index */
        ".Lf78db8_00079dc5:\n"
        "movl (%edi), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1001 */
        "movl %eax, (%esi)\n" /* index */
        "movl 4(%edi), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1002 */
        "movl %eax, 4(%esi)\n" /* index */
        "movl 8(%edi), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1003 */
        "movl %eax, 8(%esi)\n" /* index */
        "movl 0xc(%edi), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1004 */
        "movl %eax, 0xc(%esi)\n" /* index */
        "movl 0x10(%edi), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1005 */
        "movl %eax, 0x10(%esi)\n" /* index */
        "movl 0x14(%edi), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1006 */
        "movl %eax, 0x14(%esi)\n" /* index */
        "movl 0x18(%edi), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1007 */
        "movl %eax, 0x18(%esi)\n" /* index */
        "movl 0x1c(%edi), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1008 */
        "movl %eax, 0x1c(%esi)\n" /* index */
        "movl 0x20(%edi), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1009 */
        "movl %eax, 0x20(%esi)\n" /* index */
        "movl 0x24(%edi), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1010 */
        "movl %eax, 0x24(%esi)\n" /* index */
        "movl 0x28(%edi), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1011 */
        "movl %eax, 0x28(%esi)\n" /* index */
        "movl 0x2c(%edi), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1012 */
        "movl %eax, 0x2c(%esi)\n" /* index */
        "movl %edi, %ecx\n" /* in */
        "movl %esi, %edx\n" /* index */
        "xorl %ebx, %ebx\n" /* sideIndex */
        ".Lf78db8_00079e59:\n"
        "movl 0x3c(%ecx), %eax\n" /* line 1016 */
        "movl %eax, 0x3c(%edx)\n"
        "movl 0x30(%ecx), %eax\n" /* line 1017 */
        "movl %eax, 0x30(%edx)\n"
        "addl $1, %ebx\n" /* line 1014 | sideIndex */
        "addl $4, %ecx\n"
        "addl $4, %edx\n"
        "cmpl $3, %ebx\n" /* sideIndex */
        "jne .Lf78db8_00079e59\n"
        "addl $1, -0x48(%ebp)\n" /* line 999 | index */
        "addl $0x48, %edi\n" /* in */
        "addl $0x48, %esi\n" /* index */
        "movl -0x48(%ebp), %ebx\n" /* index, sideIndex */
        "cmpl %ebx, -0x44(%ebp)\n" /* sideIndex, count */
        "jne .Lf78db8_00079dc5\n"
        /* } scope */
        /* { scope 2: count, l, l, i, ... */
        ".Lf78db8_00079e89:\n"
        "movl 0x4ea68c, %ebx\n" /* line 1031 | in */
        "movl -0xc0(%ebp), %edi\n" /* header, in */
        "addl 0x10c(%edi), %ebx\n" /* in */
        "movl 0x108(%edi), %ecx\n" /* line 1032 | in */
        "movl %ecx, %edx\n"
        "shrl $2, %edx\n"
        "movl $0x24924925, %esi\n" /* index */
        "movl %edx, %eax\n"
        "mull %esi\n" /* index */
        "leal (, %edx, 4), %eax\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "cmpl %edx, %ecx\n"
        "jne .Lf78db8_0007a447\n"
        ".Lf78db8_00079ec3:\n"
        "shrl $2, %ecx\n" /* line 1034 */
        "movl %ecx, %eax\n"
        "mull %esi\n" /* index */
        "movl %edx, %edi\n" /* in */
        "movl $0x1a, 8(%esp)\n" /* line 1037 */
        "movl $0x21c978, 4(%esp)\n" /* "CMod_LoadCollisionBorders" */
        "leal (, %edx, 4), %edx\n"
        "movl %edi, %eax\n" /* in */
        "shll $5, %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_Hunk_Alloc\n"
        "movl 0x195eda4, %edx\n"
        "movl %eax, 0x60(%edx)\n"
        "movl %edi, 0x5c(%edx)\n" /* line 1038 | in */
        "movl %eax, %edx\n" /* line 1046 */
        "testl %edi, %edi\n" /* line 1047 | in */
        "jle .Lf78db8_00079f61\n"
        "leal -0x1c(%ebp), %ecx\n"
        "xorl %esi, %esi\n" /* index */
        ".Lf78db8_00079f09:\n"
        "movl (%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 1049 */
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 1050 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 1051 */
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 1052 */
        "movl %eax, 0xc(%edx)\n"
        "movl 0x10(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 1053 */
        "movl %eax, 0x10(%edx)\n"
        "movl 0x14(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 1054 */
        "movl %eax, 0x14(%edx)\n"
        "movl 0x18(%ebx), %eax\n" /* in */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 1055 */
        "movl %eax, 0x18(%edx)\n"
        "addl $1, %esi\n" /* line 1047 | index */
        "addl $0x1c, %ebx\n" /* in */
        "addl $0x1c, %edx\n"
        "cmpl %esi, %edi\n" /* index, in */
        "jne .Lf78db8_00079f09\n"
        /* } scope */
        /* { scope 2: count, l, l, i, ... */
        ".Lf78db8_00079f61:\n"
        "movl 0x4ea68c, %ebx\n" /* line 1068 | in */
        "movl -0xc0(%ebp), %ecx\n" /* header */
        "addl 0x114(%ecx), %ebx\n" /* in */
        "movl %ecx, %edi\n" /* line 1069 | index */
        "movl 0x110(%ecx), %ecx\n"
        "movl $0xaaaaaaab, %esi\n" /* count */
        "movl %ecx, %eax\n"
        "mull %esi\n" /* count */
        "shrl $3, %edx\n"
        "leal (%edx, %edx, 2), %edx\n"
        "shll $2, %edx\n"
        "cmpl %edx, %ecx\n"
        "jne .Lf78db8_0007a4d3\n"
        ".Lf78db8_00079f95:\n"
        "movl %ecx, %eax\n" /* line 1071 */
        "mull %esi\n" /* count */
        "movl %edx, %esi\n" /* count */
        "shrl $3, %esi\n" /* count */
        "movl $0x1a, 8(%esp)\n" /* line 1074 */
        "movl $0x21c9c4, 4(%esp)\n" /* "CMod_LoadCollisionPartitions" */
        "leal (%esi, %esi, 2), %eax\n" /* count */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_Hunk_Alloc\n"
        "movl 0x195eda4, %ecx\n"
        "movl %ecx, -0xcc(%ebp)\n"
        "movl %eax, 0x68(%ecx)\n"
        "movl %esi, 0x64(%ecx)\n" /* line 1075 | count */
        "movl %eax, %ecx\n" /* line 1083 */
        "testl %esi, %esi\n" /* line 1084 | count */
        "jle .Lf78db8_0007a02c\n"
        "xorl %edi, %edi\n" /* index */
        ".Lf78db8_00079fd6:\n"
        "movzbl 2(%ebx), %eax\n" /* line 1086 | in */
        "movb %al, (%ecx)\n"
        "movzbl 3(%ebx), %eax\n" /* line 1087 | in */
        "movb %al, 1(%ecx)\n"
        "movl 4(%ebx), %eax\n" /* line 1088 | in */
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, -0xdc(%ebp)\n"
        "movl -0xcc(%ebp), %eax\n"
        "movl 0x58(%eax), %edx\n"
        "movl -0xdc(%ebp), %eax\n"
        "leal (%edx, %eax, 8), %edx\n"
        "movl %edx, 4(%ecx)\n"
        "movl 8(%ebx), %eax\n" /* line 1089 | in */
        "leal (, %eax, 4), %edx\n"
        "shll $5, %eax\n"
        "subl %edx, %eax\n"
        "movl -0xcc(%ebp), %edx\n"
        "addl 0x60(%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "addl $1, %edi\n" /* line 1084 | index */
        "addl $0xc, %ebx\n" /* in */
        "addl $0xc, %ecx\n"
        "cmpl %edi, %esi\n" /* index, count */
        "jne .Lf78db8_00079fd6\n"
        /* } scope */
        ".Lf78db8_0007a02c:\n"
        "cmpb $0, -0xc1(%ebp)\n" /* line 1256 | usePvs */
        "je .Lf78db8_0007a164\n"
        "movl -0xc0(%ebp), %eax\n" /* line 1258 | header, l */
        "addl $0x128, %eax\n" /* l */
        /* { scope 2: count, l, l, i, ... */
        /* { scope 3: inBrush, inSides, outBrush, outSides, ... */
        "movl -0xc0(%ebp), %ecx\n" /* line 1160 | header */
        "movl 0x128(%ecx), %edx\n"
        "testl %edx, %edx\n" /* line 1161 */
        "je .Lf78db8_0007a321\n"
        "movl 0x4ea68c, %ebx\n" /* line 1169 | buf */
        "addl 4(%eax), %ebx\n" /* buf */
        "movl -0xcc(%ebp), %eax\n" /* line 1171 */
        "movl $1, 0x90(%eax)\n"
        "movl (%ebx), %eax\n" /* line 1172 | buf */
        "movl -0xcc(%ebp), %ecx\n"
        "movl %eax, 0x84(%ecx)\n"
        "movl 4(%ebx), %eax\n" /* line 1173 | buf */
        "movl %eax, 0x88(%ecx)\n"
        "leal -8(%edx), %esi\n" /* line 1175 | index */
        "movl $9, 8(%esp)\n"
        "movl $0x21c9e4, 4(%esp)\n" /* "CMod_LoadVisibility" */
        "movl %esi, (%esp)\n" /* index */
        "calll CM_Hunk_Alloc\n"
        "movl -0xcc(%ebp), %edi\n" /* count */
        "movl %eax, 0x8c(%edi)\n" /* count */
        "movl %esi, 8(%esp)\n" /* line 1176 | index */
        "addl $8, %ebx\n" /* buf */
        "movl %ebx, 4(%esp)\n" /* buf */
        "movl %eax, (%esp)\n"
        "calll Com_Memcpy\n"
        "movl 0x195eda4, %eax\n"
        "movl %eax, -0xcc(%ebp)\n"
        "movl -0xc0(%ebp), %ebx\n" /* header, buf */
        "movl -0xc0(%ebp), %edi\n" /* header, count */
        "movl %eax, %edx\n"
        "jmp .Lf78db8_0007a182\n"
        /* } scope */
        /* } scope */
        /* { scope 2: count, l, l, i, ... */
        /* { scope 3: inBrush, inSides, outBrush, outSides, ... */
        /* { scope 4 */
        /* { scope 5 */
        ".Lf78db8_0007a0e0:\n"
        "movl 0x195eda4, %eax\n" /* line 446 */
        "movl 0x10(%eax), %ecx\n"
        "movl -0x6c(%ebp), %ebx\n" /* out, k */
        "movzwl 0x1c(%ebx), %edx\n" /* k */
        "shll $5, %edx\n"
        "addl 0x70(%eax), %edx\n"
        "xorl %ebx, %ebx\n" /* k */
        "xorl %esi, %esi\n" /* contents */
        ".Lf78db8_0007a0f9:\n"
        "movzwl 0x18(%edx), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "orl 0x44(%ecx, %eax, 8), %esi\n" /* contents */
        "addl $1, %ebx\n" /* line 445 | k */
        "addl $0x20, %edx\n"
        "cmpl %ebx, %edi\n" /* k, count */
        "jne .Lf78db8_0007a0f9\n"
        "jmp .Lf78db8_00079848\n"
        /* } scope */
        /* } scope */
        ".Lf78db8_0007a113:\n"
        "xorl %esi, %esi\n" /* line 485 | j */
        "xorl %edi, %edi\n" /* contents */
        ".Lf78db8_0007a117:\n"
        "movl %esi, %ebx\n" /* line 487 | j, firstBrush */
        "movl -0x3c(%ebp), %eax\n"
        "addl -4(%eax), %ebx\n" /* firstBrush */
        "movl -0x64(%ebp), %edx\n" /* line 488 | indexes */
        "movw %bx, (%edx, %esi, 2)\n" /* firstBrush */
        "movzwl %bx, %eax\n" /* line 489 | firstBrush */
        "cmpl %eax, %ebx\n" /* firstBrush */
        "je .Lf78db8_0007a141\n"
        "movl $0x21c7a4, 4(%esp)\n" /* line 490 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf78db8_0007a141:\n"
        "movl -0xd0(%ebp), %ecx\n" /* line 491 */
        "movl 0x80(%ecx), %edx\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* firstBrush */
        "shll $4, %eax\n"
        "orl 0xc(%eax, %edx), %edi\n" /* contents */
        "addl $1, %esi\n" /* line 485 | j */
        "cmpl %esi, -0x60(%ebp)\n" /* j, numLeafBrushes */
        "jne .Lf78db8_0007a117\n"
        "jmp .Lf78db8_0007982e\n"
        /* } scope */
        /* } scope */
        ".Lf78db8_0007a164:\n"
        "movl -0xc0(%ebp), %edx\n" /* line 1262 | header */
        "movl 0x128(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf78db8_0007a394\n"
        "movl %edx, %ebx\n" /* name */
        "movl %edx, %edi\n" /* count */
        "movl -0xcc(%ebp), %edx\n"
        ".Lf78db8_0007a182:\n"
        "addl $0x130, %ebx\n" /* line 1266 | l */
        /* { scope 2: count, l, l, i, ... */
        "movl 0x130(%edi), %eax\n" /* line 1143 | count */
        "movl %eax, 0x94(%edx)\n"
        "movl $9, 8(%esp)\n" /* line 1144 */
        "movl $0x21ca34, 4(%esp)\n" /* "CMod_LoadEntityString" */
        "movl 0x130(%edi), %eax\n" /* count */
        "movl %eax, (%esp)\n"
        "calll CM_Hunk_Alloc\n"
        "movl -0xcc(%ebp), %ecx\n"
        "movl %eax, 0x98(%ecx)\n"
        "movl 0x130(%edi), %edx\n" /* line 1145 | count */
        "movl %edx, 8(%esp)\n"
        "movl 0x4ea68c, %edx\n"
        "addl 4(%ebx), %edx\n" /* in */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Com_Memcpy\n"
        /* } scope */
        "movl $0, 0x4ea68c\n" /* line 1267 */
        /* } scope */
        "addl $0xec, %esp\n" /* line 1268 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf78db8_0007a1f2:\n"
        "movl 0x195eda4, %edx\n"
        "movl %edx, -0xcc(%ebp)\n"
        "movl 0x4ea68c, %esi\n" /* usePvs */
        "movl %edx, %ebx\n" /* l */
        "jmp .Lf78db8_00079788\n"
        /* { scope 1: in, usePvs, in, out, ... */
        /* { scope 2: count, l, l, i, ... */
        /* { scope 3: inBrush, inSides, outBrush, outSides, ... */
        /* { scope 4 */
        ".Lf78db8_0007a20b:\n"
        "movl $0, -0x94(%ebp)\n" /* line 686 | i */
        "movl %esi, %ecx\n" /* cluster */
        "testb %cl, %cl\n"
        "je .Lf78db8_0007a2be\n"
        ".Lf78db8_0007a21f:\n"
        "movl (%edi), %esi\n" /* line 691 | in, cluster */
        "movw %si, 0x28(%ebx)\n" /* line 692 | cluster, out */
        "movswl %si, %eax\n" /* line 693 | cluster */
        "cmpl %eax, %esi\n" /* cluster */
        "je .Lf78db8_0007a240\n"
        "movl $0x21c644, 4(%esp)\n" /* line 694 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf78db8_0007a240:\n"
        "movl 8(%edi), %eax\n" /* line 698 | in */
        "movw %ax, (%ebx)\n" /* line 699 | out */
        "movzwl %ax, %edx\n" /* line 700 */
        "cmpl %edx, %eax\n"
        "je .Lf78db8_0007a261\n"
        "movl $0x21c668, 4(%esp)\n" /* line 701 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf78db8_0007a261:\n"
        "movl 0xc(%edi), %eax\n" /* line 704 | in */
        "movw %ax, 2(%ebx)\n" /* line 705 | out */
        "movzwl %ax, %edx\n" /* line 706 */
        "cmpl %edx, %eax\n"
        "je .Lf78db8_0007a283\n"
        "movl $0x21c698, 4(%esp)\n" /* line 707 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf78db8_0007a283:\n"
        "movl 0x195eda4, %edx\n" /* line 711 */
        "cmpl 0x84(%edx), %esi\n" /* cluster */
        "jl .Lf78db8_0007a29a\n"
        "leal 1(%esi), %eax\n" /* line 712 | cluster */
        "movl %eax, 0x84(%edx)\n"
        ".Lf78db8_0007a29a:\n"
        "addl $1, -0x94(%ebp)\n" /* line 686 | i */
        "addl $0x24, %edi\n" /* in */
        "addl $0x2c, %ebx\n" /* out */
        "movl -0x94(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x90(%ebp)\n" /* count */
        "jne .Lf78db8_0007a21f\n"
        "jmp .Lf78db8_00079446\n"
        ".Lf78db8_0007a2be:\n"
        "movl 8(%edi), %eax\n" /* line 698 | in */
        "movw %ax, (%ebx)\n" /* line 699 | out */
        "movzwl %ax, %edx\n" /* line 700 */
        "cmpl %edx, %eax\n"
        "je .Lf78db8_0007a2df\n"
        "movl $0x21c668, 4(%esp)\n" /* line 701 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf78db8_0007a2df:\n"
        "movl 0xc(%edi), %eax\n" /* line 704 | in */
        "movw %ax, 2(%ebx)\n" /* line 705 | out */
        "movzwl %ax, %edx\n" /* line 706 */
        "cmpl %edx, %eax\n"
        "je .Lf78db8_0007a301\n"
        "movl $0x21c698, 4(%esp)\n" /* line 707 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf78db8_0007a301:\n"
        "addl $1, -0x94(%ebp)\n" /* line 686 | i */
        "addl $0x24, %edi\n" /* in */
        "addl $0x2c, %ebx\n" /* out */
        "movl -0x94(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x90(%ebp)\n" /* count */
        "jne .Lf78db8_0007a2be\n"
        "jmp .Lf78db8_00079446\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: count, l, l, i, ... */
        /* { scope 3: inBrush, inSides, outBrush, outSides, ... */
        ".Lf78db8_0007a321:\n"
        "movl -0xcc(%ebp), %ebx\n" /* line 1163 | buf */
        "movl 0x84(%ebx), %eax\n" /* buf */
        "addl $0x1f, %eax\n"
        "andl $0xffffffe0, %eax\n"
        "movl %eax, 0x88(%ebx)\n" /* buf */
        "movl $9, 8(%esp)\n" /* line 1164 */
        "movl $0x21c9e4, 4(%esp)\n" /* "CMod_LoadVisibility" */
        "movl %eax, (%esp)\n"
        "calll CM_Hunk_Alloc\n"
        "movl %eax, 0x8c(%ebx)\n" /* buf */
        "movl 0x88(%ebx), %edx\n" /* line 1165 | buf */
        "movl %edx, 8(%esp)\n"
        "movl $0xff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Com_Memset\n"
        "movl 0x195eda4, %edi\n" /* count */
        "movl %edi, -0xcc(%ebp)\n" /* count */
        "movl -0xc0(%ebp), %ebx\n" /* header, buf */
        "movl -0xc0(%ebp), %edi\n" /* header, count */
        "movl -0xcc(%ebp), %edx\n"
        "jmp .Lf78db8_0007a182\n"
        /* } scope */
        /* } scope */
        ".Lf78db8_0007a394:\n"
        "movl $0x21c9f8, 4(%esp)\n" /* line 1263 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0x195eda4, %ecx\n"
        "movl %ecx, -0xcc(%ebp)\n"
        "movl -0xc0(%ebp), %ebx\n" /* header, name */
        "movl -0xc0(%ebp), %edi\n" /* header, count */
        "movl %ecx, %edx\n"
        "jmp .Lf78db8_0007a182\n"
        /* { scope 2: count, l, l, i, ... */
        /* { scope 3: inBrush, inSides, outBrush, outSides, ... */
        /* { scope 4 */
        ".Lf78db8_0007a3c7:\n"
        "movl $0x18, 8(%esp)\n" /* line 586 */
        "movl $0x21c468, 4(%esp)\n" /* "CMod_LoadBrushSides" */
        "movl %eax, (%esp)\n"
        "calll CM_Hunk_Alloc\n"
        "jmp .Lf78db8_00078f7e\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: count, l, l, i, ... */
        ".Lf78db8_0007a3e4:\n"
        "movl $0x21c8bc, 4(%esp)\n" /* line 919 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0xf8(%edi), %ecx\n" /* count */
        "jmp .Lf78db8_00079c39\n"
        /* } scope */
        /* { scope 2: count, l, l, i, ... */
        ".Lf78db8_0007a403:\n"
        "movl $0x21c878, 4(%esp)\n" /* line 887 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl -0xc0(%ebp), %ecx\n" /* header */
        "movl 0xf0(%ecx), %eax\n"
        "jmp .Lf78db8_00079b98\n"
        /* } scope */
        /* { scope 2: count, l, l, i, ... */
        ".Lf78db8_0007a428:\n"
        "movl $0x21c838, 4(%esp)\n" /* line 862 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0xe8(%edi), %eax\n" /* in */
        "jmp .Lf78db8_00079b2f\n"
        /* } scope */
        /* { scope 2: count, l, l, i, ... */
        ".Lf78db8_0007a447:\n"
        "movl $0x21c94c, 4(%esp)\n" /* line 1033 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0x108(%edi), %ecx\n" /* in */
        "jmp .Lf78db8_00079ec3\n"
        /* } scope */
        /* { scope 2: count, l, l, i, ... */
        ".Lf78db8_0007a466:\n"
        "movl $0x21c900, 4(%esp)\n" /* line 976 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl -0xc0(%ebp), %edx\n" /* header */
        "movl 0x100(%edx), %ecx\n"
        "jmp .Lf78db8_00079d7d\n"
        /* } scope */
        /* { scope 2: count, l, l, i, ... */
        /* { scope 3: inBrush, inSides, outBrush, outSides, ... */
        /* { scope 4 */
        ".Lf78db8_0007a48b:\n"
        "movl $0x21c420, 4(%esp)\n" /* line 579 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0x30(%ebx), %edx\n" /* materialNum */
        "movl -0xa0(%ebp), %edi\n" /* brushCount, index */
        "shrl $3, %edx\n" /* line 581 */
        "leal (%edi, %edi, 2), %eax\n" /* index */
        "addl %eax, %eax\n"
        "movl %edx, %ebx\n" /* line 582 | materialNum */
        "subl %eax, %ebx\n" /* materialNum */
        "jns .Lf78db8_00078f6d\n"
        ".Lf78db8_0007a4ba:\n"
        "movl $0x21c444, 4(%esp)\n" /* line 583 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf78db8_00078f6d\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: count, l, l, i, ... */
        ".Lf78db8_0007a4d3:\n"
        "movl $0x21c994, 4(%esp)\n" /* line 1070 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0x110(%edi), %ecx\n" /* index */
        "jmp .Lf78db8_00079f95\n"
        /* } scope */
        /* { scope 2: count, l, l, i, ... */
        ".Lf78db8_0007a4f2:\n"
        "movl $0x21c3cc, 4(%esp)\n" /* line 58 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 8(%esi), %ecx\n"
        "movl %ecx, %eax\n" /* line 60 */
        "mull %ebx\n"
        "movl %edx, %edi\n" /* count */
        "shrl $4, %edi\n" /* count */
        "testl %edi, %edi\n" /* line 62 | count */
        "jg .Lf78db8_00078ea5\n"
        ".Lf78db8_0007a51a:\n"
        "movl $0x21c3f4, 4(%esp)\n" /* line 63 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf78db8_00078ea5\n"
        /* } scope */
        /* { scope 2: count, l, l, i, ... */
        /* { scope 3: inBrush, inSides, outBrush, outSides, ... */
        /* { scope 4 */
        ".Lf78db8_0007a533:\n"
        "movl $0x21c420, 4(%esp)\n" /* line 572 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0x4ea68c, %esi\n" /* j */
        "movl -0xc0(%ebp), %ecx\n" /* header */
        "movl 0x38(%ecx), %eax\n"
        "jmp .Lf78db8_00078f35\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: count, l, l, i, ... */
        ".Lf78db8_0007a55b:\n"
        "movl $0x21c2f4, 4(%esp)\n" /* line 519 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl -0xc0(%ebp), %edx\n" /* header */
        "movl 0xd0(%edx), %ecx\n"
        "movl %ecx, %eax\n" /* line 520 */
        "mull %ebx\n" /* firstBrush */
        "shrl $3, %edx\n"
        "movl %edx, -0x4c(%ebp)\n" /* count */
        "testl %edx, %edx\n" /* line 522 */
        "jg .Lf78db8_00079a75\n"
        ".Lf78db8_0007a58d:\n"
        "movl $0x21c7f0, 4(%esp)\n" /* line 523 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl -0x4c(%ebp), %eax\n" /* count */
        "jmp .Lf78db8_00079a77\n"
        /* } scope */
        /* { scope 2: count, l, l, i, ... */
        /* { scope 3: inBrush, inSides, outBrush, outSides, ... */
        /* { scope 4 */
        ".Lf78db8_0007a5a9:\n"
        "movl $0x21c6c0, 4(%esp)\n" /* line 116 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl -0xc0(%ebp), %edx\n" /* header */
        "movl 0x120(%edx), %ecx\n"
        "movl %ecx, %eax\n" /* line 117 */
        "mull %ebx\n" /* j */
        "shrl $5, %edx\n"
        "movl %edx, -0x84(%ebp)\n" /* count */
        "testl %edx, %edx\n" /* line 119 */
        "jg .Lf78db8_0007949c\n"
        ".Lf78db8_0007a5de:\n"
        "movl $0x21c6e8, 4(%esp)\n" /* line 120 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl -0x84(%ebp), %ecx\n" /* count */
        "jmp .Lf78db8_0007949e\n"
        /* } scope */
        /* } scope */
        /* { scope 3: inBrush, inSides, outBrush, outSides, ... */
        /* { scope 4 */
        ".Lf78db8_0007a5fd:\n"
        "movl $0x21c5fc, 4(%esp)\n" /* line 673 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl -0xc0(%ebp), %edx\n" /* header */
        "movl 0xd8(%edx), %ecx\n"
        "movl %ecx, %eax\n" /* line 674 */
        "mull %ebx\n" /* out */
        "shrl $3, %edx\n"
        "movl %edx, -0x90(%ebp)\n" /* count */
        "testl %edx, %edx\n" /* line 676 */
        "jg .Lf78db8_00079401\n"
        ".Lf78db8_0007a632:\n"
        "movl $0x21c620, 4(%esp)\n" /* line 677 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl -0x90(%ebp), %ecx\n" /* count */
        "jmp .Lf78db8_00079403\n"
        /* } scope */
        /* } scope */
        /* { scope 3: inBrush, inSides, outBrush, outSides, ... */
        ".Lf78db8_0007a651:\n"
        "movl $0x21c5b0, 4(%esp)\n" /* line 1106 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0x118(%edi), %eax\n" /* count */
        "jmp .Lf78db8_00079309\n"
        /* } scope */
        /* { scope 3: inBrush, inSides, outBrush, outSides, ... */
        ".Lf78db8_0007a670:\n"
        "movl $0x21c544, 4(%esp)\n" /* line 827 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl -0xc0(%ebp), %ecx\n" /* header */
        "movl 0xe0(%ecx), %eax\n"
        "jmp .Lf78db8_00079277\n"
    );
}

