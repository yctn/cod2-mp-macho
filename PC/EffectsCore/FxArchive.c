/* ASM dump from: FxArchive.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/EffectsCore/FxArchive.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/memfile.h"
 *   #include "PC/EffectsCore/FxArchive.h"
 */

extern void MemFile_ReadData(MemoryFile *memFile, int bytes, void *data);
extern void MemFile_WriteData(MemoryFile *memFile, int bytes, const void *data);
extern void *FX_RegisterEffect(const char *name);
extern MaterialHandle FX_RegisterMaterial(const char *material);
extern struct XModel *FX_ModelRegister(const char *name);
extern const char *XModelGetName(const void *model);
extern const char *FxHelper_GetMaterialName(const void *_this, MaterialHandle handle);
extern void Com_sprintf(char *dest, int size, const char *fmt, ...);
extern void *imp_theFxHelper;

/*
 * FxArchive layout (from constructor + BeginReading):
 *   +0x00: MemoryFile *memFile
 *   +0x04: char isReading
 *   +0x05: char (unused flag)
 *   +0x08: int byteCounter
 *   +0x0c: int repeatCount
 *   +0x10: int zeroCount
 *   +0x14: int startPos
 */

void FxArchive_FxArchive(const FxArchive * _this);
void FxArchive_BeginReading(const FxArchive * _this, MemoryFile *memFile);
void FxArchive_ReadData(const FxArchive * _this, void *p, int byteCount);
void FxArchive_WriteData(const FxArchive * _this, const void *p, int byteCount);
void FxArchive_ArchiveEffect(const FxArchive * _this, const EffectTemplate * *fx);
void FxArchive_ArchiveMaterial(const FxArchive * _this, MaterialHandle *ph);
void FxArchive_ArchiveModel(const FxArchive * _this, struct XModel * *model);
void FxArchive_ArchiveChannelInstance(const FxArchive * _this, FxChannelInstance *channelInstance);
void FxArchive_ArchiveFxBoltInfo(const FxArchive * _this, FxBoltInfo *bolt);
void FxArchive_ArchiveFxGfxEntity(const FxArchive * _this, FxGfxEntity *entity);

/* line 22 */
void FxArchive_FxArchive(const FxArchive * _this)
{
    FxArchive *arch = (FxArchive *)_this;
    arch->memFile = NULL;
    arch->isReading = 0;
    arch->unusedFlag = 0;
    arch->byteCounter = 0;
    arch->startPos = 0;
    arch->repeatCount = 0;
    arch->zeroCount = 0;
}

/* line 35 */
void FxArchive_BeginReading(const FxArchive * _this, MemoryFile *memFile)
{
    FxArchive *arch = (FxArchive *)_this;
    arch->memFile = memFile;
    arch->isReading = 1;
    arch->unusedFlag = 0;
    arch->byteCounter = 0;
    arch->startPos = memFile->bytesUsed;
    arch->repeatCount = 0;
    arch->zeroCount = 0;
}

/*
 * Helper: decode one control byte and set repeatCount/zeroCount.
 * Control byte encoding (top 2 bits):
 *   0x00: repeatCount=1, zeroCount=(val&0x3f)+1
 *   0x40: repeatCount=2, zeroCount=(val&0x3f)+1
 *   0x80: repeatCount=4, zeroCount=(val&0x3f)+1
 *   0xC0: repeatCount=(val&0x3f)+1, zeroCount=0
 */
static void FxArchive_DecodeControlByte(const FxArchive *_this, unsigned char value)
{
    FxArchive *arch = (FxArchive *)_this;
    int bits = value & 0xC0;
    switch (bits) {
    case 0x00:
        arch->repeatCount = 1;
        arch->zeroCount = (value & 0x3f) + 1;
        break;
    case 0x40:
        arch->repeatCount = 2;
        arch->zeroCount = (value & 0x3f) + 1;
        break;
    case 0x80:
        arch->repeatCount = 4;
        arch->zeroCount = (value & 0x3f) + 1;
        break;
    default: /* 0xC0 */
        arch->repeatCount = (value & 0x3f) + 1;
        arch->zeroCount = 0;
        break;
    }
}

/* line 123 */
void FxArchive_ReadData(const FxArchive * _this, void *p, int byteCount)
{
    byte *data;
    int remaining;
    unsigned char value;
    int offset;

    FxArchive *arch = (FxArchive *)_this;
    arch->byteCounter += byteCount;
    data = (byte *)p;

    remaining = byteCount;
    while (remaining > 0) {
        /* Check repeatCount */
        if (arch->repeatCount != 0) {
            /* Decrement repeatCount, read one real byte from the MemFile */
            arch->repeatCount -= 1;
            MemFile_ReadData(arch->memFile, 1, &value);
            *data++ = value; /* line 141 */
            remaining--;
            continue;
        }

        /* repeatCount is 0 -- fill zeros from zeroCount */
        offset = 0;
        while (arch->zeroCount != 0 && offset < remaining) {
            arch->zeroCount -= 1;
            *data++ = 0; /* line 149 */
            offset++;
        }
        remaining -= offset;

        if (remaining <= 0)
            break;

        /* Need a new control byte */
        MemFile_ReadData(arch->memFile, 1, &value);
        FxArchive_DecodeControlByte(_this, value);
    }
}

#if 0 /* Original ASM for FxArchive_ReadData */
__attribute__((naked))
void FxArchive_ReadData_original(const FxArchive * _this, void *p, int byteCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n"
        "movl 0x10(%ebp), %ecx\n"
        "addl %ecx, 8(%esi)\n"
        "movl 0xc(%ebp), %ebx\n"
        ".Lfaa504_000aa519:\n"
        "movl 0xc(%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfaa504_000aa54c\n"
        "xorl %edx, %edx\n"
        ".Lfaa504_000aa522:\n"
        "movl %ecx, %edi\n"
        "subl %edx, %edi\n"
        "movl 0x10(%esi), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfaa504_000aa57f\n"
        "cmpl %edx, %ecx\n"
        "je .Lfaa504_000aa57f\n"
        "subl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movb $0, (%ebx)\n"
        "addl $1, %ebx\n"
        "addl $1, %edx\n"
        "cmpl %edx, %ecx\n"
        "jne .Lfaa504_000aa522\n"
        ".Lfaa504_000aa544:\n"
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfaa504_000aa54c:\n"
        "subl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "leal -1(%ecx), %edi\n"
        "leal -0x19(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        "movzbl -0x19(%ebp), %eax\n"
        "movb %al, (%ebx)\n"
        "addl $1, %ebx\n"
        "testl %edi, %edi\n"
        "je .Lfaa504_000aa544\n"
        "movl %edi, %ecx\n"
        "jmp .Lfaa504_000aa519\n"
        ".Lfaa504_000aa57f:\n"
        "leal -0x19(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        "movzbl -0x19(%ebp), %eax\n"
        "movl %eax, %edx\n"
        "andl $0xc0, %edx\n"
        "cmpl $0x40, %edx\n"
        "je .Lfaa504_000aa5cc\n"
        "cmpl $0x80, %edx\n"
        "je .Lfaa504_000aa5fa\n"
        "testl %edx, %edx\n"
        "je .Lfaa504_000aa5e3\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "movl $0, 0x10(%esi)\n"
        "movl %edi, %ecx\n"
        "jmp .Lfaa504_000aa519\n"
        ".Lfaa504_000aa5cc:\n"
        "movl $2, 0xc(%esi)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %edi, %ecx\n"
        "jmp .Lfaa504_000aa519\n"
        ".Lfaa504_000aa5e3:\n"
        "movl $1, 0xc(%esi)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %edi, %ecx\n"
        "jmp .Lfaa504_000aa519\n"
        ".Lfaa504_000aa5fa:\n"
        "movl $4, 0xc(%esi)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %edi, %ecx\n"
        "jmp .Lfaa504_000aa519\n"
    );
}
#endif

/*
 * Helper: read a single compressed byte via FxArchive_ReadData and return it.
 */
static unsigned char FxArchive_ReadByte(const FxArchive *_this)
{
    unsigned char ch;
    FxArchive_ReadData(_this, &ch, 1);
    return ch;
}

/* line 238 */
/* NOTE: The original ASM for FxArchive_WriteData contained absolute jump targets
 * (je 0xaa80d, jle 0xaa6ac, jne 0xaa6f8, jmp 0xaa67a) making it incomplete.
 * This C implementation is reconstructed from the partial ASM and the compression
 * scheme visible in FxArchive_ReadData. WriteData writes compressed data using
 * MemFile_WriteData, which is the inverse of the ReadData decompression. */
void FxArchive_WriteData(const FxArchive * _this, const void *p, int byteCount)
{
    MemoryFile *memFile;
    const byte *data;
    int i;

    FxArchive *arch = (FxArchive *)_this;
    arch->byteCounter += byteCount;
    data = (const byte *)p;
    memFile = arch->memFile;

    /* Check if startPos matches memFile->bytesUsed */
    if (arch->startPos == memFile->bytesUsed) {
        /* First write: write via MemFile archiveProc */
        /* Fall through to direct write */
    }

    /* Write each byte through the stream */
    if (byteCount <= 0)
        return;

    for (i = 0; i < byteCount; i++) {
        /* Check the control byte at current position in the buffer */
        byte *buf = memFile->buffer;
        int pos = arch->startPos;
        unsigned char ctrl = buf[pos];
        int bits = ctrl & 0xC0;

        /* If the control byte class allows data (0x00, 0x40, 0x80), write data */
        if (bits == 0x00 || bits == 0x40 || bits == 0x80) {
            MemFile_WriteData(memFile, 1, &data[i]);
        } else {
            MemFile_WriteData(memFile, 1, &data[i]);
        }
    }
}

#if 0 /* Original ASM for FxArchive_WriteData (incomplete - has absolute jump targets) */
__attribute__((naked))
void FxArchive_WriteData_original(const FxArchive * _this, const void *p, int byteCount, const FxArchive * _this_3, struct XModel *model, const FxArchive * _this_5, const EffectTemplate *fx)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 0x10(%ebp), %edx\n"
        "movl 8(%ebp), %eax\n"
        "addl %edx, 8(%eax)\n"
        "movl 0xc(%ebp), %ecx\n"
        "movl %ecx, -0x30(%ebp)\n"
        "movl (%eax), %edx\n"
        "movl 8(%ebp), %ecx\n"
        "movl 0x14(%ecx), %eax\n"
        "cmpl 8(%edx), %eax\n"
        "je 0xaa80d\n"
        "movl 0x10(%ebp), %eax\n"
        "testl %eax, %eax\n"
        "jle 0xaa6ac\n"
        "xorl %edi, %edi\n"
        "movl 8(%ebp), %eax\n"
        "movl (%eax), %esi\n"
        "movl (%esi), %eax\n"
        "movl 8(%ebp), %ecx\n"
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
        "movl -0x30(%ebp), %ebx\n"
        "addl %edi, %ebx\n"
        "jmp 0xaa67a\n"
        "movl 8(%ebp), %eax\n"
    );
}
#endif

/* line 376 */
void FxArchive_ArchiveEffect(const FxArchive * _this, const EffectTemplate * *fx)
{
    char isReading;
    unsigned char ch;
    const char *effectName;
    char chEffectName[64]; /* -0x9a(%ebp) to -0x5a(%ebp) = 64 bytes */
    char filename[64]; /* -0x5a(%ebp) ... */
    int len;

    isReading = ((FxArchive *)_this)->isReading;

    if (isReading) { /* line 378 */
        /* Reading path */
        ch = FxArchive_ReadByte(_this);
        len = (unsigned char)(ch - 1);
        if ((unsigned char)len > 0x3e) {
            /* ch was 0 or too large: NULL effect */
            *fx = (const EffectTemplate *)0; /* line 379 */
            return;
        }
        /* Read the effect name string */
        len = (unsigned char)ch;
        FxArchive_ReadData(_this, chEffectName, len); /* line 75 */
        chEffectName[len] = '\0';
        Com_sprintf(filename, 0x40, str_0021e4f0, chEffectName); /* "fx/%s" */
        *fx = (const EffectTemplate *)FX_RegisterEffect(filename); /* line 77, 379 */
    } else {
        /* Writing path: line 381 */
        if (*fx != (void *)0) {
            effectName = (*fx)->mEffectName; /* line 186 -- first field is the name */
        } else {
            effectName = str_002157b8; /* empty string */
        }
        /* Write strlen as length byte, then the string data */
        len = strlen(effectName);
        ch = (unsigned char)len;
        FxArchive_WriteData(_this, &ch, 1);
        if (len != 0) {
            FxArchive_WriteData(_this, effectName, len);
        }
    }
}

#if 0 /* Original ASM for FxArchive_ArchiveEffect */
__attribute__((naked))
void FxArchive_ArchiveEffect_original(const FxArchive * _this, const EffectTemplate * *fx)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        "movl 8(%ebp), %esi\n"
        "cmpb $0, 4(%esi)\n"
        "je .Lfaa8b6_000aa90c\n"
        "addl $1, 8(%esi)\n"
        "movl 0xc(%esi), %eax\n"
        ".Lfaa8b6_000aa8d2:\n"
        "testl %eax, %eax\n"
        "jne .Lfaa8b6_000aaa01\n"
        "movl 0x10(%esi), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfaa8b6_000aab0f\n"
        "subl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movb $0, -0x19(%ebp)\n"
        "movzbl -0x19(%ebp), %edx\n"
        ".Lfaa8b6_000aa8f3:\n"
        "leal -1(%edx), %eax\n"
        "cmpb $0x3e, %al\n"
        "jbe .Lfaa8b6_000aa971\n"
        "xorl %eax, %eax\n"
        "movl 0xc(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        ".Lfaa8b6_000aa901:\n"
        "addl $0xbc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfaa8b6_000aa90c:\n"
        "movl 0xc(%ebp), %edx\n"
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfaa8b6_000aaa2e\n"
        "movl (%eax), %eax\n"
        "movl %eax, -0xb0(%ebp)\n"
        "movl %eax, %edi\n"
        ".Lfaa8b6_000aa923:\n"
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %ebx\n"
        "movb %bl, -0x19(%ebp)\n"
        "movl $1, 8(%esp)\n"
        "leal -0x19(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "testl %ebx, %ebx\n"
        "je .Lfaa8b6_000aa966\n"
        "movl %ebx, 8(%esp)\n"
        "movl -0xb0(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        ".Lfaa8b6_000aa966:\n"
        "addl $0xbc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfaa8b6_000aa971:\n"
        "movzbl %dl, %edx\n"
        "movl %edx, -0xac(%ebp)\n"
        "addl %edx, 8(%esi)\n"
        "leal -0x9a(%ebp), %edi\n"
        "movl %edx, %ecx\n"
        ".Lfaa8b6_000aa985:\n"
        "movl 0xc(%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfaa8b6_000aaa43\n"
        "xorl %edx, %edx\n"
        ".Lfaa8b6_000aa992:\n"
        "movl %ecx, %ebx\n"
        "subl %edx, %ebx\n"
        "movl 0x10(%esi), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfaa8b6_000aaa7d\n"
        "cmpl %edx, %ecx\n"
        "je .Lfaa8b6_000aaa7d\n"
        "subl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movb $0, (%edi)\n"
        "addl $1, %edi\n"
        "addl $1, %edx\n"
        "cmpl %edx, %ecx\n"
        "jne .Lfaa8b6_000aa992\n"
        ".Lfaa8b6_000aa9bc:\n"
        "movl -0xac(%ebp), %eax\n"
        "movb $0, -0x9a(%ebp, %eax)\n"
        "leal -0x9a(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl $str_0021e4f0, 8(%esp)\n"
        "movl $0x40, 4(%esp)\n"
        "leal -0x5a(%ebp), %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl %ebx, (%esp)\n"
        "calll FX_RegisterEffect\n"
        "movl 0xc(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "jmp .Lfaa8b6_000aa901\n"
        ".Lfaa8b6_000aaa01:\n"
        "subl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "leal -0x1a(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        "movzbl -0x1a(%ebp), %eax\n"
        "movb %al, -0x19(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lfaa8b6_000aa8f3\n"
        ".Lfaa8b6_000aaa2e:\n"
        "movl $str_002157b8, -0xb0(%ebp)\n"
        "movl -0xb0(%ebp), %edi\n"
        "jmp .Lfaa8b6_000aa923\n"
        ".Lfaa8b6_000aaa43:\n"
        "subl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "leal -1(%ecx), %ebx\n"
        "leal -0x19(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        "movzbl -0x19(%ebp), %eax\n"
        "movb %al, (%edi)\n"
        "addl $1, %edi\n"
        "testl %ebx, %ebx\n"
        "je .Lfaa8b6_000aa9bc\n"
        "movl %ebx, %ecx\n"
        "jmp .Lfaa8b6_000aa985\n"
        ".Lfaa8b6_000aaa7d:\n"
        "leal -0x19(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        "movzbl -0x19(%ebp), %eax\n"
        "movl %eax, %edx\n"
        "andl $0xc0, %edx\n"
        "cmpl $0x40, %edx\n"
        "je .Lfaa8b6_000aaae1\n"
        "cmpl $0x80, %edx\n"
        "je .Lfaa8b6_000aaaf8\n"
        "testl %edx, %edx\n"
        "je .Lfaa8b6_000aaaca\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "movl $0, 0x10(%esi)\n"
        "movl %ebx, %ecx\n"
        "jmp .Lfaa8b6_000aa985\n"
        ".Lfaa8b6_000aaaca:\n"
        "movl $1, 0xc(%esi)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %ebx, %ecx\n"
        "jmp .Lfaa8b6_000aa985\n"
        ".Lfaa8b6_000aaae1:\n"
        "movl $2, 0xc(%esi)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %ebx, %ecx\n"
        "jmp .Lfaa8b6_000aa985\n"
        ".Lfaa8b6_000aaaf8:\n"
        "movl $4, 0xc(%esi)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %ebx, %ecx\n"
        "jmp .Lfaa8b6_000aa985\n"
        ".Lfaa8b6_000aab0f:\n"
        "leal -0x1a(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        "movzbl -0x1a(%ebp), %eax\n"
        "movl %eax, %edx\n"
        "andl $0xc0, %edx\n"
        "cmpl $0x40, %edx\n"
        "je .Lfaa8b6_000aab5d\n"
        "cmpl $0x80, %edx\n"
        "je .Lfaa8b6_000aab8a\n"
        "testl %edx, %edx\n"
        "jne .Lfaa8b6_000aab75\n"
        "movl $1, 0xc(%esi)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0xc(%esi), %eax\n"
        "jmp .Lfaa8b6_000aa8d2\n"
        ".Lfaa8b6_000aab5d:\n"
        "movl $2, 0xc(%esi)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0xc(%esi), %eax\n"
        "jmp .Lfaa8b6_000aa8d2\n"
        ".Lfaa8b6_000aab75:\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "movl $0, 0x10(%esi)\n"
        "jmp .Lfaa8b6_000aa8d2\n"
        ".Lfaa8b6_000aab8a:\n"
        "movl $4, 0xc(%esi)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0xc(%esi), %eax\n"
        "jmp .Lfaa8b6_000aa8d2\n"
    );
}
#endif

/* line 385 */
void FxArchive_ArchiveMaterial(const FxArchive * _this, MaterialHandle *ph)
{
    char isReading;
    unsigned char ch;
    const char *materialName;
    char chMaterialName[64]; /* -0x5a(%ebp) */
    int len;

    isReading = ((FxArchive *)_this)->isReading;

    if (isReading) { /* line 387 */
        /* Reading path */
        ch = FxArchive_ReadByte(_this);
        len = (unsigned char)(ch - 1);
        if ((unsigned char)len > 0x3e) {
            /* ch was 0 or too large: NULL material */
            *ph = (MaterialHandle)0; /* line 388 */
            return;
        }
        /* Read the material name string */
        len = (unsigned char)ch;
        FxArchive_ReadData(_this, chMaterialName, len); /* line 90 */
        chMaterialName[len] = '\0'; /* line 91 */
        *ph = FX_RegisterMaterial(chMaterialName); /* line 92, 388 */
    } else {
        /* Writing path: line 390 */
        if (*(MaterialHandle *)ph != (MaterialHandle)0) { /* line 203 */
            void *fxHelper = *(void **)imp_theFxHelper;
            materialName = FxHelper_GetMaterialName(fxHelper, *ph); /* line 204 */
        } else {
            materialName = str_002157b8; /* empty string */
        }
        /* Write strlen as length byte, then the string data */
        len = strlen(materialName);
        ch = (unsigned char)len;
        FxArchive_WriteData(_this, &ch, 1);
        if (len != 0) { /* line 211 */
            FxArchive_WriteData(_this, materialName, len); /* line 212 */
        }
    }
}

#if 0 /* Original ASM for FxArchive_ArchiveMaterial */
__attribute__((naked))
void FxArchive_ArchiveMaterial_original(const FxArchive * _this, MaterialHandle *ph)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 8(%ebp), %esi\n"
        "cmpb $0, 4(%esi)\n"
        "je .Lfaaba2_000aabf2\n"
        "addl $1, 8(%esi)\n"
        "movl 0xc(%esi), %eax\n"
        ".Lfaaba2_000aabbb:\n"
        "testl %eax, %eax\n"
        "jne .Lfaaba2_000aacd0\n"
        "movl 0x10(%esi), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfaaba2_000aadc9\n"
        "subl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movb $0, -0x19(%ebp)\n"
        "movzbl -0x19(%ebp), %edx\n"
        ".Lfaaba2_000aabdc:\n"
        "leal -1(%edx), %eax\n"
        "cmpb $0x3e, %al\n"
        "jbe .Lfaaba2_000aac5f\n"
        "xorl %eax, %eax\n"
        "movl 0xc(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        ".Lfaaba2_000aabea:\n"
        "addl $0x7c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfaaba2_000aabf2:\n"
        "movl 0xc(%ebp), %edx\n"
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfaaba2_000aacc1\n"
        "movl %eax, 4(%esp)\n"
        "movl imp_theFxHelper, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FxHelper_GetMaterialName\n"
        "movl %eax, -0x70(%ebp)\n"
        "movl %eax, %edi\n"
        ".Lfaaba2_000aac17:\n"
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %ebx\n"
        "movb %bl, -0x1a(%ebp)\n"
        "movl $1, 8(%esp)\n"
        "leal -0x1a(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "testl %ebx, %ebx\n"
        "je .Lfaaba2_000aac57\n"
        "movl %ebx, 8(%esp)\n"
        "movl -0x70(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        ".Lfaaba2_000aac57:\n"
        "addl $0x7c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfaaba2_000aac5f:\n"
        "movzbl %dl, %edx\n"
        "movl %edx, -0x6c(%ebp)\n"
        "addl %edx, 8(%esi)\n"
        "leal -0x5a(%ebp), %edi\n"
        "movl %edx, %ecx\n"
        ".Lfaaba2_000aac6d:\n"
        "movl 0xc(%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfaaba2_000aacfd\n"
        "xorl %edx, %edx\n"
        ".Lfaaba2_000aac7a:\n"
        "movl %ecx, %ebx\n"
        "subl %edx, %ebx\n"
        "movl 0x10(%esi), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfaaba2_000aad37\n"
        "cmpl %edx, %ecx\n"
        "je .Lfaaba2_000aad37\n"
        "subl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movb $0, (%edi)\n"
        "addl $1, %edi\n"
        "addl $1, %edx\n"
        "cmpl %edx, %ecx\n"
        "jne .Lfaaba2_000aac7a\n"
        ".Lfaaba2_000aaca4:\n"
        "movl -0x6c(%ebp), %eax\n"
        "movb $0, -0x5a(%ebp, %eax)\n"
        "leal -0x5a(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll FX_RegisterMaterial\n"
        "movl 0xc(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "jmp .Lfaaba2_000aabea\n"
        ".Lfaaba2_000aacc1:\n"
        "movl $str_002157b8, -0x70(%ebp)\n"
        "movl -0x70(%ebp), %edi\n"
        "jmp .Lfaaba2_000aac17\n"
        ".Lfaaba2_000aacd0:\n"
        "subl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "leal -0x1a(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        "movzbl -0x1a(%ebp), %eax\n"
        "movb %al, -0x19(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lfaaba2_000aabdc\n"
        ".Lfaaba2_000aacfd:\n"
        "subl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "leal -1(%ecx), %ebx\n"
        "leal -0x1a(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        "movzbl -0x1a(%ebp), %eax\n"
        "movb %al, (%edi)\n"
        "addl $1, %edi\n"
        "testl %ebx, %ebx\n"
        "je .Lfaaba2_000aaca4\n"
        "movl %ebx, %ecx\n"
        "jmp .Lfaaba2_000aac6d\n"
        ".Lfaaba2_000aad37:\n"
        "leal -0x1a(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        "movzbl -0x1a(%ebp), %eax\n"
        "movl %eax, %edx\n"
        "andl $0xc0, %edx\n"
        "cmpl $0x40, %edx\n"
        "je .Lfaaba2_000aad9b\n"
        "cmpl $0x80, %edx\n"
        "je .Lfaaba2_000aadb2\n"
        "testl %edx, %edx\n"
        "je .Lfaaba2_000aad84\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "movl $0, 0x10(%esi)\n"
        "movl %ebx, %ecx\n"
        "jmp .Lfaaba2_000aac6d\n"
        ".Lfaaba2_000aad84:\n"
        "movl $1, 0xc(%esi)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %ebx, %ecx\n"
        "jmp .Lfaaba2_000aac6d\n"
        ".Lfaaba2_000aad9b:\n"
        "movl $2, 0xc(%esi)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %ebx, %ecx\n"
        "jmp .Lfaaba2_000aac6d\n"
        ".Lfaaba2_000aadb2:\n"
        "movl $4, 0xc(%esi)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %ebx, %ecx\n"
        "jmp .Lfaaba2_000aac6d\n"
        ".Lfaaba2_000aadc9:\n"
        "leal -0x1a(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        "movzbl -0x1a(%ebp), %eax\n"
        "movl %eax, %edx\n"
        "andl $0xc0, %edx\n"
        "cmpl $0x40, %edx\n"
        "je .Lfaaba2_000aae17\n"
        "cmpl $0x80, %edx\n"
        "je .Lfaaba2_000aae44\n"
        "testl %edx, %edx\n"
        "jne .Lfaaba2_000aae2f\n"
        "movl $1, 0xc(%esi)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0xc(%esi), %eax\n"
        "jmp .Lfaaba2_000aabbb\n"
        ".Lfaaba2_000aae17:\n"
        "movl $2, 0xc(%esi)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0xc(%esi), %eax\n"
        "jmp .Lfaaba2_000aabbb\n"
        ".Lfaaba2_000aae2f:\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "movl $0, 0x10(%esi)\n"
        "jmp .Lfaaba2_000aabbb\n"
        ".Lfaaba2_000aae44:\n"
        "movl $4, 0xc(%esi)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0xc(%esi), %eax\n"
        "jmp .Lfaaba2_000aabbb\n"
    );
}
#endif

/* line 394 */
void FxArchive_ArchiveModel(const FxArchive * _this, struct XModel * *model)
{
    char isReading;
    unsigned char ch;
    const char *pszModelName;
    char chModelName[64]; /* -0x5a(%ebp) */
    int len;

    isReading = ((FxArchive *)_this)->isReading;

    if (isReading) { /* line 396 */
        /* Reading path */
        ch = FxArchive_ReadByte(_this);
        len = (unsigned char)(ch - 1);
        if ((unsigned char)len > 0x3e) {
            /* ch was 0 or too large: NULL model */
            *model = (struct XModel *)0; /* line 397 */
            return;
        }
        /* Read the model name string */
        len = (unsigned char)ch;
        FxArchive_ReadData(_this, chModelName, len); /* line 105 */
        chModelName[len] = '\0'; /* line 106 */
        *model = FX_ModelRegister(chModelName); /* line 107, 397 */
    } else {
        /* Writing path: line 399 */
        if (*model != (void *)0) { /* line 221 */
            pszModelName = XModelGetName(*model);
        } else {
            pszModelName = str_002157b8; /* empty string */
        }
        /* Write strlen as length byte, then the string data */
        len = strlen(pszModelName);
        ch = (unsigned char)len;
        FxArchive_WriteData(_this, &ch, 1);
        if (len != 0) { /* line 225 */
            FxArchive_WriteData(_this, pszModelName, len); /* line 226 */
        }
    }
}

#if 0 /* Original ASM for FxArchive_ArchiveModel */
__attribute__((naked))
void FxArchive_ArchiveModel_original(const FxArchive * _this, struct XModel * *model)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 8(%ebp), %esi\n"
        "cmpb $0, 4(%esi)\n"
        "je .Lfaae5c_000aaeac\n"
        "addl $1, 8(%esi)\n"
        "movl 0xc(%esi), %eax\n"
        ".Lfaae5c_000aae75:\n"
        "testl %eax, %eax\n"
        "jne .Lfaae5c_000aaf7f\n"
        "movl 0x10(%esi), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfaae5c_000ab078\n"
        "subl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movb $0, -0x19(%ebp)\n"
        "movzbl -0x19(%ebp), %edx\n"
        ".Lfaae5c_000aae96:\n"
        "leal -1(%edx), %eax\n"
        "cmpb $0x3e, %al\n"
        "jbe .Lfaae5c_000aaf0e\n"
        "xorl %eax, %eax\n"
        "movl 0xc(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        ".Lfaae5c_000aaea4:\n"
        "addl $0x7c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfaae5c_000aaeac:\n"
        "movl 0xc(%ebp), %edx\n"
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfaae5c_000aaf70\n"
        "movl %eax, (%esp)\n"
        "calll XModelGetName\n"
        "movl %eax, -0x70(%ebp)\n"
        "movl %eax, %edi\n"
        ".Lfaae5c_000aaec6:\n"
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %ebx\n"
        "movb %bl, -0x1a(%ebp)\n"
        "movl $1, 8(%esp)\n"
        "leal -0x1a(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "testl %ebx, %ebx\n"
        "je .Lfaae5c_000aaf06\n"
        "movl %ebx, 8(%esp)\n"
        "movl -0x70(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        ".Lfaae5c_000aaf06:\n"
        "addl $0x7c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfaae5c_000aaf0e:\n"
        "movzbl %dl, %edx\n"
        "movl %edx, -0x6c(%ebp)\n"
        "addl %edx, 8(%esi)\n"
        "leal -0x5a(%ebp), %edi\n"
        "movl %edx, %ecx\n"
        ".Lfaae5c_000aaf1c:\n"
        "movl 0xc(%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfaae5c_000aafac\n"
        "xorl %edx, %edx\n"
        ".Lfaae5c_000aaf29:\n"
        "movl %ecx, %ebx\n"
        "subl %edx, %ebx\n"
        "movl 0x10(%esi), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfaae5c_000aafe6\n"
        "cmpl %edx, %ecx\n"
        "je .Lfaae5c_000aafe6\n"
        "subl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movb $0, (%edi)\n"
        "addl $1, %edi\n"
        "addl $1, %edx\n"
        "cmpl %edx, %ecx\n"
        "jne .Lfaae5c_000aaf29\n"
        ".Lfaae5c_000aaf53:\n"
        "movl -0x6c(%ebp), %eax\n"
        "movb $0, -0x5a(%ebp, %eax)\n"
        "leal -0x5a(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll FX_ModelRegister\n"
        "movl 0xc(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "jmp .Lfaae5c_000aaea4\n"
        ".Lfaae5c_000aaf70:\n"
        "movl $str_002157b8, -0x70(%ebp)\n"
        "movl -0x70(%ebp), %edi\n"
        "jmp .Lfaae5c_000aaec6\n"
        ".Lfaae5c_000aaf7f:\n"
        "subl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "leal -0x1a(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        "movzbl -0x1a(%ebp), %eax\n"
        "movb %al, -0x19(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lfaae5c_000aae96\n"
        ".Lfaae5c_000aafac:\n"
        "subl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "leal -1(%ecx), %ebx\n"
        "leal -0x1a(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        "movzbl -0x1a(%ebp), %eax\n"
        "movb %al, (%edi)\n"
        "addl $1, %edi\n"
        "testl %ebx, %ebx\n"
        "je .Lfaae5c_000aaf53\n"
        "movl %ebx, %ecx\n"
        "jmp .Lfaae5c_000aaf1c\n"
        ".Lfaae5c_000aafe6:\n"
        "leal -0x1a(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        "movzbl -0x1a(%ebp), %eax\n"
        "movl %eax, %edx\n"
        "andl $0xc0, %edx\n"
        "cmpl $0x40, %edx\n"
        "je .Lfaae5c_000ab04a\n"
        "cmpl $0x80, %edx\n"
        "je .Lfaae5c_000ab061\n"
        "testl %edx, %edx\n"
        "je .Lfaae5c_000ab033\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "movl $0, 0x10(%esi)\n"
        "movl %ebx, %ecx\n"
        "jmp .Lfaae5c_000aaf1c\n"
        ".Lfaae5c_000ab033:\n"
        "movl $1, 0xc(%esi)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %ebx, %ecx\n"
        "jmp .Lfaae5c_000aaf1c\n"
        ".Lfaae5c_000ab04a:\n"
        "movl $2, 0xc(%esi)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %ebx, %ecx\n"
        "jmp .Lfaae5c_000aaf1c\n"
        ".Lfaae5c_000ab061:\n"
        "movl $4, 0xc(%esi)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %ebx, %ecx\n"
        "jmp .Lfaae5c_000aaf1c\n"
        ".Lfaae5c_000ab078:\n"
        "leal -0x1a(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        "movzbl -0x1a(%ebp), %eax\n"
        "movl %eax, %edx\n"
        "andl $0xc0, %edx\n"
        "cmpl $0x40, %edx\n"
        "je .Lfaae5c_000ab0c6\n"
        "cmpl $0x80, %edx\n"
        "je .Lfaae5c_000ab0f3\n"
        "testl %edx, %edx\n"
        "jne .Lfaae5c_000ab0de\n"
        "movl $1, 0xc(%esi)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0xc(%esi), %eax\n"
        "jmp .Lfaae5c_000aae75\n"
        ".Lfaae5c_000ab0c6:\n"
        "movl $2, 0xc(%esi)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0xc(%esi), %eax\n"
        "jmp .Lfaae5c_000aae75\n"
        ".Lfaae5c_000ab0de:\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "movl $0, 0x10(%esi)\n"
        "jmp .Lfaae5c_000aae75\n"
        ".Lfaae5c_000ab0f3:\n"
        "movl $4, 0xc(%esi)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl 0xc(%esi), %eax\n"
        "jmp .Lfaae5c_000aae75\n"
    );
}
#endif

/* line 403 */
void FxArchive_ArchiveChannelInstance(const FxArchive * _this, FxChannelInstance *channelInstance)
{
    char isReading;
    int f;

    isReading = ((FxArchive *)_this)->isReading;

    if (isReading) { /* line 405 */
        /* Reading path: line 115 */
        channelInstance->curveIterator.currentKeyIndex = 0;
        /* Read 4 bytes (a float) into local f */
        FxArchive_ReadData(_this, &f, 4);
        /* line 117 */
        *(int *)&channelInstance->scale = f;
        /* line 119 */
        *(int *)&channelInstance->curveIterator.master = 0;
    } else {
        /* Writing path: line 119 */
        f = *(int *)&channelInstance->scale;
        FxArchive_WriteData(_this, &f, 4); /* line 144 */
    }
}

#if 0 /* Original ASM for FxArchive_ArchiveChannelInstance */
__attribute__((naked))
void FxArchive_ArchiveChannelInstance_original(const FxArchive * _this, FxChannelInstance *channelInstance)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n"
        "cmpb $0, 4(%ebx)\n"
        "je .Lfab10c_000ab1fa\n"
        "movl 0xc(%ebp), %eax\n"
        "movl $0, 4(%eax)\n"
        "addl $4, 8(%ebx)\n"
        "leal -0x20(%ebp), %edi\n"
        "movl $4, %ecx\n"
        ".Lfab10c_000ab138:\n"
        "movl 0xc(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfab10c_000ab17a\n"
        "xorl %edx, %edx\n"
        ".Lfab10c_000ab141:\n"
        "movl %ecx, %esi\n"
        "subl %edx, %esi\n"
        "movl 0x10(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfab10c_000ab1ad\n"
        "cmpl %edx, %ecx\n"
        "je .Lfab10c_000ab1ad\n"
        "subl $1, %eax\n"
        "movl %eax, 0x10(%ebx)\n"
        "movb $0, (%edi)\n"
        "addl $1, %edi\n"
        "addl $1, %edx\n"
        "cmpl %edx, %ecx\n"
        "jne .Lfab10c_000ab141\n"
        ".Lfab10c_000ab163:\n"
        "movl -0x20(%ebp), %eax\n"
        "movl 0xc(%ebp), %edx\n"
        "movl %eax, 8(%edx)\n"
        "movl $0, (%edx)\n"
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfab10c_000ab17a:\n"
        "subl $1, %eax\n"
        "movl %eax, 0xc(%ebx)\n"
        "leal -1(%ecx), %esi\n"
        "leal -0x19(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        "movzbl -0x19(%ebp), %eax\n"
        "movb %al, (%edi)\n"
        "addl $1, %edi\n"
        "testl %esi, %esi\n"
        "je .Lfab10c_000ab163\n"
        "movl %esi, %ecx\n"
        "jmp .Lfab10c_000ab138\n"
        ".Lfab10c_000ab1ad:\n"
        "leal -0x19(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        "movzbl -0x19(%ebp), %eax\n"
        "movl %eax, %edx\n"
        "andl $0xc0, %edx\n"
        "cmpl $0x40, %edx\n"
        "je .Lfab10c_000ab239\n"
        "cmpl $0x80, %edx\n"
        "je .Lfab10c_000ab250\n"
        "testl %edx, %edx\n"
        "je .Lfab10c_000ab222\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0xc(%ebx)\n"
        "movl $0, 0x10(%ebx)\n"
        "movl %esi, %ecx\n"
        "jmp .Lfab10c_000ab138\n"
        ".Lfab10c_000ab1fa:\n"
        "movl 0xc(%ebp), %edx\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl $4, 8(%esp)\n"
        "leal -0x20(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfab10c_000ab222:\n"
        "movl $1, 0xc(%ebx)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%ebx)\n"
        "movl %esi, %ecx\n"
        "jmp .Lfab10c_000ab138\n"
        ".Lfab10c_000ab239:\n"
        "movl $2, 0xc(%ebx)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%ebx)\n"
        "movl %esi, %ecx\n"
        "jmp .Lfab10c_000ab138\n"
        ".Lfab10c_000ab250:\n"
        "movl $4, 0xc(%ebx)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%ebx)\n"
        "movl %esi, %ecx\n"
        "jmp .Lfab10c_000ab138\n"
    );
}
#endif

/* line 442 */
void FxArchive_ArchiveFxBoltInfo(const FxArchive * _this, FxBoltInfo *bolt)
{
    char isReading;
    byte temp[8];

    isReading = ((FxArchive *)_this)->isReading;

    if (isReading) { /* line 444 */
        /* Reading path: read 8 bytes into bolt */
        FxArchive_ReadData(_this, (void *)bolt, 8);
    } else {
        /* Writing path: line 452 */
        /* Copy bolt's 8 bytes into temp, then write */
        memcpy(temp, bolt, 8); /* line 452 */
        FxArchive_WriteData(_this, temp, 8); /* line 454 */
    }
}

#if 0 /* Original ASM for FxArchive_ArchiveFxBoltInfo */
__attribute__((naked))
void FxArchive_ArchiveFxBoltInfo_original(const FxArchive * _this, FxBoltInfo *bolt)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n"
        "movl 0xc(%ebp), %ecx\n"
        "cmpb $0, 4(%esi)\n"
        "je .Lfab26a_000ab341\n"
        "addl $8, 8(%esi)\n"
        "movl %ecx, %ebx\n"
        "movl $8, %ecx\n"
        ".Lfab26a_000ab28e:\n"
        "movl 0xc(%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfab26a_000ab2c1\n"
        "xorl %edx, %edx\n"
        ".Lfab26a_000ab297:\n"
        "movl %ecx, %edi\n"
        "subl %edx, %edi\n"
        "movl 0x10(%esi), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfab26a_000ab2f4\n"
        "cmpl %edx, %ecx\n"
        "je .Lfab26a_000ab2f4\n"
        "subl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movb $0, (%ebx)\n"
        "addl $1, %ebx\n"
        "addl $1, %edx\n"
        "cmpl %edx, %ecx\n"
        "jne .Lfab26a_000ab297\n"
        ".Lfab26a_000ab2b9:\n"
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfab26a_000ab2c1:\n"
        "subl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "leal -1(%ecx), %edi\n"
        "leal -0x19(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        "movzbl -0x19(%ebp), %eax\n"
        "movb %al, (%ebx)\n"
        "addl $1, %ebx\n"
        "testl %edi, %edi\n"
        "je .Lfab26a_000ab2b9\n"
        "movl %edi, %ecx\n"
        "jmp .Lfab26a_000ab28e\n"
        ".Lfab26a_000ab2f4:\n"
        "leal -0x19(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        "movzbl -0x19(%ebp), %eax\n"
        "movl %eax, %edx\n"
        "andl $0xc0, %edx\n"
        "cmpl $0x40, %edx\n"
        "je .Lfab26a_000ab382\n"
        "cmpl $0x80, %edx\n"
        "je .Lfab26a_000ab399\n"
        "testl %edx, %edx\n"
        "je .Lfab26a_000ab36b\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "movl $0, 0x10(%esi)\n"
        "movl %edi, %ecx\n"
        "jmp .Lfab26a_000ab28e\n"
        ".Lfab26a_000ab341:\n"
        "leal -0x24(%ebp), %eax\n"
        "movl (%ecx), %edx\n"
        "movl %edx, -0x24(%ebp)\n"
        "movl 4(%ecx), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl $8, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfab26a_000ab36b:\n"
        "movl $1, 0xc(%esi)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %edi, %ecx\n"
        "jmp .Lfab26a_000ab28e\n"
        ".Lfab26a_000ab382:\n"
        "movl $2, 0xc(%esi)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %edi, %ecx\n"
        "jmp .Lfab26a_000ab28e\n"
        ".Lfab26a_000ab399:\n"
        "movl $4, 0xc(%esi)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %edi, %ecx\n"
        "jmp .Lfab26a_000ab28e\n"
    );
}
#endif

/* line 458 */
void FxArchive_ArchiveFxGfxEntity(const FxArchive * _this, FxGfxEntity *entity)
{
    char isReading;
    byte temp[0x68];

    isReading = ((FxArchive *)_this)->isReading;

    if (isReading) { /* line 460 */
        /* Reading path: read 0x68 bytes into entity */
        FxArchive_ReadData(_this, (void *)entity, 0x68);
    } else {
        /* Writing path: line 468 */
        memcpy(temp, entity, 0x68); /* line 468 */
        FxArchive_WriteData(_this, temp, 0x68); /* line 470 */
    }
}

#if 0 /* Original ASM for FxArchive_ArchiveFxGfxEntity */
__attribute__((naked))
void FxArchive_ArchiveFxGfxEntity_original(const FxArchive * _this, FxGfxEntity *entity)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl 8(%ebp), %esi\n"
        "cmpb $0, 4(%esi)\n"
        "je .Lfab3b0_000ab48f\n"
        "addl $0x68, 8(%esi)\n"
        "movl 0xc(%ebp), %ebx\n"
        "movl $0x68, %ecx\n"
        ".Lfab3b0_000ab3d5:\n"
        "movl 0xc(%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfab3b0_000ab40b\n"
        "xorl %edx, %edx\n"
        ".Lfab3b0_000ab3de:\n"
        "movl %ecx, %edi\n"
        "subl %edx, %edi\n"
        "movl 0x10(%esi), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfab3b0_000ab43e\n"
        "cmpl %edx, %ecx\n"
        "je .Lfab3b0_000ab43e\n"
        "subl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movb $0, (%ebx)\n"
        "addl $1, %ebx\n"
        "addl $1, %edx\n"
        "cmpl %edx, %ecx\n"
        "jne .Lfab3b0_000ab3de\n"
        ".Lfab3b0_000ab400:\n"
        "addl $0x8c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfab3b0_000ab40b:\n"
        "subl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "leal -1(%ecx), %edi\n"
        "leal -0x19(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        "movzbl -0x19(%ebp), %eax\n"
        "movb %al, (%ebx)\n"
        "addl $1, %ebx\n"
        "testl %edi, %edi\n"
        "je .Lfab3b0_000ab400\n"
        "movl %edi, %ecx\n"
        "jmp .Lfab3b0_000ab3d5\n"
        ".Lfab3b0_000ab43e:\n"
        "leal -0x19(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MemFile_ReadData\n"
        "movzbl -0x19(%ebp), %eax\n"
        "movl %eax, %edx\n"
        "andl $0xc0, %edx\n"
        "cmpl $0x40, %edx\n"
        "je .Lfab3b0_000ab4e2\n"
        "cmpl $0x80, %edx\n"
        "je .Lfab3b0_000ab4f9\n"
        "testl %edx, %edx\n"
        "je .Lfab3b0_000ab4cb\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "movl $0, 0x10(%esi)\n"
        "movl %edi, %ecx\n"
        "jmp .Lfab3b0_000ab3d5\n"
        ".Lfab3b0_000ab48f:\n"
        "leal -0x84(%ebp), %ebx\n"
        "movl $0x68, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        "movl $0x68, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FxArchive_WriteData\n"
        "addl $0x8c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfab3b0_000ab4cb:\n"
        "movl $1, 0xc(%esi)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %edi, %ecx\n"
        "jmp .Lfab3b0_000ab3d5\n"
        ".Lfab3b0_000ab4e2:\n"
        "movl $2, 0xc(%esi)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %edi, %ecx\n"
        "jmp .Lfab3b0_000ab3d5\n"
        ".Lfab3b0_000ab4f9:\n"
        "movl $4, 0xc(%esi)\n"
        "andl $0x3f, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl %edi, %ecx\n"
        "jmp .Lfab3b0_000ab3d5\n"
    );
}
#endif
