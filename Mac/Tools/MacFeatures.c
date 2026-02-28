/* Converted to C from ASM: MacFeatures.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacFeatures.cp */
/* Linux replacement: reads /proc for CPU/memory info */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common_types.h"
#include "imports.h"

SInt16 MacFeatures_GetSystemVersion(void)
{
    /* Return 10.4 (Tiger) equivalent */
    return 0x1040;
}

Boolean MacFeatures_HasGestaltAttribute(OSType inSelector, UInt32 inAttribute)
{
    /* SSE check (selector 'x86f', attribute 0x19) */
    if (inSelector == 0x78383666 && inAttribute == 0x19) {
        return 1; /* All modern x86 have SSE */
    }
    return 0;
}

Boolean MacFeatures_IsAltiVecAvailable(UInt8 *outMajor, UInt8 *outMinor, UInt8 *outBug)
{
    /* AltiVec is PowerPC only - not available on x86 Linux */
    return 0;
}

float MacFeatures_GetCPUSpeedInGHz(void)
{
    FILE *f = fopen("/proc/cpuinfo", "r");
    char line[256];
    float mhz = 800.0f;

    if (f) {
        while (fgets(line, sizeof(line), f)) {
            if (strncmp(line, "cpu MHz", 7) == 0) {
                char *p = strchr(line, ':');
                if (p) {
                    mhz = (float)atof(p + 1);
                }
                break;
            }
        }
        fclose(f);
    }
    return mhz / 1000.0f;
}

UInt32 MacFeatures_GetMemorySizeInMB(void)
{
    FILE *f = fopen("/proc/meminfo", "r");
    char line[256];
    unsigned long kb = 128 * 1024;

    if (f) {
        while (fgets(line, sizeof(line), f)) {
            if (strncmp(line, "MemTotal:", 9) == 0) {
                kb = strtoul(line + 9, NULL, 10);
                break;
            }
        }
        fclose(f);
    }
    return (UInt32)(kb / 1024);
}
