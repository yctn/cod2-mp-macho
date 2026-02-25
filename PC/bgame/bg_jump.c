/* ASM dump from: bg_jump.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/bgame/bg_jump.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

static const dvar_t *jump_height; /* 0x4ed280 */
static const dvar_t *jump_stepSize; /* 0x4ed290 */
static const dvar_t *jump_slowdownEnable; /* 0x4ed288 */
static const dvar_t *jump_ladderPushVel; /* 0x4ed28c */
static const dvar_t *jump_spreadAdd; /* 0x4ed284 */

void Jump_RegisterDvars(void);
void Jump_ClearState(playerState_t *ps);
Bool Jump_GetStepHeight(playerState_t *ps, const vec_t *origin, float *stepSize);
Bool Jump_IsPlayerAboveMax(playerState_t *ps);
void Jump_ActivateSlowdown(playerState_t *ps);
void Jump_ApplySlowdown(playerState_t *ps);
float Jump_ReduceFriction(playerState_t *ps);
Bool Jump_Check(pmove_t *pm, pml_t *pml);
void Jump_ClampVelocity(playerState_t *ps, const vec_t *origin);

/* line 45 */
__attribute__((naked))
void Jump_RegisterDvars(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 45 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 57 */
        "movl $0x43000000, %edi\n"
        "movl %edi, 0xc(%esp)\n"
        "xorl %ebx, %ebx\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x421c0000, 4(%esp)\n"
        "movl $0x21df50, (%esp)\n" /* "jump_height" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, jump_height\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 58 */
        "movl $0x42800000, %esi\n"
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x41900000, 4(%esp)\n"
        "movl $0x21df5c, (%esp)\n" /* "jump_stepSize" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, jump_stepSize\n"
        "movl $0x1180, 8(%esp)\n" /* line 60 */
        "movl $1, 4(%esp)\n"
        "movl $0x21df6c, (%esp)\n" /* "jump_slowdownEnable" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, jump_slowdownEnable\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 64 */
        "movl $0x44800000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x21df80, (%esp)\n" /* "jump_ladderPushVel" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, jump_ladderPushVel\n"
        "movl $0x1180, 0x10(%esp)\n" /* line 65 */
        "movl $0x44000000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl $0x21df94, (%esp)\n" /* "jump_spreadAdd" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, jump_spreadAdd\n"
        "addl $0x2c, %esp\n" /* line 66 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 72 */
__attribute__((naked))
void Jump_ClearState(playerState_t *ps)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 72 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* ps */
        "andl $0xfff7ffff, 0xc(%eax)\n" /* line 74 */
        "movl $0, 0x74(%eax)\n" /* line 75 */
        "popl %ebp\n" /* line 76 */
        "retl\n"
    );
}

/* line 82 */
__attribute__((naked))
Bool Jump_GetStepHeight(playerState_t *ps, const vec_t *origin, float *stepSize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 82 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* ps */
        "movl 0xc(%ebp), %ecx\n" /* origin */
        "movl 0x10(%ebp), %esi\n" /* stepSize */
        "movl jump_height, %edx\n" /* line 88 */
        "movss 0x74(%ebx), %xmm0\n" /* ps */
        "addss 8(%edx), %xmm0\n"
        "ucomiss 8(%ecx), %xmm0\n"
        "jbe .Lf9d4ec_0009d547\n"
        "movl jump_stepSize, %eax\n" /* line 91 */
        "movss 8(%eax), %xmm0\n"
        "movss %xmm0, (%esi)\n" /* stepSize */
        "movss 8(%ecx), %xmm2\n" /* line 93 */
        "movss 0x74(%ebx), %xmm1\n" /* ps */
        "addss 8(%edx), %xmm1\n"
        "addss %xmm2, %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf9d4ec_0009d53e\n"
        "subss %xmm2, %xmm1\n" /* line 94 */
        "movss %xmm1, (%esi)\n" /* stepSize */
        ".Lf9d4ec_0009d53e:\n"
        "movl $1, %eax\n"
        "popl %ebx\n" /* line 100 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf9d4ec_0009d547:\n"
        "xorl %eax, %eax\n" /* line 88 */
        "popl %ebx\n" /* line 100 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 106 */
__attribute__((naked))
Bool Jump_IsPlayerAboveMax(playerState_t *ps)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 106 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* ps */
        "movss 0x74(%edx), %xmm0\n"
        "movl jump_height, %eax\n"
        "addss 8(%eax), %xmm0\n"
        "movss 0x1c(%edx), %xmm1\n"
        "xorl %eax, %eax\n"
        "ucomiss %xmm0, %xmm1\n"
        "setae %al\n"
        "popl %ebp\n" /* line 111 */
        "retl\n"
    );
}

/* line 117 */
__attribute__((naked))
void Jump_ActivateSlowdown(playerState_t *ps)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 117 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* ps */
        "movl 0x10(%eax), %edx\n" /* line 119 */
        "testl %edx, %edx\n"
        "jne .Lf9d572_0009d58d\n"
        "orl $0x80000, 0xc(%eax)\n" /* line 121 */
        "movl $0x708, 0x10(%eax)\n" /* line 122 */
        ".Lf9d572_0009d58d:\n"
        "popl %ebp\n" /* line 124 */
        "retl\n"
    );
}

/* line 130 */
__attribute__((naked))
void Jump_ApplySlowdown(playerState_t *ps)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 130 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* ps */
        /* { scope 1 */
        "movl 0x10(%edx), %eax\n" /* line 138 */
        "cmpl $0x708, %eax\n"
        "jle .Lf9d590_0009d5f2\n"
        "andl $0xfff7ffff, 0xc(%edx)\n" /* line 74 */
        "movl $0, 0x74(%edx)\n" /* line 75 */
        "movss 0x2ed768, %xmm1\n" /* 0.6499999761581421f */
        ".Lf9d590_0009d5b6:\n"
        "movl jump_slowdownEnable, %eax\n" /* line 157 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf9d590_0009d5c9\n"
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        ".Lf9d590_0009d5c9:\n"
        "leal 0x20(%edx), %eax\n" /* line 160 | result */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 272 */
        "mulss 0x20(%edx), %xmm0\n"
        "movss %xmm0, 0x20(%edx)\n"
        "movaps %xmm1, %xmm0\n" /* line 273 */
        "mulss 4(%eax), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "mulss 8(%eax), %xmm1\n" /* line 274 */
        "movss %xmm1, 8(%eax)\n"
        /* } scope */
        /* } scope */
        "popl %ebp\n" /* line 161 */
        "retl\n"
        /* { scope 1 */
        ".Lf9d590_0009d5f2:\n"
        "testl %eax, %eax\n" /* line 143 */
        "jne .Lf9d590_0009d61a\n"
        "movss 0x2ed6c8, %xmm0\n" /* line 145 | 18.0f */
        "addss 0x74(%edx), %xmm0\n"
        "ucomiss 0x1c(%edx), %xmm0\n"
        "ja .Lf9d590_0009d624\n"
        "movl $0x4b0, 0x10(%edx)\n" /* line 152 */
        "movss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "jmp .Lf9d590_0009d5b6\n"
        ".Lf9d590_0009d61a:\n"
        "movss 0x2ed5d0, %xmm1\n" /* line 143 | 1.0f */
        "jmp .Lf9d590_0009d5b6\n"
        ".Lf9d590_0009d624:\n"
        "movl $0x708, 0x10(%edx)\n" /* line 147 */
        "movss 0x2ed768, %xmm1\n" /* 0.6499999761581421f */
        "jmp .Lf9d590_0009d5b6\n"
    );
}

/* line 185 */
__attribute__((naked))
float Jump_ReduceFriction(playerState_t *ps)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 185 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %eax\n" /* ps */
        /* { scope 1 */
        "movl 0x10(%eax), %edx\n" /* line 191 */
        "cmpl $0x708, %edx\n"
        "jg .Lf9d636_0009d683\n"
        "movl jump_slowdownEnable, %eax\n" /* line 172 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf9d636_0009d691\n"
        "cmpl $0x6a3, %edx\n" /* line 175 */
        "jg .Lf9d636_0009d6a3\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 178 */
        "mulss 0x2ed600, %xmm0\n" /* 1.5f */
        "mulss 0x2ed7ec, %xmm0\n" /* 0.0005882352706976235f */
        "addss 0x2ed5d0, %xmm0\n" /* 1.0f */
        /* } scope */
        "movss %xmm0, -4(%ebp)\n" /* line 202 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9d636_0009d683:\n"
        "andl $0xfff7ffff, 0xc(%eax)\n" /* line 74 */
        "movl $0, 0x74(%eax)\n" /* line 75 */
        ".Lf9d636_0009d691:\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        /* } scope */
        "movss %xmm0, -4(%ebp)\n" /* line 202 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9d636_0009d6a3:\n"
        "movss 0x2ed6c0, %xmm0\n" /* line 175 | 2.5f */
        /* } scope */
        "movss %xmm0, -4(%ebp)\n" /* line 202 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 362 */
__attribute__((naked))
Bool Jump_Check(pmove_t *pm, pml_t *pml)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 362 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %esi\n" /* pm */
        /* { scope 1: pushOffDir, flatForward */
        "movl (%esi), %ebx\n" /* line 368 | pm, ps */
        "movl 4(%esi), %eax\n" /* line 372 | pm */
        "subl 0x70(%ebx), %eax\n" /* ps */
        "cmpl $0x1f3, %eax\n"
        "jle .Lf9d6b6_0009d6e2\n"
        "movl 0xc(%ebx), %eax\n" /* line 376 | ps */
        "testb $0x10, %ah\n"
        "jne .Lf9d6b6_0009d6e2\n"
        "testb $4, %al\n" /* line 379 */
        "jne .Lf9d6b6_0009d6e2\n"
        "cmpl $5, 4(%ebx)\n" /* line 382 | ps */
        "jle .Lf9d6b6_0009d6eb\n"
        ".Lf9d6b6_0009d6e2:\n"
        "xorl %eax, %eax\n" /* line 412 */
        /* } scope */
        ".Lf9d6b6_0009d6e4:\n"
        "addl $0x30, %esp\n" /* line 416 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: pushOffDir, flatForward */
        ".Lf9d6b6_0009d6eb:\n"
        "movl %ebx, (%esp)\n" /* line 386 | ps */
        "calll PM_GetEffectiveStance\n"
        "testl %eax, %eax\n"
        "jne .Lf9d6b6_0009d6e2\n"
        "movl 8(%esi), %eax\n" /* line 389 | pm */
        "testb $4, %ah\n"
        "je .Lf9d6b6_0009d6e2\n"
        "testb $4, 0x25(%esi)\n" /* line 393 | pm */
        "jne .Lf9d6b6_0009d80d\n"
        /* { scope 2 */
        "movl (%esi), %edx\n" /* line 262 */
        "movl jump_height, %eax\n" /* line 265 */
        "movss 8(%eax), %xmm1\n"
        "addss %xmm1, %xmm1\n"
        "cvtsi2ssl 0x48(%edx), %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "testb $8, 0xe(%edx)\n" /* line 267 */
        "je .Lf9d6b6_0009d74e\n"
        "movl 0x10(%edx), %ecx\n" /* line 269 */
        "cmpl $0x708, %ecx\n"
        "jg .Lf9d6b6_0009d74e\n"
        /* { scope 3 */
        "movl jump_slowdownEnable, %eax\n" /* line 243 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf9d6b6_0009d90f\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        /* } scope */
        ".Lf9d6b6_0009d74a:\n"
        "divss %xmm0, %xmm1\n" /* line 274 */
        ".Lf9d6b6_0009d74e:\n"
        "movl 0xc(%ebp), %eax\n" /* line 278 | pml */
        "movl $0, 0x30(%eax)\n"
        "movl $0, 0x34(%eax)\n" /* line 280 */
        "movl $0, 0x2c(%eax)\n" /* line 282 */
        "movl $0x3ff, 0x60(%edx)\n" /* line 284 */
        "movl 4(%esi), %eax\n" /* line 285 */
        "movl %eax, 0x70(%edx)\n"
        "movl 0x1c(%edx), %eax\n" /* line 286 */
        "movl %eax, 0x74(%edx)\n"
        "orl $0x80000, 0xc(%edx)\n" /* line 287 */
        "movl $0, 0x10(%edx)\n" /* line 288 */
        "sqrtss %xmm1, %xmm0\n" /* line 81 */
        "movss %xmm0, 0x28(%edx)\n"
        "movss 0x5d4(%edx), %xmm0\n" /* line 292 */
        "movl jump_spreadAdd, %eax\n"
        "addss 8(%eax), %xmm0\n"
        "movss %xmm0, 0x5d4(%edx)\n"
        "ucomiss 0x2ed5d4, %xmm0\n" /* line 293 | 255.0f */
        "jbe .Lf9d6b6_0009d7bd\n"
        "movl $0x437f0000, 0x5d4(%edx)\n" /* line 294 */
        /* } scope */
        /* { scope 2 */
        ".Lf9d6b6_0009d7bd:\n"
        "testb $0x20, 0xc(%ebx)\n" /* line 344 */
        "je .Lf9d6b6_0009d81a\n"
        "movl $0x5b, 4(%esp)\n" /* line 346 */
        "movl %ebx, (%esp)\n"
        "calll PM_AddEvent\n"
        /* } scope */
        ".Lf9d6b6_0009d7d3:\n"
        "testb $0x20, 0xc(%ebx)\n" /* line 405 | ps */
        "jne .Lf9d6b6_0009d83a\n"
        ".Lf9d6b6_0009d7d9:\n"
        "cmpb $0, 0x1c(%esi)\n" /* line 409 | pm */
        "js .Lf9d6b6_0009d8e5\n"
        "movl $1, 0xc(%esp)\n" /* line 410 */
        "movl $0, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptEvent\n"
        "movl $1, %eax\n"
        "jmp .Lf9d6b6_0009d6e4\n"
        ".Lf9d6b6_0009d80d:\n"
        "andb $0xfb, %ah\n" /* line 396 */
        "movl %eax, 8(%esi)\n" /* pm */
        "xorl %eax, %eax\n"
        "jmp .Lf9d6b6_0009d6e4\n"
        /* { scope 2 */
        ".Lf9d6b6_0009d81a:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 350 | pml */
        "movl %ecx, (%esp)\n"
        "calll PM_GroundSurfaceType\n"
        "testl %eax, %eax\n" /* line 352 */
        "je .Lf9d6b6_0009d7d3\n"
        "addl $0x46, %eax\n" /* line 355 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll PM_AddEvent\n"
        "jmp .Lf9d6b6_0009d7d3\n"
        /* } scope */
        /* { scope 2 */
        ".Lf9d6b6_0009d83a:\n"
        "movss 0x2ed67c, %xmm0\n" /* line 310 | 0.75f */
        "mulss 0x28(%ebx), %xmm0\n"
        "movss %xmm0, 0x28(%ebx)\n"
        "movl 0xc(%ebp), %eax\n" /* line 312 | pml */
        "movl 4(%eax), %edx\n" /* y */
        /* { scope 3 */
        "movl (%eax), %eax\n" /* line 191 */
        "movl %eax, -0x20(%ebp)\n" /* flatForward */
        "movl %edx, -0x1c(%ebp)\n" /* line 192 */
        "movl $0, -0x18(%ebp)\n" /* line 193 */
        /* } scope */
        "leal -0x20(%ebp), %eax\n" /* line 313 | flatForward */
        "movl %eax, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movss 0x68(%ebx), %xmm5\n" /* line 304 */
        "movss 0x6c(%ebx), %xmm6\n"
        "movss 0x64(%ebx), %xmm0\n" /* line 318 */
        "movl 0xc(%ebp), %eax\n" /* pml */
        "mulss (%eax), %xmm0\n"
        "movaps %xmm5, %xmm1\n"
        "mulss 4(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm6, %xmm1\n"
        "mulss 8(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf9d6b6_0009d945\n"
        "movl -0x20(%ebp), %eax\n" /* line 199 | flatForward */
        "movl %eax, -0x14(%ebp)\n" /* pushOffDir */
        "movl -0x1c(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x10(%ebp)\n"
        "movl -0x18(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0xc(%ebp)\n"
        ".Lf9d6b6_0009d8bb:\n"
        "movl jump_ladderPushVel, %eax\n" /* line 329 */
        "movss 8(%eax), %xmm0\n" /* scale */
        /* { scope 3 */
        "movaps %xmm0, %xmm1\n" /* line 86 */
        "mulss -0x14(%ebp), %xmm1\n" /* pushOffDir */
        "movss %xmm1, 0x20(%ebx)\n"
        "mulss -0x10(%ebp), %xmm0\n" /* line 87 */
        "movss %xmm0, 0x24(%ebx)\n"
        /* } scope */
        "andl $0xffffffdf, 0xc(%ebx)\n" /* line 332 */
        "jmp .Lf9d6b6_0009d7d9\n"
        /* } scope */
        ".Lf9d6b6_0009d8e5:\n"
        "movl $1, 0xc(%esp)\n" /* line 412 */
        "movl $0, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll BG_AnimScriptEvent\n"
        "movl $1, %eax\n"
        "jmp .Lf9d6b6_0009d6e4\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf9d6b6_0009d90f:\n"
        "cmpl $0x6a3, %ecx\n" /* line 246 */
        "jle .Lf9d6b6_0009d924\n"
        "movss 0x2ed6c0, %xmm0\n" /* 2.5f */
        "jmp .Lf9d6b6_0009d74a\n"
        ".Lf9d6b6_0009d924:\n"
        "cvtsi2ssl %ecx, %xmm0\n" /* line 249 */
        "mulss 0x2ed600, %xmm0\n" /* 1.5f */
        "mulss 0x2ed7ec, %xmm0\n" /* 0.0005882352706976235f */
        "addss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jmp .Lf9d6b6_0009d74a\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf9d6b6_0009d945:\n"
        "movss -0x20(%ebp), %xmm2\n" /* line 304 | flatForward */
        "movss -0x1c(%ebp), %xmm3\n"
        "movss -0x18(%ebp), %xmm4\n"
        "movaps %xmm2, %xmm0\n" /* line 321 | scale */
        "mulss 0x64(%ebx), %xmm0\n" /* scale */
        "mulss %xmm3, %xmm5\n"
        "addss %xmm5, %xmm0\n" /* scale */
        "mulss %xmm4, %xmm6\n"
        "addss %xmm6, %xmm0\n" /* scale */
        "mulss 0x2ed628, %xmm0\n" /* -2.0f, scale */
        /* { scope 3 */
        "movaps %xmm0, %xmm1\n" /* line 288 */
        "mulss 0x64(%ebx), %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "movss %xmm2, -0x14(%ebp)\n" /* pushOffDir */
        "movaps %xmm0, %xmm1\n" /* line 289 */
        "mulss 0x68(%ebx), %xmm1\n"
        "addss %xmm1, %xmm3\n"
        "movss %xmm3, -0x10(%ebp)\n"
        "mulss 0x6c(%ebx), %xmm0\n" /* line 290 */
        "addss %xmm0, %xmm4\n"
        "movss %xmm4, -0xc(%ebp)\n"
        /* } scope */
        "leal -0x14(%ebp), %eax\n" /* line 322 | pushOffDir */
        "movl %eax, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "jmp .Lf9d6b6_0009d8bb\n"
    );
}

/* line 208 */
__attribute__((naked))
void Jump_ClampVelocity(playerState_t *ps, const vec_t *origin)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 208 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* ps */
        /* { scope 1 */
        "movss 0x1c(%edx), %xmm2\n" /* line 216 */
        "movl 0xc(%ebp), %eax\n" /* origin */
        "movaps %xmm2, %xmm0\n"
        "subss 8(%eax), %xmm0\n"
        "pxor %xmm3, %xmm3\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lf9d9b6_0009d9f8\n"
        "movss 0x74(%edx), %xmm1\n" /* line 218 */
        "movl jump_height, %eax\n"
        "addss 8(%eax), %xmm1\n"
        "subss %xmm2, %xmm1\n"
        "ucomiss 0x2ed7d0, %xmm1\n" /* line 220 | 0.10000000149011612f */
        "jae .Lf9d9b6_0009d9fa\n"
        "jp .Lf9d9b6_0009d9fa\n"
        "movss %xmm3, 0x28(%edx)\n" /* line 222 */
        /* } scope */
        ".Lf9d9b6_0009d9f8:\n"
        "popl %ebp\n" /* line 232 */
        "retl\n"
        /* { scope 1 */
        ".Lf9d9b6_0009d9fa:\n"
        "addss %xmm1, %xmm1\n" /* line 81 */
        "cvtsi2ssl 0x48(%edx), %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "sqrtss %xmm1, %xmm1\n"
        "movss 0x28(%edx), %xmm0\n" /* line 228 */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf9d9b6_0009d9f8\n"
        "movss %xmm1, 0x28(%edx)\n" /* line 229 */
        /* } scope */
        "popl %ebp\n" /* line 232 */
        "retl\n"
    );
}

