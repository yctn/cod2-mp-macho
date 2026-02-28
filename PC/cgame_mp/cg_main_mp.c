/* ASM dump from: cg_main_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_main_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

extern struct XModel * CL_RegisterModel(const char *name);
extern void * Hunk_AllocAlignInternal(int size, int alignment);
extern void * Hunk_AllocInternal(int size);
extern void CL_ConsolePrint(int channel, const char *msg, int duration, int width);
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
static const char * cg_soundRoomTypes[27]; /* cg_soundRoomTypes */
static const char * cg_drawSoundOverlayStrings[5]; /* cg_drawSoundOverlayStrings */
static const char * cg_drawFpsNames[5]; /* cg_drawFpsNames */

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
void CG_GetDObjOrientation(int dobjHandle, vec3_t *axis_out);
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
    vec_t *origin = (vec_t *)(ent + 0x1ec);
    origin_out[0] = origin[0];
    origin_out[1] = origin[1];
    origin_out[2] = origin[2];
    AnglesToAxis((vec_t *)(ent + 0x1f8), axis_out);
}

/* line 727 */
int CG_CrosshairPlayer(void)
{
    if (*(int *)0xdb8c30 > *(int *)0xdbee50 + 0x3e8)
        return -1;
    return *(int *)0xdbee4c;
}

/* line 737 */
void CG_GameMessage(const char *msg)
{
    CL_ConsolePrint(1, msg, 0, *(int *)(*(int *)&cg_gameMessageWidth + 8));
}

/* line 743 */
void CG_BoldGameMessage(const char *msg)
{
    CL_ConsolePrint(2, msg, 0, *(int *)(*(int *)&cg_gameBoldMessageWidth + 8));
}

/* line 754 */
const char * CG_Argv(int arg)
{
    Cmd_ArgvBuffer(arg, (char *)&buffer, 0x400);
    return (const char *)&buffer;
}

/* line 862 */
static __attribute__((naked))
void CG_RegisterGraphics(const char *mapname)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 862 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %eax, -0x3c(%ebp)\n"
        /* { scope 1: mins, maxs */
        "calll SCR_UpdateScreen\n" /* line 866 */
        "movl $str_002a754c, (%esp)\n" /* line 868 */
        "calll Com_Printf\n"
        "movl $1, (%esp)\n" /* line 869 */
        "calll FX_InitSystem\n"
        "calll FX_CreateDefaultEffect\n" /* line 871 */
        "movl $str_002a7580, (%esp)\n" /* line 873 */
        "calll Com_Printf\n"
        "movl $str_002a75b4, (%esp)\n" /* line 875 */
        "calll CG_LoadingString\n"
        "movl cgs, %ebx\n" /* line 877 */
        "movl $7, 4(%esp)\n"
        "movl $str_002a75c0, (%esp)\n" /* "lagometer" */
        "calll CL_RegisterMaterial\n"
        "movl %eax, 0xba40(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 878 */
        "movl $str_002a75cc, (%esp)\n" /* "headicondisconnected" */
        "calll CL_RegisterMaterial\n"
        "movl %eax, 0xba34(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 879 */
        "movl $str_002a75e4, (%esp)\n" /* "headiconyouinkillcam" */
        "calll CL_RegisterMaterial\n"
        "movl %eax, 0xba38(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 882 */
        "movl $str_002a75fc, (%esp)\n" /* "killiconmelee" */
        "calll CL_RegisterMaterial\n"
        "movl $7, 4(%esp)\n" /* line 883 */
        "movl $str_002a760c, (%esp)\n" /* "killiconsuicide" */
        "calll CL_RegisterMaterial\n"
        "movl $7, 4(%esp)\n" /* line 884 */
        "movl $str_002a761c, (%esp)\n" /* "killiconfalling" */
        "calll CL_RegisterMaterial\n"
        "movl $7, 4(%esp)\n" /* line 885 */
        "movl $str_002a762c, (%esp)\n" /* "killiconcrush" */
        "calll CL_RegisterMaterial\n"
        "movl $7, 4(%esp)\n" /* line 886 */
        "movl $str_002a763c, (%esp)\n" /* "killicondied" */
        "calll CL_RegisterMaterial\n"
        "movl $6, 4(%esp)\n" /* line 888 */
        "movl $str_002a764c, (%esp)\n" /* "gfx/misc/tracer" */
        "calll CL_RegisterMaterial\n"
        "movl %eax, 0xba3c(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 890 */
        "movl $str_002a765c, (%esp)\n" /* "gfx/icons/hint_usable" */
        "calll CL_RegisterMaterial\n"
        "movl %eax, 0xba4c(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 891 */
        "movl $str_002a7674, (%esp)\n" /* "hint_health" */
        "calll CL_RegisterMaterial\n"
        "movl %eax, 0xba50(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 892 */
        "movl $str_002a7680, (%esp)\n" /* "hint_friendly" */
        "calll CL_RegisterMaterial\n"
        "movl %eax, 0xba54(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 894 */
        "movl $str_002a7690, (%esp)\n" /* "stance_stand" */
        "calll CL_RegisterMaterial\n"
        "movl %eax, 0xbc58(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 895 */
        "movl $str_002a76a0, (%esp)\n" /* "stance_crouch" */
        "calll CL_RegisterMaterial\n"
        "movl %eax, 0xbc5c(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 896 */
        "movl $str_002a76b0, (%esp)\n" /* "stance_prone" */
        "calll CL_RegisterMaterial\n"
        "movl %eax, 0xbc60(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 897 */
        "movl $str_002a76c0, (%esp)\n" /* "stance_flash" */
        "calll CL_RegisterMaterial\n"
        "movl %eax, 0xbc64(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 899 */
        "movl $str_002a76d0, (%esp)\n" /* "objective" */
        "calll CL_RegisterMaterial\n"
        "movl %eax, 0xbc68(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 905 */
        "movl $str_002a76dc, (%esp)\n" /* "objective_friendly" */
        "calll CL_RegisterMaterial\n"
        "movl %eax, 0xbc6c(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 906 */
        "movl $str_002a76f0, (%esp)\n" /* "objective_friendly_chat" */
        "calll CL_RegisterMaterial\n"
        "movl %eax, 0xbc70(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 908 */
        "movl $str_002a7708, (%esp)\n" /* "hit_direction" */
        "calll CL_RegisterMaterial\n"
        "movl %eax, 0xbc74(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 909 */
        "movl $str_002a7718, (%esp)\n" /* "hint_mantle" */
        "calll CL_RegisterMaterial\n"
        "movl %eax, 0xbc78(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 911 */
        "movl $str_002a7724, (%esp)\n" /* "ui/assets/checkbox_clear" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, 0xc1d4(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 912 */
        "movl $str_002a7740, (%esp)\n" /* "ui/assets/checkbox_checked" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, 0xc1d8(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 913 */
        "movl $str_002a775c, (%esp)\n" /* "ui/assets/checkbox_fail" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, 0xc1dc(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 915 */
        "movl $str_002a7774, (%esp)\n" /* "compassping_friendlyfiring" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, 0xc1e0(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 916 */
        "movl $str_002a7790, (%esp)\n" /* "compassping_friendlyyelling" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, 0xc1e4(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 917 */
        "movl $str_002a77ac, (%esp)\n" /* "compassping_enemyfiring" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, 0xc1e8(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 918 */
        "movl $str_002a77c4, (%esp)\n" /* "compassping_enemyyelling" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, 0xc1ec(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 919 */
        "movl $str_002a77e0, (%esp)\n" /* "compassping_grenade" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, 0xc1f0(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 920 */
        "movl $str_002a77f4, (%esp)\n" /* "compassping_explosion" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, 0xc1f4(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 921 */
        "movl $str_002a780c, (%esp)\n" /* "hud_grenadeicon" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, 0xc1f8(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 922 */
        "movl $str_002a781c, (%esp)\n" /* "hud_grenadepointer" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, 0xc1fc(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 928 */
        "movl $str_002a7830, (%esp)\n" /* "hudcolorbar" */
        "calll CL_RegisterMaterial\n"
        "movl %eax, 0xba28(%ebx)\n"
        "movl $str_002a783c, (%esp)\n" /* line 930 */
        "calll CG_LoadingString\n"
        "movl $7, 4(%esp)\n" /* line 934 */
        "movl $str_002a7848, (%esp)\n" /* "headiconvoicechat" */
        "calll CL_RegisterMaterial\n"
        "movl %eax, 0xba2c(%ebx)\n"
        "movl $7, 4(%esp)\n" /* line 935 */
        "movl $str_002a785c, (%esp)\n" /* "headicontalkballoon" */
        "calll CL_RegisterMaterial\n"
        "movl %eax, 0xba30(%ebx)\n"
        "calll CG_RegisterScoreboardGraphics\n" /* line 937 */
        "movl $0x2400, 8(%esp)\n" /* line 939 */
        "movl $0, 4(%esp)\n"
        "movl cg_items, %eax\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $0xda00, 8(%esp)\n" /* line 940 */
        "movl $0, 4(%esp)\n"
        "movl cg_weapons, %eax\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $str_002a7870, (%esp)\n" /* line 943 */
        "calll CG_LoadingString\n"
        "calll CG_RegisterItems\n" /* line 944 */
        "movl $str_002a787c, (%esp)\n" /* line 946 */
        "calll CG_LoadingString\n"
        "calll CM_NumInlineModels\n" /* line 949 */
        "movl %eax, 0x7188(%ebx)\n"
        "subl $1, %eax\n" /* line 950 */
        "jg .Lf143d5e_0014430b\n"
        ".Lf143d5e_00144196:\n"
        "movl $str_002a7890, (%esp)\n" /* line 963 */
        "calll CG_LoadingString\n"
        "movl $1, %esi\n"
        "movl cgs, %edi\n" /* i */
        "jmp .Lf143d5e_001441ce\n"
        /* { scope 2 */
        ".Lf143d5e_001441af:\n"
        "calll SCR_UpdateScreen\n" /* line 974 */
        "movl %ebx, (%esp)\n" /* line 976 | modelName */
        "calll CL_RegisterModel\n"
        "movl %eax, 0x63c0(%edi, %esi, 4)\n" /* i */
        /* } scope */
        "addl $1, %esi\n" /* line 966 */
        "cmpl $0x100, %esi\n"
        "je .Lf143d5e_001441e3\n"
        /* { scope 2 */
        ".Lf143d5e_001441ce:\n"
        "leal 0x14e(%esi), %eax\n" /* line 970 */
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl %eax, %ebx\n" /* modelName */
        "cmpb $0, (%eax)\n" /* line 971 */
        "jne .Lf143d5e_001441af\n"
        /* } scope */
        ".Lf143d5e_001441e3:\n"
        "movl $1, %ebx\n" /* line 966 */
        "movl cgs, %esi\n"
        "jmp .Lf143d5e_00144207\n"
        /* { scope 2 */
        ".Lf143d5e_001441f0:\n"
        "movl %eax, (%esp)\n" /* line 987 */
        "calll FX_RegisterEffect\n"
        "movl %eax, 0x67c0(%esi, %ebx, 4)\n"
        /* } scope */
        "addl $1, %ebx\n" /* line 980 | modelName */
        "cmpl $0x40, %ebx\n" /* modelName */
        "je .Lf143d5e_0014421a\n"
        /* { scope 2 */
        ".Lf143d5e_00144207:\n"
        "leal 0x34e(%ebx), %eax\n" /* line 984 | modelName */
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "cmpb $0, (%eax)\n" /* line 985 */
        "jne .Lf143d5e_001441f0\n"
        /* } scope */
        ".Lf143d5e_0014421a:\n"
        "movl cgs, %ebx\n" /* line 990 | modelName */
        "movl $str_002a78a4, (%esp)\n" /* "fx/props/american_smoke_grenade.efx" */
        "calll FX_RegisterEffect\n"
        "movl %eax, 0x68c0(%ebx)\n" /* modelName */
        "movl $1, %esi\n"
        "leal 0x6948(%ebx), %edi\n" /* modelName, i */
        "jmp .Lf143d5e_00144255\n"
        /* { scope 2 */
        ".Lf143d5e_0014423f:\n"
        "movl %edi, (%esp)\n" /* line 1002 | i */
        "calll CG_SetShellShockParmsFromDvars\n"
        /* } scope */
        "addl $1, %esi\n" /* line 993 */
        "addl $0x84, %edi\n" /* i */
        "cmpl $0x10, %esi\n"
        "je .Lf143d5e_001442a4\n"
        /* { scope 2 */
        ".Lf143d5e_00144255:\n"
        "leal 0x48e(%esi), %eax\n" /* line 997 */
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl %eax, %ebx\n" /* shellshock */
        "cmpb $0, (%eax)\n" /* line 998 */
        "je .Lf143d5e_001442a4\n"
        "movl %eax, (%esp)\n" /* line 1000 */
        "calll CG_LoadShellShockDvars\n"
        "testl %eax, %eax\n"
        "jne .Lf143d5e_0014423f\n"
        "movl %ebx, 8(%esp)\n" /* line 1001 | shellshock */
        "movl $str_002a78c8, 4(%esp)\n" /* "couldn't register shell shock '%s' -- see console
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl %edi, (%esp)\n" /* line 1002 | i */
        "calll CG_SetShellShockParmsFromDvars\n"
        /* } scope */
        "addl $1, %esi\n" /* line 993 */
        "addl $0x84, %edi\n" /* i */
        "cmpl $0x10, %esi\n"
        "jne .Lf143d5e_00144255\n"
        ".Lf143d5e_001442a4:\n"
        "movl $str_002a78fc, (%esp)\n" /* line 1005 */
        "calll CG_LoadShellShockDvars\n"
        "testl %eax, %eax\n"
        "je .Lf143d5e_001443a6\n"
        ".Lf143d5e_001442b8:\n"
        "movl cgs, %ebx\n" /* line 1007 | shellshock */
        "leal 0x7104(%ebx), %eax\n" /* shellshock */
        "movl %eax, (%esp)\n"
        "calll CG_SetShellShockParmsFromDvars\n"
        "movl -0x3c(%ebp), %eax\n" /* line 1027 */
        "movl %eax, (%esp)\n"
        "calll CG_RegisterImpactEffects\n"
        "movl %eax, 0xc200(%ebx)\n" /* shellshock */
        "testl %eax, %eax\n" /* line 1028 */
        "je .Lf143d5e_001443bf\n"
        "movl $str_002a7980, (%esp)\n" /* line 1030 */
        "calll FX_RegisterEffect\n"
        "movl %eax, 0xc204(%ebx)\n" /* shellshock */
        "movl $str_002a79a4, (%esp)\n" /* line 1032 */
        "calll CG_LoadingString\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1033 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: mins, maxs */
        ".Lf143d5e_0014430b:\n"
        "movl $1, %edi\n" /* line 950 | i */
        "movl %ebx, %esi\n"
        "movl $3, -0x40(%ebp)\n"
        /* { scope 2 */
        ".Lf143d5e_00144319:\n"
        "movl %edi, (%esp)\n" /* line 955 | i */
        "calll CL_RegisterInlineModel\n"
        "movl %eax, 0x718c(%ebx, %edi, 4)\n"
        "leal -0x30(%ebp), %eax\n" /* line 956 | maxs */
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* mins */
        "movl %eax, 4(%esp)\n"
        "movl 0x718c(%esi, %edi, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_ModelBounds\n"
        "xorl %ecx, %ecx\n"
        ".Lf143d5e_00144347:\n"
        "leal (, %ecx, 4), %eax\n" /* line 959 */
        "movss -0x24(%ebp, %eax), %xmm2\n"
        "movl -0x40(%ebp), %edx\n"
        "addl %ecx, %edx\n"
        "cvtss2sd %xmm2, %xmm1\n"
        "movss -0x30(%ebp, %eax), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "mulsd lit8_00307ce0, %xmm0\n" /* 0.5 */
        "addsd %xmm0, %xmm1\n"
        "cvtsd2ss %xmm1, %xmm1\n"
        "movss %xmm1, 0x8188(%esi, %edx, 4)\n"
        "addl $1, %ecx\n" /* line 957 */
        "cmpl $3, %ecx\n"
        "jne .Lf143d5e_00144347\n"
        /* } scope */
        "addl $1, %edi\n" /* line 950 | i */
        "addl $3, -0x40(%ebp)\n"
        "movl %esi, %ebx\n"
        "cmpl 0x7188(%esi), %edi\n" /* i */
        "jl .Lf143d5e_00144319\n"
        "jmp .Lf143d5e_00144196\n"
        ".Lf143d5e_001443a6:\n"
        "movl $str_002a7908, 4(%esp)\n" /* line 1006 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf143d5e_001442b8\n"
        ".Lf143d5e_001443bf:\n"
        "movl $str_002a7938, 4(%esp)\n" /* line 1029 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl $str_002a7980, (%esp)\n" /* line 1030 */
        "calll FX_RegisterEffect\n"
        "movl %eax, 0xc204(%ebx)\n" /* shellshock */
        "movl $str_002a79a4, (%esp)\n" /* line 1032 */
        "calll CG_LoadingString\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 1033 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1043 */
__attribute__((naked))
void CG_StartAmbient(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1043 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl $3, (%esp)\n" /* line 1053 */
        "calll CL_GetConfigString\n"
        "movl %eax, %ebx\n"
        "movl $str_002a67e4, 4(%esp)\n" /* line 1055 */
        "movl %eax, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n" /* line 1056 */
        "calll CL_PickSoundAlias\n"
        "movl %eax, %esi\n" /* pAlias */
        "movl $str_002a79b8, 4(%esp)\n" /* line 1058 */
        "movl %ebx, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n" /* line 1059 */
        "calll atoi\n"
        "movl cg, %edx\n"
        "movl 0x25bb0(%edx), %edx\n"
        "subl %edx, %eax\n" /* line 1060 */
        "js .Lf1443fa_00144456\n"
        "testl %edx, %edx\n"
        "jne .Lf1443fa_00144458\n"
        ".Lf1443fa_00144456:\n"
        "xorl %eax, %eax\n"
        ".Lf1443fa_00144458:\n"
        "movl $1, 8(%esp)\n" /* line 1063 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* pAlias */
        "calll SND_PlayAmbientAlias\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 1064 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
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
static __attribute__((naked))
Bool CG_ReplaceDirective(int *searchPos, int *dstLen, char *dstString)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1290 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x33c, %esp\n"
        "movl %eax, -0x328(%ebp)\n"
        "movl %edx, -0x32c(%ebp)\n"
        "movl %ecx, -0x330(%ebp)\n"
        /* { scope 1 */
        "movl (%edx), %eax\n" /* line 1311 */
        "movl %eax, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "leal -0x318(%ebp), %edx\n" /* srcString */
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl -0x32c(%ebp), %edx\n" /* line 1312 */
        "movl (%edx), %eax\n"
        "movb $0, -0x318(%ebp, %eax)\n"
        "leal -0x318(%ebp), %eax\n" /* line 1314 | srcString */
        "movl -0x328(%ebp), %edx\n"
        "addl (%edx), %eax\n"
        "movl $str_002a79bc, 4(%esp)\n" /* "[{" */
        "movl %eax, (%esp)\n"
        "calll strstr\n"
        "movl %eax, %esi\n"
        "testl %eax, %eax\n" /* line 1315 */
        "je .Lf144488_00144519\n"
        "movl $str_002a79c0, 4(%esp)\n" /* line 1318 */
        "movl %eax, (%esp)\n"
        "calll strstr\n"
        "movl %eax, -0x334(%ebp)\n"
        "testl %eax, %eax\n" /* line 1319 */
        "je .Lf144488_00144519\n"
        "subl %esi, %eax\n" /* line 1327 */
        "subl $2, %eax\n" /* line 1329 */
        "movl %eax, -0x324(%ebp)\n" /* directiveLen */
        "jne .Lf144488_00144526\n"
        ".Lf144488_00144519:\n"
        "xorl %eax, %eax\n" /* line 1372 */
        /* } scope */
        "addl $0x33c, %esp\n" /* line 1373 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf144488_00144526:\n"
        "calll Controls_GetConfig\n" /* line 1337 */
        "leal -0x218(%ebp), %ebx\n" /* line 1338 | directive, endLen */
        "leal 2(%esi), %eax\n"
        "movl -0x324(%ebp), %edx\n" /* directiveLen */
        "movl %edx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* endLen */
        "calll memcpy\n"
        "movl -0x324(%ebp), %eax\n" /* line 1339 | directiveLen */
        "movb $0, -0x218(%ebp, %eax)\n"
        "leal -0x118(%ebp), %edx\n" /* line 1341 | keyBinding */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* endLen */
        "calll GetKeyBindingLocalizedString\n"
        "testl %eax, %eax\n"
        "je .Lf144488_0014463b\n"
        ".Lf144488_00144572:\n"
        "cld\n" /* line 1344 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "leal -0x118(%ebp), %edi\n" /* keyBinding, beginLen */
        "repne scasb %es:(%edi), %al\n" /* beginLen */
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x320(%ebp)\n" /* bindingLen */
        "movl -0x32c(%ebp), %edx\n" /* line 1346 */
        "movl (%edx), %eax\n"
        "subl -0x324(%ebp), %eax\n" /* directiveLen */
        "addl %ecx, %eax\n"
        "leal -4(%eax), %edx\n"
        "movl %edx, -0x31c(%ebp)\n" /* newStringLen */
        "subl $3, %eax\n" /* line 1348 */
        "cmpl $0x100, %eax\n"
        "jg .Lf144488_00144519\n"
        "movl %esi, %edi\n" /* line 1357 | beginLen */
        "leal -0x318(%ebp), %eax\n" /* srcString */
        "subl %eax, %edi\n" /* beginLen */
        "movl -0x330(%ebp), %esi\n" /* line 1358 */
        "addl %edi, %esi\n" /* beginLen */
        "movl %ecx, 8(%esp)\n" /* line 1360 */
        "leal -0x118(%ebp), %eax\n" /* keyBinding */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll memcpy\n"
        "addl -0x320(%ebp), %esi\n" /* line 1361 | bindingLen */
        "movl -0x31c(%ebp), %ebx\n" /* line 1364 | newStringLen, endLen */
        "subl %edi, %ebx\n" /* beginLen, endLen */
        "subl -0x320(%ebp), %ebx\n" /* bindingLen, endLen */
        "movl -0x334(%ebp), %eax\n" /* line 1365 */
        "addl $2, %eax\n"
        "movl %ebx, 8(%esp)\n" /* endLen */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll memcpy\n"
        "movb $0, (%esi, %ebx)\n" /* line 1366 */
        "movl -0x320(%ebp), %eax\n" /* line 1368 | bindingLen */
        "addl %edi, %eax\n" /* beginLen */
        "movl -0x328(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "movl -0x31c(%ebp), %edx\n" /* line 1369 | newStringLen */
        "movl -0x32c(%ebp), %eax\n"
        "movl %edx, (%eax)\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x33c, %esp\n" /* line 1373 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf144488_0014463b:\n"
        "movl $str_002a79c4, (%esp)\n" /* line 1342 */
        "calll UI_SafeTranslateString\n"
        "movl $0x100, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x118(%ebp), %eax\n" /* keyBinding */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "jmp .Lf144488_00144572\n"
    );
}

/* line 1376 */
__attribute__((naked))
void CG_TranslateHudElemMessage(const char *message, const char *messageType, char *hudElemString)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1376 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0x10(%ebp), %esi\n" /* hudElemString */
        /* { scope 1 */
        "movl $0, 8(%esp)\n" /* line 1385 */
        "movl 0xc(%ebp), %eax\n" /* messageType */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* message */
        "movl %eax, (%esp)\n"
        "calll SEH_LocalizeTextMessage\n"
        "movl %eax, %edx\n"
        "cld\n" /* line 1386 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %edx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* stringLen */
        "cmpl $0x100, %ecx\n" /* line 1388 */
        "jle .Lf144666_001446b2\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1404 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf144666_001446b2:\n"
        "movl %eax, 8(%esp)\n" /* line 1396 */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* hudElemString */
        "calll memcpy\n"
        "movl -0x20(%ebp), %eax\n" /* line 1397 | stringLen */
        "movb $0, (%esi, %eax)\n" /* hudElemString */
        "movl $0, -0x1c(%ebp)\n" /* line 1399 | searchPos */
        "leal -0x20(%ebp), %ebx\n" /* stringLen */
        "leal -0x1c(%ebp), %edi\n" /* searchPos */
        ".Lf144666_001446d6:\n"
        "movl %esi, %ecx\n" /* line 1401 | hudElemString */
        "movl %ebx, %edx\n"
        "movl %edi, %eax\n"
        "calll CG_ReplaceDirective\n"
        "testb %al, %al\n"
        "jne .Lf144666_001446d6\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1404 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1529 */
static __attribute__((naked))
void CG_LoadHudMenu(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1529 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl $7, 4(%esp)\n" /* line 1540 */
        "movl $str_002a79d0, (%esp)\n" /* "ui_mp/hud.txt" */
        "calll UI_LoadMenus\n"
        "movl %eax, 4(%esp)\n" /* line 1541 */
        "movl $cgDC, (%esp)\n"
        "calll UI_AddMenuList\n"
        "calll CL_GetLocalClientActiveCount\n" /* line 1543 */
        "subl $1, %eax\n"
        "je .Lf1446ee_0014475f\n"
        "movl $str_002a79e8, 4(%esp)\n" /* line 1546 */
        "movl $cgDC, (%esp)\n"
        "calll Menus_FindByName\n"
        "movl %eax, %ecx\n"
        ".Lf1446ee_00144738:\n"
        "testl %ecx, %ecx\n" /* line 1547 */
        "je .Lf1446ee_0014475d\n"
        "movl cgs, %edx\n" /* line 1550 */
        "movl 8(%ecx), %eax\n"
        "movl %eax, 0xc208(%edx)\n"
        "movl 0xc(%ecx), %eax\n" /* line 1551 */
        "movl %eax, 0xc20c(%edx)\n"
        "movl 4(%ecx), %eax\n" /* line 1552 */
        "movl %eax, 0xc210(%edx)\n"
        /* } scope */
        ".Lf1446ee_0014475d:\n"
        "leave\n" /* line 1554 */
        "retl\n"
        /* { scope 1 */
        ".Lf1446ee_0014475f:\n"
        "movl $str_002a79e0, 4(%esp)\n" /* line 1544 */
        "movl $cgDC, (%esp)\n"
        "calll Menus_FindByName\n"
        "movl %eax, %ecx\n"
        "jmp .Lf1446ee_00144738\n"
    );
}

/* line 1563 */
__attribute__((naked))
void CG_InitVote(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1563 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl $0xf, (%esp)\n" /* line 1565 */
        "calll CL_GetConfigString\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, cgsArray+24712\n"
        "movl cgs, %ebx\n" /* line 1566 */
        "movl $0x11, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x608c(%ebx)\n"
        "movl $0x12, (%esp)\n" /* line 1567 */
        "calll CL_GetConfigString\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x6090(%ebx)\n"
        "movl $0x10, (%esp)\n" /* line 1568 */
        "calll CL_GetConfigString\n"
        "movl $0, 8(%esp)\n"
        "movl $str_002a79f4, 4(%esp)\n" /* "vote string" */
        "movl %eax, (%esp)\n"
        "calll SEH_LocalizeTextMessage\n"
        "movl $0x100, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "addl $0x6094, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll I_strncpyz\n"
        "addl $0x14, %esp\n" /* line 1569 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1578 */
static struct XModel * CG_GetXModel(const char *modelName)
{
    return CL_RegisterModel(modelName);
}

/* line 1590 */
static __attribute__((naked))
void CG_CreateDObj(DObjModel_s *dobjModels, int numModels, struct XAnimTree_s *tree, int handle, clientInfo_t *ci)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1590 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $8, %esp\n"
        "movl 8(%ebp), %edi\n" /* dobjModels */
        "movl 0x10(%ebp), %eax\n" /* tree */
        "movl %eax, -0x10(%ebp)\n" /* tree */
        "movl 0x14(%ebp), %eax\n" /* handle */
        "movl %eax, -0x14(%ebp)\n" /* handle */
        "movl 0x18(%ebp), %esi\n" /* ci */
        "movl 0xc(%ebp), %ebx\n" /* numModels */
        "movl 0x4a8(%esi), %edx\n" /* line 1595 | ci */
        "testl %edx, %edx\n"
        "je .Lf144820_0014488f\n"
        "leal (%edx, %edx, 2), %eax\n" /* line 1600 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl cg_weapons, %edx\n"
        "movl 0xbc(%edx, %eax, 4), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf144820_001448b7\n"
        "movzwl %bx, %eax\n" /* line 1603 | numModels */
        "leal (%eax, %eax, 2), %eax\n"
        "leal (%edi, %eax, 4), %edx\n" /* dobjModels */
        "movl %ecx, (%edx)\n"
        "movl 0x3f4(%esi), %eax\n" /* line 1604 | ci */
        "testl %eax, %eax\n"
        "je .Lf144820_001448ad\n"
        "movl cg_weaponleftbone, %eax\n"
        "movl 8(%eax), %eax\n"
        ".Lf144820_0014487f:\n"
        "movl %eax, 4(%edx)\n"
        "movl $0, 8(%edx)\n" /* line 1605 */
        "addl $1, %ebx\n" /* line 1608 | numModels */
        "movl -0x14(%ebp), %eax\n" /* handle */
        ".Lf144820_0014488f:\n"
        "movl %eax, 0x14(%ebp)\n" /* line 1612 | handle */
        "movl -0x10(%ebp), %eax\n" /* tree */
        "movl %eax, 0x10(%ebp)\n" /* tree */
        "movzwl %bx, %eax\n" /* numModels */
        "movl %eax, 0xc(%ebp)\n" /* numModels */
        "movl %edi, 8(%ebp)\n" /* dobjModels */
        "addl $8, %esp\n" /* line 1613 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp Com_ClientDObjCreate\n" /* line 1612 */
        ".Lf144820_001448ad:\n"
        "movl cg_weaponrightbone, %eax\n" /* line 1604 */
        "movl 8(%eax), %eax\n"
        "jmp .Lf144820_0014487f\n"
        ".Lf144820_001448b7:\n"
        "movl -0x14(%ebp), %eax\n" /* handle */
        "jmp .Lf144820_0014488f\n"
    );
}

/* line 1949 */
__attribute__((naked))
void CG_FreeWeapons(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1949 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl $1, %ebx\n"
        "movl $0x1b4, %esi\n"
        "movl cg_weapons, %edi\n"
        "jmp .Lf1448bc_00144916\n"
        /* { scope 1 */
        ".Lf1448bc_001448d7:\n"
        "movl %ebx, (%esp)\n" /* line 1955 | i */
        "calll CG_WeaponDObjHandle\n"
        "movl %eax, (%esp)\n"
        "calll Com_SafeClientDObjFree\n"
        "movl 0xa4(%edi, %esi), %eax\n" /* line 1956 */
        "testl %eax, %eax\n"
        "je .Lf1448bc_0014490d\n"
        "movl $0, 4(%esp)\n" /* line 1958 */
        "movl %eax, (%esp)\n"
        "calll XAnimFreeTree\n"
        "movl $0, 0xa4(%esi, %edi)\n" /* line 1959 */
        ".Lf1448bc_0014490d:\n"
        "addl $1, %ebx\n" /* line 1953 | i */
        "addl $0x1b4, %esi\n"
        ".Lf1448bc_00144916:\n"
        "calll BG_GetNumWeapons\n"
        "cmpl %eax, %ebx\n" /* i */
        "jle .Lf1448bc_001448d7\n"
        "movl $0x2400, 8(%esp)\n" /* line 1963 */
        "movl $0, 4(%esp)\n"
        "movl cg_items, %eax\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $0xda00, 8(%esp)\n" /* line 1964 */
        "movl $0, 4(%esp)\n"
        "movl cg_weapons, %eax\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1965 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1975 */
__attribute__((naked))
void CG_Shutdown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1975 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl $0, (%esp)\n" /* line 1980 */
        "calll CL_TrackStatistics\n"
        "movl $0, 4(%esp)\n" /* line 1982 */
        "movl $0x3f800000, (%esp)\n"
        "calll SND_FadeAllSounds\n"
        "movb $0, g_ambientStarted\n" /* line 1984 */
        "movb $0, g_mapLoaded\n" /* line 1985 */
        "calll Mantle_ShutdownAnims\n" /* line 1987 */
        "calll CG_FreeWeapons\n" /* line 1989 */
        "calll CG_FreeClientDObjInfo\n" /* line 1991 */
        "calll CG_FreeEntityDObjInfo\n" /* line 1992 */
        "calll CL_FreeWeaponInfoMemory\n" /* line 1993 */
        "calll FX_FreeSystem\n" /* line 1999 */
        "xorl %esi, %esi\n"
        "movl cg, %ebx\n"
        ".Lf144962_001449bf:\n"
        "movl 0xe0db8(%ebx), %eax\n" /* line 1650 */
        "testl %eax, %eax\n"
        "je .Lf144962_001449e3\n"
        "movl $0, 4(%esp)\n" /* line 1652 */
        "movl %eax, (%esp)\n"
        "calll XAnimFreeTree\n"
        "movl $0, 0xe0db8(%ebx)\n" /* line 1653 */
        ".Lf144962_001449e3:\n"
        "addl $1, %esi\n" /* line 1648 */
        "addl $0x4b8, %ebx\n"
        "cmpl $0x40, %esi\n"
        "jne .Lf144962_001449bf\n"
        "xorw %si, %si\n"
        "movl cgs, %edi\n"
        "movl %edi, %ebx\n"
        ".Lf144962_001449fc:\n"
        "movl 0xc6b8(%ebx), %eax\n" /* line 1660 */
        "testl %eax, %eax\n"
        "je .Lf144962_00144a20\n"
        "movl $0, 4(%esp)\n" /* line 1662 */
        "movl %eax, (%esp)\n"
        "calll XAnimFreeTree\n"
        "movl $0, 0xc6b8(%ebx)\n" /* line 1663 */
        ".Lf144962_00144a20:\n"
        "addl $1, %esi\n" /* line 1658 */
        "addl $0x4b8, %ebx\n"
        "cmpl $8, %esi\n"
        "jne .Lf144962_001449fc\n"
        "movl 0x5ea0(%edi), %edx\n" /* line 2003 */
        "testl %edx, %edx\n"
        "jne .Lf144962_00144a3d\n"
        "calll Scr_ShutdownGameStrings\n" /* line 2004 */
        ".Lf144962_00144a3d:\n"
        "movl $0xf399c, 8(%esp)\n" /* line 2006 */
        "movl $0, 4(%esp)\n"
        "movl cg, %eax\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "addl $0x1c, %esp\n" /* line 2012 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
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

/* line 1271 */
__attribute__((naked))
int CG_PlaySoundAliasAsMasterByName(int entitynum, const vec_t *origin, const char *aliasname)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1271 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl 0x10(%ebp), %eax\n" /* line 1279 | aliasname */
        "movl %eax, (%esp)\n"
        "calll CL_PickSoundAlias\n"
        "movl %eax, %ebx\n" /* pAlias */
        "testl %eax, %eax\n" /* line 1281 */
        "je .Lf144a88_00144b4c\n"
        "movl $1, 0x10(%esp)\n" /* line 1283 */
        "movl $0, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* origin */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* entitynum */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* pAlias */
        "calll SND_PlaySoundAliasAsMaster\n"
        "movl %eax, %esi\n" /* msec */
        /* { scope 2 */
        "testl %eax, %eax\n" /* line 1212 */
        "je .Lf144a88_00144b38\n"
        "movl 4(%ebx), %edi\n" /* line 1214 | charWidth */
        "testl %edi, %edi\n"
        "je .Lf144a88_00144b38\n"
        "movl cgs, %eax\n" /* line 1217 */
        "movss 0x5e94(%eax), %xmm0\n"
        "ucomiss lit4_002ed814, %xmm0\n" /* 1.3333333730697632f */
        "jbe .Lf144a88_00144b42\n"
        "movl cg_subtitleWidthWidescreen, %eax\n"
        "movl 8(%eax), %ebx\n" /* charWidth */
        ".Lf144a88_00144af7:\n"
        "movss lit4_002ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "movl cg_subtitleMinTime, %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x1c(%ebp)\n"
        "cvttss2si -0x1c(%ebp), %eax\n"
        "cmpl %esi, %eax\n" /* line 154 */
        "cmovsl %esi, %eax\n"
        "movl %ebx, 8(%esp)\n" /* line 1219 | charWidth */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll CL_SubtitlePrint\n"
        /* } scope */
        /* } scope */
        ".Lf144a88_00144b38:\n"
        "movl %esi, %eax\n" /* line 1287 | msec */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf144a88_00144b42:\n"
        "movl cg_subtitleWidthStandard, %eax\n" /* line 1217 */
        "movl 8(%eax), %ebx\n" /* charWidth */
        "jmp .Lf144a88_00144af7\n"
        /* } scope */
        ".Lf144a88_00144b4c:\n"
        "xorl %esi, %esi\n" /* line 1281 | msec */
        /* } scope */
        "movl %esi, %eax\n" /* line 1287 | msec */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 688 */
__attribute__((naked))
void CG_GetDObjOrientation(int dobjHandle, vec3_t *axis_out)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 688 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edx\n" /* dobjHandle */
        "movl 0xc(%ebp), %esi\n" /* axis_out */
        "cmpl $0x3ff, %edx\n" /* line 692 */
        "jbe .Lf144b58_00144bad\n"
        "leal -0x400(%edx), %eax\n" /* line 699 */
        "cmpl $0x7f, %eax\n"
        "jbe .Lf144b58_00144b7a\n"
        "popl %ebx\n" /* line 708 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf144b58_00144b7a:\n"
        "leal 0x24(%esi), %edx\n" /* line 701 | axis_out, to */
        /* { scope 1 */
        "movl cgArray+180412, %eax\n" /* line 199 */
        "movl %eax, 0x24(%esi)\n"
        "movl cgArray+180416, %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl cgArray+180420, %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl %esi, 0xc(%ebp)\n" /* line 702 | axis_out */
        "movl cg, %eax\n"
        "addl $0x2c0c8, %eax\n"
        "movl %eax, 8(%ebp)\n" /* dobjHandle */
        "popl %ebx\n" /* line 708 */
        "popl %esi\n"
        "popl %ebp\n"
        "jmp AxisCopy\n" /* line 702 */
        /* { scope 1 */
        ".Lf144b58_00144bad:\n"
        "movl %edx, %eax\n" /* line 694 | cent */
        "shll $4, %eax\n" /* cent */
        "addl %edx, %eax\n" /* cent */
        "leal (%edx, %eax, 8), %eax\n" /* cent */
        "movl cg_entities, %edx\n"
        "leal (%edx, %eax, 4), %eax\n" /* cent */
        "leal 0x24(%esi), %ebx\n" /* line 696 | axis_out, to */
        "leal 0x1ec(%eax), %ecx\n" /* from */
        /* { scope 2 */
        "movl 0x1ec(%eax), %edx\n" /* line 199 */
        "movl %edx, 0x24(%esi)\n"
        "movl 4(%ecx), %edx\n" /* line 200 */
        "movl %edx, 4(%ebx)\n"
        "movl 8(%ecx), %edx\n" /* line 201 */
        "movl %edx, 8(%ebx)\n"
        /* } scope */
        "movl %esi, 0xc(%ebp)\n" /* line 697 | axis_out */
        "addl $0x1f8, %eax\n"
        "movl %eax, 8(%ebp)\n" /* dobjHandle */
        /* } scope */
        "popl %ebx\n" /* line 708 */
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp AnglesToAxis\n" /* line 697 */
    );
}

/* line 1461 */
__attribute__((naked))
void CG_PlaySmokeGrenadesAtTime(int gametime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1461 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1: oldestTime, found, gametime */
        "xorl %eax, %eax\n" /* line 191 */
        "movl %eax, -0x24(%ebp)\n" /* up */
        "movl %eax, -0x20(%ebp)\n" /* line 192 */
        "movl $0x3f800000, -0x1c(%ebp)\n" /* line 193 */
        "movl cgsArray+26816, %eax\n" /* line 1471 */
        "testl %eax, %eax\n"
        "je .Lf144bf2_00144e1a\n"
        "movl 8(%ebp), %eax\n" /* line 1474 | gametime */
        "movl %eax, 4(%esp)\n"
        "movl $str_002a7a00, (%esp)\n" /* "Playing smoke grenades at time %i
" */
        "calll Com_Printf\n"
        "movl cgs, %eax\n" /* line 1476 */
        "movl 0x68c0(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FX_GetEffectLength\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm0\n"
        "addss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "cvttss2si %xmm0, %eax\n"
        "movl 8(%ebp), %edx\n" /* gametime */
        "subl %eax, %edx\n"
        "movl %edx, -0x40(%ebp)\n" /* time */
        /* { scope 2: oldestTime, found */
        "movl cg, %eax\n" /* line 1428 */
        "movl 0x24(%eax), %edi\n" /* snap */
        "movl 0x26b4(%edi), %ebx\n" /* line 1429 | snap */
        "testl %ebx, %ebx\n" /* snap */
        "jle .Lf144bf2_00144de1\n"
        "movl $0, -0x3c(%ebp)\n" /* oldestTime */
        "xorl %ecx, %ecx\n"
        "xorl %esi, %esi\n"
        "movb $0, -0x35(%ebp)\n" /* found */
        "leal 0x26bc(%edi), %eax\n" /* snap */
        ".Lf144bf2_00144c84:\n"
        "testb $1, 0xa(%eax)\n" /* line 1432 */
        "je .Lf144bf2_00144cb2\n"
        "movl -0x40(%ebp), %edx\n" /* line 1436 | time */
        "cmpl 0x58(%eax), %edx\n"
        "jg .Lf144bf2_00144cb2\n"
        "movl 0x54(%eax), %edx\n"
        "cmpl %edx, -0x40(%ebp)\n" /* time */
        "jg .Lf144bf2_00144cb2\n"
        "cmpl %edx, 8(%ebp)\n" /* gametime */
        "jl .Lf144bf2_00144cb2\n"
        "cmpl $0, -0x3c(%ebp)\n" /* line 1439 | oldestTime */
        "jne .Lf144bf2_00144e22\n"
        ".Lf144bf2_00144ca9:\n"
        "movl %ecx, %esi\n"
        "movl %edx, -0x3c(%ebp)\n" /* oldestTime */
        "movb $1, -0x35(%ebp)\n" /* found */
        ".Lf144bf2_00144cb2:\n"
        "addl $1, %ecx\n" /* line 1429 */
        "addl $0xf0, %eax\n"
        "cmpl %ecx, %ebx\n" /* snap */
        "jne .Lf144bf2_00144c84\n"
        "cmpb $0, -0x35(%ebp)\n" /* line 1447 | found */
        "je .Lf144bf2_00144de1\n"
        "movl %esi, %eax\n" /* line 1450 */
        "shll $4, %eax\n"
        "shll $8, %esi\n"
        "subl %eax, %esi\n"
        "leal 0x26bc(%esi, %edi), %esi\n"
        /* } scope */
        "testl %esi, %esi\n" /* line 1480 | smokeGrenadeES */
        "je .Lf144bf2_00144de1\n"
        "movl 0x54(%esi), %eax\n" /* line 1485 | smokeGrenadeES */
        "movl %eax, (%esp)\n"
        "calll FX_Rewind\n"
        "movl 8(%ebp), %ebx\n" /* line 1488 | gametime, snap */
        "addl $0x1d4c0, %ebx\n" /* snap */
        "movl %ebx, (%esp)\n" /* snap */
        "calll FX_WarpTime\n"
        "movl %ebx, 4(%esp)\n" /* line 1489 | snap */
        "movl $str_002a7a24, (%esp)\n" /* "Warping FX time to %i to kill off existing effects
" */
        "calll Com_Printf\n"
        ".Lf144bf2_00144d0d:\n"
        "movl 0x54(%esi), %ebx\n" /* line 1493 | smokeGrenadeES, snap */
        "movl %ebx, 4(%esp)\n" /* line 1495 | snap */
        "movl $str_002a7a58, (%esp)\n" /* "Warping FX time to %i
" */
        "calll Com_Printf\n"
        "movl %ebx, (%esp)\n" /* line 1496 | snap */
        "calll FX_WarpTime\n"
        "movl %ebx, 4(%esp)\n" /* line 1501 | snap */
        "movl $str_002a7a70, (%esp)\n" /* "Playing smoke grenade at time %i
" */
        "calll Com_Printf\n"
        "leal -0x24(%ebp), %eax\n" /* line 1502 | up */
        "movl %eax, 8(%esp)\n"
        "leal 0x18(%esi), %eax\n" /* smokeGrenadeES */
        "movl %eax, 4(%esp)\n"
        "movl cgs, %eax\n"
        "movl 0x68c0(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FX_PlayEffect\n"
        "addl $1, %ebx\n" /* line 1504 | snap */
        "movl %ebx, -0x34(%ebp)\n" /* snap, gametime */
        /* { scope 2: oldestTime, found */
        /* { scope 3 */
        "movl cg, %eax\n" /* line 1428 */
        "movl 0x24(%eax), %ebx\n" /* snap */
        "movl 0x26b4(%ebx), %esi\n" /* line 1429 | snap */
        "testl %esi, %esi\n"
        "jle .Lf144bf2_00144dfc\n"
        "movl $0, -0x30(%ebp)\n" /* oldestTime */
        "xorl %ecx, %ecx\n"
        "movb $0, -0x29(%ebp)\n" /* found */
        "xorl %edi, %edi\n" /* snap */
        "leal 0x26bc(%ebx), %eax\n" /* snap */
        ".Lf144bf2_00144d8a:\n"
        "testb $1, 0xa(%eax)\n" /* line 1432 */
        "je .Lf144bf2_00144db4\n"
        "movl -0x34(%ebp), %edx\n" /* line 1436 | gametime */
        "cmpl 0x58(%eax), %edx\n"
        "jg .Lf144bf2_00144db4\n"
        "movl 0x54(%eax), %edx\n"
        "cmpl %edx, -0x34(%ebp)\n" /* gametime */
        "jg .Lf144bf2_00144db4\n"
        "cmpl %edx, 8(%ebp)\n" /* gametime */
        "jl .Lf144bf2_00144db4\n"
        "cmpl $0, -0x30(%ebp)\n" /* line 1439 | oldestTime */
        "je .Lf144bf2_00144e30\n"
        "cmpl %edx, -0x30(%ebp)\n" /* oldestTime */
        "jg .Lf144bf2_00144e30\n"
        ".Lf144bf2_00144db4:\n"
        "addl $1, %ecx\n" /* line 1429 */
        "addl $0xf0, %eax\n"
        "cmpl %esi, %ecx\n"
        "jne .Lf144bf2_00144d8a\n"
        "cmpb $0, -0x29(%ebp)\n" /* line 1447 | found */
        "je .Lf144bf2_00144dfc\n"
        "movl %edi, %eax\n" /* line 1450 | snap */
        "shll $4, %eax\n"
        "shll $8, %edi\n" /* snap */
        "subl %eax, %edi\n" /* snap */
        "leal 0x26bc(%edi, %ebx), %esi\n" /* snap */
        /* } scope */
        /* } scope */
        "testl %esi, %esi\n" /* line 1491 | smokeGrenadeES */
        "jne .Lf144bf2_00144d0d\n"
        "jmp .Lf144bf2_00144dfc\n"
        ".Lf144bf2_00144de1:\n"
        "movl 8(%ebp), %eax\n" /* line 1511 | gametime */
        "movl %eax, (%esp)\n"
        "calll FX_Rewind\n"
        "movl 8(%ebp), %eax\n" /* line 1514 | gametime */
        "addl $0x1d4c0, %eax\n"
        "movl %eax, (%esp)\n"
        "calll FX_WarpTime\n"
        ".Lf144bf2_00144dfc:\n"
        "movl 8(%ebp), %edx\n" /* line 1517 | gametime */
        "movl %edx, 4(%esp)\n"
        "movl $str_002a7a94, (%esp)\n" /* "Done with smoke grenades, now warping FX time to current tim" */
        "calll Com_Printf\n"
        "movl 8(%ebp), %eax\n" /* line 1519 | gametime */
        "movl %eax, (%esp)\n"
        "calll FX_WarpTime\n"
        /* } scope */
        ".Lf144bf2_00144e1a:\n"
        "addl $0x5c, %esp\n" /* line 1520 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: oldestTime, found, gametime */
        /* { scope 2: oldestTime, found */
        ".Lf144bf2_00144e22:\n"
        "cmpl %edx, -0x3c(%ebp)\n" /* line 1439 | oldestTime */
        "jle .Lf144bf2_00144cb2\n"
        "jmp .Lf144bf2_00144ca9\n"
        /* } scope */
        /* { scope 2: oldestTime, found */
        /* { scope 3 */
        ".Lf144bf2_00144e30:\n"
        "movl %ecx, %edi\n" /* snap */
        "movl %edx, -0x30(%ebp)\n" /* oldestTime */
        "movb $1, -0x29(%ebp)\n" /* found */
        "jmp .Lf144bf2_00144db4\n"
    );
}

/* line 1223 */
__attribute__((naked))
int CG_PlaySoundAlias(int entitynum, const vec_t *origin, snd_alias_list_t *aliasList)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1223 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl 0x10(%ebp), %eax\n" /* line 1231 | aliasList */
        "movl %eax, (%esp)\n"
        "calll Com_PickSoundAliasFromList\n"
        "movl %eax, %ebx\n" /* pAlias */
        "testl %eax, %eax\n" /* line 1233 */
        "je .Lf144e3e_00144f02\n"
        "movl $1, 0x10(%esp)\n" /* line 1235 */
        "movl $0, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* origin */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* entitynum */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* pAlias */
        "calll SND_PlaySoundAlias\n"
        "movl %eax, %esi\n" /* msec */
        /* { scope 2 */
        "testl %eax, %eax\n" /* line 1212 */
        "je .Lf144e3e_00144eee\n"
        "movl 4(%ebx), %edi\n" /* line 1214 | charWidth */
        "testl %edi, %edi\n"
        "je .Lf144e3e_00144eee\n"
        "movl cgs, %eax\n" /* line 1217 */
        "movss 0x5e94(%eax), %xmm0\n"
        "ucomiss lit4_002ed814, %xmm0\n" /* 1.3333333730697632f */
        "jbe .Lf144e3e_00144ef8\n"
        "movl cg_subtitleWidthWidescreen, %eax\n"
        "movl 8(%eax), %ebx\n" /* charWidth */
        ".Lf144e3e_00144ead:\n"
        "movss lit4_002ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "movl cg_subtitleMinTime, %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x1c(%ebp)\n"
        "cvttss2si -0x1c(%ebp), %eax\n"
        "cmpl %esi, %eax\n" /* line 154 */
        "cmovsl %esi, %eax\n"
        "movl %ebx, 8(%esp)\n" /* line 1219 | charWidth */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll CL_SubtitlePrint\n"
        /* } scope */
        /* } scope */
        ".Lf144e3e_00144eee:\n"
        "movl %esi, %eax\n" /* line 1239 | msec */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf144e3e_00144ef8:\n"
        "movl cg_subtitleWidthStandard, %eax\n" /* line 1217 */
        "movl 8(%eax), %ebx\n" /* charWidth */
        "jmp .Lf144e3e_00144ead\n"
        /* } scope */
        ".Lf144e3e_00144f02:\n"
        "xorl %esi, %esi\n" /* line 1233 | msec */
        /* } scope */
        "movl %esi, %eax\n" /* line 1239 | msec */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1247 */
__attribute__((naked))
int CG_PlaySoundAliasByName(int entitynum, const vec_t *origin, const char *aliasname)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1247 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl 0x10(%ebp), %eax\n" /* line 1255 | aliasname */
        "movl %eax, (%esp)\n"
        "calll CL_PickSoundAlias\n"
        "movl %eax, %ebx\n" /* pAlias */
        "testl %eax, %eax\n" /* line 1257 */
        "je .Lf144f0e_00144fd2\n"
        "movl $1, 0x10(%esp)\n" /* line 1259 */
        "movl $0, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* origin */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* entitynum */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* pAlias */
        "calll SND_PlaySoundAlias\n"
        "movl %eax, %esi\n" /* msec */
        /* { scope 2 */
        "testl %eax, %eax\n" /* line 1212 */
        "je .Lf144f0e_00144fbe\n"
        "movl 4(%ebx), %edi\n" /* line 1214 | charWidth */
        "testl %edi, %edi\n"
        "je .Lf144f0e_00144fbe\n"
        "movl cgs, %eax\n" /* line 1217 */
        "movss 0x5e94(%eax), %xmm0\n"
        "ucomiss lit4_002ed814, %xmm0\n" /* 1.3333333730697632f */
        "jbe .Lf144f0e_00144fc8\n"
        "movl cg_subtitleWidthWidescreen, %eax\n"
        "movl 8(%eax), %ebx\n" /* charWidth */
        ".Lf144f0e_00144f7d:\n"
        "movss lit4_002ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "movl cg_subtitleMinTime, %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x1c(%ebp)\n"
        "cvttss2si -0x1c(%ebp), %eax\n"
        "cmpl %esi, %eax\n" /* line 154 */
        "cmovsl %esi, %eax\n"
        "movl %ebx, 8(%esp)\n" /* line 1219 | charWidth */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll CL_SubtitlePrint\n"
        /* } scope */
        /* } scope */
        ".Lf144f0e_00144fbe:\n"
        "movl %esi, %eax\n" /* line 1263 | msec */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf144f0e_00144fc8:\n"
        "movl cg_subtitleWidthStandard, %eax\n" /* line 1217 */
        "movl 8(%eax), %ebx\n" /* charWidth */
        "jmp .Lf144f0e_00144f7d\n"
        /* } scope */
        ".Lf144f0e_00144fd2:\n"
        "xorl %esi, %esi\n" /* line 1257 | msec */
        /* } scope */
        "movl %esi, %eax\n" /* line 1263 | msec */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1407 */
__attribute__((naked))
void CG_SafeTranslateHudElemString(int index, char *hudElemString)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1407 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* index */
        "movl 0xc(%ebp), %esi\n" /* hudElemString */
        "testl %eax, %eax\n" /* line 1411 */
        "jne .Lf144fde_00144ff9\n"
        ".Lf144fde_00144ff1:\n"
        "addl $0x2c, %esp\n" /* line 1415 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf144fde_00144ff9:\n"
        "addl $0x51e, %eax\n" /* line 1414 | message */
        "movl %eax, (%esp)\n" /* message */
        "calll CL_GetConfigString\n"
        /* { scope 1: searchPos, stringLen */
        /* { scope 2 */
        "movl $0, 8(%esp)\n" /* line 1385 */
        "movl $str_002a7ad8, 4(%esp)\n" /* "hudelem string" */
        "movl %eax, (%esp)\n"
        "calll SEH_LocalizeTextMessage\n"
        "movl %eax, %edx\n"
        "cld\n" /* line 1386 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %edx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* stringLen */
        "cmpl $0x100, %ecx\n" /* line 1388 */
        "jg .Lf144fde_00144ff1\n"
        "movl %eax, 8(%esp)\n" /* line 1396 */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll memcpy\n"
        "movl -0x20(%ebp), %eax\n" /* line 1397 | stringLen */
        "movb $0, (%esi, %eax)\n"
        "movl $0, -0x1c(%ebp)\n" /* line 1399 | searchPos */
        "leal -0x20(%ebp), %ebx\n" /* stringLen */
        "leal -0x1c(%ebp), %edi\n" /* searchPos */
        ".Lf144fde_00145060:\n"
        "movl %esi, %ecx\n" /* line 1401 */
        "movl %ebx, %edx\n"
        "movl %edi, %eax\n"
        "calll CG_ReplaceDirective\n"
        "testb %al, %al\n"
        "jne .Lf144fde_00145060\n"
        /* } scope */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1415 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1083 */
__attribute__((naked))
int CG_PlayClientSoundAliasByName(const char *aliasname)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1083 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl cgArray+36, %eax\n" /* line 1085 */
        "movl 0xd8(%eax), %edi\n"
        "leal 0x20(%eax), %esi\n" /* valGE */
        "movl 8(%ebp), %eax\n" /* line 1255 | aliasname */
        "movl %eax, (%esp)\n"
        "calll CL_PickSoundAlias\n"
        "movl %eax, %ebx\n" /* charWidth */
        "testl %eax, %eax\n" /* line 1257 */
        "je .Lf145078_00145144\n"
        "movl $1, 0x10(%esp)\n" /* line 1259 */
        "movl $0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* valGE */
        "movl %edi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SND_PlaySoundAlias\n"
        "movl %eax, %esi\n" /* valGE */
        /* { scope 1 */
        /* { scope 2 */
        "testl %eax, %eax\n" /* line 1212 */
        "je .Lf145078_00145130\n"
        "movl 4(%ebx), %edi\n" /* line 1214 | charWidth */
        "testl %edi, %edi\n"
        "je .Lf145078_00145130\n"
        "movl cgs, %eax\n" /* line 1217 */
        "movss 0x5e94(%eax), %xmm0\n"
        "ucomiss lit4_002ed814, %xmm0\n" /* 1.3333333730697632f */
        "jbe .Lf145078_0014513a\n"
        "movl cg_subtitleWidthWidescreen, %eax\n"
        "movl 8(%eax), %ebx\n" /* charWidth */
        ".Lf145078_001450ef:\n"
        "movss lit4_002ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "movl cg_subtitleMinTime, %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x1c(%ebp)\n"
        "cvttss2si -0x1c(%ebp), %eax\n"
        /* { scope 3 */
        "cmpl %esi, %eax\n" /* line 154 */
        "cmovsl %esi, %eax\n"
        /* } scope */
        "movl %ebx, 8(%esp)\n" /* line 1219 | charWidth */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll CL_SubtitlePrint\n"
        /* } scope */
        /* } scope */
        ".Lf145078_00145130:\n"
        "movl %esi, %eax\n" /* line 1086 | valGE */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf145078_0014513a:\n"
        "movl cg_subtitleWidthStandard, %eax\n" /* line 1217 */
        "movl 8(%eax), %ebx\n" /* charWidth */
        "jmp .Lf145078_001450ef\n"
        /* } scope */
        /* } scope */
        ".Lf145078_00145144:\n"
        "xorl %esi, %esi\n" /* line 1257 | valGE */
        "movl %esi, %eax\n" /* line 1086 | valGE */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1072 */
__attribute__((naked))
int CG_PlayClientSoundAlias(snd_alias_list_t *aliasList)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1072 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl cgArray+36, %eax\n" /* line 1074 */
        "movl 0xd8(%eax), %edi\n"
        "leal 0x20(%eax), %esi\n" /* valGE */
        "movl 8(%ebp), %eax\n" /* line 1231 | aliasList */
        "movl %eax, (%esp)\n"
        "calll Com_PickSoundAliasFromList\n"
        "movl %eax, %ebx\n" /* charWidth */
        "testl %eax, %eax\n" /* line 1233 */
        "je .Lf145150_0014521c\n"
        "movl $1, 0x10(%esp)\n" /* line 1235 */
        "movl $0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* valGE */
        "movl %edi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SND_PlaySoundAlias\n"
        "movl %eax, %esi\n" /* valGE */
        /* { scope 1 */
        /* { scope 2 */
        "testl %eax, %eax\n" /* line 1212 */
        "je .Lf145150_00145208\n"
        "movl 4(%ebx), %edi\n" /* line 1214 | charWidth */
        "testl %edi, %edi\n"
        "je .Lf145150_00145208\n"
        "movl cgs, %eax\n" /* line 1217 */
        "movss 0x5e94(%eax), %xmm0\n"
        "ucomiss lit4_002ed814, %xmm0\n" /* 1.3333333730697632f */
        "jbe .Lf145150_00145212\n"
        "movl cg_subtitleWidthWidescreen, %eax\n"
        "movl 8(%eax), %ebx\n" /* charWidth */
        ".Lf145150_001451c7:\n"
        "movss lit4_002ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "movl cg_subtitleMinTime, %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x1c(%ebp)\n"
        "cvttss2si -0x1c(%ebp), %eax\n"
        /* { scope 3 */
        "cmpl %esi, %eax\n" /* line 154 */
        "cmovsl %esi, %eax\n"
        /* } scope */
        "movl %ebx, 8(%esp)\n" /* line 1219 | charWidth */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll CL_SubtitlePrint\n"
        /* } scope */
        /* } scope */
        ".Lf145150_00145208:\n"
        "movl %esi, %eax\n" /* line 1075 | valGE */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf145150_00145212:\n"
        "movl cg_subtitleWidthStandard, %eax\n" /* line 1217 */
        "movl 8(%eax), %ebx\n" /* charWidth */
        "jmp .Lf145150_001451c7\n"
        /* } scope */
        /* } scope */
        ".Lf145150_0014521c:\n"
        "xorl %esi, %esi\n" /* line 1233 | valGE */
        "movl %esi, %eax\n" /* line 1075 | valGE */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1094 */
__attribute__((naked))
int CG_PlayEntitySoundAlias(int entitynum, snd_alias_list_t *aliasList)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1094 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %esi\n" /* entitynum */
        "movl %esi, %eax\n" /* entitynum, aliasList */
        "shll $4, %eax\n" /* aliasList */
        "addl %esi, %eax\n" /* entitynum, aliasList */
        "leal (%esi, %eax, 8), %eax\n" /* entitynum, aliasList */
        "movl cg_entities, %edx\n"
        "leal 0x108(%edx, %eax, 4), %edi\n"
        "movl 0xc(%ebp), %eax\n" /* line 1231 | aliasList */
        "movl %eax, (%esp)\n"
        "calll Com_PickSoundAliasFromList\n"
        "movl %eax, %ebx\n" /* charWidth */
        "testl %eax, %eax\n" /* line 1233 */
        "je .Lf145228_00145300\n"
        "movl $1, 0x10(%esp)\n" /* line 1235 */
        "movl $0, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* entitynum */
        "movl %eax, (%esp)\n"
        "calll SND_PlaySoundAlias\n"
        "movl %eax, %esi\n" /* entitynum */
        /* { scope 1 */
        /* { scope 2 */
        "testl %eax, %eax\n" /* line 1212 */
        "je .Lf145228_001452ec\n"
        "movl 4(%ebx), %edi\n" /* line 1214 | charWidth */
        "testl %edi, %edi\n"
        "je .Lf145228_001452ec\n"
        "movl cgs, %eax\n" /* line 1217 */
        "movss 0x5e94(%eax), %xmm0\n"
        "ucomiss lit4_002ed814, %xmm0\n" /* 1.3333333730697632f */
        "jbe .Lf145228_001452f6\n"
        "movl cg_subtitleWidthWidescreen, %eax\n"
        "movl 8(%eax), %ebx\n" /* charWidth */
        ".Lf145228_001452ab:\n"
        "movss lit4_002ed5c8, %xmm0\n" /* line 428 | 1000.0f */
        "movl cg_subtitleMinTime, %eax\n"
        "mulss 8(%eax), %xmm0\n"
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x1c(%ebp)\n"
        "cvttss2si -0x1c(%ebp), %eax\n"
        /* { scope 3 */
        "cmpl %esi, %eax\n" /* line 154 */
        "cmovsl %esi, %eax\n"
        /* } scope */
        "movl %ebx, 8(%esp)\n" /* line 1219 | charWidth */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll CL_SubtitlePrint\n"
        /* } scope */
        /* } scope */
        ".Lf145228_001452ec:\n"
        "movl %esi, %eax\n" /* line 1099 | entitynum */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf145228_001452f6:\n"
        "movl cg_subtitleWidthStandard, %eax\n" /* line 1217 */
        "movl 8(%eax), %ebx\n" /* charWidth */
        "jmp .Lf145228_001452ab\n"
        /* } scope */
        /* } scope */
        ".Lf145228_00145300:\n"
        "xorl %esi, %esi\n" /* line 1233 | entitynum */
        "movl %esi, %eax\n" /* line 1099 | entitynum */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 792 */
static __attribute__((naked))
void CG_RegisterSounds(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 792 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x11c, %esp\n"
        "movl cgs, %ebx\n" /* line 794 | i */
        "movl $str_002a7ae8, (%esp)\n" /* "player_out_of_ammo" */
        "calll Com_FindSoundAlias\n"
        "movl %eax, 0xbc84(%ebx)\n" /* i */
        "movl $str_002a7afc, (%esp)\n" /* line 796 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, 0xbc88(%ebx)\n" /* i */
        "leal 0xbc90(%ebx), %edi\n" /* line 798 | i, sound */
        "xorl %ebx, %ebx\n" /* i */
        "leal -0x118(%ebp), %esi\n" /* szAliasName */
        /* { scope 1: szAliasName */
        /* { scope 2 */
        ".Lf14530c_00145350:\n"
        "movl %ebx, (%esp)\n" /* line 778 | i */
        "calll Com_SurfaceTypeToName\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002a7b08, 8(%esp)\n" /* "grenade_bounce" */
        "movl $str_00218084, 4(%esp)\n" /* "%s_%s" */
        "movl %esi, (%esp)\n"
        "calll sprintf\n"
        "movl %esi, (%esp)\n" /* line 779 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, (%edi, %ebx, 4)\n"
        "addl $1, %ebx\n" /* line 776 | i */
        "cmpl $0x17, %ebx\n" /* i */
        "jne .Lf14530c_00145350\n"
        /* } scope */
        /* } scope */
        "movl cgs, %edi\n" /* line 799 | sound */
        "addl $0xbcec, %edi\n" /* sound */
        "xorb %bl, %bl\n" /* i */
        /* { scope 1: szAliasName */
        /* { scope 2 */
        ".Lf14530c_00145395:\n"
        "movl %ebx, (%esp)\n" /* line 778 | i */
        "calll Com_SurfaceTypeToName\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002a7b18, 8(%esp)\n" /* "grenade_explode" */
        "movl $str_00218084, 4(%esp)\n" /* "%s_%s" */
        "movl %esi, (%esp)\n"
        "calll sprintf\n"
        "movl %esi, (%esp)\n" /* line 779 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, (%edi, %ebx, 4)\n"
        "addl $1, %ebx\n" /* line 776 | i */
        "cmpl $0x17, %ebx\n" /* i */
        "jne .Lf14530c_00145395\n"
        /* } scope */
        /* } scope */
        "movl cgs, %edi\n" /* line 800 | sound */
        "addl $0xbd48, %edi\n" /* sound */
        "xorb %bl, %bl\n" /* i */
        /* { scope 1: szAliasName */
        /* { scope 2 */
        ".Lf14530c_001453da:\n"
        "movl %ebx, (%esp)\n" /* line 778 | i */
        "calll Com_SurfaceTypeToName\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002a7b28, 8(%esp)\n" /* "rocket_explode" */
        "movl $str_00218084, 4(%esp)\n" /* "%s_%s" */
        "movl %esi, (%esp)\n"
        "calll sprintf\n"
        "movl %esi, (%esp)\n" /* line 779 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, (%edi, %ebx, 4)\n"
        "addl $1, %ebx\n" /* line 776 | i */
        "cmpl $0x17, %ebx\n" /* i */
        "jne .Lf14530c_001453da\n"
        /* } scope */
        /* } scope */
        "movl cgs, %edi\n" /* line 801 | sound */
        "addl $0xbda4, %edi\n" /* sound */
        "xorb %bl, %bl\n" /* i */
        /* { scope 1: szAliasName */
        /* { scope 2 */
        ".Lf14530c_0014541f:\n"
        "movl %ebx, (%esp)\n" /* line 778 | i */
        "calll Com_SurfaceTypeToName\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002a7b38, 8(%esp)\n" /* "bullet_small" */
        "movl $str_00218084, 4(%esp)\n" /* "%s_%s" */
        "movl %esi, (%esp)\n"
        "calll sprintf\n"
        "movl %esi, (%esp)\n" /* line 779 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, (%edi, %ebx, 4)\n"
        "addl $1, %ebx\n" /* line 776 | i */
        "cmpl $0x17, %ebx\n" /* i */
        "jne .Lf14530c_0014541f\n"
        /* } scope */
        /* } scope */
        "movl cgs, %edi\n" /* line 802 | sound */
        "addl $0xbe00, %edi\n" /* sound */
        "xorb %bl, %bl\n" /* i */
        /* { scope 1: szAliasName */
        /* { scope 2 */
        ".Lf14530c_00145464:\n"
        "movl %ebx, (%esp)\n" /* line 778 | i */
        "calll Com_SurfaceTypeToName\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002a7b48, 8(%esp)\n" /* "bulletspray_small" */
        "movl $str_00218084, 4(%esp)\n" /* "%s_%s" */
        "movl %esi, (%esp)\n"
        "calll sprintf\n"
        "movl %esi, (%esp)\n" /* line 779 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, (%edi, %ebx, 4)\n"
        "addl $1, %ebx\n" /* line 776 | i */
        "cmpl $0x17, %ebx\n" /* i */
        "jne .Lf14530c_00145464\n"
        /* } scope */
        /* } scope */
        "movl cgs, %edi\n" /* line 803 | sound */
        "addl $0xbe5c, %edi\n" /* sound */
        "xorb %bl, %bl\n" /* i */
        /* { scope 1: szAliasName */
        /* { scope 2 */
        ".Lf14530c_001454a9:\n"
        "movl %ebx, (%esp)\n" /* line 778 | i */
        "calll Com_SurfaceTypeToName\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002a7b5c, 8(%esp)\n" /* "bullet_large" */
        "movl $str_00218084, 4(%esp)\n" /* "%s_%s" */
        "movl %esi, (%esp)\n"
        "calll sprintf\n"
        "movl %esi, (%esp)\n" /* line 779 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, (%edi, %ebx, 4)\n"
        "addl $1, %ebx\n" /* line 776 | i */
        "cmpl $0x17, %ebx\n" /* i */
        "jne .Lf14530c_001454a9\n"
        /* } scope */
        /* } scope */
        "movl cgs, %edi\n" /* line 804 | sound */
        "addl $0xbeb8, %edi\n" /* sound */
        "xorb %bl, %bl\n" /* i */
        /* { scope 1: szAliasName */
        /* { scope 2 */
        ".Lf14530c_001454ee:\n"
        "movl %ebx, (%esp)\n" /* line 778 | i */
        "calll Com_SurfaceTypeToName\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002a7b6c, 8(%esp)\n" /* "step_run" */
        "movl $str_00218084, 4(%esp)\n" /* "%s_%s" */
        "movl %esi, (%esp)\n"
        "calll sprintf\n"
        "movl %esi, (%esp)\n" /* line 779 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, (%edi, %ebx, 4)\n"
        "addl $1, %ebx\n" /* line 776 | i */
        "cmpl $0x17, %ebx\n" /* i */
        "jne .Lf14530c_001454ee\n"
        /* } scope */
        /* } scope */
        "movl cgs, %edi\n" /* line 805 | sound */
        "addl $0xbf14, %edi\n" /* sound */
        "xorb %bl, %bl\n" /* i */
        /* { scope 1: szAliasName */
        /* { scope 2 */
        ".Lf14530c_00145533:\n"
        "movl %ebx, (%esp)\n" /* line 778 | i */
        "calll Com_SurfaceTypeToName\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002a7b78, 8(%esp)\n" /* "step_run_plr" */
        "movl $str_00218084, 4(%esp)\n" /* "%s_%s" */
        "movl %esi, (%esp)\n"
        "calll sprintf\n"
        "movl %esi, (%esp)\n" /* line 779 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, (%edi, %ebx, 4)\n"
        "addl $1, %ebx\n" /* line 776 | i */
        "cmpl $0x17, %ebx\n" /* i */
        "jne .Lf14530c_00145533\n"
        /* } scope */
        /* } scope */
        "movl cgs, %edi\n" /* line 806 | sound */
        "addl $0xbf70, %edi\n" /* sound */
        "xorb %bl, %bl\n" /* i */
        /* { scope 1: szAliasName */
        /* { scope 2 */
        ".Lf14530c_00145578:\n"
        "movl %ebx, (%esp)\n" /* line 778 | i */
        "calll Com_SurfaceTypeToName\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002a7b88, 8(%esp)\n" /* "step_walk" */
        "movl $str_00218084, 4(%esp)\n" /* "%s_%s" */
        "movl %esi, (%esp)\n"
        "calll sprintf\n"
        "movl %esi, (%esp)\n" /* line 779 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, (%edi, %ebx, 4)\n"
        "addl $1, %ebx\n" /* line 776 | i */
        "cmpl $0x17, %ebx\n" /* i */
        "jne .Lf14530c_00145578\n"
        /* } scope */
        /* } scope */
        "movl cgs, %edi\n" /* line 807 | sound */
        "addl $0xbfcc, %edi\n" /* sound */
        "xorb %bl, %bl\n" /* i */
        /* { scope 1: szAliasName */
        /* { scope 2 */
        ".Lf14530c_001455bd:\n"
        "movl %ebx, (%esp)\n" /* line 778 | i */
        "calll Com_SurfaceTypeToName\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002a7b94, 8(%esp)\n" /* "step_walk_plr" */
        "movl $str_00218084, 4(%esp)\n" /* "%s_%s" */
        "movl %esi, (%esp)\n"
        "calll sprintf\n"
        "movl %esi, (%esp)\n" /* line 779 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, (%edi, %ebx, 4)\n"
        "addl $1, %ebx\n" /* line 776 | i */
        "cmpl $0x17, %ebx\n" /* i */
        "jne .Lf14530c_001455bd\n"
        /* } scope */
        /* } scope */
        "movl cgs, %edi\n" /* line 808 | sound */
        "addl $0xc028, %edi\n" /* sound */
        "xorb %bl, %bl\n" /* i */
        /* { scope 1: szAliasName */
        /* { scope 2 */
        ".Lf14530c_00145602:\n"
        "movl %ebx, (%esp)\n" /* line 778 | i */
        "calll Com_SurfaceTypeToName\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002a7ba4, 8(%esp)\n" /* "step_prone" */
        "movl $str_00218084, 4(%esp)\n" /* "%s_%s" */
        "movl %esi, (%esp)\n"
        "calll sprintf\n"
        "movl %esi, (%esp)\n" /* line 779 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, (%edi, %ebx, 4)\n"
        "addl $1, %ebx\n" /* line 776 | i */
        "cmpl $0x17, %ebx\n" /* i */
        "jne .Lf14530c_00145602\n"
        /* } scope */
        /* } scope */
        "movl cgs, %edi\n" /* line 809 | sound */
        "addl $0xc084, %edi\n" /* sound */
        "xorb %bl, %bl\n" /* i */
        /* { scope 1: szAliasName */
        /* { scope 2 */
        ".Lf14530c_00145647:\n"
        "movl %ebx, (%esp)\n" /* line 778 | i */
        "calll Com_SurfaceTypeToName\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002a7bb0, 8(%esp)\n" /* "step_prone_plr" */
        "movl $str_00218084, 4(%esp)\n" /* "%s_%s" */
        "movl %esi, (%esp)\n"
        "calll sprintf\n"
        "movl %esi, (%esp)\n" /* line 779 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, (%edi, %ebx, 4)\n"
        "addl $1, %ebx\n" /* line 776 | i */
        "cmpl $0x17, %ebx\n" /* i */
        "jne .Lf14530c_00145647\n"
        /* } scope */
        /* } scope */
        "movl cgs, %edi\n" /* line 810 | sound */
        "addl $0xc0e0, %edi\n" /* sound */
        "xorb %bl, %bl\n" /* i */
        /* { scope 1: szAliasName */
        /* { scope 2 */
        ".Lf14530c_0014568c:\n"
        "movl %ebx, (%esp)\n" /* line 778 | i */
        "calll Com_SurfaceTypeToName\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002a7bc0, 8(%esp)\n" /* "land" */
        "movl $str_00218084, 4(%esp)\n" /* "%s_%s" */
        "movl %esi, (%esp)\n"
        "calll sprintf\n"
        "movl %esi, (%esp)\n" /* line 779 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, (%edi, %ebx, 4)\n"
        "addl $1, %ebx\n" /* line 776 | i */
        "cmpl $0x17, %ebx\n" /* i */
        "jne .Lf14530c_0014568c\n"
        /* } scope */
        /* } scope */
        "movl cgs, %edi\n" /* line 811 | sound */
        "addl $0xc13c, %edi\n" /* sound */
        "xorb %bl, %bl\n" /* i */
        /* { scope 1: szAliasName */
        /* { scope 2 */
        ".Lf14530c_001456d1:\n"
        "movl %ebx, (%esp)\n" /* line 778 | i */
        "calll Com_SurfaceTypeToName\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002a7bc8, 8(%esp)\n" /* "land_plr" */
        "movl $str_00218084, 4(%esp)\n" /* "%s_%s" */
        "movl %esi, (%esp)\n"
        "calll sprintf\n"
        "movl %esi, (%esp)\n" /* line 779 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, (%edi, %ebx, 4)\n"
        "addl $1, %ebx\n" /* line 776 | i */
        "cmpl $0x17, %ebx\n" /* i */
        "jne .Lf14530c_001456d1\n"
        /* } scope */
        /* } scope */
        "movl cgs, %ebx\n" /* line 813 | i */
        "movl $str_002a7bd4, (%esp)\n" /* "gear_rattle_run" */
        "calll Com_FindSoundAlias\n"
        "movl %eax, 0xc198(%ebx)\n" /* i */
        "movl $str_002a7be4, (%esp)\n" /* line 814 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, 0xc19c(%ebx)\n" /* i */
        "movl $str_002a7bf8, (%esp)\n" /* line 815 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, 0xc1a0(%ebx)\n" /* i */
        "movl $str_002a7c0c, (%esp)\n" /* line 816 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, 0xc1a4(%ebx)\n" /* i */
        "movl $str_002a7c24, (%esp)\n" /* line 818 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, 0xc1a8(%ebx)\n" /* i */
        "movl $str_002a7c38, (%esp)\n" /* line 819 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, 0xc1ac(%ebx)\n" /* i */
        "movl $str_002a7c40, (%esp)\n" /* line 821 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, 0xc1b0(%ebx)\n" /* i */
        "movl $str_002a7c54, (%esp)\n" /* line 822 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, 0xc1b4(%ebx)\n" /* i */
        "movl $str_002a7c68, (%esp)\n" /* line 823 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, 0xc1b8(%ebx)\n" /* i */
        "movl $str_002a7c74, (%esp)\n" /* line 824 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, 0xc1bc(%ebx)\n" /* i */
        "movl $str_002a7c84, (%esp)\n" /* line 826 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, 0xc1c0(%ebx)\n" /* i */
        "movl $str_002a7c9c, (%esp)\n" /* line 827 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, 0xc1c4(%ebx)\n" /* i */
        "movl $str_002a7cb4, (%esp)\n" /* line 828 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, 0xc1c8(%ebx)\n" /* i */
        "movl $str_002a7ccc, (%esp)\n" /* line 829 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, 0xc1cc(%ebx)\n" /* i */
        "movl $str_002a7ce4, (%esp)\n" /* line 831 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, 0xc1d0(%ebx)\n" /* i */
        "addl $0x11c, %esp\n" /* line 832 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1712 */
__attribute__((naked))
void CG_Init(int serverMessageNum, int serverCommandSequence, int clientNum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1712 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        /* { scope 1 */
        "movl $0xe7d4, 8(%esp)\n" /* line 1720 */
        "movl $0, 4(%esp)\n"
        "movl cgs, %eax\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $0xf399c, 8(%esp)\n" /* line 1721 */
        "movl $0, 4(%esp)\n"
        "movl cg, %eax\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $0x274, 8(%esp)\n" /* line 1722 */
        "movl $0, 4(%esp)\n"
        "movl $cgDC, (%esp)\n"
        "calll memset\n"
        "movl $0x89000, 8(%esp)\n" /* line 1723 */
        "movl $0, 4(%esp)\n"
        "movl cg_entities, %eax\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $0xda00, 8(%esp)\n" /* line 1724 */
        "movl $0, 4(%esp)\n"
        "movl cg_weapons, %eax\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $0x2400, 8(%esp)\n" /* line 1725 */
        "movl $0, 4(%esp)\n"
        "movl cg_items, %eax\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $0x1080, 8(%esp)\n" /* line 392 */
        "movl $1, 4(%esp)\n"
        "movl $str_002a7cf8, (%esp)\n" /* "cg_drawGun" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_drawGun\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 393 */
        "movl $4, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl $str_002a7d04, (%esp)\n" /* "cg_cursorHints" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cg_cursorHints\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 394 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x64, 4(%esp)\n"
        "movl $str_002a7d14, (%esp)\n" /* "cg_hintFadeTime" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cg_hintFadeTime\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 400 */
        "movl $0x43200000, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0x42a00000, 4(%esp)\n"
        "movl $str_002a7d24, (%esp)\n" /* "cg_fov" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_fov\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 401 */
        "movl $0x40000000, %esi\n"
        "movl %esi, 0xc(%esp)\n"
        "movl $0x3e4ccccd, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $str_002a7d2c, (%esp)\n" /* "cg_fovScale" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_fovScale\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 402 */
        "movl $0x43200000, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0x41200000, 4(%esp)\n"
        "movl $str_002a7d38, (%esp)\n" /* "cg_fovMin" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_fovMin\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 404 */
        "movl $0x64, 0xc(%esp)\n"
        "movl $0x1e, 8(%esp)\n"
        "movl $0x64, 4(%esp)\n"
        "movl $str_002a7d44, (%esp)\n" /* "cg_viewsize" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cg_viewsize\n"
        "movl $0x1080, 8(%esp)\n" /* line 405 */
        "movl $1, 4(%esp)\n"
        "movl $str_002a7d50, (%esp)\n" /* "cg_draw2D" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_draw2D\n"
        "movl $0x1080, 8(%esp)\n" /* line 406 */
        "movl $0, 4(%esp)\n"
        "movl $str_002a7d5c, (%esp)\n" /* "cg_drawHealth" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_drawHealth\n"
        "movl $0x1001, 8(%esp)\n" /* line 407 */
        "movl $1, 4(%esp)\n"
        "movl $str_002a7d6c, (%esp)\n" /* "cg_drawBreathHint" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_drawBreathHint\n"
        "movl $0x1001, 8(%esp)\n" /* line 408 */
        "movl $1, 4(%esp)\n"
        "movl $str_002a7d80, (%esp)\n" /* "cg_drawMantleHint" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_drawMantleHint\n"
        "movl $0x1001, 0xc(%esp)\n" /* line 409 */
        "movl $0, 8(%esp)\n"
        "movl $cg_drawFpsNames, 4(%esp)\n"
        "movl $str_002a7d94, (%esp)\n" /* "cg_drawFPS" */
        "calll Dvar_RegisterEnum\n"
        "movl %eax, cg_drawFPS\n"
        "movl $__mh_execute_header, 0xc(%esp)\n" /* line 413 */
        "movl $0, 8(%esp)\n"
        "movl $cg_drawSoundOverlayStrings, 4(%esp)\n"
        "movl $str_002a7da0, (%esp)\n" /* "cg_drawSoundOverlay" */
        "calll Dvar_RegisterEnum\n"
        "movl %eax, cg_drawSoundOverlay\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 414 */
        "movl $0, 4(%esp)\n"
        "movl $str_002a7db4, (%esp)\n" /* "cg_drawScriptUsage" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_drawScriptUsage\n"
        "movl $0x1080, 8(%esp)\n" /* line 415 */
        "movl $0, 4(%esp)\n"
        "movl $str_002a7dc8, (%esp)\n" /* "cg_drawMaterial" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_drawMaterial\n"
        "movl $0x1001, 8(%esp)\n" /* line 416 */
        "movl $0, 4(%esp)\n"
        "movl $str_002a7dd8, (%esp)\n" /* "cg_drawSnapshot" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_drawSnapshot\n"
        "movl $0x1001, 8(%esp)\n" /* line 417 */
        "movl $1, 4(%esp)\n"
        "movl $str_002a7de8, (%esp)\n" /* "cg_drawTurretCrosshair" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_drawTurretCrosshair\n"
        "movl $0x1001, 8(%esp)\n" /* line 418 */
        "movl $1, 4(%esp)\n"
        "movl $str_002a7e00, (%esp)\n" /* "cg_drawCrosshairNames" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_drawCrosshairNames\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 419 */
        "movl $0x280, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x12c, 4(%esp)\n"
        "movl $str_002a7e18, (%esp)\n" /* "cg_drawCrosshairNamesPosX" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cg_drawCrosshairNamesPosX\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 420 */
        "movl $0x1e0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0xb4, 4(%esp)\n"
        "movl $str_002a7e34, (%esp)\n" /* "cg_drawCrosshairNamesPosY" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cg_drawCrosshairNamesPosY\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 425 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "xorl %ebx, %ebx\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $str_002a7e50, (%esp)\n" /* "cg_hudCompassSize" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_hudCompassSize\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 428 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x44bb8000, 4(%esp)\n"
        "movl $str_002a7e64, (%esp)\n" /* "cg_hudCompassMaxRange" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_hudCompassMaxRange\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 429 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_002a7e7c, (%esp)\n" /* "cg_hudCompassMinRange" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_hudCompassMinRange\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 430 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_002a7e94, (%esp)\n" /* "cg_hudCompassMinRadius" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_hudCompassMinRadius\n"
        "movl $0x1001, 8(%esp)\n" /* line 431 */
        "movl $0, 4(%esp)\n"
        "movl $str_002a7eac, (%esp)\n" /* "cg_hudCompassSpringyPointers" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_hudCompassSpringyPointers\n"
        "movl $0x1081, 0x10(%esp)\n" /* line 432 */
        "movl $0x41200000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl $str_002a7ecc, (%esp)\n" /* "cg_hudCompassSoundPingFadeTime" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_hudCompassSoundPingFadeTime\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 433 */
        "movl %ebx, 0xc(%esp)\n"
        "movl $0xff7fffff, 8(%esp)\n"
        "movl $0xc28c0000, 4(%esp)\n"
        "movl $str_002a7eec, (%esp)\n" /* "cg_hudObjectiveMinHeight" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_hudObjectiveMinHeight\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 437 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x45000000, 4(%esp)\n"
        "movl $str_002a7f08, (%esp)\n" /* "cg_hudObjectiveMaxRange" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_hudObjectiveMaxRange\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 438 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $str_002a7f20, (%esp)\n" /* "cg_hudObjectiveMinAlpha" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_hudObjectiveMinAlpha\n"
        "movl $__mh_execute_header, 0x14(%esp)\n" /* line 439 */
        "movl $0x3f800000, 0x10(%esp)\n"
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $str_002a7f38, (%esp)\n" /* "cg_hudStanceFlash" */
        "calll Dvar_RegisterColor\n"
        "movl %eax, cg_hudStanceFlash\n"
        "movl $0x1001, 8(%esp)\n" /* line 440 */
        "movl $0, 4(%esp)\n"
        "movl $str_002a7f4c, (%esp)\n" /* "cg_hudStanceHintPrints" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_hudStanceHintPrints\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 441 */
        "movl $0x44000000, %esi\n"
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x43000000, %edi\n"
        "movl %edi, 4(%esp)\n"
        "movl $str_002a7f64, (%esp)\n" /* "cg_hudDamageIconWidth" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_hudDamageIconWidth\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 442 */
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x42800000, 4(%esp)\n"
        "movl $str_002a7f7c, (%esp)\n" /* "cg_hudDamageIconHeight" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_hudDamageIconHeight\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 443 */
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $str_002a7f94, (%esp)\n" /* "cg_hudDamageIconOffset" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_hudDamageIconOffset\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 444 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x7d0, 4(%esp)\n"
        "movl $str_002a7fac, (%esp)\n" /* "cg_hudDamageIconTime" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cg_hudDamageIconTime\n"
        "movl $0x1080, 8(%esp)\n" /* line 445 */
        "movl $0, 4(%esp)\n"
        "movl $str_002a7fc4, (%esp)\n" /* "cg_hudDamageIconInScope" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_hudDamageIconInScope\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 446 */
        "movl $0x447a0000, %edi\n"
        "movl %edi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x437a0000, 4(%esp)\n"
        "movl $str_002a7fdc, (%esp)\n" /* "cg_hudGrenadeIconMaxRange" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_hudGrenadeIconMaxRange\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 447 */
        "movl %edi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x42d00000, 4(%esp)\n"
        "movl $str_002a7ff8, (%esp)\n" /* "cg_hudGrenadeIconMaxHeight" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_hudGrenadeIconMaxHeight\n"
        "movl $0x1080, 8(%esp)\n" /* line 448 */
        "movl $0, 4(%esp)\n"
        "movl $str_002a8014, (%esp)\n" /* "cg_hudGrenadeIconInScope" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_hudGrenadeIconInScope\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 449 */
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x42480000, 4(%esp)\n"
        "movl $str_002a8030, (%esp)\n" /* "cg_hudGrenadeIconOffset" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_hudGrenadeIconOffset\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 450 */
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x41c80000, %edi\n"
        "movl %edi, 4(%esp)\n"
        "movl $str_002a8048, (%esp)\n" /* "cg_hudGrenadeIconHeight" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_hudGrenadeIconHeight\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 451 */
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $str_002a8060, (%esp)\n" /* "cg_hudGrenadeIconWidth" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_hudGrenadeIconWidth\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 452 */
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x41400000, 4(%esp)\n"
        "movl $str_002a8078, (%esp)\n" /* "cg_hudGrenadePointerHeight" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_hudGrenadePointerHeight\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 453 */
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $str_002a8094, (%esp)\n" /* "cg_hudGrenadePointerWidth" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_hudGrenadePointerWidth\n"
        "movl $0x1001, 0x14(%esp)\n" /* line 454 */
        "movl %esi, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n"
        "movl $0x41d80000, 8(%esp)\n"
        "movl $0x41400000, 4(%esp)\n"
        "movl $str_002a80b0, (%esp)\n" /* "cg_hudGrenadePointerPivot" */
        "calll Dvar_RegisterVec2\n"
        "movl %eax, cg_hudGrenadePointerPivot\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 455 */
        "movl $0x42480000, 0xc(%esp)\n"
        "movl $0x3dcccccd, 8(%esp)\n"
        "movl $0x3fd9999a, 4(%esp)\n"
        "movl $str_002a80cc, (%esp)\n" /* "cg_hudGrenadePointerPulseFreq" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_hudGrenadePointerPulseFreq\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 456 */
        "movl $0x40400000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3feccccd, 4(%esp)\n"
        "movl $str_002a80ec, (%esp)\n" /* "cg_hudGrenadePointerPulseMax" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_hudGrenadePointerPulseMax\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 457 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl $0xc0400000, 8(%esp)\n"
        "movl $0x3e99999a, 4(%esp)\n"
        "movl $str_002a810c, (%esp)\n" /* "cg_hudGrenadePointerPulseMin" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_hudGrenadePointerPulseMin\n"
        "movl $0x1001, 0x14(%esp)\n" /* line 458 */
        "movl $0x44200000, %esi\n"
        "movl %esi, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n"
        "movl $0x43160000, 8(%esp)\n"
        "movl $0x40a00000, 4(%esp)\n"
        "movl $str_002a812c, (%esp)\n" /* "cg_hudChatPosition" */
        "calll Dvar_RegisterVec2\n"
        "movl %eax, cg_hudChatPosition\n"
        "movl $0x1001, 0x14(%esp)\n" /* line 459 */
        "movl %esi, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n"
        "movl $0x42fc0000, 8(%esp)\n"
        "movl $0x40a00000, 4(%esp)\n"
        "movl $str_002a8140, (%esp)\n" /* "cg_hudSayPosition" */
        "calll Dvar_RegisterVec2\n"
        "movl %eax, cg_hudSayPosition\n"
        "movl $0x1001, 8(%esp)\n" /* line 460 */
        "movl $0, 4(%esp)\n"
        "movl $str_002a8154, (%esp)\n" /* "cg_drawLagometer" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_drawLagometer\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 465 */
        "movl $0x461c4000, %esi\n"
        "movl %esi, 0xc(%esp)\n"
        "movl $0xc61c4000, %edi\n"
        "movl %edi, 8(%esp)\n"
        "movl $0xc2700000, 4(%esp)\n"
        "movl $str_002a8168, (%esp)\n" /* "cg_centerPrintY" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_centerPrintY\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 468 */
        "movl %esi, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0xc3200000, 4(%esp)\n"
        "movl $str_002a8178, (%esp)\n" /* "cg_hudProneY" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_hudProneY\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 493 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002a8188, (%esp)\n" /* "cg_weaponCycleDelay" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cg_weaponCycleDelay\n"
        "movl $0x1081, 0x10(%esp)\n" /* line 494 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $str_002a819c, (%esp)\n" /* "cg_crosshairAlpha" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_crosshairAlpha\n"
        "movl $0x1081, 0x10(%esp)\n" /* line 495 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_002a81b0, (%esp)\n" /* "cg_crosshairAlphaMin" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_crosshairAlphaMin\n"
        "movl $0x1081, 8(%esp)\n" /* line 496 */
        "movl $0, 4(%esp)\n"
        "movl $str_002a81c8, (%esp)\n" /* "cg_crosshairDynamic" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_crosshairDynamic\n"
        "movl $0x1081, 8(%esp)\n" /* line 497 */
        "movl $1, 4(%esp)\n"
        "movl $str_002a81dc, (%esp)\n" /* "cg_crosshairEnemyColor" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_crosshairEnemyColor\n"
        "movl $0x1001, 8(%esp)\n" /* line 498 */
        "movl $1, 4(%esp)\n"
        "movl $str_002a81f4, (%esp)\n" /* "cg_brass" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_brass\n"
        "movl $0x1001, 8(%esp)\n" /* line 499 */
        "movl $1, 4(%esp)\n"
        "movl $str_002a8200, (%esp)\n" /* "cg_marks" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_marks\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 500 */
        "movl $0x400, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x400, 4(%esp)\n"
        "movl $str_002a820c, (%esp)\n" /* "cg_marksLimit" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cg_marksLimit\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 502 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl $0xff7fffff, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_002a821c, (%esp)\n" /* "cg_gun_x" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_gun_x\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 503 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl $0xff7fffff, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_002a8228, (%esp)\n" /* "cg_gun_y" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_gun_y\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 504 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl $0xff7fffff, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_002a8234, (%esp)\n" /* "cg_gun_z" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_gun_z\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 505 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl $0xff7fffff, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_002a8240, (%esp)\n" /* "cg_gun_move_f" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_gun_move_f\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 506 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl $0xff7fffff, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_002a8250, (%esp)\n" /* "cg_gun_move_r" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_gun_move_r\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 507 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl $0xff7fffff, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_002a8260, (%esp)\n" /* "cg_gun_move_u" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_gun_move_u\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 508 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl $0xff7fffff, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_002a8270, (%esp)\n" /* "cg_gun_ofs_f" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_gun_ofs_f\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 509 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl $0xff7fffff, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_002a8280, (%esp)\n" /* "cg_gun_ofs_r" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_gun_ofs_r\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 510 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl $0xff7fffff, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_002a8290, (%esp)\n" /* "cg_gun_ofs_u" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_gun_ofs_u\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 511 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl $0xff7fffff, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_002a82a0, (%esp)\n" /* "cg_gun_move_rate" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_gun_move_rate\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 512 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl $0xff7fffff, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_002a82b4, (%esp)\n" /* "cg_gun_move_minspeed" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_gun_move_minspeed\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 513 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x40a00000, 4(%esp)\n"
        "movl $str_002a82cc, (%esp)\n" /* "cg_centertime" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_centertime\n"
        "movl $0x1080, 8(%esp)\n" /* line 515 */
        "movl $0, 4(%esp)\n"
        "movl $str_002a82dc, (%esp)\n" /* "cg_debugposition" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_debugPosition\n"
        "movl $0x1080, 8(%esp)\n" /* line 516 */
        "movl $0, 4(%esp)\n"
        "movl $str_002a82f0, (%esp)\n" /* "cg_debugevents" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_debugEvents\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 517 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x42c80000, 4(%esp)\n"
        "movl $str_002a8300, (%esp)\n" /* "cg_errordecay" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_errorDecay\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 518 */
        "movl $0, 4(%esp)\n"
        "movl $str_002a8310, (%esp)\n" /* "cg_nopredict" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_nopredict\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 520 */
        "movl $2, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002a8320, (%esp)\n" /* "cg_showmiss" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cg_showmiss\n"
        "movl $0x1080, 8(%esp)\n" /* line 521 */
        "movl $1, 4(%esp)\n"
        "movl $str_002a832c, (%esp)\n" /* "cg_footsteps" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_footsteps\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 522 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3ecccccd, %esi\n"
        "movl %esi, 4(%esp)\n"
        "movl $str_002a833c, (%esp)\n" /* "cg_tracerchance" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_tracerChance\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 523 */
        "movl $0x41000000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3f4ccccd, 4(%esp)\n"
        "movl $str_002a834c, (%esp)\n" /* "cg_tracerwidth" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_tracerWidth\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 524 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x458ca000, 4(%esp)\n"
        "movl $str_002a835c, (%esp)\n" /* "cg_tracerSpeed" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_tracerSpeed\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 525 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x43200000, 4(%esp)\n"
        "movl $str_002a836c, (%esp)\n" /* "cg_tracerlength" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_tracerLength\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 526 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0x42480000, 4(%esp)\n"
        "movl $str_002a837c, (%esp)\n" /* "cg_tracerScale" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_tracerScale\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 527 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x459c4000, 4(%esp)\n"
        "movl $str_002a838c, (%esp)\n" /* "cg_tracerScaleMinDist" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_tracerScaleMinDist\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 528 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x46c35000, 4(%esp)\n"
        "movl $str_002a83a4, (%esp)\n" /* "cg_tracerScaleDistRange" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_tracerScaleDistRange\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 529 */
        "movl $0x44800000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x42f00000, 4(%esp)\n"
        "movl $str_002a83bc, (%esp)\n" /* "cg_thirdPersonRange" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_thirdPersonRange\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 530 */
        "movl $0x43b40000, 0xc(%esp)\n"
        "movl $0xc3340000, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_002a83d0, (%esp)\n" /* "cg_thirdPersonAngle" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_thirdPersonAngle\n"
        "movl $0x1080, 8(%esp)\n" /* line 531 */
        "movl $0, 4(%esp)\n"
        "movl $str_002a83e4, (%esp)\n" /* "cg_thirdPerson" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_thirdPerson\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 532 */
        "movl $0xea60, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x2ee0, 4(%esp)\n"
        "movl $str_002a83f4, (%esp)\n" /* "cg_chatTime" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cg_chatTime\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 533 */
        "movl $8, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $8, 4(%esp)\n"
        "movl $str_002a8400, (%esp)\n" /* "cg_chatHeight" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cg_chatHeight\n"
        "movl $0x1003, 8(%esp)\n" /* line 534 */
        "movl $1, 4(%esp)\n"
        "movl $str_002a8410, (%esp)\n" /* "cg_predictItems" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_predictItems\n"
        "movl $0x1001, 8(%esp)\n" /* line 536 */
        "movl $0, 4(%esp)\n"
        "movl $str_002a8420, (%esp)\n" /* "cg_noTaunt" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_noTaunt\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 537 */
        "movl $0xea60, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x1770, 4(%esp)\n"
        "movl $str_002a842c, (%esp)\n" /* "cg_voiceSpriteTime" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cg_voiceSpriteTime\n"
        "movl $0x1001, 8(%esp)\n" /* line 539 */
        "movl $0, 4(%esp)\n"
        "movl $str_002a8440, (%esp)\n" /* "cg_teamChatsOnly" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_teamChatsOnly\n"
        "movl $0x1040, 0x10(%esp)\n" /* line 544 */
        "movl $2, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_0021663c, (%esp)\n" /* "cl_paused" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cg_paused\n"
        "movl $0x1008, 8(%esp)\n" /* line 546 */
        "movl $0, 4(%esp)\n"
        "movl $str_002a8454, (%esp)\n" /* "g_synchronousClients" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_synchronousClients\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 554 */
        "movl $0x3ff, 0xc(%esp)\n"
        "movl $0xffffffff, 8(%esp)\n"
        "movl $0xffffffff, 4(%esp)\n"
        "movl $str_002a846c, (%esp)\n" /* "cg_dumpAnims" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cg_dumpAnims\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 556 */
        "movl $2, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002167f8, (%esp)\n" /* "developer" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cg_developer\n"
        "movl $0x1001, 8(%esp)\n" /* line 557 */
        "movl $0, 4(%esp)\n"
        "movl $str_002a847c, (%esp)\n" /* "con_minicon" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_minicon\n"
        "movl $0x1001, 8(%esp)\n" /* line 559 */
        "movl $1, 4(%esp)\n"
        "movl $str_002a8488, (%esp)\n" /* "cg_subtitles" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_subtitles\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 560 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x40400000, 4(%esp)\n"
        "movl $str_002a8498, (%esp)\n" /* "cg_subtitleMinTime" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_subtitleMinTime\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 562 */
        "movl $0x100, 0xc(%esp)\n"
        "movl $0x14, 8(%esp)\n"
        "movl $0x50, 4(%esp)\n"
        "movl $str_002a84ac, (%esp)\n" /* "cg_subtitleWidthStandard" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cg_subtitleWidthStandard\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 563 */
        "movl $0x100, 0xc(%esp)\n"
        "movl $0x14, 8(%esp)\n"
        "movl $0x50, 4(%esp)\n"
        "movl $str_002a84c8, (%esp)\n" /* "cg_subtitleWidthWidescreen" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cg_subtitleWidthWidescreen\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 564 */
        "movl $0x280, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x78, 4(%esp)\n"
        "movl $str_002a84e4, (%esp)\n" /* "cg_subtitlePosX" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cg_subtitlePosX\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 565 */
        "movl $0x1e0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x190, 4(%esp)\n"
        "movl $str_002a84f4, (%esp)\n" /* "cg_subtitlePosY" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cg_subtitlePosY\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 566 */
        "movl $0x1e0, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0xc, 4(%esp)\n"
        "movl $str_002a8504, (%esp)\n" /* "cg_subtitleCharHeight" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cg_subtitleCharHeight\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 576 */
        "movl $0x100, 0xc(%esp)\n"
        "movl $0x14, 8(%esp)\n"
        "movl $0x46, 4(%esp)\n"
        "movl $str_002a851c, (%esp)\n" /* "cg_gameMessageWidth" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cg_gameMessageWidth\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 577 */
        "movl $0x100, 0xc(%esp)\n"
        "movl $0x14, 8(%esp)\n"
        "movl $0x3c, 4(%esp)\n"
        "movl $str_002a8530, (%esp)\n" /* "cg_gameBoldMessageWidth" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cg_gameBoldMessageWidth\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 578 */
        "movl $1, 4(%esp)\n"
        "movl $str_002a8548, (%esp)\n" /* "cg_drawGameMessages" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_drawGameMessages\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 580 */
        "movl $8, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl $str_002a855c, (%esp)\n" /* "cg_scoreboardScrollStep" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cg_scoreboardScrollStep\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 581 */
        "movl $0x64, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0x18, 4(%esp)\n"
        "movl $str_002a8574, (%esp)\n" /* "cg_scoreboardBannerHeight" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cg_scoreboardBannerHeight\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 582 */
        "movl $0x64, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0x12, 4(%esp)\n"
        "movl $str_002a8590, (%esp)\n" /* "cg_scoreboardItemHeight" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cg_scoreboardItemHeight\n"
        "movl $0x1001, 8(%esp)\n" /* line 584 */
        "movl $1, 4(%esp)\n"
        "movl $str_002a85a8, (%esp)\n" /* "cg_descriptiveText" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_descriptiveText\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 586 */
        "movl $0x41200000, 0xc(%esp)\n"
        "movl $0x3a83126f, %edi\n"
        "movl %edi, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl $str_002a85bc, (%esp)\n" /* "cg_shock_screenBlendTime" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_shock_screenBlendTime\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 587 */
        "movl $0x41200000, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $str_002a85d8, (%esp)\n" /* "cg_shock_screenBlendFadeTime" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_shock_screenBlendFadeTime\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 588 */
        "movl $0x41200000, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x3f400000, 4(%esp)\n"
        "movl $str_002a85f8, (%esp)\n" /* "cg_shock_viewKickPeriod" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_shock_viewKickPeriod\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 589 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3d4ccccd, 4(%esp)\n"
        "movl $str_002a8610, (%esp)\n" /* "cg_shock_viewKickRadius" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_shock_viewKickRadius\n"
        "movl $0x1080, 8(%esp)\n" /* line 590 */
        "movl $1, 4(%esp)\n"
        "movl $str_002a8628, (%esp)\n" /* "cg_shock_sound" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_shock_sound\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 591 */
        "movl $0x41200000, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x3e800000, 4(%esp)\n"
        "movl $str_002a8638, (%esp)\n" /* "cg_shock_soundFadeInTime" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_shock_soundFadeInTime\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 592 */
        "movl $0x41200000, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x40200000, 4(%esp)\n"
        "movl $str_002a8654, (%esp)\n" /* "cg_shock_soundFadeOutTime" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_shock_soundFadeOutTime\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 593 */
        "movl $0x41200000, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x3fc00000, 4(%esp)\n"
        "movl $str_002a8670, (%esp)\n" /* "cg_shock_soundLoopFadeTime" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_shock_soundLoopFadeTime\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 594 */
        "movl $0x41200000, 0xc(%esp)\n"
        "movl $0xc1200000, %esi\n"
        "movl %esi, 8(%esp)\n"
        "movl $0xc0400000, 4(%esp)\n"
        "movl $str_002a868c, (%esp)\n" /* "cg_shock_soundLoopEndDelay" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_shock_soundLoopEndDelay\n"
        "movl $0x1080, 0xc(%esp)\n" /* line 595 */
        "movl $0, 8(%esp)\n"
        "movl $cg_soundRoomTypes, 4(%esp)\n"
        "movl $str_002a86a8, (%esp)\n" /* "cg_shock_soundRoomType" */
        "calll Dvar_RegisterEnum\n"
        "movl %eax, cg_shock_soundRoomType\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 596 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $str_002a86c0, (%esp)\n" /* "cg_shock_soundDryLevel" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_shock_soundDryLevel\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 597 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3f000000, 4(%esp)\n"
        "movl $str_002a86d8, (%esp)\n" /* "cg_shock_soundWetLevel" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_shock_soundWetLevel\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 598 */
        "movl $0x41200000, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl $0x40000000, 4(%esp)\n"
        "movl $str_002a86f0, (%esp)\n" /* "cg_shock_soundModEndDelay" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_shock_soundModEndDelay\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 599 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3dcccccd, %esi\n"
        "movl %esi, 4(%esp)\n"
        "movl $str_002a870c, (%esp)\n" /* "cg_shock_volume_auto" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_shock_volume_auto\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 600 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl $str_002a8724, (%esp)\n" /* "cg_shock_volume_auto2d" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_shock_volume_auto2d\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 601 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $str_002a873c, (%esp)\n" /* "cg_shock_volume_menu" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_shock_volume_menu\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 602 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3f000000, 4(%esp)\n"
        "movl $str_002a8754, (%esp)\n" /* "cg_shock_volume_weapon" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_shock_volume_weapon\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 603 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3e4ccccd, 4(%esp)\n"
        "movl $str_002a876c, (%esp)\n" /* "cg_shock_volume_voice" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_shock_volume_voice\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 604 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl $str_002a8784, (%esp)\n" /* "cg_shock_volume_item" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_shock_volume_item\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 605 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl $str_002a879c, (%esp)\n" /* "cg_shock_volume_body" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_shock_volume_body\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 606 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $str_002a87b4, (%esp)\n" /* "cg_shock_volume_local" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_shock_volume_local\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 607 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $str_002a87cc, (%esp)\n" /* "cg_shock_volume_music" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_shock_volume_music\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 608 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $str_002a87e4, (%esp)\n" /* "cg_shock_volume_announcer" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_shock_volume_announcer\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 609 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $str_002a8800, (%esp)\n" /* "cg_shock_volume_shellshock" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_shock_volume_shellshock\n"
        "movl $0x1080, 8(%esp)\n" /* line 610 */
        "movl $1, 4(%esp)\n"
        "movl $str_002a881c, (%esp)\n" /* "cg_shock_mouse" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_shock_mouse\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 611 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x42b40000, %esi\n"
        "movl %esi, 4(%esp)\n"
        "movl $str_002a882c, (%esp)\n" /* "cg_shock_mouse_maxpitchspeed" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_shock_mouse_maxpitchspeed\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 612 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl $str_002a884c, (%esp)\n" /* "cg_shock_mouse_maxyawspeed" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_shock_mouse_maxyawspeed\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 613 */
        "movl $0x40000000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3f000000, 4(%esp)\n"
        "movl $str_002a8868, (%esp)\n" /* "cg_shock_mouse_sensitivityscale" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_shock_mouse_sensitivityscale\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 614 */
        "movl $0x41200000, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x40000000, 4(%esp)\n"
        "movl $str_002a8888, (%esp)\n" /* "cg_shock_mouse_fadeTime" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_shock_mouse_fadeTime\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 616 */
        "movl $0x42c80000, %esi\n"
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x40c00000, 4(%esp)\n"
        "movl $str_002a88a0, (%esp)\n" /* "cg_youInKillCamSize" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_youInKillCamSize\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 617 */
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_002a88b4, (%esp)\n" /* "cg_scriptIconSize" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_scriptIconSize\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 618 */
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_002a88c8, (%esp)\n" /* "cg_connectionIconSize" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_connectionIconSize\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 619 */
        "movl %esi, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_002a88e0, (%esp)\n" /* "cg_voiceIconSize" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_voiceIconSize\n"
        "movl $0x1080, 8(%esp)\n" /* line 620 */
        "movl $0, 4(%esp)\n"
        "movl $str_002a88f4, (%esp)\n" /* "cg_constantSizeHeadIcons" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_constantSizeHeadIcons\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 621 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0x3ca3d70a, 4(%esp)\n"
        "movl $str_002a8910, (%esp)\n" /* "cg_headIconMinScreenRadius" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, cg_headIconMinScreenRadius\n"
        "movl $0x1001, 8(%esp)\n" /* line 623 */
        "movl $1, 4(%esp)\n"
        "movl $str_002a892c, (%esp)\n" /* "cg_blood" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, cg_blood\n"
        "movl imp_legacyHacks, %ebx\n" /* line 625 */
        "movl (%ebx), %eax\n"
        "movb $0, 0x5c(%eax)\n"
        "movl (%ebx), %eax\n" /* line 626 */
        "movb $0, 0x9c(%eax)\n"
        "movl (%ebx), %eax\n" /* line 627 */
        "movb $0, 0xdc(%eax)\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 628 */
        "movl $str_002a8938, 4(%esp)\n" /* "tag_weapon_left" */
        "movl $str_002a8948, (%esp)\n" /* "cg_weaponleftbone" */
        "calll Dvar_RegisterString\n"
        "movl %eax, cg_weaponleftbone\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 629 */
        "movl $str_002a895c, 4(%esp)\n" /* "tag_weapon_right" */
        "movl $str_002a8970, (%esp)\n" /* "cg_weaponrightbone" */
        "calll Dvar_RegisterString\n"
        "movl %eax, cg_weaponrightbone\n"
        "movl imp_com_sv_running, %edx\n" /* line 632 */
        "movl (%edx), %eax\n"
        "movzbl 8(%eax), %eax\n"
        "movl cgs, %ecx\n"
        "movl %eax, 0x5ea0(%ecx)\n"
        "movl (%ebx), %eax\n" /* line 635 */
        "movl $0, 8(%eax)\n"
        "movl $0, (%esp)\n" /* line 638 */
        "calll CL_SetADS\n"
        "movl cg, %eax\n" /* line 641 */
        "movb $0, 0x2a9fc(%eax)\n"
        "calll CG_OffhandRegisterDvars\n" /* line 643 */
        "calll BG_RegisterDvars\n" /* line 644 */
        "movl imp___Z18Com_FindSoundAliasPKc, %eax\n" /* line 1730 */
        "movl cg, %edx\n"
        "movl %eax, 0xe08d8(%edx)\n"
        "movl $CG_PlayEntitySoundAlias, 0xe08dc(%edx)\n" /* line 1731 */
        "movl $CG_GetXModel, 0xe0904(%edx)\n" /* line 1733 */
        "movl $CG_CreateDObj, 0xe0908(%edx)\n" /* line 1734 */
        "movl imp___Z22Com_SafeClientDObjFreei, %eax\n" /* line 1735 */
        "movl %eax, 0xe090c(%edx)\n"
        "movl $Hunk_AllocXAnimClient, 0xe0910(%edx)\n" /* line 1736 */
        "movl $0, 0xe0900(%edx)\n" /* line 1737 */
        "movl 0x10(%ebp), %eax\n" /* line 1739 | clientNum */
        "movl %eax, 4(%edx)\n"
        "movl $1, 0x2bdc8(%edx)\n" /* line 1740 */
        "movl $1, 0x2be00(%edx)\n" /* line 1742 */
        "movl 8(%ebp), %eax\n" /* line 1743 | serverMessageNum */
        "movl cgs, %ecx\n"
        "movl %eax, 0x5e9c(%ecx)\n"
        "movl 0xc(%ebp), %eax\n" /* line 1744 | serverCommandSequence */
        "movl %eax, 0x5e98(%ecx)\n"
        "calll CG_ParseServerinfo\n" /* line 1746 */
        "calll CG_ParseCodinfo\n" /* line 1747 */
        "calll UI_LoadIngameMenus\n" /* line 1753 */
        "calll SCR_UpdateScreen\n" /* line 1755 */
        "movl $7, 4(%esp)\n" /* line 1757 */
        "movl $str_00224184, (%esp)\n" /* "white" */
        "calll CL_RegisterMaterial\n"
        "movl cgs, %edx\n"
        "movl %eax, 0xba1c(%edx)\n"
        "movl $7, 4(%esp)\n" /* line 1758 */
        "movl $str_002a8984, (%esp)\n" /* "hudsoftline" */
        "calll CL_RegisterMaterial\n"
        "movl cgs, %ecx\n"
        "movl %eax, 0xba20(%ecx)\n"
        "movl $7, 4(%esp)\n" /* line 1759 */
        "movl $str_002a8990, (%esp)\n" /* "hudsoftlineh" */
        "calll CL_RegisterMaterial\n"
        "movl cgs, %edx\n"
        "movl %eax, 0xba24(%edx)\n"
        "movl $1, 4(%esp)\n" /* line 1761 */
        "movl $str_002a89a0, (%esp)\n" /* "fonts/smallDevFont" */
        "calll CL_RegisterFont\n"
        "movl cgs, %ecx\n"
        "movl %eax, 0xbc7c(%ecx)\n"
        "movl $1, 4(%esp)\n" /* line 1762 */
        "movl $str_002a89b4, (%esp)\n" /* "fonts/bigDevFont" */
        "calll CL_RegisterFont\n"
        "movl cgs, %edx\n"
        "movl %eax, 0xbc80(%edx)\n"
        "movl $7, 4(%esp)\n" /* line 1764 */
        "movl $str_002a89c8, (%esp)\n" /* "net_disconnect" */
        "calll CL_RegisterMaterial\n"
        "movl $7, 4(%esp)\n" /* line 1777 */
        "movl $str_002a763c, (%esp)\n" /* "killicondied" */
        "calll CL_RegisterMaterial\n"
        "movl $7, 4(%esp)\n" /* line 1778 */
        "movl $str_002a762c, (%esp)\n" /* "killiconcrush" */
        "calll CL_RegisterMaterial\n"
        "movl $7, 4(%esp)\n" /* line 1779 */
        "movl $str_002a761c, (%esp)\n" /* "killiconfalling" */
        "calll CL_RegisterMaterial\n"
        "movl $7, 4(%esp)\n" /* line 1780 */
        "movl $str_002a760c, (%esp)\n" /* "killiconsuicide" */
        "calll CL_RegisterMaterial\n"
        "movl $7, 4(%esp)\n" /* line 1781 */
        "movl $str_002a89d8, (%esp)\n" /* "killiconheadshot" */
        "calll CL_RegisterMaterial\n"
        "movl $7, 4(%esp)\n" /* line 1782 */
        "movl $str_002a75fc, (%esp)\n" /* "killiconmelee" */
        "calll CL_RegisterMaterial\n"
        "calll CG_AntiBurnInHUD_RegisterDvars\n" /* line 1791 */
        "calll CG_InitConsoleCommands\n" /* line 1793 */
        "movl cgs, %ecx\n" /* line 1694 */
        "movl $0, 0x5e84(%ecx)\n"
        "movl %ecx, %eax\n" /* line 1696 */
        "addl $0x5e94, %eax\n"
        "movl %eax, 8(%esp)\n"
        "subl $4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "subl $4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_GetScreenDimensions\n"
        "movl $2, (%esp)\n" /* line 1798 */
        "calll CL_GetConfigString\n"
        "movl %eax, -0x5c(%ebp)\n" /* s */
        "movl $str_002a89ec, %edi\n" /* line 1799 */
        "movl $4, %ebx\n"
        "cld\n"
        "movl %eax, %esi\n"
        "movl %ebx, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf145828_00147493\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf145828_00147493:\n"
        "testl %eax, %eax\n"
        "jne .Lf145828_001476d2\n"
        ".Lf145828_0014749b:\n"
        "movl $0xd, (%esp)\n" /* line 1802 */
        "calll CL_GetConfigString\n"
        "movl %eax, (%esp)\n" /* line 1803 */
        "calll atoi\n"
        "movl cgs, %edx\n"
        "movl %eax, 0x63b4(%edx)\n"
        "calll SCR_UpdateScreen\n" /* line 1805 */
        "movl imp_com_sv_running, %ecx\n" /* line 1808 */
        "movl (%ecx), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf145828_0014775d\n"
        ".Lf145828_001474d2:\n"
        "movl imp_bg_iNumWeapons, %eax\n" /* line 1811 */
        "movl (%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf145828_00147742\n"
        ".Lf145828_001474e1:\n"
        "calll CG_SetupWeaponDef\n" /* line 1819 */
        "calll CGScr_LoadAnimTrees\n" /* line 1822 */
        "movl cg, %edx\n" /* line 1825 */
        "addl $0x2cd18, %edx\n"
        "movl imp_bgs, %eax\n"
        "movl %edx, (%eax)\n"
        "calll BG_LoadAnim\n" /* line 1826 */
        "movl cg, %eax\n" /* line 1627 */
        "movl 0xe08e0(%eax), %edi\n"
        "xorl %esi, %esi\n"
        "movl %eax, %ebx\n"
        "addl $0xe0db8, %ebx\n"
        ".Lf145828_00147518:\n"
        "movl $Hunk_AllocXAnimClient, 4(%esp)\n" /* line 1630 */
        "movl %edi, (%esp)\n"
        "calll XAnimCreateTree\n"
        "movl %eax, (%ebx)\n"
        "addl $1, %esi\n" /* line 1629 */
        "addl $0x4b8, %ebx\n"
        "cmpl $0x40, %esi\n"
        "jne .Lf145828_00147518\n"
        "xorw %si, %si\n"
        "movl cgs, %ebx\n"
        "addl $0xc6b8, %ebx\n"
        ".Lf145828_00147547:\n"
        "movl $Hunk_AllocXAnimClient, 4(%esp)\n" /* line 1634 */
        "movl %edi, (%esp)\n"
        "calll XAnimCreateTree\n"
        "movl %eax, (%ebx)\n"
        "addl $1, %esi\n" /* line 1633 */
        "addl $0x4b8, %ebx\n"
        "cmpl $8, %esi\n"
        "jne .Lf145828_00147547\n"
        "movl cgs, %edx\n" /* line 1829 */
        "movl 0x5ea0(%edx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf145828_00147738\n"
        ".Lf145828_0014757b:\n"
        "movl $str_002a8a14, (%esp)\n" /* line 1833 */
        "calll CG_LoadingString\n"
        "movl cgs, %ebx\n" /* line 1835 */
        "addl $0x5fc8, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll CL_CM_LoadMap\n"
        "movl $cgDC, (%esp)\n" /* line 1837 */
        "calll Menu_Setup\n"
        "movl $str_002a8a24, (%esp)\n" /* line 1839 */
        "calll CG_LoadingString\n"
        "movl cg, %eax\n" /* line 1846 */
        "addl $0x28570, %eax\n"
        "movl $0x58, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "cmpb $0, g_mapLoaded\n" /* line 1849 */
        "je .Lf145828_00147708\n"
        ".Lf145828_001475e2:\n"
        "movl $str_002a8a40, (%esp)\n" /* line 1865 */
        "calll CG_LoadingString\n"
        "leal -0x58(%ebp), %ebx\n" /* line 1868 | mapname */
        "movl %ebx, 4(%esp)\n"
        "movl cgs, %eax\n"
        "addl $0x5fcd, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_StripExtension\n"
        "movl %ebx, %eax\n" /* line 1870 */
        "calll CG_RegisterGraphics\n"
        "movl $str_002a8a4c, (%esp)\n" /* line 1872 */
        "calll CG_LoadingString\n"
        "calll CG_RegisterSounds\n" /* line 1874 */
        "movl $str_002a8a54, (%esp)\n" /* line 1876 */
        "calll CG_LoadingString\n"
        "calll CG_LoadHudMenu\n" /* line 1878 */
        "xorl %eax, %eax\n"
        "movl cg_entities, %edx\n"
        ".Lf145828_00147638:\n"
        "movl $0, 0x220(%edx, %eax)\n" /* line 1684 */
        "addl $0x224, %eax\n"
        "cmpl $0x89000, %eax\n" /* line 1679 */
        "jne .Lf145828_00147638\n"
        "movl cg, %ebx\n" /* line 1687 */
        "movl $0, 0x2848c(%ebx)\n"
        "calll CG_InitLocalEntities\n" /* line 1882 */
        "calll CG_InitMarkPolys\n" /* line 1884 */
        "movb $0, 0x2a5fc(%ebx)\n" /* line 1887 */
        "calll CG_SetConfigValues\n" /* line 1890 */
        "movl $str_002157b8, (%esp)\n" /* line 1892 */
        "calll CG_LoadingString\n"
        "calll CG_NorthDirectionChanged\n" /* line 1894 */
        "calll CL_FinishLoadingModels\n" /* line 1896 */
        "cmpb $0, g_mapLoaded\n" /* line 1899 */
        "je .Lf145828_001476fa\n"
        ".Lf145828_00147694:\n"
        "calll CG_ParseFog\n" /* line 1902 */
        "cmpb $0, g_ambientStarted\n" /* line 1905 */
        "jne .Lf145828_001476ae\n"
        "calll CG_StartAmbient\n" /* line 1908 */
        "movb $1, g_ambientStarted\n" /* line 1910 */
        ".Lf145828_001476ae:\n"
        "movl $0, (%esp)\n" /* line 1913 */
        "calll CL_SetADS\n"
        "calll CG_InitVote\n" /* line 1920 */
        "movl imp_bgs, %eax\n" /* line 1934 */
        "movl $0, (%eax)\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 1939 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf145828_001476d2:\n"
        "movl -0x5c(%ebp), %eax\n" /* line 1800 | s */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002a89ec, 8(%esp)\n" /* "cod" */
        "movl $str_002a89f0, 4(%esp)\n" /* "Client/Server game mismatch: %s/%s" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf145828_0014749b\n"
        ".Lf145828_001476fa:\n"
        "movl $0, (%esp)\n" /* line 1900 */
        "calll SND_StopSounds\n"
        "jmp .Lf145828_00147694\n"
        ".Lf145828_00147708:\n"
        "movl %ebx, (%esp)\n" /* line 1851 */
        "calll CG_LoadingString\n"
        "movl %ebx, (%esp)\n" /* line 1853 */
        "calll LoadWorld\n"
        "movb $1, g_mapLoaded\n" /* line 1855 */
        "movl $str_002a8a30, (%esp)\n" /* line 1857 */
        "calll CG_LoadingString\n"
        "movl %ebx, (%esp)\n" /* line 1860 */
        "calll CL_LoadSoundAliases\n"
        "jmp .Lf145828_001475e2\n"
        ".Lf145828_00147738:\n"
        "calll GScr_LoadConsts\n" /* line 1830 */
        "jmp .Lf145828_0014757b\n"
        ".Lf145828_00147742:\n"
        "calll CL_SetWeaponInfoMemory\n" /* line 1813 */
        "calll BG_ClearWeaponDef\n" /* line 1814 */
        "movl $0, (%esp)\n" /* line 1815 */
        "calll BG_FillInAmmoItems\n"
        "jmp .Lf145828_001474e1\n"
        ".Lf145828_0014775d:\n"
        "movl $Hunk_AllocXAnimClient, (%esp)\n" /* line 1809 */
        "calll Mantle_CreateAnims\n"
        "jmp .Lf145828_001474d2\n"
    );
}

