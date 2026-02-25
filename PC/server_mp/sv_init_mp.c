/* ASM dump from: sv_init_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/server_mp/sv_init_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

extern int sv_serverId_value; /* 0x0 */

Bool SV_Loaded(void);
float SV_GetConfigstring(int index, char *buffer, int bufferSize);
const char * SV_GetConfigstringConst(int index);
float SV_SetUserinfo(int index, const char *val);
float SV_GetUserinfo(int index, char *buffer, int bufferSize);
float SV_SetExpectedHunkUsage(char *mapname);
float SV_EnableArchivedSnapshot(qboolean bEnable);
float SV_InitArchivedSnapshot(void);
float SV_InitDvar(void);
float SV_Init(void);
float SV_SetConfigstring(const int index, const char *val);
float SV_SetConfigValueForKey(int start, int max, const char *key, const char *value);
float SV_Shutdown(char *finalmsg);
float SV_Startup(void);
float SV_ChangeMaxClients(void);
float SV_SpawnServer(const char *server);

/* line 1074 */
__attribute__((naked))
Bool SV_Loaded(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1074 */
        "movl %esp, %ebp\n"
        "movl 0x195ee80, %eax\n"
        "cmpl $2, (%eax)\n"
        "sete %al\n"
        "movzbl %al, %eax\n"
        "popl %ebp\n" /* line 1077 */
        "retl\n"
    );
}

/* line 140 */
__attribute__((naked))
float SV_GetConfigstring(int index, char *buffer, int bufferSize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 140 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* index */
        "movl 0xc(%ebp), %edi\n" /* buffer */
        "movl 0x10(%ebp), %esi\n" /* bufferSize */
        "testl %esi, %esi\n" /* line 142 | bufferSize */
        "jle .Lf142088_001420f0\n"
        ".Lf142088_0014209e:\n"
        "cmpl $0x7ff, %ebx\n" /* line 146 | index */
        "ja .Lf142088_001420d6\n"
        ".Lf142088_001420a6:\n"
        "movl 0x195ee80, %eax\n" /* line 150 */
        "movl 0x418(%eax, %ebx, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf142088_001420cb\n"
        "movl %esi, 0x10(%ebp)\n" /* line 156 | bufferSize */
        "movl %eax, 0xc(%ebp)\n" /* buffer */
        "movl %edi, 8(%ebp)\n" /* buffer, index */
        "addl $0x1c, %esp\n" /* line 157 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp I_strncpyz\n" /* line 156 */
        ".Lf142088_001420cb:\n"
        "movb $0, (%edi)\n" /* line 152 | buffer */
        "addl $0x1c, %esp\n" /* line 157 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf142088_001420d6:\n"
        "movl %ebx, 8(%esp)\n" /* line 148 | index */
        "movl $0x2a7054, 4(%esp)\n" /* "SV_GetConfigstring: bad index %i
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf142088_001420a6\n"
        ".Lf142088_001420f0:\n"
        "movl %esi, 8(%esp)\n" /* line 144 | bufferSize */
        "movl $0x2a702c, 4(%esp)\n" /* "SV_GetConfigstring: bufferSize == %i" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf142088_0014209e\n"
    );
}

/* line 166 */
__attribute__((naked))
const char * SV_GetConfigstringConst(int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 166 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* line 170 | index */
        "movl 0x195ee80, %eax\n"
        "movl 0x418(%eax, %edx, 4), %edx\n"
        "movl $0x2157b8, %eax\n"
        "testl %edx, %edx\n"
        "cmovnel %edx, %eax\n"
        "popl %ebp\n" /* line 171 */
        "retl\n"
    );
}

/* line 240 */
__attribute__((naked))
float SV_SetUserinfo(int index, const char *val)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 240 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* index */
        "movl 0xc(%ebp), %edi\n" /* val */
        "testl %ebx, %ebx\n" /* line 242 | index */
        "js .Lf142128_001421c7\n"
        "movl 0x195f290, %eax\n"
        "movl (%eax), %eax\n"
        "cmpl 8(%eax), %ebx\n" /* index */
        "jge .Lf142128_001421c7\n"
        ".Lf142128_0014214b:\n"
        "testl %edi, %edi\n" /* line 247 | val */
        "movl $0x2157b8, %eax\n"
        "cmovel %eax, %edi\n" /* val */
        "leal (%ebx, %ebx, 4), %eax\n" /* line 252 | index */
        "movl %eax, %edx\n"
        "shll $7, %edx\n"
        "addl %edx, %eax\n"
        "shll $6, %eax\n"
        "addl %ebx, %eax\n" /* index */
        "leal (, %eax, 4), %ebx\n" /* index */
        "subl %eax, %ebx\n" /* index */
        "shll $2, %ebx\n" /* index */
        "movl $0x400, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* val */
        "movl 0x195f284, %esi\n"
        "movl %ebx, %eax\n" /* index */
        "addl 0xc(%esi), %eax\n"
        "addl $0xc, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $0x2194b4, 4(%esp)\n" /* line 253 */
        "movl %edi, (%esp)\n" /* val */
        "calll Info_ValueForKey\n"
        "movl $0x20, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "addl 0xc(%esi), %ebx\n" /* index */
        "addl $0x20c48, %ebx\n" /* index */
        "movl %ebx, (%esp)\n" /* index */
        "calll I_strncpyz\n"
        "addl $0x1c, %esp\n" /* line 254 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf142128_001421c7:\n"
        "movl %ebx, 8(%esp)\n" /* line 244 | index */
        "movl $0x2a7078, 4(%esp)\n" /* "SV_SetUserinfo: bad index %i
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf142128_0014214b\n"
    );
}

/* line 263 */
__attribute__((naked))
float SV_GetUserinfo(int index, char *buffer, int bufferSize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 263 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* index */
        "movl 0xc(%ebp), %edi\n" /* buffer */
        "movl 0x10(%ebp), %esi\n" /* bufferSize */
        "testl %esi, %esi\n" /* line 265 | bufferSize */
        "jle .Lf1421e4_0014225b\n"
        ".Lf1421e4_001421fa:\n"
        "testl %ebx, %ebx\n" /* line 269 | index */
        "js .Lf1421e4_0014220a\n"
        "movl 0x195f290, %eax\n"
        "movl (%eax), %eax\n"
        "cmpl 8(%eax), %ebx\n" /* index */
        "jl .Lf1421e4_00142222\n"
        ".Lf1421e4_0014220a:\n"
        "movl %ebx, 8(%esp)\n" /* line 271 | index */
        "movl $0x2a70bc, 4(%esp)\n" /* "SV_GetUserinfo: bad index %i
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf1421e4_00142222:\n"
        "movl %esi, 0x10(%ebp)\n" /* line 273 | bufferSize */
        "leal (%ebx, %ebx, 4), %eax\n" /* index */
        "movl %eax, %edx\n"
        "shll $7, %edx\n"
        "addl %edx, %eax\n"
        "shll $6, %eax\n"
        "addl %ebx, %eax\n" /* index */
        "leal (, %eax, 4), %edx\n"
        "subl %eax, %edx\n"
        "movl 0x195f284, %eax\n"
        "movl 0xc(%eax), %eax\n"
        "leal 0xc(%eax, %edx, 4), %edx\n"
        "movl %edx, 0xc(%ebp)\n" /* buffer */
        "movl %edi, 8(%ebp)\n" /* buffer, index */
        "addl $0x1c, %esp\n" /* line 274 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp I_strncpyz\n" /* line 273 */
        ".Lf1421e4_0014225b:\n"
        "movl %esi, 8(%esp)\n" /* line 267 | bufferSize */
        "movl $0x2a7098, 4(%esp)\n" /* "SV_GetUserinfo: bufferSize == %i" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1421e4_001421fa\n"
    );
}

/* line 491 */
__attribute__((naked))
float SV_SetExpectedHunkUsage(char *mapname)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 491 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl $0, 8(%esp)\n" /* line 500 */
        "leal -0x1c(%ebp), %eax\n" /* handle */
        "movl %eax, 4(%esp)\n"
        "movl $0x2a70ec, (%esp)\n" /* "hunkusage.dat" */
        "calll FS_FOpenFileByMode\n"
        "movl %eax, %esi\n" /* len */
        "testl %eax, %eax\n" /* line 501 */
        "js .Lf142278_00142343\n"
        "leal 1(%eax), %ebx\n" /* line 504 */
        "movl %ebx, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, %edi\n" /* buf */
        "movl %ebx, 8(%esp)\n" /* line 505 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl -0x1c(%ebp), %eax\n" /* line 507 | handle */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* len */
        "movl %edi, (%esp)\n" /* buf */
        "calll FS_Read\n"
        "movl -0x1c(%ebp), %eax\n" /* line 508 | handle */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movl %edi, -0x20(%ebp)\n" /* line 511 | buf, buftrav */
        "leal -0x20(%ebp), %ebx\n" /* buftrav */
        ".Lf142278_001422eb:\n"
        "movl %ebx, (%esp)\n" /* line 512 */
        "calll Com_Parse\n"
        "testl %eax, %eax\n"
        "je .Lf142278_0014234b\n"
        "cmpb $0, (%eax)\n"
        "je .Lf142278_0014234b\n"
        "movl 8(%ebp), %edx\n" /* line 514 | mapname */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf142278_001422eb\n"
        "movl %ebx, (%esp)\n" /* line 517 */
        "calll Com_Parse\n"
        "testl %eax, %eax\n" /* line 518 */
        "je .Lf142278_001422eb\n"
        "cmpb $0, (%eax)\n"
        "je .Lf142278_001422eb\n"
        "movl %eax, (%esp)\n" /* line 521 */
        "calll atoi\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x195f2fc, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movl %edi, (%esp)\n" /* line 522 | buf */
        "calll Z_FreeInternal\n"
        /* } scope */
        ".Lf142278_00142343:\n"
        "addl $0x2c, %esp\n" /* line 530 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf142278_0014234b:\n"
        "movl %edi, (%esp)\n" /* line 528 | buf */
        "calll Z_FreeInternal\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 530 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 564 */
__attribute__((naked))
float SV_EnableArchivedSnapshot(qboolean bEnable)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 564 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* bEnable */
        "movl 0x195f284, %ebx\n" /* line 566 */
        "movl %eax, 0x28(%ebx)\n"
        "testl %eax, %eax\n" /* line 567 */
        "je .Lf14235e_0014237c\n"
        "movl 0x30(%ebx), %eax\n" /* line 570 */
        "testl %eax, %eax\n"
        "je .Lf14235e_00142382\n"
        ".Lf14235e_0014237c:\n"
        "addl $0x14, %esp\n" /* line 590 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf14235e_00142382:\n"
        "movl $0x450000, (%esp)\n" /* line 581 */
        "calll Z_MallocInternal\n"
        "movl %eax, 0x48(%ebx)\n"
        "movl $0x2708000, (%esp)\n" /* line 583 */
        "calll Z_MallocInternal\n"
        "movl %eax, 0x4c(%ebx)\n"
        "movl $0x2580, (%esp)\n" /* line 585 */
        "calll Z_MallocInternal\n"
        "movl %eax, 0x30(%ebx)\n"
        "movl $0x2000000, (%esp)\n" /* line 587 */
        "calll Z_MallocInternal\n"
        "movl %eax, 0x34(%ebx)\n"
        "movl $0x3800, (%esp)\n" /* line 589 */
        "calll Z_MallocInternal\n"
        "movl %eax, 0x50(%ebx)\n"
        "addl $0x14, %esp\n" /* line 590 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 599 */
__attribute__((naked))
float SV_InitArchivedSnapshot(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 599 */
        "movl %esp, %ebp\n"
        "movl 0x195f284, %eax\n" /* line 601 */
        "movl $0, 0x28(%eax)\n"
        "movl $0, 0x2c(%eax)\n" /* line 602 */
        "movl $0, 0x38(%eax)\n" /* line 603 */
        "movl $0, 0x3c(%eax)\n" /* line 604 */
        "movl $0, 0x40(%eax)\n" /* line 605 */
        "movl $0, 0x44(%eax)\n" /* line 606 */
        "popl %ebp\n" /* line 607 */
        "retl\n"
    );
}

/* line 655 */
__attribute__((naked))
float SV_InitDvar(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 655 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 658 */
        "jmp Dvar_ResetScriptInfo\n" /* line 657 */
    );
}

/* line 1198 */
__attribute__((naked))
float SV_Init(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1198 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "calll SV_AddOperatorCommands\n" /* line 1203 */
        "movl $0x1024, 8(%esp)\n" /* line 1206 */
        "movl $0x2a70fc, 4(%esp)\n" /* "dm" */
        "movl $0x2a7100, (%esp)\n" /* "g_gametype" */
        "calll Dvar_RegisterString\n"
        "movl 0x195f29c, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x1004, 8(%esp)\n" /* line 1208 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x2a710c, (%esp)\n" /* "sv_keywords" */
        "calll Dvar_RegisterString\n"
        "movl $0x1044, 0x10(%esp)\n" /* line 1209 */
        "movl $0x73, 0xc(%esp)\n"
        "movl $0x73, 8(%esp)\n"
        "movl $0x73, 4(%esp)\n"
        "movl $0x2a7118, (%esp)\n" /* "protocol" */
        "calll Dvar_RegisterInt\n"
        "movl $0x1044, 8(%esp)\n" /* line 1211 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x2a7124, (%esp)\n" /* "mapname" */
        "calll Dvar_RegisterString\n"
        "movl 0x195f300, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x1004, 0x10(%esp)\n" /* line 1216 */
        "movl $0x40, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x2a712c, (%esp)\n" /* "sv_privateClients" */
        "calll Dvar_RegisterInt\n"
        "movl 0x195f2c0, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x1025, 0x10(%esp)\n" /* line 1217 */
        "movl $0x40, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0x14, 4(%esp)\n"
        "movl $0x2a70dc, (%esp)\n" /* "sv_maxclients" */
        "calll Dvar_RegisterInt\n"
        "movl 0x195f290, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x1005, 8(%esp)\n" /* line 1219 */
        "movl $0x2a7140, 4(%esp)\n" /* "CoD2Host" */
        "movl $0x2a714c, (%esp)\n" /* "sv_hostname" */
        "calll Dvar_RegisterString\n"
        "movl 0x195f2b8, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x1005, 0x10(%esp)\n" /* line 1221 */
        "movl $0x61a8, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x2a7158, (%esp)\n" /* "sv_maxRate" */
        "calll Dvar_RegisterInt\n"
        "movl 0x195f268, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x1005, 0x10(%esp)\n" /* line 1222 */
        "movl $0x3e7, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x2a7164, (%esp)\n" /* "sv_minPing" */
        "calll Dvar_RegisterInt\n"
        "movl 0x195f2e8, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x1005, 0x10(%esp)\n" /* line 1223 */
        "movl $0x3e7, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x2a7170, (%esp)\n" /* "sv_maxPing" */
        "calll Dvar_RegisterInt\n"
        "movl 0x195f298, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x1005, 8(%esp)\n" /* line 1224 */
        "movl $1, 4(%esp)\n"
        "movl $0x2a717c, (%esp)\n" /* "sv_floodProtect" */
        "calll Dvar_RegisterBool\n"
        "movl 0x195f2dc, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x1004, 8(%esp)\n" /* line 1225 */
        "movl $0, 4(%esp)\n"
        "movl $0x2a718c, (%esp)\n" /* "sv_allowAnonymous" */
        "calll Dvar_RegisterBool\n"
        "movl 0x195f26c, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 1226 */
        "movl $0, 4(%esp)\n"
        "movl $0x2a71a0, (%esp)\n" /* "sv_showCommands" */
        "calll Dvar_RegisterBool\n"
        "movl 0x195f2cc, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x1008, 8(%esp)\n" /* line 1228 */
        "movl $0, 4(%esp)\n"
        "movl $0x2a71b0, (%esp)\n" /* "sv_disableClientConsole" */
        "calll Dvar_RegisterBool\n"
        "movl 0x195f264, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x100d, 8(%esp)\n" /* line 1231 */
        "movl $0, 4(%esp)\n"
        "movl $0x2a71c8, (%esp)\n" /* "sv_voice" */
        "calll Dvar_RegisterBool\n"
        "movl 0x195f2a4, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x1008, 0x10(%esp)\n" /* line 1232 */
        "movl $9, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $0x2a71d4, (%esp)\n" /* "sv_voiceQuality" */
        "calll Dvar_RegisterInt\n"
        "movl 0x195f2d0, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x1018, 8(%esp)\n" /* line 1236 */
        "movl $0, 4(%esp)\n"
        "movl $0x2198ac, (%esp)\n" /* "sv_cheats" */
        "calll Dvar_RegisterBool\n"
        "movl 0x195ef54, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x1048, 0x10(%esp)\n" /* line 1237 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0x80000000, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x2a71e4, (%esp)\n" /* "sv_serverid" */
        "calll Dvar_RegisterInt\n"
        "movl 0x195f294, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x100c, 8(%esp)\n" /* line 1240 */
        "movl $1, 4(%esp)\n"
        "movl $0x2a71f0, (%esp)\n" /* "sv_pure" */
        "calll Dvar_RegisterBool\n"
        "movl 0x195f2e0, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x1048, 8(%esp)\n" /* line 1244 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x2a71f8, (%esp)\n" /* "sv_iwds" */
        "calll Dvar_RegisterString\n"
        "movl 0x195f28c, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x1048, 8(%esp)\n" /* line 1245 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x2a7200, (%esp)\n" /* "sv_iwdNames" */
        "calll Dvar_RegisterString\n"
        "movl 0x195f270, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x1048, 8(%esp)\n" /* line 1246 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x2a720c, (%esp)\n" /* "sv_referencedIwds" */
        "calll Dvar_RegisterString\n"
        "movl 0x195f2d4, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x1048, 8(%esp)\n" /* line 1247 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x2a7220, (%esp)\n" /* "sv_referencedIwdNames" */
        "calll Dvar_RegisterString\n"
        "movl 0x195f2c4, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 1252 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x2a7238, (%esp)\n" /* "rcon_password" */
        "calll Dvar_RegisterString\n"
        "movl 0x195f2f4, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 1255 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x2a7248, (%esp)\n" /* "sv_privatePassword" */
        "calll Dvar_RegisterString\n"
        "movl 0x195f280, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 1259 */
        "movl $0x3e8, 0xc(%esp)\n"
        "movl $0xa, 8(%esp)\n"
        "movl $0x14, 4(%esp)\n"
        "movl $0x2a725c, (%esp)\n" /* "sv_fps" */
        "calll Dvar_RegisterInt\n"
        "movl 0x195f2f8, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 1265 */
        "movl $0x708, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0xf0, 4(%esp)\n"
        "movl $0x2a7264, (%esp)\n" /* "sv_timeout" */
        "calll Dvar_RegisterInt\n"
        "movl 0x195f2e4, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 1268 */
        "movl $0x708, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl $0x2a7270, (%esp)\n" /* "sv_zombietime" */
        "calll Dvar_RegisterInt\n"
        "movl 0x195f2c8, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x1001, 8(%esp)\n" /* line 1270 */
        "movl $1, 4(%esp)\n"
        "movl $0x2a7280, (%esp)\n" /* "sv_allowDownload" */
        "calll Dvar_RegisterBool\n"
        "movl 0x195f2b4, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 1271 */
        "movl $0x708, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl $0x2a7294, (%esp)\n" /* "sv_reconnectlimit" */
        "calll Dvar_RegisterInt\n"
        "movl 0x195f2a0, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 1272 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x2a72a8, (%esp)\n" /* "sv_padPackets" */
        "calll Dvar_RegisterInt\n"
        "movl 0x195f2b0, %edx\n"
        "movl %eax, (%edx)\n"
        "movl 0x195ecb4, %eax\n" /* line 1273 */
        "movl (%eax), %eax\n"
        "movb $0, 0xdd(%eax)\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 1275 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x2a72b8, (%esp)\n" /* "sv_allowedClan1" */
        "calll Dvar_RegisterString\n"
        "movl 0x195f27c, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 1276 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x2a72c8, (%esp)\n" /* "sv_allowedClan2" */
        "calll Dvar_RegisterString\n"
        "movl 0x195f274, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 1278 */
        "movl $0, 4(%esp)\n"
        "movl $0x2a72d8, (%esp)\n" /* "sv_packet_info" */
        "calll Dvar_RegisterBool\n"
        "movl 0x195f2a8, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 1280 */
        "movl $0, 4(%esp)\n"
        "movl $0x2a72e8, (%esp)\n" /* "sv_showAverageBPS" */
        "calll Dvar_RegisterBool\n"
        "movl 0x195f288, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 1282 */
        "movl $0x45610000, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x43960000, 4(%esp)\n"
        "movl $0x2a72fc, (%esp)\n" /* "sv_kickBanTime" */
        "calll Dvar_RegisterFloat\n"
        "movl 0x195f2f0, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 1288 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x2a730c, (%esp)\n" /* "sv_mapRotation" */
        "calll Dvar_RegisterString\n"
        "movl 0x195f2ec, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 1289 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x2a731c, (%esp)\n" /* "sv_mapRotationCurrent" */
        "calll Dvar_RegisterString\n"
        "movl 0x195f2ac, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 1291 */
        "movl $0, 4(%esp)\n"
        "movl $0x2a7334, (%esp)\n" /* "sv_debugRate" */
        "calll Dvar_RegisterBool\n"
        "movl 0x195f2bc, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 1292 */
        "movl $0, 4(%esp)\n"
        "movl $0x2a7344, (%esp)\n" /* "sv_debugReliableCmds" */
        "calll Dvar_RegisterBool\n"
        "movl 0x195f278, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 1294 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x2a735c, (%esp)\n" /* "nextmap" */
        "calll Dvar_RegisterString\n"
        "movl 0x195ee88, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x1040, 0x10(%esp)\n" /* line 1296 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x2a7364, (%esp)\n" /* "com_expectedHunkUsage" */
        "calll Dvar_RegisterInt\n"
        "movl 0x195f2fc, %edx\n"
        "movl %eax, (%edx)\n"
        "leave\n" /* line 1320 */
        "retl\n"
    );
}

/* line 49 */
__attribute__((naked))
float SV_SetConfigstring(const int index, const char *val)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 49 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x44c, %esp\n"
        /* { scope 1 */
        "cmpl $0x7ff, 8(%ebp)\n" /* line 61 | index */
        "ja .Lf142af6_00142ca9\n"
        ".Lf142af6_00142b0f:\n"
        "movl 0xc(%ebp), %eax\n" /* line 66 | val */
        "testl %eax, %eax\n"
        "movl $0x2157b8, %eax\n"
        "cmovnel 0xc(%ebp), %eax\n" /* val */
        "movl %eax, 0xc(%ebp)\n" /* val */
        "movl 0x195ee80, %ebx\n" /* line 71 | remaining */
        "movl 8(%ebp), %edx\n" /* index */
        "movl 0x418(%ebx, %edx, 4), %eax\n" /* remaining */
        "testl %eax, %eax\n"
        "je .Lf142af6_00142b47\n"
        "movl %eax, 4(%esp)\n" /* line 75 */
        "movl 0xc(%ebp), %ecx\n" /* val */
        "movl %ecx, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "jne .Lf142af6_00142b52\n"
        /* } scope */
        ".Lf142af6_00142b47:\n"
        "addl $0x44c, %esp\n" /* line 131 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf142af6_00142b52:\n"
        "movl 0xc(%ebp), %eax\n" /* line 81 | val */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* index */
        "leal 0x418(%ebx, %edx, 4), %eax\n" /* remaining */
        "movl %eax, (%esp)\n"
        "calll ReplaceStringInternal\n"
        "cmpl $2, (%ebx)\n" /* line 85 | remaining */
        "je .Lf142af6_00142b77\n"
        "movl 4(%ebx), %eax\n" /* remaining */
        "testl %eax, %eax\n"
        "je .Lf142af6_00142b47\n"
        ".Lf142af6_00142b77:\n"
        "movl $0xffffffff, %esi\n" /* line 88 | sent */
        "xorl %ebx, %ebx\n" /* remaining */
        "cld\n"
        "movl %esi, %ecx\n" /* sent */
        "movl 0xc(%ebp), %edi\n" /* val, client */
        "movl %ebx, %eax\n" /* remaining */
        "repne scasb %es:(%edi), %al\n" /* client */
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x42c(%ebp)\n" /* len */
        "movl 8(%ebp), %edx\n" /* line 90 | index */
        "movl %edx, 8(%esp)\n"
        "movl $0x21785c, 4(%esp)\n" /* "%i" */
        "leal -0x418(%ebp), %ecx\n" /* buf */
        "movl %ecx, (%esp)\n"
        "calll sprintf\n"
        "cld\n" /* line 92 */
        "movl %esi, %ecx\n" /* sent */
        "leal -0x418(%ebp), %edi\n" /* buf, client */
        "movl %ebx, %eax\n" /* remaining */
        "repne scasb %es:(%edi), %al\n" /* client */
        "notl %ecx\n"
        "movl $0x3fd, -0x424(%ebp)\n" /* maxChunk */
        "subl %ecx, -0x424(%ebp)\n" /* maxChunk */
        "movl 0x195f284, %eax\n" /* line 96 */
        "movl 0xc(%eax), %edi\n" /* client */
        "movl 0x195f290, %edx\n"
        "movl (%edx), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf142af6_00142b47\n"
        "movl $0, -0x428(%ebp)\n" /* i */
        ".Lf142af6_00142bf4:\n"
        "cmpl $2, (%edi)\n" /* line 98 | client */
        "jle .Lf142af6_00142d19\n"
        "movl -0x424(%ebp), %ecx\n" /* line 101 | maxChunk */
        "cmpl %ecx, -0x42c(%ebp)\n" /* len */
        "jle .Lf142af6_00142ce5\n"
        "movl -0x42c(%ebp), %eax\n" /* line 106 | len */
        "testl %eax, %eax\n"
        "jle .Lf142af6_00142d19\n"
        "addl $1, %ecx\n"
        "movl %ecx, -0x41c(%ebp)\n"
        "movl -0x42c(%ebp), %ebx\n" /* len, remaining */
        "movb $0x78, -0x41d(%ebp)\n" /* cmd */
        "xorl %esi, %esi\n" /* sent */
        "movl %ecx, %eax\n"
        ".Lf142af6_00142c37:\n"
        "movl %eax, 8(%esp)\n" /* line 116 */
        "movl 0xc(%ebp), %eax\n" /* val */
        "addl %esi, %eax\n" /* sent */
        "movl %eax, 4(%esp)\n"
        "leal -0x418(%ebp), %edx\n" /* buf */
        "movl %edx, (%esp)\n"
        "calll I_strncpyz\n"
        "leal -0x418(%ebp), %ecx\n" /* line 119 | buf */
        "movl %ecx, 0x14(%esp)\n"
        "movl 8(%ebp), %eax\n" /* index */
        "movl %eax, 0x10(%esp)\n"
        "movsbl -0x41d(%ebp), %eax\n" /* cmd */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x2a73a8, 8(%esp)\n" /* "%c %i %s" */
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* client */
        "calll SV_SendServerCommand\n"
        "addl -0x424(%ebp), %esi\n" /* line 121 | maxChunk, sent */
        "subl -0x424(%ebp), %ebx\n" /* line 122 | maxChunk, remaining */
        "testl %ebx, %ebx\n" /* line 106 | remaining */
        "jle .Lf142af6_00142d13\n"
        "testl %esi, %esi\n" /* line 108 | sent */
        "jne .Lf142af6_00142cc9\n"
        "movb $0x78, -0x41d(%ebp)\n" /* cmd */
        "movl -0x41c(%ebp), %eax\n"
        "jmp .Lf142af6_00142c37\n"
        ".Lf142af6_00142ca9:\n"
        "movl 8(%ebp), %eax\n" /* line 63 | index */
        "movl %eax, 8(%esp)\n"
        "movl $0x2a7384, 4(%esp)\n" /* "SV_SetConfigstring: bad index %i
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf142af6_00142b0f\n"
        ".Lf142af6_00142cc9:\n"
        "cmpl %ebx, -0x424(%ebp)\n" /* line 110 | remaining, maxChunk */
        "setge %al\n"
        "addb $0x79, %al\n"
        "movb %al, -0x41d(%ebp)\n" /* cmd */
        "movl -0x41c(%ebp), %eax\n"
        "jmp .Lf142af6_00142c37\n"
        ".Lf142af6_00142ce5:\n"
        "movl 0xc(%ebp), %edx\n" /* line 128 | val */
        "movl %edx, 0x14(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* index */
        "movl %ecx, 0x10(%esp)\n"
        "movl $0x64, 0xc(%esp)\n"
        "movl $0x2a73a8, 8(%esp)\n" /* "%c %i %s" */
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* client */
        "calll SV_SendServerCommand\n"
        ".Lf142af6_00142d13:\n"
        "movl 0x195f290, %edx\n"
        ".Lf142af6_00142d19:\n"
        "addl $1, -0x428(%ebp)\n" /* line 96 | i */
        "addl $0x78f0c, %edi\n" /* client */
        "movl (%edx), %eax\n"
        "movl -0x428(%ebp), %ecx\n" /* i */
        "cmpl 8(%eax), %ecx\n"
        "jl .Lf142af6_00142bf4\n"
        /* } scope */
        "addl $0x44c, %esp\n" /* line 131 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 208 */
__attribute__((naked))
float SV_SetConfigValueForKey(int start, int max, const char *key, const char *value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 208 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* start */
        "movl %eax, -0x1c(%ebp)\n" /* start */
        "movl 0xc(%ebp), %edi\n" /* max */
        "movl 0x10(%ebp), %edx\n" /* key */
        "movl %edx, -0x20(%ebp)\n" /* key */
        "movl 0x14(%ebp), %ecx\n" /* value */
        "movl %ecx, -0x24(%ebp)\n" /* value */
        /* { scope 1 */
        "testl %edi, %edi\n" /* line 213 | max */
        "jle .Lf142d42_00142de2\n"
        "movl %eax, %ecx\n"
        "movl 0x195ee80, %edx\n" /* line 215 */
        "movl 0x418(%edx, %eax, 4), %eax\n"
        "cmpb $0, (%eax)\n" /* line 216 */
        "je .Lf142d42_00142e05\n"
        "leal 0x418(%edx, %ecx, 4), %esi\n"
        "xorl %ebx, %ebx\n" /* i */
        "jmp .Lf142d42_00142d97\n"
        ".Lf142d42_00142d87:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 213 | start */
        "addl %ebx, %edx\n" /* i */
        "movl 4(%esi), %eax\n" /* line 215 */
        "addl $4, %esi\n"
        "cmpb $0, (%eax)\n" /* line 216 */
        "je .Lf142d42_00142e09\n"
        ".Lf142d42_00142d97:\n"
        "movl %eax, 4(%esp)\n" /* line 221 */
        "movl -0x20(%ebp), %edx\n" /* key */
        "movl %edx, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf142d42_00142de4\n"
        "addl $1, %ebx\n" /* line 213 | i */
        "cmpl %ebx, %edi\n" /* i, max */
        "jne .Lf142d42_00142d87\n"
        ".Lf142d42_00142db1:\n"
        "movl $0x2a73b4, 4(%esp)\n" /* line 228 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl -0x24(%ebp), %ecx\n" /* line 230 | value */
        "movl %ecx, 0xc(%ebp)\n" /* max */
        "movl -0x1c(%ebp), %edx\n" /* start */
        "leal (%edi, %edx), %eax\n" /* max */
        "addl %ebx, %eax\n" /* i */
        "movl %eax, 8(%ebp)\n" /* start */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 231 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp SV_SetConfigstring\n" /* line 230 */
        ".Lf142d42_00142de2:\n"
        "xorl %ebx, %ebx\n" /* line 213 | i */
        ".Lf142d42_00142de4:\n"
        "cmpl %ebx, %edi\n" /* line 227 | i, max */
        "je .Lf142d42_00142db1\n"
        "movl -0x24(%ebp), %ecx\n" /* line 230 | value */
        "movl %ecx, 0xc(%ebp)\n" /* max */
        "movl -0x1c(%ebp), %edx\n" /* start */
        "leal (%edi, %edx), %eax\n" /* max */
        "addl %ebx, %eax\n" /* i */
        "movl %eax, 8(%ebp)\n" /* start */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 231 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp SV_SetConfigstring\n" /* line 230 */
        ".Lf142d42_00142e05:\n"
        "movl %ecx, %edx\n" /* line 216 */
        "xorl %ebx, %ebx\n" /* i */
        ".Lf142d42_00142e09:\n"
        "movl -0x20(%ebp), %eax\n" /* line 218 | key */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "jmp .Lf142d42_00142de4\n"
    );
}

/* line 1390 */
__attribute__((naked))
float SV_Shutdown(char *finalmsg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1390 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 0x195ecbc, %eax\n" /* line 1399 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf142e1a_00142e34\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf142e1a_00142e3c\n"
        ".Lf142e1a_00142e34:\n"
        "addl $0x3c, %esp\n" /* line 1459 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf142e1a_00142e3c:\n"
        "movl $0x2a73d8, (%esp)\n" /* line 1402 */
        "calll Com_Printf\n"
        "movl 0x195ee80, %eax\n" /* line 1404 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0x195f284, %eax\n" /* line 1406 */
        "movl 0xc(%eax), %edi\n" /* j */
        "testl %edi, %edi\n" /* j */
        "je .Lf142e1a_00142f10\n"
        "xorl %edi, %edi\n" /* j */
        "movl 0x195f290, %edx\n"
        /* { scope 1 */
        ".Lf142e1a_00142e6a:\n"
        "movl 0xc(%eax), %ebx\n" /* line 1341 | cl */
        "movl (%edx), %eax\n"
        "movl 8(%eax), %esi\n" /* i */
        "testl %esi, %esi\n" /* i */
        "jle .Lf142e1a_00142f04\n"
        "xorl %esi, %esi\n" /* i */
        ".Lf142e1a_00142e7c:\n"
        "cmpl $1, (%ebx)\n" /* line 1343 | cl */
        "jle .Lf142e1a_00142ef0\n"
        "cmpl $2, 0x6e5c4(%ebx)\n" /* line 1346 | cl */
        "je .Lf142e1a_00142ed8\n"
        "movl 8(%ebp), %eax\n" /* line 1348 | finalmsg */
        "movl %eax, 0x10(%esp)\n"
        "movl $0x65, 0xc(%esp)\n"
        "movl $0x2a737c, 8(%esp)\n" /* "%c "%s"" */
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* cl */
        "calll SV_SendServerCommand\n"
        "movl 8(%ebp), %eax\n" /* line 1349 | finalmsg */
        "movl %eax, 0x10(%esp)\n"
        "movl $0x77, 0xc(%esp)\n"
        "movl $0x2a737c, 8(%esp)\n" /* "%c "%s"" */
        "movl $1, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* cl */
        "calll SV_SendServerCommand\n"
        ".Lf142e1a_00142ed8:\n"
        "movl $0xffffffff, 0x20d18(%ebx)\n" /* line 1352 | cl */
        "movl %ebx, (%esp)\n" /* line 1353 | cl */
        "calll SV_SendClientSnapshot\n"
        "movl 0x195f290, %edx\n"
        ".Lf142e1a_00142ef0:\n"
        "addl $1, %esi\n" /* line 1341 | i */
        "addl $0x78f0c, %ebx\n" /* cl */
        "movl (%edx), %eax\n"
        "cmpl 8(%eax), %esi\n" /* i */
        "jl .Lf142e1a_00142e7c\n"
        ".Lf142e1a_00142f04:\n"
        "addl $1, %edi\n" /* line 1339 | j */
        "cmpl $2, %edi\n" /* j */
        "jne .Lf142e1a_001430ae\n"
        /* } scope */
        ".Lf142e1a_00142f10:\n"
        "calll SV_RemoveOperatorCommands\n" /* line 1409 */
        "calll SV_MasterShutdown\n" /* line 1410 */
        "calll SV_ShutdownGameProgs\n" /* line 1411 */
        "movl 0x195f284, %eax\n" /* line 1373 */
        "movl 0xc(%eax), %ebx\n" /* cl */
        "movl 0x195f290, %edx\n"
        "movl (%edx), %eax\n"
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lf142e1a_00142f61\n"
        "xorl %esi, %esi\n" /* i */
        "movl %edx, %edi\n" /* j */
        ".Lf142e1a_00142f3a:\n"
        "cmpl $1, (%ebx)\n" /* line 1375 | cl */
        "jle .Lf142e1a_00142f51\n"
        "movl $0x215fa4, 4(%esp)\n" /* line 1377 */
        "movl %ebx, (%esp)\n" /* cl */
        "calll SV_DropClient\n"
        "movl %edi, %edx\n" /* j */
        ".Lf142e1a_00142f51:\n"
        "addl $1, %esi\n" /* line 1373 | i */
        "addl $0x78f0c, %ebx\n" /* cl */
        "movl (%edx), %eax\n"
        "cmpl 8(%eax), %esi\n" /* i */
        "jl .Lf142e1a_00142f3a\n"
        ".Lf142e1a_00142f61:\n"
        "movl 0x195ee80, %edx\n"
        "movl %edx, %ebx\n" /* cl */
        "movl %edx, %esi\n" /* i */
        ".Lf142e1a_00142f6b:\n"
        "movl 0x418(%ebx), %eax\n" /* line 545 */
        "testl %eax, %eax\n"
        "je .Lf142e1a_00142f7f\n"
        "movl %eax, (%esp)\n" /* line 547 */
        "calll Z_FreeInternal\n"
        "movl %esi, %edx\n"
        ".Lf142e1a_00142f7f:\n"
        "addl $4, %ebx\n"
        "leal 0x2000(%edx), %eax\n" /* line 1390 */
        "cmpl %ebx, %eax\n" /* line 543 */
        "jne .Lf142e1a_00142f6b\n"
        "movl $0x5f534, 8(%esp)\n" /* line 550 */
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Com_Memset\n"
        "movl 0x195f284, %ebx\n" /* line 1427 | cl */
        "movl 0xc(%ebx), %eax\n" /* cl */
        "testl %eax, %eax\n"
        "je .Lf142e1a_00142fb6\n"
        "calll SV_FreeClients\n" /* line 1428 */
        ".Lf142e1a_00142fb6:\n"
        "movl 0x48(%ebx), %eax\n" /* line 618 */
        "testl %eax, %eax\n"
        "je .Lf142e1a_00142fcc\n"
        "movl %eax, (%esp)\n" /* line 620 */
        "calll Z_FreeInternal\n"
        "movl $0, 0x48(%ebx)\n" /* line 621 */
        ".Lf142e1a_00142fcc:\n"
        "movl 0x4c(%ebx), %eax\n" /* line 624 */
        "testl %eax, %eax\n"
        "je .Lf142e1a_00142fe2\n"
        "movl %eax, (%esp)\n" /* line 626 */
        "calll Z_FreeInternal\n"
        "movl $0, 0x4c(%ebx)\n" /* line 627 */
        ".Lf142e1a_00142fe2:\n"
        "movl 0x30(%ebx), %eax\n" /* line 630 */
        "testl %eax, %eax\n"
        "je .Lf142e1a_00142ff8\n"
        "movl %eax, (%esp)\n" /* line 632 */
        "calll Z_FreeInternal\n"
        "movl $0, 0x30(%ebx)\n" /* line 633 */
        ".Lf142e1a_00142ff8:\n"
        "movl 0x34(%ebx), %eax\n" /* line 636 */
        "testl %eax, %eax\n"
        "je .Lf142e1a_0014300e\n"
        "movl %eax, (%esp)\n" /* line 638 */
        "calll Z_FreeInternal\n"
        "movl $0, 0x34(%ebx)\n" /* line 639 */
        ".Lf142e1a_0014300e:\n"
        "movl 0x50(%ebx), %eax\n" /* line 642 */
        "testl %eax, %eax\n"
        "je .Lf142e1a_00143024\n"
        "movl %eax, (%esp)\n" /* line 644 */
        "calll Z_FreeInternal\n"
        "movl $0, 0x50(%ebx)\n" /* line 645 */
        ".Lf142e1a_00143024:\n"
        "movl $0xa0f8, 8(%esp)\n" /* line 1432 */
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* cl */
        "calll memset\n"
        "movl 0x195ec98, %eax\n" /* line 1434 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf142e1a_001430b8\n"
        ".Lf142e1a_0014304a:\n"
        "movl $0, 4(%esp)\n" /* line 1437 */
        "movl 0x195ecbc, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetBool\n"
        "movl $0x2a73f8, (%esp)\n" /* line 1439 */
        "calll Com_Printf\n"
        "movl $0, (%esp)\n" /* line 1445 */
        "calll CL_GetLocalClientActive\n"
        "testb %al, %al\n"
        "jne .Lf142e1a_001430bf\n"
        ".Lf142e1a_0014307d:\n"
        "cmpl $1, -0x1c(%ebp)\n" /* line 1450 */
        "jne .Lf142e1a_00142e34\n"
        "calll Com_AbortDObj\n" /* line 1453 */
        "calll DObjAbort\n" /* line 1454 */
        "calll XAnimAbort\n" /* line 1455 */
        "calll Scr_Abort\n" /* line 1456 */
        "movl 0x195edb4, %eax\n" /* line 1458 */
        "movl $0, (%eax)\n"
        "addl $0x3c, %esp\n" /* line 1459 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf142e1a_001430ae:\n"
        "movl 0x195f284, %eax\n"
        "jmp .Lf142e1a_00142e6a\n"
        ".Lf142e1a_001430b8:\n"
        "calll FX_FreeSystem\n" /* line 1435 */
        "jmp .Lf142e1a_0014304a\n"
        ".Lf142e1a_001430bf:\n"
        "calll CL_Disconnect\n" /* line 1446 */
        "jmp .Lf142e1a_0014307d\n"
    );
}

/* line 365 */
__attribute__((naked))
float SV_Startup(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 365 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 0x195f284, %esi\n" /* line 367 */
        "movl (%esi), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf1430c6_001431bf\n"
        ".Lf1430c6_001430de:\n"
        "movl $0x1025, 0x10(%esp)\n" /* line 325 */
        "movl $0x40, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0x14, 4(%esp)\n"
        "movl $0x2a70dc, (%esp)\n" /* "sv_maxclients" */
        "calll Dvar_RegisterInt\n"
        "movl 0x195f290, %ebx\n"
        "movl %eax, (%ebx)\n"
        "movl %eax, (%esp)\n" /* line 327 */
        "calll Dvar_ClearModified\n"
        "movl (%ebx), %eax\n" /* line 329 */
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf1430c6_001431d8\n"
        ".Lf1430c6_00143127:\n"
        "movl 8(%eax), %ecx\n" /* line 374 */
        "leal (%ecx, %ecx, 4), %eax\n"
        "movl %eax, %edx\n"
        "shll $7, %edx\n"
        "addl %edx, %eax\n"
        "shll $6, %eax\n"
        "addl %ecx, %eax\n"
        "leal (, %eax, 4), %edx\n"
        "subl %eax, %edx\n"
        "shll $2, %edx\n"
        "movl %edx, (%esp)\n"
        "calll Z_VirtualAllocInternal\n"
        "movl %eax, 0xc(%esi)\n"
        "testl %eax, %eax\n" /* line 375 */
        "je .Lf1430c6_001431ef\n"
        ".Lf1430c6_00143158:\n"
        "movl 0x195ec98, %eax\n" /* line 380 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1430c6_001431a6\n"
        "movl (%ebx), %edx\n" /* line 382 */
        "movl 8(%edx), %eax\n"
        "shll $0xb, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 8(%edx), %eax\n" /* line 383 */
        "imull %eax, %eax\n"
        "shll $5, %eax\n"
        "movl %eax, 0x14(%esi)\n"
        ".Lf1430c6_0014317d:\n"
        "movl 0x195f284, %eax\n" /* line 391 */
        "movl $1, (%eax)\n"
        "movl $1, 4(%esp)\n" /* line 393 */
        "movl 0x195ecbc, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetBool\n"
        "addl $0x20, %esp\n" /* line 394 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1430c6_001431a6:\n"
        "movl (%ebx), %edx\n" /* line 388 */
        "movl 8(%edx), %eax\n"
        "shll $8, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 8(%edx), %eax\n" /* line 389 */
        "imull %eax, %eax\n"
        "shll $2, %eax\n"
        "movl %eax, 0x14(%esi)\n"
        "jmp .Lf1430c6_0014317d\n"
        ".Lf1430c6_001431bf:\n"
        "movl $0x2a7418, 4(%esp)\n" /* line 369 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1430c6_001430de\n"
        ".Lf1430c6_001431d8:\n"
        "movl $1, 4(%esp)\n" /* line 330 */
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movl (%ebx), %eax\n"
        "jmp .Lf1430c6_00143127\n"
        ".Lf1430c6_001431ef:\n"
        "movl $0x2a7438, 4(%esp)\n" /* line 377 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf1430c6_00143158\n"
    );
}

/* line 402 */
__attribute__((naked))
float SV_ChangeMaxClients(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 402 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl 0x195f290, %eax\n" /* line 411 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jg .Lf143208_0014340b\n"
        "movl $1, -0x1c(%ebp)\n"
        ".Lf143208_0014322a:\n"
        "movl $0x1025, 0x10(%esp)\n" /* line 325 */
        "movl $0x40, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0x14, 4(%esp)\n"
        "movl $0x2a70dc, (%esp)\n" /* "sv_maxclients" */
        "calll Dvar_RegisterInt\n"
        "movl 0x195f290, %esi\n"
        "movl %eax, (%esi)\n"
        "movl %eax, (%esp)\n" /* line 327 */
        "calll Dvar_ClearModified\n"
        "movl (%esi), %eax\n" /* line 329 */
        "movl -0x1c(%ebp), %edx\n"
        "cmpl %edx, 8(%eax)\n"
        "jl .Lf143208_0014347f\n"
        ".Lf143208_00143274:\n"
        "cmpl %ebx, 8(%eax)\n" /* line 425 */
        "je .Lf143208_00143403\n"
        "movl -0x1c(%ebp), %edx\n" /* line 430 */
        "leal (%edx, %edx, 4), %eax\n"
        "movl %eax, %edx\n"
        "shll $7, %edx\n"
        "addl %edx, %eax\n"
        "shll $6, %eax\n"
        "addl -0x1c(%ebp), %eax\n"
        "leal (, %eax, 4), %edx\n"
        "subl %eax, %edx\n"
        "shll $2, %edx\n"
        "movl %edx, (%esp)\n"
        "calll Hunk_AllocateTempMemoryInternal\n"
        "movl %eax, -0x20(%ebp)\n" /* oldClients */
        "movl -0x1c(%ebp), %edi\n" /* line 432 */
        "testl %edi, %edi\n"
        "jle .Lf143208_001432f0\n"
        "movl %eax, %ebx\n"
        "xorl %edi, %edi\n"
        "xorl %esi, %esi\n"
        ".Lf143208_001432b4:\n"
        "movl %esi, %eax\n" /* line 434 */
        "movl 0x195f284, %edx\n"
        "addl 0xc(%edx), %eax\n"
        "cmpl $1, (%eax)\n"
        "jle .Lf143208_00143462\n"
        "movl $0x78f0c, 8(%esp)\n" /* line 436 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        ".Lf143208_001432dc:\n"
        "addl $1, %edi\n" /* line 432 */
        "addl $0x78f0c, %esi\n"
        "addl $0x78f0c, %ebx\n"
        "cmpl -0x1c(%ebp), %edi\n"
        "jne .Lf143208_001432b4\n"
        ".Lf143208_001432f0:\n"
        "movl 0x195f284, %edx\n" /* line 444 */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Z_VirtualFreeInternal\n"
        "movl 0x195f290, %ebx\n" /* line 448 */
        "movl (%ebx), %eax\n"
        "movl 8(%eax), %ecx\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "movl %eax, %edx\n"
        "shll $7, %edx\n"
        "addl %edx, %eax\n"
        "shll $6, %eax\n"
        "addl %ecx, %eax\n"
        "leal (, %eax, 4), %edx\n"
        "subl %eax, %edx\n"
        "shll $2, %edx\n"
        "movl %edx, (%esp)\n"
        "calll Z_VirtualAllocInternal\n"
        "movl 0x195f284, %edx\n"
        "movl %eax, 0xc(%edx)\n"
        "testl %eax, %eax\n" /* line 449 */
        "je .Lf143208_00143492\n"
        ".Lf143208_00143340:\n"
        "movl (%ebx), %eax\n" /* line 454 */
        "movl 8(%eax), %ecx\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "movl %eax, %edx\n"
        "shll $7, %edx\n"
        "addl %edx, %eax\n"
        "shll $6, %eax\n"
        "addl %ecx, %eax\n"
        "leal (, %eax, 4), %edx\n"
        "subl %eax, %edx\n"
        "shll $2, %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl 0x195f284, %edx\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_Memset\n"
        "movl -0x1c(%ebp), %esi\n" /* line 457 */
        "testl %esi, %esi\n"
        "jle .Lf143208_001433c8\n"
        "movl -0x20(%ebp), %ebx\n" /* oldClients */
        "xorl %esi, %esi\n"
        "xorl %edi, %edi\n"
        "movl 0x195f284, %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        ".Lf143208_00143393:\n"
        "cmpl $1, (%ebx)\n" /* line 459 */
        "jle .Lf143208_001433b4\n"
        "movl %edi, %eax\n" /* line 461 */
        "movl -0x24(%ebp), %edx\n"
        "addl 0xc(%edx), %eax\n"
        "movl $0x78f0c, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        ".Lf143208_001433b4:\n"
        "addl $1, %esi\n" /* line 457 */
        "addl $0x78f0c, %edi\n"
        "addl $0x78f0c, %ebx\n"
        "cmpl -0x1c(%ebp), %esi\n"
        "jne .Lf143208_00143393\n"
        ".Lf143208_001433c8:\n"
        "movl -0x20(%ebp), %eax\n" /* line 466 | oldClients */
        "movl %eax, (%esp)\n"
        "calll Hunk_FreeTempMemory\n"
        "movl 0x195ec98, %eax\n" /* line 469 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lf143208_00143438\n"
        "movl 0x195f290, %eax\n" /* line 477 */
        "movl (%eax), %edx\n"
        "movl 0x195f284, %ecx\n"
        "movl 8(%edx), %eax\n"
        "shll $8, %eax\n"
        "movl %eax, 0x10(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 478 */
        "imull %eax, %eax\n"
        "shll $2, %eax\n"
        "movl %eax, 0x14(%ecx)\n"
        /* } scope */
        ".Lf143208_00143403:\n"
        "addl $0x3c, %esp\n" /* line 480 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf143208_0014340b:\n"
        "movl 0x195f284, %eax\n" /* line 411 */
        "movl 0xc(%eax), %eax\n"
        "xorl %edx, %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf143208_00143417:\n"
        "cmpl $1, (%eax)\n" /* line 413 */
        "jle .Lf143208_00143421\n"
        "cmpl %ecx, %edx\n" /* line 415 */
        "cmovgl %edx, %ecx\n"
        ".Lf143208_00143421:\n"
        "addl $1, %edx\n" /* line 411 */
        "addl $0x78f0c, %eax\n"
        "cmpl %ebx, %edx\n"
        "jne .Lf143208_00143417\n"
        "addl $1, %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "jmp .Lf143208_0014322a\n"
        ".Lf143208_00143438:\n"
        "movl 0x195f290, %eax\n" /* line 471 */
        "movl (%eax), %edx\n"
        "movl 0x195f284, %ecx\n"
        "movl 8(%edx), %eax\n"
        "shll $0xb, %eax\n"
        "movl %eax, 0x10(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 472 */
        "imull %eax, %eax\n"
        "shll $5, %eax\n"
        "movl %eax, 0x14(%ecx)\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 480 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf143208_00143462:\n"
        "movl $0x78f0c, 8(%esp)\n" /* line 440 */
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Com_Memset\n"
        "jmp .Lf143208_001432dc\n"
        ".Lf143208_0014347f:\n"
        "movl %edx, 4(%esp)\n" /* line 330 */
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movl (%esi), %eax\n"
        "jmp .Lf143208_00143274\n"
        ".Lf143208_00143492:\n"
        "movl $0x2a7438, 4(%esp)\n" /* line 451 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf143208_00143340\n"
    );
}

/* line 693 */
__attribute__((naked))
float SV_SpawnServer(const char *server)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 693 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20bc, %esp\n"
        /* { scope 1 */
        "calll Scr_ParseGameTypeList\n" /* line 719 */
        "calll SV_SetGametype\n" /* line 720 */
        "movl 0x195f29c, %edi\n" /* line 727 */
        "movl (%edi), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* server */
        "movl %eax, (%esp)\n"
        "calll CL_InitLoad\n"
        "movl 0x195ecbc, %eax\n" /* line 747 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1434ac_00143a3e\n"
        "movl $0, -0x207c(%ebp)\n" /* savepersist */
        ".Lf1434ac_001434f7:\n"
        "movl 8(%ebp), %eax\n" /* line 770 | server */
        "movl %eax, 4(%esp)\n"
        "movl $0x2a7124, (%esp)\n" /* "mapname" */
        "calll Dvar_SetStringByName\n"
        "movl 8(%ebp), %edx\n" /* line 779 | server */
        "movl %edx, (%esp)\n"
        "calll CL_MapLoading\n"
        "calll CL_ShutdownAll\n" /* line 788 */
        "calll SV_ShutdownGameProgs\n" /* line 792 */
        "movl $0x2a7478, (%esp)\n" /* line 794 */
        "calll Com_Printf\n"
        "movl 8(%ebp), %esi\n" /* line 795 | server, i */
        "movl %esi, 4(%esp)\n" /* i */
        "movl $0x2a74a0, (%esp)\n" /* "Server: %s
" */
        "calll Com_Printf\n"
        "movl 0x195ee80, %edi\n"
        "movl %edi, %ebx\n" /* client */
        "movl %edi, %esi\n" /* i */
        ".Lf1434ac_00143548:\n"
        "movl 0x418(%ebx), %eax\n" /* line 545 */
        "testl %eax, %eax\n"
        "je .Lf1434ac_0014355c\n"
        "movl %eax, (%esp)\n" /* line 547 */
        "calll Z_FreeInternal\n"
        "movl %esi, %edi\n"
        ".Lf1434ac_0014355c:\n"
        "addl $4, %ebx\n"
        "leal 0x2000(%edi), %eax\n" /* line 693 */
        "movl %eax, -0x206c(%ebp)\n"
        "cmpl %ebx, %eax\n" /* line 543 */
        "jne .Lf1434ac_00143548\n"
        "movl $0x5f534, 8(%esp)\n" /* line 550 */
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll Com_Memset\n"
        "movl 0x195ec98, %eax\n" /* line 801 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1434ac_0014359a\n"
        "calll FX_FreeSystem\n" /* line 802 */
        ".Lf1434ac_0014359a:\n"
        "movl $1, (%esp)\n" /* line 805 */
        "calll FS_Shutdown\n"
        "calll FS_ClearIwdReferences\n" /* line 809 */
        "calll Com_Restart\n" /* line 812 */
        "movl 0x195ecbc, %eax\n" /* line 815 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1434ac_00143a34\n"
        "calll SV_Startup\n" /* line 817 */
        ".Lf1434ac_001435c6:\n"
        "movl $0x40, 8(%esp)\n" /* line 825 */
        "movl 0x195f29c, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x195ee80, %esi\n" /* i */
        "leal 0x5f4f4(%esi), %edi\n" /* i */
        "movl %edi, (%esp)\n"
        "calll I_strncpyz\n"
        "calll Sys_MillisecondsRaw\n" /* line 829 */
        "movl %eax, (%esp)\n"
        "calll srand\n"
        "calll rand\n" /* line 830 */
        "movl %eax, -0x2080(%ebp)\n"
        "calll rand\n"
        "movl %eax, %ebx\n" /* client */
        "calll Sys_Milliseconds\n"
        "movl -0x2080(%ebp), %edx\n"
        "shll $0x10, %edx\n"
        "xorl %ebx, %edx\n" /* client */
        "xorl %eax, %edx\n"
        "movl %edx, 0xc(%esi)\n" /* i */
        "movl %edx, (%esp)\n" /* line 844 */
        "calll FS_Restart\n"
        "calll GetBspExtension\n" /* line 846 */
        "movl %eax, 0x10(%esp)\n"
        "movl 8(%ebp), %edx\n" /* server */
        "movl %edx, 0xc(%esp)\n"
        "movl $0x2a74ac, 8(%esp)\n" /* "maps/mp/%s.%s" */
        "movl $0x40, 4(%esp)\n"
        "leal -0x68(%ebp), %eax\n" /* filename */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "leal -0x68(%ebp), %edx\n" /* line 847 | filename */
        "movl %edx, (%esp)\n"
        "calll SV_SetExpectedHunkUsage\n"
        "movl %edi, 4(%esp)\n" /* line 855 */
        "movl 8(%ebp), %edi\n" /* server */
        "movl %edi, (%esp)\n"
        "calll CL_StartLoading\n"
        "calll UI_LoadIngameMenus\n" /* line 866 */
        "movl %esi, %ebx\n" /* i, client */
        ".Lf1434ac_00143678:\n"
        "movl $0x2157b8, (%esp)\n" /* line 870 */
        "calll CopyStringInternal\n"
        "movl %eax, 0x418(%ebx)\n" /* client */
        "addl $4, %ebx\n" /* client */
        "cmpl %ebx, -0x206c(%ebp)\n" /* line 869 | client */
        "jne .Lf1434ac_00143678\n"
        "calll Dvar_ResetScriptInfo\n" /* line 657 */
        "movl 0x195f284, %esi\n" /* line 875 | i */
        "movl 0x10(%esi), %eax\n" /* i */
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "shll $8, %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl %eax, 0x20(%esi)\n" /* i */
        "movl $0, 0x18(%esi)\n" /* line 876 | i */
        "movl 0x14(%esi), %edx\n" /* line 879 | i */
        "leal (%edx, %edx, 2), %eax\n"
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl %eax, 0x24(%esi)\n" /* i */
        "movl $0, 0x1c(%esi)\n" /* line 880 | i */
        "movl $0, 0x28(%esi)\n" /* line 601 */
        "movl $0, 0x2c(%esi)\n" /* line 602 */
        "movl $0, 0x38(%esi)\n" /* line 603 */
        "movl $0, 0x3c(%esi)\n" /* line 604 */
        "movl $0, 0x40(%esi)\n" /* line 605 */
        "movl $0, 0x44(%esi)\n" /* line 606 */
        "xorl $4, 8(%esi)\n" /* line 891 | i */
        "movl $0x2a74bc, 4(%esp)\n" /* line 895 */
        "movl 0x195ee88, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "movl $0, 4(%esp)\n" /* line 898 */
        "movl 0x195ed18, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "calll GetBspExtension\n" /* line 900 */
        "movl %eax, 0x10(%esp)\n"
        "movl 8(%ebp), %eax\n" /* server */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x2a74ac, 8(%esp)\n" /* "maps/mp/%s.%s" */
        "movl $0x40, 4(%esp)\n"
        "leal -0x68(%ebp), %edx\n" /* filename */
        "movl %edx, (%esp)\n"
        "calll Com_sprintf\n"
        "leal -0x68(%ebp), %edi\n" /* line 901 | filename */
        "movl %edi, (%esp)\n"
        "calll Com_LoadBsp\n"
        "leal -0x1c(%ebp), %eax\n" /* line 902 | checksum */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll CM_LoadMap\n"
        "calll Com_UnloadBsp\n" /* line 903 */
        "calll CM_LinkWorld\n" /* line 904 */
        "movzbl sv_serverId_value, %eax\n" /* line 907 */
        "addb $0x10, %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, sv_serverId_value\n"
        "testb $0xf0, %al\n" /* line 908 */
        "jne .Lf1434ac_001437a7\n"
        "addl $0x10, %eax\n" /* line 909 */
        "movl %eax, sv_serverId_value\n"
        ".Lf1434ac_001437a7:\n"
        "movl %eax, 4(%esp)\n" /* line 910 */
        "movl 0x195f294, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movl 0x195ee80, %edx\n" /* line 911 */
        "movl 0x195f2d8, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl $1, (%edx)\n" /* line 916 */
        "calll GetBspExtension\n" /* line 920 */
        "movl %eax, 0x10(%esp)\n"
        "movl 8(%ebp), %edx\n" /* server */
        "movl %edx, 0xc(%esp)\n"
        "movl $0x2a74ac, 8(%esp)\n" /* "maps/mp/%s.%s" */
        "movl $0x40, 4(%esp)\n"
        "leal -0x68(%ebp), %edi\n" /* filename */
        "movl %edi, (%esp)\n"
        "calll Com_sprintf\n"
        "movl $2, 8(%esp)\n" /* line 921 */
        "movl $0x21f990, 4(%esp)\n" /* "all_mp" */
        "movl %edi, (%esp)\n"
        "calll Com_LoadSoundAliases\n"
        "movl -0x207c(%ebp), %edx\n" /* line 925 | savepersist */
        "movl %edx, (%esp)\n"
        "calll SV_InitGameProgs\n"
        "movl 0x195ec98, %eax\n" /* line 927 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1434ac_00143b10\n"
        ".Lf1434ac_00143833:\n"
        "movl $3, %ebx\n" /* line 931 | client */
        ".Lf1434ac_00143838:\n"
        "addl $0x64, 4(%esi)\n" /* line 973 | i */
        "calll SV_RunFrame\n" /* line 974 */
        "subl $1, %ebx\n" /* line 971 | client */
        "jne .Lf1434ac_00143838\n"
        "movl 0x195ee80, %eax\n" /* line 291 */
        "cmpl $1, 0x5f424(%eax)\n"
        "jg .Lf1434ac_00143b37\n"
        ".Lf1434ac_00143858:\n"
        "movl 0x195f290, %edx\n" /* line 980 */
        "movl (%edx), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf1434ac_001438db\n"
        "xorl %esi, %esi\n" /* i */
        "xorl %ebx, %ebx\n" /* client */
        "movl 0x195f284, %edi\n"
        "jmp .Lf1434ac_0014389a\n"
        /* { scope 2 */
        ".Lf1434ac_00143873:\n"
        "movl %eax, 4(%esp)\n" /* line 993 */
        "movl %ebx, %eax\n" /* client */
        "addl 0xc(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SV_DropClient\n"
        "movl 0x195f290, %edx\n"
        /* } scope */
        ".Lf1434ac_0014388a:\n"
        "addl $1, %esi\n" /* line 980 | i */
        "addl $0x78f0c, %ebx\n" /* client */
        "movl (%edx), %eax\n"
        "cmpl %esi, 8(%eax)\n" /* i */
        "jle .Lf1434ac_001438db\n"
        ".Lf1434ac_0014389a:\n"
        "movl %ebx, %eax\n" /* line 983 | client */
        "addl 0xc(%edi), %eax\n"
        "cmpl $1, (%eax)\n"
        "jle .Lf1434ac_0014388a\n"
        /* { scope 2 */
        "movzwl 0x765f0(%eax), %eax\n" /* line 988 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* i */
        "calll ClientConnect\n"
        "testl %eax, %eax\n" /* line 989 */
        "jne .Lf1434ac_00143873\n"
        "movl 0xc(%edi), %eax\n" /* line 999 */
        "movl $2, (%ebx, %eax)\n" /* client */
        "movl 0x195f290, %edx\n"
        /* } scope */
        "addl $1, %esi\n" /* line 980 | i */
        "addl $0x78f0c, %ebx\n" /* client */
        "movl (%edx), %eax\n"
        "cmpl %esi, 8(%eax)\n" /* i */
        "jg .Lf1434ac_0014389a\n"
        ".Lf1434ac_001438db:\n"
        "movl 0x195f2e0, %eax\n" /* line 1012 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1434ac_00143a01\n"
        "calll FS_LoadedIwdChecksums\n" /* line 1016 */
        "movl %eax, %ebx\n" /* client */
        "movl %eax, 4(%esp)\n" /* line 1017 */
        "movl 0x195f28c, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "cmpb $0, (%ebx)\n" /* line 1018 | client */
        "je .Lf1434ac_00143b26\n"
        ".Lf1434ac_0014390f:\n"
        "calll FS_LoadedIwdNames\n" /* line 1022 */
        "movl %eax, 4(%esp)\n" /* line 1023 */
        "movl 0x195f270, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        ".Lf1434ac_00143927:\n"
        "calll FS_ReferencedIwdChecksums\n" /* line 1033 */
        "movl %eax, 4(%esp)\n" /* line 1034 */
        "movl 0x195f2d4, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "calll FS_ReferencedIwdNames\n" /* line 1035 */
        "movl %eax, 4(%esp)\n" /* line 1036 */
        "movl 0x195f2c4, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "movl $8, (%esp)\n" /* line 672 */
        "calll Dvar_InfoString_Big\n"
        "movl $0x2000, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x2068(%ebp), %esi\n"
        "movl %esi, (%esp)\n"
        "calll I_strncpyz\n"
        "movl 0x195ec9c, %ebx\n" /* line 673 */
        "andl $0xfffffff7, (%ebx)\n"
        "movl %esi, 4(%esp)\n" /* line 674 */
        "movl $1, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "movl $0x404, (%esp)\n" /* line 676 */
        "calll Dvar_InfoString\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "andl $0xfffffbfb, (%ebx)\n" /* line 677 */
        "movl $0x100, 8(%esp)\n" /* line 679 */
        "movl $0x60, 4(%esp)\n"
        "movl $0x8e, (%esp)\n"
        "calll SV_SetConfig\n"
        "andl $0xfffffeff, (%ebx)\n" /* line 680 */
        "movl 0x195ee80, %eax\n" /* line 1045 */
        "movl $2, (%eax)\n"
        "calll SV_Heartbeat_f\n" /* line 1048 */
        "movl $0x2a74f8, (%esp)\n" /* line 1051 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x20bc, %esp\n" /* line 1065 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1434ac_00143a01:\n"
        "movl $0x2157b8, 4(%esp)\n" /* line 1028 */
        "movl 0x195f28c, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "movl $0x2157b8, 4(%esp)\n" /* line 1029 */
        "movl 0x195f270, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "jmp .Lf1434ac_00143927\n"
        ".Lf1434ac_00143a34:\n"
        "calll SV_ChangeMaxClients\n" /* line 822 */
        "jmp .Lf1434ac_001435c6\n"
        ".Lf1434ac_00143a3e:\n"
        "calll G_GetSavePersist\n" /* line 749 */
        "movl %eax, -0x207c(%ebp)\n" /* savepersist */
        "movl 0x195f284, %eax\n" /* line 751 */
        "movl 0xc(%eax), %ebx\n" /* client */
        "movl 0x195f290, %edx\n"
        "movl (%edx), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf1434ac_00143aff\n"
        "xorl %esi, %esi\n" /* i */
        "movl %edi, -0x208c(%ebp)\n"
        "movl %edx, -0x2084(%ebp)\n"
        "jmp .Lf1434ac_00143a84\n"
        ".Lf1434ac_00143a74:\n"
        "addl $1, %esi\n" /* i */
        "addl $0x78f0c, %ebx\n" /* client */
        "movl (%edx), %eax\n"
        "cmpl %esi, 8(%eax)\n" /* i */
        "jle .Lf1434ac_00143aff\n"
        ".Lf1434ac_00143a84:\n"
        "cmpl $2, (%ebx)\n" /* line 753 | client */
        "jle .Lf1434ac_00143a74\n"
        "movl -0x208c(%ebp), %edx\n" /* line 756 */
        "movl (%edx), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 8(%ebp), %edi\n" /* server */
        "movl %edi, 0xc(%esp)\n"
        "movl $0x2a7464, 8(%esp)\n" /* "loadingnewmap
%s
%s" */
        "movl $0x40, 4(%esp)\n"
        "leal -0x68(%ebp), %eax\n" /* filename */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 0x6e5c4(%ebx), %edx\n" /* line 757 | client */
        "movl %edx, -0x28(%ebp)\n"
        "movl 0x6e5c8(%ebx), %ecx\n" /* client */
        "movl %ecx, -0x24(%ebp)\n"
        "movl 0x6e5cc(%ebx), %eax\n" /* client */
        "movl %eax, -0x20(%ebp)\n"
        "leal -0x68(%ebp), %edi\n" /* filename */
        "movl %edi, 0x10(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ecx, 8(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        "movl -0x2084(%ebp), %edx\n"
        "jmp .Lf1434ac_00143a74\n"
        ".Lf1434ac_00143aff:\n"
        "movl $0xfa, (%esp)\n" /* line 761 */
        "calll NET_Sleep\n"
        "jmp .Lf1434ac_001434f7\n"
        ".Lf1434ac_00143b10:\n"
        "movl $0, (%esp)\n" /* line 929 */
        "calll FX_InitSystem\n"
        "calll FX_CreateDefaultEffect\n" /* line 931 */
        "jmp .Lf1434ac_00143833\n"
        ".Lf1434ac_00143b26:\n"
        "movl $0x2a74c8, (%esp)\n" /* line 1020 */
        "calll Com_Printf\n"
        "jmp .Lf1434ac_0014390f\n"
        ".Lf1434ac_00143b37:\n"
        "movl $1, -0x2074(%ebp)\n" /* line 291 */
        "movl %eax, -0x2070(%ebp)\n"
        "movl -0x2074(%ebp), %esi\n"
        "jmp .Lf1434ac_00143c42\n"
        ".Lf1434ac_00143b52:\n"
        "movl %esi, (%eax)\n" /* line 298 */
        "movl -0x2070(%ebp), %eax\n" /* line 303 */
        "addl $0x2590, %eax\n"
        "movl $0xf0, 8(%esp)\n"
        "movl -0x2078(%ebp), %edi\n"
        "movl %edi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movzbl 0xf2(%edi), %eax\n" /* line 304 */
        "movl -0x2070(%ebp), %edx\n"
        "movl %eax, 0x2680(%edx)\n"
        "movl 0xf4(%edi), %eax\n" /* line 305 */
        "movl %eax, 0x2684(%edx)\n"
        "movl 0xf8(%edi), %eax\n" /* line 306 */
        "movl %eax, 0x2688(%edx)\n"
        "leal (%esi, %esi, 2), %eax\n" /* line 307 */
        "movl %eax, %edx\n"
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "shll $2, %edx\n"
        "movl 0x195ee80, %edi\n"
        "leal 0x2500(%edx, %edi), %ecx\n"
        "leal 0x18(%ecx), %esi\n"
        "movl -0x2078(%ebp), %ebx\n"
        "addl $0x120, %ebx\n"
        "movl -0x2078(%ebp), %eax\n" /* line 199 */
        "movss 0x120(%eax), %xmm0\n"
        "movss %xmm0, 0x18(%ecx)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%esi)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%esi)\n"
        "leal 0x2510(%edx, %edi), %edx\n" /* line 308 */
        "leal 0x14(%edx), %ebx\n"
        "movl -0x2078(%ebp), %ecx\n"
        "addl $0x12c, %ecx\n"
        "movl -0x2078(%ebp), %esi\n" /* line 199 */
        "movl 0x12c(%esi), %eax\n"
        "movl %eax, 0x14(%edx)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        ".Lf1434ac_00143c1d:\n"
        "addl $1, -0x2074(%ebp)\n" /* line 291 */
        "addl $0x174, -0x2070(%ebp)\n"
        "movl -0x2074(%ebp), %eax\n"
        "cmpl 0x5f424(%edi), %eax\n"
        "jge .Lf1434ac_00143858\n"
        "movl %eax, %esi\n"
        ".Lf1434ac_00143c42:\n"
        "movl %esi, (%esp)\n" /* line 293 */
        "calll SV_GentityNum\n"
        "movl %eax, -0x2078(%ebp)\n"
        "cmpb $0, 0xf0(%eax)\n" /* line 294 */
        "jne .Lf1434ac_00143b52\n"
        "movl 0x195ee80, %edi\n"
        "jmp .Lf1434ac_00143c1d\n"
    );
}

