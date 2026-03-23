/* ASM dump from: cg_newDraw_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_newDraw_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/memfile.h"
 *   #include "PC/universal/com_vector.h"
 */

extern const dvar_t *hud_fade_ammodisplay; /* 0x0 */
extern const dvar_t *hud_fade_healthbar; /* 0x0 */
extern const dvar_t *hud_fade_compass; /* 0x0 */
extern const dvar_t *hud_fade_stance; /* 0x0 */
extern const dvar_t *hud_fade_offhand; /* 0x0 */
extern const dvar_t *hud_health_startpulse_injured; /* 0x0 */
extern const dvar_t *hud_health_startpulse_critical; /* 0x0 */
extern const dvar_t *hud_health_pulserate_injured; /* 0x0 */
extern const dvar_t *hud_health_pulserate_critical; /* 0x0 */
extern const dvar_t *hud_deathQuoteFadeTime; /* 0x0 */
static vec4_t color; /* color */
static char szErrorString[1024]; /* szErrorString */
static const float pulseMags[4]; /* pulseMags */
static vec4_t color_00302d80; /* color */
static vec4_t color_00302d80; /* color */
static const dvar_t *hud_fadeout_speed; /* hud_fadeout_speed */
static const dvar_t *hud_enable; /* hud_enable */
static const dvar_t *hud_healthOverlay_regenPauseTime; /* hud_healthOverlay_regenPauseTime */
static const dvar_t *hud_healthOverlay_pulseStart; /* hud_healthOverlay_pulseStart */
static const dvar_t *hud_healthOverlay_phaseOne_pulseDuration; /* hud_healthOverlay_phaseOne_pulseDuration */
static const dvar_t *hud_healthOverlay_phaseTwo_toAlphaMultiplier; /* hud_healthOverlay_phaseTwo_toAlphaMultiplier */
static const dvar_t *hud_healthOverlay_phaseTwo_pulseDuration; /* hud_healthOverlay_phaseTwo_pulseDuration */
static const dvar_t *hud_healthOverlay_phaseThree_toAlphaMultiplier; /* hud_healthOverlay_phaseThree_toAlphaMultiplier */
static const dvar_t *hud_healthOverlay_phaseThree_pulseDuration; /* hud_healthOverlay_phaseThree_pulseDuration */
static const dvar_t *hud_healthOverlay_phaseEnd_toAlpha; /* hud_healthOverlay_phaseEnd_toAlpha */
static const dvar_t *hud_healthOverlay_phaseEnd_pulseDuration; /* hud_healthOverlay_phaseEnd_pulseDuration */

typedef void (*MemoryFileArchiveProc)(MemoryFile *memFile, int size, void *data);

extern const char *va(const char *fmt, ...);
extern int CL_GetKeyCatchers(void);
extern Bool CL_GetDisplayHUDWithKeycatchUI(void);
extern const char *CL_GetConfigString(int index);
extern void CL_DrawStretchPic(float x, float y, float w, float h, int horzAlign, int vertAlign, float s1, float t1, float s2, float t2, const vec_t *color, MaterialHandle material);
extern const dvar_t *Dvar_RegisterBool_mac(const char *name, int value, int flags);
extern const dvar_t *Dvar_RegisterFloat(const char *name, float value, float min, float max, int flags);
extern const dvar_t *Dvar_RegisterInt(const char *name, int value, int min, int max, int flags);
extern void Controls_GetConfig(void);
extern int BG_GetNumWeapons(void);
extern int GetKeyBindingLocalizedString(const char *command, char *keys);
extern int BG_GetViewmodelWeaponIndex(void *ps);
extern void *BG_GetWeaponDef(int weapIndex);
extern int BG_AmmoForWeapon(int weapon);
extern int BG_GetTotalAmmoReserve(const playerState_t *ps, int weaponIndex);
extern int BG_GetAmmoTypeMax(int iAmmoIndex);
extern qboolean BG_WeaponIsClipOnly(int weapon);
extern int BG_ClipForWeapon(int weapon);
extern int BG_GetAmmoClipSize(int iClipIndex);
extern Bool BG_DoesWeaponNeedSlot(int weapIndex);
extern int BG_GetEmptySlotForWeapon(const playerState_t *pPS, int iWeaponIndex);
extern float sinf(float x);
extern const char *SEH_LocalizeTextMessage(const char *msg, const char *context, int errType);
extern const char *UI_ReplaceConversionString(const char *sourceString, const char *replaceString);
extern const char *UI_SafeTranslateString(const char *ref);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern int Com_sprintf(char *dest, int size, const char *fmt, ...);
extern int UI_TextWidth(const char *text, int maxChars, FontHandle font, float fontScale);
extern int UI_TextHeight(FontHandle font, float fontScale);
extern void UI_DrawText(const char *text, int maxChars, FontHandle font, float x, float y, int horzAlign, int vertAlign, float scale, const vec_t *color, int style);
extern float UI_DrawHandlePic(float x, float y, float w, float h, int horzAlign, int vertAlign, const vec_t *color, MaterialHandle material);
extern const char *SEH_StringEd_GetString(const char *pszReference);
extern void Com_Error(errorParm_t code, const char *fmt, ...);
extern void Com_Printf(const char *fmt, ...);
extern void I_strncat(char *dest, int maxlen, const char *src);
extern qboolean CG_ScoreboardDisplayed(void);
extern float CG_ScrollScoreboardUp(void);
extern float CG_ScrollScoreboardDown(void);
extern float *CG_FadeColor(int startMsec, int totalMsec, int fadeMsec);

void CG_AntiBurnInHUD_RegisterDvars(void);
Bool CG_AreHudMenusHidden(void);
float CG_CalcPlayerHealth(void);
void CG_ResetLowHealthOverlay(void);
qboolean CG_ServerMaterialName(int index, char *materialName, int maxLen);
void CG_ApplySplitScreenCompassScale(float *x, float *y, float *w, float *h);
static const char * CG_GetUseString(void);
static void CG_DrawCursorhint(const rectDef_t *rect, struct Font_s *font, float fontscale, int textStyle);
static void CG_DrawMantleHint(const rectDef_t *rect, struct Font_s *font, float fontscale, int textStyle);
const char * CG_GetTranslatedLocationString(int iLocation);
static void __attribute_regparm__(3) CG_DrawScore(int team, const rectDef_t *rect, struct Font_s *font, float scale, vec_t *color, MaterialHandle material, int textStyle);
const char * CG_GetKillerText(void);
const char * CG_GameTypeString(void);
int CG_KeyInterceptEvent(int key, qboolean down);
static void CG_PulseLowHealthOverlay(float healthRatio);
void CG_ArchiveState(MemoryFile *memFile);
static void CG_DrawHoldBreathHint(const rectDef_t *rect, struct Font_s *font, float fontscale, int textStyle);
float CG_FadeHudMenu(const dvar_t *fadeDvar, int displayStartTime, int duration);
Bool CG_CheckPlayerForLowAmmo(void);
Bool CG_CheckPlayerForLowClip(void);
void CG_DrawPlayerCompassBack(const rectDef_t *rect, MaterialHandle material, vec_t *color);
static void CG_DrawPlayerStance(const rectDef_t *rect, vec_t *color, struct Font_s *font, float scale, int textStyle);
static void CG_DrawPlayerAmmoValue(const rectDef_t *rect, struct Font_s *font, float scale, vec_t *color, MaterialHandle material, int textStyle, int type);
void CG_OwnerDraw(float x, float y, float w, float h, int horzAlign, int vertAlign, float text_x, float text_y, int ownerDraw, int ownerDrawFlags, int align, float special, struct Font_s *font, float scale, vec_t *color, MaterialHandle material, int textStyle);

/* line 59 */
void CG_AntiBurnInHUD_RegisterDvars(void)
{
    hud_fadeout_speed = Dvar_RegisterFloat("hud_fadeout_speed", 0.1f, 0.0f, 1.0f, 0x1001);
    hud_enable = Dvar_RegisterBool_mac("hud_enable", 1, 0x1001);

    hud_fade_ammodisplay = Dvar_RegisterFloat("hud_fade_ammodisplay", 0.0f, 0.0f, 30.0f, 0x1001);
    hud_fade_healthbar = Dvar_RegisterFloat("hud_fade_healthbar", 2.0f, 0.0f, 30.0f, 0x1001);
    hud_fade_compass = Dvar_RegisterFloat("hud_fade_compass", 0.0f, 0.0f, 30.0f, 0x1001);
    hud_fade_stance = Dvar_RegisterFloat("hud_fade_stance", 1.7f, 0.0f, 30.0f, 0x1001);
    hud_fade_offhand = Dvar_RegisterFloat("hud_fade_offhand", 0.0f, 0.0f, 30.0f, 0x1001);

    hud_health_startpulse_injured = Dvar_RegisterFloat("hud_health_startpulse_injured", 1.0f, 0.0f, 1.1f, 0x1001);
    hud_health_startpulse_critical = Dvar_RegisterFloat("hud_health_startpulse_critical", 0.33f, 0.0f, 1.1f, 0x1001);
    hud_health_pulserate_injured = Dvar_RegisterFloat("hud_health_pulserate_injured", 1.0f, 0.1f, 3.0f, 0x1001);
    hud_health_pulserate_critical = Dvar_RegisterFloat("hud_health_pulserate_critical", 0.5f, 0.1f, 3.0f, 0x1001);

    hud_deathQuoteFadeTime = Dvar_RegisterInt("hud_deathQuoteFadeTime", 1000, 0, 100000, 0x1001);

    hud_healthOverlay_regenPauseTime = Dvar_RegisterInt("hud_healthOverlay_regenPauseTime", 5000, 0, 10000, 0x1080);
    hud_healthOverlay_pulseStart = Dvar_RegisterFloat("hud_healthOverlay_pulseStart", 0.35f, 0.0f, 1.0f, 0x1080);
    hud_healthOverlay_phaseOne_pulseDuration = Dvar_RegisterInt("hud_healthOverlay_phaseOne_pulseDuration", 150, 0, 1000, 0x1080);
    hud_healthOverlay_phaseTwo_toAlphaMultiplier = Dvar_RegisterFloat("hud_healthOverlay_phaseTwo_toAlphaMultiplier", 0.7f, 0.0f, 1.0f, 0x1080);
    hud_healthOverlay_phaseTwo_pulseDuration = Dvar_RegisterInt("hud_healthOverlay_phaseTwo_pulseDuration", 320, 0, 1000, 0x1080);
    hud_healthOverlay_phaseThree_toAlphaMultiplier = Dvar_RegisterFloat("hud_healthOverlay_phaseThree_toAlphaMultiplier", 0.6f, 0.0f, 1.0f, 0x1080);
    hud_healthOverlay_phaseThree_pulseDuration = Dvar_RegisterInt("hud_healthOverlay_phaseThree_pulseDuration", 400, 0, 1000, 0x1080);
    hud_healthOverlay_phaseEnd_toAlpha = Dvar_RegisterFloat("hud_healthOverlay_phaseEnd_toAlpha", 0.0f, 0.0f, 1.0f, 0x1080);
    hud_healthOverlay_phaseEnd_pulseDuration = Dvar_RegisterInt("hud_healthOverlay_phaseEnd_pulseDuration", 700, 0, 1000, 0x1080);
}

/* line 99 */
Bool CG_AreHudMenusHidden(void)
{
    if ((CL_GetKeyCatchers() & 8) && !CL_GetDisplayHUDWithKeycatchUI()) {
        return 1;
    }

    return ((cg_t *)*(cg_t **)imp_cg)->drawHud == 0;
}

/* line 741 */
float CG_CalcPlayerHealth(void)
{
    playerState_t *ps;
    float healthRatio;

    ps = &((cg_t *)*(cg_t **)imp_cg)->nextSnap->ps;
    if (ps->stats[0] == 0 || ps->stats[2] == 0 || ps->pm_type == 6) {
        return 0.0f;
    }

    healthRatio = (float)ps->stats[0] / (float)ps->stats[2];
    if (healthRatio < 0.0f) {
        return 0.0f;
    }
    if (healthRatio > 1.0f) {
        return 1.0f;
    }
    return healthRatio;
}

/* line 1002 */
void CG_ResetLowHealthOverlay(void)
{
    byte *cg = (byte *)*(int *)imp_cg;
    ((cg_t *)cg)->healthOverlayHurt = 0;
    ((cg_t *)cg)->healthOverlayToAlpha = *(float *)((byte *)hud_healthOverlay_phaseEnd_toAlpha + 8);
    ((cg_t *)cg)->healthOverlayPulseDuration = 0;
    ((cg_t *)cg)->healthOverlayPulsePhase = 0;
    ((cg_t *)cg)->healthOverlayPulseIndex = 0;
    ((cg_t *)cg)->healthOverlayOldHealth = 1.0f;
}

/* line 1036 */
qboolean CG_ServerMaterialName(int index, char *materialName, int maxLen)
{
    const char *configString;

    if ((unsigned int)(index - 1) > 0x7e) {
        return 0;
    }

    configString = CL_GetConfigString(index + 0x61e);
    if (configString[0] == '\0') {
        return 0;
    }
    if ((int)strlen(configString) >= maxLen) {
        return 0;
    }

    strcpy(materialName, configString);
    return 1;
}

/* line 1079 */
void CG_ApplySplitScreenCompassScale(float *x, float *y, float *w, float *h)
{
    /* Split-screen compass scaling is unused on PC. */
}

/* line 1373 */
const char * CG_GetUseString(void)
{
    byte *cg;
    const char *hintString;
    char binding[0x100];

    cg = (byte *)*(void **)imp_cg;
    hintString = CL_GetConfigString(((cg_t *)cg)->cursorHintString + 0x4fe);
    if (!hintString || !*hintString)
    {
        return 0;
    }

    if (!GetKeyBindingLocalizedString(str_002ac020, binding))
    {
        I_strncpyz(binding, UI_SafeTranslateString(str_002afa64), sizeof(binding));
    }

    return UI_ReplaceConversionString(SEH_LocalizeTextMessage(hintString, str_002afa6c, 0), binding);
}

/* line 1408 */
static void CG_DrawCursorhint(const rectDef_t *rect, struct Font_s *font, float fontscale, int textStyle)
{
    byte *cg;
    byte *cgs;
    byte *snap;
    int cursorHintValue;
    int cursorHintString;
    MaterialHandle hintIcon;
    float *fadeColor;
    float scale;
    float halfscale;
    float widthScale;
    float widthOfs;
    const char *text;
    float length;
    int cursorHintsDvarVal;
    char binding[0x100];

    /* line 1426: check if cursor hints are enabled */
    if (!*(int *)((byte *)*(void **)imp_cg_cursorHints + 8))
        return;

    /* line 1308: check for cursor hint in cg struct */
    cg = (byte *)*(void **)imp_cg;
    if (!((cg_t *)cg)->renderingThirdPerson) {
        /* line 1311: check snapshot for new hint data */
        snap = (byte *)((cg_t *)cg)->nextSnap;
        if (((snapshot_t *)snap)->ps.cursorHint) {
            /* line 1313-1316: copy hint data from snapshot */
            ((cg_t *)cg)->cursorHintTime = ((cg_t *)cg)->time; /* hintStartTime = time */
            ((cg_t *)cg)->cursorHintFade = *(int *)((byte *)*(void **)imp_cg_hintFadeTime + 8); /* hintFadeTime = dvar */
            ((cg_t *)cg)->cursorHintIcon = ((snapshot_t *)snap)->ps.cursorHint; /* cursorHintValue */
            ((cg_t *)cg)->cursorHintString = ((snapshot_t *)snap)->ps.cursorHintString; /* cursorHintString */
        }
        cg = (byte *)*(void **)imp_cg;
    }

    /* line 1431: get hint icon material */
    cgs = (byte *)*(void **)imp_cgs;
    cursorHintValue = ((cg_t *)cg)->cursorHintIcon;
    hintIcon = ((MaterialHandle *)(cgs + 0xba44))[cursorHintValue]; /* cgs->media.hintIcons[cursorHintValue] at 0xba44 */
    if (!hintIcon)
        return;

    /* line 1436: get fade color */
    fadeColor = CG_FadeColor(((cg_t *)cg)->cursorHintTime, ((cg_t *)cg)->cursorHintFade, 100);
    if (!fadeColor) {
        /* line 1439: clear cursor hint on fade out */
        ((cg_t *)cg)->cursorHintIcon = 0;
        return;
    }

    /* line 1443 */
    Controls_GetConfig();

    /* line 1450: check cursorHints dvar for display mode */
    cursorHintsDvarVal = *(int *)((byte *)*(void **)imp_cg_cursorHints + 8);

    if (cursorHintsDvarVal == 3) {
        /* line 1451: pulsing alpha mode */
        float sinVal = sinf((float)((cg_t *)cg)->time / 150.0f);
        fadeColor[3] *= sinVal * 0.5f + 0.5f;
        /* reload dvar since cg_cursorHints was read again in ASM */
        cursorHintsDvarVal = *(int *)((byte *)*(void **)imp_cg_cursorHints + 8);
    }

    /* line 1454-1465: compute scale and halfscale based on display mode */
    if (cursorHintsDvarVal <= 2) {
        if (cursorHintsDvarVal == 2) {
            /* line 1461: scale from hintStartTime percentage */
            int startTime = ((cg_t *)cg)->cursorHintTime;
            scale = (float)(startTime % 1000) / 100.0f;
        } else {
            /* line 1463: pulsing scale mode (0 or 1) */
            float sinVal = sinf((float)((cg_t *)cg)->time / 150.0f);
            scale = (sinVal * 0.5f + 0.5f) * 10.0f;
        }
        halfscale = 0.5f * scale;
    } else {
        /* line 1456: no scaling (value > 3, or value == 3 after alpha adjustment) */
        scale = 0.0f;
        halfscale = 0.0f;
    }

    /* line 1468: check if this is a weapon hint (cursorHintValue 5-132) */
    cg = (byte *)*(void **)imp_cg;
    cursorHintValue = ((cg_t *)cg)->cursorHintIcon;
    text = NULL;
    widthScale = 1.0f;
    widthOfs = 0.0f;

    if ((unsigned)(cursorHintValue - 5) <= 0x7f) {
        /* weapon hint */
        byte *weapDef;
        int weapIdx = cursorHintValue - 4;

        weapDef = (byte *)BG_GetWeaponDef(weapIdx);

        /* line 1474: check dual wield flag */
        if (((WeaponDef *)weapDef)->bWideListIcon) {
            /* line 1477: dual wield - double width, offset */
            widthOfs = rect->w * -0.5f;
            widthScale = 2.0f;
        }

        /* line 1480: check if weapon type is melee (type == 7) */
        if (((WeaponDef *)weapDef)->weapClass == 7) {
            /* line 1482: melee weapon - use cursorHintString */
            cg = (byte *)*(void **)imp_cg;
            cursorHintString = ((cg_t *)cg)->cursorHintString;
            if (cursorHintString >= 0) {
                text = CG_GetUseString();
            }
            /* else no text */
        } else {
            /* line 1336: weapon pickup logic */
            byte *pickupWeapDef;
            byte *cgPtr;

            cgPtr = (byte *)*(void **)imp_cg;
            weapIdx = ((cg_t *)cgPtr)->cursorHintIcon - 4;
            pickupWeapDef = (byte *)BG_GetWeaponDef(weapIdx);

            /* line 1340: get key binding */
            GetKeyBindingLocalizedString(str_002ac020, binding); /* "+activate" */

            /* line 1344: check if weapon needs a slot */
            if (BG_DoesWeaponNeedSlot(weapIdx)) {
                int emptySlot = BG_GetEmptySlotForWeapon((const playerState_t *)&((cg_t *)cgPtr)->predictedPlayerState, weapIdx);
                if (emptySlot == 0) {
                    /* no empty slot - check if same weapon type for swap */
                    byte *currentWeapDef;
                    int currentWeap = ((cg_t *)cgPtr)->predictedPlayerState.weapon;
                    currentWeapDef = (byte *)BG_GetWeaponDef(currentWeap);

                    /* line 1346: compare weapon type */
                    if (((WeaponDef *)currentWeapDef)->weapSlot == ((WeaponDef *)pickupWeapDef)->weapSlot) {
                        /* line 1348: same type - check if same weapon */
                        if (((cg_t *)cgPtr)->predictedPlayerState.weapon == weapIdx) {
                            text = NULL; /* same weapon, no text */
                            goto draw_icon;
                        }
                        /* line 1357: different weapon, same type - swap */
                        text = UI_ReplaceConversionString(UI_SafeTranslateString(str_002afa94), binding);
                        goto check_text;
                    }

                    /* line 1353: different weapon type - check if it's the same slot */
                    if ((signed char)((cg_t *)cgPtr)->predictedPlayerState.weaponslots[((WeaponDef *)pickupWeapDef)->weapSlot] == weapIdx) {
                        text = NULL; /* same weapon in slot */
                        goto draw_icon;
                    }

                    /* line 1357: swap weapons */
                    text = UI_ReplaceConversionString(UI_SafeTranslateString(str_002afa94), binding);
                    goto check_text;
                }
            }

            /* line 1361: pick up new weapon (empty slot available or doesn't need slot) */
            text = UI_ReplaceConversionString(UI_SafeTranslateString(str_002afa78), binding);
            goto check_text;
        }
    } else {
        /* non-weapon hint */
        cursorHintString = ((cg_t *)cg)->cursorHintString;

        if (cursorHintString < 0) {
            /* line 1494: check if hint is health pickup (cursorHintValue == 3) */
            if (cursorHintValue == 3) {
                /* line 1496: health pickup hint */
                GetKeyBindingLocalizedString(str_002ac020, binding); /* "+activate" */
                text = UI_ReplaceConversionString(UI_SafeTranslateString(str_002afaac), binding);
                widthScale = 1.0f;
                widthOfs = 0.0f;
            } else {
                /* line 1502: no text, just icon */
                widthScale = 1.0f;
                widthOfs = 0.0f;
                text = NULL;
                goto draw_icon;
            }
        } else {
            /* line 1492: get use string from config */
            text = CG_GetUseString();
        }
    }

check_text:
    /* line 1502: check if we have text to draw */
    if (text && *text) {
        /* line 1504-1510: draw text alongside icon */
        float textWidth;
        int textHeight;
        float textX, textY;
        float iconW;

        textWidth = (float)UI_TextWidth(text, 0, font, fontscale);
        textHeight = UI_TextHeight(font, fontscale);

        /* line 1507: compute text position */
        textX = (widthScale * rect->w + scale + textWidth) * -0.5f;
        textY = -0.5f * rect->h + rect->y;

        /* line 1510: draw the text */
        UI_DrawText(
            text,
            0x7fffffff,
            font,
            textX,
            rect->y + (float)textHeight * 0.5f,
            rect->horzAlign,
            rect->vertAlign,
            fontscale,
            fadeColor,
            textStyle);

        /* line 1511: draw the icon after text */
        iconW = widthScale * rect->w;
        UI_DrawHandlePic(
            textX + textWidth,
            textY,
            iconW + scale,
            scale + rect->h,
            rect->horzAlign,
            rect->vertAlign,
            fadeColor,
            hintIcon);
        return;
    }

draw_icon:
    /* line 1515-1517: draw icon only (no text) */
    {
        float iconW = widthScale * rect->w;
        float iconX = (rect->w + halfscale + widthOfs) * -0.5f + rect->x;
        UI_DrawHandlePic(
            iconX,
            rect->y - halfscale,
            iconW + scale,
            scale + rect->h,
            rect->horzAlign,
            rect->vertAlign,
            fadeColor,
            hintIcon);
    }
}
