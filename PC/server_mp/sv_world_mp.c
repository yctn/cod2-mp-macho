/* ASM dump from: sv_world_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/server_mp/sv_world_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

static vec3_t actorLocationalMins; /* 0x31454c */
static vec3_t actorLocationalMaxs; /* 0x314540 */

clipHandle_t SV_ClipHandleForEntity(const gentity_t *ent);
int SV_UnlinkEntity(gentity_t *gEnt);
int SV_SightTrace(int *hitNum, const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int passEntityNum0, int passEntityNum1, int contentmask);
int SV_Trace(trace_t *results, const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int passEntityNum, int contentmask, qboolean locational, unsigned char *priorityMap, qboolean staticmodels);
qboolean SV_TracePassed(const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int passEntityNum0, int passEntityNum1, int contentmask, qboolean locational, qboolean staticmodels);
int SV_LinkEntity(gentity_t *gEnt);
int SV_ClipMoveToEntity(const moveclip_t *clip, svEntity_t *check, trace_t *trace);
int SV_PointTraceToEntity(const pointtrace_t *clip, svEntity_t *check, trace_t *trace);
int SV_ClipSightToEntity(const sightclip_t *clip, svEntity_t *check);
int SV_PointSightTraceToEntity(const sightpointtrace_t *clip, svEntity_t *check);
int SV_SightTraceToEntity(const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int entityNum, int contentmask);
int SV_PointContents(const vec_t *p, int passEntityNum, int contentmask);

/* line 24 */
__attribute__((naked))
clipHandle_t SV_ClipHandleForEntity(const gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 24 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %edx\n" /* ent */
        "cmpb $0, 0xf1(%edx)\n" /* line 26 */
        "je .Lf1bbef8_001bbf12\n"
        "movl 0x8c(%edx), %eax\n" /* line 29 */
        "leave\n" /* line 34 */
        "retl\n"
        ".Lf1bbef8_001bbf12:\n"
        "movl 0x11c(%edx), %eax\n" /* line 33 */
        "movl %eax, 8(%esp)\n"
        "leal 0x110(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x104(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_TempBoxModel\n"
        "leave\n" /* line 34 */
        "retl\n"
    );
}

/* line 43 */
__attribute__((naked))
int SV_UnlinkEntity(gentity_t *gEnt)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 43 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* gEnt */
        /* { scope 1 */
        "movl %ebx, (%esp)\n" /* line 47 | gEnt */
        "calll SV_SvEntityForGentity\n"
        "movb $0, 0xf0(%ebx)\n" /* line 49 | gEnt */
        "movl %eax, 8(%ebp)\n" /* line 52 | gEnt */
        /* } scope */
        "addl $0x14, %esp\n" /* line 54 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CM_UnlinkEntity\n" /* line 52 */
    );
}

/* line 817 */
__attribute__((naked))
int SV_SightTrace(int *hitNum, const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int passEntityNum0, int passEntityNum1, int contentmask)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 817 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl 0x10(%ebp), %esi\n" /* mins */
        "movl 0x14(%ebp), %ebx\n" /* maxs */
        "movl 0x24(%ebp), %edi\n" /* contentmask */
        "movl %edi, 0x18(%esp)\n" /* line 833 | contentmask */
        "movl $0, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n" /* maxs */
        "movl %esi, 0xc(%esp)\n" /* mins */
        "movl 0x18(%ebp), %eax\n" /* end */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* start */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* hitNum */
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_BoxSightTrace\n"
        "movl 8(%ebp), %edx\n" /* hitNum */
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 834 */
        "jne .Lf1bbf5c_001bc034\n"
        "leal 4(%ebx), %edx\n" /* line 844 | maxs */
        "leal 4(%esi), %eax\n" /* mins */
        "movl %eax, -0x6c(%ebp)\n"
        "leal 8(%ebx), %eax\n" /* maxs */
        "leal 8(%esi), %ecx\n" /* mins */
        "movss (%ebx), %xmm7\n" /* maxs */
        "movaps %xmm7, %xmm0\n"
        "subss (%esi), %xmm0\n" /* mins */
        "addss 4(%ebx), %xmm0\n" /* maxs */
        "subss 4(%esi), %xmm0\n" /* mins */
        "addss 8(%ebx), %xmm0\n" /* maxs */
        "subss 8(%esi), %xmm0\n" /* mins */
        "ucomiss 0x2ed5e8, %xmm0\n" /* 0.0f */
        "jne .Lf1bbf5c_001bc03f\n"
        "jp .Lf1bbf5c_001bc03f\n"
        /* { scope 1 */
        "movl %edi, -0x40(%ebp)\n" /* line 848 | contentmask */
        "movl 0xc(%ebp), %edx\n" /* line 199 | start */
        "movl (%edx), %eax\n"
        "movl %eax, -0x60(%ebp)\n" /* clip */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x5c(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x58(%ebp)\n"
        "movl 0x18(%ebp), %ebx\n" /* line 199 | end */
        "movl (%ebx), %eax\n"
        "movl %eax, -0x54(%ebp)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, -0x50(%ebp)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, -0x4c(%ebp)\n"
        "movl 0x1c(%ebp), %eax\n" /* line 851 | passEntityNum0 */
        "movl %eax, -0x48(%ebp)\n"
        "movl 0x20(%ebp), %edx\n" /* line 852 | passEntityNum1 */
        "movl %edx, -0x44(%ebp)\n"
        "movl $0, -0x3c(%ebp)\n" /* line 853 */
        "leal -0x60(%ebp), %eax\n" /* line 856 | clip */
        "movl %eax, (%esp)\n"
        "calll CM_PointSightTraceToEntities\n"
        "movl 8(%ebp), %ebx\n" /* hitNum, maxs */
        "movl %eax, (%ebx)\n" /* maxs */
        /* } scope */
        ".Lf1bbf5c_001bc034:\n"
        "addl $0x8c, %esp\n" /* line 887 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bbf5c_001bc03f:\n"
        "movl %edi, -0x1c(%ebp)\n" /* line 862 | contentmask */
        "movl 0x1c(%ebp), %ebx\n" /* line 863 | passEntityNum0, maxs */
        "movl %ebx, -0x24(%ebp)\n" /* maxs */
        "movl 0x20(%ebp), %ebx\n" /* line 864 | passEntityNum1, maxs */
        "movl %ebx, -0x20(%ebp)\n" /* maxs */
        "movaps %xmm7, %xmm2\n" /* line 248 */
        "subss (%esi), %xmm2\n"
        "movss (%edx), %xmm5\n" /* line 249 */
        "movaps %xmm5, %xmm3\n"
        "movl -0x6c(%ebp), %edx\n"
        "subss (%edx), %xmm3\n"
        "movss (%eax), %xmm6\n" /* line 250 */
        "movaps %xmm6, %xmm4\n"
        "subss (%ecx), %xmm4\n"
        "mulss 0x2ed5d8, %xmm2\n" /* line 272 | 0.5f */
        "mulss 0x2ed5d8, %xmm3\n" /* line 273 | 0.5f */
        "mulss 0x2ed5d8, %xmm4\n" /* line 274 | 0.5f */
        "movss %xmm2, -0x54(%ebp)\n" /* line 199 */
        "movss %xmm3, -0x50(%ebp)\n" /* line 200 */
        "movss %xmm4, -0x4c(%ebp)\n" /* line 201 */
        "movss 0x303280, %xmm0\n" /* line 272 */
        "movaps %xmm2, %xmm1\n"
        "xorps %xmm0, %xmm1\n"
        "movss %xmm1, -0x60(%ebp)\n" /* clip */
        "movaps %xmm3, %xmm1\n" /* line 273 */
        "xorps %xmm0, %xmm1\n"
        "movss %xmm1, -0x5c(%ebp)\n"
        "xorps %xmm4, %xmm0\n" /* line 274 */
        "movss %xmm0, -0x58(%ebp)\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 872 | 1.0f */
        "addss %xmm0, %xmm2\n"
        "movss %xmm2, -0x48(%ebp)\n"
        "addss %xmm0, %xmm3\n" /* line 873 */
        "movss %xmm3, -0x44(%ebp)\n"
        "addss %xmm0, %xmm4\n" /* line 874 */
        "movss %xmm4, -0x40(%ebp)\n"
        "movaps %xmm7, %xmm1\n" /* line 240 */
        "addss (%esi), %xmm1\n"
        "addss (%edx), %xmm5\n" /* line 241 */
        "addss (%ecx), %xmm6\n" /* line 242 */
        "mulss 0x2ed5d8, %xmm1\n" /* line 272 | 0.5f */
        "mulss 0x2ed5d8, %xmm5\n" /* line 273 | 0.5f */
        "mulss 0x2ed5d8, %xmm6\n" /* line 274 | 0.5f */
        "movaps %xmm1, %xmm0\n" /* line 240 */
        "movl 0xc(%ebp), %ebx\n" /* start */
        "addss (%ebx), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "movaps %xmm5, %xmm0\n" /* line 241 */
        "addss 4(%ebx), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "movaps %xmm6, %xmm0\n" /* line 242 */
        "addss 8(%ebx), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "movl 0x18(%ebp), %eax\n" /* line 240 | end */
        "addss (%eax), %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n"
        "addss 4(%eax), %xmm5\n" /* line 241 */
        "movss %xmm5, -0x2c(%ebp)\n"
        "addss 8(%eax), %xmm6\n" /* line 242 */
        "movss %xmm6, -0x28(%ebp)\n"
        "leal -0x60(%ebp), %eax\n" /* line 883 | clip */
        "movl %eax, (%esp)\n"
        "calll CM_ClipSightTraceToEntities\n"
        "movl 8(%ebp), %edx\n" /* hitNum */
        "movl %eax, (%edx)\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 887 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 604 */
__attribute__((naked))
int SV_Trace(trace_t *results, const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int passEntityNum, int contentmask, qboolean locational, unsigned char *priorityMap, qboolean staticmodels)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 604 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl 0x10(%ebp), %esi\n" /* mins */
        "movl 0x14(%ebp), %ebx\n" /* maxs */
        "movl 0x20(%ebp), %edi\n" /* contentmask */
        "movl %edi, 0x18(%esp)\n" /* line 620 | contentmask */
        "movl $0, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n" /* maxs */
        "movl %esi, 0xc(%esp)\n" /* mins */
        "movl 0x18(%ebp), %eax\n" /* end */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* start */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* results */
        "movl %eax, (%esp)\n"
        "calll CM_BoxTrace\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 621 | 1.0f */
        "movl 8(%ebp), %edx\n" /* results */
        "ucomiss (%edx), %xmm0\n"
        "sete %al\n"
        "setnp %dl\n"
        "andb %dl, %al\n"
        "movzbw %al, %ax\n"
        "addw $0x3fe, %ax\n"
        "movl 8(%ebp), %edx\n" /* results */
        "movw %ax, 0x1c(%edx)\n"
        "pxor %xmm0, %xmm0\n" /* line 622 */
        "ucomiss (%edx), %xmm0\n"
        "jp .Lf1bc16a_001bc1e0\n"
        "je .Lf1bc16a_001bc300\n"
        ".Lf1bc16a_001bc1e0:\n"
        "movl 0x2c(%ebp), %eax\n" /* line 629 | staticmodels */
        "testl %eax, %eax\n"
        "jne .Lf1bc16a_001bc30b\n"
        ".Lf1bc16a_001bc1eb:\n"
        "leal 4(%ebx), %eax\n" /* line 643 | maxs */
        "movl %eax, -0x88(%ebp)\n"
        "leal 4(%esi), %edx\n" /* mins */
        "movl %edx, -0x84(%ebp)\n"
        "leal 8(%ebx), %eax\n" /* maxs */
        "movl %eax, -0x80(%ebp)\n"
        "leal 8(%esi), %edx\n" /* mins */
        "movl %edx, -0x7c(%ebp)\n"
        "movss (%ebx), %xmm0\n" /* maxs */
        "movss %xmm0, -0x8c(%ebp)\n"
        "subss (%esi), %xmm0\n" /* mins */
        "addss 4(%ebx), %xmm0\n" /* maxs */
        "subss 4(%esi), %xmm0\n" /* mins */
        "addss 8(%ebx), %xmm0\n" /* maxs */
        "subss 8(%esi), %xmm0\n" /* mins */
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "je .Lf1bc16a_001bc27b\n"
        /* { scope 1 */
        ".Lf1bc16a_001bc236:\n"
        "movl %edi, -0x1c(%ebp)\n" /* line 675 | contentmask */
        "movl 0x1c(%ebp), %edx\n" /* line 676 | passEntityNum */
        "movl %edx, -0x24(%ebp)\n"
        "cmpl $0x3ff, %edx\n" /* line 678 */
        "je .Lf1bc16a_001bc340\n"
        "movl %edx, (%esp)\n" /* line 680 */
        "calll SV_GentityNum\n"
        "movl 0x150(%eax), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "cmpl $0x3ff, %eax\n" /* line 681 */
        "je .Lf1bc16a_001bc47e\n"
        "movss (%ebx), %xmm1\n" /* maxs */
        "movss %xmm1, -0x8c(%ebp)\n"
        "movaps %xmm1, %xmm2\n"
        "jmp .Lf1bc16a_001bc34f\n"
        /* } scope */
        ".Lf1bc16a_001bc27b:\n"
        "jp .Lf1bc16a_001bc236\n" /* line 643 */
        /* { scope 1 */
        "movl %edi, -0x40(%ebp)\n" /* line 647 | contentmask */
        "movl 0xc(%ebp), %edx\n" /* line 199 | start */
        "movl (%edx), %eax\n"
        "movl %eax, -0x6c(%ebp)\n" /* clip */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x68(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x64(%ebp)\n"
        "movl 0x18(%ebp), %edx\n" /* line 199 | end */
        "movl (%edx), %eax\n"
        "movl %eax, -0x60(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x5c(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x58(%ebp)\n"
        "leal -0x6c(%ebp), %ebx\n" /* line 650 | clip, maxs */
        "movl %ebx, (%esp)\n" /* maxs */
        "calll CM_CalcTraceEntents\n"
        "movl 0x1c(%ebp), %eax\n" /* line 651 | passEntityNum */
        "movl %eax, -0x48(%ebp)\n"
        "movl 0x24(%ebp), %edx\n" /* line 652 | locational */
        "movl %edx, -0x3c(%ebp)\n"
        "movl 0x28(%ebp), %eax\n" /* line 653 | priorityMap */
        "movl %eax, -0x38(%ebp)\n"
        "cmpl $0x3ff, 0x1c(%ebp)\n" /* line 655 | passEntityNum */
        "je .Lf1bc16a_001bc499\n"
        "movl 0x1c(%ebp), %edx\n" /* line 657 | passEntityNum */
        "movl %edx, (%esp)\n"
        "calll SV_GentityNum\n"
        "movl 0x150(%eax), %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        "cmpl $0x3ff, %eax\n" /* line 658 */
        "je .Lf1bc16a_001bc499\n"
        ".Lf1bc16a_001bc2f1:\n"
        "movl 8(%ebp), %eax\n" /* line 667 | results */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* maxs */
        "calll CM_PointTraceToEntities\n"
        /* } scope */
        ".Lf1bc16a_001bc300:\n"
        "addl $0xac, %esp\n" /* line 710 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1bc16a_001bc30b:\n"
        "movl %edi, 0xc(%esp)\n" /* line 631 | contentmask */
        "movl 0x18(%ebp), %eax\n" /* end */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* start */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* results */
        "movl %eax, (%esp)\n"
        "calll CM_PointTraceStaticModels\n"
        "pxor %xmm0, %xmm0\n" /* line 632 */
        "movl 8(%ebp), %edx\n" /* results */
        "ucomiss (%edx), %xmm0\n"
        "jp .Lf1bc16a_001bc1eb\n"
        "jne .Lf1bc16a_001bc1eb\n"
        "jmp .Lf1bc16a_001bc300\n"
        /* { scope 1 */
        ".Lf1bc16a_001bc340:\n"
        "movl $0xffffffff, -0x20(%ebp)\n" /* line 686 */
        "movss -0x8c(%ebp), %xmm2\n"
        ".Lf1bc16a_001bc34f:\n"
        "subss (%esi), %xmm2\n" /* line 248 */
        "movl -0x88(%ebp), %eax\n" /* line 249 */
        "movss (%eax), %xmm5\n"
        "movaps %xmm5, %xmm3\n"
        "movl -0x84(%ebp), %edx\n"
        "subss (%edx), %xmm3\n"
        "movl -0x80(%ebp), %eax\n" /* line 250 */
        "movss (%eax), %xmm6\n"
        "movaps %xmm6, %xmm4\n"
        "movl -0x7c(%ebp), %edx\n"
        "subss (%edx), %xmm4\n"
        "movss 0x2ed5d8, %xmm7\n" /* line 272 | 0.5f */
        "mulss %xmm7, %xmm2\n"
        "mulss %xmm7, %xmm3\n" /* line 273 */
        "mulss %xmm7, %xmm4\n" /* line 274 */
        "movss %xmm2, -0x60(%ebp)\n" /* line 199 */
        "movss %xmm3, -0x5c(%ebp)\n" /* line 200 */
        "movss %xmm4, -0x58(%ebp)\n" /* line 201 */
        "movss 0x303290, %xmm0\n" /* line 272 */
        "movaps %xmm2, %xmm1\n"
        "xorps %xmm0, %xmm1\n"
        "movss %xmm1, -0x6c(%ebp)\n" /* clip */
        "movaps %xmm3, %xmm1\n" /* line 273 */
        "xorps %xmm0, %xmm1\n"
        "movss %xmm1, -0x68(%ebp)\n"
        "xorps %xmm4, %xmm0\n" /* line 274 */
        "movss %xmm0, -0x64(%ebp)\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 695 | 1.0f */
        "addss %xmm0, %xmm2\n"
        "movss %xmm2, -0x54(%ebp)\n"
        "addss %xmm0, %xmm3\n" /* line 696 */
        "movss %xmm3, -0x50(%ebp)\n"
        "addss %xmm0, %xmm4\n" /* line 697 */
        "movss %xmm4, -0x4c(%ebp)\n"
        "movss -0x8c(%ebp), %xmm1\n" /* line 240 */
        "addss (%esi), %xmm1\n"
        "movl -0x84(%ebp), %eax\n" /* line 241 */
        "addss (%eax), %xmm5\n"
        "addss (%edx), %xmm6\n" /* line 242 */
        "mulss %xmm7, %xmm1\n" /* line 272 */
        "mulss %xmm7, %xmm5\n" /* line 273 */
        "mulss %xmm7, %xmm6\n" /* line 274 */
        "movaps %xmm1, %xmm0\n" /* line 240 */
        "movl 0xc(%ebp), %edx\n" /* start */
        "addss (%edx), %xmm0\n"
        "movss %xmm0, -0x48(%ebp)\n"
        "movaps %xmm5, %xmm0\n" /* line 241 */
        "addss 4(%edx), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "movaps %xmm6, %xmm0\n" /* line 242 */
        "addss 8(%edx), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        "movl 0x18(%ebp), %eax\n" /* line 240 | end */
        "addss (%eax), %xmm1\n"
        "movss %xmm1, -0x3c(%ebp)\n"
        "addss 4(%eax), %xmm5\n" /* line 241 */
        "movss %xmm5, -0x38(%ebp)\n"
        "addss 8(%eax), %xmm6\n" /* line 242 */
        "movss %xmm6, -0x34(%ebp)\n"
        "leal -0x6c(%ebp), %ebx\n" /* line 704 | clip, maxs */
        "leal -0x48(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_CalcTraceEntents\n"
        "movl 8(%ebp), %edx\n" /* line 707 | results */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* maxs */
        "calll CM_ClipMoveToEntities\n"
        /* } scope */
        "addl $0xac, %esp\n" /* line 710 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bc16a_001bc47e:\n"
        "movl $0xffffffff, -0x20(%ebp)\n" /* line 682 */
        "movss (%ebx), %xmm0\n" /* maxs */
        "movss %xmm0, -0x8c(%ebp)\n"
        "movaps %xmm0, %xmm2\n"
        "jmp .Lf1bc16a_001bc34f\n"
        /* } scope */
        /* { scope 1 */
        ".Lf1bc16a_001bc499:\n"
        "movl $0xffffffff, -0x44(%ebp)\n" /* line 663 */
        "jmp .Lf1bc16a_001bc2f1\n"
    );
}

/* line 719 */
__attribute__((naked))
qboolean SV_TracePassed(const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int passEntityNum0, int passEntityNum1, int contentmask, qboolean locational, qboolean staticmodels)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 719 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* mins */
        "movl 0x10(%ebp), %ebx\n" /* maxs */
        "movl 0x20(%ebp), %edi\n" /* contentmask */
        "movl %edi, 0x18(%esp)\n" /* line 735 | contentmask */
        "movl $0, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n" /* maxs */
        "movl %esi, 0xc(%esp)\n" /* mins */
        "movl 0x14(%ebp), %eax\n" /* end */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %edx\n" /* start */
        "movl %edx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll CM_BoxSightTrace\n"
        "testl %eax, %eax\n"
        "jne .Lf1bc4a6_001bc585\n"
        "movl 0x28(%ebp), %edx\n" /* line 742 | staticmodels */
        "testl %edx, %edx\n"
        "jne .Lf1bc4a6_001bc6c4\n"
        ".Lf1bc4a6_001bc4fc:\n"
        "leal 4(%ebx), %edx\n" /* line 755 | maxs */
        "leal 4(%esi), %eax\n" /* mins */
        "movl %eax, -0x6c(%ebp)\n"
        "leal 8(%ebx), %eax\n" /* maxs */
        "leal 8(%esi), %ecx\n" /* mins */
        "movss (%ebx), %xmm7\n" /* maxs */
        "movaps %xmm7, %xmm0\n"
        "subss (%esi), %xmm0\n" /* mins */
        "addss 4(%ebx), %xmm0\n" /* maxs */
        "subss 4(%esi), %xmm0\n" /* mins */
        "addss 8(%ebx), %xmm0\n" /* maxs */
        "subss 8(%esi), %xmm0\n" /* mins */
        "ucomiss 0x2ed5e8, %xmm0\n" /* 0.0f */
        "jne .Lf1bc4a6_001bc592\n"
        "jp .Lf1bc4a6_001bc592\n"
        /* { scope 1 */
        "movl %edi, -0x40(%ebp)\n" /* line 759 | contentmask */
        "movl 8(%ebp), %edx\n" /* line 199 | start */
        "movl (%edx), %eax\n"
        "movl %eax, -0x60(%ebp)\n" /* clip */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x5c(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x58(%ebp)\n"
        "movl 0x14(%ebp), %ebx\n" /* line 199 | end */
        "movl (%ebx), %eax\n"
        "movl %eax, -0x54(%ebp)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, -0x50(%ebp)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, -0x4c(%ebp)\n"
        "movl 0x18(%ebp), %eax\n" /* line 762 | passEntityNum0 */
        "movl %eax, -0x48(%ebp)\n"
        "movl 0x1c(%ebp), %edx\n" /* line 763 | passEntityNum1 */
        "movl %edx, -0x44(%ebp)\n"
        "movl 0x24(%ebp), %ebx\n" /* line 764 | locational, maxs */
        "movl %ebx, -0x3c(%ebp)\n" /* maxs */
        "leal -0x60(%ebp), %eax\n" /* line 767 | clip */
        "movl %eax, (%esp)\n"
        "calll CM_PointSightTraceToEntities\n"
        "testl %eax, %eax\n"
        "je .Lf1bc4a6_001bc6b4\n"
        /* } scope */
        /* { scope 1 */
        ".Lf1bc4a6_001bc585:\n"
        "xorl %eax, %eax\n" /* line 800 */
        /* } scope */
        "addl $0x8c, %esp\n" /* line 809 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bc4a6_001bc592:\n"
        "movl %edi, -0x1c(%ebp)\n" /* line 779 | contentmask */
        "movl 0x18(%ebp), %ebx\n" /* line 780 | passEntityNum0, maxs */
        "movl %ebx, -0x24(%ebp)\n" /* maxs */
        "movl 0x1c(%ebp), %ebx\n" /* line 781 | passEntityNum1, maxs */
        "movl %ebx, -0x20(%ebp)\n" /* maxs */
        "movaps %xmm7, %xmm2\n" /* line 248 */
        "subss (%esi), %xmm2\n"
        "movss (%edx), %xmm5\n" /* line 249 */
        "movaps %xmm5, %xmm3\n"
        "movl -0x6c(%ebp), %edx\n"
        "subss (%edx), %xmm3\n"
        "movss (%eax), %xmm6\n" /* line 250 */
        "movaps %xmm6, %xmm4\n"
        "subss (%ecx), %xmm4\n"
        "mulss 0x2ed5d8, %xmm2\n" /* line 272 | 0.5f */
        "mulss 0x2ed5d8, %xmm3\n" /* line 273 | 0.5f */
        "mulss 0x2ed5d8, %xmm4\n" /* line 274 | 0.5f */
        "movss %xmm2, -0x54(%ebp)\n" /* line 199 */
        "movss %xmm3, -0x50(%ebp)\n" /* line 200 */
        "movss %xmm4, -0x4c(%ebp)\n" /* line 201 */
        "movss 0x3032a0, %xmm0\n" /* line 272 */
        "movaps %xmm2, %xmm1\n"
        "xorps %xmm0, %xmm1\n"
        "movss %xmm1, -0x60(%ebp)\n" /* clip */
        "movaps %xmm3, %xmm1\n" /* line 273 */
        "xorps %xmm0, %xmm1\n"
        "movss %xmm1, -0x5c(%ebp)\n"
        "xorps %xmm4, %xmm0\n" /* line 274 */
        "movss %xmm0, -0x58(%ebp)\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 789 | 1.0f */
        "addss %xmm0, %xmm2\n"
        "movss %xmm2, -0x48(%ebp)\n"
        "addss %xmm0, %xmm3\n" /* line 790 */
        "movss %xmm3, -0x44(%ebp)\n"
        "addss %xmm0, %xmm4\n" /* line 791 */
        "movss %xmm4, -0x40(%ebp)\n"
        "movaps %xmm7, %xmm1\n" /* line 240 */
        "addss (%esi), %xmm1\n"
        "addss (%edx), %xmm5\n" /* line 241 */
        "addss (%ecx), %xmm6\n" /* line 242 */
        "mulss 0x2ed5d8, %xmm1\n" /* line 272 | 0.5f */
        "mulss 0x2ed5d8, %xmm5\n" /* line 273 | 0.5f */
        "mulss 0x2ed5d8, %xmm6\n" /* line 274 | 0.5f */
        "movaps %xmm1, %xmm0\n" /* line 240 */
        "movl 8(%ebp), %ebx\n" /* start */
        "addss (%ebx), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "movaps %xmm5, %xmm0\n" /* line 241 */
        "addss 4(%ebx), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "movaps %xmm6, %xmm0\n" /* line 242 */
        "addss 8(%ebx), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "movl 0x14(%ebp), %eax\n" /* line 240 | end */
        "addss (%eax), %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n"
        "addss 4(%eax), %xmm5\n" /* line 241 */
        "movss %xmm5, -0x2c(%ebp)\n"
        "addss 8(%eax), %xmm6\n" /* line 242 */
        "movss %xmm6, -0x28(%ebp)\n"
        "leal -0x60(%ebp), %eax\n" /* line 800 | clip */
        "movl %eax, (%esp)\n"
        "calll CM_ClipSightTraceToEntities\n"
        "testl %eax, %eax\n"
        "jne .Lf1bc4a6_001bc585\n"
        ".Lf1bc4a6_001bc6b4:\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 809 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1bc4a6_001bc6c4:\n"
        "movl %edi, 8(%esp)\n" /* line 744 | contentmask */
        "movl 0x14(%ebp), %eax\n" /* end */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* start */
        "movl %edx, (%esp)\n"
        "calll CM_PointTraceStaticModelsComplete\n"
        "testl %eax, %eax\n"
        "jne .Lf1bc4a6_001bc4fc\n"
        "jmp .Lf1bc4a6_001bc585\n"
    );
}

/* line 84 */
__attribute__((naked))
int SV_LinkEntity(gentity_t *gEnt)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 84 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x27c, %esp\n"
        "movl 8(%ebp), %edi\n" /* gEnt */
        /* { scope 1 */
        "movl %edi, (%esp)\n" /* line 100 | gEnt */
        "calll SV_SvEntityForGentity\n"
        "movl %eax, -0x23c(%ebp)\n" /* ent */
        "cmpb $0, 0xf1(%edi)\n" /* line 103 | gEnt */
        "je .Lf1bc6e8_001bc9e3\n"
        "movl $0xffffff, 0x9c(%edi)\n" /* line 105 | gEnt */
        ".Lf1bc6e8_001bc71c:\n"
        "leal 0x144(%edi), %eax\n" /* line 138 | gEnt */
        "movl %eax, -0x240(%ebp)\n" /* angles */
        "leal 0x138(%edi), %edx\n" /* line 139 | gEnt */
        "movl %edx, -0x244(%ebp)\n" /* origin */
        "movl $1, %esi\n"
        "leal 0x148(%edi), %ebx\n" /* gEnt, clipHandle */
        /* { scope 2 */
        ".Lf1bc6e8_001bc73f:\n"
        "movss -4(%ebx), %xmm0\n" /* line 428 | clipHandle */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x24c(%ebp)\n"
        "cvttss2si -0x24c(%ebp), %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movaps %xmm1, %xmm0\n" /* line 69 | delta */
        "subss -4(%ebx), %xmm0\n" /* delta */
        "mulss %xmm0, %xmm0\n" /* line 71 */
        "movss 0x2ed66c, %xmm2\n" /* 1.0000001111620804e-06f */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf1bc6e8_001bc786\n"
        "movss %xmm1, -4(%ebx)\n" /* line 72 */
        ".Lf1bc6e8_001bc786:\n"
        "addl $1, %esi\n"
        "addl $4, %ebx\n"
        /* } scope */
        "cmpl $4, %esi\n" /* line 66 */
        "jne .Lf1bc6e8_001bc73f\n"
        "cmpb $0, 0xf1(%edi)\n" /* line 147 | gEnt */
        "je .Lf1bc6e8_001bc83f\n"
        "pxor %xmm0, %xmm0\n"
        "movl -0x240(%ebp), %eax\n" /* angles */
        "ucomiss (%eax), %xmm0\n"
        "je .Lf1bc6e8_001bc81d\n"
        /* { scope 2 */
        ".Lf1bc6e8_001bc7ad:\n"
        "leal 0x110(%edi), %esi\n" /* line 155 | gEnt */
        "movl %esi, 4(%esp)\n"
        "leal 0x104(%edi), %ecx\n" /* gEnt */
        "movl %ecx, -0x250(%ebp)\n"
        "movl %ecx, (%esp)\n"
        "calll RadiusFromBounds\n"
        "fstps -0x25c(%ebp)\n"
        "movss -0x25c(%ebp), %xmm1\n"
        "movl %edi, %edx\n" /* gEnt */
        "movl $1, %ecx\n"
        "movl -0x244(%ebp), %eax\n" /* origin */
        "addl $4, %eax\n"
        ".Lf1bc6e8_001bc7e9:\n"
        "movss -4(%eax), %xmm0\n" /* line 158 */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0x120(%edx)\n"
        "movaps %xmm1, %xmm0\n" /* line 159 */
        "addss -4(%eax), %xmm0\n"
        "movss %xmm0, 0x12c(%edx)\n"
        "addl $1, %ecx\n"
        "addl $4, %eax\n"
        "addl $4, %edx\n"
        "cmpl $4, %ecx\n" /* line 156 */
        "jne .Lf1bc6e8_001bc7e9\n"
        "jmp .Lf1bc6e8_001bc8c7\n"
        /* } scope */
        ".Lf1bc6e8_001bc81d:\n"
        "jp .Lf1bc6e8_001bc7ad\n" /* line 147 */
        "ucomiss 4(%eax), %xmm0\n"
        "jne .Lf1bc6e8_001bcbae\n"
        "jp .Lf1bc6e8_001bcbae\n"
        "ucomiss 8(%eax), %xmm0\n"
        "jne .Lf1bc6e8_001bc7ad\n"
        "jp .Lf1bc6e8_001bc7ad\n"
        ".Lf1bc6e8_001bc83f:\n"
        "leal 0x120(%edi), %eax\n" /* line 178 | gEnt, sum */
        "leal 0x104(%edi), %ecx\n" /* gEnt */
        "movl %ecx, -0x250(%ebp)\n"
        /* { scope 2 */
        "movl -0x244(%ebp), %edx\n" /* line 240 | origin */
        "movss (%edx), %xmm0\n"
        "addss 0x104(%edi), %xmm0\n" /* gEnt */
        "movss %xmm0, 0x120(%edi)\n" /* gEnt */
        "movss 4(%edx), %xmm0\n" /* line 241 */
        "addss 4(%ecx), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movss 8(%edx), %xmm0\n" /* line 242 */
        "addss 8(%ecx), %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        "leal 0x12c(%edi), %eax\n" /* line 179 | gEnt, sum */
        "leal 0x110(%edi), %esi\n" /* gEnt */
        /* { scope 2 */
        "movss (%edx), %xmm0\n" /* line 240 */
        "addss 0x110(%edi), %xmm0\n" /* gEnt */
        "movss %xmm0, 0x12c(%edi)\n" /* gEnt */
        "movss 4(%edx), %xmm0\n" /* line 241 */
        "addss 4(%esi), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movss 8(%edx), %xmm0\n" /* line 242 */
        "addss 8(%esi), %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        ".Lf1bc6e8_001bc8c7:\n"
        "movss 0x120(%edi), %xmm0\n" /* line 184 | gEnt */
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0x120(%edi)\n" /* gEnt */
        "movss 0x124(%edi), %xmm0\n" /* line 185 | gEnt */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0x124(%edi)\n" /* gEnt */
        "movss 0x128(%edi), %xmm0\n" /* line 186 | gEnt */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0x128(%edi)\n" /* gEnt */
        "movss 0x12c(%edi), %xmm0\n" /* line 187 | gEnt */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 0x12c(%edi)\n" /* gEnt */
        "movss 0x130(%edi), %xmm0\n" /* line 188 | gEnt */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 0x130(%edi)\n" /* gEnt */
        "addss 0x134(%edi), %xmm1\n" /* line 189 | gEnt */
        "movss %xmm1, 0x134(%edi)\n" /* gEnt */
        "movl -0x23c(%ebp), %ecx\n" /* line 192 | ent */
        "movl $0, 0x118(%ecx)\n"
        "movl $0, 0x15c(%ecx)\n" /* line 193 */
        "movzbl 0xf2(%edi), %eax\n" /* line 195 | gEnt */
        "testb $0x19, %al\n"
        "je .Lf1bc6e8_001bca83\n"
        ".Lf1bc6e8_001bc96c:\n"
        "movb $1, 0xf0(%edi)\n" /* line 229 | gEnt */
        "movl 0x11c(%edi), %ecx\n" /* line 232 | gEnt */
        "testl %ecx, %ecx\n"
        "je .Lf1bc6e8_001bcaf5\n"
        ".Lf1bc6e8_001bc981:\n"
        "cmpb $0, 0xf1(%edi)\n" /* line 26 */
        "je .Lf1bc6e8_001bcb8b\n"
        "movl 0x8c(%edi), %ebx\n" /* line 29 */
        ".Lf1bc6e8_001bc994:\n"
        "movl (%edi), %eax\n" /* line 241 | gEnt */
        "movl %eax, (%esp)\n"
        "calll Com_GetServerDObj\n"
        "testl %eax, %eax\n" /* line 242 */
        "je .Lf1bc6e8_001bc9b2\n"
        "movzbl 0xf2(%edi), %edx\n" /* gEnt */
        "testb $6, %dl\n"
        "jne .Lf1bc6e8_001bcb0e\n"
        ".Lf1bc6e8_001bc9b2:\n"
        "movl %ebx, 0xc(%esp)\n" /* line 244 | clipHandle */
        "leal 0x12c(%edi), %eax\n" /* gEnt */
        "movl %eax, 8(%esp)\n"
        "leal 0x120(%edi), %eax\n" /* gEnt */
        "movl %eax, 4(%esp)\n"
        "movl -0x23c(%ebp), %edx\n" /* ent */
        "movl %edx, (%esp)\n"
        "calll CM_LinkEntity\n"
        /* } scope */
        ".Lf1bc6e8_001bc9d8:\n"
        "addl $0x27c, %esp\n" /* line 262 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bc6e8_001bc9e3:\n"
        "testl $0x2000001, 0x11c(%edi)\n" /* line 107 | gEnt */
        "jne .Lf1bc6e8_001bc9fe\n"
        "movl $0, 0x9c(%edi)\n" /* line 134 | gEnt */
        "jmp .Lf1bc6e8_001bc71c\n"
        ".Lf1bc6e8_001bc9fe:\n"
        "cvttss2si 0x110(%edi), %edx\n" /* line 110 | gEnt */
        "testl %edx, %edx\n" /* line 111 */
        "jle .Lf1bc6e8_001bccb3\n"
        "cmpl $0x100, %edx\n" /* line 113 */
        "movl $0xff, %eax\n"
        "cmovgel %eax, %edx\n"
        ".Lf1bc6e8_001bca1c:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 117 | 1.0f */
        "subss 0x10c(%edi), %xmm0\n" /* gEnt */
        "cvttss2si %xmm0, %eax\n"
        "testl %eax, %eax\n" /* line 118 */
        "jle .Lf1bc6e8_001bcd44\n"
        "cmpl $0xff, %eax\n" /* line 120 */
        "jle .Lf1bc6e8_001bccc5\n"
        "movl $0xff00, %ecx\n"
        ".Lf1bc6e8_001bca48:\n"
        "movss 0x2ed830, %xmm0\n" /* line 124 | 32.0f */
        "addss 0x118(%edi), %xmm0\n" /* gEnt */
        "cvttss2si %xmm0, %eax\n"
        "testl %eax, %eax\n" /* line 125 */
        "jle .Lf1bc6e8_001bcd3a\n"
        "cmpl $0xff, %eax\n" /* line 127 */
        "jle .Lf1bc6e8_001bccbd\n"
        "movl $0xff0000, %eax\n"
        ".Lf1bc6e8_001bca74:\n"
        "orl %ecx, %eax\n" /* line 130 */
        "orl %eax, %edx\n"
        "movl %edx, 0x9c(%edi)\n" /* gEnt */
        "jmp .Lf1bc6e8_001bc71c\n"
        ".Lf1bc6e8_001bca83:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 199 | lastLeaf */
        "movl %eax, 0x10(%esp)\n"
        "movl $0x80, 0xc(%esp)\n"
        "leal -0x234(%ebp), %eax\n" /* leafs */
        "movl %eax, 8(%esp)\n"
        "leal 0x12c(%edi), %eax\n" /* gEnt */
        "movl %eax, 4(%esp)\n"
        "leal 0x120(%edi), %eax\n" /* gEnt */
        "movl %eax, (%esp)\n"
        "calll CM_BoxLeafnums\n"
        "movl %eax, -0x248(%ebp)\n" /* num_leafs */
        "cmpl $0, %eax\n" /* line 204 */
        "je .Lf1bc6e8_001bcccf\n"
        "jg .Lf1bc6e8_001bcc64\n" /* line 213 */
        ".Lf1bc6e8_001bcac9:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 226 | lastLeaf */
        "movl %eax, (%esp)\n"
        "calll CM_LeafCluster\n"
        "movl -0x23c(%ebp), %edx\n" /* ent */
        "movl %eax, 0x15c(%edx)\n"
        "movb $1, 0xf0(%edi)\n" /* line 229 | gEnt */
        "movl 0x11c(%edi), %ecx\n" /* line 232 | gEnt */
        "testl %ecx, %ecx\n"
        "jne .Lf1bc6e8_001bc981\n"
        ".Lf1bc6e8_001bcaf5:\n"
        "movl -0x23c(%ebp), %ecx\n" /* line 234 | ent */
        "movl %ecx, (%esp)\n"
        "calll CM_UnlinkEntity\n"
        /* } scope */
        "addl $0x27c, %esp\n" /* line 262 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bc6e8_001bcb0e:\n"
        "andb $2, %dl\n" /* line 249 */
        "je .Lf1bc6e8_001bcce2\n"
        "movl -0x244(%ebp), %ecx\n" /* line 58 | origin */
        "movss (%ecx), %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        "addss actorLocationalMins, %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n" /* absmin */
        "movss 4(%ecx), %xmm1\n" /* line 59 */
        "movaps %xmm1, %xmm0\n"
        "addss 0x314550, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        "addss actorLocationalMaxs, %xmm2\n" /* line 58 */
        "movss %xmm2, -0x34(%ebp)\n" /* absmax */
        "addss 0x314544, %xmm1\n" /* line 59 */
        "movss %xmm1, -0x30(%ebp)\n"
        "leal -0x34(%ebp), %edi\n" /* absmax */
        "leal -0x28(%ebp), %esi\n" /* absmin */
        ".Lf1bc6e8_001bcb66:\n"
        "movl %ebx, 0xc(%esp)\n" /* line 260 | clipHandle */
        "movl %edi, 8(%esp)\n" /* gEnt */
        "movl %esi, 4(%esp)\n"
        "movl -0x23c(%ebp), %edx\n" /* ent */
        "movl %edx, (%esp)\n"
        "calll CM_LinkEntity\n"
        /* } scope */
        "addl $0x27c, %esp\n" /* line 262 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bc6e8_001bcb8b:\n"
        "movl 0x11c(%edi), %eax\n" /* line 33 */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl -0x250(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_TempBoxModel\n"
        "movl %eax, %ebx\n"
        "jmp .Lf1bc6e8_001bc994\n"
        /* { scope 2 */
        ".Lf1bc6e8_001bcbae:\n"
        "movl -0x240(%ebp), %edx\n" /* line 153 | angles */
        "ucomiss 8(%edx), %xmm0\n"
        "jp .Lf1bc6e8_001bc7ad\n"
        "jne .Lf1bc6e8_001bc7ad\n"
        "leal 0x110(%edi), %esi\n" /* line 164 | gEnt */
        "movl %esi, 4(%esp)\n"
        "leal 0x104(%edi), %eax\n" /* gEnt */
        "movl %eax, -0x250(%ebp)\n"
        "movl %eax, (%esp)\n"
        "calll RadiusFromBounds2D\n"
        "fstps -0x25c(%ebp)\n"
        "movss -0x25c(%ebp), %xmm1\n"
        "movl %edi, %edx\n" /* gEnt */
        "movl $1, %ecx\n"
        "movl -0x244(%ebp), %eax\n" /* origin */
        "addl $4, %eax\n"
        ".Lf1bc6e8_001bcc00:\n"
        "movss -4(%eax), %xmm0\n" /* line 167 */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0x120(%edx)\n"
        "movaps %xmm1, %xmm0\n" /* line 168 */
        "addss -4(%eax), %xmm0\n"
        "movss %xmm0, 0x12c(%edx)\n"
        "addl $1, %ecx\n"
        "addl $4, %eax\n"
        "addl $4, %edx\n"
        "cmpl $3, %ecx\n" /* line 165 */
        "jne .Lf1bc6e8_001bcc00\n"
        "movl -0x244(%ebp), %edx\n" /* line 171 | origin */
        "movss 8(%edx), %xmm0\n"
        "addss 0x10c(%edi), %xmm0\n" /* gEnt */
        "movss %xmm0, 0x128(%edi)\n" /* gEnt */
        "movss 8(%edx), %xmm0\n" /* line 172 */
        "addss 0x118(%edi), %xmm0\n" /* gEnt */
        "movss %xmm0, 0x134(%edi)\n" /* gEnt */
        "jmp .Lf1bc6e8_001bc8c7\n"
        /* } scope */
        ".Lf1bc6e8_001bcc64:\n"
        "xorl %ebx, %ebx\n" /* line 209 | clipHandle */
        "jmp .Lf1bc6e8_001bcc77\n"
        ".Lf1bc6e8_001bcc68:\n"
        "addl $1, %ebx\n" /* line 213 | clipHandle */
        "cmpl -0x248(%ebp), %ebx\n" /* num_leafs, clipHandle */
        "je .Lf1bc6e8_001bc96c\n"
        ".Lf1bc6e8_001bcc77:\n"
        "movl -0x234(%ebp, %ebx, 4), %eax\n" /* line 215 */
        "movl %eax, (%esp)\n"
        "calll CM_LeafCluster\n"
        "movl %eax, %edx\n"
        "cmpl $-1, %eax\n" /* line 216 */
        "je .Lf1bc6e8_001bcc68\n"
        "movl -0x23c(%ebp), %ecx\n" /* line 218 | ent */
        "movl 0x118(%ecx), %eax\n"
        "movl %edx, 0x11c(%ecx, %eax, 4)\n"
        "addl $1, %eax\n"
        "movl %eax, 0x118(%ecx)\n"
        "cmpl $0x10, %eax\n" /* line 219 */
        "jne .Lf1bc6e8_001bcc68\n"
        "jmp .Lf1bc6e8_001bcac9\n"
        ".Lf1bc6e8_001bccb3:\n"
        "movl $1, %edx\n" /* line 111 */
        "jmp .Lf1bc6e8_001bca1c\n"
        ".Lf1bc6e8_001bccbd:\n"
        "shll $0x10, %eax\n" /* line 127 */
        "jmp .Lf1bc6e8_001bca74\n"
        ".Lf1bc6e8_001bccc5:\n"
        "movl %eax, %ecx\n" /* line 120 */
        "shll $8, %ecx\n"
        "jmp .Lf1bc6e8_001bca48\n"
        ".Lf1bc6e8_001bcccf:\n"
        "movl -0x23c(%ebp), %eax\n" /* line 207 | ent */
        "movl %eax, (%esp)\n"
        "calll CM_UnlinkEntity\n"
        "jmp .Lf1bc6e8_001bc9d8\n"
        ".Lf1bc6e8_001bcce2:\n"
        "leal -0x34(%ebp), %edi\n" /* line 256 | absmax, gEnt */
        "movl %edi, 8(%esp)\n" /* gEnt */
        "leal -0x28(%ebp), %esi\n" /* absmin */
        "movl %esi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll DObjGetBounds\n"
        "movl -0x244(%ebp), %eax\n" /* line 58 | origin */
        "movss (%eax), %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        "addss -0x28(%ebp), %xmm0\n" /* absmin */
        "movss %xmm0, -0x28(%ebp)\n" /* absmin */
        "movss 4(%eax), %xmm1\n" /* line 59 */
        "movaps %xmm1, %xmm0\n"
        "addss -0x24(%ebp), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        "addss -0x34(%ebp), %xmm2\n" /* line 58 | absmax */
        "movss %xmm2, -0x34(%ebp)\n" /* absmax */
        "addss -0x30(%ebp), %xmm1\n" /* line 59 */
        "movss %xmm1, -0x30(%ebp)\n"
        "jmp .Lf1bc6e8_001bcb66\n"
        ".Lf1bc6e8_001bcd3a:\n"
        "movl $0x10000, %eax\n" /* line 125 */
        "jmp .Lf1bc6e8_001bca74\n"
        ".Lf1bc6e8_001bcd44:\n"
        "movl $0x100, %ecx\n" /* line 118 */
        "jmp .Lf1bc6e8_001bca48\n"
    );
}

/* line 273 */
__attribute__((naked))
int SV_ClipMoveToEntity(const moveclip_t *clip, svEntity_t *check, trace_t *trace)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 273 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl 8(%ebp), %edi\n" /* clip */
        "movl 0xc(%ebp), %edx\n" /* check */
        /* { scope 1 */
        "movl 0x195ee80, %eax\n" /* line 283 */
        "addl $0x2418, %eax\n"
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
        "leal (%edx, %eax, 4), %esi\n"
        "movl %esi, (%esp)\n" /* line 284 */
        "calll SV_GentityNum\n"
        "movl %eax, %ebx\n" /* touch */
        "movl 0x50(%edi), %eax\n" /* line 288 | clip */
        "testl %eax, 0x11c(%ebx)\n" /* touch */
        "je .Lf1bcd4e_001bced8\n"
        "movl 0x48(%edi), %eax\n" /* line 292 | clip */
        "cmpl $0x3ff, %eax\n"
        "je .Lf1bcd4e_001bcdcd\n"
        "cmpl %eax, %esi\n" /* line 294 */
        "je .Lf1bcd4e_001bced8\n"
        "movl 0x150(%ebx), %edx\n" /* line 296 | touch */
        "cmpl %edx, %eax\n"
        "je .Lf1bcd4e_001bced8\n"
        "cmpl 0x4c(%edi), %edx\n" /* line 298 | clip */
        "je .Lf1bcd4e_001bced8\n"
        ".Lf1bcd4e_001bcdcd:\n"
        "leal 0x120(%ebx), %eax\n" /* line 302 | touch, a */
        /* { scope 2 */
        "movss 0x120(%ebx), %xmm0\n" /* line 240 */
        "addss (%edi), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* absmin */
        "movss 4(%eax), %xmm0\n" /* line 241 */
        "addss 4(%edi), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 242 */
        "addss 8(%edi), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        /* } scope */
        "leal 0xc(%edi), %esi\n" /* line 303 | clip, b */
        "leal 0x12c(%ebx), %eax\n" /* touch, a */
        /* { scope 2 */
        "movss 0x12c(%ebx), %xmm0\n" /* line 240 */
        "addss 0xc(%edi), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* absmax */
        "movss 4(%eax), %xmm0\n" /* line 241 */
        "addss 4(%esi), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 242 */
        "addss 8(%esi), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        /* } scope */
        "movl 0x10(%ebp), %edx\n" /* line 304 | trace */
        "movl (%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* absmax */
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* absmin */
        "movl %eax, 4(%esp)\n"
        "leal 0x24(%edi), %ecx\n" /* clip */
        "movl %ecx, -0x40(%ebp)\n"
        "movl %ecx, (%esp)\n"
        "calll CM_TraceBox\n"
        "testl %eax, %eax\n"
        "jne .Lf1bcd4e_001bced8\n"
        "cmpb $0, 0xf1(%ebx)\n" /* line 26 */
        "je .Lf1bcd4e_001bcee7\n"
        "movl 0x8c(%ebx), %edx\n" /* line 29 */
        ".Lf1bcd4e_001bce73:\n"
        "leal 0x144(%ebx), %eax\n" /* line 310 | touch */
        "cmpb $0, 0xf1(%ebx)\n" /* line 312 | touch */
        "je .Lf1bcd4e_001bcee0\n"
        ".Lf1bcd4e_001bce82:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 315 | trace */
        "movss (%ecx), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n" /* oldFraction */
        "movl %eax, 0x20(%esp)\n" /* line 316 */
        "leal 0x138(%ebx), %eax\n" /* touch */
        "movl %eax, 0x1c(%esp)\n"
        "movl 0x50(%edi), %eax\n" /* clip */
        "movl %eax, 0x18(%esp)\n"
        "movl %edx, 0x14(%esp)\n"
        "movl %esi, 0x10(%esp)\n" /* b */
        "movl %edi, 0xc(%esp)\n" /* clip */
        "leal 0x30(%edi), %eax\n" /* clip */
        "movl %eax, 8(%esp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll CM_TransformedBoxTrace\n"
        "movl 0x10(%ebp), %edx\n" /* line 317 | trace */
        "movss (%edx), %xmm0\n"
        "ucomiss -0x3c(%ebp), %xmm0\n" /* oldFraction */
        "jae .Lf1bcd4e_001bced8\n"
        "movl (%ebx), %eax\n" /* line 320 | touch */
        "movw %ax, 0x1c(%edx)\n"
        /* } scope */
        ".Lf1bcd4e_001bced8:\n"
        "addl $0x6c, %esp\n" /* line 321 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bcd4e_001bcee0:\n"
        "movl 0x195ed4c, %eax\n" /* line 312 */
        "jmp .Lf1bcd4e_001bce82\n"
        ".Lf1bcd4e_001bcee7:\n"
        "movl 0x11c(%ebx), %eax\n" /* line 33 */
        "movl %eax, 8(%esp)\n"
        "leal 0x110(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x104(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_TempBoxModel\n"
        "movl %eax, %edx\n"
        "jmp .Lf1bcd4e_001bce73\n"
    );
}

/* line 330 */
__attribute__((naked))
int SV_PointTraceToEntity(const pointtrace_t *clip, svEntity_t *check, trace_t *trace)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 330 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xcc, %esp\n"
        "movl 8(%ebp), %edi\n" /* clip */
        /* { scope 1 */
        "movl 0x195ee80, %eax\n" /* line 345 */
        "addl $0x2418, %eax\n"
        "movl 0xc(%ebp), %edx\n" /* check */
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
        "leal (%edx, %eax, 4), %ebx\n" /* obj */
        "movl %ebx, (%esp)\n" /* line 346 | obj */
        "calll SV_GentityNum\n"
        "movl %eax, %esi\n" /* touch */
        "movl 0x2c(%edi), %ecx\n" /* line 350 | clip */
        "testl %ecx, 0x11c(%eax)\n"
        "je .Lf1bcf10_001bcf98\n"
        "movl 0x24(%edi), %eax\n" /* line 354 | clip */
        "cmpl $0x3ff, %eax\n"
        "je .Lf1bcf10_001bcf82\n"
        "cmpl %eax, %ebx\n" /* line 356 | obj */
        "je .Lf1bcf10_001bcf98\n"
        "movl 0x150(%esi), %edx\n" /* line 358 | touch */
        "cmpl %edx, %eax\n"
        "je .Lf1bcf10_001bcf98\n"
        "cmpl 0x28(%edi), %edx\n" /* line 360 | clip */
        "je .Lf1bcf10_001bcf98\n"
        ".Lf1bcf10_001bcf82:\n"
        "movl 0x30(%edi), %eax\n" /* line 364 | clip */
        "testl %eax, %eax\n"
        "jne .Lf1bcf10_001bd07f\n"
        ".Lf1bcf10_001bcf8d:\n"
        "movl 0xc(%ebp), %edx\n" /* line 417 | check */
        "testl %ecx, 0x160(%edx)\n"
        "jne .Lf1bcf10_001bcfa3\n"
        /* } scope */
        ".Lf1bcf10_001bcf98:\n"
        "addl $0xcc, %esp\n" /* line 444 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bcf10_001bcfa3:\n"
        "movl 0x10(%ebp), %ebx\n" /* line 420 | trace, obj */
        "movl (%ebx), %eax\n" /* obj */
        "movl %eax, 0xc(%esp)\n"
        "leal 0x12c(%esi), %eax\n" /* touch */
        "movl %eax, 8(%esp)\n"
        "leal 0x120(%esi), %eax\n" /* touch */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* clip */
        "calll CM_TraceBox\n"
        "testl %eax, %eax\n"
        "jne .Lf1bcf10_001bcf98\n"
        "cmpb $0, 0xf1(%esi)\n" /* line 26 */
        "je .Lf1bcf10_001bd2e9\n"
        "movl 0x8c(%esi), %ecx\n" /* line 29 */
        ".Lf1bcf10_001bcfdf:\n"
        "leal 0x144(%esi), %eax\n" /* line 426 | touch */
        "cmpb $0, 0xf1(%esi)\n" /* line 428 | touch */
        "jne .Lf1bcf10_001bd23d\n"
        "movl 0x195ed4c, %edx\n"
        "movl %edx, %eax\n"
        ".Lf1bcf10_001bcffa:\n"
        "movl 0x10(%ebp), %ebx\n" /* line 431 | trace, obj */
        "movss (%ebx), %xmm0\n" /* obj */
        "movss %xmm0, -0x9c(%ebp)\n" /* oldFraction */
        "movl %eax, 0x20(%esp)\n" /* line 432 */
        "leal 0x138(%esi), %eax\n" /* touch */
        "movl %eax, 0x1c(%esp)\n"
        "movl 0x2c(%edi), %eax\n" /* clip */
        "movl %eax, 0x18(%esp)\n"
        "movl %ecx, 0x14(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "leal 0xc(%edi), %eax\n" /* clip */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* clip */
        "movl %ebx, (%esp)\n" /* obj */
        "calll CM_TransformedBoxTrace\n"
        "movss (%ebx), %xmm0\n" /* line 433 | obj */
        "ucomiss -0x9c(%ebp), %xmm0\n" /* oldFraction */
        "jae .Lf1bcf10_001bcf98\n"
        "movl $0, 0x10(%ebx)\n" /* line 436 | obj */
        "movw $0, 0x1e(%ebx)\n" /* line 437 | obj */
        "movw $0, 0x20(%ebx)\n" /* line 438 | obj */
        ".Lf1bcf10_001bd061:\n"
        "movl (%esi), %eax\n" /* line 441 | touch */
        "movl 0x10(%ebp), %edx\n" /* trace */
        "movw %ax, 0x1c(%edx)\n"
        "movl 0x11c(%esi), %eax\n" /* line 442 | touch */
        "movl %eax, 0x14(%edx)\n"
        "movl $0, 0x18(%edx)\n" /* line 443 */
        "jmp .Lf1bcf10_001bcf98\n"
        ".Lf1bcf10_001bd07f:\n"
        "movl (%esi), %eax\n" /* line 364 | touch */
        "movl %eax, (%esp)\n"
        "calll Com_GetServerDObj\n"
        "movl %eax, %ebx\n" /* obj */
        "testl %eax, %eax\n"
        "je .Lf1bcf10_001bd235\n"
        "movzbl 0xf2(%esi), %eax\n" /* touch */
        "testb $6, %al\n"
        "je .Lf1bcf10_001bd235\n"
        "testb $4, %al\n" /* line 366 */
        "jne .Lf1bcf10_001bd248\n"
        "movl 0x34(%edi), %eax\n" /* line 378 | clip */
        "testl %eax, %eax\n"
        "je .Lf1bcf10_001bd235\n"
        "leal 0x138(%esi), %eax\n" /* line 379 | touch */
        /* { scope 2 */
        "movss 0x138(%esi), %xmm1\n" /* line 199 */
        "movss %xmm1, -0x6c(%ebp)\n"
        "movss 4(%eax), %xmm2\n" /* line 200 */
        "movss %xmm2, -0x68(%ebp)\n"
        "movss 8(%eax), %xmm3\n" /* line 201 */
        "movss %xmm3, -0x64(%ebp)\n"
        /* } scope */
        "movaps %xmm1, %xmm0\n" /* line 240 */
        "addss actorLocationalMins, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* absmin */
        "movaps %xmm2, %xmm0\n" /* line 241 */
        "addss 0x314550, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movaps %xmm3, %xmm0\n" /* line 242 */
        "addss 0x314554, %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "addss actorLocationalMaxs, %xmm1\n" /* line 240 */
        "movss %xmm1, -0x30(%ebp)\n" /* absmax */
        "addss 0x314544, %xmm2\n" /* line 241 */
        "movss %xmm2, -0x2c(%ebp)\n"
        "addss 0x314548, %xmm3\n" /* line 242 */
        "movss %xmm3, -0x28(%ebp)\n"
        ".Lf1bcf10_001bd133:\n"
        "movl 0x10(%ebp), %edx\n" /* line 386 | trace */
        "movl (%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* absmax */
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %edx\n" /* absmin */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* clip */
        "calll CM_TraceBox\n"
        "testl %eax, %eax\n"
        "jne .Lf1bcf10_001bcf98\n"
        "movl %esi, (%esp)\n" /* line 389 | touch */
        "calll G_DObjCalcPose\n"
        "leal -0x90(%ebp), %eax\n" /* line 391 | entAxis */
        "movl %eax, 4(%esp)\n"
        "leal 0x144(%esi), %eax\n" /* touch */
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "leal -0x3c(%ebp), %edx\n" /* line 393 | localStart */
        "movl %edx, 8(%esp)\n"
        "leal -0x90(%ebp), %eax\n" /* entAxis */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* clip */
        "calll MatrixTransposeTransformVector43\n"
        "leal -0x48(%ebp), %edx\n" /* line 394 | localEnd */
        "movl %edx, 8(%esp)\n"
        "leal -0x90(%ebp), %eax\n" /* entAxis */
        "movl %eax, 4(%esp)\n"
        "leal 0xc(%edi), %eax\n" /* clip */
        "movl %eax, (%esp)\n"
        "calll MatrixTransposeTransformVector43\n"
        "movl 0x10(%ebp), %edx\n" /* line 396 | trace */
        "movl (%edx), %eax\n"
        "movl %eax, -0x60(%ebp)\n" /* objTrace */
        "testb $4, 0xf2(%esi)\n" /* line 397 | touch */
        "je .Lf1bcf10_001bd312\n"
        "leal -0x60(%ebp), %eax\n" /* line 398 | objTrace */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x2c(%edi), %eax\n" /* clip */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* localEnd */
        "movl %eax, 8(%esp)\n"
        "leal -0x3c(%ebp), %edx\n" /* localStart */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* obj */
        "calll DObjGeomTraceline\n"
        ".Lf1bcf10_001bd1e8:\n"
        "movss -0x60(%ebp), %xmm0\n" /* line 402 | objTrace */
        "movl 0x10(%ebp), %ebx\n" /* trace, obj */
        "ucomiss (%ebx), %xmm0\n" /* obj */
        "jae .Lf1bcf10_001bcf98\n"
        "movss %xmm0, (%ebx)\n" /* line 407 | obj */
        "movl -0x5c(%ebp), %eax\n" /* line 408 */
        "movl %eax, 0x10(%ebx)\n" /* obj */
        "movl -0x4c(%ebp), %eax\n" /* line 409 */
        "movw %ax, 0x1e(%ebx)\n" /* obj */
        "movzwl -0x4a(%ebp), %eax\n" /* line 410 */
        "movw %ax, 0x20(%ebx)\n" /* obj */
        "movl %ebx, %eax\n" /* line 411 | obj */
        "addl $4, %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x90(%ebp), %eax\n" /* entAxis */
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MatrixTransformVector\n"
        "jmp .Lf1bcf10_001bd061\n"
        ".Lf1bcf10_001bd235:\n"
        "movl 0x2c(%edi), %ecx\n" /* clip */
        "jmp .Lf1bcf10_001bcf8d\n"
        ".Lf1bcf10_001bd23d:\n"
        "movl 0x195ed4c, %edx\n"
        "jmp .Lf1bcf10_001bcffa\n"
        ".Lf1bcf10_001bd248:\n"
        "movl 0x2c(%edi), %eax\n" /* line 368 | clip */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* obj */
        "calll DObjHasContents\n"
        "testl %eax, %eax\n"
        "je .Lf1bcf10_001bcf98\n"
        "leal 0x138(%esi), %edx\n" /* line 369 | touch */
        /* { scope 2 */
        "movl 0x138(%esi), %eax\n" /* line 199 */
        "movl %eax, -0x6c(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x68(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x64(%ebp)\n"
        /* } scope */
        "leal -0x30(%ebp), %eax\n" /* line 372 | absmax */
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %edx\n" /* absmin */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* obj */
        "calll DObjGetBounds\n"
        "movss -0x6c(%ebp), %xmm3\n" /* line 240 */
        "movaps %xmm3, %xmm0\n"
        "addss -0x24(%ebp), %xmm0\n" /* absmin */
        "movss %xmm0, -0x24(%ebp)\n" /* absmin */
        "movss -0x68(%ebp), %xmm2\n" /* line 241 */
        "movaps %xmm2, %xmm0\n"
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss -0x64(%ebp), %xmm1\n" /* line 242 */
        "movaps %xmm1, %xmm0\n"
        "addss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "addss -0x30(%ebp), %xmm3\n" /* line 240 | absmax */
        "movss %xmm3, -0x30(%ebp)\n" /* absmax */
        "addss -0x2c(%ebp), %xmm2\n" /* line 241 */
        "movss %xmm2, -0x2c(%ebp)\n"
        "addss -0x28(%ebp), %xmm1\n" /* line 242 */
        "movss %xmm1, -0x28(%ebp)\n"
        "jmp .Lf1bcf10_001bd133\n"
        ".Lf1bcf10_001bd2e9:\n"
        "movl 0x11c(%esi), %eax\n" /* line 33 */
        "movl %eax, 8(%esp)\n"
        "leal 0x110(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x104(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_TempBoxModel\n"
        "movl %eax, %ecx\n"
        "jmp .Lf1bcf10_001bcfdf\n"
        ".Lf1bcf10_001bd312:\n"
        "leal -0x60(%ebp), %eax\n" /* line 400 | objTrace */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x34(%edi), %eax\n" /* clip */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* localEnd */
        "movl %eax, 8(%esp)\n"
        "leal -0x3c(%ebp), %edx\n" /* localStart */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* obj */
        "calll DObjTraceline\n"
        "jmp .Lf1bcf10_001bd1e8\n"
    );
}

/* line 453 */
__attribute__((naked))
int SV_ClipSightToEntity(const sightclip_t *clip, svEntity_t *check)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 453 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %edi\n" /* clip */
        "movl 0xc(%ebp), %edx\n" /* check */
        /* { scope 1 */
        "movl 0x195ee80, %eax\n" /* line 461 */
        "addl $0x2418, %eax\n"
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
        "leal (%edx, %eax, 4), %esi\n"
        "movl %esi, (%esp)\n" /* line 462 */
        "calll SV_GentityNum\n"
        "movl %eax, %ebx\n" /* touch */
        "movl 0x11c(%eax), %ecx\n" /* line 466 */
        "movl 0x44(%edi), %edx\n" /* clip */
        "testl %ecx, %edx\n"
        "je .Lf1bd33e_001bd428\n"
        "movl 0x3c(%edi), %eax\n" /* line 470 | clip */
        "cmpl $0x3ff, %eax\n"
        "je .Lf1bd33e_001bd3b0\n"
        "cmpl %eax, %esi\n" /* line 472 */
        "je .Lf1bd33e_001bd428\n"
        "cmpl 0x150(%ebx), %eax\n" /* line 474 | touch */
        "je .Lf1bd33e_001bd428\n"
        ".Lf1bd33e_001bd3b0:\n"
        "movl 0x40(%edi), %eax\n" /* line 478 | clip */
        "cmpl $0x3ff, %eax\n"
        "je .Lf1bd33e_001bd3c6\n"
        "cmpl %eax, %esi\n" /* line 480 */
        "je .Lf1bd33e_001bd428\n"
        "cmpl 0x150(%ebx), %eax\n" /* line 482 | touch */
        "je .Lf1bd33e_001bd428\n"
        ".Lf1bd33e_001bd3c6:\n"
        "cmpb $0, 0xf1(%ebx)\n" /* line 26 */
        "je .Lf1bd33e_001bd432\n"
        "movl 0x8c(%ebx), %ecx\n" /* line 29 */
        ".Lf1bd33e_001bd3d5:\n"
        "leal 0x144(%ebx), %eax\n" /* line 489 | touch */
        "cmpb $0, 0xf1(%ebx)\n" /* line 491 | touch */
        "jne .Lf1bd33e_001bd3e9\n"
        "movl 0x195ed4c, %eax\n"
        ".Lf1bd33e_001bd3e9:\n"
        "movl %eax, 0x20(%esp)\n" /* line 494 */
        "leal 0x138(%ebx), %eax\n" /* touch */
        "movl %eax, 0x1c(%esp)\n"
        "movl %edx, 0x18(%esp)\n"
        "movl %ecx, 0x14(%esp)\n"
        "leal 0xc(%edi), %eax\n" /* clip */
        "movl %eax, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n" /* clip */
        "leal 0x30(%edi), %eax\n" /* clip */
        "movl %eax, 8(%esp)\n"
        "leal 0x24(%edi), %eax\n" /* clip */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll CM_TransformedBoxSightTrace\n"
        "testl %eax, %eax\n" /* line 495 */
        "jne .Lf1bd33e_001bd455\n"
        ".Lf1bd33e_001bd428:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf1bd33e_001bd42a:\n"
        "addl $0x3c, %esp\n" /* line 498 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bd33e_001bd432:\n"
        "movl %ecx, 8(%esp)\n" /* line 33 */
        "leal 0x110(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x104(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_TempBoxModel\n"
        "movl %eax, %ecx\n"
        "movl 0x44(%edi), %edx\n"
        "jmp .Lf1bd33e_001bd3d5\n"
        ".Lf1bd33e_001bd455:\n"
        "movl $0xffffffff, %eax\n" /* line 495 */
        "jmp .Lf1bd33e_001bd42a\n"
    );
}

/* line 507 */
__attribute__((naked))
int SV_PointSightTraceToEntity(const sightpointtrace_t *clip, svEntity_t *check)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 507 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xec, %esp\n"
        "movl 8(%ebp), %esi\n" /* clip */
        "movl 0xc(%ebp), %edx\n" /* check */
        /* { scope 1 */
        "movl 0x195ee80, %eax\n" /* line 523 */
        "addl $0x2418, %eax\n"
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
        "leal (%edx, %eax, 4), %ebx\n"
        "movl %ebx, (%esp)\n" /* line 524 */
        "calll SV_GentityNum\n"
        "movl %eax, %edi\n" /* touch */
        "movl 0x20(%esi), %eax\n" /* line 528 | clip */
        "testl %eax, 0x11c(%edi)\n" /* touch */
        "je .Lf1bd45c_001bd55a\n"
        "movl 0x18(%esi), %eax\n" /* line 532 | clip */
        "cmpl $0x3ff, %eax\n"
        "je .Lf1bd45c_001bd4d3\n"
        "cmpl %eax, %ebx\n" /* line 534 */
        "je .Lf1bd45c_001bd55a\n"
        "cmpl 0x150(%edi), %eax\n" /* line 536 | touch */
        "je .Lf1bd45c_001bd55a\n"
        ".Lf1bd45c_001bd4d3:\n"
        "movl 0x1c(%esi), %eax\n" /* line 540 | clip */
        "cmpl $0x3ff, %eax\n"
        "je .Lf1bd45c_001bd4e9\n"
        "cmpl %eax, %ebx\n" /* line 542 */
        "je .Lf1bd45c_001bd55a\n"
        "cmpl 0x150(%edi), %eax\n" /* line 544 | touch */
        "je .Lf1bd45c_001bd55a\n"
        ".Lf1bd45c_001bd4e9:\n"
        "movl 0x24(%esi), %eax\n" /* line 548 | clip */
        "testl %eax, %eax\n"
        "jne .Lf1bd45c_001bd56f\n"
        ".Lf1bd45c_001bd4f0:\n"
        "cmpb $0, 0xf1(%edi)\n" /* line 26 */
        "je .Lf1bd45c_001bd74c\n"
        "movl 0x8c(%edi), %ecx\n" /* line 29 */
        ".Lf1bd45c_001bd503:\n"
        "leal 0x144(%edi), %eax\n" /* line 583 | touch */
        "cmpb $0, 0xf1(%edi)\n" /* line 585 | touch */
        "jne .Lf1bd45c_001bd567\n"
        "movl 0x195ed4c, %edx\n"
        "movl %edx, %eax\n"
        ".Lf1bd45c_001bd51a:\n"
        "movl %eax, 0x20(%esp)\n" /* line 588 */
        "leal 0x138(%edi), %eax\n" /* touch */
        "movl %eax, 0x1c(%esp)\n"
        "movl 0x20(%esi), %eax\n" /* clip */
        "movl %eax, 0x18(%esp)\n"
        "movl %ecx, 0x14(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "leal 0xc(%esi), %eax\n" /* clip */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* clip */
        "movl $0, (%esp)\n"
        "calll CM_TransformedBoxSightTrace\n"
        "testl %eax, %eax\n" /* line 589 */
        "jne .Lf1bd45c_001bd742\n"
        ".Lf1bd45c_001bd55a:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf1bd45c_001bd55c:\n"
        "addl $0xec, %esp\n" /* line 594 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1bd45c_001bd567:\n"
        "movl 0x195ed4c, %edx\n"
        "jmp .Lf1bd45c_001bd51a\n"
        /* { scope 1 */
        ".Lf1bd45c_001bd56f:\n"
        "movl (%edi), %eax\n" /* line 548 | touch */
        "movl %eax, (%esp)\n"
        "calll Com_GetServerDObj\n"
        "movl %eax, -0xbc(%ebp)\n" /* obj */
        "testl %eax, %eax\n"
        "je .Lf1bd45c_001bd4f0\n"
        "testb $4, 0xf2(%edi)\n" /* touch */
        "je .Lf1bd45c_001bd4f0\n"
        "movl 0x20(%esi), %eax\n" /* line 550 | clip */
        "movl %eax, 4(%esp)\n"
        "movl -0xbc(%ebp), %eax\n" /* obj */
        "movl %eax, (%esp)\n"
        "calll DObjHasContents\n"
        "testl %eax, %eax\n"
        "je .Lf1bd45c_001bd55a\n"
        "leal 0x138(%edi), %edx\n" /* touch */
        /* { scope 2 */
        "movl 0x138(%edi), %eax\n" /* line 199 */
        "movl %eax, -0x90(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x8c(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x88(%ebp)\n"
        /* } scope */
        "leal -0x3c(%ebp), %ebx\n" /* line 554 | absmax */
        "movl %ebx, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* absmin */
        "movl %eax, 4(%esp)\n"
        "movl -0xbc(%ebp), %eax\n" /* obj */
        "movl %eax, (%esp)\n"
        "calll DObjGetBounds\n"
        "movss -0x90(%ebp), %xmm3\n" /* line 240 */
        "movaps %xmm3, %xmm0\n"
        "addss -0x30(%ebp), %xmm0\n" /* absmin */
        "movss %xmm0, -0x30(%ebp)\n" /* absmin */
        "movss -0x8c(%ebp), %xmm2\n" /* line 241 */
        "movaps %xmm2, %xmm0\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss -0x88(%ebp), %xmm1\n" /* line 242 */
        "movaps %xmm1, %xmm0\n"
        "addss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "addss -0x3c(%ebp), %xmm3\n" /* line 240 | absmax */
        "movss %xmm3, -0x3c(%ebp)\n" /* absmax */
        "addss -0x38(%ebp), %xmm2\n" /* line 241 */
        "movss %xmm2, -0x38(%ebp)\n"
        "addss -0x34(%ebp), %xmm1\n" /* line 242 */
        "movss %xmm1, -0x34(%ebp)\n"
        "movl (%esi), %eax\n" /* line 199 */
        "movl %eax, -0x84(%ebp)\n" /* extents */
        "movl 4(%esi), %eax\n" /* line 200 */
        "movl %eax, -0x80(%ebp)\n"
        "movl 8(%esi), %eax\n" /* line 201 */
        "movl %eax, -0x7c(%ebp)\n"
        "leal 0xc(%esi), %edx\n" /* line 559 | clip, from */
        /* { scope 2 */
        "movl 0xc(%esi), %eax\n" /* line 199 */
        "movl %eax, -0x78(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x74(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x70(%ebp)\n"
        /* } scope */
        "leal -0x84(%ebp), %eax\n" /* line 560 | extents */
        "movl %eax, (%esp)\n"
        "calll CM_CalcTraceEntents\n"
        "movl $0x3f800000, 0xc(%esp)\n" /* line 562 */
        "movl %ebx, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* absmin */
        "movl %eax, 4(%esp)\n"
        "leal -0x84(%ebp), %eax\n" /* extents */
        "movl %eax, (%esp)\n"
        "calll CM_TraceBox\n"
        "testl %eax, %eax\n"
        "jne .Lf1bd45c_001bd55a\n"
        "movl %edi, (%esp)\n" /* line 565 | touch */
        "calll G_DObjCalcPose\n"
        "leal -0xb4(%ebp), %eax\n" /* line 567 | entAxis */
        "movl %eax, 4(%esp)\n"
        "leal 0x144(%edi), %eax\n" /* touch */
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "leal -0x24(%ebp), %edi\n" /* line 569 | localStart, touch */
        "movl %edi, 8(%esp)\n" /* touch */
        "leal -0xb4(%ebp), %eax\n" /* entAxis */
        "movl %eax, 4(%esp)\n"
        "leal -0x84(%ebp), %eax\n" /* extents */
        "movl %eax, (%esp)\n"
        "calll MatrixTransposeTransformVector43\n"
        "leal -0x48(%ebp), %ebx\n" /* line 570 | localEnd */
        "movl %ebx, 8(%esp)\n"
        "leal -0xb4(%ebp), %eax\n" /* entAxis */
        "movl %eax, 4(%esp)\n"
        "leal -0x78(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MatrixTransposeTransformVector43\n"
        "movl $0x3f800000, -0x60(%ebp)\n" /* line 572 | objTrace */
        "leal -0x60(%ebp), %eax\n" /* line 573 | objTrace */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x20(%esi), %eax\n" /* clip */
        "movl %eax, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* touch */
        "movl -0xbc(%ebp), %eax\n" /* obj */
        "movl %eax, (%esp)\n"
        "calll DObjGeomTraceline\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 575 | 1.0f */
        "ucomiss -0x60(%ebp), %xmm0\n" /* objTrace */
        "jbe .Lf1bd45c_001bd55a\n"
        ".Lf1bd45c_001bd742:\n"
        "movl $0xffffffff, %eax\n" /* line 589 */
        "jmp .Lf1bd45c_001bd55c\n"
        ".Lf1bd45c_001bd74c:\n"
        "movl 0x11c(%edi), %eax\n" /* line 33 */
        "movl %eax, 8(%esp)\n"
        "leal 0x110(%edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x104(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_TempBoxModel\n"
        "movl %eax, %ecx\n"
        "jmp .Lf1bd45c_001bd503\n"
    );
}

/* line 896 */
__attribute__((naked))
int SV_SightTraceToEntity(const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int entityNum, int contentmask)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 896 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 0x10(%ebp), %edi\n" /* maxs */
        /* { scope 1 */
        "movl 0x18(%ebp), %eax\n" /* line 907 | entityNum */
        "movl %eax, (%esp)\n"
        "calll SV_GentityNum\n"
        "movl %eax, %ebx\n" /* ent */
        "movl 0x1c(%ebp), %eax\n" /* line 909 | contentmask */
        "testl %eax, 0x11c(%ebx)\n" /* ent */
        "je .Lf1bd776_001bd8d0\n"
        "movl $1, %edx\n"
        "leal -0x24(%ebp), %esi\n" /* boxmins */
        "movss 0x2ed5d0, %xmm2\n" /* 1.0f */
        ".Lf1bd776_001bd7ae:\n"
        "leal (, %edx, 4), %eax\n" /* line 896 | entityNum */
        "movl 0x14(%ebp), %ecx\n" /* line 927 | end */
        "movss -4(%ecx, %eax), %xmm1\n"
        "movl 8(%ebp), %ecx\n" /* start */
        "movss -4(%ecx, %eax), %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf1bd776_001bd8da\n"
        "movl 0xc(%ebp), %ecx\n" /* line 929 | mins */
        "addss -4(%ecx, %eax), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, -4(%esi, %eax)\n"
        "addss -4(%edi, %eax), %xmm1\n" /* line 930 | maxs */
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0x34(%ebp, %eax)\n"
        ".Lf1bd776_001bd7f3:\n"
        "addl $1, %edx\n" /* line 935 */
        "cmpl $4, %edx\n" /* line 925 */
        "jne .Lf1bd776_001bd7ae\n"
        "movss 0x120(%ebx), %xmm0\n" /* line 939 | ent */
        "ucomiss -0x30(%ebp), %xmm0\n" /* boxmaxs */
        "ja .Lf1bd776_001bd8d0\n"
        "movss 0x124(%ebx), %xmm0\n" /* ent */
        "ucomiss -0x2c(%ebp), %xmm0\n"
        "ja .Lf1bd776_001bd8d0\n"
        "movss 0x128(%ebx), %xmm0\n" /* ent */
        "ucomiss -0x28(%ebp), %xmm0\n"
        "ja .Lf1bd776_001bd8d0\n"
        "movss -0x24(%ebp), %xmm0\n" /* boxmins */
        "ucomiss 0x12c(%ebx), %xmm0\n" /* ent */
        "ja .Lf1bd776_001bd8d0\n"
        "movss -0x20(%ebp), %xmm0\n"
        "ucomiss 0x130(%ebx), %xmm0\n" /* ent */
        "ja .Lf1bd776_001bd8d0\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "ucomiss 0x134(%ebx), %xmm0\n" /* ent */
        "ja .Lf1bd776_001bd8d0\n"
        "cmpb $0, 0xf1(%ebx)\n" /* line 26 */
        "je .Lf1bd776_001bd902\n"
        "movl 0x8c(%ebx), %eax\n" /* line 29 */
        ".Lf1bd776_001bd872:\n"
        "leal 0x138(%ebx), %ecx\n" /* line 944 | ent */
        "leal 0x144(%ebx), %edx\n" /* line 945 | ent */
        "cmpb $0, 0xf1(%ebx)\n" /* line 947 | ent */
        "jne .Lf1bd776_001bd88d\n"
        "movl 0x195ed4c, %edx\n"
        ".Lf1bd776_001bd88d:\n"
        "movl %edx, 0x20(%esp)\n" /* line 950 */
        "movl %ecx, 0x1c(%esp)\n"
        "movl 0x1c(%ebp), %edx\n" /* contentmask */
        "movl %edx, 0x18(%esp)\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %edi, 0x10(%esp)\n" /* maxs */
        "movl 0xc(%ebp), %ecx\n" /* mins */
        "movl %ecx, 0xc(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* end */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %edx\n" /* start */
        "movl %edx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll CM_TransformedBoxSightTrace\n"
        "testl %eax, %eax\n" /* line 951 */
        "je .Lf1bd776_001bd8d0\n"
        "movl $0xffffffff, %eax\n"
        "jmp .Lf1bd776_001bd8d2\n"
        ".Lf1bd776_001bd8d0:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf1bd776_001bd8d2:\n"
        "addl $0x5c, %esp\n" /* line 954 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1bd776_001bd8da:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 934 | mins */
        "addss -4(%ecx, %eax), %xmm1\n"
        "subss %xmm2, %xmm1\n"
        "movss %xmm1, -4(%esi, %eax)\n"
        "addss -4(%edi, %eax), %xmm0\n" /* line 935 | maxs */
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -0x34(%ebp, %eax)\n"
        "jmp .Lf1bd776_001bd7f3\n"
        ".Lf1bd776_001bd902:\n"
        "movl 0x11c(%ebx), %eax\n" /* line 33 */
        "movl %eax, 8(%esp)\n"
        "leal 0x110(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x104(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_TempBoxModel\n"
        "jmp .Lf1bd776_001bd872\n"
    );
}

/* line 1001 */
__attribute__((naked))
int SV_PointContents(const vec_t *p, int passEntityNum, int contentmask)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1001 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x103c, %esp\n"
        /* { scope 1 */
        "movl $0, 4(%esp)\n" /* line 1010 */
        "movl 8(%ebp), %eax\n" /* p */
        "movl %eax, (%esp)\n"
        "calll CM_PointContents\n"
        "movl %eax, %edi\n" /* contents */
        "movl 0x10(%ebp), %eax\n" /* line 1013 | contentmask */
        "movl %eax, 0x10(%esp)\n"
        "movl $0x400, 0xc(%esp)\n"
        "leal -0x1018(%ebp), %eax\n" /* touch */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* p */
        "movl %eax, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CM_AreaEntities\n"
        "movl %eax, -0x101c(%ebp)\n" /* num */
        "testl %eax, %eax\n" /* line 1015 */
        "jle .Lf1bd92a_001bd9fc\n"
        "xorl %esi, %esi\n" /* i */
        "jmp .Lf1bd92a_001bd9b7\n"
        ".Lf1bd92a_001bd981:\n"
        "movl 0x8c(%eax), %edx\n" /* line 29 */
        ".Lf1bd92a_001bd987:\n"
        "leal 0x144(%ebx), %eax\n" /* line 1024 | hit */
        "movl %eax, 0xc(%esp)\n"
        "leal 0x138(%ebx), %eax\n" /* hit */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* p */
        "movl %eax, (%esp)\n"
        "calll CM_TransformedPointContents\n"
        "orl %eax, %edi\n" /* contents */
        ".Lf1bd92a_001bd9ac:\n"
        "addl $1, %esi\n" /* line 1015 | i */
        "cmpl %esi, -0x101c(%ebp)\n" /* i, num */
        "je .Lf1bd92a_001bd9fc\n"
        ".Lf1bd92a_001bd9b7:\n"
        "movl -0x1018(%ebp, %esi, 4), %eax\n" /* line 1017 */
        "cmpl 0xc(%ebp), %eax\n" /* passEntityNum */
        "je .Lf1bd92a_001bd9ac\n"
        "movl %eax, (%esp)\n" /* line 1021 */
        "calll SV_GentityNum\n"
        "movl %eax, %ebx\n" /* hit */
        "cmpb $0, 0xf1(%eax)\n" /* line 26 */
        "jne .Lf1bd92a_001bd981\n"
        "movl 0x11c(%eax), %eax\n" /* line 33 */
        "movl %eax, 8(%esp)\n"
        "leal 0x110(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x104(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CM_TempBoxModel\n"
        "movl %eax, %edx\n"
        "jmp .Lf1bd92a_001bd987\n"
        ".Lf1bd92a_001bd9fc:\n"
        "andl %edi, 0x10(%ebp)\n" /* line 1015 | contents, contentmask */
        /* } scope */
        "movl 0x10(%ebp), %eax\n" /* line 1028 | contentmask */
        "addl $0x103c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

