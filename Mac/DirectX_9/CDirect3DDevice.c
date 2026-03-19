/* Clean CDirect3DDevice (IDirect3DDevice9) implementation for Linux */
/* Replaces Mac OpenGL-based implementation with stub/minimal implementations */
/* Original: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CDirect3DDevice.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdlib.h>
#include <string.h>
/* SDL_Window and SDL_GL_SwapWindow declared externally */
typedef struct SDL_Window SDL_Window;
extern void SDL_GL_SwapWindow(SDL_Window *window);

/* --- External vtable --- */
extern void *vtbl_CDirect3DDevice[];

/* --- External globals --- */
extern bool g_ShowShadowCookies;
extern UINT32 g_NumBlurShadowPasses;
extern bool g_RenderToShadowCookie;
extern UINT32 g_showtexid;
extern float g_scale1;
extern float g_scale2;
extern bool g_InhibitCopy;
extern bool g_NoTextureID;

/* Validation flags — asm symbol names for link compatibility */
bool __attribute__((visibility("default"))) CDirect3DDevice_mNeedsVertexShaderValidation
    __asm__("__ZN15CDirect3DDevice28mNeedsVertexShaderValidationE");
bool __attribute__((visibility("default"))) CDirect3DDevice_mNeedsTransformationValidation
    __asm__("__ZN15CDirect3DDevice30mNeedsTransformationValidationE");
bool __attribute__((visibility("default"))) CDirect3DDevice_mNeedsRasterizationValidation
    __asm__("__ZN15CDirect3DDevice29mNeedsRasterizationValidationE");

/* GaussianBlurWeights and sPointScale - statics from original */
static const float GaussianBlurWeights[5] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
static float sPointScale[3] = {0.0f, 0.0f, 0.0f};

/* --- External constructor declarations --- */
extern void CDirect3DTexture_CDirect3DTexture(const CDirect3DTexture *_this,
    UINT32 Width, UINT32 Height, UINT32 Levels, DWORD Usage, D3DFORMAT Format);
extern void CDirect3DVolumeTexture_CDirect3DVolumeTexture(const CDirect3DVolumeTexture *_this,
    UINT32 Width, UINT32 Height, UINT32 Depth, UINT32 Levels, DWORD Usage, D3DFORMAT Format);
extern void CDirect3DCubeTexture_CDirect3DCubeTexture(const CDirect3DCubeTexture *_this,
    UINT32 EdgeLength, UINT32 Levels, DWORD Usage, D3DFORMAT Format);
extern void CDirect3DVertexBuffer_CDirect3DVertexBuffer(const CDirect3DVertexBuffer *_this,
    UINT32 Length, DWORD Usage, D3DPOOL Pool);
extern void CDirect3DIndexBuffer_CDirect3DIndexBuffer(const CDirect3DIndexBuffer *_this,
    UINT32 Length, D3DFORMAT Format, DWORD Usage, D3DPOOL Pool);
extern int CDirect3DVertexDeclaration_CDirect3DVertexDeclaration(const CDirect3DVertexDeclaration *_this,
    const D3DVERTEXELEMENT9 *pVertexElements);
extern unsigned char CDirect3DVertexShader_CDirect3DVertexShader(const CDirect3DVertexShader *_this,
    const char *pSrcData);
extern void CDirect3DSurface_CDirect3DSurface(const CDirect3DSurface *_this,
    SurfaceType s, GLenum CubemapID, UINT32 Level, UINT32 Width, UINT32 Height,
    D3DFORMAT Format, const void *pSurfaceMemory, COpenGLTexture *pOpenGLTextureInfo);
extern void CDirect3DSurface_UpdateOpenGLSurfaceObject(const CDirect3DSurface *_this, int bRecreateSurface);
extern int CDirect3DSwapChain_CDirect3DSwapChain(const CDirect3DSwapChain *_this);
extern int CDirect3DSwapChain_SetBackBuffer(const CDirect3DSwapChain *_this, const IDirect3DSurface9 *pBackBuffer);

extern UINT32 MacOpenGLUtils_GetImageSizeInBytes(UINT32 Width, UINT32 Height, UINT32 Depth, UINT32 LevelCount, const D3DFORMAT *f);
extern UINT32 MacOpenGLUtils_GetPCPixelShaderVersion(void);
extern int MacDisplay_GetCardType(void);
extern void *SDL_GL_GetProcAddress(const char *proc);

/* --- Forward declarations for COpenGL functions --- */
extern unsigned int COpenGL_SetColorMaterialEnable(const COpenGL *_this, int Value);
extern unsigned int COpenGL_SetActiveTexUnit(const COpenGL *_this, UINT32 Unit);
extern unsigned int COpenGL_SetDither(const COpenGL *_this, int Value);
extern unsigned int COpenGL_SetBlendEXT(const COpenGL *_this, int ForceValidation, GLenum SrcFactorRGB, GLenum DstFactorRGB, GLenum SrcFactorAlpha, GLenum DstFactorAlpha);
extern unsigned int COpenGL_SetBlend(const COpenGL *_this, int ForceValidation, GLenum SrcFactorRGB, GLenum DstFactorRGB);
extern unsigned int COpenGL_SetLight(const COpenGL *_this, UINT32 Light, const LightInfoType *Src);
extern unsigned int COpenGL_SetTexMatrix(const COpenGL *_this, UINT32 Unit, const float *m);
extern unsigned int COpenGL_SetTexMatrixIdentity(const COpenGL *_this, UINT32 Unit);
extern unsigned int COpenGL_EnableTexCoordArray(const COpenGL *_this, UINT32 Unit, GLint Size, GLenum Type, GLsizei Stride, const unsigned int *Pointer);
extern unsigned int COpenGL_Shutdown(const COpenGL *_this);
extern unsigned int COpenGL_Init(const COpenGL *_this, UINT32 Buffers, UINT32 MaxTextureUnits, UINT32 MaxTextureImageUnits);

extern void *imp___ZN7COpenGL7sOpenGLE;  /* COpenGL::sOpenGL */
extern void *imp___ZN13COpenGLMatrix9sIdentityE;  /* COpenGLMatrix::sIdentity */

/* Helpers from CDirect3D.c */
extern void *CDirect3D_GetDirect3DInterface(void);

/* MacDisplay helpers */
extern int MacDisplay_GetSupportsSeparateBlendFunc(void);
extern int MacDisplay_GetSupportsAnisotropicFiltering(void);
extern double MacDisplay_GetMaxSupportedAnisotropy(void);
extern int MacDisplay_GetMaxTextureImageUnits(void);
extern int MacDisplay_GetMaxTextureUnits(void);
extern void MacDisplay_ReleaseContext(void *ctx);
extern void MacDisplay_SetGammaRamp(const D3DGAMMARAMP *pRamp);
extern void MacDisplay_FadeOut(int val);
extern void MacDisplay_FadeIn(float val);
extern void MacDisplay_GetCurrentDimensions(int *w, int *h);
extern void *MacDisplay_CreateScreenContext(int depth, int windowed, int stencil, int multiSample, int fsaa, int *hasAux);
extern void MacDisplay_SwapContext(void *ctx);
extern void MacDisplay_SetMode(int w, int h, int depth, int freq);
extern void MacDisplay_GetVideoMemoryInfo(int *video, int *texture);
extern const char *MacDisplay_GetGLVendor(void);
extern const char *MacDisplay_GetGLRenderer(void);
extern const char *MacDisplay_GetGLExtensions(void);
extern void game_dprintf(const char *fmt, ...);
extern void COpenGLMatrix_SetIdentity(float *m);
extern void D3DXMatrixMultiply(float *out, const float *a, const float *b);

/* --- Pixel shader stub vtable --- */
/* Minimal pixel shader object: vtable + refcount */
typedef struct {
    void **vtable;
    ULONG refCount;
} PixelShaderStub;

static HRESULT PS_QueryInterface(const void *t, const IID *i, void **p) { (void)t; (void)i; *p=(void*)t; return 0; }
static ULONG PS_AddRef(const void *t) { ((PixelShaderStub*)t)->refCount++; return ((PixelShaderStub*)t)->refCount; }
static ULONG PS_Release(const void *t) {
    PixelShaderStub *ps = (PixelShaderStub *)t;
    ULONG rc = --ps->refCount;
    if (!rc) free(ps);
    return rc;
}
static HRESULT PS_GetDevice(const void *t, void **d) { (void)t; (void)d; return 0; }
static HRESULT PS_GetFunction(const void *t, void *d, UINT *s) { (void)t; (void)d; (void)s; return 0; }
/* Enable/Disable/SetConstants for pixel shader programs */
static void PS_Enable(const void *t) { (void)t; }
static void PS_Disable(const void *t) { (void)t; }
static void PS_SetConstants(const void *t, int s, const float *d, int c, int u) { (void)t; (void)s; (void)d; (void)c; (void)u; }
static void PS_D1(void *t) { (void)t; }
static void PS_D0(void *t) { free(t); }

static void *ps_stub_vtbl[] = {
    (void*)PS_QueryInterface, (void*)PS_AddRef, (void*)PS_Release,
    (void*)PS_GetDevice, (void*)PS_GetFunction,
    (void*)PS_D1, (void*)PS_D0,
    (void*)PS_Enable, (void*)PS_Disable, (void*)PS_SetConstants
};

/* --- Query stub --- */
typedef struct {
    void **vtable;
    ULONG refCount;
} QueryStub;

static HRESULT Q_QueryInterface(const void *t, const IID *i, void **p) { (void)t; (void)i; *p=(void*)t; return 0; }
static ULONG Q_AddRef(const void *t) { ((QueryStub*)t)->refCount++; return ((QueryStub*)t)->refCount; }
static ULONG Q_Release(const void *t) {
    QueryStub *q = (QueryStub *)t;
    ULONG rc = --q->refCount;
    if (!rc) free(q);
    return rc;
}
static HRESULT Q_GetDevice(const void *t, void **d) { (void)t; (void)d; return 0; }
static int Q_GetType(const void *t) { (void)t; return 0; }
static UINT Q_GetDataSize(const void *t) { (void)t; return 0; }
static HRESULT Q_Issue(const void *t, DWORD f) { (void)t; (void)f; return 0; }
static HRESULT Q_GetData(const void *t, void *d, DWORD s, DWORD f) { (void)t; (void)d; (void)s; (void)f; return 0; }
static void Q_D1(void *t) { (void)t; }
static void Q_D0(void *t) { free(t); }

static void *query_stub_vtbl[] = {
    (void*)Q_QueryInterface, (void*)Q_AddRef, (void*)Q_Release,
    (void*)Q_GetDevice, (void*)Q_GetType, (void*)Q_GetDataSize,
    (void*)Q_Issue, (void*)Q_GetData,
    (void*)Q_D1, (void*)Q_D0
};

/* ============================================================ */
/* CDirect3DDevice struct layout (from ASM field offsets)       */
/* ============================================================ */
typedef struct {
    void **vtable;             /* 0x000 */
    ULONG refCount;            /* 0x004 */
    void *context;             /* 0x008: OpenGL context handle */
    UINT32 cardType;           /* 0x00C */
    UINT32 _pad010;            /* 0x010 */
    IDirect3DSurface9 *renderTarget;     /* 0x014: current render target surface */
    IDirect3DSurface9 *depthStencil;     /* 0x018: current depth stencil surface */
    IDirect3DSurface9 *backBuffer;       /* 0x01C: back buffer surface */
    IDirect3DSurface9 *depthBuffer;      /* 0x020: depth buffer surface */
    IDirect3DVertexBuffer9 *streams[16]; /* 0x024..0x060: stream source VBs */
    UINT streamOffsets[16];              /* 0x064..0x0A0: stream offsets */
    IDirect3DIndexBuffer9 *indexBuffer;  /* 0x0A4: current index buffer */
    UINT _pad0A8;                        /* 0x0A8: sentinel for stream source (-1) */
    UINT streamStrides[16];              /* 0x0AC..0x0E8: stream strides */
    IDirect3DSwapChain9 *swapChain;      /* 0x0EC: swap chain */
    IDirect3DSurface9 *saveSurface;      /* 0x0F0: save render target */
    IDirect3DSurface9 *saveSurface2;     /* 0x0F4: save depth surface */
    unsigned char _pad0F8[0x394 - 0x0F8];  /* padding */
    DWORD srcBlend;                      /* 0x394 */
    DWORD destBlend;                     /* 0x398 */
    DWORD srcBlendAlpha;                 /* 0x39C */
    DWORD destBlendAlpha;                /* 0x3A0 */
    DWORD _pad3A4;                       /* 0x3A4 */
    float alphaRef;                      /* 0x3A8 */
    GLenum alphaFunc;                    /* 0x3AC */
    float worldMatrix[16];               /* 0x3B0..0x3EC */
    float viewMatrix[16];                /* 0x3F0..0x42C */
    float worldViewMatrix[16];           /* 0x430..0x46C */
    unsigned char isWorldViewDirty;      /* 0x470 */
    unsigned char _pad471[3];
    float projMatrix[16];                /* 0x474..0x4B0 */
    unsigned char isProjDirty;           /* 0x4B4 */
    unsigned char _pad4B5[3];
    float texMatrix[16];                 /* 0x4B8..0x4F4 */
    UINT32 videoMemory;                  /* 0x4F8 */
    UINT32 textureMemory;                /* 0x4FC */
    UINT32 maxTextureSize;               /* 0x500 */
    UINT32 maxTextureUnits;              /* 0x504 */
    UINT32 maxTextureImageUnits;         /* 0x508 */
    DWORD alphaSrcBlend;                 /* 0x50C */
    DWORD alphaRefVal;                   /* 0x510 */
    DWORD alphaFuncVal;                  /* 0x514 */
    unsigned char alphaBlendEnable;      /* 0x518 */
    unsigned char _pad519[3];
    DWORD zEnable;                       /* 0x51C */
    DWORD zWriteEnable;                  /* 0x520 */
    DWORD fillMode;                      /* 0x524 */
    DWORD shadeMode;                     /* 0x528 */
    DWORD cullMode;                      /* 0x52C */
    DWORD lighting;                      /* 0x530 */
    DWORD zFunc;                         /* 0x534 */
    DWORD fogEnable;                     /* 0x538 */
    DWORD stencilEnable;                 /* 0x53C */
    DWORD stencilFunc;                   /* 0x540 */
    DWORD colorWriteEnable;              /* 0x544 */
    DWORD stencilRef;                    /* 0x548 */
    DWORD stencilMask;                   /* 0x54C */
    DWORD stencilWriteMask;              /* 0x550 */
    DWORD _pad554;
    DWORD sRGBWriteEnable;              /* 0x558 */
    DWORD separateAlphaBlendEnable;     /* 0x55C */
    DWORD colorWriteEnable1;            /* 0x560 */
    DWORD depthBias;                    /* 0x564 */
    DWORD stencilZFail;                 /* 0x568 */
    DWORD stencilFail;                  /* 0x56C */
    DWORD stencilPass;                  /* 0x570 */
    DWORD fogColor;                     /* 0x574 */
    DWORD fogTableMode;                 /* 0x578 */
    DWORD fogStart;                     /* 0x57C */
    DWORD fogEnd;                       /* 0x580 */
    DWORD fogDensity;                   /* 0x584 */
    DWORD tweenFactor;                  /* 0x588 */
    DWORD blendOp;                      /* 0x58C */
    DWORD colorWriteEnable2;            /* 0x590 */
    DWORD _pad594;
    DWORD _pad598;
    DWORD _pad59C;
    DWORD _pad5A0;
    DWORD _pad5A4;
    DWORD _pad5A8;
    unsigned char lights[0x44];         /* 0x5AC..0x5EF */
    UINT32 viewportX;                   /* 0x5F0 */
    UINT32 viewportY;                   /* 0x5F4 */
    UINT32 viewportW;                   /* 0x5F8 */
    UINT32 viewportH;                   /* 0x5FC */
    float viewportMinZ;                 /* 0x600 */
    float viewportMaxZ;                 /* 0x604 */
    /* 0x608: CTexStage vector { data, end, capacity } */
    void *texStageData;                 /* 0x608 */
    void *texStageEnd;                  /* 0x60C */
    void *texStageCap;                  /* 0x610 */
    unsigned char lightData[0x5A0];     /* 0x614..0xBB3 */
    UINT32 bVal1;                       /* 0xBB4 */
    IDirect3DPixelShader9 *pixelShader; /* 0xBB8 */
    UINT32 bVal3;                       /* 0xBBC */
    unsigned char _padBC0[8];           /* 0xBC0 */
    DWORD bc8Val;                       /* 0xBC8 */
    unsigned char bccPad[0x100];        /* 0xBCC+ */
} DeviceImpl;

static DWORD g_currentFVF = 0;
static float g_vsConst[256 * 4]; /* Vertex shader constant registers (256 vec4) */
static IDirect3DBaseTexture9 *g_boundTextures[8] = {0};
unsigned int g_prebind_texID = 0; /* Set by RB_EndSurface texture pre-binding */

/* ============================================================ */
/* IUnknown                                                     */
/* ============================================================ */

ULONG CDirect3DDevice_AddRef(const CDirect3DDevice *_this)
{
    DeviceImpl *dev = (DeviceImpl *)_this;
    return ++dev->refCount;
}

HRESULT CDirect3DDevice_QueryInterface(const CDirect3DDevice *_this, const IID *iid, LPVOID *ppvObj)
{
    (void)iid;
    *ppvObj = (void *)_this;
    CDirect3DDevice_AddRef(_this);
    return 0;
}

ULONG CDirect3DDevice_Release(const CDirect3DDevice *_this)
{
    DeviceImpl *dev = (DeviceImpl *)_this;
    ULONG rc = --dev->refCount;
    if (!rc) {
        /* Call deleting destructor via vtable */
        void (*dtor)(void*) = (void(*)(void*))dev->vtable[120]; /* D0 at slot [480/4]=120 */
        dtor((void*)_this);
    }
    return rc;
}

/* ============================================================ */
/* Resource Creation                                            */
/* ============================================================ */

HRESULT CDirect3DDevice_CreateTexture(const CDirect3DDevice *_this, UINT Width, UINT Height,
    UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool,
    IDirect3DTexture9 **ppTexture, HANDLE *pSharedHandle)
{
    void *tex;
    (void)_this; (void)Pool; (void)pSharedHandle;
    tex = malloc(0x68);
    CDirect3DTexture_CDirect3DTexture((const CDirect3DTexture *)tex, Width, Height, Levels, Usage, Format);
    *ppTexture = (IDirect3DTexture9 *)tex;
    return 0;
}

HRESULT CDirect3DDevice_CreateVolumeTexture(const CDirect3DDevice *_this, UINT Width, UINT Height,
    UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool,
    IDirect3DVolumeTexture9 **ppVolumeTexture, HANDLE *pSharedHandle)
{
    void *tex;
    (void)_this; (void)Pool; (void)pSharedHandle;
    tex = malloc(0x6c);
    CDirect3DVolumeTexture_CDirect3DVolumeTexture((const CDirect3DVolumeTexture *)tex, Width, Height, Depth, Levels, Usage, Format);
    *ppVolumeTexture = (IDirect3DVolumeTexture9 *)tex;
    return 0;
}

HRESULT CDirect3DDevice_CreateCubeTexture(const CDirect3DDevice *_this, UINT EdgeLength,
    UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool,
    IDirect3DCubeTexture9 **ppCubeTexture, HANDLE *pSharedHandle)
{
    void *tex;
    (void)_this; (void)Pool; (void)pSharedHandle;
    tex = malloc(0x7c);
    CDirect3DCubeTexture_CDirect3DCubeTexture((const CDirect3DCubeTexture *)tex, EdgeLength, Levels, Usage, Format);
    *ppCubeTexture = (IDirect3DCubeTexture9 *)tex;
    return 0;
}

/* Free-standing CreateVolumeTexture (non-member) */
HRESULT CreateVolumeTexture(UINT Width, UINT Height, UINT Depth, UINT Levels,
    DWORD Usage, D3DFORMAT Format, D3DPOOL Pool,
    IDirect3DVolumeTexture9 **ppVolumeTexture, HANDLE *pSharedHandle)
{
    void *tex;
    (void)Pool; (void)pSharedHandle;
    tex = malloc(0x6c);
    CDirect3DVolumeTexture_CDirect3DVolumeTexture((const CDirect3DVolumeTexture *)tex, Width, Height, Depth, Levels, Usage, Format);
    *ppVolumeTexture = (IDirect3DVolumeTexture9 *)tex;
    return 0;
}

HRESULT CDirect3DDevice_CreateVertexBuffer(const CDirect3DDevice *_this, UINT Length,
    DWORD Usage, DWORD FVF, D3DPOOL Pool,
    IDirect3DVertexBuffer9 **ppVertexBuffer, HANDLE *pSharedHandle)
{
    void *vb;
    (void)_this; (void)FVF; (void)pSharedHandle;
    vb = malloc(0x3c);
    CDirect3DVertexBuffer_CDirect3DVertexBuffer((const CDirect3DVertexBuffer *)vb, Length, Usage, Pool);
    *ppVertexBuffer = (IDirect3DVertexBuffer9 *)vb;
    return 0;
}

HRESULT CDirect3DDevice_CreateIndexBuffer(const CDirect3DDevice *_this, UINT Length,
    DWORD Usage, D3DFORMAT Format, D3DPOOL Pool,
    IDirect3DIndexBuffer9 **ppIndexBuffer, HANDLE *pSharedHandle)
{
    void *ib;
    (void)_this; (void)pSharedHandle;
    ib = malloc(0x34);
    CDirect3DIndexBuffer_CDirect3DIndexBuffer((const CDirect3DIndexBuffer *)ib, Length, Format, Usage, Pool);
    *ppIndexBuffer = (IDirect3DIndexBuffer9 *)ib;
    return 0;
}

HRESULT CDirect3DDevice_CreateVertexDeclaration(const CDirect3DDevice *_this,
    const D3DVERTEXELEMENT9 *pVertexElements, IDirect3DVertexDeclaration9 **ppDecl)
{
    void *decl;
    (void)_this;
    decl = malloc(0x10);
    CDirect3DVertexDeclaration_CDirect3DVertexDeclaration((const CDirect3DVertexDeclaration *)decl, pVertexElements);
    *ppDecl = (IDirect3DVertexDeclaration9 *)decl;
    return 0;
}

HRESULT CDirect3DDevice_CreateVertexShader(const CDirect3DDevice *_this,
    const DWORD *pFunction, IDirect3DVertexShader9 **ppShader)
{
    void *shader;
    int errorPos;
    (void)_this;
    shader = malloc(0x19c);
    CDirect3DVertexShader_CDirect3DVertexShader((const CDirect3DVertexShader *)shader, (const char *)pFunction);
    *ppShader = (IDirect3DVertexShader9 *)shader;
    glGetIntegerv(0x864b, &errorPos);
    if (errorPos != -1) {
        return 0x8876086c; /* error code */
    }
    return 0;
}

HRESULT CDirect3DDevice_CreatePixelShader(const CDirect3DDevice *_this,
    const DWORD *pFunction, IDirect3DPixelShader9 **ppShader)
{
    PixelShaderStub *ps;
    (void)_this; (void)pFunction;
    ps = (PixelShaderStub *)calloc(1, sizeof(PixelShaderStub));
    ps->vtable = ps_stub_vtbl;
    ps->refCount = 1;
    *ppShader = (IDirect3DPixelShader9 *)ps;
    return 0;
}

HRESULT CDirect3DDevice_CreatePixelShaderOpenGL(const CDirect3DDevice *_this,
    OpenGLPixelShaderType ShaderType, const long unsigned int *pSrcData,
    IDirect3DPixelShader9 **ppShader)
{
    PixelShaderStub *ps;
    (void)_this; (void)ShaderType; (void)pSrcData;
    ps = (PixelShaderStub *)calloc(1, sizeof(PixelShaderStub));
    ps->vtable = ps_stub_vtbl;
    ps->refCount = 1;
    *ppShader = (IDirect3DPixelShader9 *)ps;
    return 0;
}

HRESULT CDirect3DDevice_CreateDepthStencilSurface(const CDirect3DDevice *_this,
    UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample,
    DWORD MultisampleQuality, BOOL Discard,
    IDirect3DSurface9 **ppSurface, HANDLE *pSharedHandle)
{
    void *surfMem = NULL;
    void *surf;
    int currentTexture = 0;
    (void)_this; (void)MultiSample; (void)MultisampleQuality; (void)Discard; (void)pSharedHandle;

    if (!g_NoTextureID) {
        UINT allocW = 1, allocH = 1;
        UINT imageSize;
        while (allocH < Height) allocH <<= 1;
        while (allocW < Width) allocW <<= 1;
        imageSize = MacOpenGLUtils_GetImageSizeInBytes(allocW, allocH, 1, 1, &Format);
        surfMem = malloc(imageSize);
    }

    glGetIntegerv(0x8069, &currentTexture);
    surf = malloc(0x3c);
    CDirect3DSurface_CDirect3DSurface((const CDirect3DSurface *)surf, 0, 0, 0, Width, Height, Format, surfMem, 0);
    *ppSurface = (IDirect3DSurface9 *)surf;
    glBindTexture(0xde1, currentTexture);
    return 0;
}

HRESULT CDirect3DDevice_CreateRenderTarget(const CDirect3DDevice *_this,
    UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample,
    DWORD MultisampleQuality, BOOL Lockable,
    IDirect3DSurface9 **ppSurface, HANDLE *pSharedHandle)
{
    void *surfMem = NULL;
    void *surf;
    int currentTexture = 0;
    (void)_this; (void)MultiSample; (void)MultisampleQuality; (void)Lockable; (void)pSharedHandle;

    if (!g_NoTextureID) {
        UINT allocW = 1, allocH = 1;
        UINT imageSize;
        while (allocH < Height) allocH <<= 1;
        while (allocW < Width) allocW <<= 1;
        imageSize = MacOpenGLUtils_GetImageSizeInBytes(allocW, allocH, 1, 1, &Format);
        surfMem = malloc(imageSize);
    }

    glGetIntegerv(0x8069, &currentTexture);
    surf = malloc(0x3c);
    CDirect3DSurface_CDirect3DSurface((const CDirect3DSurface *)surf, 0, 0, 0, Width, Height, Format, surfMem, 0);
    *ppSurface = (IDirect3DSurface9 *)surf;
    glBindTexture(0xde1, currentTexture);
    return 0;
}

HRESULT CDirect3DDevice_CreateQuery(const CDirect3DDevice *_this, D3DQUERYTYPE Type, bool (*ppQuery)())
{
    QueryStub *q;
    (void)_this; (void)Type;
    if (ppQuery) {
        q = (QueryStub *)calloc(1, sizeof(QueryStub));
        q->vtable = query_stub_vtbl;
        q->refCount = 1;
        *(void **)ppQuery = (void *)q;
    }
    return 0;
}

HRESULT CDirect3DDevice_CreateOffscreenPlainSurface(const CDirect3DDevice *_this,
    UINT Width, UINT Height, D3DFORMAT Format, D3DPOOL Pool,
    IDirect3DSurface9 **ppSurface, HANDLE *pSharedHandle)
{
    CDirect3DSurface *surface;
    void *surfaceMemory;
    int currentTexture;
    UINT allocWidth;
    UINT allocHeight;
    UINT imageSize;

    (void)_this;
    (void)Pool;

    surfaceMemory = NULL;
    currentTexture = 0;

    glGetIntegerv(0x8069, &currentTexture);

    if (!g_NoTextureID) {
        allocWidth = 1;
        while (allocWidth < Width) {
            allocWidth <<= 1;
        }
        allocHeight = 1;
        while (allocHeight < Height) {
            allocHeight <<= 1;
        }
        imageSize = MacOpenGLUtils_GetImageSizeInBytes(allocWidth, allocHeight, 1, 1, &Format);
        surfaceMemory = malloc(imageSize);
    }

    surface = (CDirect3DSurface *)malloc(0x3c);
    CDirect3DSurface_CDirect3DSurface(surface, 0, 0, 0, Width, Height, Format, surfaceMemory, 0);

    if (ppSurface != NULL) {
        *ppSurface = (IDirect3DSurface9 *)surface;
    }
    if (pSharedHandle != NULL) {
        *pSharedHandle = 0;
    }

    glBindTexture(0xde1, currentTexture);
    return 0;
}

/* ============================================================ */
/* Rendering Core                                               */
/* ============================================================ */

HRESULT CDirect3DDevice_TestCooperativeLevel(const CDirect3DDevice *_this)
{
    (void)_this;
    return 0;
}

UINT CDirect3DDevice_GetAvailableTextureMem(const CDirect3DDevice *_this)
{
    DeviceImpl *dev = (DeviceImpl *)_this;
    return dev->textureMemory;
}

HRESULT CDirect3DDevice_EvictManagedResources(const CDirect3DDevice *_this)
{
    (void)_this;
    return 0;
}

HRESULT CDirect3DDevice_GetDirect3D(const CDirect3DDevice *_this, IDirect3D9 **ppD3D8)
{
    (void)_this;
    *ppD3D8 = (IDirect3D9 *)CDirect3D_GetDirect3DInterface();
    return 0;
}

HRESULT CDirect3DDevice_GetDeviceCaps(const CDirect3DDevice *_this, D3DCAPS9 *pCaps)
{
    DeviceImpl *dev = (DeviceImpl *)_this;
    int maxTexUnits, maxTexImageUnits, maxStages;
    (void)dev;

    memset(pCaps, 0, 0x130);
    *(DWORD *)((char *)pCaps + 0x00) = 1;        /* DeviceType */
    *(DWORD *)((char *)pCaps + 0x04) = dev->cardType; /* AdapterOrdinal */
    *(DWORD *)((char *)pCaps + 0x08) = 0;
    *(DWORD *)((char *)pCaps + 0x0C) = 0x30020000;
    *(DWORD *)((char *)pCaps + 0x10) = 0x120;
    *(DWORD *)((char *)pCaps + 0x14) = 0x80000001;
    *(DWORD *)((char *)pCaps + 0x18) = 1;
    *(DWORD *)((char *)pCaps + 0x1C) = 0x19bfc0;
    *(DWORD *)((char *)pCaps + 0x20) = 0xcaf2;

    if (MacDisplay_GetSupportsSeparateBlendFunc()) {
        *(DWORD *)((char *)pCaps + 0x20) |= 0x20000;
    }

    *(DWORD *)((char *)pCaps + 0x24) = 0;
    if (MacDisplay_GetSupportsAnisotropicFiltering()) {
        *(DWORD *)((char *)pCaps + 0x24) |= 0x20000;
    }
    *(DWORD *)((char *)pCaps + 0x24) |= 0x5602081;
    *(DWORD *)((char *)pCaps + 0x24) &= 0xfffeffff;
    *(DWORD *)((char *)pCaps + 0x24) |= 0x2000000;

    *(DWORD *)((char *)pCaps + 0x28) = 0xff;
    *(DWORD *)((char *)pCaps + 0x2C) = 0x7ff;
    *(DWORD *)((char *)pCaps + 0x30) = 0x7ff;
    *(DWORD *)((char *)pCaps + 0x34) = 0xff;
    *(DWORD *)((char *)pCaps + 0x38) = 0x84208;
    *(DWORD *)((char *)pCaps + 0x3C) = 0x234d07;
    *(DWORD *)((char *)pCaps + 0x40) = 0x3030300;
    *(DWORD *)((char *)pCaps + 0x44) = 0x3030300;

    if (MacDisplay_GetSupportsAnisotropicFiltering()) {
        *(DWORD *)((char *)pCaps + 0x40) |= 0x4000400;
        *(DWORD *)((char *)pCaps + 0x44) |= 0x4000400;
    }

    *(DWORD *)((char *)pCaps + 0x48) = 0;
    *(DWORD *)((char *)pCaps + 0x4C) = 0xd;
    *(DWORD *)((char *)pCaps + 0x50) = 0;
    *(DWORD *)((char *)pCaps + 0x54) = 0;
    *(DWORD *)((char *)pCaps + 0x58) = dev->maxTextureSize;
    *(DWORD *)((char *)pCaps + 0x5C) = dev->maxTextureSize;
    *(DWORD *)((char *)pCaps + 0x60) = 0;
    *(DWORD *)((char *)pCaps + 0x64) = 0;
    *(DWORD *)((char *)pCaps + 0x68) = 0x800;

    if (MacDisplay_GetSupportsAnisotropicFiltering()) {
        *(DWORD *)((char *)pCaps + 0x6C) = (DWORD)MacDisplay_GetMaxSupportedAnisotropy();
    }

    *(DWORD *)((char *)pCaps + 0x70) = 0;
    *(DWORD *)((char *)pCaps + 0x74) = 0;
    *(DWORD *)((char *)pCaps + 0x78) = 0;
    *(DWORD *)((char *)pCaps + 0x7C) = 0;
    *(DWORD *)((char *)pCaps + 0x80) = 0;
    *(DWORD *)((char *)pCaps + 0x84) = 0;
    *(DWORD *)((char *)pCaps + 0x88) = 0xff;
    *(DWORD *)((char *)pCaps + 0x8C) = 0;
    *(DWORD *)((char *)pCaps + 0x90) = 0x3feffff;
    *(DWORD *)((char *)pCaps + 0x9C) = 0x3b;
    *(DWORD *)((char *)pCaps + 0xA0) = 8;
    *(DWORD *)((char *)pCaps + 0xA4) = 0;
    *(DWORD *)((char *)pCaps + 0xA8) = 0;
    *(DWORD *)((char *)pCaps + 0xAC) = 0;
    *(DWORD *)((char *)pCaps + 0xB0) = 0x3f800000; /* 1.0f */
    *(DWORD *)((char *)pCaps + 0xB4) = 0xffff;
    *(DWORD *)((char *)pCaps + 0xB8) = 0xffff;
    *(DWORD *)((char *)pCaps + 0xBC) = 0x10;
    *(DWORD *)((char *)pCaps + 0xC0) = 0x400;
    *(DWORD *)((char *)pCaps + 0xC4) = 0xfffe0200;

    *(DWORD *)((char *)pCaps + 0xCC) = MacOpenGLUtils_GetPCPixelShaderVersion();
    *(DWORD *)((char *)pCaps + 0xC8) = 0x100;
    *(DWORD *)((char *)pCaps + 0xD0) = 0x41000000; /* 8.0f */

    maxTexImageUnits = MacDisplay_GetMaxTextureImageUnits();
    maxTexUnits = MacDisplay_GetMaxTextureUnits();
    maxStages = (maxTexUnits < maxTexImageUnits) ? maxTexImageUnits : maxTexUnits;
    *(DWORD *)((char *)pCaps + 0x98) = maxStages;
    *(DWORD *)((char *)pCaps + 0x94) = maxStages;

    *(DWORD *)((char *)pCaps + 0xD4) = 1;
    *(DWORD *)((char *)pCaps + 0xD8) = 0;
    *(DWORD *)((char *)pCaps + 0xEC) = 0;
    *(DWORD *)((char *)pCaps + 0xF0) = 1;
    *(DWORD *)((char *)pCaps + 0xF4) = 0x200;
    *(DWORD *)((char *)pCaps + 0x11C) = 0;
    *(DWORD *)((char *)pCaps + 0x120) = 0;
    *(DWORD *)((char *)pCaps + 0x124) = 0;
    *(DWORD *)((char *)pCaps + 0x128) = 0;
    return 0;
}

HRESULT CDirect3DDevice_GetDisplayMode(const CDirect3DDevice *_this, UINT iSwapChain, D3DDISPLAYMODE *pMode)
{
    (void)_this; (void)iSwapChain; (void)pMode;
    return 0;
}

HRESULT CDirect3DDevice_GetCreationParameters(const CDirect3DDevice *_this, D3DDEVICE_CREATION_PARAMETERS *pParameters)
{
    (void)_this; (void)pParameters;
    return 0;
}

HRESULT CDirect3DDevice_GetBackBuffer(const CDirect3DDevice *_this, UINT iSwapChain, UINT BackBuffer,
    D3DBACKBUFFER_TYPE Type, IDirect3DSurface9 **ppBackBuffer)
{
    DeviceImpl *dev = (DeviceImpl *)_this;
    (void)iSwapChain; (void)BackBuffer; (void)Type;
    *ppBackBuffer = dev->backBuffer;
    if (dev->backBuffer) {
        void **vtbl = *(void ***)dev->backBuffer;
        ((ULONG(*)(const void *))vtbl[1])((const void *)dev->backBuffer); /* AddRef */
    }
    return 0;
}

HRESULT CDirect3DDevice_BeginScene(const CDirect3DDevice *_this)
{
    (void)_this;
    return 0;
}

HRESULT CDirect3DDevice_EndScene(const CDirect3DDevice *_this)
{
    (void)_this;
    return 0;
}

HRESULT CDirect3DDevice_Clear(const CDirect3DDevice *_this, DWORD Count, const D3DRECT *pRects,
    DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil)
{
    GLbitfield glFlags = 0;
    (void)_this; (void)Count; (void)pRects;

    if (Flags & 1) { /* D3DCLEAR_TARGET */
        float r = ((Color >> 16) & 0xFF) / 255.0f;
        float g = ((Color >> 8) & 0xFF) / 255.0f;
        float b = (Color & 0xFF) / 255.0f;
        float a = ((Color >> 24) & 0xFF) / 255.0f;
        glClearColor(r, g, b, a);
        glFlags |= 0x4000; /* GL_COLOR_BUFFER_BIT */
    }
    if (Flags & 2) { /* D3DCLEAR_ZBUFFER */
        glClearDepth((double)Z);
        glFlags |= 0x100; /* GL_DEPTH_BUFFER_BIT */
    }
    if (Flags & 4) { /* D3DCLEAR_STENCIL */
        glClearStencil(Stencil);
        glFlags |= 0x400; /* GL_STENCIL_BUFFER_BIT */
    }
    if (glFlags) {
        /* Skip color-only clears with transparent black (0x00000000) —
         * the game issues this after drawing, wiping the framebuffer */
        if (Flags == 1 && Color == 0x00000000) {
            /* Skip this clear — it destroys the rendered frame */
        } else {
            glClear(glFlags);
            /* (test code removed — rendering verified working) */
        }
    }
    return 0;
}

HRESULT CDirect3DDevice_Present(const CDirect3DDevice *_this, const RECT *pSourceRect,
    const RECT *pDestRect, HWND hDestWindowOverride, const RGNDATA *pDirtyRegion)
{
    static int present_count = 0;
    extern SDL_Window *sdl_gl_window;
    (void)_this; (void)pSourceRect; (void)pDestRect; (void)hDestWindowOverride; (void)pDirtyRegion;
    present_count++;
    /* Actually swap the buffers! */
    if (sdl_gl_window)
        SDL_GL_SwapWindow(sdl_gl_window);
    return 0;
}

HRESULT CDirect3DDevice_DrawPrimitive(const CDirect3DDevice *_this,
    D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount)
{
    (void)_this; (void)PrimitiveType; (void)StartVertex; (void)PrimitiveCount;
    return 0;
}

HRESULT CDirect3DDevice_DrawIndexedPrimitive(const CDirect3DDevice *_this,
    D3DPRIMITIVETYPE PrimitiveType, INT BaseVertexIndex, UINT MinVertexIndex,
    UINT NumVertices, UINT startIndex, UINT primCount)
{
    DeviceImpl *dev = (DeviceImpl *)_this;
    byte *vbData, *ibData, *vertBase;
    UINT stride, offset;
    int indexCount;
    GLenum glMode;
    static int dip_count = 0;

    (void)PrimitiveType; /* Always D3DPT_TRIANGLELIST (4) from the game */

    if (!dev->streams[0] || !dev->indexBuffer)
        return 0;

    /* Get vertex buffer data pointer (CDirect3DVertexBufferClean: vtable, refCount, length, data) */
    vbData = *(byte **)((byte *)dev->streams[0] + 12); /* data field at offset 12 */
    if (!vbData)
        return 0;
    offset = dev->streamOffsets[0];
    stride = dev->streamStrides[0];

    /* Get index buffer data pointer (CDirect3DIndexBufferClean: same layout) */
    ibData = *(byte **)((byte *)dev->indexBuffer + 12); /* data field at offset 12 */
    if (!ibData)
        return 0;

    /* Vertex base = VB data + stream offset + BaseVertexIndex * stride */
    vertBase = vbData + offset + BaseVertexIndex * stride;

    /* Set up vertex attributes based on stride.
     * Non-Dx7 generic vertex (stride 64): pos(12) + normal(4 packed) + color(4) + texcoord0(8) + ...
     * The FVF-based layout differs: pos(12) + normal(12) + color(4) + texcoord(8) = 36 bytes.
     * Since SetFVF may not always be called before DIP, use stride to determine layout. */
    {
        DWORD fvf = g_currentFVF;
        int fvfOffset = 0;

        /* For stride=64 (non-Dx7 generic vertex), the actual layout is:
         *   float pos[3]       @ 0  (12 bytes)
         *   packed normal      @ 12 (4 bytes)
         *   float texcoord[2]  @ 16 (8 bytes)
         *   4 bytes padding    @ 24
         *   byte color[4]      @ 28 (0x1c)
         *   ... remaining data up to stride
         * This doesn't match FVF 0x152 which assumes 12-byte float normal.
         * Use stride-based layout for correct offsets. */

        /* Position: always 3 floats at offset 0 */
        glEnableClientState(0x8074); /* GL_VERTEX_ARRAY */
        glVertexPointer(3, 0x1406 /* GL_FLOAT */, stride, vertBase);

        /* Color and texcoord offsets depend on vertex layout.
         * GfxWorldVertex (stride 0x44=68): pos(12)+tangent(12)+color(4)+texCoord(8)+lmapCoord(8)+binormal(12)+normal(12)
         * HUD vertex (stride 0x40=64): similar layout */
        {
            int colorOffset = -1;
            int texOffset = -1;
            if (stride == 0x44) {
                colorOffset = 0x18;  /* after pos(12) + tangent(12) */
                texOffset = 0x1c;    /* after color(4) */
            } else if (stride == 0x40) {
                colorOffset = 0x1c;
                texOffset = 0x20;
            } else if (stride == 0x18 || stride == 0x20) {
                colorOffset = 0x0c;
            } else if (stride == 0x24) {
                colorOffset = 0x18;
                texOffset = 0x1c;
            }
            if (colorOffset >= 0 && stride != 0x44) {
                /* Use vertex colors for non-world geometry (HUD, etc.) */
                glEnableClientState(0x8076); /* GL_COLOR_ARRAY */
                glColorPointer(0x80E1 /* GL_BGRA */, 0x1401 /* GL_UNSIGNED_BYTE */, stride, vertBase + colorOffset);
            } else if (stride == 0x44) {
                /* World geometry: force white color since vertex colors are
                   dark ambient occlusion and we don't have lightmap support yet */
                glDisableClientState(0x8076); /* GL_COLOR_ARRAY */
                glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
            }
            if (texOffset >= 0) {
                glEnableClientState(0x8078); /* GL_TEXTURE_COORD_ARRAY */
                glTexCoordPointer(2, 0x1406 /* GL_FLOAT */, stride, vertBase + texOffset);
            }
        }

        if (dip_count < 3) {
            float *pos = (float *)vertBase;
            unsigned int *raw = (unsigned int *)vertBase;
            unsigned short *idx = (unsigned short *)(ibData + startIndex * 2);
            int vi;
            fprintf(stderr, "[DIP] stride=%d numVtx=%d primCount=%d base=%d off=%d\n",
                    stride, NumVertices, primCount, BaseVertexIndex, offset);
            for (vi = 0; vi < NumVertices && vi < 4; vi++) {
                float *vp = (float *)(vertBase + vi * stride);
                fprintf(stderr, "  v%d pos=(%.2f,%.2f,%.2f) col=%02x%02x%02x%02x\n",
                        vi, vp[0], vp[1], vp[2],
                        vertBase[vi*stride+28], vertBase[vi*stride+29],
                        vertBase[vi*stride+30], vertBase[vi*stride+31]);
            }
            fprintf(stderr, "  idx: %d %d %d %d %d %d\n", idx[0], idx[1], idx[2], idx[3], idx[4], idx[5]);
        }
    }

    /* Reset GL state. For world geometry (stride=0x44), keep ARB programs
     * and use 3D perspective projection. For HUD (other strides), use
     * fixed-function with ortho projection. */
    while (glGetError()) {}
    { extern void glBindVertexArray(unsigned int); glBindVertexArray(0); }

    {
        /* Common rendering path for both world and HUD.
         * Reset GL state, then set projection based on stride. */
        glBindProgramARB(0x8620, 0);
        glBindProgramARB(0x8804, 0);
        glDisable(0x8620);
        glDisable(0x8804);
        glDisable(0x0B71); /* GL_DEPTH_TEST */
        glDisable(0x0B44); /* GL_CULL_FACE */
        glDisable(0x0B60); /* GL_FOG */
        glDisable(0x0B50); /* GL_LIGHTING */
        glDisable(0x0BC0); /* GL_ALPHA_TEST */
        glColorMask(1, 1, 1, 1);
        glDepthMask(0);
        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

        if (stride == 0x44) {
            /* 3D world: use separate view and projection matrices.
             * projection at viewParms+0x88, view at viewParms+0x48.
             * Only projection gets D3D→GL z remap. */
            extern byte backEnd[];
            void *viewParms = *(void **)(backEnd + 0x3c8);
            if (viewParms) {
                float *src;
                float t[16];
                int i, hasNaN;
                /* Projection matrix */
                src = (float *)((byte *)viewParms + 0x88);
                hasNaN = 0;
                for (i = 0; i < 16; i++) if (src[i] != src[i]) hasNaN = 1;
                if (!hasNaN) {
                    t[0]=src[0]; t[1]=src[4]; t[2]=src[8];  t[3]=src[12];
                    t[4]=src[1]; t[5]=src[5]; t[6]=src[9];  t[7]=src[13];
                    t[8]=src[2]; t[9]=src[6]; t[10]=src[10]; t[11]=src[14];
                    t[12]=src[3]; t[13]=src[7]; t[14]=src[11]; t[15]=src[15];
                    /* D3D z→[0,1] to GL z→[-1,1] */
                    t[2]  = 2.0f*t[2]  - t[3];
                    t[6]  = 2.0f*t[6]  - t[7];
                    t[10] = 2.0f*t[10] - t[11];
                    t[14] = 2.0f*t[14] - t[15];
                    glMatrixMode(0x1701);
                    glLoadMatrixf(t);
                } else {
                    glMatrixMode(0x1701);
                    glLoadIdentity();
                    glScalef(1.0f/4000.0f, 1.0f/4000.0f, 1.0f/4000.0f);
                }
                /* View matrix */
                src = (float *)((byte *)viewParms + 0x48);
                hasNaN = 0;
                for (i = 0; i < 16; i++) if (src[i] != src[i]) hasNaN = 1;
                if (!hasNaN) {
                    t[0]=src[0]; t[1]=src[4]; t[2]=src[8];  t[3]=src[12];
                    t[4]=src[1]; t[5]=src[5]; t[6]=src[9];  t[7]=src[13];
                    t[8]=src[2]; t[9]=src[6]; t[10]=src[10]; t[11]=src[14];
                    t[12]=src[3]; t[13]=src[7]; t[14]=src[11]; t[15]=src[15];
                    glMatrixMode(0x1700);
                    glLoadMatrixf(t);
                } else {
                    glMatrixMode(0x1700);
                    glLoadIdentity();
                }
            } else {
                glMatrixMode(0x1701);
                glLoadIdentity();
                glScalef(1.0f/4000.0f, 1.0f/4000.0f, 1.0f/4000.0f);
                glMatrixMode(0x1700);
                glLoadIdentity();
            }
        } else {
            /* 2D HUD: ortho projection */
            float ortho[16] = {
                2.0f/640.0f, 0, 0, 0,
                0, -2.0f/480.0f, 0, 0,
                0, 0, -1.0f, 0,
                -1.0f, 1.0f, 0, 1.0f
            };
            glMatrixMode(0x1701);
            glLoadMatrixf(ortho);
            glMatrixMode(0x1700);
            glLoadIdentity();
        }
    }
    while (glGetError()) {}

    /* Bind texture from pre-bind. For world geometry, skip textures to ensure
     * solid color rendering works first. */
    if (stride == 0x44) {
        glDisable(0x0DE1); /* force no textures for world — just solid color */
    }
    else
    { extern void glBindTexture(unsigned int, unsigned int);
      { extern void glBindTexture(unsigned int, unsigned int);
        unsigned int glTexID = g_prebind_texID;
        if (glTexID) {
            glEnable(0x0DE1); /* GL_TEXTURE_2D */
            glBindTexture(0x0DE1, glTexID);
            /* GL_MODULATE: output RGB = tex.rgb * vtx.rgb, output A = tex.a * vtx.a */
            glTexEnvi(0x2300, 0x2200, 0x2100); /* GL_TEXTURE_ENV_MODE = GL_MODULATE */
            /* Force re-upload texture data from CPU memory.
             * The game writes texture data via LockRect but never uploads to GL
             * because UpdateOpenGLSurfaces was a no-op. We upload here on first use. */
            {
                extern void *imp_tess;
                byte *tess_base = (byte *)imp_tess;
                void *material = *(void **)(tess_base + 0x5a7bc);
                if (material && (unsigned int)material > 0x08000000u) {
                    unsigned short texCount = *(unsigned short *)((byte *)material + 0x34);
                    if (texCount > 0) {
                        byte *texDefs = *(byte **)((byte *)material + 0x3C);
                        if (texDefs && (unsigned int)texDefs > 0x08000000u) {
                            void *image = *(void **)((byte *)texDefs + 0x08);
                            if (image && (unsigned int)image > 0x08000000u) {
                                void *d3dTex = *(void **)((byte *)image + 0x04);
                                if (d3dTex && (unsigned int)d3dTex > 0x08000000u) {
                                    /* Call UpdateOpenGLSurfaces on the texture to upload data */
                                    extern void CDirect3DTexture_UpdateOpenGLSurfaces(const void *);
                                    {
                                    unsigned int tid = *(unsigned int *)((byte *)d3dTex + 0x54);
                                    CDirect3DTexture_UpdateOpenGLSurfaces(d3dTex);
                                    glBindTexture(0x0DE1, tid);
                                }
                            }
                        }
                    }
                }
            }
            }
        } else {
            glDisable(0x0DE1);
        }
      }
    }

    /* (texture diagnostic removed) */

    /* Alpha blending: enable for HUD, disable for world */
    if (stride == 0x44) {
        glDisable(0x0BE2); /* no blend for world — solid color */
    } else {
        glEnable(0x0BE2); /* GL_BLEND */
        glBlendFunc(0x0302 /* GL_SRC_ALPHA */, 0x0303 /* GL_ONE_MINUS_SRC_ALPHA */);
    }

    /* Set up vertex attributes from game data */
    glEnableClientState(0x8074); /* GL_VERTEX_ARRAY */
    glVertexPointer(3, 0x1406 /* GL_FLOAT */, stride, vertBase);

    /* Color and texcoord offsets depend on vertex layout stride */
    {
        int colorOffset = -1;
        int texOffset = -1;
        if (stride == 0x44) {
            colorOffset = 0x18;
            texOffset = 0x1c;
        } else if (stride == 0x40) {
            colorOffset = 0x1c;
            texOffset = 0x20;
        } else if (stride == 0x24) {
            colorOffset = 0x18;
            texOffset = 0x1c;
        } else if (stride == 0x18 || stride == 0x20) {
            colorOffset = 0x0c;
            texOffset = -1;
        }
        if (colorOffset >= 0) {
            glEnableClientState(0x8076); /* GL_COLOR_ARRAY */
            /* D3D vertex colors are BGRA; use GL_BGRA (0x80E1) as size param
             * (GL_EXT_vertex_array_bgra) to swizzle to RGBA on read */
            glColorPointer(0x80E1 /* GL_BGRA */, 0x1401 /* GL_UNSIGNED_BYTE */, stride, vertBase + colorOffset);
        }
        if (texOffset >= 0) {
            glEnableClientState(0x8078); /* GL_TEXTURE_COORD_ARRAY */
            glTexCoordPointer(2, 0x1406 /* GL_FLOAT */, stride, vertBase + texOffset);
        }
    }

    /* Draw with glDrawElements */
    {
        extern void glDrawElements(unsigned int, int, unsigned int, const void *);
        indexCount = primCount * 3;
        glDrawElements(0x0004 /* GL_TRIANGLES */, indexCount,
                       0x1403 /* GL_UNSIGNED_SHORT */,
                       ibData + startIndex * 2);
    }

    /* Disable arrays */
    glDisableClientState(0x8074); /* GL_VERTEX_ARRAY */
    glDisableClientState(0x8076); /* GL_COLOR_ARRAY */
    glDisableClientState(0x8078); /* GL_TEXTURE_COORD_ARRAY */

    return 0;
}

HRESULT CDirect3DDevice_DrawPrimitiveUP(const CDirect3DDevice *_this,
    D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount,
    const void *pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
    (void)_this; (void)PrimitiveType; (void)PrimitiveCount;
    (void)pVertexStreamZeroData; (void)VertexStreamZeroStride;
    return 0;
}

HRESULT CDirect3DDevice_DrawIndexedPrimitiveUP(const CDirect3DDevice *_this,
    D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertexIndices,
    UINT PrimitiveCount, const long unsigned int *pIndexData,
    D3DFORMAT IndexDataFormat, const long unsigned int *pVertexStreamZeroData,
    UINT VertexStreamZeroStride)
{
    (void)_this; (void)PrimitiveType; (void)MinVertexIndex; (void)NumVertexIndices;
    (void)PrimitiveCount; (void)pIndexData; (void)IndexDataFormat;
    (void)pVertexStreamZeroData; (void)VertexStreamZeroStride;
    return 0;
}

/* ============================================================ */
/* State Management                                             */
/* ============================================================ */

HRESULT CDirect3DDevice_SetRenderState(const CDirect3DDevice *_this, D3DRENDERSTATETYPE State, DWORD Value)
{
    (void)_this;
    switch (State) {
        case 0x22: { /* D3DRS_FOGCOLOR */
            float fc[4];
            fc[0] = ((Value >> 16) & 0xFF) / 255.0f;
            fc[1] = ((Value >> 8) & 0xFF) / 255.0f;
            fc[2] = (Value & 0xFF) / 255.0f;
            fc[3] = ((Value >> 24) & 0xFF) / 255.0f;
            glFogfv(0x0B66 /* GL_FOG_COLOR */, fc);
            break;
        }
        default:
            break;
    }
    return 0;
}

HRESULT CDirect3DDevice_GetRenderState(const CDirect3DDevice *_this, D3DRENDERSTATETYPE State, DWORD *pValue)
{
    (void)_this; (void)State;
    if (pValue) *pValue = 0;
    return 0;
}

HRESULT CDirect3DDevice_SetTexture(const CDirect3DDevice *_this, DWORD Stage, IDirect3DBaseTexture9 *pTexture)
{
    (void)_this;
    if (Stage < 8)
        g_boundTextures[Stage] = pTexture;
    return 0;
}

HRESULT CDirect3DDevice_GetTexture(const CDirect3DDevice *_this, DWORD Stage, IDirect3DBaseTexture9 **ppTexture)
{
    (void)_this; (void)Stage;
    if (ppTexture) *ppTexture = NULL;
    return 0;
}

HRESULT CDirect3DDevice_SetTextureStageState(const CDirect3DDevice *_this, DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value)
{
    (void)_this; (void)Stage; (void)Type; (void)Value;
    return 0;
}

HRESULT CDirect3DDevice_GetTextureStageState(const CDirect3DDevice *_this, DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD *pValue)
{
    (void)_this; (void)Stage; (void)Type;
    if (pValue) *pValue = 0;
    return 0;
}

HRESULT CDirect3DDevice_SetSamplerState(const CDirect3DDevice *_this, DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD Value)
{
    (void)_this; (void)Sampler; (void)Type; (void)Value;
    return 0;
}

HRESULT CDirect3DDevice_GetSamplerState(const CDirect3DDevice *_this, DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD *pValue)
{
    (void)_this; (void)Sampler; (void)Type;
    if (pValue) *pValue = 0;
    return 0;
}

HRESULT CDirect3DDevice_SetTransform(const CDirect3DDevice *_this, D3DTRANSFORMSTATETYPE State, const D3DMATRIX *pMatrix)
{
    (void)_this; (void)State; (void)pMatrix;
    return 0;
}

HRESULT CDirect3DDevice_GetTransform(const CDirect3DDevice *_this, D3DTRANSFORMSTATETYPE State, D3DMATRIX *pMatrix)
{
    DeviceImpl *dev = (DeviceImpl *)_this;
    const float *src = NULL;
    if (State == 0x100) {       /* D3DTS_WORLD */
        src = dev->worldMatrix;
    } else if (State == 2) {    /* D3DTS_VIEW */
        src = dev->viewMatrix;
    } else if (State == 3) {    /* D3DTS_PROJECTION */
        src = dev->texMatrix;
    }
    if (src && pMatrix) {
        memcpy(pMatrix, src, 64);
    }
    return 0;
}

HRESULT CDirect3DDevice_SetViewport(const CDirect3DDevice *_this, const D3DVIEWPORT9 *pViewport)
{
    DeviceImpl *dev = (DeviceImpl *)_this;

    dev->viewportX = pViewport->X;
    dev->viewportY = pViewport->Y;
    dev->viewportW = pViewport->Width;
    dev->viewportH = pViewport->Height;
    dev->viewportMinZ = pViewport->MinZ;
    dev->viewportMaxZ = pViewport->MaxZ;

    glViewport(pViewport->X, pViewport->Y, pViewport->Width, pViewport->Height);
    glDepthRange((double)pViewport->MinZ, (double)pViewport->MaxZ);
    return 0;
}

HRESULT CDirect3DDevice_GetViewport(const CDirect3DDevice *_this, IDirect3DIndexBuffer9 *(*pViewport)[10])
{
    DeviceImpl *dev = (DeviceImpl *)_this;
    UINT32 *dst = (UINT32 *)pViewport;
    dst[0] = dev->viewportX;
    dst[1] = dev->viewportY;
    dst[2] = dev->viewportW;
    dst[3] = dev->viewportH;
    *(float *)&dst[4] = dev->viewportMinZ;
    *(float *)&dst[5] = dev->viewportMaxZ;
    return 0;
}

HRESULT CDirect3DDevice_SetMaterial(const CDirect3DDevice *_this, const D3DMATERIAL9 *pMaterial)
{
    (void)_this; (void)pMaterial;
    return 0;
}

HRESULT CDirect3DDevice_GetMaterial(const CDirect3DDevice *_this, char (*pMaterial)[4])
{
    (void)_this; (void)pMaterial;
    return 0;
}

HRESULT CDirect3DDevice_SetLight(const CDirect3DDevice *_this, DWORD Index, const D3DLIGHT9 *pLight)
{
    (void)_this; (void)Index; (void)pLight;
    return 0;
}

HRESULT CDirect3DDevice_GetLight(const CDirect3DDevice *_this, DWORD Index)
{
    (void)_this; (void)Index;
    return 0;
}

HRESULT CDirect3DDevice_LightEnable(const CDirect3DDevice *_this, DWORD Index, BOOL Enable)
{
    (void)_this; (void)Index; (void)Enable;
    return 0;
}

HRESULT CDirect3DDevice_GetLightEnable(const CDirect3DDevice *_this, DWORD Index, BOOL *pEnable)
{
    (void)_this; (void)Index; (void)pEnable;
    return 0;
}

HRESULT CDirect3DDevice_SetClipPlane(const CDirect3DDevice *_this, DWORD Index, const float *pPlane)
{
    (void)_this; (void)Index; (void)pPlane;
    return 0;
}

HRESULT CDirect3DDevice_GetClipPlane(const CDirect3DDevice *_this, DWORD Index, float *pPlane)
{
    (void)_this; (void)Index; (void)pPlane;
    return 0;
}

HRESULT CDirect3DDevice_SetStreamSource(const CDirect3DDevice *_this, UINT StreamNumber,
    IDirect3DVertexBuffer9 *pStreamData, UINT OffsetInBytes, UINT Stride)
{
    DeviceImpl *dev = (DeviceImpl *)_this;
    dev->streams[StreamNumber] = (IDirect3DVertexBuffer9 *)pStreamData;
    dev->streamOffsets[StreamNumber] = OffsetInBytes;
    dev->streamStrides[StreamNumber] = Stride;
    CDirect3DDevice_mNeedsTransformationValidation = 1;
    CDirect3DDevice_mNeedsRasterizationValidation = 1;
    return 0;
}

HRESULT CDirect3DDevice_GetStreamSource(const CDirect3DDevice *_this, UINT StreamNumber,
    IDirect3DVertexBuffer9 **ppStreamData, UINT *pOffsetInBytes, UINT *pStride)
{
    DeviceImpl *dev = (DeviceImpl *)_this;
    *ppStreamData = dev->streams[StreamNumber];
    if (dev->streams[StreamNumber]) {
        void **vtbl = *(void ***)dev->streams[StreamNumber];
        ((ULONG(*)(const void *))vtbl[1])((const void *)dev->streams[StreamNumber]);
    }
    *pStride = dev->streamStrides[StreamNumber];
    *pOffsetInBytes = dev->streamOffsets[StreamNumber];
    return 0;
}

HRESULT CDirect3DDevice_SetIndices(const CDirect3DDevice *_this, IDirect3DIndexBuffer9 *pIndexData)
{
    DeviceImpl *dev = (DeviceImpl *)_this;
    dev->indexBuffer = pIndexData;
    return 0;
}

HRESULT CDirect3DDevice_GetIndices(const CDirect3DDevice *_this, IDirect3DIndexBuffer9 **ppIndexData)
{
    DeviceImpl *dev = (DeviceImpl *)_this;
    *ppIndexData = dev->indexBuffer;
    return 0;
}

HRESULT CDirect3DDevice_SetVertexDeclaration(const CDirect3DDevice *_this, IDirect3DVertexDeclaration9 *pDecl)
{
    (void)_this; (void)pDecl;
    return 0;
}

HRESULT CDirect3DDevice_GetVertexDeclaration(const CDirect3DDevice *_this, IDirect3DVertexDeclaration9 **ppDecl)
{
    (void)_this; (void)ppDecl;
    return 0;
}

HRESULT CDirect3DDevice_SetFVF(const CDirect3DDevice *_this, DWORD FVF)
{
    (void)_this;
    g_currentFVF = FVF;
    return 0;
}

HRESULT CDirect3DDevice_GetFVF(const CDirect3DDevice *_this, DWORD *pFVF)
{
    (void)_this; (void)pFVF;
    return 0;
}

HRESULT CDirect3DDevice_SetVertexShader(const CDirect3DDevice *_this, IDirect3DVertexShader9 *pShader)
{
    (void)_this; (void)pShader;
    CDirect3DDevice_mNeedsVertexShaderValidation = 1;
    return 0;
}

HRESULT CDirect3DDevice_GetVertexShader(const CDirect3DDevice *_this, IDirect3DVertexShader9 **ppShader)
{
    (void)_this; (void)ppShader;
    return 0;
}

HRESULT CDirect3DDevice_SetPixelShader(const CDirect3DDevice *_this, IDirect3DPixelShader9 *pShader)
{
    DeviceImpl *dev = (DeviceImpl *)_this;
    if (dev->pixelShader != pShader) {
        dev->pixelShader = pShader;
        CDirect3DDevice_mNeedsRasterizationValidation = 1;
    }
    return 0;
}

HRESULT CDirect3DDevice_GetPixelShader(const CDirect3DDevice *_this, IDirect3DPixelShader9 **ppShader)
{
    (void)_this; (void)ppShader;
    return 0;
}

HRESULT CDirect3DDevice_SetVertexShaderConstantF(const CDirect3DDevice *_this, UINT StartRegister,
    const float *pConstantData, UINT Vector4fCount)
{
    UINT i;
    const float *pf = pConstantData;
    (void)_this;
    {
        static int vsc_log = 0;
        if (vsc_log++ < 20)
            fprintf(stderr, "[VSC] SetVertexShaderConstantF reg=%d count=%d val=(%.3f,%.3f,%.3f,%.3f)\n",
                    StartRegister, Vector4fCount, pf[0], pf[1], pf[2], pf[3]);
    }
    for (i = StartRegister; i < StartRegister + Vector4fCount; i++) {
        glProgramEnvParameter4fvARB(0x8620, i, pf);
        /* Also save to our local copy for fixed-function fallback */
        if (i < 256)
            memcpy(g_vsConst + i * 4, pf, 16);
        pf += 4;
    }
    return 0;
}

HRESULT CDirect3DDevice_GetVertexShaderConstantF(const CDirect3DDevice *_this, UINT StartRegister,
    float *pConstantData, UINT Vector4fCount)
{
    (void)_this; (void)StartRegister; (void)pConstantData; (void)Vector4fCount;
    return 0;
}

HRESULT CDirect3DDevice_SetPixelShaderConstantF(const CDirect3DDevice *_this, UINT StartRegister,
    const float *pConstantData, UINT Vector4fCount)
{
    DeviceImpl *dev = (DeviceImpl *)_this;
    if (dev->pixelShader) {
        void **vtbl = *(void ***)dev->pixelShader;
        /* SetConstants at vtable slot 9 (offset 0x24) */
        ((void(*)(const void*, int, const float*, int, int))vtbl[9])(
            (const void *)dev->pixelShader, StartRegister, pConstantData, Vector4fCount, 0);
    }
    return 0;
}

HRESULT CDirect3DDevice_GetPixelShaderConstantF(const CDirect3DDevice *_this, UINT StartRegister,
    float *pConstantData, UINT Vector4fCount)
{
    (void)_this; (void)StartRegister; (void)pConstantData; (void)Vector4fCount;
    return 0;
}

HRESULT CDirect3DDevice_SetVertexShaderConstantI(const CDirect3DDevice *_this, UINT StartRegister, const int *pConstantData, UINT Vector4iCount)
{ (void)_this; (void)StartRegister; (void)pConstantData; (void)Vector4iCount; return 0; }
HRESULT CDirect3DDevice_GetVertexShaderConstantI(const CDirect3DDevice *_this, UINT StartRegister, int *pConstantData, UINT Vector4iCount)
{ (void)_this; (void)StartRegister; (void)pConstantData; (void)Vector4iCount; return 0; }
HRESULT CDirect3DDevice_SetVertexShaderConstantB(const CDirect3DDevice *_this, UINT StartRegister, const BOOL *pConstantData, UINT BoolCount)
{ (void)_this; (void)StartRegister; (void)pConstantData; (void)BoolCount; return 0; }
HRESULT CDirect3DDevice_GetVertexShaderConstantB(const CDirect3DDevice *_this, UINT StartRegister, BOOL *pConstantData, UINT BoolCount)
{ (void)_this; (void)StartRegister; (void)pConstantData; (void)BoolCount; return 0; }
HRESULT CDirect3DDevice_SetPixelShaderConstantI(const CDirect3DDevice *_this, UINT StartRegister, const int *pConstantData, UINT Vector4iCount)
{ (void)_this; (void)StartRegister; (void)pConstantData; (void)Vector4iCount; return 0; }
HRESULT CDirect3DDevice_GetPixelShaderConstantI(const CDirect3DDevice *_this, UINT StartRegister, int *pConstantData, UINT Vector4iCount)
{ (void)_this; (void)StartRegister; (void)pConstantData; (void)Vector4iCount; return 0; }
HRESULT CDirect3DDevice_SetPixelShaderConstantB(const CDirect3DDevice *_this, UINT StartRegister, const BOOL *pConstantData, UINT BoolCount)
{ (void)_this; (void)StartRegister; (void)pConstantData; (void)BoolCount; return 0; }
HRESULT CDirect3DDevice_GetPixelShaderConstantB(const CDirect3DDevice *_this, UINT StartRegister, BOOL *pConstantData, UINT BoolCount)
{ (void)_this; (void)StartRegister; (void)pConstantData; (void)BoolCount; return 0; }

HRESULT CDirect3DDevice_SetRenderTarget(const CDirect3DDevice *_this, DWORD RenderTargetIndex, IDirect3DSurface9 *pRenderTarget)
{
    DeviceImpl *dev = (DeviceImpl *)_this;
    (void)RenderTargetIndex;
    dev->renderTarget = pRenderTarget;
    return 0;
}

HRESULT CDirect3DDevice_GetRenderTarget(const CDirect3DDevice *_this, DWORD RenderTargetIndex, IDirect3DSurface9 **ppRenderTarget)
{
    DeviceImpl *dev = (DeviceImpl *)_this;
    (void)RenderTargetIndex;
    *ppRenderTarget = dev->renderTarget;
    if (dev->renderTarget) {
        void **vtbl = *(void ***)dev->renderTarget;
        ((ULONG(*)(const void *))vtbl[1])((const void *)dev->renderTarget);
    }
    return 0;
}

HRESULT CDirect3DDevice_SetDepthStencilSurface(const CDirect3DDevice *_this, IDirect3DSurface9 *pNewZStencil)
{
    DeviceImpl *dev = (DeviceImpl *)_this;
    dev->depthStencil = pNewZStencil;
    return 0;
}

HRESULT CDirect3DDevice_GetDepthStencilSurface(const CDirect3DDevice *_this, IDirect3DSurface9 **ppZStencilSurface)
{
    DeviceImpl *dev = (DeviceImpl *)_this;
    *ppZStencilSurface = dev->depthBuffer;
    if (dev->depthBuffer) {
        void **vtbl = *(void ***)dev->depthBuffer;
        ((ULONG(*)(const void *))vtbl[1])((const void *)dev->depthBuffer);
    }
    return 0;
}

HRESULT CDirect3DDevice_SetStreamSourceFreq(const CDirect3DDevice *_this, UINT StreamNumber, UINT Setting)
{ (void)_this; (void)StreamNumber; (void)Setting; return 0; }
HRESULT CDirect3DDevice_GetStreamSourceFreq(const CDirect3DDevice *_this, UINT StreamNumber, UINT *pSetting)
{ (void)_this; (void)StreamNumber; (void)pSetting; return 0; }

/* ============================================================ */
/* Query/State stubs                                            */
/* ============================================================ */

HRESULT CDirect3DDevice_ValidateDevice(const CDirect3DDevice *_this, DWORD *pNumPasses)
{
    (void)_this;
    if (pNumPasses) *pNumPasses = 1;
    return 0;
}

HRESULT CDirect3DDevice_Reset(const CDirect3DDevice *_this, D3DPRESENT_PARAMETERS *pPresentationParameters)
{
    (void)_this; (void)pPresentationParameters;
    return 0;
}

long unsigned int CDirect3DDevice_SetGammaRamp(const CDirect3DDevice *_this, UINT iSwapChain, DWORD Flags, const D3DGAMMARAMP *pRamp)
{
    (void)_this; (void)iSwapChain; (void)Flags;
    MacDisplay_SetGammaRamp(pRamp);
    return 0;
}

long unsigned int CDirect3DDevice_GetGammaRamp(const CDirect3DDevice *_this, UINT iSwapChain, D3DGAMMARAMP *pRamp)
{
    (void)_this; (void)iSwapChain; (void)pRamp;
    return 0;
}

HRESULT CDirect3DDevice_StretchRect(const CDirect3DDevice *_this, IDirect3DSurface9 *pSourceSurface,
    const RECT *pSourceRect, IDirect3DSurface9 *pDestSurface, const RECT *pDestRect, D3DTEXTUREFILTERTYPE Filter)
{
    (void)_this; (void)pSourceSurface; (void)pSourceRect; (void)pDestSurface; (void)pDestRect; (void)Filter;
    return 0;
}

HRESULT CDirect3DDevice_UpdateTexture(const CDirect3DDevice *_this, IDirect3DBaseTexture9 *pSourceTexture, IDirect3DBaseTexture9 *pDestinationTexture)
{
    (void)_this; (void)pSourceTexture; (void)pDestinationTexture;
    return 0;
}

HRESULT CDirect3DDevice_MultiplyTransform(const CDirect3DDevice *_this)
{ (void)_this; return 0; }

HRESULT CDirect3DDevice_SetCursorProperties(const CDirect3DDevice *_this, UINT XHotSpot, UINT YHotSpot, IDirect3DSurface9 *pCursorBitmap)
{ (void)_this; (void)XHotSpot; (void)YHotSpot; (void)pCursorBitmap; return 0; }
long unsigned int CDirect3DDevice_SetCursorPosition(const CDirect3DDevice *_this, int XScreenSpace, int YScreenSpace, DWORD Flags)
{ (void)_this; (void)XScreenSpace; (void)YScreenSpace; (void)Flags; return 0; }
BOOL CDirect3DDevice_ShowCursor(const CDirect3DDevice *_this, BOOL bShow)
{ (void)_this; (void)bShow; return 0; }

HRESULT CDirect3DDevice_CreateAdditionalSwapChain(const CDirect3DDevice *_this, D3DPRESENT_PARAMETERS *pPresentationParameters, IDirect3DSwapChain9 **pSwapChain)
{ (void)_this; (void)pPresentationParameters; (void)pSwapChain; return 0; }
HRESULT CDirect3DDevice_GetSwapChain(const CDirect3DDevice *_this, UINT iSwapChain, IDirect3DSwapChain9 **pSwapChain)
{ (void)_this; (void)iSwapChain; (void)pSwapChain; return 0; }
UINT CDirect3DDevice_GetNumberOfSwapChains(const CDirect3DDevice *_this)
{ (void)_this; return 1; }
HRESULT CDirect3DDevice_GetRasterStatus(const CDirect3DDevice *_this, UINT iSwapChain, D3DRASTER_STATUS *pRasterStatus)
{ (void)_this; (void)iSwapChain; (void)pRasterStatus; return 0; }
HRESULT CDirect3DDevice_SetDialogBoxMode(const CDirect3DDevice *_this, BOOL bEnableDialogs)
{ (void)_this; (void)bEnableDialogs; return 0; }

HRESULT CDirect3DDevice_UpdateSurface(const CDirect3DDevice *_this, IDirect3DSurface9 *pSourceSurface, const RECT *pSourceRect, IDirect3DSurface9 *pDestinationSurface, const POINT *pDestPoint)
{ (void)_this; (void)pSourceSurface; (void)pSourceRect; (void)pDestinationSurface; (void)pDestPoint; return 0; }
HRESULT CDirect3DDevice_GetRenderTargetData(const CDirect3DDevice *_this, IDirect3DSurface9 *pRenderTarget, IDirect3DSurface9 *pDestSurface)
{ (void)_this; (void)pRenderTarget; (void)pDestSurface; return 0; }
HRESULT CDirect3DDevice_GetFrontBufferData(const CDirect3DDevice *_this, UINT iSwapChain, IDirect3DSurface9 *pDestSurface)
{ (void)_this; (void)iSwapChain; (void)pDestSurface; return 0; }
HRESULT CDirect3DDevice_ColorFill(const CDirect3DDevice *_this, IDirect3DSurface9 *pSurface, const RECT *pRect, D3DCOLOR color)
{ (void)_this; (void)pSurface; (void)pRect; (void)color; return 0; }

HRESULT CDirect3DDevice_CreateStateBlock(const CDirect3DDevice *_this, D3DSTATEBLOCKTYPE Type, IDirect3DStateBlock9 **ppSB)
{ (void)_this; (void)Type; (void)ppSB; return 0; }
HRESULT CDirect3DDevice_BeginStateBlock(const CDirect3DDevice *_this)
{ (void)_this; return 0; }
HRESULT CDirect3DDevice_EndStateBlock(const CDirect3DDevice *_this, IDirect3DStateBlock9 **ppSB)
{ (void)_this; (void)ppSB; return 0; }
HRESULT CDirect3DDevice_SetClipStatus(const CDirect3DDevice *_this, const D3DCLIPSTATUS9 *pClipStatus)
{ (void)_this; (void)pClipStatus; return 0; }
HRESULT CDirect3DDevice_GetClipStatus(const CDirect3DDevice *_this, D3DCLIPSTATUS9 *pClipStatus)
{ (void)_this; (void)pClipStatus; return 0; }
HRESULT CDirect3DDevice_SetPaletteEntries(const CDirect3DDevice *_this, UINT PaletteNumber, const PALETTEENTRY *pEntries)
{ (void)_this; (void)PaletteNumber; (void)pEntries; return 0; }
HRESULT CDirect3DDevice_GetPaletteEntries(const CDirect3DDevice *_this, UINT PaletteNumber, _D3DFORMAT (*pEntries)[4][4])
{ (void)_this; (void)PaletteNumber; (void)pEntries; return 0; }
HRESULT CDirect3DDevice_SetCurrentTexturePalette(const CDirect3DDevice *_this, UINT PaletteNumber)
{ (void)_this; (void)PaletteNumber; return 0; }
HRESULT CDirect3DDevice_GetCurrentTexturePalette(const CDirect3DDevice *_this, UINT *PaletteNumber)
{ (void)_this; (void)PaletteNumber; return 0; }
HRESULT CDirect3DDevice_SetScissorRect(const CDirect3DDevice *_this, const RECT *pRect)
{ (void)_this; (void)pRect; return 0; }
HRESULT CDirect3DDevice_GetScissorRect(const CDirect3DDevice *_this, RECT *pRect)
{ (void)_this; (void)pRect; return 0; }
HRESULT CDirect3DDevice_SetSoftwareVertexProcessing(const CDirect3DDevice *_this, BOOL bSoftware)
{ (void)_this; (void)bSoftware; return 0; }
BOOL CDirect3DDevice_GetSoftwareVertexProcessing(const CDirect3DDevice *_this)
{ (void)_this; return 0; }
HRESULT CDirect3DDevice_SetNPatchMode(const CDirect3DDevice *_this, float nSegments)
{ (void)_this; (void)nSegments; return 0; }
float CDirect3DDevice_GetNPatchMode(const CDirect3DDevice *_this)
{ (void)_this; return 0.0f; }
HRESULT CDirect3DDevice_ProcessVertices(const CDirect3DDevice *_this, UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer9 *pDestBuffer, IDirect3DVertexDeclaration9 *pVertexDecl, DWORD Flags)
{ (void)_this; (void)SrcStartIndex; (void)DestIndex; (void)VertexCount; (void)pDestBuffer; (void)pVertexDecl; (void)Flags; return 0; }
HRESULT CDirect3DDevice_DrawRectPatch(const CDirect3DDevice *_this, UINT Handle, const float *pNumSegs, const D3DRECTPATCH_INFO *pRectPatchInfo)
{ (void)_this; (void)Handle; (void)pNumSegs; (void)pRectPatchInfo; return 0; }
HRESULT CDirect3DDevice_DrawTriPatch(const CDirect3DDevice *_this, UINT Handle, const float *pNumSegs, const D3DTRIPATCH_INFO *pTriPatchInfo)
{ (void)_this; (void)Handle; (void)pNumSegs; (void)pTriPatchInfo; return 0; }
HRESULT CDirect3DDevice_DeletePatch(const CDirect3DDevice *_this, UINT Handle)
{ (void)_this; (void)Handle; return 0; }

/* ============================================================ */
/* Helper functions referenced from the original ASM            */
/* ============================================================ */

long unsigned int CDirect3DDevice_StartPixelOneToOneState(const CDirect3DDevice *_this)
{
    (void)_this;
    return 0;
}

long unsigned int CDirect3DDevice_EndPixelOneToOneState(const CDirect3DDevice *_this)
{
    (void)_this;
    return 0;
}

long unsigned int CDirect3DDevice_SetAlphaFuncAndRef(const CDirect3DDevice *_this, DWORD AlphaFuncValue, DWORD AlphaRefValue)
{
    (void)_this; (void)AlphaFuncValue; (void)AlphaRefValue;
    return 0;
}

GLenum CDirect3DDevice_GetStencilOpFunc(const CDirect3DDevice *_this, UINT32 Value)
{
    (void)_this;
    switch (Value) {
        case 1: return 0x1e00; /* GL_KEEP */
        case 3: return 0x1e01; /* GL_REPLACE */
        case 4: return 0x1e02; /* GL_INCR */
        case 5: return 0x1e03; /* GL_DECR */
        case 6: return 0x150a; /* GL_INVERT - actually GL_INVERT=0x150a */
        case 7: return 0x8507; /* GL_INCR_WRAP */
        case 8: return 0x8508; /* GL_DECR_WRAP */
        default: return 0;
    }
}

long unsigned int CDirect3DDevice_CopyColorToRenderTargetTexture(const CDirect3DDevice *_this)
{
    (void)_this;
    return 0;
}

bool CDirect3DDevice_CTexStage_GetUsesTexture(const CTexStage *_this, bool *UsesTexFactor)
{
    (void)_this; (void)UsesTexFactor;
    return 0;
}

long unsigned int CDirect3DDevice_SetTextureCoordStream(const CDirect3DDevice *_this,
    UINT32 TexUnit, UINT32 TransformFlags, const D3DMATRIX *OriginalTexTransform,
    GLint VSize, UINT32 Tci, UINT32 StartVertex, UINT32 EndVertex,
    const float *pSrcCoords, UINT32 SrcStride, const float *pSrc2Coords, UINT32 Src2Stride)
{
    (void)_this; (void)TexUnit; (void)TransformFlags; (void)OriginalTexTransform;
    (void)VSize; (void)Tci; (void)StartVertex; (void)EndVertex;
    (void)pSrcCoords; (void)SrcStride; (void)pSrc2Coords; (void)Src2Stride;
    return 0;
}

/* CTexCombiner helpers — these are defined IN CDirect3DDevice.c in the original */
long unsigned int COpenGL_SetTexCombinerAlpha3(const COpenGL *_this, UINT32 Unit,
    GLenum AlphaOp, GLenum Source0, GLenum Operand0, GLenum Source1, GLenum Operand1,
    GLenum Source2, GLenum Operand2, float Scale)
{
    (void)_this; (void)Unit; (void)AlphaOp; (void)Source0; (void)Operand0;
    (void)Source1; (void)Operand1; (void)Source2; (void)Operand2; (void)Scale;
    return 0;
}

long unsigned int COpenGL_SetTexCombinerRGB3(const COpenGL *_this, UINT32 Unit,
    GLenum ColorOp, GLenum Source0, GLenum Operand0, GLenum Source1, GLenum Operand1,
    GLenum Source2, GLenum Operand2, GLfloat Scale)
{
    (void)_this; (void)Unit; (void)ColorOp; (void)Source0; (void)Operand0;
    (void)Source1; (void)Operand1; (void)Source2; (void)Operand2; (void)Scale;
    return 0;
}

long unsigned int COpenGL_SetTexCombinerRGB1(const COpenGL *_this, UINT32 Unit,
    GLenum ColorOp, GLenum Source0, GLenum Operand0, GLfloat Scale)
{
    (void)_this; (void)Unit; (void)ColorOp; (void)Source0; (void)Operand0; (void)Scale;
    return 0;
}

long unsigned int COpenGL_SetTexCombinerRGB2(const COpenGL *_this, UINT32 Unit,
    GLenum ColorOp, GLenum Source0, GLenum Operand0, GLenum Source1, GLenum Operand1, GLfloat Scale)
{
    (void)_this; (void)Unit; (void)ColorOp; (void)Source0; (void)Operand0;
    (void)Source1; (void)Operand1; (void)Scale;
    return 0;
}

long unsigned int COpenGL_SetTexCombinerAlpha1(const COpenGL *_this, UINT32 Unit,
    GLenum AlphaOp, GLenum Source0, GLenum Operand0, float Scale)
{
    (void)_this; (void)Unit; (void)AlphaOp; (void)Source0; (void)Operand0; (void)Scale;
    return 0;
}

long unsigned int COpenGL_SetTexCombinerAlpha2(const COpenGL *_this, UINT32 Unit,
    GLenum AlphaOp, GLenum Source0, GLenum Operand0, GLenum Source1, GLenum Operand1, float Scale)
{
    (void)_this; (void)Unit; (void)AlphaOp; (void)Source0; (void)Operand0;
    (void)Source1; (void)Operand1; (void)Scale;
    return 0;
}

/* CTexStage Init — stub */
long unsigned int CDirect3DDevice_CTexStage_Init(const CTexStage *_this, UINT32 Stage, int IsProgrammableStage)
{
    (void)_this; (void)Stage; (void)IsProgrammableStage;
    return 0;
}

/* std::char_traits<char>::eq */
void ZNSt11char_traitsIcE2eqERKcS2_(void) {}

/* std::vector<CDirect3DDevice::CTexStage>::erase */
void ZNSt6vectorIN15CDirect3DDevice9CTexStageESaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_(void) {}

/* std::vector<CDirect3DDevice::CTexStage>::_M_insert_aux */
void ZNSt6vectorIN15CDirect3DDevice9CTexStageESaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_(void) {}

/* ============================================================ */
/* Constructor                                                   */
/* ============================================================ */

/* Called from CDirect3DDevice_CDirect3DDevice and CDirect3DDevice_Init */
long unsigned int CDirect3DDevice_CDirect3DDevice(const CDirect3DDevice *_this,
    UINT Adapter, D3DDEVTYPE DeviceType, ContextRef Context,
    D3DPRESENT_PARAMETERS *pPresentationParameters)
{
    DeviceImpl *dev = (DeviceImpl *)_this;
    (void)Adapter; (void)DeviceType; (void)Context; (void)pPresentationParameters;

    dev->vtable = vtbl_CDirect3DDevice;
    dev->refCount = 1;

    return 0;
}

/* Called from CDirect3D_CreateDevice */
void CDirect3DDevice_Init(void *device)
{
    DeviceImpl *dev = (DeviceImpl *)device;
    dev->vtable = vtbl_CDirect3DDevice;
    dev->refCount = 1;
}

/* ============================================================ */
/* Destructors                                                   */
/* ============================================================ */

void ZN15CDirect3DDeviceD1Ev(void *_this)
{
    DeviceImpl *dev = (DeviceImpl *)_this;
    dev->vtable = vtbl_CDirect3DDevice;
    /* COpenGL_Shutdown skipped - GL calls crash in Mesa/gallium during teardown */
    if (dev->context) {
        MacDisplay_ReleaseContext(&dev->context);
    }
}

void ZN15CDirect3DDeviceD0Ev(void *_this)
{
    ZN15CDirect3DDeviceD1Ev(_this);
    /* Don't free: the device is allocated in a static buffer (deviceMem)
       in CDirect3D.c, not on the heap. */
}

void ZN15CDirect3DDeviceD2Ev(void *_this)
{
    ZN15CDirect3DDeviceD1Ev(_this);
}
