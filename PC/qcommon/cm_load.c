/* Converted to C from ASM: cm_load.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/cm_load.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

extern int stricmp(const char *s1, const char *s2);
extern void CM_LoadMapFromBsp(const char *name, int flag);
extern void CM_LoadStaticModels(void);
extern void *Hunk_AllocInternal(int size);
extern void Com_Error(int level, const char *fmt, ...);
extern void Com_Memset(void *dest, int val, int count);
extern void *CM_ClipHandleToModel(clipHandle_t handle);
extern int FS_FOpenFileRead(const char *filename, int *file, int uniqueFile);
extern int FS_Read(void *buffer, int len, int f);
extern void FS_FCloseFile(int f);
extern int FS_Write(const void *buffer, int len, int h);
extern int FS_OpenFileOverwrite(const char *filename);
extern void *Z_MallocInternal(int size);
extern void Z_FreeInternal(void *ptr);
extern int FS_ReadFile(const char *filename, void **buffer);
extern int Com_BlockChecksum(const void *buffer, int length);
extern void FS_FreeFile(void *buffer);
extern void *Hunk_AllocateTempMemoryHighInternal(int size);
extern void Hunk_ClearTempMemory(void);
extern void Hunk_ClearTempMemoryHigh(void);

extern byte *cm_phys_ptr; /* imp_g_traceThreadInfo */

extern struct clipMap_t cm; /* 0x0 */

void CM_LoadMap(const char *name, int *checksum);
void CM_Shutdown(void);
int CM_NumInlineModels(void);
const char * CM_EntityString(void);
int CM_LeafCluster(int leafnum);
void * CM_Hunk_Alloc(int size, const char *name, int type);
void CM_Hunk_CheckTempMemoryClear(void);
void CM_Hunk_CheckTempMemoryHighClear(void);
void * CM_Hunk_AllocateTempMemoryHigh(int size, const char *name);
void CM_Hunk_ClearTempMemory(void);
void CM_Hunk_ClearTempMemoryHigh(void);
void CM_ModelBounds(clipHandle_t model, vec_t *mins, vec_t *maxs);
void CM_SaveLump(int lumpnum, byte *newLump, int size, int *checksum);

/* line 144 */
void CM_LoadMap(const char *name, int *checksum)
{
    byte *cm_base = (byte *)&cm;
    byte *phys;
    void *alloc;
    byte *src;

    if (name == NULL || *name == '\0') {
        Com_Error(1, "CM_LoadMap: NULL name");
    }

    if (*(char **)cm_base != NULL) {
        if (stricmp(*(char **)cm_base, name) == 0) {
            *checksum = *(int *)(cm_base + 0x10c);
            return;
        }
    }

    CM_LoadMapFromBsp(name, 1);
    CM_LoadStaticModels();

    phys = *(byte **)cm_phys_ptr;
    *(int *)phys = 0;

    alloc = Hunk_AllocInternal(*(int *)(cm_base + 0x64) * 2);
    *(void **)(phys + 0xc) = alloc;

    alloc = Hunk_AllocInternal(*(int *)(cm_base + 0x4c) * 4);
    *(void **)(phys + 4) = alloc;

    alloc = Hunk_AllocInternal(*(int *)(cm_base + 0x44) * 4);
    *(void **)(phys + 8) = alloc;

    alloc = Hunk_AllocInternal(0x30);
    *(void **)(phys + 0x10) = alloc;
    src = *(byte **)(cm_base + 0x9c);
    memcpy(alloc, src, 0x30);

    alloc = Hunk_AllocInternal(0x48);
    *(void **)(phys + 0x14) = alloc;
    memcpy(alloc, cm_base + 0xa0, 0x48);

    *checksum = *(int *)(cm_base + 0x10c);
}

/* line 165 */
void CM_Shutdown(void)
{
    Com_Memset(&cm, 0, 0x110);
}

/* line 303 */
int CM_NumInlineModels(void)
{
    byte *cm_base = (byte *)&cm;
    return *(int *)(cm_base + 0x74);
}

/* line 309 */
const char * CM_EntityString(void)
{
    byte *cm_base = (byte *)&cm;
    return *(const char **)(cm_base + 0x98);
}

/* line 316 */
int CM_LeafCluster(int leafnum)
{
    byte *cm_base = (byte *)&cm;
    byte *leaves = *(byte **)(cm_base + 0x28);
    return *(short *)(leaves + leafnum * 44 + 0x28);
}

/* line 349 */
void * CM_Hunk_Alloc(int size, const char *name, int type)
{
    return Hunk_AllocInternal(size);
}

/* line 360 */
void CM_Hunk_CheckTempMemoryClear(void)
{
}

/* line 371 */
void CM_Hunk_CheckTempMemoryHighClear(void)
{
}

/* line 382 */
void * CM_Hunk_AllocateTempMemoryHigh(int size, const char *name)
{
    return Hunk_AllocateTempMemoryHighInternal(size);
}

/* line 393 */
void CM_Hunk_ClearTempMemory(void)
{
    Hunk_ClearTempMemory();
}

/* line 404 */
void CM_Hunk_ClearTempMemoryHigh(void)
{
    Hunk_ClearTempMemoryHigh();
}

/* line 332 */
void CM_ModelBounds(clipHandle_t model, vec_t *mins, vec_t *maxs)
{
    byte *cmod;

    cmod = (byte *)CM_ClipHandleToModel(model);

    /* VectorCopy cmod+0 to mins */
    *(int *)&mins[0] = *(int *)(cmod);
    *(int *)&mins[1] = *(int *)(cmod + 4);
    *(int *)&mins[2] = *(int *)(cmod + 8);

    /* VectorCopy cmod+0xc to maxs */
    *(int *)&maxs[0] = *(int *)(cmod + 0xc);
    *(int *)&maxs[1] = *(int *)(cmod + 0x10);
    *(int *)&maxs[2] = *(int *)(cmod + 0x14);
}

/* line 206 */
void CM_SaveLump(int lumpnum, byte *newLump, int size, int *checksum)
{
    int h;
    byte *buf;
    int length;
    byte header[0x140];
    byte oldHeader[0x140];
    int zero;
    int offset;
    int i;
    int lumpSize;
    int padding;
    byte *data;

    length = FS_FOpenFileRead(*(char **)&cm, &h, 0);
    if (h == 0) {
        Com_Error(1, "EXE_ERR_COULDNT_LOAD%s", *(char **)&cm);
    }

    buf = (byte *)Z_MallocInternal(length + 1);
    FS_Read(buf, length, h);
    buf[length] = '\0';
    FS_FCloseFile(h);

    memcpy(header, buf, 0x140);

    if (*(int *)(header + 4) != 4 && *(int *)(header + 4) != 0x3d) {
        Com_Error(1, "bad bsp version %d", *(int *)(header + 4));
    }

    memcpy(oldHeader, header, 0x140);

    h = FS_OpenFileOverwrite(*(char **)&cm);
    if (h == 0) {
        Com_Error(1, "Failed to open file %s for writing", *(char **)&cm);
    }

    /* Rebuild lump offsets with updated size */
    offset = 0x140;
    for (i = 0; i < 39; i++) {
        if (i == lumpnum) {
            *(int *)(header + 8 + i * 8) = size;
        }
        *(int *)(header + 0xc + i * 8) = offset;
        lumpSize = *(int *)(header + 8 + i * 8);
        offset += (lumpSize + 3) & ~3;
    }

    /* Write new header */
    FS_Write(header, 0x140, h);

    /* Write each lump's data */
    zero = 0;
    for (i = 0; i < 39; i++) {
        lumpSize = *(int *)(header + 8 + i * 8);
        if (lumpSize == 0)
            continue;

        if (i == lumpnum) {
            data = newLump;
        } else {
            data = buf + *(int *)(oldHeader + 0xc + i * 8);
        }

        FS_Write(data, lumpSize, h);

        padding = ((lumpSize + 3) & ~3) - lumpSize;
        if (padding > 0) {
            FS_Write(&zero, padding, h);
        }
    }

    FS_FCloseFile(h);
    Z_FreeInternal(buf);

    if (checksum != NULL) {
        int fileLen;
        fileLen = FS_ReadFile(*(char **)&cm, (void **)&buf);
        *checksum = Com_BlockChecksum(buf, fileLen);
        FS_FreeFile(buf);
    }
}
