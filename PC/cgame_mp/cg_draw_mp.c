/* ASM dump from: cg_draw_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_draw_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

extern struct lagometer_t lagometer; /* 0x0 */
static int previous; /* previous */
static struct trStatistics_t rendererStats; /* rendererStats */
static int fps_previousTimes[32]; /* fps_previousTimes */
static int fps_index; /* fps_index */
static vec4_t colorWhiteFaded; /* colorWhiteFaded */
static vec4_t colorGreenFaded; /* colorGreenFaded */
static vec4_t colorRedFaded; /* colorRedFaded */
extern const vec_t *colorWhite; /* imp_colorWhite */
extern byte *cgs_ptr; /* imp_cgs */
extern char **cg_glob; /* imp_cg */
extern float UI_DrawHandlePic(float x, float y, float w, float h, int horzAlign, int vertAlign, const vec_t *color, MaterialHandle material);
extern void CG_DrawStringExt(float x, float y, const char *string, const vec_t *setColor, qboolean forceColor, qboolean shadow, float charHeight, qboolean adjust);
extern void CL_LookupColor(int c, vec_t *color);
extern const char *va(const char *fmt, ...);
extern unsigned int Scr_GetNumScriptVars(void);
extern unsigned int Scr_GetNumScriptThreads(void);
extern unsigned int Scr_GetStringUsage(void);
extern int Sys_Milliseconds(void);
extern int CL_GetCurrentCmdNumber(void);
extern int CL_GetKeyCatchers(void);
extern qboolean CL_GetUserCmd(int cmdNumber, usercmd_t *ucmd);
extern Bool CL_IsRenderingSplitScreen(void);
extern void CL_SetUserCmdAimValues(const vec_t *angles);
extern void CL_SetUserCmdValue(int weapon, int offHandIndex, float sensitivity);
extern void CL_RenderScene(const void *refdef);
extern void CG_DrawShellShockSavedScreenBlend(float r, float g, float b);
extern void CG_TileClear(void);
extern const char *UI_SafeTranslateString(const char *ref);
extern const char *UI_ReplaceConversionString(const char *sourceString, const char *replaceString);
extern const char *SEH_LocalizeTextMessage(const char *msg, const char *context, int errType);
extern FontHandle UI_GetFontHandle(int fontEnum, float scale);
extern int UI_TextWidth(const char *text, int maxChars, FontHandle font, float scale);
extern int UI_TextHeight(FontHandle font, float fontScale);
extern void UI_DrawText(const char *text, int maxChars, FontHandle font, float x, float y, int horzAlign, int vertAlign, float scale, const vec_t *color, int style);
extern MaterialHandle CL_RegisterMaterial(const char *name, int flags);
extern void CG_TranslateHudElemMessage(const char *message, const char *messageType, char *hudElemString);
extern void CG_TraceCapsule(trace_t *result, const vec_t *start, const vec_t *mins, const vec_t *maxs, const vec_t *end, int skipNumber, int mask);
extern int BG_GetViewmodelWeaponIndex(void *ps);
extern void *BG_GetWeaponDef(int weapIndex);
extern void CL_DrawStretchPic(float x, float y, float w, float h, int horzAlign, int vertAlign, float s1, float t1, float s2, float t2, const vec_t *color, MaterialHandle material);
extern void CL_DrawStretchPicPhysical(float x, float y, float w, float h, float s1, float t1, float s2, float t2, const vec_t *color, MaterialHandle material);
extern qboolean CG_ScoreboardDisplayed(void);
extern void Con_DrawBoldMessages(int xPos, int yPos, float alpha, msgwnd_mode_t mode);
extern float *CG_FadeColor(int startMsec, int totalMsec, int fadeMsec);
extern void Controls_GetConfig(void);
extern int GetKeyBindingLocalizedString(const char *command, char *keys);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern char *I_CleanStr(char *string);
extern unsigned int SEH_ReadCharFromString(const char **ppsText, qboolean *pbIsTrailingPunctuation);
extern centity_t **cg_entities_glob; /* imp_cg_entities */
extern void CG_PlayerSprites(centity_t *cent);
extern qboolean CL_PickMaterial(const vec_t *org, const vec_t *dir, char *pszName, char *pszSurfaceFlags, char *pszContents, int iMaxChars);
extern int CG_DrawSmallDevStringColor(float x, float y, const char *s, const vec_t *color, int align);
extern int __mh_execute_header;
extern int SND_GetSoundOverlay(snd_overlay_type_t type, snd_overlay_info_t *info, int maxcount, int *cpu);
extern const char *Dvar_GetString(const char *dvarName);
extern int Dvar_GetInt(const char *dvarName);
extern Bool Dvar_GetBool(const char *dvarName);
extern void AngleVectors(const vec_t *angles, vec_t *forward, vec_t *right, vec_t *up);
extern float Vec3Distance(const vec_t *v1, const vec_t *v2);
extern float crandom(void);
extern double sin(double);
extern double tan(double);

/* Externs for CG_CheckTimedMenus */
extern void Menus_CloseByName(void *dc, const char *name);
extern void *Menus_FindByName(void *dc, const char *name);
extern void Window_AddDynamicFlags(void *window, int flags);
extern void Window_RemoveDynamicFlags(void *window, int flags);
extern void CG_MenuShowNotify(int menuToShow);
extern float CG_CalcPlayerHealth(void);
extern Bool CG_CheckPlayerForLowAmmo(void);
extern Bool CG_CheckPlayerForLowClip(void);
extern int CL_GetLocalClientActiveCount(void);

unsigned int CG_DrawTeamBackground(float x, float y, float w, float h, float alpha, int team);
static unsigned int CG_DrawScriptUsage(void);
unsigned int CG_CalculateFPS(void);
unsigned int CG_AddLagometerFrameInfo(void);
unsigned int CG_AddLagometerSnapshotInfo(snapshot_t *snap);
static unsigned int CG_DrawDisconnect(void);
unsigned int CG_PriorityCenterPrint(const char *str, float charWidth, int priority);
Bool CG_GetWeapReticleZoom(float *pfZoom);
unsigned int CG_DrawFrameOverlay(float innerLeft, float innerRight, float innerTop, float innerBottom, const vec_t *color, MaterialHandle material);
static unsigned int CG_DrawCrosshairNames(void);
unsigned int CG_CheckTimedMenus(void);
static unsigned int CG_DrawSoundOverlay(void);
static unsigned int CG_DrawMaterial(void);
unsigned int CG_ShakeCamera(void);
static qboolean CG_DrawFollow(void);
unsigned int CG_DrawPlayerSprites(void);
unsigned int CG_DrawActive(void);
static unsigned int CG_DrawChatMessages(void);
static void __attribute_regparm__(2) CG_CalcCrosshairPosition(float *x, float *y);
static float CG_DrawFPS(float y);
unsigned int CG_DrawBoldGameMessages(void);
unsigned int CG_DrawTurretCrossHair(void);
static unsigned int CG_DrawSpectatorMessage(void);
unsigned int CG_StartShakeCamera(float p, int duration, vec_t *src, float radius);
static float CG_DrawWeapReticle(void);
unsigned int CG_DrawCrosshair(void);
unsigned int CG_Draw2D(void);

static qboolean CG_UpdateCameraShakeStrength(cg_t *cg, cameraShake_t *shake)
{
    float elapsed;
    float distanceScale;
    float rumbleScale;

    elapsed = (float)(cg->time - shake->time);
    if (elapsed < 0.0f || elapsed >= shake->length)
    {
        return 0;
    }

    distanceScale = 1.0f - Vec3Distance(shake->src, cg->refdef.vieworg) / shake->radius;
    rumbleScale = (1.0f - elapsed / shake->length) * shake->scale;
    if (rumbleScale <= 0.0f)
    {
        return 0;
    }

    shake->size = distanceScale < 0.0f ? distanceScale / rumbleScale : distanceScale * rumbleScale;
    shake->rumbleScale = rumbleScale;
    return 1;
}

/* line 133 */
unsigned int CG_DrawTeamBackground(float x, float y, float w, float h, float alpha, int team)
{
    vec4_t color;
    cgs_t *cgs;

    color[3] = alpha;
    if (team == 1)
    {
        color[0] = 1.0f;
        color[1] = 0.0f;
        color[2] = 0.0f;
    }
    else if (team == 2)
    {
        color[0] = 0.0f;
        color[1] = 0.0f;
        color[2] = 1.0f;
    }
    else
    {
        return 0;
    }

    cgs = *(cgs_t **)cgs_ptr;
    UI_DrawHandlePic(x, y, w, h, 0, 0, color, cgs->media.teamStatusBar);
    return 0;
}

/* line 241 */
unsigned int CG_DrawScriptUsage(void)
{
    CG_DrawStringExt(480.0f, 80.0f, va(str_002b6fbc, Scr_GetNumScriptVars()), colorWhite, 1, 1, 16.0f, 1);
    CG_DrawStringExt(480.0f, 96.0f, va(str_002b6fcc, Scr_GetNumScriptThreads()), colorWhite, 1, 1, 16.0f, 1);
    CG_DrawStringExt(480.0f, 112.0f, va(str_002b6fdc, Scr_GetStringUsage()), colorWhite, 1, 1, 16.0f, 1);
    return 0;
}

/* line 262 */
unsigned int CG_CalculateFPS(void)
{
    int now;
    int index;

    now = Sys_Milliseconds();
    fps_previousTimes[fps_index & 31] = now - previous;
    previous = now;
    index = fps_index + 1;
    fps_index = index;
    return 0;
}

/* line 639 */
unsigned int CG_AddLagometerFrameInfo(void)
{
    cg_t *cg = *(cg_t **)imp_cg;
    int index = *(int *)((char *)&lagometer + 512);
    lagometer.frameSamples[index & 0x7f] = cg->time - cg->latestSnapshotTime;
    *(int *)((char *)&lagometer + 512) = index + 1;
    return 0;
}

/* line 657 */
unsigned int CG_AddLagometerSnapshotInfo(snapshot_t *snap)
{
    int index;
    if (!snap)
    {
        index = *(int *)((char *)&lagometer + 1540);
        ((int *)((char *)&lagometer + 1028))[index & 0x7f] = -1;
        *(int *)((char *)&lagometer + 1540) = index + 1;
        return 0;
    }
    index = *(int *)((char *)&lagometer + 1540);
    ((int *)((char *)&lagometer + 1028))[index & 0x7f] = *(int *)((byte *)snap + 4);
    ((int *)((char *)&lagometer + 516))[index & 0x7f] = *(int *)snap;
    *(int *)((char *)&lagometer + 1540) = index + 1;
    return 0;
}

/* line 679 */
unsigned int CG_DrawDisconnect(void)
{
    usercmd_t cmd;
    cg_t *cg;
    byte *snap;
    const char *text;
    FontHandle font;
    int textWidth;
    vec4_t color = {1.0f, 1.0f, 1.0f, 1.0f};

    CL_GetUserCmd(CL_GetCurrentCmdNumber() - 127, &cmd);
    cg = *cg_glob;
    snap = (byte *)cg->nextSnap;
    if (cmd.serverTime <= ((snapshot_t *)snap)->ps.commandTime || cmd.serverTime > cg->time)
    {
        return 0;
    }

    text = UI_SafeTranslateString(str_002b6ff0);
    font = UI_GetFontHandle(0, 0.5f);
    textWidth = UI_TextWidth(text, 0, font, 0.5f);
    UI_DrawText(text, 0x7fffffff, font, (float)((640 - textWidth) / 2), 100.0f, 0, 0, 0.5f, color, 3);
    if (!(((byte *)&cg->time)[1] & 2))
    {
        UI_DrawHandlePic(296.0f, 416.0f, 48.0f, 48.0f, 0, 0, 0, CL_RegisterMaterial(str_002a89c8, 7));
    }

    return 0;
}

/* line 971 */
unsigned int CG_PriorityCenterPrint(const char *str, float charWidth, int priority)
{
    cg_t *cg;
    char hudElemString[256];
    const char *s;
    qboolean needNewline;
    int count;
    unsigned int letter;

    cg = *(cg_t **)imp_cg;
    if (cg->centerPrintTime && priority < cg->centerPrintPriority)
    {
        return 0;
    }

    CG_TranslateHudElemMessage(str, str_002b700c, hudElemString);
    I_strncpyz(cg->centerPrint, hudElemString, 0x100);
    cg->centerPrintPriority = priority;

    s = cg->centerPrint;
    needNewline = 0;
    count = 0;
    while (*s)
    {
        letter = SEH_ReadCharFromString(&s, 0);
        if (letter == '\n')
        {
            needNewline = 0;
            count = 0;
            continue;
        }

        ++count;
        if (count > 0x4a)
        {
            needNewline = 1;
        }

        if (needNewline && letter == ' ')
        {
            ((char *)s)[-1] = '\n';
            needNewline = 0;
            count = 0;
        }
    }

    cg->centerPrintTime = cg->time + 0x7d0;
    cg->centerPrintCharWidth = (int)charWidth;
    cg->centerPrintLines = 1;

    s = cg->centerPrint;
    while (*s)
    {
        letter = SEH_ReadCharFromString(&s, 0);
        if (letter == '\n')
        {
            ++cg->centerPrintLines;
            continue;
        }

        if (letter == '\\' && *s == 'n')
        {
            ++cg->centerPrintLines;
            ++s;
        }
    }

    return 0;
}

/* line 1132 */
Bool CG_GetWeapReticleZoom(float *pfZoom)
{
    cg_t *cg;
    WeaponDef *weaponDef;
    float zoom;

    cg = (cg_t *)*cg_glob;
    weaponDef = BG_GetWeaponDef(BG_GetViewmodelWeaponIndex(&cg->predictedPlayerState));
    zoom = cg->predictedPlayerState.fWeaponPosFrac;
    *pfZoom = 0.0f;

    if (!*weaponDef->szOverlayMaterial && !weaponDef->overlayReticle)
    {
        return 0;
    }

    if (zoom == 0.0f)
    {
        return 0;
    }

    if (*(int *)((byte *)&cg->playerEntity + 4) /* TODO: identify playerEntity_t field */)
    {
        *pfZoom = zoom - (1.0f - weaponDef->fAdsZoomInFrac);
        if (*pfZoom > 0.0f)
        {
            *pfZoom /= weaponDef->fAdsZoomInFrac;
        }
    }
    else
    {
        *pfZoom = zoom - (1.0f - weaponDef->fAdsZoomOutFrac);
        if (*pfZoom > 0.0f)
        {
            *pfZoom /= weaponDef->fAdsZoomOutFrac;
        }
    }

    if (*pfZoom <= 0.01f)
    {
        return 0;
    }

    if (*pfZoom > 1.0f)
    {
        *pfZoom = 1.0f;
    }

    return 1;
}

/* line 1186 */
unsigned int CG_DrawFrameOverlay(float innerLeft, float innerRight, float innerTop, float innerBottom, const vec_t *color, MaterialHandle material)
{
    byte *cls;
    float screenWidth;
    float screenHeight;

    cls = (byte *)imp_cls;
    screenWidth = (float)((clientStatic_t *)cls)->vidConfig.width; /* cls + 0x2a0a64 */
    screenHeight = (float)((clientStatic_t *)cls)->vidConfig.height; /* cls + 0x2a0a68 */

    if (innerLeft > 0.0f)
    {
        CL_DrawStretchPicPhysical(0.0f, 0.0f, innerLeft, screenHeight, 0.0f, 0.0f, 0.0f, 1.0f, color, material);
    }

    if (screenWidth > innerRight)
    {
        CL_DrawStretchPicPhysical(innerRight, 0.0f, screenWidth - innerRight, screenHeight, 0.0f, 0.0f, 0.0f, 1.0f, color, material);
    }

    if (innerTop > 0.0f)
    {
        CL_DrawStretchPicPhysical(innerLeft, 0.0f, innerRight - innerLeft, innerTop, 0.0f, 0.0f, 1.0f, 0.0f, color, material);
    }

    if (screenHeight > innerBottom)
    {
        CL_DrawStretchPicPhysical(innerLeft, innerBottom, innerRight - innerLeft, screenHeight - innerBottom, 0.0f, 0.0f, 1.0f, 0.0f, color, material);
    }

    return 0;
}

/* line 1782 */
unsigned int CG_DrawCrosshairNames(void)
{
    cg_t *cg;
    trace_t trace;
    vec3_t start;
    vec3_t end;
    vec3_t traceMins = {0.0f, 0.0f, 0.0f};
    vec3_t traceMaxs = {0.0f, 0.0f, 0.0f};
    float *baseColor;
    clientInfo_t *localClientInfo;
    clientInfo_t *targetClientInfo;
    char *name;
    FontHandle font;
    vec4_t actualColor;
    float healthFrac;
    int targetClientNum;
    int x;
    int y;

    if (!(*(const dvar_t **)imp_cg_drawCrosshairNames)->current.enabled)
    {
        return 0;
    }

    cg = *(cg_t **)imp_cg;
    if (cg->renderingThirdPerson)
    {
        return 0;
    }

    start[0] = cg->refdef.vieworg[0];
    start[1] = cg->refdef.vieworg[1];
    start[2] = cg->refdef.vieworg[2];
    end[0] = start[0] + cg->refdef.viewaxis[0][0] * 8192.0f;
    end[1] = start[1] + cg->refdef.viewaxis[0][1] * 8192.0f;
    end[2] = start[2] + cg->refdef.viewaxis[0][2] * 8192.0f;
    CG_TraceCapsule(&trace, start, traceMins, traceMaxs, end, cg->snap->ps.clientNum, 0x2000001);

    if (trace.entityNum <= 63)
    {
        cg->crosshairClientNum = trace.entityNum;
        cg->crosshairClientTime = cg->time;
    }

    baseColor = CG_FadeColor(cg->crosshairClientTime, 150, 100);
    if (!baseColor)
    {
        return 0;
    }

    targetClientNum = cg->crosshairClientNum;
    if (targetClientNum < 0 || targetClientNum > 64)
    {
        return 0;
    }

    localClientInfo = (clientInfo_t *)((byte *)cg + 0xe0914 + cg->snap->ps.clientNum * sizeof(clientInfo_t));
    if (!localClientInfo->infoValid || !localClientInfo->team)
    {
        return 0;
    }

    targetClientInfo = (clientInfo_t *)((byte *)cg + 0xe0914 + targetClientNum * sizeof(clientInfo_t));
    if (!targetClientInfo->infoValid)
    {
        return 0;
    }

    if (localClientInfo->team != 3 && localClientInfo->team != targetClientInfo->team)
    {
        return 0;
    }

    name = va(str_00216058, targetClientInfo->name);
    if (!name || !name[0])
    {
        return 0;
    }
    I_CleanStr(name);

    x = (*(const dvar_t **)imp_cg_drawCrosshairNamesPosX)->current.integer;
    y = (*(const dvar_t **)imp_cg_drawCrosshairNamesPosY)->current.integer + 16;

    if (cg->crosshairClientNum != cg->identifyClientNum)
    {
        actualColor[0] = 1.0f;
        actualColor[1] = 1.0f;
        actualColor[2] = 1.0f;
    }
    else
    {
        healthFrac = (float)cg->identifyClientHealth / 100.0f;
        if (healthFrac < 0.0f)
        {
            healthFrac = 0.0f;
        }
        else if (healthFrac > 1.0f)
        {
            healthFrac = 1.0f;
        }

        actualColor[2] = 0.0f;
        if (healthFrac > 0.5f)
        {
            actualColor[0] = (1.0f - healthFrac) * 2.0f;
            actualColor[1] = 1.0f;
        }
        else
        {
            actualColor[0] = 1.0f;
            actualColor[1] = healthFrac * 2.0f;
        }
    }

    actualColor[3] = baseColor[3] * 0.60000002f;
    font = UI_GetFontHandle(0, 1.0f / 3.0f);
    UI_DrawText(name, 0x7fffffff, font, (float)x, (float)y, 0, 0, 1.0f / 3.0f, actualColor, 3);
    return 0;
}

/* line 2410 */
unsigned int CG_CheckTimedMenus(void)
{
    cg_t *cg;
    int serverTime;
    int timedMenuTime;
    usercmd_t prevCmd;
    usercmd_t curCmd;
    usercmd_t prevCopy;
    usercmd_t curCopy;
    int cmdNum;
    int buttonBits;
    int buttonChanged;
    int hasChange;
    float health;
    float fadeVal;
    int showTime;
    void *menu;

    /* line 2414: check timed close menu */
    cg = *(cg_t **)imp_cg;
    timedMenuTime = cg->voiceTime;
    if (timedMenuTime != 0) {
        serverTime = cg->time;
        if (serverTime - timedMenuTime > 2500) {
            /* line 2420 */
            Menus_CloseByName(*(void **)imp_cgDC, (const char *)str_002b701c);
            cg->voiceTime = 0;
        }
    }

    /* line 2231: get user cmds for button change detection */
    cmdNum = CL_GetCurrentCmdNumber();
    if (cmdNum <= 1)
        goto after_buttons;

    /* line 2236-2237 */
    CL_GetUserCmd(cmdNum - 1, &prevCmd);
    CL_GetUserCmd(cmdNum, &curCmd);

    /* line 2238: extract button bits */
    buttonBits = curCmd.buttons;
    buttonChanged = buttonBits ^ prevCmd.buttons;

    /* line 2240: copy both usercmds for memcmp */
    memcpy(&prevCopy, &prevCmd, sizeof(usercmd_t));
    memcpy(&curCopy, &curCmd, sizeof(usercmd_t));

    /* line 2136: compare first 12 bytes (movement fields) */
    if (memcmp(&prevCopy, &curCopy, 12) != 0) {
        hasChange = 1;
    } else {
        /* line 2140: check if buttons changed */
        if ((unsigned short)curCopy.angles[1] != 0) {
            hasChange = 1;
        } else {
            hasChange = 0;
        }
    }

    /* line 2186: fire button check */
    if (buttonBits & 0x1) {
        cg = *(cg_t **)imp_cg;
        if (!(cg->predictedPlayerState.eFlags & 0x300)) {
            /* line 2197 */
            CG_MenuShowNotify(1);
            hasChange = 1;
            buttonBits = curCmd.buttons;
        }
    }

    /* line 2169: use button check */
    if (buttonBits & 0x30) {
        byte *cg2 = *(byte **)imp_cg;
        if (!((byte)(((cg_t *)cg2)->predictedPlayerState.pm_flags) & 0x4)) {
            snapshot_t *snap = ((cg_t *)cg2)->snap;
            if (!(snap->ps.cursorHint & 0x2)) {
                if (!(((cg_t *)cg2)->predictedPlayerState.eFlags & 0x300)) {
                    /* line 2197 */
                    CG_MenuShowNotify(1);
                    hasChange = 1;
                    buttonBits = curCmd.buttons;
                }
            }
        }
    }

    /* line 2206: weapon switch buttons */
    if (buttonBits & 0x30000) {
        /* line 2208 */
        CG_MenuShowNotify(4);
        hasChange = 1;
        buttonBits = curCmd.buttons;
    }

    /* line 2149: stance buttons (new pressed) */
    if (buttonChanged & 0x2300) {
        /* line 2151 */
        CG_MenuShowNotify(3);
        goto do_notify2;
    }

    /* line 2154: stance buttons (held) */
    if (buttonBits & 0x2300) {
        /* line 2156 */
        CG_MenuShowNotify(3);
    }

    /* line 2255 */
    if (!hasChange) {
        if (!(buttonChanged & 0xffffd4ff))
            goto after_buttons;
    }

do_notify2:
    /* line 2259 */
    CG_MenuShowNotify(2);

after_buttons:
    /* line 2268 */
    health = CG_CalcPlayerHealth();
    {
        float threshold = *(float *)(*(byte **)imp_hud_health_startpulse_injured + 8);
        if (threshold <= health) {
            /* line 2270: not injured enough, show health menu */
            CG_MenuShowNotify(0);
        }
    }

    /* line 2272: health bar fade */
    fadeVal = *(float *)(*(byte **)imp_hud_fade_healthbar + 8);
    if (fadeVal != 0.0f) {
        cg = *(cg_t **)imp_cg;
        showTime = cg->healthFadeTime;
        if (showTime != 0) {
            serverTime = cg->time;
            if ((float)(serverTime - showTime) > fadeVal * 1000.0f) {
                /* line 2277 */
                if (CL_GetLocalClientActiveCount() == 1) {
                    menu = Menus_FindByName(*(void **)imp_cgDC, (const char *)str_002b7028);
                } else {
                    menu = Menus_FindByName(*(void **)imp_cgDC, (const char *)str_002b7030);
                }
                /* line 2281 */
                if (menu)
                    Window_RemoveDynamicFlags(menu, 4);
                /* line 2283 */
                cg = *(cg_t **)imp_cg;
                cg->healthFadeTime = 0;
            }
        }
    }

    /* line 2294: low ammo check */
    if (CG_CheckPlayerForLowAmmo() || CG_CheckPlayerForLowClip()) {
        /* line 2296 */
        CG_MenuShowNotify(1);
    }

    /* line 2298: ammo display fade */
    fadeVal = *(float *)(*(byte **)imp_hud_fade_ammodisplay + 8);
    if (fadeVal != 0.0f) {
        cg = *(cg_t **)imp_cg;
        showTime = cg->ammoFadeTime;
        if (showTime != 0) {
            serverTime = cg->time;
            if ((float)(serverTime - showTime) > fadeVal * 1000.0f) {
                /* line 2303 */
                if (CL_GetLocalClientActiveCount() == 1) {
                    menu = Menus_FindByName(*(void **)imp_cgDC, (const char *)str_002b5978);
                } else {
                    menu = Menus_FindByName(*(void **)imp_cgDC, (const char *)str_002b703c);
                }
                /* line 2307 */
                if (menu)
                    Window_RemoveDynamicFlags(menu, 4);
                /* line 2309 */
                cg = *(cg_t **)imp_cg;
                cg->ammoFadeTime = 0;
            }
        }
    }

    /* line 2320: compass fade */
    fadeVal = *(float *)(*(byte **)imp_hud_fade_compass + 8);
    if (fadeVal != 0.0f) {
        cg = *(cg_t **)imp_cg;
        showTime = cg->compassFadeTime;
        if (showTime != 0) {
            serverTime = cg->time;
            if ((float)(serverTime - showTime) > fadeVal * 1000.0f) {
                /* line 2325 */
                if (CL_GetLocalClientActiveCount() == 1) {
                    menu = Menus_FindByName(*(void **)imp_cgDC, (const char *)str_002a79e0);
                } else {
                    menu = Menus_FindByName(*(void **)imp_cgDC, (const char *)str_002a79e8);
                }
                /* line 2329 */
                if (menu)
                    Window_RemoveDynamicFlags(menu, 4);
                /* line 2331 */
                cg = *(cg_t **)imp_cg;
                cg->compassFadeTime = 0;
            }
        }
    }

    /* line 2342: ADS / binocular check */
    {
        cg = *(cg_t **)imp_cg;
        int ps_eFlags = cg->nextSnap->ps.eFlags;
        if ((ps_eFlags & 0x8) && (ps_eFlags & 0x100)) {
            /* line 2345 */
            CG_MenuShowNotify(3);
        } else if ((ps_eFlags & 0x4) && (ps_eFlags & 0x200)) {
            /* line 2345 */
            CG_MenuShowNotify(3);
        }
    }

    /* line 2347: stance fade */
    fadeVal = *(float *)(*(byte **)imp_hud_fade_stance + 8);
    if (fadeVal != 0.0f) {
        cg = *(cg_t **)imp_cg;
        showTime = cg->stanceFadeTime;
        if (showTime != 0) {
            serverTime = cg->time;
            if ((float)(serverTime - showTime) > fadeVal * 1000.0f) {
                /* line 2354 */
                if (CL_GetLocalClientActiveCount() == 1) {
                    menu = Menus_FindByName(*(void **)imp_cgDC, (const char *)str_00221984);
                } else {
                    menu = Menus_FindByName(*(void **)imp_cgDC, (const char *)str_002b704c);
                }
                /* line 2359 */
                if (menu)
                    Window_RemoveDynamicFlags(menu, 4);
                /* line 2361 */
                cg = *(cg_t **)imp_cg;
                cg->stanceFadeTime = 0;
            }
        }
    }

    /* line 2373: offhand fade */
    fadeVal = *(float *)(*(byte **)imp_hud_fade_offhand + 8);
    if (fadeVal != 0.0f) {
        cg = *(cg_t **)imp_cg;
        showTime = cg->offhandFadeTime;
        if (showTime != 0) {
            serverTime = cg->time;
            if ((float)(serverTime - showTime) > fadeVal * 1000.0f) {
                /* line 2378 */
                if (CL_GetLocalClientActiveCount() == 1) {
                    menu = Menus_FindByName(*(void **)imp_cgDC, (const char *)str_002b7058);
                } else {
                    menu = Menus_FindByName(*(void **)imp_cgDC, (const char *)str_002b7064);
                }
                /* line 2382 */
                if (menu)
                    Window_RemoveDynamicFlags(menu, 4);
                /* line 2384 */
                cg = *(cg_t **)imp_cg;
                cg->offhandFadeTime = 0;
            }
        }
    }

    /* line 2396: scoreboard */
    if (CG_ScoreboardDisplayed()) {
        cg = *(cg_t **)imp_cg;
        serverTime = cg->time;
        if (serverTime - cg->scoreFadeTime > 100) {
            /* line 2401 */
            menu = Menus_FindByName(*(void **)imp_cgDC, (const char *)str_002b7074);
            if (menu)
                Window_RemoveDynamicFlags(menu, 4);
        }
    }

    return 0;
}

/* line 2507 */
static unsigned int CG_DrawSoundOverlay(void)
{
    snd_overlay_info_t info[64];
    const char *provider;
    const char *line;
    int cpu;
    int count;
    int bits;
    int khz;
    int channels;
    int i;
    float y;

    count = SND_GetSoundOverlay(
        (snd_overlay_type_t)(*(const dvar_t **)imp_cg_drawSoundOverlay)->current.integer,
        info,
        (int)(sizeof(info) / sizeof(info[0])),
        &cpu);
    if (count <= 0)
    {
        return 0;
    }

    provider = Dvar_GetString("mss_3d_provider");
    bits = Dvar_GetInt("snd_bits");
    khz = Dvar_GetInt("snd_khz");
    channels = Dvar_GetBool("snd_stereo") ? 2 : 1;

    CG_DrawStringExt(
        2.0f,
        82.0f,
        va("CPU: ^3%%%i ^73D provider: ^3%s ^7bits: ^3%i ^7kHz: ^3%i ^7chan: ^3%i", cpu, provider, bits, khz, channels),
        colorWhite,
        0,
        1,
        10.0f,
        0);

    y = 92.0f;
    for (i = 0; i < count; ++i)
    {
        if (info[i].pszSampleName)
        {
            line = va(
                "%2i %-50s vol^3%04.2f ^7rvol^3%04.2f ^7dist^3%5i ^7pit^3%04.2f",
                i,
                info[i].pszSampleName,
                info[i].fBaseVolume,
                info[i].fCurVolume,
                info[i].dist,
                info[i].fPitch);
        }
        else
        {
            line = va("%2i", i);
        }

        CG_DrawStringExt(2.0f, y, line, colorWhite, 0, 1, 10.0f, 0);
        y += 10.0f;
    }

    return 0;
}

/* line 2715 */
unsigned int CG_DrawMaterial(void)
{
    cg_t *cg;
    char szName[0x58];
    char szSurfaceFlags[0x1000];
    char szContents[0x1000];
    float y;

    cg = (cg_t *)*cg_glob;
    if (!CL_PickMaterial((const vec_t *)cg->refdef.vieworg, (const vec_t *)cg->refdef.viewaxis, szName, szSurfaceFlags, szContents, (int)&__mh_execute_header))
    {
        return 0;
    }

    y = 240.0f;
    y += (float)CG_DrawSmallDevStringColor(8.0f, y, szName, colorWhite, 5);
    y += (float)CG_DrawSmallDevStringColor(8.0f, y, szSurfaceFlags, colorWhite, 5);
    CG_DrawSmallDevStringColor(8.0f, y, szContents, colorWhite, 5);
    return 0;
}

/* line 2896 */
unsigned int CG_ShakeCamera(void)
{
    cg_t *cg;
    cameraShake_t *shake;
    float sx;
    float bestSize;
    float bestRumble;
    float phase;
    int i;

    cg = *(cg_t **)imp_cg;
    sx = (float)cg->time / 600.0f;
    bestSize = 0.0f;
    bestRumble = 0.0f;

    for (i = 0; i < 4; ++i)
    {
        shake = &cg->cameraShake[i];
        if (!CG_UpdateCameraShakeStrength(cg, shake))
        {
            continue;
        }

        if (shake->size > bestSize)
        {
            bestSize = shake->size;
            bestRumble = shake->rumbleScale;
        }
    }

    if (cg->rumbleScale > bestSize)
    {
        bestSize = cg->rumbleScale;
        bestRumble = cg->rumbleScale;
    }

    if (bestSize <= 0.0f)
    {
        cg->cameraShakePhase = crandom() * 3.14159265358979323846f;
        return 0;
    }

    if (bestSize > 1.0f)
    {
        bestSize = 1.0f;
    }

    phase = cg->cameraShakePhase;
    cg->kickAngles[0] += (float)sin((double)(sx * 25.132741228718345f + phase)) * bestRumble * 18.0f * bestSize;
    cg->kickAngles[1] += (float)sin((double)(sx * 47.12388980384689f + phase)) * bestRumble * 16.0f * bestSize;
    cg->kickAngles[2] += (float)sin((double)(sx * 37.69911184307752f + phase)) * bestRumble * 10.0f * bestSize;
    return 0;
}

/* line 3216 */
qboolean CG_DrawFollow(void)
{
    cg_t *cg;
    clientInfo_t *clientInfo;
    const char *clientName;
    const char *followingString;
    FontHandle font;
    float scale;
    int textWidth;

    cg = *(cg_t **)imp_cg;
    if (!(cg->snap->ps.pm_flags & 0x400000))
    {
        return 0;
    }

    if (cg->inKillCam)
    {
        return 0;
    }

    clientInfo = &((clientInfo_t *)((byte *)cg + 0xe0914))[cg->snap->ps.clientNum];
    if (clientInfo->infoValid)
    {
        clientName = clientInfo->name;
    }
    else
    {
        clientName = str_0022292c;
    }

    followingString = SEH_LocalizeTextMessage(str_002b7124, str_002b710c, 0);
    scale = CL_IsRenderingSplitScreen() ? 0.5f : (1.0f / 3.0f);
    font = UI_GetFontHandle(0, 1.0f / 3.0f);

    textWidth = UI_TextWidth(followingString, 0, font, scale);
    UI_DrawText(followingString, 0x7fffffff, font, (float)(-textWidth) * 0.5f, 40.0f, 7, 1, scale, colorWhite, 3);

    textWidth = UI_TextWidth(clientName, 0, font, scale);
    UI_DrawText(clientName, 0x7fffffff, font, (float)(-textWidth) * 0.5f, 65.0f, 7, 1, scale, colorWhite, 3);

    return 1;
}

/* line 3257 */
unsigned int CG_DrawPlayerSprites(void)
{
    cg_t *cg;
    snapshot_t *snap;
    int entityIndex;
    centity_t *cent;

    cg = (byte *)*cg_glob;
    snap = cg->nextSnap;
    for (entityIndex = 0; entityIndex < snap->numEntities; ++entityIndex)
    {
        cent = &(*cg_entities_glob)[snap->entities[entityIndex].number];
        if (cent->currentState.eType == 1)
        {
            CG_PlayerSprites(cent);
        }
    }

    return 0;
}

/* line 3404 */
unsigned int CG_DrawActive(void) {
    cg_t *cg = *(cg_t **)imp_cg;
    float sensitivity;
    float angles[3];

    /* Copy viewModelAngle to viewAngle backup */
    cg->refdef.time = cg->time;
    cg->refdef.viewIndex = 0;

    /* Compute sensitivity with shellshock modifier */
    sensitivity = cg->zoomSensitivity;
    {
        float shellshockSensitivity = cg->shellshock.sensitivity;
        if (shellshockSensitivity != 0.0f)
            sensitivity *= shellshockSensitivity;
    }

    /* Compute combined aim angles = gunAngles + cmdAngles */
    angles[0] = cg->kickAngles[0] + cg->offsetAngles[0];
    angles[1] = cg->kickAngles[1] + cg->offsetAngles[1];
    angles[2] = cg->kickAngles[2] + cg->offsetAngles[2];

    CL_SetUserCmdAimValues(angles);
    CL_SetUserCmdValue(cg->weaponSelect, cg->equippedOffHand, sensitivity);

    /* Render the scene */
    CL_RenderScene(&cg->refdef);

    /* If not split screen, draw shellshock saved screen blend */
    if (!CL_IsRenderingSplitScreen()) {
        CG_DrawShellShockSavedScreenBlend(
            *(float *)&cg->shellshock.parms,
            *(float *)&cg->shellshock.startTime,
            *(float *)&cg->shellshock.duration
        );
    }

    CG_TileClear();
    return 0;
}

/* line 549 */
unsigned int CG_DrawChatMessages(void)
{
    cg_t *cg;
    cgs_t *cgs;
    FontHandle font;
    const char *msg;
    vec4_t color;
    float alphaPercent;
    float backgroundAlpha;
    float y;
    float timeRemaining;
    int chatHeight;
    int hudChatX;
    int hudChatY;
    int chatTime;
    int index;
    int i;
    int textWidth;

    chatHeight = (*(const dvar_t **)imp_cg_chatHeight)->current.integer;
    if (!chatHeight)
    {
        return 0;
    }

    hudChatX = (int)(*(const dvar_t **)imp_cg_hudChatPosition)->current.vector[0];
    hudChatY = (int)(*(const dvar_t **)imp_cg_hudChatPosition)->current.vector[1];
    cgs = *(cgs_t **)imp_cgs;
    if (cgs->teamLastChatPos == cgs->teamChatPos)
    {
        return 0;
    }

    cg = *(cg_t **)imp_cg;
    index = cgs->teamLastChatPos % chatHeight;
    chatTime = (*(const dvar_t **)imp_cg_chatTime)->current.integer;
    if (cg->time - cgs->teamChatMsgTimes[index] > chatTime)
    {
        ++cgs->teamLastChatPos;
    }

    font = UI_GetFontHandle(0, 1.0f / 3.0f);
    for (i = cgs->teamChatPos - 1; i >= cgs->teamLastChatPos; --i)
    {
        index = i % chatHeight;
        timeRemaining = (float)chatTime - (float)(cg->time - cgs->teamChatMsgTimes[index]);
        if (timeRemaining > 200.0f)
        {
            alphaPercent = 1.0f;
            backgroundAlpha = 0.60000002f;
        }
        else
        {
            alphaPercent = timeRemaining / 200.0f;
            if (alphaPercent <= 0.0f)
            {
                continue;
            }

            backgroundAlpha = alphaPercent * 0.60000002f;
        }

        msg = cgs->teamChatMsgs[index];
        if (msg[0] == '^' && msg[1] && msg[1] != '^' && msg[1] >= '0' && msg[1] <= '9')
        {
            CL_LookupColor((unsigned char)msg[1], color);
        }
        else
        {
            color[0] = 1.0f;
            color[1] = 1.0f;
            color[2] = 1.0f;
        }

        color[0] *= 0.25f;
        color[1] *= 0.25f;
        color[2] *= 0.25f;
        color[3] = backgroundAlpha;

        y = (float)(hudChatY - (cgs->teamChatPos - i) * 10);
        textWidth = UI_TextWidth(msg, 0, font, 1.0f / 3.0f);
        UI_DrawHandlePic(0.0f, y, (float)(textWidth + 24), 10.0f, 1, 1, color, cgs->media.whiteMaterial);

        color[0] = 1.0f;
        color[1] = 1.0f;
        color[2] = 1.0f;
        color[3] = alphaPercent;
        UI_DrawText(msg, 0x7fffffff, font, (float)hudChatX, y + 9.0f, 1, 1, 1.0f / 3.0f, color, 3);
    }

    return 0;
}

/* line 1110 */
static void __attribute_regparm__(2) CG_CalcCrosshairPosition(float *x, float *y)
{
    cg_t *cg;
    vec3_t gunAng;
    vec3_t gunDir;
    float forward;
    float horiz;
    float vert;

    cg = *(cg_t **)imp_cg;
    gunAng[0] = cg->gunPitch;
    gunAng[1] = cg->gunYaw;
    gunAng[2] = cg->refdefViewAngles[2];
    AngleVectors(gunAng, gunDir, NULL, NULL);

    forward =
        gunDir[0] * cg->refdef.viewaxis[0][0] +
        gunDir[1] * cg->refdef.viewaxis[0][1] +
        gunDir[2] * cg->refdef.viewaxis[0][2];
    if (forward <= 0.0f || cg->refdef.fov_x <= 0.0f || cg->refdef.fov_y <= 0.0f)
    {
        *x = 0.0f;
        *y = 0.0f;
        return;
    }

    horiz =
        gunDir[0] * cg->refdef.viewaxis[1][0] +
        gunDir[1] * cg->refdef.viewaxis[1][1] +
        gunDir[2] * cg->refdef.viewaxis[1][2];
    *x = horiz / (forward * (float)tan((double)cg->refdef.fov_x * 0.008726646259971648)) * -320.0f;

    vert =
        gunDir[0] * cg->refdef.viewaxis[2][0] +
        gunDir[1] * cg->refdef.viewaxis[2][1] +
        gunDir[2] * cg->refdef.viewaxis[2][2];
    *y = vert / (forward * (float)tan((double)cg->refdef.fov_y * 0.008726646259971648)) * -240.0f;
}

/* line 286 */
static float CG_DrawFPS(float y) { return 0.0f; }
