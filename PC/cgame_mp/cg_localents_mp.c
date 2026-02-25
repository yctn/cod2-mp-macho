/* ASM dump from: cg_localents_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_localents_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

extern localEntity_t cg_eachClientActiveLocalEntities[1]; /* 0x0 */
extern localEntity_t * cg_eachClientFreeLocalEntities[1]; /* 0x0 */
extern localEntity_t *cg_localEntities; /* 0x0 */
extern localEntity_t *cg_activeLocalEntities; /* 0x0 */
extern localEntity_t *cg_freeLocalEntities; /* 0x0 */
static cg_eachClientLocalEntities_t cg_eachClientLocalEntities; /* 0xfead80 */

void CG_InitLocalEntities(void);
void CG_AddMovingTracer(localEntity_t *le);
static void __static_initialization_and_destruction_0(void);
static void GLOBAL__I_cg_eachClientActiveLocalEntities(void); /* global constructors keyed to cg_eachClientActiveLocalEntities */
localEntity_t * CG_AllocLocalEntity(void);
void CG_AddLocalEntities(void);

/* line 50 */
__attribute__((naked))
void CG_InitLocalEntities(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 50 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x5e00, 8(%esp)\n" /* line 54 */
        "movl $0, 4(%esp)\n"
        "movl cg_localEntities, %eax\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl cg_activeLocalEntities, %eax\n" /* line 55 */
        "movl %eax, 4(%eax)\n"
        "movl cg_activeLocalEntities, %eax\n" /* line 56 */
        "movl %eax, (%eax)\n"
        "movl cg_localEntities, %eax\n" /* line 57 */
        "movl %eax, cg_freeLocalEntities\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lf1dd7c0_001dd805\n"
        ".Lf1dd7c0_001dd800:\n"
        "movl cg_localEntities, %eax\n"
        ".Lf1dd7c0_001dd805:\n"
        "leal (%ecx, %eax), %edx\n" /* line 59 */
        "leal 0xbc(%edx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "addl $0xbc, %ecx\n"
        "cmpl $0x5d44, %ecx\n" /* line 58 */
        "jne .Lf1dd7c0_001dd800\n"
        "leave\n" /* line 60 */
        "retl\n"
    );
}

/* line 103 */
__attribute__((naked))
void CG_AddMovingTracer(localEntity_t *le)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 103 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x40, %esp\n"
        "movl 8(%ebp), %ebx\n" /* le */
        /* { scope 1 */
        "leal -0x14(%ebp), %esi\n" /* line 113 | start */
        "movl %esi, 8(%esp)\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x10(%ebx), %eax\n" /* le */
        "movl %eax, (%esp)\n"
        "calll BG_EvaluateTrajectory\n"
        "leal -0x2c(%ebp), %eax\n" /* line 115 | dir */
        "movl %eax, 4(%esp)\n"
        "leal 0x28(%ebx), %eax\n" /* le */
        "movl %eax, (%esp)\n"
        "calll Vec3NormalizeTo\n"
        "fstp %st(0)\n"
        "leal 0x1c(%ebx), %eax\n" /* le */
        /* { scope 2 */
        "movss -0x14(%ebp), %xmm5\n" /* line 248 | start */
        "movss -0x10(%ebp), %xmm6\n" /* line 249 */
        "movss -0xc(%ebp), %xmm7\n" /* line 250 */
        /* } scope */
        "movss -0x2c(%ebp), %xmm3\n" /* line 304 | dir */
        "movss -0x28(%ebp), %xmm4\n"
        "movaps %xmm5, %xmm1\n" /* line 120 */
        "subss 0x1c(%ebx), %xmm1\n" /* le */
        "mulss %xmm3, %xmm1\n"
        "movaps %xmm6, %xmm0\n"
        "subss 4(%eax), %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movaps %xmm7, %xmm0\n"
        "subss 8(%eax), %xmm0\n"
        "mulss -0x24(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x44(%ebx), %xmm2\n" /* le */
        "subss %xmm1, %xmm2\n"
        "movl 0x195f948, %eax\n" /* line 122 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "minss %xmm0, %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        "mulss %xmm2, %xmm3\n" /* line 288 */
        "addss %xmm3, %xmm5\n"
        "movss %xmm5, -0x20(%ebp)\n" /* end */
        "mulss %xmm2, %xmm4\n" /* line 289 */
        "addss %xmm4, %xmm6\n"
        "movss %xmm6, -0x1c(%ebp)\n"
        "mulss -0x24(%ebp), %xmm0\n" /* line 290 */
        "addss %xmm0, %xmm7\n"
        "movss %xmm7, -0x18(%ebp)\n"
        "leal -0x20(%ebp), %eax\n" /* line 125 | end */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll CG_DrawTracer\n"
        /* } scope */
        "addl $0x40, %esp\n" /* line 126 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 157 */
static __attribute__((naked))
void __static_initialization_and_destruction_0(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 157 */
        "movl %esp, %ebp\n"
        "cmpl $0xffff, %edx\n" /* line 15 */
        "je .Lf1dd90a_001dd917\n"
        ".Lf1dd90a_001dd915:\n"
        "popl %ebp\n" /* line 157 */
        "retl\n"
        ".Lf1dd90a_001dd917:\n"
        "subl $1, %eax\n" /* line 15 */
        "jne .Lf1dd90a_001dd915\n"
        "movl cg_eachClientFreeLocalEntities, %eax\n"
        "movl %eax, cg_freeLocalEntities\n"
        "popl %ebp\n" /* line 157 */
        "retl\n"
    );
}

/* line 158 */
static __attribute__((naked))
void GLOBAL__I_cg_eachClientActiveLocalEntities(void) /* global constructors keyed to cg_eachClientActiveLocalEntities */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 158 */
        "movl %esp, %ebp\n"
        "movl $0xffff, %edx\n"
        "movl $1, %eax\n"
        "popl %ebp\n"
        "jmp __static_initialization_and_destruction_0\n"
    );
}

/* line 78 */
__attribute__((naked))
localEntity_t * CG_AllocLocalEntity(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 78 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl cg_freeLocalEntities, %ecx\n" /* line 82 */
        "testl %ecx, %ecx\n"
        "je .Lf1dd93c_001dd99f\n"
        "movl cg_freeLocalEntities, %ebx\n" /* le */
        ".Lf1dd93c_001dd953:\n"
        "movl 4(%ebx), %eax\n" /* line 90 | le */
        "movl %eax, cg_freeLocalEntities\n"
        "movl $0xbc, 8(%esp)\n" /* line 92 */
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* le */
        "calll memset\n"
        "movl cg_activeLocalEntities, %eax\n" /* line 95 */
        "movl 4(%eax), %eax\n"
        "movl %eax, 4(%ebx)\n" /* le */
        "movl cg_activeLocalEntities, %eax\n" /* line 96 */
        "movl %eax, (%ebx)\n" /* le */
        "movl cg_activeLocalEntities, %eax\n" /* line 97 */
        "movl 4(%eax), %eax\n"
        "movl %ebx, (%eax)\n" /* le */
        "movl cg_activeLocalEntities, %eax\n" /* line 98 */
        "movl %ebx, 4(%eax)\n" /* le */
        /* } scope */
        "movl %ebx, %eax\n" /* line 100 | le */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1dd93c_001dd99f:\n"
        "movl cg_activeLocalEntities, %eax\n" /* line 86 */
        "movl (%eax), %ebx\n" /* le */
        /* { scope 2 */
        "movl (%ebx), %edx\n" /* line 65 */
        "testl %edx, %edx\n"
        "je .Lf1dd93c_001dd9c9\n"
        ".Lf1dd93c_001dd9ac:\n"
        "movl (%ebx), %edx\n" /* line 69 */
        "movl 4(%ebx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 70 */
        "movl %edx, (%eax)\n"
        "movl cg_freeLocalEntities, %eax\n" /* line 73 */
        "movl %eax, 4(%ebx)\n"
        "movl %ebx, cg_freeLocalEntities\n" /* line 74 */
        "jmp .Lf1dd93c_001dd953\n"
        ".Lf1dd93c_001dd9c9:\n"
        "movl $0x2ade80, 4(%esp)\n" /* line 66 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1dd93c_001dd9ac\n"
    );
}

/* line 129 */
__attribute__((naked))
void CG_AddLocalEntities(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 129 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl cg_activeLocalEntities, %eax\n" /* line 135 */
        "movl (%eax), %ebx\n" /* le */
        "movl 0x195f584, %edi\n"
        "cmpl cg_activeLocalEntities, %ebx\n" /* line 136 | le */
        "je .Lf1dd9e0_001dda3b\n"
        ".Lf1dd9e0_001dd9fe:\n"
        "movl (%ebx), %esi\n" /* line 138 | le, next */
        "movl %esi, %edx\n" /* next */
        "movl (%edi), %eax\n" /* line 149 */
        "movl 0x25bb0(%eax), %eax\n"
        "cmpl 0xc(%ebx), %eax\n" /* le */
        "jge .Lf1dd9e0_001dda14\n"
        "cmpl 0x14(%ebx), %eax\n" /* le */
        "jge .Lf1dd9e0_001dda43\n"
        ".Lf1dd9e0_001dda14:\n"
        "testl %esi, %esi\n" /* line 65 */
        "je .Lf1dd9e0_001dda4f\n"
        ".Lf1dd9e0_001dda18:\n"
        "movl 4(%ebx), %eax\n" /* line 69 */
        "movl %eax, 4(%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 70 */
        "movl %edx, (%eax)\n"
        "movl cg_freeLocalEntities, %eax\n" /* line 73 */
        "movl %eax, 4(%ebx)\n"
        "movl %ebx, cg_freeLocalEntities\n" /* line 74 */
        "movl %esi, %ebx\n" /* line 155 | next, le */
        ".Lf1dd9e0_001dda33:\n"
        "cmpl cg_activeLocalEntities, %ebx\n" /* line 136 | le */
        "jne .Lf1dd9e0_001dd9fe\n"
        /* } scope */
        ".Lf1dd9e0_001dda3b:\n"
        "addl $0x1c, %esp\n" /* line 157 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1dd9e0_001dda43:\n"
        "movl %ebx, (%esp)\n" /* line 155 | le */
        "calll CG_AddMovingTracer\n"
        "movl %esi, %ebx\n" /* next, le */
        "jmp .Lf1dd9e0_001dda33\n"
        ".Lf1dd9e0_001dda4f:\n"
        "movl $0x2ade80, 4(%esp)\n" /* line 66 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl (%ebx), %edx\n"
        "jmp .Lf1dd9e0_001dda18\n"
    );
}

