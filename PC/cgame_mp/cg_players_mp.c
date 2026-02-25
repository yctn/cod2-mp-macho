/* ASM dump from: cg_players_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_players_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/xanim/xanim_public.h"
 *   #include "PC/universal/q_shared.h"
 */

void CG_UpdatePlayerDObj(centity_t *cent);
void CG_ResetPlayerEntity(centity_t *cent);
static void CG_PlayerFloatSprite(MaterialHandle material, float additionalRadiusSize, int fixedScreenSize);
void CG_PlayerSprites(centity_t *cent);
void CG_Player(centity_t *cent);
void CG_Corpse(centity_t *cent);

/* line 531 */
__attribute__((naked))
void CG_UpdatePlayerDObj(centity_t *cent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 531 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ecx\n" /* cent */
        /* { scope 1 */
        "cmpb $0, 0x1e0(%ecx)\n" /* line 535 */
        "je .Lf1e3b5c_001e3bc1\n"
        "leal 0xf0(%ecx), %esi\n" /* line 537 | es */
        "movl 0x90(%esi), %edx\n" /* line 539 | es */
        "leal (%edx, %edx, 4), %eax\n"
        "movl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "subl %eax, %ebx\n"
        "leal (%edx, %ebx, 2), %ebx\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "leal 0xe0914(%eax, %ebx, 8), %ebx\n"
        "movl 0x220(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Com_GetClientDObj\n"
        "movl $0, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* es */
        "movl %eax, (%esp)\n"
        "calll BG_UpdatePlayerDObj\n"
        /* } scope */
        ".Lf1e3b5c_001e3bc1:\n"
        "addl $0x10, %esp\n" /* line 540 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 552 */
__attribute__((naked))
void CG_ResetPlayerEntity(centity_t *cent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 552 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %ebx\n" /* line 557 | cent, es */
        "addl $0xf0, %ebx\n" /* es */
        "movl 0x195f584, %eax\n" /* line 558 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0x90(%ebx), %edx\n" /* es */
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "movl -0x1c(%ebp), %edx\n"
        "leal 0xe0900(%edx, %eax, 8), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl %eax, %esi\n" /* ci */
        "addl $0x14, %esi\n" /* ci */
        "movl 8(%ebx), %ecx\n" /* line 560 | es */
        "andl $0x20000, %ecx\n"
        "movl %ecx, -0x24(%ebp)\n"
        "je .Lf1e3bc8_001e3c53\n"
        ".Lf1e3bc8_001e3c17:\n"
        "movl 0x195f970, %eax\n" /* line 587 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1e3bc8_001e3c4b\n"
        "cvtss2sd 0x3b0(%esi), %xmm0\n" /* line 589 | ci */
        "movsd %xmm0, 8(%esp)\n"
        "movl 8(%ebp), %edx\n" /* cent */
        "movl 0xf0(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b8500, (%esp)\n" /* "%i ResetPlayerEntity yaw=%i
" */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf1e3bc8_001e3c4b:\n"
        "addl $0x4c, %esp\n" /* line 591 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1e3bc8_001e3c53:\n"
        "movl 0x4a4(%esi), %edi\n" /* line 564 | ci, pAnimTree */
        "xorl %ebx, %ebx\n" /* line 567 | es */
        "movl %ebx, 8(%esp)\n" /* es */
        "movzwl 0xe08e4(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* pAnimTree */
        "calll XAnimClearTreeGoalWeights\n"
        "movl $0, 0x1c(%esp)\n" /* line 570 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* es */
        "movl %ebx, 8(%esp)\n" /* es */
        "movl -0x1c(%ebp), %edx\n"
        "movzwl 0xe08d0(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* pAnimTree */
        "calll XAnimSetCompleteGoalWeight\n"
        "movl $0, 0x1c(%esp)\n" /* line 571 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* es */
        "movl $0x3f800000, 8(%esp)\n"
        "movl -0x1c(%ebp), %ecx\n"
        "movzwl 0xe08d2(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* pAnimTree */
        "calll XAnimSetCompleteGoalWeight\n"
        "movl $0, 0x1c(%esp)\n" /* line 572 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* es */
        "movl %ebx, 8(%esp)\n" /* es */
        "movl -0x1c(%ebp), %edx\n"
        "movzwl 0xe08d4(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* pAnimTree */
        "calll XAnimSetCompleteGoalWeight\n"
        "movl -0x20(%ebp), %edi\n" /* line 574 | pAnimTree */
        "addl $0x394, %edi\n" /* pAnimTree */
        "cld\n"
        "movl $0xc, %edx\n"
        "movl %edx, %ecx\n"
        "movl -0x24(%ebp), %eax\n"
        "rep stosl %eax, %es:(%edi)\n" /* pAnimTree */
        "movss 0x3ec(%esi), %xmm0\n" /* line 575 | ci */
        "movss %xmm0, 0x380(%esi)\n" /* ci */
        "movl $0, 0x384(%esi)\n" /* line 576 | ci */
        "movl %ebx, 0x388(%esi)\n" /* line 577 | es, ci */
        "movl $0, 0x38c(%esi)\n" /* line 578 | ci */
        "movl -0x20(%ebp), %edi\n" /* line 580 | pAnimTree */
        "addl $0x3c4, %edi\n" /* pAnimTree */
        "movl %edx, %ecx\n"
        "rep stosl %eax, %es:(%edi)\n" /* pAnimTree */
        "movss %xmm0, 0x3b0(%esi)\n" /* line 581 | ci */
        "movl $0, 0x3b4(%esi)\n" /* line 582 | ci */
        "movl 0x3e8(%esi), %eax\n" /* line 583 | ci */
        "movl %eax, 0x3b8(%esi)\n" /* ci */
        "movl $0, 0x3bc(%esi)\n" /* line 584 | ci */
        "jmp .Lf1e3bc8_001e3c17\n"
    );
}

/* line 25 */
static __attribute__((naked))
void CG_PlayerFloatSprite(MaterialHandle material, float additionalRadiusSize, int fixedScreenSize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 25 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %eax, %ebx\n" /* cent */
        "movl %edx, -0x2c(%ebp)\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "movl %ecx, %esi\n" /* height */
        "movzbl 8(%ebp), %edi\n" /* fixedScreenSize */
        /* { scope 1 */
        "movl 0x195f584, %eax\n" /* line 38 */
        "movl (%eax), %eax\n"
        "movl 0x24(%eax), %ecx\n"
        "testl $0xc00000, 0x18(%ecx)\n"
        "je .Lf1e3daa_001e3f05\n"
        "movl 0xf0(%ebx), %edx\n" /* cent */
        "cmpl 0xd8(%ecx), %edx\n"
        "je .Lf1e3daa_001e3ef5\n"
        ".Lf1e3daa_001e3dec:\n"
        "movl 0x220(%ebx), %eax\n" /* line 42 | cent */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Com_GetClientDObj\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 43 */
        "je .Lf1e3daa_001e3e2f\n"
        "leal -0x28(%ebp), %eax\n" /* origin */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x195f5bc, %eax\n"
        "movzwl 0x96(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* cent */
        "calll CG_DObjGetWorldTagPos\n"
        "testl %eax, %eax\n"
        "jne .Lf1e3daa_001e3eda\n"
        ".Lf1e3daa_001e3e2f:\n"
        "leal 0x1ec(%ebx), %edx\n" /* cent */
        /* { scope 2 */
        "movl 0x1ec(%ebx), %eax\n" /* line 199 | cent */
        "movl %eax, -0x28(%ebp)\n" /* origin */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x24(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x20(%ebp)\n"
        /* } scope */
        "cvtsi2ssl %esi, %xmm0\n" /* line 50 | height */
        "addss 0x2eda98, %xmm0\n" /* 82.0f */
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        ".Lf1e3daa_001e3e60:\n"
        "movl %edi, %eax\n" /* line 53 | fixedScreenSize */
        "testb %al, %al\n"
        "je .Lf1e3daa_001e3ec9\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 56 */
        "addss 0x2ed6b4, %xmm0\n" /* 10.0f */
        "mulss 0x2eda8c, %xmm0\n" /* 0.00430000014603138f */
        "movl $0x3000, %eax\n"
        ".Lf1e3daa_001e3e80:\n"
        "movb $0xff, -0x1c(%ebp)\n" /* line 664 | rgbaColor */
        "movb $0xff, -0x1b(%ebp)\n" /* line 665 */
        "movb $0xff, -0x1a(%ebp)\n" /* line 666 */
        "movb $0xff, -0x19(%ebp)\n" /* line 667 */
        "movl %eax, 0x14(%esp)\n" /* line 66 */
        "movl 0x195f96c, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movss %xmm0, 0xc(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* origin */
        "movl %eax, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* rgbaColor */
        "movl %eax, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_DrawSprite\n"
        /* } scope */
        ".Lf1e3daa_001e3ec1:\n"
        "addl $0x4c, %esp\n" /* line 67 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e3daa_001e3ec9:\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 61 */
        "addss 0x2ed6b4, %xmm0\n" /* 10.0f */
        "xorl %eax, %eax\n"
        "jmp .Lf1e3daa_001e3e80\n"
        ".Lf1e3daa_001e3eda:\n"
        "cvtsi2ssl %esi, %xmm0\n" /* line 45 | height */
        "addss 0x2eda9c, %xmm0\n" /* 21.0f */
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "jmp .Lf1e3daa_001e3e60\n"
        ".Lf1e3daa_001e3ef5:\n"
        "movl 0x25bc0(%eax), %eax\n" /* line 38 */
        "testl %eax, %eax\n"
        "jne .Lf1e3daa_001e3dec\n"
        "jmp .Lf1e3daa_001e3ec1\n"
        ".Lf1e3daa_001e3f05:\n"
        "movl 0xf0(%ebx), %edx\n" /* cent */
        "jmp .Lf1e3daa_001e3dec\n"
    );
}

/* line 75 */
__attribute__((naked))
void CG_PlayerSprites(centity_t *cent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 75 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* cent */
        /* { scope 1 */
        "movl 0x195f584, %eax\n" /* line 84 */
        "movl (%eax), %ebx\n"
        "movl 0x180(%esi), %eax\n" /* cent */
        "leal (%eax, %eax, 4), %ecx\n"
        "movl %ecx, %edx\n"
        "shll $4, %edx\n"
        "subl %ecx, %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "leal (%ebx, %edx, 8), %eax\n"
        "movl 0xe0914(%eax), %edi\n"
        "testl %edi, %edi\n"
        "je .Lf1e3f10_001e3fd4\n"
        "movl 0xe0940(%eax), %eax\n" /* line 86 */
        "movl %eax, -0x1c(%ebp)\n" /* iTeam */
        "movl 0x24(%ebx), %eax\n" /* line 88 */
        "movl 0xd8(%eax), %edx\n"
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "leal (%ebx, %eax, 8), %eax\n"
        "movl 0xe0914(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lf1e3f10_001e3fd4\n"
        "movl 0xe0940(%eax), %edi\n" /* line 90 */
        "movl 0x184(%esi), %eax\n" /* line 93 | cent */
        "testl %eax, %eax\n"
        "je .Lf1e3f10_001e3fa2\n"
        "movl 0x188(%esi), %edx\n" /* line 95 | cent */
        "testl %edx, %edx\n"
        "je .Lf1e3f10_001e4030\n"
        "cmpl $3, %edi\n"
        "je .Lf1e3f10_001e4030\n"
        "cmpl %edx, %edi\n"
        "je .Lf1e3f10_001e4030\n"
        ".Lf1e3f10_001e3fa2:\n"
        "pxor %xmm0, %xmm0\n" /* line 114 */
        ".Lf1e3f10_001e3fa6:\n"
        "movl 0x195f584, %eax\n" /* line 117 */
        "movl (%eax), %edx\n"
        "movl 0xf0(%esi), %eax\n" /* cent */
        "cmpl 4(%edx), %eax\n"
        "je .Lf1e3f10_001e408d\n"
        ".Lf1e3f10_001e3fbc:\n"
        "movl 0xf8(%esi), %ecx\n" /* line 123 | cent */
        "testb %cl, %cl\n"
        "js .Lf1e3f10_001e40c4\n"
        "cmpl %edi, -0x1c(%ebp)\n" /* line 129 | iTeam */
        "je .Lf1e3f10_001e3fdc\n"
        "cmpl $3, %edi\n"
        "je .Lf1e3f10_001e3fdc\n"
        /* } scope */
        ".Lf1e3f10_001e3fd4:\n"
        "addl $0x2c, %esp\n" /* line 145 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e3f10_001e3fdc:\n"
        "movl 0x218(%esi), %eax\n" /* line 132 | cent */
        "cmpl 0x25bb0(%edx), %eax\n"
        "jg .Lf1e3f10_001e40f6\n"
        "andl $0x200000, %ecx\n" /* line 139 */
        "je .Lf1e3f10_001e3fd4\n"
        "subss 0x2ed6d4, %xmm0\n" /* line 141 | 5.0f */
        "cvttss2si %xmm0, %ecx\n"
        "movl 0x195f968, %eax\n"
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "movl 0x195f5c4, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0xba30(%eax), %edx\n"
        "movl $0, 8(%ebp)\n" /* cent */
        ".Lf1e3f10_001e4022:\n"
        "movl %esi, %eax\n" /* line 125 | cent */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 145 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CG_PlayerFloatSprite\n" /* line 125 */
        ".Lf1e3f10_001e4030:\n"
        "addl $0x1e, %eax\n" /* line 101 */
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl $7, 4(%esp)\n" /* line 102 */
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterial\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 103 */
        "je .Lf1e3f10_001e3fa2\n"
        "movl 0x195f978, %ebx\n" /* line 105 */
        "movl (%ebx), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "movl 0x195f974, %eax\n"
        "movl (%eax), %eax\n"
        "movzbl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "xorl %ecx, %ecx\n"
        "movl %esi, %eax\n" /* cent */
        "calll CG_PlayerFloatSprite\n"
        "movl (%ebx), %eax\n" /* line 114 */
        "movss 0x2ed6a8, %xmm0\n" /* 16.0f */
        "addss 8(%eax), %xmm0\n"
        "jmp .Lf1e3f10_001e3fa6\n"
        ".Lf1e3f10_001e408d:\n"
        "movl 0x2cd14(%edx), %ecx\n" /* line 117 */
        "testl %ecx, %ecx\n"
        "je .Lf1e3f10_001e3fbc\n"
        "cvttss2si %xmm0, %ecx\n" /* line 119 */
        "movl 0x195f97c, %eax\n"
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "movl 0x195f5c4, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0xba38(%eax), %edx\n"
        "movl $1, 8(%ebp)\n" /* cent */
        "jmp .Lf1e3f10_001e4022\n"
        ".Lf1e3f10_001e40c4:\n"
        "cvttss2si %xmm0, %ecx\n" /* line 125 */
        "movl 0x195f980, %eax\n"
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "movl 0x195f5c4, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0xba34(%eax), %edx\n"
        "movl $0, 8(%ebp)\n" /* cent */
        "movl %esi, %eax\n" /* cent */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 145 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CG_PlayerFloatSprite\n" /* line 125 */
        ".Lf1e3f10_001e40f6:\n"
        "cvttss2si %xmm0, %ecx\n" /* line 134 */
        "movl 0x195f968, %eax\n"
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "movl 0x214(%esi), %edx\n" /* cent */
        "movl $0, 8(%ebp)\n" /* cent */
        "jmp .Lf1e3f10_001e4022\n"
    );
}

/* line 378 */
__attribute__((naked))
void CG_Player(centity_t *cent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 378 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x23c, %esp\n"
        /* { scope 1: i, numVertChildren, iPrevBlend, ci, ... */
        "movl 8(%ebp), %edi\n" /* line 387 | cent, es */
        "addl $0xf0, %edi\n" /* es */
        "movl 8(%edi), %eax\n" /* line 390 | es */
        "testb $0x20, %al\n"
        "jne .Lf1e4118_001e48f8\n"
        "testl $0x20000, %eax\n" /* line 393 */
        "jne .Lf1e4118_001e48f8\n"
        "movl 0x195f584, %eax\n" /* line 396 */
        "movl (%eax), %ecx\n"
        "movl 0x24(%ecx), %edx\n"
        "testl $0xc00000, 0x18(%edx)\n"
        "je .Lf1e4118_001e4923\n"
        "movl 8(%ebp), %ebx\n" /* cent, iClientNum */
        "movl 0xf0(%ebx), %eax\n" /* iClientNum */
        "cmpl 0xd8(%edx), %eax\n"
        "je .Lf1e4118_001e4919\n"
        "movl %ebx, %edx\n" /* iClientNum */
        ".Lf1e4118_001e4171:\n"
        "movl 0x90(%edi), %ebx\n" /* line 402 | es, iClientNum */
        "movl 0x220(%edx), %eax\n" /* line 405 */
        "movl %eax, 4(%esp)\n"
        "movl (%edi), %eax\n" /* es */
        "movl %eax, (%esp)\n"
        "calll Com_GetClientDObj\n"
        "movl %eax, -0x208(%ebp)\n" /* obj */
        "testl %eax, %eax\n" /* line 406 */
        "je .Lf1e4118_001e48f8\n"
        "movl $0x74, 8(%esp)\n" /* line 409 */
        "movl $0, 4(%esp)\n"
        "leal -0x190(%ebp), %ecx\n" /* body */
        "movl %ecx, (%esp)\n"
        "calll memset\n"
        "movb $0xff, -0x138(%ebp)\n" /* line 411 */
        "movb $0xff, -0x137(%ebp)\n" /* line 412 */
        "movb $0xff, -0x136(%ebp)\n" /* line 413 */
        "movb $0xff, -0x135(%ebp)\n" /* line 414 */
        "leal (%ebx, %ebx, 4), %eax\n" /* line 419 | iClientNum */
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "subl %eax, %edx\n"
        "leal (%ebx, %edx, 2), %edx\n" /* iClientNum */
        "movl 0x195f584, %eax\n"
        "movl (%eax), %esi\n" /* heightAnim */
        "leal 0xe0914(%esi, %edx, 8), %edx\n" /* heightAnim */
        "movl %edx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* es */
        "movl -0x208(%ebp), %ebx\n" /* obj, iClientNum */
        "movl %ebx, (%esp)\n" /* iClientNum */
        "calll BG_PlayerAnimation\n"
        "testl $0x300, 8(%edi)\n" /* line 421 | es */
        "je .Lf1e4118_001e4816\n"
        /* { scope 2: xx, yy */
        "movl 8(%ebp), %eax\n" /* line 198 | cent */
        "movl 0x164(%eax), %ebx\n" /* numHorChildren */
        "cmpl $0x3f, %ebx\n" /* numHorChildren */
        "jle .Lf1e4118_001e4940\n"
        "cmpl $0x3ff, %ebx\n" /* numHorChildren */
        "je .Lf1e4118_001e4816\n"
        "movl 0x180(%eax), %eax\n" /* line 202 */
        "leal (%eax, %eax, 4), %ecx\n"
        "movl %ecx, %edx\n"
        "shll $4, %edx\n"
        "subl %ecx, %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "leal 0xe0900(%esi, %edx, 8), %eax\n" /* heightAnim */
        "leal 0x14(%eax), %ecx\n"
        "movl %ecx, -0x1f0(%ebp)\n" /* ci */
        "movl 0x14(%eax), %ecx\n" /* line 203 */
        "testl %ecx, %ecx\n"
        "je .Lf1e4118_001e4959\n"
        "addl $0x394, %eax\n" /* line 207 */
        "movl %eax, -0x1e8(%ebp)\n" /* pLerpAnim */
        "movl 0x10(%eax), %edx\n" /* line 208 */
        "testl %edx, %edx\n"
        "je .Lf1e4118_001e4816\n"
        "movl 0x14(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e4118_001e4959\n"
        "testb $4, 0x50(%eax)\n"
        "je .Lf1e4118_001e4816\n"
        "movl %ebx, %eax\n" /* line 211 | numHorChildren */
        "shll $4, %eax\n"
        "addl %ebx, %eax\n" /* numHorChildren */
        "leal (%ebx, %eax, 8), %eax\n" /* numHorChildren */
        "movl 0x195f5cc, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0x1ec(%ebp)\n" /* pTurretCEnt */
        "cmpb $0, 0x1e0(%eax)\n" /* line 212 */
        "je .Lf1e4118_001e4959\n"
        "movl %eax, %ecx\n" /* line 215 */
        "movl 0x220(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xf0(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_GetClientDObj\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 216 */
        "je .Lf1e4118_001e4816\n"
        "movl 0x195f5bc, %eax\n" /* line 219 */
        "movzwl 0x98(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x1ec(%ebp), %ebx\n" /* pTurretCEnt, numHorChildren */
        "movl %ebx, (%esp)\n" /* numHorChildren */
        "calll CG_DObjGetLocalTagMatrix\n"
        "movl %eax, -0x1c8(%ebp)\n" /* tagMat */
        "testl %eax, %eax\n" /* line 220 */
        "je .Lf1e4118_001e480a\n"
        "movl 0x25bac(%esi), %eax\n" /* line 226 | heightAnim */
        "testl %eax, %eax\n"
        "je .Lf1e4118_001e4959\n"
        "movl -0x1ec(%ebp), %edx\n" /* line 230 | pTurretCEnt */
        "movl 0x1b8(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl %eax, -0x1e4(%ebp)\n" /* weapDef */
        "movl -0x1f0(%ebp), %ecx\n" /* line 234 | ci */
        "movl 0x4a4(%ecx), %ecx\n"
        "movl %ecx, -0x1c4(%ebp)\n" /* pAnimTree */
        "movl 0xe08cc(%esi), %esi\n" /* line 235 | heightAnim */
        "movl %esi, -0x1c0(%ebp)\n" /* heightAnim, pXAnims */
        "movl -0x1e8(%ebp), %ebx\n" /* line 236 | pLerpAnim, numHorChildren */
        "movl 0x10(%ebx), %eax\n" /* numHorChildren */
        "andb $0xfd, %ah\n"
        "movl %eax, -0x1bc(%ebp)\n" /* baseAnim */
        /* { scope 3 */
        "movl -0x1c8(%ebp), %edx\n" /* line 306 | tagMat */
        "movss 0x1c(%edx), %xmm1\n" /* scale */
        /* { scope 4 */
        "movaps %xmm1, %xmm3\n" /* line 272 */
        "mulss (%edx), %xmm3\n"
        "movaps %xmm1, %xmm4\n" /* line 273 */
        "mulss 4(%edx), %xmm4\n"
        "mulss 8(%edx), %xmm1\n" /* line 274 */
        /* } scope */
        "movaps %xmm3, %xmm0\n" /* line 308 */
        "mulss (%edx), %xmm0\n"
        "movss %xmm0, -0x1b0(%ebp)\n" /* xx */
        "movss 4(%edx), %xmm5\n" /* line 309 */
        "movaps %xmm3, %xmm6\n"
        "mulss %xmm5, %xmm6\n"
        "movss 8(%edx), %xmm2\n" /* line 310 */
        "movaps %xmm3, %xmm7\n"
        "mulss %xmm2, %xmm7\n"
        "movss 0xc(%edx), %xmm0\n" /* line 311 */
        "mulss %xmm0, %xmm3\n"
        "mulss %xmm4, %xmm5\n" /* line 313 */
        "movss %xmm5, -0x1ac(%ebp)\n" /* yy */
        "movaps %xmm4, %xmm5\n" /* line 314 */
        "mulss %xmm2, %xmm5\n"
        "mulss %xmm0, %xmm4\n" /* line 315 */
        "mulss %xmm1, %xmm2\n" /* line 317 */
        "mulss %xmm0, %xmm1\n" /* line 318 */
        "movss -0x1ac(%ebp), %xmm0\n" /* line 320 | yy */
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -0x220(%ebp)\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "subss -0x220(%ebp), %xmm0\n"
        "movss %xmm0, -0x68(%ebp)\n" /* tagAxis */
        "movaps %xmm6, %xmm0\n" /* line 321 */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x64(%ebp)\n"
        "movaps %xmm7, %xmm0\n" /* line 322 */
        "subss %xmm4, %xmm0\n"
        "movss %xmm0, -0x60(%ebp)\n"
        "subss %xmm1, %xmm6\n" /* line 324 */
        "movss %xmm6, -0x5c(%ebp)\n"
        "addss -0x1b0(%ebp), %xmm2\n" /* line 325 | xx */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "movaps %xmm3, %xmm0\n" /* line 326 */
        "addss %xmm5, %xmm0\n"
        "movss %xmm0, -0x54(%ebp)\n"
        "addss %xmm4, %xmm7\n" /* line 328 */
        "movss %xmm7, -0x50(%ebp)\n"
        "subss %xmm3, %xmm5\n" /* line 329 */
        "movss %xmm5, -0x4c(%ebp)\n"
        "movss -0x1b0(%ebp), %xmm1\n" /* line 330 | xx */
        "addss -0x1ac(%ebp), %xmm1\n" /* yy */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x48(%ebp)\n"
        /* } scope */
        "leal -0x68(%ebp), %eax\n" /* line 239 | tagAxis */
        "movl %eax, (%esp)\n"
        "calll vectosignedyaw\n"
        "fstps -0x1e0(%ebp)\n" /* localYaw */
        "leal -0xec(%ebp), %eax\n" /* line 241 | turretAxis */
        "movl %eax, 4(%esp)\n"
        "movl -0x1ec(%ebp), %eax\n" /* pTurretCEnt */
        "addl $0x1f8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "movl -0x1ec(%ebp), %edx\n" /* pTurretCEnt */
        "addl $0x1ec, %edx\n"
        /* { scope 3 */
        "movl -0x1ec(%ebp), %ecx\n" /* line 199 | pTurretCEnt */
        "movl 0x1ec(%ecx), %eax\n"
        "movl %eax, -0xc8(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0xc4(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0xc0(%ebp)\n"
        /* } scope */
        "movl 8(%ebp), %ebx\n" /* line 244 | cent, numHorChildren */
        "addl $0x1ec, %ebx\n" /* numHorChildren */
        "movl %ebx, -0x20c(%ebp)\n" /* numHorChildren */
        "movl 8(%ebp), %eax\n" /* line 249 | cent */
        "addl $0x1f0, %eax\n"
        "movl %eax, -0x1a8(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 250 | cent */
        "addl $0x1f4, %edx\n"
        "movl %edx, -0x1a4(%ebp)\n"
        "movl 8(%ebp), %ecx\n" /* line 304 | cent */
        "movss 0x1ec(%ecx), %xmm0\n"
        "subss -0xc8(%ebp), %xmm0\n"
        "mulss -0xd4(%ebp), %xmm0\n"
        "movss %xmm0, -0x1cc(%ebp)\n" /* tagHeight */
        "movss 0x1f0(%ecx), %xmm0\n"
        "subss -0xc4(%ebp), %xmm0\n"
        "mulss -0xd0(%ebp), %xmm0\n"
        "addss -0x1cc(%ebp), %xmm0\n" /* tagHeight */
        "movss %xmm0, -0x1cc(%ebp)\n" /* tagHeight */
        "movss 0x1f4(%ecx), %xmm0\n"
        "subss -0xc0(%ebp), %xmm0\n"
        "mulss -0xcc(%ebp), %xmm0\n"
        "addss -0x1cc(%ebp), %xmm0\n" /* tagHeight */
        "movss %xmm0, -0x1cc(%ebp)\n" /* tagHeight */
        "movl -0x1c8(%ebp), %eax\n" /* line 246 | tagMat */
        "subss 0x18(%eax), %xmm0\n"
        "movss %xmm0, -0x1dc(%ebp)\n" /* fDelta */
        "xorl %ebx, %ebx\n" /* line 248 | numHorChildren */
        "movl %ebx, 8(%esp)\n" /* numHorChildren */
        "movl -0x1bc(%ebp), %edx\n" /* baseAnim */
        "movl %edx, 4(%esp)\n"
        "movl -0x1c4(%ebp), %ecx\n" /* pAnimTree */
        "movl %ecx, (%esp)\n"
        "calll XAnimClearTreeGoalWeightsStrict\n"
        "movl -0x1bc(%ebp), %eax\n" /* line 250 | baseAnim */
        "movl %eax, 4(%esp)\n"
        "movl -0x1c0(%ebp), %edx\n" /* pXAnims */
        "movl %edx, (%esp)\n"
        "calll XAnimGetNumChildren\n"
        "movl %eax, -0x1f8(%ebp)\n" /* numVertChildren */
        "testl %eax, %eax\n" /* line 256 */
        "jne .Lf1e4118_001e45ec\n"
        "movl -0x1bc(%ebp), %ecx\n" /* line 257 | baseAnim */
        "movl %ecx, 4(%esp)\n"
        "movl -0x1c0(%ebp), %eax\n" /* pXAnims */
        "movl %eax, (%esp)\n"
        "calll XAnimGetAnimDebugName\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2b59fc, 4(%esp)\n" /* "Player anim '%s' has no children" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf1e4118_001e45ec:\n"
        "movl %ebx, -0x1d4(%ebp)\n" /* numHorChildren, fPrevBlend */
        "movss -0x1d4(%ebp), %xmm0\n" /* fPrevBlend */
        "movss %xmm0, -0x1a0(%ebp)\n"
        "movl $0, -0x1f4(%ebp)\n" /* iPrevBlend */
        "movl $0, -0x1b4(%ebp)\n" /* leafAnim2 */
        "movl $0, -0x1fc(%ebp)\n" /* i */
        "jmp .Lf1e4118_001e4739\n"
        ".Lf1e4118_001e4625:\n"
        "cvttss2si %xmm1, %ebx\n" /* line 273 | numHorChildren */
        ".Lf1e4118_001e4629:\n"
        "cvtsi2ssl %ebx, %xmm0\n" /* line 277 | numHorChildren */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x19c(%ebp)\n"
        "movl %ebx, 8(%esp)\n" /* line 279 | numHorChildren */
        "movl %esi, 4(%esp)\n" /* heightAnim */
        "movl -0x1c0(%ebp), %eax\n" /* pXAnims */
        "movl %eax, (%esp)\n"
        "calll XAnimGetChildAt\n"
        "movl %eax, -0x1b8(%ebp)\n" /* leafAnim1 */
        "movss 0x2ed5d0, %xmm0\n" /* line 280 | 1.0f */
        "subss -0x19c(%ebp), %xmm0\n"
        "movss %xmm0, -0x204(%ebp)\n"
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, 0x10(%esp)\n"
        "movl $0x3f800000, 0xc(%esp)\n"
        "movss %xmm0, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x1c4(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "movss -0x19c(%ebp), %xmm0\n" /* line 282 */
        "ucomiss 0x2ed5e8, %xmm0\n" /* 0.0f */
        "jp .Lf1e4118_001e49a5\n"
        "jne .Lf1e4118_001e49a5\n"
        ".Lf1e4118_001e46c8:\n"
        "leal -0x44(%ebp), %edx\n" /* line 288 | trans */
        "movl %edx, 0xc(%esp)\n"
        "leal -0x20(%ebp), %ecx\n" /* rot */
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* heightAnim */
        "movl -0x1c4(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimCalcAbsDelta\n"
        "movss -0x3c(%ebp), %xmm0\n" /* line 289 */
        "movss %xmm0, -0x1d8(%ebp)\n" /* fPrevTransZ */
        "ucomiss -0x1dc(%ebp), %xmm0\n" /* fDelta */
        "jae .Lf1e4118_001e51b8\n"
        "addl $1, -0x1fc(%ebp)\n" /* line 296 | i */
        "movl -0x1fc(%ebp), %eax\n" /* line 260 | i */
        "cmpl %eax, -0x1f8(%ebp)\n" /* numVertChildren */
        "jle .Lf1e4118_001e4a1c\n"
        "movss %xmm0, -0x1a0(%ebp)\n"
        "movss -0x19c(%ebp), %xmm0\n"
        "movss %xmm0, -0x1d4(%ebp)\n" /* fPrevBlend */
        "movl %ebx, -0x1f4(%ebp)\n" /* numHorChildren, iPrevBlend */
        ".Lf1e4118_001e4739:\n"
        "movl -0x1fc(%ebp), %eax\n" /* line 262 | i */
        "movl %eax, 8(%esp)\n"
        "movl -0x1bc(%ebp), %edx\n" /* baseAnim */
        "movl %edx, 4(%esp)\n"
        "movl -0x1c0(%ebp), %ecx\n" /* pXAnims */
        "movl %ecx, (%esp)\n"
        "calll XAnimGetChildAt\n"
        "movl %eax, %esi\n" /* heightAnim */
        "movl $0, 0x1c(%esp)\n" /* line 263 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, 0x10(%esp)\n"
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x1c4(%ebp), %ebx\n" /* pAnimTree, numHorChildren */
        "movl %ebx, (%esp)\n" /* numHorChildren */
        "calll XAnimSetGoalWeight\n"
        "movl %esi, 4(%esp)\n" /* line 265 | heightAnim */
        "movl -0x1c0(%ebp), %eax\n" /* pXAnims */
        "movl %eax, (%esp)\n"
        "calll XAnimGetNumChildren\n"
        "movl %eax, %ebx\n" /* numHorChildren */
        "testl %eax, %eax\n" /* line 266 */
        "je .Lf1e4118_001e4976\n"
        ".Lf1e4118_001e47bb:\n"
        "cvtsi2ssl %ebx, %xmm1\n" /* line 269 | numHorChildren */
        "mulss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "movss -0x1e0(%ebp), %xmm0\n" /* localYaw */
        "movl -0x1e4(%ebp), %ecx\n" /* weapDef */
        "divss 0x564(%ecx), %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "pxor %xmm0, %xmm0\n" /* line 271 */
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf1e4118_001e4a11\n"
        "leal -1(%ebx), %eax\n" /* line 273 | numHorChildren */
        "cvtsi2ssl %eax, %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf1e4118_001e4625\n"
        "cvttss2si %xmm0, %ebx\n" /* numHorChildren */
        "movaps %xmm0, %xmm1\n"
        "jmp .Lf1e4118_001e4629\n"
        ".Lf1e4118_001e480a:\n"
        "movl $0x2b59a8, (%esp)\n" /* line 222 */
        "calll Com_Printf\n"
        ".Lf1e4118_001e4816:\n"
        "movl 8(%ebp), %eax\n" /* cent */
        "addl $0x1ec, %eax\n"
        "movl %eax, -0x20c(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* cent */
        "leal 0x1f8(%edx), %esi\n" /* heightAnim */
        /* } scope */
        ".Lf1e4118_001e482d:\n"
        "leal -0x17c(%ebp), %eax\n" /* line 424 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* heightAnim */
        "calll AnglesToAxis\n"
        "movl 8(%ebp), %eax\n" /* line 199 | cent */
        "movl 0x1ec(%eax), %edx\n"
        "movl %edx, -0x154(%ebp)\n"
        "movl -0x20c(%ebp), %ecx\n" /* line 200 */
        "movl 4(%ecx), %eax\n"
        "movl %eax, -0x150(%ebp)\n"
        "movss 8(%ecx), %xmm0\n" /* line 201 */
        "movss %xmm0, -0x14c(%ebp)\n"
        "movl %edx, -0x188(%ebp)\n" /* line 199 */
        "movl %eax, -0x184(%ebp)\n" /* line 200 */
        "addss 0xe4(%edi), %xmm0\n" /* line 433 | es */
        "movss %xmm0, -0x180(%ebp)\n"
        "movl 8(%edi), %eax\n" /* line 435 | es */
        "testb $8, %al\n"
        "je .Lf1e4118_001e4903\n"
        "addss 0x2ed79c, %xmm0\n" /* line 436 | 12.0f */
        "movss %xmm0, -0x180(%ebp)\n"
        ".Lf1e4118_001e489d:\n"
        "movl $0, -0x190(%ebp)\n" /* line 442 | body */
        "movl $0x80, -0x18c(%ebp)\n" /* line 444 */
        "movl 8(%ebp), %ebx\n" /* line 446 | cent, iClientNum */
        "movl %ebx, 8(%esp)\n" /* iClientNum */
        "movl -0x208(%ebp), %eax\n" /* obj */
        "movl %eax, 4(%esp)\n"
        "leal -0x190(%ebp), %edx\n" /* body */
        "movl %edx, (%esp)\n"
        "calll CG_AddCEntityToScene\n"
        "testb $2, 0xa(%edi)\n" /* line 449 | es */
        "jne .Lf1e4118_001e48f8\n"
        "movl $1, 0xc(%esp)\n" /* line 451 */
        "movl %ebx, 8(%esp)\n" /* iClientNum */
        "movl $0, 4(%esp)\n"
        "leal -0x190(%ebp), %ecx\n" /* body */
        "movl %ecx, (%esp)\n"
        "calll CG_AddPlayerWeapon\n"
        /* } scope */
        ".Lf1e4118_001e48f8:\n"
        "addl $0x23c, %esp\n" /* line 458 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: i, numVertChildren, iPrevBlend, ci, ... */
        ".Lf1e4118_001e4903:\n"
        "testb $4, %al\n" /* line 437 */
        "je .Lf1e4118_001e492b\n"
        "addss 0x2ed694, %xmm0\n" /* line 438 | 20.0f */
        "movss %xmm0, -0x180(%ebp)\n"
        "jmp .Lf1e4118_001e489d\n"
        ".Lf1e4118_001e4919:\n"
        "movl 0x25bc0(%ecx), %ebx\n" /* line 396 | iClientNum */
        "testl %ebx, %ebx\n" /* iClientNum */
        "je .Lf1e4118_001e48f8\n"
        ".Lf1e4118_001e4923:\n"
        "movl 8(%ebp), %edx\n" /* cent */
        "jmp .Lf1e4118_001e4171\n"
        ".Lf1e4118_001e492b:\n"
        "addss 0x2ed830, %xmm0\n" /* line 440 | 32.0f */
        "movss %xmm0, -0x180(%ebp)\n"
        "jmp .Lf1e4118_001e489d\n"
        ".Lf1e4118_001e4940:\n"
        "movl %eax, %ecx\n"
        "addl $0x1ec, %ecx\n"
        "movl %ecx, -0x20c(%ebp)\n"
        "leal 0x1f8(%eax), %esi\n" /* heightAnim */
        "jmp .Lf1e4118_001e482d\n"
        ".Lf1e4118_001e4959:\n"
        "movl 8(%ebp), %ecx\n" /* cent */
        "addl $0x1ec, %ecx\n"
        "movl %ecx, -0x20c(%ebp)\n"
        "movl 8(%ebp), %ebx\n" /* cent, iClientNum */
        "leal 0x1f8(%ebx), %esi\n" /* iClientNum, heightAnim */
        "jmp .Lf1e4118_001e482d\n"
        /* { scope 2: xx, yy */
        ".Lf1e4118_001e4976:\n"
        "movl %esi, 4(%esp)\n" /* line 267 | heightAnim */
        "movl -0x1c0(%ebp), %edx\n" /* pXAnims */
        "movl %edx, (%esp)\n"
        "calll XAnimGetAnimDebugName\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2b59fc, 4(%esp)\n" /* "Player anim '%s' has no children" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1e4118_001e47bb\n"
        ".Lf1e4118_001e49a5:\n"
        "leal 1(%ebx), %eax\n" /* line 284 | numHorChildren */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* heightAnim */
        "movl -0x1c0(%ebp), %eax\n" /* pXAnims */
        "movl %eax, (%esp)\n"
        "calll XAnimGetChildAt\n"
        "movl %eax, -0x1b4(%ebp)\n" /* leafAnim2 */
        "movl $0, 0x1c(%esp)\n" /* line 285 */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, 0x10(%esp)\n"
        "movl $0x3f800000, 0xc(%esp)\n"
        "movss -0x19c(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x1c4(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1e4118_001e46c8\n"
        ".Lf1e4118_001e4a11:\n"
        "pxor %xmm1, %xmm1\n" /* line 271 */
        "xorl %ebx, %ebx\n" /* numHorChildren */
        "jmp .Lf1e4118_001e4629\n"
        ".Lf1e4118_001e4a1c:\n"
        "movss -0x19c(%ebp), %xmm0\n" /* line 260 */
        "movss %xmm0, -0x1d4(%ebp)\n" /* fPrevBlend */
        "movl %ebx, -0x1f4(%ebp)\n" /* numHorChildren, iPrevBlend */
        ".Lf1e4118_001e4a32:\n"
        "movl $0, 8(%esp)\n" /* line 299 */
        "movl -0x1bc(%ebp), %eax\n" /* baseAnim */
        "movl %eax, 4(%esp)\n"
        "movl -0x1c4(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimClearTreeGoalWeightsStrict\n"
        "movl -0x1b8(%ebp), %ecx\n" /* line 301 | leafAnim1 */
        "movl %ecx, 4(%esp)\n"
        "movl -0x1c4(%ebp), %ebx\n" /* pAnimTree, numHorChildren */
        "movl %ebx, (%esp)\n" /* numHorChildren */
        "calll XAnimGetWeight\n"
        "fstps -0x21c(%ebp)\n"
        "movss -0x21c(%ebp), %xmm2\n"
        "subss -0x204(%ebp), %xmm2\n"
        "andps 0x303d00, %xmm2\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "cvtsi2ssl 0x25bac(%eax), %xmm1\n"
        "movss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "divss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "pxor %xmm0, %xmm0\n" /* line 302 */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf1e4118_001e4abb\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "divss %xmm2, %xmm0\n"
        ".Lf1e4118_001e4abb:\n"
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, 0x10(%esp)\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x204(%ebp), %xmm1\n"
        "movss %xmm1, 8(%esp)\n"
        "movl -0x1b8(%ebp), %eax\n" /* leafAnim1 */
        "movl %eax, 4(%esp)\n"
        "movl -0x1c4(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "movss -0x19c(%ebp), %xmm0\n" /* line 304 */
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "jp .Lf1e4118_001e4d90\n"
        "jne .Lf1e4118_001e4d90\n"
        ".Lf1e4118_001e4b22:\n"
        "movl -0x1fc(%ebp), %eax\n" /* line 310 | i */
        "testl %eax, %eax\n"
        "je .Lf1e4118_001e4b3e\n"
        "movl -0x1f8(%ebp), %ecx\n" /* numVertChildren */
        "cmpl %ecx, -0x1fc(%ebp)\n" /* i */
        "jne .Lf1e4118_001e4e4a\n"
        ".Lf1e4118_001e4b3e:\n"
        "movl %esi, 4(%esp)\n" /* line 313 | heightAnim */
        "movl -0x1c4(%ebp), %ebx\n" /* pAnimTree, numHorChildren */
        "movl %ebx, (%esp)\n" /* numHorChildren */
        "calll XAnimGetWeight\n"
        "fstps -0x21c(%ebp)\n"
        "movss -0x21c(%ebp), %xmm2\n"
        "subss 0x2ed5d0, %xmm2\n" /* 1.0f */
        "andps 0x303d00, %xmm2\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "cvtsi2ssl 0x25bac(%eax), %xmm1\n"
        "movss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "divss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "pxor %xmm0, %xmm0\n" /* line 314 */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf1e4118_001e4ba1\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "divss %xmm2, %xmm0\n"
        ".Lf1e4118_001e4ba1:\n"
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, 0x10(%esp)\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* heightAnim */
        "movl -0x1c4(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        ".Lf1e4118_001e4be1:\n"
        "leal -0x44(%ebp), %edx\n" /* line 342 | trans */
        "movl %edx, 0xc(%esp)\n"
        "leal -0x20(%ebp), %ecx\n" /* rot */
        "movl %ecx, 8(%esp)\n"
        "movl -0x1bc(%ebp), %ebx\n" /* baseAnim, numHorChildren */
        "movl %ebx, 4(%esp)\n" /* numHorChildren */
        "movl -0x1c4(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimCalcAbsDelta\n"
        "movss -0x1e0(%ebp), %xmm0\n" /* line 343 | localYaw */
        "movss %xmm0, 4(%esp)\n"
        "leal -0x44(%ebp), %eax\n" /* trans */
        "movl %eax, (%esp)\n"
        "calll VectorAngleMultiply\n"
        "movss -0x44(%ebp), %xmm0\n" /* line 58 | trans */
        "movl -0x1c8(%ebp), %edx\n" /* tagMat */
        "addss 0x10(%edx), %xmm0\n"
        "movss %xmm0, -0xf8(%ebp)\n"
        "leal -0x11c(%ebp), %esi\n" /* line 59 | localAxis */
        "movss -0x40(%ebp), %xmm0\n"
        "addss 0x14(%edx), %xmm0\n"
        "movss %xmm0, -0xf4(%ebp)\n"
        "movss -0x1cc(%ebp), %xmm0\n" /* line 345 | tagHeight */
        "movss %xmm0, -0xf0(%ebp)\n"
        "leal -0x20(%ebp), %eax\n" /* line 347 | rot */
        "movl %eax, (%esp)\n"
        "calll RotationToYaw\n"
        "fstps -0x200(%ebp)\n"
        "movl %esi, 4(%esp)\n" /* line 349 | heightAnim */
        "movss -0x1e0(%ebp), %xmm0\n" /* localYaw */
        "addss -0x200(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll YawToAxis\n"
        "leal -0xbc(%ebp), %ebx\n" /* line 351 | axis, numHorChildren */
        "movl %ebx, 8(%esp)\n" /* numHorChildren */
        "leal -0xec(%ebp), %eax\n" /* turretAxis */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* heightAnim */
        "calll MatrixMultiply43\n"
        "movl 8(%ebp), %esi\n" /* line 353 | cent, heightAnim */
        "addl $0x1f8, %esi\n" /* heightAnim */
        "movl %esi, 4(%esp)\n" /* heightAnim */
        "movl %ebx, (%esp)\n" /* numHorChildren */
        "calll AxisToAngles\n"
        "movl -0x98(%ebp), %edx\n" /* line 199 */
        "movl -0x20c(%ebp), %ecx\n"
        "movl %edx, (%ecx)\n"
        "movl -0x94(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x90(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        "movl %edx, -0x2c(%ebp)\n" /* line 199 | start */
        "movl -0x1a8(%ebp), %ebx\n" /* line 200 | numHorChildren */
        "movl (%ebx), %eax\n" /* numHorChildren */
        "movl %eax, -0x28(%ebp)\n"
        "movl -0x1a4(%ebp), %ebx\n" /* line 201 | numHorChildren */
        "movl (%ebx), %ecx\n" /* numHorChildren */
        "movl %ecx, -0x24(%ebp)\n"
        "movl %edx, -0x38(%ebp)\n" /* line 199 | end */
        "movl %eax, -0x34(%ebp)\n" /* line 200 */
        "movl %ecx, -0x30(%ebp)\n" /* line 201 */
        "movl -0x1ec(%ebp), %edx\n" /* line 360 | pTurretCEnt */
        "movl 0x1f4(%edx), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl $0x2810011, 0x18(%esp)\n" /* line 362 */
        "movl 8(%ebp), %ecx\n" /* cent */
        "movl 0xf0(%ecx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "leal -0x38(%ebp), %eax\n" /* end */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x195ed4c, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* start */
        "movl %eax, 4(%esp)\n"
        "leal -0x8c(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll CG_TraceCapsule\n"
        "movss -0x8c(%ebp), %xmm2\n" /* line 363 | trace */
        "ucomiss 0x2ed5d0, %xmm2\n" /* 1.0f */
        "jae .Lf1e4118_001e482d\n"
        "jp .Lf1e4118_001e482d\n"
        "movss -0x24(%ebp), %xmm1\n" /* line 1205 */
        "movss -0x30(%ebp), %xmm0\n" /* line 366 */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movl 8(%ebp), %ebx\n" /* cent, numHorChildren */
        "movss %xmm1, 0x1f4(%ebx)\n" /* numHorChildren */
        "jmp .Lf1e4118_001e482d\n"
        ".Lf1e4118_001e4d90:\n"
        "movl -0x1b4(%ebp), %eax\n" /* line 306 | leafAnim2 */
        "movl %eax, 4(%esp)\n"
        "movl -0x1c4(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimGetWeight\n"
        "fstps -0x21c(%ebp)\n"
        "movss -0x21c(%ebp), %xmm2\n"
        "subss -0x19c(%ebp), %xmm2\n"
        "andps 0x303d00, %xmm2\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "cvtsi2ssl 0x25bac(%eax), %xmm1\n" /* scale */
        "movss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "divss %xmm1, %xmm0\n" /* scale */
        "mulss %xmm0, %xmm2\n"
        "pxor %xmm0, %xmm0\n" /* line 307 */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf1e4118_001e4df9\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "divss %xmm2, %xmm0\n"
        ".Lf1e4118_001e4df9:\n"
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, 0x10(%esp)\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x19c(%ebp), %xmm1\n"
        "movss %xmm1, 8(%esp)\n"
        "movl -0x1b4(%ebp), %eax\n" /* leafAnim2 */
        "movl %eax, 4(%esp)\n"
        "movl -0x1c4(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1e4118_001e4b22\n"
        ".Lf1e4118_001e4e4a:\n"
        "movss -0x1dc(%ebp), %xmm0\n" /* line 320 | fDelta */
        "subss -0x1d8(%ebp), %xmm0\n" /* fPrevTransZ */
        "movss %xmm0, -0x1d0(%ebp)\n" /* fHeightRatio */
        "movss -0x3c(%ebp), %xmm0\n"
        "subss -0x1d8(%ebp), %xmm0\n" /* fPrevTransZ */
        "movss -0x1d0(%ebp), %xmm1\n" /* fHeightRatio */
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, -0x1d0(%ebp)\n" /* fHeightRatio */
        "movl %esi, 4(%esp)\n" /* line 322 | heightAnim */
        "movl -0x1c4(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimGetWeight\n"
        "fstps -0x21c(%ebp)\n"
        "movss -0x21c(%ebp), %xmm2\n"
        "subss -0x1d0(%ebp), %xmm2\n" /* fHeightRatio */
        "andps 0x303d00, %xmm2\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "cvtsi2ssl 0x25bac(%eax), %xmm1\n"
        "movss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "divss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "pxor %xmm0, %xmm0\n" /* line 323 */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf1e4118_001e4ee6\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "divss %xmm2, %xmm0\n"
        ".Lf1e4118_001e4ee6:\n"
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, %ebx\n" /* numHorChildren */
        "movl %ebx, 0x10(%esp)\n" /* numHorChildren */
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x1d0(%ebp), %xmm0\n" /* fHeightRatio */
        "movss %xmm0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* heightAnim */
        "movl -0x1c4(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "movl -0x1fc(%ebp), %eax\n" /* line 325 | i */
        "subl $1, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x1bc(%ebp), %edx\n" /* baseAnim */
        "movl %edx, 4(%esp)\n"
        "movl -0x1c0(%ebp), %ecx\n" /* pXAnims */
        "movl %ecx, (%esp)\n"
        "calll XAnimGetChildAt\n"
        "movl %eax, %esi\n" /* heightAnim */
        "movl %eax, 4(%esp)\n" /* line 327 */
        "movl -0x1c4(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimGetWeight\n"
        "fstps -0x21c(%ebp)\n"
        "movss -0x21c(%ebp), %xmm2\n"
        "movl %ebx, -0x21c(%ebp)\n" /* numHorChildren */
        "movss -0x21c(%ebp), %xmm3\n"
        "subss -0x1d0(%ebp), %xmm3\n" /* fHeightRatio */
        "subss %xmm3, %xmm2\n"
        "andps 0x303d00, %xmm2\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "cvtsi2ssl 0x25bac(%eax), %xmm1\n"
        "movss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "divss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "pxor %xmm0, %xmm0\n" /* line 328 */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf1e4118_001e4fc9\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "divss %xmm2, %xmm0\n"
        ".Lf1e4118_001e4fc9:\n"
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, 0x10(%esp)\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss %xmm3, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* heightAnim */
        "movl -0x1c4(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "movl -0x1f4(%ebp), %ecx\n" /* line 330 | iPrevBlend */
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* heightAnim */
        "movl -0x1c0(%ebp), %ebx\n" /* pXAnims, numHorChildren */
        "movl %ebx, (%esp)\n" /* numHorChildren */
        "calll XAnimGetChildAt\n"
        "movl %eax, %ebx\n" /* numHorChildren */
        "movl %eax, 4(%esp)\n" /* line 331 */
        "movl -0x1c4(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimGetWeight\n"
        "fstps -0x21c(%ebp)\n"
        "movss -0x21c(%ebp), %xmm2\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "subss -0x1d4(%ebp), %xmm3\n" /* fPrevBlend */
        "subss %xmm3, %xmm2\n"
        "andps 0x303d00, %xmm2\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "cvtsi2ssl 0x25bac(%eax), %xmm1\n"
        "movss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "divss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "pxor %xmm0, %xmm0\n" /* line 332 */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf1e4118_001e5094\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "divss %xmm2, %xmm0\n"
        ".Lf1e4118_001e5094:\n"
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, 0x10(%esp)\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss %xmm3, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* numHorChildren */
        "movl -0x1c4(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "movss -0x1d4(%ebp), %xmm0\n" /* line 334 | fPrevBlend */
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "jp .Lf1e4118_001e50e9\n"
        "je .Lf1e4118_001e4be1\n"
        ".Lf1e4118_001e50e9:\n"
        "movl -0x1f4(%ebp), %eax\n" /* line 336 | iPrevBlend */
        "addl $1, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* heightAnim */
        "movl -0x1c0(%ebp), %eax\n" /* pXAnims */
        "movl %eax, (%esp)\n"
        "calll XAnimGetChildAt\n"
        "movl %eax, %ebx\n" /* numHorChildren */
        "movl %eax, 4(%esp)\n" /* line 337 */
        "movl -0x1c4(%ebp), %edx\n" /* pAnimTree */
        "movl %edx, (%esp)\n"
        "calll XAnimGetWeight\n"
        "fstps -0x21c(%ebp)\n"
        "movss -0x21c(%ebp), %xmm2\n"
        "subss -0x1d4(%ebp), %xmm2\n" /* fPrevBlend */
        "andps 0x303d00, %xmm2\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "cvtsi2ssl 0x25bac(%eax), %xmm1\n"
        "movss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "divss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "pxor %xmm0, %xmm0\n" /* line 338 */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf1e4118_001e516d\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "divss %xmm2, %xmm0\n"
        ".Lf1e4118_001e516d:\n"
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x3f800000, 0x10(%esp)\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x1d4(%ebp), %xmm1\n" /* fPrevBlend */
        "movss %xmm1, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* numHorChildren */
        "movl -0x1c4(%ebp), %eax\n" /* pAnimTree */
        "movl %eax, (%esp)\n"
        "calll XAnimSetGoalWeight\n"
        "jmp .Lf1e4118_001e4be1\n"
        ".Lf1e4118_001e51b8:\n"
        "movss -0x1a0(%ebp), %xmm1\n" /* line 260 */
        "movss %xmm1, -0x1d8(%ebp)\n" /* fPrevTransZ */
        "jmp .Lf1e4118_001e4a32\n"
    );
}

/* line 466 */
__attribute__((naked))
void CG_Corpse(centity_t *cent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 466 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl 8(%ebp), %esi\n" /* cent */
        /* { scope 1 */
        "leal 0xf0(%esi), %ebx\n" /* line 474 | cent, es */
        "testb $0x20, 8(%ebx)\n" /* line 479 | es */
        "je .Lf1e51ce_001e51f4\n"
        /* } scope */
        ".Lf1e51ce_001e51e9:\n"
        "addl $0xac, %esp\n" /* line 520 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e51ce_001e51f4:\n"
        "movl 0xf0(%esi), %ecx\n" /* line 482 | cent */
        "leal (%ecx, %ecx, 4), %edx\n" /* line 484 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "movl 0x195f5c4, %edx\n"
        "movl (%edx), %edx\n"
        "leal -0x6bec(%edx, %eax, 8), %edx\n"
        "movl %edx, -0x9c(%ebp)\n" /* ci */
        "movl 0x220(%esi), %eax\n" /* line 486 | cent */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll Com_GetClientDObj\n"
        "movl $0, 0xc(%esp)\n"
        "movl -0x9c(%ebp), %edx\n" /* ci */
        "movl %edx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* es */
        "movl %eax, (%esp)\n"
        "calll BG_UpdatePlayerDObj\n"
        "movl 0x220(%esi), %eax\n" /* line 488 | cent */
        "movl %eax, 4(%esp)\n"
        "movl 0xf0(%esi), %eax\n" /* cent */
        "movl %eax, (%esp)\n"
        "calll Com_GetClientDObj\n"
        "movl %eax, %edi\n" /* obj */
        "testl %eax, %eax\n" /* line 489 */
        "je .Lf1e51ce_001e51e9\n"
        "movl $0x74, 8(%esp)\n" /* line 492 */
        "movl $0, 4(%esp)\n"
        "leal -0x8c(%ebp), %eax\n" /* body */
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movb $0xff, -0x34(%ebp)\n" /* line 494 */
        "movb $0xff, -0x33(%ebp)\n" /* line 495 */
        "movb $0xff, -0x32(%ebp)\n" /* line 496 */
        "movb $0xff, -0x31(%ebp)\n" /* line 497 */
        "movl -0x9c(%ebp), %edx\n" /* line 500 | ci */
        "movl %edx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* es */
        "movl %edi, (%esp)\n" /* obj */
        "calll BG_PlayerAnimation\n"
        "leal -0x78(%ebp), %eax\n" /* line 502 */
        "movl %eax, 4(%esp)\n"
        "leal 0x1f8(%esi), %eax\n" /* cent */
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "leal 0x1ec(%esi), %eax\n" /* cent */
        /* { scope 2 */
        "movl 0x1ec(%esi), %ecx\n" /* line 199 */
        "movl %ecx, -0x50(%ebp)\n"
        "movl 4(%eax), %edx\n" /* line 200 */
        "movl %edx, -0x4c(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 201 */
        "movss %xmm0, -0x48(%ebp)\n"
        /* } scope */
        "movl %ecx, -0x84(%ebp)\n" /* line 199 */
        "movl %edx, -0x80(%ebp)\n" /* line 200 */
        "addss 0xe4(%ebx), %xmm0\n" /* line 506 | es */
        "movss %xmm0, -0x7c(%ebp)\n"
        "movl 8(%ebx), %eax\n" /* line 508 | es */
        "testb $8, %al\n"
        "jne .Lf1e51ce_001e5316\n"
        "testb $4, %al\n" /* line 510 */
        "je .Lf1e51ce_001e5358\n"
        "addss 0x2ed694, %xmm0\n" /* line 511 | 20.0f */
        "movss %xmm0, -0x7c(%ebp)\n"
        "jmp .Lf1e51ce_001e5323\n"
        ".Lf1e51ce_001e5316:\n"
        "addss 0x2ed79c, %xmm0\n" /* line 509 | 12.0f */
        "movss %xmm0, -0x7c(%ebp)\n"
        ".Lf1e51ce_001e5323:\n"
        "movl $0, -0x8c(%ebp)\n" /* line 515 | body */
        "movl $0x80, -0x88(%ebp)\n" /* line 517 */
        "movl %esi, 8(%esp)\n" /* line 519 | cent */
        "movl %edi, 4(%esp)\n" /* obj */
        "leal -0x8c(%ebp), %eax\n" /* body */
        "movl %eax, (%esp)\n"
        "calll CG_AddCEntityToScene\n"
        /* } scope */
        "addl $0xac, %esp\n" /* line 520 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e51ce_001e5358:\n"
        "addss 0x2ed830, %xmm0\n" /* line 513 | 32.0f */
        "movss %xmm0, -0x7c(%ebp)\n"
        "jmp .Lf1e51ce_001e5323\n"
    );
}

