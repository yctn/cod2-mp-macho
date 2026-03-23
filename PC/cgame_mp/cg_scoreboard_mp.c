/* ASM dump from: cg_scoreboard_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_scoreboard_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

extern struct Material * CL_RegisterMaterialNoMip(const char *name, int imageTrack);
extern const char * Dvar_GetString(const char *dvarName);
extern void Dvar_GetUnpackedColorByName(const char *dvarName, vec_t *color);
extern void UI_DrawHandlePic(float x, float y, float w, float h, int horzAlign, int vertAlign, float *color, int material);
extern void UI_DrawText(const char *text, int maxChars, void *font, float x, float y, int horzAlign, int vertAlign, float scale, float *color, int style);
extern int UI_TextWidth(const char *text, int maxChars, void *font, float scale);
extern int UI_TextHeight(void *font, float scale);
extern void *UI_GetFontHandle(int fontEnum, float scale);
extern const char *UI_GetGameTypeDisplayName(const char *gameType);
extern const char *UI_GetMapDisplayName(const char *mapName);
extern const char *SEH_LocalizeTextMessage(const char *msg, const char *context, int errType);
extern const char *CL_GetServerIPAddress(void);
extern int I_stricmp(const char *s1, const char *s2);
extern int I_strnicmp(const char *s1, const char *s2, int n);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern const char *FS_GetMapBaseName(const char *mapfile);
extern const char *UI_SafeTranslateString(const char *key);
extern void CL_AddReliableCommand(const char *cmd);
extern float *CG_FadeColor(int startMsec, int totalMsec, int fadeMsec);

__attribute__((used, aligned(4)))
int lastLeadTeam_storage[8] = {
    2, 0, 0, 0, 0, 0, 0, 0,
}; /* 0x314640 */

#define lastLeadTeam (lastLeadTeam_storage[0])
/* The decompiler dropped the original scoreboard column table. */
static const listColumnInfo_t columnInfo[6] = {
    {LCT_NAME, 0.46f, "", 0},
    {LCT_STATUS_ICON, 0.05f, "", 0},
    {LCT_TALKING_ICON, 0.05f, "", 0},
    {LCT_SCORE, 0.15f, str_002b6804, 2},
    {LCT_DEATHS, 0.15f, str_002b6814, 2},
    {LCT_PING, 0.14f, str_002b6824, 2},
}; /* columnInfo */

qboolean CG_ScoreboardDisplayed(void);
float CG_ScrollScoreboardUp(void);
float CG_ScrollScoreboardDown(void);
float CG_RegisterScoreboardGraphics(void);
int CalcBorderLines(sbpicinfo_t *backdropBorderLines);
float CG_DrawScoreboard_GetTeamColor(int team, vec_t *color);
static float CG_DrawClientScore(vec_t *color, float y, score_t *score, float listWidth, qboolean selection, int *piDrawLine, const int numDrawn);
static float CG_DrawScoreboard_ListBanner(float y, float w, float h);
static float CG_DrawScoreboard_ScoresList(float alpha);
qboolean CG_DrawScoreboard(void);

/* line 1392 */
qboolean CG_ScoreboardDisplayed(void)
{
    return ((cg_t *)*(int *)imp_cg)->showScores;
}

/* line 1404 */
float CG_ScrollScoreboardUp(void)
{
    cg_t *cg = (cg_t *)*(int *)imp_cg;
    int scrollOffset = cg->scoresTop;
    if (scrollOffset > 0) {
        scrollOffset -= *(int *)(*(int *)imp_cg_scoreboardScrollStep + 8);
        cg->scoresTop = scrollOffset;
        if (scrollOffset < 0)
            cg->scoresTop = 0;
    }
    return 0;
}

/* line 1415 */
float CG_ScrollScoreboardDown(void)
{
    cg_t *cg = (cg_t *)*(int *)imp_cg;
    if (cg->scoresOffBottom != 0) {
        int scrollOffset = cg->scoresTop;
        scrollOffset += *(int *)(*(int *)imp_cg_scoreboardScrollStep + 8);
        cg->scoresTop = scrollOffset;
        int maxScroll = cg->numScores - 1;
        if (scrollOffset > maxScroll)
            cg->scoresTop = maxScroll;
    }
    return 0;
}

/* line 1427 */
float CG_RegisterScoreboardGraphics(void)
{
    CL_RegisterMaterialNoMip((const char *)str_00224184, 7); /* "white" */
    CL_RegisterMaterialNoMip((const char *)str_00224184, 7); /* "white" */
    CL_RegisterMaterialNoMip((const char *)str_00226ec8, 7); /* "black" */
    CL_RegisterMaterialNoMip((const char *)str_00224184, 7); /* "white" */
    CL_RegisterMaterialNoMip((const char *)str_00224184, 7); /* "white" */
    CL_RegisterMaterialNoMip((const char *)str_00226ec8, 7); /* "black" */
    CL_RegisterMaterialNoMip((const char *)str_002b6834, 7); /* "hudscoreboardscroll_uparrow" */
    CL_RegisterMaterialNoMip((const char *)str_002b6850, 7); /* "hudscoreboardscroll_upkey" */
    CL_RegisterMaterialNoMip((const char *)str_002b686c, 7); /* "hudscoreboardscroll_downarrow" */
    CL_RegisterMaterialNoMip((const char *)str_002b688c, 7); /* "hudscoreboardscroll_downkey" */
    CL_RegisterMaterialNoMip(Dvar_GetString((const char *)str_002b4730), 7);
    CL_RegisterMaterialNoMip(Dvar_GetString((const char *)str_002b46e8), 7);
    CL_RegisterMaterialNoMip(Dvar_GetString((const char *)str_002b46c0), 7);
    CL_RegisterMaterialNoMip(Dvar_GetString((const char *)str_002b4708), 7);
    CL_RegisterMaterialNoMip((const char *)str_002aa96c, 7); /* "voice_on" */
    CL_RegisterMaterialNoMip((const char *)str_002b68a8, 7); /* "voice_off" */
    return 0;
}

/* line 322 */
int CalcBorderLines(sbpicinfo_t *backdropBorderLines)
{
    /* sbpicinfo_t has fields: x, y, w, h (4 floats) */
    float *p = (float *)backdropBorderLines;

    /* Line 0: top border */
    p[0] = 123.0f; p[1] = 25.0f; p[2] = 394.0f; p[3] = 2.0f;
    /* Line 1: bottom border */
    p[4] = 123.0f; p[5] = 447.0f; p[6] = 394.0f; p[7] = 2.0f;
    /* Line 2: left border */
    p[8] = 123.0f; p[9] = 27.0f; p[10] = 2.0f; p[11] = 420.0f;
    /* Line 3: right border */
    p[12] = 515.0f; p[13] = 27.0f; p[14] = 2.0f; p[15] = 420.0f;
    /* Line 4: inner top */
    p[16] = 125.0f; p[17] = 51.0f; p[18] = 390.0f; p[19] = 1.0f;
    /* Line 5: inner bottom */
    p[20] = 125.0f; p[21] = 432.0f; p[22] = 390.0f; p[23] = 1.0f;

    return 6;
}

/* line 843 */
float CG_DrawScoreboard_GetTeamColor(int team, vec_t *color)
{
    float savedAlpha = color[3];

    if (team == 1) {
        Dvar_GetUnpackedColorByName((const char *)str_002addd4, color); /* "g_TeamColor_Axis" */
    } else if (team == 2) {
        Dvar_GetUnpackedColorByName((const char *)str_002addc0, color); /* "g_TeamColor_Allies" */
    } else {
        color[0] = 1.0f;
        color[1] = 1.0f;
        color[2] = 1.0f;
    }

    color[3] = savedAlpha;
    return 0;
}

/* line 958 */

/* line 1347 */
qboolean CG_DrawScoreboard(void)
{
    byte *cg_s;
    byte *cgsPtr;
    float fade;
    float bgAlpha;
    float borderAlpha;
    float color[4];
    float fontScale;
    float footerFontScale;
    struct Material *material;
    sbpicinfo_t borderLines[4]; /* CalcBorderLines output */
    char mapBuffer[64];
    const char *map;
    const char *gameType;
    const char *serverName;
    const char *serverIP;
    void *headerFont;
    void *footerFont;
    int numLines;
    int mapLen;
    float y;
    float *fadePtr;

    /* line 1352: if paused, return false */
    {
        byte *dvar = *(byte **)imp_cg_paused;
        if (*(int *)((byte *)dvar + 8) != 0)
            return 0;
    }

    /* line 1355 */
    cg_s = *(byte **)imp_cg;
    {
        cg_t *cg = (cg_t *)cg_s;
        if (cg->showScores == 0) {
            /* line 1365: try to get fade color */
            fadePtr = (float *)CG_FadeColor(cg->scoreFadeTime, 100, 100);
            if (fadePtr == 0) {
                /* line 1371 */
                cg->killerName[0] = 0;
                goto scoreboard_done;
            }
            /* line 1374 */
            fade = fadePtr[0];
            bgAlpha = fade * 0.8f;
            borderAlpha = fade * 0.1f;
        } else {
            /* line 1355: scoreboard is showing */
            fade = 1.0f;
            bgAlpha = 0.8f;
            borderAlpha = 0.1f;
        }

        /* line 1378: check if we need to request scores */
        {
            int serverTime = cg->time;
            int lastScoreTime = cg->scoresRequestTime;
            if (lastScoreTime + 0x7d0 < serverTime) {
                cg->scoresRequestTime = serverTime;
                CL_AddReliableCommand((const char *)str_002b3bec);
            }
        }
    }

    /* Draw black background */
    {
        byte *cb = *(byte **)imp_colorBlack;
        color[0] = *(float *)(cb + 0);
        color[1] = *(float *)(cb + 4);
        color[2] = *(float *)(cb + 8);
        color[3] = bgAlpha;
        {
            struct Material *whiteMat = CL_RegisterMaterialNoMip((const char *)str_00224184, 7);
            {
                float x = 120.0f;   /* 0x42f00000 */
                float yy = 22.0f;   /* 0x41b00000 */
                float w = 400.0f;   /* 0x43c80000 */
                float h = 430.0f;   /* 0x43d70000 */
                UI_DrawHandlePic(x, yy, w, h, 0, 0, color, (int)whiteMat);
            }
        }
    }

    /* Draw white border lines */
    {
        byte *cw = *(byte **)imp_colorWhite;
        color[0] = *(float *)(cw + 0);
        color[1] = *(float *)(cw + 4);
        color[2] = *(float *)(cw + 8);
        color[3] = borderAlpha;
        material = CL_RegisterMaterialNoMip((const char *)str_00224184, 7);
        numLines = CalcBorderLines(borderLines);
        if (numLines > 0) {
            int lineIdx;
            float *linePtr = (float *)borderLines + 4;
            for (lineIdx = 0; lineIdx < numLines; lineIdx++) {
                UI_DrawHandlePic(linePtr[-3], linePtr[-2], linePtr[-1], linePtr[0], 0, 0, color, (int)material);
                linePtr += 4;
            }
        }
    }

    /* line 605: get game type display name */
    cgsPtr = *(byte **)imp_cgs;
    gameType = (const char *)SEH_LocalizeTextMessage(
        UI_GetGameTypeDisplayName((const char *)(cgsPtr + 0x5ea4)),
        (const char *)str_002b693c, 0);

    /* Draw game type header */
    {
        byte *cw = *(byte **)imp_colorWhite;
        float savedR = *(float *)(cw + 0);
        float savedG = *(float *)(cw + 4);
        int savedB = *(int *)(cw + 8);
        color[0] = savedR;
        color[1] = savedG;
        color[2] = *(float *)&savedB;
        color[3] = fade;
        {
            float headerScale;
            int textHeight;
            *(int *)&headerScale = 0x3ed1eb85; /* ~0.41f */
            headerFont = UI_GetFontHandle(0, headerScale);
            textHeight = UI_TextHeight(headerFont, headerScale);
            {
                float yPos = 51.0f + (float)(24 - textHeight) * -0.5f;
                UI_DrawText(gameType, 0x7fffffff, headerFont, 129.0f, yPos, 0, 0, headerScale, color, 3);
            }
        }

        /* Draw map name */
        color[0] = savedR;
        color[1] = savedG;
        color[2] = *(float *)&savedB;
        color[3] = fade;

        /* Get map name */
        {
            const char *baseName = FS_GetMapBaseName((const char *)(cgsPtr + 0x5fc8));
            const char *dispName = UI_GetMapDisplayName(baseName);
            I_strncpyz(mapBuffer, dispName, 0x40);
        }

        if (mapBuffer[0] == '\0') {
            /* line 522: copy raw mapfile name */
            strcpy(mapBuffer, (const char *)(cgsPtr + 0x5fc8));
            /* compute strlen */
            {
                int len = 0;
                while (mapBuffer[len] != '\0') len++;
                mapLen = len;
            }
            /* line 524: strip ".bsp" extension */
            if (mapLen >= 4 && I_strnicmp(mapBuffer + mapLen - 4, (const char *)str_00217ff4, 3) == 0) {
                mapBuffer[mapLen - 4] = '\0';
            }
        }

        /* line 528: strip "maps/" prefix */
        map = mapBuffer;
        if (I_strnicmp(mapBuffer, (const char *)str_002b6958, 4) == 0) {
            char c = mapBuffer[4];
            if (c == '/' || c == '\\') {
                map = mapBuffer + 5;
            }
        }

        /* line 530: strip "mp/" prefix */
        if (I_strnicmp(map, (const char *)str_0021cc10, 2) == 0) {
            char c = map[2];
            if (c == '/' || c == '\\') {
                map = map + 3;
            }
        }

        /* line 531-539: compute fontScale to fit text */
        fontScale = 0.41f;
        numLines = 14;
        {
            float curScale = fontScale;
            void *curFont;
            while (numLines > 0) {
                curFont = UI_GetFontHandle(0, curScale);
                headerFont = curFont;
                {
                    int w1 = UI_TextWidth(gameType, 0, curFont, curScale);
                    int w2 = UI_TextWidth(map, 0, curFont, curScale);
                    if ((float)(w1 + w2 + 4) <= 386.0f)
                        break;
                }
                curScale -= 0.025f;
                fontScale = curScale;
                numLines--;
            }
        }

        /* line 543-545: draw map name */
        {
            int mapWidth = UI_TextWidth(map, 0, headerFont, fontScale);
            int textHeight2 = UI_TextHeight(headerFont, fontScale);
            float yPos2 = 51.0f + (float)(24 - textHeight2) * -0.5f;
            float xPos = 511.0f - (float)(mapWidth + 4);
            UI_DrawText(map, 0x7fffffff, headerFont, xPos, yPos2, 0, 0, fontScale, color, 3);
        }
    }

    /* line 567: Draw server name and IP footer */
    {
        byte *cw = *(byte **)imp_colorWhite;
        color[0] = *(float *)(cw + 0);
        color[1] = *(float *)(cw + 4);
        color[2] = *(float *)(cw + 8);
        color[3] = fade;

        cgsPtr = *(byte **)imp_cgs;
        serverName = (const char *)(cgsPtr + 0x5ec4);
        serverIP = (const char *)CL_GetServerIPAddress();

        if (I_stricmp(serverIP, (const char *)str_002b6960) == 0) {
            serverIP = (const char *)UI_SafeTranslateString((const char *)str_002b696c);
        }

        /* line 573-580: compute footer font scale */
        footerFontScale = 0.2f;
        numLines = 13;
        {
            float curScale = footerFontScale;
            void *curFont;
            while (numLines > 0) {
                curFont = UI_GetFontHandle(0, curScale);
                footerFont = curFont;
                {
                    int w1 = UI_TextWidth(serverName, 0, curFont, curScale);
                    int w2 = UI_TextWidth(serverIP, 0, curFont, curScale);
                    if ((float)(w1 + w2 + 4) <= 386.0f)
                        break;
                }
                curScale -= 0.01f;
                footerFontScale = curScale;
                numLines--;
            }
        }

        /* line 584: compute y position */
        {
            int textHeight3 = UI_TextHeight(footerFont, footerFontScale);
            y = 447.0f + (float)(14 - textHeight3) * -0.5f;
        }

        /* line 586: draw server name */
        UI_DrawText(serverName, 0x7fffffff, footerFont, 129.0f, y, 0, 0, footerFontScale, color, 3);

        /* line 590-591: draw server IP right-aligned */
        {
            int ipWidth = UI_TextWidth(serverIP, 0, footerFont, footerFontScale);
            float xPos = 511.0f - (float)(ipWidth + 4);
            UI_DrawText(serverIP, 0x7fffffff, footerFont, xPos, y, 0, 0, footerFontScale, color, 3);
        }
    }

    /* line 1386: draw scores list */
    CG_DrawScoreboard_ScoresList(fade);

scoreboard_done:
    return 1;
}
