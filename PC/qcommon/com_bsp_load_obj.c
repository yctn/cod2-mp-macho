/* ASM dump from: com_bsp_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/com_bsp_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

static int comBspGlob; /* 0xceb380 */

const dheader_t * Com_GetBsp(int *fileSize, unsigned int *checksum);
long int Com_UnloadBsp(void);
long int Com_LoadBsp(const char *filename);
long int Com_CleanupBsp(void);

/* line 25 */
__attribute__((naked))
const dheader_t * Com_GetBsp(int *fileSize, unsigned int *checksum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 25 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* fileSize */
        "movl 0xc(%ebp), %ecx\n" /* checksum */
        "testl %edx, %edx\n" /* line 29 */
        "je .Lf111cf8_00111d0c\n"
        "movl 0xceb384, %eax\n" /* line 30 */
        "movl %eax, (%edx)\n"
        ".Lf111cf8_00111d0c:\n"
        "testl %ecx, %ecx\n" /* line 32 */
        "je .Lf111cf8_00111d17\n"
        "movl 0xceb388, %eax\n" /* line 33 */
        "movl %eax, (%ecx)\n"
        ".Lf111cf8_00111d17:\n"
        "movl comBspGlob, %eax\n"
        "popl %ebp\n" /* line 36 */
        "retl\n"
    );
}

/* line 87 */
__attribute__((naked))
long int Com_UnloadBsp(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 87 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl comBspGlob, %eax\n" /* line 93 */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        "movl $0, comBspGlob\n" /* line 94 */
        "leave\n" /* line 99 */
        "retl\n"
    );
}

/* line 39 */
__attribute__((naked))
long int Com_LoadBsp(const char *filename)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 39 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %esi\n" /* filename */
        /* { scope 1 */
        "movl $0, 8(%esp)\n" /* line 50 */
        "leal -0xc(%ebp), %eax\n" /* h */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* filename */
        "calll FS_FOpenFileRead\n"
        "movl %eax, 0xceb384\n"
        "movl -0xc(%ebp), %edx\n" /* line 51 | h */
        "testl %edx, %edx\n"
        "je .Lf111d3e_00111e54\n"
        ".Lf111d3e_00111d70:\n"
        "movl %eax, (%esp)\n" /* line 54 */
        "calll Z_MallocGarbageInternal\n"
        "movl %eax, comBspGlob\n"
        "movl -0xc(%ebp), %edx\n" /* line 55 | h */
        "movl %edx, 8(%esp)\n"
        "movl 0xceb384, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FS_Read\n"
        "movl %eax, %ebx\n" /* bytesRead */
        "movl -0xc(%ebp), %eax\n" /* line 56 | h */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "cmpl 0xceb384, %ebx\n" /* line 57 | bytesRead */
        "je .Lf111d3e_00111e40\n"
        ".Lf111d3e_00111daf:\n"
        "movl comBspGlob, %eax\n" /* line 59 */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        "movl %esi, 4(%esp)\n" /* line 60 | filename */
        "movl $0x21bf88, (%esp)\n" /* "EXE_ERR_COULDNT_LOAD%s" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf111d3e_00111ddc:\n"
        "movl 0xceb384, %eax\n" /* line 63 */
        "movl %eax, 4(%esp)\n"
        "movl comBspGlob, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_BlockChecksum\n"
        "movl %eax, 0xceb388\n"
        "movl comBspGlob, %eax\n" /* line 66 */
        "movl 4(%eax), %edx\n" /* line 67 */
        "cmpl $0x50534249, (%eax)\n" /* line 68 */
        "je .Lf111d3e_00111e4d\n"
        ".Lf111d3e_00111e07:\n"
        "movl %eax, (%esp)\n" /* line 70 */
        "calll Z_FreeInternal\n"
        "movl %esi, 4(%esp)\n" /* line 71 | filename */
        "movl $0x228df4, (%esp)\n" /* "EXE_ERR_WRONG_MAP_VERSION_NUM%s" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf111d3e_00111e2f:\n"
        "xorl %eax, %eax\n"
        ".Lf111d3e_00111e31:\n"
        "addl $1, %eax\n" /* line 74 */
        "cmpl $0x27, %eax\n"
        "jne .Lf111d3e_00111e31\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 84 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf111d3e_00111e40:\n"
        "cmpl $0x13f, %ebx\n" /* line 57 | bytesRead */
        "ja .Lf111d3e_00111ddc\n"
        "jmp .Lf111d3e_00111daf\n"
        ".Lf111d3e_00111e4d:\n"
        "cmpl $4, %edx\n" /* line 68 */
        "jne .Lf111d3e_00111e07\n"
        "jmp .Lf111d3e_00111e2f\n"
        ".Lf111d3e_00111e54:\n"
        "movl %esi, 4(%esp)\n" /* line 52 | filename */
        "movl $0x21bf88, (%esp)\n" /* "EXE_ERR_COULDNT_LOAD%s" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0xceb384, %eax\n"
        "jmp .Lf111d3e_00111d70\n"
    );
}

/* line 102 */
__attribute__((naked))
long int Com_CleanupBsp(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 102 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl comBspGlob, %eax\n" /* line 21 */
        "testl %eax, %eax\n" /* line 104 */
        "jne .Lf111e7e_00111e8f\n"
        "leave\n" /* line 108 */
        "retl\n"
        ".Lf111e7e_00111e8f:\n"
        "movl %eax, (%esp)\n" /* line 93 */
        "calll Z_FreeInternal\n"
        "movl $0, comBspGlob\n" /* line 94 */
        "leave\n" /* line 108 */
        "retl\n"
    );
}

