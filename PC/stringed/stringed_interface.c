/* ASM dump from: stringed_interface.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/stringed/stringed_interface.cpp */

#include "common_types.h"
#include "imports.h"

extern int giFilesFound; /* 0x0 */

unsigned char * SE_LoadFileData(const char *psFileName);
my_upsampler SE_FreeFileDataAfterLoad(unsigned char *psLoadedFile);
static my_upsampler SE_R_ListFiles(const char *psExtension, const char *psDir);
int SE_BuildFileList(const char *psStartDir, LocalizeString *strResults);

/* line 31 */
__attribute__((naked))
unsigned char * SE_LoadFileData(const char *psFileName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 31 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        /* { scope 1 */
        "leal -0xc(%ebp), %eax\n" /* line 36 | pvLoadedData */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* psFileName */
        "movl %eax, (%esp)\n"
        "calll FS_ReadFile\n"
        "testl %eax, %eax\n" /* line 37 */
        "jle .Lfbcf6c_000bcf8d\n"
        "movl -0xc(%ebp), %eax\n" /* pvLoadedData */
        /* } scope */
        "leave\n" /* line 38 */
        "retl\n"
        /* { scope 1 */
        ".Lfbcf6c_000bcf8d:\n"
        "xorl %eax, %eax\n" /* line 37 */
        /* } scope */
        "leave\n" /* line 38 */
        "retl\n"
    );
}

/* line 43 */
__attribute__((naked))
my_upsampler SE_FreeFileDataAfterLoad(unsigned char *psLoadedFile)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 43 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 47 */
        "jmp FS_FreeFile\n" /* line 46 */
    );
}

/* line 53 */
static __attribute__((naked))
my_upsampler SE_R_ListFiles(const char *psExtension, const char *psDir)
{
    __asm__ __volatile__ (
        ".Lfbcf9c_000bcf9c:\n"
        "pushl %ebp\n" /* line 53 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl %eax, -0x78(%ebp)\n"
        "movl %edx, -0x7c(%ebp)\n"
        "movl %ecx, %esi\n" /* strResults */
        /* { scope 1: sDirName */
        "movl $0xa, 0x10(%esp)\n" /* line 58 */
        "leal -0x20(%ebp), %eax\n" /* numdirs */
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x216f38, 4(%esp)\n" /* "/" */
        "movl %edx, (%esp)\n"
        "calll FS_ListFiles\n"
        "movl %eax, -0x70(%ebp)\n" /* dirFiles */
        "movl -0x20(%ebp), %ecx\n" /* line 59 | numdirs */
        "testl %ecx, %ecx\n"
        "jle .Lfbcf9c_000bd026\n"
        "xorl %edi, %edi\n" /* i */
        ".Lfbcf9c_000bcfe3:\n"
        "movl -0x70(%ebp), %eax\n" /* line 61 | dirFiles */
        "movl (%eax, %edi, 4), %edx\n"
        "movzbl (%edx), %eax\n"
        "testb %al, %al\n"
        "je .Lfbcf9c_000bd01e\n"
        "cmpb $0x2e, %al\n"
        "je .Lfbcf9c_000bd01e\n"
        /* { scope 2 */
        "movl %edx, 0xc(%esp)\n" /* line 65 */
        "movl -0x7c(%ebp), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $0x216e18, 4(%esp)\n" /* "%s/%s" */
        "leal -0x60(%ebp), %ebx\n" /* sDirName */
        "movl %ebx, (%esp)\n"
        "calll sprintf\n"
        "movl %esi, %ecx\n" /* line 66 | strResults */
        "movl %ebx, %edx\n"
        "movl -0x78(%ebp), %eax\n"
        "calll SE_R_ListFiles\n"
        /* } scope */
        ".Lfbcf9c_000bd01e:\n"
        "addl $1, %edi\n" /* line 59 | i */
        "cmpl -0x20(%ebp), %edi\n" /* numdirs, i */
        "jl .Lfbcf9c_000bcfe3\n"
        ".Lfbcf9c_000bd026:\n"
        "movl $0xa, 0x10(%esp)\n" /* line 70 */
        "leal -0x1c(%ebp), %eax\n" /* numSysFiles */
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl -0x78(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl -0x7c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_ListFiles\n"
        "movl %eax, -0x74(%ebp)\n" /* sysFiles */
        "movl -0x1c(%ebp), %edx\n" /* line 71 | numSysFiles */
        "testl %edx, %edx\n"
        "jg .Lfbcf9c_000bd089\n"
        "movl %eax, %ecx\n"
        ".Lfbcf9c_000bd05b:\n"
        "movl $0xa, 4(%esp)\n" /* line 81 */
        "movl %ecx, (%esp)\n"
        "calll FS_FreeFileList\n"
        "movl $0xa, 4(%esp)\n" /* line 82 */
        "movl -0x70(%ebp), %eax\n" /* dirFiles */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFileList\n"
        /* } scope */
        "addl $0x9c, %esp\n" /* line 83 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: sDirName */
        ".Lfbcf9c_000bd089:\n"
        "movl $0, -0x6c(%ebp)\n" /* line 71 */
        "leal -0x60(%ebp), %ebx\n" /* sDirName */
        "movl -0x6c(%ebp), %edx\n"
        /* { scope 2 */
        ".Lfbcf9c_000bd096:\n"
        "movl -0x74(%ebp), %ecx\n" /* line 75 | sysFiles */
        "movl (%ecx, %edx, 4), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x7c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x216e18, 4(%esp)\n" /* "%s/%s" */
        "movl %ebx, (%esp)\n"
        "calll sprintf\n"
        "cld\n" /* line 257 */
        "movl $0xffffffff, %ecx\n"
        "movl %ebx, %edi\n" /* i */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* i */
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* strResults */
        "calll __ZNSs6appendEPKcm\n"
        "movl (%esi), %edx\n" /* line 847 | strResults */
        "movl -0xc(%edx), %edi\n" /* i */
        "addl $1, %edi\n" /* i */
        "cmpl -8(%edx), %edi\n" /* line 848 | i */
        "ja .Lfbcf9c_000bd0ec\n"
        "movl -4(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lfbcf9c_000bd0fa\n"
        ".Lfbcf9c_000bd0ec:\n"
        "movl %edi, 4(%esp)\n" /* line 849 | i */
        "movl %esi, (%esp)\n" /* strResults */
        "calll __ZNSs7reserveEm\n"
        "movl (%esi), %edx\n" /* strResults */
        ".Lfbcf9c_000bd0fa:\n"
        "movl -0xc(%edx), %eax\n" /* line 241 */
        "movb $0x3b, (%edx, %eax)\n"
        "movl (%esi), %edx\n" /* line 277 | strResults */
        /* { scope 3 */
        "movl $0, -4(%edx)\n" /* line 194 */
        "movl %edi, -0xc(%edx)\n" /* line 200 | i */
        "movl __ZNSs4_Rep11_S_terminalE, %eax\n" /* line 201 */
        "movzbl (%eax), %eax\n"
        "movb %al, (%edx, %edi)\n"
        /* } scope */
        "addl $1, giFilesFound\n" /* line 79 */
        /* } scope */
        "addl $1, -0x6c(%ebp)\n" /* line 71 */
        "movl -0x6c(%ebp), %edx\n"
        "cmpl %edx, -0x1c(%ebp)\n" /* numSysFiles */
        "jg .Lfbcf9c_000bd096\n"
        "movl -0x74(%ebp), %ecx\n" /* sysFiles */
        "jmp .Lfbcf9c_000bd05b\n"
    );
}

/* line 90 */
__attribute__((naked))
int SE_BuildFileList(const char *psStartDir, LocalizeString *strResults)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 90 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* strResults */
        "movl $0, giFilesFound\n" /* line 92 */
        "movl $0, 8(%esp)\n" /* line 906 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* strResults */
        "calll __ZNSs6assignEPKcm\n"
        "movl %ebx, %ecx\n" /* line 95 | strResults */
        "movl 8(%ebp), %edx\n" /* psStartDir */
        "movl $0x216ce0, %eax\n" /* "str" */
        "calll SE_R_ListFiles\n"
        "movl giFilesFound, %eax\n"
        "addl $0x14, %esp\n" /* line 98 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

