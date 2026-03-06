/* Platform stubs for agl (macOS → Linux) */
#include "agl_stubs.h"
#include <GL/gl.h>
#include <dlfcn.h>
#include <stdio.h>
#include <sys/time.h>

static long long get_ms(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

/* Intercept glProgramStringARB to report ARB program compilation errors */
void glProgramStringARB(unsigned int target, unsigned int format, int len, const void *string)
{
    typedef void (*fn_t)(unsigned int, unsigned int, int, const void *);
    static fn_t real_glProgramStringARB = NULL;
    if (!real_glProgramStringARB)
        real_glProgramStringARB = (fn_t)dlsym(RTLD_NEXT, "glProgramStringARB");

    if (!real_glProgramStringARB) {
        fprintf(stderr, "[ARB] glProgramStringARB not found via dlsym!\n");
        return;
    }

    real_glProgramStringARB(target, format, len, string);

    /* Check for compilation error */
    int pos = -1;
    glGetIntegerv(0x864B /* GL_PROGRAM_ERROR_POSITION_ARB */, &pos);
    const char *err = (const char *)glGetString(0x8874 /* GL_PROGRAM_ERROR_STRING_ARB */);

    static int prog_count = 0;
    prog_count++;
    if (pos != -1) {
        fprintf(stderr, "[ARB #%d] COMPILE ERROR at char %d (target=0x%x len=%d): %s\n",
                prog_count, pos, target, len, err ? err : "(null)");
        /* print context around error position */
        const char *prog = (const char *)string;
        int start = pos > 60 ? pos - 60 : 0;
        fprintf(stderr, "[ARB #%d] near: \"%.120s\"\n", prog_count, prog + start);
    } else {
        fprintf(stderr, "[ARB #%d] OK (target=0x%x len=%d)\n", prog_count, target, len);
    }
    /* consume any spurious GL error from glGetString on non-error path */
    glGetError();
}

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

extern void *sdl_gl_window; /* SDL_Window*, exposed from macos_compat.c */
void SDL_GL_SwapWindow(void *window);

typedef void (*PFNGLBINDFRAMEBUFFEREXTPROC)(unsigned int target, unsigned int framebuffer);
typedef void (*PFNGLBLITFRAMEBUFFEREXTPROC)(int srcX0, int srcY0, int srcX1, int srcY1,
    int dstX0, int dstY0, int dstX1, int dstY1, unsigned int mask, unsigned int filter);
extern void *SDL_GL_GetProcAddress(const char *proc);

void aglSwapBuffers(AGLContext ctx)
{
    if (!sdl_gl_window)
        return;

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
