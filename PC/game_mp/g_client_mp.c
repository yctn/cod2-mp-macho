/* ASM dump from: g_client_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_client_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

extern vec3_t playerMins; /* 0x0 */
extern vec3_t playerMaxs; /* 0x0 */

void G_GetPlayerViewDirection(const gentity_t *ent, vec_t *forward, vec_t *right, vec_t *up);
void ClientBegin(int clientNum);
void ClientDisconnect(int clientNum);
int G_GetNonPVSFriendlyInfo(gentity_t *pSelf, vec_t *vPosition, int iLastUpdateEnt);
void G_BroadcastVoice(gentity_t *talker, VoicePacket_t *voicePacket);
void SetClientViewAngle(gentity_t *ent, const vec_t *angle);
void ClientSpawn(gentity_t *ent, const vec_t *spawn_origin, const vec_t *spawn_angles);
void G_GetPlayerViewOrigin(const gentity_t *ent, vec_t *origin);
void ClientUserinfoChanged(int clientNum);
char * ClientConnect(int clientNum, int scriptPersId);

/* line 156 */
__attribute__((naked))
void G_GetPlayerViewDirection(const gentity_t *ent, vec_t *forward, vec_t *right, vec_t *up)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 156 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 161 | ent */
        "movl 0x158(%eax), %eax\n"
        "addl $0xe8, %eax\n"
        "movl %eax, 8(%ebp)\n" /* ent */
        "popl %ebp\n" /* line 162 */
        "jmp AngleVectors\n" /* line 161 */
    );
}

/* line 426 */
__attribute__((naked))
void ClientBegin(int clientNum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 426 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* clientNum */
        /* { scope 1 */
        "leal (%edx, %edx, 4), %ebx\n" /* line 430 */
        "movl %ebx, %eax\n"
        "shll $6, %eax\n"
        "leal (%ebx, %eax), %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl 0x195f6a0, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl $2, 0x26c4(%eax)\n" /* line 432 */
        "movl $4, 4(%eax)\n" /* line 433 */
        "calll CalculateRanks\n" /* line 435 */
        "movl $0, 8(%esp)\n" /* line 437 */
        "movl 0x195f5bc, %eax\n"
        "movzwl 0x6c(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal (, %ebx, 8), %eax\n"
        "subl %ebx, %eax\n"
        "shll $4, %eax\n"
        "addl 0x195f688, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Notify\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 438 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 596 */
__attribute__((naked))
void ClientDisconnect(int clientNum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 596 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %eax\n" /* clientNum */
        "movl %eax, -0x24(%ebp)\n" /* clientNum */
        /* { scope 1 */
        "movl 0x195f6a0, %edi\n" /* line 602 */
        "leal (%eax, %eax, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $6, %eax\n"
        "leal (%ecx, %eax), %eax\n"
        "movl -0x24(%ebp), %edx\n" /* clientNum */
        "leal (%edx, %eax, 8), %eax\n"
        "movl (%edi), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* client */
        "leal (, %ecx, 8), %eax\n" /* line 603 */
        "subl %ecx, %eax\n"
        "shll $4, %eax\n"
        "movl 0x195f688, %ecx\n"
        "movl %ecx, -0x28(%ebp)\n"
        "addl %ecx, %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* ent */
        "movl $1, (%esp)\n" /* line 607 */
        "calll Scr_IsSystemActive\n"
        "testl %eax, %eax\n"
        "jne .Lf190658_0019077c\n"
        ".Lf190658_001906b4:\n"
        "movl 0x1e4(%edi), %ebx\n" /* line 617 */
        "testl %ebx, %ebx\n"
        "jle .Lf190658_00190712\n"
        "xorl %esi, %esi\n" /* i */
        "xorl %ebx, %ebx\n"
        "movl %edi, %edx\n"
        "movl %edi, -0x2c(%ebp)\n"
        "movl -0x28(%ebp), %edi\n"
        "jmp .Lf190658_001906e3\n"
        ".Lf190658_001906cc:\n"
        "addl $1, %esi\n" /* i */
        "addl $0x230, %edi\n"
        "addl $0x28a4, %ebx\n"
        "cmpl 0x1e4(%edx), %esi\n" /* i */
        "jge .Lf190658_00190712\n"
        ".Lf190658_001906e3:\n"
        "movl %ebx, %eax\n" /* line 619 */
        "addl (%edx), %eax\n"
        "movl 0x26c4(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf190658_001906cc\n"
        "cmpl $2, 0x26a8(%eax)\n" /* line 622 */
        "jne .Lf190658_001906cc\n"
        "movl -0x24(%ebp), %ecx\n" /* clientNum */
        "cmpl 0x27a8(%eax), %ecx\n"
        "jne .Lf190658_001906cc\n"
        "movl %edi, (%esp)\n" /* line 623 */
        "calll StopFollowing\n"
        "movl -0x2c(%ebp), %edx\n"
        "jmp .Lf190658_001906cc\n"
        ".Lf190658_00190712:\n"
        "movl -0x20(%ebp), %eax\n" /* line 630 | ent */
        "movl %eax, (%esp)\n"
        "calll HudElem_ClientDisconnect\n"
        "movl $1, (%esp)\n" /* line 631 */
        "calll Scr_IsSystemActive\n"
        "testl %eax, %eax\n"
        "je .Lf190658_00190738\n"
        "movl -0x20(%ebp), %edx\n" /* line 633 | ent */
        "movl %edx, (%esp)\n"
        "calll Scr_PlayerDisconnect\n"
        ".Lf190658_00190738:\n"
        "movl -0x20(%ebp), %ecx\n" /* line 635 | ent */
        "movl %ecx, (%esp)\n"
        "calll G_FreeEntity\n"
        "movl -0x1c(%ebp), %eax\n" /* line 637 | client */
        "movl $0, 0x26c4(%eax)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 638 | client */
        "addl $0x2748, %eax\n"
        "movl $0x5c, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 641 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CalculateRanks\n" /* line 640 */
        ".Lf190658_0019077c:\n"
        "movl $0x228e90, (%esp)\n" /* line 611 */
        "calll Scr_AddString\n"
        "movl $0x2b015c, (%esp)\n" /* line 612 */
        "calll Scr_AddString\n"
        "movl $2, 8(%esp)\n" /* line 613 */
        "movl 0x195f5bc, %eax\n"
        "movzwl 0x70(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x20(%ebp), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll Scr_Notify\n"
        "jmp .Lf190658_001906b4\n"
    );
}

/* line 651 */
__attribute__((naked))
int G_GetNonPVSFriendlyInfo(gentity_t *pSelf, vec_t *vPosition, int iLastUpdateEnt)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 651 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %edx\n" /* line 663 | pSelf */
        "movl 0x158(%edx), %eax\n"
        "movl 0x274c(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* team */
        "testl %eax, %eax\n" /* line 664 */
        "je .Lf1907ba_0019084f\n"
        "cmpl $3, %eax\n"
        "je .Lf1907ba_0019084f\n"
        "cmpl $0x3ff, 0x10(%ebp)\n" /* line 667 | iLastUpdateEnt */
        "je .Lf1907ba_00190985\n"
        "movl 0x10(%ebp), %edi\n" /* line 670 | iLastUpdateEnt, iBaseEnt */
        "addl $1, %edi\n" /* iBaseEnt */
        ".Lf1907ba_001907f1:\n"
        "xorl %esi, %esi\n" /* iEntCount */
        "jmp .Lf1907ba_0019083a\n"
        ".Lf1907ba_001907f5:\n"
        "leal (%eax, %eax, 4), %eax\n" /* line 675 */
        "leal (, %eax, 8), %ebx\n" /* pEnt */
        "subl %eax, %ebx\n" /* pEnt */
        "shll $4, %ebx\n" /* pEnt */
        "addl 0x195f688, %ebx\n" /* pEnt */
        "cmpb $0, 0xfc(%ebx)\n" /* line 676 | pEnt */
        "je .Lf1907ba_00190832\n"
        "movl 0x158(%ebx), %eax\n" /* line 678 | pEnt */
        "testl %eax, %eax\n"
        "je .Lf1907ba_00190832\n"
        "movl 0x26a8(%eax), %edx\n" /* line 680 */
        "testl %edx, %edx\n"
        "jne .Lf1907ba_00190832\n"
        "movl -0x1c(%ebp), %edx\n" /* line 682 | team */
        "cmpl 0x274c(%eax), %edx\n"
        "je .Lf1907ba_0019085b\n"
        ".Lf1907ba_00190832:\n"
        "addl $1, %esi\n" /* line 672 | iEntCount */
        "cmpl $0x40, %esi\n" /* iEntCount */
        "je .Lf1907ba_0019084f\n"
        ".Lf1907ba_0019083a:\n"
        "leal (%edi, %esi), %eax\n" /* line 675 | iBaseEnt */
        "andl $0x8000003f, %eax\n"
        "jns .Lf1907ba_001907f5\n"
        "subl $1, %eax\n"
        "orl $0xffffffc0, %eax\n"
        "addl $1, %eax\n"
        "jmp .Lf1907ba_001907f5\n"
        ".Lf1907ba_0019084f:\n"
        "xorl %ecx, %ecx\n" /* line 672 */
        /* } scope */
        ".Lf1907ba_00190851:\n"
        "movl %ecx, %eax\n" /* line 740 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1907ba_0019085b:\n"
        "cmpl %ebx, 8(%ebp)\n" /* line 684 | pEnt, pSelf */
        "je .Lf1907ba_00190832\n"
        "movl (%ebx), %eax\n" /* line 686 | pEnt */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* vPosition */
        "movl %eax, (%esp)\n"
        "calll SV_inSnapshot\n"
        "testl %eax, %eax\n"
        "jne .Lf1907ba_00190832\n"
        "movl (%ebx), %ecx\n" /* line 690 | pEnt */
        "movss 0x138(%ebx), %xmm0\n" /* line 694 | pEnt */
        "movl 0xc(%ebp), %edx\n" /* vPosition */
        "subss (%edx), %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "cvttss2si %xmm0, %eax\n"
        "movss 0x13c(%ebx), %xmm0\n" /* line 695 | pEnt */
        "subss 4(%edx), %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "cvttss2si %xmm0, %edx\n"
        "cmpl $0x400, %eax\n" /* line 698 */
        "jle .Lf1907ba_0019098c\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 699 */
        "movss 0x2ed960, %xmm2\n" /* 1024.0f */
        "divss %xmm0, %xmm2\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        ".Lf1907ba_001908ce:\n"
        "cmpl $0x400, %edx\n" /* line 702 */
        "jle .Lf1907ba_001909b5\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 703 */
        "movss 0x2ed960, %xmm1\n" /* 1024.0f */
        "divss %xmm0, %xmm1\n"
        ".Lf1907ba_001908ea:\n"
        "ucomiss %xmm2, %xmm3\n" /* line 706 */
        "ja .Lf1907ba_001909d6\n"
        "ucomiss %xmm1, %xmm3\n"
        "ja .Lf1907ba_001909d6\n"
        ".Lf1907ba_001908fc:\n"
        "cmpl $0x400, %eax\n" /* line 719 */
        "jle .Lf1907ba_001909c5\n"
        "movl $0x402, %eax\n"
        ".Lf1907ba_0019090c:\n"
        "cmpl $0x400, %edx\n" /* line 723 */
        "jle .Lf1907ba_001909a3\n"
        "movl $0x402, %esi\n" /* iEntCount */
        ".Lf1907ba_0019091d:\n"
        "andl $0xffff803f, %ecx\n" /* line 732 */
        "leal 3(%eax), %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "sarl $2, %eax\n"
        "addl $0xff, %eax\n"
        "andl $0x1ff, %eax\n"
        "shll $6, %eax\n"
        "orl %eax, %ecx\n"
        "andl $0xff007fff, %ecx\n"
        "movl %esi, %eax\n" /* iEntCount */
        "leal 3(%esi), %edx\n" /* iEntCount */
        "cmpl $-1, %esi\n" /* iEntCount */
        "cmovlel %edx, %eax\n"
        "sarl $2, %eax\n"
        "addl $0xff, %eax\n"
        "andl $0x1ff, %eax\n"
        "shll $0xf, %eax\n"
        "orl %eax, %ecx\n"
        "andl $0xffffff, %ecx\n"
        "movss 0x148(%ebx), %xmm0\n" /* pEnt */
        "mulss 0x2ed974, %xmm0\n" /* 0.7111111283302307f */
        "cvttss2si %xmm0, %eax\n"
        "shll $0x18, %eax\n"
        "orl %eax, %ecx\n"
        "jmp .Lf1907ba_00190851\n"
        ".Lf1907ba_00190985:\n"
        "xorl %edi, %edi\n" /* line 667 | iBaseEnt */
        "jmp .Lf1907ba_001907f1\n"
        ".Lf1907ba_0019098c:\n"
        "cmpl $0xfffffc02, %eax\n" /* line 700 */
        "jl .Lf1907ba_001909ec\n"
        "movss 0x2ed5d0, %xmm2\n" /* 1.0f */
        "movaps %xmm2, %xmm3\n"
        "jmp .Lf1907ba_001908ce\n"
        ".Lf1907ba_001909a3:\n"
        "cmpl $0xfffffc02, %edx\n" /* line 725 */
        "jge .Lf1907ba_00190a09\n"
        "movl $0xfffffc04, %esi\n" /* iEntCount */
        "jmp .Lf1907ba_0019091d\n"
        ".Lf1907ba_001909b5:\n"
        "cmpl $0xfffffc02, %edx\n" /* line 704 */
        "jl .Lf1907ba_00190a19\n"
        "movaps %xmm3, %xmm1\n"
        "jmp .Lf1907ba_001908ea\n"
        ".Lf1907ba_001909c5:\n"
        "cmpl $0xfffffc02, %eax\n" /* line 721 */
        "jge .Lf1907ba_00190a11\n"
        "movl $0xfffffc04, %eax\n"
        "jmp .Lf1907ba_0019090c\n"
        ".Lf1907ba_001909d6:\n"
        "ucomiss %xmm2, %xmm1\n" /* line 708 */
        "jbe .Lf1907ba_00190a2e\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 711 */
        "mulss %xmm2, %xmm0\n"
        "cvttss2si %xmm0, %edx\n"
        "jmp .Lf1907ba_001908fc\n"
        ".Lf1907ba_001909ec:\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 701 */
        "movss 0x2ed970, %xmm2\n" /* -1022.0f */
        "divss %xmm0, %xmm2\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "jmp .Lf1907ba_001908ce\n"
        ".Lf1907ba_00190a09:\n"
        "leal 2(%edx), %esi\n" /* line 725 | iEntCount */
        "jmp .Lf1907ba_0019091d\n"
        ".Lf1907ba_00190a11:\n"
        "addl $2, %eax\n" /* line 721 */
        "jmp .Lf1907ba_0019090c\n"
        ".Lf1907ba_00190a19:\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 705 */
        "movss 0x2ed970, %xmm1\n" /* -1022.0f */
        "divss %xmm0, %xmm1\n"
        "jmp .Lf1907ba_001908ea\n"
        ".Lf1907ba_00190a2e:\n"
        "ucomiss %xmm1, %xmm2\n" /* line 713 */
        "jbe .Lf1907ba_001908fc\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 716 */
        "mulss %xmm0, %xmm1\n"
        "cvttss2si %xmm1, %eax\n"
        "jmp .Lf1907ba_001908fc\n"
    );
}

/* line 748 */
__attribute__((naked))
void G_BroadcastVoice(gentity_t *talker, VoicePacket_t *voicePacket)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 748 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* talker */
        /* { scope 1 */
        "movl 0x158(%edi), %eax\n" /* line 754 | talker */
        "movl 0x195f6a0, %edx\n"
        "movl 0x1ec(%edx), %edx\n"
        "movl %edx, 0x2808(%eax)\n"
        "xorl %esi, %esi\n" /* otherPlayer */
        "movl 0x195f688, %ebx\n"
        "jmp .Lf190a48_00190aaa\n"
        ".Lf190a48_00190a76:\n"
        "movl 0x158(%edi), %edx\n" /* talker */
        ".Lf190a48_00190a7c:\n"
        "movl 0x158(%ebx), %eax\n" /* line 775 */
        "movl 0x26a8(%eax), %eax\n"
        "movl 0x26a8(%edx), %edx\n"
        "cmpl %edx, %eax\n"
        "je .Lf190a48_00190b0d\n"
        "subl $1, %eax\n" /* line 778 */
        "je .Lf190a48_00190b00\n"
        "subl $1, %edx\n"
        "je .Lf190a48_00190b00\n"
        ".Lf190a48_00190a9c:\n"
        "addl $1, %esi\n" /* line 762 | otherPlayer */
        "addl $0x230, %ebx\n"
        "cmpl $0x40, %esi\n" /* otherPlayer */
        "je .Lf190a48_00190af8\n"
        ".Lf190a48_00190aaa:\n"
        "cmpb $0, 0xfc(%ebx)\n" /* line 765 */
        "je .Lf190a48_00190a9c\n"
        "movl 0x158(%ebx), %eax\n" /* line 767 */
        "testl %eax, %eax\n"
        "je .Lf190a48_00190a9c\n"
        "movl 0x195f684, %eax\n" /* line 771 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf190a48_00190a76\n"
        "movl %ebx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* talker */
        "calll OnSameTeam\n"
        "testl %eax, %eax\n"
        "jne .Lf190a48_00190a76\n"
        "movl 0x158(%edi), %edx\n" /* talker */
        "movl 0x274c(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf190a48_00190a7c\n"
        "addl $1, %esi\n" /* line 762 | otherPlayer */
        "addl $0x230, %ebx\n"
        "cmpl $0x40, %esi\n" /* otherPlayer */
        "jne .Lf190a48_00190aaa\n"
        /* } scope */
        ".Lf190a48_00190af8:\n"
        "addl $0x1c, %esp\n" /* line 800 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf190a48_00190b00:\n"
        "movl 0x195f690, %eax\n" /* line 778 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf190a48_00190a9c\n"
        ".Lf190a48_00190b0d:\n"
        "cmpl %ebx, %edi\n" /* line 783 | talker */
        "je .Lf190a48_00190b51\n"
        ".Lf190a48_00190b11:\n"
        "movl (%edi), %eax\n" /* line 786 | talker */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* otherPlayer */
        "calll SV_ClientHasClientMuted\n"
        "testb %al, %al\n"
        "jne .Lf190a48_00190a9c\n"
        "movl %esi, (%esp)\n" /* line 796 | otherPlayer */
        "calll SV_ClientWantsVoiceData\n"
        "testb %al, %al\n"
        "je .Lf190a48_00190a9c\n"
        "movl 0xc(%ebp), %eax\n" /* line 798 | voicePacket */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* otherPlayer */
        "movl (%edi), %eax\n" /* talker */
        "movl %eax, (%esp)\n"
        "calll SV_QueueVoicePacket\n"
        "jmp .Lf190a48_00190a9c\n"
        ".Lf190a48_00190b51:\n"
        "movl 0x195f69c, %eax\n" /* line 783 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf190a48_00190a9c\n"
        "jmp .Lf190a48_00190b11\n"
    );
}

/* line 22 */
__attribute__((naked))
void SetClientViewAngle(gentity_t *ent, const vec_t *angle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 22 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %esi\n" /* ent */
        "movl 0xc(%ebp), %eax\n" /* angle */
        /* { scope 1 */
        "movl (%eax), %edx\n" /* line 199 */
        "movl %edx, -0x14(%ebp)\n" /* newAngle */
        "movl 4(%eax), %ecx\n" /* line 200 */
        "movl %ecx, -0x10(%ebp)\n"
        "movl 8(%eax), %eax\n" /* line 201 */
        "movl %eax, -0xc(%ebp)\n"
        "movl 0x158(%esi), %edx\n" /* line 29 | ent */
        "testb $1, 0xc(%edx)\n"
        "je .Lf190b64_00190b9b\n"
        "testl $0x300, 0xa0(%edx)\n"
        "je .Lf190b64_00190c19\n"
        /* { scope 2 */
        ".Lf190b64_00190b9b:\n"
        "xorl %ecx, %ecx\n" /* line 82 */
        "movss 0x2ed644, %xmm1\n" /* 182.04444885253906f */
        /* } scope */
        ".Lf190b64_00190ba5:\n"
        "movss -0x14(%ebp, %ecx, 4), %xmm0\n" /* line 92 */
        "mulss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "andl $0xffff, %eax\n"
        "subl 0x26d4(%edx, %ecx, 4), %eax\n"
        "movl %eax, 0x54(%edx, %ecx, 4)\n"
        "addl $1, %ecx\n" /* line 87 */
        "cmpl $3, %ecx\n"
        "je .Lf190b64_00190bd3\n"
        "movl 0x158(%esi), %edx\n" /* ent */
        "jmp .Lf190b64_00190ba5\n"
        ".Lf190b64_00190bd3:\n"
        "leal 0x144(%esi), %ecx\n" /* line 95 | ent, to */
        /* { scope 2 */
        "movl -0x14(%ebp), %eax\n" /* line 199 | newAngle */
        "movl %eax, 0x144(%esi)\n" /* ent */
        "movl -0x10(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0xc(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl 0x158(%esi), %edx\n" /* line 96 | ent */
        "leal 0xe8(%edx), %ebx\n" /* to */
        /* { scope 2 */
        "movl 0x144(%esi), %eax\n" /* line 199 | ent */
        "movl %eax, 0xe8(%edx)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n" /* to */
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n" /* to */
        /* } scope */
        /* } scope */
        "addl $0x30, %esp\n" /* line 97 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf190b64_00190c19:\n"
        "movl %ecx, 4(%esp)\n" /* line 37 */
        "movl 0x584(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AngleDelta\n"
        "fstps (%esp)\n" /* line 38 */
        "calll AngleNormalize180\n"
        "fstps -0x1c(%ebp)\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "ucomiss 0x2ed6ec, %xmm0\n" /* line 44 | 45.0f */
        "ja .Lf190b64_00190d06\n"
        "ucomiss 0x2ed714, %xmm0\n" /* -45.0f */
        "jp .Lf190b64_00190c57\n"
        "jb .Lf190b64_00190d5f\n"
        ".Lf190b64_00190c57:\n"
        "movl -0x14(%ebp), %eax\n" /* line 65 | newAngle */
        "movl %eax, 4(%esp)\n"
        "movl 0x158(%esi), %eax\n" /* ent */
        "movl 0x58c(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AngleDelta\n"
        "fstps (%esp)\n" /* line 66 */
        "calll AngleNormalize180\n"
        "fstps -0x1c(%ebp)\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "ucomiss 0x2ed6ec, %xmm0\n" /* line 68 | 45.0f */
        "ja .Lf190b64_00190ca3\n"
        "ucomiss 0x2ed978, %xmm0\n" /* -15.0f */
        "jp .Lf190b64_00190cfb\n"
        "jae .Lf190b64_00190cfb\n"
        "movaps %xmm0, %xmm1\n" /* line 74 */
        "addss 0x2ed908, %xmm1\n" /* 15.0f */
        "jmp .Lf190b64_00190cae\n"
        ".Lf190b64_00190ca3:\n"
        "movaps %xmm0, %xmm1\n" /* line 72 */
        "subss 0x2ed6ec, %xmm1\n" /* 45.0f */
        ".Lf190b64_00190cae:\n"
        "movl 0x158(%esi), %edx\n" /* line 76 | ent */
        "movaps %xmm1, %xmm0\n"
        "mulss 0x2ed644, %xmm0\n" /* 182.04444885253906f */
        "cvttss2si %xmm0, %eax\n"
        "andl $0xffff, %eax\n"
        "addl %eax, 0x54(%edx)\n"
        "ucomiss 0x2ed5e8, %xmm1\n" /* line 79 | 0.0f */
        "jbe .Lf190b64_00190d90\n"
        "movl 0x158(%esi), %eax\n" /* line 80 | ent */
        "movss 0x58c(%eax), %xmm0\n"
        "subss 0x2ed6ec, %xmm0\n" /* 45.0f */
        "movss %xmm0, (%esp)\n"
        "calll AngleNormalize180\n"
        "fstps -0x14(%ebp)\n" /* newAngle */
        ".Lf190b64_00190cfb:\n"
        "movl 0x158(%esi), %edx\n" /* ent */
        "jmp .Lf190b64_00190b9b\n"
        ".Lf190b64_00190d06:\n"
        "movss 0x2ed6ec, %xmm2\n" /* line 48 | 45.0f */
        "movaps %xmm0, %xmm1\n"
        "subss %xmm2, %xmm1\n"
        ".Lf190b64_00190d15:\n"
        "movl 0x158(%esi), %edx\n" /* line 52 | ent */
        "movaps %xmm1, %xmm0\n"
        "mulss 0x2ed644, %xmm0\n" /* 182.04444885253906f */
        "cvttss2si %xmm0, %eax\n"
        "andl $0xffff, %eax\n"
        "addl %eax, 0x58(%edx)\n"
        "ucomiss 0x2ed5e8, %xmm1\n" /* line 55 | 0.0f */
        "jbe .Lf190b64_00190d70\n"
        "movl 0x158(%esi), %eax\n" /* line 56 | ent */
        "movss 0x584(%eax), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll AngleNormalize360\n"
        "fstps -0x10(%ebp)\n"
        "jmp .Lf190b64_00190c57\n"
        ".Lf190b64_00190d5f:\n"
        "movss 0x2ed6ec, %xmm2\n" /* line 50 | 45.0f */
        "movaps %xmm0, %xmm1\n"
        "addss %xmm2, %xmm1\n"
        "jmp .Lf190b64_00190d15\n"
        ".Lf190b64_00190d70:\n"
        "movl 0x158(%esi), %eax\n" /* line 58 | ent */
        "addss 0x584(%eax), %xmm2\n"
        "movss %xmm2, (%esp)\n"
        "calll AngleNormalize360\n"
        "fstps -0x10(%ebp)\n"
        "jmp .Lf190b64_00190c57\n"
        ".Lf190b64_00190d90:\n"
        "movl 0x158(%esi), %eax\n" /* line 82 | ent */
        "movss 0x2ed908, %xmm0\n" /* 15.0f */
        "addss 0x58c(%eax), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll AngleNormalize180\n"
        "fstps -0x14(%ebp)\n" /* newAngle */
        "jmp .Lf190b64_00190cfb\n"
    );
}

/* line 452 */
__attribute__((naked))
void ClientSpawn(gentity_t *ent, const vec_t *spawn_origin, const vec_t *spawn_angles)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 452 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x13c, %esp\n"
        /* { scope 1: to, to */
        "movl 8(%ebp), %eax\n" /* line 463 | ent */
        "subl 0x195f688, %eax\n"
        "sarl $4, %eax\n"
        "imull $0x8af8af8b, %eax, %eax\n"
        "movl %eax, -0x12c(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* line 464 | ent */
        "movl 0x158(%eax), %edi\n" /* client */
        "testb $0x80, 0xe(%edi)\n" /* line 470 | client */
        "je .Lf190db8_00190e1f\n"
        "testl $0x300, 0xa0(%edi)\n" /* client */
        "jne .Lf190db8_00191147\n"
        "movl 8(%ebp), %edx\n" /* ent */
        "movl %edx, (%esp)\n" /* line 478 */
        "calll G_EntUnlink\n"
        "movl 8(%ebp), %ecx\n" /* line 479 | ent */
        "cmpb $0, 0xf0(%ecx)\n"
        "je .Lf190db8_00190e35\n"
        ".Lf190db8_00190e12:\n"
        "movl %ecx, (%esp)\n" /* line 480 */
        "calll SV_UnlinkEntity\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "jmp .Lf190db8_00190e37\n"
        ".Lf190db8_00190e1f:\n"
        "movl %eax, %edx\n"
        ".Lf190db8_00190e21:\n"
        "movl %edx, (%esp)\n" /* line 478 */
        "calll G_EntUnlink\n"
        "movl 8(%ebp), %ecx\n" /* line 479 | ent */
        "cmpb $0, 0xf0(%ecx)\n"
        "jne .Lf190db8_00190e12\n"
        ".Lf190db8_00190e35:\n"
        "movl %ecx, %eax\n"
        ".Lf190db8_00190e37:\n"
        "movl $0x3ff, 0x7c(%eax)\n" /* line 482 */
        "movl 0x195f5bc, %eax\n" /* line 483 */
        "movzwl 0x32(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "addl $0x168, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_SetString\n"
        "movl 8(%ebp), %edx\n" /* line 485 | ent */
        "movl $0x2810011, 0x184(%edx)\n"
        "orb $1, 0xf2(%edx)\n" /* line 487 */
        "movb $0, 0x161(%edx)\n" /* line 488 */
        "movl %edx, (%esp)\n" /* line 490 */
        "calll G_SetClientContents\n"
        "movl 8(%ebp), %ecx\n" /* line 492 | ent */
        "movb $0xa, 0x166(%ecx)\n"
        "movl $__mh_execute_header, 0x174(%ecx)\n" /* line 493 */
        "addl $0x104, %ecx\n" /* line 495 */
        "movl %ecx, -0x120(%ebp)\n" /* to */
        /* { scope 2 */
        "movl playerMins, %eax\n" /* line 199 */
        "movl 8(%ebp), %edx\n" /* ent */
        "movl %eax, 0x104(%edx)\n"
        "movl 0x3131d0, %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 0x3131d4, %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "addl $0x110, %edx\n" /* line 496 */
        "movl %edx, -0x11c(%ebp)\n" /* to */
        /* { scope 2 */
        "movl playerMaxs, %eax\n" /* line 199 */
        "movl 8(%ebp), %ecx\n" /* ent */
        "movl %eax, 0x110(%ecx)\n"
        "movl 0x3131c4, %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 0x3131c8, %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl 0xa0(%edi), %eax\n" /* line 499 | client */
        "andl $0x100002, %eax\n"
        "movl %eax, -0x124(%ebp)\n" /* iFlags */
        "leal 0x26a8(%edi), %esi\n" /* line 501 | client */
        "movl $0x100, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x118(%ebp), %edx\n" /* savedSess */
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl 0x140(%edi), %ebx\n" /* line 502 | client, savedSpawnCount */
        "movl $0x28a4, 8(%esp)\n" /* line 507 */
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* client */
        "calll memset\n"
        "movl $0x100, 8(%esp)\n" /* line 513 */
        "leal -0x118(%ebp), %ecx\n" /* savedSess */
        "movl %ecx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll memcpy\n"
        "movl $0xffffffff, 0x27a8(%edi)\n" /* line 515 | client */
        "movl $0x3ff, 0x2830(%edi)\n" /* line 516 | client */
        "addl $1, %ebx\n" /* line 518 | savedSpawnCount */
        "movl %ebx, 0x140(%edi)\n" /* savedSpawnCount, client */
        "movl 0x2728(%edi), %eax\n" /* line 521 | client */
        "movl %eax, 0x134(%edi)\n" /* client */
        "movl -0x124(%ebp), %eax\n" /* line 522 | iFlags */
        "movl %eax, 0xa0(%edi)\n" /* client */
        "movl -0x12c(%ebp), %edx\n" /* line 524 */
        "movl %edx, 0x2748(%edi)\n" /* client */
        "movl %edx, 0xcc(%edi)\n" /* line 525 | client */
        "movl $0x3ff, 0x594(%edi)\n" /* line 526 | client */
        "leal 0x26c8(%edi), %ecx\n" /* line 528 | client */
        "movl %ecx, -0x128(%ebp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl 0x195f6a0, %ebx\n" /* savedSpawnCount */
        "movl %edi, %edx\n" /* client */
        "subl (%ebx), %edx\n" /* savedSpawnCount */
        "sarl $2, %edx\n"
        "movl %edx, %eax\n"
        "shll $9, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "shll $7, %eax\n"
        "addl %edx, %eax\n"
        "shll $9, %eax\n"
        "addl %edx, %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_GetUsercmd\n"
        "xorl $2, 0xa0(%edi)\n" /* line 530 | client */
        "leal 0x56c(%edi), %edx\n" /* line 533 | client, to */
        /* { scope 2 */
        "movl 8(%ebp), %ecx\n" /* line 199 | ent */
        "movl 0x104(%ecx), %eax\n"
        "movl %eax, 0x56c(%edi)\n"
        "movl -0x120(%ebp), %ecx\n" /* line 200 | to */
        "movl 4(%ecx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0x578(%edi), %edx\n" /* line 534 | client, to */
        /* { scope 2 */
        "movl 8(%ebp), %ecx\n" /* line 199 | ent */
        "movl 0x110(%ecx), %eax\n"
        "movl %eax, 0x578(%edi)\n"
        "movl -0x11c(%ebp), %ecx\n" /* line 200 | to */
        "movl 4(%ecx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl $0x3c, 0xf4(%edi)\n" /* line 537 | client */
        "movl $0x42700000, 0xf8(%edi)\n" /* line 538 | client */
        "movl $0, 0xfc(%edi)\n" /* line 539 | client */
        "movl $0, 0x108(%edi)\n" /* line 540 | client */
        "movl 0xc(%ebp), %eax\n" /* line 542 | spawn_origin */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* ent */
        "movl %edx, (%esp)\n"
        "calll G_SetOrigin\n"
        "leal 0x14(%edi), %edx\n" /* line 543 | client, to */
        /* { scope 2 */
        "movl 0xc(%ebp), %ecx\n" /* line 199 | spawn_origin */
        "movl (%ecx), %eax\n"
        "movl %eax, 0x14(%edi)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "orl $__mh_execute_header, 0xc(%edi)\n" /* line 546 | client */
        "movl 0x10(%ebp), %eax\n" /* line 548 | spawn_angles */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll SetClientViewAngle\n"
        "movl 0x195f694, %eax\n" /* line 550 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "movl 0x1ec(%ebx), %edx\n" /* savedSpawnCount */
        "leal (%edx, %eax, 8), %eax\n"
        "movl %eax, 0x2800(%edi)\n" /* client */
        "movl 0x26cc(%edi), %eax\n" /* line 554 | client */
        "movl %eax, 0x27bc(%edi)\n" /* client */
        "movl $1, 0x20(%ebx)\n" /* line 559 | savedSpawnCount */
        "movl 0x1ec(%ebx), %eax\n" /* line 560 | savedSpawnCount */
        "movl %eax, 0x28a0(%edi)\n" /* client */
        "movl 0x1ec(%ebx), %eax\n" /* line 565 | savedSpawnCount */
        "movl %eax, 0x26c8(%edi)\n" /* client */
        "movl 0x1ec(%ebx), %eax\n" /* line 566 | savedSpawnCount */
        "subl $0x64, %eax\n"
        "movl %eax, (%edi)\n" /* client */
        "movl 8(%ebp), %edx\n" /* line 568 | ent */
        "movl %edx, (%esp)\n"
        "calll ClientEndFrame\n"
        "movl -0x128(%ebp), %ecx\n" /* line 569 */
        "movl %ecx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll ClientThink_real\n"
        "movl $0, 0x20(%ebx)\n" /* line 577 | savedSpawnCount */
        "movl $1, 0xc(%esp)\n" /* line 580 */
        "movl $1, 8(%esp)\n"
        "movl 8(%ebp), %edx\n" /* ent */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* client */
        "calll BG_PlayerStateToEntityState\n"
        /* } scope */
        "addl $0x13c, %esp\n" /* line 581 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: to, to */
        ".Lf190db8_00191147:\n"
        "movl 0x594(%edi), %eax\n" /* line 475 | client */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "movl 0x195f6a0, %eax\n"
        "addl 4(%eax), %edx\n"
        "movl %edx, (%esp)\n"
        "calll G_ClientStopUsingTurret\n"
        "movl 8(%ebp), %edx\n" /* ent */
        "jmp .Lf190db8_00190e21\n"
    );
}

/* line 103 */
__attribute__((naked))
void G_GetPlayerViewOrigin(const gentity_t *ent, vec_t *origin)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 103 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* origin */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 116 | ent */
        "movl 0x158(%eax), %esi\n" /* ps */
        "testl $0x300, 0xa0(%esi)\n" /* line 118 | ps */
        "je .Lf191174_001911dc\n"
        "movl %edi, 8(%esp)\n" /* line 125 | origin */
        "movl 0x195f5bc, %eax\n"
        "movzwl 0x9a(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x594(%esi), %edx\n" /* ps */
        "leal (%edx, %edx, 4), %edx\n"
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl 0x195f688, %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_DObjGetWorldTagPos\n"
        "testl %eax, %eax\n"
        "je .Lf191174_00191349\n"
        /* } scope */
        ".Lf191174_001911d4:\n"
        "addl $0x6c, %esp\n" /* line 150 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf191174_001911dc:\n"
        "leal 0x14(%esi), %edx\n" /* line 131 | ps, from */
        /* { scope 2 */
        "movl 0x14(%esi), %eax\n" /* line 199 | ps */
        "movl %eax, (%edi)\n" /* origin */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%edi)\n" /* origin */
        "movss 8(%edx), %xmm0\n" /* line 201 */
        "movss %xmm0, 8(%edi)\n" /* origin */
        /* } scope */
        "addss 0xf8(%esi), %xmm0\n" /* line 132 | ps */
        "movss %xmm0, 8(%edi)\n" /* origin */
        "movl %esi, (%esp)\n" /* line 134 | ps */
        "calll BG_GetBobCycle\n"
        "fstps -0x30(%ebp)\n" /* fBobCycle */
        "movl 0x195f6a0, %eax\n" /* line 135 */
        "movl 0x1ec(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* ps */
        "calll BG_GetSpeed\n"
        "fstps -0x2c(%ebp)\n" /* xyspeed */
        "movl 0x195f680, %ebx\n" /* line 138 */
        "movl (%ebx), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movss -0x2c(%ebp), %xmm0\n" /* xyspeed */
        "movss %xmm0, 8(%esp)\n"
        "movss -0x30(%ebp), %xmm0\n" /* fBobCycle */
        "movss %xmm0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* ps */
        "calll BG_GetVerticalBobFactor\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm0\n"
        "addss 8(%edi), %xmm0\n" /* line 139 | origin */
        "movss %xmm0, 8(%edi)\n" /* origin */
        "movl (%ebx), %eax\n" /* line 140 */
        "movl 8(%eax), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movss -0x2c(%ebp), %xmm0\n" /* xyspeed */
        "movss %xmm0, 8(%esp)\n"
        "movss -0x30(%ebp), %xmm0\n" /* fBobCycle */
        "movss %xmm0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* ps */
        "calll BG_GetHorizontalBobFactor\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm1\n"
        "movl $0, 0xc(%esp)\n" /* line 161 */
        "leal -0x24(%ebp), %eax\n" /* vRight */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* ent */
        "movl 0x158(%edx), %eax\n"
        "addl $0xe8, %eax\n"
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0x48(%ebp)\n"
        "calll AngleVectors\n"
        "movss -0x48(%ebp), %xmm1\n" /* line 288 */
        "movaps %xmm1, %xmm0\n"
        "mulss -0x24(%ebp), %xmm0\n" /* vRight */
        "addss (%edi), %xmm0\n" /* origin */
        "movss %xmm0, (%edi)\n" /* origin */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x20(%ebp), %xmm0\n"
        "addss 4(%edi), %xmm0\n" /* origin */
        "movss %xmm0, 4(%edi)\n" /* origin */
        "mulss -0x1c(%ebp), %xmm1\n" /* line 290 */
        "addss 8(%edi), %xmm1\n" /* origin */
        "movss %xmm1, 8(%edi)\n" /* origin */
        "movl $0x41a00000, 0x10(%esp)\n" /* line 145 */
        "movl $0x41800000, 0xc(%esp)\n"
        "movl 0x4c(%esi), %eax\n" /* ps */
        "movl %eax, 8(%esp)\n"
        "movl 0xec(%esi), %eax\n" /* ps */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* origin */
        "calll AddLeanToPosition\n"
        "movss 0x2ed740, %xmm0\n" /* line 148 | 8.0f */
        "addss 0x1c(%esi), %xmm0\n" /* ps */
        "ucomiss 8(%edi), %xmm0\n" /* origin */
        "jbe .Lf191174_001911d4\n"
        "movss %xmm0, 8(%edi)\n" /* line 149 | origin */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 150 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf191174_00191349:\n"
        "movl $0x2b0160, 4(%esp)\n" /* line 126 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 150 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 270 */
__attribute__((naked))
void ClientUserinfoChanged(int clientNum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 270 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x83c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 280 | clientNum */
        "leal (%eax, %eax, 4), %edx\n"
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "shll $4, %eax\n"
        "movl 0x195f688, %edx\n"
        "movl 0x158(%eax, %edx), %eax\n"
        "movl %eax, -0x834(%ebp)\n" /* client */
        "movl $0x400, 8(%esp)\n" /* line 282 */
        "leal -0x818(%ebp), %ebx\n" /* userinfo, ci */
        "movl %ebx, 4(%esp)\n" /* ci */
        "movl 8(%ebp), %edx\n" /* clientNum */
        "movl %edx, (%esp)\n"
        "calll SV_GetUserinfo\n"
        "movl %ebx, (%esp)\n" /* line 285 | ci */
        "calll Info_Validate\n"
        "testl %eax, %eax\n"
        "je .Lf191366_00191694\n"
        ".Lf191366_001913c4:\n"
        "movl 8(%ebp), %eax\n" /* line 291 | clientNum */
        "movl %eax, (%esp)\n"
        "calll SV_IsLocalClient\n"
        "movl -0x834(%ebp), %edx\n" /* client */
        "movl %eax, 0x2700(%edx)\n"
        "movl $0x2a8410, 4(%esp)\n" /* line 294 */
        "movl %ebx, (%esp)\n" /* ci */
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n" /* line 295 */
        "calll atoi\n"
        "testl %eax, %eax\n" /* line 297 */
        "setne %al\n"
        "movzbl %al, %eax\n"
        "movl -0x834(%ebp), %edx\n" /* client */
        "movl %eax, 0x2704(%edx)\n"
        "cmpl $2, 0x26c4(%edx)\n" /* line 305 */
        "je .Lf191366_001915e9\n"
        ".Lf191366_00191414:\n"
        "movl -0x834(%ebp), %edi\n" /* line 312 | client, out */
        "addl $0x2784, %edi\n" /* out */
        "movl $0x400, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* out */
        "leal -0x418(%ebp), %eax\n" /* oldname */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $0x2194b4, 4(%esp)\n" /* line 313 */
        "movl %ebx, (%esp)\n" /* in */
        "calll Info_ValueForKey\n"
        "movl %eax, %ebx\n" /* in */
        /* { scope 2: len, colorlessLen, spaces, len, ... */
        /* { scope 3 */
        "movl -0x834(%ebp), %eax\n" /* line 183 | client */
        "movb $0, 0x2784(%eax)\n"
        "movl %edi, %esi\n"
        "movl $0, -0x824(%ebp)\n" /* len */
        "movl $0, -0x820(%ebp)\n" /* colorlessLen */
        "movl $0, -0x81c(%ebp)\n" /* spaces */
        "movzbl (%ebx), %eax\n" /* line 188 */
        "leal 1(%ebx), %edx\n"
        "testb %al, %al\n" /* line 189 */
        "je .Lf191366_001914ce\n"
        ".Lf191366_00191483:\n"
        "cmpb $0, (%edi)\n" /* line 195 */
        "jne .Lf191366_0019148c\n"
        "cmpb $0x20, %al\n"
        "je .Lf191366_001914c2\n"
        ".Lf191366_0019148c:\n"
        "cmpb $0x5e, %al\n" /* line 201 */
        "je .Lf191366_00191561\n"
        "cmpb $0x20, %al\n" /* line 229 */
        "je .Lf191366_00191586\n"
        "movl $0, -0x81c(%ebp)\n" /* spaces */
        ".Lf191366_001914a6:\n"
        "cmpl $0x1e, -0x824(%ebp)\n" /* line 242 | len */
        "jg .Lf191366_001914ce\n"
        "movb %al, (%esi)\n" /* line 247 */
        "addl $1, %esi\n"
        "addl $1, -0x820(%ebp)\n" /* line 248 | colorlessLen */
        "addl $1, -0x824(%ebp)\n" /* line 249 | len */
        ".Lf191366_001914c2:\n"
        "movl %edx, %ebx\n" /* line 183 */
        ".Lf191366_001914c4:\n"
        "movzbl (%ebx), %eax\n" /* line 188 */
        "leal 1(%ebx), %edx\n"
        "testb %al, %al\n" /* line 189 */
        "jne .Lf191366_00191483\n"
        ".Lf191366_001914ce:\n"
        "movb $0, (%esi)\n" /* line 251 */
        "cmpb $0, (%edi)\n" /* line 254 */
        "je .Lf191366_001915cc\n"
        "movl -0x820(%ebp), %eax\n" /* colorlessLen */
        "testl %eax, %eax\n"
        "je .Lf191366_001915cc\n"
        /* } scope */
        /* } scope */
        ".Lf191366_001914e8:\n"
        "movl $0x20, 8(%esp)\n" /* line 316 */
        "movl %edi, 4(%esp)\n" /* out */
        "movl -0x834(%ebp), %eax\n" /* client */
        "addl $0x2708, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        ".Lf191366_00191507:\n"
        "movl 8(%ebp), %eax\n" /* line 319 | clientNum */
        "leal (%eax, %eax, 4), %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "movl 8(%ebp), %edx\n" /* clientNum */
        "leal (%edx, %eax, 2), %eax\n"
        "movl 0x195f68c, %edx\n"
        "leal 0xb3bf0(%edx, %eax, 8), %eax\n"
        "leal 0xc(%eax), %ebx\n" /* in */
        "movl 8(%ebp), %edx\n" /* line 322 | clientNum */
        "movl %edx, 8(%ebx)\n" /* in */
        "movl $0x20, 8(%esp)\n" /* line 323 */
        "movl %edi, 4(%esp)\n" /* out */
        "addl $0x18, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl -0x834(%ebp), %edx\n" /* line 324 | client */
        "movl 0x274c(%edx), %eax\n"
        "movl %eax, 0x2c(%ebx)\n" /* in */
        /* } scope */
        "addl $0x83c, %esp\n" /* line 325 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: len, colorlessLen, spaces, len, ... */
        /* { scope 3 */
        ".Lf191366_00191561:\n"
        "movzbl 1(%ebx), %eax\n" /* line 204 */
        "testb %al, %al\n"
        "je .Lf191366_001914ce\n"
        "movzbl %al, %eax\n" /* line 210 */
        "movl %eax, (%esp)\n"
        "calll ColorIndex\n"
        "testb %al, %al\n"
        "jne .Lf191366_001915a1\n"
        "leal 2(%ebx), %edx\n" /* line 212 */
        "movl %edx, %ebx\n" /* line 183 */
        "jmp .Lf191366_001914c4\n"
        ".Lf191366_00191586:\n"
        "addl $1, -0x81c(%ebp)\n" /* line 231 | spaces */
        "cmpl $3, -0x81c(%ebp)\n" /* line 232 | spaces */
        "jle .Lf191366_001914a6\n"
        "movl %edx, %ebx\n" /* line 183 */
        "jmp .Lf191366_001914c4\n"
        ".Lf191366_001915a1:\n"
        "cmpl $0x1d, -0x824(%ebp)\n" /* line 217 | len */
        "jg .Lf191366_001914ce\n"
        "movb $0x5e, (%esi)\n" /* line 222 */
        "movzbl 1(%ebx), %eax\n" /* line 223 */
        "movb %al, 1(%esi)\n"
        "addl $2, %esi\n"
        "leal 2(%ebx), %edx\n"
        "addl $2, -0x824(%ebp)\n" /* line 224 | len */
        "movl %edx, %ebx\n" /* line 183 */
        "jmp .Lf191366_001914c4\n"
        ".Lf191366_001915cc:\n"
        "movl $0x1f, 8(%esp)\n" /* line 256 */
        "movl $0x2b01a0, 4(%esp)\n" /* "UnnamedPlayer" */
        "movl %edi, (%esp)\n"
        "calll I_strncpyz\n"
        "jmp .Lf191366_001914e8\n"
        /* } scope */
        /* } scope */
        ".Lf191366_001915e9:\n"
        "movl 0x195f6a0, %eax\n" /* line 305 */
        "movl 0x214(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf191366_00191414\n"
        "movl $0x2194b4, 4(%esp)\n" /* line 307 */
        "movl %ebx, (%esp)\n" /* ci */
        "calll Info_ValueForKey\n"
        "movl -0x834(%ebp), %edi\n" /* line 308 | client, out */
        "addl $0x2708, %edi\n" /* out */
        "movl %eax, %ebx\n" /* in */
        /* { scope 2: len, colorlessLen, spaces, len, ... */
        /* { scope 3 */
        "movl -0x834(%ebp), %eax\n" /* line 183 | client */
        "movb $0, 0x2708(%eax)\n"
        "movl %edi, %esi\n"
        "movl $0, -0x830(%ebp)\n" /* len */
        "movl $0, -0x82c(%ebp)\n" /* colorlessLen */
        "movl $0, -0x828(%ebp)\n" /* spaces */
        ".Lf191366_00191647:\n"
        "movzbl (%ebx), %eax\n" /* line 188 */
        "leal 1(%ebx), %edx\n"
        "testb %al, %al\n" /* line 189 */
        "je .Lf191366_00191723\n"
        "cmpb $0, (%edi)\n" /* line 195 */
        "jne .Lf191366_0019165e\n"
        "cmpb $0x20, %al\n"
        "je .Lf191366_00191690\n"
        ".Lf191366_0019165e:\n"
        "cmpb $0x5e, %al\n" /* line 201 */
        "je .Lf191366_001916c0\n"
        "cmpb $0x20, %al\n" /* line 229 */
        "je .Lf191366_001916e1\n"
        "movl $0, -0x828(%ebp)\n" /* spaces */
        ".Lf191366_00191670:\n"
        "cmpl $0x1e, -0x830(%ebp)\n" /* line 242 | len */
        "jg .Lf191366_00191723\n"
        "movb %al, (%esi)\n" /* line 247 */
        "addl $1, %esi\n"
        "addl $1, -0x82c(%ebp)\n" /* line 248 | colorlessLen */
        "addl $1, -0x830(%ebp)\n" /* line 249 | len */
        ".Lf191366_00191690:\n"
        "movl %edx, %ebx\n" /* line 183 */
        "jmp .Lf191366_00191647\n"
        /* } scope */
        /* } scope */
        ".Lf191366_00191694:\n"
        "movl $0x6d616e5c, -0x818(%ebp)\n" /* line 287 | userinfo */
        "movl $0x61625c65, -0x814(%ebp)\n"
        "movl $0x666e6964, -0x810(%ebp)\n"
        "movw $0x6f, -0x80c(%ebp)\n"
        "jmp .Lf191366_001913c4\n"
        /* { scope 2: len, colorlessLen, spaces, len, ... */
        /* { scope 3 */
        ".Lf191366_001916c0:\n"
        "movzbl 1(%ebx), %eax\n" /* line 204 */
        "testb %al, %al\n"
        "je .Lf191366_00191723\n"
        "movzbl %al, %eax\n" /* line 210 */
        "movl %eax, (%esp)\n"
        "calll ColorIndex\n"
        "testb %al, %al\n"
        "jne .Lf191366_001916fc\n"
        "leal 2(%ebx), %edx\n" /* line 212 */
        "movl %edx, %ebx\n" /* line 183 */
        "jmp .Lf191366_00191647\n"
        ".Lf191366_001916e1:\n"
        "addl $1, -0x828(%ebp)\n" /* line 231 | spaces */
        "cmpl $3, -0x828(%ebp)\n" /* line 232 | spaces */
        "jle .Lf191366_00191670\n"
        "movl %edx, %ebx\n" /* line 183 */
        "jmp .Lf191366_00191647\n"
        ".Lf191366_001916fc:\n"
        "cmpl $0x1d, -0x830(%ebp)\n" /* line 217 | len */
        "jg .Lf191366_00191723\n"
        "movb $0x5e, (%esi)\n" /* line 222 */
        "movzbl 1(%ebx), %eax\n" /* line 223 */
        "movb %al, 1(%esi)\n"
        "addl $2, %esi\n"
        "leal 2(%ebx), %edx\n"
        "addl $2, -0x830(%ebp)\n" /* line 224 | len */
        "movl %edx, %ebx\n" /* line 183 */
        "jmp .Lf191366_00191647\n"
        ".Lf191366_00191723:\n"
        "movb $0, (%esi)\n" /* line 251 */
        "cmpb $0, (%edi)\n" /* line 254 */
        "je .Lf191366_00191735\n"
        "movl -0x82c(%ebp), %eax\n" /* colorlessLen */
        "testl %eax, %eax\n"
        "jne .Lf191366_0019175e\n"
        ".Lf191366_00191735:\n"
        "movl $0x1f, 8(%esp)\n" /* line 256 */
        "movl $0x2b01a0, 4(%esp)\n" /* "UnnamedPlayer" */
        "movl %edi, (%esp)\n"
        "calll I_strncpyz\n"
        "movl -0x834(%ebp), %edx\n" /* client */
        "leal 0x2784(%edx), %edi\n"
        "jmp .Lf191366_00191507\n"
        ".Lf191366_0019175e:\n"
        "movl -0x834(%ebp), %edx\n" /* client */
        "leal 0x2784(%edx), %edi\n"
        "jmp .Lf191366_00191507\n"
    );
}

/* line 344 */
__attribute__((naked))
char * ClientConnect(int clientNum, int scriptPersId)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 344 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* scriptPersId */
        "movl %eax, -0x424(%ebp)\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 355 | clientNum */
        "leal (%eax, %eax, 4), %edi\n" /* ci */
        "leal (, %edi, 8), %eax\n"
        "subl %edi, %eax\n" /* ci */
        "shll $4, %eax\n"
        "movl %eax, -0x420(%ebp)\n" /* ent */
        "movl 0x195f688, %eax\n"
        "addl %eax, -0x420(%ebp)\n" /* ent */
        "movl %edi, %esi\n" /* line 358 | ci, client */
        "shll $6, %esi\n" /* client */
        "leal (%edi, %esi), %esi\n" /* ci, client */
        "movl 8(%ebp), %eax\n" /* clientNum */
        "leal (%eax, %esi, 8), %esi\n" /* client */
        "movl 0x195f6a0, %eax\n"
        "movl (%eax), %eax\n"
        "leal (%eax, %esi, 4), %esi\n" /* client */
        "movl $0x28a4, 8(%esp)\n" /* line 360 */
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* client */
        "calll memset\n"
        "movl %edi, %ebx\n" /* line 362 | ci */
        "shll $4, %ebx\n"
        "subl %edi, %ebx\n" /* ci */
        "movl 8(%ebp), %eax\n" /* clientNum */
        "leal (%eax, %ebx, 2), %ebx\n"
        "movl 0x195f68c, %eax\n"
        "leal 0xb3bf0(%eax, %ebx, 8), %ebx\n"
        "leal 0xc(%ebx), %edi\n" /* ci */
        "movl 0x4a4(%edi), %eax\n" /* line 363 | ci */
        "movl %eax, -0x41c(%ebp)\n" /* pXAnimTree */
        "movl $0x4b8, 8(%esp)\n" /* line 364 */
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ci */
        "calll memset\n"
        "movl -0x41c(%ebp), %eax\n" /* line 365 | pXAnimTree */
        "movl %eax, 0x4a4(%edi)\n" /* ci */
        "movl $1, 0xc(%ebx)\n" /* line 367 */
        "movl $1, 4(%edi)\n" /* line 368 | ci */
        "movl $1, 0x26c4(%esi)\n" /* line 370 | client */
        "movl -0x424(%ebp), %eax\n" /* line 371 */
        "movw %ax, 0x26c0(%esi)\n" /* client */
        "movl $3, 0x274c(%esi)\n" /* line 374 | client */
        "movl $2, 0x26a8(%esi)\n" /* line 375 | client */
        "movl $0xffffffff, 0x27a8(%esi)\n" /* line 376 | client */
        "movl $0xffffffff, 0x26ac(%esi)\n" /* line 377 | client */
        "movl -0x420(%ebp), %eax\n" /* line 379 | ent */
        "movl %eax, (%esp)\n"
        "calll G_InitGentity\n"
        "movl -0x420(%ebp), %eax\n" /* line 380 | ent */
        "movb $0, 0x166(%eax)\n"
        "movl %esi, 0x158(%eax)\n" /* line 381 | client */
        "movl $0x3ff, 0x2830(%esi)\n" /* line 383 | client */
        "movl 8(%ebp), %eax\n" /* line 384 | clientNum */
        "movl %eax, 0x2748(%esi)\n" /* client */
        "movl %eax, 0xcc(%esi)\n" /* line 385 | client */
        "movl %eax, (%esp)\n" /* line 391 */
        "calll ClientUserinfoChanged\n"
        "movl $0x400, 8(%esp)\n" /* line 393 */
        "leal -0x418(%ebp), %ebx\n" /* userinfo */
        "movl %ebx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* clientNum */
        "movl %eax, (%esp)\n"
        "calll SV_GetUserinfo\n"
        "movl 0x2700(%esi), %eax\n" /* line 396 | client */
        "testl %eax, %eax\n"
        "jne .Lf191770_001918fc\n"
        "movl $0x2a8fa0, 4(%esp)\n" /* line 399 */
        "movl %ebx, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, %esi\n" /* client */
        "movl 0x195f698, %ebx\n" /* line 400 */
        "movl (%ebx), %eax\n"
        "movl 8(%eax), %eax\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf191770_0019191c\n"
        ".Lf191770_001918fc:\n"
        "movl -0x420(%ebp), %eax\n" /* line 408 | ent */
        "movl %eax, (%esp)\n"
        "calll Scr_PlayerConnect\n"
        "calll CalculateRanks\n" /* line 411 */
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf191770_00191911:\n"
        "addl $0x42c, %esp\n" /* line 414 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf191770_0019191c:\n"
        "movl $0x218298, 4(%esp)\n" /* line 400 */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf191770_001918fc\n"
        "movl (%ebx), %eax\n"
        "movl %esi, 4(%esp)\n" /* client */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf191770_001918fc\n"
        "movl -0x420(%ebp), %eax\n" /* line 402 | ent */
        "movl %eax, (%esp)\n"
        "calll G_FreeEntity\n"
        "movl $0x2b01b0, %eax\n" /* "GAME_INVALIDPASSWORD" */
        "jmp .Lf191770_00191911\n"
    );
}

