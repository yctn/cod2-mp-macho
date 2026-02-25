/* Uninitialized global data (BSS) */
#include "common_types.h"

int sBuilderProcPtr; /* 0x00334700 */
int sControlValidationUPP; /* 0x00334704 */
unsigned char sControlKeyFilterUPP[120]; /* 0x00334708 */
unsigned char sRectList[12]; /* 0x00334780 */
unsigned char sDisplayList[12]; /* 0x0033478c */
int sSwapCount; /* 0x00334798 */
unsigned char sCaptureMedia[8]; /* 0x0033479c */
int sMainWindow; /* 0x003347a4 */
unsigned char sCaptureMovie[24]; /* 0x003347a8 */
unsigned char sCaptureName[256]; /* 0x003347c0 */
int sCaptureTrack; /* 0x003348c0 */
int sCaptureRefNum; /* 0x003348c4 */
int sDisplayID; /* 0x003348c8 */
int sSystemGammaBlue; /* 0x003348cc */
int sSystemGammaGreen; /* 0x003348d0 */
int sSystemGammaRed; /* 0x003348d4 */
int sInWindowMode; /* 0x003348d8 */
int sScreenContext; /* 0x003348dc */
int sDisplayRefreshRate; /* 0x003348e0 */
int sDisplayDepth; /* 0x003348e4 */
int sDisplayIndex; /* 0x003348e8 */
int sFadeToken; /* 0x003348ec */
int sInitialized; /* 0x003348f0 */
unsigned char sDisplayRect[16]; /* 0x003348f4 */
int sMainDisplayID; /* 0x00334904 */
unsigned char sMainRect[120]; /* 0x00334908 */
unsigned char sResult_00334980[2]; /* 0x00334980 */
unsigned char sTested[1]; /* 0x00334982 */
unsigned char hasAltiVec[1]; /* 0x00334983 */
unsigned char hasAltiVecBeenDetermined[124]; /* 0x00334984 */
int sDataFolderDirID; /* 0x00334a00 */
int sExecutableDirID; /* 0x00334a04 */
int sAppFolderDirID; /* 0x00334a08 */
unsigned char sAppFolderVRefNum[20]; /* 0x00334a0c */
unsigned char sAppBundleRef[96]; /* 0x00334a20 */
unsigned char sSystemLock[128]; /* 0x00334a80 */
int sResult_00334b00; /* 0x00334b00 */
int sResult_00334b04; /* 0x00334b04 */
int sResult_00334b08; /* 0x00334b08 */
int sResult_00334b0c; /* 0x00334b0c */
unsigned char sResult_00334b10[8]; /* 0x00334b10 */
int sResult_00334b18; /* 0x00334b18 */
int sResult_00334b1c; /* 0x00334b1c */
int sResult_00334b20; /* 0x00334b20 */
int sResult_00334b24; /* 0x00334b24 */
int sResult_00334b28; /* 0x00334b28 */
unsigned char sResult_00334b2c[84]; /* 0x00334b2c */
unsigned char sGlobalMouse[128]; /* 0x00334b80 */
unsigned char sCursorList[12]; /* 0x00334c00 */
int sCurrentCursor; /* 0x00334c0c */
int sSavedWinCursor; /* 0x00334c10 */
unsigned char sTimerRef[108]; /* 0x00334c14 */
unsigned char sCachedVKMap[128]; /* 0x00334c80 */
int sATI4CompsConverterABGR; /* 0x00334d00 */
int sATI4CompsConverterARGB; /* 0x00334d04 */
int sStdConverterABGR; /* 0x00334d08 */
unsigned char sStdConverterARGB[116]; /* 0x00334d0c */
unsigned char sDirect3DInterface[128]; /* 0x00334d80 */
unsigned char sPointScale[128]; /* 0x00334e00 */
int sEventTargetRef; /* 0x00334e80 */
unsigned char sSystemCursorVisible_00334e84[124]; /* 0x00334e84 */
unsigned char g_threadValues[20]; /* 0x00334f00 */
unsigned char threadId[108]; /* 0x00334f14 */
unsigned char value1[16384]; /* 0x00334f80 */
unsigned char g_com_error[96]; /* 0x00338f80 */
unsigned char va_info[2052]; /* 0x00338fe0 */
int LittleFloatWrite; /* 0x003397e4 */
int LittleFloatRead; /* 0x003397e8 */
int LittleLong64; /* 0x003397ec */
int LittleLong; /* 0x003397f0 */
int LittleShort; /* 0x003397f4 */
unsigned char valueindex[8]; /* 0x003397f8 */
int iWeaponInfoSource; /* 0x00339800 */
int logfile; /* 0x00339804 */
unsigned char errorcode[120]; /* 0x00339808 */
unsigned char com_errorMessage[4096]; /* 0x00339880 */
int com_lastFrameTime; /* 0x0033a880 */
int com_codeTimeScale; /* 0x0033a884 */
unsigned char com_fullyInitialized[120]; /* 0x0033a888 */
unsigned char com_pushedEvents[6144]; /* 0x0033a900 */
int com_pushedEventsTail; /* 0x0033c100 */
int com_pushedEventsHead; /* 0x0033c104 */
int com_safemode; /* 0x0033c108 */
int rd_flush; /* 0x0033c10c */
int rd_buffersize; /* 0x0033c110 */
int rd_buffer; /* 0x0033c114 */
int opening_qconsole; /* 0x0033c118 */
int printedWarning; /* 0x0033c11c */
int timeClientFrame; /* 0x0033c120 */
int errorCount; /* 0x0033c124 */
unsigned char lastErrorTime[88]; /* 0x0033c128 */
unsigned char g_currentAsian[32]; /* 0x0033c180 */
unsigned char szErrorString[1024]; /* 0x0033c1a0 */
unsigned char szStrings[2048]; /* 0x0033c5a0 */
unsigned char iCurrString[96]; /* 0x0033cda0 */
unsigned char iString[32]; /* 0x0033ce00 */
unsigned char szIwdLanguageName[128]; /* 0x0033ce20 */
unsigned char bLanguagesListed[96]; /* 0x0033cea0 */
unsigned char g_largeLocalPos[128]; /* 0x0033cf00 */
unsigned char g_largeLocalBuf[524288]; /* 0x0033cf80 */
unsigned char hunk_high[8]; /* 0x003bcf80 */
unsigned char hunk_low[8]; /* 0x003bcf88 */
int s_hunkData; /* 0x003bcf90 */
int s_hunkTotal; /* 0x003bcf94 */
unsigned char com_hunkData[8]; /* 0x003bcf98 */
unsigned char com_fileDataHashTable[4096]; /* 0x003bcfa0 */
unsigned char s_origHunkData[96]; /* 0x003bdfa0 */
unsigned char g_xAnimInfo[163840]; /* 0x003be000 */
unsigned char g_notifyListSize[32]; /* 0x003e6000 */
unsigned char g_notifyList[1536]; /* 0x003e6020 */
unsigned char g_end[5]; /* 0x003e6620 */
unsigned char g_anim_developer[91]; /* 0x003e6625 */
unsigned char scrStringGlob[65664]; /* 0x003e6680 */
unsigned char scrMemTreeGlob[525184]; /* 0x003f6700 */
unsigned char info6[8192]; /* 0x00476a80 */
unsigned char info8[8192]; /* 0x00478a80 */
unsigned char info5[8192]; /* 0x0047aa80 */
unsigned char info4[8192]; /* 0x0047ca80 */
unsigned char info3[8192]; /* 0x0047ea80 */
unsigned char info2[8192]; /* 0x00480a80 */
unsigned char buf_00482a80[1024]; /* 0x00482a80 */
unsigned char basename[128]; /* 0x00482e80 */
unsigned char sString[128]; /* 0x00482f00 */
unsigned char sString_00482f80[64]; /* 0x00482f80 */
unsigned char sTemp[64]; /* 0x00482fc0 */
unsigned char cmd_functions[128]; /* 0x00483000 */
unsigned char cmd_argv[2048]; /* 0x00483080 */
unsigned char cmd_argc[128]; /* 0x00483880 */
unsigned char cmd_tokenized[8704]; /* 0x00483900 */
unsigned char cmd_args1[1024]; /* 0x00485b00 */
unsigned char cmd_text_buf[65536]; /* 0x00485f00 */
unsigned char info2_00495f00[8192]; /* 0x00495f00 */
unsigned char info1[1024]; /* 0x00497f00 */
unsigned char dvarHashTable[1024]; /* 0x00498300 */
unsigned char dvarVectorPool[48]; /* 0x00498700 */
int dvarVectorIndex; /* 0x00498730 */
unsigned char dvar_cheats[12]; /* 0x00498734 */
unsigned char dvarPool[46080]; /* 0x00498740 */
unsigned char isDvarSystemActive[1]; /* 0x004a3b40 */
unsigned char isLoadingAutoExecGlobalFlag[63]; /* 0x004a3b41 */
unsigned char milesGlob[384]; /* 0x004a3b80 */
unsigned char effectListArrayNonBolt[7296]; /* 0x004a3d00 */
unsigned char effectListArrayBolt[7296]; /* 0x004a5980 */
unsigned char effectClusterArray[28800]; /* 0x004a7600 */
unsigned char visibleEffectsBolt[14400]; /* 0x004ae680 */
unsigned char visibleEffectsNonBolt[14400]; /* 0x004b1ec0 */
unsigned char effectTemplateArrayCount[32]; /* 0x004b5700 */
unsigned char effectTemplateArray[1120]; /* 0x004b5720 */
int g_bDObjInited; /* 0x004b5b80 */
unsigned char com_lastDObjIndex[124]; /* 0x004b5b84 */
unsigned char serverObjMap[2048]; /* 0x004b5c00 */
unsigned char clientObjMap[2304]; /* 0x004b6400 */
unsigned char objFreeCount[128]; /* 0x004b6d00 */
unsigned char objAlloced[2048]; /* 0x004b6d80 */
unsigned char objBuf[204800]; /* 0x004b7580 */
unsigned char g_empty[128]; /* 0x004e9580 */
unsigned char localization[32]; /* 0x004e9600 */
unsigned char language_buffer[4192]; /* 0x004e9620 */
int shouldQuitOnError; /* 0x004ea680 */
unsigned char cml[124]; /* 0x004ea684 */
unsigned char bg_iNumAmmoTypes[32]; /* 0x004ea700 */
unsigned char bg_weapAmmoTypes[512]; /* 0x004ea720 */
unsigned char bg_iNumSharedAmmoCaps[32]; /* 0x004ea920 */
unsigned char bg_sharedAmmoCaps[512]; /* 0x004ea940 */
unsigned char bg_iNumWeapClips[32]; /* 0x004eab40 */
unsigned char bg_weapClips[544]; /* 0x004eab60 */
unsigned char scrVmGlob[8320]; /* 0x004ead80 */
unsigned char scrCompileGlob[512]; /* 0x004ece00 */
unsigned char scrAnimGlob[640]; /* 0x004ed000 */
int jump_height; /* 0x004ed280 */
int jump_spreadAdd; /* 0x004ed284 */
int jump_slowdownEnable; /* 0x004ed288 */
int jump_ladderPushVel; /* 0x004ed28c */
unsigned char jump_stepSize[112]; /* 0x004ed290 */
int mantle_enable; /* 0x004ed300 */
int mantle_view_yawcap; /* 0x004ed304 */
int s_mantleAnims; /* 0x004ed308 */
int mantle_debug; /* 0x004ed30c */
int mantle_check_angle; /* 0x004ed310 */
int mantle_check_range; /* 0x004ed314 */
unsigned char mantle_check_radius[104]; /* 0x004ed318 */
unsigned char token_004ed380[1024]; /* 0x004ed380 */
unsigned char statCount[32]; /* 0x004ed780 */
unsigned char stats[96]; /* 0x004ed7a0 */
unsigned char initialized[128]; /* 0x004ed800 */
unsigned char cm_world[24704]; /* 0x004ed880 */
unsigned char cinTable[7360]; /* 0x004f3900 */
unsigned char cin[2426400]; /* 0x004f55c0 */
unsigned char ROQ_YY_tab[1024]; /* 0x00745be0 */
unsigned char ROQ_VG_tab[1024]; /* 0x00745fe0 */
unsigned char ROQ_UG_tab[1024]; /* 0x007463e0 */
unsigned char ROQ_VR_tab[1024]; /* 0x007467e0 */
unsigned char ROQ_UB_tab[1024]; /* 0x00746be0 */
unsigned char vq2[32768]; /* 0x00746fe0 */
unsigned char vq4[131072]; /* 0x0074efe0 */
unsigned char vq8[524288]; /* 0x0076efe0 */
unsigned char sAspyrIntroPlayed[32]; /* 0x007eefe0 */
unsigned char g_testLods[128]; /* 0x007ef000 */
unsigned char szReference[1024]; /* 0x007ef080 */
unsigned char currentPos[128]; /* 0x007ef480 */
unsigned char bg_defaultWeaponDefs[1568]; /* 0x007ef500 */
unsigned char g_playerAnimTypeNames[256]; /* 0x007efb20 */
unsigned char g_playerAnimTypeNamesCount[96]; /* 0x007efc20 */
unsigned char sys_info[544]; /* 0x007efc80 */
unsigned char eventQue[6144]; /* 0x007efea0 */
int eventTail; /* 0x007f16a0 */
int eventHead; /* 0x007f16a4 */
int sys_configSum; /* 0x007f16a8 */
int sys_gpu; /* 0x007f16ac */
int sys_sysMB; /* 0x007f16b0 */
unsigned char sys_cpuGHz[76]; /* 0x007f16b4 */
int sConsoleEditText; /* 0x007f1700 */
int sConsoleTextView; /* 0x007f1704 */
int sConsoleData; /* 0x007f1708 */
unsigned char sConsoleWindow[20]; /* 0x007f170c */
unsigned char sReturnedText[512]; /* 0x007f1720 */
unsigned char sConsoleText[512]; /* 0x007f1920 */
unsigned char sTimerRef_007f1b20[96]; /* 0x007f1b20 */
unsigned char cwd[256]; /* 0x007f1b80 */
unsigned char lockPvsViewParms[332]; /* 0x007f1c80 */
int warnCount; /* 0x007f1dcc */
unsigned char warnCount_007f1dd0[48]; /* 0x007f1dd0 */
unsigned char s_cmdList[128]; /* 0x007f1e00 */
unsigned char s_debugFrameGlob[2399616]; /* 0x007f1e80 */
unsigned char s_backEndData[2399596]; /* 0x00a3bc00 */
unsigned char g_dummyBuf[20]; /* 0x00c8596c */
unsigned char re[384]; /* 0x00c85980 */
int warnCount_00c85b00; /* 0x00c85b00 */
int warnCount_00c85b04; /* 0x00c85b04 */
int warnCount_00c85b08; /* 0x00c85b08 */
int warnCount_00c85b0c; /* 0x00c85b0c */
unsigned char warnCount_00c85b10[112]; /* 0x00c85b10 */
unsigned char materialGlobals[10752]; /* 0x00c85b80 */
unsigned char s_cache[50304]; /* 0x00c88580 */
unsigned char g_imageProgs[448]; /* 0x00c94a00 */
unsigned char imageGlobals[8256]; /* 0x00c94bc0 */
unsigned char cubeShotGlob[24]; /* 0x00c96c00 */
unsigned char lastNumber[104]; /* 0x00c96c18 */
unsigned char s_vc_log[128]; /* 0x00c96c80 */
unsigned char registeredFontCount[32]; /* 0x00c96d00 */
unsigned char registeredFont[96]; /* 0x00c96d20 */
unsigned char debugGlobals[128]; /* 0x00c96d80 */
unsigned char dpvsConfig[32]; /* 0x00c96e00 */
unsigned char dpvsGlob[224]; /* 0x00c96e20 */
unsigned char dpvsScene[131200]; /* 0x00c96f00 */
unsigned char shadowCookieGlob[128]; /* 0x00cb6f80 */
unsigned char waterGlob[196608]; /* 0x00cb7000 */
unsigned char surfBoundsGlob[128]; /* 0x00ce7000 */
unsigned char mtlLoadGlob[128]; /* 0x00ce7080 */
unsigned char smodelLoadGlob[128]; /* 0x00ce7100 */
unsigned char outdoorGlob[128]; /* 0x00ce7180 */
unsigned char sOldButtonState[128]; /* 0x00ce7200 */
int yaccResult; /* 0x00ce7280 */
int yy_start; /* 0x00ce7284 */
unsigned char yy_current_buffer[24]; /* 0x00ce7288 */
unsigned char ch_buf[16388]; /* 0x00ce72a0 */
int g_dummyVal; /* 0x00ceb2a4 */
int g_parse_user; /* 0x00ceb2a8 */
int g_sourcePos; /* 0x00ceb2ac */
int g_out_pos; /* 0x00ceb2b0 */
int yy_hold_char; /* 0x00ceb2b4 */
int yy_c_buf_p; /* 0x00ceb2b8 */
int yy_n_chars; /* 0x00ceb2bc */
int yy_did_buffer_switch_on_eof; /* 0x00ceb2c0 */
int yy_last_accepting_cpos; /* 0x00ceb2c4 */
unsigned char yy_last_accepting_state[56]; /* 0x00ceb2c8 */
int sSoundEngine; /* 0x00ceb300 */
unsigned char sHighQualityEngine[124]; /* 0x00ceb304 */
unsigned char comBspGlob[128]; /* 0x00ceb380 */
unsigned char __ZGVZ16GetMacGameEnginevE13theGameEngine[32]; /* 0x00ceb400 */
unsigned char theGameEngine[96]; /* 0x00ceb420 */
unsigned char sDeviceName[128]; /* 0x00ceb480 */
unsigned char sShaderPrograms[24]; /* 0x00ceb500 */
unsigned char sInit[104]; /* 0x00ceb518 */
unsigned char hasExactMatch[128]; /* 0x00ceb580 */
unsigned char shortestMatch[1024]; /* 0x00ceb600 */
int matchCount; /* 0x00ceba00 */
int completionString; /* 0x00ceba04 */
unsigned char tinystr[120]; /* 0x00ceba08 */
unsigned char cg_itemsArray[9216]; /* 0x00ceba80 */
unsigned char cg_weaponsArray[55808]; /* 0x00cede80 */
unsigned char cg_entitiesArray[561152]; /* 0x00cfb880 */
unsigned char cgsArray[59392]; /* 0x00d84880 */
unsigned char cgArray[997788]; /* 0x00d93080 */
unsigned char g_mapLoaded[1]; /* 0x00e86a1c */
unsigned char g_ambientStarted[3]; /* 0x00e86a1d */
unsigned char buffer_00e86a20[1120]; /* 0x00e86a20 */
unsigned char input_viewSensitivity[32]; /* 0x00e86e80 */
unsigned char szServerIPAddress[128]; /* 0x00e86ea0 */
unsigned char recursive[96]; /* 0x00e86f20 */
unsigned char g_sv_skel_memory_start[128]; /* 0x00e86f80 */
unsigned char g_sv_skel_memory[262144]; /* 0x00e87000 */
unsigned char warnCount_00ec7000[128]; /* 0x00ec7000 */
unsigned char g_gametype[64]; /* 0x00ec7080 */
unsigned char g_mapname[64]; /* 0x00ec70c0 */
int g_ingameMenusLoaded; /* 0x00ec7100 */
unsigned char ui_serverFilterType[28]; /* 0x00ec7104 */
unsigned char menuBuf2[32768]; /* 0x00ec7120 */
unsigned char errorString[1024]; /* 0x00ecf120 */
unsigned char info[1024]; /* 0x00ecf520 */
int bypassKeyClear; /* 0x00ecf920 */
int numclean; /* 0x00ecf924 */
unsigned char lastTime[24]; /* 0x00ecf928 */
unsigned char clientBuff[32]; /* 0x00ecf940 */
unsigned char info_00ecf960[1024]; /* 0x00ecf960 */
int numTimeOuts; /* 0x00ecfd60 */
int numFound; /* 0x00ecfd64 */
unsigned char tleIndex[24]; /* 0x00ecfd68 */
unsigned char loopbacks[45072]; /* 0x00ecfd80 */
unsigned char net_iProfilingOn[16]; /* 0x00edad90 */
unsigned char s[96]; /* 0x00edada0 */
unsigned char string_00edae00[1024]; /* 0x00edae00 */
unsigned char con[151588]; /* 0x00edb200 */
int con_outputWindowColor; /* 0x00f00224 */
int con_outputSliderColor; /* 0x00f00228 */
int con_outputBarColor; /* 0x00f0022c */
int con_inputHintBoxColor; /* 0x00f00230 */
unsigned char con_inputBoxColor[12]; /* 0x00f00234 */
unsigned char conDrawInputGlob[32]; /* 0x00f00240 */
unsigned char hudMsgIconMaterials[1024]; /* 0x00f00260 */
unsigned char registeredIconMaterialCount[32]; /* 0x00f00660 */
unsigned char s_playerMute[64]; /* 0x00f00680 */
unsigned char rconGlob[64]; /* 0x00f006c0 */
int debugMode; /* 0x00f00700 */
int captureData; /* 0x00f00704 */
int captureFunc; /* 0x00f00708 */
int itemCapture; /* 0x00f0070c */
unsigned char g_bindItem[16]; /* 0x00f00710 */
unsigned char scrollInfo[32]; /* 0x00f00720 */
int lastListBoxClickTime; /* 0x00f00740 */
unsigned char rect_00f00744[24]; /* 0x00f00744 */
unsigned char inHandleKey[36]; /* 0x00f0075c */
unsigned char initialized_00f00780[128]; /* 0x00f00780 */
unsigned char msgInit[32]; /* 0x00f00800 */
unsigned char msgHuff[57408]; /* 0x00f00820 */
unsigned char string_00f0e860[1024]; /* 0x00f0e860 */
unsigned char string_00f0ec60[8192]; /* 0x00f0ec60 */
unsigned char string_00f10c60[1056]; /* 0x00f10c60 */
unsigned char bigConfigString[8192]; /* 0x00f11080 */
int warnCount_00f13080; /* 0x00f13080 */
unsigned char warnCount_00f13084[124]; /* 0x00f13084 */
unsigned char botport[128]; /* 0x00f13100 */
unsigned char ui_arenaInfos[256]; /* 0x00f13180 */
unsigned char ui_numArenas[128]; /* 0x00f13280 */
unsigned char defineBits[1152]; /* 0x00f13300 */
unsigned char weaponStrings[1024]; /* 0x00f13780 */
int parseEvent; /* 0x00f13b80 */
int parseMovetype; /* 0x00f13b84 */
unsigned char defineStringsOffset[24]; /* 0x00f13b88 */
unsigned char numDefines[64]; /* 0x00f13ba0 */
unsigned char defineStrings[10016]; /* 0x00f13be0 */
unsigned char defineStr[1152]; /* 0x00f16300 */
int g_piNumLoadAnims; /* 0x00f16780 */
int g_pLoadAnims; /* 0x00f16784 */
unsigned char globalScriptData[24]; /* 0x00f16788 */
unsigned char input[100000]; /* 0x00f167a0 */
unsigned char bScriptFileLoaded[64]; /* 0x00f2ee40 */
unsigned char playersKb[640]; /* 0x00f2ee80 */
int hud_healthOverlay_phaseEnd_pulseDuration; /* 0x00f2f100 */
int hud_healthOverlay_phaseEnd_toAlpha; /* 0x00f2f104 */
int hud_healthOverlay_regenPauseTime; /* 0x00f2f108 */
int hud_healthOverlay_phaseThree_pulseDuration; /* 0x00f2f10c */
int hud_healthOverlay_phaseThree_toAlphaMultiplier; /* 0x00f2f110 */
int hud_healthOverlay_phaseTwo_pulseDuration; /* 0x00f2f114 */
int hud_healthOverlay_phaseTwo_toAlphaMultiplier; /* 0x00f2f118 */
int hud_healthOverlay_phaseOne_pulseDuration; /* 0x00f2f11c */
int hud_healthOverlay_pulseStart; /* 0x00f2f120 */
int hud_enable; /* 0x00f2f124 */
unsigned char hud_fadeout_speed[24]; /* 0x00f2f128 */
unsigned char szErrorString_00f2f140[1088]; /* 0x00f2f140 */
unsigned char spGlob[128]; /* 0x00f2f580 */
unsigned char bloc[128]; /* 0x00f2f600 */
unsigned char g_strHandle[8192]; /* 0x00f2f680 */
int lasttime; /* 0x00f31680 */
unsigned char adr[124]; /* 0x00f31684 */
unsigned char color_00f31700[128]; /* 0x00f31700 */
unsigned char line_00f31780[1024]; /* 0x00f31780 */
unsigned char menuBuf[32768]; /* 0x00f31b80 */
unsigned char g_load[1600]; /* 0x00f39b80 */
unsigned char menuParseKeywordHash[2048]; /* 0x00f3a1c0 */
unsigned char menuBuf1[4096]; /* 0x00f3a9c0 */
unsigned char string_00f3b9c0[4160]; /* 0x00f3b9c0 */
unsigned char g_clients[665856]; /* 0x00f3ca00 */
int hud_flash_period_offhand; /* 0x00fdf300 */
unsigned char hud_flash_time_offhand[124]; /* 0x00fdf304 */
unsigned char cached_models[1024]; /* 0x00fdf380 */
unsigned char pushed[32768]; /* 0x00fdf780 */
unsigned char pushed_p[128]; /* 0x00fe7780 */
unsigned char turretInfo[2176]; /* 0x00fe7800 */
unsigned char g_HitLocConstNames[128]; /* 0x00fe8080 */
unsigned char numIPFilters[32]; /* 0x00fe8100 */
unsigned char ipFilters[8288]; /* 0x00fe8120 */
unsigned char str_00fea180[256]; /* 0x00fea180 */
unsigned char index_00fea280[128]; /* 0x00fea280 */
unsigned char rendererStats[64]; /* 0x00fea300 */
unsigned char fps_previousTimes[128]; /* 0x00fea340 */
int fps_index; /* 0x00fea3c0 */
unsigned char previous[60]; /* 0x00fea3c4 */
unsigned char cg_pmove[248]; /* 0x00fea400 */
unsigned char cg_numTriggerEntities[8]; /* 0x00fea4f8 */
unsigned char cg_triggerEntities[1024]; /* 0x00fea500 */
unsigned char cg_numSolidEntities[128]; /* 0x00fea900 */
unsigned char cg_solidEntities[1024]; /* 0x00fea980 */
unsigned char cg_eachClientLocalEntities[24064]; /* 0x00fead80 */
int ip_socket; /* 0x00ff0b80 */
unsigned char winsockInitialized[28]; /* 0x00ff0b84 */
unsigned char winsockdata[400]; /* 0x00ff0ba0 */
int net_socksPassword; /* 0x00ff0d30 */
int net_socksUsername; /* 0x00ff0d34 */
int net_socksPort; /* 0x00ff0d38 */
int net_socksServer; /* 0x00ff0d3c */
int net_socksEnabled; /* 0x00ff0d40 */
int net_noipx; /* 0x00ff0d44 */
int net_noudp; /* 0x00ff0d48 */
int networkingEnabled; /* 0x00ff0d4c */
int socks_socket; /* 0x00ff0d50 */
unsigned char socksRelayAddr[16]; /* 0x00ff0d54 */
unsigned char usingSocks[28]; /* 0x00ff0d64 */
unsigned char localIP[64]; /* 0x00ff0d80 */
unsigned char numIP[32]; /* 0x00ff0dc0 */
unsigned char socksBuf[4096]; /* 0x00ff0de0 */
unsigned char ipx_socket[32]; /* 0x00ff1de0 */
unsigned char hackSize[128]; /* 0x00ff1e00 */
int currentRecordingSample; /* 0x00ff1e80 */
unsigned char recording[28]; /* 0x00ff1e84 */
unsigned char s_clientTalkTime[256]; /* 0x00ff1ea0 */
unsigned char s_clientSamples[256]; /* 0x00ff1fa0 */
int playing_00ff20a0; /* 0x00ff20a0 */
unsigned char count_00ff20a4[92]; /* 0x00ff20a4 */
unsigned char decodeBits[128]; /* 0x00ff2100 */
unsigned char encodeBits[36]; /* 0x00ff2180 */
unsigned char g_encoder[92]; /* 0x00ff21a4 */
int sAudioRecorder; /* 0x00ff2200 */
unsigned char g_current_sample[28]; /* 0x00ff2204 */
unsigned char s_recordingSamples[2340]; /* 0x00ff2220 */
unsigned char s_recordingSamplePtr[60]; /* 0x00ff2b44 */
unsigned char dsoundplay_initialized[128]; /* 0x00ff2b80 */
int g_High; /* 0x00ff2c00 */
int g_Low; /* 0x00ff2c04 */
unsigned char g_special[120]; /* 0x00ff2c08 */
unsigned char g_WarmOff[1]; /* 0x00ff2c80 */
unsigned char g_NoTextureID[127]; /* 0x00ff2c81 */
unsigned char __ZN6CFence15sUnusedFenceIDsE[128]; /* 0x00ff2d00 */
unsigned char __ZN13CMemoryBuffer20sDelayedFreeRequestsE[128]; /* 0x00ff2d80 */
unsigned char __ZN7COpenGL7sOpenGLE[4096]; /* 0x00ff2e00 */
unsigned char g_ShadowCookieMemory[132]; /* 0x00ff3e00 */
unsigned char g_traceThreadInfo[28]; /* 0x00ff3e84 */
unsigned char com_consoleLines[128]; /* 0x00ff3ea0 */
unsigned char com_numConsoleLines[8]; /* 0x00ff3f20 */
int ui_errorTitle; /* 0x00ff3f28 */
int ui_errorMessage; /* 0x00ff3f2c */
int com_fixedConsolePosition; /* 0x00ff3f30 */
int com_errorEntered; /* 0x00ff3f34 */
int com_frameNumber; /* 0x00ff3f38 */
int com_frameTime; /* 0x00ff3f3c */
int com_animCheck; /* 0x00ff3f40 */
int com_recommendedSet; /* 0x00ff3f44 */
int sv_paused; /* 0x00ff3f48 */
int com_expectedHunkUsage; /* 0x00ff3f4c */
int nextmap; /* 0x00ff3f50 */
int cl_paused; /* 0x00ff3f54 */
int com_introPlayed; /* 0x00ff3f58 */
int shortversion; /* 0x00ff3f5c */
int version_00ff3f60; /* 0x00ff3f60 */
int com_logfile; /* 0x00ff3f64 */
int com_sv_running; /* 0x00ff3f68 */
int com_maxfps; /* 0x00ff3f6c */
int com_fixedtime; /* 0x00ff3f70 */
int com_timescaleValue; /* 0x00ff3f74 */
int com_timescale; /* 0x00ff3f78 */
int com_statmon; /* 0x00ff3f7c */
int com_developer_script; /* 0x00ff3f80 */
int com_developer; /* 0x00ff3f84 */
unsigned char com_viewlog[120]; /* 0x00ff3f88 */
int loc_warningsAsErrors; /* 0x00ff4000 */
int loc_warnings; /* 0x00ff4004 */
int loc_translate; /* 0x00ff4008 */
int loc_forceEnglish; /* 0x00ff400c */
unsigned char loc_language[16]; /* 0x00ff4010 */
unsigned char lastValidGame[256]; /* 0x00ff4020 */
unsigned char lastValidBase[256]; /* 0x00ff4120 */
unsigned char fs_serverReferencedIwdNames[4096]; /* 0x00ff4220 */
unsigned char fs_serverReferencedIwds[4096]; /* 0x00ff5220 */
unsigned char fs_numServerReferencedIwds[32]; /* 0x00ff6220 */
unsigned char fs_serverIwdNames[4096]; /* 0x00ff6240 */
unsigned char fs_serverIwds[4096]; /* 0x00ff7240 */
unsigned char fsh[21016]; /* 0x00ff8240 */
int fs_checksumFeed; /* 0x00ffd458 */
int fs_fakeChkSum; /* 0x00ffd45c */
int fs_ignoreLocalized; /* 0x00ffd460 */
int fs_restrict; /* 0x00ffd464 */
int fs_gameDirVar; /* 0x00ffd468 */
int fs_copyfiles; /* 0x00ffd46c */
int fs_cdpath; /* 0x00ffd470 */
int fs_useOldAssets; /* 0x00ffd474 */
int fs_basegame; /* 0x00ffd478 */
int fs_basepath; /* 0x00ffd47c */
int fs_homepath; /* 0x00ffd480 */
unsigned char fs_debug[28]; /* 0x00ffd484 */
unsigned char fs_gamedir[256]; /* 0x00ffd4a0 */
int fs_loadStack; /* 0x00ffd5a0 */
unsigned char com_fileAccessed[96]; /* 0x00ffd5a4 */
unsigned char com_dedicated[128]; /* 0x00ffd604 */
unsigned char scrMemTreePub[28]; /* 0x00ffd684 */
unsigned char g_default[228]; /* 0x00ffd6a0 */
int snd_touchStreamFilesOnLoad; /* 0x00ffd784 */
int snd_enableReverb; /* 0x00ffd788 */
int snd_enableStream; /* 0x00ffd78c */
int snd_enable3D; /* 0x00ffd790 */
int snd_enable2D; /* 0x00ffd794 */
int snd_slaveFadeTime; /* 0x00ffd798 */
int snd_volume; /* 0x00ffd79c */
int snd_stereo; /* 0x00ffd7a0 */
int snd_bits; /* 0x00ffd7a4 */
int snd_khz; /* 0x00ffd7a8 */
unsigned char snd_errorOnMissing[84]; /* 0x00ffd7ac */
unsigned char g_snd[5124]; /* 0x00ffd800 */
unsigned char cmd_texts[12]; /* 0x00ffec04 */
unsigned char cmd_wait[116]; /* 0x00ffec10 */
int dvarCount; /* 0x00ffec84 */
int dvar_modifiedFlags; /* 0x00ffec88 */
unsigned char sortedDvars[116]; /* 0x00ffec8c */
int mss_q3fs; /* 0x00ffed00 */
unsigned char mss_3d_provider[128]; /* 0x00ffed04 */
int visibleEffectCountBolt; /* 0x00ffed84 */
unsigned char visibleEffectCountNonBolt[24]; /* 0x00ffed88 */
unsigned char theFxHelpers[252]; /* 0x00ffeda0 */
int effectBlockSightCount; /* 0x00ffee9c */
int cullEffectCountNonBolt; /* 0x00ffeea0 */
int cullEffectCountBolt; /* 0x00ffeea4 */
int initialEffectActiveCountNonBolt; /* 0x00ffeea8 */
int initialEffectActiveCountBolt; /* 0x00ffeeac */
int privateEffectActiveCountNonBolt; /* 0x00ffeeb0 */
int privateEffectActiveCountBolt; /* 0x00ffeeb4 */
int effectActiveCount; /* 0x00ffeeb8 */
int effectActiveCountNonBolt; /* 0x00ffeebc */
unsigned char effectActiveCountBolt[64]; /* 0x00ffeec0 */
unsigned char g_effectVisArray[36000]; /* 0x00ffef00 */
int g_effectVisArrayCount; /* 0x01007ba0 */
int clusterSort; /* 0x01007ba4 */
unsigned char effectClusterCount[92]; /* 0x01007ba8 */
unsigned char fx_camera_valid[128]; /* 0x01007c04 */
unsigned char fxSchedulers[128]; /* 0x01007c84 */
int player_dmgtimer_flinchTime; /* 0x01007d04 */
int player_dmgtimer_stumbleTime; /* 0x01007d08 */
int player_dmgtimer_minScale; /* 0x01007d0c */
int player_dmgtimer_maxTime; /* 0x01007d10 */
int player_dmgtimer_timePerPoint; /* 0x01007d14 */
int player_turnAnims; /* 0x01007d18 */
int player_spectateSpeedScale; /* 0x01007d1c */
int player_backSpeedScale; /* 0x01007d20 */
int player_strafeSpeedScale; /* 0x01007d24 */
int player_footstepsThreshhold; /* 0x01007d28 */
int player_moveThreshhold; /* 0x01007d2c */
int player_adsExitDelay; /* 0x01007d30 */
int player_scopeExitOnDamage; /* 0x01007d34 */
int player_toggleBinoculars; /* 0x01007d38 */
int player_breath_snd_delay; /* 0x01007d3c */
int player_breath_snd_lerp; /* 0x01007d40 */
int player_breath_gasp_lerp; /* 0x01007d44 */
int player_breath_hold_lerp; /* 0x01007d48 */
int player_breath_gasp_scale; /* 0x01007d4c */
int player_breath_fire_delay; /* 0x01007d50 */
int player_breath_gasp_time; /* 0x01007d54 */
int player_breath_hold_time; /* 0x01007d58 */
int bg_aimSpreadMoveSpeedThreshold; /* 0x01007d5c */
int bg_bobMax; /* 0x01007d60 */
int bg_bobAmplitudeProne; /* 0x01007d64 */
int bg_bobAmplitudeDucked; /* 0x01007d68 */
int bg_bobAmplitudeStanding; /* 0x01007d6c */
int bg_swingSpeed; /* 0x01007d70 */
int friction; /* 0x01007d74 */
int stopspeed; /* 0x01007d78 */
int inertiaAngle; /* 0x01007d7c */
int inertiaDebug; /* 0x01007d80 */
int inertiaMax; /* 0x01007d84 */
int bg_fallDamageMaxHeight; /* 0x01007d88 */
int bg_fallDamageMinHeight; /* 0x01007d8c */
int bg_foliagesnd_resetinterval; /* 0x01007d90 */
int bg_foliagesnd_fastinterval; /* 0x01007d94 */
int bg_foliagesnd_slowinterval; /* 0x01007d98 */
int bg_foliagesnd_maxspeed; /* 0x01007d9c */
int bg_foliagesnd_minspeed; /* 0x01007da0 */
int bg_prone_yawcap; /* 0x01007da4 */
int bg_ladder_yawcap; /* 0x01007da8 */
int player_view_pitch_down; /* 0x01007dac */
unsigned char player_view_pitch_up[112]; /* 0x01007db0 */
unsigned char cm[384]; /* 0x01007e20 */
unsigned char bg_weaponDefs[608]; /* 0x01007fa0 */
unsigned char scrVmPub[17184]; /* 0x01008200 */
unsigned char g_script_error_level[32]; /* 0x0100c520 */
unsigned char g_script_error[2400]; /* 0x0100c540 */
unsigned char scrVarPub[262240]; /* 0x0100cea0 */
unsigned char scrVarGlob[1048608]; /* 0x0104cf00 */
unsigned char scrCompilePub[4196]; /* 0x0114cf20 */
unsigned char scrParserPub[28]; /* 0x0114df84 */
unsigned char scrParserGlob[128]; /* 0x0114dfa0 */
unsigned char scrAnimPub[1152]; /* 0x0114e020 */
unsigned char g_sa[6500]; /* 0x0114e4a0 */
unsigned char sys_timeBase[28]; /* 0x0114fe04 */
unsigned char legacyHacksArray[1792]; /* 0x0114fe20 */
unsigned char saLoadObjGlob[2272]; /* 0x01150520 */
unsigned char giFilesFound[32]; /* 0x01150e00 */
unsigned char sourceFiles[256]; /* 0x01150e20 */
int globaldefines; /* 0x01150f20 */
unsigned char numtokens[92]; /* 0x01150f24 */
unsigned char g_wv[32]; /* 0x01150f80 */
unsigned char sys_packetReceived[16480]; /* 0x01150fa0 */
unsigned char scene[124292]; /* 0x01155000 */
unsigned char frontEndDataOut[124]; /* 0x01173584 */
unsigned char g_skinBuffers[40964]; /* 0x01173600 */
int r_aspectRatio; /* 0x0117d604 */
int r_rendererInUse; /* 0x0117d608 */
int r_rendererPreference; /* 0x0117d60c */
int r_displayRefresh; /* 0x0117d610 */
int r_mode; /* 0x0117d614 */
int r_monitor; /* 0x0117d618 */
int r_fullscreen; /* 0x0117d61c */
int r_sse_skinning; /* 0x0117d620 */
int sys_SSE; /* 0x0117d624 */
int developer; /* 0x0117d628 */
int vid_ypos; /* 0x0117d62c */
int vid_xpos; /* 0x0117d630 */
int r_testFillEnable; /* 0x0117d634 */
int r_testFill; /* 0x0117d638 */
int r_testTransform; /* 0x0117d63c */
int r_sun_from_dvars; /* 0x0117d640 */
int r_outdoorFeather; /* 0x0117d644 */
int r_outdoorDownBias; /* 0x0117d648 */
int r_outdoorAwayBias; /* 0x0117d64c */
int r_glowBloomDesaturation; /* 0x0117d650 */
int r_glowBloomCutoff; /* 0x0117d654 */
unsigned char r_glowBloomIntensity[8]; /* 0x0117d658 */
unsigned char r_glowSkyBleedIntensity[8]; /* 0x0117d660 */
unsigned char r_glowRadius[8]; /* 0x0117d668 */
int r_glow; /* 0x0117d670 */
int r_distortion; /* 0x0117d674 */
int r_blur; /* 0x0117d678 */
int sc_offscreenCasterLodScale; /* 0x0117d67c */
int sc_offscreenCasterLodBias; /* 0x0117d680 */
int sc_length; /* 0x0117d684 */
int sc_shadowOutRate; /* 0x0117d688 */
int sc_shadowInRate; /* 0x0117d68c */
int sc_fadeRange; /* 0x0117d690 */
int sc_wantCountMargin; /* 0x0117d694 */
int sc_wantCount; /* 0x0117d698 */
int sc_showDebug; /* 0x0117d69c */
int sc_showOverlay; /* 0x0117d6a0 */
int sc_debugReceiverCount; /* 0x0117d6a4 */
int sc_debugCasterCount; /* 0x0117d6a8 */
int sc_count; /* 0x0117d6ac */
int sc_blur; /* 0x0117d6b0 */
int sc_enable; /* 0x0117d6b4 */
int r_forceLod; /* 0x0117d6b8 */
int r_lowestLodDist; /* 0x0117d6bc */
int r_lowLodDist; /* 0x0117d6c0 */
int r_mediumLodDist; /* 0x0117d6c4 */
int r_highLodDist; /* 0x0117d6c8 */
int r_showGroundLit; /* 0x0117d6cc */
int r_showFloatZDebug; /* 0x0117d6d0 */
int r_showFbColorDebug; /* 0x0117d6d4 */
int r_showSModelNames; /* 0x0117d6d8 */
int r_showPortals; /* 0x0117d6dc */
int r_portalMinClipArea; /* 0x0117d6e0 */
int r_portalWalkLimit; /* 0x0117d6e4 */
int r_singleCell; /* 0x0117d6e8 */
int r_portalBevelsOnly; /* 0x0117d6ec */
int r_portalBevels; /* 0x0117d6f0 */
int r_portalFineCull; /* 0x0117d6f4 */
int r_pvsStats; /* 0x0117d6f8 */
int r_skipPvs; /* 0x0117d6fc */
int r_lockPvs; /* 0x0117d700 */
int r_depthPrepassModels; /* 0x0117d704 */
int r_drawWater; /* 0x0117d708 */
int r_drawPrimFloor; /* 0x0117d70c */
int r_drawPrimCap; /* 0x0117d710 */
unsigned char r_dlightLimit[8]; /* 0x0117d714 */
int r_drawXModels; /* 0x0117d71c */
int r_drawSModels; /* 0x0117d720 */
int r_drawBModels; /* 0x0117d724 */
int r_drawEntities; /* 0x0117d728 */
int r_drawDecals; /* 0x0117d72c */
int r_drawWorld; /* 0x0117d730 */
int r_drawSun; /* 0x0117d734 */
int r_clearColor2; /* 0x0117d738 */
int r_clearColor; /* 0x0117d73c */
int r_aaSamples; /* 0x0117d740 */
int r_aaAlpha; /* 0x0117d744 */
int r_swapInterval; /* 0x0117d748 */
int r_norefresh; /* 0x0117d74c */
int r_skipBackEnd; /* 0x0117d750 */
int r_logFile; /* 0x0117d754 */
int r_objectiveColorDx7Max; /* 0x0117d758 */
int r_objectiveColorDx7Min; /* 0x0117d75c */
int r_lightTweakSunDirection; /* 0x0117d760 */
int r_lightTweakSunDiffuseColor; /* 0x0117d764 */
int r_lightTweakSunColor; /* 0x0117d768 */
int r_lightTweakAmbientColor; /* 0x0117d76c */
int r_lightTweakSunLight; /* 0x0117d770 */
int r_lightTweakDiffuseFraction; /* 0x0117d774 */
int r_lightTweakAmbient; /* 0x0117d778 */
int r_showMissingLightGrid; /* 0x0117d77c */
int r_showLightGrid; /* 0x0117d780 */
int r_vc_showlog; /* 0x0117d784 */
int r_vc_makelog; /* 0x0117d788 */
int r_railCoreWidth; /* 0x0117d78c */
int r_xdebug; /* 0x0117d790 */
int r_showVertCounts; /* 0x0117d794 */
int r_showSurfCounts; /* 0x0117d798 */
int r_showTriCounts; /* 0x0117d79c */
int r_showTris; /* 0x0117d7a0 */
int r_cosinePowerMapShift; /* 0x0117d7a4 */
int r_specularColorScale; /* 0x0117d7a8 */
int r_specularMap; /* 0x0117d7ac */
int r_normalMap; /* 0x0117d7b0 */
int r_colorMap; /* 0x0117d7b4 */
int r_lightMap; /* 0x0117d7b8 */
int r_picmip_spec; /* 0x0117d7bc */
int r_picmip_bump; /* 0x0117d7c0 */
int r_picmip; /* 0x0117d7c4 */
int r_picmip_manual; /* 0x0117d7c8 */
int r_polygonOffsetBias; /* 0x0117d7cc */
int r_polygonOffsetScale; /* 0x0117d7d0 */
int r_fog; /* 0x0117d7d4 */
int r_zfar; /* 0x0117d7d8 */
int r_znear_depthhack; /* 0x0117d7dc */
int r_znear; /* 0x0117d7e0 */
int r_lodBias; /* 0x0117d7e4 */
int r_lodScale; /* 0x0117d7e8 */
int r_smc_enable; /* 0x0117d7ec */
int r_skinCache; /* 0x0117d7f0 */
int r_multiGpu; /* 0x0117d7f4 */
int r_gpuSync; /* 0x0117d7f8 */
int r_optimizeXModels; /* 0x0117d7fc */
int r_optimizeLightmaps; /* 0x0117d800 */
int r_optimize; /* 0x0117d804 */
int r_debugEntCounts; /* 0x0117d808 */
int r_debugShader; /* 0x0117d80c */
int r_fullbright; /* 0x0117d810 */
int r_anisotropy; /* 0x0117d814 */
int r_textureMode; /* 0x0117d818 */
int r_ignoreHwGamma; /* 0x0117d81c */
int r_gamma; /* 0x0117d820 */
int r_overbrightBits; /* 0x0117d824 */
unsigned char r_ignore[120]; /* 0x0117d828 */
unsigned char dx[11744]; /* 0x0117d8a0 */
unsigned char vidConfig[64]; /* 0x01180680 */
unsigned char ri[576]; /* 0x011806c0 */
unsigned char rg[12800]; /* 0x01180900 */
unsigned char rgp[4336]; /* 0x01183b00 */
unsigned char g_disableRendering[16]; /* 0x01184bf0 */
unsigned char dxState[8580]; /* 0x01184c00 */
unsigned char g_FenceID[124]; /* 0x01186d84 */
unsigned char tess[370688]; /* 0x01186e00 */
unsigned char backEnd[224912]; /* 0x011e1600 */
unsigned char backEndData[16]; /* 0x01218490 */
unsigned char sunFlareArray[228]; /* 0x012184a0 */
unsigned char rgl[28]; /* 0x01218584 */
unsigned char s_world[640]; /* 0x012185a0 */
unsigned char lightGlob[352]; /* 0x01218820 */
unsigned char delayedGroup[260]; /* 0x01218980 */
int r_sun_fx_position; /* 0x01218a84 */
int r_sunglare_fadeout; /* 0x01218a88 */
int r_sunglare_fadein; /* 0x01218a8c */
int r_sunglare_max_lighten; /* 0x01218a90 */
int r_sunglare_max_angle; /* 0x01218a94 */
int r_sunglare_min_angle; /* 0x01218a98 */
int r_sunblind_fadeout; /* 0x01218a9c */
int r_sunblind_fadein; /* 0x01218aa0 */
int r_sunblind_max_darken; /* 0x01218aa4 */
int r_sunblind_max_angle; /* 0x01218aa8 */
int r_sunblind_min_angle; /* 0x01218aac */
int r_sunflare_fadeout; /* 0x01218ab0 */
int r_sunflare_fadein; /* 0x01218ab4 */
int r_sunflare_max_alpha; /* 0x01218ab8 */
int r_sunflare_max_angle; /* 0x01218abc */
int r_sunflare_max_size; /* 0x01218ac0 */
int r_sunflare_min_angle; /* 0x01218ac4 */
int r_sunflare_min_size; /* 0x01218ac8 */
int r_sunflare_shader; /* 0x01218acc */
int r_sunsprite_size; /* 0x01218ad0 */
unsigned char r_sunsprite_shader[44]; /* 0x01218ad4 */
unsigned char in_mouse[128]; /* 0x01218b00 */
int yytext; /* 0x01218b80 */
int yyleng; /* 0x01218b84 */
int yynerrs; /* 0x01218b88 */
unsigned char yylval[8]; /* 0x01218b8c */
unsigned char yychar[108]; /* 0x01218b94 */
int ui_playerProfileAlreadyChosen; /* 0x01218c00 */
unsigned char com_playerProfile[124]; /* 0x01218c04 */
unsigned char __ZN10CVAOPacket14sGenericPacketE[688]; /* 0x01218c80 */
unsigned char __ZN10CVAOPacket11sAllPacketsE[80]; /* 0x01218f30 */
unsigned char __ZN12CStreamSound10sQTStreamsE[128]; /* 0x01218f80 */
unsigned char playerKeys[3392]; /* 0x01219000 */
unsigned char g_consoleField[280]; /* 0x01219d40 */
int historyLine; /* 0x01219e58 */
int nextHistoryLine; /* 0x01219e5c */
unsigned char historyEditLines[8992]; /* 0x01219e60 */
int cg_weaponrightbone; /* 0x0121c180 */
int cg_weaponleftbone; /* 0x0121c184 */
int cg_blood; /* 0x0121c188 */
int cg_headIconMinScreenRadius; /* 0x0121c18c */
int cg_constantSizeHeadIcons; /* 0x0121c190 */
int cg_voiceIconSize; /* 0x0121c194 */
int cg_connectionIconSize; /* 0x0121c198 */
int cg_scriptIconSize; /* 0x0121c19c */
int cg_youInKillCamSize; /* 0x0121c1a0 */
int cg_shock_mouse_fadeTime; /* 0x0121c1a4 */
int cg_shock_mouse_sensitivityscale; /* 0x0121c1a8 */
int cg_shock_mouse_maxyawspeed; /* 0x0121c1ac */
int cg_shock_mouse_maxpitchspeed; /* 0x0121c1b0 */
int cg_shock_mouse; /* 0x0121c1b4 */
int cg_shock_volume_shellshock; /* 0x0121c1b8 */
int cg_shock_volume_announcer; /* 0x0121c1bc */
int cg_shock_volume_music; /* 0x0121c1c0 */
int cg_shock_volume_local; /* 0x0121c1c4 */
int cg_shock_volume_body; /* 0x0121c1c8 */
int cg_shock_volume_item; /* 0x0121c1cc */
int cg_shock_volume_voice; /* 0x0121c1d0 */
int cg_shock_volume_weapon; /* 0x0121c1d4 */
int cg_shock_volume_menu; /* 0x0121c1d8 */
int cg_shock_volume_auto2d; /* 0x0121c1dc */
int cg_shock_volume_auto; /* 0x0121c1e0 */
int cg_shock_soundModEndDelay; /* 0x0121c1e4 */
int cg_shock_soundWetLevel; /* 0x0121c1e8 */
int cg_shock_soundDryLevel; /* 0x0121c1ec */
int cg_shock_soundRoomType; /* 0x0121c1f0 */
int cg_shock_soundLoopEndDelay; /* 0x0121c1f4 */
int cg_shock_soundLoopFadeTime; /* 0x0121c1f8 */
int cg_shock_soundFadeOutTime; /* 0x0121c1fc */
int cg_shock_soundFadeInTime; /* 0x0121c200 */
int cg_shock_sound; /* 0x0121c204 */
int cg_shock_viewKickRadius; /* 0x0121c208 */
int cg_shock_viewKickPeriod; /* 0x0121c20c */
int cg_shock_screenBlendFadeTime; /* 0x0121c210 */
int cg_shock_screenBlendTime; /* 0x0121c214 */
int cg_scoreboardItemHeight; /* 0x0121c218 */
int cg_scoreboardBannerHeight; /* 0x0121c21c */
int cg_scoreboardScrollStep; /* 0x0121c220 */
int cg_drawGameMessages; /* 0x0121c224 */
int cg_gameBoldMessageWidth; /* 0x0121c228 */
int cg_gameMessageWidth; /* 0x0121c22c */
int cg_subtitleCharHeight; /* 0x0121c230 */
int cg_subtitlePosY; /* 0x0121c234 */
int cg_subtitlePosX; /* 0x0121c238 */
int cg_subtitleWidthWidescreen; /* 0x0121c23c */
int cg_subtitleWidthStandard; /* 0x0121c240 */
int cg_subtitleMinTime; /* 0x0121c244 */
int cg_subtitles; /* 0x0121c248 */
int cg_minicon; /* 0x0121c24c */
int cg_developer; /* 0x0121c250 */
int cg_dumpAnims; /* 0x0121c254 */
int cg_descriptiveText; /* 0x0121c258 */
int cg_voiceSpriteTime; /* 0x0121c25c */
int cg_noTaunt; /* 0x0121c260 */
int cg_predictItems; /* 0x0121c264 */
int cg_paused; /* 0x0121c268 */
int cg_chatHeight; /* 0x0121c26c */
int cg_chatTime; /* 0x0121c270 */
int cg_synchronousClients; /* 0x0121c274 */
int cg_thirdPersonAngle; /* 0x0121c278 */
int cg_thirdPersonRange; /* 0x0121c27c */
int cg_thirdPerson; /* 0x0121c280 */
int cg_fovMin; /* 0x0121c284 */
int cg_fovScale; /* 0x0121c288 */
int cg_fov; /* 0x0121c28c */
int cg_tracerScaleDistRange; /* 0x0121c290 */
int cg_tracerScaleMinDist; /* 0x0121c294 */
int cg_tracerScale; /* 0x0121c298 */
int cg_tracerSpeed; /* 0x0121c29c */
int cg_tracerLength; /* 0x0121c2a0 */
int cg_tracerWidth; /* 0x0121c2a4 */
int cg_tracerChance; /* 0x0121c2a8 */
int cg_gun_move_minspeed; /* 0x0121c2ac */
int cg_gun_move_rate; /* 0x0121c2b0 */
int cg_gun_ofs_u; /* 0x0121c2b4 */
int cg_gun_ofs_r; /* 0x0121c2b8 */
int cg_gun_ofs_f; /* 0x0121c2bc */
int cg_gun_move_u; /* 0x0121c2c0 */
int cg_gun_move_r; /* 0x0121c2c4 */
int cg_gun_move_f; /* 0x0121c2c8 */
int cg_gun_z; /* 0x0121c2cc */
int cg_gun_y; /* 0x0121c2d0 */
int cg_gun_x; /* 0x0121c2d4 */
int cg_hintFadeTime; /* 0x0121c2d8 */
int cg_cursorHints; /* 0x0121c2dc */
int cg_drawGun; /* 0x0121c2e0 */
int cg_viewsize; /* 0x0121c2e4 */
int cg_brass; /* 0x0121c2e8 */
int cg_marksLimit; /* 0x0121c2ec */
int cg_marks; /* 0x0121c2f0 */
int cg_footsteps; /* 0x0121c2f4 */
int cg_showmiss; /* 0x0121c2f8 */
int cg_nopredict; /* 0x0121c2fc */
int cg_errorDecay; /* 0x0121c300 */
int cg_debugEvents; /* 0x0121c304 */
int cg_debugPosition; /* 0x0121c308 */
int cg_drawMantleHint; /* 0x0121c30c */
int cg_drawBreathHint; /* 0x0121c310 */
int cg_drawHealth; /* 0x0121c314 */
int cg_teamChatsOnly; /* 0x0121c318 */
int cg_draw2D; /* 0x0121c31c */
int cg_crosshairEnemyColor; /* 0x0121c320 */
int cg_crosshairDynamic; /* 0x0121c324 */
int cg_crosshairAlphaMin; /* 0x0121c328 */
int cg_crosshairAlpha; /* 0x0121c32c */
int cg_weaponCycleDelay; /* 0x0121c330 */
int cg_drawLagometer; /* 0x0121c334 */
int cg_hudProneY; /* 0x0121c338 */
int cg_centerPrintY; /* 0x0121c33c */
int cg_hudSayPosition; /* 0x0121c340 */
int cg_hudChatPosition; /* 0x0121c344 */
int cg_hudGrenadePointerPulseMin; /* 0x0121c348 */
int cg_hudGrenadePointerPulseMax; /* 0x0121c34c */
int cg_hudGrenadePointerPulseFreq; /* 0x0121c350 */
int cg_hudGrenadePointerPivot; /* 0x0121c354 */
int cg_hudGrenadePointerWidth; /* 0x0121c358 */
int cg_hudGrenadePointerHeight; /* 0x0121c35c */
int cg_hudGrenadeIconWidth; /* 0x0121c360 */
int cg_hudGrenadeIconHeight; /* 0x0121c364 */
int cg_hudGrenadeIconOffset; /* 0x0121c368 */
int cg_hudGrenadeIconMaxHeight; /* 0x0121c36c */
int cg_hudGrenadeIconMaxRange; /* 0x0121c370 */
int cg_hudGrenadeIconInScope; /* 0x0121c374 */
int cg_hudDamageIconInScope; /* 0x0121c378 */
int cg_hudDamageIconTime; /* 0x0121c37c */
int cg_hudDamageIconOffset; /* 0x0121c380 */
int cg_hudDamageIconHeight; /* 0x0121c384 */
int cg_hudDamageIconWidth; /* 0x0121c388 */
int cg_hudStanceHintPrints; /* 0x0121c38c */
int cg_hudStanceFlash; /* 0x0121c390 */
int cg_hudObjectiveMinAlpha; /* 0x0121c394 */
int cg_hudObjectiveMaxRange; /* 0x0121c398 */
int cg_hudObjectiveMinHeight; /* 0x0121c39c */
int cg_hudCompassSoundPingFadeTime; /* 0x0121c3a0 */
int cg_hudCompassSpringyPointers; /* 0x0121c3a4 */
int cg_hudCompassMinRadius; /* 0x0121c3a8 */
int cg_hudCompassMinRange; /* 0x0121c3ac */
int cg_hudCompassMaxRange; /* 0x0121c3b0 */
int cg_hudCompassSize; /* 0x0121c3b4 */
int cg_drawCrosshairNamesPosY; /* 0x0121c3b8 */
int cg_drawCrosshairNamesPosX; /* 0x0121c3bc */
int cg_drawCrosshairNames; /* 0x0121c3c0 */
int cg_drawTurretCrosshair; /* 0x0121c3c4 */
int cg_drawCrosshair; /* 0x0121c3c8 */
int cg_drawSnapshot; /* 0x0121c3cc */
int cg_drawScriptUsage; /* 0x0121c3d0 */
int cg_drawSoundOverlay; /* 0x0121c3d4 */
int cg_drawMaterial; /* 0x0121c3d8 */
int cg_drawFPS; /* 0x0121c3dc */
unsigned char cg_centertime[32]; /* 0x0121c3e0 */
unsigned char cgDC[640]; /* 0x0121c400 */
int old_com_frameTime; /* 0x0121c680 */
unsigned char frame_msec[28]; /* 0x0121c684 */
unsigned char re_0121c6a0[352]; /* 0x0121c6a0 */
unsigned char cl_pinglist[16704]; /* 0x0121c800 */
unsigned char g_waitingForServer[32]; /* 0x01220940 */
unsigned char cls[2755264]; /* 0x01220960 */
unsigned char clientConnections[296992]; /* 0x014c1420 */
unsigned char clients[1547284]; /* 0x01509c40 */
int cl_voice; /* 0x01683854 */
int name_01683858; /* 0x01683858 */
int nextdemo; /* 0x0168385c */
int cl_ingame; /* 0x01683860 */
int fx_profile; /* 0x01683864 */
int fx_visMinTraceDist; /* 0x01683868 */
int fx_count; /* 0x0168386c */
int fx_freeze; /* 0x01683870 */
int fx_debugBolt; /* 0x01683874 */
int fx_debug; /* 0x01683878 */
int fx_sort; /* 0x0168387c */
int fx_cull; /* 0x01683880 */
int fx_draw; /* 0x01683884 */
int fx_enable; /* 0x01683888 */
int cl_serverStatusResendTime; /* 0x0168388c */
unsigned char cl_inGameVideo[8]; /* 0x01683890 */
int cl_allowDownload; /* 0x01683898 */
int cl_motdString; /* 0x0168389c */
int cl_activeAction; /* 0x016838a0 */
int m_filter; /* 0x016838a4 */
int m_side; /* 0x016838a8 */
int m_forward; /* 0x016838ac */
int m_yaw; /* 0x016838b0 */
int m_pitch; /* 0x016838b4 */
int cl_showMouseRate; /* 0x016838b8 */
int cl_mouseAccel; /* 0x016838bc */
int cl_sensitivity; /* 0x016838c0 */
int cl_freelook; /* 0x016838c4 */
int cl_forceavidemo; /* 0x016838c8 */
int cl_avidemo; /* 0x016838cc */
int cl_showServerCommands; /* 0x016838d0 */
int cl_showSend; /* 0x016838d4 */
int cl_shownuments; /* 0x016838d8 */
int cl_freezeDemo; /* 0x016838dc */
int cl_showTimeDelta; /* 0x016838e0 */
int cl_packetdup; /* 0x016838e4 */
int cl_maxpackets; /* 0x016838e8 */
int cl_connectTimeout; /* 0x016838ec */
int cl_timeout; /* 0x016838f0 */
int cl_noprint; /* 0x016838f4 */
unsigned char cl_nodelta[8]; /* 0x016838f8 */
unsigned char gameInitialized[128]; /* 0x01683900 */
int ui_playerProfileNameNew; /* 0x01683980 */
int ui_playerProfileSelected; /* 0x01683984 */
int ui_playerProfileCount; /* 0x01683988 */
int ui_serverStatusTimeOut; /* 0x0168398c */
int ui_currentMap; /* 0x01683990 */
int ui_browserKillcam; /* 0x01683994 */
int ui_browserFriendlyfire; /* 0x01683998 */
int ui_browserMod; /* 0x0168399c */
int ui_browserShowDedicated; /* 0x016839a0 */
int ui_browserShowPure; /* 0x016839a4 */
int ui_browserShowNoPassword; /* 0x016839a8 */
int ui_browserShowPassword; /* 0x016839ac */
int ui_browserShowEmpty; /* 0x016839b0 */
int ui_browserShowFull; /* 0x016839b4 */
int ui_currentNetMap; /* 0x016839b8 */
int ui_dedicated; /* 0x016839bc */
int ui_joinGameType; /* 0x016839c0 */
int ui_netGameTypeName; /* 0x016839c4 */
int ui_netGameType; /* 0x016839c8 */
unsigned char ui_netSource[8]; /* 0x016839cc */
int ui_extraBigFont; /* 0x016839d4 */
int ui_bigFont; /* 0x016839d8 */
int ui_smallFont; /* 0x016839dc */
unsigned char ui_gametype[32]; /* 0x016839e0 */
unsigned char uiInfoArray[4288]; /* 0x01683a00 */
unsigned char sharedUiInfo[115392]; /* 0x01684ac0 */
int net_lanauthorize; /* 0x016a0d80 */
int net_showprofile; /* 0x016a0d84 */
int net_profile; /* 0x016a0d88 */
int packetDebug; /* 0x016a0d8c */
int showdrop; /* 0x016a0d90 */
unsigned char showpackets[108]; /* 0x016a0d94 */
int sv_allowedClan2; /* 0x016a0e00 */
int sv_allowedClan1; /* 0x016a0e04 */
int sv_referencedIwdNames; /* 0x016a0e08 */
int sv_referencedIwds; /* 0x016a0e0c */
int sv_iwdNames; /* 0x016a0e10 */
int sv_iwds; /* 0x016a0e14 */
int sv_voiceQuality; /* 0x016a0e18 */
int sv_voice; /* 0x016a0e1c */
int sv_disableClientConsole; /* 0x016a0e20 */
int sv_kickBanTime; /* 0x016a0e24 */
int sv_mapRotationCurrent; /* 0x016a0e28 */
int sv_mapRotation; /* 0x016a0e2c */
int sv_showAverageBPS; /* 0x016a0e30 */
int sv_packet_info; /* 0x016a0e34 */
int sv_showCommands; /* 0x016a0e38 */
int sv_allowAnonymous; /* 0x016a0e3c */
int sv_cheats; /* 0x016a0e40 */
int sv_floodProtect; /* 0x016a0e44 */
int sv_pure; /* 0x016a0e48 */
int sv_debugReliableCmds; /* 0x016a0e4c */
int sv_debugRate; /* 0x016a0e50 */
int sv_gametype; /* 0x016a0e54 */
int sv_maxPing; /* 0x016a0e58 */
int sv_minPing; /* 0x016a0e5c */
int sv_maxRate; /* 0x016a0e60 */
int sv_serverid; /* 0x016a0e64 */
int sv_mapname; /* 0x016a0e68 */
int sv_padPackets; /* 0x016a0e6c */
int sv_reconnectlimit; /* 0x016a0e70 */
int sv_hostname; /* 0x016a0e74 */
int sv_privateClients; /* 0x016a0e78 */
int sv_maxclients; /* 0x016a0e7c */
int sv_allowDownload; /* 0x016a0e80 */
int sv_privatePassword; /* 0x016a0e84 */
int rcon_password; /* 0x016a0e88 */
int sv_zombietime; /* 0x016a0e8c */
int sv_timeout; /* 0x016a0e90 */
unsigned char sv_fps[108]; /* 0x016a0e94 */
unsigned char sv[390528]; /* 0x016a0f00 */
unsigned char svs[41216]; /* 0x01700480 */
int con_restricted; /* 0x0170a580 */
int con_miniconlines; /* 0x0170a584 */
int con_minicontime; /* 0x0170a588 */
int con_boldgamemessagetime; /* 0x0170a58c */
unsigned char con_gamemessagetime[16]; /* 0x0170a590 */
unsigned char cl_serverStatusList[131680]; /* 0x0170a5a0 */
unsigned char scr_initialized[128]; /* 0x0172a800 */
unsigned char markVerts[69632]; /* 0x0172a880 */
unsigned char cg_markPolys[663552]; /* 0x0173b880 */
unsigned char cg_freeMarkPolys[128]; /* 0x017dd880 */
unsigned char buf_017dd900[128]; /* 0x017dd900 */
int cl_bypassMouseInput; /* 0x017dd980 */
int cl_talking; /* 0x017dd984 */
int cl_anglespeedkey; /* 0x017dd988 */
int cl_pitchspeed; /* 0x017dd98c */
unsigned char cl_yawspeed[16]; /* 0x017dd990 */
int cl_stanceHoldTime; /* 0x017dd9a0 */
unsigned char cl_analog_attack_threshold[92]; /* 0x017dd9a4 */
int hud_deathQuoteFadeTime; /* 0x017dda00 */
int hud_health_pulserate_critical; /* 0x017dda04 */
int hud_health_pulserate_injured; /* 0x017dda08 */
int hud_health_startpulse_critical; /* 0x017dda0c */
int hud_health_startpulse_injured; /* 0x017dda10 */
int hud_fade_offhand; /* 0x017dda14 */
int hud_fade_stance; /* 0x017dda18 */
int hud_fade_compass; /* 0x017dda1c */
int hud_fade_healthbar; /* 0x017dda20 */
unsigned char hud_fade_ammodisplay[92]; /* 0x017dda24 */
unsigned char g_scr_data[14080]; /* 0x017dda80 */
unsigned char itemParseKeywordHash[2048]; /* 0x017e1180 */
int g_dumpAnims; /* 0x017e1980 */
int g_voteAbstainWeight; /* 0x017e1984 */
int g_oldVoting; /* 0x017e1988 */
int g_antilag; /* 0x017e198c */
int player_meleeHeight; /* 0x017e1990 */
int player_meleeWidth; /* 0x017e1994 */
int player_meleeRange; /* 0x017e1998 */
int g_friendlyNameDist; /* 0x017e199c */
int g_friendlyfireDist; /* 0x017e19a0 */
int g_debugLocDamage; /* 0x017e19a4 */
int g_NoScriptSpam; /* 0x017e19a8 */
int g_TeamColor_Axis; /* 0x017e19ac */
int g_TeamColor_Allies; /* 0x017e19b0 */
int g_TeamName_Axis; /* 0x017e19b4 */
int g_TeamName_Allies; /* 0x017e19b8 */
int g_ScoresBanner_Spectators; /* 0x017e19bc */
int g_ScoresBanner_None; /* 0x017e19c0 */
int g_ScoresBanner_Axis; /* 0x017e19c4 */
int g_ScoresBanner_Allies; /* 0x017e19c8 */
unsigned char g_smoothClients[8]; /* 0x017e19cc */
int g_banIPs; /* 0x017e19d4 */
int g_listEntity; /* 0x017e19d8 */
unsigned char g_deadChat[8]; /* 0x017e19dc */
int g_allowVote; /* 0x017e19e4 */
int g_logSync; /* 0x017e19e8 */
int g_log; /* 0x017e19ec */
int g_voiceChatTalkingDuration; /* 0x017e19f0 */
int voice_deadChat; /* 0x017e19f4 */
int voice_global; /* 0x017e19f8 */
int voice_localEcho; /* 0x017e19fc */
int g_mantleBlockTimeBuffer; /* 0x017e1a00 */
int g_clonePlayerMaxVelocity; /* 0x017e1a04 */
int g_dropUpSpeedRand; /* 0x017e1a08 */
int g_dropUpSpeedBase; /* 0x017e1a0c */
int g_dropForwardSpeed; /* 0x017e1a10 */
int g_playerCollisionEjectSpeed; /* 0x017e1a14 */
int g_synchronousClients; /* 0x017e1a18 */
int g_motd; /* 0x017e1a1c */
int g_maxDroppedWeapons; /* 0x017e1a20 */
int g_weaponAmmoPools; /* 0x017e1a24 */
int g_debugBullets; /* 0x017e1a28 */
int g_debugDamage; /* 0x017e1a2c */
int g_inactivity; /* 0x017e1a30 */
int g_useholdspawndelay; /* 0x017e1a34 */
int g_useholdtime; /* 0x017e1a38 */
int g_knockback; /* 0x017e1a3c */
int g_cheats; /* 0x017e1a40 */
int g_gravity; /* 0x017e1a44 */
int g_speed; /* 0x017e1a48 */
int g_dedicated; /* 0x017e1a4c */
int g_maxclients; /* 0x017e1a50 */
int g_password; /* 0x017e1a54 */
unsigned char g_gametype_017e1a58[40]; /* 0x017e1a58 */
unsigned char g_entities[573440]; /* 0x017e1a80 */
unsigned char level_bgs[813568]; /* 0x0186da80 */
unsigned char level[13952]; /* 0x01934480 */
unsigned char itemRegistered[1024]; /* 0x01937b00 */
unsigned char g_hudelems[143392]; /* 0x01937f00 */
unsigned char __ZN12UI_Component1gE[224]; /* 0x0195af20 */
unsigned char g_fHitLocDamageMult[128]; /* 0x0195b000 */
unsigned char scr_const[256]; /* 0x0195b080 */
unsigned char lagometer[1664]; /* 0x0195b180 */
unsigned char cl_connectedToPureServer[128]; /* 0x0195b800 */
int removeMeWhenMPStopsCrashingInHere; /* 0x0195b880 */
unsigned char ejectBrassCasingOrigin[124]; /* 0x0195b884 */
int cg_freeLocalEntities; /* 0x0195b900 */
unsigned char cg_eachClientFreeLocalEntities[28]; /* 0x0195b904 */
unsigned char cg_eachClientActiveLocalEntities[224]; /* 0x0195b920 */
unsigned char levelSamples[24]; /* 0x0195ba00 */
unsigned char voice_current_voicelevel[8]; /* 0x0195ba18 */
unsigned char old_rec_source[256]; /* 0x0195ba20 */
int mic_current_reclevel; /* 0x0195bb20 */
int mic_old_reclevel; /* 0x0195bb24 */
unsigned char winvoice_mic_scaler[8]; /* 0x0195bb28 */
int winvoice_save_voice; /* 0x0195bb30 */
int winvoice_mic_reclevel; /* 0x0195bb34 */
unsigned char winvoice_mic_mute[72]; /* 0x0195bb38 */
unsigned char partial_audio_buffer[1280]; /* 0x0195bb80 */
unsigned char enc_buffer[4096]; /* 0x0195c080 */
unsigned char g_decode_frame_size[128]; /* 0x0195d080 */
unsigned char current_audioCallback[128]; /* 0x0195d100 */
int catch_exception_raise; /* 0x0195d180 */
int catch_exception_raise_state; /* 0x0195d184 */
int catch_exception_raise_state_identity; /* 0x0195d188 */
int clock_alarm_reply; /* 0x0195d18c */
int do_mach_notify_dead_name; /* 0x0195d190 */
int do_mach_notify_no_senders; /* 0x0195d194 */
int do_mach_notify_port_deleted; /* 0x0195d198 */
int do_mach_notify_send_once; /* 0x0195d19c */
int do_seqnos_mach_notify_dead_name; /* 0x0195d1a0 */
int do_seqnos_mach_notify_no_senders; /* 0x0195d1a4 */
int do_seqnos_mach_notify_port_deleted; /* 0x0195d1a8 */
int do_seqnos_mach_notify_send_once; /* 0x0195d1ac */
int receive_samples; /* 0x0195d1b0 */
