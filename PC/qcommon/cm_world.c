/* ASM dump from: cm_world.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/cm_world.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/com_vector.h"
 */

static struct cm_world_t cm_world; /* 0x4ed880 */

void CM_UnlinkEntity(svEntity_t *ent);
static void CM_AreaEntities_r(void);
int CM_AreaEntities(const vec_t *mins, const vec_t *maxs, int *entityList, int maxcount, int contentmask);
static int CM_PointSightTraceToEntities_r(const vec_t *p2);
int CM_PointSightTraceToEntities(sightpointtrace_t *clip);
static qboolean CM_PointTraceStaticModelsComplete_r(const vec_t *p2);
qboolean CM_PointTraceStaticModelsComplete(const vec_t *start, const vec_t *end, int contentmask);
static int CM_ClipSightTraceToEntities_r(const vec_t *p2);
int CM_ClipSightTraceToEntities(sightclip_t *clip);
static void CM_PointTraceStaticModels_r(locTraceWork_t *tw, const vec_t *p2, trace_t *trace);
void CM_PointTraceStaticModels(trace_t *results, const vec_t *start, const vec_t *end, int contentmask);
static void CM_PointTraceToEntities_r(const vec_t *p2, trace_t *trace);
void CM_PointTraceToEntities(pointtrace_t *clip, trace_t *trace);
static void CM_ClipMoveToEntities_r(const vec_t *p2, trace_t *trace);
void CM_ClipMoveToEntities(moveclip_t *clip, trace_t *trace);
static void CM_SortNode(short unsigned int nodeIndex, vec_t *mins, vec_t *maxs);
void CM_LinkWorld(void);
void CM_LinkEntity(svEntity_t *ent, vec_t *absmin, vec_t *absmax, clipHandle_t clipHandle);

/* line 454 */
__attribute__((naked))
void CM_UnlinkEntity(svEntity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 454 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 462 | ent */
        "movzwl (%eax), %ebx\n" /* nodeIndex */
        "testw %bx, %bx\n" /* line 463 | nodeIndex */
        "je .Lfafba0_000afd13\n"
        "movl %eax, %edx\n"
        "movzwl %bx, %eax\n" /* line 465 | nodeIndex */
        "leal (%eax, %eax, 2), %eax\n"
        "leal 0x4ed89c(, %eax, 8), %edi\n" /* node */
        "movw $0, (%edx)\n" /* line 466 */
        "movzwl 8(%edi), %eax\n" /* line 470 | node */
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl 0x195ee80, %esi\n" /* contents */
        "movl %esi, -0x1c(%ebp)\n" /* contents */
        "leal 0x22a4(%esi, %edx, 4), %ecx\n" /* contents */
        "cmpl %ecx, 8(%ebp)\n" /* ent */
        "jne .Lfafba0_000afbf9\n"
        "jmp .Lfafba0_000afd1b\n"
        ".Lfafba0_000afbf4:\n"
        "movl %eax, %ecx\n" /* line 478 */
        "movl -0x1c(%ebp), %esi\n" /* contents */
        ".Lfafba0_000afbf9:\n"
        "movzwl 2(%ecx), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "leal 0x22a4(%esi, %edx, 4), %eax\n" /* contents */
        "cmpl %eax, 8(%ebp)\n" /* ent */
        "jne .Lfafba0_000afbf4\n"
        "movl 8(%ebp), %edx\n" /* line 480 | ent */
        "movzwl 2(%edx), %eax\n"
        "movw %ax, 2(%ecx)\n"
        ".Lfafba0_000afc1e:\n"
        "movl 8(%edi), %edx\n" /* line 487 | node */
        "testl %edx, %edx\n"
        "jne .Lfafba0_000afc74\n"
        ".Lfafba0_000afc25:\n"
        "movl 0x14(%edi), %eax\n" /* node */
        "testl %eax, %eax\n"
        "jne .Lfafba0_000afc74\n"
        "movl $0, 4(%edi)\n" /* line 490 | node */
        "movzwl 0x12(%edi), %edx\n" /* line 492 | node */
        "testw %dx, %dx\n"
        "je .Lfafba0_000afc74\n"
        "movzwl 0x4ed89a, %eax\n" /* line 500 */
        "movw %ax, 0x12(%edi)\n" /* node */
        "movw %bx, 0x4ed89a\n" /* line 501 | nodeIndex */
        "movzwl %dx, %eax\n" /* line 503 */
        "leal (%eax, %eax, 2), %eax\n"
        "leal 0x4ed89c(, %eax, 8), %edi\n" /* node */
        "cmpw 0x14(%edi), %bx\n" /* line 505 | node, nodeIndex */
        "je .Lfafba0_000afd06\n"
        "movw $0, 0x16(%edi)\n" /* line 512 | node */
        "movl %edx, %ebx\n" /* nodeIndex */
        ".Lfafba0_000afc6d:\n"
        "movl 8(%edi), %edx\n" /* line 487 | node */
        "testl %edx, %edx\n"
        "je .Lfafba0_000afc25\n"
        ".Lfafba0_000afc74:\n"
        "movzwl 0x14(%edi), %edx\n" /* line 520 | node */
        "leal (%edx, %edx, 2), %edx\n"
        "movzwl 0x16(%edi), %eax\n" /* node */
        "leal (%eax, %eax, 2), %eax\n"
        "movl 0x4ed8a0(, %edx, 8), %esi\n" /* contents */
        "orl 0x4ed8a0(, %eax, 8), %esi\n" /* contents */
        "movzwl 8(%edi), %eax\n" /* line 521 | node */
        "testw %ax, %ax\n"
        "je .Lfafba0_000afce8\n"
        "movzwl %ax, %eax\n" /* line 523 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl 0x195ee80, %eax\n"
        "leal 0x22a4(%eax, %edx, 4), %ebx\n" /* nodeIndex */
        "jmp .Lfafba0_000afcd1\n"
        ".Lfafba0_000afcb4:\n"
        "movzwl %ax, %edx\n"
        "leal (%edx, %edx, 2), %edx\n"
        "movl %edx, %eax\n"
        "shll $5, %eax\n"
        "subl %edx, %eax\n"
        "leal 0x229c(, %eax, 4), %eax\n"
        "addl 0x195ee80, %eax\n"
        "leal 8(%eax), %ebx\n" /* nodeIndex */
        ".Lfafba0_000afcd1:\n"
        "movl %ebx, (%esp)\n" /* line 525 | nodeIndex */
        "calll SV_GEntityForSvEntity\n"
        "orl 0x11c(%eax), %esi\n" /* contents */
        "movzwl 2(%ebx), %eax\n" /* line 526 | nodeIndex */
        "testw %ax, %ax\n"
        "jne .Lfafba0_000afcb4\n"
        ".Lfafba0_000afce8:\n"
        "movl %esi, 4(%edi)\n" /* line 530 | contents, node */
        "movzwl 0x12(%edi), %eax\n" /* line 532 | node */
        "testw %ax, %ax\n" /* line 533 */
        "je .Lfafba0_000afd13\n"
        "movzwl %ax, %eax\n" /* line 536 */
        "leal (%eax, %eax, 2), %eax\n"
        "leal 0x4ed89c(, %eax, 8), %edi\n" /* node */
        "jmp .Lfafba0_000afc74\n"
        ".Lfafba0_000afd06:\n"
        "movw $0, 0x14(%edi)\n" /* line 507 | node */
        "movl %edx, %ebx\n" /* line 512 | nodeIndex */
        "jmp .Lfafba0_000afc6d\n"
        /* } scope */
        ".Lfafba0_000afd13:\n"
        "addl $0x2c, %esp\n" /* line 538 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfafba0_000afd1b:\n"
        "movzwl 2(%ecx), %eax\n" /* line 472 */
        "movw %ax, 8(%edi)\n" /* node */
        "jmp .Lfafba0_000afc1e\n"
    );
}

/* line 927 */
static __attribute__((naked))
void CM_AreaEntities_r(void)
{
    __asm__ __volatile__ (
        ".Lfafd28_000afd28:\n"
        "pushl %ebp\n" /* line 927 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %edx, %esi\n" /* ap */
        /* { scope 1 */
        "movzwl %ax, %eax\n" /* line 934 */
        "leal (%eax, %eax, 2), %eax\n"
        "leal 0x4ed89c(, %eax, 8), %ebx\n" /* node */
        "movl 4(%ebx), %eax\n" /* line 935 | node */
        "testl %eax, 0x18(%edx)\n"
        "je .Lfafd28_000afd75\n"
        "movzwl 8(%ebx), %eax\n" /* line 938 | node */
        "testw %ax, %ax\n"
        "jne .Lfafd28_000afd8f\n"
        "movzwl 0x10(%ebx), %edx\n" /* line 959 | node */
        "movl 8(%esi), %eax\n" /* ap */
        "movss (%eax, %edx, 4), %xmm0\n"
        "ucomiss 0xc(%ebx), %xmm0\n" /* node */
        "ja .Lfafd28_000afe91\n"
        ".Lfafd28_000afd67:\n"
        "movl 4(%esi), %eax\n" /* line 961 | ap */
        "movss 0xc(%ebx), %xmm0\n" /* node */
        "ucomiss (%eax, %edx, 4), %xmm0\n"
        "ja .Lfafd28_000afd7d\n"
        /* } scope */
        ".Lfafd28_000afd75:\n"
        "addl $0x2c, %esp\n" /* line 963 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfafd28_000afd7d:\n"
        "movzwl 0x16(%ebx), %eax\n" /* line 962 | node */
        "movl %esi, %edx\n" /* ap */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 963 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CM_AreaEntities_r\n" /* line 962 */
        ".Lfafd28_000afd8f:\n"
        "movl 0x195ee80, %edx\n"
        "movl %edx, -0x24(%ebp)\n"
        "movl %edx, %ecx\n"
        "addl $0x2418, %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        ".Lfafd28_000afda3:\n"
        "movzwl %ax, %eax\n" /* line 940 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl -0x24(%ebp), %eax\n"
        "leal 0x22a4(%eax, %edx, 4), %edi\n" /* check */
        "movl %edi, (%esp)\n" /* line 941 | check */
        "calll SV_GEntityForSvEntity\n"
        "movl %eax, %edx\n"
        "movl 0x11c(%eax), %eax\n" /* line 942 */
        "testl %eax, 0x18(%esi)\n" /* ap */
        "je .Lfafd28_000afe6e\n"
        "movl 8(%esi), %eax\n" /* line 945 | ap */
        "movss 0x120(%edx), %xmm0\n"
        "ucomiss (%eax), %xmm0\n"
        "ja .Lfafd28_000afe6e\n"
        "movl 4(%esi), %ecx\n" /* ap */
        "movss (%ecx), %xmm0\n"
        "ucomiss 0x12c(%edx), %xmm0\n"
        "ja .Lfafd28_000afe6e\n"
        "movss 0x124(%edx), %xmm0\n"
        "ucomiss 4(%eax), %xmm0\n"
        "ja .Lfafd28_000afe6e\n"
        "movss 4(%ecx), %xmm0\n"
        "ucomiss 0x130(%edx), %xmm0\n"
        "ja .Lfafd28_000afe6e\n"
        "movss 0x128(%edx), %xmm0\n"
        "ucomiss 8(%eax), %xmm0\n"
        "ja .Lfafd28_000afe6e\n"
        "movss 8(%ecx), %xmm0\n"
        "ucomiss 0x134(%edx), %xmm0\n"
        "ja .Lfafd28_000afe6e\n"
        "movl 0x10(%esi), %edx\n" /* line 948 | ap */
        "movl %edx, -0x20(%ebp)\n"
        "cmpl 0x14(%esi), %edx\n" /* ap */
        "je .Lfafd28_000afeb7\n"
        "movl %edi, %edx\n" /* line 954 | check */
        "subl -0x1c(%ebp), %edx\n"
        "sarl $2, %edx\n"
        "movl %edx, %eax\n"
        "shll $6, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, %ecx\n"
        "shll $0xa, %ecx\n"
        "addl %ecx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "shll $6, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl -0x20(%ebp), %ecx\n"
        "movl 0xc(%esi), %edx\n" /* ap */
        "movl %eax, (%edx, %ecx, 4)\n"
        "addl $1, 0x10(%esi)\n" /* line 955 | ap */
        ".Lfafd28_000afe6e:\n"
        "movzwl 2(%edi), %eax\n" /* line 938 | check */
        "testw %ax, %ax\n"
        "jne .Lfafd28_000afda3\n"
        "movzwl 0x10(%ebx), %edx\n" /* line 959 | node */
        "movl 8(%esi), %eax\n" /* ap */
        "movss (%eax, %edx, 4), %xmm0\n"
        "ucomiss 0xc(%ebx), %xmm0\n" /* node */
        "jbe .Lfafd28_000afd67\n"
        ".Lfafd28_000afe91:\n"
        "movzwl 0x14(%ebx), %eax\n" /* line 960 | node */
        "movl %esi, %edx\n" /* ap */
        "calll CM_AreaEntities_r\n"
        "movzwl 0x10(%ebx), %edx\n" /* node */
        "movl 4(%esi), %eax\n" /* line 961 | ap */
        "movss 0xc(%ebx), %xmm0\n" /* node */
        "ucomiss (%eax, %edx, 4), %xmm0\n"
        "jbe .Lfafd28_000afd75\n"
        "jmp .Lfafd28_000afd7d\n"
        ".Lfafd28_000afeb7:\n"
        "movl $0x21e994, (%esp)\n" /* line 950 */
        "calll Com_DPrintf\n"
        "jmp .Lfafd28_000afd75\n"
    );
}

/* line 971 */
__attribute__((naked))
int CM_AreaEntities(const vec_t *mins, const vec_t *maxs, int *entityList, int maxcount, int contentmask)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 971 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 976 | mins */
        "movl %eax, -0x24(%ebp)\n"
        "movl 0xc(%ebp), %eax\n" /* line 977 | maxs */
        "movl %eax, -0x20(%ebp)\n"
        "movl 0x10(%ebp), %eax\n" /* line 978 | entityList */
        "movl %eax, -0x1c(%ebp)\n"
        "movl $0, -0x18(%ebp)\n" /* line 979 */
        "movl 0x14(%ebp), %eax\n" /* line 980 | maxcount */
        "movl %eax, -0x14(%ebp)\n"
        "movl 0x18(%ebp), %eax\n" /* line 981 | contentmask */
        "movl %eax, -0x10(%ebp)\n"
        "leal -0x28(%ebp), %edx\n" /* line 983 | ap */
        "movl $1, %eax\n"
        "calll CM_AreaEntities_r\n"
        "movl -0x18(%ebp), %eax\n"
        /* } scope */
        "leave\n" /* line 987 */
        "retl\n"
    );
}

/* line 1511 */
static __attribute__((naked))
int CM_PointSightTraceToEntities_r(const vec_t *p2)
{
    __asm__ __volatile__ (
        ".Lfaff06_000aff06:\n"
        "pushl %ebp\n" /* line 1511 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, %esi\n" /* clip */
        "movl 8(%ebp), %edi\n" /* p2 */
        /* { scope 1 */
        "movzwl %dx, %edx\n" /* line 1523 | nodeIndex */
        "leal (%edx, %edx, 2), %edx\n" /* nodeIndex */
        "leal 0x4ed89c(, %edx, 8), %ebx\n" /* node */
        "movl 4(%ebx), %eax\n" /* line 1524 | node */
        "testl %eax, 0x20(%esi)\n" /* clip */
        "je .Lfaff06_000aff9e\n"
        "movzwl 0x10(%ebx), %eax\n" /* line 1527 | node */
        "shll $2, %eax\n"
        "movss 0xc(%ebx), %xmm0\n" /* node */
        "movss (%eax, %ecx), %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "movss (%eax, %edi), %xmm3\n" /* line 1528 */
        "subss %xmm0, %xmm3\n"
        "movaps %xmm2, %xmm0\n" /* line 1530 */
        "mulss %xmm3, %xmm0\n"
        "pxor %xmm4, %xmm4\n"
        "ucomiss %xmm4, %xmm0\n"
        "jb .Lfaff06_000affe2\n"
        "movaps %xmm3, %xmm0\n" /* line 45 */
        "subss %xmm2, %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "cmpltss %xmm4, %xmm0\n"
        "andps %xmm0, %xmm1\n"
        "andnps %xmm2, %xmm0\n"
        "orps %xmm1, %xmm0\n"
        "xorl %edx, %edx\n" /* line 1532 | nodeIndex */
        "ucomiss %xmm0, %xmm4\n"
        "setbe %dl\n" /* nodeIndex */
        "movl $1, %eax\n"
        "subl %edx, %eax\n" /* nodeIndex */
        "movzwl 0x14(%ebx, %eax, 2), %edx\n" /* node, nodeIndex */
        "movl %edi, (%esp)\n" /* p2 */
        "movl %esi, %eax\n" /* clip */
        "calll CM_PointSightTraceToEntities_r\n"
        "testl %eax, %eax\n" /* line 1533 */
        "jne .Lfaff06_000affa0\n"
        ".Lfaff06_000aff95:\n"
        "movzwl 8(%ebx), %eax\n" /* line 1556 | node */
        "testw %ax, %ax\n"
        "jne .Lfaff06_000affa8\n"
        ".Lfaff06_000aff9e:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lfaff06_000affa0:\n"
        "addl $0x3c, %esp\n" /* line 1565 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfaff06_000affa8:\n"
        "movzwl %ax, %edx\n" /* line 1558 | nodeIndex */
        "leal (%edx, %edx, 2), %edx\n" /* nodeIndex */
        "movl %edx, %eax\n" /* nodeIndex */
        "shll $5, %eax\n"
        "subl %edx, %eax\n" /* nodeIndex */
        "leal 0x229c(, %eax, 4), %eax\n"
        "addl 0x195ee80, %eax\n"
        "leal 8(%eax), %ebx\n" /* node */
        "movl %ebx, 4(%esp)\n" /* line 1559 | node */
        "movl %esi, (%esp)\n" /* clip */
        "calll SV_PointSightTraceToEntity\n"
        "testl %eax, %eax\n" /* line 1560 */
        "jne .Lfaff06_000affa0\n"
        "movzwl 2(%ebx), %eax\n" /* line 1556 | node */
        "testw %ax, %ax\n"
        "jne .Lfaff06_000affa8\n"
        "xorl %eax, %eax\n"
        "jmp .Lfaff06_000affa0\n"
        ".Lfaff06_000affe2:\n"
        "movaps %xmm2, %xmm0\n" /* line 1538 */
        "subss %xmm3, %xmm0\n"
        "divss %xmm0, %xmm2\n"
        "movss (%ecx), %xmm1\n" /* line 1542 | p1 */
        "movss (%edi), %xmm0\n" /* p2 */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n" /* mid */
        "movss 4(%ecx), %xmm1\n" /* line 1543 | p1 */
        "movss 4(%edi), %xmm0\n" /* p2 */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "movss 8(%ecx), %xmm1\n" /* line 1544 | p1 */
        "movss 8(%edi), %xmm0\n" /* p2 */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "xorl %eax, %eax\n" /* line 96 */
        "ucomiss %xmm3, %xmm4\n"
        "setbe %al\n"
        "movl %eax, -0x2c(%ebp)\n" /* side */
        "movzwl 0x14(%ebx, %eax, 2), %edx\n" /* line 1548 | node, nodeIndex */
        "leal -0x24(%ebp), %eax\n" /* mid */
        "movl %eax, (%esp)\n"
        "movl %esi, %eax\n" /* clip */
        "calll CM_PointSightTraceToEntities_r\n"
        "testl %eax, %eax\n" /* line 1549 */
        "jne .Lfaff06_000affa0\n"
        "movb $1, %al\n" /* line 1551 */
        "subl -0x2c(%ebp), %eax\n" /* side */
        "movzwl 0x14(%ebx, %eax, 2), %edx\n" /* node, nodeIndex */
        "movl %edi, (%esp)\n" /* p2 */
        "leal -0x24(%ebp), %ecx\n" /* mid, p1 */
        "movl %esi, %eax\n" /* clip */
        "calll CM_PointSightTraceToEntities_r\n"
        "testl %eax, %eax\n" /* line 1552 */
        "je .Lfaff06_000aff95\n"
        "jmp .Lfaff06_000affa0\n"
    );
}

/* line 1573 */
__attribute__((naked))
int CM_PointSightTraceToEntities(sightpointtrace_t *clip)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1573 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* clip */
        "leal 0xc(%eax), %edx\n" /* line 1579 */
        "movl %edx, 8(%ebp)\n" /* clip */
        "movl %eax, %ecx\n"
        "movl $1, %edx\n"
        "popl %ebp\n" /* line 1583 */
        "jmp CM_PointSightTraceToEntities_r\n" /* line 1579 */
    );
}

/* line 1098 */
static __attribute__((naked))
qboolean CM_PointTraceStaticModelsComplete_r(const vec_t *p2)
{
    __asm__ __volatile__ (
        ".Lfb00a0_000b00a0:\n"
        "pushl %ebp\n" /* line 1098 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %eax, %edi\n" /* clip */
        /* { scope 1 */
        "movl (%ecx), %eax\n" /* line 199 */
        "movl %eax, -0x30(%ebp)\n" /* p1 */
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, -0x28(%ebp)\n"
        "jmp .Lfb00a0_000b0123\n"
        ".Lfb00a0_000b00be:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 1128 | node */
        "movss 0xc(%eax), %xmm0\n"
        "movzwl 0x10(%eax), %eax\n"
        "movss -0x30(%ebp, %eax, 4), %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "movl 8(%ebp), %ecx\n" /* line 1129 | p2, p1_ */
        "movss (%ecx, %eax, 4), %xmm3\n" /* p1_ */
        "subss %xmm0, %xmm3\n"
        "movaps %xmm2, %xmm0\n" /* line 1131 */
        "mulss %xmm3, %xmm0\n"
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lfb00a0_000b01c8\n"
        "movaps %xmm3, %xmm0\n" /* line 45 */
        "subss %xmm2, %xmm0\n"
        "movaps %xmm3, %xmm4\n"
        "cmpltss %xmm1, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm2, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        "xorl %eax, %eax\n" /* line 1133 */
        "ucomiss %xmm0, %xmm1\n"
        "setbe %al\n"
        "movl $1, %edx\n" /* nodeIndex */
        "subl %eax, %edx\n" /* nodeIndex */
        "movl -0x3c(%ebp), %ecx\n" /* node, p1_ */
        "movzwl 0x14(%ecx, %edx, 2), %edx\n" /* p1_, nodeIndex */
        ".Lfb00a0_000b0123:\n"
        "movzwl %dx, %eax\n" /* line 1113 | nodeIndex */
        "leal (%eax, %eax, 2), %eax\n"
        "leal 0x4ed890(, %eax, 8), %eax\n"
        "leal 0xc(%eax), %edx\n" /* nodeIndex */
        "movl %edx, -0x3c(%ebp)\n" /* nodeIndex, node */
        "movl 0xc(%eax), %eax\n" /* line 1114 */
        "testl %eax, 0x24(%edi)\n" /* clip */
        "je .Lfb00a0_000b028b\n"
        ".Lfb00a0_000b0142:\n"
        "movzwl 0xa(%edx), %eax\n" /* line 1117 | nodeIndex */
        "testw %ax, %ax\n"
        "je .Lfb00a0_000b00be\n"
        "jmp .Lfb00a0_000b01a1\n"
        ".Lfb00a0_000b0151:\n"
        "movl $0x3f800000, 0xc(%esp)\n" /* line 1122 */
        "leal -0xc(%ebx), %eax\n" /* side */
        "movl %eax, 8(%esp)\n"
        "leal -0x18(%ebx), %eax\n" /* side */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* clip */
        "calll CM_TraceBox\n"
        "testl %eax, %eax\n"
        "jne .Lfb00a0_000b0195\n"
        "movl 0x24(%edi), %eax\n" /* line 1124 | clip */
        "movl %eax, 0xc(%esp)\n"
        "leal 0xc(%edi), %eax\n" /* clip */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* clip */
        "movl %esi, (%esp)\n" /* check */
        "calll CM_TraceStaticModelComplete\n"
        "testl %eax, %eax\n"
        "je .Lfb00a0_000b0298\n"
        ".Lfb00a0_000b0195:\n"
        "movzwl (%esi), %eax\n" /* line 1117 | check */
        "testw %ax, %ax\n"
        "je .Lfb00a0_000b00be\n"
        ".Lfb00a0_000b01a1:\n"
        "movzwl %ax, %eax\n" /* line 1119 */
        "leal (%eax, %eax, 4), %ebx\n" /* side */
        "shll $4, %ebx\n" /* side */
        "movl 0x195eda4, %ecx\n" /* p1_ */
        "addl 8(%ecx), %ebx\n" /* p1_, side */
        "leal -0x50(%ebx), %esi\n" /* side, check */
        "movl 4(%esi), %eax\n" /* line 1120 | check */
        "movl %eax, (%esp)\n"
        "calll XModelGetContents\n"
        "testl %eax, 0x24(%edi)\n" /* clip */
        "je .Lfb00a0_000b0195\n"
        "jmp .Lfb00a0_000b0151\n"
        ".Lfb00a0_000b01c8:\n"
        "movaps %xmm2, %xmm0\n" /* line 1138 */
        "subss %xmm3, %xmm0\n"
        "divss %xmm0, %xmm2\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 1142 | p1 */
        "movss (%ecx), %xmm0\n" /* p1_ */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n" /* mid */
        "movss -0x2c(%ebp), %xmm1\n" /* line 1143 */
        "movss 4(%ecx), %xmm0\n" /* p1_ */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "movss -0x28(%ebp), %xmm1\n" /* line 1144 */
        "movss 8(%ecx), %xmm0\n" /* p1_ */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "pxor %xmm0, %xmm0\n" /* line 96 */
        "xorl %ebx, %ebx\n"
        "ucomiss %xmm3, %xmm0\n"
        "setbe %bl\n"
        "movl -0x3c(%ebp), %eax\n" /* line 1148 | node */
        "movzwl 0x14(%eax, %ebx, 2), %edx\n" /* nodeIndex */
        "leal -0x24(%ebp), %eax\n" /* mid */
        "movl %eax, (%esp)\n"
        "leal -0x30(%ebp), %ecx\n" /* p1, p1_ */
        "movl %edi, %eax\n" /* clip */
        "calll CM_PointTraceStaticModelsComplete_r\n"
        "testl %eax, %eax\n"
        "je .Lfb00a0_000b0298\n"
        "movl $1, %eax\n" /* line 1151 */
        "subl %ebx, %eax\n" /* side */
        "movl -0x3c(%ebp), %ecx\n" /* node, p1_ */
        "movzwl 0x14(%ecx, %eax, 2), %edx\n" /* p1_, nodeIndex */
        "movl -0x24(%ebp), %eax\n" /* line 199 | mid */
        "movl %eax, -0x30(%ebp)\n" /* p1 */
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x28(%ebp)\n"
        "movzwl %dx, %eax\n" /* line 1113 | nodeIndex */
        "leal (%eax, %eax, 2), %eax\n"
        "leal 0x4ed890(, %eax, 8), %eax\n"
        "leal 0xc(%eax), %edx\n" /* nodeIndex */
        "movl %edx, -0x3c(%ebp)\n" /* nodeIndex, node */
        "movl 0xc(%eax), %eax\n" /* line 1114 */
        "testl %eax, 0x24(%edi)\n" /* clip */
        "jne .Lfb00a0_000b0142\n"
        ".Lfb00a0_000b028b:\n"
        "movl $1, %eax\n" /* line 1153 */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1154 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfb00a0_000b0298:\n"
        "xorl %eax, %eax\n" /* line 1153 */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1154 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1162 */
__attribute__((naked))
qboolean CM_PointTraceStaticModelsComplete(const vec_t *start, const vec_t *end, int contentmask)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1162 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x44, %esp\n"
        "movl 8(%ebp), %edx\n" /* start */
        "movl 0xc(%ebp), %ecx\n" /* end */
        /* { scope 1 */
        "movl 0x10(%ebp), %eax\n" /* line 1169 | contentmask */
        "movl %eax, -0xc(%ebp)\n"
        "movl (%edx), %eax\n" /* line 199 */
        "movl %eax, -0x30(%ebp)\n" /* clip */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x28(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 199 */
        "movl %eax, -0x24(%ebp)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, -0x20(%ebp)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n"
        "leal -0x30(%ebp), %ebx\n" /* line 1173 | clip */
        "movl %ebx, (%esp)\n"
        "calll CM_CalcTraceEntents\n"
        "leal -0x24(%ebp), %eax\n" /* line 1175 */
        "movl %eax, (%esp)\n"
        "movl %ebx, %ecx\n"
        "movl $1, %edx\n"
        "movl %ebx, %eax\n"
        "calll CM_PointTraceStaticModelsComplete_r\n"
        /* } scope */
        "addl $0x44, %esp\n" /* line 1179 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1311 */
static __attribute__((naked))
int CM_ClipSightTraceToEntities_r(const vec_t *p2)
{
    __asm__ __volatile__ (
        ".Lfb02fc_000b02fc:\n"
        "pushl %ebp\n" /* line 1311 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, %edi\n" /* clip */
        /* { scope 1 */
        "movl (%ecx), %eax\n" /* line 199 */
        "movl %eax, -0x30(%ebp)\n" /* p */
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, -0x28(%ebp)\n"
        ".Lfb02fc_000b0318:\n"
        "movzwl %dx, %eax\n" /* line 1333 | nodeIndex */
        "leal (%eax, %eax, 2), %eax\n"
        "leal 0x4ed89c(, %eax, 8), %esi\n" /* node */
        "movl 4(%esi), %eax\n" /* line 1334 | node */
        "testl %eax, 0x44(%edi)\n" /* clip */
        "je .Lfb02fc_000b0398\n"
        ".Lfb02fc_000b032d:\n"
        "movzwl 8(%esi), %eax\n" /* line 1337 | node */
        "testw %ax, %ax\n"
        "jne .Lfb02fc_000b03ab\n"
        ".Lfb02fc_000b0336:\n"
        "movzwl 0x10(%esi), %eax\n" /* line 1345 | node */
        "movss 0xc(%esi), %xmm0\n" /* node */
        "movss -0x30(%ebp, %eax, 4), %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "movl 8(%ebp), %edx\n" /* line 1346 | p2, nodeIndex */
        "movss (%edx, %eax, 4), %xmm1\n" /* nodeIndex */
        "subss %xmm0, %xmm1\n"
        "movss 0x18(%edi, %eax, 4), %xmm4\n" /* line 1347 | clip */
        "movaps %xmm1, %xmm5\n" /* line 166 | comparand */
        "subss %xmm2, %xmm5\n" /* comparand */
        /* { scope 2 */
        "pxor %xmm6, %xmm6\n" /* line 45 */
        "movaps %xmm5, %xmm0\n"
        "movaps %xmm2, %xmm3\n"
        "cmpnltss %xmm6, %xmm0\n"
        "andps %xmm0, %xmm3\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm3, %xmm0\n"
        /* } scope */
        "ucomiss %xmm4, %xmm0\n" /* line 1349 */
        "jb .Lfb02fc_000b03e0\n"
        "movzwl 0x14(%esi), %edx\n" /* line 1351 | node, nodeIndex */
        "movzwl %dx, %eax\n" /* line 1333 | nodeIndex */
        "leal (%eax, %eax, 2), %eax\n"
        "leal 0x4ed89c(, %eax, 8), %esi\n" /* node */
        "movl 4(%esi), %eax\n" /* line 1334 | node */
        "testl %eax, 0x44(%edi)\n" /* clip */
        "jne .Lfb02fc_000b032d\n"
        ".Lfb02fc_000b0398:\n"
        "xorl %eax, %eax\n" /* line 1398 */
        /* } scope */
        ".Lfb02fc_000b039a:\n"
        "addl $0x5c, %esp\n" /* line 1399 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfb02fc_000b03a2:\n"
        "movzwl 2(%ebx), %eax\n" /* line 1337 | check */
        "testw %ax, %ax\n"
        "je .Lfb02fc_000b0336\n"
        ".Lfb02fc_000b03ab:\n"
        "movzwl %ax, %edx\n" /* line 1339 | nodeIndex */
        "leal (%edx, %edx, 2), %edx\n" /* nodeIndex */
        "movl %edx, %eax\n" /* nodeIndex */
        "shll $5, %eax\n"
        "subl %edx, %eax\n" /* nodeIndex */
        "leal 0x229c(, %eax, 4), %eax\n"
        "addl 0x195ee80, %eax\n"
        "leal 8(%eax), %ebx\n" /* check */
        "movl %ebx, 4(%esp)\n" /* line 1340 | check */
        "movl %edi, (%esp)\n" /* clip */
        "calll SV_ClipSightToEntity\n"
        "testl %eax, %eax\n" /* line 1341 */
        "je .Lfb02fc_000b03a2\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 1399 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfb02fc_000b03e0:\n"
        "movaps %xmm2, %xmm0\n" /* line 45 */
        "subss %xmm1, %xmm0\n"
        "movaps %xmm1, %xmm7\n"
        "cmpltss %xmm6, %xmm0\n"
        "andps %xmm0, %xmm7\n"
        "andnps %xmm2, %xmm0\n"
        "orps %xmm7, %xmm0\n"
        "movss 0x2f1c60, %xmm3\n" /* line 1355 */
        "movaps %xmm4, %xmm1\n"
        "xorps %xmm3, %xmm1\n"
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lfb02fc_000b0414\n"
        "movzwl 0x16(%esi), %edx\n" /* line 1357 | node, nodeIndex */
        "jmp .Lfb02fc_000b0318\n"
        ".Lfb02fc_000b0414:\n"
        "ucomiss %xmm6, %xmm5\n" /* line 1363 */
        "jne .Lfb02fc_000b0536\n"
        "jp .Lfb02fc_000b0536\n"
        "movaps %xmm6, %xmm3\n"
        "movss 0x2ed5d0, %xmm2\n" /* 1.0f */
        "movaps %xmm2, %xmm7\n"
        "xorl %ebx, %ebx\n" /* check */
        "movaps %xmm6, %xmm0\n"
        ".Lfb02fc_000b0436:\n"
        "movaps %xmm2, %xmm1\n" /* line 45 */
        "cmpnltss %xmm6, %xmm0\n"
        "andps %xmm0, %xmm1\n"
        "andnps %xmm7, %xmm0\n"
        "orps %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm2\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 1382 | p */
        "movl 8(%ebp), %eax\n" /* p2 */
        "movss (%eax), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n" /* mid */
        "movss -0x2c(%ebp), %xmm1\n" /* line 1383 */
        "movss 4(%eax), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "movss -0x28(%ebp), %xmm1\n" /* line 1384 */
        "movss 8(%eax), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "movzwl 0x14(%esi, %ebx, 2), %edx\n" /* line 1386 | node, nodeIndex */
        "leal -0x24(%ebp), %eax\n" /* mid */
        "movl %eax, (%esp)\n"
        "leal -0x30(%ebp), %ecx\n" /* p, p1 */
        "movl %edi, %eax\n" /* clip */
        "movss %xmm3, -0x48(%ebp)\n"
        "movss %xmm6, -0x58(%ebp)\n"
        "calll CM_ClipSightTraceToEntities_r\n"
        "testl %eax, %eax\n" /* line 1387 */
        "movss -0x48(%ebp), %xmm3\n"
        "movss -0x58(%ebp), %xmm6\n"
        "jne .Lfb02fc_000b039a\n"
        "maxss %xmm3, %xmm6\n" /* line 45 */
        "movaps %xmm6, %xmm3\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 1393 | p */
        "movl 8(%ebp), %edx\n" /* p2, nodeIndex */
        "movss (%edx), %xmm0\n" /* nodeIndex */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n" /* p */
        "movss -0x2c(%ebp), %xmm1\n" /* line 1394 */
        "movss 4(%edx), %xmm0\n" /* nodeIndex */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n"
        "movss -0x28(%ebp), %xmm1\n" /* line 1395 */
        "movss 8(%edx), %xmm0\n" /* nodeIndex */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "movb $1, %al\n" /* line 1397 */
        "subl %ebx, %eax\n" /* check */
        "movzwl 0x14(%esi, %eax, 2), %edx\n" /* node, nodeIndex */
        "jmp .Lfb02fc_000b0318\n"
        ".Lfb02fc_000b0536:\n"
        "movaps %xmm5, %xmm1\n" /* line 54 */
        "andps 0x2f1c70, %xmm1\n"
        "movaps %xmm2, %xmm0\n" /* line 1366 */
        "xorps %xmm3, %xmm0\n"
        "movaps %xmm5, %xmm3\n" /* line 45 */
        "movaps %xmm0, %xmm7\n"
        "cmpnltss %xmm6, %xmm3\n"
        "andps %xmm3, %xmm7\n"
        "andnps %xmm2, %xmm3\n"
        "orps %xmm7, %xmm3\n"
        "movaps %xmm3, %xmm0\n"
        "movss 0x2ed5d0, %xmm7\n" /* line 1367 | 1.0f */
        "movaps %xmm7, %xmm2\n"
        "divss %xmm1, %xmm2\n"
        "movaps %xmm2, %xmm1\n"
        "subss %xmm4, %xmm3\n" /* line 1368 */
        "mulss %xmm2, %xmm3\n"
        "movaps %xmm0, %xmm2\n" /* line 1369 */
        "addss %xmm4, %xmm2\n"
        "mulss %xmm1, %xmm2\n"
        "xorl %ebx, %ebx\n" /* line 96 */
        "ucomiss %xmm5, %xmm6\n"
        "setbe %bl\n"
        "movaps %xmm7, %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "jmp .Lfb02fc_000b0436\n"
    );
}

/* line 1407 */
__attribute__((naked))
int CM_ClipSightTraceToEntities(sightclip_t *clip)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1407 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* clip */
        "leal 0x24(%eax), %ecx\n" /* line 1413 */
        "leal 0x30(%eax), %edx\n"
        "movl %edx, 8(%ebp)\n" /* clip */
        "movl $1, %edx\n"
        "popl %ebp\n" /* line 1417 */
        "jmp CM_ClipSightTraceToEntities_r\n" /* line 1413 */
    );
}

/* line 1002 */
static __attribute__((naked))
void CM_PointTraceStaticModels_r(locTraceWork_t *tw, const vec_t *p2, trace_t *trace)
{
    __asm__ __volatile__ (
        ".Lfb05b0_000b05b0:\n"
        "pushl %ebp\n" /* line 1002 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, -0x3c(%ebp)\n"
        /* { scope 1 */
        "movl (%ecx), %eax\n" /* line 456 */
        "movl %eax, -0x38(%ebp)\n" /* p1 */
        "movl 4(%ecx), %eax\n" /* line 457 */
        "movl %eax, -0x34(%ebp)\n"
        "movl 8(%ecx), %eax\n" /* line 458 */
        "movl %eax, -0x30(%ebp)\n"
        "movl 0xc(%ecx), %eax\n" /* line 459 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "addl $4, %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        ".Lfb05b0_000b05dc:\n"
        "movzwl %dx, %eax\n" /* line 1017 | nodeIndex */
        "leal (%eax, %eax, 2), %eax\n"
        "leal 0x4ed890(, %eax, 8), %eax\n"
        "leal 0xc(%eax), %edi\n" /* node */
        "movl 0xc(%eax), %eax\n" /* line 1018 */
        "movl -0x3c(%ebp), %edx\n" /* nodeIndex */
        "testl %eax, (%edx)\n" /* nodeIndex */
        "je .Lfb05b0_000b0684\n"
        ".Lfb05b0_000b05fa:\n"
        "movzwl 0xa(%edi), %eax\n" /* line 1021 | node */
        "testw %ax, %ax\n"
        "jne .Lfb05b0_000b06e6\n"
        ".Lfb05b0_000b0607:\n"
        "movss 0xc(%edi), %xmm0\n" /* line 1031 | node */
        "movzwl 0x10(%edi), %eax\n" /* node */
        "movss -0x38(%ebp, %eax, 4), %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "movl 8(%ebp), %edx\n" /* line 1032 | p2, nodeIndex */
        "movss (%edx, %eax, 4), %xmm3\n" /* nodeIndex */
        "subss %xmm0, %xmm3\n"
        "movaps %xmm2, %xmm0\n" /* line 1034 */
        "mulss %xmm3, %xmm0\n"
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lfb05b0_000b0711\n"
        "movaps %xmm3, %xmm0\n" /* line 45 */
        "subss %xmm2, %xmm0\n"
        "movaps %xmm3, %xmm4\n"
        "cmpltss %xmm1, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm2, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        "xorl %edx, %edx\n" /* line 1036 | nodeIndex */
        "ucomiss %xmm0, %xmm1\n"
        "setbe %dl\n" /* nodeIndex */
        "movl $1, %eax\n"
        "subl %edx, %eax\n" /* nodeIndex */
        "movzwl 0x14(%edi, %eax, 2), %edx\n" /* node, nodeIndex */
        "movzwl %dx, %eax\n" /* line 1017 | nodeIndex */
        "leal (%eax, %eax, 2), %eax\n"
        "leal 0x4ed890(, %eax, 8), %eax\n"
        "leal 0xc(%eax), %edi\n" /* node */
        "movl 0xc(%eax), %eax\n" /* line 1018 */
        "movl -0x3c(%ebp), %edx\n" /* nodeIndex */
        "testl %eax, (%edx)\n" /* nodeIndex */
        "jne .Lfb05b0_000b05fa\n"
        /* } scope */
        ".Lfb05b0_000b0684:\n"
        "addl $0x5c, %esp\n" /* line 1060 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfb05b0_000b068c:\n"
        "movl 0xc(%ebp), %edx\n" /* line 1026 | trace, nodeIndex */
        "movl (%edx), %eax\n" /* nodeIndex */
        "movl %eax, 0xc(%esp)\n"
        "leal -0xc(%ebx), %eax\n" /* side */
        "movl %eax, 8(%esp)\n"
        "leal -0x18(%ebx), %eax\n" /* side */
        "movl %eax, 4(%esp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_TraceBox\n"
        "testl %eax, %eax\n"
        "jne .Lfb05b0_000b06da\n"
        "movl -0x3c(%ebp), %edx\n" /* line 1028 | nodeIndex */
        "movl (%edx), %eax\n" /* nodeIndex */
        "movl %eax, 0x10(%esp)\n"
        "movl %edx, %eax\n" /* nodeIndex */
        "addl $0x10, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* trace, nodeIndex */
        "movl %edx, 4(%esp)\n" /* nodeIndex */
        "movl %esi, (%esp)\n" /* check */
        "calll CM_TraceStaticModel\n"
        ".Lfb05b0_000b06da:\n"
        "movzwl (%esi), %eax\n" /* line 1021 | check */
        "testw %ax, %ax\n"
        "je .Lfb05b0_000b0607\n"
        ".Lfb05b0_000b06e6:\n"
        "movzwl %ax, %eax\n" /* line 1023 */
        "leal (%eax, %eax, 4), %ebx\n" /* side */
        "shll $4, %ebx\n" /* side */
        "movl 0x195eda4, %eax\n"
        "addl 8(%eax), %ebx\n" /* side */
        "leal -0x50(%ebx), %esi\n" /* side, check */
        "movl 4(%esi), %eax\n" /* line 1024 | check */
        "movl %eax, (%esp)\n"
        "calll XModelGetContents\n"
        "movl -0x3c(%ebp), %edx\n" /* nodeIndex */
        "testl %eax, (%edx)\n" /* nodeIndex */
        "je .Lfb05b0_000b06da\n"
        "jmp .Lfb05b0_000b068c\n"
        ".Lfb05b0_000b0711:\n"
        "movss -0x2c(%ebp), %xmm4\n" /* line 1040 */
        "movl 0xc(%ebp), %eax\n" /* trace */
        "ucomiss (%eax), %xmm4\n"
        "jae .Lfb05b0_000b0684\n"
        "movaps %xmm2, %xmm0\n" /* line 1044 */
        "subss %xmm3, %xmm0\n"
        "divss %xmm0, %xmm2\n"
        "movss -0x38(%ebp), %xmm1\n" /* line 1048 | p1 */
        "movl 8(%ebp), %edx\n" /* p2, nodeIndex */
        "movss (%edx), %xmm0\n" /* nodeIndex */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n" /* mid */
        "movss -0x34(%ebp), %xmm1\n" /* line 1049 */
        "movss 4(%edx), %xmm0\n" /* nodeIndex */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 1050 */
        "movss 8(%edx), %xmm0\n" /* nodeIndex */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "movss 0xc(%edx), %xmm0\n" /* line 1051 | nodeIndex */
        "subss %xmm4, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm4\n"
        "movss %xmm4, -0x1c(%ebp)\n"
        "pxor %xmm0, %xmm0\n" /* line 96 */
        "xorl %ebx, %ebx\n"
        "ucomiss %xmm3, %xmm0\n"
        "setbe %bl\n"
        "movzwl 0x14(%edi, %ebx, 2), %edx\n" /* line 1055 | node, nodeIndex */
        "movl %eax, 4(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* mid */
        "movl %eax, (%esp)\n"
        "leal -0x38(%ebp), %ecx\n" /* p1, p1_ */
        "movl -0x3c(%ebp), %eax\n"
        "calll CM_PointTraceStaticModels_r\n"
        "movl $1, %eax\n" /* line 1057 */
        "subl %ebx, %eax\n" /* side */
        "movzwl 0x14(%edi, %eax, 2), %edx\n" /* node, nodeIndex */
        "movl -0x28(%ebp), %eax\n" /* line 456 | mid */
        "movl %eax, -0x38(%ebp)\n" /* p1 */
        "movl -0x24(%ebp), %eax\n" /* line 457 */
        "movl %eax, -0x34(%ebp)\n"
        "movl -0x20(%ebp), %eax\n" /* line 458 */
        "movl %eax, -0x30(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 459 */
        "movl %eax, -0x2c(%ebp)\n"
        "jmp .Lfb05b0_000b05dc\n"
    );
}

/* line 1068 */
__attribute__((naked))
void CM_PointTraceStaticModels(trace_t *results, const vec_t *start, const vec_t *end, int contentmask)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1068 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x60, %esp\n"
        "movl 8(%ebp), %ebx\n" /* results */
        "movl 0xc(%ebp), %edx\n" /* start */
        "movl 0x10(%ebp), %ecx\n" /* end */
        /* { scope 1 */
        "movl 0x14(%ebp), %eax\n" /* line 1076 | contentmask */
        "movl %eax, -0x50(%ebp)\n" /* tw */
        "movl (%edx), %eax\n" /* line 199 */
        "movl %eax, -0x4c(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x48(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x44(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 199 */
        "movl %eax, -0x40(%ebp)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, -0x3c(%ebp)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, -0x38(%ebp)\n"
        "leal -0x50(%ebp), %esi\n" /* line 1080 | tw */
        "leal -0x4c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_CalcTraceEntents\n"
        "movl -0x4c(%ebp), %eax\n" /* line 199 */
        "movl %eax, -0x18(%ebp)\n" /* start_ */
        "movl -0x48(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x14(%ebp)\n"
        "movl -0x44(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x10(%ebp)\n"
        "movl $0, -0xc(%ebp)\n" /* line 1083 */
        "movl -0x40(%ebp), %eax\n" /* line 199 */
        "movl %eax, -0x28(%ebp)\n" /* end_ */
        "movl -0x3c(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x24(%ebp)\n"
        "movl -0x38(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x20(%ebp)\n"
        "movl (%ebx), %eax\n" /* line 1085 | results */
        "movl %eax, -0x1c(%ebp)\n"
        "leal -0x18(%ebp), %ecx\n" /* line 1087 | start_ */
        "movl %ebx, 4(%esp)\n" /* results */
        "leal -0x28(%ebp), %eax\n" /* end_ */
        "movl %eax, (%esp)\n"
        "movl $1, %edx\n"
        "movl %esi, %eax\n"
        "calll CM_PointTraceStaticModels_r\n"
        /* } scope */
        "addl $0x60, %esp\n" /* line 1090 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1425 */
static __attribute__((naked))
void CM_PointTraceToEntities_r(const vec_t *p2, trace_t *trace)
{
    __asm__ __volatile__ (
        ".Lfb087e_000b087e:\n"
        "pushl %ebp\n" /* line 1425 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, %edi\n" /* clip */
        /* { scope 1 */
        "movl (%ecx), %eax\n" /* line 456 */
        "movl %eax, -0x38(%ebp)\n" /* p */
        "movl 4(%ecx), %eax\n" /* line 457 */
        "movl %eax, -0x34(%ebp)\n"
        "movl 8(%ecx), %eax\n" /* line 458 */
        "movl %eax, -0x30(%ebp)\n"
        "movl 0xc(%ecx), %eax\n" /* line 459 */
        "movl %eax, -0x2c(%ebp)\n"
        ".Lfb087e_000b08a0:\n"
        "movzwl %dx, %eax\n" /* line 1440 | nodeIndex */
        "leal (%eax, %eax, 2), %eax\n"
        "leal 0x4ed89c(, %eax, 8), %esi\n" /* node */
        "movl 4(%esi), %eax\n" /* line 1441 | node */
        "testl %eax, 0x2c(%edi)\n" /* clip */
        "je .Lfb087e_000b0932\n"
        ".Lfb087e_000b08b5:\n"
        "movzwl 8(%esi), %eax\n" /* line 1444 | node */
        "testw %ax, %ax\n"
        "jne .Lfb087e_000b093a\n"
        ".Lfb087e_000b08be:\n"
        "movss 0xc(%esi), %xmm0\n" /* line 1450 | node */
        "movzwl 0x10(%esi), %eax\n" /* node */
        "movss -0x38(%ebp, %eax, 4), %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "movl 8(%ebp), %edx\n" /* line 1451 | p2, nodeIndex */
        "movss (%edx, %eax, 4), %xmm3\n" /* nodeIndex */
        "subss %xmm0, %xmm3\n"
        "movaps %xmm2, %xmm0\n" /* line 1453 */
        "mulss %xmm3, %xmm0\n"
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lfb087e_000b0978\n"
        "movaps %xmm3, %xmm0\n" /* line 45 */
        "subss %xmm2, %xmm0\n"
        "movaps %xmm3, %xmm4\n"
        "cmpltss %xmm1, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm2, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        "xorl %eax, %eax\n" /* line 1455 */
        "ucomiss %xmm0, %xmm1\n"
        "setbe %al\n"
        "movl $1, %edx\n" /* nodeIndex */
        "subl %eax, %edx\n" /* nodeIndex */
        "movzwl 0x14(%esi, %edx, 2), %edx\n" /* node, nodeIndex */
        "movzwl %dx, %eax\n" /* line 1440 | nodeIndex */
        "leal (%eax, %eax, 2), %eax\n"
        "leal 0x4ed89c(, %eax, 8), %esi\n" /* node */
        "movl 4(%esi), %eax\n" /* line 1441 | node */
        "testl %eax, 0x2c(%edi)\n" /* clip */
        "jne .Lfb087e_000b08b5\n"
        /* } scope */
        ".Lfb087e_000b0932:\n"
        "addl $0x3c, %esp\n" /* line 1478 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfb087e_000b093a:\n"
        "movzwl %ax, %eax\n" /* line 1446 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, %ebx\n" /* check */
        "shll $5, %ebx\n" /* check */
        "subl %eax, %ebx\n" /* check */
        "leal 0x229c(, %ebx, 4), %ebx\n" /* check */
        "addl 0x195ee80, %ebx\n" /* check */
        "addl $8, %ebx\n" /* check */
        "movl 0xc(%ebp), %eax\n" /* line 1447 | trace */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* check */
        "movl %edi, (%esp)\n" /* clip */
        "calll SV_PointTraceToEntity\n"
        "movzwl 2(%ebx), %eax\n" /* line 1444 | check */
        "testw %ax, %ax\n"
        "jne .Lfb087e_000b093a\n"
        "jmp .Lfb087e_000b08be\n"
        ".Lfb087e_000b0978:\n"
        "movss -0x2c(%ebp), %xmm4\n" /* line 1459 */
        "movl 0xc(%ebp), %eax\n" /* trace */
        "ucomiss (%eax), %xmm4\n"
        "jae .Lfb087e_000b0932\n"
        "movaps %xmm2, %xmm0\n" /* line 1462 */
        "subss %xmm3, %xmm0\n"
        "divss %xmm0, %xmm2\n"
        "movss -0x38(%ebp), %xmm1\n" /* line 1466 | p */
        "movl 8(%ebp), %edx\n" /* p2, nodeIndex */
        "movss (%edx), %xmm0\n" /* nodeIndex */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n" /* mid */
        "movss -0x34(%ebp), %xmm1\n" /* line 1467 */
        "movss 4(%edx), %xmm0\n" /* nodeIndex */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 1468 */
        "movss 8(%edx), %xmm0\n" /* nodeIndex */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "movss 0xc(%edx), %xmm0\n" /* line 1469 | nodeIndex */
        "subss %xmm4, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm4\n"
        "movss %xmm4, -0x1c(%ebp)\n"
        "pxor %xmm0, %xmm0\n" /* line 96 */
        "xorl %ebx, %ebx\n"
        "ucomiss %xmm3, %xmm0\n"
        "setbe %bl\n"
        "movzwl 0x14(%esi, %ebx, 2), %edx\n" /* line 1473 | node, nodeIndex */
        "movl %eax, 4(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* mid */
        "movl %eax, (%esp)\n"
        "leal -0x38(%ebp), %ecx\n" /* p, p1 */
        "movl %edi, %eax\n" /* clip */
        "calll CM_PointTraceToEntities_r\n"
        "movl $1, %eax\n" /* line 1475 */
        "subl %ebx, %eax\n" /* check */
        "movzwl 0x14(%esi, %eax, 2), %edx\n" /* node, nodeIndex */
        "movl -0x28(%ebp), %eax\n" /* line 456 | mid */
        "movl %eax, -0x38(%ebp)\n" /* p */
        "movl -0x24(%ebp), %eax\n" /* line 457 */
        "movl %eax, -0x34(%ebp)\n"
        "movl -0x20(%ebp), %eax\n" /* line 458 */
        "movl %eax, -0x30(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 459 */
        "movl %eax, -0x2c(%ebp)\n"
        "jmp .Lfb087e_000b08a0\n"
    );
}

/* line 1486 */
__attribute__((naked))
void CM_PointTraceToEntities(pointtrace_t *clip, trace_t *trace)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1486 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        "movl 8(%ebp), %eax\n" /* clip */
        "movl 0xc(%ebp), %ebx\n" /* trace */
        /* { scope 1 */
        "movl (%eax), %edx\n" /* line 199 */
        "movl %edx, -0x18(%ebp)\n" /* start */
        "movl 4(%eax), %edx\n" /* line 200 */
        "movl %edx, -0x14(%ebp)\n"
        "movl 8(%eax), %edx\n" /* line 201 */
        "movl %edx, -0x10(%ebp)\n"
        "leal 0xc(%eax), %ecx\n"
        /* { scope 2 */
        "movl 0xc(%eax), %edx\n" /* line 199 */
        "movl %edx, -0x28(%ebp)\n" /* end */
        "movl 4(%ecx), %edx\n" /* line 200 */
        "movl %edx, -0x24(%ebp)\n"
        "movl 8(%ecx), %edx\n" /* line 201 */
        "movl %edx, -0x20(%ebp)\n"
        /* } scope */
        "movl $0, -0xc(%ebp)\n" /* line 1497 */
        "movl (%ebx), %edx\n" /* line 1498 | trace */
        "movl %edx, -0x1c(%ebp)\n"
        "leal -0x18(%ebp), %ecx\n" /* line 1500 | start */
        "movl %ebx, 4(%esp)\n" /* trace */
        "leal -0x28(%ebp), %edx\n" /* end */
        "movl %edx, (%esp)\n"
        "movl $1, %edx\n"
        "calll CM_PointTraceToEntities_r\n"
        /* } scope */
        "addl $0x34, %esp\n" /* line 1503 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1187 */
static __attribute__((naked))
void CM_ClipMoveToEntities_r(const vec_t *p2, trace_t *trace)
{
    __asm__ __volatile__ (
        ".Lfb0aa4_000b0aa4:\n"
        "pushl %ebp\n" /* line 1187 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl %eax, %edi\n" /* clip */
        /* { scope 1 */
        "movl (%ecx), %eax\n" /* line 456 */
        "movl %eax, -0x38(%ebp)\n" /* p */
        "movl 4(%ecx), %eax\n" /* line 457 */
        "movl %eax, -0x34(%ebp)\n"
        "movl 8(%ecx), %eax\n" /* line 458 */
        "movl %eax, -0x30(%ebp)\n"
        "movl 0xc(%ecx), %eax\n" /* line 459 */
        "movl %eax, -0x2c(%ebp)\n"
        ".Lfb0aa4_000b0ac6:\n"
        "movzwl %dx, %eax\n" /* line 1208 | nodeIndex */
        "leal (%eax, %eax, 2), %eax\n"
        "leal 0x4ed89c(, %eax, 8), %esi\n" /* node */
        "movl 0x50(%edi), %ecx\n" /* line 1209 | clip, p1 */
        "testl %ecx, 4(%esi)\n" /* p1, node */
        "je .Lfb0aa4_000b0b4a\n"
        ".Lfb0aa4_000b0adb:\n"
        "movzwl 8(%esi), %eax\n" /* line 1212 | node */
        "testw %ax, %ax\n"
        "jne .Lfb0aa4_000b0b75\n"
        ".Lfb0aa4_000b0ae8:\n"
        "movzwl 0x10(%esi), %eax\n" /* line 1220 | node */
        "movss 0xc(%esi), %xmm0\n" /* node */
        "movss -0x38(%ebp, %eax, 4), %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "movl 8(%ebp), %edx\n" /* line 1221 | p2, nodeIndex */
        "movss (%edx, %eax, 4), %xmm1\n" /* nodeIndex */
        "subss %xmm0, %xmm1\n"
        "movss 0x18(%edi, %eax, 4), %xmm3\n" /* line 1222 | clip */
        "movaps %xmm1, %xmm5\n" /* line 166 | comparand */
        "subss %xmm2, %xmm5\n" /* comparand */
        /* { scope 2 */
        "pxor %xmm6, %xmm6\n" /* line 45 */
        "movaps %xmm5, %xmm0\n"
        "movaps %xmm2, %xmm4\n"
        "cmpnltss %xmm6, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        /* } scope */
        "ucomiss %xmm3, %xmm0\n" /* line 1224 */
        "jb .Lfb0aa4_000b0b9c\n"
        "movzwl 0x14(%esi), %edx\n" /* line 1226 | node, nodeIndex */
        "movzwl %dx, %eax\n" /* line 1208 | nodeIndex */
        "leal (%eax, %eax, 2), %eax\n"
        "leal 0x4ed89c(, %eax, 8), %esi\n" /* node */
        "movl 0x50(%edi), %ecx\n" /* line 1209 | clip, p1 */
        "testl %ecx, 4(%esi)\n" /* p1, node */
        "jne .Lfb0aa4_000b0adb\n"
        /* } scope */
        ".Lfb0aa4_000b0b4a:\n"
        "addl $0x6c, %esp\n" /* line 1278 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfb0aa4_000b0b52:\n"
        "movl 0xc(%ebp), %eax\n" /* line 1217 | trace */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* check */
        "movl %edi, (%esp)\n" /* clip */
        "calll SV_ClipMoveToEntity\n"
        ".Lfb0aa4_000b0b65:\n"
        "movzwl 2(%ebx), %eax\n" /* line 1212 | check */
        "testw %ax, %ax\n"
        "je .Lfb0aa4_000b0ae8\n"
        "movl 0x50(%edi), %ecx\n" /* clip, p1 */
        ".Lfb0aa4_000b0b75:\n"
        "movzwl %ax, %edx\n" /* line 1214 | nodeIndex */
        "leal (%edx, %edx, 2), %edx\n" /* nodeIndex */
        "movl %edx, %eax\n" /* nodeIndex */
        "shll $5, %eax\n"
        "subl %edx, %eax\n" /* nodeIndex */
        "leal 0x229c(, %eax, 4), %eax\n"
        "addl 0x195ee80, %eax\n"
        "leal 8(%eax), %ebx\n" /* check */
        "testl %ecx, 0x160(%ebx)\n" /* line 1215 | p1, check */
        "je .Lfb0aa4_000b0b65\n"
        "jmp .Lfb0aa4_000b0b52\n"
        ".Lfb0aa4_000b0b9c:\n"
        "movaps %xmm2, %xmm0\n" /* line 45 */
        "subss %xmm1, %xmm0\n"
        "movaps %xmm1, %xmm4\n"
        "cmpltss %xmm6, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm2, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        "movss 0x2f1c80, %xmm4\n" /* line 1230 */
        "movaps %xmm3, %xmm1\n"
        "xorps %xmm4, %xmm1\n"
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lfb0aa4_000b0bd0\n"
        "movzwl 0x16(%esi), %edx\n" /* line 1232 | node, nodeIndex */
        "jmp .Lfb0aa4_000b0ac6\n"
        ".Lfb0aa4_000b0bd0:\n"
        "movss -0x2c(%ebp), %xmm7\n" /* line 1236 */
        "movl 0xc(%ebp), %eax\n" /* trace */
        "ucomiss (%eax), %xmm7\n"
        "jae .Lfb0aa4_000b0b4a\n"
        "ucomiss %xmm6, %xmm5\n" /* line 1241 */
        "jne .Lfb0aa4_000b0d34\n"
        "jp .Lfb0aa4_000b0d34\n"
        "movaps %xmm6, %xmm4\n"
        "movss 0x2ed5d0, %xmm2\n" /* 1.0f */
        "xorl %eax, %eax\n"
        "movaps %xmm6, %xmm0\n"
        "movl $1, %ebx\n" /* check */
        "movaps %xmm2, %xmm3\n"
        ".Lfb0aa4_000b0c08:\n"
        "movaps %xmm2, %xmm1\n" /* line 45 */
        "cmpnltss %xmm6, %xmm0\n"
        "andps %xmm0, %xmm1\n"
        "andnps %xmm3, %xmm0\n"
        "orps %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm2\n"
        "movss -0x38(%ebp), %xmm1\n" /* line 1261 | p */
        "movl 8(%ebp), %edx\n" /* p2, nodeIndex */
        "movss (%edx), %xmm0\n" /* nodeIndex */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n" /* mid */
        "movss -0x34(%ebp), %xmm1\n" /* line 1262 */
        "movss 4(%edx), %xmm0\n" /* nodeIndex */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 1263 */
        "movss 8(%edx), %xmm0\n" /* nodeIndex */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "movss 0xc(%edx), %xmm0\n" /* line 1264 | nodeIndex */
        "subss %xmm7, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm7\n"
        "movss %xmm7, -0x1c(%ebp)\n"
        "movzwl 0x14(%esi, %eax, 2), %edx\n" /* line 1266 | node, nodeIndex */
        "movl 0xc(%ebp), %eax\n" /* trace */
        "movl %eax, 4(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* mid */
        "movl %eax, (%esp)\n"
        "leal -0x38(%ebp), %ecx\n" /* p, p1 */
        "movl %edi, %eax\n" /* clip */
        "movss %xmm4, -0x48(%ebp)\n"
        "movss %xmm6, -0x58(%ebp)\n"
        "calll CM_ClipMoveToEntities_r\n"
        "movss -0x48(%ebp), %xmm4\n" /* line 45 */
        "movss -0x58(%ebp), %xmm6\n"
        "maxss %xmm4, %xmm6\n"
        "movaps %xmm6, %xmm4\n"
        "movss -0x38(%ebp), %xmm1\n" /* line 1271 | p */
        "movl 8(%ebp), %edx\n" /* p2, nodeIndex */
        "movss (%edx), %xmm0\n" /* nodeIndex */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x38(%ebp)\n" /* p */
        "movss -0x34(%ebp), %xmm1\n" /* line 1272 */
        "movss 4(%edx), %xmm0\n" /* nodeIndex */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x34(%ebp)\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 1273 */
        "movss 8(%edx), %xmm0\n" /* nodeIndex */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n"
        "movss -0x2c(%ebp), %xmm1\n" /* line 1274 */
        "movss 0xc(%edx), %xmm0\n" /* nodeIndex */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "addss %xmm4, %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n"
        "movzwl 0x14(%esi, %ebx, 2), %edx\n" /* line 1276 | node, nodeIndex */
        "jmp .Lfb0aa4_000b0ac6\n"
        ".Lfb0aa4_000b0d34:\n"
        "movaps %xmm5, %xmm0\n" /* line 54 */
        "andps 0x2f1c90, %xmm0\n"
        "movss %xmm0, -0x5c(%ebp)\n" /* absDiff */
        "movaps %xmm2, %xmm0\n" /* line 1244 */
        "xorps %xmm4, %xmm0\n"
        "movaps %xmm5, %xmm1\n" /* line 45 */
        "movaps %xmm0, %xmm4\n"
        "cmpnltss %xmm6, %xmm1\n"
        "andps %xmm1, %xmm4\n"
        "andnps %xmm2, %xmm1\n"
        "orps %xmm4, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "movss 0x2ed5d0, %xmm1\n" /* line 1245 | 1.0f */
        "divss -0x5c(%ebp), %xmm1\n" /* absDiff */
        "movaps %xmm0, %xmm4\n" /* line 1246 */
        "subss %xmm3, %xmm4\n"
        "mulss %xmm1, %xmm4\n"
        "movaps %xmm0, %xmm2\n" /* line 1247 */
        "addss %xmm3, %xmm2\n"
        "mulss %xmm1, %xmm2\n"
        "xorl %eax, %eax\n" /* line 96 */
        "ucomiss %xmm5, %xmm6\n"
        "setbe %al\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "subss %xmm2, %xmm0\n"
        "movl $1, %ebx\n"
        "subl %eax, %ebx\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "jmp .Lfb0aa4_000b0c08\n"
    );
}

/* line 1286 */
__attribute__((naked))
void CM_ClipMoveToEntities(moveclip_t *clip, trace_t *trace)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1286 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        "movl 8(%ebp), %eax\n" /* clip */
        "movl 0xc(%ebp), %ebx\n" /* trace */
        "leal 0x24(%eax), %ecx\n"
        /* { scope 1 */
        /* { scope 2 */
        "movl 0x24(%eax), %edx\n" /* line 199 */
        "movl %edx, -0x18(%ebp)\n" /* start */
        "movl 4(%ecx), %edx\n" /* line 200 */
        "movl %edx, -0x14(%ebp)\n"
        "movl 8(%ecx), %edx\n" /* line 201 */
        "movl %edx, -0x10(%ebp)\n"
        "leal 0x30(%eax), %ecx\n"
        /* } scope */
        /* { scope 2 */
        "movl 0x30(%eax), %edx\n" /* line 199 */
        "movl %edx, -0x28(%ebp)\n" /* end */
        "movl 4(%ecx), %edx\n" /* line 200 */
        "movl %edx, -0x24(%ebp)\n"
        "movl 8(%ecx), %edx\n" /* line 201 */
        "movl %edx, -0x20(%ebp)\n"
        /* } scope */
        "movl $0, -0xc(%ebp)\n" /* line 1297 */
        "movl (%ebx), %edx\n" /* line 1298 | trace */
        "movl %edx, -0x1c(%ebp)\n"
        "leal -0x18(%ebp), %ecx\n" /* line 1300 | start */
        "movl %ebx, 4(%esp)\n" /* trace */
        "leal -0x28(%ebp), %edx\n" /* end */
        "movl %edx, (%esp)\n"
        "movl $1, %edx\n"
        "calll CM_ClipMoveToEntities_r\n"
        /* } scope */
        "addl $0x34, %esp\n" /* line 1303 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 594 */
static __attribute__((naked))
void CM_SortNode(short unsigned int nodeIndex, vec_t *mins, vec_t *maxs)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 594 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl %edx, -0x54(%ebp)\n"
        "movl %ecx, -0x58(%ebp)\n"
        "movw %ax, -0x4e(%ebp)\n"
        /* { scope 1: size, nodeIndex */
        "cmpb $0, 0x4ed898\n" /* line 607 */
        "jne .Lfb0e0c_000b0fc9\n"
        "movzwl %ax, %eax\n" /* line 610 */
        "leal (%eax, %eax, 2), %eax\n"
        "leal 0x4ed89c(, %eax, 8), %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* node */
        "movzwl 0x10(%eax), %eax\n" /* line 612 */
        "movl %eax, -0x40(%ebp)\n" /* axis */
        "movl -0x30(%ebp), %edx\n" /* line 613 | node */
        "movss 0xc(%edx), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n" /* dist */
        "movzwl 8(%edx), %edi\n" /* line 616 | modelnum */
        "testw %di, %di\n" /* line 618 | modelnum */
        "je .Lfb0e0c_000b0f14\n"
        "movl $0, -0x38(%ebp)\n" /* prevEnt */
        "movl 0x195ee80, %eax\n"
        "movl %eax, -0x5c(%ebp)\n"
        ".Lfb0e0c_000b0e6c:\n"
        "movzwl %di, %eax\n" /* line 620 | modelnum */
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl -0x5c(%ebp), %eax\n"
        "leal 0x22a4(%eax, %edx, 4), %edx\n"
        "movl %edx, -0x48(%ebp)\n" /* ent */
        "movl -0x40(%ebp), %eax\n" /* line 621 | axis */
        "movss 0x164(%edx, %eax, 4), %xmm0\n"
        "ucomiss -0x3c(%ebp), %xmm0\n" /* dist */
        "jbe .Lfb0e0c_000b1141\n"
        "movl -0x30(%ebp), %edx\n" /* line 623 | node */
        "movzwl 0x14(%edx), %eax\n"
        "testw %ax, %ax\n" /* line 624 */
        "jne .Lfb0e0c_000b1216\n"
        /* { scope 2 */
        "movzwl 0x4ed89a, %edx\n" /* line 107 */
        "testw %dx, %dx\n" /* line 108 */
        "je .Lfb0e0c_000b0efe\n"
        "movl -0x58(%ebp), %eax\n" /* line 65 */
        "movss (%eax), %xmm1\n"
        "movl -0x54(%ebp), %eax\n"
        "subss (%eax), %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n" /* size */
        "movl -0x58(%ebp), %eax\n" /* line 66 */
        "movss 4(%eax), %xmm0\n"
        "movl -0x54(%ebp), %eax\n"
        "subss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "xorl %ebx, %ebx\n" /* line 112 | axis */
        "ucomiss %xmm1, %xmm0\n"
        "setae %bl\n" /* axis */
        "movzwl %bx, %ecx\n" /* line 113 | axis */
        "movss 0x2ed828, %xmm0\n" /* 512.0f */
        "ucomiss -0x20(%ebp, %ecx, 4), %xmm0\n"
        "jb .Lfb0e0c_000b1366\n"
        ".Lfb0e0c_000b0efe:\n"
        "movl -0x48(%ebp), %eax\n" /* ent */
        /* } scope */
        ".Lfb0e0c_000b0f01:\n"
        "movzwl 2(%eax), %edi\n" /* line 649 | modelnum */
        "movl %eax, -0x38(%ebp)\n" /* prevEnt */
        ".Lfb0e0c_000b0f08:\n"
        "testw %di, %di\n" /* line 618 | modelnum */
        "jne .Lfb0e0c_000b0e6c\n"
        "movl -0x30(%ebp), %edx\n" /* node */
        ".Lfb0e0c_000b0f14:\n"
        "movzwl 0xa(%edx), %edi\n" /* line 668 | modelnum */
        "testw %di, %di\n" /* line 670 | modelnum */
        "je .Lfb0e0c_000b0fc9\n"
        "movl $0, -0x34(%ebp)\n" /* prevStaticModel */
        ".Lfb0e0c_000b0f28:\n"
        "movl 0x195eda4, %eax\n" /* line 672 */
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x4c(%ebp)\n"
        "movzwl %di, %eax\n" /* modelnum */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $4, %eax\n"
        "movl -0x4c(%ebp), %edx\n"
        "leal -0x50(%edx, %eax), %eax\n"
        "movl %eax, -0x44(%ebp)\n" /* staticModel */
        "movl -0x40(%ebp), %edx\n" /* line 673 | axis */
        "movss 0x38(%eax, %edx, 4), %xmm0\n"
        "ucomiss -0x3c(%ebp), %xmm0\n" /* dist */
        "jbe .Lfb0e0c_000b0fd1\n"
        "movl -0x30(%ebp), %edx\n" /* line 675 | node */
        "movzwl 0x14(%edx), %eax\n"
        "testw %ax, %ax\n" /* line 676 */
        "jne .Lfb0e0c_000b10a4\n"
        /* { scope 2 */
        "movzwl 0x4ed89a, %edx\n" /* line 107 */
        "testw %dx, %dx\n" /* line 108 */
        "je .Lfb0e0c_000b0fb7\n"
        "movl -0x58(%ebp), %eax\n" /* line 65 */
        "movss (%eax), %xmm1\n"
        "movl -0x54(%ebp), %eax\n"
        "subss (%eax), %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n" /* size */
        "movl -0x58(%ebp), %eax\n" /* line 66 */
        "movss 4(%eax), %xmm0\n"
        "movl -0x54(%ebp), %eax\n"
        "subss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "xorl %ebx, %ebx\n" /* line 112 | axis */
        "ucomiss %xmm1, %xmm0\n"
        "setae %bl\n" /* axis */
        "movzwl %bx, %ecx\n" /* line 113 | axis */
        "movss 0x2ed828, %xmm0\n" /* 512.0f */
        "ucomiss -0x20(%ebp, %ecx, 4), %xmm0\n"
        "jb .Lfb0e0c_000b1307\n"
        ".Lfb0e0c_000b0fb7:\n"
        "movl -0x44(%ebp), %eax\n" /* staticModel */
        /* } scope */
        ".Lfb0e0c_000b0fba:\n"
        "movzwl (%eax), %edi\n" /* line 701 | modelnum */
        "movl %eax, -0x34(%ebp)\n" /* prevStaticModel */
        ".Lfb0e0c_000b0fc0:\n"
        "testw %di, %di\n" /* line 670 | modelnum */
        "jne .Lfb0e0c_000b0f28\n"
        /* } scope */
        ".Lfb0e0c_000b0fc9:\n"
        "addl $0x6c, %esp\n" /* line 718 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfb0e0c_000b0fd1:\n"
        "movl %edx, %eax\n"
        /* { scope 1: size, nodeIndex */
        "movss -0x3c(%ebp), %xmm0\n" /* line 685 | dist */
        "movl -0x44(%ebp), %edx\n" /* staticModel */
        "ucomiss 0x44(%edx, %eax, 4), %xmm0\n"
        "jbe .Lfb0e0c_000b12dd\n"
        "movl -0x30(%ebp), %edx\n" /* line 687 | node */
        "movzwl 0x16(%edx), %eax\n"
        "testw %ax, %ax\n" /* line 688 */
        "jne .Lfb0e0c_000b10a4\n"
        /* { scope 2 */
        "movzwl 0x4ed89a, %edx\n" /* line 107 */
        "testw %dx, %dx\n" /* line 108 */
        "je .Lfb0e0c_000b0fb7\n"
        "movl -0x58(%ebp), %eax\n" /* line 65 */
        "movss (%eax), %xmm1\n"
        "movl -0x54(%ebp), %eax\n"
        "subss (%eax), %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n" /* size */
        "movl -0x58(%ebp), %eax\n" /* line 66 */
        "movss 4(%eax), %xmm0\n"
        "movl -0x54(%ebp), %eax\n"
        "subss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "xorl %ebx, %ebx\n" /* line 112 | axis */
        "ucomiss %xmm1, %xmm0\n"
        "setae %bl\n" /* axis */
        "movzwl %bx, %ecx\n" /* line 113 | axis */
        "movss 0x2ed828, %xmm0\n" /* 512.0f */
        "ucomiss -0x20(%ebp, %ecx, 4), %xmm0\n"
        "jae .Lfb0e0c_000b0fb7\n"
        "movzwl %dx, %esi\n" /* line 116 */
        "leal (%esi, %esi, 2), %edx\n"
        "leal 0x4ed89c(, %edx, 8), %edx\n"
        "movzwl 0x12(%edx), %eax\n" /* line 125 */
        "movw %ax, 0x4ed89a\n"
        "movw %bx, 0x10(%edx)\n" /* line 127 | axis */
        "movl -0x58(%ebp), %eax\n" /* line 128 */
        "movss (%eax, %ecx, 4), %xmm0\n"
        "movl -0x54(%ebp), %eax\n"
        "addss (%eax, %ecx, 4), %xmm0\n"
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, 0xc(%edx)\n"
        /* } scope */
        "testw %si, %si\n" /* line 691 */
        "je .Lfb0e0c_000b0fb7\n"
        "movl -0x30(%ebp), %edx\n" /* line 693 | node */
        "movw %si, 0x16(%edx)\n"
        "movzwl %si, %esi\n" /* line 694 */
        "leal (%esi, %esi, 2), %eax\n"
        "movzwl -0x4e(%ebp), %edx\n"
        "movw %dx, 0x4ed8ae(, %eax, 8)\n"
        "jmp .Lfb0e0c_000b10a7\n"
        ".Lfb0e0c_000b10a4:\n"
        "movzwl %ax, %esi\n" /* line 702 */
        ".Lfb0e0c_000b10a7:\n"
        "movl -0x44(%ebp), %edx\n" /* line 705 | staticModel */
        "movzwl (%edx), %edi\n" /* modelnum */
        /* { scope 2 */
        "movl %edx, %ecx\n" /* line 576 */
        "subl -0x4c(%ebp), %ecx\n"
        "sarl $4, %ecx\n"
        "leal (%ecx, %ecx, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $8, %edx\n"
        "addl %edx, %eax\n"
        "leal (%ecx, %eax, 4), %ecx\n"
        "leal (%esi, %esi, 2), %eax\n" /* line 577 */
        "leal 0x4ed890(, %eax, 8), %eax\n"
        "leal 0x16(%eax), %ebx\n" /* prevStaticModel */
        "movzwl 0x16(%eax), %edx\n" /* line 579 */
        "leal -1(%edx), %eax\n"
        "cmpw %ax, %cx\n"
        "jb .Lfb0e0c_000b10fd\n"
        ".Lfb0e0c_000b10e2:\n"
        "movzwl %dx, %eax\n" /* line 577 */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $4, %eax\n"
        "addl -0x4c(%ebp), %eax\n"
        "leal -0x50(%eax), %ebx\n" /* prevStaticModel */
        "movzwl -0x50(%eax), %edx\n" /* line 579 */
        "leal -1(%edx), %eax\n"
        "cmpw %ax, %cx\n"
        "jae .Lfb0e0c_000b10e2\n"
        ".Lfb0e0c_000b10fd:\n"
        "movl -0x44(%ebp), %eax\n" /* line 583 | staticModel */
        "movw %dx, (%eax)\n"
        "leal 1(%ecx), %eax\n" /* line 584 */
        "movw %ax, (%ebx)\n" /* prevStaticModel */
        /* } scope */
        "leal (%esi, %esi, 2), %esi\n" /* line 711 */
        "shll $3, %esi\n"
        "movl 0x4ed89c(%esi), %ebx\n" /* prevStaticModel */
        "movl -0x44(%ebp), %edx\n" /* staticModel */
        "movl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll XModelGetContents\n"
        "orl %eax, %ebx\n" /* prevStaticModel */
        "movl %ebx, 0x4ed89c(%esi)\n" /* prevStaticModel */
        "movl -0x34(%ebp), %ecx\n" /* line 713 | prevStaticModel */
        "testl %ecx, %ecx\n"
        "je .Lfb0e0c_000b12ef\n"
        "movl -0x34(%ebp), %edx\n" /* line 716 | prevStaticModel */
        "movw %di, (%edx)\n" /* modelnum */
        "jmp .Lfb0e0c_000b0fc0\n"
        ".Lfb0e0c_000b1141:\n"
        "movss -0x3c(%ebp), %xmm0\n" /* line 633 | dist */
        "ucomiss 0x16c(%edx, %eax, 4), %xmm0\n"
        "jbe .Lfb0e0c_000b12e4\n"
        "movl -0x30(%ebp), %edx\n" /* line 635 | node */
        "movzwl 0x16(%edx), %eax\n"
        "testw %ax, %ax\n" /* line 636 */
        "jne .Lfb0e0c_000b1216\n"
        /* { scope 2 */
        "movzwl 0x4ed89a, %edx\n" /* line 107 */
        "testw %dx, %dx\n" /* line 108 */
        "je .Lfb0e0c_000b0efe\n"
        "movl -0x58(%ebp), %eax\n" /* line 65 */
        "movss (%eax), %xmm1\n"
        "movl -0x54(%ebp), %eax\n"
        "subss (%eax), %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n" /* size */
        "movl -0x58(%ebp), %eax\n" /* line 66 */
        "movss 4(%eax), %xmm0\n"
        "movl -0x54(%ebp), %eax\n"
        "subss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "xorl %ebx, %ebx\n" /* line 112 | axis */
        "ucomiss %xmm1, %xmm0\n"
        "setae %bl\n" /* axis */
        "movzwl %bx, %ecx\n" /* line 113 | axis */
        "movss 0x2ed828, %xmm0\n" /* 512.0f */
        "ucomiss -0x20(%ebp, %ecx, 4), %xmm0\n"
        "jae .Lfb0e0c_000b0efe\n"
        "movzwl %dx, %esi\n" /* line 116 */
        "leal (%esi, %esi, 2), %edx\n"
        "leal 0x4ed89c(, %edx, 8), %edx\n"
        "movzwl 0x12(%edx), %eax\n" /* line 125 */
        "movw %ax, 0x4ed89a\n"
        "movw %bx, 0x10(%edx)\n" /* line 127 | axis */
        "movl -0x58(%ebp), %eax\n" /* line 128 */
        "movss (%eax, %ecx, 4), %xmm0\n"
        "movl -0x54(%ebp), %eax\n"
        "addss (%eax, %ecx, 4), %xmm0\n"
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, 0xc(%edx)\n"
        /* } scope */
        "testw %si, %si\n" /* line 639 */
        "je .Lfb0e0c_000b0efe\n"
        "movl -0x30(%ebp), %edx\n" /* line 641 | node */
        "movw %si, 0x16(%edx)\n"
        "movzwl %si, %esi\n" /* line 642 */
        "leal (%esi, %esi, 2), %eax\n"
        "movzwl -0x4e(%ebp), %edx\n"
        "movw %dx, 0x4ed8ae(, %eax, 8)\n"
        "jmp .Lfb0e0c_000b1219\n"
        ".Lfb0e0c_000b1216:\n"
        "movzwl %ax, %esi\n" /* line 650 */
        ".Lfb0e0c_000b1219:\n"
        "movl -0x48(%ebp), %edx\n" /* line 653 | ent */
        "movzwl 2(%edx), %edi\n" /* modelnum */
        /* { scope 2 */
        /* { scope 3 */
        "movl -0x5c(%ebp), %edx\n" /* line 552 */
        "leal 0x2418(%edx), %eax\n"
        "movl -0x48(%ebp), %edx\n" /* ent */
        "subl %eax, %edx\n"
        "sarl $2, %edx\n"
        "movl %edx, %eax\n"
        "shll $6, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, %ecx\n"
        "shll $0xa, %ecx\n"
        "addl %ecx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "shll $6, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal (%edx, %eax, 4), %ebx\n" /* entnum */
        "movw %si, -0x2a(%ebp)\n" /* line 553 | nodeIndex */
        "leal (%esi, %esi, 2), %eax\n"
        "leal 0x4ed890(, %eax, 8), %eax\n"
        "leal 0x14(%eax), %ecx\n"
        "movzwl 0x14(%eax), %edx\n" /* line 555 */
        "leal -1(%edx), %eax\n"
        "cmpw %ax, %bx\n" /* entnum */
        "jb .Lfb0e0c_000b12eb\n"
        ".Lfb0e0c_000b126d:\n"
        "movzwl %dx, %eax\n" /* line 553 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl -0x5c(%ebp), %eax\n"
        "leal 0x229c(%eax, %edx, 4), %edx\n"
        "leal 0xa(%edx), %ecx\n"
        "movzwl 0xa(%edx), %edx\n" /* line 555 */
        "leal -1(%edx), %eax\n"
        "cmpw %ax, %bx\n" /* entnum */
        "jae .Lfb0e0c_000b126d\n"
        "movzwl -0x2a(%ebp), %eax\n" /* nodeIndex */
        ".Lfb0e0c_000b1297:\n"
        "movl -0x48(%ebp), %edx\n" /* line 559 | ent */
        "movw %ax, (%edx)\n"
        "movzwl (%ecx), %eax\n" /* line 560 */
        "movw %ax, 2(%edx)\n"
        "leal 1(%ebx), %eax\n" /* line 561 | entnum */
        "movw %ax, (%ecx)\n"
        /* } scope */
        /* } scope */
        "leal (%esi, %esi, 2), %esi\n" /* line 659 */
        "shll $3, %esi\n"
        "movl 0x4ed8a0(%esi), %ebx\n" /* prevStaticModel */
        "movl %edx, (%esp)\n"
        "calll SV_GEntityForSvEntity\n"
        "orl 0x11c(%eax), %ebx\n" /* prevStaticModel */
        "movl %ebx, 0x4ed8a0(%esi)\n" /* prevStaticModel */
        "movl -0x38(%ebp), %ebx\n" /* line 661 | prevEnt, prevStaticModel */
        "testl %ebx, %ebx\n" /* prevStaticModel */
        "je .Lfb0e0c_000b12fb\n"
        "movl -0x38(%ebp), %eax\n" /* line 664 | prevEnt */
        "movw %di, 2(%eax)\n" /* modelnum */
        "jmp .Lfb0e0c_000b0f08\n"
        ".Lfb0e0c_000b12dd:\n"
        "movl %edx, %eax\n"
        "jmp .Lfb0e0c_000b0fba\n"
        ".Lfb0e0c_000b12e4:\n"
        "movl %edx, %eax\n"
        "jmp .Lfb0e0c_000b0f01\n"
        ".Lfb0e0c_000b12eb:\n"
        "movl %esi, %eax\n"
        "jmp .Lfb0e0c_000b1297\n"
        ".Lfb0e0c_000b12ef:\n"
        "movl -0x30(%ebp), %eax\n" /* line 714 | node */
        "movw %di, 0xa(%eax)\n" /* modelnum */
        "jmp .Lfb0e0c_000b0fc0\n"
        ".Lfb0e0c_000b12fb:\n"
        "movl -0x30(%ebp), %edx\n" /* line 662 | node */
        "movw %di, 8(%edx)\n" /* modelnum */
        "jmp .Lfb0e0c_000b0f08\n"
        /* { scope 2 */
        ".Lfb0e0c_000b1307:\n"
        "movzwl %dx, %esi\n" /* line 116 */
        "leal (%esi, %esi, 2), %edx\n"
        "leal 0x4ed89c(, %edx, 8), %edx\n"
        "movzwl 0x12(%edx), %eax\n" /* line 125 */
        "movw %ax, 0x4ed89a\n"
        "movw %bx, 0x10(%edx)\n" /* line 127 | axis */
        "movl -0x58(%ebp), %eax\n" /* line 128 */
        "movss (%eax, %ecx, 4), %xmm0\n"
        "movl -0x54(%ebp), %eax\n"
        "addss (%eax, %ecx, 4), %xmm0\n"
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, 0xc(%edx)\n"
        /* } scope */
        "testw %si, %si\n" /* line 679 */
        "je .Lfb0e0c_000b0fb7\n"
        "movl -0x30(%ebp), %edx\n" /* line 681 | node */
        "movw %si, 0x14(%edx)\n"
        "movzwl %si, %esi\n" /* line 682 */
        "leal (%esi, %esi, 2), %eax\n"
        "movzwl -0x4e(%ebp), %edx\n"
        "movw %dx, 0x4ed8ae(, %eax, 8)\n"
        "jmp .Lfb0e0c_000b10a7\n"
        /* { scope 2 */
        ".Lfb0e0c_000b1366:\n"
        "movzwl %dx, %esi\n" /* line 116 */
        "leal (%esi, %esi, 2), %edx\n"
        "leal 0x4ed89c(, %edx, 8), %edx\n"
        "movzwl 0x12(%edx), %eax\n" /* line 125 */
        "movw %ax, 0x4ed89a\n"
        "movw %bx, 0x10(%edx)\n" /* line 127 | axis */
        "movl -0x58(%ebp), %eax\n" /* line 128 */
        "movss (%eax, %ecx, 4), %xmm0\n"
        "movl -0x54(%ebp), %eax\n"
        "addss (%eax, %ecx, 4), %xmm0\n"
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, 0xc(%edx)\n"
        /* } scope */
        "testw %si, %si\n" /* line 627 */
        "je .Lfb0e0c_000b0efe\n"
        "movl -0x30(%ebp), %edx\n" /* line 629 | node */
        "movw %si, 0x14(%edx)\n"
        "movzwl %si, %esi\n" /* line 630 */
        "leal (%esi, %esi, 2), %eax\n"
        "movzwl -0x4e(%ebp), %edx\n"
        "movw %dx, 0x4ed8ae(, %eax, 8)\n"
        "jmp .Lfb0e0c_000b1219\n"
    );
}

/* line 173 */
__attribute__((naked))
void CM_LinkWorld(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 173 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl $0x601c, 8(%esp)\n" /* line 147 */
        "movl $0, 4(%esp)\n"
        "movl $cm_world, (%esp)\n"
        "calll memset\n"
        "movl $0x4ed88c, 8(%esp)\n" /* line 150 */
        "movl $cm_world, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll CM_ModelBounds\n"
        "movw $2, 0x4ed89a\n" /* line 154 */
        "movl $3, %eax\n"
        "movl $cm_world, %edx\n"
        ".Lfb13c6_000b141a:\n"
        "movw %ax, 0x5e(%edx)\n" /* line 156 */
        "addl $1, %eax\n"
        "addl $0x18, %edx\n"
        "cmpl $0x400, %eax\n" /* line 155 */
        "jne .Lfb13c6_000b141a\n"
        "movw $0, 0x4f3896\n" /* line 157 */
        "movss 0x4ed88c, %xmm1\n" /* line 160 */
        "subss cm_world, %xmm1\n"
        "movss 0x4ed890, %xmm0\n"
        "subss 0x4ed884, %xmm0\n"
        "xorl %eax, %eax\n"
        "ucomiss %xmm1, %xmm0\n"
        "setae %al\n"
        "movw %ax, 0x4ed8c4\n"
        "movzwl %ax, %eax\n" /* line 161 */
        "movss 0x4ed88c(, %eax, 4), %xmm0\n"
        "addss cm_world(, %eax, 4), %xmm0\n"
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, 0x4ed8c0\n"
        "movl 0x195eda4, %eax\n" /* line 889 */
        "movl 8(%eax), %esi\n"
        "movl 4(%eax), %edi\n"
        "testl %edi, %edi\n"
        "jg .Lfb13c6_000b149e\n"
        ".Lfb13c6_000b1496:\n"
        "addl $0x3c, %esp\n" /* line 177 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfb13c6_000b149e:\n"
        "movl $0, -0x30(%ebp)\n" /* line 889 */
        "movl %eax, -0x34(%ebp)\n"
        "jmp .Lfb13c6_000b14bc\n"
        ".Lfb13c6_000b14aa:\n"
        "addl $1, -0x30(%ebp)\n"
        "addl $0x50, %esi\n"
        "movl -0x30(%ebp), %eax\n"
        "movl -0x34(%ebp), %edx\n"
        "cmpl 4(%edx), %eax\n"
        "jge .Lfb13c6_000b1496\n"
        ".Lfb13c6_000b14bc:\n"
        "movl 4(%esi), %eax\n" /* line 892 */
        "movl %eax, (%esp)\n"
        "calll XModelGetContents\n"
        "testl %eax, %eax\n"
        "je .Lfb13c6_000b14aa\n"
        "movl 4(%esi), %eax\n" /* line 832 */
        "movl %eax, (%esp)\n"
        "calll XModelGetContents\n"
        "movl %eax, %ecx\n"
        "movl cm_world, %eax\n" /* line 37 */
        "movl %eax, -0x20(%ebp)\n"
        "movl 0x4ed884, %eax\n" /* line 38 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0x4ed88c, %eax\n" /* line 37 */
        "movl %eax, -0x28(%ebp)\n"
        "movl 0x4ed890, %eax\n" /* line 38 */
        "movl %eax, -0x24(%ebp)\n"
        "movl $1, %eax\n"
        "movl $0x4ed890, %edi\n"
        ".Lfb13c6_000b1502:\n"
        "movzwl %ax, %ebx\n" /* line 841 */
        "leal (%ebx, %ebx, 2), %eax\n"
        "shll $3, %eax\n"
        "movl %ecx, %edx\n"
        "orl 0x4ed89c(%eax), %edx\n"
        "movl %edx, 0xc(%eax, %edi)\n"
        "addl $0x4ed89c, %eax\n" /* line 843 */
        "movzwl 0x10(%eax), %edx\n" /* line 844 */
        "movss 0xc(%eax), %xmm1\n" /* line 845 */
        "movss 0x38(%esi, %edx, 4), %xmm0\n" /* line 847 */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lfb13c6_000b15b6\n"
        "movss %xmm1, -0x20(%ebp, %edx, 4)\n" /* line 849 */
        "movzwl 0x14(%eax), %eax\n" /* line 850 */
        "testw %ax, %ax\n"
        "jne .Lfb13c6_000b1502\n"
        ".Lfb13c6_000b1543:\n"
        "movl -0x34(%ebp), %eax\n" /* line 576 */
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl %esi, %ecx\n"
        "subl %eax, %ecx\n"
        "sarl $4, %ecx\n"
        "leal (%ecx, %ecx, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $8, %edx\n"
        "addl %edx, %eax\n"
        "leal (%ecx, %eax, 4), %ecx\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 577 */
        "leal 0x4ed890(, %eax, 8), %eax\n"
        "leal 0x16(%eax), %edi\n"
        "movzwl 0x16(%eax), %edx\n" /* line 579 */
        "leal -1(%edx), %eax\n"
        "cmpw %cx, %ax\n"
        "ja .Lfb13c6_000b159b\n"
        ".Lfb13c6_000b1580:\n"
        "movzwl %dx, %eax\n" /* line 577 */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $4, %eax\n"
        "addl -0x2c(%ebp), %eax\n"
        "leal -0x50(%eax), %edi\n"
        "movzwl -0x50(%eax), %edx\n" /* line 579 */
        "leal -1(%edx), %eax\n"
        "cmpw %cx, %ax\n"
        "jbe .Lfb13c6_000b1580\n"
        ".Lfb13c6_000b159b:\n"
        "movw %dx, (%esi)\n" /* line 583 */
        "leal 1(%ecx), %eax\n" /* line 584 */
        "movw %ax, (%edi)\n"
        "leal -0x28(%ebp), %ecx\n" /* line 874 */
        "leal -0x20(%ebp), %edx\n"
        "movl %ebx, %eax\n"
        "calll CM_SortNode\n"
        "jmp .Lfb13c6_000b14aa\n"
        ".Lfb13c6_000b15b6:\n"
        "ucomiss 0x44(%esi, %edx, 4), %xmm1\n" /* line 858 */
        "jbe .Lfb13c6_000b1543\n"
        "movss %xmm1, -0x28(%ebp, %edx, 4)\n" /* line 860 */
        "movzwl 0x16(%eax), %eax\n" /* line 861 */
        "testw %ax, %ax\n"
        "jne .Lfb13c6_000b1502\n"
        "jmp .Lfb13c6_000b1543\n"
    );
}

/* line 727 */
__attribute__((naked))
void CM_LinkEntity(svEntity_t *ent, vec_t *absmin, vec_t *absmax, clipHandle_t clipHandle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 727 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl 0x14(%ebp), %eax\n" /* line 739 | clipHandle */
        "movl %eax, (%esp)\n"
        "calll CM_ClipHandleToModel\n"
        "movl 0x20(%eax), %edx\n" /* line 742 */
        "orl 0x24(%eax), %edx\n" /* line 743 */
        "movl %edx, -0x2c(%ebp)\n" /* contents */
        "jne .Lfb15d6_000b1831\n"
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 462 | ent */
        "movzwl (%eax), %ebx\n" /* nodeIndex */
        "testw %bx, %bx\n" /* line 463 | nodeIndex */
        "je .Lfb15d6_000b1829\n"
        "movzwl %bx, %eax\n" /* line 465 | nodeIndex */
        "leal (%eax, %eax, 2), %eax\n"
        "leal 0x4ed89c(, %eax, 8), %edi\n" /* node */
        "movl 8(%ebp), %edx\n" /* line 466 | ent */
        "movw $0, (%edx)\n"
        "movzwl 8(%edi), %eax\n" /* line 470 | node */
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl 0x195ee80, %esi\n" /* nodeIndex */
        "movl %esi, -0x34(%ebp)\n" /* nodeIndex */
        "leal 0x22a4(%esi, %edx, 4), %ecx\n" /* nodeIndex */
        "cmpl %ecx, 8(%ebp)\n" /* ent */
        "jne .Lfb15d6_000b164a\n"
        "jmp .Lfb15d6_000b1abb\n"
        ".Lfb15d6_000b1645:\n"
        "movl %eax, %ecx\n" /* line 478 */
        "movl -0x34(%ebp), %esi\n" /* nodeIndex */
        ".Lfb15d6_000b164a:\n"
        "movzwl 2(%ecx), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "leal 0x22a4(%esi, %edx, 4), %eax\n" /* nodeIndex */
        "cmpl %eax, 8(%ebp)\n" /* ent */
        "jne .Lfb15d6_000b1645\n"
        "movl 8(%ebp), %edx\n" /* line 480 | ent */
        "movzwl 2(%edx), %eax\n"
        "movw %ax, 2(%ecx)\n"
        ".Lfb15d6_000b166f:\n"
        "movl 8(%edi), %eax\n" /* line 487 | node */
        "testl %eax, %eax\n"
        "jne .Lfb15d6_000b16c5\n"
        ".Lfb15d6_000b1676:\n"
        "movl 0x14(%edi), %eax\n" /* node */
        "testl %eax, %eax\n"
        "jne .Lfb15d6_000b16c5\n"
        "movl $0, 4(%edi)\n" /* line 490 | node */
        "movzwl 0x12(%edi), %edx\n" /* line 492 | node */
        "testw %dx, %dx\n"
        "je .Lfb15d6_000b16c5\n"
        "movzwl 0x4ed89a, %eax\n" /* line 500 */
        "movw %ax, 0x12(%edi)\n" /* node */
        "movw %bx, 0x4ed89a\n" /* line 501 | nodeIndex */
        "movzwl %dx, %eax\n" /* line 503 */
        "leal (%eax, %eax, 2), %eax\n"
        "leal 0x4ed89c(, %eax, 8), %edi\n" /* node */
        "cmpw 0x14(%edi), %bx\n" /* line 505 | node, nodeIndex */
        "je .Lfb15d6_000b1a6f\n"
        "movw $0, 0x16(%edi)\n" /* line 512 | node */
        "movl %edx, %ebx\n" /* nodeIndex */
        ".Lfb15d6_000b16be:\n"
        "movl 8(%edi), %eax\n" /* line 487 | node */
        "testl %eax, %eax\n"
        "je .Lfb15d6_000b1676\n"
        ".Lfb15d6_000b16c5:\n"
        "movzwl 0x14(%edi), %edx\n" /* line 520 | node */
        "leal (%edx, %edx, 2), %edx\n"
        "movzwl 0x16(%edi), %eax\n" /* node */
        "leal (%eax, %eax, 2), %eax\n"
        "movl 0x4ed8a0(, %edx, 8), %esi\n" /* nodeIndex */
        "orl 0x4ed8a0(, %eax, 8), %esi\n" /* nodeIndex */
        "movzwl 8(%edi), %eax\n" /* line 521 | node */
        "testw %ax, %ax\n"
        "je .Lfb15d6_000b1739\n"
        "movzwl %ax, %eax\n" /* line 523 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl 0x195ee80, %eax\n"
        "leal 0x22a4(%eax, %edx, 4), %ebx\n" /* nodeIndex */
        "jmp .Lfb15d6_000b1722\n"
        ".Lfb15d6_000b1705:\n"
        "movzwl %ax, %edx\n"
        "leal (%edx, %edx, 2), %edx\n"
        "movl %edx, %eax\n"
        "shll $5, %eax\n"
        "subl %edx, %eax\n"
        "leal 0x229c(, %eax, 4), %eax\n"
        "addl 0x195ee80, %eax\n"
        "leal 8(%eax), %ebx\n" /* nodeIndex */
        ".Lfb15d6_000b1722:\n"
        "movl %ebx, (%esp)\n" /* line 525 | nodeIndex */
        "calll SV_GEntityForSvEntity\n"
        "orl 0x11c(%eax), %esi\n" /* nodeIndex */
        "movzwl 2(%ebx), %eax\n" /* line 526 | nodeIndex */
        "testw %ax, %ax\n"
        "jne .Lfb15d6_000b1705\n"
        ".Lfb15d6_000b1739:\n"
        "movl %esi, 4(%edi)\n" /* line 530 | nodeIndex, node */
        "movzwl 0x12(%edi), %eax\n" /* line 532 | node */
        "testw %ax, %ax\n" /* line 533 */
        "je .Lfb15d6_000b1829\n"
        "movzwl %ax, %eax\n" /* line 536 */
        "leal (%eax, %eax, 2), %eax\n"
        "leal 0x4ed89c(, %eax, 8), %edi\n" /* node */
        "jmp .Lfb15d6_000b16c5\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfb15d6_000b175b:\n"
        "movl 0x195ee80, %esi\n" /* line 552 | entnum */
        "movl %esi, -0x34(%ebp)\n" /* entnum */
        "leal 0x2418(%esi), %eax\n" /* entnum */
        "movl 8(%ebp), %edx\n" /* ent */
        "subl %eax, %edx\n"
        "sarl $2, %edx\n"
        "movl %edx, %eax\n"
        "shll $6, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, %ecx\n"
        "shll $0xa, %ecx\n"
        "addl %ecx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "shll $6, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal (%edx, %eax, 4), %esi\n" /* entnum */
        "movl %ebx, %edi\n" /* line 553 | nodeIndex, node */
        "leal (%ebx, %ebx, 2), %eax\n" /* nodeIndex */
        "leal 0x4ed890(, %eax, 8), %eax\n"
        "leal 0x14(%eax), %ecx\n"
        "movzwl 0x14(%eax), %edx\n" /* line 555 */
        "leal -1(%edx), %eax\n"
        "cmpw %si, %ax\n" /* entnum */
        "ja .Lfb15d6_000b17d2\n"
        ".Lfb15d6_000b17ac:\n"
        "movzwl %dx, %eax\n" /* line 553 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl -0x34(%ebp), %eax\n"
        "leal 0x229c(%eax, %edx, 4), %edx\n"
        "leal 0xa(%edx), %ecx\n"
        "movzwl 0xa(%edx), %edx\n" /* line 555 */
        "leal -1(%edx), %eax\n"
        "cmpw %ax, %si\n" /* entnum */
        "jae .Lfb15d6_000b17ac\n"
        ".Lfb15d6_000b17d2:\n"
        "movl 8(%ebp), %edx\n" /* line 559 | ent */
        "movw %di, (%edx)\n" /* node */
        "movzwl (%ecx), %eax\n" /* line 560 */
        "movw %ax, 2(%edx)\n"
        "leal 1(%esi), %eax\n" /* line 561 | entnum */
        "movw %ax, (%ecx)\n"
        /* } scope */
        /* } scope */
        ".Lfb15d6_000b17e5:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 808 | contents */
        "movl 8(%ebp), %esi\n" /* ent, entnum */
        "movl %eax, 0x160(%esi)\n" /* entnum */
        "movl 0xc(%ebp), %edx\n" /* line 37 | absmin */
        "movl (%edx), %eax\n"
        "movl %eax, 0x164(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 38 */
        "movl %eax, 0x168(%esi)\n"
        "movl 0x10(%ebp), %esi\n" /* line 37 | absmax */
        "movl (%esi), %eax\n"
        "movl 8(%ebp), %edx\n" /* ent */
        "movl %eax, 0x16c(%edx)\n"
        "movl 4(%esi), %eax\n" /* line 38 */
        "movl %eax, 0x170(%edx)\n"
        "leal -0x28(%ebp), %ecx\n" /* line 812 | maxs */
        "leal -0x20(%ebp), %edx\n" /* mins */
        "movl %ebx, %eax\n" /* nodeIndex */
        "calll CM_SortNode\n"
        /* } scope */
        ".Lfb15d6_000b1829:\n"
        "addl $0x3c, %esp\n" /* line 813 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfb15d6_000b1831:\n"
        "movl %edx, %ebx\n" /* nodeIndex */
        "notl %ebx\n" /* nodeIndex */
        "movl %ebx, -0x30(%ebp)\n" /* nodeIndex */
        "movl 0x195ee80, %esi\n" /* entnum */
        "movl %esi, -0x38(%ebp)\n" /* entnum */
        /* { scope 1 */
        ".Lfb15d6_000b1841:\n"
        "movl cm_world, %eax\n" /* line 37 */
        "movl %eax, -0x20(%ebp)\n" /* mins */
        "movl 0x4ed884, %eax\n" /* line 38 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0x4ed88c, %eax\n" /* line 37 */
        "movl %eax, -0x28(%ebp)\n" /* maxs */
        "movl 0x4ed890, %eax\n" /* line 38 */
        "movl %eax, -0x24(%ebp)\n"
        "movl $1, %edi\n"
        ".Lfb15d6_000b1866:\n"
        "movzwl %di, %ebx\n" /* line 756 | nodeIndex */
        "leal (%ebx, %ebx, 2), %eax\n" /* nodeIndex */
        "shll $3, %eax\n"
        "movl -0x2c(%ebp), %edx\n" /* contents */
        "orl 0x4ed8a0(%eax), %edx\n"
        "movl %edx, 0x4ed8a0(%eax)\n"
        "addl $0x4ed89c, %eax\n" /* line 758 */
        "movzwl 0x10(%eax), %edx\n" /* line 759 */
        "movss 0xc(%eax), %xmm1\n" /* line 760 */
        "leal (, %edx, 4), %ecx\n" /* line 762 */
        "movl 0xc(%ebp), %esi\n" /* absmin, entnum */
        "movss (%ecx, %esi), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lfb15d6_000b1a1a\n"
        "movss %xmm1, -0x20(%ebp, %edx, 4)\n" /* line 764 */
        "movzwl 0x14(%eax), %eax\n" /* line 765 */
        "testw %ax, %ax\n"
        "je .Lfb15d6_000b18ce\n"
        "movl %eax, %edi\n" /* line 38 */
        "jmp .Lfb15d6_000b1866\n"
        ".Lfb15d6_000b18b7:\n"
        "movl 8(%ebp), %eax\n" /* line 785 | ent */
        "cmpw (%eax), %di\n" /* nodeIndex */
        "jne .Lfb15d6_000b18d1\n"
        "movl -0x30(%ebp), %edx\n"
        "testl %edx, 0x160(%eax)\n"
        "je .Lfb15d6_000b1a7c\n"
        ".Lfb15d6_000b18ce:\n"
        "movl 8(%ebp), %eax\n" /* ent */
        ".Lfb15d6_000b18d1:\n"
        "movzwl (%eax), %esi\n" /* line 795 | entnum */
        "testw %si, %si\n" /* entnum */
        "je .Lfb15d6_000b175b\n"
        "cmpw %di, %si\n" /* line 797 | nodeIndex, entnum */
        "je .Lfb15d6_000b1a4e\n"
        /* { scope 2 */
        ".Lfb15d6_000b18e6:\n"
        "movzwl %si, %eax\n" /* line 465 | nodeIndex */
        "leal (%eax, %eax, 2), %eax\n"
        "leal 0x4ed89c(, %eax, 8), %edi\n" /* node */
        "movl 8(%ebp), %ebx\n" /* line 466 | ent, nodeIndex */
        "movw $0, (%ebx)\n" /* nodeIndex */
        "movzwl 8(%edi), %eax\n" /* line 470 | node */
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "leal 0x22a4(%eax, %edx, 4), %ecx\n"
        "cmpl %ecx, %ebx\n" /* nodeIndex */
        "je .Lfb15d6_000b1a62\n"
        "movl %eax, %ebx\n" /* nodeIndex */
        "jmp .Lfb15d6_000b1927\n"
        ".Lfb15d6_000b1922:\n"
        "movl %eax, %ecx\n" /* line 478 */
        "movl -0x34(%ebp), %ebx\n" /* nodeIndex */
        ".Lfb15d6_000b1927:\n"
        "movzwl 2(%ecx), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "leal 0x22a4(%ebx, %edx, 4), %eax\n" /* nodeIndex */
        "cmpl %eax, 8(%ebp)\n" /* ent */
        "jne .Lfb15d6_000b1922\n"
        "movl 8(%ebp), %edx\n" /* line 480 | ent */
        "movzwl 2(%edx), %eax\n"
        "movw %ax, 2(%ecx)\n"
        ".Lfb15d6_000b194c:\n"
        "movl 8(%edi), %eax\n" /* line 487 | node */
        "testl %eax, %eax\n"
        "jne .Lfb15d6_000b19a2\n"
        ".Lfb15d6_000b1953:\n"
        "movl 0x14(%edi), %eax\n" /* node */
        "testl %eax, %eax\n"
        "jne .Lfb15d6_000b19a2\n"
        "movl $0, 4(%edi)\n" /* line 490 | node */
        "movzwl 0x12(%edi), %edx\n" /* line 492 | node */
        "testw %dx, %dx\n"
        "je .Lfb15d6_000b19a2\n"
        "movzwl 0x4ed89a, %eax\n" /* line 500 */
        "movw %ax, 0x12(%edi)\n" /* node */
        "movw %si, 0x4ed89a\n" /* line 501 | nodeIndex */
        "movzwl %dx, %eax\n" /* line 503 */
        "leal (%eax, %eax, 2), %eax\n"
        "leal 0x4ed89c(, %eax, 8), %edi\n" /* node */
        "cmpw 0x14(%edi), %si\n" /* line 505 | node, nodeIndex */
        "je .Lfb15d6_000b1a41\n"
        "movw $0, 0x16(%edi)\n" /* line 512 | node */
        "movl %edx, %esi\n" /* nodeIndex */
        ".Lfb15d6_000b199b:\n"
        "movl 8(%edi), %eax\n" /* line 487 | node */
        "testl %eax, %eax\n"
        "je .Lfb15d6_000b1953\n"
        ".Lfb15d6_000b19a2:\n"
        "movzwl 0x14(%edi), %edx\n" /* line 520 | node */
        "leal (%edx, %edx, 2), %edx\n"
        "movzwl 0x16(%edi), %eax\n" /* node */
        "leal (%eax, %eax, 2), %eax\n"
        "movl 0x4ed8a0(, %edx, 8), %esi\n" /* nodeIndex */
        "orl 0x4ed8a0(, %eax, 8), %esi\n" /* nodeIndex */
        "movzwl 8(%edi), %eax\n" /* line 521 | node */
        "testw %ax, %ax\n"
        "je .Lfb15d6_000b19fb\n"
        ".Lfb15d6_000b19c7:\n"
        "movzwl %ax, %edx\n" /* line 523 */
        "leal (%edx, %edx, 2), %edx\n"
        "movl %edx, %eax\n"
        "shll $5, %eax\n"
        "subl %edx, %eax\n"
        "leal 0x229c(, %eax, 4), %eax\n"
        "addl 0x195ee80, %eax\n"
        "leal 8(%eax), %ebx\n" /* nodeIndex */
        "movl %ebx, (%esp)\n" /* line 525 | nodeIndex */
        "calll SV_GEntityForSvEntity\n"
        "orl 0x11c(%eax), %esi\n" /* nodeIndex */
        "movzwl 2(%ebx), %eax\n" /* line 526 | nodeIndex */
        "testw %ax, %ax\n"
        "jne .Lfb15d6_000b19c7\n"
        ".Lfb15d6_000b19fb:\n"
        "movl %esi, 4(%edi)\n" /* line 530 | nodeIndex, node */
        "movzwl 0x12(%edi), %eax\n" /* line 532 | node */
        "testw %ax, %ax\n" /* line 533 */
        "je .Lfb15d6_000b1841\n"
        "movzwl %ax, %eax\n" /* line 536 */
        "leal (%eax, %eax, 2), %eax\n"
        "leal 0x4ed89c(, %eax, 8), %edi\n" /* node */
        "jmp .Lfb15d6_000b19a2\n"
        /* } scope */
        ".Lfb15d6_000b1a1a:\n"
        "movl 0x10(%ebp), %esi\n" /* line 773 | absmax, entnum */
        "ucomiss (%ecx, %esi), %xmm1\n"
        "jbe .Lfb15d6_000b18b7\n"
        "movss %xmm1, -0x28(%ebp, %edx, 4)\n" /* line 775 */
        "movzwl 0x16(%eax), %eax\n" /* line 776 */
        "testw %ax, %ax\n"
        "je .Lfb15d6_000b18ce\n"
        "movl %eax, %edi\n" /* line 38 */
        "jmp .Lfb15d6_000b1866\n"
        /* { scope 2 */
        ".Lfb15d6_000b1a41:\n"
        "movw $0, 0x14(%edi)\n" /* line 507 | node */
        "movl %edx, %esi\n" /* line 512 | nodeIndex */
        "jmp .Lfb15d6_000b199b\n"
        /* } scope */
        ".Lfb15d6_000b1a4e:\n"
        "movl -0x30(%ebp), %edx\n" /* line 797 */
        "testl %edx, 0x160(%eax)\n"
        "jne .Lfb15d6_000b18e6\n"
        "jmp .Lfb15d6_000b17e5\n"
        /* { scope 2 */
        ".Lfb15d6_000b1a62:\n"
        "movzwl 2(%ebx), %eax\n" /* line 472 | nodeIndex */
        "movw %ax, 8(%edi)\n" /* node */
        "jmp .Lfb15d6_000b194c\n"
        /* } scope */
        /* { scope 2 */
        ".Lfb15d6_000b1a6f:\n"
        "movw $0, 0x14(%edi)\n" /* line 507 | node */
        "movl %edx, %ebx\n" /* line 512 | nodeIndex */
        "jmp .Lfb15d6_000b16be\n"
        /* } scope */
        ".Lfb15d6_000b1a7c:\n"
        "movl -0x2c(%ebp), %esi\n" /* line 787 | contents, entnum */
        "movl 8(%ebp), %ebx\n" /* ent, nodeIndex */
        "movl %esi, 0x160(%ebx)\n" /* entnum, nodeIndex */
        "movl 0xc(%ebp), %edx\n" /* line 37 | absmin */
        "movl (%edx), %eax\n"
        "movl %eax, 0x164(%ebx)\n"
        "movl 4(%edx), %eax\n" /* line 38 */
        "movl %eax, 0x168(%ebx)\n"
        "movl 0x10(%ebp), %ebx\n" /* line 37 | absmax */
        "movl (%ebx), %eax\n"
        "movl 8(%ebp), %esi\n" /* ent */
        "movl %eax, 0x16c(%esi)\n"
        "movl 4(%ebx), %eax\n" /* line 38 */
        "movl %eax, 0x170(%esi)\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 813 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfb15d6_000b1abb:\n"
        "movl 8(%ebp), %edx\n" /* line 472 | ent */
        "movzwl 2(%edx), %eax\n"
        "movw %ax, 8(%edi)\n" /* node */
        "jmp .Lfb15d6_000b166f\n"
    );
}

