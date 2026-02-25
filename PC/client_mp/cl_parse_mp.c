/* ASM dump from: cl_parse_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/client_mp/cl_parse_mp.cpp */

#include "common_types.h"
#include "imports.h"

extern int cl_connectedToPureServer; /* 0x0 */
extern char * svc_strings[256]; /* 0x0 */

void CL_SystemInfoChanged(void);
void CL_ParseGamestate(msg_t *msg);
void CL_ParseDownload(msg_t *msg);
void CL_ParseSnapshot(msg_t *msg);
void CL_ParseServerMessage(msg_t *msg);

/* line 572 */
__attribute__((naked))
void CL_SystemInfoChanged(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 572 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl $0x2000, 4(%esp)\n" /* line 579 */
        "leal -0x20(%ebp), %eax\n" /* key_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_LargeLocal\n"
        "leal -0x20(%ebp), %eax\n" /* key_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_GetBuf\n"
        "movl %eax, %esi\n" /* key */
        "movl $0x2000, 4(%esp)\n" /* line 580 */
        "leal -0x24(%ebp), %eax\n" /* value_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_LargeLocal\n"
        "leal -0x24(%ebp), %eax\n" /* value_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_GetBuf\n"
        "movl %eax, -0x2c(%ebp)\n" /* value */
        "movl 0x195ee78, %eax\n" /* line 582 */
        "movl (%eax), %ebx\n"
        "movl 0x2710(%ebx), %eax\n"
        "leal 0x470c(%ebx, %eax), %edi\n" /* systemInfo */
        "movl $0x2a71e4, 4(%esp)\n" /* line 583 */
        "movl %edi, (%esp)\n" /* systemInfo */
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x8628(%ebx)\n"
        "movl 0x195ee8c, %eax\n" /* line 586 */
        "movl (%eax), %eax\n"
        "movl 0x407a0(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lf1d2ec6_001d3053\n"
        "movl $0x2198ac, 4(%esp)\n" /* line 591 */
        "movl %edi, (%esp)\n" /* systemInfo */
        "calll Info_ValueForKey\n"
        "movl %eax, -0x1c(%ebp)\n" /* s */
        "movl %eax, (%esp)\n" /* line 592 */
        "calll atoi\n"
        "testl %eax, %eax\n"
        "je .Lf1d2ec6_001d3071\n"
        ".Lf1d2ec6_001d2f7a:\n"
        "movl $0x2a71f8, 4(%esp)\n" /* line 597 */
        "movl %edi, (%esp)\n" /* systemInfo */
        "calll Info_ValueForKey\n"
        "movl %eax, -0x1c(%ebp)\n" /* s */
        "movl $0x2a7200, 4(%esp)\n" /* line 598 */
        "movl %edi, (%esp)\n" /* systemInfo */
        "calll Info_ValueForKey\n"
        "movl %eax, 4(%esp)\n" /* line 599 */
        "movl -0x1c(%ebp), %eax\n" /* s */
        "movl %eax, (%esp)\n"
        "calll FS_PureServerSetLoadedIwds\n"
        "movl $0x2a720c, 4(%esp)\n" /* line 601 */
        "movl %edi, (%esp)\n" /* systemInfo */
        "calll Info_ValueForKey\n"
        "movl %eax, -0x1c(%ebp)\n" /* s */
        "movl $0x2a7220, 4(%esp)\n" /* line 602 */
        "movl %edi, (%esp)\n" /* systemInfo */
        "calll Info_ValueForKey\n"
        "movl %eax, 4(%esp)\n" /* line 603 */
        "movl -0x1c(%ebp), %eax\n" /* s */
        "movl %eax, (%esp)\n"
        "calll FS_PureServerSetReferencedIwds\n"
        "movl 0x195ecbc, %eax\n" /* line 606 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1d2ec6_001d3021\n"
        "movl %edi, -0x1c(%ebp)\n" /* line 609 | systemInfo, s */
        "leal -0x1c(%ebp), %ebx\n" /* s */
        "jmp .Lf1d2ec6_001d301a\n"
        ".Lf1d2ec6_001d2ff3:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 612 | value */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* key */
        "movl %ebx, (%esp)\n"
        "calll Info_NextPair\n"
        "cmpb $0, (%esi)\n" /* line 613 | key */
        "je .Lf1d2ec6_001d3021\n"
        "movl -0x2c(%ebp), %eax\n" /* line 618 | value */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* key */
        "calll Dvar_SetFromStringByName\n"
        ".Lf1d2ec6_001d301a:\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 610 | s */
        "testl %ecx, %ecx\n"
        "jne .Lf1d2ec6_001d2ff3\n"
        ".Lf1d2ec6_001d3021:\n"
        "movl $0x2a71f0, (%esp)\n" /* line 622 */
        "calll Dvar_GetBool\n"
        "movzbl %al, %eax\n"
        "movl %eax, cl_connectedToPureServer\n"
        "leal -0x24(%ebp), %eax\n" /* value_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "leal -0x20(%ebp), %eax\n" /* key_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 624 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d2ec6_001d3053:\n"
        "leal -0x24(%ebp), %eax\n" /* line 622 | value_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "leal -0x20(%ebp), %eax\n" /* key_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 624 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d2ec6_001d3071:\n"
        "calll Dvar_SetCheatState\n" /* line 593 */
        "jmp .Lf1d2ec6_001d2f7a\n"
        "movl %eax, %ebx\n"
        "leal -0x24(%ebp), %eax\n" /* line 622 | value_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        ".Lf1d2ec6_001d3088:\n"
        "leal -0x20(%ebp), %eax\n" /* key_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n"
        "jmp .Lf1d2ec6_001d3088\n"
    );
}

/* line 632 */
__attribute__((naked))
void CL_ParseGamestate(msg_t *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 632 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x12c, %esp\n"
        /* { scope 1 */
        "calll Con_Close\n" /* line 641 */
        "movl 0x195ee8c, %eax\n" /* line 643 */
        "movl (%eax), %ebx\n" /* newnum */
        "movl $0, 0x24(%ebx)\n" /* newnum */
        "calll CL_ClearState\n" /* line 646 */
        "movl 8(%ebp), %eax\n" /* line 649 | msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadLong\n"
        "movl %eax, 0x2013c(%ebx)\n" /* newnum */
        "movl 0x195ee78, %edx\n" /* line 652 */
        "movl (%edx), %eax\n"
        "movl $1, 0x858c(%eax)\n"
        "movl %edx, -0x124(%ebp)\n"
        ".Lf1d30a0_001d30ed:\n"
        "movl 8(%ebp), %edx\n" /* line 655 | msg */
        "movl %edx, (%esp)\n"
        "calll MSG_ReadByte\n"
        "cmpl $7, %eax\n" /* line 657 */
        "je .Lf1d30a0_001d3133\n"
        ".Lf1d30a0_001d30fd:\n"
        "cmpl $2, %eax\n" /* line 662 */
        "je .Lf1d30a0_001d3244\n"
        "cmpl $3, %eax\n" /* line 684 */
        "je .Lf1d30a0_001d31cb\n"
        "movl $0x2b7670, 4(%esp)\n" /* line 697 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 8(%ebp), %edx\n" /* line 655 | msg */
        "movl %edx, (%esp)\n"
        "calll MSG_ReadByte\n"
        "cmpl $7, %eax\n" /* line 657 */
        "jne .Lf1d30a0_001d30fd\n"
        ".Lf1d30a0_001d3133:\n"
        "movl 0x195ee8c, %eax\n" /* line 701 */
        "movl (%eax), %ebx\n" /* newnum */
        "movl 8(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_ReadLong\n"
        "movl %eax, 8(%ebx)\n" /* newnum */
        "movl 8(%ebp), %ecx\n" /* line 703 | msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_ReadLong\n"
        "movl %eax, 0x12c(%ebx)\n" /* newnum */
        "calll CL_SystemInfoChanged\n" /* line 706 */
        "movl 0x12c(%ebx), %eax\n" /* line 710 | newnum */
        "movl %eax, (%esp)\n"
        "calll FS_ConditionalRestart\n"
        "movl 0x195f354, %eax\n" /* line 720 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1d30a0_001d319f\n"
        "movl 0x14(%ebx), %ecx\n" /* newnum */
        "movl %ecx, -0x24(%ebp)\n"
        "movl 0x18(%ebx), %edx\n" /* newnum */
        "movl %edx, -0x20(%ebp)\n"
        "movl 0x1c(%ebx), %eax\n" /* newnum */
        "movl %eax, -0x1c(%ebp)\n"
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll Sys_IsLANAddress\n"
        "testl %eax, %eax\n"
        "jne .Lf1d30a0_001d31a4\n"
        ".Lf1d30a0_001d319f:\n"
        "calll CL_RequestAuthorization\n" /* line 721 */
        ".Lf1d30a0_001d31a4:\n"
        "calll CL_InitDownloads\n" /* line 726 */
        "movl $0, 4(%esp)\n" /* line 732 */
        "movl 0x195ed18, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        /* } scope */
        "addl $0x12c, %esp\n" /* line 733 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d30a0_001d31cb:\n"
        "movl $0xa, 4(%esp)\n" /* line 686 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_ReadBits\n"
        "movl %eax, %ebx\n" /* newnum */
        "cmpl $0x3ff, %eax\n" /* line 687 */
        "ja .Lf1d30a0_001d32df\n"
        ".Lf1d30a0_001d31eb:\n"
        "movl $0xf0, 8(%esp)\n" /* line 691 */
        "movl $0, 4(%esp)\n"
        "leal -0x114(%ebp), %eax\n" /* nullstate */
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl %ebx, 0xc(%esp)\n" /* line 693 | newnum */
        "movl %ebx, %eax\n" /* newnum */
        "shll $4, %eax\n"
        "shll $8, %ebx\n" /* newnum */
        "subl %eax, %ebx\n" /* newnum */
        "movl -0x124(%ebp), %edx\n"
        "movl (%edx), %eax\n"
        "leal 0x970e0(%ebx, %eax), %eax\n" /* newnum */
        "movl %eax, 8(%esp)\n"
        "leal -0x114(%ebp), %ecx\n" /* nullstate */
        "movl %ecx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadDeltaEntity\n"
        "jmp .Lf1d30a0_001d30ed\n"
        /* { scope 2 */
        ".Lf1d30a0_001d3244:\n"
        "movl 8(%ebp), %ecx\n" /* line 666 | msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_ReadShort\n"
        "movl %eax, -0x120(%ebp)\n" /* i */
        "cmpl $0x7ff, %eax\n" /* line 667 */
        "ja .Lf1d30a0_001d32fc\n"
        ".Lf1d30a0_001d3260:\n"
        "movl 8(%ebp), %eax\n" /* line 671 | msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadBigString\n"
        "movl %eax, -0x11c(%ebp)\n" /* s */
        "cld\n" /* line 672 */
        "xorl %eax, %eax\n"
        "movl $0xffffffff, %ecx\n"
        "movl -0x11c(%ebp), %edi\n" /* s, len */
        "repne scasb %es:(%edi), %al\n" /* len */
        "movl %ecx, %esi\n"
        "notl %esi\n"
        "leal -1(%esi), %edi\n" /* len */
        "movl -0x124(%ebp), %eax\n" /* line 674 */
        "movl (%eax), %ebx\n" /* newnum */
        "movl 0x858c(%ebx), %edx\n" /* newnum */
        "leal 1(%edi, %edx), %eax\n" /* len */
        "cmpl $0x3e80, %eax\n"
        "jg .Lf1d30a0_001d3315\n"
        ".Lf1d30a0_001d32a1:\n"
        "movl -0x120(%ebp), %ecx\n" /* line 680 | i */
        "movl %edx, 0x270c(%ebx, %ecx, 4)\n" /* newnum */
        "leal 0x470c(%ebx, %edx), %eax\n" /* line 681 | newnum */
        "movl %esi, 8(%esp)\n"
        "movl -0x11c(%ebp), %edx\n" /* s */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "addl 0x858c(%ebx), %edi\n" /* line 682 | newnum, len */
        "leal 1(%edi), %eax\n" /* len */
        "movl %eax, 0x858c(%ebx)\n" /* newnum */
        "jmp .Lf1d30a0_001d30ed\n"
        /* } scope */
        ".Lf1d30a0_001d32df:\n"
        "movl %eax, 8(%esp)\n" /* line 689 */
        "movl $0x2b764c, 4(%esp)\n" /* "Baseline number out of range: %i" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1d30a0_001d31eb\n"
        /* { scope 2 */
        ".Lf1d30a0_001d32fc:\n"
        "movl $0x2ada90, 4(%esp)\n" /* line 669 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1d30a0_001d3260\n"
        ".Lf1d30a0_001d3315:\n"
        "movl $0x2adab4, 4(%esp)\n" /* line 676 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0x858c(%ebx), %edx\n" /* newnum */
        "jmp .Lf1d30a0_001d32a1\n"
    );
}

/* line 748 */
__attribute__((naked))
void CL_ParseDownload(msg_t *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 748 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl $0x4000, 4(%esp)\n" /* line 752 */
        "leal -0x1c(%ebp), %eax\n" /* data_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_LargeLocal\n"
        "leal -0x1c(%ebp), %edx\n" /* data_large_local */
        "movl %edx, (%esp)\n"
        "calll LargeLocal_GetBuf\n"
        "movl %eax, -0x2c(%ebp)\n" /* data */
        "movl 8(%ebp), %eax\n" /* line 755 | msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadShort\n"
        "movl %eax, %esi\n" /* block */
        "testl %eax, %eax\n" /* line 757 */
        "jne .Lf1d3334_001d33a0\n"
        "movl 0x195ee8c, %eax\n" /* line 760 */
        "movl (%eax), %ebx\n"
        "movl 8(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_ReadLong\n"
        "movl %eax, 0x40354(%ebx)\n"
        "movl 0x195ecb4, %edx\n" /* line 762 */
        "movl (%edx), %edx\n"
        "movl %eax, 0x10(%edx)\n"
        "movl 0x40354(%ebx), %edi\n" /* line 764 | size */
        "testl %edi, %edi\n" /* size */
        "js .Lf1d3334_001d3542\n"
        ".Lf1d3334_001d33a0:\n"
        "movl 8(%ebp), %edx\n" /* line 771 | msg */
        "movl %edx, (%esp)\n"
        "calll MSG_ReadShort\n"
        "movl %eax, %edi\n" /* size */
        "testl %eax, %eax\n" /* line 772 */
        "jle .Lf1d3334_001d33c7\n"
        "movl %eax, 8(%esp)\n" /* line 773 */
        "movl -0x2c(%ebp), %eax\n" /* data */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_ReadData\n"
        ".Lf1d3334_001d33c7:\n"
        "movl 0x195ee8c, %eax\n" /* line 775 */
        "movl (%eax), %ebx\n"
        "movl 0x4034c(%ebx), %eax\n"
        "cmpl %eax, %esi\n" /* block */
        "je .Lf1d3334_001d340b\n"
        "movl %esi, 8(%esp)\n" /* line 777 | block */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b7698, (%esp)\n" /* "CL_ParseDownload: Expected block %d, got %d
" */
        "calll Com_DPrintf\n"
        "cmpl 0x4034c(%ebx), %esi\n" /* line 779 | block */
        "jg .Lf1d3334_001d3572\n"
        ".Lf1d3334_001d33f8:\n"
        "leal -0x1c(%ebp), %edx\n" /* line 843 | data_large_local */
        "movl %edx, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 844 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d3334_001d340b:\n"
        "movl 0x40144(%ebx), %esi\n" /* line 789 | block */
        "testl %esi, %esi\n" /* block */
        "jne .Lf1d3334_001d343e\n"
        "cmpb $0, 0x40148(%ebx)\n" /* line 791 */
        "je .Lf1d3334_001d34f6\n"
        "leal 0x40148(%ebx), %esi\n" /* line 798 | block */
        "movl %esi, (%esp)\n" /* block */
        "calll FS_SV_FOpenFileWrite\n"
        "movl %eax, 0x40144(%ebx)\n"
        "testl %eax, %eax\n" /* line 800 */
        "je .Lf1d3334_001d35a1\n"
        ".Lf1d3334_001d343e:\n"
        "testl %edi, %edi\n" /* line 809 | size */
        "jne .Lf1d3334_001d34d0\n"
        ".Lf1d3334_001d3446:\n"
        "movl 0x195ee8c, %edx\n" /* line 812 */
        "movl (%edx), %ebx\n"
        "movl 0x4034c(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b7770, (%esp)\n" /* "nextdl %d" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll CL_AddReliableCommand\n"
        "addl $1, 0x4034c(%ebx)\n" /* line 813 */
        "movl %edi, %edx\n" /* line 815 | size */
        "addl 0x40350(%ebx), %edx\n"
        "movl %edx, 0x40350(%ebx)\n"
        "movl 0x195ecb4, %esi\n" /* line 818 | block */
        "movl (%esi), %eax\n" /* block */
        "movl %edx, 0x14(%eax)\n"
        "testl %edi, %edi\n" /* line 820 | size */
        "jne .Lf1d3334_001d34bd\n"
        "movl 0x40144(%ebx), %eax\n" /* line 822 */
        "testl %eax, %eax\n"
        "jne .Lf1d3334_001d3513\n"
        ".Lf1d3334_001d349a:\n"
        "movb $0, 0x40248(%ebx)\n" /* line 830 */
        "movb $0, 0x40148(%ebx)\n"
        "movl (%esi), %eax\n" /* line 831 | block */
        "movb $0, 0x1c(%eax)\n"
        "calll CL_WritePacket\n" /* line 838 */
        "calll CL_WritePacket\n" /* line 839 */
        "calll CL_NextDownload\n" /* line 842 */
        ".Lf1d3334_001d34bd:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 843 | data_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 844 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d3334_001d34d0:\n"
        "movl 0x195ee8c, %edx\n" /* line 810 */
        "movl (%edx), %eax\n"
        "movl 0x40144(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* size */
        "movl -0x2c(%ebp), %eax\n" /* data */
        "movl %eax, (%esp)\n"
        "calll FS_Write\n"
        "jmp .Lf1d3334_001d3446\n"
        ".Lf1d3334_001d34f6:\n"
        "movl $0x2b7720, (%esp)\n" /* line 793 */
        "calll Com_Printf\n"
        "movl $0x2adec4, (%esp)\n" /* line 794 */
        "calll CL_AddReliableCommand\n"
        "jmp .Lf1d3334_001d33f8\n"
        ".Lf1d3334_001d3513:\n"
        "movl %eax, (%esp)\n" /* line 824 */
        "calll FS_FCloseFile\n"
        "movl $0, 0x40144(%ebx)\n" /* line 825 */
        "leal 0x40248(%ebx), %eax\n" /* line 828 */
        "movl %eax, 4(%esp)\n"
        "leal 0x40148(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_SV_Rename\n"
        "jmp .Lf1d3334_001d349a\n"
        ".Lf1d3334_001d3542:\n"
        "movl 8(%ebp), %eax\n" /* line 766 | msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadString\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x216058, (%esp)\n" /* "%s" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1d3334_001d33f8\n"
        ".Lf1d3334_001d3572:\n"
        "movl $0x2b76c8, (%esp)\n" /* line 781 */
        "calll Com_DPrintf\n"
        "movl 0x4034c(%ebx), %eax\n" /* line 782 */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b7710, (%esp)\n" /* "retransdl %d" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll CL_AddReliableCommand\n"
        "jmp .Lf1d3334_001d33f8\n"
        ".Lf1d3334_001d35a1:\n"
        "movl %esi, 4(%esp)\n" /* line 802 | block */
        "movl $0x2b7758, (%esp)\n" /* "Could not create %s
" */
        "calll Com_Printf\n"
        "movl $0x2adec4, (%esp)\n" /* line 803 */
        "calll CL_AddReliableCommand\n"
        "calll CL_NextDownload\n" /* line 804 */
        "jmp .Lf1d3334_001d33f8\n"
        "movl %eax, %ebx\n"
        "leal -0x1c(%ebp), %eax\n" /* line 843 | data_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 407 */
__attribute__((naked))
void CL_ParseSnapshot(msg_t *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 407 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        /* { scope 1: oldindex, oldindex, dummy */
        "movl $0x26d8, 4(%esp)\n" /* line 413 */
        "leal -0x1c(%ebp), %eax\n" /* newSnap_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_LargeLocal\n"
        "leal -0x1c(%ebp), %edx\n" /* newSnap_large_local */
        "movl %edx, (%esp)\n"
        "calll LargeLocal_GetBuf\n"
        "movl %eax, -0x90(%ebp)\n" /* newSnap */
        "movl $0x26d8, 8(%esp)\n" /* line 421 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl 0x195ee8c, %eax\n" /* line 425 */
        "movl (%eax), %ebx\n" /* oldMessageNum */
        "movl 0x2013c(%ebx), %eax\n" /* oldMessageNum */
        "movl -0x90(%ebp), %ecx\n" /* newSnap */
        "movl %eax, 0x26d4(%ecx)\n"
        "movl 8(%ebp), %eax\n" /* line 427 | msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadLong\n"
        "movl -0x90(%ebp), %edx\n" /* newSnap */
        "movl %eax, 8(%edx)\n"
        "movl 0x20138(%ebx), %eax\n" /* line 429 | oldMessageNum */
        "movl %eax, 0xc(%edx)\n"
        "movl 8(%ebp), %ecx\n" /* line 431 | msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_ReadByte\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 432 */
        "jne .Lf1d35dc_001d3cab\n"
        "movl -0x90(%ebp), %eax\n" /* line 434 | newSnap */
        "movl $0xffffffff, 0x10(%eax)\n"
        ".Lf1d35dc_001d367c:\n"
        "movl 8(%ebp), %eax\n" /* line 440 | msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadByte\n"
        "movl -0x90(%ebp), %edx\n" /* newSnap */
        "movl %eax, 4(%edx)\n"
        "movl 0x10(%edx), %ebx\n" /* line 446 | oldMessageNum */
        "testl %ebx, %ebx\n" /* oldMessageNum */
        "jle .Lf1d35dc_001d420d\n"
        "movl 0x195ee78, %eax\n" /* line 454 */
        "movl (%eax), %esi\n" /* newnum */
        "movl %ebx, %edx\n" /* oldMessageNum */
        "andl $0x1f, %edx\n"
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $5, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "leal 0x495e0(%esi, %eax, 8), %eax\n" /* newnum */
        "movl %eax, -0x94(%ebp)\n" /* old */
        "movl (%eax), %edi\n" /* line 455 | newnum */
        "testl %edi, %edi\n" /* newnum */
        "je .Lf1d35dc_001d41fc\n"
        "movl %eax, %ecx\n"
        "cmpl 0xc(%eax), %ebx\n" /* line 460 | oldMessageNum */
        "je .Lf1d35dc_001d3cbe\n"
        "movl $0x2b77b4, (%esp)\n" /* line 464 */
        "calll Com_DPrintf\n"
        ".Lf1d35dc_001d36e5:\n"
        "movl 0x195f5e4, %eax\n" /* line 52 */
        "movl (%eax), %eax\n"
        "cmpl $1, 8(%eax)\n"
        "jle .Lf1d35dc_001d3713\n"
        "movl $0x2b7810, 8(%esp)\n" /* line 54 */
        "movl 8(%ebp), %edx\n" /* msg */
        "movl 0x10(%edx), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b7644, (%esp)\n" /* "%3i:%s
" */
        "calll Com_Printf\n"
        ".Lf1d35dc_001d3713:\n"
        "movl -0x94(%ebp), %esi\n" /* line 482 | old, newnum */
        "testl %esi, %esi\n" /* newnum */
        "je .Lf1d35dc_001d4298\n"
        "movl -0x90(%ebp), %eax\n" /* line 484 | newSnap */
        "addl $0x1c, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x94(%ebp), %eax\n" /* old */
        "addl $0x1c, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_ReadDeltaPlayerstate\n"
        ".Lf1d35dc_001d3746:\n"
        "movl 0x195f5e4, %eax\n" /* line 52 */
        "movl (%eax), %eax\n"
        "cmpl $1, 8(%eax)\n"
        "jle .Lf1d35dc_001d3774\n"
        "movl $0x2b781c, 8(%esp)\n" /* line 54 */
        "movl 8(%ebp), %edx\n" /* msg */
        "movl 0x10(%edx), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b7644, (%esp)\n" /* "%3i:%s
" */
        "calll Com_Printf\n"
        /* { scope 2: old, old, newnum */
        ".Lf1d35dc_001d3774:\n"
        "movl 0x195ee78, %eax\n" /* line 142 */
        "movl (%eax), %ecx\n"
        "movl 0x85d0(%ecx), %eax\n"
        "movl -0x90(%ebp), %edx\n" /* newSnap */
        "movl %eax, 0x26cc(%edx)\n"
        "movl $0, 0x26c4(%edx)\n" /* line 143 */
        "movl -0x94(%ebp), %ebx\n" /* line 148 | old */
        "testl %ebx, %ebx\n"
        "je .Lf1d35dc_001d41a6\n"
        "movl -0x94(%ebp), %eax\n" /* line 154 | old */
        "movl 0x26c4(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf1d35dc_001d41a6\n"
        "movl 0x26cc(%eax), %eax\n" /* line 160 */
        "andl $0x7ff, %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "shll $8, %eax\n"
        "subl %edx, %eax\n"
        "leal 0xd30e0(%eax, %ecx), %eax\n"
        "movl %eax, -0x88(%ebp)\n" /* old */
        "movl (%eax), %edi\n" /* line 161 */
        ".Lf1d35dc_001d37dd:\n"
        "movl $0, -0x8c(%ebp)\n" /* line 148 | oldindex */
        ".Lf1d35dc_001d37e7:\n"
        "movl 8(%ebp), %ecx\n" /* line 165 | msg */
        "movl (%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1d35dc_001d38b5\n"
        ".Lf1d35dc_001d37f4:\n"
        "movl $0xa, 4(%esp)\n" /* line 168 */
        "movl %ecx, (%esp)\n"
        "calll MSG_ReadBits\n"
        "movl %eax, %esi\n"
        "cmpl $0x3ff, %eax\n" /* line 170 */
        "je .Lf1d35dc_001d38b5\n"
        "movl 8(%ebp), %edx\n" /* line 175 | msg */
        "movl 0x10(%edx), %eax\n"
        "cmpl 0xc(%edx), %eax\n"
        "jg .Lf1d35dc_001d3edb\n"
        ".Lf1d35dc_001d3820:\n"
        "cmpl %edi, %esi\n" /* line 180 */
        "jg .Lf1d35dc_001d3d55\n"
        ".Lf1d35dc_001d3828:\n"
        "cmpl %esi, %edi\n" /* line 201 */
        "je .Lf1d35dc_001d3ef4\n"
        "movl 0x195f5e4, %eax\n" /* line 227 */
        "movl (%eax), %eax\n"
        "cmpl $3, 8(%eax)\n"
        "je .Lf1d35dc_001d3fc4\n"
        ".Lf1d35dc_001d3841:\n"
        "movl 0x195ee78, %eax\n" /* line 231 */
        "movl (%eax), %ebx\n"
        /* { scope 3 */
        "movl %esi, 0xc(%esp)\n" /* line 90 */
        "movl 0x85d0(%ebx), %eax\n"
        "andl $0x7ff, %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "shll $8, %eax\n"
        "subl %edx, %eax\n"
        "leal 0xd30e0(%eax, %ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %esi, %eax\n"
        "shll $4, %eax\n"
        "shll $8, %esi\n"
        "subl %eax, %esi\n"
        "leal 0x970e0(%esi, %ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadDeltaEntity\n"
        "testl %eax, %eax\n"
        "jne .Lf1d35dc_001d37e7\n"
        "addl $1, 0x85d0(%ebx)\n" /* line 94 */
        "movl -0x90(%ebp), %edx\n" /* line 95 | newSnap */
        "addl $1, 0x26c4(%edx)\n"
        /* } scope */
        "movl 8(%ebp), %ecx\n" /* line 165 | msg */
        "movl (%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1d35dc_001d37f4\n"
        ".Lf1d35dc_001d38b5:\n"
        "cmpl $0x1869f, %edi\n" /* line 235 */
        "je .Lf1d35dc_001d397d\n"
        ".Lf1d35dc_001d38c1:\n"
        "movl 8(%ebp), %eax\n" /* msg */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1d35dc_001d397d\n"
        "movl 0x195f5e4, %eax\n" /* line 238 */
        "movl (%eax), %eax\n"
        "cmpl $3, 8(%eax)\n"
        "je .Lf1d35dc_001d42bd\n"
        /* { scope 3 */
        ".Lf1d35dc_001d38df:\n"
        "movl 0x195ee78, %eax\n" /* line 82 */
        "movl (%eax), %ebx\n"
        "movl 0x85d0(%ebx), %eax\n" /* line 86 */
        "andl $0x7ff, %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "shll $8, %eax\n"
        "subl %edx, %eax\n"
        "leal 0xd30e0(%eax, %ebx), %eax\n"
        "movl $0xf0, 8(%esp)\n"
        "movl -0x88(%ebp), %ecx\n" /* old */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "addl $1, 0x85d0(%ebx)\n" /* line 94 */
        "movl -0x90(%ebp), %eax\n" /* line 95 | newSnap */
        "addl $1, 0x26c4(%eax)\n"
        /* } scope */
        "addl $1, -0x8c(%ebp)\n" /* line 244 | oldindex */
        "movl -0x8c(%ebp), %ecx\n" /* line 246 | oldindex */
        "movl -0x94(%ebp), %edx\n" /* old */
        "cmpl 0x26c4(%edx), %ecx\n"
        "jge .Lf1d35dc_001d397d\n"
        "movl %ecx, %eax\n" /* line 252 */
        "addl 0x26cc(%edx), %eax\n"
        "andl $0x7ff, %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "shll $8, %eax\n"
        "subl %edx, %eax\n"
        "leal 0xd30e0(%eax, %ebx), %eax\n"
        "movl %eax, -0x88(%ebp)\n" /* old */
        "movl (%eax), %edi\n" /* line 253 | newnum */
        "cmpl $0x1869f, %edi\n" /* line 235 */
        "jne .Lf1d35dc_001d38c1\n"
        ".Lf1d35dc_001d397d:\n"
        "movl 0x195f870, %eax\n" /* line 257 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1d35dc_001d41ba\n"
        /* } scope */
        ".Lf1d35dc_001d398e:\n"
        "movl 0x195f5e4, %eax\n" /* line 52 */
        "movl (%eax), %eax\n"
        "cmpl $1, 8(%eax)\n"
        "jle .Lf1d35dc_001d39bc\n"
        "movl $0x2b78ac, 8(%esp)\n" /* line 54 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 0x10(%ecx), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b7644, (%esp)\n" /* "%3i:%s
" */
        "calll Com_Printf\n"
        /* { scope 2: old, old, newnum */
        ".Lf1d35dc_001d39bc:\n"
        "movl 0x195ee78, %eax\n" /* line 277 */
        "movl (%eax), %ecx\n"
        "movl 0x85d4(%ecx), %eax\n"
        "movl -0x90(%ebp), %edx\n" /* newSnap */
        "movl %eax, 0x26d0(%edx)\n"
        "movl $0, 0x26c8(%edx)\n" /* line 278 */
        "movl -0x94(%ebp), %esi\n" /* line 283 | old, newnum */
        "testl %esi, %esi\n" /* newnum */
        "je .Lf1d35dc_001d4193\n"
        "movl -0x94(%ebp), %eax\n" /* line 289 | old */
        "movl 0x26c8(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jle .Lf1d35dc_001d4193\n"
        "movl 0x26d0(%eax), %edx\n" /* line 295 */
        "andl $0x7ff, %edx\n"
        "leal (%edx, %edx, 2), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "leal 0x14b0e0(%ecx, %eax, 4), %eax\n"
        "movl %eax, -0x80(%ebp)\n" /* old */
        "movl (%eax), %edx\n" /* line 296 */
        "movl %edx, -0x7c(%ebp)\n" /* newnum */
        ".Lf1d35dc_001d3a24:\n"
        "movl $0, -0x84(%ebp)\n" /* line 283 | oldindex */
        ".Lf1d35dc_001d3a2e:\n"
        "movl 8(%ebp), %edx\n" /* line 300 | msg */
        "movl (%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf1d35dc_001d3b9c\n"
        ".Lf1d35dc_001d3a3b:\n"
        "movl %edx, (%esp)\n" /* line 302 */
        "calll MSG_ReadBit\n"
        "testl %eax, %eax\n"
        "je .Lf1d35dc_001d3b9c\n"
        "movl $6, 4(%esp)\n" /* line 306 */
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadBits\n"
        "movl %eax, %edi\n" /* newnum */
        "movl 8(%ebp), %edx\n" /* line 308 | msg */
        "movl 0x10(%edx), %eax\n"
        "cmpl 0xc(%edx), %eax\n"
        "jg .Lf1d35dc_001d3e2f\n"
        ".Lf1d35dc_001d3a6f:\n"
        "cmpl -0x7c(%ebp), %edi\n" /* line 313 | newnum */
        "jle .Lf1d35dc_001d3b05\n"
        ".Lf1d35dc_001d3a78:\n"
        "movl 0x195f5e4, %eax\n" /* line 316 */
        "movl (%eax), %eax\n"
        "cmpl $3, 8(%eax)\n"
        "je .Lf1d35dc_001d3d33\n"
        ".Lf1d35dc_001d3a89:\n"
        "movl 0x195ee78, %eax\n" /* line 113 */
        "movl (%eax), %ebx\n"
        "movl 0x85d4(%ebx), %edx\n" /* line 117 */
        "andl $0x7ff, %edx\n"
        "leal (%edx, %edx, 2), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "leal 0x14b0e0(%ebx, %eax, 4), %eax\n"
        "movl $0x5c, 8(%esp)\n"
        "movl -0x80(%ebp), %ecx\n" /* old */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "addl $1, 0x85d4(%ebx)\n" /* line 125 */
        "movl -0x90(%ebp), %eax\n" /* line 126 | newSnap */
        "addl $1, 0x26c8(%eax)\n"
        "addl $1, -0x84(%ebp)\n" /* line 322 | oldindex */
        "movl -0x84(%ebp), %ecx\n" /* line 324 | oldindex */
        "movl -0x94(%ebp), %edx\n" /* old */
        "cmpl 0x26c8(%edx), %ecx\n"
        "jl .Lf1d35dc_001d3d03\n"
        "movl $0x1869f, -0x7c(%ebp)\n" /* newnum */
        "cmpl -0x7c(%ebp), %edi\n" /* line 313 | newnum */
        "jg .Lf1d35dc_001d3a78\n"
        ".Lf1d35dc_001d3b05:\n"
        "cmpl -0x7c(%ebp), %edi\n" /* line 334 | newnum */
        "je .Lf1d35dc_001d3e48\n"
        "movl 0x195f5e4, %eax\n" /* line 360 */
        "movl (%eax), %eax\n"
        "cmpl $3, 8(%eax)\n"
        "je .Lf1d35dc_001d3fa5\n"
        ".Lf1d35dc_001d3b1f:\n"
        "leal -0x78(%ebp), %ebx\n" /* line 364 | dummy */
        "movl $0x5c, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memset\n"
        /* { scope 3 */
        "movl 0x195ee78, %eax\n" /* line 113 */
        "movl (%eax), %esi\n"
        "movl %edi, 0xc(%esp)\n" /* line 121 */
        "movl 0x85d4(%esi), %edx\n"
        "andl $0x7ff, %edx\n"
        "leal (%edx, %edx, 2), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "leal 0x14b0e0(%esi, %eax, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl %ecx, (%esp)\n"
        "calll MSG_ReadDeltaClient\n"
        "testl %eax, %eax\n"
        "jne .Lf1d35dc_001d3a2e\n"
        "addl $1, 0x85d4(%esi)\n" /* line 125 */
        "movl -0x90(%ebp), %eax\n" /* line 126 | newSnap */
        "addl $1, 0x26c8(%eax)\n"
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 300 | msg */
        "movl (%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf1d35dc_001d3a3b\n"
        ".Lf1d35dc_001d3b9c:\n"
        "cmpl $0x1869f, -0x7c(%ebp)\n" /* line 369 | newnum */
        "je .Lf1d35dc_001d3c6b\n"
        "movl 8(%ebp), %edx\n" /* msg */
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1d35dc_001d3c6b\n"
        ".Lf1d35dc_001d3bb6:\n"
        "movl 0x195f5e4, %eax\n" /* line 372 */
        "movl (%eax), %eax\n"
        "cmpl $3, 8(%eax)\n"
        "je .Lf1d35dc_001d42dc\n"
        /* { scope 3 */
        ".Lf1d35dc_001d3bc7:\n"
        "movl 0x195ee78, %eax\n" /* line 113 */
        "movl (%eax), %ebx\n"
        "movl 0x85d4(%ebx), %edx\n" /* line 117 */
        "andl $0x7ff, %edx\n"
        "leal (%edx, %edx, 2), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "leal 0x14b0e0(%ebx, %eax, 4), %eax\n"
        "movl $0x5c, 8(%esp)\n"
        "movl -0x80(%ebp), %ecx\n" /* old */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "addl $1, 0x85d4(%ebx)\n" /* line 125 */
        "movl -0x90(%ebp), %eax\n" /* line 126 | newSnap */
        "addl $1, 0x26c8(%eax)\n"
        /* } scope */
        "addl $1, -0x84(%ebp)\n" /* line 378 | oldindex */
        "movl -0x84(%ebp), %ecx\n" /* line 380 | oldindex */
        "movl -0x94(%ebp), %edx\n" /* old */
        "cmpl 0x26c8(%edx), %ecx\n"
        "jge .Lf1d35dc_001d3c6b\n"
        "movl %edx, %eax\n"
        "movl %ecx, %edx\n" /* line 386 */
        "addl 0x26d0(%eax), %edx\n"
        "andl $0x7ff, %edx\n"
        "leal (%edx, %edx, 2), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "leal 0x14b0e0(%ebx, %eax, 4), %eax\n"
        "movl %eax, -0x80(%ebp)\n" /* old */
        "movl (%eax), %edx\n" /* line 387 */
        "movl %edx, -0x7c(%ebp)\n" /* newnum */
        "cmpl $0x1869f, %edx\n" /* line 369 */
        "je .Lf1d35dc_001d3c6b\n"
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl (%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1d35dc_001d3bb6\n"
        ".Lf1d35dc_001d3c6b:\n"
        "movl 0x195f870, %eax\n" /* line 391 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1d35dc_001d41db\n"
        /* } scope */
        ".Lf1d35dc_001d3c7c:\n"
        "movl 8(%ebp), %ecx\n" /* line 499 | msg */
        "movl (%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1d35dc_001d4075\n"
        "movl -0x90(%ebp), %eax\n" /* line 501 | newSnap */
        "movl $0, (%eax)\n"
        ".Lf1d35dc_001d3c95:\n"
        "leal -0x1c(%ebp), %edx\n" /* line 549 | newSnap_large_local */
        "movl %edx, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "addl $0x9c, %esp\n" /* line 550 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: oldindex, oldindex, dummy */
        ".Lf1d35dc_001d3cab:\n"
        "movl -0x90(%ebp), %ecx\n" /* line 438 | newSnap */
        "movl 0xc(%ecx), %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, 0x10(%ecx)\n"
        "jmp .Lf1d35dc_001d367c\n"
        ".Lf1d35dc_001d3cbe:\n"
        "movl 0x85d0(%esi), %eax\n" /* line 466 | newnum */
        "subl 0x26cc(%ecx), %eax\n"
        "cmpl $0x780, %eax\n"
        "jg .Lf1d35dc_001d4261\n"
        "movl 0x85d4(%esi), %eax\n" /* line 470 | newnum */
        "movl -0x94(%ebp), %ecx\n" /* old */
        "subl 0x26d0(%ecx), %eax\n"
        "cmpl $0x780, %eax\n"
        "jg .Lf1d35dc_001d42fe\n"
        "movl -0x90(%ebp), %eax\n" /* line 476 | newSnap */
        "movl $1, (%eax)\n"
        "jmp .Lf1d35dc_001d36e5\n"
        ".Lf1d35dc_001d3d03:\n"
        "movl %ecx, %edx\n"
        /* { scope 2: old, old, newnum */
        "movl -0x94(%ebp), %eax\n" /* line 330 | old */
        "addl 0x26d0(%eax), %edx\n"
        "andl $0x7ff, %edx\n"
        "leal (%edx, %edx, 2), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "leal 0x14b0e0(%ebx, %eax, 4), %eax\n"
        "movl %eax, -0x80(%ebp)\n" /* old */
        "movl (%eax), %edx\n" /* line 331 */
        "movl %edx, -0x7c(%ebp)\n" /* newnum */
        "jmp .Lf1d35dc_001d3a6f\n"
        ".Lf1d35dc_001d3d33:\n"
        "movl -0x7c(%ebp), %ecx\n" /* line 318 | newnum */
        "movl %ecx, 8(%esp)\n"
        "movl 8(%ebp), %edx\n" /* msg */
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b7854, (%esp)\n" /* "%3i:  unchanged: %i
" */
        "calll Com_Printf\n"
        "jmp .Lf1d35dc_001d3a89\n"
        /* } scope */
        /* { scope 2: old, old, newnum */
        ".Lf1d35dc_001d3d55:\n"
        "movl 8(%ebp), %ecx\n" /* line 180 | msg */
        "movl (%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1d35dc_001d3d7d\n"
        "jmp .Lf1d35dc_001d3828\n"
        ".Lf1d35dc_001d3d63:\n"
        "movl $0x1869f, %edi\n" /* line 191 */
        ".Lf1d35dc_001d3d68:\n"
        "cmpl %esi, %edi\n" /* line 180 */
        "jge .Lf1d35dc_001d3828\n"
        "movl 8(%ebp), %eax\n" /* msg */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1d35dc_001d3828\n"
        ".Lf1d35dc_001d3d7d:\n"
        "movl 0x195f5e4, %eax\n" /* line 183 */
        "movl (%eax), %eax\n"
        "cmpl $3, 8(%eax)\n"
        "je .Lf1d35dc_001d3f86\n"
        ".Lf1d35dc_001d3d8e:\n"
        "movl 0x195ee78, %eax\n" /* line 82 */
        "movl (%eax), %ebx\n"
        "movl 0x85d0(%ebx), %eax\n" /* line 86 */
        "andl $0x7ff, %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "shll $8, %eax\n"
        "subl %edx, %eax\n"
        "leal 0xd30e0(%eax, %ebx), %eax\n"
        "movl $0xf0, 8(%esp)\n"
        "movl -0x88(%ebp), %edx\n" /* old */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "addl $1, 0x85d0(%ebx)\n" /* line 94 */
        "movl -0x90(%ebp), %ecx\n" /* line 95 | newSnap */
        "addl $1, 0x26c4(%ecx)\n"
        "addl $1, -0x8c(%ebp)\n" /* line 189 | oldindex */
        "movl -0x8c(%ebp), %edx\n" /* line 191 | oldindex */
        "movl -0x94(%ebp), %eax\n" /* old */
        "cmpl 0x26c4(%eax), %edx\n"
        "jge .Lf1d35dc_001d3d63\n"
        "movl %edx, %eax\n"
        "movl -0x94(%ebp), %ecx\n" /* line 197 | old */
        "addl 0x26cc(%ecx), %eax\n"
        "andl $0x7ff, %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "shll $8, %eax\n"
        "subl %edx, %eax\n"
        "leal 0xd30e0(%eax, %ebx), %eax\n"
        "movl %eax, -0x88(%ebp)\n" /* old */
        "movl (%eax), %edi\n" /* line 198 */
        "jmp .Lf1d35dc_001d3d68\n"
        /* } scope */
        /* { scope 2: old, old, newnum */
        ".Lf1d35dc_001d3e2f:\n"
        "movl $0x2b78bc, 4(%esp)\n" /* line 310 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1d35dc_001d3a6f\n"
        ".Lf1d35dc_001d3e48:\n"
        "movl 0x195f5e4, %eax\n" /* line 337 */
        "movl (%eax), %eax\n"
        "cmpl $3, 8(%eax)\n"
        "je .Lf1d35dc_001d4034\n"
        ".Lf1d35dc_001d3e59:\n"
        "movl 0x195ee78, %eax\n" /* line 113 */
        "movl (%eax), %ebx\n"
        "movl -0x7c(%ebp), %ecx\n" /* line 121 | newnum */
        "movl %ecx, 0xc(%esp)\n"
        "movl 0x85d4(%ebx), %edx\n"
        "andl $0x7ff, %edx\n"
        "leal (%edx, %edx, 2), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "leal 0x14b0e0(%ebx, %eax, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x80(%ebp), %eax\n" /* old */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* msg */
        "movl %edx, (%esp)\n"
        "calll MSG_ReadDeltaClient\n"
        "testl %eax, %eax\n"
        "jne .Lf1d35dc_001d3eb0\n"
        "addl $1, 0x85d4(%ebx)\n" /* line 125 */
        "movl -0x90(%ebp), %ecx\n" /* line 126 | newSnap */
        "addl $1, 0x26c8(%ecx)\n"
        ".Lf1d35dc_001d3eb0:\n"
        "addl $1, -0x84(%ebp)\n" /* line 343 | oldindex */
        "movl -0x84(%ebp), %edx\n" /* line 345 | oldindex */
        "movl -0x94(%ebp), %eax\n" /* old */
        "cmpl 0x26c8(%eax), %edx\n"
        "jl .Lf1d35dc_001d3fe3\n"
        "movl $0x1869f, -0x7c(%ebp)\n" /* newnum */
        "jmp .Lf1d35dc_001d3a2e\n"
        /* } scope */
        /* { scope 2: old, old, newnum */
        ".Lf1d35dc_001d3edb:\n"
        "movl $0x2b782c, 4(%esp)\n" /* line 177 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1d35dc_001d3820\n"
        ".Lf1d35dc_001d3ef4:\n"
        "movl 0x195f5e4, %eax\n" /* line 204 */
        "movl (%eax), %eax\n"
        "cmpl $3, 8(%eax)\n"
        "je .Lf1d35dc_001d4056\n"
        ".Lf1d35dc_001d3f05:\n"
        "movl 0x195ee78, %eax\n" /* line 82 */
        "movl (%eax), %ebx\n"
        "movl %edi, 0xc(%esp)\n" /* line 90 */
        "movl 0x85d0(%ebx), %eax\n"
        "andl $0x7ff, %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "shll $8, %eax\n"
        "subl %edx, %eax\n"
        "leal 0xd30e0(%eax, %ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x88(%ebp), %ecx\n" /* old */
        "movl %ecx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadDeltaEntity\n"
        "testl %eax, %eax\n"
        "jne .Lf1d35dc_001d3f5d\n"
        "addl $1, 0x85d0(%ebx)\n" /* line 94 */
        "movl -0x90(%ebp), %edx\n" /* line 95 | newSnap */
        "addl $1, 0x26c4(%edx)\n"
        ".Lf1d35dc_001d3f5d:\n"
        "addl $1, -0x8c(%ebp)\n" /* line 210 | oldindex */
        "movl -0x8c(%ebp), %eax\n" /* line 212 | oldindex */
        "movl -0x94(%ebp), %ecx\n" /* old */
        "cmpl 0x26c4(%ecx), %eax\n"
        "jl .Lf1d35dc_001d400b\n"
        "movl $0x1869f, %edi\n"
        "jmp .Lf1d35dc_001d37e7\n"
        ".Lf1d35dc_001d3f86:\n"
        "movl %edi, 8(%esp)\n" /* line 185 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 0x10(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b7854, (%esp)\n" /* "%3i:  unchanged: %i
" */
        "calll Com_Printf\n"
        "jmp .Lf1d35dc_001d3d8e\n"
        /* } scope */
        /* { scope 2: old, old, newnum */
        ".Lf1d35dc_001d3fa5:\n"
        "movl %edi, 8(%esp)\n" /* line 362 | newnum */
        "movl 8(%ebp), %edx\n" /* msg */
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b7880, (%esp)\n" /* "%3i:  baseline: %i
" */
        "calll Com_Printf\n"
        "jmp .Lf1d35dc_001d3b1f\n"
        /* } scope */
        /* { scope 2: old, old, newnum */
        ".Lf1d35dc_001d3fc4:\n"
        "movl %esi, 8(%esp)\n" /* line 229 */
        "movl 8(%ebp), %ecx\n" /* msg */
        "movl 0x10(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b7880, (%esp)\n" /* "%3i:  baseline: %i
" */
        "calll Com_Printf\n"
        "jmp .Lf1d35dc_001d3841\n"
        /* } scope */
        /* { scope 2: old, old, newnum */
        ".Lf1d35dc_001d3fe3:\n"
        "addl 0x26d0(%eax), %edx\n" /* line 351 */
        "andl $0x7ff, %edx\n"
        "leal (%edx, %edx, 2), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "leal 0x14b0e0(%ebx, %eax, 4), %eax\n"
        "movl %eax, -0x80(%ebp)\n" /* old */
        "movl (%eax), %eax\n" /* line 352 */
        "movl %eax, -0x7c(%ebp)\n" /* newnum */
        "jmp .Lf1d35dc_001d3a2e\n"
        /* } scope */
        /* { scope 2: old, old, newnum */
        ".Lf1d35dc_001d400b:\n"
        "addl 0x26cc(%ecx), %eax\n" /* line 218 */
        "andl $0x7ff, %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "shll $8, %eax\n"
        "subl %edx, %eax\n"
        "leal 0xd30e0(%eax, %ebx), %eax\n"
        "movl %eax, -0x88(%ebp)\n" /* old */
        "movl (%eax), %edi\n" /* line 219 */
        "jmp .Lf1d35dc_001d37e7\n"
        /* } scope */
        /* { scope 2: old, old, newnum */
        ".Lf1d35dc_001d4034:\n"
        "movl -0x7c(%ebp), %ecx\n" /* line 339 | newnum */
        "movl %ecx, 8(%esp)\n"
        "movl 8(%ebp), %edx\n" /* msg */
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b786c, (%esp)\n" /* "%3i:  delta: %i
" */
        "calll Com_Printf\n"
        "jmp .Lf1d35dc_001d3e59\n"
        /* } scope */
        /* { scope 2: old, old, newnum */
        ".Lf1d35dc_001d4056:\n"
        "movl %edi, 8(%esp)\n" /* line 206 */
        "movl 8(%ebp), %edx\n" /* msg */
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b786c, (%esp)\n" /* "%3i:  delta: %i
" */
        "calll Com_Printf\n"
        "jmp .Lf1d35dc_001d3f05\n"
        /* } scope */
        ".Lf1d35dc_001d4075:\n"
        "movl -0x90(%ebp), %edx\n" /* line 507 | newSnap */
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1d35dc_001d3c95\n"
        "movl 0x195ee78, %ecx\n" /* line 516 */
        "movl (%ecx), %esi\n" /* newnum */
        "movl 0x24(%esi), %ebx\n" /* newnum, oldMessageNum */
        "addl $1, %ebx\n" /* oldMessageNum */
        "movl 0xc(%edx), %ecx\n" /* line 518 */
        "movl %ecx, %eax\n"
        "subl %ebx, %eax\n" /* oldMessageNum */
        "leal -0x1f(%ecx), %edx\n" /* line 520 */
        "cmpl $0x20, %eax\n"
        "cmovgel %edx, %ebx\n" /* oldMessageNum */
        "cmpl %ebx, %ecx\n" /* line 522 | oldMessageNum */
        "jg .Lf1d35dc_001d4233\n"
        ".Lf1d35dc_001d40ab:\n"
        "movl 0x195ee78, %eax\n" /* line 528 */
        "movl (%eax), %ebx\n" /* oldMessageNum */
        "movl 0x20(%ebx), %eax\n" /* oldMessageNum */
        "movl %eax, 0x2700(%ebx)\n" /* oldMessageNum */
        "leal 0x18(%ebx), %eax\n" /* line 529 | oldMessageNum */
        "movl $0x26d8, 8(%esp)\n"
        "movl -0x90(%ebp), %edx\n" /* newSnap */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0x3e7, 0x2c(%ebx)\n" /* line 530 | oldMessageNum */
        "movl 0x195ee8c, %eax\n" /* line 534 */
        "movl (%eax), %eax\n"
        "movl 0x407c8(%eax), %edi\n" /* newnum */
        "movl 0x34(%ebx), %esi\n" /* line 535 | oldMessageNum, newnum */
        "movl $1, %edx\n"
        "jmp .Lf1d35dc_001d40fe\n"
        ".Lf1d35dc_001d40f6:\n"
        "addl $1, %edx\n" /* line 538 */
        "cmpl $0x21, %edx\n" /* line 532 */
        "je .Lf1d35dc_001d4127\n"
        ".Lf1d35dc_001d40fe:\n"
        "movl %edi, %eax\n" /* line 534 | newnum */
        "subl %edx, %eax\n"
        "andl $0x1f, %eax\n"
        "leal (%eax, %eax, 2), %eax\n" /* line 535 */
        "leal (%ebx, %eax, 4), %ecx\n" /* oldMessageNum */
        "cmpl 0x49464(%ecx), %esi\n" /* newnum */
        "jl .Lf1d35dc_001d40f6\n"
        "movl 0x195ecac, %eax\n" /* line 537 */
        "movl 0x118(%eax), %eax\n"
        "subl 0x49468(%ecx), %eax\n"
        "movl %eax, 0x2c(%ebx)\n" /* oldMessageNum */
        ".Lf1d35dc_001d4127:\n"
        "movl 0x195ee78, %eax\n" /* line 542 */
        "movl (%eax), %ebx\n" /* oldMessageNum */
        "movl 0x24(%ebx), %edx\n" /* oldMessageNum */
        "andl $0x1f, %edx\n"
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $5, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "leal 0x495e0(%ebx, %eax, 8), %eax\n" /* oldMessageNum */
        "leal 0x18(%ebx), %edx\n" /* oldMessageNum */
        "movl $0x26d8, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl 0x195f5e4, %eax\n" /* line 544 */
        "movl (%eax), %eax\n"
        "cmpl $3, 8(%eax)\n"
        "je .Lf1d35dc_001d4272\n"
        ".Lf1d35dc_001d4173:\n"
        "movl $1, 0x2708(%ebx)\n" /* line 549 | oldMessageNum */
        "leal -0x1c(%ebp), %ecx\n" /* newSnap_large_local */
        "movl %ecx, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "addl $0x9c, %esp\n" /* line 550 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: oldindex, oldindex, dummy */
        /* { scope 2: old, old, newnum */
        ".Lf1d35dc_001d4193:\n"
        "movl $0, -0x80(%ebp)\n" /* line 283 | old */
        "movl $0x1869f, -0x7c(%ebp)\n" /* newnum */
        "jmp .Lf1d35dc_001d3a24\n"
        /* } scope */
        /* { scope 2: old, old, newnum */
        ".Lf1d35dc_001d41a6:\n"
        "movl $0, -0x88(%ebp)\n" /* line 148 | old */
        "movl $0x1869f, %edi\n"
        "jmp .Lf1d35dc_001d37dd\n"
        ".Lf1d35dc_001d41ba:\n"
        "movl -0x90(%ebp), %edx\n" /* line 259 | newSnap */
        "movl 0x26c4(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b7894, (%esp)\n" /* "Entities in packet: %i
" */
        "calll Com_Printf\n"
        "jmp .Lf1d35dc_001d398e\n"
        /* } scope */
        /* { scope 2: old, old, newnum */
        ".Lf1d35dc_001d41db:\n"
        "movl -0x90(%ebp), %edx\n" /* line 393 | newSnap */
        "movl 0x26c8(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b78e4, (%esp)\n" /* "Clients in packet: %i
" */
        "calll Com_Printf\n"
        "jmp .Lf1d35dc_001d3c7c\n"
        /* } scope */
        ".Lf1d35dc_001d41fc:\n"
        "movl $0x2b777c, (%esp)\n" /* line 458 */
        "calll Com_Printf\n"
        "jmp .Lf1d35dc_001d36e5\n"
        ".Lf1d35dc_001d420d:\n"
        "movl $1, (%edx)\n" /* line 448 */
        "movl 0x195ee8c, %eax\n" /* line 450 */
        "movl (%eax), %eax\n"
        "movl $0, 0x407a8(%eax)\n"
        "movl $0, -0x94(%ebp)\n" /* old */
        "jmp .Lf1d35dc_001d36e5\n"
        ".Lf1d35dc_001d4233:\n"
        "movl %ecx, %edi\n" /* newnum */
        ".Lf1d35dc_001d4235:\n"
        "movl %ebx, %eax\n" /* line 524 | oldMessageNum */
        "andl $0x1f, %eax\n"
        "leal (%eax, %eax, 4), %ecx\n"
        "movl %ecx, %edx\n"
        "shll $5, %edx\n"
        "subl %ecx, %edx\n"
        "leal (%eax, %edx, 4), %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "movl $0, 0x495e0(%esi, %edx, 8)\n" /* newnum */
        "addl $1, %ebx\n" /* line 522 | oldMessageNum */
        "cmpl %edi, %ebx\n" /* newnum, oldMessageNum */
        "jl .Lf1d35dc_001d4235\n"
        "jmp .Lf1d35dc_001d40ab\n"
        ".Lf1d35dc_001d4261:\n"
        "movl $0x2b77cc, (%esp)\n" /* line 468 */
        "calll Com_DPrintf\n"
        "jmp .Lf1d35dc_001d36e5\n"
        ".Lf1d35dc_001d4272:\n"
        "movl 0x2c(%ebx), %eax\n" /* line 546 | oldMessageNum */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x28(%ebx), %eax\n" /* oldMessageNum */
        "movl %eax, 8(%esp)\n"
        "movl 0x24(%ebx), %eax\n" /* oldMessageNum */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b78fc, (%esp)\n" /* "   snapshot:%i  delta:%i  ping:%i
" */
        "calll Com_Printf\n"
        "jmp .Lf1d35dc_001d4173\n"
        ".Lf1d35dc_001d4298:\n"
        "movl -0x90(%ebp), %eax\n" /* line 488 | newSnap */
        "addl $0x1c, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* msg */
        "movl %eax, (%esp)\n"
        "calll MSG_ReadDeltaPlayerstate\n"
        "jmp .Lf1d35dc_001d3746\n"
        /* { scope 2: old, old, newnum */
        ".Lf1d35dc_001d42bd:\n"
        "movl %edi, 8(%esp)\n" /* line 240 */
        "movl 8(%ebp), %edx\n" /* msg */
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b7854, (%esp)\n" /* "%3i:  unchanged: %i
" */
        "calll Com_Printf\n"
        "jmp .Lf1d35dc_001d38df\n"
        /* } scope */
        /* { scope 2: old, old, newnum */
        ".Lf1d35dc_001d42dc:\n"
        "movl -0x7c(%ebp), %ecx\n" /* line 374 | newnum */
        "movl %ecx, 8(%esp)\n"
        "movl 8(%ebp), %edx\n" /* msg */
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b7854, (%esp)\n" /* "%3i:  unchanged: %i
" */
        "calll Com_Printf\n"
        "jmp .Lf1d35dc_001d3bc7\n"
        /* } scope */
        ".Lf1d35dc_001d42fe:\n"
        "movl $0x2b77f0, (%esp)\n" /* line 472 */
        "calll Com_DPrintf\n"
        "jmp .Lf1d35dc_001d36e5\n"
        "movl %eax, %ebx\n" /* oldMessageNum */
        "leal -0x1c(%ebp), %eax\n" /* line 549 | newSnap_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "movl %ebx, (%esp)\n" /* oldMessageNum */
        "calll __Unwind_Resume\n"
    );
}

/* line 883 */
__attribute__((naked))
void CL_ParseServerMessage(msg_t *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 883 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* msg */
        /* { scope 1 */
        "movl $0x4000, 4(%esp)\n" /* line 887 */
        "leal -0x1c(%ebp), %eax\n" /* msgCompressed_buf_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_LargeLocal\n"
        "leal -0x1c(%ebp), %eax\n" /* msgCompressed_buf_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_GetBuf\n"
        "movl %eax, %edi\n" /* msgCompressed_buf */
        "movl 0x195f5e4, %eax\n" /* line 892 */
        "movl (%eax), %eax\n"
        "cmpl $1, 8(%eax)\n"
        "je .Lf1d4324_001d450d\n"
        "jle .Lf1d4324_001d436f\n" /* line 896 */
        "movl $0x2b7920, (%esp)\n" /* line 898 */
        "calll Com_Printf\n"
        ".Lf1d4324_001d436f:\n"
        "movl $0x4000, 8(%esp)\n" /* line 901 */
        "movl %edi, 4(%esp)\n" /* msgCompressed_buf */
        "leal -0x34(%ebp), %esi\n" /* msgCompressed */
        "movl %esi, (%esp)\n"
        "calll MSG_Init\n"
        "movl 0x10(%ebx), %edx\n" /* line 902 | cmd */
        "movl 0xc(%ebx), %eax\n" /* cmd */
        "subl %edx, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* msgCompressed_buf */
        "addl 4(%ebx), %edx\n" /* cmd */
        "movl %edx, (%esp)\n"
        "calll MSG_ReadBitsCompress\n"
        "movl %eax, -0x28(%ebp)\n"
        ".Lf1d4324_001d43a4:\n"
        "movl -0x34(%ebp), %eax\n" /* line 907 | msgCompressed */
        "testl %eax, %eax\n"
        "jne .Lf1d4324_001d441f\n"
        ".Lf1d4324_001d43ab:\n"
        "movl %esi, (%esp)\n" /* line 909 */
        "calll MSG_ReadByte\n"
        "movl %eax, %ebx\n" /* cmd */
        "cmpl $7, %eax\n" /* line 911 */
        "je .Lf1d4324_001d44cb\n"
        "movl 0x195f5e4, %eax\n" /* line 917 */
        "movl (%eax), %eax\n"
        "cmpl $1, 8(%eax)\n"
        "jle .Lf1d4324_001d43f4\n"
        "movl svc_strings(, %ebx, 4), %eax\n" /* line 919 */
        "testl %eax, %eax\n"
        "je .Lf1d4324_001d44ac\n"
        "movl %eax, 8(%esp)\n" /* line 54 */
        "movl -0x24(%ebp), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b7644, (%esp)\n" /* "%3i:%s
" */
        "calll Com_Printf\n"
        ".Lf1d4324_001d43f4:\n"
        "cmpl $6, %ebx\n" /* line 930 | cmd */
        "ja .Lf1d4324_001d4400\n"
        "jmpl *0x303460(, %ebx, 4)\n"
        ".Lf1d4324_001d4400:\n"
        "movl %ebx, 8(%esp)\n" /* line 942 | cmd */
        "movl $0x2b7954, 4(%esp)\n" /* "CL_ParseServerMessage: Illegible server message %d
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl -0x34(%ebp), %eax\n" /* line 907 | msgCompressed */
        "testl %eax, %eax\n"
        "je .Lf1d4324_001d43ab\n"
        ".Lf1d4324_001d441f:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 961 | msgCompressed_buf_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 962 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        "movl %esi, (%esp)\n" /* line 950 */
        "calll CL_ParseGamestate\n"
        "jmp .Lf1d4324_001d43a4\n"
        /* { scope 2 */
        "movl %esi, (%esp)\n" /* line 863 */
        "calll MSG_ReadLong\n"
        "movl %eax, %ebx\n" /* seq */
        "movl %esi, (%esp)\n" /* line 864 */
        "calll MSG_ReadString\n"
        "movl %eax, %edx\n"
        "movl 0x195ee8c, %eax\n" /* line 867 */
        "movl (%eax), %eax\n"
        "cmpl 0x2013c(%eax), %ebx\n" /* seq */
        "jle .Lf1d4324_001d43a4\n"
        "movl %ebx, 0x2013c(%eax)\n" /* line 871 | seq */
        "movl $0x400, 8(%esp)\n" /* line 874 */
        "movl %edx, 4(%esp)\n"
        "andl $0x7f, %ebx\n" /* seq */
        "shll $0xa, %ebx\n" /* seq */
        "leal 0x20144(%ebx, %eax), %eax\n" /* seq */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "jmp .Lf1d4324_001d43a4\n"
        /* } scope */
        "movl %esi, (%esp)\n" /* line 957 */
        "calll CL_ParseDownload\n"
        "jmp .Lf1d4324_001d43a4\n"
        "movl %esi, (%esp)\n" /* line 953 */
        "calll CL_ParseSnapshot\n"
        "jmp .Lf1d4324_001d43a4\n"
        ".Lf1d4324_001d44ac:\n"
        "movl %ebx, 8(%esp)\n" /* line 921 | cmd */
        "movl -0x24(%ebp), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b7944, (%esp)\n" /* "%3i:BAD CMD %i
" */
        "calll Com_Printf\n"
        "jmp .Lf1d4324_001d43f4\n"
        ".Lf1d4324_001d44cb:\n"
        "movl 0x195f5e4, %eax\n" /* line 52 */
        "movl (%eax), %eax\n"
        "cmpl $1, 8(%eax)\n"
        "jle .Lf1d4324_001d441f\n"
        "movl $0x2b7934, 8(%esp)\n" /* line 54 */
        "movl -0x24(%ebp), %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b7644, (%esp)\n" /* "%3i:%s
" */
        "calll Com_Printf\n"
        "leal -0x1c(%ebp), %eax\n" /* line 961 | msgCompressed_buf_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 962 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d4324_001d450d:\n"
        "movl 0xc(%ebx), %eax\n" /* line 894 | cmd */
        "movl %eax, 4(%esp)\n"
        "movl $0x217fac, (%esp)\n" /* "%i " */
        "calll Com_Printf\n"
        "jmp .Lf1d4324_001d436f\n"
        "movl %eax, %ebx\n" /* cmd */
        "leal -0x1c(%ebp), %eax\n" /* line 961 | msgCompressed_buf_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "movl %ebx, (%esp)\n" /* cmd */
        "calll __Unwind_Resume\n"
    );
}

