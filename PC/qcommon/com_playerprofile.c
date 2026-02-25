/* ASM dump from: com_playerprofile.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/com_playerprofile.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/q_shared.h"
 */

extern const dvar_t *com_playerProfile; /* 0x0 */
extern const dvar_t *ui_playerProfileAlreadyChosen; /* 0x0 */

Bool Com_HasPlayerProfile(void);
int Com_BuildPlayerProfilePath(char *path, int pathSize, const char *format);
int Com_BuildPlayerProfilePathForPlayer(char *path, int pathSize, const char *playerName, const char *format);
Bool Com_DeletePlayerProfile(const char *profileName);
JCOEF Com_ChangePlayerProfile(const char *profileName);
JCOEF Com_InitPlayerProfiles(void);
Bool Com_NewPlayerProfile(const char *profileName);

/* line 124 */
__attribute__((naked))
Bool Com_HasPlayerProfile(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 124 */
        "movl %esp, %ebp\n"
        "movl com_playerProfile, %eax\n"
        "movl 8(%eax), %eax\n"
        "cmpb $0, (%eax)\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "popl %ebp\n" /* line 128 */
        "retl\n"
    );
}

/* line 179 */
__attribute__((naked))
int Com_BuildPlayerProfilePath(char *path, int pathSize, const char *format)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 179 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* pathSize */
        /* { scope 1 */
        "movl com_playerProfile, %edx\n" /* line 186 */
        "movl 8(%edx), %eax\n"
        "cmpb $0, (%eax)\n"
        "je .Lf111eba_00111f4d\n"
        ".Lf111eba_00111ed4:\n"
        "leal 0x14(%ebp), %edi\n" /* line 189 */
        "movl %edi, -0x1c(%ebp)\n" /* vargs */
        /* { scope 2 */
        "movl 8(%edx), %eax\n" /* line 143 */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x228e68, 8(%esp)\n" /* "players/%s/" */
        "movl %esi, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* path */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "movl %eax, %ebx\n" /* prefixLength */
        "testl %eax, %eax\n" /* line 144 */
        "js .Lf111eba_00111f02\n"
        "cmpl %eax, %esi\n"
        "jg .Lf111eba_00111f0e\n"
        ".Lf111eba_00111f02:\n"
        "movl %esi, %edx\n" /* line 150 */
        /* } scope */
        /* } scope */
        ".Lf111eba_00111f04:\n"
        "movl %edx, %eax\n" /* line 194 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf111eba_00111f0e:\n"
        "movl %edi, 0xc(%esp)\n" /* line 147 */
        "movl 0x10(%ebp), %eax\n" /* format */
        "movl %eax, 8(%esp)\n"
        "movl %esi, %eax\n"
        "subl %ebx, %eax\n" /* prefixLength */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* path */
        "addl %ebx, %eax\n" /* prefixLength */
        "movl %eax, (%esp)\n"
        "calll vsnprintf\n"
        "leal (%ebx, %eax), %edx\n" /* line 149 | prefixLength */
        "testl %eax, %eax\n" /* line 150 */
        "js .Lf111eba_00111f39\n"
        "cmpl %edx, %esi\n"
        "jg .Lf111eba_00111f04\n"
        ".Lf111eba_00111f39:\n"
        "movl 8(%ebp), %eax\n" /* line 153 | path */
        "movb $0, -1(%eax, %esi)\n"
        "movl %esi, %edx\n"
        /* } scope */
        /* } scope */
        "movl %edx, %eax\n" /* line 194 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf111eba_00111f4d:\n"
        "movl $0x228e18, 4(%esp)\n" /* line 187 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "movl com_playerProfile, %edx\n"
        "jmp .Lf111eba_00111ed4\n"
    );
}

/* line 166 */
__attribute__((naked))
int Com_BuildPlayerProfilePathForPlayer(char *path, int pathSize, const char *playerName, const char *format)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 166 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* pathSize */
        /* { scope 1 */
        "leal 0x18(%ebp), %edi\n" /* line 171 */
        "movl %edi, -0x1c(%ebp)\n" /* vargs */
        /* { scope 2 */
        "movl 0x10(%ebp), %eax\n" /* line 143 | playerName */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x228e68, 8(%esp)\n" /* "players/%s/" */
        "movl %esi, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* path */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "movl %eax, %ebx\n" /* prefixLength */
        "testl %eax, %eax\n" /* line 144 */
        "js .Lf111f6c_00111fa6\n"
        "cmpl %eax, %esi\n"
        "jg .Lf111f6c_00111fb2\n"
        ".Lf111f6c_00111fa6:\n"
        "movl %esi, %edx\n" /* line 150 */
        /* } scope */
        /* } scope */
        ".Lf111f6c_00111fa8:\n"
        "movl %edx, %eax\n" /* line 176 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf111f6c_00111fb2:\n"
        "movl %edi, 0xc(%esp)\n" /* line 147 */
        "movl 0x14(%ebp), %eax\n" /* format */
        "movl %eax, 8(%esp)\n"
        "movl %esi, %eax\n"
        "subl %ebx, %eax\n" /* prefixLength */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* path */
        "addl %ebx, %eax\n" /* prefixLength */
        "movl %eax, (%esp)\n"
        "calll vsnprintf\n"
        "leal (%ebx, %eax), %edx\n" /* line 149 | prefixLength */
        "testl %eax, %eax\n" /* line 150 */
        "js .Lf111f6c_00111fdd\n"
        "cmpl %edx, %esi\n"
        "jg .Lf111f6c_00111fa8\n"
        ".Lf111f6c_00111fdd:\n"
        "movl 8(%ebp), %eax\n" /* line 153 | path */
        "movb $0, -1(%eax, %esi)\n"
        "movl %esi, %edx\n"
        /* } scope */
        /* } scope */
        "movl %edx, %eax\n" /* line 176 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 220 */
__attribute__((naked))
Bool Com_DeletePlayerProfile(const char *profileName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 220 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x17c, %esp\n"
        "movl 8(%ebp), %edi\n" /* profileName */
        /* { scope 1: dirCount */
        /* { scope 2 */
        "cmpb $0, (%edi)\n" /* line 25 */
        "jne .Lf111ff2_00112013\n"
        /* } scope */
        ".Lf111ff2_00112006:\n"
        "xorl %eax, %eax\n" /* line 234 */
        /* } scope */
        ".Lf111ff2_00112008:\n"
        "addl $0x17c, %esp\n" /* line 237 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: dirCount */
        /* { scope 2 */
        ".Lf111ff2_00112013:\n"
        "movl $3, 0x10(%esp)\n" /* line 29 */
        "leal -0x1c(%ebp), %eax\n" /* dirCount */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0x216f38, 4(%esp)\n" /* "/" */
        "movl $0x228e74, (%esp)\n" /* "players" */
        "calll FS_ListFiles\n"
        "movl %eax, %esi\n" /* dirs */
        "movl -0x1c(%ebp), %eax\n" /* line 30 | dirCount */
        "testl %eax, %eax\n"
        "jg .Lf111ff2_001120db\n"
        ".Lf111ff2_0011204b:\n"
        "xorl %ebx, %ebx\n" /* dirIndex */
        ".Lf111ff2_0011204d:\n"
        "movl $3, 4(%esp)\n" /* line 38 */
        "movl %esi, (%esp)\n" /* dirs */
        "calll FS_FreeFileList\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 225 | dirIndex */
        "je .Lf111ff2_00112006\n"
        "movl $0x2157b8, 0xc(%esp)\n" /* line 228 */
        "movl %edi, 8(%esp)\n" /* profileName */
        "movl $0x40, 4(%esp)\n"
        "leal -0x5c(%ebp), %ebx\n" /* profilePath, dirIndex */
        "movl %ebx, (%esp)\n" /* dirIndex */
        "calll Com_BuildPlayerProfilePathForPlayer\n"
        "leal -0x15c(%ebp), %esi\n" /* line 229 | osPath, dirs */
        "movl %esi, 0xc(%esp)\n" /* dirs */
        "movl %ebx, 8(%esp)\n" /* dirIndex */
        "movl 0x195ee98, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x195ecc8, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_BuildOSPath\n"
        "movl %esi, (%esp)\n" /* line 230 | dirs */
        "calll Sys_RemoveDirTree\n"
        "testl %eax, %eax\n"
        "je .Lf111ff2_00112006\n"
        "movl com_playerProfile, %eax\n" /* line 233 */
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* profileName */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf111ff2_001120fd\n"
        "movl $1, %eax\n" /* line 234 */
        "jmp .Lf111ff2_00112008\n"
        /* { scope 2 */
        ".Lf111ff2_001120db:\n"
        "xorl %ebx, %ebx\n" /* line 30 | dirIndex */
        ".Lf111ff2_001120dd:\n"
        "movl %edi, 4(%esp)\n" /* line 32 */
        "movl (%esi, %ebx, 4), %eax\n" /* dirs */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf111ff2_0011211c\n"
        "addl $1, %ebx\n" /* line 30 | dirIndex */
        "cmpl %ebx, -0x1c(%ebp)\n" /* dirIndex, dirCount */
        "jg .Lf111ff2_001120dd\n"
        "jmp .Lf111ff2_0011204b\n"
        /* } scope */
        ".Lf111ff2_001120fd:\n"
        "movl $0x2157b8, 4(%esp)\n" /* line 234 */
        "movl com_playerProfile, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "movl $1, %eax\n"
        "jmp .Lf111ff2_00112008\n"
        /* { scope 2 */
        ".Lf111ff2_0011211c:\n"
        "movl $1, %ebx\n" /* line 30 | dirIndex */
        "jmp .Lf111ff2_0011204d\n"
    );
}

/* line 57 */
__attribute__((naked))
JCOEF Com_ChangePlayerProfile(const char *profileName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 57 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        "movl 8(%ebp), %ebx\n" /* profileName */
        /* { scope 1: dirCount, configFile */
        "movl com_playerProfile, %eax\n" /* line 64 */
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* profileName */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf112126_00112158\n"
        /* } scope */
        ".Lf112126_0011214d:\n"
        "addl $0xbc, %esp\n" /* line 84 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: dirCount, configFile */
        ".Lf112126_00112158:\n"
        "movl $0x40, 8(%esp)\n" /* line 68 */
        "movl %ebx, 4(%esp)\n" /* profileName */
        "leal -0x5c(%ebp), %esi\n" /* cachedName */
        "movl %esi, (%esp)\n"
        "calll I_strncpyz\n"
        /* { scope 2 */
        "cmpb $0, -0x5c(%ebp)\n" /* line 25 | cachedName */
        "je .Lf112126_0011214d\n"
        "movl $3, 0x10(%esp)\n" /* line 29 */
        "leal -0x1c(%ebp), %eax\n" /* dirCount */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0x216f38, 4(%esp)\n" /* "/" */
        "movl $0x228e74, (%esp)\n" /* "players" */
        "calll FS_ListFiles\n"
        "movl %eax, %edi\n" /* dirs */
        "movl -0x1c(%ebp), %edx\n" /* line 30 | dirCount */
        "testl %edx, %edx\n"
        "jg .Lf112126_0011226a\n"
        ".Lf112126_001121ad:\n"
        "xorl %ebx, %ebx\n" /* dirIndex */
        ".Lf112126_001121af:\n"
        "movl $3, 4(%esp)\n" /* line 38 */
        "movl %edi, (%esp)\n" /* dirs */
        "calll FS_FreeFileList\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 69 | profileName */
        "je .Lf112126_0011214d\n"
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* dirs */
        "repne scasb %es:(%edi), %al\n" /* dirs */
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl $0x228e7c, (%esp)\n" /* "players/active.txt" */
        "calll FS_WriteFile\n"
        "movl $0x228e90, 4(%esp)\n" /* line 74 */
        "movl $0, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "movl $1, 4(%esp)\n" /* line 75 */
        "movl $0xffffffff, (%esp)\n"
        "calll Dvar_ResetDvars\n"
        /* { scope 2 */
        "movl %esi, 4(%esp)\n" /* line 51 */
        "movl com_playerProfile, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "movl $0x216300, 8(%esp)\n" /* line 52 */
        "movl $0x40, 4(%esp)\n"
        "leal -0x9c(%ebp), %ebx\n" /* configFile, dirIndex */
        "movl %ebx, (%esp)\n" /* dirIndex */
        "calll Com_BuildPlayerProfilePath\n"
        "movl %ebx, (%esp)\n" /* line 53 | dirIndex */
        "calll Com_ExecStartupConfigs\n"
        /* } scope */
        "calll Com_CheckSetRecommended\n" /* line 79 */
        "calll Dvar_AnyLatchedValues\n" /* line 82 */
        "testb %al, %al\n"
        "je .Lf112126_0011214d\n"
        "movl $0x216604, (%esp)\n" /* line 83 */
        "calll Cbuf_AddText\n"
        "jmp .Lf112126_0011214d\n"
        /* { scope 2 */
        ".Lf112126_0011226a:\n"
        "xorl %ebx, %ebx\n" /* line 30 | dirIndex */
        ".Lf112126_0011226c:\n"
        "movl %esi, 4(%esp)\n" /* line 32 */
        "movl (%edi, %ebx, 4), %eax\n" /* dirs */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf112126_0011228c\n"
        "addl $1, %ebx\n" /* line 30 | dirIndex */
        "cmpl %ebx, -0x1c(%ebp)\n" /* dirIndex, dirCount */
        "jg .Lf112126_0011226c\n"
        "jmp .Lf112126_001121ad\n"
        ".Lf112126_0011228c:\n"
        "movl $1, %ebx\n" /* dirIndex */
        "jmp .Lf112126_001121af\n"
    );
}

/* line 107 */
__attribute__((naked))
JCOEF Com_InitPlayerProfiles(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 107 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl $0x1200, 0x10(%esp)\n" /* line 113 */
        "movl $1, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x228e9c, (%esp)\n" /* "ui_playerProfileAlreadyChosen" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, ui_playerProfileAlreadyChosen\n"
        "movl $1, 4(%esp)\n" /* line 115 */
        "movl %eax, (%esp)\n"
        "calll Dvar_ChangeResetValue\n"
        "movl $0x1040, 8(%esp)\n" /* line 117 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x228ebc, (%esp)\n" /* "com_playerProfile" */
        "calll Dvar_RegisterString\n"
        "movl %eax, com_playerProfile\n"
        "leal -0x1c(%ebp), %eax\n" /* line 93 */
        "movl %eax, 4(%esp)\n"
        "movl $0x228e7c, (%esp)\n" /* "players/active.txt" */
        "calll FS_ReadFile\n"
        "testl %eax, %eax\n"
        "js .Lf112296_0011233b\n"
        "movl -0x1c(%ebp), %eax\n" /* line 96 */
        "movl %eax, -0x20(%ebp)\n"
        "leal -0x20(%ebp), %eax\n" /* line 97 */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, %esi\n"
        "movl -0x1c(%ebp), %eax\n" /* line 98 */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        "cmpb $0, (%esi)\n" /* line 25 */
        "jne .Lf112296_0011234f\n"
        ".Lf112296_0011233b:\n"
        "movl $0, (%esp)\n" /* line 120 */
        "calll Com_ExecStartupConfigs\n"
        ".Lf112296_00112347:\n"
        "addl $0x7c, %esp\n" /* line 121 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf112296_0011234f:\n"
        "movl $3, 0x10(%esp)\n" /* line 29 */
        "leal -0x24(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0x216f38, 4(%esp)\n" /* "/" */
        "movl $0x228e74, (%esp)\n" /* "players" */
        "calll FS_ListFiles\n"
        "movl %eax, %edi\n"
        "movl -0x24(%ebp), %ecx\n" /* line 30 */
        "testl %ecx, %ecx\n"
        "jg .Lf112296_001123d2\n"
        ".Lf112296_00112383:\n"
        "xorl %ebx, %ebx\n"
        ".Lf112296_00112385:\n"
        "movl $3, 4(%esp)\n" /* line 38 */
        "movl %edi, (%esp)\n"
        "calll FS_FreeFileList\n"
        "testl %ebx, %ebx\n" /* line 99 */
        "je .Lf112296_0011233b\n"
        "movl %esi, 4(%esp)\n" /* line 51 */
        "movl com_playerProfile, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "movl $0x216300, 8(%esp)\n" /* line 52 */
        "movl $0x40, 4(%esp)\n"
        "leal -0x64(%ebp), %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll Com_BuildPlayerProfilePath\n"
        "movl %ebx, (%esp)\n" /* line 53 */
        "calll Com_ExecStartupConfigs\n"
        "jmp .Lf112296_00112347\n"
        ".Lf112296_001123d2:\n"
        "xorl %ebx, %ebx\n" /* line 30 */
        ".Lf112296_001123d4:\n"
        "movl %esi, 4(%esp)\n" /* line 32 */
        "movl (%edi, %ebx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf112296_001123f1\n"
        "addl $1, %ebx\n" /* line 30 */
        "cmpl %ebx, -0x24(%ebp)\n"
        "jg .Lf112296_001123d4\n"
        "jmp .Lf112296_00112383\n"
        ".Lf112296_001123f1:\n"
        "movl $1, %ebx\n"
        "jmp .Lf112296_00112385\n"
    );
}

/* line 197 */
__attribute__((naked))
Bool Com_NewPlayerProfile(const char *profileName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 197 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x17c, %esp\n"
        "movl 8(%ebp), %esi\n" /* profileName */
        /* { scope 1: dirCount */
        /* { scope 2 */
        "cmpb $0, (%esi)\n" /* line 25 */
        "jne .Lf1123f8_0011248a\n"
        /* } scope */
        ".Lf1123f8_0011240c:\n"
        "movl $0x2157b8, 0xc(%esp)\n" /* line 208 */
        "movl %esi, 8(%esp)\n" /* profileName */
        "movl $0x40, 4(%esp)\n"
        "leal -0x5c(%ebp), %ebx\n" /* profilePath, dirIndex */
        "movl %ebx, (%esp)\n" /* dirIndex */
        "calll Com_BuildPlayerProfilePathForPlayer\n"
        "leal -0x15c(%ebp), %esi\n" /* line 209 | osPath, profileName */
        "movl %esi, 0xc(%esp)\n" /* profileName */
        "movl %ebx, 8(%esp)\n" /* dirIndex */
        "movl 0x195ee98, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x195ecc8, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_BuildOSPath\n"
        "movl %esi, (%esp)\n" /* line 210 | profileName */
        "calll FS_CreatePath\n"
        "testl %eax, %eax\n"
        "jne .Lf1123f8_0011246d\n"
        "movb $1, %al\n"
        /* } scope */
        "addl $0x17c, %esp\n" /* line 217 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: dirCount */
        ".Lf1123f8_0011246d:\n"
        "movl %esi, 4(%esp)\n" /* line 212 | profileName */
        "movl $0x228ef0, (%esp)\n" /* "Unable to create new profile path: %s
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x17c, %esp\n" /* line 217 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: dirCount */
        /* { scope 2 */
        ".Lf1123f8_0011248a:\n"
        "movl $3, 0x10(%esp)\n" /* line 29 */
        "leal -0x1c(%ebp), %eax\n" /* dirCount */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0x216f38, 4(%esp)\n" /* "/" */
        "movl $0x228e74, (%esp)\n" /* "players" */
        "calll FS_ListFiles\n"
        "movl %eax, %edi\n" /* dirs */
        "movl -0x1c(%ebp), %ebx\n" /* line 30 | dirCount, dirIndex */
        "testl %ebx, %ebx\n" /* dirIndex */
        "jg .Lf1123f8_001124f5\n"
        ".Lf1123f8_001124be:\n"
        "xorl %ebx, %ebx\n" /* dirIndex */
        ".Lf1123f8_001124c0:\n"
        "movl $3, 4(%esp)\n" /* line 38 */
        "movl %edi, (%esp)\n" /* dirs */
        "calll FS_FreeFileList\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 202 | dirIndex */
        "je .Lf1123f8_0011240c\n"
        "movl %esi, 4(%esp)\n" /* line 204 | profileName */
        "movl $0x228ed0, (%esp)\n" /* "Profile '%s' already exists
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x17c, %esp\n" /* line 217 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: dirCount */
        /* { scope 2 */
        ".Lf1123f8_001124f5:\n"
        "xorl %ebx, %ebx\n" /* line 30 | dirIndex */
        ".Lf1123f8_001124f7:\n"
        "movl %esi, 4(%esp)\n" /* line 32 */
        "movl (%edi, %ebx, 4), %eax\n" /* dirs */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1123f8_00112514\n"
        "addl $1, %ebx\n" /* line 30 | dirIndex */
        "cmpl %ebx, -0x1c(%ebp)\n" /* dirIndex, dirCount */
        "jg .Lf1123f8_001124f7\n"
        "jmp .Lf1123f8_001124be\n"
        ".Lf1123f8_00112514:\n"
        "movl $1, %ebx\n" /* dirIndex */
        "jmp .Lf1123f8_001124c0\n"
    );
}

