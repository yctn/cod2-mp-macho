#define _GNU_SOURCE
/* Platform stubs for agl (macOS → Linux) */
#include "agl_stubs.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>


static long long get_ms(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

/* Intercept glDrawRangeElements to dump GL state at draw time */

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
