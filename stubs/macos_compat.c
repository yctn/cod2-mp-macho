/* macOS libc compatibility stubs for Linux */
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include "stubs/gcc40_compat.h"

/* Forward declaration for ___maskrune */
static unsigned int bsd_rune_data[13 + 256];

/* macOS ___tolower / ___maskrune are used by naked ASM code */
int ___tolower(int c) { return tolower(c); }
int ___maskrune(int c, unsigned long f) {
    /* Look up BSD __runetype and mask with requested flags */
    if ((unsigned int)c > 0xFF) return 0;
    unsigned int *rt = &bsd_rune_data[13]; /* __runetype at offset 0x34 */
    return rt[(unsigned char)c] & f;
}

/* Mac threading */
int pthread_main_np(void) { return 1; }

/* Mac timing functions used by WinSleep (now replaced, but some ASM still refs) */
typedef struct { unsigned int hi; unsigned int lo; } AbsoluteTime;
AbsoluteTime UpTime(void) { AbsoluteTime t = {0,0}; return t; }
AbsoluteTime AddDurationToAbsolute(int duration, AbsoluteTime absTime) { return absTime; }
int MPDelayUntil(AbsoluteTime *expiration) { return 0; }
void Microseconds(long long *us) { 
    struct timeval tv;
    gettimeofday(&tv, 0);
    *us = (long long)tv.tv_sec * 1000000LL + tv.tv_usec;
}

/* Mac memory */
void *NewPtrClear(long size) { return calloc(1, size); }
void DisposePtr(void *p) { free(p); }

/* Mac Toolbox atomic ops (used by unconverted ASM) */
int OTAtomicAdd32(int val, volatile int *addr) {
    return cod2_sync_add_and_fetch_i32(addr, val);
}
int OTCompareAndSwap32(int oldVal, int newVal, volatile int *addr) {
    return cod2_sync_bool_compare_and_swap_i32(addr, oldVal, newVal);
}

/* ___isnanf - macOS mangling of isnanf */
int ___isnanf(float f) { return isnan(f); }

/* ___toupper */
int ___toupper(int c) { return toupper(c); }

/* ___dynamic_cast is handled in cpp_compat.S */

/* ___sF - macOS stdio FILE array (stdin/stdout/stderr) */
/* ASM references patched to use Linux stdin/stdout/stderr directly */
/* Keep symbol defined to avoid link errors from any remaining refs */
void *___sF[3] = {0, 0, 0};

/*
 * BSD _DefaultRuneLocale compatibility for macOS ctype.
 * macOS code accesses __runetype[c] at offset 0x34 from base:
 *   movl __DefaultRuneLocale, %eax    (load import pointer)
 *   movl 0x34(%eax, %edx, 4), %eax   (load __runetype[edx])
 *
 * Flag bits used by the code:
 *   bit  8 (0x0100) = _CTYPE_A (alpha)     - shrl $8 + andl $1
 *   bit 10 (0x0400) = _CTYPE_D (digit)     - testl $0x500, testb $4 at +1
 *   bit 14 (0x4000) = _CTYPE_S (space)     - shrl $0xe + andl $1
 *   bit  2 (0x0004) = old BSD _N (digit)   - C code: & 4
 */
static unsigned int bsd_rune_data[13 + 256]; /* 0x34 header + __runetype[256] */
void *__DefaultRuneLocale;

__attribute__((constructor))
static void init_rune_locale(void) {
    unsigned int *rt = &bsd_rune_data[13]; /* __runetype starts at offset 0x34 */
    int i;

    __DefaultRuneLocale = bsd_rune_data;

    /* Control characters 0x00-0x1f, 0x7f */
    for (i = 0; i < 0x20; i++)
        rt[i] = 0x0200;
    rt[0x7f] = 0x0200;

    /* Whitespace: \t \n \v \f \r */
    rt['\t'] |= 0x4000 | 0x20000 | 0x08 | 0x80;  /* space + blank */
    rt['\n'] |= 0x4000 | 0x08;
    rt['\v'] |= 0x4000 | 0x08;
    rt['\f'] |= 0x4000 | 0x08;
    rt['\r'] |= 0x4000 | 0x08;

    /* Space (0x20): space + blank + print */
    rt[' '] = 0x4000 | 0x20000 | 0x40000 | 0x08 | 0x80;

    /* Digits 0-9 */
    for (i = '0'; i <= '9'; i++)
        rt[i] = 0x0400 | 0x0004 | 0x0800 | 0x40000 | 0x10000 | 0x40;

    /* Uppercase A-Z */
    for (i = 'A'; i <= 'Z'; i++) {
        rt[i] = 0x0100 | 0x8000 | 0x0800 | 0x40000 | 0x01;
        if (i <= 'F') rt[i] |= 0x10000 | 0x40;
    }

    /* Lowercase a-z */
    for (i = 'a'; i <= 'z'; i++) {
        rt[i] = 0x0100 | 0x1000 | 0x0800 | 0x40000 | 0x02;
        if (i <= 'f') rt[i] |= 0x10000 | 0x40;
    }

    /* Punctuation: printable non-alnum non-space */
    for (i = '!'; i <= '/'; i++)
        rt[i] = 0x2000 | 0x0800 | 0x40000 | 0x10;
    for (i = ':'; i <= '@'; i++)
        rt[i] = 0x2000 | 0x0800 | 0x40000 | 0x10;
    for (i = '['; i <= '`'; i++)
        rt[i] = 0x2000 | 0x0800 | 0x40000 | 0x10;
    for (i = '{'; i <= '~'; i++)
        rt[i] = 0x2000 | 0x0800 | 0x40000 | 0x10;
}

/*
 * sDisplayList initialization for Linux.
 * On Mac, MacDisplay_Initialize populates sDisplayList via CGGetActiveDisplayList.
 * On Linux, we provide a dummy display entry with standard display modes.
 *
 * sDisplayList is a CDisplayList (std::vector-like): { CDisplayInfo *data; CDisplayInfo *end; CDisplayInfo *capacity; }
 * Each CDisplayInfo entry is 100 bytes with fields accessed by MacDisplay_Get* at known offsets:
 *   0x14: pointer to mode array start
 *   0x18: pointer to mode array end  (numModes = (end - start) / 16)
 *   0x2c: card type
 *   0x30: GL vendor string pointer
 *   0x34: GL renderer string pointer
 *   0x38: GL extensions string pointer
 *   0x3c: video memory (bytes)
 *   0x40: texture memory (bytes)
 *   0x44: max texture units
 *   0x48: max texture image units
 *
 * Each display mode is 16 bytes: { uint32 width, height, depth, refreshRate }
 */
extern unsigned char sDisplayList[12]; /* from bss.c */
extern int sInWindowMode; /* from bss.c - force windowed mode to avoid GDHandle NULL deref */

/* Display mode: { width, height, depth, refreshRate } - 16 bytes each */
struct DisplayMode {
    unsigned int width;
    unsigned int height;
    unsigned int depth;
    unsigned int refreshRate;
};

static struct DisplayMode dummy_modes[] = {
    {  640,  480, 32, 60 },
    {  800,  600, 32, 60 },
    { 1024,  768, 32, 60 },
    { 1152,  864, 32, 60 },
    { 1280,  720, 32, 60 },
    { 1280,  800, 32, 60 },
    { 1280, 1024, 32, 60 },
    { 1440,  900, 32, 60 },
    { 1600, 1200, 32, 60 },
    { 1680, 1050, 32, 60 },
    { 1920, 1080, 32, 60 },
    { 1920, 1200, 32, 60 },
};

static const char dummy_gl_vendor[] = "Linux OpenGL";
static const char dummy_gl_renderer[] = "OpenGL";
static const char dummy_gl_extensions[] = "";

static unsigned char dummy_display_entry[100];

__attribute__((constructor))
static void init_display_list(void) {
    int i;
    int num_modes = sizeof(dummy_modes) / sizeof(dummy_modes[0]);

    /* Zero the entry first */
    for (i = 0; i < 100; i++)
        dummy_display_entry[i] = 0;

    /* Mode array pointers (offset 0x14 and 0x18) */
    *(void **)&dummy_display_entry[0x14] = &dummy_modes[0];
    *(void **)&dummy_display_entry[0x18] = &dummy_modes[num_modes];

    /* Card type (offset 0x2c) - 0 = unknown, safe */

    /* GL strings (offset 0x30, 0x34, 0x38) - avoid NULL dereference */
    *(const char **)&dummy_display_entry[0x30] = dummy_gl_vendor;
    *(const char **)&dummy_display_entry[0x34] = dummy_gl_renderer;
    *(const char **)&dummy_display_entry[0x38] = dummy_gl_extensions;

    /* Video/texture memory in bytes (offset 0x3c, 0x40) - 256MB */
    *(unsigned int *)&dummy_display_entry[0x3c] = 256 * 1024 * 1024;
    *(unsigned int *)&dummy_display_entry[0x40] = 256 * 1024 * 1024;

    /* Max texture units (offset 0x44, 0x48) */
    *(unsigned int *)&dummy_display_entry[0x44] = 8;
    *(unsigned int *)&dummy_display_entry[0x48] = 8;

    /* PC pixel shader version (offset 0x4c) - D3DPS_VERSION(2,0) = 0xffff0200
     * Report PS 2.0 so the renderer uses the shader path instead of the no-shader fallback */
    *(unsigned int *)&dummy_display_entry[0x4c] = 0xffff0200;

    /* Force windowed mode to avoid NULL GDHandle dereference in CenterWindowOnDisplay */
    sInWindowMode = 1;

    /* sDisplayList vector: { data, end, capacity } */
    *(void **)&sDisplayList[0] = dummy_display_entry;
    *(void **)&sDisplayList[4] = dummy_display_entry + 100;
    *(void **)&sDisplayList[8] = dummy_display_entry + 100;
}

/*
 * MacDisplay_CreateScreenContext replacement for Linux.
 * Creates an SDL OpenGL window and context instead of using macOS CGL.
 * The context ref is a 16-byte struct: { void *glContext, void *unused1, void *unused2, char hasAux }
 */
SDL_Window *sdl_gl_window = NULL;
int sdl_gl_width = 640;
int sdl_gl_height = 480;

static int sdl_quit_watch(void *ud, SDL_Event *e)
{
    (void)ud;
    if (e->type == SDL_QUIT) _exit(0);
    return 0;
}
static SDL_GLContext sdl_gl_context = NULL;

typedef void *ContextRef;
typedef int Boolean;

ContextRef MacDisplay_CreateScreenContext(int inDepthSize, int inUseStencil,
    int inMultiSampleType, int inMultiSampleQuality,
    int inPresentationInterval, Boolean *outHasAuxBuffer)
{
    unsigned char *ctx;

    if (outHasAuxBuffer)
        *outHasAuxBuffer = 0;

    /* Set OpenGL attributes */
    /* Request compatibility profile — game uses ARB_fragment_program / ARB_vertex_program
     * which are not available in core profile contexts */
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 0); /* no alpha = no compositor transparency */
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, inDepthSize ? inDepthSize : 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, inUseStencil ? 8 : 0);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    if (!sdl_gl_window) {
        sdl_gl_window = SDL_CreateWindow("CoD2",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            sdl_gl_width, sdl_gl_height,
            SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
        if (!sdl_gl_window)
            return (ContextRef)0;
        /* Exit immediately on window close regardless of game loop speed */
        SDL_AddEventWatch(sdl_quit_watch, NULL);
    }

    sdl_gl_context = SDL_GL_CreateContext(sdl_gl_window);
    if (!sdl_gl_context)
        return (ContextRef)0;

    /* Initial clear to solid black so the window isn't transparent garbage */
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    SDL_GL_SwapWindow(sdl_gl_window);

    /* Allocate a fake 16-byte context struct (matches what the Mac code allocates) */
    ctx = (unsigned char *)calloc(1, 16);
    /* Store the SDL context pointer so we can use it later */
    *(void **)&ctx[0] = sdl_gl_context;

    return (ContextRef)ctx;
}

static int swap_diag = 0;
void MacDisplay_SwapContext(ContextRef ctx)
{
    if (swap_diag < 5) {
        fprintf(stderr, "[SWAP#%d] win=%p ctx=%p\n", swap_diag, sdl_gl_window, (void*)(uintptr_t)ctx);
        swap_diag++;
    }
    if (sdl_gl_window)
        SDL_GL_SwapWindow(sdl_gl_window);
}

void MacDisplay_ReleaseContext(ContextRef *ctx)
{
}

void MacDisplay_FadeIn(float duration)
{
}

void MacDisplay_FadeOut(float duration)
{
}

void MacDisplay_GetCurrentDimensions(int *outWidth, int *outHeight)
{
    if (outWidth) *outWidth = 640;
    if (outHeight) *outHeight = 480;
}
