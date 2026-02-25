/* ASM dump from: g_weapon_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game/g_weapon_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

static const char * accuracyDirName[3]; /* 0x314b40 */

Bool G_ParseWeaponAccurayGraphs(WeaponDef *weaponDef);

/* line 139 */
__attribute__((naked))
Bool G_ParseWeaponAccurayGraphs(WeaponDef *weaponDef)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 139 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x211c, %esp\n"
        "movl 8(%ebp), %eax\n" /* weaponDef */
        "movl %eax, -0x210c(%ebp)\n"
        "movl $accuracyDirName, -0x20ec(%ebp)\n"
        /* { scope 1 */
        ".Lf1e58b4_001e58d3:\n"
        "movl $0x80, 8(%esp)\n" /* line 148 */
        "movl $0, 4(%esp)\n"
        "leal -0xe0(%ebp), %edx\n" /* accuracyGraphKnots */
        "movl %edx, (%esp)\n"
        "calll memset\n"
        "movl -0x20ec(%ebp), %ebx\n" /* line 151 | size */
        "movl (%ebx), %ecx\n" /* size, dirName */
        "movl -0x210c(%ebp), %edi\n"
        "movl 0x50c(%edi), %edx\n" /* graphName */
        /* { scope 2: fileLength, fileHandle, fileName, buffer, ... */
        /* { scope 3: buffer */
        "movl 8(%ebp), %ebx\n" /* line 88 | weaponDef */
        "movl 0x78(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e58b4_001e593e\n"
        "cmpl $2, %eax\n"
        "je .Lf1e58b4_001e593e\n"
        /* } scope */
        /* } scope */
        ".Lf1e58b4_001e5914:\n"
        "addl $4, -0x210c(%ebp)\n" /* line 159 */
        "addl $4, -0x20ec(%ebp)\n"
        "cmpl $0x314b48, -0x20ec(%ebp)\n" /* line 146 */
        "jne .Lf1e58b4_001e58d3\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lf1e58b4_001e5933:\n"
        "addl $0x211c, %esp\n" /* line 164 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: fileLength, fileHandle, fileName, buffer, ... */
        /* { scope 3: buffer */
        ".Lf1e58b4_001e593e:\n"
        "cmpb $0, (%edx)\n" /* line 91 */
        "je .Lf1e58b4_001e5914\n"
        "movl %edx, 0xc(%esp)\n" /* line 94 */
        "movl %ecx, 8(%esp)\n"
        "movl $0x2b8764, 4(%esp)\n" /* "accuracy/%s/%s" */
        "leal -0x60(%ebp), %edi\n" /* fileName */
        "movl %edi, (%esp)\n"
        "calll sprintf\n"
        "movl $0, 8(%esp)\n" /* line 96 */
        "leal -0x1c(%ebp), %eax\n" /* fileHandle */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll FS_FOpenFileByMode\n"
        "movl %eax, -0x2108(%ebp)\n" /* fileLength */
        "testl %eax, %eax\n" /* line 97 */
        "js .Lf1e58b4_001e5b25\n"
        "movl -0x1c(%ebp), %eax\n" /* line 104 | fileHandle */
        "movl %eax, 8(%esp)\n"
        "movl $0xe, 4(%esp)\n"
        "leal -0x20e0(%ebp), %ebx\n" /* buffer */
        "movl %ebx, (%esp)\n"
        "calll FS_Read\n"
        "movb $0, -0x20d2(%ebp)\n" /* line 105 */
        "movl $0x2b87ac, %ebx\n" /* line 107 */
        "movl $0xe, %ecx\n"
        "cld\n"
        "leal -0x20e0(%ebp), %esi\n" /* buffer, knotCountIndex */
        "movl %ebx, %edi\n"
        "repe cmpsb %es:(%edi), (%esi)\n" /* knotCountIndex */
        "movl $0, %eax\n"
        "je .Lf1e58b4_001e59cd\n"
        "movzbl -1(%esi), %eax\n" /* knotCountIndex */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf1e58b4_001e59cd:\n"
        "testl %eax, %eax\n"
        "jne .Lf1e58b4_001e5a0d\n"
        "movl -0x2108(%ebp), %ebx\n" /* line 115 | fileLength */
        "subl $0xe, %ebx\n"
        "cmpl $0x1fff, %ebx\n"
        "jle .Lf1e58b4_001e5a1d\n"
        "leal -0x60(%ebp), %edx\n" /* line 117 | fileName */
        "movl %edx, 4(%esp)\n"
        "movl $0x2b8800, (%esp)\n" /* "^3WARNING: "%s" Is too long of an ai weapon accuracy file to" */
        ".Lf1e58b4_001e59f0:\n"
        "calll Com_Printf\n"
        "movl -0x1c(%ebp), %eax\n" /* line 118 | fileHandle */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        /* } scope */
        /* } scope */
        "xorl %eax, %eax\n" /* line 151 */
        /* } scope */
        "addl $0x211c, %esp\n" /* line 164 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: fileLength, fileHandle, fileName, buffer, ... */
        /* { scope 3: buffer */
        ".Lf1e58b4_001e5a0d:\n"
        "leal -0x60(%ebp), %eax\n" /* line 109 | fileName */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b87bc, (%esp)\n" /* "^3WARNING: "%s" does not appear to be an ai weapon accuracy " */
        "jmp .Lf1e58b4_001e59f0\n"
        ".Lf1e58b4_001e5a1d:\n"
        "movl $0x2000, 8(%esp)\n" /* line 123 */
        "movl $0, 4(%esp)\n"
        "leal -0x20e0(%ebp), %edi\n" /* buffer */
        "movl %edi, (%esp)\n"
        "calll memset\n"
        "movl -0x1c(%ebp), %eax\n" /* line 124 | fileHandle */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll FS_Read\n"
        "movb $0, -0x20e0(%ebp, %ebx)\n" /* line 125 */
        "movl -0x1c(%ebp), %eax\n" /* line 126 | fileHandle */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movl %edi, -0x20(%ebp)\n" /* buffer */
        /* { scope 4 */
        /* { scope 5 */
        "leal -0x60(%ebp), %ebx\n" /* line 28 | fileName */
        "movl %ebx, (%esp)\n"
        "calll Com_BeginParseSession\n"
        "leal -0x20(%ebp), %edi\n" /* line 31 | buffer */
        "movl %edi, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, (%esp)\n" /* line 32 */
        "calll atoi\n"
        "movl %eax, -0x2104(%ebp)\n" /* knotCountInternal */
        "xorl %esi, %esi\n" /* knotCountIndex */
        "leal -0xdc(%ebp), %ebx\n"
        ".Lf1e58b4_001e5a90:\n"
        "leal -0x20(%ebp), %eax\n" /* line 38 | buffer */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movzbl (%eax), %edx\n" /* line 39 */
        "testb %dl, %dl\n"
        "je .Lf1e58b4_001e5b3c\n"
        "cmpb $0x7d, %dl\n"
        "je .Lf1e58b4_001e5b3c\n"
        "movl %eax, (%esp)\n" /* line 42 */
        "calll atof\n"
        "fstpl -0x2100(%ebp)\n"
        "cvtsd2ss -0x2100(%ebp), %xmm0\n"
        "movss %xmm0, -4(%ebx)\n"
        "leal -0x20(%ebp), %eax\n" /* line 44 | buffer */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movzbl (%eax), %edx\n" /* line 45 */
        "testb %dl, %dl\n"
        "je .Lf1e58b4_001e5b3c\n"
        "cmpb $0x7d, %dl\n"
        "je .Lf1e58b4_001e5b3c\n"
        "movl %eax, (%esp)\n" /* line 48 */
        "calll atof\n"
        "fstpl -0x20f8(%ebp)\n"
        "cvtsd2ss -0x20f8(%ebp), %xmm0\n"
        "movss %xmm0, (%ebx)\n"
        "addl $1, %esi\n" /* line 50 | knotCountIndex */
        "addl $8, %ebx\n"
        "cmpl $0x10, %esi\n" /* line 52 | knotCountIndex */
        "jne .Lf1e58b4_001e5a90\n"
        "leal -0x60(%ebp), %eax\n" /* line 54 | fileName */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b8844, (%esp)\n" /* "^3WARNING: "%s" has too many graph knots
" */
        "calll Com_Printf\n"
        "calll Com_EndParseSession\n" /* line 55 */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        "xorl %eax, %eax\n" /* line 151 */
        "jmp .Lf1e58b4_001e5933\n"
        /* { scope 2: fileLength, fileHandle, fileName, buffer, ... */
        /* { scope 3: buffer */
        ".Lf1e58b4_001e5b25:\n"
        "movl %edi, 4(%esp)\n" /* line 99 */
        "movl $0x2b8774, (%esp)\n" /* "^3WARNING: Could not load ai weapon accuracy file '%s'
" */
        "calll Com_Printf\n"
        /* } scope */
        /* } scope */
        "xorl %eax, %eax\n" /* line 151 */
        "jmp .Lf1e58b4_001e5933\n"
        /* { scope 2: fileLength, fileHandle, fileName, buffer, ... */
        /* { scope 3: buffer */
        /* { scope 4 */
        /* { scope 5 */
        ".Lf1e58b4_001e5b3c:\n"
        "calll Com_EndParseSession\n" /* line 60 */
        "cmpl %esi, -0x2104(%ebp)\n" /* line 62 | knotCountIndex, knotCountInternal */
        "je .Lf1e58b4_001e5b63\n"
        "leal -0x60(%ebp), %edx\n" /* line 64 | fileName */
        "movl %edx, 4(%esp)\n"
        "movl $0x2b8870, (%esp)\n" /* "^3WARNING: "%s" Error in parsing an ai weapon accuracy file
" */
        "calll Com_Printf\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        "xorl %eax, %eax\n" /* line 151 */
        "jmp .Lf1e58b4_001e5933\n"
        /* { scope 2: fileLength, fileHandle, fileName, buffer, ... */
        /* { scope 3: buffer */
        ".Lf1e58b4_001e5b63:\n"
        "movl -0x2104(%ebp), %esi\n" /* line 130 | knotCountInternal, knotCountIndex */
        /* } scope */
        /* } scope */
        "testl %esi, %esi\n" /* line 154 | accuracyGraphKnotCount */
        "jle .Lf1e58b4_001e5914\n"
        "leal (, %esi, 8), %ebx\n" /* line 156 | size */
        "movl $4, 4(%esp)\n" /* line 157 */
        "movl %ebx, (%esp)\n" /* size */
        "calll Hunk_AllocLowAlignInternal\n"
        "movl -0x210c(%ebp), %edi\n"
        "movl %eax, 0x514(%edi)\n"
        "movl %ebx, 8(%esp)\n" /* line 158 | size */
        "leal -0xe0(%ebp), %edx\n" /* accuracyGraphKnots */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl %esi, 0x51c(%edi)\n" /* line 159 | accuracyGraphKnotCount */
        "jmp .Lf1e58b4_001e5914\n"
    );
}

