/* ASM dump from: cg_playerstate_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_playerstate_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

void CG_Respawn(void);
void CG_DamageFeedback(int yawByte, int pitchByte, int damage);
void CG_TransitionPlayerState(playerState_t *ps, playerState_t *ops);

/* line 83 */
__attribute__((naked))
void CG_Respawn(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 83 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0x195f584, %eax\n" /* line 85 */
        "movl (%eax), %ebx\n"
        "movl $0, 0x25bbc(%ebx)\n"
        "leal 0x25bc4(%ebx), %edx\n" /* line 88 */
        "movl 0x20(%ebx), %eax\n"
        "addl $0xc, %eax\n"
        "movl $0x26a8, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl 0x25c98(%ebx), %eax\n" /* line 91 */
        "movl %eax, 0x2be50(%ebx)\n"
        "movl 0x25bb0(%ebx), %eax\n" /* line 92 */
        "movl %eax, 0x2be54(%ebx)\n"
        "movl 0x25c94(%ebx), %eax\n" /* line 93 */
        "movl %eax, 0x2be70(%ebx)\n"
        "movl $0, 0x2bde8(%ebx)\n" /* line 95 */
        "movl $0, 0x2bdec(%ebx)\n" /* line 96 */
        "movl $0, 0x2be30(%ebx)\n" /* line 97 */
        "leal 0x285d4(%ebx), %eax\n" /* line 99 | v */
        /* { scope 1 */
        "xorl %esi, %esi\n" /* line 183 */
        "movl %esi, 0x285d4(%ebx)\n"
        "movl %esi, 4(%eax)\n" /* line 184 */
        "movl %esi, 8(%eax)\n" /* line 185 */
        /* } scope */
        "leal 0x285e0(%ebx), %eax\n" /* line 100 | v */
        /* { scope 1 */
        "movl %esi, 0x285e0(%ebx)\n" /* line 183 */
        "movl %esi, 4(%eax)\n" /* line 184 */
        "movl %esi, 8(%eax)\n" /* line 185 */
        /* } scope */
        "leal 0x285ec(%ebx), %eax\n" /* line 101 | v */
        /* { scope 1 */
        "movl %esi, 0x285ec(%ebx)\n" /* line 183 */
        "movl %esi, 4(%eax)\n" /* line 184 */
        "movl %esi, 8(%eax)\n" /* line 185 */
        /* } scope */
        "leal 0x2c03c(%ebx), %eax\n" /* line 103 | v */
        /* { scope 1 */
        "movl %esi, 0x2c03c(%ebx)\n" /* line 183 */
        "movl %esi, 4(%eax)\n" /* line 184 */
        "movl %esi, 8(%eax)\n" /* line 185 */
        /* } scope */
        "leal 0x2c030(%ebx), %eax\n" /* line 104 | v */
        /* { scope 1 */
        "movl %esi, 0x2c030(%ebx)\n" /* line 183 */
        "movl %esi, 4(%eax)\n" /* line 184 */
        "movl %esi, 8(%eax)\n" /* line 185 */
        /* } scope */
        "movl %esi, 0x2bf1c(%ebx)\n" /* line 106 */
        "leal 0x28490(%ebx), %edi\n" /* line 108 */
        "cld\n"
        "movl $0xc, %ecx\n"
        "xorl %eax, %eax\n"
        "rep stosl %eax, %es:(%edi)\n"
        "movl $0, 0x2bed4(%ebx)\n" /* line 110 */
        "movl %esi, 0x2bf10(%ebx)\n" /* line 111 */
        "movl %esi, 0x2bf14(%ebx)\n" /* line 112 */
        "leal 0x2c0a4(%ebx), %eax\n" /* line 113 | v */
        /* { scope 1 */
        "movl %esi, 0x2c0a4(%ebx)\n" /* line 183 */
        "movl %esi, 4(%eax)\n" /* line 184 */
        "movl %esi, 8(%eax)\n" /* line 185 */
        /* } scope */
        "leal 0x2c0b0(%ebx), %eax\n" /* line 114 | v */
        /* { scope 1 */
        "movl %esi, 0x2c0b0(%ebx)\n" /* line 183 */
        "movl %esi, 4(%eax)\n" /* line 184 */
        "movl %esi, 8(%eax)\n" /* line 185 */
        /* } scope */
        "leal 0x2be74(%ebx), %eax\n" /* line 116 */
        "movl $0x60, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "leal 0x2c50c(%ebx), %eax\n" /* line 117 */
        "movl $0x90, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "leal 0x284c4(%ebx), %eax\n" /* line 119 | v */
        /* { scope 1 */
        "movl %esi, 0x284c4(%ebx)\n" /* line 183 */
        "movl %esi, 4(%eax)\n" /* line 184 */
        "movl %esi, 8(%eax)\n" /* line 185 */
        /* } scope */
        "movl $0, 0x2cd10(%ebx)\n" /* line 121 */
        "movl 0x195ecb4, %eax\n" /* line 124 */
        "movl (%eax), %eax\n"
        "movl $0, 8(%eax)\n"
        "movl $0, (%esp)\n" /* line 127 */
        "calll CL_SetADS\n"
        "movl 0x25c94(%ebx), %eax\n" /* line 130 */
        "movl %eax, (%esp)\n"
        "calll CG_SetEquippedOffHand\n"
        "calll CG_HoldBreathInit\n" /* line 132 */
        "addl $0x1c, %esp\n" /* line 135 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp CG_ResetLowHealthOverlay\n" /* line 134 */
    );
}

/* line 18 */
__attribute__((naked))
void CG_DamageFeedback(int yawByte, int pitchByte, int damage)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 18 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 8(%ebp), %ecx\n" /* yawByte */
        "movl 0xc(%ebp), %ebx\n" /* pitchByte */
        /* { scope 1 */
        "movl 0x195f584, %eax\n" /* line 28 */
        "movl (%eax), %edx\n"
        "movl 0x25bb0(%edx), %eax\n"
        "movl %eax, 0x2be48(%edx)\n"
        "cvtsi2ssl 0x10(%ebp), %xmm3\n" /* line 30 | damage */
        "mulss 0x2ed724, %xmm3\n" /* 0.20000000298023224f */
        "ucomiss 0x2ed6d4, %xmm3\n" /* line 32 | 5.0f */
        "jae .Lf1e173c_001e1957\n"
        "jp .Lf1e173c_001e1957\n"
        "movss 0x2ed6d4, %xmm3\n" /* 5.0f */
        "movss 0x2ed920, %xmm5\n" /* -5.0f */
        ".Lf1e173c_001e178e:\n"
        "cmpl $0xff, %ecx\n" /* line 38 */
        "je .Lf1e173c_001e1976\n"
        ".Lf1e173c_001e179a:\n"
        "cvtsi2ssl %ecx, %xmm4\n" /* line 47 */
        "movss 0x2ed5d4, %xmm2\n" /* 255.0f */
        "divss %xmm2, %xmm4\n"
        "movss 0x2ed638, %xmm1\n" /* 360.0f */
        "mulss %xmm1, %xmm4\n"
        "cvtsi2ssl %ebx, %xmm0\n" /* line 49 | i */
        "divss %xmm2, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* angles */
        "movss %xmm4, -0x2c(%ebp)\n" /* line 50 */
        "movl $0, -0x28(%ebp)\n" /* line 51 */
        "movl $0, 0xc(%esp)\n" /* line 53 */
        "movl $0, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* dir */
        "movl %eax, 4(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* angles */
        "movl %eax, (%esp)\n"
        "movss %xmm3, -0x48(%ebp)\n"
        "movss %xmm4, -0x58(%ebp)\n"
        "movss %xmm5, -0x68(%ebp)\n"
        "calll AngleVectors\n"
        "movl 0x195f584, %eax\n" /* line 55 */
        "movl (%eax), %edi\n"
        "leal 0x285a0(%edi), %eax\n"
        "movss -0x24(%ebp), %xmm1\n" /* dir */
        "mulss 0x285a0(%edi), %xmm1\n"
        "movss -0x20(%ebp), %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x68(%ebp), %xmm5\n"
        "mulss %xmm5, %xmm1\n"
        "movss %xmm1, 0x2bf14(%edi)\n"
        "leal 0x28594(%edi), %eax\n" /* line 56 */
        "movss -0x24(%ebp), %xmm1\n" /* dir */
        "mulss 0x28594(%edi), %xmm1\n"
        "movss -0x20(%ebp), %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x48(%ebp), %xmm3\n"
        "mulss %xmm3, %xmm1\n"
        "movss %xmm1, 0x2bf10(%edi)\n"
        "movl %edi, %ecx\n" /* line 61 */
        "xorl %esi, %esi\n" /* slot */
        "movl $1, %ebx\n" /* i */
        "movss -0x58(%ebp), %xmm4\n"
        ".Lf1e173c_001e1899:\n"
        "leal (%esi, %esi, 2), %edx\n" /* slot */
        "movl 0x2be80(%ecx), %eax\n"
        "cmpl 0x2be74(%edi, %edx, 4), %eax\n"
        "cmovll %ebx, %esi\n" /* i, slot */
        "addl $1, %ebx\n" /* line 59 | i */
        "addl $0xc, %ecx\n"
        "cmpl $8, %ebx\n" /* i */
        "jne .Lf1e173c_001e1899\n"
        "leal (%esi, %esi, 2), %ebx\n" /* line 65 | slot, i */
        "shll $2, %ebx\n" /* i */
        "movl 0x20(%edi), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 0x2be74(%ebx, %edi)\n" /* i */
        "movl 0x195f584, %edx\n" /* line 66 */
        "addl (%edx), %ebx\n" /* i */
        "movl 0x195f950, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 0x2be78(%ebx)\n" /* i */
        "movss %xmm4, -0x58(%ebp)\n" /* line 67 */
        "calll randomf\n"
        "fstps -0x6c(%ebp)\n"
        "movss -0x6c(%ebp), %xmm0\n"
        "subss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "mulss 0x2ed694, %xmm0\n" /* 20.0f */
        "movss -0x58(%ebp), %xmm4\n"
        "addss %xmm0, %xmm4\n"
        "movss %xmm4, (%esp)\n"
        "calll AngleNormalize360\n"
        "fstps 0x2be7c(%ebx)\n" /* i */
        "movl 0x195f584, %edx\n"
        ".Lf1e173c_001e1923:\n"
        "movl (%edx), %eax\n" /* line 70 */
        "movl 0x25bb0(%eax), %edx\n"
        "addl $0x1f4, %edx\n"
        "movl %edx, 0x2bf0c(%eax)\n"
        "movl 0x20(%eax), %edx\n" /* line 71 */
        "movl 8(%edx), %edx\n"
        "movl %edx, 0x2bed4(%eax)\n"
        "movl $0, (%esp)\n" /* line 72 */
        "calll CG_MenuShowNotify\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 73 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e173c_001e1957:\n"
        "ucomiss 0x2ed5f8, %xmm3\n" /* line 34 | 90.0f */
        "ja .Lf1e173c_001e199e\n"
        "movaps %xmm3, %xmm5\n"
        "xorps 0x303bc0, %xmm5\n"
        "cmpl $0xff, %ecx\n" /* line 38 */
        "jne .Lf1e173c_001e179a\n"
        ".Lf1e173c_001e1976:\n"
        "cmpl $0xff, %ebx\n" /* i */
        "jne .Lf1e173c_001e179a\n"
        "movl 0x195f584, %edx\n" /* line 40 */
        "movl (%edx), %eax\n"
        "movl $0, 0x2bf14(%eax)\n"
        "movss %xmm5, 0x2bf10(%eax)\n" /* line 41 */
        "jmp .Lf1e173c_001e1923\n"
        ".Lf1e173c_001e199e:\n"
        "movss 0x2ed5f8, %xmm3\n" /* line 34 | 90.0f */
        "movss 0x2ed660, %xmm5\n" /* -90.0f */
        "jmp .Lf1e173c_001e178e\n"
    );
}

/* line 173 */
__attribute__((naked))
void CG_TransitionPlayerState(playerState_t *ps, playerState_t *ops)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 173 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* ps */
        "movl 0x11c(%esi), %eax\n" /* line 176 | ps */
        "movl 0xc(%ebp), %edx\n" /* ops */
        "cmpl 0x11c(%edx), %eax\n"
        "je .Lf1e19b4_001e19db\n"
        "movl 0x128(%esi), %eax\n" /* ps */
        "testl %eax, %eax\n"
        "jne .Lf1e19b4_001e1a59\n"
        /* { scope 1 */
        ".Lf1e19b4_001e19db:\n"
        "movl 0x195f584, %eax\n" /* line 149 */
        "movl (%eax), %edi\n" /* cent */
        "addl $0x2826c, %edi\n" /* cent */
        "movl 0xa4(%esi), %ebx\n" /* line 151 | i */
        "subl $4, %ebx\n" /* i */
        "jmp .Lf1e19b4_001e1a36\n"
        ".Lf1e19b4_001e19f3:\n"
        "subl $4, %eax\n" /* line 154 */
        "cmpl %eax, %ebx\n" /* i */
        "jle .Lf1e19b4_001e1a2b\n"
        "movl %ebx, %eax\n" /* i */
        "andl $3, %eax\n"
        "movl 0xa8(%esi, %eax, 4), %edx\n"
        "movl 0xc(%ebp), %ecx\n" /* ops */
        "cmpl 0xa8(%ecx, %eax, 4), %edx\n"
        "je .Lf1e19b4_001e1a2b\n"
        ".Lf1e19b4_001e1a12:\n"
        "movl 0xb8(%esi, %eax, 4), %eax\n" /* line 160 */
        "movl %eax, 0x190(%edi)\n" /* cent */
        "movl %edx, 4(%esp)\n" /* line 161 */
        "movl %edi, (%esp)\n" /* cent */
        "calll CG_EntityEvent\n"
        ".Lf1e19b4_001e1a2b:\n"
        "addl $1, %ebx\n" /* line 151 | i */
        "cmpl 0xa4(%esi), %ebx\n" /* i */
        "jge .Lf1e19b4_001e1a51\n"
        ".Lf1e19b4_001e1a36:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 154 | ops */
        "movl 0xa4(%ecx), %eax\n"
        "cmpl %eax, %ebx\n" /* i */
        "jl .Lf1e19b4_001e19f3\n"
        "movl %ebx, %eax\n" /* i */
        "andl $3, %eax\n"
        "movl 0xa8(%esi, %eax, 4), %edx\n"
        "jmp .Lf1e19b4_001e1a12\n"
        /* } scope */
        ".Lf1e19b4_001e1a51:\n"
        "addl $0x1c, %esp\n" /* line 183 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1e19b4_001e1a59:\n"
        "movl %eax, 8(%esp)\n" /* line 178 */
        "movl 0x124(%esi), %eax\n" /* ps */
        "movl %eax, 4(%esp)\n"
        "movl 0x120(%esi), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "calll CG_DamageFeedback\n"
        "jmp .Lf1e19b4_001e19db\n"
    );
}

