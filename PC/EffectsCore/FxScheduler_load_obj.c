/* ASM dump from: FxScheduler_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/EffectsCore/FxScheduler_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/EffectsCore/GenericParser2.h"
 */

extern FxScheduler *theFxScheduler; /* 0x0 */
extern EffectTemplate *defaultEffect; /* 0x0 */

float FX_CleanTemplate(EffectTemplate *fx);
float FX_CreateDefaultEffect(void);
float MediaHandles_Shutdown(const MediaHandles * _this);
float MediaHandles_AddHandle(const MediaHandles * _this, TMediaElement item);
EffectTemplate * FX_ParseEffect(GenericParser2 *parser, const char *name);
EffectTemplate * FX_RegisterEffect(const char *fileName);
float MediaHandles_AddEffect(const MediaHandles * _this, EffectTemplate *fx);

/* line 51 */
__attribute__((naked))
float FX_CleanTemplate(EffectTemplate *fx)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 51 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* fx */
        /* { scope 1 */
        "movl 4(%edi), %eax\n" /* line 55 | fx */
        "testl %eax, %eax\n"
        "jg .Lf5d840_0005d85b\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 67 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5d840_0005d85b:\n"
        "movl %edi, %ebx\n" /* line 55 | fx */
        "xorl %esi, %esi\n" /* j */
        ".Lf5d840_0005d85f:\n"
        "movl 8(%ebx), %eax\n" /* line 57 */
        "movl %eax, (%esp)\n"
        "calll PrimitiveTemplate_Shutdown\n"
        "addl $1, %esi\n" /* line 55 | j */
        "addl $4, %ebx\n"
        "cmpl %esi, 4(%edi)\n" /* j, fx */
        "jg .Lf5d840_0005d85f\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 67 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 108 */
__attribute__((naked))
float FX_CreateDefaultEffect(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 108 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x219d68, (%esp)\n" /* line 111 */
        "calll FX_TryRegisterEffect\n"
        "movl %eax, defaultEffect\n"
        "testl %eax, %eax\n" /* line 112 */
        "je .Lf5d87e_0005d89b\n"
        "leave\n" /* line 115 */
        "retl\n"
        ".Lf5d87e_0005d89b:\n"
        "movl $0x219d68, 8(%esp)\n" /* line 113 */
        "movl $0x219d78, 4(%esp)\n" /* "^1ERROR: could not load default effect file '%s'" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "leave\n" /* line 115 */
        "retl\n"
    );
}

/* line 620 */
__attribute__((naked))
float MediaHandles_Shutdown(const MediaHandles * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 620 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl (%ebx), %eax\n" /* line 622 | this */
        "testl %eax, %eax\n"
        "je .Lf5d8ba_0005d8e4\n"
        "movl %eax, (%esp)\n" /* line 624 */
        "calll Z_FreeInternal\n"
        "movl $0, (%ebx)\n" /* line 625 | this */
        "movw $0, 4(%ebx)\n" /* line 626 | this */
        "movw $0, 6(%ebx)\n" /* line 627 | this */
        ".Lf5d8ba_0005d8e4:\n"
        "addl $0x14, %esp\n" /* line 628 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 631 */
__attribute__((naked))
float MediaHandles_AddHandle(const MediaHandles * _this, TMediaElement item)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 631 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1 */
        "movzwl 4(%ebx), %eax\n" /* line 636 | this */
        "cmpw 6(%ebx), %ax\n" /* this */
        "je .Lf5d8ea_0005d917\n"
        "movl (%ebx), %edx\n" /* this */
        "movzwl 4(%ebx), %ecx\n" /* line 651 | this */
        "movl 0xc(%ebp), %eax\n" /* item */
        "movl %eax, (%edx, %ecx, 4)\n"
        "addw $1, 4(%ebx)\n" /* line 652 | this */
        /* } scope */
        "addl $0x10, %esp\n" /* line 653 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5d8ea_0005d917:\n"
        "testw %ax, %ax\n" /* line 638 */
        "je .Lf5d8ea_0005d977\n"
        "movzwl %ax, %eax\n" /* line 639 */
        "addl %eax, %eax\n"
        "movw %ax, 6(%ebx)\n" /* this */
        ".Lf5d8ea_0005d925:\n"
        "movzwl 6(%ebx), %eax\n" /* line 643 | this */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, %esi\n" /* newElements */
        "movl (%ebx), %edx\n" /* line 644 | this */
        "testl %edx, %edx\n"
        "je .Lf5d8ea_0005d95d\n"
        "movzwl 4(%ebx), %eax\n" /* line 646 | this */
        "shll $2, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* newElements */
        "calll memcpy\n"
        "movl (%ebx), %eax\n" /* line 647 | this */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        ".Lf5d8ea_0005d95d:\n"
        "movl %esi, (%ebx)\n" /* line 649 | newElements, this */
        "movl %esi, %edx\n" /* newElements */
        "movzwl 4(%ebx), %ecx\n" /* line 651 | this */
        "movl 0xc(%ebp), %eax\n" /* item */
        "movl %eax, (%edx, %ecx, 4)\n"
        "addw $1, 4(%ebx)\n" /* line 652 | this */
        /* } scope */
        "addl $0x10, %esp\n" /* line 653 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5d8ea_0005d977:\n"
        "movw $4, 6(%ebx)\n" /* line 641 | this */
        "jmp .Lf5d8ea_0005d925\n"
    );
}

/* line 522 */
__attribute__((naked))
EffectTemplate * FX_ParseEffect(GenericParser2 *parser, const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 522 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 8(%ebp), %esi\n" /* parser */
        /* { scope 1: fileHandle, fileName, bufParse */
        /* { scope 2 */
        "movl 0xc(%ebp), %eax\n" /* line 82 | name */
        "movl %eax, 8(%esp)\n"
        "movl $0x219dac, 4(%esp)\n" /* "fx/%s.efx" */
        "leal -0x60(%ebp), %ebx\n" /* fileName */
        "movl %ebx, (%esp)\n"
        "calll sprintf\n"
        "movl $0, 8(%esp)\n" /* line 84 */
        "leal -0x1c(%ebp), %eax\n" /* fileHandle */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FS_FOpenFileByMode\n"
        "movl %eax, %edi\n" /* fileLength */
        "testl %eax, %eax\n" /* line 85 */
        "js .Lf5d980_0005dcc6\n"
        "leal 1(%eax), %eax\n" /* line 91 */
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocateTempMemoryInternal\n"
        "movl %eax, %ebx\n"
        "movl -0x1c(%ebp), %eax\n" /* line 93 | fileHandle */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* fileLength */
        "movl %ebx, (%esp)\n"
        "calll FS_Read\n"
        "movl -0x1c(%ebp), %eax\n" /* line 94 | fileHandle */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movb $0, (%ebx, %edi)\n" /* line 96 */
        "movl %ebx, -0x20(%ebp)\n" /* line 97 | bufParse */
        "movl $0, 0xc(%esp)\n" /* line 100 */
        "movl $1, 8(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* bufParse */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* j */
        "calll GenericParser2_Parse\n"
        "movl %ebx, (%esp)\n" /* line 102 */
        "calll Hunk_FreeTempMemory\n"
        /* } scope */
        "movl $4, 4(%esp)\n" /* line 38 */
        "movl $0x68, (%esp)\n"
        "calll Hunk_AllocAlignInternal\n"
        "movl %eax, -0x70(%ebp)\n" /* effect */
        "movl $4, 4(%esp)\n"
        "cld\n" /* line 541 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl 0xc(%ebp), %edi\n" /* name, primitiveGroup */
        "repne scasb %es:(%edi), %al\n" /* primitiveGroup */
        "notl %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll Hunk_AllocAlignInternal\n"
        "movl -0x70(%ebp), %edx\n" /* line 542 | effect */
        "movl %eax, (%edx)\n"
        "movl 0xc(%ebp), %edx\n" /* line 543 | name */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl 0x1c(%esi), %edi\n" /* line 123 | j, fileLength */
        "testl %edi, %edi\n" /* line 549 | primitiveGroup */
        "je .Lf5d980_0005db83\n"
        "movl $0, -0x6c(%ebp)\n" /* currentPrimitiveIndex */
        "jmp .Lf5d980_0005dafa\n"
        ".Lf5d980_0005da7e:\n"
        "movl $1, %esi\n" /* line 554 | type */
        ".Lf5d980_0005da83:\n"
        "movl $4, 4(%esp)\n" /* line 38 */
        "movl $0x2a4, (%esp)\n"
        "calll Hunk_AllocAlignInternal\n"
        "movl %eax, %ebx\n"
        "movl %eax, (%esp)\n" /* line 584 */
        "calll PrimitiveTemplate_Init\n"
        "movl %esi, 0x40(%ebx)\n" /* line 586 | type, grpName */
        "movl -0x6c(%ebp), %eax\n" /* line 588 | currentPrimitiveIndex */
        "movl %eax, 0x44(%ebx)\n" /* grpName */
        "movl %edi, 4(%esp)\n" /* line 590 | primitiveGroup */
        "movl %ebx, (%esp)\n" /* grpName */
        "calll PrimitiveTemplate_ParsePrimitive\n"
        "testb %al, %al\n"
        "je .Lf5d980_0005dbf9\n"
        "movl 0x40(%ebx), %edx\n" /* line 495 */
        "cmpl $1, %edx\n"
        "je .Lf5d980_0005db32\n"
        "cmpl $7, %edx\n"
        "je .Lf5d980_0005db32\n"
        "cmpl $3, %edx\n"
        "je .Lf5d980_0005db32\n"
        /* { scope 2 */
        ".Lf5d980_0005dad0:\n"
        "movl -0x70(%ebp), %edx\n" /* line 174 | effect */
        "movl 4(%edx), %eax\n" /* ct */
        "cmpl $0x17, %eax\n" /* line 176 */
        "jg .Lf5d980_0005db8e\n"
        "movl %ebx, 8(%edx, %eax, 4)\n" /* line 182 */
        "addl $1, %eax\n" /* line 183 */
        "movl %eax, 4(%edx)\n"
        /* } scope */
        ".Lf5d980_0005dae9:\n"
        "movl 4(%edi), %eax\n" /* line 113 | fileLength */
        "movl %eax, %edi\n" /* fileLength */
        "addl $1, -0x6c(%ebp)\n" /* line 613 | currentPrimitiveIndex */
        "testl %eax, %eax\n" /* line 549 */
        "je .Lf5d980_0005db83\n"
        ".Lf5d980_0005dafa:\n"
        "movl (%edi), %ebx\n" /* line 49 */
        "movl $0x219de8, 4(%esp)\n" /* line 554 */
        "movl %ebx, (%esp)\n" /* grpName */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf5d980_0005da7e\n"
        "movl $0x219df4, 4(%esp)\n" /* line 556 */
        "movl %ebx, (%esp)\n" /* grpName */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5d980_0005db9f\n"
        "movl $2, %esi\n" /* type */
        "jmp .Lf5d980_0005da83\n"
        ".Lf5d980_0005db32:\n"
        "movl 0x195ed5c, %eax\n" /* line 475 */
        "cmpb $0, (%eax)\n"
        "je .Lf5d980_0005dad0\n"
        "cmpw $0, 0x6c(%ebx)\n" /* line 483 */
        "jne .Lf5d980_0005dad0\n"
        "movl %edx, 4(%esp)\n" /* line 499 */
        "movl $0x219e90, (%esp)\n" /* "^1FX Error, no materials defined for primitive template of t" */
        "calll FX_Print\n"
        "movl %ebx, (%esp)\n" /* line 601 | grpName */
        "calll PrimitiveTemplate_Shutdown\n"
        /* { scope 2 */
        "movl -0x70(%ebp), %edx\n" /* line 55 | effect */
        "movl 4(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jg .Lf5d980_0005dd00\n"
        /* } scope */
        ".Lf5d980_0005db69:\n"
        "movl 0xc(%ebp), %edx\n" /* line 604 | name */
        "movl %edx, 4(%esp)\n"
        "movl $0x219ed8, (%esp)\n" /* "^1FX Error, invalid primitive template for effect '%s'
" */
        "calll FX_Print\n"
        "movl $0, -0x70(%ebp)\n" /* effect */
        /* } scope */
        ".Lf5d980_0005db83:\n"
        "movl -0x70(%ebp), %eax\n" /* line 617 | effect */
        "addl $0x7c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: fileHandle, fileName, bufParse */
        /* { scope 2 */
        ".Lf5d980_0005db8e:\n"
        "movl $0x219f10, (%esp)\n" /* line 178 */
        "calll FX_Print\n"
        "jmp .Lf5d980_0005dae9\n"
        /* } scope */
        ".Lf5d980_0005db9f:\n"
        "movl $0x219dfc, 4(%esp)\n" /* line 558 */
        "movl %ebx, (%esp)\n" /* grpName */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5d980_0005dbbd\n"
        "movl $3, %esi\n" /* type */
        "jmp .Lf5d980_0005da83\n"
        ".Lf5d980_0005dbbd:\n"
        "movl $0x219e04, 4(%esp)\n" /* line 560 */
        "movl %ebx, (%esp)\n" /* grpName */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5d980_0005dbdb\n"
        "movl $4, %esi\n" /* type */
        "jmp .Lf5d980_0005da83\n"
        ".Lf5d980_0005dbdb:\n"
        "movl $0x219e10, 4(%esp)\n" /* line 562 */
        "movl %ebx, (%esp)\n" /* grpName */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5d980_0005dc4e\n"
        "movl $5, %esi\n" /* type */
        "jmp .Lf5d980_0005da83\n"
        ".Lf5d980_0005dbf9:\n"
        "movl %ebx, (%esp)\n" /* line 592 | grpName */
        "calll PrimitiveTemplate_Shutdown\n"
        /* { scope 2 */
        "movl -0x70(%ebp), %edx\n" /* line 55 | effect */
        "movl 4(%edx), %ebx\n"
        "testl %ebx, %ebx\n"
        "jg .Lf5d980_0005dc2f\n"
        /* } scope */
        ".Lf5d980_0005dc0b:\n"
        "movl (%edi), %eax\n" /* line 595 | primitiveGroup */
        "movl %eax, 4(%esp)\n"
        "movl $0x219e64, (%esp)\n" /* "^1FX Error while parsing segment type '%s'
" */
        "calll FX_Print\n"
        "movl $0, -0x70(%ebp)\n" /* effect */
        /* } scope */
        "movl -0x70(%ebp), %eax\n" /* line 617 | effect */
        "addl $0x7c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: fileHandle, fileName, bufParse */
        /* { scope 2 */
        ".Lf5d980_0005dc2f:\n"
        "movl %edx, %ebx\n" /* line 55 */
        "xorl %esi, %esi\n" /* j */
        ".Lf5d980_0005dc33:\n"
        "movl 8(%ebx), %eax\n" /* line 57 */
        "movl %eax, (%esp)\n"
        "calll PrimitiveTemplate_Shutdown\n"
        "addl $1, %esi\n" /* line 55 | j */
        "addl $4, %ebx\n"
        "movl -0x70(%ebp), %eax\n" /* effect */
        "cmpl 4(%eax), %esi\n" /* j */
        "jl .Lf5d980_0005dc33\n"
        "jmp .Lf5d980_0005dc0b\n"
        /* } scope */
        ".Lf5d980_0005dc4e:\n"
        "movl $0x219e18, 4(%esp)\n" /* line 564 */
        "movl %ebx, (%esp)\n" /* grpName */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5d980_0005dc6c\n"
        "movl $6, %esi\n" /* type */
        "jmp .Lf5d980_0005da83\n"
        ".Lf5d980_0005dc6c:\n"
        "movl $0x219e20, 4(%esp)\n" /* line 566 */
        "movl %ebx, (%esp)\n" /* grpName */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5d980_0005dc8a\n"
        "movl $7, %esi\n" /* type */
        "jmp .Lf5d980_0005da83\n"
        ".Lf5d980_0005dc8a:\n"
        "movl $0x219e34, 4(%esp)\n" /* line 568 */
        "movl %ebx, (%esp)\n" /* grpName */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5d980_0005dca8\n"
        "movl $8, %esi\n" /* type */
        "jmp .Lf5d980_0005da83\n"
        ".Lf5d980_0005dca8:\n"
        "movl $0x219e40, 4(%esp)\n" /* line 570 */
        "movl %ebx, (%esp)\n" /* grpName */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5d980_0005dce2\n"
        "movl $9, %esi\n" /* type */
        "jmp .Lf5d980_0005da83\n"
        /* { scope 2 */
        ".Lf5d980_0005dcc6:\n"
        "movl %ebx, 4(%esp)\n" /* line 87 */
        "movl $0x219db8, (%esp)\n" /* "Effect file load failed: %s: file not found
" */
        "calll FX_Print\n"
        /* } scope */
        "movl $0, -0x70(%ebp)\n" /* line 549 | effect */
        "jmp .Lf5d980_0005db83\n"
        ".Lf5d980_0005dce2:\n"
        "movl $0x219e48, 4(%esp)\n" /* line 572 */
        "movl %ebx, (%esp)\n" /* grpName */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5d980_0005dd22\n"
        "movl $0xa, %esi\n" /* type */
        "jmp .Lf5d980_0005da83\n"
        /* { scope 2 */
        ".Lf5d980_0005dd00:\n"
        "movl %edx, %ebx\n" /* line 55 */
        "xorl %esi, %esi\n" /* j */
        ".Lf5d980_0005dd04:\n"
        "movl 8(%ebx), %eax\n" /* line 57 */
        "movl %eax, (%esp)\n"
        "calll PrimitiveTemplate_Shutdown\n"
        "addl $1, %esi\n" /* line 55 | j */
        "addl $4, %ebx\n"
        "movl -0x70(%ebp), %eax\n" /* effect */
        "cmpl 4(%eax), %esi\n" /* j */
        "jl .Lf5d980_0005dd04\n"
        "jmp .Lf5d980_0005db69\n"
        /* } scope */
        ".Lf5d980_0005dd22:\n"
        "movl $0x219e54, 4(%esp)\n" /* line 574 */
        "movl %ebx, (%esp)\n" /* grpName */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5d980_0005dd40\n"
        "movl $0xb, %esi\n" /* type */
        "jmp .Lf5d980_0005da83\n"
        ".Lf5d980_0005dd40:\n"
        "movl $0x219e5c, 4(%esp)\n" /* line 576 */
        "movl %ebx, (%esp)\n" /* grpName */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5d980_0005dae9\n"
        "movl $0xc, %esi\n" /* type */
        "jmp .Lf5d980_0005da83\n"
    );
}

/* line 129 */
__attribute__((naked))
EffectTemplate * FX_RegisterEffect(const char *fileName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 129 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x50, %esp\n"
        "movl 8(%ebp), %esi\n" /* fileName */
        /* { scope 1 */
        "movzbl (%esi), %eax\n" /* line 139 | fileName */
        "cmpb $0x2f, %al\n"
        "je .Lf5dd62_0005dddd\n"
        "cmpb $0x5c, %al\n"
        "je .Lf5dd62_0005dddd\n"
        ".Lf5dd62_0005dd78:\n"
        "movl $3, 8(%esp)\n" /* line 142 */
        "movl $0x219f48, 4(%esp)\n" /* "fx/" */
        "movl %esi, (%esp)\n" /* fileName */
        "calll strnicmp\n"
        "testl %eax, %eax\n"
        "jne .Lf5dd62_0005ddc1\n"
        "leal -0x48(%ebp), %ebx\n" /* line 685 | strippedFileName */
        "movl %ebx, 4(%esp)\n"
        "leal 3(%esi), %eax\n" /* fileName */
        "movl %eax, (%esp)\n"
        "calll Com_StripExtension\n"
        "movl %ebx, (%esp)\n" /* line 686 */
        "calll strlwr\n"
        "movl %ebx, (%esp)\n" /* line 146 */
        "calll FX_TryRegisterEffect\n"
        "testl %eax, %eax\n" /* line 149 */
        "je .Lf5dd62_0005ddd1\n"
        /* } scope */
        "addl $0x50, %esp\n" /* line 169 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5dd62_0005ddc1:\n"
        "movl %esi, 4(%esp)\n" /* line 155 | fileName */
        "movl $0x219f4c, (%esp)\n" /* "Effect file '%s' must start with fx/.
" */
        "calll FX_Print\n"
        ".Lf5dd62_0005ddd1:\n"
        "movl defaultEffect, %eax\n" /* line 165 */
        /* } scope */
        "addl $0x50, %esp\n" /* line 169 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5dd62_0005dddd:\n"
        "addl $1, %esi\n" /* line 140 | fileName */
        "jmp .Lf5dd62_0005dd78\n"
    );
}

/* line 657 */
__attribute__((naked))
float MediaHandles_AddEffect(const MediaHandles * _this, EffectTemplate *fx)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 657 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1 */
        "movzwl 4(%ebx), %eax\n" /* line 636 */
        "cmpw 6(%ebx), %ax\n"
        "je .Lf5dde2_0005de0f\n"
        "movl (%ebx), %edx\n"
        "movzwl 4(%ebx), %ecx\n" /* line 651 */
        "movl 0xc(%ebp), %eax\n" /* fx */
        "movl %eax, (%edx, %ecx, 4)\n"
        "addw $1, 4(%ebx)\n" /* line 652 */
        /* } scope */
        "addl $0x10, %esp\n" /* line 663 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5dde2_0005de0f:\n"
        "testw %ax, %ax\n" /* line 638 */
        "je .Lf5dde2_0005de6f\n"
        "movzwl %ax, %eax\n" /* line 639 */
        "addl %eax, %eax\n"
        "movw %ax, 6(%ebx)\n"
        ".Lf5dde2_0005de1d:\n"
        "movzwl 6(%ebx), %eax\n" /* line 643 */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, %esi\n" /* newElements */
        "movl (%ebx), %edx\n" /* line 644 */
        "testl %edx, %edx\n"
        "je .Lf5dde2_0005de55\n"
        "movzwl 4(%ebx), %eax\n" /* line 646 */
        "shll $2, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* newElements */
        "calll memcpy\n"
        "movl (%ebx), %eax\n" /* line 647 */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        ".Lf5dde2_0005de55:\n"
        "movl %esi, (%ebx)\n" /* line 649 | newElements */
        "movl %esi, %edx\n" /* newElements */
        "movzwl 4(%ebx), %ecx\n" /* line 651 */
        "movl 0xc(%ebp), %eax\n" /* fx */
        "movl %eax, (%edx, %ecx, 4)\n"
        "addw $1, 4(%ebx)\n" /* line 652 */
        /* } scope */
        "addl $0x10, %esp\n" /* line 663 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5dde2_0005de6f:\n"
        "movw $4, 6(%ebx)\n" /* line 641 */
        "jmp .Lf5dde2_0005de1d\n"
    );
}

