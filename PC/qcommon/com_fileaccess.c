/* ASM dump from: com_fileaccess.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/com_fileaccess.cpp */

#include "common_types.h"
#include "imports.h"

size_t FS_FileRead(long int *ptr, size_t size, size_t nitems, FILE *stream);
size_t FS_FileWrite(const long int *ptr, size_t size, size_t nitems, FILE *stream);
FILE * FS_FileOpen(const char *filename, const char *mode);
int FS_FileClose(FILE *stream);
int FS_FileSeek(FILE *file, long int offset, int whence);

/* line 83 */
__attribute__((naked))
size_t FS_FileRead(long int *ptr, size_t size, size_t nitems, FILE *stream)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 83 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 91 */
        "jmp fread\n" /* line 88 */
    );
}

/* line 101 */
__attribute__((naked))
size_t FS_FileWrite(const long int *ptr, size_t size, size_t nitems, FILE *stream)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 101 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 108 */
        "jmp fwrite\n" /* line 104 */
    );
}

/* line 118 */
__attribute__((naked))
FILE * FS_FileOpen(const char *filename, const char *mode)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 118 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 135 */
        "jmp fopen\n" /* line 129 */
    );
}

/* line 145 */
__attribute__((naked))
int FS_FileClose(FILE *stream)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 145 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 148 */
        "jmp fclose\n" /* line 147 */
    );
}

/* line 158 */
__attribute__((naked))
int FS_FileSeek(FILE *file, long int offset, int whence)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 158 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 166 */
        "jmp fseek\n" /* line 163 */
    );
}

