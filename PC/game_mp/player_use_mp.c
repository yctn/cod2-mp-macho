/* ASM dump from: player_use_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/player_use_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

void Player_UpdateActivate(gentity_t *ent);
static int compare_use(const void *pe1, const void *pe2);
static int Player_GetUseList(gentity_t *ent, useList_t *useList);
void Player_UpdateCursorHints(gentity_t *ent);
void Player_UpdateLookAtEntity(gentity_t *ent);

/* line 150 */
__attribute__((naked))
void Player_UpdateActivate(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 150 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* ent */
        /* { scope 1 */
        "movl 0x158(%esi), %eax\n" /* line 157 | ent */
        "andl $0xfffffff7, 0xc(%eax)\n"
        "movl 0x158(%esi), %edx\n" /* line 159 | ent */
        "movl 0xd8(%edx), %eax\n"
        "subl $0x11, %eax\n"
        "cmpl $5, %eax\n"
        "jbe .Lf1ca060_001ca1cd\n"
        "cmpl $0x3ff, 0x2830(%edx)\n" /* line 165 */
        "je .Lf1ca060_001ca0b0\n"
        "testb $0x20, 0x27c0(%edx)\n" /* line 167 */
        "je .Lf1ca060_001ca0b0\n"
        "testb $0x20, 0x27bc(%edx)\n"
        "je .Lf1ca060_001ca229\n"
        ".Lf1ca060_001ca0b0:\n"
        "testb $0x28, 0x27c4(%edx)\n" /* line 174 */
        "jne .Lf1ca060_001ca1d5\n"
        ".Lf1ca060_001ca0bd:\n"
        "xorl %eax, %eax\n" /* line 109 */
        ".Lf1ca060_001ca0bf:\n"
        "cmpl $0x3ff, 0x2830(%edx)\n" /* line 178 */
        "je .Lf1ca060_001ca218\n"
        ".Lf1ca060_001ca0cf:\n"
        "testb $0x28, 0x27bc(%edx)\n" /* line 186 */
        "je .Lf1ca060_001ca1cd\n"
        "movl $1, (%esp)\n" /* line 125 */
        "calll Scr_IsSystemActive\n"
        "testl %eax, %eax\n"
        "je .Lf1ca060_001ca1cd\n"
        "movl 0x158(%esi), %ebx\n" /* line 128 */
        "movl 0x2830(%ebx), %edi\n" /* use */
        "cmpl $0x3ff, %edi\n" /* use */
        "je .Lf1ca060_001ca1cd\n"
        "movl 0x195f6a0, %eax\n" /* line 132 */
        "movl 0x1ec(%eax), %ecx\n"
        "movl %ecx, %edx\n"
        "subl 0x28a0(%ebx), %edx\n"
        "movl 0x195f774, %eax\n"
        "movl (%eax), %eax\n"
        "cmpl 8(%eax), %edx\n"
        "jl .Lf1ca060_001ca1cd\n"
        "subl 0x2834(%ebx), %ecx\n" /* line 135 */
        "movl 0x195f77c, %eax\n"
        "movl (%eax), %eax\n"
        "cmpl 8(%eax), %ecx\n"
        "jl .Lf1ca060_001ca1cd\n"
        "leal (%edi, %edi, 4), %eax\n" /* line 138 | use */
        "leal (, %eax, 8), %ebx\n"
        "subl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "addl 0x195f688, %ebx\n"
        /* { scope 2: touch */
        /* { scope 3 */
        "movzbl 0x166(%ebx), %eax\n" /* line 43 */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "addl 0x195f6b4, %eax\n"
        "movl 0x10(%eax), %edi\n" /* use */
        "movl 0xc(%eax), %eax\n" /* line 44 */
        "movl %eax, -0x1c(%ebp)\n" /* touch */
        "movl 4(%ebx), %eax\n" /* line 47 */
        "cmpl $3, %eax\n"
        "je .Lf1ca060_001ca263\n"
        "cmpl $9, %eax\n" /* line 60 */
        "je .Lf1ca060_001ca301\n"
        ".Lf1ca060_001ca187:\n"
        "movl %esi, (%esp)\n" /* line 62 */
        "calll Scr_AddEntity\n"
        "movl $1, 8(%esp)\n" /* line 63 */
        "movl 0x195f5bc, %eax\n"
        "movzwl 0x54(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Scr_Notify\n"
        "testl %edi, %edi\n" /* line 65 | use */
        "je .Lf1ca060_001ca1bd\n"
        "movl %esi, 8(%esp)\n" /* line 66 */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll *%edi\n" /* use */
        ".Lf1ca060_001ca1bd:\n"
        "movl 0x158(%esi), %eax\n" /* line 70 */
        "movl $0x3ff, 0x2830(%eax)\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1ca060_001ca1cd:\n"
        "addl $0x2c, %esp\n" /* line 188 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1ca060_001ca1d5:\n"
        "movl $1, (%esp)\n" /* line 83 */
        "calll Scr_IsSystemActive\n"
        "testl %eax, %eax\n"
        "je .Lf1ca060_001ca235\n"
        "movl 0x158(%esi), %eax\n" /* line 86 */
        "movl $0x3ff, 0x2830(%eax)\n"
        "cmpb $0, 0x162(%esi)\n" /* line 89 */
        "jne .Lf1ca060_001ca240\n"
        "movl 0x158(%esi), %edx\n" /* line 99 */
        "testb $4, 0xc(%edx)\n"
        "je .Lf1ca060_001ca2c2\n"
        "movl $1, %eax\n"
        "jmp .Lf1ca060_001ca0bf\n"
        ".Lf1ca060_001ca218:\n"
        "testb %al, %al\n" /* line 178 */
        "jne .Lf1ca060_001ca0cf\n"
        "testb $0x20, 0x27c4(%edx)\n" /* line 180 */
        "je .Lf1ca060_001ca1cd\n"
        ".Lf1ca060_001ca229:\n"
        "orl $8, 0xc(%edx)\n" /* line 181 */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 188 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1ca060_001ca235:\n"
        "movl 0x158(%esi), %edx\n" /* ent */
        "jmp .Lf1ca060_001ca0bd\n"
        /* { scope 1 */
        ".Lf1ca060_001ca240:\n"
        "movl 0x158(%esi), %edx\n" /* line 91 */
        "testl $0x300, 0xa0(%edx)\n"
        "je .Lf1ca060_001ca2b1\n"
        "movb $2, 0x162(%esi)\n" /* line 92 */
        "movl $1, %eax\n"
        "jmp .Lf1ca060_001ca0bf\n"
        /* { scope 2: touch */
        /* { scope 3 */
        ".Lf1ca060_001ca263:\n"
        "movl %esi, (%esp)\n" /* line 49 */
        "calll Scr_AddEntity\n"
        "movl $1, 8(%esp)\n" /* line 50 */
        "movl 0x195f5bc, %eax\n"
        "movzwl 0x52(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Scr_Notify\n"
        "movb $1, 0x162(%ebx)\n" /* line 52 */
        "movl -0x1c(%ebp), %eax\n" /* line 54 | touch */
        "testl %eax, %eax\n"
        "je .Lf1ca060_001ca1bd\n"
        "movl $0, 8(%esp)\n" /* line 55 */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll *-0x1c(%ebp)\n" /* touch */
        "jmp .Lf1ca060_001ca1bd\n"
        /* } scope */
        /* } scope */
        ".Lf1ca060_001ca2b1:\n"
        "movb $0, 0x162(%esi)\n" /* line 94 */
        "movl $1, %eax\n"
        "jmp .Lf1ca060_001ca0bf\n"
        ".Lf1ca060_001ca2c2:\n"
        "movl 0x5a0(%edx), %eax\n" /* line 103 */
        "cmpl $0x3ff, %eax\n"
        "je .Lf1ca060_001ca0bd\n"
        "movl %eax, 0x2830(%edx)\n" /* line 108 */
        "movl 0x158(%esi), %eax\n" /* line 109 */
        "movl 0x195f6a0, %edx\n"
        "movl 0x1ec(%edx), %edx\n"
        "movl %edx, 0x2834(%eax)\n"
        "movl $1, %eax\n"
        "movl 0x158(%esi), %edx\n"
        "jmp .Lf1ca060_001ca0bf\n"
        /* { scope 2: touch */
        /* { scope 3 */
        ".Lf1ca060_001ca301:\n"
        "movl %esi, 4(%esp)\n" /* line 60 */
        "movl %ebx, (%esp)\n"
        "calll G_IsTurretUsable\n"
        "testl %eax, %eax\n"
        "je .Lf1ca060_001ca1bd\n"
        "jmp .Lf1ca060_001ca187\n"
    );
}

/* line 194 */
static __attribute__((naked))
int compare_use(const void *pe1, const void *pe2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 194 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* pe1, pe2 */
        "movss 4(%eax), %xmm0\n"
        "movl 0xc(%ebp), %eax\n" /* pe2 */
        "subss 4(%eax), %xmm0\n"
        "cvttss2si %xmm0, %eax\n" /* pe2 */
        "popl %ebp\n" /* line 200 */
        "retl\n"
    );
}

/* line 206 */
static __attribute__((naked))
int Player_GetUseList(gentity_t *ent, useList_t *useList)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 206 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10cc, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 230 | ent */
        "movl 0x158(%eax), %eax\n"
        "movl %eax, -0x1090(%ebp)\n" /* ps */
        "leal -0x48(%ebp), %edx\n" /* line 233 | origin */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll G_GetPlayerViewOrigin\n"
        "movl $0, 0xc(%esp)\n" /* line 234 */
        "movl $0, 8(%esp)\n"
        "leal -0x6c(%ebp), %eax\n" /* forward */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* ent */
        "movl %edx, (%esp)\n"
        "calll G_GetPlayerViewDirection\n"
        "movl -0x1090(%ebp), %eax\n" /* line 236 | ps, b */
        "addl $0x56c, %eax\n" /* b */
        /* { scope 2 */
        "movl -0x1090(%ebp), %edx\n" /* line 240 | ps */
        "movss 0x14(%edx), %xmm0\n"
        "addss 0x56c(%edx), %xmm0\n"
        "movss %xmm0, -0x78(%ebp)\n" /* playerMin */
        "movss 0x18(%edx), %xmm0\n" /* line 241 */
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x74(%ebp)\n"
        "movss 0x1c(%edx), %xmm0\n" /* line 242 */
        "addss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x70(%ebp)\n"
        "movl %edx, %eax\n"
        "addl $0x578, %eax\n"
        /* } scope */
        /* { scope 2 */
        "movss 0x14(%edx), %xmm0\n" /* line 240 */
        "addss 0x578(%edx), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* playerMax */
        "movss 0x18(%edx), %xmm0\n" /* line 241 */
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss 0x1c(%edx), %xmm0\n" /* line 242 */
        "addss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        /* } scope */
        "movss -0x48(%ebp), %xmm3\n" /* line 248 | origin */
        "movss 0x2eda10, %xmm4\n" /* 192.0f */
        "movaps %xmm3, %xmm0\n"
        "subss %xmm4, %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* mins */
        "movss -0x44(%ebp), %xmm2\n" /* line 249 */
        "movaps %xmm2, %xmm0\n"
        "subss %xmm4, %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss -0x40(%ebp), %xmm1\n" /* line 250 */
        "movss 0x2eda14, %xmm5\n" /* 96.0f */
        "movaps %xmm1, %xmm0\n"
        "subss %xmm5, %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "addss %xmm4, %xmm3\n" /* line 240 */
        "movss %xmm3, -0x3c(%ebp)\n" /* maxs */
        "addss %xmm4, %xmm2\n" /* line 241 */
        "movss %xmm2, -0x38(%ebp)\n"
        "addss %xmm5, %xmm1\n" /* line 242 */
        "movss %xmm1, -0x34(%ebp)\n"
        "movl $0x200000, 0x10(%esp)\n"
        "movl $0x400, 0xc(%esp)\n"
        "leal -0x1078(%ebp), %eax\n" /* touch */
        "movl %eax, 8(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* maxs */
        "movl %eax, 4(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* mins */
        "movl %eax, (%esp)\n"
        "calll CM_AreaEntities\n"
        "movl %eax, -0x108c(%ebp)\n" /* num */
        "testl %eax, %eax\n" /* line 246 */
        "jg .Lf1ca334_001ca518\n"
        "xorl %eax, %eax\n"
        "movl $0, -0x1080(%ebp)\n"
        ".Lf1ca334_001ca49f:\n"
        "movl $compare_use, 0xc(%esp)\n" /* line 303 */
        "movl $8, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* useList */
        "movl %eax, (%esp)\n"
        "calll qsort\n"
        "movl -0x1080(%ebp), %edx\n" /* line 337 */
        "testl %edx, %edx\n"
        "jg .Lf1ca334_001ca6f3\n"
        "movl $0, -0x1088(%ebp)\n" /* invalidUseCount */
        ".Lf1ca334_001ca4d6:\n"
        "movl $compare_use, 0xc(%esp)\n" /* line 357 */
        "movl $8, 8(%esp)\n"
        "movl -0x1080(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* useList */
        "movl %edx, (%esp)\n"
        "calll qsort\n"
        "movl -0x1088(%ebp), %eax\n" /* invalidUseCount */
        "subl %eax, -0x1080(%ebp)\n"
        /* } scope */
        "movl -0x1080(%ebp), %eax\n" /* line 362 */
        "addl $0x10cc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1ca334_001ca518:\n"
        "xorl %esi, %esi\n" /* line 246 | i */
        "movl $0, -0x1084(%ebp)\n" /* ignoredFullItems */
        "movl $0, -0x107c(%ebp)\n"
        "movl 0xc(%ebp), %edi\n" /* useList */
        ".Lf1ca334_001ca531:\n"
        "movl -0x1078(%ebp, %esi, 4), %eax\n" /* line 250 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* hit */
        "subl %eax, %ebx\n" /* hit */
        "shll $4, %ebx\n" /* hit */
        "addl 0x195f688, %ebx\n" /* hit */
        "cmpl %ebx, 8(%ebp)\n" /* line 252 | hit, ent */
        "je .Lf1ca334_001ca594\n"
        "cmpl $3, 4(%ebx)\n" /* line 255 | hit */
        "je .Lf1ca334_001ca561\n"
        "testb $0x20, 0x11e(%ebx)\n" /* hit */
        "je .Lf1ca334_001ca594\n"
        ".Lf1ca334_001ca561:\n"
        "movzwl 0x168(%ebx), %eax\n" /* line 258 | hit */
        "movl 0x195f5bc, %edx\n"
        "cmpw 0x58(%edx), %ax\n"
        "jne .Lf1ca334_001ca5b8\n"
        "movss 0x120(%ebx), %xmm0\n" /* line 260 | hit */
        "ucomiss -0x24(%ebp), %xmm0\n" /* playerMax */
        "ja .Lf1ca334_001ca594\n"
        "movss -0x78(%ebp), %xmm0\n" /* playerMin */
        "ucomiss 0x12c(%ebx), %xmm0\n" /* hit */
        "jbe .Lf1ca334_001ca80f\n"
        ".Lf1ca334_001ca594:\n"
        "addl $1, %esi\n" /* line 246 | i */
        "cmpl %esi, -0x108c(%ebp)\n" /* i, num */
        "jne .Lf1ca334_001ca531\n"
        ".Lf1ca334_001ca59f:\n"
        "movl -0x107c(%ebp), %eax\n"
        "movl %eax, %edx\n"
        "subl -0x1084(%ebp), %edx\n" /* ignoredFullItems */
        "movl %edx, -0x1080(%ebp)\n"
        "jmp .Lf1ca334_001ca49f\n"
        ".Lf1ca334_001ca5b8:\n"
        "leal 0x120(%ebx), %eax\n" /* line 269 | hit */
        "leal 0x12c(%ebx), %edx\n" /* hit */
        /* { scope 2 */
        "movss 0x120(%ebx), %xmm0\n" /* line 240 | hit */
        "addss 0x12c(%ebx), %xmm0\n" /* hit */
        "movss %xmm0, -0x54(%ebp)\n" /* usePos */
        "movss 4(%eax), %xmm1\n" /* line 241 */
        "addss 4(%edx), %xmm1\n"
        "movss %xmm1, -0x50(%ebp)\n"
        "movss 8(%eax), %xmm2\n" /* line 242 */
        "addss 8(%edx), %xmm2\n"
        /* } scope */
        "mulss 0x2ed5d8, %xmm0\n" /* line 272 | 0.5f */
        "movss %xmm0, -0x54(%ebp)\n" /* usePos */
        "mulss 0x2ed5d8, %xmm1\n" /* line 273 | 0.5f */
        "movss %xmm1, -0x50(%ebp)\n"
        "mulss 0x2ed5d8, %xmm2\n" /* line 274 | 0.5f */
        "movss %xmm2, -0x4c(%ebp)\n"
        "subss -0x48(%ebp), %xmm0\n" /* line 248 | origin */
        "movss %xmm0, -0x60(%ebp)\n" /* useDir */
        "subss -0x44(%ebp), %xmm1\n" /* line 249 */
        "movss %xmm1, -0x5c(%ebp)\n"
        "subss -0x40(%ebp), %xmm2\n" /* line 250 */
        "movss %xmm2, -0x58(%ebp)\n"
        "leal -0x60(%ebp), %eax\n" /* line 276 | useDir */
        "movl %eax, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstps -0x10ac(%ebp)\n"
        "movss -0x10ac(%ebp), %xmm2\n"
        "ucomiss 0x2ed7cc, %xmm2\n" /* line 277 | 128.0f */
        "ja .Lf1ca334_001ca594\n"
        "movss -0x60(%ebp), %xmm1\n" /* line 283 | useDir */
        "mulss -0x6c(%ebp), %xmm1\n" /* forward */
        "movss -0x5c(%ebp), %xmm0\n"
        "mulss -0x68(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x58(%ebp), %xmm0\n"
        "mulss -0x64(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "addss %xmm0, %xmm1\n"
        "mulss 0x2ed63c, %xmm1\n" /* -0.5f */
        "addss %xmm0, %xmm1\n"
        "mulss 0x2ed8b0, %xmm1\n" /* 256.0f */
        "movss %xmm1, 4(%edi)\n"
        "movzwl 0x168(%ebx), %eax\n" /* line 286 | hit */
        "movl 0x195f5bc, %edx\n"
        "cmpw 0x56(%edx), %ax\n"
        "je .Lf1ca334_001ca88d\n"
        ".Lf1ca334_001ca6bf:\n"
        "cmpl $3, 4(%ebx)\n" /* line 290 | hit */
        "je .Lf1ca334_001ca8a2\n"
        ".Lf1ca334_001ca6c9:\n"
        "movl %ebx, (%edi)\n" /* line 299 | hit */
        "addss 4(%edi), %xmm2\n" /* line 300 */
        "movss %xmm2, 4(%edi)\n"
        "addl $1, -0x107c(%ebp)\n" /* line 301 */
        "addl $8, %edi\n"
        "addl $1, %esi\n" /* line 246 | i */
        "cmpl %esi, -0x108c(%ebp)\n" /* i, num */
        "jne .Lf1ca334_001ca531\n"
        "jmp .Lf1ca334_001ca59f\n"
        ".Lf1ca334_001ca6f3:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 337 | useList, hit */
        "xorl %edi, %edi\n"
        "movl $0, -0x1088(%ebp)\n" /* invalidUseCount */
        "jmp .Lf1ca334_001ca76a\n"
        ".Lf1ca334_001ca704:\n"
        "leal -0x54(%ebp), %esi\n" /* usePos, i */
        ".Lf1ca334_001ca707:\n"
        "movl $0x11, 0x14(%esp)\n" /* line 351 */
        "movl -0x1090(%ebp), %edx\n" /* ps */
        "movl 0xcc(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n" /* i */
        "movl 0x195ed4c, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x48(%ebp), %edx\n" /* origin */
        "movl %edx, (%esp)\n"
        "calll G_TraceCapsuleComplete\n"
        "testl %eax, %eax\n"
        "jne .Lf1ca334_001ca758\n"
        "movss 4(%ebx), %xmm0\n" /* line 354 | hit */
        "addss 0x2eda18, %xmm0\n" /* 10000.0f */
        "movss %xmm0, 4(%ebx)\n" /* hit */
        "addl $1, -0x1088(%ebp)\n" /* line 355 | invalidUseCount */
        ".Lf1ca334_001ca758:\n"
        "addl $1, %edi\n" /* line 337 */
        "addl $8, %ebx\n" /* hit */
        "cmpl -0x1080(%ebp), %edi\n"
        "je .Lf1ca334_001ca4d6\n"
        ".Lf1ca334_001ca76a:\n"
        "movl (%ebx), %ecx\n" /* line 339 | hit */
        "movzwl 0x168(%ecx), %eax\n" /* line 341 */
        "movl 0x195f5bc, %edx\n"
        "cmpw 0x58(%edx), %ax\n"
        "je .Lf1ca334_001ca758\n"
        "leal 0x120(%ecx), %eax\n" /* line 342 */
        "leal 0x12c(%ecx), %edx\n"
        /* { scope 2 */
        "movss 0x120(%ecx), %xmm2\n" /* line 240 */
        "addss 0x12c(%ecx), %xmm2\n"
        "movss %xmm2, -0x54(%ebp)\n" /* usePos */
        "movss 4(%eax), %xmm0\n" /* line 241 */
        "addss 4(%edx), %xmm0\n"
        "movss %xmm0, -0x50(%ebp)\n"
        "movss 8(%eax), %xmm1\n" /* line 242 */
        "addss 8(%edx), %xmm1\n"
        /* } scope */
        "mulss 0x2ed5d8, %xmm2\n" /* line 272 | 0.5f */
        "movss %xmm2, -0x54(%ebp)\n" /* usePos */
        "mulss 0x2ed5d8, %xmm0\n" /* line 273 | 0.5f */
        "movss %xmm0, -0x50(%ebp)\n"
        "mulss 0x2ed5d8, %xmm1\n" /* line 274 | 0.5f */
        "movss %xmm1, -0x4c(%ebp)\n"
        "cmpl $9, 4(%ecx)\n" /* line 348 */
        "jne .Lf1ca334_001ca704\n"
        "leal -0x54(%ebp), %esi\n" /* line 349 | usePos, i */
        "movl %esi, 8(%esp)\n" /* i */
        "movl 0x195f5bc, %edx\n"
        "movzwl 0x9e(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll G_DObjGetWorldTagPos\n"
        "jmp .Lf1ca334_001ca707\n"
        ".Lf1ca334_001ca80f:\n"
        "movss 0x124(%ebx), %xmm0\n" /* line 260 | hit */
        "ucomiss -0x20(%ebp), %xmm0\n"
        "ja .Lf1ca334_001ca594\n"
        "movss -0x74(%ebp), %xmm0\n"
        "ucomiss 0x130(%ebx), %xmm0\n" /* hit */
        "ja .Lf1ca334_001ca594\n"
        "movss 0x128(%ebx), %xmm0\n" /* hit */
        "ucomiss -0x1c(%ebp), %xmm0\n"
        "ja .Lf1ca334_001ca594\n"
        "movss -0x70(%ebp), %xmm0\n"
        "ucomiss 0x134(%ebx), %xmm0\n" /* hit */
        "ja .Lf1ca334_001ca594\n"
        "movl %ebx, 8(%esp)\n" /* line 263 | hit */
        "leal -0x24(%ebp), %eax\n" /* playerMax */
        "movl %eax, 4(%esp)\n"
        "leal -0x78(%ebp), %eax\n" /* playerMin */
        "movl %eax, (%esp)\n"
        "calll SV_EntityContact\n"
        "testl %eax, %eax\n"
        "je .Lf1ca334_001ca594\n"
        "movl $0xc3800000, 4(%edi)\n" /* line 266 */
        "movl %ebx, (%edi)\n" /* line 267 | hit */
        "addl $1, -0x107c(%ebp)\n" /* line 268 */
        "addl $8, %edi\n"
        "jmp .Lf1ca334_001ca594\n"
        ".Lf1ca334_001ca88d:\n"
        "movaps %xmm1, %xmm0\n" /* line 287 */
        "subss 0x2ed8b0, %xmm0\n" /* 256.0f */
        "movss %xmm0, 4(%edi)\n"
        "jmp .Lf1ca334_001ca6bf\n"
        ".Lf1ca334_001ca8a2:\n"
        "movl $0, 8(%esp)\n" /* line 292 */
        "movl 8(%ebp), %edx\n" /* ent */
        "movl 0x158(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* hit */
        "movss %xmm2, -0x10a8(%ebp)\n"
        "calll BG_CanItemBeGrabbed\n"
        "testl %eax, %eax\n"
        "movss -0x10a8(%ebp), %xmm2\n"
        "jne .Lf1ca334_001ca6c9\n"
        "movss 4(%edi), %xmm0\n" /* line 294 */
        "addss 0x2eda18, %xmm0\n" /* 10000.0f */
        "movss %xmm0, 4(%edi)\n"
        "addl $1, -0x1084(%ebp)\n" /* line 295 | ignoredFullItems */
        "jmp .Lf1ca334_001ca6c9\n"
    );
}

/* line 428 */
__attribute__((naked))
void Player_UpdateCursorHints(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 428 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x202c, %esp\n"
        "movl 8(%ebp), %edi\n" /* ent */
        /* { scope 1: client */
        "movl 0x158(%edi), %ebx\n" /* line 441 | ent, ps */
        "movl $0, 0x598(%ebx)\n" /* line 443 | ps */
        "movl $0xffffffff, 0x59c(%ebx)\n" /* line 444 | ps */
        "movl $0x3ff, 0x5a0(%ebx)\n" /* line 445 | ps */
        "movl 0x194(%edi), %ecx\n" /* line 447 | ent */
        "testl %ecx, %ecx\n"
        "jle .Lf1ca8f6_001ca95a\n"
        "movl 0x158(%edi), %esi\n" /* line 450 | ent, hintType */
        "movl 0xd8(%esi), %eax\n" /* hintType */
        "subl $0x11, %eax\n"
        "cmpl $5, %eax\n"
        "jbe .Lf1ca8f6_001ca95a\n"
        "cmpb $0, 0x162(%edi)\n" /* line 453 | ent */
        "jne .Lf1ca8f6_001ca965\n"
        "testb $4, 0xc(%esi)\n" /* line 460 | hintType */
        "je .Lf1ca8f6_001ca9df\n"
        /* } scope */
        ".Lf1ca8f6_001ca95a:\n"
        "addl $0x202c, %esp\n" /* line 531 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: client */
        ".Lf1ca8f6_001ca965:\n"
        "testl $0x300, 0xa0(%ebx)\n" /* line 455 | ps */
        "je .Lf1ca8f6_001ca95a\n"
        /* { scope 2 */
        "movl 0x594(%esi), %eax\n" /* line 413 | item */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* turret */
        "subl %eax, %ebx\n" /* turret */
        "shll $4, %ebx\n" /* turret */
        "movl 0x195f6a0, %eax\n"
        "addl 4(%eax), %ebx\n" /* turret */
        "movl 0xc8(%ebx), %eax\n" /* line 416 | turret */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl 0x570(%eax), %eax\n"
        "cmpb $0, (%eax)\n"
        "je .Lf1ca8f6_001ca95a\n"
        "movl $0x3ff, 0x5a0(%esi)\n" /* line 418 | item */
        "movl 0xc8(%ebx), %eax\n" /* line 419 | turret */
        "addl $4, %eax\n"
        "movl %eax, 0x598(%esi)\n" /* item */
        "movl 0xc8(%ebx), %eax\n" /* line 420 | turret */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl 0x578(%eax), %eax\n"
        "movl %eax, 0x59c(%esi)\n" /* item */
        "jmp .Lf1ca8f6_001ca95a\n"
        /* } scope */
        ".Lf1ca8f6_001ca9df:\n"
        "leal -0x2018(%ebp), %eax\n" /* line 463 | useList */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ent */
        "calll Player_GetUseList\n"
        "movl %eax, -0x2024(%ebp)\n" /* numUsable */
        "cmpl $0, %eax\n" /* line 464 */
        "je .Lf1ca8f6_001ca95a\n"
        "jle .Lf1ca8f6_001ca95a\n" /* line 472 */
        "movl $0, -0x2020(%ebp)\n" /* line 464 | i */
        "jmp .Lf1ca8f6_001caa7f\n"
        ".Lf1ca8f6_001caa12:\n"
        "cmpl $9, %eax\n" /* line 478 */
        "je .Lf1ca8f6_001cab4a\n"
        "testl %eax, %eax\n"
        "jne .Lf1ca8f6_001caa66\n"
        "movzwl 0x168(%edx), %eax\n" /* line 482 */
        "movl 0x195f5bc, %ecx\n"
        "cmpw 0x56(%ecx), %ax\n"
        "je .Lf1ca8f6_001caa3c\n"
        "cmpw 0x58(%ecx), %ax\n"
        "jne .Lf1ca8f6_001cabfc\n"
        ".Lf1ca8f6_001caa3c:\n"
        "movl -0x2028(%ebp), %esi\n" /* line 484 | traceEnt, hintType */
        "movzbl 0x167(%esi), %eax\n" /* hintType */
        "testb %al, %al\n"
        "je .Lf1ca8f6_001caba6\n"
        "movzbl %al, %edx\n"
        "movl 0x158(%edi), %eax\n" /* ent */
        "cmpl 0x274c(%eax), %edx\n"
        "je .Lf1ca8f6_001cabf4\n"
        ".Lf1ca8f6_001caa66:\n"
        "addl $1, -0x2020(%ebp)\n" /* line 472 | i */
        "movl -0x2020(%ebp), %esi\n" /* i, hintType */
        "cmpl %esi, -0x2024(%ebp)\n" /* hintType, numUsable */
        "je .Lf1ca8f6_001ca95a\n"
        ".Lf1ca8f6_001caa7f:\n"
        "movl -0x2020(%ebp), %eax\n" /* line 474 | i */
        "movl -0x2018(%ebp, %eax, 8), %eax\n"
        "movl %eax, -0x2028(%ebp)\n" /* traceEnt */
        "movl %eax, %edx\n" /* line 478 */
        "movl 4(%eax), %eax\n"
        "cmpl $3, %eax\n"
        "jne .Lf1ca8f6_001caa12\n"
        "movl 0x158(%edi), %ecx\n" /* line 504 | ent */
        "movl %ecx, -0x201c(%ebp)\n" /* client */
        /* { scope 2 */
        /* { scope 3 */
        "movl -0x2028(%ebp), %esi\n" /* line 374 | traceEnt, item */
        "movzwl 0x1ac(%esi), %eax\n" /* item */
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "leal (, %edx, 4), %esi\n" /* item */
        "addl 0x195eda8, %esi\n" /* item */
        "cmpl $1, 0x1c(%esi)\n" /* line 378 | item */
        "jne .Lf1ca8f6_001caa66\n"
        "movl 0x20(%esi), %eax\n" /* line 382 | item */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "cmpl $1, 0x78(%eax)\n" /* line 384 */
        "je .Lf1ca8f6_001caa66\n"
        "movl 0x20(%esi), %edx\n" /* line 387 | item */
        "movl %edx, %eax\n"
        "sarl $5, %eax\n"
        "movl %edx, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl -0x201c(%ebp), %esi\n" /* client, item */
        "movl 0x544(%esi, %eax, 4), %eax\n" /* item */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf1ca8f6_001caa66\n"
        /* } scope */
        /* } scope */
        "movl %edx, %eax\n" /* line 509 */
        "addl $4, %eax\n"
        "je .Lf1ca8f6_001caa66\n"
        "movl %eax, %esi\n" /* line 510 | hintType */
        "movl $0xffffffff, %edx\n"
        ".Lf1ca8f6_001cab19:\n"
        "movl -0x2028(%ebp), %ecx\n" /* line 519 | traceEnt */
        "movl (%ecx), %eax\n"
        "movl %eax, 0x5a0(%ebx)\n" /* ps */
        "movl %esi, 0x598(%ebx)\n" /* line 520 | hintType, ps */
        "movl %edx, 0x59c(%ebx)\n" /* line 521 | ps */
        "testl %esi, %esi\n" /* line 524 | hintType */
        "jne .Lf1ca8f6_001ca95a\n"
        "movl $0x3ff, 0x5a0(%ebx)\n" /* line 525 | ps */
        "jmp .Lf1ca8f6_001ca95a\n"
        ".Lf1ca8f6_001cab4a:\n"
        "movl %edi, 4(%esp)\n" /* line 498 | ent */
        "movl -0x2028(%ebp), %esi\n" /* traceEnt, hintType */
        "movl %esi, (%esp)\n" /* hintType */
        "calll G_IsTurretUsable\n"
        "testl %eax, %eax\n"
        "je .Lf1ca8f6_001caa66\n"
        "movl 0xc8(%esi), %eax\n" /* line 501 | hintType */
        "leal 4(%eax), %esi\n" /* hintType */
        "movl %eax, (%esp)\n" /* line 503 */
        "calll BG_GetWeaponDef\n"
        "movl 0x56c(%eax), %eax\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf1ca8f6_001cab87\n"
        ".Lf1ca8f6_001cab80:\n"
        "movl $0xffffffff, %edx\n" /* line 510 */
        "jmp .Lf1ca8f6_001cab19\n"
        ".Lf1ca8f6_001cab87:\n"
        "movl -0x2028(%ebp), %edx\n" /* line 504 | traceEnt */
        "movl 0xc8(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl 0x574(%eax), %edx\n"
        "jmp .Lf1ca8f6_001cab19\n"
        ".Lf1ca8f6_001caba6:\n"
        "movl %esi, %eax\n" /* hintType */
        ".Lf1ca8f6_001caba8:\n"
        "movl 0x1b4(%eax), %edx\n" /* line 487 */
        "cmpl $0x3ff, %edx\n"
        "je .Lf1ca8f6_001cac08\n"
        "movl 0x158(%edi), %eax\n" /* ent */
        "cmpl 0xcc(%eax), %edx\n"
        "jne .Lf1ca8f6_001caa66\n"
        "movl -0x2028(%ebp), %edx\n" /* traceEnt */
        ".Lf1ca8f6_001cabce:\n"
        "movl 0xdc(%edx), %esi\n" /* line 490 | hintType */
        "testl %esi, %esi\n" /* line 492 | hintType */
        "je .Lf1ca8f6_001cab80\n"
        "movl 0xd8(%edx), %edx\n"
        "cmpl $0xff, %edx\n"
        "jne .Lf1ca8f6_001cab19\n"
        "movl $0xffffffff, %edx\n" /* line 510 */
        "jmp .Lf1ca8f6_001cab19\n"
        ".Lf1ca8f6_001cabf4:\n"
        "movl -0x2028(%ebp), %eax\n" /* traceEnt */
        "jmp .Lf1ca8f6_001caba8\n"
        ".Lf1ca8f6_001cabfc:\n"
        "xorl %esi, %esi\n" /* line 482 | hintType */
        "movl $0xffffffff, %edx\n"
        "jmp .Lf1ca8f6_001cab19\n"
        ".Lf1ca8f6_001cac08:\n"
        "movl %eax, %edx\n"
        "jmp .Lf1ca8f6_001cabce\n"
    );
}

/* line 562 */
__attribute__((naked))
void Player_UpdateLookAtEntity(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 562 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ent */
        /* { scope 1: contactEnd, vis, vis */
        "movl 0x158(%ebx), %esi\n" /* line 579 | ent, ps */
        "andl $0xffcfffff, 0xc(%esi)\n" /* line 580 | ps */
        "movl 0x158(%ebx), %eax\n" /* line 582 | ent */
        "movl $0, 0x282c(%eax)\n"
        "leal -0x24(%ebp), %eax\n" /* line 584 | start */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ent */
        "calll G_GetPlayerViewOrigin\n"
        "movl $0, 0xc(%esp)\n" /* line 585 */
        "movl $0, 8(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* forward */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ent */
        "calll G_GetPlayerViewDirection\n"
        "testl $0x300, 0xa0(%esi)\n" /* line 587 | ps */
        "je .Lf1cac0c_001cad52\n"
        "movl 0x594(%esi), %eax\n" /* line 591 | ps */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl 0x195f688, %edx\n"
        "movl 0xc8(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl %eax, -0x84(%ebp)\n" /* weapDef */
        ".Lf1cac0c_001caca5:\n"
        "movl 0x158(%ebx), %eax\n" /* line 598 | ent */
        "movl 0xd4(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1cac0c_001cacc9\n"
        "movl -0x84(%ebp), %eax\n" /* weapDef */
        "movl 0x31c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1cac0c_001cad71\n"
        ".Lf1cac0c_001cacc9:\n"
        "movl 0x195f734, %edi\n" /* line 601 | pPriorityMap */
        ".Lf1cac0c_001caccf:\n"
        "movss -0x3c(%ebp), %xmm0\n" /* line 288 | forward */
        "mulss 0x2ed848, %xmm0\n" /* 15000.0f */
        "addss -0x24(%ebp), %xmm0\n" /* start */
        "movss %xmm0, -0x30(%ebp)\n" /* end */
        "movss -0x38(%ebp), %xmm0\n" /* line 289 */
        "mulss 0x2ed848, %xmm0\n" /* 15000.0f */
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss -0x34(%ebp), %xmm0\n" /* line 290 */
        "mulss 0x2ed848, %xmm0\n" /* 15000.0f */
        "addss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        /* { scope 2 */
        "movl %edi, 0x14(%esp)\n" /* line 545 */
        "movl $0x22802801, 0x10(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* end */
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* start */
        "movl %eax, 4(%esp)\n"
        "leal -0x6c(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll G_LocationalTrace\n"
        "cmpw $0x3fd, -0x50(%ebp)\n" /* line 546 */
        "jbe .Lf1cac0c_001cad7c\n"
        /* } scope */
        /* } scope */
        ".Lf1cac0c_001cad47:\n"
        "addl $0x9c, %esp\n" /* line 657 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: contactEnd, vis, vis */
        ".Lf1cac0c_001cad52:\n"
        "movl 0x158(%ebx), %eax\n" /* line 595 | ent */
        "movl 0xd4(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl %eax, -0x84(%ebp)\n" /* weapDef */
        "jmp .Lf1cac0c_001caca5\n"
        ".Lf1cac0c_001cad71:\n"
        "movl 0x195f760, %edi\n" /* line 599 | pPriorityMap */
        "jmp .Lf1cac0c_001caccf\n"
        /* { scope 2 */
        ".Lf1cac0c_001cad7c:\n"
        "movss -0x6c(%ebp), %xmm1\n" /* line 549 | trace, scale */
        "mulss 0x2ed848, %xmm1\n" /* 15000.0f, scale */
        /* { scope 3 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x3c(%ebp), %xmm0\n" /* forward */
        "addss -0x24(%ebp), %xmm0\n" /* start */
        "movss %xmm0, -0x48(%ebp)\n" /* contactEnd */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x38(%ebp), %xmm0\n"
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "mulss -0x34(%ebp), %xmm1\n" /* line 290 */
        "addss -0x1c(%ebp), %xmm1\n"
        "movss %xmm1, -0x40(%ebp)\n"
        /* } scope */
        "leal -0x48(%ebp), %eax\n" /* line 551 | contactEnd */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* start */
        "movl %eax, (%esp)\n"
        "calll SV_FX_GetVisibility\n"
        "fstps -0x80(%ebp)\n" /* vis */
        "movss -0x80(%ebp), %xmm0\n" /* line 552 | vis */
        "ucomiss 0x2ed724, %xmm0\n" /* 0.20000000298023224f */
        "jp .Lf1cac0c_001cade5\n"
        "jb .Lf1cac0c_001cad47\n"
        ".Lf1cac0c_001cade5:\n"
        "movzwl -0x50(%ebp), %eax\n" /* line 555 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "movl 0x195f688, %eax\n"
        "movl %eax, -0x88(%ebp)\n"
        /* } scope */
        "movl %eax, %ecx\n" /* line 610 */
        "addl %edx, %ecx\n"
        "je .Lf1cac0c_001cad47\n"
        "movzwl 0x168(%ecx), %edx\n" /* line 613 */
        "movl 0x195f5bc, %eax\n"
        "cmpw 0x5c(%eax), %dx\n"
        "je .Lf1cac0c_001caec5\n"
        ".Lf1cac0c_001cae23:\n"
        "cmpl $1, 4(%ecx)\n" /* line 625 */
        "jne .Lf1cac0c_001cad47\n"
        "testb $0x10, -0x5c(%ebp)\n" /* line 627 */
        "jne .Lf1cac0c_001cad47\n"
        "leal 0x138(%ecx), %eax\n" /* line 628 */
        /* { scope 2 */
        "movss 0x138(%ecx), %xmm1\n" /* line 248 */
        "subss -0x24(%ebp), %xmm1\n" /* start */
        "movss 4(%eax), %xmm2\n" /* line 249 */
        "subss -0x20(%ebp), %xmm2\n"
        "movss 8(%eax), %xmm3\n" /* line 250 */
        "subss -0x1c(%ebp), %xmm3\n"
        /* } scope */
        "movl 0x158(%ecx), %eax\n" /* line 633 */
        "movl 0x274c(%eax), %eax\n"
        "movl 0x158(%ebx), %edx\n" /* ent */
        "cmpl 0x274c(%edx), %eax\n"
        "je .Lf1cac0c_001cafa1\n"
        ".Lf1cac0c_001cae7c:\n"
        "movl -0x84(%ebp), %eax\n" /* line 646 | weapDef */
        "movss 0x260(%eax), %xmm0\n"
        "mulss %xmm1, %xmm1\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "mulss %xmm3, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss %xmm0, %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf1cac0c_001cad47\n"
        "movl 0x282c(%edx), %ebx\n" /* line 648 | ent */
        "testl %ebx, %ebx\n" /* ent */
        "je .Lf1cac0c_001cb001\n"
        ".Lf1cac0c_001caeb9:\n"
        "orl $0x200000, 0xc(%esi)\n" /* line 651 | ps */
        "jmp .Lf1cac0c_001cad47\n"
        ".Lf1cac0c_001caec5:\n"
        "movl 0x158(%ebx), %eax\n" /* line 615 | ent */
        "movl %ecx, 0x282c(%eax)\n"
        "movl %ebx, 4(%esp)\n" /* line 616 | ent */
        "movl %ecx, (%esp)\n"
        "calll G_Trigger\n"
        /* { scope 2 */
        "movl %edi, 0x14(%esp)\n" /* line 545 */
        "movl $0x2802801, 0x10(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* end */
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* start */
        "movl %eax, 4(%esp)\n"
        "leal -0x6c(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll G_LocationalTrace\n"
        "cmpw $0x3fd, -0x50(%ebp)\n" /* line 546 */
        "ja .Lf1cac0c_001cad47\n"
        "movss 0x2ed848, %xmm1\n" /* line 549 | 15000.0f, scale */
        "mulss -0x6c(%ebp), %xmm1\n" /* trace, scale */
        /* { scope 3 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x3c(%ebp), %xmm0\n" /* forward */
        "addss -0x24(%ebp), %xmm0\n" /* start */
        "movss %xmm0, -0x48(%ebp)\n" /* contactEnd */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x38(%ebp), %xmm0\n"
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "mulss -0x34(%ebp), %xmm1\n" /* line 290 */
        "addss -0x1c(%ebp), %xmm1\n"
        "movss %xmm1, -0x40(%ebp)\n"
        /* } scope */
        "leal -0x48(%ebp), %eax\n" /* line 551 | contactEnd */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* start */
        "movl %eax, (%esp)\n"
        "calll SV_FX_GetVisibility\n"
        "fstps -0x7c(%ebp)\n" /* vis */
        "movss 0x2ed724, %xmm0\n" /* line 552 | 0.20000000298023224f */
        "ucomiss -0x7c(%ebp), %xmm0\n" /* vis */
        "ja .Lf1cac0c_001cad47\n"
        "movzwl -0x50(%ebp), %edx\n" /* line 555 */
        "leal (%edx, %edx, 4), %edx\n"
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "shll $4, %eax\n"
        /* } scope */
        "movl -0x88(%ebp), %ecx\n" /* line 621 */
        "addl %eax, %ecx\n"
        "jne .Lf1cac0c_001cae23\n"
        "jmp .Lf1cac0c_001cad47\n"
        ".Lf1cac0c_001cafa1:\n"
        "testl %eax, %eax\n" /* line 633 */
        "je .Lf1cac0c_001cae7c\n"
        "mulss %xmm1, %xmm1\n" /* line 316 */
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "mulss %xmm3, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "movl 0x195f778, %eax\n" /* line 636 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "mulss %xmm0, %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf1cac0c_001cafdc\n"
        "movl 0x282c(%edx), %edi\n" /* pPriorityMap */
        "testl %edi, %edi\n" /* pPriorityMap */
        "je .Lf1cac0c_001cb00c\n"
        ".Lf1cac0c_001cafdc:\n"
        "movl 0x195f770, %eax\n" /* line 640 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "mulss %xmm0, %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf1cac0c_001cad47\n"
        "orl $0x100000, 0xc(%esi)\n" /* line 641 | ps */
        "jmp .Lf1cac0c_001cad47\n"
        ".Lf1cac0c_001cb001:\n"
        "movl %ecx, 0x282c(%edx)\n" /* line 649 */
        "jmp .Lf1cac0c_001caeb9\n"
        ".Lf1cac0c_001cb00c:\n"
        "movl %ecx, 0x282c(%edx)\n" /* line 637 */
        "jmp .Lf1cac0c_001cafdc\n"
    );
}

