/* Converted to C from ASM: win_shared.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/win32/win_shared.cpp */

#include "common_types.h"
#include "imports.h"

extern int timeGetTime(void);

extern int sys_timeBase; /* 0x0 */
static qboolean initialized; /* 0x4ed800 */

int Sys_Milliseconds(void)
{
    if (!initialized) {
        sys_timeBase = timeGetTime();
        initialized = 1;
    }
    return timeGetTime() - sys_timeBase;
}

int Sys_MillisecondsRaw(void)
{
    return timeGetTime();
}

void Sys_SnapVector(float *v)
{
    v[0] = (float)(int)v[0];
    v[1] = (float)(int)v[1];
    v[2] = (float)(int)v[2];
}
