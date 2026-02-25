/* ASM dump from: cm_staticmodel.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/cm_staticmodel.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

float * CM_Hunk_AllocXModel(int size);
static float * CM_Hunk_AllocXModelColl(int size);
struct XModel * CM_XModelPrecache(const char *name);
float CM_TraceStaticModel(cStaticModel_t *sm, trace_t *results, const vec_t *start, const vec_t *end, int contentmask);
qboolean CM_TraceStaticModelComplete(cStaticModel_t *sm, const vec_t *start, const vec_t *end, int contentmask);

/* line 16 */
__attribute__((naked))
float * CM_Hunk_AllocXModel(int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 16 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 19 */
        "jmp Hunk_AllocInternal\n" /* line 18 */
    );
}

/* line 27 */
static __attribute__((naked))
float * CM_Hunk_AllocXModelColl(int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 27 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 30 */
        "jmp Hunk_AllocInternal\n" /* line 29 */
    );
}

/* line 38 */
__attribute__((naked))
struct XModel * CM_XModelPrecache(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 38 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $CM_Hunk_AllocXModelColl, 8(%esp)\n" /* line 40 */
        "movl $CM_Hunk_AllocXModel, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* name */
        "movl %eax, (%esp)\n"
        "calll XModelPrecache\n"
        "leave\n" /* line 41 */
        "retl\n"
    );
}

/* line 51 */
__attribute__((naked))
float CM_TraceStaticModel(cStaticModel_t *sm, trace_t *results, const vec_t *start, const vec_t *end, int contentmask)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 51 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* sm */
        "movl 0x10(%ebp), %eax\n" /* start */
        "movl 0x14(%ebp), %esi\n" /* end */
        /* { scope 1 */
        "movss (%eax), %xmm0\n" /* line 248 */
        "subss 8(%ebx), %xmm0\n" /* sm */
        "movss %xmm0, -0x3c(%ebp)\n" /* delta */
        "movss 4(%eax), %xmm0\n" /* line 249 */
        "subss 0xc(%ebx), %xmm0\n" /* sm */
        "movss %xmm0, -0x38(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 250 */
        "subss 0x10(%ebx), %xmm0\n" /* sm */
        "movss %xmm0, -0x34(%ebp)\n"
        "leal 0x14(%ebx), %eax\n" /* line 61 | sm */
        "movl %eax, -0x4c(%ebp)\n"
        "leal -0x30(%ebp), %edx\n" /* localStart */
        "movl %edx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x3c(%ebp), %edi\n" /* delta */
        "movl %edi, (%esp)\n"
        "calll MatrixTransformVector\n"
        "movss (%esi), %xmm0\n" /* line 248 | end */
        "subss 8(%ebx), %xmm0\n" /* sm */
        "movss %xmm0, -0x3c(%ebp)\n" /* delta */
        "movss 4(%esi), %xmm0\n" /* line 249 | end */
        "subss 0xc(%ebx), %xmm0\n" /* sm */
        "movss %xmm0, -0x38(%ebp)\n"
        "movss 8(%esi), %xmm0\n" /* line 250 | end */
        "subss 0x10(%ebx), %xmm0\n" /* sm */
        "movss %xmm0, -0x34(%ebp)\n"
        "leal -0x24(%ebp), %esi\n" /* line 64 | localEnd, end */
        "movl %esi, 8(%esp)\n" /* end */
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll MatrixTransformVector\n"
        "movl 4(%ebx), %eax\n" /* line 66 | sm */
        "movl %eax, (%esp)\n"
        "calll XModelGetBasePose\n"
        "movl 0x18(%ebp), %edx\n" /* line 67 | contentmask */
        "movl %edx, 0x14(%esp)\n"
        "movl %esi, 0x10(%esp)\n" /* end */
        "leal -0x30(%ebp), %edx\n" /* localStart */
        "movl %edx, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* results */
        "movl %eax, 4(%esp)\n"
        "movl 4(%ebx), %eax\n" /* sm */
        "movl %eax, (%esp)\n"
        "calll XModelTraceLine\n"
        "testl %eax, %eax\n"
        "js .Lfbde00_000bdf16\n"
        "movl 0xc(%ebp), %edx\n" /* line 71 | results */
        "movw $0x3fe, 0x1c(%edx)\n"
        "movl %edx, %ebx\n" /* line 74 | sm */
        "addl $4, %ebx\n" /* sm */
        "leal -0x48(%ebp), %esi\n" /* normal, end */
        "movl %esi, 8(%esp)\n" /* end */
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* sm */
        "calll MatrixTransposeTransformVector\n"
        "movl %esi, (%esp)\n" /* line 75 | end */
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movl -0x48(%ebp), %eax\n" /* line 199 | normal */
        "movl 0xc(%ebp), %edx\n" /* results */
        "movl %eax, 4(%edx)\n"
        "movl -0x44(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n" /* sm */
        "movl -0x40(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n" /* sm */
        /* } scope */
        ".Lfbde00_000bdf16:\n"
        "addl $0x6c, %esp\n" /* line 77 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 85 */
__attribute__((naked))
qboolean CM_TraceStaticModelComplete(cStaticModel_t *sm, const vec_t *start, const vec_t *end, int contentmask)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 85 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* sm */
        "movl 0xc(%ebp), %eax\n" /* start */
        "movl 0x10(%ebp), %esi\n" /* end */
        /* { scope 1 */
        "movss (%eax), %xmm0\n" /* line 248 */
        "subss 8(%ebx), %xmm0\n" /* sm */
        "movss %xmm0, -0x3c(%ebp)\n" /* delta */
        "movss 4(%eax), %xmm0\n" /* line 249 */
        "subss 0xc(%ebx), %xmm0\n" /* sm */
        "movss %xmm0, -0x38(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 250 */
        "subss 0x10(%ebx), %xmm0\n" /* sm */
        "movss %xmm0, -0x34(%ebp)\n"
        "leal 0x14(%ebx), %edi\n" /* line 95 | sm */
        "leal -0x30(%ebp), %eax\n" /* localStart */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "leal -0x3c(%ebp), %edx\n" /* delta */
        "movl %edx, (%esp)\n"
        "calll MatrixTransformVector\n"
        "movss (%esi), %xmm0\n" /* line 248 | end */
        "subss 8(%ebx), %xmm0\n" /* sm */
        "movss %xmm0, -0x3c(%ebp)\n" /* delta */
        "movss 4(%esi), %xmm0\n" /* line 249 | end */
        "subss 0xc(%ebx), %xmm0\n" /* sm */
        "movss %xmm0, -0x38(%ebp)\n"
        "movss 8(%esi), %xmm0\n" /* line 250 | end */
        "subss 0x10(%ebx), %xmm0\n" /* sm */
        "movss %xmm0, -0x34(%ebp)\n"
        "leal -0x24(%ebp), %esi\n" /* line 98 | localEnd, end */
        "movl %esi, 8(%esp)\n" /* end */
        "movl %edi, 4(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* delta */
        "movl %eax, (%esp)\n"
        "calll MatrixTransformVector\n"
        "movl $0x3f800000, -0x60(%ebp)\n" /* line 100 | results */
        "movl 4(%ebx), %eax\n" /* line 102 | sm */
        "movl %eax, (%esp)\n"
        "calll XModelGetBasePose\n"
        "movl 0x14(%ebp), %edx\n" /* line 103 | contentmask */
        "movl %edx, 0x14(%esp)\n"
        "movl %esi, 0x10(%esp)\n" /* end */
        "leal -0x30(%ebp), %edx\n" /* localStart */
        "movl %edx, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x60(%ebp), %eax\n" /* results */
        "movl %eax, 4(%esp)\n"
        "movl 4(%ebx), %eax\n" /* sm */
        "movl %eax, (%esp)\n"
        "calll XModelTraceLine\n"
        "shrl $0x1f, %eax\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 104 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

