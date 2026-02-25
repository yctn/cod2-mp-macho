/* Converted to C from ASM: mac_splash.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Main/mac_splash.cpp */

#include "common_types.h"
#include "imports.h"

extern void CMacGameEngine_DrawSplashScreen(const char *imageName);

void Sys_CreateSplashWindow(void)
{
}

void Sys_DestroySplashWindow(void)
{
}

void Sys_ShowSplashWindow(void)
{
    CMacGameEngine_DrawSplashScreen("cod.png");
}

void Sys_HideSplashWindow(void)
{
}
