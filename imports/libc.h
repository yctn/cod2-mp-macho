#ifndef IMPORTS_LIBC_H
#define IMPORTS_LIBC_H

/* Import stubs for libc */

int AUGraphConnectNodeInput(); /* _AUGraphConnectNodeInput */
int AUGraphGetCPULoad(); /* _AUGraphGetCPULoad */
int AUGraphGetNodeInfo(); /* _AUGraphGetNodeInfo */
int AUGraphInitialize(); /* _AUGraphInitialize */
int AUGraphNewNode(); /* _AUGraphNewNode */
int AUGraphOpen(); /* _AUGraphOpen */
int AUGraphStart(); /* _AUGraphStart */
int AUGraphStop(); /* _AUGraphStop */
int AUGraphUpdate(); /* _AUGraphUpdate */
int AddDurationToAbsolute(); /* _AddDurationToAbsolute */
int AddMovieResource(); /* _AddMovieResource */
int AdvanceKeyboardFocus(); /* _AdvanceKeyboardFocus */
int AlertSoundPlay(); /* _AlertSoundPlay */
int AppendMenuItemTextWithCFString(); /* _AppendMenuItemTextWithCFString */
int CGAcquireDisplayFadeReservation(); /* _CGAcquireDisplayFadeReservation */
int CGAssociateMouseAndMouseCursorPosition(); /* _CGAssociateMouseAndMouseCursorPosition */
int CGContextClearRect(); /* _CGContextClearRect */
int CGContextDrawImage(); /* _CGContextDrawImage */
int CGContextFlush(); /* _CGContextFlush */
int CGDataProviderCreateWithURL(); /* _CGDataProviderCreateWithURL */
int CGDataProviderRelease(); /* _CGDataProviderRelease */
int CGDisplayAvailableModes(); /* _CGDisplayAvailableModes */
int CGDisplayBitsPerPixel(); /* _CGDisplayBitsPerPixel */
int CGDisplayBounds(); /* _CGDisplayBounds */
int CGDisplayCurrentMode(); /* _CGDisplayCurrentMode */
int CGDisplayFade(); /* _CGDisplayFade */
int CGDisplayIDToOpenGLDisplayMask(); /* _CGDisplayIDToOpenGLDisplayMask */
int CGDisplayIOServicePort(); /* _CGDisplayIOServicePort */
int CGDisplayPixelsHigh(); /* _CGDisplayPixelsHigh */
int CGDisplayPixelsWide(); /* _CGDisplayPixelsWide */
int CGGetActiveDisplayList(); /* _CGGetActiveDisplayList */
int CGGetDisplayTransferByTable(); /* _CGGetDisplayTransferByTable */
int CGImageCreateWithPNGDataProvider(); /* _CGImageCreateWithPNGDataProvider */
int CGImageRelease(); /* _CGImageRelease */
int CGLChoosePixelFormat(); /* _CGLChoosePixelFormat */
int CGLCreateContext(); /* _CGLCreateContext */
int CGLDescribeRenderer(); /* _CGLDescribeRenderer */
int CGLDestroyContext(); /* _CGLDestroyContext */
int CGLDestroyPixelFormat(); /* _CGLDestroyPixelFormat */
int CGLDestroyRendererInfo(); /* _CGLDestroyRendererInfo */
int CGLGetCurrentContext(); /* _CGLGetCurrentContext */
int CGLQueryRendererInfo(); /* _CGLQueryRendererInfo */
int CGLSetCurrentContext(); /* _CGLSetCurrentContext */
int CGRectEqualToRect(); /* _CGRectEqualToRect */
int CGRectGetHeight(); /* _CGRectGetHeight */
int CGRectGetWidth(); /* _CGRectGetWidth */
int CGRectIsEmpty(); /* _CGRectIsEmpty */
int CGRectUnion(); /* _CGRectUnion */
int CGRectZero(); /* _CGRectZero */
int CGReleaseDisplayFadeReservation(); /* _CGReleaseDisplayFadeReservation */
int CGSetDisplayTransferByTable(); /* _CGSetDisplayTransferByTable */
int CGWarpMouseCursorPosition(); /* _CGWarpMouseCursorPosition */
int ClipRect(); /* _ClipRect */
int CloseComponent(); /* _CloseComponent */
int CloseMovieFile(); /* _CloseMovieFile */
int CloseRgn(); /* _CloseRgn */
int CollapseWindow(); /* _CollapseWindow */
int CreateEvent(); /* _CreateEvent */
int CreateNewWindow(); /* _CreateNewWindow */
int CreateNibReferenceWithCFBundle(); /* _CreateNibReferenceWithCFBundle */
int CreateStandardAlert(); /* _CreateStandardAlert */
int CreateWindowFromNib(); /* _CreateWindowFromNib */
int DMGetFirstScreenDevice(); /* _DMGetFirstScreenDevice */
int DMGetNextScreenDevice(); /* _DMGetNextScreenDevice */
int DisableControl(); /* _DisableControl */
int DisableMenuItem(); /* _DisableMenuItem */
int DisposeAUGraph(); /* _DisposeAUGraph */
int DisposeGWorld(); /* _DisposeGWorld */
int DisposeHandle(); /* _DisposeHandle */
int DisposeMovie(); /* _DisposeMovie */
int DisposeNibReference(); /* _DisposeNibReference */
int DisposeRgn(); /* _DisposeRgn */
int DisposeWindow(); /* _DisposeWindow */
int DrawThemeFocusRect(); /* _DrawThemeFocusRect */
int DrawThemeMenuBarBackground(); /* _DrawThemeMenuBarBackground */
int EnableControl(); /* _EnableControl */
int EndMediaEdits(); /* _EndMediaEdits */
int EqualRect(); /* _EqualRect */
int EventAvail(); /* _EventAvail */
int FSCloseIterator(); /* _FSCloseIterator */
int FSDeleteObject(); /* _FSDeleteObject */
int FSGetCatalogInfo(); /* _FSGetCatalogInfo */
int FSGetCatalogInfoBulk(); /* _FSGetCatalogInfoBulk */
int FSGetVolumeInfo(); /* _FSGetVolumeInfo */
int FSMakeFSSpec(); /* _FSMakeFSSpec */
int FSOpenIterator(); /* _FSOpenIterator */
int FSPathMakeRef(); /* _FSPathMakeRef */
int FSRefMakePath(); /* _FSRefMakePath */
int FSSetCatalogInfo(); /* _FSSetCatalogInfo */
int FSpMakeFSRef(); /* _FSpMakeFSRef */
int FindNextComponent(); /* _FindNextComponent */
int FlushEventQueue(); /* _FlushEventQueue */
int ForeColor(); /* _ForeColor */
int FrameRoundRect(); /* _FrameRoundRect */
int Gestalt(); /* _Gestalt */
int GetApplicationEventTarget(); /* _GetApplicationEventTarget */
int GetAvailableWindowPositioningBounds(); /* _GetAvailableWindowPositioningBounds */
int GetComponentVersion(); /* _GetComponentVersion */
int GetCompressionInfo(); /* _GetCompressionInfo */
int GetControlBounds(); /* _GetControlBounds */
int GetControlByID(); /* _GetControlByID */
int GetControlData(); /* _GetControlData */
int GetControlDataSize(); /* _GetControlDataSize */
int GetControlKind(); /* _GetControlKind */
int GetControlMaximum(); /* _GetControlMaximum */
int GetControlOwner(); /* _GetControlOwner */
int GetControlReference(); /* _GetControlReference */
int GetCurrentEventTime(); /* _GetCurrentEventTime */
int GetCurrentKeyModifiers(); /* _GetCurrentKeyModifiers */
int GetCurrentProcess(); /* _GetCurrentProcess */
int GetCursor(); /* _GetCursor */
int GetEventClass(); /* _GetEventClass */
int GetEventDispatcherTarget(); /* _GetEventDispatcherTarget */
int GetEventKind(); /* _GetEventKind */
int GetEventParameter(); /* _GetEventParameter */
int GetGWorldPixMap(); /* _GetGWorldPixMap */
int GetGlobalMouse(); /* _GetGlobalMouse */
int GetHandleSize(); /* _GetHandleSize */
int GetIconRefFromFileInfo(); /* _GetIconRefFromFileInfo */
int GetIndMenuItemWithCommandID(); /* _GetIndMenuItemWithCommandID */
int GetMainDevice(); /* _GetMainDevice */
int GetMainEventLoop(); /* _GetMainEventLoop */
int GetMainEventQueue(); /* _GetMainEventQueue */
int GetMediaDuration(); /* _GetMediaDuration */
int GetMediaHandler(); /* _GetMediaHandler */
int GetMediaSampleDescription(); /* _GetMediaSampleDescription */
int GetMenuEventTarget(); /* _GetMenuEventTarget */
int GetMenuHandle(); /* _GetMenuHandle */
int GetMovieDuration(); /* _GetMovieDuration */
int GetMovieIndTrackType(); /* _GetMovieIndTrackType */
int GetMoviePreferredRate(); /* _GetMoviePreferredRate */
int GetMovieTime(); /* _GetMovieTime */
int GetMovieTimeScale(); /* _GetMovieTimeScale */
int GetNextProcess(); /* _GetNextProcess */
int GetPixRowBytes(); /* _GetPixRowBytes */
int GetPort(); /* _GetPort */
int GetProcessBundleLocation(); /* _GetProcessBundleLocation */
int GetProcessInformation(); /* _GetProcessInformation */
int GetQDGlobalsArrow(); /* _GetQDGlobalsArrow */
int GetStandardAlertDefaultParams(); /* _GetStandardAlertDefaultParams */
int GetTrackMedia(); /* _GetTrackMedia */
int GetWRefCon(); /* _GetWRefCon */
int GetWindowEventTarget(); /* _GetWindowEventTarget */
int GetWindowPort(); /* _GetWindowPort */
int GetWindowPortBounds(); /* _GetWindowPortBounds */
int GetWindowResizeLimits(); /* _GetWindowResizeLimits */
int GoToBeginningOfMovie(); /* _GoToBeginningOfMovie */
int HITextViewGetTXNObject(); /* _HITextViewGetTXNObject */
int HIViewGetRoot(); /* _HIViewGetRoot */
int HIViewGetViewForMouseEvent(); /* _HIViewGetViewForMouseEvent */
int HandleControlKey(); /* _HandleControlKey */
int HideControl(); /* _HideControl */
int HideCursor(); /* _HideCursor */
int HideMenuBar(); /* _HideMenuBar */
int HideWindow(); /* _HideWindow */
int InitCursor(); /* _InitCursor */
int InsertMediaIntoTrack(); /* _InsertMediaIntoTrack */
int InsertMenu(); /* _InsertMenu */
int InsetRect(); /* _InsetRect */
int InstallEventHandler(); /* _InstallEventHandler */
int InstallEventLoopTimer(); /* _InstallEventLoopTimer */
int InvalMenuBar(); /* _InvalMenuBar */
int IsMovieDone(); /* _IsMovieDone */
int IsWindowVisible(); /* _IsWindowVisible */
int LSCopyItemInfoForRef(); /* _LSCopyItemInfoForRef */
int LSOpenFSRef(); /* _LSOpenFSRef */
int LockPixels(); /* _LockPixels */
int MPDelayUntil(); /* _MPDelayUntil */
int MapRect(); /* _MapRect */
int MediaSetSoundBalance(); /* _MediaSetSoundBalance */
int Microseconds(); /* _Microseconds */
int MoveWindow(); /* _MoveWindow */
int MoviesTask(); /* _MoviesTask */
int NewAUGraph(); /* _NewAUGraph */
int NewControlEditTextValidationUPP(); /* _NewControlEditTextValidationUPP */
int NewControlKeyFilterUPP(); /* _NewControlKeyFilterUPP */
int NewControlUserPaneDrawUPP(); /* _NewControlUserPaneDrawUPP */
int NewControlUserPaneHitTestUPP(); /* _NewControlUserPaneHitTestUPP */
int NewControlUserPaneTrackingUPP(); /* _NewControlUserPaneTrackingUPP */
int NewGWorld(); /* _NewGWorld */
int NewHandle(); /* _NewHandle */
int NewMenu(); /* _NewMenu */
int NewMovieFromFile(); /* _NewMovieFromFile */
int NewRgn(); /* _NewRgn */
int NormalizeThemeDrawingState(); /* _NormalizeThemeDrawingState */
int OTAtomicAdd32(); /* _OTAtomicAdd32 */
int OTCompareAndSwap32(); /* _OTCompareAndSwap32 */
int OffsetRect(); /* _OffsetRect */
int OpenAComponent(); /* _OpenAComponent */
int OpenComponent(); /* _OpenComponent */
int OpenMovieFile(); /* _OpenMovieFile */
int OpenRgn(); /* _OpenRgn */
int PBGetCatInfoSync(); /* _PBGetCatInfoSync */
int PBHGetVolParmsSync(); /* _PBHGetVolParmsSync */
int PaintRect(); /* _PaintRect */
int PaintRoundRect(); /* _PaintRoundRect */
int PlotIconRef(); /* _PlotIconRef */
int PostEventToQueue(); /* _PostEventToQueue */
int PrerollMovie(); /* _PrerollMovie */
int PtInRect(); /* _PtInRect */
int PtrAndHand(); /* _PtrAndHand */
int QDBeginCGContext(); /* _QDBeginCGContext */
int QDEndCGContext(); /* _QDEndCGContext */
int QDGlobalToLocalPoint(); /* _QDGlobalToLocalPoint */
int QDLocalToGlobalPoint(); /* _QDLocalToGlobalPoint */
int QDRegisterNamedPixMapCursor(); /* _QDRegisterNamedPixMapCursor */
int QDSetNamedPixMapCursor(); /* _QDSetNamedPixMapCursor */
int QuitAppModalLoopForWindow(); /* _QuitAppModalLoopForWindow */
int QuitApplicationEventLoop(); /* _QuitApplicationEventLoop */
int RGBForeColor(); /* _RGBForeColor */
int ReceiveNextEvent(); /* _ReceiveNextEvent */
int ReleaseEvent(); /* _ReleaseEvent */
int ReleaseIconRef(); /* _ReleaseIconRef */
int RemoveEventHandler(); /* _RemoveEventHandler */
int RemoveEventLoopTimer(); /* _RemoveEventLoopTimer */
int RunAppModalLoopForWindow(); /* _RunAppModalLoopForWindow */
int RunApplicationEventLoop(); /* _RunApplicationEventLoop */
int RunStandardAlert(); /* _RunStandardAlert */
int SendEventToEventTarget(); /* _SendEventToEventTarget */
int SetClip(); /* _SetClip */
int SetControlData(); /* _SetControlData */
int SetControlFontStyle(); /* _SetControlFontStyle */
int SetControlMaximum(); /* _SetControlMaximum */
int SetControlReference(); /* _SetControlReference */
int SetCursor(); /* _SetCursor */
int SetEventParameter(); /* _SetEventParameter */
int SetFrontProcess(); /* _SetFrontProcess */
int SetItemCmd(); /* _SetItemCmd */
int SetKeyboardFocus(); /* _SetKeyboardFocus */
int SetMovieRate(); /* _SetMovieRate */
int SetMovieTimeValue(); /* _SetMovieTimeValue */
int SetPort(); /* _SetPort */
int SetPortWindowPort(); /* _SetPortWindowPort */
int SetSystemUIMode(); /* _SetSystemUIMode */
int SetThemeCursor(); /* _SetThemeCursor */
int SetTrackVolume(); /* _SetTrackVolume */
int SetWRefCon(); /* _SetWRefCon */
int SetWindowContentColor(); /* _SetWindowContentColor */
int SetWindowResizeLimits(); /* _SetWindowResizeLimits */
int SetWindowTitleWithCFString(); /* _SetWindowTitleWithCFString */
int ShowControl(); /* _ShowControl */
int ShowCursor(); /* _ShowCursor */
int ShowMenuBar(); /* _ShowMenuBar */
int ShowWindow(); /* _ShowWindow */
int SizeWindow(); /* _SizeWindow */
int StartMovie(); /* _StartMovie */
int StopMovie(); /* _StopMovie */
int StringToNum(); /* _StringToNum */
int TXNSetData(); /* _TXNSetData */
int TXNSetSelection(); /* _TXNSetSelection */
int TXNSetTypeAttributes(); /* _TXNSetTypeAttributes */
int TXNShowSelection(); /* _TXNShowSelection */
int TickCount(); /* _TickCount */
int UpTime(); /* _UpTime */
int UpdateSystemActivity(); /* _UpdateSystemActivity */
int WaitNextEvent(); /* _WaitNextEvent */
int DefaultRuneLocale(); /* __DefaultRuneLocale */
int Unwind_Resume(); /* __Unwind_Resume */
int ZN9__gnu_cxx18__exchange_and_addEPVii(); /* __ZN9__gnu_cxx18__exchange_and_addEPVii */
int ZNKSs4findEPKcmm(); /* __ZNKSs4findEPKcmm */
int ZNKSs7compareEPKc(); /* __ZNKSs7compareEPKc */
int ZNSs12_M_leak_hardEv(); /* __ZNSs12_M_leak_hardEv */
int ZNSs4_Rep10_M_destroyERKSaIcE(); /* __ZNSs4_Rep10_M_destroyERKSaIcE */
int ZNSs4_Rep11_S_terminalE(); /* __ZNSs4_Rep11_S_terminalE */
int ZNSs4_Rep20_S_empty_rep_storageE(); /* __ZNSs4_Rep20_S_empty_rep_storageE */
int ZNSs6appendEPKcm(); /* __ZNSs6appendEPKcm */
int ZNSs6appendERKSs(); /* __ZNSs6appendERKSs */
int ZNSs6assignEPKcm(); /* __ZNSs6assignEPKcm */
int ZNSs6assignERKSs(); /* __ZNSs6assignERKSs */
int ZNSs7replaceEmmPKcm(); /* __ZNSs7replaceEmmPKcm */
int ZNSs7reserveEm(); /* __ZNSs7reserveEm */
int ZNSs9_M_mutateEmmm(); /* __ZNSs9_M_mutateEmmm */
int ZNSsC1EPKcRKSaIcE(); /* __ZNSsC1EPKcRKSaIcE */
int ZNSsC1ERKSs(); /* __ZNSsC1ERKSs */
int ZNSsC1ERKSsmm(); /* __ZNSsC1ERKSsmm */
int ZNSsD1Ev(); /* __ZNSsD1Ev */
int ZNSt15_List_node_base4hookEPS_(); /* __ZNSt15_List_node_base4hookEPS_ */
int ZNSt15_List_node_base6unhookEv(); /* __ZNSt15_List_node_base6unhookEv */
int ZSt17__throw_bad_allocv(); /* __ZSt17__throw_bad_allocv */
int ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base(); /* __ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base */
int ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base(); /* __ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base */
int ZSt20__throw_length_errorPKc(); /* __ZSt20__throw_length_errorPKc */
int ZSt20__throw_out_of_rangePKc(); /* __ZSt20__throw_out_of_rangePKc */
int ZSt28_Rb_tree_rebalance_for_erasePSt18_Rb_tree_node_baseRS_(); /* __ZSt28_Rb_tree_rebalance_for_erasePSt18_Rb_tree_node_baseRS_ */
int ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_(); /* __ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_ */
int ZTISt9exception(); /* __ZTISt9exception */
int ZTIl(); /* __ZTIl */
int ZTVN10__cxxabiv117__class_type_infoE(); /* __ZTVN10__cxxabiv117__class_type_infoE */
int ZTVN10__cxxabiv120__si_class_type_infoE(); /* __ZTVN10__cxxabiv120__si_class_type_infoE */
int ZTVN10__cxxabiv121__vmi_class_type_infoE(); /* __ZTVN10__cxxabiv121__vmi_class_type_infoE */
int ZdaPv(); /* __ZdaPv */
int ZdlPv(); /* __ZdlPv */
int Znam(); /* __Znam */
int Znwm(); /* __Znwm */
int CFConstantStringClassReference(); /* ___CFConstantStringClassReference */
int dynamic_cast(); /* ___dynamic_cast */
/* error() — provided by system headers */
/* int isnanf(); */ /* ___isnanf — provided by system headers */
int keymgr_dwarf2_register_sections(); /* ___keymgr_dwarf2_register_sections */
int maskrune(); /* ___maskrune */
int sF(); /* ___sF */
int tolower(); /* ___tolower */
int toupper(); /* ___toupper */
int udivdi3(); /* ___udivdi3 */
int cthread_init_routine(); /* __cthread_init_routine */
/* access() — provided by system headers */
/* acos() — provided by system headers */
/* acosf() — provided by system headers */
/* asctime() — provided by system headers */
/* asin() — provided by system headers */
/* asinf() — provided by system headers */
/* atan2() — provided by system headers */
/* atanf() — provided by system headers */
/* atexit() — provided by system headers */
/* atof() — provided by system headers */
/* atoi() — provided by system headers */
/* bind() — provided by system headers */
/* calloc() — provided by system headers */
/* ceilf() — provided by system headers */
/* chdir() — provided by system headers */
/* close() — provided by system headers */
/* int closedir(); */ /* _closedir — provided by system headers */
/* connect() — provided by system headers */
/* cos() — provided by system headers */
/* cosf() — provided by system headers */
/* ctime() — provided by system headers */
int errno(); /* _errno */
/* exit() — provided by system headers */
/* exp() — provided by system headers */
/* expf() — provided by system headers */
/* fclose() — provided by system headers */
/* fflush() — provided by system headers */
/* fileno() — provided by system headers */
/* floor() — provided by system headers */
/* floorf() — provided by system headers */
/* fopen() — provided by system headers */
/* fprintf() — provided by system headers */
/* fread() — provided by system headers */
/* free() — provided by system headers */
/* fseek() — provided by system headers */
/* ftell() — provided by system headers */
/* fwrite() — provided by system headers */
/* getcwd() — provided by system headers */
/* getenv() — provided by system headers */
/* gethostbyname() — provided by system headers */
/* getrlimit() — provided by system headers */
/* inet_addr() — provided by system headers */
/* ioctl() — provided by system headers */
/* isatty() — provided by system headers */
/* int isprint(); */ /* _isprint — provided by system headers */
/* int isspace(); */ /* _isspace — provided by system headers */
/* localtime() — provided by system headers */
/* log() — provided by system headers */
/* log10f() — provided by system headers */
/* logf() — provided by system headers */
/* longjmp() — provided by system headers */
/* int lround(); */ /* _lround — provided by system headers */
int mach_init_routine(); /* _mach_init_routine */
/* malloc() — provided by system headers */
/* memcpy() — provided by system headers */
/* memmove() — provided by system headers */
/* memset() — provided by system headers */
/* mkdir() — provided by system headers */
/* int opendir(); */ /* _opendir — provided by system headers */
/* pow() — provided by system headers */
/* printf() — provided by system headers */
/* pthread_create() — provided by system headers */
/* pthread_getschedparam() — provided by system headers */
int pthread_main_np(); /* _pthread_main_np */
/* pthread_mutex_destroy() — provided by system headers */
/* pthread_mutex_init() — provided by system headers */
/* pthread_mutex_lock() — provided by system headers */
/* pthread_mutex_unlock() — provided by system headers */
/* pthread_mutexattr_destroy() — provided by system headers */
/* pthread_mutexattr_init() — provided by system headers */
/* pthread_mutexattr_settype() — provided by system headers */
/* pthread_setschedparam() — provided by system headers */
/* putenv() — provided by system headers */
/* puts() — provided by system headers */
/* qsort() — provided by system headers */
/* rand() — provided by system headers */
/* int readdir(); */ /* _readdir — provided by system headers */
/* realloc() — provided by system headers */
/* recv() — provided by system headers */
/* recvfrom() — provided by system headers */
/* remove() — provided by system headers */
/* rename() — provided by system headers */
/* rewind() — provided by system headers */
/* sched_get_priority_max() — provided by system headers */
/* sched_get_priority_min() — provided by system headers */
/* select() — provided by system headers */
/* send() — provided by system headers */
/* sendto() — provided by system headers */
/* setjmp() — provided by system headers */
/* setrlimit() — provided by system headers */
/* setsockopt() — provided by system headers */
/* sin() — provided by system headers */
/* sinf() — provided by system headers */
/* snprintf() — provided by system headers */
/* socket() — provided by system headers */
/* sprintf() — provided by system headers */
/* srand() — provided by system headers */
/* sscanf() — provided by system headers */
/* stat() — provided by system headers */
/* strcasecmp() — provided by system headers */
/* strcat() — provided by system headers */
/* strchr() — provided by system headers */
/* strcmp() — provided by system headers */
/* strcpy() — provided by system headers */
/* strdup() — provided by system headers */
/* strerror() — provided by system headers */
/* strncasecmp() — provided by system headers */
/* strncat() — provided by system headers */
/* strncmp() — provided by system headers */
/* strncpy() — provided by system headers */
/* strrchr() — provided by system headers */
/* strstr() — provided by system headers */
/* strtok() — provided by system headers */
int sysctl(); /* _sysctl */
/* tan() — provided by system headers */
/* tanf() — provided by system headers */
/* time() — provided by system headers */
/* usleep() — provided by system headers */
/* vsnprintf() — provided by system headers */
/* vsprintf() — provided by system headers */

#endif /* IMPORTS_LIBC_H */
