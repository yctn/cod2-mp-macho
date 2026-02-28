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
static vec4_t color; /* 0x302d60 */
static char szErrorString[1024]; /* 0xf2f140 */
static const float pulseMags[4]; /* 0x302d70 */
static vec4_t color_00302d80; /* 0x302d80 */
static vec4_t color_00302d80; /* 0x302d80 */
static const dvar_t *hud_fadeout_speed; /* 0xf2f128 */
static const dvar_t *hud_enable; /* 0xf2f124 */
static const dvar_t *hud_healthOverlay_regenPauseTime; /* 0xf2f108 */
static const dvar_t *hud_healthOverlay_pulseStart; /* 0xf2f120 */
static const dvar_t *hud_healthOverlay_phaseOne_pulseDuration; /* 0xf2f11c */
static const dvar_t *hud_healthOverlay_phaseTwo_toAlphaMultiplier; /* 0xf2f118 */
static const dvar_t *hud_healthOverlay_phaseTwo_pulseDuration; /* 0xf2f114 */
static const dvar_t *hud_healthOverlay_phaseThree_toAlphaMultiplier; /* 0xf2f110 */
static const dvar_t *hud_healthOverlay_phaseThree_pulseDuration; /* 0xf2f10c */
static const dvar_t *hud_healthOverlay_phaseEnd_toAlpha; /* 0xf2f104 */
static const dvar_t *hud_healthOverlay_phaseEnd_pulseDuration; /* 0xf2f100 */

extern const char *va(const char *fmt, ...);

void CG_AntiBurnInHUD_RegisterDvars(void);
Bool CG_AreHudMenusHidden(void);
float CG_CalcPlayerHealth(void);
void CG_ResetLowHealthOverlay(void);
qboolean CG_ServerMaterialName(int index, char *materialName, int maxLen);
void CG_ApplySplitScreenCompassScale(float *x, float *y, float *w, float *h);
static const char * CG_GetUseString(void);
static void CG_DrawCursorhint(struct Font_s *font, float fontscale, int textStyle);
static void CG_DrawMantleHint(const rectDef_t *rect, struct Font_s *font, float fontscale, int textStyle);
const char * CG_GetTranslatedLocationString(int iLocation);
static void CG_DrawScore(float scale, vec_t *color, MaterialHandle material, int textStyle);
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
__attribute__((naked))
void CG_AntiBurnInHUD_RegisterDvars(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 59 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 61 */
        "movl $0x3f800000, %edi\n"
        "movl %edi, 0xc(%esp)\n"
        "xorl %ebx, %ebx\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3dcccccd, 4(%esp)\n"
        "movl $0x2af7dc, (%esp)\n" /* "hud_fadeout_speed" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, hud_fadeout_speed\n"
        "movl $0x1001, 8(%esp)\n" /* line 64 */
        "movl $1, 4(%esp)\n"
        "movl $0x2a9028, (%esp)\n" /* "hud_enable" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, hud_enable\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 68 */
        "movl $0x41f00000, %esi\n"
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $0x2af7f0, (%esp)\n" /* "hud_fade_ammodisplay" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, hud_fade_ammodisplay\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 69 */
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x40000000, 4(%esp)\n"
        "movl $0x2af808, (%esp)\n" /* "hud_fade_healthbar" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, hud_fade_healthbar\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 70 */
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $0x2af81c, (%esp)\n" /* "hud_fade_compass" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, hud_fade_compass\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 71 */
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3fd9999a, 4(%esp)\n"
        "movl $0x2af830, (%esp)\n" /* "hud_fade_stance" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, hud_fade_stance\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 72 */
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $0x2af840, (%esp)\n" /* "hud_fade_offhand" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, hud_fade_offhand\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 74 */
        "movl $0x3f8ccccd, %esi\n"
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x2af854, (%esp)\n" /* "hud_health_startpulse_injured" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, hud_health_startpulse_injured\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 75 */
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3ea8f5c3, 4(%esp)\n"
        "movl $0x2af874, (%esp)\n" /* "hud_health_startpulse_critical" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, hud_health_startpulse_critical\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 76 */
        "movl $0x40400000, %esi\n"
        "movl %esi, 0xc(%esp)\n"
        "movl $0x3dcccccd, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x2af894, (%esp)\n" /* "hud_health_pulserate_injured" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, hud_health_pulserate_injured\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 77 */
        "movl %esi, 0xc(%esp)\n"
        "movl $0x3dcccccd, 8(%esp)\n"
        "movl $0x3f000000, 4(%esp)\n"
        "movl $0x2af8b4, (%esp)\n" /* "hud_health_pulserate_critical" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, hud_health_pulserate_critical\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 79 */
        "movl $0x186a0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x3e8, 4(%esp)\n"
        "movl $0x2af8d4, (%esp)\n" /* "hud_deathQuoteFadeTime" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, hud_deathQuoteFadeTime\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 81 */
        "movl $0x2710, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x1388, 4(%esp)\n"
        "movl $0x2af8ec, (%esp)\n" /* "hud_healthOverlay_regenPauseTime" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, hud_healthOverlay_regenPauseTime\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 82 */
        "movl %edi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3eb33333, 4(%esp)\n"
        "movl $0x2af910, (%esp)\n" /* "hud_healthOverlay_pulseStart" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, hud_healthOverlay_pulseStart\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 83 */
        "movl $0x3e8, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x96, 4(%esp)\n"
        "movl $0x2af930, (%esp)\n" /* "hud_healthOverlay_phaseOne_pulseDuration" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, hud_healthOverlay_phaseOne_pulseDuration\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 85 */
        "movl %edi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3f333333, 4(%esp)\n"
        "movl $0x2af95c, (%esp)\n" /* "hud_healthOverlay_phaseTwo_toAlphaMultiplier" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, hud_healthOverlay_phaseTwo_toAlphaMultiplier\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 86 */
        "movl $0x3e8, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x140, 4(%esp)\n"
        "movl $0x2af98c, (%esp)\n" /* "hud_healthOverlay_phaseTwo_pulseDuration" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, hud_healthOverlay_phaseTwo_pulseDuration\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 88 */
        "movl %edi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3f19999a, 4(%esp)\n"
        "movl $0x2af9b8, (%esp)\n" /* "hud_healthOverlay_phaseThree_toAlphaMultiplier" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, hud_healthOverlay_phaseThree_toAlphaMultiplier\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 89 */
        "movl $0x3e8, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x190, 4(%esp)\n"
        "movl $0x2af9e8, (%esp)\n" /* "hud_healthOverlay_phaseThree_pulseDuration" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, hud_healthOverlay_phaseThree_pulseDuration\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 91 */
        "movl %edi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $0x2afa14, (%esp)\n" /* "hud_healthOverlay_phaseEnd_toAlpha" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, hud_healthOverlay_phaseEnd_toAlpha\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 92 */
        "movl $0x3e8, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x2bc, 4(%esp)\n"
        "movl $0x2afa38, (%esp)\n" /* "hud_healthOverlay_phaseEnd_pulseDuration" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, hud_healthOverlay_phaseEnd_pulseDuration\n"
        "addl $0x2c, %esp\n" /* line 93 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 99 */
__attribute__((naked))
Bool CG_AreHudMenusHidden(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 99 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "calll CL_GetKeyCatchers\n" /* line 101 */
        "testb $8, %al\n"
        "jne .Lf188414_0018843f\n"
        ".Lf188414_00188423:\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x2bdc8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf188414_0018843b\n"
        "movl $1, %eax\n"
        ".Lf188414_00188439:\n"
        "leave\n" /* line 102 */
        "retl\n"
        ".Lf188414_0018843b:\n"
        "xorl %eax, %eax\n" /* line 101 */
        "leave\n" /* line 102 */
        "retl\n"
        ".Lf188414_0018843f:\n"
        "calll CL_GetDisplayHUDWithKeycatchUI\n" /* line 101 */
        "testb %al, %al\n"
        "jne .Lf188414_00188423\n"
        "movl $1, %eax\n"
        "jmp .Lf188414_00188439\n"
    );
}

/* line 741 */
__attribute__((naked))
float CG_CalcPlayerHealth(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 741 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        /* { scope 1 */
        "movl 0x195f584, %eax\n" /* line 743 | ps */
        "movl (%eax), %eax\n" /* ps */
        "movl 0x24(%eax), %eax\n" /* ps */
        "addl $0xc, %eax\n" /* ps */
        "movl 0x12c(%eax), %edx\n" /* line 746 */
        "testl %edx, %edx\n"
        "je .Lf188450_001884ae\n"
        "movl 0x134(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf188450_001884ae\n"
        "cmpl $6, 4(%eax)\n"
        "je .Lf188450_001884ae\n"
        "cvtsi2ssl %edx, %xmm1\n" /* line 748 */
        "cvtsi2ssl %ecx, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "ucomiss 0x2ed5e8, %xmm1\n" /* line 749 | 0.0f */
        "jb .Lf188450_001884ac\n"
        ".Lf188450_00188492:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 751 | 1.0f */
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf188450_001884b2\n"
        "movaps %xmm0, %xmm1\n"
        /* } scope */
        "movss %xmm1, -4(%ebp)\n" /* line 757 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
        /* { scope 1 */
        ".Lf188450_001884ac:\n"
        "jp .Lf188450_00188492\n" /* line 749 */
        ".Lf188450_001884ae:\n"
        "pxor %xmm1, %xmm1\n" /* line 751 */
        /* } scope */
        ".Lf188450_001884b2:\n"
        "movss %xmm1, -4(%ebp)\n" /* line 757 */
        "flds -4(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 1002 */
void CG_ResetLowHealthOverlay(void)
{
    byte *cg = *(byte **)(*(int *)0x195f584);
    *(byte *)(cg + 0x2be20) = 0;
    *(float *)(cg + 0x2be10) = *(float *)((byte *)hud_healthOverlay_phaseEnd_toAlpha + 8);
    *(int *)(cg + 0x2be18) = 0;
    *(int *)(cg + 0x2be1c) = 0;
    *(int *)(cg + 0x2be2c) = 0;
    *(float *)(cg + 0x2be28) = 1.0f;
}

/* line 1036 */
__attribute__((naked))
qboolean CG_ServerMaterialName(int index, char *materialName, int maxLen)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1036 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* index */
        /* { scope 1 */
        "leal -1(%edx), %eax\n" /* line 1040 */
        "cmpl $0x7e, %eax\n"
        "jbe .Lf188506_00188520\n"
        ".Lf188506_00188518:\n"
        "xorl %eax, %eax\n" /* line 1048 */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1049 */
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf188506_00188520:\n"
        "leal 0x61e(%edx), %eax\n" /* line 1042 */
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl %eax, %edx\n"
        "cmpb $0, (%eax)\n" /* line 1043 */
        "je .Lf188506_00188518\n"
        "cld\n" /* line 1045 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %edx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "cmpl 0x10(%ebp), %ecx\n" /* maxLen */
        "jae .Lf188506_00188518\n"
        "movl %edx, 4(%esp)\n" /* line 1047 */
        "movl 0xc(%ebp), %eax\n" /* materialName */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 1049 */
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1079 */
void CG_ApplySplitScreenCompassScale(float *x, float *y, float *w, float *h)
{
}

/* line 1373 */
static __attribute__((naked))
const char * CG_GetUseString(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1373 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x110, %esp\n"
        /* { scope 1 */
        "movl 0x195f584, %eax\n" /* line 1380 */
        "movl (%eax), %eax\n"
        "movl 0x2bdf4(%eax), %eax\n"
        "addl $0x4fe, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 1382 */
        "jne .Lf18856c_001885a3\n"
        ".Lf18856c_00188597:\n"
        "xorl %eax, %eax\n" /* line 1392 */
        /* } scope */
        "addl $0x110, %esp\n" /* line 1393 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf18856c_001885a3:\n"
        "cmpb $0, (%eax)\n" /* line 1382 */
        "je .Lf18856c_00188597\n"
        "leal -0x108(%ebp), %esi\n" /* line 1385 | binding */
        "movl %esi, 4(%esp)\n"
        "movl $0x2ac020, (%esp)\n" /* "+activate" */
        "calll GetKeyBindingLocalizedString\n"
        "testl %eax, %eax\n"
        "je .Lf18856c_001885f0\n"
        ".Lf18856c_001885c2:\n"
        "movl $0, 8(%esp)\n" /* line 1388 */
        "movl $0x2afa6c, 4(%esp)\n" /* "Hint String" */
        "movl %ebx, (%esp)\n"
        "calll SEH_LocalizeTextMessage\n"
        "movl %esi, 4(%esp)\n" /* line 1390 */
        "movl %eax, (%esp)\n"
        "calll UI_ReplaceConversionString\n"
        /* } scope */
        "addl $0x110, %esp\n" /* line 1393 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf18856c_001885f0:\n"
        "movl $0x2afa64, (%esp)\n" /* line 1386 */
        "calll UI_SafeTranslateString\n"
        "movl $0x100, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll I_strncpyz\n"
        "jmp .Lf18856c_001885c2\n"
    );
}

/* line 1408 */
static __attribute__((naked))
void CG_DrawCursorhint(struct Font_s *font, float fontscale, int textStyle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1408 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x29c, %esp\n"
        "movl %eax, %esi\n" /* rect */
        "movl %edx, -0x23c(%ebp)\n"
        "movss %xmm0, -0x240(%ebp)\n"
        "movl %ecx, -0x244(%ebp)\n"
        /* { scope 1 */
        "movl 0x195f658, %eax\n" /* line 1426 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf188612_001887e2\n"
        "movl 0x195f584, %ebx\n" /* line 1308 */
        "movl (%ebx), %edx\n"
        "movl 0x25bc0(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf188612_001887ed\n"
        "movl %edx, %ebx\n"
        ".Lf188612_0018865e:\n"
        "movl 0x195f5c4, %eax\n" /* line 1431 */
        "movl (%eax), %edx\n"
        "movl 0x2bde8(%ebx), %eax\n"
        "movl 0xba44(%edx, %eax, 4), %eax\n"
        "movl %eax, -0x234(%ebp)\n" /* hintIcon */
        "testl %eax, %eax\n" /* line 1432 */
        "je .Lf188612_001887e2\n"
        "movl $0x64, 8(%esp)\n" /* line 1436 */
        "movl 0x2bdf0(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x2bdec(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_FadeColor\n"
        "movl %eax, -0x238(%ebp)\n" /* color */
        "testl %eax, %eax\n" /* line 1437 */
        "je .Lf188612_00188996\n"
        "calll Controls_GetConfig\n" /* line 1443 */
        "movl 0x195f658, %edi\n" /* line 1450 */
        "movl (%edi), %eax\n"
        "cmpl $3, 8(%eax)\n"
        "je .Lf188612_00188bd6\n"
        ".Lf188612_001886c5:\n"
        "cmpl $2, 8(%eax)\n" /* line 1454 */
        "jle .Lf188612_00188805\n"
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0x22c(%ebp)\n" /* halfscale */
        "movss %xmm0, -0x230(%ebp)\n" /* scale */
        "movl 0x195f584, %eax\n" /* line 1468 */
        "movl (%eax), %ecx\n"
        "movl 0x2bde8(%ecx), %edx\n"
        "leal -5(%edx), %eax\n"
        "cmpl $0x7f, %eax\n"
        "jbe .Lf188612_00188877\n"
        ".Lf188612_001886fc:\n"
        "movl 0x2bdf4(%ecx), %ecx\n" /* line 1490 */
        "testl %ecx, %ecx\n"
        "js .Lf188612_001889ab\n"
        "calll CG_GetUseString\n" /* line 1492 */
        ".Lf188612_0018870f:\n"
        "movl %eax, %ebx\n" /* line 1499 */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x228(%ebp)\n" /* widthScale */
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0x224(%ebp)\n" /* widthOfs */
        ".Lf188612_0018872d:\n"
        "testl %ebx, %ebx\n" /* line 1502 */
        "je .Lf188612_0018873a\n"
        "cmpb $0, (%ebx)\n"
        "jne .Lf188612_00188a22\n"
        ".Lf188612_0018873a:\n"
        "movss 8(%esi), %xmm1\n" /* line 1515 | rect */
        "movl -0x234(%ebp), %eax\n" /* line 1517 | hintIcon */
        "movl %eax, 0x1c(%esp)\n"
        "movl -0x238(%ebp), %edx\n" /* color */
        "movl %edx, 0x18(%esp)\n"
        "movl 0x14(%esi), %eax\n" /* rect */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%esi), %eax\n" /* rect */
        "movl %eax, 0x10(%esp)\n"
        "movss -0x230(%ebp), %xmm0\n" /* scale */
        "addss 0xc(%esi), %xmm0\n" /* rect */
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x228(%ebp), %xmm0\n" /* widthScale */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x228(%ebp)\n" /* widthScale */
        "movss -0x230(%ebp), %xmm0\n" /* scale */
        "addss -0x228(%ebp), %xmm0\n" /* widthScale */
        "movss %xmm0, 8(%esp)\n"
        "movss 4(%esi), %xmm0\n" /* rect */
        "subss -0x22c(%ebp), %xmm0\n" /* halfscale */
        "movss %xmm0, 4(%esp)\n"
        "addss -0x22c(%ebp), %xmm1\n" /* halfscale */
        "movaps %xmm1, %xmm0\n"
        "addss -0x224(%ebp), %xmm0\n" /* widthOfs */
        "mulss 0x2ed63c, %xmm0\n" /* -0.5f */
        "movss %xmm0, -0x22c(%ebp)\n" /* halfscale */
        "addss (%esi), %xmm0\n" /* rect */
        "movss %xmm0, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        /* } scope */
        ".Lf188612_001887e2:\n"
        "addl $0x29c, %esp\n" /* line 1519 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf188612_001887ed:\n"
        "movl 0x24(%edx), %ecx\n" /* line 1311 */
        "movl 0x5a4(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf188612_0018895b\n"
        "movl (%ebx), %ebx\n"
        "jmp .Lf188612_0018865e\n"
        ".Lf188612_00188805:\n"
        "jne .Lf188612_001889d5\n" /* line 1460 */
        "movl 0x2bdec(%ebx), %ebx\n" /* line 1461 */
        "movl $0x10624dd3, %edx\n"
        "movl %ebx, %eax\n"
        "imull %edx\n"
        "sarl $6, %edx\n"
        "movl %ebx, %ecx\n"
        "sarl $0x1f, %ecx\n"
        "subl %ecx, %edx\n"
        "leal (%edx, %edx, 4), %edx\n"
        "leal (%edx, %edx, 4), %edx\n"
        "leal (%edx, %edx, 4), %edx\n"
        "shll $3, %edx\n"
        "subl %edx, %ebx\n"
        "cvtsi2ssl %ebx, %xmm0\n"
        "divss 0x2ed798, %xmm0\n" /* 100.0f */
        "movss %xmm0, -0x230(%ebp)\n" /* scale */
        "movss 0x2ed5d8, %xmm1\n" /* 0.5f */
        ".Lf188612_0018884e:\n"
        "mulss -0x230(%ebp), %xmm1\n" /* line 1465 | scale */
        "movss %xmm1, -0x22c(%ebp)\n" /* halfscale */
        "movl 0x195f584, %eax\n" /* line 1468 */
        "movl (%eax), %ecx\n"
        "movl 0x2bde8(%ecx), %edx\n"
        "leal -5(%edx), %eax\n"
        "cmpl $0x7f, %eax\n"
        "ja .Lf188612_001886fc\n"
        ".Lf188612_00188877:\n"
        "leal -4(%edx), %eax\n" /* line 1471 */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl 0x344(%eax), %edi\n" /* line 1474 */
        "testl %edi, %edi\n"
        "jne .Lf188612_00188bac\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x228(%ebp)\n" /* widthScale */
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0x224(%ebp)\n" /* widthOfs */
        ".Lf188612_001888ac:\n"
        "cmpl $7, 0x7c(%eax)\n" /* line 1480 */
        "je .Lf188612_00188c4a\n"
        "movl 0x195f584, %eax\n" /* line 1336 */
        "movl (%eax), %edi\n"
        "movl 0x2bde8(%edi), %ebx\n"
        "subl $4, %ebx\n"
        "movl %ebx, (%esp)\n" /* line 1337 */
        "calll BG_GetWeaponDef\n"
        "movl %eax, -0x21c(%ebp)\n"
        "leal -0x218(%ebp), %eax\n" /* line 1340 */
        "movl %eax, 4(%esp)\n"
        "movl $0x2ac020, (%esp)\n" /* "+activate" */
        "calll GetKeyBindingLocalizedString\n"
        "movl %ebx, (%esp)\n" /* line 1344 */
        "calll BG_DoesWeaponNeedSlot\n"
        "testb %al, %al\n"
        "je .Lf188612_00188c25\n"
        "movl %ebx, 4(%esp)\n"
        "leal 0x25bc4(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetEmptySlotForWeapon\n"
        "testl %eax, %eax\n"
        "jne .Lf188612_00188c25\n"
        "movl 0x25c98(%edi), %eax\n" /* line 1346 */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl -0x21c(%ebp), %ecx\n"
        "movl 0x80(%ecx), %edx\n"
        "cmpl %edx, 0x80(%eax)\n"
        "je .Lf188612_00188c9e\n"
        "movsbl 0x26118(%edx, %edi), %eax\n" /* line 1353 */
        "cmpl %eax, %ebx\n"
        "je .Lf188612_0018873a\n"
        ".Lf188612_0018894a:\n"
        "movl $0x2afa94, (%esp)\n" /* line 1357 */
        "calll UI_SafeTranslateString\n"
        "jmp .Lf188612_00188c31\n"
        ".Lf188612_0018895b:\n"
        "movl 0x25bb0(%edx), %eax\n" /* line 1313 */
        "movl %eax, 0x2bdec(%edx)\n"
        "movl 0x195f668, %eax\n" /* line 1314 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 0x2bdf0(%edx)\n"
        "movl 0x5a4(%ecx), %eax\n" /* line 1315 */
        "movl %eax, 0x2bde8(%edx)\n"
        "movl 0x5a8(%ecx), %eax\n" /* line 1316 */
        "movl %eax, 0x2bdf4(%edx)\n"
        "movl (%ebx), %ebx\n"
        "jmp .Lf188612_0018865e\n"
        ".Lf188612_00188996:\n"
        "movl $0, 0x2bde8(%ebx)\n" /* line 1439 */
        /* } scope */
        "addl $0x29c, %esp\n" /* line 1519 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf188612_001889ab:\n"
        "cmpl $3, %edx\n" /* line 1494 */
        "je .Lf188612_00188c6b\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 1502 | 1.0f */
        "movss %xmm0, -0x228(%ebp)\n" /* widthScale */
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0x224(%ebp)\n" /* widthOfs */
        "jmp .Lf188612_0018873a\n"
        ".Lf188612_001889d5:\n"
        "cvtsi2ssl 0x25bb0(%ebx), %xmm0\n" /* line 1463 */
        "divss 0x2ed93c, %xmm0\n" /* 150.0f */
        "movss %xmm0, (%esp)\n"
        "calll sinf\n"
        "fstps -0x230(%ebp)\n" /* scale */
        "movss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "movss -0x230(%ebp), %xmm0\n" /* scale */
        "mulss %xmm1, %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "mulss 0x2ed6b4, %xmm0\n" /* 10.0f */
        "movss %xmm0, -0x230(%ebp)\n" /* scale */
        "jmp .Lf188612_0018884e\n"
        ".Lf188612_00188a22:\n"
        "movss -0x240(%ebp), %xmm0\n" /* line 1504 */
        "movss %xmm0, 0xc(%esp)\n"
        "movl -0x23c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll UI_TextWidth\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x220(%ebp)\n" /* length */
        "movss -0x240(%ebp), %xmm0\n" /* line 1505 */
        "movss %xmm0, 4(%esp)\n"
        "movl -0x23c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_TextHeight\n"
        "movss -0x228(%ebp), %xmm2\n" /* line 1507 | widthScale */
        "mulss 8(%esi), %xmm2\n" /* rect */
        "addss -0x230(%ebp), %xmm2\n" /* scale */
        "addss -0x220(%ebp), %xmm2\n" /* length */
        "movss 0x2ed63c, %xmm1\n" /* -0.5f */
        "mulss %xmm1, %xmm2\n"
        "movss 4(%esi), %xmm3\n" /* line 1508 | rect */
        "mulss 0xc(%esi), %xmm1\n" /* rect */
        "addss %xmm3, %xmm1\n"
        "movl -0x244(%ebp), %edx\n" /* line 1510 */
        "movl %edx, 0x24(%esp)\n"
        "movl -0x238(%ebp), %ecx\n" /* color */
        "movl %ecx, 0x20(%esp)\n"
        "movss -0x240(%ebp), %xmm0\n"
        "movss %xmm0, 0x1c(%esp)\n"
        "movl 0x14(%esi), %edx\n" /* rect */
        "movl %edx, 0x18(%esp)\n"
        "movl 0x10(%esi), %edx\n" /* rect */
        "movl %edx, 0x14(%esp)\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "addss %xmm0, %xmm3\n"
        "movss %xmm3, 0x10(%esp)\n"
        "movss %xmm2, 0xc(%esp)\n"
        "movl -0x23c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "movss %xmm1, -0x258(%ebp)\n"
        "movss %xmm2, -0x268(%ebp)\n"
        "calll UI_DrawText\n"
        "movl -0x234(%ebp), %edx\n" /* line 1511 | hintIcon */
        "movl %edx, 0x1c(%esp)\n"
        "movl -0x238(%ebp), %ecx\n" /* color */
        "movl %ecx, 0x18(%esp)\n"
        "movl 0x14(%esi), %eax\n" /* rect */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%esi), %eax\n" /* rect */
        "movl %eax, 0x10(%esp)\n"
        "movss -0x230(%ebp), %xmm0\n" /* scale */
        "addss 0xc(%esi), %xmm0\n" /* rect */
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x228(%ebp), %xmm0\n" /* widthScale */
        "mulss 8(%esi), %xmm0\n" /* rect */
        "movss %xmm0, -0x228(%ebp)\n" /* widthScale */
        "movss -0x230(%ebp), %xmm0\n" /* scale */
        "addss -0x228(%ebp), %xmm0\n" /* widthScale */
        "movss %xmm0, 8(%esp)\n"
        "movss -0x258(%ebp), %xmm1\n"
        "movss %xmm1, 4(%esp)\n"
        "movss -0x268(%ebp), %xmm2\n"
        "addss -0x220(%ebp), %xmm2\n" /* length */
        "movss %xmm2, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        "jmp .Lf188612_001887e2\n"
        ".Lf188612_00188bac:\n"
        "movss 0x2ed63c, %xmm0\n" /* line 1477 | -0.5f */
        "mulss 8(%esi), %xmm0\n" /* rect */
        "movss %xmm0, -0x224(%ebp)\n" /* widthOfs */
        "movss 0x2ed62c, %xmm0\n" /* 2.0f */
        "movss %xmm0, -0x228(%ebp)\n" /* widthScale */
        "jmp .Lf188612_001888ac\n"
        ".Lf188612_00188bd6:\n"
        "cvtsi2ssl 0x25bb0(%ebx), %xmm0\n" /* line 1451 */
        "divss 0x2ed93c, %xmm0\n" /* 150.0f */
        "movss %xmm0, (%esp)\n"
        "calll sinf\n"
        "fstps -0x26c(%ebp)\n"
        "movss -0x26c(%ebp), %xmm0\n"
        "movss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "mulss %xmm1, %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "movl -0x238(%ebp), %eax\n" /* color */
        "mulss 0xc(%eax), %xmm0\n"
        "movss %xmm0, 0xc(%eax)\n"
        "movl (%edi), %eax\n"
        "jmp .Lf188612_001886c5\n"
        ".Lf188612_00188c25:\n"
        "movl $0x2afa78, (%esp)\n" /* line 1361 */
        "calll UI_SafeTranslateString\n"
        ".Lf188612_00188c31:\n"
        "leal -0x218(%ebp), %edx\n" /* line 1364 */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll UI_ReplaceConversionString\n"
        "movl %eax, %ebx\n"
        "jmp .Lf188612_0018872d\n"
        ".Lf188612_00188c4a:\n"
        "movl 0x195f584, %eax\n" /* line 1482 */
        "movl (%eax), %eax\n"
        "movl 0x2bdf4(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "js .Lf188612_0018873a\n"
        "calll CG_GetUseString\n" /* line 1483 */
        "movl %eax, %ebx\n"
        "jmp .Lf188612_0018872d\n"
        ".Lf188612_00188c6b:\n"
        "leal -0x118(%ebp), %ebx\n" /* line 1496 | binding */
        "movl %ebx, 4(%esp)\n"
        "movl $0x2ac020, (%esp)\n" /* "+activate" */
        "calll GetKeyBindingLocalizedString\n"
        "movl $0x2afaac, (%esp)\n" /* line 1498 */
        "calll UI_SafeTranslateString\n"
        "movl %ebx, 4(%esp)\n" /* line 1499 */
        "movl %eax, (%esp)\n"
        "calll UI_ReplaceConversionString\n"
        "jmp .Lf188612_0018870f\n"
        ".Lf188612_00188c9e:\n"
        "cmpl 0x25c98(%edi), %ebx\n" /* line 1348 */
        "jne .Lf188612_0018894a\n"
        "jmp .Lf188612_0018873a\n"
    );
}

/* line 1570 */
static __attribute__((naked))
void CG_DrawMantleHint(const rectDef_t *rect, struct Font_s *font, float fontscale, int textStyle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1570 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x150, %esp\n"
        "movl 8(%ebp), %esi\n" /* rect */
        /* { scope 1 */
        "movl 0x195f64c, %eax\n" /* line 1583 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf188cb0_00188cdb\n"
        "movl 0x195f584, %eax\n" /* line 1588 */
        "movl (%eax), %eax\n"
        "testb $8, 0x2618c(%eax)\n"
        "jne .Lf188cb0_00188ce5\n"
        /* } scope */
        ".Lf188cb0_00188cdb:\n"
        "addl $0x150, %esp\n" /* line 1609 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf188cb0_00188ce5:\n"
        "calll Controls_GetConfig\n" /* line 1591 */
        "leal -0x108(%ebp), %ebx\n" /* line 1593 | binding */
        "movl %ebx, 4(%esp)\n"
        "movl $0x2ac148, (%esp)\n" /* "+gostand" */
        "calll GetKeyBindingLocalizedString\n"
        "testl %eax, %eax\n"
        "je .Lf188cb0_00188e53\n"
        ".Lf188cb0_00188d08:\n"
        "movl $0x2afac4, (%esp)\n" /* line 1596 */
        "calll UI_SafeTranslateString\n"
        "movl %ebx, 4(%esp)\n" /* line 1597 */
        "movl %eax, (%esp)\n"
        "calll UI_ReplaceConversionString\n"
        "movl %eax, %ebx\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 1599 | fontscale */
        "movss %xmm0, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll UI_TextWidth\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x10c(%ebp)\n" /* length */
        "movss 0x10(%ebp), %xmm0\n" /* line 1600 | fontscale */
        "movss %xmm0, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* font */
        "movl %eax, (%esp)\n"
        "calll UI_TextHeight\n"
        "movss -0x10c(%ebp), %xmm1\n" /* line 1602 | length */
        "addss 8(%esi), %xmm1\n" /* rect */
        "mulss 0x2ed63c, %xmm1\n" /* -0.5f */
        "addss (%esi), %xmm1\n" /* rect */
        "movl 0x14(%ebp), %edx\n" /* line 1604 | textStyle */
        "movl %edx, 0x24(%esp)\n"
        "movl $color, 0x20(%esp)\n"
        "movss 0x10(%ebp), %xmm0\n" /* fontscale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl 0x14(%esi), %edx\n" /* rect */
        "movl %edx, 0x18(%esp)\n"
        "movl 0x10(%esi), %edx\n" /* rect */
        "movl %edx, 0x14(%esp)\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "addss 4(%esi), %xmm0\n" /* rect */
        "movss %xmm0, 0x10(%esp)\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "movss %xmm1, -0x128(%ebp)\n"
        "calll UI_DrawText\n"
        "movss 0xc(%esi), %xmm0\n" /* line 1607 | rect */
        "movl 0x195f5c4, %eax\n" /* line 1608 */
        "movl (%eax), %eax\n"
        "movl 0xbc78(%eax), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl $color, 0x18(%esp)\n"
        "movl 0x14(%esi), %eax\n" /* rect */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%esi), %eax\n" /* rect */
        "movl %eax, 0x10(%esp)\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl 8(%esi), %eax\n" /* rect */
        "movl %eax, 8(%esp)\n"
        "mulss 0x2ed63c, %xmm0\n" /* -0.5f */
        "addss 4(%esi), %xmm0\n" /* rect */
        "movss %xmm0, 4(%esp)\n"
        "movss -0x128(%ebp), %xmm1\n"
        "addss -0x10c(%ebp), %xmm1\n" /* length */
        "movss %xmm1, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        /* } scope */
        "addl $0x150, %esp\n" /* line 1609 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf188cb0_00188e53:\n"
        "movl %ebx, 4(%esp)\n" /* line 1594 */
        "movl $0x2abf84, (%esp)\n" /* "+moveup" */
        "calll GetKeyBindingLocalizedString\n"
        "jmp .Lf188cb0_00188d08\n"
    );
}

/* line 1615 */
__attribute__((naked))
const char * CG_GetTranslatedLocationString(int iLocation)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1615 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1621 | iLocation */
        "addl $0x2e, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl %eax, %ebx\n" /* p */
        "testl %eax, %eax\n" /* line 1622 */
        "je .Lf188e68_00188e9a\n"
        "cmpb $0, (%eax)\n"
        "je .Lf188e68_00188e9a\n"
        "movl %ebx, (%esp)\n" /* line 1625 | p */
        "calll SEH_StringEd_GetString\n"
        "testl %eax, %eax\n" /* line 1626 */
        "je .Lf188e68_00188eab\n"
        /* } scope */
        ".Lf188e68_00188e94:\n"
        "addl $0x14, %esp\n" /* line 1646 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf188e68_00188e9a:\n"
        "movl $0x2afad4, %ebx\n" /* line 1622 | p */
        "movl %ebx, (%esp)\n" /* line 1625 | p */
        "calll SEH_StringEd_GetString\n"
        "testl %eax, %eax\n" /* line 1626 */
        "jne .Lf188e68_00188e94\n"
        ".Lf188e68_00188eab:\n"
        "movl 0x195f574, %eax\n" /* line 1628 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf188e68_00188f65\n"
        "movl 0x195f570, %eax\n" /* line 1630 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf188e68_00188f53\n"
        "movl %ebx, 8(%esp)\n" /* line 1631 | p */
        "movl $0x2afae4, 4(%esp)\n" /* "Could not translate map location string "%s"" */
        "movl $6, (%esp)\n"
        "calll Com_Error\n"
        ".Lf188e68_00188ee5:\n"
        "movl $0x4e55315e, szErrorString\n" /* line 1635 */
        "movl $0x41434f4c, 0xf2f144\n"
        "movl $0x455a494c, 0xf2f148\n"
        "movl $0x375e2844, 0xf2f14c\n"
        "movb $0, 0xf2f150\n"
        "movl %ebx, 8(%esp)\n" /* line 1636 | p */
        "movl $0x400, 4(%esp)\n"
        "movl $szErrorString, (%esp)\n"
        "calll I_strncat\n"
        "movl $0x216b78, 8(%esp)\n" /* line 1637 */
        "movl $0x400, 4(%esp)\n"
        "movl $szErrorString, (%esp)\n"
        "calll I_strncat\n"
        "movl $szErrorString, %eax\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 1646 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf188e68_00188f53:\n"
        "movl %ebx, 4(%esp)\n" /* line 1633 | p */
        "movl $0x2afb14, (%esp)\n" /* "^3WARNING: Could not translate map location string "%s"
" */
        "calll Com_Printf\n"
        "jmp .Lf188e68_00188ee5\n"
        ".Lf188e68_00188f65:\n"
        "movl $0x400, 8(%esp)\n" /* line 1640 */
        "movl %ebx, 4(%esp)\n" /* p */
        "movl $szErrorString, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $szErrorString, %eax\n"
        "jmp .Lf188e68_00188e94\n"
    );
}

/* line 1665 */
static __attribute__((naked))
void CG_DrawScore(float scale, vec_t *color, MaterialHandle material, int textStyle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1665 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %edx, %ebx\n" /* textStyle, rect */
        "movl %ecx, %esi\n" /* font */
        "movss %xmm0, -0x2c(%ebp)\n"
        /* { scope 1 */
        "movl 0x195f5c4, %edx\n" /* line 1670 */
        "movl (%edx), %edx\n"
        "movl 0x63b8(%edx, %eax, 4), %eax\n"
        "cmpl $0xffffd8f1, %eax\n"
        "je .Lf188f88_0018905c\n"
        "movl %eax, 0xc(%esp)\n" /* line 1676 */
        "movl $0x21785c, 8(%esp)\n" /* "%i" */
        "movl $0x10, 4(%esp)\n"
        "leal -0x28(%ebp), %edi\n" /* num */
        "movl %edi, (%esp)\n"
        "calll Com_sprintf\n"
        ".Lf188f88_00188fd3:\n"
        "movss -0x2c(%ebp), %xmm0\n" /* line 1678 */
        "movss %xmm0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* font */
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll UI_TextWidth\n"
        "movl 0x10(%ebp), %edx\n" /* line 1679 | textStyle */
        "movl %edx, 0x24(%esp)\n"
        "movl 8(%ebp), %edx\n" /* color */
        "movl %edx, 0x20(%esp)\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, 0x1c(%esp)\n"
        "movl 0x14(%ebx), %edx\n" /* rect */
        "movl %edx, 0x18(%esp)\n"
        "movl 0x10(%ebx), %edx\n" /* rect */
        "movl %edx, 0x14(%esp)\n"
        "movss 4(%ebx), %xmm0\n" /* rect */
        "addss 0xc(%ebx), %xmm0\n" /* rect */
        "movss %xmm0, 0x10(%esp)\n"
        "movss (%ebx), %xmm0\n" /* rect */
        "addss 8(%ebx), %xmm0\n" /* rect */
        "cvtsi2ssl %eax, %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* font */
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll UI_DrawText\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 1680 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf188f88_0018905c:\n"
        "movl $0x222900, 8(%esp)\n" /* line 1672 */
        "movl $0x10, 4(%esp)\n"
        "leal -0x28(%ebp), %edi\n" /* num */
        "movl %edi, (%esp)\n"
        "calll Com_sprintf\n"
        "jmp .Lf188f88_00188fd3\n"
    );
}

/* line 1722 */
const char * CG_GetKillerText(void)
{
    byte *cg = *(byte **)(*(int *)0x195f584);
    if (!*(byte *)(cg + 0x2b54c))
        return "";
    return va("Fragged by %s", (const char *)(cg + 0x2b54c));
}

/* line 1768 */
const char * CG_GameTypeString(void)
{
    return (const char *)((byte *)*(void **)*(void **)0x195f5c4 + 0x5ea4);
}

/* line 1926 */
__attribute__((naked))
int CG_KeyInterceptEvent(int key, qboolean down)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1926 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* line 1928 | down */
        "testl %eax, %eax\n"
        "jne .Lf1890c4_001890d5\n"
        ".Lf1890c4_001890d1:\n"
        "xorl %eax, %eax\n" /* line 1941 */
        "leave\n" /* line 1946 */
        "retl\n"
        ".Lf1890c4_001890d5:\n"
        "calll CG_ScoreboardDisplayed\n" /* line 1931 */
        "testl %eax, %eax\n"
        "je .Lf1890c4_001890d1\n"
        "cmpl $0xce, 8(%ebp)\n" /* line 1933 | key */
        "je .Lf1890c4_0018910e\n"
        "cmpl $0xa4, 8(%ebp)\n" /* key */
        "je .Lf1890c4_0018910e\n"
        "cmpl $0xcd, 8(%ebp)\n" /* line 1938 | key */
        "je .Lf1890c4_00189102\n"
        "cmpl $0xa3, 8(%ebp)\n" /* key */
        "jne .Lf1890c4_001890d1\n"
        ".Lf1890c4_00189102:\n"
        "calll CG_ScrollScoreboardDown\n" /* line 1940 */
        "movl $1, %eax\n"
        "leave\n" /* line 1946 */
        "retl\n"
        ".Lf1890c4_0018910e:\n"
        "calll CG_ScrollScoreboardUp\n" /* line 1935 */
        "movl $1, %eax\n"
        "leave\n" /* line 1946 */
        "retl\n"
    );
}

/* line 938 */
static __attribute__((naked))
void CG_PulseLowHealthOverlay(float healthRatio)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 938 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movss 8(%ebp), %xmm1\n" /* healthRatio */
        /* { scope 1 */
        "movl 0x195f584, %ecx\n" /* line 942 */
        "movl (%ecx), %edx\n"
        "movss 0x2be28(%edx), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf18911a_0018914f\n"
        "movl hud_healthOverlay_pulseStart, %eax\n"
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf18911a_0018925a\n"
        "movl (%ecx), %edx\n"
        ".Lf18911a_0018914f:\n"
        "movss %xmm1, 0x2be28(%edx)\n" /* line 947 */
        "movl 0x2be14(%edx), %eax\n" /* line 949 */
        "addl 0x2be18(%edx), %eax\n"
        "cmpl 0x25bb0(%edx), %eax\n"
        "jg .Lf18911a_0018923c\n"
        "movl hud_healthOverlay_pulseStart, %eax\n" /* line 952 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf18911a_00189241\n"
        "cmpb $0, 0x2be20(%edx)\n"
        "je .Lf18911a_0018923c\n"
        ".Lf18911a_0018918f:\n"
        "movl (%ecx), %esi\n" /* line 957 */
        "movl 0x25bb0(%esi), %eax\n"
        "movl %eax, 0x2be14(%esi)\n"
        "movl 0x2be10(%esi), %eax\n" /* line 958 */
        "movl %eax, 0x2be0c(%esi)\n"
        "movl 0x2be2c(%esi), %edi\n" /* line 960 */
        "cmpl $3, %edi\n"
        "ja .Lf18911a_00189277\n"
        "movl 0x2be1c(%esi), %eax\n" /* line 962 */
        "cmpl $1, %eax\n"
        "je .Lf18911a_001892a9\n"
        "cmpl $2, %eax\n"
        "je .Lf18911a_00189320\n"
        "testl %eax, %eax\n"
        "jne .Lf18911a_0018923c\n"
        "movss pulseMags(, %edi, 4), %xmm0\n" /* line 965 */
        "movss 0x2ed5d0, %xmm2\n" /* line 45 | 1.0f */
        "movaps %xmm0, %xmm1\n"
        "subss %xmm2, %xmm1\n"
        "pxor %xmm3, %xmm3\n"
        "movaps %xmm2, %xmm4\n"
        "cmpnltss %xmm3, %xmm1\n"
        "andps %xmm1, %xmm4\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm4, %xmm1\n"
        "movaps %xmm3, %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        "movaps %xmm1, %xmm4\n"
        "cmpltss %xmm3, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm3, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        "movss %xmm0, 0x2be10(%esi)\n" /* line 965 */
        "movl hud_healthOverlay_phaseOne_pulseDuration, %eax\n" /* line 966 */
        "movl 8(%eax), %eax\n"
        "movl %eax, 0x2be18(%esi)\n"
        "movl $1, 0x2be1c(%esi)\n" /* line 967 */
        /* } scope */
        ".Lf18911a_0018923c:\n"
        "popl %ebx\n" /* line 1000 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf18911a_00189241:\n"
        "cmpb $0, 0x2be20(%edx)\n" /* line 954 */
        "jne .Lf18911a_0018918f\n"
        "movb $1, 0x2be20(%edx)\n" /* line 955 */
        "jmp .Lf18911a_0018918f\n"
        ".Lf18911a_0018925a:\n"
        "movl 0x25bb0(%edx), %eax\n" /* line 944 */
        "movl %eax, 0x2be24(%edx)\n"
        "movl $0, 0x2be2c(%edx)\n" /* line 945 */
        "movl (%ecx), %edx\n"
        "jmp .Lf18911a_0018914f\n"
        ".Lf18911a_00189277:\n"
        "movb $0, 0x2be20(%esi)\n" /* line 994 */
        "movl hud_healthOverlay_phaseEnd_toAlpha, %eax\n" /* line 995 */
        "movl 8(%eax), %eax\n"
        "movl %eax, 0x2be10(%esi)\n"
        "movl hud_healthOverlay_phaseEnd_pulseDuration, %eax\n" /* line 996 */
        "movl 8(%eax), %eax\n"
        "movl %eax, 0x2be18(%esi)\n"
        "movl $0, 0x2be1c(%esi)\n" /* line 997 */
        /* } scope */
        "popl %ebx\n" /* line 1000 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf18911a_001892a9:\n"
        "movss pulseMags(, %edi, 4), %xmm0\n" /* line 970 */
        "movl hud_healthOverlay_phaseTwo_toAlphaMultiplier, %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "movss 0x2ed5d0, %xmm2\n" /* line 45 | 1.0f */
        "movaps %xmm0, %xmm1\n"
        "subss %xmm2, %xmm1\n"
        "pxor %xmm3, %xmm3\n"
        "movaps %xmm2, %xmm4\n"
        "cmpnltss %xmm3, %xmm1\n"
        "andps %xmm1, %xmm4\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm4, %xmm1\n"
        "movaps %xmm3, %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        "movaps %xmm1, %xmm4\n"
        "cmpltss %xmm3, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm3, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        "movss %xmm0, 0x2be10(%esi)\n" /* line 970 */
        "movl hud_healthOverlay_phaseTwo_pulseDuration, %eax\n" /* line 971 */
        "movl 8(%eax), %eax\n"
        "movl %eax, 0x2be18(%esi)\n"
        "movl $2, 0x2be1c(%esi)\n" /* line 972 */
        /* } scope */
        "popl %ebx\n" /* line 1000 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf18911a_00189320:\n"
        "movss pulseMags(, %edi, 4), %xmm0\n" /* line 975 */
        "movl hud_healthOverlay_phaseThree_toAlphaMultiplier, %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "movss 0x2ed5d0, %xmm2\n" /* line 45 | 1.0f */
        "movaps %xmm0, %xmm1\n"
        "subss %xmm2, %xmm1\n"
        "pxor %xmm3, %xmm3\n"
        "movaps %xmm2, %xmm4\n"
        "cmpnltss %xmm3, %xmm1\n"
        "andps %xmm1, %xmm4\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm4, %xmm1\n"
        "movaps %xmm3, %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        "movaps %xmm1, %xmm4\n"
        "cmpltss %xmm3, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm3, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        "movss %xmm0, 0x2be10(%esi)\n" /* line 975 */
        "movl hud_healthOverlay_phaseThree_pulseDuration, %ebx\n" /* line 976 */
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x2be18(%esi)\n"
        "movl $0, 0x2be1c(%esi)\n" /* line 977 */
        "movl 0x2be24(%esi), %ecx\n" /* line 983 */
        "movl hud_healthOverlay_regenPauseTime, %eax\n"
        "addl 8(%eax), %ecx\n"
        "movl hud_healthOverlay_phaseOne_pulseDuration, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl hud_healthOverlay_phaseTwo_pulseDuration, %edx\n"
        "addl 8(%edx), %eax\n"
        "addl 8(%ebx), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "subl %eax, %ecx\n"
        "cmpl %ecx, 0x25bb0(%esi)\n"
        "jl .Lf18911a_0018923c\n"
        "leal 1(%edi), %eax\n" /* line 984 */
        "movl %eax, 0x2be2c(%esi)\n"
        /* } scope */
        "popl %ebx\n" /* line 1000 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2012 */
__attribute__((naked))
void CG_ArchiveState(MemoryFile *memFile)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2012 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* memFile */
        "movl 0x195f584, %eax\n" /* line 167 */
        "movl (%eax), %esi\n"
        "leal 0x2c5c4(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll *0x10(%ebx)\n"
        "leal 0x2c5c8(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll *0x10(%ebx)\n"
        "leal 0x2c5cc(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll *0x10(%ebx)\n"
        "leal 0x2c5c0(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll *0x10(%ebx)\n"
        "leal 0x2c5d0(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll *0x10(%ebx)\n"
        "leal 0x2bdc8(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll *0x10(%ebx)\n"
        "leal 0x2a9fc(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x400, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll *0x10(%ebx)\n"
        "addl $0x2adfc, %esi\n"
        "movl %esi, 8(%esp)\n"
        "movl $0x100, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll *0x10(%ebx)\n"
        "addl $0x10, %esp\n" /* line 2023 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1525 */
static __attribute__((naked))
void CG_DrawHoldBreathHint(const rectDef_t *rect, struct Font_s *font, float fontscale, int textStyle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1525 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x144, %esp\n"
        /* { scope 1 */
        "movl 0x195f63c, %eax\n" /* line 1534 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1894ae_001894d8\n"
        "movl 0x195f584, %eax\n" /* line 1537 */
        "movl (%eax), %ebx\n" /* ps */
        "addl $0x25bc4, %ebx\n" /* ps */
        "testb $0x40, 0xd(%ebx)\n" /* line 1539 | ps */
        "je .Lf1894ae_001894e1\n"
        /* } scope */
        ".Lf1894ae_001894d8:\n"
        "addl $0x144, %esp\n" /* line 1564 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1894ae_001894e1:\n"
        "movl %ebx, (%esp)\n" /* line 1542 | ps */
        "calll BG_GetViewmodelWeaponIndex\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl 0x278(%eax), %ecx\n" /* line 1544 */
        "testl %ecx, %ecx\n"
        "je .Lf1894ae_001894d8\n"
        "cmpl $9, 0x7c(%eax)\n"
        "je .Lf1894ae_001894d8\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 1547 | 1.0f */
        "ucomiss 0xdc(%ebx), %xmm0\n" /* ps */
        "jne .Lf1894ae_001894d8\n"
        "jp .Lf1894ae_001894d8\n"
        "calll Controls_GetConfig\n" /* line 1550 */
        "leal -0x108(%ebp), %ebx\n" /* line 1552 | binding, ps */
        "movl %ebx, 4(%esp)\n" /* ps */
        "movl $0x2ac0d4, (%esp)\n" /* "+holdbreath" */
        "calll GetKeyBindingLocalizedString\n"
        "testl %eax, %eax\n"
        "je .Lf1894ae_00189612\n"
        ".Lf1894ae_00189537:\n"
        "movl $0x2afb60, (%esp)\n" /* line 1558 */
        "calll UI_SafeTranslateString\n"
        "movl %ebx, 4(%esp)\n" /* line 1559 | ps */
        "movl %eax, (%esp)\n"
        "calll UI_ReplaceConversionString\n"
        "movl %eax, %ebx\n" /* ps */
        "movl 8(%ebp), %eax\n" /* line 1561 | rect */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, -0x10c(%ebp)\n"
        "movss 0x10(%ebp), %xmm1\n" /* fontscale */
        "movss %xmm1, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ps */
        "calll UI_TextWidth\n"
        "movl 0x14(%ebp), %edx\n" /* line 1563 | textStyle */
        "movl %edx, 0x24(%esp)\n"
        "movl $color, 0x20(%esp)\n"
        "movss 0x10(%ebp), %xmm0\n" /* fontscale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* rect */
        "movl 0x14(%ecx), %edx\n"
        "movl %edx, 0x18(%esp)\n"
        "movl 0x10(%ecx), %edx\n"
        "movl %edx, 0x14(%esp)\n"
        "movl 4(%ecx), %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 428 */
        "movss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "mulss %xmm1, %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x110(%ebp)\n"
        "cvttss2si -0x110(%ebp), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0x10c(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll UI_DrawText\n"
        "jmp .Lf1894ae_001894d8\n"
        ".Lf1894ae_00189612:\n"
        "movl %ebx, 4(%esp)\n" /* line 1554 | ps */
        "movl $0x2ac0e0, (%esp)\n" /* "+melee_breath" */
        "calll GetKeyBindingLocalizedString\n"
        "testl %eax, %eax\n"
        "jne .Lf1894ae_00189537\n"
        "movl %ebx, 4(%esp)\n" /* line 1555 | ps */
        "movl $0x2ac0b8, (%esp)\n" /* "+breath_binoculars" */
        "calll GetKeyBindingLocalizedString\n"
        "jmp .Lf1894ae_00189537\n"
    );
}

/* line 108 */
__attribute__((naked))
float CG_FadeHudMenu(const dvar_t *fadeDvar, int displayStartTime, int duration)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 108 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "calll CL_GetKeyCatchers\n" /* line 101 */
        "testb $8, %al\n"
        "jne .Lf189640_0018968f\n"
        ".Lf189640_0018964f:\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x2bdc8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf189640_0018968b\n"
        ".Lf189640_00189660:\n"
        "movl $1, %eax\n"
        ".Lf189640_00189665:\n"
        "testl %eax, %eax\n" /* line 113 */
        "jne .Lf189640_00189687\n"
        "movl hud_enable, %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf189640_00189687\n"
        "pxor %xmm0, %xmm0\n" /* line 119 */
        "movl 8(%ebp), %eax\n" /* fadeDvar */
        "ucomiss 8(%eax), %xmm0\n"
        "jne .Lf189640_0018969a\n"
        "jp .Lf189640_0018969a\n"
        "fld1\n"
        /* } scope */
        "leave\n" /* line 127 */
        "retl\n"
        /* { scope 1 */
        ".Lf189640_00189687:\n"
        "fldz\n" /* line 126 */
        /* } scope */
        "leave\n" /* line 127 */
        "retl\n"
        /* { scope 1 */
        ".Lf189640_0018968b:\n"
        "xorl %eax, %eax\n" /* line 101 */
        "jmp .Lf189640_00189665\n"
        ".Lf189640_0018968f:\n"
        "calll CL_GetDisplayHUDWithKeycatchUI\n"
        "testb %al, %al\n"
        "je .Lf189640_00189660\n"
        "jmp .Lf189640_0018964f\n"
        ".Lf189640_0018969a:\n"
        "movl $0x2bc, 8(%esp)\n" /* line 122 */
        "movl 0x10(%ebp), %eax\n" /* duration */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* displayStartTime */
        "movl %eax, (%esp)\n"
        "calll CG_FadeColor\n"
        "testl %eax, %eax\n" /* line 123 */
        "je .Lf189640_00189687\n"
        "flds 0xc(%eax)\n" /* line 126 */
        /* } scope */
        "leave\n" /* line 127 */
        "retl\n"
    );
}

/* line 168 */
__attribute__((naked))
Bool CG_CheckPlayerForLowAmmo(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 168 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 0x195f584, %edi\n" /* line 176 */
        "movl (%edi), %ebx\n" /* ammoIndex */
        "leal 0x25bc4(%ebx), %eax\n" /* ammoIndex */
        "movl %eax, -0x1c(%ebp)\n" /* ps */
        "movl 0x2be50(%ebx), %esi\n" /* line 159 */
        "testl %esi, %esi\n"
        "js .Lf1896be_00189788\n"
        "calll BG_GetNumWeapons\n"
        "cmpl %eax, %esi\n"
        "jl .Lf1896be_00189762\n"
        ".Lf1896be_001896ef:\n"
        "movl (%edi), %eax\n"
        ".Lf1896be_001896f1:\n"
        "movl 0x25c98(%eax), %esi\n" /* line 161 */
        ".Lf1896be_001896f7:\n"
        "testl %esi, %esi\n" /* line 179 | curAmmo */
        "jne .Lf1896be_00189705\n"
        ".Lf1896be_001896fb:\n"
        "xorl %eax, %eax\n" /* line 191 */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 194 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1896be_00189705:\n"
        "movl %esi, (%esp)\n" /* line 181 | curAmmo */
        "calll BG_AmmoForWeapon\n"
        "movl %eax, %ebx\n" /* ammoIndex */
        "movl %esi, 4(%esp)\n" /* line 183 | curAmmo */
        "movl -0x1c(%ebp), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "calll BG_GetTotalAmmoReserve\n"
        "movl %eax, %esi\n" /* curAmmo */
        "cmpl $0x3e8, %eax\n" /* line 184 */
        "movl $0x3e7, %eax\n"
        "cmovgel %eax, %esi\n" /* curAmmo */
        "movl %ebx, (%esp)\n" /* line 187 | ammoIndex */
        "calll BG_GetAmmoTypeMax\n"
        "cmpl $0x3e7, %eax\n" /* line 188 */
        "jle .Lf1896be_0018978f\n"
        "movss 0x2ed94c, %xmm1\n" /* 999.0f */
        ".Lf1896be_00189744:\n"
        "cvtsi2ssl %esi, %xmm0\n" /* line 191 | curAmmo */
        "mulss 0x2ed724, %xmm1\n" /* 0.20000000298023224f */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf1896be_001896fb\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 194 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1896be_00189762:\n"
        "movl 0x2be50(%ebx), %esi\n" /* line 159 */
        "movl %esi, %eax\n"
        "sarl $5, %eax\n"
        "movl %esi, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl 0x26108(%ebx, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf1896be_001896f7\n"
        "jmp .Lf1896be_001896ef\n"
        ".Lf1896be_00189788:\n"
        "movl %ebx, %eax\n"
        "jmp .Lf1896be_001896f1\n"
        ".Lf1896be_0018978f:\n"
        "testl %eax, %eax\n" /* line 191 */
        "js .Lf1896be_001896fb\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "jmp .Lf1896be_00189744\n"
    );
}

/* line 200 */
__attribute__((naked))
Bool CG_CheckPlayerForLowClip(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 200 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 0x195f584, %edi\n" /* line 207 */
        "movl (%edi), %ebx\n" /* curClipVal */
        "leal 0x25bc4(%ebx), %eax\n" /* curClipVal */
        "movl %eax, -0x1c(%ebp)\n" /* ps */
        "movl 0x2be50(%ebx), %esi\n" /* line 159 */
        "testl %esi, %esi\n"
        "js .Lf18979e_0018987c\n"
        "calll BG_GetNumWeapons\n"
        "cmpl %eax, %esi\n"
        "jl .Lf18979e_00189856\n"
        ".Lf18979e_001897d3:\n"
        "movl (%edi), %eax\n"
        ".Lf18979e_001897d5:\n"
        "movl 0x25c98(%eax), %esi\n" /* line 161 */
        ".Lf18979e_001897db:\n"
        "testl %esi, %esi\n" /* line 211 | weapIndex */
        "jne .Lf18979e_001897e9\n"
        ".Lf18979e_001897df:\n"
        "xorl %eax, %eax\n" /* line 226 */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 230 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf18979e_001897e9:\n"
        "movl %esi, (%esp)\n" /* line 213 | weapIndex */
        "calll BG_WeaponIsClipOnly\n"
        "testl %eax, %eax\n"
        "jne .Lf18979e_001897df\n"
        "movl %esi, (%esp)\n" /* line 216 | weapIndex */
        "calll BG_ClipForWeapon\n"
        "movl -0x1c(%ebp), %edx\n" /* ps */
        "movl 0x344(%edx, %eax, 4), %ebx\n" /* curClipVal */
        "testl %ebx, %ebx\n" /* line 217 | curClipVal */
        "js .Lf18979e_001897df\n"
        "cmpl $0x3e8, %ebx\n" /* line 219 | curClipVal */
        "movl $0x3e7, %eax\n"
        "cmovgel %eax, %ebx\n" /* curClipVal */
        "movl %esi, (%esp)\n" /* line 222 | weapIndex */
        "calll BG_ClipForWeapon\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetAmmoClipSize\n"
        "cmpl $0x3e7, %eax\n" /* line 223 */
        "jle .Lf18979e_00189883\n"
        "movss 0x2ed94c, %xmm1\n" /* 999.0f */
        ".Lf18979e_00189838:\n"
        "cvtsi2ssl %ebx, %xmm0\n" /* line 226 | curClipVal */
        "mulss 0x2ed8ec, %xmm1\n" /* 0.33000001311302185f */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf18979e_001897df\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 230 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf18979e_00189856:\n"
        "movl 0x2be50(%ebx), %esi\n" /* line 159 */
        "movl %esi, %eax\n"
        "sarl $5, %eax\n"
        "movl %esi, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl 0x26108(%ebx, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf18979e_001897db\n"
        "jmp .Lf18979e_001897d3\n"
        ".Lf18979e_0018987c:\n"
        "movl %ebx, %eax\n"
        "jmp .Lf18979e_001897d5\n"
        ".Lf18979e_00189883:\n"
        "testl %eax, %eax\n" /* line 226 */
        "jle .Lf18979e_001897df\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "jmp .Lf18979e_00189838\n"
    );
}

/* line 1148 */
__attribute__((naked))
void CG_DrawPlayerCompassBack(const rectDef_t *rect, MaterialHandle material, vec_t *color)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1148 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %edi\n" /* rect */
        "movl 0x10(%ebp), %eax\n" /* line 1153 | color */
        "addl $0xc, %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl hud_fade_compass, %esi\n"
        "movss 0x2ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "mulss 8(%esi), %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x28(%ebp)\n"
        "cvttss2si -0x28(%ebp), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* duration */
        "movl 0x195f584, %eax\n" /* line 1153 */
        "movl (%eax), %ebx\n"
        "movl 0x2c5c0(%ebx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* displayStartTime */
        /* { scope 1 */
        /* { scope 2 */
        "calll CL_GetKeyCatchers\n" /* line 101 */
        "testb $8, %al\n"
        "jne .Lf189892_001899e6\n"
        ".Lf189892_001898f4:\n"
        "movl 0x2bdc8(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf189892_0018992f\n"
        ".Lf189892_001898fe:\n"
        "movl $1, %eax\n"
        ".Lf189892_00189903:\n"
        "testl %eax, %eax\n" /* line 113 */
        "jne .Lf189892_00189912\n"
        "movl hud_enable, %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf189892_00189933\n"
        ".Lf189892_00189912:\n"
        "pxor %xmm0, %xmm0\n" /* line 126 */
        "movaps %xmm0, %xmm1\n"
        /* } scope */
        /* } scope */
        ".Lf189892_00189919:\n"
        "movl -0x24(%ebp), %eax\n" /* line 1153 */
        "movss %xmm0, (%eax)\n"
        "ucomiss %xmm1, %xmm0\n" /* line 1154 */
        "jp .Lf189892_00189951\n"
        "jne .Lf189892_00189951\n"
        "addl $0x4c, %esp\n" /* line 1159 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf189892_0018992f:\n"
        "xorl %eax, %eax\n" /* line 101 */
        "jmp .Lf189892_00189903\n"
        ".Lf189892_00189933:\n"
        "pxor %xmm1, %xmm1\n" /* line 119 */
        "ucomiss 8(%esi), %xmm1\n"
        "jne .Lf189892_001899f8\n"
        "jp .Lf189892_001899f8\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jmp .Lf189892_00189919\n"
        /* } scope */
        /* } scope */
        ".Lf189892_00189951:\n"
        "movss 0xc(%edi), %xmm3\n" /* line 1115 */
        "movl 0x195f640, %eax\n"
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "movl 0xc(%ebp), %eax\n" /* line 1158 | material */
        "movl %eax, 0x2c(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* color */
        "movl %eax, 0x28(%esp)\n"
        "movss 0x2ed5d0, %xmm2\n" /* 1.0f */
        "movss %xmm2, 0x24(%esp)\n"
        "movss %xmm2, 0x20(%esp)\n"
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl 0x14(%edi), %eax\n" /* rect */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edi), %eax\n" /* rect */
        "movl %eax, 0x10(%esp)\n"
        "movaps %xmm3, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movaps %xmm1, %xmm0\n"
        "mulss 8(%edi), %xmm0\n" /* rect */
        "movss %xmm0, 8(%esp)\n"
        "subss %xmm2, %xmm1\n"
        "mulss %xmm1, %xmm3\n"
        "movss 4(%edi), %xmm0\n" /* rect */
        "subss %xmm3, %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl (%edi), %eax\n" /* rect */
        "movl %eax, (%esp)\n"
        "calll CL_DrawStretchPic\n"
        "addl $0x4c, %esp\n" /* line 1159 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf189892_001899e6:\n"
        "calll CL_GetDisplayHUDWithKeycatchUI\n" /* line 101 */
        "testb %al, %al\n"
        "je .Lf189892_001898fe\n"
        "jmp .Lf189892_001898f4\n"
        ".Lf189892_001899f8:\n"
        "movl $0x2bc, 8(%esp)\n" /* line 122 */
        "movl -0x20(%ebp), %eax\n" /* duration */
        "movl %eax, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* displayStartTime */
        "movl %eax, (%esp)\n"
        "calll CG_FadeColor\n"
        "testl %eax, %eax\n" /* line 123 */
        "je .Lf189892_00189912\n"
        "movss 0xc(%eax), %xmm0\n" /* line 126 */
        "pxor %xmm1, %xmm1\n"
        "jmp .Lf189892_00189919\n"
    );
}

/* line 559 */
static __attribute__((naked))
void CG_DrawPlayerStance(const rectDef_t *rect, vec_t *color, struct Font_s *font, float scale, int textStyle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 559 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x28c, %esp\n"
        /* { scope 1: duration, i, numHintLines, height, ... */
        "movl hud_fade_stance, %esi\n" /* line 571 | height */
        "movss 0x2ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "mulss 8(%esi), %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x248(%ebp)\n"
        "cvttss2si -0x248(%ebp), %eax\n"
        "movl %eax, -0x238(%ebp)\n" /* duration */
        "movl 0x195f584, %eax\n" /* line 571 */
        "movl (%eax), %ebx\n" /* proneStr */
        "movl 0x2c5cc(%ebx), %edi\n" /* proneStr, displayStartTime */
        /* { scope 2: keyBinding */
        /* { scope 3 */
        "calll CL_GetKeyCatchers\n" /* line 101 */
        "testb $8, %al\n"
        "jne .Lf189a28_00189d13\n"
        ".Lf189a28_00189a87:\n"
        "movl 0x2bdc8(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf189a28_00189d0c\n"
        ".Lf189a28_00189a95:\n"
        "movl $1, %eax\n"
        ".Lf189a28_00189a9a:\n"
        "testl %eax, %eax\n" /* line 113 */
        "jne .Lf189a28_00189d01\n"
        "movl hud_enable, %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf189a28_00189d01\n"
        "pxor %xmm0, %xmm0\n" /* line 119 */
        "ucomiss 8(%esi), %xmm0\n"
        "jne .Lf189a28_00189e73\n"
        "jp .Lf189a28_00189e73\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x23c(%ebp)\n" /* fadeAlpha */
        /* } scope */
        /* } scope */
        ".Lf189a28_00189ad5:\n"
        "movl 0x195f648, %esi\n" /* line 575 | height */
        "movl (%esi), %eax\n" /* height */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf189a28_00189d25\n"
        "movl 0x195f584, %ebx\n" /* line 576 | proneStr */
        "movl (%ebx), %eax\n" /* proneStr */
        "movl $0, 0x2be38(%eax)\n"
        "movl %eax, %ecx\n"
        ".Lf189a28_00189afb:\n"
        "movl 0x25bd0(%ecx), %eax\n" /* line 580 */
        "andl $3, %eax\n"
        "movl %eax, 0x2be34(%ecx)\n"
        "movl 0x195f5c4, %eax\n" /* line 583 */
        "movl (%eax), %edx\n"
        "movl 0x195f640, %eax\n"
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x244(%ebp)\n" /* x */
        "mulss 0xc208(%edx), %xmm1\n"
        "mulss 0x2ed6ac, %xmm1\n" /* 0.699999988079071f */
        "movss %xmm1, -0x244(%ebp)\n" /* x */
        "movl 8(%ebp), %eax\n" /* rect */
        "addss (%eax), %xmm1\n"
        "movss %xmm1, -0x244(%ebp)\n" /* x */
        "movss 4(%eax), %xmm0\n" /* line 584 */
        "movss %xmm0, -0x240(%ebp)\n" /* y */
        "movl 0xc(%ebp), %edx\n" /* line 199 | color */
        "movl (%edx), %eax\n"
        "movl %eax, -0x40(%ebp)\n" /* drawColor */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x3c(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x38(%ebp)\n"
        "testb $1, 0x25bd2(%ecx)\n" /* line 590 */
        "je .Lf189a28_00189d55\n"
        "movl 0x25bb0(%ecx), %eax\n"
        "cmpl %eax, 0x2be30(%ecx)\n"
        "jge .Lf189a28_00189b97\n"
        "addl $0x5dc, %eax\n" /* line 591 */
        "movl %eax, 0x2be30(%ecx)\n"
        ".Lf189a28_00189b97:\n"
        "movl (%ebx), %edi\n" /* proneStr, displayStartTime */
        "movl 0x2be30(%edi), %eax\n" /* line 593 | displayStartTime */
        "cmpl 0x25bb0(%edi), %eax\n" /* displayStartTime */
        "jg .Lf189a28_00189d69\n"
        ".Lf189a28_00189bab:\n"
        "movl (%esi), %eax\n" /* line 604 | height */
        "cmpb $0, 8(%eax)\n"
        "je .Lf189a28_00189bca\n"
        "movl 0x2be38(%edi), %eax\n" /* displayStartTime */
        "addl $0xbb8, %eax\n"
        "cmpl 0x25bb0(%edi), %eax\n" /* displayStartTime */
        "jg .Lf189a28_00189ed0\n"
        ".Lf189a28_00189bca:\n"
        "movss -0x23c(%ebp), %xmm0\n" /* line 732 | fadeAlpha */
        "movss %xmm0, -0x34(%ebp)\n"
        /* { scope 2: keyBinding */
        "movl 8(%ebp), %eax\n" /* line 530 | rect */
        "movl 8(%eax), %edi\n" /* width */
        "movl 0xc(%eax), %esi\n" /* line 531 | height */
        "movl 0x195f584, %eax\n" /* line 535 */
        "movl (%eax), %eax\n"
        "movl 0x2be34(%eax), %eax\n"
        "testb $1, %al\n"
        "je .Lf189a28_00189e5d\n"
        "movl 0x195f5c4, %eax\n" /* line 536 */
        "movl (%eax), %eax\n"
        "movl 0xbc60(%eax), %eax\n"
        ".Lf189a28_00189c02:\n"
        "movl %eax, 0x1c(%esp)\n" /* line 542 */
        "leal -0x40(%ebp), %edx\n" /* drawColor */
        "movl %edx, 0x18(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* rect */
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%ecx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n" /* height */
        "movl %edi, 8(%esp)\n" /* width */
        "movss -0x240(%ebp), %xmm0\n" /* y */
        "movss %xmm0, 4(%esp)\n"
        "movss -0x244(%ebp), %xmm1\n" /* x */
        "movss %xmm1, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        "movl 0x195f584, %eax\n" /* line 545 */
        "movl (%eax), %ebx\n"
        "movl 0x2be38(%ebx), %eax\n"
        "addl $0x3e8, %eax\n"
        "cmpl 0x25bb0(%ebx), %eax\n"
        "jle .Lf189a28_00189d01\n"
        "leal -0x40(%ebp), %eax\n" /* line 547 | drawColor */
        "movl %eax, 4(%esp)\n"
        "movl 0x195f65c, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_GetUnpackedColor\n"
        "movl 0x2be38(%ebx), %eax\n" /* line 548 */
        "subl 0x25bb0(%ebx), %eax\n"
        "addl $0x3e8, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "divss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "mulss 0x2ed7f0, %xmm0\n" /* 0.800000011920929f */
        "movss -0x23c(%ebp), %xmm1\n" /* line 550 | fadeAlpha */
        "minss %xmm0, %xmm1\n"
        "movss %xmm1, -0x34(%ebp)\n"
        "movl 0x195f5c4, %eax\n" /* line 551 */
        "movl (%eax), %eax\n"
        "movl 0xbc64(%eax), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "leal -0x40(%ebp), %eax\n" /* drawColor */
        "movl %eax, 0x18(%esp)\n"
        "movl 8(%ebp), %edx\n" /* rect */
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n" /* height */
        "movl %edi, 8(%esp)\n" /* width */
        "movss -0x240(%ebp), %xmm0\n" /* y */
        "movss %xmm0, 4(%esp)\n"
        "movss -0x244(%ebp), %xmm1\n" /* x */
        "movss %xmm1, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        /* } scope */
        /* } scope */
        ".Lf189a28_00189d01:\n"
        "addl $0x28c, %esp\n" /* line 735 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: duration, i, numHintLines, height, ... */
        /* { scope 2: keyBinding */
        /* { scope 3 */
        ".Lf189a28_00189d0c:\n"
        "xorl %eax, %eax\n" /* line 101 */
        "jmp .Lf189a28_00189a9a\n"
        ".Lf189a28_00189d13:\n"
        "calll CL_GetDisplayHUDWithKeycatchUI\n"
        "testb %al, %al\n"
        "je .Lf189a28_00189a95\n"
        "jmp .Lf189a28_00189a87\n"
        /* } scope */
        /* } scope */
        ".Lf189a28_00189d25:\n"
        "movl 0x195f584, %ebx\n" /* line 577 | proneStr */
        "movl (%ebx), %edx\n" /* proneStr */
        "movl 0x25bd0(%edx), %eax\n"
        "andl $3, %eax\n"
        "cmpl %eax, 0x2be34(%edx)\n"
        "je .Lf189a28_0018a09b\n"
        "movl 0x25bb0(%edx), %eax\n" /* line 578 */
        "movl %eax, 0x2be38(%edx)\n"
        "movl (%ebx), %ecx\n" /* proneStr */
        "jmp .Lf189a28_00189afb\n"
        ".Lf189a28_00189d55:\n"
        "movl %ecx, %edi\n" /* displayStartTime */
        "movl 0x2be30(%edi), %eax\n" /* line 593 | displayStartTime */
        "cmpl 0x25bb0(%edi), %eax\n" /* displayStartTime */
        "jle .Lf189a28_00189bab\n"
        ".Lf189a28_00189d69:\n"
        "movl $0x2afb78, (%esp)\n" /* line 595 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, %ebx\n" /* proneStr */
        "movss 0x14(%ebp), %xmm0\n" /* line 596 | scale */
        "movss %xmm0, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* proneStr */
        "calll UI_TextWidth\n"
        "movl %eax, %esi\n" /* height */
        "movl 0x2be30(%edi), %eax\n" /* line 599 | displayStartTime */
        "subl 0x25bb0(%edi), %eax\n" /* displayStartTime */
        "cvtsi2ssl %eax, %xmm0\n"
        "divss 0x2ed950, %xmm0\n" /* 1500.0f */
        "mulss 0x2ed954, %xmm0\n" /* 540.0f */
        "cvtss2sd %xmm0, %xmm0\n"
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
        "movsd %xmm0, (%esp)\n"
        "calll sin\n"
        "fstpl -0x250(%ebp)\n"
        "cvtsd2ss -0x250(%ebp), %xmm0\n"
        "andps 0x302d90, %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "movl 0x18(%ebp), %edx\n" /* line 600 | textStyle */
        "movl %edx, 0x24(%esp)\n"
        "leal -0x40(%ebp), %ecx\n" /* drawColor */
        "movl %ecx, 0x20(%esp)\n"
        "movss 0x14(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl $3, 0x18(%esp)\n"
        "movl $7, 0x14(%esp)\n"
        "movl 0x195f670, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "cvtsi2ssl %esi, %xmm0\n" /* height */
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "xorps 0x302da0, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* proneStr */
        "calll UI_DrawText\n"
        "movl 0x195f648, %esi\n" /* height */
        "jmp .Lf189a28_00189bab\n"
        /* { scope 2: keyBinding */
        ".Lf189a28_00189e5d:\n"
        "testb $2, %al\n" /* line 537 */
        "je .Lf189a28_00189ebe\n"
        "movl 0x195f5c4, %eax\n" /* line 538 */
        "movl (%eax), %eax\n"
        "movl 0xbc5c(%eax), %eax\n"
        "jmp .Lf189a28_00189c02\n"
        /* } scope */
        /* { scope 2: keyBinding */
        /* { scope 3 */
        ".Lf189a28_00189e73:\n"
        "movl $0x2bc, 8(%esp)\n" /* line 122 */
        "movl -0x238(%ebp), %edx\n" /* duration */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll CG_FadeColor\n"
        "testl %eax, %eax\n" /* line 123 */
        "je .Lf189a28_00189d01\n"
        "movss 0xc(%eax), %xmm0\n" /* line 126 */
        "movss %xmm0, -0x23c(%ebp)\n" /* fadeAlpha */
        /* } scope */
        /* } scope */
        "ucomiss 0x2ed5e8, %xmm0\n" /* line 572 | 0.0f */
        "jp .Lf189a28_00189eb1\n"
        "je .Lf189a28_00189d01\n"
        ".Lf189a28_00189eb1:\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jmp .Lf189a28_00189ad5\n"
        /* { scope 2: keyBinding */
        ".Lf189a28_00189ebe:\n"
        "movl 0x195f5c4, %eax\n" /* line 540 */
        "movl (%eax), %eax\n"
        "movl 0xbc58(%eax), %eax\n"
        "jmp .Lf189a28_00189c02\n"
        /* } scope */
        /* { scope 2: keyBinding */
        ".Lf189a28_00189ed0:\n"
        "movl $0x48, 8(%esp)\n" /* line 630 */
        "movl $__ZZ19CG_DrawPlayerStancePK9rectDef_sPfP6Font_sfiE5C.180, 4(%esp)\n"
        "leal -0xd0(%ebp), %edx\n" /* standCmds */
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl $0x48, 8(%esp)\n" /* line 642 */
        "movl $__ZZ19CG_DrawPlayerStancePK9rectDef_sPfP6Font_sfiE5C.181, 4(%esp)\n"
        "leal -0x88(%ebp), %ecx\n" /* duckCmds */
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        "movl $0x48, 8(%esp)\n" /* line 653 */
        "movl $__ZZ19CG_DrawPlayerStancePK9rectDef_sPfP6Font_sfiE5C.182, 4(%esp)\n"
        "leal -0x118(%ebp), %eax\n" /* proneCmds */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0x2afb8c, -0x30(%ebp)\n" /* line 659 | hintTypeStrings */
        "movl $0x2afba8, -0x2c(%ebp)\n" /* "PLATFORM_STANCEHINT_CROUCH" */
        "movl $0x2afbc4, -0x28(%ebp)\n" /* "PLATFORM_STANCEHINT_PRONE" */
        "calll Controls_GetConfig\n" /* line 661 */
        "movl 0x2be38(%edi), %edx\n" /* line 663 | displayStartTime */
        "movl 0x25bb0(%edi), %ecx\n" /* displayStartTime */
        "leal 0x7d0(%edx), %eax\n"
        "cmpl %ecx, %eax\n"
        "jle .Lf189a28_0018a0a2\n"
        "movl $0x3f800000, -0x34(%ebp)\n" /* line 664 */
        ".Lf189a28_00189f65:\n"
        "movss 0x14(%ebp), %xmm0\n" /* line 668 | scale */
        "movss %xmm0, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* font */
        "movl %eax, (%esp)\n"
        "calll UI_TextHeight\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x22c(%ebp)\n" /* height */
        "movl $0, -0x230(%ebp)\n" /* numHintLines */
        "movl $0, -0x234(%ebp)\n" /* i */
        "movl $0, -0x21c(%ebp)\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %edx\n"
        "movl %edx, -0x254(%ebp)\n"
        "movl %eax, -0x258(%ebp)\n"
        "movl $0, -0x25c(%ebp)\n"
        "leal -0x24(%ebp), %ecx\n" /* hintLineCmds */
        "movl %ecx, -0x260(%ebp)\n"
        "movl %ecx, %eax\n"
        ".Lf189a28_00189fcd:\n"
        "movl $0, (%eax)\n" /* line 673 */
        "movl -0x254(%ebp), %edx\n" /* line 676 */
        "movl 0x2be34(%edx), %eax\n"
        "testb $1, %al\n"
        "je .Lf189a28_0018a0d7\n"
        "movl -0x21c(%ebp), %ecx\n" /* line 677 */
        "movl -0x118(%ecx, %ebp), %ebx\n" /* binding */
        ".Lf189a28_00189ff4:\n"
        "testl %ebx, %ebx\n" /* line 683 | binding */
        "je .Lf189a28_0018a06b\n"
        "leal -0xd0(%ebp), %eax\n" /* line 681 | standCmds */
        "addl -0x25c(%ebp), %eax\n"
        "movl %eax, -0x220(%ebp)\n"
        "leal -0x118(%ebp), %esi\n" /* proneCmds, height */
        "addl -0x25c(%ebp), %esi\n" /* height */
        "leal -0x88(%ebp), %edi\n" /* duckCmds, displayStartTime */
        "addl -0x25c(%ebp), %edi\n" /* displayStartTime */
        "movl $6, -0x224(%ebp)\n"
        ".Lf189a28_0018a02c:\n"
        "movl %ebx, (%esp)\n" /* line 685 | binding */
        "calll GetCommandHasBinding\n"
        "testl %eax, %eax\n"
        "jne .Lf189a28_0018a27a\n"
        "movl -0x258(%ebp), %edx\n" /* line 693 */
        "movl (%edx), %eax\n"
        "movl 0x2be34(%eax), %eax\n"
        "testb $1, %al\n"
        "je .Lf189a28_0018a0c0\n"
        "movl 4(%esi), %ebx\n" /* line 694 | height, binding */
        ".Lf189a28_0018a051:\n"
        "subl $1, -0x224(%ebp)\n" /* line 683 */
        "je .Lf189a28_0018a06b\n"
        "addl $4, -0x220(%ebp)\n"
        "addl $4, %esi\n" /* height */
        "addl $4, %edi\n" /* displayStartTime */
        "testl %ebx, %ebx\n" /* binding */
        "jne .Lf189a28_0018a02c\n"
        ".Lf189a28_0018a06b:\n"
        "addl $1, -0x234(%ebp)\n" /* line 671 | i */
        "addl $4, -0x260(%ebp)\n"
        "addl $0x18, -0x25c(%ebp)\n"
        "addl $0x18, -0x21c(%ebp)\n"
        "cmpl $3, -0x234(%ebp)\n" /* i */
        "je .Lf189a28_0018a0f1\n"
        "movl -0x260(%ebp), %eax\n"
        "jmp .Lf189a28_00189fcd\n"
        ".Lf189a28_0018a09b:\n"
        "movl %edx, %ecx\n"
        "jmp .Lf189a28_00189afb\n"
        ".Lf189a28_0018a0a2:\n"
        "subl %ecx, %edx\n" /* line 666 */
        "leal 0xbb8(%edx), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "divss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "movss %xmm0, -0x34(%ebp)\n"
        "jmp .Lf189a28_00189f65\n"
        ".Lf189a28_0018a0c0:\n"
        "testb $2, %al\n" /* line 695 */
        "je .Lf189a28_0018a0c9\n"
        "movl 4(%edi), %ebx\n" /* line 696 | displayStartTime, binding */
        "jmp .Lf189a28_0018a051\n"
        ".Lf189a28_0018a0c9:\n"
        "movl -0x220(%ebp), %ecx\n" /* line 698 */
        "movl 4(%ecx), %ebx\n" /* binding */
        "jmp .Lf189a28_0018a051\n"
        ".Lf189a28_0018a0d7:\n"
        "testb $2, %al\n" /* line 678 */
        "je .Lf189a28_0018a24b\n"
        "movl -0x21c(%ebp), %eax\n" /* line 679 */
        "movl -0x88(%eax, %ebp), %ebx\n" /* binding */
        "jmp .Lf189a28_00189ff4\n"
        ".Lf189a28_0018a0f1:\n"
        "movss 0x2ed5d8, %xmm0\n" /* line 702 | 0.5f */
        "movl 8(%ebp), %eax\n" /* rect */
        "movss 0xc(%eax), %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x228(%ebp)\n" /* y */
        "addss 4(%eax), %xmm1\n"
        "movss %xmm1, -0x228(%ebp)\n" /* y */
        "movss 0x2ed600, %xmm1\n" /* 1.5f */
        "movss -0x228(%ebp), %xmm2\n" /* y */
        "subss %xmm1, %xmm2\n"
        "movss %xmm2, -0x228(%ebp)\n" /* y */
        "cmpl $1, -0x230(%ebp)\n" /* line 703 | numHintLines */
        "je .Lf189a28_0018a25d\n"
        "cmpl $3, -0x230(%ebp)\n" /* numHintLines */
        "je .Lf189a28_0018a28e\n"
        ".Lf189a28_0018a150:\n"
        "movss -0x34(%ebp), %xmm0\n" /* line 713 */
        "movss -0x23c(%ebp), %xmm1\n" /* line 714 | fadeAlpha */
        "movaps %xmm1, %xmm2\n"
        "cmpltss %xmm0, %xmm1\n"
        "andps %xmm1, %xmm2\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm2, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "movl $1, %esi\n" /* height */
        "leal -0x218(%ebp), %edi\n" /* keyBinding, displayStartTime */
        ".Lf189a28_0018a181:\n"
        "leal (, %esi, 4), %ebx\n" /* line 717 | binding */
        "movl -0x28(%ebp, %ebx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf189a28_0018a23a\n"
        /* { scope 3 */
        "movl %edi, 4(%esp)\n" /* line 721 | displayStartTime */
        "movl %eax, (%esp)\n"
        "calll GetKeyBindingLocalizedString\n"
        "movl -0x34(%ebp, %ebx), %eax\n" /* line 723 */
        "movl %eax, (%esp)\n"
        "calll UI_SafeTranslateString\n"
        "movl %edi, 4(%esp)\n" /* line 724 | displayStartTime */
        "movl %eax, (%esp)\n"
        "calll UI_ReplaceConversionString\n"
        "movl 0x18(%ebp), %edx\n" /* line 726 | textStyle */
        "movl %edx, 0x24(%esp)\n"
        "leal -0x40(%ebp), %ecx\n" /* drawColor */
        "movl %ecx, 0x20(%esp)\n"
        "movss 0x14(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* rect */
        "movl 0x14(%ecx), %edx\n"
        "movl %edx, 0x18(%esp)\n"
        "movl 0x10(%ecx), %edx\n"
        "movl %edx, 0x14(%esp)\n"
        "movss -0x228(%ebp), %xmm0\n" /* y */
        "movss %xmm0, 0x10(%esp)\n"
        "movss -0x244(%ebp), %xmm0\n" /* x */
        "addss 8(%ecx), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* font */
        "movl %edx, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        "movss -0x22c(%ebp), %xmm0\n" /* line 727 | height */
        "addss 0x2ed600, %xmm0\n" /* 1.5f */
        "addss -0x228(%ebp), %xmm0\n" /* y */
        "movss %xmm0, -0x228(%ebp)\n" /* y */
        ".Lf189a28_0018a23a:\n"
        "addl $1, %esi\n" /* height */
        /* } scope */
        "cmpl $4, %esi\n" /* line 715 | height */
        "jne .Lf189a28_0018a181\n"
        "jmp .Lf189a28_00189bca\n"
        ".Lf189a28_0018a24b:\n"
        "movl -0x21c(%ebp), %edx\n" /* line 681 */
        "movl -0xd0(%edx, %ebp), %ebx\n" /* binding */
        "jmp .Lf189a28_00189ff4\n"
        ".Lf189a28_0018a25d:\n"
        "mulss -0x22c(%ebp), %xmm0\n" /* line 709 | height */
        "addss -0x228(%ebp), %xmm0\n" /* y */
        "movss %xmm0, -0x228(%ebp)\n" /* y */
        "jmp .Lf189a28_0018a150\n"
        ".Lf189a28_0018a27a:\n"
        "movl -0x260(%ebp), %ecx\n" /* line 687 */
        "movl %ebx, (%ecx)\n" /* binding */
        "addl $1, -0x230(%ebp)\n" /* line 688 | numHintLines */
        "jmp .Lf189a28_0018a06b\n"
        ".Lf189a28_0018a28e:\n"
        "mulss -0x22c(%ebp), %xmm0\n" /* line 706 | height */
        "addss %xmm1, %xmm0\n"
        "subss %xmm0, %xmm2\n"
        "movss %xmm2, -0x228(%ebp)\n" /* y */
        "jmp .Lf189a28_0018a150\n"
    );
}

/* line 259 */
static __attribute__((naked))
void CG_DrawPlayerAmmoValue(const rectDef_t *rect, struct Font_s *font, float scale, vec_t *color, MaterialHandle material, int textStyle, int type)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 259 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2ac, %esp\n"
        "movl %eax, -0x254(%ebp)\n"
        "movl %edx, -0x258(%ebp)\n"
        "movss %xmm0, -0x25c(%ebp)\n"
        "movl %ecx, -0x260(%ebp)\n"
        /* { scope 1: duration */
        "movl 0x195f584, %eax\n" /* line 277 */
        "movl (%eax), %ebx\n" /* weap */
        "movl 0x25c98(%ebx), %eax\n" /* weap */
        "testl %eax, %eax\n"
        "jne .Lf18a2ac_0018a2ee\n"
        /* } scope */
        ".Lf18a2ac_0018a2e3:\n"
        "addl $0x2ac, %esp\n" /* line 375 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: duration */
        ".Lf18a2ac_0018a2ee:\n"
        "addl $0xc, %ecx\n" /* line 280 */
        "movl %ecx, -0x250(%ebp)\n"
        "movl hud_fade_ammodisplay, %esi\n" /* ammoVal */
        "movss 0x2ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "mulss 8(%esi), %xmm0\n" /* ammoVal */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x264(%ebp)\n"
        "cvttss2si -0x264(%ebp), %eax\n"
        "movl %eax, -0x240(%ebp)\n" /* duration */
        "movl 0x2c5c8(%ebx), %edi\n" /* line 280 | weap, displayStartTime */
        /* { scope 2 */
        /* { scope 3 */
        "calll CL_GetKeyCatchers\n" /* line 101 */
        "testb $8, %al\n"
        "jne .Lf18a2ac_0018a67c\n"
        ".Lf18a2ac_0018a343:\n"
        "movl 0x2bdc8(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf18a2ac_0018a62e\n"
        ".Lf18a2ac_0018a351:\n"
        "movl $1, %eax\n"
        ".Lf18a2ac_0018a356:\n"
        "testl %eax, %eax\n" /* line 113 */
        "jne .Lf18a2ac_0018a369\n"
        "movl hud_enable, %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf18a2ac_0018a65b\n"
        ".Lf18a2ac_0018a369:\n"
        "pxor %xmm0, %xmm0\n" /* line 126 */
        "movaps %xmm0, %xmm1\n"
        /* } scope */
        /* } scope */
        ".Lf18a2ac_0018a370:\n"
        "movl -0x250(%ebp), %ecx\n" /* line 280 */
        "movss %xmm0, (%ecx)\n"
        "ucomiss %xmm1, %xmm0\n" /* line 281 */
        "jp .Lf18a2ac_0018a385\n"
        "je .Lf18a2ac_0018a2e3\n"
        ".Lf18a2ac_0018a385:\n"
        "movl 0x195f584, %eax\n" /* line 284 */
        "movl (%eax), %ebx\n" /* weap */
        "movl 0x24(%ebx), %ecx\n" /* weap */
        "movl 0xd8(%ecx), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %eax, %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "movl 0x195f5cc, %eax\n"
        "movl (%eax), %eax\n"
        "leal (%eax, %edx, 4), %edi\n" /* displayStartTime */
        "leal 0x25bc4(%ebx), %eax\n" /* line 285 | weap */
        "movl %eax, -0x248(%ebp)\n" /* ps */
        "testb $0x80, 0x1a(%ecx)\n" /* line 290 */
        "jne .Lf18a2ac_0018a635\n"
        ".Lf18a2ac_0018a3bf:\n"
        "movl 0x1b8(%edi), %ebx\n" /* line 293 | displayStartTime, weap */
        ".Lf18a2ac_0018a3c5:\n"
        "testl %ebx, %ebx\n" /* line 295 | weap */
        "je .Lf18a2ac_0018a2e3\n"
        "movl %ebx, 4(%esp)\n" /* line 303 | weap */
        "movl -0x248(%ebp), %edx\n" /* ps */
        "movl %edx, (%esp)\n"
        "calll BG_GetTotalAmmoReserve\n"
        "movl %eax, %esi\n" /* ammoVal */
        "movl %ebx, (%esp)\n" /* line 305 | weap */
        "calll BG_WeaponIsClipOnly\n"
        "testl %eax, %eax\n"
        "je .Lf18a2ac_0018a9c8\n"
        "movl $0xffffffff, %eax\n"
        ".Lf18a2ac_0018a3f6:\n"
        "movb $0, -0x242(%ebp)\n" /* drawClip */
        ".Lf18a2ac_0018a3fd:\n"
        "testl %esi, %esi\n" /* line 315 | ammoVal */
        "js .Lf18a2ac_0018aa2d\n"
        "cmpl $0x3e7, %esi\n" /* line 317 | ammoVal */
        "jle .Lf18a2ac_0018a412\n"
        "movl $0x3e7, %esi\n" /* ammoVal */
        ".Lf18a2ac_0018a412:\n"
        "movl $1, %edi\n" /* displayStartTime */
        ".Lf18a2ac_0018a417:\n"
        "cmpb $0, -0x242(%ebp)\n" /* line 320 | drawClip */
        "jne .Lf18a2ac_0018a99e\n"
        "movb $0, -0x241(%ebp)\n" /* lowClip */
        ".Lf18a2ac_0018a42b:\n"
        "movl %edi, %eax\n" /* line 326 | displayStartTime */
        "testb %al, %al\n"
        "jne .Lf18a2ac_0018a978\n"
        "xorl %esi, %esi\n" /* ammoVal */
        ".Lf18a2ac_0018a437:\n"
        "cmpb $0, -0x241(%ebp)\n" /* line 332 | lowClip */
        "je .Lf18a2ac_0018a68e\n"
        "movl 0x195f584, %ebx\n" /* line 334 | weap */
        "movl (%ebx), %ecx\n" /* weap */
        "movl 0x2bdf8(%ecx), %eax\n"
        "movl 0x25bb0(%ecx), %edx\n"
        "cmpl %edx, %eax\n"
        "jle .Lf18a2ac_0018a95c\n"
        ".Lf18a2ac_0018a460:\n"
        "movl %edx, 0x2bdf8(%ecx)\n" /* line 335 */
        ".Lf18a2ac_0018a466:\n"
        "movl $0x3f63d70a, -0x28(%ebp)\n" /* line 191 | flashColor */
        "movl $0x3e3851ec, -0x24(%ebp)\n" /* line 192 */
        "movl $0x3c23d70a, -0x20(%ebp)\n" /* line 193 */
        "movl (%ebx), %eax\n" /* line 338 | weap */
        "movl 0x2bdf8(%eax), %edx\n"
        "subl 0x25bb0(%eax), %edx\n"
        "addl $0x320, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "divss 0x2ed958, %xmm0\n" /* 800.0f */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl -0x250(%ebp), %edx\n" /* line 339 */
        "movss (%edx), %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf18a2ac_0018a96e\n"
        ".Lf18a2ac_0018a4b3:\n"
        "movl %esi, %eax\n" /* line 343 | ammoVal */
        "testb %al, %al\n"
        "je .Lf18a2ac_0018a753\n"
        "movl $0x3f63d70a, -0x38(%ebp)\n" /* line 191 | ammoColor */
        "movl $0x3e3851ec, -0x34(%ebp)\n" /* line 192 */
        "movl $0x3c23d70a, -0x30(%ebp)\n" /* line 193 */
        ".Lf18a2ac_0018a4d2:\n"
        "movss %xmm1, -0x2c(%ebp)\n" /* line 347 */
        "cmpb $0, -0x242(%ebp)\n" /* line 350 | drawClip */
        "je .Lf18a2ac_0018a69d\n"
        "movl %edi, %ecx\n" /* displayStartTime */
        "testb %cl, %cl\n"
        "jne .Lf18a2ac_0018a76f\n"
        "movl -0x254(%ebp), %edx\n" /* line 365 */
        "movss (%edx), %xmm0\n"
        "movss %xmm0, -0x23c(%ebp)\n"
        "movss 8(%edx), %xmm1\n"
        "movss -0x25c(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl -0x258(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0x138(%ebp), %ebx\n" /* clipString, weap */
        "movl %ebx, (%esp)\n" /* weap */
        "movss %xmm1, -0x278(%ebp)\n"
        "calll UI_TextWidth\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0x278(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "mulss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "addss -0x23c(%ebp), %xmm1\n"
        "movss %xmm1, -0x23c(%ebp)\n"
        "movl 0xc(%ebp), %edx\n" /* line 366 | textStyle */
        "movl %edx, 0x24(%esp)\n"
        "movl -0x260(%ebp), %ecx\n"
        "movl %ecx, 0x20(%esp)\n"
        "movss -0x25c(%ebp), %xmm0\n"
        "movss %xmm0, 0x1c(%esp)\n"
        "movl -0x254(%ebp), %edx\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movl -0x258(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* weap */
        "calll UI_DrawText\n"
        "cmpb $0, -0x241(%ebp)\n" /* line 367 | lowClip */
        "je .Lf18a2ac_0018a2e3\n"
        "movl 0xc(%ebp), %edx\n" /* line 368 | textStyle */
        "movl %edx, 0x24(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* flashColor */
        "movl %eax, 0x20(%esp)\n"
        "movss -0x25c(%ebp), %xmm0\n"
        "movss %xmm0, 0x1c(%esp)\n"
        "movl -0x254(%ebp), %edx\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movss -0x23c(%ebp), %xmm0\n"
        ".Lf18a2ac_0018a609:\n"
        "movss %xmm0, 0xc(%esp)\n" /* line 373 */
        "movl -0x258(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* weap */
        "calll UI_DrawText\n"
        "jmp .Lf18a2ac_0018a2e3\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf18a2ac_0018a62e:\n"
        "xorl %eax, %eax\n" /* line 101 */
        "jmp .Lf18a2ac_0018a356\n"
        /* } scope */
        /* } scope */
        ".Lf18a2ac_0018a635:\n"
        "movl 0x2be50(%ebx), %esi\n" /* line 290 | weap, ammoVal */
        "testl %esi, %esi\n" /* ammoVal */
        "js .Lf18a2ac_0018a3bf\n"
        "calll BG_GetNumWeapons\n"
        "cmpl %eax, %esi\n" /* ammoVal */
        "jge .Lf18a2ac_0018a3bf\n"
        "movl 0x2be50(%ebx), %ebx\n" /* line 291 | weap */
        "jmp .Lf18a2ac_0018a3c5\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf18a2ac_0018a65b:\n"
        "pxor %xmm1, %xmm1\n" /* line 119 */
        "ucomiss 8(%esi), %xmm1\n"
        "jne .Lf18a2ac_0018a9fd\n"
        "jp .Lf18a2ac_0018a9fd\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jmp .Lf18a2ac_0018a370\n"
        ".Lf18a2ac_0018a67c:\n"
        "calll CL_GetDisplayHUDWithKeycatchUI\n" /* line 101 */
        "testb %al, %al\n"
        "je .Lf18a2ac_0018a351\n"
        "jmp .Lf18a2ac_0018a343\n"
        ".Lf18a2ac_0018a68e:\n"
        "movl -0x250(%ebp), %ecx\n"
        "movss (%ecx), %xmm1\n"
        "jmp .Lf18a2ac_0018a4b3\n"
        /* } scope */
        /* } scope */
        ".Lf18a2ac_0018a69d:\n"
        "movl %edi, %edx\n" /* line 370 | displayStartTime */
        "testb %dl, %dl\n"
        "je .Lf18a2ac_0018a2e3\n"
        "movl -0x254(%ebp), %ecx\n" /* line 372 */
        "movss (%ecx), %xmm0\n"
        "movss %xmm0, -0x24c(%ebp)\n"
        "movss 8(%ecx), %xmm1\n"
        "movss -0x25c(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl -0x258(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0x238(%ebp), %ebx\n" /* ammoString, weap */
        "movl %ebx, (%esp)\n" /* weap */
        "movss %xmm1, -0x278(%ebp)\n"
        "calll UI_TextWidth\n"
        "movl 0xc(%ebp), %edx\n" /* line 373 | textStyle */
        "movl %edx, 0x24(%esp)\n"
        "leal -0x38(%ebp), %edx\n" /* ammoColor */
        "movl %edx, 0x20(%esp)\n"
        "movss -0x25c(%ebp), %xmm0\n"
        "movss %xmm0, 0x1c(%esp)\n"
        "movl -0x254(%ebp), %ecx\n"
        "movl 0x14(%ecx), %edx\n"
        "movl %edx, 0x18(%esp)\n"
        "movl 0x10(%ecx), %edx\n"
        "movl %edx, 0x14(%esp)\n"
        "movl 4(%ecx), %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0x278(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "mulss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "addss -0x24c(%ebp), %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "jmp .Lf18a2ac_0018a609\n"
        ".Lf18a2ac_0018a753:\n"
        "movl -0x260(%ebp), %edx\n" /* line 199 */
        "movl (%edx), %eax\n"
        "movl %eax, -0x38(%ebp)\n" /* ammoColor */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x34(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x30(%ebp)\n"
        "jmp .Lf18a2ac_0018a4d2\n"
        ".Lf18a2ac_0018a76f:\n"
        "movl 0xc(%ebp), %eax\n" /* line 352 | textStyle */
        "movl %eax, 0x24(%esp)\n"
        "movl -0x260(%ebp), %edx\n"
        "movl %edx, 0x20(%esp)\n"
        "movss -0x25c(%ebp), %xmm0\n"
        "movss %xmm0, 0x1c(%esp)\n"
        "movl -0x254(%ebp), %edx\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl (%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x258(%ebp), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "leal -0x138(%ebp), %ebx\n" /* clipString, weap */
        "movl %ebx, (%esp)\n" /* weap */
        "calll UI_DrawText\n"
        "cmpb $0, -0x241(%ebp)\n" /* line 353 | lowClip */
        "jne .Lf18a2ac_0018aa40\n"
        ".Lf18a2ac_0018a7dc:\n"
        "movl -0x254(%ebp), %eax\n" /* line 356 */
        "movss (%eax), %xmm1\n"
        "addss 8(%eax), %xmm1\n"
        "movss -0x25c(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl -0x258(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0x238(%ebp), %ebx\n" /* ammoString, weap */
        "movl %ebx, (%esp)\n" /* weap */
        "movss %xmm1, -0x278(%ebp)\n"
        "calll UI_TextWidth\n"
        "movl 0xc(%ebp), %edx\n" /* line 357 | textStyle */
        "movl %edx, 0x24(%esp)\n"
        "leal -0x38(%ebp), %esi\n" /* ammoColor, ammoVal */
        "movl %esi, 0x20(%esp)\n" /* ammoVal */
        "movss -0x25c(%ebp), %xmm0\n"
        "movss %xmm0, 0x1c(%esp)\n"
        "movl -0x254(%ebp), %ecx\n"
        "movl 0x14(%ecx), %edx\n"
        "movl %edx, 0x18(%esp)\n"
        "movl 0x10(%ecx), %edx\n"
        "movl %edx, 0x14(%esp)\n"
        "movl 4(%ecx), %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0x278(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movl -0x258(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* weap */
        "calll UI_DrawText\n"
        "movl -0x254(%ebp), %edx\n" /* line 360 */
        "movss (%edx), %xmm2\n"
        "movss 8(%edx), %xmm1\n"
        "movss -0x25c(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl -0x258(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x22290c, (%esp)\n" /* "|" */
        "movss %xmm1, -0x278(%ebp)\n"
        "movss %xmm2, -0x288(%ebp)\n"
        "calll UI_TextWidth\n"
        "movl 0xc(%ebp), %edx\n" /* line 361 | textStyle */
        "movl %edx, 0x24(%esp)\n"
        "movl %esi, 0x20(%esp)\n" /* ammoVal */
        "movss -0x25c(%ebp), %xmm0\n"
        "movss %xmm0, 0x1c(%esp)\n"
        "movl -0x254(%ebp), %ecx\n"
        "movl 0x14(%ecx), %edx\n"
        "movl %edx, 0x18(%esp)\n"
        "movl 0x10(%ecx), %edx\n"
        "movl %edx, 0x14(%esp)\n"
        "movl 4(%ecx), %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0x278(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "mulss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "movss -0x288(%ebp), %xmm2\n"
        "addss %xmm1, %xmm2\n"
        "subss 0x2ed6d4, %xmm2\n" /* 5.0f */
        "movss %xmm2, 0xc(%esp)\n"
        "movl -0x258(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl $0x22290c, (%esp)\n" /* "|" */
        "calll UI_DrawText\n"
        "jmp .Lf18a2ac_0018a2e3\n"
        ".Lf18a2ac_0018a95c:\n"
        "addl $0x320, %eax\n" /* line 334 */
        "cmpl %eax, %edx\n"
        "jle .Lf18a2ac_0018a466\n"
        "jmp .Lf18a2ac_0018a460\n"
        ".Lf18a2ac_0018a96e:\n"
        "movss %xmm1, -0x1c(%ebp)\n" /* line 340 */
        "jmp .Lf18a2ac_0018a4b3\n"
        ".Lf18a2ac_0018a978:\n"
        "movl %esi, 8(%esp)\n" /* line 328 | ammoVal */
        "movl $0x2afbe4, 4(%esp)\n" /* "%3i" */
        "leal -0x238(%ebp), %eax\n" /* ammoString */
        "movl %eax, (%esp)\n"
        "calll sprintf\n"
        "calll CG_CheckPlayerForLowAmmo\n" /* line 329 */
        "movl %eax, %esi\n" /* ammoVal */
        "jmp .Lf18a2ac_0018a437\n"
        ".Lf18a2ac_0018a99e:\n"
        "movl %eax, 8(%esp)\n" /* line 322 */
        "movl $0x2afbe0, 4(%esp)\n" /* "%2i" */
        "leal -0x138(%ebp), %eax\n" /* clipString */
        "movl %eax, (%esp)\n"
        "calll sprintf\n"
        "calll CG_CheckPlayerForLowClip\n" /* line 323 */
        "movb %al, -0x241(%ebp)\n" /* lowClip */
        "jmp .Lf18a2ac_0018a42b\n"
        ".Lf18a2ac_0018a9c8:\n"
        "movl %ebx, (%esp)\n" /* line 308 | weap */
        "calll BG_ClipForWeapon\n"
        "movl -0x248(%ebp), %ecx\n" /* ps */
        "movl 0x344(%ecx, %eax, 4), %eax\n"
        "testl %eax, %eax\n" /* line 310 */
        "js .Lf18a2ac_0018a3f6\n"
        "cmpl $0x3e7, %eax\n" /* line 312 */
        "jle .Lf18a2ac_0018aa34\n"
        "movl $0x3e7, %eax\n"
        "movb $1, -0x242(%ebp)\n" /* drawClip */
        "jmp .Lf18a2ac_0018a3fd\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf18a2ac_0018a9fd:\n"
        "movl $0x2bc, 8(%esp)\n" /* line 122 */
        "movl -0x240(%ebp), %edx\n" /* duration */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll CG_FadeColor\n"
        "testl %eax, %eax\n" /* line 123 */
        "je .Lf18a2ac_0018a369\n"
        "movss 0xc(%eax), %xmm0\n" /* line 126 */
        "pxor %xmm1, %xmm1\n"
        "jmp .Lf18a2ac_0018a370\n"
        /* } scope */
        /* } scope */
        ".Lf18a2ac_0018aa2d:\n"
        "xorl %edi, %edi\n" /* line 315 | displayStartTime */
        "jmp .Lf18a2ac_0018a417\n"
        ".Lf18a2ac_0018aa34:\n"
        "movb $1, -0x242(%ebp)\n" /* line 312 | drawClip */
        "jmp .Lf18a2ac_0018a3fd\n"
        ".Lf18a2ac_0018aa40:\n"
        "movl 0xc(%ebp), %eax\n" /* line 354 | textStyle */
        "movl %eax, 0x24(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* flashColor */
        "movl %eax, 0x20(%esp)\n"
        "movss -0x25c(%ebp), %xmm0\n"
        "movss %xmm0, 0x1c(%esp)\n"
        "movl -0x254(%ebp), %edx\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl (%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x258(%ebp), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* weap */
        "calll UI_DrawText\n"
        "jmp .Lf18a2ac_0018a7dc\n"
    );
}

/* line 1795 */
__attribute__((naked))
void CG_OwnerDraw(float x, float y, float w, float h, int horzAlign, int vertAlign, float text_x, float text_y, int ownerDraw, int ownerDrawFlags, int align, float special, struct Font_s *font, float scale, vec_t *color, MaterialHandle material, int textStyle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1795 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x19c, %esp\n"
        "movl 0x1c(%ebp), %edi\n" /* vertAlign */
        /* { scope 1: drawColor, y, w, centerX, ... */
        "movl 8(%ebp), %eax\n" /* line 1799 | x */
        "movl %eax, -0x54(%ebp)\n" /* rect */
        "movl 0xc(%ebp), %eax\n" /* line 1800 | y */
        "movl %eax, -0x50(%ebp)\n"
        "movl 0x10(%ebp), %eax\n" /* line 1801 | w */
        "movl %eax, -0x4c(%ebp)\n"
        "movl 0x14(%ebp), %eax\n" /* line 1802 | h */
        "movl %eax, -0x48(%ebp)\n"
        "movl 0x18(%ebp), %eax\n" /* line 1803 | horzAlign */
        "movl %eax, -0x44(%ebp)\n"
        "movl %edi, -0x40(%ebp)\n" /* line 1804 | vertAlign */
        "movl 0x28(%ebp), %eax\n" /* line 1806 | ownerDraw */
        "subl $5, %eax\n"
        "cmpl $0x68, %eax\n"
        "ja .Lf18aa9c_0018adab\n"
        "jmpl *0x302db0(, %eax, 4)\n"
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        "movl 0x195f66c, %eax\n" /* line 775 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf18aa9c_0018adab\n"
        "movl 0x195f584, %eax\n" /* line 743 */
        "movl (%eax), %ebx\n" /* weapIndex */
        "movl 0x24(%ebx), %eax\n" /* weapIndex */
        "addl $0xc, %eax\n"
        "movl 0x12c(%eax), %edx\n" /* line 746 */
        "testl %edx, %edx\n"
        "je .Lf18aa9c_0018c1c5\n"
        "movl 0x134(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf18aa9c_0018c1c5\n"
        "cmpl $6, 4(%eax)\n"
        "je .Lf18aa9c_0018c1c5\n"
        "cvtsi2ssl %edx, %xmm2\n" /* line 748 */
        "cvtsi2ssl %ecx, %xmm0\n"
        "divss %xmm0, %xmm2\n"
        "ucomiss 0x2ed5e8, %xmm2\n" /* line 749 | 0.0f */
        "jb .Lf18aa9c_0018c1bf\n"
        ".Lf18aa9c_0018ab3f:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 751 | 1.0f */
        "ucomiss %xmm0, %xmm2\n"
        "jbe .Lf18aa9c_0018ab4f\n"
        "movaps %xmm0, %xmm2\n"
        ".Lf18aa9c_0018ab4f:\n"
        "movl 0x40(%ebp), %eax\n" /* line 779 | color */
        "addl $0xc, %eax\n"
        "movl %eax, -0xb8(%ebp)\n"
        "movl hud_fade_healthbar, %esi\n" /* ps */
        "movss 0x2ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "mulss 8(%esi), %xmm0\n" /* weapInfo */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "movss %xmm2, -0x148(%ebp)\n"
        "calll floorf\n"
        "fstps -0x118(%ebp)\n"
        "cvttss2si -0x118(%ebp), %edi\n" /* displayStartTime */
        "movl 0x2c5c4(%ebx), %ebx\n" /* line 779 | displayStartTime */
        /* { scope 3 */
        /* { scope 4 */
        "calll CL_GetKeyCatchers\n" /* line 101 */
        "testb $8, %al\n"
        "movss -0x148(%ebp), %xmm2\n"
        "jne .Lf18aa9c_0018c269\n"
        ".Lf18aa9c_0018abb1:\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x2bdc8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf18aa9c_0018c27e\n"
        "xorl %eax, %eax\n"
        ".Lf18aa9c_0018abc8:\n"
        "testl %eax, %eax\n" /* line 113 */
        "jne .Lf18aa9c_0018abdb\n"
        "movl hud_enable, %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf18aa9c_0018c43f\n"
        ".Lf18aa9c_0018abdb:\n"
        "pxor %xmm3, %xmm3\n" /* line 126 */
        "movaps %xmm3, %xmm0\n"
        /* } scope */
        /* } scope */
        ".Lf18aa9c_0018abe2:\n"
        "movl -0xb8(%ebp), %edx\n" /* line 779 */
        "movss %xmm0, (%edx)\n"
        "ucomiss %xmm3, %xmm0\n" /* line 780 */
        "jp .Lf18aa9c_0018abf7\n"
        "je .Lf18aa9c_0018adab\n"
        ".Lf18aa9c_0018abf7:\n"
        "movl 0x195f584, %ebx\n" /* line 783 | displayStartTime */
        "movl (%ebx), %eax\n" /* displayStartTime */
        "movl 0x24(%eax), %esi\n" /* ps */
        "addl $0xc, %esi\n" /* ps */
        "movss 0x2ed5d0, %xmm4\n" /* line 45 | 1.0f */
        "movaps %xmm2, %xmm1\n"
        "subss %xmm4, %xmm1\n"
        "movaps %xmm4, %xmm0\n"
        "cmpnltss %xmm3, %xmm1\n"
        "andps %xmm1, %xmm0\n"
        "andnps %xmm2, %xmm1\n"
        "orps %xmm0, %xmm1\n"
        "movaps %xmm3, %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "movaps %xmm1, %xmm5\n"
        "cmpltss %xmm3, %xmm0\n"
        "andps %xmm0, %xmm5\n"
        "andnps %xmm3, %xmm0\n"
        "orps %xmm5, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "ucomiss %xmm3, %xmm2\n" /* line 787 */
        "jbe .Lf18aa9c_0018c5c4\n"
        "movl -0x54(%ebp), %ecx\n" /* line 789 | rect */
        "movl -0x50(%ebp), %ebx\n" /* line 790 | displayStartTime */
        "movaps %xmm2, %xmm3\n" /* line 791 */
        "mulss -0x4c(%ebp), %xmm3\n"
        "movl -0x48(%ebp), %edx\n" /* line 792 */
        "ucomiss 0x2ed5d8, %xmm1\n" /* line 794 | 0.5f */
        "jbe .Lf18aa9c_0018c41d\n"
        "movaps %xmm4, %xmm0\n" /* line 796 */
        "subss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "movl 0x40(%ebp), %eax\n" /* color */
        "mulss (%eax), %xmm1\n"
        "movss %xmm1, (%eax)\n"
        "mulss 8(%eax), %xmm0\n" /* line 797 */
        "movss %xmm0, 8(%eax)\n"
        ".Lf18aa9c_0018ac8a:\n"
        "movl 0x44(%ebp), %eax\n" /* line 805 | material */
        "movl %eax, 0x2c(%esp)\n"
        "movl 0x40(%ebp), %edi\n" /* color, duration */
        "movl %edi, 0x28(%esp)\n" /* duration */
        "movl $0x3f800000, 0x24(%esp)\n"
        "movss %xmm2, 0x20(%esp)\n"
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movss %xmm3, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* displayStartTime */
        "movl %ecx, (%esp)\n"
        "movss %xmm2, -0x148(%ebp)\n"
        "calll CL_DrawStretchPic\n"
        "movss -0x148(%ebp), %xmm2\n"
        "movl 0x195f584, %edx\n"
        ".Lf18aa9c_0018acf0:\n"
        "movl (%edx), %eax\n" /* line 808 */
        "movl 0xcc(%esi), %edx\n" /* ps */
        "cmpl %edx, 0x2be04(%eax)\n"
        "je .Lf18aa9c_0018c4f5\n"
        "movl %edx, 0x2be04(%eax)\n" /* line 810 */
        ".Lf18aa9c_0018ad0a:\n"
        "movss %xmm2, 0x2be08(%eax)\n" /* line 811 */
        "movl $1, 0x2be00(%eax)\n" /* line 812 */
        ".Lf18aa9c_0018ad1c:\n"
        "movl 0x195f584, %ebx\n" /* line 838 | displayStartTime */
        "movl (%ebx), %ecx\n" /* displayStartTime */
        "movss 0x2be08(%ecx), %xmm3\n"
        "ucomiss %xmm2, %xmm3\n"
        "jbe .Lf18aa9c_0018adab\n"
        "movss -0x4c(%ebp), %xmm0\n" /* line 840 */
        "movaps %xmm2, %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "addss -0x54(%ebp), %xmm1\n" /* rect */
        "movl $0x3f800000, %eax\n" /* line 191 */
        "movl 0x40(%ebp), %edi\n" /* color */
        "movl %eax, (%edi)\n"
        "xorl %edx, %edx\n" /* line 192 */
        "movl %edx, 4(%edi)\n"
        "movl %edx, 8(%edi)\n" /* line 193 */
        "movl 0x44(%ebp), %ebx\n" /* line 846 | material, displayStartTime */
        "movl %ebx, 0x2c(%esp)\n" /* displayStartTime */
        "movl %edi, 0x28(%esp)\n" /* duration */
        "movl %eax, 0x24(%esp)\n"
        "movl 0x2be08(%ecx), %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl %edx, 0x1c(%esp)\n"
        "movss %xmm2, 0x18(%esp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "subss %xmm2, %xmm3\n"
        "mulss %xmm3, %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movss %xmm1, (%esp)\n"
        "calll CL_DrawStretchPic\n"
        /* } scope */
        /* } scope */
        ".Lf18aa9c_0018adab:\n"
        "addl $0x19c, %esp\n" /* line 1918 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: drawColor, y, w, centerX, ... */
        "leal -0x54(%ebp), %eax\n" /* line 1812 | rect */
        "movl $0, 8(%esp)\n"
        ".Lf18aa9c_0018adc1:\n"
        "movl 0x48(%ebp), %edx\n" /* line 1824 | textStyle */
        "movl %edx, 4(%esp)\n"
        "movl 0x44(%ebp), %ebx\n" /* material, x */
        "movl %ebx, (%esp)\n" /* x */
        "movl 0x40(%ebp), %ecx\n" /* color */
        "movss 0x3c(%ebp), %xmm0\n" /* scale */
        "movl 0x38(%ebp), %edx\n" /* font */
        "calll CG_DrawPlayerAmmoValue\n"
        "jmp .Lf18aa9c_0018adab\n"
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        "movl 0x195f584, %eax\n" /* line 240 */
        "movl (%eax), %ebx\n"
        "movl 0x25c98(%ebx), %esi\n"
        "testl %esi, %esi\n"
        "je .Lf18aa9c_0018adab\n"
        "movl hud_fade_ammodisplay, %esi\n" /* line 243 */
        "movss 0x2ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "mulss 8(%esi), %xmm0\n" /* weapInfo */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x108(%ebp)\n"
        "cvttss2si -0x108(%ebp), %eax\n"
        "movl %eax, -0x104(%ebp)\n" /* duration */
        "movl 0x2c5c8(%ebx), %edi\n" /* line 243 | displayStartTime */
        /* { scope 3 */
        /* { scope 4 */
        "calll CL_GetKeyCatchers\n" /* line 101 */
        "testb $8, %al\n"
        "jne .Lf18aa9c_0018c328\n"
        ".Lf18aa9c_0018ae3d:\n"
        "movl 0x2bdc8(%ebx), %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lf18aa9c_0018c335\n"
        "xorl %eax, %eax\n"
        ".Lf18aa9c_0018ae4d:\n"
        "testl %eax, %eax\n" /* line 113 */
        "jne .Lf18aa9c_0018ae60\n"
        "movl hud_enable, %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf18aa9c_0018c537\n"
        ".Lf18aa9c_0018ae60:\n"
        "pxor %xmm3, %xmm3\n" /* line 126 */
        "movaps %xmm3, %xmm0\n"
        /* } scope */
        /* } scope */
        ".Lf18aa9c_0018ae67:\n"
        "movss %xmm0, -0x20(%ebp)\n" /* line 243 */
        "ucomiss %xmm3, %xmm0\n" /* line 244 */
        "jp .Lf18aa9c_0018ae77\n"
        "je .Lf18aa9c_0018adab\n"
        ".Lf18aa9c_0018ae77:\n"
        "calll CG_CheckPlayerForLowAmmo\n" /* line 247 */
        "testb %al, %al\n"
        "je .Lf18aa9c_0018c5ab\n"
        "movl $0x3f63d70a, -0x2c(%ebp)\n" /* line 191 | drawColor */
        "movl $0x3e3851ec, -0x28(%ebp)\n" /* line 192 */
        "movl $0x3c23d70a, -0x24(%ebp)\n" /* line 193 */
        ".Lf18aa9c_0018ae99:\n"
        "movl 0x44(%ebp), %edi\n" /* line 252 | material, displayStartTime */
        "movl %edi, 0x1c(%esp)\n" /* displayStartTime */
        "leal -0x2c(%ebp), %eax\n" /* drawColor */
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        ".Lf18aa9c_0018aea3:\n"
        "movl %eax, 0x18(%esp)\n" /* line 478 */
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x54(%ebp), %eax\n" /* rect */
        "movl %eax, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        "jmp .Lf18aa9c_0018adab\n"
        /* } scope */
        "movl 0x48(%ebp), %edi\n" /* line 1827 | textStyle, vertAlign */
        "movl %edi, 0x10(%esp)\n" /* vertAlign */
        "movss 0x3c(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 0xc(%esp)\n"
        "movl 0x38(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl 0x40(%ebp), %edx\n" /* color */
        "movl %edx, 4(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* rect */
        "movl %eax, (%esp)\n"
        "calll CG_DrawPlayerStance\n"
        "jmp .Lf18aa9c_0018adab\n"
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        "movl 0x40(%ebp), %edi\n" /* line 466 | color, displayStartTime */
        "addl $0xc, %edi\n" /* displayStartTime */
        "movl 0x195f584, %eax\n"
        "movl (%eax), %ebx\n" /* weapIndex */
        "movl 0x2be54(%ebx), %eax\n" /* weapIndex */
        "movl %eax, -0xfc(%ebp)\n" /* displayStartTime */
        "movl hud_fade_ammodisplay, %esi\n" /* fadeDvar */
        /* { scope 3 */
        /* { scope 4 */
        "calll CL_GetKeyCatchers\n" /* line 101 */
        "testb $8, %al\n"
        "jne .Lf18aa9c_0018c213\n"
        ".Lf18aa9c_0018af36:\n"
        "movl 0x2bdc8(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf18aa9c_0018c220\n"
        "xorl %eax, %eax\n"
        ".Lf18aa9c_0018af46:\n"
        "testl %eax, %eax\n" /* line 113 */
        "jne .Lf18aa9c_0018af59\n"
        "movl hud_enable, %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf18aa9c_0018c377\n"
        ".Lf18aa9c_0018af59:\n"
        "pxor %xmm3, %xmm3\n" /* line 126 */
        "movaps %xmm3, %xmm0\n"
        /* } scope */
        /* } scope */
        ".Lf18aa9c_0018af60:\n"
        "movss %xmm0, (%edi)\n" /* line 466 | displayStartTime */
        "ucomiss %xmm3, %xmm0\n" /* line 467 */
        "jp .Lf18aa9c_0018af6f\n"
        "je .Lf18aa9c_0018adab\n"
        ".Lf18aa9c_0018af6f:\n"
        "movl 0x195f584, %ebx\n" /* line 159 */
        "movl (%ebx), %esi\n"
        "movl 0x2be50(%esi), %ebx\n"
        "testl %ebx, %ebx\n"
        "js .Lf18aa9c_0018afa7\n"
        "calll BG_GetNumWeapons\n"
        "cmpl %eax, %ebx\n"
        "jge .Lf18aa9c_0018afa7\n"
        "movl 0x2be50(%esi), %ebx\n"
        "movl %ebx, %eax\n"
        "sarl $5, %eax\n"
        "movl %ebx, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl 0x26108(%esi, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf18aa9c_0018afb5\n"
        ".Lf18aa9c_0018afa7:\n"
        "movl 0x195f584, %edi\n" /* line 161 */
        "movl (%edi), %eax\n"
        "movl 0x25c98(%eax), %ebx\n"
        ".Lf18aa9c_0018afb5:\n"
        "testl %ebx, %ebx\n" /* line 471 | weapIndex */
        "je .Lf18aa9c_0018adab\n"
        "movl 0x195f5c8, %eax\n" /* line 475 */
        "movl (%eax), %edx\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* weapIndex */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n" /* weapIndex */
        "movl 0x13c(%edx, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf18aa9c_0018adab\n"
        "movl %eax, 0x1c(%esp)\n" /* line 478 */
        "movl 0x40(%ebp), %eax\n" /* color */
        "jmp .Lf18aa9c_0018aea3\n"
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        "movl 0x40(%ebp), %edx\n" /* line 1133 | color */
        "addl $0xc, %edx\n"
        "movl %edx, -0xf8(%ebp)\n"
        "movl hud_fade_compass, %esi\n" /* h */
        "movss 0x2ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "mulss 8(%esi), %xmm0\n" /* weapInfo */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x10c(%ebp)\n"
        "cvttss2si -0x10c(%ebp), %ebx\n" /* weapIndex */
        "movl %ebx, -0xec(%ebp)\n" /* weapIndex, duration */
        "movl 0x195f584, %eax\n" /* line 1133 */
        "movl (%eax), %ebx\n" /* x */
        "movl 0x2c5c0(%ebx), %edi\n" /* x, displayStartTime */
        /* { scope 3 */
        /* { scope 4 */
        "calll CL_GetKeyCatchers\n" /* line 101 */
        "testb $8, %al\n"
        "jne .Lf18aa9c_0018c1fc\n"
        ".Lf18aa9c_0018b047:\n"
        "movl 0x2bdc8(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf18aa9c_0018c209\n"
        "xorl %eax, %eax\n"
        ".Lf18aa9c_0018b057:\n"
        "testl %eax, %eax\n" /* line 113 */
        "jne .Lf18aa9c_0018b06a\n"
        "movl hud_enable, %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf18aa9c_0018c398\n"
        ".Lf18aa9c_0018b06a:\n"
        "pxor %xmm3, %xmm3\n" /* line 126 */
        "movaps %xmm3, %xmm0\n"
        /* } scope */
        /* } scope */
        ".Lf18aa9c_0018b071:\n"
        "movl -0xf8(%ebp), %edx\n" /* line 1133 */
        "movss %xmm0, (%edx)\n"
        "ucomiss %xmm3, %xmm0\n" /* line 1134 */
        "jp .Lf18aa9c_0018b086\n"
        "je .Lf18aa9c_0018adab\n"
        ".Lf18aa9c_0018b086:\n"
        "movl -0x54(%ebp), %ebx\n" /* line 1114 | rect, displayStartTime */
        "movss -0x48(%ebp), %xmm1\n" /* line 1115 */
        "movl 0x195f640, %eax\n"
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "movss %xmm0, -0xe8(%ebp)\n"
        "subss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "mulss %xmm1, %xmm0\n"
        "movss -0x50(%ebp), %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "movss %xmm2, -0xf4(%ebp)\n" /* y */
        "movss -0xe8(%ebp), %xmm3\n" /* line 1116 */
        "mulss -0x4c(%ebp), %xmm3\n"
        "movss %xmm3, -0xf0(%ebp)\n" /* w */
        "movss %xmm1, -0x138(%ebp)\n" /* line 1139 */
        "calll CG_UpdateCompassOrientation\n"
        "movl 0x44(%ebp), %eax\n" /* line 1141 | material */
        "movl %eax, 0x20(%esp)\n"
        "movl 0x40(%ebp), %edx\n" /* color */
        "movl %edx, 0x1c(%esp)\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x2c5b0(%eax), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movss -0x138(%ebp), %xmm1\n"
        "mulss -0xe8(%ebp), %xmm1\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movss -0xf0(%ebp), %xmm0\n" /* w */
        "movss %xmm0, 8(%esp)\n"
        "movss -0xf4(%ebp), %xmm1\n" /* y */
        "movss %xmm1, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* x */
        "calll CG_DrawRotatedPic\n"
        "jmp .Lf18aa9c_0018adab\n"
        /* } scope */
        "movl 0x40(%ebp), %eax\n" /* line 1866 | color */
        "movl %eax, 8(%esp)\n"
        "movl 0x44(%ebp), %edx\n" /* material */
        "movl %edx, 4(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* rect */
        "movl %eax, (%esp)\n"
        "calll CG_DrawPlayerCompassBack\n"
        "jmp .Lf18aa9c_0018adab\n"
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        "movl hud_fade_compass, %esi\n" /* line 1206 | objNum */
        "movss 0x2ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "mulss 8(%esi), %xmm0\n" /* weapInfo */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x110(%ebp)\n"
        "cvttss2si -0x110(%ebp), %ebx\n" /* weapIndex */
        "movl %ebx, -0xc0(%ebp)\n" /* weapIndex, duration */
        "movl 0x195f584, %eax\n" /* line 1206 */
        "movl (%eax), %ebx\n" /* x */
        "movl 0x2c5c0(%ebx), %edi\n" /* x, displayStartTime */
        /* { scope 3 */
        /* { scope 4 */
        "calll CL_GetKeyCatchers\n" /* line 101 */
        "testb $8, %al\n"
        "jne .Lf18aa9c_0018c1e5\n"
        ".Lf18aa9c_0018b1be:\n"
        "movl 0x2bdc8(%ebx), %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lf18aa9c_0018c1f2\n"
        "xorl %eax, %eax\n"
        ".Lf18aa9c_0018b1ce:\n"
        "testl %eax, %eax\n" /* line 113 */
        "jne .Lf18aa9c_0018adab\n"
        "movl hud_enable, %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf18aa9c_0018adab\n"
        "pxor %xmm0, %xmm0\n" /* line 119 */
        "ucomiss 8(%esi), %xmm0\n"
        "jne .Lf18aa9c_0018c3b9\n"
        "jp .Lf18aa9c_0018c3b9\n"
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "movss %xmm1, -0xc8(%ebp)\n" /* fadeAlpha */
        /* } scope */
        /* } scope */
        ".Lf18aa9c_0018b209:\n"
        "calll CG_UpdateCompPointerOrientation\n" /* line 1210 */
        "movl 0x195f640, %eax\n" /* line 1212 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "movaps %xmm1, %xmm2\n"
        "mulss -0x4c(%ebp), %xmm2\n"
        "movss %xmm2, -0xdc(%ebp)\n" /* centerX */
        "movss 0x2ed5d8, %xmm2\n" /* 0.5f */
        "movss -0xdc(%ebp), %xmm3\n" /* centerX */
        "mulss %xmm2, %xmm3\n"
        "addss -0x54(%ebp), %xmm3\n" /* rect */
        "movss %xmm3, -0xdc(%ebp)\n" /* centerX */
        "movss -0x48(%ebp), %xmm0\n" /* line 1213 */
        "mulss %xmm1, %xmm2\n"
        "mulss %xmm0, %xmm2\n"
        "subss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "mulss %xmm1, %xmm0\n"
        "subss %xmm0, %xmm2\n"
        "addss -0x50(%ebp), %xmm2\n"
        "movss %xmm2, -0xd8(%ebp)\n" /* centerY */
        "movl 0x195f584, %eax\n" /* line 1215 */
        "movl (%eax), %ebx\n" /* x */
        "movl 0x24(%ebx), %eax\n" /* x */
        "movl 0xd8(%eax), %edx\n"
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "movl 0xe0914(%ebx, %eax, 8), %ecx\n" /* x */
        "testl %ecx, %ecx\n"
        "je .Lf18aa9c_0018adab\n"
        "xorl %esi, %esi\n" /* objNum */
        "jmp .Lf18aa9c_0018b2b1\n"
        ".Lf18aa9c_0018b2a5:\n"
        "addl $1, %esi\n" /* line 1218 | objNum */
        "cmpl $0x10, %esi\n" /* objNum */
        "je .Lf18aa9c_0018adab\n"
        ".Lf18aa9c_0018b2b1:\n"
        "movl 0x195f584, %edx\n" /* line 1220 */
        "movl (%edx), %ebx\n" /* x */
        "leal (, %esi, 4), %eax\n"
        "movl %esi, %edx\n" /* objNum */
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl 0x24(%ebx), %eax\n" /* x */
        "leal 0x5e0(%edx, %eax), %edx\n"
        "leal 0x10(%edx), %edi\n" /* displayStartTime */
        "cmpl $4, 0x10(%edx)\n" /* line 1221 */
        "jne .Lf18aa9c_0018b2a5\n"
        "movl 0x10(%edi), %ecx\n" /* line 1224 | displayStartTime */
        "cmpl $0x3ff, %ecx\n"
        "je .Lf18aa9c_0018c288\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "addl %ecx, %eax\n"
        "leal (%ecx, %eax, 8), %eax\n"
        "movl 0x195f5cc, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 0x1ec(%eax), %edx\n"
        /* { scope 3 */
        "movss 0x1ec(%eax), %xmm0\n" /* line 199 */
        "movss 4(%edx), %xmm1\n" /* line 200 */
        "movss 8(%edx), %xmm2\n" /* line 201 */
        /* } scope */
        /* { scope 3 */
        ".Lf18aa9c_0018b316:\n"
        "leal 0x28588(%ebx), %eax\n"
        /* } scope */
        /* { scope 3 */
        "subss 0x28588(%ebx), %xmm0\n" /* line 248 */
        "movss %xmm0, -0x2c(%ebp)\n" /* drawColor */
        "subss 4(%eax), %xmm1\n" /* line 249 */
        "movss %xmm1, -0x28(%ebp)\n"
        "subss 8(%eax), %xmm2\n" /* line 250 */
        "movss %xmm2, -0x24(%ebp)\n"
        /* } scope */
        "leal -0x2c(%ebp), %eax\n" /* line 1235 | drawColor */
        "movl %eax, (%esp)\n"
        "calll vectoyaw\n"
        "fstps -0x16c(%ebp)\n"
        "movss -0x16c(%ebp), %xmm0\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "subss 0x2c5b8(%eax), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll AngleNormalize360\n"
        "fstps -0xc4(%ebp)\n" /* objYaw */
        "movss -0x2c(%ebp), %xmm1\n" /* line 134 | drawColor */
        "movss -0x28(%ebp), %xmm0\n"
        "mulss %xmm1, %xmm1\n" /* line 81 */
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "sqrtss %xmm1, %xmm2\n"
        "movl 0x40(%ebp), %ebx\n" /* line 456 | color, weapIndex */
        "movl (%ebx), %eax\n" /* weapIndex */
        "movl %eax, -0x3c(%ebp)\n" /* newColor */
        "movl 4(%ebx), %eax\n" /* line 457 | weapIndex */
        "movl %eax, -0x38(%ebp)\n"
        "movl 8(%ebx), %eax\n" /* line 458 | weapIndex */
        "movl %eax, -0x34(%ebp)\n"
        "movl 0xc(%ebx), %eax\n" /* line 459 | weapIndex */
        "movl %eax, -0x30(%ebp)\n"
        "movl 0x195f654, %edx\n" /* line 1239 */
        "movl (%edx), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "ucomiss %xmm2, %xmm1\n"
        "jb .Lf18aa9c_0018c242\n"
        "movl $0x3f800000, -0x30(%ebp)\n" /* line 1241 */
        ".Lf18aa9c_0018b3c6:\n"
        "movl 0x195f644, %eax\n" /* line 1257 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm2, %xmm0\n"
        "jb .Lf18aa9c_0018c22a\n"
        "movl 0x195f650, %eax\n" /* line 1259 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* radiusScale */
        ".Lf18aa9c_0018b3e8:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 1275 | radiusScale */
        "movl %eax, (%esp)\n"
        "calll CG_ApplyCompassPointerRadiusScale\n"
        "cvtss2sd -0xc4(%ebp), %xmm0\n" /* line 1277 | objYaw */
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0xbc(%ebp)\n"
        "movl 0x195f640, %eax\n" /* line 1170 */
        "movl (%eax), %eax\n"
        "movss 0x2ed6a8, %xmm5\n" /* 16.0f */
        "movss %xmm5, -0xcc(%ebp)\n" /* w */
        "mulss 8(%eax), %xmm5\n"
        "movss %xmm5, -0xcc(%ebp)\n" /* w */
        "mulss 0x2ed63c, %xmm5\n" /* line 1279 | -0.5f */
        "movss %xmm5, -0xe4(%ebp)\n"
        "movss -0x1c(%ebp), %xmm0\n" /* radiusScale */
        "movss %xmm0, -0xe0(%ebp)\n"
        "movss -0xdc(%ebp), %xmm1\n" /* centerX */
        "addss %xmm5, %xmm1\n"
        "movss %xmm1, -0xd4(%ebp)\n" /* x */
        "movss -0xbc(%ebp), %xmm2\n" /* line 485 */
        "movss %xmm2, (%esp)\n"
        "calll sinf\n"
        "fstps -0x16c(%ebp)\n"
        "movss -0x16c(%ebp), %xmm0\n"
        "mulss -0xe0(%ebp), %xmm0\n"
        "movss -0xd4(%ebp), %xmm3\n" /* x */
        "subss %xmm0, %xmm3\n"
        "movss %xmm3, -0xd4(%ebp)\n" /* x */
        "movss -0xd8(%ebp), %xmm5\n" /* line 1280 | centerY */
        "addss -0xe4(%ebp), %xmm5\n"
        "movss %xmm5, -0xd0(%ebp)\n" /* y */
        "movss -0xbc(%ebp), %xmm0\n" /* line 486 */
        "movss %xmm0, (%esp)\n"
        "calll cosf\n"
        "fstps -0x114(%ebp)\n"
        "movss -0x114(%ebp), %xmm1\n"
        "mulss -0xe0(%ebp), %xmm1\n"
        "movss -0xd0(%ebp), %xmm2\n" /* y */
        "subss %xmm1, %xmm2\n"
        "movss %xmm2, -0xd0(%ebp)\n" /* y */
        "movl 0x18(%edi), %edx\n" /* line 1292 | displayStartTime */
        /* { scope 3 */
        "testl %edx, %edx\n" /* line 1062 */
        "je .Lf18aa9c_0018b507\n"
        /* { scope 4 */
        /* { scope 5 */
        "leal -1(%edx), %eax\n" /* line 1040 */
        "cmpl $0x7e, %eax\n"
        "jbe .Lf18aa9c_0018c460\n"
        /* } scope */
        /* } scope */
        ".Lf18aa9c_0018b507:\n"
        "movl 0x195f5c4, %eax\n" /* line 1072 */
        "movl (%eax), %eax\n"
        "movl 0xbc68(%eax), %eax\n"
        /* } scope */
        ".Lf18aa9c_0018b514:\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 1295 */
        "movss -0xc8(%ebp), %xmm1\n" /* line 1296 | fadeAlpha */
        "movaps %xmm1, %xmm2\n"
        "cmpltss %xmm0, %xmm1\n"
        "andps %xmm1, %xmm2\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm2, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "movl %eax, 0x1c(%esp)\n" /* line 1298 */
        "leal -0x3c(%ebp), %eax\n" /* newColor */
        "movl %eax, 0x18(%esp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movss -0xcc(%ebp), %xmm3\n" /* w */
        "movss %xmm3, 0xc(%esp)\n"
        "movss %xmm3, 8(%esp)\n"
        "movss -0xd0(%ebp), %xmm5\n" /* y */
        "movss %xmm5, 4(%esp)\n"
        "movss -0xd4(%ebp), %xmm0\n" /* x */
        "movss %xmm0, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        "jmp .Lf18aa9c_0018b2a5\n"
        /* } scope */
        "movl 0x40(%ebp), %ebx\n" /* line 1881 | color, x */
        "movl %ebx, 8(%esp)\n" /* x */
        "movl 0x44(%ebp), %edi\n" /* material, vertAlign */
        "movl %edi, 4(%esp)\n" /* vertAlign */
        "leal -0x54(%ebp), %eax\n" /* rect */
        "movl %eax, (%esp)\n"
        "calll CG_DrawCompassFriendlies\n"
        "jmp .Lf18aa9c_0018adab\n"
        "movl 0x44(%ebp), %ebx\n" /* line 1788 | material, x */
        "movl %ebx, 0x2c(%esp)\n" /* x */
        "movl 0x40(%ebp), %eax\n" /* color */
        "movl %eax, 0x28(%esp)\n"
        "movl $0x3f800000, %eax\n"
        "movl %eax, 0x24(%esp)\n"
        "movl %eax, 0x20(%esp)\n"
        "xorl %eax, %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl %eax, 0x18(%esp)\n"
        "movl %edi, 0x14(%esp)\n" /* displayStartTime */
        ".Lf18aa9c_0018b5d3:\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x54(%ebp), %eax\n" /* rect */
        "movl %eax, (%esp)\n"
        "calll CL_DrawStretchPic\n"
        "jmp .Lf18aa9c_0018adab\n"
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        "movl 0x195f66c, %eax\n" /* line 864 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf18aa9c_0018adab\n"
        "movl hud_fade_healthbar, %esi\n" /* line 867 | h */
        "movss 0x2ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "mulss 8(%esi), %xmm0\n" /* weapInfo */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x11c(%ebp)\n"
        "cvttss2si -0x11c(%ebp), %edi\n" /* displayStartTime */
        "movl %edi, -0xa4(%ebp)\n" /* displayStartTime, duration */
        "movl 0x195f584, %eax\n" /* line 867 */
        "movl (%eax), %ebx\n" /* displayStartTime */
        "movl 0x2c5c4(%ebx), %edi\n" /* displayStartTime */
        /* { scope 3 */
        /* { scope 4 */
        "calll CL_GetKeyCatchers\n" /* line 101 */
        "testb $8, %al\n"
        "jne .Lf18aa9c_0018c33f\n"
        ".Lf18aa9c_0018b663:\n"
        "movl 0x2bdc8(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf18aa9c_0018c34c\n"
        "xorl %eax, %eax\n"
        ".Lf18aa9c_0018b673:\n"
        "testl %eax, %eax\n" /* line 113 */
        "jne .Lf18aa9c_0018adab\n"
        "movl hud_enable, %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf18aa9c_0018adab\n"
        "pxor %xmm3, %xmm3\n" /* line 119 */
        "ucomiss 8(%esi), %xmm3\n"
        "jne .Lf18aa9c_0018c558\n"
        "jp .Lf18aa9c_0018c558\n"
        "movss 0x2ed5d0, %xmm4\n" /* 1.0f */
        "movss %xmm4, -0xa8(%ebp)\n" /* fadeAlpha */
        "movaps %xmm4, %xmm0\n"
        /* } scope */
        /* } scope */
        ".Lf18aa9c_0018b6b1:\n"
        "movl 0x40(%ebp), %eax\n" /* line 871 | color */
        "addl $0xc, %eax\n"
        "movl %eax, -0xb4(%ebp)\n"
        "movl 0x40(%ebp), %edx\n" /* color */
        "movss %xmm0, 0xc(%edx)\n"
        "movss -0x54(%ebp), %xmm1\n" /* line 872 | rect */
        "movss %xmm1, -0xb0(%ebp)\n" /* x */
        "movss -0x50(%ebp), %xmm2\n" /* line 873 */
        "movss %xmm2, -0xac(%ebp)\n" /* y */
        "movl -0x4c(%ebp), %edi\n" /* line 874 | displayStartTime */
        "movl -0x48(%ebp), %esi\n" /* line 875 | h */
        "movl 0x44(%ebp), %eax\n" /* line 877 | material */
        "movl %eax, 0x2c(%esp)\n"
        "movl %edx, 0x28(%esp)\n"
        "movl $0x3f800000, 0x24(%esp)\n"
        "movl $0x3f800000, 0x20(%esp)\n"
        "movss %xmm3, 0x1c(%esp)\n"
        "movss %xmm3, 0x18(%esp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n" /* h */
        "movl %edi, 8(%esp)\n" /* displayStartTime */
        "movss %xmm2, 4(%esp)\n"
        "movss %xmm1, (%esp)\n"
        "movss %xmm3, -0x158(%ebp)\n"
        "movss %xmm4, -0x168(%ebp)\n"
        "calll CL_DrawStretchPic\n"
        "movl 0x195f584, %edx\n" /* line 743 */
        "movl (%edx), %ebx\n" /* weapIndex */
        "movl 0x24(%ebx), %eax\n" /* weapIndex */
        "addl $0xc, %eax\n"
        "movl 0x12c(%eax), %edx\n" /* line 746 */
        "testl %edx, %edx\n"
        "movss -0x158(%ebp), %xmm3\n"
        "movss -0x168(%ebp), %xmm4\n"
        "je .Lf18aa9c_0018adab\n"
        "movl 0x134(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf18aa9c_0018adab\n"
        "cmpl $6, 4(%eax)\n"
        "je .Lf18aa9c_0018adab\n"
        "cvtsi2ssl %edx, %xmm1\n" /* line 748 */
        "cvtsi2ssl %ecx, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "ucomiss %xmm1, %xmm3\n" /* line 749 */
        "ja .Lf18aa9c_0018adab\n"
        "ucomiss %xmm4, %xmm1\n" /* line 751 */
        "jbe .Lf18aa9c_0018c716\n"
        "movaps %xmm4, %xmm1\n"
        ".Lf18aa9c_0018b7a7:\n"
        "movl hud_health_startpulse_critical, %eax\n" /* line 884 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf18aa9c_0018c72a\n"
        "movl hud_health_startpulse_injured, %eax\n" /* line 886 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf18aa9c_0018adab\n"
        "movss 0x2ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "movl hud_health_pulserate_injured, %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x124(%ebp)\n"
        "cvttss2si -0x124(%ebp), %ecx\n"
        ".Lf18aa9c_0018b7ff:\n"
        "testl %ecx, %ecx\n" /* line 891 */
        "je .Lf18aa9c_0018adab\n"
        "movl 0x2bdfc(%ebx), %eax\n" /* line 893 | displayStartTime */
        "movl 0x25bb0(%ebx), %edx\n" /* displayStartTime */
        "cmpl %edx, %eax\n"
        "jg .Lf18aa9c_0018b81d\n"
        "addl %ecx, %eax\n"
        "cmpl %eax, %edx\n"
        "jle .Lf18aa9c_0018b823\n"
        ".Lf18aa9c_0018b81d:\n"
        "movl %edx, 0x2bdfc(%ebx)\n" /* line 894 | displayStartTime */
        ".Lf18aa9c_0018b823:\n"
        "movl 0x40(%ebp), %ebx\n" /* line 191 | color */
        "movl $0x3f63d70a, (%ebx)\n"
        "movl $0x3e3851ec, 4(%ebx)\n" /* line 192 */
        "movl $0x3c23d70a, 8(%ebx)\n" /* line 193 */
        "movl 0x195f584, %eax\n" /* line 897 */
        "movl (%eax), %edx\n"
        "movl %ecx, %eax\n"
        "addl 0x2bdfc(%edx), %eax\n"
        "subl 0x25bb0(%edx), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "cvtsi2ssl %ecx, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss -0xa8(%ebp), %xmm1\n" /* line 899 | fadeAlpha */
        "minss %xmm0, %xmm1\n"
        "movl -0xb4(%ebp), %eax\n"
        "movss %xmm1, (%eax)\n"
        "movl 0x44(%ebp), %edx\n" /* line 900 | material */
        "movl %edx, 0x2c(%esp)\n"
        "movl %ebx, 0x28(%esp)\n" /* displayStartTime */
        "movl $0x3f800000, %eax\n"
        "movl %eax, 0x24(%esp)\n"
        "movl %eax, 0x20(%esp)\n"
        "xorl %eax, %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl %eax, 0x18(%esp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n" /* h */
        "movl %edi, 8(%esp)\n" /* displayStartTime */
        "movss -0xac(%ebp), %xmm0\n" /* y */
        "movss %xmm0, 4(%esp)\n"
        "movss -0xb0(%ebp), %xmm1\n" /* x */
        "movss %xmm1, (%esp)\n"
        "calll CL_DrawStretchPic\n"
        "jmp .Lf18aa9c_0018adab\n"
        /* } scope */
        "movl $1, 0x10(%esp)\n" /* line 1894 */
        "movl 0x44(%ebp), %edx\n" /* material */
        "movl %edx, 0xc(%esp)\n"
        "movl 0x40(%ebp), %ebx\n" /* color, x */
        "movl %ebx, 8(%esp)\n" /* x */
        ".Lf18aa9c_0018b8e4:\n"
        "movss 0x3c(%ebp), %xmm0\n" /* line 1906 | scale */
        "movss %xmm0, 4(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* rect */
        "movl %eax, (%esp)\n"
        "calll CG_DrawOffHandIcon\n"
        "jmp .Lf18aa9c_0018adab\n"
        "movl $2, 0x10(%esp)\n"
        "movl 0x44(%ebp), %eax\n" /* material */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x40(%ebp), %edx\n" /* color */
        "movl %edx, 8(%esp)\n"
        "jmp .Lf18aa9c_0018b8e4\n"
        "movl $1, 0x14(%esp)\n" /* line 1897 */
        ".Lf18aa9c_0018b91f:\n"
        "movl 0x48(%ebp), %eax\n" /* line 1909 | textStyle */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x40(%ebp), %edx\n" /* color */
        "movl %edx, 0xc(%esp)\n"
        "movss 0x3c(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 8(%esp)\n"
        "movl 0x38(%ebp), %eax\n" /* font */
        "movl %eax, 4(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* rect */
        "movl %eax, (%esp)\n"
        "calll CG_DrawOffHandAmmo\n"
        "jmp .Lf18aa9c_0018adab\n"
        "movl $2, 0x14(%esp)\n"
        "jmp .Lf18aa9c_0018b91f\n"
        "movl $1, 0x14(%esp)\n" /* line 1900 */
        ".Lf18aa9c_0018b961:\n"
        "movl 0x48(%ebp), %edx\n" /* line 1912 | textStyle */
        "movl %edx, 0x10(%esp)\n"
        "movl 0x40(%ebp), %ebx\n" /* color, x */
        "movl %ebx, 0xc(%esp)\n" /* x */
        "movss 0x3c(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 8(%esp)\n"
        "movl 0x38(%ebp), %eax\n" /* font */
        "movl %eax, 4(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* rect */
        "movl %eax, (%esp)\n"
        "calll CG_DrawOffHandName\n"
        "jmp .Lf18aa9c_0018adab\n"
        "movl $2, 0x14(%esp)\n"
        "jmp .Lf18aa9c_0018b961\n"
        "movl $1, 0x10(%esp)\n" /* line 1903 */
        ".Lf18aa9c_0018b9a3:\n"
        "movl 0x44(%ebp), %edx\n" /* line 1915 | material */
        "movl %edx, 0xc(%esp)\n"
        "movl 0x40(%ebp), %ebx\n" /* color, x */
        "movl %ebx, 8(%esp)\n" /* x */
        "movss 0x3c(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 4(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* rect */
        "movl %eax, (%esp)\n"
        "calll CG_DrawOffHandHighlight\n"
        "jmp .Lf18aa9c_0018adab\n"
        "movl $2, 0x10(%esp)\n"
        "jmp .Lf18aa9c_0018b9a3\n"
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        "movl 0x195f584, %eax\n" /* line 743 */
        "movl (%eax), %eax\n"
        "movl 0x24(%eax), %eax\n"
        "addl $0xc, %eax\n"
        "movl 0x12c(%eax), %edx\n" /* line 746 */
        "testl %edx, %edx\n"
        "je .Lf18aa9c_0018adab\n"
        "movl 0x134(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf18aa9c_0018adab\n"
        "cmpl $6, 4(%eax)\n"
        "je .Lf18aa9c_0018adab\n"
        "cvtsi2ssl %edx, %xmm1\n" /* line 748 */
        "cvtsi2ssl %ecx, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "ucomiss 0x2ed5e8, %xmm1\n" /* line 749 | 0.0f */
        "jp .Lf18aa9c_0018ba24\n"
        "jb .Lf18aa9c_0018adab\n"
        ".Lf18aa9c_0018ba24:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 751 | 1.0f */
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf18aa9c_0018c6fe\n"
        "movaps %xmm0, %xmm1\n"
        ".Lf18aa9c_0018ba38:\n"
        "movss %xmm1, (%esp)\n" /* line 1024 */
        "calll CG_PulseLowHealthOverlay\n"
        "movl 0x40(%ebp), %ebx\n" /* line 1025 | color, displayStartTime */
        "addl $0xc, %ebx\n" /* displayStartTime */
        "movl 0x195f584, %eax\n" /* line 915 */
        "movl (%eax), %edx\n"
        "movl 0x25bb0(%edx), %eax\n"
        "movl %eax, %ecx\n" /* line 916 */
        "subl 0x2be14(%edx), %ecx\n"
        "movl $0, %eax\n"
        "cmovsl %eax, %ecx\n"
        "movl 0x2be18(%edx), %eax\n" /* line 919 */
        "testl %eax, %eax\n"
        "jle .Lf18aa9c_0018c5cb\n"
        "cmpl %eax, %ecx\n"
        "jge .Lf18aa9c_0018c5cb\n"
        "movss 0x2be0c(%edx), %xmm1\n" /* line 923 */
        "cvtsi2ssl %ecx, %xmm2\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "divss %xmm0, %xmm2\n"
        "movss 0x2be10(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm1, %xmm2\n"
        ".Lf18aa9c_0018baa3:\n"
        "movss %xmm2, (%ebx)\n" /* line 1025 | displayStartTime */
        "pxor %xmm0, %xmm0\n" /* line 1026 */
        "ucomiss %xmm0, %xmm2\n"
        "jp .Lf18aa9c_0018bab6\n"
        "je .Lf18aa9c_0018adab\n"
        ".Lf18aa9c_0018bab6:\n"
        "movl 0x44(%ebp), %eax\n" /* line 1029 | material */
        "movl %eax, 0x2c(%esp)\n"
        "movl 0x40(%ebp), %edx\n" /* color */
        "movl %edx, 0x28(%esp)\n"
        "movl $0x3f800000, %eax\n"
        "movl %eax, 0x24(%esp)\n"
        "movl %eax, 0x20(%esp)\n"
        "movss %xmm0, 0x1c(%esp)\n"
        "movss %xmm0, 0x18(%esp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "jmp .Lf18aa9c_0018b5d3\n"
        /* } scope */
        "movl 0x195f5c4, %eax\n" /* line 1758 */
        "movl (%eax), %eax\n"
        "movl 0x63bc(%eax), %eax\n"
        "cmpl $0xffffd8f1, %eax\n"
        "je .Lf18aa9c_0018adab\n"
        "movl -0x44(%ebp), %ebx\n" /* line 1760 | x */
        "movl -0x50(%ebp), %esi\n" /* objNum */
        "movss -0x54(%ebp), %xmm0\n" /* rect */
        "movss %xmm0, -0x9c(%ebp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2afbe0, (%esp)\n" /* "%2i" */
        "calll va\n"
        "movl 0x48(%ebp), %edx\n" /* textStyle */
        "movl %edx, 0x24(%esp)\n"
        "movl 0x40(%ebp), %edx\n" /* color */
        "movl %edx, 0x20(%esp)\n"
        "movss 0x3c(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl %edi, 0x18(%esp)\n" /* displayStartTime */
        "movl %ebx, 0x14(%esp)\n" /* x */
        "movl %esi, 0x10(%esp)\n" /* objNum */
        "movss -0x9c(%ebp), %xmm1\n"
        "movss %xmm1, 0xc(%esp)\n"
        ".Lf18aa9c_0018bb57:\n"
        "movl 0x38(%ebp), %edx\n" /* font */
        "movl %edx, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        "jmp .Lf18aa9c_0018adab\n"
        "leal -0x54(%ebp), %eax\n" /* line 1824 | rect */
        "movl $1, 8(%esp)\n"
        "jmp .Lf18aa9c_0018adc1\n"
        "movl 0x48(%ebp), %edi\n" /* line 1815 | textStyle, vertAlign */
        "movl %edi, 0xc(%esp)\n" /* vertAlign */
        "movss 0x3c(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 8(%esp)\n"
        "movl 0x38(%ebp), %eax\n" /* font */
        "movl %eax, 4(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* rect */
        "movl %eax, (%esp)\n"
        "calll CG_DrawHoldBreathHint\n"
        "jmp .Lf18aa9c_0018adab\n"
        "leal -0x54(%ebp), %eax\n" /* line 1821 | rect */
        "movl 0x48(%ebp), %ecx\n" /* textStyle */
        "movss 0x3c(%ebp), %xmm0\n" /* scale */
        "movl 0x38(%ebp), %edx\n" /* font */
        "calll CG_DrawCursorhint\n"
        "jmp .Lf18aa9c_0018adab\n"
        "movl 0x48(%ebp), %edx\n" /* line 1818 | textStyle */
        "movl %edx, 0xc(%esp)\n"
        "movss 0x3c(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 8(%esp)\n"
        "movl 0x38(%ebp), %eax\n" /* font */
        "movl %eax, 4(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* rect */
        "movl %eax, (%esp)\n"
        "calll CG_DrawMantleHint\n"
        "jmp .Lf18aa9c_0018adab\n"
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        "movl $0x2bc, 8(%esp)\n" /* line 392 */
        "movl $0x708, 4(%esp)\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %esi\n" /* weapInfo */
        "movl 0x2be54(%esi), %eax\n" /* weapInfo */
        "movl %eax, (%esp)\n"
        "calll CG_FadeColor\n"
        "testl %eax, %eax\n" /* line 393 */
        "je .Lf18aa9c_0018adab\n"
        "movl 0xc(%eax), %eax\n" /* line 396 */
        "movl %eax, -0x20(%ebp)\n"
        "movl 0x40(%ebp), %edx\n" /* line 199 | color */
        "movl (%edx), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* drawColor */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x28(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x24(%ebp)\n"
        "movl 0x2be50(%esi), %ebx\n" /* line 159 */
        "testl %ebx, %ebx\n"
        "js .Lf18aa9c_0018bc64\n"
        "calll BG_GetNumWeapons\n"
        "cmpl %eax, %ebx\n"
        "jge .Lf18aa9c_0018bc64\n"
        "movl 0x2be50(%esi), %ebx\n"
        "movl %ebx, %eax\n"
        "sarl $5, %eax\n"
        "movl %ebx, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl 0x26108(%esi, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf18aa9c_0018bc71\n"
        ".Lf18aa9c_0018bc64:\n"
        "movl 0x195f584, %eax\n" /* line 161 */
        "movl (%eax), %eax\n"
        "movl 0x25c98(%eax), %ebx\n"
        ".Lf18aa9c_0018bc71:\n"
        "testl %ebx, %ebx\n" /* line 400 | weapIndex */
        "je .Lf18aa9c_0018adab\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 403 | weapIndex */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n" /* weapIndex */
        "movl 0x195f5c8, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %esi\n" /* weapInfo */
        "movl %ebx, (%esp)\n" /* line 405 | weapIndex */
        "calll BG_GetWeaponDef\n"
        "movl 0x70(%eax), %eax\n" /* line 406 */
        "cmpb $0, (%eax)\n"
        "je .Lf18aa9c_0018c400\n"
        "movl 0xb4(%esi), %eax\n" /* line 407 | weapInfo */
        "movl %eax, 8(%esp)\n"
        "movl 0xb0(%esi), %eax\n" /* weapInfo */
        "movl %eax, 4(%esp)\n"
        "movl $0x2afbe8, (%esp)\n" /* "%s / %s" */
        "calll va\n"
        "movl %eax, %ebx\n" /* weapIndex */
        ".Lf18aa9c_0018bcc3:\n"
        "movss -0x54(%ebp), %xmm1\n" /* line 412 | rect */
        "addss -0x4c(%ebp), %xmm1\n"
        "movss 0x3c(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 0xc(%esp)\n"
        "movl 0x38(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* weapIndex */
        "movss %xmm1, -0x138(%ebp)\n"
        "calll UI_TextWidth\n"
        "movl 0x48(%ebp), %edx\n" /* line 414 | textStyle */
        "movl %edx, 0x24(%esp)\n"
        "leal -0x2c(%ebp), %edx\n" /* drawColor */
        "movl %edx, 0x20(%esp)\n"
        "movss 0x3c(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl -0x40(%ebp), %edx\n"
        "movl %edx, 0x18(%esp)\n"
        "movl -0x44(%ebp), %edx\n"
        "movl %edx, 0x14(%esp)\n"
        "movl -0x50(%ebp), %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0x138(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "subss 0x2ed8f0, %xmm1\n" /* 28.0f */
        ".Lf18aa9c_0018bd3d:\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movl 0x38(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* weapIndex */
        "calll UI_DrawText\n"
        "jmp .Lf18aa9c_0018adab\n"
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        "movl 0x195f584, %eax\n" /* line 432 */
        "movl (%eax), %ebx\n" /* weapIndex */
        "movl 0x2be54(%ebx), %edi\n" /* weapIndex, displayStartTime */
        "movl hud_fade_ammodisplay, %esi\n" /* fadeDvar */
        /* { scope 3 */
        /* { scope 4 */
        "calll CL_GetKeyCatchers\n" /* line 101 */
        "testb $8, %al\n"
        "jne .Lf18aa9c_0018c1ce\n"
        ".Lf18aa9c_0018bd7f:\n"
        "movl 0x2bdc8(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf18aa9c_0018c1db\n"
        "xorl %eax, %eax\n"
        ".Lf18aa9c_0018bd8f:\n"
        "testl %eax, %eax\n" /* line 113 */
        "jne .Lf18aa9c_0018bda2\n"
        "movl hud_enable, %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf18aa9c_0018c356\n"
        ".Lf18aa9c_0018bda2:\n"
        "pxor %xmm3, %xmm3\n" /* line 126 */
        "movaps %xmm3, %xmm0\n"
        /* } scope */
        /* } scope */
        ".Lf18aa9c_0018bda9:\n"
        "movss %xmm0, -0x20(%ebp)\n" /* line 432 */
        "ucomiss %xmm3, %xmm0\n" /* line 433 */
        "jp .Lf18aa9c_0018bdb9\n"
        "je .Lf18aa9c_0018adab\n"
        ".Lf18aa9c_0018bdb9:\n"
        "movl 0x40(%ebp), %edx\n" /* line 199 | color */
        "movl (%edx), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* drawColor */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x28(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x24(%ebp)\n"
        "movl 0x195f584, %ebx\n" /* line 159 */
        "movl (%ebx), %esi\n"
        "movl 0x2be50(%esi), %ebx\n"
        "testl %ebx, %ebx\n"
        "js .Lf18aa9c_0018be05\n"
        "calll BG_GetNumWeapons\n"
        "cmpl %eax, %ebx\n"
        "jge .Lf18aa9c_0018be05\n"
        "movl 0x2be50(%esi), %ebx\n"
        "movl %ebx, %eax\n"
        "sarl $5, %eax\n"
        "movl %ebx, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl 0x26108(%esi, %eax, 4), %eax\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "jne .Lf18aa9c_0018be13\n"
        ".Lf18aa9c_0018be05:\n"
        "movl 0x195f584, %edi\n" /* line 161 */
        "movl (%edi), %eax\n"
        "movl 0x25c98(%eax), %ebx\n"
        ".Lf18aa9c_0018be13:\n"
        "testl %ebx, %ebx\n" /* line 439 | weapIndex */
        "je .Lf18aa9c_0018adab\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 442 | weapIndex */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n" /* weapIndex */
        "movl 0x195f5c8, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %esi\n" /* fadeDvar */
        "movl %ebx, (%esp)\n" /* line 444 | weapIndex */
        "calll BG_GetWeaponDef\n"
        "movl 0x70(%eax), %eax\n" /* line 445 */
        "cmpb $0, (%eax)\n"
        "je .Lf18aa9c_0018c4ba\n"
        "movl 0xb4(%esi), %eax\n" /* line 446 | fadeDvar */
        "movl %eax, 8(%esp)\n"
        "movl 0xb0(%esi), %eax\n" /* fadeDvar */
        "movl %eax, 4(%esp)\n"
        "movl $0x2afbe8, (%esp)\n" /* "%s / %s" */
        "calll va\n"
        ".Lf18aa9c_0018be63:\n"
        "movss 0x3c(%ebp), %xmm0\n" /* line 451 | scale */
        "movss %xmm0, 0xc(%esp)\n"
        "movl 0x38(%ebp), %edx\n" /* font */
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll UI_TextWidth\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "addss 0x2ed8f0, %xmm1\n" /* 28.0f */
        "addss 0x2ed740, %xmm1\n" /* 8.0f */
        "movl 0x44(%ebp), %ebx\n" /* line 454 | material, weapIndex */
        "movl %ebx, 0x1c(%esp)\n" /* weapIndex */
        "leal -0x2c(%ebp), %eax\n" /* drawColor */
        "movl %eax, 0x18(%esp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movss %xmm1, 8(%esp)\n"
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movss -0x54(%ebp), %xmm0\n" /* rect */
        "addss -0x4c(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        "jmp .Lf18aa9c_0018adab\n"
        /* } scope */
        "movl 0x195f584, %eax\n" /* line 1688 */
        "movl (%eax), %ebx\n" /* x */
        "movl 0x24(%ebx), %eax\n" /* x */
        "movl 0xd8(%eax), %edx\n"
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "leal (%ebx, %eax, 8), %eax\n" /* x */
        "movl 0xe0914(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf18aa9c_0018adab\n"
        "movl 0xe0940(%eax), %eax\n" /* line 1690 */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x40(%ebp), %ebx\n" /* color, x */
        "movl 0xc(%ebx), %eax\n" /* x */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x54(%ebp), %eax\n" /* rect */
        "movl %eax, (%esp)\n"
        "calll CG_DrawTeamBackground\n"
        "jmp .Lf18aa9c_0018adab\n"
        "leal -0x54(%ebp), %edx\n" /* line 1830 | rect */
        "movl 0x48(%ebp), %ebx\n" /* textStyle, x */
        "movl %ebx, 8(%esp)\n" /* x */
        "movl 0x44(%ebp), %edi\n" /* material, vertAlign */
        "movl %edi, 4(%esp)\n" /* vertAlign */
        "movl 0x40(%ebp), %eax\n" /* color */
        "movl %eax, (%esp)\n"
        "movss 0x3c(%ebp), %xmm0\n" /* scale */
        "movl 0x38(%ebp), %ecx\n" /* font */
        "xorl %eax, %eax\n"
        "calll CG_DrawScore\n"
        "jmp .Lf18aa9c_0018adab\n"
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        "movl 0x195f584, %eax\n" /* line 1657 */
        "movl (%eax), %ebx\n" /* x */
        "movl 0x24(%ebx), %eax\n" /* x */
        "movl 0xd8(%eax), %edx\n"
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "leal 0xe0900(%ebx, %eax, 8), %eax\n" /* x */
        "leal 0x14(%eax), %edx\n"
        "movl 0x14(%eax), %ecx\n" /* line 1658 */
        "testl %ecx, %ecx\n"
        "je .Lf18aa9c_0018adab\n"
        "movl 0x38(%edx), %eax\n" /* line 1660 */
        "movl %eax, (%esp)\n"
        "calll CG_GetTranslatedLocationString\n"
        "movl 0x48(%ebp), %edx\n" /* line 1661 | textStyle */
        "movl %edx, 0x24(%esp)\n"
        "movl 0x40(%ebp), %ebx\n" /* color, x */
        "movl %ebx, 0x20(%esp)\n" /* x */
        "movss 0x3c(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl -0x40(%ebp), %edx\n"
        "movl %edx, 0x18(%esp)\n"
        "movl -0x44(%ebp), %edx\n"
        "movl %edx, 0x14(%esp)\n"
        "movss -0x50(%ebp), %xmm0\n"
        "addss -0x48(%ebp), %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movl -0x54(%ebp), %edx\n" /* rect */
        "movl %edx, 0xc(%esp)\n"
        "jmp .Lf18aa9c_0018bb57\n"
        /* } scope */
        "leal -0x54(%ebp), %edx\n" /* line 1833 | rect */
        "movl 0x48(%ebp), %ebx\n" /* textStyle, x */
        "movl %ebx, 8(%esp)\n" /* x */
        "movl 0x44(%ebp), %edi\n" /* material, vertAlign */
        "movl %edi, 4(%esp)\n" /* vertAlign */
        "movl 0x40(%ebp), %eax\n" /* color */
        "movl %eax, (%esp)\n"
        "movss 0x3c(%ebp), %xmm0\n" /* scale */
        "movl 0x38(%ebp), %ecx\n" /* font */
        "movl $1, %eax\n"
        "calll CG_DrawScore\n"
        "jmp .Lf18aa9c_0018adab\n"
        "movl 0x195f584, %eax\n" /* line 1740 */
        "movl (%eax), %eax\n"
        "cmpb $0, 0x2b54c(%eax)\n"
        "je .Lf18aa9c_0018adab\n"
        "addl $0x2b54c, %eax\n" /* line 1728 */
        "movl %eax, 4(%esp)\n"
        "movl $0x2afb50, (%esp)\n" /* "Fragged by %s" */
        "calll va\n"
        "movl %eax, %ebx\n" /* x */
        "movss -0x54(%ebp), %xmm0\n" /* line 1746 | rect */
        "movss %xmm0, -0x100(%ebp)\n"
        "movss -0x4c(%ebp), %xmm1\n"
        "movss 0x3c(%ebp), %xmm2\n" /* scale */
        "movss %xmm2, 0xc(%esp)\n"
        "movl 0x38(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* x */
        "movss %xmm1, -0x138(%ebp)\n"
        "calll UI_TextWidth\n"
        "movl 0x48(%ebp), %edx\n" /* line 1747 | textStyle */
        "movl %edx, 0x24(%esp)\n"
        "movl 0x40(%ebp), %edi\n" /* color, displayStartTime */
        "movl %edi, 0x20(%esp)\n" /* displayStartTime */
        "movss 0x3c(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl -0x40(%ebp), %edx\n"
        "movl %edx, 0x18(%esp)\n"
        "movl -0x44(%ebp), %edx\n"
        "movl %edx, 0x14(%esp)\n"
        "movss -0x50(%ebp), %xmm0\n"
        "addss -0x48(%ebp), %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0x138(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "mulss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "addss -0x100(%ebp), %xmm1\n"
        "jmp .Lf18aa9c_0018bd3d\n"
        "movl 0x195f5c4, %eax\n" /* line 1758 */
        "movl (%eax), %eax\n"
        "movl 0x63b8(%eax), %eax\n"
        "cmpl $0xffffd8f1, %eax\n"
        "je .Lf18aa9c_0018adab\n"
        "movl -0x44(%ebp), %ebx\n" /* line 1760 | x */
        "movl -0x50(%ebp), %esi\n" /* objNum */
        "movss -0x54(%ebp), %xmm0\n" /* rect */
        "movss %xmm0, -0xa0(%ebp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2afbe0, (%esp)\n" /* "%2i" */
        "calll va\n"
        "movl 0x48(%ebp), %edx\n" /* textStyle */
        "movl %edx, 0x24(%esp)\n"
        "movl 0x40(%ebp), %edx\n" /* color */
        "movl %edx, 0x20(%esp)\n"
        "movss 0x3c(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl %edi, 0x18(%esp)\n" /* displayStartTime */
        "movl %ebx, 0x14(%esp)\n" /* x */
        "movl %esi, 0x10(%esp)\n" /* objNum */
        "movss -0xa0(%ebp), %xmm1\n"
        "movss %xmm1, 0xc(%esp)\n"
        "jmp .Lf18aa9c_0018bb57\n"
        "movl 0x48(%ebp), %eax\n" /* line 1779 | textStyle */
        "movl %eax, 0x24(%esp)\n"
        "movl 0x40(%ebp), %edx\n" /* color */
        "movl %edx, 0x20(%esp)\n"
        "movss 0x3c(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl %edi, 0x18(%esp)\n" /* displayStartTime */
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movss -0x50(%ebp), %xmm0\n"
        "addss -0x48(%ebp), %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movl -0x54(%ebp), %eax\n" /* rect */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x38(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl 0x195f5c4, %eax\n"
        "movl (%eax), %eax\n"
        "addl $0x5ea4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        "jmp .Lf18aa9c_0018adab\n"
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        ".Lf18aa9c_0018c1bf:\n"
        "jp .Lf18aa9c_0018ab3f\n" /* line 749 */
        ".Lf18aa9c_0018c1c5:\n"
        "pxor %xmm2, %xmm2\n" /* line 751 */
        "jmp .Lf18aa9c_0018ab4f\n"
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf18aa9c_0018c1ce:\n"
        "calll CL_GetDisplayHUDWithKeycatchUI\n" /* line 101 */
        "testb %al, %al\n"
        "jne .Lf18aa9c_0018bd7f\n"
        ".Lf18aa9c_0018c1db:\n"
        "movl $1, %eax\n"
        "jmp .Lf18aa9c_0018bd8f\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf18aa9c_0018c1e5:\n"
        "calll CL_GetDisplayHUDWithKeycatchUI\n"
        "testb %al, %al\n"
        "jne .Lf18aa9c_0018b1be\n"
        ".Lf18aa9c_0018c1f2:\n"
        "movl $1, %eax\n"
        "jmp .Lf18aa9c_0018b1ce\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf18aa9c_0018c1fc:\n"
        "calll CL_GetDisplayHUDWithKeycatchUI\n"
        "testb %al, %al\n"
        "jne .Lf18aa9c_0018b047\n"
        ".Lf18aa9c_0018c209:\n"
        "movl $1, %eax\n"
        "jmp .Lf18aa9c_0018b057\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf18aa9c_0018c213:\n"
        "calll CL_GetDisplayHUDWithKeycatchUI\n"
        "testb %al, %al\n"
        "jne .Lf18aa9c_0018af36\n"
        ".Lf18aa9c_0018c220:\n"
        "movl $1, %eax\n"
        "jmp .Lf18aa9c_0018af46\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        ".Lf18aa9c_0018c22a:\n"
        "movl (%edx), %eax\n" /* line 1261 */
        "movss 8(%eax), %xmm1\n"
        "ucomiss %xmm1, %xmm2\n"
        "jb .Lf18aa9c_0018c29f\n"
        "movl $0x3f800000, -0x1c(%ebp)\n" /* line 1263 | radiusScale */
        "jmp .Lf18aa9c_0018b3e8\n"
        ".Lf18aa9c_0018c242:\n"
        "movl 0x195f660, %eax\n" /* line 1243 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "jb .Lf18aa9c_0018c2e8\n"
        "movl 0x195f664, %eax\n" /* line 1245 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "jmp .Lf18aa9c_0018b3c6\n"
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf18aa9c_0018c269:\n"
        "calll CL_GetDisplayHUDWithKeycatchUI\n" /* line 101 */
        "testb %al, %al\n"
        "movss -0x148(%ebp), %xmm2\n"
        "jne .Lf18aa9c_0018abb1\n"
        ".Lf18aa9c_0018c27e:\n"
        "movl $1, %eax\n"
        "jmp .Lf18aa9c_0018abc8\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        /* { scope 3 */
        ".Lf18aa9c_0018c288:\n"
        "leal 0x14(%edx), %eax\n" /* line 201 */
        /* } scope */
        /* { scope 3 */
        "movss 0x14(%edx), %xmm0\n" /* line 199 */
        "movss 4(%eax), %xmm1\n" /* line 200 */
        "movss 8(%eax), %xmm2\n" /* line 201 */
        "jmp .Lf18aa9c_0018b316\n"
        /* } scope */
        /* { scope 3 */
        ".Lf18aa9c_0018c29f:\n"
        "movaps %xmm1, %xmm3\n" /* line 1269 */
        "subss %xmm0, %xmm3\n"
        "movaps %xmm3, %xmm0\n"
        "pxor %xmm3, %xmm3\n"
        "ucomiss %xmm3, %xmm0\n"
        "jne .Lf18aa9c_0018c4d5\n"
        "jp .Lf18aa9c_0018c4d5\n"
        "movaps %xmm3, %xmm2\n"
        ".Lf18aa9c_0018c2bf:\n"
        "movl 0x195f650, %eax\n" /* line 1272 */
        "movl (%eax), %eax\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movaps %xmm0, %xmm1\n"
        "subss 8(%eax), %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n" /* radiusScale */
        "jmp .Lf18aa9c_0018b3e8\n"
        /* } scope */
        /* { scope 3 */
        ".Lf18aa9c_0018c2e8:\n"
        "subss %xmm1, %xmm0\n" /* line 1251 */
        "pxor %xmm3, %xmm3\n"
        "ucomiss %xmm3, %xmm0\n"
        "jne .Lf18aa9c_0018c4e5\n"
        "jp .Lf18aa9c_0018c4e5\n"
        ".Lf18aa9c_0018c2ff:\n"
        "movl 0x195f664, %eax\n" /* line 1254 */
        "movl (%eax), %eax\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movaps %xmm0, %xmm1\n"
        "subss 8(%eax), %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "jmp .Lf18aa9c_0018b3c6\n"
        /* } scope */
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf18aa9c_0018c328:\n"
        "calll CL_GetDisplayHUDWithKeycatchUI\n" /* line 101 */
        "testb %al, %al\n"
        "jne .Lf18aa9c_0018ae3d\n"
        ".Lf18aa9c_0018c335:\n"
        "movl $1, %eax\n"
        "jmp .Lf18aa9c_0018ae4d\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf18aa9c_0018c33f:\n"
        "calll CL_GetDisplayHUDWithKeycatchUI\n"
        "testb %al, %al\n"
        "jne .Lf18aa9c_0018b663\n"
        ".Lf18aa9c_0018c34c:\n"
        "movl $1, %eax\n"
        "jmp .Lf18aa9c_0018b673\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf18aa9c_0018c356:\n"
        "pxor %xmm3, %xmm3\n" /* line 119 */
        "ucomiss 8(%esi), %xmm3\n"
        "jne .Lf18aa9c_0018c608\n"
        "jp .Lf18aa9c_0018c608\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jmp .Lf18aa9c_0018bda9\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf18aa9c_0018c377:\n"
        "pxor %xmm3, %xmm3\n"
        "ucomiss 8(%esi), %xmm3\n"
        "jne .Lf18aa9c_0018c636\n"
        "jp .Lf18aa9c_0018c636\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jmp .Lf18aa9c_0018af60\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf18aa9c_0018c398:\n"
        "pxor %xmm3, %xmm3\n"
        "ucomiss 8(%esi), %xmm3\n"
        "jne .Lf18aa9c_0018c5d8\n"
        "jp .Lf18aa9c_0018c5d8\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jmp .Lf18aa9c_0018b071\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf18aa9c_0018c3b9:\n"
        "movl $0x2bc, 8(%esp)\n" /* line 122 */
        "movl -0xc0(%ebp), %eax\n" /* duration */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll CG_FadeColor\n"
        "testl %eax, %eax\n" /* line 123 */
        "je .Lf18aa9c_0018adab\n"
        "movss 0xc(%eax), %xmm0\n" /* line 126 */
        "movss %xmm0, -0xc8(%ebp)\n" /* fadeAlpha */
        /* } scope */
        /* } scope */
        "ucomiss 0x2ed5e8, %xmm0\n" /* line 1207 | 0.0f */
        "jp .Lf18aa9c_0018b209\n"
        "jne .Lf18aa9c_0018b209\n"
        "jmp .Lf18aa9c_0018adab\n"
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        ".Lf18aa9c_0018c400:\n"
        "movl 0xb0(%esi), %eax\n" /* line 409 | weapInfo */
        "movl %eax, 4(%esp)\n"
        "movl $0x216058, (%esp)\n" /* "%s" */
        "calll va\n"
        "movl %eax, %ebx\n" /* weapIndex */
        "jmp .Lf18aa9c_0018bcc3\n"
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        ".Lf18aa9c_0018c41d:\n"
        "addss 0x2ed724, %xmm1\n" /* line 802 | 0.20000000298023224f */
        "movl 0x40(%ebp), %edi\n" /* color, duration */
        "mulss 4(%edi), %xmm1\n" /* duration */
        "addss 0x2ed6f4, %xmm1\n" /* 0.30000001192092896f */
        "movss %xmm1, 4(%edi)\n" /* duration */
        "jmp .Lf18aa9c_0018ac8a\n"
        /* { scope 3 */
        /* { scope 4 */
        ".Lf18aa9c_0018c43f:\n"
        "pxor %xmm3, %xmm3\n" /* line 119 */
        "ucomiss 8(%esi), %xmm3\n"
        "jne .Lf18aa9c_0018c66a\n"
        "jp .Lf18aa9c_0018c66a\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jmp .Lf18aa9c_0018abe2\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        /* { scope 3 */
        /* { scope 4 */
        /* { scope 5 */
        ".Lf18aa9c_0018c460:\n"
        "leal 0x61e(%edx), %eax\n" /* line 1042 */
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl %eax, %edx\n"
        "cmpb $0, (%eax)\n" /* line 1043 */
        "je .Lf18aa9c_0018b507\n"
        "cld\n" /* line 1045 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %edx, %edi\n" /* displayStartTime */
        "repne scasb %es:(%edi), %al\n" /* displayStartTime */
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "cmpl $0x3f, %ecx\n"
        "ja .Lf18aa9c_0018b507\n"
        "movl %edx, 4(%esp)\n" /* line 1047 */
        "leal -0x94(%ebp), %ebx\n" /* shaderName, displayStartTime */
        "movl %ebx, (%esp)\n" /* displayStartTime */
        "calll strcpy\n"
        /* } scope */
        /* } scope */
        "movl $7, 4(%esp)\n" /* line 1068 */
        "movl %ebx, (%esp)\n" /* displayStartTime */
        "calll CL_RegisterMaterialNoMip\n"
        "jmp .Lf18aa9c_0018b514\n"
        /* } scope */
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        ".Lf18aa9c_0018c4ba:\n"
        "movl 0xb0(%esi), %eax\n" /* line 448 | fadeDvar */
        "movl %eax, 4(%esp)\n"
        "movl $0x216058, (%esp)\n" /* "%s" */
        "calll va\n"
        "jmp .Lf18aa9c_0018be63\n"
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        /* { scope 3 */
        ".Lf18aa9c_0018c4d5:\n"
        "subss %xmm2, %xmm1\n" /* line 1270 */
        "movaps %xmm1, %xmm2\n"
        "divss %xmm0, %xmm2\n"
        "jmp .Lf18aa9c_0018c2bf\n"
        /* } scope */
        /* { scope 3 */
        ".Lf18aa9c_0018c4e5:\n"
        "movaps %xmm2, %xmm3\n" /* line 1252 */
        "subss %xmm1, %xmm3\n"
        "divss %xmm0, %xmm3\n"
        "jmp .Lf18aa9c_0018c2ff\n"
        /* } scope */
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        ".Lf18aa9c_0018c4f5:\n"
        "movss 0x2be08(%eax), %xmm1\n" /* line 814 */
        "ucomiss %xmm2, %xmm1\n"
        "jbe .Lf18aa9c_0018ad0a\n"
        "movl 0x2be00(%eax), %edx\n" /* line 816 */
        "testl %edx, %edx\n"
        "je .Lf18aa9c_0018c6d4\n"
        "subl 0x25bac(%eax), %edx\n" /* line 818 */
        "movl %edx, 0x2be00(%eax)\n"
        "testl %edx, %edx\n" /* line 819 */
        "jns .Lf18aa9c_0018ad1c\n"
        "movl $0, 0x2be00(%eax)\n" /* line 820 */
        "jmp .Lf18aa9c_0018ad1c\n"
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf18aa9c_0018c537:\n"
        "pxor %xmm3, %xmm3\n" /* line 119 */
        "ucomiss 8(%esi), %xmm3\n"
        "jne .Lf18aa9c_0018c6a4\n"
        "jp .Lf18aa9c_0018c6a4\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jmp .Lf18aa9c_0018ae67\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf18aa9c_0018c558:\n"
        "movl $0x2bc, 8(%esp)\n" /* line 122 */
        "movl -0xa4(%ebp), %eax\n" /* duration */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll CG_FadeColor\n"
        "testl %eax, %eax\n" /* line 123 */
        "je .Lf18aa9c_0018adab\n"
        "movss 0xc(%eax), %xmm0\n" /* line 126 */
        "movss %xmm0, -0xa8(%ebp)\n" /* fadeAlpha */
        /* } scope */
        /* } scope */
        "pxor %xmm3, %xmm3\n" /* line 868 */
        "ucomiss %xmm3, %xmm0\n"
        "jp .Lf18aa9c_0018c596\n"
        "je .Lf18aa9c_0018adab\n"
        ".Lf18aa9c_0018c596:\n"
        "movss 0x2ed5d0, %xmm4\n" /* 1.0f */
        "movss -0xa8(%ebp), %xmm0\n" /* fadeAlpha */
        "jmp .Lf18aa9c_0018b6b1\n"
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        ".Lf18aa9c_0018c5ab:\n"
        "movl 0x40(%ebp), %ebx\n" /* line 199 | color */
        "movl (%ebx), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* drawColor */
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, -0x28(%ebp)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, -0x24(%ebp)\n"
        "jmp .Lf18aa9c_0018ae99\n"
        ".Lf18aa9c_0018c5c4:\n"
        "movl %ebx, %edx\n"
        "jmp .Lf18aa9c_0018acf0\n"
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        ".Lf18aa9c_0018c5cb:\n"
        "movss 0x2be10(%edx), %xmm2\n" /* line 927 */
        "jmp .Lf18aa9c_0018baa3\n"
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf18aa9c_0018c5d8:\n"
        "movl $0x2bc, 8(%esp)\n" /* line 122 */
        "movl -0xec(%ebp), %eax\n" /* duration */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll CG_FadeColor\n"
        "testl %eax, %eax\n" /* line 123 */
        "je .Lf18aa9c_0018b06a\n"
        "movss 0xc(%eax), %xmm0\n" /* line 126 */
        "pxor %xmm3, %xmm3\n"
        "jmp .Lf18aa9c_0018b071\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf18aa9c_0018c608:\n"
        "movl $0x2bc, 8(%esp)\n" /* line 122 */
        "movl $0x708, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll CG_FadeColor\n"
        "testl %eax, %eax\n" /* line 123 */
        "je .Lf18aa9c_0018bda2\n"
        "movss 0xc(%eax), %xmm0\n" /* line 126 */
        "pxor %xmm3, %xmm3\n"
        "jmp .Lf18aa9c_0018bda9\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf18aa9c_0018c636:\n"
        "movl $0x2bc, 8(%esp)\n" /* line 122 */
        "movl $0x708, 4(%esp)\n"
        "movl -0xfc(%ebp), %edx\n" /* displayStartTime */
        "movl %edx, (%esp)\n"
        "calll CG_FadeColor\n"
        "testl %eax, %eax\n" /* line 123 */
        "je .Lf18aa9c_0018af59\n"
        "movss 0xc(%eax), %xmm0\n" /* line 126 */
        "pxor %xmm3, %xmm3\n"
        "jmp .Lf18aa9c_0018af60\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf18aa9c_0018c66a:\n"
        "movl $0x2bc, 8(%esp)\n" /* line 122 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "movss %xmm2, -0x148(%ebp)\n"
        "calll CG_FadeColor\n"
        "testl %eax, %eax\n" /* line 123 */
        "movss -0x148(%ebp), %xmm2\n"
        "je .Lf18aa9c_0018abdb\n"
        "movss 0xc(%eax), %xmm0\n" /* line 126 */
        "pxor %xmm3, %xmm3\n"
        "jmp .Lf18aa9c_0018abe2\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf18aa9c_0018c6a4:\n"
        "movl $0x2bc, 8(%esp)\n" /* line 122 */
        "movl -0x104(%ebp), %edx\n" /* duration */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll CG_FadeColor\n"
        "testl %eax, %eax\n" /* line 123 */
        "je .Lf18aa9c_0018ae60\n"
        "movss 0xc(%eax), %xmm0\n" /* line 126 */
        "pxor %xmm3, %xmm3\n"
        "jmp .Lf18aa9c_0018ae67\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        ".Lf18aa9c_0018c6d4:\n"
        "cvtsi2ssl 0x25bac(%eax), %xmm0\n" /* line 824 */
        "mulss 0x2ed95c, %xmm0\n" /* 0.0012000000569969416f */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0x2be08(%eax)\n"
        "ucomiss %xmm1, %xmm2\n" /* line 825 */
        "jb .Lf18aa9c_0018ad1c\n"
        "jmp .Lf18aa9c_0018ad0a\n"
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        ".Lf18aa9c_0018c6fe:\n"
        "ucomiss 0x2ed5e8, %xmm1\n" /* line 1021 | 0.0f */
        "jp .Lf18aa9c_0018ba38\n"
        "jne .Lf18aa9c_0018ba38\n"
        "jmp .Lf18aa9c_0018adab\n"
        /* } scope */
        /* { scope 2: duration, displayStartTime, duration, duration, ... */
        ".Lf18aa9c_0018c716:\n"
        "ucomiss %xmm3, %xmm1\n" /* line 881 */
        "jp .Lf18aa9c_0018b7a7\n"
        "jne .Lf18aa9c_0018b7a7\n"
        "jmp .Lf18aa9c_0018adab\n"
        ".Lf18aa9c_0018c72a:\n"
        "movss 0x2ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "movl hud_health_pulserate_critical, %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x120(%ebp)\n"
        "cvttss2si -0x120(%ebp), %ecx\n"
        "jmp .Lf18aa9c_0018b7ff\n"
    );
}

