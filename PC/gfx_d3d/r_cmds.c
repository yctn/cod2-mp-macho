/* Converted to C from ASM: r_cmds.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_cmds.cpp */

#include "common_types.h"
#include "imports.h"

extern void R_ScreenshotCommand(int type);
extern void Material_UpdatePicmipAll(void);

extern void (**r_import)(); /* 0x195eee0 */
extern void (*R_ImageList_f)(void); /* 0x195f1ec */
extern void (*R_ReloadMaterialTextures_f)(void); /* 0x195f1e8 */
extern void (*R_LoadSun_f)(void); /* 0x195f1f0 */
extern void (*R_SaveSun_f)(void); /* 0x195f1dc */
extern void (*R_SmcStats_f)(void); /* 0x195f1e0 */
extern void (*R_SmcFlush_f)(void); /* 0x195f1e4 */

static void R_Cmd_ApplyPicmip(void)
{
    Material_UpdatePicmipAll();
}

static void R_Cmd_Screenshot(void)
{
    R_ScreenshotCommand(1);
}

static void R_Cmd_ScreenshotJpeg(void)
{
    R_ScreenshotCommand(0);
}

void R_RegisterCmds(void)
{
    void (*addCmd)(const char *, void (*)(void)) = (void (*)(const char *, void (*)(void)))r_import[0xf8 / 4];
    addCmd("screenshot", R_Cmd_Screenshot);
    addCmd("screenshotJpeg", R_Cmd_ScreenshotJpeg);
    addCmd("imagelist", R_ImageList_f);
    addCmd("r_applyPicmip", R_Cmd_ApplyPicmip);
    addCmd("reloadmaterialtextures", R_ReloadMaterialTextures_f);
    addCmd("r_loadsun", R_LoadSun_f);
    addCmd("r_savesun", R_SaveSun_f);
    addCmd("r_smc_stats", R_SmcStats_f);
    addCmd("r_smc_flush", R_SmcFlush_f);
}

void R_UnregisterCmds(void)
{
    void (*removeCmd)(const char *) = (void (*)(const char *))r_import[0xfc / 4];
    removeCmd("r_applyPicmip");
    removeCmd("r_vc_stats");
    removeCmd("screenshot");
    removeCmd("screenshotJpeg");
    removeCmd("imagelist");
    removeCmd("reloadmaterialtextures");
    removeCmd("r_loadsun");
    removeCmd("r_savesun");
    removeCmd("r_smc_stats");
    removeCmd("r_smc_flush");
}
