/* Decompiled from: com_memory.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/universal/com_memory.cpp */

#include "common_types.h"
#include "imports.h"

#include <string.h>
#include <stdlib.h>

extern void Com_Printf(const char *fmt, ...);
extern void Com_Error(int code, const char *fmt, ...);
extern void Com_Memset(void *dest, int val, int count);
extern void Sys_OutOfMemErrorInternal(const char *filename, int line);
extern void *VirtualAlloc(void *lpAddress, int dwSize, int flAllocationType, int flProtect);
extern int VirtualFree(void *lpAddress, int dwSize, int dwFreeType);
extern int FS_HashFileName(const char *fname, int hashSize);
extern int FS_LoadStack(void);
extern int stricmp(const char *s1, const char *s2);
extern void XModelPartsFree(void *data);
extern void XModelFree(void *data);
extern void XAnimFree(void *data);
extern void XAnimFreeList(void *data);
extern void Cmd_AddCommand(const char *cmdName, void (*function)());
extern dvar_t *Dvar_RegisterInt(const char *dvarName, int value, int min, int max, int flags);
extern int Sys_Milliseconds(void);

extern const dvar_t *com_dedicated; /* 0x0 */
static fileData_t * com_fileDataHashTable[1024]; /* com_fileDataHashTable */
static fileData_t *com_hunkData; /* com_hunkData */
static int g_largeLocalPos; /* g_largeLocalPos */
static byte g_largeLocalBuf[524288]; /* g_largeLocalBuf */
static struct hunkUsed_t hunk_low; /* hunk_low */
static hunkUsed_t hunk_high; /* hunk_high */
static byte *s_hunkData; /* s_hunkData */
static byte *s_origHunkData; /* s_origHunkData */
static int s_hunkTotal; /* s_hunkTotal */

/* forward declarations */
static void Hunk_ClearData(void);
static void Com_Meminfo_f(void);

/* Helper: round up to MB for error messages */
#define TO_MB(x) (((x) <= -1) ? (((x) + 0xfffff) >> 20) : ((x) >> 20))

/* Helper: remove a fileData node from the hunk range [low..high) and free its resources */
static void Hunk_ClearFileData(fileData_t **pFileData, byte *low, byte *high)
{
    fileData_t *fd;

    while ((fd = *pFileData) != 0) {
        if ((byte *)fd < low || (byte *)fd >= high) {
            pFileData = (fileData_t **)&fd->next;
            continue;
        }
        /* remove from list */
        *pFileData = (fileData_t *)fd->next;
        void *data = fd->data;

        switch (fd->type) {
        case 3:
            XModelPartsFree(data);
            break;
        case 4:
            XModelFree(data);
            break;
        case 5:
            XAnimFree(data);
            break;
        case 6:
            XAnimFreeList(data);
            break;
        default:
            break;
        }
    }
}

/* line 194 */
void Z_FreeInternal(void *ptr)
{
    free(ptr);
}

/* line 200 */
void Z_VirtualFreeInternal(void *ptr)
{
    VirtualFree(ptr, 0, 0x8000);
}

/* line 206 */
void Z_VirtualDecommitInternal(void *ptr, int size)
{
    VirtualFree(ptr, size, 0x4000);
}

/* line 475 */
void * Z_TryMallocInternal(int size)
{
    void *buf;

    buf = malloc(size);
    if (buf) {
        Com_Memset(buf, 0, size);
    }
    return buf;
}

/* line 486 */
void * Z_MallocInternal(int size)
{
    void *buf;

    buf = malloc(size);
    if (!buf) {
        Sys_OutOfMemErrorInternal("/Users/kevin/Development/i5works/COD2/Project/PC/universal/com_memory.cpp", 0xdc);
    }
    Com_Memset(buf, 0, size);
    return buf;
}

/* line 497 */
void * Z_MallocGarbageInternal(int size)
{
    void *buf;

    buf = malloc(size);
    if (!buf) {
        Sys_OutOfMemErrorInternal("/Users/kevin/Development/i5works/COD2/Project/PC/universal/com_memory.cpp", 0xdc);
    }
    return buf;
}

/* line 516 */
void * Z_VirtualAllocInternal(int size)
{
    void *buf;

    buf = VirtualAlloc(0, size, 0x1000, 4);
    if (!buf) {
        Sys_OutOfMemErrorInternal("/Users/kevin/Development/i5works/COD2/Project/PC/universal/com_memory.cpp", 0x20c);
    }
    return buf;
}

/* line 535 */
void * Z_VirtualReserveInternal(int size)
{
    return VirtualAlloc(0, size, 0x2000, 4);
}

/* line 541 */
void Z_VirtualCommitInternal(void *ptr, int size)
{
    if (!VirtualAlloc(ptr, size, 0x1000, 4)) {
        Sys_OutOfMemErrorInternal("/Users/kevin/Development/i5works/COD2/Project/PC/universal/com_memory.cpp", 0x225);
    }
}

/* line 565 */
char * CopyStringInternal(const char *in)
{
    int len;
    char *buf;

    len = strlen(in) + 1;
    buf = (char *)Z_MallocInternal(len);
    strcpy(buf, in);
    return buf;
}

/* line 581 */
void ReplaceStringInternal(char * *str, const char *in)
{
    int newLen;
    int oldLen;
    char *newStr;

    newLen = strlen(in);

    newStr = *str;
    if (newStr) {
        oldLen = strlen(newStr);
        if (oldLen >= newLen) {
            /* existing buffer is large enough, reuse it */
            strcpy(newStr, in);
            return;
        }
        free(newStr);
    }

    newStr = (char *)Z_MallocInternal(newLen + 1);
    *str = newStr;
    strcpy(newStr, in);
}

/* line 673 */
static void Com_Meminfo_f(void)
{
    Com_Printf("%8i bytes total hunk\n", s_hunkTotal);
    Com_Printf("\n");
    Com_Printf("%8i low permanent\n", hunk_low.permanent);
    if (hunk_low.temp != hunk_low.permanent) {
        Com_Printf("%8i low temp\n", hunk_low.temp);
    }
    Com_Printf("\n");
    Com_Printf("%8i high permanent\n", hunk_high.permanent);
    if (hunk_high.temp != hunk_high.permanent) {
        Com_Printf("%8i high temp\n", hunk_high.temp);
    }
    Com_Printf("\n");
    Com_Printf("%8i total hunk in use\n", hunk_low.permanent + hunk_high.permanent);
    Com_Printf("\n");
}

/* line 738 */
void Com_TouchMemory(void)
{
    int start;
    int i;
    int sum;
    int totalIntCount;
    int highStart;
    int highEnd;

    start = Sys_Milliseconds();

    sum = 0;
    totalIntCount = hunk_low.permanent >> 2;
    for (i = 0; i < totalIntCount; i += 64) {
        sum += ((int *)s_hunkData)[i];
    }

    highEnd = hunk_high.permanent >> 2;
    highStart = (s_hunkTotal - hunk_high.permanent) >> 2;
    for (i = highStart; i < highEnd; i += 64) {
        sum += ((int *)s_hunkData)[i];
    }

    Com_Printf("Com_TouchMemory: %i msec. Using sum: %d\n", Sys_Milliseconds() - start, sum);
}

/* line 797 */
void Com_InitHunkMemory(void)
{
    dvar_t *cv;
    int nMegs;

    if (FS_LoadStack() != 0) {
        Com_Error(0, "Hunk initialization failed. File system load stack not zero");
    }

    cv = Dvar_RegisterInt("com_hunkMegs", 0xa0, 1, 0x200, 0x1021);
    nMegs = cv->current.integer;
    if (nMegs <= 0x4f) {
        Com_Printf("Minimum com_hunkMegs for a dedicated server is %i, allocating %i megs.\n", 0x50, 0x50);
        s_hunkTotal = 0x5000000;
    } else {
        s_hunkTotal = nMegs << 20;
    }

    s_hunkData = (byte *)VirtualAlloc(0, s_hunkTotal, 0x1000, 4);
    if (!s_hunkData) {
        Sys_OutOfMemErrorInternal("/Users/kevin/Development/i5works/COD2/Project/PC/universal/com_memory.cpp", 0x34b);
    }

    s_origHunkData = s_hunkData;

    hunk_low.permanent = 0;
    hunk_low.temp = 0;
    hunk_high.permanent = 0;
    hunk_high.temp = 0;
    Hunk_ClearData();

    Cmd_AddCommand("meminfo", Com_Meminfo_f);
}

/* Helper: find a fileData node by type and name in the hash table */
static fileData_t * Hunk_FindFileData(int type, const char *name, int hash)
{
    fileData_t *fd;

    for (fd = com_fileDataHashTable[hash]; fd; fd = (fileData_t *)fd->next) {
        if (fd->type == (byte)type && !stricmp(fd->name, name)) {
            return fd;
        }
    }
    return 0;
}

/* line 924 */
void * Hunk_FindDataForFile(int type, const char *name)
{
    int hash;
    fileData_t *fd;

    hash = FS_HashFileName(name, 0x400);
    fd = Hunk_FindFileData(type, name, hash);
    if (fd) {
        return fd->data;
    }
    return 0;
}

/* line 939 */
qboolean Hunk_DataOnHunk(void *data)
{
    if ((byte *)data < s_hunkData) {
        return 0;
    }
    if ((byte *)data < s_hunkData + s_hunkTotal) {
        return 1;
    }
    return 0;
}

/* line 959 */
const char * Hunk_SetDataForFile(int type, const char *name, void *data, Alloc_t alloc)
{
    int hash;
    int nameLen;
    fileData_t *fd;

    hash = FS_HashFileName(name, 0x400);
    nameLen = strlen(name) + 1;
    fd = (fileData_t *)alloc(nameLen + 9);
    fd->data = data;
    fd->type = (byte)type;
    strcpy(fd->name, name);
    fd->next = (int)com_fileDataHashTable[hash];
    com_fileDataHashTable[hash] = fd;
    return fd->name;
}

/* line 991 */
void Hunk_AddData(int type, void *data, Alloc_t alloc)
{
    fileData_t *fd;

    fd = (fileData_t *)alloc(9);
    fd->data = data;
    fd->type = (byte)type;
    fd->next = (int)com_hunkData;
    com_hunkData = fd;
}

/* line 1017 */
void Hunk_OverrideDataForFile(int type, const char *name, void *data)
{
    int hash;
    fileData_t *fd;

    hash = FS_HashFileName(name, 0x400);
    for (fd = com_fileDataHashTable[hash]; fd; fd = (fileData_t *)fd->next) {
        if (fd->type == (byte)type && !stricmp(fd->name, name)) {
            fd->data = data;
            return;
        }
    }
}

/* line 1096 */
static void Hunk_ClearData(void)
{
    int hash;
    byte *low;
    byte *high;

    low = s_hunkData + hunk_low.permanent;
    high = s_hunkData + s_hunkTotal - hunk_high.permanent;

    for (hash = 0; hash < 1024; hash++) {
        Hunk_ClearFileData(&com_fileDataHashTable[hash], low, high);
    }
    Hunk_ClearFileData(&com_hunkData, low, high);
}

/* line 1167 */
void DB_EnumXAssets(int type, XAssetEnum func, void *inData, int includeOverride)
{
    int i;
    fileData_t *fd;

    if (type != 1) {
        return;
    }

    for (i = 0; i < 1024; i++) {
        for (fd = com_fileDataHashTable[i]; fd; fd = (fileData_t *)fd->next) {
            if (fd->type == 4) {
                func(fd->data, inData);
            }
        }
    }
}

/* line 1209 */
int Hunk_SetMark(void)
{
    return hunk_high.permanent;
}

/* line 1224 */
void Hunk_ClearToMark(int mark)
{
    hunk_high.temp = mark;
    hunk_high.permanent = mark;
    Hunk_ClearData();
}

/* line 1259 */
void Hunk_ClearToMarkLow(int mark)
{
    hunk_low.temp = mark;
    hunk_low.permanent = mark;
    Hunk_ClearData();
}

/* line 1280 */
void Hunk_Clear(void)
{
    hunk_low.permanent = 0;
    hunk_low.temp = 0;
    hunk_high.permanent = 0;
    hunk_high.temp = 0;
    Hunk_ClearData();
}

/* line 1306 */
int Hunk_Used(void)
{
    return hunk_low.permanent + hunk_high.permanent;
}

/* line 1331 */
void * Hunk_AllocInternal(int size)
{
    int newHighUsed;
    byte *buf;

    newHighUsed = (hunk_high.permanent + size + 31) & ~31;
    hunk_high.permanent = newHighUsed;
    buf = s_hunkData + s_hunkTotal - newHighUsed;
    hunk_high.temp = newHighUsed;

    if (s_hunkTotal < newHighUsed + hunk_low.temp) {
        Com_Error(1, "Hunk_AllocAlign failed on %i bytes (total %i MB, low %i MB, high %i MB)",
                  size, TO_MB(s_hunkTotal), TO_MB(hunk_low.temp), TO_MB(newHighUsed));
    }

    memset(buf, 0, size);
    return buf;
}

/* line 1344 */
void * Hunk_AllocNoZeroInternal(int size)
{
    int newHighUsed;
    byte *buf;

    newHighUsed = (hunk_high.permanent + size + 31) & ~31;
    hunk_high.permanent = newHighUsed;
    buf = s_hunkData + s_hunkTotal - newHighUsed;
    hunk_high.temp = newHighUsed;

    if (s_hunkTotal < newHighUsed + hunk_low.temp) {
        Com_Error(1, "Hunk_AllocAlign failed on %i bytes (total %i MB, low %i MB, high %i MB)",
                  size, TO_MB(s_hunkTotal), TO_MB(hunk_low.temp), TO_MB(newHighUsed));
    }

    return buf;
}

/* line 1415 */
void * Hunk_AllocAlignInternal(int size, int alignment)
{
    int newHighUsed;
    byte *buf;

    newHighUsed = (hunk_high.permanent + size + alignment - 1) & ~(alignment - 1);
    hunk_high.permanent = newHighUsed;
    buf = s_hunkData + s_hunkTotal - newHighUsed;
    hunk_high.temp = newHighUsed;

    if (s_hunkTotal < newHighUsed + hunk_low.temp) {
        Com_Error(1, "Hunk_AllocAlign failed on %i bytes (total %i MB, low %i MB, high %i MB)",
                  size, TO_MB(s_hunkTotal), TO_MB(hunk_low.temp), TO_MB(newHighUsed));
    }

    memset(buf, 0, size);
    return buf;
}

/* line 1478 */
void * Hunk_AllocateTempMemoryHighInternal(int size)
{
    int newTempHigh;

    newTempHigh = (hunk_high.temp + size + 15) & ~15;
    hunk_high.temp = newTempHigh;

    if (newTempHigh + hunk_low.temp > s_hunkTotal) {
        Com_Error(1, "Hunk_AllocateTempMemoryHigh: failed on %i bytes (total %i MB, low %i MB, high %i MB)",
                  size, TO_MB(s_hunkTotal), TO_MB(hunk_low.temp), TO_MB(newTempHigh));
    }

    return s_hunkData + s_hunkTotal - newTempHigh;
}

/* line 1519 */
void Hunk_ClearTempMemoryHigh(void)
{
    hunk_high.temp = hunk_high.permanent;
}

/* line 1548 */
void * Hunk_AllocLowInternal(int size)
{
    int aligned;
    byte *buf;
    int newLow;

    aligned = (hunk_low.permanent + 31) & ~31;
    buf = s_hunkData + aligned;
    newLow = aligned + size;
    hunk_low.permanent = newLow;
    hunk_low.temp = newLow;

    if (newLow + hunk_high.temp > s_hunkTotal) {
        Com_Error(1, "Hunk_AllocLowAlign failed on %i bytes (total %i MB, low %i MB, high %i MB)",
                  size, TO_MB(s_hunkTotal), TO_MB(newLow), TO_MB(hunk_high.temp));
    }

    memset(buf, 0, size);
    return buf;
}

/* line 1574 */
void * Hunk_AllocLowAlignInternal(int size, int alignment)
{
    int aligned;
    byte *buf;
    int newLow;

    aligned = (hunk_low.permanent + alignment - 1) & ~(alignment - 1);
    buf = s_hunkData + aligned;
    newLow = aligned + size;
    hunk_low.permanent = newLow;
    hunk_low.temp = newLow;

    if (newLow + hunk_high.temp > s_hunkTotal) {
        Com_Error(1, "Hunk_AllocLowAlign failed on %i bytes (total %i MB, low %i MB, high %i MB)",
                  size, TO_MB(s_hunkTotal), TO_MB(newLow), TO_MB(hunk_high.temp));
    }

    memset(buf, 0, size);
    return buf;
}

/* line 1634 */
void Hunk_ConvertTempToPermLowInternal(void)
{
    hunk_low.permanent = hunk_low.temp;
}

/* line 1659 */
void * Hunk_AllocateTempMemoryInternal(int size)
{
    int allocSize;
    int prevTemp;
    int aligned;
    byte *base;
    int newTemp;
    byte *buf;

    if (!s_hunkData) {
        /* No hunk memory, fall back to malloc */
        return Z_MallocInternal(size);
    }

    allocSize = size + 16;
    prevTemp = hunk_low.temp;
    aligned = (prevTemp + 15) & ~15;
    base = s_hunkData + aligned;
    newTemp = aligned + allocSize;
    hunk_low.temp = newTemp;

    if (newTemp + hunk_high.temp > s_hunkTotal) {
        Com_Error(1, "Hunk_AllocateTempMemory: failed on %i bytes (total %i MB, low %i MB, high %i MB), needs %i more hunk bytes",
                  allocSize, TO_MB(s_hunkTotal), TO_MB(newTemp), TO_MB(hunk_high.temp),
                  newTemp + hunk_high.temp - s_hunkTotal);
    }

    buf = base + 16;
    *(int *)base = 0x89537892; /* magic */
    *(int *)(base + 4) = hunk_low.temp - prevTemp;
    return buf;
}

/* line 1719 */
void * Hunk_ReallocateTempMemoryInternal(int size)
{
    int aligned;
    byte *buf;
    int newTemp;

    aligned = (hunk_low.permanent + 31) & ~31;
    buf = s_hunkData + aligned;
    newTemp = aligned + size;
    hunk_low.temp = newTemp;

    if (newTemp + hunk_high.temp > s_hunkTotal) {
        Com_Error(1, "Hunk_ReallocateTempMemory: failed on %i bytes (total %i MB, low %i MB, high %i MB)",
                  size, TO_MB(s_hunkTotal), TO_MB(newTemp), TO_MB(hunk_high.temp));
    }

    return buf;
}

/* line 1753 */
void Hunk_FreeTempMemory(void *buf)
{
    byte *hdr;

    if (!s_hunkData) {
        free(buf);
        return;
    }

    hdr = (byte *)buf - 16;
    if (*(int *)hdr != 0x89537892) {
        Com_Error(0, "Hunk_FreeTempMemory: bad magic");
    }
    *(int *)hdr = 0x89537893; /* mark as freed */
    hunk_low.temp -= *(int *)(hdr + 4);
}

/* line 1791 */
void Hunk_ClearTempMemory(void)
{
    if (s_hunkData) {
        hunk_low.temp = hunk_low.permanent;
    }
}

/* line 1839 */
int Hunk_HideTempMemory(void)
{
    int mark;

    mark = hunk_low.permanent;
    hunk_low.permanent = hunk_low.temp;
    return mark;
}

/* line 1857 */
void Hunk_ShowTempMemory(int mark)
{
    hunk_low.permanent = mark;
}

/* line 1952 */
void LargeLocal_LargeLocal(const LargeLocal * _this, int size)
{
    int pos;

    pos = g_largeLocalPos;
    size = (size + 3) & ~3;
    g_largeLocalPos = pos + size;
    ((LargeLocal *)_this)->_placeholder = pos;
}

/* line 1965 */
/* LargeLocal::~LargeLocal - mangled name preserved for linking */
void ZN10LargeLocalD1Ev(LargeLocal *_this)
{
    g_largeLocalPos = _this->_placeholder;
}

/* line 1978 */
void * LargeLocal_GetBuf(const LargeLocal * _this)
{
    return g_largeLocalBuf + _this->_placeholder;
}

/* line 1991 */
void LargeLocalReset(void)
{
    g_largeLocalPos = 0;
}
