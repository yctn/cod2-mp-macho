/* ASM dump from: g_client_fields_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_client_fields_mp.cpp */

#include "common_types.h"
#include "imports.h"

static const client_fields_t fields[14]; /* 0x333760 */

static void ClientScr_ReadOnly(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_SetSessionTeam(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_GetSessionTeam(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_SetSessionState(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_GetSessionState(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_SetMaxHealth(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_SetScore(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_SetSpectatorClient(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_SetStatusIcon(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_GetStatusIcon(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_SetHeadIcon(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_GetHeadIcon(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_SetHeadIconTeam(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_GetHeadIconTeam(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_SetArchiveTime(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_GetArchiveTime(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_SetPSOffsetTime(gclient_t *pSelf, const client_fields_s *pField);
static void ClientScr_GetPSOffsetTime(gclient_t *pSelf, const client_fields_s *pField);
void GScr_AddFieldsForClient(void);
void Scr_SetClientField(gclient_t *client, int offset);
void Scr_GetClientField(gclient_t *client, int offset);

/* line 20 */
static __attribute__((naked))
void ClientScr_ReadOnly(gclient_t *pSelf, const client_fields_s *pField)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 20 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* line 24 | pField */
        "movl (%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b5608, (%esp)\n" /* "player field %s is read-only" */
        "calll va\n"
        "movl %eax, 8(%ebp)\n" /* pSelf */
        "leave\n" /* line 25 */
        "jmp Scr_Error\n" /* line 24 */
    );
}

/* line 33 */
static __attribute__((naked))
void ClientScr_SetSessionTeam(gclient_t *pSelf, const client_fields_s *pField)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 33 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* pSelf */
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 39 */
        "calll Scr_GetConstString\n"
        "movl 0x195f5bc, %edx\n" /* line 41 */
        "cmpw 4(%edx), %ax\n"
        "je .Lf1b7acc_001b7b29\n"
        "cmpw 2(%edx), %ax\n" /* line 43 */
        "je .Lf1b7acc_001b7b6b\n"
        "cmpw 0x48(%edx), %ax\n" /* line 45 */
        "je .Lf1b7acc_001b7b83\n"
        "cmpw 0x74(%edx), %ax\n" /* line 47 */
        "je .Lf1b7acc_001b7b77\n"
        "movzwl %ax, %eax\n" /* line 50 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b5628, (%esp)\n" /* "'%s' is an illegal sessionteam string. Must be allies, axis," */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "jmp .Lf1b7acc_001b7b33\n"
        ".Lf1b7acc_001b7b29:\n"
        "movl $1, 0x274c(%ebx)\n" /* line 42 | pSelf */
        ".Lf1b7acc_001b7b33:\n"
        "movl 0x195f6a0, %eax\n" /* line 52 */
        "movl %ebx, %edx\n" /* pSelf */
        "subl (%eax), %edx\n"
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
        "calll ClientUserinfoChanged\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 54 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CalculateRanks\n" /* line 53 */
        ".Lf1b7acc_001b7b6b:\n"
        "movl $2, 0x274c(%ebx)\n" /* line 44 | pSelf */
        "jmp .Lf1b7acc_001b7b33\n"
        ".Lf1b7acc_001b7b77:\n"
        "movl $0, 0x274c(%ebx)\n" /* line 48 | pSelf */
        "jmp .Lf1b7acc_001b7b33\n"
        ".Lf1b7acc_001b7b83:\n"
        "movl $3, 0x274c(%ebx)\n" /* line 46 | pSelf */
        "jmp .Lf1b7acc_001b7b33\n"
    );
}

/* line 62 */
static __attribute__((naked))
void ClientScr_GetSessionTeam(gclient_t *pSelf, const client_fields_s *pField)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 62 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 66 | pSelf */
        "movl 0x274c(%eax), %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf1b7b90_001b7baf\n"
        "jle .Lf1b7b90_001b7be5\n"
        "cmpl $2, %eax\n"
        "je .Lf1b7b90_001b7bc1\n"
        "cmpl $3, %eax\n"
        "je .Lf1b7b90_001b7bd3\n"
        ".Lf1b7b90_001b7bad:\n"
        "popl %ebp\n" /* line 81 */
        "retl\n"
        ".Lf1b7b90_001b7baf:\n"
        "movl 0x195f5bc, %eax\n" /* line 72 */
        "movzwl 4(%eax), %eax\n"
        "movl %eax, 8(%ebp)\n" /* pSelf */
        "popl %ebp\n" /* line 81 */
        "jmp Scr_AddConstString\n" /* line 72 */
        ".Lf1b7b90_001b7bc1:\n"
        "movl 0x195f5bc, %eax\n" /* line 69 */
        "movzwl 2(%eax), %eax\n"
        "movl %eax, 8(%ebp)\n" /* pSelf */
        "popl %ebp\n" /* line 81 */
        "jmp Scr_AddConstString\n" /* line 69 */
        ".Lf1b7b90_001b7bd3:\n"
        "movl 0x195f5bc, %eax\n" /* line 75 */
        "movzwl 0x48(%eax), %eax\n"
        "movl %eax, 8(%ebp)\n" /* pSelf */
        "popl %ebp\n" /* line 81 */
        "jmp Scr_AddConstString\n" /* line 75 */
        ".Lf1b7b90_001b7be5:\n"
        "testl %eax, %eax\n" /* line 66 */
        "jne .Lf1b7b90_001b7bad\n"
        "movl 0x195f5bc, %eax\n" /* line 78 */
        "movzwl 0x74(%eax), %eax\n"
        "movl %eax, 8(%ebp)\n" /* pSelf */
        "popl %ebp\n" /* line 81 */
        "jmp Scr_AddConstString\n" /* line 78 */
    );
}

/* line 89 */
static __attribute__((naked))
void ClientScr_SetSessionState(gclient_t *pSelf, const client_fields_s *pField)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 89 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* pSelf */
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 96 */
        "calll Scr_GetConstString\n"
        "movl 0x195f5bc, %edx\n" /* line 98 */
        "cmpw 0x72(%edx), %ax\n"
        "je .Lf1b7bfc_001b7c58\n"
        "cmpw 0x76(%edx), %ax\n" /* line 102 */
        "je .Lf1b7bfc_001b7c68\n"
        "cmpw 0x48(%edx), %ax\n" /* line 106 */
        "je .Lf1b7bfc_001b7c8f\n"
        "cmpw 0x6e(%edx), %ax\n" /* line 110 */
        "je .Lf1b7bfc_001b7c78\n"
        "movzwl %ax, %eax\n" /* line 116 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b567c, (%esp)\n" /* "'%s' is an illegal sessionstate string. Must be playing, dea" */
        "calll va\n"
        "movl %eax, 8(%ebp)\n" /* pSelf */
        /* } scope */
        "addl $0x14, %esp\n" /* line 117 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_Error\n" /* line 116 */
        ".Lf1b7bfc_001b7c58:\n"
        "movl $0, 0x26a8(%ebx)\n" /* line 100 | pSelf */
        /* } scope */
        "addl $0x14, %esp\n" /* line 117 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b7bfc_001b7c68:\n"
        "movl $1, 0x26a8(%ebx)\n" /* line 104 | pSelf */
        /* } scope */
        "addl $0x14, %esp\n" /* line 117 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b7bfc_001b7c78:\n"
        "xorl $2, 0xa0(%ebx)\n" /* line 112 | pSelf */
        "movl $3, 0x26a8(%ebx)\n" /* line 113 | pSelf */
        /* } scope */
        "addl $0x14, %esp\n" /* line 117 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b7bfc_001b7c8f:\n"
        "movl $2, 0x26a8(%ebx)\n" /* line 108 | pSelf */
        /* } scope */
        "addl $0x14, %esp\n" /* line 117 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 125 */
static __attribute__((naked))
void ClientScr_GetSessionState(gclient_t *pSelf, const client_fields_s *pField)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 125 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 130 | pSelf */
        "movl 0x26a8(%eax), %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf1b7ca0_001b7cbf\n"
        "jle .Lf1b7ca0_001b7cf5\n"
        "cmpl $2, %eax\n"
        "je .Lf1b7ca0_001b7cd1\n"
        "cmpl $3, %eax\n"
        "je .Lf1b7ca0_001b7ce3\n"
        ".Lf1b7ca0_001b7cbd:\n"
        "popl %ebp\n" /* line 145 */
        "retl\n"
        ".Lf1b7ca0_001b7cbf:\n"
        "movl 0x195f5bc, %eax\n" /* line 136 */
        "movzwl 0x76(%eax), %eax\n"
        "movl %eax, 8(%ebp)\n" /* pSelf */
        "popl %ebp\n" /* line 145 */
        "jmp Scr_AddConstString\n" /* line 136 */
        ".Lf1b7ca0_001b7cd1:\n"
        "movl 0x195f5bc, %eax\n" /* line 139 */
        "movzwl 0x48(%eax), %eax\n"
        "movl %eax, 8(%ebp)\n" /* pSelf */
        "popl %ebp\n" /* line 145 */
        "jmp Scr_AddConstString\n" /* line 139 */
        ".Lf1b7ca0_001b7ce3:\n"
        "movl 0x195f5bc, %eax\n" /* line 142 */
        "movzwl 0x6e(%eax), %eax\n"
        "movl %eax, 8(%ebp)\n" /* pSelf */
        "popl %ebp\n" /* line 145 */
        "jmp Scr_AddConstString\n" /* line 142 */
        ".Lf1b7ca0_001b7cf5:\n"
        "testl %eax, %eax\n" /* line 130 */
        "jne .Lf1b7ca0_001b7cbd\n"
        "movl 0x195f5bc, %eax\n" /* line 133 */
        "movzwl 0x72(%eax), %eax\n"
        "movl %eax, 8(%ebp)\n" /* pSelf */
        "popl %ebp\n" /* line 145 */
        "jmp Scr_AddConstString\n" /* line 133 */
    );
}

/* line 153 */
static __attribute__((naked))
void ClientScr_SetMaxHealth(gclient_t *pSelf, const client_fields_s *pField)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 153 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* pSelf */
        "movl $0, (%esp)\n" /* line 159 */
        "calll Scr_GetInt\n"
        "movl $1, %edx\n" /* line 161 */
        "testl %eax, %eax\n"
        "cmovgl %eax, %edx\n"
        "movl %edx, 0x2728(%ebx)\n" /* pSelf */
        "cmpl %edx, 0x12c(%ebx)\n" /* line 164 | pSelf */
        "jle .Lf1b7d0c_001b7d95\n"
        "movl %edx, 0x12c(%ebx)\n" /* line 165 | pSelf */
        "movl %edx, %ecx\n"
        ".Lf1b7d0c_001b7d42:\n"
        "movl 0x195f6a0, %eax\n" /* line 168 */
        "movl %ebx, %edx\n" /* pSelf */
        "subl (%eax), %edx\n"
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
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "movl 0x195f688, %eax\n"
        "movl %ecx, 0x194(%eax, %edx)\n"
        "movl 0x2728(%ebx), %eax\n" /* line 170 | pSelf */
        "movl %eax, 0x134(%ebx)\n" /* pSelf */
        "addl $0x14, %esp\n" /* line 171 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1b7d0c_001b7d95:\n"
        "movl 0x12c(%ebx), %ecx\n" /* pSelf */
        "jmp .Lf1b7d0c_001b7d42\n"
    );
}

/* line 179 */
static __attribute__((naked))
void ClientScr_SetScore(gclient_t *pSelf, const client_fields_s *pField)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 179 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* pSelf */
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 183 */
        "calll Scr_GetInt\n"
        "movl %eax, 0x26b8(%ebx)\n" /* line 184 | pSelf */
        /* } scope */
        "addl $0x14, %esp\n" /* line 186 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CalculateRanks\n" /* line 185 */
    );
}

/* line 194 */
static __attribute__((naked))
void ClientScr_SetSpectatorClient(gclient_t *pSelf, const client_fields_s *pField)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 194 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 200 */
        "calll Scr_GetInt\n"
        "movl %eax, %ebx\n" /* iNewSpectatorClient */
        "leal 1(%eax), %eax\n" /* line 202 */
        "cmpl $0x40, %eax\n"
        "jbe .Lf1b7dc4_001b7ded\n"
        "movl $0x2b56d8, (%esp)\n" /* line 203 */
        "calll Scr_Error\n"
        ".Lf1b7dc4_001b7ded:\n"
        "movl 8(%ebp), %eax\n" /* line 205 | pSelf */
        "movl %ebx, 0x26ac(%eax)\n" /* iNewSpectatorClient */
        /* } scope */
        "addl $0x14, %esp\n" /* line 206 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 214 */
static __attribute__((naked))
void ClientScr_SetStatusIcon(gclient_t *pSelf, const client_fields_s *pField)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 214 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 220 */
        "calll Scr_GetString\n"
        "movl %eax, (%esp)\n" /* line 221 */
        "calll GScr_GetStatusIconIndex\n"
        "movl 8(%ebp), %edx\n" /* pSelf */
        "movl %eax, 0x26b0(%edx)\n"
        /* } scope */
        "leave\n" /* line 222 */
        "retl\n"
    );
}

/* line 230 */
static __attribute__((naked))
void ClientScr_GetStatusIcon(gclient_t *pSelf, const client_fields_s *pField)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 230 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x414, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 235 | pSelf */
        "movl 0x26b0(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1b7e22_001b7e4e\n"
        "movl $0x2157b8, (%esp)\n" /* line 237 */
        "calll Scr_AddString\n"
        "addl $0x414, %esp\n" /* line 246 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b7e22_001b7e4e:\n"
        "movl $0x400, 8(%esp)\n" /* line 243 */
        "leal -0x408(%ebp), %ebx\n" /* szConfigString */
        "movl %ebx, 4(%esp)\n"
        "addl $0x16, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_GetConfigstring\n"
        "movl %ebx, (%esp)\n" /* line 244 */
        "calll Scr_AddString\n"
        /* } scope */
        "addl $0x414, %esp\n" /* line 246 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 254 */
static __attribute__((naked))
void ClientScr_SetHeadIcon(gclient_t *pSelf, const client_fields_s *pField)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 254 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* pSelf */
        /* { scope 1 */
        "movl 0x195f6a0, %eax\n" /* line 261 */
        "subl (%eax), %edx\n"
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
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pEnt */
        "subl %eax, %ebx\n" /* pEnt */
        "shll $4, %ebx\n" /* pEnt */
        "addl 0x195f688, %ebx\n" /* pEnt */
        "movl $0, (%esp)\n" /* line 263 */
        "calll Scr_GetString\n"
        "movl %eax, (%esp)\n" /* line 264 */
        "calll GScr_GetHeadIconIndex\n"
        "movl %eax, 0x94(%ebx)\n" /* pEnt */
        /* } scope */
        "addl $0x14, %esp\n" /* line 265 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 273 */
static __attribute__((naked))
void ClientScr_GetHeadIcon(gclient_t *pSelf, const client_fields_s *pField)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 273 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x414, %esp\n"
        "movl 8(%ebp), %edx\n" /* pSelf */
        "movl 0x195f6a0, %eax\n" /* line 281 */
        "subl (%eax), %edx\n"
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
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "movl 0x195f688, %eax\n"
        "movl 0x94(%eax, %edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1b7ee0_001b7f6c\n"
        "cmpl $0xf, %eax\n" /* line 283 */
        "jle .Lf1b7ee0_001b7f3e\n"
        "addl $0x414, %esp\n" /* line 290 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b7ee0_001b7f3e:\n"
        "movl $0x400, 8(%esp)\n" /* line 287 */
        "leal -0x408(%ebp), %ebx\n" /* szConfigString */
        "movl %ebx, 4(%esp)\n"
        "addl $0x1e, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_GetConfigstring\n"
        "movl %ebx, (%esp)\n" /* line 288 */
        "calll Scr_AddString\n"
        /* } scope */
        "addl $0x414, %esp\n" /* line 290 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1b7ee0_001b7f6c:\n"
        "movl $0x2157b8, (%esp)\n" /* line 282 */
        "calll Scr_AddString\n"
        "addl $0x414, %esp\n" /* line 290 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 298 */
static __attribute__((naked))
void ClientScr_SetHeadIconTeam(gclient_t *pSelf, const client_fields_s *pField)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 298 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* pSelf */
        /* { scope 1 */
        "movl 0x195f6a0, %eax\n" /* line 305 */
        "subl (%eax), %edx\n"
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
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %ebx\n" /* pEnt */
        "subl %eax, %ebx\n" /* pEnt */
        "shll $4, %ebx\n" /* pEnt */
        "addl 0x195f688, %ebx\n" /* pEnt */
        "movl $0, (%esp)\n" /* line 307 */
        "calll Scr_GetConstString\n"
        "movl 0x195f5bc, %edx\n" /* line 308 */
        "cmpw 0x74(%edx), %ax\n"
        "je .Lf1b7f82_001b7fff\n"
        "cmpw 2(%edx), %ax\n" /* line 310 */
        "je .Lf1b7f82_001b800f\n"
        "cmpw 4(%edx), %ax\n" /* line 312 */
        "je .Lf1b7f82_001b801f\n"
        "cmpw 0x48(%edx), %ax\n" /* line 314 */
        "je .Lf1b7f82_001b802f\n"
        "movl $3, 0x98(%ebx)\n" /* line 315 | pEnt */
        /* } scope */
        "addl $0x14, %esp\n" /* line 318 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b7f82_001b7fff:\n"
        "movl $0, 0x98(%ebx)\n" /* line 309 | pEnt */
        /* } scope */
        "addl $0x14, %esp\n" /* line 318 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b7f82_001b800f:\n"
        "movl $2, 0x98(%ebx)\n" /* line 311 | pEnt */
        /* } scope */
        "addl $0x14, %esp\n" /* line 318 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b7f82_001b801f:\n"
        "movl $1, 0x98(%ebx)\n" /* line 313 | pEnt */
        /* } scope */
        "addl $0x14, %esp\n" /* line 318 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b7f82_001b802f:\n"
        "movzwl %ax, %eax\n" /* line 317 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b5718, (%esp)\n" /* "'%s' is an illegal head icon team string. Must be none, alli" */
        "calll va\n"
        "movl %eax, 8(%ebp)\n" /* pSelf */
        /* } scope */
        "addl $0x14, %esp\n" /* line 318 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_Error\n" /* line 317 */
    );
}

/* line 326 */
static __attribute__((naked))
void ClientScr_GetHeadIconTeam(gclient_t *pSelf, const client_fields_s *pField)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 326 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* pSelf */
        "movl 0x195f6a0, %eax\n" /* line 334 */
        "subl (%eax), %edx\n"
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
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "shll $4, %edx\n"
        "movl 0x195f688, %eax\n"
        "movl 0x98(%eax, %edx), %eax\n"
        "cmpl $2, %eax\n"
        "je .Lf1b8058_001b80be\n"
        "cmpl $3, %eax\n"
        "je .Lf1b8058_001b80d0\n"
        "subl $1, %eax\n"
        "je .Lf1b8058_001b80e2\n"
        "movl 0x195f5bc, %eax\n" /* line 346 */
        "movzwl 0x74(%eax), %eax\n"
        "movl %eax, 8(%ebp)\n" /* pSelf */
        "popl %ebp\n" /* line 349 */
        "jmp Scr_AddConstString\n" /* line 346 */
        ".Lf1b8058_001b80be:\n"
        "movl 0x195f5bc, %eax\n" /* line 340 */
        "movzwl 2(%eax), %eax\n"
        "movl %eax, 8(%ebp)\n" /* pSelf */
        "popl %ebp\n" /* line 349 */
        "jmp Scr_AddConstString\n" /* line 340 */
        ".Lf1b8058_001b80d0:\n"
        "movl 0x195f5bc, %eax\n" /* line 343 */
        "movzwl 0x48(%eax), %eax\n"
        "movl %eax, 8(%ebp)\n" /* pSelf */
        "popl %ebp\n" /* line 349 */
        "jmp Scr_AddConstString\n" /* line 343 */
        ".Lf1b8058_001b80e2:\n"
        "movl 0x195f5bc, %eax\n" /* line 337 */
        "movzwl 4(%eax), %eax\n"
        "movl %eax, 8(%ebp)\n" /* pSelf */
        "popl %ebp\n" /* line 349 */
        "jmp Scr_AddConstString\n" /* line 337 */
    );
}

/* line 357 */
static __attribute__((naked))
void ClientScr_SetArchiveTime(gclient_t *pSelf, const client_fields_s *pField)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 357 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl $0, (%esp)\n" /* line 361 */
        "calll Scr_GetFloat\n"
        "fstps -0xc(%ebp)\n"
        "movss -0xc(%ebp), %xmm0\n"
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "cvttss2si %xmm0, %edx\n"
        "movl 8(%ebp), %eax\n" /* pSelf */
        "movl %edx, 0x26b4(%eax)\n"
        "leave\n" /* line 362 */
        "retl\n"
    );
}

/* line 370 */
static __attribute__((naked))
void ClientScr_GetArchiveTime(gclient_t *pSelf, const client_fields_s *pField)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 370 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 372 | pSelf */
        "cvtsi2ssl 0x26b4(%eax), %xmm0\n"
        "mulss 0x2ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, 8(%ebp)\n" /* pSelf */
        "popl %ebp\n" /* line 373 */
        "jmp Scr_AddFloat\n" /* line 372 */
    );
}

/* line 380 */
static __attribute__((naked))
void ClientScr_SetPSOffsetTime(gclient_t *pSelf, const client_fields_s *pField)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 380 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0, (%esp)\n" /* line 384 */
        "calll Scr_GetInt\n"
        "movl 8(%ebp), %edx\n" /* pSelf */
        "movl %eax, 0x27a4(%edx)\n"
        "leave\n" /* line 385 */
        "retl\n"
    );
}

/* line 393 */
static __attribute__((naked))
void ClientScr_GetPSOffsetTime(gclient_t *pSelf, const client_fields_s *pField)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 393 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 395 | pSelf */
        "movl 0x26b4(%eax), %eax\n"
        "movl %eax, 8(%ebp)\n" /* pSelf */
        "popl %ebp\n" /* line 396 */
        "jmp Scr_AddInt\n" /* line 395 */
    );
}

/* line 428 */
__attribute__((naked))
void GScr_AddFieldsForClient(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 428 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl fields, %ebx\n" /* line 432 */
        "testl %ebx, %ebx\n"
        "je .Lf1b817c_001b81dd\n"
        "xorl %edi, %edi\n" /* line 428 */
        "movl $0x333774, %esi\n"
        ".Lf1b817c_001b8196:\n"
        "movl %edi, %ecx\n" /* line 436 */
        "sarl $2, %ecx\n"
        "leal (%ecx, %ecx, 2), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $8, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $0x10, %edx\n"
        "addl %edx, %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "orw $0xc000, %ax\n"
        "movzwl %ax, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_AddClassField\n"
        "movl (%esi), %ebx\n" /* line 432 */
        "addl $0x14, %edi\n"
        "addl $0x14, %esi\n"
        "testl %ebx, %ebx\n"
        "jne .Lf1b817c_001b8196\n"
        ".Lf1b817c_001b81dd:\n"
        "addl $0x1c, %esp\n" /* line 438 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 446 */
__attribute__((naked))
void Scr_SetClientField(gclient_t *client, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 446 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* client */
        "movl 0xc(%ebp), %eax\n" /* offset */
        /* { scope 1 */
        "leal (%eax, %eax, 4), %eax\n" /* line 453 */
        "leal fields(, %eax, 4), %edx\n"
        "movl 0xc(%edx), %ecx\n" /* line 455 */
        "testl %ecx, %ecx\n"
        "je .Lf1b81e6_001b820e\n"
        "movl %edx, 0xc(%ebp)\n" /* line 457 | offset */
        /* } scope */
        "addl $0x14, %esp\n" /* line 463 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmpl *%ecx\n" /* line 457 */
        ".Lf1b81e6_001b820e:\n"
        "movl 4(%edx), %eax\n" /* line 462 */
        "movl %eax, 8(%esp)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* client */
        "calll Scr_SetGenericField\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 463 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 471 */
__attribute__((naked))
void Scr_GetClientField(gclient_t *client, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 471 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* client */
        "movl 0xc(%ebp), %eax\n" /* offset */
        /* { scope 1 */
        "leal (%eax, %eax, 4), %eax\n" /* line 478 */
        "leal fields(, %eax, 4), %edx\n"
        "movl 0x10(%edx), %ecx\n" /* line 480 */
        "testl %ecx, %ecx\n"
        "je .Lf1b822a_001b8252\n"
        "movl %edx, 0xc(%ebp)\n" /* line 482 | offset */
        /* } scope */
        "addl $0x14, %esp\n" /* line 488 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmpl *%ecx\n" /* line 482 */
        ".Lf1b822a_001b8252:\n"
        "movl 4(%edx), %eax\n" /* line 487 */
        "movl %eax, 8(%esp)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* client */
        "calll Scr_GetGenericField\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 488 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

