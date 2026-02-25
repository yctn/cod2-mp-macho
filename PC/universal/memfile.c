/* ASM dump from: memfile.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/universal/memfile.cpp */

#include "common_types.h"
#include "imports.h"

void MemFile_InitForWriting(MemoryFile *memFile, int size, void *buffer, int errorOnOverflow);
void MemFile_ReadData(MemoryFile *memFile, int bytes, void *data);
void MemFile_WriteData(MemoryFile *memFile, int bytes, const void *data);
const char * MemFile_ReadCString(MemoryFile *memFile);
void MemFile_InitForReading(MemoryFile *memFile, int size, void *buffer);
static void MemFile_WriteDataForArchive(MemoryFile *memFile, int bytes, void *data);
void MemFile_WriteCString(MemoryFile *memFile, const char *string);

/* line 181 */
__attribute__((naked))
void MemFile_InitForWriting(MemoryFile *memFile, int size, void *buffer, int errorOnOverflow)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 181 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* memFile */
        "movl 0x10(%ebp), %eax\n" /* line 162 | buffer */
        "movl %eax, (%edx)\n"
        "movl 0xc(%ebp), %eax\n" /* line 163 | size */
        "movl %eax, 4(%edx)\n"
        "movl $0, 8(%edx)\n" /* line 164 */
        "movzbl 0x14(%ebp), %eax\n" /* line 165 | errorOnOverflow */
        "movb %al, 0xc(%edx)\n"
        "movb $0, 0xd(%edx)\n" /* line 166 */
        "movl $MemFile_WriteDataForArchive, 0x10(%edx)\n" /* line 184 */
        "popl %ebp\n" /* line 185 */
        "retl\n"
    );
}

/* line 278 */
__attribute__((naked))
void MemFile_ReadData(MemoryFile *memFile, int bytes, void *data)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 278 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %ebx\n" /* memFile */
        "movl 0xc(%ebp), %esi\n" /* bytes */
        "testl %esi, %esi\n" /* line 286 | bytes */
        "je .Lfa02ca_000a02f9\n"
        "cmpb $0, 0xd(%ebx)\n" /* line 291 | memFile */
        "jne .Lfa02ca_000a02f9\n"
        "movl 8(%ebx), %ecx\n" /* line 294 | memFile */
        "movl 4(%ebx), %edx\n" /* memFile */
        "leal (%esi, %ecx), %eax\n" /* bytes */
        "cmpl %edx, %eax\n"
        "jle .Lfa02ca_000a032a\n"
        "cmpb $0, 0xc(%ebx)\n" /* line 296 | memFile */
        "jne .Lfa02ca_000a0300\n"
        "movb $1, 0xd(%ebx)\n" /* line 299 | memFile */
        ".Lfa02ca_000a02f9:\n"
        "addl $0x20, %esp\n" /* line 309 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa02ca_000a0300:\n"
        "movl %edx, %eax\n" /* line 297 */
        "subl %ecx, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* bytes */
        "movl $0x21e430, 4(%esp)\n" /* "Couldn't read %i bytes from %i-byte buffer (only %i bytes le" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movb $1, 0xd(%ebx)\n" /* line 299 | memFile */
        "jmp .Lfa02ca_000a02f9\n"
        ".Lfa02ca_000a032a:\n"
        "addl (%ebx), %ecx\n" /* line 307 | memFile */
        "movl %esi, 8(%esp)\n" /* bytes */
        "movl %ecx, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* data */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "addl %esi, 8(%ebx)\n" /* line 308 | bytes, memFile */
        "addl $0x20, %esp\n" /* line 309 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 209 */
__attribute__((naked))
void MemFile_WriteData(MemoryFile *memFile, int bytes, const void *data)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 209 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %ebx\n" /* memFile */
        "movl 0xc(%ebp), %esi\n" /* bytes */
        "testl %esi, %esi\n" /* line 217 | bytes */
        "je .Lfa034a_000a0379\n"
        "cmpb $0, 0xd(%ebx)\n" /* line 220 | memFile */
        "jne .Lfa034a_000a0379\n"
        "movl 8(%ebx), %ecx\n" /* line 225 | memFile */
        "movl 4(%ebx), %edx\n" /* memFile */
        "leal (%esi, %ecx), %eax\n" /* bytes */
        "cmpl %edx, %eax\n"
        "jle .Lfa034a_000a03aa\n"
        "cmpb $0, 0xc(%ebx)\n" /* line 227 | memFile */
        "jne .Lfa034a_000a0380\n"
        "movb $1, 0xd(%ebx)\n" /* line 230 | memFile */
        ".Lfa034a_000a0379:\n"
        "addl $0x20, %esp\n" /* line 240 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa034a_000a0380:\n"
        "movl %edx, %eax\n" /* line 228 */
        "subl %ecx, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* bytes */
        "movl $0x21e474, 4(%esp)\n" /* "Couldn't write %i bytes to %i-byte buffer (only %i bytes fre" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movb $1, 0xd(%ebx)\n" /* line 230 | memFile */
        "jmp .Lfa034a_000a0379\n"
        ".Lfa034a_000a03aa:\n"
        "addl (%ebx), %ecx\n" /* line 238 | memFile */
        "movl %esi, 8(%esp)\n" /* bytes */
        "movl 0x10(%ebp), %eax\n" /* data */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        "addl %esi, 8(%ebx)\n" /* line 239 | bytes, memFile */
        "addl $0x20, %esp\n" /* line 240 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 312 */
__attribute__((naked))
const char * MemFile_ReadCString(MemoryFile *memFile)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 312 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* memFile */
        /* { scope 1 */
        "cmpb $0, 0xd(%ebx)\n" /* line 321 | memFile */
        "jne .Lfa03cc_000a03fe\n"
        "movl 8(%ebx), %ecx\n" /* line 324 | memFile */
        "movl %ecx, %eax\n"
        "movl (%ebx), %edx\n" /* memFile */
        ".Lfa03cc_000a03e3:\n"
        "cmpb $0, (%edx, %eax)\n" /* line 325 */
        "je .Lfa03cc_000a0409\n"
        "addl $1, %eax\n" /* line 327 */
        "movl %eax, 8(%ebx)\n" /* memFile */
        "cmpl %eax, 4(%ebx)\n" /* line 328 | memFile */
        "jne .Lfa03cc_000a03e3\n"
        "cmpb $0, 0xc(%ebx)\n" /* line 330 | memFile */
        "jne .Lfa03cc_000a0418\n"
        "movb $1, 0xd(%ebx)\n" /* line 332 | memFile */
        ".Lfa03cc_000a03fe:\n"
        "movl $0x2157b8, %eax\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 339 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa03cc_000a0409:\n"
        "addl $1, %eax\n" /* line 336 */
        "movl %eax, 8(%ebx)\n" /* memFile */
        "leal (%ecx, %edx), %eax\n" /* line 337 */
        /* } scope */
        "addl $0x14, %esp\n" /* line 339 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfa03cc_000a0418:\n"
        "subl %ecx, %eax\n" /* line 331 */
        "movl %eax, 8(%esp)\n"
        "movl $0x21e4b4, 4(%esp)\n" /* "End of memory file while reading string (%i bytes read)
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movb $1, 0xd(%ebx)\n" /* line 332 | memFile */
        "jmp .Lfa03cc_000a03fe\n"
    );
}

/* line 174 */
__attribute__((naked))
void MemFile_InitForReading(MemoryFile *memFile, int size, void *buffer)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 174 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* memFile */
        "movl 0x10(%ebp), %edx\n" /* line 162 | buffer */
        "movl %edx, (%eax)\n"
        "movl 0xc(%ebp), %edx\n" /* line 163 | size */
        "movl %edx, 4(%eax)\n"
        "movl $0, 8(%eax)\n" /* line 164 */
        "movb $1, 0xc(%eax)\n" /* line 165 */
        "movb $0, 0xd(%eax)\n" /* line 166 */
        "movl $MemFile_ReadData, 0x10(%eax)\n" /* line 177 */
        "popl %ebp\n" /* line 178 */
        "retl\n"
    );
}

/* line 150 */
static __attribute__((naked))
void MemFile_WriteDataForArchive(MemoryFile *memFile, int bytes, void *data)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 150 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %ebx\n" /* memFile */
        "movl 0xc(%ebp), %esi\n" /* bytes */
        "testl %esi, %esi\n" /* line 217 | bytes */
        "je .Lfa0462_000a0491\n"
        "cmpb $0, 0xd(%ebx)\n" /* line 220 | memFile */
        "jne .Lfa0462_000a0491\n"
        "movl 8(%ebx), %ecx\n" /* line 225 | memFile */
        "movl 4(%ebx), %edx\n" /* memFile */
        "leal (%esi, %ecx), %eax\n" /* bytes */
        "cmpl %edx, %eax\n"
        "jle .Lfa0462_000a04c2\n"
        "cmpb $0, 0xc(%ebx)\n" /* line 227 | memFile */
        "jne .Lfa0462_000a0498\n"
        "movb $1, 0xd(%ebx)\n" /* line 230 | memFile */
        ".Lfa0462_000a0491:\n"
        "addl $0x20, %esp\n" /* line 153 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa0462_000a0498:\n"
        "movl %edx, %eax\n" /* line 228 */
        "subl %ecx, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* bytes */
        "movl $0x21e474, 4(%esp)\n" /* "Couldn't write %i bytes to %i-byte buffer (only %i bytes fre" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movb $1, 0xd(%ebx)\n" /* line 230 | memFile */
        "jmp .Lfa0462_000a0491\n"
        ".Lfa0462_000a04c2:\n"
        "addl (%ebx), %ecx\n" /* line 238 | memFile */
        "movl %esi, 8(%esp)\n" /* bytes */
        "movl 0x10(%ebp), %eax\n" /* data */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        "addl %esi, 8(%ebx)\n" /* line 239 | bytes, memFile */
        "addl $0x20, %esp\n" /* line 153 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 243 */
__attribute__((naked))
void MemFile_WriteCString(MemoryFile *memFile, const char *string)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 243 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %ebx\n" /* memFile */
        "cld\n" /* line 247 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl 0xc(%ebp), %edi\n" /* string */
        "repne scasb %es:(%edi), %al\n"
        "movl %ecx, %edi\n" /* line 217 */
        "xorl $0xffffffff, %edi\n"
        "je .Lfa04e2_000a051e\n"
        "cmpb $0, 0xd(%ebx)\n" /* line 220 */
        "jne .Lfa04e2_000a051e\n"
        "movl 8(%ebx), %ecx\n" /* line 225 */
        "movl 4(%ebx), %edx\n"
        "leal (%edi, %ecx), %eax\n"
        "cmpl %edx, %eax\n"
        "jle .Lfa04e2_000a054f\n"
        "cmpb $0, 0xc(%ebx)\n" /* line 227 */
        "jne .Lfa04e2_000a0525\n"
        "movb $1, 0xd(%ebx)\n" /* line 230 */
        ".Lfa04e2_000a051e:\n"
        "addl $0x20, %esp\n" /* line 248 */
        "popl %ebx\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfa04e2_000a0525:\n"
        "movl %edx, %eax\n" /* line 228 */
        "subl %ecx, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x21e474, 4(%esp)\n" /* "Couldn't write %i bytes to %i-byte buffer (only %i bytes fre" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movb $1, 0xd(%ebx)\n" /* line 230 */
        "jmp .Lfa04e2_000a051e\n"
        ".Lfa04e2_000a054f:\n"
        "addl (%ebx), %ecx\n" /* line 238 */
        "movl %edi, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* string */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        "addl %edi, 8(%ebx)\n" /* line 239 */
        "addl $0x20, %esp\n" /* line 248 */
        "popl %ebx\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

