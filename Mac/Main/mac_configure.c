/* Converted to C from ASM: mac_configure.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Main/mac_configure.cpp */

#include "common_types.h"
#include "imports.h"

extern float MacFeatures_GetCPUSpeedInGHz(void);
extern int MacFeatures_GetMemorySizeInMB(void);
extern const char *MacDisplay_GetGLRenderer(void);
extern bool MacFeatures_HasGestaltAttribute(unsigned int selector, int bit);

double Sys_CpuGHz(void)
{
    return (double)MacFeatures_GetCPUSpeedInGHz();
}

int Sys_SystemMemoryMB(void)
{
    int mem = MacFeatures_GetMemorySizeInMB();
    if (mem >= 0x8000001)
        mem = 0x8000000;
    return mem;
}

float Sys_DetectVideoCard(int descLimit, char *description)
{
    const char *renderer = MacDisplay_GetGLRenderer();
    strncpy(description, renderer, descLimit);
}

bool Sys_SupportsSSE(void)
{
    return MacFeatures_HasGestaltAttribute(0x78383666, 0x19) != 0;
}
