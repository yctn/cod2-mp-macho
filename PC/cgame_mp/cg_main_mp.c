/* ASM dump from: cg_main_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_main_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

extern struct XModel * CL_RegisterModel(const char *name);
extern snd_alias_t *CL_PickSoundAlias(const char *aliasname);
extern const char *CL_GetConfigString(int index);
extern void CL_SubtitlePrint(const char *pszText, int iDuration, int iLineWidth);
extern int atoi(const char *nptr);
extern const char *Info_ValueForKey(const char *s, const char *key);
extern const char *SEH_LocalizeTextMessage(const char *msg, const char *context, int errType);
extern void SND_PlayAmbientAlias(const snd_alias_t *pAlias, int fadetime, snd_alias_system_t system);
extern int SND_PlaySoundAliasAsMaster(const snd_alias_t *pAlias, int entnum, const vec_t *org, int timeshift, snd_alias_system_t system);
extern int SND_PlaySoundAlias(const snd_alias_t *pAlias, int entnum, const vec_t *org, int timeshift, snd_alias_system_t system);
extern snd_alias_t *Com_PickSoundAliasFromList(snd_alias_list_t *aliasList);
extern MenuList * UI_LoadMenus(const char *menuFile, int imageTrack);
extern void UI_AddMenuList(displayContextDef_t *dc, MenuList *menuList);
extern int CL_GetLocalClientActiveCount(void);
extern menuDef_t * Menus_FindByName(displayContextDef_t *dc, const char *p);
extern int Com_ClientDObjCreate(DObjModel_s *dobjModels, int numModels, struct XAnimTree_s *tree, int handle);
extern int CG_WeaponDObjHandle(int weaponNum);
extern int Com_SafeClientDObjFree(int handle);
extern void XAnimFreeTree(struct XAnimTree_s *tree, void *Free);
extern int BG_GetNumWeapons(void);
extern void AxisCopy(vec3_t *in, vec3_t *out);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern void CL_TrackStatistics(trStatistics_t *pStats);
extern void SND_FadeAllSounds(float volume, int fadetime);
extern void Mantle_ShutdownAnims(void);
extern void CG_FreeClientDObjInfo(void);
extern void CG_FreeEntityDObjInfo(void);
extern void CL_FreeWeaponInfoMemory(void);
extern void FX_FreeSystem(void);
extern unsigned int Scr_ShutdownGameStrings(void);
extern void * Hunk_AllocAlignInternal(int size, int alignment);
extern void * Hunk_AllocInternal(int size);
extern void CL_ConsolePrint(int channel, const char *msg, int duration, int width);
extern void SCR_UpdateScreen(void);
extern void Com_Printf(const char *fmt, ...);
extern void FX_InitSystem(int maxEffects);
extern void FX_CreateDefaultEffect(void);
extern void CG_LoadingString(const char *str);
extern int CL_RegisterMaterial(const char *name, int flags);
extern int CL_RegisterMaterialNoMip(const char *name, int flags);
extern void CG_RegisterScoreboardGraphics(void);
extern void CG_RegisterItems(void);
extern int CM_NumInlineModels(void);
extern int CL_RegisterInlineModel(int index);
extern void CL_ModelBounds(int model, float *mins, float *maxs);
extern int FX_RegisterEffect(const char *name);
extern void CG_SetShellShockParmsFromDvars(byte *parms);
extern int CG_LoadShellShockDvars(const char *name);
extern void Com_Error(int code, const char *fmt, ...);
extern int CG_RegisterImpactEffects(const char *mapname);
extern void Controls_GetConfig(void);
extern int GetKeyBindingLocalizedString(const char *binding, char *buf);
extern const char *UI_SafeTranslateString(const char *key);
extern void AnglesToAxis(const vec_t *angles, vec3_t *axis);
extern void Cmd_ArgvBuffer(int arg, char *buffer, int bufferLength);

extern const centity_t * cg_entities; /* 0x0 */
extern const weaponInfo_t * cg_weapons; /* 0x0 */
extern const itemInfo_t * cg_items; /* 0x0 */
extern const cgs_t * cgs; /* 0x0 */
extern const cg_t * cg; /* 0x0 */
extern const dvar_t *cg_centertime; /* 0x0 */
extern const dvar_t *cg_drawFPS; /* 0x0 */
extern const dvar_t *cg_drawSoundOverlay; /* 0x0 */
extern const dvar_t *cg_drawScriptUsage; /* 0x0 */
extern const dvar_t *cg_drawMaterial; /* 0x0 */
extern const dvar_t *cg_drawSnapshot; /* 0x0 */
extern const dvar_t *cg_drawCrosshair; /* 0x0 */
extern const dvar_t *cg_hudCompassSize; /* 0x0 */
extern const dvar_t *cg_hudCompassMaxRange; /* 0x0 */
extern const dvar_t *cg_hudCompassMinRange; /* 0x0 */
extern const dvar_t *cg_hudCompassMinRadius; /* 0x0 */
extern const dvar_t *cg_hudCompassSpringyPointers; /* 0x0 */
extern const dvar_t *cg_hudCompassSoundPingFadeTime; /* 0x0 */
extern const dvar_t *cg_hudObjectiveMinHeight; /* 0x0 */
extern const dvar_t *cg_hudObjectiveMaxRange; /* 0x0 */
extern const dvar_t *cg_hudObjectiveMinAlpha; /* 0x0 */
extern const dvar_t *cg_hudStanceFlash; /* 0x0 */
extern const dvar_t *cg_hudStanceHintPrints; /* 0x0 */
extern const dvar_t *cg_hudDamageIconWidth; /* 0x0 */
extern const dvar_t *cg_hudDamageIconHeight; /* 0x0 */
extern const dvar_t *cg_hudDamageIconOffset; /* 0x0 */
extern const dvar_t *cg_hudDamageIconTime; /* 0x0 */
extern const dvar_t *cg_hudDamageIconInScope; /* 0x0 */
extern const dvar_t *cg_hudGrenadeIconInScope; /* 0x0 */
extern const dvar_t *cg_hudGrenadeIconMaxRange; /* 0x0 */
extern const dvar_t *cg_hudGrenadeIconMaxHeight; /* 0x0 */
extern const dvar_t *cg_hudGrenadeIconOffset; /* 0x0 */
extern const dvar_t *cg_hudGrenadeIconHeight; /* 0x0 */
extern const dvar_t *cg_hudGrenadeIconWidth; /* 0x0 */
extern const dvar_t *cg_hudGrenadePointerHeight; /* 0x0 */
extern const dvar_t *cg_hudGrenadePointerWidth; /* 0x0 */
extern const dvar_t *cg_hudGrenadePointerPivot; /* 0x0 */
extern const dvar_t *cg_hudGrenadePointerPulseFreq; /* 0x0 */
extern const dvar_t *cg_hudGrenadePointerPulseMax; /* 0x0 */
extern const dvar_t *cg_hudGrenadePointerPulseMin; /* 0x0 */
extern const dvar_t *cg_hudChatPosition; /* 0x0 */
extern const dvar_t *cg_hudSayPosition; /* 0x0 */
extern const dvar_t *cg_hudProneY; /* 0x0 */
extern const dvar_t *cg_weaponCycleDelay; /* 0x0 */
extern const dvar_t *cg_crosshairAlpha; /* 0x0 */
extern const dvar_t *cg_crosshairAlphaMin; /* 0x0 */
extern const dvar_t *cg_crosshairDynamic; /* 0x0 */
extern const dvar_t *cg_crosshairEnemyColor; /* 0x0 */
extern const dvar_t *cg_drawHealth; /* 0x0 */
extern const dvar_t *cg_drawBreathHint; /* 0x0 */
extern const dvar_t *cg_drawMantleHint; /* 0x0 */
extern const dvar_t *cg_draw2D; /* 0x0 */
extern const dvar_t *cg_debugEvents; /* 0x0 */
extern const dvar_t *cg_errorDecay; /* 0x0 */
extern const dvar_t *cg_nopredict; /* 0x0 */
extern const dvar_t *cg_showmiss; /* 0x0 */
extern const dvar_t *cg_footsteps; /* 0x0 */
extern const dvar_t *cg_marks; /* 0x0 */
extern const dvar_t *cg_marksLimit; /* 0x0 */
extern const dvar_t *cg_brass; /* 0x0 */
extern const dvar_t *cg_gun_x; /* 0x0 */
extern const dvar_t *cg_gun_y; /* 0x0 */
extern const dvar_t *cg_gun_z; /* 0x0 */
extern const dvar_t *cg_gun_move_f; /* 0x0 */
extern const dvar_t *cg_gun_move_r; /* 0x0 */
extern const dvar_t *cg_gun_move_u; /* 0x0 */
extern const dvar_t *cg_gun_ofs_f; /* 0x0 */
extern const dvar_t *cg_gun_ofs_r; /* 0x0 */
extern const dvar_t *cg_gun_ofs_u; /* 0x0 */
extern const dvar_t *cg_gun_move_rate; /* 0x0 */
extern const dvar_t *cg_gun_move_minspeed; /* 0x0 */
extern const dvar_t *cg_drawGun; /* 0x0 */
extern const dvar_t *cg_cursorHints; /* 0x0 */
extern const dvar_t *cg_hintFadeTime; /* 0x0 */
extern const dvar_t *cg_viewsize; /* 0x0 */
extern const dvar_t *cg_tracerChance; /* 0x0 */
extern const dvar_t *cg_tracerWidth; /* 0x0 */
extern const dvar_t *cg_tracerLength; /* 0x0 */
extern const dvar_t *cg_tracerSpeed; /* 0x0 */
extern const dvar_t *cg_tracerScale; /* 0x0 */
extern const dvar_t *cg_tracerScaleMinDist; /* 0x0 */
extern const dvar_t *cg_tracerScaleDistRange; /* 0x0 */
extern const dvar_t *cg_fov; /* 0x0 */
extern const dvar_t *cg_fovMin; /* 0x0 */
extern const dvar_t *cg_fovScale; /* 0x0 */
extern const dvar_t *cg_thirdPersonRange; /* 0x0 */
extern const dvar_t *cg_thirdPersonAngle; /* 0x0 */
extern const dvar_t *cg_thirdPerson; /* 0x0 */
extern const dvar_t *cg_synchronousClients; /* 0x0 */
extern const dvar_t *cg_paused; /* 0x0 */
extern const dvar_t *cg_predictItems; /* 0x0 */
extern const dvar_t *cg_dumpAnims; /* 0x0 */
extern const dvar_t *cg_developer; /* 0x0 */
extern const dvar_t *cg_minicon; /* 0x0 */
extern const dvar_t *cg_subtitles; /* 0x0 */
extern const dvar_t *cg_subtitleMinTime; /* 0x0 */
extern const dvar_t *cg_subtitleWidthStandard; /* 0x0 */
extern const dvar_t *cg_subtitleWidthWidescreen; /* 0x0 */
extern const dvar_t *cg_subtitlePosX; /* 0x0 */
extern const dvar_t *cg_subtitlePosY; /* 0x0 */
extern const dvar_t *cg_subtitleCharHeight; /* 0x0 */
extern const dvar_t *cg_gameMessageWidth; /* 0x0 */
extern const dvar_t *cg_gameBoldMessageWidth; /* 0x0 */
extern const dvar_t *cg_drawGameMessages; /* 0x0 */
extern const dvar_t *cg_scoreboardScrollStep; /* 0x0 */
extern const dvar_t *cg_scoreboardBannerHeight; /* 0x0 */
extern const dvar_t *cg_scoreboardItemHeight; /* 0x0 */
extern const dvar_t *cg_chatTime; /* 0x0 */
extern const dvar_t *cg_chatHeight; /* 0x0 */
extern const dvar_t *cg_teamChatsOnly; /* 0x0 */
extern const dvar_t *cg_noTaunt; /* 0x0 */
extern const dvar_t *cg_voiceSpriteTime; /* 0x0 */
extern const dvar_t *cg_descriptiveText; /* 0x0 */
extern const dvar_t *cg_drawCrosshairNames; /* 0x0 */
extern const dvar_t *cg_drawTurretCrosshair; /* 0x0 */
extern const dvar_t *cg_debugPosition; /* 0x0 */
extern const dvar_t *cg_shock_screenBlendTime; /* 0x0 */
extern const dvar_t *cg_shock_screenBlendFadeTime; /* 0x0 */
extern const dvar_t *cg_shock_viewKickPeriod; /* 0x0 */
extern const dvar_t *cg_shock_viewKickRadius; /* 0x0 */
extern const dvar_t *cg_shock_sound; /* 0x0 */
extern const dvar_t *cg_shock_soundFadeInTime; /* 0x0 */
extern const dvar_t *cg_shock_soundFadeOutTime; /* 0x0 */
extern const dvar_t *cg_shock_soundLoopFadeTime; /* 0x0 */
extern const dvar_t *cg_shock_soundLoopEndDelay; /* 0x0 */
extern const dvar_t *cg_shock_soundRoomType; /* 0x0 */
extern const dvar_t *cg_shock_soundDryLevel; /* 0x0 */
extern const dvar_t *cg_shock_soundWetLevel; /* 0x0 */
extern const dvar_t *cg_shock_soundModEndDelay; /* 0x0 */
extern const dvar_t *cg_shock_volume_auto; /* 0x0 */
extern const dvar_t *cg_shock_volume_auto2d; /* 0x0 */
extern const dvar_t *cg_shock_volume_menu; /* 0x0 */
extern const dvar_t *cg_shock_volume_weapon; /* 0x0 */
extern const dvar_t *cg_shock_volume_voice; /* 0x0 */
extern const dvar_t *cg_shock_volume_item; /* 0x0 */
extern const dvar_t *cg_shock_volume_body; /* 0x0 */
extern const dvar_t *cg_shock_volume_local; /* 0x0 */
extern const dvar_t *cg_shock_volume_music; /* 0x0 */
extern const dvar_t *cg_shock_volume_announcer; /* 0x0 */
extern const dvar_t *cg_shock_volume_shellshock; /* 0x0 */
extern const dvar_t *cg_shock_mouse; /* 0x0 */
extern const dvar_t *cg_shock_mouse_maxpitchspeed; /* 0x0 */
extern const dvar_t *cg_shock_mouse_maxyawspeed; /* 0x0 */
extern const dvar_t *cg_shock_mouse_sensitivityscale; /* 0x0 */
extern const dvar_t *cg_shock_mouse_fadeTime; /* 0x0 */
extern const dvar_t *cg_scriptIconSize; /* 0x0 */
extern const dvar_t *cg_youInKillCamSize; /* 0x0 */
extern const dvar_t *cg_connectionIconSize; /* 0x0 */
extern const dvar_t *cg_voiceIconSize; /* 0x0 */
extern const dvar_t *cg_constantSizeHeadIcons; /* 0x0 */
extern const dvar_t *cg_headIconMinScreenRadius; /* 0x0 */
extern const dvar_t *cg_blood; /* 0x0 */
extern displayContextDef_t cgDC; /* 0x0 */
extern const dvar_t *cg_drawCrosshairNamesPosX; /* 0x0 */
extern const dvar_t *cg_drawCrosshairNamesPosY; /* 0x0 */
extern const dvar_t *cg_centerPrintY; /* 0x0 */
extern const dvar_t *cg_drawLagometer; /* 0x0 */
extern const dvar_t *cg_weaponleftbone; /* 0x0 */
extern const dvar_t *cg_weaponrightbone; /* 0x0 */
static char buffer[1024]; /* buffer */
static cg_t cgArray[1]; /* cgArray */
static cgs_t cgsArray[1]; /* cgsArray */
static centityArray_t cg_entitiesArray[1]; /* cg_entitiesArray */
static cg_weaponsArray_t cg_weaponsArray; /* cg_weaponsArray */
static cg_itemsArray_t cg_itemsArray; /* cg_itemsArray */
static Bool g_ambientStarted; /* g_ambientStarted */
static Bool g_mapLoaded; /* g_mapLoaded */

__attribute__((used)) const char *cg_soundRoomTypes[27] = {
    "generic",
    "paddedcell",
    "room",
    "bathroom",
    "livingroom",
    "stoneroom",
    "auditorium",
    "concerthall",
    "cave",
    "arena",
    "hangar",
    "carpetedhallway",
    "hallway",
    "stonecorridor",
    "alley",
    "forest",
    "city",
    "mountains",
    "quarry",
    "plain",
    "parkinglot",
    "sewerpipe",
    "underwater",
    "drugged",
    "dizzy",
    "psychotic",
    0,
}; /* 0x311b80 */
__attribute__((used)) const char *cg_drawSoundOverlayStrings[5] = {
    "None",
    "Off",
    "Simple",
    "Verbose",
    "Time",
}; /* 0x311bec */
__attribute__((used)) const char *cg_drawFpsNames[8] = {
    "3D",
    "Stream",
    "2D",
    "None",
    0,
    0,
    0,
    0,
}; /* 0x311c00 */

void CG_GetEntityOrientation(int entnum, vec_t *origin_out, vec3_t *axis_out);
int CG_CrosshairPlayer(void);
void CG_GameMessage(const char *msg);
void CG_BoldGameMessage(const char *msg);
const char * CG_Argv(int arg);
static void CG_RegisterGraphics(const char *mapname);
void CG_StartAmbient(void);
Bool CG_PlaySoundOnFirstClient(void);
Bool CG_PlaySoundOnCurrentLocalClient(int entitynum, const vec_t *origin, const char *aliasname);
static Bool CG_ReplaceDirective(int *searchPos, int *dstLen, char *dstString);
void CG_TranslateHudElemMessage(const char *message, const char *messageType, char *hudElemString);
static void CG_LoadHudMenu(void);
void CG_InitVote(void);
static struct XModel * CG_GetXModel(const char *modelName);
static void CG_CreateDObj(DObjModel_s *dobjModels, int numModels, struct XAnimTree_s *tree, int handle, clientInfo_t *ci);
void CG_FreeWeapons(void);
void CG_Shutdown(void);
void * Hunk_AllocXAnimPrecache(int size);
void * Hunk_AllocXAnimClient(int size);
int CG_PlaySoundAliasAsMasterByName(int entitynum, const vec_t *origin, const char *aliasname);
void CG_GetDObjOrientation(int dobjHandle, orientation_t *orient);
void CG_PlaySmokeGrenadesAtTime(int gametime);
int CG_PlaySoundAlias(int entitynum, const vec_t *origin, snd_alias_list_t *aliasList);
int CG_PlaySoundAliasByName(int entitynum, const vec_t *origin, const char *aliasname);
void CG_SafeTranslateHudElemString(int index, char *hudElemString);
int CG_PlayClientSoundAliasByName(const char *aliasname);
int CG_PlayClientSoundAlias(snd_alias_list_t *aliasList);
int CG_PlayEntitySoundAlias(int entitynum, snd_alias_list_t *aliasList);
static void CG_RegisterSounds(void);
void CG_Init(int serverMessageNum, int serverCommandSequence, int clientNum);

/* line 716 */
void CG_GetEntityOrientation(int entnum, vec_t *origin_out, vec3_t *axis_out)
{
    char *ent = (char *)cg_entities + entnum * 548;
    vec_t *origin = (vec_t *)((centity_t *)ent)->lerpOrigin;
    origin_out[0] = origin[0];
    origin_out[1] = origin[1];
    origin_out[2] = origin[2];
    AnglesToAxis((vec_t *)((centity_t *)ent)->lerpAngles, axis_out);
}

/* line 727 */
int CG_CrosshairPlayer(void)
{
    if (cgArray[0].time > cgArray[0].crosshairClientTime + 0x3e8)
        return -1;
    return cgArray[0].crosshairClientNum;
}

/* line 737 */
void CG_GameMessage(const char *msg)
{
    CL_ConsolePrint(1, msg, 0, cg_gameMessageWidth->current.integer);
}

/* line 743 */
void CG_BoldGameMessage(const char *msg)
{
    CL_ConsolePrint(2, msg, 0, cg_gameBoldMessageWidth->current.integer);
}

/* line 754 */
const char * CG_Argv(int arg)
{
    Cmd_ArgvBuffer(arg, (char *)&buffer, 0x400);
    return (const char *)&buffer;
}

/* line 862 */
/* CG_RegisterGraphics rewritten in clean C in cg_registergraphics_new.c */

/* line 1043 */
void CG_StartAmbient(void)
{
    const char *infoString;
    int fadeTime;

    infoString = CL_GetConfigString(3);
    SND_PlayAmbientAlias(
        CL_PickSoundAlias(Info_ValueForKey(infoString, "n")),
        ((fadeTime = atoi(Info_ValueForKey(infoString, "t"))) - cg->time < 0 || cg->time == 0) ? 0 : fadeTime - cg->time,
        1);
}

/* line 1120 */
Bool CG_PlaySoundOnFirstClient(void)
{
    return 1;
}

/* line 1150 */
Bool CG_PlaySoundOnCurrentLocalClient(int entitynum, const vec_t *origin, const char *aliasname)
{
    return 1;
}

/* line 1290 */
static Bool CG_ReplaceDirective(int *searchPos, int *dstLen, char *dstString)
{
    char srcString[0x100];
    char directive[0x100];
    char keyBinding[0x100];
    char *pFound;
    char *pEnd;
    int directiveLen;
    int bindingLen;
    int newStringLen;
    int beginLen;
    int endLen;
    char *dst;

    /* line 1311: copy dstString to srcString */
    memcpy(srcString, dstString, *dstLen);
    srcString[*dstLen] = '\0';

    /* line 1314: search for "[{" from searchPos */
    pFound = (char *)strstr(srcString + *searchPos, (const char *)"[{");
    if (!pFound)
        return 0;

    /* line 1318: search for "}]" */
    pEnd = (char *)strstr(pFound, (const char *)"}]");
    if (!pEnd)
        return 0;

    /* line 1327-1329: compute directive length (excluding "[{" and "}]") */
    directiveLen = (int)(pEnd - pFound) - 2;
    if (directiveLen == 0)
        return 0;

    /* line 1337 */
    Controls_GetConfig();

    /* line 1338: copy directive text */
    memcpy(directive, pFound + 2, directiveLen);
    directive[directiveLen] = '\0';

    /* line 1341: get key binding */
    if (!GetKeyBindingLocalizedString(directive, keyBinding)) {
        /* line 1342: fallback to "KEY_UNBOUND" */
        I_strncpyz(keyBinding, UI_SafeTranslateString((const char *)"KEY_UNBOUND"), 0x100);
    }

    /* line 1344: compute strlen of keyBinding using inline repne scasb equivalent */
    {
        int len = 0;
        while (keyBinding[len] != '\0') len++;
        bindingLen = len;
    }

    /* line 1346: compute newStringLen */
    newStringLen = *dstLen - directiveLen + bindingLen - 4;

    /* line 1348: check overflow */
    if (*dstLen - directiveLen + bindingLen - 3 > 0x100)
        return 0;

    /* line 1357: compute beginLen = offset of "[{" in srcString */
    beginLen = (int)(pFound - srcString);

    /* line 1358-1360: write binding into dstString at beginLen */
    dst = dstString + beginLen;
    memcpy(dst, keyBinding, bindingLen);
    dst += bindingLen;

    /* line 1364-1366: compute and copy end portion */
    endLen = newStringLen - beginLen - bindingLen;
    memcpy(dst, pEnd + 2, endLen);
    dst[endLen] = '\0';

    /* line 1368: update searchPos */
    *searchPos = bindingLen + beginLen;

    /* line 1369: update dstLen */
    *dstLen = newStringLen;

    return 1;
}

static void CG_LocalizeHudElemString(const char *message, const char *messageType, char *hudElemString)
{
    const char *localizedString;
    int searchPos;
    int stringLen;

    localizedString = SEH_LocalizeTextMessage(message, messageType, 0);
    for (stringLen = 0; localizedString[stringLen]; ++stringLen) {
    }

    if (stringLen >= 0x100) {
        return;
    }

    memcpy(hudElemString, localizedString, stringLen);
    hudElemString[stringLen] = '\0';

    searchPos = 0;
    while (CG_ReplaceDirective(&searchPos, &stringLen, hudElemString)) {
    }
}

/* line 1376 */
void CG_TranslateHudElemMessage(const char *message, const char *messageType, char *hudElemString)
{
    CG_LocalizeHudElemString(message, messageType, hudElemString);
}

/* line 1529 */
static
void CG_LoadHudMenu(void)
{
    MenuList *menuList;
    menuDef_t *menu;

    menuList = UI_LoadMenus("ui_mp/hud.txt", 7);
    UI_AddMenuList(&cgDC, menuList);

    if (CL_GetLocalClientActiveCount() == 1) {
        menu = Menus_FindByName(&cgDC, "Compass");
    } else {
        menu = Menus_FindByName(&cgDC, "Compass_mp");
    }

    if (menu != NULL) {
        /* menuDef_t/window layout is still partially suspect; keep the recovered rect offsets local here. */
        ((cgs_t *)cgs)->compassWidth  = menu->window.rect[0].w;
        ((cgs_t *)cgs)->compassHeight = menu->window.rect[0].h;
        ((cgs_t *)cgs)->compassY      = menu->window.rect[0].y;
    }
}

/* line 1563 */
void CG_InitVote(void)
{
    ((cgs_t *)cgs)->voteTime = atoi(CL_GetConfigString(0xf));
    ((cgs_t *)cgs)->voteYes = atoi(CL_GetConfigString(0x11));
    ((cgs_t *)cgs)->voteNo = atoi(CL_GetConfigString(0x12));
    I_strncpyz(cgs->voteString, SEH_LocalizeTextMessage(CL_GetConfigString(0x10), "vote string", 0), 0x100);
}

/* line 1578 */
static struct XModel * CG_GetXModel(const char *modelName)
{
    return CL_RegisterModel(modelName);
}

/* line 1590 */
static void CG_CreateDObj(DObjModel_s *dobjModels, int numModels, struct XAnimTree_s *tree, int handle, clientInfo_t *ci)
{
    int weaponNum;
    struct XModel *weaponModel;

    weaponNum = ci->iDObjWeapon;
    if (weaponNum) {
        /* weaponInfo_t is still partially inaccurate here; 0xbc is the weapon world model slot. */
        weaponModel = cg_weapons[weaponNum].worldSurfModel;
        if (weaponModel) {
            dobjModels[numModels].model = weaponModel;
            dobjModels[numModels].boneName = ci->leftHandGun ? cg_weaponleftbone->current.string : cg_weaponrightbone->current.string;
            dobjModels[numModels].ignoreCollision = 0;
            ++numModels;
        }
    }

    Com_ClientDObjCreate(dobjModels, numModels, tree, handle);
}

/* line 1949 */
void CG_FreeWeapons(void)
{
    int i;
    int weaponCount;
    byte *weaponInfo;

    weaponCount = BG_GetNumWeapons();
    weaponInfo = (byte *)cg_weapons + 0x1b4;

    for (i = 1; i <= weaponCount; ++i, weaponInfo += 0x1b4) {
        Com_SafeClientDObjFree(CG_WeaponDObjHandle(i));
        if (((weaponInfo_t *)weaponInfo)->tree) {
            XAnimFreeTree(((weaponInfo_t *)weaponInfo)->tree, 0);
            ((weaponInfo_t *)weaponInfo)->tree = NULL;
        }
    }

    memset((void *)cg_items, 0, 0x2400);
    memset((void *)cg_weapons, 0, 0xda00);
}

/* line 1975 */
void CG_Shutdown(void)
{
    byte *cgBase;
    byte *cgsBase;
    int i;

    CL_TrackStatistics(0);
    SND_FadeAllSounds(1.0f, 0);
    g_ambientStarted = 0;
    g_mapLoaded = 0;
    Mantle_ShutdownAnims();
    CG_FreeWeapons();
    CG_FreeClientDObjInfo();
    CG_FreeEntityDObjInfo();
    CL_FreeWeaponInfoMemory();
    FX_FreeSystem();

    cgBase = (byte *)cg;
    for (i = 0; i < 64; ++i, cgBase += 0x4b8) {
        struct XAnimTree_s *tree = *(struct XAnimTree_s **)(cgBase + 0xe0db8); /* cg->bgs.pXAnimTree at 0xe0db8 */
        if (tree) {
            XAnimFreeTree(tree, 0);
            *(struct XAnimTree_s **)(cgBase + 0xe0db8) = NULL; /* cg->bgs.pXAnimTree at 0xe0db8 */
        }
    }

    cgsBase = (byte *)cgs;
    for (i = 0; i < 8; ++i, cgsBase += 0x4b8) {
        struct XAnimTree_s *tree = *(struct XAnimTree_s **)(cgsBase + 0xc6b8); /* cgs->bgs.pXAnimTree at 0xc6b8 */
        if (tree) {
            XAnimFreeTree(tree, 0);
            *(struct XAnimTree_s **)(cgsBase + 0xc6b8) = NULL; /* cgs->bgs.pXAnimTree at 0xc6b8 */
        }
    }

    if (((cgs_t *)cgs)->localServer == 0) {
        Scr_ShutdownGameStrings();
    }

    memset((void *)cg, 0, 0xf399c);
}

/* line 2022 */
void * Hunk_AllocXAnimPrecache(int size)
{
    return Hunk_AllocAlignInternal(size, 4);
}

/* line 2035 */
void * Hunk_AllocXAnimClient(int size)
{
    return Hunk_AllocInternal(size);
}

static void CG_PrintAliasSubtitle(const snd_alias_t *pAlias, int msec)
{
    int minMsec;
    int subtitleWidth;

    if (msec == 0 || pAlias == NULL || pAlias->pszSubtitle == NULL) {
        return;
    }

    if (((cgs_t *)cgs)->viewAspect > 1.3333334f) {
        subtitleWidth = cg_subtitleWidthWidescreen->current.integer;
    } else {
        subtitleWidth = cg_subtitleWidthStandard->current.integer;
    }

    minMsec = (int)(cg_subtitleMinTime->current.value * 1000.0f + 0.5f);
    if (minMsec < msec) {
        minMsec = msec;
    }

    CL_SubtitlePrint(pAlias->pszSubtitle, minMsec, subtitleWidth);
}

static int CG_PlayPickedAlias(const snd_alias_t *pAlias, int entitynum, const vec_t *origin, qboolean master)
{
    int msec;

    if (pAlias == NULL) {
        return 0;
    }

    if (master) {
        msec = SND_PlaySoundAliasAsMaster(pAlias, entitynum, origin, 0, SASYS_CGAME);
    } else {
        msec = SND_PlaySoundAlias(pAlias, entitynum, origin, 0, SASYS_CGAME);
    }

    CG_PrintAliasSubtitle(pAlias, msec);
    return msec;
}

static int CG_LocalSoundEntityNum(void)
{
    return cgArray[0].nextSnap->ps.clientNum;
}

static const vec_t *CG_LocalSoundOrigin(void)
{
    return (const vec_t *)cgArray[0].nextSnap->ps.origin;
}

/* line 1271 */
int CG_PlaySoundAliasAsMasterByName(int entitynum, const vec_t *origin, const char *aliasname)
{
    return CG_PlayPickedAlias(CL_PickSoundAlias(aliasname), entitynum, origin, 1);
}

/* line 688 */
void CG_GetDObjOrientation(int dobjHandle, orientation_t *orient)
{
    const byte *cent;

    if ((unsigned int)dobjHandle <= 0x3ff) {
        cent = (const byte *)cg_entities + dobjHandle * 548;
        orient->origin[0] = ((const centity_t *)cent)->lerpOrigin[0];
        orient->origin[1] = ((const centity_t *)cent)->lerpOrigin[1];
        orient->origin[2] = ((const centity_t *)cent)->lerpOrigin[2];
        AnglesToAxis((const vec_t *)((const centity_t *)cent)->lerpAngles, orient->axis);
        return;
    }

    if ((unsigned int)(dobjHandle - 0x400) > 0x7f) {
        return;
    }

    orient->origin[0] = cgArray[0].viewModelOrigin[0];
    orient->origin[1] = cgArray[0].viewModelOrigin[1];
    orient->origin[2] = cgArray[0].viewModelOrigin[2];
    AxisCopy(cgArray[0].viewModelAxis, orient->axis);
}

/* line 1461 */
