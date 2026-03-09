#define _GNU_SOURCE
/* Platform stubs for agl (macOS → Linux) */
#include "agl_stubs.h"
#include <ucontext.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>
#include <dlfcn.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <execinfo.h>
#include <signal.h>

static void crash_handler(int sig, siginfo_t *info, void *ucontext) {
    ucontext_t *uc = (ucontext_t *)ucontext;
    unsigned int eip = uc->uc_mcontext.gregs[REG_EIP];
    unsigned int eax = uc->uc_mcontext.gregs[REG_EAX];
    unsigned int ebx = uc->uc_mcontext.gregs[REG_EBX];
    unsigned int ecx = uc->uc_mcontext.gregs[REG_ECX];
    unsigned int edx = uc->uc_mcontext.gregs[REG_EDX];
    unsigned int esp = uc->uc_mcontext.gregs[REG_ESP];
    unsigned int ebp = uc->uc_mcontext.gregs[REG_EBP];
    fprintf(stderr, "\n*** SIGSEGV at eip=0x%08x addr=%p ***\n", eip, info->si_addr);
    fprintf(stderr, "  eax=%08x ebx=%08x ecx=%08x edx=%08x esp=%08x ebp=%08x\n",
            eax, ebx, ecx, edx, esp, ebp);
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
}

static long long get_ms(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

/* Diagnostic: dump x,y,material inside RB_DrawStretchPic */
int g_rb_draw_diag_count = 0;
void diag_rb_draw(unsigned int x_hex, unsigned int y_hex, unsigned int mat_ptr)
{
    if (g_rb_draw_diag_count < 40) {
        fprintf(stderr, "RB_Draw[%d] mat=%08x x=%08x y=%08x\n",
                g_rb_draw_diag_count, mat_ptr, x_hex, y_hex);
        g_rb_draw_diag_count++;
    }
}

/* Diagnostic: dump x,y,retaddr inside R_AddCmdDrawStretchPic */
int g_addcmd_diag_count = 0;
void diag_addcmd(unsigned int x_hex, unsigned int y_hex, unsigned int retaddr)
{
    if (g_addcmd_diag_count < 40) {
        fprintf(stderr, "AddCmd[%d] x=%08x y=%08x ra=%08x\n",
                g_addcmd_diag_count, x_hex, y_hex, retaddr);
        g_addcmd_diag_count++;
    }
}

/* Intercept glDrawRangeElements to dump GL state at draw time */
void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices)
{
    typedef void (*fn_t)(GLenum, GLuint, GLuint, GLsizei, GLenum, const void *);
    static fn_t real_fn = NULL;
    if (!real_fn) real_fn = (fn_t)dlsym(RTLD_NEXT, "glDrawRangeElements");

    extern int g_draw_count;
    g_draw_count++;

    real_fn(mode, start, end, count, type, indices);
}

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
    if (!sdl_gl_window)
        return;

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
