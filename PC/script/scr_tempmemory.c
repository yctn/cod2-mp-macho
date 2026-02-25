/* Converted to C from ASM: scr_tempmemory.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/script/scr_tempmemory.cpp */

#include "common_types.h"
#include "imports.h"

extern char *Hunk_ReallocateTempMemoryInternal(int minimumSize);

static int currentPos; /* 0x7ef480 */

void TempMemoryReset(void)
{
    currentPos = 0;
}

char *TempMalloc(int len)
{
    int newCurrentPos;
    char *base;

    newCurrentPos = currentPos + len;
    base = Hunk_ReallocateTempMemoryInternal(newCurrentPos);
    base += currentPos;
    currentPos = newCurrentPos;
    return base;
}

char *TempMallocAlign(int len)
{
    int newCurrentPos;
    char *base;

    newCurrentPos = currentPos + len;
    base = Hunk_ReallocateTempMemoryInternal(newCurrentPos);
    base += currentPos;
    currentPos = newCurrentPos;
    return base;
}

char *TempMallocAlignStrict(int len)
{
    int newCurrentPos;
    char *base;

    newCurrentPos = currentPos + len;
    base = Hunk_ReallocateTempMemoryInternal(newCurrentPos);
    base += currentPos;
    currentPos = newCurrentPos;
    return base;
}

void TempMemorySetPos(char *pos)
{
    char *base;

    base = Hunk_ReallocateTempMemoryInternal(currentPos);
    base += currentPos;
    currentPos -= (int)(base - pos);
    Hunk_ReallocateTempMemoryInternal(currentPos);
}
