/* ASM dump from: g_cmds_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_cmds_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/q_shared.h"
 */

static char line[1024]; /* line */
extern char * gc_orders[7]; /* gc_orders */
extern level_locals_t level;
extern gentity_t g_entities[1024];
extern const dvar_t *g_cheats;
extern void Com_sprintf(char *dest, int size, const char *fmt, ...);
extern char *va(const char *fmt, ...);
extern int SV_GetClientPing(int clientNum);
extern void SV_GameSendServerCommand(int clientNum, int type, const char *text);
extern void SV_SetConfigstring(int index, const char *val);
extern int SV_Cmd_Argc(void);
extern void SV_Cmd_ArgvBuffer(int arg, char *buffer, int bufferLength);

enum {
    GCMDS_MAX_CLIENTS = 64
};

void DeathmatchScoreboardMessage(gentity_t *ent);
void Cmd_Score_f(gentity_t *ent);
qboolean CheatsOk(gentity_t *ent);
char * ConcatArgs(int start);
void G_setfog(const char *fogstring);
qboolean Cmd_FollowCycle_f(gentity_t *ent, int dir);
qboolean G_IsPlaying(gentity_t *ent);
void Cmd_CallVote_f(gentity_t *ent);
void Cmd_Vote_f(gentity_t *ent);
void Cmd_SetViewpos_f(gentity_t *ent);
void Cmd_MenuResponse_f(gentity_t *pEnt);
static void G_SayTo(int color, const char *name, const char *message);
void G_Say(gentity_t *ent, gentity_t *target, int mode, const char *chatText);
void Cmd_GameCommand_f(gentity_t *ent);
void StopFollowing(gentity_t *ent);
void Cmd_Give_f(gentity_t *ent);
void Cmd_Take_f(gentity_t *ent);
void ClientCommand(int clientNum);

/* line 13 */
void DeathmatchScoreboardMessage(gentity_t *ent)
{
    gclient_t *client;
    int clientNum;
    char entry[1024];
    int i;
    int j;
    int numSorted;
    int ping;
    char string[1400];
    int stringlength;

    string[0] = '\0';
    stringlength = 0;

    numSorted = level.numConnectedClients;
    if (numSorted > GCMDS_MAX_CLIENTS) {
        numSorted = GCMDS_MAX_CLIENTS;
    }

    for (i = 0; i < numSorted; ++i) {
        clientNum = level.sortedClients[i];
        client = &level.clients[clientNum];

        if (client->sess.connected == CON_CONNECTING) {
            Com_sprintf(entry, sizeof(entry), " %i %i %i %i %i",
                level.sortedClients[i], client->sess.score, -1,
                client->sess.deaths, client->sess.status_icon);
        } else {
            ping = SV_GetClientPing(clientNum);
            Com_sprintf(entry, sizeof(entry), " %i %i %i %i %i",
                level.sortedClients[i], client->sess.score, ping,
                client->sess.deaths, client->sess.status_icon);
        }

        j = strlen(entry);
        if (stringlength + j > 1024) {
            break;
        }

        strcpy(string + stringlength, entry);
        stringlength += j;
    }

    SV_GameSendServerCommand(ent - g_entities, SV_CMD_RELIABLE,
        va("%c %i %i %i%s", 98, i, level.teamScores[TEAM_AXIS],
            level.teamScores[TEAM_ALLIES], string));
}

/* line 66 */
void Cmd_Score_f(gentity_t *ent)
{
    DeathmatchScoreboardMessage(ent);
}

/* line 77 */
qboolean CheatsOk(gentity_t *ent)
{
    if (!g_cheats->current.enabled) {
        SV_GameSendServerCommand(ent - g_entities, SV_CMD_CAN_IGNORE,
            va("%c \"GAME_CHEATSNOTENABLED\"", 101));
        return 0;
    }

    if (ent->health <= 0) {
        SV_GameSendServerCommand(ent - g_entities, SV_CMD_CAN_IGNORE,
            va("%c \"GAME_MUSTBEALIVECOMMAND\"", 101));
        return 0;
    }

    return 1;
}

/* line 98 */
char * ConcatArgs(int start)
{
    char arg[1024];
    int argc;
    int i;
    int len;
    int tlen;

    argc = SV_Cmd_Argc();
    len = 0;

    for (i = start; i < argc; ++i) {
        SV_Cmd_ArgvBuffer(i, arg, sizeof(arg));
        tlen = strlen(arg);

        if (len + tlen >= (int)sizeof(line) - 1) {
            break;
        }

        memcpy(line + len, arg, tlen);
        len += tlen;

        if (i != argc - 1) {
            line[len] = ' ';
            ++len;
        }
    }

    line[len] = '\0';
    return line;
}

/* line 217 */
void G_setfog(const char *fogstring)
{
    float fTime;
    float r;
    float g;
    float b;
    float fDensity;
    float fFar;
    float fNear;

    SV_SetConfigstring(12, fogstring);

    level.fFogOpaqueDist = 3.402823466e+38f;
    level.fFogOpaqueDistSqrd = 3.402823466e+38f;

    if (sscanf(fogstring, "%f %f %f %f %f %f %f", &fNear, &fFar, &fDensity, &r, &g, &b, &fTime) != 7) {
        return;
    }

    if (fDensity < 1.0f) {
        return;
    }

    level.fFogOpaqueDist = fFar;
    level.fFogOpaqueDistSqrd = fFar * fFar;
}

/* line 732 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
qboolean Cmd_FollowCycle_f(gentity_t *ent, int dir)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 732 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x272c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* dir */
        /* { scope 1 */
        "cmpl $1, %edi\n" /* line 739 | dir */
        "je .Lf1a3054_001a3085\n"
        "cmpl $-1, %edi\n" /* dir */
        "je .Lf1a3054_001a3085\n"
        "movl %edi, 8(%esp)\n" /* line 741 | dir */
        "movl $str_002b3724, 4(%esp)\n" /* "Cmd_FollowCycle_f: bad dir %i" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf1a3054_001a3085:\n"
        "movl 8(%ebp), %eax\n" /* line 747 | ent */
        "movl 0x158(%eax), %edx\n"
        "cmpl $2, 0x26a8(%edx)\n"
        "je .Lf1a3054_001a30a4\n"
        ".Lf1a3054_001a3097:\n"
        "xorl %eax, %eax\n" /* line 757 */
        /* } scope */
        ".Lf1a3054_001a3099:\n"
        "addl $0x272c, %esp\n" /* line 786 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1a3054_001a30a4:\n"
        "movl 0x26ac(%edx), %ebx\n" /* line 750 */
        "testl %ebx, %ebx\n"
        "jns .Lf1a3054_001a3097\n"
        "movl 0x27a8(%edx), %esi\n" /* line 753 | clientnum */
        "testl %esi, %esi\n" /* line 754 | clientnum */
        "movl $0, %eax\n"
        "cmovsl %eax, %esi\n" /* clientnum */
        "movl %esi, %ebx\n" /* clientnum */
        "jmp .Lf1a3054_001a30f8\n"
        ".Lf1a3054_001a30c2:\n"
        "xorl %ebx, %ebx\n" /* line 760 */
        ".Lf1a3054_001a30c4:\n"
        "leal -0x74(%ebp), %eax\n" /* line 770 | cs */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x271c(%ebp), %eax\n" /* ps */
        "movl %eax, 8(%esp)\n"
        "leal 0x26b4(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SV_GetArchivedClientInfo\n"
        "testl %eax, %eax\n"
        "jne .Lf1a3054_001a3114\n"
        ".Lf1a3054_001a30eb:\n"
        "cmpl %ebx, %esi\n" /* line 757 | clientnum */
        "je .Lf1a3054_001a3097\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "movl 0x158(%eax), %edx\n"
        ".Lf1a3054_001a30f8:\n"
        "addl %edi, %ebx\n" /* line 759 | dir */
        "movl imp_level, %eax\n" /* line 760 */
        "movl 0x1e4(%eax), %eax\n"
        "cmpl %eax, %ebx\n"
        "jge .Lf1a3054_001a30c2\n"
        "subl $1, %eax\n" /* line 766 */
        "cmpl $-1, %ebx\n"
        "cmovlel %eax, %ebx\n"
        "jmp .Lf1a3054_001a30c4\n"
        ".Lf1a3054_001a3114:\n"
        "movl -0x70(%ebp), %eax\n" /* line 775 */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* ent */
        "movl 0x158(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_ClientCanSpectateTeam\n"
        "testl %eax, %eax\n"
        "je .Lf1a3054_001a30eb\n"
        "movl 8(%ebp), %edx\n" /* line 779 | ent */
        "movl 0x158(%edx), %eax\n"
        "movl %ebx, 0x27a8(%eax)\n"
        "movl 0x158(%edx), %eax\n" /* line 780 */
        "movl $2, 0x26a8(%eax)\n"
        "movl $1, %eax\n"
        "jmp .Lf1a3054_001a3099\n"
    );
}

/* line 794 */
qboolean G_IsPlaying(gentity_t *ent)
{
    /* Returns true if client's session state is SESS_STATE_PLAYING (0) */
    return *(int *)((byte *)ent->client + 0x26A8) == SESS_STATE_PLAYING;
}

/* line 1059 */
__attribute__((naked))
void Cmd_CallVote_f(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1059 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x37c, %esp\n"
        "movl 8(%ebp), %esi\n" /* ent */
        /* { scope 1: kicknum */
        "movl imp_g_allowVote, %eax\n" /* line 1067 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1a3178_001a3288\n"
        "movl imp_g_oldVoting, %eax\n" /* line 1073 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1a3178_001a31d8\n"
        "movl imp_level, %eax\n" /* line 1075 */
        "movl 0xb1c(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf1a3178_001a3299\n"
        "movl 0x158(%esi), %eax\n" /* line 1081 | ent */
        "cmpl $2, 0x2734(%eax)\n"
        "jg .Lf1a3178_001a32aa\n"
        "cmpl $3, 0x274c(%eax)\n" /* line 1087 */
        "je .Lf1a3178_001a3419\n"
        ".Lf1a3178_001a31d8:\n"
        "movl $0x100, 8(%esp)\n" /* line 1095 */
        "leal -0x158(%ebp), %ebx\n" /* arg1 */
        "movl %ebx, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll SV_Cmd_ArgvBuffer\n"
        "movl $0x100, 8(%esp)\n" /* line 1096 */
        "leal -0x258(%ebp), %eax\n" /* arg2 */
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll SV_Cmd_ArgvBuffer\n"
        "movl $0x100, 8(%esp)\n" /* line 1097 */
        "leal -0x358(%ebp), %edi\n" /* arg3 */
        "movl %edi, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll SV_Cmd_ArgvBuffer\n"
        "movl $0x3b, 4(%esp)\n" /* line 1099 */
        "movl %ebx, (%esp)\n"
        "calll strchr\n"
        "testl %eax, %eax\n"
        "je .Lf1a3178_001a32bb\n"
        ".Lf1a3178_001a3246:\n"
        "movl $0x65, 4(%esp)\n" /* line 1101 */
        "movl $str_002b37c8, (%esp)\n" /* "%c "GAME_INVALIDVOTESTRING"" */
        ".Lf1a3178_001a3255:\n"
        "calll va\n" /* line 1077 */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "subl imp_g_entities, %esi\n" /* ent */
        "sarl $4, %esi\n" /* ent */
        "imull $0x8af8af8b, %esi, %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        /* } scope */
        ".Lf1a3178_001a327d:\n"
        "addl $0x37c, %esp\n" /* line 1295 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: kicknum */
        ".Lf1a3178_001a3288:\n"
        "movl $0x65, 4(%esp)\n" /* line 1069 */
        "movl $str_002b3750, (%esp)\n" /* "%c "GAME_VOTINGNOTENABLED"" */
        "jmp .Lf1a3178_001a3255\n"
        ".Lf1a3178_001a3299:\n"
        "movl $0x65, 4(%esp)\n" /* line 1077 */
        "movl $str_002b376c, (%esp)\n" /* "%c "GAME_VOTEALREADYINPROGRESS"" */
        "jmp .Lf1a3178_001a3255\n"
        ".Lf1a3178_001a32aa:\n"
        "movl $0x65, 4(%esp)\n" /* line 1083 */
        "movl $str_002b378c, (%esp)\n" /* "%c "GAME_MAXVOTESCALLED"" */
        "jmp .Lf1a3178_001a3255\n"
        ".Lf1a3178_001a32bb:\n"
        "movl $0x3b, 4(%esp)\n" /* line 1099 */
        "leal -0x258(%ebp), %edx\n" /* arg2 */
        "movl %edx, (%esp)\n"
        "calll strchr\n"
        "testl %eax, %eax\n"
        "jne .Lf1a3178_001a3246\n"
        "movl $0x3b, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll strchr\n"
        "testl %eax, %eax\n"
        "jne .Lf1a3178_001a3246\n"
        "movl imp_g_oldVoting, %eax\n" /* line 1105 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1a3178_001a342d\n"
        "movl $str_002a74bc, 4(%esp)\n" /* line 1107 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a3178_001a348e\n"
        ".Lf1a3178_001a331a:\n"
        "movl imp_level, %eax\n" /* line 1142 */
        "movl 0xb20(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf1a3178_001a35b2\n"
        ".Lf1a3178_001a332d:\n"
        "movl $str_002b37e4, 4(%esp)\n" /* line 1148 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a3178_001a344c\n"
        /* { scope 2 */
        "leal -0x258(%ebp), %edx\n" /* line 1152 | arg2 */
        "movl %edx, (%esp)\n"
        "calll Scr_IsValidGameType\n"
        "testl %eax, %eax\n"
        "je .Lf1a3178_001a347a\n"
        "movl imp_g_gametype, %eax\n" /* line 1157 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x258(%ebp), %eax\n" /* arg2 */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "xorl %ebx, %ebx\n" /* line 1158 */
        "testl %eax, %eax\n"
        "movzbl -0x258(%ebp), %eax\n" /* arg2 */
        "cmovel %ebx, %eax\n"
        "movb %al, -0x258(%ebp)\n" /* arg2 */
        "movl $0x100, 8(%esp)\n" /* line 1160 */
        "movl %edi, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll SV_Cmd_ArgvBuffer\n"
        "movl %edi, (%esp)\n" /* line 1161 */
        "calll SV_MapExists\n"
        "testl %eax, %eax\n"
        "je .Lf1a3178_001a37bd\n"
        "movl $0x1044, 8(%esp)\n" /* line 1166 */
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_002a7124, (%esp)\n" /* "mapname" */
        "calll Dvar_RegisterString_mac\n"
        "movl 8(%eax), %eax\n" /* line 1167 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n" /* line 1168 */
        "movzbl -0x358(%ebp), %eax\n" /* arg3 */
        "cmovnel %eax, %ebx\n"
        "movb %bl, -0x358(%ebp)\n" /* arg3 */
        "cmpb $0, -0x258(%ebp)\n" /* line 1170 | arg2 */
        "jne .Lf1a3178_001a3905\n"
        "testb %bl, %bl\n"
        "jne .Lf1a3178_001a3895\n"
        "movl $0x65, 4(%esp)\n" /* line 1172 */
        "movl $str_002b3900, (%esp)\n" /* "%c "GAME_TYPEMAP_NOCHANGE"" */
        "jmp .Lf1a3178_001a3255\n"
        /* } scope */
        ".Lf1a3178_001a3419:\n"
        "movl $0x65, 4(%esp)\n" /* line 1089 */
        "movl $str_002b37a8, (%esp)\n" /* "%c "GAME_NOSPECTATORCALLVOTE"" */
        "jmp .Lf1a3178_001a3255\n"
        ".Lf1a3178_001a342d:\n"
        "movl %edi, 0xc(%esp)\n" /* line 1293 | i */
        "leal -0x258(%ebp), %edx\n" /* arg2 */
        "movl %edx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* ent */
        "calll Scr_VoteCalled\n"
        "jmp .Lf1a3178_001a327d\n"
        ".Lf1a3178_001a344c:\n"
        "movl $str_002a7100, 4(%esp)\n" /* line 1194 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a3178_001a35e6\n"
        "leal -0x258(%ebp), %edx\n" /* line 1196 | arg2 */
        "movl %edx, (%esp)\n"
        "calll Scr_IsValidGameType\n"
        "testl %eax, %eax\n"
        "jne .Lf1a3178_001a37d1\n"
        ".Lf1a3178_001a347a:\n"
        "movl $0x65, 4(%esp)\n" /* line 1198 */
        "movl $str_002b38bc, (%esp)\n" /* "%c "GAME_INVALIDGAMETYPE"" */
        "jmp .Lf1a3178_001a3255\n"
        ".Lf1a3178_001a348e:\n"
        "movl $str_002ac814, 4(%esp)\n" /* line 1110 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1a3178_001a331a\n"
        "movl $str_002b37e4, 4(%esp)\n" /* line 1113 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1a3178_001a331a\n"
        "movl $str_002ac808, 4(%esp)\n" /* line 1116 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1a3178_001a331a\n"
        "movl $str_002a7100, 4(%esp)\n" /* line 1119 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1a3178_001a331a\n"
        "movl $str_002ac790, 4(%esp)\n" /* line 1122 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1a3178_001a331a\n"
        "movl $str_002ac7c0, 4(%esp)\n" /* line 1125 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1a3178_001a331a\n"
        "movl $str_002ac798, 4(%esp)\n" /* line 1128 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1a3178_001a331a\n"
        "movl $str_002ac7a4, 4(%esp)\n" /* line 1131 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1a3178_001a331a\n"
        "movl $0x65, 4(%esp)\n" /* line 1136 */
        "movl $str_002b37c8, (%esp)\n" /* "%c "GAME_INVALIDVOTESTRING"" */
        "calll va\n"
        "subl imp_g_entities, %esi\n" /* ent */
        "sarl $4, %esi\n" /* ent */
        "imull $0x8af8af8b, %esi, %ebx\n" /* ent */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        "movl $0x65, 4(%esp)\n" /* line 1137 */
        "movl $str_002b37ec, (%esp)\n" /* "%c "GAME_VOTECOMMANDSARE map_restart, map_rotate, map <mapn" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        "jmp .Lf1a3178_001a327d\n"
        ".Lf1a3178_001a35b2:\n"
        "movl $0, 0xb20(%eax)\n" /* line 1144 */
        "addl $0x31c, %eax\n" /* line 1145 */
        "movl %eax, 4(%esp)\n"
        "movl $str_00215bbc, (%esp)\n" /* "%s
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "jmp .Lf1a3178_001a332d\n"
        ".Lf1a3178_001a35e6:\n"
        "movl $str_002a74bc, 4(%esp)\n" /* line 1205 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a3178_001a3772\n"
        "movl $str_002ac7f8, 8(%esp)\n" /* line 1207 */
        "movl $0x400, 4(%esp)\n"
        "movl imp_level, %eax\n"
        "addl $0x31c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "movl $str_002b39bc, 8(%esp)\n" /* line 1208 */
        /* { scope 2 */
        ".Lf1a3178_001a3628:\n"
        "movl $0x400, 4(%esp)\n" /* line 1191 */
        "movl imp_level, %eax\n"
        "addl $0x71c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        /* } scope */
        ".Lf1a3178_001a3642:\n"
        "movl 0x158(%esi), %eax\n" /* line 1275 | ent */
        "addl $0x2784, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x65, 4(%esp)\n"
        "movl $str_002b3a24, (%esp)\n" /* "%c "GAME_CALLEDAVOTE%s"" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0xffffffff, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        "movl imp_level, %ebx\n" /* line 1278 */
        "movl 0x1ec(%ebx), %eax\n"
        "addl $0x7530, %eax\n"
        "movl %eax, 0xb1c(%ebx)\n"
        "movl $1, 0xb24(%ebx)\n" /* line 1279 */
        "movl $0, 0xb28(%ebx)\n" /* line 1280 */
        "movl 0x1e4(%ebx), %eax\n" /* line 1282 */
        "testl %eax, %eax\n"
        "jle .Lf1a3178_001a36d5\n"
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lf1a3178_001a36b6:\n"
        "movl %edx, %eax\n" /* line 1283 */
        "addl (%ebx), %eax\n"
        "andl $0xffefffff, 0xa0(%eax)\n"
        "addl $1, %ecx\n" /* line 1282 */
        "addl $0x28a4, %edx\n"
        "cmpl 0x1e4(%ebx), %ecx\n"
        "jl .Lf1a3178_001a36b6\n"
        ".Lf1a3178_001a36d5:\n"
        "movl 0x158(%esi), %eax\n" /* line 1284 | ent */
        "orl $0x100000, 0xa0(%eax)\n"
        "movl 0xb1c(%ebx), %eax\n" /* line 1286 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0xf, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "leal 0x71c(%ebx), %eax\n" /* line 1287 */
        "movl %eax, 4(%esp)\n"
        "movl $0x10, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "movl 0xb24(%ebx), %eax\n" /* line 1288 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x11, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "movl 0xb28(%ebx), %eax\n" /* line 1289 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x12, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "jmp .Lf1a3178_001a327d\n"
        ".Lf1a3178_001a3772:\n"
        "movl $str_002ac814, 4(%esp)\n" /* line 1210 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a3178_001a3820\n"
        "movl %ebx, 0xc(%esp)\n" /* line 1212 */
        "movl $str_00216058, 8(%esp)\n" /* "%s" */
        "movl $0x400, 4(%esp)\n"
        "movl imp_level, %eax\n"
        "addl $0x31c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "movl $str_002b39d4, 8(%esp)\n" /* line 1213 */
        "jmp .Lf1a3178_001a3628\n"
        ".Lf1a3178_001a37bd:\n"
        "movl $0x65, 4(%esp)\n" /* line 1219 */
        "movl $str_002b38d8, (%esp)\n" /* "%c "the server doesn't have that map"" */
        "jmp .Lf1a3178_001a3255\n"
        ".Lf1a3178_001a37d1:\n"
        "leal -0x258(%ebp), %eax\n" /* line 1202 | arg2 */
        "movl %eax, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n"
        "movl $str_002b39a8, 8(%esp)\n" /* "%s %s; map_restart" */
        "movl $0x400, 4(%esp)\n"
        "movl imp_level, %eax\n"
        "addl $0x31c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "leal -0x258(%ebp), %edx\n" /* line 1203 | arg2 */
        "movl %edx, (%esp)\n"
        "calll Scr_GetGameTypeNameForScript\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002b3990, 8(%esp)\n" /* "GAME_VOTE_GAMETYPE%s" */
        "jmp .Lf1a3178_001a3628\n"
        ".Lf1a3178_001a3820:\n"
        "movl $str_002ac808, 4(%esp)\n" /* line 1215 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a3178_001a3947\n"
        "leal -0x258(%ebp), %eax\n" /* line 1217 | arg2 */
        "movl %eax, (%esp)\n"
        "calll SV_MapExists\n"
        "testl %eax, %eax\n"
        "je .Lf1a3178_001a37bd\n"
        "leal -0x258(%ebp), %edx\n" /* line 1222 | arg2 */
        "movl %edx, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n"
        "movl $str_002ae9f4, 8(%esp)\n" /* "%s %s" */
        "movl $0x400, 4(%esp)\n"
        "movl imp_level, %eax\n"
        "addl $0x31c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "leal -0x258(%ebp), %eax\n" /* line 1223 | arg2 */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002b3960, 8(%esp)\n" /* "GAME_VOTE_MAP%s" */
        "jmp .Lf1a3178_001a3628\n"
        /* { scope 2 */
        ".Lf1a3178_001a3895:\n"
        "movl %edi, 0xc(%esp)\n" /* line 1181 */
        "movl $str_002b3a40, 8(%esp)\n" /* "map %s" */
        "movl $0x400, 4(%esp)\n"
        "movl imp_level, %eax\n"
        "addl $0x31c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        ".Lf1a3178_001a38bb:\n"
        "cmpb $0, -0x258(%ebp)\n" /* line 1183 | arg2 */
        "je .Lf1a3178_001a3b59\n"
        "leal -0x258(%ebp), %eax\n" /* line 1184 | arg2 */
        "movl %eax, (%esp)\n"
        "calll Scr_GetGameTypeNameForScript\n"
        "movl %edi, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002b3934, 8(%esp)\n" /* "GAME_VOTE_GAMETYPE%s - GAME_VOTE_MAP%s" */
        "movl $0x400, 4(%esp)\n"
        "movl imp_level, %eax\n"
        "addl $0x71c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "jmp .Lf1a3178_001a3642\n"
        ".Lf1a3178_001a3905:\n"
        "cmpb $0, -0x358(%ebp)\n" /* line 1176 | arg3 */
        "je .Lf1a3178_001a3bd1\n"
        "movl %edi, 0x10(%esp)\n" /* line 1179 */
        "leal -0x258(%ebp), %edx\n" /* arg2 */
        "movl %edx, 0xc(%esp)\n"
        "movl $str_002b391c, 8(%esp)\n" /* "g_gametype %s; map %s" */
        "movl $0x400, 4(%esp)\n"
        "movl imp_level, %eax\n"
        "addl $0x31c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "jmp .Lf1a3178_001a38bb\n"
        /* } scope */
        ".Lf1a3178_001a3947:\n"
        "movl $str_002ac790, 4(%esp)\n" /* line 1225 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1a3178_001a3973\n"
        "movl $str_002ac7c0, 4(%esp)\n" /* "clientkick" */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a3178_001a3b6a\n"
        /* { scope 2 */
        ".Lf1a3178_001a3973:\n"
        "movl $str_002ac790, 4(%esp)\n" /* line 1230 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a3178_001a3a0f\n"
        ".Lf1a3178_001a398b:\n"
        "movl $0x40, -0x35c(%ebp)\n" /* kicknum */
        "xorl %edi, %edi\n" /* i */
        "xorl %ebx, %ebx\n"
        "jmp .Lf1a3178_001a39ad\n"
        ".Lf1a3178_001a399b:\n"
        "addl $1, %edi\n" /* line 1232 | i */
        "addl $0x28a4, %ebx\n"
        "cmpl $0x40, %edi\n" /* i */
        "je .Lf1a3178_001a3b9f\n"
        ".Lf1a3178_001a39ad:\n"
        "movl %ebx, %eax\n" /* line 1234 */
        "movl imp_level, %edx\n"
        "addl (%edx), %eax\n"
        "cmpl $2, 0x26c4(%eax)\n"
        "jne .Lf1a3178_001a399b\n"
        "movl $0x40, 8(%esp)\n" /* line 1237 */
        "addl $0x2784, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %eax\n" /* cleanName */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "leal -0x58(%ebp), %edx\n" /* line 1238 | cleanName */
        "movl %edx, (%esp)\n"
        "calll I_CleanStr\n"
        "leal -0x258(%ebp), %eax\n" /* line 1239 | arg2 */
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %edx\n" /* cleanName */
        "movl %edx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "movl -0x35c(%ebp), %eax\n" /* kicknum */
        "cmovel %edi, %eax\n" /* i */
        "movl %eax, -0x35c(%ebp)\n" /* kicknum */
        "jmp .Lf1a3178_001a399b\n"
        ".Lf1a3178_001a3a0f:\n"
        "movl $str_002ac798, 4(%esp)\n" /* line 1230 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1a3178_001a398b\n"
        "leal -0x258(%ebp), %eax\n" /* line 1245 | arg2 */
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, -0x35c(%ebp)\n" /* kicknum */
        "cmpl $0, %eax\n" /* line 1247 */
        "je .Lf1a3178_001a3a92\n"
        "jl .Lf1a3178_001a3a7e\n"
        "cmpl $0x3f, -0x35c(%ebp)\n" /* kicknum */
        "jg .Lf1a3178_001a3a7e\n"
        ".Lf1a3178_001a3a4b:\n"
        "movl -0x35c(%ebp), %edx\n" /* kicknum */
        "leal (%edx, %edx, 4), %eax\n"
        "movl %eax, %edx\n"
        "shll $6, %edx\n"
        "addl %edx, %eax\n"
        "movl -0x35c(%ebp), %edx\n" /* kicknum */
        "leal (%edx, %eax, 8), %eax\n"
        "leal (, %eax, 4), %edi\n" /* i */
        "movl imp_level, %eax\n"
        "movl (%eax), %edx\n"
        "leal (%edi, %edx), %eax\n" /* i */
        "cmpl $2, 0x26c4(%eax)\n"
        "je .Lf1a3178_001a3aae\n"
        ".Lf1a3178_001a3a7e:\n"
        "movl $0x65, 4(%esp)\n" /* line 1262 */
        "movl $str_002b39e8, (%esp)\n" /* "%c "GAME_CLIENTNOTONSERVER"" */
        "jmp .Lf1a3178_001a3255\n"
        ".Lf1a3178_001a3a92:\n"
        "movl $str_0021952c, 4(%esp)\n" /* line 1247 */
        "leal -0x258(%ebp), %edx\n" /* arg2 */
        "movl %edx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a3178_001a3a7e\n"
        "jmp .Lf1a3178_001a3a4b\n"
        ".Lf1a3178_001a3aae:\n"
        "movl $0x40, 8(%esp)\n" /* line 1254 */
        "addl $0x2784, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %ebx\n" /* cleanName */
        "movl %ebx, (%esp)\n"
        "calll I_strncpyz\n"
        "movl %ebx, (%esp)\n" /* line 1255 */
        "calll I_CleanStr\n"
        ".Lf1a3178_001a3ad2:\n"
        "movzbl -0x158(%ebp), %eax\n" /* line 1266 | arg1 */
        "cmpb $0x74, %al\n"
        "je .Lf1a3178_001a3c1c\n"
        "cmpb $0x54, %al\n"
        "je .Lf1a3178_001a3c1c\n"
        "movl $str_002ac7c0, %eax\n" /* "clientkick" */
        ".Lf1a3178_001a3aee:\n"
        "movl -0x35c(%ebp), %edx\n" /* kicknum */
        "movl %edx, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002b3a04, 8(%esp)\n" /* "%s "%d"" */
        "movl $0x400, 4(%esp)\n"
        "movl imp_level, %ebx\n"
        "leal 0x31c(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "addl (%ebx), %edi\n" /* line 1267 | i */
        "leal 0x2784(%edi), %eax\n" /* i */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x35c(%ebp), %eax\n" /* kicknum */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002b3a0c, 8(%esp)\n" /* "GAME_VOTE_KICK(%i)%s" */
        "movl $0x400, 4(%esp)\n"
        "addl $0x71c, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "jmp .Lf1a3178_001a3642\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1a3178_001a3b59:\n"
        "movl %edi, 0xc(%esp)\n" /* line 1186 */
        "movl $str_002b3960, 8(%esp)\n" /* "GAME_VOTE_MAP%s" */
        "jmp .Lf1a3178_001a3628\n"
        /* } scope */
        ".Lf1a3178_001a3b6a:\n"
        "movl $str_002ac798, 4(%esp)\n" /* line 1225 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1a3178_001a3973\n"
        "movl $str_002ac7a4, 4(%esp)\n" /* "tempBanClient" */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1a3178_001a3973\n"
        "jmp .Lf1a3178_001a327d\n"
        /* { scope 2 */
        ".Lf1a3178_001a3b9f:\n"
        "cmpl $0x40, -0x35c(%ebp)\n" /* line 1260 | kicknum */
        "je .Lf1a3178_001a3a7e\n"
        "movl -0x35c(%ebp), %edx\n" /* line 1263 | kicknum */
        "leal (%edx, %edx, 4), %eax\n"
        "movl %eax, %edx\n"
        "shll $6, %edx\n"
        "addl %edx, %eax\n"
        "movl -0x35c(%ebp), %edx\n" /* kicknum */
        "leal (%edx, %eax, 8), %eax\n"
        "leal (, %eax, 4), %edi\n" /* i */
        "jmp .Lf1a3178_001a3ad2\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1a3178_001a3bd1:\n"
        "leal -0x258(%ebp), %edx\n" /* line 1190 | arg2 */
        "movl %edx, 0xc(%esp)\n"
        "movl $str_002b3974, 8(%esp)\n" /* "g_gametype %s; map_restart" */
        "movl $0x400, 4(%esp)\n"
        "movl imp_level, %eax\n"
        "addl $0x31c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "leal -0x258(%ebp), %eax\n" /* line 1191 | arg2 */
        "movl %eax, (%esp)\n"
        "calll Scr_GetGameTypeNameForScript\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002b3990, 8(%esp)\n" /* "GAME_VOTE_GAMETYPE%s" */
        "jmp .Lf1a3178_001a3628\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1a3178_001a3c1c:\n"
        "movl $str_002ac7a4, %eax\n" /* line 1266 */
        "jmp .Lf1a3178_001a3aee\n"
    );
}

/* line 1302 */
__attribute__((naked))
void Cmd_Vote_f(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1302 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x54, %esp\n"
        "movl 8(%ebp), %ebx\n" /* ent */
        /* { scope 1 */
        "movl imp_g_oldVoting, %eax\n" /* line 1306 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1a3c26_001a3cb9\n"
        "movl imp_level, %eax\n" /* line 1308 */
        "movl 0xb1c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1a3c26_001a3d39\n"
        "movl 0x158(%ebx), %eax\n" /* line 1313 | ent */
        "testb $0x10, 0xa2(%eax)\n"
        "jne .Lf1a3c26_001a3dd3\n"
        "cmpl $3, 0x274c(%eax)\n" /* line 1318 */
        "je .Lf1a3c26_001a3de7\n"
        "movl $0x65, 4(%esp)\n" /* line 1324 */
        "movl $str_002b3a9c, (%esp)\n" /* "%c "GAME_VOTECAST"" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, %eax\n" /* ent */
        "subl imp_g_entities, %eax\n"
        "sarl $4, %eax\n"
        "imull $0x8af8af8b, %eax, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        "movl 0x158(%ebx), %eax\n" /* line 1326 | ent */
        "orl $0x100000, 0xa0(%eax)\n"
        ".Lf1a3c26_001a3cb9:\n"
        "movl $0x40, 8(%esp)\n" /* line 1329 */
        "leal -0x48(%ebp), %eax\n" /* msg */
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll SV_Cmd_ArgvBuffer\n"
        "cmpb $0x79, -0x48(%ebp)\n" /* line 1331 | msg */
        "je .Lf1a3c26_001a3d76\n"
        "movzbl -0x47(%ebp), %eax\n"
        "cmpb $0x59, %al\n"
        "je .Lf1a3c26_001a3d76\n"
        "cmpb $0x31, %al\n"
        "je .Lf1a3c26_001a3d76\n"
        "movl imp_g_oldVoting, %eax\n" /* line 1345 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1a3c26_001a3dfb\n"
        "movl imp_level, %eax\n" /* line 1347 */
        "movl 0xb28(%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, 0xb28(%eax)\n"
        "movl %edx, 4(%esp)\n" /* line 1348 */
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x12, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "jmp .Lf1a3c26_001a3d70\n"
        ".Lf1a3c26_001a3d39:\n"
        "movl $0x65, 4(%esp)\n" /* line 1310 */
        "movl $str_002b3a48, (%esp)\n" /* "%c "GAME_NOVOTEINPROGRESS"" */
        ".Lf1a3c26_001a3d48:\n"
        "calll va\n" /* line 1315 */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "subl imp_g_entities, %ebx\n" /* ent */
        "sarl $4, %ebx\n" /* ent */
        "imull $0x8af8af8b, %ebx, %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        /* } scope */
        ".Lf1a3c26_001a3d70:\n"
        "addl $0x54, %esp\n" /* line 1358 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1a3c26_001a3d76:\n"
        "movl imp_g_oldVoting, %eax\n" /* line 1333 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1a3c26_001a3d99\n"
        "movl $str_002b3ab0, 4(%esp)\n" /* line 1340 */
        "movl %ebx, (%esp)\n" /* ent */
        "calll Scr_PlayerVote\n"
        /* } scope */
        "addl $0x54, %esp\n" /* line 1358 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1a3c26_001a3d99:\n"
        "movl imp_level, %eax\n" /* line 1335 */
        "movl 0xb24(%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, 0xb24(%eax)\n"
        "movl %edx, 4(%esp)\n" /* line 1336 */
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x11, (%esp)\n"
        "calll SV_SetConfigstring\n"
        /* } scope */
        "addl $0x54, %esp\n" /* line 1358 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1a3c26_001a3dd3:\n"
        "movl $0x65, 4(%esp)\n" /* line 1315 */
        "movl $str_002b3a64, (%esp)\n" /* "%c "GAME_VOTEALREADYCAST"" */
        "jmp .Lf1a3c26_001a3d48\n"
        ".Lf1a3c26_001a3de7:\n"
        "movl $0x65, 4(%esp)\n" /* line 1320 */
        "movl $str_002b3a80, (%esp)\n" /* "%c "GAME_NOSPECTATORVOTE"" */
        "jmp .Lf1a3c26_001a3d48\n"
        ".Lf1a3c26_001a3dfb:\n"
        "movl $str_002b3ab4, 4(%esp)\n" /* line 1352 */
        "movl %ebx, (%esp)\n" /* ent */
        "calll Scr_PlayerVote\n"
        "jmp .Lf1a3c26_001a3d70\n"
    );
}

/* line 1366 */
__attribute__((naked))
void Cmd_SetViewpos_f(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1366 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x44c, %esp\n"
        "movl 8(%ebp), %esi\n" /* ent */
        /* { scope 1 */
        "movl imp_g_cheats, %eax\n" /* line 1375 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1a3e10_001a3e6e\n"
        "movl $0x65, 4(%esp)\n" /* line 1377 */
        "movl $str_002b3620, (%esp)\n" /* "%c "GAME_CHEATSNOTENABLED"" */
        ".Lf1a3e10_001a3e3b:\n"
        "calll va\n" /* line 1382 */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "subl imp_g_entities, %esi\n" /* ent */
        "sarl $4, %esi\n" /* ent */
        "imull $0x8af8af8b, %esi, %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        /* } scope */
        "addl $0x44c, %esp\n" /* line 1399 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1a3e10_001a3e6e:\n"
        "calll SV_Cmd_Argc\n" /* line 1380 */
        "cmpl $5, %eax\n"
        "je .Lf1a3e10_001a3e89\n"
        "movl $0x65, 4(%esp)\n" /* line 1382 */
        "movl $str_002b3ab8, (%esp)\n" /* "%c "GAME_USAGE: setviewpos x y z yaw"" */
        "jmp .Lf1a3e10_001a3e3b\n"
        ".Lf1a3e10_001a3e89:\n"
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, -0x30(%ebp)\n" /* angles */
        "movl %eax, -0x2c(%ebp)\n" /* line 184 */
        "movl %eax, -0x28(%ebp)\n" /* line 185 */
        "xorl %ebx, %ebx\n"
        "leal -0x430(%ebp), %edi\n" /* buffer */
        ".Lf1a3e10_001a3e9c:\n"
        "addl $1, %ebx\n" /* line 1389 | i */
        "movl $0x400, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* i */
        "calll SV_Cmd_ArgvBuffer\n"
        "movl %edi, (%esp)\n" /* line 1390 */
        "calll atof\n"
        "fstpl -0x448(%ebp)\n"
        "cvtsd2ss -0x448(%ebp), %xmm0\n"
        "movss %xmm0, -0x28(%ebp, %ebx, 4)\n"
        "cmpl $3, %ebx\n" /* line 1387 | i */
        "jne .Lf1a3e10_001a3e9c\n"
        "movl $0x400, 8(%esp)\n" /* line 1393 */
        "movl %edi, 4(%esp)\n"
        "movl $4, (%esp)\n"
        "calll SV_Cmd_ArgvBuffer\n"
        "movl %edi, (%esp)\n" /* line 1394 */
        "calll atof\n"
        "fstpl -0x440(%ebp)\n"
        "cvtsd2ss -0x440(%ebp), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movl 0x158(%esi), %eax\n" /* line 1396 | ent */
        "movss -0x1c(%ebp), %xmm0\n"
        "subss 0xf8(%eax), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "leal -0x30(%ebp), %eax\n" /* line 1398 | angles */
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* origin */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* ent */
        "calll TeleportPlayer\n"
        /* } scope */
        "addl $0x44c, %esp\n" /* line 1399 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1421 */
__attribute__((naked))
void Cmd_MenuResponse_f(gentity_t *pEnt)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1421 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xc10, %esp\n"
        /* { scope 1 */
        "calll SV_Cmd_Argc\n" /* line 1428 */
        "cmpl $4, %eax\n"
        "je .Lf1a3f40_001a3fac\n"
        "movb $0, -0x808(%ebp)\n" /* line 1430 | szMenuName */
        "movl $0x646162, -0xc08(%ebp)\n" /* line 1431 | szResponse */
        "leal -0x808(%ebp), %esi\n" /* szMenuName */
        "leal -0xc08(%ebp), %ebx\n" /* szResponse */
        ".Lf1a3f40_001a3f72:\n"
        "movl %ebx, (%esp)\n" /* line 1451 */
        "calll Scr_AddString\n"
        "movl %esi, (%esp)\n" /* line 1452 */
        "calll Scr_AddString\n"
        "movl $2, 8(%esp)\n" /* line 1453 */
        "movl imp_scr_const, %eax\n"
        "movzwl 0x70(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* pEnt */
        "movl %eax, (%esp)\n"
        "calll Scr_Notify\n"
        /* } scope */
        ".Lf1a3f40_001a3fa2:\n"
        "addl $0xc10, %esp\n" /* line 1454 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1a3f40_001a3fac:\n"
        "movl $0x400, 8(%esp)\n" /* line 1435 */
        "leal -0x408(%ebp), %ebx\n" /* szServerId */
        "movl %ebx, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll SV_Cmd_ArgvBuffer\n"
        "movl %ebx, (%esp)\n" /* line 1436 */
        "calll atoi\n"
        "movl %eax, %ebx\n"
        "movl $str_002a8d30, (%esp)\n" /* "sv_serverId" */
        "calll Dvar_GetInt\n"
        "cmpl %eax, %ebx\n"
        "jne .Lf1a3f40_001a3fa2\n"
        "movl $0x400, 8(%esp)\n" /* line 1439 */
        "leal -0x808(%ebp), %esi\n" /* szMenuName */
        "movl %esi, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll SV_Cmd_ArgvBuffer\n"
        "movl %esi, (%esp)\n" /* line 1440 */
        "calll atoi\n"
        "cmpl $0x1f, %eax\n" /* line 1444 */
        "jbe .Lf1a3f40_001a4032\n"
        ".Lf1a3f40_001a400f:\n"
        "movl $0x400, 8(%esp)\n" /* line 1447 */
        "leal -0xc08(%ebp), %ebx\n" /* szResponse */
        "movl %ebx, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll SV_Cmd_ArgvBuffer\n"
        "jmp .Lf1a3f40_001a3f72\n"
        ".Lf1a3f40_001a4032:\n"
        "movl $0x400, 8(%esp)\n" /* line 1445 */
        "movl %esi, 4(%esp)\n"
        "addl $0x4de, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_GetConfigstring\n"
        "jmp .Lf1a3f40_001a400f\n"
    );
}

/* line 814 */
static __attribute__((naked))
void G_SayTo(int color, const char *name, const char *message)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 814 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, %edi\n" /* ent */
        "movl %edx, %ebx\n" /* other */
        "movl %ecx, %esi\n" /* mode */
        "movl 8(%ebp), %eax\n" /* color */
        "movl %eax, -0x1c(%ebp)\n" /* color */
        "movl 0xc(%ebp), %edx\n" /* name */
        "movl %edx, -0x20(%ebp)\n" /* name */
        "movl 0x10(%ebp), %eax\n" /* message */
        "movl %eax, -0x24(%ebp)\n" /* message */
        "testl %ebx, %ebx\n" /* line 816 | other */
        "je .Lf1a404e_001a408f\n"
        "cmpb $0, 0xfc(%ebx)\n" /* line 820 | other */
        "je .Lf1a404e_001a408f\n"
        "movl 0x158(%ebx), %eax\n" /* line 824 | other */
        "testl %eax, %eax\n"
        "je .Lf1a404e_001a408f\n"
        "cmpl $2, 0x26c4(%eax)\n" /* line 828 */
        "je .Lf1a404e_001a4097\n"
        ".Lf1a404e_001a408f:\n"
        "addl $0x3c, %esp\n" /* line 843 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1a404e_001a4097:\n"
        "cmpl $1, %ecx\n" /* line 832 */
        "je .Lf1a404e_001a4133\n"
        ".Lf1a404e_001a40a0:\n"
        "movl imp_g_deadChat, %eax\n" /* line 838 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1a404e_001a40cd\n"
        "movl 0x158(%edi), %eax\n" /* ent */
        "movl 0x26a8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1a404e_001a40cd\n"
        "movl 0x158(%ebx), %eax\n" /* other */
        "movl 0x26a8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1a404e_001a408f\n"
        ".Lf1a404e_001a40cd:\n"
        "subl $1, %esi\n" /* line 842 | mode */
        "je .Lf1a404e_001a412c\n"
        "movl $0x68, %eax\n"
        ".Lf1a404e_001a40d7:\n"
        "movl -0x24(%ebp), %edx\n" /* message */
        "movl %edx, 0x14(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* color */
        "movl %edx, 0x10(%esp)\n"
        "movl $0x5e, 0xc(%esp)\n"
        "movl -0x20(%ebp), %edx\n" /* name */
        "movl %edx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b3af4, (%esp)\n" /* "%c "%s%c%c%s"" */
        "calll va\n"
        "movl %eax, 0x10(%ebp)\n" /* message */
        "movl $0, 0xc(%ebp)\n" /* name */
        "subl imp_g_entities, %ebx\n" /* other */
        "sarl $4, %ebx\n" /* other */
        "imull $0x8af8af8b, %ebx, %eax\n" /* other */
        "movl %eax, 8(%ebp)\n" /* color */
        "addl $0x3c, %esp\n" /* line 843 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp SV_GameSendServerCommand\n" /* line 842 */
        ".Lf1a404e_001a412c:\n"
        "movl $0x69, %eax\n" /* line 838 */
        "jmp .Lf1a404e_001a40d7\n"
        ".Lf1a404e_001a4133:\n"
        "movl %ebx, 4(%esp)\n" /* line 832 | other */
        "movl %edi, (%esp)\n" /* ent */
        "calll OnSameTeam\n"
        "testl %eax, %eax\n"
        "jne .Lf1a404e_001a40a0\n"
        "jmp .Lf1a404e_001a408f\n"
    );
}

/* line 846 */
__attribute__((naked))
void G_Say(gentity_t *ent, gentity_t *target, int mode, const char *chatText)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 846 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1dc, %esp\n"
        /* { scope 1 */
        "cmpl $1, 0x10(%ebp)\n" /* line 860 | mode */
        "je .Lf1a414c_001a4431\n"
        "movl 8(%ebp), %edx\n" /* ent */
        "movl 0x158(%edx), %eax\n"
        ".Lf1a414c_001a416b:\n"
        "movl $0x40, 8(%esp)\n" /* line 863 */
        "addl $0x2784, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %edi\n" /* cleanname */
        "movl %edi, (%esp)\n"
        "calll I_strncpyz\n"
        "movl %edi, (%esp)\n" /* line 864 */
        "calll I_CleanStr\n"
        "movl 8(%ebp), %eax\n" /* line 866 | ent */
        "movl 0x158(%eax), %edx\n"
        "movl 0x274c(%edx), %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf1a414c_001a4419\n"
        "cmpl $2, %eax\n"
        "je .Lf1a414c_001a445e\n"
        "movl $str_002157b8, %ecx\n"
        "cmpl $3, %eax\n" /* line 881 */
        "je .Lf1a414c_001a44b9\n"
        "movl 0x26a8(%edx), %esi\n" /* line 883 | j */
        "testl %esi, %esi\n" /* j */
        "je .Lf1a414c_001a42c4\n"
        ".Lf1a414c_001a41cc:\n"
        "movl %ecx, 0xc(%esp)\n" /* line 884 */
        "movl $str_002b3b20, 8(%esp)\n" /* "%s(GAME_DEAD)" */
        "movl $0x40, 4(%esp)\n"
        "leal -0x98(%ebp), %eax\n" /* szStateString */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        ".Lf1a414c_001a41ee:\n"
        "cmpl $1, 0x10(%ebp)\n" /* line 888 | mode */
        "je .Lf1a414c_001a42f0\n"
        ".Lf1a414c_001a41f8:\n"
        "cmpl $2, 0x10(%ebp)\n" /* mode */
        "je .Lf1a414c_001a4476\n"
        "movl 8(%ebp), %eax\n" /* line 892 | ent */
        "movl (%eax), %ebx\n" /* pszTeamString */
        "movl %ebx, (%esp)\n" /* pszTeamString */
        "calll SV_GetGuid\n"
        "movl 0x14(%ebp), %edx\n" /* chatText */
        "movl %edx, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* pszTeamString */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b3b34, (%esp)\n" /* "say;%d;%d;%s;%s
" */
        "calll G_LogPrintf\n"
        "movl $str_002b3b48, 0x14(%esp)\n" /* line 893 */
        "movl %edi, 0x10(%esp)\n"
        "leal -0x98(%ebp), %eax\n" /* szStateString */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002b3b4c, 8(%esp)\n" /* "%s%s%s: " */
        "movl $0x80, 4(%esp)\n"
        "leal -0x118(%ebp), %edx\n" /* name */
        "movl %edx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl $0x37, -0x1bc(%ebp)\n" /* color */
        ".Lf1a414c_001a426c:\n"
        "movl $0x96, 8(%esp)\n" /* line 913 */
        "movl 0x14(%ebp), %eax\n" /* chatText */
        "movl %eax, 4(%esp)\n"
        "leal -0x1ae(%ebp), %edi\n" /* text */
        "movl %edi, (%esp)\n"
        "calll I_strncpyz\n"
        "movl 0xc(%ebp), %ebx\n" /* line 915 | target, pszTeamString */
        "testl %ebx, %ebx\n" /* pszTeamString */
        "je .Lf1a414c_001a43a0\n"
        ".Lf1a414c_001a4294:\n"
        "movl %edi, 8(%esp)\n" /* line 917 */
        "leal -0x118(%ebp), %edx\n" /* name */
        "movl %edx, 4(%esp)\n"
        "movl -0x1bc(%ebp), %eax\n" /* color */
        "movl %eax, (%esp)\n"
        "movl 0x10(%ebp), %ecx\n" /* mode */
        "movl 0xc(%ebp), %edx\n" /* target */
        "movl 8(%ebp), %eax\n" /* ent */
        "calll G_SayTo\n"
        /* } scope */
        ".Lf1a414c_001a42b9:\n"
        "addl $0x1dc, %esp\n" /* line 931 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1a414c_001a42c4:\n"
        "movl %ecx, 0xc(%esp)\n" /* line 886 */
        "movl $str_0021cdd0, 8(%esp)\n" /* "%s" */
        "movl $0x40, 4(%esp)\n"
        "leal -0x98(%ebp), %edx\n" /* szStateString */
        "movl %edx, (%esp)\n"
        "calll Com_sprintf\n"
        "cmpl $1, 0x10(%ebp)\n" /* line 888 | mode */
        "jne .Lf1a414c_001a41f8\n"
        ".Lf1a414c_001a42f0:\n"
        "movl 8(%ebp), %edx\n" /* line 898 | ent */
        "movl 0x158(%edx), %eax\n"
        "movl $str_002b3b58, %ebx\n" /* pszTeamString */
        "cmpl $1, 0x274c(%eax)\n"
        "movl $str_002b3b64, %eax\n" /* "GAME_ALLIES" */
        "cmovnel %eax, %ebx\n" /* pszTeamString */
        "movl (%edx), %esi\n" /* line 903 | j */
        "movl %esi, (%esp)\n" /* j */
        "calll SV_GetGuid\n"
        "movl 0x14(%ebp), %edx\n" /* chatText */
        "movl %edx, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* j */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b3b70, (%esp)\n" /* "sayteam;%d;%d;%s;%s
" */
        "calll G_LogPrintf\n"
        "movl $str_002b3b48, 0x18(%esp)\n" /* line 904 */
        "movl %edi, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n" /* pszTeamString */
        "leal -0x98(%ebp), %eax\n" /* szStateString */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002b3b88, 8(%esp)\n" /* "%s(%s)%s%s: " */
        "movl $0x80, 4(%esp)\n"
        "leal -0x118(%ebp), %edx\n" /* name */
        "movl %edx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl $0x35, -0x1bc(%ebp)\n" /* color */
        "movl $0x96, 8(%esp)\n" /* line 913 */
        "movl 0x14(%ebp), %eax\n" /* chatText */
        "movl %eax, 4(%esp)\n"
        "leal -0x1ae(%ebp), %edi\n" /* text */
        "movl %edi, (%esp)\n"
        "calll I_strncpyz\n"
        "movl 0xc(%ebp), %ebx\n" /* line 915 | target, pszTeamString */
        "testl %ebx, %ebx\n" /* pszTeamString */
        "jne .Lf1a414c_001a4294\n"
        ".Lf1a414c_001a43a0:\n"
        "movl imp_g_dedicated, %eax\n" /* line 922 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf1a414c_001a44e8\n"
        ".Lf1a414c_001a43b2:\n"
        "movl imp_level, %eax\n" /* line 926 */
        "movl 0x1e4(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf1a414c_001a42b9\n"
        "xorl %esi, %esi\n" /* j */
        "movl %eax, -0x1c0(%ebp)\n"
        "movl imp_g_entities, %ebx\n" /* pszTeamString */
        ".Lf1a414c_001a43d3:\n"
        "movl %edi, 8(%esp)\n" /* line 929 */
        "leal -0x118(%ebp), %eax\n" /* name */
        "movl %eax, 4(%esp)\n"
        "movl -0x1bc(%ebp), %edx\n" /* color */
        "movl %edx, (%esp)\n"
        "movl 0x10(%ebp), %ecx\n" /* mode */
        "movl %ebx, %edx\n" /* pszTeamString */
        "movl 8(%ebp), %eax\n" /* ent */
        "calll G_SayTo\n"
        "addl $1, %esi\n" /* line 926 | j */
        "addl $0x230, %ebx\n" /* pszTeamString */
        "movl -0x1c0(%ebp), %eax\n"
        "cmpl %esi, 0x1e4(%eax)\n" /* j */
        "jg .Lf1a414c_001a43d3\n"
        /* } scope */
        "addl $0x1dc, %esp\n" /* line 931 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1a414c_001a4419:\n"
        "movl $str_002b3b04, %ecx\n" /* line 866 */
        "movl 0x26a8(%edx), %esi\n" /* line 883 | j */
        "testl %esi, %esi\n" /* j */
        "je .Lf1a414c_001a42c4\n"
        "jmp .Lf1a414c_001a41cc\n"
        ".Lf1a414c_001a4431:\n"
        "movl 8(%ebp), %edx\n" /* line 860 | ent */
        "movl 0x158(%edx), %eax\n"
        "movl 0x274c(%eax), %edx\n"
        "cmpl $1, %edx\n"
        "je .Lf1a414c_001a44dc\n"
        "cmpl $2, %edx\n"
        "je .Lf1a414c_001a44dc\n"
        "movl $0, 0x10(%ebp)\n" /* mode */
        "jmp .Lf1a414c_001a416b\n"
        ".Lf1a414c_001a445e:\n"
        "movl $str_002b3b08, %ecx\n" /* line 866 */
        "movl 0x26a8(%edx), %esi\n" /* line 883 | j */
        "testl %esi, %esi\n" /* j */
        "je .Lf1a414c_001a42c4\n"
        "jmp .Lf1a414c_001a41cc\n"
        ".Lf1a414c_001a4476:\n"
        "movl $str_002b3b48, 0x14(%esp)\n" /* line 908 */
        "movl %edi, 0x10(%esp)\n"
        "leal -0x98(%ebp), %eax\n" /* szStateString */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002b3b98, 8(%esp)\n" /* "%s[%s]%s: " */
        "movl $0x80, 4(%esp)\n"
        "leal -0x118(%ebp), %edx\n" /* name */
        "movl %edx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl $0x33, -0x1bc(%ebp)\n" /* color */
        "jmp .Lf1a414c_001a426c\n"
        ".Lf1a414c_001a44b9:\n"
        "movl $str_002b3b0c, 8(%esp)\n" /* line 882 */
        "movl $0x40, 4(%esp)\n"
        "leal -0x98(%ebp), %edx\n" /* szStateString */
        "movl %edx, (%esp)\n"
        "calll Com_sprintf\n"
        "jmp .Lf1a414c_001a41ee\n"
        ".Lf1a414c_001a44dc:\n"
        "movl $1, 0x10(%ebp)\n" /* line 860 | mode */
        "jmp .Lf1a414c_001a416b\n"
        ".Lf1a414c_001a44e8:\n"
        "movl %edi, 8(%esp)\n" /* line 923 */
        "leal -0x118(%ebp), %edx\n" /* name */
        "movl %edx, 4(%esp)\n"
        "movl $str_002b3ba4, (%esp)\n" /* "%s%s
" */
        "calll Com_Printf\n"
        "jmp .Lf1a414c_001a43b2\n"
    );
}

/* line 1019 */
__attribute__((naked))
void Cmd_GameCommand_f(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1019 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x410, %esp\n"
        /* { scope 1 */
        "movl $0x400, 8(%esp)\n" /* line 1025 */
        "leal -0x408(%ebp), %ebx\n" /* str, order */
        "movl %ebx, 4(%esp)\n" /* order */
        "movl $1, (%esp)\n"
        "calll SV_Cmd_ArgvBuffer\n"
        "movl %ebx, (%esp)\n" /* line 1026 | order */
        "calll atoi\n"
        "movl %eax, %esi\n" /* player */
        "movl $0x400, 8(%esp)\n" /* line 1027 */
        "movl %ebx, 4(%esp)\n" /* order */
        "movl $2, (%esp)\n"
        "calll SV_Cmd_ArgvBuffer\n"
        "movl %ebx, (%esp)\n" /* line 1028 | order */
        "calll atoi\n"
        "movl %eax, %ebx\n" /* order */
        "cmpl $0x3f, %esi\n" /* line 1030 | player */
        "ja .Lf1a4508_001a4567\n"
        "cmpl $6, %eax\n" /* line 1034 */
        "jbe .Lf1a4508_001a4571\n"
        /* } scope */
        ".Lf1a4508_001a4567:\n"
        "addl $0x410, %esp\n" /* line 1040 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1a4508_001a4571:\n"
        "movl gc_orders(, %eax, 4), %eax\n" /* line 1038 */
        "movl %eax, 0xc(%esp)\n"
        "movl $2, 8(%esp)\n"
        "leal (%esi, %esi, 4), %edx\n" /* player */
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl imp_g_entities, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll G_Say\n"
        "movl gc_orders(, %ebx, 4), %eax\n" /* line 1039 */
        "movl %eax, 0xc(%esp)\n"
        "movl $2, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "movl %eax, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll G_Say\n"
        /* } scope */
        "addl $0x410, %esp\n" /* line 1040 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 667 */
__attribute__((naked))
void StopFollowing(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 667 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl 8(%ebp), %edi\n" /* ent */
        /* { scope 1 */
        "movl 0x158(%edi), %esi\n" /* line 679 | ent, client */
        "movl $0xffffffff, 0x26ac(%esi)\n" /* line 681 | client */
        "movl $0xffffffff, 0x27a8(%esi)\n" /* line 682 | client */
        "testb $0x40, 0xe(%esi)\n" /* line 684 | client */
        "je .Lf1a45d4_001a481a\n"
        "leal -0x30(%ebp), %ebx\n" /* line 688 | vPos */
        "movl %ebx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ent */
        "calll G_GetPlayerViewOrigin\n"
        "leal -0x48(%ebp), %eax\n" /* line 689 | vUp */
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* vForward */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ent */
        "calll G_GetPlayerViewDirection\n"
        "leal 0xe8(%esi), %edx\n" /* client */
        /* { scope 2 */
        "movss 0xe8(%esi), %xmm0\n" /* line 199 */
        "movss %xmm0, -0x24(%ebp)\n" /* vAngles */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x20(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n"
        /* } scope */
        "addss lit4_002ed908, %xmm0\n" /* line 692 | 15.0f */
        "movss %xmm0, -0x24(%ebp)\n" /* vAngles */
        "movss lit4_002ed998, %xmm1\n" /* line 288 | -40.0f */
        "movss -0x3c(%ebp), %xmm0\n" /* vForward */
        "mulss %xmm1, %xmm0\n"
        "addss -0x30(%ebp), %xmm0\n" /* vPos */
        "movss %xmm0, -0x54(%ebp)\n" /* vEnd */
        "movss -0x38(%ebp), %xmm0\n" /* line 289 */
        "mulss %xmm1, %xmm0\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, -0x50(%ebp)\n"
        "mulss -0x34(%ebp), %xmm1\n" /* line 290 */
        "addss -0x28(%ebp), %xmm1\n"
        "movss %xmm1, -0x4c(%ebp)\n"
        "movss lit4_002ed6b4, %xmm1\n" /* line 288 | 10.0f */
        "movss -0x48(%ebp), %xmm0\n" /* vUp */
        "mulss %xmm1, %xmm0\n"
        "addss -0x54(%ebp), %xmm0\n" /* vEnd */
        "movss %xmm0, -0x54(%ebp)\n" /* vEnd */
        "movss -0x44(%ebp), %xmm0\n" /* line 289 */
        "mulss %xmm1, %xmm0\n"
        "addss -0x50(%ebp), %xmm0\n"
        "movss %xmm0, -0x50(%ebp)\n"
        "mulss -0x40(%ebp), %xmm1\n" /* line 290 */
        "addss -0x4c(%ebp), %xmm1\n"
        "movss %xmm1, -0x4c(%ebp)\n"
        "movl $0xc1000000, %eax\n" /* line 191 */
        "movl %eax, -0x60(%ebp)\n" /* vMins */
        "movl %eax, -0x5c(%ebp)\n" /* line 192 */
        "movl %eax, -0x58(%ebp)\n" /* line 193 */
        "movl $0x41000000, %eax\n" /* line 191 */
        "movl %eax, -0x6c(%ebp)\n" /* vMaxs */
        "movl %eax, -0x68(%ebp)\n" /* line 192 */
        "movl %eax, -0x64(%ebp)\n" /* line 193 */
        "movl $0x00810011, 0x18(%esp)\n" /* line 700 */
        "movl $0x3ff, 0x14(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* vEnd */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x6c(%ebp), %eax\n" /* vMaxs */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x60(%ebp), %eax\n" /* vMins */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "leal -0x90(%ebp), %eax\n" /* trace */
        "movl %eax, (%esp)\n"
        "calll G_TraceCapsule\n"
        "movss -0x90(%ebp), %xmm2\n" /* line 701 | trace, fraction */
        /* { scope 2 */
        "movss -0x30(%ebp), %xmm1\n" /* line 1203 | vPos */
        "movss -0x54(%ebp), %xmm0\n" /* vEnd */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n" /* vPos */
        "movss -0x2c(%ebp), %xmm1\n" /* line 1204 */
        "movss -0x50(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n"
        "movss -0x28(%ebp), %xmm1\n" /* line 1205 */
        "movss -0x4c(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        /* } scope */
        "movl %edi, %eax\n" /* line 703 | ent */
        "subl imp_g_entities, %eax\n"
        "sarl $4, %eax\n"
        "imull $0x8af8af8b, %eax, %eax\n"
        "movl %eax, 0xcc(%esi)\n" /* client */
        "andl $0xfffffcff, 0xa0(%esi)\n" /* line 706 | client */
        "movl $0, 0x590(%esi)\n" /* line 707 | client */
        "movl $0x3ff, 0x594(%esi)\n" /* line 708 | client */
        "andl $0xffbfffbf, 0xc(%esi)\n" /* line 710 | client */
        "movl $0, 0xdc(%esi)\n" /* line 711 | client */
        "movl %ebx, 4(%esp)\n" /* line 714 */
        "movl %edi, (%esp)\n" /* ent */
        "calll G_SetOrigin\n"
        "leal 0x14(%esi), %edx\n" /* line 715 | client, to */
        /* { scope 2 */
        "movl -0x30(%ebp), %eax\n" /* line 199 | vPos */
        "movl %eax, 0x14(%esi)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal -0x24(%ebp), %eax\n" /* line 718 | vAngles */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* ent */
        "calll SetClientViewAngle\n"
        "movl $0, 0x5d8(%esi)\n" /* line 721 | client */
        "movl $0, 0x5dc(%esi)\n" /* line 722 | client */
        "movl $0, 0x5e0(%esi)\n" /* line 723 | client */
        /* } scope */
        ".Lf1a45d4_001a481a:\n"
        "addl $0xac, %esp\n" /* line 724 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 266 */
__attribute__((naked))
void Cmd_Give_f(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 266 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x44c, %esp\n"
        /* { scope 1: c, arg */
        "movl 8(%ebp), %eax\n" /* line 275 | ent */
        "movl %eax, (%esp)\n"
        "calll CheatsOk\n"
        "testl %eax, %eax\n"
        "jne .Lf1a4828_001a484e\n"
        /* } scope */
        ".Lf1a4828_001a4843:\n"
        "addl $0x44c, %esp\n" /* line 393 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: c, arg */
        /* { scope 2 */
        ".Lf1a4828_001a484e:\n"
        "calll SV_Cmd_Argc\n" /* line 106 */
        "movl %eax, -0x420(%ebp)\n" /* c */
        "cmpl $2, %eax\n" /* line 107 */
        "jg .Lf1a4828_001a4c1c\n"
        "xorl %edi, %edi\n" /* len */
        ".Lf1a4828_001a4864:\n"
        "movb $0, line(%edi)\n" /* line 124 | len */
        /* } scope */
        "movl $line, (%esp)\n" /* line 282 */
        "calll atoi\n"
        "movl %eax, -0x424(%ebp)\n" /* amount */
        /* { scope 2 */
        "calll SV_Cmd_Argc\n" /* line 106 */
        "movl %eax, %esi\n" /* len */
        "cmpl $1, %eax\n" /* line 107 */
        "jg .Lf1a4828_001a4b7b\n"
        "movl $0, -0x41c(%ebp)\n"
        "movl -0x41c(%ebp), %eax\n"
        ".Lf1a4828_001a489d:\n"
        "movb $0, line(%eax)\n" /* line 124 */
        /* } scope */
        "cmpb $0, line\n" /* line 287 */
        "je .Lf1a4828_001a4843\n"
        "movl $str_0022540c, 4(%esp)\n" /* line 290 */
        "movl $line, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a4828_001a49d3\n"
        "movl $1, %esi\n" /* give_all */
        ".Lf1a4828_001a48ce:\n"
        "movl -0x424(%ebp), %edi\n" /* line 298 | amount, i */
        "testl %edi, %edi\n" /* i */
        "je .Lf1a4828_001a4cb0\n"
        "movl -0x424(%ebp), %eax\n" /* line 299 | amount */
        "movl 8(%ebp), %edx\n" /* ent */
        "addl %eax, 0x194(%edx)\n"
        ".Lf1a4828_001a48eb:\n"
        "testl %esi, %esi\n" /* line 302 | give_all */
        "je .Lf1a4828_001a4843\n"
        /* { scope 2 */
        ".Lf1a4828_001a48f3:\n"
        "movl imp_level, %eax\n" /* line 310 */
        "movl $1, 0x1c(%eax)\n"
        "movl 8(%ebp), %edx\n" /* line 312 | ent */
        "movl 0x158(%edx), %eax\n"
        "movsbl 0x556(%eax), %ebx\n" /* maxCurrentWeapon */
        "movsbl 0x555(%eax), %edx\n" /* line 314 */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll BG_TakePlayerWeapon\n"
        "movl 8(%ebp), %eax\n" /* line 315 | ent */
        "movl 0x158(%eax), %edx\n"
        "movsbl 0x556(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll BG_TakePlayerWeapon\n"
        "movl $1, %edi\n" /* i */
        "calll BG_GetNumWeapons\n" /* line 318 */
        "cmpl %eax, %edi\n" /* i */
        "jg .Lf1a4828_001a4968\n"
        ".Lf1a4828_001a494c:\n"
        "movl %edi, (%esp)\n" /* line 320 | i */
        "calll BG_DoesWeaponRequireSlot\n"
        "testb %al, %al\n"
        "je .Lf1a4828_001a49b9\n"
        "cmpl %ebx, %edi\n" /* line 322 | maxCurrentWeapon, i */
        "jg .Lf1a4828_001a49a4\n"
        ".Lf1a4828_001a495c:\n"
        "addl $1, %edi\n" /* line 318 | i */
        ".Lf1a4828_001a495f:\n"
        "calll BG_GetNumWeapons\n"
        "cmpl %eax, %edi\n" /* i */
        "jle .Lf1a4828_001a494c\n"
        ".Lf1a4828_001a4968:\n"
        "movl $1, %edi\n" /* i */
        ".Lf1a4828_001a496d:\n"
        "movl 8(%ebp), %edx\n" /* line 334 | ent */
        "movl 0x158(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_IsAnyEmptyPrimaryWeaponSlot\n"
        "testb %al, %al\n"
        "je .Lf1a4828_001a4a1b\n"
        "calll BG_GetNumWeapons\n"
        "cmpl %eax, %edi\n" /* i */
        "jg .Lf1a4828_001a4a1b\n"
        "movl %edi, (%esp)\n" /* line 336 | i */
        "calll BG_DoesWeaponRequireSlot\n"
        "testb %al, %al\n"
        "jne .Lf1a4828_001a49fe\n"
        "addl $1, %edi\n" /* line 339 | i */
        "jmp .Lf1a4828_001a496d\n"
        ".Lf1a4828_001a49a4:\n"
        "movl 8(%ebp), %edx\n" /* line 322 | ent */
        "movl 0x158(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_IsAnyEmptyPrimaryWeaponSlot\n"
        "testb %al, %al\n"
        "je .Lf1a4828_001a495c\n"
        ".Lf1a4828_001a49b9:\n"
        "movl %edi, 4(%esp)\n" /* line 327 | i */
        "movl 8(%ebp), %edx\n" /* ent */
        "movl 0x158(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_GivePlayerWeapon\n"
        "addl $1, %edi\n" /* line 318 | i */
        "jmp .Lf1a4828_001a495f\n"
        /* } scope */
        ".Lf1a4828_001a49d3:\n"
        "movl $6, 8(%esp)\n" /* line 295 */
        "movl $str_002b33c4, 4(%esp)\n" /* "health" */
        "movl $line, (%esp)\n"
        "calll I_strnicmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a4828_001a4cf0\n"
        "xorl %esi, %esi\n" /* give_all */
        "jmp .Lf1a4828_001a48ce\n"
        /* { scope 2 */
        ".Lf1a4828_001a49fe:\n"
        "movl %edi, 4(%esp)\n" /* line 337 | i */
        "movl 8(%ebp), %edx\n" /* ent */
        "movl 0x158(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_GivePlayerWeapon\n"
        "addl $1, %edi\n" /* line 339 | i */
        "jmp .Lf1a4828_001a496d\n"
        ".Lf1a4828_001a4a1b:\n"
        "movl imp_level, %eax\n" /* line 342 */
        "movl $0, 0x1c(%eax)\n"
        "testl %esi, %esi\n" /* line 343 | give_all */
        "je .Lf1a4828_001a4843\n"
        /* } scope */
        ".Lf1a4828_001a4a2f:\n"
        "movl -0x424(%ebp), %ebx\n" /* line 348 | amount, maxCurrentWeapon */
        "testl %ebx, %ebx\n" /* maxCurrentWeapon */
        "je .Lf1a4828_001a4d0f\n"
        "movl 8(%ebp), %edx\n" /* line 350 | ent */
        "movl 0x158(%edx), %eax\n"
        "movl 0xd4(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1a4828_001a4cca\n"
        ".Lf1a4828_001a4a54:\n"
        "testl %esi, %esi\n" /* line 359 | give_all */
        "je .Lf1a4828_001a4843\n"
        ".Lf1a4828_001a4a5c:\n"
        "movl $7, 8(%esp)\n" /* line 365 */
        "movl $str_002b3bbc, 4(%esp)\n" /* "allammo" */
        "movl $line, (%esp)\n"
        "calll I_strnicmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a4828_001a4abf\n"
        "movl -0x424(%ebp), %ecx\n" /* amount */
        "testl %ecx, %ecx\n"
        "je .Lf1a4828_001a4abf\n"
        "movl $1, %ebx\n" /* maxCurrentWeapon */
        "jmp .Lf1a4828_001a4ab1\n"
        ".Lf1a4828_001a4a8d:\n"
        "movl $1, 0xc(%esp)\n" /* line 368 */
        "movl -0x424(%ebp), %eax\n" /* amount */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* maxCurrentWeapon */
        "movl 8(%ebp), %edx\n" /* ent */
        "movl %edx, (%esp)\n"
        "calll Add_Ammo\n"
        "addl $1, %ebx\n" /* line 367 | maxCurrentWeapon */
        ".Lf1a4828_001a4ab1:\n"
        "calll BG_GetNumWeapons\n"
        "cmpl %eax, %ebx\n" /* maxCurrentWeapon */
        "jle .Lf1a4828_001a4a8d\n"
        "jmp .Lf1a4828_001a4843\n"
        ".Lf1a4828_001a4abf:\n"
        "testl %esi, %esi\n" /* line 375 | give_all */
        "jne .Lf1a4828_001a4843\n"
        "movl $line, (%esp)\n" /* line 377 */
        "calll G_FindItem\n"
        "movl %eax, %esi\n" /* give_all */
        "testl %eax, %eax\n" /* line 378 */
        "je .Lf1a4828_001a4843\n"
        "movl imp_level, %edi\n" /* line 381 | i */
        "movl $1, 0x1c(%edi)\n" /* i */
        "calll G_Spawn\n" /* line 382 */
        "movl %eax, %ebx\n" /* maxCurrentWeapon */
        "leal 0x138(%eax), %ecx\n" /* line 383 | to */
        "movl 8(%ebp), %edx\n" /* ent, from */
        "addl $0x138, %edx\n" /* from */
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 199 | ent */
        "movss 0x138(%eax), %xmm0\n"
        "movss %xmm0, 0x138(%ebx)\n" /* i */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x168(%ebx), %eax\n" /* line 384 | maxCurrentWeapon */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* give_all */
        "calll G_GetItemClassname\n"
        "movl %esi, 4(%esp)\n" /* line 385 | give_all */
        "movl %ebx, (%esp)\n" /* maxCurrentWeapon */
        "calll G_SpawnItem\n"
        "movb $1, 0x162(%ebx)\n" /* line 386 | maxCurrentWeapon */
        "movl $1, 8(%esp)\n" /* line 387 */
        "movl 8(%ebp), %eax\n" /* ent */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* maxCurrentWeapon */
        "calll Touch_Item\n"
        "movb $0, 0x162(%ebx)\n" /* line 388 | maxCurrentWeapon */
        "cmpb $0, 0xfc(%ebx)\n" /* line 389 | maxCurrentWeapon */
        "jne .Lf1a4828_001a4d46\n"
        ".Lf1a4828_001a4b6f:\n"
        "movl $0, 0x1c(%edi)\n" /* line 391 | i */
        "jmp .Lf1a4828_001a4843\n"
        /* { scope 2 */
        ".Lf1a4828_001a4b7b:\n"
        "movl $1, %ebx\n" /* line 107 | i */
        "movl $0, -0x41c(%ebp)\n"
        "leal -1(%eax), %eax\n"
        "movl %eax, -0x42c(%ebp)\n"
        ".Lf1a4828_001a4b93:\n"
        "movl $0x400, 8(%esp)\n" /* line 109 */
        "leal -0x418(%ebp), %edx\n" /* arg */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* i */
        "calll SV_Cmd_ArgvBuffer\n"
        "cld\n" /* line 110 */
        "movl $0xffffffff, %ecx\n"
        "leal -0x418(%ebp), %edi\n" /* arg, len */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* len */
        "notl %ecx\n"
        "leal -1(%ecx), %edx\n"
        "movl -0x41c(%ebp), %eax\n" /* line 111 */
        "leal (%edx, %eax), %edi\n" /* len */
        "cmpl $0x3fe, %edi\n" /* len */
        "jg .Lf1a4828_001a489d\n"
        "addl $line, %eax\n" /* line 115 */
        "movl %edx, 8(%esp)\n"
        "leal -0x418(%ebp), %edx\n" /* arg */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "cmpl -0x42c(%ebp), %ebx\n" /* line 117 | i */
        "je .Lf1a4828_001a4c04\n"
        "movb $0x20, line(%edi)\n" /* line 119 | len */
        "addl $1, %edi\n" /* line 120 | len */
        ".Lf1a4828_001a4c04:\n"
        "movl %edi, -0x41c(%ebp)\n" /* len */
        "addl $1, %ebx\n" /* line 107 | i */
        "cmpl %ebx, %esi\n" /* i, len */
        "jne .Lf1a4828_001a4b93\n"
        "movl -0x41c(%ebp), %eax\n"
        "jmp .Lf1a4828_001a489d\n"
        ".Lf1a4828_001a4c1c:\n"
        "movl %eax, %edx\n"
        /* } scope */
        /* { scope 2 */
        "movl $2, %ebx\n" /* i */
        "xorl %esi, %esi\n" /* len */
        "subl $1, %edx\n"
        "movl %edx, -0x428(%ebp)\n"
        "jmp .Lf1a4828_001a4c6f\n"
        ".Lf1a4828_001a4c30:\n"
        "leal line(%esi), %eax\n" /* line 115 | len */
        "movl %edx, 8(%esp)\n"
        "leal -0x418(%ebp), %edx\n" /* arg */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "cmpl -0x428(%ebp), %ebx\n" /* line 117 | i */
        "je .Lf1a4828_001a4c5e\n"
        "movb $0x20, line(%edi)\n" /* line 119 | len */
        "addl $1, %edi\n" /* line 120 | len */
        ".Lf1a4828_001a4c5e:\n"
        "addl $1, %ebx\n" /* line 107 | i */
        "cmpl %ebx, -0x420(%ebp)\n" /* i, c */
        "je .Lf1a4828_001a4864\n"
        "movl %edi, %esi\n" /* len */
        ".Lf1a4828_001a4c6f:\n"
        "movl $0x400, 8(%esp)\n" /* line 109 */
        "leal -0x418(%ebp), %eax\n" /* arg */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* i */
        "calll SV_Cmd_ArgvBuffer\n"
        "cld\n" /* line 110 */
        "movl $0xffffffff, %ecx\n"
        "leal -0x418(%ebp), %edi\n" /* arg, len */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* len */
        "notl %ecx\n"
        "leal -1(%ecx), %edx\n"
        "leal (%edx, %esi), %edi\n" /* line 111 | len */
        "cmpl $0x3fe, %edi\n" /* len */
        "jle .Lf1a4828_001a4c30\n"
        "movl %esi, %edi\n" /* line 107 | len */
        "jmp .Lf1a4828_001a4864\n"
        /* } scope */
        ".Lf1a4828_001a4cb0:\n"
        "movl 8(%ebp), %edx\n" /* line 301 | ent */
        "movl 0x158(%edx), %eax\n"
        "movl 0x134(%eax), %eax\n"
        "movl %eax, 0x194(%edx)\n"
        "jmp .Lf1a4828_001a48eb\n"
        ".Lf1a4828_001a4cca:\n"
        "movl $1, 0xc(%esp)\n" /* line 351 */
        "movl -0x424(%ebp), %edx\n" /* amount */
        "movl %edx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll Add_Ammo\n"
        "jmp .Lf1a4828_001a4a54\n"
        ".Lf1a4828_001a4cf0:\n"
        "movl $str_002b3bac, 4(%esp)\n" /* line 306 */
        "movl $line, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a4828_001a4d53\n"
        "xorl %esi, %esi\n" /* give_all */
        "jmp .Lf1a4828_001a48f3\n"
        ".Lf1a4828_001a4d0f:\n"
        "movl $1, %ebx\n" /* line 348 | maxCurrentWeapon */
        "jmp .Lf1a4828_001a4d38\n"
        ".Lf1a4828_001a4d16:\n"
        "movl $1, 0xc(%esp)\n" /* line 356 */
        "movl $0x3e6, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* maxCurrentWeapon */
        "movl 8(%ebp), %edx\n" /* ent */
        "movl %edx, (%esp)\n"
        "calll Add_Ammo\n"
        "addl $1, %ebx\n" /* line 355 | maxCurrentWeapon */
        ".Lf1a4828_001a4d38:\n"
        "calll BG_GetNumWeapons\n"
        "cmpl %eax, %ebx\n" /* maxCurrentWeapon */
        "jle .Lf1a4828_001a4d16\n"
        "jmp .Lf1a4828_001a4a54\n"
        ".Lf1a4828_001a4d46:\n"
        "movl %ebx, (%esp)\n" /* line 390 | maxCurrentWeapon */
        "calll G_FreeEntity\n"
        "jmp .Lf1a4828_001a4b6f\n"
        ".Lf1a4828_001a4d53:\n"
        "movl $4, 8(%esp)\n" /* line 346 */
        "movl $str_002b3bb4, 4(%esp)\n" /* "ammo" */
        "movl $line, (%esp)\n"
        "calll I_strnicmp\n"
        "testl %eax, %eax\n"
        "je .Lf1a4828_001a4d7a\n"
        "xorl %esi, %esi\n" /* give_all */
        "jmp .Lf1a4828_001a4a5c\n"
        ".Lf1a4828_001a4d7a:\n"
        "xorl %esi, %esi\n" /* give_all */
        "jmp .Lf1a4828_001a4a2f\n"
    );
}

/* line 401 */
__attribute__((naked))
void Cmd_Take_f(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 401 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x44c, %esp\n"
        /* { scope 1: c, len, arg, c, ... */
        "movl 8(%ebp), %eax\n" /* line 408 | ent */
        "movl %eax, (%esp)\n"
        "calll CheatsOk\n"
        "testl %eax, %eax\n"
        "jne .Lf1a4d82_001a4da8\n"
        /* } scope */
        ".Lf1a4d82_001a4d9d:\n"
        "addl $0x44c, %esp\n" /* line 510 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: c, len, arg, c, ... */
        /* { scope 2 */
        ".Lf1a4d82_001a4da8:\n"
        "calll SV_Cmd_Argc\n" /* line 106 */
        "movl %eax, -0x42c(%ebp)\n" /* c */
        "cmpl $2, %eax\n" /* line 107 */
        "jg .Lf1a4d82_001a5153\n"
        "xorl %ebx, %ebx\n"
        ".Lf1a4d82_001a4dbe:\n"
        "movb $0, line(%ebx)\n" /* line 124 */
        /* } scope */
        "movl $line, (%esp)\n" /* line 412 */
        "calll atoi\n"
        "movl %eax, -0x430(%ebp)\n" /* amount */
        /* { scope 2 */
        "calll SV_Cmd_Argc\n" /* line 106 */
        "movl %eax, -0x424(%ebp)\n" /* c */
        "cmpl $1, %eax\n" /* line 107 */
        "jg .Lf1a4d82_001a50a2\n"
        "movl $0, -0x420(%ebp)\n" /* len */
        "movl -0x420(%ebp), %ecx\n" /* len */
        ".Lf1a4d82_001a4dfb:\n"
        "movb $0, line(%ecx)\n" /* line 124 */
        /* } scope */
        "cmpb $0, line\n" /* line 416 */
        "je .Lf1a4d82_001a4d9d\n"
        "movl $str_0022540c, 4(%esp)\n" /* line 419 */
        "movl $line, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a4d82_001a506f\n"
        "movl $1, -0x434(%ebp)\n" /* take_all */
        ".Lf1a4d82_001a4e31:\n"
        "movl -0x430(%ebp), %edi\n" /* line 427 | amount */
        "testl %edi, %edi\n"
        "je .Lf1a4d82_001a51fe\n"
        "movl 8(%ebp), %edx\n" /* line 429 | ent */
        "movl 0x194(%edx), %eax\n"
        "subl -0x430(%ebp), %eax\n" /* amount */
        "movl %eax, 0x194(%edx)\n"
        "testl %eax, %eax\n" /* line 430 */
        "jle .Lf1a4d82_001a53aa\n"
        ".Lf1a4d82_001a4e5c:\n"
        "movl -0x434(%ebp), %esi\n" /* line 435 | take_all, i */
        "testl %esi, %esi\n" /* i */
        "je .Lf1a4d82_001a4d9d\n"
        ".Lf1a4d82_001a4e6a:\n"
        "movl $1, %esi\n" /* line 439 | i */
        "jmp .Lf1a4d82_001a4ec1\n"
        ".Lf1a4d82_001a4e71:\n"
        "movl %esi, 4(%esp)\n" /* line 444 | i */
        "movl 8(%ebp), %edx\n" /* ent */
        "movl 0x158(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_TakePlayerWeapon\n"
        "movl 8(%ebp), %ecx\n" /* line 445 | ent */
        "movl 0x158(%ecx), %ebx\n"
        "movl %esi, (%esp)\n" /* i */
        "calll BG_AmmoForWeapon\n"
        "movl $0, 0x144(%ebx, %eax, 4)\n"
        "movl 8(%ebp), %eax\n" /* line 446 | ent */
        "movl 0x158(%eax), %ebx\n"
        "movl %esi, (%esp)\n" /* i */
        "calll BG_ClipForWeapon\n"
        "movl $0, 0x344(%ebx, %eax, 4)\n"
        "addl $1, %esi\n" /* line 442 | i */
        ".Lf1a4d82_001a4ec1:\n"
        "calll BG_GetNumWeapons\n"
        "cmpl %eax, %esi\n" /* i */
        "jle .Lf1a4d82_001a4e71\n"
        "movl 8(%ebp), %edx\n" /* line 450 | ent */
        "movl 0x158(%edx), %eax\n"
        "movl 0xd4(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lf1a4d82_001a532a\n"
        ".Lf1a4d82_001a4ee1:\n"
        "movl -0x434(%ebp), %ecx\n" /* line 456 | take_all */
        "testl %ecx, %ecx\n"
        "je .Lf1a4d82_001a4d9d\n"
        ".Lf1a4d82_001a4eef:\n"
        "movl -0x430(%ebp), %edx\n" /* line 462 | amount */
        "testl %edx, %edx\n"
        "je .Lf1a4d82_001a535a\n"
        "movl 8(%ebp), %ecx\n" /* line 464 | ent */
        "movl 0x158(%ecx), %eax\n"
        "movl 0xd4(%eax), %eax\n"
        "movl %eax, -0x438(%ebp)\n"
        "testl %eax, %eax\n"
        "jne .Lf1a4d82_001a5210\n"
        ".Lf1a4d82_001a4f1a:\n"
        "movl -0x434(%ebp), %eax\n" /* line 487 | take_all */
        "testl %eax, %eax\n"
        "je .Lf1a4d82_001a4d9d\n"
        ".Lf1a4d82_001a4f28:\n"
        "movl $7, 8(%esp)\n" /* line 493 */
        "movl $str_002b3bbc, 4(%esp)\n" /* "allammo" */
        "movl $line, (%esp)\n"
        "calll I_strnicmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a4d82_001a4d9d\n"
        "movl -0x430(%ebp), %eax\n" /* amount */
        "testl %eax, %eax\n"
        "je .Lf1a4d82_001a4d9d\n"
        "movl $1, -0x41c(%ebp)\n"
        "jmp .Lf1a4d82_001a4f6d\n"
        ".Lf1a4d82_001a4f66:\n"
        "addl $1, -0x41c(%ebp)\n" /* line 495 */
        ".Lf1a4d82_001a4f6d:\n"
        "calll BG_GetNumWeapons\n"
        "cmpl %eax, -0x41c(%ebp)\n"
        "jg .Lf1a4d82_001a4d9d\n"
        "movl -0x41c(%ebp), %edx\n" /* line 497 */
        "movl %edx, (%esp)\n"
        "calll BG_AmmoForWeapon\n"
        "movl 8(%ebp), %ecx\n" /* ent */
        "movl 0x158(%ecx), %edx\n"
        "movl -0x430(%ebp), %ecx\n" /* amount */
        "subl %ecx, 0x144(%edx, %eax, 4)\n"
        "movl 8(%ebp), %eax\n" /* line 498 | ent */
        "movl 0x158(%eax), %ebx\n"
        "movl -0x41c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll BG_AmmoForWeapon\n"
        "movl 0x144(%ebx, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "jns .Lf1a4d82_001a4f66\n"
        "movl -0x41c(%ebp), %ecx\n" /* line 500 */
        "movl %ecx, (%esp)\n"
        "calll BG_ClipForWeapon\n"
        "movl %eax, %edi\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "movl 0x158(%eax), %esi\n" /* i */
        "movl 0x344(%esi, %edi, 4), %ebx\n" /* i */
        "movl -0x41c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll BG_AmmoForWeapon\n"
        "addl 0x144(%esi, %eax, 4), %ebx\n" /* i */
        "movl %ebx, 0x344(%esi, %edi, 4)\n" /* i */
        "movl 8(%ebp), %ecx\n" /* line 501 | ent */
        "movl 0x158(%ecx), %ebx\n"
        "movl -0x41c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_AmmoForWeapon\n"
        "movl $0, 0x144(%ebx, %eax, 4)\n"
        "movl 8(%ebp), %edx\n" /* line 502 | ent */
        "movl 0x158(%edx), %ebx\n"
        "movl -0x41c(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll BG_ClipForWeapon\n"
        "movl 0x344(%ebx, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "jns .Lf1a4d82_001a4f66\n"
        "movl 8(%ebp), %eax\n" /* line 503 | ent */
        "movl 0x158(%eax), %ebx\n"
        "movl -0x41c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll BG_ClipForWeapon\n"
        "movl $0, 0x344(%ebx, %eax, 4)\n"
        "jmp .Lf1a4d82_001a4f66\n"
        ".Lf1a4d82_001a506f:\n"
        "movl $6, 8(%esp)\n" /* line 424 */
        "movl $str_002b33c4, 4(%esp)\n" /* "health" */
        "movl $line, (%esp)\n"
        "calll I_strnicmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a4d82_001a52ff\n"
        "movl $0, -0x434(%ebp)\n" /* take_all */
        "jmp .Lf1a4d82_001a4e31\n"
        ".Lf1a4d82_001a50a2:\n"
        "movl %eax, %ecx\n"
        /* { scope 2 */
        "movl $1, %esi\n" /* line 107 | i */
        "movl $0, -0x420(%ebp)\n" /* len */
        "subl $1, %ecx\n"
        "movl %ecx, -0x440(%ebp)\n"
        "jmp .Lf1a4d82_001a50c4\n"
        ".Lf1a4d82_001a50be:\n"
        "movl %ebx, -0x420(%ebp)\n" /* len */
        ".Lf1a4d82_001a50c4:\n"
        "movl $0x400, 8(%esp)\n" /* line 109 */
        "leal -0x418(%ebp), %eax\n" /* arg */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* i */
        "calll SV_Cmd_ArgvBuffer\n"
        "cld\n" /* line 110 */
        "movl $0xffffffff, %ecx\n"
        "leal -0x418(%ebp), %edi\n" /* arg */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %edx\n"
        "movl -0x420(%ebp), %ecx\n" /* line 111 | len */
        "leal (%edx, %ecx), %ebx\n"
        "cmpl $0x3fe, %ebx\n"
        "jg .Lf1a4d82_001a4dfb\n"
        "movl %ecx, %eax\n" /* line 115 */
        "addl $line, %eax\n"
        "movl %edx, 8(%esp)\n"
        "leal -0x418(%ebp), %edx\n" /* arg */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "cmpl -0x440(%ebp), %esi\n" /* line 117 | i */
        "je .Lf1a4d82_001a5137\n"
        "movb $0x20, line(%ebx)\n" /* line 119 */
        "addl $1, %ebx\n" /* line 120 */
        ".Lf1a4d82_001a5137:\n"
        "addl $1, %esi\n" /* line 107 | i */
        "cmpl %esi, -0x424(%ebp)\n" /* i, c */
        "jne .Lf1a4d82_001a50be\n"
        "movl %ebx, -0x420(%ebp)\n" /* len */
        "movl %ebx, %ecx\n"
        "jmp .Lf1a4d82_001a4dfb\n"
        ".Lf1a4d82_001a5153:\n"
        "movl %eax, %edx\n"
        /* } scope */
        /* { scope 2 */
        "movl $2, %esi\n" /* i */
        "movl $0, -0x428(%ebp)\n" /* len */
        "subl $1, %edx\n"
        "movl %edx, -0x43c(%ebp)\n"
        "jmp .Lf1a4d82_001a51b3\n"
        ".Lf1a4d82_001a516f:\n"
        "movl %ecx, %eax\n" /* line 115 */
        "addl $line, %eax\n"
        "movl %edx, 8(%esp)\n"
        "leal -0x418(%ebp), %edx\n" /* arg */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "cmpl -0x43c(%ebp), %esi\n" /* line 117 | i */
        "je .Lf1a4d82_001a519e\n"
        "movb $0x20, line(%ebx)\n" /* line 119 */
        "addl $1, %ebx\n" /* line 120 */
        ".Lf1a4d82_001a519e:\n"
        "addl $1, %esi\n" /* line 107 | i */
        "cmpl %esi, -0x42c(%ebp)\n" /* i, c */
        "je .Lf1a4d82_001a4dbe\n"
        "movl %ebx, -0x428(%ebp)\n" /* len */
        ".Lf1a4d82_001a51b3:\n"
        "movl $0x400, 8(%esp)\n" /* line 109 */
        "leal -0x418(%ebp), %ecx\n" /* arg */
        "movl %ecx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* i */
        "calll SV_Cmd_ArgvBuffer\n"
        "cld\n" /* line 110 */
        "movl $0xffffffff, %ecx\n"
        "leal -0x418(%ebp), %edi\n" /* arg */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %edx\n"
        "movl -0x428(%ebp), %ecx\n" /* line 111 | len */
        "leal (%edx, %ecx), %ebx\n"
        "cmpl $0x3fe, %ebx\n"
        "jle .Lf1a4d82_001a516f\n"
        "movl %ecx, %ebx\n"
        "jmp .Lf1a4d82_001a4dbe\n"
        /* } scope */
        ".Lf1a4d82_001a51fe:\n"
        "movl 8(%ebp), %ecx\n" /* line 434 | ent */
        "movl $1, 0x194(%ecx)\n"
        "jmp .Lf1a4d82_001a4e5c\n"
        ".Lf1a4d82_001a5210:\n"
        "movl %eax, (%esp)\n" /* line 468 */
        "calll BG_AmmoForWeapon\n"
        "movl 8(%ebp), %ecx\n" /* ent */
        "movl 0x158(%ecx), %edx\n"
        "movl -0x430(%ebp), %ecx\n" /* amount */
        "subl %ecx, 0x144(%edx, %eax, 4)\n"
        "movl 8(%ebp), %eax\n" /* line 469 | ent */
        "movl 0x158(%eax), %ebx\n"
        "movl -0x438(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll BG_AmmoForWeapon\n"
        "movl 0x144(%ebx, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "jns .Lf1a4d82_001a4f1a\n"
        "movl -0x438(%ebp), %ecx\n" /* line 471 */
        "movl %ecx, (%esp)\n"
        "calll BG_ClipForWeapon\n"
        "movl %eax, %edi\n"
        "movl 8(%ebp), %eax\n" /* ent */
        "movl 0x158(%eax), %esi\n" /* i */
        "movl 0x344(%esi, %edi, 4), %ebx\n" /* i */
        "movl -0x438(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll BG_AmmoForWeapon\n"
        "addl 0x144(%esi, %eax, 4), %ebx\n" /* i */
        "movl %ebx, 0x344(%esi, %edi, 4)\n" /* i */
        "movl 8(%ebp), %ecx\n" /* line 472 | ent */
        "movl 0x158(%ecx), %ebx\n"
        "movl -0x438(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_AmmoForWeapon\n"
        "movl $0, 0x144(%ebx, %eax, 4)\n"
        "movl 8(%ebp), %edx\n" /* line 473 | ent */
        "movl 0x158(%edx), %ebx\n"
        "movl -0x438(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll BG_ClipForWeapon\n"
        "movl 0x344(%ebx, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "jns .Lf1a4d82_001a4f1a\n"
        "movl 8(%ebp), %eax\n" /* line 474 | ent */
        "movl 0x158(%eax), %ebx\n"
        "movl -0x438(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll BG_ClipForWeapon\n"
        "movl $0, 0x344(%ebx, %eax, 4)\n"
        "jmp .Lf1a4d82_001a4f1a\n"
        ".Lf1a4d82_001a52ff:\n"
        "movl $str_002b3bac, 4(%esp)\n" /* line 439 */
        "movl $line, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a4d82_001a53b9\n"
        "movl $0, -0x434(%ebp)\n" /* take_all */
        "jmp .Lf1a4d82_001a4e6a\n"
        ".Lf1a4d82_001a532a:\n"
        "movl $0, 0xd4(%eax)\n" /* line 452 */
        "movl $0, 4(%esp)\n" /* line 453 */
        "movl %edx, %eax\n"
        "subl imp_g_entities, %eax\n"
        "sarl $4, %eax\n"
        "imull $0x8af8af8b, %eax, %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_SelectWeaponIndex\n"
        "jmp .Lf1a4d82_001a4ee1\n"
        ".Lf1a4d82_001a535a:\n"
        "movl $1, %esi\n" /* line 462 | i */
        "jmp .Lf1a4d82_001a539c\n"
        ".Lf1a4d82_001a5361:\n"
        "movl 8(%ebp), %ecx\n" /* line 482 | ent */
        "movl 0x158(%ecx), %ebx\n"
        "movl %esi, (%esp)\n" /* i */
        "calll BG_AmmoForWeapon\n"
        "movl $0, 0x144(%ebx, %eax, 4)\n"
        "movl 8(%ebp), %eax\n" /* line 483 | ent */
        "movl 0x158(%eax), %ebx\n"
        "movl %esi, (%esp)\n" /* i */
        "calll BG_ClipForWeapon\n"
        "movl $0, 0x344(%ebx, %eax, 4)\n"
        "addl $1, %esi\n" /* line 480 | i */
        ".Lf1a4d82_001a539c:\n"
        "calll BG_GetNumWeapons\n"
        "cmpl %eax, %esi\n" /* i */
        "jle .Lf1a4d82_001a5361\n"
        "jmp .Lf1a4d82_001a4f1a\n"
        ".Lf1a4d82_001a53aa:\n"
        "movl $1, 0x194(%edx)\n" /* line 431 */
        "jmp .Lf1a4d82_001a4e5c\n"
        ".Lf1a4d82_001a53b9:\n"
        "movl $4, 8(%esp)\n" /* line 460 */
        "movl $str_002b3bb4, 4(%esp)\n" /* "ammo" */
        "movl $line, (%esp)\n"
        "calll I_strnicmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a4d82_001a4f28\n"
        "movl $0, -0x434(%ebp)\n" /* take_all */
        "jmp .Lf1a4d82_001a4eef\n"
    );
}

/* line 1468 */
__attribute__((naked))
void ClientCommand(int clientNum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1468 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x336c, %esp\n"
        "movl 8(%ebp), %esi\n" /* clientNum */
        /* { scope 1: c, len, arg, target, ... */
        "leal (%esi, %esi, 4), %edx\n" /* line 1473 | clientNum */
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "shll $4, %eax\n"
        "movl imp_g_entities, %edi\n"
        "addl %edi, %eax\n"
        "movl %eax, -0x3330(%ebp)\n" /* ent */
        "movl 0x158(%eax), %eax\n" /* line 1474 */
        "testl %eax, %eax\n"
        "je .Lf1a53ec_001a54b3\n"
        "movl $0x400, 8(%esp)\n" /* line 1479 */
        "leal -0xc58(%ebp), %ebx\n" /* cmd, len */
        "movl %ebx, 4(%esp)\n" /* len */
        "movl $0, (%esp)\n"
        "calll SV_Cmd_ArgvBuffer\n"
        "movl $str_002ac704, 4(%esp)\n" /* line 1481 */
        "movl %ebx, (%esp)\n" /* len */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a53ec_001a54be\n"
        "calll SV_Cmd_Argc\n" /* line 943 */
        "subl $1, %eax\n"
        "jle .Lf1a53ec_001a54b3\n"
        /* { scope 2: c, arg */
        "calll SV_Cmd_Argc\n" /* line 106 */
        "movl %eax, -0x332c(%ebp)\n" /* c */
        "cmpl $1, %eax\n" /* line 107 */
        "jg .Lf1a53ec_001a575f\n"
        "movl $0, -0x3328(%ebp)\n" /* len */
        ".Lf1a53ec_001a5480:\n"
        "movl -0x3328(%ebp), %ecx\n" /* line 124 | len */
        "movb $0, line(%ecx)\n"
        /* } scope */
        "movl $line, 0xc(%esp)\n" /* line 957 */
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl -0x3330(%ebp), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll G_Say\n"
        /* } scope */
        ".Lf1a53ec_001a54b3:\n"
        "addl $0x336c, %esp\n" /* line 1549 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: c, len, arg, target, ... */
        ".Lf1a53ec_001a54be:\n"
        "movl $str_002b3bc4, 4(%esp)\n" /* line 1486 */
        "movl %ebx, (%esp)\n" /* len */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1a53ec_001a569c\n"
        "movl $str_002ac708, 4(%esp)\n" /* line 1493 */
        "movl %ebx, (%esp)\n" /* len */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a53ec_001a5706\n"
        /* { scope 2: c, arg */
        "calll SV_Cmd_Argc\n" /* line 975 */
        "subl $1, %eax\n"
        "jle .Lf1a53ec_001a54b3\n"
        "movl $0x400, 8(%esp)\n" /* line 980 */
        "leal -0x858(%ebp), %ebx\n" /* arg, len */
        "movl %ebx, 4(%esp)\n" /* len */
        "movl $1, (%esp)\n"
        "calll SV_Cmd_ArgvBuffer\n"
        "movl %ebx, (%esp)\n" /* line 981 | len */
        "calll atoi\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 982 */
        "js .Lf1a53ec_001a54b3\n"
        "movl imp_level, %eax\n"
        "cmpl 0x1e4(%eax), %edx\n"
        "jge .Lf1a53ec_001a54b3\n"
        "leal (%edx, %edx, 4), %edx\n" /* line 987 */
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl %edi, %eax\n" /* line 988 */
        "movl %eax, -0x3314(%ebp)\n" /* target */
        "je .Lf1a53ec_001a54b3\n"
        "cmpb $0, 0xfc(%eax)\n"
        "je .Lf1a53ec_001a54b3\n"
        "movl 0x158(%eax), %edi\n"
        "testl %edi, %edi\n"
        "je .Lf1a53ec_001a54b3\n"
        /* { scope 3 */
        "calll SV_Cmd_Argc\n" /* line 106 */
        "movl %eax, -0x3310(%ebp)\n" /* c */
        "cmpl $2, %eax\n" /* line 107 */
        "jg .Lf1a53ec_001a5916\n"
        "xorl %ebx, %ebx\n" /* len */
        ".Lf1a53ec_001a557f:\n"
        "movb $0, line(%ebx)\n" /* line 124 | len */
        /* } scope */
        "movl $0x40, 8(%esp)\n" /* line 995 */
        "movl -0x3330(%ebp), %ecx\n" /* ent */
        "movl 0x158(%ecx), %eax\n"
        "addl $0x2784, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %edi\n" /* cleanname */
        "movl %edi, (%esp)\n"
        "calll I_strncpyz\n"
        "movl %edi, (%esp)\n" /* line 996 */
        "calll I_CleanStr\n"
        "movl $0x40, 8(%esp)\n" /* line 998 */
        "movl -0x3314(%ebp), %edx\n" /* target */
        "movl 0x158(%edx), %eax\n"
        "addl $0x2784, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x458(%ebp), %ebx\n" /* arg, len */
        "movl %ebx, (%esp)\n" /* len */
        "calll I_strncpyz\n"
        "movl %ebx, (%esp)\n" /* line 999 | len */
        "calll I_CleanStr\n"
        "movl -0x3314(%ebp), %ecx\n" /* line 1001 | target */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x331c(%ebp)\n"
        "movl %ecx, (%esp)\n"
        "calll SV_GetGuid\n"
        "movl %eax, -0x3318(%ebp)\n"
        "movl -0x3330(%ebp), %eax\n" /* ent */
        "movl (%eax), %esi\n" /* clientnum */
        "movl %esi, (%esp)\n" /* clientnum */
        "calll SV_GetGuid\n"
        "movl $line, 0x1c(%esp)\n"
        "movl %ebx, 0x18(%esp)\n" /* len */
        "movl -0x331c(%ebp), %edx\n"
        "movl %edx, 0x14(%esp)\n"
        "movl -0x3318(%ebp), %ecx\n"
        "movl %ecx, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* clientnum */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b3bd0, (%esp)\n" /* "tell;%d;%d;%s;%d;%d;%s;%s
" */
        "calll G_LogPrintf\n"
        "movl $line, 0xc(%esp)\n" /* line 1002 */
        "movl $2, 8(%esp)\n"
        "movl -0x3314(%ebp), %eax\n" /* target */
        "movl %eax, 4(%esp)\n"
        "movl -0x3330(%ebp), %edx\n" /* ent */
        "movl %edx, (%esp)\n"
        "calll G_Say\n"
        "movl $line, 0xc(%esp)\n" /* line 1003 */
        "movl $2, 8(%esp)\n"
        "movl -0x3330(%ebp), %ecx\n" /* ent */
        "movl %ecx, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll G_Say\n"
        "jmp .Lf1a53ec_001a54b3\n"
        /* } scope */
        ".Lf1a53ec_001a569c:\n"
        "calll SV_Cmd_Argc\n" /* line 943 */
        "subl $1, %eax\n"
        "jle .Lf1a53ec_001a54b3\n"
        /* { scope 2: c, arg */
        "calll SV_Cmd_Argc\n" /* line 106 */
        "movl %eax, -0x3324(%ebp)\n" /* c */
        "cmpl $1, %eax\n" /* line 107 */
        "jg .Lf1a53ec_001a5807\n"
        "movl $0, -0x3320(%ebp)\n" /* len */
        ".Lf1a53ec_001a56c8:\n"
        "movl -0x3320(%ebp), %ecx\n" /* line 124 | len */
        "movb $0, line(%ecx)\n"
        /* } scope */
        "movl $line, 0xc(%esp)\n" /* line 957 */
        "movl $1, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl -0x3330(%ebp), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll G_Say\n"
        /* } scope */
        "addl $0x336c, %esp\n" /* line 1549 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: c, len, arg, target, ... */
        ".Lf1a53ec_001a5706:\n"
        "movl $str_002b3bec, 4(%esp)\n" /* line 1498 */
        "movl %ebx, (%esp)\n" /* len */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1a53ec_001a58b1\n"
        "movl -0x3330(%ebp), %edx\n" /* line 1505 | ent */
        "movl 0x158(%edx), %eax\n"
        "cmpl $5, 4(%eax)\n"
        "je .Lf1a53ec_001a54b3\n"
        "movl $str_002b3bf4, 4(%esp)\n" /* line 1511 */
        "movl %ebx, (%esp)\n" /* len */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a53ec_001a58c4\n"
        "movl -0x3330(%ebp), %ecx\n" /* line 1512 | ent */
        "movl %ecx, (%esp)\n"
        "calll Cmd_MenuResponse_f\n"
        "jmp .Lf1a53ec_001a54b3\n"
        ".Lf1a53ec_001a575f:\n"
        "movl $1, %esi\n" /* line 943 | clientnum */
        "movl $0, -0x3328(%ebp)\n" /* len */
        "subl $1, %eax\n"
        "movl %eax, -0x3334(%ebp)\n"
        /* { scope 2: c, arg */
        ".Lf1a53ec_001a5777:\n"
        "movl $0x400, 8(%esp)\n" /* line 109 */
        "leal -0x458(%ebp), %edx\n" /* arg */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* i */
        "calll SV_Cmd_ArgvBuffer\n"
        "cld\n" /* line 110 */
        "movl $0xffffffff, %ecx\n"
        "leal -0x458(%ebp), %edi\n" /* arg */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %edx\n"
        "movl -0x3328(%ebp), %ebx\n" /* line 111 | len */
        "addl %edx, %ebx\n" /* len */
        "cmpl $0x3fe, %ebx\n" /* len */
        "jg .Lf1a53ec_001a5480\n"
        "movl -0x3328(%ebp), %eax\n" /* line 115 | len */
        "addl $line, %eax\n"
        "movl %edx, 8(%esp)\n"
        "leal -0x458(%ebp), %edx\n" /* arg */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "cmpl -0x3334(%ebp), %esi\n" /* line 117 | i */
        "je .Lf1a53ec_001a57ed\n"
        "movb $0x20, line(%ebx)\n" /* line 119 | len */
        "addl $1, %ebx\n" /* line 120 | len */
        ".Lf1a53ec_001a57ed:\n"
        "movl %ebx, -0x3328(%ebp)\n" /* len */
        "addl $1, %esi\n" /* line 107 | i */
        "cmpl %esi, -0x332c(%ebp)\n" /* i, c */
        "jne .Lf1a53ec_001a5777\n"
        "jmp .Lf1a53ec_001a5480\n"
        ".Lf1a53ec_001a5807:\n"
        "movl %eax, %edx\n"
        /* } scope */
        "movl $1, %esi\n" /* line 943 | clientnum */
        "movl $0, -0x3320(%ebp)\n" /* len */
        "subl $1, %edx\n"
        "movl %edx, -0x3338(%ebp)\n"
        /* { scope 2: c, arg */
        ".Lf1a53ec_001a5821:\n"
        "movl $0x400, 8(%esp)\n" /* line 109 */
        "leal -0x3300(%ebp), %ecx\n" /* arg */
        "movl %ecx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* i */
        "calll SV_Cmd_ArgvBuffer\n"
        "cld\n" /* line 110 */
        "movl $0xffffffff, %ecx\n"
        "leal -0x3300(%ebp), %edi\n" /* arg */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %edx\n"
        "movl -0x3320(%ebp), %ebx\n" /* line 111 | len */
        "addl %edx, %ebx\n" /* len */
        "cmpl $0x3fe, %ebx\n" /* len */
        "jg .Lf1a53ec_001a56c8\n"
        "movl -0x3320(%ebp), %eax\n" /* line 115 | len */
        "addl $line, %eax\n"
        "movl %edx, 8(%esp)\n"
        "leal -0x3300(%ebp), %edx\n" /* arg */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "cmpl -0x3338(%ebp), %esi\n" /* line 117 | i */
        "je .Lf1a53ec_001a5897\n"
        "movb $0x20, line(%ebx)\n" /* line 119 | len */
        "addl $1, %ebx\n" /* line 120 | len */
        ".Lf1a53ec_001a5897:\n"
        "movl %ebx, -0x3320(%ebp)\n" /* len */
        "addl $1, %esi\n" /* line 107 | i */
        "cmpl %esi, -0x3324(%ebp)\n" /* i, c */
        "jne .Lf1a53ec_001a5821\n"
        "jmp .Lf1a53ec_001a56c8\n"
        /* } scope */
        ".Lf1a53ec_001a58b1:\n"
        "movl -0x3330(%ebp), %eax\n" /* line 68 | ent */
        "movl %eax, (%esp)\n"
        "calll DeathmatchScoreboardMessage\n"
        "jmp .Lf1a53ec_001a54b3\n"
        ".Lf1a53ec_001a58c4:\n"
        "movl $str_002b3bf8, 4(%esp)\n" /* line 1513 */
        "movl %ebx, (%esp)\n" /* len */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a53ec_001a58eb\n"
        "movl -0x3330(%ebp), %eax\n" /* line 1514 | ent */
        "movl %eax, (%esp)\n"
        "calll Cmd_Give_f\n"
        "jmp .Lf1a53ec_001a54b3\n"
        ".Lf1a53ec_001a58eb:\n"
        "movl $str_002b3c00, 4(%esp)\n" /* line 1515 */
        "movl %ebx, (%esp)\n" /* len */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a53ec_001a59c1\n"
        "movl -0x3330(%ebp), %edx\n" /* line 1516 | ent */
        "movl %edx, (%esp)\n"
        "calll Cmd_Take_f\n"
        "jmp .Lf1a53ec_001a54b3\n"
        ".Lf1a53ec_001a5916:\n"
        "movl %eax, %edx\n"
        /* { scope 2: c, arg */
        /* { scope 3 */
        "movl $2, %esi\n" /* line 107 | i */
        "movl $0, -0x330c(%ebp)\n"
        "subl $1, %edx\n"
        "movl %edx, -0x333c(%ebp)\n"
        "jmp .Lf1a53ec_001a5976\n"
        ".Lf1a53ec_001a5932:\n"
        "movl %ecx, %eax\n" /* line 115 */
        "addl $line, %eax\n"
        "movl %edx, 8(%esp)\n"
        "leal -0x3300(%ebp), %edx\n" /* arg */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "cmpl -0x333c(%ebp), %esi\n" /* line 117 | i */
        "je .Lf1a53ec_001a5961\n"
        "movb $0x20, line(%ebx)\n" /* line 119 | len */
        "addl $1, %ebx\n" /* line 120 | len */
        ".Lf1a53ec_001a5961:\n"
        "addl $1, %esi\n" /* line 107 | i */
        "cmpl %esi, -0x3310(%ebp)\n" /* i, c */
        "je .Lf1a53ec_001a557f\n"
        "movl %ebx, -0x330c(%ebp)\n" /* len */
        ".Lf1a53ec_001a5976:\n"
        "movl $0x400, 8(%esp)\n" /* line 109 */
        "leal -0x3300(%ebp), %ecx\n" /* arg */
        "movl %ecx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* i */
        "calll SV_Cmd_ArgvBuffer\n"
        "cld\n" /* line 110 */
        "movl $0xffffffff, %ecx\n"
        "leal -0x3300(%ebp), %edi\n" /* arg */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %edx\n"
        "movl -0x330c(%ebp), %ecx\n" /* line 111 */
        "leal (%edx, %ecx), %ebx\n" /* len */
        "cmpl $0x3fe, %ebx\n" /* len */
        "jle .Lf1a53ec_001a5932\n"
        "movl %ecx, %ebx\n" /* len */
        "jmp .Lf1a53ec_001a557f\n"
        /* } scope */
        /* } scope */
        ".Lf1a53ec_001a59c1:\n"
        "movl $str_002b3c08, 4(%esp)\n" /* line 1517 */
        "movl %ebx, (%esp)\n" /* len */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a53ec_001a5a5c\n"
        "movl -0x3330(%ebp), %ecx\n" /* line 526 | ent */
        "movl %ecx, (%esp)\n"
        "calll CheatsOk\n"
        "testl %eax, %eax\n"
        "je .Lf1a53ec_001a54b3\n"
        "movl -0x3330(%ebp), %eax\n" /* line 529 | ent */
        "movl 0x174(%eax), %edx\n"
        "xorl $1, %edx\n"
        "movl %edx, 0x174(%eax)\n"
        "movl $str_002b3674, %eax\n" /* line 531 */
        "andb $1, %dl\n"
        "movl $str_002b3684, %edx\n" /* "GAME_GODMODE_OFF" */
        ".Lf1a53ec_001a5a11:\n"
        "cmovel %edx, %eax\n" /* line 546 */
        ".Lf1a53ec_001a5a14:\n"
        "movl %eax, 8(%esp)\n" /* line 548 */
        "movl $0x65, 4(%esp)\n"
        "movl $str_002a737c, (%esp)\n" /* "%c "%s"" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "subl %edi, -0x3330(%ebp)\n" /* ent */
        "sarl $4, -0x3330(%ebp)\n" /* ent */
        "imull $0x8af8af8b, -0x3330(%ebp), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        "jmp .Lf1a53ec_001a54b3\n"
        ".Lf1a53ec_001a5a5c:\n"
        "movl $str_002b3c0c, 4(%esp)\n" /* line 1519 */
        "movl %ebx, (%esp)\n" /* len */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a53ec_001a5aad\n"
        "movl -0x3330(%ebp), %edx\n" /* line 541 | ent */
        "movl %edx, (%esp)\n"
        "calll CheatsOk\n"
        "testl %eax, %eax\n"
        "je .Lf1a53ec_001a54b3\n"
        "movl -0x3330(%ebp), %ecx\n" /* line 544 | ent */
        "movl 0x174(%ecx), %edx\n"
        "xorl $2, %edx\n"
        "movl %edx, 0x174(%ecx)\n"
        "movl $str_002b3698, %eax\n" /* line 546 */
        "andb $2, %dl\n"
        "movl $str_002b36b0, %edx\n" /* "GAME_DEMI_GODMODE_OFF" */
        "jmp .Lf1a53ec_001a5a11\n"
        ".Lf1a53ec_001a5aad:\n"
        "movl $str_002b3c14, 4(%esp)\n" /* line 1521 */
        "movl %ebx, (%esp)\n" /* len */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a53ec_001a5b01\n"
        "movl -0x3330(%ebp), %eax\n" /* line 565 | ent */
        "movl %eax, (%esp)\n"
        "calll CheatsOk\n"
        "testl %eax, %eax\n"
        "je .Lf1a53ec_001a54b3\n"
        "movl -0x3330(%ebp), %ecx\n" /* line 570 | ent */
        "movl 0x174(%ecx), %edx\n"
        "xorl $4, %edx\n"
        "movl %edx, 0x174(%ecx)\n"
        "movl $str_002b36c8, %eax\n" /* line 571 */
        "andb $4, %dl\n"
        "movl $str_002b36dc, %edx\n" /* "GAME_NOTARGETON" */
        "cmovnel %edx, %eax\n"
        "jmp .Lf1a53ec_001a5a14\n"
        ".Lf1a53ec_001a5b01:\n"
        "movl $str_002b3c20, 4(%esp)\n" /* line 1523 */
        "movl %ebx, (%esp)\n" /* len */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a53ec_001a5baa\n"
        "movl -0x3330(%ebp), %eax\n" /* line 591 | ent */
        "movl %eax, (%esp)\n"
        "calll CheatsOk\n"
        "testl %eax, %eax\n"
        "je .Lf1a53ec_001a54b3\n"
        "movl -0x3330(%ebp), %edx\n" /* line 596 | ent */
        "movl 0x158(%edx), %ebx\n" /* len */
        "movl 0x27ac(%ebx), %ecx\n" /* len */
        "movl $str_002b36ec, %edx\n" /* "GAME_NOCLIPOFF" */
        "testl %ecx, %ecx\n"
        "movl $str_002b36fc, %eax\n" /* "GAME_NOCLIPON" */
        "cmovel %eax, %edx\n"
        "sete %al\n" /* line 604 */
        "movzbl %al, %eax\n"
        "movl %eax, 0x27ac(%ebx)\n" /* len */
        ".Lf1a53ec_001a5b5c:\n"
        "movl %edx, 8(%esp)\n" /* line 636 */
        "movl $0x65, 4(%esp)\n"
        "movl $str_002a737c, (%esp)\n" /* "%c "%s"" */
        ".Lf1a53ec_001a5b6f:\n"
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl imp_g_entities, %ecx\n"
        "subl %ecx, -0x3330(%ebp)\n" /* ent */
        "sarl $4, -0x3330(%ebp)\n" /* ent */
        "imull $0x8af8af8b, -0x3330(%ebp), %eax\n" /* ent */
        "movl %eax, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        "jmp .Lf1a53ec_001a54b3\n"
        ".Lf1a53ec_001a5baa:\n"
        "movl $str_002b3c28, 4(%esp)\n" /* line 1525 */
        "movl %ebx, (%esp)\n" /* len */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a53ec_001a5c06\n"
        "movl -0x3330(%ebp), %eax\n" /* line 621 | ent */
        "movl %eax, (%esp)\n"
        "calll CheatsOk\n"
        "testl %eax, %eax\n"
        "je .Lf1a53ec_001a54b3\n"
        "movl -0x3330(%ebp), %edx\n" /* line 626 | ent */
        "movl 0x158(%edx), %ebx\n" /* len */
        "movl 0x27b0(%ebx), %ecx\n" /* len */
        "movl $str_002b370c, %edx\n" /* "GAME_UFOOFF" */
        "testl %ecx, %ecx\n"
        "movl $str_002b3718, %eax\n" /* "GAME_UFOON" */
        "cmovel %eax, %edx\n"
        "sete %al\n" /* line 634 */
        "movzbl %al, %eax\n"
        "movl %eax, 0x27b0(%ebx)\n" /* len */
        "jmp .Lf1a53ec_001a5b5c\n"
        ".Lf1a53ec_001a5c06:\n"
        "movl $str_002b3c2c, 4(%esp)\n" /* line 1527 */
        "movl %ebx, (%esp)\n" /* len */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a53ec_001a5c94\n"
        "movl -0x3330(%ebp), %edx\n" /* line 650 | ent */
        "movl 0x158(%edx), %eax\n"
        "movl 0x26a8(%eax), %esi\n" /* i */
        "testl %esi, %esi\n" /* i */
        "jne .Lf1a53ec_001a54b3\n"
        "andl $0xfffffffc, 0x174(%edx)\n" /* line 653 */
        "movl $0, 0x194(%edx)\n" /* line 654 */
        "movl $0, 0x12c(%eax)\n"
        "movl $0, 0x20(%esp)\n" /* line 655 */
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0xc, 0x10(%esp)\n"
        "movl $0x186a0, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll player_die\n"
        "jmp .Lf1a53ec_001a54b3\n"
        ".Lf1a53ec_001a5c94:\n"
        "movl $str_002b3c34, 4(%esp)\n" /* line 1529 */
        "movl %ebx, (%esp)\n" /* len */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a53ec_001a5d3d\n"
        /* { scope 2: c, arg */
        "movl -0x3330(%ebp), %ecx\n" /* line 747 | ent */
        "movl 0x158(%ecx), %edx\n"
        "cmpl $2, 0x26a8(%edx)\n"
        "jne .Lf1a53ec_001a54b3\n"
        "movl 0x26ac(%edx), %ebx\n" /* line 750 | len */
        "testl %ebx, %ebx\n" /* len */
        "jns .Lf1a53ec_001a54b3\n"
        "movl 0x27a8(%edx), %esi\n" /* line 753 | clientnum */
        "testl %esi, %esi\n" /* line 754 | clientnum */
        "movl %eax, %ebx\n" /* len */
        "cmovnsl %esi, %ebx\n" /* clientnum, len */
        "movl %ebx, %esi\n" /* len, clientnum */
        "movl imp_level, %edi\n"
        ".Lf1a53ec_001a5ce8:\n"
        "addl $1, %ebx\n" /* line 759 | len */
        "movl 0x1e4(%edi), %eax\n" /* line 760 */
        "cmpl %eax, %ebx\n" /* len */
        "jl .Lf1a53ec_001a5e2f\n"
        "xorl %ebx, %ebx\n" /* len */
        ".Lf1a53ec_001a5cfb:\n"
        "leal -0x458(%ebp), %eax\n" /* line 770 | arg */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x3300(%ebp), %edx\n" /* arg */
        "movl %edx, 8(%esp)\n"
        "movl -0x3330(%ebp), %ecx\n" /* ent */
        "movl 0x158(%ecx), %eax\n"
        "addl $0x26b4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* len */
        "calll SV_GetArchivedClientInfo\n"
        "testl %eax, %eax\n"
        "jne .Lf1a53ec_001a5de2\n"
        ".Lf1a53ec_001a5d34:\n"
        "cmpl %ebx, %esi\n" /* line 757 | len, clientnum */
        "jne .Lf1a53ec_001a5ce8\n"
        "jmp .Lf1a53ec_001a54b3\n"
        /* } scope */
        ".Lf1a53ec_001a5d3d:\n"
        "movl $str_002b3c40, 4(%esp)\n" /* line 1531 */
        "movl %ebx, (%esp)\n" /* len */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a53ec_001a5e98\n"
        /* { scope 2: c, arg */
        "movl -0x3330(%ebp), %ecx\n" /* line 747 | ent */
        "movl 0x158(%ecx), %edx\n"
        "cmpl $2, 0x26a8(%edx)\n"
        "jne .Lf1a53ec_001a54b3\n"
        "movl 0x26ac(%edx), %ecx\n" /* line 750 */
        "testl %ecx, %ecx\n"
        "jns .Lf1a53ec_001a54b3\n"
        "movl 0x27a8(%edx), %esi\n" /* line 753 | clientnum */
        "testl %esi, %esi\n" /* line 754 | clientnum */
        "movl %eax, %ebx\n" /* len */
        "cmovnsl %esi, %ebx\n" /* clientnum, len */
        "movl %ebx, %esi\n" /* len, clientnum */
        "movl imp_level, %edi\n"
        ".Lf1a53ec_001a5d91:\n"
        "subl $1, %ebx\n" /* line 759 | len */
        "movl 0x1e4(%edi), %eax\n" /* line 760 */
        "cmpl %eax, %ebx\n" /* len */
        "jl .Lf1a53ec_001a5e8a\n"
        "xorl %ebx, %ebx\n" /* len */
        ".Lf1a53ec_001a5da4:\n"
        "leal -0x458(%ebp), %eax\n" /* line 770 | arg */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x3300(%ebp), %edx\n" /* arg */
        "movl %edx, 8(%esp)\n"
        "movl -0x3330(%ebp), %ecx\n" /* ent */
        "movl 0x158(%ecx), %eax\n"
        "addl $0x26b4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* len */
        "calll SV_GetArchivedClientInfo\n"
        "testl %eax, %eax\n"
        "jne .Lf1a53ec_001a5e3d\n"
        ".Lf1a53ec_001a5dd9:\n"
        "cmpl %ebx, %esi\n" /* line 757 | len, clientnum */
        "jne .Lf1a53ec_001a5d91\n"
        "jmp .Lf1a53ec_001a54b3\n"
        /* } scope */
        /* { scope 2: c, arg */
        ".Lf1a53ec_001a5de2:\n"
        "movl -0x454(%ebp), %eax\n" /* line 775 */
        "movl %eax, 4(%esp)\n"
        "movl -0x3330(%ebp), %edx\n" /* ent */
        "movl 0x158(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_ClientCanSpectateTeam\n"
        "testl %eax, %eax\n"
        "je .Lf1a53ec_001a5d34\n"
        "movl -0x3330(%ebp), %ecx\n" /* line 779 | ent */
        "movl 0x158(%ecx), %eax\n"
        "movl %ebx, 0x27a8(%eax)\n" /* len */
        "movl 0x158(%ecx), %eax\n" /* line 780 */
        "movl $2, 0x26a8(%eax)\n"
        "jmp .Lf1a53ec_001a54b3\n"
        ".Lf1a53ec_001a5e2f:\n"
        "subl $1, %eax\n" /* line 766 */
        "cmpl $-1, %ebx\n" /* len */
        "cmovlel %eax, %ebx\n" /* len */
        "jmp .Lf1a53ec_001a5cfb\n"
        /* } scope */
        /* { scope 2: c, arg */
        ".Lf1a53ec_001a5e3d:\n"
        "movl -0x454(%ebp), %eax\n" /* line 775 */
        "movl %eax, 4(%esp)\n"
        "movl -0x3330(%ebp), %edx\n" /* ent */
        "movl 0x158(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_ClientCanSpectateTeam\n"
        "testl %eax, %eax\n"
        "je .Lf1a53ec_001a5dd9\n"
        "movl -0x3330(%ebp), %edx\n" /* line 779 | ent */
        "movl 0x158(%edx), %eax\n"
        "movl %ebx, 0x27a8(%eax)\n" /* len */
        "movl 0x158(%edx), %eax\n" /* line 780 */
        "movl $2, 0x26a8(%eax)\n"
        "jmp .Lf1a53ec_001a54b3\n"
        ".Lf1a53ec_001a5e8a:\n"
        "subl $1, %eax\n" /* line 766 */
        "cmpl $-1, %ebx\n" /* len */
        "cmovlel %eax, %ebx\n" /* len */
        "jmp .Lf1a53ec_001a5da4\n"
        /* } scope */
        ".Lf1a53ec_001a5e98:\n"
        "movl $str_002b3c4c, 4(%esp)\n" /* line 1533 */
        "movl %ebx, (%esp)\n" /* len */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a53ec_001a5ed7\n"
        "movl -0x3330(%ebp), %eax\n" /* line 1050 | ent */
        "addl $0x138, %eax\n"
        "movl %eax, (%esp)\n"
        "calll vtos\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x65, 4(%esp)\n"
        "movl $str_002b3744, (%esp)\n" /* "%c "%s
"" */
        "jmp .Lf1a53ec_001a5b6f\n"
        ".Lf1a53ec_001a5ed7:\n"
        "movl $str_002b3c54, 4(%esp)\n" /* line 1535 */
        "movl %ebx, (%esp)\n" /* len */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a53ec_001a5efe\n"
        "movl -0x3330(%ebp), %eax\n" /* line 1536 | ent */
        "movl %eax, (%esp)\n"
        "calll Cmd_CallVote_f\n"
        "jmp .Lf1a53ec_001a54b3\n"
        ".Lf1a53ec_001a5efe:\n"
        "movl $str_002b3c60, 4(%esp)\n" /* line 1537 */
        "movl %ebx, (%esp)\n" /* len */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a53ec_001a5f25\n"
        "movl -0x3330(%ebp), %edx\n" /* line 1538 | ent */
        "movl %edx, (%esp)\n"
        "calll Cmd_Vote_f\n"
        "jmp .Lf1a53ec_001a54b3\n"
        ".Lf1a53ec_001a5f25:\n"
        "movl $str_002b3c68, 4(%esp)\n" /* line 1539 */
        "movl %ebx, (%esp)\n" /* len */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a53ec_001a5f4c\n"
        "movl -0x3330(%ebp), %ecx\n" /* line 1540 | ent */
        "movl %ecx, (%esp)\n"
        "calll Cmd_GameCommand_f\n"
        "jmp .Lf1a53ec_001a54b3\n"
        ".Lf1a53ec_001a5f4c:\n"
        "movl $str_002b3c6c, 4(%esp)\n" /* line 1541 */
        "movl %ebx, (%esp)\n" /* len */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a53ec_001a5f73\n"
        "movl -0x3330(%ebp), %eax\n" /* line 1542 | ent */
        "movl %eax, (%esp)\n"
        "calll Cmd_SetViewpos_f\n"
        "jmp .Lf1a53ec_001a54b3\n"
        ".Lf1a53ec_001a5f73:\n"
        "movl $str_002b3c78, 4(%esp)\n" /* line 1543 */
        "movl %ebx, (%esp)\n" /* len */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a53ec_001a5fb5\n"
        "movl imp_g_cheats, %eax\n" /* line 1409 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1a53ec_001a54b3\n"
        "movl imp_level, %eax\n" /* line 1412 */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b3ae0, (%esp)\n" /* "entity count = %i
" */
        "calll Com_Printf\n"
        "jmp .Lf1a53ec_001a54b3\n"
        ".Lf1a53ec_001a5fb5:\n"
        "movl $str_002b3c84, 4(%esp)\n" /* line 1545 */
        "movl %ebx, (%esp)\n" /* len */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1a53ec_001a5fd3\n"
        "calll G_PrintEntities\n" /* line 1459 */
        "jmp .Lf1a53ec_001a54b3\n"
        ".Lf1a53ec_001a5fd3:\n"
        "movl %ebx, 8(%esp)\n" /* line 1548 | len */
        "movl $0x65, 4(%esp)\n"
        "movl $str_002b3c94, (%esp)\n" /* "%c "GAME_UNKNOWNCLIENTCOMMAND%s"" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* clientNum */
        "calll SV_GameSendServerCommand\n"
        "jmp .Lf1a53ec_001a54b3\n"
    );
}
#else
extern void Com_Error(int code, const char *fmt, ...);
extern int SV_GetArchivedClientInfo(int clientNum, void *cmd, void *ps, void *cs);
extern qboolean G_ClientCanSpectateTeam(gclient_t *client, int team);

qboolean Cmd_FollowCycle_f(gentity_t *ent, int dir) {
    int clientnum;
    int original;
    gclient_t *client;
    playerState_t ps;
    clientState_t cs;
    int maxclients;

    if (dir != 1 && dir != -1) {
        Com_Error(1, str_002b3724, dir);
    }

    client = *(gclient_t **)((byte *)ent + 0x158);
    /* Check session state == 2 (spectating) */
    if (*(int *)((byte *)client + 0x26a8) != 2)
        return 0;

    /* Check forceSpectatorClient >= 0 */
    if (*(int *)((byte *)client + 0x26ac) >= 0)
        return 0;

    /* Get spectatorClient */
    clientnum = *(int *)((byte *)client + 0x27a8);
    if (clientnum < 0)
        clientnum = 0;

    original = clientnum;

    for (;;) {
        clientnum += dir;

        maxclients = *(int *)((byte *)imp_level + 0x1e4);
        if (clientnum >= maxclients) {
            clientnum = 0;
        }
        if (clientnum == -1) {
            clientnum = maxclients - 1;
        }

        /* Try to get archived client info */
        client = *(gclient_t **)((byte *)ent + 0x158);
        if (SV_GetArchivedClientInfo(clientnum, (byte *)client + 0x26b4, &ps, &cs)) {
            /* Check if we can spectate this team */
            if (G_ClientCanSpectateTeam(*(gclient_t **)((byte *)ent + 0x158), *(int *)((byte *)&cs + 4))) {
                /* Set spectatorClient and session state */
                *(int *)((byte *)(*(gclient_t **)((byte *)ent + 0x158)) + 0x27a8) = clientnum;
                *(int *)((byte *)(*(gclient_t **)((byte *)ent + 0x158)) + 0x26a8) = 2;
                return 1;
            }
        }

        if (clientnum == original)
            return 0;
    }
}
#endif
