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
        Com_sprintf(filename, 0x40, "fx/%s", chEffectName); /* "fx/%s" */
        *fx = (const EffectTemplate *)FX_RegisterEffect(filename); /* line 77, 379 */
    } else {
        /* Writing path: line 381 */
        if (*fx != (void *)0) {
            effectName = (*fx)->mEffectName; /* line 186 -- first field is the name */
        } else {
            effectName = ""; /* empty string */
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
            materialName = ""; /* empty string */
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
            pszModelName = ""; /* empty string */
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
        memcpy(&channelInstance->scale, &f, 4);
        /* line 119 */
        channelInstance->curveIterator.master = NULL;
    } else {
        /* Writing path: line 119 */
        memcpy(&f, &channelInstance->scale, 4);
        FxArchive_WriteData(_this, &f, 4); /* line 144 */
    }
}

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

