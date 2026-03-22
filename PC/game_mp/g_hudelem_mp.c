/* ASM dump from: g_hudelem_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_hudelem_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 */

extern game_hudelem_t g_hudelems[1024]; /* 0x0 */
static const game_hudelem_field_t fields[16]; /* fields */
extern const char str_00220284[]; /* "default" */
extern const char str_00227904[]; /* "left" */
extern const char str_002b3f60[]; /* "fullscreen" */
extern const char str_002b4cd8[]; /* "subtop" */
extern const char str_002b4ce0[]; /* "top" */
extern const char str_002b4ce4[]; /* "middle" */
extern const char str_002b4cec[]; /* "bottom" */
extern const char str_002b4cf4[]; /* "noscale" */
extern const char str_002b4cfc[]; /* "alignto480" */
extern const char str_002b4d08[]; /* "center_safearea" */
extern const char str_002b4d18[]; /* "subleft" */
extern const char str_002b4d20[]; /* "center" */
extern const char str_002b4d28[]; /* "right" */
extern const char str_002b4d30[]; /* "alignto640" */
extern const char str_002b4d3c[]; /* "bigfixed" */
extern const char str_002b4d48[]; /* "smallfixed" */

__attribute__((used)) const char *g_he_vertalign[8] = {
    str_002b4cd8,
    str_002b4ce0,
    str_002b4ce4,
    str_002b4cec,
    str_002b3f60,
    str_002b4cf4,
    str_002b4cfc,
    str_002b4d08,
}; /* 0x314480 */
__attribute__((used)) const char *g_he_horzalign[8] = {
    str_002b4d18,
    str_00227904,
    str_002b4d20,
    str_002b4d28,
    str_002b3f60,
    str_002b4cf4,
    str_002b4d30,
    str_002b4d08,
}; /* 0x3144a0 */
__attribute__((used)) const char *g_he_aligny[3] = {
    str_002b4ce0,
    str_002b4ce4,
    str_002b4cec,
}; /* 0x3144c0 */
__attribute__((used)) const char *g_he_alignx[3] = {
    str_00227904,
    str_002b4d20,
    str_002b4d28,
}; /* 0x3144cc */
__attribute__((used, aligned(4)))
UInt32 g_he_font_storage[10] __asm__("g_he_font") = {
    (UInt32)str_00220284,
    (UInt32)str_002b4d3c,
    (UInt32)str_002b4d48,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
}; /* 0x3144d8 */

#define g_he_font ((const char * const *)g_he_font_storage)
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
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
void HudElem_SetEnumString(const char * *names, int nameCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 282 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x82c, %esp\n"
        "movl %edx, %edi\n" /* f */
        "movl %ecx, -0x820(%ebp)\n"
        /* { scope 1 */
        "movl 4(%edx), %edx\n" /* line 294 */
        "addl %edx, %eax\n" /* hud */
        "movl %eax, -0x81c(%ebp)\n" /* hud, value */
        "movl $0, (%esp)\n" /* line 295 */
        "calll Scr_GetString\n"
        "movl %eax, %esi\n" /* hud, selectedName */
        "movl 8(%ebp), %edx\n" /* line 296 | nameCount */
        "testl %edx, %edx\n"
        "jle .Lf1b09fa_001b0a51\n"
        "xorl %ebx, %ebx\n" /* nameIndex */
        ".Lf1b09fa_001b0a30:\n"
        "movl -0x820(%ebp), %edx\n" /* line 298 */
        "movl (%edx, %ebx, 4), %eax\n" /* hud */
        "movl %eax, 4(%esp)\n" /* hud */
        "movl %esi, (%esp)\n" /* selectedName */
        "calll I_stricmp\n"
        "testl %eax, %eax\n" /* hud */
        "je .Lf1b09fa_001b0ac8\n"
        "addl $1, %ebx\n" /* line 296 | nameIndex */
        "cmpl %ebx, 8(%ebp)\n" /* nameIndex, nameCount */
        "jne .Lf1b09fa_001b0a30\n"
        ".Lf1b09fa_001b0a51:\n"
        "movl (%edi), %eax\n" /* line 306 | f, hud */
        "movl %eax, 0xc(%esp)\n" /* hud */
        "movl %esi, 8(%esp)\n" /* selectedName */
        "movl $str_002b4d54, 4(%esp)\n" /* ""%s" is not a valid value for hudelem field "%s"
Should be o" */
        "leal -0x818(%ebp), %esi\n" /* errormsg, selectedName */
        "movl %esi, (%esp)\n" /* selectedName */
        "calll sprintf\n"
        "movl 8(%ebp), %eax\n" /* line 307 | nameCount, hud */
        "testl %eax, %eax\n" /* hud */
        "jg .Lf1b09fa_001b0a8b\n"
        ".Lf1b09fa_001b0a78:\n"
        "movl %esi, (%esp)\n" /* line 312 | selectedName */
        "calll Scr_Error\n"
        /* } scope */
        "addl $0x82c, %esp\n" /* line 313 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b09fa_001b0a8b:\n"
        "xorl %ebx, %ebx\n" /* line 307 | nameIndex */
        ".Lf1b09fa_001b0a8d:\n"
        "movl -0x820(%ebp), %edx\n" /* line 309 */
        "movl (%edx, %ebx, 4), %eax\n" /* hud */
        "movl %eax, 4(%esp)\n" /* hud */
        "movl $str_002abc2c, (%esp)\n" /* " %s" */
        "calll va\n"
        "movl $0x800, 8(%esp)\n"
        "movl %eax, 4(%esp)\n" /* hud */
        "movl %esi, (%esp)\n" /* selectedName */
        "calll strncat\n"
        "movb $0, -0x19(%ebp)\n" /* line 310 */
        "addl $1, %ebx\n" /* line 307 | nameIndex */
        "cmpl %ebx, 8(%ebp)\n" /* nameIndex, nameCount */
        "jne .Lf1b09fa_001b0a8d\n"
        "jmp .Lf1b09fa_001b0a78\n"
        ".Lf1b09fa_001b0ac8:\n"
        "movl 0x10(%edi), %ecx\n" /* line 300 | f */
        "movl 0xc(%edi), %eax\n" /* f, hud */
        "shll %cl, %eax\n" /* hud */
        "notl %eax\n" /* hud */
        "movl -0x81c(%ebp), %edx\n" /* value */
        "andl (%edx), %eax\n" /* hud */
        "movl %eax, (%edx)\n" /* hud */
        "movl 0x10(%edi), %ecx\n" /* line 301 | f */
        "shll %cl, %ebx\n" /* nameIndex */
        "orl %ebx, %eax\n" /* nameIndex, hud */
        "movl %eax, (%edx)\n" /* hud */
        /* } scope */
        "addl $0x82c, %esp\n" /* line 313 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
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
    sprintf(errormsg, str_002b4d54, selectedName, f->name);
    for (nameIndex = 0; nameIndex < nameCount; nameIndex++) {
        strncat(errormsg, va(str_002abc2c, names[nameIndex]), 0x800);
        errormsg[0x800 - 1] = '\0';
    }
    Scr_Error(errormsg);
}
static void HudElem_SetEnumString(const char * *names, int nameCount) {
    /* This function is only called via naked trampolines which are disabled in Emscripten.
       The real work is in HudElem_SetEnumString_impl which is called by SetFont/SetAlignX etc. */
}
#endif

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
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
void HudElem_SetFont(game_hudelem_t *hud, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 458 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* hud */
        "movl 0xc(%ebp), %edx\n" /* offset */
        "leal (, %edx, 4), %ecx\n" /* line 460 */
        "shll $5, %edx\n"
        "subl %ecx, %edx\n"
        "addl $fields, %edx\n"
        "movl $3, 8(%ebp)\n" /* hud */
        "movl $g_he_font, %ecx\n"
        "popl %ebp\n" /* line 461 */
        "jmp HudElem_SetEnumString\n" /* line 460 */
    );
}
#else
static void HudElem_SetFont(game_hudelem_t *hud, int offset) {
    const game_hudelem_field_t *f = &fields[offset];
    HudElem_SetEnumString_impl(hud, f, g_he_font, 3);
}
#endif

/* line 480 */
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
void HudElem_SetAlignX(game_hudelem_t *hud, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 480 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* hud */
        "movl 0xc(%ebp), %edx\n" /* offset */
        "leal (, %edx, 4), %ecx\n" /* line 482 */
        "shll $5, %edx\n"
        "subl %ecx, %edx\n"
        "addl $fields, %edx\n"
        "movl $3, 8(%ebp)\n" /* hud */
        "movl $g_he_alignx, %ecx\n"
        "popl %ebp\n" /* line 483 */
        "jmp HudElem_SetEnumString\n" /* line 482 */
    );
}
#else
static void HudElem_SetAlignX(game_hudelem_t *hud, int offset) {
    const game_hudelem_field_t *f = &fields[offset];
    HudElem_SetEnumString_impl(hud, f, g_he_alignx, 3);
}
#endif

/* line 502 */
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
void HudElem_SetAlignY(game_hudelem_t *hud, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 502 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* hud */
        "movl 0xc(%ebp), %edx\n" /* offset */
        "leal (, %edx, 4), %ecx\n" /* line 504 */
        "shll $5, %edx\n"
        "subl %ecx, %edx\n"
        "addl $fields, %edx\n"
        "movl $3, 8(%ebp)\n" /* hud */
        "movl $g_he_aligny, %ecx\n"
        "popl %ebp\n" /* line 505 */
        "jmp HudElem_SetEnumString\n" /* line 504 */
    );
}
#else
static void HudElem_SetAlignY(game_hudelem_t *hud, int offset) {
    const game_hudelem_field_t *f = &fields[offset];
    HudElem_SetEnumString_impl(hud, f, g_he_aligny, 3);
}
#endif

/* line 524 */
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
void HudElem_SetHorzAlign(game_hudelem_t *hud, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 524 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* hud */
        "movl 0xc(%ebp), %edx\n" /* offset */
        "leal (, %edx, 4), %ecx\n" /* line 526 */
        "shll $5, %edx\n"
        "subl %ecx, %edx\n"
        "addl $fields, %edx\n"
        "movl $8, 8(%ebp)\n" /* hud */
        "movl $g_he_horzalign, %ecx\n"
        "popl %ebp\n" /* line 527 */
        "jmp HudElem_SetEnumString\n" /* line 526 */
    );
}
#else
static void HudElem_SetHorzAlign(game_hudelem_t *hud, int offset) {
    const game_hudelem_field_t *f = &fields[offset];
    HudElem_SetEnumString_impl(hud, f, g_he_horzalign, 8);
}
#endif

/* line 546 */
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
void HudElem_SetVertAlign(game_hudelem_t *hud, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 546 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* hud */
        "movl 0xc(%ebp), %edx\n" /* offset */
        "leal (, %edx, 4), %ecx\n" /* line 548 */
        "shll $5, %edx\n"
        "subl %ecx, %edx\n"
        "addl $fields, %edx\n"
        "movl $8, 8(%ebp)\n" /* hud */
        "movl $g_he_vertalign, %ecx\n"
        "popl %ebp\n" /* line 549 */
        "jmp HudElem_SetEnumString\n" /* line 548 */
    );
}
#else
static void HudElem_SetVertAlign(game_hudelem_t *hud, int offset) {
    const game_hudelem_field_t *f = &fields[offset];
    HudElem_SetEnumString_impl(hud, f, g_he_vertalign, 8);
}
#endif

/* line 557 */
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
void HudElem_GetVertAlign(game_hudelem_t *hud, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 557 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 0xc(%ebp), %edx\n" /* offset */
        "leal (, %edx, 4), %eax\n" /* line 559 */
        "shll $5, %edx\n" /* f */
        "subl %eax, %edx\n" /* f */
        "addl $fields, %edx\n" /* f */
        /* { scope 1 */
        "movl 4(%edx), %ecx\n" /* line 334 */
        "movl 0x10(%edx), %ebx\n"
        "movl 8(%ebp), %eax\n" /* hud */
        "movl (%ecx, %eax), %eax\n"
        "movl %ebx, %ecx\n"
        "sarl %cl, %eax\n"
        "andl 0xc(%edx), %eax\n"
        "movl g_he_vertalign(, %eax, 4), %eax\n"
        "movl %eax, 8(%ebp)\n" /* hud */
        /* } scope */
        "popl %ebx\n" /* line 560 */
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddString\n" /* line 334 */
    );
}

/* line 568 */
__attribute__((naked))
void Scr_GetHudElemField(int entnum, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 568 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %edx\n" /* entnum */
        "movl 0xc(%ebp), %ebx\n" /* offset */
        /* { scope 1 */
        "leal (, %ebx, 4), %ecx\n" /* line 576 */
        "movl %ebx, %eax\n" /* offset */
        "shll $5, %eax\n"
        "subl %ecx, %eax\n"
        "leal fields(%eax), %esi\n" /* f */
        "leal (%edx, %edx, 4), %edx\n" /* line 577 */
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "leal g_hudelems(, %eax, 4), %edx\n"
        "movl 0x18(%esi), %ecx\n" /* line 579 | f */
        "testl %ecx, %ecx\n"
        "je .Lf1b0d56_001b0d9d\n"
        "movl %edx, 8(%ebp)\n" /* line 581 | entnum */
        /* } scope */
        "addl $0x10, %esp\n" /* line 586 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmpl *%ecx\n" /* line 581 */
        ".Lf1b0d56_001b0d9d:\n"
        "movl 4(%esi), %eax\n" /* line 585 | f */
        "movl %eax, 8(%esp)\n"
        "movl 8(%esi), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Scr_GetGenericField\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 586 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 594 */
__attribute__((naked))
void Scr_SetHudElemField(int entnum, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 594 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %edx\n" /* entnum */
        "movl 0xc(%ebp), %ebx\n" /* offset */
        /* { scope 1 */
        "leal (, %ebx, 4), %ecx\n" /* line 602 */
        "movl %ebx, %eax\n" /* offset */
        "shll $5, %eax\n"
        "subl %ecx, %eax\n"
        "leal fields(%eax), %esi\n" /* f */
        "leal (%edx, %edx, 4), %edx\n" /* line 603 */
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "leal g_hudelems(, %eax, 4), %edx\n"
        "movl 0x14(%esi), %ecx\n" /* line 605 | f */
        "testl %ecx, %ecx\n"
        "je .Lf1b0dba_001b0e01\n"
        "movl %edx, 8(%ebp)\n" /* line 607 | entnum */
        /* } scope */
        "addl $0x10, %esp\n" /* line 612 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmpl *%ecx\n" /* line 607 */
        ".Lf1b0dba_001b0e01:\n"
        "movl 4(%esi), %eax\n" /* line 611 | f */
        "movl %eax, 8(%esp)\n"
        "movl 8(%esi), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Scr_SetGenericField\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 612 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 620 */
__attribute__((naked))
void Scr_FreeHudElemConstStrings(game_hudelem_t *hud)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 620 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* hud */
        "movl fields, %ecx\n" /* line 624 */
        "testl %ecx, %ecx\n"
        "je .Lf1b0e1e_001b0e68\n"
        "movl $fields+8, %ebx\n"
        "jmp .Lf1b0e1e_001b0e44\n"
        ".Lf1b0e1e_001b0e3a:\n"
        "movl 0x14(%ebx), %eax\n"
        "addl $0x1c, %ebx\n"
        "testl %eax, %eax\n"
        "je .Lf1b0e1e_001b0e68\n"
        ".Lf1b0e1e_001b0e44:\n"
        "cmpl $3, (%ebx)\n" /* line 626 */
        "jne .Lf1b0e1e_001b0e3a\n"
        "movl $0, 4(%esp)\n" /* line 627 */
        "movl %esi, %eax\n" /* hud */
        "addl -4(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_SetString\n"
        "movl 0x14(%ebx), %eax\n" /* line 624 */
        "addl $0x1c, %ebx\n"
        "testl %eax, %eax\n"
        "jne .Lf1b0e1e_001b0e44\n"
        ".Lf1b0e1e_001b0e68:\n"
        "addl $0x10, %esp\n" /* line 629 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 713 */
__attribute__((naked))
void GScr_AddFieldsForHudElems(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 713 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl fields, %ebx\n" /* line 717 */
        "testl %ebx, %ebx\n"
        "je .Lf1b0e70_001b0ecb\n"
        "xorl %edi, %edi\n" /* line 713 */
        "movl $fields+28, %esi\n"
        ".Lf1b0e70_001b0e8a:\n"
        "movl %edi, %ecx\n" /* line 721 */
        "sarl $2, %ecx\n"
        "leal (%ecx, %ecx, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $6, %edx\n"
        "addl %edx, %eax\n"
        "leal (%ecx, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $0xf, %edx\n"
        "addl %edx, %eax\n"
        "leal (%ecx, %eax, 8), %eax\n"
        "negl %eax\n"
        "movzwl %ax, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Scr_AddClassField\n"
        "movl (%esi), %ebx\n" /* line 717 */
        "addl $0x1c, %edi\n"
        "addl $0x1c, %esi\n"
        "testl %ebx, %ebx\n"
        "jne .Lf1b0e70_001b0e8a\n"
        ".Lf1b0e70_001b0ecb:\n"
        "addl $0x1c, %esp\n" /* line 723 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1217 */
__attribute__((naked))
BuiltinMethod HudElem_GetMethod(const char * *pName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1217 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1222 | pName */
        "movl (%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* name */
        "xorl %esi, %esi\n" /* i */
        "movl $methods, %ebx\n"
        "xorl %edi, %edi\n"
        "movl %eax, %edx\n"
        "jmp .Lf1b0ed4_001b0ef5\n"
        ".Lf1b0ed4_001b0ef2:\n"
        "movl -0x1c(%ebp), %edx\n" /* name */
        ".Lf1b0ed4_001b0ef5:\n"
        "movl (%ebx), %eax\n" /* line 1226 */
        "testl %eax, %eax\n"  /* NULL check for zero-init methods table */
        "je .Lf1b0ed4_hud_next\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf1b0ed4_001b0f1f\n"
        ".Lf1b0ed4_hud_next:\n"
        "addl $1, %esi\n" /* line 1224 | i */
        "addl $0xc, %edi\n"
        "addl $0xc, %ebx\n"
        "cmpl $0x12, %esi\n" /* i */
        "jne .Lf1b0ed4_001b0ef2\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1234 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b0ed4_001b0f1f:\n"
        "movl methods(%edi), %eax\n" /* line 1228 */
        "movl 8(%ebp), %edx\n" /* pName */
        "movl %eax, (%edx)\n"
        "movl methods+4(%edi), %eax\n" /* line 1229 */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1234 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1242 */
__attribute__((naked))
void HudElem_UpdateClient(gclient_t *client, int clientNum, hudelem_update_t which)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1242 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* client */
        "movl 0x10(%ebp), %ebx\n" /* which */
        /* { scope 1 */
        "movl %ebx, %eax\n" /* line 1255 | which */
        "andb $1, %al\n"
        "movl %eax, %esi\n" /* currentCount */
        "jne .Lf1b0f38_001b0fef\n"
        "andb $2, %bl\n" /* line 1257 | which */
        "jne .Lf1b0f38_001b1016\n"
        ".Lf1b0f38_001b0f5c:\n"
        "movl %esi, %eax\n" /* line 1258 | currentCount */
        "testb %al, %al\n"
        "je .Lf1b0f38_001b10fc\n"
        "xorl %esi, %esi\n" /* line 1279 | currentCount */
        "movl $g_hudelems+136, %ebx\n" /* which */
        "jmp .Lf1b0f38_001b0f7d\n"
        ".Lf1b0f38_001b0f6f:\n"
        "addl $0x8c, %ebx\n" /* line 1265 | which */
        "cmpl $__ZN12UI_Component1gE+104, %ebx\n" /* line 1263 | which */
        "je .Lf1b0f38_001b0fe7\n"
        ".Lf1b0f38_001b0f7d:\n"
        "movl -0x88(%ebx), %eax\n" /* line 1265 | which */
        "testl %eax, %eax\n"
        "je .Lf1b0f38_001b0f6f\n"
        "movl -4(%ebx), %eax\n" /* line 1267 | which */
        "testl %eax, %eax\n"
        "je .Lf1b0f38_001b0f96\n"
        "cmpl 0x274c(%edi), %eax\n" /* client */
        "jne .Lf1b0f38_001b0f6f\n"
        ".Lf1b0f38_001b0f96:\n"
        "movl -8(%ebx), %eax\n" /* line 1269 | which */
        "cmpl $0x3ff, %eax\n"
        "je .Lf1b0f38_001b0fa5\n"
        "cmpl 0xc(%ebp), %eax\n" /* clientNum */
        "jne .Lf1b0f38_001b0f6f\n"
        ".Lf1b0f38_001b0fa5:\n"
        "movl (%ebx), %eax\n" /* line 1272 | which */
        "testl %eax, %eax\n"
        "je .Lf1b0f38_001b0f6f\n"
        "movl %esi, %eax\n" /* line 1276 | currentCount */
        "shll $7, %eax\n"
        "leal 0x1728(%edi, %eax), %edx\n" /* client */
        "addl $1, %esi\n" /* line 1278 | currentCount */
        "cmpl $0x1f, %esi\n" /* line 1279 | currentCount */
        "jg .Lf1b0f38_001b0f6f\n"
        "leal -0x88(%ebx), %eax\n" /* line 1293 | which */
        "movl $0x80, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "addl $0x8c, %ebx\n" /* line 1265 | which */
        "cmpl $__ZN12UI_Component1gE+104, %ebx\n" /* line 1263 | which */
        "jne .Lf1b0f38_001b0f7d\n"
        /* } scope */
        ".Lf1b0f38_001b0fe7:\n"
        "addl $0x2c, %esp\n" /* line 1295 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b0f38_001b0fef:\n"
        "leal 0x1728(%edi), %eax\n" /* line 1256 | client */
        "movl $0xf80, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "andb $2, %bl\n" /* line 1257 | which */
        "je .Lf1b0f38_001b0f5c\n"
        ".Lf1b0f38_001b1016:\n"
        "leal 0x7a8(%edi), %eax\n" /* line 1258 | client */
        "movl %eax, -0x20(%ebp)\n"
        "movl $0xf80, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl %esi, %eax\n" /* currentCount */
        "testb %al, %al\n"
        "je .Lf1b0f38_001b10d8\n"
        "movl $0, -0x1c(%ebp)\n" /* line 1267 | archivalCount */
        "xorl %esi, %esi\n" /* currentCount */
        "movl $g_hudelems+136, %ebx\n" /* which */
        "jmp .Lf1b0f38_001b105f\n"
        ".Lf1b0f38_001b1051:\n"
        "addl $0x8c, %ebx\n" /* line 1265 | which */
        "cmpl $__ZN12UI_Component1gE+104, %ebx\n" /* line 1263 | which */
        "je .Lf1b0f38_001b0fe7\n"
        ".Lf1b0f38_001b105f:\n"
        "movl -0x88(%ebx), %eax\n" /* line 1265 | which */
        "testl %eax, %eax\n"
        "je .Lf1b0f38_001b1051\n"
        "movl -4(%ebx), %eax\n" /* line 1267 | which */
        "testl %eax, %eax\n"
        "je .Lf1b0f38_001b1078\n"
        "cmpl 0x274c(%edi), %eax\n" /* client */
        "jne .Lf1b0f38_001b1051\n"
        ".Lf1b0f38_001b1078:\n"
        "movl -8(%ebx), %eax\n" /* line 1269 | which */
        "cmpl $0x3ff, %eax\n"
        "je .Lf1b0f38_001b1087\n"
        "cmpl 0xc(%ebp), %eax\n" /* clientNum */
        "jne .Lf1b0f38_001b1051\n"
        ".Lf1b0f38_001b1087:\n"
        "movl (%ebx), %eax\n" /* line 1272 | which */
        "testl %eax, %eax\n"
        "je .Lf1b0f38_001b10c0\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1276 | archivalCount */
        "shll $7, %eax\n"
        "leal 0x1728(%edi, %eax), %edx\n" /* client */
        "addl $1, -0x1c(%ebp)\n" /* line 1278 | archivalCount */
        "cmpl $0x1f, -0x1c(%ebp)\n" /* line 1279 | archivalCount */
        "jg .Lf1b0f38_001b1051\n"
        ".Lf1b0f38_001b10a4:\n"
        "leal -0x88(%ebx), %eax\n" /* line 1293 | which */
        "movl $0x80, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "jmp .Lf1b0f38_001b1051\n"
        ".Lf1b0f38_001b10c0:\n"
        "movl %esi, %eax\n" /* line 1286 | currentCount */
        "shll $7, %eax\n"
        "movl -0x20(%ebp), %edx\n"
        "addl %eax, %edx\n"
        "addl $1, %esi\n" /* line 1288 | currentCount */
        "cmpl $0x1f, %esi\n" /* line 1289 | currentCount */
        "jg .Lf1b0f38_001b1051\n"
        "jmp .Lf1b0f38_001b10a4\n"
        ".Lf1b0f38_001b10d8:\n"
        "xorl %esi, %esi\n" /* line 1295 | currentCount */
        "movl $g_hudelems+136, %ebx\n" /* which */
        ".Lf1b0f38_001b10df:\n"
        "movl -0x88(%ebx), %eax\n" /* line 1265 | which */
        "testl %eax, %eax\n"
        "jne .Lf1b0f38_001b1112\n"
        ".Lf1b0f38_001b10e9:\n"
        "addl $0x8c, %ebx\n" /* which */
        "cmpl $__ZN12UI_Component1gE+104, %ebx\n" /* line 1263 | which */
        "jne .Lf1b0f38_001b10df\n"
        "jmp .Lf1b0f38_001b0fe7\n"
        ".Lf1b0f38_001b10fc:\n"
        "movl $g_hudelems+136, %eax\n" /* line 1258 */
        ".Lf1b0f38_001b1101:\n"
        "addl $0x8c, %eax\n"
        "cmpl $__ZN12UI_Component1gE+104, %eax\n" /* line 1263 */
        "jne .Lf1b0f38_001b1101\n"
        "jmp .Lf1b0f38_001b0fe7\n"
        ".Lf1b0f38_001b1112:\n"
        "movl -4(%ebx), %eax\n" /* line 1267 | which */
        "testl %eax, %eax\n"
        "je .Lf1b0f38_001b1121\n"
        "cmpl 0x274c(%edi), %eax\n" /* client */
        "jne .Lf1b0f38_001b10e9\n"
        ".Lf1b0f38_001b1121:\n"
        "movl -8(%ebx), %eax\n" /* line 1269 | which */
        "cmpl $0x3ff, %eax\n"
        "je .Lf1b0f38_001b1130\n"
        "cmpl 0xc(%ebp), %eax\n" /* clientNum */
        "jne .Lf1b0f38_001b10e9\n"
        ".Lf1b0f38_001b1130:\n"
        "movl (%ebx), %eax\n" /* line 1272 | which */
        "testl %eax, %eax\n"
        "jne .Lf1b0f38_001b10e9\n"
        "movl %esi, %eax\n" /* line 1286 | currentCount */
        "shll $7, %eax\n"
        "movl -0x20(%ebp), %edx\n"
        "addl %eax, %edx\n"
        "addl $1, %esi\n" /* line 1288 | currentCount */
        "cmpl $0x1f, %esi\n" /* line 1289 | currentCount */
        "jg .Lf1b0f38_001b10e9\n"
        "leal -0x88(%ebx), %eax\n" /* line 1293 | which */
        "movl $0x80, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "jmp .Lf1b0f38_001b10e9\n"
    );
}

/* line 375 */
static __attribute__((naked))
void HudElem_SetColor(game_hudelem_t *hud, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 375 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x44, %esp\n"
        "movl 8(%ebp), %ebx\n" /* hud */
        /* { scope 1 */
        "leal -0x14(%ebp), %eax\n" /* line 381 | color */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_GetVector\n"
        "movss -0x14(%ebp), %xmm1\n" /* line 382 | color */
        "movaps %xmm1, %xmm0\n" /* line 45 */
        "subss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf1b1164_001b12f0\n"
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "movss lit4_002ed5dc, %xmm0\n" /* -1.0f */
        /* { scope 2 */
        ".Lf1b1164_001b11ae:\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf1b1164_001b12e0\n"
        "movaps %xmm2, %xmm0\n"
        /* } scope */
        ".Lf1b1164_001b11ba:\n"
        "addss lit4_002ed5d8, %xmm0\n" /* line 428 | 0.5f */
        "movss %xmm0, (%esp)\n"
        "movss %xmm2, -0x38(%ebp)\n"
        "calll floorf\n"
        "fstps -0x1c(%ebp)\n"
        "cvttss2si -0x1c(%ebp), %eax\n"
        "movb %al, 0x20(%ebx)\n" /* hud */
        "movss -0x10(%ebp), %xmm1\n" /* line 383 */
        "movaps %xmm1, %xmm0\n" /* line 45 */
        "subss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss -0x38(%ebp), %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf1b1164_001b12d4\n"
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "movss lit4_002ed5dc, %xmm0\n" /* -1.0f */
        /* { scope 2 */
        ".Lf1b1164_001b120a:\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf1b1164_001b12c4\n"
        "movaps %xmm2, %xmm0\n"
        /* } scope */
        ".Lf1b1164_001b1216:\n"
        "addss lit4_002ed5d8, %xmm0\n" /* line 428 | 0.5f */
        "movss %xmm0, (%esp)\n"
        "movss %xmm2, -0x38(%ebp)\n"
        "calll floorf\n"
        "fstps -0x20(%ebp)\n"
        "cvttss2si -0x20(%ebp), %eax\n"
        "movb %al, 0x21(%ebx)\n" /* hud */
        "movss -0xc(%ebp), %xmm1\n" /* line 384 */
        "movaps %xmm1, %xmm0\n" /* line 45 */
        "subss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss -0x38(%ebp), %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf1b1164_001b12bb\n"
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "movss lit4_002ed5dc, %xmm0\n" /* -1.0f */
        /* { scope 2 */
        ".Lf1b1164_001b1262:\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf1b1164_001b128d\n"
        "movaps %xmm2, %xmm0\n"
        /* } scope */
        "addss lit4_002ed5d8, %xmm0\n" /* line 428 | 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x24(%ebp)\n"
        "cvttss2si -0x24(%ebp), %eax\n"
        "movb %al, 0x22(%ebx)\n" /* hud */
        /* } scope */
        "addl $0x44, %esp\n" /* line 385 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1b1164_001b128d:\n"
        "movaps %xmm1, %xmm0\n" /* line 45 */
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        /* } scope */
        "addss lit4_002ed5d8, %xmm0\n" /* line 428 | 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x24(%ebp)\n"
        "cvttss2si -0x24(%ebp), %eax\n"
        "movb %al, 0x22(%ebx)\n" /* hud */
        /* } scope */
        "addl $0x44, %esp\n" /* line 385 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b1164_001b12bb:\n"
        "movaps %xmm2, %xmm0\n" /* line 45 */
        "subss %xmm1, %xmm0\n"
        "jmp .Lf1b1164_001b1262\n"
        /* { scope 2 */
        ".Lf1b1164_001b12c4:\n"
        "movaps %xmm1, %xmm0\n"
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "jmp .Lf1b1164_001b1216\n"
        /* } scope */
        ".Lf1b1164_001b12d4:\n"
        "movaps %xmm2, %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "jmp .Lf1b1164_001b120a\n"
        /* { scope 2 */
        ".Lf1b1164_001b12e0:\n"
        "movaps %xmm1, %xmm0\n"
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "jmp .Lf1b1164_001b11ba\n"
        /* } scope */
        ".Lf1b1164_001b12f0:\n"
        "movaps %xmm2, %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "jmp .Lf1b1164_001b11ae\n"
    );
}

/* line 411 */
static __attribute__((naked))
void HudElem_SetAlpha(game_hudelem_t *hud, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 411 */
        "movl %esp, %ebp\n"
        "subl $0x38, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 417 */
        "calll Scr_GetFloat\n"
        "fstps -0x1c(%ebp)\n"
        "movss -0x1c(%ebp), %xmm1\n"
        "movss lit4_002ed5d0, %xmm3\n" /* line 45 | 1.0f */
        "movaps %xmm1, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf1b12fc_001b1390\n"
        "movaps %xmm3, %xmm1\n"
        "movss lit4_002ed5dc, %xmm0\n" /* -1.0f */
        ".Lf1b12fc_001b1339:\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf1b12fc_001b1363\n"
        "movaps %xmm2, %xmm0\n"
        "addss lit4_002ed5d8, %xmm0\n" /* line 428 | 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0xc(%ebp)\n"
        "cvttss2si -0xc(%ebp), %edx\n"
        "movl 8(%ebp), %eax\n" /* hud */
        "movb %dl, 0x23(%eax)\n"
        /* } scope */
        "leave\n" /* line 419 */
        "retl\n"
        /* { scope 1 */
        ".Lf1b12fc_001b1363:\n"
        "movaps %xmm1, %xmm0\n" /* line 45 */
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "addss lit4_002ed5d8, %xmm0\n" /* line 428 | 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0xc(%ebp)\n"
        "cvttss2si -0xc(%ebp), %edx\n"
        "movl 8(%ebp), %eax\n" /* hud */
        "movb %dl, 0x23(%eax)\n"
        /* } scope */
        "leave\n" /* line 419 */
        "retl\n"
        /* { scope 1 */
        ".Lf1b12fc_001b1390:\n"
        "movaps %xmm2, %xmm0\n" /* line 45 */
        "subss %xmm1, %xmm0\n"
        "jmp .Lf1b12fc_001b1339\n"
    );
}

/* line 469 */
static __attribute__((naked))
void HudElem_GetFont(game_hudelem_t *hud, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 469 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 0xc(%ebp), %edx\n" /* offset */
        "leal (, %edx, 4), %eax\n" /* line 471 */
        "shll $5, %edx\n" /* f */
        "subl %eax, %edx\n" /* f */
        "addl $fields, %edx\n" /* f */
        /* { scope 1 */
        "movl 4(%edx), %ecx\n" /* line 334 */
        "movl 0x10(%edx), %ebx\n"
        "movl 8(%ebp), %eax\n" /* hud */
        "movl (%ecx, %eax), %eax\n"
        "movl %ebx, %ecx\n"
        "sarl %cl, %eax\n"
        "andl 0xc(%edx), %eax\n"
        "movl g_he_font(, %eax, 4), %eax\n"
        "movl %eax, 8(%ebp)\n" /* hud */
        /* } scope */
        "popl %ebx\n" /* line 472 */
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddString\n" /* line 334 */
    );
}

/* line 491 */
static __attribute__((naked))
void HudElem_GetAlignX(game_hudelem_t *hud, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 491 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 0xc(%ebp), %edx\n" /* offset */
        "leal (, %edx, 4), %eax\n" /* line 493 */
        "shll $5, %edx\n" /* f */
        "subl %eax, %edx\n" /* f */
        "addl $fields, %edx\n" /* f */
        /* { scope 1 */
        "movl 4(%edx), %ecx\n" /* line 334 */
        "movl 0x10(%edx), %ebx\n"
        "movl 8(%ebp), %eax\n" /* hud */
        "movl (%ecx, %eax), %eax\n"
        "movl %ebx, %ecx\n"
        "sarl %cl, %eax\n"
        "andl 0xc(%edx), %eax\n"
        "movl g_he_alignx(, %eax, 4), %eax\n"
        "movl %eax, 8(%ebp)\n" /* hud */
        /* } scope */
        "popl %ebx\n" /* line 494 */
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddString\n" /* line 334 */
    );
}

/* line 513 */
static __attribute__((naked))
void HudElem_GetAlignY(game_hudelem_t *hud, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 513 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 0xc(%ebp), %edx\n" /* offset */
        "leal (, %edx, 4), %eax\n" /* line 515 */
        "shll $5, %edx\n" /* f */
        "subl %eax, %edx\n" /* f */
        "addl $fields, %edx\n" /* f */
        /* { scope 1 */
        "movl 4(%edx), %ecx\n" /* line 334 */
        "movl 0x10(%edx), %ebx\n"
        "movl 8(%ebp), %eax\n" /* hud */
        "movl (%ecx, %eax), %eax\n"
        "movl %ebx, %ecx\n"
        "sarl %cl, %eax\n"
        "andl 0xc(%edx), %eax\n"
        "movl g_he_aligny(, %eax, 4), %eax\n"
        "movl %eax, 8(%ebp)\n" /* hud */
        /* } scope */
        "popl %ebx\n" /* line 516 */
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddString\n" /* line 334 */
    );
}

/* line 535 */
static __attribute__((naked))
void HudElem_GetHorzAlign(game_hudelem_t *hud, int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 535 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 0xc(%ebp), %edx\n" /* offset */
        "leal (, %edx, 4), %eax\n" /* line 537 */
        "shll $5, %edx\n" /* f */
        "subl %eax, %edx\n" /* f */
        "addl $fields, %edx\n" /* f */
        /* { scope 1 */
        "movl 4(%edx), %ecx\n" /* line 334 */
        "movl 0x10(%edx), %ebx\n"
        "movl 8(%ebp), %eax\n" /* hud */
        "movl (%ecx, %eax), %eax\n"
        "movl %ebx, %ecx\n"
        "sarl %cl, %eax\n"
        "andl 0xc(%edx), %eax\n"
        "movl g_he_horzalign(, %eax, 4), %eax\n"
        "movl %eax, 8(%ebp)\n" /* hud */
        /* } scope */
        "popl %ebx\n" /* line 538 */
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_AddString\n" /* line 334 */
    );
}

/* line 241 */
__attribute__((naked))
void HudElem_ClientDisconnect(gentity_t *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 241 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* ent */
        "movl $g_hudelems, %ebx\n"
        "jmp .Lf1b1494_001b14b4\n"
        ".Lf1b1494_001b14a6:\n"
        "addl $0x8c, %ebx\n" /* line 232 */
        "cmpl $g_hudelems+143360, %ebx\n" /* line 246 */
        "je .Lf1b1494_001b14e0\n"
        ".Lf1b1494_001b14b4:\n"
        "movl (%ebx), %ecx\n" /* line 248 */
        "testl %ecx, %ecx\n"
        "je .Lf1b1494_001b14a6\n"
        "movl 0x80(%ebx), %eax\n" /* line 250 */
        "cmpl (%esi), %eax\n" /* ent */
        "jne .Lf1b1494_001b14a6\n"
        "movl %ebx, (%esp)\n" /* line 231 */
        "calll Scr_FreeHudElem\n"
        "movl $0, (%ebx)\n" /* line 232 */
        "addl $0x8c, %ebx\n"
        "cmpl $g_hudelems+143360, %ebx\n" /* line 246 */
        "jne .Lf1b1494_001b14b4\n"
        ".Lf1b1494_001b14e0:\n"
        "addl $0x10, %esp\n" /* line 253 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 261 */
__attribute__((naked))
void HudElem_DestroyAll(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 261 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl $g_hudelems, %ebx\n"
        "jmp .Lf1b14e8_001b1504\n"
        ".Lf1b14e8_001b14f6:\n"
        "addl $0x8c, %ebx\n" /* line 232 */
        "cmpl $g_hudelems+143360, %ebx\n" /* line 266 */
        "je .Lf1b14e8_001b1526\n"
        ".Lf1b14e8_001b1504:\n"
        "movl (%ebx), %eax\n" /* line 268 */
        "testl %eax, %eax\n"
        "je .Lf1b14e8_001b14f6\n"
        "movl %ebx, (%esp)\n" /* line 231 */
        "calll Scr_FreeHudElem\n"
        "movl $0, (%ebx)\n" /* line 232 */
        "addl $0x8c, %ebx\n"
        "cmpl $g_hudelems+143360, %ebx\n" /* line 266 */
        "jne .Lf1b14e8_001b1504\n"
        ".Lf1b14e8_001b1526:\n"
        "movl $0x23000, 8(%esp)\n" /* line 273 */
        "movl $0, 4(%esp)\n"
        "movl $g_hudelems, (%esp)\n"
        "calll memset\n"
        "addl $0x14, %esp\n" /* line 274 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1180 */
static __attribute__((naked))
void HECmd_Destroy(struct scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1180 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 734 */
        "subw $1, %ax\n"
        "je .Lf1b1548_001b157f\n"
        "movl $str_002b4dbc, (%esp)\n" /* line 740 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        "movl %ebx, (%esp)\n" /* line 231 */
        "calll Scr_FreeHudElem\n"
        "movl $0, (%ebx)\n" /* line 232 */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1186 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b1548_001b157f:\n"
        "movzwl %dx, %eax\n" /* line 737 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "leal g_hudelems(, %edx, 4), %ebx\n"
        "movl %ebx, (%esp)\n" /* line 231 */
        "calll Scr_FreeHudElem\n"
        "movl $0, (%ebx)\n" /* line 232 */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1186 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 750 */
static __attribute__((naked))
void HECmd_SetText(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 750 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 734 */
        "subw $1, %ax\n"
        "je .Lf1b15aa_001b1653\n"
        "movl $str_002b4dbc, (%esp)\n" /* line 740 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        ".Lf1b15aa_001b15d1:\n"
        "movl $0, (%esp)\n" /* line 756 */
        "calll Scr_GetIString\n"
        "movl $0, 0x34(%ebx)\n" /* line 144 */
        "movl $0, 0x38(%ebx)\n" /* line 145 */
        "movl $0, 0x3c(%ebx)\n" /* line 146 */
        "xorl %edx, %edx\n" /* line 147 */
        "movl %edx, 0x50(%ebx)\n"
        "movl %edx, 0x54(%ebx)\n" /* line 148 */
        "movl $0, 0x58(%ebx)\n" /* line 149 */
        "movl $0, 0x5c(%ebx)\n" /* line 150 */
        "movl $0, 0x40(%ebx)\n" /* line 151 */
        "movl $0, 0x44(%ebx)\n" /* line 152 */
        "movl $0, 0x48(%ebx)\n" /* line 153 */
        "movl $0, 0x4c(%ebx)\n" /* line 154 */
        "movl $0, 0x68(%ebx)\n" /* line 155 */
        "movl $0, 0x6c(%ebx)\n" /* line 156 */
        "movl %edx, 0x70(%ebx)\n" /* line 157 */
        "movl $0, 0x74(%ebx)\n" /* line 158 */
        "movl $1, (%ebx)\n" /* line 758 | hud */
        "movl %eax, (%esp)\n" /* line 759 */
        "calll G_LocalizedStringIndex\n"
        "movl %eax, 0x74(%ebx)\n" /* hud */
        /* } scope */
        "addl $0x14, %esp\n" /* line 762 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b15aa_001b1653:\n"
        "movzwl %dx, %eax\n" /* line 737 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "leal g_hudelems(, %edx, 4), %ebx\n"
        "jmp .Lf1b15aa_001b15d1\n"
    );
}

/* line 765 */
static __attribute__((naked))
void HECmd_SetPlayerNameString(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 765 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 734 */
        "subw $1, %ax\n"
        "je .Lf1b166e_001b172d\n"
        "movl $str_002b4dbc, (%esp)\n" /* line 740 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        ".Lf1b166e_001b1695:\n"
        "movl $0, (%esp)\n" /* line 771 */
        "calll Scr_GetEntity\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 773 */
        "je .Lf1b166e_001b1748\n"
        "movl 0x158(%eax), %eax\n" /* line 779 */
        "testl %eax, %eax\n"
        "je .Lf1b166e_001b1759\n"
        "movl $0, 0x34(%ebx)\n" /* line 144 */
        "movl $0, 0x38(%ebx)\n" /* line 145 */
        "movl $0, 0x3c(%ebx)\n" /* line 146 */
        "xorl %eax, %eax\n" /* line 147 */
        "movl %eax, 0x50(%ebx)\n"
        "movl %eax, 0x54(%ebx)\n" /* line 148 */
        "movl $0, 0x58(%ebx)\n" /* line 149 */
        "movl $0, 0x5c(%ebx)\n" /* line 150 */
        "movl $0, 0x40(%ebx)\n" /* line 151 */
        "movl $0, 0x44(%ebx)\n" /* line 152 */
        "movl $0, 0x48(%ebx)\n" /* line 153 */
        "movl $0, 0x4c(%ebx)\n" /* line 154 */
        "movl $0, 0x68(%ebx)\n" /* line 155 */
        "movl $0, 0x6c(%ebx)\n" /* line 156 */
        "movl %eax, 0x70(%ebx)\n" /* line 157 */
        "movl $0, 0x74(%ebx)\n" /* line 158 */
        "movl $3, (%ebx)\n" /* line 786 | hud */
        "cvtsi2ssl (%edx), %xmm0\n" /* line 787 */
        "movss %xmm0, 0x70(%ebx)\n" /* hud */
        /* } scope */
        "addl $0x14, %esp\n" /* line 788 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b166e_001b172d:\n"
        "movzwl %dx, %eax\n" /* line 737 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "leal g_hudelems(, %edx, 4), %ebx\n"
        "jmp .Lf1b166e_001b1695\n"
        ".Lf1b166e_001b1748:\n"
        "movl $str_002b4dd0, 8(%ebp)\n" /* line 775 | entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 788 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Com_Printf\n" /* line 775 */
        ".Lf1b166e_001b1759:\n"
        "movl $str_002b4e08, 8(%ebp)\n" /* line 781 | entref */
        /* } scope */
        "addl $0x14, %esp\n" /* line 788 */
        "popl %ebx\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Com_Printf\n" /* line 781 */
    );
}

/* line 819 */
static __attribute__((naked))
void HECmd_SetMapNameString(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 819 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 734 */
        "subw $1, %ax\n"
        "je .Lf1b176a_001b1842\n"
        "movl $str_002b4dbc, (%esp)\n" /* line 740 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        "movl $0, (%esp)\n" /* line 825 */
        "calll Scr_GetString\n"
        "movl %eax, %esi\n" /* mapname */
        "testl %eax, %eax\n" /* line 827 */
        "je .Lf1b176a_001b186e\n"
        ".Lf1b176a_001b17a8:\n"
        "movl %eax, (%esp)\n" /* line 833 */
        "calll SV_MapExists\n"
        "testl %eax, %eax\n"
        "jne .Lf1b176a_001b17c6\n"
        "movl $str_002b4e90, 8(%ebp)\n" /* line 835 | entref */
        /* } scope */
        "addl $0x10, %esp\n" /* line 843 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Com_Printf\n" /* line 835 */
        ".Lf1b176a_001b17c6:\n"
        "movl %esi, 4(%esp)\n" /* line 839 | mapname */
        "movl $0x13, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "movl $0, 0x34(%ebx)\n" /* line 144 */
        "movl $0, 0x38(%ebx)\n" /* line 145 */
        "movl $0, 0x3c(%ebx)\n" /* line 146 */
        "xorl %eax, %eax\n" /* line 147 */
        "movl %eax, 0x50(%ebx)\n"
        "movl %eax, 0x54(%ebx)\n" /* line 148 */
        "movl $0, 0x58(%ebx)\n" /* line 149 */
        "movl $0, 0x5c(%ebx)\n" /* line 150 */
        "movl $0, 0x40(%ebx)\n" /* line 151 */
        "movl $0, 0x44(%ebx)\n" /* line 152 */
        "movl $0, 0x48(%ebx)\n" /* line 153 */
        "movl $0, 0x4c(%ebx)\n" /* line 154 */
        "movl $0, 0x68(%ebx)\n" /* line 155 */
        "movl $0, 0x6c(%ebx)\n" /* line 156 */
        "movl %eax, 0x70(%ebx)\n" /* line 157 */
        "movl $0, 0x74(%ebx)\n" /* line 158 */
        "movl $4, (%ebx)\n" /* line 842 | hud */
        /* } scope */
        "addl $0x10, %esp\n" /* line 843 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b176a_001b1842:\n"
        "movzwl %dx, %eax\n" /* line 737 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "leal g_hudelems(, %edx, 4), %ebx\n"
        "movl $0, (%esp)\n" /* line 825 */
        "calll Scr_GetString\n"
        "movl %eax, %esi\n" /* mapname */
        "testl %eax, %eax\n" /* line 827 */
        "jne .Lf1b176a_001b17a8\n"
        ".Lf1b176a_001b186e:\n"
        "movl $str_002b4e58, 8(%ebp)\n" /* line 829 | entref */
        /* } scope */
        "addl $0x10, %esp\n" /* line 843 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Com_Printf\n" /* line 835 */
    );
}

/* line 791 */
static __attribute__((naked))
void HECmd_SetGameTypeString(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 791 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 734 */
        "subw $1, %ax\n"
        "je .Lf1b1880_001b194e\n"
        "movl $str_002b4dbc, (%esp)\n" /* line 740 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        "movl $0, (%esp)\n" /* line 797 */
        "calll Scr_GetString\n"
        "movl %eax, %esi\n" /* gametype */
        "testl %eax, %eax\n" /* line 799 */
        "je .Lf1b1880_001b197a\n"
        ".Lf1b1880_001b18be:\n"
        "movl %eax, (%esp)\n" /* line 805 */
        "calll Scr_GetGameTypeNameForScript\n"
        "testl %eax, %eax\n"
        "je .Lf1b1880_001b198c\n"
        "movl %esi, 4(%esp)\n" /* line 811 | gametype */
        "movl $0x14, (%esp)\n"
        "calll SV_SetConfigstring\n"
        "movl $0, 0x34(%ebx)\n" /* line 144 */
        "movl $0, 0x38(%ebx)\n" /* line 145 */
        "movl $0, 0x3c(%ebx)\n" /* line 146 */
        "xorl %eax, %eax\n" /* line 147 */
        "movl %eax, 0x50(%ebx)\n"
        "movl %eax, 0x54(%ebx)\n" /* line 148 */
        "movl $0, 0x58(%ebx)\n" /* line 149 */
        "movl $0, 0x5c(%ebx)\n" /* line 150 */
        "movl $0, 0x40(%ebx)\n" /* line 151 */
        "movl $0, 0x44(%ebx)\n" /* line 152 */
        "movl $0, 0x48(%ebx)\n" /* line 153 */
        "movl $0, 0x4c(%ebx)\n" /* line 154 */
        "movl $0, 0x68(%ebx)\n" /* line 155 */
        "movl $0, 0x6c(%ebx)\n" /* line 156 */
        "movl $0, 0x74(%ebx)\n" /* line 158 */
        "movl $5, (%ebx)\n" /* line 814 | hud */
        "movl $0x41a00000, 0x70(%ebx)\n" /* line 815 | hud */
        /* } scope */
        "addl $0x10, %esp\n" /* line 816 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b1880_001b194e:\n"
        "movzwl %dx, %eax\n" /* line 737 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "leal g_hudelems(, %edx, 4), %ebx\n"
        "movl $0, (%esp)\n" /* line 797 */
        "calll Scr_GetString\n"
        "movl %eax, %esi\n" /* gametype */
        "testl %eax, %eax\n" /* line 799 */
        "jne .Lf1b1880_001b18be\n"
        ".Lf1b1880_001b197a:\n"
        "movl $str_002b4ed8, 8(%ebp)\n" /* line 801 | entref */
        /* } scope */
        "addl $0x10, %esp\n" /* line 816 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Com_Printf\n" /* line 801 */
        ".Lf1b1880_001b198c:\n"
        "movl %esi, 4(%esp)\n" /* line 807 | gametype */
        "movl $str_002b4f10, (%esp)\n" /* "Invalid gametype '%s'
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 816 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 851 */
static __attribute__((naked))
void HECmd_SetShader(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 851 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 734 */
        "subw $1, %ax\n"
        "je .Lf1b19a4_001b1a9a\n"
        "movl $str_002b4dbc, (%esp)\n" /* line 740 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        ".Lf1b19a4_001b19cd:\n"
        "calll Scr_GetNumParam\n" /* line 861 */
        "movl %eax, %esi\n" /* height */
        "cmpl $1, %eax\n" /* line 862 */
        "je .Lf1b19a4_001b19ea\n"
        "cmpl $3, %eax\n"
        "je .Lf1b19a4_001b19ea\n"
        "movl $str_002b4f28, (%esp)\n" /* line 863 */
        "calll Scr_Error\n"
        ".Lf1b19a4_001b19ea:\n"
        "movl $0, (%esp)\n" /* line 865 */
        "calll Scr_GetString\n"
        "movl %eax, (%esp)\n"
        "calll G_ShaderIndex\n"
        "movl %eax, -0x1c(%ebp)\n" /* materialIndex */
        "cmpl $1, %esi\n" /* line 866 | height */
        "je .Lf1b19a4_001b1ab5\n"
        "movl $1, (%esp)\n" /* line 873 */
        "calll Scr_GetInt\n"
        "movl %eax, %edi\n" /* width */
        "testl %eax, %eax\n" /* line 874 */
        "js .Lf1b19a4_001b1ae4\n"
        ".Lf1b19a4_001b1a20:\n"
        "movl $2, (%esp)\n" /* line 876 */
        "calll Scr_GetInt\n"
        "movl %eax, %esi\n" /* height */
        "testl %eax, %eax\n" /* line 877 */
        "js .Lf1b19a4_001b1abf\n"
        ".Lf1b19a4_001b1a36:\n"
        "xorl %eax, %eax\n" /* line 147 */
        "movl %eax, 0x50(%ebx)\n"
        "movl %eax, 0x54(%ebx)\n" /* line 148 */
        "movl $0, 0x58(%ebx)\n" /* line 149 */
        "movl $0, 0x5c(%ebx)\n" /* line 150 */
        "movl $0, 0x40(%ebx)\n" /* line 151 */
        "movl $0, 0x44(%ebx)\n" /* line 152 */
        "movl $0, 0x48(%ebx)\n" /* line 153 */
        "movl $0, 0x4c(%ebx)\n" /* line 154 */
        "movl $0, 0x68(%ebx)\n" /* line 155 */
        "movl $0, 0x6c(%ebx)\n" /* line 156 */
        "movl %eax, 0x70(%ebx)\n" /* line 157 */
        "movl $0, 0x74(%ebx)\n" /* line 158 */
        "movl $6, (%ebx)\n" /* line 882 | hud */
        "movl -0x1c(%ebp), %eax\n" /* line 883 | materialIndex */
        "movl %eax, 0x3c(%ebx)\n" /* hud */
        "movl %edi, 0x34(%ebx)\n" /* line 884 | width, hud */
        "movl %esi, 0x38(%ebx)\n" /* line 885 | height, hud */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 888 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b19a4_001b1a9a:\n"
        "movzwl %dx, %eax\n" /* line 737 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "leal g_hudelems(, %edx, 4), %ebx\n"
        "jmp .Lf1b19a4_001b19cd\n"
        ".Lf1b19a4_001b1ab5:\n"
        "xorl %edi, %edi\n" /* line 866 | width */
        "xorw %si, %si\n" /* height */
        "jmp .Lf1b19a4_001b1a36\n"
        ".Lf1b19a4_001b1abf:\n"
        "movl %eax, 4(%esp)\n" /* line 878 */
        "movl $str_002b4f88, (%esp)\n" /* "height %i < 0" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf1b19a4_001b1a36\n"
        ".Lf1b19a4_001b1ae4:\n"
        "movl %eax, 4(%esp)\n" /* line 875 */
        "movl $str_002b4f78, (%esp)\n" /* "width %i < 0" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf1b19a4_001b1a20\n"
    );
}

/* line 896 */
static __attribute__((naked))
void HECmd_SetTimer_Internal(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 896 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %edx, %edi\n" /* type */
        "movl %ecx, %esi\n" /* cmdName */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 734 */
        "subw $1, %ax\n"
        "je .Lf1b1b0a_001b1c03\n"
        "movl $str_002b4dbc, (%esp)\n" /* line 740 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        ".Lf1b1b0a_001b1b34:\n"
        "calll Scr_GetNumParam\n" /* line 904 */
        "subl $1, %eax\n" /* entref */
        "je .Lf1b1b0a_001b1b56\n"
        "movl %esi, 4(%esp)\n" /* line 905 | time */
        "movl $str_002b4f98, (%esp)\n" /* "USAGE: <hudelem> %s(time_in_seconds);
" */
        "calll va\n"
        "movl %eax, (%esp)\n" /* entref */
        "calll Scr_Error\n"
        ".Lf1b1b0a_001b1b56:\n"
        "movl $0, (%esp)\n" /* line 907 */
        "calll Scr_GetFloat\n"
        "fstps -0x2c(%ebp)\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "mulss lit4_002ed5c8, %xmm0\n" /* line 458 | 1000.0f */
        "movss %xmm0, (%esp)\n"
        "calll ceilf\n"
        "fstps -0x1c(%ebp)\n"
        "cvttss2si -0x1c(%ebp), %esi\n"
        "testl %esi, %esi\n" /* line 908 | time */
        "jle .Lf1b1b0a_001b1c1e\n"
        ".Lf1b1b0a_001b1b8c:\n"
        "movl $0, 0x34(%ebx)\n" /* line 144 */
        "movl $0, 0x38(%ebx)\n" /* line 145 */
        "movl $0, 0x3c(%ebx)\n" /* line 146 */
        "xorl %eax, %eax\n" /* line 147 */
        "movl %eax, 0x50(%ebx)\n"
        "movl %eax, 0x54(%ebx)\n" /* line 148 */
        "movl $0, 0x58(%ebx)\n" /* line 149 */
        "movl $0, 0x5c(%ebx)\n" /* line 150 */
        "movl $0, 0x40(%ebx)\n" /* line 151 */
        "movl $0, 0x44(%ebx)\n" /* line 152 */
        "movl $0, 0x48(%ebx)\n" /* line 153 */
        "movl $0, 0x4c(%ebx)\n" /* line 154 */
        "movl $0, 0x68(%ebx)\n" /* line 155 */
        "movl $0, 0x6c(%ebx)\n" /* line 156 */
        "movl %eax, 0x70(%ebx)\n" /* line 157 */
        "movl $0, 0x74(%ebx)\n" /* line 158 */
        "movl %edi, (%ebx)\n" /* line 912 | type, hud */
        "movl imp_level, %eax\n" /* line 913 | entref */
        "addl 0x1ec(%eax), %esi\n" /* entref, time */
        "movl %esi, 0x68(%ebx)\n" /* time, hud */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 914 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b1b0a_001b1c03:\n"
        "movzwl %dx, %eax\n" /* line 737 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "leal g_hudelems(, %edx, 4), %ebx\n"
        "jmp .Lf1b1b0a_001b1b34\n"
        ".Lf1b1b0a_001b1c1e:\n"
        "cmpl $8, %edi\n" /* line 908 | type */
        "je .Lf1b1b0a_001b1b8c\n"
        "cvtsi2ssl %esi, %xmm0\n" /* line 909 | time */
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 4(%esp)\n"
        "movl $str_002b4fc0, (%esp)\n" /* "time %g should be > 0" */
        "calll va\n"
        "movl %eax, 4(%esp)\n" /* entref */
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf1b1b0a_001b1b8c\n"
    );
}

/* line 1011 */
static __attribute__((naked))
void HECmd_SetTenthsTimerUp(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1011 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl $str_002b4fd8, %ecx\n" /* line 1013 */
        "movl $0xa, %edx\n"
        "popl %ebp\n" /* line 1014 */
        "jmp HECmd_SetTimer_Internal\n" /* line 1013 */
    );
}

/* line 1000 */
static __attribute__((naked))
void HECmd_SetTenthsTimer(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1000 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl $str_002b4fec, %ecx\n" /* line 1002 */
        "movl $9, %edx\n"
        "popl %ebp\n" /* line 1003 */
        "jmp HECmd_SetTimer_Internal\n" /* line 1002 */
    );
}

/* line 989 */
static __attribute__((naked))
void HECmd_SetTimerUp(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 989 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl $str_002b4ffc, %ecx\n" /* line 991 */
        "movl $8, %edx\n"
        "popl %ebp\n" /* line 992 */
        "jmp HECmd_SetTimer_Internal\n" /* line 991 */
    );
}

/* line 978 */
static __attribute__((naked))
void HECmd_SetTimer(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 978 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl $str_002b5008, %ecx\n" /* line 980 */
        "movl $7, %edx\n"
        "popl %ebp\n" /* line 981 */
        "jmp HECmd_SetTimer_Internal\n" /* line 980 */
    );
}

/* line 922 */
static __attribute__((naked))
void HECmd_SetClock_Internal(he_type_t type)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 922 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %edx, -0x28(%ebp)\n"
        "movl %ecx, %edi\n" /* cmdName */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 734 */
        "subw $1, %ax\n"
        "je .Lf1b1cb6_001b1e55\n"
        "movl $str_002b4dbc, (%esp)\n" /* line 740 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        ".Lf1b1cb6_001b1ce1:\n"
        "calll Scr_GetNumParam\n" /* line 935 */
        "movl %eax, %esi\n" /* entref, height */
        "cmpl $3, %eax\n" /* line 936 | entref */
        "je .Lf1b1cb6_001b1d0a\n"
        "cmpl $5, %eax\n" /* entref */
        "je .Lf1b1cb6_001b1d0a\n"
        "movl %edi, 4(%esp)\n" /* line 937 | time */
        "movl $str_002b5014, (%esp)\n" /* "USAGE: <hudelem> %s(time_in_seconds, total_clock_time_in_sec" */
        "calll va\n"
        "movl %eax, (%esp)\n" /* entref */
        "calll Scr_Error\n"
        ".Lf1b1cb6_001b1d0a:\n"
        "movl $0, (%esp)\n" /* line 939 */
        "calll Scr_GetFloat\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "mulss lit4_002ed5c8, %xmm0\n" /* line 458 | 1000.0f */
        "movss %xmm0, (%esp)\n"
        "calll ceilf\n"
        "fstps -0x2c(%ebp)\n"
        "cvttss2si -0x2c(%ebp), %edi\n"
        "testl %edi, %edi\n" /* line 940 | time */
        "jle .Lf1b1cb6_001b1e7f\n"
        ".Lf1b1cb6_001b1d40:\n"
        "movl $1, (%esp)\n" /* line 943 */
        "calll Scr_GetFloat\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "mulss lit4_002ed5c8, %xmm0\n" /* line 458 | 1000.0f */
        "movss %xmm0, (%esp)\n"
        "calll ceilf\n"
        "fstps -0x30(%ebp)\n"
        "cvttss2si -0x30(%ebp), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* duration */
        "testl %eax, %eax\n" /* line 944 | entref */
        "jle .Lf1b1cb6_001b1ee5\n"
        ".Lf1b1cb6_001b1d79:\n"
        "movl $2, (%esp)\n" /* line 947 */
        "calll Scr_GetString\n"
        "movl %eax, (%esp)\n" /* entref */
        "calll G_ShaderIndex\n"
        "movl %eax, -0x20(%ebp)\n" /* entref, materialIndex */
        "cmpl $3, %esi\n" /* line 948 | height */
        "je .Lf1b1cb6_001b1e70\n"
        "movl $3, (%esp)\n" /* line 955 */
        "calll Scr_GetInt\n"
        "movl %eax, -0x1c(%ebp)\n" /* entref, width */
        "testl %eax, %eax\n" /* line 956 | entref */
        "js .Lf1b1cb6_001b1f1c\n"
        ".Lf1b1cb6_001b1db0:\n"
        "movl $4, (%esp)\n" /* line 958 */
        "calll Scr_GetInt\n"
        "movl %eax, %esi\n" /* entref, height */
        "testl %eax, %eax\n" /* line 959 | entref */
        "js .Lf1b1cb6_001b1ec0\n"
        ".Lf1b1cb6_001b1dc6:\n"
        "movl $0, 0x34(%ebx)\n" /* line 144 */
        "movl $0, 0x38(%ebx)\n" /* line 145 */
        "movl $0, 0x3c(%ebx)\n" /* line 146 */
        "xorl %eax, %eax\n" /* line 147 */
        "movl %eax, 0x50(%ebx)\n"
        "movl %eax, 0x54(%ebx)\n" /* line 148 */
        "movl $0, 0x58(%ebx)\n" /* line 149 */
        "movl $0, 0x5c(%ebx)\n" /* line 150 */
        "movl $0, 0x40(%ebx)\n" /* line 151 */
        "movl $0, 0x44(%ebx)\n" /* line 152 */
        "movl $0, 0x48(%ebx)\n" /* line 153 */
        "movl $0, 0x4c(%ebx)\n" /* line 154 */
        "movl $0, 0x68(%ebx)\n" /* line 155 */
        "movl $0, 0x6c(%ebx)\n" /* line 156 */
        "movl %eax, 0x70(%ebx)\n" /* line 157 */
        "movl $0, 0x74(%ebx)\n" /* line 158 */
        "movl -0x28(%ebp), %eax\n" /* line 964 | entref */
        "movl %eax, (%ebx)\n" /* entref, hud */
        "movl imp_level, %eax\n" /* line 965 | entref */
        "addl 0x1ec(%eax), %edi\n" /* entref, time */
        "movl %edi, 0x68(%ebx)\n" /* time, hud */
        "movl -0x24(%ebp), %eax\n" /* line 966 | duration, entref */
        "movl %eax, 0x6c(%ebx)\n" /* entref, hud */
        "movl -0x20(%ebp), %eax\n" /* line 967 | materialIndex, entref */
        "movl %eax, 0x3c(%ebx)\n" /* entref, hud */
        "movl -0x1c(%ebp), %eax\n" /* line 968 | width, entref */
        "movl %eax, 0x34(%ebx)\n" /* entref, hud */
        "movl %esi, 0x38(%ebx)\n" /* line 969 | height, hud */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 970 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b1cb6_001b1e55:\n"
        "movzwl %dx, %eax\n" /* line 737 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "leal g_hudelems(, %edx, 4), %ebx\n"
        "jmp .Lf1b1cb6_001b1ce1\n"
        ".Lf1b1cb6_001b1e70:\n"
        "movl $0, -0x1c(%ebp)\n" /* line 948 | width */
        "xorw %si, %si\n" /* height */
        "jmp .Lf1b1cb6_001b1dc6\n"
        ".Lf1b1cb6_001b1e7f:\n"
        "cmpl $0xc, -0x28(%ebp)\n" /* line 940 */
        "je .Lf1b1cb6_001b1d40\n"
        "cvtsi2ssl %edi, %xmm0\n" /* line 941 | time */
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 4(%esp)\n"
        "movl $str_002b4fc0, (%esp)\n" /* "time %g should be > 0" */
        "calll va\n"
        "movl %eax, 4(%esp)\n" /* entref */
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf1b1cb6_001b1d40\n"
        ".Lf1b1cb6_001b1ec0:\n"
        "movl %eax, 4(%esp)\n" /* line 960 | entref */
        "movl $str_002b4f88, (%esp)\n" /* "height %i < 0" */
        "calll va\n"
        "movl %eax, 4(%esp)\n" /* entref */
        "movl $4, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf1b1cb6_001b1dc6\n"
        ".Lf1b1cb6_001b1ee5:\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 945 | entref */
        "mulss lit4_002ed658, %xmm0\n" /* 0.0010000000474974513f */
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 4(%esp)\n"
        "movl $str_002b5078, (%esp)\n" /* "duration %g should be > 0" */
        "calll va\n"
        "movl %eax, 4(%esp)\n" /* entref */
        "movl $1, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf1b1cb6_001b1d79\n"
        ".Lf1b1cb6_001b1f1c:\n"
        "movl %eax, 4(%esp)\n" /* line 957 | entref */
        "movl $str_002b4f78, (%esp)\n" /* "width %i < 0" */
        "calll va\n"
        "movl %eax, 4(%esp)\n" /* entref */
        "movl $3, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf1b1cb6_001b1db0\n"
    );
}

/* line 1033 */
static __attribute__((naked))
void HECmd_SetClockUp(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1033 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl $str_002b5094, %ecx\n" /* line 1035 */
        "movl $0xc, %edx\n"
        "popl %ebp\n" /* line 1036 */
        "jmp HECmd_SetClock_Internal\n" /* line 1035 */
    );
}

/* line 1022 */
static __attribute__((naked))
void HECmd_SetClock(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1022 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl $str_002b50a0, %ecx\n" /* line 1024 */
        "movl $0xb, %edx\n"
        "popl %ebp\n" /* line 1025 */
        "jmp HECmd_SetClock_Internal\n" /* line 1024 */
    );
}

/* line 1044 */
static __attribute__((naked))
void HECmd_SetValue(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1044 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 734 */
        "subw $1, %ax\n"
        "je .Lf1b1f6e_001b200c\n"
        "movl $str_002b4dbc, (%esp)\n" /* line 740 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        ".Lf1b1f6e_001b1f95:\n"
        "movl $0, (%esp)\n" /* line 1050 */
        "calll Scr_GetFloat\n"
        "movl $0, 0x34(%ebx)\n" /* line 144 */
        "movl $0, 0x38(%ebx)\n" /* line 145 */
        "movl $0, 0x3c(%ebx)\n" /* line 146 */
        "xorl %eax, %eax\n" /* line 147 */
        "movl %eax, 0x50(%ebx)\n"
        "movl %eax, 0x54(%ebx)\n" /* line 148 */
        "movl $0, 0x58(%ebx)\n" /* line 149 */
        "movl $0, 0x5c(%ebx)\n" /* line 150 */
        "movl $0, 0x40(%ebx)\n" /* line 151 */
        "movl $0, 0x44(%ebx)\n" /* line 152 */
        "movl $0, 0x48(%ebx)\n" /* line 153 */
        "movl $0, 0x4c(%ebx)\n" /* line 154 */
        "movl $0, 0x68(%ebx)\n" /* line 155 */
        "movl $0, 0x6c(%ebx)\n" /* line 156 */
        "movl $0, 0x74(%ebx)\n" /* line 158 */
        "movl $2, (%ebx)\n" /* line 1052 | hud */
        "fstps 0x70(%ebx)\n" /* line 1053 | hud */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1054 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b1f6e_001b200c:\n"
        "movzwl %dx, %eax\n" /* line 737 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "leal g_hudelems(, %edx, 4), %ebx\n"
        "jmp .Lf1b1f6e_001b1f95\n"
    );
}

/* line 1061 */
static __attribute__((naked))
void HECmd_SetWaypoint(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1061 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 734 */
        "subw $1, %ax\n"
        "je .Lf1b2028_001b206c\n"
        "movl $str_002b4dbc, (%esp)\n" /* line 740 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        "movl $0, (%esp)\n" /* line 1067 */
        "calll Scr_GetInt\n"
        "movl $0xd, (%ebx)\n" /* line 1068 | hud */
        "cvtsi2ssl %eax, %xmm0\n" /* line 1069 */
        "movss %xmm0, 0x70(%ebx)\n" /* hud */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1070 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b2028_001b206c:\n"
        "movzwl %dx, %eax\n" /* line 737 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "leal g_hudelems(, %edx, 4), %ebx\n"
        "movl $0, (%esp)\n" /* line 1067 */
        "calll Scr_GetInt\n"
        "movl $0xd, (%ebx)\n" /* line 1068 | hud */
        "cvtsi2ssl %eax, %xmm0\n" /* line 1069 */
        "movss %xmm0, 0x70(%ebx)\n" /* hud */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1070 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1078 */
static __attribute__((naked))
void HECmd_FadeOverTime(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1078 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 734 */
        "subw $1, %ax\n"
        "je .Lf1b20a4_001b2166\n"
        "movl $str_002b4dbc, (%esp)\n" /* line 740 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        "movl $0, (%esp)\n" /* line 1085 */
        "calll Scr_GetFloat\n"
        "fstps -0xc(%ebp)\n" /* fadeTime */
        "movss -0xc(%ebp), %xmm0\n" /* line 1086 | fadeTime */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jbe .Lf1b20a4_001b219d\n"
        ".Lf1b20a4_001b20ec:\n"
        "ucomiss lit4_002ed7c8, %xmm0\n" /* line 1088 | 60.0f */
        "ja .Lf1b20a4_001b213e\n"
        ".Lf1b20a4_001b20f5:\n"
        "movl imp_level, %eax\n" /* line 1091 */
        "movl 0x1ec(%eax), %eax\n"
        "movl %eax, 0x28(%ebx)\n" /* hud */
        "movss -0xc(%ebp), %xmm0\n" /* line 428 | fadeTime */
        "mulss lit4_002ed5c8, %xmm0\n" /* 1000.0f */
        "movss %xmm0, -0xc(%ebp)\n" /* fadeTime */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x10(%ebp)\n"
        "cvttss2si -0x10(%ebp), %eax\n"
        "movl %eax, 0x2c(%ebx)\n"
        "movl 0x20(%ebx), %eax\n" /* line 1093 | hud */
        "movl %eax, 0x24(%ebx)\n" /* hud */
        /* } scope */
        "addl $0x24, %esp\n" /* line 1096 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b20a4_001b213e:\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 1089 */
        "movsd %xmm0, 4(%esp)\n"
        "movl $str_002b50c0, (%esp)\n" /* "fade time %g > 60" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf1b20a4_001b20f5\n"
        ".Lf1b20a4_001b2166:\n"
        "movzwl %dx, %eax\n" /* line 737 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "leal g_hudelems(, %edx, 4), %ebx\n"
        "movl $0, (%esp)\n" /* line 1085 */
        "calll Scr_GetFloat\n"
        "fstps -0xc(%ebp)\n" /* fadeTime */
        "movss -0xc(%ebp), %xmm0\n" /* line 1086 | fadeTime */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "ja .Lf1b20a4_001b20ec\n"
        ".Lf1b20a4_001b219d:\n"
        "jp .Lf1b20a4_001b20ec\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 1087 */
        "movsd %xmm0, 4(%esp)\n"
        "movl $str_002b50ac, (%esp)\n" /* "fade time %g <= 0" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf1b20a4_001b20f5\n"
    );
}

/* line 1104 */
static __attribute__((naked))
void HECmd_ScaleOverTime(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1104 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 734 */
        "subw $1, %ax\n"
        "je .Lf1b21ce_001b22d5\n"
        "movl $str_002b4dbc, (%esp)\n" /* line 740 */
        "calll Scr_ObjectError\n"
        "xorl %edi, %edi\n"
        ".Lf1b21ce_001b21f7:\n"
        "calll Scr_GetNumParam\n" /* line 1113 */
        "cmpl $3, %eax\n"
        "je .Lf1b21ce_001b220d\n"
        "movl $str_002b50d4, (%esp)\n" /* line 1114 */
        "calll Scr_Error\n"
        ".Lf1b21ce_001b220d:\n"
        "movl $0, (%esp)\n" /* line 1116 */
        "calll Scr_GetFloat\n"
        "fstps -0x1c(%ebp)\n" /* scaleTime */
        "movss -0x1c(%ebp), %xmm0\n" /* line 1117 | scaleTime */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jbe .Lf1b21ce_001b22f0\n"
        ".Lf1b21ce_001b222e:\n"
        "ucomiss lit4_002ed7c8, %xmm0\n" /* line 1119 | 60.0f */
        "ja .Lf1b21ce_001b22aa\n"
        ".Lf1b21ce_001b2237:\n"
        "movl $1, (%esp)\n" /* line 1122 */
        "calll Scr_GetInt\n"
        "movl %eax, %esi\n" /* width */
        "movl $2, (%esp)\n" /* line 1123 */
        "calll Scr_GetInt\n"
        "movl %eax, %ebx\n" /* height */
        "movl imp_level, %eax\n" /* line 1125 */
        "movl 0x1ec(%eax), %eax\n"
        "movl %eax, 0x48(%edi)\n" /* hud */
        "movss -0x1c(%ebp), %xmm0\n" /* line 428 | scaleTime */
        "mulss lit4_002ed5c8, %xmm0\n" /* 1000.0f */
        "movss %xmm0, -0x1c(%ebp)\n" /* scaleTime */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x20(%ebp)\n"
        "cvttss2si -0x20(%ebp), %eax\n"
        "movl %eax, 0x4c(%edi)\n"
        "movl 0x34(%edi), %eax\n" /* line 1127 | hud */
        "movl %eax, 0x40(%edi)\n" /* hud */
        "movl 0x38(%edi), %eax\n" /* line 1128 | hud */
        "movl %eax, 0x44(%edi)\n" /* hud */
        "movl %esi, 0x34(%edi)\n" /* line 1129 | width, hud */
        "movl %ebx, 0x38(%edi)\n" /* line 1130 | height, hud */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1131 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b21ce_001b22aa:\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 1120 */
        "movsd %xmm0, 4(%esp)\n"
        "movl $str_002b5128, (%esp)\n" /* "scale time %g > 60" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf1b21ce_001b2237\n"
        ".Lf1b21ce_001b22d5:\n"
        "movzwl %dx, %eax\n" /* line 737 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "leal g_hudelems(, %edx, 4), %edi\n"
        "jmp .Lf1b21ce_001b21f7\n"
        ".Lf1b21ce_001b22f0:\n"
        "jp .Lf1b21ce_001b222e\n" /* line 1117 */
        "cvtss2sd %xmm0, %xmm0\n" /* line 1118 */
        "movsd %xmm0, 4(%esp)\n"
        "movl $str_002b5114, (%esp)\n" /* "scale time %g <= 0" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf1b21ce_001b2237\n"
    );
}

/* line 1139 */
static __attribute__((naked))
void HECmd_MoveOverTime(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1139 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 734 */
        "subw $1, %ax\n"
        "je .Lf1b2322_001b23f9\n"
        "movl $str_002b4dbc, (%esp)\n" /* line 740 */
        "calll Scr_ObjectError\n"
        "xorl %ebx, %ebx\n"
        "movl $0, (%esp)\n" /* line 1146 */
        "calll Scr_GetFloat\n"
        "fstps -0xc(%ebp)\n" /* moveTime */
        "movss -0xc(%ebp), %xmm0\n" /* line 1147 | moveTime */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jbe .Lf1b2322_001b2430\n"
        ".Lf1b2322_001b236a:\n"
        "ucomiss lit4_002ed7c8, %xmm0\n" /* line 1149 | 60.0f */
        "ja .Lf1b2322_001b23ce\n"
        ".Lf1b2322_001b2373:\n"
        "movl imp_level, %eax\n" /* line 1152 */
        "movl 0x1ec(%eax), %eax\n"
        "movl %eax, 0x60(%ebx)\n" /* hud */
        "movss -0xc(%ebp), %xmm0\n" /* line 428 | moveTime */
        "mulss lit4_002ed5c8, %xmm0\n" /* 1000.0f */
        "movss %xmm0, -0xc(%ebp)\n" /* moveTime */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x10(%ebp)\n"
        "cvttss2si -0x10(%ebp), %eax\n"
        "movl %eax, 0x64(%ebx)\n"
        "movl 4(%ebx), %eax\n" /* line 1154 | hud */
        "movl %eax, 0x50(%ebx)\n" /* hud */
        "movl 8(%ebx), %eax\n" /* line 1155 | hud */
        "movl %eax, 0x54(%ebx)\n" /* hud */
        "movl 0x18(%ebx), %eax\n" /* line 1156 | hud */
        "movl %eax, 0x58(%ebx)\n" /* hud */
        "movl 0x1c(%ebx), %eax\n" /* line 1157 | hud */
        "movl %eax, 0x5c(%ebx)\n" /* hud */
        /* } scope */
        "addl $0x24, %esp\n" /* line 1158 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b2322_001b23ce:\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 1150 */
        "movsd %xmm0, 4(%esp)\n"
        "movl $str_002b5150, (%esp)\n" /* "move time %g > 60" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf1b2322_001b2373\n"
        ".Lf1b2322_001b23f9:\n"
        "movzwl %dx, %eax\n" /* line 737 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "leal g_hudelems(, %edx, 4), %ebx\n"
        "movl $0, (%esp)\n" /* line 1146 */
        "calll Scr_GetFloat\n"
        "fstps -0xc(%ebp)\n" /* moveTime */
        "movss -0xc(%ebp), %xmm0\n" /* line 1147 | moveTime */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "ja .Lf1b2322_001b236a\n"
        ".Lf1b2322_001b2430:\n"
        "jp .Lf1b2322_001b236a\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 1148 */
        "movsd %xmm0, 4(%esp)\n"
        "movl $str_002b513c, (%esp)\n" /* "move time %g <= 0" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf1b2322_001b2373\n"
    );
}

/* line 1166 */
static __attribute__((naked))
void HECmd_Reset(scr_entref_t entref)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1166 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* entref */
        "movl %eax, %edx\n" /* entref */
        /* { scope 1 */
        "shrl $0x10, %eax\n" /* line 734 */
        "subw $1, %ax\n"
        "je .Lf1b2462_001b254b\n"
        "movl $str_002b4dbc, (%esp)\n" /* line 740 */
        "calll Scr_ObjectError\n"
        "xorl %edx, %edx\n"
        ".Lf1b2462_001b2488:\n"
        "movl $1, (%edx)\n" /* line 172 */
        "xorl %eax, %eax\n" /* line 173 */
        "movl %eax, 4(%edx)\n"
        "movl %eax, 8(%edx)\n" /* line 174 */
        "movl %eax, 0xc(%edx)\n" /* line 175 */
        "movl $0x3f800000, 0x10(%edx)\n" /* line 176 */
        "movl $0, 0x14(%edx)\n" /* line 177 */
        "movl $0, 0x18(%edx)\n" /* line 178 */
        "movl $0, 0x1c(%edx)\n" /* line 179 */
        "movl $0xffffffff, 0x20(%edx)\n" /* line 180 */
        "movl $0, 0x24(%edx)\n" /* line 181 */
        "movl $0, 0x28(%edx)\n" /* line 182 */
        "movl $0, 0x2c(%edx)\n" /* line 183 */
        "movl $0, 0x30(%edx)\n" /* line 184 */
        "movl %eax, 0x78(%edx)\n" /* line 185 */
        "movl $0, 0x7c(%edx)\n" /* line 186 */
        "movl $1, 0x88(%edx)\n" /* line 188 */
        "movl $0, 0x34(%edx)\n" /* line 144 */
        "movl $0, 0x38(%edx)\n" /* line 145 */
        "movl $0, 0x3c(%edx)\n" /* line 146 */
        "movl %eax, 0x50(%edx)\n" /* line 147 */
        "movl %eax, 0x54(%edx)\n" /* line 148 */
        "movl $0, 0x58(%edx)\n" /* line 149 */
        "movl $0, 0x5c(%edx)\n" /* line 150 */
        "movl $0, 0x40(%edx)\n" /* line 151 */
        "movl $0, 0x44(%edx)\n" /* line 152 */
        "movl $0, 0x48(%edx)\n" /* line 153 */
        "movl $0, 0x4c(%edx)\n" /* line 154 */
        "movl $0, 0x68(%edx)\n" /* line 155 */
        "movl $0, 0x6c(%edx)\n" /* line 156 */
        "movl %eax, 0x70(%edx)\n" /* line 157 */
        "movl $0, 0x74(%edx)\n" /* line 158 */
        /* } scope */
        "leave\n" /* line 1172 */
        "retl\n"
        /* { scope 1 */
        ".Lf1b2462_001b254b:\n"
        "movzwl %dx, %eax\n" /* line 737 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "leal g_hudelems(, %edx, 4), %edx\n"
        "jmp .Lf1b2462_001b2488\n"
    );
}

/* line 637 */
__attribute__((naked))
void GScr_NewHudElem(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 637 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        /* { scope 2 */
        "movl g_hudelems, %eax\n" /* line 205 */
        "testl %eax, %eax\n"
        "jne .Lf1b2566_001b2689\n"
        "xorl %ebx, %ebx\n" /* i */
        "xorl %eax, %eax\n"
        ".Lf1b2566_001b257e:\n"
        "leal (%eax, %eax, 4), %edx\n" /* line 207 */
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "shll $2, %eax\n"
        "leal g_hudelems(%eax), %ecx\n"
        "movl $1, g_hudelems(%eax)\n" /* line 172 */
        "xorl %eax, %eax\n" /* line 173 */
        "movl %eax, 4(%ecx)\n"
        "movl %eax, 8(%ecx)\n" /* line 174 */
        "movl %eax, 0xc(%ecx)\n" /* line 175 */
        "movl $0x3f800000, 0x10(%ecx)\n" /* line 176 */
        "movl $0, 0x14(%ecx)\n" /* line 177 */
        "movl $0, 0x18(%ecx)\n" /* line 178 */
        "movl $0, 0x1c(%ecx)\n" /* line 179 */
        "movl $0xffffffff, 0x20(%ecx)\n" /* line 180 */
        "movl $0, 0x24(%ecx)\n" /* line 181 */
        "movl $0, 0x28(%ecx)\n" /* line 182 */
        "movl $0, 0x2c(%ecx)\n" /* line 183 */
        "movl $0, 0x30(%ecx)\n" /* line 184 */
        "movl %eax, 0x78(%ecx)\n" /* line 185 */
        "movl $0, 0x7c(%ecx)\n" /* line 186 */
        "movl $1, 0x88(%ecx)\n" /* line 188 */
        "movl $0, 0x34(%ecx)\n" /* line 144 */
        "movl $0, 0x38(%ecx)\n" /* line 145 */
        "movl $0, 0x3c(%ecx)\n" /* line 146 */
        "movl %eax, 0x50(%ecx)\n" /* line 147 */
        "movl %eax, 0x54(%ecx)\n" /* line 148 */
        "movl $0, 0x58(%ecx)\n" /* line 149 */
        "movl $0, 0x5c(%ecx)\n" /* line 150 */
        "movl $0, 0x40(%ecx)\n" /* line 151 */
        "movl $0, 0x44(%ecx)\n" /* line 152 */
        "movl $0, 0x48(%ecx)\n" /* line 153 */
        "movl $0, 0x4c(%ecx)\n" /* line 154 */
        "movl $0, 0x68(%ecx)\n" /* line 155 */
        "movl $0, 0x6c(%ecx)\n" /* line 156 */
        "movl %eax, 0x70(%ecx)\n" /* line 157 */
        "movl $0, 0x74(%ecx)\n" /* line 158 */
        "leal (%ebx, %ebx, 4), %edx\n" /* line 208 | i */
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "shll $2, %eax\n"
        "movl $0x3ff, g_hudelems+128(%eax)\n"
        "movl $0, g_hudelems+132(%eax)\n" /* line 209 */
        /* } scope */
        ".Lf1b2566_001b267b:\n"
        "movl %ecx, (%esp)\n" /* line 644 */
        "calll Scr_AddHudElem\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 645 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1b2566_001b2689:\n"
        "xorl %ebx, %ebx\n" /* line 209 | i */
        "movl $g_hudelems, %edx\n"
        ".Lf1b2566_001b2690:\n"
        "addl $1, %ebx\n" /* line 203 | i */
        "cmpl $0x400, %ebx\n" /* i */
        "je .Lf1b2566_001b26b2\n"
        "movl 0x8c(%edx), %eax\n" /* line 205 */
        "addl $0x8c, %edx\n"
        "testl %eax, %eax\n"
        "jne .Lf1b2566_001b2690\n"
        "movl %ebx, %eax\n" /* i */
        "jmp .Lf1b2566_001b257e\n"
        /* } scope */
        ".Lf1b2566_001b26b2:\n"
        "movl $str_002b5164, (%esp)\n" /* line 643 */
        "calll Scr_Error\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lf1b2566_001b267b\n"
    );
}

/* line 653 */
__attribute__((naked))
void GScr_NewClientHudElem(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 653 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 658 */
        "calll Scr_GetEntity\n"
        "movl %eax, %ebx\n" /* ent */
        "movl 0x158(%eax), %eax\n" /* line 661 */
        "testl %eax, %eax\n"
        "je .Lf1b26c2_001b282a\n"
        ".Lf1b26c2_001b26e6:\n"
        "movl (%ebx), %esi\n" /* line 664 | ent, clientNum */
        /* { scope 2 */
        /* { scope 3 */
        "movl g_hudelems, %eax\n" /* line 205 */
        "testl %eax, %eax\n"
        "jne .Lf1b26c2_001b2801\n"
        "xorl %ebx, %ebx\n" /* i */
        "xorl %eax, %eax\n"
        ".Lf1b26c2_001b26f9:\n"
        "leal (%eax, %eax, 4), %edx\n" /* line 207 */
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "shll $2, %eax\n"
        "leal g_hudelems(%eax), %ecx\n"
        "movl $1, g_hudelems(%eax)\n" /* line 172 */
        "xorl %eax, %eax\n" /* line 173 */
        "movl %eax, 4(%ecx)\n"
        "movl %eax, 8(%ecx)\n" /* line 174 */
        "movl %eax, 0xc(%ecx)\n" /* line 175 */
        "movl $0x3f800000, 0x10(%ecx)\n" /* line 176 */
        "movl $0, 0x14(%ecx)\n" /* line 177 */
        "movl $0, 0x18(%ecx)\n" /* line 178 */
        "movl $0, 0x1c(%ecx)\n" /* line 179 */
        "movl $0xffffffff, 0x20(%ecx)\n" /* line 180 */
        "movl $0, 0x24(%ecx)\n" /* line 181 */
        "movl $0, 0x28(%ecx)\n" /* line 182 */
        "movl $0, 0x2c(%ecx)\n" /* line 183 */
        "movl $0, 0x30(%ecx)\n" /* line 184 */
        "movl %eax, 0x78(%ecx)\n" /* line 185 */
        "movl $0, 0x7c(%ecx)\n" /* line 186 */
        "movl $1, 0x88(%ecx)\n" /* line 188 */
        "movl $0, 0x34(%ecx)\n" /* line 144 */
        "movl $0, 0x38(%ecx)\n" /* line 145 */
        "movl $0, 0x3c(%ecx)\n" /* line 146 */
        "movl %eax, 0x50(%ecx)\n" /* line 147 */
        "movl %eax, 0x54(%ecx)\n" /* line 148 */
        "movl $0, 0x58(%ecx)\n" /* line 149 */
        "movl $0, 0x5c(%ecx)\n" /* line 150 */
        "movl $0, 0x40(%ecx)\n" /* line 151 */
        "movl $0, 0x44(%ecx)\n" /* line 152 */
        "movl $0, 0x48(%ecx)\n" /* line 153 */
        "movl $0, 0x4c(%ecx)\n" /* line 154 */
        "movl $0, 0x68(%ecx)\n" /* line 155 */
        "movl $0, 0x6c(%ecx)\n" /* line 156 */
        "movl %eax, 0x70(%ecx)\n" /* line 157 */
        "movl $0, 0x74(%ecx)\n" /* line 158 */
        "leal (%ebx, %ebx, 4), %edx\n" /* line 208 | i */
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "shll $2, %eax\n"
        "movl %esi, g_hudelems+128(%eax)\n"
        "movl $0, g_hudelems+132(%eax)\n" /* line 209 */
        /* } scope */
        /* } scope */
        ".Lf1b26c2_001b27f2:\n"
        "movl %ecx, (%esp)\n" /* line 667 */
        "calll Scr_AddHudElem\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 668 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1b26c2_001b2801:\n"
        "xorl %ebx, %ebx\n" /* line 209 | i */
        "movl $g_hudelems, %edx\n"
        ".Lf1b26c2_001b2808:\n"
        "addl $1, %ebx\n" /* line 203 | i */
        "cmpl $0x400, %ebx\n" /* i */
        "je .Lf1b26c2_001b2843\n"
        "movl 0x8c(%edx), %eax\n" /* line 205 */
        "addl $0x8c, %edx\n"
        "testl %eax, %eax\n"
        "jne .Lf1b26c2_001b2808\n"
        "movl %ebx, %eax\n" /* i */
        "jmp .Lf1b26c2_001b26f9\n"
        /* } scope */
        /* } scope */
        ".Lf1b26c2_001b282a:\n"
        "movl $str_002b5174, 4(%esp)\n" /* line 662 */
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "jmp .Lf1b26c2_001b26e6\n"
        ".Lf1b26c2_001b2843:\n"
        "movl $str_002b5164, (%esp)\n" /* line 666 */
        "calll Scr_Error\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lf1b26c2_001b27f2\n"
    );
}

/* line 676 */
__attribute__((naked))
void GScr_NewTeamHudElem(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 676 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 682 */
        "calll Scr_GetConstString\n"
        "movl imp_scr_const, %edx\n" /* line 683 */
        "cmpw 2(%edx), %ax\n"
        "je .Lf1b2854_001b2a0e\n"
        "cmpw 4(%edx), %ax\n" /* line 687 */
        "je .Lf1b2854_001b2a18\n"
        "cmpw 0x48(%edx), %ax\n" /* line 691 */
        "je .Lf1b2854_001b29d3\n"
        "movl $0, (%esp)\n" /* line 697 */
        "calll Scr_GetString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b5184, (%esp)\n" /* "team "%s" should be "allies", "axis", or "spectator"" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_ParamError\n"
        "xorl %esi, %esi\n" /* team */
        /* { scope 2 */
        ".Lf1b2854_001b28ba:\n"
        "movl g_hudelems, %eax\n" /* line 205 */
        "testl %eax, %eax\n"
        "jne .Lf1b2854_001b29e5\n"
        ".Lf1b2854_001b28c7:\n"
        "xorl %ebx, %ebx\n" /* i */
        "xorl %eax, %eax\n"
        ".Lf1b2854_001b28cb:\n"
        "leal (%eax, %eax, 4), %edx\n" /* line 207 */
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "shll $2, %eax\n"
        "leal g_hudelems(%eax), %ecx\n"
        "movl $1, g_hudelems(%eax)\n" /* line 172 */
        "xorl %eax, %eax\n" /* line 173 */
        "movl %eax, 4(%ecx)\n"
        "movl %eax, 8(%ecx)\n" /* line 174 */
        "movl %eax, 0xc(%ecx)\n" /* line 175 */
        "movl $0x3f800000, 0x10(%ecx)\n" /* line 176 */
        "movl $0, 0x14(%ecx)\n" /* line 177 */
        "movl $0, 0x18(%ecx)\n" /* line 178 */
        "movl $0, 0x1c(%ecx)\n" /* line 179 */
        "movl $0xffffffff, 0x20(%ecx)\n" /* line 180 */
        "movl $0, 0x24(%ecx)\n" /* line 181 */
        "movl $0, 0x28(%ecx)\n" /* line 182 */
        "movl $0, 0x2c(%ecx)\n" /* line 183 */
        "movl $0, 0x30(%ecx)\n" /* line 184 */
        "movl %eax, 0x78(%ecx)\n" /* line 185 */
        "movl $0, 0x7c(%ecx)\n" /* line 186 */
        "movl $1, 0x88(%ecx)\n" /* line 188 */
        "movl $0, 0x34(%ecx)\n" /* line 144 */
        "movl $0, 0x38(%ecx)\n" /* line 145 */
        "movl $0, 0x3c(%ecx)\n" /* line 146 */
        "movl %eax, 0x50(%ecx)\n" /* line 147 */
        "movl %eax, 0x54(%ecx)\n" /* line 148 */
        "movl $0, 0x58(%ecx)\n" /* line 149 */
        "movl $0, 0x5c(%ecx)\n" /* line 150 */
        "movl $0, 0x40(%ecx)\n" /* line 151 */
        "movl $0, 0x44(%ecx)\n" /* line 152 */
        "movl $0, 0x48(%ecx)\n" /* line 153 */
        "movl $0, 0x4c(%ecx)\n" /* line 154 */
        "movl $0, 0x68(%ecx)\n" /* line 155 */
        "movl $0, 0x6c(%ecx)\n" /* line 156 */
        "movl %eax, 0x70(%ecx)\n" /* line 157 */
        "movl $0, 0x74(%ecx)\n" /* line 158 */
        "leal (%ebx, %ebx, 4), %edx\n" /* line 208 | i */
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "shll $2, %eax\n"
        "movl $0x3ff, g_hudelems+128(%eax)\n"
        "movl %esi, g_hudelems+132(%eax)\n" /* line 209 */
        /* } scope */
        ".Lf1b2854_001b29c4:\n"
        "movl %ecx, (%esp)\n" /* line 704 */
        "calll Scr_AddHudElem\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 705 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1b2854_001b29d3:\n"
        "movl $3, %esi\n" /* line 691 | team */
        /* { scope 2 */
        "movl g_hudelems, %eax\n" /* line 205 */
        "testl %eax, %eax\n"
        "je .Lf1b2854_001b28c7\n"
        ".Lf1b2854_001b29e5:\n"
        "xorl %ebx, %ebx\n" /* line 209 | i */
        "movl $g_hudelems, %edx\n"
        ".Lf1b2854_001b29ec:\n"
        "addl $1, %ebx\n" /* line 203 | i */
        "cmpl $0x400, %ebx\n" /* i */
        "je .Lf1b2854_001b2a22\n"
        "movl 0x8c(%edx), %eax\n" /* line 205 */
        "addl $0x8c, %edx\n"
        "testl %eax, %eax\n"
        "jne .Lf1b2854_001b29ec\n"
        "movl %ebx, %eax\n" /* i */
        "jmp .Lf1b2854_001b28cb\n"
        /* } scope */
        ".Lf1b2854_001b2a0e:\n"
        "movl $2, %esi\n" /* line 683 | team */
        "jmp .Lf1b2854_001b28ba\n"
        ".Lf1b2854_001b2a18:\n"
        "movl $1, %esi\n" /* line 687 | team */
        "jmp .Lf1b2854_001b28ba\n"
        ".Lf1b2854_001b2a22:\n"
        "movl $str_002b5164, (%esp)\n" /* line 703 */
        "calll Scr_Error\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lf1b2854_001b29c4\n"
    );
}

#else
static void HudElem_GetVertAlign(game_hudelem_t *hud, int offset) {
    const game_hudelem_field_t *f = &fields[offset];
    int shift = f->shift;
    int mask = f->mask;
    int value = *(int *)((byte *)hud + f->ofs);
    value = (value >> shift) & mask;
    Scr_AddString(g_he_vertalign[value]);
}
#endif
