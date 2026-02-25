/* Converted to C from ASM: win_threads.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/win32/win_threads.cpp */

#include "common_types.h"
#include "imports.h"

extern DWORD GetCurrentThreadId(void);
extern void Com_InitThreadData(int index);

static void *g_threadValues[5]; /* 0x334f00 */
static DWORD threadId[1]; /* 0x334f14 */

void Sys_InitMainThread(void)
{
    threadId[0] = GetCurrentThreadId();
    Com_InitThreadData(0);
}

Bool Sys_IsMainThread(void)
{
    return GetCurrentThreadId() == threadId[0];
}

void Sys_SetValue(int valueIndex, void *data)
{
    g_threadValues[valueIndex] = data;
}

void *Sys_GetValue(int valueIndex)
{
    return g_threadValues[valueIndex];
}
