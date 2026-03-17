/* ASM dump from: MacDisplay.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacDisplay.cp */

#include "common_types.h"
#include "imports.h"
#include <dlfcn.h>

void *__Znam(unsigned long size);

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/Tools/MacMemory.h"
 */

extern const char *kFirstTimeKey; /* 0x30804c */
extern const char *kDisplayIndexKey; /* 0x308048 */
extern const char *kDisplayRectKey; /* 0x308044 */
static Boolean sInitialized; /* 0x3348f0 */
static CGDirectDisplayID sDisplayID; /* 0x3348c8 */
size_t sDisplayIndex; /* 0x3348e8 */
static CGRect sDisplayRect; /* 0x3348f4 */
static SInt32 sDisplayDepth; /* 0x3348e4 */
static SInt32 sDisplayRefreshRate; /* 0x3348e0 */
Boolean sInWindowMode; /* 0x3348d8 */
static ContextRef sScreenContext; /* 0x3348dc */
extern Boolean sEnableSwap; /* 0x308040 */
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
#ifndef __EMSCRIPTEN__
__attribute__((naked))
GDHandle MacDisplay_GetDeviceHandle(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 495 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        /* { scope 1: gdRect */
        "leal -0x48(%ebp), %edx\n" /* line 497 */
        "movl sDisplayID, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CGDisplayBounds\n"
        "subl $4, %esp\n"
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, -0x38(%ebp)\n" /* cgRect */
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "cvttss2si -0x38(%ebp), %edx\n" /* line 500 | cgRect */
        "movw %dx, -0x1e(%ebp)\n"
        "cvttss2si -0x34(%ebp), %ecx\n" /* line 501 */
        "movw %cx, -0x20(%ebp)\n" /* qdRect */
        "cvttss2si -0x30(%ebp), %eax\n" /* line 502 */
        "addl %edx, %eax\n"
        "movw %ax, -0x1a(%ebp)\n"
        "cvttss2si -0x2c(%ebp), %eax\n" /* line 503 */
        "addl %ecx, %eax\n"
        "movw %ax, -0x1c(%ebp)\n"
        "movl $1, (%esp)\n" /* line 505 */
        "calll DMGetFirstScreenDevice\n"
        "movl %eax, %ebx\n" /* device */
        "testl %eax, %eax\n" /* line 506 */
        "je .Lf43b6_00004462\n"
        "leal -0x28(%ebp), %edi\n" /* gdRect */
        "leal -0x20(%ebp), %esi\n" /* qdRect */
        /* { scope 2 */
        ".Lf43b6_0000442e:\n"
        "movl (%ebx), %eax\n" /* line 508 | device */
        "movl 0x26(%eax), %edx\n"
        "movl 0x22(%eax), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* gdRect */
        "movl %edx, -0x24(%ebp)\n"
        "movl %edi, 4(%esp)\n" /* line 509 */
        "movl %esi, (%esp)\n"
        "calll EqualRect\n"
        "testb %al, %al\n"
        "jne .Lf43b6_00004469\n"
        "movl $1, 4(%esp)\n" /* line 514 */
        "movl %ebx, (%esp)\n" /* device */
        "calll DMGetNextScreenDevice\n"
        "movl %eax, %ebx\n" /* device */
        /* } scope */
        "testl %eax, %eax\n" /* line 506 */
        "jne .Lf43b6_0000442e\n"
        ".Lf43b6_00004462:\n"
        "calll GetMainDevice\n" /* line 520 */
        "movl %eax, %ebx\n" /* device */
        /* } scope */
        ".Lf43b6_00004469:\n"
        "movl %ebx, %eax\n" /* line 524 | device */
        "leal -0xc(%ebp), %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
GDHandle MacDisplay_GetDeviceHandle(void)
{ return 0; }
#endif

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
#ifndef __EMSCRIPTEN__
__attribute__((naked))
static short unsigned int MacDisplay_FadeOut_orig(float inInterval)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 658 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "cmpb $0, sInWindowMode\n" /* line 660 */
        "jne .Lf455c_0000458c\n"
        /* { scope 1 */
        "movl sFadeToken, %eax\n" /* line 663 */
        "testl %eax, %eax\n"
        "jne .Lf455c_000045ca\n"
        "movl $sFadeToken, 4(%esp)\n" /* line 671 */
        "movl $0x41700000, (%esp)\n"
        "calll CGAcquireDisplayFadeReservation\n"
        "testl %eax, %eax\n" /* line 673 */
        "je .Lf455c_0000458e\n"
        /* } scope */
        ".Lf455c_0000458c:\n"
        "leave\n" /* line 678 */
        "retl\n"
        /* { scope 1 */
        ".Lf455c_0000458e:\n"
        "movl $1, 0x1c(%esp)\n" /* line 675 */
        "xorl %eax, %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movss 8(%ebp), %xmm0\n" /* inInterval */
        "movss %xmm0, 4(%esp)\n"
        "movl sFadeToken, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CGDisplayFade\n"
        /* } scope */
        "leave\n" /* line 678 */
        "retl\n"
        /* { scope 1 */
        ".Lf455c_000045ca:\n"
        "movl %eax, (%esp)\n" /* line 666 */
        "calll CGReleaseDisplayFadeReservation\n"
        "movl $0, sFadeToken\n" /* line 667 */
        "movl $sFadeToken, 4(%esp)\n" /* line 671 */
        "movl $0x41700000, (%esp)\n"
        "calll CGAcquireDisplayFadeReservation\n"
        "testl %eax, %eax\n" /* line 673 */
        "jne .Lf455c_0000458c\n"
        "jmp .Lf455c_0000458e\n"
    );
}
#else
static short unsigned int MacDisplay_FadeOut_orig(float inInterval)
{ return 0; }
#endif

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
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
short unsigned int CenterWindowOnDisplay(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2622 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        /* { scope 1 */
        "calll MacDisplay_GetDeviceHandle\n" /* line 2626 */
        "movl %eax, %ebx\n" /* deviceHdl */
        "cmpb $0, sInWindowMode\n" /* line 2631 */
        "jne .Lf476c_00004816\n"
        ".Lf476c_00004788:\n"
        "movl (%ebx), %eax\n" /* line 2641 | deviceHdl */
        "movl 0x26(%eax), %edx\n"
        "movl 0x22(%eax), %eax\n"
        "movl %eax, -0x10(%ebp)\n" /* maxBounds */
        "movl %edx, -0xc(%ebp)\n"
        ".Lf476c_00004796:\n"
        "leal -0x18(%ebp), %eax\n" /* line 2645 | bounds */
        "movl %eax, 4(%esp)\n"
        "movl sMainWindow, %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetWindowPortBounds\n"
        "movswl -0xe(%ebp), %esi\n" /* line 2647 */
        "movswl -0x10(%ebp), %ebx\n" /* line 2648 | maxBounds, deviceHdl */
        "movl $0, 0xc(%esp)\n" /* line 2656 */
        "movswl -0xc(%ebp), %edx\n"
        "subl %ebx, %edx\n" /* deviceHdl */
        "movswl -0x14(%ebp), %eax\n"
        "movswl -0x18(%ebp), %ecx\n" /* bounds */
        "subl %ecx, %eax\n"
        "subl %eax, %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "addl %eax, %ebx\n" /* deviceHdl */
        "movswl %bx, %ebx\n" /* deviceHdl */
        "movl %ebx, 8(%esp)\n" /* deviceHdl */
        "movswl -0xa(%ebp), %edx\n"
        "subl %esi, %edx\n"
        "movswl -0x12(%ebp), %eax\n"
        "movswl -0x16(%ebp), %ecx\n"
        "subl %ecx, %eax\n"
        "subl %eax, %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "addl %eax, %esi\n"
        "movswl %si, %esi\n"
        "movl %esi, 4(%esp)\n"
        "movl sMainWindow, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MoveWindow\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 2657 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf476c_00004816:\n"
        "leal -0x10(%ebp), %eax\n" /* line 2633 | maxBounds, error */
        "movl %eax, 4(%esp)\n" /* error */
        "movl %ebx, (%esp)\n" /* deviceHdl */
        "calll GetAvailableWindowPositioningBounds\n"
        "testl %eax, %eax\n" /* line 2634 */
        "jne .Lf476c_00004788\n"
        "jmp .Lf476c_00004796\n"
    );
}
#else
static short unsigned int CenterWindowOnDisplay(void)
{ return 0; }
#endif

/* line 349 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
OSStatus MacDisplay_SetupDisplay(int inWidth, int inHeight)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 349 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x44, %esp\n"
        /* { scope 1 */
        "cmpb $0, sInitialized\n" /* line 351 */
        "je .Lf4832_0000493a\n"
        "cmpb $1, sInWindowMode\n" /* line 359 */
        "sbbl %ebx, %ebx\n" /* attributes */
        "andl $0x22fff7, %ebx\n" /* attributes */
        "addl $0x2000009, %ebx\n" /* attributes */
        "leal -0x38(%ebp), %edx\n" /* line 371 */
        "movl sDisplayID, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CGDisplayBounds\n"
        "subl $4, %esp\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* displayRect */
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "cvttss2si -0x28(%ebp), %eax\n" /* line 373 | displayRect */
        "movw %ax, -0x14(%ebp)\n"
        "cvttss2si -0x24(%ebp), %edx\n" /* line 374 */
        "movw %dx, -0x16(%ebp)\n" /* bounds */
        "addl 8(%ebp), %eax\n" /* line 375 | inWidth */
        "movw %ax, -0x10(%ebp)\n"
        "addl 0xc(%ebp), %edx\n" /* line 376 | inHeight */
        "movw %dx, -0x12(%ebp)\n"
        "cmpb $1, sInWindowMode\n" /* line 378 */
        "sbbl %edx, %edx\n"
        "andl $7, %edx\n"
        "addl $6, %edx\n"
        "movl $sMainWindow, 0xc(%esp)\n"
        "leal -0x16(%ebp), %eax\n" /* bounds */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* error */
        "movl %edx, (%esp)\n"
        "calll CreateNewWindow\n"
        "movl %eax, %ebx\n" /* error */
        "testl %eax, %eax\n" /* line 379 */
        "je .Lf4832_000048e1\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 400 | error */
        "movl -4(%ebp), %ebx\n" /* error */
        "leave\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4832_000048e1:\n"
        "movl sMainWindow, %eax\n" /* line 383 */
        "movl %eax, (%esp)\n"
        "calll SetPortWindowPort\n"
        "movw $0, -0xa(%ebp)\n" /* line 386 */
        "movw $0, -0xc(%ebp)\n"
        "movw $0, -0xe(%ebp)\n" /* color */
        "leal -0xe(%ebp), %eax\n" /* line 387 | color */
        "movl %eax, 4(%esp)\n"
        "movl sMainWindow, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SetWindowContentColor\n"
        "calll MacResources_GetProductFamily\n" /* line 389 */
        "testl %eax, %eax\n" /* line 390 */
        "je .Lf4832_0000492e\n"
        "movl %eax, 4(%esp)\n" /* line 392 */
        "movl sMainWindow, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SetWindowTitleWithCFString\n"
        ".Lf4832_0000492e:\n"
        "calll CenterWindowOnDisplay\n" /* line 396 */
        /* } scope */
        "movl %ebx, %eax\n" /* line 400 | error */
        "movl -4(%ebp), %ebx\n" /* error */
        "leave\n"
        "retl\n"
        /* { scope 1 */
        ".Lf4832_0000493a:\n"
        "movl $0xffffffce, %ebx\n" /* line 351 */
        /* } scope */
        "movl %ebx, %eax\n" /* line 400 | error */
        "movl -4(%ebp), %ebx\n" /* error */
        "leave\n"
        "retl\n"
    );
}
#else
OSStatus MacDisplay_SetupDisplay(int inWidth, int inHeight)
{ return 0; }
#endif

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
#ifndef __EMSCRIPTEN__
__attribute__((naked))
short unsigned int UserPaneDrawProc(ControlRef theControl)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2671 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x17c, %esp\n"
        /* { scope 1: displayR, bounds, itemW, itemH, ... */
        "movl 0x334784, %eax\n" /* line 361 */
        "subl sRectList, %eax\n" /* line 2675 */
        "sarl $3, %eax\n"
        "testl %eax, %eax\n"
        "je .Lf4df6_000050b3\n"
        ".Lf4df6_00004e18:\n"
        "calll NormalizeThemeDrawingState\n" /* line 2745 */
        "movw $0x5252, -0x26(%ebp)\n" /* line 2749 | bgColor */
        "movw $0x8a8a, -0x24(%ebp)\n"
        "movw $0xcccc, -0x22(%ebp)\n"
        "movl sRectList, %edx\n" /* line 334 */
        "movl %edx, %esi\n" /* line 2750 */
        "cmpl %edx, 0x334784\n"
        "je .Lf4df6_00004f71\n"
        "movl %edx, %eax\n"
        "leal -0x46(%ebp), %edi\n" /* displayR */
        "jmp .Lf4df6_00004e7f\n"
        /* { scope 2: menuR, portRect, r */
        ".Lf4df6_00004e4a:\n"
        "movl $0x21, (%esp)\n" /* line 2780 */
        "calll ForeColor\n"
        "movl $8, 8(%esp)\n" /* line 2781 */
        "movl $8, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll FrameRoundRect\n"
        /* } scope */
        "addl $8, %esi\n" /* line 623 */
        "cmpl %esi, 0x334784\n" /* line 2750 */
        "je .Lf4df6_00004f6b\n"
        "movl %esi, %eax\n"
        /* { scope 2: menuR, portRect, r */
        ".Lf4df6_00004e7f:\n"
        "movl 4(%eax), %edx\n" /* line 2752 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x46(%ebp)\n" /* displayR */
        "movl %edx, -0x42(%ebp)\n"
        "leal -0x26(%ebp), %eax\n" /* line 2755 | bgColor */
        "movl %eax, (%esp)\n"
        "calll RGBForeColor\n"
        "movl $8, 8(%esp)\n" /* line 2756 */
        "movl $8, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll PaintRoundRect\n"
        "movl %edi, 4(%esp)\n" /* line 2759 */
        "movl $sMainRect, (%esp)\n"
        "calll EqualRect\n"
        "testb %al, %al\n"
        "je .Lf4df6_00004e4a\n"
        /* { scope 3 */
        "calll NewRgn\n" /* line 2761 */
        "movl %eax, %ebx\n" /* rgn */
        "calll OpenRgn\n" /* line 2762 */
        "movl $8, 8(%esp)\n" /* line 2763 */
        "movl $8, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll FrameRoundRect\n"
        "movl %ebx, (%esp)\n" /* line 2764 | rgn */
        "calll CloseRgn\n"
        "movl %ebx, (%esp)\n" /* line 2765 | rgn */
        "calll SetClip\n"
        "movl %ebx, (%esp)\n" /* line 2766 | rgn */
        "calll DisposeRgn\n"
        "movl -0x46(%ebp), %eax\n" /* line 2768 | displayR */
        "movl -0x42(%ebp), %edx\n"
        "movl %eax, -0x4e(%ebp)\n" /* menuR */
        "movl %edx, -0x4a(%ebp)\n"
        "movzwl -0x4e(%ebp), %eax\n" /* line 2769 | menuR */
        "leal 8(%eax), %edx\n"
        "movw %dx, -0x4a(%ebp)\n"
        "addl $1, %eax\n" /* line 2770 */
        "movw %ax, -0x4e(%ebp)\n" /* menuR */
        "leal -0x4e(%ebp), %edx\n" /* line 2771 | menuR */
        "movl %edx, (%esp)\n"
        "calll ClipRect\n"
        "movl $1, 8(%esp)\n" /* line 2772 */
        "movl $0, 4(%esp)\n"
        "leal -0x4e(%ebp), %eax\n" /* menuR */
        "movl %eax, (%esp)\n"
        "calll DrawThemeMenuBarBackground\n"
        "movl 8(%ebp), %edx\n" /* line 2775 | theControl */
        "movl %edx, (%esp)\n"
        "calll GetControlOwner\n"
        "leal -0x36(%ebp), %edx\n" /* portRect */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll GetWindowPortBounds\n"
        "leal -0x36(%ebp), %eax\n" /* line 2776 | portRect */
        "movl %eax, (%esp)\n"
        "calll ClipRect\n"
        "jmp .Lf4df6_00004e4a\n"
        ".Lf4df6_00004f6b:\n"
        "movl sRectList, %edx\n"
        /* } scope */
        /* } scope */
        ".Lf4df6_00004f71:\n"
        "movl 0x334790, %eax\n" /* line 361 */
        "movl sDisplayIndex, %ecx\n" /* line 2787 */
        "subl sDisplayList, %eax\n"
        "sarl $2, %eax\n"
        "imull $0xc28f5c29, %eax, %eax\n"
        "cmpl %ecx, %eax\n"
        "jbe .Lf4df6_000050a3\n"
        "movl (%edx, %ecx, 8), %eax\n" /* line 2789 */
        "movl 4(%edx, %ecx, 8), %edx\n"
        "movl %eax, -0x56(%ebp)\n" /* focusR */
        "movl %edx, -0x52(%ebp)\n"
        ".Lf4df6_00004fa0:\n"
        "movl $4, 8(%esp)\n" /* line 2795 */
        "movl $4, 4(%esp)\n"
        "leal -0x56(%ebp), %ebx\n" /* focusR, rgn */
        "movl %ebx, (%esp)\n" /* rgn */
        "calll InsetRect\n"
        "movl $1, 4(%esp)\n" /* line 2796 */
        "movl %ebx, (%esp)\n" /* rgn */
        "calll DrawThemeFocusRect\n"
        "leal -0x108(%ebp), %ebx\n" /* line 2801 | appRef, rgn */
        "movl %ebx, (%esp)\n" /* rgn */
        "calll MacFolders_GetApplicationRef\n"
        "leal -0x1a(%ebp), %eax\n" /* line 2805 | label */
        "movl %eax, 0x1c(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* iconRef */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* rgn */
        "calll GetIconRefFromFileInfo\n"
        "xorl %ebx, %ebx\n" /* line 2808 | rgn */
        "testw %ax, %ax\n"
        "cmovel -0x20(%ebp), %ebx\n" /* iconRef, rgn */
        "movl %ebx, -0x20(%ebp)\n" /* rgn, iconRef */
        "movswl -0x50(%ebp), %eax\n" /* line 2816 */
        "movswl -0x54(%ebp), %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %ecx\n"
        "shrl $0x1f, %ecx\n"
        "addl %eax, %ecx\n"
        "sarl $1, %ecx\n"
        "leal -0x18(%ecx), %eax\n"
        "movw %ax, -0x2c(%ebp)\n"
        "movswl -0x52(%ebp), %edx\n" /* line 2817 */
        "movswl -0x56(%ebp), %eax\n" /* focusR */
        "addl %eax, %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "leal -0x18(%eax), %edx\n"
        "movw %dx, -0x2e(%ebp)\n" /* iconR */
        "addl $0x18, %ecx\n" /* line 2818 */
        "movw %cx, -0x28(%ebp)\n"
        "addl $0x18, %eax\n" /* line 2819 */
        "movw %ax, -0x2a(%ebp)\n"
        "testl %ebx, %ebx\n" /* line 2821 | rgn */
        "je .Lf4df6_0000509b\n"
        "movl %ebx, 0x10(%esp)\n" /* line 2823 | rgn */
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0x2e(%ebp), %eax\n" /* iconR */
        "movl %eax, (%esp)\n"
        "calll PlotIconRef\n"
        "movl -0x20(%ebp), %eax\n" /* line 2824 | iconRef */
        "movl %eax, (%esp)\n"
        "calll ReleaseIconRef\n"
        /* } scope */
        ".Lf4df6_0000509b:\n"
        "leal -0xc(%ebp), %esp\n" /* line 2826 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: displayR, bounds, itemW, itemH, ... */
        ".Lf4df6_000050a3:\n"
        "movl (%edx), %eax\n" /* line 2793 */
        "movl 4(%edx), %edx\n"
        "movl %eax, -0x56(%ebp)\n" /* focusR */
        "movl %edx, -0x52(%ebp)\n"
        "jmp .Lf4df6_00004fa0\n"
        /* { scope 2: menuR, portRect, r */
        ".Lf4df6_000050b3:\n"
        "leal -0x36(%ebp), %eax\n" /* line 2678 | portRect */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* theControl */
        "movl %eax, (%esp)\n"
        "calll GetControlBounds\n"
        "movswl -0x30(%ebp), %eax\n" /* line 2680 */
        "movswl -0x34(%ebp), %edx\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x13c(%ebp)\n" /* itemW */
        "movswl -0x32(%ebp), %eax\n" /* line 2681 */
        "movswl -0x36(%ebp), %edx\n" /* portRect */
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm2\n"
        "movss %xmm2, -0x138(%ebp)\n" /* itemH */
        "movl CGRectZero, %eax\n" /* line 2685 */
        "movss 0xc(%eax), %xmm0\n"
        "movss %xmm0, -0x130(%ebp)\n"
        "movss 8(%eax), %xmm2\n"
        "movss %xmm2, -0x12c(%ebp)\n"
        "movss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x128(%ebp)\n"
        "movss (%eax), %xmm2\n"
        "movss %xmm2, -0x124(%ebp)\n"
        "movl sDisplayList, %eax\n" /* line 334 */
        "cmpl 0x334790, %eax\n" /* line 2686 */
        "je .Lf4df6_00005309\n"
        "movl %eax, -0x11c(%ebp)\n"
        "jmp .Lf4df6_0000517d\n"
        ".Lf4df6_00005142:\n"
        "movl %ebx, -0x130(%ebp)\n" /* line 2689 */
        "movl %esi, -0x12c(%ebp)\n"
        "movl %edi, -0x128(%ebp)\n"
        "movss -0x120(%ebp), %xmm2\n"
        "movss %xmm2, -0x124(%ebp)\n"
        "addl $0x64, -0x11c(%ebp)\n" /* line 623 */
        "movl -0x11c(%ebp), %eax\n" /* line 2686 */
        "cmpl %eax, 0x334790\n"
        "je .Lf4df6_00005309\n"
        ".Lf4df6_0000517d:\n"
        "movl 0x10(%eax), %ebx\n" /* line 2688 */
        "movl 0xc(%eax), %esi\n"
        "movl 8(%eax), %edi\n"
        "movss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x120(%ebp)\n"
        "movl %ebx, -0x7c(%ebp)\n" /* line 2689 */
        "movl %esi, -0x80(%ebp)\n"
        "movl %edi, -0x84(%ebp)\n"
        "movss %xmm0, -0x88(%ebp)\n"
        "movl -0x88(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "movl -0x84(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x80(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x7c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "calll CGRectIsEmpty\n"
        "testl %eax, %eax\n"
        "jne .Lf4df6_00005142\n"
        "movss -0x130(%ebp), %xmm0\n" /* line 2695 */
        "movss %xmm0, -0x5c(%ebp)\n"
        "movss -0x12c(%ebp), %xmm2\n"
        "movss %xmm2, -0x60(%ebp)\n"
        "movss -0x128(%ebp), %xmm0\n"
        "movss %xmm0, -0x64(%ebp)\n"
        "movss -0x124(%ebp), %xmm2\n"
        "movss %xmm2, -0x68(%ebp)\n"
        "movl %ebx, -0x8c(%ebp)\n"
        "movl %esi, -0x90(%ebp)\n"
        "movl %edi, -0x94(%ebp)\n"
        "movss -0x120(%ebp), %xmm0\n"
        "movss %xmm0, -0x98(%ebp)\n"
        "movl -0x68(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl -0x64(%ebp), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl -0x60(%ebp), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl -0x5c(%ebp), %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl -0x98(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x94(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x90(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x8c(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x118(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CGRectUnion\n"
        "subl $4, %esp\n"
        "movl -0x118(%ebp), %eax\n"
        "movl %eax, -0xb8(%ebp)\n" /* srcR */
        "movl -0x114(%ebp), %eax\n"
        "movl %eax, -0xb4(%ebp)\n"
        "movl -0x110(%ebp), %eax\n"
        "movl %eax, -0xb0(%ebp)\n"
        "movl -0x10c(%ebp), %eax\n"
        "movl %eax, -0xac(%ebp)\n"
        "movss -0xac(%ebp), %xmm0\n"
        "movss %xmm0, -0x130(%ebp)\n"
        "movss -0xb0(%ebp), %xmm2\n"
        "movss %xmm2, -0x12c(%ebp)\n"
        "movss -0xb4(%ebp), %xmm0\n"
        "movss %xmm0, -0x128(%ebp)\n"
        "movss -0xb8(%ebp), %xmm2\n" /* srcR */
        "movss %xmm2, -0x124(%ebp)\n" /* line 2689 */
        "addl $0x64, -0x11c(%ebp)\n" /* line 623 */
        "movl -0x11c(%ebp), %eax\n" /* line 2686 */
        "cmpl %eax, 0x334790\n"
        "jne .Lf4df6_0000517d\n"
        ".Lf4df6_00005309:\n"
        "movss -0x130(%ebp), %xmm0\n" /* line 2698 */
        "movss %xmm0, -0x9c(%ebp)\n"
        "movss -0x12c(%ebp), %xmm2\n"
        "movss %xmm2, -0xa0(%ebp)\n"
        "movss -0x128(%ebp), %xmm0\n"
        "movss %xmm0, -0xa4(%ebp)\n"
        "movss -0x124(%ebp), %xmm2\n"
        "movss %xmm2, -0xa8(%ebp)\n"
        "movl -0xa8(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "movl -0xa4(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0xa0(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x9c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "calll CGRectGetWidth\n"
        "fstps -0x134(%ebp)\n" /* srcW */
        "movss -0x130(%ebp), %xmm0\n" /* line 2699 */
        "movss %xmm0, -0x6c(%ebp)\n"
        "movss -0x12c(%ebp), %xmm2\n"
        "movss %xmm2, -0x70(%ebp)\n"
        "movss -0x128(%ebp), %xmm0\n"
        "movss %xmm0, -0x74(%ebp)\n"
        "movss -0x124(%ebp), %xmm2\n"
        "movss %xmm2, -0x78(%ebp)\n"
        "movl -0x78(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "movl -0x74(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x70(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x6c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "calll CGRectGetHeight\n"
        "fstps -0x14c(%ebp)\n"
        "movss -0x14c(%ebp), %xmm0\n"
        "divss -0x134(%ebp), %xmm0\n" /* line 2703 | srcW, dstH */
        "mulss -0x13c(%ebp), %xmm0\n" /* itemW, dstH */
        "ucomiss -0x138(%ebp), %xmm0\n" /* line 2704 | itemH */
        "ja .Lf4df6_00005557\n"
        "movss -0x13c(%ebp), %xmm1\n" /* itemW */
        "movss -0x138(%ebp), %xmm2\n" /* itemH */
        ".Lf4df6_0000540a:\n"
        "movw $0, -0x3c(%ebp)\n" /* line 2712 */
        "movw $0, -0x3e(%ebp)\n" /* line 2713 | qdDest */
        "cvttss2si %xmm1, %eax\n" /* line 2714 */
        "movw %ax, -0x38(%ebp)\n"
        "cvttss2si %xmm0, %eax\n" /* line 2715 */
        "movw %ax, -0x3a(%ebp)\n"
        "subss %xmm0, %xmm2\n" /* line 2716 */
        "cvttss2si %xmm2, %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "addw -0x36(%ebp), %ax\n" /* portRect */
        "cwtl\n"
        "movl %eax, 8(%esp)\n"
        "movss -0x13c(%ebp), %xmm0\n" /* itemW */
        "subss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "addl -0x34(%ebp), %eax\n"
        "cwtl\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x3e(%ebp), %eax\n" /* qdDest */
        "movl %eax, (%esp)\n"
        "calll OffsetRect\n"
        "cvttss2si -0x124(%ebp), %edx\n" /* line 2719 */
        "movw %dx, -0x4c(%ebp)\n"
        "cvttss2si -0x128(%ebp), %ecx\n" /* line 2720 */
        "movw %cx, -0x4e(%ebp)\n" /* menuR */
        "cvttss2si -0x12c(%ebp), %eax\n" /* line 2721 */
        "addl %edx, %eax\n"
        "movw %ax, -0x48(%ebp)\n"
        "cvttss2si -0x130(%ebp), %eax\n" /* line 2722 */
        "addl %ecx, %eax\n"
        "movw %ax, -0x4a(%ebp)\n"
        "movl sDisplayList, %eax\n" /* line 334 */
        "cmpl 0x334790, %eax\n" /* line 2725 */
        "je .Lf4df6_00004e18\n"
        "movl %eax, %ebx\n"
        "leal -0x4e(%ebp), %esi\n" /* menuR */
        "leal -0x46(%ebp), %edi\n" /* displayR */
        "jmp .Lf4df6_000054cc\n"
        ".Lf4df6_000054bb:\n"
        "addl $0x64, %ebx\n" /* line 623 */
        "cmpl 0x334790, %ebx\n" /* line 2725 */
        "je .Lf4df6_00004e18\n"
        "movl %ebx, %eax\n"
        /* { scope 3 */
        ".Lf4df6_000054cc:\n"
        "cvttss2si 4(%eax), %edx\n" /* line 2728 */
        "movw %dx, -0x44(%ebp)\n"
        "cvttss2si 8(%ebx), %ecx\n" /* line 2729 */
        "movw %cx, -0x46(%ebp)\n" /* displayR */
        "cvttss2si 0xc(%ebx), %eax\n" /* line 2730 */
        "addl %edx, %eax\n"
        "movw %ax, -0x40(%ebp)\n"
        "cvttss2si 0x10(%ebx), %eax\n" /* line 2731 */
        "addl %ecx, %eax\n"
        "movw %ax, -0x42(%ebp)\n"
        "leal -0x3e(%ebp), %edx\n" /* line 2733 | qdDest */
        "movl %edx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll MapRect\n"
        "movl 0x334784, %ecx\n" /* line 604 */
        "cmpl 0x334788, %ecx\n"
        "je .Lf4df6_0000557b\n"
        "testl %ecx, %ecx\n" /* line 104 */
        "je .Lf4df6_0000552a\n"
        "movl -0x46(%ebp), %eax\n" /* displayR */
        "movl -0x42(%ebp), %edx\n"
        "movl %eax, (%ecx)\n"
        "movl %edx, 4(%ecx)\n"
        "movl 0x334784, %ecx\n"
        ".Lf4df6_0000552a:\n"
        "addl $8, %ecx\n" /* line 607 */
        "movl %ecx, 0x334784\n"
        ".Lf4df6_00005533:\n"
        "movl (%ebx), %eax\n" /* line 2737 */
        "cmpl sMainDisplayID, %eax\n"
        "jne .Lf4df6_000054bb\n"
        "movl -0x46(%ebp), %eax\n" /* line 2739 | displayR */
        "movl -0x42(%ebp), %edx\n"
        "movl %eax, sMainRect\n"
        "movl %edx, 0x33490c\n"
        "jmp .Lf4df6_000054bb\n"
        /* } scope */
        ".Lf4df6_00005557:\n"
        "movss -0x13c(%ebp), %xmm1\n" /* line 2706 | itemW */
        "divss %xmm0, %xmm1\n"
        "mulss -0x138(%ebp), %xmm1\n" /* itemH */
        "movss -0x138(%ebp), %xmm0\n" /* itemH */
        "movaps %xmm0, %xmm2\n"
        "jmp .Lf4df6_0000540a\n"
        /* { scope 3 */
        ".Lf4df6_0000557b:\n"
        "movl %edi, 8(%esp)\n" /* line 610 */
        "movl %ecx, 4(%esp)\n"
        "movl $sRectList, (%esp)\n"
        "calll ZNSt6vectorI7MacRectSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_\n"
        "jmp .Lf4df6_00005533\n"
    );
}
#else
short unsigned int UserPaneDrawProc(ControlRef theControl)
{ return 0; }
#endif

/* line 2831 */
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
ControlPartCode UserPaneTrackingProc(ControlRef theControl, Point theStartPt)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2831 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* theStartPt */
        "xorl %ebx, %ebx\n"
        "leal -0x20(%ebp), %esi\n" /* r */
        "jmp .Lf5592_000055c5\n"
        /* { scope 1: r */
        /* { scope 2 */
        ".Lf5592_000055a5:\n"
        "movl (%edx, %ebx, 8), %eax\n" /* line 2835 */
        "movl 4(%edx, %ebx, 8), %edx\n"
        "movl %eax, -0x20(%ebp)\n" /* r */
        "movl %edx, -0x1c(%ebp)\n"
        "movl %esi, 4(%esp)\n" /* line 2836 */
        "movl %edi, (%esp)\n" /* theStartPt */
        "calll PtInRect\n"
        "testb %al, %al\n"
        "jne .Lf5592_000055e3\n"
        /* } scope */
        "addl $1, %ebx\n" /* line 2833 | i */
        ".Lf5592_000055c5:\n"
        "movl sRectList, %edx\n" /* line 343 */
        "movl 0x334784, %eax\n" /* line 361 */
        "subl %edx, %eax\n" /* line 2833 */
        "sarl $3, %eax\n"
        "cmpl %ebx, %eax\n" /* i */
        "ja .Lf5592_000055a5\n"
        /* } scope */
        ".Lf5592_000055d9:\n"
        "xorl %eax, %eax\n" /* line 2852 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: r */
        /* { scope 2 */
        ".Lf5592_000055e3:\n"
        "cmpl sDisplayIndex, %ebx\n" /* line 2838 | i */
        "je .Lf5592_000055d9\n"
        "movl %ebx, sDisplayIndex\n" /* line 2840 | i */
        "movl $0, 4(%esp)\n" /* line 2841 */
        "movl 8(%ebp), %eax\n" /* theControl */
        "movl %eax, (%esp)\n"
        "calll UserPaneDrawProc\n"
        /* } scope */
        /* } scope */
        "xorl %eax, %eax\n" /* line 2852 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
static ControlPartCode UserPaneTrackingProc(ControlRef theControl, Point theStartPt)
{ return 0; }
#endif

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
#ifndef __EMSCRIPTEN__
__attribute__((naked))
static ContextRef MacDisplay_CreateScreenContext_orig(int inDepthSize, int inUseStencil, int inMultiSampleType, int inMultiSampleQuality, int inPresentationInterval, Boolean *outHasAuxBuffer)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1101 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xdc, %esp\n"
        "movl 8(%ebp), %esi\n" /* inDepthSize */
        /* { scope 1: inDeviceHdl, currHeight, currDepth, currRate */
        "testl %esi, %esi\n" /* line 1104 | inDepthSize */
        "movl $0x20, %eax\n"
        "cmovel %eax, %esi\n" /* inDepthSize */
        "cmpb $0, 0xc(%ebp)\n" /* line 1116 | inUseStencil */
        "jne .Lf57ca_00005c74\n"
        "movl $0, -0xc4(%ebp)\n" /* stencilSize */
        ".Lf57ca_000057f7:\n"
        "movl 0x1c(%ebp), %eax\n" /* line 1126 | outHasAuxBuffer */
        "movb $1, (%eax)\n"
        "cmpl $1, 0x10(%ebp)\n" /* line 1130 | inMultiSampleType */
        "jle .Lf57ca_00005817\n"
        "cmpb $0, sInWindowMode\n" /* line 1133 */
        "je .Lf57ca_00005dfa\n"
        ".Lf57ca_00005810:\n"
        "movl $0, 0x10(%ebp)\n" /* inMultiSampleType */
        ".Lf57ca_00005817:\n"
        "movl $0x10, (%esp)\n" /* line 1141 */
        "calll __Znwm\n"
        "movl %eax, %ebx\n" /* contextRef */
        "movl $0, (%eax)\n" /* line 1891 */
        "movl $0, 4(%eax)\n"
        "movl $0, 8(%eax)\n"
        "movb $0, 0xc(%eax)\n"
        "calll MacDisplay_GetDeviceHandle\n" /* line 1145 */
        "movl %eax, -0xc0(%ebp)\n" /* deviceHdl */
        "movl 0x1c(%ebp), %edx\n" /* line 1152 | outHasAuxBuffer, inPixelSize */
        "movzbl (%edx), %eax\n" /* inUseAuxBuffer */
        "movl sDisplayDepth, %edx\n" /* inPixelSize */
        "movl -0xc0(%ebp), %ecx\n" /* deviceHdl */
        "movl %ecx, -0x1c(%ebp)\n" /* inDeviceHdl */
        /* { scope 2: attribs, refreshRate */
        /* { scope 3 */
        "movl $4, -0x9c(%ebp)\n" /* line 1031 | attribs */
        "movl $5, -0x98(%ebp)\n" /* line 1032 */
        "movl $0x48, -0x94(%ebp)\n" /* line 1033 */
        "cmpb $0, sInWindowMode\n" /* line 1035 */
        "je .Lf57ca_00005c4f\n"
        "leal -0x90(%ebp), %ecx\n"
        ".Lf57ca_0000588e:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1043 | inDeviceHdl */
        "testl %edx, %edx\n"
        "je .Lf57ca_0000589e\n"
        "movl $0x49, (%ecx)\n" /* line 1045 */
        "addl $4, %ecx\n"
        ".Lf57ca_0000589e:\n"
        "movl $0xc, (%ecx)\n" /* line 1048 */
        "movl %esi, 4(%ecx)\n" /* line 1049 */
        "leal 8(%ecx), %edx\n"
        "movl -0xc4(%ebp), %edi\n" /* line 1051 | stencilSize */
        "testl %edi, %edi\n"
        "jle .Lf57ca_000058c7\n"
        "movl $0xd, 8(%ecx)\n" /* line 1053 */
        "movl -0xc4(%ebp), %edx\n" /* line 1054 | stencilSize */
        "movl %edx, 0xc(%ecx)\n"
        "leal 0x10(%ecx), %edx\n"
        ".Lf57ca_000058c7:\n"
        "testb %al, %al\n" /* line 1057 */
        "je .Lf57ca_000058e2\n"
        "movl $7, (%edx)\n" /* line 1059 */
        "movl $2, 4(%edx)\n" /* line 1061 */
        "movl $0x39, 8(%edx)\n" /* line 1069 */
        "addl $0xc, %edx\n"
        ".Lf57ca_000058e2:\n"
        "cmpl $1, 0x10(%ebp)\n" /* line 1072 | inMultiSampleType */
        "jle .Lf57ca_00005905\n"
        "movl $0x37, (%edx)\n" /* line 1074 */
        "movl $1, 4(%edx)\n" /* line 1075 */
        "movl $0x38, 8(%edx)\n" /* line 1076 */
        "movl 0x10(%ebp), %ecx\n" /* line 1077 | inMultiSampleType */
        "movl %ecx, 0xc(%edx)\n"
        "addl $0x10, %edx\n"
        ".Lf57ca_00005905:\n"
        "movl $0, (%edx)\n" /* line 1080 */
        "movl -0x1c(%ebp), %eax\n" /* line 1082 | inDeviceHdl */
        "testl %eax, %eax\n"
        "je .Lf57ca_00005ee8\n"
        "leal -0x9c(%ebp), %eax\n" /* line 1084 | attribs */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* inDeviceHdl */
        "movl %eax, (%esp)\n"
        "calll aglChoosePixelFormat\n"
        "movl %eax, %edi\n"
        /* } scope */
        /* } scope */
        ".Lf57ca_00005935:\n"
        "testl %edi, %edi\n" /* line 1155 | format */
        "je .Lf57ca_00005d01\n"
        ".Lf57ca_0000593d:\n"
        "movl $0, 4(%esp)\n" /* line 1205 */
        "movl %edi, (%esp)\n" /* format */
        "calll aglCreateContext\n"
        "movl %eax, (%ebx)\n" /* contextRef */
        "testl %eax, %eax\n" /* line 1206 */
        "je .Lf57ca_000060c4\n"
        "cmpb $0, sInWindowMode\n" /* line 1216 */
        "jne .Lf57ca_00005bad\n"
        /* { scope 2: attribs, refreshRate */
        "movl sMainWindow, %eax\n" /* line 687 */
        "testl %eax, %eax\n"
        "je .Lf57ca_00005f26\n"
        "leal -0x9c(%ebp), %edx\n" /* line 690 | attribs */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll GetWindowPortBounds\n"
        "movswl -0x96(%ebp), %esi\n" /* line 692 */
        "cmpl $0x27f, %esi\n" /* line 693 */
        "movl $0x280, %eax\n"
        "cmovlel %eax, %esi\n"
        "movswl -0x98(%ebp), %ecx\n" /* line 698 */
        "movl %ecx, -0xbc(%ebp)\n" /* currHeight */
        "cmpl $0x1df, %ecx\n" /* line 699 */
        "jle .Lf57ca_00005ce5\n"
        "movl sDisplayDepth, %eax\n" /* line 719 */
        "testl %eax, %eax\n"
        "je .Lf57ca_00005e2e\n"
        ".Lf57ca_000059be:\n"
        "movl sDisplayDepth, %eax\n"
        "movl %eax, -0xb8(%ebp)\n" /* line 724 | currDepth */
        "movl sDisplayRefreshRate, %ecx\n" /* line 735 */
        "testl %ecx, %ecx\n"
        "je .Lf57ca_00005e54\n"
        ".Lf57ca_000059d7:\n"
        "movl sDisplayRefreshRate, %edx\n"
        ".Lf57ca_000059dd:\n"
        "movl %edx, -0xb4(%ebp)\n" /* line 748 | currRate */
        "movl $0, 0x10(%esp)\n" /* line 1226 */
        "movl %edx, 0xc(%esp)\n"
        "movl -0xbc(%ebp), %ecx\n" /* currHeight */
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* currWidth */
        "movl (%ebx), %eax\n" /* contextRef, ok */
        "movl %eax, (%esp)\n" /* ok */
        "calll aglSetFullScreen\n"
        "testb %al, %al\n" /* line 1227 */
        "jne .Lf57ca_00005b73\n"
        /* { scope 3 */
        "movl sDisplayID, %eax\n" /* line 2563 | modeRef */
        "movl %eax, (%esp)\n" /* modeRef */
        "calll CGDisplayCurrentMode\n"
        "testl %eax, %eax\n" /* line 2564 */
        "je .Lf57ca_00005ed9\n"
        "movl $0x32e624, 4(%esp)\n" /* line 2566 */
        "movl %eax, (%esp)\n"
        "calll MacTools_GetDictionaryValue\n"
        "movl %eax, -0xb0(%ebp)\n" /* refreshRate */
        "addl $1, %eax\n" /* line 2567 */
        "je .Lf57ca_00005ed9\n"
        ".Lf57ca_00005a43:\n"
        "movl sDisplayIndex, %eax\n" /* line 495 */
        "leal (%eax, %eax, 4), %eax\n" /* line 654 */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "addl sDisplayList, %eax\n"
        "movl 0x14(%eax), %edx\n" /* line 343 */
        "movl 0x18(%eax), %eax\n" /* line 361 */
        "cmpl %edx, %eax\n" /* line 2577 */
        "je .Lf57ca_00005af7\n"
        /* } scope */
        /* } scope */
        "cmpl $0x63, -0xb0(%ebp)\n" /* line 1315 | refreshRate */
        "jg .Lf57ca_00005ac3\n"
        "movl $0, -0xac(%ebp)\n"
        "jmp .Lf57ca_00005a81\n"
        /* { scope 2: attribs, refreshRate */
        /* { scope 3 */
        ".Lf57ca_00005a7a:\n"
        "addl $0x10, %edx\n" /* line 623 */
        "cmpl %eax, %edx\n" /* line 2577 */
        "je .Lf57ca_00005adc\n"
        ".Lf57ca_00005a81:\n"
        "cmpl %esi, (%edx)\n" /* line 2579 | currWidth */
        "jne .Lf57ca_00005a7a\n"
        "movl -0xbc(%ebp), %ecx\n" /* currHeight */
        "cmpl %ecx, 4(%edx)\n"
        "jne .Lf57ca_00005a7a\n"
        "movl -0xb8(%ebp), %ecx\n" /* currDepth */
        "cmpl 8(%edx), %ecx\n"
        "jne .Lf57ca_00005a7a\n"
        "movl 0xc(%edx), %ecx\n" /* line 2581 */
        "cmpl %ecx, -0xb0(%ebp)\n" /* refreshRate */
        "je .Lf57ca_000060b3\n"
        "cmpl $0x63, %ecx\n" /* line 2589 */
        "jle .Lf57ca_000060d1\n"
        "cmpl %ecx, -0xac(%ebp)\n" /* line 2592 */
        "jle .Lf57ca_00005a7a\n"
        ".Lf57ca_00005abb:\n"
        "movl %ecx, -0xac(%ebp)\n" /* line 2579 */
        "jmp .Lf57ca_00005a7a\n"
        ".Lf57ca_00005ac3:\n"
        "movl $0, -0xac(%ebp)\n" /* line 2577 */
        ".Lf57ca_00005acd:\n"
        "cmpl %esi, (%edx)\n" /* line 2579 | currWidth */
        "je .Lf57ca_00006114\n"
        ".Lf57ca_00005ad5:\n"
        "addl $0x10, %edx\n" /* line 623 */
        "cmpl %eax, %edx\n" /* line 2577 */
        "jne .Lf57ca_00005acd\n"
        ".Lf57ca_00005adc:\n"
        "movl -0xac(%ebp), %eax\n"
        ".Lf57ca_00005ae2:\n"
        "movl -0xac(%ebp), %edx\n" /* line 2611 */
        "testl %edx, %edx\n"
        "cmovel -0xb0(%ebp), %eax\n" /* refreshRate */
        "movl %eax, -0xb0(%ebp)\n" /* refreshRate */
        /* } scope */
        ".Lf57ca_00005af7:\n"
        "movl -0xb4(%ebp), %edx\n" /* line 1230 | currRate */
        "cmpl %edx, -0xb0(%ebp)\n" /* refreshRate */
        "je .Lf57ca_00005b43\n"
        /* { scope 3 */
        "movl $0, 0x10(%esp)\n" /* line 1233 */
        "movl -0xb0(%ebp), %ecx\n" /* refreshRate */
        "movl %ecx, 0xc(%esp)\n"
        "movl -0xbc(%ebp), %eax\n" /* currHeight, ok */
        "movl %eax, 8(%esp)\n" /* ok */
        "movl %esi, 4(%esp)\n" /* currWidth */
        "movl (%ebx), %eax\n" /* contextRef, ok */
        "movl %eax, (%esp)\n" /* ok */
        "calll aglSetFullScreen\n"
        "testb %al, %al\n" /* line 1236 */
        "movl -0xb0(%ebp), %eax\n" /* refreshRate */
        "cmovel sDisplayRefreshRate, %eax\n"
        "movl %eax, sDisplayRefreshRate\n"
        /* } scope */
        ".Lf57ca_00005b43:\n"
        "movl $0, 0x10(%esp)\n" /* line 1242 */
        "movl $0, 0xc(%esp)\n"
        "movl -0xbc(%ebp), %edx\n" /* currHeight */
        "movl %edx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* currWidth */
        "movl (%ebx), %eax\n" /* contextRef */
        "movl %eax, (%esp)\n"
        "calll aglSetFullScreen\n"
        "testb %al, %al\n" /* line 1245 */
        "je .Lf57ca_000060c4\n"
        ".Lf57ca_00005b73:\n"
        "xorl %eax, %eax\n" /* line 1255 */
        "cmpl $0x80000000, 0x18(%ebp)\n" /* inPresentationInterval */
        "setne %al\n"
        "movl %eax, -0x1c(%ebp)\n" /* inDeviceHdl */
        "leal -0x1c(%ebp), %eax\n" /* line 1256 | inDeviceHdl */
        "movl %eax, 8(%esp)\n"
        "movl $0xde, 4(%esp)\n"
        "movl (%ebx), %eax\n" /* contextRef */
        "movl %eax, (%esp)\n"
        "calll aglSetInteger\n"
        "calll HideMenuBar\n" /* line 1258 */
        /* } scope */
        "cmpb $0, sInWindowMode\n" /* line 1263 */
        "je .Lf57ca_00005e8f\n"
        ".Lf57ca_00005bad:\n"
        "movl sMainWindow, %eax\n" /* line 1265 */
        "movl %eax, (%esp)\n"
        "calll GetWindowPort\n"
        "movl %eax, 4(%ebx)\n" /* contextRef */
        ".Lf57ca_00005bbd:\n"
        "movb $1, 0xc(%ebx)\n" /* line 1272 | contextRef */
        "leal 8(%ebx), %eax\n" /* line 1276 | contextRef */
        "movl %eax, 8(%esp)\n"
        "movl $0x46, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* format */
        "calll aglDescribePixelFormat\n"
        "movl %edi, (%esp)\n" /* line 1280 | format */
        "calll aglDestroyPixelFormat\n"
        "cmpb $0, sInWindowMode\n" /* line 1284 */
        "jne .Lf57ca_00005c8c\n"
        ".Lf57ca_00005bed:\n"
        "movl %ebx, sScreenContext\n" /* line 1295 | contextRef */
        "movl (%ebx), %eax\n" /* line 1406 | contextRef */
        "movl %eax, (%esp)\n"
        "calll aglSetCurrentContext\n"
        "cmpl $1, 0x10(%ebp)\n" /* line 1302 | inMultiSampleType */
        "jle .Lf57ca_00005f0d\n"
        "movl $0x809d, (%esp)\n" /* line 1304 */
        "calll glEnable\n"
        "movl sDisplayIndex, %eax\n" /* line 495 */
        "leal (%eax, %eax, 4), %eax\n" /* line 654 */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "addl sDisplayList, %eax\n"
        "movl 0x38(%eax), %eax\n" /* line 147 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002158b8, (%esp)\n" /* "GL_NV_multisample_filter_hint" */
        "calll gluCheckExtension\n"
        "testb %al, %al\n" /* line 1305 */
        "jne .Lf57ca_00005cc4\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 1320 | contextRef */
        "addl $0xdc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: inDeviceHdl, currHeight, currDepth, currRate */
        /* { scope 2: attribs, refreshRate */
        /* { scope 3 */
        ".Lf57ca_00005c4f:\n"
        "movl $0x36, -0x90(%ebp)\n" /* line 1037 */
        "movl $0x32, -0x8c(%ebp)\n" /* line 1039 */
        "movl %edx, -0x88(%ebp)\n" /* line 1040 */
        "leal -0x84(%ebp), %ecx\n"
        "jmp .Lf57ca_0000588e\n"
        /* } scope */
        /* } scope */
        ".Lf57ca_00005c74:\n"
        "cmpl $0x20, %esi\n" /* line 1118 | inDepthSize */
        "je .Lf57ca_00005ec6\n"
        "movl $8, -0xc4(%ebp)\n" /* stencilSize */
        "jmp .Lf57ca_000057f7\n"
        ".Lf57ca_00005c8c:\n"
        "movl 4(%ebx), %eax\n" /* line 1286 | contextRef */
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n" /* contextRef */
        "movl %eax, (%esp)\n"
        "calll aglSetDrawable\n"
        "testb %al, %al\n"
        "jne .Lf57ca_00005bed\n"
        ".Lf57ca_00005ca5:\n"
        "movl %ebx, (%esp)\n" /* line 1210 | contextRef */
        "calll ZN16OpaqueContextRefD1Ev\n"
        "movl %ebx, (%esp)\n" /* contextRef */
        "calll __ZdlPv\n"
        "xorl %ebx, %ebx\n" /* contextRef */
        /* } scope */
        "movl %ebx, %eax\n" /* line 1320 | contextRef */
        "addl $0xdc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: inDeviceHdl, currHeight, currDepth, currRate */
        ".Lf57ca_00005cc4:\n"
        "movl $0x1101, 4(%esp)\n" /* line 1310 */
        "movl $0x8534, (%esp)\n"
        "calll glHint\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 1320 | contextRef */
        "addl $0xdc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: inDeviceHdl, currHeight, currDepth, currRate */
        /* { scope 2: attribs, refreshRate */
        ".Lf57ca_00005ce5:\n"
        "movl $0x1e0, -0xbc(%ebp)\n" /* line 699 | currHeight */
        "movl sDisplayDepth, %eax\n" /* line 719 */
        "testl %eax, %eax\n"
        "jne .Lf57ca_000059be\n"
        "jmp .Lf57ca_00005e2e\n"
        /* } scope */
        ".Lf57ca_00005d01:\n"
        "cmpl $0x20, %esi\n" /* line 1155 | inDepthSize */
        "je .Lf57ca_00005f7f\n"
        ".Lf57ca_00005d0a:\n"
        "cmpl $1, 0x10(%ebp)\n" /* line 1163 | inMultiSampleType */
        "jle .Lf57ca_00005ca5\n"
        "movl $str_002158a0, (%esp)\n" /* line 1165 */
        "calll game_dprintf\n"
        "movl 0x1c(%ebp), %ecx\n" /* line 1167 | outHasAuxBuffer */
        "movzbl (%ecx), %eax\n" /* inUseAuxBuffer */
        "movl sDisplayDepth, %edx\n" /* inPixelSize */
        "movl -0xc0(%ebp), %ecx\n" /* deviceHdl */
        "movl %ecx, -0x1c(%ebp)\n" /* inDeviceHdl */
        /* { scope 2: attribs, refreshRate */
        /* { scope 3 */
        "movl $4, -0x9c(%ebp)\n" /* line 1031 | attribs */
        "movl $5, -0x98(%ebp)\n" /* line 1032 */
        "movl $0x48, -0x94(%ebp)\n" /* line 1033 */
        "cmpb $0, sInWindowMode\n" /* line 1035 */
        "je .Lf57ca_00005ea1\n"
        "leal -0x90(%ebp), %ecx\n"
        ".Lf57ca_00005d62:\n"
        "movl -0x1c(%ebp), %edi\n" /* line 1043 | inDeviceHdl */
        "testl %edi, %edi\n"
        "je .Lf57ca_00005d72\n"
        "movl $0x49, (%ecx)\n" /* line 1045 */
        "addl $4, %ecx\n"
        ".Lf57ca_00005d72:\n"
        "movl $0xc, (%ecx)\n" /* line 1048 */
        "movl %esi, 4(%ecx)\n" /* line 1049 */
        "leal 8(%ecx), %edx\n"
        "movl -0xc4(%ebp), %esi\n" /* line 1051 | stencilSize */
        "testl %esi, %esi\n"
        "jle .Lf57ca_00005d9b\n"
        "movl $0xd, 8(%ecx)\n" /* line 1053 */
        "movl -0xc4(%ebp), %edx\n" /* line 1054 | stencilSize */
        "movl %edx, 0xc(%ecx)\n"
        "leal 0x10(%ecx), %edx\n"
        ".Lf57ca_00005d9b:\n"
        "testb %al, %al\n" /* line 1057 */
        "je .Lf57ca_00005db6\n"
        "movl $7, (%edx)\n" /* line 1059 */
        "movl $2, 4(%edx)\n" /* line 1061 */
        "movl $0x39, 8(%edx)\n" /* line 1069 */
        "addl $0xc, %edx\n"
        ".Lf57ca_00005db6:\n"
        "movl $0, (%edx)\n" /* line 1080 */
        "movl -0x1c(%ebp), %eax\n" /* line 1082 | inDeviceHdl */
        "testl %eax, %eax\n"
        "je .Lf57ca_00005f5a\n"
        "leal -0x9c(%ebp), %ecx\n" /* line 1084 | attribs */
        "movl %ecx, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* inDeviceHdl */
        "movl %eax, (%esp)\n"
        "calll aglChoosePixelFormat\n"
        "movl %eax, %edi\n"
        /* } scope */
        /* } scope */
        ".Lf57ca_00005de6:\n"
        "testl %edi, %edi\n" /* line 1196 | format */
        "je .Lf57ca_00005ca5\n"
        "movl $0, 0x10(%ebp)\n" /* line 1200 | inMultiSampleType */
        "jmp .Lf57ca_0000593d\n"
        ".Lf57ca_00005dfa:\n"
        "movl sDisplayIndex, %eax\n" /* line 495 */
        "leal (%eax, %eax, 4), %eax\n" /* line 654 */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "addl sDisplayList, %eax\n"
        "movl 0x38(%eax), %eax\n" /* line 147 */
        "movl %eax, 4(%esp)\n"
        "movl $str_00215870, (%esp)\n" /* "GL_ARB_multisample" */
        "calll gluCheckExtension\n"
        "testb %al, %al\n" /* line 1133 */
        "jne .Lf57ca_00005817\n"
        "jmp .Lf57ca_00005810\n"
        /* { scope 2: attribs, refreshRate */
        ".Lf57ca_00005e2e:\n"
        "movl sDisplayID, %eax\n" /* line 721 */
        "movl %eax, (%esp)\n"
        "calll CGDisplayBitsPerPixel\n"
        "movl %eax, sDisplayDepth\n"
        "movl %eax, -0xb8(%ebp)\n" /* line 724 | currDepth */
        "movl sDisplayRefreshRate, %ecx\n" /* line 735 */
        "testl %ecx, %ecx\n"
        "jne .Lf57ca_000059d7\n"
        ".Lf57ca_00005e54:\n"
        "movl sDisplayID, %eax\n" /* line 737 */
        "movl %eax, (%esp)\n"
        "calll CGDisplayCurrentMode\n"
        "testl %eax, %eax\n" /* line 738 */
        "je .Lf57ca_000059d7\n"
        "movl $0x32e624, 4(%esp)\n" /* line 740 */
        "movl %eax, (%esp)\n"
        "calll MacTools_GetDictionaryValue\n"
        "cmpl $-1, %eax\n" /* line 743 */
        "cmovel sDisplayRefreshRate, %eax\n"
        "movl %eax, sDisplayRefreshRate\n"
        "movl %eax, %edx\n"
        "jmp .Lf57ca_000059dd\n"
        /* } scope */
        ".Lf57ca_00005e8f:\n"
        "movl (%ebx), %eax\n" /* line 1269 | contextRef */
        "movl %eax, (%esp)\n"
        "calll aglGetDrawable\n"
        "movl %eax, 4(%ebx)\n" /* contextRef */
        "jmp .Lf57ca_00005bbd\n"
        /* { scope 2: attribs, refreshRate */
        /* { scope 3 */
        ".Lf57ca_00005ea1:\n"
        "movl $0x36, -0x90(%ebp)\n" /* line 1037 */
        "movl $0x32, -0x8c(%ebp)\n" /* line 1039 */
        "movl %edx, -0x88(%ebp)\n" /* line 1040 */
        "leal -0x84(%ebp), %ecx\n"
        "jmp .Lf57ca_00005d62\n"
        /* } scope */
        /* } scope */
        ".Lf57ca_00005ec6:\n"
        "movw $0x18, %si\n" /* line 1118 | inDepthSize */
        "movl $8, -0xc4(%ebp)\n" /* stencilSize */
        "jmp .Lf57ca_000057f7\n"
        /* { scope 2: attribs, refreshRate */
        /* { scope 3 */
        ".Lf57ca_00005ed9:\n"
        "movl $0x4b, -0xb0(%ebp)\n" /* line 2567 | refreshRate */
        "jmp .Lf57ca_00005a43\n"
        /* } scope */
        /* } scope */
        /* { scope 2: attribs, refreshRate */
        /* { scope 3 */
        ".Lf57ca_00005ee8:\n"
        "leal -0x9c(%ebp), %edx\n" /* line 1088 | attribs */
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll aglChoosePixelFormat\n"
        "movl %eax, %edi\n"
        "jmp .Lf57ca_00005935\n"
        /* } scope */
        /* } scope */
        ".Lf57ca_00005f0d:\n"
        "movl $0x809d, (%esp)\n" /* line 1315 */
        "calll glDisable\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 1320 | contextRef */
        "addl $0xdc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: inDeviceHdl, currHeight, currDepth, currRate */
        /* { scope 2: attribs, refreshRate */
        ".Lf57ca_00005f26:\n"
        "movl sDisplayID, %eax\n" /* line 706 */
        "movl %eax, (%esp)\n"
        "calll CGDisplayPixelsWide\n"
        "movl %eax, %esi\n"
        "movl sDisplayID, %eax\n" /* line 707 */
        "movl %eax, (%esp)\n"
        "calll CGDisplayPixelsHigh\n"
        "movl %eax, -0xbc(%ebp)\n" /* currHeight */
        "movl sDisplayDepth, %eax\n" /* line 719 */
        "testl %eax, %eax\n"
        "jne .Lf57ca_000059be\n"
        "jmp .Lf57ca_00005e2e\n"
        /* } scope */
        /* { scope 2: attribs, refreshRate */
        /* { scope 3 */
        ".Lf57ca_00005f5a:\n"
        "leal -0x9c(%ebp), %eax\n" /* line 1088 | attribs */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll aglChoosePixelFormat\n"
        "movl %eax, %edi\n"
        "jmp .Lf57ca_00005de6\n"
        /* } scope */
        /* } scope */
        ".Lf57ca_00005f7f:\n"
        "movl $str_00215884, (%esp)\n" /* line 1157 */
        "calll game_dprintf\n"
        "movl 0x1c(%ebp), %ecx\n" /* line 1159 | outHasAuxBuffer */
        "movzbl (%ecx), %eax\n" /* inUseAuxBuffer */
        "movl sDisplayDepth, %edx\n" /* inPixelSize */
        "movl -0xc0(%ebp), %ecx\n" /* deviceHdl */
        "movl %ecx, -0x1c(%ebp)\n" /* inDeviceHdl */
        /* { scope 2: attribs, refreshRate */
        /* { scope 3 */
        "movl $4, -0x9c(%ebp)\n" /* line 1031 | attribs */
        "movl $5, -0x98(%ebp)\n" /* line 1032 */
        "movl $0x48, -0x94(%ebp)\n" /* line 1033 */
        "cmpb $0, sInWindowMode\n" /* line 1035 */
        "je .Lf57ca_0000608e\n"
        "leal -0x90(%ebp), %ecx\n"
        ".Lf57ca_00005fd1:\n"
        "movl -0x1c(%ebp), %edi\n" /* line 1043 | inDeviceHdl */
        "testl %edi, %edi\n"
        "je .Lf57ca_00005fe1\n"
        "movl $0x49, (%ecx)\n" /* line 1045 */
        "addl $4, %ecx\n"
        ".Lf57ca_00005fe1:\n"
        "movl $0xc, (%ecx)\n" /* line 1048 */
        "movl $0x10, 4(%ecx)\n" /* line 1049 */
        "leal 8(%ecx), %edx\n"
        "movl -0xc4(%ebp), %esi\n" /* line 1051 | stencilSize */
        "testl %esi, %esi\n"
        "jle .Lf57ca_0000600e\n"
        "movl $0xd, 8(%ecx)\n" /* line 1053 */
        "movl -0xc4(%ebp), %edx\n" /* line 1054 | stencilSize */
        "movl %edx, 0xc(%ecx)\n"
        "leal 0x10(%ecx), %edx\n"
        ".Lf57ca_0000600e:\n"
        "testb %al, %al\n" /* line 1057 */
        "je .Lf57ca_00006029\n"
        "movl $7, (%edx)\n" /* line 1059 */
        "movl $2, 4(%edx)\n" /* line 1061 */
        "movl $0x39, 8(%edx)\n" /* line 1069 */
        "addl $0xc, %edx\n"
        ".Lf57ca_00006029:\n"
        "cmpl $1, 0x10(%ebp)\n" /* line 1072 | inMultiSampleType */
        "jle .Lf57ca_0000604c\n"
        "movl $0x37, (%edx)\n" /* line 1074 */
        "movl $1, 4(%edx)\n" /* line 1075 */
        "movl $0x38, 8(%edx)\n" /* line 1076 */
        "movl 0x10(%ebp), %ecx\n" /* line 1077 | inMultiSampleType */
        "movl %ecx, 0xc(%edx)\n"
        "addl $0x10, %edx\n"
        ".Lf57ca_0000604c:\n"
        "movl $0, (%edx)\n" /* line 1080 */
        "movl -0x1c(%ebp), %eax\n" /* line 1082 | inDeviceHdl */
        "testl %eax, %eax\n"
        "je .Lf57ca_000060ef\n"
        "leal -0x9c(%ebp), %eax\n" /* line 1084 | attribs */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* inDeviceHdl */
        "movl %eax, (%esp)\n"
        "calll aglChoosePixelFormat\n"
        "movl %eax, %edi\n"
        /* } scope */
        /* } scope */
        ".Lf57ca_0000607c:\n"
        "testl %edi, %edi\n" /* line 1163 | format */
        "jne .Lf57ca_0000593d\n"
        "movl $0x10, %esi\n" /* inDepthSize */
        "jmp .Lf57ca_00005d0a\n"
        /* { scope 2: attribs, refreshRate */
        /* { scope 3 */
        ".Lf57ca_0000608e:\n"
        "movl $0x36, -0x90(%ebp)\n" /* line 1037 */
        "movl $0x32, -0x8c(%ebp)\n" /* line 1039 */
        "movl %edx, -0x88(%ebp)\n" /* line 1040 */
        "leal -0x84(%ebp), %ecx\n"
        "jmp .Lf57ca_00005fd1\n"
        /* } scope */
        /* } scope */
        /* { scope 2: attribs, refreshRate */
        /* { scope 3 */
        ".Lf57ca_000060b3:\n"
        "movl -0xb0(%ebp), %eax\n" /* line 2581 | refreshRate */
        "movl %eax, -0xac(%ebp)\n"
        "jmp .Lf57ca_00005ae2\n"
        /* } scope */
        /* } scope */
        ".Lf57ca_000060c4:\n"
        "movl %edi, (%esp)\n" /* line 1209 | format */
        "calll aglDestroyPixelFormat\n"
        "jmp .Lf57ca_00005ca5\n"
        /* { scope 2: attribs, refreshRate */
        /* { scope 3 */
        ".Lf57ca_000060d1:\n"
        "cmpl $0x63, -0xac(%ebp)\n" /* line 2597 */
        "jg .Lf57ca_00005a7a\n"
        "cmpl %ecx, -0xac(%ebp)\n" /* line 2600 */
        "jl .Lf57ca_00005abb\n"
        "jmp .Lf57ca_00005a7a\n"
        /* } scope */
        /* } scope */
        /* { scope 2: attribs, refreshRate */
        /* { scope 3 */
        ".Lf57ca_000060ef:\n"
        "leal -0x9c(%ebp), %edx\n" /* line 1088 | attribs */
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll aglChoosePixelFormat\n"
        "movl %eax, %edi\n"
        "jmp .Lf57ca_0000607c\n"
        /* } scope */
        /* } scope */
        /* { scope 2: attribs, refreshRate */
        /* { scope 3 */
        ".Lf57ca_00006114:\n"
        "movl -0xbc(%ebp), %ecx\n" /* line 2579 | currHeight */
        "cmpl %ecx, 4(%edx)\n"
        "jne .Lf57ca_00005ad5\n"
        "movl -0xb8(%ebp), %ecx\n" /* currDepth */
        "cmpl 8(%edx), %ecx\n"
        "jne .Lf57ca_00005ad5\n"
        "movl 0xc(%edx), %ecx\n" /* line 2581 */
        "cmpl %ecx, -0xb0(%ebp)\n" /* refreshRate */
        "je .Lf57ca_00005ad5\n"
        "cmpl $0x63, %ecx\n" /* line 2589 */
        "jle .Lf57ca_0000615d\n"
        "cmpl %ecx, -0xac(%ebp)\n" /* line 2592 */
        "jle .Lf57ca_00005ad5\n"
        ".Lf57ca_00006152:\n"
        "movl %ecx, -0xac(%ebp)\n" /* line 2600 */
        "jmp .Lf57ca_00005ad5\n"
        ".Lf57ca_0000615d:\n"
        "cmpl $0x63, -0xac(%ebp)\n" /* line 2597 */
        "jg .Lf57ca_00005ad5\n"
        "cmpl %ecx, -0xac(%ebp)\n" /* line 2600 */
        "jge .Lf57ca_00005ad5\n"
        "jmp .Lf57ca_00006152\n"
    );
}
#else
static ContextRef MacDisplay_CreateScreenContext_orig(int inDepthSize, int inUseStencil, int inMultiSampleType, int inMultiSampleQuality, int inPresentationInterval, Boolean *outHasAuxBuffer)
{ return 0; }
#endif

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
#ifndef __EMSCRIPTEN__
__attribute__((naked))
short unsigned int MacDisplay_SetMode(int inWidth, int inHeight, int inDepth, int inRefreshRate)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 774 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* inWidth */
        /* { scope 1 */
        "movl sMainWindow, %eax\n" /* line 785 */
        "movl %eax, (%esp)\n"
        "calll IsWindowVisible\n"
        "movl %eax, %esi\n" /* wasVisible */
        "testb %al, %al\n" /* line 786 */
        "je .Lf628a_000062fc\n"
        /* { scope 2 */
        "movl sMainWindow, %edx\n" /* line 687 */
        "testl %edx, %edx\n"
        "je .Lf628a_000063b8\n"
        "leal -0x28(%ebp), %eax\n" /* line 690 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll GetWindowPortBounds\n"
        "movswl -0x22(%ebp), %ebx\n" /* line 692 */
        "cmpl $0x27f, %ebx\n" /* line 693 */
        "movl $0x280, %eax\n"
        "cmovlel %eax, %ebx\n"
        "movswl -0x24(%ebp), %eax\n" /* line 698 */
        "cmpl $0x1df, %eax\n" /* line 699 */
        "jle .Lf628a_000063a9\n"
        "cmpl %ebx, %edi\n" /* line 791 | currWidth, inWidth */
        "je .Lf628a_0000638e\n"
        ".Lf628a_000062ef:\n"
        "movl sMainWindow, %eax\n" /* line 801 */
        "movl %eax, (%esp)\n"
        "calll HideWindow\n"
        /* } scope */
        ".Lf628a_000062fc:\n"
        "movl $0, 0xc(%esp)\n" /* line 805 */
        "movswl 0xc(%ebp), %eax\n" /* inHeight */
        "movl %eax, 8(%esp)\n"
        "movswl %di, %eax\n" /* inWidth */
        "movl %eax, 4(%esp)\n"
        "movl sMainWindow, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SizeWindow\n"
        "movl 0x10(%ebp), %eax\n" /* line 806 | inDepth */
        "movl %eax, sDisplayDepth\n"
        "movl 0x14(%ebp), %eax\n" /* line 807 | inRefreshRate */
        "movl %eax, sDisplayRefreshRate\n"
        "calll CenterWindowOnDisplay\n" /* line 808 */
        "movl sMainWindow, %eax\n" /* line 812 */
        "movl %eax, (%esp)\n"
        "calll SetPortWindowPort\n"
        "movl $0x21, (%esp)\n" /* line 813 */
        "calll ForeColor\n"
        "leal -0x20(%ebp), %ebx\n" /* line 815 | bounds, currWidth */
        "movl %ebx, 4(%esp)\n" /* currWidth */
        "movl sMainWindow, %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetWindowPortBounds\n"
        "movl %ebx, (%esp)\n" /* line 816 | currWidth */
        "calll PaintRect\n"
        "movl %esi, %eax\n" /* line 819 | wasVisible */
        "testb %al, %al\n"
        "jne .Lf628a_00006379\n"
        "cmpb $0, sInWindowMode\n"
        "je .Lf628a_00006386\n"
        ".Lf628a_00006379:\n"
        "movl sMainWindow, %eax\n" /* line 821 */
        "movl %eax, (%esp)\n"
        "calll ShowWindow\n"
        /* } scope */
        ".Lf628a_00006386:\n"
        "addl $0x2c, %esp\n" /* line 823 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf628a_0000638e:\n"
        "cmpl %eax, 0xc(%ebp)\n" /* line 791 | inHeight */
        "jne .Lf628a_000062ef\n"
        "movl 0x10(%ebp), %eax\n" /* line 795 | inDepth */
        "movl %eax, sDisplayDepth\n"
        "movl 0x14(%ebp), %eax\n" /* line 796 | inRefreshRate */
        "movl %eax, sDisplayRefreshRate\n"
        "jmp .Lf628a_00006386\n"
        ".Lf628a_000063a9:\n"
        "movl $0x1e0, %eax\n" /* line 699 */
        "cmpl %ebx, %edi\n" /* line 791 | currWidth, inWidth */
        "jne .Lf628a_000062ef\n"
        "jmp .Lf628a_0000638e\n"
        ".Lf628a_000063b8:\n"
        "movl sDisplayID, %eax\n" /* line 706 */
        "movl %eax, (%esp)\n"
        "calll CGDisplayPixelsWide\n"
        "movl %eax, %ebx\n"
        "movl sDisplayID, %eax\n" /* line 707 */
        "movl %eax, (%esp)\n"
        "calll CGDisplayPixelsHigh\n"
        "cmpl %ebx, %edi\n" /* line 791 | currWidth, inWidth */
        "jne .Lf628a_000062ef\n"
        "jmp .Lf628a_0000638e\n"
    );
}
#else
short unsigned int MacDisplay_SetMode(int inWidth, int inHeight, int inDepth, int inRefreshRate)
{ return 0; }
#endif

/* line 2361 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void ZN12CDisplayInfoaSERKS_(void) /* CDisplayInfo_operator= */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2361 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* inInfo */
        "movl (%ebx), %eax\n" /* line 2365 | inInfo */
        "movl %eax, (%esi)\n" /* this */
        "movl 4(%ebx), %eax\n" /* line 2366 | inInfo */
        "movl %eax, 4(%esi)\n" /* this */
        "movl 8(%ebx), %eax\n" /* inInfo */
        "movl %eax, 8(%esi)\n" /* this */
        "movl 0xc(%ebx), %eax\n" /* inInfo */
        "movl %eax, 0xc(%esi)\n" /* this */
        "movl 0x10(%ebx), %eax\n" /* inInfo */
        "movl %eax, 0x10(%esi)\n" /* this */
        "leal 0x14(%ebx), %eax\n" /* line 2367 | inInfo */
        "movl %eax, 4(%esp)\n"
        "leal 0x14(%esi), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll ZNSt6vectorI8CResInfoSaIS0_EEaSERKS2_\n"
        "leal 0x20(%ebx), %eax\n" /* line 480 */
        "movl %eax, 4(%esp)\n"
        "leal 0x20(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSs6assignERKSs\n"
        "movl 0x24(%ebx), %eax\n" /* line 2369 | inInfo */
        "movl %eax, 0x24(%esi)\n" /* this */
        "movl 0x28(%ebx), %eax\n" /* line 2370 | inInfo */
        "movl %eax, 0x28(%esi)\n" /* this */
        "movl 0x2c(%ebx), %eax\n" /* line 2371 | inInfo */
        "movl %eax, 0x2c(%esi)\n" /* this */
        "leal 0x30(%ebx), %eax\n" /* line 480 */
        "movl %eax, 4(%esp)\n"
        "leal 0x30(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSs6assignERKSs\n"
        "leal 0x34(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x34(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSs6assignERKSs\n"
        "leal 0x38(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x38(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSs6assignERKSs\n"
        "movl 0x3c(%ebx), %eax\n" /* line 2375 | inInfo */
        "movl %eax, 0x3c(%esi)\n" /* this */
        "movl 0x40(%ebx), %eax\n" /* line 2376 | inInfo */
        "movl %eax, 0x40(%esi)\n" /* this */
        "movl 0x44(%ebx), %eax\n" /* line 2377 | inInfo */
        "movl %eax, 0x44(%esi)\n" /* this */
        "movl 0x48(%ebx), %eax\n" /* line 2378 | inInfo */
        "movl %eax, 0x48(%esi)\n" /* this */
        "movl 0x4c(%ebx), %eax\n" /* line 2379 | inInfo */
        "movl %eax, 0x4c(%esi)\n" /* this */
        "movzbl 0x50(%ebx), %eax\n" /* line 2380 | inInfo */
        "movb %al, 0x50(%esi)\n" /* this */
        "movzbl 0x51(%ebx), %eax\n" /* line 2381 | inInfo */
        "movb %al, 0x51(%esi)\n" /* this */
        "movzbl 0x52(%ebx), %eax\n" /* line 2382 | inInfo */
        "movb %al, 0x52(%esi)\n" /* this */
        "movl 0x54(%ebx), %eax\n" /* line 2383 | inInfo */
        "movl %eax, 0x54(%esi)\n" /* this */
        "movl 0x58(%ebx), %eax\n" /* line 2384 | inInfo */
        "movl %eax, 0x58(%esi)\n" /* this */
        "movl 0x5c(%ebx), %eax\n" /* line 2385 | inInfo */
        "movl %eax, 0x5c(%esi)\n" /* this */
        "movzbl 0x60(%ebx), %eax\n" /* line 2386 | inInfo */
        "movb %al, 0x60(%esi)\n" /* this */
        "movzbl 0x61(%ebx), %eax\n" /* line 2387 | inInfo */
        "movb %al, 0x61(%esi)\n" /* this */
        "movzbl 0x62(%ebx), %eax\n" /* line 2388 | inInfo */
        "movb %al, 0x62(%esi)\n" /* this */
        "movl %esi, %eax\n" /* line 2391 | this */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
void ZN12CDisplayInfoaSERKS_(void) /* CDisplayInfo_operator= */
{ }
#endif

/* line 1979 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
short unsigned int CDisplayInfo_CDisplayInfo(const CDisplayInfo * _this, CGDirectDisplayID inDisplayID)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1979 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x47c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %eax\n" /* line 1991 | inDisplayID */
        "movl %eax, (%ebx)\n" /* this */
        "leal 0x14(%ebx), %eax\n" /* this */
        "movl %eax, -0x474(%ebp)\n" /* this */
        /* { scope 1: rendererInfo, numRenderers, modeArrayRef, attrib, ... */
        "movl $0, 0x14(%ebx)\n" /* line 85 */
        "movl $0, 4(%eax)\n"
        "movl $0, 8(%eax)\n"
        /* } scope */
        "leal 0x20(%ebx), %edx\n" /* line 1991 | this */
        "movl %edx, -0x470(%ebp)\n" /* this */
        /* { scope 1: rendererInfo, numRenderers, modeArrayRef, attrib, ... */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %eax\n" /* line 207 */
        "addl $0xc, %eax\n"
        /* { scope 2: numModes, newContext */
        "movl %eax, 0x20(%ebx)\n" /* line 251 */
        /* } scope */
        /* } scope */
        "movl $0, 0x24(%ebx)\n" /* line 1991 | this */
        "movl $0, 0x28(%ebx)\n" /* this */
        "movl $0, 0x2c(%ebx)\n" /* this */
        "leal 0x30(%ebx), %edx\n" /* this */
        "movl %edx, -0x46c(%ebp)\n" /* this */
        /* { scope 1: rendererInfo, numRenderers, modeArrayRef, attrib, ... */
        "movl %eax, 0x30(%ebx)\n" /* line 251 */
        /* } scope */
        "leal 0x34(%ebx), %edx\n" /* line 1991 | this */
        "movl %edx, -0x468(%ebp)\n" /* this */
        /* { scope 1: rendererInfo, numRenderers, modeArrayRef, attrib, ... */
        "movl %eax, 0x34(%ebx)\n" /* line 251 */
        /* } scope */
        "leal 0x38(%ebx), %edx\n" /* line 1991 | this */
        "movl %edx, -0x464(%ebp)\n" /* this */
        /* { scope 1: rendererInfo, numRenderers, modeArrayRef, attrib, ... */
        "movl %eax, 0x38(%ebx)\n" /* line 251 */
        /* } scope */
        "movl $0x4000000, 0x3c(%ebx)\n" /* line 1991 | this */
        "movl $0x4000000, 0x40(%ebx)\n" /* this */
        "movl $1, 0x44(%ebx)\n" /* this */
        "movl $0xffff0000, 0x4c(%ebx)\n" /* this */
        "movb $1, 0x50(%ebx)\n" /* this */
        "movb $0, 0x51(%ebx)\n" /* this */
        "movb $0, 0x52(%ebx)\n" /* this */
        "movl $0x3f800000, 0x54(%ebx)\n" /* this */
        /* { scope 1: rendererInfo, numRenderers, modeArrayRef, attrib, ... */
        "leal -0x448(%ebp), %edx\n" /* line 1994 */
        "movl (%ebx), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CGDisplayBounds\n"
        "subl $4, %esp\n"
        "movl -0x448(%ebp), %eax\n"
        "movl %eax, 4(%ebx)\n" /* this */
        "movl -0x444(%ebp), %eax\n"
        "movl %eax, 8(%ebx)\n" /* this */
        "movl -0x440(%ebp), %eax\n"
        "movl %eax, 0xc(%ebx)\n" /* this */
        "movl -0x43c(%ebp), %eax\n"
        "movl %eax, 0x10(%ebx)\n" /* this */
        "movl (%ebx), %eax\n" /* line 1998 | this */
        "movl %eax, (%esp)\n"
        "calll CGDisplayIDToOpenGLDisplayMask\n"
        "movl %eax, -0x460(%ebp)\n" /* displayMask */
        "cmpb $0, 0x50(%ebx)\n" /* line 2002 | this */
        "jne .Lf64da_000065e1\n"
        /* } scope */
        ".Lf64da_000065d9:\n"
        "leal -0xc(%ebp), %esp\n" /* line 2322 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: rendererInfo, numRenderers, modeArrayRef, attrib, ... */
        /* { scope 2: numModes, newContext */
        ".Lf64da_000065e1:\n"
        "movb $0, 0x50(%ebx)\n" /* line 2004 | this */
        "leal -0x20(%ebp), %eax\n" /* line 2011 | numRenderers, error */
        "movl %eax, 8(%esp)\n" /* error */
        "leal -0x1c(%ebp), %eax\n" /* rendererInfo, error */
        "movl %eax, 4(%esp)\n" /* error */
        "movl -0x460(%ebp), %eax\n" /* displayMask, error */
        "movl %eax, (%esp)\n" /* error */
        "calll CGLQueryRendererInfo\n"
        "testl %eax, %eax\n" /* line 2012 */
        "jne .Lf64da_0000678e\n"
        /* { scope 3: memory, fullscreen, accelerated, depth, ... */
        "movl -0x20(%ebp), %esi\n" /* line 2014 | numRenderers */
        "testl %esi, %esi\n"
        "jle .Lf64da_00006783\n"
        "xorl %edi, %edi\n" /* i */
        "leal -0x24(%ebp), %esi\n" /* memory */
        /* { scope 4: height, depth */
        ".Lf64da_00006619:\n"
        "movl $0, -0x24(%ebp)\n" /* line 2016 | memory */
        "movl %esi, 0xc(%esp)\n" /* line 2017 */
        "movl $0x78, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* i */
        "movl -0x1c(%ebp), %eax\n" /* rendererInfo */
        "movl %eax, (%esp)\n"
        "calll CGLDescribeRenderer\n"
        "leal 0x3c(%ebx), %eax\n" /* this */
        /* { scope 5: resItem */
        "movl -0x24(%ebp), %edx\n" /* line 211 | memory */
        "cmpl 0x3c(%ebx), %edx\n"
        "cmovgel %esi, %eax\n"
        /* } scope */
        "movl (%eax), %eax\n" /* line 2018 | __b */
        "movl %eax, 0x3c(%ebx)\n" /* __b, this */
        "movl %esi, 0xc(%esp)\n" /* line 2020 */
        "movl $0x79, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* i */
        "movl -0x1c(%ebp), %eax\n" /* rendererInfo */
        "movl %eax, (%esp)\n"
        "calll CGLDescribeRenderer\n"
        "leal 0x40(%ebx), %eax\n" /* this */
        /* { scope 5: resItem */
        "movl -0x24(%ebp), %edx\n" /* line 211 | memory */
        "cmpl 0x40(%ebx), %edx\n"
        "cmovgel %esi, %eax\n"
        /* } scope */
        "movl (%eax), %eax\n" /* line 2021 | __b */
        "movl %eax, 0x40(%ebx)\n" /* __b, this */
        "leal 0x58(%ebx), %eax\n" /* line 2024 | this */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x6c, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* i */
        "movl -0x1c(%ebp), %eax\n" /* rendererInfo */
        "movl %eax, (%esp)\n"
        "calll CGLDescribeRenderer\n"
        "leal 0x5c(%ebx), %eax\n" /* line 2026 | this */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x6d, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* i */
        "movl -0x1c(%ebp), %eax\n" /* rendererInfo */
        "movl %eax, (%esp)\n"
        "calll CGLDescribeRenderer\n"
        "cmpl $1, 0x5c(%ebx)\n" /* line 2027 | this */
        "setg %al\n"
        "movb %al, 0x60(%ebx)\n" /* this */
        "movb $0, 0x61(%ebx)\n" /* line 2028 | this */
        "movb %al, 0x62(%ebx)\n" /* line 2029 | __dat, this */
        "movl $0, -0x28(%ebp)\n" /* line 2031 | fullscreen */
        "leal -0x28(%ebp), %eax\n" /* line 2032 | fullscreen */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x36, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* i */
        "movl -0x1c(%ebp), %eax\n" /* rendererInfo */
        "movl %eax, (%esp)\n"
        "calll CGLDescribeRenderer\n"
        "movl $0, -0x34(%ebp)\n" /* line 2034 | accelerated */
        "leal -0x34(%ebp), %eax\n" /* line 2035 | accelerated */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x49, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* i */
        "movl -0x1c(%ebp), %eax\n" /* rendererInfo */
        "movl %eax, (%esp)\n"
        "calll CGLDescribeRenderer\n"
        "movl $0, -0x30(%ebp)\n" /* line 2037 | depth */
        "leal -0x30(%ebp), %eax\n" /* line 2038 | depth */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x69, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* i */
        "movl -0x1c(%ebp), %eax\n" /* rendererInfo */
        "movl %eax, (%esp)\n"
        "calll CGLDescribeRenderer\n"
        "movl $0, -0x2c(%ebp)\n" /* line 2040 | stencil */
        "leal -0x2c(%ebp), %eax\n" /* line 2041 | stencil */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x6a, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* i */
        "movl -0x1c(%ebp), %eax\n" /* rendererInfo */
        "movl %eax, (%esp)\n"
        "calll CGLDescribeRenderer\n"
        "movl -0x28(%ebp), %eax\n" /* line 2044 | fullscreen */
        "testl %eax, %eax\n"
        "je .Lf64da_00006777\n"
        "movl -0x34(%ebp), %eax\n" /* accelerated */
        "testl %eax, %eax\n"
        "je .Lf64da_00006777\n"
        "testb $8, -0x2f(%ebp)\n"
        "je .Lf64da_00006777\n"
        "cmpb $0, -0x2c(%ebp)\n" /* stencil */
        "js .Lf64da_00006ad3\n"
        /* } scope */
        ".Lf64da_00006777:\n"
        "addl $1, %edi\n" /* line 2014 | i */
        "cmpl %edi, -0x20(%ebp)\n" /* i, numRenderers */
        "jg .Lf64da_00006619\n"
        /* } scope */
        ".Lf64da_00006783:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2054 | rendererInfo */
        "movl %eax, (%esp)\n"
        "calll CGLDestroyRendererInfo\n"
        /* } scope */
        ".Lf64da_0000678e:\n"
        "cmpb $0, 0x50(%ebx)\n" /* line 2060 | this */
        "je .Lf64da_000065d9\n"
        /* { scope 2: numModes, newContext */
        "movb $0, 0x50(%ebx)\n" /* line 2062 | this */
        "movl (%ebx), %eax\n" /* line 2065 | this */
        "movl %eax, (%esp)\n"
        "calll CGDisplayAvailableModes\n"
        "movl %eax, -0x45c(%ebp)\n" /* modeArrayRef */
        "testl %eax, %eax\n" /* line 2066 */
        "je .Lf64da_00006810\n"
        /* { scope 3: memory, fullscreen, accelerated, depth, ... */
        "movl %eax, (%esp)\n" /* line 2068 */
        "calll CFArrayGetCount\n"
        "movl %eax, -0x458(%ebp)\n" /* numModes */
        /* { scope 4: height, depth */
        "testl %eax, %eax\n" /* line 2069 */
        "jg .Lf64da_00006b28\n"
        ".Lf64da_000067c6:\n"
        "movl -0x474(%ebp), %edx\n" /* line 352 | this */
        "movl 4(%edx), %edi\n"
        /* } scope */
        "movl (%edx), %esi\n" /* line 334 */
        /* { scope 4: height, depth */
        "cmpl %esi, %edi\n" /* line 2568 | currContext, port */
        "je .Lf64da_00006810\n"
        "movl %edi, %eax\n" /* line 759 */
        "subl %esi, %eax\n"
        "sarl $4, %eax\n"
        /* { scope 5: resItem */
        /* { scope 6 */
        "cmpl $1, %eax\n" /* line 2253 */
        "je .Lf64da_00006d75\n"
        "xorl %edx, %edx\n"
        ".Lf64da_000067e7:\n"
        "addl $1, %edx\n" /* line 2254 */
        "sarl $1, %eax\n" /* line 2253 */
        "cmpl $1, %eax\n"
        "jne .Lf64da_000067e7\n"
        "leal (%edx, %edx), %eax\n"
        /* } scope */
        /* } scope */
        ".Lf64da_000067f4:\n"
        "movl %eax, 8(%esp)\n" /* line 2570 | __n */
        "movl %edi, 4(%esp)\n" /* port */
        "movl %esi, (%esp)\n" /* currContext */
        "calll ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEiEvT_S8_T0_\n"
        "movl %edi, 4(%esp)\n" /* line 2571 | port */
        "movl %esi, (%esp)\n" /* currContext */
        "calll ZSt22__final_insertion_sortIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEEvT_S8_\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf64da_00006810:\n"
        "cmpb $0, 0x50(%ebx)\n" /* line 2124 | this */
        "je .Lf64da_000065d9\n"
        /* { scope 2: numModes, newContext */
        "movl (%ebx), %eax\n" /* line 2126 | this */
        "movl %eax, (%esp)\n"
        "calll CGDisplayIOServicePort\n"
        "movl %eax, %edi\n" /* port */
        "testl %eax, %eax\n" /* line 2127 */
        "jne .Lf64da_00006c7b\n"
        /* } scope */
        ".Lf64da_0000682e:\n"
        "cmpb $0, 0x50(%ebx)\n" /* line 2181 | this */
        "je .Lf64da_000065d9\n"
        /* { scope 2: numModes, newContext */
        "calll CGLGetCurrentContext\n" /* line 2183 */
        "movl %eax, %esi\n" /* currContext */
        "movl $0, -0x42c(%ebp)\n" /* line 2185 */
        "movl $0x54, -0x434(%ebp)\n" /* attrib */
        "movl -0x460(%ebp), %edx\n" /* displayMask */
        "movl %edx, -0x430(%ebp)\n"
        "movl $0, -0x34(%ebp)\n" /* line 2187 | accelerated */
        "movl $0, -0x2c(%ebp)\n" /* line 2188 | stencil */
        "leal -0x2c(%ebp), %eax\n" /* line 2189 | stencil */
        "movl %eax, 8(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* accelerated */
        "movl %eax, 4(%esp)\n"
        "leal -0x434(%ebp), %eax\n" /* attrib */
        "movl %eax, (%esp)\n"
        "calll CGLChoosePixelFormat\n"
        "movl -0x34(%ebp), %eax\n" /* line 2191 | accelerated */
        "testl %eax, %eax\n"
        "je .Lf64da_000069c9\n"
        /* { scope 3: memory, fullscreen, accelerated, depth, ... */
        "movl $0, -0x30(%ebp)\n" /* line 2193 | depth */
        "leal -0x30(%ebp), %eax\n" /* line 2194 | depth */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl -0x34(%ebp), %eax\n" /* accelerated */
        "movl %eax, (%esp)\n"
        "calll CGLCreateContext\n"
        "movl -0x34(%ebp), %eax\n" /* line 2196 | accelerated */
        "movl %eax, (%esp)\n"
        "calll CGLDestroyPixelFormat\n"
        "movl -0x30(%ebp), %eax\n" /* line 2198 | depth */
        "testl %eax, %eax\n"
        "je .Lf64da_000069c9\n"
        "movl %eax, (%esp)\n" /* line 2200 */
        "calll CGLSetCurrentContext\n"
        "movl $0x1f00, (%esp)\n" /* line 2202 */
        "calll glGetString\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 2203 */
        "je .Lf64da_0000690c\n"
        "cld\n" /* line 257 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %edx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x46c(%ebp), %edx\n" /* this */
        "movl %edx, (%esp)\n"
        "calll __ZNSs6assignEPKcm\n"
        ".Lf64da_0000690c:\n"
        "movl $0x1f01, (%esp)\n" /* line 2208 */
        "calll glGetString\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 2209 */
        "je .Lf64da_00006945\n"
        "cld\n" /* line 257 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %edx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x468(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll __ZNSs6assignEPKcm\n"
        ".Lf64da_00006945:\n"
        "movl $0x1f03, (%esp)\n" /* line 2214 */
        "calll glGetString\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 2215 */
        "je .Lf64da_0000697e\n"
        "cld\n" /* line 257 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %edx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x464(%ebp), %edx\n" /* this */
        "movl %edx, (%esp)\n"
        "calll __ZNSs6assignEPKcm\n"
        ".Lf64da_0000697e:\n"
        "leal 0x44(%ebx), %eax\n" /* line 2221 | this */
        "movl %eax, 4(%esp)\n"
        "movl $0x84e2, (%esp)\n"
        "calll glGetIntegerv\n"
        "movl $0, 0x48(%ebx)\n" /* line 2223 | this */
        "movl 0x38(%ebx), %eax\n" /* line 147 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021595c, (%esp)\n" /* "GL_ARB_fragment_program" */
        "calll gluCheckExtension\n"
        "testb %al, %al\n" /* line 2225 */
        "je .Lf64da_000069be\n"
        "calll MacFeatures_GetSystemVersion\n"
        "cmpw $0x102f, %ax\n"
        "jg .Lf64da_00006e33\n"
        ".Lf64da_000069be:\n"
        "movl -0x30(%ebp), %eax\n" /* line 2230 | depth */
        "movl %eax, (%esp)\n"
        "calll CGLDestroyContext\n"
        /* } scope */
        ".Lf64da_000069c9:\n"
        "movl %esi, (%esp)\n" /* line 2234 | currContext */
        "calll CGLSetCurrentContext\n"
        /* } scope */
        "cmpb $0, 0x50(%ebx)\n" /* line 2239 | this */
        "je .Lf64da_000065d9\n"
        /* { scope 2: numModes, newContext */
        "movl -0x470(%ebp), %edx\n" /* line 2241 | this */
        "movl (%edx), %eax\n"
        "movl -0xc(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf64da_00006b11\n"
        ".Lf64da_000069ee:\n"
        "movl -0x46c(%ebp), %edx\n" /* line 2246 | this */
        "movl %edx, 4(%esp)\n"
        "leal -0x434(%ebp), %eax\n" /* attrib */
        "movl %eax, (%esp)\n"
        "calll __ZNSsC1ERKSs\n"
        "movl -0x434(%ebp), %eax\n" /* line 2247 | attrib */
        "movl %eax, (%esp)\n"
        "calll strlwr\n"
        "movl -0x434(%ebp), %esi\n" /* line 269 | attrib */
        "movl $str_00215974, 4(%esp)\n" /* line 2248 */
        "movl %esi, (%esp)\n" /* currContext */
        "calll strstr\n"
        "testl %eax, %eax\n"
        "je .Lf64da_00006e10\n"
        "movl $2, 0x2c(%ebx)\n" /* line 2250 | this */
        ".Lf64da_00006a39:\n"
        "movl 0x24(%ebx), %edi\n" /* line 2261 | this, port */
        "testl %edi, %edi\n" /* port */
        "je .Lf64da_00006ae9\n"
        ".Lf64da_00006a44:\n"
        "movl 0x38(%ebx), %eax\n" /* line 147 */
        "movl %eax, 4(%esp)\n"
        "movl $str_00215984, (%esp)\n" /* "GL_EXT_blend_func_separate" */
        "calll gluCheckExtension\n"
        "movb %al, 0x51(%ebx)\n" /* line 2287 | this */
        "movl 0x38(%ebx), %eax\n" /* line 147 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002159a0, (%esp)\n" /* "GL_EXT_texture_filter_anisotropic" */
        "calll gluCheckExtension\n"
        "movzbl %al, %eax\n" /* line 2288 */
        "movb %al, 0x52(%ebx)\n" /* this */
        "testl %eax, %eax\n" /* line 2289 */
        "jne .Lf64da_00006d5d\n"
        "movl $0x3f800000, 0x54(%ebx)\n" /* line 2295 | this */
        ".Lf64da_00006a82:\n"
        "movl 0x2c(%ebx), %eax\n" /* line 2299 | this */
        "cmpl $2, %eax\n"
        "je .Lf64da_00006d7c\n"
        "subl $1, %eax\n" /* line 2306 */
        "je .Lf64da_00006dd1\n"
        ".Lf64da_00006a97:\n"
        "movl 0x38(%ebx), %eax\n" /* line 147 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021595c, (%esp)\n" /* "GL_ARB_fragment_program" */
        "calll gluCheckExtension\n"
        "testb %al, %al\n" /* line 2314 */
        "je .Lf64da_00006ac0\n"
        "calll MacFeatures_GetSystemVersion\n"
        "cmpw $0x102f, %ax\n"
        "jle .Lf64da_00006ac0\n"
        "movl $0xffff0200, 0x4c(%ebx)\n" /* line 2316 | this */
        ".Lf64da_00006ac0:\n"
        "leal -0x434(%ebp), %eax\n" /* line 2317 | attrib */
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "jmp .Lf64da_000065d9\n"
        /* } scope */
        /* { scope 2: numModes, newContext */
        /* { scope 3: memory, fullscreen, accelerated, depth, ... */
        /* { scope 4: height, depth */
        ".Lf64da_00006ad3:\n"
        "cmpl $0x3ffffff, 0x3c(%ebx)\n" /* line 2046 | this */
        "jle .Lf64da_00006777\n"
        "movb $1, 0x50(%ebx)\n" /* line 2048 | this */
        "jmp .Lf64da_00006783\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: numModes, newContext */
        ".Lf64da_00006ae9:\n"
        "movl 0x2c(%ebx), %eax\n" /* line 2264 | this */
        "cmpl $2, %eax\n"
        "je .Lf64da_00006dbe\n"
        "cmpl $3, %eax\n"
        "je .Lf64da_00006dfd\n"
        "movl $0x1002, 0x24(%ebx)\n" /* line 2278 | this */
        "movl $0x5159, 0x28(%ebx)\n" /* line 2279 | this */
        "jmp .Lf64da_00006a44\n"
        ".Lf64da_00006b11:\n"
        "movl -0x468(%ebp), %eax\n" /* line 2243 | this */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll __ZNSs6assignERKSs\n"
        "jmp .Lf64da_000069ee\n"
        /* } scope */
        /* { scope 2: numModes, newContext */
        /* { scope 3: memory, fullscreen, accelerated, depth, ... */
        ".Lf64da_00006b28:\n"
        "movl $0, -0x454(%ebp)\n" /* line 2068 | i */
        "movl -0x454(%ebp), %edx\n" /* i */
        "jmp .Lf64da_00006b3c\n"
        ".Lf64da_00006b3a:\n"
        "movl %eax, %edx\n"
        /* { scope 4: height, depth */
        ".Lf64da_00006b3c:\n"
        "movl %edx, 4(%esp)\n" /* line 2071 */
        "movl -0x45c(%ebp), %eax\n" /* modeArrayRef */
        "movl %eax, (%esp)\n"
        "calll CFArrayGetValueAtIndex\n"
        "movl %eax, %edi\n" /* i */
        "testl %eax, %eax\n" /* line 2072 */
        "je .Lf64da_00006c5d\n"
        /* { scope 5: resItem */
        "movl $0x32e634, 4(%esp)\n" /* line 2074 */
        "movl %eax, (%esp)\n"
        "calll MacTools_GetDictionaryValue\n"
        "movl %eax, %esi\n" /* width */
        "movl $0x32e644, 4(%esp)\n" /* line 2075 */
        "movl %edi, (%esp)\n" /* i */
        "calll MacTools_GetDictionaryValue\n"
        "movl %eax, -0x450(%ebp)\n" /* height */
        "movl $0x32e654, 4(%esp)\n" /* line 2076 */
        "movl %edi, (%esp)\n" /* i */
        "calll MacTools_GetDictionaryValue\n"
        "movl %eax, -0x44c(%ebp)\n" /* depth */
        "movl $0x32e624, 4(%esp)\n" /* line 2077 */
        "movl %edi, (%esp)\n" /* i */
        "calll MacTools_GetDictionaryValue\n"
        "movl %eax, %edx\n" /* rate */
        "cmpl $0, %eax\n" /* line 2079 */
        "jl .Lf64da_00006c5d\n"
        "movl $0x3c, %eax\n" /* line 2083 */
        "cmovel %eax, %edx\n"
        "cmpl $0x27f, %esi\n" /* line 2090 | width */
        "jle .Lf64da_00006c5d\n"
        "cmpl $0x1df, -0x450(%ebp)\n" /* height */
        "jle .Lf64da_00006c5d\n"
        "cmpl $0x1f, -0x44c(%ebp)\n" /* depth */
        "jle .Lf64da_00006c5d\n"
        /* { scope 6 */
        "cmpl $0x4000000, 0x3c(%ebx)\n" /* line 2095 | this */
        "jg .Lf64da_00006bef\n"
        "cmpl $0x400, %esi\n" /* line 2097 | width */
        "jg .Lf64da_00006c5d\n"
        ".Lf64da_00006bef:\n"
        "movb $1, 0x50(%ebx)\n" /* line 2104 | this */
        "movl %esi, -0x434(%ebp)\n" /* line 2108 | width, attrib */
        "movl -0x450(%ebp), %eax\n" /* line 2109 | height */
        "movl %eax, -0x430(%ebp)\n"
        "movl -0x44c(%ebp), %eax\n" /* line 2110 | depth */
        "movl %eax, -0x42c(%ebp)\n"
        "movl %edx, -0x428(%ebp)\n" /* line 2111 */
        "movl -0x474(%ebp), %eax\n" /* line 604 | this */
        "movl 4(%eax), %edx\n"
        "cmpl 8(%eax), %edx\n"
        "je .Lf64da_00006e56\n"
        "testl %edx, %edx\n" /* line 104 */
        "je .Lf64da_00006e4b\n"
        "movl %esi, (%edx)\n"
        "movl -0x430(%ebp), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl -0x42c(%ebp), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl -0x428(%ebp), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "movl -0x474(%ebp), %eax\n" /* this */
        "movl 4(%eax), %edx\n"
        ".Lf64da_00006c57:\n"
        "addl $0x10, %edx\n" /* line 607 */
        "movl %edx, 4(%eax)\n"
        /* } scope */
        /* } scope */
        ".Lf64da_00006c5d:\n"
        "addl $1, -0x454(%ebp)\n" /* line 2069 | i */
        "movl -0x454(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x458(%ebp)\n" /* numModes */
        "jne .Lf64da_00006b3a\n"
        "jmp .Lf64da_000067c6\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: numModes, newContext */
        ".Lf64da_00006c7b:\n"
        "movl $str_002158f8, 4(%esp)\n" /* line 2129 */
        "movl %eax, (%esp)\n"
        "calll IOObjectConformsTo\n"
        "testl %eax, %eax\n"
        "je .Lf64da_0000682e\n"
        /* { scope 3: memory, fullscreen, accelerated, depth, ... */
        "movl $0, -0x30(%ebp)\n" /* line 2134 | depth */
        "leal -0x30(%ebp), %esi\n" /* line 2135 | depth, width */
        "movl %esi, 8(%esp)\n" /* width */
        "movl $str_00215908, 4(%esp)\n" /* "IOService" */
        "movl %edi, (%esp)\n" /* port */
        "calll IORegistryEntryGetParentEntry\n"
        "testl %eax, %eax\n" /* line 2136 */
        "jne .Lf64da_0000682e\n"
        "movl $str_00215914, 4(%esp)\n" /* line 2138 */
        "movl -0x30(%ebp), %eax\n" /* depth */
        "movl %eax, (%esp)\n"
        "calll IOObjectConformsTo\n"
        "testl %eax, %eax\n"
        "je .Lf64da_00006e77\n"
        ".Lf64da_00006cd4:\n"
        "movl -0x30(%ebp), %eax\n" /* line 2162 | depth */
        "testl %eax, %eax\n"
        "je .Lf64da_0000682e\n"
        /* { scope 4: height, depth */
        "leal -0x434(%ebp), %esi\n" /* line 2165 | attrib, width */
        "movl %esi, 8(%esp)\n" /* width */
        "movl $0x32e664, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll MacTools_GetIORegistryValue\n"
        "testb %al, %al\n" /* line 2166 */
        "je .Lf64da_00006d24\n"
        "cld\n" /* line 257 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl -0x470(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll __ZNSs6assignEPKcm\n"
        ".Lf64da_00006d24:\n"
        "leal 0x24(%ebx), %eax\n" /* line 2171 | this */
        "movl %eax, 8(%esp)\n"
        "movl $0x32e674, 4(%esp)\n"
        "movl -0x30(%ebp), %eax\n" /* depth */
        "movl %eax, (%esp)\n"
        "calll MacTools_GetIORegistryValue\n"
        "leal 0x28(%ebx), %eax\n" /* line 2173 | this */
        "movl %eax, 8(%esp)\n"
        "movl $0x32e684, 4(%esp)\n"
        "movl -0x30(%ebp), %eax\n" /* depth */
        "movl %eax, (%esp)\n"
        "calll MacTools_GetIORegistryValue\n"
        "jmp .Lf64da_0000682e\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: numModes, newContext */
        ".Lf64da_00006d5d:\n"
        "leal 0x54(%ebx), %eax\n" /* line 2291 | this */
        "movl %eax, 4(%esp)\n"
        "movl $0x84ff, (%esp)\n"
        "calll glGetFloatv\n"
        "jmp .Lf64da_00006a82\n"
        /* } scope */
        /* { scope 2: numModes, newContext */
        /* { scope 3: memory, fullscreen, accelerated, depth, ... */
        /* { scope 4: height, depth */
        /* { scope 5: resItem */
        ".Lf64da_00006d75:\n"
        "xorb %al, %al\n" /* line 2253 */
        "jmp .Lf64da_000067f4\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: numModes, newContext */
        ".Lf64da_00006d7c:\n"
        "movl 0x38(%ebx), %eax\n" /* line 147 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002159c4, (%esp)\n" /* "GL_NV_texture_shader" */
        "calll gluCheckExtension\n"
        "testb %al, %al\n" /* line 2301 */
        "je .Lf64da_00006a97\n"
        "movl 0x38(%ebx), %eax\n" /* line 147 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002159dc, (%esp)\n" /* "GL_NV_register_combiners2" */
        "calll gluCheckExtension\n"
        "testb %al, %al\n" /* line 2301 */
        "je .Lf64da_00006a97\n"
        ".Lf64da_00006db2:\n"
        "movl $0xffff0104, 0x4c(%ebx)\n" /* line 2310 | this */
        "jmp .Lf64da_00006a97\n"
        ".Lf64da_00006dbe:\n"
        "movl $0x10de, 0x24(%ebx)\n" /* line 2267 | this */
        "movl $0x110, 0x28(%ebx)\n" /* line 2268 | this */
        "jmp .Lf64da_00006a44\n"
        ".Lf64da_00006dd1:\n"
        "movl 0x38(%ebx), %eax\n" /* line 147 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002159f8, (%esp)\n" /* "GL_ATI_text_fragment_shader" */
        "calll gluCheckExtension\n"
        "testb %al, %al\n" /* line 2308 */
        "je .Lf64da_00006a97\n"
        "calll MacFeatures_GetSystemVersion\n"
        "cmpw $0x1027, %ax\n"
        "jle .Lf64da_00006a97\n"
        "jmp .Lf64da_00006db2\n"
        ".Lf64da_00006dfd:\n"
        "movl $0x8086, 0x24(%ebx)\n" /* line 2272 | this */
        "movl $0x2582, 0x28(%ebx)\n" /* line 2273 | this */
        "jmp .Lf64da_00006a44\n"
        ".Lf64da_00006e10:\n"
        "movl $str_0021597c, 4(%esp)\n" /* line 2252 */
        "movl %esi, (%esp)\n" /* currContext */
        "calll strstr\n"
        "cmpl $1, %eax\n" /* line 2254 */
        "sbbl %eax, %eax\n"
        "andl $0xfffffffe, %eax\n"
        "addl $3, %eax\n"
        "movl %eax, 0x2c(%ebx)\n" /* this */
        "jmp .Lf64da_00006a39\n"
        /* } scope */
        /* { scope 2: numModes, newContext */
        /* { scope 3: memory, fullscreen, accelerated, depth, ... */
        ".Lf64da_00006e33:\n"
        "leal 0x48(%ebx), %eax\n" /* line 2227 | this */
        "movl %eax, 4(%esp)\n"
        "movl $0x8872, (%esp)\n"
        "calll glGetIntegerv\n"
        "jmp .Lf64da_000069be\n"
        ".Lf64da_00006e4b:\n"
        "movl -0x474(%ebp), %eax\n" /* this */
        "jmp .Lf64da_00006c57\n"
        /* } scope */
        /* } scope */
        /* { scope 2: numModes, newContext */
        /* { scope 3: memory, fullscreen, accelerated, depth, ... */
        /* { scope 4: height, depth */
        /* { scope 5: resItem */
        /* { scope 6 */
        ".Lf64da_00006e56:\n"
        "leal -0x434(%ebp), %eax\n" /* line 610 | attrib */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x474(%ebp), %edx\n" /* this */
        "movl %edx, (%esp)\n"
        "calll ZNSt6vectorI8CResInfoSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_\n"
        "jmp .Lf64da_00006c5d\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: numModes, newContext */
        /* { scope 3: memory, fullscreen, accelerated, depth, ... */
        ".Lf64da_00006e77:\n"
        "movl $str_00215920, 4(%esp)\n" /* line 2138 */
        "movl -0x30(%ebp), %eax\n" /* depth */
        "movl %eax, (%esp)\n"
        "calll IOObjectConformsTo\n"
        "testl %eax, %eax\n"
        "jne .Lf64da_00006cd4\n"
        "movl $str_00215a14, 4(%esp)\n" /* line 2144 */
        "movl -0x30(%ebp), %eax\n" /* depth */
        "movl %eax, (%esp)\n"
        "calll IOObjectConformsTo\n"
        "testl %eax, %eax\n"
        "je .Lf64da_0000682e\n"
        "movl %esi, 8(%esp)\n" /* line 2149 | width */
        "movl $str_0021592c, 4(%esp)\n" /* "IODeviceTree" */
        "movl -0x30(%ebp), %eax\n" /* depth */
        "movl %eax, (%esp)\n"
        "calll IORegistryEntryGetParentEntry\n"
        "testl %eax, %eax\n" /* line 2150 */
        "je .Lf64da_00006cd4\n"
        "jmp .Lf64da_0000682e\n"
        "movl %eax, %ebx\n" /* this */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf64da_00006ed3:\n"
        "movl -0x464(%ebp), %edx\n" /* line 2322 | this */
        "movl %edx, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "movl -0x468(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "movl -0x46c(%ebp), %edx\n" /* this */
        "movl %edx, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "movl -0x470(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "movl -0x474(%ebp), %edx\n" /* line 273 | this */
        "movl 4(%edx), %ecx\n" /* __last */
        "movl (%edx), %edx\n"
        "movl %edx, %eax\n"
        /* { scope 1: rendererInfo, numRenderers, modeArrayRef, attrib, ... */
        "cmpl %edx, %ecx\n" /* line 173 */
        "je .Lf64da_00006f23\n"
        ".Lf64da_00006f1c:\n"
        "addl $0x10, %eax\n"
        "cmpl %eax, %ecx\n"
        "jne .Lf64da_00006f1c\n"
        /* } scope */
        ".Lf64da_00006f23:\n"
        "testl %edx, %edx\n" /* line 122 */
        "je .Lf64da_00006f2f\n"
        "movl %edx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf64da_00006f2f:\n"
        "movl %ebx, (%esp)\n" /* line 273 */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n"
        /* { scope 1: rendererInfo, numRenderers, modeArrayRef, attrib, ... */
        /* { scope 2: numModes, newContext */
        "leal -0x434(%ebp), %edx\n" /* line 2317 | attrib */
        "movl %edx, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "jmp .Lf64da_00006ed3\n"
    );
}
#else
short unsigned int CDisplayInfo_CDisplayInfo(const CDisplayInfo * _this, CGDirectDisplayID inDisplayID)
{ return 0; }
#endif

/* overload skip: CDisplayInfo_CDisplayInfo (0x6f4a) */

/* overload skip: CDisplayInfo_CDisplayInfo (0x79ba) */

/* overload skip: CDisplayInfo_CDisplayInfo (0x7c2a) */

/* line 214 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
OSStatus MacDisplay_Initialize(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 214 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1fc, %esp\n"
        /* { scope 1 */
        "leal -0x20(%ebp), %ebx\n" /* line 2401 */
        "movl %ebx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll CGGetActiveDisplayList\n"
        "testl %eax, %eax\n" /* line 2402 */
        "jne .Lf7e9a_00007ecc\n"
        "movl -0x20(%ebp), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf7e9a_00007efd\n"
        ".Lf7e9a_00007ecc:\n"
        "movl 0x334790, %eax\n" /* line 361 */
        "subl sDisplayList, %eax\n" /* line 223 */
        "sarl $2, %eax\n"
        "imull $0xc28f5c29, %eax, %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf7e9a_00007f4a\n"
        "movl $str_00215a24, (%esp)\n" /* line 225 */
        "calll game_dprintf\n"
        "movl $0x3ec, %eax\n"
        /* } scope */
        ".Lf7e9a_00007ef5:\n"
        "leal -0xc(%ebp), %esp\n" /* line 342 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf7e9a_00007efd:\n"
        "shll $2, %eax\n" /* line 2404 */
        "movl %eax, (%esp)\n"
        "calll __Znam\n"
        "movl %eax, -0x1e0(%ebp)\n"
        "movl %ebx, 8(%esp)\n" /* line 2405 */
        "movl %eax, 4(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CGGetActiveDisplayList\n"
        "testl %eax, %eax\n" /* line 2406 */
        "jne .Lf7e9a_00007f30\n"
        "movl -0x20(%ebp), %eax\n" /* line 2408 */
        "testl %eax, %eax\n"
        "jne .Lf7e9a_000081f3\n"
        ".Lf7e9a_00007f30:\n"
        "movl -0x1e0(%ebp), %eax\n" /* line 2425 */
        "testl %eax, %eax\n"
        "je .Lf7e9a_00007ecc\n"
        "movl -0x1e0(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZdaPv\n"
        "jmp .Lf7e9a_00007ecc\n"
        ".Lf7e9a_00007f4a:\n"
        "movl $1, 4(%esp)\n" /* line 231 */
        "movl kFirstTimeKey, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MacPreferences_GetBoolean\n"
        "testb %al, %al\n"
        "je .Lf7e9a_000082e2\n"
        "movl sDisplayIndex, %eax\n" /* line 495 */
        "leal (%eax, %eax, 4), %eax\n" /* line 654 */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "addl sDisplayList, %eax\n"
        "movl (%eax), %eax\n" /* line 234 */
        "movl %eax, sDisplayID\n"
        "leal -0x1b8(%ebp), %edx\n" /* line 235 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CGDisplayBounds\n"
        "subl $4, %esp\n"
        "movl -0x1b8(%ebp), %eax\n"
        "movl %eax, sDisplayRect\n"
        "movl -0x1b4(%ebp), %eax\n"
        "movl %eax, 0x3348f8\n"
        "movl -0x1b0(%ebp), %eax\n"
        "movl %eax, 0x3348fc\n"
        "movl -0x1ac(%ebp), %eax\n"
        "movl %eax, 0x334900\n"
        ".Lf7e9a_00007fc3:\n"
        "movl sDisplayList, %ecx\n" /* line 343 */
        "movl 0x334790, %eax\n" /* line 361 */
        "subl %ecx, %eax\n" /* line 2435 */
        "sarl $2, %eax\n"
        "imull $0xc28f5c29, %eax, %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf7e9a_0000833f\n"
        "testl %eax, %eax\n" /* line 2444 */
        "je .Lf7e9a_00007ff4\n"
        "movl sDisplayIndex, %edx\n"
        "cmpl %edx, %eax\n"
        "ja .Lf7e9a_000083bd\n"
        ".Lf7e9a_00007ff4:\n"
        "movl $0, sDisplayIndex\n" /* line 2446 */
        ".Lf7e9a_00007ffe:\n"
        "movl $BuilderCallback, 0xc(%esp)\n" /* line 2485 */
        "movl $1, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x32e694, (%esp)\n"
        "calll MacBuilder_BuildWindow\n"
        "movl %eax, %esi\n"
        "testl %eax, %eax\n" /* line 2486 */
        "je .Lf7e9a_00008335\n"
        "movl $UserPaneTrackingProc, 0xc(%esp)\n" /* line 2490 */
        "movl $UserPaneDrawProc, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll MacBuilder_SetupUserPaneControl\n"
        "movl $0, 8(%esp)\n" /* line 2499 */
        "movl $4, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll MacBuilder_SetControlEnabled\n"
        "movl $0, 8(%esp)\n" /* line 2507 */
        "movl $5, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll MacBuilder_SetControlVisible\n"
        "movl $0, 8(%esp)\n" /* line 2508 */
        "movl $6, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll MacBuilder_SetControlVisible\n"
        "movl sDisplayIndex, %ebx\n" /* line 2511 */
        "movl %esi, (%esp)\n" /* line 2513 */
        "calll MacBuilder_RunModalWindow\n"
        "movl %eax, %edi\n"
        "cmpl $0x6f6b2020, %eax\n" /* line 2544 */
        "cmovel sDisplayIndex, %ebx\n"
        "movl %ebx, sDisplayIndex\n"
        "movl %esi, (%esp)\n" /* line 2547 */
        "calll MacBuilder_ReleaseWindow\n"
        ".Lf7e9a_000080be:\n"
        "cmpl $0x6f6b2020, %edi\n" /* line 267 */
        "je .Lf7e9a_000080d0\n"
        "movl $0xffffff80, %eax\n" /* line 290 */
        "jmp .Lf7e9a_00007ef5\n"
        ".Lf7e9a_000080d0:\n"
        "movl $4, (%esp)\n" /* line 272 */
        "calll MacTools_SetCursorID\n"
        "movl sDisplayIndex, %eax\n" /* line 495 */
        "leal (%eax, %eax, 4), %eax\n" /* line 654 */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "addl sDisplayList, %eax\n"
        "movl (%eax), %eax\n" /* line 275 */
        "movl %eax, sDisplayID\n"
        "leal -0x1d8(%ebp), %edx\n" /* line 276 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CGDisplayBounds\n"
        "subl $4, %esp\n"
        "movl -0x1d8(%ebp), %eax\n"
        "movl %eax, sDisplayRect\n"
        "movl -0x1d4(%ebp), %eax\n"
        "movl %eax, 0x3348f8\n"
        "movl -0x1d0(%ebp), %eax\n"
        "movl %eax, 0x3348fc\n"
        "movl -0x1cc(%ebp), %eax\n"
        "movl %eax, 0x334900\n"
        ".Lf7e9a_00008138:\n"
        "cmpb $0, sInWindowMode\n" /* line 286 */
        "je .Lf7e9a_0000815b\n"
        "movl sDisplayDepth, %eax\n" /* line 719 */
        "testl %eax, %eax\n"
        "je .Lf7e9a_00008461\n"
        ".Lf7e9a_0000814e:\n"
        "cmpl $0x20, sDisplayDepth\n" /* line 288 */
        "jne .Lf7e9a_00008534\n"
        ".Lf7e9a_0000815b:\n"
        "movl $0, 4(%esp)\n" /* line 297 */
        "movl kFirstTimeKey, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MacPreferences_PutBoolean\n"
        "movl sDisplayIndex, %eax\n" /* line 298 */
        "movl %eax, 4(%esp)\n"
        "movl kDisplayIndexKey, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MacPreferences_PutInteger\n"
        "movl $sDisplayRect, 4(%esp)\n" /* line 299 */
        "movl kDisplayRectKey, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MacPreferences_PutRect\n"
        "movb $1, -0x1a4(%ebp)\n" /* line 320 | title */
        "movb $0x14, -0x1a3(%ebp)\n" /* line 321 */
        "leal -0x1a4(%ebp), %eax\n" /* line 323 | title, theMenu */
        "movl %eax, 4(%esp)\n" /* theMenu */
        "movl $0x80, (%esp)\n"
        "calll NewMenu\n"
        "testl %eax, %eax\n" /* line 324 */
        "je .Lf7e9a_000081d8\n"
        "movl $0, 4(%esp)\n" /* line 326 */
        "movl %eax, (%esp)\n"
        "calll InsertMenu\n"
        "calll InvalMenuBar\n" /* line 327 */
        ".Lf7e9a_000081d8:\n"
        "cmpb $0, sInWindowMode\n" /* line 332 */
        "je .Lf7e9a_000083a4\n"
        ".Lf7e9a_000081e5:\n"
        "movb $1, sInitialized\n" /* line 338 */
        "xorl %eax, %eax\n"
        "jmp .Lf7e9a_00007ef5\n"
        ".Lf7e9a_000081f3:\n"
        "movl -0x1e0(%ebp), %eax\n" /* line 2408 */
        "movl %eax, -0x1dc(%ebp)\n"
        "xorl %edi, %edi\n"
        ".Lf7e9a_00008201:\n"
        "movl (%eax), %ebx\n" /* line 2410 */
        "movl %ebx, 4(%esp)\n" /* line 2412 */
        "leal -0xa4(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll CDisplayInfo_CDisplayInfo\n"
        "cmpb $0, -0x54(%ebp)\n" /* line 2414 */
        "je .Lf7e9a_0000825e\n"
        "testl %edi, %edi\n" /* line 2418 */
        "movl sMainDisplayID, %eax\n"
        "cmovel %ebx, %eax\n"
        "movl %eax, sMainDisplayID\n"
        "movl 0x334790, %eax\n" /* line 604 */
        "cmpl 0x334794, %eax\n"
        "je .Lf7e9a_00008316\n"
        "testl %eax, %eax\n" /* line 104 */
        "je .Lf7e9a_00008256\n"
        "leal -0xa4(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CDisplayInfo_CDisplayInfo\n"
        "movl 0x334790, %eax\n"
        ".Lf7e9a_00008256:\n"
        "addl $0x64, %eax\n" /* line 607 */
        "movl %eax, 0x334790\n"
        ".Lf7e9a_0000825e:\n"
        "movl -0x6c(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %esi\n" /* line 178 */
        "cmpl %esi, %ebx\n" /* line 224 */
        "jne .Lf7e9a_000084d6\n"
        ".Lf7e9a_00008272:\n"
        "movl -0x70(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "cmpl %esi, %ebx\n" /* line 224 */
        "jne .Lf7e9a_000084a7\n"
        ".Lf7e9a_00008280:\n"
        "movl -0x74(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "cmpl %esi, %ebx\n" /* line 224 */
        "jne .Lf7e9a_00008478\n"
        ".Lf7e9a_0000828e:\n"
        "movl -0x84(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "cmpl %esi, %ebx\n" /* line 224 */
        "jne .Lf7e9a_00008505\n"
        ".Lf7e9a_0000829f:\n"
        "movl -0x8c(%ebp), %edx\n" /* line 273 */
        "movl -0x90(%ebp), %ecx\n"
        "movl %ecx, %eax\n"
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf7e9a_000082b8\n"
        ".Lf7e9a_000082b1:\n"
        "addl $0x10, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf7e9a_000082b1\n"
        ".Lf7e9a_000082b8:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf7e9a_000082c4\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf7e9a_000082c4:\n"
        "addl $1, %edi\n" /* line 2408 */
        "addl $4, -0x1dc(%ebp)\n"
        "cmpl -0x20(%ebp), %edi\n"
        "jae .Lf7e9a_00007f30\n"
        "movl -0x1dc(%ebp), %eax\n"
        "jmp .Lf7e9a_00008201\n"
        ".Lf7e9a_000082e2:\n"
        "movl $0, 4(%esp)\n" /* line 239 */
        "movl kDisplayIndexKey, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MacPreferences_GetInteger\n"
        "movl %eax, sDisplayIndex\n"
        "movl $sDisplayRect, 4(%esp)\n" /* line 240 */
        "movl kDisplayRectKey, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MacPreferences_GetRect\n"
        "jmp .Lf7e9a_00007fc3\n"
        ".Lf7e9a_00008316:\n"
        "leal -0xa4(%ebp), %edx\n" /* line 610 */
        "movl %edx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $sDisplayList, (%esp)\n"
        "calll ZNSt6vectorI12CDisplayInfoSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_\n"
        "jmp .Lf7e9a_0000825e\n"
        ".Lf7e9a_00008335:\n"
        "movl $0x6f6b2020, %edi\n" /* line 2486 */
        "jmp .Lf7e9a_000080be\n"
        ".Lf7e9a_0000833f:\n"
        "movl $0, sDisplayIndex\n" /* line 2437 */
        "movl (%ecx), %eax\n" /* line 2438 */
        "movl %eax, sDisplayID\n"
        "leal -0x1c8(%ebp), %edx\n" /* line 2439 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CGDisplayBounds\n"
        "subl $4, %esp\n"
        "movl -0x1c8(%ebp), %eax\n"
        "movl %eax, sDisplayRect\n"
        "movl -0x1c4(%ebp), %eax\n"
        "movl %eax, 0x3348f8\n"
        "movl -0x1c0(%ebp), %eax\n"
        "movl %eax, 0x3348fc\n"
        "movl -0x1bc(%ebp), %eax\n"
        "movl %eax, 0x334900\n"
        ".Lf7e9a_00008391:\n"
        "calll GetCurrentKeyModifiers\n" /* line 265 */
        "testb $1, %ah\n"
        "je .Lf7e9a_00008138\n"
        "jmp .Lf7e9a_00007ffe\n"
        ".Lf7e9a_000083a4:\n"
        "movl $0xc, 4(%esp)\n" /* line 334 */
        "movl $3, (%esp)\n"
        "calll SetSystemUIMode\n"
        "jmp .Lf7e9a_000081e5\n"
        ".Lf7e9a_000083bd:\n"
        "leal (%edx, %edx, 4), %eax\n" /* line 654 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl %eax, -0x1e4(%ebp)\n"
        "movl 4(%eax), %eax\n" /* line 2452 */
        "movl %eax, -0x1e8(%ebp)\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl -0x1e4(%ebp), %edx\n"
        "movl 8(%edx), %ebx\n"
        "movl %ebx, -0x3c(%ebp)\n"
        "movl 0xc(%edx), %esi\n"
        "movl %esi, -0x38(%ebp)\n"
        "movl 0x10(%edx), %edi\n"
        "movl %edi, -0x34(%ebp)\n"
        "movl sDisplayRect, %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl 0x3348f8, %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "movl 0x3348fc, %ecx\n"
        "movl %ecx, -0x28(%ebp)\n"
        "movl 0x334900, %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl -0x1e8(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %ebx, 0x14(%esp)\n"
        "movl %esi, 0x18(%esp)\n"
        "movl %edi, 0x1c(%esp)\n"
        "movl sDisplayRect, %eax\n"
        "movl %eax, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ecx, 8(%esp)\n"
        "movl 0x334900, %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "calll CGRectEqualToRect\n"
        "testl %eax, %eax\n"
        "je .Lf7e9a_00007ffe\n"
        "movl -0x1e4(%ebp), %edx\n" /* line 2457 */
        "movl (%edx), %eax\n"
        "movl %eax, sDisplayID\n"
        "jmp .Lf7e9a_00008391\n"
        ".Lf7e9a_00008461:\n"
        "movl sDisplayID, %eax\n" /* line 721 */
        "movl %eax, (%esp)\n"
        "calll CGDisplayBitsPerPixel\n"
        "movl %eax, sDisplayDepth\n"
        "jmp .Lf7e9a_0000814e\n"
        ".Lf7e9a_00008478:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf7e9a_0000828e\n"
        "leal -0x1b(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf7e9a_0000828e\n"
        ".Lf7e9a_000084a7:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf7e9a_00008280\n"
        "leal -0x1c(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf7e9a_00008280\n"
        ".Lf7e9a_000084d6:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf7e9a_00008272\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf7e9a_00008272\n"
        ".Lf7e9a_00008505:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf7e9a_0000829f\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf7e9a_0000829f\n"
        ".Lf7e9a_00008534:\n"
        "calll MacResources_GetNeeds32BitError\n" /* line 290 */
        "movl $1, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll MacTools_MessageAlert\n"
        "movl $0xffffff80, %eax\n"
        "jmp .Lf7e9a_00007ef5\n"
        "movl %eax, %ebx\n"
        "movl -0x6c(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %esi\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edi\n" /* line 178 */
        "cmpl %edi, %esi\n" /* line 224 */
        "jne .Lf7e9a_000086eb\n"
        ".Lf7e9a_00008569:\n"
        "movl -0x70(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %esi\n"
        "cmpl %esi, %edi\n" /* line 224 */
        "jne .Lf7e9a_000086bc\n"
        ".Lf7e9a_00008577:\n"
        "movl -0x74(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %esi\n"
        "cmpl %esi, %edi\n" /* line 224 */
        "jne .Lf7e9a_00008632\n"
        ".Lf7e9a_00008585:\n"
        "movl -0x84(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %esi\n"
        "cmpl %esi, %edi\n" /* line 224 */
        "jne .Lf7e9a_00008603\n"
        ".Lf7e9a_00008592:\n"
        "movl -0x8c(%ebp), %edx\n" /* line 273 */
        "movl -0x90(%ebp), %ecx\n"
        "movl %ecx, %eax\n"
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf7e9a_000085ab\n"
        ".Lf7e9a_000085a4:\n"
        "addl $0x10, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf7e9a_000085a4\n"
        ".Lf7e9a_000085ab:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf7e9a_000085b7\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf7e9a_000085b7:\n"
        "movl %ebx, (%esp)\n" /* line 273 */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n"
        ".Lf7e9a_000085c1:\n"
        "movl -0x74(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %edi\n"
        "cmpl %esi, %edi\n" /* line 224 */
        "jne .Lf7e9a_000087fb\n"
        ".Lf7e9a_000085cf:\n"
        "movl -0x84(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %edi\n"
        "cmpl %esi, %edi\n" /* line 224 */
        "jne .Lf7e9a_000087cc\n"
        ".Lf7e9a_000085e0:\n"
        "movl -0x8c(%ebp), %edx\n" /* line 273 */
        "movl -0x90(%ebp), %ecx\n"
        "movl %ecx, %eax\n"
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf7e9a_000085ab\n"
        ".Lf7e9a_000085f2:\n"
        "addl $0x10, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf7e9a_000085f2\n"
        "jmp .Lf7e9a_000085ab\n"
        "movl %eax, %ebx\n"
        "jmp .Lf7e9a_000085cf\n"
        "movl %eax, %ebx\n"
        "jmp .Lf7e9a_000085e0\n"
        ".Lf7e9a_00008603:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf7e9a_00008592\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf7e9a_00008592\n"
        ".Lf7e9a_00008632:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf7e9a_00008585\n"
        "leal -0x1b(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf7e9a_00008585\n"
        "movl %eax, %ebx\n"
        ".Lf7e9a_00008663:\n"
        "movl -0x8c(%ebp), %edx\n" /* line 273 */
        "movl -0x90(%ebp), %ecx\n"
        "movl %ecx, %eax\n"
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf7e9a_000085ab\n"
        ".Lf7e9a_00008679:\n"
        "addl $0x10, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf7e9a_00008679\n"
        "jmp .Lf7e9a_000085ab\n"
        "movl %eax, %ebx\n"
        ".Lf7e9a_00008687:\n"
        "movl -0x84(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %esi\n"
        "cmpl %esi, %edi\n" /* line 224 */
        "je .Lf7e9a_00008663\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf7e9a_00008663\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf7e9a_00008663\n"
        ".Lf7e9a_000086bc:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf7e9a_00008577\n"
        "leal -0x1c(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf7e9a_00008577\n"
        ".Lf7e9a_000086eb:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf7e9a_00008569\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf7e9a_00008569\n"
        "movl %eax, %ebx\n"
        ".Lf7e9a_0000871c:\n"
        "movl -0x74(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %esi\n"
        "cmpl %esi, %edi\n" /* line 224 */
        "je .Lf7e9a_00008687\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf7e9a_00008687\n"
        "leal -0x1b(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf7e9a_00008687\n"
        "movl %eax, %ebx\n"
        "movl -0x70(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %esi\n"
        "cmpl %esi, %edi\n" /* line 224 */
        "je .Lf7e9a_0000871c\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf7e9a_0000871c\n"
        "leal -0x1c(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf7e9a_0000871c\n"
        "movl %eax, %ebx\n"
        "movl -0x70(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %edi\n"
        "cmpl %esi, %edi\n" /* line 224 */
        "je .Lf7e9a_000085c1\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf7e9a_000085c1\n"
        "leal -0x1c(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf7e9a_000085c1\n"
        ".Lf7e9a_000087cc:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf7e9a_000085e0\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf7e9a_000085e0\n"
        ".Lf7e9a_000087fb:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf7e9a_000085cf\n"
        "leal -0x1b(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf7e9a_000085cf\n"
    );
}
#else
OSStatus MacDisplay_Initialize(void)
{ return 0; }
#endif

/* line 2923 */
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
short unsigned int __static_initialization_and_destruction_0(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2923 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "cmpl $0xffff, %edx\n" /* line 191 */
        "je .Lf882a_00008843\n"
        ".Lf882a_0000883b:\n"
        "addl $0x3c, %esp\n" /* line 2923 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf882a_00008843:\n"
        "cmpl $1, %eax\n" /* line 191 */
        "je .Lf882a_0000890e\n"
        "testl %eax, %eax\n" /* line 2665 */
        "jne .Lf882a_0000883b\n"
        "movl 0x334784, %edx\n" /* line 273 */
        "movl sRectList, %ecx\n"
        "movl %ecx, %eax\n"
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf882a_00008869\n"
        ".Lf882a_00008862:\n"
        "addl $8, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf882a_00008862\n"
        ".Lf882a_00008869:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf882a_00008875\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf882a_00008875:\n"
        "movl 0x334790, %eax\n" /* line 273 */
        "movl %eax, -0x38(%ebp)\n"
        "movl sDisplayList, %eax\n"
        "movl %eax, %ebx\n"
        "cmpl %eax, -0x38(%ebp)\n" /* line 173 */
        "je .Lf882a_000088f6\n"
        ".Lf882a_00008889:\n"
        "movl 0x38(%ebx), %eax\n" /* line 269 */
        "leal -0xc(%eax), %esi\n" /* line 277 */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edi\n" /* line 178 */
        "cmpl %edi, %esi\n" /* line 224 */
        "jne .Lf882a_00008981\n"
        ".Lf882a_0000889d:\n"
        "movl 0x34(%ebx), %eax\n" /* line 269 */
        "leal -0xc(%eax), %esi\n" /* line 277 */
        "cmpl %edi, %esi\n" /* line 224 */
        "jne .Lf882a_000089b0\n"
        ".Lf882a_000088ab:\n"
        "movl 0x30(%ebx), %eax\n" /* line 269 */
        "leal -0xc(%eax), %esi\n" /* line 277 */
        "cmpl %edi, %esi\n" /* line 224 */
        "jne .Lf882a_000089df\n"
        ".Lf882a_000088b9:\n"
        "movl 0x20(%ebx), %eax\n" /* line 269 */
        "leal -0xc(%eax), %esi\n" /* line 277 */
        "cmpl %esi, %edi\n" /* line 224 */
        "jne .Lf882a_00008952\n"
        ".Lf882a_000088c7:\n"
        "leal 0x14(%ebx), %ecx\n" /* line 135 */
        "movl 4(%ecx), %edx\n" /* line 273 */
        "movl 0x14(%ebx), %eax\n"
        "cmpl %eax, %edx\n" /* line 173 */
        "je .Lf882a_000088db\n"
        ".Lf882a_000088d4:\n"
        "addl $0x10, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf882a_000088d4\n"
        ".Lf882a_000088db:\n"
        "movl (%ecx), %eax\n" /* line 109 */
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf882a_000088e9\n"
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf882a_000088e9:\n"
        "addl $0x64, %ebx\n" /* line 173 */
        "cmpl %ebx, -0x38(%ebp)\n"
        "jne .Lf882a_00008889\n"
        "movl sDisplayList, %eax\n"
        ".Lf882a_000088f6:\n"
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf882a_0000883b\n"
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        "addl $0x3c, %esp\n" /* line 2923 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf882a_0000890e:\n"
        "movl $0, sDisplayList\n" /* line 85 */
        "movl $0, 0x334790\n"
        "movl $0, 0x334794\n"
        "movl $0, sRectList\n"
        "movl $0, 0x334784\n"
        "movl $0, 0x334788\n"
        "addl $0x3c, %esp\n" /* line 2923 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf882a_00008952:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf882a_000088c7\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf882a_000088c7\n"
        ".Lf882a_00008981:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf882a_0000889d\n"
        "leal -0x1c(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf882a_0000889d\n"
        ".Lf882a_000089b0:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf882a_000088ab\n"
        "leal -0x1b(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf882a_000088ab\n"
        ".Lf882a_000089df:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf882a_000088b9\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf882a_000088b9\n"
        "movl %eax, %esi\n"
        ".Lf882a_00008a10:\n"
        "leal 0x14(%ebx), %ecx\n" /* line 135 */
        "movl 4(%ecx), %edx\n" /* line 273 */
        "movl 0x14(%ebx), %eax\n"
        "cmpl %eax, %edx\n" /* line 173 */
        "je .Lf882a_00008a24\n"
        ".Lf882a_00008a1d:\n"
        "addl $0x10, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf882a_00008a1d\n"
        ".Lf882a_00008a24:\n"
        "movl (%ecx), %eax\n" /* line 109 */
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf882a_00008a32\n"
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf882a_00008a32:\n"
        "movl sDisplayList, %eax\n" /* line 109 */
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf882a_00008a43\n"
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf882a_00008a43:\n"
        "movl %esi, (%esp)\n" /* line 109 */
        "calll __Unwind_Resume\n"
        "movl %eax, %esi\n"
        ".Lf882a_00008a4d:\n"
        "movl 0x20(%ebx), %eax\n" /* line 269 */
        "leal -0xc(%eax), %edx\n" /* line 277 */
        "movl %edx, -0x30(%ebp)\n"
        "cmpl %edi, %edx\n" /* line 224 */
        "je .Lf882a_00008a10\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf882a_00008a10\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf882a_00008a10\n"
        "movl %eax, %esi\n"
        "movl 0x34(%ebx), %eax\n" /* line 269 */
        "leal -0xc(%eax), %edx\n" /* line 277 */
        "movl %edx, -0x2c(%ebp)\n"
        "cmpl %edi, %edx\n" /* line 224 */
        "jne .Lf882a_00008ad0\n"
        ".Lf882a_00008a94:\n"
        "movl 0x30(%ebx), %eax\n" /* line 269 */
        "leal -0xc(%eax), %edx\n" /* line 277 */
        "movl %edx, -0x34(%ebp)\n"
        "cmpl %edi, %edx\n" /* line 224 */
        "je .Lf882a_00008a4d\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf882a_00008a4d\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf882a_00008a4d\n"
        "movl %eax, %esi\n"
        "jmp .Lf882a_00008a94\n"
        ".Lf882a_00008ad0:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf882a_00008a94\n"
        "leal -0x1b(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf882a_00008a94\n"
    );
}
#else
static short unsigned int __static_initialization_and_destruction_0(void)
{ return 0; }
#endif

/* line 2925 */
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
void GLOBAL__D__ZN10MacDisplay10InitializeEv(void) /* global destructors keyed to MacDisplay_Initialize */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2925 */
        "movl %esp, %ebp\n"
        "movl $0xffff, %edx\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "jmp __static_initialization_and_destruction_0\n"
    );
}
#else
static void GLOBAL__D__ZN10MacDisplay10InitializeEv(void) /* global destructors keyed to MacDisplay_Initialize */
{ }
#endif

/* line 2924 */
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
void GLOBAL__I__ZN10MacDisplay10InitializeEv(void) /* global constructors keyed to MacDisplay_Initialize */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2924 */
        "movl %esp, %ebp\n"
        "movl $0xffff, %edx\n"
        "movl $1, %eax\n"
        "popl %ebp\n"
        "jmp __static_initialization_and_destruction_0\n"
    );
}
#else
static void GLOBAL__I__ZN10MacDisplay10InitializeEv(void) /* global constructors keyed to MacDisplay_Initialize */
{ }
#endif

/* line 118 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void ZSt11__push_heapIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEiS2_EvT_T0_S9_T1_(void) /* void std___push_heap<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > >, int, CResInfo> */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 118 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %edi\n" /* __first */
        "movl 0xc(%ebp), %ebx\n" /* __holeIndex */
        "movl 0x20(%ebp), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0x1c(%ebp), %edx\n"
        "movl %edx, -0x18(%ebp)\n"
        "movl 0x18(%ebp), %eax\n"
        "movl %eax, -0x14(%ebp)\n"
        "movl 0x14(%ebp), %edx\n" /* __value */
        "movl %edx, -0x10(%ebp)\n"
        /* { scope 1 */
        "leal -1(%ebx), %edx\n" /* line 120 | __holeIndex */
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "leal (%eax, %edx), %esi\n" /* __parent */
        "sarl $1, %esi\n" /* __parent */
        "cmpl 0x10(%ebp), %ebx\n" /* line 121 | __topIndex, __holeIndex */
        "jle .Lf2ba718_002ba762\n"
        ".Lf2ba718_002ba751:\n"
        "movl %esi, %eax\n" /* line 654 | __parent */
        "shll $4, %eax\n"
        "leal (%edi, %eax), %ecx\n" /* __first */
        "movl (%ecx), %eax\n" /* line 1938 */
        "cmpl %eax, -0x10(%ebp)\n"
        "jg .Lf2ba718_002ba7a3\n"
        "je .Lf2ba718_002ba787\n" /* line 1942 */
        ".Lf2ba718_002ba762:\n"
        "shll $4, %ebx\n" /* line 121 | __holeIndex */
        "leal (%edi, %ebx), %ecx\n" /* __first */
        ".Lf2ba718_002ba768:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 127 */
        "movl %eax, 0xc(%ecx)\n"
        "movl -0x18(%ebp), %edx\n"
        "movl %edx, 8(%ecx)\n"
        "movl -0x14(%ebp), %eax\n"
        "movl %eax, 4(%ecx)\n"
        "movl -0x10(%ebp), %edx\n"
        "movl %edx, (%ecx)\n"
        /* } scope */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2ba718_002ba787:\n"
        "movl -0x14(%ebp), %edx\n" /* line 1944 */
        "cmpl 4(%ecx), %edx\n"
        "jg .Lf2ba718_002ba7a3\n"
        "jne .Lf2ba718_002ba762\n" /* line 1948 */
        "movl -0x18(%ebp), %edx\n" /* line 1950 */
        "cmpl 8(%ecx), %edx\n"
        "jg .Lf2ba718_002ba7a3\n"
        "jne .Lf2ba718_002ba762\n" /* line 1954 */
        "movl -0x1c(%ebp), %edx\n" /* line 121 */
        "cmpl 0xc(%ecx), %edx\n"
        "jle .Lf2ba718_002ba762\n"
        ".Lf2ba718_002ba7a3:\n"
        "shll $4, %ebx\n" /* line 654 | __holeIndex */
        "leal (%edi, %ebx), %edx\n" /* __first */
        "movl %eax, (%edx)\n" /* line 123 */
        "movl 4(%ecx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%ecx), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "leal -1(%esi), %edx\n" /* line 125 | __parent */
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "cmpl 0x10(%ebp), %esi\n" /* line 121 | __topIndex, __parent */
        "jle .Lf2ba718_002ba768\n"
        "movl %esi, %ebx\n" /* __parent, __holeIndex */
        "movl %eax, %esi\n" /* __parent */
        "jmp .Lf2ba718_002ba751\n"
    );
}
#else
void ZSt11__push_heapIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEiS2_EvT_T0_S9_T1_(void) /* void std___push_heap<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > >, int, CResInfo> */
{ }
#endif

/* line 210 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEiS2_EvT_T0_S9_T1_(void) /* void std___adjust_heap<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > >, int, CResInfo> */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 210 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %eax\n" /* __first */
        "movl %eax, -0x30(%ebp)\n" /* __first */
        "movl 0xc(%ebp), %edx\n" /* __holeIndex */
        "movl %edx, -0x34(%ebp)\n" /* __holeIndex */
        "movl 0x10(%ebp), %ecx\n" /* __len */
        "movl %ecx, -0x38(%ebp)\n" /* __len */
        "movl 0x20(%ebp), %ebx\n"
        "movl %ebx, -0x20(%ebp)\n"
        "movl 0x1c(%ebp), %edi\n"
        "movl %edi, -0x24(%ebp)\n"
        "movl 0x18(%ebp), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl 0x14(%ebp), %edx\n" /* __value */
        "movl %edx, -0x2c(%ebp)\n"
        /* { scope 1 */
        "movl -0x34(%ebp), %ecx\n" /* line 213 | __holeIndex */
        "leal 2(%ecx, %ecx), %ebx\n" /* __secondChild */
        "cmpl -0x38(%ebp), %ebx\n" /* line 214 | __len, __secondChild */
        "jl .Lf2ba7d8_002ba888\n"
        "movl %ecx, %eax\n"
        ".Lf2ba7d8_002ba819:\n"
        "cmpl %ebx, -0x38(%ebp)\n" /* line 222 | __secondChild, __len */
        "jne .Lf2ba7d8_002ba849\n"
        "shll $4, %eax\n" /* line 654 */
        "movl -0x30(%ebp), %edi\n" /* __first */
        "leal (%eax, %edi), %ecx\n"
        "subl $1, %ebx\n" /* line 224 | __secondChild */
        "movl %ebx, %edx\n" /* line 654 | __secondChild */
        "shll $4, %edx\n"
        "addl %edi, %edx\n"
        "movl (%edx), %eax\n" /* line 224 */
        "movl %eax, (%ecx)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%ecx)\n"
        "movl %ebx, %eax\n" /* __secondChild */
        ".Lf2ba7d8_002ba849:\n"
        "movl -0x20(%ebp), %edx\n" /* line 227 */
        "movl %edx, -0x10(%ebp)\n"
        "movl -0x24(%ebp), %ecx\n"
        "movl %ecx, -0x14(%ebp)\n"
        "movl -0x28(%ebp), %ebx\n" /* __secondChild */
        "movl %ebx, -0x18(%ebp)\n" /* __secondChild */
        "movl -0x2c(%ebp), %edi\n"
        "movl %edi, -0x1c(%ebp)\n"
        "movl %edi, 0x14(%ebp)\n" /* __value */
        "movl %ebx, 0x18(%ebp)\n" /* __secondChild */
        "movl %ecx, 0x1c(%ebp)\n"
        "movl %edx, 0x20(%ebp)\n"
        "movl -0x34(%ebp), %edx\n" /* __holeIndex */
        "movl %edx, 0x10(%ebp)\n" /* __len */
        "movl %eax, 0xc(%ebp)\n" /* __holeIndex */
        "movl -0x30(%ebp), %ecx\n" /* __first */
        "movl %ecx, 8(%ebp)\n" /* __first */
        /* } scope */
        "addl $0x30, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp ZSt11__push_heapIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEiS2_EvT_T0_S9_T1_\n"
        ".Lf2ba7d8_002ba888:\n"
        "movl %ecx, %edx\n"
        "leal -1(%ebx), %edi\n" /* line 654 | __secondChild */
        "movl %edi, -0x3c(%ebp)\n"
        "movl %edi, %eax\n"
        "shll $4, %eax\n"
        "movl -0x30(%ebp), %ecx\n" /* __first */
        "leal (%eax, %ecx), %esi\n"
        "movl %ebx, %eax\n" /* __secondChild */
        "shll $4, %eax\n"
        "leal (%eax, %ecx), %ecx\n"
        "movl (%ecx), %edi\n" /* line 1938 */
        "cmpl (%esi), %edi\n"
        "jl .Lf2ba7d8_002ba8f5\n"
        ".Lf2ba7d8_002ba8a9:\n"
        "je .Lf2ba7d8_002ba92f\n" /* line 1942 */
        ".Lf2ba7d8_002ba8af:\n"
        "movl %ebx, %esi\n" /* line 216 | __secondChild */
        "shll $4, %edx\n" /* line 654 */
        "addl -0x30(%ebp), %edx\n" /* __first */
        "movl %edi, (%edx)\n" /* line 218 */
        "movl 4(%ecx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%ecx), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "leal 2(%esi, %esi), %ebx\n" /* line 220 | __secondChild */
        "cmpl %ebx, -0x38(%ebp)\n" /* line 214 | __secondChild, __len */
        "jle .Lf2ba7d8_002ba928\n"
        ".Lf2ba7d8_002ba8d4:\n"
        "movl %esi, %edx\n"
        "leal -1(%ebx), %edi\n" /* line 654 | __secondChild */
        "movl %edi, -0x3c(%ebp)\n"
        "movl %edi, %eax\n"
        "shll $4, %eax\n"
        "movl -0x30(%ebp), %ecx\n" /* __first */
        "leal (%eax, %ecx), %esi\n"
        "movl %ebx, %eax\n" /* __secondChild */
        "shll $4, %eax\n"
        "leal (%eax, %ecx), %ecx\n"
        "movl (%ecx), %edi\n" /* line 1938 */
        "cmpl (%esi), %edi\n"
        "jge .Lf2ba7d8_002ba8a9\n"
        ".Lf2ba7d8_002ba8f5:\n"
        "movl -0x3c(%ebp), %esi\n" /* line 217 */
        "movl %esi, %eax\n"
        "shll $4, %eax\n"
        "movl -0x30(%ebp), %ebx\n" /* __first, __secondChild */
        "leal (%eax, %ebx), %ecx\n"
        "movl (%ecx), %edi\n"
        "shll $4, %edx\n" /* line 654 */
        "addl -0x30(%ebp), %edx\n" /* __first */
        "movl %edi, (%edx)\n" /* line 218 */
        "movl 4(%ecx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%ecx), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "leal 2(%esi, %esi), %ebx\n" /* line 220 | __secondChild */
        "cmpl %ebx, -0x38(%ebp)\n" /* line 214 | __secondChild, __len */
        "jg .Lf2ba7d8_002ba8d4\n"
        ".Lf2ba7d8_002ba928:\n"
        "movl %esi, %eax\n"
        "jmp .Lf2ba7d8_002ba819\n"
        ".Lf2ba7d8_002ba92f:\n"
        "movl 4(%esi), %eax\n" /* line 1944 */
        "cmpl %eax, 4(%ecx)\n"
        "jl .Lf2ba7d8_002ba8f5\n"
        "jne .Lf2ba7d8_002ba8af\n" /* line 1948 */
        "movl 8(%esi), %eax\n" /* line 1950 */
        "cmpl %eax, 8(%ecx)\n"
        "jl .Lf2ba7d8_002ba8f5\n"
        "jne .Lf2ba7d8_002ba8af\n" /* line 1954 */
        "movl 0xc(%ecx), %eax\n"
        "cmpl 0xc(%esi), %eax\n" /* line 216 */
        "jl .Lf2ba7d8_002ba8f5\n"
        "jmp .Lf2ba7d8_002ba8af\n"
    );
}
#else
void ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEiS2_EvT_T0_S9_T1_(void) /* void std___adjust_heap<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > >, int, CResInfo> */
{ }
#endif

/* line 2083 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void ZSt25__unguarded_linear_insertIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEES2_EvT_T0_(void) /* void std___unguarded_linear_insert<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > >, CResInfo> */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2083 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $8, %esp\n"
        "movl 8(%ebp), %ecx\n" /* __last */
        "movl 0x18(%ebp), %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "movl 0x14(%ebp), %edi\n"
        "movl %edi, -0x14(%ebp)\n"
        "movl 0x10(%ebp), %esi\n"
        "movl 0xc(%ebp), %ebx\n" /* __val */
        "leal -0x10(%ecx), %edx\n" /* line 635 */
        ".Lf2ba958_002ba979:\n"
        "movl (%edx), %eax\n" /* line 1938 */
        "cmpl %ebx, %eax\n"
        "jg .Lf2ba958_002ba9a9\n"
        "je .Lf2ba958_002ba99a\n" /* line 1942 */
        ".Lf2ba958_002ba981:\n"
        "movl -0x10(%ebp), %eax\n"
        ".Lf2ba958_002ba984:\n"
        "movl %eax, 0xc(%ecx)\n" /* line 2093 */
        "movl -0x14(%ebp), %edi\n"
        "movl %edi, 8(%ecx)\n"
        "movl %esi, 4(%ecx)\n"
        "movl %ebx, (%ecx)\n"
        "addl $8, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2ba958_002ba99a:\n"
        "cmpl 4(%edx), %esi\n" /* line 1944 */
        "jl .Lf2ba958_002ba9a9\n"
        "jne .Lf2ba958_002ba981\n" /* line 1948 */
        "movl -0x14(%ebp), %edi\n" /* line 1950 */
        "cmpl %edi, 8(%edx)\n"
        "jle .Lf2ba958_002ba9c4\n"
        ".Lf2ba958_002ba9a9:\n"
        "movl %eax, (%ecx)\n" /* line 2089 */
        "movl 4(%edx), %eax\n"
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%ecx)\n"
        "movl %edx, %ecx\n" /* line 635 */
        "subl $0x10, %edx\n"
        "jmp .Lf2ba958_002ba979\n"
        ".Lf2ba958_002ba9c4:\n"
        "jne .Lf2ba958_002ba981\n" /* line 1954 */
        "movl -0x10(%ebp), %edi\n" /* line 2087 */
        "cmpl 0xc(%edx), %edi\n"
        "jl .Lf2ba958_002ba9a9\n"
        "movl %edi, %eax\n"
        "jmp .Lf2ba958_002ba984\n"
    );
}
#else
void ZSt25__unguarded_linear_insertIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEES2_EvT_T0_(void) /* void std___unguarded_linear_insert<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > >, CResInfo> */
{ }
#endif

/* line 344 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void ZSt9make_heapIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEEvT_S8_(void) /* void std_make_heap<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > > > */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 344 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 759 | __first */
        "subl %eax, 0xc(%ebp)\n" /* __last */
        "sarl $4, 0xc(%ebp)\n" /* __last */
        "cmpl $1, 0xc(%ebp)\n" /* line 357 | __last */
        "jle .Lf2ba9d2_002baa5d\n"
        "movl 0xc(%ebp), %eax\n" /* line 344 | __last */
        "subl $2, %eax\n"
        "movl %eax, %edx\n"
        "shrl $0x1f, %edx\n"
        "leal (%edx, %eax), %edi\n"
        "sarl $1, %edi\n"
        "movl %edi, %eax\n"
        "shll $4, %eax\n"
        "movl 8(%ebp), %edx\n" /* __first */
        "leal (%eax, %edx), %esi\n"
        "movl $0, -0x2c(%ebp)\n"
        "jmp .Lf2ba9d2_002baa13\n"
        ".Lf2ba9d2_002baa0f:\n"
        "addl $1, -0x2c(%ebp)\n" /* line 367 */
        ".Lf2ba9d2_002baa13:\n"
        "movl (%esi), %ebx\n" /* line 364 */
        "movl %ebx, -0x28(%ebp)\n"
        "movl 4(%esi), %ecx\n"
        "movl %ecx, -0x24(%ebp)\n"
        "movl 8(%esi), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl 0xc(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %ebx, 0xc(%esp)\n"
        "movl %ecx, 0x10(%esp)\n"
        "movl %edx, 0x14(%esp)\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* __last */
        "movl %eax, 8(%esp)\n"
        "movl %edi, %eax\n"
        "subl -0x2c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* __first */
        "movl %edx, (%esp)\n"
        "calll ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEiS2_EvT_T0_S9_T1_\n"
        "subl $0x10, %esi\n"
        "cmpl -0x2c(%ebp), %edi\n" /* line 366 */
        "jne .Lf2ba9d2_002baa0f\n"
        /* } scope */
        ".Lf2ba9d2_002baa5d:\n"
        "addl $0x4c, %esp\n" /* line 368 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
void ZSt9make_heapIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEEvT_S8_(void) /* void std_make_heap<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > > > */
{ }
#endif

/* line 2027 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void ZSt21__unguarded_partitionIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEES2_ET_S8_S8_T0_(void) /* __gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > > std___unguarded_partition<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > >, CResInfo> */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2027 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edi\n" /* __first */
        "movl 0x1c(%ebp), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0x18(%ebp), %edx\n"
        "movl %edx, -0x18(%ebp)\n"
        "movl 0x14(%ebp), %eax\n"
        "movl %eax, -0x14(%ebp)\n"
        "movl 0x10(%ebp), %edx\n" /* __pivot */
        "movl %edx, -0x10(%ebp)\n"
        "movl 0xc(%ebp), %esi\n" /* __last */
        ".Lf2baa66_002baa8d:\n"
        "movl (%edi), %eax\n" /* line 1938 */
        "movl %eax, -0x20(%ebp)\n"
        "cmpl %eax, -0x10(%ebp)\n"
        "jg .Lf2baa66_002baae5\n"
        ".Lf2baa66_002baa97:\n"
        "je .Lf2baa66_002bab08\n" /* line 1942 */
        ".Lf2baa66_002baa99:\n"
        "subl $0x10, %esi\n" /* line 635 */
        "movl (%esi), %eax\n" /* line 1938 */
        "cmpl %eax, -0x10(%ebp)\n"
        "jl .Lf2baa66_002baa99\n"
        "je .Lf2baa66_002baaea\n" /* line 1942 */
        ".Lf2baa66_002baaa5:\n"
        "cmpl %edi, %esi\n" /* line 2036 */
        "jbe .Lf2baa66_002bab34\n"
        "movl 0xc(%edi), %edx\n" /* line 97 */
        "movl 8(%edi), %ecx\n"
        "movl 4(%edi), %ebx\n"
        /* { scope 1 */
        "movl %eax, (%edi)\n" /* line 98 */
        "movl 4(%esi), %eax\n"
        "movl %eax, 4(%edi)\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, 8(%edi)\n"
        "movl 0xc(%esi), %eax\n"
        "movl %eax, 0xc(%edi)\n"
        "movl %edx, 0xc(%esi)\n" /* line 99 */
        "movl %ecx, 8(%esi)\n"
        "movl %ebx, 4(%esi)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, (%esi)\n"
        /* } scope */
        "addl $0x10, %edi\n" /* line 623 */
        "movl (%edi), %eax\n" /* line 1938 */
        "movl %eax, -0x20(%ebp)\n"
        "cmpl %eax, -0x10(%ebp)\n"
        "jle .Lf2baa66_002baa97\n"
        ".Lf2baa66_002baae5:\n"
        "addl $0x10, %edi\n" /* line 623 */
        "jmp .Lf2baa66_002baa8d\n"
        ".Lf2baa66_002baaea:\n"
        "movl -0x14(%ebp), %edx\n" /* line 1944 */
        "cmpl 4(%esi), %edx\n"
        "jl .Lf2baa66_002baa99\n"
        "jne .Lf2baa66_002baaa5\n" /* line 1948 */
        "movl -0x18(%ebp), %edx\n" /* line 1950 */
        "cmpl 8(%esi), %edx\n"
        "jl .Lf2baa66_002baa99\n"
        "jne .Lf2baa66_002baaa5\n" /* line 1954 */
        "movl -0x1c(%ebp), %edx\n" /* line 2034 */
        "cmpl 0xc(%esi), %edx\n"
        "jl .Lf2baa66_002baa99\n"
        "jmp .Lf2baa66_002baaa5\n"
        ".Lf2baa66_002bab08:\n"
        "movl -0x14(%ebp), %edx\n" /* line 1944 */
        "cmpl 4(%edi), %edx\n"
        "jg .Lf2baa66_002baae5\n"
        "jne .Lf2baa66_002baa99\n" /* line 1948 */
        "movl -0x18(%ebp), %eax\n" /* line 1950 */
        "cmpl 8(%edi), %eax\n"
        "jg .Lf2baa66_002baae5\n"
        "jne .Lf2baa66_002baa99\n" /* line 1954 */
        "movl -0x1c(%ebp), %edx\n" /* line 2031 */
        "cmpl 0xc(%edi), %edx\n"
        "jle .Lf2baa66_002baa99\n"
        "addl $0x10, %edi\n" /* line 623 */
        "jmp .Lf2baa66_002baa8d\n"
        ".Lf2baa66_002bab34:\n"
        "movl %edi, %eax\n" /* line 2039 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
void ZSt21__unguarded_partitionIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEES2_ET_S8_S8_T0_(void) /* __gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > > std___unguarded_partition<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > >, CResInfo> */
{ }
#endif

/* line 2125 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEEvT_S8_(void) /* void std___insertion_sort<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > > > */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2125 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %eax\n" /* __first */
        "movl %eax, -0x3c(%ebp)\n"
        "movl 0xc(%ebp), %edx\n" /* line 2127 | __last */
        "cmpl %edx, %eax\n"
        "je .Lf2bab3e_002bac42\n"
        "movl %eax, %ebx\n" /* line 2130 */
        "addl $0x10, %ebx\n"
        "cmpl %ebx, %edx\n"
        "je .Lf2bab3e_002bac42\n"
        "movl %ebx, %edi\n"
        "movl 0xc(%edi), %eax\n" /* line 2133 */
        "movl %eax, -0x38(%ebp)\n"
        "movl 8(%edi), %edx\n"
        "movl %edx, -0x34(%ebp)\n"
        "movl 4(%edi), %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl (%edi), %edi\n"
        "movl %edi, -0x2c(%ebp)\n"
        "movl -0x3c(%ebp), %edx\n" /* line 1938 */
        "cmpl (%edx), %edi\n"
        "jl .Lf2bab3e_002babe9\n"
        ".Lf2bab3e_002bab85:\n"
        "je .Lf2bab3e_002bac4a\n" /* line 1942 */
        ".Lf2bab3e_002bab8b:\n"
        "movl -0x38(%ebp), %edx\n"
        /* { scope 1 */
        ".Lf2bab3e_002bab8e:\n"
        "movl %edx, -0x1c(%ebp)\n" /* line 2140 */
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl -0x30(%ebp), %edx\n"
        "movl %edx, -0x24(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        /* } scope */
        "movl %eax, 4(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll ZSt25__unguarded_linear_insertIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEES2_EvT_T0_\n"
        "leal 0x10(%ebx), %edi\n"
        "cmpl %edi, 0xc(%ebp)\n" /* line 2130 | __last */
        "je .Lf2bab3e_002bac42\n"
        ".Lf2bab3e_002babc9:\n"
        "movl %edi, %ebx\n"
        "movl 0xc(%edi), %eax\n" /* line 2133 */
        "movl %eax, -0x38(%ebp)\n"
        "movl 8(%edi), %edx\n"
        "movl %edx, -0x34(%ebp)\n"
        "movl 4(%edi), %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl (%edi), %edi\n"
        "movl %edi, -0x2c(%ebp)\n"
        "movl -0x3c(%ebp), %edx\n" /* line 1938 */
        "cmpl (%edx), %edi\n"
        "jge .Lf2bab3e_002bab85\n"
        ".Lf2bab3e_002babe9:\n"
        "leal 0x10(%ebx), %edi\n" /* line 654 */
        "movl %ebx, %esi\n" /* line 411 */
        "subl -0x3c(%ebp), %esi\n"
        "sarl $4, %esi\n"
        "testl %esi, %esi\n"
        "jle .Lf2bab3e_002bac23\n"
        "movl %ebx, %ecx\n"
        "movl %edi, %edx\n"
        "xorl %ebx, %ebx\n"
        ".Lf2bab3e_002babfe:\n"
        "movl -0x10(%ecx), %eax\n" /* line 412 */
        "movl %eax, -0x10(%edx)\n"
        "movl -0xc(%ecx), %eax\n"
        "movl %eax, -0xc(%edx)\n"
        "movl -8(%ecx), %eax\n"
        "movl %eax, -8(%edx)\n"
        "movl -4(%ecx), %eax\n"
        "movl %eax, -4(%edx)\n"
        "addl $1, %ebx\n"
        "subl $0x10, %ecx\n"
        "subl $0x10, %edx\n"
        "cmpl %ebx, %esi\n" /* line 411 */
        "jne .Lf2bab3e_002babfe\n"
        ".Lf2bab3e_002bac23:\n"
        "movl -0x38(%ebp), %eax\n" /* line 2137 */
        "movl -0x3c(%ebp), %edx\n"
        "movl %eax, 0xc(%edx)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%edx)\n"
        "cmpl %edi, 0xc(%ebp)\n" /* line 2130 | __last */
        "jne .Lf2bab3e_002babc9\n"
        ".Lf2bab3e_002bac42:\n"
        "addl $0x5c, %esp\n" /* line 2140 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2bab3e_002bac4a:\n"
        "movl -0x30(%ebp), %eax\n" /* line 1944 */
        "cmpl 4(%edx), %eax\n"
        "jl .Lf2bab3e_002babe9\n"
        "jne .Lf2bab3e_002bab8b\n" /* line 1948 */
        "movl -0x34(%ebp), %eax\n" /* line 1950 */
        "cmpl 8(%edx), %eax\n"
        "jl .Lf2bab3e_002babe9\n"
        "jne .Lf2bab3e_002bab8b\n" /* line 1954 */
        "movl -0x38(%ebp), %eax\n" /* line 2134 */
        "cmpl 0xc(%edx), %eax\n"
        "jl .Lf2bab3e_002babe9\n"
        "movl %eax, %edx\n"
        "jmp .Lf2bab3e_002bab8e\n"
    );
}
#else
void ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEEvT_S8_(void) /* void std___insertion_sort<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > > > */
{ }
#endif

/* line 2212 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void ZSt22__final_insertion_sortIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEEvT_S8_(void) /* void std___final_insertion_sort<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > > > */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2212 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %edx\n" /* __first */
        "movl 0xc(%ebp), %edi\n" /* __last */
        "movl %edi, %eax\n" /* line 2214 */
        "subl %edx, %eax\n"
        "sarl $4, %eax\n"
        "cmpl $0x10, %eax\n"
        "jle .Lf2bac7a_002baceb\n"
        "leal 0x100(%edx), %ebx\n" /* line 654 */
        "movl %ebx, 4(%esp)\n" /* line 2216 */
        "movl %edx, (%esp)\n"
        "calll ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEEvT_S8_\n"
        /* { scope 1 */
        "movl %ebx, %esi\n" /* line 2183 */
        "cmpl %edi, %ebx\n"
        "je .Lf2bac7a_002bace3\n"
        ".Lf2bac7a_002bacad:\n"
        "movl (%esi), %ebx\n" /* line 2184 */
        "movl %ebx, -0x28(%ebp)\n"
        "movl 4(%esi), %ecx\n"
        "movl %ecx, -0x24(%ebp)\n"
        "movl 8(%esi), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl 0xc(%esi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %ecx, 8(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll ZSt25__unguarded_linear_insertIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEES2_EvT_T0_\n"
        "addl $0x10, %esi\n" /* line 623 */
        "cmpl %esi, %edi\n" /* line 2183 */
        "jne .Lf2bac7a_002bacad\n"
        /* } scope */
        ".Lf2bac7a_002bace3:\n"
        "addl $0x3c, %esp\n" /* line 2220 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2bac7a_002baceb:\n"
        "movl %edi, 0xc(%ebp)\n" /* __last */
        "movl %edx, 8(%ebp)\n" /* __first */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEEvT_S8_\n"
    );
}
#else
void ZSt22__final_insertion_sortIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEEvT_S8_(void) /* void std___final_insertion_sort<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > > > */
{ }
#endif

/* line 2277 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void ZSt12partial_sortIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEEvT_S8_S8_(void) /* void std_partial_sort<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > > > */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2277 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 8(%ebp), %eax\n" /* __first */
        "movl %eax, -0x48(%ebp)\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %ecx\n" /* line 2289 | __middle */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ZSt9make_heapIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEEvT_S8_\n"
        "movl 0xc(%ebp), %edi\n" /* line 2290 | __middle */
        "movl %edi, %esi\n"
        "cmpl %edi, 0x10(%ebp)\n" /* __last */
        "jbe .Lf2bacfe_002bade6\n"
        "subl -0x48(%ebp), %esi\n"
        "sarl $4, %esi\n"
        "movl %esi, -0x4c(%ebp)\n"
        "jmp .Lf2bacfe_002bad43\n"
        ".Lf2bacfe_002bad35:\n"
        "je .Lf2bacfe_002badcc\n" /* line 1942 */
        ".Lf2bacfe_002bad3b:\n"
        "addl $0x10, %edi\n" /* line 623 */
        "cmpl 0x10(%ebp), %edi\n" /* line 2290 | __last */
        "jae .Lf2bacfe_002badb2\n"
        ".Lf2bacfe_002bad43:\n"
        "movl (%edi), %edx\n" /* line 1938 */
        "movl -0x48(%ebp), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, -0x50(%ebp)\n"
        "cmpl %eax, %edx\n"
        "jge .Lf2bacfe_002bad35\n"
        "movl 0xc(%edi), %esi\n"
        ".Lf2bacfe_002bad54:\n"
        "movl %esi, -0x44(%ebp)\n" /* line 2292 */
        "movl 8(%edi), %ebx\n"
        "movl 4(%edi), %ecx\n"
        /* { scope 2 */
        "movl %eax, (%edi)\n" /* line 237 */
        "movl -0x48(%ebp), %esi\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, 4(%edi)\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, 8(%edi)\n"
        "movl 0xc(%esi), %eax\n"
        "movl %eax, 0xc(%edi)\n"
        "movl -0x44(%ebp), %eax\n" /* line 238 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl %ebx, -0x30(%ebp)\n"
        "movl %ecx, -0x34(%ebp)\n"
        "movl %edx, -0x38(%ebp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %ecx, 0x10(%esp)\n"
        "movl %ebx, 0x14(%esp)\n"
        "movl %eax, 0x18(%esp)\n"
        "movl -0x4c(%ebp), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEiS2_EvT_T0_S9_T1_\n"
        /* } scope */
        "addl $0x10, %edi\n" /* line 623 */
        "cmpl 0x10(%ebp), %edi\n" /* line 2290 | __last */
        "jb .Lf2bacfe_002bad43\n"
        ".Lf2bacfe_002badb2:\n"
        "movl 0xc(%ebp), %esi\n" /* __middle */
        "movl %esi, %edx\n" /* line 432 */
        "subl -0x48(%ebp), %edx\n"
        "movl %edx, %eax\n"
        "sarl $4, %eax\n"
        "subl $1, %eax\n"
        "jg .Lf2bacfe_002badf7\n"
        /* } scope */
        ".Lf2bacfe_002badc4:\n"
        "addl $0x7c, %esp\n" /* line 2293 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2bacfe_002badcc:\n"
        "movl -0x48(%ebp), %ecx\n" /* line 1944 */
        "movl 4(%ecx), %eax\n"
        "cmpl %eax, 4(%edi)\n"
        "jge .Lf2bacfe_002bae81\n"
        ".Lf2bacfe_002baddb:\n"
        "movl 0xc(%edi), %esi\n"
        "movl -0x50(%ebp), %eax\n"
        "jmp .Lf2bacfe_002bad54\n"
        ".Lf2bacfe_002bade6:\n"
        "movl %edi, %esi\n"
        "movl %esi, %edx\n" /* line 432 */
        "subl -0x48(%ebp), %edx\n"
        "movl %edx, %eax\n"
        "sarl $4, %eax\n"
        "subl $1, %eax\n"
        "jle .Lf2bacfe_002badc4\n"
        ".Lf2bacfe_002badf7:\n"
        "subl $0x10, %edx\n"
        "movl %edx, -0x3c(%ebp)\n"
        "jmp .Lf2bacfe_002bae01\n"
        ".Lf2bacfe_002badff:\n"
        "movl %edi, %esi\n"
        ".Lf2bacfe_002bae01:\n"
        "leal -0x10(%esi), %edi\n" /* line 641 */
        /* { scope 1 */
        "movl 0xc(%edi), %eax\n" /* line 265 */
        "movl %eax, -0x40(%ebp)\n"
        "movl 8(%edi), %ebx\n"
        "movl 4(%edi), %ecx\n"
        "movl -0x10(%esi), %edx\n"
        /* { scope 2 */
        "movl -0x48(%ebp), %eax\n" /* line 237 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x10(%esi)\n"
        "movl -0x48(%ebp), %esi\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, 4(%edi)\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, 8(%edi)\n"
        "movl 0xc(%esi), %eax\n"
        "movl %eax, 0xc(%edi)\n"
        "movl -0x40(%ebp), %eax\n" /* line 238 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl %ebx, -0x20(%ebp)\n"
        "movl %ecx, -0x24(%ebp)\n"
        "movl %edx, -0x28(%ebp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %ecx, 0x10(%esp)\n"
        "movl %ebx, 0x14(%esp)\n"
        "movl %eax, 0x18(%esp)\n"
        "movl %edi, %eax\n"
        "subl %esi, %eax\n"
        "sarl $4, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEiS2_EvT_T0_S9_T1_\n"
        /* } scope */
        /* } scope */
        "movl -0x3c(%ebp), %eax\n" /* line 759 */
        "sarl $4, %eax\n"
        "subl $0x10, -0x3c(%ebp)\n"
        "subl $1, %eax\n" /* line 432 */
        "jg .Lf2bacfe_002badff\n"
        "addl $0x7c, %esp\n" /* line 2293 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2bacfe_002bae81:\n"
        "jne .Lf2bacfe_002bad3b\n" /* line 1948 */
        "movl 8(%ecx), %eax\n" /* line 1950 */
        "cmpl %eax, 8(%edi)\n"
        "jl .Lf2bacfe_002baddb\n"
        "jne .Lf2bacfe_002bad3b\n" /* line 1954 */
        "movl 0xc(%edi), %eax\n"
        "cmpl 0xc(%ecx), %eax\n" /* line 2291 */
        "jge .Lf2bacfe_002bad3b\n"
        "movl %eax, %esi\n"
        "movl -0x50(%ebp), %eax\n"
        "jmp .Lf2bacfe_002bad54\n"
    );
}
#else
void ZSt12partial_sortIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEEvT_S8_S8_(void) /* void std_partial_sort<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > > > */
{ }
#endif

/* line 2478 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEiEvT_S8_T0_(void) /* void std___introsort_loop<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > >, int> */
{
    __asm__ __volatile__ (
        ".Lf2baeb0_002baeb0:\n"
        "pushl %ebp\n" /* line 2478 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl 8(%ebp), %edi\n" /* __first */
        "movl 0x10(%ebp), %eax\n" /* __depth_limit */
        "movl %eax, -0x40(%ebp)\n" /* __depth_limit */
        "movl 0xc(%ebp), %edx\n" /* __last */
        "movl %edx, -0x34(%ebp)\n"
        /* { scope 1 */
        "movl %edx, %eax\n" /* line 2483 */
        "subl %edi, %eax\n" /* __first */
        "sarl $4, %eax\n"
        "cmpl $0x10, %eax\n"
        "jle .Lf2baeb0_002bb05a\n"
        "movl -0x40(%ebp), %eax\n" /* line 2485 | __depth_limit */
        "testl %eax, %eax\n"
        "je .Lf2baeb0_002bafc0\n"
        "movl -0x40(%ebp), %eax\n" /* line 2487 | __depth_limit */
        "movl %eax, -0x2c(%ebp)\n"
        "movl $0, -0x30(%ebp)\n"
        ".Lf2baeb0_002baef0:\n"
        "subl $1, -0x2c(%ebp)\n" /* line 2490 */
        "movl -0x34(%ebp), %edx\n" /* line 662 */
        "subl $0x10, %edx\n"
        "movl %edx, -0x4c(%ebp)\n"
        "movl -0x34(%ebp), %edx\n" /* line 654 */
        "subl %edi, %edx\n"
        "sarl $4, %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "shll $4, %eax\n"
        "addl %edi, %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        "movl %eax, %esi\n" /* line 2499 | inLHS */
        "movl (%edi), %ecx\n" /* line 1938 */
        "movl (%eax), %edx\n"
        "cmpl %edx, %ecx\n"
        "jl .Lf2baeb0_002bb000\n"
        "je .Lf2baeb0_002bafd8\n" /* line 1942 */
        ".Lf2baeb0_002baf2a:\n"
        "movl -0x4c(%ebp), %ebx\n" /* line 1938 */
        "movl (%ebx), %ebx\n"
        "movl %ebx, -0x38(%ebp)\n"
        "cmpl %ebx, %ecx\n"
        "jl .Lf2baeb0_002bb019\n"
        "je .Lf2baeb0_002bb0c5\n" /* line 1942 */
        /* { scope 2 */
        ".Lf2baeb0_002baf40:\n"
        "cmpl -0x38(%ebp), %edx\n" /* line 1938 */
        "jl .Lf2baeb0_002bb052\n"
        "je .Lf2baeb0_002bb020\n" /* line 1942 */
        /* } scope */
        ".Lf2baeb0_002baf4f:\n"
        "movl (%esi), %ebx\n" /* line 2499 | inLHS */
        "movl %ebx, -0x28(%ebp)\n"
        "movl 4(%esi), %ecx\n" /* inLHS */
        "movl %ecx, -0x24(%ebp)\n"
        "movl 8(%esi), %edx\n" /* inLHS */
        "movl %edx, -0x20(%ebp)\n"
        "movl 0xc(%esi), %eax\n" /* inLHS */
        "movl %eax, -0x1c(%ebp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl %eax, 0x14(%esp)\n"
        "movl -0x34(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* __first */
        "calll ZSt21__unguarded_partitionIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEES2_ET_S8_S8_T0_\n"
        "movl %eax, %ebx\n"
        "movl -0x2c(%ebp), %eax\n" /* line 2500 */
        "movl %eax, 8(%esp)\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEiEvT_S8_T0_\n"
        "movl %ebx, -0x34(%ebp)\n" /* line 2501 */
        "movl %ebx, %eax\n" /* line 2483 */
        "subl %edi, %eax\n" /* __first */
        "sarl $4, %eax\n"
        "cmpl $0x10, %eax\n"
        "jle .Lf2baeb0_002bb05a\n"
        "addl $1, -0x30(%ebp)\n"
        "movl -0x30(%ebp), %ecx\n" /* line 2485 */
        "cmpl %ecx, -0x40(%ebp)\n" /* __depth_limit */
        "jne .Lf2baeb0_002baef0\n"
        ".Lf2baeb0_002bafc0:\n"
        "movl -0x34(%ebp), %ebx\n" /* line 2487 */
        "movl %ebx, 0x10(%ebp)\n" /* __depth_limit */
        "movl %ebx, 0xc(%ebp)\n" /* __last */
        "movl %edi, 8(%ebp)\n" /* __first */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 2501 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp ZSt12partial_sortIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEEvT_S8_S8_\n" /* line 2487 */
        ".Lf2baeb0_002bafd8:\n"
        "movl 4(%eax), %eax\n" /* line 1944 */
        "cmpl %eax, 4(%edi)\n"
        "jl .Lf2baeb0_002bb000\n"
        "jne .Lf2baeb0_002baf2a\n" /* line 1948 */
        "movl 8(%esi), %eax\n" /* line 1950 | inLHS */
        "cmpl %eax, 8(%edi)\n"
        "jl .Lf2baeb0_002bb000\n"
        "jne .Lf2baeb0_002baf2a\n" /* line 1954 */
        "movl 0xc(%edi), %eax\n" /* line 90 */
        "cmpl 0xc(%esi), %eax\n"
        "jge .Lf2baeb0_002baf2a\n"
        ".Lf2baeb0_002bb000:\n"
        "movl -0x4c(%ebp), %ebx\n" /* line 1938 */
        "movl (%ebx), %ebx\n"
        "movl %ebx, -0x3c(%ebp)\n"
        "cmpl %ebx, %edx\n"
        "jl .Lf2baeb0_002baf4f\n"
        "je .Lf2baeb0_002bb062\n" /* line 1942 */
        ".Lf2baeb0_002bb012:\n"
        "cmpl -0x3c(%ebp), %ecx\n" /* line 1938 */
        "jl .Lf2baeb0_002bb052\n"
        "je .Lf2baeb0_002bb092\n" /* line 1942 */
        ".Lf2baeb0_002bb019:\n"
        "movl %edi, %esi\n" /* line 99 | inLHS */
        "jmp .Lf2baeb0_002baf4f\n"
        /* { scope 1 */
        ".Lf2baeb0_002bb020:\n"
        "movl -0x4c(%ebp), %ebx\n" /* line 1944 */
        "movl 4(%ebx), %eax\n"
        "movl -0x44(%ebp), %edx\n"
        "cmpl %eax, 4(%edx)\n"
        "jl .Lf2baeb0_002bb106\n"
        "jne .Lf2baeb0_002baf4f\n" /* line 1948 */
        "movl 8(%ebx), %eax\n" /* line 1950 */
        "cmpl %eax, 8(%edx)\n"
        "jl .Lf2baeb0_002bb052\n"
        "jne .Lf2baeb0_002baf4f\n" /* line 1954 */
        "movl 0xc(%edx), %eax\n"
        /* } scope */
        "cmpl 0xc(%ebx), %eax\n" /* line 99 */
        "jge .Lf2baeb0_002baf4f\n"
        ".Lf2baeb0_002bb052:\n"
        "movl -0x4c(%ebp), %esi\n" /* inLHS */
        "jmp .Lf2baeb0_002baf4f\n"
        ".Lf2baeb0_002bb05a:\n"
        "addl $0x6c, %esp\n" /* line 2501 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2baeb0_002bb062:\n"
        "movl -0x4c(%ebp), %edx\n" /* line 1944 */
        "movl 4(%edx), %eax\n"
        "movl -0x44(%ebp), %ebx\n"
        "cmpl %eax, 4(%ebx)\n"
        "jl .Lf2baeb0_002baf4f\n"
        "jne .Lf2baeb0_002bb012\n" /* line 1948 */
        "movl 8(%edx), %eax\n" /* line 1950 */
        "cmpl %eax, 8(%ebx)\n"
        "jl .Lf2baeb0_002baf4f\n"
        "jne .Lf2baeb0_002bb012\n" /* line 1954 */
        "movl 0xc(%ebx), %eax\n"
        "cmpl 0xc(%edx), %eax\n" /* line 91 */
        "jl .Lf2baeb0_002baf4f\n"
        "jmp .Lf2baeb0_002bb012\n"
        ".Lf2baeb0_002bb092:\n"
        "movl -0x4c(%ebp), %edx\n" /* line 1944 */
        "movl 4(%edx), %eax\n"
        "cmpl %eax, 4(%edi)\n"
        "jl .Lf2baeb0_002bb0ff\n"
        "jne .Lf2baeb0_002bb019\n" /* line 1948 */
        "movl 8(%edx), %eax\n" /* line 1950 */
        "cmpl %eax, 8(%edi)\n"
        "jl .Lf2baeb0_002bb052\n"
        "jne .Lf2baeb0_002bb019\n" /* line 1954 */
        "movl 0xc(%edi), %eax\n"
        "cmpl 0xc(%edx), %eax\n" /* line 93 */
        "jge .Lf2baeb0_002bb019\n"
        "movl -0x4c(%ebp), %esi\n"
        "jmp .Lf2baeb0_002baf4f\n"
        ".Lf2baeb0_002bb0c5:\n"
        "movl -0x4c(%ebp), %ecx\n" /* line 1944 */
        "movl 4(%ecx), %eax\n"
        "cmpl %eax, 4(%edi)\n"
        "jl .Lf2baeb0_002bb019\n"
        "jne .Lf2baeb0_002baf40\n" /* line 1948 */
        "movl 8(%ecx), %eax\n" /* line 1950 */
        "cmpl %eax, 8(%edi)\n"
        "jl .Lf2baeb0_002bb019\n"
        "jne .Lf2baeb0_002baf40\n" /* line 1954 */
        "movl 0xc(%edi), %eax\n"
        "cmpl 0xc(%ecx), %eax\n" /* line 97 */
        "jge .Lf2baeb0_002baf40\n"
        "movl %edi, %esi\n" /* line 99 | inLHS */
        "jmp .Lf2baeb0_002baf4f\n"
        ".Lf2baeb0_002bb0ff:\n"
        "movl %edx, %esi\n" /* inLHS */
        "jmp .Lf2baeb0_002baf4f\n"
        ".Lf2baeb0_002bb106:\n"
        "movl %ebx, %esi\n" /* inLHS */
        "jmp .Lf2baeb0_002baf4f\n"
    );
}
#else
void ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIP8CResInfoSt6vectorIS2_SaIS2_EEEEiEvT_S8_T0_(void) /* void std___introsort_loop<__gnu_cxx___normal_iterator<CResInfo*, std_vector<CResInfo, std_allocator<CResInfo> > >, int> */
{ }
#endif

/* line 249 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void ZNSt6vectorI7MacRectSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_(void) /* std_vector<MacRect, std_allocator<MacRect> >__M_insert_aux */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 249 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0xc(%ebp), %eax\n" /* __position */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 4(%edi), %ecx\n" /* line 251 | this */
        "cmpl 8(%edi), %ecx\n" /* this */
        "je .Lf2bb10e_002bb196\n"
        "testl %ecx, %ecx\n" /* line 104 */
        "je .Lf2bb10e_002bb13a\n"
        "movl -8(%ecx), %eax\n"
        "movl -4(%ecx), %edx\n"
        "movl %eax, (%ecx)\n"
        "movl %edx, 4(%ecx)\n"
        "movl 4(%edi), %ecx\n"
        ".Lf2bb10e_002bb13a:\n"
        "movl %ecx, %eax\n" /* line 255 */
        "addl $8, %ecx\n"
        "movl %ecx, 4(%edi)\n" /* this */
        "movl 0x10(%ebp), %ecx\n" /* line 256 | __x */
        "movl (%ecx), %edx\n"
        "movl 4(%ecx), %ecx\n"
        "movl %edx, -0x28(%ebp)\n"
        "movl %ecx, -0x24(%ebp)\n"
        "leal -8(%eax), %edi\n" /* line 257 | this */
        /* { scope 1 */
        "subl -0x1c(%ebp), %edi\n" /* line 411 | this */
        "sarl $3, %edi\n" /* this */
        "testl %edi, %edi\n" /* this */
        "jle .Lf2bb10e_002bb25d\n"
        "movl %eax, %ebx\n"
        "leal -0x10(%eax), %ecx\n"
        "xorl %esi, %esi\n"
        ".Lf2bb10e_002bb168:\n"
        "movl (%ecx), %eax\n" /* line 412 */
        "movl 4(%ecx), %edx\n"
        "movl %eax, -8(%ebx)\n"
        "movl %edx, -4(%ebx)\n"
        "addl $1, %esi\n"
        "subl $8, %ebx\n"
        "subl $8, %ecx\n"
        "cmpl %edi, %esi\n" /* line 411 | this */
        "jne .Lf2bb10e_002bb168\n"
        "movl -0x28(%ebp), %eax\n"
        "movl -0x24(%ebp), %edx\n"
        /* } scope */
        ".Lf2bb10e_002bb186:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 260 | __position */
        "movl %eax, (%ecx)\n"
        "movl %edx, 4(%ecx)\n"
        "addl $0x3c, %esp\n" /* line 304 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2bb10e_002bb196:\n"
        "movl %ecx, %eax\n" /* line 759 */
        "subl (%edi), %eax\n" /* this */
        "sarl $3, %eax\n"
        "cmpl $0x1fffffff, %eax\n" /* line 265 */
        "je .Lf2bb10e_002bb28c\n"
        "testl %eax, %eax\n" /* line 271 */
        "jne .Lf2bb10e_002bb266\n"
        "movl $1, %edx\n" /* __len */
        ".Lf2bb10e_002bb1b5:\n"
        "shll $3, %edx\n" /* line 88 */
        "movl %edx, -0x2c(%ebp)\n"
        "movl %edx, (%esp)\n"
        "calll __Znwm\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl (%edi), %ecx\n" /* line 279 | this */
        /* { scope 2 */
        "movl %eax, %ebx\n" /* line 82 */
        "cmpl 0xc(%ebp), %ecx\n" /* line 85 | __position */
        "je .Lf2bb10e_002bb1e8\n"
        ".Lf2bb10e_002bb1cf:\n"
        "testl %ebx, %ebx\n" /* line 81 */
        "je .Lf2bb10e_002bb1dd\n"
        "movl (%ecx), %eax\n"
        "movl 4(%ecx), %edx\n"
        "movl %eax, (%ebx)\n"
        "movl %edx, 4(%ebx)\n"
        ".Lf2bb10e_002bb1dd:\n"
        "addl $8, %ecx\n" /* line 623 */
        "addl $8, %ebx\n"
        "cmpl 0xc(%ebp), %ecx\n" /* line 85 | __position */
        "jne .Lf2bb10e_002bb1cf\n"
        /* } scope */
        ".Lf2bb10e_002bb1e8:\n"
        "testl %ebx, %ebx\n" /* line 104 */
        "je .Lf2bb10e_002bb1f9\n"
        "movl 0x10(%ebp), %ecx\n" /* __x */
        "movl (%ecx), %eax\n"
        "movl 4(%ecx), %edx\n"
        "movl %eax, (%ebx)\n"
        "movl %edx, 4(%ebx)\n"
        ".Lf2bb10e_002bb1f9:\n"
        "leal 4(%edi), %eax\n" /* line 286 | this */
        "movl %eax, -0x30(%ebp)\n"
        "movl 4(%edi), %esi\n" /* line 603 | this */
        "movl -0x1c(%ebp), %ecx\n" /* line 286 */
        /* { scope 2 */
        "addl $8, %ebx\n" /* line 82 */
        "cmpl %ecx, %esi\n" /* line 85 */
        "je .Lf2bb10e_002bb288\n"
        ".Lf2bb10e_002bb20c:\n"
        "testl %ebx, %ebx\n" /* line 81 */
        "je .Lf2bb10e_002bb21a\n"
        "movl 4(%ecx), %edx\n"
        "movl (%ecx), %eax\n"
        "movl %eax, (%ebx)\n"
        "movl %edx, 4(%ebx)\n"
        ".Lf2bb10e_002bb21a:\n"
        "addl $8, %ecx\n" /* line 623 */
        "addl $8, %ebx\n"
        "cmpl %esi, %ecx\n" /* line 85 */
        "jne .Lf2bb10e_002bb20c\n"
        "movl -0x30(%ebp), %ecx\n"
        /* } scope */
        ".Lf2bb10e_002bb227:\n"
        "movl (%ecx), %edx\n" /* line 352 */
        "movl (%edi), %ecx\n" /* line 334 | this */
        "movl %ecx, %eax\n"
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf2bb10e_002bb238\n"
        ".Lf2bb10e_002bb231:\n"
        "addl $8, %eax\n" /* line 623 */
        "cmpl %eax, %edx\n" /* line 173 */
        "jne .Lf2bb10e_002bb231\n"
        ".Lf2bb10e_002bb238:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf2bb10e_002bb244\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf2bb10e_002bb244:\n"
        "movl -0x34(%ebp), %eax\n" /* line 302 */
        "movl %eax, (%edi)\n" /* this */
        "movl %ebx, 4(%edi)\n" /* line 303 | this */
        "movl -0x34(%ebp), %eax\n" /* line 304 */
        "addl -0x2c(%ebp), %eax\n"
        "movl %eax, 8(%edi)\n" /* this */
        /* } scope */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2bb10e_002bb25d:\n"
        "movl %edx, %eax\n"
        "movl %ecx, %edx\n"
        "jmp .Lf2bb10e_002bb186\n"
        /* { scope 1 */
        ".Lf2bb10e_002bb266:\n"
        "leal (%eax, %eax), %edx\n" /* line 271 | __len */
        "cmpl %eax, %edx\n" /* line 272 */
        "jb .Lf2bb10e_002bb27e\n"
        "cmpl $0x1fffffff, %edx\n" /* line 85 */
        "jbe .Lf2bb10e_002bb1b5\n"
        "calll __ZSt17__throw_bad_allocv\n" /* line 86 */
        ".Lf2bb10e_002bb27e:\n"
        "movl $0x1fffffff, %edx\n" /* line 272 */
        "jmp .Lf2bb10e_002bb1b5\n"
        ".Lf2bb10e_002bb288:\n"
        "movl %eax, %ecx\n"
        "jmp .Lf2bb10e_002bb227\n"
        ".Lf2bb10e_002bb28c:\n"
        "movl $str_00215858, (%esp)\n" /* line 266 */
        "calll __ZSt20__throw_length_errorPKc\n"
    );
}
#else
void ZNSt6vectorI7MacRectSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_(void) /* std_vector<MacRect, std_allocator<MacRect> >__M_insert_aux */
{ }
#endif

/* line 249 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void ZNSt6vectorI8CResInfoSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_(void) /* std_vector<CResInfo, std_allocator<CResInfo> >__M_insert_aux */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 249 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* __position */
        "movl 0x10(%ebp), %esi\n" /* __x */
        "movl %edi, -0x1c(%ebp)\n" /* __position */
        "movl 8(%ebp), %eax\n" /* line 251 | this */
        "movl 4(%eax), %edx\n"
        "cmpl 8(%eax), %edx\n"
        "je .Lf2bb298_002bb35b\n"
        "leal -0x10(%edx), %ecx\n"
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 104 */
        "je .Lf2bb298_002bb454\n"
        "movl -0x10(%edx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%ecx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%ecx), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 4(%ecx), %edx\n"
        "movl %ecx, %eax\n"
        /* } scope */
        ".Lf2bb298_002bb2e3:\n"
        "movl %edx, %ebx\n" /* line 255 */
        "addl $0x10, %edx\n"
        "movl %edx, 4(%eax)\n"
        "movl 0xc(%esi), %edx\n" /* line 256 | __x */
        "movl %edx, -0x20(%ebp)\n"
        "movl 8(%esi), %ecx\n" /* __x */
        "movl %ecx, -0x24(%ebp)\n"
        "movl 4(%esi), %eax\n" /* __x */
        "movl %eax, -0x28(%ebp)\n"
        "movl (%esi), %esi\n" /* __x */
        "movl %esi, -0x2c(%ebp)\n" /* __x */
        "leal -0x10(%ebx), %eax\n" /* line 257 */
        /* { scope 1 */
        "movl %eax, %esi\n" /* line 411 | __x */
        "subl -0x1c(%ebp), %esi\n" /* __x */
        "sarl $4, %esi\n" /* __x */
        "testl %esi, %esi\n" /* __x */
        "jle .Lf2bb298_002bb33f\n"
        "movl %eax, %ecx\n"
        "movl %ebx, %edx\n"
        "xorl %ebx, %ebx\n"
        ".Lf2bb298_002bb317:\n"
        "movl -0x10(%ecx), %eax\n" /* line 412 */
        "movl %eax, -0x10(%edx)\n"
        "movl -0xc(%ecx), %eax\n"
        "movl %eax, -0xc(%edx)\n"
        "movl -8(%ecx), %eax\n"
        "movl %eax, -8(%edx)\n"
        "movl -4(%ecx), %eax\n"
        "movl %eax, -4(%edx)\n"
        "addl $1, %ebx\n"
        "subl $0x10, %ecx\n"
        "subl $0x10, %edx\n"
        "cmpl %ebx, %esi\n" /* line 411 | __x */
        "jne .Lf2bb298_002bb317\n"
        "movl -0x20(%ebp), %edx\n"
        ".Lf2bb298_002bb33f:\n"
        "movl %edx, 0xc(%edi)\n" /* line 260 | __position */
        "movl -0x24(%ebp), %ecx\n"
        "movl %ecx, 8(%edi)\n" /* __position */
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 4(%edi)\n" /* __position */
        "movl -0x2c(%ebp), %edx\n"
        "movl %edx, (%edi)\n" /* __position */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 304 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2bb298_002bb35b:\n"
        "movl %eax, %ecx\n"
        /* { scope 1 */
        "movl %edx, %eax\n" /* line 759 */
        "subl (%ecx), %eax\n"
        "sarl $4, %eax\n"
        "cmpl $0xfffffff, %eax\n" /* line 265 */
        "je .Lf2bb298_002bb47e\n"
        "testl %eax, %eax\n" /* line 271 */
        "jne .Lf2bb298_002bb45c\n"
        "movl $1, %edx\n" /* __len */
        ".Lf2bb298_002bb37c:\n"
        "shll $4, %edx\n" /* line 88 */
        "movl %edx, -0x30(%ebp)\n"
        "movl %edx, (%esp)\n"
        "calll __Znwm\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* line 279 | this */
        "movl (%eax), %edx\n"
        /* { scope 2 */
        "movl -0x34(%ebp), %ecx\n" /* line 82 */
        "cmpl %edx, %edi\n" /* line 85 */
        "je .Lf2bb298_002bb3c3\n"
        "movl %edx, %ebx\n"
        "jmp .Lf2bb298_002bb39f\n"
        ".Lf2bb298_002bb39d:\n"
        "movl %ebx, %edx\n"
        ".Lf2bb298_002bb39f:\n"
        "testl %ecx, %ecx\n" /* line 81 */
        "je .Lf2bb298_002bb3b9\n"
        "movl (%edx), %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%ecx)\n"
        ".Lf2bb298_002bb3b9:\n"
        "addl $0x10, %ebx\n" /* line 623 */
        "addl $0x10, %ecx\n"
        "cmpl %ebx, %edi\n" /* line 85 */
        "jne .Lf2bb298_002bb39d\n"
        /* } scope */
        ".Lf2bb298_002bb3c3:\n"
        "testl %ecx, %ecx\n" /* line 104 */
        "je .Lf2bb298_002bb3dd\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, 4(%ecx)\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%esi), %eax\n"
        "movl %eax, 0xc(%ecx)\n"
        ".Lf2bb298_002bb3dd:\n"
        "movl 8(%ebp), %edi\n" /* line 286 | this, __position */
        "addl $4, %edi\n" /* __position */
        "movl 8(%ebp), %edx\n" /* line 603 | this */
        "movl 4(%edx), %esi\n" /* __x */
        "movl -0x1c(%ebp), %edx\n" /* line 286 */
        /* { scope 2 */
        "leal 0x10(%ecx), %ebx\n" /* line 82 */
        "cmpl %edx, %esi\n" /* line 85 */
        "je .Lf2bb298_002bb419\n"
        ".Lf2bb298_002bb3f3:\n"
        "movl %edx, %ecx\n"
        "testl %ebx, %ebx\n" /* line 81 */
        "je .Lf2bb298_002bb40f\n"
        "movl (%edx), %eax\n"
        "movl %eax, (%ebx)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 4(%ebx)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%ebx)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%ebx)\n"
        ".Lf2bb298_002bb40f:\n"
        "leal 0x10(%ecx), %edx\n" /* line 623 */
        "addl $0x10, %ebx\n"
        "cmpl %esi, %edx\n" /* line 85 */
        "jne .Lf2bb298_002bb3f3\n"
        /* } scope */
        ".Lf2bb298_002bb419:\n"
        "movl (%edi), %edx\n" /* line 352 | __position */
        "movl 8(%ebp), %eax\n" /* line 334 | this */
        "movl (%eax), %ecx\n"
        "movl %ecx, %eax\n"
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf2bb298_002bb42d\n"
        ".Lf2bb298_002bb426:\n"
        "addl $0x10, %eax\n" /* line 623 */
        "cmpl %eax, %edx\n" /* line 173 */
        "jne .Lf2bb298_002bb426\n"
        ".Lf2bb298_002bb42d:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf2bb298_002bb439\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf2bb298_002bb439:\n"
        "movl -0x34(%ebp), %ecx\n" /* line 302 */
        "movl 8(%ebp), %edx\n" /* this */
        "movl %ecx, (%edx)\n"
        "movl %ebx, 4(%edx)\n" /* line 303 */
        "movl %ecx, %eax\n" /* line 304 */
        "addl -0x30(%ebp), %eax\n"
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2bb298_002bb454:\n"
        "movl 8(%ebp), %eax\n" /* this */
        "jmp .Lf2bb298_002bb2e3\n"
        /* { scope 1 */
        ".Lf2bb298_002bb45c:\n"
        "leal (%eax, %eax), %edx\n" /* line 271 | __len */
        "cmpl %eax, %edx\n" /* line 272 */
        "jb .Lf2bb298_002bb474\n"
        "cmpl $0xfffffff, %edx\n" /* line 85 */
        "jbe .Lf2bb298_002bb37c\n"
        "calll __ZSt17__throw_bad_allocv\n" /* line 86 */
        ".Lf2bb298_002bb474:\n"
        "movl $0xfffffff, %edx\n" /* line 272 */
        "jmp .Lf2bb298_002bb37c\n"
        ".Lf2bb298_002bb47e:\n"
        "movl $str_00215858, (%esp)\n" /* line 266 */
        "calll __ZSt20__throw_length_errorPKc\n"
    );
}
#else
void ZNSt6vectorI8CResInfoSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_(void) /* std_vector<CResInfo, std_allocator<CResInfo> >__M_insert_aux */
{ }
#endif

/* line 133 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void ZNSt6vectorI8CResInfoSaIS0_EEaSERKS2_(void) /* std_vector<CResInfo, std_allocator<CResInfo> >_operator= */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 133 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 135 | this */
        "cmpl %eax, 0xc(%ebp)\n" /* __x */
        "je .Lf2bb48a_002bb573\n"
        "movl 0xc(%ebp), %edx\n" /* line 343 | __x */
        "movl (%edx), %edi\n"
        "movl 4(%edx), %ecx\n" /* line 361 */
        "movl %ecx, -0x28(%ebp)\n"
        "subl %edi, %ecx\n" /* line 403 */
        "sarl $4, %ecx\n"
        "movl %ecx, -0x20(%ebp)\n"
        "movl (%eax), %esi\n" /* line 343 */
        "movl 8(%eax), %eax\n" /* line 138 */
        "subl %esi, %eax\n"
        "sarl $4, %eax\n"
        "cmpl %eax, %ecx\n"
        "ja .Lf2bb48a_002bb5c7\n"
        "movl 8(%ebp), %edx\n" /* line 361 | this */
        "movl 4(%edx), %eax\n"
        "movl %eax, %ebx\n" /* line 150 */
        "subl %esi, %ebx\n"
        "sarl $4, %ebx\n"
        "cmpl %ebx, -0x20(%ebp)\n"
        "jbe .Lf2bb48a_002bb57b\n"
        "movl %esi, %ecx\n" /* line 157 */
        "movl %edi, %edx\n" /* line 343 */
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        "movl %ebx, -0x24(%ebp)\n" /* line 283 */
        "testl %ebx, %ebx\n"
        "jle .Lf2bb48a_002bb51e\n"
        "xorl %ebx, %ebx\n"
        ".Lf2bb48a_002bb4e7:\n"
        "movl (%edx), %eax\n" /* line 285 */
        "movl %eax, (%ecx)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%ecx)\n"
        "addl $0x10, %edx\n" /* line 286 */
        "addl $0x10, %ecx\n" /* line 287 */
        "addl $1, %ebx\n"
        "cmpl %ebx, -0x24(%ebp)\n" /* line 283 */
        "jne .Lf2bb48a_002bb4e7\n"
        "movl 0xc(%ebp), %eax\n" /* __x */
        "movl (%eax), %edi\n"
        "movl 4(%eax), %edx\n"
        "movl %edx, -0x28(%ebp)\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl (%ecx), %esi\n"
        "movl 4(%ecx), %eax\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf2bb48a_002bb51e:\n"
        "movl %eax, %ecx\n" /* line 159 */
        "subl %esi, %eax\n"
        "andl $0xfffffff0, %eax\n" /* line 654 */
        "leal (%edi, %eax), %edx\n"
        /* { scope 1 */
        "cmpl %edx, -0x28(%ebp)\n" /* line 85 */
        "je .Lf2bb48a_002bb5bf\n"
        "movl %edx, %ebx\n"
        "jmp .Lf2bb48a_002bb537\n"
        ".Lf2bb48a_002bb535:\n"
        "movl %ebx, %edx\n"
        /* { scope 2 */
        ".Lf2bb48a_002bb537:\n"
        "testl %ecx, %ecx\n" /* line 81 */
        "je .Lf2bb48a_002bb551\n"
        "movl (%edx), %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%ecx)\n"
        /* } scope */
        ".Lf2bb48a_002bb551:\n"
        "addl $0x10, %ebx\n" /* line 623 */
        "addl $0x10, %ecx\n" /* line 85 */
        "cmpl %ebx, -0x28(%ebp)\n"
        "jne .Lf2bb48a_002bb535\n"
        "movl -0x20(%ebp), %edx\n"
        "shll $4, %edx\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl (%eax), %esi\n"
        /* } scope */
        ".Lf2bb48a_002bb567:\n"
        "leal (%edx, %esi), %eax\n" /* line 163 */
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebp), %eax\n" /* this */
        ".Lf2bb48a_002bb573:\n"
        "addl $0x2c, %esp\n" /* line 165 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2bb48a_002bb57b:\n"
        "movl %edi, %ecx\n" /* line 343 */
        "movl %esi, %edx\n"
        /* { scope 1 */
        /* { scope 2 */
        "movl -0x20(%ebp), %ebx\n" /* line 283 */
        "testl %ebx, %ebx\n"
        "jle .Lf2bb48a_002bb5b4\n"
        "xorl %ebx, %ebx\n"
        ".Lf2bb48a_002bb588:\n"
        "movl (%ecx), %eax\n" /* line 285 */
        "movl %eax, (%edx)\n"
        "movl 4(%ecx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%ecx), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "addl $0x10, %ecx\n" /* line 286 */
        "addl $0x10, %edx\n" /* line 287 */
        "addl $1, %ebx\n"
        "cmpl -0x20(%ebp), %ebx\n" /* line 283 */
        "jne .Lf2bb48a_002bb588\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl (%ecx), %esi\n"
        "movl 4(%ecx), %eax\n"
        /* } scope */
        /* } scope */
        ".Lf2bb48a_002bb5b4:\n"
        "cmpl %edx, %eax\n" /* line 173 */
        "je .Lf2bb48a_002bb5bf\n"
        ".Lf2bb48a_002bb5b8:\n"
        "addl $0x10, %edx\n" /* line 623 */
        "cmpl %edx, %eax\n" /* line 173 */
        "jne .Lf2bb48a_002bb5b8\n"
        ".Lf2bb48a_002bb5bf:\n"
        "movl -0x20(%ebp), %edx\n" /* line 85 */
        "shll $4, %edx\n"
        "jmp .Lf2bb48a_002bb567\n"
        /* { scope 1 */
        ".Lf2bb48a_002bb5c7:\n"
        "cmpl $0xfffffff, %ecx\n"
        "ja .Lf2bb48a_002bb64d\n"
        "movl -0x20(%ebp), %ecx\n" /* line 88 */
        "shll $4, %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "movl %ecx, (%esp)\n"
        "calll __Znwm\n"
        "movl %eax, %esi\n"
        "movl %edi, %ecx\n"
        /* { scope 2 */
        "cmpl %edi, -0x28(%ebp)\n" /* line 85 */
        "je .Lf2bb48a_002bb616\n"
        "movl %eax, %edx\n"
        "movl %edi, %ebx\n"
        "jmp .Lf2bb48a_002bb5f1\n"
        ".Lf2bb48a_002bb5ef:\n"
        "movl %ebx, %ecx\n"
        ".Lf2bb48a_002bb5f1:\n"
        "testl %edx, %edx\n" /* line 81 */
        "je .Lf2bb48a_002bb60b\n"
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%ecx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%ecx), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        ".Lf2bb48a_002bb60b:\n"
        "addl $0x10, %ebx\n" /* line 623 */
        "addl $0x10, %edx\n" /* line 85 */
        "cmpl %ebx, -0x28(%ebp)\n"
        "jne .Lf2bb48a_002bb5ef\n"
        /* } scope */
        ".Lf2bb48a_002bb616:\n"
        "movl 8(%ebp), %eax\n" /* line 142 | this */
        "movl 4(%eax), %edx\n" /* __last */
        "movl (%eax), %ecx\n"
        /* { scope 2 */
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf2bb48a_002bb62b\n"
        "movl %ecx, %eax\n"
        ".Lf2bb48a_002bb624:\n"
        "addl $0x10, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf2bb48a_002bb624\n"
        /* } scope */
        ".Lf2bb48a_002bb62b:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf2bb48a_002bb637\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf2bb48a_002bb637:\n"
        "movl 8(%ebp), %edx\n" /* line 147 | this */
        "movl %esi, (%edx)\n"
        "movl -0x1c(%ebp), %edx\n" /* line 148 */
        "leal (%esi, %edx), %eax\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %eax, 8(%ecx)\n"
        "jmp .Lf2bb48a_002bb567\n"
        ".Lf2bb48a_002bb64d:\n"
        "calll __ZSt17__throw_bad_allocv\n" /* line 86 */
    );
}
#else
void ZNSt6vectorI8CResInfoSaIS0_EEaSERKS2_(void) /* std_vector<CResInfo, std_allocator<CResInfo> >_operator= */
{ }
#endif

/* line 249 */
#ifndef __EMSCRIPTEN__
__attribute__((naked))
void ZNSt6vectorI12CDisplayInfoSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_(void) /* std_vector<CDisplayInfo, std_allocator<CDisplayInfo> >__M_insert_aux */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 249 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* __position */
        "movl %eax, -0x94(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 251 | this */
        "movl 4(%edx), %edi\n"
        "cmpl 8(%edx), %edi\n"
        "je .Lf2bb652_002bb76d\n"
        /* { scope 1 */
        "leal -0x64(%edi), %eax\n" /* line 253 | __val */
        /* { scope 2 */
        "testl %edi, %edi\n" /* line 104 */
        "je .Lf2bb652_002bb8e7\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll CDisplayInfo_CDisplayInfo\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 4(%eax), %edi\n"
        "movl %eax, %edx\n"
        /* } scope */
        ".Lf2bb652_002bb695:\n"
        "addl $0x64, %edi\n" /* line 255 */
        "movl %edi, 4(%edx)\n"
        "movl 0x10(%ebp), %eax\n" /* line 256 | __x */
        "movl %eax, 4(%esp)\n"
        "leal -0x80(%ebp), %edx\n" /* __x_copy */
        "movl %edx, (%esp)\n"
        "calll CDisplayInfo_CDisplayInfo\n"
        "movl 8(%ebp), %edx\n" /* line 257 | this */
        "movl 4(%edx), %eax\n"
        "leal -0xc8(%eax), %esi\n"
        "leal -0x64(%eax), %ebx\n"
        /* { scope 2 */
        "movl %esi, %eax\n" /* line 411 */
        "subl 0xc(%ebp), %eax\n" /* __position */
        "sarl $2, %eax\n"
        "imull $0xc28f5c29, %eax, %eax\n"
        "movl %eax, -0xa0(%ebp)\n"
        "testl %eax, %eax\n"
        "jle .Lf2bb652_002bb6f3\n"
        "xorl %edi, %edi\n"
        ".Lf2bb652_002bb6d6:\n"
        "subl $0x64, %esi\n" /* line 412 */
        "subl $0x64, %ebx\n"
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll ZN12CDisplayInfoaSERKS_\n"
        "addl $1, %edi\n"
        "cmpl %edi, -0xa0(%ebp)\n" /* line 411 */
        "jne .Lf2bb652_002bb6d6\n"
        /* } scope */
        ".Lf2bb652_002bb6f3:\n"
        "leal -0x80(%ebp), %eax\n" /* line 260 | __x_copy */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* __position */
        "movl %edx, (%esp)\n"
        "calll ZN12CDisplayInfoaSERKS_\n"
        "movl -0x48(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %esi\n" /* line 178 */
        "cmpl %esi, %ebx\n" /* line 224 */
        "jne .Lf2bb652_002bb911\n"
        ".Lf2bb652_002bb719:\n"
        "movl -0x4c(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "cmpl %ebx, %esi\n" /* line 224 */
        "jne .Lf2bb652_002bb96f\n"
        ".Lf2bb652_002bb727:\n"
        "movl -0x50(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "cmpl %ebx, %esi\n" /* line 224 */
        "jne .Lf2bb652_002bb940\n"
        ".Lf2bb652_002bb735:\n"
        "movl -0x60(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "cmpl %ebx, %esi\n" /* line 224 */
        "jne .Lf2bb652_002bb99e\n"
        ".Lf2bb652_002bb743:\n"
        "movl -0x68(%ebp), %edx\n" /* line 273 | __last */
        "movl -0x6c(%ebp), %ecx\n"
        "movl %ecx, %eax\n"
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf2bb652_002bb756\n"
        ".Lf2bb652_002bb74f:\n"
        "addl $0x10, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf2bb652_002bb74f\n"
        ".Lf2bb652_002bb756:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf2bb652_002bb762\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        ".Lf2bb652_002bb762:\n"
        "addl $0xac, %esp\n" /* line 304 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2bb652_002bb76d:\n"
        "subl (%edx), %edi\n" /* line 759 */
        "sarl $2, %edi\n"
        "imull $0xc28f5c29, %edi, %eax\n"
        "cmpl $0x28f5c28, %eax\n" /* line 265 */
        "je .Lf2bb652_002bb9cd\n"
        "testl %eax, %eax\n" /* line 271 */
        "jne .Lf2bb652_002bb8ef\n"
        "movl $1, %edx\n" /* __len */
        ".Lf2bb652_002bb790:\n"
        "leal (%edx, %edx, 4), %eax\n" /* line 88 */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, -0xa4(%ebp)\n"
        "movl %eax, (%esp)\n"
        "calll __Znwm\n"
        "movl %eax, -0x98(%ebp)\n"
        "movl %eax, -0x8c(%ebp)\n" /* line 276 */
        "movl 8(%ebp), %eax\n" /* line 603 | this */
        "movl (%eax), %esi\n"
        /* { scope 2 */
        "movl -0x98(%ebp), %edi\n" /* line 82 */
        "cmpl 0xc(%ebp), %esi\n" /* line 85 | __position */
        "je .Lf2bb652_002bb7e2\n"
        "movl %edi, %ebx\n"
        ".Lf2bb652_002bb7c5:\n"
        "testl %ebx, %ebx\n" /* line 81 */
        "je .Lf2bb652_002bb7d5\n"
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CDisplayInfo_CDisplayInfo\n"
        ".Lf2bb652_002bb7d5:\n"
        "addl $0x64, %esi\n" /* line 623 */
        "leal 0x64(%ebx), %edi\n"
        "movl %edi, %ebx\n"
        "cmpl 0xc(%ebp), %esi\n" /* line 85 | __position */
        "jne .Lf2bb652_002bb7c5\n"
        /* } scope */
        ".Lf2bb652_002bb7e2:\n"
        "movl %edi, -0x8c(%ebp)\n" /* line 279 */
        "testl %edi, %edi\n" /* line 104 */
        "je .Lf2bb652_002bb7fb\n"
        "movl 0x10(%ebp), %edx\n" /* __x */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll CDisplayInfo_CDisplayInfo\n"
        ".Lf2bb652_002bb7fb:\n"
        "addl $0x64, %edi\n" /* line 623 */
        "movl %edi, -0x8c(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 603 | this */
        "movl 4(%edx), %edi\n"
        "movl -0x94(%ebp), %esi\n" /* line 286 */
        /* { scope 2 */
        "movl -0x8c(%ebp), %eax\n" /* line 82 */
        "movl %eax, -0x90(%ebp)\n"
        "cmpl %edi, %esi\n" /* line 85 */
        "je .Lf2bb652_002bb848\n"
        "movl %eax, %ebx\n"
        ".Lf2bb652_002bb822:\n"
        "testl %ebx, %ebx\n" /* line 81 */
        "je .Lf2bb652_002bb832\n"
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CDisplayInfo_CDisplayInfo\n"
        ".Lf2bb652_002bb832:\n"
        "addl $0x64, %esi\n" /* line 623 */
        "addl $0x64, %ebx\n"
        "movl %ebx, -0x90(%ebp)\n"
        "cmpl %edi, %esi\n" /* line 85 */
        "jne .Lf2bb652_002bb822\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 4(%edx), %edi\n"
        /* } scope */
        ".Lf2bb652_002bb848:\n"
        "movl (%edx), %eax\n" /* line 603 */
        "movl %eax, %ebx\n" /* line 334 */
        "cmpl %eax, %edi\n" /* line 173 */
        "je .Lf2bb652_002bb8aa\n"
        ".Lf2bb652_002bb850:\n"
        "leal 0x38(%ebx), %eax\n" /* line 135 */
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "leal 0x34(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "leal 0x30(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "leal 0x20(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "leal 0x14(%ebx), %ecx\n" /* this */
        /* { scope 2 */
        "movl 4(%ecx), %edx\n" /* line 273 | __last */
        "movl 0x14(%ebx), %eax\n"
        /* { scope 3 */
        "cmpl %eax, %edx\n" /* line 173 */
        "je .Lf2bb652_002bb890\n"
        ".Lf2bb652_002bb889:\n"
        "addl $0x10, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf2bb652_002bb889\n"
        /* } scope */
        ".Lf2bb652_002bb890:\n"
        "movl (%ecx), %eax\n" /* line 109 */
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf2bb652_002bb89e\n"
        /* { scope 3 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        /* } scope */
        ".Lf2bb652_002bb89e:\n"
        "addl $0x64, %ebx\n" /* line 623 */
        "cmpl %edi, %ebx\n" /* line 173 */
        "jne .Lf2bb652_002bb850\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl (%edx), %eax\n"
        ".Lf2bb652_002bb8aa:\n"
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf2bb652_002bb8b6\n"
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf2bb652_002bb8b6:\n"
        "movl -0x98(%ebp), %edx\n" /* line 302 */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %edx, (%eax)\n"
        "movl -0x90(%ebp), %edx\n" /* line 303 */
        "movl %edx, 4(%eax)\n"
        "movl -0x98(%ebp), %eax\n" /* line 304 */
        "addl -0xa4(%ebp), %eax\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "addl $0xac, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2bb652_002bb8e7:\n"
        "movl 8(%ebp), %edx\n" /* this */
        "jmp .Lf2bb652_002bb695\n"
        /* { scope 1 */
        ".Lf2bb652_002bb8ef:\n"
        "leal (%eax, %eax), %edx\n" /* line 271 | __len */
        "cmpl %eax, %edx\n" /* line 272 */
        "jb .Lf2bb652_002bb907\n"
        "cmpl $0x28f5c28, %edx\n" /* line 85 */
        "jbe .Lf2bb652_002bb790\n"
        "calll __ZSt17__throw_bad_allocv\n" /* line 86 */
        ".Lf2bb652_002bb907:\n"
        "movl $0x28f5c28, %edx\n" /* line 272 */
        "jmp .Lf2bb652_002bb790\n"
        /* } scope */
        /* { scope 1 */
        ".Lf2bb652_002bb911:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2bb652_002bb719\n"
        "leal -0x1c(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2bb652_002bb719\n"
        ".Lf2bb652_002bb940:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2bb652_002bb735\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2bb652_002bb735\n"
        ".Lf2bb652_002bb96f:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2bb652_002bb727\n"
        "leal -0x1b(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2bb652_002bb727\n"
        ".Lf2bb652_002bb99e:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2bb652_002bb743\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2bb652_002bb743\n"
        /* } scope */
        /* { scope 1 */
        ".Lf2bb652_002bb9cd:\n"
        "movl $str_00215858, (%esp)\n" /* line 266 */
        "calll __ZSt20__throw_length_errorPKc\n"
        "movl %eax, -0x9c(%ebp)\n"
        /* } scope */
        /* { scope 1 */
        "movl -0x4c(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "cmpl %ebx, %esi\n" /* line 224 */
        "jne .Lf2bb652_002bbcee\n"
        ".Lf2bb652_002bb9ed:\n"
        "movl -0x50(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "cmpl %ebx, %esi\n" /* line 224 */
        "jne .Lf2bb652_002bbcbf\n"
        ".Lf2bb652_002bb9fb:\n"
        "movl -0x60(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "cmpl %ebx, %esi\n" /* line 224 */
        "jne .Lf2bb652_002bbc90\n"
        ".Lf2bb652_002bba09:\n"
        "movl -0x68(%ebp), %edx\n" /* line 273 | __last */
        "movl -0x6c(%ebp), %ecx\n"
        "movl %ecx, %eax\n"
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf2bb652_002bba1c\n"
        ".Lf2bb652_002bba15:\n"
        "addl $0x10, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf2bb652_002bba15\n"
        ".Lf2bb652_002bba1c:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf2bb652_002bbc0d\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        "jmp .Lf2bb652_002bbc0d\n"
        "movl %eax, -0x9c(%ebp)\n"
        /* } scope */
        /* { scope 1 */
        ".Lf2bb652_002bba37:\n"
        "leal 0x30(%ebx), %eax\n" /* line 135 */
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        ".Lf2bb652_002bba42:\n"
        "leal 0x20(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        ".Lf2bb652_002bba4d:\n"
        "leal 0x14(%ebx), %ecx\n" /* this */
        /* { scope 2 */
        "movl 4(%ecx), %edx\n" /* line 273 | __last */
        "movl 0x14(%ebx), %eax\n"
        /* { scope 3 */
        "cmpl %eax, %edx\n" /* line 173 */
        "je .Lf2bb652_002bba61\n"
        ".Lf2bb652_002bba5a:\n"
        "addl $0x10, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf2bb652_002bba5a\n"
        /* } scope */
        ".Lf2bb652_002bba61:\n"
        "movl (%ecx), %eax\n" /* line 109 */
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf2bb652_002bba6f\n"
        /* { scope 3 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        /* } scope */
        ".Lf2bb652_002bba6f:\n"
        "movl -0x9c(%ebp), %edx\n" /* line 105 */
        "movl %edx, (%esp)\n"
        "calll __Unwind_Resume\n"
        "movl %eax, -0x9c(%ebp)\n"
        "leal 0x34(%ebx), %eax\n" /* line 135 */
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "jmp .Lf2bb652_002bba37\n"
        "movl %eax, (%esp)\n" /* line 89 */
        "calll ___cxa_begin_catch\n"
        "movl -0x8c(%ebp), %ebx\n" /* line 91 */
        /* { scope 2 */
        "cmpl %ebx, -0x90(%ebp)\n" /* line 121 */
        "je .Lf2bb652_002bbaff\n"
        ".Lf2bb652_002bbaa6:\n"
        "leal 0x38(%ebx), %eax\n" /* line 135 */
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "leal 0x34(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "leal 0x30(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "leal 0x20(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "leal 0x14(%ebx), %ecx\n" /* this */
        /* { scope 3 */
        "movl 4(%ecx), %edx\n" /* line 273 | __last */
        "movl 0x14(%ebx), %eax\n"
        /* { scope 4 */
        "cmpl %eax, %edx\n" /* line 173 */
        "je .Lf2bb652_002bbae6\n"
        ".Lf2bb652_002bbadf:\n"
        "addl $0x10, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf2bb652_002bbadf\n"
        /* } scope */
        ".Lf2bb652_002bbae6:\n"
        "movl (%ecx), %eax\n" /* line 109 */
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf2bb652_002bbaf4\n"
        /* { scope 4 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        /* } scope */
        ".Lf2bb652_002bbaf4:\n"
        "addl $0x64, %ebx\n" /* line 623 */
        "cmpl -0x90(%ebp), %ebx\n" /* line 121 */
        "jne .Lf2bb652_002bbaa6\n"
        /* } scope */
        ".Lf2bb652_002bbaff:\n"
        "calll ___cxa_rethrow\n" /* line 92 */
        "movl %eax, -0x9c(%ebp)\n"
        ".Lf2bb652_002bbb0a:\n"
        "movl -0x9c(%ebp), %edx\n" /* line 292 */
        "movl %edx, (%esp)\n"
        "calll ___cxa_begin_catch\n"
        "movl -0x98(%ebp), %ebx\n" /* line 294 */
        "movl -0x8c(%ebp), %eax\n" /* line 173 */
        "cmpl %eax, %ebx\n"
        "je .Lf2bb652_002bbb81\n"
        ".Lf2bb652_002bbb28:\n"
        "leal 0x38(%ebx), %eax\n" /* line 135 */
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "leal 0x34(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "leal 0x30(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "leal 0x20(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "leal 0x14(%ebx), %ecx\n" /* this */
        /* { scope 2 */
        "movl 4(%ecx), %edx\n" /* line 273 | __last */
        "movl 0x14(%ebx), %eax\n"
        /* { scope 3 */
        "cmpl %eax, %edx\n" /* line 173 */
        "je .Lf2bb652_002bbb68\n"
        ".Lf2bb652_002bbb61:\n"
        "addl $0x10, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf2bb652_002bbb61\n"
        /* } scope */
        ".Lf2bb652_002bbb68:\n"
        "movl (%ecx), %eax\n" /* line 109 */
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf2bb652_002bbb76\n"
        /* { scope 3 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        /* } scope */
        ".Lf2bb652_002bbb76:\n"
        "addl $0x64, %ebx\n" /* line 623 */
        "cmpl -0x8c(%ebp), %ebx\n" /* line 173 */
        "jne .Lf2bb652_002bbb28\n"
        ".Lf2bb652_002bbb81:\n"
        "movl -0x98(%ebp), %eax\n" /* line 122 */
        "testl %eax, %eax\n"
        "je .Lf2bb652_002bbb99\n"
        "movl -0x98(%ebp), %edx\n" /* line 94 */
        "movl %edx, (%esp)\n"
        "calll __ZdlPv\n"
        ".Lf2bb652_002bbb99:\n"
        "calll ___cxa_rethrow\n" /* line 296 */
        "movl %eax, -0x9c(%ebp)\n"
        ".Lf2bb652_002bbba4:\n"
        "leal 0x14(%ebx), %ecx\n" /* line 135 | this */
        /* { scope 2 */
        "movl 4(%ecx), %edx\n" /* line 273 | __last */
        "movl 0x14(%ebx), %eax\n"
        /* { scope 3 */
        "cmpl %eax, %edx\n" /* line 173 */
        "je .Lf2bb652_002bbbb8\n"
        ".Lf2bb652_002bbbb1:\n"
        "addl $0x10, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf2bb652_002bbbb1\n"
        /* } scope */
        ".Lf2bb652_002bbbb8:\n"
        "movl (%ecx), %eax\n" /* line 109 */
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf2bb652_002bbbce\n"
        /* { scope 3 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        "jmp .Lf2bb652_002bbbce\n"
        "movl %eax, -0x9c(%ebp)\n"
        /* } scope */
        /* } scope */
        ".Lf2bb652_002bbbce:\n"
        "calll ___cxa_end_catch\n" /* line 89 */
        "jmp .Lf2bb652_002bbb0a\n"
        "movl %eax, -0x9c(%ebp)\n"
        ".Lf2bb652_002bbbde:\n"
        "leal 0x14(%ebx), %ecx\n" /* line 135 | this */
        /* { scope 2 */
        "movl 4(%ecx), %edx\n" /* line 273 | __last */
        "movl 0x14(%ebx), %eax\n"
        /* { scope 3 */
        "cmpl %eax, %edx\n" /* line 173 */
        "je .Lf2bb652_002bbbf2\n"
        ".Lf2bb652_002bbbeb:\n"
        "addl $0x10, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf2bb652_002bbbeb\n"
        /* } scope */
        ".Lf2bb652_002bbbf2:\n"
        "movl (%ecx), %eax\n" /* line 109 */
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf2bb652_002bbc08\n"
        /* { scope 3 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        "jmp .Lf2bb652_002bbc08\n"
        "movl %eax, -0x9c(%ebp)\n"
        /* } scope */
        /* } scope */
        ".Lf2bb652_002bbc08:\n"
        "calll ___cxa_end_catch\n" /* line 292 */
        ".Lf2bb652_002bbc0d:\n"
        "movl -0x9c(%ebp), %eax\n"
        ".Lf2bb652_002bbc13:\n"
        "movl %eax, (%esp)\n"
        "calll __Unwind_Resume\n"
        "movl %eax, -0x9c(%ebp)\n"
        ".Lf2bb652_002bbc21:\n"
        "leal 0x20(%ebx), %eax\n" /* line 135 */
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "jmp .Lf2bb652_002bbbde\n"
        "movl %eax, -0x9c(%ebp)\n"
        "leal 0x34(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        ".Lf2bb652_002bbc3f:\n"
        "leal 0x30(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "jmp .Lf2bb652_002bbc21\n"
        "movl %eax, -0x9c(%ebp)\n"
        "jmp .Lf2bb652_002bbc3f\n"
        "movl %eax, -0x9c(%ebp)\n"
        ".Lf2bb652_002bbc5a:\n"
        "leal 0x20(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "jmp .Lf2bb652_002bbba4\n"
        "movl %eax, -0x9c(%ebp)\n"
        "leal 0x34(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        ".Lf2bb652_002bbc7b:\n"
        "leal 0x30(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "jmp .Lf2bb652_002bbc5a\n"
        "movl %eax, -0x9c(%ebp)\n"
        "jmp .Lf2bb652_002bbc7b\n"
        /* } scope */
        /* { scope 1 */
        ".Lf2bb652_002bbc90:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2bb652_002bba09\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2bb652_002bba09\n"
        ".Lf2bb652_002bbcbf:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2bb652_002bb9fb\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2bb652_002bb9fb\n"
        ".Lf2bb652_002bbcee:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2bb652_002bb9ed\n"
        "leal -0x1b(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2bb652_002bb9ed\n"
        "movl %eax, -0x9c(%ebp)\n"
        "jmp .Lf2bb652_002bba09\n"
        "movl %eax, -0x9c(%ebp)\n"
        "jmp .Lf2bb652_002bb9fb\n"
        "movl %eax, -0x9c(%ebp)\n"
        "jmp .Lf2bb652_002bb9ed\n"
        "movl %eax, -0x9c(%ebp)\n"
        "jmp .Lf2bb652_002bba4d\n"
        "movl %eax, -0x9c(%ebp)\n"
        "jmp .Lf2bb652_002bba42\n"
        "jmp .Lf2bb652_002bbc13\n"
        /* } scope */
        /* { scope 1 */
        "movl %eax, (%esp)\n" /* line 89 */
        "calll ___cxa_begin_catch\n"
        "movl -0x98(%ebp), %ebx\n" /* line 91 */
        /* { scope 2 */
        "cmpl %ebx, %edi\n" /* line 121 */
        "je .Lf2bb652_002bbdc0\n"
        ".Lf2bb652_002bbd6b:\n"
        "leal 0x38(%ebx), %eax\n" /* line 135 */
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "leal 0x34(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "leal 0x30(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "leal 0x20(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "leal 0x14(%ebx), %ecx\n" /* this */
        /* { scope 3 */
        "movl 4(%ecx), %edx\n" /* line 273 | __last */
        "movl 0x14(%ebx), %eax\n"
        /* { scope 4 */
        "cmpl %eax, %edx\n" /* line 173 */
        "je .Lf2bb652_002bbdab\n"
        ".Lf2bb652_002bbda4:\n"
        "addl $0x10, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf2bb652_002bbda4\n"
        /* } scope */
        ".Lf2bb652_002bbdab:\n"
        "movl (%ecx), %eax\n" /* line 109 */
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf2bb652_002bbdb9\n"
        /* { scope 4 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        /* } scope */
        ".Lf2bb652_002bbdb9:\n"
        "addl $0x64, %ebx\n" /* line 623 */
        "cmpl %ebx, %edi\n" /* line 121 */
        "jne .Lf2bb652_002bbd6b\n"
        /* } scope */
        ".Lf2bb652_002bbdc0:\n"
        "calll ___cxa_rethrow\n" /* line 92 */
        "movl %eax, -0x9c(%ebp)\n"
        /* } scope */
        /* { scope 1 */
        "movl -0x48(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %esi\n" /* line 178 */
        "cmpl %esi, %ebx\n" /* line 224 */
        "jne .Lf2bb652_002bbf2c\n"
        ".Lf2bb652_002bbddf:\n"
        "movl -0x4c(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "cmpl %ebx, %esi\n" /* line 224 */
        "jne .Lf2bb652_002bbefd\n"
        ".Lf2bb652_002bbded:\n"
        "movl -0x50(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "cmpl %ebx, %esi\n" /* line 224 */
        "jne .Lf2bb652_002bbe74\n"
        ".Lf2bb652_002bbdf7:\n"
        "movl -0x60(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "cmpl %ebx, %esi\n" /* line 224 */
        "jne .Lf2bb652_002bbe4c\n"
        ".Lf2bb652_002bbe01:\n"
        "movl -0x68(%ebp), %edx\n" /* line 273 | __last */
        "movl -0x6c(%ebp), %ecx\n"
        "movl %ecx, %eax\n"
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf2bb652_002bbe14\n"
        ".Lf2bb652_002bbe0d:\n"
        "addl $0x10, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf2bb652_002bbe0d\n"
        ".Lf2bb652_002bbe14:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf2bb652_002bba6f\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        "jmp .Lf2bb652_002bba6f\n"
        "movl %eax, -0x9c(%ebp)\n"
        /* } scope */
        /* { scope 1 */
        ".Lf2bb652_002bbe2f:\n"
        "leal 0x14(%ebx), %ecx\n" /* line 135 | this */
        /* { scope 2 */
        "movl 4(%ecx), %edx\n" /* line 273 | __last */
        "movl 0x14(%ebx), %eax\n"
        /* { scope 3 */
        "cmpl %eax, %edx\n" /* line 173 */
        "je .Lf2bb652_002bbbb8\n"
        ".Lf2bb652_002bbe40:\n"
        "addl $0x10, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf2bb652_002bbe40\n"
        "jmp .Lf2bb652_002bbbb8\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1 */
        ".Lf2bb652_002bbe4c:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2bb652_002bbe01\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2bb652_002bbe01\n"
        ".Lf2bb652_002bbe74:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2bb652_002bbdf7\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2bb652_002bbdf7\n"
        "movl %eax, -0x9c(%ebp)\n"
        ".Lf2bb652_002bbea9:\n"
        "movl -0x68(%ebp), %edx\n" /* line 273 | __last */
        "movl -0x6c(%ebp), %ecx\n"
        "movl %ecx, %eax\n"
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf2bb652_002bba1c\n"
        ".Lf2bb652_002bbeb9:\n"
        "addl $0x10, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf2bb652_002bbeb9\n"
        "jmp .Lf2bb652_002bba1c\n"
        "movl %eax, -0x9c(%ebp)\n"
        ".Lf2bb652_002bbecb:\n"
        "movl -0x60(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "cmpl %ebx, %esi\n" /* line 224 */
        "je .Lf2bb652_002bbea9\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2bb652_002bbea9\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2bb652_002bbea9\n"
        ".Lf2bb652_002bbefd:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2bb652_002bbded\n"
        "leal -0x1b(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2bb652_002bbded\n"
        ".Lf2bb652_002bbf2c:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2bb652_002bbddf\n"
        "leal -0x1c(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2bb652_002bbddf\n"
        "movl %eax, -0x9c(%ebp)\n"
        ".Lf2bb652_002bbf61:\n"
        "movl -0x50(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "cmpl %ebx, %esi\n" /* line 224 */
        "je .Lf2bb652_002bbecb\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2bb652_002bbecb\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2bb652_002bbecb\n"
        "movl %eax, -0x9c(%ebp)\n"
        "movl -0x4c(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "cmpl %ebx, %esi\n" /* line 224 */
        "je .Lf2bb652_002bbf61\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2bb652_002bbf61\n"
        "leal -0x1b(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2bb652_002bbf61\n"
        "movl %eax, -0x9c(%ebp)\n"
        /* } scope */
        /* { scope 1 */
        ".Lf2bb652_002bbfdc:\n"
        "leal 0x20(%ebx), %eax\n" /* line 135 */
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "jmp .Lf2bb652_002bbe2f\n"
        "movl %eax, -0x9c(%ebp)\n"
        "leal 0x34(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        ".Lf2bb652_002bbffd:\n"
        "leal 0x30(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSsD1Ev\n"
        "jmp .Lf2bb652_002bbfdc\n"
        "movl %eax, -0x9c(%ebp)\n"
        "jmp .Lf2bb652_002bbffd\n"
    );
}
#else
void ZNSt6vectorI12CDisplayInfoSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_(void) /* std_vector<CDisplayInfo, std_allocator<CDisplayInfo> >__M_insert_aux */
{ }
#endif
