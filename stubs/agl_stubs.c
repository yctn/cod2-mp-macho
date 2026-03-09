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

    real_fn(mode, start, end, count, type, indices);
}

/* Intercept glTexImage2D to check texture uploads */
void glTexImage2D(GLenum target, GLint level, GLint internalformat,
                  GLsizei width, GLsizei height, GLint border,
                  GLenum format, GLenum type, const void *pixels)
{
    typedef void (*fn_t)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *);
    static fn_t real_fn = NULL;
    if (!real_fn) real_fn = (fn_t)dlsym(RTLD_NEXT, "glTexImage2D");

    static int tex_log_count = 0;
    tex_log_count++;
    if (tex_log_count <= 20 || internalformat == 0x1906 || internalformat == 0x190a
        || (width == 256 && height == 128)) {
        GLint tex_id = 0;
        glGetIntegerv(0x8069, &tex_id);
        fprintf(stderr, "[teximg#%d] target=0x%x lvl=%d ifmt=0x%x %dx%d fmt=0x%x type=0x%x px=%p texid=%d\n",
                tex_log_count, target, level, internalformat, width, height,
                format, type, pixels, tex_id);
    }
    real_fn(target, level, internalformat, width, height, border, format, type, pixels);
}

/* Intercept glCompressedTexImage2DARB */
void glCompressedTexImage2DARB(GLenum target, GLint level, GLenum internalformat,
                                GLsizei width, GLsizei height, GLint border,
                                GLsizei imageSize, const void *data)
{
    typedef void (*fn_t)(GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const void *);
    static fn_t real_fn = NULL;
    if (!real_fn) real_fn = (fn_t)dlsym(RTLD_NEXT, "glCompressedTexImage2DARB");

    static int comp_log_count = 0;
    comp_log_count++;
    if (comp_log_count <= 50) {
        int nonzero = 0;
        if (data) {
            const unsigned char *p = (const unsigned char *)data;
            int check = imageSize < 256 ? imageSize : 256;
            for (int i = 0; i < check; i++) {
                if (p[i]) { nonzero = 1; break; }
            }
        }
        GLint tex_id = 0;
        glGetIntegerv(0x8069, &tex_id);
        fprintf(stderr, "[comptex#%d] ifmt=0x%x %dx%d size=%d data=%p nonzero=%d texid=%d\n",
                comp_log_count, internalformat, width, height, imageSize,
                data, nonzero, tex_id);
    }
    real_fn(target, level, internalformat, width, height, border, imageSize, data);
}

/* Intercept glTexSubImage2D to check if update path is reached */
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset,
                     GLsizei width, GLsizei height, GLenum format, GLenum type,
                     const void *pixels)
{
    typedef void (*fn_t)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const void *);
    static fn_t real_fn = NULL;
    if (!real_fn) real_fn = (fn_t)dlsym(RTLD_NEXT, "glTexSubImage2D");

    static int sub_log_count = 0;
    sub_log_count++;
    if (sub_log_count <= 30) {
        int nonzero = 0;
        if (pixels) {
            const unsigned char *p = (const unsigned char *)pixels;
            int total = width * height * 4;
            if (total > 1024) total = 1024;
            for (int i = 0; i < total; i++) {
                if (p[i]) { nonzero = 1; break; }
            }
        }
        GLint tex_id = 0;
        glGetIntegerv(0x8069, &tex_id);
        fprintf(stderr, "[texsub#%d] target=0x%x lvl=%d %dx%d fmt=0x%x type=0x%x px=%p nonzero=%d texid=%d\n",
                sub_log_count, target, level, width, height, format, type, pixels, nonzero, tex_id);
    }
    real_fn(target, level, xoffset, yoffset, width, height, format, type, pixels);
}

/* Intercept glCompressedTexSubImage2D */
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset,
                                GLsizei width, GLsizei height, GLenum format,
                                GLsizei imageSize, const void *data)
{
    typedef void (*fn_t)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const void *);
    static fn_t real_fn = NULL;
    if (!real_fn) real_fn = (fn_t)dlsym(RTLD_NEXT, "glCompressedTexSubImage2D");

    static int csub_log_count = 0;
    csub_log_count++;
    if (csub_log_count <= 30) {
        int nonzero = 0;
        if (data) {
            const unsigned char *p = (const unsigned char *)data;
            int check = imageSize < 256 ? imageSize : 256;
            for (int i = 0; i < check; i++) {
                if (p[i]) { nonzero = 1; break; }
            }
        }
        GLint tex_id = 0;
        glGetIntegerv(0x8069, &tex_id);
        fprintf(stderr, "[compsub#%d] fmt=0x%x %dx%d size=%d data=%p nonzero=%d texid=%d\n",
                csub_log_count, format, width, height, imageSize, data, nonzero, tex_id);
    }
    real_fn(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}

/* Intercept glBindTexture to trace texture bindings during rendering */
void glBindTexture(GLenum target, GLuint texture)
{
    typedef void (*fn_t)(GLenum, GLuint);
    static fn_t real_fn = NULL;
    if (!real_fn) real_fn = (fn_t)dlsym(RTLD_NEXT, "glBindTexture");

    static int tex_bind_count = 0;
    tex_bind_count++;
    extern int g_draw_count;
    /* Log during draw calls (draw=1 for init, then rendering) */
    if ((g_draw_count >= 1 && g_draw_count <= 5) || (g_draw_count > 870 && tex_bind_count <= 200)) {
        fprintf(stderr, "[texBind#%d] target=0x%x tex=%u draws=%d\n",
                tex_bind_count, target, texture, g_draw_count);
    }
    real_fn(target, texture);
}

/* Intercept glBindProgramARB to trace program bindings */
void glBindProgramARB(GLenum target, GLuint program)
{
    typedef void (*fn_t)(GLenum, GLuint);
    static fn_t real_fn = NULL;
    if (!real_fn) {
        real_fn = (fn_t)SDL_GL_GetProcAddress("glBindProgramARB");
        if (!real_fn)
            real_fn = (fn_t)dlsym(RTLD_NEXT, "glBindProgramARB");
        fprintf(stderr, "[glBindProgramARB] resolved real_fn=%p via SDL\n", real_fn);
    }

    static int bind_log_count = 0;
    bind_log_count++;
    /* Log the first 100 and then any during rendering (after swap#0) */
    extern int g_draw_count;
    if (bind_log_count <= 100 || (g_draw_count > 880 && bind_log_count <= 350)) {
        fprintf(stderr, "[bind#%d] target=0x%x program=%u draws=%d\n", bind_log_count, target, program, g_draw_count);
    }
    real_fn(target, program);
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
    /* Dump all program sources with their GL program IDs */
    static int fp_dump_count = 0, vp_dump_count = 0;
    if (target == 0x8620) { /* VP */
        vp_dump_count++;
        GLint pid = 0;
        typedef void (*glGetPFn)(GLenum, GLenum, GLint*);
        static glGetPFn glGetProgiv2 = NULL;
        if (!glGetProgiv2) glGetProgiv2 = (glGetPFn)dlsym(RTLD_NEXT, "glGetProgramivARB");
        if (glGetProgiv2) glGetProgiv2(0x8620, 0x8677, &pid);
        fprintf(stderr, "[ARB-VP gl=%d] source:\n%.*s\n---END-VP---\n", pid, len, (const char*)string);
    }
    if (target == 0x8804) {
        fp_dump_count++;
        /* Get the current program ID */
        GLint pid = 0;
        typedef void (*glGetPFn)(GLenum, GLenum, GLint*);
        static glGetPFn glGetProgiv = NULL;
        if (!glGetProgiv) glGetProgiv = (glGetPFn)dlsym(RTLD_NEXT, "glGetProgramivARB");
        if (glGetProgiv) glGetProgiv(0x8804, 0x8677, &pid);
        fprintf(stderr, "[ARB-FP gl=%d] source:\n%.*s\n---END---\n", pid, len, (const char*)string);
    }
    /* consume any spurious GL error from glGetString on non-error path */
    glGetError();
}


/* Intercept glProgramEnvParameter4fvARB to catch NaN */
void glProgramEnvParameter4fvARB(GLenum target, GLuint index, const float *params)
{
    typedef void (*fn_t)(GLenum, GLuint, const float *);
    static fn_t real_fn = NULL;
    if (!real_fn) real_fn = (fn_t)SDL_GL_GetProcAddress("glProgramEnvParameter4fvARB");
    if (!real_fn) real_fn = (fn_t)dlsym(RTLD_NEXT, "glProgramEnvParameter4fvARB");

    static int nan_count = 0;
    int has_nan = 0;
    for (int i = 0; i < 4; i++) {
        if (params[i] != params[i]) has_nan = 1; /* NaN check */
    }
    if (has_nan && nan_count < 30) {
        nan_count++;
        void *ra = __builtin_return_address(0);
        fprintf(stderr, "[ENV-NaN#%d] target=0x%x idx=%u val=[%g,%g,%g,%g] ra=%p\n",
                nan_count, target, index, params[0], params[1], params[2], params[3], ra);
    }

    /* Detect extreme matrix values in env 23-26 */
    static int extreme_log = 0;
    if (index >= 23 && index <= 26 && target == 0x8620) {
        int has_extreme = 0;
        for (int i = 0; i < 4; i++) {
            float v = params[i] < 0 ? -params[i] : params[i];
            if (v > 1e6) has_extreme = 1;
        }
        if (has_extreme && extreme_log < 3) {
            extreme_log++;
            void *ra = __builtin_return_address(0);
            extern unsigned char backEnd[];
            int stackLevel = *(int *)(backEnd + 0x2e80);
            /* Compute activeMatrices = backEnd + 0x4e0 + level * 3552 */
            unsigned char *activeMatrices = backEnd + 0x4e0 + stackLevel * 3552;
            fprintf(stderr, "[ENV-EXTREME#%d] idx=%u val=[%.6g,%.6g,%.6g,%.6g] ra=%p\n",
                    extreme_log, index, params[0], params[1], params[2], params[3], ra);
            fprintf(stderr, "  stackLevel=%d activeMatrices=%p (backEnd+0x%x)\n",
                    stackLevel, activeMatrices, (int)(activeMatrices - backEnd));
            fprintf(stderr, "  data_ptr=%p offset_from_active=0x%x\n",
                    params, (int)((unsigned char*)params - activeMatrices));
            /* Dump viewParms pointer and its matrices */
            void **vpPtr = (void **)(backEnd + 0x3c8);
            fprintf(stderr, "  viewParms ptr=%p\n", *vpPtr);
            if (*vpPtr) {
                float *vpView = (float *)((char *)*vpPtr + 0x48);
                float *vpProj = (float *)((char *)*vpPtr + 0x88);
                fprintf(stderr, "  vpView=[%.3g,%.3g,%.3g,%.3g / %.3g,%.3g,%.3g,%.3g / %.3g,%.3g,%.3g,%.3g / %.3g,%.3g,%.3g,%.3g]\n",
                        vpView[0],vpView[1],vpView[2],vpView[3],
                        vpView[4],vpView[5],vpView[6],vpView[7],
                        vpView[8],vpView[9],vpView[10],vpView[11],
                        vpView[12],vpView[13],vpView[14],vpView[15]);
                fprintf(stderr, "  vpProj=[%.3g,%.3g,%.3g,%.3g / %.3g,%.3g,%.3g,%.3g / %.3g,%.3g,%.3g,%.3g / %.3g,%.3g,%.3g,%.3g]\n",
                        vpProj[0],vpProj[1],vpProj[2],vpProj[3],
                        vpProj[4],vpProj[5],vpProj[6],vpProj[7],
                        vpProj[8],vpProj[9],vpProj[10],vpProj[11],
                        vpProj[12],vpProj[13],vpProj[14],vpProj[15]);
            }
            /* Dump the active matrices View (+0x230) and Proj (+0x340) within activeMatrices */
            float *amView = (float *)(activeMatrices + 0x230);
            float *amProj = (float *)(activeMatrices + 0x340);
            fprintf(stderr, "  amView=[%.3g,%.3g,%.3g,%.3g / %.3g,%.3g,%.3g,%.3g / %.3g,%.3g,%.3g,%.3g / %.3g,%.3g,%.3g,%.3g]\n",
                    amView[0],amView[1],amView[2],amView[3],
                    amView[4],amView[5],amView[6],amView[7],
                    amView[8],amView[9],amView[10],amView[11],
                    amView[12],amView[13],amView[14],amView[15]);
            fprintf(stderr, "  amProj=[%.3g,%.3g,%.3g,%.3g / %.3g,%.3g,%.3g,%.3g / %.3g,%.3g,%.3g,%.3g / %.3g,%.3g,%.3g,%.3g]\n",
                    amProj[0],amProj[1],amProj[2],amProj[3],
                    amProj[4],amProj[5],amProj[6],amProj[7],
                    amProj[8],amProj[9],amProj[10],amProj[11],
                    amProj[12],amProj[13],amProj[14],amProj[15]);
        }
    }

    /* Also log first few calls for all env params */
    static int env_log = 0;
    if (env_log < 80 || (index >= 23 && index <= 26 && env_log < 200)) {
        env_log++;
        fprintf(stderr, "[ENV#%d] target=0x%x idx=%u val=[%.6g,%.6g,%.6g,%.6g]\n",
                env_log, target, index, params[0], params[1], params[2], params[3]);
    }
    real_fn(target, index, params);
}

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

    /* Pump OS events here so the close button works even if IN_Frame is slow */
    SDL_PumpEvents();

    extern int g_draw_count;
    extern int g_rb_exec_count;
    extern int g_addcmd_count;
    extern int g_rb_dispatch_count;
    extern int g_rb_first_cmd;
    extern int g_rb_skip_reason;
    extern int g_rb_endsurface_count;
    extern int g_rb_endsurface_notechnique;
    extern int g_rb_endsurface_dxstate;
    extern int g_rb_endsurface_draw;
    static int swap_diag = 0;
    int do_diag = (swap_diag < 10 || (swap_diag >= 436 && swap_diag < 445));
    if (do_diag) {
        unsigned char px[4] = {0};
        GLint vp[4] = {0};
        GLint prog_v = 0, prog_f = 0;
        GLboolean depth_test = 0, blend = 0, cull = 0;
        GLint fbo = 0;
        glGetIntegerv(0xba2 /*GL_VIEWPORT*/, vp);
        glGetIntegerv(0x8626 /*GL_VERTEX_PROGRAM_BINDING_ARB*/, &prog_v);
        glGetIntegerv(0x8677 /*GL_FRAGMENT_PROGRAM_BINDING_ARB*/, &prog_f);
        depth_test = glIsEnabled(0xb71 /*GL_DEPTH_TEST*/);
        blend = glIsEnabled(0xbe2 /*GL_BLEND*/);
        cull = glIsEnabled(0xb44 /*GL_CULL_FACE*/);
        glGetIntegerv(0x8ca6 /*GL_DRAW_FRAMEBUFFER_BINDING*/, &fbo);
        glReadBuffer(0x405 /*GL_BACK*/);
        glReadPixels(vp[0]+vp[2]/2, vp[1]+vp[3]/2, 1, 1, 0x1908, 0x1401, px);
        /* also sample a few other spots */
        unsigned char px2[4] = {0}, px3[4] = {0};
        glReadPixels(vp[0]+10, vp[1]+10, 1, 1, 0x1908, 0x1401, px2);
        glReadPixels(vp[0]+vp[2]-10, vp[1]+vp[3]-10, 1, 1, 0x1908, 0x1401, px3);
        glGetError(); /* clear */
        fprintf(stderr, "[swap#%d] vp=(%d,%d,%d,%d) fbo=%d px=(%d,%d,%d,%d) corners=(%d,%d,%d)/(%d,%d,%d)\n",
                swap_diag, vp[0],vp[1],vp[2],vp[3], fbo,
                px[0],px[1],px[2],px[3],
                px2[0],px2[1],px2[2], px3[0],px3[1],px3[2]);
        extern int g_dip_enter, g_dip_is_tri, g_dip_drawflag_zero;
        extern int g_dip_numelems_zero, g_dip_gl_draw;
        extern int g_dip_last_numelems, g_dip_last_mode;
        extern int g_fp_enable_count, g_fp_bind_count, g_vp_enable_count;
        extern int g_dip_vs_null, g_dip_vs_bound, g_dip_vs_skip;
        extern int g_svs_count;
        fprintf(stderr, "  DIP: dflag0=%d glDraw=%d isTri=%d | vp=%d fp_en=%d fp_bind=%d\n",
                g_dip_drawflag_zero, g_dip_gl_draw, g_dip_is_tri,
                g_vp_enable_count, g_fp_enable_count, g_fp_bind_count);
        fprintf(stderr, "  VP: svs=%d vsSkip=%d vsNull=%d vsBound=%d\n",
                g_svs_count, g_dip_vs_skip, g_dip_vs_null, g_dip_vs_bound);
        fprintf(stderr, "  draws=%d endsurf=%d drw=%d vprog=%d fprog=%d depth=%d blend=%d cull=%d\n",
                g_draw_count, g_rb_endsurface_count, g_rb_endsurface_draw,
                prog_v, prog_f, depth_test, blend, cull);
        swap_diag++;
    }

    /* Diagnostic: read game's rendering output (read-only, no state changes!) */
    if (do_diag) {
        while (glGetError() != 0) {}

        unsigned char game_px[4] = {0};
        glReadPixels(320, 240, 1, 1, 0x1908, 0x1401, game_px);

        GLboolean vp_en = glIsEnabled(0x8620);
        GLboolean fp_en = glIsEnabled(0x8804);

        fprintf(stderr, "[diag#%d] game_px=(%d,%d,%d,%d) vp=%d fp=%d\n",
                swap_diag, game_px[0],game_px[1],game_px[2],game_px[3],
                vp_en, fp_en);
    }

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
