/* Converted to C from ASM: mac_configure.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Main/mac_configure.cpp */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common_types.h"
#include "imports.h"

double Sys_CpuGHz(void)
{
    /* Read from /proc/cpuinfo on Linux */
    FILE *f = fopen("/proc/cpuinfo", "r");
    char line[256];
    double mhz = 1000.0;

    if (f) {
        while (fgets(line, sizeof(line), f)) {
            if (strncmp(line, "cpu MHz", 7) == 0) {
                char *p = strchr(line, ':');
                if (p) {
                    mhz = atof(p + 1);
                }
                break;
            }
        }
        fclose(f);
    }
    return mhz / 1000.0;
}

int Sys_SystemMemoryMB(void)
{
    /* Read from /proc/meminfo on Linux */
    FILE *f = fopen("/proc/meminfo", "r");
    char line[256];
    long kb = 512 * 1024; /* default 512 MB */

    if (f) {
        while (fgets(line, sizeof(line), f)) {
            if (strncmp(line, "MemTotal:", 9) == 0) {
                kb = atol(line + 9);
                break;
            }
        }
        fclose(f);
    }

    int mb = (int)(kb / 1024);
    /* Cap at 128 GB to match original behavior */
    if (mb >= 0x8000001)
        mb = 0x8000000;
    return mb;
}

float Sys_DetectVideoCard(int descLimit, char *description)
{
    /* Try to read GL renderer from /proc or glxinfo */
    const char *renderer = "Linux OpenGL";
    strncpy(description, renderer, descLimit);
    description[descLimit - 1] = '\0';
    return 0;
}

bool Sys_SupportsSSE(void)
{
    /* All modern x86 CPUs support SSE */
    return 1;
}
