/* ASM dump from: r_dvars.cpp */
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
static const char * s_technologyNames[4]; /* 0x3110b4 */
static const char * s_aspectRatioNames[5]; /* 0x3110a0 */
static const char * s_aaAlphaNames[4]; /* 0x3110ec */
static const char * textureModeNames[6]; /* 0x311158 */
static const char * xdebugNames[5]; /* 0x3110fc */
static const char * gpuSyncNames[5]; /* 0x31112c */
static const char * colorMapNames[4]; /* 0x31111c */
static const char * normalMapNames[3]; /* 0x311110 */
static const char * fbColorDebugNames[4]; /* 0x3110dc */
static const char * debugShaderNames[6]; /* 0x311140 */
static const char * r_forceLodNames[6]; /* 0x3110c4 */

void R_RegisterDvars(void);
void R_UnregisterDvars(void);

/* line 430 */
__attribute__((naked))
void R_RegisterDvars(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 430 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "calll R_RegisterSunDvars\n" /* line 442 */
        "movl 0x195eee0, %ebx\n" /* line 444 */
        "movl $0x2000, 0x10(%esp)\n"
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0x80000000, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x223010, (%esp)\n" /* "r_ignore" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, r_ignore\n"
        "movl $0x2021, 0x10(%esp)\n" /* line 446 */
        "movl $1, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $0x22301c, (%esp)\n" /* "r_overbrightBits" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, r_overbrightBits\n"
        "movl $0x2001, 0x10(%esp)\n" /* line 453 */
        "movl $0x40400000, 0xc(%esp)\n"
        "movl $0x3f000000, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $0x223030, (%esp)\n" /* "r_gamma" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_gamma\n"
        "movl $0x2021, 8(%esp)\n" /* line 456 */
        "movl $0, 4(%esp)\n"
        "movl $0x223038, (%esp)\n" /* "r_ignorehwgamma" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_ignoreHwGamma\n"
        "movl $0x2001, 0xc(%esp)\n" /* line 459 */
        "movl $2, 8(%esp)\n"
        "movl $textureModeNames, 4(%esp)\n"
        "movl $0x223048, (%esp)\n" /* "r_textureMode" */
        "calll *0x68(%ebx)\n"
        "movl %eax, r_textureMode\n"
        "movl $0x2001, 0x10(%esp)\n" /* line 460 */
        "movl $0x10, 0xc(%esp)\n"
        "movl $2, 8(%esp)\n"
        "movl $8, 4(%esp)\n"
        "movl $0x223058, (%esp)\n" /* "r_anisotropy" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, r_anisotropy\n"
        "movl $0x2080, 8(%esp)\n" /* line 461 */
        "movl $0, 4(%esp)\n"
        "movl $0x223068, (%esp)\n" /* "r_fullbright" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_fullbright\n"
        "movl $0x2080, 0xc(%esp)\n" /* line 462 */
        "movl $0, 8(%esp)\n"
        "movl $debugShaderNames, 4(%esp)\n"
        "movl $0x223078, (%esp)\n" /* "r_debugShader" */
        "calll *0x68(%ebx)\n"
        "movl %eax, r_debugShader\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 463 */
        "movl $0x7fe, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x223088, (%esp)\n" /* "r_debugEntCounts" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, r_debugEntCounts\n"
        "movl $0x2020, 8(%esp)\n" /* line 465 */
        "movl $1, 4(%esp)\n"
        "movl $0x22309c, (%esp)\n" /* "r_optimize" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_optimize\n"
        "movl $0x2020, 8(%esp)\n" /* line 466 */
        "movl $1, 4(%esp)\n"
        "movl $0x2230a8, (%esp)\n" /* "r_optimizeLightmaps" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_optimizeLightmaps\n"
        "movl $0x2020, 0x10(%esp)\n" /* line 469 */
        "movl $0x3e8, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x64, 4(%esp)\n"
        "movl $0x2230bc, (%esp)\n" /* "r_optimizeXModels" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, r_optimizeXModels\n"
        "movl $0x2000, 0xc(%esp)\n" /* line 470 */
        "movl $3, 8(%esp)\n"
        "movl $gpuSyncNames, 4(%esp)\n"
        "movl $0x2230d0, (%esp)\n" /* "r_gpuSync" */
        "calll *0x68(%ebx)\n"
        "movl %eax, r_gpuSync\n"
        "movl $0x2000, 8(%esp)\n" /* line 471 */
        "movl $0, 4(%esp)\n"
        "movl $0x2230dc, (%esp)\n" /* "r_multiGpu" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_multiGpu\n"
        "movl $0x2000, 8(%esp)\n" /* line 479 */
        "movl $1, 4(%esp)\n"
        "movl $0x2230e8, (%esp)\n" /* "r_skinCache" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_skinCache\n"
        "movl $0x2000, 8(%esp)\n" /* line 483 */
        "movl $1, 4(%esp)\n"
        "movl $0x2230f4, (%esp)\n" /* "r_smc_enable" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_smc_enable\n"
        "movl $0x2001, 0x10(%esp)\n" /* line 486 */
        "movl $0x40800000, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $0x223104, (%esp)\n" /* "r_lodScale" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_lodScale\n"
        "movl $0x2001, 0x10(%esp)\n" /* line 487 */
        "xorl %edi, %edi\n"
        "movl %edi, 0xc(%esp)\n"
        "movl $0xc47a0000, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x223110, (%esp)\n" /* "r_lodBias" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_lodBias\n"
        "movl $0x2080, 0x10(%esp)\n" /* line 488 */
        "movl $0x41800000, 0xc(%esp)\n"
        "movl $0x3a83126f, %esi\n"
        "movl %esi, 8(%esp)\n"
        "movl $0x40800000, 4(%esp)\n"
        "movl $0x22311c, (%esp)\n" /* "r_znear" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_znear\n"
        "movl $0x2080, 0x10(%esp)\n" /* line 489 */
        "movl $0x41800000, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl $0x3dcccccd, 4(%esp)\n"
        "movl $0x223124, (%esp)\n" /* "r_znear_depthhack" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_znear_depthhack\n"
        "movl $0x2080, 0x10(%esp)\n" /* line 490 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x223138, (%esp)\n" /* "r_zfar" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_zfar\n"
        "movl $0x2080, 8(%esp)\n" /* line 491 */
        "movl $1, 4(%esp)\n"
        "movl $0x223140, (%esp)\n" /* "r_fog" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_fog\n"
        "movl $0x2001, 0x10(%esp)\n" /* line 492 */
        "movl $0x40800000, 0xc(%esp)\n"
        "movl $0xc0800000, 8(%esp)\n"
        "movl $0xbf800000, %esi\n"
        "movl %esi, 4(%esp)\n"
        "movl $0x223148, (%esp)\n" /* "r_polygonOffsetScale" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_polygonOffsetScale\n"
        "movl $0x2001, 0x10(%esp)\n" /* line 493 */
        "movl $0x41800000, 0xc(%esp)\n"
        "movl $0xc1800000, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl $0x223160, (%esp)\n" /* "r_polygonOffsetBias" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_polygonOffsetBias\n"
        "movl $0x2001, 8(%esp)\n" /* line 496 */
        "movl $0, 4(%esp)\n"
        "movl $0x223174, (%esp)\n" /* "r_picmip_manual" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_picmip_manual\n"
        "movl $0x2001, 0x10(%esp)\n" /* line 497 */
        "movl $3, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x223184, (%esp)\n" /* "r_picmip" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, r_picmip\n"
        "movl $0x2001, 0x10(%esp)\n" /* line 498 */
        "movl $3, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x223190, (%esp)\n" /* "r_picmip_bump" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, r_picmip_bump\n"
        "movl $0x2001, 0x10(%esp)\n" /* line 499 */
        "movl $3, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x2231a0, (%esp)\n" /* "r_picmip_spec" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, r_picmip_spec\n"
        "movl $0x2080, 0xc(%esp)\n" /* line 502 */
        "movl $0, 8(%esp)\n"
        "movl $colorMapNames, 4(%esp)\n"
        "movl $0x2231b0, (%esp)\n" /* "r_lightMap" */
        "calll *0x68(%ebx)\n"
        "movl %eax, r_lightMap\n"
        "movl $0x2080, 0xc(%esp)\n" /* line 503 */
        "movl $0, 8(%esp)\n"
        "movl $colorMapNames, 4(%esp)\n"
        "movl $0x2231bc, (%esp)\n" /* "r_colorMap" */
        "calll *0x68(%ebx)\n"
        "movl %eax, r_colorMap\n"
        "movl $0x2080, 0xc(%esp)\n" /* line 504 */
        "movl $0, 8(%esp)\n"
        "movl $normalMapNames, 4(%esp)\n"
        "movl $0x2231c8, (%esp)\n" /* "r_normalMap" */
        "calll *0x68(%ebx)\n"
        "movl %eax, r_normalMap\n"
        "movl $0x2080, 0xc(%esp)\n" /* line 505 */
        "movl $0, 8(%esp)\n"
        "movl $colorMapNames, 4(%esp)\n"
        "movl $0x2231d4, (%esp)\n" /* "r_specularMap" */
        "calll *0x68(%ebx)\n"
        "movl %eax, r_specularMap\n"
        "movl $0x2080, 0x10(%esp)\n" /* line 506 */
        "movl $0x42c80000, 0xc(%esp)\n"
        "movl $0x3c23d70a, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $0x2231e4, (%esp)\n" /* "r_specularColorScale" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_specularColorScale\n"
        "movl $0x2080, 0x10(%esp)\n" /* line 507 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x2231fc, (%esp)\n" /* "r_cosinePowerMapShift" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_cosinePowerMapShift\n"
        "movl $0x2080, 0x10(%esp)\n" /* line 508 */
        "movl $2, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x223214, (%esp)\n" /* "r_showTris" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, r_showTris\n"
        "movl $0x2080, 8(%esp)\n" /* line 509 */
        "movl $0, 4(%esp)\n"
        "movl $0x223220, (%esp)\n" /* "r_showTriCounts" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_showTriCounts\n"
        "movl $0x2080, 8(%esp)\n" /* line 510 */
        "movl $0, 4(%esp)\n"
        "movl $0x223230, (%esp)\n" /* "r_showSurfCounts" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_showSurfCounts\n"
        "movl $0x2080, 8(%esp)\n" /* line 511 */
        "movl $0, 4(%esp)\n"
        "movl $0x223244, (%esp)\n" /* "r_showVertCounts" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_showVertCounts\n"
        "movl $0x2080, 0xc(%esp)\n" /* line 512 */
        "movl $0, 8(%esp)\n"
        "movl $xdebugNames, 4(%esp)\n"
        "movl $0x223258, (%esp)\n" /* "r_xdebug" */
        "calll *0x68(%ebx)\n"
        "movl %eax, r_xdebug\n"
        "movl $0x2001, 0x10(%esp)\n" /* line 513 */
        "movl $0x41800000, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $0x223264, (%esp)\n" /* "r_railCoreWidth" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_railCoreWidth\n"
        "movl $0x2020, 0x10(%esp)\n" /* line 515 */
        "movl $2, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x223274, (%esp)\n" /* "r_vc_makelog" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, r_vc_makelog\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 516 */
        "movl $0x400, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x223284, (%esp)\n" /* "r_vc_showlog" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, r_vc_showlog\n"
        "movl $0x2080, 8(%esp)\n" /* line 517 */
        "movl $0, 4(%esp)\n"
        "movl $0x223294, (%esp)\n" /* "r_showLightGrid" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_showLightGrid\n"
        "movl $0x2080, 8(%esp)\n" /* line 521 */
        "movl $0, 4(%esp)\n"
        "movl $0x2232a4, (%esp)\n" /* "r_showMissingLightGrid" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_showMissingLightGrid\n"
        "movl $0x2200, 0x10(%esp)\n" /* line 524 */
        "movl $0x40800000, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x3dcccccd, 4(%esp)\n"
        "movl $0x2232bc, (%esp)\n" /* "r_lightTweakAmbient" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_lightTweakAmbient\n"
        "movl $0x2200, 0x10(%esp)\n" /* line 525 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x3f000000, 4(%esp)\n"
        "movl $0x2232d0, (%esp)\n" /* "r_lightTweakDiffuseFraction" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_lightTweakDiffuseFraction\n"
        "movl $0x2200, 0x10(%esp)\n" /* line 526 */
        "movl $0x40800000, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $0x2232ec, (%esp)\n" /* "r_lightTweakSunLight" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_lightTweakSunLight\n"
        "movl $0x2200, 0x14(%esp)\n" /* line 528 */
        "movl $0x3f800000, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $0x223304, (%esp)\n" /* "r_lightTweakAmbientColor" */
        "calll *0x6c(%ebx)\n"
        "movl %eax, r_lightTweakAmbientColor\n"
        "movl $0x2200, 0x14(%esp)\n" /* line 529 */
        "movl $0x3f800000, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x223320, (%esp)\n" /* "r_lightTweakSunColor" */
        "calll *0x6c(%ebx)\n"
        "movl %eax, r_lightTweakSunColor\n"
        "movl $0x2200, 0x14(%esp)\n" /* line 530 */
        "movl $0x3f800000, 0x10(%esp)\n"
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x223338, (%esp)\n" /* "r_lightTweakSunDiffuseColor" */
        "calll *0x6c(%ebx)\n"
        "movl %eax, r_lightTweakSunDiffuseColor\n"
        "movl $0x2200, 0x18(%esp)\n" /* line 531 */
        "movl $0x43b40000, 0x14(%esp)\n"
        "movl $0xc3b40000, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x223354, (%esp)\n" /* "r_lightTweakSunDirection" */
        "calll *0x74(%ebx)\n"
        "movl %eax, r_lightTweakSunDirection\n"
        "movl $0x2000, 0x14(%esp)\n" /* line 534 */
        "movl $0x3f800000, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n"
        "movl $0x3ec28f5c, 8(%esp)\n"
        "movl $0x3f0ccccd, 4(%esp)\n"
        "movl $0x223370, (%esp)\n" /* "r_objectiveColorDx7Min" */
        "calll *0x6c(%ebx)\n"
        "movl %eax, r_objectiveColorDx7Min\n"
        "movl $0x2000, 0x14(%esp)\n" /* line 535 */
        "movl $0x3f800000, 0x10(%esp)\n"
        "movl $0x3e4ccccd, 0xc(%esp)\n"
        "movl $0x3f333333, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $0x223388, (%esp)\n" /* "r_objectiveColorDx7Max" */
        "calll *0x6c(%ebx)\n"
        "movl %eax, r_objectiveColorDx7Max\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 542 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x2233a0, (%esp)\n" /* "r_logFile" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, r_logFile\n"
        "movl $0x2080, 8(%esp)\n" /* line 543 */
        "movl $0, 4(%esp)\n"
        "movl $0x2233ac, (%esp)\n" /* "r_skipBackEnd" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_skipBackEnd\n"
        "movl $0x2080, 8(%esp)\n" /* line 556 */
        "movl $0, 4(%esp)\n"
        "movl $0x2233bc, (%esp)\n" /* "r_norefresh" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_norefresh\n"
        "movl $0x2021, 8(%esp)\n" /* line 558 */
        "movl $0, 4(%esp)\n"
        "movl $0x2233c8, (%esp)\n" /* "r_swapInterval" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_swapInterval\n"
        "movl $0x2001, 0xc(%esp)\n" /* line 559 */
        "movl $1, 8(%esp)\n"
        "movl $s_aaAlphaNames, 4(%esp)\n"
        "movl $0x2233d8, (%esp)\n" /* "r_aaAlpha" */
        "calll *0x68(%ebx)\n"
        "movl %eax, r_aaAlpha\n"
        "movl $0x2021, 0x10(%esp)\n" /* line 561 */
        "movl $4, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $0x2162a0, (%esp)\n" /* "r_aaSamples" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, r_aaSamples\n"
        "movl $0x2000, 0x14(%esp)\n" /* line 562 */
        "movl %edi, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x2233e4, (%esp)\n" /* "r_clearColor" */
        "calll *0x6c(%ebx)\n"
        "movl %eax, r_clearColor\n"
        "movl $0x2000, 0x14(%esp)\n" /* line 563 */
        "movl %edi, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x2233f4, (%esp)\n" /* "r_clearColor2" */
        "calll *0x6c(%ebx)\n"
        "movl %eax, r_clearColor2\n"
        "movl $0x2001, 8(%esp)\n" /* line 564 */
        "movl $1, 4(%esp)\n"
        "movl $0x223404, (%esp)\n" /* "r_drawSun" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_drawSun\n"
        "movl $0x2080, 8(%esp)\n" /* line 565 */
        "movl $1, 4(%esp)\n"
        "movl $0x223410, (%esp)\n" /* "r_drawWorld" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_drawWorld\n"
        "movl $0x2080, 8(%esp)\n" /* line 566 */
        "movl $1, 4(%esp)\n"
        "movl $0x22341c, (%esp)\n" /* "r_drawDecals" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_drawDecals\n"
        "movl $0x2080, 8(%esp)\n" /* line 567 */
        "movl $1, 4(%esp)\n"
        "movl $0x22342c, (%esp)\n" /* "r_drawEntities" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_drawEntities\n"
        "movl $0x2080, 8(%esp)\n" /* line 568 */
        "movl $1, 4(%esp)\n"
        "movl $0x22343c, (%esp)\n" /* "r_drawBModels" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_drawBModels\n"
        "movl $0x2080, 8(%esp)\n" /* line 569 */
        "movl $1, 4(%esp)\n"
        "movl $0x22344c, (%esp)\n" /* "r_drawSModels" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_drawSModels\n"
        "movl $0x2080, 8(%esp)\n" /* line 570 */
        "movl $1, 4(%esp)\n"
        "movl $0x22345c, (%esp)\n" /* "r_drawXModels" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_drawXModels\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 571 */
        "movl $0x20, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl $0x22346c, (%esp)\n" /* "r_dlightLimit" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, r_dlightLimit\n"
        "movl $0x2080, 0x10(%esp)\n" /* line 572 */
        "movl $0x2710, 0xc(%esp)\n"
        "movl $0xffffffff, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x22347c, (%esp)\n" /* "r_drawPrimCap" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, r_drawPrimCap\n"
        "movl $0x2080, 0x10(%esp)\n" /* line 573 */
        "movl $0x2710, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x22348c, (%esp)\n" /* "r_drawPrimFloor" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, r_drawPrimFloor\n"
        "movl $0x2080, 8(%esp)\n" /* line 574 */
        "movl $1, 4(%esp)\n"
        "movl $0x22349c, (%esp)\n" /* "r_drawWater" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_drawWater\n"
        "movl $0x2000, 8(%esp)\n" /* line 575 */
        "movl $0, 4(%esp)\n"
        "movl $0x2234a8, (%esp)\n" /* "r_depthPrepassModels" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_depthPrepassModels\n"
        "movl $0x2080, 8(%esp)\n" /* line 577 */
        "movl $0, 4(%esp)\n"
        "movl $0x2234c0, (%esp)\n" /* "r_lockPvs" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_lockPvs\n"
        "movl $0x2080, 8(%esp)\n" /* line 578 */
        "movl $0, 4(%esp)\n"
        "movl $0x2234cc, (%esp)\n" /* "r_skipPvs" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_skipPvs\n"
        "movl $0x2000, 8(%esp)\n" /* line 579 */
        "movl $0, 4(%esp)\n"
        "movl $0x2234d8, (%esp)\n" /* "r_pvsStats" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_pvsStats\n"
        "movl $0x2080, 8(%esp)\n" /* line 580 */
        "movl $1, 4(%esp)\n"
        "movl $0x2234e4, (%esp)\n" /* "r_portalFineCull" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_portalFineCull\n"
        "movl $0x2001, 0x10(%esp)\n" /* line 581 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x3f333333, 4(%esp)\n"
        "movl $0x2234f8, (%esp)\n" /* "r_portalBevels" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_portalBevels\n"
        "movl $0x2000, 8(%esp)\n" /* line 582 */
        "movl $0, 4(%esp)\n"
        "movl $0x223508, (%esp)\n" /* "r_portalBevelsOnly" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_portalBevelsOnly\n"
        "movl $0x2080, 8(%esp)\n" /* line 583 */
        "movl $0, 4(%esp)\n"
        "movl $0x22351c, (%esp)\n" /* "r_singleCell" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_singleCell\n"
        "movl $0x2080, 0x10(%esp)\n" /* line 584 */
        "movl $0x64, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x22352c, (%esp)\n" /* "r_portalWalkLimit" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, r_portalWalkLimit\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 585 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x3ca3d70a, 4(%esp)\n"
        "movl $0x223540, (%esp)\n" /* "r_portalMinClipArea" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_portalMinClipArea\n"
        "movl $0x2080, 0x10(%esp)\n" /* line 586 */
        "movl $3, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x223554, (%esp)\n" /* "r_showPortals" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, r_showPortals\n"
        "movl $0x2080, 8(%esp)\n" /* line 597 */
        "movl $0, 4(%esp)\n"
        "movl $0x223564, (%esp)\n" /* "r_showSModelNames" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_showSModelNames\n"
        "movl $0x2080, 0xc(%esp)\n" /* line 605 */
        "movl $0, 8(%esp)\n"
        "movl $fbColorDebugNames, 4(%esp)\n"
        "movl $0x223578, (%esp)\n" /* "r_showFbColorDebug" */
        "calll *0x68(%ebx)\n"
        "movl %eax, r_showFbColorDebug\n"
        "movl $0x2080, 8(%esp)\n" /* line 606 */
        "movl $0, 4(%esp)\n"
        "movl $0x22358c, (%esp)\n" /* "r_showFloatZDebug" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_showFloatZDebug\n"
        "movl $0x20a0, 8(%esp)\n" /* line 609 */
        "movl $0, 4(%esp)\n"
        "movl $0x2235a0, (%esp)\n" /* "r_showGroundLit" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_showGroundLit\n"
        "movl $0x2080, 0x10(%esp)\n" /* line 616 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl $0x2235b0, (%esp)\n" /* "r_highLodDist" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_highLodDist\n"
        "movl $0x2080, 0x10(%esp)\n" /* line 617 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl $0x2235c0, (%esp)\n" /* "r_mediumLodDist" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_mediumLodDist\n"
        "movl $0x2080, 0x10(%esp)\n" /* line 618 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl $0x2235d0, (%esp)\n" /* "r_lowLodDist" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_lowLodDist\n"
        "movl $0x2080, 0x10(%esp)\n" /* line 619 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl $0x2235e0, (%esp)\n" /* "r_lowestLodDist" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_lowestLodDist\n"
        "movl $0x2080, 0xc(%esp)\n" /* line 620 */
        "movl $4, 8(%esp)\n"
        "movl $r_forceLodNames, 4(%esp)\n"
        "movl $0x2235f0, (%esp)\n" /* "r_forceLod" */
        "calll *0x68(%ebx)\n"
        "movl %eax, r_forceLod\n"
        "movl $0x2000, 8(%esp)\n" /* line 622 */
        "movl $1, 4(%esp)\n"
        "movl $0x2235fc, (%esp)\n" /* "sc_enable" */
        "calll *0x58(%ebx)\n"
        "movl %eax, sc_enable\n"
        "movl $0x2080, 0x10(%esp)\n" /* line 623 */
        "movl $4, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl $0x223608, (%esp)\n" /* "sc_blur" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, sc_blur\n"
        "movl $0x2080, 0x10(%esp)\n" /* line 624 */
        "movl $0x18, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x18, 4(%esp)\n"
        "movl $0x223610, (%esp)\n" /* "sc_count" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, sc_count\n"
        "movl $0x2080, 0x10(%esp)\n" /* line 625 */
        "movl $0x18, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x18, 4(%esp)\n"
        "movl $0x22361c, (%esp)\n" /* "sc_debugCasterCount" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, sc_debugCasterCount\n"
        "movl $0x2080, 0x10(%esp)\n" /* line 626 */
        "movl $0x18, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x18, 4(%esp)\n"
        "movl $0x223630, (%esp)\n" /* "sc_debugReceiverCount" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, sc_debugReceiverCount\n"
        "movl $0x2080, 8(%esp)\n" /* line 627 */
        "movl $0, 4(%esp)\n"
        "movl $0x223648, (%esp)\n" /* "sc_showOverlay" */
        "calll *0x58(%ebx)\n"
        "movl %eax, sc_showOverlay\n"
        "movl $0x2080, 8(%esp)\n" /* line 628 */
        "movl $0, 4(%esp)\n"
        "movl $0x223658, (%esp)\n" /* "sc_showDebug" */
        "calll *0x58(%ebx)\n"
        "movl %eax, sc_showDebug\n"
        "movl $0x2080, 0x10(%esp)\n" /* line 629 */
        "movl $0x18, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0xc, 4(%esp)\n"
        "movl $0x223668, (%esp)\n" /* "sc_wantCount" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, sc_wantCount\n"
        "movl $0x2080, 0x10(%esp)\n" /* line 630 */
        "movl $0x18, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $0x223678, (%esp)\n" /* "sc_wantCountMargin" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, sc_wantCountMargin\n"
        "movl $0x2080, 0x10(%esp)\n" /* line 631 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x3e800000, 4(%esp)\n"
        "movl $0x22368c, (%esp)\n" /* "sc_fadeRange" */
        "calll *0x60(%ebx)\n"
        "movl %eax, sc_fadeRange\n"
        "movl $0x2080, 0x10(%esp)\n" /* line 632 */
        "movl $0x41a00000, %esi\n"
        "movl %esi, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x40000000, 4(%esp)\n"
        "movl $0x22369c, (%esp)\n" /* "sc_shadowInRate" */
        "calll *0x60(%ebx)\n"
        "movl %eax, sc_shadowInRate\n"
        "movl $0x2080, 0x10(%esp)\n" /* line 633 */
        "movl %esi, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x40a00000, 4(%esp)\n"
        "movl $0x2236ac, (%esp)\n" /* "sc_shadowOutRate" */
        "calll *0x60(%ebx)\n"
        "movl %eax, sc_shadowOutRate\n"
        "movl $0x2080, 0x10(%esp)\n" /* line 634 */
        "movl $0x44fa0000, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0x43c80000, 4(%esp)\n"
        "movl $0x2236c0, (%esp)\n" /* "sc_length" */
        "calll *0x60(%ebx)\n"
        "movl %eax, sc_length\n"
        "movl $0x2080, 0x10(%esp)\n" /* line 635 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl $0xff7fffff, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x2236cc, (%esp)\n" /* "sc_offscreenCasterLodBias" */
        "calll *0x60(%ebx)\n"
        "movl %eax, sc_offscreenCasterLodBias\n"
        "movl $0x2080, 0x10(%esp)\n" /* line 636 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl $0x2236e8, (%esp)\n" /* "sc_offscreenCasterLodScale" */
        "calll *0x60(%ebx)\n"
        "movl %eax, sc_offscreenCasterLodScale\n"
        "movl $0x2080, 0x10(%esp)\n" /* line 638 */
        "movl $0x42000000, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x223704, (%esp)\n" /* "r_blur" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_blur\n"
        "movl $0x2001, 8(%esp)\n" /* line 639 */
        "movl $1, 4(%esp)\n"
        "movl $0x22370c, (%esp)\n" /* "r_distortion" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_distortion\n"
        "movl $0x2001, 8(%esp)\n" /* line 642 */
        "movl $1, 4(%esp)\n"
        "movl $0x22371c, (%esp)\n" /* "r_glow" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_glow\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 643 */
        "movl $0x42000000, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x40a00000, 4(%esp)\n"
        "movl $0x223724, (%esp)\n" /* "r_glowRadius0" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_glowRadius\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 644 */
        "movl $0x42000000, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x41400000, 4(%esp)\n"
        "movl $0x223734, (%esp)\n" /* "r_glowRadius1" */
        "calll *0x60(%ebx)\n"
        "movl %eax, 0x117d66c\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 645 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x3f000000, 4(%esp)\n"
        "movl $0x223744, (%esp)\n" /* "r_glowSkyBleedIntensity0" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_glowSkyBleedIntensity\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 646 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x223760, (%esp)\n" /* "r_glowSkyBleedIntensity1" */
        "calll *0x60(%ebx)\n"
        "movl %eax, 0x117d664\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 647 */
        "movl $0x41000000, %esi\n"
        "movl %esi, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $0x22377c, (%esp)\n" /* "r_glowBloomIntensity0" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_glowBloomIntensity\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 648 */
        "movl %esi, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $0x223794, (%esp)\n" /* "r_glowBloomIntensity1" */
        "calll *0x60(%ebx)\n"
        "movl %eax, 0x117d65c\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 649 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x3f666666, 4(%esp)\n"
        "movl $0x2237ac, (%esp)\n" /* "r_glowBloomCutoff" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_glowBloomCutoff\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 650 */
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x3f400000, 4(%esp)\n"
        "movl $0x2237c0, (%esp)\n" /* "r_glowBloomDesaturation" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_glowBloomDesaturation\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 652 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl $0xff7fffff, 8(%esp)\n"
        "movl $0x42000000, 4(%esp)\n"
        "movl $0x2237d8, (%esp)\n" /* "r_outdoorAwayBias" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_outdoorAwayBias\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 653 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl $0xff7fffff, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x2237ec, (%esp)\n" /* "r_outdoorDownBias" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_outdoorDownBias\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 654 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl $0xff7fffff, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl $0x223800, (%esp)\n" /* "r_outdoorFeather" */
        "calll *0x60(%ebx)\n"
        "movl %eax, r_outdoorFeather\n"
        "movl %eax, (%esp)\n" /* line 655 */
        "calll *0x8c(%ebx)\n"
        "movl $0x2080, 8(%esp)\n" /* line 667 */
        "movl $0, 4(%esp)\n"
        "movl $0x223814, (%esp)\n" /* "r_sun_from_dvars" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_sun_from_dvars\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 670 */
        "movl $1, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x223828, (%esp)\n" /* "r_testTransform" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, r_testTransform\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 671 */
        "movl $0x1f4, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x223838, (%esp)\n" /* "r_testFill" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, r_testFill\n"
        "movl $0x2020, 8(%esp)\n" /* line 672 */
        "movl $0, 4(%esp)\n"
        "movl $0x223844, (%esp)\n" /* "r_testFillEnable" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_testFillEnable\n"
        "movl $0x2000, 8(%esp)\n" /* line 674 */
        "movl $1, 4(%esp)\n"
        "movl $0x223858, (%esp)\n" /* "fx_sort" */
        "calll *0x58(%ebx)\n"
        "movl 0x195ed68, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x2001, 0x10(%esp)\n" /* line 683 */
        "movl $__mh_execute_header, 0xc(%esp)\n"
        "movl $0xfffff000, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl $0x223860, (%esp)\n" /* "vid_xpos" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, vid_xpos\n"
        "movl $0x2001, 0x10(%esp)\n" /* line 684 */
        "movl $__mh_execute_header, 0xc(%esp)\n"
        "movl $0xfffff000, 8(%esp)\n"
        "movl $0x16, 4(%esp)\n"
        "movl $0x22386c, (%esp)\n" /* "vid_ypos" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, vid_ypos\n"
        "movl $0x2000, 0x10(%esp)\n" /* line 686 */
        "movl $2, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x2167f8, (%esp)\n" /* "developer" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, developer\n"
        "movl $0x2048, 8(%esp)\n" /* line 687 */
        "movl $0, 4(%esp)\n"
        "movl $0x2198ac, (%esp)\n" /* "sv_cheats" */
        "calll *0x58(%ebx)\n"
        "movl 0x195ef54, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x2000, 8(%esp)\n" /* line 689 */
        "movl $0, 4(%esp)\n"
        "movl $0x21682c, (%esp)\n" /* "com_statmon" */
        "calll *0x58(%ebx)\n"
        "movl 0x195ed14, %edx\n"
        "movl %eax, (%edx)\n"
        "movl $0x2000, 8(%esp)\n" /* line 700 */
        "movl $0, 4(%esp)\n"
        "movl $0x222c98, (%esp)\n" /* "sys_SSE" */
        "calll *0x58(%ebx)\n"
        "movl %eax, sys_SSE\n"
        "movl $0x2000, 8(%esp)\n" /* line 701 */
        "movl $1, 4(%esp)\n"
        "movl $0x223878, (%esp)\n" /* "r_sse_skinning" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_sse_skinning\n"
        "movl $0x2040, 8(%esp)\n" /* line 703 */
        "movl $1, 4(%esp)\n"
        "movl $0x223888, (%esp)\n" /* "r_fullscreen" */
        "calll *0x58(%ebx)\n"
        "movl %eax, r_fullscreen\n"
        "movl $0x2021, 0x10(%esp)\n" /* line 707 */
        "movl $8, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x223898, (%esp)\n" /* "r_monitor" */
        "calll *0x5c(%ebx)\n"
        "movl %eax, r_monitor\n"
        "movl $0x2021, 0xc(%esp)\n" /* line 708 */
        "movl $0, 8(%esp)\n"
        "movl $s_technologyNames, 4(%esp)\n"
        "movl $0x2238a4, (%esp)\n" /* "r_rendererPreference" */
        "calll *0x68(%ebx)\n"
        "movl %eax, r_rendererPreference\n"
        "movl $0x2040, 0xc(%esp)\n" /* line 709 */
        "movl $0, 8(%esp)\n"
        "movl $s_technologyNames, 4(%esp)\n"
        "movl $0x2238bc, (%esp)\n" /* "r_rendererInUse" */
        "calll *0x68(%ebx)\n"
        "movl %eax, r_rendererInUse\n"
        "movl $0x2021, 0xc(%esp)\n" /* line 710 */
        "movl $0, 8(%esp)\n"
        "movl $s_aspectRatioNames, 4(%esp)\n"
        "movl $0x2238cc, (%esp)\n" /* "r_aspectRatio" */
        "calll *0x68(%ebx)\n"
        "movl %eax, r_aspectRatio\n"
        "addl $0x2c, %esp\n" /* line 731 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 734 */
__attribute__((naked))
void R_UnregisterDvars(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 734 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x2000, (%esp)\n" /* line 737 */
        "movl 0x195eee0, %eax\n"
        "calll *0x7c(%eax)\n"
        "leave\n" /* line 738 */
        "retl\n"
    );
}

