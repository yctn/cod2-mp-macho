/* ASM dump from: g_hudelem_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_hudelem_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 */

extern game_hudelem_t g_hudelems[1024]; /* 0x0 */
static const game_hudelem_field_t fields[16]; /* fields */

__attribute__((used)) const char *g_he_vertalign[8] = {
    "subtop",
    "top",
    "middle",
    "bottom",
    "fullscreen",
    "noscale",
    "alignto480",
    "center_safearea",
}; /* 0x314480 */
__attribute__((used)) const char *g_he_horzalign[8] = {
    "subleft",
    "left",
    "center",
    "right",
    "fullscreen",
    "noscale",
    "alignto640",
    "center_safearea",
}; /* 0x3144a0 */
__attribute__((used)) const char *g_he_aligny[3] = {
    "top",
    "middle",
    "bottom",
}; /* 0x3144c0 */
__attribute__((used)) const char *g_he_alignx[3] = {
    "left",
    "center",
    "right",
}; /* 0x3144cc */
__attribute__((used, aligned(4)))
const char * g_he_font[] = {
    "default",
    "bigfixed",
    "smallfixed",
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
}; /* 0x3144d8 */

static void HECmd_SetText(scr_entref_t entref);
static void HECmd_SetPlayerNameString(scr_entref_t entref);
static void HECmd_SetMapNameString(scr_entref_t entref);
static void HECmd_SetGameTypeString(scr_entref_t entref);
static void HECmd_SetShader(scr_entref_t entref);
static void HECmd_SetTimer(scr_entref_t entref);
static void HECmd_SetTimerUp(scr_entref_t entref);
static void HECmd_SetTenthsTimer(scr_entref_t entref);
static void HECmd_SetTenthsTimerUp(scr_entref_t entref);
static void HECmd_SetClock(scr_entref_t entref);
static void HECmd_SetClockUp(scr_entref_t entref);
static void HECmd_SetValue(scr_entref_t entref);
static void HECmd_SetWaypoint(scr_entref_t entref);
static void HECmd_FadeOverTime(scr_entref_t entref);
static void HECmd_ScaleOverTime(scr_entref_t entref);
static void HECmd_MoveOverTime(scr_entref_t entref);
static void HECmd_Reset(scr_entref_t entref);
static void HECmd_Destroy(struct scr_entref_t entref);

static const BuiltinMethodDef methods[] __attribute__((used)) = {
    {"settext", (BuiltinMethod)HECmd_SetText, 0},
    {"setplayernamestring", (BuiltinMethod)HECmd_SetPlayerNameString, 0},
    {"setmapnamestring", (BuiltinMethod)HECmd_SetMapNameString, 0},
    {"setgametypestring", (BuiltinMethod)HECmd_SetGameTypeString, 0},
    {"setshader", (BuiltinMethod)HECmd_SetShader, 0},
    {"settimer", (BuiltinMethod)HECmd_SetTimer, 0},
    {"settimerup", (BuiltinMethod)HECmd_SetTimerUp, 0},
    {"settenthstimer", (BuiltinMethod)HECmd_SetTenthsTimer, 0},
    {"settenthstimerup", (BuiltinMethod)HECmd_SetTenthsTimerUp, 0},
    {"setclock", (BuiltinMethod)HECmd_SetClock, 0},
    {"setclockup", (BuiltinMethod)HECmd_SetClockUp, 0},
    {"setvalue", (BuiltinMethod)HECmd_SetValue, 0},
    {"setwaypoint", (BuiltinMethod)HECmd_SetWaypoint, 0},
    {"fadeovertime", (BuiltinMethod)HECmd_FadeOverTime, 0},
    {"scaleovertime", (BuiltinMethod)HECmd_ScaleOverTime, 0},
    {"moveovertime", (BuiltinMethod)HECmd_MoveOverTime, 0},
    {"reset", (BuiltinMethod)HECmd_Reset, 0},
    {"destroy", (BuiltinMethod)HECmd_Destroy, 0},
};

extern void Scr_AddFloat(float value);
extern float Scr_GetFloat(unsigned int index);
extern int Scr_GetInt(unsigned int index);
extern int Scr_GetIString(unsigned int index);
extern int G_LocalizedStringIndex(int str);
extern void Scr_AddVector(vec_t *vec);
extern void Scr_Error(const char *msg);
extern const char *va(const char *fmt, ...);

static void HudElem_SetEnumString(const char * *names, int nameCount);
static void HudElem_SetLocalizedString(game_hudelem_t *hud, int offset);
static void HudElem_SetBoolean(game_hudelem_t *hud, int offset);
static void HudElem_GetColor(game_hudelem_t *hud, int offset);
static void HudElem_GetAlpha(game_hudelem_t *hud, int offset);
static void HudElem_SetFontScale(game_hudelem_t *hud, int offset);
static void HudElem_SetFont(game_hudelem_t *hud, int offset);
static void HudElem_SetAlignX(game_hudelem_t *hud, int offset);
static void HudElem_SetAlignY(game_hudelem_t *hud, int offset);
static void HudElem_SetHorzAlign(game_hudelem_t *hud, int offset);
static void HudElem_SetVertAlign(game_hudelem_t *hud, int offset);
static void HudElem_GetVertAlign(game_hudelem_t *hud, int offset);
void Scr_GetHudElemField(int entnum, int offset);
void Scr_SetHudElemField(int entnum, int offset);
void Scr_FreeHudElemConstStrings(game_hudelem_t *hud);
void GScr_AddFieldsForHudElems(void);
BuiltinMethod HudElem_GetMethod(const char * *pName);
void HudElem_UpdateClient(gclient_t *client, int clientNum, hudelem_update_t which);
static void HudElem_SetColor(game_hudelem_t *hud, int offset);
static void HudElem_SetAlpha(game_hudelem_t *hud, int offset);
static void HudElem_GetFont(game_hudelem_t *hud, int offset);
static void HudElem_GetAlignX(game_hudelem_t *hud, int offset);
static void HudElem_GetAlignY(game_hudelem_t *hud, int offset);
static void HudElem_GetHorzAlign(game_hudelem_t *hud, int offset);
void HudElem_ClientDisconnect(gentity_t *ent);
void HudElem_DestroyAll(void);
static void HECmd_Destroy(struct scr_entref_t entref);
static void HECmd_SetText(scr_entref_t entref);
static void HECmd_SetPlayerNameString(scr_entref_t entref);
static void HECmd_SetMapNameString(scr_entref_t entref);
static void HECmd_SetGameTypeString(scr_entref_t entref);
static void HECmd_SetShader(scr_entref_t entref);
static void HECmd_SetTimer_Internal(void);
static void HECmd_SetTenthsTimerUp(scr_entref_t entref);
static void HECmd_SetTenthsTimer(scr_entref_t entref);
static void HECmd_SetTimerUp(scr_entref_t entref);
static void HECmd_SetTimer(scr_entref_t entref);
static void HECmd_SetClock_Internal(he_type_t type);
static void HECmd_SetClockUp(scr_entref_t entref);
static void HECmd_SetClock(scr_entref_t entref);
static void HECmd_SetValue(scr_entref_t entref);
static void HECmd_SetWaypoint(scr_entref_t entref);
static void HECmd_FadeOverTime(scr_entref_t entref);
static void HECmd_ScaleOverTime(scr_entref_t entref);
static void HECmd_MoveOverTime(scr_entref_t entref);
static void HECmd_Reset(scr_entref_t entref);
void GScr_NewHudElem(void);
void GScr_NewClientHudElem(void);
void GScr_NewTeamHudElem(void);

/* line 282 */
extern const char *Scr_GetString(unsigned int index);
extern int I_stricmp(const char *s1, const char *s2);
extern void Scr_AddString(const char *s);
extern int G_ShaderIndex(const char *name);

static void HudElem_SetEnumString_impl(game_hudelem_t *hud_base, const game_hudelem_field_t *f, const char **names, int nameCount) {
    char errormsg[0x800];
    int *value;
    const char *selectedName;
    int nameIndex;
    int mask;
    int shift;

    value = (int *)((byte *)hud_base + f->ofs);
    selectedName = (const char *)Scr_GetString(0);

    for (nameIndex = 0; nameIndex < nameCount; nameIndex++) {
        if (I_stricmp(selectedName, names[nameIndex]) == 0) {
            /* Found match: clear old bits, set new bits */
            mask = ((game_hudelem_field_t *)f)->mask;
            shift = ((game_hudelem_field_t *)f)->shift;
            *value = *value & ~(mask << shift);
            *value = *value | (nameIndex << shift);
            return;
        }
    }

    /* Not found: build error message */
    sprintf(errormsg, "\"%s\" is not a valid value for hudelem field \"%s\"\nShould be one of:", selectedName, f->name);
    for (nameIndex = 0; nameIndex < nameCount; nameIndex++) {
        strncat(errormsg, va(" %s", names[nameIndex]), 0x800);
        errormsg[0x800 - 1] = '\0';
    }
    Scr_Error(errormsg);
}
static void HudElem_SetEnumString(const char * *names, int nameCount) {
    /* This function is only called via naked trampolines which are disabled in Emscripten.
       The real work is in HudElem_SetEnumString_impl which is called by SetFont/SetAlignX etc. */
}

/* line 343 */
static void HudElem_SetLocalizedString(game_hudelem_t *hud, int offset)
{
    int str;
    int idx;
    const game_hudelem_field_t *f = &fields[offset];

    str = Scr_GetIString(0);
    idx = G_LocalizedStringIndex(str);
    *(int *)((byte *)hud + f->ofs) = idx;
}

/* line 359 */
static void HudElem_SetBoolean(game_hudelem_t *hud, int offset)
{
    int value;
    const game_hudelem_field_t *f = &fields[offset];

    value = Scr_GetInt(0);
    *(int *)((byte *)hud + f->ofs) = value;
}

/* line 393 */
static void HudElem_GetColor(game_hudelem_t *hud, int offset)
{
    vec3_t color;
    hudelem_t *elem = (hudelem_t *)hud;

    color[0] = (float)elem->color.r * (1.0f / 255.0f);
    color[1] = (float)elem->color.g * (1.0f / 255.0f);
    color[2] = (float)elem->color.b * (1.0f / 255.0f);
    Scr_AddVector(color);
}

/* line 427 */
static void HudElem_GetAlpha(game_hudelem_t *hud, int offset)
{
    Scr_AddFloat((float)((hudelem_t *)hud)->color.a * (1.0f / 255.0f));
}

/* line 440 */
static void HudElem_SetFontScale(game_hudelem_t *hud, int offset)
{
    float scale = Scr_GetFloat(0);

    if (scale <= 0.0f)
        Scr_Error(va("font scale was %g; should be > 0", (double)scale));
    ((hudelem_t *)hud)->fontScale = scale;
}

/* line 458 */
static void HudElem_SetFont(game_hudelem_t *hud, int offset) {
    const game_hudelem_field_t *f = &fields[offset];
    HudElem_SetEnumString_impl(hud, f, g_he_font, 3);
}

/* line 480 */
static void HudElem_SetAlignX(game_hudelem_t *hud, int offset) {
    const game_hudelem_field_t *f = &fields[offset];
    HudElem_SetEnumString_impl(hud, f, g_he_alignx, 3);
}

/* line 502 */
static void HudElem_SetAlignY(game_hudelem_t *hud, int offset) {
    const game_hudelem_field_t *f = &fields[offset];
    HudElem_SetEnumString_impl(hud, f, g_he_aligny, 3);
}

/* line 524 */
static void HudElem_SetHorzAlign(game_hudelem_t *hud, int offset) {
    const game_hudelem_field_t *f = &fields[offset];
    HudElem_SetEnumString_impl(hud, f, g_he_horzalign, 8);
}

/* line 546 */
static void HudElem_SetVertAlign(game_hudelem_t *hud, int offset) {
    const game_hudelem_field_t *f = &fields[offset];
    HudElem_SetEnumString_impl(hud, f, g_he_vertalign, 8);
}

/* line 557 */
static void HudElem_GetVertAlign(game_hudelem_t *hud, int offset) {
    const game_hudelem_field_t *f = &fields[offset];
    int shift = f->shift;
    int mask = f->mask;
    int value = *(int *)((byte *)hud + f->ofs);
    value = (value >> shift) & mask;
    Scr_AddString(g_he_vertalign[value]);
}
