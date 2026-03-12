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
extern const char *va(const char *fmt, ...);
extern unsigned int Scr_GetNumScriptVars(void);
extern unsigned int Scr_GetNumScriptThreads(void);
extern unsigned int Scr_GetStringUsage(void);
extern int Sys_Milliseconds(void);
extern int CL_GetCurrentCmdNumber(void);
extern qboolean CL_GetUserCmd(int cmdNumber, usercmd_t *ucmd);
extern const char *UI_SafeTranslateString(const char *ref);
extern FontHandle UI_GetFontHandle(int fontEnum, float scale);
extern int UI_TextWidth(const char *text, int maxChars, FontHandle font, float scale);
extern void UI_DrawText(const char *text, int maxChars, FontHandle font, float x, float y, int horzAlign, int vertAlign, float scale, const vec_t *color, int style);
extern MaterialHandle CL_RegisterMaterial(const char *name, int flags);

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
static unsigned int CG_CalcCrosshairPosition(void);
static float CG_DrawFPS(float y);
unsigned int CG_DrawBoldGameMessages(void);
unsigned int CG_DrawTurretCrossHair(void);
static unsigned int CG_DrawSpectatorMessage(void);
unsigned int CG_StartShakeCamera(float p, int duration, vec_t *src, float radius);
static float CG_DrawWeapReticle(void);
unsigned int CG_DrawCrosshair(void);
unsigned int CG_Draw2D(void);

/* line 133 */
unsigned int CG_DrawTeamBackground(float x, float y, float w, float h, float alpha, int team)
{
    vec4_t color;
    byte *cgs;

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

    cgs = *(byte **)cgs_ptr;
    UI_DrawHandlePic(x, y, w, h, 0, 0, color, *(MaterialHandle *)(cgs + 0xba28));
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
    byte *cg = (byte *)*(int *)imp_cg;
    int index = *(int *)((char *)&lagometer + 512);
    lagometer.frameSamples[index & 0x7f] = *(int *)(cg + 0x25bb0) - *(int *)(cg + 0x1c);
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
    char *cg;
    byte *snap;
    const char *text;
    FontHandle font;
    int textWidth;
    vec4_t color = {1.0f, 1.0f, 1.0f, 1.0f};

    CL_GetUserCmd(CL_GetCurrentCmdNumber() - 127, &cmd);
    cg = *cg_glob;
    snap = *(byte **)(cg + 0x24);
    if (cmd.serverTime <= *(int *)(snap + 0xc) || cmd.serverTime > *(int *)(cg + 0x25bb0))
    {
        return 0;
    }

    text = UI_SafeTranslateString(str_002b6ff0);
    font = UI_GetFontHandle(0, 0.5f);
    textWidth = UI_TextWidth(text, 0, font, 0.5f);
    UI_DrawText(text, 0x7fffffff, font, (float)((640 - textWidth) / 2), 100.0f, 0, 0, 0.5f, color, 3);
    if (!(*(byte *)(cg + 0x25bb1) & 2))
    {
        UI_DrawHandlePic(296.0f, 416.0f, 48.0f, 48.0f, 0, 0, 0, CL_RegisterMaterial(str_002a89c8, 7));
    }

    return 0;
}

/* line 971 */
__attribute__((naked))
unsigned int CG_PriorityCenterPrint(const char *str, float charWidth, int priority)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 971 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x12c, %esp\n"
        "movl 0x10(%ebp), %edi\n" /* priority */
        /* { scope 1 */
        "movl imp_cg, %eax\n" /* line 982 */
        "movl (%eax), %esi\n" /* neednewline */
        "movl 0x2b990(%esi), %eax\n" /* neednewline */
        "testl %eax, %eax\n"
        "je .Lf1cb3de_001cb40a\n"
        "cmpl 0x2bd9c(%esi), %edi\n" /* neednewline, priority */
        "jl .Lf1cb3de_001cb4fa\n"
        ".Lf1cb3de_001cb40a:\n"
        "leal -0x11c(%ebp), %ebx\n" /* line 985 | hudElemString, count */
        "movl %ebx, 8(%esp)\n" /* count */
        "movl $str_002b700c, 4(%esp)\n" /* "Center Print" */
        "movl 8(%ebp), %eax\n" /* str */
        "movl %eax, (%esp)\n"
        "calll CG_TranslateHudElemMessage\n"
        "movl $0x100, 8(%esp)\n" /* line 986 */
        "movl %ebx, 4(%esp)\n" /* count */
        "leal 0x2b998(%esi), %ebx\n" /* neednewline, count */
        "movl %ebx, (%esp)\n" /* count */
        "calll I_strncpyz\n"
        "movl %edi, 0x2bd9c(%esi)\n" /* line 987 | priority, neednewline */
        "movl %ebx, -0x1c(%ebp)\n" /* line 991 | count, s */
        "xorl %esi, %esi\n" /* neednewline */
        "xorl %ebx, %ebx\n" /* count */
        "leal -0x1c(%ebp), %edi\n" /* s, priority */
        ".Lf1cb3de_001cb451:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 992 | s */
        "cmpb $0, (%eax)\n"
        "je .Lf1cb3de_001cb497\n"
        ".Lf1cb3de_001cb459:\n"
        "movl $0, 4(%esp)\n" /* line 994 */
        "movl %edi, (%esp)\n" /* priority */
        "calll SEH_ReadCharFromString\n"
        "cmpl $0xa, %eax\n" /* line 996 */
        "je .Lf1cb3de_001cb48b\n"
        "addl $1, %ebx\n" /* line 1003 | count */
        "cmpl $0x4a, %ebx\n" /* line 1004 | count */
        "jle .Lf1cb3de_001cb505\n"
        "movl $1, %esi\n" /* neednewline */
        ".Lf1cb3de_001cb47f:\n"
        "cmpl $0x20, %eax\n" /* line 1007 */
        "jne .Lf1cb3de_001cb451\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1009 | s */
        "movb $0xa, -1(%eax)\n"
        ".Lf1cb3de_001cb48b:\n"
        "xorl %esi, %esi\n" /* neednewline */
        "xorl %ebx, %ebx\n" /* count */
        "movl -0x1c(%ebp), %eax\n" /* line 992 | s */
        "cmpb $0, (%eax)\n"
        "jne .Lf1cb3de_001cb459\n"
        ".Lf1cb3de_001cb497:\n"
        "movl imp_cg, %ecx\n" /* line 1015 */
        "movl (%ecx), %eax\n"
        "movl 0x25bb0(%eax), %edx\n"
        "addl $0x7d0, %edx\n"
        "movl %edx, 0x2b990(%eax)\n"
        "cvttss2si 0xc(%ebp), %edx\n" /* line 1016 | charWidth */
        "movl %edx, 0x2b994(%eax)\n"
        "movl $1, 0x2bd98(%eax)\n" /* line 1019 */
        "addl $0x2b998, %eax\n" /* line 1020 */
        "movl %eax, -0x1c(%ebp)\n" /* s */
        "leal -0x1c(%ebp), %ebx\n" /* s, count */
        "movl %ecx, %esi\n" /* neednewline */
        ".Lf1cb3de_001cb4d3:\n"
        "cmpb $0, (%eax)\n" /* line 1021 */
        "je .Lf1cb3de_001cb4fa\n"
        ".Lf1cb3de_001cb4d8:\n"
        "movl $0, 4(%esp)\n" /* line 1023 */
        "movl %ebx, (%esp)\n" /* count */
        "calll SEH_ReadCharFromString\n"
        "cmpl $0xa, %eax\n" /* line 1025 */
        "je .Lf1cb3de_001cb512\n"
        "cmpl $0x5c, %eax\n" /* line 1029 */
        "je .Lf1cb3de_001cb520\n"
        "movl -0x1c(%ebp), %eax\n" /* s */
        "cmpb $0, (%eax)\n" /* line 1021 */
        "jne .Lf1cb3de_001cb4d8\n"
        /* } scope */
        ".Lf1cb3de_001cb4fa:\n"
        "addl $0x12c, %esp\n" /* line 1035 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1cb3de_001cb505:\n"
        "testl %esi, %esi\n" /* line 1007 | neednewline */
        "je .Lf1cb3de_001cb451\n"
        "jmp .Lf1cb3de_001cb47f\n"
        ".Lf1cb3de_001cb512:\n"
        "movl (%esi), %eax\n" /* line 1027 | neednewline */
        "addl $1, 0x2bd98(%eax)\n"
        "movl -0x1c(%ebp), %eax\n" /* s */
        "jmp .Lf1cb3de_001cb4d3\n"
        ".Lf1cb3de_001cb520:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1029 | s */
        "cmpb $0x6e, (%eax)\n"
        "jne .Lf1cb3de_001cb4d3\n"
        "movl (%esi), %eax\n" /* line 1031 | neednewline */
        "addl $1, 0x2bd98(%eax)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1032 | s */
        "addl $1, %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* s */
        "jmp .Lf1cb3de_001cb4d3\n"
    );
}

/* line 1132 */
__attribute__((naked))
Bool CG_GetWeapReticleZoom(float *pfZoom)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1132 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* pfZoom */
        /* { scope 1 */
        "movl imp_cg, %eax\n" /* line 1138 */
        "movl (%eax), %ebx\n"
        "leal 0x25bc4(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetViewmodelWeaponIndex\n"
        "movl %eax, (%esp)\n" /* line 1139 */
        "calll BG_GetWeaponDef\n"
        "movl %eax, %edx\n"
        "movss 0x25ca0(%ebx), %xmm1\n" /* line 1141 */
        "pxor %xmm2, %xmm2\n" /* line 1143 */
        "movss %xmm2, (%esi)\n" /* pfZoom */
        "movl 0x274(%eax), %eax\n" /* line 1148 */
        "cmpb $0, (%eax)\n"
        "jne .Lf1cb53e_001cb58d\n"
        "movl 0x278(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1cb53e_001cb5ef\n"
        ".Lf1cb53e_001cb58d:\n"
        "ucomiss %xmm2, %xmm1\n" /* line 1152 */
        "jp .Lf1cb53e_001cb594\n"
        "je .Lf1cb53e_001cb5ef\n"
        ".Lf1cb53e_001cb594:\n"
        "movl 0x28494(%ebx), %ecx\n" /* line 1156 */
        "testl %ecx, %ecx\n"
        "je .Lf1cb53e_001cb5f8\n"
        "movss lit4_002ed5d0, %xmm3\n" /* line 1158 | 1.0f */
        "movaps %xmm3, %xmm0\n"
        "subss 0x26c(%edx), %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "movss %xmm1, (%esi)\n" /* pfZoom */
        "ucomiss %xmm2, %xmm1\n" /* line 1159 */
        "jbe .Lf1cb53e_001cb5cd\n"
        "divss 0x26c(%edx), %xmm0\n" /* line 1160 */
        "movss %xmm0, (%esi)\n" /* pfZoom */
        ".Lf1cb53e_001cb5cd:\n"
        "ucomiss lit4_002ed738, %xmm0\n" /* line 1170 | 0.009999999776482582f */
        "jp .Lf1cb53e_001cb5d8\n"
        "jbe .Lf1cb53e_001cb5ef\n"
        ".Lf1cb53e_001cb5d8:\n"
        "ucomiss %xmm3, %xmm0\n" /* line 1173 */
        "jbe .Lf1cb53e_001cb5e3\n"
        "movl $0x3f800000, (%esi)\n" /* line 1174 | pfZoom */
        ".Lf1cb53e_001cb5e3:\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 1177 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1cb53e_001cb5ef:\n"
        "xorl %eax, %eax\n" /* line 1174 */
        /* } scope */
        "addl $0x10, %esp\n" /* line 1177 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1cb53e_001cb5f8:\n"
        "movss lit4_002ed5d0, %xmm3\n" /* line 1164 | 1.0f */
        "movaps %xmm3, %xmm0\n"
        "subss 0x270(%edx), %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "movss %xmm1, (%esi)\n" /* pfZoom */
        "ucomiss %xmm2, %xmm1\n" /* line 1165 */
        "jbe .Lf1cb53e_001cb5cd\n"
        "divss 0x270(%edx), %xmm0\n" /* line 1166 */
        "movss %xmm0, (%esi)\n" /* pfZoom */
        "jmp .Lf1cb53e_001cb5cd\n"
    );
}

/* line 1186 */
__attribute__((naked))
unsigned int CG_DrawFrameOverlay(float innerLeft, float innerRight, float innerTop, float innerBottom, const vec_t *color, MaterialHandle material)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1186 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x60, %esp\n"
        "movl 0x18(%ebp), %esi\n" /* color */
        "movl 0x1c(%ebp), %ebx\n" /* material */
        /* { scope 1 */
        "movl imp_cls, %eax\n" /* line 1188 */
        "cvtsi2ssl 0x2a0a64(%eax), %xmm0\n" /* screenWidth */
        "cvtsi2ssl 0x2a0a68(%eax), %xmm1\n" /* line 1189 */
        "movss %xmm1, -0xc(%ebp)\n" /* screenHeight */
        "pxor %xmm1, %xmm1\n" /* line 1192 */
        "movss 8(%ebp), %xmm2\n" /* innerLeft */
        "ucomiss %xmm1, %xmm2\n"
        "jbe .Lf1cb62a_001cb6bc\n"
        "movl %ebx, 0x24(%esp)\n" /* line 1193 | material */
        "movl %esi, 0x20(%esp)\n" /* color */
        "movl $0x3f800000, 0x1c(%esp)\n"
        "movss %xmm1, 0x18(%esp)\n"
        "movss %xmm1, 0x14(%esp)\n"
        "movss %xmm1, 0x10(%esp)\n"
        "movss -0xc(%ebp), %xmm2\n" /* screenHeight */
        "movss %xmm2, 0xc(%esp)\n"
        "movss 8(%ebp), %xmm2\n" /* innerLeft */
        "movss %xmm2, 8(%esp)\n"
        "movss %xmm1, 4(%esp)\n"
        "movss %xmm1, (%esp)\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "movss %xmm1, -0x38(%ebp)\n"
        "calll CL_DrawStretchPicPhysical\n"
        "movss -0x38(%ebp), %xmm1\n"
        "movss -0x28(%ebp), %xmm0\n"
        ".Lf1cb62a_001cb6bc:\n"
        "ucomiss 0xc(%ebp), %xmm0\n" /* line 1196 | innerRight */
        "ja .Lf1cb62a_001cb790\n"
        ".Lf1cb62a_001cb6c6:\n"
        "movss 0x10(%ebp), %xmm2\n" /* line 1200 | innerTop */
        "ucomiss %xmm1, %xmm2\n"
        "jbe .Lf1cb62a_001cb727\n"
        "movl %ebx, 0x24(%esp)\n" /* line 1201 | material */
        "movl %esi, 0x20(%esp)\n" /* color */
        "movss %xmm1, 0x1c(%esp)\n"
        "movl $0x3f800000, 0x18(%esp)\n"
        "movss %xmm1, 0x14(%esp)\n"
        "movss %xmm1, 0x10(%esp)\n"
        "movss %xmm2, 0xc(%esp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* innerRight */
        "subss 8(%ebp), %xmm0\n" /* innerLeft */
        "movss %xmm0, 8(%esp)\n"
        "movss %xmm1, 4(%esp)\n"
        "movss 8(%ebp), %xmm0\n" /* innerLeft */
        "movss %xmm0, (%esp)\n"
        "movss %xmm1, -0x38(%ebp)\n"
        "calll CL_DrawStretchPicPhysical\n"
        "movss -0x38(%ebp), %xmm1\n"
        ".Lf1cb62a_001cb727:\n"
        "movss -0xc(%ebp), %xmm2\n" /* line 1204 | screenHeight */
        "ucomiss 0x14(%ebp), %xmm2\n" /* innerBottom */
        "jbe .Lf1cb62a_001cb789\n"
        "movl %ebx, 0x24(%esp)\n" /* line 1205 | material */
        "movl %esi, 0x20(%esp)\n" /* color */
        "movss %xmm1, 0x1c(%esp)\n"
        "movl $0x3f800000, 0x18(%esp)\n"
        "movss %xmm1, 0x14(%esp)\n"
        "movss %xmm1, 0x10(%esp)\n"
        "subss 0x14(%ebp), %xmm2\n" /* innerBottom */
        "movss %xmm2, 0xc(%esp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* innerRight */
        "subss 8(%ebp), %xmm0\n" /* innerLeft */
        "movss %xmm0, 8(%esp)\n"
        "movss 0x14(%ebp), %xmm1\n" /* innerBottom */
        "movss %xmm1, 4(%esp)\n"
        "movss 8(%ebp), %xmm2\n" /* innerLeft */
        "movss %xmm2, (%esp)\n"
        "calll CL_DrawStretchPicPhysical\n"
        /* } scope */
        ".Lf1cb62a_001cb789:\n"
        "addl $0x60, %esp\n" /* line 1206 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1cb62a_001cb790:\n"
        "movl %ebx, 0x24(%esp)\n" /* line 1197 | material */
        "movl %esi, 0x20(%esp)\n" /* color */
        "movl $0x3f800000, 0x1c(%esp)\n"
        "movss %xmm1, 0x18(%esp)\n"
        "movss %xmm1, 0x14(%esp)\n"
        "movss %xmm1, 0x10(%esp)\n"
        "movss -0xc(%ebp), %xmm2\n" /* screenHeight */
        "movss %xmm2, 0xc(%esp)\n"
        "subss 0xc(%ebp), %xmm0\n" /* innerRight */
        "movss %xmm0, 8(%esp)\n"
        "movss %xmm1, 4(%esp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* innerRight */
        "movss %xmm0, (%esp)\n"
        "movss %xmm1, -0x38(%ebp)\n"
        "calll CL_DrawStretchPicPhysical\n"
        "movss -0x38(%ebp), %xmm1\n"
        "jmp .Lf1cb62a_001cb6c6\n"
    );
}

/* line 1782 */
static __attribute__((naked))
unsigned int CG_DrawCrosshairNames(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1782 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        /* { scope 1 */
        "movl imp_cg_drawCrosshairNames, %eax\n" /* line 1798 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1cb7ec_001cb816\n"
        "movl imp_cg, %eax\n" /* line 1800 */
        "movl (%eax), %ebx\n"
        "movl 0x25bc0(%ebx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf1cb7ec_001cb821\n"
        /* } scope */
        ".Lf1cb7ec_001cb816:\n"
        "addl $0x9c, %esp\n" /* line 1877 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1cb7ec_001cb821:\n"
        "leal 0x28588(%ebx), %edx\n" /* line 1801 */
        "movl 0x28588(%ebx), %eax\n" /* line 199 */
        "movl %eax, -0x24(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x20(%ebp)\n"
        "movss 8(%edx), %xmm2\n" /* line 201 */
        "movss %xmm2, -0x1c(%ebp)\n"
        "leal 0x28594(%ebx), %eax\n"
        "movss lit4_002eda0c, %xmm1\n" /* line 288 | 8192.0f */
        "movss 0x28594(%ebx), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss -0x24(%ebp), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "movss 4(%eax), %xmm0\n" /* line 289 */
        "mulss %xmm1, %xmm0\n"
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "mulss 8(%eax), %xmm1\n" /* line 290 */
        "addss %xmm1, %xmm2\n"
        "movss %xmm2, -0x28(%ebp)\n"
        "movl $0x2000001, 0x18(%esp)\n" /* line 1762 */
        "movl 0x24(%ebx), %eax\n"
        "movl 0xd8(%eax), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "leal -0x30(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl imp_vec3_origin, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x64(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_TraceCapsule\n"
        "movl -0x48(%ebp), %eax\n" /* line 1764 */
        "cmpw $0x3f, %ax\n"
        "jbe .Lf1cb7ec_001cba5d\n"
        ".Lf1cb7ec_001cb8cd:\n"
        "movl $0x64, 8(%esp)\n" /* line 1807 */
        "movl $0x96, 4(%esp)\n"
        "movl 0x2bdd0(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_FadeColor\n"
        "movl %eax, %edi\n" /* baseColor */
        "testl %eax, %eax\n" /* line 1809 */
        "je .Lf1cb7ec_001cb816\n"
        "movl 0x2bdcc(%ebx), %esi\n" /* line 1812 | s */
        "cmpl $0x40, %esi\n" /* s */
        "jg .Lf1cb7ec_001cb816\n"
        "movl 0x24(%ebx), %eax\n" /* line 1815 */
        "movl 0xd8(%eax), %edx\n"
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "leal (%ebx, %eax, 8), %eax\n"
        "movl 0xe0914(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1cb7ec_001cb816\n"
        "movl 0xe0940(%eax), %ecx\n" /* line 1817 */
        "testl %ecx, %ecx\n" /* line 1818 */
        "je .Lf1cb7ec_001cb816\n"
        "leal (%esi, %esi, 4), %edx\n" /* line 1821 | s */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%esi, %eax, 2), %eax\n" /* s */
        "shll $3, %eax\n"
        "leal (%eax, %ebx), %edx\n"
        "movl 0xe0914(%edx), %esi\n" /* s */
        "testl %esi, %esi\n" /* s */
        "je .Lf1cb7ec_001cb816\n"
        "cmpl $3, %ecx\n" /* line 1825 */
        "je .Lf1cb7ec_001cb96b\n"
        "cmpl 0xe0940(%edx), %ecx\n" /* line 1828 */
        "jne .Lf1cb7ec_001cb816\n"
        ".Lf1cb7ec_001cb96b:\n"
        "leal 0xe0920(%eax, %ebx), %eax\n" /* line 1834 */
        "movl %eax, 4(%esp)\n"
        "movl $str_00216058, (%esp)\n" /* "%s" */
        "calll va\n"
        "movl %eax, %esi\n" /* s */
        "testl %eax, %eax\n" /* line 1835 */
        "je .Lf1cb7ec_001cb816\n"
        "cmpb $0, (%eax)\n"
        "je .Lf1cb7ec_001cb816\n"
        "movl %eax, (%esp)\n" /* line 1837 */
        "calll I_CleanStr\n"
        "movl imp_cg_drawCrosshairNamesPosX, %eax\n" /* line 1839 */
        "movl (%eax), %eax\n"
        "cvtsi2ssl 8(%eax), %xmm0\n"
        "movss %xmm0, -0x70(%ebp)\n" /* x */
        "movl imp_cg_drawCrosshairNamesPosY, %eax\n" /* line 1840 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "addl $0x10, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x6c(%ebp)\n" /* y */
        "movl 0x2bdcc(%ebx), %eax\n" /* line 1842 */
        "cmpl 0x2bddc(%ebx), %eax\n"
        "je .Lf1cb7ec_001cba77\n"
        "movl $0x3f800000, %eax\n" /* line 191 */
        "movl %eax, -0x40(%ebp)\n" /* actualColor */
        "movl %eax, -0x3c(%ebp)\n" /* line 192 */
        "movl %eax, -0x38(%ebp)\n" /* line 193 */
        ".Lf1cb7ec_001cb9e4:\n"
        "movss lit4_002ed944, %xmm0\n" /* line 1867 | 0.6000000238418579f */
        "mulss 0xc(%edi), %xmm0\n" /* baseColor */
        "movss %xmm0, -0x34(%ebp)\n"
        "movl $0x3eaaaaab, %ebx\n" /* line 1875 */
        "movl %ebx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl $3, 0x24(%esp)\n" /* line 1876 */
        "leal -0x40(%ebp), %edx\n" /* actualColor */
        "movl %edx, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movss -0x6c(%ebp), %xmm0\n" /* y */
        "movss %xmm0, 0x10(%esp)\n"
        "movss -0x70(%ebp), %xmm0\n" /* x */
        "movss %xmm0, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* s */
        "calll UI_DrawText\n"
        "jmp .Lf1cb7ec_001cb816\n"
        ".Lf1cb7ec_001cba5d:\n"
        "movzwl %ax, %eax\n" /* line 1768 */
        "movl %eax, 0x2bdcc(%ebx)\n"
        "movl 0x25bb0(%ebx), %eax\n" /* line 1769 */
        "movl %eax, 0x2bdd0(%ebx)\n"
        "jmp .Lf1cb7ec_001cb8cd\n"
        ".Lf1cb7ec_001cba77:\n"
        "cvtsi2ssl 0x2bde0(%ebx), %xmm1\n" /* line 1844 */
        "divss lit4_002ed798, %xmm1\n" /* 100.0f */
        "movss lit4_002ed5d0, %xmm2\n" /* line 1846 | 1.0f */
        "ucomiss %xmm2, %xmm1\n"
        "jbe .Lf1cb7ec_001cbad8\n"
        "movaps %xmm2, %xmm1\n"
        ".Lf1cb7ec_001cba97:\n"
        "movl $0, -0x38(%ebp)\n" /* line 1851 */
        "ucomiss lit4_002ed5d8, %xmm1\n" /* line 1852 | 0.5f */
        "jbe .Lf1cb7ec_001cbac3\n"
        "movaps %xmm2, %xmm0\n" /* line 1854 */
        "subss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n" /* actualColor */
        "movl $0x3f800000, -0x3c(%ebp)\n" /* line 1855 */
        "jmp .Lf1cb7ec_001cb9e4\n"
        ".Lf1cb7ec_001cbac3:\n"
        "movl $0x3f800000, -0x40(%ebp)\n" /* line 1859 | actualColor */
        "addss %xmm1, %xmm1\n" /* line 1860 */
        "movss %xmm1, -0x3c(%ebp)\n"
        "jmp .Lf1cb7ec_001cb9e4\n"
        ".Lf1cb7ec_001cbad8:\n"
        "pxor %xmm0, %xmm0\n" /* line 1848 */
        "maxss %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "jmp .Lf1cb7ec_001cba97\n"
    );
}

/* line 2410 */
__attribute__((naked))
unsigned int CG_CheckTimedMenus(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2410 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xdc, %esp\n"
        "movl imp_cg, %eax\n" /* line 2414 */
        "movl (%eax), %esi\n"
        "movl 0x2be4c(%esi), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1cbae6_001cbb16\n"
        "movl 0x25bb0(%esi), %eax\n" /* line 2418 */
        "subl %edx, %eax\n"
        "cmpl $0x9c4, %eax\n"
        "jg .Lf1cbae6_001cc0f0\n"
        ".Lf1cbae6_001cbb16:\n"
        "calll CL_GetCurrentCmdNumber\n" /* line 2231 */
        "movl %eax, %esi\n"
        "cmpl $1, %eax\n" /* line 2232 */
        "jle .Lf1cbae6_001cbc84\n"
        "leal -0x34(%ebp), %eax\n" /* line 2236 */
        "movl %eax, 4(%esp)\n"
        "leal -1(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_GetUserCmd\n"
        "leal -0x50(%ebp), %eax\n" /* line 2237 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll CL_GetUserCmd\n"
        "movl -0x30(%ebp), %edx\n" /* line 2238 */
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, -0x94(%ebp)\n"
        "xorl %edx, %eax\n"
        "movl %eax, -0x90(%ebp)\n"
        "movzbl -0x1b(%ebp), %eax\n" /* line 2240 */
        "movb %al, -0x6f(%ebp)\n"
        "movzbl -0x1c(%ebp), %eax\n"
        "movb %al, -0x70(%ebp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, -0x74(%ebp)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, -0x78(%ebp)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, -0x7c(%ebp)\n"
        "movzbl -0x2b(%ebp), %eax\n"
        "movb %al, -0x7f(%ebp)\n"
        "movzbl -0x2c(%ebp), %eax\n"
        "movb %al, -0x80(%ebp)\n"
        "movl %edx, -0x84(%ebp)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, -0x88(%ebp)\n"
        "movzbl -0x37(%ebp), %eax\n"
        "movb %al, -0x53(%ebp)\n"
        "movzbl -0x38(%ebp), %eax\n"
        "movb %al, -0x54(%ebp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, -0x58(%ebp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, -0x5c(%ebp)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, -0x60(%ebp)\n"
        "movzbl -0x47(%ebp), %eax\n"
        "movb %al, -0x63(%ebp)\n"
        "movzbl -0x48(%ebp), %eax\n"
        "movb %al, -0x64(%ebp)\n"
        "movl -0x94(%ebp), %edx\n"
        "movl %edx, -0x68(%ebp)\n"
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, -0x6c(%ebp)\n"
        "movl $0xc, %ebx\n" /* line 2136 */
        "cld\n"
        "leal -0x7c(%ebp), %esi\n"
        "leal -0x60(%ebp), %edi\n"
        "movl %ebx, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf1cbae6_001cbbf6\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf1cbae6_001cbbf6:\n"
        "testl %eax, %eax\n"
        "je .Lf1cbae6_001cbeec\n"
        ".Lf1cbae6_001cbbfe:\n"
        "movl $1, %ebx\n" /* line 2140 */
        ".Lf1cbae6_001cbc03:\n"
        "testb $1, -0x94(%ebp)\n" /* line 2186 */
        "je .Lf1cbae6_001cbc23\n"
        "movl imp_cg, %eax\n"
        "movl (%eax), %eax\n"
        "testl $0x300, 0x25c64(%eax)\n"
        "je .Lf1cbae6_001cc08b\n"
        ".Lf1cbae6_001cbc23:\n"
        "testb $0x30, -0x94(%ebp)\n" /* line 2169 */
        "je .Lf1cbae6_001cbc40\n"
        "movl imp_cg, %eax\n" /* line 2171 */
        "movl (%eax), %edx\n"
        "testb $4, 0x25bd0(%edx)\n"
        "je .Lf1cbae6_001cc06b\n"
        ".Lf1cbae6_001cbc40:\n"
        "testl $0x30000, -0x94(%ebp)\n" /* line 2206 */
        "jne .Lf1cbae6_001cc0b5\n"
        ".Lf1cbae6_001cbc50:\n"
        "testl $0x2300, -0x90(%ebp)\n" /* line 2149 */
        "jne .Lf1cbae6_001cc0df\n"
        ".Lf1cbae6_001cbc60:\n"
        "testl $0x2300, -0x94(%ebp)\n" /* line 2154 */
        "jne .Lf1cbae6_001cc15e\n"
        ".Lf1cbae6_001cbc70:\n"
        "testl %ebx, %ebx\n" /* line 2255 */
        "je .Lf1cbae6_001cc056\n"
        ".Lf1cbae6_001cbc78:\n"
        "movl $2, (%esp)\n" /* line 2259 */
        "calll CG_MenuShowNotify\n"
        ".Lf1cbae6_001cbc84:\n"
        "calll CG_CalcPlayerHealth\n" /* line 2268 */
        "fstps -0x8c(%ebp)\n"
        "movl imp_hud_health_startpulse_injured, %eax\n"
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "ucomiss -0x8c(%ebp), %xmm0\n"
        "ja .Lf1cbae6_001cc045\n"
        "movl imp_hud_fade_healthbar, %eax\n" /* line 2272 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "ucomiss lit4_002ed5e8, %xmm1\n" /* 0.0f */
        "jp .Lf1cbae6_001cbe35\n"
        "jne .Lf1cbae6_001cbe35\n"
        ".Lf1cbae6_001cbcc7:\n"
        "calll CG_CheckPlayerForLowAmmo\n" /* line 2294 */
        "testb %al, %al\n"
        "jne .Lf1cbae6_001cbddb\n"
        "calll CG_CheckPlayerForLowClip\n"
        "testb %al, %al\n"
        "jne .Lf1cbae6_001cbddb\n"
        ".Lf1cbae6_001cbce1:\n"
        "movl imp_hud_fade_ammodisplay, %eax\n" /* line 2298 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm2, %xmm1\n"
        "jp .Lf1cbae6_001cbcfc\n"
        "je .Lf1cbae6_001cbe10\n"
        ".Lf1cbae6_001cbcfc:\n"
        "movl imp_cg, %ecx\n"
        "movl (%ecx), %eax\n"
        "movl 0x2c5c8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf1cbae6_001cbefe\n"
        ".Lf1cbae6_001cbd12:\n"
        "movl imp_hud_fade_compass, %eax\n" /* line 2320 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "ucomiss %xmm2, %xmm1\n"
        "jp .Lf1cbae6_001cbd29\n"
        "je .Lf1cbae6_001cbe09\n"
        ".Lf1cbae6_001cbd29:\n"
        "movl (%ecx), %eax\n"
        "movl 0x2c5c0(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf1cbae6_001cbdec\n"
        ".Lf1cbae6_001cbd39:\n"
        "movl 0x24(%eax), %eax\n" /* line 2342 */
        "movl 0xac(%eax), %eax\n"
        "testb $8, %al\n"
        "je .Lf1cbae6_001cbd4f\n"
        "testb $1, %ah\n"
        "jne .Lf1cbae6_001cbe24\n"
        ".Lf1cbae6_001cbd4f:\n"
        "testb $4, %al\n" /* line 2344 */
        "jne .Lf1cbae6_001cbe1b\n"
        ".Lf1cbae6_001cbd57:\n"
        "movl imp_hud_fade_stance, %eax\n" /* line 2347 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm2, %xmm1\n"
        "jp .Lf1cbae6_001cbd6e\n"
        "je .Lf1cbae6_001cbd83\n"
        ".Lf1cbae6_001cbd6e:\n"
        "movl imp_cg, %eax\n" /* line 2349 */
        "movl (%eax), %eax\n"
        "movl 0x2c5cc(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf1cbae6_001cbfd7\n"
        ".Lf1cbae6_001cbd83:\n"
        "movl imp_hud_fade_offhand, %eax\n" /* line 2373 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "ucomiss %xmm2, %xmm1\n"
        "jp .Lf1cbae6_001cbd96\n"
        "je .Lf1cbae6_001cbdab\n"
        ".Lf1cbae6_001cbd96:\n"
        "movl imp_cg, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x2c5d0(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf1cbae6_001cbf6d\n"
        ".Lf1cbae6_001cbdab:\n"
        "calll CG_ScoreboardDisplayed\n" /* line 2396 */
        "testl %eax, %eax\n"
        "je .Lf1cbae6_001cbdd0\n"
        "movl imp_cg, %eax\n" /* line 2398 */
        "movl (%eax), %edx\n"
        "movl 0x25bb0(%edx), %eax\n" /* line 2399 */
        "subl 0x2b538(%edx), %eax\n"
        "cmpl $0x64, %eax\n"
        "jg .Lf1cbae6_001cbeb4\n"
        ".Lf1cbae6_001cbdd0:\n"
        "addl $0xdc, %esp\n" /* line 2432 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1cbae6_001cbddb:\n"
        "movl $1, (%esp)\n" /* line 2296 */
        "calll CG_MenuShowNotify\n"
        "jmp .Lf1cbae6_001cbce1\n"
        ".Lf1cbae6_001cbdec:\n"
        "movl 0x25bb0(%eax), %eax\n" /* line 2323 */
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss lit4_002ed5c8, %xmm1\n" /* 1000.0f */
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf1cbae6_001cc114\n"
        ".Lf1cbae6_001cbe09:\n"
        "movl (%ecx), %eax\n"
        "jmp .Lf1cbae6_001cbd39\n"
        ".Lf1cbae6_001cbe10:\n"
        "movl imp_cg, %ecx\n"
        "jmp .Lf1cbae6_001cbd12\n"
        ".Lf1cbae6_001cbe1b:\n"
        "testb $2, %ah\n" /* line 2344 */
        "je .Lf1cbae6_001cbd57\n"
        ".Lf1cbae6_001cbe24:\n"
        "movl $3, (%esp)\n" /* line 2345 */
        "calll CG_MenuShowNotify\n"
        "jmp .Lf1cbae6_001cbd57\n"
        ".Lf1cbae6_001cbe35:\n"
        "movl imp_cg, %eax\n" /* line 2272 */
        "movl (%eax), %eax\n"
        "movl 0x2c5c4(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1cbae6_001cbcc7\n"
        "movl 0x25bb0(%eax), %eax\n" /* line 2275 */
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss lit4_002ed5c8, %xmm1\n" /* 1000.0f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf1cbae6_001cbcc7\n"
        "calll CL_GetLocalClientActiveCount\n" /* line 2277 */
        "subl $1, %eax\n"
        "je .Lf1cbae6_001cc16f\n"
        "movl $str_002b7030, 4(%esp)\n" /* line 2280 */
        "movl imp_cgDC, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        ".Lf1cbae6_001cbe8a:\n"
        "testl %eax, %eax\n" /* line 2281 */
        "je .Lf1cbae6_001cbe9e\n"
        "movl $4, 4(%esp)\n" /* line 2282 */
        "movl %eax, (%esp)\n"
        "calll Window_RemoveDynamicFlags\n"
        ".Lf1cbae6_001cbe9e:\n"
        "movl imp_cg, %eax\n" /* line 2283 */
        "movl (%eax), %eax\n"
        "movl $0, 0x2c5c4(%eax)\n"
        "jmp .Lf1cbae6_001cbcc7\n"
        ".Lf1cbae6_001cbeb4:\n"
        "movl $str_002b7074, 4(%esp)\n" /* line 2401 */
        "movl imp_cgDC, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        "testl %eax, %eax\n" /* line 2402 */
        "je .Lf1cbae6_001cbdd0\n"
        "movl $4, 4(%esp)\n" /* line 2403 */
        "movl %eax, (%esp)\n"
        "calll Window_RemoveDynamicFlags\n"
        "addl $0xdc, %esp\n" /* line 2432 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1cbae6_001cbeec:\n"
        "cmpw $0, -0x54(%ebp)\n" /* line 2140 */
        "jne .Lf1cbae6_001cbbfe\n"
        "xorb %bl, %bl\n"
        "jmp .Lf1cbae6_001cbc03\n"
        ".Lf1cbae6_001cbefe:\n"
        "movl 0x25bb0(%eax), %eax\n" /* line 2301 */
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss lit4_002ed5c8, %xmm1\n" /* 1000.0f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf1cbae6_001cbd12\n"
        "calll CL_GetLocalClientActiveCount\n" /* line 2303 */
        "subl $1, %eax\n"
        "je .Lf1cbae6_001cc1a0\n"
        "movl $str_002b703c, 4(%esp)\n" /* line 2306 */
        "movl imp_cgDC, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        ".Lf1cbae6_001cbf3e:\n"
        "testl %eax, %eax\n" /* line 2307 */
        "je .Lf1cbae6_001cbf52\n"
        "movl $4, 4(%esp)\n" /* line 2308 */
        "movl %eax, (%esp)\n"
        "calll Window_RemoveDynamicFlags\n"
        ".Lf1cbae6_001cbf52:\n"
        "movl imp_cg, %ecx\n" /* line 2309 */
        "movl (%ecx), %eax\n"
        "movl $0, 0x2c5c8(%eax)\n"
        "pxor %xmm2, %xmm2\n"
        "jmp .Lf1cbae6_001cbd12\n"
        ".Lf1cbae6_001cbf6d:\n"
        "movl 0x25bb0(%eax), %eax\n" /* line 2376 */
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss lit4_002ed5c8, %xmm1\n" /* 1000.0f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf1cbae6_001cbdab\n"
        "calll CL_GetLocalClientActiveCount\n" /* line 2378 */
        "subl $1, %eax\n"
        "je .Lf1cbae6_001cc1ba\n"
        "movl $str_002b7064, 4(%esp)\n" /* line 2381 */
        "movl imp_cgDC, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        ".Lf1cbae6_001cbfad:\n"
        "testl %eax, %eax\n" /* line 2382 */
        "je .Lf1cbae6_001cbfc1\n"
        "movl $4, 4(%esp)\n" /* line 2383 */
        "movl %eax, (%esp)\n"
        "calll Window_RemoveDynamicFlags\n"
        ".Lf1cbae6_001cbfc1:\n"
        "movl imp_cg, %eax\n" /* line 2384 */
        "movl (%eax), %eax\n"
        "movl $0, 0x2c5d0(%eax)\n"
        "jmp .Lf1cbae6_001cbdab\n"
        ".Lf1cbae6_001cbfd7:\n"
        "movl 0x25bb0(%eax), %eax\n" /* line 2352 */
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss lit4_002ed5c8, %xmm1\n" /* 1000.0f */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf1cbae6_001cbd83\n"
        "calll CL_GetLocalClientActiveCount\n" /* line 2354 */
        "subl $1, %eax\n"
        "je .Lf1cbae6_001cc1d4\n"
        "movl $str_002b704c, 4(%esp)\n" /* line 2357 */
        "movl imp_cgDC, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        ".Lf1cbae6_001cc017:\n"
        "testl %eax, %eax\n" /* line 2359 */
        "je .Lf1cbae6_001cc02b\n"
        "movl $4, 4(%esp)\n" /* line 2360 */
        "movl %eax, (%esp)\n"
        "calll Window_RemoveDynamicFlags\n"
        ".Lf1cbae6_001cc02b:\n"
        "movl imp_cg, %eax\n" /* line 2361 */
        "movl (%eax), %eax\n"
        "movl $0, 0x2c5cc(%eax)\n"
        "pxor %xmm2, %xmm2\n"
        "jmp .Lf1cbae6_001cbd83\n"
        ".Lf1cbae6_001cc045:\n"
        "movl $0, (%esp)\n" /* line 2270 */
        "calll CG_MenuShowNotify\n"
        "jmp .Lf1cbae6_001cbcc7\n"
        ".Lf1cbae6_001cc056:\n"
        "testl $0xffffd4ff, -0x90(%ebp)\n" /* line 2255 */
        "je .Lf1cbae6_001cbc84\n"
        "jmp .Lf1cbae6_001cbc78\n"
        ".Lf1cbae6_001cc06b:\n"
        "movl 0x20(%edx), %eax\n" /* line 2171 */
        "testb $2, 0x5a4(%eax)\n"
        "jne .Lf1cbae6_001cbc40\n"
        "testl $0x300, 0x25c64(%edx)\n"
        "jne .Lf1cbae6_001cbc40\n"
        ".Lf1cbae6_001cc08b:\n"
        "movl $1, (%esp)\n" /* line 2197 */
        "calll CG_MenuShowNotify\n"
        "movl $1, %ebx\n"
        "movl -0x4c(%ebp), %ecx\n"
        "movl %ecx, -0x94(%ebp)\n"
        "testl $0x30000, -0x94(%ebp)\n" /* line 2206 */
        "je .Lf1cbae6_001cbc50\n"
        ".Lf1cbae6_001cc0b5:\n"
        "movl $4, (%esp)\n" /* line 2208 */
        "calll CG_MenuShowNotify\n"
        "movl $1, %ebx\n"
        "movl -0x4c(%ebp), %esi\n"
        "movl %esi, -0x94(%ebp)\n"
        "testl $0x2300, -0x90(%ebp)\n" /* line 2149 */
        "je .Lf1cbae6_001cbc60\n"
        ".Lf1cbae6_001cc0df:\n"
        "movl $3, (%esp)\n" /* line 2151 */
        "calll CG_MenuShowNotify\n"
        "jmp .Lf1cbae6_001cbc78\n"
        ".Lf1cbae6_001cc0f0:\n"
        "movl $str_002b701c, 4(%esp)\n" /* line 2420 */
        "movl imp_cgDC, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_CloseByName\n"
        "movl $0, 0x2be4c(%esi)\n" /* line 2421 */
        "jmp .Lf1cbae6_001cbb16\n"
        ".Lf1cbae6_001cc114:\n"
        "calll CL_GetLocalClientActiveCount\n" /* line 2325 */
        "subl $1, %eax\n"
        "je .Lf1cbae6_001cc189\n"
        "movl $str_002a79e8, 4(%esp)\n" /* line 2328 */
        "movl imp_cgDC, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        ".Lf1cbae6_001cc133:\n"
        "testl %eax, %eax\n" /* line 2329 */
        "je .Lf1cbae6_001cc147\n"
        "movl $4, 4(%esp)\n" /* line 2330 */
        "movl %eax, (%esp)\n"
        "calll Window_RemoveDynamicFlags\n"
        ".Lf1cbae6_001cc147:\n"
        "movl imp_cg, %ecx\n" /* line 2331 */
        "movl (%ecx), %eax\n"
        "movl $0, 0x2c5c0(%eax)\n"
        "jmp .Lf1cbae6_001cbd39\n"
        ".Lf1cbae6_001cc15e:\n"
        "movl $3, (%esp)\n" /* line 2156 */
        "calll CG_MenuShowNotify\n"
        "jmp .Lf1cbae6_001cbc70\n"
        ".Lf1cbae6_001cc16f:\n"
        "movl $str_002b7028, 4(%esp)\n" /* line 2278 */
        "movl imp_cgDC, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        "jmp .Lf1cbae6_001cbe8a\n"
        ".Lf1cbae6_001cc189:\n"
        "movl $str_002a79e0, 4(%esp)\n" /* line 2326 */
        "movl imp_cgDC, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        "jmp .Lf1cbae6_001cc133\n"
        ".Lf1cbae6_001cc1a0:\n"
        "movl $str_002b5978, 4(%esp)\n" /* line 2304 */
        "movl imp_cgDC, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        "jmp .Lf1cbae6_001cbf3e\n"
        ".Lf1cbae6_001cc1ba:\n"
        "movl $str_002b7058, 4(%esp)\n" /* line 2379 */
        "movl imp_cgDC, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        "jmp .Lf1cbae6_001cbfad\n"
        ".Lf1cbae6_001cc1d4:\n"
        "movl $str_00221984, 4(%esp)\n" /* line 2355 */
        "movl imp_cgDC, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        "jmp .Lf1cbae6_001cc017\n"
    );
}

/* line 2507 */
static __attribute__((naked))
unsigned int CG_DrawSoundOverlay(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2507 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x55c, %esp\n"
        /* { scope 1 */
        "leal -0x1c(%ebp), %eax\n" /* line 2526 | cpu */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x40, 8(%esp)\n"
        "leal -0x51c(%ebp), %eax\n" /* info */
        "movl %eax, 4(%esp)\n"
        "movl imp_cg_drawSoundOverlay, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SND_GetSoundOverlay\n"
        "movl %eax, -0x530(%ebp)\n" /* count */
        "testl %eax, %eax\n" /* line 2527 */
        "jle .Lf1cc1f0_001cc3c1\n"
        "movl $str_00219b04, (%esp)\n" /* line 2545 */
        "calll Dvar_GetString\n"
        "movl %eax, %edi\n" /* provider */
        "movl $str_002189d4, (%esp)\n" /* line 2547 */
        "calll Dvar_GetInt\n"
        "movl %eax, %esi\n" /* bits */
        "movl $str_002189cc, (%esp)\n" /* line 2548 */
        "calll Dvar_GetInt\n"
        "movl %eax, %ebx\n" /* khz */
        "movl $str_002189e0, (%esp)\n" /* line 2549 */
        "calll Dvar_GetBool\n"
        "cmpb $1, %al\n" /* line 2552 */
        "sbbl %eax, %eax\n"
        "addl $2, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n" /* khz */
        "movl %esi, 0xc(%esp)\n" /* bits */
        "movl %edi, 8(%esp)\n" /* provider */
        "movl -0x1c(%ebp), %eax\n" /* cpu */
        "movl %eax, 4(%esp)\n"
        "movl $str_002b7084, (%esp)\n" /* "CPU: ^3%%%i ^73D provider: ^3%s ^7bits: ^3%i ^7kHz: ^3%i ^7c" */
        "calll va\n"
        "movl $0, 0x1c(%esp)\n" /* line 2556 */
        "movl $0x41200000, %ebx\n" /* khz */
        "movl %ebx, 0x18(%esp)\n" /* khz */
        "movl $1, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl imp_colorWhite, %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x42a40000, 4(%esp)\n"
        "movl $0x40000000, (%esp)\n"
        "calll CG_DrawStringExt\n"
        "movss lit4_002eda1c, %xmm0\n" /* 92.0f */
        "movss %xmm0, -0x52c(%ebp)\n" /* y */
        "xorl %edi, %edi\n" /* provider */
        "leal -0x51c(%ebp), %esi\n" /* info, bits */
        "jmp .Lf1cc1f0_001cc3a0\n"
        ".Lf1cc1f0_001cc2f5:\n"
        "cvtss2sd 0x10(%esi), %xmm0\n" /* line 2567 | bits */
        "movsd %xmm0, 0x20(%esp)\n"
        "movl 0xc(%esi), %eax\n" /* bits */
        "movl %eax, 0x1c(%esp)\n"
        "cvtss2sd 8(%esi), %xmm0\n" /* bits */
        "movsd %xmm0, 0x14(%esp)\n"
        "cvtss2sd 4(%esi), %xmm0\n" /* bits */
        "movsd %xmm0, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* provider */
        "movl $str_002b70cc, (%esp)\n" /* "%2i %-50s vol^3%04.2f ^7rvol^3%04.2f ^7dist^3%5i ^7pit^3%04." */
        "calll va\n"
        "movl %eax, %edx\n"
        ".Lf1cc1f0_001cc333:\n"
        "movl $0, 0x1c(%esp)\n" /* line 2570 */
        "movl $0x41200000, 0x18(%esp)\n"
        "movl $1, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl imp_colorWhite, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movss -0x52c(%ebp), %xmm0\n" /* y */
        "movss %xmm0, 4(%esp)\n"
        "movl $0x40000000, (%esp)\n"
        "calll CG_DrawStringExt\n"
        "movss lit4_002ed6b4, %xmm0\n" /* line 2571 | 10.0f */
        "addss -0x52c(%ebp), %xmm0\n" /* y */
        "movss %xmm0, -0x52c(%ebp)\n" /* y */
        "addl $1, %edi\n" /* line 2559 | provider */
        "addl $0x14, %esi\n" /* bits */
        "cmpl %edi, -0x530(%ebp)\n" /* provider, count */
        "je .Lf1cc1f0_001cc3c1\n"
        ".Lf1cc1f0_001cc3a0:\n"
        "movl (%esi), %edx\n" /* line 2561 | bits */
        "testl %edx, %edx\n"
        "jne .Lf1cc1f0_001cc2f5\n"
        "movl %edi, 4(%esp)\n" /* line 2563 | provider */
        "movl $str_002afbe0, (%esp)\n" /* "%2i" */
        "calll va\n"
        "movl %eax, %edx\n"
        "jmp .Lf1cc1f0_001cc333\n"
        /* } scope */
        ".Lf1cc1f0_001cc3c1:\n"
        "addl $0x55c, %esp\n" /* line 2573 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2715 */
static __attribute__((naked))
unsigned int CG_DrawMaterial(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2715 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x207c, %esp\n"
        /* { scope 1 */
        "movl imp_cg, %eax\n" /* line 2723 */
        "movl (%eax), %edx\n"
        "movl $__mh_execute_header, 0x14(%esp)\n"
        "leal -0x2058(%ebp), %eax\n" /* szContents */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x1058(%ebp), %edi\n" /* szSurfaceFlags */
        "movl %edi, 0xc(%esp)\n"
        "leal -0x58(%ebp), %esi\n" /* szName */
        "movl %esi, 8(%esp)\n"
        "leal 0x28594(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "addl $0x28588, %edx\n"
        "movl %edx, (%esp)\n"
        "calll CL_PickMaterial\n"
        "testl %eax, %eax\n"
        "je .Lf1cc3ce_001cc4b5\n"
        "movl $5, 0x10(%esp)\n" /* line 2727 */
        "movl imp_colorWhite, %ebx\n"
        "movl %ebx, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl $0x43700000, 4(%esp)\n"
        "movl $0x41000000, %esi\n"
        "movl %esi, (%esp)\n"
        "calll CG_DrawSmallDevStringColor\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "addss lit4_002ed6e8, %xmm1\n" /* 240.0f */
        "movl $5, 0x10(%esp)\n" /* line 2728 */
        "movl %ebx, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movss %xmm1, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "movss %xmm1, -0x2068(%ebp)\n"
        "calll CG_DrawSmallDevStringColor\n"
        "movl $5, 0x10(%esp)\n" /* line 2729 */
        "movl %ebx, 0xc(%esp)\n"
        "leal -0x2058(%ebp), %edx\n" /* szContents */
        "movl %edx, 8(%esp)\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0x2068(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll CG_DrawSmallDevStringColor\n"
        /* } scope */
        ".Lf1cc3ce_001cc4b5:\n"
        "addl $0x207c, %esp\n" /* line 2731 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2896 */
__attribute__((naked))
unsigned int CG_ShakeCamera(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2896 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        /* { scope 1 */
        "movl imp_cg, %edx\n" /* line 2904 */
        "movl (%edx), %eax\n"
        "cvtsi2ssl 0x25bb0(%eax), %xmm0\n"
        "divss lit4_002ed804, %xmm0\n" /* 600.0f */
        "movss %xmm0, -0x20(%ebp)\n" /* sx */
        "pxor %xmm1, %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n" /* bx */
        "movaps %xmm1, %xmm4\n"
        "movaps %xmm1, %xmm3\n"
        "xorl %edi, %edi\n" /* i */
        "movl $0, -0x4c(%ebp)\n"
        "movl $0x2c500, %esi\n"
        "movl %edx, %eax\n"
        "movl (%eax), %ecx\n" /* line 2907 */
        "leal (%ecx, %esi), %edx\n"
        "leal 0xc(%edx), %ebx\n" /* shake */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x25bb0(%ecx), %eax\n" /* line 2816 */
        "subl 0xc(%edx), %eax\n" /* line 2817 */
        "js .Lf1cc4c0_001cc525\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "ucomiss 8(%ebx), %xmm1\n"
        "jb .Lf1cc4c0_001cc55a\n"
        /* } scope */
        /* } scope */
        ".Lf1cc4c0_001cc525:\n"
        "addl $1, %edi\n" /* line 2905 | i */
        "addl $0x24, %esi\n"
        "addl $0x24, -0x4c(%ebp)\n"
        "cmpl $4, %edi\n" /* i */
        "je .Lf1cc4c0_001cc627\n"
        ".Lf1cc4c0_001cc538:\n"
        "movl imp_cg, %eax\n"
        "movl (%eax), %ecx\n" /* line 2907 */
        "leal (%ecx, %esi), %edx\n"
        "leal 0xc(%edx), %ebx\n" /* shake */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x25bb0(%ecx), %eax\n" /* line 2816 */
        "subl 0xc(%edx), %eax\n" /* line 2817 */
        "js .Lf1cc4c0_001cc525\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "ucomiss 8(%ebx), %xmm1\n"
        "jae .Lf1cc4c0_001cc525\n"
        ".Lf1cc4c0_001cc55a:\n"
        "leal 0x28588(%ecx), %eax\n" /* line 2824 */
        "movl %eax, 4(%esp)\n"
        "leal 0x1c(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0x68(%ebp)\n"
        "movss %xmm3, -0x88(%ebp)\n"
        "calll Vec3Distance\n"
        "fstps -0x8c(%ebp)\n"
        "movss -0x8c(%ebp), %xmm0\n"
        "divss 0xc(%ebx), %xmm0\n" /* line 2826 */
        "movss lit4_002ed5d0, %xmm2\n" /* 1.0f */
        "subss %xmm0, %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        "movss -0x68(%ebp), %xmm1\n" /* line 2829 */
        "divss 8(%ebx), %xmm1\n"
        "movss lit4_002ed5d0, %xmm2\n" /* 1.0f */
        "subss %xmm1, %xmm2\n"
        "movaps %xmm2, %xmm1\n"
        "mulss 4(%ebx), %xmm1\n"
        "pxor %xmm4, %xmm4\n" /* line 2831 */
        "ucomiss %xmm1, %xmm4\n"
        "movss -0x88(%ebp), %xmm3\n"
        "jae .Lf1cc4c0_001cc525\n"
        "ucomiss %xmm4, %xmm0\n" /* line 2834 */
        "jb .Lf1cc4c0_001cc7b8\n"
        "mulss %xmm1, %xmm0\n" /* line 2835 */
        ".Lf1cc4c0_001cc5de:\n"
        "movss %xmm0, 0x1c(%ebx)\n" /* line 2839 */
        "movss %xmm1, 0x20(%ebx)\n" /* line 2840 */
        /* } scope */
        /* } scope */
        "movl -0x4c(%ebp), %eax\n" /* line 2910 */
        "movl imp_cg, %edx\n"
        "addl (%edx), %eax\n"
        "movss 0x2c528(%eax), %xmm0\n"
        "ucomiss %xmm3, %xmm0\n"
        "jbe .Lf1cc4c0_001cc525\n"
        "movss 0x2c52c(%eax), %xmm1\n" /* line 2913 */
        "movss %xmm1, -0x1c(%ebp)\n" /* bx */
        "movaps %xmm0, %xmm3\n"
        "addl $1, %edi\n" /* line 2905 | i */
        "addl $0x24, %esi\n"
        "addl $0x24, -0x4c(%ebp)\n"
        "cmpl $4, %edi\n" /* i */
        "jne .Lf1cc4c0_001cc538\n"
        ".Lf1cc4c0_001cc627:\n"
        "movl imp_cg, %eax\n" /* line 2918 */
        "movl (%eax), %ebx\n" /* shake */
        "movss 0x2c5a0(%ebx), %xmm2\n" /* shake */
        "ucomiss %xmm3, %xmm2\n"
        "jbe .Lf1cc4c0_001cc780\n"
        "movss %xmm2, -0x1c(%ebp)\n" /* bx */
        "ucomiss %xmm2, %xmm4\n" /* line 2924 */
        "jae .Lf1cc4c0_001cc78c\n"
        ".Lf1cc4c0_001cc64d:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 2930 | 1.0f */
        "minss %xmm2, %xmm0\n"
        "movaps %xmm0, %xmm2\n"
        "cvtss2sd -0x20(%ebp), %xmm0\n" /* line 2934 | sx */
        "movsd %xmm0, -0x28(%ebp)\n"
        "mulsd lit8_00307d78, %xmm0\n" /* 25.132741228718345 */
        "cvtss2sd 0x2c59c(%ebx), %xmm1\n" /* shake */
        "addsd %xmm1, %xmm0\n"
        "movsd %xmm0, (%esp)\n"
        "movss %xmm2, -0x78(%ebp)\n"
        "calll sin\n"
        "fstpl -0x38(%ebp)\n"
        "cvtsd2ss -0x38(%ebp), %xmm0\n"
        "mulss -0x1c(%ebp), %xmm0\n" /* bx */
        "mulss lit4_002ed6c8, %xmm0\n" /* 18.0f */
        "movss -0x78(%ebp), %xmm2\n"
        "mulss %xmm2, %xmm0\n"
        "addss 0x285c8(%ebx), %xmm0\n" /* shake */
        "movss %xmm0, 0x285c8(%ebx)\n" /* shake */
        "movl imp_cg, %eax\n" /* line 2938 */
        "movl (%eax), %ebx\n" /* shake */
        "movsd -0x28(%ebp), %xmm0\n"
        "mulsd lit8_00307d80, %xmm0\n" /* 47.12388980384689 */
        "cvtss2sd 0x2c59c(%ebx), %xmm1\n" /* shake */
        "addsd %xmm1, %xmm0\n"
        "movsd %xmm0, (%esp)\n"
        "movss %xmm2, -0x78(%ebp)\n"
        "calll sin\n"
        "fstpl -0x40(%ebp)\n"
        "cvtsd2ss -0x40(%ebp), %xmm0\n"
        "mulss -0x1c(%ebp), %xmm0\n" /* bx */
        "mulss lit4_002ed6a8, %xmm0\n" /* 16.0f */
        "movss -0x78(%ebp), %xmm2\n"
        "mulss %xmm2, %xmm0\n"
        "addss 0x285cc(%ebx), %xmm0\n" /* shake */
        "movss %xmm0, 0x285cc(%ebx)\n" /* shake */
        "movsd -0x28(%ebp), %xmm0\n" /* line 2942 */
        "mulsd lit8_00307d88, %xmm0\n" /* 37.69911184307752 */
        "movsd %xmm0, -0x28(%ebp)\n"
        "cvtss2sd 0x2c59c(%ebx), %xmm0\n" /* shake */
        "addsd -0x28(%ebp), %xmm0\n"
        "movsd %xmm0, (%esp)\n"
        "movss %xmm2, -0x78(%ebp)\n"
        "calll sin\n"
        "fstpl -0x48(%ebp)\n"
        "cvtsd2ss -0x48(%ebp), %xmm0\n"
        "mulss -0x1c(%ebp), %xmm0\n" /* bx */
        "movss %xmm0, -0x1c(%ebp)\n" /* bx */
        "mulss lit4_002ed6b4, %xmm0\n" /* 10.0f */
        "movss -0x78(%ebp), %xmm2\n"
        "mulss %xmm0, %xmm2\n"
        "addss 0x285d0(%ebx), %xmm2\n" /* shake */
        "movss %xmm2, 0x285d0(%ebx)\n" /* shake */
        /* } scope */
        "addl $0x9c, %esp\n" /* line 2944 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1cc4c0_001cc780:\n"
        "movaps %xmm3, %xmm2\n" /* line 2918 */
        "ucomiss %xmm2, %xmm4\n" /* line 2924 */
        "jb .Lf1cc4c0_001cc64d\n"
        ".Lf1cc4c0_001cc78c:\n"
        "calll crandom\n" /* line 2926 */
        "fstps -0x2c(%ebp)\n"
        "cvtss2sd -0x2c(%ebp), %xmm0\n"
        "mulsd lit8_00307c28, %xmm0\n" /* 3.141592653589793 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, 0x2c59c(%ebx)\n" /* shake */
        /* } scope */
        "addl $0x9c, %esp\n" /* line 2944 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1cc4c0_001cc7b8:\n"
        "divss %xmm1, %xmm0\n" /* line 2837 */
        "jmp .Lf1cc4c0_001cc5de\n"
    );
}

/* line 3216 */
static __attribute__((naked))
qboolean CG_DrawFollow(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3216 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        /* { scope 1 */
        "movl imp_cg, %eax\n" /* line 3225 */
        "movl (%eax), %ebx\n" /* font */
        "movl 0x24(%ebx), %eax\n" /* font */
        "testb $0x40, 0x1a(%eax)\n"
        "je .Lf1cc7c2_001cc952\n"
        "movl 0x2cd14(%ebx), %ecx\n" /* line 3229 | font */
        "testl %ecx, %ecx\n"
        "jne .Lf1cc7c2_001cc952\n"
        "movl 0xd8(%eax), %eax\n" /* line 3232 */
        "leal (%eax, %eax, 4), %ecx\n"
        "movl %ecx, %edx\n"
        "shll $4, %edx\n"
        "subl %ecx, %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "leal (, %edx, 8), %eax\n"
        "movl 0xe0914(%eax, %ebx), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf1cc7c2_001cc95c\n"
        "movl $str_0022292c, -0x1c(%ebp)\n" /* clientName */
        ".Lf1cc7c2_001cc81d:\n"
        "movl $0, 8(%esp)\n" /* line 3237 */
        "movl $str_002b710c, 4(%esp)\n" /* "spectator follow string" */
        "movl $str_002b7124, (%esp)\n" /* "CGAME_FOLLOWING" */
        "calll SEH_LocalizeTextMessage\n"
        "movl %eax, %esi\n" /* followingString */
        "calll CL_IsRenderingSplitScreen\n" /* line 3240 */
        "testb %al, %al\n"
        "je .Lf1cc7c2_001cc96b\n"
        "movl $0x3f000000, %edi\n" /* scale */
        ".Lf1cc7c2_001cc84d:\n"
        "movl $0x3eaaaaab, 4(%esp)\n" /* line 3243 */
        "movl $0, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %eax, %ebx\n" /* font */
        "movl %edi, 0xc(%esp)\n" /* line 3245 | scale */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* followingString */
        "calll UI_TextWidth\n"
        "movl $3, 0x24(%esp)\n" /* line 3247 */
        "movl imp_colorWhite, %edx\n"
        "movl %edx, 0x20(%esp)\n"
        "movl %edi, 0x1c(%esp)\n" /* scale */
        "movl $1, 0x18(%esp)\n"
        "movl $7, 0x14(%esp)\n"
        "movl $0x42200000, 0x10(%esp)\n"
        "negl %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* font */
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* followingString */
        "calll UI_DrawText\n"
        "movl %edi, 0xc(%esp)\n" /* line 3249 | scale */
        "movl %ebx, 8(%esp)\n" /* font */
        "movl $0, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* clientName */
        "movl %eax, (%esp)\n"
        "calll UI_TextWidth\n"
        "movl $3, 0x24(%esp)\n" /* line 3251 */
        "movl imp_colorWhite, %edx\n"
        "movl %edx, 0x20(%esp)\n"
        "movl %edi, 0x1c(%esp)\n" /* scale */
        "movl $1, 0x18(%esp)\n"
        "movl $7, 0x14(%esp)\n"
        "movl $0x42820000, 0x10(%esp)\n"
        "negl %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* font */
        "movl $0x7fffffff, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* clientName */
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 3254 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1cc7c2_001cc952:\n"
        "xorl %eax, %eax\n" /* line 3253 */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 3254 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1cc7c2_001cc95c:\n"
        "leal 0xe0920(%eax, %ebx), %ebx\n" /* line 3233 | font */
        "movl %ebx, -0x1c(%ebp)\n" /* font, clientName */
        "jmp .Lf1cc7c2_001cc81d\n"
        ".Lf1cc7c2_001cc96b:\n"
        "movl $0x3eaaaaab, %edi\n" /* line 3240 | scale */
        "jmp .Lf1cc7c2_001cc84d\n"
    );
}

/* line 3257 */
__attribute__((naked))
unsigned int CG_DrawPlayerSprites(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3257 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl imp_cg, %ecx\n" /* line 3263 */
        "movl (%ecx), %eax\n"
        "movl 0x24(%eax), %eax\n"
        "movl 0x26b4(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jle .Lf1cc976_001cc9f9\n"
        "xorl %esi, %esi\n" /* entityIndex */
        "movl imp_cg_entities, %edi\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf1cc976_001cc9b9\n"
        ".Lf1cc976_001cc9a3:\n"
        "addl $1, %esi\n" /* entityIndex */
        "addl $0xf0, %ebx\n"
        "movl (%ecx), %eax\n"
        "movl 0x24(%eax), %eax\n"
        "cmpl %esi, 0x26b4(%eax)\n" /* entityIndex */
        "jle .Lf1cc976_001cc9f9\n"
        ".Lf1cc976_001cc9b9:\n"
        "movl 0x26bc(%ebx, %eax), %edx\n" /* line 3266 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "shll $2, %eax\n"
        "addl (%edi), %eax\n"
        "cmpl $1, 0xf4(%eax)\n" /* line 3270 */
        "jne .Lf1cc976_001cc9a3\n"
        "movl %eax, (%esp)\n" /* line 3273 */
        "calll CG_PlayerSprites\n"
        "movl -0x1c(%ebp), %ecx\n"
        "addl $1, %esi\n" /* line 3263 | entityIndex */
        "addl $0xf0, %ebx\n"
        "movl (%ecx), %eax\n"
        "movl 0x24(%eax), %eax\n"
        "cmpl %esi, 0x26b4(%eax)\n" /* entityIndex */
        "jg .Lf1cc976_001cc9b9\n"
        /* } scope */
        ".Lf1cc976_001cc9f9:\n"
        "addl $0x2c, %esp\n" /* line 3275 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3404 */
__attribute__((naked))
unsigned int CG_DrawActive(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3404 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        /* { scope 1 */
        "movl imp_cg, %eax\n" /* line 3409 */
        "movl (%eax), %ecx\n"
        "movl 0x25bb0(%ecx), %eax\n"
        "movl %eax, 0x285b8(%ecx)\n"
        "movl $0, 0x285c4(%ecx)\n" /* line 3410 */
        "movss 0x2a5f8(%ecx), %xmm0\n" /* line 3413 */
        "movss %xmm0, -0x1c(%ebp)\n" /* sensitivity */
        "movss 0x2cce8(%ecx), %xmm0\n" /* line 3414 */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jp .Lf1cca02_001cca46\n"
        "je .Lf1cca02_001cca50\n"
        ".Lf1cca02_001cca46:\n"
        "mulss -0x1c(%ebp), %xmm0\n" /* line 3415 | sensitivity */
        "movss %xmm0, -0x1c(%ebp)\n" /* sensitivity */
        ".Lf1cca02_001cca50:\n"
        "leal 0x2c03c(%ecx), %eax\n"
        "leal 0x2c048(%ecx), %edx\n"
        /* { scope 2 */
        "movss 0x2c03c(%ecx), %xmm0\n" /* line 240 */
        "addss 0x2c048(%ecx), %xmm0\n"
        "movss %xmm0, -0x14(%ebp)\n" /* angles */
        "movss 4(%eax), %xmm0\n" /* line 241 */
        "addss 4(%edx), %xmm0\n"
        "movss %xmm0, -0x10(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 242 */
        "addss 8(%edx), %xmm0\n"
        "movss %xmm0, -0xc(%ebp)\n"
        /* } scope */
        "leal -0x14(%ebp), %eax\n" /* line 3418 | angles */
        "movl %eax, (%esp)\n"
        "calll CL_SetUserCmdAimValues\n"
        "movl imp_cg, %eax\n" /* line 3419 */
        "movl (%eax), %ebx\n"
        "movss -0x1c(%ebp), %xmm0\n" /* sensitivity */
        "movss %xmm0, 8(%esp)\n"
        "movl 0x2be70(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x2be50(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_SetUserCmdValue\n"
        "leal 0x28570(%ebx), %eax\n" /* line 3426 */
        "movl %eax, (%esp)\n"
        "calll CL_RenderScene\n"
        "calll CL_IsRenderingSplitScreen\n" /* line 3428 */
        "testb %al, %al\n"
        "jne .Lf1cca02_001ccafd\n"
        "movl 0x2cce0(%ebx), %eax\n" /* line 3393 */
        "movl %eax, 8(%esp)\n"
        "movl 0x2ccdc(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x2ccd8(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_DrawShellShockSavedScreenBlend\n"
        ".Lf1cca02_001ccafd:\n"
        "calll CG_TileClear\n" /* line 3432 */
        /* } scope */
        "addl $0x34, %esp\n" /* line 3433 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 549 */
static __attribute__((naked))
unsigned int CG_DrawChatMessages(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 549 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1 */
        "movl imp_cg_chatHeight, %eax\n" /* line 566 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x44(%ebp)\n" /* chatHeight */
        "testl %eax, %eax\n" /* line 567 */
        "je .Lf1ccb08_001ccdd9\n"
        "movl imp_cg_hudChatPosition, %eax\n" /* line 570 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "cvttss2si (%eax), %edx\n"
        "movl %edx, -0x30(%ebp)\n" /* hudChatX */
        "cvttss2si 4(%eax), %eax\n" /* line 571 */
        "movl %eax, -0x34(%ebp)\n" /* hudChatY */
        "movl imp_cgs, %eax\n" /* line 573 */
        "movl (%eax), %ebx\n"
        "movl 0xba18(%ebx), %ecx\n"
        "cmpl 0xba14(%ebx), %ecx\n"
        "je .Lf1ccb08_001ccdd9\n"
        "movl imp_cg, %eax\n" /* line 575 */
        "movl (%eax), %edi\n" /* msg */
        "movl %ecx, %eax\n"
        "cltd\n"
        "idivl -0x44(%ebp)\n" /* chatHeight */
        "movl 0x25bb0(%edi), %eax\n" /* msg */
        "subl 0xb9f4(%ebx, %edx, 4), %eax\n"
        "movl imp_cg_chatTime, %edx\n"
        "movl (%edx), %edx\n"
        "cmpl 8(%edx), %eax\n"
        "jg .Lf1ccb08_001ccde1\n"
        ".Lf1ccb08_001ccb83:\n"
        "movl $0x3e555555, 4(%esp)\n" /* line 578 */
        "movl $0, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %eax, -0x38(%ebp)\n" /* font */
        "movl 0xba14(%ebx), %esi\n" /* line 579 | i */
        "subl $1, %esi\n" /* i */
        "cmpl 0xba18(%ebx), %esi\n" /* i */
        "jl .Lf1ccb08_001ccdd9\n"
        "movl %edi, -0x48(%ebp)\n" /* msg */
        "jmp .Lf1ccb08_001ccd75\n"
        ".Lf1ccb08_001ccbb7:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 582 | 1.0f */
        "movss %xmm0, -0x3c(%ebp)\n" /* alphapercent */
        "movss lit4_002ed944, %xmm0\n" /* 0.6000000238418579f */
        "movss %xmm0, -0x2c(%ebp)\n"
        ".Lf1ccb08_001ccbd1:\n"
        "movl %ecx, %eax\n" /* line 591 */
        "shll $4, %eax\n"
        "movl %ecx, %edx\n"
        "shll $8, %edx\n"
        "addl %edx, %eax\n"
        "subl %ecx, %eax\n"
        "leal 0xb170(%eax, %ebx), %eax\n"
        "movl %eax, %edi\n" /* line 593 | msg */
        "addl $0xc, %edi\n" /* msg */
        "je .Lf1ccb08_001ccbf7\n"
        "cmpb $0x5e, 0xc(%eax)\n"
        "je .Lf1ccb08_001ccdef\n"
        ".Lf1ccb08_001ccbf7:\n"
        "movl $0x3f800000, -0x28(%ebp)\n" /* line 191 | color */
        "movl $0x3f800000, -0x24(%ebp)\n" /* line 192 */
        "movl $0x3f800000, -0x20(%ebp)\n" /* line 193 */
        ".Lf1ccb08_001ccc0c:\n"
        "movss -0x28(%ebp), %xmm0\n" /* line 272 | color */
        "mulss lit4_002ed604, %xmm0\n" /* 0.25f */
        "movss %xmm0, -0x28(%ebp)\n" /* color */
        "movss -0x24(%ebp), %xmm0\n" /* line 273 */
        "mulss lit4_002ed604, %xmm0\n" /* 0.25f */
        "movss %xmm0, -0x24(%ebp)\n"
        "movss -0x20(%ebp), %xmm0\n" /* line 274 */
        "mulss lit4_002ed604, %xmm0\n" /* 0.25f */
        "movss %xmm0, -0x20(%ebp)\n"
        "movss -0x2c(%ebp), %xmm0\n" /* line 600 */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl imp_cgs, %eax\n" /* line 603 */
        "movl (%eax), %ebx\n"
        "movl 0xba14(%ebx), %eax\n"
        "subl %esi, %eax\n" /* i */
        "leal (%eax, %eax, 4), %eax\n"
        "addl %eax, %eax\n"
        "movl -0x34(%ebp), %edx\n" /* hudChatY */
        "subl %eax, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n" /* y */
        "movl $0x3e555555, 0xc(%esp)\n" /* line 604 */
        "movl -0x38(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* msg */
        "calll UI_TextWidth\n"
        "movl 0xba28(%ebx), %edx\n" /* line 606 */
        "movl %edx, 0x1c(%esp)\n"
        "leal -0x28(%ebp), %edx\n" /* color */
        "movl %edx, 0x18(%esp)\n"
        "movl $1, 0x14(%esp)\n"
        "movl $1, 0x10(%esp)\n"
        "movl $0x41200000, 0xc(%esp)\n"
        "addl $0x18, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movss -0x40(%ebp), %xmm0\n" /* y */
        "movss %xmm0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        "movss -0x3c(%ebp), %xmm0\n" /* line 608 | alphapercent */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl 0xba14(%ebx), %eax\n" /* line 611 */
        "subl %esi, %eax\n" /* i */
        "leal (%eax, %eax, 4), %eax\n"
        "addl %eax, %eax\n"
        "movl -0x34(%ebp), %edx\n" /* hudChatY */
        "subl %eax, %edx\n"
        "movl %edx, %eax\n"
        "addl $9, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movl $0x3f800000, -0x28(%ebp)\n" /* line 191 | color */
        "movl $0x3f800000, -0x24(%ebp)\n" /* line 192 */
        "movl $0x3f800000, -0x20(%ebp)\n" /* line 193 */
        "movl $3, 0x24(%esp)\n" /* line 614 */
        "leal -0x28(%ebp), %eax\n" /* color */
        "movl %eax, 0x20(%esp)\n"
        "movl $0x3e555555, 0x1c(%esp)\n"
        "movl $1, 0x18(%esp)\n"
        "movl $1, 0x14(%esp)\n"
        "movss %xmm0, 0x10(%esp)\n"
        "cvtsi2ssl -0x30(%ebp), %xmm0\n" /* hudChatX */
        "movss %xmm0, 0xc(%esp)\n"
        "movl -0x38(%ebp), %edx\n" /* font */
        "movl %edx, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* msg */
        "calll UI_DrawText\n"
        ".Lf1ccb08_001ccd63:\n"
        "subl $1, %esi\n" /* line 579 | i */
        "movl imp_cgs, %eax\n"
        "movl (%eax), %ebx\n"
        "cmpl 0xba18(%ebx), %esi\n" /* i */
        "jl .Lf1ccb08_001ccdd9\n"
        ".Lf1ccb08_001ccd75:\n"
        "movl %esi, %eax\n" /* line 581 | i */
        "cltd\n"
        "idivl -0x44(%ebp)\n" /* chatHeight */
        "movl %edx, %ecx\n"
        "movl imp_cg_chatTime, %eax\n"
        "movl (%eax), %eax\n"
        "cvtsi2ssl 8(%eax), %xmm1\n"
        "movl -0x48(%ebp), %edx\n"
        "movl 0x25bb0(%edx), %eax\n"
        "subl 0xb9f4(%ebx, %ecx, 4), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "ucomiss lit4_002ed734, %xmm1\n" /* line 582 | 200.0f */
        "ja .Lf1ccb08_001ccbb7\n"
        "divss lit4_002ed734, %xmm1\n" /* line 586 | 200.0f */
        "movss %xmm1, -0x3c(%ebp)\n" /* alphapercent */
        "pxor %xmm0, %xmm0\n" /* line 587 */
        "ucomiss %xmm1, %xmm0\n"
        "jae .Lf1ccb08_001ccd63\n"
        "movaps %xmm1, %xmm0\n" /* line 588 */
        "mulss lit4_002ed944, %xmm0\n" /* 0.6000000238418579f */
        "movss %xmm0, -0x2c(%ebp)\n"
        "jmp .Lf1ccb08_001ccbd1\n"
        /* } scope */
        ".Lf1ccb08_001ccdd9:\n"
        "addl $0x6c, %esp\n" /* line 617 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1ccb08_001ccde1:\n"
        "leal 1(%ecx), %eax\n" /* line 576 */
        "movl %eax, 0xba18(%ebx)\n"
        "jmp .Lf1ccb08_001ccb83\n"
        ".Lf1ccb08_001ccdef:\n"
        "movzbl 1(%edi), %eax\n" /* line 593 | msg */
        "testb %al, %al\n"
        "je .Lf1ccb08_001ccbf7\n"
        "cmpb $0x5e, %al\n"
        "je .Lf1ccb08_001ccbf7\n"
        "cmpb $0x2f, %al\n"
        "jle .Lf1ccb08_001ccbf7\n"
        "cmpb $0x39, %al\n"
        "jg .Lf1ccb08_001ccbf7\n"
        "leal -0x28(%ebp), %edx\n" /* line 594 | color */
        "movl %edx, 4(%esp)\n"
        "movzbl %al, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_LookupColor\n"
        "jmp .Lf1ccb08_001ccc0c\n"
    );
}

/* line 1110 */
static __attribute__((naked))
unsigned int CG_CalcCrosshairPosition(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1110 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl %eax, %esi\n" /* x */
        "movl %edx, %edi\n" /* y */
        /* { scope 1 */
        "movl imp_cg, %eax\n" /* line 1116 */
        "movl (%eax), %ebx\n"
        "movl 0x285d0(%ebx), %ecx\n" /* z */
        "movl 0x2c094(%ebx), %edx\n" /* y */
        /* { scope 2 */
        "movl 0x2c090(%ebx), %eax\n" /* line 191 */
        "movl %eax, -0x24(%ebp)\n" /* gunAng */
        "movl %edx, -0x20(%ebp)\n" /* line 192 */
        "movl %ecx, -0x1c(%ebp)\n" /* line 193 */
        /* } scope */
        "movl $0, 0xc(%esp)\n" /* line 1117 */
        "movl $0, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* gunDir */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* gunAng */
        "movl %eax, (%esp)\n"
        "calll AngleVectors\n"
        "leal 0x28594(%ebx), %eax\n" /* line 1119 | a */
        /* { scope 2 */
        "movss -0x30(%ebp), %xmm1\n" /* line 304 | gunDir */
        "movss -0x2c(%ebp), %xmm3\n"
        "movss -0x28(%ebp), %xmm4\n"
        "movaps %xmm1, %xmm2\n"
        "mulss 0x28594(%ebx), %xmm2\n"
        "movaps %xmm3, %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movaps %xmm4, %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        /* } scope */
        "pxor %xmm5, %xmm5\n" /* line 1120 */
        "ucomiss %xmm2, %xmm5\n"
        "jae .Lf1cce2a_001ccfc0\n"
        "movss 0x28580(%ebx), %xmm0\n"
        "ucomiss %xmm0, %xmm5\n"
        "jae .Lf1cce2a_001ccfc0\n"
        "ucomiss 0x28584(%ebx), %xmm5\n"
        "jae .Lf1cce2a_001ccfc0\n"
        "leal 0x285a0(%ebx), %eax\n" /* line 1124 */
        "mulss 0x285a0(%ebx), %xmm1\n" /* line 1127 */
        "mulss 4(%eax), %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "mulss 8(%eax), %xmm4\n"
        "addss %xmm4, %xmm1\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "mulsd lit8_00307c68, %xmm0\n" /* 0.008726646259971648 */
        "movsd %xmm0, (%esp)\n"
        "movss %xmm1, -0x58(%ebp)\n"
        "movss %xmm2, -0x68(%ebp)\n"
        "calll tan\n"
        "fstpl -0x40(%ebp)\n"
        "cvtsd2ss -0x40(%ebp), %xmm0\n"
        "movss -0x68(%ebp), %xmm2\n"
        "mulss %xmm2, %xmm0\n"
        "movss -0x58(%ebp), %xmm1\n"
        "divss %xmm0, %xmm1\n"
        "mulss lit4_002eda20, %xmm1\n" /* -320.0f */
        "movss %xmm1, (%esi)\n" /* x */
        "leal 0x285ac(%ebx), %eax\n" /* line 1128 */
        "movss 0x285ac(%ebx), %xmm1\n"
        "mulss -0x30(%ebp), %xmm1\n" /* gunDir */
        "movss 4(%eax), %xmm0\n"
        "mulss -0x2c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "mulss -0x28(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "cvtss2sd 0x28584(%ebx), %xmm0\n"
        "mulsd lit8_00307c68, %xmm0\n" /* 0.008726646259971648 */
        "movsd %xmm0, (%esp)\n"
        "movss %xmm1, -0x58(%ebp)\n"
        "calll tan\n"
        "fstpl -0x48(%ebp)\n"
        "cvtsd2ss -0x48(%ebp), %xmm0\n"
        "movss -0x68(%ebp), %xmm2\n"
        "mulss %xmm0, %xmm2\n"
        "movss -0x58(%ebp), %xmm1\n"
        "divss %xmm2, %xmm1\n"
        "mulss lit4_002eda24, %xmm1\n" /* -240.0f */
        "movss %xmm1, (%edi)\n" /* y */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 1129 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1cce2a_001ccfc0:\n"
        "movl $0, (%esi)\n" /* line 1122 | x */
        "movl $0, (%edi)\n" /* line 1123 | y */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 1129 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 286 */
static __attribute__((naked))
float CG_DrawFPS(float y)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 286 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movss %xmm0, -0x48(%ebp)\n"
        /* { scope 1 */
        "cmpl $0x1f, fps_index\n" /* line 303 */
        "jle .Lf1ccfd4_001cd5e0\n"
        "movl $0x7fffffff, %ebx\n" /* minTime */
        "xorl %edi, %edi\n" /* maxTime */
        "xorl %ecx, %ecx\n"
        "movl $fps_previousTimes, %edx\n"
        ".Lf1ccfd4_001cd000:\n"
        "movl (%edx), %eax\n" /* line 309 */
        "addl %eax, %ecx\n"
        "cmpl %ebx, %eax\n" /* line 310 | minTime */
        "cmovll %eax, %ebx\n" /* minTime */
        "cmpl %edi, %eax\n" /* line 312 | maxTime */
        "cmovgl %eax, %edi\n" /* maxTime */
        "addl $4, %edx\n"
        "movl $fps_index, %esi\n" /* line 286 */
        "movl $fps_index, %eax\n" /* line 307 */
        "cmpl %edx, %eax\n"
        "jne .Lf1ccfd4_001cd000\n"
        "cvtsi2ssl %ecx, %xmm0\n" /* line 316 */
        "movss %xmm0, -0x3c(%ebp)\n"
        "movaps %xmm0, %xmm3\n"
        "mulss lit4_002ed878, %xmm3\n" /* 0.03125f */
        "pxor %xmm2, %xmm2\n"
        "movl $fps_previousTimes, %eax\n"
        "movss colorWhiteFaded+16, %xmm1\n"
        ".Lf1ccfd4_001cd044:\n"
        "cvtsi2ssl (%eax), %xmm0\n" /* line 321 */
        "subss %xmm3, %xmm0\n"
        "andps %xmm1, %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "addl $4, %eax\n"
        "cmpl %eax, %esi\n" /* line 319 | color */
        "jne .Lf1ccfd4_001cd044\n"
        "mulss lit4_002ed878, %xmm2\n" /* line 323 | 0.03125f */
        "movss %xmm2, -0x40(%ebp)\n" /* variance */
        "testl %ecx, %ecx\n" /* line 325 */
        "je .Lf1ccfd4_001cd655\n"
        "testl %ebx, %ebx\n" /* line 329 | minTime */
        "jle .Lf1ccfd4_001cd66a\n"
        ".Lf1ccfd4_001cd077:\n"
        "cvtsi2ssl %ebx, %xmm0\n" /* minTime */
        "movss %xmm0, -0x38(%ebp)\n"
        ".Lf1ccfd4_001cd080:\n"
        "cvtsi2ssl %edi, %xmm0\n" /* line 428 | maxTime */
        "movss lit4_002ed5c8, %xmm1\n" /* 1000.0f */
        "movaps %xmm1, %xmm2\n"
        "divss %xmm0, %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "movss %xmm1, -0x78(%ebp)\n"
        "calll floorf\n"
        "fstps -0x4c(%ebp)\n"
        "cvttss2si -0x4c(%ebp), %eax\n"
        "movl %eax, -0x44(%ebp)\n" /* fpsMin */
        "movss -0x78(%ebp), %xmm1\n"
        "divss -0x38(%ebp), %xmm1\n"
        "addss lit4_002ed5d8, %xmm1\n" /* 0.5f */
        "movss %xmm1, (%esp)\n"
        "calll floorf\n"
        "fstps -0x50(%ebp)\n"
        "cvttss2si -0x50(%ebp), %esi\n" /* color */
        "movl imp_cg_drawFPS, %eax\n" /* line 335 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "jle .Lf1ccfd4_001cd5eb\n"
        "movl %edi, 0x10(%esp)\n" /* line 338 | maxTime */
        "movl %ebx, 0xc(%esp)\n" /* minTime */
        "movss lit4_002ed878, %xmm0\n" /* 0.03125f */
        "mulss -0x3c(%ebp), %xmm0\n"
        "cvtss2sd %xmm0, %xmm1\n"
        "movsd %xmm1, 4(%esp)\n"
        "movl $str_002b7138, (%esp)\n" /* "%1.2fmspf(%i-%i)" */
        "calll va\n"
        ".Lf1ccfd4_001cd118:\n"
        "movl $6, 0x10(%esp)\n" /* line 346 */
        "movl $colorWhiteFaded, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movss -0x48(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl $0x441b0000, %ebx\n" /* minTime */
        "movl %ebx, (%esp)\n" /* minTime */
        "calll CG_DrawBigDevStringColor\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss -0x48(%ebp), %xmm0\n"
        "movss %xmm0, -0x48(%ebp)\n"
        "movl imp_cg_drawFPS, %eax\n" /* line 349 */
        "movl (%eax), %eax\n"
        "cmpl $1, 8(%eax)\n"
        "jle .Lf1ccfd4_001cd5e0\n"
        "movl $rendererStats, (%esp)\n" /* line 360 */
        "calll CL_TrackStatistics\n"
        "movl $6, 0x10(%esp)\n" /* line 362 */
        "movl $colorGreenFaded, 0xc(%esp)\n"
        "movl $str_002b715c, 8(%esp)\n" /* "scene" */
        "movss -0x48(%ebp), %xmm1\n"
        "movss %xmm1, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* minTime */
        "calll CG_DrawSmallDevStringColor\n"
        "cvtsi2ssl %eax, %xmm2\n"
        "movss -0x48(%ebp), %xmm0\n"
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "movl $str_002b7164, (%esp)\n" /* line 364 */
        "calll va\n"
        "movl $6, 0x10(%esp)\n" /* line 365 */
        "movl $colorWhiteFaded, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movss -0x30(%ebp), %xmm1\n"
        "movss %xmm1, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* minTime */
        "calll CG_DrawSmallDevStringColor\n"
        "movl rendererStats+8, %ecx\n" /* line 366 */
        "movl $0x55555556, %esi\n" /* color */
        "movl %ecx, %eax\n"
        "imull %esi\n" /* color */
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl $6, 0x10(%esp)\n" /* line 367 */
        "movl $colorWhiteFaded, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movss -0x30(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* minTime */
        "calll CG_DrawSmallDevStringColor\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movss -0x30(%ebp), %xmm2\n"
        "addss %xmm1, %xmm2\n"
        "movss %xmm2, -0x34(%ebp)\n"
        "movl rendererStats+12, %edi\n" /* line 369 | maxTime */
        "testl %edi, %edi\n" /* maxTime */
        "jne .Lf1ccfd4_001cd6a7\n"
        ".Lf1ccfd4_001cd24c:\n"
        "movl $str_002b7190, (%esp)\n" /* line 377 */
        "calll va\n"
        "movl $6, 0x10(%esp)\n" /* line 378 */
        "movl $colorWhiteFaded, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movss -0x34(%ebp), %xmm1\n"
        "movss %xmm1, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* minTime */
        "calll CG_DrawSmallDevStringColor\n"
        "movl rendererStats, %ecx\n" /* line 379 */
        "movl %ecx, %eax\n"
        "imull %esi\n" /* color */
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl $6, 0x10(%esp)\n" /* line 380 */
        "movl $colorWhiteFaded, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* minTime */
        "calll CG_DrawSmallDevStringColor\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movss -0x34(%ebp), %xmm2\n"
        "addss %xmm1, %xmm2\n"
        "movss %xmm2, -0x2c(%ebp)\n"
        "movl $str_002b71a8, (%esp)\n" /* line 382 */
        "calll va\n"
        "movl $6, 0x10(%esp)\n" /* line 383 */
        "movl $colorWhiteFaded, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* minTime */
        "calll CG_DrawSmallDevStringColor\n"
        "movl rendererStats+4, %ecx\n" /* line 384 */
        "movl %ecx, %eax\n"
        "imull %esi\n" /* color */
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl $6, 0x10(%esp)\n" /* line 385 */
        "movl $colorWhiteFaded, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* minTime */
        "calll CG_DrawSmallDevStringColor\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movss -0x2c(%ebp), %xmm2\n"
        "addss %xmm1, %xmm2\n"
        "movss %xmm2, -0x28(%ebp)\n"
        "movl $str_002b71c0, (%esp)\n" /* line 387 */
        "calll va\n"
        "movl $6, 0x10(%esp)\n" /* line 388 */
        "movl $colorWhiteFaded, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* minTime */
        "calll CG_DrawSmallDevStringColor\n"
        "movl rendererStats+20, %eax\n" /* line 389 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl $6, 0x10(%esp)\n" /* line 390 */
        "movl $colorWhiteFaded, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movss -0x28(%ebp), %xmm1\n"
        "movss %xmm1, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* minTime */
        "calll CG_DrawSmallDevStringColor\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss -0x28(%ebp), %xmm0\n"
        "movl $6, 0x10(%esp)\n" /* line 392 */
        "movl $colorGreenFaded, 0xc(%esp)\n"
        "movl $str_002182a0, 8(%esp)\n" /* "level" */
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* minTime */
        "movss %xmm0, -0x68(%ebp)\n"
        "calll CG_DrawSmallDevStringColor\n"
        "cvtsi2ssl %eax, %xmm2\n"
        "movss -0x68(%ebp), %xmm0\n"
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        "movl $str_002b71d0, (%esp)\n" /* line 395 */
        "calll va\n"
        "movl $6, 0x10(%esp)\n" /* line 396 */
        "movl $colorWhiteFaded, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movss -0x24(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* minTime */
        "calll CG_DrawSmallDevStringColor\n"
        "movl rendererStats+32, %eax\n" /* line 397 */
        "leal 0xfffff(%eax), %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "sarl $0x14, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_00215a64, (%esp)\n" /* "%d" */
        "calll va\n"
        "movl $6, 0x10(%esp)\n" /* line 398 */
        "movl $colorWhiteFaded, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movss -0x24(%ebp), %xmm1\n"
        "movss %xmm1, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* minTime */
        "calll CG_DrawSmallDevStringColor\n"
        "cvtsi2ssl %eax, %xmm2\n"
        "movss -0x24(%ebp), %xmm0\n"
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "cmpl $0x3000000, rendererStats+40\n" /* line 422 */
        "jg .Lf1ccfd4_001cd681\n"
        "movl $str_002b71dc, (%esp)\n" /* line 425 */
        "calll va\n"
        "movl $colorWhiteFaded, %esi\n" /* color */
        ".Lf1ccfd4_001cd4cc:\n"
        "movl $6, 0x10(%esp)\n" /* line 432 */
        "movl %esi, 0xc(%esp)\n" /* color */
        "movl %eax, 8(%esp)\n"
        "movss -0x20(%ebp), %xmm1\n"
        "movss %xmm1, 4(%esp)\n"
        "movl $0x441b0000, %ebx\n" /* minTime */
        "movl %ebx, (%esp)\n" /* minTime */
        "calll CG_DrawSmallDevStringColor\n"
        "movl rendererStats+40, %eax\n" /* line 433 */
        "leal 0xfffff(%eax), %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "sarl $0x14, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_00215a64, (%esp)\n" /* "%d" */
        "calll va\n"
        "movl $6, 0x10(%esp)\n" /* line 434 */
        "movl %esi, 0xc(%esp)\n" /* color */
        "movl %eax, 8(%esp)\n"
        "movss -0x20(%ebp), %xmm2\n"
        "movss %xmm2, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* minTime */
        "calll CG_DrawSmallDevStringColor\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0x20(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "movl $str_002b7208, (%esp)\n" /* line 443 */
        "calll va\n"
        "movl $6, 0x10(%esp)\n" /* line 444 */
        "movl $colorWhiteFaded, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movss -0x1c(%ebp), %xmm2\n"
        "movss %xmm2, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* minTime */
        "calll CG_DrawSmallDevStringColor\n"
        "movl rendererStats+36, %eax\n" /* line 445 */
        "leal 0xfffff(%eax), %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "sarl $0x14, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_00215a64, (%esp)\n" /* "%d" */
        "calll va\n"
        "movl $6, 0x10(%esp)\n" /* line 446 */
        "movl $colorWhiteFaded, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* minTime */
        "calll CG_DrawSmallDevStringColor\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movss -0x1c(%ebp), %xmm2\n"
        "addss %xmm1, %xmm2\n"
        "movss %xmm2, -0x48(%ebp)\n"
        "movaps %xmm2, %xmm0\n"
        /* } scope */
        ".Lf1ccfd4_001cd5e0:\n"
        "addl $0x8c, %esp\n" /* line 478 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1ccfd4_001cd5eb:\n"
        "movss -0x40(%ebp), %xmm0\n" /* line 428 | variance */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x54(%ebp)\n"
        "cvttss2si -0x54(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n" /* color */
        "movl -0x44(%ebp), %eax\n" /* fpsMin */
        "movl %eax, 8(%esp)\n"
        "movss lit4_002eda28, %xmm0\n" /* 32000.0f */
        "divss -0x3c(%ebp), %xmm0\n"
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x58(%ebp)\n"
        "cvttss2si -0x58(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b714c, (%esp)\n" /* "%ifps(%i-%i,%i)" */
        "calll va\n"
        "jmp .Lf1ccfd4_001cd118\n"
        ".Lf1ccfd4_001cd655:\n"
        "movss lit4_002ed5d0, %xmm1\n" /* line 325 | 1.0f */
        "movss %xmm1, -0x3c(%ebp)\n"
        "testl %ebx, %ebx\n" /* line 329 | minTime */
        "jg .Lf1ccfd4_001cd077\n"
        ".Lf1ccfd4_001cd66a:\n"
        "movl $1, %ebx\n" /* minTime */
        "movss lit4_002ed5d0, %xmm2\n" /* 1.0f */
        "movss %xmm2, -0x38(%ebp)\n"
        "jmp .Lf1ccfd4_001cd080\n"
        ".Lf1ccfd4_001cd681:\n"
        "movl $0, 4(%esp)\n" /* line 430 */
        "movl $0x40480000, 8(%esp)\n"
        "movl $str_002b71f0, (%esp)\n" /* "min pc tex (%g)      " */
        "calll va\n"
        "movl $colorRedFaded, %esi\n" /* color */
        "jmp .Lf1ccfd4_001cd4cc\n"
        ".Lf1ccfd4_001cd6a7:\n"
        "movl $str_002b7178, (%esp)\n" /* line 371 */
        "calll va\n"
        "movl $6, 0x10(%esp)\n" /* line 372 */
        "movl $colorWhiteFaded, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* minTime */
        "calll CG_DrawSmallDevStringColor\n"
        "movl rendererStats+12, %ecx\n" /* line 373 */
        "movl %ecx, %eax\n"
        "imull %esi\n" /* color */
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl $6, 0x10(%esp)\n" /* line 374 */
        "movl $colorWhiteFaded, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* minTime */
        "calll CG_DrawSmallDevStringColor\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss -0x34(%ebp), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "jmp .Lf1ccfd4_001cd24c\n"
    );
}

/* line 2610 */
__attribute__((naked))
unsigned int CG_DrawBoldGameMessages(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2610 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "calll CG_ScoreboardDisplayed\n" /* line 2619 */
        "testl %eax, %eax\n"
        "jne .Lf1cd736_001cd76c\n"
        "movl $0x3f800000, %eax\n"
        ".Lf1cd736_001cd74a:\n"
        "movl $3, 0xc(%esp)\n" /* line 2634 */
        "movl %eax, 8(%esp)\n"
        "movl $0xffffffc4, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Con_DrawBoldMessages\n"
        /* } scope */
        ".Lf1cd736_001cd76a:\n"
        "leave\n" /* line 2635 */
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1cd736_001cd76c:\n"
        "movl $0x64, 8(%esp)\n" /* line 2623 */
        "movl $0x64, 4(%esp)\n"
        "movl imp_cg, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x2b538(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_FadeColor\n"
        "testl %eax, %eax\n" /* line 2624 */
        "je .Lf1cd736_001cd76a\n"
        "movl 0xc(%eax), %eax\n" /* line 2627 */
        "jmp .Lf1cd736_001cd74a\n"
    );
}

/* line 1323 */
__attribute__((naked))
unsigned int CG_DrawTurretCrossHair(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1323 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x50, %esp\n"
        /* { scope 1 */
        "movl imp_cg_drawTurretCrosshair, %eax\n" /* line 1341 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1cd79a_001cd8de\n"
        "movl imp_cg_paused, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1cd79a_001cd8de\n"
        "movl imp_cg, %eax\n" /* line 1348 */
        "movl (%eax), %esi\n"
        "movl 0x26158(%esi), %edx\n"
        "movl imp_cg_entities, %eax\n"
        "movl (%eax), %ecx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movl 0x1b8(%ecx, %eax, 4), %ebx\n" /* weapIndex */
        "testl %ebx, %ebx\n" /* line 1349 | weapIndex */
        "je .Lf1cd79a_001cd8de\n"
        "movl %ebx, (%esp)\n" /* line 1352 | weapIndex */
        "calll BG_GetWeaponDef\n"
        "movl %eax, %ecx\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 1355 | weapIndex */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n" /* weapIndex */
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %edx\n"
        "leal (%edx, %eax, 4), %ebx\n" /* weapIndex */
        "movl 0x178(%ebx), %eax\n" /* line 1356 | weapIndex */
        "testl %eax, %eax\n"
        "je .Lf1cd79a_001cd8de\n"
        "movl imp_cg_crosshairAlpha, %eax\n" /* line 1359 */
        "movl (%eax), %edx\n"
        "movss lit4_002ed738, %xmm0\n" /* 0.009999999776482582f */
        "ucomiss 8(%edx), %xmm0\n"
        "ja .Lf1cd79a_001cd8de\n"
        "movl 0x25bd0(%esi), %eax\n" /* line 1311 */
        "testl $0x100000, %eax\n"
        "je .Lf1cd79a_001cd8e5\n"
        "movl $0x3e800000, %eax\n" /* line 191 */
        "movl %eax, -0x18(%ebp)\n" /* reticleColor */
        "movl $0x3f800000, -0x14(%ebp)\n" /* line 192 */
        "movl %eax, -0x10(%ebp)\n" /* line 193 */
        ".Lf1cd79a_001cd85a:\n"
        "movl 8(%edx), %eax\n" /* line 1319 */
        "movl %eax, -0xc(%ebp)\n"
        "cvtsi2ssl 0x120(%ecx), %xmm1\n" /* line 1363 */
        "movss %xmm1, -0x28(%ebp)\n" /* line 1364 */
        "calll CL_IsRenderingSplitScreen\n"
        "testb %al, %al\n"
        "movss -0x28(%ebp), %xmm1\n"
        "je .Lf1cd79a_001cd87f\n"
        "addss %xmm1, %xmm1\n" /* line 1365 */
        ".Lf1cd79a_001cd87f:\n"
        "movaps %xmm1, %xmm0\n" /* line 1368 */
        "mulss lit4_002ed63c, %xmm0\n" /* -0.5f */
        "movl 0x178(%ebx), %eax\n" /* line 1375 | weapIndex */
        "movl %eax, 0x2c(%esp)\n"
        "leal -0x18(%ebp), %eax\n" /* reticleColor */
        "movl %eax, 0x28(%esp)\n"
        "movl $0x3f800000, %eax\n"
        "movl %eax, 0x24(%esp)\n"
        "movl %eax, 0x20(%esp)\n"
        "xorl %eax, %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl %eax, 0x18(%esp)\n"
        "movl $2, 0x14(%esp)\n"
        "movl $2, 0x10(%esp)\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movss %xmm1, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "movss %xmm0, (%esp)\n"
        "calll CL_DrawStretchPic\n"
        /* } scope */
        ".Lf1cd79a_001cd8de:\n"
        "addl $0x50, %esp\n" /* line 1376 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1cd79a_001cd8e5:\n"
        "testl $0x200000, %eax\n" /* line 1313 */
        "je .Lf1cd79a_001cd910\n"
        "movl imp_cg_crosshairEnemyColor, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1cd79a_001cd910\n"
        "movl $0x3f800000, -0x18(%ebp)\n" /* line 191 | reticleColor */
        "movl $0x3e800000, %eax\n" /* line 192 */
        "movl %eax, -0x14(%ebp)\n"
        "movl %eax, -0x10(%ebp)\n" /* line 193 */
        "jmp .Lf1cd79a_001cd85a\n"
        ".Lf1cd79a_001cd910:\n"
        "movl $0x3f800000, %eax\n" /* line 191 */
        "movl %eax, -0x18(%ebp)\n" /* reticleColor */
        "movl %eax, -0x14(%ebp)\n" /* line 192 */
        "movl %eax, -0x10(%ebp)\n" /* line 193 */
        "jmp .Lf1cd79a_001cd85a\n"
    );
}

/* line 3066 */
static __attribute__((naked))
unsigned int CG_DrawSpectatorMessage(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3066 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x27c, %esp\n"
        /* { scope 1: binding */
        "movl imp_cg_descriptiveText, %eax\n" /* line 3093 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1cd924_001cd948\n"
        /* } scope */
        ".Lf1cd924_001cd93d:\n"
        "addl $0x27c, %esp\n" /* line 3213 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: binding */
        ".Lf1cd924_001cd948:\n"
        "calll CL_GetKeyCatchers\n" /* line 3097 */
        "testb $8, %al\n"
        "jne .Lf1cd924_001cd93d\n"
        "movl imp_cg, %eax\n" /* line 3102 */
        "movl (%eax), %esi\n" /* i */
        "movl 0x24(%esi), %eax\n" /* i */
        "testl $0x3000000, 0x18(%eax)\n"
        "je .Lf1cd924_001cd93d\n"
        "calll Controls_GetConfig\n" /* line 3105 */
        "movl $0x3e555555, %ebx\n" /* line 3119 */
        "movl %ebx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %eax, -0x250(%ebp)\n" /* font */
        "movl %ebx, 4(%esp)\n" /* line 3177 */
        "movl %eax, (%esp)\n"
        "calll UI_TextHeight\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x24c(%ebp)\n" /* lineHeight */
        "mulss lit4_002ed628, %xmm0\n" /* line 3179 | -2.0f */
        "addss lit4_002eda2c, %xmm0\n" /* 436.0f */
        "movss %xmm0, -0x258(%ebp)\n" /* y */
        "movl 0x24(%esi), %eax\n" /* line 3183 | i */
        "testb $1, 0x1b(%eax)\n"
        "jne .Lf1cd924_001cdb16\n"
        "movl $0, -0x254(%ebp)\n" /* lineNum */
        ".Lf1cd924_001cd9cb:\n"
        "movl imp_cg, %eax\n" /* line 3194 */
        "movl (%eax), %eax\n"
        "movl 0x24(%eax), %eax\n"
        "testb $2, 0x1b(%eax)\n"
        "jne .Lf1cd924_001cdad7\n"
        ".Lf1cd924_001cd9df:\n"
        "movl -0x254(%ebp), %eax\n" /* line 3203 | lineNum */
        "testl %eax, %eax\n"
        "jle .Lf1cd924_001cd93d\n"
        "xorl %esi, %esi\n" /* i */
        "leal -0x140(%ebp), %edi\n" /* binding */
        "jmp .Lf1cd924_001cda93\n"
        ".Lf1cd924_001cd9fa:\n"
        "movl -0x40(%ebp, %ebx), %eax\n" /* line 3208 */
        "movl %eax, (%esp)\n"
        "calll UI_SafeTranslateString\n"
        "movl %edi, 4(%esp)\n" /* line 3209 */
        "movl %eax, (%esp)\n"
        "calll UI_ReplaceConversionString\n"
        "movl $3, 0x24(%esp)\n" /* line 3210 */
        "movl imp_colorWhite, %edx\n"
        "movl %edx, 0x20(%esp)\n"
        "movl $0x3e555555, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movss -0x258(%ebp), %xmm0\n" /* y */
        "movss %xmm0, 0x10(%esp)\n"
        "movl $0x43700000, 0xc(%esp)\n"
        "movl -0x250(%ebp), %edx\n" /* font */
        "movl %edx, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        "movss -0x258(%ebp), %xmm0\n" /* line 3211 | y */
        "addss -0x24c(%ebp), %xmm0\n" /* lineHeight */
        "movss %xmm0, -0x258(%ebp)\n" /* y */
        "addl $1, %esi\n" /* line 3203 | i */
        "cmpl %esi, -0x254(%ebp)\n" /* i, lineNum */
        "je .Lf1cd924_001cd93d\n"
        ".Lf1cd924_001cda93:\n"
        "movl %edi, 4(%esp)\n" /* line 3205 */
        "leal (, %esi, 4), %ebx\n"
        "movl -0x2c(%ebp, %ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetKeyBindingLocalizedString\n"
        "testl %eax, %eax\n" /* line 3206 */
        "jne .Lf1cd924_001cd9fa\n"
        "movl $str_002a79c4, (%esp)\n" /* line 3207 */
        "calll UI_SafeTranslateString\n"
        "movl $0x100, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_strncpyz\n"
        "jmp .Lf1cd924_001cd9fa\n"
        /* { scope 2 */
        ".Lf1cd924_001cdad7:\n"
        "leal -0x240(%ebp), %ebx\n" /* line 3051 | binding */
        "movl %ebx, 4(%esp)\n"
        "movl $str_002ac0cc, (%esp)\n" /* "+melee" */
        "calll GetKeyBindingLocalizedString\n"
        "testl %eax, %eax\n" /* line 3052 */
        "je .Lf1cd924_001cdb5c\n"
        "movl $str_002ac0cc, %edx\n" /* "+melee" */
        /* } scope */
        ".Lf1cd924_001cdaf6:\n"
        "movl -0x254(%ebp), %eax\n" /* line 3196 | lineNum */
        "movl %edx, -0x2c(%ebp, %eax, 4)\n"
        "movl $str_002b726c, -0x40(%ebp, %eax, 4)\n" /* line 3197 */
        "addl $1, %eax\n" /* line 3198 */
        "movl %eax, -0x254(%ebp)\n" /* lineNum */
        "jmp .Lf1cd924_001cd9df\n"
        ".Lf1cd924_001cdb16:\n"
        "movl $str_002abfd8, -0x2c(%ebp)\n" /* line 3185 | commands */
        "movl $str_002b7230, -0x40(%ebp)\n" /* line 3186 | messages */
        /* { scope 2 */
        "leal -0x240(%ebp), %ebx\n" /* line 3051 | binding */
        "movl %ebx, 4(%esp)\n"
        "movl $str_002ac154, (%esp)\n" /* "toggleads" */
        "calll GetKeyBindingLocalizedString\n"
        "testl %eax, %eax\n" /* line 3052 */
        "je .Lf1cd924_001cdb80\n"
        "movl $str_002ac154, %edx\n" /* "toggleads" */
        /* } scope */
        ".Lf1cd924_001cdb43:\n"
        "movl %edx, -0x28(%ebp)\n" /* line 3189 */
        "movl $str_002b724c, -0x3c(%ebp)\n" /* line 3190 */
        "movl $2, -0x254(%ebp)\n" /* lineNum */
        "jmp .Lf1cd924_001cd9cb\n"
        /* { scope 2 */
        ".Lf1cd924_001cdb5c:\n"
        "movl %ebx, 4(%esp)\n" /* line 3054 */
        "movl $str_002ac0e0, (%esp)\n" /* "+melee_breath" */
        "calll GetKeyBindingLocalizedString\n"
        "movl $str_002ac0cc, %edx\n" /* line 3055 */
        "testl %eax, %eax\n"
        "movl $str_002ac0e0, %eax\n" /* "+melee_breath" */
        "cmovnel %eax, %edx\n"
        "jmp .Lf1cd924_001cdaf6\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1cd924_001cdb80:\n"
        "movl %ebx, 4(%esp)\n" /* line 3054 */
        "movl $str_002abf50, (%esp)\n" /* "+speed" */
        "calll GetKeyBindingLocalizedString\n"
        "movl $str_002ac154, %edx\n" /* line 3055 */
        "testl %eax, %eax\n"
        "movl $str_002abf50, %eax\n" /* "+speed" */
        "cmovnel %eax, %edx\n"
        "jmp .Lf1cd924_001cdb43\n"
    );
}

/* line 2845 */
__attribute__((naked))
unsigned int CG_StartShakeCamera(float p, int duration, vec_t *src, float radius)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2845 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl 0x10(%ebp), %ecx\n" /* src */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 2856 | p */
        "movl %eax, -0x38(%ebp)\n"
        "cvtsi2ssl 0xc(%ebp), %xmm0\n" /* line 2857 | duration */
        "movss %xmm0, -0x34(%ebp)\n"
        "movl imp_cg, %esi\n" /* line 2858 */
        "movl (%esi), %ebx\n" /* i */
        "movl 0x25bb0(%ebx), %edx\n" /* i */
        "movl %edx, -0x3c(%ebp)\n" /* shake */
        "movl (%ecx), %eax\n" /* line 199 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, -0x28(%ebp)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, -0x24(%ebp)\n"
        "movl 0x14(%ebp), %eax\n" /* line 2860 | radius */
        "movl %eax, -0x30(%ebp)\n"
        /* { scope 2 */
        "movl 0x25bb0(%ebx), %eax\n" /* line 2816 */
        "subl %edx, %eax\n" /* line 2817 */
        "js .Lf1cdba2_001cdd7d\n"
        "cvtsi2ssl %eax, %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "jb .Lf1cdba2_001cdcc0\n"
        ".Lf1cdba2_001cdc01:\n"
        "movl (%esi), %edi\n"
        /* } scope */
        ".Lf1cdba2_001cdc03:\n"
        "movl 0x25bb0(%edi), %esi\n" /* line 2867 */
        "cvtsi2ssl %esi, %xmm1\n"
        "movl %edi, %edx\n"
        "xorl %ebx, %ebx\n" /* i */
        "leal 0x2c500(%edi), %ecx\n"
        ".Lf1cdba2_001cdc17:\n"
        "movl 0x2c50c(%edx), %eax\n"
        "cmpl %esi, %eax\n"
        "jg .Lf1cdba2_001cdd3f\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss 0x2c514(%edx), %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "jae .Lf1cdba2_001cdd3f\n"
        "addl $1, %ebx\n" /* line 2865 | i */
        "addl $0x24, %ecx\n"
        "addl $0x24, %edx\n"
        "cmpl $4, %ebx\n" /* i */
        "jne .Lf1cdba2_001cdc17\n"
        "movss -0x20(%ebp), %xmm1\n" /* line 2874 */
        "movl %edi, %eax\n"
        "movl $4, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lf1cdba2_001cdc56:\n"
        "movss 0x2c528(%eax), %xmm0\n" /* line 2880 */
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf1cdba2_001cdc68\n"
        "movl %edx, %ecx\n"
        "movaps %xmm0, %xmm1\n"
        ".Lf1cdba2_001cdc68:\n"
        "addl $1, %edx\n" /* line 2878 */
        "addl $0x24, %eax\n"
        "cmpl $4, %edx\n"
        "jne .Lf1cdba2_001cdc56\n"
        "cmpl $4, %ecx\n" /* line 2887 */
        "je .Lf1cdba2_001cdcb8\n"
        "leal (%ecx, %ecx, 8), %edx\n" /* line 2892 */
        "leal 0x2c500(%edi, %edx, 4), %edx\n"
        "movl -0x3c(%ebp), %eax\n" /* shake */
        "movl %eax, 0xc(%edx)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 0x10(%edx)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, 0x14(%edx)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 0x1c(%edx)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 0x20(%edx)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 0x24(%edx)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 0x28(%edx)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0x2c(%edx)\n"
        /* } scope */
        ".Lf1cdba2_001cdcb8:\n"
        "addl $0x6c, %esp\n" /* line 2893 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1cdba2_001cdcc0:\n"
        "leal 0x28588(%ebx), %eax\n" /* line 2824 */
        "movl %eax, 4(%esp)\n"
        "leal -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "movss %xmm2, -0x58(%ebp)\n"
        "calll Vec3Distance\n"
        "fstps -0x5c(%ebp)\n"
        "movss -0x5c(%ebp), %xmm0\n"
        "divss -0x30(%ebp), %xmm0\n" /* line 2826 */
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "movaps %xmm1, %xmm3\n"
        "subss %xmm0, %xmm3\n"
        "movaps %xmm3, %xmm0\n"
        "movss -0x58(%ebp), %xmm2\n" /* line 2829 */
        "divss -0x34(%ebp), %xmm2\n"
        "subss %xmm2, %xmm1\n"
        "mulss -0x38(%ebp), %xmm1\n"
        "ucomiss lit4_002ed5e8, %xmm1\n" /* line 2831 | 0.0f */
        "jp .Lf1cdba2_001cdd1b\n"
        "jbe .Lf1cdba2_001cdc01\n"
        ".Lf1cdba2_001cdd1b:\n"
        "ucomiss lit4_002ed5e8, %xmm0\n" /* line 2834 | 0.0f */
        "jb .Lf1cdba2_001cdd84\n"
        "mulss %xmm1, %xmm0\n" /* line 2835 */
        ".Lf1cdba2_001cdd28:\n"
        "movss %xmm0, -0x20(%ebp)\n" /* line 2839 */
        "movss %xmm1, -0x1c(%ebp)\n" /* line 2840 */
        "movl imp_cg, %esi\n"
        "movl (%esi), %edi\n"
        "jmp .Lf1cdba2_001cdc03\n"
        /* } scope */
        ".Lf1cdba2_001cdd3f:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 2869 | shake */
        "movl %eax, 0xc(%ecx)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 0x10(%ecx)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, 0x14(%ecx)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 0x18(%ecx)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 0x1c(%ecx)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 0x20(%ecx)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 0x24(%ecx)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 0x28(%ecx)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0x2c(%ecx)\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 2893 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1cdba2_001cdd7d:\n"
        "movl %ebx, %edi\n" /* i */
        "jmp .Lf1cdba2_001cdc03\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1cdba2_001cdd84:\n"
        "divss %xmm1, %xmm0\n" /* line 2837 */
        "jmp .Lf1cdba2_001cdd28\n"
    );
}

/* line 1266 */
static __attribute__((naked))
float CG_DrawWeapReticle(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1266 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        /* { scope 1: drawPos, drawSize, material */
        /* { scope 2 */
        "movl imp_cg, %eax\n" /* line 1138 */
        "movl (%eax), %ebx\n"
        "leal 0x25bc4(%ebx), %esi\n"
        "movl %esi, (%esp)\n"
        "calll BG_GetViewmodelWeaponIndex\n"
        "movl %eax, (%esp)\n" /* line 1139 */
        "calll BG_GetWeaponDef\n"
        "movl %eax, %edx\n"
        "movss 0x25ca0(%ebx), %xmm1\n" /* line 1141 */
        "movl 0x274(%eax), %eax\n" /* line 1148 */
        "cmpb $0, (%eax)\n"
        "jne .Lf1cdd8a_001cdddf\n"
        "movl 0x278(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1cdd8a_001cdddf\n"
        /* } scope */
        ".Lf1cdd8a_001cddcf:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 1280 | 1.0f */
        /* } scope */
        "addl $0x7c, %esp\n" /* line 1300 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: drawPos, drawSize, material */
        /* { scope 2 */
        ".Lf1cdd8a_001cdddf:\n"
        "pxor %xmm2, %xmm2\n" /* line 1152 */
        "ucomiss %xmm2, %xmm1\n"
        "jp .Lf1cdd8a_001cddea\n"
        "je .Lf1cdd8a_001cddcf\n"
        ".Lf1cdd8a_001cddea:\n"
        "movl 0x28494(%ebx), %eax\n" /* line 1156 */
        "testl %eax, %eax\n"
        "je .Lf1cdd8a_001cdfc4\n"
        "movss 0x26c(%edx), %xmm3\n" /* line 1158 */
        ".Lf1cdd8a_001cde00:\n"
        "movss lit4_002ed5d0, %xmm4\n" /* line 1164 | 1.0f */
        "movaps %xmm4, %xmm0\n"
        "subss %xmm3, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x50(%ebp)\n" /* zoomFrac */
        "movaps %xmm1, %xmm0\n" /* line 1165 */
        "ucomiss %xmm2, %xmm1\n"
        "jbe .Lf1cdd8a_001cdfd1\n"
        "divss %xmm3, %xmm0\n" /* line 1166 */
        "movss %xmm0, -0x50(%ebp)\n" /* zoomFrac */
        ".Lf1cdd8a_001cde2d:\n"
        "ucomiss lit4_002ed738, %xmm0\n" /* line 1170 | 0.009999999776482582f */
        "jp .Lf1cdd8a_001cde38\n"
        "jbe .Lf1cdd8a_001cddcf\n"
        ".Lf1cdd8a_001cde38:\n"
        "ucomiss %xmm4, %xmm0\n" /* line 1173 */
        "jbe .Lf1cdd8a_001cde42\n"
        "movss %xmm4, -0x50(%ebp)\n" /* zoomFrac */
        /* } scope */
        ".Lf1cdd8a_001cde42:\n"
        "movl %esi, (%esp)\n" /* line 1286 | weapDef */
        "calll BG_GetViewmodelWeaponIndex\n"
        "movl %eax, %ebx\n" /* weapIndex */
        "movl %eax, (%esp)\n" /* line 1287 */
        "calll BG_GetWeaponDef\n"
        "movl %eax, %esi\n" /* weapDef */
        "movl $0x3f800000, %edi\n" /* line 447 */
        "movl %edi, -0x40(%ebp)\n" /* color */
        "movl %edi, -0x3c(%ebp)\n" /* line 448 */
        "movl %edi, -0x38(%ebp)\n" /* line 449 */
        "movss -0x50(%ebp), %xmm0\n" /* line 450 | zoomFrac */
        "movss %xmm0, -0x34(%ebp)\n"
        "leal -0x20(%ebp), %eax\n" /* line 1291 | crosshairPos */
        "leal -0x1c(%ebp), %edx\n"
        "calll CG_CalcCrosshairPosition\n"
        /* { scope 2 */
        "movl imp_cg_weapons, %eax\n" /* line 1220 */
        "movl (%eax), %edx\n"
        "leal (%ebx, %ebx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "movl 0x180(%edx, %eax, 4), %eax\n"
        "movl %eax, -0x4c(%ebp)\n" /* material */
        "testl %eax, %eax\n" /* line 1221 */
        "je .Lf1cdd8a_001cdfaf\n"
        "movss 0x27c(%esi), %xmm3\n" /* line 1227 */
        "movss %xmm3, -0x30(%ebp)\n" /* drawSize */
        "movss 0x280(%esi), %xmm2\n" /* line 1228 */
        "movss %xmm2, -0x2c(%ebp)\n"
        "ucomiss lit4_002ed8e8, %xmm3\n" /* line 1231 | 320.0f */
        "ja .Lf1cdd8a_001cdecb\n"
        "ucomiss lit4_002ed6e8, %xmm2\n" /* 240.0f */
        "jbe .Lf1cdd8a_001cdfd9\n"
        ".Lf1cdd8a_001cdecb:\n"
        "movss lit4_002ed63c, %xmm0\n" /* line 1233 | -0.5f */
        "movaps %xmm3, %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "addss -0x20(%ebp), %xmm1\n" /* crosshairPos */
        "movss %xmm1, -0x28(%ebp)\n" /* drawPos */
        "mulss %xmm2, %xmm0\n" /* line 1234 */
        "addss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        "movl -0x4c(%ebp), %eax\n" /* line 1235 | material */
        "movl %eax, 0x2c(%esp)\n"
        "leal -0x40(%ebp), %ebx\n" /* color */
        "movl %ebx, 0x28(%esp)\n"
        "movl %edi, 0x24(%esp)\n"
        "movl %edi, 0x20(%esp)\n"
        "xorl %eax, %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl %eax, 0x18(%esp)\n"
        "movl $2, 0x14(%esp)\n"
        "movl $2, 0x10(%esp)\n"
        "movss %xmm2, 0xc(%esp)\n"
        "movss %xmm3, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "movss %xmm1, (%esp)\n"
        "calll CL_DrawStretchPic\n"
        "movl $2, 0x14(%esp)\n" /* line 1237 */
        "movl $2, 0x10(%esp)\n"
        "leal -0x30(%ebp), %edx\n" /* drawSize */
        "leal -0x2c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "leal -0x28(%ebp), %edx\n" /* drawPos */
        "leal -0x24(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x24(%ebp), %xmm1\n" /* line 1238 */
        "movss -0x28(%ebp), %xmm2\n" /* drawPos */
        "movl -0x4c(%ebp), %eax\n" /* material */
        "movl %eax, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n"
        "movaps %xmm1, %xmm0\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss %xmm1, 8(%esp)\n"
        "movaps %xmm2, %xmm0\n"
        "addss -0x30(%ebp), %xmm0\n" /* drawSize */
        "movss %xmm0, 4(%esp)\n"
        "movss %xmm2, (%esp)\n"
        "calll CG_DrawFrameOverlay\n"
        /* } scope */
        ".Lf1cdd8a_001cdfaf:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 1295 | 1.0f */
        "subss -0x50(%ebp), %xmm0\n" /* zoomFrac */
        /* } scope */
        "addl $0x7c, %esp\n" /* line 1300 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: drawPos, drawSize, material */
        /* { scope 2 */
        ".Lf1cdd8a_001cdfc4:\n"
        "movss 0x270(%edx), %xmm3\n" /* line 1164 */
        "jmp .Lf1cdd8a_001cde00\n"
        ".Lf1cdd8a_001cdfd1:\n"
        "movaps %xmm1, %xmm0\n"
        "jmp .Lf1cdd8a_001cde2d\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1cdd8a_001cdfd9:\n"
        "movss -0x20(%ebp), %xmm1\n" /* line 1242 | crosshairPos */
        "subss %xmm3, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n" /* drawPos */
        "movss -0x1c(%ebp), %xmm0\n" /* line 1243 */
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        "movl -0x4c(%ebp), %eax\n" /* line 1244 | material */
        "movl %eax, 0x2c(%esp)\n"
        "leal -0x40(%ebp), %esi\n" /* color */
        "movl %esi, 0x28(%esp)\n"
        "movl %edi, 0x24(%esp)\n"
        "movl %edi, 0x20(%esp)\n"
        "xorl %ebx, %ebx\n"
        "movl %ebx, 0x1c(%esp)\n"
        "movl %ebx, 0x18(%esp)\n"
        "movl $2, 0x14(%esp)\n"
        "movl $2, 0x10(%esp)\n"
        "movss %xmm2, 0xc(%esp)\n"
        "movss %xmm3, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "movss %xmm1, (%esp)\n"
        "calll CL_DrawStretchPic\n"
        "movl -0x20(%ebp), %edx\n" /* line 1246 | crosshairPos */
        "movl %edx, -0x28(%ebp)\n" /* drawPos */
        "movss -0x2c(%ebp), %xmm1\n" /* line 1247 */
        "movss -0x1c(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        "movl -0x4c(%ebp), %eax\n" /* line 1248 | material */
        "movl %eax, 0x2c(%esp)\n"
        "movl %esi, 0x28(%esp)\n"
        "movl %edi, 0x24(%esp)\n"
        "movl %ebx, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n"
        "movl %edi, 0x18(%esp)\n"
        "movl $2, 0x14(%esp)\n"
        "movl $2, 0x10(%esp)\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movl -0x30(%ebp), %eax\n" /* drawSize */
        "movl %eax, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CL_DrawStretchPic\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 1250 | drawSize */
        "movss -0x20(%ebp), %xmm0\n" /* crosshairPos */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n" /* drawPos */
        "movl -0x1c(%ebp), %edx\n" /* line 1251 */
        "movl %edx, -0x24(%ebp)\n"
        "movl -0x4c(%ebp), %eax\n" /* line 1252 | material */
        "movl %eax, 0x2c(%esp)\n"
        "movl %esi, 0x28(%esp)\n"
        "movl %ebx, 0x24(%esp)\n"
        "movl %edi, 0x20(%esp)\n"
        "movl %edi, 0x1c(%esp)\n"
        "movl %ebx, 0x18(%esp)\n"
        "movl $2, 0x14(%esp)\n"
        "movl $2, 0x10(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movss %xmm1, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movss %xmm0, (%esp)\n"
        "calll CL_DrawStretchPic\n"
        "movl -0x20(%ebp), %ecx\n" /* line 1254 | crosshairPos */
        "movl %ecx, -0x28(%ebp)\n" /* drawPos */
        "movl -0x1c(%ebp), %edx\n" /* line 1255 */
        "movl %edx, -0x24(%ebp)\n"
        "movl -0x4c(%ebp), %eax\n" /* line 1256 | material */
        "movl %eax, 0x2c(%esp)\n"
        "movl %esi, 0x28(%esp)\n"
        "movl %ebx, 0x24(%esp)\n"
        "movl %ebx, 0x20(%esp)\n"
        "movl %edi, 0x1c(%esp)\n"
        "movl %edi, 0x18(%esp)\n"
        "movl $2, 0x14(%esp)\n"
        "movl $2, 0x10(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x30(%ebp), %eax\n" /* drawSize */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll CL_DrawStretchPic\n"
        "movss -0x20(%ebp), %xmm0\n" /* line 1258 | crosshairPos */
        "subss -0x30(%ebp), %xmm0\n" /* drawSize */
        "movss %xmm0, -0x28(%ebp)\n" /* drawPos */
        "movss -0x1c(%ebp), %xmm0\n" /* line 1259 */
        "subss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        "movl $2, 0x14(%esp)\n" /* line 1260 */
        "movl $2, 0x10(%esp)\n"
        "leal -0x30(%ebp), %edx\n" /* drawSize */
        "leal -0x2c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "leal -0x28(%ebp), %edx\n" /* drawPos */
        "leal -0x24(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x24(%ebp), %xmm1\n" /* line 1261 */
        "movss -0x28(%ebp), %xmm2\n" /* drawPos */
        "movl -0x4c(%ebp), %eax\n" /* material */
        "movl %eax, 0x14(%esp)\n"
        "movl %esi, 0x10(%esp)\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss %xmm1, 8(%esp)\n"
        "movss -0x30(%ebp), %xmm0\n" /* drawSize */
        "addss %xmm0, %xmm0\n"
        "addss %xmm2, %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movss %xmm2, (%esp)\n"
        "calll CG_DrawFrameOverlay\n"
        "jmp .Lf1cdd8a_001cdfaf\n"
    );
}

/* line 1664 */
__attribute__((naked))
unsigned int CG_DrawCrosshair(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1664 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xfc, %esp\n"
        /* { scope 1: reticleColor */
        "movl imp_cg, %eax\n" /* line 1680 */
        "movl (%eax), %ebx\n" /* material */
        "movl 0x25bc0(%ebx), %esi\n" /* material, drawHudMenus */
        "testl %esi, %esi\n" /* drawHudMenus */
        "je .Lf1ce1ee_001ce216\n"
        /* } scope */
        ".Lf1ce1ee_001ce20b:\n"
        "addl $0xfc, %esp\n" /* line 1750 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: reticleColor */
        ".Lf1ce1ee_001ce216:\n"
        "calll CG_AreHudMenusHidden\n" /* line 1683 */
        "testb %al, %al\n"
        "sete %al\n"
        "movl %eax, %esi\n" /* drawHudMenus */
        "movss 0x25ca0(%ebx), %xmm0\n" /* line 1685 | material */
        "movss %xmm0, -0x74(%ebp)\n" /* posLerp */
        "testl $0x300, 0x25c64(%ebx)\n" /* line 1690 | material */
        "je .Lf1ce1ee_001ce25b\n"
        "testb %al, %al\n" /* line 1692 */
        "je .Lf1ce1ee_001ce20b\n"
        "cmpl $0x3ff, 0x26158(%ebx)\n" /* line 1694 | material */
        "je .Lf1ce1ee_001ce20b\n"
        "calll CG_DrawTurretCrossHair\n" /* line 1697 */
        /* } scope */
        "addl $0xfc, %esp\n" /* line 1750 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: reticleColor */
        ".Lf1ce1ee_001ce25b:\n"
        "leal 0x25bc4(%ebx), %eax\n" /* line 1703 | material */
        "movl %eax, (%esp)\n"
        "calll BG_GetViewmodelWeaponIndex\n"
        "movl %eax, %edi\n" /* weapIndex */
        "testl %eax, %eax\n" /* line 1704 */
        "je .Lf1ce1ee_001ce20b\n"
        "movl %eax, (%esp)\n" /* line 1707 */
        "calll BG_GetWeaponDef\n"
        "movl %eax, -0x78(%ebp)\n" /* weapDef */
        "calll CG_DrawWeapReticle\n" /* line 1709 */
        "movl %esi, %eax\n" /* line 1711 | drawHudMenus */
        "testb %al, %al\n"
        "je .Lf1ce1ee_001ce20b\n"
        "movl 0x25bd0(%ebx), %eax\n" /* line 1311 */
        "testl $0x100000, %eax\n"
        "je .Lf1ce1ee_001ce99e\n"
        "movl $0x3e800000, %eax\n" /* line 191 */
        "movl %eax, -0x38(%ebp)\n" /* color */
        "movss lit4_002ed5d0, %xmm5\n" /* line 192 | 1.0f */
        "movss %xmm5, -0x34(%ebp)\n"
        "movl %eax, -0x30(%ebp)\n" /* line 193 */
        ".Lf1ce1ee_001ce2ae:\n"
        "movl imp_cg_crosshairAlpha, %eax\n" /* line 1319 */
        "movl (%eax), %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "ucomiss lit4_002ed738, %xmm0\n" /* line 1717 | 0.009999999776482582f */
        "jp .Lf1ce1ee_001ce2ce\n"
        "jb .Lf1ce1ee_001ce20b\n"
        ".Lf1ce1ee_001ce2ce:\n"
        "movss -0x74(%ebp), %xmm0\n" /* line 1721 | posLerp */
        "ucomiss %xmm5, %xmm0\n"
        "jne .Lf1ce1ee_001ce2eb\n"
        "jp .Lf1ce1ee_001ce2eb\n"
        "movl imp_cg_drawGun, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1ce1ee_001ce20b\n"
        ".Lf1ce1ee_001ce2eb:\n"
        "movl imp_cg_paused, %eax\n" /* line 1400 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lf1ce1ee_001ce20b\n"
        "movl imp_cg_drawCrosshair, %eax\n" /* line 1403 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1ce1ee_001ce20b\n"
        "movl imp_cg, %eax\n" /* line 1407 */
        "movl (%eax), %eax\n"
        "movl 0x25c9c(%eax), %edx\n"
        "leal -0xa(%edx), %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf1ce1ee_001ce20b\n"
        "cmpl $5, %edx\n" /* line 1411 */
        "je .Lf1ce1ee_001ce20b\n"
        "leal -1(%edx), %eax\n" /* line 1415 */
        "cmpl $1, %eax\n"
        "jbe .Lf1ce1ee_001ce20b\n"
        "leal -0x20(%ebp), %edx\n" /* line 1727 | centerY */
        "leal -0x1c(%ebp), %eax\n" /* centerX */
        "calll CG_CalcCrosshairPosition\n"
        "pxor %xmm2, %xmm2\n" /* line 1729 */
        "movss -0x74(%ebp), %xmm1\n" /* posLerp */
        "ucomiss %xmm2, %xmm1\n"
        "jne .Lf1ce1ee_001cea47\n"
        "jp .Lf1ce1ee_001cea47\n"
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        "movss %xmm3, -0x70(%ebp)\n" /* transScale */
        "movaps %xmm3, %xmm5\n"
        "movaps %xmm2, %xmm4\n"
        ".Lf1ce1ee_001ce372:\n"
        "movss -0x74(%ebp), %xmm0\n" /* line 1737 | posLerp */
        "ucomiss %xmm5, %xmm0\n"
        "jne .Lf1ce1ee_001ce38f\n"
        "jp .Lf1ce1ee_001ce38f\n"
        "movl imp_cg_drawGun, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1ce1ee_001ce20b\n"
        ".Lf1ce1ee_001ce38f:\n"
        "movl imp_cg_crosshairDynamic, %eax\n" /* line 1741 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1ce1ee_001ce3a8\n"
        "movl $0, -0x1c(%ebp)\n" /* line 1743 | centerX */
        "movss %xmm4, -0x20(%ebp)\n" /* line 1744 | centerY */
        ".Lf1ce1ee_001ce3a8:\n"
        "movss -0x20(%ebp), %xmm1\n" /* line 1747 | centerY */
        "movss %xmm1, -0x84(%ebp)\n"
        "movss -0x1c(%ebp), %xmm2\n" /* centerX */
        "movss %xmm2, -0x88(%ebp)\n"
        /* { scope 2: f, maxSpread, material */
        "leal (%edi, %edi, 2), %eax\n" /* line 1513 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%edi, %eax, 4), %eax\n"
        "leal (, %eax, 4), %esi\n"
        "movl imp_cg_weapons, %edx\n"
        "movl (%edx), %eax\n"
        "movl 0x178(%esi, %eax), %ebx\n" /* material */
        "testl %ebx, %ebx\n" /* line 1514 | material */
        "je .Lf1ce1ee_001ce4ad\n"
        "movl -0x78(%ebp), %eax\n" /* line 1520 | weapDef */
        "cvtsi2ssl 0x120(%eax), %xmm1\n"
        "cmpl $1, 0x78(%eax)\n" /* line 1522 */
        "je .Lf1ce1ee_001ce9eb\n"
        ".Lf1ce1ee_001ce3fe:\n"
        "mulss -0x70(%ebp), %xmm1\n" /* line 1524 | transScale */
        "movss %xmm1, -0x98(%ebp)\n" /* line 1525 */
        "calll CL_IsRenderingSplitScreen\n"
        "testb %al, %al\n"
        "movss -0x98(%ebp), %xmm1\n"
        "je .Lf1ce1ee_001ce420\n"
        "addss %xmm1, %xmm1\n" /* line 1526 */
        ".Lf1ce1ee_001ce420:\n"
        "movaps %xmm1, %xmm0\n" /* line 1529 */
        "mulss lit4_002ed63c, %xmm0\n" /* -0.5f */
        "movl %ebx, 0x2c(%esp)\n" /* line 1533 | material */
        "leal -0x38(%ebp), %eax\n" /* color */
        "movl %eax, 0x28(%esp)\n"
        "movl $0x3f800000, %eax\n"
        "movl %eax, 0x24(%esp)\n"
        "movl %eax, 0x20(%esp)\n"
        "xorl %eax, %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl %eax, 0x18(%esp)\n"
        "movl $2, 0x14(%esp)\n"
        "movl $2, 0x10(%esp)\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movss %xmm1, 8(%esp)\n"
        "movss -0x84(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%esp)\n"
        "addss -0x88(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll CL_DrawStretchPic\n"
        "movss -0x20(%ebp), %xmm2\n" /* centerY */
        "movss %xmm2, -0x84(%ebp)\n"
        "movss -0x1c(%ebp), %xmm3\n" /* centerX */
        "movss %xmm3, -0x88(%ebp)\n"
        "movl imp_cg_weapons, %edx\n"
        /* } scope */
        /* { scope 2: f, maxSpread, material */
        ".Lf1ce1ee_001ce4ad:\n"
        "movl (%edx), %eax\n" /* line 1618 */
        "movl 0x17c(%esi, %eax), %esi\n"
        "movl %esi, -0x64(%ebp)\n" /* material */
        "testl %esi, %esi\n" /* line 1619 */
        "je .Lf1ce1ee_001ce20b\n"
        "calll CG_DrawWeapReticle\n" /* line 1625 */
        "movl -0x38(%ebp), %eax\n" /* line 199 | color */
        "movl %eax, -0x48(%ebp)\n" /* reticleColor */
        "movl -0x34(%ebp), %eax\n" /* line 200 */
        "movl %eax, -0x44(%ebp)\n"
        "movl -0x30(%ebp), %eax\n" /* line 201 */
        "movl %eax, -0x40(%ebp)\n"
        "movl imp_cg_crosshairAlpha, %eax\n" /* line 1566 */
        "movl (%eax), %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "movl imp_cg, %eax\n"
        "movl (%eax), %eax\n"
        "movss 0x26198(%eax), %xmm1\n"
        "divss lit4_002eda30, %xmm1\n" /* -255.0f */
        "addss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "movl imp_cg_crosshairAlphaMin, %eax\n" /* line 1567 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "movaps %xmm0, %xmm2\n" /* line 1568 */
        "cmpnltss %xmm1, %xmm0\n"
        "andps %xmm0, %xmm2\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm2, %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "movl -0x78(%ebp), %eax\n" /* line 1629 | weapDef */
        "cvtsi2ssl 0x124(%eax), %xmm0\n"
        "mulss -0x70(%ebp), %xmm0\n" /* transScale */
        "movss %xmm0, -0x60(%ebp)\n"
        "calll CL_IsRenderingSplitScreen\n" /* line 1633 */
        "testb %al, %al\n"
        "jne .Lf1ce1ee_001cebb6\n"
        "movss -0x60(%ebp), %xmm1\n"
        "movss %xmm1, -0x5c(%ebp)\n"
        "movl -0x5c(%ebp), %esi\n"
        /* { scope 3 */
        ".Lf1ce1ee_001ce55d:\n"
        "leal -0x28(%ebp), %eax\n" /* line 1546 | maxSpread */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* f */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl imp_cg, %eax\n"
        "movl (%eax), %ebx\n" /* material */
        "leal 0x25bc4(%ebx), %eax\n" /* material */
        "movl %eax, (%esp)\n"
        "calll BG_GetSpreadForWeapon\n"
        "movss -0x24(%ebp), %xmm2\n" /* line 1547 | f */
        "movss -0x28(%ebp), %xmm0\n" /* maxSpread */
        "subss %xmm2, %xmm0\n"
        "movss 0x26198(%ebx), %xmm1\n" /* material */
        "divss lit4_002ed5d4, %xmm1\n" /* 255.0f */
        "mulss %xmm1, %xmm0\n"
        "addss %xmm2, %xmm0\n"
        "mulss -0x70(%ebp), %xmm0\n" /* transScale */
        "movss %xmm0, -0x24(%ebp)\n" /* f */
        "cvtss2sd %xmm0, %xmm0\n" /* line 1549 */
        "mulsd lit8_00307c48, %xmm0\n" /* 0.017453292519943295 */
        "movsd %xmm0, (%esp)\n"
        "calll tan\n"
        "fstpl -0xd0(%ebp)\n"
        "movsd -0xd0(%ebp), %xmm1\n"
        "mulsd lit8_00307d90, %xmm1\n" /* 240.0 */
        "cvtss2sd 0x28584(%ebx), %xmm0\n" /* material */
        "mulsd lit8_00307c48, %xmm0\n" /* 0.017453292519943295 */
        "mulsd lit8_00307ce0, %xmm0\n" /* 0.5 */
        "movsd %xmm0, (%esp)\n"
        "movsd %xmm1, -0x98(%ebp)\n"
        "calll tan\n"
        "fstpl -0x80(%ebp)\n"
        "movsd -0x98(%ebp), %xmm1\n"
        "divsd -0x80(%ebp), %xmm1\n"
        "cvtsd2ss %xmm1, %xmm0\n"
        "movl -0x78(%ebp), %eax\n" /* line 1550 | weapDef */
        "cvtsi2ssl 0x128(%eax), %xmm1\n"
        "maxss %xmm0, %xmm1\n"
        "movss %xmm1, -0x58(%ebp)\n"
        "movss -0x60(%ebp), %xmm2\n" /* line 1553 */
        "mulss 0x2bc(%eax), %xmm2\n"
        "subss %xmm2, %xmm1\n"
        "movss %xmm1, -0x58(%ebp)\n"
        /* } scope */
        /* { scope 3 */
        "movss -0x5c(%ebp), %xmm3\n" /* line 1587 */
        "movss %xmm3, (%esp)\n"
        "calll GetRealWidthFromVirtualWidth\n"
        "fstps -0xd4(%ebp)\n"
        "movss -0xd4(%ebp), %xmm1\n"
        "movl %esi, (%esp)\n" /* line 1588 */
        "movss %xmm1, -0x98(%ebp)\n"
        "calll GetRealHeightFromVirtualHeight\n"
        "fstps -0xd4(%ebp)\n"
        "movss -0xd4(%ebp), %xmm2\n"
        "movl imp_cgs, %eax\n" /* line 1590 */
        "movl (%eax), %eax\n"
        "cvtsi2ssl 0x5e90(%eax), %xmm3\n"
        "cvtsi2ssl 0x5e8c(%eax), %xmm0\n"
        "movss -0x98(%ebp), %xmm1\n" /* line 1596 */
        "divss %xmm0, %xmm1\n"
        "mulss lit4_002ed610, %xmm1\n" /* 0.125f */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "movss %xmm2, -0xa8(%ebp)\n"
        "movss %xmm3, -0xb8(%ebp)\n"
        "calll GetVirtualWidthFromRealWidth\n"
        "fstps -0x50(%ebp)\n"
        "movss -0xa8(%ebp), %xmm2\n" /* line 1597 */
        "movss -0xb8(%ebp), %xmm3\n"
        "divss %xmm3, %xmm2\n"
        "mulss lit4_002ed610, %xmm2\n" /* 0.125f */
        "mulss %xmm2, %xmm3\n"
        "movss %xmm3, (%esp)\n"
        "calll GetVirtualHeightFromRealHeight\n"
        "fstps -0x54(%ebp)\n"
        /* } scope */
        "movss -0x5c(%ebp), %xmm0\n" /* line 1643 */
        "movss %xmm0, 8(%esp)\n"
        "movss -0x88(%ebp), %xmm1\n"
        "movss %xmm1, 4(%esp)\n"
        "movl $4, (%esp)\n"
        "calll CG_AlignHudElemX\n"
        "fstps -0x4c(%ebp)\n"
        "movl %esi, 8(%esp)\n" /* line 1644 */
        "movss -0x84(%ebp), %xmm2\n"
        "movss %xmm2, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll CG_AlignHudElemY\n"
        "fstps -0xd4(%ebp)\n"
        "movss -0xd4(%ebp), %xmm0\n"
        "movl -0x64(%ebp), %eax\n" /* line 1645 | material */
        "movl %eax, 0x20(%esp)\n"
        "leal -0x48(%ebp), %ebx\n" /* reticleColor, material */
        "movl %ebx, 0x1c(%esp)\n" /* material */
        "movl $0, 0x18(%esp)\n"
        "movl $2, 0x14(%esp)\n"
        "movl $2, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n"
        "movss -0x5c(%ebp), %xmm1\n"
        "movss %xmm1, 8(%esp)\n"
        "subss -0x58(%ebp), %xmm0\n"
        "subss -0x54(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movss -0x4c(%ebp), %xmm2\n"
        "movss %xmm2, (%esp)\n"
        "calll CG_DrawRotatedPic\n"
        "movss -0x5c(%ebp), %xmm3\n" /* line 1648 */
        "movss %xmm3, 8(%esp)\n"
        "movss -0x88(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll CG_AlignHudElemX\n"
        "fstps -0x6c(%ebp)\n"
        "movl %esi, 8(%esp)\n" /* line 1649 */
        "movss -0x84(%ebp), %xmm1\n"
        "movss %xmm1, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll CG_AlignHudElemY\n"
        "movl -0x64(%ebp), %eax\n" /* line 1650 | material */
        "movl %eax, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n" /* material */
        "movl $0x42b40000, 0x18(%esp)\n"
        "movl $2, 0x14(%esp)\n"
        "movl $2, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n"
        "movss -0x5c(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "fstps 4(%esp)\n"
        "movss -0x58(%ebp), %xmm1\n"
        "addss -0x6c(%ebp), %xmm1\n"
        "movss %xmm1, (%esp)\n"
        "calll CG_DrawRotatedPic\n"
        "movss -0x5c(%ebp), %xmm2\n" /* line 1653 */
        "movss %xmm2, 8(%esp)\n"
        "movss -0x88(%ebp), %xmm3\n"
        "movss %xmm3, 4(%esp)\n"
        "movl $4, (%esp)\n"
        "calll CG_AlignHudElemX\n"
        "fstps -0x68(%ebp)\n"
        "movl %esi, 8(%esp)\n" /* line 1654 */
        "movss -0x84(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll CG_AlignHudElemY\n"
        "fstps -0xd4(%ebp)\n"
        "movss -0xd4(%ebp), %xmm0\n"
        "movl -0x64(%ebp), %eax\n" /* line 1655 | material */
        "movl %eax, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n" /* material */
        "movl $0x43340000, 0x18(%esp)\n"
        "movl $2, 0x14(%esp)\n"
        "movl $2, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n"
        "movss -0x5c(%ebp), %xmm1\n"
        "movss %xmm1, 8(%esp)\n"
        "addss -0x58(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movss -0x68(%ebp), %xmm2\n"
        "subss -0x50(%ebp), %xmm2\n"
        "movss %xmm2, (%esp)\n"
        "calll CG_DrawRotatedPic\n"
        "movss -0x5c(%ebp), %xmm3\n" /* line 1658 */
        "movss %xmm3, 8(%esp)\n"
        "movss -0x88(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl $8, (%esp)\n"
        "calll CG_AlignHudElemX\n"
        "fstps -0xd4(%ebp)\n"
        "movss -0xd4(%ebp), %xmm1\n"
        "movl %esi, 8(%esp)\n" /* line 1659 */
        "movss -0x84(%ebp), %xmm2\n"
        "movss %xmm2, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "movss %xmm1, -0x98(%ebp)\n"
        "calll CG_AlignHudElemY\n"
        "fstps -0xd4(%ebp)\n"
        "movss -0xd4(%ebp), %xmm0\n"
        "movl -0x64(%ebp), %eax\n" /* line 1660 | material */
        "movl %eax, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n" /* material */
        "movl $0x43870000, 0x18(%esp)\n"
        "movl $2, 0x14(%esp)\n"
        "movl $2, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n"
        "movss -0x5c(%ebp), %xmm2\n"
        "movss %xmm2, 8(%esp)\n"
        "subss -0x54(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movss -0x98(%ebp), %xmm1\n"
        "subss -0x58(%ebp), %xmm1\n"
        "subss -0x50(%ebp), %xmm1\n"
        "movss %xmm1, (%esp)\n"
        "calll CG_DrawRotatedPic\n"
        "jmp .Lf1ce1ee_001ce20b\n"
        /* } scope */
        ".Lf1ce1ee_001ce99e:\n"
        "testl $0x200000, %eax\n" /* line 1313 */
        "je .Lf1ce1ee_001ce9cf\n"
        "movl imp_cg_crosshairEnemyColor, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1ce1ee_001ce9cf\n"
        "movss lit4_002ed5d0, %xmm5\n" /* line 191 | 1.0f */
        "movss %xmm5, -0x38(%ebp)\n" /* color */
        "movl $0x3e800000, %eax\n" /* line 192 */
        "movl %eax, -0x34(%ebp)\n"
        "movl %eax, -0x30(%ebp)\n" /* line 193 */
        "jmp .Lf1ce1ee_001ce2ae\n"
        ".Lf1ce1ee_001ce9cf:\n"
        "movss lit4_002ed5d0, %xmm5\n" /* line 191 | 1.0f */
        "movss %xmm5, -0x38(%ebp)\n" /* color */
        "movss %xmm5, -0x34(%ebp)\n" /* line 192 */
        "movss %xmm5, -0x30(%ebp)\n" /* line 193 */
        "jmp .Lf1ce1ee_001ce2ae\n"
        /* { scope 2: f, maxSpread, material */
        ".Lf1ce1ee_001ce9eb:\n"
        "movl imp_cg, %eax\n" /* line 1522 */
        "movl (%eax), %eax\n"
        "movl 0x25c00(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf1ce1ee_001ce3fe\n"
        "movl -0x78(%ebp), %edx\n" /* weapDef */
        "movl 0x33c(%edx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1ce1ee_001ce3fe\n"
        "movl $0x10624dd3, %edx\n" /* line 1523 */
        "movl %ecx, %eax\n"
        "imull %edx\n"
        "sarl $6, %edx\n"
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "leal (%edx, %edx, 4), %edx\n"
        "leal (%edx, %edx, 4), %edx\n"
        "leal (%edx, %edx, 4), %edx\n"
        "shll $3, %edx\n"
        "subl %edx, %ecx\n"
        "cvtsi2ssl %ecx, %xmm0\n"
        "divss lit4_002ed798, %xmm0\n" /* 100.0f */
        "addss %xmm0, %xmm1\n"
        "jmp .Lf1ce1ee_001ce3fe\n"
        /* } scope */
        /* { scope 2: f, maxSpread, material */
        ".Lf1ce1ee_001cea47:\n"
        "movl imp_cg, %eax\n" /* line 1472 */
        "movl (%eax), %eax\n"
        "movl 0x28494(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf1ce1ee_001cebd9\n"
        "movl -0x78(%ebp), %edx\n" /* line 1474 | weapDef */
        "movss 0x470(%edx), %xmm1\n"
        ".Lf1ce1ee_001cea67:\n"
        "movss lit4_002ed5d0, %xmm5\n" /* line 1483 | 1.0f */
        "movaps %xmm5, %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss -0x74(%ebp), %xmm3\n" /* posLerp */
        "subss %xmm0, %xmm3\n"
        "movaps %xmm3, %xmm0\n"
        "ucomiss %xmm2, %xmm3\n" /* line 1484 */
        "jbe .Lf1ce1ee_001cebcc\n"
        "divss %xmm1, %xmm0\n" /* line 1487 */
        "ucomiss %xmm2, %xmm0\n" /* line 1491 */
        "jbe .Lf1ce1ee_001cebcc\n"
        "movaps %xmm0, %xmm1\n" /* line 1496 */
        "mulss lit4_002ed63c, %xmm1\n" /* -0.5f */
        "addss %xmm5, %xmm1\n"
        "movss %xmm1, -0x70(%ebp)\n" /* transScale */
        "movss lit4_002ed840, %xmm4\n" /* line 1497 | 480.0f */
        "divss 0x28584(%eax), %xmm4\n"
        "mulss %xmm0, %xmm4\n"
        "movl -0x78(%ebp), %eax\n" /* weapDef */
        "mulss 0x46c(%eax), %xmm4\n"
        /* } scope */
        ".Lf1ce1ee_001ceacb:\n"
        "movss -0x20(%ebp), %xmm3\n" /* line 1732 | centerY */
        "movss -0x1c(%ebp), %xmm2\n" /* centerX */
        /* { scope 2: f, maxSpread, material */
        /* { scope 3 */
        "movl imp_cg_drawGun, %eax\n" /* line 1435 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1ce1ee_001ce372\n"
        "movss -0x70(%ebp), %xmm0\n" /* line 1440 | transScale */
        "ucomiss %xmm5, %xmm0\n"
        "jae .Lf1ce1ee_001ce372\n"
        "movl imp_cg_weapons, %eax\n" /* line 1443 */
        "movl (%eax), %edx\n"
        "leal (%edi, %edi, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%edi, %eax, 4), %eax\n"
        "movl 0x178(%edx, %eax, 4), %eax\n"
        "testl %eax, %eax\n" /* line 1444 */
        "je .Lf1ce1ee_001ce372\n"
        "movl -0x78(%ebp), %edx\n" /* line 1451 | weapDef */
        "cvtsi2ssl 0x120(%edx), %xmm1\n"
        "movss lit4_002ed600, %xmm0\n" /* 1.5f */
        "subss -0x70(%ebp), %xmm0\n" /* transScale */
        "mulss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n" /* line 1453 */
        "mulss lit4_002ed63c, %xmm0\n" /* -0.5f */
        "movl %eax, 0x2c(%esp)\n" /* line 1457 */
        "leal -0x38(%ebp), %eax\n" /* color */
        "movl %eax, 0x28(%esp)\n"
        "movl $0x3f800000, 0x24(%esp)\n"
        "movl $0x3f800000, 0x20(%esp)\n"
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $2, 0x14(%esp)\n"
        "movl $2, 0x10(%esp)\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movss %xmm1, 8(%esp)\n"
        "addss %xmm0, %xmm3\n"
        "movss %xmm3, 4(%esp)\n"
        "addss %xmm0, %xmm2\n"
        "movss %xmm2, (%esp)\n"
        "movss %xmm4, -0xc8(%ebp)\n"
        "calll CL_DrawStretchPic\n"
        "movss lit4_002ed5d0, %xmm5\n" /* 1.0f */
        "movss -0xc8(%ebp), %xmm4\n"
        "jmp .Lf1ce1ee_001ce372\n"
        /* } scope */
        /* } scope */
        /* { scope 2: f, maxSpread, material */
        ".Lf1ce1ee_001cebb6:\n"
        "movss -0x60(%ebp), %xmm2\n" /* line 86 */
        "addss %xmm2, %xmm2\n"
        "movss %xmm2, -0x5c(%ebp)\n"
        "movl -0x5c(%ebp), %esi\n"
        "jmp .Lf1ce1ee_001ce55d\n"
        /* } scope */
        /* { scope 2: f, maxSpread, material */
        ".Lf1ce1ee_001cebcc:\n"
        "movss %xmm5, -0x70(%ebp)\n" /* line 1497 | transScale */
        "movaps %xmm2, %xmm4\n"
        "jmp .Lf1ce1ee_001ceacb\n"
        ".Lf1ce1ee_001cebd9:\n"
        "movl -0x78(%ebp), %edx\n" /* line 1483 | weapDef */
        "movss 0x474(%edx), %xmm1\n"
        "jmp .Lf1ce1ee_001cea67\n"
    );
}

/* line 3278 */
__attribute__((naked))
unsigned int CG_Draw2D(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3278 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x71c, %esp\n"
        /* { scope 1 */
        "movl imp_cg, %ecx\n" /* line 3285 */
        "movl (%ecx), %edx\n"
        "movl 0xc(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1cebea_001cf376\n"
        "movl imp_cg_draw2D, %eax\n" /* line 3288 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1cebea_001cf376\n"
        "movss 0x2bda4(%edx), %xmm0\n" /* line 2442 */
        "pxor %xmm4, %xmm4\n"
        "ucomiss %xmm4, %xmm0\n"
        "jp .Lf1cebea_001cec31\n"
        "je .Lf1cebea_001cece0\n"
        ".Lf1cebea_001cec31:\n"
        "movl 0x2bda0(%edx), %eax\n" /* line 2445 */
        "subl 0x25bb0(%edx), %eax\n"
        "testl %eax, %eax\n" /* line 2446 */
        "jle .Lf1cebea_001cfd2e\n"
        "cvtsi2ssl %eax, %xmm2\n" /* line 2463 */
        "mulss %xmm0, %xmm2\n"
        "movss lit4_002ed5d0, %xmm3\n" /* line 2465 | 1.0f */
        "subss %xmm2, %xmm3\n"
        "xorl %ebx, %ebx\n"
        "leal -0x620(%ebp), %eax\n"
        "movl %eax, -0x6a4(%ebp)\n"
        "movl %edx, %eax\n"
        ".Lf1cebea_001cec69:\n"
        "movaps %xmm2, %xmm0\n" /* line 2468 */
        "mulss 0x2bda8(%eax, %ebx, 4), %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 0x2bdb8(%eax, %ebx, 4), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0x620(%ebp, %ebx, 4)\n"
        "addl $1, %ebx\n" /* line 2467 */
        "cmpl $4, %ebx\n"
        "jne .Lf1cebea_001cec69\n"
        "ucomiss -0x614(%ebp), %xmm4\n" /* line 2470 */
        "jp .Lf1cebea_001ceca1\n"
        "je .Lf1cebea_001cece0\n"
        ".Lf1cebea_001ceca1:\n"
        "movl -0x6a4(%ebp), %edx\n" /* line 2471 */
        "movl %edx, 0x10(%esp)\n"
        ".Lf1cebea_001cecab:\n"
        "movl imp_cls, %eax\n"
        "cvtsi2ssl 0x2a0a68(%eax), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "cvtsi2ssl 0x2a0a64(%eax), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll UI_FillRectPhysical\n"
        ".Lf1cebea_001cece0:\n"
        "calll CG_AreHudMenusHidden\n" /* line 3293 */
        "testb %al, %al\n"
        "sete %cl\n"
        "movl %ecx, %edi\n" /* drawHudMenus */
        "calll CG_AreHudElemsHidden\n" /* line 3294 */
        "testb %al, %al\n"
        "sete -0x689(%ebp)\n" /* drawHudElems */
        "movl imp_cg, %eax\n" /* line 3296 */
        "movl (%eax), %ebx\n"
        "movl 0x24(%ebx), %eax\n"
        "movl 0x10(%eax), %eax\n"
        "cmpl $5, %eax\n"
        "je .Lf1cebea_001cf867\n"
        "cmpl $4, %eax\n" /* line 3302 */
        "je .Lf1cebea_001cf72c\n"
        "cmpl $5, %eax\n" /* line 3320 */
        "jle .Lf1cebea_001cf4b3\n"
        ".Lf1cebea_001ced22:\n"
        "movl %edi, %eax\n" /* line 3323 | drawHudMenus */
        "testb %al, %al\n"
        "jne .Lf1cebea_001cf381\n"
        "calll CG_CheckTimedMenus\n" /* line 3331 */
        "cmpb $0, -0x689(%ebp)\n" /* line 3333 | drawHudElems */
        "jne .Lf1cebea_001cf4a2\n"
        ".Lf1cebea_001ced3e:\n"
        "movl %edi, %edx\n" /* line 3336 | drawHudMenus */
        "testb %dl, %dl\n"
        "jne .Lf1cebea_001cf490\n"
        ".Lf1cebea_001ced48:\n"
        "movl $1, (%esp)\n" /* line 3339 */
        "calll CG_Draw2dHudElems\n"
        ".Lf1cebea_001ced54:\n"
        "calll CG_DrawScoreboard\n" /* line 3342 */
        "movl %eax, -0x690(%ebp)\n" /* drawScoreboard */
        "movl %edi, %ecx\n" /* line 3344 | drawHudMenus */
        "testb %cl, %cl\n"
        "je .Lf1cebea_001cf376\n"
        "movl imp_cg, %ecx\n" /* line 1886 */
        "movl (%ecx), %edx\n"
        "movl 0x24(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1cebea_001d0556\n"
        "movl 0x2bf0c(%edx), %eax\n" /* line 1889 */
        "movl 0x25bb0(%edx), %ebx\n"
        "cmpl %ebx, %eax\n"
        "jle .Lf1cebea_001cee3c\n"
        "subl %ebx, %eax\n" /* line 54 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x2bf10(%edx), %xmm0\n"
        "divss lit4_002ed7a4, %xmm0\n" /* 500.0f */
        "andps colorWhiteFaded+32, %xmm0\n"
        "ucomiss lit4_002ed6d4, %xmm0\n" /* line 1894 | 5.0f */
        "jbe .Lf1cebea_001cfa1d\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        ".Lf1cebea_001cedc2:\n"
        "movl $0x3e4ccccd, -0x620(%ebp)\n" /* line 191 */
        "xorl %eax, %eax\n" /* line 192 */
        "movl %eax, -0x61c(%ebp)\n"
        "movl %eax, -0x618(%ebp)\n" /* line 193 */
        "mulss lit4_002ed6ac, %xmm0\n" /* line 1898 | 0.699999988079071f */
        "movss %xmm0, -0x614(%ebp)\n"
        "leal -0x620(%ebp), %ebx\n" /* line 1901 */
        "movl %ebx, 0x10(%esp)\n"
        "movl imp_cls, %eax\n"
        "cvtsi2ssl 0x2a0a68(%eax), %xmm0\n"
        "movss lit4_002ed6b4, %xmm1\n" /* 10.0f */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "cvtsi2ssl 0x2a0a64(%eax), %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movl $0xc1200000, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll UI_FillRectPhysical\n"
        "movl imp_cg, %ecx\n"
        ".Lf1cebea_001cee3c:\n"
        "movl (%ecx), %ebx\n"
        ".Lf1cebea_001cee3e:\n"
        "movl 0x24(%ebx), %eax\n" /* line 1919 */
        "testl %eax, %eax\n"
        "je .Lf1cebea_001cf09d\n"
        "leal 0x25bc4(%ebx), %eax\n" /* line 1138 */
        "movl %eax, (%esp)\n"
        "calll BG_GetViewmodelWeaponIndex\n"
        "movl %eax, (%esp)\n" /* line 1139 */
        "calll BG_GetWeaponDef\n"
        "movl %eax, %edx\n"
        "movss 0x25ca0(%ebx), %xmm1\n" /* line 1141 */
        "movl 0x274(%eax), %eax\n" /* line 1148 */
        "cmpb $0, (%eax)\n"
        "jne .Lf1cebea_001cf6c0\n"
        "movl 0x278(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1cebea_001cf6c0\n"
        ".Lf1cebea_001cee86:\n"
        "movl $0x43a00000, -0x20(%ebp)\n" /* line 1933 */
        "movl $0x43700000, -0x1c(%ebp)\n" /* line 1934 */
        ".Lf1cebea_001cee94:\n"
        "movl imp_cg_hudDamageIconWidth, %eax\n" /* line 1937 */
        "movl (%eax), %eax\n"
        "movss lit4_002ed5d8, %xmm2\n" /* 0.5f */
        "mulss 8(%eax), %xmm2\n"
        "movl imp_cg_hudDamageIconOffset, %ecx\n" /* line 1938 */
        "movl (%ecx), %edx\n"
        "movl imp_cg_hudDamageIconHeight, %ebx\n"
        "movl (%ebx), %eax\n"
        "movss 8(%edx), %xmm0\n"
        "addss 8(%eax), %xmm0\n"
        "movss %xmm2, -0x120(%ebp)\n" /* line 30 */
        "movss %xmm0, -0x11c(%ebp)\n" /* line 31 */
        "movl (%ecx), %eax\n" /* line 1939 */
        "movl (%ebx), %edx\n"
        "movss 8(%eax), %xmm0\n"
        "addss 8(%edx), %xmm0\n"
        "movaps %xmm2, %xmm1\n"
        "xorps sse_float_sign_mask, %xmm1\n"
        "movss %xmm1, -0x118(%ebp)\n" /* line 30 */
        "movss %xmm0, -0x114(%ebp)\n" /* line 31 */
        "movl (%ecx), %eax\n" /* line 1940 */
        "movl 8(%eax), %eax\n"
        "movss %xmm1, -0x110(%ebp)\n" /* line 30 */
        "movl %eax, -0x10c(%ebp)\n" /* line 31 */
        "movl (%ecx), %eax\n" /* line 1941 */
        "movl 8(%eax), %eax\n"
        "movss %xmm2, -0x108(%ebp)\n" /* line 30 */
        "movl %eax, -0x104(%ebp)\n" /* line 31 */
        "movl $0, 4(%esp)\n" /* line 1943 */
        "leal -0x20(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $0, 4(%esp)\n" /* line 1944 */
        "leal -0x1c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll CalcScreenY\n"
        "movl imp_colorWhite, %edx\n" /* line 456 */
        "movl (%edx), %eax\n"
        "movl %eax, -0x620(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 457 */
        "movl %eax, -0x61c(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 458 */
        "movl %eax, -0x618(%ebp)\n"
        "movl 0xc(%edx), %eax\n" /* line 459 */
        "movl %eax, -0x614(%ebp)\n"
        "movl $0, -0x688(%ebp)\n"
        "movl imp_cg, %ecx\n"
        "movl %ecx, -0x6a8(%ebp)\n"
        "movl $0, -0x6ac(%ebp)\n"
        "jmp .Lf1cebea_001cefac\n"
        ".Lf1cebea_001cef91:\n"
        "addl $1, -0x688(%ebp)\n" /* line 1946 */
        "addl $0xc, -0x6ac(%ebp)\n"
        "cmpl $8, -0x688(%ebp)\n"
        "je .Lf1cebea_001cf09d\n"
        ".Lf1cebea_001cefac:\n"
        "movl (%ecx), %eax\n" /* line 1948 */
        "movl -0x6ac(%ebp), %esi\n"
        "addl %eax, %esi\n"
        "movl 0x2be78(%esi), %edi\n"
        "movl 0x25bb0(%eax), %ebx\n" /* line 1949 */
        "subl 0x2be74(%esi), %ebx\n"
        "testl %ebx, %ebx\n" /* line 1950 */
        "jle .Lf1cebea_001cef91\n"
        "cmpl %ebx, %edi\n"
        "jle .Lf1cebea_001cef91\n"
        "addl $0x28594, %eax\n" /* line 1953 */
        "movl %eax, (%esp)\n"
        "calll vectoyaw\n"
        "fstps -0x6ec(%ebp)\n"
        "movss -0x6ec(%ebp), %xmm2\n"
        "subss 0x2be7c(%esi), %xmm2\n" /* line 1954 */
        "cvtsi2ssl %ebx, %xmm0\n" /* line 1955 */
        "mulss lit4_002ed628, %xmm0\n" /* -2.0f */
        "cvtsi2ssl %edi, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "addss lit4_002ed62c, %xmm0\n" /* 2.0f */
        "movaps %xmm0, %xmm1\n" /* line 45 */
        "subss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "movss lit4_002ed5d0, %xmm4\n" /* 1.0f */
        "movaps %xmm0, %xmm3\n"
        "cmpltss lit4_002ed5e8, %xmm1\n" /* 0.0f */
        "andps %xmm1, %xmm3\n"
        "andnps %xmm4, %xmm1\n"
        "orps %xmm3, %xmm1\n"
        "movss %xmm1, -0x614(%ebp)\n" /* line 1955 */
        "movl imp_cgs, %eax\n" /* line 1956 */
        "movl (%eax), %eax\n"
        "movl 0xbc74(%eax), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "leal -0x620(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movss %xmm2, 0xc(%esp)\n"
        "leal -0x120(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_DrawRotatedQuadPic\n"
        "movl -0x6a8(%ebp), %ecx\n"
        "addl $1, -0x688(%ebp)\n" /* line 1946 */
        "addl $0xc, -0x6ac(%ebp)\n"
        "cmpl $8, -0x688(%ebp)\n"
        "jne .Lf1cebea_001cefac\n"
        ".Lf1cebea_001cf09d:\n"
        "movl (%ecx), %ebx\n" /* line 2090 */
        "movl 0x24(%ebx), %edi\n"
        "testl %edi, %edi\n"
        "je .Lf1cebea_001cf0bc\n"
        "cmpl $4, 0x25bc8(%ebx)\n" /* line 2093 */
        "je .Lf1cebea_001cf0bc\n"
        "testb $0x40, 0x25bd2(%ebx)\n"
        "je .Lf1cebea_001cfd7e\n"
        ".Lf1cebea_001cf0bc:\n"
        "movl -0x690(%ebp), %ebx\n" /* line 3351 | drawScoreboard */
        "testl %ebx, %ebx\n"
        "je .Lf1cebea_001cf4bd\n"
        ".Lf1cebea_001cf0ca:\n"
        "movl imp_cgs, %eax\n" /* line 2974 */
        "movl (%eax), %eax\n"
        "movl 0x6088(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf1cebea_001cf4cc\n"
        ".Lf1cebea_001cf0df:\n"
        "movl imp_cg_drawLagometer, %eax\n" /* line 874 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1cebea_001cf275\n"
        "movl imp_cgs, %esi\n"
        "movl (%esi), %eax\n"
        "movl 0x5ea0(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf1cebea_001cf275\n"
        "movl 0xba40(%eax), %eax\n" /* line 886 */
        "movl %eax, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $3, 0x14(%esp)\n"
        "movl $3, 0x10(%esp)\n"
        "movl $0x42400000, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl $0xc30c0000, 4(%esp)\n"
        "movl $0xc25c0000, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        "xorl %ebx, %ebx\n"
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm4, %xmm2\n"
        "jmp .Lf1cebea_001cf1e6\n"
        ".Lf1cebea_001cf157:\n"
        "movss lit4_002eda3c, %xmm0\n" /* line 907 | -124.0f */
        "subss %xmm1, %xmm0\n"
        ".Lf1cebea_001cf163:\n"
        "movl (%esi), %eax\n" /* line 911 */
        "movl 0xba1c(%eax), %eax\n"
        "movl %eax, 0x2c(%esp)\n"
        "movl imp_colorYellow, %eax\n"
        "movl %eax, 0x28(%esp)\n"
        "movl $0, 0x24(%esp)\n"
        "movl $0, 0x20(%esp)\n"
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $3, 0x14(%esp)\n"
        "movl $3, 0x10(%esp)\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        ".Lf1cebea_001cf1bc:\n"
        "movss lit4_002eda40, %xmm0\n" /* line 920 | -7.0f */
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll CL_DrawStretchPic\n"
        "pxor %xmm4, %xmm4\n"
        ".Lf1cebea_001cf1d6:\n"
        "addl $1, %ebx\n" /* line 900 */
        "cvtsi2ssl %ebx, %xmm2\n"
        "cmpl $0x30, %ebx\n"
        "je .Lf1cebea_001cf896\n"
        ".Lf1cebea_001cf1e6:\n"
        "movl %ebx, %eax\n" /* line 903 */
        "notl %eax\n"
        "addl lagometer+512, %eax\n"
        "andl $0x7f, %eax\n"
        "cvtsi2ssl lagometer(, %eax, 4), %xmm1\n"
        "mulss lit4_002eda38, %xmm1\n" /* line 904 | 0.0533333346247673f */
        "ucomiss %xmm4, %xmm1\n" /* line 905 */
        "jbe .Lf1cebea_001cf760\n"
        "ucomiss lit4_002ed6a8, %xmm1\n" /* line 907 | 16.0f */
        "jbe .Lf1cebea_001cf157\n"
        "movss lit4_002ed6a8, %xmm1\n" /* 16.0f */
        "movss lit4_002eda34, %xmm0\n" /* -140.0f */
        "jmp .Lf1cebea_001cf163\n"
        ".Lf1cebea_001cf22f:\n"
        "movl imp_cg_nopredict, %eax\n" /* line 956 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1cebea_001cf249\n"
        "movl imp_cg_synchronousClients, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1cebea_001cf275\n"
        ".Lf1cebea_001cf249:\n"
        "movl $9, 0x10(%esp)\n" /* line 957 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl $str_002b72e8, 8(%esp)\n" /* "snc" */
        "movl $0xc30c0000, 4(%esp)\n"
        "movl $0xc25c0000, (%esp)\n"
        "calll CG_DrawBigDevString\n"
        ".Lf1cebea_001cf275:\n"
        "calll CG_DrawDisconnect\n" /* line 959 */
        "calll Sys_Milliseconds\n" /* line 2694 */
        "movl %eax, %esi\n"
        "leal -0x20(%ebp), %eax\n" /* line 2695 */
        "movl %eax, 4(%esp)\n"
        "leal -0x1c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll StatMon_GetStatsArray\n"
        "movl -0x20(%ebp), %eax\n" /* line 2700 */
        "testl %eax, %eax\n"
        "jg .Lf1cebea_001cf3aa\n"
        ".Lf1cebea_001cf29e:\n"
        "movl imp_cg_drawSoundOverlay, %eax\n" /* line 2773 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1cebea_001cf6b6\n"
        "movl imp_cg_drawScriptUsage, %eax\n" /* line 2779 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1cebea_001cf88c\n"
        "movl imp_cg_drawMaterial, %eax\n" /* line 2785 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1cebea_001d065a\n"
        ".Lf1cebea_001cf2d2:\n"
        "movl $0, (%esp)\n" /* line 525 */
        "calll CL_TrackStatistics\n"
        "movl imp_cg_drawSnapshot, %eax\n" /* line 529 */
        "movl (%eax), %eax\n"
        "pxor %xmm0, %xmm0\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1cebea_001cf7f7\n"
        ".Lf1cebea_001cf2f3:\n"
        "movl imp_cg_drawFPS, %eax\n" /* line 539 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1cebea_001cf7ed\n"
        ".Lf1cebea_001cf305:\n"
        "movl -0x690(%ebp), %edi\n" /* line 3374 | drawScoreboard, drawHudMenus */
        "testl %edi, %edi\n" /* drawHudMenus */
        "jne .Lf1cebea_001cf376\n"
        "movl imp_cg, %eax\n" /* line 1062 */
        "movl (%eax), %ebx\n"
        "movl 0x2b990(%ebx), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf1cebea_001cfb27\n"
        ".Lf1cebea_001cf324:\n"
        "movl imp_cg_drawGameMessages, %eax\n" /* line 3378 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1cebea_001cfa4b\n"
        ".Lf1cebea_001cf335:\n"
        "calll CG_DrawBoldGameMessages\n" /* line 3380 */
        "movl imp_cg_minicon, %eax\n" /* line 2640 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1cebea_001cfa2a\n"
        ".Lf1cebea_001cf34b:\n"
        "movl imp_cg_subtitles, %eax\n" /* line 2656 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1cebea_001cfae4\n"
        ".Lf1cebea_001cf35c:\n"
        "movl imp_cg_hudSayPosition, %eax\n" /* line 2672 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "cvttss2si 4(%eax), %eax\n"
        "addl $0x18, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Con_DrawSay\n"
        /* } scope */
        ".Lf1cebea_001cf376:\n"
        "addl $0x71c, %esp\n" /* line 3388 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1cebea_001cf381:\n"
        "movl 0x24(%ebx), %eax\n" /* line 3325 */
        "cmpl $5, 0x10(%eax)\n"
        "jle .Lf1cebea_001d04d8\n"
        "calll CG_DrawChatMessages\n" /* line 3328 */
        ".Lf1cebea_001cf393:\n"
        "calll CG_CheckTimedMenus\n" /* line 3331 */
        "cmpb $0, -0x689(%ebp)\n" /* line 3333 | drawHudElems */
        "je .Lf1cebea_001ced3e\n"
        "jmp .Lf1cebea_001cf4a2\n"
        ".Lf1cebea_001cf3aa:\n"
        "movss lit4_002ed62c, %xmm1\n" /* line 2700 | 2.0f */
        "movss lit4_002ed734, %xmm0\n" /* 200.0f */
        "movss %xmm0, -0x640(%ebp)\n"
        "xorl %ebx, %ebx\n"
        "movss lit4_002ed830, %xmm2\n" /* 32.0f */
        "movss %xmm2, -0x6ec(%ebp)\n"
        "movl -0x6ec(%ebp), %edi\n"
        "jmp .Lf1cebea_001cf420\n"
        ".Lf1cebea_001cf3dc:\n"
        "addss lit4_002eda50, %xmm1\n" /* line 2705 | 34.0f */
        "movaps %xmm1, %xmm0\n" /* line 2706 */
        "addss %xmm2, %xmm0\n"
        "ucomiss lit4_002eda54, %xmm0\n" /* 68.0f */
        "jbe .Lf1cebea_001cf414\n"
        "movss lit4_002eda50, %xmm0\n" /* line 2709 | 34.0f */
        "addss -0x640(%ebp), %xmm0\n"
        "movss %xmm0, -0x640(%ebp)\n"
        "movss lit4_002ed62c, %xmm1\n" /* 2.0f */
        ".Lf1cebea_001cf414:\n"
        "addl $1, %ebx\n" /* line 2700 */
        "cmpl -0x20(%ebp), %ebx\n"
        "jge .Lf1cebea_001cf29e\n"
        ".Lf1cebea_001cf420:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2702 */
        "leal (%eax, %ebx, 8), %eax\n"
        "cmpl (%eax), %esi\n"
        "jg .Lf1cebea_001cf3dc\n"
        "movl 4(%eax), %eax\n" /* line 2703 */
        "movl %eax, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $1, 0x10(%esp)\n"
        "movss %xmm2, 0xc(%esp)\n"
        "movss %xmm2, 8(%esp)\n"
        "movss -0x640(%ebp), %xmm4\n"
        "movss %xmm4, 4(%esp)\n"
        "movss %xmm1, (%esp)\n"
        "movss %xmm1, -0x6c8(%ebp)\n"
        "calll UI_DrawHandlePic\n"
        "movl %edi, -0x6ec(%ebp)\n"
        "movss -0x6ec(%ebp), %xmm2\n"
        "movss -0x6c8(%ebp), %xmm1\n"
        "jmp .Lf1cebea_001cf3dc\n"
        ".Lf1cebea_001cf490:\n"
        "movl imp_cgDC, %eax\n" /* line 3337 */
        "movl %eax, (%esp)\n"
        "calll Menu_PaintAll\n"
        "jmp .Lf1cebea_001ced48\n"
        ".Lf1cebea_001cf4a2:\n"
        "movl $0, (%esp)\n" /* line 3334 */
        "calll CG_Draw2dHudElems\n"
        "jmp .Lf1cebea_001ced3e\n"
        ".Lf1cebea_001cf4b3:\n"
        "calll CG_DrawCrosshair\n" /* line 3321 */
        "jmp .Lf1cebea_001ced22\n"
        ".Lf1cebea_001cf4bd:\n"
        "calll CG_DrawSpectatorMessage\n" /* line 3353 */
        "calll CG_DrawFollow\n" /* line 3354 */
        "jmp .Lf1cebea_001cf0ca\n"
        ".Lf1cebea_001cf4cc:\n"
        "movl $0x3e555555, 4(%esp)\n" /* line 2977 */
        "movl $0, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %eax, -0x644(%ebp)\n"
        "leal -0x120(%ebp), %ebx\n" /* line 2981 */
        "movl %ebx, 4(%esp)\n"
        "movl $str_002ac060, (%esp)\n" /* "vote yes" */
        "calll GetKeyBindingLocalizedString\n"
        "testl %eax, %eax\n" /* line 2982 */
        "je .Lf1cebea_001d04e7\n"
        "movl $0x100, 8(%esp)\n" /* line 2983 */
        "movl %ebx, 4(%esp)\n"
        "leal -0x220(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        ".Lf1cebea_001cf51e:\n"
        "movl %ebx, 4(%esp)\n" /* line 2987 */
        "movl $str_002ac06c, (%esp)\n" /* "vote no" */
        "calll GetKeyBindingLocalizedString\n"
        "testl %eax, %eax\n" /* line 2988 */
        "je .Lf1cebea_001d0631\n"
        "movl $0x100, 8(%esp)\n" /* line 2989 */
        "movl %ebx, 4(%esp)\n"
        "leal -0x620(%ebp), %ecx\n"
        "movl %ecx, -0x6a4(%ebp)\n"
        "movl %ecx, (%esp)\n"
        "calll I_strncpyz\n"
        ".Lf1cebea_001cf556:\n"
        "movl imp_cgs, %eax\n" /* line 2993 */
        "movl (%eax), %esi\n"
        "movl imp_cg, %eax\n"
        "movl (%eax), %ecx\n"
        "movl 0x6088(%esi), %ebx\n"
        "subl 0x25bb0(%ecx), %ebx\n"
        "movl $0x10624dd3, %edx\n"
        "movl %ebx, %eax\n"
        "imull %edx\n"
        "sarl $6, %edx\n"
        "movl %ebx, %eax\n"
        "sarl $0x1f, %eax\n"
        "movl %edx, %ebx\n" /* line 2994 */
        "subl %eax, %ebx\n"
        "movl $0, %eax\n"
        "cmovsl %eax, %ebx\n"
        "movl 0x24(%ecx), %eax\n" /* line 2997 */
        "testb $0x10, 0xae(%eax)\n"
        "je .Lf1cebea_001d055d\n"
        "movl $str_002b7290, (%esp)\n" /* line 2999 */
        "calll UI_SafeTranslateString\n"
        "leal 0x6094(%esi), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b729c, (%esp)\n" /* "%s(%i):%s" */
        "calll va\n"
        "movl $3, 0x24(%esp)\n" /* line 3000 */
        "movl imp_colorYellow, %edx\n"
        "movl %edx, 0x20(%esp)\n"
        "movl $0x3e555555, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x43480000, 0x10(%esp)\n"
        "movl $0x41000000, 0xc(%esp)\n"
        "movl -0x644(%ebp), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        "movl 0x6090(%esi), %edi\n" /* line 3003 */
        "movl $str_002b72a8, (%esp)\n" /* "CGAME_NO" */
        "calll UI_SafeTranslateString\n"
        "movl %eax, %ebx\n"
        "movl 0x608c(%esi), %esi\n"
        "movl $str_002b72b4, (%esp)\n" /* "CGAME_YES" */
        "calll UI_SafeTranslateString\n"
        "movl %edi, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b72c0, (%esp)\n" /* "%s:%i, %s:%i" */
        ".Lf1cebea_001cf658:\n"
        "calll va\n" /* line 3012 */
        "movl $3, 0x24(%esp)\n" /* line 3013 */
        "movl imp_colorYellow, %ebx\n"
        "movl %ebx, 0x20(%esp)\n"
        "movl $0x3e555555, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x43520000, 0x10(%esp)\n"
        "movl $0x41000000, 0xc(%esp)\n"
        "movl -0x644(%ebp), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        "jmp .Lf1cebea_001cf0df\n"
        ".Lf1cebea_001cf6b6:\n"
        "calll CG_DrawSoundOverlay\n" /* line 2775 */
        "jmp .Lf1cebea_001cf2d2\n"
        ".Lf1cebea_001cf6c0:\n"
        "pxor %xmm2, %xmm2\n" /* line 1152 */
        "ucomiss %xmm2, %xmm1\n"
        "jp .Lf1cebea_001cf6cf\n"
        "je .Lf1cebea_001cee86\n"
        ".Lf1cebea_001cf6cf:\n"
        "movl 0x28494(%ebx), %eax\n" /* line 1156 */
        "testl %eax, %eax\n"
        "je .Lf1cebea_001d050a\n"
        "movss 0x26c(%edx), %xmm3\n" /* line 1158 */
        ".Lf1cebea_001cf6e5:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 1164 | 1.0f */
        "subss %xmm3, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "ucomiss %xmm2, %xmm1\n" /* line 1165 */
        "jbe .Lf1cebea_001cf701\n"
        "divss %xmm3, %xmm0\n" /* line 1166 */
        ".Lf1cebea_001cf701:\n"
        "ucomiss lit4_002ed738, %xmm0\n" /* line 1170 | 0.009999999776482582f */
        "jp .Lf1cebea_001cf710\n"
        "jbe .Lf1cebea_001cee86\n"
        ".Lf1cebea_001cf710:\n"
        "movl imp_cg_hudDamageIconInScope, %eax\n" /* line 1924 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1cebea_001d071a\n"
        "movl imp_cg, %ecx\n"
        "jmp .Lf1cebea_001cf09d\n"
        ".Lf1cebea_001cf72c:\n"
        "movl %edi, %ebx\n" /* line 3304 | drawHudMenus */
        "testb %bl, %bl\n"
        "jne .Lf1cebea_001d0664\n"
        ".Lf1cebea_001cf736:\n"
        "cmpb $0, -0x689(%ebp)\n" /* line 3311 | drawHudElems */
        "je .Lf1cebea_001ced54\n"
        "movl $0, (%esp)\n" /* line 3313 */
        "calll CG_Draw2dHudElems\n"
        "movl $1, (%esp)\n" /* line 3314 */
        "calll CG_Draw2dHudElems\n"
        "jmp .Lf1cebea_001ced54\n"
        ".Lf1cebea_001cf760:\n"
        "pxor %xmm0, %xmm0\n" /* line 913 */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf1cebea_001cf1d6\n"
        "xorps sse_float_sign_mask, %xmm1\n" /* line 915 */
        "movss lit4_002ed6a8, %xmm0\n" /* line 916 | 16.0f */
        "movaps %xmm0, %xmm3\n"
        "cmpltss %xmm1, %xmm0\n"
        "andps %xmm0, %xmm3\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm3, %xmm0\n"
        "movl (%esi), %eax\n" /* line 920 */
        "movl 0xba1c(%eax), %eax\n"
        "movl %eax, 0x2c(%esp)\n"
        "movl imp_colorBlue, %eax\n"
        "movl %eax, 0x28(%esp)\n"
        "movl $0, 0x24(%esp)\n"
        "movl $0, 0x20(%esp)\n"
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $3, 0x14(%esp)\n"
        "movl $3, 0x10(%esp)\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0xc2f80000, 4(%esp)\n"
        "jmp .Lf1cebea_001cf1bc\n"
        ".Lf1cebea_001cf7ed:\n"
        "calll CG_DrawFPS\n" /* line 540 */
        "jmp .Lf1cebea_001cf305\n"
        ".Lf1cebea_001cf7f7:\n"
        "movl imp_cg, %eax\n" /* line 255 */
        "movl (%eax), %edx\n"
        "movl imp_cgs, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x5e98(%eax), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x18(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x24(%edx), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b7218, (%esp)\n" /* "time:%i snap:%i cmd:%i" */
        "calll va\n"
        "movl $6, 0x10(%esp)\n" /* line 256 */
        "movl imp_colorWhite, %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x441b0000, (%esp)\n"
        "calll CG_DrawBigDevStringColor\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "pxor %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "jmp .Lf1cebea_001cf2f3\n"
        ".Lf1cebea_001cf867:\n"
        "calll CL_CloseAllMenus\n" /* line 3021 */
        "movl $1, 0x2b534(%ebx)\n" /* line 3022 */
        "movl 0x25bb0(%ebx), %eax\n" /* line 3025 */
        "movl %eax, 0x2b538(%ebx)\n"
        "calll CG_DrawScoreboard\n" /* line 3036 */
        "jmp .Lf1cebea_001cf376\n"
        ".Lf1cebea_001cf88c:\n"
        "calll CG_DrawScriptUsage\n" /* line 2781 */
        "jmp .Lf1cebea_001cf2d2\n"
        ".Lf1cebea_001cf896:\n"
        "xorb %bl, %bl\n" /* line 900 */
        "movaps %xmm4, %xmm2\n"
        "jmp .Lf1cebea_001cf94a\n"
        ".Lf1cebea_001cf8a0:\n"
        "movl imp_colorGreen, %edx\n" /* line 934 */
        "mulss lit4_002eda44, %xmm0\n" /* line 942 | 0.02666666731238365f */
        "ucomiss lit4_002ed8b8, %xmm0\n" /* line 943 | 24.0f */
        "ja .Lf1cebea_001cf98e\n"
        ".Lf1cebea_001cf8bb:\n"
        "movss lit4_002eda4c, %xmm1\n" /* -92.0f */
        "subss %xmm0, %xmm1\n"
        ".Lf1cebea_001cf8c7:\n"
        "movl imp_cgs, %eax\n" /* line 947 */
        "movl (%eax), %eax\n"
        "movl 0xba1c(%eax), %eax\n"
        "movl %eax, 0x2c(%esp)\n"
        "movl %edx, 0x28(%esp)\n"
        "movl $0, 0x24(%esp)\n"
        "movl $0, 0x20(%esp)\n"
        "movl $0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $3, 0x14(%esp)\n"
        "movl $3, 0x10(%esp)\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movss %xmm1, 4(%esp)\n"
        "movss lit4_002eda40, %xmm0\n" /* -7.0f */
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll CL_DrawStretchPic\n"
        ".Lf1cebea_001cf936:\n"
        "addl $1, %ebx\n" /* line 928 */
        "cvtsi2ssl %ebx, %xmm2\n"
        "cmpl $0x30, %ebx\n"
        "je .Lf1cebea_001cf22f\n"
        "pxor %xmm4, %xmm4\n"
        ".Lf1cebea_001cf94a:\n"
        "movl %ebx, %eax\n" /* line 930 */
        "notl %eax\n"
        "addl lagometer+1540, %eax\n"
        "andl $0x7f, %eax\n"
        "cvtsi2ssl lagometer+1028(, %eax, 4), %xmm0\n" /* line 931 */
        "ucomiss %xmm4, %xmm0\n" /* line 932 */
        "jbe .Lf1cebea_001cf9a3\n"
        "testb $1, lagometer+516(, %eax, 4)\n" /* line 934 */
        "je .Lf1cebea_001cf8a0\n"
        "movl imp_colorYellow, %edx\n"
        "mulss lit4_002eda44, %xmm0\n" /* line 942 | 0.02666666731238365f */
        "ucomiss lit4_002ed8b8, %xmm0\n" /* line 943 | 24.0f */
        "jbe .Lf1cebea_001cf8bb\n"
        ".Lf1cebea_001cf98e:\n"
        "movss lit4_002ed8b8, %xmm0\n" /* 24.0f */
        "movss lit4_002eda48, %xmm1\n" /* -116.0f */
        "jmp .Lf1cebea_001cf8c7\n"
        ".Lf1cebea_001cf9a3:\n"
        "ucomiss %xmm0, %xmm4\n" /* line 949 */
        "jbe .Lf1cebea_001cf936\n"
        "movl imp_cgs, %eax\n" /* line 952 */
        "movl (%eax), %eax\n"
        "movl 0xba1c(%eax), %eax\n"
        "movl %eax, 0x2c(%esp)\n"
        "movl imp_colorRed, %eax\n"
        "movl %eax, 0x28(%esp)\n"
        "movss %xmm4, 0x24(%esp)\n"
        "movss %xmm4, 0x20(%esp)\n"
        "movss %xmm4, 0x1c(%esp)\n"
        "movss %xmm4, 0x18(%esp)\n"
        "movl $3, 0x14(%esp)\n"
        "movl $3, 0x10(%esp)\n"
        "movl $0x41c00000, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0xc2e80000, 4(%esp)\n"
        "movss lit4_002eda40, %xmm0\n" /* -7.0f */
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll CL_DrawStretchPic\n"
        "jmp .Lf1cebea_001cf936\n"
        ".Lf1cebea_001cfa1d:\n"
        "divss lit4_002ed6d4, %xmm0\n" /* line 1894 | 5.0f */
        "jmp .Lf1cebea_001cedc2\n"
        ".Lf1cebea_001cfa2a:\n"
        "movl $0x3f800000, 8(%esp)\n" /* line 2643 */
        "movl $4, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Con_DrawMiniConsole\n"
        "jmp .Lf1cebea_001cf34b\n"
        ".Lf1cebea_001cfa4b:\n"
        "movl imp_cgs, %eax\n" /* line 2590 */
        "movl (%eax), %edx\n"
        "movl imp_cg_hudCompassSize, %eax\n" /* line 428 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "subss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "mulss 0xc20c(%edx), %xmm1\n"
        "movss 0xc210(%edx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "addss lit4_002ed79c, %xmm0\n" /* 12.0f */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x6a0(%ebp)\n"
        "cvttss2si -0x6a0(%ebp), %ebx\n"
        "calll CG_ScoreboardDisplayed\n" /* line 2593 */
        "testl %eax, %eax\n"
        "je .Lf1cebea_001d0517\n"
        "movl $0x64, 8(%esp)\n" /* line 2595 */
        "movl $0x64, 4(%esp)\n"
        "movl imp_cg, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x2b538(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_FadeColor\n"
        "testl %eax, %eax\n" /* line 2596 */
        "je .Lf1cebea_001cf335\n"
        "movl 0xc(%eax), %eax\n" /* line 2599 */
        "jmp .Lf1cebea_001d051c\n"
        ".Lf1cebea_001cfae4:\n"
        "movl $2, 0x10(%esp)\n" /* line 2662 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl imp_cg_subtitleCharHeight, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl imp_cg_subtitlePosY, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl imp_cg_subtitlePosX, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Con_DrawSubtitles\n"
        "jmp .Lf1cebea_001cf35c\n"
        ".Lf1cebea_001cfb27:\n"
        "movl $0x64, 8(%esp)\n" /* line 1065 */
        "movl imp_cg_centertime, %eax\n"
        "movl (%eax), %eax\n"
        "movss lit4_002ed5c8, %xmm0\n" /* 1000.0f */
        "mulss 8(%eax), %xmm0\n"
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CG_FadeColor\n"
        "movl %eax, %edi\n"
        "testl %eax, %eax\n" /* line 1066 */
        "je .Lf1cebea_001d053d\n"
        "leal 0x2b998(%ebx), %esi\n" /* line 1073 */
        "cvtsi2ssl 0x2b994(%ebx), %xmm2\n" /* line 1074 */
        "mulss lit4_002ed878, %xmm2\n" /* 0.03125f */
        "movss %xmm2, -0x634(%ebp)\n"
        "calll CL_IsRenderingSplitScreen\n" /* line 1075 */
        "testb %al, %al\n"
        "je .Lf1cebea_001d074e\n"
        "movss -0x634(%ebp), %xmm3\n" /* line 1076 */
        "mulss lit4_002ed7f8, %xmm3\n" /* 1.25f */
        "movss %xmm3, -0x634(%ebp)\n"
        "movaps %xmm3, %xmm4\n"
        ".Lf1cebea_001cfba3:\n"
        "movss %xmm4, 4(%esp)\n" /* line 1078 */
        "movl $0, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movss -0x634(%ebp), %xmm0\n" /* line 1079 */
        "movss %xmm0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll UI_TextHeight\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movl imp_cg_centerPrintY, %eax\n" /* line 1080 */
        "movl (%eax), %eax\n"
        "cvtsi2ssl 0x2bd98(%ebx), %xmm2\n"
        "movaps %xmm1, %xmm0\n"
        "mulss lit4_002ed92c, %xmm0\n" /* -1.2000000476837158f */
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0x638(%ebp)\n"
        "addss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x638(%ebp)\n"
        "mulss lit4_002eda58, %xmm1\n" /* line 1099 | 1.2000000476837158f */
        "movss %xmm1, -0x63c(%ebp)\n"
        "leal -0x620(%ebp), %eax\n"
        "movl %eax, -0x6a4(%ebp)\n"
        ".Lf1cebea_001cfc1e:\n"
        "xorl %edx, %edx\n"
        "jmp .Lf1cebea_001cfc37\n"
        ".Lf1cebea_001cfc22:\n"
        "cmpb $0xa, %al\n" /* line 1088 */
        "je .Lf1cebea_001cfc3f\n"
        "movl -0x6a4(%ebp), %ecx\n" /* line 1090 */
        "movb %al, (%edx, %ecx)\n"
        "addl $1, %edx\n" /* line 1086 */
        "cmpl $0x4b, %edx\n"
        "je .Lf1cebea_001cfc3f\n"
        ".Lf1cebea_001cfc37:\n"
        "movzbl (%esi, %edx), %eax\n" /* line 1088 */
        "testb %al, %al\n"
        "jne .Lf1cebea_001cfc22\n"
        ".Lf1cebea_001cfc3f:\n"
        "movb $0, -0x620(%ebp, %edx)\n" /* line 1092 */
        "movss -0x634(%ebp), %xmm0\n" /* line 1094 */
        "movss %xmm0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %eax, %ebx\n"
        "movss -0x634(%ebp), %xmm1\n" /* line 1095 */
        "movss %xmm1, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl -0x6a4(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_TextWidth\n"
        "movl $3, 0x24(%esp)\n" /* line 1097 */
        "movl %edi, 0x20(%esp)\n"
        "movss -0x634(%ebp), %xmm0\n"
        "movss %xmm0, 0x1c(%esp)\n"
        "movl $3, 0x18(%esp)\n"
        "movl $7, 0x14(%esp)\n"
        "movss -0x638(%ebp), %xmm1\n"
        "movss %xmm1, 0x10(%esp)\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss lit4_002ed63c, %xmm0\n" /* -0.5f */
        "movss %xmm0, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl -0x6a4(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        "movss -0x638(%ebp), %xmm0\n" /* line 1099 */
        "addss -0x63c(%ebp), %xmm0\n"
        "movss %xmm0, -0x638(%ebp)\n"
        "movzbl (%esi), %eax\n" /* line 1101 */
        "testb %al, %al\n"
        "je .Lf1cebea_001cf324\n"
        "jmp .Lf1cebea_001cfd22\n"
        ".Lf1cebea_001cfd14:\n"
        "addl $1, %esi\n" /* line 1102 */
        "movzbl (%esi), %eax\n" /* line 1101 */
        "testb %al, %al\n"
        "je .Lf1cebea_001cf324\n"
        ".Lf1cebea_001cfd22:\n"
        "cmpb $0xa, %al\n"
        "jne .Lf1cebea_001cfd14\n"
        "addl $1, %esi\n" /* line 1105 */
        "jmp .Lf1cebea_001cfc1e\n"
        ".Lf1cebea_001cfd2e:\n"
        "movl 0x2bdb8(%edx), %eax\n" /* line 2448 */
        "movl %eax, 0x2bda8(%edx)\n"
        "movl 0x2bdbc(%edx), %eax\n" /* line 2449 */
        "movl %eax, 0x2bdac(%edx)\n"
        "movl 0x2bdc0(%edx), %eax\n" /* line 2450 */
        "movl %eax, 0x2bdb0(%edx)\n"
        "movl 0x2bdc4(%edx), %eax\n" /* line 2451 */
        "movl %eax, 0x2bdb4(%edx)\n"
        "ucomiss 0x2bdb4(%edx), %xmm4\n" /* line 2453 */
        "jne .Lf1cebea_001d075b\n"
        "jp .Lf1cebea_001d075b\n"
        "movss %xmm4, 0x2bda4(%edx)\n" /* line 2455 */
        "jmp .Lf1cebea_001cece0\n"
        ".Lf1cebea_001cfd7e:\n"
        "leal 0x25bc4(%ebx), %eax\n" /* line 1138 */
        "movl %eax, (%esp)\n"
        "calll BG_GetViewmodelWeaponIndex\n"
        "movl %eax, (%esp)\n" /* line 1139 */
        "calll BG_GetWeaponDef\n"
        "movl %eax, %edx\n"
        "movss 0x25ca0(%ebx), %xmm1\n" /* line 1141 */
        "movl 0x274(%eax), %eax\n" /* line 1148 */
        "cmpb $0, (%eax)\n"
        "jne .Lf1cebea_001cfdb7\n"
        "movl 0x278(%edx), %esi\n"
        "testl %esi, %esi\n"
        "je .Lf1cebea_001d070d\n"
        ".Lf1cebea_001cfdb7:\n"
        "pxor %xmm2, %xmm2\n" /* line 1152 */
        "ucomiss %xmm2, %xmm1\n"
        "jp .Lf1cebea_001cfdc6\n"
        "je .Lf1cebea_001d070d\n"
        ".Lf1cebea_001cfdc6:\n"
        "movl 0x28494(%ebx), %ecx\n" /* line 1156 */
        "testl %ecx, %ecx\n"
        "je .Lf1cebea_001d076a\n"
        "movss 0x26c(%edx), %xmm3\n" /* line 1158 */
        ".Lf1cebea_001cfddc:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 1164 | 1.0f */
        "subss %xmm3, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "ucomiss %xmm2, %xmm1\n" /* line 1165 */
        "jbe .Lf1cebea_001cfdf8\n"
        "divss %xmm3, %xmm0\n" /* line 1166 */
        ".Lf1cebea_001cfdf8:\n"
        "ucomiss lit4_002ed738, %xmm0\n" /* line 1170 | 0.009999999776482582f */
        "jp .Lf1cebea_001cfe07\n"
        "jbe .Lf1cebea_001d070d\n"
        ".Lf1cebea_001cfe07:\n"
        "movl imp_cg_hudGrenadeIconInScope, %eax\n" /* line 2098 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1cebea_001cf0bc\n"
        "leal -0x20(%ebp), %edx\n" /* line 2101 */
        "leal -0x1c(%ebp), %eax\n"
        "calll CG_CalcCrosshairPosition\n"
        ".Lf1cebea_001cfe23:\n"
        "movl $2, 4(%esp)\n" /* line 2109 */
        "leal -0x1c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $2, 4(%esp)\n" /* line 2110 */
        "leal -0x20(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll CalcScreenY\n"
        "movl imp_cg, %ecx\n" /* line 2112 */
        "movl (%ecx), %eax\n"
        "movl 0x24(%eax), %eax\n"
        "movl 0x26b4(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf1cebea_001cf0bc\n"
        "movl $0, -0x684(%ebp)\n"
        "movl %ecx, -0x694(%ebp)\n"
        "movl $0x26b0, %edi\n"
        "jmp .Lf1cebea_001cfe9d\n"
        ".Lf1cebea_001cfe79:\n"
        "addl $1, -0x684(%ebp)\n"
        "addl $0xf0, %edi\n"
        "movl (%ecx), %eax\n"
        "movl 0x24(%eax), %eax\n"
        "movl -0x684(%ebp), %ebx\n"
        "cmpl %ebx, 0x26b4(%eax)\n"
        "jle .Lf1cebea_001cf0bc\n"
        ".Lf1cebea_001cfe9d:\n"
        "leal (%eax, %edi), %ebx\n" /* line 2114 */
        "leal 0xc(%ebx), %esi\n"
        "cmpl $4, 4(%esi)\n" /* line 2041 */
        "jne .Lf1cebea_001cfe79\n"
        "leal 0x30(%ebx), %eax\n" /* line 2045 */
        "movss 0x30(%ebx), %xmm0\n" /* line 316 */
        "movss 4(%eax), %xmm1\n"
        "movss 8(%eax), %xmm2\n"
        "mulss %xmm0, %xmm0\n" /* line 2045 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "ucomiss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "ja .Lf1cebea_001cfe79\n"
        "movl 0xc8(%esi), %eax\n" /* line 2049 */
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl 0x390(%eax), %eax\n" /* line 2050 */
        "testl %eax, %eax\n"
        "jne .Lf1cebea_001d0777\n"
        "movl imp_cg, %ecx\n" /* line 2054 */
        "movl (%ecx), %eax\n"
        "movl %eax, -0x680(%ebp)\n"
        "leal 0x24(%ebx), %eax\n"
        "movl -0x680(%ebp), %edx\n"
        "addl $0x25bd8, %edx\n"
        "movss 0x24(%ebx), %xmm2\n" /* line 248 */
        "movl -0x680(%ebp), %ebx\n"
        "subss 0x25bd8(%ebx), %xmm2\n"
        "movss 4(%eax), %xmm3\n" /* line 249 */
        "subss 4(%edx), %xmm3\n"
        "movss 8(%eax), %xmm1\n" /* line 250 */
        "subss 8(%edx), %xmm1\n"
        "ucomiss lit4_002ed5e8, %xmm1\n" /* line 2056 | 0.0f */
        "jb .Lf1cebea_001d0782\n"
        ".Lf1cebea_001cff45:\n"
        "movl imp_cg_hudGrenadeIconMaxHeight, %eax\n" /* line 2063 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "movl -0x680(%ebp), %eax\n"
        "addss 0x25cbc(%eax), %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf1cebea_001cfe79\n"
        ".Lf1cebea_001cff68:\n"
        "movl imp_cg_hudGrenadeIconMaxRange, %eax\n" /* line 2068 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "mulss %xmm0, %xmm0\n" /* line 2071 */
        "mulss %xmm2, %xmm2\n"
        "mulss %xmm3, %xmm3\n"
        "addss %xmm3, %xmm2\n"
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lf1cebea_001cfe79\n"
        "leal 0x18(%esi), %eax\n" /* line 2116 */
        "movl (%ecx), %ecx\n"
        "leal 0x25bd8(%ecx), %edx\n"
        "movss 0x18(%esi), %xmm0\n" /* line 248 */
        "subss 0x25bd8(%ecx), %xmm0\n"
        "movss %xmm0, -0x620(%ebp)\n"
        "movss 4(%eax), %xmm0\n" /* line 249 */
        "subss 4(%edx), %xmm0\n"
        "movss %xmm0, -0x61c(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 250 */
        "subss 8(%edx), %xmm0\n"
        "movss %xmm0, -0x618(%ebp)\n"
        "movl imp_colorWhite, %edx\n" /* line 456 */
        "movl (%edx), %eax\n"
        "movl %eax, -0x220(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 457 */
        "movl %eax, -0x21c(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 458 */
        "movl %eax, -0x218(%ebp)\n"
        "movl 0xc(%edx), %eax\n" /* line 459 */
        "movl %eax, -0x214(%ebp)\n"
        "movl imp_cg_hudGrenadePointerPulseMin, %eax\n" /* line 2121 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm3\n"
        "movl imp_cg_hudGrenadePointerPulseMax, %eax\n"
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm2\n"
        "subss %xmm3, %xmm2\n"
        "mulss lit4_002ed5d8, %xmm2\n" /* 0.5f */
        "addss %xmm2, %xmm3\n" /* line 2123 */
        "cvtsi2sdl 0x25bb0(%ecx), %xmm0\n"
        "mulsd lit8_00307d98, %xmm0\n" /* 0.006283185307179587 */
        "movl imp_cg_hudGrenadePointerPulseFreq, %eax\n"
        "movl (%eax), %eax\n"
        "cvtss2sd 8(%eax), %xmm1\n"
        "mulsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "movss %xmm2, -0x6d8(%ebp)\n"
        "movss %xmm3, -0x6e8(%ebp)\n"
        "calll sinf\n"
        "fstps -0x6ec(%ebp)\n"
        "movss -0x6ec(%ebp), %xmm0\n"
        "movss -0x6d8(%ebp), %xmm2\n"
        "mulss %xmm2, %xmm0\n"
        "movss -0x6e8(%ebp), %xmm3\n"
        "addss %xmm3, %xmm0\n"
        "movaps %xmm0, %xmm1\n" /* line 45 */
        "subss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "pxor %xmm4, %xmm4\n"
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        "movaps %xmm3, %xmm2\n"
        "cmpnltss %xmm4, %xmm1\n"
        "andps %xmm1, %xmm2\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm2, %xmm1\n"
        "movaps %xmm4, %xmm2\n"
        "subss %xmm0, %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        "movaps %xmm1, %xmm3\n"
        "cmpltss %xmm4, %xmm0\n"
        "andps %xmm0, %xmm3\n"
        "andnps %xmm4, %xmm0\n"
        "orps %xmm3, %xmm0\n"
        "movss %xmm0, -0x214(%ebp)\n" /* line 2124 */
        "movss -0x20(%ebp), %xmm4\n" /* line 2126 */
        "movss %xmm4, -0x67c(%ebp)\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, -0x678(%ebp)\n"
        "movl imp_cg_hudGrenadePointerWidth, %eax\n" /* line 1974 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetRealWidthFromVirtualWidth\n"
        "fstps -0x674(%ebp)\n"
        "movl imp_cg_hudGrenadePointerHeight, %eax\n" /* line 1975 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetRealHeightFromVirtualHeight\n"
        "fstps -0x670(%ebp)\n"
        "movl imp_cg_hudGrenadeIconOffset, %edx\n" /* line 1976 */
        "movl (%edx), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetRealHeightFromVirtualHeight\n"
        "fstps -0x66c(%ebp)\n"
        "movl imp_cg_hudGrenadePointerPivot, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl (%eax), %edx\n" /* line 37 */
        "movl 4(%eax), %ebx\n" /* line 38 */
        "movl %edx, (%esp)\n" /* line 1979 */
        "calll GetRealWidthFromVirtualWidth\n"
        "fstps -0x62c(%ebp)\n"
        "movl %ebx, (%esp)\n" /* line 1980 */
        "calll GetRealHeightFromVirtualHeight\n"
        "fstps -0x630(%ebp)\n"
        "leal -0x620(%ebp), %ecx\n" /* line 1982 */
        "movl %ecx, -0x6a4(%ebp)\n"
        "movl %ecx, (%esp)\n"
        "calll vectoyaw\n"
        "fstps -0x6ec(%ebp)\n"
        "movss -0x6ec(%ebp), %xmm0\n"
        "movl -0x694(%ebp), %eax\n"
        "movl (%eax), %ebx\n"
        "subss 0x25cb0(%ebx), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll AngleNormalize360\n"
        "fstps -0x668(%ebp)\n"
        "cvtss2sd -0x668(%ebp), %xmm0\n" /* line 1984 */
        "mulsd lit8_00307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x664(%ebp)\n"
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0x6ec(%ebp)\n"
        "movss -0x6ec(%ebp), %xmm0\n"
        "mulss -0x66c(%ebp), %xmm0\n"
        "movss -0x678(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x678(%ebp)\n"
        "movss -0x664(%ebp), %xmm2\n" /* line 486 */
        "movss %xmm2, (%esp)\n"
        "calll cosf\n"
        "fstps -0x698(%ebp)\n"
        "movss -0x66c(%ebp), %xmm3\n"
        "mulss -0x698(%ebp), %xmm3\n"
        "movss -0x67c(%ebp), %xmm4\n"
        "subss %xmm3, %xmm4\n"
        "movss -0x62c(%ebp), %xmm0\n" /* line 1988 */
        "xorps sse_float_sign_mask, %xmm0\n"
        "movss %xmm0, -0x108(%ebp)\n"
        "movss %xmm0, -0x120(%ebp)\n"
        "movss -0x674(%ebp), %xmm0\n" /* line 1989 */
        "subss -0x62c(%ebp), %xmm0\n"
        "movss %xmm0, -0x110(%ebp)\n"
        "movss %xmm0, -0x118(%ebp)\n"
        "movss -0x630(%ebp), %xmm0\n" /* line 1990 */
        "xorps sse_float_sign_mask, %xmm0\n"
        "movss %xmm0, -0x114(%ebp)\n"
        "movss %xmm0, -0x11c(%ebp)\n"
        "movss -0x670(%ebp), %xmm0\n" /* line 1991 */
        "subss -0x630(%ebp), %xmm0\n"
        "movss %xmm0, -0x104(%ebp)\n"
        "movss %xmm0, -0x10c(%ebp)\n"
        "movl imp_cgs, %eax\n" /* line 1993 */
        "movl (%eax), %esi\n"
        "movl 0xc1fc(%esi), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "leal -0x220(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "xorl $0x80000000, -0x668(%ebp)\n"
        "movss -0x668(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "leal -0x120(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movss %xmm4, 4(%esp)\n"
        "movss -0x678(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll CG_DrawRotatedQuadPic\n"
        "movss -0x20(%ebp), %xmm1\n" /* line 2127 */
        "movss %xmm1, -0x660(%ebp)\n"
        "movss -0x1c(%ebp), %xmm2\n"
        "movss %xmm2, -0x65c(%ebp)\n"
        "movl imp_cg_hudGrenadeIconWidth, %eax\n" /* line 2007 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetRealWidthFromVirtualWidth\n"
        "fstps -0x658(%ebp)\n"
        "movl imp_cg_hudGrenadeIconHeight, %eax\n" /* line 2008 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetRealHeightFromVirtualHeight\n"
        "fstps -0x654(%ebp)\n"
        "movl imp_cg_hudGrenadeIconOffset, %edx\n" /* line 2009 */
        "movl (%edx), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetRealHeightFromVirtualHeight\n"
        "fstps -0x650(%ebp)\n"
        "movl -0x6a4(%ebp), %ecx\n" /* line 2011 */
        "movl %ecx, (%esp)\n"
        "calll vectoyaw\n"
        "fstps -0x6ec(%ebp)\n"
        "movss -0x6ec(%ebp), %xmm0\n"
        "subss 0x25cb0(%ebx), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll AngleNormalize360\n"
        "fstps -0x64c(%ebp)\n"
        "cvtss2sd -0x64c(%ebp), %xmm0\n" /* line 2013 */
        "mulsd lit8_00307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x648(%ebp)\n"
        "movss %xmm0, (%esp)\n" /* line 486 */
        "calll cosf\n"
        "fstps -0x69c(%ebp)\n"
        "movss -0x648(%ebp), %xmm0\n" /* line 485 */
        "movss %xmm0, (%esp)\n"
        "calll sinf\n"
        "fstps -0x6ec(%ebp)\n"
        "movss -0x6ec(%ebp), %xmm1\n"
        "mulss -0x650(%ebp), %xmm1\n"
        "movss -0x658(%ebp), %xmm0\n" /* line 2014 */
        "mulss lit4_002ed63c, %xmm0\n" /* -0.5f */
        "addss -0x65c(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x108(%ebp)\n"
        "movss %xmm0, -0x120(%ebp)\n"
        "movss -0x658(%ebp), %xmm0\n" /* line 2015 */
        "mulss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "addss -0x65c(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x110(%ebp)\n"
        "movss %xmm0, -0x118(%ebp)\n"
        "movss -0x650(%ebp), %xmm1\n" /* line 2016 */
        "mulss -0x69c(%ebp), %xmm1\n"
        "movss -0x654(%ebp), %xmm0\n"
        "mulss lit4_002ed63c, %xmm0\n" /* -0.5f */
        "addss -0x660(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x114(%ebp)\n"
        "movss %xmm0, -0x11c(%ebp)\n"
        "movss -0x654(%ebp), %xmm0\n" /* line 2017 */
        "mulss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "addss -0x660(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x104(%ebp)\n"
        "movss %xmm0, -0x10c(%ebp)\n"
        "movl 0xc1f8(%esi), %eax\n" /* line 2019 */
        "movl %eax, 8(%esp)\n"
        "leal -0x220(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x120(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll CL_DrawQuadPic\n"
        "movl -0x694(%ebp), %ecx\n"
        "jmp .Lf1cebea_001cfe79\n"
        ".Lf1cebea_001d04d8:\n"
        "calll CG_DrawCrosshairNames\n" /* line 3326 */
        "calll CG_DrawChatMessages\n" /* line 3328 */
        "jmp .Lf1cebea_001cf393\n"
        ".Lf1cebea_001d04e7:\n"
        "movl $0x100, 8(%esp)\n" /* line 2985 */
        "movl $str_002ac060, 4(%esp)\n" /* "vote yes" */
        "leal -0x220(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll I_strncpyz\n"
        "jmp .Lf1cebea_001cf51e\n"
        ".Lf1cebea_001d050a:\n"
        "movss 0x270(%edx), %xmm3\n" /* line 1164 */
        "jmp .Lf1cebea_001cf6e5\n"
        ".Lf1cebea_001d0517:\n"
        "movl $0x3f800000, %eax\n" /* line 2593 */
        ".Lf1cebea_001d051c:\n"
        "movl $2, 0xc(%esp)\n" /* line 2606 */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $6, (%esp)\n"
        "calll Con_DrawNotify\n"
        "jmp .Lf1cebea_001cf335\n"
        ".Lf1cebea_001d053d:\n"
        "movl $0, 0x2b990(%ebx)\n" /* line 1068 */
        "movl $0, 0x2bd9c(%ebx)\n" /* line 1069 */
        "jmp .Lf1cebea_001cf324\n"
        ".Lf1cebea_001d0556:\n"
        "movl %edx, %ebx\n"
        "jmp .Lf1cebea_001cee3e\n"
        ".Lf1cebea_001d055d:\n"
        "movl $str_002b7290, (%esp)\n" /* line 3008 */
        "calll UI_SafeTranslateString\n"
        "leal 0x6094(%esi), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b729c, (%esp)\n" /* "%s(%i):%s" */
        "calll va\n"
        "movl $3, 0x24(%esp)\n" /* line 3009 */
        "movl imp_colorYellow, %ecx\n"
        "movl %ecx, 0x20(%esp)\n"
        "movl $0x3e555555, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x43480000, 0x10(%esp)\n"
        "movl $0x41000000, 0xc(%esp)\n"
        "movl -0x644(%ebp), %ebx\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        "movl 0x6090(%esi), %edi\n" /* line 3012 */
        "movl $str_002b72a8, (%esp)\n" /* "CGAME_NO" */
        "calll UI_SafeTranslateString\n"
        "movl %eax, %ebx\n"
        "movl 0x608c(%esi), %esi\n"
        "movl $str_002b72b4, (%esp)\n" /* "CGAME_YES" */
        "calll UI_SafeTranslateString\n"
        "movl %edi, 0x18(%esp)\n"
        "movl -0x6a4(%ebp), %edx\n"
        "movl %edx, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n"
        "leal -0x220(%ebp), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002b72d0, (%esp)\n" /* "%s(%s):%i, %s(%s):%i" */
        "jmp .Lf1cebea_001cf658\n"
        ".Lf1cebea_001d0631:\n"
        "movl $0x100, 8(%esp)\n" /* line 2991 */
        "movl $str_002ac06c, 4(%esp)\n" /* "vote no" */
        "leal -0x620(%ebp), %ebx\n"
        "movl %ebx, -0x6a4(%ebp)\n"
        "movl %ebx, (%esp)\n"
        "calll I_strncpyz\n"
        "jmp .Lf1cebea_001cf556\n"
        ".Lf1cebea_001d065a:\n"
        "calll CG_DrawMaterial\n" /* line 2787 */
        "jmp .Lf1cebea_001cf2d2\n"
        ".Lf1cebea_001d0664:\n"
        "movl $str_002b7280, (%esp)\n" /* line 2954 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, %esi\n"
        "movl $0x3f000000, 4(%esp)\n" /* line 2955 */
        "movl $4, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %eax, %ebx\n"
        "movl $0x3f000000, 0xc(%esp)\n" /* line 2956 */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll UI_TextWidth\n"
        "movl $3, 0x24(%esp)\n" /* line 2958 */
        "movl imp_colorWhite, %edx\n"
        "movl %edx, 0x20(%esp)\n"
        "movl $0x3f000000, 0x1c(%esp)\n"
        "movl $3, 0x18(%esp)\n"
        "movl $7, 0x14(%esp)\n"
        "movl $0xc1d80000, 0x10(%esp)\n"
        "negl %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll UI_DrawText\n"
        "calll CG_DrawCrosshairNames\n" /* line 3307 */
        "calll CG_DrawChatMessages\n" /* line 3308 */
        "jmp .Lf1cebea_001cf736\n"
        ".Lf1cebea_001d070d:\n"
        "xorl %eax, %eax\n" /* line 2105 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl %eax, -0x20(%ebp)\n" /* line 2106 */
        "jmp .Lf1cebea_001cfe23\n"
        ".Lf1cebea_001d071a:\n"
        "leal -0x1c(%ebp), %edx\n" /* line 1927 */
        "leal -0x20(%ebp), %eax\n"
        "calll CG_CalcCrosshairPosition\n"
        "movss lit4_002ed8e8, %xmm0\n" /* line 1928 | 320.0f */
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss lit4_002ed6e8, %xmm0\n" /* line 1929 | 240.0f */
        "addss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "jmp .Lf1cebea_001cee94\n"
        ".Lf1cebea_001d074e:\n"
        "movss -0x634(%ebp), %xmm4\n"
        "jmp .Lf1cebea_001cfba3\n"
        ".Lf1cebea_001d075b:\n"
        "leal 0x2bda8(%edx), %eax\n" /* line 2459 */
        "movl %eax, 0x10(%esp)\n"
        "jmp .Lf1cebea_001cecab\n"
        ".Lf1cebea_001d076a:\n"
        "movss 0x270(%edx), %xmm3\n" /* line 1164 */
        "jmp .Lf1cebea_001cfddc\n"
        ".Lf1cebea_001d0777:\n"
        "movl imp_cg, %ecx\n"
        "jmp .Lf1cebea_001cfe79\n"
        ".Lf1cebea_001d0782:\n"
        "jp .Lf1cebea_001cff45\n" /* line 2056 */
        "movl imp_cg_hudGrenadeIconMaxHeight, %eax\n" /* line 2058 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "xorps sse_float_sign_mask, %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf1cebea_001cfe79\n"
        "jmp .Lf1cebea_001cff68\n"
    );
}
