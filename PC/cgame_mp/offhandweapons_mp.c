/* Converted to C from ASM: offhandweapons_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/offhandweapons_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

extern const dvar_t *Dvar_RegisterFloat(const char *name, float defaultValue, float min, float max, int flags);
extern int BG_GetFirstAvailableOffhand(void *ps, int weaponType);
extern int BG_GetFirstEquippedOffhand(void *ps, int weaponType);
extern float CG_FadeHudMenu(void *hud, int val, int time);
extern void UI_DrawText(const char *text, int maxChars, void *font, float x, float y, int horzAlign, int vertAlign, float scale, const float *color, int textStyle);
extern const char *UI_SafeTranslateString(const char *str);
extern void CG_PlayEntitySoundAlias(int entNum, int soundAlias);
extern void CG_PlaySoundAlias(int entNum, float *origin, int soundAlias);
extern int CG_DObjGetWorldTagPos(void *cent, void *dobj, unsigned short tag, float *origin);
extern int CG_DObjGetViewModelTagPos(void *dobj, unsigned short tag, float *origin);
extern void BG_EvaluateTrajectory(void *trajectory, int time, float *result);
extern void *BG_GetWeaponDef(int weaponIndex);
extern int BG_GetNumWeapons(void);
extern int BG_ClipForWeapon(int weaponIndex);
extern void *Com_GetClientDObj(int clientNum, int lod);
extern void CG_MenuShowNotify(int type);
extern float UI_DrawHandlePic(float x, float y, float w, float h, int horzAlign, int vertAlign, const float *color, MaterialHandle material);
extern float floorf(float x);
extern float cosf(float x);
extern char *va(const char *fmt, ...);
extern void Com_Printf(const char *fmt, ...);

extern byte *cg_ptr;           /* imp_cg */
extern byte *cg_tags_ptr;      /* imp_scr_const */
extern byte *cg_weapons;       /* 0x0 */
extern const dvar_t *hud_fade_offhand; /* 0x0 */
extern const char str_002157b8[];
extern const char str_002b51bc[];
extern const char str_002b51d0[];

__attribute__((used, packed, aligned(4)))
UInt32 offhandStrings_storage[8] = {
    (UInt32)str_002157b8,
    (UInt32)str_002b51bc,
    (UInt32)str_002b51d0,
    0,
    0,
    0,
    0,
    0,
}; /* 0x314500 */

#define offhandStrings ((const char * const *)offhandStrings_storage)
static const dvar_t *hud_flash_time_offhand; /* hud_flash_time_offhand */
static const dvar_t *hud_flash_period_offhand; /* hud_flash_period_offhand */

void CG_OffhandRegisterDvars(void);
void CG_DrawOffHandName(rectDef_s *rect, struct Font_s *font, float scale, vec_t *color, int textStyle, int weaponType);
void CG_PrepOffHand(entityState_t *ent, int event, int eventParam);
void CG_UseOffHand(centity_t *cent, int event, int eventParam);
void CG_SetEquippedOffHand(int offHandIndex);
void CG_SwitchOffHandCmd(void);
void CG_DrawOffHandIcon(rectDef_s *rect, float scale, vec_t *color, MaterialHandle material, int weaponType);
void CG_DrawOffHandHighlight(rectDef_s *rect, float scale, vec_t *color, MaterialHandle material, int weaponType);
void CG_DrawOffHandAmmo(rectDef_s *rect, struct Font_s *font, float scale, vec_t *color, int textStyle, int weaponType);

/* line 30 */
void CG_OffhandRegisterDvars(void)
{
    hud_flash_time_offhand = Dvar_RegisterFloat("hud_flash_time_offhand", 2.0f, 0.0f, 30.0f, 0x1001);
    hud_flash_period_offhand = Dvar_RegisterFloat("hud_flash_period_offhand", 0.5f, 0.0f, 30.0f, 0x1001);
}

/* line 251 */
void CG_DrawOffHandName(rectDef_s *rect, struct Font_s *font, float scale, vec_t *color, int textStyle, int weaponType)
{
    cg_t *cg;
    const dvar_t *hud;
    float fade;
    float drawColor[4];
    const char *text;
    int weapon;
    int time;

    cg = *(cg_t **)cg_ptr;
    if (cg->predictedPlayerState.pm_type > 5)
        return;

    weapon = BG_GetFirstAvailableOffhand((void *)&cg->predictedPlayerState, weaponType);
    if (weapon == 0) {
        weapon = BG_GetFirstEquippedOffhand((void *)&cg->predictedPlayerState, weaponType);
        if (weapon == 0)
            return;
    }

    hud = hud_fade_offhand;
    if (!hud)
        return;

    time = (int)floorf(hud->current.value * 1000.0f + 0.5f);
    fade = CG_FadeHudMenu((void *)hud, cg->offhandFadeTime, time);

    if (fade == 0.0f)
        return;

    *(int *)&drawColor[0] = *(int *)&color[0];
    *(int *)&drawColor[1] = *(int *)&color[1];
    *(int *)&drawColor[2] = *(int *)&color[2];

    text = UI_SafeTranslateString(offhandStrings[weaponType]);

    UI_DrawText(text, 0x7fffffff, font,
                rect->x, rect->y,
                rect->horzAlign, rect->vertAlign,
                scale, drawColor, textStyle);
}

/* line 301 */
void CG_PrepOffHand(entityState_t *ent, int event, int eventParam)
{
    weaponInfo_s *wi;
    int soundAlias;

    wi = &((weaponInfo_s *)cg_weapons)[eventParam];
    soundAlias = (int)(intptr_t)wi->pullbackSound;

    if (soundAlias != 0) {
        CG_PlayEntitySoundAlias(ent->number, soundAlias);
    }
}

/* line 319 */
void CG_UseOffHand(centity_t *cent, int event, int eventParam)
{
    cg_t *cg;
    weaponInfo_s *wi;
    int soundAlias;
    int clientNum;
    float origin[3];
    void *dobj;

    wi = &((weaponInfo_s *)cg_weapons)[eventParam];
    soundAlias = (int)(intptr_t)wi->flashSound;

    if (soundAlias == 0)
        return;

    clientNum = cent->nextState.number;
    cg = *(cg_t **)cg_ptr;

    if (clientNum == cg->snap->ps.clientNum) {
        /* Local player - try view model tag */
        void *viewModel = wi->viewModelDObj;
        if (viewModel != NULL) {
            if (CG_DObjGetViewModelTagPos(viewModel, (*(scr_const_t **)cg_tags_ptr)->tag_flash, origin)) {
                goto play_sound;
            }
        }
    } else {
        /* Remote player - try world tag */
        dobj = Com_GetClientDObj(clientNum, cent->localClientNum);
        if (dobj != NULL) {
            if (CG_DObjGetWorldTagPos(cent, dobj, (*(scr_const_t **)cg_tags_ptr)->tag_flash, origin)) {
                goto play_sound;
            }
        }
    }

    /* Fallback: evaluate trajectory */
    BG_EvaluateTrajectory((void *)&cent->nextState.pos, cg->time, origin);

play_sound:
    CG_PlaySoundAlias(cent->nextState.number, origin, (int)(intptr_t)wi->flashSound);
}

/* line 354 */
void CG_SetEquippedOffHand(int offHandIndex)
{
    cg_t *cg = *(cg_t **)cg_ptr;
    cg->equippedOffHand = offHandIndex;
    CG_MenuShowNotify(4);
}

/* line 279 */
void CG_SwitchOffHandCmd(void)
{
    cg_t *cg;
    int currentWeapon;
    void *weapDef;
    int newWeapon;

    cg = *(cg_t **)cg_ptr;
    currentWeapon = cg->equippedOffHand;

    if (currentWeapon == 0)
        return;

    weapDef = BG_GetWeaponDef(currentWeapon);
    newWeapon = BG_GetFirstAvailableOffhand((void *)&cg->predictedPlayerState, ((WeaponDef *)weapDef)->offhandClass);

    if (newWeapon == 0)
        return;

    cg->equippedOffHand = newWeapon;
    CG_MenuShowNotify(4);
}

/* line 68 */
void CG_DrawOffHandIcon(rectDef_s *rect, float scale, vec_t *color, MaterialHandle material, int weaponType)
{
    cg_t *cg;
    const dvar_t *hud;
    float fade;
    float drawColor[4];
    int weapon;
    int time;
    MaterialHandle iconMaterial;
    void *weapDef;

    cg = *(cg_t **)cg_ptr;
    if (cg->predictedPlayerState.pm_type > 5)
        return;

    weapon = BG_GetFirstAvailableOffhand((void *)&cg->predictedPlayerState, weaponType);
    if (weapon == 0) {
        weapon = BG_GetFirstEquippedOffhand((void *)&cg->predictedPlayerState, weaponType);
        if (weapon == 0)
            return;
    }

    hud = hud_fade_offhand;
    if (!hud)
        return;

    time = (int)floorf(hud->current.value * 1000.0f + 0.5f);
    fade = CG_FadeHudMenu((void *)hud, cg->offhandFadeTime, time);

    if (fade == 0.0f)
        return;

    *(int *)&drawColor[0] = *(int *)&color[0];
    *(int *)&drawColor[1] = *(int *)&color[1];
    *(int *)&drawColor[2] = *(int *)&color[2];

    /* Check if equipped offhand matches this weapon type */
    if (cg->equippedOffHand != 0) {
        weapDef = BG_GetWeaponDef(cg->equippedOffHand);
        if (((WeaponDef *)weapDef)->offhandClass == weaponType) {
            weapon = cg->equippedOffHand;
            if (weapon == 0)
                goto find_weapon;
            goto draw_icon;
        }
    }

find_weapon:
    cg = *(cg_t **)cg_ptr;
    weapon = BG_GetFirstAvailableOffhand((void *)&cg->predictedPlayerState, weaponType);
    if (weapon == 0) {
        weapon = BG_GetFirstEquippedOffhand((void *)&cg->predictedPlayerState, weaponType);
        if (weapon == 0)
            return;
    }

draw_icon:
    iconMaterial = ((weaponInfo_s *)cg_weapons)[weapon].hHudIcon;

    UI_DrawHandlePic(rect->x, rect->y, rect->w,
                     rect->h, rect->horzAlign, rect->vertAlign,
                     drawColor, iconMaterial);
}

/* line 173 */
void CG_DrawOffHandHighlight(rectDef_s *rect, float scale, vec_t *color, MaterialHandle material, int weaponType)
{
    cg_t *cg;
    const dvar_t *hud;
    float fade;
    float flashColor[4];
    int weapon;
    int time;
    void *weapDef;
    int weapCount;
    int ammoCount;
    int i;
    int clip;
    float timeSinceF;
    float flashTime;
    float angle;
    float pulse;

    cg = *(cg_t **)cg_ptr;
    if (cg->predictedPlayerState.pm_type > 5)
        return;

    weapon = BG_GetFirstAvailableOffhand((void *)&cg->predictedPlayerState, weaponType);
    if (weapon == 0) {
        weapon = BG_GetFirstEquippedOffhand((void *)&cg->predictedPlayerState, weaponType);
        if (weapon == 0)
            return;
    }

    if (cg->equippedOffHand == 0)
        return;

    hud = hud_fade_offhand;
    if (!hud)
        return;

    time = (int)floorf(hud->current.value * 1000.0f + 0.5f);
    fade = CG_FadeHudMenu((void *)hud, cg->offhandFadeTime, time);

    if (fade == 0.0f)
        return;

    weapDef = BG_GetWeaponDef(cg->equippedOffHand);
    if (((WeaponDef *)weapDef)->offhandClass != weaponType)
        return;

    /* Count total ammo for this weapon type */
    weapCount = BG_GetNumWeapons();
    ammoCount = 0;
    for (i = 1; i <= weapCount; i++) {
        if (!((cg->predictedPlayerState.weapons[i >> 5] >> (i & 0x1f)) & 1))
            continue;
        weapDef = BG_GetWeaponDef(i);
        if (((WeaponDef *)weapDef)->offhandClass != weaponType)
            continue;
        clip = BG_ClipForWeapon(i);
        ammoCount += cg->predictedPlayerState.ammoclip[clip];
    }

    /* Set flash color */
    if (ammoCount == 0) {
        flashColor[0] = 0.89f;
        flashColor[1] = 0.18f;
        flashColor[2] = 0.01f;
    } else {
        *(int *)&flashColor[0] = *(int *)&color[0];
        *(int *)&flashColor[1] = *(int *)&color[1];
        *(int *)&flashColor[2] = *(int *)&color[2];
    }

    flashColor[3] = fade;

    /* Check flash animation */
    cg = *(cg_t **)cg_ptr;
    timeSinceF = (float)(cg->time - cg->offhandFlashTime) / 1000.0f;
    flashTime = *(float *)((byte *)hud_flash_time_offhand + 8);

    if (flashTime > timeSinceF) {
        angle = timeSinceF * 6.2831855f / *(float *)((byte *)hud_flash_period_offhand + 8);
        pulse = cosf(angle) * 0.5f + 0.5f;
        flashColor[3] = pulse * fade;
    }

    UI_DrawHandlePic(rect->x, rect->y, rect->w,
                     rect->h, rect->horzAlign, rect->vertAlign,
                     flashColor, material);
}

/* line 215 */
void CG_DrawOffHandAmmo(rectDef_s *rect, struct Font_s *font, float scale, vec_t *color, int textStyle, int weaponType)
{
    cg_t *cg;
    const dvar_t *hud;
    float fade;
    float drawColor[4];
    int weapon;
    int time;
    int weapCount;
    int ammoCount;
    int i;
    int clip;
    char *text;
    void *weapDef;

    cg = *(cg_t **)cg_ptr;
    if (cg->predictedPlayerState.pm_type > 5)
        return;

    weapon = BG_GetFirstAvailableOffhand((void *)&cg->predictedPlayerState, weaponType);
    if (weapon == 0) {
        weapon = BG_GetFirstEquippedOffhand((void *)&cg->predictedPlayerState, weaponType);
        if (weapon == 0)
            return;
    }

    hud = hud_fade_offhand;
    if (!hud)
        return;

    time = (int)floorf(hud->current.value * 1000.0f + 0.5f);
    fade = CG_FadeHudMenu((void *)hud, cg->offhandFadeTime, time);

    if (fade == 0.0f)
        return;

    /* Count total ammo for this weapon type */
    weapCount = BG_GetNumWeapons();
    ammoCount = 0;
    for (i = 1; i <= weapCount; i++) {
        if (!((cg->predictedPlayerState.weapons[i >> 5] >> (i & 0x1f)) & 1))
            continue;
        weapDef = BG_GetWeaponDef(i);
        if (((WeaponDef *)weapDef)->offhandClass != weaponType)
            continue;
        clip = BG_ClipForWeapon(i);
        ammoCount += cg->predictedPlayerState.ammoclip[clip];
    }

    text = va("%i", ammoCount);

    if (ammoCount == 0) {
        drawColor[0] = 0.89f;
        drawColor[1] = 0.18f;
        drawColor[2] = 0.01f;
    } else {
        *(int *)&drawColor[0] = *(int *)&color[0];
        *(int *)&drawColor[1] = *(int *)&color[1];
        *(int *)&drawColor[2] = *(int *)&color[2];
    }

    UI_DrawText(text, 0x7fffffff, font,
                rect->x, rect->y,
                rect->horzAlign, rect->vertAlign,
                scale, drawColor, textStyle);
}
