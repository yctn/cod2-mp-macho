/* ASM dump from: MacDisplay.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacDisplay.cp */

#include "common_types.h"
#include "imports.h"
#include <dlfcn.h>

void *__Znam(unsigned long size);

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/Tools/MacMemory.h"
 */

extern const char str_00215810[]; /* "mac.display.rect" */
extern const char str_00215824[]; /* "mac.display.index" */
extern const char str_00215838[]; /* "mac.display.first" */

typedef struct {
    const char *value;
    UInt32 reserved[4];
} MacDisplayPreferenceKeyStorage;

__attribute__((used)) static MacDisplayPreferenceKeyStorage kFirstTimeKey = {
    str_00215838,
    {0, 0, 0, 0},
}; /* 0x30804c */
__attribute__((used)) static const char *kDisplayIndexKey = str_00215824; /* 0x308048 */
__attribute__((used)) static const char *kDisplayRectKey = str_00215810; /* 0x308044 */
static Boolean sInitialized; /* 0x3348f0 */
static CGDirectDisplayID sDisplayID; /* 0x3348c8 */
size_t sDisplayIndex; /* 0x3348e8 */
static CGRect sDisplayRect; /* 0x3348f4 */
static SInt32 sDisplayDepth; /* 0x3348e4 */
static SInt32 sDisplayRefreshRate; /* 0x3348e0 */
Boolean sInWindowMode; /* 0x3348d8 */
static ContextRef sScreenContext; /* 0x3348dc */
__attribute__((used)) static UInt32 sEnableSwap = 1; /* 0x308040 */
static UInt32 sSwapCount; /* 0x334798 */
static WindowRef sMainWindow; /* 0x3347a4 */
static CGGammaValue *sSystemGammaRed; /* 0x3348d4 */
static CGGammaValue *sSystemGammaGreen; /* 0x3348d0 */
static CGGammaValue *sSystemGammaBlue; /* 0x3348cc */
CDisplayList sDisplayList; /* 0x33478c */
static CGDirectDisplayID sMainDisplayID; /* 0x334904 */
static Str255 sCaptureName; /* 0x3347c0 */
static SInt16 sCaptureRefNum; /* 0x3348c4 */
static Movie sCaptureMovie; /* 0x3347a8 */
static Track sCaptureTrack; /* 0x3348c0 */
static Media sCaptureMedia; /* 0x33479c */
static CGDisplayFadeReservationToken sFadeToken; /* 0x3348ec */
static struct CRectList sRectList; /* 0x334780 */
static MacRect sMainRect; /* 0x334908 */

/* Carbon types for clean C replacements */
typedef struct { short top; short left; short bottom; short right; } Rect;
typedef struct { short v; short h; } RGBColor;

/* C++ operator new[] / delete[] / delete */
void *__Znam(unsigned long size);
void __ZdaPv(void *ptr);
void __ZdlPv(void *ptr);

/* External function declarations for clean C replacements */
int MacTools_CenterRect(void *ioRect, const void *inBounds);
int MacTools_GetDictionaryValue(int dict, int key);
int MacResources_GetProductFamily(void);

/*
 * Display info accessor helper.
 * sDisplayList is a std::vector<CDisplayInfo> (12-byte vector header in BSS).
 * Each CDisplayInfo entry is 100 (0x64) bytes.
 * First 4 bytes of sDisplayList = pointer to data array.
 */
static inline char *MacDisplay_CurrentDisplayInfo(void)
{
    return *(char **)&sDisplayList + sDisplayIndex * 100;
}

Boolean MacDisplay_IsFullscreen(void);
Boolean MacDisplay_InWindowMode(void);
WindowRef MacDisplay_GetMainWindow(void);
CGrafPtr MacDisplay_GetMainPort(void);
GDHandle MacDisplay_GetDeviceHandle(void);
Boolean MacDisplay_IsWindowMode(void);
Boolean MacDisplay_PointInWindow(struct Point inPoint);
short unsigned int MacDisplay_CenterRectInDisplay(MacRect *ioRect);
static short unsigned int MacDisplay_FadeIn_orig(float inInterval);
static short unsigned int MacDisplay_FadeOut_orig(float inInterval);
short unsigned int MacDisplay_GetCurrentDimensions(int *outWidth, int *outHeight);
int MacDisplay_GetCurrentDepth(void);
short unsigned int MacDisplay_SwapContext(ContextRef inContextRef);
short unsigned int MacDisplay_StopCapture(void);
static short unsigned int CenterWindowOnDisplay(void);
OSStatus MacDisplay_SetupDisplay(int inWidth, int inHeight);
static Boolean BuilderCallback(WindowRef theWindow, UInt32 theCommandID);
short unsigned int MacDisplay_GetNthMode(int inIndex, int *outWidth, int *outHeight, int *outDepth, int *outRefreshRate);
int MacDisplay_GetCardType(void);
const char * MacDisplay_GetGLVendor(void);
const char * MacDisplay_GetGLRenderer(void);
const char * MacDisplay_GetGLExtensions(void);
Boolean MacDisplay_IsGLExtensionSupported(const char *inExtension);
short unsigned int MacDisplay_GetVideoMemoryInfo(long int *outVideoMemory, long int *outTextureMemory);
long int MacDisplay_GetMaxTextureUnits(void);
long int MacDisplay_GetMaxTextureImageUnits(void);
short unsigned int MacDisplay_GetAntiAliasingMultiSampleInfo(int *outMaxSampleBuffers, int *outMaxSamples, Boolean *outDoesSuperSampling, Boolean *outDoesMultiSampling, Boolean *outDoesAlphaSampling);
UInt32 MacDisplay_GetPCPixelShaderVersion(void);
Boolean MacDisplay_GetSupportsSeparateBlendFunc(void);
Boolean MacDisplay_GetSupportsAnisotropicFiltering(void);
float MacDisplay_GetMaxSupportedAnisotropy(void);
short unsigned int MacDisplay_SetGammaRamp(const _D3DGAMMARAMP *inRamp);
short unsigned int MacDisplay_LocalToGlobal(Point *ioPoint);
short unsigned int MacDisplay_GlobalToLocal(Point *ioPoint);
int MacDisplay_GetNumModes(void);
short unsigned int UserPaneDrawProc(ControlRef theControl);
static ControlPartCode UserPaneTrackingProc(ControlRef theControl, Point theStartPt);
void ZN16OpaqueContextRefD1Ev(char *this_ptr); /* OpaqueContextRef_~OpaqueContextRef */
short unsigned int MacDisplay_ReleaseContext(int *ioContextRef);
short unsigned int MacDisplay_ReleaseDisplay(void);
static ContextRef MacDisplay_CreateScreenContext_orig(int inDepthSize, int inUseStencil, int inMultiSampleType, int inMultiSampleQuality, int inPresentationInterval, Boolean *outHasAuxBuffer);
short unsigned int MacDisplay_GetCurrentMode(int *outWidth, int *outHeight, int *outDepth, int *outRefreshRate);
short unsigned int MacDisplay_SetMode(int inWidth, int inHeight, int inDepth, int inRefreshRate);
void ZN12CDisplayInfoaSERKS_(void); /* CDisplayInfo_operator= */
short unsigned int CDisplayInfo_CDisplayInfo(const CDisplayInfo * _this, CGDirectDisplayID inDisplayID);
OSStatus MacDisplay_Initialize(void);
static short unsigned int __static_initialization_and_destruction_0(void);
static void GLOBAL__D__ZN10MacDisplay10InitializeEv(void); /* global destructors keyed to MacDisplay_Initialize */
static void GLOBAL__I__ZN10MacDisplay10InitializeEv(void); /* global constructors keyed to MacDisplay_Initialize */
void ZSt11__push_heapIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEiS2_EvT_T0_S9_T1_(void); /* void std___push_heap<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > >, int, CResInfo> */
void ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEiS2_EvT_T0_S9_T1_(void); /* void std___adjust_heap<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > >, int, CResInfo> */
void ZSt25__unguarded_linear_insertIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEES2_EvT_T0_(void); /* void std___unguarded_linear_insert<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > >, CResInfo> */
void ZSt9make_heapIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEEvT_S8_(void); /* void std_make_heap<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > > > */
void ZSt21__unguarded_partitionIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEES2_ET_S8_S8_T0_(void); /* __gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > > std___unguarded_partition<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > >, CResInfo> */
void ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEEvT_S8_(void); /* void std___insertion_sort<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > > > */
void ZSt22__final_insertion_sortIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEEvT_S8_(void); /* void std___final_insertion_sort<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > > > */
void ZSt12partial_sortIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEEvT_S8_S8_(void); /* void std_partial_sort<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > > > */
void ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEiEvT_S8_T0_(void); /* void std___introsort_loop<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > >, int> */
void ZNSt6vectorI7MacRectSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_(void); /* std_vector<MacRect, std_allocator<MacRect> >__M_insert_aux */
void ZNSt6vectorI8CResInfoSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_(void); /* std_vector<CResInfo, std_allocator<CResInfo> >__M_insert_aux */
void ZNSt6vectorI8CResInfoSaIS0_EEaSERKS2_(void); /* std_vector<CResInfo, std_allocator<CResInfo> >_operator= */
void ZNSt6vectorI12CDisplayInfoSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_(void); /* std_vector<CDisplayInfo, std_allocator<CDisplayInfo> >__M_insert_aux */

/* line 440 */
Boolean MacDisplay_IsFullscreen(void)
{
    if (sInWindowMode)
        return 0;
    return sScreenContext != 0;
}

/* line 455 */
Boolean MacDisplay_InWindowMode(void)
{
    return sInWindowMode;
}

/* line 463 */
WindowRef MacDisplay_GetMainWindow(void)
{
    return sMainWindow;
}

/* line 471 */
CGrafPtr MacDisplay_GetMainPort(void)
{
    if (sScreenContext)
        return *(CGrafPtr *)((char *)sScreenContext + 4);

    return (CGrafPtr)GetWindowPort(sMainWindow);
}

/* line 495 */
GDHandle MacDisplay_GetDeviceHandle(void)
{ return 0; }

/* line 529 */
Boolean MacDisplay_IsWindowMode(void)
{
    if (!sInitialized)
        return 1;
    return sInWindowMode;
}

/* line 609 */
Boolean MacDisplay_PointInWindow(struct Point inPoint)
{
    Rect bounds;
    GetWindowPortBounds(sMainWindow, &bounds);
    return PtInRect(inPoint, &bounds) != 0;
}

/* line 623 */
short unsigned int MacDisplay_CenterRectInDisplay(MacRect *ioRect)
{
    GDHandle device = MacDisplay_GetDeviceHandle();
    Rect gdRect;
    char *devData = *(char **)device;
    *(int *)&gdRect = *(int *)(devData + 0x22);
    *((int *)&gdRect + 1) = *(int *)(devData + 0x26);

    MacTools_CenterRect(ioRect, &gdRect);
}

/* line 638 */
static short unsigned int MacDisplay_FadeIn_orig(float inInterval)
{
    if (sInWindowMode)
        return 0;

    if (!sFadeToken)
        return 0;

    CGDisplayFade(sFadeToken, inInterval, 0.0f, 1.0f, 0.0f, 0.0f, 0);
    CGReleaseDisplayFadeReservation(sFadeToken);
    sFadeToken = 0;
}

/* line 658 */
static short unsigned int MacDisplay_FadeOut_orig(float inInterval)
{ return 0; }

/* line 685 */
short unsigned int MacDisplay_GetCurrentDimensions(int *outWidth, int *outHeight)
{
    if (sMainWindow)
    {
        Rect bounds;
        GetWindowPortBounds(sMainWindow, &bounds);

        int width = (short)bounds.right;
        if (width <= 639)
            width = 640;
        *outWidth = width;

        int height = (short)bounds.bottom;
        *outHeight = height;
        if (height <= 479)
            *outHeight = 480;
        return 0;
    }

    *outWidth = CGDisplayPixelsWide(sDisplayID);
    *outHeight = CGDisplayPixelsHigh(sDisplayID);
}

/* line 714 */
int MacDisplay_GetCurrentDepth(void)
{
    if (sDisplayDepth)
        return sDisplayDepth;

    sDisplayDepth = CGDisplayBitsPerPixel(sDisplayID);
    return sDisplayDepth;
}

/* line 1417 */
static short unsigned int MacDisplay_SwapContext_impl(ContextRef inContextRef)
{
    if (!sEnableSwap)
        return 0;

    aglSwapBuffers(*(void **)inContextRef);
    sSwapCount++;
}

short unsigned int MacDisplay_SwapContext(ContextRef inContextRef)
{
    extern void *sdl_gl_window;
    (void)inContextRef;

    if (sdl_gl_window) {
        extern void SDL_GL_SwapWindow(void *);

        SDL_GL_SwapWindow(sdl_gl_window);
    }

    return 1;
}

/* line 1747 */
short unsigned int MacDisplay_StopCapture(void)
{
    if (!sCaptureMovie)
        return 0;

    OSErr error = EndMediaEdits(sCaptureMedia);
    if (error == 0)
    {
        TimeValue duration = GetMediaDuration(sCaptureMedia);
        error = InsertMediaIntoTrack(sCaptureTrack, 0, 0, duration, 0x10000);
        if (error == 0)
        {
            short resID = -1;
            AddMovieResource(sCaptureMovie, (short)sCaptureRefNum, &resID, sCaptureName);
        }
    }

    CloseMovieFile((short)sCaptureRefNum);
    sCaptureMovie = 0;
}

/* line 2622 */
static short unsigned int CenterWindowOnDisplay(void)
{ return 0; }

/* line 349 */
OSStatus MacDisplay_SetupDisplay(int inWidth, int inHeight)
{ return 0; }

/* line 2857 */
static Boolean BuilderCallback(WindowRef theWindow, UInt32 theCommandID)
{
    return 0;
}

/* line 842 */
short unsigned int MacDisplay_GetNthMode(int inIndex, int *outWidth, int *outHeight, int *outDepth, int *outRefreshRate)
{
    char *di = MacDisplay_CurrentDisplayInfo();
    /* offset 0x14 = pointer to modes array; each mode entry is 16 bytes */
    char *mode = (char *)(*(int *)(di + 0x14)) + inIndex * 16;
    *outWidth = *(int *)(mode + 0);
    *outHeight = *(int *)(mode + 4);
    *outDepth = *(int *)(mode + 8);
    *outRefreshRate = *(int *)(mode + 12);
}

/* line 885 */
int MacDisplay_GetCardType(void)
{
    char *di = MacDisplay_CurrentDisplayInfo();
    return *(int *)(di + 0x2c);
}

/* line 894 */
const char * MacDisplay_GetGLVendor(void)
{
    char *di = MacDisplay_CurrentDisplayInfo();
    return *(const char **)(di + 0x30);
}

/* line 903 */
const char * MacDisplay_GetGLRenderer(void)
{
    char *di = MacDisplay_CurrentDisplayInfo();
    return *(const char **)(di + 0x34);
}

/* line 912 */
const char * MacDisplay_GetGLExtensions(void)
{
    char *di = MacDisplay_CurrentDisplayInfo();
    return *(const char **)(di + 0x38);
}

/* line 922 */
Boolean MacDisplay_IsGLExtensionSupported(const char *inExtension)
{
    char *di = MacDisplay_CurrentDisplayInfo();
    return gluCheckExtension(inExtension, *(const char **)(di + 0x38));
}

/* line 933 */
short unsigned int MacDisplay_GetVideoMemoryInfo(long int *outVideoMemory, long int *outTextureMemory)
{
    char *di = MacDisplay_CurrentDisplayInfo();
    *outVideoMemory = *(long *)(di + 0x3c);
    *outTextureMemory = *(long *)(di + 0x40);
}

/* line 944 */
long int MacDisplay_GetMaxTextureUnits(void)
{
    char *di = MacDisplay_CurrentDisplayInfo();
    return *(long *)(di + 0x44);
}

/* line 953 */
long int MacDisplay_GetMaxTextureImageUnits(void)
{
    char *di = MacDisplay_CurrentDisplayInfo();
    return *(long *)(di + 0x48);
}

/* line 967 */
short unsigned int MacDisplay_GetAntiAliasingMultiSampleInfo(int *outMaxSampleBuffers, int *outMaxSamples, Boolean *outDoesSuperSampling, Boolean *outDoesMultiSampling, Boolean *outDoesAlphaSampling)
{
    char *di = MacDisplay_CurrentDisplayInfo();
    *outMaxSampleBuffers = *(int *)(di + 0x58);
    *outMaxSamples = *(int *)(di + 0x5c);
    *outDoesSuperSampling = *(unsigned char *)(di + 0x60);
    *outDoesMultiSampling = *(unsigned char *)(di + 0x61);
    *outDoesAlphaSampling = *(unsigned char *)(di + 0x62);
}

/* line 981 */
UInt32 MacDisplay_GetPCPixelShaderVersion(void)
{
    char *di = MacDisplay_CurrentDisplayInfo();
    return *(UInt32 *)(di + 0x4c);
}

/* line 990 */
Boolean MacDisplay_GetSupportsSeparateBlendFunc(void)
{
    char *di = MacDisplay_CurrentDisplayInfo();
    return *(unsigned char *)(di + 0x51);
}

/* line 999 */
Boolean MacDisplay_GetSupportsAnisotropicFiltering(void)
{
    char *di = MacDisplay_CurrentDisplayInfo();
    return *(unsigned char *)(di + 0x52);
}

/* line 1008 */
float MacDisplay_GetMaxSupportedAnisotropy(void)
{
    char *di = MacDisplay_CurrentDisplayInfo();
    return *(float *)(di + 0x54);
}

/* line 1519 */
short unsigned int MacDisplay_SetGammaRamp(const _D3DGAMMARAMP *inRamp)
{
    if (sInWindowMode)
        return 0;

    if (!sSystemGammaRed)
    {
        sSystemGammaRed = (CGGammaValue *)__Znam(0x400);
        sSystemGammaGreen = (CGGammaValue *)__Znam(0x400);
        sSystemGammaBlue = (CGGammaValue *)__Znam(0x400);
        int count;
        CGGetDisplayTransferByTable(sDisplayID, 0x100,
            sSystemGammaRed, sSystemGammaGreen, sSystemGammaBlue, &count);
    }

    float *redTable = (float *)__Znam(0x400);
    float *greenTable = (float *)__Znam(0x400);
    float *blueTable = (float *)__Znam(0x400);

    /*
     * _D3DGAMMARAMP: unsigned short red[256] at +0x000,
     *                unsigned short green[256] at +0x200,
     *                unsigned short blue[256] at +0x400.
     * Convert high byte of each 16-bit value to 0.0-1.0 float.
     */
    const unsigned short *red = (const unsigned short *)inRamp;
    const unsigned short *green = (const unsigned short *)((char *)inRamp + 0x200);
    const unsigned short *blue = (const unsigned short *)((char *)inRamp + 0x400);

    for (int i = 0; i < 256; i++)
    {
        redTable[i] = (float)(red[i] >> 8) * 0.00390625f;
        greenTable[i] = (float)(green[i] >> 8) * 0.00390625f;
        blueTable[i] = (float)(blue[i] >> 8) * 0.00390625f;
    }

    CGSetDisplayTransferByTable(sDisplayID, 0x100, redTable, greenTable, blueTable);

    if (blueTable) __ZdaPv(blueTable);
    if (greenTable) __ZdaPv(greenTable);
    if (redTable) __ZdaPv(redTable);
}

/* line 577 */
short unsigned int MacDisplay_LocalToGlobal(Point *ioPoint)
{
    int port;

    if (sInitialized && !sInWindowMode && sScreenContext)
        port = *(int *)((char *)sScreenContext + 4);
    else
        port = GetWindowPort(sMainWindow);

    QDLocalToGlobalPoint(port, ioPoint);
}

/* line 593 */
short unsigned int MacDisplay_GlobalToLocal(Point *ioPoint)
{
    int port;

    if (sInitialized && !sInWindowMode && sScreenContext)
        port = *(int *)((char *)sScreenContext + 4);
    else
        port = GetWindowPort(sMainWindow);

    QDGlobalToLocalPoint(port, ioPoint);
}

/* line 828 */
int MacDisplay_GetNumModes(void)
{
    char *di = MacDisplay_CurrentDisplayInfo();
    /* (end_ptr - start_ptr) / 16 = number of mode entries */
    return (*(int *)(di + 0x18) - *(int *)(di + 0x14)) >> 4;
}

/* line 2671 */
short unsigned int UserPaneDrawProc(ControlRef theControl)
{ return 0; }

/* line 2831 */
static ControlPartCode UserPaneTrackingProc(ControlRef theControl, Point theStartPt)
{ return 0; }

/* line 1897 */
void ZN16OpaqueContextRefD1Ev(char *this_ptr) /* OpaqueContextRef_~OpaqueContextRef */
{
    int ctx = *(int *)this_ptr;
    if (!ctx)
        return;

    /* If swap count is odd and context has swap flag, do a final swap */
    if ((sSwapCount & 1) && *(char *)(this_ptr + 0xc) && sEnableSwap)
    {
        aglSwapBuffers(ctx);
        sSwapCount++;
    }

    aglSetCurrentContext(0);

    if (*(int *)(this_ptr + 4))
        aglSetDrawable(ctx, 0);

    aglDestroyContext(ctx);
    *(int *)this_ptr = 0;
}

/* line 1385 */
short unsigned int MacDisplay_ReleaseContext(int *ioContextRef)
{
    int ctx = *ioContextRef;

    /* Clear sScreenContext if it matches the one being released */
    if (ctx == sScreenContext)
        sScreenContext = 0;

    if (ctx)
    {
        ZN16OpaqueContextRefD1Ev((char *)ctx);
        __ZdlPv((void *)ctx);
    }
    *ioContextRef = 0;
}

/* line 405 */
short unsigned int MacDisplay_ReleaseDisplay(void)
{
    if (!sInitialized)
        return 0;

    MacDisplay_StopCapture();

    /* Restore system gamma if in fullscreen mode */
    if (!sInWindowMode && sSystemGammaRed)
    {
        CGSetDisplayTransferByTable(sDisplayID, 0x100,
            sSystemGammaRed, sSystemGammaGreen, sSystemGammaBlue);

        if (sSystemGammaRed)
            __ZdaPv((void *)sSystemGammaRed);
        if (sSystemGammaGreen)
            __ZdaPv((void *)sSystemGammaGreen);
        if (sSystemGammaBlue)
            __ZdaPv((void *)sSystemGammaBlue);

        sSystemGammaRed = 0;
        sSystemGammaGreen = 0;
        sSystemGammaBlue = 0;
    }

    int wasInWindowMode = sInWindowMode;
    sInWindowMode = 0;

    if (sMainWindow)
    {
        DisposeWindow(sMainWindow);
        sMainWindow = 0;
    }

    if (!wasInWindowMode)
    {
        ShowMenuBar();
        SetSystemUIMode(0, 0);
    }
}

/* line 1101 */
static ContextRef MacDisplay_CreateScreenContext_orig(int inDepthSize, int inUseStencil, int inMultiSampleType, int inMultiSampleQuality, int inPresentationInterval, Boolean *outHasAuxBuffer)
{ return 0; }

/* line 758 */
short unsigned int MacDisplay_GetCurrentMode(int *outWidth, int *outHeight, int *outDepth, int *outRefreshRate)
{
    if (sMainWindow)
    {
        Rect bounds;
        GetWindowPortBounds(sMainWindow, &bounds);

        int width = (short)bounds.right;
        if (width <= 639)
            width = 640;
        *outWidth = width;

        int height = (short)bounds.bottom;
        *outHeight = height;
        if (height <= 479)
            *outHeight = 480;
    }
    else
    {
        *outWidth = CGDisplayPixelsWide(sDisplayID);
        *outHeight = CGDisplayPixelsHigh(sDisplayID);
    }

    if (!sDisplayDepth)
        sDisplayDepth = CGDisplayBitsPerPixel(sDisplayID);
    *outDepth = sDisplayDepth;

    if (!sDisplayRefreshRate)
    {
        int modeDict = CGDisplayCurrentMode(sDisplayID);
        if (modeDict)
        {
            int rate = MacTools_GetDictionaryValue(modeDict, 0x32e624); /* kRefreshRateKey */
            if (rate == -1)
                rate = sDisplayRefreshRate;
            sDisplayRefreshRate = rate;
        }
    }
    *outRefreshRate = sDisplayRefreshRate;
}

/* line 774 */
short unsigned int MacDisplay_SetMode(int inWidth, int inHeight, int inDepth, int inRefreshRate)
{ return 0; }

/* line 2361 */
void ZN12CDisplayInfoaSERKS_(void) /* CDisplayInfo_operator= */
{ }

/* line 1979 */
short unsigned int CDisplayInfo_CDisplayInfo(const CDisplayInfo * _this, CGDirectDisplayID inDisplayID)
{ return 0; }

/* overload skip: CDisplayInfo_CDisplayInfo (0x6f4a) */

/* overload skip: CDisplayInfo_CDisplayInfo (0x79ba) */

/* overload skip: CDisplayInfo_CDisplayInfo (0x7c2a) */

/* line 214 */
OSStatus MacDisplay_Initialize(void)
{ return 0; }

/* line 2923 */
static short unsigned int __static_initialization_and_destruction_0(void)
{ return 0; }

/* line 2925 */
static void GLOBAL__D__ZN10MacDisplay10InitializeEv(void) /* global destructors keyed to MacDisplay_Initialize */
{ }

/* line 2924 */
static void GLOBAL__I__ZN10MacDisplay10InitializeEv(void) /* global constructors keyed to MacDisplay_Initialize */
{ }

/* line 118 */
void ZSt11__push_heapIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEiS2_EvT_T0_S9_T1_(void) /* void std___push_heap<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > >, int, CResInfo> */
{ }

/* line 210 */
void ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEiS2_EvT_T0_S9_T1_(void) /* void std___adjust_heap<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > >, int, CResInfo> */
{ }

/* line 2083 */
void ZSt25__unguarded_linear_insertIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEES2_EvT_T0_(void) /* void std___unguarded_linear_insert<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > >, CResInfo> */
{ }

/* line 344 */
void ZSt9make_heapIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEEvT_S8_(void) /* void std_make_heap<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > > > */
{ }

/* line 2027 */
void ZSt21__unguarded_partitionIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEES2_ET_S8_S8_T0_(void) /* __gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > > std___unguarded_partition<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > >, CResInfo> */
{ }

/* line 2125 */
void ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEEvT_S8_(void) /* void std___insertion_sort<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > > > */
{ }

/* line 2212 */
void ZSt22__final_insertion_sortIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEEvT_S8_(void) /* void std___final_insertion_sort<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > > > */
{ }

/* line 2277 */
void ZSt12partial_sortIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEEvT_S8_S8_(void) /* void std_partial_sort<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > > > */
{ }

/* line 2478 */
void ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEiEvT_S8_T0_(void) /* void std___introsort_loop<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > >, int> */
{ }

/* line 249 */
void ZNSt6vectorI7MacRectSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_(void) /* std_vector<MacRect, std_allocator<MacRect> >__M_insert_aux */
{ }

/* line 249 */
void ZNSt6vectorI8CResInfoSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_(void) /* std_vector<CResInfo, std_allocator<CResInfo> >__M_insert_aux */
{ }

/* line 133 */
void ZNSt6vectorI8CResInfoSaIS0_EEaSERKS2_(void) /* std_vector<CResInfo, std_allocator<CResInfo> >_operator= */
{ }

/* line 249 */
void ZNSt6vectorI12CDisplayInfoSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_(void) /* std_vector<CDisplayInfo, std_allocator<CDisplayInfo> >__M_insert_aux */
{ }
