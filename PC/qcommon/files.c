/* ASM dump from: files.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/files.cpp */

#include "common_types.h"
#include "imports.h"

static char buf[1024]; /* buf */
static char basename[64]; /* basename */
static char info2[8192]; /* info2 */
static char info3[8192]; /* info3 */
static char info4[8192]; /* info4 */
static char info5[8192]; /* info5 */
static char info6[8192]; /* info6 */
static char info8[8192]; /* info8 */

fileHandle_t FS_SV_FOpenFileWrite(const char *filename);
int FS_SV_FOpenFileRead(const char *filename, fileHandle_t *fp);
double FS_SV_Rename(const char *from, const char *to);
char * FS_ShiftStr(const char *string, int shift);
double FS_Dir_f(void);
double FS_NewDir_f(void);
double FS_TouchFile_f(void);
qboolean FS_iwIwd(char *iwd, char *base);
double FS_AddCommands(void);
double FS_SetRestrictions(void);
const char * FS_LoadedIwdChecksums(void);
const char * FS_LoadedIwdNames(void);
const char * FS_LoadedIwdPureChecksums(void);
const char * FS_ReferencedIwdChecksums(void);
const char * FS_ReferencedIwdNames(void);
const char * FS_ReferencedIwdPureChecksums(void);
double FS_PureServerSetLoadedIwds(const char *iwdSums, const char *iwdNames);
double FS_PureServerSetReferencedIwds(const char *iwdSums, const char *iwdNames);
const char * FS_GetMapBaseName(const char *mapname);
int FS_GetModList(char *listbuf, int bufsize);
qboolean FS_CompareIwds(char *needediwds, int len, qboolean dlstring);

/* line 94 */
__attribute__((naked))
fileHandle_t FS_SV_FOpenFileWrite(const char *filename)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 94 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x12c, %esp\n"
        /* { scope 1 */
        "calll FS_CheckFileSystemStarted\n" /* line 99 */
        "leal -0x118(%ebp), %esi\n" /* line 101 | ospath */
        "movl %esi, 0xc(%esp)\n"
        "movl $str_002157b8, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* filename */
        "movl %eax, 4(%esp)\n"
        "movl imp_fs_homepath, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_BuildOSPath\n"
        "cld\n" /* line 102 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* f */
        "repne scasb %es:(%edi), %al\n" /* f */
        "notl %ecx\n"
        "movb $0, -0x11a(%ecx, %ebp)\n"
        "movl $0, (%esp)\n" /* line 104 */
        "calll FS_HandleForFile\n"
        "movl %eax, %edi\n" /* f */
        "leal (%eax, %eax, 8), %eax\n" /* line 105 */
        "shll $3, %eax\n"
        "subl %edi, %eax\n" /* f */
        "shll $2, %eax\n"
        "movl %eax, -0x11c(%ebp)\n"
        "movl %eax, %ebx\n"
        "addl imp_fsh, %ebx\n"
        "movl $0, 0x14(%ebx)\n"
        "movl imp_fs_debug, %eax\n" /* line 107 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf46cbc_00046dc8\n"
        ".Lf46cbc_00046d4a:\n"
        "movl %esi, (%esp)\n" /* line 110 */
        "calll FS_CreatePath\n"
        "testl %eax, %eax\n"
        "je .Lf46cbc_00046d65\n"
        ".Lf46cbc_00046d56:\n"
        "xorl %edi, %edi\n" /* line 119 | f */
        /* } scope */
        "movl %edi, %eax\n" /* line 124 | f */
        "addl $0x12c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf46cbc_00046d65:\n"
        "movl %esi, 4(%esp)\n" /* line 113 */
        "movl $str_00217dec, (%esp)\n" /* "writing to: %s
" */
        "calll Com_DPrintf\n"
        "movl $str_00216fec, 4(%esp)\n" /* line 114 */
        "movl %esi, (%esp)\n"
        "calll FS_FileOpen\n"
        "movl %eax, (%ebx)\n"
        "movl $0x100, 8(%esp)\n" /* line 116 */
        "movl 8(%ebp), %edx\n" /* filename */
        "movl %edx, 4(%esp)\n"
        "movl -0x11c(%ebp), %ecx\n"
        "movl imp_fsh, %edx\n"
        "leal 0x1c(%ecx, %edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $0, 8(%ebx)\n" /* line 118 */
        "movl (%ebx), %eax\n" /* line 119 */
        "testl %eax, %eax\n"
        "je .Lf46cbc_00046d56\n"
        /* } scope */
        "movl %edi, %eax\n" /* line 124 | f */
        "addl $0x12c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf46cbc_00046dc8:\n"
        "movl %esi, 4(%esp)\n" /* line 108 */
        "movl $str_00217dd0, (%esp)\n" /* "FS_SV_FOpenFileWrite: %s
" */
        "calll Com_Printf\n"
        "jmp .Lf46cbc_00046d4a\n"
    );
}

/* line 134 */
__attribute__((naked))
int FS_SV_FOpenFileRead(const char *filename, fileHandle_t *fp)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 134 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x11c, %esp\n"
        /* { scope 1 */
        "calll FS_CheckFileSystemStarted\n" /* line 139 */
        "movl $0, (%esp)\n" /* line 141 */
        "calll FS_HandleForFile\n"
        "movl %eax, %esi\n" /* f */
        "movl imp_fsh, %edx\n" /* line 142 */
        "leal (%eax, %eax, 8), %eax\n"
        "shll $3, %eax\n"
        "subl %esi, %eax\n" /* f */
        "shll $2, %eax\n"
        "leal (%eax, %edx), %ebx\n"
        "movl $0, 0x14(%ebx)\n"
        "movl $0x100, 8(%esp)\n" /* line 144 */
        "movl 8(%ebp), %ecx\n" /* filename */
        "movl %ecx, 4(%esp)\n"
        "leal 0x1c(%eax, %edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "leal -0x118(%ebp), %eax\n" /* line 147 | ospath */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002157b8, 8(%esp)\n"
        "movl 8(%ebp), %edx\n" /* filename */
        "movl %edx, 4(%esp)\n"
        "movl imp_fs_homepath, %ecx\n"
        "movl (%ecx), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_BuildOSPath\n"
        "cld\n" /* line 149 */
        "movl $0xffffffff, %ecx\n"
        "leal -0x118(%ebp), %edi\n" /* ospath */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movb $0, -0x11a(%ecx, %ebp)\n"
        "movl imp_fs_debug, %edx\n" /* line 151 */
        "movl (%edx), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf46dde_00046ed4\n"
        ".Lf46dde_00046e88:\n"
        "movl $str_00215b98, 4(%esp)\n" /* line 154 */
        "leal -0x118(%ebp), %eax\n" /* ospath */
        "movl %eax, (%esp)\n"
        "calll FS_FileOpen\n"
        "movl %eax, (%ebx)\n"
        "movl $0, 8(%ebx)\n" /* line 155 */
        "testl %eax, %eax\n" /* line 156 */
        "je .Lf46dde_00046eec\n"
        ".Lf46dde_00046eab:\n"
        "movl 0xc(%ebp), %eax\n" /* line 196 | fp */
        "movl %esi, (%eax)\n" /* f */
        "testl %esi, %esi\n" /* line 197 | f */
        "jne .Lf46dde_00046ec1\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x11c, %esp\n" /* line 202 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf46dde_00046ec1:\n"
        "movl %esi, (%esp)\n" /* line 199 | f */
        "calll FS_filelength\n"
        /* } scope */
        "addl $0x11c, %esp\n" /* line 202 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf46dde_00046ed4:\n"
        "leal -0x118(%ebp), %ecx\n" /* line 152 | ospath */
        "movl %ecx, 4(%esp)\n"
        "movl $str_00217dfc, (%esp)\n" /* "FS_SV_FOpenFileRead (fs_homepath): %s
" */
        "calll Com_Printf\n"
        "jmp .Lf46dde_00046e88\n"
        ".Lf46dde_00046eec:\n"
        "movl imp_fs_basepath, %edi\n" /* line 159 */
        "movl (%edi), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl imp_fs_homepath, %edx\n"
        "movl (%edx), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf46dde_00046fc7\n"
        ".Lf46dde_00046f16:\n"
        "leal (%esi, %esi, 8), %eax\n" /* line 178 | f */
        "shll $3, %eax\n"
        "subl %esi, %eax\n" /* f */
        "leal (, %eax, 4), %ebx\n"
        "movl imp_fsh, %edx\n"
        "movl (%ebx, %edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf46dde_00046eab\n"
        "leal -0x118(%ebp), %ecx\n" /* line 181 | ospath */
        "movl %ecx, 0xc(%esp)\n"
        "movl $str_002157b8, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* filename */
        "movl %eax, 4(%esp)\n"
        "movl imp_fs_cdpath, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_BuildOSPath\n"
        "cld\n" /* line 182 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "leal -0x118(%ebp), %edi\n" /* ospath */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movb $0, -0x11a(%ecx, %ebp)\n"
        "movl imp_fs_debug, %eax\n" /* line 184 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %edi\n"
        "testl %edi, %edi\n"
        "jne .Lf46dde_0004705c\n"
        ".Lf46dde_00046f8d:\n"
        "movl $str_00215b98, 4(%esp)\n" /* line 187 */
        "leal -0x118(%ebp), %ecx\n" /* ospath */
        "movl %ecx, (%esp)\n"
        "calll FS_FileOpen\n"
        "movl imp_fsh, %edx\n"
        "movl %eax, (%ebx, %edx)\n"
        "leal (%ebx, %edx), %eax\n" /* line 188 */
        "movl $0, 8(%eax)\n"
        "movl (%eax), %ecx\n" /* line 190 */
        "testl %ecx, %ecx\n"
        "movl $0, %eax\n"
        "cmovel %eax, %esi\n" /* f */
        "jmp .Lf46dde_00046eab\n"
        ".Lf46dde_00046fc7:\n"
        "leal -0x118(%ebp), %ecx\n" /* line 162 | ospath */
        "movl %ecx, 0xc(%esp)\n"
        "movl $str_002157b8, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* filename */
        "movl %eax, 4(%esp)\n"
        "movl (%edi), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_BuildOSPath\n"
        "cld\n" /* line 163 */
        "movl $0xffffffff, %ecx\n"
        "leal -0x118(%ebp), %edi\n" /* ospath */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movb $0, -0x11a(%ecx, %ebp)\n"
        "movl imp_fs_debug, %edx\n" /* line 165 */
        "movl (%edx), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf46dde_00047044\n"
        ".Lf46dde_00047016:\n"
        "movl $str_00215b98, 4(%esp)\n" /* line 168 */
        "leal -0x118(%ebp), %eax\n" /* ospath */
        "movl %eax, (%esp)\n"
        "calll FS_FileOpen\n"
        "movl %eax, (%ebx)\n"
        "movl $0, 8(%ebx)\n" /* line 169 */
        "testl %eax, %eax\n" /* line 171 */
        "jne .Lf46dde_00046eab\n"
        "xorl %esi, %esi\n" /* f */
        "jmp .Lf46dde_00046f16\n"
        ".Lf46dde_00047044:\n"
        "leal -0x118(%ebp), %ecx\n" /* line 166 | ospath */
        "movl %ecx, 4(%esp)\n"
        "movl $str_00217e24, (%esp)\n" /* "FS_SV_FOpenFileRead (fs_basepath): %s
" */
        "calll Com_Printf\n"
        "jmp .Lf46dde_00047016\n"
        ".Lf46dde_0004705c:\n"
        "leal -0x118(%ebp), %edx\n" /* line 185 | ospath */
        "movl %edx, 4(%esp)\n"
        "movl $str_00217e4c, (%esp)\n" /* "FS_SV_FOpenFileRead (fs_cdpath) : %s
" */
        "calll Com_Printf\n"
        "jmp .Lf46dde_00046f8d\n"
    );
}

/* line 211 */
__attribute__((naked))
double FS_SV_Rename(const char *from, const char *to)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 211 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x21c, %esp\n"
        /* { scope 1 */
        "calll FS_CheckFileSystemStarted\n" /* line 217 */
        "leal -0x118(%ebp), %eax\n" /* line 219 | from_ospath */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002157b8, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* from */
        "movl %eax, 4(%esp)\n"
        "movl imp_fs_homepath, %ebx\n"
        "movl (%ebx), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_BuildOSPath\n"
        "leal -0x218(%ebp), %esi\n" /* line 220 | to_ospath */
        "movl %esi, 0xc(%esp)\n"
        "movl $str_002157b8, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* to */
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_BuildOSPath\n"
        "movl $0xffffffff, %edx\n" /* line 221 */
        "xorl %eax, %eax\n"
        "cld\n"
        "movl %edx, %ecx\n"
        "leal -0x118(%ebp), %edi\n" /* from_ospath */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movb $0, -0x11a(%ecx, %ebp)\n"
        "movl %edx, %ecx\n" /* line 222 */
        "movl %esi, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movb $0, -0x21a(%ecx, %ebp)\n"
        "movl imp_fs_debug, %eax\n" /* line 224 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf47078_00047156\n"
        ".Lf47078_00047115:\n"
        "movl %esi, 4(%esp)\n" /* line 227 */
        "leal -0x118(%ebp), %eax\n" /* from_ospath */
        "movl %eax, (%esp)\n"
        "calll rename\n"
        "testl %eax, %eax\n"
        "je .Lf47078_0004714b\n"
        "movl %esi, 4(%esp)\n" /* line 230 */
        "leal -0x118(%ebp), %eax\n" /* from_ospath */
        "movl %eax, (%esp)\n"
        "calll FS_CopyFile\n"
        "leal -0x118(%ebp), %eax\n" /* line 231 | from_ospath */
        "movl %eax, (%esp)\n"
        "calll FS_Remove\n"
        /* } scope */
        ".Lf47078_0004714b:\n"
        "addl $0x21c, %esp\n" /* line 234 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf47078_00047156:\n"
        "movl %esi, 8(%esp)\n" /* line 225 */
        "leal -0x118(%ebp), %eax\n" /* from_ospath */
        "movl %eax, 4(%esp)\n"
        "movl $str_00217e74, (%esp)\n" /* "FS_SV_Rename: %s --> %s
" */
        "calll Com_Printf\n"
        "jmp .Lf47078_00047115\n"
    );
}

/* line 243 */
__attribute__((naked))
char * FS_ShiftStr(const char *string, int shift)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 243 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xc, %esp\n"
        "movl 8(%ebp), %esi\n" /* string */
        /* { scope 1 */
        "cld\n" /* line 248 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* string */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "testl %ecx, %ecx\n" /* line 249 */
        "jg .Lf47172_000471a9\n"
        "xorl %eax, %eax\n"
        "movb $0, buf(%eax)\n" /* line 251 */
        /* } scope */
        "movl $buf, %eax\n" /* line 253 */
        "addl $0xc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf47172_000471a9:\n"
        "movzbl 0xc(%ebp), %ebx\n" /* line 249 | shift */
        "xorl %edx, %edx\n"
        ".Lf47172_000471af:\n"
        "movl %ebx, %eax\n" /* line 250 */
        "addb (%esi, %edx), %al\n" /* string */
        "movb %al, buf(%edx)\n"
        "addl $1, %edx\n" /* line 249 */
        "cmpl %ecx, %edx\n"
        "jne .Lf47172_000471af\n"
        "movl %ecx, %eax\n"
        "movb $0, buf(%eax)\n" /* line 251 */
        /* } scope */
        "movl $buf, %eax\n" /* line 253 */
        "addl $0xc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 607 */
__attribute__((naked))
double FS_Dir_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 607 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 615 */
        "subl $1, %eax\n"
        "jle .Lf471d8_000471f4\n"
        "calll Cmd_Argc\n"
        "cmpl $3, %eax\n"
        "jle .Lf471d8_00047207\n"
        ".Lf471d8_000471f4:\n"
        "movl $str_00217e90, (%esp)\n" /* line 617 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x30, %esp\n" /* line 642 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf471d8_00047207:\n"
        "calll Cmd_Argc\n" /* line 621 */
        "cmpl $2, %eax\n"
        "je .Lf471d8_00047290\n"
        "movl $1, (%esp)\n" /* line 628 */
        "calll Cmd_Argv\n"
        "movl %eax, %ebx\n" /* i */
        "movl $2, (%esp)\n" /* line 629 */
        "calll Cmd_Argv\n"
        "movl %eax, %esi\n" /* dirnames */
        ".Lf471d8_0004722d:\n"
        "movl %esi, 8(%esp)\n" /* line 632 | dirnames */
        "movl %ebx, 4(%esp)\n" /* i */
        "movl $str_00217eb4, (%esp)\n" /* "Directory of %s %s
" */
        "calll Com_Printf\n"
        "movl $str_00217ec8, (%esp)\n" /* line 633 */
        "calll Com_Printf\n"
        "movl $0xa, 0x10(%esp)\n" /* line 635 */
        "leal -0xc(%ebp), %eax\n" /* ndirs */
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* dirnames */
        "movl %ebx, (%esp)\n" /* i */
        "calll FS_ListFiles\n"
        "movl %eax, %esi\n" /* dirnames */
        "movl -0xc(%ebp), %eax\n" /* line 637 | ndirs */
        "testl %eax, %eax\n"
        "jg .Lf471d8_000472a5\n"
        ".Lf471d8_00047279:\n"
        "movl $0xa, 4(%esp)\n" /* line 641 */
        "movl %esi, (%esp)\n" /* dirnames */
        "calll FS_FreeFileList\n"
        /* } scope */
        "addl $0x30, %esp\n" /* line 642 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf471d8_00047290:\n"
        "movl $1, (%esp)\n" /* line 623 */
        "calll Cmd_Argv\n"
        "movl %eax, %ebx\n" /* i */
        "movl $str_002157b8, %esi\n" /* dirnames */
        "jmp .Lf471d8_0004722d\n"
        ".Lf471d8_000472a5:\n"
        "xorl %ebx, %ebx\n" /* line 637 | i */
        ".Lf471d8_000472a7:\n"
        "movl (%esi, %ebx, 4), %eax\n" /* line 639 | dirnames */
        "movl %eax, 4(%esp)\n"
        "movl $str_00215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "addl $1, %ebx\n" /* line 637 | i */
        "cmpl %ebx, -0xc(%ebp)\n" /* i, ndirs */
        "jg .Lf471d8_000472a7\n"
        "jmp .Lf471d8_00047279\n"
    );
}

/* line 650 */
__attribute__((naked))
double FS_NewDir_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 650 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 657 */
        "subl $1, %eax\n"
        "jle .Lf472c4_000473a6\n"
        "movl $1, (%esp)\n" /* line 664 */
        "calll Cmd_Argv\n"
        "movl %eax, %ebx\n" /* filter */
        "movl $str_00217ec8, (%esp)\n" /* line 666 */
        "calll Com_Printf\n"
        "movl $0xa, 0x18(%esp)\n" /* line 668 */
        "leal -0x1c(%ebp), %eax\n" /* ndirs */
        "movl %eax, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* filter */
        "movl $str_002157b8, 8(%esp)\n"
        "movl $str_002157b8, 4(%esp)\n"
        "movl imp_fs_searchpaths, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_ListFilteredFiles\n"
        "movl %eax, %edi\n" /* dirnames */
        "movl -0x1c(%ebp), %eax\n" /* line 670 | ndirs */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* dirnames */
        "calll FS_SortFileList\n"
        "movl -0x1c(%ebp), %edx\n" /* line 672 | ndirs */
        "testl %edx, %edx\n"
        "jg .Lf472c4_0004736f\n"
        ".Lf472c4_00047347:\n"
        "movl %edx, 4(%esp)\n" /* line 677 */
        "movl $str_00217f10, (%esp)\n" /* "%d files listed
" */
        "calll Com_Printf\n"
        "movl $0xa, 4(%esp)\n" /* line 678 */
        "movl %edi, (%esp)\n" /* dirnames */
        "calll FS_FreeFileList\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 679 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf472c4_0004736f:\n"
        "movl $1, %esi\n" /* line 672 */
        "leal 4(%edi), %ebx\n" /* dirnames, filter */
        ".Lf472c4_00047377:\n"
        "movl -4(%ebx), %eax\n" /* line 674 | filter */
        "movl %eax, (%esp)\n"
        "calll FS_ConvertPath\n"
        "movl -4(%ebx), %eax\n" /* line 675 | filter */
        "movl %eax, 4(%esp)\n"
        "movl $str_00215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "movl %esi, %eax\n"
        "movl -0x1c(%ebp), %edx\n" /* line 672 | ndirs */
        "addl $1, %esi\n"
        "addl $4, %ebx\n" /* filter */
        "cmpl %eax, %edx\n"
        "jg .Lf472c4_00047377\n"
        "jmp .Lf472c4_00047347\n"
        ".Lf472c4_000473a6:\n"
        "movl $str_00217edc, (%esp)\n" /* line 659 */
        "calll Com_Printf\n"
        "movl $str_00217ef4, (%esp)\n" /* line 660 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 679 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 690 */
__attribute__((naked))
double FS_TouchFile_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 690 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "calll Cmd_Argc\n" /* line 692 */
        "cmpl $2, %eax\n"
        "je .Lf473c6_000473e4\n"
        "movl $str_00217f24, (%esp)\n" /* line 694 */
        "calll Com_Printf\n"
        "leave\n" /* line 698 */
        "retl\n"
        ".Lf473c6_000473e4:\n"
        "movl $1, (%esp)\n" /* line 697 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll FS_TouchFile\n"
        "leave\n" /* line 698 */
        "retl\n"
    );
}

/* line 711 */
__attribute__((naked))
qboolean FS_iwIwd(char *iwd, char *base)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 711 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %esi\n" /* iwd */
        "movl 0xc(%ebp), %edi\n" /* base */
        "xorl %ebx, %ebx\n"
        "jmp .Lf473fa_00047415\n"
        /* { scope 1 */
        ".Lf473fa_0004740d:\n"
        "addl $1, %ebx\n" /* line 717 | i */
        "cmpl $0x19, %ebx\n" /* i */
        "je .Lf473fa_00047446\n"
        ".Lf473fa_00047415:\n"
        "movl %ebx, 8(%esp)\n" /* line 719 | i */
        "movl %edi, 4(%esp)\n" /* base */
        "movl $str_00217f40, (%esp)\n" /* "%s/iw_%02d" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* iwd */
        "calll FS_FilenameCompare\n"
        "testl %eax, %eax\n"
        "jne .Lf473fa_0004740d\n"
        ".Lf473fa_00047439:\n"
        "movl $1, %eax\n" /* line 734 */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 743 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf473fa_00047446:\n"
        "movl $str_0021703c, 4(%esp)\n" /* line 724 */
        "movl %esi, (%esp)\n" /* iwd */
        "calll strstr\n"
        "movl %eax, %ebx\n" /* i */
        "testl %eax, %eax\n" /* line 725 */
        "je .Lf473fa_00047497\n"
        "movl %esi, 4(%esp)\n" /* line 727 | iwd */
        "leal -0x58(%ebp), %eax\n" /* szFile */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl %ebx, %eax\n" /* line 728 | i */
        "subl %esi, %eax\n" /* iwd */
        "movb $0, -0x4e(%ebp, %eax)\n"
        "movl %edi, 4(%esp)\n" /* line 730 | base */
        "movl $str_00217f4c, (%esp)\n" /* "%s/localized_" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %eax\n" /* szFile */
        "movl %eax, (%esp)\n"
        "calll FS_FilenameCompare\n"
        "testl %eax, %eax\n"
        "je .Lf473fa_000474a1\n"
        ".Lf473fa_00047497:\n"
        "xorl %eax, %eax\n" /* line 734 */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 743 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf473fa_000474a1:\n"
        "leal 0xa(%ebx), %eax\n" /* line 732 | i */
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %eax\n" /* szFile */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "leal -0x58(%ebp), %eax\n" /* line 733 | szFile */
        "movl %eax, (%esp)\n"
        "calll I_strlwr\n"
        "xorl %ebx, %ebx\n" /* i */
        "jmp .Lf473fa_000474ca\n"
        ".Lf473fa_000474c2:\n"
        "addl $1, %ebx\n" /* line 734 | i */
        "cmpl $0x19, %ebx\n" /* i */
        "je .Lf473fa_00047497\n"
        ".Lf473fa_000474ca:\n"
        "movl %ebx, 4(%esp)\n" /* line 736 | i */
        "movl $str_00217f5c, (%esp)\n" /* "_iw%02d" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %eax\n" /* szFile */
        "movl %eax, (%esp)\n"
        "calll strstr\n"
        "testl %eax, %eax\n"
        "je .Lf473fa_000474c2\n"
        "jmp .Lf473fa_00047439\n"
    );
}

/* line 875 */
__attribute__((naked))
double FS_AddCommands(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 875 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl imp___Z9FS_Path_fv, %eax\n" /* line 877 */
        "movl %eax, 4(%esp)\n"
        "movl $str_00216da8, (%esp)\n" /* "path" */
        "calll Cmd_AddCommand\n"
        "movl imp___Z13FS_FullPath_fv, %eax\n" /* line 878 */
        "movl %eax, 4(%esp)\n"
        "movl $str_00216db0, (%esp)\n" /* "fullpath" */
        "calll Cmd_AddCommand\n"
        "movl $FS_Dir_f, 4(%esp)\n" /* line 879 */
        "movl $str_00216dbc, (%esp)\n" /* "dir" */
        "calll Cmd_AddCommand\n"
        "movl $FS_NewDir_f, 4(%esp)\n" /* line 880 */
        "movl $str_00216dc0, (%esp)\n" /* "fdir" */
        "calll Cmd_AddCommand\n"
        "movl $FS_TouchFile_f, 4(%esp)\n" /* line 881 */
        "movl $str_00216dc8, (%esp)\n" /* "touchFile" */
        "calll Cmd_AddCommand\n"
        "leave\n" /* line 882 */
        "retl\n"
    );
}

/* line 894 */
__attribute__((naked))
double FS_SetRestrictions(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 894 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl imp_fs_restrict, %eax\n" /* line 901 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf47560_0004757a\n"
        ".Lf47560_00047574:\n"
        "addl $0x14, %esp\n" /* line 936 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf47560_0004757a:\n"
        "movl $1, 4(%esp)\n" /* line 906 */
        "movl %eax, (%esp)\n"
        "calll Dvar_SetBool\n"
        "movl $str_00217f64, (%esp)\n" /* line 908 */
        "calll Com_Printf\n"
        "movl $0, (%esp)\n" /* line 911 */
        "calll FS_Shutdown\n"
        "movl $str_00217f88, (%esp)\n" /* line 914 */
        "calll FS_Startup\n"
        /* { scope 1 */
        "movl imp_fs_searchpaths, %eax\n" /* line 923 */
        "movl (%eax), %ebx\n" /* path */
        "testl %ebx, %ebx\n" /* path */
        "je .Lf47560_00047574\n"
        ".Lf47560_000475b9:\n"
        "movl %ebx, (%esp)\n" /* line 925 | path */
        "calll FS_UseSearchPath\n"
        "testl %eax, %eax\n"
        "je .Lf47560_000475f1\n"
        "movl 4(%ebx), %eax\n" /* line 928 | path */
        "testl %eax, %eax\n"
        "je .Lf47560_000475f1\n"
        "movl 0x304(%eax), %eax\n" /* line 931 */
        "cmpl $0xb1f595f5, %eax\n"
        "je .Lf47560_000475f1\n"
        "movl %eax, 8(%esp)\n" /* line 932 */
        "movl $str_00217f94, 4(%esp)\n" /* "Corrupted iw0.iwd: %u" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        ".Lf47560_000475f1:\n"
        "movl (%ebx), %ebx\n" /* line 923 | path */
        "testl %ebx, %ebx\n" /* path */
        "jne .Lf47560_000475b9\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 936 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 951 */
__attribute__((naked))
const char * FS_LoadedIwdChecksums(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 951 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movb $0, info2\n" /* line 955 */
        "movl imp_fs_searchpaths, %eax\n" /* line 957 */
        "movl (%eax), %ebx\n" /* search */
        "testl %ebx, %ebx\n" /* search */
        "jne .Lf475fe_0004761f\n"
        "jmp .Lf475fe_00047661\n"
        ".Lf475fe_00047619:\n"
        "movl (%ebx), %ebx\n" /* search */
        "testl %ebx, %ebx\n" /* search */
        "je .Lf475fe_00047661\n"
        ".Lf475fe_0004761f:\n"
        "movl 4(%ebx), %eax\n" /* line 960 | search */
        "testl %eax, %eax\n"
        "je .Lf475fe_00047619\n"
        "movl 0xc(%ebx), %edx\n" /* line 964 | search */
        "testl %edx, %edx\n"
        "jne .Lf475fe_00047619\n"
        "movl 0x304(%eax), %eax\n" /* line 967 */
        "movl %eax, 4(%esp)\n"
        "movl $str_00217fac, (%esp)\n" /* "%i " */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2000, 4(%esp)\n"
        "movl $info2, (%esp)\n"
        "calll I_strncat\n"
        "movl (%ebx), %ebx\n" /* line 957 | search */
        "testl %ebx, %ebx\n" /* search */
        "jne .Lf475fe_0004761f\n"
        /* } scope */
        ".Lf475fe_00047661:\n"
        "movl $info2, %eax\n" /* line 971 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 982 */
__attribute__((naked))
const char * FS_LoadedIwdNames(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 982 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movb $0, info3\n" /* line 986 */
        "movl imp_fs_searchpaths, %eax\n" /* line 988 */
        "movl (%eax), %ebx\n" /* search */
        "testl %ebx, %ebx\n" /* search */
        "jne .Lf4766c_000476ad\n"
        "jmp .Lf4766c_000476e2\n"
        ".Lf4766c_00047687:\n"
        "movl 4(%ebx), %eax\n" /* line 1001 | search */
        "addl $0x100, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2000, 4(%esp)\n"
        "movl $info3, (%esp)\n"
        "calll I_strncat\n"
        ".Lf4766c_000476a7:\n"
        "movl (%ebx), %ebx\n" /* line 988 | search */
        "testl %ebx, %ebx\n" /* search */
        "je .Lf4766c_000476e2\n"
        ".Lf4766c_000476ad:\n"
        "movl 4(%ebx), %eax\n" /* line 991 | search */
        "testl %eax, %eax\n"
        "je .Lf4766c_000476a7\n"
        "movl 0xc(%ebx), %ecx\n" /* line 995 | search */
        "testl %ecx, %ecx\n"
        "jne .Lf4766c_000476a7\n"
        "cmpb $0, info3\n" /* line 998 */
        "je .Lf4766c_00047687\n"
        "movl $str_00217914, 8(%esp)\n" /* line 999 */
        "movl $0x2000, 4(%esp)\n"
        "movl $info3, (%esp)\n"
        "calll I_strncat\n"
        "jmp .Lf4766c_00047687\n"
        /* } scope */
        ".Lf4766c_000476e2:\n"
        "movl $info3, %eax\n" /* line 1005 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1017 */
__attribute__((naked))
const char * FS_LoadedIwdPureChecksums(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1017 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movb $0, info4\n" /* line 1021 */
        "movl imp_fs_searchpaths, %eax\n" /* line 1023 */
        "movl (%eax), %ebx\n" /* search */
        "testl %ebx, %ebx\n" /* search */
        "jne .Lf476ee_0004770f\n"
        "jmp .Lf476ee_00047751\n"
        ".Lf476ee_00047709:\n"
        "movl (%ebx), %ebx\n" /* search */
        "testl %ebx, %ebx\n" /* search */
        "je .Lf476ee_00047751\n"
        ".Lf476ee_0004770f:\n"
        "movl 4(%ebx), %eax\n" /* line 1026 | search */
        "testl %eax, %eax\n"
        "je .Lf476ee_00047709\n"
        "movl 0xc(%ebx), %edx\n" /* line 1030 | search */
        "testl %edx, %edx\n"
        "jne .Lf476ee_00047709\n"
        "movl 0x308(%eax), %eax\n" /* line 1033 */
        "movl %eax, 4(%esp)\n"
        "movl $str_00217fac, (%esp)\n" /* "%i " */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2000, 4(%esp)\n"
        "movl $info4, (%esp)\n"
        "calll I_strncat\n"
        "movl (%ebx), %ebx\n" /* line 1023 | search */
        "testl %ebx, %ebx\n" /* search */
        "jne .Lf476ee_0004770f\n"
        /* } scope */
        ".Lf476ee_00047751:\n"
        "movl $info4, %eax\n" /* line 1037 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1048 */
__attribute__((naked))
const char * FS_ReferencedIwdChecksums(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1048 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movb $0, info5\n" /* line 1052 */
        "movl imp_fs_searchpaths, %eax\n" /* line 1054 */
        "movl (%eax), %ebx\n" /* search */
        "testl %ebx, %ebx\n" /* search */
        "je .Lf4775c_000477dd\n"
        ".Lf4775c_00047775:\n"
        "movl 4(%ebx), %eax\n" /* line 1057 | search */
        "testl %eax, %eax\n"
        "je .Lf4775c_000477d7\n"
        "cmpb $0, 0x310(%eax)\n" /* line 1060 */
        "jne .Lf4775c_000477a9\n"
        "movl $4, 8(%esp)\n"
        "movl $str_00216f3c, 4(%esp)\n" /* "main" */
        "addl $0x200, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strnicmp\n"
        "testl %eax, %eax\n"
        "je .Lf4775c_000477d7\n"
        "movl 4(%ebx), %eax\n" /* search */
        ".Lf4775c_000477a9:\n"
        "movl 0x304(%eax), %eax\n" /* line 1061 */
        "movl %eax, 4(%esp)\n"
        "movl $str_00217fac, (%esp)\n" /* "%i " */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2000, 4(%esp)\n"
        "movl $info5, (%esp)\n"
        "calll I_strncat\n"
        ".Lf4775c_000477d7:\n"
        "movl (%ebx), %ebx\n" /* line 1054 | search */
        "testl %ebx, %ebx\n" /* search */
        "jne .Lf4775c_00047775\n"
        /* } scope */
        ".Lf4775c_000477dd:\n"
        "movl $info5, %eax\n" /* line 1065 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1076 */
__attribute__((naked))
const char * FS_ReferencedIwdNames(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1076 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movb $0, info8\n" /* line 1080 */
        "movl imp_fs_searchpaths, %eax\n" /* line 1084 */
        "movl (%eax), %ebx\n" /* search */
        "testl %ebx, %ebx\n" /* search */
        "jne .Lf477e8_00047875\n"
        "jmp .Lf477e8_000478b0\n"
        ".Lf477e8_00047806:\n"
        "cmpb $0, info8\n" /* line 1092 */
        "jne .Lf477e8_000478bb\n"
        ".Lf477e8_00047813:\n"
        "movl 4(%ebx), %eax\n" /* line 1095 | search */
        "addl $0x200, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2000, 4(%esp)\n"
        "movl $info8, (%esp)\n"
        "calll I_strncat\n"
        "movl $str_00216f38, 8(%esp)\n" /* line 1096 */
        "movl $0x2000, 4(%esp)\n"
        "movl $info8, (%esp)\n"
        "calll I_strncat\n"
        "movl 4(%ebx), %eax\n" /* line 1097 | search */
        "addl $0x100, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2000, 4(%esp)\n"
        "movl $info8, (%esp)\n"
        "calll I_strncat\n"
        ".Lf477e8_0004786f:\n"
        "movl (%ebx), %ebx\n" /* line 1084 | search */
        "testl %ebx, %ebx\n" /* search */
        "je .Lf477e8_000478b0\n"
        ".Lf477e8_00047875:\n"
        "movl 4(%ebx), %eax\n" /* line 1087 | search */
        "testl %eax, %eax\n"
        "je .Lf477e8_0004786f\n"
        "cmpb $0, 0x310(%eax)\n" /* line 1090 */
        "jne .Lf477e8_00047806\n"
        "movl $4, 8(%esp)\n"
        "movl $str_00216f3c, 4(%esp)\n" /* "main" */
        "addl $0x200, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strnicmp\n"
        "testl %eax, %eax\n"
        "jne .Lf477e8_00047806\n"
        "movl (%ebx), %ebx\n" /* line 1084 | search */
        "testl %ebx, %ebx\n" /* search */
        "jne .Lf477e8_00047875\n"
        /* } scope */
        ".Lf477e8_000478b0:\n"
        "movl $info8, %eax\n" /* line 1102 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf477e8_000478bb:\n"
        "movl $str_00217914, 8(%esp)\n" /* line 1093 */
        "movl $0x2000, 4(%esp)\n"
        "movl $info8, (%esp)\n"
        "calll I_strncat\n"
        "jmp .Lf477e8_00047813\n"
    );
}

/* line 1119 */
__attribute__((naked))
const char * FS_ReferencedIwdPureChecksums(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1119 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movb $0, info6\n" /* line 1124 */
        "movl imp_fs_checksumFeed, %eax\n" /* line 1125 */
        "movl (%eax), %esi\n"
        "movl $0xffffffff, %edx\n" /* line 1131 */
        "movl $info6, %edi\n" /* numIwds */
        "xorl %eax, %eax\n"
        "cld\n"
        "movl %edx, %ecx\n"
        "repne scasb %es:(%edi), %al\n" /* numIwds */
        "notl %ecx\n"
        "movb $0, info6(%ecx)\n"
        "movl $info6, %edi\n" /* line 1132 | numIwds */
        "movl %edx, %ecx\n"
        "repne scasb %es:(%edi), %al\n" /* numIwds */
        "notl %ecx\n"
        "movb $0, info6+1(%ecx)\n"
        "movl $info6, %edi\n" /* line 1133 | numIwds */
        "movl %edx, %ecx\n"
        "repne scasb %es:(%edi), %al\n" /* numIwds */
        "notl %ecx\n"
        "movb $0x40, scrMemTreeGlob+525183(%ecx)\n"
        "movl $info6, %edi\n" /* line 1134 | numIwds */
        "movl %edx, %ecx\n"
        "repne scasb %es:(%edi), %al\n" /* numIwds */
        "notl %ecx\n"
        "movb $0x20, scrMemTreeGlob+525183(%ecx)\n"
        "movl imp_fs_searchpaths, %eax\n" /* line 1136 */
        "movl (%eax), %ebx\n" /* search */
        "testl %ebx, %ebx\n" /* search */
        "je .Lf478dc_00047a1d\n"
        "xorl %edi, %edi\n" /* numIwds */
        "jmp .Lf478dc_0004795c\n"
        ".Lf478dc_00047956:\n"
        "movl (%ebx), %ebx\n" /* search */
        "testl %ebx, %ebx\n" /* search */
        "je .Lf478dc_000479b3\n"
        ".Lf478dc_0004795c:\n"
        "movl 4(%ebx), %eax\n" /* line 1139 | search */
        "testl %eax, %eax\n"
        "je .Lf478dc_00047956\n"
        "movl 0xc(%ebx), %ecx\n" /* line 1143 | search */
        "testl %ecx, %ecx\n"
        "jne .Lf478dc_00047956\n"
        "cmpb $0, 0x310(%eax)\n" /* line 1147 */
        "je .Lf478dc_00047956\n"
        "movl 0x308(%eax), %eax\n" /* line 1149 */
        "movl %eax, 4(%esp)\n"
        "movl $str_00217fac, (%esp)\n" /* "%i " */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2000, 4(%esp)\n"
        "movl $info6, (%esp)\n"
        "calll I_strncat\n"
        "movl 4(%ebx), %eax\n" /* line 1150 | search */
        "xorl 0x308(%eax), %esi\n"
        "addl $1, %edi\n" /* line 1151 | numIwds */
        "movl (%ebx), %ebx\n" /* line 1136 | search */
        "testl %ebx, %ebx\n" /* search */
        "jne .Lf478dc_0004795c\n"
        ".Lf478dc_000479b3:\n"
        "movl imp_fs_fakeChkSum, %eax\n" /* line 1155 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf478dc_000479e6\n"
        "movl %eax, 4(%esp)\n" /* line 1156 */
        "movl $str_00217fac, (%esp)\n" /* "%i " */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2000, 4(%esp)\n"
        "movl $info6, (%esp)\n"
        "calll I_strncat\n"
        ".Lf478dc_000479e6:\n"
        "xorl %esi, %edi\n" /* line 1160 | numIwds */
        "movl %edi, 4(%esp)\n" /* numIwds */
        "movl $str_00217fac, (%esp)\n" /* "%i " */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2000, 4(%esp)\n"
        "movl $info6, (%esp)\n"
        "calll I_strncat\n"
        /* } scope */
        "movl $info6, %eax\n" /* line 1163 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf478dc_00047a1d:\n"
        "xorl %edi, %edi\n" /* line 1136 | numIwds */
        "jmp .Lf478dc_000479b3\n"
    );
}

/* line 1514 */
__attribute__((naked))
double FS_PureServerSetLoadedIwds(const char *iwdSums, const char *iwdNames)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1514 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x202c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1523 | iwdSums */
        "movl %eax, (%esp)\n"
        "calll Cmd_TokenizeString\n"
        "calll Cmd_Argc\n" /* line 1524 */
        "movl %eax, -0x2024(%ebp)\n" /* c */
        "cmpl $0x400, %eax\n" /* line 1525 */
        "jle .Lf47a22_00047b26\n"
        "movl $0x400, -0x2024(%ebp)\n" /* c */
        ".Lf47a22_00047a59:\n"
        "xorl %ebx, %ebx\n" /* line 1529 | i */
        ".Lf47a22_00047a5b:\n"
        "movl %ebx, (%esp)\n" /* line 1531 | i */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, -0x1018(%ebp, %ebx, 4)\n"
        "addl $1, %ebx\n" /* line 1529 | i */
        "cmpl %ebx, -0x2024(%ebp)\n" /* i, c */
        "jne .Lf47a22_00047a5b\n"
        ".Lf47a22_00047a7d:\n"
        "movl 0xc(%ebp), %eax\n" /* line 1534 | iwdNames */
        "movl %eax, (%esp)\n"
        "calll Cmd_TokenizeString\n"
        "calll Cmd_Argc\n" /* line 1535 */
        "movl %eax, %edi\n" /* d */
        "cmpl $0x400, %eax\n" /* line 1536 */
        "jle .Lf47a22_00047b1d\n"
        "movl $0x400, %edi\n" /* d */
        ".Lf47a22_00047a9f:\n"
        "xorl %ebx, %ebx\n" /* line 1540 | i */
        ".Lf47a22_00047aa1:\n"
        "movl %ebx, (%esp)\n" /* line 1542 | i */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll CopyStringInternal\n"
        "movl %eax, -0x2018(%ebp, %ebx, 4)\n"
        "addl $1, %ebx\n" /* line 1540 | i */
        "cmpl %ebx, %edi\n" /* i, d */
        "jne .Lf47a22_00047aa1\n"
        ".Lf47a22_00047abf:\n"
        "cmpl %edi, -0x2024(%ebp)\n" /* line 1544 | d, c */
        "je .Lf47a22_00047adb\n"
        "movl $str_00217fb0, 4(%esp)\n" /* line 1545 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf47a22_00047adb:\n"
        "movl imp_fs_numServerIwds, %ecx\n" /* line 1548 */
        "movl -0x2024(%ebp), %eax\n" /* c */
        "cmpl (%ecx), %eax\n"
        "je .Lf47a22_00047b9b\n"
        ".Lf47a22_00047aef:\n"
        "movl $8, (%esp)\n" /* line 1568 */
        "calll SND_StopSounds\n"
        "calll FS_ShutdownServerIwdNames\n" /* line 1571 */
        "movl imp_fs_numServerIwds, %ebx\n" /* line 1573 | i */
        "movl -0x2024(%ebp), %ecx\n" /* c */
        "movl %ecx, (%ebx)\n" /* i */
        "testl %ecx, %ecx\n" /* line 1574 */
        "jne .Lf47a22_00047b39\n"
        /* } scope */
        ".Lf47a22_00047b12:\n"
        "addl $0x202c, %esp\n" /* line 1581 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf47a22_00047b1d:\n"
        "testl %eax, %eax\n" /* line 1540 */
        "jle .Lf47a22_00047abf\n"
        "jmp .Lf47a22_00047a9f\n"
        ".Lf47a22_00047b26:\n"
        "movl -0x2024(%ebp), %edi\n" /* line 1529 | c, d */
        "testl %edi, %edi\n" /* d */
        "jle .Lf47a22_00047a7d\n"
        "jmp .Lf47a22_00047a59\n"
        ".Lf47a22_00047b39:\n"
        "movl $str_00217fc8, (%esp)\n" /* line 1576 */
        "calll Com_DPrintf\n"
        "movl (%ebx), %eax\n" /* line 1577 | i */
        "shll $2, %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x1018(%ebp), %eax\n" /* serverIwds */
        "movl %eax, 4(%esp)\n"
        "movl imp_fs_serverIwds, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_Memcpy\n"
        "movl (%ebx), %eax\n" /* line 1578 | i */
        "shll $2, %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x2018(%ebp), %eax\n" /* serverIwdNames */
        "movl %eax, 4(%esp)\n"
        "movl imp_fs_serverIwdNames, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_Memcpy\n"
        "movl imp_fs_fakeChkSum, %eax\n" /* line 1579 */
        "movl $0, (%eax)\n"
        /* } scope */
        "addl $0x202c, %esp\n" /* line 1581 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf47a22_00047b9b:\n"
        "movl -0x2024(%ebp), %ebx\n" /* line 1550 | c, i */
        "testl %ebx, %ebx\n" /* i */
        "jle .Lf47a22_00047c1e\n"
        "movl $0, -0x201c(%ebp)\n"
        ".Lf47a22_00047baf:\n"
        "movl (%ecx), %esi\n" /* line 1552 | j */
        "testl %esi, %esi\n" /* j */
        "jle .Lf47a22_00047aef\n"
        "xorl %esi, %esi\n" /* j */
        "movl imp_fs_serverIwds, %ebx\n" /* i */
        "movl imp_fs_serverIwdNames, %eax\n"
        "movl %eax, -0x2020(%ebp)\n"
        "jmp .Lf47a22_00047be3\n"
        ".Lf47a22_00047bce:\n"
        "addl $1, %esi\n" /* j */
        "addl $4, %ebx\n" /* i */
        "addl $4, -0x2020(%ebp)\n"
        "cmpl (%ecx), %esi\n" /* j */
        "jge .Lf47a22_00047aef\n"
        ".Lf47a22_00047be3:\n"
        "movl -0x201c(%ebp), %edx\n" /* line 1554 */
        "shll $2, %edx\n"
        "movl -0x1018(%ebp, %edx), %eax\n"
        "cmpl (%ebx), %eax\n" /* i */
        "jne .Lf47a22_00047bce\n"
        "movl -0x2020(%ebp), %ecx\n"
        "movl (%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x2018(%ebp, %edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf47a22_00047c49\n"
        "movl imp_fs_numServerIwds, %ecx\n"
        "jmp .Lf47a22_00047bce\n"
        ".Lf47a22_00047c1e:\n"
        "testl %edi, %edi\n" /* line 1560 | d */
        "jle .Lf47a22_00047b12\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf47a22_00047c28:\n"
        "movl -0x2018(%ebp, %ebx, 4), %eax\n" /* line 1561 */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        "addl $1, %ebx\n" /* line 1560 | i */
        "cmpl %ebx, %edi\n" /* i, d */
        "jne .Lf47a22_00047c28\n"
        /* } scope */
        "addl $0x202c, %esp\n" /* line 1581 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf47a22_00047c49:\n"
        "addl $1, -0x201c(%ebp)\n" /* line 1550 */
        "movl -0x201c(%ebp), %eax\n"
        "cmpl %eax, -0x2024(%ebp)\n" /* c */
        "je .Lf47a22_00047c1e\n"
        "movl imp_fs_numServerIwds, %ecx\n"
        "jmp .Lf47a22_00047baf\n"
    );
}

/* line 1593 */
__attribute__((naked))
double FS_PureServerSetReferencedIwds(const char *iwdSums, const char *iwdNames)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1593 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1597 | iwdSums */
        "movl %eax, (%esp)\n"
        "calll Cmd_TokenizeString\n"
        "calll Cmd_Argc\n" /* line 1599 */
        "movl %eax, %edi\n" /* c */
        "cmpl $0x401, %eax\n" /* line 1600 */
        "movl $0x400, %eax\n"
        "cmovgel %eax, %edi\n" /* c */
        "calll FS_ShutdownServerReferencedIwds\n" /* line 1605 */
        "testl %edi, %edi\n" /* line 1607 | c */
        "jg .Lf47c6a_00047ce0\n"
        ".Lf47c6a_00047c9b:\n"
        "movl 0xc(%ebp), %eax\n" /* line 1611 | iwdNames */
        "testl %eax, %eax\n"
        "je .Lf47c6a_00047caa\n"
        "movl 0xc(%ebp), %eax\n" /* iwdNames */
        "cmpb $0, (%eax)\n"
        "jne .Lf47c6a_00047d06\n"
        ".Lf47c6a_00047caa:\n"
        "testl %edi, %edi\n" /* line 1631 | c */
        "jne .Lf47c6a_00047cbd\n"
        ".Lf47c6a_00047cae:\n"
        "movl imp_fs_numServerReferencedIwds, %eax\n" /* line 1635 */
        "movl %edi, (%eax)\n" /* c */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1636 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf47c6a_00047cbd:\n"
        "movl $str_00217fb0, 4(%esp)\n" /* line 1632 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl imp_fs_numServerReferencedIwds, %eax\n" /* line 1635 */
        "movl %edi, (%eax)\n" /* c */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1636 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf47c6a_00047ce0:\n"
        "xorl %ebx, %ebx\n" /* line 1607 | i */
        "movl imp_fs_serverReferencedIwds, %esi\n" /* d */
        ".Lf47c6a_00047ce8:\n"
        "movl %ebx, (%esp)\n" /* line 1609 | i */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, (%esi)\n" /* d */
        "addl $1, %ebx\n" /* line 1607 | i */
        "addl $4, %esi\n" /* d */
        "cmpl %ebx, %edi\n" /* i, c */
        "jne .Lf47c6a_00047ce8\n"
        "jmp .Lf47c6a_00047c9b\n"
        ".Lf47c6a_00047d06:\n"
        "movl %eax, (%esp)\n" /* line 1613 */
        "calll Cmd_TokenizeString\n"
        "calll Cmd_Argc\n" /* line 1615 */
        "movl %eax, %esi\n" /* d */
        "cmpl $0x401, %eax\n" /* line 1616 */
        "movl $0x400, %eax\n"
        "cmovgel %eax, %esi\n" /* d */
        "cmpl %esi, %edi\n" /* line 1621 | d, c */
        "je .Lf47c6a_00047d3a\n"
        "movl $str_00217fb0, 4(%esp)\n" /* line 1622 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf47c6a_00047d3a:\n"
        "testl %esi, %esi\n" /* line 1624 | d */
        "jle .Lf47c6a_00047cae\n"
        "xorl %ebx, %ebx\n" /* i */
        "movl imp_fs_serverReferencedIwdNames, %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        ".Lf47c6a_00047d4d:\n"
        "movl %ebx, (%esp)\n" /* line 1626 | i */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll CopyStringInternal\n"
        "movl -0x1c(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "addl $1, %ebx\n" /* line 1624 | i */
        "addl $4, %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "cmpl %ebx, %esi\n" /* i, d */
        "jne .Lf47c6a_00047d4d\n"
        "jmp .Lf47c6a_00047cae\n"
    );
}

/* line 1644 */
__attribute__((naked))
const char * FS_GetMapBaseName(const char *mapname)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1644 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl $8, 8(%esp)\n" /* line 1652 */
        "movl $str_00217fe8, 4(%esp)\n" /* "maps/mp/" */
        "movl 8(%ebp), %eax\n" /* mapname */
        "movl %eax, (%esp)\n"
        "calll I_strnicmp\n"
        "movl 8(%ebp), %edx\n" /* line 1653 | mapname */
        "addl $8, %edx\n"
        "testl %eax, %eax\n"
        "cmovnel 8(%ebp), %edx\n" /* mapname */
        "movl %edx, 8(%ebp)\n" /* mapname */
        "cld\n" /* line 1654 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %edx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "movl %ecx, %esi\n"
        "notl %esi\n"
        "leal -1(%esi), %ebx\n" /* len */
        "movl $str_00217ff4, 4(%esp)\n" /* line 1655 */
        "leal -3(%edx, %ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "leal -8(%esi), %edx\n" /* line 1656 */
        "testl %eax, %eax\n"
        "cmovel %edx, %ebx\n" /* len */
        "movl %ebx, 8(%esp)\n" /* line 1657 | len */
        "movl 8(%ebp), %eax\n" /* mapname */
        "movl %eax, 4(%esp)\n"
        "movl $basename, (%esp)\n"
        "calll memcpy\n"
        "movb $0, basename(%ebx)\n" /* line 1658 | len */
        "testl %ebx, %ebx\n" /* line 1661 | len */
        "jle .Lf47d74_00047e1b\n"
        "movl $basename, %eax\n"
        "leal basename(%ebx), %edx\n" /* len */
        "jmp .Lf47d74_00047e0c\n"
        ".Lf47d74_00047e05:\n"
        "addl $1, %eax\n" /* line 1664 */
        "cmpl %edx, %eax\n" /* line 1661 */
        "je .Lf47d74_00047e1b\n"
        ".Lf47d74_00047e0c:\n"
        "cmpb $0x25, (%eax)\n" /* line 1663 */
        "jne .Lf47d74_00047e05\n"
        "movb $0x5f, (%eax)\n" /* line 1664 */
        "addl $1, %eax\n"
        "cmpl %edx, %eax\n" /* line 1661 */
        "jne .Lf47d74_00047e0c\n"
        /* } scope */
        ".Lf47d74_00047e1b:\n"
        "movl $basename, %eax\n" /* line 1668 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 465 */
__attribute__((naked))
int FS_GetModList(char *listbuf, int bufsize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 465 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x25c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 481 | listbuf */
        "movb $0, (%eax)\n"
        "movl $1, 0x10(%esp)\n" /* line 484 */
        "leal -0x24(%ebp), %ebx\n" /* dummy, pFiles2 */
        "movl %ebx, 0xc(%esp)\n" /* pFiles2 */
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl imp_fs_homepath, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Sys_ListFiles\n"
        "movl %eax, %edi\n" /* pFiles0 */
        "movl $1, 0x10(%esp)\n" /* line 485 */
        "movl %ebx, 0xc(%esp)\n" /* pFiles2 */
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl imp_fs_basepath, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Sys_ListFiles\n"
        "movl %eax, %esi\n" /* pFiles1 */
        "movl imp_fs_cdpath, %eax\n" /* line 486 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf47e28_00047eb4\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf47e28_000482a8\n"
        ".Lf47e28_00047eb4:\n"
        "xorl %ebx, %ebx\n" /* line 487 | pFiles2 */
        /* { scope 2 */
        "testl %edi, %edi\n" /* line 399 */
        "je .Lf47e28_000482d6\n"
        ".Lf47e28_00047ebe:\n"
        "movl (%edi), %eax\n" /* line 401 */
        "testl %eax, %eax\n"
        "je .Lf47e28_000482d6\n"
        "xorl %eax, %eax\n"
        ".Lf47e28_00047eca:\n"
        "addl $1, %eax\n" /* line 404 */
        "movl (%edi, %eax, 4), %edx\n" /* line 401 */
        "testl %edx, %edx\n"
        "jne .Lf47e28_00047eca\n"
        "movl %eax, %ecx\n"
        /* } scope */
        /* { scope 2 */
        "testl %esi, %esi\n" /* line 399 */
        "je .Lf47e28_000482e0\n"
        ".Lf47e28_00047ede:\n"
        "movl (%esi), %eax\n" /* line 401 */
        "testl %eax, %eax\n"
        "je .Lf47e28_000482e0\n"
        "xorl %edx, %edx\n"
        ".Lf47e28_00047eea:\n"
        "addl $1, %edx\n" /* line 404 */
        "movl (%esi, %edx, 4), %eax\n" /* line 401 */
        "testl %eax, %eax\n"
        "jne .Lf47e28_00047eea\n"
        "movl %edx, %eax\n"
        /* } scope */
        "addl %eax, %ecx\n" /* line 417 */
        /* { scope 2 */
        "testl %ebx, %ebx\n" /* line 399 */
        "je .Lf47e28_000482ec\n"
        ".Lf47e28_00047f00:\n"
        "movl (%ebx), %eax\n" /* line 401 */
        "testl %eax, %eax\n"
        "je .Lf47e28_000482ec\n"
        "xorl %edx, %edx\n"
        ".Lf47e28_00047f0c:\n"
        "addl $1, %edx\n" /* line 404 */
        "movl (%ebx, %edx, 4), %eax\n" /* line 401 */
        "testl %eax, %eax\n"
        "jne .Lf47e28_00047f0c\n"
        "movl %edx, %eax\n"
        /* } scope */
        "leal (%ecx, %eax), %eax\n" /* line 421 */
        "leal 4(, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, -0x22c(%ebp)\n"
        "testl %edi, %edi\n" /* line 424 */
        "je .Lf47e28_0004830e\n"
        ".Lf47e28_00047f38:\n"
        "movl (%edi), %ecx\n" /* line 426 */
        "testl %ecx, %ecx\n"
        "je .Lf47e28_0004830e\n"
        "movl %edi, %eax\n"
        "movl -0x22c(%ebp), %edx\n"
        ".Lf47e28_00047f4a:\n"
        "movl %ecx, (%edx)\n" /* line 427 */
        "addl $4, %edx\n" /* line 426 */
        "movl 4(%eax), %ecx\n"
        "addl $4, %eax\n"
        "testl %ecx, %ecx\n"
        "jne .Lf47e28_00047f4a\n"
        ".Lf47e28_00047f59:\n"
        "testl %esi, %esi\n" /* line 429 */
        "je .Lf47e28_00047f74\n"
        "movl (%esi), %ecx\n" /* line 431 */
        "testl %ecx, %ecx\n"
        "je .Lf47e28_00047f74\n"
        "movl %esi, %eax\n"
        ".Lf47e28_00047f65:\n"
        "movl %ecx, (%edx)\n" /* line 432 */
        "addl $4, %edx\n" /* line 431 */
        "movl 4(%eax), %ecx\n"
        "addl $4, %eax\n"
        "testl %ecx, %ecx\n"
        "jne .Lf47e28_00047f65\n"
        ".Lf47e28_00047f74:\n"
        "testl %ebx, %ebx\n" /* line 434 */
        "je .Lf47e28_00047f8f\n"
        "movl (%ebx), %ecx\n" /* line 436 */
        "testl %ecx, %ecx\n"
        "je .Lf47e28_00047f8f\n"
        "movl %ebx, %eax\n"
        ".Lf47e28_00047f80:\n"
        "movl %ecx, (%edx)\n" /* line 437 */
        "addl $4, %edx\n" /* line 436 */
        "movl 4(%eax), %ecx\n"
        "addl $4, %eax\n"
        "testl %ecx, %ecx\n"
        "jne .Lf47e28_00047f80\n"
        ".Lf47e28_00047f8f:\n"
        "movl $0, (%edx)\n" /* line 441 */
        "testl %edi, %edi\n" /* line 445 */
        "je .Lf47e28_00047fa1\n"
        "movl %edi, (%esp)\n" /* line 446 */
        "calll Z_FreeInternal\n"
        ".Lf47e28_00047fa1:\n"
        "testl %esi, %esi\n" /* line 447 */
        "je .Lf47e28_00047fad\n"
        "movl %esi, (%esp)\n" /* line 448 */
        "calll Z_FreeInternal\n"
        ".Lf47e28_00047fad:\n"
        "testl %ebx, %ebx\n" /* line 449 */
        "je .Lf47e28_00047fb9\n"
        "movl %ebx, (%esp)\n" /* line 450 */
        "calll Z_FreeInternal\n"
        /* { scope 2 */
        ".Lf47e28_00047fb9:\n"
        "movl -0x22c(%ebp), %edi\n" /* line 399 */
        "testl %edi, %edi\n"
        "je .Lf47e28_0004827f\n"
        "movl -0x22c(%ebp), %edx\n" /* line 401 */
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf47e28_0004827f\n"
        "xorl %eax, %eax\n"
        "movl -0x22c(%ebp), %edx\n"
        ".Lf47e28_00047fdf:\n"
        "addl $1, %eax\n" /* line 404 */
        "movl (%edx, %eax, 4), %esi\n" /* line 401 */
        "testl %esi, %esi\n"
        "jne .Lf47e28_00047fdf\n"
        "movl %eax, -0x230(%ebp)\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 493 */
        "jle .Lf47e28_0004827f\n"
        "movl $0, -0x234(%ebp)\n" /* bDrop */
        "movl $0, -0x23c(%ebp)\n" /* nTotal */
        "movl $0, -0x240(%ebp)\n" /* i */
        "movl $0, -0x244(%ebp)\n" /* nMods */
        "jmp .Lf47e28_0004806c\n"
        ".Lf47e28_00048021:\n"
        "jg .Lf47e28_00048319\n" /* line 501 */
        ".Lf47e28_00048027:\n"
        "movl $0, -0x234(%ebp)\n" /* line 511 | bDrop */
        "movl $1, 8(%esp)\n" /* line 516 */
        "movl $str_00217ff8, 4(%esp)\n" /* "." */
        "movl -0x238(%ebp), %ecx\n" /* name */
        "movl %ecx, (%esp)\n"
        "calll I_strnicmp\n"
        "testl %eax, %eax\n"
        "jne .Lf47e28_000480b6\n"
        ".Lf47e28_00048053:\n"
        "addl $1, -0x240(%ebp)\n" /* line 493 | i */
        "movl -0x240(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x230(%ebp)\n"
        "je .Lf47e28_00048289\n"
        ".Lf47e28_0004806c:\n"
        "movl -0x240(%ebp), %ecx\n" /* line 495 | i */
        "movl -0x22c(%ebp), %eax\n"
        "movl (%eax, %ecx, 4), %ecx\n"
        "movl %ecx, -0x238(%ebp)\n" /* name */
        "cmpl $0, -0x240(%ebp)\n" /* line 498 | i */
        "jne .Lf47e28_00048021\n"
        "movl -0x234(%ebp), %ebx\n" /* line 511 | bDrop, pFiles2 */
        "testl %ebx, %ebx\n" /* pFiles2 */
        "jne .Lf47e28_00048053\n"
        "movl $1, 8(%esp)\n" /* line 516 */
        "movl $str_00217ff8, 4(%esp)\n" /* "." */
        "movl -0x238(%ebp), %ecx\n" /* name */
        "movl %ecx, (%esp)\n"
        "calll I_strnicmp\n"
        "testl %eax, %eax\n"
        "je .Lf47e28_00048053\n"
        ".Lf47e28_000480b6:\n"
        "leal -0x124(%ebp), %eax\n" /* line 523 | path */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002157b8, 8(%esp)\n"
        "movl -0x238(%ebp), %edx\n" /* name */
        "movl %edx, 4(%esp)\n"
        "movl imp_fs_basepath, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_BuildOSPath\n"
        "movl $0, -0x1c(%ebp)\n" /* line 524 | nIwds */
        "movl $0, 0x10(%esp)\n" /* line 525 */
        "leal -0x1c(%ebp), %ecx\n" /* nIwds */
        "movl %ecx, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $str_00216ffc, 4(%esp)\n" /* "iwd" */
        "leal -0x124(%ebp), %eax\n" /* path */
        "movl %eax, (%esp)\n"
        "calll Sys_ListFiles\n"
        "movl %eax, (%esp)\n" /* line 526 */
        "calll Sys_FreeFileList\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 529 | nIwds */
        "testl %ecx, %ecx\n"
        "jle .Lf47e28_000483dd\n"
        ".Lf47e28_0004812b:\n"
        "cld\n" /* line 548 */
        "movl $0xffffffff, %ecx\n"
        "movl -0x238(%ebp), %edi\n" /* name, pFiles0 */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* pFiles0 */
        "notl %ecx\n"
        "movl %ecx, -0x248(%ebp)\n"
        "movl -0x238(%ebp), %eax\n" /* line 551 | name */
        "movl %eax, 4(%esp)\n"
        "leal -0x224(%ebp), %edx\n" /* descPath */
        "movl %edx, (%esp)\n"
        "calll strcpy\n"
        "movl $str_00217ffc, 8(%esp)\n" /* line 552 */
        "movl $0x100, 4(%esp)\n"
        "leal -0x224(%ebp), %ecx\n" /* descPath */
        "movl %ecx, (%esp)\n"
        "calll I_strncat\n"
        "leal -0x20(%ebp), %eax\n" /* line 553 | descHandle */
        "movl %eax, 4(%esp)\n"
        "leal -0x224(%ebp), %eax\n" /* descPath */
        "movl %eax, (%esp)\n"
        "calll FS_SV_FOpenFileRead\n"
        "testl %eax, %eax\n" /* line 554 */
        "jle .Lf47e28_0004819d\n"
        "movl -0x20(%ebp), %eax\n" /* descHandle */
        "testl %eax, %eax\n"
        "jne .Lf47e28_00048377\n"
        ".Lf47e28_0004819d:\n"
        "movl $str_00216f3c, 4(%esp)\n" /* line 568 */
        "movl -0x238(%ebp), %eax\n" /* name */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf47e28_0004835a\n"
        "movl $0x6c6c6143, -0x224(%ebp)\n" /* line 570 | descPath */
        "movl $0x20666f20, -0x220(%ebp)\n"
        "movl $0x79747544, -0x21c(%ebp)\n"
        "movl $0x4d203220, -0x218(%ebp)\n"
        "movl $0x69746c75, -0x214(%ebp)\n"
        "movl $0x79616c70, -0x210(%ebp)\n"
        "movw $0x7265, -0x20c(%ebp)\n"
        "movb $0, -0x20a(%ebp)\n"
        ".Lf47e28_00048207:\n"
        "cld\n" /* line 576 */
        "movl $0xffffffff, %ecx\n"
        "leal -0x224(%ebp), %edi\n" /* descPath, pFiles0 */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* pFiles0 */
        "movl %ecx, %esi\n" /* pFiles1 */
        "notl %esi\n" /* pFiles1 */
        "movl -0x23c(%ebp), %eax\n" /* line 578 | nTotal */
        "addl -0x248(%ebp), %eax\n"
        "leal 2(%esi, %eax), %eax\n" /* pFiles1 */
        "cmpl 0xc(%ebp), %eax\n" /* bufsize */
        "jge .Lf47e28_00048289\n"
        "movl -0x238(%ebp), %eax\n" /* line 580 | name */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* listbuf */
        "movl %edx, (%esp)\n"
        "calll strcpy\n"
        "movl 8(%ebp), %ebx\n" /* line 581 | listbuf, file */
        "addl -0x248(%ebp), %ebx\n" /* file */
        "leal -0x224(%ebp), %ecx\n" /* line 582 | descPath */
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* file */
        "calll strcpy\n"
        "addl %esi, %ebx\n" /* line 583 | pFiles1, file */
        "movl %ebx, 8(%ebp)\n" /* file, listbuf */
        "movl -0x248(%ebp), %eax\n" /* line 584 */
        "addl %esi, %eax\n" /* pFiles1 */
        "addl %eax, -0x23c(%ebp)\n" /* nTotal */
        "addl $1, -0x244(%ebp)\n" /* line 585 | nMods */
        "jmp .Lf47e28_00048053\n"
        ".Lf47e28_0004827f:\n"
        "movl $0, -0x244(%ebp)\n" /* line 493 | nMods */
        ".Lf47e28_00048289:\n"
        "movl -0x22c(%ebp), %ecx\n" /* line 594 */
        "movl %ecx, (%esp)\n"
        "calll Sys_FreeFileList\n"
        /* } scope */
        "movl -0x244(%ebp), %eax\n" /* line 597 | nMods */
        "addl $0x25c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf47e28_000482a8:\n"
        "movl $1, 0x10(%esp)\n" /* line 487 */
        "movl %ebx, 0xc(%esp)\n" /* pFiles2 */
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Sys_ListFiles\n"
        "movl %eax, %ebx\n" /* pFiles2 */
        /* { scope 2 */
        "testl %edi, %edi\n" /* line 399 */
        "jne .Lf47e28_00047ebe\n"
        ".Lf47e28_000482d6:\n"
        "xorl %ecx, %ecx\n" /* line 401 */
        /* } scope */
        /* { scope 2 */
        "testl %esi, %esi\n" /* line 399 */
        "jne .Lf47e28_00047ede\n"
        ".Lf47e28_000482e0:\n"
        "xorl %eax, %eax\n" /* line 401 */
        /* } scope */
        "addl %eax, %ecx\n" /* line 417 */
        /* { scope 2 */
        "testl %ebx, %ebx\n" /* line 399 */
        "jne .Lf47e28_00047f00\n"
        ".Lf47e28_000482ec:\n"
        "xorl %eax, %eax\n" /* line 401 */
        /* } scope */
        "leal (%ecx, %eax), %eax\n" /* line 421 */
        "leal 4(, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, -0x22c(%ebp)\n"
        "testl %edi, %edi\n" /* line 424 */
        "jne .Lf47e28_00047f38\n"
        ".Lf47e28_0004830e:\n"
        "movl -0x22c(%ebp), %edx\n" /* line 426 */
        "jmp .Lf47e28_00047f59\n"
        ".Lf47e28_00048319:\n"
        "xorl %ebx, %ebx\n" /* line 498 | pFiles2 */
        "jmp .Lf47e28_0004832c\n"
        ".Lf47e28_0004831d:\n"
        "addl $1, %ebx\n" /* line 501 | pFiles2 */
        "cmpl %ebx, -0x240(%ebp)\n" /* pFiles2, i */
        "je .Lf47e28_00048027\n"
        ".Lf47e28_0004832c:\n"
        "movl -0x238(%ebp), %eax\n" /* line 503 | name */
        "movl %eax, 4(%esp)\n"
        "movl -0x22c(%ebp), %edx\n"
        "movl (%edx, %ebx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf47e28_0004831d\n"
        "movl $1, -0x234(%ebp)\n" /* bDrop */
        "jmp .Lf47e28_00048053\n"
        ".Lf47e28_0004835a:\n"
        "movl -0x238(%ebp), %edx\n" /* line 574 | name */
        "movl %edx, 4(%esp)\n"
        "leal -0x224(%ebp), %ecx\n" /* descPath */
        "movl %ecx, (%esp)\n"
        "calll strcpy\n"
        "jmp .Lf47e28_00048207\n"
        /* { scope 2 */
        ".Lf47e28_00048377:\n"
        "movl %eax, (%esp)\n" /* line 558 */
        "calll FS_FileForHandle\n"
        "movl %eax, %ebx\n" /* file */
        "movl $0x100, 8(%esp)\n" /* line 559 */
        "movl $0, 4(%esp)\n"
        "leal -0x224(%ebp), %edx\n" /* descPath */
        "movl %edx, (%esp)\n"
        "calll Com_Memset\n"
        "movl %ebx, 0xc(%esp)\n" /* line 560 | file */
        "movl $0x30, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal -0x224(%ebp), %ecx\n" /* descPath */
        "movl %ecx, (%esp)\n"
        "calll FS_FileRead\n"
        "testl %eax, %eax\n" /* line 561 */
        "js .Lf47e28_000483cd\n"
        "movb $0, -0x224(%ebp, %eax)\n" /* line 563 */
        ".Lf47e28_000483cd:\n"
        "movl -0x20(%ebp), %eax\n" /* line 565 | descHandle */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "jmp .Lf47e28_00048207\n"
        /* } scope */
        ".Lf47e28_000483dd:\n"
        "leal -0x124(%ebp), %edx\n" /* line 531 | path */
        "movl %edx, 0xc(%esp)\n"
        "movl $str_002157b8, 8(%esp)\n"
        "movl -0x238(%ebp), %ecx\n" /* name */
        "movl %ecx, 4(%esp)\n"
        "movl imp_fs_cdpath, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_BuildOSPath\n"
        "movl $0, -0x1c(%ebp)\n" /* line 532 | nIwds */
        "movl $0, 0x10(%esp)\n" /* line 533 */
        "leal -0x1c(%ebp), %eax\n" /* nIwds */
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $str_00216ffc, 4(%esp)\n" /* "iwd" */
        "leal -0x124(%ebp), %edx\n" /* path */
        "movl %edx, (%esp)\n"
        "calll Sys_ListFiles\n"
        "movl %eax, (%esp)\n" /* line 534 */
        "calll Sys_FreeFileList\n"
        "movl -0x1c(%ebp), %edx\n" /* line 538 | nIwds */
        "testl %edx, %edx\n"
        "jg .Lf47e28_0004812b\n"
        "leal -0x124(%ebp), %ecx\n" /* line 540 | path */
        "movl %ecx, 0xc(%esp)\n"
        "movl $str_002157b8, 8(%esp)\n"
        "movl -0x238(%ebp), %eax\n" /* name */
        "movl %eax, 4(%esp)\n"
        "movl imp_fs_homepath, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_BuildOSPath\n"
        "movl $0, -0x1c(%ebp)\n" /* line 541 | nIwds */
        "movl $0, 0x10(%esp)\n" /* line 542 */
        "leal -0x1c(%ebp), %edx\n" /* nIwds */
        "movl %edx, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $str_00216ffc, 4(%esp)\n" /* "iwd" */
        "leal -0x124(%ebp), %ecx\n" /* path */
        "movl %ecx, (%esp)\n"
        "calll Sys_ListFiles\n"
        "movl %eax, (%esp)\n" /* line 543 */
        "calll Sys_FreeFileList\n"
        "movl -0x1c(%ebp), %eax\n" /* line 546 | nIwds */
        "testl %eax, %eax\n"
        "jle .Lf47e28_00048053\n"
        "jmp .Lf47e28_0004812b\n"
    );
}

/* line 772 */
__attribute__((naked))
qboolean FS_CompareIwds(char *needediwds, int len, qboolean dlstring)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 772 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x13c, %esp\n"
        /* { scope 1: testpath */
        "movl imp_fs_numServerReferencedIwds, %eax\n" /* line 778 */
        "movl (%eax), %esi\n"
        "testl %esi, %esi\n"
        "je .Lf484cc_000484f7\n"
        "movl 8(%ebp), %edx\n" /* line 781 | needediwds */
        "movb $0, (%edx)\n"
        "movl (%eax), %ebx\n" /* line 783 */
        "testl %ebx, %ebx\n"
        "jg .Lf484cc_00048524\n"
        "movl 8(%ebp), %eax\n" /* line 845 | needediwds */
        "cmpb $0, (%eax)\n"
        "jne .Lf484cc_00048504\n"
        ".Lf484cc_000484f7:\n"
        "xorl %eax, %eax\n" /* line 848 */
        /* } scope */
        "addl $0x13c, %esp\n" /* line 852 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: testpath */
        ".Lf484cc_00048504:\n"
        "movl %eax, 4(%esp)\n" /* line 847 */
        "movl $str_00218054, (%esp)\n" /* "Need iwds: %s
" */
        "calll Com_Printf\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x13c, %esp\n" /* line 852 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: testpath */
        ".Lf484cc_00048524:\n"
        "movl $0, -0x11c(%ebp)\n" /* line 783 | i */
        "movl imp_fs_serverReferencedIwdNames, %ebx\n"
        "movl imp_fs_serverReferencedIwds, %esi\n"
        ".Lf484cc_0004853a:\n"
        "movl $str_00216f3c, 4(%esp)\n" /* line 790 */
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_iwIwd\n"
        "testl %eax, %eax\n"
        "jne .Lf484cc_00048672\n"
        "movl imp_fs_searchpaths, %eax\n" /* line 793 */
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf484cc_0004857a\n"
        ".Lf484cc_0004855f:\n"
        "movl 4(%edx), %eax\n" /* line 795 */
        "testl %eax, %eax\n"
        "je .Lf484cc_00048574\n"
        "movl 0x304(%eax), %eax\n"
        "cmpl (%esi), %eax\n"
        "je .Lf484cc_00048672\n"
        ".Lf484cc_00048574:\n"
        "movl (%edx), %edx\n" /* line 793 */
        "testl %edx, %edx\n"
        "jne .Lf484cc_0004855f\n"
        ".Lf484cc_0004857a:\n"
        "movl (%ebx), %eax\n" /* line 802 */
        "testl %eax, %eax\n"
        "je .Lf484cc_00048672\n"
        "cmpb $0, (%eax)\n"
        "je .Lf484cc_00048672\n"
        "movl 0x10(%ebp), %ecx\n" /* line 806 | dlstring */
        "testl %ecx, %ecx\n"
        "jne .Lf484cc_000486a3\n"
        "movl %eax, 8(%esp)\n" /* line 833 */
        "movl 0xc(%ebp), %eax\n" /* len */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* needediwds */
        "movl %edx, (%esp)\n"
        "calll I_strncat\n"
        "movl $str_00217198, 8(%esp)\n" /* line 834 */
        "movl 0xc(%ebp), %eax\n" /* len */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* needediwds */
        "movl %edx, (%esp)\n"
        "calll I_strncat\n"
        "movl (%ebx), %eax\n" /* line 836 */
        "movl %eax, 4(%esp)\n"
        "movl $str_00218014, (%esp)\n" /* "%s.iwd" */
        "calll va\n"
        /* { scope 2 */
        "leal -0x118(%ebp), %edx\n" /* line 75 | testpath */
        "movl %edx, 0xc(%esp)\n"
        "movl $str_002157b8, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl imp_fs_homepath, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_BuildOSPath\n"
        "cld\n" /* line 76 */
        "movl $0xffffffff, %ecx\n"
        "leal -0x118(%ebp), %edi\n" /* testpath */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movb $0, -0x11a(%ecx, %ebp)\n"
        "movl $str_00215b98, 4(%esp)\n" /* line 78 */
        "leal -0x118(%ebp), %edx\n" /* testpath */
        "movl %edx, (%esp)\n"
        "calll FS_FileOpen\n"
        "testl %eax, %eax\n" /* line 79 */
        "je .Lf484cc_00048658\n"
        "movl %eax, (%esp)\n" /* line 81 */
        "calll FS_FileClose\n"
        /* } scope */
        "movl $str_00218028, 8(%esp)\n" /* line 838 */
        "movl 0xc(%ebp), %eax\n" /* len */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* needediwds */
        "movl %edx, (%esp)\n"
        "calll I_strncat\n"
        ".Lf484cc_00048658:\n"
        "movl $str_002160e8, 8(%esp)\n" /* line 840 */
        "movl 0xc(%ebp), %eax\n" /* len */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* needediwds */
        "movl %edx, (%esp)\n"
        "calll I_strncat\n"
        ".Lf484cc_00048672:\n"
        "addl $1, -0x11c(%ebp)\n" /* line 783 | i */
        "addl $4, %ebx\n"
        "addl $4, %esi\n"
        "movl imp_fs_numServerReferencedIwds, %eax\n"
        "movl -0x11c(%ebp), %edx\n" /* i */
        "cmpl (%eax), %edx\n"
        "jl .Lf484cc_0004853a\n"
        ".Lf484cc_00048692:\n"
        "movl 8(%ebp), %eax\n" /* line 845 | needediwds */
        "cmpb $0, (%eax)\n"
        "je .Lf484cc_000484f7\n"
        "jmp .Lf484cc_00048504\n"
        ".Lf484cc_000486a3:\n"
        "movl $str_00218010, 8(%esp)\n" /* line 809 */
        "movl 0xc(%ebp), %eax\n" /* len */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* needediwds */
        "movl %edx, (%esp)\n"
        "calll I_strncat\n"
        "movl (%ebx), %eax\n" /* line 810 */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* len */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* needediwds */
        "movl %edx, (%esp)\n"
        "calll I_strncat\n"
        "movl $str_00217198, 8(%esp)\n" /* line 811 */
        "movl 0xc(%ebp), %eax\n" /* len */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* needediwds */
        "movl %edx, (%esp)\n"
        "calll I_strncat\n"
        "movl $str_00218010, 8(%esp)\n" /* line 814 */
        "movl 0xc(%ebp), %eax\n" /* len */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* needediwds */
        "movl %edx, (%esp)\n"
        "calll I_strncat\n"
        "movl (%ebx), %eax\n" /* line 816 */
        "movl %eax, 4(%esp)\n"
        "movl $str_00218014, (%esp)\n" /* "%s.iwd" */
        "calll va\n"
        /* { scope 2 */
        "leal -0x118(%ebp), %edx\n" /* line 75 | testpath */
        "movl %edx, 0xc(%esp)\n"
        "movl $str_002157b8, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl imp_fs_homepath, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_BuildOSPath\n"
        "cld\n" /* line 76 */
        "movl $0xffffffff, %ecx\n"
        "leal -0x118(%ebp), %edi\n" /* testpath */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movb $0, -0x11a(%ecx, %ebp)\n"
        "movl $str_00215b98, 4(%esp)\n" /* line 78 */
        "leal -0x118(%ebp), %edx\n" /* testpath */
        "movl %edx, (%esp)\n"
        "calll FS_FileOpen\n"
        "testl %eax, %eax\n" /* line 79 */
        "je .Lf484cc_000487ea\n"
        "movl %eax, (%esp)\n" /* line 81 */
        "calll FS_FileClose\n"
        /* } scope */
        /* { scope 2 */
        "movl (%esi), %eax\n" /* line 822 */
        "movl %eax, 0x10(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_0021801c, 8(%esp)\n" /* "%s.%08x.iwd" */
        "movl $0x100, 4(%esp)\n"
        "leal -0x118(%ebp), %eax\n" /* testpath */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "leal -0x118(%ebp), %edx\n" /* line 823 | testpath */
        "movl %edx, 8(%esp)\n"
        /* } scope */
        ".Lf484cc_000487b3:\n"
        "movl 0xc(%ebp), %eax\n" /* line 840 | len */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* needediwds */
        "movl %edx, (%esp)\n"
        "calll I_strncat\n"
        "addl $1, -0x11c(%ebp)\n" /* line 783 | i */
        "addl $4, %ebx\n"
        "addl $4, %esi\n"
        "movl imp_fs_numServerReferencedIwds, %eax\n"
        "movl -0x11c(%ebp), %edx\n" /* i */
        "cmpl (%eax), %edx\n"
        "jl .Lf484cc_0004853a\n"
        "jmp .Lf484cc_00048692\n"
        ".Lf484cc_000487ea:\n"
        "movl (%ebx), %eax\n" /* line 827 */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* len */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* needediwds */
        "movl %edx, (%esp)\n"
        "calll I_strncat\n"
        "movl $str_00217198, 8(%esp)\n" /* line 828 */
        "jmp .Lf484cc_000487b3\n"
    );
}

