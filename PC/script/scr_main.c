/* ASM dump from: scr_main.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/script/scr_main.cpp */

#include "common_types.h"
#include "imports.h"

int Scr_IsInOpcodeMemory(const char *pos);
Bool Scr_IsIdentifier(const char *token);
unsigned int SL_TransferToCanonicalString(unsigned int stringValue);
inflate_blocks_statef Scr_BeginLoadAnimTrees(int user);
int Scr_ScanFile(char *buf, int max_size);
unsigned int Scr_LoadScript(const char *filename);
inflate_blocks_statef Scr_PostCompileScripts(void);
inflate_blocks_statef Scr_EndLoadScripts(void);
inflate_blocks_statef Scr_PrecacheAnimTrees(Alloc_t Alloc, int user);
inflate_blocks_statef Scr_EndLoadAnimTrees(void);
inflate_blocks_statef Scr_FreeScripts(int sys);
scr_func_t Scr_GetFunctionHandle(const char *filename, const char *name);
inflate_blocks_statef Scr_BeginLoadScripts(void);
unsigned int SL_GetCanonicalString(const char *str);

/* line 22 */
__attribute__((naked))
int Scr_IsInOpcodeMemory(const char *pos)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 22 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* pos */
        "movl 0x195ee58, %edx\n"
        "subl 0x48(%edx), %eax\n" /* pos */
        "movl 0x195ee5c, %edx\n"
        "cmpl 0x30(%edx), %eax\n" /* pos */
        "setb %al\n" /* pos */
        "movzbl %al, %eax\n" /* pos */
        "popl %ebp\n" /* line 28 */
        "retl\n"
    );
}

/* line 55 */
__attribute__((naked))
Bool Scr_IsIdentifier(const char *token)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 55 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* token */
        "movzbl (%eax), %ebx\n" /* line 57 */
        "testb %bl, %bl\n"
        "je .Lfaf47c_000af4cd\n"
        "movl %eax, %esi\n"
        "movl __DefaultRuneLocale, %edi\n"
        ".Lfaf47c_000af497:\n"
        "movsbl %bl, %eax\n" /* line 59 */
        /* { scope 1 */
        "testl $0xffffff80, %eax\n" /* line 220 */
        "jne .Lfaf47c_000af4da\n"
        "testl $0x500, 0x34(%edi, %eax, 4)\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        ".Lfaf47c_000af4af:\n"
        "testl %eax, %eax\n" /* line 44 | _c */
        "jne .Lfaf47c_000af4c2\n"
        "cmpb $0x5f, %bl\n"
        "je .Lfaf47c_000af4c2\n"
        "xorl %eax, %eax\n" /* line 57 */
        "addl $0x1c, %esp\n" /* line 64 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfaf47c_000af4c2:\n"
        "movzbl 1(%esi), %ebx\n" /* line 57 */
        "addl $1, %esi\n"
        "testb %bl, %bl\n"
        "jne .Lfaf47c_000af497\n"
        ".Lfaf47c_000af4cd:\n"
        "movl $1, %eax\n"
        "addl $0x1c, %esp\n" /* line 64 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfaf47c_000af4da:\n"
        "movl $0x500, 4(%esp)\n" /* line 220 */
        "movl %eax, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "jmp .Lfaf47c_000af4af\n"
    );
}

/* line 138 */
__attribute__((naked))
unsigned int SL_TransferToCanonicalString(unsigned int stringValue)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 138 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* stringValue */
        /* { scope 1 */
        "movl $2, 4(%esp)\n" /* line 144 */
        "movl %ebx, (%esp)\n" /* stringValue */
        "calll SL_TransferRefToUser\n"
        "movl 0x195ee5c, %eax\n" /* line 145 */
        "movl 0x18(%eax), %eax\n"
        "leal (%eax, %ebx, 2), %ecx\n"
        "movzwl (%ecx), %eax\n"
        "movzwl %ax, %edx\n"
        "testw %ax, %ax\n" /* line 146 */
        "jne .Lfaf4f4_000af53b\n"
        "movl 0x195ee58, %eax\n" /* line 148 */
        "movzwl 8(%eax), %edx\n"
        "addl $1, %edx\n"
        "movw %dx, 8(%eax)\n"
        "movw %dx, (%ecx)\n" /* line 149 */
        "movzwl 8(%eax), %edx\n" /* line 150 */
        /* } scope */
        ".Lfaf4f4_000af53b:\n"
        "movl %edx, %eax\n" /* line 151 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 261 */
__attribute__((naked))
inflate_blocks_statef Scr_BeginLoadAnimTrees(int user)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 261 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %eax\n" /* user */
        "movl 0x195ee54, %ebx\n" /* line 268 */
        "movb $1, 0x418(%ebx)\n"
        "movl $0, 0x40c(%ebx, %eax, 4)\n" /* line 270 */
        "shll $9, %eax\n" /* line 271 */
        "movl $0, 0xc(%eax, %ebx)\n"
        "calll Scr_AllocArray\n" /* line 274 */
        "movl %eax, (%ebx)\n"
        "movl $0, 4(%ebx)\n" /* line 279 */
        "movl 0x195ee5c, %eax\n" /* line 281 */
        "movl $0, 0x28(%eax)\n"
        "addl $4, %esp\n" /* line 282 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 285 */
__attribute__((naked))
int Scr_ScanFile(char *buf, int max_size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 285 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edi\n" /* buf */
        "movl 0xc(%ebp), %esi\n" /* max_size */
        /* { scope 1 */
        "testl %esi, %esi\n" /* line 290 | max_size */
        "jg .Lfaf592_000af5ab\n"
        "xorl %ecx, %ecx\n"
        /* } scope */
        ".Lfaf592_000af5a4:\n"
        "movl %ecx, %eax\n" /* line 310 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfaf592_000af5ab:\n"
        "movl 0x195ee5c, %ebx\n" /* line 290 */
        "movl 0x1c(%ebx), %eax\n"
        "movzbl (%eax), %edx\n"
        "addl $1, %eax\n"
        "movl %eax, 0x1c(%ebx)\n"
        "testb %dl, %dl\n"
        "jne .Lfaf592_000af5df\n"
        "xorl %ecx, %ecx\n"
        ".Lfaf592_000af5c3:\n"
        "testb %dl, %dl\n" /* line 297 */
        "jne .Lfaf592_000af5a4\n"
        ".Lfaf592_000af5c7:\n"
        "movl 0x20(%ebx), %eax\n" /* line 299 */
        "testl %eax, %eax\n"
        "je .Lfaf592_000af622\n"
        "movl %eax, 0x1c(%ebx)\n" /* line 305 */
        "movl $0, 0x20(%ebx)\n" /* line 306 */
        /* } scope */
        "movl %ecx, %eax\n" /* line 310 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfaf592_000af5df:\n"
        "cmpb $0xa, %dl\n" /* line 290 */
        "je .Lfaf592_000af615\n"
        "xorl %ecx, %ecx\n" /* line 293 */
        ".Lfaf592_000af5e6:\n"
        "movb %dl, (%edi, %ecx)\n" /* line 291 | buf */
        "addl $1, %ecx\n" /* line 290 */
        "cmpl %ecx, %esi\n" /* max_size */
        "je .Lfaf592_000af62b\n"
        "movl 0x1c(%ebx), %eax\n"
        "movzbl (%eax), %edx\n"
        "addl $1, %eax\n"
        "movl %eax, 0x1c(%ebx)\n"
        "testb %dl, %dl\n"
        "je .Lfaf592_000af5c7\n"
        "cmpb $0xa, %dl\n"
        "jne .Lfaf592_000af5e6\n"
        "movl %ecx, %eax\n"
        "addl $1, %ecx\n"
        ".Lfaf592_000af60a:\n"
        "movb $0xa, (%eax, %edi)\n" /* line 295 */
        /* } scope */
        ".Lfaf592_000af60e:\n"
        "movl %ecx, %eax\n" /* line 310 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfaf592_000af615:\n"
        "xorl %eax, %eax\n" /* line 290 */
        "movl $1, %ecx\n"
        "movb $0xa, (%eax, %edi)\n" /* line 295 */
        "jmp .Lfaf592_000af60e\n"
        ".Lfaf592_000af622:\n"
        "subl $1, 0x1c(%ebx)\n" /* line 301 */
        "jmp .Lfaf592_000af5a4\n"
        ".Lfaf592_000af62b:\n"
        "cmpb $0xa, %dl\n" /* line 293 */
        "jne .Lfaf592_000af5c3\n"
        "movl %ecx, %eax\n" /* line 290 */
        "addl $1, %ecx\n"
        "jmp .Lfaf592_000af60a\n"
    );
}

/* line 313 */
__attribute__((naked))
unsigned int Scr_LoadScript(const char *filename)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 313 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 331 | filename */
        "movl %eax, (%esp)\n"
        "calll Scr_CreateCanonicalFilename\n"
        "movl %eax, %esi\n" /* fileId */
        "movl %eax, 4(%esp)\n" /* line 332 */
        "movl 0x195ee5c, %edi\n"
        "movl 8(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "testl %eax, %eax\n"
        "je .Lfaf638_000af692\n"
        "movl %esi, (%esp)\n" /* line 334 | fileId */
        "calll SL_RemoveRefToString\n"
        "movl %esi, 4(%esp)\n" /* line 335 | fileId */
        "movl 0xc(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "testl %eax, %eax\n" /* line 336 */
        "jne .Lfaf638_000af7a0\n"
        ".Lfaf638_000af686:\n"
        "xorl %esi, %esi\n" /* line 366 | fileId */
        /* } scope */
        "movl %esi, %eax\n" /* line 371 | fileId */
        "addl $0x7c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfaf638_000af692:\n"
        "movl %esi, 4(%esp)\n" /* line 339 | fileId */
        "movl 8(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetNewVariable\n"
        "movl %eax, -0x6c(%ebp)\n" /* scriptId */
        "movl %esi, (%esp)\n" /* line 340 | fileId */
        "calll SL_RemoveRefToString\n"
        "movl %esi, (%esp)\n" /* line 342 | fileId */
        "calll SL_ConvertToString\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0x21e988, 8(%esp)\n" /* "%s.gsc" */
        "movl $0x40, 4(%esp)\n"
        "leal -0x5c(%ebp), %eax\n" /* extFilename */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 0x195ee64, %edx\n" /* line 344 */
        "movl 0xc(%edx), %edx\n"
        "movl %edx, -0x70(%ebp)\n" /* oldSourceBuf */
        "movl $0, (%esp)\n" /* line 346 */
        "calll TempMalloc\n"
        "movl %eax, %ebx\n" /* oldFilename */
        "movl %esi, (%esp)\n" /* fileId */
        "calll SL_ConvertToString\n"
        "movl $1, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* oldFilename */
        "leal -0x5c(%ebp), %ecx\n" /* extFilename */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Scr_AddSourceBuffer\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 347 */
        "je .Lfaf638_000af686\n"
        "movl 0x195ee54, %eax\n" /* line 350 */
        "movl $0, 8(%eax)\n"
        "movl $0, 4(%edi)\n" /* line 351 */
        "movl 0x195ee64, %eax\n" /* line 353 */
        "movl 8(%eax), %ebx\n" /* oldFilename */
        "leal -0x5c(%ebp), %ecx\n" /* line 354 | extFilename */
        "movl %ecx, 8(%eax)\n"
        "movl $0x21e990, 0x1c(%edi)\n" /* line 356 */
        "movl %edx, 0x20(%edi)\n" /* line 357 */
        "movl $0, 4(%esp)\n" /* line 358 */
        "leal -0x1c(%ebp), %eax\n" /* parseData */
        "movl %eax, (%esp)\n"
        "calll ScriptParse\n"
        "movl %esi, 4(%esp)\n" /* line 359 | fileId */
        "movl 0xc(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetVariable\n"
        "movl %eax, (%esp)\n"
        "calll GetObjectA\n"
        "movl %eax, %esi\n" /* fileId */
        "movl -0x6c(%ebp), %eax\n" /* line 360 | scriptId */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* fileId */
        "movl -0x1c(%ebp), %eax\n" /* parseData */
        "movl %eax, (%esp)\n"
        "calll ScriptCompile\n"
        "movl 0x195ee64, %edx\n" /* line 362 */
        "movl %ebx, 8(%edx)\n" /* oldFilename */
        "movl -0x70(%ebp), %ecx\n" /* line 363 | oldSourceBuf */
        "movl %ecx, 0xc(%edx)\n"
        /* } scope */
        "movl %esi, %eax\n" /* line 371 | fileId */
        "addl $0x7c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfaf638_000af7a0:\n"
        "movl %eax, (%esp)\n" /* line 336 */
        "calll FindObject\n"
        "movl %eax, %esi\n" /* fileId */
        /* } scope */
        "movl %esi, %eax\n" /* line 371 | fileId */
        "addl $0x7c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 374 */
__attribute__((naked))
inflate_blocks_statef Scr_PostCompileScripts(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 374 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 380 */
        "jmp Hunk_ConvertTempToPermLowInternal\n" /* line 378 */
    );
}

/* line 383 */
__attribute__((naked))
inflate_blocks_statef Scr_EndLoadScripts(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 383 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0x195ee5c, %ebx\n" /* line 133 */
        "movl $0, 0x18(%ebx)\n"
        "movl 0x195ee58, %eax\n" /* line 134 */
        "movl 4(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_ClearToMark\n"
        "movl $2, (%esp)\n" /* line 394 */
        "calll SL_ShutdownSystem\n"
        "movb $0, 0x24(%ebx)\n" /* line 401 */
        "movl 8(%ebx), %eax\n" /* line 404 */
        "movl %eax, (%esp)\n"
        "calll ClearObject\n"
        "movl 8(%ebx), %eax\n" /* line 408 */
        "movl %eax, (%esp)\n"
        "calll RemoveRefToObject\n"
        "movl $0, 8(%ebx)\n" /* line 409 */
        "movl 0xc(%ebx), %eax\n" /* line 417 */
        "movl %eax, (%esp)\n"
        "calll ClearObject\n"
        "movl 0xc(%ebx), %eax\n" /* line 421 */
        "movl %eax, (%esp)\n"
        "calll RemoveRefToObject\n"
        "movl $0, 0xc(%ebx)\n" /* line 422 */
        "movl 0x10(%ebx), %eax\n" /* line 425 */
        "movl %eax, (%esp)\n"
        "calll ClearObject\n"
        "movl 0x10(%ebx), %eax\n" /* line 429 */
        "movl %eax, (%esp)\n"
        "calll RemoveRefToObject\n"
        "movl $0, 0x10(%ebx)\n" /* line 430 */
        "movl 0x14(%ebx), %eax\n" /* line 433 */
        "movl %eax, (%esp)\n"
        "calll ClearObject\n"
        "movl 0x14(%ebx), %eax\n" /* line 437 */
        "movl %eax, (%esp)\n"
        "calll RemoveRefToObject\n"
        "movl $0, 0x14(%ebx)\n" /* line 438 */
        "addl $0x14, %esp\n" /* line 439 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 444 */
__attribute__((naked))
inflate_blocks_statef Scr_PrecacheAnimTrees(Alloc_t Alloc, int user)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 444 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* user */
        /* { scope 1 */
        "movl 0x195ee54, %eax\n" /* line 448 */
        "movl 0x40c(%eax, %esi, 4), %edx\n"
        "testl %edx, %edx\n"
        "jg .Lfaf86c_000af890\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 450 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfaf86c_000af890:\n"
        "movl $1, %ebx\n" /* line 448 | i */
        "movl %eax, %edi\n"
        ".Lfaf86c_000af897:\n"
        "movl %esi, 8(%esp)\n" /* line 449 | user */
        "movl 8(%ebp), %eax\n" /* Alloc */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* i */
        "calll Scr_LoadAnimTreeAtIndex\n"
        "addl $1, %ebx\n" /* line 448 | i */
        "cmpl %ebx, 0x40c(%edi, %esi, 4)\n" /* i */
        "jge .Lfaf86c_000af897\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 450 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 453 */
__attribute__((naked))
inflate_blocks_statef Scr_EndLoadAnimTrees(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 453 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0x195ee54, %ebx\n" /* line 456 */
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll ClearObject\n"
        "movl (%ebx), %eax\n" /* line 460 */
        "movl %eax, (%esp)\n"
        "calll RemoveRefToObject\n"
        "movl $0, (%ebx)\n" /* line 461 */
        "movl 4(%ebx), %eax\n" /* line 463 */
        "testl %eax, %eax\n"
        "je .Lfaf8be_000af8f4\n"
        "movl %eax, (%esp)\n" /* line 464 */
        "calll RemoveRefToObject\n"
        ".Lfaf8be_000af8f4:\n"
        "movl $2, (%esp)\n" /* line 466 */
        "calll SL_ShutdownSystem\n"
        "movl $0, (%esp)\n" /* line 468 */
        "calll Hunk_AllocLowInternal\n"
        "movl 0x195ee58, %edx\n"
        "movl %eax, 0x4c(%edx)\n"
        "movb $0, 0x418(%ebx)\n" /* line 470 */
        "addl $0x14, %esp\n" /* line 475 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 478 */
__attribute__((naked))
inflate_blocks_statef Scr_FreeScripts(int sys)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 478 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0x195ee5c, %ebx\n" /* line 484 */
        "cmpb $0, 0x24(%ebx)\n"
        "jne .Lfaf922_000af987\n"
        ".Lfaf922_000af935:\n"
        "movl 0x195ee54, %eax\n" /* line 490 */
        "cmpb $0, 0x418(%eax)\n"
        "je .Lfaf922_000af94f\n"
        "movb $0, 0x418(%eax)\n" /* line 492 */
        "calll Scr_EndLoadAnimTrees\n" /* line 493 */
        ".Lfaf922_000af94f:\n"
        "movl $1, (%esp)\n" /* line 502 */
        "calll SL_ShutdownSystem\n"
        "calll Scr_ShutdownOpcodeLookup\n" /* line 503 */
        "movl 0x195ee58, %eax\n" /* line 505 */
        "movl $0, 0x48(%eax)\n"
        "movl $0, 0x30(%ebx)\n" /* line 506 */
        "movl $0, 0x4c(%eax)\n" /* line 507 */
        "movl $0, 0x3c(%eax)\n" /* line 508 */
        "addl $0x14, %esp\n" /* line 509 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfaf922_000af987:\n"
        "movb $0, 0x24(%ebx)\n" /* line 486 */
        "calll Scr_EndLoadScripts\n" /* line 487 */
        "jmp .Lfaf922_000af935\n"
    );
}

/* line 67 */
__attribute__((naked))
scr_func_t Scr_GetFunctionHandle(const char *filename, const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 67 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 83 | filename */
        "movl %eax, (%esp)\n"
        "calll Scr_CreateCanonicalFilename\n"
        "movl %eax, %ebx\n" /* name2 */
        "movl %eax, 4(%esp)\n" /* line 84 */
        "movl 0x195ee5c, %edi\n"
        "movl 0xc(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "movl %eax, %esi\n" /* fileId */
        "movl %ebx, (%esp)\n" /* line 85 | name2 */
        "calll SL_RemoveRefToString\n"
        "testl %esi, %esi\n" /* line 87 | fileId */
        "jne .Lfaf992_000af9d5\n"
        ".Lfaf992_000af9cb:\n"
        "xorl %eax, %eax\n" /* line 113 */
        /* } scope */
        ".Lfaf992_000af9cd:\n"
        "addl $0x1c, %esp\n" /* line 119 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfaf992_000af9d5:\n"
        "movl %esi, (%esp)\n" /* line 90 | fileId */
        "calll FindObject\n"
        "movl %eax, %ebx\n" /* name2 */
        "movl 0xc(%ebp), %eax\n" /* line 93 | name */
        "movl %eax, (%esp)\n"
        "calll SL_FindLowercaseString\n"
        "testl %eax, %eax\n" /* line 94 */
        "je .Lfaf992_000af9cb\n"
        "movl %eax, 4(%esp)\n" /* line 96 */
        "movl %ebx, (%esp)\n" /* name2 */
        "calll FindVariable\n"
        "movl %eax, %ebx\n" /* name2 */
        "testl %eax, %eax\n" /* line 97 */
        "je .Lfaf992_000af9cb\n"
        "movl %eax, (%esp)\n" /* line 99 */
        "calll GetVarType\n"
        "subl $1, %eax\n"
        "jne .Lfaf992_000af9cb\n"
        "movl %ebx, (%esp)\n" /* line 102 | name2 */
        "calll FindObject\n"
        "movl $1, 4(%esp)\n" /* line 105 */
        "movl %eax, (%esp)\n"
        "calll FindVariable\n"
        "movl %eax, (%esp)\n" /* line 108 */
        "calll Scr_EvalVariable\n"
        "movl 0x195ee58, %ecx\n" /* line 27 */
        "subl 0x48(%ecx), %eax\n"
        "cmpl 0x30(%edi), %eax\n" /* line 113 */
        "jae .Lfaf992_000af9cb\n"
        "jmp .Lfaf992_000af9cd\n"
    );
}

/* line 165 */
__attribute__((naked))
inflate_blocks_statef Scr_BeginLoadScripts(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 165 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0x195ee5c, %esi\n" /* line 172 */
        "movb $1, 0x24(%esi)\n"
        "calll Scr_InitOpcodeLookup\n" /* line 174 */
        "calll Scr_AllocArray\n" /* line 180 */
        "movl %eax, 8(%esi)\n"
        "calll Scr_AllocArray\n" /* line 199 */
        "movl %eax, 0xc(%esi)\n"
        "calll Scr_AllocArray\n" /* line 205 */
        "movl %eax, 0x10(%esi)\n"
        "calll Scr_AllocArray\n" /* line 211 */
        "movl %eax, 0x14(%esi)\n"
        "movl $0, (%esp)\n" /* line 216 */
        "calll Hunk_AllocLowInternal\n"
        "movl 0x195ee58, %ebx\n"
        "movl %eax, 0x48(%ebx)\n"
        "movl $0, 0x30(%esi)\n" /* line 217 */
        "movl $0, 0x4c(%ebx)\n" /* line 219 */
        "calll Hunk_SetMark\n" /* line 124 */
        "movl %eax, 4(%ebx)\n"
        "movl $0x20000, (%esp)\n" /* line 126 */
        "calll Hunk_AllocInternal\n"
        "movl %eax, 0x18(%esi)\n"
        "movw $0, 8(%ebx)\n" /* line 127 */
        "movl $0, (%ebx)\n" /* line 227 */
        "movl $0, (%esi)\n" /* line 229 */
        "calll Scr_ClearErrorMessage\n" /* line 231 */
        "movl $0, 0x34(%esi)\n" /* line 233 */
        "movl 0x195ee54, %ebx\n" /* line 268 */
        "movb $1, 0x418(%ebx)\n"
        "movl $0, 0x410(%ebx)\n" /* line 270 */
        "movl $0, 0x20c(%ebx)\n" /* line 271 */
        "calll Scr_AllocArray\n" /* line 274 */
        "movl %eax, (%ebx)\n"
        "movl $0, 4(%ebx)\n" /* line 279 */
        "movl $0, 0x28(%esi)\n" /* line 281 */
        "addl $0x10, %esp\n" /* line 239 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp TempMemoryReset\n" /* line 238 */
    );
}

/* line 154 */
__attribute__((naked))
unsigned int SL_GetCanonicalString(const char *str)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 154 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* str */
        /* { scope 1 */
        "movl 0x195ee5c, %edi\n" /* line 158 */
        "movl 0x18(%edi), %ebx\n"
        "movl %esi, (%esp)\n" /* str */
        "calll SL_FindString\n"
        "movzwl (%ebx, %eax, 2), %eax\n"
        "movzwl %ax, %edx\n"
        "testw %ax, %ax\n" /* line 159 */
        "je .Lfafb0e_000afb41\n"
        /* } scope */
        ".Lfafb0e_000afb37:\n"
        "movl %edx, %eax\n" /* line 162 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfafb0e_000afb41:\n"
        "movl $0xf, 8(%esp)\n" /* line 161 */
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* str */
        "calll SL_GetString_\n"
        "movl %eax, %ebx\n" /* stringValue */
        /* { scope 2 */
        "movl $2, 4(%esp)\n" /* line 144 */
        "movl %eax, (%esp)\n"
        "calll SL_TransferRefToUser\n"
        "movl 0x18(%edi), %eax\n" /* line 145 */
        "leal (%eax, %ebx, 2), %ecx\n"
        "movzwl (%ecx), %eax\n"
        "movzwl %ax, %edx\n"
        "testw %ax, %ax\n" /* line 146 */
        "jne .Lfafb0e_000afb37\n"
        "movl 0x195ee58, %eax\n" /* line 148 */
        "movzwl 8(%eax), %edx\n"
        "addl $1, %edx\n"
        "movw %dx, 8(%eax)\n"
        "movw %dx, (%ecx)\n" /* line 149 */
        "movzwl 8(%eax), %edx\n" /* line 150 */
        /* } scope */
        /* } scope */
        "movl %edx, %eax\n" /* line 162 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

