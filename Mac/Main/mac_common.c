/* ASM dump from: mac_common.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Main/mac_common.cpp */

#include "common_types.h"
#include "imports.h"

static char cwd[256]; /* 0x7f1b80 */

void Sys_Mkdir(const char *path);
qboolean Sys_RemoveDirTree(const char *path);
char * Sys_DefaultCDPath(void);
char * Sys_DefaultHomePath(void);
char * Sys_DefaultInstallPath(void);
void Sys_ListFilteredFiles(const char *basedir, const char *subdirs, const char *filter, char * *list, int *numfiles);
char * * Sys_ListFiles(const char *directory, const char *extension, const char *filter, int *numfiles, qboolean wantsubs);
void Sys_FreeFileList(char * *list);
qboolean Sys_DirectoryHasContents(const char *directory);
void Sys_InitStreamThread(void);
void Sys_BeginStreamedFile(fileHandle_t f, int readAhead);
void Sys_EndStreamedFile(fileHandle_t f);
int Sys_StreamedRead(void *buffer, int size, int count, fileHandle_t f);
void Sys_StreamSeek(fileHandle_t f, int offset, int origin);

/* line 28 */
__attribute__((naked))
void Sys_Mkdir(const char *path)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 28 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* path */
        /* { scope 1 */
        "movl $7, 4(%esp)\n" /* line 31 */
        "movl %ebx, (%esp)\n" /* path */
        "calll access\n"
        "testl %eax, %eax\n" /* line 32 */
        "je .Lfc4eb8_000c4ee6\n"
        "movl $0x1ff, 4(%esp)\n" /* line 34 */
        "movl %ebx, (%esp)\n" /* path */
        "calll mkdir\n"
        /* } scope */
        ".Lfc4eb8_000c4ee6:\n"
        "addl $0x14, %esp\n" /* line 37 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 41 */
__attribute__((naked))
qboolean Sys_RemoveDirTree(const char *path)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 41 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 43 | path, error */
        "movl %eax, (%esp)\n" /* error */
        "calll MacFiles_RemoveDirectoryA\n"
        "testl %eax, %eax\n" /* error */
        "sete %al\n" /* error */
        "movzbl %al, %eax\n" /* error */
        /* } scope */
        "leave\n" /* line 45 */
        "retl\n"
    );
}

/* line 49 */
__attribute__((naked))
char * Sys_DefaultCDPath(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 49 */
        "movl %esp, %ebp\n"
        "movl $0x2157b8, %eax\n" /* line 52 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 56 */
__attribute__((naked))
char * Sys_DefaultHomePath(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 56 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n" /* line 59 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 63 */
__attribute__((naked))
char * Sys_DefaultInstallPath(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 63 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl $0xff, 4(%esp)\n" /* line 67 */
        "movl $cwd, (%esp)\n"
        "calll getcwd\n"
        "movb $0, 0x7f1c7f\n" /* line 68 */
        /* } scope */
        "movl $cwd, %eax\n" /* line 71 */
        "leave\n"
        "retl\n"
    );
}

/* line 77 */
__attribute__((naked))
void Sys_ListFilteredFiles(const char *basedir, const char *subdirs, const char *filter, char * *list, int *numfiles)
{
    __asm__ __volatile__ (
        ".Lfc4f42_000c4f42:\n"
        "pushl %ebp\n" /* line 77 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x38c, %esp\n"
        /* { scope 1 */
        "movl 0x18(%ebp), %eax\n" /* line 85 | numfiles */
        "cmpl $0xffe, (%eax)\n"
        "jg .Lfc4f42_000c5087\n"
        "movl 0xc(%ebp), %eax\n" /* line 89 | subdirs */
        "cmpb $0, (%eax)\n"
        "je .Lfc4f42_000c5092\n"
        "movl %eax, 0x10(%esp)\n" /* line 90 */
        "movl 8(%ebp), %eax\n" /* basedir */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x216e18, 8(%esp)\n" /* "%s/%s" */
        "movl $0x100, 4(%esp)\n"
        "leal -0x178(%ebp), %eax\n" /* search */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        ".Lfc4f42_000c4f92:\n"
        "leal -0x178(%ebp), %eax\n" /* line 96 | search */
        "movl %eax, (%esp)\n"
        "calll opendir\n"
        "movl %eax, %edi\n" /* fdir */
        "testl %eax, %eax\n"
        "je .Lfc4f42_000c5087\n"
        "leal -0x378(%ebp), %esi\n" /* filename */
        ".Lfc4f42_000c4fb0:\n"
        "movl %edi, (%esp)\n" /* line 100 | fdir */
        "calll readdir\n"
        "testl %eax, %eax\n"
        "je .Lfc4f42_000c507f\n"
        ".Lfc4f42_000c4fc0:\n"
        "leal 8(%eax), %ebx\n" /* line 101 */
        "movl %ebx, 0x10(%esp)\n"
        "leal -0x178(%ebp), %eax\n" /* search */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x216e18, 8(%esp)\n" /* "%s/%s" */
        "movl $0x100, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Com_sprintf\n"
        "leal -0x78(%ebp), %eax\n" /* line 102 | st */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll stat\n"
        "addl $1, %eax\n"
        "je .Lfc4f42_000c4fb0\n"
        "testb $0x40, -0x6f(%ebp)\n" /* line 105 */
        "jne .Lfc4f42_000c50bc\n"
        ".Lfc4f42_000c5007:\n"
        "movl 0x18(%ebp), %eax\n" /* line 116 | numfiles */
        "cmpl $0xffe, (%eax)\n"
        "jg .Lfc4f42_000c507f\n"
        "movl %ebx, 0x10(%esp)\n" /* line 119 */
        "movl 0xc(%ebp), %eax\n" /* subdirs */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x216e18, 8(%esp)\n" /* "%s/%s" */
        "movl $0x100, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Com_sprintf\n"
        "movl $0, 8(%esp)\n" /* line 120 */
        "movl %esi, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* filter */
        "movl %eax, (%esp)\n"
        "calll Com_FilterPath\n"
        "testb %al, %al\n"
        "je .Lfc4f42_000c4fb0\n"
        "movl 0x18(%ebp), %eax\n" /* line 122 | numfiles */
        "movl (%eax), %ebx\n"
        "movl 0x14(%ebp), %eax\n" /* list */
        "leal (%eax, %ebx, 4), %ebx\n"
        "movl %esi, (%esp)\n"
        "calll CopyStringInternal\n"
        "movl %eax, (%ebx)\n"
        "movl 0x18(%ebp), %eax\n" /* line 123 | numfiles */
        "addl $1, (%eax)\n"
        "movl %edi, (%esp)\n" /* line 100 | fdir */
        "calll readdir\n"
        "testl %eax, %eax\n"
        "jne .Lfc4f42_000c4fc0\n"
        ".Lfc4f42_000c507f:\n"
        "movl %edi, (%esp)\n" /* line 126 | fdir */
        "calll closedir\n"
        /* } scope */
        ".Lfc4f42_000c5087:\n"
        "addl $0x38c, %esp\n" /* line 127 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc4f42_000c5092:\n"
        "movl 8(%ebp), %eax\n" /* line 93 | basedir */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x216058, 8(%esp)\n" /* "%s" */
        "movl $0x100, 4(%esp)\n"
        "leal -0x178(%ebp), %eax\n" /* search */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "jmp .Lfc4f42_000c4f92\n"
        ".Lfc4f42_000c50bc:\n"
        "movl $0x217ff8, 4(%esp)\n" /* line 106 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfc4f42_000c5007\n"
        "movl $0x216ca0, 4(%esp)\n" /* ".." */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lfc4f42_000c5007\n"
        "movl 0xc(%ebp), %eax\n" /* line 107 | subdirs */
        "cmpb $0, (%eax)\n"
        "je .Lfc4f42_000c5149\n"
        "movl %ebx, 0x10(%esp)\n" /* line 108 */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x216e18, 8(%esp)\n" /* "%s/%s" */
        "movl $0x100, 4(%esp)\n"
        "leal -0x278(%ebp), %eax\n" /* newsubdirs */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        ".Lfc4f42_000c511a:\n"
        "movl 0x18(%ebp), %eax\n" /* line 113 | numfiles */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* list */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* filter */
        "movl %eax, 8(%esp)\n"
        "leal -0x278(%ebp), %eax\n" /* newsubdirs */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* basedir */
        "movl %eax, (%esp)\n"
        "calll Sys_ListFilteredFiles\n"
        "jmp .Lfc4f42_000c5007\n"
        ".Lfc4f42_000c5149:\n"
        "movl %ebx, 0xc(%esp)\n" /* line 111 */
        "movl $0x216058, 8(%esp)\n" /* "%s" */
        "movl $0x100, 4(%esp)\n"
        "leal -0x278(%ebp), %eax\n" /* newsubdirs */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "jmp .Lfc4f42_000c511a\n"
    );
}

/* line 131 */
__attribute__((naked))
char * * Sys_ListFiles(const char *directory, const char *extension, const char *filter, int *numfiles, qboolean wantsubs)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 131 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x41ac, %esp\n"
        "movl 0x10(%ebp), %edx\n" /* filter */
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 147 */
        "jne .Lfc516e_000c5373\n"
        "movl 0xc(%ebp), %ecx\n" /* line 167 | extension */
        "testl %ecx, %ecx\n"
        "movl $0x2157b8, %eax\n"
        "cmovnel 0xc(%ebp), %eax\n" /* extension */
        "movl %eax, 0xc(%ebp)\n" /* extension */
        "cmpb $0x2f, (%eax)\n" /* line 170 */
        "je .Lfc516e_000c5353\n"
        ".Lfc516e_000c519f:\n"
        "movl 0x18(%ebp), %eax\n" /* wantsubs */
        "movl %eax, -0x418c(%ebp)\n" /* dironly */
        ".Lfc516e_000c51a8:\n"
        "movl $0, -0x1c(%ebp)\n" /* line 178 | nfiles */
        "movl 8(%ebp), %edx\n" /* line 180 | directory */
        "movl %edx, (%esp)\n"
        "calll opendir\n"
        "movl %eax, -0x4190(%ebp)\n" /* fdir */
        "testl %eax, %eax\n"
        "je .Lfc516e_000c533b\n"
        "movl %eax, %edx\n"
        "jmp .Lfc516e_000c51d8\n"
        ".Lfc516e_000c51cc:\n"
        "testb $0x40, -0x73(%ebp)\n" /* line 191 */
        "jne .Lfc516e_000c523e\n"
        ".Lfc516e_000c51d2:\n"
        "movl -0x4190(%ebp), %edx\n" /* fdir */
        ".Lfc516e_000c51d8:\n"
        "movl %edx, (%esp)\n" /* line 185 */
        "calll readdir\n"
        "testl %eax, %eax\n"
        "je .Lfc516e_000c527e\n"
        ".Lfc516e_000c51e8:\n"
        "cmpb $0x2e, 8(%eax)\n" /* line 186 */
        "je .Lfc516e_000c51d2\n"
        "leal 8(%eax), %esi\n" /* line 188 */
        "movl %esi, 0x10(%esp)\n"
        "movl 8(%ebp), %edx\n" /* directory */
        "movl %edx, 0xc(%esp)\n"
        "movl $0x216e18, 8(%esp)\n" /* "%s/%s" */
        "movl $0x100, 4(%esp)\n"
        "leal -0x17c(%ebp), %ebx\n" /* search */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "leal -0x7c(%ebp), %eax\n" /* line 189 | st */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll stat\n"
        "addl $1, %eax\n"
        "je .Lfc516e_000c51d2\n"
        "movl -0x418c(%ebp), %edx\n" /* line 191 | dironly */
        "testl %edx, %edx\n"
        "jne .Lfc516e_000c51cc\n"
        "testb $0x40, -0x73(%ebp)\n"
        "jne .Lfc516e_000c51d2\n"
        ".Lfc516e_000c523e:\n"
        "movl 0xc(%ebp), %eax\n" /* line 195 | extension */
        "cmpb $0, (%eax)\n"
        "jne .Lfc516e_000c52f3\n"
        ".Lfc516e_000c524a:\n"
        "movl -0x1c(%ebp), %ebx\n" /* line 204 | nfiles */
        "cmpl $0xfff, %ebx\n"
        "je .Lfc516e_000c5281\n"
        "movl %esi, (%esp)\n" /* line 206 */
        "calll CopyStringInternal\n"
        "movl %eax, -0x417c(%ebp, %ebx, 4)\n"
        "addl $1, -0x1c(%ebp)\n" /* line 207 | nfiles */
        "movl -0x4190(%ebp), %edx\n" /* fdir */
        "movl %edx, (%esp)\n" /* line 185 */
        "calll readdir\n"
        "testl %eax, %eax\n"
        "jne .Lfc516e_000c51e8\n"
        ".Lfc516e_000c527e:\n"
        "movl -0x1c(%ebp), %ebx\n" /* nfiles */
        ".Lfc516e_000c5281:\n"
        "movl $0, -0x417c(%ebp, %ebx, 4)\n" /* line 211 */
        "movl -0x4190(%ebp), %eax\n" /* line 213 | fdir */
        "movl %eax, (%esp)\n"
        "calll closedir\n"
        "movl -0x1c(%ebp), %eax\n" /* line 216 | nfiles */
        "movl 0x14(%ebp), %edx\n" /* numfiles */
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 218 */
        "jne .Lfc516e_000c52b5\n"
        ".Lfc516e_000c52a6:\n"
        "xorl %ecx, %ecx\n" /* line 228 */
        /* } scope */
        "movl %ecx, %eax\n" /* line 229 */
        "addl $0x41ac, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc516e_000c52b5:\n"
        "leal 4(, %eax, 4), %eax\n" /* line 222 */
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, %ecx\n"
        "movl -0x1c(%ebp), %eax\n" /* line 223 | nfiles */
        "testl %eax, %eax\n"
        "jle .Lfc516e_000c53d5\n"
        "movl $1, %edx\n"
        "leal -0x417c(%ebp), %ebx\n" /* list */
        ".Lfc516e_000c52dc:\n"
        "movl -4(%ebx, %edx, 4), %eax\n" /* line 224 */
        "movl %eax, -4(%ecx, %edx, 4)\n"
        "movl %edx, %eax\n"
        "addl $1, %edx\n"
        "cmpl -0x1c(%ebp), %eax\n" /* line 223 | nfiles */
        "jl .Lfc516e_000c52dc\n"
        "jmp .Lfc516e_000c53d7\n"
        ".Lfc516e_000c52f3:\n"
        "movl $0xffffffff, %edx\n" /* line 196 */
        "xorl %eax, %eax\n"
        "cld\n"
        "movl %edx, %ecx\n"
        "movl %esi, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %ebx\n"
        "movl %edx, %ecx\n"
        "movl 0xc(%ebp), %edi\n" /* extension */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %edx\n"
        "cmpl %edx, %ebx\n"
        "jb .Lfc516e_000c51d2\n"
        "movl 0xc(%ebp), %eax\n" /* extension */
        "movl %eax, 4(%esp)\n"
        "leal (%esi, %ebx), %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfc516e_000c51d2\n"
        "jmp .Lfc516e_000c524a\n"
        ".Lfc516e_000c533b:\n"
        "movl 0x14(%ebp), %eax\n" /* line 181 | numfiles */
        "movl $0, (%eax)\n"
        "xorl %ecx, %ecx\n"
        /* } scope */
        "movl %ecx, %eax\n" /* line 229 */
        "addl $0x41ac, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc516e_000c5353:\n"
        "cmpb $0, 1(%eax)\n" /* line 170 */
        "jne .Lfc516e_000c519f\n"
        "movl $1, -0x418c(%ebp)\n" /* dironly */
        "movl $0x2157b8, 0xc(%ebp)\n" /* extension */
        "jmp .Lfc516e_000c51a8\n"
        ".Lfc516e_000c5373:\n"
        "movl $0, -0x1c(%ebp)\n" /* line 149 | nfiles */
        "leal -0x1c(%ebp), %eax\n" /* line 150 | nfiles */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x417c(%ebp), %ebx\n" /* list */
        "movl %ebx, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl $0x2157b8, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* directory */
        "movl %eax, (%esp)\n"
        "calll Sys_ListFilteredFiles\n"
        "movl -0x1c(%ebp), %eax\n" /* line 152 | nfiles */
        "movl $0, -0x417c(%ebp, %eax, 4)\n"
        "movl 0x14(%ebp), %edx\n" /* line 153 | numfiles */
        "movl %eax, (%edx)\n"
        "testl %eax, %eax\n" /* line 155 */
        "je .Lfc516e_000c52a6\n"
        "leal 4(, %eax, 4), %eax\n" /* line 158 */
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, %ecx\n"
        "movl -0x1c(%ebp), %esi\n" /* line 159 | nfiles */
        "testl %esi, %esi\n"
        "jg .Lfc516e_000c53eb\n"
        ".Lfc516e_000c53d5:\n"
        "xorl %eax, %eax\n" /* line 223 */
        ".Lfc516e_000c53d7:\n"
        "movl $0, (%ecx, %eax, 4)\n" /* line 226 */
        /* } scope */
        "movl %ecx, %eax\n" /* line 229 */
        "addl $0x41ac, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc516e_000c53eb:\n"
        "movl $1, %edx\n" /* line 159 */
        ".Lfc516e_000c53f0:\n"
        "movl -4(%ebx, %edx, 4), %eax\n" /* line 160 */
        "movl %eax, -4(%ecx, %edx, 4)\n"
        "movl %edx, %eax\n"
        "addl $1, %edx\n"
        "cmpl %eax, -0x1c(%ebp)\n" /* line 159 | nfiles */
        "jg .Lfc516e_000c53f0\n"
        "jmp .Lfc516e_000c53d7\n"
    );
}

/* line 233 */
__attribute__((naked))
void Sys_FreeFileList(char * *list)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 233 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* list */
        "testl %esi, %esi\n" /* line 237 | list */
        "je .Lfc5404_000c543b\n"
        "movl (%esi), %eax\n" /* line 241 | list */
        "testl %eax, %eax\n"
        "je .Lfc5404_000c542d\n"
        "movl %esi, %ebx\n" /* list */
        ".Lfc5404_000c541b:\n"
        "movl %eax, (%esp)\n" /* line 242 */
        "calll Z_FreeInternal\n"
        "movl 4(%ebx), %eax\n" /* line 241 */
        "addl $4, %ebx\n"
        "testl %eax, %eax\n"
        "jne .Lfc5404_000c541b\n"
        ".Lfc5404_000c542d:\n"
        "movl %esi, 8(%ebp)\n" /* line 245 | list */
        "addl $0x10, %esp\n" /* line 246 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp Z_FreeInternal\n" /* line 245 */
        ".Lfc5404_000c543b:\n"
        "addl $0x10, %esp\n" /* line 246 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 251 */
__attribute__((naked))
qboolean Sys_DirectoryHasContents(const char *directory)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 251 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 255 | directory */
        "movl %eax, (%esp)\n"
        "calll opendir\n"
        "movl %eax, %ebx\n" /* dir */
        "testl %eax, %eax\n" /* line 256 */
        "je .Lfc5442_000c5493\n"
        /* { scope 2 */
        ".Lfc5442_000c545b:\n"
        "movl %ebx, (%esp)\n" /* line 258 | dir */
        "calll readdir\n"
        "testl %eax, %eax\n" /* line 259 */
        "je .Lfc5442_000c5480\n"
        "cmpb $0x2e, 8(%eax)\n" /* line 261 */
        "je .Lfc5442_000c545b\n"
        "movzbl 6(%eax), %eax\n"
        "cmpb $4, %al\n"
        "je .Lfc5442_000c545b\n"
        "cmpb $8, %al\n"
        "jne .Lfc5442_000c545b\n"
        "movl $1, %esi\n" /* line 259 | hasContents */
        "jmp .Lfc5442_000c5482\n"
        ".Lfc5442_000c5480:\n"
        "xorl %esi, %esi\n" /* hasContents */
        ".Lfc5442_000c5482:\n"
        "movl %ebx, (%esp)\n" /* line 273 | dir */
        "calll closedir\n"
        /* } scope */
        /* } scope */
        "movl %esi, %eax\n" /* line 277 | hasContents */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc5442_000c5493:\n"
        "xorl %esi, %esi\n" /* line 256 | hasContents */
        /* } scope */
        "movl %esi, %eax\n" /* line 277 | hasContents */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 281 */
__attribute__((naked))
void Sys_InitStreamThread(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 281 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 284 */
        "retl\n"
    );
}

/* line 288 */
__attribute__((naked))
void Sys_BeginStreamedFile(fileHandle_t f, int readAhead)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 288 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 291 */
        "retl\n"
    );
}

/* line 295 */
__attribute__((naked))
void Sys_EndStreamedFile(fileHandle_t f)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 295 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 298 */
        "retl\n"
    );
}

/* line 302 */
__attribute__((naked))
int Sys_StreamedRead(void *buffer, int size, int count, fileHandle_t f)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 302 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %edx\n" /* size */
        "movl 0x10(%ebp), %ecx\n" /* count */
        "movl 0x14(%ebp), %eax\n" /* line 304 | f */
        "movl %eax, 0x10(%ebp)\n" /* count */
        "imull %ecx, %edx\n"
        "movl %edx, 0xc(%ebp)\n" /* size */
        "popl %ebp\n" /* line 305 */
        "jmp FS_Read\n" /* line 304 */
    );
}

/* line 309 */
__attribute__((naked))
void Sys_StreamSeek(fileHandle_t f, int offset, int origin)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 309 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x10(%ebp), %eax\n" /* line 311 | origin */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* offset */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* f */
        "movl %eax, (%esp)\n"
        "calll FS_Seek\n"
        "leave\n" /* line 312 */
        "retl\n"
    );
}

