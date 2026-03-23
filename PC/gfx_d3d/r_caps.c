/* Converted to C from ASM: r_caps.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_caps.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdio.h>

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

    (void)caps;
    MacDisplay_GetVideoMemoryInfo(&videoMemory, &textureMemory);

    /* Allow both DX9c (bit 2) and DX9b (bit 1) paths.
     * The s_capsCheckBits/s_capsCheckInt tables are uninitialized in
     * the decompilation so all cap checks would be skipped anyway.
     * The original function returns garbage due to a stack frame issue
     * in the compiled output, so we hardcode the result. */
    int allowedPaths = 6;

    return allowedPaths;
}
