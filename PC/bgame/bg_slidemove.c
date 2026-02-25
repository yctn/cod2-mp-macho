/* ASM dump from: bg_slidemove.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/bgame/bg_slidemove.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/q_shared.h"
 *   #include "PC/universal/com_math.h"
 */

static qboolean PM_SlideMove(pmove_t *pm, pml_t *pml, qboolean gravity);
jpeg_component_info PM_StepSlideMove(pmove_t *pm, pml_t *pml, qboolean gravity);

/* line 89 */
static __attribute__((naked))
qboolean PM_SlideMove(pmove_t *pm, pml_t *pml, qboolean gravity)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 89 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x17c, %esp\n"
        "movl %eax, -0x14c(%ebp)\n"
        "movl %edx, -0x150(%ebp)\n"
        "movl %ecx, -0x154(%ebp)\n"
        /* { scope 1: parallel */
        "movl (%eax), %eax\n" /* line 108 */
        "movl %eax, -0x13c(%ebp)\n" /* ps */
        "addl $0x20, %eax\n" /* line 113 */
        "movl %eax, -0x148(%ebp)\n"
        "movl -0x13c(%ebp), %edx\n" /* line 199 | ps */
        "movss 0x20(%edx), %xmm0\n"
        "movss %xmm0, -0x128(%ebp)\n"
        "addl $0x24, %edx\n" /* line 200 */
        "movl %edx, -0x138(%ebp)\n"
        "movl -0x13c(%ebp), %eax\n" /* ps */
        "movss 0x24(%eax), %xmm0\n"
        "movss %xmm0, -0x12c(%ebp)\n"
        "addl $0x28, %eax\n" /* line 201 */
        "movl %eax, -0x134(%ebp)\n"
        "movl -0x13c(%ebp), %eax\n" /* ps */
        "movss 0x28(%eax), %xmm0\n"
        "movss %xmm0, -0x130(%ebp)\n"
        "movss -0x128(%ebp), %xmm1\n" /* line 199 */
        "movss %xmm1, -0x30(%ebp)\n" /* endVelocity */
        "movl %eax, %edx\n" /* line 200 */
        "movl 0x24(%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movss 0x28(%edx), %xmm1\n" /* line 201 */
        "movss %xmm1, -0x28(%ebp)\n"
        "testl %ecx, %ecx\n" /* line 116 */
        "je .Lf9da1c_0009daff\n"
        "cvtsi2ssl 0x48(%edx), %xmm0\n" /* line 118 */
        "movl -0x150(%ebp), %ecx\n"
        "mulss 0x24(%ecx), %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "addss 0x28(%edx), %xmm0\n" /* line 119 */
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, 0x28(%edx)\n"
        "movss -0x28(%ebp), %xmm0\n" /* line 120 */
        "movss %xmm0, -0x130(%ebp)\n"
        "movl 0x30(%ecx), %edi\n" /* line 121 | permutedIndex */
        "testl %edi, %edi\n" /* permutedIndex */
        "jne .Lf9da1c_0009e324\n"
        ".Lf9da1c_0009daff:\n"
        "movl -0x150(%ebp), %ecx\n" /* line 128 */
        "movss 0x24(%ecx), %xmm0\n"
        "movss %xmm0, -0x140(%ebp)\n" /* time_left */
        "movl 0x30(%ecx), %esi\n" /* line 131 | j */
        "testl %esi, %esi\n" /* j */
        "jne .Lf9da1c_0009e255\n"
        "xorl %edx, %edx\n"
        "movl $1, -0x11c(%ebp)\n"
        ".Lf9da1c_0009db29:\n"
        "leal (%edx, %edx), %eax\n" /* line 142 */
        "addl %edx, %eax\n"
        "leal -0x118(%ebp, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x148(%ebp), %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll Vec3NormalizeTo\n"
        "fstp %st(0)\n"
        "movl $0, -0x144(%ebp)\n" /* bumpcount */
        "movl -0x13c(%ebp), %eax\n" /* ps */
        "addl $0x14, %eax\n"
        "movl %eax, -0x15c(%ebp)\n"
        "movl -0x14c(%ebp), %edx\n"
        "addl $0xd0, %edx\n"
        "movl %edx, -0x164(%ebp)\n"
        "movl -0x14c(%ebp), %ecx\n"
        "addl $0xc4, %ecx\n"
        "movl %ecx, -0x160(%ebp)\n"
        "movl -0x11c(%ebp), %ebx\n"
        "leal (%ebx, %ebx, 2), %eax\n"
        "leal -0x118(%ebp, %eax, 4), %eax\n"
        "movl %eax, -0x168(%ebp)\n"
        ".Lf9da1c_0009db9c:\n"
        "movss -0x140(%ebp), %xmm0\n" /* line 288 | time_left */
        "movl -0x148(%ebp), %eax\n"
        "mulss (%eax), %xmm0\n"
        "movl -0x13c(%ebp), %edx\n" /* ps */
        "addss 0x14(%edx), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* end */
        "movss -0x140(%ebp), %xmm0\n" /* line 289 | time_left */
        "movl -0x138(%ebp), %ecx\n"
        "mulss (%ecx), %xmm0\n"
        "addss 0x18(%edx), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss -0x140(%ebp), %xmm0\n" /* line 290 | time_left */
        "movl -0x134(%ebp), %ebx\n"
        "mulss (%ebx), %xmm0\n"
        "addss 0x1c(%edx), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl -0x14c(%ebp), %edx\n" /* line 151 */
        "movl 0x3c(%edx), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl -0x13c(%ebp), %ecx\n" /* ps */
        "movl 0xcc(%ecx), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "leal -0x24(%ebp), %ebx\n" /* end */
        "movl %ebx, 0x14(%esp)\n"
        "movl -0x164(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x160(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl -0x15c(%ebp), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "leal -0xb8(%ebp), %ebx\n" /* trace */
        "movl %ebx, 4(%esp)\n"
        "movl -0x14c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll PM_playerTrace\n"
        "cmpb $0, -0x96(%ebp)\n" /* line 153 */
        "jne .Lf9da1c_0009e34a\n"
        "movss -0xb8(%ebp), %xmm2\n" /* line 160 | trace */
        "ucomiss 0x2ed5e8, %xmm2\n" /* 0.0f */
        "jbe .Lf9da1c_0009dccb\n"
        "movl -0x13c(%ebp), %edx\n" /* line 1203 | ps */
        "movss 0x14(%edx), %xmm1\n"
        "movss -0x24(%ebp), %xmm0\n" /* end */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x14(%edx)\n"
        "movss 0x18(%edx), %xmm1\n" /* line 1204 */
        "movss -0x20(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movl -0x15c(%ebp), %ecx\n"
        "movss %xmm1, 4(%ecx)\n"
        "movss 0x1c(%edx), %xmm1\n" /* line 1205 */
        "movss -0x1c(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, 8(%ecx)\n"
        ".Lf9da1c_0009dccb:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 163 | 1.0f */
        "ucomiss -0xb8(%ebp), %xmm0\n" /* trace */
        "jp .Lf9da1c_0009dce2\n"
        "je .Lf9da1c_0009de3b\n"
        ".Lf9da1c_0009dce2:\n"
        "movzwl -0x9c(%ebp), %eax\n" /* line 167 */
        "movl %eax, 4(%esp)\n"
        "movl -0x14c(%ebp), %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll PM_AddTouchEnt\n"
        "movss -0x140(%ebp), %xmm0\n" /* line 169 | time_left */
        "mulss -0xb8(%ebp), %xmm0\n" /* trace */
        "movss -0x140(%ebp), %xmm1\n" /* time_left */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x140(%ebp)\n" /* time_left */
        "cmpl $7, -0x11c(%ebp)\n" /* line 171 */
        "jg .Lf9da1c_0009e361\n"
        "movl -0x11c(%ebp), %ecx\n" /* line 182 */
        "testl %ecx, %ecx\n"
        "jle .Lf9da1c_0009de71\n"
        "movss -0xb4(%ebp), %xmm3\n" /* line 304 */
        "movss -0xb0(%ebp), %xmm5\n"
        "movss -0xac(%ebp), %xmm4\n"
        "movaps %xmm4, %xmm0\n" /* line 184 */
        "mulss -0x110(%ebp), %xmm0\n"
        "movaps %xmm5, %xmm1\n"
        "mulss -0x114(%ebp), %xmm1\n"
        "movaps %xmm3, %xmm2\n"
        "mulss -0x118(%ebp), %xmm2\n" /* planes */
        "addss %xmm2, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "ucomiss 0x2ed690, %xmm0\n" /* 0.9990000128746033f */
        "ja .Lf9da1c_0009ddc7\n"
        "xorl %edx, %edx\n" /* line 189 */
        ".Lf9da1c_0009dd86:\n"
        "addl $1, %edx\n" /* line 182 */
        "cmpl -0x11c(%ebp), %edx\n"
        "je .Lf9da1c_0009de79\n"
        "leal (%edx, %edx, 2), %eax\n" /* line 174 */
        "leal -0x118(%ebp, %eax, 4), %eax\n"
        "movaps %xmm4, %xmm2\n" /* line 184 */
        "mulss 8(%eax), %xmm2\n"
        "movaps %xmm5, %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss (%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "ucomiss 0x2ed690, %xmm2\n" /* 0.9990000128746033f */
        "jbe .Lf9da1c_0009dd86\n"
        ".Lf9da1c_0009ddc7:\n"
        "movl -0x148(%ebp), %edx\n" /* line 186 */
        "movl %edx, 8(%esp)\n"
        "leal -0xb4(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll PM_ClipVelocity\n"
        "movss -0xb4(%ebp), %xmm0\n" /* line 240 */
        "movl -0x148(%ebp), %ecx\n"
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "movss -0xb0(%ebp), %xmm0\n" /* line 241 */
        "movl -0x138(%ebp), %ebx\n"
        "addss (%ebx), %xmm0\n"
        "movss %xmm0, 4(%ecx)\n"
        "movss -0xac(%ebp), %xmm0\n" /* line 242 */
        "movl -0x134(%ebp), %eax\n"
        "addss (%eax), %xmm0\n"
        "movss %xmm0, 8(%ecx)\n"
        ".Lf9da1c_0009de27:\n"
        "addl $1, -0x144(%ebp)\n" /* line 145 | bumpcount */
        "cmpl $4, -0x144(%ebp)\n" /* bumpcount */
        "jne .Lf9da1c_0009db9c\n"
        ".Lf9da1c_0009de3b:\n"
        "movl -0x154(%ebp), %edx\n" /* line 261 */
        "testl %edx, %edx\n"
        "jne .Lf9da1c_0009e2cb\n"
        "movl -0x13c(%ebp), %ebx\n" /* line 265 | ps */
        "movl 0x10(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf9da1c_0009e2f3\n"
        ".Lf9da1c_0009de5a:\n"
        "xorl %eax, %eax\n" /* line 268 */
        "cmpl $0, -0x144(%ebp)\n" /* bumpcount */
        "setne %al\n"
        /* } scope */
        ".Lf9da1c_0009de66:\n"
        "addl $0x17c, %esp\n" /* line 269 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf9da1c_0009de71:\n"
        "movss -0xb4(%ebp), %xmm3\n"
        /* { scope 1: parallel */
        ".Lf9da1c_0009de79:\n"
        "movl -0x168(%ebp), %edx\n" /* line 199 */
        "movss %xmm3, (%edx)\n"
        "movl -0xb0(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0xac(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "addl $1, -0x11c(%ebp)\n" /* line 197 */
        "addl $0xc, %edx\n"
        "movl %edx, -0x168(%ebp)\n"
        /* { scope 2 */
        "movl -0x11c(%ebp), %ebx\n" /* line 59 */
        "testl %ebx, %ebx\n"
        "jle .Lf9da1c_0009df7e\n"
        /* } scope */
        "xorl %edi, %edi\n" /* line 182 | permutedIndex */
        "leal -0x118(%ebp), %ecx\n" /* planes */
        "movl %ecx, -0x124(%ebp)\n"
        "movl $0, -0x120(%ebp)\n"
        "movl %ecx, %eax\n"
        "jmp .Lf9da1c_0009df0f\n"
        ".Lf9da1c_0009decf:\n"
        "movl -0x120(%ebp), %esi\n" /* line 184 | j */
        /* { scope 2 */
        "movl -0x98(%ebp, %eax), %edx\n" /* line 64 */
        "ucomiss -0x74(%ebp, %edx, 4), %xmm1\n"
        "jbe .Lf9da1c_0009e207\n"
        "movl %esi, %eax\n"
        ".Lf9da1c_0009dee9:\n"
        "movl %edi, -0x94(%ebp, %eax)\n" /* line 68 | permutedIndex */
        "addl $1, %edi\n" /* line 59 | permutedIndex */
        "addl $0xc, -0x124(%ebp)\n"
        "addl $4, -0x120(%ebp)\n"
        "cmpl %edi, -0x11c(%ebp)\n" /* permutedIndex */
        "je .Lf9da1c_0009df7e\n"
        ".Lf9da1c_0009df09:\n"
        "movl -0x124(%ebp), %eax\n"
        ".Lf9da1c_0009df0f:\n"
        "movl -0x148(%ebp), %ebx\n" /* line 304 */
        "movss (%ebx), %xmm1\n"
        "mulss (%eax), %xmm1\n"
        "movl -0x138(%ebp), %edx\n"
        "movss (%edx), %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movl -0x134(%ebp), %ecx\n"
        "movss (%ecx), %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "leal (, %edi, 4), %eax\n" /* line 61 */
        "movss %xmm1, -0x74(%ebp, %eax)\n"
        "testl %edi, %edi\n" /* line 62 | permutedIndex */
        "jne .Lf9da1c_0009decf\n"
        "movl -0x120(%ebp), %eax\n"
        "movl %edi, -0x94(%ebp, %eax)\n" /* line 68 | permutedIndex */
        "addl $1, %edi\n" /* line 59 | permutedIndex */
        "addl $0xc, -0x124(%ebp)\n"
        "addl $4, -0x120(%ebp)\n"
        "cmpl %edi, -0x11c(%ebp)\n" /* permutedIndex */
        "jne .Lf9da1c_0009df09\n"
        ".Lf9da1c_0009df7e:\n"
        "movl -0x94(%ebp), %eax\n" /* line 70 | permutation */
        "movss -0x74(%ebp, %eax, 4), %xmm0\n"
        /* } scope */
        "ucomiss 0x2ed7d0, %xmm0\n" /* line 204 | 0.10000000149011612f */
        "jae .Lf9da1c_0009de27\n"
        "xorps 0x2f1b80, %xmm0\n" /* line 208 */
        "movl -0x150(%ebp), %edx\n"
        "ucomiss 0x5c(%edx), %xmm0\n"
        "ja .Lf9da1c_0009e28f\n"
        ".Lf9da1c_0009dfae:\n"
        "leal -0x48(%ebp), %ecx\n" /* line 212 | clipVelocity */
        "movl %ecx, 8(%esp)\n"
        "leal (%eax, %eax, 2), %eax\n"
        "leal -0x118(%ebp, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x148(%ebp), %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll PM_ClipVelocity\n"
        "leal -0x54(%ebp), %eax\n" /* line 215 | endClipVelocity */
        "movl %eax, 8(%esp)\n"
        "movl -0x94(%ebp), %eax\n" /* permutation */
        "leal (%eax, %eax, 2), %eax\n"
        "leal -0x118(%ebp, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* endVelocity */
        "movl %eax, (%esp)\n"
        "calll PM_ClipVelocity\n"
        "cmpl $1, -0x11c(%ebp)\n" /* line 218 */
        "jle .Lf9da1c_0009e299\n"
        "movl $1, %esi\n" /* j */
        "leal -0x94(%ebp), %edi\n" /* permutation, permutedIndex */
        "movss -0x48(%ebp), %xmm5\n" /* clipVelocity */
        "leal -0x8c(%ebp), %ebx\n"
        "jmp .Lf9da1c_0009e02e\n"
        ".Lf9da1c_0009e01c:\n"
        "addl $1, %esi\n" /* j */
        "addl $4, %ebx\n"
        "cmpl %esi, -0x11c(%ebp)\n" /* j */
        "je .Lf9da1c_0009e29e\n"
        ".Lf9da1c_0009e02e:\n"
        "movl -4(%ebx), %eax\n" /* line 220 */
        "leal (%eax, %eax, 2), %eax\n"
        "leal -0x118(%ebp, %eax, 4), %eax\n"
        "movaps %xmm5, %xmm1\n"
        "mulss (%eax), %xmm1\n"
        "movss -0x44(%ebp), %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x40(%ebp), %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "ucomiss 0x2ed7d0, %xmm1\n" /* 0.10000000149011612f */
        "jae .Lf9da1c_0009e01c\n"
        "leal -0x48(%ebp), %edx\n" /* line 224 | clipVelocity */
        "movl %edx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll PM_ClipVelocity\n"
        "leal -0x54(%ebp), %eax\n" /* line 225 | endClipVelocity */
        "movl %eax, 8(%esp)\n"
        "movl -4(%ebx), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "leal -0x118(%ebp, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x54(%ebp), %edx\n" /* endClipVelocity */
        "movl %edx, (%esp)\n"
        "calll PM_ClipVelocity\n"
        "movl -0x94(%ebp), %eax\n" /* line 228 | permutation */
        "leal (%eax, %eax, 2), %eax\n"
        "leal -0x118(%ebp, %eax, 4), %edx\n"
        "movss -0x48(%ebp), %xmm5\n" /* clipVelocity */
        "movaps %xmm5, %xmm1\n"
        "mulss (%edx), %xmm1\n"
        "movss -0x44(%ebp), %xmm0\n"
        "mulss 4(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x40(%ebp), %xmm0\n"
        "mulss 8(%edx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "ucomiss 0x2ed5e8, %xmm1\n" /* 0.0f */
        "jae .Lf9da1c_0009e01c\n"
        "leal -0x3c(%ebp), %ecx\n" /* line 232 | dir */
        "movl %ecx, 8(%esp)\n"
        "movl -4(%ebx), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "leal -0x118(%ebp, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Vec3Cross\n"
        "leal -0x3c(%ebp), %eax\n" /* line 233 | dir */
        "movl %eax, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movss -0x3c(%ebp), %xmm3\n" /* line 304 | dir */
        "movaps %xmm3, %xmm0\n"
        "movl -0x148(%ebp), %edx\n"
        "mulss (%edx), %xmm0\n"
        "movss -0x38(%ebp), %xmm4\n"
        "movaps %xmm4, %xmm1\n"
        "movl -0x138(%ebp), %ecx\n"
        "mulss (%ecx), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss -0x34(%ebp), %xmm2\n"
        "movaps %xmm2, %xmm1\n"
        "movl -0x134(%ebp), %eax\n"
        "mulss (%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm3, %xmm5\n" /* line 272 */
        "mulss %xmm0, %xmm5\n"
        "movss %xmm5, -0x48(%ebp)\n" /* clipVelocity */
        "movaps %xmm0, %xmm7\n" /* line 273 */
        "mulss %xmm4, %xmm7\n"
        "movss %xmm7, -0x44(%ebp)\n"
        "movaps %xmm0, %xmm6\n" /* line 274 */
        "mulss %xmm2, %xmm6\n"
        "movss %xmm6, -0x40(%ebp)\n"
        "movaps %xmm3, %xmm0\n" /* line 304 */
        "mulss -0x30(%ebp), %xmm0\n" /* endVelocity */
        "mulss -0x2c(%ebp), %xmm4\n"
        "addss %xmm4, %xmm0\n"
        "mulss -0x28(%ebp), %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm3\n" /* line 272 */
        "movss %xmm3, -0x54(%ebp)\n" /* endClipVelocity */
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -0x38(%ebp), %xmm1\n"
        "movss %xmm1, -0x50(%ebp)\n"
        "mulss -0x34(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, -0x4c(%ebp)\n"
        /* { scope 2 */
        "movl $1, %ecx\n" /* line 304 */
        "leal 4(%edi), %edx\n" /* permutedIndex */
        /* } scope */
        ".Lf9da1c_0009e1b3:\n"
        "cmpl %ecx, %esi\n" /* line 244 | j */
        "je .Lf9da1c_0009e1ef\n"
        "movl (%edx), %eax\n" /* line 245 */
        "leal (%eax, %eax, 2), %eax\n"
        "leal -0x118(%ebp, %eax, 4), %eax\n"
        "movaps %xmm5, %xmm0\n" /* line 247 */
        "mulss (%eax), %xmm0\n"
        "movaps %xmm7, %xmm1\n"
        "mulss 4(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm6, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "ucomiss 0x2ed7d0, %xmm0\n" /* 0.10000000149011612f */
        "jb .Lf9da1c_0009e385\n"
        ".Lf9da1c_0009e1ef:\n"
        "addl $1, %ecx\n" /* line 242 */
        "addl $4, %edx\n"
        "cmpl %ecx, -0x11c(%ebp)\n"
        "jne .Lf9da1c_0009e1b3\n"
        "movss -0x48(%ebp), %xmm5\n" /* clipVelocity */
        "jmp .Lf9da1c_0009e01c\n"
        ".Lf9da1c_0009e207:\n"
        "movl %esi, %eax\n" /* j */
        /* { scope 2 */
        "subl $4, %eax\n" /* line 64 */
        "movl %edi, %ecx\n" /* permutedIndex */
        "movl $1, %ebx\n"
        "subl $1, %ebx\n"
        "movl %ebx, -0x158(%ebp)\n"
        "jmp .Lf9da1c_0009e237\n"
        ".Lf9da1c_0009e21e:\n"
        "movl -0x98(%ebp, %eax), %edx\n"
        "leal -4(%eax), %ebx\n"
        "ucomiss -0x74(%ebp, %edx, 4), %xmm1\n"
        "ja .Lf9da1c_0009dee9\n"
        "movl %eax, %esi\n" /* line 65 */
        "movl %ebx, %eax\n"
        ".Lf9da1c_0009e237:\n"
        "movl %edx, -0x94(%ebp, %esi)\n" /* line 66 */
        "subl $1, %ecx\n" /* line 62 */
        "cmpl %ecx, -0x158(%ebp)\n"
        "jne .Lf9da1c_0009e21e\n"
        "leal (, %ecx, 4), %eax\n"
        "jmp .Lf9da1c_0009dee9\n"
        ".Lf9da1c_0009e255:\n"
        "movl %ecx, %edx\n"
        /* } scope */
        "addl $0x3c, %edx\n" /* line 131 */
        /* { scope 2 */
        "movl -0x150(%ebp), %ecx\n" /* line 199 */
        "movl 0x3c(%ecx), %eax\n"
        "movl %eax, -0x118(%ebp)\n" /* planes */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x114(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x110(%ebp)\n"
        "movl $1, %edx\n"
        "movl $2, -0x11c(%ebp)\n"
        "jmp .Lf9da1c_0009db29\n"
        /* } scope */
        ".Lf9da1c_0009e28f:\n"
        "movss %xmm0, 0x5c(%edx)\n" /* line 209 */
        "jmp .Lf9da1c_0009dfae\n"
        ".Lf9da1c_0009e299:\n"
        "movss -0x48(%ebp), %xmm5\n" /* clipVelocity */
        ".Lf9da1c_0009e29e:\n"
        "movl -0x148(%ebp), %edx\n" /* line 199 */
        "movss %xmm5, (%edx)\n"
        "movl -0x44(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x40(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "movl -0x54(%ebp), %eax\n" /* line 199 | endClipVelocity */
        "movl %eax, -0x30(%ebp)\n" /* endVelocity */
        "movl -0x50(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl -0x4c(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x28(%ebp)\n"
        "jmp .Lf9da1c_0009de27\n"
        ".Lf9da1c_0009e2cb:\n"
        "movl -0x30(%ebp), %eax\n" /* line 199 | endVelocity */
        "movl -0x148(%ebp), %ecx\n"
        "movl %eax, (%ecx)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        "movl -0x13c(%ebp), %ebx\n" /* line 265 | ps */
        "movl 0x10(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf9da1c_0009de5a\n"
        ".Lf9da1c_0009e2f3:\n"
        "movss -0x128(%ebp), %xmm0\n" /* line 199 */
        "movl -0x148(%ebp), %eax\n"
        "movss %xmm0, (%eax)\n"
        "movss -0x12c(%ebp), %xmm1\n" /* line 200 */
        "movss %xmm1, 4(%eax)\n"
        "movss -0x130(%ebp), %xmm0\n" /* line 201 */
        "movss %xmm0, 8(%eax)\n"
        "jmp .Lf9da1c_0009de5a\n"
        ".Lf9da1c_0009e324:\n"
        "movl -0x148(%ebp), %eax\n" /* line 124 */
        "movl %eax, 8(%esp)\n"
        "movl %ecx, %eax\n"
        "addl $0x3c, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x148(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll PM_ClipVelocity\n"
        "jmp .Lf9da1c_0009daff\n"
        ".Lf9da1c_0009e34a:\n"
        "movl -0x13c(%ebp), %eax\n" /* line 156 | ps */
        "movl $0, 0x28(%eax)\n"
        "movl $1, %eax\n"
        "jmp .Lf9da1c_0009de66\n"
        ".Lf9da1c_0009e361:\n"
        "movl -0x148(%ebp), %eax\n" /* line 183 */
        "movl $0, (%eax)\n"
        "movl $0, 4(%eax)\n" /* line 184 */
        "movl $0, 8(%eax)\n" /* line 185 */
        "movl $1, %eax\n"
        "jmp .Lf9da1c_0009de66\n"
        ".Lf9da1c_0009e385:\n"
        "xorl %eax, %eax\n" /* line 183 */
        "movl -0x148(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "movl %eax, 4(%edx)\n" /* line 184 */
        "movl %eax, 8(%edx)\n" /* line 185 */
        "movl $1, %eax\n"
        "jmp .Lf9da1c_0009de66\n"
    );
}

/* line 278 */
__attribute__((naked))
jpeg_component_info PM_StepSlideMove(pmove_t *pm, pml_t *pml, qboolean gravity)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 278 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x11c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 296 | pm */
        "movl (%eax), %ebx\n" /* ps */
        "movl 0xc(%ebx), %eax\n" /* line 301 | ps */
        "testb $0x20, %al\n"
        "jne .Lf9e3a0_0009e9bc\n"
        "movl 0xc(%ebp), %edx\n" /* line 308 | pml */
        "movl 0x30(%edx), %esi\n" /* ps */
        "testl %esi, %esi\n" /* ps */
        "je .Lf9e3a0_0009e5e0\n"
        "movl $1, -0xb4(%ebp)\n" /* bHadGround */
        ".Lf9e3a0_0009e3d4:\n"
        "leal 0x14(%ebx), %esi\n" /* line 321 | ps */
        "movl 0x14(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x28(%ebp)\n" /* start_o */
        "leal 0x18(%ebx), %eax\n" /* line 200 */
        "movl %eax, -0xac(%ebp)\n"
        "movl 0x18(%ebx), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "leal 0x1c(%ebx), %edx\n" /* line 201 */
        "movl %edx, -0xa8(%ebp)\n"
        "movl 0x1c(%ebx), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "leal 0x20(%ebx), %edi\n" /* line 322 | ps */
        "movss 0x20(%ebx), %xmm0\n" /* line 199 */
        "movss %xmm0, -0x90(%ebp)\n"
        "leal 0x24(%ebx), %eax\n" /* line 200 */
        "movl %eax, -0xa4(%ebp)\n"
        "movss 0x24(%ebx), %xmm0\n"
        "movss %xmm0, -0x94(%ebp)\n"
        "leal 0x28(%ebx), %eax\n" /* line 201 */
        "movl %eax, -0xa0(%ebp)\n"
        "movss 0x28(%ebx), %xmm0\n"
        "movss %xmm0, -0x98(%ebp)\n"
        "movl 0x10(%ebp), %ecx\n" /* line 324 | gravity */
        "movl 0xc(%ebp), %edx\n" /* pml */
        "movl 8(%ebp), %eax\n" /* pm */
        "calll PM_SlideMove\n"
        "movl %eax, -0xb8(%ebp)\n" /* iBumps */
        "testb $1, 0xc(%ebx)\n" /* line 327 | ps */
        "je .Lf9e3a0_0009e6f5\n"
        "movl $0x41200000, -0x1c(%ebp)\n" /* line 328 | fStepSize */
        "cmpl $0x3ff, 0x60(%ebx)\n" /* line 332 | ps */
        "je .Lf9e3a0_0009e709\n"
        ".Lf9e3a0_0009e469:\n"
        "movl $0, -0xb0(%ebp)\n" /* line 350 | jumping */
        ".Lf9e3a0_0009e473:\n"
        "movss (%esi), %xmm1\n" /* line 199 | ps */
        "movss %xmm1, -0x34(%ebp)\n" /* down_o */
        "movl -0xac(%ebp), %eax\n" /* line 200 */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "movl -0xa8(%ebp), %edx\n" /* line 201 */
        "movl (%edx), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movss (%edi), %xmm2\n" /* line 199 */
        "movss %xmm2, -0x84(%ebp)\n"
        "movl -0xa4(%ebp), %eax\n" /* line 200 */
        "movss (%eax), %xmm2\n"
        "movss %xmm2, -0x88(%ebp)\n"
        "movl -0xa0(%ebp), %eax\n" /* line 201 */
        "movss (%eax), %xmm2\n"
        "movss %xmm2, -0x8c(%ebp)\n"
        "movss -0x28(%ebp), %xmm2\n" /* line 65 | start_o */
        "subss %xmm2, %xmm1\n"
        "movss %xmm1, -0x7c(%ebp)\n"
        "subss -0x24(%ebp), %xmm0\n" /* line 66 */
        "movss %xmm0, -0x80(%ebp)\n"
        "movl -0xb8(%ebp), %edx\n" /* line 360 | iBumps */
        "testl %edx, %edx\n"
        "jne .Lf9e3a0_0009e5fa\n"
        ".Lf9e3a0_0009e4ec:\n"
        "pxor %xmm2, %xmm2\n" /* line 372 */
        ".Lf9e3a0_0009e4f0:\n"
        "movl -0xb4(%ebp), %eax\n" /* line 388 | bHadGround */
        "testl %eax, %eax\n"
        "jne .Lf9e3a0_0009e509\n"
        "ucomiss 0x2ed5e8, %xmm2\n" /* 0.0f */
        "jp .Lf9e3a0_0009e509\n"
        "je .Lf9e3a0_0009e7c8\n"
        ".Lf9e3a0_0009e509:\n"
        "movl (%esi), %eax\n" /* line 199 | ps */
        "movl %eax, -0x4c(%ebp)\n" /* down */
        "movl -0xac(%ebp), %edx\n" /* line 200 */
        "movl (%edx), %eax\n"
        "movl %eax, -0x48(%ebp)\n"
        "movl -0xa8(%ebp), %eax\n" /* line 201 */
        "movss (%eax), %xmm0\n"
        "subss %xmm2, %xmm0\n" /* line 392 */
        "movss %xmm0, -0x44(%ebp)\n"
        "movl -0xb4(%ebp), %eax\n" /* line 393 | bHadGround */
        "testl %eax, %eax\n"
        "je .Lf9e3a0_0009e543\n"
        "subss 0x2ed728, %xmm0\n" /* line 394 | 9.0f */
        "movss %xmm0, -0x44(%ebp)\n"
        ".Lf9e3a0_0009e543:\n"
        "movl 8(%ebp), %edx\n" /* line 395 | pm */
        "movl 0x3c(%edx), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl 0xcc(%ebx), %eax\n" /* ps */
        "movl %eax, 0x18(%esp)\n"
        "leal -0x4c(%ebp), %eax\n" /* down */
        "movl %eax, 0x14(%esp)\n"
        "movl %edx, %eax\n"
        "addl $0xd0, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "subl $0xc, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* ps */
        "leal -0x70(%ebp), %eax\n" /* trace */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "movss %xmm2, -0xe8(%ebp)\n"
        "calll PM_playerTrace\n"
        "cmpw $0x3f, -0x54(%ebp)\n" /* line 397 */
        "movss -0xe8(%ebp), %xmm2\n"
        "ja .Lf9e3a0_0009e9d3\n"
        "movl -0x34(%ebp), %eax\n" /* line 199 | down_o */
        "movl %eax, (%esi)\n" /* ps */
        "movl -0x30(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%esi)\n" /* ps */
        "movl -0x2c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%esi)\n" /* ps */
        "movss -0x84(%ebp), %xmm0\n" /* line 199 */
        "movss %xmm0, (%edi)\n"
        "movss -0x88(%ebp), %xmm2\n" /* line 200 */
        "movss %xmm2, 4(%edi)\n"
        "movss -0x8c(%ebp), %xmm0\n" /* line 201 */
        "movss %xmm0, 8(%edi)\n"
        /* } scope */
        ".Lf9e3a0_0009e5d5:\n"
        "addl $0x11c, %esp\n" /* line 507 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9e3a0_0009e5e0:\n"
        "testl $0x80000, %eax\n" /* line 316 */
        "jne .Lf9e3a0_0009e9b1\n"
        ".Lf9e3a0_0009e5eb:\n"
        "movl $0, -0xb4(%ebp)\n" /* line 317 | bHadGround */
        "jmp .Lf9e3a0_0009e3d4\n"
        ".Lf9e3a0_0009e5fa:\n"
        "movss %xmm2, -0x40(%ebp)\n" /* line 199 | up */
        "movl -0x24(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x3c(%ebp)\n"
        "movl -0x20(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x38(%ebp)\n"
        "movss 0x2ed5d0, %xmm1\n" /* line 363 | 1.0f */
        "movss -0x1c(%ebp), %xmm0\n" /* fStepSize */
        "addss %xmm1, %xmm0\n"
        "addss -0x38(%ebp), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 366 | pm */
        "movl 0x3c(%edx), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl 0xcc(%ebx), %eax\n" /* ps */
        "movl %eax, 0x18(%esp)\n"
        "leal -0x40(%ebp), %eax\n" /* up */
        "movl %eax, 0x14(%esp)\n"
        "movl %edx, %eax\n"
        "addl $0xd0, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "subl $0xc, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* start_o */
        "movl %eax, 8(%esp)\n"
        "leal -0x70(%ebp), %eax\n" /* trace */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "movss %xmm1, -0xd8(%ebp)\n"
        "calll PM_playerTrace\n"
        "movss -0xd8(%ebp), %xmm1\n" /* line 369 */
        "movss -0x1c(%ebp), %xmm2\n" /* fStepSize */
        "addss %xmm1, %xmm2\n"
        "mulss -0x70(%ebp), %xmm2\n" /* trace */
        "subss %xmm1, %xmm2\n"
        "ucomiss %xmm2, %xmm1\n" /* line 372 */
        "ja .Lf9e3a0_0009e4ec\n"
        "movaps %xmm2, %xmm0\n" /* line 379 | z */
        "addss -0x20(%ebp), %xmm0\n" /* z */
        "movl -0x3c(%ebp), %edx\n" /* y */
        /* { scope 2 */
        "movl -0x40(%ebp), %eax\n" /* line 191 | up */
        "movl %eax, (%esi)\n" /* ps */
        "movl %edx, 4(%esi)\n" /* line 192 | ps */
        "movss %xmm0, 8(%esi)\n" /* line 193 | ps */
        /* } scope */
        "movss -0x90(%ebp), %xmm0\n" /* line 199 */
        "movss %xmm0, (%edi)\n"
        "movss -0x94(%ebp), %xmm0\n" /* line 200 */
        "movss %xmm0, 4(%edi)\n"
        "movss -0x98(%ebp), %xmm0\n" /* line 201 */
        "movss %xmm0, 8(%edi)\n"
        "movl 0x10(%ebp), %ecx\n" /* line 383 | gravity */
        "movl 0xc(%ebp), %edx\n" /* pml */
        "movl 8(%ebp), %eax\n" /* pm */
        "movss %xmm2, -0xe8(%ebp)\n"
        "calll PM_SlideMove\n"
        "movss -0xe8(%ebp), %xmm2\n"
        "jmp .Lf9e3a0_0009e4f0\n"
        ".Lf9e3a0_0009e6f5:\n"
        "movl $0x41900000, -0x1c(%ebp)\n" /* line 330 | fStepSize */
        "cmpl $0x3ff, 0x60(%ebx)\n" /* line 332 | ps */
        "jne .Lf9e3a0_0009e469\n"
        ".Lf9e3a0_0009e709:\n"
        "movl 0xc(%ebx), %eax\n" /* line 334 | ps */
        "testl $0x80000, %eax\n"
        "jne .Lf9e3a0_0009eac4\n"
        ".Lf9e3a0_0009e717:\n"
        "movl -0xb8(%ebp), %ecx\n" /* line 338 | iBumps */
        "testl %ecx, %ecx\n"
        "jne .Lf9e3a0_0009ea7a\n"
        ".Lf9e3a0_0009e725:\n"
        "testb $0x20, %al\n" /* line 350 */
        "je .Lf9e3a0_0009e5d5\n"
        "movss 0x28(%ebx), %xmm0\n" /* ps */
        "ucomiss 0x2ed5e8, %xmm0\n" /* 0.0f */
        "ja .Lf9e3a0_0009e469\n"
        "jmp .Lf9e3a0_0009e5d5\n"
        ".Lf9e3a0_0009e744:\n"
        "jp .Lf9e3a0_0009e9e5\n" /* line 405 */
        "movss 0x2ed6f4, %xmm0\n" /* line 407 | 0.30000001192092896f */
        "ucomiss -0x64(%ebp), %xmm0\n"
        "ja .Lf9e3a0_0009ecac\n"
        "movss (%esi), %xmm1\n" /* line 1203 | ps */
        "movss -0x4c(%ebp), %xmm0\n" /* down */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%esi)\n" /* ps */
        "movl -0xac(%ebp), %eax\n" /* line 1204 */
        "movss (%eax), %xmm1\n"
        "movss -0x48(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%esi)\n" /* ps */
        "movl -0xa8(%ebp), %edx\n" /* line 1205 */
        "movss (%edx), %xmm1\n"
        "movss -0x44(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "movss %xmm1, 8(%esi)\n" /* ps */
        "movl %edi, 8(%esp)\n" /* line 414 */
        "leal -0x6c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PM_ClipVelocity\n"
        ".Lf9e3a0_0009e7c8:\n"
        "movl -0xa4(%ebp), %eax\n" /* line 114 */
        "movss (%eax), %xmm2\n"
        "movss (%esi), %xmm1\n" /* line 429 | ps */
        "subss -0x28(%ebp), %xmm1\n" /* start_o */
        "mulss (%edi), %xmm1\n"
        "movl -0xac(%ebp), %edx\n"
        "movss (%edx), %xmm0\n"
        "subss -0x24(%ebp), %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x7c(%ebp), %xmm0\n"
        "mulss (%edi), %xmm0\n"
        "mulss -0x80(%ebp), %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -0x7c(%ebp)\n"
        "addss 0x2ed658, %xmm0\n" /* 0.0010000000474974513f */
        "ucomiss %xmm1, %xmm0\n"
        "jae .Lf9e3a0_0009ea13\n"
        "movl -0xb0(%ebp), %eax\n" /* jumping */
        "testl %eax, %eax\n"
        "jne .Lf9e3a0_0009ea07\n"
        ".Lf9e3a0_0009e82c:\n"
        "movl -0xb4(%ebp), %eax\n" /* line 459 | bHadGround */
        "testl %eax, %eax\n"
        "je .Lf9e3a0_0009e5d5\n"
        "cmpl $5, 4(%ebx)\n" /* ps */
        "jg .Lf9e3a0_0009e5d5\n"
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 26 | pm */
        "movl (%eax), %esi\n" /* ps */
        "testb $1, 0xc(%esi)\n" /* line 29 | ps */
        "jne .Lf9e3a0_0009ebcf\n"
        /* } scope */
        ".Lf9e3a0_0009e853:\n"
        "movss 0x1c(%ebx), %xmm1\n" /* line 462 | ps */
        "subss -0x2c(%ebp), %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "andps 0x2f1b90, %xmm0\n"
        "ucomiss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "jbe .Lf9e3a0_0009e5d5\n"
        /* { scope 2 */
        "addss 0x2ed5d8, %xmm1\n" /* line 428 | 0.5f */
        "movss %xmm1, (%esp)\n"
        "calll floorf\n"
        "fstps -0xbc(%ebp)\n"
        "cvttss2si -0xbc(%ebp), %eax\n"
        "testl %eax, %eax\n" /* line 468 */
        "je .Lf9e3a0_0009e5d5\n"
        /* { scope 3 */
        "cmpl $-0x10, %eax\n" /* line 475 */
        "jge .Lf9e3a0_0009ece8\n"
        "movl $0x70, %esi\n" /* ps */
        ".Lf9e3a0_0009e8aa:\n"
        "movl %ebx, 8(%esp)\n" /* line 480 | ps */
        "movl %esi, 4(%esp)\n" /* ps */
        "movl $0x8f, (%esp)\n"
        "calll BG_AddPredictableEventToPlayerstate\n"
        "movss 0x1c(%ebx), %xmm0\n" /* line 484 | ps */
        "subss -0x20(%ebp), %xmm0\n"
        "andps 0x2f1b90, %xmm0\n"
        "divss -0x1c(%ebp), %xmm0\n" /* fStepSize */
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "subss %xmm0, %xmm1\n"
        "mulss 0x2ed7f0, %xmm1\n" /* 0.800000011920929f */
        "addss 0x2ed7f4, %xmm1\n" /* 0.19999998807907104f */
        "movaps %xmm1, %xmm0\n" /* line 272 */
        "mulss (%edi), %xmm0\n"
        "movss %xmm0, (%edi)\n"
        "movaps %xmm1, %xmm0\n" /* line 273 */
        "movl -0xa4(%ebp), %eax\n"
        "mulss (%eax), %xmm0\n"
        "movss %xmm0, 4(%edi)\n"
        "movl -0xa0(%ebp), %edx\n" /* line 274 */
        "mulss (%edx), %xmm1\n"
        "movss %xmm1, 8(%edi)\n"
        "addl $-0x80, %esi\n" /* line 489 | ps */
        "js .Lf9e3a0_0009ed0a\n"
        ".Lf9e3a0_0009e925:\n"
        "cmpl $3, %esi\n" /* ps */
        "jle .Lf9e3a0_0009e5d5\n"
        "cmpl $0x3ff, 0x60(%ebx)\n" /* ps */
        "je .Lf9e3a0_0009e5d5\n"
        "movl 8(%ebp), %eax\n" /* pm */
        "movl %eax, (%esp)\n"
        "calll PM_ShouldMakeFootsteps\n"
        "testl %eax, %eax\n"
        "je .Lf9e3a0_0009e5d5\n"
        /* { scope 4 */
        "movl %esi, %eax\n" /* line 494 | ps */
        "sarl $1, %eax\n"
        "cmpl $4, %eax\n" /* line 495 */
        "jle .Lf9e3a0_0009ed11\n"
        "movss 0x2ed608, %xmm1\n" /* 4.0f */
        ".Lf9e3a0_0009e963:\n"
        "movl 8(%ebx), %edx\n" /* line 500 | ps */
        "mulss 0x2ed7f8, %xmm1\n" /* line 501 | 1.25f */
        "addss 0x2ed7fc, %xmm1\n" /* 7.0f */
        "cvtsi2ssl %edx, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "cvttss2si %xmm1, %eax\n"
        "andl $0xff, %eax\n"
        "movl %eax, 8(%ebx)\n" /* ps */
        "movl $1, 0x10(%esp)\n" /* line 502 */
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* pml */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* pm */
        "movl %eax, (%esp)\n"
        "calll PM_FootstepEvent\n"
        "jmp .Lf9e3a0_0009e5d5\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf9e3a0_0009e9b1:\n"
        "movl 0x10(%ebx), %ecx\n" /* line 316 | ps */
        "testl %ecx, %ecx\n"
        "je .Lf9e3a0_0009e5eb\n"
        ".Lf9e3a0_0009e9bc:\n"
        "movl %ebx, (%esp)\n" /* line 317 | ps */
        "calll Jump_ClearState\n"
        "movl $0, -0xb4(%ebp)\n" /* bHadGround */
        "jmp .Lf9e3a0_0009e3d4\n"
        ".Lf9e3a0_0009e9d3:\n"
        "movss -0x70(%ebp), %xmm3\n" /* line 405 | trace */
        "ucomiss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "jb .Lf9e3a0_0009e744\n"
        ".Lf9e3a0_0009e9e5:\n"
        "ucomiss 0x2ed5e8, %xmm2\n" /* line 416 | 0.0f */
        "jp .Lf9e3a0_0009e9f4\n"
        "je .Lf9e3a0_0009e7c8\n"
        ".Lf9e3a0_0009e9f4:\n"
        "movss 0x1c(%ebx), %xmm0\n" /* line 419 | ps */
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, 0x1c(%ebx)\n" /* ps */
        "jmp .Lf9e3a0_0009e7c8\n"
        ".Lf9e3a0_0009ea07:\n"
        "movl %ebx, (%esp)\n" /* line 429 | ps */
        "calll Jump_IsPlayerAboveMax\n"
        "testb %al, %al\n"
        "je .Lf9e3a0_0009ea66\n"
        ".Lf9e3a0_0009ea13:\n"
        "movl -0x34(%ebp), %eax\n" /* line 199 | down_o */
        "movl %eax, (%esi)\n" /* ps */
        "movl -0x30(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%esi)\n" /* ps */
        "movl -0x2c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%esi)\n" /* ps */
        "movss -0x84(%ebp), %xmm2\n" /* line 199 */
        "movss %xmm2, (%edi)\n"
        "movss -0x88(%ebp), %xmm0\n" /* line 200 */
        "movss %xmm0, 4(%edi)\n"
        "movss -0x8c(%ebp), %xmm2\n" /* line 201 */
        "movss %xmm2, 8(%edi)\n"
        "movl -0xb4(%ebp), %eax\n" /* line 436 | bHadGround */
        "testl %eax, %eax\n"
        "jne .Lf9e3a0_0009eadf\n"
        ".Lf9e3a0_0009ea58:\n"
        "movl -0xb0(%ebp), %eax\n" /* line 455 | jumping */
        "testl %eax, %eax\n"
        "je .Lf9e3a0_0009e82c\n"
        ".Lf9e3a0_0009ea66:\n"
        "leal -0x34(%ebp), %eax\n" /* line 456 | down_o */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll Jump_ClampVelocity\n"
        "jmp .Lf9e3a0_0009e82c\n"
        ".Lf9e3a0_0009ea7a:\n"
        "testl $0x80000, %eax\n" /* line 338 */
        "je .Lf9e3a0_0009e725\n"
        "leal -0x1c(%ebp), %eax\n" /* line 340 | fStepSize */
        "movl %eax, 8(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* start_o */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll Jump_GetStepHeight\n"
        "testb %al, %al\n"
        "je .Lf9e3a0_0009ecf7\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 342 | 1.0f */
        "ucomiss -0x1c(%ebp), %xmm0\n" /* fStepSize */
        "ja .Lf9e3a0_0009e5d5\n"
        "movl $1, -0xb0(%ebp)\n" /* line 343 | jumping */
        "jmp .Lf9e3a0_0009e473\n"
        ".Lf9e3a0_0009eac4:\n"
        "movl 0x10(%ebx), %edx\n" /* line 334 | ps */
        "testl %edx, %edx\n"
        "je .Lf9e3a0_0009e717\n"
        "movl %ebx, (%esp)\n" /* line 335 | ps */
        "calll Jump_ClearState\n"
        "movl 0xc(%ebx), %eax\n" /* ps */
        "jmp .Lf9e3a0_0009e717\n"
        ".Lf9e3a0_0009eadf:\n"
        "movl (%esi), %eax\n" /* line 199 | ps */
        "movl %eax, -0x4c(%ebp)\n" /* down */
        "movl -0xac(%ebp), %edx\n" /* line 200 */
        "movl (%edx), %eax\n"
        "movl %eax, -0x48(%ebp)\n"
        "movl -0xa8(%ebp), %eax\n" /* line 201 */
        "movss (%eax), %xmm0\n"
        "subss 0x2ed728, %xmm0\n" /* line 439 | 9.0f */
        "movss %xmm0, -0x44(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 440 | pm */
        "movl 0x3c(%edx), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl 0xcc(%ebx), %eax\n" /* ps */
        "movl %eax, 0x18(%esp)\n"
        "leal -0x4c(%ebp), %eax\n" /* down */
        "movl %eax, 0x14(%esp)\n"
        "movl %edx, %eax\n"
        "addl $0xd0, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "subl $0xc, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* ps */
        "leal -0x70(%ebp), %eax\n" /* trace */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll PM_playerTrace\n"
        "movss -0x70(%ebp), %xmm4\n" /* line 443 | trace */
        "ucomiss 0x2ed5d0, %xmm4\n" /* 1.0f */
        "jae .Lf9e3a0_0009ea58\n"
        "jp .Lf9e3a0_0009ea58\n"
        "movss (%esi), %xmm2\n" /* line 1203 | ps */
        "movl -0xac(%ebp), %eax\n" /* line 1204 */
        "movss (%eax), %xmm3\n"
        "movss -0x48(%ebp), %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "movl -0xa8(%ebp), %edx\n" /* line 1205 */
        "movss (%edx), %xmm1\n"
        "movss -0x44(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm4, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x4c(%ebp), %xmm0\n" /* line 199 | down */
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm4\n"
        "addss %xmm4, %xmm2\n"
        "movss %xmm2, (%esi)\n" /* ps */
        "movss %xmm3, 4(%esi)\n" /* line 200 | ps */
        "movss %xmm1, 8(%esi)\n" /* line 201 | ps */
        "movl %edi, 8(%esp)\n" /* line 449 */
        "leal -0x6c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PM_ClipVelocity\n"
        "jmp .Lf9e3a0_0009ea58\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf9e3a0_0009ebcf:\n"
        "leal 0x14(%esi), %edx\n" /* line 33 | ps */
        "movl %edx, -0x9c(%ebp)\n"
        "movl $0x42840000, 0x34(%esp)\n"
        "movl $0, 0x30(%esp)\n"
        "movzbl 0xe4(%eax), %eax\n"
        "movl %eax, 0x2c(%esp)\n"
        "movl $0, 0x28(%esp)\n"
        "movl $1, 0x24(%esp)\n"
        "movl $1, 0x20(%esp)\n"
        "leal 0x5b0(%esi), %eax\n" /* ps */
        "movl %eax, 0x1c(%esp)\n"
        "leal 0x5ac(%esi), %eax\n" /* ps */
        "movl %eax, 0x18(%esp)\n"
        "leal 0x5a8(%esi), %eax\n" /* ps */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x584(%esi), %eax\n" /* ps */
        "movl %eax, 0x10(%esp)\n"
        "movl $0x41f00000, 0xc(%esp)\n"
        "movl 0x578(%esi), %eax\n" /* ps */
        "movl %eax, 8(%esp)\n"
        "movl -0x9c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xcc(%esi), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "calll BG_CheckProne\n"
        "testl %eax, %eax\n" /* line 35 */
        "jne .Lf9e3a0_0009e853\n"
        "movl -0x28(%ebp), %eax\n" /* line 199 | start_o */
        "movl %eax, 0x14(%esi)\n" /* ps */
        "movl -0x24(%ebp), %eax\n" /* line 200 */
        "movl -0x9c(%ebp), %edx\n"
        "movl %eax, 4(%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "leal 0x20(%esi), %eax\n" /* line 38 | ps, to */
        /* { scope 4 */
        "movss -0x90(%ebp), %xmm0\n" /* line 199 */
        "movss %xmm0, 0x20(%esi)\n" /* ps */
        "movss -0x94(%ebp), %xmm2\n" /* line 200 */
        "movss %xmm2, 4(%eax)\n"
        "movss -0x98(%ebp), %xmm0\n" /* line 201 */
        "movss %xmm0, 8(%eax)\n"
        "jmp .Lf9e3a0_0009e5d5\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf9e3a0_0009ecac:\n"
        "movl -0x34(%ebp), %eax\n" /* line 199 | down_o */
        "movl %eax, (%esi)\n" /* ps */
        "movl -0x30(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%esi)\n" /* ps */
        "movl -0x2c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%esi)\n" /* ps */
        "movss -0x84(%ebp), %xmm2\n" /* line 199 */
        "movss %xmm2, (%edi)\n"
        "movss -0x88(%ebp), %xmm0\n" /* line 200 */
        "movss %xmm0, 4(%edi)\n"
        "movss -0x8c(%ebp), %xmm2\n" /* line 201 */
        "movss %xmm2, 8(%edi)\n"
        "jmp .Lf9e3a0_0009e5d5\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf9e3a0_0009ece8:\n"
        "cmpl $0x18, %eax\n" /* line 477 */
        "jle .Lf9e3a0_0009ecff\n"
        "movl $0x98, %esi\n" /* ps */
        "jmp .Lf9e3a0_0009e8aa\n"
        ".Lf9e3a0_0009ecf7:\n"
        "movl 0xc(%ebx), %eax\n" /* ps */
        "jmp .Lf9e3a0_0009e725\n"
        ".Lf9e3a0_0009ecff:\n"
        "leal 0x80(%eax), %esi\n" /* ps */
        "jmp .Lf9e3a0_0009e8aa\n"
        ".Lf9e3a0_0009ed0a:\n"
        "negl %esi\n" /* line 489 | ps */
        "jmp .Lf9e3a0_0009e925\n"
        /* { scope 4 */
        ".Lf9e3a0_0009ed11:\n"
        "cvtsi2ssl %eax, %xmm1\n" /* line 495 */
        "jmp .Lf9e3a0_0009e963\n"
    );
}

