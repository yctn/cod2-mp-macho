/* ASM dump from: sv_ccmds_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/server_mp/sv_ccmds_mp.cpp */

#include "common_types.h"
#include "imports.h"

extern const char * FS_GetMapBaseName(const char *mapname);
extern void Com_Printf(const char *fmt, ...);
extern char * Dvar_InfoString(int bit);
extern void Info_Print(const char *s);
extern void Com_Shutdown(const char *finalmsg);
extern void SV_MasterGameCompleteStatus(void);
extern void Scr_DumpScriptThreads(void);
extern void MT_DumpTree(void);
extern void Cmd_AddCommand(const char *cmd_name, void (*function)(void));
extern void Cmd_SetAutoComplete(const char *cmd_name, const char *dir, const char *ext);
extern int SV_Cmd_Argc(void);
extern const char *SV_Cmd_Argv(int arg);
extern void SV_BanClient(void *cl);
extern void SV_UnbanClient(const char *name);

static qboolean initialized; /* initialized */

static client_t * SV_GetPlayerByName(void);
static client_t * SV_GetPlayerByNum(void);
const char * SV_GetMapBaseName(const char *mapname);
static short int SV_MapRestart(void);
static short int SV_MapRestart_f(void);
static short int SV_FastRestart_f(void);
static int SV_KickClient_f(void);
static short int SV_Ban_f(void);
static short int SV_BanNum_f(void);
static short int SV_Unban_f(void);
static short int SV_DropNum_f(void);
static short int SV_TempBanNum_f(void);
static short int SV_Status_f(void);
static short int SV_ConSay_f(void);
static short int SV_ConTell_f(void);
short int SV_Heartbeat_f(void);
static short int SV_Serverinfo_f(void);
static short int SV_Systeminfo_f(void);
static short int SV_DumpUser_f(void);
static short int SV_KillServer_f(void);
short int SV_GameCompleteStatus_f(void);
static short int SV_ScriptUsage_f(void);
static short int SV_StringUsage_f(void);
short int SV_AddDedicatedCommands(void);
short int SV_RemoveOperatorCommands(void);
static short int SV_Map_f(void);
short int SV_AddOperatorCommands(void);
static int SV_KickUser_f(void);
static short int SV_TempBan_f(void);
static short int SV_Drop_f(void);
static short int SV_MapRotate_f(void);

/* line 34 */
static __attribute__((naked))
client_t * SV_GetPlayerByName(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 34 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1 */
        "movl imp_com_sv_running, %eax\n" /* line 42 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf16fd38_0016fd5a\n"
        ".Lf16fd38_0016fd4e:\n"
        "xorl %edi, %edi\n" /* line 75 | cl */
        /* } scope */
        ".Lf16fd38_0016fd50:\n"
        "movl %edi, %eax\n" /* line 78 | cl */
        "addl $0x6c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16fd38_0016fd5a:\n"
        "calll SV_Cmd_Argc\n" /* line 47 */
        "subl $1, %eax\n"
        "jle .Lf16fd38_0016fe43\n"
        "movl $1, (%esp)\n" /* line 53 */
        "calll SV_Cmd_Argv\n"
        "movl %eax, -0x5c(%ebp)\n" /* s */
        "movl imp_svs, %eax\n" /* line 56 */
        "movl 0xc(%eax), %edi\n" /* cl */
        "movl imp_sv_maxclients, %edx\n"
        "movl (%edx), %eax\n"
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lf16fd38_0016fe2b\n"
        "xorl %esi, %esi\n" /* i */
        "movl %edx, -0x60(%ebp)\n"
        "leal 0x20c48(%edi), %ebx\n" /* cl */
        "jmp .Lf16fd38_0016fdb5\n"
        ".Lf16fd38_0016fd9f:\n"
        "addl $1, %esi\n" /* i */
        "addl $0x78f0c, %edi\n" /* cl */
        "addl $0x78f0c, %ebx\n"
        "movl (%edx), %eax\n"
        "cmpl 8(%eax), %esi\n" /* i */
        "jge .Lf16fd38_0016fe2b\n"
        ".Lf16fd38_0016fdb5:\n"
        "movl -0x20c48(%ebx), %eax\n" /* line 58 */
        "testl %eax, %eax\n"
        "je .Lf16fd38_0016fd9f\n"
        "movl -0x5c(%ebp), %eax\n" /* line 62 | s */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf16fd38_0016fd50\n"
        "movl $0x40, 8(%esp)\n" /* line 67 */
        "movl %ebx, 4(%esp)\n"
        "leal -0x58(%ebp), %eax\n" /* cleanName */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "leal -0x58(%ebp), %eax\n" /* line 68 | cleanName */
        "movl %eax, (%esp)\n"
        "calll I_CleanStr\n"
        "movl -0x5c(%ebp), %eax\n" /* line 69 | s */
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %eax\n" /* cleanName */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf16fd38_0016fd50\n"
        "movl -0x60(%ebp), %edx\n"
        "addl $1, %esi\n" /* line 56 | i */
        "addl $0x78f0c, %edi\n" /* cl */
        "addl $0x78f0c, %ebx\n"
        "movl (%edx), %eax\n"
        "cmpl 8(%eax), %esi\n" /* i */
        "jl .Lf16fd38_0016fdb5\n"
        ".Lf16fd38_0016fe2b:\n"
        "movl -0x5c(%ebp), %eax\n" /* line 75 | s */
        "movl %eax, 4(%esp)\n"
        "movl $str_002ac3fc, (%esp)\n" /* "Player %s is not on the server
" */
        "calll Com_Printf\n"
        "jmp .Lf16fd38_0016fd4e\n"
        ".Lf16fd38_0016fe43:\n"
        "movl $str_002ac3e4, (%esp)\n" /* line 49 */
        "calll Com_Printf\n"
        "xorl %edi, %edi\n" /* cl */
        "jmp .Lf16fd38_0016fd50\n"
    );
}

/* line 88 */
static __attribute__((naked))
client_t * SV_GetPlayerByNum(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 88 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl imp_com_sv_running, %eax\n" /* line 96 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf16fe56_0016fe6d\n"
        "xorl %eax, %eax\n" /* line 127 */
        /* } scope */
        ".Lf16fe56_0016fe6b:\n"
        "leave\n" /* line 131 */
        "retl\n"
        /* { scope 1 */
        ".Lf16fe56_0016fe6d:\n"
        "calll SV_Cmd_Argc\n" /* line 101 */
        "subl $1, %eax\n"
        "jle .Lf16fe56_0016ff32\n"
        "movl $1, (%esp)\n" /* line 107 */
        "calll SV_Cmd_Argv\n"
        "movl %eax, %ecx\n"
        "movzbl (%eax), %eax\n" /* line 109 */
        "testb %al, %al\n"
        "je .Lf16fe56_0016febd\n"
        "subb $0x30, %al\n" /* line 111 */
        "cmpb $9, %al\n"
        "ja .Lf16fe56_0016fea9\n"
        "movl %ecx, %edx\n"
        ".Lf16fe56_0016fe98:\n"
        "movzbl 1(%edx), %eax\n" /* line 109 */
        "testb %al, %al\n"
        "je .Lf16fe56_0016febd\n"
        "addl $1, %edx\n"
        "subb $0x30, %al\n" /* line 111 */
        "cmpb $9, %al\n"
        "jbe .Lf16fe56_0016fe98\n"
        ".Lf16fe56_0016fea9:\n"
        "movl %ecx, 4(%esp)\n" /* line 113 */
        "movl $str_002ac41c, (%esp)\n" /* "Bad slot number: %s
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "leave\n" /* line 131 */
        "retl\n"
        /* { scope 1 */
        ".Lf16fe56_0016febd:\n"
        "movl %ecx, (%esp)\n" /* line 117 */
        "calll atoi\n"
        "movl %eax, %ecx\n"
        "testl %eax, %eax\n" /* line 118 */
        "js .Lf16fe56_0016ff1b\n"
        "movl imp_sv_maxclients, %eax\n"
        "movl (%eax), %eax\n"
        "cmpl 8(%eax), %ecx\n"
        "jge .Lf16fe56_0016ff1b\n"
        "leal (%ecx, %ecx, 4), %eax\n" /* line 124 */
        "movl %eax, %edx\n"
        "shll $7, %edx\n"
        "addl %edx, %eax\n"
        "shll $6, %eax\n"
        "addl %ecx, %eax\n"
        "leal (, %eax, 4), %edx\n"
        "subl %eax, %edx\n"
        "movl imp_svs, %eax\n"
        "movl 0xc(%eax), %eax\n"
        "leal (%eax, %edx, 4), %eax\n"
        "movl (%eax), %edx\n" /* line 125 */
        "testl %edx, %edx\n"
        "jne .Lf16fe56_0016fe6b\n"
        "movl %ecx, 4(%esp)\n" /* line 127 */
        "movl $str_002ac44c, (%esp)\n" /* "Client %i is not active
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        "jmp .Lf16fe56_0016fe6b\n"
        ".Lf16fe56_0016ff1b:\n"
        "movl %ecx, 4(%esp)\n" /* line 120 */
        "movl $str_002ac434, (%esp)\n" /* "Bad client slot: %i
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n" /* line 127 */
        "jmp .Lf16fe56_0016fe6b\n"
        ".Lf16fe56_0016ff32:\n"
        "movl $str_002ac3e4, (%esp)\n" /* line 103 */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "leave\n" /* line 131 */
        "retl\n"
    );
}

/* line 136 */
const char * SV_GetMapBaseName(const char *mapname)
{
    return FS_GetMapBaseName(mapname);
}

/* line 216 */
static __attribute__((naked))
short int SV_MapRestart(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 216 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl %eax, %edi\n" /* fast_restart */
        /* { scope 1 */
        "movl imp_com_sv_running, %eax\n" /* line 233 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf16ff4c_0016ff78\n"
        "movl $str_002ac468, (%esp)\n" /* line 235 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf16ff4c_0016ff70:\n"
        "addl $0x6c, %esp\n" /* line 325 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16ff4c_0016ff78:\n"
        "calll SV_SetGametype\n" /* line 239 */
        "movl $0x40, 8(%esp)\n" /* line 240 */
        "movl imp_sv_gametype, %esi\n" /* i */
        "movl (%esi), %eax\n" /* i */
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl imp_sv, %ebx\n" /* client */
        "addl $0x5f4f4, %ebx\n" /* client */
        "movl %ebx, (%esp)\n" /* client */
        "calll I_strncpyz\n"
        "calll G_GetSavePersist\n" /* line 242 */
        "movl %eax, -0x5c(%ebp)\n" /* savepersist */
        "movl imp_sv_maxclients, %eax\n" /* line 245 */
        "movl (%eax), %eax\n"
        "cmpb $0, 7(%eax)\n"
        "je .Lf16ff4c_00170004\n"
        ".Lf16ff4c_0016ffbd:\n"
        "movl $0, (%esp)\n" /* line 247 */
        "calll G_SetSavePersist\n"
        "movl $str_002a7124, (%esp)\n" /* line 250 */
        "calll Dvar_GetString\n"
        "movl $0x40, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %ebx\n" /* mapname, client */
        "movl %ebx, (%esp)\n" /* client */
        "calll I_strncpyz\n"
        "movl %ebx, (%esp)\n" /* line 251 | client */
        "calll FS_ConvertPath\n"
        "movl %ebx, (%esp)\n" /* line 252 | client */
        "calll SV_SpawnServer\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 325 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16ff4c_00170004:\n"
        "movl (%esi), %eax\n" /* line 245 | i */
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* client */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf16ff4c_0016ffbd\n"
        "testl %edi, %edi\n" /* fast_restart */
        "je .Lf16ff4c_0016ffbd\n"
        "movl imp_com_frameTime, %esi\n" /* line 257 | i */
        "movl imp_sv, %edx\n"
        "movl 8(%edx), %eax\n"
        "cmpl (%esi), %eax\n" /* i */
        "je .Lf16ff4c_0016ff70\n"
        "calll SV_InitDvar\n" /* line 260 */
        "calll SV_InitArchivedSnapshot\n" /* line 262 */
        "movl imp_svs, %ebx\n" /* line 266 | client */
        "xorl $4, 8(%ebx)\n" /* client */
        "movl imp_sv_serverId_value, %ecx\n" /* line 269 */
        "movl (%ecx), %eax\n"
        "movl %eax, %edx\n"
        "andl $0xf0, %edx\n"
        "addl $1, %eax\n"
        "andl $0xf, %eax\n"
        "addl %eax, %edx\n"
        "movl %edx, (%ecx)\n"
        "movl %edx, 4(%esp)\n" /* line 270 */
        "movl imp_sv_serverid, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movl (%esi), %eax\n" /* line 271 | i */
        "movl imp_sv, %edx\n"
        "movl %eax, 8(%edx)\n"
        "movl $1, (%edx)\n" /* line 276 */
        "movl $1, 4(%edx)\n" /* line 277 */
        "movl -0x5c(%ebp), %eax\n" /* line 283 | savepersist */
        "movl %eax, (%esp)\n"
        "calll SV_RestartGameProgs\n"
        "movl $3, %esi\n" /* i */
        ".Lf16ff4c_0017009d:\n"
        "addl $0x64, 4(%ebx)\n" /* line 288 | client */
        "calll SV_RunFrame\n" /* line 289 */
        "subl $1, %esi\n" /* line 286 | i */
        "jne .Lf16ff4c_0017009d\n"
        "movl imp_sv_maxclients, %edx\n" /* line 293 */
        "movl (%edx), %eax\n"
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lf16ff4c_0017015d\n"
        "xorl %esi, %esi\n" /* i */
        "xorl %edi, %edi\n" /* fast_restart */
        "jmp .Lf16ff4c_001700f6\n"
        ".Lf16ff4c_001700c4:\n"
        "movl %eax, 4(%esp)\n" /* line 312 */
        "movl %ebx, (%esp)\n" /* client */
        "calll SV_DropClient\n"
        "movl %esi, 4(%esp)\n" /* line 313 | i */
        "movl $str_002ac480, (%esp)\n" /* "SV_MapRestart_f: dropped client %i - denied!
" */
        "calll Com_Printf\n"
        "movl imp_sv_maxclients, %edx\n"
        ".Lf16ff4c_001700e6:\n"
        "addl $1, %esi\n" /* line 293 | i */
        "addl $0x78f0c, %edi\n" /* fast_restart */
        "movl (%edx), %eax\n"
        "cmpl 8(%eax), %esi\n" /* i */
        "jge .Lf16ff4c_0017015d\n"
        ".Lf16ff4c_001700f6:\n"
        "movl imp_svs, %eax\n" /* line 295 */
        "movl %edi, %ebx\n" /* fast_restart, client */
        "addl 0xc(%eax), %ebx\n" /* client */
        "cmpl $1, (%ebx)\n" /* line 298 | client */
        "jle .Lf16ff4c_001700e6\n"
        "cmpl $1, -0x5c(%ebp)\n" /* line 304 | savepersist */
        "sbbl %eax, %eax\n"
        "andl $0xffffffd4, %eax\n"
        "addl $0x6e, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002a6fe0, (%esp)\n" /* "%c" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* client */
        "calll SV_AddServerCommand\n"
        "movzwl 0x765f0(%ebx), %eax\n" /* line 307 | client */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* i */
        "calll ClientConnect\n"
        "testl %eax, %eax\n" /* line 308 */
        "jne .Lf16ff4c_001700c4\n"
        "cmpl $4, (%ebx)\n" /* line 317 | client */
        "je .Lf16ff4c_00170174\n"
        "movl imp_sv_maxclients, %edx\n"
        "jmp .Lf16ff4c_001700e6\n"
        ".Lf16ff4c_0017015d:\n"
        "movl imp_sv, %eax\n" /* line 323 */
        "movl $2, (%eax)\n"
        "movl $0, 4(%eax)\n" /* line 324 */
        "jmp .Lf16ff4c_0016ff70\n"
        ".Lf16ff4c_00170174:\n"
        "leal 0x20824(%ebx), %eax\n" /* line 320 | client */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* client */
        "calll SV_ClientEnterWorld\n"
        "movl imp_sv_maxclients, %edx\n"
        "jmp .Lf16ff4c_001700e6\n"
    );
}

/* line 334 */
static __attribute__((naked))
short int SV_MapRestart_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 334 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n" /* line 336 */
        "popl %ebp\n" /* line 337 */
        "jmp SV_MapRestart\n" /* line 336 */
    );
}

/* line 346 */
static __attribute__((naked))
short int SV_FastRestart_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 346 */
        "movl %esp, %ebp\n"
        "movl $1, %eax\n" /* line 348 */
        "popl %ebp\n" /* line 349 */
        "jmp SV_MapRestart\n" /* line 348 */
    );
}

/* line 528 */
static __attribute__((naked))
int SV_KickClient_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 528 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl %eax, %ebx\n" /* playerName */
        "movl %edx, %edi\n" /* maxPlayerNameLen */
        /* { scope 1 */
        "movl imp_com_sv_running, %eax\n" /* line 532 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1701ac_001701de\n"
        "movl $str_002ac468, (%esp)\n" /* line 534 */
        "calll Com_Printf\n"
        "xorl %ebx, %ebx\n" /* playerName */
        /* } scope */
        ".Lf1701ac_001701d4:\n"
        "movl %ebx, %eax\n" /* line 549 | playerName */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1701ac_001701de:\n"
        "calll SV_Cmd_Argc\n" /* line 538 */
        "cmpl $2, %eax\n"
        "je .Lf1701ac_00170210\n"
        "movl $0, (%esp)\n" /* line 540 */
        "calll SV_Cmd_Argv\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ac4b0, (%esp)\n" /* "Usage: %s <client number>
" */
        "calll Com_Printf\n"
        "xorl %ebx, %ebx\n" /* playerName */
        /* } scope */
        "movl %ebx, %eax\n" /* line 549 | playerName */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1701ac_00170210:\n"
        "calll SV_GetPlayerByNum\n" /* line 544 */
        "movl %eax, %esi\n" /* cl */
        "testl %eax, %eax\n" /* line 545 */
        "je .Lf1701ac_00170298\n"
        /* { scope 2 */
        "cmpl $2, 0x6e5c4(%eax)\n" /* line 465 */
        "je .Lf1701ac_00170274\n"
        "testl %ebx, %ebx\n" /* line 471 | guid */
        "je .Lf1701ac_00170246\n"
        "movl %edi, 8(%esp)\n" /* line 473 */
        "leal 0x20c48(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* guid */
        "calll I_strncpyz\n"
        "movl %ebx, (%esp)\n" /* line 474 | guid */
        "calll I_CleanStr\n"
        ".Lf1701ac_00170246:\n"
        "movl 0x765ec(%esi), %ebx\n" /* line 476 | guid */
        "movl $str_002ac4ec, 4(%esp)\n" /* line 478 */
        "movl %esi, (%esp)\n"
        "calll SV_DropClient\n"
        "movl imp_svs, %eax\n" /* line 479 */
        "movl 4(%eax), %eax\n"
        "movl %eax, 0x20d10(%esi)\n"
        /* } scope */
        /* } scope */
        "movl %ebx, %eax\n" /* line 549 | playerName */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1701ac_00170274:\n"
        "movl $0x65, 0xc(%esp)\n" /* line 467 */
        "movl $str_002ac4cc, 8(%esp)\n" /* "%c "EXE_CANNOTKICKHOSTPLAYER"" */
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll SV_SendServerCommand\n"
        ".Lf1701ac_00170298:\n"
        "xorl %ebx, %ebx\n" /* guid */
        "jmp .Lf1701ac_001701d4\n"
    );
}

/* line 581 */
static short int SV_Ban_f(void)
{
    void *cl;
    if (!*(byte *)((byte *)(*(void **)imp_com_sv_running) + 8))
    {
        Com_Printf("Server is not running.\n");
        return 0;
    }
    if (SV_Cmd_Argc() != 2)
    {
        Com_Printf("Usage: banUser <player name>\n");
        return 0;
    }
    cl = (void *)SV_GetPlayerByName();
    if (cl)
        SV_BanClient(cl);
    return 0;
}

/* line 614 */
static short int SV_BanNum_f(void)
{
    void *cl;
    if (!*(byte *)((byte *)(*(void **)imp_com_sv_running) + 8))
    {
        Com_Printf("Server is not running.\n");
        return 0;
    }
    if (SV_Cmd_Argc() != 2)
    {
        Com_Printf("Usage: banClient <client number>\n");
        return 0;
    }
    cl = (void *)SV_GetPlayerByNum();
    if (cl)
        SV_BanClient(cl);
    return 0;
}

/* line 644 */
static short int SV_Unban_f(void)
{
    if (SV_Cmd_Argc() != 2)
    {
        Com_Printf("Usage: unbanUser <player name>\n");
        return 0;
    }
    SV_UnbanClient(SV_Cmd_Argv(1));
    return 0;
}

/* line 662 */
static __attribute__((naked))
short int SV_DropNum_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 662 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "xorl %edx, %edx\n" /* line 664 */
        "xorl %eax, %eax\n"
        "calll SV_KickClient_f\n"
        "leave\n" /* line 665 */
        "retl\n"
    );
}

/* line 675 */
static __attribute__((naked))
short int SV_TempBanNum_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 675 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x50, %esp\n"
        /* { scope 1 */
        "leal -0x48(%ebp), %esi\n" /* line 680 | playerName */
        "movl $0x40, %edx\n"
        "movl %esi, %eax\n"
        "calll SV_KickClient_f\n"
        "movl %eax, %ebx\n" /* guid */
        "testl %eax, %eax\n" /* line 681 */
        "je .Lf17037e_001703b7\n"
        "movl %eax, 8(%esp)\n" /* line 683 */
        "movl %esi, 4(%esp)\n"
        "movl $str_002ac560, (%esp)\n" /* "%s (guid %i) was kicked for cheating
" */
        "calll Com_Printf\n"
        "movl %ebx, (%esp)\n" /* line 684 | guid */
        "calll SV_BanGuidBriefly\n"
        /* } scope */
        ".Lf17037e_001703b7:\n"
        "addl $0x50, %esp\n" /* line 686 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 696 */
static __attribute__((naked))
short int SV_Status_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 696 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl imp_com_sv_running, %eax\n" /* line 705 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1703be_001703e8\n"
        "movl $str_002ac468, (%esp)\n" /* line 707 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 757 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1703be_001703e8:\n"
        "movl imp_sv_mapname, %eax\n" /* line 711 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ac588, (%esp)\n" /* "map: %s
" */
        "calll Com_Printf\n"
        "movl $str_002ac594, (%esp)\n" /* line 713 */
        "calll Com_Printf\n"
        "movl $str_002ac5e4, (%esp)\n" /* line 714 */
        "calll Com_Printf\n"
        "movl imp_svs, %ecx\n" /* line 715 */
        "movl 0xc(%ecx), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* cl */
        "movl imp_sv_maxclients, %edx\n"
        "movl (%edx), %eax\n"
        "movl 8(%eax), %esi\n"
        "testl %esi, %esi\n"
        "jle .Lf1703be_00170608\n"
        "movl $0, -0x30(%ebp)\n" /* i */
        "movl %ecx, -0x34(%ebp)\n"
        "movl %edx, -0x38(%ebp)\n"
        "movl -0x2c(%ebp), %esi\n" /* cl */
        "addl $0x20c48, %esi\n"
        "jmp .Lf1703be_00170470\n"
        ".Lf1703be_00170451:\n"
        "addl $1, -0x30(%ebp)\n" /* i */
        "addl $0x78f0c, -0x2c(%ebp)\n" /* cl */
        "addl $0x78f0c, %esi\n"
        "movl (%edx), %eax\n"
        "movl -0x30(%ebp), %ecx\n" /* i */
        "cmpl 8(%eax), %ecx\n"
        "jge .Lf1703be_00170608\n"
        ".Lf1703be_00170470:\n"
        "movl -0x20c48(%esi), %ebx\n" /* line 717 | l */
        "testl %ebx, %ebx\n" /* l */
        "je .Lf1703be_00170451\n"
        "movl -0x30(%ebp), %edx\n" /* line 719 | i */
        "movl %edx, 4(%esp)\n"
        "movl $str_002ac638, (%esp)\n" /* "%3i " */
        "calll Com_Printf\n"
        "movl -0x30(%ebp), %ecx\n" /* line 720 | i */
        "movl %ecx, (%esp)\n"
        "calll SV_GameClientNum\n"
        "movl -0x2c(%ebp), %eax\n" /* line 721 | cl */
        "movl -0x34(%ebp), %edx\n"
        "subl 0xc(%edx), %eax\n"
        "sarl $2, %eax\n"
        "imull $0x3789a4eb, %eax, %eax\n"
        "movl %eax, (%esp)\n"
        "calll G_GetClientScore\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ac640, (%esp)\n" /* "%5i " */
        "calll Com_Printf\n"
        "movl -0x20c48(%esi), %eax\n" /* line 723 */
        "cmpl $2, %eax\n"
        "je .Lf1703be_00170661\n"
        "subl $1, %eax\n" /* line 725 */
        "je .Lf1703be_00170650\n"
        "movl 0x4d95c(%esi), %eax\n" /* line 730 */
        "cmpl $0x2710, %eax\n"
        "movl $0x270f, %edx\n"
        "cmovgel %edx, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ac658, (%esp)\n" /* "%4i " */
        "calll Com_Printf\n"
        ".Lf1703be_001704fd:\n"
        "movl 0x559a4(%esi), %eax\n" /* line 733 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002ac660, (%esp)\n" /* "%6i " */
        "calll Com_Printf\n"
        "movl %esi, 4(%esp)\n" /* line 735 */
        "movl $str_002ac668, (%esp)\n" /* "%s^7" */
        "calll Com_Printf\n"
        "movl %esi, (%esp)\n" /* line 736 */
        "calll I_DrawStrlen\n"
        "movl $0x10, %ebx\n" /* l */
        "subl %eax, %ebx\n" /* l */
        "testl %ebx, %ebx\n" /* line 737 | l */
        "jg .Lf1703be_0017061c\n"
        ".Lf1703be_0017053a:\n"
        "movl -0x34(%ebp), %ecx\n" /* line 740 */
        "movl 4(%ecx), %eax\n"
        "subl 0xc8(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ac670, (%esp)\n" /* "%7i " */
        "calll Com_Printf\n"
        "movl 0x4d97c(%esi), %ecx\n" /* line 742 */
        "movl %ecx, -0x24(%ebp)\n"
        "movl 0x4d980(%esi), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl 0x4d984(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_AdrToString\n"
        "movl %eax, %edi\n" /* s */
        "movl %eax, 4(%esp)\n" /* line 743 */
        "movl $str_00216058, (%esp)\n" /* "%s" */
        "calll Com_Printf\n"
        "cld\n" /* line 744 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* s */
        "notl %ecx\n"
        "movl $0x17, %ebx\n" /* l */
        "subl %ecx, %ebx\n" /* l */
        "testl %ebx, %ebx\n" /* line 745 | l */
        "jg .Lf1703be_00170636\n"
        ".Lf1703be_001705ae:\n"
        "movl 0x4d988(%esi), %eax\n" /* line 749 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002ac678, (%esp)\n" /* "%5i" */
        "calll Com_Printf\n"
        "movl 0x4d960(%esi), %eax\n" /* line 752 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002ac67c, (%esp)\n" /* " %5i" */
        "calll Com_Printf\n"
        "movl $str_002160e8, (%esp)\n" /* line 754 */
        "calll Com_Printf\n"
        "movl -0x38(%ebp), %edx\n"
        "addl $1, -0x30(%ebp)\n" /* line 715 | i */
        "addl $0x78f0c, -0x2c(%ebp)\n" /* cl */
        "addl $0x78f0c, %esi\n"
        "movl (%edx), %eax\n"
        "movl -0x30(%ebp), %ecx\n" /* i */
        "cmpl 8(%eax), %ecx\n"
        "jl .Lf1703be_00170470\n"
        ".Lf1703be_00170608:\n"
        "movl $str_002160e8, (%esp)\n" /* line 756 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 757 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1703be_0017061c:\n"
        "xorl %edi, %edi\n" /* line 737 | s */
        ".Lf1703be_0017061e:\n"
        "movl $str_00217914, (%esp)\n" /* line 738 */
        "calll Com_Printf\n"
        "addl $1, %edi\n" /* line 737 | s */
        "cmpl %edi, %ebx\n" /* s, l */
        "jne .Lf1703be_0017061e\n"
        "jmp .Lf1703be_0017053a\n"
        ".Lf1703be_00170636:\n"
        "xorl %edi, %edi\n" /* line 745 | s */
        ".Lf1703be_00170638:\n"
        "movl $str_00217914, (%esp)\n" /* line 746 */
        "calll Com_Printf\n"
        "addl $1, %edi\n" /* line 745 | s */
        "cmpl %edi, %ebx\n" /* s, l */
        "jne .Lf1703be_00170638\n"
        "jmp .Lf1703be_001705ae\n"
        ".Lf1703be_00170650:\n"
        "movl $str_002ac650, (%esp)\n" /* line 726 */
        "calll Com_Printf\n"
        "jmp .Lf1703be_001704fd\n"
        ".Lf1703be_00170661:\n"
        "movl $str_002ac648, (%esp)\n" /* line 724 */
        "calll Com_Printf\n"
        "jmp .Lf1703be_001704fd\n"
    );
}

/* line 765 */
static __attribute__((naked))
short int SV_ConSay_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 765 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %ebx\n"
        "subl $0x420, %esp\n"
        /* { scope 1 */
        "movl imp_com_sv_running, %eax\n" /* line 771 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf170672_001706a0\n"
        "movl $str_002ac468, (%esp)\n" /* line 773 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf170672_00170696:\n"
        "addl $0x420, %esp\n" /* line 794 */
        "popl %ebx\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf170672_001706a0:\n"
        "calll SV_Cmd_Argc\n" /* line 777 */
        "subl $1, %eax\n"
        "jle .Lf170672_00170696\n"
        "leal -0x408(%ebp), %ebx\n" /* line 782 | text */
        "movl $0x736e6f63, -0x408(%ebp)\n" /* text */
        "movl $0x3a656c6f, -0x404(%ebp)\n"
        "movw $0x20, -0x400(%ebp)\n"
        "movl $1, (%esp)\n" /* line 783 */
        "calll Cmd_Args\n"
        "movl %eax, %edx\n"
        "cmpb $0x22, (%eax)\n" /* line 785 */
        "je .Lf170672_00170726\n"
        ".Lf170672_001706e0:\n"
        "movl %edx, 8(%esp)\n" /* line 791 */
        "movl $0x400, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll I_strncat\n"
        "movl %ebx, 0x10(%esp)\n" /* line 793 */
        "movl $0x68, 0xc(%esp)\n"
        "movl $str_002ac684, 8(%esp)\n" /* "%c "%s"" */
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll SV_SendServerCommand\n"
        /* } scope */
        "addl $0x420, %esp\n" /* line 794 */
        "popl %ebx\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf170672_00170726:\n"
        "addl $1, %edx\n" /* line 787 */
        "cld\n" /* line 788 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %edx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movb $0, -2(%ecx, %edx)\n"
        "jmp .Lf170672_001706e0\n"
    );
}

/* line 802 */
static __attribute__((naked))
short int SV_ConTell_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 802 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        /* { scope 1 */
        "movl imp_com_sv_running, %eax\n" /* line 810 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf17073e_0017076e\n"
        "movl $str_002ac468, (%esp)\n" /* line 812 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf17073e_00170763:\n"
        "addl $0x42c, %esp\n" /* line 838 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17073e_0017076e:\n"
        "calll SV_Cmd_Argc\n" /* line 816 */
        "cmpl $2, %eax\n"
        "jle .Lf17073e_00170763\n"
        "movl $1, (%esp)\n" /* line 819 */
        "calll SV_Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %ecx\n"
        "testl %eax, %eax\n" /* line 820 */
        "js .Lf17073e_00170763\n"
        "movl imp_sv_maxclients, %eax\n"
        "movl (%eax), %eax\n"
        "cmpl 8(%eax), %ecx\n"
        "jge .Lf17073e_00170763\n"
        "leal (%ecx, %ecx, 4), %eax\n" /* line 822 */
        "movl %eax, %edx\n"
        "shll $7, %edx\n"
        "addl %edx, %eax\n"
        "shll $6, %eax\n"
        "addl %ecx, %eax\n"
        "leal (, %eax, 4), %edx\n"
        "subl %eax, %edx\n"
        "movl imp_svs, %eax\n"
        "movl 0xc(%eax), %eax\n"
        "leal (%eax, %edx, 4), %ebx\n" /* cl */
        "cmpl $4, (%ebx)\n" /* line 823 | cl */
        "jne .Lf17073e_00170763\n"
        "leal -0x418(%ebp), %esi\n" /* line 826 | text */
        "movl $0x736e6f63, -0x418(%ebp)\n" /* text */
        "movl $0x3a656c6f, -0x414(%ebp)\n"
        "movw $0x20, -0x410(%ebp)\n"
        "movl $2, (%esp)\n" /* line 827 */
        "calll Cmd_Args\n"
        "movl %eax, %edx\n"
        "cmpb $0x22, (%eax)\n" /* line 829 */
        "je .Lf17073e_00170839\n"
        ".Lf17073e_001707fc:\n"
        "movl %edx, 8(%esp)\n" /* line 835 */
        "movl $0x400, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll I_strncat\n"
        "movl %esi, 0x10(%esp)\n" /* line 837 */
        "movl $0x68, 0xc(%esp)\n"
        "movl $str_002ac684, 8(%esp)\n" /* "%c "%s"" */
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* cl */
        "calll SV_SendServerCommand\n"
        "jmp .Lf17073e_00170763\n"
        ".Lf17073e_00170839:\n"
        "addl $1, %edx\n" /* line 831 */
        "cld\n" /* line 832 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %edx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movb $0, -2(%ecx, %edx)\n"
        "jmp .Lf17073e_001707fc\n"
    );
}

/* line 848 */
short int SV_Heartbeat_f(void)
{
    *(int *)((byte *)imp_svs + 0x54) = (int)0x80000000;
}

/* line 861 */
static short int SV_Serverinfo_f(void)
{
    Com_Printf("Server info settings:\n");
    Info_Print(Dvar_InfoString(0x404));
}

/* line 875 */
static short int SV_Systeminfo_f(void)
{
    Com_Printf("System info settings:\n");
    Info_Print(Dvar_InfoString(8));
}

/* line 889 */
static short int SV_DumpUser_f(void)
{
    byte *cl;
    if (!*(byte *)((byte *)(*(void **)imp_com_sv_running) + 8))
    {
        Com_Printf("Server is not running.\n");
        return 0;
    }
    if (SV_Cmd_Argc() != 2)
    {
        Com_Printf("Usage: dumpuser <player name>\n");
        return 0;
    }
    cl = (byte *)SV_GetPlayerByName();
    if (!cl)
        return 0;
    Com_Printf("userinfo\n");
    Com_Printf("--------\n");
    Info_Print((const char *)(cl + 0xc));
    return 0;
}

/* line 923 */
static short int SV_KillServer_f(void)
{
    Com_Shutdown("EXE_SERVERKILLED");
}

/* line 936 */
short int SV_GameCompleteStatus_f(void)
{
    SV_MasterGameCompleteStatus();
}

/* line 947 */
static short int SV_ScriptUsage_f(void)
{
    Scr_DumpScriptThreads();
}

/* line 1028 */
static short int SV_StringUsage_f(void)
{
    MT_DumpTree();
}

/* line 1111 */
short int SV_AddDedicatedCommands(void)
{
    Cmd_AddCommand("say", (void (*)(void))SV_ConSay_f);
    Cmd_AddCommand("tell", (void (*)(void))SV_ConTell_f);
}

/* line 1101 */
short int SV_RemoveOperatorCommands(void)
{
}

/* line 151 */
static __attribute__((naked))
short int SV_Map_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 151 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x50, %esp\n"
        /* { scope 1 */
        "movl $1, (%esp)\n" /* line 160 */
        "calll SV_Cmd_Argv\n"
        "movl %eax, %ebx\n" /* map */
        "cmpb $0, (%eax)\n" /* line 162 */
        "jne .Lf170992_001709b4\n"
        /* } scope */
        ".Lf170992_001709ad:\n"
        "addl $0x50, %esp\n" /* line 205 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf170992_001709b4:\n"
        "calll Com_HasPlayerProfile\n" /* line 166 */
        "testb %al, %al\n"
        "jne .Lf170992_001709d0\n"
        "movl $str_002ac710, (%esp)\n" /* line 168 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x50, %esp\n" /* line 205 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf170992_001709d0:\n"
        "movl %ebx, (%esp)\n" /* line 138 */
        "calll FS_GetMapBaseName\n"
        "movl $0x40, 8(%esp)\n" /* line 184 */
        "movl %eax, 4(%esp)\n"
        "leal -0x48(%ebp), %esi\n" /* stableName */
        "movl %esi, (%esp)\n"
        "calll I_strncpyz\n"
        "movl %esi, (%esp)\n" /* line 185 */
        "calll I_strlwr\n"
        "calll GetBspExtension\n" /* line 186 */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl $str_002a74ac, (%esp)\n" /* "maps/mp/%s.%s" */
        "calll va\n"
        "movl %eax, %ebx\n" /* map */
        "movl $0, 4(%esp)\n" /* line 191 */
        "movl %eax, (%esp)\n"
        "calll FS_ReadFile\n"
        "addl $1, %eax\n"
        "je .Lf170992_00170a76\n"
        "movl $0, (%esp)\n" /* line 198 */
        "calll SV_Cmd_Argv\n"
        "movl $str_002ac75c, 4(%esp)\n" /* line 199 */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "movl %eax, %ebx\n" /* map */
        "movl %esi, (%esp)\n" /* line 201 */
        "calll FS_ConvertPath\n"
        "movl %esi, (%esp)\n" /* line 202 */
        "calll SV_SpawnServer\n"
        "xorl %eax, %eax\n" /* line 204 */
        "testl %ebx, %ebx\n" /* map */
        "sete %al\n"
        "movl %eax, 4(%esp)\n"
        "movl imp_sv_cheats, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetBool\n"
        /* } scope */
        "addl $0x50, %esp\n" /* line 205 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf170992_00170a76:\n"
        "movl %ebx, 4(%esp)\n" /* line 193 | map */
        "movl $str_002ac748, (%esp)\n" /* "Can't find map %s
" */
        "calll Com_Printf\n"
        "jmp .Lf170992_001709ad\n"
    );
}

/* line 1041 */
short int SV_AddOperatorCommands(void)
{
    if (initialized)
        return 0;
    initialized = 1;
    Cmd_AddCommand("heartbeat", (void (*)(void))SV_Heartbeat_f);
    Cmd_AddCommand("onlykick", (void (*)(void))SV_Drop_f);
    Cmd_AddCommand("banUser", (void (*)(void))SV_Ban_f);
    Cmd_AddCommand("banClient", (void (*)(void))SV_BanNum_f);
    Cmd_AddCommand("kick", (void (*)(void))SV_TempBan_f);
    Cmd_AddCommand("tempBanUser", (void (*)(void))SV_TempBan_f);
    Cmd_AddCommand("tempBanClient", (void (*)(void))SV_TempBanNum_f);
    Cmd_AddCommand("unbanUser", (void (*)(void))SV_Unban_f);
    Cmd_AddCommand("clientkick", (void (*)(void))SV_DropNum_f);
    Cmd_AddCommand("status", (void (*)(void))SV_Status_f);
    Cmd_AddCommand("serverinfo", (void (*)(void))SV_Serverinfo_f);
    Cmd_AddCommand("systeminfo", (void (*)(void))SV_Systeminfo_f);
    Cmd_AddCommand("dumpuser", (void (*)(void))SV_DumpUser_f);
    Cmd_AddCommand("map_restart", (void (*)(void))SV_MapRestart_f);
    Cmd_AddCommand("fast_restart", (void (*)(void))SV_FastRestart_f);
    Cmd_AddCommand("map", (void (*)(void))SV_Map_f);
    Cmd_SetAutoComplete("map", "maps/mp", "d3dbsp");
    Cmd_AddCommand("map_rotate", (void (*)(void))SV_MapRotate_f);
    Cmd_AddCommand("gameCompleteStatus", (void (*)(void))SV_GameCompleteStatus_f);
    Cmd_AddCommand("devmap", (void (*)(void))SV_Map_f);
    Cmd_SetAutoComplete("devmap", "maps/mp", "d3dbsp");
    Cmd_AddCommand("killserver", (void (*)(void))SV_KillServer_f);
    if (*(int *)((byte *)(*(void **)imp_com_dedicated) + 8))
    {
        Cmd_AddCommand("say", (void (*)(void))SV_ConSay_f);
        Cmd_AddCommand("tell", (void (*)(void))SV_ConTell_f);
    }
    Cmd_AddCommand("scriptUsage", (void (*)(void))SV_ScriptUsage_f);
    Cmd_AddCommand("stringUsage", (void (*)(void))SV_StringUsage_f);
    return 0;
}

/* line 487 */
static __attribute__((naked))
int SV_KickUser_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 487 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl %eax, %ebx\n" /* playerName */
        "movl %edx, %edi\n" /* maxPlayerNameLen */
        /* { scope 1 */
        "movl imp_com_sv_running, %eax\n" /* line 493 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf170cd2_00170d04\n"
        "movl $str_002ac468, (%esp)\n" /* line 495 */
        "calll Com_Printf\n"
        "xorl %ebx, %ebx\n" /* cl */
        /* } scope */
        ".Lf170cd2_00170cfa:\n"
        "movl %ebx, %eax\n" /* line 522 | cl */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf170cd2_00170d04:\n"
        "calll SV_Cmd_Argc\n" /* line 499 */
        "cmpl $2, %eax\n"
        "je .Lf170cd2_00170d3a\n"
        "movl $0, (%esp)\n" /* line 501 */
        "calll SV_Cmd_Argv\n"
        "movl %eax, 8(%esp)\n" /* line 502 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002ac858, (%esp)\n" /* "Usage: %s <player name>
%s all = kick everyone
" */
        "calll Com_Printf\n"
        "xorl %ebx, %ebx\n" /* cl */
        /* } scope */
        "movl %ebx, %eax\n" /* line 522 | cl */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf170cd2_00170d3a:\n"
        "calll SV_GetPlayerByName\n" /* line 506 */
        "movl %eax, %esi\n" /* clientNum */
        "testl %eax, %eax\n" /* line 507 */
        "je .Lf170cd2_00170dcd\n"
        /* { scope 2 */
        "cmpl $2, 0x6e5c4(%eax)\n" /* line 465 */
        "je .Lf170cd2_00170da2\n"
        "testl %ebx, %ebx\n" /* line 471 | guid */
        "je .Lf170cd2_00170d74\n"
        "movl %edi, 8(%esp)\n" /* line 473 */
        "leal 0x20c48(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* guid */
        "calll I_strncpyz\n"
        "movl %ebx, (%esp)\n" /* line 474 | guid */
        "calll I_CleanStr\n"
        ".Lf170cd2_00170d74:\n"
        "movl 0x765ec(%esi), %ebx\n" /* line 476 | guid */
        "movl $str_002ac4ec, 4(%esp)\n" /* line 478 */
        "movl %esi, (%esp)\n"
        "calll SV_DropClient\n"
        "movl imp_svs, %eax\n" /* line 479 */
        "movl 4(%eax), %eax\n"
        "movl %eax, 0x20d10(%esi)\n"
        /* } scope */
        /* } scope */
        "movl %ebx, %eax\n" /* line 522 | cl */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf170cd2_00170da2:\n"
        "movl $0x65, 0xc(%esp)\n" /* line 467 */
        "movl $str_002ac4cc, 8(%esp)\n" /* "%c "EXE_CANNOTKICKHOSTPLAYER"" */
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll SV_SendServerCommand\n"
        "xorl %ebx, %ebx\n" /* guid */
        "jmp .Lf170cd2_00170cfa\n"
        /* } scope */
        ".Lf170cd2_00170dcd:\n"
        "movl $1, (%esp)\n" /* line 509 */
        "calll SV_Cmd_Argv\n"
        "movl $str_0022540c, 4(%esp)\n" /* "all" */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf170cd2_00170e77\n"
        "movl imp_svs, %edx\n" /* line 511 */
        "movl 0xc(%edx), %ebx\n" /* cl */
        "movl imp_sv_maxclients, %ecx\n"
        "movl (%ecx), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf170cd2_00170e77\n"
        "movl %edx, %edi\n" /* maxPlayerNameLen */
        "jmp .Lf170cd2_00170e3c\n"
        ".Lf170cd2_00170e0d:\n"
        "movl $str_002ac4ec, 4(%esp)\n" /* line 478 */
        "movl %ebx, (%esp)\n" /* guid */
        "calll SV_DropClient\n"
        "movl 4(%edi), %eax\n" /* line 479 */
        "movl %eax, 0x20d10(%ebx)\n" /* guid */
        "movl imp_sv_maxclients, %ecx\n"
        ".Lf170cd2_00170e2c:\n"
        "addl $1, %esi\n" /* line 511 | clientNum */
        "addl $0x78f0c, %ebx\n" /* cl */
        "movl (%ecx), %eax\n"
        "cmpl %esi, 8(%eax)\n" /* clientNum */
        "jle .Lf170cd2_00170e77\n"
        ".Lf170cd2_00170e3c:\n"
        "movl (%ebx), %eax\n" /* line 513 | cl */
        "testl %eax, %eax\n"
        "je .Lf170cd2_00170e2c\n"
        "cmpl $2, 0x6e5c4(%ebx)\n" /* line 465 | guid */
        "jne .Lf170cd2_00170e0d\n"
        "movl $0x65, 0xc(%esp)\n" /* line 467 */
        "movl $str_002ac4cc, 8(%esp)\n" /* "%c "EXE_CANNOTKICKHOSTPLAYER"" */
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll SV_SendServerCommand\n"
        "movl imp_sv_maxclients, %ecx\n"
        "jmp .Lf170cd2_00170e2c\n"
        /* { scope 2 */
        ".Lf170cd2_00170e77:\n"
        "xorl %ebx, %ebx\n" /* line 479 | guid */
        "jmp .Lf170cd2_00170cfa\n"
    );
}

/* line 559 */
static __attribute__((naked))
short int SV_TempBan_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 559 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x50, %esp\n"
        /* { scope 1 */
        "leal -0x48(%ebp), %esi\n" /* line 564 | playerName */
        "movl $0x40, %edx\n"
        "movl %esi, %eax\n"
        "calll SV_KickUser_f\n"
        "movl %eax, %ebx\n" /* guid */
        "testl %eax, %eax\n" /* line 565 */
        "je .Lf170e7e_00170eb7\n"
        "movl %eax, 8(%esp)\n" /* line 567 */
        "movl %esi, 4(%esp)\n"
        "movl $str_002ac560, (%esp)\n" /* "%s (guid %i) was kicked for cheating
" */
        "calll Com_Printf\n"
        "movl %ebx, (%esp)\n" /* line 568 | guid */
        "calll SV_BanGuidBriefly\n"
        /* } scope */
        ".Lf170e7e_00170eb7:\n"
        "addl $0x50, %esp\n" /* line 570 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 656 */
static __attribute__((naked))
short int SV_Drop_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 656 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "xorl %edx, %edx\n" /* line 658 */
        "xorl %eax, %eax\n"
        "calll SV_KickUser_f\n"
        "leave\n" /* line 659 */
        "retl\n"
    );
}

/* line 386 */
static __attribute__((naked))
short int SV_MapRotate_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 386 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl $str_002ac888, (%esp)\n" /* line 391 */
        "calll Com_Printf\n"
        "movl imp_sv_mapRotation, %ebx\n" /* line 392 | token */
        "movl (%ebx), %eax\n" /* token */
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ac898, (%esp)\n" /* ""sv_mapRotation" is:"%s"

" */
        "calll Com_Printf\n"
        "movl imp_sv_mapRotationCurrent, %esi\n" /* line 393 */
        "movl (%esi), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002ac8b4, (%esp)\n" /* ""sv_mapRotationCurrent" is:"%s"

" */
        "calll Com_Printf\n"
        "movl (%esi), %edx\n" /* line 395 */
        "movl 8(%edx), %eax\n"
        "cmpb $0, (%eax)\n"
        "je .Lf170ed0_001710d4\n"
        ".Lf170ed0_00170f29:\n"
        "movl %eax, -0x1c(%ebp)\n" /* line 365 */
        "leal -0x1c(%ebp), %edi\n" /* line 366 */
        "movl %edi, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, %ebx\n"
        "movl -0x1c(%ebp), %eax\n" /* line 367 */
        "testl %eax, %eax\n"
        "je .Lf170ed0_0017109f\n"
        "movl %eax, 4(%esp)\n" /* line 373 */
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "testl %ebx, %ebx\n" /* line 399 | token */
        "je .Lf170ed0_001710b1\n"
        ".Lf170ed0_00170f5a:\n"
        "movl $str_002aa884, 4(%esp)\n" /* line 414 */
        "movl %ebx, (%esp)\n" /* token */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf170ed0_00171032\n"
        "movl imp_sv_mapRotationCurrent, %esi\n" /* line 365 */
        "movl (%esi), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %edi, (%esp)\n" /* line 366 */
        "calll Com_Parse\n"
        "movl %eax, %ebx\n"
        "movl -0x1c(%ebp), %eax\n" /* line 367 */
        "testl %eax, %eax\n"
        "je .Lf170ed0_001710ef\n"
        "movl %eax, 4(%esp)\n" /* line 373 */
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "testl %ebx, %ebx\n" /* line 417 | token */
        "je .Lf170ed0_00171101\n"
        "movl %ebx, 4(%esp)\n" /* line 423 | token */
        "movl $str_002ac970, (%esp)\n" /* "Setting g_gametype: %s.
" */
        "calll Com_Printf\n"
        "movl imp_com_sv_running, %eax\n" /* line 424 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf170ed0_00171070\n"
        ".Lf170ed0_00170fcc:\n"
        "movl %ebx, 4(%esp)\n" /* line 428 | token */
        "movl imp_sv_gametype, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        ".Lf170ed0_00170fdf:\n"
        "movl imp_sv_mapRotationCurrent, %esi\n" /* line 365 */
        ".Lf170ed0_00170fe5:\n"
        "movl (%esi), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %edi, (%esp)\n" /* line 366 */
        "calll Com_Parse\n"
        "movl %eax, %ebx\n"
        "movl -0x1c(%ebp), %eax\n" /* line 367 */
        "testl %eax, %eax\n"
        "je .Lf170ed0_0017105c\n"
        "movl %eax, 4(%esp)\n" /* line 373 */
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "testl %ebx, %ebx\n" /* line 407 | token */
        "jne .Lf170ed0_00170f5a\n"
        ".Lf170ed0_00171014:\n"
        "movl $str_002ac8d8, (%esp)\n" /* line 409 */
        "calll Com_Printf\n"
        "movl $1, %eax\n" /* line 348 */
        "calll SV_MapRestart\n"
        /* } scope */
        ".Lf170ed0_0017102a:\n"
        "addl $0x2c, %esp\n" /* line 451 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf170ed0_00171032:\n"
        "movl $str_002ac808, 4(%esp)\n" /* line 430 */
        "movl %ebx, (%esp)\n" /* token */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf170ed0_0017111c\n"
        "movl %ebx, 4(%esp)\n" /* line 445 | token */
        "movl $str_002ac9f0, (%esp)\n" /* "Unknown keyword '%s' in sv_mapRotation.
" */
        "calll Com_Printf\n"
        "jmp .Lf170ed0_00170fdf\n"
        ".Lf170ed0_0017105c:\n"
        "movl $str_002157b8, 4(%esp)\n" /* line 369 */
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "jmp .Lf170ed0_00171014\n"
        ".Lf170ed0_00171070:\n"
        "movl %ebx, 4(%esp)\n" /* line 424 | token */
        "movl imp_sv_gametype, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf170ed0_00170fcc\n"
        "movl $0, (%esp)\n" /* line 426 */
        "calll G_SetSavePersist\n"
        "jmp .Lf170ed0_00170fcc\n"
        ".Lf170ed0_0017109f:\n"
        "movl $str_002157b8, 4(%esp)\n" /* line 369 */
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        ".Lf170ed0_001710b1:\n"
        "movl imp_sv_mapRotation, %eax\n" /* line 401 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl imp_sv_mapRotationCurrent, %esi\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "jmp .Lf170ed0_00170fe5\n"
        ".Lf170ed0_001710d4:\n"
        "movl (%ebx), %eax\n" /* line 396 | token */
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Dvar_SetString\n"
        "movl (%esi), %edx\n"
        "movl 8(%edx), %eax\n"
        "jmp .Lf170ed0_00170f29\n"
        ".Lf170ed0_001710ef:\n"
        "movl $str_002157b8, 4(%esp)\n" /* line 369 */
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        ".Lf170ed0_00171101:\n"
        "movl $str_002ac914, (%esp)\n" /* line 419 */
        "calll Com_Printf\n"
        "movl $1, %eax\n" /* line 348 */
        "calll SV_MapRestart\n"
        "jmp .Lf170ed0_0017102a\n"
        ".Lf170ed0_0017111c:\n"
        "movl imp_sv_mapRotationCurrent, %esi\n" /* line 365 */
        "movl (%esi), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %edi, (%esp)\n" /* line 366 */
        "calll Com_Parse\n"
        "movl %eax, %ebx\n"
        "movl -0x1c(%ebp), %eax\n" /* line 367 */
        "testl %eax, %eax\n"
        "je .Lf170ed0_00171182\n"
        "movl %eax, 4(%esp)\n" /* line 373 */
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "testl %ebx, %ebx\n" /* line 433 | token */
        "je .Lf170ed0_00171194\n"
        "movl %ebx, 4(%esp)\n" /* line 439 | token */
        "movl $str_002ac9dc, (%esp)\n" /* "Setting map: %s.
" */
        "calll Com_Printf\n"
        "movl %ebx, 4(%esp)\n" /* line 440 | token */
        "movl $str_002ab5ac, (%esp)\n" /* "map %s
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "jmp .Lf170ed0_0017102a\n"
        ".Lf170ed0_00171182:\n"
        "movl $str_002157b8, 4(%esp)\n" /* line 369 */
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        ".Lf170ed0_00171194:\n"
        "movl $str_002ac98c, (%esp)\n" /* line 435 */
        "calll Com_Printf\n"
        "movl $1, %eax\n" /* line 348 */
        "calll SV_MapRestart\n"
        "jmp .Lf170ed0_0017102a\n"
    );
}

