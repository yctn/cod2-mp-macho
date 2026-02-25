/* ASM dump from: g_team_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_team_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

qboolean OnSameTeam(gentity_t *ent1, gentity_t *ent2);
short int TeamplayInfoMessage(gentity_t *ent);
short int CheckTeamStatus(void);

/* line 11 */
__attribute__((naked))
qboolean OnSameTeam(gentity_t *ent1, gentity_t *ent2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 11 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 13 | ent1 */
        "movl 0x158(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1c9944_001c9973\n"
        "movl 0xc(%ebp), %ecx\n" /* ent2 */
        "movl 0x158(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1c9944_001c9973\n"
        "movl 0x274c(%eax), %eax\n" /* line 18 */
        "testl %eax, %eax\n"
        "je .Lf1c9944_001c9973\n"
        "cmpl 0x274c(%edx), %eax\n" /* line 21 */
        "je .Lf1c9944_001c9977\n"
        ".Lf1c9944_001c9973:\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n" /* line 27 */
        "retl\n"
        ".Lf1c9944_001c9977:\n"
        "movl $1, %eax\n" /* line 21 */
        "popl %ebp\n" /* line 27 */
        "retl\n"
    );
}

/* line 37 */
__attribute__((naked))
short int TeamplayInfoMessage(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 37 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl 8(%ebp), %edi\n" /* ent */
        /* { scope 1 */
        "movl 0x158(%edi), %eax\n" /* line 49 | ent */
        "movl 0x26a8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf1c997e_001c9b00\n"
        "movl 0x274c(%eax), %edx\n" /* line 51 */
        "testl %edx, %edx\n"
        "jne .Lf1c997e_001c99d0\n"
        "movl $0xffffffff, 0x138(%eax)\n" /* line 53 */
        "movl 0x158(%edi), %eax\n" /* line 54 | ent */
        "movl $0, 0x13c(%eax)\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 87 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c997e_001c99d0:\n"
        "leal -0x30(%ebp), %ebx\n" /* line 58 | vStart */
        "movl %ebx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ent */
        "calll G_GetPlayerViewOrigin\n"
        "movl $0, 0xc(%esp)\n" /* line 59 */
        "movl $0, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* vForward */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ent */
        "calll G_GetPlayerViewDirection\n"
        "movss 0x2eda0c, %xmm1\n" /* line 288 | 8192.0f */
        "movss -0x24(%ebp), %xmm0\n" /* vForward */
        "mulss %xmm1, %xmm0\n"
        "addss -0x30(%ebp), %xmm0\n" /* vStart */
        "movss %xmm0, -0x3c(%ebp)\n" /* vEnd */
        "movss -0x20(%ebp), %xmm0\n" /* line 289 */
        "mulss %xmm1, %xmm0\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "mulss -0x1c(%ebp), %xmm1\n" /* line 290 */
        "addss -0x28(%ebp), %xmm1\n"
        "movss %xmm1, -0x34(%ebp)\n"
        "movl 0x158(%edi), %edx\n" /* ent */
        ".Lf1c997e_001c9a41:\n"
        "movl $0x2000001, 0x18(%esp)\n" /* line 72 */
        "movl 0xcc(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* vEnd */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x195ed4c, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "leal -0x60(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll G_TraceCapsule\n"
        "movzwl -0x44(%ebp), %esi\n" /* line 73 | identEnt */
        "cmpl $0x3f, %esi\n" /* line 75 | identEnt */
        "jg .Lf1c997e_001c9ad6\n"
        "leal (%esi, %esi, 4), %eax\n" /* identEnt */
        "leal (, %eax, 8), %ebx\n"
        "subl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "addl 0x195f688, %ebx\n"
        "leal 0x150(%ebx), %eax\n"
        "movl %eax, -0x6c(%ebp)\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1c997e_001c9ad6\n"
        "movl %edi, (%esp)\n" /* ent */
        "calll G_IsPlaying\n"
        "testl %eax, %eax\n"
        "je .Lf1c997e_001c9b9b\n"
        "movl -0x6c(%ebp), %edx\n"
        "movl 8(%edx), %eax\n"
        "movl 0x158(%edi), %edx\n" /* ent */
        "movl 0x274c(%eax), %eax\n"
        "cmpl 0x274c(%edx), %eax\n"
        "jne .Lf1c997e_001c9adc\n"
        ".Lf1c997e_001c9ace:\n"
        "movl 0x194(%ebx), %ecx\n" /* line 77 */
        "jmp .Lf1c997e_001c9ae3\n"
        ".Lf1c997e_001c9ad6:\n"
        "movl 0x158(%edi), %edx\n" /* ent */
        ".Lf1c997e_001c9adc:\n"
        "movl $0xffffffff, %esi\n" /* identEnt */
        "xorl %ecx, %ecx\n"
        ".Lf1c997e_001c9ae3:\n"
        "movl %esi, 0x138(%edx)\n" /* line 85 | identEnt */
        "movl 0x158(%edi), %eax\n" /* line 86 | ent */
        "movl %ecx, 0x13c(%eax)\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 87 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c997e_001c9b00:\n"
        "leal -0x30(%ebp), %ebx\n" /* line 65 | vStart */
        "movl %ebx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ent */
        "calll G_GetPlayerViewOrigin\n"
        "movl $0, 0xc(%esp)\n" /* line 66 */
        "movl $0, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* vForward */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ent */
        "calll G_GetPlayerViewDirection\n"
        "movl 0x158(%edi), %edx\n" /* line 68 | ent */
        "movss 0xf8(%edx), %xmm0\n"
        "movss 0x2ed740, %xmm1\n" /* 8.0f */
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf1c997e_001c9b8b\n"
        ".Lf1c997e_001c9b49:\n"
        "movss 0x2eda0c, %xmm0\n" /* line 288 | 8192.0f */
        "movss -0x24(%ebp), %xmm1\n" /* vForward */
        "mulss %xmm0, %xmm1\n"
        "addss -0x30(%ebp), %xmm1\n" /* vStart */
        "movss %xmm1, -0x3c(%ebp)\n" /* vEnd */
        "movss -0x20(%ebp), %xmm1\n" /* line 289 */
        "mulss %xmm0, %xmm1\n"
        "addss -0x2c(%ebp), %xmm1\n"
        "movss %xmm1, -0x38(%ebp)\n"
        "mulss -0x1c(%ebp), %xmm0\n" /* line 290 */
        "addss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "jmp .Lf1c997e_001c9a41\n"
        ".Lf1c997e_001c9b8b:\n"
        "subss %xmm0, %xmm1\n" /* line 69 */
        "addss -0x28(%ebp), %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "jmp .Lf1c997e_001c9b49\n"
        ".Lf1c997e_001c9b9b:\n"
        "movl 0x158(%edi), %edx\n" /* ent */
        "jmp .Lf1c997e_001c9ace\n"
    );
}

/* line 90 */
__attribute__((naked))
short int CheckTeamStatus(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 90 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 0x195f6a0, %edx\n" /* line 95 */
        "movl 0x1ec(%edx), %ecx\n"
        "movl %ecx, %eax\n"
        "subl 0x20c(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf1c9ba6_001c9c3a\n"
        "movl %ecx, 0x20c(%edx)\n" /* line 97 */
        "movl 0x195f6c0, %edx\n" /* line 99 */
        "movl (%edx), %eax\n"
        "movl 8(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jle .Lf1c9ba6_001c9c3a\n"
        "xorl %esi, %esi\n" /* i */
        "movl 0x195f688, %ebx\n"
        "addl $0xfc, %ebx\n"
        "movl 0x195f688, %edi\n"
        "movl %edx, -0x1c(%ebp)\n"
        "jmp .Lf1c9ba6_001c9c0b\n"
        ".Lf1c9ba6_001c9bf5:\n"
        "addl $1, %esi\n" /* i */
        "addl $0x230, %ebx\n"
        "addl $0x230, %edi\n"
        "movl (%edx), %eax\n"
        "cmpl 8(%eax), %esi\n" /* i */
        "jge .Lf1c9ba6_001c9c3a\n"
        ".Lf1c9ba6_001c9c0b:\n"
        "cmpb $0, (%ebx)\n" /* line 102 */
        "je .Lf1c9ba6_001c9bf5\n"
        "movl 0x5c(%ebx), %eax\n"
        "testb $0x40, 0xe(%eax)\n"
        "jne .Lf1c9ba6_001c9bf5\n"
        "movl %edi, (%esp)\n" /* line 104 */
        "calll TeamplayInfoMessage\n"
        "movl -0x1c(%ebp), %edx\n"
        "addl $1, %esi\n" /* line 99 | i */
        "addl $0x230, %ebx\n"
        "addl $0x230, %edi\n"
        "movl (%edx), %eax\n"
        "cmpl 8(%eax), %esi\n" /* i */
        "jl .Lf1c9ba6_001c9c0b\n"
        /* } scope */
        ".Lf1c9ba6_001c9c3a:\n"
        "addl $0x2c, %esp\n" /* line 108 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

