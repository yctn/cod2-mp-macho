/* ASM dump from: FxArchive.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/EffectsCore/FxArchive.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/memfile.h"
 *   #include "PC/EffectsCore/FxArchive.h"
 */

void FxArchive_FxArchive(const FxArchive * _this);
void FxArchive_BeginReading(const FxArchive * _this, MemoryFile *memFile);
void FxArchive_ReadData(const FxArchive * _this, void *p, int byteCount);
void FxArchive_WriteData(const FxArchive * _this, const void *p, int byteCount, const FxArchive * _this_3, struct XModel *model, const FxArchive * _this_5, const EffectTemplate *fx);
void FxArchive_ArchiveEffect(const FxArchive * _this, const EffectTemplate * *fx);
void FxArchive_ArchiveMaterial(const FxArchive * _this, MaterialHandle *ph);
void FxArchive_ArchiveModel(const FxArchive * _this, struct XModel * *model);
void FxArchive_ArchiveChannelInstance(const FxArchive * _this, FxChannelInstance *channelInstance);
void FxArchive_ArchiveFxBoltInfo(const FxArchive * _this, FxBoltInfo *bolt);
void FxArchive_ArchiveFxGfxEntity(const FxArchive * _this, FxGfxEntity *entity);

/* line 22 */
void FxArchive_FxArchive(const FxArchive * _this)
{
    *(int *)((byte *)_this + 0) = 0;
    *(char *)((byte *)_this + 4) = 0;
    *(char *)((byte *)_this + 5) = 0;
    *(int *)((byte *)_this + 8) = 0;
    *(int *)((byte *)_this + 0x14) = 0;
    *(int *)((byte *)_this + 0xc) = 0;
    *(int *)((byte *)_this + 0x10) = 0;
}

/* line 35 */
void FxArchive_BeginReading(const FxArchive * _this, MemoryFile *memFile)
{
    *(MemoryFile **)((byte *)_this + 0) = memFile;
    *(char *)((byte *)_this + 4) = 1;
    *(char *)((byte *)_this + 5) = 0;
    *(int *)((byte *)_this + 8) = 0;
    *(int *)((byte *)_this + 0x14) = *(int *)((byte *)memFile + 8);
    *(int *)((byte *)_this + 0xc) = 0;
    *(int *)((byte *)_this + 0x10) = 0;
}

/* line 123 */
__attribute__((naked))
void FxArchive_ReadData(const FxArchive * _this, void *p, int byteCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 123 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0x10(%ebp), %ecx\n" /* byteCount */
        /* { scope 1: value */
        "addl %ecx, 8(%esi)\n" /* line 132 | this */
        "movl 0xc(%ebp), %ebx\n" /* line 134 | p, data */
        ".Lfaa504_000aa519:\n"
        "movl 0xc(%esi), %eax\n" /* line 137 | this */
        "testl %eax, %eax\n"
        "jne .Lfaa504_000aa54c\n"
        "xorl %edx, %edx\n"
        ".Lfaa504_000aa522:\n"
        "movl %ecx, %edi\n" /* line 123 | byteCount */
        "subl %edx, %edi\n"
        "movl 0x10(%esi), %eax\n" /* line 145 | this */
        "testl %eax, %eax\n"
        "je .Lfaa504_000aa57f\n"
        "cmpl %edx, %ecx\n"
        "je .Lfaa504_000aa57f\n"
        "subl $1, %eax\n" /* line 147 */
        "movl %eax, 0x10(%esi)\n" /* this */
        "movb $0, (%ebx)\n" /* line 149 | data */
        "addl $1, %ebx\n" /* data */
        "addl $1, %edx\n"
        "cmpl %edx, %ecx\n" /* line 150 */
        "jne .Lfaa504_000aa522\n"
        /* } scope */
        ".Lfaa504_000aa544:\n"
        "addl $0x2c, %esp\n" /* line 177 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: value */
        ".Lfaa504_000aa54c:\n"
        "subl $1, %eax\n" /* line 139 */
        "movl %eax, 0xc(%esi)\n" /* this */
        "leal -1(%ecx), %edi\n" /* line 140 */
        /* { scope 2 */
        "leal -0x19(%ebp), %eax\n" /* line 122 | value */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movzbl -0x19(%ebp), %eax\n" /* line 141 | value */
        "movb %al, (%ebx)\n" /* data */
        "addl $1, %ebx\n" /* data */
        "testl %edi, %edi\n" /* line 142 */
        "je .Lfaa504_000aa544\n"
        "movl %edi, %ecx\n" /* line 143 */
        "jmp .Lfaa504_000aa519\n"
        /* { scope 2 */
        ".Lfaa504_000aa57f:\n"
        "leal -0x19(%ebp), %eax\n" /* line 122 | value */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movzbl -0x19(%ebp), %eax\n" /* line 156 | value */
        "movl %eax, %edx\n"
        "andl $0xc0, %edx\n"
        "cmpl $0x40, %edx\n"
        "je .Lfaa504_000aa5cc\n"
        "cmpl $0x80, %edx\n"
        "je .Lfaa504_000aa5fa\n"
        "testl %edx, %edx\n"
        "je .Lfaa504_000aa5e3\n"
        "andl $0x3f, %eax\n" /* line 172 */
        "addl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n" /* this */
        "movl $0, 0x10(%esi)\n" /* line 173 | this */
        "movl %edi, %ecx\n" /* line 143 */
        "jmp .Lfaa504_000aa519\n"
        ".Lfaa504_000aa5cc:\n"
        "movl $2, 0xc(%esi)\n" /* line 163 | this */
        "andl $0x3f, %eax\n" /* line 164 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n" /* this */
        "movl %edi, %ecx\n" /* line 143 */
        "jmp .Lfaa504_000aa519\n"
        ".Lfaa504_000aa5e3:\n"
        "movl $1, 0xc(%esi)\n" /* line 159 | this */
        "andl $0x3f, %eax\n" /* line 160 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n" /* this */
        "movl %edi, %ecx\n" /* line 143 */
        "jmp .Lfaa504_000aa519\n"
        ".Lfaa504_000aa5fa:\n"
        "movl $4, 0xc(%esi)\n" /* line 167 | this */
        "andl $0x3f, %eax\n" /* line 168 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n" /* this */
        "movl %edi, %ecx\n" /* line 143 */
        "jmp .Lfaa504_000aa519\n"
    );
}

/* line 238 */
__attribute__((naked))
void FxArchive_WriteData(const FxArchive * _this, const void *p, int byteCount, const FxArchive * _this_3, struct XModel *model, const FxArchive * _this_5, const EffectTemplate *fx)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 238 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1: value */
        "movl 0x10(%ebp), %edx\n" /* line 247 | byteCount */
        "movl 8(%ebp), %eax\n" /* this */
        "addl %edx, 8(%eax)\n"
        "movl 0xc(%ebp), %ecx\n" /* line 249 | p */
        "movl %ecx, -0x30(%ebp)\n" /* data */
        "movl (%eax), %edx\n" /* line 250 */
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0x14(%ecx), %eax\n"
        "cmpl 8(%edx), %eax\n"
        "je 0xaa80d\n"
        "movl 0x10(%ebp), %eax\n" /* line 266 | byteCount */
        "testl %eax, %eax\n"
        "jle 0xaa6ac\n"
        "xorl %edi, %edi\n" /* i */
        "movl 8(%ebp), %eax\n" /* line 268 | this */
        "movl (%eax), %esi\n" /* pszModelName */
        "movl (%esi), %eax\n" /* pszModelName */
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0x14(%ecx), %edx\n"
        "movzbl (%eax, %edx), %eax\n"
        "andl $0xc0, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lfaa612_000aa66e\n"
        "cmpl $0x80, %eax\n"
        "je .Lfaa612_000aa66e\n"
        "testl %eax, %eax\n"
        "jne 0xaa6f8\n"
        ".Lfaa612_000aa66e:\n"
        "movl -0x30(%ebp), %ebx\n" /* data */
        "addl %edi, %ebx\n" /* i */
        "jmp 0xaa67a\n"
        "movl 8(%ebp), %eax\n" /* this */
    );
}

/* line 376 */
__attribute__((naked))
void FxArchive_ArchiveEffect(const FxArchive * _this, const EffectTemplate * *fx)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 376 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "cmpb $0, 4(%esi)\n" /* line 378 | this */
        "je .Lfaa8b6_000aa90c\n"
        /* { scope 1: ch, effectName */
        /* { scope 2: b, value */
        "addl $1, 8(%esi)\n" /* line 132 */
        "movl 0xc(%esi), %eax\n"
        ".Lfaa8b6_000aa8d2:\n"
        "testl %eax, %eax\n" /* line 137 */
        "jne .Lfaa8b6_000aaa01\n"
        "movl 0x10(%esi), %eax\n" /* line 145 */
        "testl %eax, %eax\n"
        "je .Lfaa8b6_000aab0f\n"
        "subl $1, %eax\n" /* line 147 */
        "movl %eax, 0x10(%esi)\n"
        "movb $0, -0x19(%ebp)\n" /* line 149 | ch */
        "movzbl -0x19(%ebp), %edx\n" /* ch */
        /* } scope */
        ".Lfaa8b6_000aa8f3:\n"
        "leal -1(%edx), %eax\n" /* line 71 */
        "cmpb $0x3e, %al\n"
        "jbe .Lfaa8b6_000aa971\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "movl 0xc(%ebp), %edx\n" /* line 379 | fx */
        "movl %eax, (%edx)\n"
        ".Lfaa8b6_000aa901:\n"
        "addl $0xbc, %esp\n" /* line 382 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfaa8b6_000aa90c:\n"
        "movl 0xc(%ebp), %edx\n" /* line 381 | fx */
        "movl (%edx), %eax\n" /* fx */
        /* { scope 1: ch, effectName */
        /* { scope 2: b, value */
        "testl %eax, %eax\n" /* line 185 */
        "je .Lfaa8b6_000aaa2e\n"
        "movl (%eax), %eax\n" /* line 186 */
        "movl %eax, -0xb0(%ebp)\n" /* effectName */
        "movl %eax, %edi\n" /* data */
        ".Lfaa8b6_000aa923:\n"
        "cld\n" /* line 190 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* data */
        "notl %ecx\n"
        "leal -1(%ecx), %ebx\n"
        "movb %bl, -0x19(%ebp)\n" /* ch */
        /* { scope 3: value */
        "movl $1, 8(%esp)\n" /* line 123 */
        "leal -0x19(%ebp), %eax\n" /* ch */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 193 */
        "je .Lfaa8b6_000aa966\n"
        "movl %ebx, 8(%esp)\n" /* line 194 */
        "movl -0xb0(%ebp), %eax\n" /* effectName */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        ".Lfaa8b6_000aa966:\n"
        "addl $0xbc, %esp\n" /* line 382 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: ch, effectName */
        ".Lfaa8b6_000aa971:\n"
        "movzbl %dl, %edx\n" /* line 74 */
        "movl %edx, -0xac(%ebp)\n"
        /* { scope 2: b, value */
        /* { scope 3: value */
        "addl %edx, 8(%esi)\n" /* line 132 */
        "leal -0x9a(%ebp), %edi\n" /* line 134 | chEffectName, data */
        "movl %edx, %ecx\n"
        ".Lfaa8b6_000aa985:\n"
        "movl 0xc(%esi), %eax\n" /* line 137 */
        "testl %eax, %eax\n"
        "jne .Lfaa8b6_000aaa43\n"
        "xorl %edx, %edx\n"
        ".Lfaa8b6_000aa992:\n"
        "movl %ecx, %ebx\n" /* line 376 */
        "subl %edx, %ebx\n"
        "movl 0x10(%esi), %eax\n" /* line 145 */
        "testl %eax, %eax\n"
        "je .Lfaa8b6_000aaa7d\n"
        "cmpl %edx, %ecx\n"
        "je .Lfaa8b6_000aaa7d\n"
        "subl $1, %eax\n" /* line 147 */
        "movl %eax, 0x10(%esi)\n"
        "movb $0, (%edi)\n" /* line 149 | data */
        "addl $1, %edi\n" /* data */
        "addl $1, %edx\n"
        "cmpl %edx, %ecx\n" /* line 150 */
        "jne .Lfaa8b6_000aa992\n"
        /* } scope */
        /* } scope */
        ".Lfaa8b6_000aa9bc:\n"
        "movl -0xac(%ebp), %eax\n" /* line 75 */
        "movb $0, -0x9a(%ebp, %eax)\n"
        "leal -0x9a(%ebp), %edx\n" /* line 76 | chEffectName */
        "movl %edx, 0xc(%esp)\n"
        "movl $str_0021e4f0, 8(%esp)\n" /* "fx/%s" */
        "movl $0x40, 4(%esp)\n"
        "leal -0x5a(%ebp), %ebx\n" /* filename */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl %ebx, (%esp)\n" /* line 77 */
        "calll FX_RegisterEffect\n"
        /* } scope */
        "movl 0xc(%ebp), %edx\n" /* line 379 | fx */
        "movl %eax, (%edx)\n"
        "jmp .Lfaa8b6_000aa901\n"
        /* { scope 1: ch, effectName */
        /* { scope 2: b, value */
        ".Lfaa8b6_000aaa01:\n"
        "subl $1, %eax\n" /* line 139 */
        "movl %eax, 0xc(%esi)\n"
        /* { scope 3: value */
        "leal -0x1a(%ebp), %eax\n" /* line 122 | value */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movzbl -0x1a(%ebp), %eax\n" /* line 141 | value */
        "movb %al, -0x19(%ebp)\n" /* ch */
        "movl %eax, %edx\n"
        "jmp .Lfaa8b6_000aa8f3\n"
        /* } scope */
        /* } scope */
        /* { scope 1: ch, effectName */
        /* { scope 2: b, value */
        ".Lfaa8b6_000aaa2e:\n"
        "movl $str_002157b8, -0xb0(%ebp)\n" /* line 185 | effectName */
        "movl -0xb0(%ebp), %edi\n" /* effectName, data */
        "jmp .Lfaa8b6_000aa923\n"
        /* } scope */
        /* } scope */
        /* { scope 1: ch, effectName */
        /* { scope 2: b, value */
        /* { scope 3: value */
        ".Lfaa8b6_000aaa43:\n"
        "subl $1, %eax\n" /* line 139 */
        "movl %eax, 0xc(%esi)\n"
        "leal -1(%ecx), %ebx\n" /* line 140 */
        /* { scope 4 */
        "leal -0x19(%ebp), %eax\n" /* line 122 | ch */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movzbl -0x19(%ebp), %eax\n" /* line 141 | ch */
        "movb %al, (%edi)\n" /* data */
        "addl $1, %edi\n" /* data */
        "testl %ebx, %ebx\n" /* line 142 */
        "je .Lfaa8b6_000aa9bc\n"
        "movl %ebx, %ecx\n"
        "jmp .Lfaa8b6_000aa985\n"
        /* { scope 4 */
        ".Lfaa8b6_000aaa7d:\n"
        "leal -0x19(%ebp), %eax\n" /* line 122 | ch */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movzbl -0x19(%ebp), %eax\n" /* line 156 | ch */
        "movl %eax, %edx\n"
        "andl $0xc0, %edx\n"
        "cmpl $0x40, %edx\n"
        "je .Lfaa8b6_000aaae1\n"
        "cmpl $0x80, %edx\n"
        "je .Lfaa8b6_000aaaf8\n"
        "testl %edx, %edx\n"
        "je .Lfaa8b6_000aaaca\n"
        "andl $0x3f, %eax\n" /* line 172 */
        "addl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "movl $0, 0x10(%esi)\n" /* line 173 */
        "movl %ebx, %ecx\n" /* line 142 */
        "jmp .Lfaa8b6_000aa985\n"
        ".Lfaa8b6_000aaaca:\n"
        "movl $1, 0xc(%esi)\n" /* line 159 */
        "andl $0x3f, %eax\n" /* line 160 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %ebx, %ecx\n" /* line 142 */
        "jmp .Lfaa8b6_000aa985\n"
        ".Lfaa8b6_000aaae1:\n"
        "movl $2, 0xc(%esi)\n" /* line 163 */
        "andl $0x3f, %eax\n" /* line 164 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %ebx, %ecx\n" /* line 142 */
        "jmp .Lfaa8b6_000aa985\n"
        ".Lfaa8b6_000aaaf8:\n"
        "movl $4, 0xc(%esi)\n" /* line 167 */
        "andl $0x3f, %eax\n" /* line 168 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %ebx, %ecx\n" /* line 142 */
        "jmp .Lfaa8b6_000aa985\n"
        /* } scope */
        /* } scope */
        /* { scope 2: b, value */
        /* { scope 3: value */
        ".Lfaa8b6_000aab0f:\n"
        "leal -0x1a(%ebp), %eax\n" /* line 122 | value */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movzbl -0x1a(%ebp), %eax\n" /* line 156 | value */
        "movl %eax, %edx\n"
        "andl $0xc0, %edx\n"
        "cmpl $0x40, %edx\n"
        "je .Lfaa8b6_000aab5d\n"
        "cmpl $0x80, %edx\n"
        "je .Lfaa8b6_000aab8a\n"
        "testl %edx, %edx\n"
        "jne .Lfaa8b6_000aab75\n"
        "movl $1, 0xc(%esi)\n" /* line 159 */
        "andl $0x3f, %eax\n" /* line 160 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0xc(%esi), %eax\n"
        "jmp .Lfaa8b6_000aa8d2\n"
        ".Lfaa8b6_000aab5d:\n"
        "movl $2, 0xc(%esi)\n" /* line 163 */
        "andl $0x3f, %eax\n" /* line 164 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0xc(%esi), %eax\n"
        "jmp .Lfaa8b6_000aa8d2\n"
        ".Lfaa8b6_000aab75:\n"
        "andl $0x3f, %eax\n" /* line 172 */
        "addl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "movl $0, 0x10(%esi)\n" /* line 173 */
        "jmp .Lfaa8b6_000aa8d2\n"
        ".Lfaa8b6_000aab8a:\n"
        "movl $4, 0xc(%esi)\n" /* line 167 */
        "andl $0x3f, %eax\n" /* line 168 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0xc(%esi), %eax\n"
        "jmp .Lfaa8b6_000aa8d2\n"
    );
}

/* line 385 */
__attribute__((naked))
void FxArchive_ArchiveMaterial(const FxArchive * _this, MaterialHandle *ph)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 385 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "cmpb $0, 4(%esi)\n" /* line 387 | this */
        "je .Lfaaba2_000aabf2\n"
        /* { scope 1: ch, materialName */
        /* { scope 2: b */
        "addl $1, 8(%esi)\n" /* line 132 */
        "movl 0xc(%esi), %eax\n"
        ".Lfaaba2_000aabbb:\n"
        "testl %eax, %eax\n" /* line 137 */
        "jne .Lfaaba2_000aacd0\n"
        "movl 0x10(%esi), %eax\n" /* line 145 */
        "testl %eax, %eax\n"
        "je .Lfaaba2_000aadc9\n"
        "subl $1, %eax\n" /* line 147 */
        "movl %eax, 0x10(%esi)\n"
        "movb $0, -0x19(%ebp)\n" /* line 149 | ch */
        "movzbl -0x19(%ebp), %edx\n" /* ch */
        /* } scope */
        ".Lfaaba2_000aabdc:\n"
        "leal -1(%edx), %eax\n" /* line 87 */
        "cmpb $0x3e, %al\n"
        "jbe .Lfaaba2_000aac5f\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "movl 0xc(%ebp), %edx\n" /* line 388 | ph */
        "movl %eax, (%edx)\n"
        ".Lfaaba2_000aabea:\n"
        "addl $0x7c, %esp\n" /* line 391 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfaaba2_000aabf2:\n"
        "movl 0xc(%ebp), %edx\n" /* line 390 | ph */
        "movl (%edx), %eax\n" /* h */
        /* { scope 1: ch, materialName */
        /* { scope 2: b */
        "testl %eax, %eax\n" /* line 203 */
        "je .Lfaaba2_000aacc1\n"
        "movl %eax, 4(%esp)\n" /* line 204 */
        "movl imp_theFxHelper, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_GetMaterialName\n"
        "movl %eax, -0x70(%ebp)\n" /* materialName */
        "movl %eax, %edi\n" /* data */
        ".Lfaaba2_000aac17:\n"
        "cld\n" /* line 208 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* data */
        "notl %ecx\n"
        "leal -1(%ecx), %ebx\n"
        "movb %bl, -0x1a(%ebp)\n" /* b */
        /* { scope 3: value */
        "movl $1, 8(%esp)\n" /* line 123 */
        "leal -0x1a(%ebp), %eax\n" /* b */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 211 */
        "je .Lfaaba2_000aac57\n"
        "movl %ebx, 8(%esp)\n" /* line 212 */
        "movl -0x70(%ebp), %eax\n" /* materialName */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        ".Lfaaba2_000aac57:\n"
        "addl $0x7c, %esp\n" /* line 391 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: ch, materialName */
        ".Lfaaba2_000aac5f:\n"
        "movzbl %dl, %edx\n" /* line 90 */
        "movl %edx, -0x6c(%ebp)\n"
        /* { scope 2: b */
        /* { scope 3: value */
        "addl %edx, 8(%esi)\n" /* line 132 */
        "leal -0x5a(%ebp), %edi\n" /* line 134 | chMaterialName, data */
        "movl %edx, %ecx\n"
        ".Lfaaba2_000aac6d:\n"
        "movl 0xc(%esi), %eax\n" /* line 137 */
        "testl %eax, %eax\n"
        "jne .Lfaaba2_000aacfd\n"
        "xorl %edx, %edx\n"
        ".Lfaaba2_000aac7a:\n"
        "movl %ecx, %ebx\n" /* line 385 */
        "subl %edx, %ebx\n"
        "movl 0x10(%esi), %eax\n" /* line 145 */
        "testl %eax, %eax\n"
        "je .Lfaaba2_000aad37\n"
        "cmpl %edx, %ecx\n"
        "je .Lfaaba2_000aad37\n"
        "subl $1, %eax\n" /* line 147 */
        "movl %eax, 0x10(%esi)\n"
        "movb $0, (%edi)\n" /* line 149 | data */
        "addl $1, %edi\n" /* data */
        "addl $1, %edx\n"
        "cmpl %edx, %ecx\n" /* line 150 */
        "jne .Lfaaba2_000aac7a\n"
        /* } scope */
        /* } scope */
        ".Lfaaba2_000aaca4:\n"
        "movl -0x6c(%ebp), %eax\n" /* line 91 */
        "movb $0, -0x5a(%ebp, %eax)\n"
        "leal -0x5a(%ebp), %edx\n" /* line 92 | chMaterialName */
        "movl %edx, (%esp)\n"
        "calll FX_RegisterMaterial\n"
        /* } scope */
        "movl 0xc(%ebp), %edx\n" /* line 388 | ph */
        "movl %eax, (%edx)\n"
        "jmp .Lfaaba2_000aabea\n"
        /* { scope 1: ch, materialName */
        /* { scope 2: b */
        ".Lfaaba2_000aacc1:\n"
        "movl $str_002157b8, -0x70(%ebp)\n" /* line 203 | materialName */
        "movl -0x70(%ebp), %edi\n" /* materialName, data */
        "jmp .Lfaaba2_000aac17\n"
        /* } scope */
        /* } scope */
        /* { scope 1: ch, materialName */
        /* { scope 2: b */
        ".Lfaaba2_000aacd0:\n"
        "subl $1, %eax\n" /* line 139 */
        "movl %eax, 0xc(%esi)\n"
        /* { scope 3: value */
        "leal -0x1a(%ebp), %eax\n" /* line 122 | b */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movzbl -0x1a(%ebp), %eax\n" /* line 141 | b */
        "movb %al, -0x19(%ebp)\n" /* ch */
        "movl %eax, %edx\n"
        "jmp .Lfaaba2_000aabdc\n"
        /* } scope */
        /* { scope 2: b */
        /* { scope 3: value */
        ".Lfaaba2_000aacfd:\n"
        "subl $1, %eax\n" /* line 139 */
        "movl %eax, 0xc(%esi)\n"
        "leal -1(%ecx), %ebx\n" /* line 140 */
        /* { scope 4 */
        "leal -0x1a(%ebp), %eax\n" /* line 122 | b */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movzbl -0x1a(%ebp), %eax\n" /* line 141 | b */
        "movb %al, (%edi)\n" /* data */
        "addl $1, %edi\n" /* data */
        "testl %ebx, %ebx\n" /* line 142 */
        "je .Lfaaba2_000aaca4\n"
        "movl %ebx, %ecx\n"
        "jmp .Lfaaba2_000aac6d\n"
        /* { scope 4 */
        ".Lfaaba2_000aad37:\n"
        "leal -0x1a(%ebp), %eax\n" /* line 122 | b */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movzbl -0x1a(%ebp), %eax\n" /* line 156 | b */
        "movl %eax, %edx\n"
        "andl $0xc0, %edx\n"
        "cmpl $0x40, %edx\n"
        "je .Lfaaba2_000aad9b\n"
        "cmpl $0x80, %edx\n"
        "je .Lfaaba2_000aadb2\n"
        "testl %edx, %edx\n"
        "je .Lfaaba2_000aad84\n"
        "andl $0x3f, %eax\n" /* line 172 */
        "addl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "movl $0, 0x10(%esi)\n" /* line 173 */
        "movl %ebx, %ecx\n" /* line 142 */
        "jmp .Lfaaba2_000aac6d\n"
        ".Lfaaba2_000aad84:\n"
        "movl $1, 0xc(%esi)\n" /* line 159 */
        "andl $0x3f, %eax\n" /* line 160 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %ebx, %ecx\n" /* line 142 */
        "jmp .Lfaaba2_000aac6d\n"
        ".Lfaaba2_000aad9b:\n"
        "movl $2, 0xc(%esi)\n" /* line 163 */
        "andl $0x3f, %eax\n" /* line 164 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %ebx, %ecx\n" /* line 142 */
        "jmp .Lfaaba2_000aac6d\n"
        ".Lfaaba2_000aadb2:\n"
        "movl $4, 0xc(%esi)\n" /* line 167 */
        "andl $0x3f, %eax\n" /* line 168 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %ebx, %ecx\n" /* line 142 */
        "jmp .Lfaaba2_000aac6d\n"
        /* } scope */
        /* } scope */
        /* { scope 2: b */
        /* { scope 3: value */
        ".Lfaaba2_000aadc9:\n"
        "leal -0x1a(%ebp), %eax\n" /* line 122 | b */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movzbl -0x1a(%ebp), %eax\n" /* line 156 | b */
        "movl %eax, %edx\n"
        "andl $0xc0, %edx\n"
        "cmpl $0x40, %edx\n"
        "je .Lfaaba2_000aae17\n"
        "cmpl $0x80, %edx\n"
        "je .Lfaaba2_000aae44\n"
        "testl %edx, %edx\n"
        "jne .Lfaaba2_000aae2f\n"
        "movl $1, 0xc(%esi)\n" /* line 159 */
        "andl $0x3f, %eax\n" /* line 160 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0xc(%esi), %eax\n"
        "jmp .Lfaaba2_000aabbb\n"
        ".Lfaaba2_000aae17:\n"
        "movl $2, 0xc(%esi)\n" /* line 163 */
        "andl $0x3f, %eax\n" /* line 164 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0xc(%esi), %eax\n"
        "jmp .Lfaaba2_000aabbb\n"
        ".Lfaaba2_000aae2f:\n"
        "andl $0x3f, %eax\n" /* line 172 */
        "addl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "movl $0, 0x10(%esi)\n" /* line 173 */
        "jmp .Lfaaba2_000aabbb\n"
        ".Lfaaba2_000aae44:\n"
        "movl $4, 0xc(%esi)\n" /* line 167 */
        "andl $0x3f, %eax\n" /* line 168 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0xc(%esi), %eax\n"
        "jmp .Lfaaba2_000aabbb\n"
    );
}

/* line 394 */
__attribute__((naked))
void FxArchive_ArchiveModel(const FxArchive * _this, struct XModel * *model)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 394 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "cmpb $0, 4(%esi)\n" /* line 396 | this */
        "je .Lfaae5c_000aaeac\n"
        /* { scope 1: ch, pszModelName */
        /* { scope 2: b */
        "addl $1, 8(%esi)\n" /* line 132 */
        "movl 0xc(%esi), %eax\n"
        ".Lfaae5c_000aae75:\n"
        "testl %eax, %eax\n" /* line 137 */
        "jne .Lfaae5c_000aaf7f\n"
        "movl 0x10(%esi), %eax\n" /* line 145 */
        "testl %eax, %eax\n"
        "je .Lfaae5c_000ab078\n"
        "subl $1, %eax\n" /* line 147 */
        "movl %eax, 0x10(%esi)\n"
        "movb $0, -0x19(%ebp)\n" /* line 149 | ch */
        "movzbl -0x19(%ebp), %edx\n" /* ch */
        /* } scope */
        ".Lfaae5c_000aae96:\n"
        "leal -1(%edx), %eax\n" /* line 102 */
        "cmpb $0x3e, %al\n"
        "jbe .Lfaae5c_000aaf0e\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "movl 0xc(%ebp), %edx\n" /* line 397 | model */
        "movl %eax, (%edx)\n"
        ".Lfaae5c_000aaea4:\n"
        "addl $0x7c, %esp\n" /* line 400 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfaae5c_000aaeac:\n"
        "movl 0xc(%ebp), %edx\n" /* line 399 | model */
        "movl (%edx), %eax\n" /* model */
        /* { scope 1: ch, pszModelName */
        /* { scope 2: b */
        "testl %eax, %eax\n" /* line 221 */
        "je .Lfaae5c_000aaf70\n"
        "movl %eax, (%esp)\n"
        "calll XModelGetName\n"
        "movl %eax, -0x70(%ebp)\n" /* pszModelName */
        "movl %eax, %edi\n" /* data */
        ".Lfaae5c_000aaec6:\n"
        "cld\n" /* line 222 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* data */
        "notl %ecx\n"
        "leal -1(%ecx), %ebx\n"
        "movb %bl, -0x1a(%ebp)\n" /* b */
        /* { scope 3: value */
        "movl $1, 8(%esp)\n" /* line 123 */
        "leal -0x1a(%ebp), %eax\n" /* b */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 225 */
        "je .Lfaae5c_000aaf06\n"
        "movl %ebx, 8(%esp)\n" /* line 226 */
        "movl -0x70(%ebp), %eax\n" /* pszModelName */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        /* } scope */
        ".Lfaae5c_000aaf06:\n"
        "addl $0x7c, %esp\n" /* line 400 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: ch, pszModelName */
        ".Lfaae5c_000aaf0e:\n"
        "movzbl %dl, %edx\n" /* line 105 */
        "movl %edx, -0x6c(%ebp)\n"
        /* { scope 2: b */
        /* { scope 3: value */
        "addl %edx, 8(%esi)\n" /* line 132 */
        "leal -0x5a(%ebp), %edi\n" /* line 134 | chModelName, data */
        "movl %edx, %ecx\n"
        ".Lfaae5c_000aaf1c:\n"
        "movl 0xc(%esi), %eax\n" /* line 137 */
        "testl %eax, %eax\n"
        "jne .Lfaae5c_000aafac\n"
        "xorl %edx, %edx\n"
        ".Lfaae5c_000aaf29:\n"
        "movl %ecx, %ebx\n" /* line 394 */
        "subl %edx, %ebx\n"
        "movl 0x10(%esi), %eax\n" /* line 145 */
        "testl %eax, %eax\n"
        "je .Lfaae5c_000aafe6\n"
        "cmpl %edx, %ecx\n"
        "je .Lfaae5c_000aafe6\n"
        "subl $1, %eax\n" /* line 147 */
        "movl %eax, 0x10(%esi)\n"
        "movb $0, (%edi)\n" /* line 149 | data */
        "addl $1, %edi\n" /* data */
        "addl $1, %edx\n"
        "cmpl %edx, %ecx\n" /* line 150 */
        "jne .Lfaae5c_000aaf29\n"
        /* } scope */
        /* } scope */
        ".Lfaae5c_000aaf53:\n"
        "movl -0x6c(%ebp), %eax\n" /* line 106 */
        "movb $0, -0x5a(%ebp, %eax)\n"
        "leal -0x5a(%ebp), %edx\n" /* line 107 | chModelName */
        "movl %edx, (%esp)\n"
        "calll FX_ModelRegister\n"
        /* } scope */
        "movl 0xc(%ebp), %edx\n" /* line 397 | model */
        "movl %eax, (%edx)\n"
        "jmp .Lfaae5c_000aaea4\n"
        /* { scope 1: ch, pszModelName */
        /* { scope 2: b */
        ".Lfaae5c_000aaf70:\n"
        "movl $str_002157b8, -0x70(%ebp)\n" /* line 221 | pszModelName */
        "movl -0x70(%ebp), %edi\n" /* pszModelName, data */
        "jmp .Lfaae5c_000aaec6\n"
        /* } scope */
        /* } scope */
        /* { scope 1: ch, pszModelName */
        /* { scope 2: b */
        ".Lfaae5c_000aaf7f:\n"
        "subl $1, %eax\n" /* line 139 */
        "movl %eax, 0xc(%esi)\n"
        /* { scope 3: value */
        "leal -0x1a(%ebp), %eax\n" /* line 122 | b */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movzbl -0x1a(%ebp), %eax\n" /* line 141 | b */
        "movb %al, -0x19(%ebp)\n" /* ch */
        "movl %eax, %edx\n"
        "jmp .Lfaae5c_000aae96\n"
        /* } scope */
        /* { scope 2: b */
        /* { scope 3: value */
        ".Lfaae5c_000aafac:\n"
        "subl $1, %eax\n" /* line 139 */
        "movl %eax, 0xc(%esi)\n"
        "leal -1(%ecx), %ebx\n" /* line 140 */
        /* { scope 4 */
        "leal -0x1a(%ebp), %eax\n" /* line 122 | b */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movzbl -0x1a(%ebp), %eax\n" /* line 141 | b */
        "movb %al, (%edi)\n" /* data */
        "addl $1, %edi\n" /* data */
        "testl %ebx, %ebx\n" /* line 142 */
        "je .Lfaae5c_000aaf53\n"
        "movl %ebx, %ecx\n"
        "jmp .Lfaae5c_000aaf1c\n"
        /* { scope 4 */
        ".Lfaae5c_000aafe6:\n"
        "leal -0x1a(%ebp), %eax\n" /* line 122 | b */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movzbl -0x1a(%ebp), %eax\n" /* line 156 | b */
        "movl %eax, %edx\n"
        "andl $0xc0, %edx\n"
        "cmpl $0x40, %edx\n"
        "je .Lfaae5c_000ab04a\n"
        "cmpl $0x80, %edx\n"
        "je .Lfaae5c_000ab061\n"
        "testl %edx, %edx\n"
        "je .Lfaae5c_000ab033\n"
        "andl $0x3f, %eax\n" /* line 172 */
        "addl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "movl $0, 0x10(%esi)\n" /* line 173 */
        "movl %ebx, %ecx\n" /* line 142 */
        "jmp .Lfaae5c_000aaf1c\n"
        ".Lfaae5c_000ab033:\n"
        "movl $1, 0xc(%esi)\n" /* line 159 */
        "andl $0x3f, %eax\n" /* line 160 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %ebx, %ecx\n" /* line 142 */
        "jmp .Lfaae5c_000aaf1c\n"
        ".Lfaae5c_000ab04a:\n"
        "movl $2, 0xc(%esi)\n" /* line 163 */
        "andl $0x3f, %eax\n" /* line 164 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %ebx, %ecx\n" /* line 142 */
        "jmp .Lfaae5c_000aaf1c\n"
        ".Lfaae5c_000ab061:\n"
        "movl $4, 0xc(%esi)\n" /* line 167 */
        "andl $0x3f, %eax\n" /* line 168 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %ebx, %ecx\n" /* line 142 */
        "jmp .Lfaae5c_000aaf1c\n"
        /* } scope */
        /* } scope */
        /* { scope 2: b */
        /* { scope 3: value */
        ".Lfaae5c_000ab078:\n"
        "leal -0x1a(%ebp), %eax\n" /* line 122 | b */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movzbl -0x1a(%ebp), %eax\n" /* line 156 | b */
        "movl %eax, %edx\n"
        "andl $0xc0, %edx\n"
        "cmpl $0x40, %edx\n"
        "je .Lfaae5c_000ab0c6\n"
        "cmpl $0x80, %edx\n"
        "je .Lfaae5c_000ab0f3\n"
        "testl %edx, %edx\n"
        "jne .Lfaae5c_000ab0de\n"
        "movl $1, 0xc(%esi)\n" /* line 159 */
        "andl $0x3f, %eax\n" /* line 160 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0xc(%esi), %eax\n"
        "jmp .Lfaae5c_000aae75\n"
        ".Lfaae5c_000ab0c6:\n"
        "movl $2, 0xc(%esi)\n" /* line 163 */
        "andl $0x3f, %eax\n" /* line 164 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0xc(%esi), %eax\n"
        "jmp .Lfaae5c_000aae75\n"
        ".Lfaae5c_000ab0de:\n"
        "andl $0x3f, %eax\n" /* line 172 */
        "addl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "movl $0, 0x10(%esi)\n" /* line 173 */
        "jmp .Lfaae5c_000aae75\n"
        ".Lfaae5c_000ab0f3:\n"
        "movl $4, 0xc(%esi)\n" /* line 167 */
        "andl $0x3f, %eax\n" /* line 168 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0xc(%esi), %eax\n"
        "jmp .Lfaae5c_000aae75\n"
    );
}

/* line 403 */
__attribute__((naked))
void FxArchive_ArchiveChannelInstance(const FxArchive * _this, FxChannelInstance *channelInstance)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 403 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "cmpb $0, 4(%ebx)\n" /* line 405 | this */
        "je .Lfab10c_000ab1fa\n"
        "movl 0xc(%ebp), %eax\n" /* line 115 | channelInstance */
        "movl $0, 4(%eax)\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3: value */
        "addl $4, 8(%ebx)\n" /* line 132 */
        "leal -0x20(%ebp), %edi\n" /* line 134 | f, data */
        "movl $4, %ecx\n"
        ".Lfab10c_000ab138:\n"
        "movl 0xc(%ebx), %eax\n" /* line 137 */
        "testl %eax, %eax\n"
        "jne .Lfab10c_000ab17a\n"
        "xorl %edx, %edx\n"
        ".Lfab10c_000ab141:\n"
        "movl %ecx, %esi\n" /* line 403 */
        "subl %edx, %esi\n"
        "movl 0x10(%ebx), %eax\n" /* line 145 */
        "testl %eax, %eax\n"
        "je .Lfab10c_000ab1ad\n"
        "cmpl %edx, %ecx\n"
        "je .Lfab10c_000ab1ad\n"
        "subl $1, %eax\n" /* line 147 */
        "movl %eax, 0x10(%ebx)\n"
        "movb $0, (%edi)\n" /* line 149 | data */
        "addl $1, %edi\n" /* data */
        "addl $1, %edx\n"
        "cmpl %edx, %ecx\n" /* line 150 */
        "jne .Lfab10c_000ab141\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lfab10c_000ab163:\n"
        "movl -0x20(%ebp), %eax\n" /* line 117 | f */
        "movl 0xc(%ebp), %edx\n" /* channelInstance */
        "movl %eax, 8(%edx)\n"
        "movl $0, (%edx)\n" /* line 119 */
        "addl $0x2c, %esp\n" /* line 409 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3: value */
        ".Lfab10c_000ab17a:\n"
        "subl $1, %eax\n" /* line 139 */
        "movl %eax, 0xc(%ebx)\n"
        "leal -1(%ecx), %esi\n" /* line 140 */
        /* { scope 4 */
        "leal -0x19(%ebp), %eax\n" /* line 122 | value */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movzbl -0x19(%ebp), %eax\n" /* line 141 | value */
        "movb %al, (%edi)\n" /* data */
        "addl $1, %edi\n" /* data */
        "testl %esi, %esi\n" /* line 142 */
        "je .Lfab10c_000ab163\n"
        "movl %esi, %ecx\n"
        "jmp .Lfab10c_000ab138\n"
        /* { scope 4 */
        ".Lfab10c_000ab1ad:\n"
        "leal -0x19(%ebp), %eax\n" /* line 122 | value */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movzbl -0x19(%ebp), %eax\n" /* line 156 | value */
        "movl %eax, %edx\n"
        "andl $0xc0, %edx\n"
        "cmpl $0x40, %edx\n"
        "je .Lfab10c_000ab239\n"
        "cmpl $0x80, %edx\n"
        "je .Lfab10c_000ab250\n"
        "testl %edx, %edx\n"
        "je .Lfab10c_000ab222\n"
        "andl $0x3f, %eax\n" /* line 172 */
        "addl $1, %eax\n"
        "movl %eax, 0xc(%ebx)\n"
        "movl $0, 0x10(%ebx)\n" /* line 173 */
        "movl %esi, %ecx\n" /* line 142 */
        "jmp .Lfab10c_000ab138\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lfab10c_000ab1fa:\n"
        "movl 0xc(%ebp), %edx\n" /* line 119 | channelInstance */
        "movl 8(%edx), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* f */
        /* { scope 1 */
        "movl $4, 8(%esp)\n" /* line 144 */
        "leal -0x20(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 409 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3: value */
        ".Lfab10c_000ab222:\n"
        "movl $1, 0xc(%ebx)\n" /* line 159 */
        "andl $0x3f, %eax\n" /* line 160 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%ebx)\n"
        "movl %esi, %ecx\n" /* line 142 */
        "jmp .Lfab10c_000ab138\n"
        ".Lfab10c_000ab239:\n"
        "movl $2, 0xc(%ebx)\n" /* line 163 */
        "andl $0x3f, %eax\n" /* line 164 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%ebx)\n"
        "movl %esi, %ecx\n" /* line 142 */
        "jmp .Lfab10c_000ab138\n"
        ".Lfab10c_000ab250:\n"
        "movl $4, 0xc(%ebx)\n" /* line 167 */
        "andl $0x3f, %eax\n" /* line 168 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%ebx)\n"
        "movl %esi, %ecx\n" /* line 142 */
        "jmp .Lfab10c_000ab138\n"
    );
}

/* line 442 */
__attribute__((naked))
void FxArchive_ArchiveFxBoltInfo(const FxArchive * _this, FxBoltInfo *bolt)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 442 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0xc(%ebp), %ecx\n" /* bolt */
        "cmpb $0, 4(%esi)\n" /* line 444 | this */
        "je .Lfab26a_000ab341\n"
        /* { scope 1 */
        /* { scope 2: value */
        "addl $8, 8(%esi)\n" /* line 132 */
        "movl %ecx, %ebx\n" /* line 134 | data */
        "movl $8, %ecx\n"
        ".Lfab26a_000ab28e:\n"
        "movl 0xc(%esi), %eax\n" /* line 137 */
        "testl %eax, %eax\n"
        "jne .Lfab26a_000ab2c1\n"
        "xorl %edx, %edx\n"
        ".Lfab26a_000ab297:\n"
        "movl %ecx, %edi\n" /* line 442 | bolt */
        "subl %edx, %edi\n"
        "movl 0x10(%esi), %eax\n" /* line 145 */
        "testl %eax, %eax\n"
        "je .Lfab26a_000ab2f4\n"
        "cmpl %edx, %ecx\n"
        "je .Lfab26a_000ab2f4\n"
        "subl $1, %eax\n" /* line 147 */
        "movl %eax, 0x10(%esi)\n"
        "movb $0, (%ebx)\n" /* line 149 | data */
        "addl $1, %ebx\n" /* data */
        "addl $1, %edx\n"
        "cmpl %edx, %ecx\n" /* line 150 */
        "jne .Lfab26a_000ab297\n"
        /* } scope */
        /* } scope */
        ".Lfab26a_000ab2b9:\n"
        "addl $0x2c, %esp\n" /* line 456 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: value */
        ".Lfab26a_000ab2c1:\n"
        "subl $1, %eax\n" /* line 139 */
        "movl %eax, 0xc(%esi)\n"
        "leal -1(%ecx), %edi\n" /* line 140 */
        /* { scope 3 */
        "leal -0x19(%ebp), %eax\n" /* line 122 | value */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movzbl -0x19(%ebp), %eax\n" /* line 141 | value */
        "movb %al, (%ebx)\n" /* data */
        "addl $1, %ebx\n" /* data */
        "testl %edi, %edi\n" /* line 142 */
        "je .Lfab26a_000ab2b9\n"
        "movl %edi, %ecx\n"
        "jmp .Lfab26a_000ab28e\n"
        /* { scope 3 */
        ".Lfab26a_000ab2f4:\n"
        "leal -0x19(%ebp), %eax\n" /* line 122 | value */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movzbl -0x19(%ebp), %eax\n" /* line 156 | value */
        "movl %eax, %edx\n"
        "andl $0xc0, %edx\n"
        "cmpl $0x40, %edx\n"
        "je .Lfab26a_000ab382\n"
        "cmpl $0x80, %edx\n"
        "je .Lfab26a_000ab399\n"
        "testl %edx, %edx\n"
        "je .Lfab26a_000ab36b\n"
        "andl $0x3f, %eax\n" /* line 172 */
        "addl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "movl $0, 0x10(%esi)\n" /* line 173 */
        "movl %edi, %ecx\n" /* line 142 */
        "jmp .Lfab26a_000ab28e\n"
        /* } scope */
        /* } scope */
        /* { scope 1 */
        ".Lfab26a_000ab341:\n"
        "leal -0x24(%ebp), %eax\n" /* line 452 | temp */
        "movl (%ecx), %edx\n"
        "movl %edx, -0x24(%ebp)\n" /* temp */
        "movl 4(%ecx), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl $8, 8(%esp)\n" /* line 454 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* this */
        "calll FxArchive_WriteData\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 456 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: value */
        ".Lfab26a_000ab36b:\n"
        "movl $1, 0xc(%esi)\n" /* line 159 */
        "andl $0x3f, %eax\n" /* line 160 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %edi, %ecx\n" /* line 142 */
        "jmp .Lfab26a_000ab28e\n"
        ".Lfab26a_000ab382:\n"
        "movl $2, 0xc(%esi)\n" /* line 163 */
        "andl $0x3f, %eax\n" /* line 164 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %edi, %ecx\n" /* line 142 */
        "jmp .Lfab26a_000ab28e\n"
        ".Lfab26a_000ab399:\n"
        "movl $4, 0xc(%esi)\n" /* line 167 */
        "andl $0x3f, %eax\n" /* line 168 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %edi, %ecx\n" /* line 142 */
        "jmp .Lfab26a_000ab28e\n"
    );
}

/* line 458 */
__attribute__((naked))
void FxArchive_ArchiveFxGfxEntity(const FxArchive * _this, FxGfxEntity *entity)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 458 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "cmpb $0, 4(%esi)\n" /* line 460 | this */
        "je .Lfab3b0_000ab48f\n"
        /* { scope 1 */
        /* { scope 2: value */
        "addl $0x68, 8(%esi)\n" /* line 132 */
        "movl 0xc(%ebp), %ebx\n" /* line 134 | entity, data */
        "movl $0x68, %ecx\n"
        ".Lfab3b0_000ab3d5:\n"
        "movl 0xc(%esi), %eax\n" /* line 137 */
        "testl %eax, %eax\n"
        "jne .Lfab3b0_000ab40b\n"
        "xorl %edx, %edx\n"
        ".Lfab3b0_000ab3de:\n"
        "movl %ecx, %edi\n" /* line 458 */
        "subl %edx, %edi\n"
        "movl 0x10(%esi), %eax\n" /* line 145 */
        "testl %eax, %eax\n"
        "je .Lfab3b0_000ab43e\n"
        "cmpl %edx, %ecx\n"
        "je .Lfab3b0_000ab43e\n"
        "subl $1, %eax\n" /* line 147 */
        "movl %eax, 0x10(%esi)\n"
        "movb $0, (%ebx)\n" /* line 149 | data */
        "addl $1, %ebx\n" /* data */
        "addl $1, %edx\n"
        "cmpl %edx, %ecx\n" /* line 150 */
        "jne .Lfab3b0_000ab3de\n"
        /* } scope */
        /* } scope */
        ".Lfab3b0_000ab400:\n"
        "addl $0x8c, %esp\n" /* line 472 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: value */
        ".Lfab3b0_000ab40b:\n"
        "subl $1, %eax\n" /* line 139 */
        "movl %eax, 0xc(%esi)\n"
        "leal -1(%ecx), %edi\n" /* line 140 */
        /* { scope 3 */
        "leal -0x19(%ebp), %eax\n" /* line 122 | value */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movzbl -0x19(%ebp), %eax\n" /* line 141 | value */
        "movb %al, (%ebx)\n" /* data */
        "addl $1, %ebx\n" /* data */
        "testl %edi, %edi\n" /* line 142 */
        "je .Lfab3b0_000ab400\n"
        "movl %edi, %ecx\n"
        "jmp .Lfab3b0_000ab3d5\n"
        /* { scope 3 */
        ".Lfab3b0_000ab43e:\n"
        "leal -0x19(%ebp), %eax\n" /* line 122 | value */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        /* } scope */
        "movzbl -0x19(%ebp), %eax\n" /* line 156 | value */
        "movl %eax, %edx\n"
        "andl $0xc0, %edx\n"
        "cmpl $0x40, %edx\n"
        "je .Lfab3b0_000ab4e2\n"
        "cmpl $0x80, %edx\n"
        "je .Lfab3b0_000ab4f9\n"
        "testl %edx, %edx\n"
        "je .Lfab3b0_000ab4cb\n"
        "andl $0x3f, %eax\n" /* line 172 */
        "addl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "movl $0, 0x10(%esi)\n" /* line 173 */
        "movl %edi, %ecx\n" /* line 142 */
        "jmp .Lfab3b0_000ab3d5\n"
        /* } scope */
        /* } scope */
        /* { scope 1 */
        ".Lfab3b0_000ab48f:\n"
        "leal -0x84(%ebp), %ebx\n" /* line 468 | temp, data */
        "movl $0x68, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* entity */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* data */
        "calll memcpy\n"
        "movl $0x68, 8(%esp)\n" /* line 470 */
        "movl %ebx, 4(%esp)\n" /* data */
        "movl %esi, (%esp)\n" /* this */
        "calll FxArchive_WriteData\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 472 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: value */
        ".Lfab3b0_000ab4cb:\n"
        "movl $1, 0xc(%esi)\n" /* line 159 */
        "andl $0x3f, %eax\n" /* line 160 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %edi, %ecx\n" /* line 142 */
        "jmp .Lfab3b0_000ab3d5\n"
        ".Lfab3b0_000ab4e2:\n"
        "movl $2, 0xc(%esi)\n" /* line 163 */
        "andl $0x3f, %eax\n" /* line 164 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %edi, %ecx\n" /* line 142 */
        "jmp .Lfab3b0_000ab3d5\n"
        ".Lfab3b0_000ab4f9:\n"
        "movl $4, 0xc(%esi)\n" /* line 167 */
        "andl $0x3f, %eax\n" /* line 168 */
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %edi, %ecx\n" /* line 142 */
        "jmp .Lfab3b0_000ab3d5\n"
    );
}

