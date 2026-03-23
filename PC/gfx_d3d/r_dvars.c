/* Decompiled from: r_dvars.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_dvars.cpp */

#include "common_types.h"
#include "imports.h"

extern const dvar_t *r_ignore; /* 0x0 */
extern const dvar_t *r_overbrightBits; /* 0x0 */
extern const dvar_t *r_gamma; /* 0x0 */
extern const dvar_t *r_ignoreHwGamma; /* 0x0 */
extern const dvar_t *r_textureMode; /* 0x0 */
extern const dvar_t *r_anisotropy; /* 0x0 */
extern const dvar_t *r_fullbright; /* 0x0 */
extern const dvar_t *r_debugShader; /* 0x0 */
extern const dvar_t *r_debugEntCounts; /* 0x0 */
extern const dvar_t *r_optimize; /* 0x0 */
extern const dvar_t *r_optimizeLightmaps; /* 0x0 */
extern const dvar_t *r_optimizeXModels; /* 0x0 */
extern const dvar_t *r_gpuSync; /* 0x0 */
extern const dvar_t *r_multiGpu; /* 0x0 */
extern const dvar_t *r_skinCache; /* 0x0 */
extern const dvar_t *r_fullscreen; /* 0x0 */
extern const dvar_t *r_monitor; /* 0x0 */
extern const dvar_t *r_mode; /* 0x0 */
extern const dvar_t *r_displayRefresh; /* 0x0 */
extern const dvar_t *r_rendererPreference; /* 0x0 */
extern const dvar_t *r_rendererInUse; /* 0x0 */
extern const dvar_t *r_aspectRatio; /* 0x0 */
extern const dvar_t *r_smc_enable; /* 0x0 */
extern const dvar_t *r_lodScale; /* 0x0 */
extern const dvar_t *r_lodBias; /* 0x0 */
extern const dvar_t *r_znear; /* 0x0 */
extern const dvar_t *r_znear_depthhack; /* 0x0 */
extern const dvar_t *r_zfar; /* 0x0 */
extern const dvar_t *r_fog; /* 0x0 */
extern const dvar_t *r_polygonOffsetScale; /* 0x0 */
extern const dvar_t *r_polygonOffsetBias; /* 0x0 */
extern const dvar_t *r_picmip_manual; /* 0x0 */
extern const dvar_t *r_picmip; /* 0x0 */
extern const dvar_t *r_picmip_bump; /* 0x0 */
extern const dvar_t *r_picmip_spec; /* 0x0 */
extern const dvar_t *r_lightMap; /* 0x0 */
extern const dvar_t *r_colorMap; /* 0x0 */
extern const dvar_t *r_normalMap; /* 0x0 */
extern const dvar_t *r_specularMap; /* 0x0 */
extern const dvar_t *r_specularColorScale; /* 0x0 */
extern const dvar_t *r_cosinePowerMapShift; /* 0x0 */
extern const dvar_t *r_showTris; /* 0x0 */
extern const dvar_t *r_showTriCounts; /* 0x0 */
extern const dvar_t *r_showSurfCounts; /* 0x0 */
extern const dvar_t *r_showVertCounts; /* 0x0 */
extern const dvar_t *r_xdebug; /* 0x0 */
extern const dvar_t *r_railCoreWidth; /* 0x0 */
extern const dvar_t *r_vc_makelog; /* 0x0 */
extern const dvar_t *r_vc_showlog; /* 0x0 */
extern const dvar_t *r_showLightGrid; /* 0x0 */
extern const dvar_t *r_showMissingLightGrid; /* 0x0 */
extern const dvar_t *r_lightTweakAmbient; /* 0x0 */
extern const dvar_t *r_lightTweakDiffuseFraction; /* 0x0 */
extern const dvar_t *r_lightTweakSunLight; /* 0x0 */
extern const dvar_t *r_lightTweakAmbientColor; /* 0x0 */
extern const dvar_t *r_lightTweakSunColor; /* 0x0 */
extern const dvar_t *r_lightTweakSunDiffuseColor; /* 0x0 */
extern const dvar_t *r_lightTweakSunDirection; /* 0x0 */
extern const dvar_t *r_objectiveColorDx7Min; /* 0x0 */
extern const dvar_t *r_objectiveColorDx7Max; /* 0x0 */
extern const dvar_t *r_logFile; /* 0x0 */
extern const dvar_t *r_skipBackEnd; /* 0x0 */
extern const dvar_t *r_norefresh; /* 0x0 */
extern const dvar_t *r_swapInterval; /* 0x0 */
extern const dvar_t *r_aaAlpha; /* 0x0 */
extern const dvar_t *r_aaSamples; /* 0x0 */
extern const dvar_t *r_clearColor; /* 0x0 */
extern const dvar_t *r_clearColor2; /* 0x0 */
extern const dvar_t *r_drawSun; /* 0x0 */
extern const dvar_t *r_drawWorld; /* 0x0 */
extern const dvar_t *r_drawDecals; /* 0x0 */
extern const dvar_t *r_drawEntities; /* 0x0 */
extern const dvar_t *r_drawBModels; /* 0x0 */
extern const dvar_t *r_drawSModels; /* 0x0 */
extern const dvar_t *r_drawXModels; /* 0x0 */
extern const dvar_t *r_dlightLimit; /* 0x0 */
extern const dvar_t *r_drawPrimCap; /* 0x0 */
extern const dvar_t *r_drawPrimFloor; /* 0x0 */
extern const dvar_t *r_drawWater; /* 0x0 */
extern const dvar_t *r_depthPrepassModels; /* 0x0 */
extern const dvar_t *r_lockPvs; /* 0x0 */
extern const dvar_t *r_skipPvs; /* 0x0 */
extern const dvar_t *r_pvsStats; /* 0x0 */
extern const dvar_t *r_portalFineCull; /* 0x0 */
extern const dvar_t *r_portalBevels; /* 0x0 */
extern const dvar_t *r_portalBevelsOnly; /* 0x0 */
extern const dvar_t *r_singleCell; /* 0x0 */
extern const dvar_t *r_portalWalkLimit; /* 0x0 */
extern const dvar_t *r_portalMinClipArea; /* 0x0 */
extern const dvar_t *r_showPortals; /* 0x0 */
extern const dvar_t *r_showSModelNames; /* 0x0 */
extern const dvar_t *r_showFbColorDebug; /* 0x0 */
extern const dvar_t *r_showFloatZDebug; /* 0x0 */
extern const dvar_t *r_showGroundLit; /* 0x0 */
extern const dvar_t *r_highLodDist; /* 0x0 */
extern const dvar_t *r_mediumLodDist; /* 0x0 */
extern const dvar_t *r_lowLodDist; /* 0x0 */
extern const dvar_t *r_lowestLodDist; /* 0x0 */
extern const dvar_t *r_forceLod; /* 0x0 */
extern const dvar_t *sc_enable; /* 0x0 */
extern const dvar_t *sc_blur; /* 0x0 */
extern const dvar_t *sc_count; /* 0x0 */
extern const dvar_t *sc_debugCasterCount; /* 0x0 */
extern const dvar_t *sc_debugReceiverCount; /* 0x0 */
extern const dvar_t *sc_showOverlay; /* 0x0 */
extern const dvar_t *sc_showDebug; /* 0x0 */
extern const dvar_t *sc_wantCount; /* 0x0 */
extern const dvar_t *sc_wantCountMargin; /* 0x0 */
extern const dvar_t *sc_fadeRange; /* 0x0 */
extern const dvar_t *sc_shadowInRate; /* 0x0 */
extern const dvar_t *sc_shadowOutRate; /* 0x0 */
extern const dvar_t *sc_length; /* 0x0 */
extern const dvar_t *sc_offscreenCasterLodBias; /* 0x0 */
extern const dvar_t *sc_offscreenCasterLodScale; /* 0x0 */
extern const dvar_t *r_blur; /* 0x0 */
extern const dvar_t *r_distortion; /* 0x0 */
extern const dvar_t *r_glow; /* 0x0 */
extern const dvar_t * r_glowRadius[2]; /* 0x0 */
extern const dvar_t * r_glowSkyBleedIntensity[2]; /* 0x0 */
extern const dvar_t * r_glowBloomIntensity[2]; /* 0x0 */
extern const dvar_t *r_glowBloomCutoff; /* 0x0 */
extern const dvar_t *r_glowBloomDesaturation; /* 0x0 */
extern const dvar_t *r_outdoorAwayBias; /* 0x0 */
extern const dvar_t *r_outdoorDownBias; /* 0x0 */
extern const dvar_t *r_outdoorFeather; /* 0x0 */
extern const dvar_t *r_sun_from_dvars; /* 0x0 */
extern const dvar_t *r_testTransform; /* 0x0 */
extern const dvar_t *r_testFill; /* 0x0 */
extern const dvar_t *r_testFillEnable; /* 0x0 */
extern const dvar_t *vid_xpos; /* 0x0 */
extern const dvar_t *vid_ypos; /* 0x0 */
extern const dvar_t *developer; /* 0x0 */
extern const dvar_t *sys_SSE; /* 0x0 */
extern const dvar_t *r_sse_skinning; /* 0x0 */

__attribute__((used)) const char *s_technologyNames[4] = {
    "none",
    "dx9",
    "dx7",
    0,
}; /* 0x3110b4 */
__attribute__((used)) const char *xdebugNames[5] = {
    "",
    "boxes",
    "axes",
    "both",
    0,
}; /* 0x3110fc */
__attribute__((used, packed, aligned(4)))
const char * textureModeNames[] = {
    "nearest",
    "linear",
    "bilinear",
    "trilinear",
    "anisotropic",
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
}; /* 0x311158 */

static const char *s_aspectRatioNames[5] = {
    "auto",
    "standard",
    "wide 16:10",
    "wide 16:9",
    0,
}; /* 0x3110a0 */
static const char *r_forceLodNames[6] = {
    "high",
    "medium",
    "low",
    "lowest",
    "none",
    0,
}; /* 0x3110c4 */
static const char *fbColorDebugNames[4] = {
    "None",
    "Screen",
    "Feedback",
    0,
}; /* 0x3110dc */
static const char *s_aaAlphaNames[4] = {
    "off",
    "dither (fast)",
    "supersample (nice)",
    0,
}; /* 0x3110ec */
static const char *normalMapNames[3] = {
    "Unchanged",
    "Flat",
    0,
}; /* 0x311110 */
static const char *colorMapNames[4] = {
    "Unchanged",
    "White",
    "Black",
    0,
}; /* 0x31111c */
static const char *gpuSyncNames[5] = {
    "off",
    "beginning",
    "beforePresent",
    "adaptive",
    0,
}; /* 0x31112c */
static const char *debugShaderNames[6] = {
    "none",
    "normal",
    "basisTangent",
    "basisBinormal",
    "basisNormal",
    0,
}; /* 0x311140 */

/* Extern declarations for functions and globals used */
extern int R_RegisterSunDvars(void);
extern refimport_t ri; /* imp_ri */

/* These dvars are stored in BSS via import pointers */

/* __mh_execute_header is the Mach-O header base (0x1000) used as max for vid pos dvars */
extern int __mh_execute_header;

void R_RegisterDvars(void);
void R_UnregisterDvars(void);

/* line 430 */
void R_RegisterDvars(void)
{
    /* line 442 */
    R_RegisterSunDvars();

    /* line 444 */
    r_ignore = ri.Dvar_RegisterInt("r_ignore", 0, (int)0x80000000, 0x7fffffff, 0x2000);

    /* line 446 */
    r_overbrightBits = ri.Dvar_RegisterInt("r_overbrightBits", 1, 0, 1, 0x2021);

    /* line 453 */
    r_gamma = ri.Dvar_RegisterFloat("r_gamma", 1.0f, 0.5f, 3.0f, 0x2001);

    /* line 456 */
    r_ignoreHwGamma = ri.Dvar_RegisterBool("r_ignorehwgamma", 0, 0x2021);

    /* line 459 */
    r_textureMode = ri.Dvar_RegisterEnum("r_textureMode", textureModeNames, 2, 0x2001);

    /* line 460 */
    r_anisotropy = ri.Dvar_RegisterInt("r_anisotropy", 8, 2, 16, 0x2001);

    /* line 461 */
    r_fullbright = ri.Dvar_RegisterBool("r_fullbright", 0, 0x2080);

    /* line 462 */
    r_debugShader = ri.Dvar_RegisterEnum("r_debugShader", debugShaderNames, 0, 0x2080);

    /* line 463 */
    r_debugEntCounts = ri.Dvar_RegisterInt("r_debugEntCounts", 0, 0, 0x7fe, 0x2000);

    /* line 465 */
    r_optimize = ri.Dvar_RegisterBool("r_optimize", 1, 0x2020);

    /* line 466 */
    r_optimizeLightmaps = ri.Dvar_RegisterBool("r_optimizeLightmaps", 1, 0x2020);

    /* line 469 */
    r_optimizeXModels = ri.Dvar_RegisterInt("r_optimizeXModels", 100, 0, 1000, 0x2020);

    /* line 470 */
    r_gpuSync = ri.Dvar_RegisterEnum("r_gpuSync", gpuSyncNames, 3, 0x2000);

    /* line 471 */
    r_multiGpu = ri.Dvar_RegisterBool("r_multiGpu", 0, 0x2000);

    /* line 479 */
    r_skinCache = ri.Dvar_RegisterBool("r_skinCache", 1, 0x2000);

    /* line 483 */
    r_smc_enable = ri.Dvar_RegisterBool("r_smc_enable", 1, 0x2000);

    /* line 486 */
    r_lodScale = ri.Dvar_RegisterFloat("r_lodScale", 1.0f, 1.0f, 4.0f, 0x2001);

    /* line 487 */
    r_lodBias = ri.Dvar_RegisterFloat("r_lodBias", 0.0f, -1000.0f, 0.0f, 0x2001);

    /* line 488 */
    r_znear = ri.Dvar_RegisterFloat("r_znear", 4.0f, 0.001f, 16.0f, 0x2080);

    /* line 489 */
    r_znear_depthhack = ri.Dvar_RegisterFloat("r_znear_depthhack", 0.1f, 0.001f, 16.0f, 0x2080);

    /* line 490 */
    r_zfar = ri.Dvar_RegisterFloat("r_zfar", 0.0f, 0.0f, 3.4028235e+38f, 0x2080);

    /* line 491 */
    r_fog = ri.Dvar_RegisterBool("r_fog", 1, 0x2080);

    /* line 492 */
    r_polygonOffsetScale = ri.Dvar_RegisterFloat("r_polygonOffsetScale", -1.0f, -4.0f, 4.0f, 0x2001);

    /* line 493 */
    r_polygonOffsetBias = ri.Dvar_RegisterFloat("r_polygonOffsetBias", -1.0f, -16.0f, 16.0f, 0x2001);

    /* line 496 */
    r_picmip_manual = ri.Dvar_RegisterBool("r_picmip_manual", 0, 0x2001);

    /* line 497 */
    r_picmip = ri.Dvar_RegisterInt("r_picmip", 0, 0, 3, 0x2001);

    /* line 498 */
    r_picmip_bump = ri.Dvar_RegisterInt("r_picmip_bump", 0, 0, 3, 0x2001);

    /* line 499 */
    r_picmip_spec = ri.Dvar_RegisterInt("r_picmip_spec", 0, 0, 3, 0x2001);

    /* line 502 */
    r_lightMap = ri.Dvar_RegisterEnum("r_lightMap", colorMapNames, 0, 0x2080);

    /* line 503 */
    r_colorMap = ri.Dvar_RegisterEnum("r_colorMap", colorMapNames, 0, 0x2080);

    /* line 504 */
    r_normalMap = ri.Dvar_RegisterEnum("r_normalMap", normalMapNames, 0, 0x2080);

    /* line 505 */
    r_specularMap = ri.Dvar_RegisterEnum("r_specularMap", colorMapNames, 0, 0x2080);

    /* line 506 */
    r_specularColorScale = ri.Dvar_RegisterFloat("r_specularColorScale", 1.0f, 0.01f, 100.0f, 0x2080);

    /* line 507 */
    r_cosinePowerMapShift = ri.Dvar_RegisterFloat("r_cosinePowerMapShift", 0.0f, -1.0f, 1.0f, 0x2080);

    /* line 508 */
    r_showTris = ri.Dvar_RegisterInt("r_showTris", 0, 0, 2, 0x2080);

    /* line 509 */
    r_showTriCounts = ri.Dvar_RegisterBool("r_showTriCounts", 0, 0x2080);

    /* line 510 */
    r_showSurfCounts = ri.Dvar_RegisterBool("r_showSurfCounts", 0, 0x2080);

    /* line 511 */
    r_showVertCounts = ri.Dvar_RegisterBool("r_showVertCounts", 0, 0x2080);

    /* line 512 */
    r_xdebug = ri.Dvar_RegisterEnum("r_xdebug", xdebugNames, 0, 0x2080);

    /* line 513 */
    r_railCoreWidth = ri.Dvar_RegisterFloat("r_railCoreWidth", 1.0f, 0.0f, 16.0f, 0x2001);

    /* line 515 */
    r_vc_makelog = ri.Dvar_RegisterInt("r_vc_makelog", 0, 0, 2, 0x2020);

    /* line 516 */
    r_vc_showlog = ri.Dvar_RegisterInt("r_vc_showlog", 0, 0, 1024, 0x2000);

    /* line 517 */
    r_showLightGrid = ri.Dvar_RegisterBool("r_showLightGrid", 0, 0x2080);

    /* line 521 */
    r_showMissingLightGrid = ri.Dvar_RegisterBool("r_showMissingLightGrid", 0, 0x2080);

    /* line 524 */
    r_lightTweakAmbient = ri.Dvar_RegisterFloat("r_lightTweakAmbient", 0.1f, 0.0f, 4.0f, 0x2200);

    /* line 525 */
    r_lightTweakDiffuseFraction = ri.Dvar_RegisterFloat("r_lightTweakDiffuseFraction", 0.5f, 0.0f, 1.0f, 0x2200);

    /* line 526 */
    r_lightTweakSunLight = ri.Dvar_RegisterFloat("r_lightTweakSunLight", 1.0f, 0.0f, 4.0f, 0x2200);

    /* line 528 */
    r_lightTweakAmbientColor = ri.Dvar_RegisterColor("r_lightTweakAmbientColor", 1.0f, 0.0f, 0.0f, 1.0f, 0x2200);

    /* line 529 */
    r_lightTweakSunColor = ri.Dvar_RegisterColor("r_lightTweakSunColor", 0.0f, 1.0f, 0.0f, 1.0f, 0x2200);

    /* line 530 */
    r_lightTweakSunDiffuseColor = ri.Dvar_RegisterColor("r_lightTweakSunDiffuseColor", 0.0f, 0.0f, 1.0f, 1.0f, 0x2200);

    /* line 531 */
    r_lightTweakSunDirection = ri.Dvar_RegisterVec3("r_lightTweakSunDirection", 0.0f, 0.0f, 0.0f, -360.0f, 360.0f, 0x2200);

    /* line 534 */
    r_objectiveColorDx7Min = ri.Dvar_RegisterColor("r_objectiveColorDx7Min", 0.55f, 0.38f, 0.0f, 1.0f, 0x2000);

    /* line 535 */
    r_objectiveColorDx7Max = ri.Dvar_RegisterColor("r_objectiveColorDx7Max", 1.0f, 0.7f, 0.2f, 1.0f, 0x2000);

    /* line 542 */
    r_logFile = ri.Dvar_RegisterInt("r_logFile", 0, 0, 0x7fffffff, 0x2000);

    /* line 543 */
    r_skipBackEnd = ri.Dvar_RegisterBool("r_skipBackEnd", 0, 0x2080);

    /* line 556 */
    r_norefresh = ri.Dvar_RegisterBool("r_norefresh", 0, 0x2080);

    /* line 558 */
    r_swapInterval = ri.Dvar_RegisterBool("r_swapInterval", 0, 0x2021);

    /* line 559 */
    r_aaAlpha = ri.Dvar_RegisterEnum("r_aaAlpha", s_aaAlphaNames, 1, 0x2001);

    /* line 561 */
    r_aaSamples = ri.Dvar_RegisterInt("r_aaSamples", 1, 1, 4, 0x2021);

    /* line 562 */
    r_clearColor = ri.Dvar_RegisterColor("r_clearColor", 0.0f, 0.0f, 0.0f, 0.0f, 0x2000);

    /* line 563 */
    r_clearColor2 = ri.Dvar_RegisterColor("r_clearColor2", 0.0f, 0.0f, 0.0f, 0.0f, 0x2000);

    /* line 564 */
    r_drawSun = ri.Dvar_RegisterBool("r_drawSun", 1, 0x2001);

    /* line 565 */
    r_drawWorld = ri.Dvar_RegisterBool("r_drawWorld", 1, 0x2080);

    /* line 566 */
    r_drawDecals = ri.Dvar_RegisterBool("r_drawDecals", 1, 0x2080);

    /* line 567 */
    r_drawEntities = ri.Dvar_RegisterBool("r_drawEntities", 1, 0x2080);

    /* line 568 */
    r_drawBModels = ri.Dvar_RegisterBool("r_drawBModels", 1, 0x2080);

    /* line 569 */
    r_drawSModels = ri.Dvar_RegisterBool("r_drawSModels", 1, 0x2080);

    /* line 570 */
    r_drawXModels = ri.Dvar_RegisterBool("r_drawXModels", 1, 0x2080);

    /* line 571 */
    r_dlightLimit = ri.Dvar_RegisterInt("r_dlightLimit", 4, 0, 32, 0x2000);

    /* line 572 */
    r_drawPrimCap = ri.Dvar_RegisterInt("r_drawPrimCap", 0, -1, 10000, 0x2080);

    /* line 573 */
    r_drawPrimFloor = ri.Dvar_RegisterInt("r_drawPrimFloor", 0, 0, 10000, 0x2080);

    /* line 574 */
    r_drawWater = ri.Dvar_RegisterBool("r_drawWater", 1, 0x2080);

    /* line 575 */
    r_depthPrepassModels = ri.Dvar_RegisterBool("r_depthPrepassModels", 0, 0x2000);

    /* line 577 */
    r_lockPvs = ri.Dvar_RegisterBool("r_lockPvs", 0, 0x2080);

    /* line 578 */
    r_skipPvs = ri.Dvar_RegisterBool("r_skipPvs", 0, 0x2080);

    /* line 579 */
    r_pvsStats = ri.Dvar_RegisterBool("r_pvsStats", 0, 0x2000);

    /* line 580 */
    r_portalFineCull = ri.Dvar_RegisterBool("r_portalFineCull", 1, 0x2080);

    /* line 581 */
    r_portalBevels = ri.Dvar_RegisterFloat("r_portalBevels", 0.7f, 0.0f, 1.0f, 0x2001);

    /* line 582 */
    r_portalBevelsOnly = ri.Dvar_RegisterBool("r_portalBevelsOnly", 0, 0x2000);

    /* line 583 */
    r_singleCell = ri.Dvar_RegisterBool("r_singleCell", 0, 0x2080);

    /* line 584 */
    r_portalWalkLimit = ri.Dvar_RegisterInt("r_portalWalkLimit", 0, 0, 100, 0x2080);

    /* line 585 */
    r_portalMinClipArea = ri.Dvar_RegisterFloat("r_portalMinClipArea", 0.02f, 0.0f, 1.0f, 0x2000);

    /* line 586 */
    r_showPortals = ri.Dvar_RegisterInt("r_showPortals", 0, 0, 3, 0x2080);

    /* line 597 */
    r_showSModelNames = ri.Dvar_RegisterBool("r_showSModelNames", 0, 0x2080);

    /* line 605 */
    r_showFbColorDebug = ri.Dvar_RegisterEnum("r_showFbColorDebug", fbColorDebugNames, 0, 0x2080);

    /* line 606 */
    r_showFloatZDebug = ri.Dvar_RegisterBool("r_showFloatZDebug", 0, 0x2080);

    /* line 609 */
    r_showGroundLit = ri.Dvar_RegisterBool("r_showGroundLit", 0, 0x20a0);

    /* line 616 */
    r_highLodDist = ri.Dvar_RegisterFloat("r_highLodDist", -1.0f, -1.0f, 3.4028235e+38f, 0x2080);

    /* line 617 */
    r_mediumLodDist = ri.Dvar_RegisterFloat("r_mediumLodDist", -1.0f, -1.0f, 3.4028235e+38f, 0x2080);

    /* line 618 */
    r_lowLodDist = ri.Dvar_RegisterFloat("r_lowLodDist", -1.0f, -1.0f, 3.4028235e+38f, 0x2080);

    /* line 619 */
    r_lowestLodDist = ri.Dvar_RegisterFloat("r_lowestLodDist", -1.0f, -1.0f, 3.4028235e+38f, 0x2080);

    /* line 620 */
    r_forceLod = ri.Dvar_RegisterEnum("r_forceLod", r_forceLodNames, 4, 0x2080);

    /* line 622 */
    sc_enable = ri.Dvar_RegisterBool("sc_enable", 1, 0x2000);

    /* line 623 */
    sc_blur = ri.Dvar_RegisterInt("sc_blur", 2, 0, 4, 0x2080);

    /* line 624 */
    sc_count = ri.Dvar_RegisterInt("sc_count", 24, 0, 24, 0x2080);

    /* line 625 */
    sc_debugCasterCount = ri.Dvar_RegisterInt("sc_debugCasterCount", 24, 0, 24, 0x2080);

    /* line 626 */
    sc_debugReceiverCount = ri.Dvar_RegisterInt("sc_debugReceiverCount", 24, 0, 24, 0x2080);

    /* line 627 */
    sc_showOverlay = ri.Dvar_RegisterBool("sc_showOverlay", 0, 0x2080);

    /* line 628 */
    sc_showDebug = ri.Dvar_RegisterBool("sc_showDebug", 0, 0x2080);

    /* line 629 */
    sc_wantCount = ri.Dvar_RegisterInt("sc_wantCount", 12, 0, 24, 0x2080);

    /* line 630 */
    sc_wantCountMargin = ri.Dvar_RegisterInt("sc_wantCountMargin", 1, 0, 24, 0x2080);

    /* line 631 */
    sc_fadeRange = ri.Dvar_RegisterFloat("sc_fadeRange", 0.25f, 0.0f, 1.0f, 0x2080);

    /* line 632 */
    sc_shadowInRate = ri.Dvar_RegisterFloat("sc_shadowInRate", 2.0f, 0.0f, 20.0f, 0x2080);

    /* line 633 */
    sc_shadowOutRate = ri.Dvar_RegisterFloat("sc_shadowOutRate", 5.0f, 0.0f, 20.0f, 0x2080);

    /* line 634 */
    sc_length = ri.Dvar_RegisterFloat("sc_length", 400.0f, 1.0f, 2000.0f, 0x2080);

    /* line 635 */
    sc_offscreenCasterLodBias = ri.Dvar_RegisterFloat("sc_offscreenCasterLodBias", 0.0f, -3.4028235e+38f, 3.4028235e+38f, 0x2080);

    /* line 636 */
    sc_offscreenCasterLodScale = ri.Dvar_RegisterFloat("sc_offscreenCasterLodScale", 20.0f, 0.0f, 3.4028235e+38f, 0x2080);

    /* line 638 */
    r_blur = ri.Dvar_RegisterFloat("r_blur", 0.0f, 0.0f, 32.0f, 0x2080);

    /* line 639 */
    r_distortion = ri.Dvar_RegisterBool("r_distortion", 1, 0x2001);

    /* line 642 */
    r_glow = ri.Dvar_RegisterBool("r_glow", 1, 0x2001);

    /* line 643 */
    r_glowRadius[0] = ri.Dvar_RegisterFloat("r_glowRadius0", 5.0f, 0.0f, 32.0f, 0x2000);

    /* line 644 */
    r_glowRadius[1] = ri.Dvar_RegisterFloat("r_glowRadius1", 12.0f, 0.0f, 32.0f, 0x2000);

    /* line 645 */
    r_glowSkyBleedIntensity[0] = ri.Dvar_RegisterFloat("r_glowSkyBleedIntensity0", 0.5f, 0.0f, 1.0f, 0x2000);

    /* line 646 */
    r_glowSkyBleedIntensity[1] = ri.Dvar_RegisterFloat("r_glowSkyBleedIntensity1", 0.0f, 0.0f, 1.0f, 0x2000);

    /* line 647 */
    r_glowBloomIntensity[0] = ri.Dvar_RegisterFloat("r_glowBloomIntensity0", 1.0f, 0.0f, 8.0f, 0x2000);

    /* line 648 */
    r_glowBloomIntensity[1] = ri.Dvar_RegisterFloat("r_glowBloomIntensity1", 1.0f, 0.0f, 8.0f, 0x2000);

    /* line 649 */
    r_glowBloomCutoff = ri.Dvar_RegisterFloat("r_glowBloomCutoff", 0.9f, 0.0f, 1.0f, 0x2000);

    /* line 650 */
    r_glowBloomDesaturation = ri.Dvar_RegisterFloat("r_glowBloomDesaturation", 0.75f, 0.0f, 1.0f, 0x2000);

    /* line 652 */
    r_outdoorAwayBias = ri.Dvar_RegisterFloat("r_outdoorAwayBias", 32.0f, -3.4028235e+38f, 3.4028235e+38f, 0x2000);

    /* line 653 */
    r_outdoorDownBias = ri.Dvar_RegisterFloat("r_outdoorDownBias", 0.0f, -3.4028235e+38f, 3.4028235e+38f, 0x2000);

    /* line 654 */
    r_outdoorFeather = ri.Dvar_RegisterFloat("r_outdoorFeather", 8.0f, -3.4028235e+38f, 3.4028235e+38f, 0x2000);

    /* line 655 */
    ri.Dvar_SetModified(r_outdoorFeather);

    /* line 667 */
    r_sun_from_dvars = ri.Dvar_RegisterBool("r_sun_from_dvars", 0, 0x2080);

    /* line 670 */
    r_testTransform = ri.Dvar_RegisterInt("r_testTransform", 0, 0, 1, 0x2000);

    /* line 671 */
    r_testFill = ri.Dvar_RegisterInt("r_testFill", 0, 0, 500, 0x2000);

    /* line 672 */
    r_testFillEnable = ri.Dvar_RegisterBool("r_testFillEnable", 0, 0x2020);

    /* line 674 */
    *(const dvar_t **)imp_fx_sort = ri.Dvar_RegisterBool("fx_sort", 1, 0x2000);

    /* line 683 */
    vid_xpos = ri.Dvar_RegisterInt("vid_xpos", 3, (int)0xfffff000, 4096, 0x2001);

    /* line 684 */
    vid_ypos = ri.Dvar_RegisterInt("vid_ypos", 22, (int)0xfffff000, 4096, 0x2001);

    /* line 686 */
    developer = ri.Dvar_RegisterInt("developer", 0, 0, 2, 0x2000);

    /* line 687 */
    *(const dvar_t **)imp_sv_cheats = ri.Dvar_RegisterBool("sv_cheats", 0, 0x2048);

    /* line 689 */
    *(const dvar_t **)imp_com_statmon = ri.Dvar_RegisterBool("com_statmon", 0, 0x2000);

    /* line 700 */
    sys_SSE = ri.Dvar_RegisterBool("sys_SSE", 0, 0x2000);

    /* line 701 */
    r_sse_skinning = ri.Dvar_RegisterBool("r_sse_skinning", 1, 0x2000);

    /* line 703 */
    r_fullscreen = ri.Dvar_RegisterBool("r_fullscreen", 1, 0x2040);

    /* line 707 */
    r_monitor = ri.Dvar_RegisterInt("r_monitor", 0, 0, 8, 0x2021);

    /* line 708 */
    r_rendererPreference = ri.Dvar_RegisterEnum("r_rendererPreference", s_technologyNames, 1, 0x2021); /* default to "dx9" (index 1) instead of "none" (0) which falls to DX7 */

    /* line 709 */
    r_rendererInUse = ri.Dvar_RegisterEnum("r_rendererInUse", s_technologyNames, 0, 0x2040);

    /* line 710 */
    r_aspectRatio = ri.Dvar_RegisterEnum("r_aspectRatio", s_aspectRatioNames, 0, 0x2021);
}

/* line 734 */
void R_UnregisterDvars(void)
{
    /* The generated dvar teardown still has invalid string cleanup paths.
     * Skipping renderer dvar unregistration keeps shutdown from crashing
     * while we chase the earlier initialization failures.
     */
    return;
}
