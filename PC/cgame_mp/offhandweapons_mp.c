/* Converted to C from ASM: offhandweapons_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/offhandweapons_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

extern const dvar_t *Dvar_RegisterFloat(const char *name, float defaultValue, float min, float max, int flags);
extern int BG_GetFirstAvailableOffhand(void *ps, int weaponType);
extern int BG_GetFirstEquippedOffhand(void *ps, int weaponType);
extern float CG_FadeHudMenu(void *hud, int val, int time);
extern void UI_DrawText(const char *text, int maxChars, void *font, float x, float y, float horzAlign, float vertAlign, float scale, float *color, int textStyle);
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
extern void UI_DrawHandlePic(float x, float y, float w, float h, float horzAlign, float vertAlign, float *color, MaterialHandle material);
extern float floorf(float x);
extern float cosf(float x);
extern char *va(const char *fmt, ...);
extern void Com_Printf(const char *fmt, ...);

extern byte *cg_ptr;           /* imp_cg */
extern byte *cg_weapinfo_ptr;  /* imp_cg_weapons */
extern byte *cg_hud_ptr;       /* imp_hud_fade_offhand */
extern byte *cg_tags_ptr;      /* imp_scr_const */

extern const char * offhandStrings[3]; /* offhandStrings */
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
    byte *cg;
    byte *hud;
    float fade;
    float drawColor[4];
    const char *text;
    int weapon;
    int time;
    byte *r;

    cg = *(byte **)cg_ptr;
    if (*(int *)(cg + 0x25bc8) > 5)
        return;

    weapon = BG_GetFirstAvailableOffhand(cg + 0x25bc4, weaponType);
    if (weapon == 0) {
        weapon = BG_GetFirstEquippedOffhand(cg + 0x25bc4, weaponType);
        if (weapon == 0)
            return;
    }

    hud = *(byte **)cg_hud_ptr;
    time = (int)floorf(*(float *)(hud + 8) * 1000.0f + 0.5f);
    fade = CG_FadeHudMenu(hud, *(int *)(cg + 0x2c5d0), time);

    if (fade == 0.0f)
        return;

    *(int *)&drawColor[0] = *(int *)&color[0];
    *(int *)&drawColor[1] = *(int *)&color[1];
    *(int *)&drawColor[2] = *(int *)&color[2];

    text = UI_SafeTranslateString(offhandStrings[weaponType]);

    r = (byte *)rect;
    UI_DrawText(text, 0x7fffffff, font,
                *(float *)r, *(float *)(r + 4),
                *(float *)(r + 0x10), *(float *)(r + 0x14),
                scale, drawColor, textStyle);
}

/* line 301 */
void CG_PrepOffHand(entityState_t *ent, int event, int eventParam)
{
    byte *weapInfo;
    int soundAlias;

    weapInfo = *(byte **)cg_weapinfo_ptr;
    soundAlias = *(int *)(weapInfo + eventParam * 436 + 0xd8);

    if (soundAlias != 0) {
        CG_PlayEntitySoundAlias(*(int *)ent, soundAlias);
    }
}

/* line 319 */
void CG_UseOffHand(centity_t *cent, int event, int eventParam)
{
    byte *c = (byte *)cent;
    byte *cg;
    byte *weapInfo;
    int soundAlias;
    int clientNum;
    float origin[3];
    void *dobj;

    weapInfo = *(byte **)cg_weapinfo_ptr + eventParam * 436;
    soundAlias = *(int *)(weapInfo + 0xdc);

    if (soundAlias == 0)
        return;

    clientNum = *(int *)(c + 0xf0);
    cg = *(byte **)cg_ptr;

    if (clientNum == *(int *)(*(byte **)(cg + 0x24) + 0xd8)) {
        /* Local player - try view model tag */
        void *viewModel = *(void **)weapInfo;
        if (viewModel != NULL) {
            if (CG_DObjGetViewModelTagPos(viewModel, *(unsigned short *)(*(byte **)cg_tags_ptr + 0x8c), origin)) {
                goto play_sound;
            }
        }
    } else {
        /* Remote player - try world tag */
        dobj = Com_GetClientDObj(clientNum, *(int *)(c + 0x220));
        if (dobj != NULL) {
            if (CG_DObjGetWorldTagPos(cent, dobj, *(unsigned short *)(*(byte **)cg_tags_ptr + 0x8c), origin)) {
                goto play_sound;
            }
        }
    }

    /* Fallback: evaluate trajectory */
    BG_EvaluateTrajectory(c + 0xfc, *(int *)(cg + 0x25bb0), origin);

play_sound:
    CG_PlaySoundAlias(*(int *)(c + 0xf0), origin, *(int *)(weapInfo + 0xdc));
}

/* line 354 */
void CG_SetEquippedOffHand(int offHandIndex)
{
    byte *cg = *(byte **)cg_ptr;
    *(int *)(cg + 0x2be70) = offHandIndex;
    CG_MenuShowNotify(4);
}

/* line 279 */
void CG_SwitchOffHandCmd(void)
{
    byte *cg;
    int currentWeapon;
    void *weapDef;
    int newWeapon;

    cg = *(byte **)cg_ptr;
    currentWeapon = *(int *)(cg + 0x2be70);

    if (currentWeapon == 0)
        return;

    weapDef = BG_GetWeaponDef(currentWeapon);
    newWeapon = BG_GetFirstAvailableOffhand(cg + 0x25bc4, *(int *)((byte *)weapDef + 0x84));

    if (newWeapon == 0)
        return;

    *(int *)(cg + 0x2be70) = newWeapon;
    CG_MenuShowNotify(4);
}

/* line 68 */
void CG_DrawOffHandIcon(rectDef_s *rect, float scale, vec_t *color, MaterialHandle material, int weaponType)
{
    byte *cg;
    byte *hud;
    float fade;
    float drawColor[4];
    int weapon;
    int time;
    byte *weapInfo;
    MaterialHandle iconMaterial;
    byte *r;
    void *weapDef;

    cg = *(byte **)cg_ptr;
    if (*(int *)(cg + 0x25bc8) > 5)
        return;

    weapon = BG_GetFirstAvailableOffhand(cg + 0x25bc4, weaponType);
    if (weapon == 0) {
        weapon = BG_GetFirstEquippedOffhand(cg + 0x25bc4, weaponType);
        if (weapon == 0)
            return;
    }

    hud = *(byte **)cg_hud_ptr;
    time = (int)floorf(*(float *)(hud + 8) * 1000.0f + 0.5f);
    fade = CG_FadeHudMenu(hud, *(int *)(cg + 0x2c5d0), time);

    if (fade == 0.0f)
        return;

    *(int *)&drawColor[0] = *(int *)&color[0];
    *(int *)&drawColor[1] = *(int *)&color[1];
    *(int *)&drawColor[2] = *(int *)&color[2];

    /* Check if equipped offhand matches this weapon type */
    if (*(int *)(cg + 0x2be70) != 0) {
        weapDef = BG_GetWeaponDef(*(int *)(cg + 0x2be70));
        if (*(int *)((byte *)weapDef + 0x84) == weaponType) {
            weapon = *(int *)(cg + 0x2be70);
            if (weapon == 0)
                goto find_weapon;
            goto draw_icon;
        }
    }

find_weapon:
    cg = *(byte **)cg_ptr;
    weapon = BG_GetFirstAvailableOffhand(cg + 0x25bc4, weaponType);
    if (weapon == 0) {
        weapon = BG_GetFirstEquippedOffhand(cg + 0x25bc4, weaponType);
        if (weapon == 0)
            return;
    }

draw_icon:
    weapInfo = *(byte **)cg_weapinfo_ptr;
    iconMaterial = *(MaterialHandle *)(weapInfo + weapon * 436 + 0x138);

    r = (byte *)rect;
    UI_DrawHandlePic(*(float *)r, *(float *)(r + 4), *(float *)(r + 8),
                     *(float *)(r + 0xc), *(float *)(r + 0x10), *(float *)(r + 0x14),
                     drawColor, iconMaterial);
}

/* line 173 */
void CG_DrawOffHandHighlight(rectDef_s *rect, float scale, vec_t *color, MaterialHandle material, int weaponType)
{
    byte *cg;
    byte *hud;
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
    byte *r;

    cg = *(byte **)cg_ptr;
    if (*(int *)(cg + 0x25bc8) > 5)
        return;

    weapon = BG_GetFirstAvailableOffhand(cg + 0x25bc4, weaponType);
    if (weapon == 0) {
        weapon = BG_GetFirstEquippedOffhand(cg + 0x25bc4, weaponType);
        if (weapon == 0)
            return;
    }

    if (*(int *)(cg + 0x2be70) == 0)
        return;

    hud = *(byte **)cg_hud_ptr;
    time = (int)floorf(*(float *)(hud + 8) * 1000.0f + 0.5f);
    fade = CG_FadeHudMenu(hud, *(int *)(cg + 0x2c5d0), time);

    if (fade == 0.0f)
        return;

    weapDef = BG_GetWeaponDef(*(int *)(cg + 0x2be70));
    if (*(int *)((byte *)weapDef + 0x84) != weaponType)
        return;

    /* Count total ammo for this weapon type */
    weapCount = BG_GetNumWeapons();
    ammoCount = 0;
    for (i = 1; i <= weapCount; i++) {
        if (!((*(int *)(cg + 0x26108 + (i >> 5) * 4) >> (i & 0x1f)) & 1))
            continue;
        weapDef = BG_GetWeaponDef(i);
        if (*(int *)((byte *)weapDef + 0x84) != weaponType)
            continue;
        clip = BG_ClipForWeapon(i);
        ammoCount += *(int *)(cg + 0x25f08 + clip * 4);
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
    cg = *(byte **)cg_ptr;
    timeSinceF = (float)(*(int *)(cg + 0x25bb0) - *(int *)(cg + 0x2c5d4)) / 1000.0f;
    flashTime = *(float *)((byte *)hud_flash_time_offhand + 8);

    if (flashTime > timeSinceF) {
        angle = timeSinceF * 6.2831855f / *(float *)((byte *)hud_flash_period_offhand + 8);
        pulse = cosf(angle) * 0.5f + 0.5f;
        flashColor[3] = pulse * fade;
    }

    r = (byte *)rect;
    UI_DrawHandlePic(*(float *)r, *(float *)(r + 4), *(float *)(r + 8),
                     *(float *)(r + 0xc), *(float *)(r + 0x10), *(float *)(r + 0x14),
                     flashColor, material);
}

/* line 215 */
void CG_DrawOffHandAmmo(rectDef_s *rect, struct Font_s *font, float scale, vec_t *color, int textStyle, int weaponType)
{
    byte *cg;
    byte *hud;
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
    byte *r;

    cg = *(byte **)cg_ptr;
    if (*(int *)(cg + 0x25bc8) > 5)
        return;

    weapon = BG_GetFirstAvailableOffhand(cg + 0x25bc4, weaponType);
    if (weapon == 0) {
        weapon = BG_GetFirstEquippedOffhand(cg + 0x25bc4, weaponType);
        if (weapon == 0)
            return;
    }

    hud = *(byte **)cg_hud_ptr;
    time = (int)floorf(*(float *)(hud + 8) * 1000.0f + 0.5f);
    fade = CG_FadeHudMenu(hud, *(int *)(cg + 0x2c5d0), time);

    if (fade == 0.0f)
        return;

    /* Count total ammo for this weapon type */
    weapCount = BG_GetNumWeapons();
    ammoCount = 0;
    for (i = 1; i <= weapCount; i++) {
        if (!((*(int *)(cg + 0x26108 + (i >> 5) * 4) >> (i & 0x1f)) & 1))
            continue;
        weapDef = BG_GetWeaponDef(i);
        if (*(int *)((byte *)weapDef + 0x84) != weaponType)
            continue;
        clip = BG_ClipForWeapon(i);
        ammoCount += *(int *)(cg + 0x25f08 + clip * 4);
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

    r = (byte *)rect;
    UI_DrawText(text, 0x7fffffff, font,
                *(float *)r, *(float *)(r + 4),
                *(float *)(r + 0x10), *(float *)(r + 0x14),
                scale, drawColor, textStyle);
}
