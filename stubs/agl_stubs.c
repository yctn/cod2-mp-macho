#define _GNU_SOURCE
/* Platform stubs for agl (macOS → Linux) */
#include "agl_stubs.h"
#ifndef __EMSCRIPTEN__
#include <ucontext.h>
#include <GL/gl.h>
#include <dlfcn.h>
#include <execinfo.h>
#include <sys/mman.h>
#endif
#include <SDL2/SDL.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>

#ifndef __EMSCRIPTEN__
static void crash_handler(int sig, siginfo_t *info, void *ucontext) {
    ucontext_t *uc = (ucontext_t *)ucontext;
    unsigned int eip = uc->uc_mcontext.gregs[REG_EIP];
    unsigned int eax = uc->uc_mcontext.gregs[REG_EAX];
    unsigned int ebx = uc->uc_mcontext.gregs[REG_EBX];
    unsigned int ecx = uc->uc_mcontext.gregs[REG_ECX];
    unsigned int edx = uc->uc_mcontext.gregs[REG_EDX];
    unsigned int esp = uc->uc_mcontext.gregs[REG_ESP];
    unsigned int ebp = uc->uc_mcontext.gregs[REG_EBP];
    unsigned int addr = (unsigned int)(unsigned long)info->si_addr;

    /* If the fault address is in shared library space or read-only strings,
       skip the faulting instruction.  This handles writes to stale Mac
       relocation addresses in the BSP loader ASM and DX9 stubs.
       We advance EIP past the faulting instruction (assume 2-6 byte mov). */
    /* During BSP loading, skip ALL faults.  R_LoadWorldInternal has
       stale Mac relocations that write to unmapped/read-only addresses.
       These faults also occur inside libc memcpy called from BSP code. */
    extern int g_bsp_loading;
    if (g_bsp_loading) {
        /* Redirect the write to a scratch buffer by modifying registers.
           ESI and EDI are commonly used as memcpy dest pointers.
           Also map the faulting page to a scratch area. */
        static char bsp_scratch[4*1024*1024] __attribute__((aligned(4096)));
        /* mmap the faulting page to a writable scratch page so the
           instruction can complete without modification */
        void *page = (void *)(addr & ~0xFFF);
        mmap(page, 0x1000, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_FIXED, -1, 0);
        return; /* retry the instruction — now the page is mapped */
    }

    fprintf(stderr, "\n*** SIGSEGV at eip=0x%08x addr=%p ***\n", eip, info->si_addr);
    fprintf(stderr, "  eax=%08x ebx=%08x ecx=%08x edx=%08x esp=%08x ebp=%08x\n",
            eax, ebx, ecx, edx, esp, ebp);
    unsigned int *sp = (unsigned int *)(unsigned long)esp;
    fprintf(stderr, "  stack: [esp]=%08x [esp+4]=%08x [esp+8]=%08x [esp+c]=%08x\n",
            sp[0], sp[1], sp[2], sp[3]);
    void *bt[20];
    int n = backtrace(bt, 20);
    backtrace_symbols_fd(bt, n, 2);
    _exit(139);
}
__attribute__((constructor)) static void install_crash_handler(void) {
    struct sigaction sa = {0};
    sa.sa_sigaction = crash_handler;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGSEGV, &sa, NULL);
    sigaction(SIGILL, &sa, NULL);
    sigaction(SIGBUS, &sa, NULL);
}
#endif

static long long get_ms(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

/* Intercept glDrawRangeElements to dump GL state at draw time */
#ifndef __EMSCRIPTEN__
void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices)
{
    typedef void (*fn_t)(GLenum, GLuint, GLuint, GLsizei, GLenum, const void *);
    static fn_t real_fn = NULL;
    if (!real_fn) real_fn = (fn_t)dlsym(RTLD_NEXT, "glDrawRangeElements");

    extern int g_draw_count;
    g_draw_count++;

    real_fn(mode, start, end, count, type, indices);
}
#endif

/* Intercept glTexImage2D to check texture uploads */
/* glTexImage2D interceptor disabled — was calling glGetIntegerv inside GL calls */

/* glCompressedTexImage2DARB interceptor disabled */

/* glTexSubImage2D and glCompressedTexSubImage2D interceptors disabled */

/* glBindTexture interceptor REMOVED — was breaking texture binding */

/* glBindProgramARB and glProgramStringARB interceptors removed — diagnostics only */


/* glProgramEnvParameter4fvARB interceptor REMOVED — was potentially breaking shader params */

/* Counters for DrawIndexedPrimitive flow tracing */
int g_dip_enter = 0;        /* entered DrawIndexedPrimitive */
int g_dip_is_tri = 0;       /* mode == GL_TRIANGLES */
int g_dip_drawflag_zero = 0; /* sDrawFlag was 0 → early return */
int g_dip_numelems_zero = 0; /* NumElements was 0 → skip draw */
int g_dip_gl_draw = 0;       /* reached glDrawRangeElements */
int g_dip_last_numelems = 0;
int g_dip_last_mode = 0;

/* Fragment program diagnostics */
int g_fp_enable_count = 0;
int g_fp_bind_count = 0;
int g_vp_enable_count = 0;

AGLPixelFormat aglChoosePixelFormat(void *gdevs, int ndev, const int *attribs)
{
    return (AGLPixelFormat)0; /* TODO: implement with GLX */
}

AGLContext aglCreateContext(AGLPixelFormat pix, AGLContext share)
{
    return (AGLContext)0; /* TODO: implement with GLX */
}

int aglDestroyContext(AGLContext ctx)
{
    return 1;
}

int aglSetCurrentContext(AGLContext ctx)
{
    extern SDL_Window *sdl_gl_window;
    if (sdl_gl_window && ctx) {
        SDL_GL_MakeCurrent(sdl_gl_window, (SDL_GLContext)ctx);
    }
    return 1;
}

int aglSetDrawable(AGLContext ctx, AGLDrawable draw)
{
    return 1;
}

int aglSetFullScreen(AGLContext ctx, int width, int height, int freq, int device)
{
    return 1;
}

void aglDestroyPixelFormat(AGLPixelFormat pix)
{
}

int aglUpdateContext(AGLContext ctx)
{
    return 1;
}

extern SDL_Window *sdl_gl_window; /* exposed from macos_compat.c */

void aglSwapBuffers(AGLContext ctx)
{
    static int swap_count = 0;
    if (!sdl_gl_window)
        return;

    if (swap_count++ < 10)
        fprintf(stderr, "[SEQ] aglSwapBuffers\n");
    SDL_PumpEvents();
    SDL_GL_SwapWindow(sdl_gl_window);
}

AGLError aglGetError(void)
{
    return 0; /* AGL_NO_ERROR */
}

const char * aglErrorString(AGLError code)
{
    return "no error";
}

int aglSetInteger(AGLContext ctx, GLenum pname, const GLint *params)
{
    return 1;
}

int aglGetInteger(AGLContext ctx, GLenum pname, GLint *params)
{
    if (params) *params = 0; return 1;
}

/* Fake D3D9 device removed — CDirect3D_CreateDevice now creates a real GL
   context via MacDisplay_CreateScreenContext, so the renderer init path in
   R_BeginRegistration must not be short-circuited by a pre-existing dx+8. */
