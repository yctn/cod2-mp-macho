/* Converted to C from ASM: r_caps.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_caps.cpp */

#include "common_types.h"
#include "imports.h"

extern void MacDisplay_GetVideoMemoryInfo(int *videoMemory, int *textureMemory);
extern void R_Error(int level, const char *fmt, ...);
extern refimport_t ri; /* imp_ri */

static const DxCapsCheckBits s_capsCheckBits[36]; /* s_capsCheckBits */
static const DxCapsCheckInteger s_capsCheckInt[8]; /* s_capsCheckInt */

static void R_HandleCapsResponse(int response, const char *msg, int *allowedPaths)
{
    int printLevel;

    if (response == 1 || response == 3) {
        printLevel = 2;
    } else {
        printLevel = 0;
    }

    typedef void (*PrintfFn)(int, const char *, ...);
    ((PrintfFn)ri.Printf)(printLevel, "Video card or driver %s.\n", msg);

    if (response == 3) {
        *allowedPaths &= ~4;
        ((PrintfFn)ri.Printf)(printLevel, "  Disabling DirectX 9.0c codepath.\n");
    } else if (response == 4) {
        *allowedPaths &= ~2;
        ((PrintfFn)ri.Printf)(printLevel, "  Disabling DirectX 9.0b codepath.\n");
    } else if (response == 0) {
        R_Error(0, "Video card or driver %s.\n", msg);
    }
}

int R_CheckDxCaps(const D3DCAPS9 *caps)
{
    int videoMemory;
    int textureMemory;

    MacDisplay_GetVideoMemoryInfo(&videoMemory, &textureMemory);

    int allowedPaths;
    if (videoMemory >= 0x4000001) {
        allowedPaths = 6; /* 4 + 2: both DX9c and DX9b paths */
    } else {
        allowedPaths = 4; /* DX9c only */
    }

    /* Check bits-based caps */
    int i;
    for (i = 0; i < 36; i++) {
        int capsOffset = *(int *)((byte *)&s_capsCheckBits[i]);
        int requiredBits = *(int *)((byte *)&s_capsCheckBits[i] + 4);
        int disallowedBits = *(int *)((byte *)&s_capsCheckBits[i] + 8);
        int response = *(int *)((byte *)&s_capsCheckBits[i] + 0xc);
        const char *msg = *(const char **)((byte *)&s_capsCheckBits[i] + 0x10);

        /* Skip empty table entries (uninitialized data) */
        if (requiredBits == 0 && disallowedBits == 0)
            continue;

        int capsValue = *(int *)((byte *)caps + capsOffset);

        /* Check disallowed bits */
        if (disallowedBits != 0) {
            if ((~capsValue & disallowedBits) == 0)
                continue;
        }

        /* Check required bits */
        if (requiredBits != 0) {
            if ((capsValue & requiredBits) == 0)
                continue;
        }

        R_HandleCapsResponse(response, msg, &allowedPaths);
    }

    /* Check integer-range caps */
    for (i = 0; i < 8; i++) {
        int capsOffset = *(int *)((byte *)&s_capsCheckInt[i]);
        int minVal = *(int *)((byte *)&s_capsCheckInt[i] + 4);
        int maxVal = *(int *)((byte *)&s_capsCheckInt[i] + 8);
        int response = *(int *)((byte *)&s_capsCheckInt[i] + 0xc);
        const char *msg = *(const char **)((byte *)&s_capsCheckInt[i] + 0x10);

        /* Skip empty table entries (uninitialized data) */
        if (minVal == 0 && maxVal == 0 && response == 0)
            continue;

        int capsValue = *(int *)((byte *)caps + capsOffset);

        /* Value must be in range [minVal, maxVal] */
        if (capsValue >= minVal && capsValue <= maxVal)
            continue;

        R_HandleCapsResponse(response, msg, &allowedPaths);
    }

    return allowedPaths;
}
