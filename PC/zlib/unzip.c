/* ASM dump from: unzip.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/zlib/unzip.c */

#include "common_types.h"
#include "imports.h"

unzFile unzReOpen(const char *path, unzFile file);
int unzGetGlobalInfo(unzFile file, unz_global_info *pglobal_info);
int unzGetCurrentFileInfoPosition(unzFile file, long unsigned int *pos);
int unzReadCurrentFile(unzFile file, voidp buf, unsigned int len);
long int unztell(unzFile file);
int unzCloseCurrentFile(unzFile file);
static int unzlocal_GetCurrentFileInfoInternal(unz_file_info_internal *pfile_info_internal, char *szFileName, uLong fileNameBufferSize, double *extraField, uLong extraFieldBufferSize, char *szComment, uLong commentBufferSize);
int unzSetCurrentFileInfoPosition(unzFile file, long unsigned int pos);
int unzGoToNextFile(unzFile file);
int unzGoToFirstFile(unzFile file);
int unzGetCurrentFileInfo(unzFile file, unz_file_info *pfile_info, char *szFileName, uLong fileNameBufferSize, double *extraField, uLong extraFieldBufferSize, char *szComment, uLong commentBufferSize);
unzFile unzOpen(const char *path);
int unzClose(unzFile file);
int unzOpenCurrentFile(unzFile file);

/* line 326 */
__attribute__((naked))
unzFile unzReOpen(const char *path, unzFile file)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 326 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl $0x215b98, 4(%esp)\n" /* line 331 */
        "movl 8(%ebp), %eax\n" /* path */
        "movl %eax, (%esp)\n"
        "calll FS_FileOpen\n"
        "movl %eax, %esi\n" /* fin */
        "testl %eax, %eax\n" /* line 332 */
        "je .Lf27950_000279a8\n"
        "movl $0x80, (%esp)\n" /* line 335 */
        "calll malloc\n"
        "movl %eax, %ebx\n"
        "movl $0x80, 8(%esp)\n" /* line 336 */
        "movl 0xc(%ebp), %eax\n" /* file */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Com_Memcpy\n"
        "movl %esi, (%ebx)\n" /* line 338 | fin */
        "movl $0, 0x7c(%ebx)\n" /* line 339 */
        "movl %ebx, %eax\n" /* line 340 */
        /* } scope */
        "addl $0x10, %esp\n" /* line 341 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf27950_000279a8:\n"
        "xorl %eax, %eax\n" /* line 332 */
        /* } scope */
        "addl $0x10, %esp\n" /* line 341 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 472 */
__attribute__((naked))
int unzGetGlobalInfo(unzFile file, unz_global_info *pglobal_info)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 472 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* file */
        "testl %eax, %eax\n" /* line 477 */
        "je .Lf279b2_000279ce\n"
        "movl 8(%eax), %edx\n" /* line 480 */
        "movl 4(%eax), %eax\n"
        "movl 0xc(%ebp), %ecx\n" /* pglobal_info */
        "movl %eax, (%ecx)\n"
        "movl %edx, 4(%ecx)\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n" /* line 482 */
        "retl\n"
        ".Lf279b2_000279ce:\n"
        "movl $0xffffff9a, %eax\n" /* line 477 */
        "popl %ebp\n" /* line 482 */
        "retl\n"
    );
}

/* line 757 */
__attribute__((naked))
int unzGetCurrentFileInfoPosition(unzFile file, long unsigned int *pos)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 757 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* file */
        "testl %eax, %eax\n" /* line 761 */
        "je .Lf279d6_000279ec\n"
        "movl 0x14(%eax), %eax\n" /* line 765 */
        "movl 0xc(%ebp), %edx\n" /* pos */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n" /* line 767 */
        "retl\n"
        ".Lf279d6_000279ec:\n"
        "movl $0xffffff9a, %eax\n" /* line 761 */
        "popl %ebp\n" /* line 767 */
        "retl\n"
    );
}

/* line 1043 */
__attribute__((naked))
int unzReadCurrentFile(unzFile file, voidp buf, unsigned int len)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1043 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* file */
        /* { scope 1 */
        "testl %eax, %eax\n" /* line 1052 */
        "jne .Lf279f4_00027a13\n"
        ".Lf279f4_00027a04:\n"
        "movl $0xffffff9a, %edi\n" /* line 1057 | err */
        /* } scope */
        ".Lf279f4_00027a09:\n"
        "movl %edi, %eax\n" /* line 1168 | err */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf279f4_00027a13:\n"
        "movl 0x7c(%eax), %esi\n" /* line 1055 | pfile_in_zip_read_info */
        "testl %esi, %esi\n" /* line 1057 | pfile_in_zip_read_info */
        "je .Lf279f4_00027a04\n"
        "movl (%esi), %edi\n" /* line 1061 | pfile_in_zip_read_info, err */
        "testl %edi, %edi\n" /* err */
        "je .Lf279f4_00027b70\n"
        "movl 0x10(%ebp), %ebx\n" /* line 1063 | len */
        "testl %ebx, %ebx\n"
        "je .Lf279f4_00027b61\n"
        "movl 0xc(%ebp), %eax\n" /* line 1066 | buf */
        "movl %eax, 0x10(%esi)\n" /* pfile_in_zip_read_info */
        "movl 0x10(%ebp), %edx\n" /* line 1068 | len */
        "movl %edx, 0x14(%esi)\n" /* pfile_in_zip_read_info */
        "movl 0x54(%esi), %eax\n" /* line 1070 | pfile_in_zip_read_info */
        "cmpl %eax, %edx\n"
        "jbe .Lf279f4_00027a45\n"
        "movl %eax, 0x14(%esi)\n" /* line 1072 | pfile_in_zip_read_info */
        ".Lf279f4_00027a45:\n"
        "xorl %edi, %edi\n" /* err */
        "movl $0, -0x1c(%ebp)\n" /* iRead */
        ".Lf279f4_00027a4e:\n"
        "movl 0x14(%esi), %eax\n" /* line 1074 | pfile_in_zip_read_info */
        "testl %eax, %eax\n"
        "je .Lf279f4_00027af3\n"
        "movl 8(%esi), %ecx\n" /* line 1076 | pfile_in_zip_read_info */
        "testl %ecx, %ecx\n"
        "jne .Lf279f4_00027a6b\n"
        "movl 0x50(%esi), %eax\n" /* pfile_in_zip_read_info */
        "testl %eax, %eax\n"
        "jne .Lf279f4_00027afe\n"
        ".Lf279f4_00027a6b:\n"
        "movl 0x5c(%esi), %edx\n" /* line 1100 | pfile_in_zip_read_info */
        "testl %edx, %edx\n"
        "jne .Lf279f4_00027aba\n"
        /* { scope 2 */
        "movl 0x14(%esi), %ebx\n" /* line 1103 | pfile_in_zip_read_info, uDoCopy */
        "movl %ebx, %edx\n" /* uDoCopy */
        "movl 8(%esi), %eax\n" /* pfile_in_zip_read_info */
        "cmpl %eax, %ebx\n" /* uDoCopy */
        "cmovael %eax, %ebx\n" /* uDoCopy */
        "testl %ebx, %ebx\n" /* line 1109 | uDoCopy */
        "je .Lf279f4_00027a9f\n"
        "xorl %ecx, %ecx\n"
        ".Lf279f4_00027a85:\n"
        "movl 0x10(%esi), %eax\n" /* line 1111 | pfile_in_zip_read_info */
        "movl 4(%esi), %edx\n" /* pfile_in_zip_read_info */
        "movzbl (%edx, %ecx), %edx\n"
        "movb %dl, (%eax, %ecx)\n"
        "addl $1, %ecx\n" /* line 1109 */
        "cmpl %ecx, %ebx\n" /* uDoCopy */
        "jne .Lf279f4_00027a85\n"
        "movl 0x14(%esi), %edx\n" /* pfile_in_zip_read_info */
        "movl 8(%esi), %eax\n" /* pfile_in_zip_read_info */
        ".Lf279f4_00027a9f:\n"
        "subl %ebx, 0x54(%esi)\n" /* line 1118 | uDoCopy, pfile_in_zip_read_info */
        "subl %ebx, %eax\n" /* line 1119 | uDoCopy */
        "movl %eax, 8(%esi)\n" /* pfile_in_zip_read_info */
        "subl %ebx, %edx\n" /* line 1120 | uDoCopy */
        "movl %edx, 0x14(%esi)\n" /* pfile_in_zip_read_info */
        "addl %ebx, 0x10(%esi)\n" /* line 1121 | uDoCopy, pfile_in_zip_read_info */
        "addl %ebx, 4(%esi)\n" /* line 1122 | uDoCopy, pfile_in_zip_read_info */
        "addl %ebx, 0x18(%esi)\n" /* line 1123 | uDoCopy, pfile_in_zip_read_info */
        "addl %ebx, -0x1c(%ebp)\n" /* line 1124 | uDoCopy, iRead */
        "jmp .Lf279f4_00027a4e\n"
        /* } scope */
        /* { scope 2 */
        ".Lf279f4_00027aba:\n"
        "movl 0x18(%esi), %ebx\n" /* line 1133 | pfile_in_zip_read_info, uTotalOutBefore */
        "movl $2, 4(%esp)\n" /* line 1142 */
        "leal 4(%esi), %eax\n" /* pfile_in_zip_read_info */
        "movl %eax, (%esp)\n"
        "calll inflate\n"
        "movl %eax, %edi\n" /* err */
        "movl 0x18(%esi), %eax\n" /* line 1145 | pfile_in_zip_read_info */
        "subl %ebx, %eax\n" /* uTotalOutBefore */
        "subl %eax, 0x54(%esi)\n" /* line 1154 | pfile_in_zip_read_info */
        "addl %eax, -0x1c(%ebp)\n" /* line 1156 | iRead */
        "cmpl $1, %edi\n" /* line 1158 | err */
        "je .Lf279f4_00027b68\n"
        "testl %edi, %edi\n" /* line 1160 | err */
        "je .Lf279f4_00027a4e\n"
        "jmp .Lf279f4_00027a09\n"
        /* } scope */
        ".Lf279f4_00027af3:\n"
        "testl %edi, %edi\n" /* line 1166 | err */
        "cmovel -0x1c(%ebp), %edi\n" /* iRead, err */
        "jmp .Lf279f4_00027a09\n"
        /* { scope 2 */
        ".Lf279f4_00027afe:\n"
        "movl $0x4000, %ebx\n" /* line 1080 | uReadThis */
        "cmpl $0x3fff, %eax\n"
        "cmovbel %eax, %ebx\n" /* uReadThis */
        "movl $0, 8(%esp)\n" /* line 1084 */
        "movl 0x3c(%esi), %eax\n" /* pfile_in_zip_read_info */
        "addl 0x60(%esi), %eax\n" /* pfile_in_zip_read_info */
        "movl %eax, 4(%esp)\n"
        "movl 0x58(%esi), %eax\n" /* pfile_in_zip_read_info */
        "movl %eax, (%esp)\n"
        "calll FS_FileSeek\n"
        "testl %eax, %eax\n"
        "jne .Lf279f4_00027b7a\n"
        "movl 0x58(%esi), %eax\n" /* line 1088 | pfile_in_zip_read_info */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* uReadThis */
        "movl (%esi), %eax\n" /* pfile_in_zip_read_info */
        "movl %eax, (%esp)\n"
        "calll FS_FileRead\n"
        "subl $1, %eax\n"
        "jne .Lf279f4_00027b7a\n"
        "addl %ebx, 0x3c(%esi)\n" /* line 1091 | uReadThis, pfile_in_zip_read_info */
        "subl %ebx, 0x50(%esi)\n" /* line 1093 | uReadThis, pfile_in_zip_read_info */
        "movl (%esi), %eax\n" /* line 1096 | pfile_in_zip_read_info */
        "movl %eax, 4(%esi)\n" /* pfile_in_zip_read_info */
        "movl %ebx, 8(%esi)\n" /* line 1097 | uReadThis, pfile_in_zip_read_info */
        "jmp .Lf279f4_00027a6b\n"
        /* } scope */
        ".Lf279f4_00027b61:\n"
        "xorl %edi, %edi\n" /* line 1063 | err */
        "jmp .Lf279f4_00027a09\n"
        /* { scope 2 */
        ".Lf279f4_00027b68:\n"
        "movl -0x1c(%ebp), %edi\n" /* line 1159 | iRead, err */
        "jmp .Lf279f4_00027a09\n"
        /* } scope */
        ".Lf279f4_00027b70:\n"
        "movl $0xffffff9c, %edi\n" /* line 1061 | err */
        "jmp .Lf279f4_00027a09\n"
        /* { scope 2 */
        ".Lf279f4_00027b7a:\n"
        "movl $0xffffffff, %edi\n" /* line 1088 | err */
        "jmp .Lf279f4_00027a09\n"
    );
}

/* line 1174 */
__attribute__((naked))
long int unztell(unzFile file)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1174 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* file */
        /* { scope 1 */
        "testl %eax, %eax\n" /* line 1179 */
        "jne .Lf27b84_00027b95\n"
        ".Lf27b84_00027b8e:\n"
        "movl $0xffffff9a, %eax\n" /* line 1187 */
        /* } scope */
        "popl %ebp\n" /* line 1188 */
        "retl\n"
        /* { scope 1 */
        ".Lf27b84_00027b95:\n"
        "movl 0x7c(%eax), %eax\n" /* line 1182 */
        "testl %eax, %eax\n" /* line 1184 */
        "je .Lf27b84_00027b8e\n"
        "movl 0x18(%eax), %eax\n" /* line 1187 */
        /* } scope */
        "popl %ebp\n" /* line 1188 */
        "retl\n"
    );
}

/* line 1274 */
__attribute__((naked))
int unzCloseCurrentFile(unzFile file)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1274 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* file */
        /* { scope 1 */
        "testl %esi, %esi\n" /* line 1281 | file */
        "jne .Lf27ba2_00027bbd\n"
        ".Lf27ba2_00027bb1:\n"
        "movl $0xffffff9a, %eax\n" /* line 1286 */
        /* } scope */
        "addl $0x10, %esp\n" /* line 1308 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf27ba2_00027bbd:\n"
        "movl 0x7c(%esi), %ebx\n" /* line 1284 | file, pfile_in_zip_read_info */
        "testl %ebx, %ebx\n" /* line 1286 | pfile_in_zip_read_info */
        "je .Lf27ba2_00027bb1\n"
        "movl (%ebx), %eax\n" /* line 1297 | pfile_in_zip_read_info */
        "movl %eax, (%esp)\n"
        "calll free\n"
        "movl $0, (%ebx)\n" /* line 1298 | pfile_in_zip_read_info */
        "movl 0x40(%ebx), %ecx\n" /* line 1299 | pfile_in_zip_read_info */
        "testl %ecx, %ecx\n"
        "jne .Lf27ba2_00027bfa\n"
        ".Lf27ba2_00027bdb:\n"
        "movl $0, 0x40(%ebx)\n" /* line 1302 | pfile_in_zip_read_info */
        "movl %ebx, (%esp)\n" /* line 1303 | pfile_in_zip_read_info */
        "calll free\n"
        "movl $0, 0x7c(%esi)\n" /* line 1305 | file */
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 1308 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf27ba2_00027bfa:\n"
        "leal 4(%ebx), %eax\n" /* line 1300 | pfile_in_zip_read_info */
        "movl %eax, (%esp)\n"
        "calll inflateEnd\n"
        "jmp .Lf27ba2_00027bdb\n"
    );
}

/* line 522 */
static __attribute__((naked))
int unzlocal_GetCurrentFileInfoInternal(unz_file_info_internal *pfile_info_internal, char *szFileName, uLong fileNameBufferSize, double *extraField, uLong extraFieldBufferSize, char *szComment, uLong commentBufferSize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 522 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl %eax, %ebx\n" /* file */
        "movl %edx, %edi\n" /* pfile_info */
        "movl %ecx, -0x94(%ebp)\n"
        /* { scope 1: v, uSizeRead */
        "testl %eax, %eax\n" /* line 540 */
        "je .Lf27c08_0002810e\n"
        "movl $0, 8(%esp)\n" /* line 543 */
        "movl 0x14(%eax), %eax\n"
        "addl 0xc(%ebx), %eax\n" /* file */
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n" /* file */
        "movl %eax, (%esp)\n"
        "calll FS_FileSeek\n"
        "movl %eax, %esi\n"
        "testl %eax, %eax\n"
        "je .Lf27c08_000280ca\n"
        "movl $0xffffffff, -0x90(%ebp)\n" /* err */
        /* { scope 2 */
        ".Lf27c08_00027c56:\n"
        "movl (%ebx), %eax\n" /* line 120 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "leal -0x1c(%ebp), %edx\n" /* v */
        "movl %edx, (%esp)\n"
        "calll FS_FileRead\n"
        "movswl -0x1c(%ebp), %ecx\n" /* line 124 | v */
        "movl %ecx, -0x34(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 120 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* v */
        "movl %eax, (%esp)\n"
        "calll FS_FileRead\n"
        "movswl -0x1c(%ebp), %edx\n" /* line 124 | v */
        "movl %edx, -0x38(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 120 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "leal -0x1c(%ebp), %ecx\n" /* v */
        "movl %ecx, (%esp)\n"
        "calll FS_FileRead\n"
        "movswl -0x1c(%ebp), %eax\n" /* line 124 | v */
        "movl %eax, -0x3c(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 120 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "leal -0x1c(%ebp), %edx\n" /* v */
        "movl %edx, (%esp)\n"
        "calll FS_FileRead\n"
        "movswl -0x1c(%ebp), %ecx\n" /* line 124 | v */
        "movl %ecx, -0x40(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 162 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* v */
        "movl %eax, (%esp)\n"
        "calll FS_FileRead\n"
        "movl -0x1c(%ebp), %edx\n" /* line 166 | v */
        "movl %edx, -0x44(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "shrl $0x10, %edx\n" /* line 493 */
        "movl %edx, %ecx\n" /* line 494 */
        "andl $0x1f, %ecx\n"
        "movl %ecx, -0x48(%ebp)\n"
        "movl %edx, %eax\n" /* line 495 */
        "andl $0x1e0, %eax\n"
        "shrl $5, %eax\n"
        "subl $1, %eax\n"
        "movl %eax, -0x8c(%ebp)\n"
        "shrl $9, %edx\n" /* line 496 */
        "addl $0x7bc, %edx\n"
        "movl %edx, -0x88(%ebp)\n"
        "movl -0x44(%ebp), %eax\n" /* line 498 */
        "andl $0xf800, %eax\n"
        "shrl $0xb, %eax\n"
        "movl %eax, -0x84(%ebp)\n"
        "movl -0x44(%ebp), %edx\n" /* line 499 */
        "andl $0x7e0, %edx\n"
        "shrl $5, %edx\n"
        "movl %edx, -0x80(%ebp)\n"
        "movl -0x44(%ebp), %eax\n" /* line 500 */
        "andl $0x1f, %eax\n"
        "addl %eax, %eax\n"
        "movl %eax, -0x7c(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 162 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "leal -0x1c(%ebp), %ecx\n" /* v */
        "movl %ecx, (%esp)\n"
        "calll FS_FileRead\n"
        "movl -0x1c(%ebp), %eax\n" /* line 166 | v */
        "movl %eax, -0x4c(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 162 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "leal -0x1c(%ebp), %edx\n" /* v */
        "movl %edx, (%esp)\n"
        "calll FS_FileRead\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 166 | v */
        "movl %ecx, -0x50(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 162 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* v */
        "movl %eax, (%esp)\n"
        "calll FS_FileRead\n"
        "movl -0x1c(%ebp), %edx\n" /* line 166 | v */
        "movl %edx, -0x54(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 120 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "leal -0x1c(%ebp), %ecx\n" /* v */
        "movl %ecx, (%esp)\n"
        "calll FS_FileRead\n"
        "movl -0x1c(%ebp), %eax\n" /* line 124 | v */
        "movw %ax, -0x76(%ebp)\n"
        "movswl %ax, %edx\n"
        "movl %edx, -0x58(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 120 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "leal -0x1c(%ebp), %ecx\n" /* v */
        "movl %ecx, (%esp)\n"
        "calll FS_FileRead\n"
        "movl -0x1c(%ebp), %eax\n" /* line 124 | v */
        "movw %ax, -0x74(%ebp)\n"
        "movswl %ax, %edx\n"
        "movl %edx, -0x5c(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 120 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "leal -0x1c(%ebp), %ecx\n" /* v */
        "movl %ecx, (%esp)\n"
        "calll FS_FileRead\n"
        "movl -0x1c(%ebp), %eax\n" /* line 124 | v */
        "movw %ax, -0x72(%ebp)\n"
        "movswl %ax, %edx\n"
        "movl %edx, -0x60(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 120 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "leal -0x1c(%ebp), %ecx\n" /* v */
        "movl %ecx, (%esp)\n"
        "calll FS_FileRead\n"
        "movswl -0x1c(%ebp), %eax\n" /* line 124 | v */
        "movl %eax, -0x64(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 120 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "leal -0x1c(%ebp), %edx\n" /* v */
        "movl %edx, (%esp)\n"
        "calll FS_FileRead\n"
        "movswl -0x1c(%ebp), %ecx\n" /* line 124 | v */
        "movl %ecx, -0x68(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 162 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* v */
        "movl %eax, (%esp)\n"
        "calll FS_FileRead\n"
        "movl -0x1c(%ebp), %edx\n" /* line 166 | v */
        "movl %edx, -0x6c(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 162 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "leal -0x1c(%ebp), %ecx\n" /* v */
        "movl %ecx, (%esp)\n"
        "calll FS_FileRead\n"
        "movl -0x1c(%ebp), %eax\n" /* line 166 | v */
        "movl %eax, -0x30(%ebp)\n"
        /* } scope */
        "movl -0x58(%ebp), %esi\n" /* line 601 */
        "movl -0x90(%ebp), %eax\n" /* line 602 | err */
        "testl %eax, %eax\n"
        "je .Lf27c08_00028031\n"
        ".Lf27c08_00027f23:\n"
        "movl -0x5c(%ebp), %eax\n" /* line 639 */
        "addl %esi, %eax\n" /* uSizeRead */
        ".Lf27c08_00027f28:\n"
        "movl -0x90(%ebp), %ecx\n" /* line 642 | err */
        "testl %ecx, %ecx\n"
        "jne .Lf27c08_00028020\n"
        "movl 0x18(%ebp), %edx\n" /* szComment */
        "testl %edx, %edx\n"
        "je .Lf27c08_00027f83\n"
        /* { scope 2 */
        "movl 0x1c(%ebp), %edx\n" /* line 645 | commentBufferSize */
        "cmpl %edx, -0x60(%ebp)\n"
        "jae .Lf27c08_00027f4f\n"
        "movl 0x18(%ebp), %ecx\n" /* line 647 | szComment */
        "movl -0x60(%ebp), %edx\n"
        "movb $0, (%ecx, %edx)\n"
        ".Lf27c08_00027f4f:\n"
        "movl %edx, %esi\n" /* uSizeRead */
        "testl %eax, %eax\n" /* line 653 */
        "jne .Lf27c08_0002816f\n"
        ".Lf27c08_00027f59:\n"
        "movl $0, -0x90(%ebp)\n" /* line 654 | err */
        ".Lf27c08_00027f63:\n"
        "cmpw $0, -0x72(%ebp)\n" /* line 658 */
        "je .Lf27c08_00027f75\n"
        "movl 0x1c(%ebp), %eax\n" /* commentBufferSize */
        "testl %eax, %eax\n"
        "jne .Lf27c08_0002813a\n"
        /* } scope */
        ".Lf27c08_00027f75:\n"
        "movl -0x90(%ebp), %eax\n" /* line 666 | err */
        "testl %eax, %eax\n"
        "jne .Lf27c08_00028020\n"
        ".Lf27c08_00027f83:\n"
        "testl %edi, %edi\n" /* pfile_info */
        "je .Lf27c08_0002800b\n"
        "movl -0x6c(%ebp), %eax\n" /* line 667 */
        "movl %eax, 0x34(%edi)\n" /* pfile_info */
        "movl -0x68(%ebp), %edx\n"
        "movl %edx, 0x30(%edi)\n" /* pfile_info */
        "movl -0x64(%ebp), %ecx\n"
        "movl %ecx, 0x2c(%edi)\n" /* pfile_info */
        "movl -0x60(%ebp), %eax\n"
        "movl %eax, 0x28(%edi)\n" /* pfile_info */
        "movl -0x5c(%ebp), %edx\n"
        "movl %edx, 0x24(%edi)\n" /* pfile_info */
        "movl -0x58(%ebp), %ecx\n"
        "movl %ecx, 0x20(%edi)\n" /* pfile_info */
        "movl -0x54(%ebp), %eax\n"
        "movl %eax, 0x1c(%edi)\n" /* pfile_info */
        "movl -0x50(%ebp), %edx\n"
        "movl %edx, 0x18(%edi)\n" /* pfile_info */
        "movl -0x4c(%ebp), %ecx\n"
        "movl %ecx, 0x14(%edi)\n" /* pfile_info */
        "movl -0x7c(%ebp), %eax\n"
        "movl %eax, 0x38(%edi)\n" /* pfile_info */
        "movl -0x80(%ebp), %edx\n"
        "movl %edx, 0x3c(%edi)\n" /* pfile_info */
        "movl -0x84(%ebp), %ecx\n"
        "movl %ecx, 0x40(%edi)\n" /* pfile_info */
        "movl -0x88(%ebp), %eax\n"
        "movl %eax, 0x4c(%edi)\n" /* pfile_info */
        "movl -0x8c(%ebp), %edx\n"
        "movl %edx, 0x48(%edi)\n" /* pfile_info */
        "movl -0x48(%ebp), %ecx\n"
        "movl %ecx, 0x44(%edi)\n" /* pfile_info */
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 0x10(%edi)\n" /* pfile_info */
        "movl -0x40(%ebp), %edx\n"
        "movl %edx, 0xc(%edi)\n" /* pfile_info */
        "movl -0x3c(%ebp), %ecx\n"
        "movl %ecx, 8(%edi)\n" /* pfile_info */
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 4(%edi)\n" /* pfile_info */
        "movl -0x34(%ebp), %edx\n"
        "movl %edx, (%edi)\n" /* pfile_info */
        ".Lf27c08_0002800b:\n"
        "movl -0x94(%ebp), %eax\n" /* line 669 */
        "testl %eax, %eax\n"
        "je .Lf27c08_00028020\n"
        "movl -0x30(%ebp), %eax\n" /* line 670 */
        "movl -0x94(%ebp), %ecx\n"
        "movl %eax, (%ecx)\n"
        /* } scope */
        ".Lf27c08_00028020:\n"
        "movl -0x90(%ebp), %eax\n" /* line 673 | err */
        "addl $0x9c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: v, uSizeRead */
        ".Lf27c08_00028031:\n"
        "movl 8(%ebp), %eax\n" /* line 602 | szFileName */
        "testl %eax, %eax\n"
        "je .Lf27c08_00028076\n"
        /* { scope 2 */
        "movl 0xc(%ebp), %edx\n" /* line 605 | fileNameBufferSize */
        "cmpl %edx, %esi\n" /* uSizeRead */
        "jb .Lf27c08_00028129\n"
        "movl %edx, %esi\n" /* uSizeRead */
        ".Lf27c08_00028045:\n"
        "cmpw $0, -0x76(%ebp)\n" /* line 613 */
        "je .Lf27c08_00028057\n"
        "movl 0xc(%ebp), %eax\n" /* fileNameBufferSize */
        "testl %eax, %eax\n"
        "jne .Lf27c08_00028219\n"
        ".Lf27c08_00028057:\n"
        "movl $0, -0x90(%ebp)\n" /* line 614 | err */
        ".Lf27c08_00028061:\n"
        "movl -0x58(%ebp), %ecx\n" /* line 616 */
        "subl %esi, %ecx\n" /* uSizeRead */
        "movl %ecx, %esi\n" /* uSizeRead */
        /* } scope */
        "movl -0x90(%ebp), %eax\n" /* line 620 | err */
        "testl %eax, %eax\n"
        "jne .Lf27c08_00027f23\n"
        ".Lf27c08_00028076:\n"
        "movl 0x10(%ebp), %eax\n" /* extraField */
        "testl %eax, %eax\n"
        "je .Lf27c08_00027f23\n"
        /* { scope 2 */
        "movl 0x14(%ebp), %eax\n" /* line 623 | extraFieldBufferSize */
        "cmpl %eax, -0x5c(%ebp)\n"
        "jae .Lf27c08_0002819c\n"
        "movl -0x5c(%ebp), %edx\n"
        "movl %edx, -0x70(%ebp)\n" /* uSizeRead */
        "movl $0, -0x2c(%ebp)\n"
        ".Lf27c08_0002809a:\n"
        "testl %esi, %esi\n" /* line 628 | uSizeRead */
        "jne .Lf27c08_000281ad\n"
        ".Lf27c08_000280a2:\n"
        "movl $0, -0x90(%ebp)\n" /* line 629 | err */
        "xorl %esi, %esi\n" /* uSizeRead */
        ".Lf27c08_000280ae:\n"
        "cmpw $0, -0x74(%ebp)\n" /* line 633 */
        "je .Lf27c08_000280c0\n"
        "movl 0x14(%ebp), %eax\n" /* extraFieldBufferSize */
        "testl %eax, %eax\n"
        "jne .Lf27c08_000281da\n"
        ".Lf27c08_000280c0:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 636 */
        "addl %esi, %eax\n" /* uSizeRead */
        "jmp .Lf27c08_00027f28\n"
        /* } scope */
        /* { scope 2 */
        ".Lf27c08_000280ca:\n"
        "movl (%ebx), %eax\n" /* line 162 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* v */
        "movl %eax, (%esp)\n"
        "calll FS_FileRead\n"
        /* } scope */
        "movl $0xffffff99, -0x90(%ebp)\n" /* line 551 | err */
        "cmpl $0x2014b50, -0x1c(%ebp)\n" /* v */
        "cmovnel -0x90(%ebp), %esi\n" /* err */
        "movl %esi, -0x90(%ebp)\n" /* err */
        "jmp .Lf27c08_00027c56\n"
        ".Lf27c08_0002810e:\n"
        "movl $0xffffff9a, -0x90(%ebp)\n" /* line 540 | err */
        /* } scope */
        "movl -0x90(%ebp), %eax\n" /* line 673 | err */
        "addl $0x9c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: v, uSizeRead */
        /* { scope 2 */
        ".Lf27c08_00028129:\n"
        "movl 8(%ebp), %ecx\n" /* line 607 | szFileName */
        "movl -0x58(%ebp), %eax\n"
        "movb $0, (%ecx, %eax)\n"
        "movl %eax, %esi\n" /* uSizeRead */
        "jmp .Lf27c08_00028045\n"
        /* } scope */
        /* { scope 2 */
        ".Lf27c08_0002813a:\n"
        "movl (%ebx), %eax\n" /* line 659 | file */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* uSizeRead */
        "movl 0x18(%ebp), %ecx\n" /* szComment */
        "movl %ecx, (%esp)\n"
        "calll FS_FileRead\n"
        "subl $1, %eax\n"
        "je .Lf27c08_00027f75\n"
        "movl $0xffffffff, -0x90(%ebp)\n" /* err */
        "jmp .Lf27c08_00028020\n"
        ".Lf27c08_0002816f:\n"
        "movl $1, 8(%esp)\n" /* line 654 */
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n" /* file */
        "movl %eax, (%esp)\n"
        "calll FS_FileSeek\n"
        "testl %eax, %eax\n"
        "je .Lf27c08_00027f59\n"
        "movl $0xffffffff, -0x90(%ebp)\n" /* err */
        "jmp .Lf27c08_00027f63\n"
        /* } scope */
        /* { scope 2 */
        ".Lf27c08_0002819c:\n"
        "movl -0x5c(%ebp), %ecx\n" /* line 623 */
        "subl 0x14(%ebp), %ecx\n" /* extraFieldBufferSize */
        "movl %ecx, -0x2c(%ebp)\n"
        "movl %eax, -0x70(%ebp)\n" /* uSizeRead */
        "jmp .Lf27c08_0002809a\n"
        ".Lf27c08_000281ad:\n"
        "movl $1, 8(%esp)\n" /* line 629 */
        "movl %esi, 4(%esp)\n" /* uSizeRead */
        "movl (%ebx), %eax\n" /* file */
        "movl %eax, (%esp)\n"
        "calll FS_FileSeek\n"
        "testl %eax, %eax\n"
        "je .Lf27c08_000280a2\n"
        "movl $0xffffffff, -0x90(%ebp)\n" /* err */
        "jmp .Lf27c08_000280ae\n"
        ".Lf27c08_000281da:\n"
        "movl (%ebx), %eax\n" /* line 634 | file */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl -0x70(%ebp), %edx\n" /* uSizeRead */
        "movl %edx, 4(%esp)\n"
        "movl 0x10(%ebp), %ecx\n" /* extraField */
        "movl %ecx, (%esp)\n"
        "calll FS_FileRead\n"
        "subl $1, %eax\n"
        "movl $0xffffffff, %eax\n"
        "cmovel -0x90(%ebp), %eax\n" /* err */
        "movl %eax, -0x90(%ebp)\n" /* err */
        "movl -0x2c(%ebp), %eax\n" /* line 636 */
        "addl %esi, %eax\n" /* uSizeRead */
        "jmp .Lf27c08_00027f28\n"
        /* } scope */
        /* { scope 2 */
        ".Lf27c08_00028219:\n"
        "movl (%ebx), %eax\n" /* line 614 | file */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* uSizeRead */
        "movl 8(%ebp), %edx\n" /* szFileName */
        "movl %edx, (%esp)\n"
        "calll FS_FileRead\n"
        "subl $1, %eax\n"
        "je .Lf27c08_00028057\n"
        "movl $0xffffffff, -0x90(%ebp)\n" /* err */
        "jmp .Lf27c08_00028061\n"
    );
}

/* line 773 */
__attribute__((naked))
int unzSetCurrentFileInfoPosition(unzFile file, long unsigned int pos)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 773 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %ebx\n" /* file */
        /* { scope 1 */
        "testl %ebx, %ebx\n" /* line 778 | file */
        "je .Lf2824e_000282b1\n"
        "movl 0xc(%ebp), %eax\n" /* line 782 | pos */
        "movl %eax, 0x14(%ebx)\n" /* file */
        "leal 0x78(%ebx), %ecx\n" /* line 785 | file */
        "leal 0x28(%ebx), %edx\n" /* file */
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "movl %ebx, %eax\n" /* file */
        "calll unzlocal_GetCurrentFileInfoInternal\n"
        "testl %eax, %eax\n" /* line 786 */
        "sete %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, 0x18(%ebx)\n" /* file */
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x24, %esp\n" /* line 788 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2824e_000282b1:\n"
        "movl $0xffffff9a, %eax\n" /* line 778 */
        /* } scope */
        "addl $0x24, %esp\n" /* line 788 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 729 */
__attribute__((naked))
int unzGoToNextFile(unzFile file)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 729 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %ebx\n" /* file */
        /* { scope 1 */
        "testl %ebx, %ebx\n" /* line 735 | file */
        "jne .Lf282bc_000282d7\n"
        "movl $0xffffff9a, %edx\n"
        /* } scope */
        ".Lf282bc_000282cf:\n"
        "movl %edx, %eax\n" /* line 751 */
        "addl $0x24, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf282bc_000282d7:\n"
        "movl 0x18(%ebx), %edx\n" /* line 738 | file */
        "testl %edx, %edx\n"
        "jne .Lf282bc_000282eb\n"
        ".Lf282bc_000282de:\n"
        "movl $0xffffff9c, %edx\n" /* line 740 */
        /* } scope */
        "movl %edx, %eax\n" /* line 751 */
        "addl $0x24, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf282bc_000282eb:\n"
        "movl 0x10(%ebx), %edx\n" /* line 740 | file */
        "addl $1, %edx\n"
        "cmpl 4(%ebx), %edx\n" /* file */
        "je .Lf282bc_000282de\n"
        "movl 0x48(%ebx), %eax\n" /* line 744 | file */
        "addl 0x4c(%ebx), %eax\n" /* file */
        "addl 0x50(%ebx), %eax\n" /* file */
        "addl 0x14(%ebx), %eax\n" /* file */
        "addl $0x2e, %eax\n"
        "movl %eax, 0x14(%ebx)\n" /* file */
        "movl %edx, 0x10(%ebx)\n" /* line 745 | file */
        "leal 0x78(%ebx), %ecx\n" /* line 748 | file */
        "leal 0x28(%ebx), %edx\n" /* file */
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "movl %ebx, %eax\n" /* file */
        "calll unzlocal_GetCurrentFileInfoInternal\n"
        "movl %eax, %edx\n"
        "xorl %eax, %eax\n" /* line 749 */
        "testl %edx, %edx\n"
        "sete %al\n"
        "movl %eax, 0x18(%ebx)\n" /* file */
        "jmp .Lf282bc_000282cf\n"
    );
}

/* line 706 */
__attribute__((naked))
int unzGoToFirstFile(unzFile file)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 706 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %ebx\n" /* file */
        /* { scope 1 */
        "testl %ebx, %ebx\n" /* line 711 | file */
        "je .Lf28358_000283c3\n"
        "movl 0x24(%ebx), %eax\n" /* line 714 | file */
        "movl %eax, 0x14(%ebx)\n" /* file */
        "movl $0, 0x10(%ebx)\n" /* line 715 | file */
        "leal 0x78(%ebx), %ecx\n" /* line 718 | file */
        "leal 0x28(%ebx), %edx\n" /* file */
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "movl %ebx, %eax\n" /* file */
        "calll unzlocal_GetCurrentFileInfoInternal\n"
        "movl %eax, %edx\n"
        "xorl %eax, %eax\n" /* line 719 */
        "testl %edx, %edx\n"
        "sete %al\n"
        "movl %eax, 0x18(%ebx)\n" /* file */
        /* } scope */
        "movl %edx, %eax\n" /* line 721 */
        "addl $0x24, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf28358_000283c3:\n"
        "movl $0xffffff9a, %edx\n" /* line 711 */
        /* } scope */
        "movl %edx, %eax\n" /* line 721 */
        "addl $0x24, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 686 */
__attribute__((naked))
int unzGetCurrentFileInfo(unzFile file, unz_file_info *pfile_info, char *szFileName, uLong fileNameBufferSize, double *extraField, uLong extraFieldBufferSize, char *szComment, uLong commentBufferSize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 686 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* file */
        "movl 0xc(%ebp), %edx\n" /* pfile_info */
        "movl 0x10(%ebp), %ecx\n" /* szFileName, szComment */
        "movl %ecx, 8(%ebp)\n" /* szComment, file */
        "movl 0x14(%ebp), %edi\n" /* fileNameBufferSize */
        "movl 0x18(%ebp), %esi\n" /* extraField */
        "movl 0x1c(%ebp), %ebx\n" /* extraFieldBufferSize */
        "movl 0x24(%ebp), %ecx\n" /* line 699 | commentBufferSize */
        "movl %ecx, 0x1c(%ebp)\n" /* extraFieldBufferSize */
        "movl 0x20(%ebp), %ecx\n" /* szComment */
        "movl %ecx, 0x18(%ebp)\n" /* extraField */
        "movl %ebx, 0x14(%ebp)\n" /* extraFieldBufferSize, fileNameBufferSize */
        "movl %esi, 0x10(%ebp)\n" /* extraField, szFileName */
        "movl %edi, 0xc(%ebp)\n" /* fileNameBufferSize, pfile_info */
        "xorl %ecx, %ecx\n"
        "popl %ebx\n" /* line 700 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp unzlocal_GetCurrentFileInfoInternal\n" /* line 699 */
    );
}

/* line 352 */
__attribute__((naked))
unzFile unzOpen(const char *path)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 352 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xec, %esp\n"
        /* { scope 1: uBackRead, v */
        "movl $0x215b98, 4(%esp)\n" /* line 373 */
        "movl 8(%ebp), %eax\n" /* path */
        "movl %eax, (%esp)\n"
        "calll FS_FileOpen\n"
        "movl %eax, %esi\n" /* fin */
        "testl %eax, %eax\n" /* line 374 */
        "je .Lf2840c_00028821\n"
        /* { scope 2: uReadPos */
        "movl $2, 8(%esp)\n" /* line 279 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FS_FileSeek\n"
        "testl %eax, %eax\n"
        "je .Lf2840c_000285fc\n"
        /* } scope */
        ".Lf2840c_00028455:\n"
        "movl $0xffffffff, -0xcc(%ebp)\n" /* line 378 | err */
        "movl $0, -0xd0(%ebp)\n" /* central_pos */
        "xorl %eax, %eax\n"
        ".Lf2840c_0002846b:\n"
        "movl $0, 8(%esp)\n" /* line 381 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* fin */
        "calll FS_FileSeek\n"
        "testl %eax, %eax\n"
        "movl $0xffffffff, %eax\n"
        "cmovel -0xcc(%ebp), %eax\n" /* err */
        "movl %eax, -0xcc(%ebp)\n" /* err */
        /* { scope 2: uReadPos */
        "movl %esi, 0xc(%esp)\n" /* line 162 */
        "movl $1, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "leal -0x1c(%ebp), %ebx\n" /* v */
        "movl %ebx, (%esp)\n"
        "calll FS_FileRead\n"
        /* } scope */
        /* { scope 2: uReadPos */
        "movl %esi, 0xc(%esp)\n" /* line 120 */
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FS_FileRead\n"
        "movl -0x1c(%ebp), %eax\n" /* line 124 | v */
        "movw %ax, -0xbe(%ebp)\n"
        /* } scope */
        /* { scope 2: uReadPos */
        "movl %esi, 0xc(%esp)\n" /* line 120 */
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FS_FileRead\n"
        "movl -0x1c(%ebp), %edi\n" /* line 124 | v */
        /* } scope */
        /* { scope 2: uReadPos */
        "movl %esi, 0xc(%esp)\n" /* line 120 */
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FS_FileRead\n"
        "movswl -0x1c(%ebp), %eax\n" /* line 124 | v */
        "movl %eax, -0xb0(%ebp)\n"
        /* } scope */
        /* { scope 2: uReadPos */
        "movl %esi, 0xc(%esp)\n" /* line 120 */
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FS_FileRead\n"
        /* } scope */
        "movswl -0x1c(%ebp), %eax\n" /* line 404 | v */
        "cmpl %eax, -0xb0(%ebp)\n"
        "je .Lf2840c_00028734\n"
        ".Lf2840c_00028549:\n"
        "movl $0xffffff99, -0xcc(%ebp)\n" /* err */
        /* { scope 2: uReadPos */
        ".Lf2840c_00028553:\n"
        "movl %esi, 0xc(%esp)\n" /* line 162 */
        "movl $1, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FS_FileRead\n"
        "movl -0x1c(%ebp), %eax\n" /* line 166 | v */
        "movl %eax, -0xb8(%ebp)\n"
        /* } scope */
        /* { scope 2: uReadPos */
        "movl %esi, 0xc(%esp)\n" /* line 162 */
        "movl $1, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FS_FileRead\n"
        "movl -0x1c(%ebp), %eax\n" /* line 166 | v */
        "movl %eax, -0xbc(%ebp)\n"
        /* } scope */
        /* { scope 2: uReadPos */
        "movl %esi, 0xc(%esp)\n" /* line 120 */
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FS_FileRead\n"
        "movswl -0x1c(%ebp), %eax\n" /* line 124 | v */
        "movl %eax, -0xb4(%ebp)\n"
        /* } scope */
        "movl -0xb8(%ebp), %edi\n" /* line 422 */
        "addl -0xbc(%ebp), %edi\n"
        "cmpl -0xd0(%ebp), %edi\n" /* central_pos */
        "ja .Lf2840c_000285e5\n"
        "movl -0xcc(%ebp), %ecx\n" /* line 426 | err */
        "testl %ecx, %ecx\n"
        "je .Lf2840c_00028750\n"
        ".Lf2840c_000285e5:\n"
        "movl %esi, (%esp)\n" /* line 428 | fin */
        "calll FS_FileClose\n"
        "xorl %ebx, %ebx\n" /* uReadSize */
        /* } scope */
        "movl %ebx, %eax\n" /* line 443 | file */
        "addl $0xec, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: uBackRead, v */
        /* { scope 2: uReadPos */
        ".Lf2840c_000285fc:\n"
        "movl %esi, (%esp)\n" /* line 283 */
        "calll ftell\n"
        "movl %eax, -0xac(%ebp)\n"
        "cmpl $0xfffe, %eax\n" /* line 285 */
        "movl $0xffff, %eax\n"
        "cmovbel -0xac(%ebp), %eax\n"
        "movl %eax, -0xc8(%ebp)\n" /* uBackRead */
        "movl $0x404, (%esp)\n" /* line 288 */
        "calll malloc\n"
        "movl %eax, -0xd4(%ebp)\n"
        "testl %eax, %eax\n" /* line 289 */
        "je .Lf2840c_00028455\n"
        "cmpl $4, -0xc8(%ebp)\n" /* line 293 | uBackRead */
        "jbe .Lf2840c_000286fd\n"
        "movl $4, %edi\n"
        /* { scope 3 */
        ".Lf2840c_0002864d:\n"
        "addl $0x400, %edi\n" /* line 297 */
        "cmpl %edi, -0xc8(%ebp)\n" /* uBackRead */
        "cmovbl -0xc8(%ebp), %edi\n" /* uBackRead */
        "movl -0xac(%ebp), %eax\n" /* line 301 */
        "subl %edi, %eax\n"
        "movl %eax, -0xc4(%ebp)\n" /* uReadPos */
        "movl -0xac(%ebp), %ebx\n" /* line 304 | uReadSize */
        "subl %eax, %ebx\n" /* uReadSize */
        "cmpl $0x405, %ebx\n" /* uReadSize */
        "movl $0x404, %eax\n"
        "cmovael %eax, %ebx\n" /* uReadSize */
        "movl $0, 8(%esp)\n" /* line 305 */
        "movl -0xc4(%ebp), %eax\n" /* uReadPos */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FS_FileSeek\n"
        "testl %eax, %eax\n"
        "jne .Lf2840c_000286fd\n"
        "movl %esi, 0xc(%esp)\n" /* line 308 */
        "movl $1, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* uReadSize */
        "movl -0xd4(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_FileRead\n"
        "subl $1, %eax\n"
        "jne .Lf2840c_000286fd\n"
        "leal -3(%ebx), %ecx\n" /* line 311 | uReadSize */
        "movl -0xd4(%ebp), %edx\n" /* line 352 */
        "addl %ecx, %edx\n"
        "subl $1, %ecx\n" /* line 311 */
        "leal 1(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf2840c_000286f1\n"
        ".Lf2840c_000286da:\n"
        "cmpb $0x50, -1(%edx)\n" /* line 312 */
        "je .Lf2840c_00028830\n"
        ".Lf2840c_000286e4:\n"
        "subl $1, %edx\n" /* line 319 */
        "subl $1, %ecx\n" /* line 311 */
        "leal 1(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf2840c_000286da\n"
        /* } scope */
        ".Lf2840c_000286f1:\n"
        "cmpl %edi, -0xc8(%ebp)\n" /* line 293 | uBackRead */
        "ja .Lf2840c_0002864d\n"
        ".Lf2840c_000286fd:\n"
        "movl $0, -0xd0(%ebp)\n" /* central_pos */
        ".Lf2840c_00028707:\n"
        "movl -0xd4(%ebp), %eax\n" /* line 322 */
        "movl %eax, (%esp)\n"
        "calll free\n"
        /* } scope */
        "movl -0xd0(%ebp), %ebx\n" /* line 378 | central_pos, uReadSize */
        "testl %ebx, %ebx\n" /* uReadSize */
        "jne .Lf2840c_00028864\n"
        "movl $0xffffffff, -0xcc(%ebp)\n" /* err */
        "xorl %eax, %eax\n"
        "jmp .Lf2840c_0002846b\n"
        ".Lf2840c_00028734:\n"
        "testw %di, %di\n" /* line 404 */
        "jne .Lf2840c_00028549\n"
        "cmpw $0, -0xbe(%ebp)\n"
        "je .Lf2840c_00028553\n"
        "jmp .Lf2840c_00028549\n"
        ".Lf2840c_00028750:\n"
        "movl $0x80, (%esp)\n" /* line 439 */
        "calll malloc\n"
        "movl %eax, %ebx\n" /* uReadSize */
        "movl $0, -0x20(%ebp)\n" /* line 440 */
        "movl -0xd0(%ebp), %eax\n" /* central_pos */
        "movl %eax, -0x80(%ebp)\n"
        "subl %edi, %eax\n"
        "movl %eax, -0x90(%ebp)\n"
        "movl %esi, -0x9c(%ebp)\n" /* fin, us */
        "movl -0xbc(%ebp), %eax\n"
        "movl %eax, -0x78(%ebp)\n"
        "movl -0xb8(%ebp), %eax\n"
        "movl %eax, -0x7c(%ebp)\n"
        "movl -0xb4(%ebp), %eax\n"
        "movl %eax, -0x94(%ebp)\n"
        "movl -0xb0(%ebp), %eax\n"
        "movl %eax, -0x98(%ebp)\n"
        "leal -0x9c(%ebp), %eax\n" /* us */
        "movl $0x80, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* uReadSize */
        "calll memcpy\n"
        /* { scope 2: uReadPos */
        /* { scope 3 */
        "movl 0x24(%ebx), %eax\n" /* line 714 | file */
        "movl %eax, 0x14(%ebx)\n" /* file */
        "movl $0, 0x10(%ebx)\n" /* line 715 | file */
        "leal 0x78(%ebx), %ecx\n" /* line 718 | file */
        "leal 0x28(%ebx), %edx\n" /* file */
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "movl %ebx, %eax\n" /* file */
        "calll unzlocal_GetCurrentFileInfoInternal\n"
        "testl %eax, %eax\n" /* line 719 */
        "sete %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, 0x18(%ebx)\n" /* file */
        /* } scope */
        /* } scope */
        /* } scope */
        "movl %ebx, %eax\n" /* line 443 | file */
        "addl $0xec, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: uBackRead, v */
        /* { scope 2: uReadPos */
        /* { scope 3 */
        ".Lf2840c_00028821:\n"
        "xorl %ebx, %ebx\n" /* line 442 | file */
        /* } scope */
        /* } scope */
        /* } scope */
        "movl %ebx, %eax\n" /* line 443 | file */
        "addl $0xec, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: uBackRead, v */
        /* { scope 2: uReadPos */
        /* { scope 3 */
        ".Lf2840c_00028830:\n"
        "cmpb $0x4b, (%edx)\n" /* line 312 */
        "jne .Lf2840c_000286e4\n"
        "cmpb $5, 1(%edx)\n"
        "jne .Lf2840c_000286e4\n"
        "cmpb $6, 2(%edx)\n"
        "jne .Lf2840c_000286e4\n"
        "addl -0xc4(%ebp), %ecx\n" /* line 319 | uReadPos */
        "movl %ecx, -0xd0(%ebp)\n" /* central_pos */
        "je .Lf2840c_000286f1\n"
        "jmp .Lf2840c_00028707\n"
        /* } scope */
        /* } scope */
        ".Lf2840c_00028864:\n"
        "movl -0xd0(%ebp), %eax\n" /* line 378 | central_pos */
        "movl $0, -0xcc(%ebp)\n" /* err */
        "jmp .Lf2840c_0002846b\n"
    );
}

/* line 451 */
__attribute__((naked))
int unzClose(unzFile file)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 451 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* file */
        "testl %esi, %esi\n" /* line 455 | file */
        "je .Lf2887a_000288e5\n"
        "movl 0x7c(%esi), %ebx\n" /* line 459 | file */
        "testl %ebx, %ebx\n"
        "je .Lf2887a_000288bd\n"
        "movl (%ebx), %eax\n" /* line 1297 */
        "movl %eax, (%esp)\n"
        "calll free\n"
        "movl $0, (%ebx)\n" /* line 1298 */
        "movl 0x40(%ebx), %eax\n" /* line 1299 */
        "testl %eax, %eax\n"
        "jne .Lf2887a_000288d8\n"
        ".Lf2887a_000288a7:\n"
        "movl $0, 0x40(%ebx)\n" /* line 1302 */
        "movl %ebx, (%esp)\n" /* line 1303 */
        "calll free\n"
        "movl $0, 0x7c(%esi)\n" /* line 1305 | file */
        ".Lf2887a_000288bd:\n"
        "movl (%esi), %eax\n" /* line 462 | file */
        "movl %eax, (%esp)\n"
        "calll FS_FileClose\n"
        "movl %esi, (%esp)\n" /* line 463 | file */
        "calll free\n"
        "xorl %eax, %eax\n"
        "addl $0x10, %esp\n" /* line 465 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2887a_000288d8:\n"
        "leal 4(%ebx), %eax\n" /* line 1300 */
        "movl %eax, (%esp)\n"
        "calll inflateEnd\n"
        "jmp .Lf2887a_000288a7\n"
        ".Lf2887a_000288e5:\n"
        "movl $0xffffff9a, %eax\n" /* line 455 */
        "addl $0x10, %esp\n" /* line 465 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 941 */
__attribute__((naked))
int unzOpenCurrentFile(unzFile file)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 941 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* file */
        /* { scope 1: size_extra_field */
        "testl %ebx, %ebx\n" /* line 952 | file */
        "jne .Lf288f2_0002890f\n"
        ".Lf288f2_00028902:\n"
        "movl $0xffffff9a, %eax\n" /* line 955 */
        /* } scope */
        ".Lf288f2_00028907:\n"
        "addl $0x3c, %esp\n" /* line 1030 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: size_extra_field */
        ".Lf288f2_0002890f:\n"
        "movl 0x18(%ebx), %eax\n" /* line 955 | file */
        "testl %eax, %eax\n"
        "je .Lf288f2_00028902\n"
        "movl 0x7c(%ebx), %esi\n" /* line 958 | file, size_filename */
        "testl %esi, %esi\n" /* size_filename */
        "je .Lf288f2_0002894e\n"
        "movl (%esi), %eax\n" /* line 1297 | size_filename */
        "movl %eax, (%esp)\n"
        "calll free\n"
        "movl $0, (%esi)\n" /* line 1298 | size_filename */
        "movl 0x40(%esi), %eax\n" /* line 1299 | size_filename */
        "testl %eax, %eax\n"
        "jne .Lf288f2_00028c25\n"
        ".Lf288f2_00028938:\n"
        "movl $0, 0x40(%esi)\n" /* line 1302 | size_filename */
        "movl %esi, (%esp)\n" /* line 1303 | size_filename */
        "calll free\n"
        "movl $0, 0x7c(%ebx)\n" /* line 1305 | file */
        /* { scope 2: v */
        ".Lf288f2_0002894e:\n"
        "movl $0, 8(%esp)\n" /* line 868 */
        "movl 0x78(%ebx), %eax\n"
        "addl 0xc(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_FileSeek\n"
        "movl %eax, %esi\n" /* size_filename */
        "testl %eax, %eax\n"
        "je .Lf288f2_00028977\n"
        /* } scope */
        ".Lf288f2_00028970:\n"
        "movl $0xffffff99, %eax\n" /* line 1029 */
        "jmp .Lf288f2_00028907\n"
        /* { scope 2: v */
        /* { scope 3 */
        ".Lf288f2_00028977:\n"
        "movl (%ebx), %eax\n" /* line 162 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* v */
        "movl %eax, (%esp)\n"
        "calll FS_FileRead\n"
        /* } scope */
        "movl $0xffffff99, %edi\n" /* line 876 | err */
        "cmpl $0x4034b50, -0x1c(%ebp)\n" /* v */
        "cmovel %esi, %edi\n" /* size_filename, err */
        /* { scope 3 */
        "movl (%ebx), %eax\n" /* line 120 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* v */
        "movl %eax, (%esp)\n"
        "calll FS_FileRead\n"
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* v */
        "movl %eax, (%esp)\n"
        "calll FS_FileRead\n"
        "movswl -0x1c(%ebp), %esi\n" /* line 124 | v */
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %eax\n" /* line 120 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* v */
        "movl %eax, (%esp)\n"
        "calll FS_FileRead\n"
        "movl -0x1c(%ebp), %eax\n" /* line 124 | v */
        "movswl %ax, %edx\n"
        /* } scope */
        "testl %edi, %edi\n" /* line 890 | err */
        "jne .Lf288f2_00028a26\n"
        "cmpl 0x34(%ebx), %edx\n"
        "je .Lf288f2_00028c0f\n"
        ".Lf288f2_00028a21:\n"
        "movl $0xffffff99, %edi\n" /* line 893 | err */
        /* { scope 3 */
        ".Lf288f2_00028a26:\n"
        "movl (%ebx), %eax\n" /* line 162 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* v */
        "movl %eax, (%esp)\n"
        "calll FS_FileRead\n"
        /* } scope */
        /* { scope 3 */
        "movl (%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* v */
        "movl %eax, (%esp)\n"
        "calll FS_FileRead\n"
        "movl -0x1c(%ebp), %eax\n" /* line 166 | v */
        /* } scope */
        "testl %edi, %edi\n" /* line 902 | err */
        "jne .Lf288f2_00028a89\n"
        "cmpl 0x3c(%ebx), %eax\n"
        "je .Lf288f2_00028c3c\n"
        "testl $8, %esi\n" /* size_filename */
        "jne .Lf288f2_00028c3c\n"
        "movl $0xffffff99, %edi\n" /* err */
        /* { scope 3 */
        ".Lf288f2_00028a89:\n"
        "movl (%ebx), %eax\n" /* line 162 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* v */
        "movl %eax, (%esp)\n"
        "calll FS_FileRead\n"
        "movl -0x1c(%ebp), %eax\n" /* line 166 | v */
        /* } scope */
        "testl %edi, %edi\n" /* line 908 | err */
        "jne .Lf288f2_00028acb\n"
        "cmpl 0x40(%ebx), %eax\n"
        "je .Lf288f2_00028c43\n"
        "testl $8, %esi\n" /* size_filename */
        "jne .Lf288f2_00028c43\n"
        "movl $0xffffff99, %edi\n" /* err */
        /* { scope 3 */
        ".Lf288f2_00028acb:\n"
        "movl (%ebx), %eax\n" /* line 162 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* v */
        "movl %eax, (%esp)\n"
        "calll FS_FileRead\n"
        "movl -0x1c(%ebp), %eax\n" /* line 166 | v */
        /* } scope */
        "testl %edi, %edi\n" /* line 914 | err */
        "jne .Lf288f2_00028b0a\n"
        "cmpl 0x44(%ebx), %eax\n"
        "je .Lf288f2_00028c35\n"
        "andl $8, %esi\n" /* size_filename */
        "jne .Lf288f2_00028c35\n"
        "movl $0xffffff99, %edi\n" /* err */
        /* { scope 3 */
        ".Lf288f2_00028b0a:\n"
        "movl (%ebx), %eax\n" /* line 120 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* v */
        "movl %eax, (%esp)\n"
        "calll FS_FileRead\n"
        "movswl -0x1c(%ebp), %esi\n" /* line 124 | v */
        /* } scope */
        "testl %edi, %edi\n" /* line 921 | err */
        "jne .Lf288f2_00028b3e\n"
        "cmpl 0x48(%ebx), %esi\n" /* size_filename */
        "movl $0xffffff99, %eax\n"
        "cmovnel %eax, %edi\n" /* err */
        /* { scope 3 */
        ".Lf288f2_00028b3e:\n"
        "movl (%ebx), %eax\n" /* line 120 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* v */
        "movl %eax, (%esp)\n"
        "calll FS_FileRead\n"
        "movswl -0x1c(%ebp), %eax\n" /* line 124 | v */
        "movl %eax, -0x2c(%ebp)\n" /* size_extra_field */
        /* } scope */
        "movl %esi, %eax\n" /* line 929 | size_filename */
        "addl 0x78(%ebx), %eax\n"
        "addl $0x1e, %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* offset_local_extrafield */
        "addl -0x2c(%ebp), %esi\n" /* line 932 | size_extra_field, size_filename */
        "movl %esi, -0x34(%ebp)\n" /* size_filename, iSizeVar */
        /* } scope */
        "testl %edi, %edi\n" /* line 961 | err */
        "jne .Lf288f2_00028970\n"
        "movl $0x64, (%esp)\n" /* line 965 */
        "calll malloc\n"
        "movl %eax, %esi\n" /* size_filename */
        "testl %eax, %eax\n" /* line 966 */
        "je .Lf288f2_00028c9e\n"
        "movl $0x4000, (%esp)\n" /* line 969 */
        "calll malloc\n"
        "movl %eax, (%esi)\n" /* size_filename */
        "movl -0x30(%ebp), %eax\n" /* line 970 | offset_local_extrafield */
        "movl %eax, 0x44(%esi)\n" /* size_filename */
        "movl -0x2c(%ebp), %eax\n" /* line 971 | size_extra_field */
        "movl %eax, 0x48(%esi)\n" /* size_filename */
        "movl $0, 0x4c(%esi)\n" /* line 972 | size_filename */
        "movl (%esi), %eax\n" /* line 974 | size_filename */
        "testl %eax, %eax\n"
        "je .Lf288f2_00028c96\n"
        "movl $0, 0x40(%esi)\n" /* line 980 | size_filename */
        "movl 0x34(%ebx), %eax\n" /* line 982 | file */
        "movl %eax, 0x5c(%esi)\n" /* line 992 | size_filename */
        "movl (%ebx), %edx\n" /* line 993 | file */
        "movl %edx, 0x58(%esi)\n" /* size_filename */
        "movl 0xc(%ebx), %edx\n" /* line 994 | file */
        "movl %edx, 0x60(%esi)\n" /* size_filename */
        "movl $0, 0x18(%esi)\n" /* line 996 | size_filename */
        "testl %eax, %eax\n" /* line 998 */
        "jne .Lf288f2_00028c4a\n"
        ".Lf288f2_00028be3:\n"
        "movl 0x40(%ebx), %eax\n" /* line 1016 | file */
        "movl %eax, 0x50(%esi)\n" /* size_filename */
        "movl 0x44(%ebx), %eax\n" /* line 1018 | file */
        "movl %eax, 0x54(%esi)\n" /* size_filename */
        "movl 0x78(%ebx), %eax\n" /* line 1023 | file */
        "addl %eax, -0x34(%ebp)\n" /* iSizeVar */
        "movl -0x34(%ebp), %eax\n" /* iSizeVar */
        "addl $0x1e, %eax\n"
        "movl %eax, 0x3c(%esi)\n" /* size_filename */
        "movl $0, 8(%esi)\n" /* line 1025 | size_filename */
        "movl %esi, 0x7c(%ebx)\n" /* line 1028 | size_filename, file */
        "xorl %eax, %eax\n"
        "jmp .Lf288f2_00028907\n"
        /* { scope 2: v */
        ".Lf288f2_00028c0f:\n"
        "testw %ax, %ax\n" /* line 893 */
        "je .Lf288f2_00028c1e\n"
        "cmpw $8, %ax\n"
        "jne .Lf288f2_00028a21\n"
        ".Lf288f2_00028c1e:\n"
        "xorl %edi, %edi\n" /* err */
        "jmp .Lf288f2_00028a26\n"
        /* } scope */
        ".Lf288f2_00028c25:\n"
        "leal 4(%esi), %eax\n" /* line 1300 | size_filename */
        "movl %eax, (%esp)\n"
        "calll inflateEnd\n"
        "jmp .Lf288f2_00028938\n"
        /* { scope 2: v */
        ".Lf288f2_00028c35:\n"
        "xorl %edi, %edi\n" /* line 914 | err */
        "jmp .Lf288f2_00028b0a\n"
        ".Lf288f2_00028c3c:\n"
        "xorl %edi, %edi\n" /* line 902 | err */
        "jmp .Lf288f2_00028a89\n"
        ".Lf288f2_00028c43:\n"
        "xorl %edi, %edi\n" /* line 908 | err */
        "jmp .Lf288f2_00028acb\n"
        /* } scope */
        ".Lf288f2_00028c4a:\n"
        "movl $0, 0x24(%esi)\n" /* line 1000 | size_filename */
        "movl $0, 0x28(%esi)\n" /* line 1001 | size_filename */
        "movl $0, 0x2c(%esi)\n" /* line 1002 | size_filename */
        "movl $0x38, 0xc(%esp)\n" /* line 1004 */
        "movl $0x215d44, 8(%esp)\n" /* "1.1.4" */
        "movl $0xfffffff1, 4(%esp)\n"
        "leal 4(%esi), %eax\n" /* size_filename */
        "movl %eax, (%esp)\n"
        "calll inflateInit2_\n"
        "testl %eax, %eax\n" /* line 1005 */
        "jne .Lf288f2_00028be3\n"
        "movl $1, 0x40(%esi)\n" /* line 1006 | size_filename */
        "jmp .Lf288f2_00028be3\n"
        ".Lf288f2_00028c96:\n"
        "movl %esi, (%esp)\n" /* line 976 | size_filename */
        "calll free\n"
        ".Lf288f2_00028c9e:\n"
        "movl $0xffffff98, %eax\n"
        "jmp .Lf288f2_00028907\n"
    );
}

