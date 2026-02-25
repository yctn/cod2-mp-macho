/* ASM dump from: MacFiles.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacFiles.cp */

#include "common_types.h"
#include "imports.h"

void MacFiles_CleanPath(const char *inPath, char *outPath, int inForHFS);
static void RemoveDirectoryContents(void);
OSStatus MacFiles_RemoveDirectoryA(const char *inPath);
int MacFiles_access(const char *inPath, int inMode);

/* line 183 */
__attribute__((naked))
void MacFiles_CleanPath(const char *inPath, char *outPath, int inForHFS)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 183 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ecx\n" /* inPath */
        "movl 0xc(%ebp), %ebx\n" /* outPath */
        "movzbl 0x10(%ebp), %eax\n" /* inForHFS */
        "movzbl (%ecx), %edx\n" /* line 185 */
        "testb %dl, %dl\n"
        "je .Lf8ce0_00008d14\n"
        "testb %al, %al\n" /* line 205 */
        "jne .Lf8ce0_00008d1a\n"
        /* { scope 1 */
        ".Lf8ce0_00008cf9:\n"
        "cmpb $0x5c, %dl\n" /* line 189 */
        "movl $0x2f, %eax\n"
        "cmovel %eax, %edx\n"
        "movb %dl, (%ebx)\n" /* line 201 | outPath */
        "addl $1, %ebx\n" /* outPath */
        /* } scope */
        "movzbl 1(%ecx), %edx\n" /* line 185 */
        "addl $1, %ecx\n"
        "testb %dl, %dl\n"
        "jne .Lf8ce0_00008cf9\n"
        ".Lf8ce0_00008d14:\n"
        "movb $0, (%ebx)\n" /* line 204 | outPath */
        "popl %ebx\n" /* line 205 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf8ce0_00008d1a:\n"
        "cmpb $0x5c, %dl\n" /* line 189 */
        "movl $0x3a, %eax\n"
        "cmovel %eax, %edx\n"
        "movb %dl, (%ebx)\n" /* line 201 | outPath */
        "addl $1, %ebx\n" /* outPath */
        /* } scope */
        "movzbl 1(%ecx), %edx\n" /* line 185 */
        "addl $1, %ecx\n"
        "testb %dl, %dl\n"
        "jne .Lf8ce0_00008d1a\n"
        "jmp .Lf8ce0_00008d14\n"
    );
}

/* overload skip: MacFiles_CleanPath (0x8d38) */

/* line 272 */
static __attribute__((naked))
void RemoveDirectoryContents(void)
{
    __asm__ __volatile__ (
        ".Lf8d8a_00008d8a:\n"
        "pushl %ebp\n" /* line 272 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl %edx, %ebx\n" /* ioInfo */
        /* { scope 1: currRef */
        "leal -0x1c(%ebp), %edx\n" /* line 276 | iterator */
        "movl %edx, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %eax, (%esp)\n" /* inRef */
        "calll FSOpenIterator\n"
        "movswl %ax, %edx\n" /* inRef */
        "movl %edx, (%ebx)\n" /* ioInfo */
        "testw %ax, %ax\n" /* line 277 | inRef */
        "je .Lf8d8a_00008dc4\n"
        /* } scope */
        "addl $0xac, %esp\n" /* line 317 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf8d8a_00008dc4:\n"
        "leal 8(%ebx), %eax\n" /* ioInfo, inRef */
        "movl %eax, -0x80(%ebp)\n" /* inRef */
        "leal 4(%ebx), %eax\n" /* ioInfo, inRef */
        "movl %eax, -0x7c(%ebp)\n" /* inRef */
        "jmp .Lf8d8a_00008dde\n"
        /* { scope 1: currRef */
        /* { scope 2 */
        ".Lf8d8a_00008dd2:\n"
        "cmpl $1, 4(%ebx)\n" /* line 283 | ioInfo */
        "je .Lf8d8a_00008e53\n"
        "movl (%ebx), %eax\n" /* ioInfo, inRef */
        /* } scope */
        ".Lf8d8a_00008dda:\n"
        "testl %eax, %eax\n" /* line 279 | inRef */
        "jne .Lf8d8a_00008e36\n"
        /* { scope 2 */
        ".Lf8d8a_00008dde:\n"
        "movl $0, 0x20(%esp)\n" /* line 282 */
        "movl $0, 0x1c(%esp)\n"
        "leal -0x6c(%ebp), %eax\n" /* currRef, inRef */
        "movl %eax, 0x18(%esp)\n" /* inRef */
        "movl -0x80(%ebp), %eax\n" /* inRef */
        "movl %eax, 0x14(%esp)\n" /* inRef */
        "movl $2, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl -0x7c(%ebp), %eax\n" /* inRef */
        "movl %eax, 8(%esp)\n" /* inRef */
        "movl $1, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* iterator, inRef */
        "movl %eax, (%esp)\n" /* inRef */
        "calll FSGetCatalogInfoBulk\n"
        "movswl %ax, %edx\n" /* inRef */
        "movl %edx, (%ebx)\n" /* ioInfo */
        "testw %ax, %ax\n" /* line 283 | inRef */
        "je .Lf8d8a_00008dd2\n"
        "movl %edx, %eax\n" /* inRef */
        /* } scope */
        "testl %eax, %eax\n" /* line 279 | inRef */
        "je .Lf8d8a_00008dde\n"
        ".Lf8d8a_00008e36:\n"
        "cmpl $0xfffffa77, %eax\n" /* line 310 | inRef */
        "je .Lf8d8a_00008eaf\n"
        ".Lf8d8a_00008e3d:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 315 | iterator, inRef */
        "movl %eax, (%esp)\n" /* inRef */
        "calll FSCloseIterator\n"
        /* } scope */
        "addl $0xac, %esp\n" /* line 317 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: currRef */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf8d8a_00008e53:\n"
        "movzwl 8(%ebx), %esi\n" /* line 285 | ioInfo, nodeFlags */
        "movzwl %si, %edi\n" /* line 288 | nodeFlags */
        "testl $0x10, %edi\n"
        "jne .Lf8d8a_00008e80\n"
        ".Lf8d8a_00008e62:\n"
        "movl (%ebx), %eax\n" /* line 293 | ioInfo, inRef */
        "testl %eax, %eax\n" /* inRef */
        "jne .Lf8d8a_00008e36\n"
        "andl $1, %edi\n" /* line 296 */
        "jne .Lf8d8a_00008e8c\n"
        ".Lf8d8a_00008e6d:\n"
        "leal -0x6c(%ebp), %eax\n" /* line 303 | currRef, inRef */
        "movl %eax, (%esp)\n" /* inRef */
        "calll FSDeleteObject\n"
        "cwtl\n"
        "movl %eax, (%ebx)\n" /* inRef, ioInfo */
        "jmp .Lf8d8a_00008dda\n"
        ".Lf8d8a_00008e80:\n"
        "movl %ebx, %edx\n" /* line 290 | ioInfo */
        "leal -0x6c(%ebp), %eax\n" /* currRef, inRef */
        "calll RemoveDirectoryContents\n"
        "jmp .Lf8d8a_00008e62\n"
        ".Lf8d8a_00008e8c:\n"
        "andl $0xfffffffe, %esi\n" /* line 298 | nodeFlags */
        "movw %si, 8(%ebx)\n" /* nodeFlags, ioInfo */
        "movl -0x80(%ebp), %eax\n" /* line 299 | inRef */
        "movl %eax, 8(%esp)\n" /* inRef */
        "movl $2, 4(%esp)\n"
        "leal -0x6c(%ebp), %eax\n" /* currRef, inRef */
        "movl %eax, (%esp)\n" /* inRef */
        "calll FSSetCatalogInfo\n"
        "jmp .Lf8d8a_00008e6d\n"
        /* } scope */
        /* } scope */
        ".Lf8d8a_00008eaf:\n"
        "movl $0, (%ebx)\n" /* line 312 | ioInfo */
        "jmp .Lf8d8a_00008e3d\n"
    );
}

/* line 321 */
__attribute__((naked))
OSStatus MacFiles_RemoveDirectoryA(const char *inPath)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 321 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x100, %esp\n"
        /* { scope 1 */
        "leal -9(%ebp), %eax\n" /* line 325 | isDirectory */
        "movl %eax, 8(%esp)\n"
        "leal -0x5a(%ebp), %esi\n" /* ref */
        "movl %esi, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* inPath */
        "movl %eax, (%esp)\n"
        "calll FSPathMakeRef\n"
        "movl %eax, %ebx\n" /* error */
        "testl %eax, %eax\n" /* line 326 */
        "je .Lf8eb8_00008eee\n"
        /* } scope */
        ".Lf8eb8_00008ee2:\n"
        "movl %ebx, %eax\n" /* line 346 | error */
        "addl $0x100, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf8eb8_00008eee:\n"
        "cmpb $0, -9(%ebp)\n" /* line 330 | isDirectory */
        "jne .Lf8eb8_00008efb\n"
        "movl $0xffffffce, %ebx\n" /* error */
        "jmp .Lf8eb8_00008ee2\n"
        ".Lf8eb8_00008efb:\n"
        "leal -0xf4(%ebp), %edx\n" /* line 336 | info */
        "movl %esi, %eax\n"
        "calll RemoveDirectoryContents\n"
        "movl -0xf4(%ebp), %eax\n" /* line 339 | info */
        "testl %eax, %eax\n"
        "jne .Lf8eb8_00008ee2\n"
        "movl %esi, (%esp)\n" /* line 342 */
        "calll FSDeleteObject\n"
        "jmp .Lf8eb8_00008ee2\n"
    );
}

/* line 75 */
__attribute__((naked))
int MacFiles_access(const char *inPath, int inMode)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 75 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x410, %esp\n"
        "movl 8(%ebp), %eax\n" /* inPath */
        /* { scope 1 */
        /* { scope 2 */
        "movzbl (%eax), %edx\n" /* line 185 */
        "testb %dl, %dl\n"
        "je .Lf8f1c_00008f72\n"
        "movl %eax, %ecx\n"
        "leal -0x408(%ebp), %esi\n" /* tempPath */
        "movl %esi, %ebx\n" /* outPath */
        /* { scope 3 */
        ".Lf8f1c_00008f3b:\n"
        "cmpb $0x5c, %dl\n" /* line 189 */
        "movl $0x2f, %eax\n"
        "cmovel %eax, %edx\n"
        "movb %dl, (%ebx)\n" /* line 201 | outPath */
        "addl $1, %ebx\n" /* outPath */
        /* } scope */
        "movzbl 1(%ecx), %edx\n" /* line 185 */
        "addl $1, %ecx\n"
        "testb %dl, %dl\n"
        "jne .Lf8f1c_00008f3b\n"
        "movb $0, (%ebx)\n" /* line 204 | outPath */
        /* } scope */
        "movl 0xc(%ebp), %eax\n" /* line 80 | inMode */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll access\n"
        /* } scope */
        "addl $0x410, %esp\n" /* line 81 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf8f1c_00008f72:\n"
        "leal -0x408(%ebp), %esi\n" /* line 185 | tempPath */
        "movl %esi, %ebx\n" /* outPath */
        "movb $0, (%ebx)\n" /* line 204 | outPath */
        /* } scope */
        "movl 0xc(%ebp), %eax\n" /* line 80 | inMode */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll access\n"
        /* } scope */
        "addl $0x410, %esp\n" /* line 81 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

