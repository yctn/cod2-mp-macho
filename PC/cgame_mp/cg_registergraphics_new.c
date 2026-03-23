/*
 * CG_RegisterGraphics - Clean C reimplementation
 * Replaces the naked ASM version in cg_main_mp.c (lines 317-670).
 * Registers materials, models, effects, and shellshock configs.
 */
#include "common_types.h"
#include "imports.h"
#include <string.h>

/* External function declarations */
extern void SCR_UpdateScreen(void);
extern void Com_Printf(const char *fmt, ...);
extern void Com_Error(int level, const char *fmt, ...);
extern void FX_InitSystem(int maxEffects);
extern void FX_CreateDefaultEffect(void);
extern void *FX_RegisterEffect(const char *name);
extern void CG_LoadingString(const char *str);
extern void *CL_RegisterMaterial(const char *name, int flags);
extern void *CL_RegisterMaterialNoMip(const char *name, int flags);
extern void *CL_RegisterModel(const char *name);
extern void *CL_RegisterInlineModel(int index);
extern void CL_ModelBounds(void *model, vec3_t mins, vec3_t maxs);
extern const char *CL_GetConfigString(int index);
extern int CM_NumInlineModels(void);
extern void CG_RegisterItems(void);
extern void CG_RegisterScoreboardGraphics(void);
extern int CG_LoadShellShockDvars(const char *name);
extern void CG_SetShellShockParmsFromDvars(void *parms);
extern int CG_RegisterImpactEffects(const char *mapname);
/* memset from string.h */

/* External globals — these are POINTERS to the actual arrays, not the arrays themselves.
   The linker symbols (cgs, cg_items, cg_weapons) are 4-byte import pointers.
   Declaring as pointer types ensures C dereferences them correctly. */
extern cgs_t *cgs;       /* pointer to client game state */
extern byte *cg_items;   /* pointer to items array */
extern byte *cg_weapons; /* pointer to weapons array */

/* This function was __attribute__((regparm(1))) in the original —
   mapname passed in eax. Called from CG_Init ASM. */
void __attribute__((regparm(1))) CG_RegisterGraphics(const char *mapname)
{
    int i, j;
    const char *str;
    vec3_t mins, maxs;

    /* --- FX system initialization --- */
    SCR_UpdateScreen();
    Com_Printf("^5---------- Fx System Initialization ---------\n");
    FX_InitSystem(1);
    FX_CreateDefaultEffect();
    Com_Printf("^5----- Fx System Initialization Complete -----\n");

    /* --- Material registration --- */
    CG_LoadingString(" - textures");

    cgs->media.lagometerMaterial = CL_RegisterMaterial("lagometer", 7);
    cgs->media.connectionMaterial = CL_RegisterMaterial("headicondisconnected", 7);
    cgs->media.youInKillCamMaterial = CL_RegisterMaterial("headiconyouinkillcam", 7);
    CL_RegisterMaterial("killiconmelee", 7);
    CL_RegisterMaterial("killiconsuicide", 7);
    CL_RegisterMaterial("killiconfalling", 7);
    CL_RegisterMaterial("killiconcrush", 7);
    CL_RegisterMaterial("killicondied", 7);
    cgs->media.tracerMaterial = CL_RegisterMaterial("gfx/misc/tracer", 6);
    cgs->media.hintMaterials[2] = CL_RegisterMaterial("gfx/icons/hint_usable", 7);
    cgs->media.hintMaterials[3] = CL_RegisterMaterial("hint_health", 7);
    cgs->media.hintMaterials[4] = CL_RegisterMaterial("hint_friendly", 7);
    cgs->media.stanceMaterials[0] = CL_RegisterMaterial("stance_stand", 7);
    cgs->media.stanceMaterials[1] = CL_RegisterMaterial("stance_crouch", 7);
    cgs->media.stanceMaterials[2] = CL_RegisterMaterial("stance_prone", 7);
    cgs->media.stanceMaterials[3] = CL_RegisterMaterial("stance_flash", 7);
    cgs->media.objectiveMaterials[0] = CL_RegisterMaterial("objective", 7);
    cgs->media.friendMaterials[0] = CL_RegisterMaterial("objective_friendly", 7);
    cgs->media.friendMaterials[1] = CL_RegisterMaterial("objective_friendly_chat", 7);
    cgs->media.damageMaterial = CL_RegisterMaterial("hit_direction", 7);
    cgs->media.mantleHint = CL_RegisterMaterial("hint_mantle", 7);
    cgs->media.checkbox_clear = CL_RegisterMaterialNoMip("ui/assets/checkbox_clear", 7);
    cgs->media.checkbox_checked = CL_RegisterMaterialNoMip("ui/assets/checkbox_checked", 7);
    cgs->media.checkbox_fail = CL_RegisterMaterialNoMip("ui/assets/checkbox_fail", 7);
    cgs->media.compassping_friendlyfiring = CL_RegisterMaterialNoMip("compassping_friendlyfiring", 7);
    cgs->media.compassping_friendlyyelling = CL_RegisterMaterialNoMip("compassping_friendlyyelling", 7);
    cgs->media.compassping_enemyfiring = CL_RegisterMaterialNoMip("compassping_enemyfiring", 7);
    cgs->media.compassping_enemyyelling = CL_RegisterMaterialNoMip("compassping_enemyyelling", 7);
    cgs->media.compassping_grenade = CL_RegisterMaterialNoMip("compassping_grenade", 7);
    cgs->media.compassping_explosion = CL_RegisterMaterialNoMip("compassping_explosion", 7);
    cgs->media.grenadeIcon = CL_RegisterMaterialNoMip("hud_grenadeicon", 7);
    cgs->media.grenadePointer = CL_RegisterMaterialNoMip("hud_grenadepointer", 7);
    cgs->media.teamStatusBar = CL_RegisterMaterial("hudcolorbar", 7);

    /* --- Model/sound registration --- */
    CG_LoadingString(" - models");
    cgs->media.voiceChatMaterial = CL_RegisterMaterial("headiconvoicechat", 7);
    cgs->media.balloonMaterial = CL_RegisterMaterial("headicontalkballoon", 7);
    CG_RegisterScoreboardGraphics();

    /* Clear weapon and item arrays */
    memset((void *)cg_items, 0, 9216);
    memset((void *)cg_weapons, 0, 55808);

    /* --- Register items --- */
    CG_LoadingString(" - items");
    CG_RegisterItems();

    /* --- Register inline models --- */
    CG_LoadingString(" - inline models");
    cgs->numInlineModels = CM_NumInlineModels();

    if (cgs->numInlineModels > 1) {
        for (i = 1; i < cgs->numInlineModels; i++) {
            cgs->inlineDrawModel[i] = CL_RegisterInlineModel(i);

            void *model = cgs->inlineDrawModel[i];
            CL_ModelBounds(model, mins, maxs);

            for (j = 0; j < 3; j++) {
                float mid = (mins[j] + maxs[j]) * 0.5f;
                cgs->inlineModelMidpoints[i][j] = mid;
            }
        }
    }

    /* --- Register server models --- */
    CG_LoadingString(" - server models");
    for (i = 1; i < 256; i++) {
        str = CL_GetConfigString(0x14e + i);
        if (str[0] == '\0')
            continue;
        cgs->gameModels[i] = CL_RegisterModel(str);
    }

    /* --- Register server effects --- */
    for (i = 1; i < 64; i++) {
        str = CL_GetConfigString(0x34e + i);
        if (str[0] == '\0')
            continue;
        cgs->fxs[i] = FX_RegisterEffect(str);
    }

    /* --- Register smoke grenade effect --- */
    cgs->smokeGrenadeFx = FX_RegisterEffect("fx/props/american_smoke_grenade.efx");

    /* --- Register shellshock configs --- */
    for (i = 1; i < 16; i++) {
        str = CL_GetConfigString(0x48e + i);
        if (str[0] == '\0')
            break;
        if (!CG_LoadShellShockDvars(str)) {
            Com_Error(1, "couldn't register shell shock '%s' -- see console\n", str);
        }
        CG_SetShellShockParmsFromDvars(&cgs->shellshockParms[i]);
    }

    /* --- Register hold_breath shellshock --- */
    if (!CG_LoadShellShockDvars("hold_breath")) {
        Com_Error(1, "Couldn't find shock file [hold_breath.shock]\n");
    }
    CG_SetShellShockParmsFromDvars(&cgs->holdBreathParams);

    /* --- Register impact effects --- */
    cgs->media.fx = (FxImpactTable *)CG_RegisterImpactEffects(mapname);
    if (!cgs->media.fx) {
        Com_Error(1, "Error reading CSV files in the fx directory to identify impact effects");
    }
    cgs->media.fxNoBloodFleshHit = FX_RegisterEffect("fx/impacts/flesh_hit_noblood.efx");

    CG_LoadingString(" - game media done");
}
