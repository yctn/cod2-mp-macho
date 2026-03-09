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

    /* Print return address for first few draws */
    static int draw_bt_count = 0;
    if (draw_bt_count < 2) {
        draw_bt_count++;
        void *ra0 = __builtin_return_address(0);
        void *ra1 = __builtin_return_address(1);
        void *ra2 = __builtin_return_address(2);
        void *ra3 = __builtin_return_address(3);
        void *ra4 = __builtin_return_address(4);
        void *ra5 = __builtin_return_address(5);
        void *ra6 = __builtin_return_address(6);
        void *ra7 = __builtin_return_address(7);
        fprintf(stderr, "[glDraw caller #%d] ra0=%p ra1=%p ra2=%p ra3=%p ra4=%p ra5=%p ra6=%p ra7=%p\n",
                draw_bt_count, ra0, ra1, ra2, ra3, ra4, ra5, ra6, ra7);
    }

    static int draw_dump_count = 0;
    if (draw_dump_count < 3) {
        draw_dump_count++;
        GLint fp_id = 0, vp_id = 0;
        glGetIntegerv(0x8677 /*GL_FRAGMENT_PROGRAM_BINDING_ARB*/, &fp_id);
        glGetIntegerv(0x8626 /*GL_VERTEX_PROGRAM_BINDING_ARB*/, &vp_id);
        GLboolean fp_on = glIsEnabled(0x8804);
        GLboolean vp_on = glIsEnabled(0x8620);

        /* Check textures on first 4 units */
        typedef void (*glActiveTexFn)(GLenum);
        static glActiveTexFn glActiveTex = NULL;
        if (!glActiveTex) glActiveTex = (glActiveTexFn)dlsym(RTLD_NEXT, "glActiveTextureARB");
        int tex_ids[4] = {0};
        for (int i = 0; i < 4; i++) {
            if (glActiveTex) glActiveTex(0x84c0 + i);
            glGetIntegerv(0x8069, &tex_ids[i]);
        }
        if (glActiveTex) glActiveTex(0x84c0); /* restore unit 0 */

        /* Check first vertex attrib pointer */
        typedef void (*glGetVAPFn)(GLuint, GLenum, void**);
        static glGetVAPFn glGetVAP = NULL;
        if (!glGetVAP) glGetVAP = (glGetVAPFn)dlsym(RTLD_NEXT, "glGetVertexAttribPointervARB");
        void *attr0_ptr = NULL, *attr3_ptr = NULL;
        if (glGetVAP) {
            glGetVAP(0, 0x8645 /*GL_VERTEX_ATTRIB_ARRAY_POINTER*/, &attr0_ptr);
            glGetVAP(3, 0x8645, &attr3_ptr); /* attr 3 is often color */
        }

        /* Check enabled vertex attribs */
        typedef void (*glGetVAIFn)(GLuint, GLenum, GLint*);
        static glGetVAIFn glGetVAI = NULL;
        if (!glGetVAI) glGetVAI = (glGetVAIFn)dlsym(RTLD_NEXT, "glGetVertexAttribivARB");
        int attr_enabled[8] = {0};
        if (glGetVAI) {
            for (int i = 0; i < 8; i++)
                glGetVAI(i, 0x8622 /*GL_VERTEX_ATTRIB_ARRAY_ENABLED*/, &attr_enabled[i]);
        }

        /* Check VP env parameters 23-26 (transformation matrix) */
        typedef void (*glGetProgramEnvParamFn)(GLenum, GLuint, float*);
        static glGetProgramEnvParamFn glGetEnvParam = NULL;
        if (!glGetEnvParam) glGetEnvParam = (glGetProgramEnvParamFn)dlsym(RTLD_NEXT, "glGetProgramEnvParameterfvARB");
        float env23[4] = {0}, env24[4] = {0};
        if (glGetEnvParam) {
            glGetEnvParam(0x8620, 23, env23);
            glGetEnvParam(0x8620, 24, env24);
        }

        /* Read first vertex from attrib 0 and attrib 5 */
        typedef void (*glGetVAPFn2)(GLuint, GLenum, GLint*);
        static glGetVAPFn2 glGetVAI2 = NULL;
        if (!glGetVAI2) glGetVAI2 = (glGetVAPFn2)dlsym(RTLD_NEXT, "glGetVertexAttribivARB");
        int attr5_size = 0, attr5_type = 0, attr5_stride = 0;
        void *attr5_ptr = NULL;
        if (glGetVAI2) {
            glGetVAI2(5, 0x8623 /*GL_VERTEX_ATTRIB_ARRAY_SIZE*/, &attr5_size);
            glGetVAI2(5, 0x8625 /*GL_VERTEX_ATTRIB_ARRAY_TYPE*/, &attr5_type);
            glGetVAI2(5, 0x8624 /*GL_VERTEX_ATTRIB_ARRAY_STRIDE*/, &attr5_stride);
        }
        if (glGetVAP) glGetVAP(5, 0x8645, &attr5_ptr);

        /* Try to read first vertex of attr5 */
        float attr5_val[4] = {-999,-999,-999,-999};
        if (attr5_ptr && attr_enabled[5]) {
            /* Read 4 bytes as floats if type is float */
            if (attr5_type == 0x1406) { /* GL_FLOAT */
                for (int i = 0; i < attr5_size && i < 4; i++)
                    attr5_val[i] = ((float*)attr5_ptr)[i];
            } else if (attr5_type == 0x1401) { /* GL_UNSIGNED_BYTE */
                for (int i = 0; i < attr5_size && i < 4; i++)
                    attr5_val[i] = ((unsigned char*)attr5_ptr)[i] / 255.0f;
            }
        }

        fprintf(stderr, "[draw#%d] mode=%d count=%d vp=%d fp=%d tex=[%d,%d,%d,%d]\n",
                draw_dump_count, mode, count, vp_on, fp_on,
                tex_ids[0], tex_ids[1], tex_ids[2], tex_ids[3]);
        fprintf(stderr, "[draw#%d] env23=[%.3f,%.3f,%.3f,%.3f] env24=[%.3f,%.3f,%.3f,%.3f]\n",
                draw_dump_count, env23[0],env23[1],env23[2],env23[3],
                env24[0],env24[1],env24[2],env24[3]);
        fprintf(stderr, "[draw#%d] attr5: en=%d size=%d type=0x%x stride=%d ptr=%p val=[%.3f,%.3f,%.3f,%.3f]\n",
                draw_dump_count, attr_enabled[5], attr5_size, attr5_type, attr5_stride, attr5_ptr,
                attr5_val[0], attr5_val[1], attr5_val[2], attr5_val[3]);
    }
    /* Check tess buffer and screen placement data */
    extern unsigned char tess[];
    extern unsigned char cls[];
    static int draw_state_count = 0;
    if (draw_state_count < 3) {
        float aspect_ratio_pixel = *(float *)(cls + 0x2a0a78);
        int vid_w = *(int *)(cls + 0x2a0a64);
        int vid_h = *(int *)(cls + 0x2a0a68);
        fprintf(stderr, "[drawDiag#%d] cls=%p aspect=%.6f vidW=%d vidH=%d\n",
                draw_state_count+1, cls, aspect_ratio_pixel, vid_w, vid_h);
    }
    if (draw_state_count < 5) {
        draw_state_count++;
        GLenum err = glGetError();
        GLint depth_func = 0;
        glGetIntegerv(0x0B74 /*GL_DEPTH_FUNC*/, &depth_func);
        GLboolean depth_write = 0;
        glGetBooleanv(0x0B72 /*GL_DEPTH_WRITEMASK*/, &depth_write);
        GLboolean cmask[4] = {0};
        glGetBooleanv(0x0C23 /*GL_COLOR_WRITEMASK*/, cmask);
        GLboolean depth_on = glIsEnabled(0x0B71 /*GL_DEPTH_TEST*/);
        GLboolean scissor_on = glIsEnabled(0x0C11 /*GL_SCISSOR_TEST*/);
        GLint scissor[4] = {0};
        if (scissor_on) glGetIntegerv(0x0C10 /*GL_SCISSOR_BOX*/, scissor);

        /* Read vertex position from attr0 */
        typedef void (*glGetVAPFn)(GLuint, GLenum, void**);
        static glGetVAPFn myGetVAP = NULL;
        if (!myGetVAP) myGetVAP = (glGetVAPFn)dlsym(RTLD_NEXT, "glGetVertexAttribPointervARB");
        typedef void (*glGetVAIFn2)(GLuint, GLenum, GLint*);
        static glGetVAIFn2 myGetVAI = NULL;
        if (!myGetVAI) myGetVAI = (glGetVAIFn2)dlsym(RTLD_NEXT, "glGetVertexAttribivARB");
        void *attr0_ptr = NULL;
        int attr0_stride = 0, attr0_en = 0, attr0_size = 0;
        GLint vbo_bound = 0;
        if (myGetVAP) myGetVAP(0, 0x8645, &attr0_ptr);
        if (myGetVAI) {
            myGetVAI(0, 0x8624 /*STRIDE*/, &attr0_stride);
            myGetVAI(0, 0x8622 /*ENABLED*/, &attr0_en);
            myGetVAI(0, 0x8623 /*SIZE*/, &attr0_size);
        }
        glGetIntegerv(0x8894 /*GL_ARRAY_BUFFER_BINDING*/, &vbo_bound);

        /* Read from first indexed vertex */
        float pos[3] = {-999,-999,-999};
        unsigned char *vbase = (unsigned char *)attr0_ptr;
        if (vbase && !vbo_bound && attr0_stride > 0) {
            /* Read vertex at index 'start' */
            float *vp = (float *)(vbase + start * attr0_stride);
            pos[0] = vp[0]; pos[1] = vp[1]; pos[2] = vp[2];
        }

        /* Also dump raw hex of first 16 bytes at attr0_ptr */
        unsigned int raw[4] = {0};
        if (vbase && !vbo_bound) {
            unsigned char *p = vbase + start * (attr0_stride ? attr0_stride : 64);
            raw[0] = *(unsigned int *)(p + 0);
            raw[1] = *(unsigned int *)(p + 4);
            raw[2] = *(unsigned int *)(p + 8);
            raw[3] = *(unsigned int *)(p + 12);
        }

        fprintf(stderr, "[drawstate#%d] err=%d depth=%d func=0x%x zmask=%d cmask=(%d,%d,%d,%d) scissor=%d vbo=%d\n",
                draw_state_count, err, depth_on, depth_func, depth_write,
                cmask[0],cmask[1],cmask[2],cmask[3], scissor_on, vbo_bound);
        fprintf(stderr, "  attr0: en=%d ptr=%p stride=%d size=%d start=%u pos=(%.3f,%.3f,%.3f) raw=%08x %08x %08x %08x\n",
                attr0_en, attr0_ptr, attr0_stride, attr0_size, start,
                pos[0], pos[1], pos[2], raw[0], raw[1], raw[2], raw[3]);
    }

    real_fn(mode, start, end, count, type, indices);

    /* Check for GL error after draw */
    static int post_draw_count = 0;
    if (post_draw_count < 5) {
        post_draw_count++;
        GLenum err = glGetError();
        if (err) fprintf(stderr, "[drawERR#%d] glError=0x%x after draw\n", post_draw_count, err);

        /* Read a pixel after this draw */
        unsigned char rpx[4] = {0};
        glReadPixels(320, 240, 1, 1, 0x1908, 0x1401, rpx);
        glGetError(); /* clear */
        fprintf(stderr, "[postdraw#%d] px=(%d,%d,%d,%d)\n", post_draw_count, rpx[0],rpx[1],rpx[2],rpx[3]);
    }
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

/* Intercept glBindProgramARB to trace program bindings */
void glBindProgramARB(GLenum target, GLuint program)
{
    typedef void (*fn_t)(GLenum, GLuint);
    static fn_t real_fn = NULL;
    if (!real_fn) real_fn = (fn_t)dlsym(RTLD_NEXT, "glBindProgramARB");

    static int bind_log_count = 0;
    bind_log_count++;
    /* Log the first 100 and then any during rendering (after swap#0) */
    extern int g_draw_count;
    if (bind_log_count <= 100 || (g_draw_count > 0 && bind_log_count <= 200)) {
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
        fprintf(stderr, "  DIP: dflag0=%d glDraw=%d isTri=%d | vp=%d fp_en=%d fp_bind=%d\n",
                g_dip_drawflag_zero, g_dip_gl_draw, g_dip_is_tri,
                g_vp_enable_count, g_fp_enable_count, g_fp_bind_count);
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
