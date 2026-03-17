/* Converted to C from ASM: FxScheduler_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/EffectsCore/FxScheduler_load_obj.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>
#include <stdio.h>

extern void PrimitiveTemplate_Shutdown(void *prim);
extern void PrimitiveTemplate_Init(void *prim);
extern int PrimitiveTemplate_ParsePrimitive(void *prim, void *group);
extern EffectTemplate *FX_TryRegisterEffect(const char *name);
extern void Com_Error(int level, const char *fmt, ...);
extern void Z_FreeInternal(void *ptr);
extern void *Z_MallocInternal(int size);
extern int FS_FOpenFileByMode(const char *filename, int *f, int mode);
extern int FS_Read(void *buffer, int len, int f);
extern void FS_FCloseFile(int f);
extern void *Hunk_AllocateTempMemoryInternal(int size);
extern void Hunk_FreeTempMemory(void *buf);
extern void GenericParser2_Parse(void *parser, void **bufPtr, int flag1, int flag2);
extern void *Hunk_AllocAlignInternal(int size, int align);
extern void FX_Print(const char *fmt, ...);
extern void Com_StripExtension(const char *in, char *out);
extern int strnicmp(const char *s1, const char *s2, int n);
extern int stricmp(const char *s1, const char *s2);
#ifndef __EMSCRIPTEN__
extern void strlwr(char *s);
#endif

extern byte *fx_developer_check_ptr; /* imp_g_rendererExists */

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
float FX_CleanTemplate(EffectTemplate *fx)
{
    int count;
    int j;

    count = *(int *)((byte *)fx + 4);
    if (count <= 0)
        return 0;

    for (j = 0; j < count; j++) {
        PrimitiveTemplate_Shutdown(*(void **)((byte *)fx + 8 + j * 4));
    }
}

/* line 108 */
float FX_CreateDefaultEffect(void)
{
    defaultEffect = FX_TryRegisterEffect("default_fx");
    if (defaultEffect == NULL) {
        /* default_fx.efx not in any IWD; pure mode blocks loose .efx files.
           Create a minimal empty effect template in-memory. */
        char *nameBuf;
        defaultEffect = (EffectTemplate *)Hunk_AllocAlignInternal(0x68, 4);
        memset(defaultEffect, 0, 0x68);
        nameBuf = (char *)Hunk_AllocAlignInternal(11, 4);
        strcpy(nameBuf, "default_fx");
        *(char **)defaultEffect = nameBuf;
    }
}

/* line 620 */
float MediaHandles_Shutdown(const MediaHandles * _this)
{
    byte *self = (byte *)_this;

    if (*(void **)self != NULL) {
        Z_FreeInternal(*(void **)self);
        *(void **)self = NULL;
        *(short *)(self + 4) = 0;
        *(short *)(self + 6) = 0;
    }
}

/* line 631 */
float MediaHandles_AddHandle(const MediaHandles * _this, TMediaElement item)
{
    byte *self = (byte *)_this;
    unsigned short count;
    unsigned short capacity;
    void *newElements;

    count = *(unsigned short *)(self + 4);
    capacity = *(unsigned short *)(self + 6);

    if (count == capacity) {
        if (count == 0) {
            *(unsigned short *)(self + 6) = 4;
        } else {
            *(unsigned short *)(self + 6) = count * 2;
        }
        newElements = Z_MallocInternal(*(unsigned short *)(self + 6) * 4);
        if (*(void **)self != NULL) {
            memcpy(newElements, *(void **)self, *(unsigned short *)(self + 4) * 4);
            Z_FreeInternal(*(void **)self);
        }
        *(void **)self = newElements;
    }

    ((void **)(*(void **)self))[*(unsigned short *)(self + 4)] = item.data;
    *(unsigned short *)(self + 4) += 1;
}

/* line 522 */
EffectTemplate * FX_ParseEffect(GenericParser2 *parser, const char *name)
{
    char fileName[64];
    int fileHandle;
    void *buf;
    void *bufParse;
    EffectTemplate *effect;
    int currentPrimitiveIndex;
    void *primitiveGroup;
    char *grpName;
    int type;
    void *prim;
    int fileLength;
    int count;
    int j;
    char *nameBuf;

    sprintf(fileName, "fx/%s.efx", name);
    fileLength = FS_FOpenFileByMode(fileName, &fileHandle, 0);

    if (fileLength < 0) {
        FX_Print("Effect file load failed: %s: file not found\n", fileName);
        return NULL;
    }

    buf = Hunk_AllocateTempMemoryInternal(fileLength + 1);
    FS_Read(buf, fileLength, fileHandle);
    FS_FCloseFile(fileHandle);
    ((char *)buf)[fileLength] = '\0';

    bufParse = buf;
    GenericParser2_Parse(parser, &bufParse, 1, 0);
    Hunk_FreeTempMemory(buf);

    effect = (EffectTemplate *)Hunk_AllocAlignInternal(0x68, 4);

    nameBuf = (char *)Hunk_AllocAlignInternal(strlen(name) + 1, 4);
    *(char **)effect = nameBuf;
    strcpy(nameBuf, name);

    primitiveGroup = *(void **)((byte *)parser + 0x1c);
    if (primitiveGroup == NULL)
        return effect;

    currentPrimitiveIndex = 0;

    while (primitiveGroup != NULL) {
        grpName = *(char **)primitiveGroup;

        if (stricmp(grpName, "particle") == 0) {
            type = 1;
        } else if (stricmp(grpName, "line") == 0) {
            type = 2;
        } else if (stricmp(grpName, "tail") == 0) {
            type = 3;
        } else if (stricmp(grpName, "electricity") == 0) {
            type = 4;
        } else if (stricmp(grpName, "cylinder") == 0) {
            type = 5;
        } else if (stricmp(grpName, "light") == 0) {
            type = 6;
        } else if (stricmp(grpName, "sound") == 0) {
            type = 7;
        } else if (stricmp(grpName, "decal") == 0) {
            type = 8;
        } else if (stricmp(grpName, "runner") == 0) {
            type = 9;
        } else if (stricmp(grpName, "fxrunner") == 0) {
            type = 10;
        } else if (stricmp(grpName, "flash") == 0) {
            type = 11;
        } else if (stricmp(grpName, "spotLight") == 0) {
            type = 12;
        } else {
            goto next_group;
        }

        prim = Hunk_AllocAlignInternal(0x2a4, 4);
        PrimitiveTemplate_Init(prim);
        *(int *)((byte *)prim + 0x40) = type;
        *(int *)((byte *)prim + 0x44) = currentPrimitiveIndex;

        if (!PrimitiveTemplate_ParsePrimitive(prim, primitiveGroup)) {
            PrimitiveTemplate_Shutdown(prim);
            count = *(int *)((byte *)effect + 4);
            for (j = 0; j < count; j++) {
                PrimitiveTemplate_Shutdown(*(void **)((byte *)effect + 8 + j * 4));
            }
            FX_Print("^1FX Error while parsing segment type '%s'\n", *(char **)primitiveGroup);
            return NULL;
        }

        /* Validate materials for particle/tail/sound types */
        if (type == 1 || type == 7 || type == 3) {
            if (*fx_developer_check_ptr != 0 && *(short *)((byte *)prim + 0x6c) == 0) {
                FX_Print("^1FX Error, no materials defined for primitive template of type %d\n", type);
                PrimitiveTemplate_Shutdown(prim);
                count = *(int *)((byte *)effect + 4);
                for (j = 0; j < count; j++) {
                    PrimitiveTemplate_Shutdown(*(void **)((byte *)effect + 8 + j * 4));
                }
                FX_Print("^1FX Error, invalid primitive template for effect '%s'\n", name);
                return NULL;
            }
        }

        /* Add primitive to effect */
        count = *(int *)((byte *)effect + 4);
        if (count > 0x17) {
            FX_Print("^1FX Error, too many primitives in effect\n");
        } else {
            *(void **)((byte *)effect + 8 + count * 4) = prim;
            *(int *)((byte *)effect + 4) = count + 1;
        }

    next_group:
        primitiveGroup = *(void **)((byte *)primitiveGroup + 4);
        currentPrimitiveIndex++;
    }

    return effect;
}

/* line 129 */
EffectTemplate * FX_RegisterEffect(const char *fileName)
{
    char strippedFileName[64];
    EffectTemplate *result;

    if (*fileName == '/' || *fileName == '\\')
        fileName++;

    if (strnicmp(fileName, "fx/", 3) != 0) {
        FX_Print("Effect file '%s' must start with fx/.\n", fileName);
        return defaultEffect;
    }

    Com_StripExtension(fileName + 3, strippedFileName);
    strlwr(strippedFileName);

    result = FX_TryRegisterEffect(strippedFileName);
    if (result == NULL)
        return defaultEffect;

    return result;
}

/* line 657 */
float MediaHandles_AddEffect(const MediaHandles * _this, EffectTemplate *fx)
{
    byte *self = (byte *)_this;
    unsigned short count;
    unsigned short capacity;
    void *newElements;

    count = *(unsigned short *)(self + 4);
    capacity = *(unsigned short *)(self + 6);

    if (count == capacity) {
        if (count == 0) {
            *(unsigned short *)(self + 6) = 4;
        } else {
            *(unsigned short *)(self + 6) = count * 2;
        }
        newElements = Z_MallocInternal(*(unsigned short *)(self + 6) * 4);
        if (*(void **)self != NULL) {
            memcpy(newElements, *(void **)self, *(unsigned short *)(self + 4) * 4);
            Z_FreeInternal(*(void **)self);
        }
        *(void **)self = newElements;
    }

    ((void **)(*(void **)self))[*(unsigned short *)(self + 4)] = (void *)fx;
    *(unsigned short *)(self + 4) += 1;
}
