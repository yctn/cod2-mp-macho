/* Auto-generated stubs for remaining undefined symbols */
#include <stdio.h>
#include "common_types.h"

/*
 * Mac binary's Dvar_RegisterString/Bool used a 5-param convention:
 *   (name, value, min, max, flags)
 * Our decompiled versions only take 3 params: (name, value, flags).
 * All inline asm from the Mac decompilation uses the 5-param convention.
 * These wrappers translate between the two calling conventions.
 */
extern const dvar_t * Dvar_RegisterString(const char *dvarName, const char *value, int flags);
extern const dvar_t * Dvar_RegisterBool(const char *dvarName, int value, int flags);

const dvar_t * Dvar_RegisterString_mac(const char *name, const char *value, int min, int max, int flags) {
    return Dvar_RegisterString(name, value ? value : "", flags);
}

const dvar_t * Dvar_RegisterBool_mac(const char *name, int value, int min, int max, int flags) {
    return Dvar_RegisterBool(name, value, flags);
}

/* --- Function stubs --- */
int AddMovieResource() { return 0; }
int AdvanceKeyboardFocus() { return 0; }
int AECoerceDesc() { return 0; }
int AECreateAppleEvent() { return 0; }
int AECreateDesc() { return 0; }
int AEDisposeDesc() { return 0; }
int AEGetDescData() { return 0; }
int AEGetParamDesc() { return 0; }
int AEGetParamPtr() { return 0; }
int AEPutParamDesc() { return 0; }
int AEPutParamPtr() { return 0; }
int AESend() { return 0; }
int aglDescribePixelFormat() { return 0; }
int aglGetDrawable() { return 0; }
int AlertSoundPlay() { return 0; }
int AudioConverterDispose() { return 0; }
int AudioConverterFillBuffer() { return 0; }
int AudioConverterFillComplexBuffer() { return 0; }
int AudioConverterNew() { return 0; }
int AudioConverterReset() { return 0; }
int AudioDeviceGetPropertyInfo() { return 0; }
int AudioUnitAddRenderNotify() { return 0; }
int AudioUnitInitialize() { return 0; }
int AudioUnitRemoveRenderNotify() { return 0; }
int AudioUnitUninitialize() { return 0; }
int CFBooleanGetValue() { return 0; }
int CFBundleCopyExecutableURL() { return 0; }
int CFBundleCopyLocalizedString() { return 0; }
int CFDataGetBytePtr() { return 0; }
int CFStringCompare() { return 0; }
int CFStringCreateWithCharacters() { return 0; }
int CFStringCreateWithFormat() { return 0; }
int CFStringGetPascalString() { return 0; }
int CFURLGetFSRef() { return 0; }
int CGAcquireDisplayFadeReservation() { return 0; }
int CGAssociateMouseAndMouseCursorPosition() { return 0; }
int CGDisplayAvailableModes() { return 0; }
int CGDisplayBitsPerPixel() { return 0; }
int CGDisplayBounds() { return 0; }
int CGDisplayCurrentMode() { return 0; }
int CGDisplayFade() { return 0; }
int CGDisplayIDToOpenGLDisplayMask() { return 0; }
int CGDisplayIOServicePort() { return 0; }
int CGDisplayPixelsHigh() { return 0; }
int CGDisplayPixelsWide() { return 0; }
int CGGetActiveDisplayList() { return 0; }
int CGGetDisplayTransferByTable() { return 0; }
int CGLChoosePixelFormat() { return 0; }
int CGLCreateContext() { return 0; }
int CGLDescribeRenderer() { return 0; }
int CGLDestroyContext() { return 0; }
int CGLDestroyPixelFormat() { return 0; }
int CGLDestroyRendererInfo() { return 0; }
int CGLGetCurrentContext() { return 0; }
int CGLQueryRendererInfo() { return 0; }
int CGLSetCurrentContext() { return 0; }
int CGRectEqualToRect() { return 0; }
int CGRectGetHeight() { return 0; }
int CGRectGetWidth() { return 0; }
int CGRectIsEmpty() { return 0; }
int CGRectUnion() { return 0; }
int CGRectZero() { return 0; }
int CGReleaseDisplayFadeReservation() { return 0; }
int CGSetDisplayTransferByTable() { return 0; }
int CGWarpMouseCursorPosition() { return 0; }
int DisposeGWorld() { return 0; }
int DisposeHandle() { return 0; }
int DisposeMovie() { return 0; }
int DisposeNibReference() { return 0; }
int DisposeRgn() { return 0; }
int FSCloseIterator() { return 0; }
int FSDeleteObject() { return 0; }
int FSGetCatalogInfo() { return 0; }
int FSGetCatalogInfoBulk() { return 0; }
int FSGetVolumeInfo() { return 0; }
int FSMakeFSSpec() { return 0; }
int FSOpenIterator() { return 0; }
int FSPathMakeRef() { return 0; }
int FSpMakeFSRef() { return 0; }
int FSRefMakePath() { return 0; }
int FSSetCatalogInfo() { return 0; }
int GetControlBounds() { return 0; }
int GetControlByID() { return 0; }
int GetControlData() { return 0; }
int GetControlDataSize() { return 0; }
int GetControlKind() { return 0; }
int GetControlMaximum() { return 0; }
int GetControlOwner() { return 0; }
int GetControlReference() { return 0; }
int SND_SetChannelInfo() { return 0; }
int SND_SetEnvironmentEffects_f() { return 0; }
int SV_GetBrushModelCount() { return 0; }

/* --- Data stubs --- */
char AUGraphGetCPULoad[64] __attribute__((aligned(4))) = {0};
char AUGraphGetNodeInfo[64] __attribute__((aligned(4))) = {0};
char AUGraphNewNode[64] __attribute__((aligned(4))) = {0};
char AUGraphUpdate[64] __attribute__((aligned(4))) = {0};
char bg_itemlist_ptr[64] __attribute__((aligned(4))) = {0};
char bg_weaponInfoMem[64] __attribute__((aligned(4))) = {0};
char buf[64] __attribute__((aligned(4))) = {0};
extern unsigned char cgArray[];
void *cg __attribute__((aligned(4))) = (void *)cgArray;
char cg_debug_ptr[64] __attribute__((aligned(4))) = {0};
char cg_dvar1[64] __attribute__((aligned(4))) = {0};
char cg_dvar2[64] __attribute__((aligned(4))) = {0};
char cg_dvar_debug[64] __attribute__((aligned(4))) = {0};
char cg_dvar_footsteps[64] __attribute__((aligned(4))) = {0};
/* cg_dvar_shellshock_max: aliased to imp_bg_fallDamageMaxHeight in import_pointers.S */
/* cg_dvar_shellshock_min: aliased to imp_bg_fallDamageMinHeight in import_pointers.S */
extern unsigned char cg_entitiesArray[];
void *cg_entities __attribute__((aligned(4))) = (void *)cg_entitiesArray;
/* cg_entities_glob: aliased to imp_cg_entities in import_pointers.S */
/* cg_entities_ptr: aliased to imp_cg_entities in import_pointers.S */
char cg_eventNames[64] __attribute__((aligned(4))) = {0};
/* cg_glob: aliased to imp_cg in import_pointers.S */
char cg_globSnap[64] __attribute__((aligned(4))) = {0};
/* cg_globUI: aliased to legacyHacks via --defsym */
char cg_hud_ptr[64] __attribute__((aligned(4))) = {0};
char cg_itemCount[64] __attribute__((aligned(4))) = {0};
char cg_itemDefs[64] __attribute__((aligned(4))) = {0};
char cg_itemInfo[64] __attribute__((aligned(4))) = {0};
extern unsigned char cg_itemsArray[];
void *cg_items __attribute__((aligned(4))) = (void *)cg_itemsArray;
/* _cg_p: aliased to imp_cg in import_pointers.S */
char cg_pmove_mins[64] __attribute__((aligned(4))) = {0};
/* cg_ptr: aliased to imp_cg in import_pointers.S */
extern unsigned char cgsArray[];
void *cgs __attribute__((aligned(4))) = (void *)cgsArray;
/* cgs_glob: aliased to imp_cgs in import_pointers.S */
char cg_sprite2_ptr[64] __attribute__((aligned(4))) = {0};
char cg_sprite3_ptr[64] __attribute__((aligned(4))) = {0};
char cg_sprite4_ptr[64] __attribute__((aligned(4))) = {0};
char cg_sprite5_ptr[64] __attribute__((aligned(4))) = {0};
char cg_sprite6_ptr[64] __attribute__((aligned(4))) = {0};
char cg_sprite_ptr[64] __attribute__((aligned(4))) = {0};
/* cgs_ptr: aliased to imp_cgs in import_pointers.S */
char cg_tags_ptr[64] __attribute__((aligned(4))) = {0};
char cg_uiglob[64] __attribute__((aligned(4))) = {0};
char cg_viewscreen_ptr[64] __attribute__((aligned(4))) = {0};
char cg_weapinfo_ptr[64] __attribute__((aligned(4))) = {0};
char cg_weaponDefs[64] __attribute__((aligned(4))) = {0};
extern unsigned char cg_weaponsArray[];
void *cg_weapons __attribute__((aligned(4))) = (void *)cg_weaponsArray;
char cg_xanimInfo[64] __attribute__((aligned(4))) = {0};
extern unsigned char clients[];
void *cl __attribute__((aligned(4))) = (void *)clients;
extern unsigned char clientConnections[];
void *clc __attribute__((aligned(4))) = (void *)clientConnections;
/* clc_ptr, clc_ptr_195ee8c: aliases for imp_clc — defined in import_pointers.S */
char ClipRect[64] __attribute__((aligned(4))) = {0};
char CloseComponent[64] __attribute__((aligned(4))) = {0};
char CloseMovieFile[64] __attribute__((aligned(4))) = {0};
char CloseRgn[64] __attribute__((aligned(4))) = {0};
char cl_packetdelay[64] __attribute__((aligned(4))) = {0};
/* cl_ptr: alias for imp_cl — defined in import_pointers.S */
char cl_showPackets[64] __attribute__((aligned(4))) = {0};
/* cls_ptr: alias for imp_cls — defined in import_pointers.S */
extern unsigned char cls[];
void *cls_ptr_195ecac = (void *)cls; /* GOT alias: pointer to cls BSS struct */
char cm_global[64] __attribute__((aligned(4))) = {0};
char cm_phys_ptr[64] __attribute__((aligned(4))) = {0};
char com_checksumFeed_dvar[64] __attribute__((aligned(4))) = {0};
/* com_dvarflags_ptr: alias for imp_dvar_modifiedFlags — defined in import_pointers.S */
char com_errorEntered_ptr[64] __attribute__((aligned(4))) = {0};
char commandsList[64] __attribute__((aligned(4))) = {0};
char compPointerConfig[64] __attribute__((aligned(4))) = {0};
char com_statmon_ptr[64] __attribute__((aligned(4))) = {0};
char CreateEvent[64] __attribute__((aligned(4))) = {0};
char CreateNewWindow[64] __attribute__((aligned(4))) = {0};
char CreateNibReferenceWithCFBundle[64] __attribute__((aligned(4))) = {0};
char CreateObjSpecifier[64] __attribute__((aligned(4))) = {0};
char CreateStandardAlert[64] __attribute__((aligned(4))) = {0};
char CreateWindowFromNib[64] __attribute__((aligned(4))) = {0};
char d3d_context[64] __attribute__((aligned(4))) = {0};
char __DefaultRuneLocale[64] __attribute__((aligned(4))) = {0};
char DisableControl[64] __attribute__((aligned(4))) = {0};
char DMGetFirstScreenDevice[64] __attribute__((aligned(4))) = {0};
char DMGetNextScreenDevice[64] __attribute__((aligned(4))) = {0};
char download_ui_ptr[64] __attribute__((aligned(4))) = {0};
char DrawThemeFocusRect[64] __attribute__((aligned(4))) = {0};
char DrawThemeMenuBarBackground[64] __attribute__((aligned(4))) = {0};
char dvar_autoPickup[64] __attribute__((aligned(4))) = {0};
char dvar_compassClampDist[64] __attribute__((aligned(4))) = {0};
char dvar_compassClampSaturation[64] __attribute__((aligned(4))) = {0};
char dvar_compassFade[64] __attribute__((aligned(4))) = {0};
char dvar_compassMaxRange[64] __attribute__((aligned(4))) = {0};
char dvar_compassMinRange[64] __attribute__((aligned(4))) = {0};
char dvar_compassMinSaturation[64] __attribute__((aligned(4))) = {0};
char dvar_compassPingFadeTime[64] __attribute__((aligned(4))) = {0};
char dvar_compassSize[64] __attribute__((aligned(4))) = {0};
char dvar_developer[64] __attribute__((aligned(4))) = {0};
char dvar_errorDecay[64] __attribute__((aligned(4))) = {0};
char dvar_nopredict[64] __attribute__((aligned(4))) = {0};
char dvar_ptr_195ee78[64] __attribute__((aligned(4))) = {0};
/* _dvar_shellshock_*: 29 aliases defined in import_pointers.S (fix #123) */
char dvar_synchronous[64] __attribute__((aligned(4))) = {0};
/* dx_device_ptr: alias for imp_dx — defined in import_pointers.S */
/* dx_fence: alias for imp_alwaysfails — defined in import_pointers.S */
char dxIter[64] __attribute__((aligned(4))) = {0};
char __dyld_func_lookup[64] __attribute__((aligned(4))) = {0};
char EnableControl[64] __attribute__((aligned(4))) = {0};
char encode_vol_ptr[64] __attribute__((aligned(4))) = {0};
char EndMediaEdits[64] __attribute__((aligned(4))) = {0};
char entityHandlers_ptr[64] __attribute__((aligned(4))) = {0};
char EqualRect[64] __attribute__((aligned(4))) = {0};
int FindNextComponent() { return 0; } /* Mac Carbon stub: no audio components */
char ForeColor[64] __attribute__((aligned(4))) = {0};
char FrameRoundRect[64] __attribute__((aligned(4))) = {0};
/* FxFlagEntry = { const char *flag, unsigned int masks[2] } — 12 bytes each */
extern const char str_00219f74[]; /* org2fromTrace */
extern const char str_00219f84[]; /* traceImpactFx */
extern const char str_00219f94[]; /* org2isOffset */
extern const char str_00219fa4[]; /* cheapOrgCalc */
extern const char str_00219fb4[]; /* cheapOrg2Calc */
extern const char str_00219fc4[]; /* orgOnSphere */
extern const char str_00219fd0[]; /* orgOnCylinder */
extern const char str_00219fe0[]; /* axisFromSphere */
extern const char str_00219ff0[]; /* randrotaroundfwd */
extern const char str_0021a09c[]; /* useAlpha */
extern const char str_0021a0a8[]; /* useRandomColors */
extern const char str_0021a0b8[]; /* useRandomAlpha */
extern const char str_0021a0c8[]; /* useRandomSize */
extern const char str_0021a0d8[]; /* useRandomSize2 */
extern const char str_0021a0e8[]; /* useRandomLength */
extern const char str_0021a0f8[]; /* useRandomRotationDelta */
extern const char str_0021a110[]; /* useRandomVelocity */
extern const char str_0021a124[]; /* useRandomVelocity2 */
extern const char str_0021a138[]; /* absoluteVel2 */
extern const char str_0021a148[]; /* affectedByWind */
extern const char str_0021a158[]; /* emitFx */
extern const char str_0021a160[]; /* relative */
extern const char str_0021a16c[]; /* blocksSight */
extern const char str_0021a178[]; /* disableFarPlaneCulling */
extern const char str_0021a024[]; /* absoluteVel */
extern const char str_0021a068[]; /* useBBox */
extern const char str_0021a070[]; /* usePhysics */
extern const char str_0021a07c[]; /* impactKills */
extern const char str_0021a088[]; /* impactFx */
extern const char str_0021a1a4[]; /* linear */
struct { const char *flag; unsigned int masks[2]; }
fxAttributeFlags[26] __attribute__((aligned(4))) = {
    { str_00219f74, { 0x000001, 0 } }, /* org2fromTrace */
    { str_00219f84, { 0x000002, 0 } }, /* traceImpactFx */
    { str_00219f94, { 0x000004, 0 } }, /* org2isOffset */
    { str_00219fa4, { 0x000008, 0 } }, /* cheapOrgCalc */
    { str_00219fb4, { 0x000010, 0 } }, /* cheapOrg2Calc */
    { str_0021a024, { 0x000020, 0 } }, /* absoluteVel (was spawn→attr) */
    { str_0021a068, { 0x000040, 0 } }, /* useBBox (was spawn→attr) */
    { str_0021a070, { 0x000080, 0 } }, /* usePhysics (was spawn→attr) */
    { str_0021a07c, { 0x000100, 0 } }, /* impactKills (was spawn→attr) */
    { str_0021a09c, { 0x000200, 0 } }, /* useAlpha */
    { str_0021a0a8, { 0x000400, 0 } }, /* useRandomColors */
    { str_0021a0b8, { 0x000800, 0 } }, /* useRandomAlpha */
    { str_0021a0c8, { 0x001000, 0 } }, /* useRandomSize */
    { str_0021a0d8, { 0x002000, 0 } }, /* useRandomSize2 */
    { str_0021a0e8, { 0x004000, 0 } }, /* useRandomLength */
    { str_0021a0f8, { 0x008000, 0 } }, /* useRandomRotationDelta */
    { str_0021a110, { 0x010000, 0 } }, /* useRandomVelocity */
    { str_0021a124, { 0x020000, 0 } }, /* useRandomVelocity2 */
    { str_0021a138, { 0x040000, 0 } }, /* absoluteVel2 */
    { str_0021a148, { 0x080000, 0 } }, /* affectedByWind */
    { str_0021a158, { 0x100000, 0 } }, /* emitFx */
    { str_0021a160, { 0x200000, 0 } }, /* relative */
    { str_0021a16c, { 0x400000, 0 } }, /* blocksSight */
    { str_0021a178, { 0x800000, 0 } }, /* disableFarPlaneCulling */
    { str_0021a088, { 0x1000000, 0 } }, /* impactFx (also in spawnFlags) */
    { str_0021a1a4, { 0x2000000, 0 } }, /* linear */
};
/* fx_developer_check_ptr: aliased to imp_g_rendererExists in import_pointers.S */
/* fx_helper_ptr: alias for imp_theFxHelper — defined in import_pointers.S */
/* fx_scheduler_ptr: alias for imp_theFxScheduler — defined in import_pointers.S */
char fx_sort_ptr[64] __attribute__((aligned(4))) = {0};
extern const char str_0021a004[]; /* evenDistribution */
extern const char str_0021a018[]; /* frustumCull */
extern const char str_0021a024[]; /* absoluteVel */
extern const char str_0021a030[]; /* absoluteAccel */
extern const char str_0021a040[]; /* depthHack */
extern const char str_0021a04c[]; /* setShaderTime */
extern const char str_0021a05c[]; /* useModel */
extern const char str_0021a068[]; /* useBBox */
extern const char str_0021a070[]; /* usePhysics */
extern const char str_0021a07c[]; /* impactKills */
extern const char str_0021a088[]; /* impactFx */
extern const char str_0021a094[]; /* deathFx */
struct { const char *flag; unsigned int masks[2]; }
fxSpawnFlags[13] __attribute__((aligned(4))) = {
    { str_0021a004, { 0, 0x001 } }, /* evenDistribution */
    { str_0021a018, { 0, 0x002 } }, /* frustumCull */
    { str_00219fc4, { 0, 0x004 } }, /* orgOnSphere (was attr→spawn) */
    { str_0021a030, { 0, 0x008 } }, /* absoluteAccel */
    { str_0021a040, { 0, 0x010 } }, /* depthHack */
    { str_0021a04c, { 0, 0x020 } }, /* setShaderTime */
    { str_0021a05c, { 0, 0x040 } }, /* useModel */
    { str_00219fd0, { 0, 0x080 } }, /* orgOnCylinder (was attr→spawn) */
    { str_00219fe0, { 0, 0x100 } }, /* axisFromSphere (was attr→spawn) */
    { str_00219ff0, { 0, 0x200 } }, /* randrotaroundfwd (was attr→spawn) */
    { str_0021a088, { 0, 0x400 } }, /* impactFx */
    { str_0021a094, { 0, 0x800 } }, /* deathFx */
    { str_0021a158, { 0, 0x1000 } }, /* emitFx (reuse) */
};
char fx_time_dst1[64] __attribute__((aligned(4))) = {0};
char fx_time_dst2[64] __attribute__((aligned(4))) = {0};
char fx_time_src1[64] __attribute__((aligned(4))) = {0};
char fx_time_src2[64] __attribute__((aligned(4))) = {0};
/* g_backEndData: decompiler alias for imp_dxState — now a symbol alias in import_pointers.S */
/* g_banIPs_dvar: aliased to g_banIPs in import_pointers.S */
/* g_bobMax_ptr: alias for imp_bg_bobMax — defined in import_pointers.S */
char g_cheats_dvar[64] __attribute__((aligned(4))) = {0};
char g_clients_ptr[64] __attribute__((aligned(4))) = {0};
char g_creatingTexture[64] __attribute__((aligned(4))) = {0};
char g_deadChat_ptr[64] __attribute__((aligned(4))) = {0};
/* g_debug_damage_ptr: alias for imp_g_debugDamage — defined in import_pointers.S */
/* g_drawSurf: decompiler alias for imp_tess — now a symbol alias in import_pointers.S */
/* g_dx: decompiler alias for BSS 'dx' — now a symbol alias in stubs/symbol_aliases.S */
/* g_dxCaps: decompiler alias for BSS 'r_rendererInUse' — now a symbol alias in stubs/symbol_aliases.S */
/* g_dxIter: decompiler alias for 'alwaysfails' — now a symbol alias in stubs/symbol_aliases.S */
char g_enemylookDist[64] __attribute__((aligned(4))) = {0};
/* g_entities_ptr: alias defined in literals.S as .set g_entities_ptr, g_entities */
char GetAvailableWindowPositioningBounds[64] __attribute__((aligned(4))) = {0};
char GetComponentVersion[64] __attribute__((aligned(4))) = {0};
char GetCurrentKeyModifiers[64] __attribute__((aligned(4))) = {0};
char GetCurrentProcess[64] __attribute__((aligned(4))) = {0};
char GetCursor[64] __attribute__((aligned(4))) = {0};
char GetGlobalMouse[64] __attribute__((aligned(4))) = {0};
char GetGWorldPixMap[64] __attribute__((aligned(4))) = {0};
char GetHandleSize[64] __attribute__((aligned(4))) = {0};
char GetIconRefFromFileInfo[64] __attribute__((aligned(4))) = {0};
char GetMainEventLoop[64] __attribute__((aligned(4))) = {0};
char GetMainEventQueue[64] __attribute__((aligned(4))) = {0};
char GetMediaDuration[64] __attribute__((aligned(4))) = {0};
char GetMediaHandler[64] __attribute__((aligned(4))) = {0};
char GetMediaSampleDescription[64] __attribute__((aligned(4))) = {0};
char GetMovieDuration[64] __attribute__((aligned(4))) = {0};
char GetMovieIndTrackType[64] __attribute__((aligned(4))) = {0};
char GetMoviePreferredRate[64] __attribute__((aligned(4))) = {0};
char GetMovieTime[64] __attribute__((aligned(4))) = {0};
char GetMovieTimeScale[64] __attribute__((aligned(4))) = {0};
char GetNextProcess[64] __attribute__((aligned(4))) = {0};
char GetPixRowBytes[64] __attribute__((aligned(4))) = {0};
char GetPort[64] __attribute__((aligned(4))) = {0};
char GetProcessBundleLocation[64] __attribute__((aligned(4))) = {0};
char GetProcessInformation[64] __attribute__((aligned(4))) = {0};
char GetQDGlobalsArrow[64] __attribute__((aligned(4))) = {0};
char GetStandardAlertDefaultParams[64] __attribute__((aligned(4))) = {0};
char GetTrackMedia[64] __attribute__((aligned(4))) = {0};
char GetWindowPortBounds[64] __attribute__((aligned(4))) = {0};
char GetWindowResizeLimits[64] __attribute__((aligned(4))) = {0};
char GetWRefCon[64] __attribute__((aligned(4))) = {0};
char g_friendlylookDist[64] __attribute__((aligned(4))) = {0};
/* gfx_buf: decompiler alias for imp_tess — now a symbol alias in import_pointers.S */
char gfxBuf[64] __attribute__((aligned(4))) = {0};
/* gfxScene: decompiler alias for imp_scene — now a symbol alias in import_pointers.S */
char GLOBAL__I__ZN13CMemoryBuffer20sDelayedFreeRequestsE[64] __attribute__((aligned(4))) = {0};
char GoToBeginningOfMovie[64] __attribute__((aligned(4))) = {0};
/* g_password_ptr: alias for imp_g_password — defined in import_pointers.S */
char g_phys_world[64] __attribute__((aligned(4))) = {0};
/* g_renderer_ptr: linker alias to re */
/* g_renderState: decompiler alias for imp_r_fog — now a symbol alias in import_pointers.S */
char g_ri[64] __attribute__((aligned(4))) = {0};
char g_scr_data_ptr[64] __attribute__((aligned(4))) = {0};
void GScr_LoadAnimScripts(void) {}
void GScr_PostResetTimeout(void) {}
char g_sNextDmgTableId[64] __attribute__((aligned(4))) = {0};
void G_SpawnTriggerHurt(void) {}
char g_sv_running_ptr[64] __attribute__((aligned(4))) = {0};
/* g_time: decompiler alias for imp_level_bgs — now a defsym alias */
/* g_time_ptr: decompiler alias for imp_bgs — now a defsym alias */
char g_trace_zero_ptr[64] __attribute__((aligned(4))) = {0};
char g_unknown_195f22c[64] __attribute__((aligned(4))) = {0};
char g_unknown_195f230[64] __attribute__((aligned(4))) = {0};
char g_useActivateHoldTime[64] __attribute__((aligned(4))) = {0};
char g_useActivateReuseTime[64] __attribute__((aligned(4))) = {0};
char g_vidConfig[64] __attribute__((aligned(4))) = {0};
/* g_viewInfo: decompiler alias for imp_r_zfar — now a symbol alias in import_pointers.S */
/* g_viewParms: decompiler alias for imp_backEndData — now a symbol alias in import_pointers.S */
char g_voiceChatsAllowed_ptr[64] __attribute__((aligned(4))) = {0};
char g_voiceChatTalkingDuration_ptr[64] __attribute__((aligned(4))) = {0};
char HandleControlKey[64] __attribute__((aligned(4))) = {0};
char HideControl[64] __attribute__((aligned(4))) = {0};
char HideMenuBar[64] __attribute__((aligned(4))) = {0};
char HITextViewGetTXNObject[64] __attribute__((aligned(4))) = {0};
char HIViewGetRoot[64] __attribute__((aligned(4))) = {0};
char HIViewGetViewForMouseEvent[64] __attribute__((aligned(4))) = {0};
char InitCursor[64] __attribute__((aligned(4))) = {0};
char InsertMediaIntoTrack[64] __attribute__((aligned(4))) = {0};
char InsertMenu[64] __attribute__((aligned(4))) = {0};
char InsetRect[64] __attribute__((aligned(4))) = {0};
char InstallEventLoopTimer[64] __attribute__((aligned(4))) = {0};
char InvalMenuBar[64] __attribute__((aligned(4))) = {0};
char IOBSDNameMatching[64] __attribute__((aligned(4))) = {0};
char IOObjectConformsTo[64] __attribute__((aligned(4))) = {0};
char IOObjectGetClass[64] __attribute__((aligned(4))) = {0};
char IOObjectRetain[64] __attribute__((aligned(4))) = {0};
char IORegistryEntryCreateCFProperty[64] __attribute__((aligned(4))) = {0};
char IORegistryEntryCreateIterator[64] __attribute__((aligned(4))) = {0};
char IORegistryEntryGetParentEntry[64] __attribute__((aligned(4))) = {0};
char IsMovieDone[64] __attribute__((aligned(4))) = {0};
char IsWindowVisible[64] __attribute__((aligned(4))) = {0};
char jpeg_memory_src[64] __attribute__((aligned(4))) = {0};
char kCFAllocatorDefault[64] __attribute__((aligned(4))) = {0};
/* level_ptr: alias defined in literals.S as .set level_ptr, level */
char loadingMessage[64] __attribute__((aligned(4))) = {0};
char LockPixels[64] __attribute__((aligned(4))) = {0};
char LSCopyItemInfoForRef[64] __attribute__((aligned(4))) = {0};
char MapRect[64] __attribute__((aligned(4))) = {0};
char MediaSetSoundBalance[64] __attribute__((aligned(4))) = {0};
/* __mh_execute_header is linker --defsym=0x1000 */
char MoveWindow[64] __attribute__((aligned(4))) = {0};
char MoviesTask[64] __attribute__((aligned(4))) = {0};
char name[64] __attribute__((aligned(4))) = {0};
/* net_profile_dvar: alias for imp_net_profile — defined in import_pointers.S */
char NewControlEditTextValidationUPP[64] __attribute__((aligned(4))) = {0};
char NewControlKeyFilterUPP[64] __attribute__((aligned(4))) = {0};
char NewControlUserPaneDrawUPP[64] __attribute__((aligned(4))) = {0};
char NewControlUserPaneHitTestUPP[64] __attribute__((aligned(4))) = {0};
char NewControlUserPaneTrackingUPP[64] __attribute__((aligned(4))) = {0};
char NewGWorld[64] __attribute__((aligned(4))) = {0};
char NewHandle[64] __attribute__((aligned(4))) = {0};
char NewMenu[64] __attribute__((aligned(4))) = {0};
char NewMovieFromFile[64] __attribute__((aligned(4))) = {0};
char NewRgn[64] __attribute__((aligned(4))) = {0};
/* nextmap_dvar: alias for imp_nextmap — defined in import_pointers.S */
char NormalizeThemeDrawingState[64] __attribute__((aligned(4))) = {0};
char OffsetRect[64] __attribute__((aligned(4))) = {0};
char OpenAComponent[64] __attribute__((aligned(4))) = {0};
char OpenComponent[64] __attribute__((aligned(4))) = {0};
char OpenMovieFile[64] __attribute__((aligned(4))) = {0};
char OpenRgn[64] __attribute__((aligned(4))) = {0};
char PaintRect[64] __attribute__((aligned(4))) = {0};
char PaintRoundRect[64] __attribute__((aligned(4))) = {0};
char PBGetCatInfoSync[64] __attribute__((aligned(4))) = {0};
char PBHGetVolParmsSync[64] __attribute__((aligned(4))) = {0};
/* playerCorpseInfo_ptr: alias defined in literals.S as .set playerCorpseInfo_ptr, g_scr_data */
char PlotIconRef[64] __attribute__((aligned(4))) = {0};
char PostEventToQueue[64] __attribute__((aligned(4))) = {0};
char pPriorityMap[64] __attribute__((aligned(4))) = {0};
char pPriorityMapAlt[64] __attribute__((aligned(4))) = {0};
char PrerollMovie[64] __attribute__((aligned(4))) = {0};
char PtInRect[64] __attribute__((aligned(4))) = {0};
/* ptr_195ecb4 = Mac GOT entry for legacyHacks (double-deref pattern, stores &legacyHacks) */
__asm__(".section .data\n.globl ptr_195ecb4\nptr_195ecb4: .long legacyHacks\n.space 60\n.previous\n");
/* ptr_195ecbc = Mac GOT entry for com_sv_running (double-deref pattern, stores &com_sv_running) */
__asm__(".section .data\n.globl ptr_195ecbc\nptr_195ecbc: .long com_sv_running\n.space 60\n.previous\n");
char ptr_195eea4[64] __attribute__((aligned(4))) = {0};
char ptr_195f58c[64] __attribute__((aligned(4))) = {0};
char ptr_195f5e0[64] __attribute__((aligned(4))) = {0};
char QDGlobalToLocalPoint[64] __attribute__((aligned(4))) = {0};
char QDLocalToGlobalPoint[64] __attribute__((aligned(4))) = {0};
char QDRegisterNamedPixMapCursor[64] __attribute__((aligned(4))) = {0};
char QDSetNamedPixMapCursor[64] __attribute__((aligned(4))) = {0};
char QuitAppModalLoopForWindow[64] __attribute__((aligned(4))) = {0};
char rcon_password_dvar[64] __attribute__((aligned(4))) = {0};
/* r_contentmask: alias for imp_vec3_origin — defined in import_pointers.S */
/* r_defaultColor: alias for imp_colorWhite — defined in import_pointers.S */
/* r_device_ptr: decompiler alias for BSS 'r_rendererInUse' — now a symbol alias in stubs/symbol_aliases.S */
/* r_dvar_ef30: alias for imp_r_lightTweakSunColor — defined in import_pointers.S */
/* r_dvar_ef34: alias for imp_r_lightTweakDiffuseFraction — defined in import_pointers.S */
/* r_dvar_ef38: alias for imp_r_lightTweakAmbient — defined in import_pointers.S */
/* r_dvar_ef3c: alias for imp_r_lightTweakAmbientColor — defined in import_pointers.S */
/* r_dvar_ef44: alias for imp_r_lightTweakSunDiffuseColor — defined in import_pointers.S */
/* r_dvar_ef48: alias for imp_r_lightTweakSunLight — defined in import_pointers.S */
/* r_dvar_ef4c: alias for imp_r_lightTweakSunDirection — defined in import_pointers.S */
/* r_dvar_sunEnable: alias for imp_r_drawSun — defined in import_pointers.S */
char record_callback_ptr[64] __attribute__((aligned(4))) = {0};
char ReleaseEvent[64] __attribute__((aligned(4))) = {0};
char ReleaseIconRef[64] __attribute__((aligned(4))) = {0};
char re_ptr_195eca8[64] __attribute__((aligned(4))) = {0};
void RestoreBody(void) {}
/* r_frontEndDataOut: alias for imp_backEnd — defined in import_pointers.S */
/* r_frontEndData_ptr: linker alias to rg */
char r_gammaSetting[64] __attribute__((aligned(4))) = {0};
char RGBForeColor[64] __attribute__((aligned(4))) = {0};
/* r_glob: alias for imp_rgp — defined in import_pointers.S */
extern unsigned char rgp[];
void *r_glob_ptr = (void *)rgp;
/* r_lightGridContrast: alias to imp_r_vc_makelog in import_pointers.S */
/* r_lightGridEnableTweaks: alias for imp_r_showLightGrid — defined in import_pointers.S */
/* r_lightGridSpread: alias for imp_r_vc_showlog — defined in import_pointers.S */
/* r_lightGridSunDir: alias for imp_vec3_colorintensity — defined in import_pointers.S */
/* r_lightGridUseTweakedValues: alias for imp_r_showMissingLightGrid — defined in import_pointers.S */
/* r_limits_ptr: linker alias to vidConfig */
char R_LoadSun_f[64] __attribute__((aligned(4))) = {0};
char r_occlusionQuery[64] __attribute__((aligned(4))) = {0};
char r_phys[64] __attribute__((aligned(4))) = {0};
char R_ReloadMaterialTextures_f[64] __attribute__((aligned(4))) = {0};
/* r_rendererGlob: decompiler alias for BSS 'r_rendererInUse' — now a symbol alias in stubs/symbol_aliases.S */
char R_SaveSun_f[64] __attribute__((aligned(4))) = {0};
char R_SmcFlush_f[64] __attribute__((aligned(4))) = {0};
char R_SmcStats_f[64] __attribute__((aligned(4))) = {0};
/* r_sundvar_table: alias for imp_s_sundvars — defined in import_pointers.S */
/* r_sunFlareState: alias for imp_sunFlareArray — defined in import_pointers.S */
/* r_surftype_table_ptr: alias for imp_infoParms — defined in import_pointers.S */
/* r_sys_ptr: linker alias to ri */
char RunAppModalLoopForWindow[64] __attribute__((aligned(4))) = {0};
char RunStandardAlert[64] __attribute__((aligned(4))) = {0};
/* r_videoConfig: alias for imp_vidConfig — defined in import_pointers.S */
/* r_vtable_ptr: alias for imp_ri — defined in import_pointers.S */
/* r_world_ptr: alias for imp_vec3_origin — defined in import_pointers.S */
/* scrAnimPub_ptr: linker alias to scrAnimPub */
void Scr_BeginLoadAnimScripts(void) {}
/* scrCompGlob_ptr: replaced by imp_scrCompileGlob in import_pointers.S */
/* scrCompPub_ptr: linker alias to scrCompilePub */
/* scr_const_ptr: alias defined in literals.S as .set scr_const_ptr, scr_const */
void Scr_EndLoadAnimScripts(void) {}
/* scrParserPub_ptr: linker alias to scrParserPub */
char scrPlace[64] __attribute__((aligned(4))) = {0};
char SetClip[64] __attribute__((aligned(4))) = {0};
char SetControlData[64] __attribute__((aligned(4))) = {0};
char SetControlFontStyle[64] __attribute__((aligned(4))) = {0};
char SetControlMaximum[64] __attribute__((aligned(4))) = {0};
char SetControlReference[64] __attribute__((aligned(4))) = {0};
char SetCursor[64] __attribute__((aligned(4))) = {0};
char SetEventParameter[64] __attribute__((aligned(4))) = {0};
char SetKeyboardFocus[64] __attribute__((aligned(4))) = {0};
char SetMovieRate[64] __attribute__((aligned(4))) = {0};
char SetMovieTimeValue[64] __attribute__((aligned(4))) = {0};
char SetPort[64] __attribute__((aligned(4))) = {0};
char SetPortWindowPort[64] __attribute__((aligned(4))) = {0};
char SetSystemUIMode[64] __attribute__((aligned(4))) = {0};
char SetThemeCursor[64] __attribute__((aligned(4))) = {0};
char SetTrackVolume[64] __attribute__((aligned(4))) = {0};
char SetWindowContentColor[64] __attribute__((aligned(4))) = {0};
char SetWindowResizeLimits[64] __attribute__((aligned(4))) = {0};
char SetWindowTitleWithCFString[64] __attribute__((aligned(4))) = {0};
char SetWRefCon[64] __attribute__((aligned(4))) = {0};
char ShowControl[64] __attribute__((aligned(4))) = {0};
char ShowMenuBar[64] __attribute__((aligned(4))) = {0};
/* showpackets_dvar: alias for imp_showpackets — defined in import_pointers.S */
char SizeWindow[64] __attribute__((aligned(4))) = {0};
/* sm_dvar_ptr: alias for imp_com_statmon — defined in import_pointers.S */
/* sm_mtl_init: alias for imp_cls — defined in import_pointers.S */
/* sm_mtl_vtable: alias for imp_re — defined in import_pointers.S */
char _snd_local_listener[64] __attribute__((aligned(4))) = {0};
char speex_nb_mode_ptr[64] __attribute__((aligned(4))) = {0};
char speex_quality_ptr[64] __attribute__((aligned(4))) = {0};
char speex_uwb_mode_ptr[64] __attribute__((aligned(4))) = {0};
char speex_wb_mode_ptr[64] __attribute__((aligned(4))) = {0};
char StartMovie[64] __attribute__((aligned(4))) = {0};
char StopMovie[64] __attribute__((aligned(4))) = {0};
/* sv_allowAnonymous_dvar: alias for imp_sv_allowAnonymous — defined in import_pointers.S */
/* sv_allowDownload_dvar: alias for imp_sv_allowDownload — defined in import_pointers.S */
/* sv_allowedClan1_dvar: alias for imp_sv_allowedClan1 — defined in import_pointers.S */
/* sv_allowedClan2_dvar: alias for imp_sv_allowedClan2 — defined in import_pointers.S */
/* sv_cheats_dvar: alias for imp_sv_cheats — defined in import_pointers.S */
char sv_cheats_ptr[64] __attribute__((aligned(4))) = {0};
char s_vc_logCount[64] __attribute__((aligned(4))) = {0};
char sv_com_dvarDump_ptr[64] __attribute__((aligned(4))) = {0};
/* sv_debugRate_dvar: alias for imp_sv_debugRate — defined in import_pointers.S */
/* sv_debugReliableCmds_dvar: alias for imp_sv_debugReliableCmds — defined in import_pointers.S */
/* sv_dedicated_dvar: alias for imp_com_dedicated — defined in import_pointers.S */
char sv_dedicated_dvar2[64] __attribute__((aligned(4))) = {0};
/* sv_disableClientConsole_dvar: alias for imp_sv_disableClientConsole — defined in import_pointers.S */
/* sv_expectedHunkUsage_dvar: alias for imp_com_expectedHunkUsage — defined in import_pointers.S */
/* sv_floodProtect_dvar: alias for imp_sv_floodProtect — defined in import_pointers.S */
/* sv_fps_dvar: alias for imp_sv_fps — defined in import_pointers.S */
/* sv_gametype_dvar: alias for imp_sv_gametype — defined in import_pointers.S */
/* sv_hostname_dvar: alias for imp_sv_hostname — defined in import_pointers.S */
/* sv_iwdNames_dvar: alias for imp_sv_iwdNames — defined in import_pointers.S */
/* sv_iwds_dvar: alias for imp_sv_iwds — defined in import_pointers.S */
/* sv_kickBanTime_dvar: alias for imp_sv_kickBanTime — defined in import_pointers.S */
/* sv_mapname_dvar: alias for imp_sv_mapname — defined in import_pointers.S */
/* sv_mapRotationCurrent_dvar: alias for imp_sv_mapRotationCurrent — defined in import_pointers.S */
/* sv_mapRotation_dvar: alias for imp_sv_mapRotation — defined in import_pointers.S */
/* sv_maxclients_dvar: alias for imp_sv_maxclients — defined in import_pointers.S */
/* sv_maxPing_dvar: alias for imp_sv_maxPing — defined in import_pointers.S */
/* sv_maxRate_dvar: alias for imp_sv_maxRate — defined in import_pointers.S */
/* sv_minPing_dvar: alias for imp_sv_minPing — defined in import_pointers.S */
/* sv_minPingRate_dvar: alias for imp_sv_maxRate — defined in import_pointers.S */
/* sv_packet_info_dvar: alias for imp_sv_packet_info — defined in import_pointers.S */
/* sv_padPackets_dvar: alias for imp_sv_padPackets — defined in import_pointers.S */
/* sv_privateClients_dvar: alias for imp_sv_privateClients — defined in import_pointers.S */
char sv_privatePassword_dvar[64] __attribute__((aligned(4))) = {0};
/* sv_ptr: linker alias to sv */
/* sv_pure_dvar: alias for imp_sv_pure — defined in import_pointers.S */
/* sv_reconnectlimit_dvar: alias for imp_sv_reconnectlimit — defined in import_pointers.S */
/* sv_referencedIwdNames_dvar: alias for imp_sv_referencedIwdNames — defined in import_pointers.S */
/* sv_referencedIwds_dvar: alias for imp_sv_referencedIwds — defined in import_pointers.S */
/* sv_running_dvar: alias for imp_com_sv_running — defined in import_pointers.S */
/* sv_serverid_dvar: alias for imp_sv_serverid — defined in import_pointers.S */
/* sv_showAverageBPS_dvar: alias for imp_sv_showAverageBPS — defined in import_pointers.S */
char sv_showcommands_dvar[64] __attribute__((aligned(4))) = {0};
/* sv_showCommands_dvar: alias for imp_sv_showCommands — defined in import_pointers.S */
/* svs_ptr: linker alias to svs */
/* sv_timeout_dvar: alias for imp_sv_timeout — defined in import_pointers.S */
/* sv_voice_dvar: alias for imp_sv_voice — defined in import_pointers.S */
/* sv_voiceQuality_dvar: alias for imp_sv_voiceQuality — defined in import_pointers.S */
/* sv_zombietime_dvar: alias for imp_sv_zombietime — defined in import_pointers.S */
char tr[64] __attribute__((aligned(4))) = {0};
/* trace_mins: alias for imp_vec3_origin — defined in import_pointers.S */
char TXNSetTypeAttributes[64] __attribute__((aligned(4))) = {0};
char UI_Component_g[64] __attribute__((aligned(4))) = {0};
char ui_globals_195ecac[64] __attribute__((aligned(4))) = {0};
char uiInfo_ptr[64] __attribute__((aligned(4))) = {0};
char ui_maxclients_195ecc0[64] __attribute__((aligned(4))) = {0};
char ui_vtable_195eca8[64] __attribute__((aligned(4))) = {0};
char vec3_origin_ptr[64] __attribute__((aligned(4))) = {0};
char version[64] __attribute__((aligned(4))) = {0};
char voice_freq_ptr[64] __attribute__((aligned(4))) = {0};
char voice_maxframe_ptr[64] __attribute__((aligned(4))) = {0};
char voice_scale_ptr[64] __attribute__((aligned(4))) = {0};
char WaitNextEvent[64] __attribute__((aligned(4))) = {0};
