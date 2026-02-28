/* Converted to C from ASM: cg_info_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_info_mp.cpp */

#include "common_types.h"
#include "imports.h"

#include <ctype.h>

/* External function declarations */
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern const char *va(const char *format, ...);
extern void Com_Printf(const char *msg, ...);
extern void SCR_UpdateScreen(void);
extern void CG_CloseScriptMenu(void);
extern void CL_CloseAllMenus(void);
extern void SND_StopSounds(int flags);
extern const char *CL_GetConfigString(int index);
extern const char *Info_ValueForKey(const char *s, const char *key);
extern const char *Dvar_GetString(const char *dvarName);
extern int Dvar_GetInt(const char *dvarName);
extern void UI_DrawMapLevelshot(void);
extern int Sys_Milliseconds(void);
extern void *UI_GetFontHandle(int fontEnum, float scale);
extern int UI_TextWidth(const char *text, int maxChars, void *font, float scale);
extern const char *UI_SafeTranslateString(const char *ref);
extern void UI_DrawText(const char *text, int maxChars, void *font, float x, float y, int horzAlign, int vertAlign, float scale, const float *color, int style);

/* External globals */
extern char **cg_glob;           /* imp_cg — pointer to cg_t base */
extern char **cg_globUI;         /* imp_legacyHacks — pointer to cg_t base (UI side) */
extern const float *scrPlace;    /* imp_colorWhite — screen placement */
extern char *loadingMessage;     /* imp_g_waitingForServer — loading message string */

/* cg_t field offsets */
#define CG_LOADING_STRING    0x2a5fc  /* char[1024] — loading string buffer */
#define CG_FIELD_5C          0x5c     /* byte — cleared on !serverLoading */
#define CG_FIELD_9C          0x9c     /* byte — cleared on !serverLoading */
#define CG_FIELD_DC          0xdc     /* byte — loading initialized flag */
#define CG_FIELD_4ED         0x4ed    /* byte — script menu state */

extern int ___tolower(int c);

void CG_LoadingString(const char *s);
void CG_DrawInformation(qboolean serverLoading);

/* line 16 */
void CG_LoadingString(const char *s)
{
    char *base = *cg_glob;

    /* line 18 */
    I_strncpyz(base + CG_LOADING_STRING, s, 0x400);

    /* line 20 */
    if (s == NULL || *s == '\0')
    {
        /* line 23 */
        SCR_UpdateScreen();
        return;
    }

    /* line 21 */
    Com_Printf(va("LOADING... %s\n", s));

    /* line 23 */
    SCR_UpdateScreen();
}

/* line 27 */
void CG_DrawInformation(qboolean serverLoading)
{
    char string[0x400];
    void *font;
    char *base;
    char *pos;
    const char *configStr;
    const char *mapname;
    const char *dots;
    const char *translated;
    int textWidth;
    int ms;
    int phase;
    float x;

    /* line 50 */
    if (!serverLoading)
    {
        /* line 52-54 */
        base = *cg_globUI;
        *(char *)(base + CG_FIELD_5C) = 0;
        base = *cg_globUI;
        *(char *)(base + CG_FIELD_9C) = 0;
        base = *cg_globUI;
        *(char *)(base + CG_FIELD_DC) = 0;
    }

    /* line 58 */
    base = *cg_globUI;
    if (*(char *)(base + CG_FIELD_DC) == 0)
    {
        /* line 60 */
        *(char *)(base + CG_FIELD_4ED) = 0;

        /* line 61-62 */
        CG_CloseScriptMenu();
        CG_CloseScriptMenu();

        /* line 63 */
        base = *cg_globUI;
        *(char *)(base + CG_FIELD_4ED) = 1;

        /* line 65 */
        CL_CloseAllMenus();

        /* line 66 */
        SND_StopSounds(0);

        /* line 68 */
        base = *cg_globUI;
        *(char *)(base + CG_FIELD_DC) = 1;
    }

    /* line 72 */
    configStr = CL_GetConfigString(0);

    /* line 74 */
    if (serverLoading)
    {
        /* line 76 — copy the raw config string as the server name display */
        base = *cg_globUI;
        I_strncpyz(string, base + 0x5c, 0x400);
    }
    else
    {
        /* line 80 */
        mapname = Info_ValueForKey(configStr, "mapname");

        /* line 82 */
        if (*mapname == '\0')
        {
            /* line 83-84 — fallback to dvar */
            mapname = Dvar_GetString("mapname");
        }

        I_strncpyz(string, mapname, 0x400);
    }

    /* line 88-89 — lowercase the string */
    pos = string;
    while (*pos)
    {
        *pos = (char)___tolower((int)*pos);
        pos++;
    }

    /* line 91 */
    UI_DrawMapLevelshot();

    /* line 95-96 */
    if (Dvar_GetInt("com_expectedhunkusage") <= 0)
    {
        /* line 107 */
        if (!serverLoading)
            return;

        if (*loadingMessage == '\0')
            return;

        /* line 111 */
        font = UI_GetFontHandle(0, 0.5f);

        /* line 113 */
        ms = Sys_Milliseconds();

        /* line 115 — dot animation: divide by 750, take mod 4 */
        phase = (ms / 750) & 3;

        switch (phase)
        {
            case 0: dots = "";    break;
            case 1: dots = ".";   break;
            case 2: dots = "..";  break;
            case 3: dots = "..."; break;
        }

        /* line 131 */
        translated = UI_SafeTranslateString("CGAME_WAITINGFORSERVERLOAD");

        /* line 132 */
        textWidth = UI_TextWidth(translated, 0, font, 0.5f);

        /* line 133 */
        x = (640.0f - (float)textWidth) * 0.5f;

        /* line 136 */
        UI_DrawText(
            va("%s%s", translated, dots),  /* text */
            0x7fffffff,                     /* maxChars */
            font,                           /* font */
            x,                              /* x — centered */
            439.0f,                         /* y */
            0,                              /* horzAlign */
            0,                              /* vertAlign */
            0.5f,                           /* scale */
            scrPlace,                       /* color */
            3                               /* style */
        );
    }

    /* line 137 */
}
