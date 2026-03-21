/* Converted to C from ASM: r_rendertarget.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_rendertarget.cpp */

#include "common_types.h"
#include "imports.h"

extern void *imp_dx;          /* import pointer: address of dx BSS struct */
extern void *imp_vidConfig;   /* import pointer: address of vidConfig BSS struct */
extern void *imp_ri;          /* import pointer: address of ri BSS struct */
extern void *imp_alwaysfails; /* import pointer: always-false flag */
extern void *imp_g_NoTextureID; /* import pointer */

/* Function declarations */
extern const char *va(const char *fmt, ...);
extern void Com_Error(int level, const char *fmt, ...);
extern const char *R_ErrorDescription(HRESULT hr);
extern GfxImage *Image_AllocProg(int imageProgType, int category);
extern void Image_SetupRenderTarget(GfxImage *image, int width, int height, D3DFORMAT imageFormat);
extern void Image_SetupSystem(GfxImage *image, int width, int height, D3DFORMAT imageFormat);
extern IDirect3DSurface9 *Image_GetSurface(GfxImage *image);
extern void Image_Release(GfxImage *image);
extern void Image_TrackFullscreenTexture(GfxImage *image, int picmip, D3DFORMAT format);
extern void Image_TrackTexture(GfxImage *image, int imageFlags, D3DFORMAT format, int width, int height, int depth);

/*
 * Offsets within DxGlobals (accessed via g_dx pointer):
 *   0x08  = device (IDirect3DDevice9*)
 *   0x10  = backBufferFormat (D3DFORMAT)
 *   0x2c24 = multiSampleType
 *   0x2c28 = multiSampleQuality
 *   0x2c30 = renderTargets[0]  (GfxRenderTarget, 20 bytes each)
 *   0x2c34 = renderTargets[0].colorSurface / singleSampleDepthStencilSurface at 0x2d34
 *   0x2d34 = singleSampleDepthStencilSurface
 *   0x2d50 = windows[0] (GfxWindowTarget)
 *
 * vidConfig_t (via g_vidConfig):
 *   0x00 = width
 *   0x04 = height
 *
 * refimport_t (via imp_ri):
 *   0x00 = Printf function pointer
 */

/* Helper to get DxGlobals byte pointer (for legacy offset arithmetic) */
#define DX()          ((byte *)imp_dx)
#define DX_PTR()      ((DxGlobals *)imp_dx)
#define VIDCONFIG()   ((vidConfig_t *)imp_vidConfig)

/* DxGlobals field accessors */
#define DX_DEVICE(dx)                     ((DxGlobals *)(dx))->device
#define DX_BACKBUFFER_FORMAT(dx)          ((DxGlobals *)(dx))->backBufferFormat
#define DX_MULTISAMPLE_TYPE(dx)           ((DxGlobals *)(dx))->multiSampleType  /* TODO: verify offset 0x2c24 */
#define DX_MULTISAMPLE_QUALITY(dx)        ((DxGlobals *)(dx))->multiSampleQuality  /* TODO: verify offset 0x2c28 */
#define DX_RENDERTARGET(dx, i)            ((byte *)&((DxGlobals *)(dx))->renderTargets[i])
#define DX_RT_IMAGE(rt)                   (*(GfxImage **)((rt) + 0))
#define DX_RT_COLOR_SURFACE(rt)           (*(IDirect3DSurface9 **)((rt) + 4))
#define DX_RT_DEPTH_SURFACE(rt)           (*(IDirect3DSurface9 **)((rt) + 8))
#define DX_RT_WIDTH(rt)                   (*(int *)((rt) + 12))
#define DX_RT_HEIGHT(rt)                  (*(int *)((rt) + 16))
#define DX_SINGLE_SAMPLE_DS(dx)           ((DxGlobals *)(dx))->singleSampleDepthStencilSurface  /* TODO: verify offset 0x2d34 */
#define DX_WINDOWS(dx)                    ((byte *)&((DxGlobals *)(dx))->windows)  /* TODO: verify offset 0x2d50 */

/* COM vtable call helpers */
#define VTABLE(obj)         (*(void ***)obj)

/* IDirect3DDevice9 vtable indices (offset / 4) */
/* Release = 2, AddRef = 1 */
/* GetSwapChain = 14 (0x38), GetBackBuffer = vtable[0x38/4] */
/* GetDepthStencilSurface = 18 (0x48) -> actually used for getting render target */
/* CreateDepthStencilSurface = 29 (0x74) */

typedef HRESULT (*D3DDevice_GetBackBufferFn)(void *device, UINT swapChain, UINT backBuffer, void *type, IDirect3DSurface9 **surface);
typedef HRESULT (*D3DDevice_GetRenderTargetFn)(void *device, DWORD renderTargetIndex, void *unused, IDirect3DSurface9 **surface);
typedef HRESULT (*D3DDevice_GetDepthStencilFn)(void *device, DWORD unused1, DWORD unused2, DWORD unused3, IDirect3DSurface9 **surface);
typedef HRESULT (*D3DDevice_CreateDepthStencilFn)(void *device, UINT width, UINT height, D3DFORMAT format, int multiSample, DWORD multiSampleQuality, int discard, IDirect3DSurface9 **surface, void *sharedHandle);
typedef HRESULT (*D3DSurface_GetDescFn)(void *surface, void *desc);
typedef ULONG (*IUnknown_AddRefFn)(void *obj);
typedef ULONG (*IUnknown_ReleaseFn)(void *obj);

/* line 54 */
const char *R_DescribeFormat(int format)
{
    switch (format) {
    case D3DFMT_A8R8G8B8:  /* 21 */
        return "24-bit color with 8-bit alpha";
    case D3DFMT_A1R5G5B5:  /* 25 */
        return "15-bit color with 1-bit alpha";
    case D3DFMT_D32:       /* 71 */
        return "32-bit depth without stencil";
    case D3DFMT_D15S1:     /* 73 */
        return "15-bit depth with 1-bit stencil";
    case D3DFMT_D24S8:     /* 75 */
        return "24-bit depth with 8-bit stencil";
    case D3DFMT_D24X8:     /* 77 */
        return "24-bit depth without stencil";
    case D3DFMT_D16:       /* 80 */
        return "16-bit depth without stencil";
    default:
        return va("unknown format 0x%08x", format);
    }
}

/* Helper: create or reuse the single-sample depth stencil surface */
static IDirect3DSurface9 *R_GetOrCreateDepthStencil(byte *dxPtr, int fullWidth, int fullHeight)
{
    IDirect3DSurface9 *dsSurface;

    dsSurface = DX_SINGLE_SAMPLE_DS(dxPtr);
    if (dsSurface != NULL) {
        /* AddRef the existing surface */
        ((IUnknown_AddRefFn)VTABLE(dsSurface)[1])((void *)dsSurface);
        return DX_SINGLE_SAMPLE_DS(dxPtr);
    }

    /* Check if multiSampleType is 0 and we can reuse renderTargets[0].depthStencilSurface */
    if (DX_MULTISAMPLE_TYPE(dxPtr) == 0) {
        byte *rt0 = DX_RENDERTARGET(dxPtr, 0);
        IDirect3DSurface9 *rt0ds = DX_RT_DEPTH_SURFACE(rt0);
        DX_SINGLE_SAMPLE_DS(dxPtr) = rt0ds;
        if (rt0ds != NULL) {
            ((IUnknown_AddRefFn)VTABLE(rt0ds)[1])((void *)rt0ds);
            return DX_SINGLE_SAMPLE_DS(dxPtr);
        }
    }

    /* Create a new depth stencil surface */
    {
        void *device = DX_DEVICE(dxPtr);
        void **vtable = VTABLE(device);
        HRESULT hr;
        int w = fullWidth;
        int h = fullHeight;

        hr = ((D3DDevice_CreateDepthStencilFn)vtable[0x74 / 4])(
            device, w, h, D3DFMT_D24S8, 0, 0, 0,
            &DX_SINGLE_SAMPLE_DS(dxPtr), NULL);

        if (hr < 0) {
            const char *desc = R_ErrorDescription(hr);
            Com_Error(0, "Couldn't create a %i x %i depth-stencil surface: %s\n", w, h, desc);
        }
    }

    return DX_SINGLE_SAMPLE_DS(dxPtr);
}

/* line 412 */
static void R_InitFullscreenRenderTargetImage(int imageProgId, int picmip, D3DFORMAT format, RenderTargetUsage usage, GfxRenderTarget *renderTarget)
{
    vidConfig_t *vidCfg = VIDCONFIG();
    int fullWidth = vidCfg->width;
    int fullHeight = vidCfg->height;
    int width, height;

    width = fullWidth >> (byte)picmip;
    if (width <= 0) width = 1;
    height = fullHeight >> (byte)picmip;
    if (height <= 0) height = 1;

    /* Allocate a prog image */
    renderTarget->image = Image_AllocProg(imageProgId, 6);

    /* Setup the render target image */
    if (usage == RENDERTARGET_USAGE_READBACK) {
        Image_SetupSystem(renderTarget->image, (unsigned short)width, (unsigned short)height, format);
    } else {
        Image_SetupRenderTarget(renderTarget->image, (unsigned short)width, (unsigned short)height, format);
    }

    /* Get the surface and store dimensions */
    renderTarget->colorSurface = Image_GetSurface(renderTarget->image);
    renderTarget->width = (unsigned short)width;
    renderTarget->height = (unsigned short)height;

    /* For RENDERTARGET_USAGE_RENDER, set up the depth stencil surface */
    if (usage == RENDERTARGET_USAGE_RENDER) {
        byte *dxPtr = DX();
        IDirect3DSurface9 *dsSurface = R_GetOrCreateDepthStencil(dxPtr, fullWidth, fullHeight);
        renderTarget->depthStencilSurface = dsSurface;
    }

    /* Track the fullscreen texture */
    Image_TrackFullscreenTexture(renderTarget->image, picmip, format);
}

/* Helper for creating 128x128 depth stencil for small render targets */
static IDirect3DSurface9 *R_CreateSmallDepthStencil(byte *dxPtr)
{
    IDirect3DSurface9 *existing = *(IDirect3DSurface9 **)(dxPtr + 0x2c88);
    if (existing != NULL) {
        /* AddRef the existing surface */
        ((IUnknown_AddRefFn)VTABLE(existing)[1])((void *)existing);
        return *(IDirect3DSurface9 **)(dxPtr + 0x2c88);
    }

    /* Create a new 128x128 depth stencil surface */
    {
        void *device = DX_DEVICE(dxPtr);
        void **vtable = VTABLE(device);
        IDirect3DSurface9 *newSurface = NULL;
        HRESULT hr;

        *(byte *)imp_g_NoTextureID = 1;
        hr = ((D3DDevice_CreateDepthStencilFn)vtable[0x74 / 4])(
            device, 128, 128, D3DFMT_D24S8, 0, 0, 0,
            &newSurface, NULL);
        *(byte *)imp_g_NoTextureID = 0;

        if (hr < 0) {
            const char *desc = R_ErrorDescription(hr);
            Com_Error(0, "Couldn't create a %i x %i depth-stencil surface: %s\n", 128, 128, desc);
        }

        return newSurface;
    }
}

/* line 578 */
long int R_ShutdownRenderTargets(void)
{
    int renderTargetId;
    byte *dxPtr;

    for (renderTargetId = 0; renderTargetId <= 12; renderTargetId++) {
        /* Skip RESOLVED_POST_SUN (1) and SAVED_SCREEN (7) */
        if (renderTargetId == 1 || renderTargetId == 7) {
            continue;
        }

        dxPtr = DX();
        byte *rt = DX_RENDERTARGET(dxPtr, renderTargetId);

        /* Release color surface */
        {
            IDirect3DSurface9 *colorSurf = DX_RT_COLOR_SURFACE(rt);
            if (colorSurf != NULL) {
                ((IUnknown_ReleaseFn)VTABLE(colorSurf)[2])((void *)colorSurf);
            }
        }

        /* Release depth stencil surface */
        {
            IDirect3DSurface9 *dsSurf = DX_RT_DEPTH_SURFACE(rt);
            if (dsSurf != NULL) {
                ((IUnknown_ReleaseFn)VTABLE(dsSurf)[2])((void *)dsSurf);
            }
        }

        /* Release image */
        {
            GfxImage *img = DX_RT_IMAGE(rt);
            if (img != NULL) {
                Image_Release(img);
            }
        }
    }

    /* Clear all render target memory */
    dxPtr = DX();
    memset(dxPtr + 0x2c30, 0, 0x104);

    /* Clear singleSampleDepthStencilSurface */
    DX_SINGLE_SAMPLE_DS(dxPtr) = 0;

    return 0;
}

/* line 504 */
long int R_InitRenderTargets(void)
{
    byte *dxPtr;
    vidConfig_t *vidCfg;
    int fullWidth, fullHeight;
    void *device;
    void **vtable;
    HRESULT hr;
    D3DFORMAT backBufferFormat;
    D3DFORMAT surfaceFormat;
    _D3DSURFACE_DESC desc;

    /* line 210-211: Store display dimensions */
    dxPtr = DX();
    vidCfg = VIDCONFIG();
    fullWidth = vidCfg->width;
    DX_PTR()->renderTargets[0].width = fullWidth;
    fullHeight = vidCfg->height;
    DX_PTR()->renderTargets[0].height = fullHeight;

    /* line 213: Get back buffer - device->GetBackBuffer(0, 0, &dx.windows[0]) */
    device = DX_DEVICE(dxPtr);
    vtable = VTABLE(device);
    hr = ((HRESULT (*)(void *, UINT, byte *))vtable[0x38 / 4])(
        device, 0, (byte *)&DX_PTR()->windows[0]); /* TODO: verify offset 0x2d50 */

    /* line 214 */
    if (hr < 0) {
        const char *errDesc = R_ErrorDescription(hr);
        Com_Error(0, "Couldn't get an interface to the swap chain: %s\n", errDesc);
    }

    /* line 217: Get render target - device->GetRenderTarget(0, 0, 0, &dx.renderTargets[0].colorSurface) */
    do {
        dxPtr = DX();
        device = DX_DEVICE(dxPtr);
        vtable = VTABLE(device);
        hr = ((HRESULT (*)(void *, DWORD, DWORD, DWORD, byte *))vtable[0x48 / 4])(
            device, 0, 0, 0, (byte *)&DX_PTR()->renderTargets[0].colorSurface);

        /* Check if iteration needed */
    } while (*(int *)imp_alwaysfails != 0);

    /* line 108-109: Get full screen dimensions from vidConfig */
    vidCfg = VIDCONFIG();
    fullWidth = vidCfg->width;
    fullHeight = vidCfg->height;

    /* line 223-226: Create main depth stencil surface */
    {
        byte *creatingTex = (byte *)imp_g_NoTextureID;
        *creatingTex = 1;

        dxPtr = DX();
        device = DX_DEVICE(dxPtr);
        vtable = VTABLE(device);

        hr = ((D3DDevice_CreateDepthStencilFn)vtable[0x74 / 4])(
            device, fullWidth, fullHeight, D3DFMT_D24S8,
            DX_MULTISAMPLE_TYPE(dxPtr), DX_MULTISAMPLE_QUALITY(dxPtr),
            0, (IDirect3DSurface9 **)(dxPtr + 0x2c38), NULL);

        *creatingTex = 0;

        if (hr < 0) {
            const char *errDesc = R_ErrorDescription(hr);
            Com_Error(0, "Couldn't create a %i x %i depth-stencil surface: %s\n", fullWidth, fullHeight, errDesc);
        }
    }

    /* line 491: Print requested frame buffer format */
    {
        void (*riPrintf)() = *(void (**)())imp_ri;
        riPrintf(0, "Requested frame buffer to be %s\n", "24-bit color with 8-bit alpha");

        /* line 492: Get the actual format of the color surface */
        dxPtr = DX();
        {
            IDirect3DSurface9 *colorSurf = *(IDirect3DSurface9 **)(dxPtr + 0x2c34);
            void **surfVtable = VTABLE(colorSurf);
            ((D3DSurface_GetDescFn)surfVtable[0x30 / 4])((void *)colorSurf, &desc);
        }

        /* line 493: Store the actual format */
        surfaceFormat = desc.Format;
        *(D3DFORMAT *)(dxPtr + 0x10) = surfaceFormat;

        /* line 495: Print actual format */
        riPrintf = *(void (**)())imp_ri;
        riPrintf(0, "DirectX returned a frame buffer that is %s\n", R_DescribeFormat(surfaceFormat));
    }

    /* line 517: Init render targets[3] (DYNAMICSHADOWS) - full size, no picmip */
    dxPtr = DX();
    backBufferFormat = DX_BACKBUFFER_FORMAT(dxPtr);
    R_InitFullscreenRenderTargetImage(0, 0, backBufferFormat, RENDERTARGET_USAGE_RENDER,
        (GfxRenderTarget *)(dxPtr + 0x2c6c));

    /* line 520: Copy renderTargets[3] to renderTargets[1] (RESOLVED_POST_SUN) */
    {
        byte *rt3 = DX_RENDERTARGET(dxPtr, 3);
        byte *rt1 = DX_RENDERTARGET(dxPtr, 1);
        *(void **)(rt1 + 0) = *(void **)(rt3 + 0);
        *(void **)(rt1 + 4) = *(void **)(rt3 + 4);
        *(void **)(rt1 + 8) = *(void **)(rt3 + 8);
        *(int *)(rt1 + 12) = *(int *)(rt3 + 12);
        *(int *)(rt1 + 16) = *(int *)(rt3 + 16);
    }

    /* line 521: Init renderTargets[2] (RESOLVED_SCENE) - format D3DFMT_A4R4G4B4 (=9?), picmip=0, usage=TEXTURE */
    backBufferFormat = DX_BACKBUFFER_FORMAT(dxPtr);
    R_InitFullscreenRenderTargetImage(9, 0, backBufferFormat, RENDERTARGET_USAGE_TEXTURE,
        (GfxRenderTarget *)(dxPtr + 0x2c58));

    /* line 522: Copy renderTargets[1] to renderTargets[7] (SAVED_SCREEN) */
    {
        byte *rt1 = DX_RENDERTARGET(dxPtr, 1);
        byte *rt7 = DX_RENDERTARGET(dxPtr, 7);
        *(void **)(rt7 + 0) = *(void **)(rt1 + 0);
        *(void **)(rt7 + 4) = *(void **)(rt1 + 4);
        *(void **)(rt7 + 8) = *(void **)(rt1 + 8);
        *(int *)(rt7 + 12) = *(int *)(rt1 + 12);
        *(int *)(rt7 + 16) = *(int *)(rt1 + 16);
    }

    /* Init renderTargets[4] (SHADOWCOOKIE) - 128x128 A8R8G8B8 render target */
    {
        GfxImage *image;
        IDirect3DSurface9 *depthSurface;

        /* line 366: Allocate image prog 1 */
        image = Image_AllocProg(1, 6);
        *(GfxImage **)(dxPtr + 0x2c80) = image;

        /* line 371: Setup as 128x128 A8R8G8B8 render target */
        Image_SetupRenderTarget(image, 128, 128, D3DFMT_A8R8G8B8);

        /* line 373: Get surface */
        image = *(GfxImage **)(dxPtr + 0x2c80);
        *(IDirect3DSurface9 **)(dxPtr + 0x2c84) = Image_GetSurface(image);
        *(int *)(dxPtr + 0x2c8c) = 128;   /* line 374: width */
        *(int *)(dxPtr + 0x2c90) = 128;   /* line 375: height */

        /* line 383: Track texture */
        Image_TrackTexture(*(GfxImage **)(dxPtr + 0x2c80), 3, D3DFMT_A8R8G8B8, 128, 128, 1);

        /* line 174: Get or create 128x128 depth stencil for shadow cookie */
        depthSurface = R_CreateSmallDepthStencil(dxPtr);
        dxPtr = DX();
        *(IDirect3DSurface9 **)(dxPtr + 0x2c88) = depthSurface;
    }

    /* Init renderTargets[5] (SHADOWCOOKIE_BLUR) - 128x128 A8R8G8B8 render target */
    {
        GfxImage *image;
        IDirect3DSurface9 *depthSurface;

        /* line 366: Allocate image prog 2 */
        image = Image_AllocProg(2, 6);
        *(GfxImage **)(dxPtr + 0x2c94) = image;

        /* line 371: Setup as 128x128 A8R8G8B8 render target */
        Image_SetupRenderTarget(image, 128, 128, D3DFMT_A8R8G8B8);

        /* line 373: Get surface */
        image = *(GfxImage **)(dxPtr + 0x2c94);
        *(IDirect3DSurface9 **)(dxPtr + 0x2c98) = Image_GetSurface(image);
        *(int *)(dxPtr + 0x2ca0) = 128;   /* line 374: width */
        *(int *)(dxPtr + 0x2ca4) = 128;   /* line 375: height */

        /* line 383: Track texture */
        Image_TrackTexture(*(GfxImage **)(dxPtr + 0x2c94), 3, D3DFMT_A8R8G8B8, 128, 128, 1);

        /* line 174: Reuse 128x128 depth stencil */
        depthSurface = R_CreateSmallDepthStencil(dxPtr);
        dxPtr = DX();
        *(IDirect3DSurface9 **)(dxPtr + 0x2c9c) = depthSurface;
    }

    /* line 543: Init renderTargets[8] (BLURRED_SCREEN) - picmip=2, format=backBufferFormat, usage=READBACK */
    dxPtr = DX();
    backBufferFormat = DX_BACKBUFFER_FORMAT(dxPtr);
    R_InitFullscreenRenderTargetImage(3, 2, backBufferFormat, RENDERTARGET_USAGE_READBACK,
        (GfxRenderTarget *)(dxPtr + 0x2cd0));

    /* line 544: Init renderTargets[9] (GLOW_0) */
    backBufferFormat = DX_BACKBUFFER_FORMAT(dxPtr);
    R_InitFullscreenRenderTargetImage(4, 2, backBufferFormat, RENDERTARGET_USAGE_READBACK,
        (GfxRenderTarget *)(dxPtr + 0x2ce4));

    /* line 545: Init renderTargets[10] (GLOW_1) */
    backBufferFormat = DX_BACKBUFFER_FORMAT(dxPtr);
    R_InitFullscreenRenderTargetImage(5, 2, backBufferFormat, RENDERTARGET_USAGE_READBACK,
        (GfxRenderTarget *)(dxPtr + 0x2cf8));

    /* line 552: Init renderTargets[11] (PINGPONG_0) */
    backBufferFormat = DX_BACKBUFFER_FORMAT(dxPtr);
    R_InitFullscreenRenderTargetImage(6, 2, backBufferFormat, RENDERTARGET_USAGE_READBACK,
        (GfxRenderTarget *)(dxPtr + 0x2d0c));

    /* line 553: Init renderTargets[12] (PINGPONG_1) */
    backBufferFormat = DX_BACKBUFFER_FORMAT(dxPtr);
    R_InitFullscreenRenderTargetImage(7, 2, backBufferFormat, RENDERTARGET_USAGE_READBACK,
        (GfxRenderTarget *)(dxPtr + 0x2d20));

    return 0;
}
