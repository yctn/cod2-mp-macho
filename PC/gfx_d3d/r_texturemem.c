/* Converted to C from ASM: r_texturemem.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_texturemem.cpp */

#include "common_types.h"
#include "imports.h"

extern void MacDisplay_GetVideoMemoryInfo(int *vidMemMB, int *totalVidMem);

extern char *d3d_context; /* 0x195eed0 */
extern void (**r_import)(); /* 0x195eee0 */

unsigned int R_AvailableTextureMemory(void)
{
    int vidMemInMegs;
    int vidMem2;
    unsigned int texMemInMegs;
    void (*r_printf)(int, const char *, ...) = (void (*)(int, const char *, ...))r_import[0];

    MacDisplay_GetVideoMemoryInfo(&vidMemInMegs, &vidMem2);

    /* IDirect3DDevice9::GetAvailableTextureMem() via vtable */
    char *device = *(char **)(d3d_context + 8);
    void **vtable = *(void ***)device;
    unsigned int texMem = ((unsigned int (*)(void *))vtable[4])(device);
    texMemInMegs = texMem >> 20;

    if (vidMemInMegs == 0) {
        r_printf(0, "DirectX reports %i MB of available texture memory, but wouldn't tell available video memory.\n", texMemInMegs);
    } else {
        r_printf(0, "DirectX reports %i MB of video memory and %i MB of available texture memory.\n", vidMemInMegs, texMemInMegs);
        if ((unsigned int)vidMemInMegs < texMemInMegs) {
            texMemInMegs = vidMemInMegs - 16;
            r_printf(0, "Using video memory size to cap used texture memory at %i MB.\n", texMemInMegs);
        }
    }
    return texMemInMegs;
}
