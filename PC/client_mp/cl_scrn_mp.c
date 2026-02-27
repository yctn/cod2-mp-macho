/* Decompiled from: cl_scrn_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/client_mp/cl_scrn_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#define stricmp strcasecmp

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

extern qboolean scr_initialized; /* 0x0 */
extern Bool updateScreenCalled; /* 0x0 */
static const char * szShotName[6]; /* 0x312604 */

/* Global pointers */
extern byte *re_ptr_195eca8;     /* 0x195eca8 - renderer export function table */
extern byte *cls_ptr_195ecac;    /* 0x195ecac - pointer to clientStatic_t */
extern byte *dvar_ptr_195ee78;   /* 0x195ee78 - dvar pointer (cl_paused/sv_running) */
extern byte *clc_ptr_195ee8c;    /* 0x195ee8c - client connection pointer */
extern byte *ptr_195eea4;        /* 0x195eea4 - loading/rendering guard */
extern byte *ptr_195f58c;        /* 0x195f58c - material handle */
extern byte *ptr_195f5e0;        /* 0x195f5e0 - net profile struct */

/* Renderer function table call helpers */
typedef void (*re_void_func)(void);
typedef void (*re_int_func)(int);
typedef void (*re_int2_func)(int, int);
typedef void (*re_int4_func)(int, int, int, int);
typedef void (*re_floatp_func)(float *);
typedef float (*re_font_height_func)(int, float);
typedef int (*re_font_iheight_func)(int);
typedef void (*re_draw_string_func)(const char *, int, int, float, float, float, float, const float *, int);
typedef void (*re_draw_console_func)(const short int *, int, int, float, float, float, float, const float *, int);
typedef void (*re_write_cubemap_func)(const char *, int, float, float);

#define RE_FUNC(re, offset, type) ((type)(*(void **)((byte *)(re) + (offset))))

/* clientStatic_t field offsets */
#define CLS_CONSOLE_FONT(base) (*(int *)((base) + 0x2a0a60))
#define CLS_CONN_STATE_FLAG(base) (*(int *)((base) + 0x110))
#define CLS_CLIENT_TIME(base) (*(int *)((base) + 0x118))

/* Extern function declarations */
extern void Com_Printf(const char *fmt, ...);
extern void Com_Error(int code, const char *fmt, ...);
extern int Cmd_Argc(void);
extern const char *Cmd_Argv(int arg);
extern const char *va(const char *fmt, ...);
extern int CG_DrawActiveFrame(int serverTime, int needRender, int side, int size, int serverDemo);
extern float UI_GetBlurRadius(void);
extern void UI_Refresh(void);
extern int UI_IsFullscreen(void);
extern void UI_DrawConnectScreen(void);
extern void UI_SetActiveMenu(int menu);
extern void UI_UpdateTime(int time);
extern void CL_ClearScene(void);
extern void CL_ResetSkeletonCache(int flags);
extern void CL_SendCmdInternal(void);
extern qboolean CL_AnyLocalClientChallenging(void);
extern void CL_DrawLogo(void);
extern void CL_LookupColor(int colorIndex, float *outColor);
extern void Con_DrawConsole(void);
extern void SND_StopSounds(int flags);
extern void SCR_DrawCinematic(void);
extern qboolean Sys_IsMainThread(void);
extern void Sys_LoadingKeepAlive(void);
extern void Net_DisplayProfile(void);
extern int FS_FTell(int fh);
extern float CalcScreenPlacement(float *x, float *y, float *w, float *h, int horzAlign, int vertAlign);

void SCR_DrawSmallStringExt(int x, int y, const char *string, const vec_t *setColor);
void SCR_DrawConsoleString(int x, int y, const short int *string, int maxChars, const vec_t *setColor);
void SCR_Init(void);
float CL_GetMenuBlurRadius(void);
static void CL_CubemapShotUsage(void);
void CL_CubemapShot_f(void);
static void SCR_UpdateFrame(void);
void SCR_UpdateScreenInternal(void);
void SCR_UpdateScreen(void);

/* line 77 */
void SCR_DrawSmallStringExt(int x, int y, const char *string, const vec_t *setColor)
{
    byte *re = re_ptr_195eca8;
    byte *cls = cls_ptr_195ecac;
    int font = CLS_CONSOLE_FONT(cls);

    int fontHeight = RE_FUNC(re, 0x118, re_font_iheight_func)(font);

    RE_FUNC(re, 0x11c, re_draw_string_func)(
        string, 0x7fffffff, font, (float)x, (float)y + (float)fontHeight,
        1.0f, 1.0f, setColor, 0);
}

/* line 96 */
void SCR_DrawConsoleString(int x, int y, const short int *string, int maxChars, const vec_t *setColor)
{
    byte *re = re_ptr_195eca8;
    byte *cls = cls_ptr_195ecac;
    int font = CLS_CONSOLE_FONT(cls);

    int fontHeight = RE_FUNC(re, 0x118, re_font_iheight_func)(font);

    RE_FUNC(re, 0x128, re_draw_console_func)(
        string, maxChars, font, (float)x, (float)y + (float)fontHeight,
        1.0f, 1.0f, setColor, 0);
}

/* line 140 */
void SCR_Init(void)
{
    scr_initialized = 1;
}

/* line 302 */
float CL_GetMenuBlurRadius(void)
{
    byte *dvar = *(byte **)dvar_ptr_195ee78;
    if (!(*(byte *)(dvar + 4) & 8))
        return 0.0f;

    byte *cls = cls_ptr_195ecac;
    if (CLS_CONN_STATE_FLAG(cls) == 0)
        return 0.0f;

    byte *clc = *(byte **)clc_ptr_195ee8c;
    if (*(int *)clc == 1)
        return 0.0f;

    return UI_GetBlurRadius();
}

/* line 451 */
static void CL_CubemapShotUsage(void)
{
    Com_Printf("Syntax: cubemapShot size basefilename [water r0 g0 b0 r90 g90 b90 | fresnel n0 n1]\n");
    Com_Printf("size must be a power of 2 >= 4 and <= 1024\n");
    Com_Printf("screenshots will be written to 'env/basefilename_*.tga'\n");
    Com_Printf("basefilename must not exceed %i chars\n", 40);
    Com_Printf("If 'water' is specified, a diffuse water color cubemap is generated using local lighting.\n");
    Com_Printf("The water has the given colors at the given angles, and blends between them in the middle.\n");
    Com_Printf("If 'fresnel' is specified, the alpha channel of the cubemap contains the reflection factor.\n");
    Com_Printf("n0 and n1 are the index of refraction of the 'air' and 'water' surfaces, respectively.\n");
    Com_Printf("The index of refraction must always be 1 or greater.\n");
    Com_Printf("This is always calculated, and defaults to air-water interface (n0 = 1, n1 = 1.333).\n");
}

/* line 471 */
void CL_CubemapShot_f(void)
{
    char szBaseName[100];
    float rgb[3];
    float n0, n1;
    byte isLightingShot;
    int side;

    byte *dvar = *(byte **)dvar_ptr_195ee78;
    if (*(byte *)(dvar + 9) == 0) {
        Com_Printf("must be in a map to use this command\n");
        return;
    }

    if (Cmd_Argc() <= 2) {
        CL_CubemapShotUsage();
        return;
    }

    const char *baseArg = Cmd_Argv(2);
    if (strlen(baseArg) > 40) {
        CL_CubemapShotUsage();
        return;
    }

    strcpy(szBaseName, Cmd_Argv(2));
    int size = atoi(Cmd_Argv(1));

    if ((unsigned int)(size - 4) > 0x3fc) {
        CL_CubemapShotUsage();
        return;
    }
    if ((size - 1) & size) {
        CL_CubemapShotUsage();
        return;
    }

    rgb[0] = 0.0f;
    rgb[1] = 0.0f;
    rgb[2] = 0.0f;

    if (Cmd_Argc() == 7) {
        if (stricmp(Cmd_Argv(3), "lighting") != 0) {
            CL_CubemapShotUsage();
            return;
        }
        rgb[0] = (float)atof(Cmd_Argv(4));
        rgb[1] = (float)atof(Cmd_Argv(5));
        rgb[2] = (float)atof(Cmd_Argv(6));
        isLightingShot = 1;
        n0 = 1.0f;
        n1 = 1.333f;
    } else if (Cmd_Argc() == 6) {
        if (stricmp(Cmd_Argv(3), "fresnel") != 0) {
            CL_CubemapShotUsage();
            return;
        }
        n0 = (float)atof(Cmd_Argv(4));
        n1 = (float)atof(Cmd_Argv(5));
        if (n0 < 1.0f) {
            CL_CubemapShotUsage();
            return;
        }
        if (n1 < 1.0f) {
            CL_CubemapShotUsage();
            return;
        }
        isLightingShot = 0;
    } else if (Cmd_Argc() == 3) {
        isLightingShot = 0;
        n0 = 1.0f;
        n1 = 1.333f;
    } else {
        CL_CubemapShotUsage();
        return;
    }

    CL_ResetSkeletonCache(0);

    byte *re = re_ptr_195eca8;
    for (side = 1; side <= 6; side++) {
        RE_FUNC(re, 0xec, re_int2_func)(size, 1);
        RE_FUNC(re, 0xa8, re_void_func)();
        CL_ClearScene();

        byte *clc = *(byte **)clc_ptr_195ee8c;
        int needRender = *(int *)(clc + 0x407a0) != 0;
        byte *dv = *(byte **)dvar_ptr_195ee78;
        int serverTime = *(int *)(dv + 0x26f0);

        CG_DrawActiveFrame(serverTime, needRender, side, size, 0);
        RE_FUNC(re, 0xac, re_void_func)();
        RE_FUNC(re, 0xf0, re_int_func)(side);
    }

    if (isLightingShot) {
        RE_FUNC(re, 0xf8, re_floatp_func)(rgb);
    }

    for (side = 1; side <= 6; side++) {
        re_write_cubemap_func writeFn = RE_FUNC(re_ptr_195eca8, 0xf4, re_write_cubemap_func);
        const char *filename = va("env/%s%s.tga", szBaseName, szShotName[side - 1]);
        writeFn(filename, side, n0, n1);
    }
}

/* line 338 */
static void SCR_UpdateFrame(void)
{
    byte *re = re_ptr_195eca8;

    RE_FUNC(re, 0xa8, re_void_func)();
    CL_ClearScene();
    CL_ResetSkeletonCache(0);

    byte *cls = cls_ptr_195ecac;
    int gameLoaded = CLS_CONN_STATE_FLAG(cls);

    if (!gameLoaded) {
        RE_FUNC(re, 0xc8, re_int4_func)(1, (int)(unsigned int)ptr_195f58c, 0, 0);
        goto end_frame;
    }

    /* Check connection state for scene rendering */
    byte *clc = *(byte **)clc_ptr_195ee8c;
    int connstate = *(int *)clc;
    if (connstate != 8 && connstate != 1) {
        RE_FUNC(re, 0xc8, re_int4_func)(1, (int)(unsigned int)ptr_195f58c, 0, 0);
    }

    UI_UpdateTime(CLS_CLIENT_TIME(cls));

    if (UI_IsFullscreen()) {
        /* Fullscreen UI path */
        clc = *(byte **)clc_ptr_195ee8c;
        connstate = *(int *)clc;

        if (connstate < 0) {
            Com_Error(0, "SCR_DrawScreenField: bad clc->state");
        } else if (connstate <= 7) {
            goto check_ui;
        } else if (connstate == 8) {
            /* Active game frame (fullscreen) */
            int needRender = *(int *)(clc + 0x407a0) != 0;
            byte *dv = *(byte **)dvar_ptr_195ee78;
            int serverTime = *(int *)(dv + 0x26f0);

            int result = CG_DrawActiveFrame(serverTime, needRender, 0, 0, 0);
            if (result == 0) {
                CL_SendCmdInternal();
            }
            goto check_ui;
        } else {
            Com_Error(0, "SCR_DrawScreenField: bad clc->state");
        }
    } else {
        /* Non-fullscreen path */
        clc = *(byte **)clc_ptr_195ee8c;
        connstate = *(int *)clc;

        if ((unsigned int)connstate > 8) {
            Com_Error(0, "SCR_DrawScreenField: bad clc->state");
        }

        switch (connstate) {
        case 0: /* disconnected */
            SND_StopSounds(0);
            if (Sys_IsMainThread()) {
                UI_SetActiveMenu(1);
            } else if (CL_AnyLocalClientChallenging()) {
                UI_Refresh();
                UI_DrawConnectScreen();
            }
            goto check_ui;

        case 1: /* cinematic */
            SCR_DrawCinematic();
            goto check_ui;

        case 2: /* logo */
            CL_DrawLogo();
            clc = *(byte **)clc_ptr_195ee8c;
            if (*(int *)clc != 2) {
                goto end_frame_draw;
            }
            goto check_ui;

        case 3: /* connecting */
        case 4: /* challenging */
        case 5: /* connected */
        case 6: /* loading */
        case 7: /* primed */
            UI_Refresh();
            UI_DrawConnectScreen();
            goto check_ui;

        case 8: /* active */
        {
            int needRender = *(int *)(clc + 0x407a0) != 0;
            byte *dv = *(byte **)dvar_ptr_195ee78;
            int serverTime = *(int *)(dv + 0x26f0);

            int result = CG_DrawActiveFrame(serverTime, needRender, 0, 0, 1);
            if (result == 0) {
                CL_SendCmdInternal();
            }

            /* Demo recording overlay */
            clc = *(byte **)clc_ptr_195ee8c;
            if (*(int *)(clc + 0x4079c)) {
                int pos = FS_FTell(*(int *)(clc + 0x407b0));
                int posKB = (pos + 0x3ff) >> 10;
                char buf[1024];
                float color[4];
                sprintf(buf, "RECORDING %s: %ik", (char *)(clc + 0x4075c), posKB);

                CL_LookupColor(0x37, color);
                float x = 5.0f;
                float y = 479.0f;

                re = re_ptr_195eca8;
                cls = cls_ptr_195ecac;
                int font = CLS_CONSOLE_FONT(cls);
                float fontH = RE_FUNC(re, 0x110, re_font_height_func)(font, 0.333333f);
                float w = fontH;
                float h = fontH;

                CalcScreenPlacement(&x, &y, &w, &h, 1, 1);

                RE_FUNC(re, 0x11c, re_draw_string_func)(
                    buf, 0x7fffffff, font, x, y, w, h, color, 0);
            }
            goto check_ui;
        }
        }
    }

check_ui:
    /* Draw UI if conditions met */
    {
        byte *dv = *(byte **)dvar_ptr_195ee78;
        if (*(byte *)(dv + 4) & 8) {
            byte *clc2 = *(byte **)clc_ptr_195ee8c;
            if (*(int *)clc2 != 1) {
                UI_Refresh();
            }
        }
    }

    /* Check net display profile */
    {
        byte *netPtr = *(byte **)ptr_195f5e0;
        if (*(int *)(netPtr + 8)) {
            Net_DisplayProfile();
        }
    }

    /* Render screen */
    RE_FUNC(re_ptr_195eca8, 0xb8, re_int_func)(0);

end_frame_draw:
    re = re_ptr_195eca8;
    RE_FUNC(re, 0xbc, re_void_func)();
    Con_DrawConsole();
    RE_FUNC(re, 0xac, re_void_func)();
    Sys_IsMainThread();
    return;

end_frame:
    RE_FUNC(re_ptr_195eca8, 0xbc, re_void_func)();
    Con_DrawConsole();
    RE_FUNC(re_ptr_195eca8, 0xac, re_void_func)();
    Sys_IsMainThread();
}

/* line 403 */
void SCR_UpdateScreenInternal(void)
{
    if (updateScreenCalled)
        return;

    byte *clc = *(byte **)clc_ptr_195ee8c;
    if (*(int *)clc == 6) {
        Sys_LoadingKeepAlive();
    }

    if (!scr_initialized)
        return;

    byte *guard = *(byte **)ptr_195eea4;
    if (*(int *)guard)
        return;

    updateScreenCalled = 1;
    SCR_UpdateFrame();
    updateScreenCalled = 0;
}

/* line 438 */
void SCR_UpdateScreen(void)
{
    if (updateScreenCalled)
        return;

    byte *clc = *(byte **)clc_ptr_195ee8c;
    if (*(int *)clc == 6) {
        Sys_LoadingKeepAlive();
    }

    if (!scr_initialized)
        return;

    byte *guard = *(byte **)ptr_195eea4;
    if (*(int *)guard)
        return;

    updateScreenCalled = 1;
    SCR_UpdateFrame();
    updateScreenCalled = 0;
}
