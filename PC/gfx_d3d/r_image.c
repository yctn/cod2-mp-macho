/* ASM dump from: r_image.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_image.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 *   #include "PC/gfx_d3d/r_image.h"
 */

extern const char * g_platform_name[2]; /* 0x0 */
static int imageGlobals[2064]; /* imageGlobals */
static GfxImage g_imageProgs[12]; /* g_imageProgs */
extern const char str_00224568[];
extern const char str_00225118[];
extern const char str_00225120[];
extern const char str_00225128[];
extern const char str_00225130[];
extern const char str_00225138[];
extern const char str_00225140[];
extern const char str_00225148[];
extern const char str_00225150[];
extern const char str_00225158[];
extern const char str_00225160[];
extern const char str_00225168[];
extern const char str_0022517c[];
extern const char str_0022518c[];
extern const char str_002251a0[];
extern const char str_002251b0[];
extern const char str_002251b8[];
extern const char str_002251c0[];
extern const char str_002251cc[];
extern const char str_002251d8[];
extern const char str_002251ec[];
extern const char str_002251fc[];

__attribute__((used, packed, aligned(4)))
UInt32 imageTypeName_storage[16] __asm__("imageTypeName") = {
    (UInt32)str_00225118,
    (UInt32)str_00225120,
    (UInt32)str_00225128,
    (UInt32)str_00225130,
    (UInt32)str_00225138,
    (UInt32)str_00225140,
    (UInt32)str_00225148,
    (UInt32)str_00225150,
    (UInt32)str_00225158,
    (UInt32)str_00225160,
    0,
    0,
    0,
    0,
    0,
    0,
}; /* 0x3111c0 */
__attribute__((used, packed, aligned(4)))
UInt32 g_imageProgNames_storage[16] __asm__("g_imageProgNames") = {
    (UInt32)str_00225168,
    (UInt32)str_0022517c,
    (UInt32)str_0022518c,
    (UInt32)str_002251a0,
    (UInt32)str_002251b0,
    (UInt32)str_002251b8,
    (UInt32)str_002251c0,
    (UInt32)str_002251cc,
    (UInt32)str_002251d8,
    (UInt32)str_002251ec,
    (UInt32)str_002251fc,
    (UInt32)str_00224568,
    0,
    0,
    0,
    0,
}; /* 0x311200 */

#define imageTypeName ((const char * const *)imageTypeName_storage)
#define g_imageProgNames ((const char * const *)g_imageProgNames_storage)

static void R_AddImageToList(union XAssetHeader header, void *data);
extern void DB_EnumXAssets(int type, void (*func)(union XAssetHeader, void *), void *data, int overrides);
extern Bool Image_LoadFromFile(GfxImage *image);
extern void R_Error(int level, const char *msg, ...);
void R_GetImageList(ImageList *imageList);
int R_GetMinSpecImageMemory(void);
void R_ResetImageAllocations(void);
void R_FreeImageAllocations(void);
void Image_Create2DTexture(GfxImage *image, int width, int height, int mipmapCount, DWORD usage, D3DFORMAT imageFormat, D3DPOOL memPool);
void Image_Create3DTexture(GfxImage *image, int width, int height, int depth, int mipmapCount, DWORD usage, D3DFORMAT imageFormat, D3DPOOL memPool);
void Image_CreateCubeTexture(GfxImage *image, int edgeLen, int mipmapCount, DWORD usage, D3DFORMAT imageFormat, D3DPOOL memPool);
void Image_PicmipForSemantic(int semantic, Picmip *picmip);
IDirect3DSurface9 * Image_GetSurface(GfxImage *image);
void R_SetPicmip(void);
static int imagecompare(GfxImage *image1, GfxImage *image2);
water_t * R_LoadWaterSetup(const water_t *water);
void R_DownsampleMipMapBilinear(const byte *src, int srcBufferSize, int srcWidth, int srcHeight, int texelPitch, byte *dst, int dstBufferSize);
void Image_Release(GfxImage *image);
void R_ReloadLostImages(void);
void Image_TrackTexture(GfxImage *image, int imageFlags, D3DFORMAT format, int width, int height, int depth);
void Image_TrackFullscreenTexture(GfxImage *image, int picmip, D3DFORMAT format);
GfxImage * Image_AllocProg(int imageProgType, int category);
GfxImage * Image_Alloc(const char *name, int category, int semantic, int imageTrack);
void R_ImageList_f(void);
GfxImage * Image_Register(const char *imageName, int semantic, int imageTrack);
void R_InitImages(void);
void Image_SetupRenderTarget(GfxImage *image, int width, int height, D3DFORMAT imageFormat);
void Image_SetupSystem(GfxImage *image, int width, int height, D3DFORMAT imageFormat);
void Image_RebuildCosinePowerMap(float shift);
void R_ShutdownImages(void);
void R_ReleaseLostImages(void);
void Image_UpdatePicmip(GfxImage *image);
void Image_Reload(GfxImage *image);
typedef int (*GfxImageCompFunc)(GfxImage *, GfxImage *);
void ZSt13__adjust_heapIPP8GfxImageiS1_PFiS1_S1_EEvT_T0_S6_T1_T2_(GfxImage **first, int holeIndex, int len, GfxImage *value, GfxImageCompFunc comp);
void ZSt16__insertion_sortIPP8GfxImagePFiS1_S1_EEvT_S5_T0_(GfxImage **first, GfxImage **last, GfxImageCompFunc comp);
void ZSt16__introsort_loopIPP8GfxImageiPFiS1_S1_EEvT_S5_T0_T1_(GfxImage **first, GfxImage **last, int depth_limit, GfxImageCompFunc comp);

/* line 183 */
static void R_AddImageToList(union XAssetHeader header, void *data)
{
    int *list = (int *)data;
    int count = list[0];
    list[1 + count] = (int)header.data;
    list[0] = count + 1;
}

/* line 194 */
void R_GetImageList(ImageList *imageList)
{
    imageList->count = 0;
    DB_EnumXAssets(3, R_AddImageToList, imageList, 1);
}

/* line 255 */
int R_GetMinSpecImageMemory(void)
{
    return imageGlobals[2052];
}

/* line 637 */
void R_ResetImageAllocations(void)
{
}

/* line 642 */
void R_FreeImageAllocations(void)
{
}

/* line 648 */
extern const char *R_ErrorDescription(HRESULT hr);

void Image_Create2DTexture(GfxImage *image, int width, int height, int mipmapCount, DWORD usage, D3DFORMAT imageFormat, D3DPOOL memPool)
{
    byte *img = (byte *)image;
    void *device;
    void **vtable;
    HRESULT hr;

    image->width = (unsigned short)width;
    image->height = (unsigned short)height;
    image->depth = 1;
    image->mapType = 3; /* texture type = 2D */

    /* IDirect3DDevice9::CreateTexture — vtable 0x5C */
    device = ((DxGlobals *)imp_dx)->device;
    if (!device) { image->texture.map = NULL; return 0; }
    vtable = *(void ***)device;
    hr = ((HRESULT (*)(void *, UINT, UINT, UINT, DWORD, DWORD, DWORD, void **, void *))(vtable[0x5C / 4]))(
        device, (unsigned short)width, (unsigned short)height,
        mipmapCount, usage, imageFormat, memPool, (void **)&image->texture.map, NULL);

    if (hr < 0) {
        R_Error(1, "Create2DTexture( %s, %i, %i, %i, %i ) failed: %08x = %s",
            image->name,
            (int)image->width,
            (int)image->height,
            0, (int)imageFormat, (int)hr, R_ErrorDescription(hr));
    }
}

/* line 669 */
void Image_Create3DTexture(GfxImage *image, int width, int height, int depth, int mipmapCount, DWORD usage, D3DFORMAT imageFormat, D3DPOOL memPool)
{
    byte *img = (byte *)image;
    void *device;
    void **vtable;
    HRESULT hr;

    image->width = (unsigned short)width;
    image->height = (unsigned short)height;
    image->depth = (unsigned short)depth;
    image->mapType = 4; /* texture type = 3D/volume */

    /* IDirect3DDevice9::CreateVolumeTexture — vtable 0x60 */
    device = ((DxGlobals *)imp_dx)->device;
    if (!device) { image->texture.map = NULL; return 0; }
    vtable = *(void ***)device;
    hr = ((HRESULT (*)(void *, UINT, UINT, UINT, UINT, DWORD, DWORD, DWORD, void **, void *))(vtable[0x60 / 4]))(
        device, (unsigned short)width, (unsigned short)height, (unsigned short)depth,
        mipmapCount, usage, imageFormat, memPool, (void **)&image->texture.map, NULL);

    if (hr < 0) {
        R_Error(1, "Create3DTexture( %s, %i, %i, %i, %i, %i ) failed: %08x = %s",
            image->name,
            (int)image->width,
            (int)image->height,
            (int)image->depth,
            0, (int)imageFormat, (int)hr, R_ErrorDescription(hr));
    }
}

/* line 690 */
void Image_CreateCubeTexture(GfxImage *image, int edgeLen, int mipmapCount, DWORD usage, D3DFORMAT imageFormat, D3DPOOL memPool)
{
    byte *img = (byte *)image;
    byte *dx;
    void *device;
    void **vtable;
    HRESULT hr;
    int actualMipCount;

    image->width = (unsigned short)edgeLen;
    image->height = (unsigned short)edgeLen;
    image->depth = 1;
    image->mapType = 5; /* texture type = cube */

    /* Check if cubemap mipmaps are supported */
    if (((DxGlobals *)imp_dx)->canMipCubemaps)
        actualMipCount = mipmapCount;
    else
        actualMipCount = 1;

    /* IDirect3DDevice9::CreateCubeTexture — vtable 0x64 */
    device = ((DxGlobals *)imp_dx)->device;
    if (!device) { image->texture.map = NULL; return 0; }
    vtable = *(void ***)device;
    hr = ((HRESULT (*)(void *, UINT, UINT, DWORD, DWORD, DWORD, void **, void *))(vtable[0x64 / 4]))(
        device, (unsigned short)edgeLen, actualMipCount, 0, imageFormat, memPool,
        (void **)&image->texture.map, NULL);

    if (hr < 0) {
        R_Error(1, "CreateCubeTexture ( %s, %i, %i, %i ) failed: %08x = %s",
            image->name,
            (int)image->width,
            mipmapCount, (int)imageFormat, (int)hr, R_ErrorDescription(hr));
    }
}

/* line 752 */
void Image_PicmipForSemantic(int semantic, Picmip *picmip)
{
    byte s = (byte)semantic;
    int val;

    switch (s) {
    case 2:
    case 5:
        val = imageGlobals[2048]; /* imageGlobals+8192 */
        break;
    case 3:
        val = imageGlobals[2049]; /* imageGlobals+8196 */
        break;
    case 4:
        val = imageGlobals[2050]; /* imageGlobals+8200 */
        break;
    default:
        *(unsigned short *)picmip = 0;
        return;
    }

    ((byte *)picmip)[1] = 2;
    if (val < 0)
        ((byte *)picmip)[0] = 0;
    else
        ((byte *)picmip)[0] = (byte)(val < 4 ? val : 3);
}

/* line 1068 */
IDirect3DSurface9 * Image_GetSurface(GfxImage *image)
{
    IDirect3DSurface9 *surface;
    void *texture;
    void **vtable;

    /* IDirect3DTexture9::GetSurfaceLevel(0, &surface) — vtable 0x48 */
    do {
        texture = image->texture.map;
        vtable = *(void ***)texture;
        ((HRESULT (*)(void *, UINT, IDirect3DSurface9 **))(vtable[0x48 / 4]))(texture, 0, &surface);
    } while (*(volatile int *)imp_alwaysfails);

    return surface;
}

/* line 1130 */
extern int R_AvailableTextureMemory(void);

void R_SetPicmip(void)
{
    byte *ri = (byte *)imp_ri;
    void (*ri_Printf)(int, const char *, ...) = *(void (**)(int, const char *, ...))ri;
    void (*Cvar_SetValue)(void *, int) = (void (*)(void *, int))((refimport_t *)ri)->Dvar_SetInt;
    int (*Cvar_VariableIntegerValue)(const char *) = (int (*)(const char *))((refimport_t *)ri)->Dvar_GetInt;
    int texMemInMegs, sysMemInMegs;
    int minPicmip;
    int changed;

    texMemInMegs = R_AvailableTextureMemory();
    sysMemInMegs = Cvar_VariableIntegerValue("sys_sysMB");

    /* Manual picmip override */
    if ((*(const dvar_t **)imp_r_picmip_manual)->current.enabled) {
        ri_Printf(0, "Using manual picmip settings\n");
        imageGlobals[2048] = (*(const dvar_t **)imp_r_picmip)->current.integer;
        imageGlobals[2049] = (*(const dvar_t **)imp_r_picmip_bump)->current.integer;
        imageGlobals[2050] = (*(const dvar_t **)imp_r_picmip_spec)->current.integer;
    } else if ((*(const dvar_t **)imp_r_rendererInUse)->current.integer == 2) {
        /* Dx7 renderer */
        ri_Printf(0, "Dx7 renderer: using low-res textures\n");
        if (texMemInMegs > 128) {
            imageGlobals[2048] = 1;
            imageGlobals[2049] = 1;
            imageGlobals[2050] = 1;
        } else {
            imageGlobals[2048] = 2;
            imageGlobals[2049] = 2;
            imageGlobals[2050] = 2;
        }

        /* Apply system memory constraints */
        if (sysMemInMegs <= 383) {
            minPicmip = 1;
            goto apply_sysmem;
        }
    } else {
        /* Non-Dx7 renderer */
        ri_Printf(0, "Using non-Dx7 renderer\n");
        imageGlobals[2048] = 2;
        imageGlobals[2049] = 2;
        imageGlobals[2050] = 2;

        if (sysMemInMegs <= 383) {
            if (sysMemInMegs <= 479) {
                minPicmip = 1;
                goto apply_sysmem;
            }
        } else {
            minPicmip = 2;
apply_sysmem:
            changed = 0;
            if (imageGlobals[2048] < minPicmip) {
                imageGlobals[2048] = minPicmip;
                changed = 1;
            }
            if (imageGlobals[2049] < minPicmip) {
                imageGlobals[2049] = minPicmip;
                changed = 1;
            }
            if (imageGlobals[2050] < minPicmip) {
                imageGlobals[2050] = minPicmip;
                changed = 1;
            } else if (!changed) {
                goto set_cvars;
            }
            ri_Printf(0, "Reducing texture detail based on total system memory of %i M", sysMemInMegs);
        }
    }

set_cvars:
    /* Set cvar values to match computed picmip levels */
    ri = (byte *)imp_ri;
    Cvar_SetValue = (void (*)(void *, int))((refimport_t *)ri)->Dvar_SetInt;
    ri_Printf = *(void (**)(int, const char *, ...))ri;
    Cvar_SetValue(*(void **)imp_r_picmip, imageGlobals[2048]);
    Cvar_SetValue(*(void **)imp_r_picmip_bump, imageGlobals[2049]);
    Cvar_SetValue(*(void **)imp_r_picmip_spec, imageGlobals[2050]);
    ri_Printf(0, "Using picmip %i on most textures, %i on normal maps, and %i on spec maps",
        imageGlobals[2048], imageGlobals[2049], imageGlobals[2050]);
}

/* line 1301 */
static int imagecompare(GfxImage *image1, GfxImage *image2)
{
    if (image1->track > image2->track)
        return 0;
    if (image1->track < image2->track)
        return 1;
    return image1->cardMemory.platform[0] < image2->cardMemory.platform[0];
}

/* line 1507 */
extern void Com_Printf(const char *fmt, ...);
extern int R_WatersEquivalent(const water_t *a, const water_t *b);
extern void R_CreateWaterSetup(const water_t *water, int index, water_t *dest);

water_t * R_LoadWaterSetup(const water_t *water)
{
    byte *rg = (byte *)imp_rg;
    int waterCount = ((r_globals_t *)rg)->sceneWaterMapSetupsCount;
    int i;
    water_t *slot;

    /* Check existing water setups for match */
    for (i = 0; i < waterCount; i++) {
        rg = (byte *)imp_rg;
        /* Each water setup is 68 bytes (64 + 4 = index*64 + index*4 = index*68),
         * stored at rg + 0xc + 0x1020 + i*68 */
        slot = (water_t *)(rg + 0xc + 0x1020 + i * 68);
        if (R_WatersEquivalent(slot, water))
            return slot;
    }

    /* No match found — create new one */
    if (i == 16) {
        Com_Printf("^1ERROR: map uses more than %i waterMap textures\n", 16);
        return NULL;
    }

    rg = (byte *)imp_rg;
    slot = (water_t *)(rg + 0xc + 0x1020 + i * 68);
    R_CreateWaterSetup(water, i, slot);
    ((r_globals_t *)rg)->sceneWaterMapSetupsCount += 1;

    return slot;
}

/* line 1566 */
void R_DownsampleMipMapBilinear(const byte *src, int srcBufferSize, int srcWidth, int srcHeight, int texelPitch, byte *dst, int dstBufferSize)
{
    int dstWidth, dstHeight;
    int srcRowPitch, dstRowPitch;
    int row, col, ch;

    (void)srcBufferSize;
    (void)dstBufferSize;

    /* 1x1 source: nothing to downsample */
    if (srcWidth == 1 && srcHeight == 1)
        return;

    dstWidth = srcWidth >> 1;
    dstHeight = srcHeight >> 1;
    srcRowPitch = srcWidth * texelPitch;
    dstRowPitch = dstWidth * texelPitch;

    /* Degenerate case: one dimension is 0 after halving (1xN or Nx1 source) */
    if (dstWidth == 0 || dstHeight == 0) {
        int totalTexels = dstWidth + dstHeight;
        const byte *srcPos = src;
        byte *dstPos = dst;
        int srcStride = texelPitch * 2;

        for (col = 0; col < totalTexels; col++) {
            for (ch = 0; ch < texelPitch; ch++) {
                /* Average 2 adjacent texels along the non-degenerate axis */
                dstPos[ch] = (byte)(((int)srcPos[ch] + (int)srcPos[ch + texelPitch]) >> 1);
            }
            dstPos += texelPitch;
            srcPos += srcStride;
        }
        return;
    }

    /* Normal 2D downsample: average 2x2 blocks */
    for (row = 0; row < dstHeight; row++) {
        const byte *srcRow = src + row * 2 * srcRowPitch;
        byte *dstRow = dst + row * dstRowPitch;

        for (col = 0; col < dstWidth; col++) {
            const byte *srcTexel = srcRow;
            const byte *srcTexelNextRow = srcRow + texelPitch + srcRowPitch;

            for (ch = 0; ch < texelPitch; ch++) {
                /* Average 4 texels: (row,col), (row,col+1), (row+1,col), (row+1,col+1) */
                int sum = (int)srcTexel[ch];
                sum += (int)srcTexel[ch + texelPitch];
                sum += (int)srcTexel[ch + srcRowPitch];
                sum += (int)srcTexelNextRow[0];
                dstRow[ch] = (byte)(sum >> 2);
                srcTexelNextRow++;
            }
            dstRow += texelPitch;
            srcRow += texelPitch * 2;
        }
    }
}

/* line 276 */
void Image_Release(GfxImage *image)
{
    byte *img = (byte *)image;
    signed char mapType = (signed char)image->track;
    void *texture;
    void **vtable;
    int i;

    /* Check if this image type needs global memory accounting:
     * types > 4, or types 0-4 where (1 << type) & 0x13 == 0 */
    if ((byte)mapType > 4 || !((1 << mapType) & 0x13)) {
        /* Subtract per-platform memory tracking from imageGlobals totals */
        for (i = 0; i < 2; i++) {
            imageGlobals[0x200c / 4 + i] -= image->cardMemory.platform[i];
        }
    }

    /* Release COM texture object if present */
    texture = image->texture.map;
    if (texture) {
        vtable = *(void ***)texture;
        if (vtable && vtable[8 / 4])
            ((ULONG (*)(void *))(vtable[8 / 4]))(texture); /* Release — vtable 0x08 */
        image->texture.map = NULL;
        image->cardMemory.platform[0] = 0;
        image->cardMemory.platform[1] = 0;
    }

    image->mapType = 0;
}

/* line 935 */
extern void Image_BuildWaterMap(GfxImage *image);

void R_ReloadLostImages(void)
{
    int i;

    for (i = 0; i < 2048; i++) {
        GfxImage *image = (GfxImage *)imageGlobals[i];
        byte category;
        int isProg;

        if (!image)
            continue;

        category = image->category;
        if (category <= 4)
            continue;

        /* Skip images that already have a texture */
        if (image->texture.map != NULL)
            continue;

        /* Check if image is in g_imageProgs range */
        isProg = ((char *)image >= (char *)g_imageProgs &&
                  (char *)image < (char *)g_imageProgs + 432);

        if (isProg)
            continue;

        /* Only rebuild water maps (category 5) */
        if (category != 5)
            continue;

        Image_BuildWaterMap(image);
    }
}

/* line 388 */
extern int Image_GetCardMemoryAmount(int imageFlags, D3DFORMAT format, int width, int height, int depth);

void Image_TrackTexture(GfxImage *image, int imageFlags, D3DFORMAT format, int width, int height, int depth)
{
    byte *img = (byte *)image;
    signed char mapType = (signed char)image->track;
    int needsGlobalAccounting;
    int amount;
    int i;

    /* Check if this image type needs per-image tracking (bit test) */
    needsGlobalAccounting = ((byte)mapType > 4) || !((1 << mapType) & 0x13);

    if (!(imageFlags & 1)) {
        /* Multi-platform path: iterate per-platform picmip levels */
        for (i = 0; i < 2; i++) {
            int picmipLevel = image->picmip.platform[i];
            int mipW = width >> picmipLevel;
            int mipH = height >> picmipLevel;
            int mipD = depth >> picmipLevel;
            if (mipW < 1) mipW = 1;
            if (mipH < 1) mipH = 1;
            if (mipD < 1) mipD = 1;

            amount = Image_GetCardMemoryAmount(imageFlags, format, mipW, mipH, mipD);
            image->cardMemory.platform[i] = amount;

            if (needsGlobalAccounting)
                imageGlobals[0x200c / 4 + i] += amount;
        }
    } else {
        /* Single-platform path: same dimensions for all platforms */
        for (i = 0; i < 2; i++) {
            amount = Image_GetCardMemoryAmount(imageFlags, format, width, height, depth);
            image->cardMemory.platform[i] = amount;

            if (needsGlobalAccounting)
                imageGlobals[0x200c / 4 + i] += amount;
        }
    }
}

/* line 362 */
void Image_TrackFullscreenTexture(GfxImage *image, int picmip, D3DFORMAT format)
{
    byte *img = (byte *)image;
    signed char mapType = (signed char)image->track;
    int needsGlobalAccounting = ((byte)mapType > 4) || !((1 << mapType) & 0x13);
    int platform;
    int screenWidth, screenHeight;
    int mipW, mipH;
    int amount;

    for (platform = 0; platform <= 1; platform++) {
        if (platform == 0) {
            /* Platform 0: actual screen resolution */
            int *vidConfig = (int *)imp_vidConfig;
            screenWidth = vidConfig[0];
            screenHeight = vidConfig[1];
        } else {
            /* Platform 1: fixed 640x480 */
            screenWidth = 640;
            screenHeight = 480;
        }

        mipW = screenWidth >> (byte)picmip;
        if (mipW < 1) mipW = 1;
        mipH = screenHeight >> (byte)picmip;
        if (mipH < 1) mipH = 1;

        amount = Image_GetCardMemoryAmount(3, format, mipW, mipH, 1);
        image->cardMemory.platform[platform] += amount;

        if (needsGlobalAccounting)
            imageGlobals[0x200c / 4 + platform] += amount;
    }
}

/* line 474 */
extern int R_HashAssetName(const char *name);

GfxImage * Image_AllocProg(int imageProgType, int category)
{
    /* Each GfxImage is 36 bytes; imageProgType * 9 * 4 = imageProgType * 36 */
    GfxImage *image = &g_imageProgs[imageProgType];
    const char *name = g_imageProgNames[imageProgType];
    int hash;

    /* Initialize image fields */
    image->name = name; /* image->name */
    image->category = (byte)category;      /* image->category */
    /* image->semantic = 0 (zero-initialized) */                    /* image->state */
    image->track = 0;                    /* image->mapType */

    /* Find free slot in hash table */
    hash = R_HashAssetName(name) & 0x7ff;
    while (imageGlobals[hash] != 0) {
        hash = (hash + 1) & 0x7ff;
    }
    imageGlobals[hash] = (int)image;

    return image;
}

/* line 516 */
GfxImage * Image_Alloc(const char *name, int category, int semantic, int imageTrack)
{
    int nameLen = strlen(name) + 1; /* including null terminator */
    void *(*hunkAlloc)(int) = ((refimport_t *)imp_ri)->Hunk_AllocInternal;
    byte *image;
    char *nameDst;
    int hash;

    /* Allocate image struct + name string (0x24 bytes for struct + name) */
    image = (byte *)hunkAlloc(0x24 + nameLen);

    /* Name stored right after the struct */
    nameDst = (char *)(image + sizeof(GfxImage));
    ((GfxImage *)image)->name = nameDst;
    memcpy(nameDst, name, nameLen);

    /* Initialize fields */
    ((GfxImage *)image)->category = (byte)category;
    ((GfxImage *)image)->semantic = (byte)semantic;
    ((GfxImage *)image)->track = (byte)imageTrack;

    /* Insert into hash table */
    hash = R_HashAssetName(name) & 0x7ff;
    while (imageGlobals[hash] != 0) {
        hash = (hash + 1) & 0x7ff;
    }
    imageGlobals[hash] = (int)image;

    return (GfxImage *)image;
}

/* line 1318 — Console command: lists all loaded images with format, size, and type stats */
extern int I_stricmp(const char *, const char *);
void R_ImageList_f(void)
{
    typedef int (*PrintFunc)(int, const char *, ...);
    typedef int (*CmdArgcFunc)(void);
    typedef const char *(*CmdArgvFunc)(int);
    typedef HRESULT (__attribute__((stdcall)) *GetDescFunc)(void *, UINT, void *);

    PrintFunc Com_Printf = *(PrintFunc *)((char *)imp_ri);
    CmdArgcFunc Cmd_Argc = (CmdArgcFunc)((refimport_t *)imp_ri)->Cmd_Argc;
    CmdArgvFunc Cmd_Argv = (CmdArgvFunc)((refimport_t *)imp_ri)->Cmd_Argv;

    int imageListBuf[2049]; /* [0]=count, [1..2048]=GfxImage* pointers */
    int imageTrack[20];     /* [imageType*2 + platform] per-type per-platform size */
    int total[2];           /* per-platform total size */
    byte listAllImages;
    int i, j, platform;
    int desc[8];            /* D3D surface/volume desc buffer */

    /* Check for "all" argument */
    if (Cmd_Argc() == 2) {
        const char *arg = Cmd_Argv(1);
        listAllImages = (I_stricmp(arg, "all") == 0) ? 1 : 0;
    } else {
        listAllImages = 0;
    }

    total[0] = 0;
    total[1] = 0;
    memset(imageTrack, 0, 0x50);

    /* Enumerate all image assets */
    imageListBuf[0] = 0;
    DB_EnumXAssets(3, R_AddImageToList, imageListBuf, 1);

    /* If listAllImages, also add procedural image entries from g_imageProgs */
    if (listAllImages) {
        int count;
        for (j = 0; j < 12; j++) {
            count = imageListBuf[0];
            if ((unsigned int)count > 0x7ff)
                break;
            if (g_imageProgs[j].mapType != 0) {
                imageListBuf[1 + count] = (int)&g_imageProgs[j];
                imageListBuf[0] = count + 1;
            }
        }
    }

    {
        int count = imageListBuf[0];
        GfxImage **first = (GfxImage **)&imageListBuf[1];
        GfxImage **last = first + count;

        /* Sort images using std::sort (introsort + insertion sort) */
        if (first != last) {
            int n = count;
            int depth = 0;
            if (n > 1) {
                int tmp = n;
                while (tmp > 1) { depth++; tmp >>= 1; }
                depth *= 2;
            }
            ZSt16__introsort_loopIPP8GfxImageiPFiS1_S1_EEvT_S5_T0_T1_(first, last, depth, imagecompare);
            if ((char *)last - (char *)first > 0x43) {
                GfxImage **threshold = first + 16;
                ZSt16__insertion_sortIPP8GfxImagePFiS1_S1_EEvT_S5_T0_(first, threshold, imagecompare);
                /* Finish rest with unguarded insertion sort */
                for (i = (int)(threshold - first); &first[i] != last; i++) {
                    GfxImage *val = first[i];
                    GfxImage **hole = &first[i];
                    GfxImage **prev = hole - 1;
                    while (imagecompare(val, *prev)) {
                        *hole = *prev;
                        hole = prev;
                        prev--;
                    }
                    *hole = val;
                }
            } else {
                ZSt16__insertion_sortIPP8GfxImagePFiS1_S1_EEvT_S5_T0_(first, last, imagecompare);
            }
        }

        /* Print header */
        Com_Printf(0, "\n-if-- ");
        for (j = 0; j < 2; j++)
            Com_Printf(0, "%s", g_platform_name[j]);
        Com_Printf(0, " ---------\n");

        /* Print each image */
        for (i = 0; i < count; i++) {
            GfxImage *image = first[i];
            int imageKind = image->mapType;
            int format;
            void *d3dRes;

            /* Get D3D format via GetLevelDesc */
            if (imageKind == 4) {
                /* Volume texture */
                d3dRes = image->texture.map;
                (*(GetDescFunc **)d3dRes)[0x44/4](d3dRes, 0, desc);
                format = desc[0];
            } else if (imageKind == 5 || imageKind == 3) {
                /* Cube or regular texture */
                d3dRes = image->texture.map;
                (*(GetDescFunc **)d3dRes)[0x44/4](d3dRes, 0, desc);
                format = desc[0];
            } else {
                /* Unknown type — bail */
                return;
            }

            /* Print format name */
            switch (format) {
                case 0x15: Com_Printf(0, "A1R5"); break; /* D3DFMT_A1R5G5B5 */
                case 0x16: Com_Printf(0, "A4R4"); break; /* D3DFMT_A4R4G4B4 */
                case 0x17: Com_Printf(0, "R3G3"); break; /* D3DFMT_R3G3B2 */
                case 0x1c: Com_Printf(0, "8888"); break; /* D3DFMT_A8R8G8B8 */
                case 0x32: Com_Printf(0, "L___"); break; /* D3DFMT_L8 */
                case 0x33: Com_Printf(0, "AL__"); break; /* D3DFMT_A8L8 */
                case 0x31545844: Com_Printf(0, "DXT1"); break;
                case 0x33545844: Com_Printf(0, "DXT3"); break;
                case 0x35545844: Com_Printf(0, "DXT5"); break;
                case 0x72: Com_Printf(0, "DP__"); break; /* D3DFMT_D32 */
                default: break;
            }

            /* Print image type */
            Com_Printf(0, "  %s", imageTypeName[image->track]);

            if (!listAllImages) {
                /* Print per-platform sizes */
                for (platform = 0; platform < 2; platform++) {
                    int size = image->cardMemory.platform[platform];
                    float sizeKB = (float)size * 0.0009765625f; /* / 1024.0 */
                    if (sizeKB < 10.0f)
                        Com_Printf(0, "%7.1f", (double)sizeKB);
                    else
                        Com_Printf(0, "%7.0f", (double)sizeKB);

                    /* Accumulate per-type stats */
                    {
                        int imgType = image->track;
                        imageTrack[imgType * 2 + platform] += size;
                    }

                    /* Accumulate total for eligible types */
                    {
                        int imgType = image->track;
                        if (imgType <= 4 && ((1 << imgType) & 0x13))
                            ; /* skip total for these types */
                        else
                            total[platform] += size;
                    }
                }
            } else {
                /* listAllImages: print sizes and accumulate totals directly */
                for (platform = 0; platform < 2; platform++) {
                    int size = image->cardMemory.platform[platform];
                    float sizeKB = (float)size * 0.0009765625f;
                    const char *fmt = (sizeKB >= 10.0f) ? "%7.0f" : "%7.1f";
                    Com_Printf(0, fmt, (double)sizeKB);

                    {
                        int imgType = image->track;
                        imageTrack[imgType * 2 + platform] += size;
                    }
                    total[platform] += size;
                }
            }

            /* Print image name */
            Com_Printf(0, "  %s\n", image->name);
        }

        /* Print summary */
        Com_Printf(0, " ---------\n");
        Com_Printf(0, " %i total images\n", count);

        for (platform = 0; platform < 2; platform++) {
            Com_Printf(0, " %5.1f MB %s total image size\n",
                (double)((float)total[platform] * 9.5367431640625e-07f),
                g_platform_name[platform]);
        }
        Com_Printf(0, "\n");
        Com_Printf(0, " ---------\n");
        for (j = 0; j < 2; j++)
            Com_Printf(0, "%s", g_platform_name[j]);
        Com_Printf(0, "\n");

        /* Per-type breakdown */
        for (j = 0; j < 10; j++) {
            Com_Printf(0, "%s:", imageTypeName[j]);
            for (platform = 0; platform < 2; platform++) {
                Com_Printf(0, "  %5.1f",
                    (double)((float)imageTrack[j * 2 + platform] * 9.5367431640625e-07f));
            }
            Com_Printf(0, "\n");
        }
        Com_Printf(0, "\n");
    }
}

#if 0 /* original naked — replaced above */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1318 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20fc, %esp\n"
        /* { scope 1 */
        "movl imp_ri, %ebx\n" /* line 1336 */
        "calll *0x100(%ebx)\n"
        "cmpl $2, %eax\n"
        "je .Lfe7e74_000e84e8\n"
        ".Lfe7e74_000e7e95:\n"
        "movb $0, -0x20c9(%ebp)\n" /* line 1338 | listAllImages */
        ".Lfe7e74_000e7e9c:\n"
        "movl $0, -0x20(%ebp)\n" /* line 1342 | total */
        "movl $0, -0x1c(%ebp)\n"
        "movl $0x50, 8(%esp)\n" /* line 1344 */
        "movl $0, 4(%esp)\n"
        "leal -0xac(%ebp), %eax\n" /* imageTrack */
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $0, -0x20b0(%ebp)\n" /* line 197 | imageList */
        "movl $1, 0xc(%esp)\n" /* line 198 */
        "leal -0x20b0(%ebp), %edx\n" /* imageList */
        "movl %edx, 8(%esp)\n"
        "movl $R_AddImageToList, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll DB_EnumXAssets\n"
        "cmpb $0, -0x20c9(%ebp)\n" /* line 1348 | listAllImages */
        "je .Lfe7e74_000e80f2\n"
        "xorl %ecx, %ecx\n"
        "movl $g_imageProgs, %ebx\n"
        "movl -0x20b0(%ebp), %edx\n" /* imageList */
        ".Lfe7e74_000e7f12:\n"
        "cmpl $0x7ff, %edx\n" /* line 1350 */
        "ja .Lfe7e74_000e7f47\n"
        "movl (%ebx), %eax\n" /* line 1352 */
        "testl %eax, %eax\n"
        "je .Lfe7e74_000e7f3c\n"
        "leal (%ecx, %ecx, 8), %eax\n" /* line 1354 */
        "leal g_imageProgs(, %eax, 4), %eax\n"
        "movl %eax, -0x20ac(%ebp, %edx, 4)\n"
        "leal 1(%edx), %eax\n" /* line 1355 */
        "movl %eax, -0x20b0(%ebp)\n" /* imageList */
        "movl %eax, %edx\n"
        ".Lfe7e74_000e7f3c:\n"
        "addl $1, %ecx\n" /* line 1350 */
        "addl $0x24, %ebx\n"
        "cmpl $0xc, %ecx\n"
        "jne .Lfe7e74_000e7f12\n"
        ".Lfe7e74_000e7f47:\n"
        "leal -0x20ac(%ebp, %edx, 4), %edx\n" /* line 1360 */
        "movl %edx, -0x20c8(%ebp)\n" /* __last */
        /* { scope 2: __last */
        "leal -0x20ac(%ebp), %esi\n" /* line 2604 */
        "cmpl %edx, %esi\n"
        "je .Lfe7e74_000e8053\n"
        "movl %edx, %ebx\n" /* line 2606 */
        "subl %esi, %ebx\n"
        "movl %ebx, %eax\n" /* __n */
        "sarl $2, %eax\n" /* __n */
        /* { scope 3 */
        /* { scope 4: __val, __last */
        "cmpl $1, %eax\n" /* line 2253 */
        "je .Lfe7e74_000e8490\n"
        "xorl %edx, %edx\n"
        ".Lfe7e74_000e7f76:\n"
        "addl $1, %edx\n" /* line 2254 */
        "sarl $1, %eax\n" /* line 2253 */
        "cmpl $1, %eax\n"
        "jne .Lfe7e74_000e7f76\n"
        "leal (%edx, %edx), %eax\n"
        /* } scope */
        /* } scope */
        ".Lfe7e74_000e7f83:\n"
        "movl $imagecompare, 0xc(%esp)\n" /* line 2606 */
        "movl %eax, 8(%esp)\n" /* __n */
        "movl -0x20c8(%ebp), %ecx\n" /* __last */
        "movl %ecx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll ZSt16__introsort_loopIPP8GfxImageiPFiS1_S1_EEvT_S5_T0_T1_\n"
        "cmpl $0x43, %ebx\n" /* line 2233 */
        "jle .Lfe7e74_000e8039\n"
        "movl $imagecompare, 8(%esp)\n" /* line 2235 */
        "leal -0x206c(%ebp), %ebx\n"
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll ZSt16__insertion_sortIPP8GfxImagePFiS1_S1_EEvT_S5_T0_\n"
        /* { scope 3 */
        /* { scope 4: __val, __last */
        "cmpl %ebx, -0x20c8(%ebp)\n" /* line 2200 | __last */
        "je .Lfe7e74_000e8053\n"
        "movl %ebx, -0x20c0(%ebp)\n" /* __last */
        "movl %ebx, %eax\n"
        "movl %ebx, %edi\n"
        ".Lfe7e74_000e7fda:\n"
        "movl (%eax), %eax\n" /* line 2201 */
        "movl %eax, -0x20c4(%ebp)\n" /* __val */
        "movl -0x20c0(%ebp), %ebx\n" /* __last */
        "subl $4, %ebx\n"
        "movl %eax, %edx\n"
        "jmp .Lfe7e74_000e7ffc\n"
        /* { scope 5 */
        ".Lfe7e74_000e7fef:\n"
        "movl %esi, (%edi)\n" /* line 2110 */
        "movl %ebx, %edi\n" /* line 2112 */
        "subl $4, %ebx\n"
        "movl -0x20c4(%ebp), %edx\n" /* __val */
        ".Lfe7e74_000e7ffc:\n"
        "movl (%ebx), %esi\n" /* line 2108 */
        "movl %esi, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll imagecompare\n"
        "testl %eax, %eax\n"
        "jne .Lfe7e74_000e7fef\n"
        "movl -0x20c4(%ebp), %ecx\n" /* line 2114 | __val */
        "movl %ecx, (%edi)\n"
        /* } scope */
        "addl $4, -0x20c0(%ebp)\n" /* line 2200 | __last */
        "movl -0x20c0(%ebp), %eax\n" /* __last */
        "cmpl %eax, -0x20c8(%ebp)\n" /* __last */
        "je .Lfe7e74_000e8053\n"
        "movl -0x20c0(%ebp), %eax\n" /* __last */
        "movl -0x20c0(%ebp), %edi\n" /* __last */
        "jmp .Lfe7e74_000e7fda\n"
        /* } scope */
        /* } scope */
        ".Lfe7e74_000e8039:\n"
        "movl $imagecompare, 8(%esp)\n" /* line 2240 */
        "movl -0x20c8(%ebp), %edx\n" /* __last */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll ZSt16__insertion_sortIPP8GfxImagePFiS1_S1_EEvT_S5_T0_\n"
        /* } scope */
        ".Lfe7e74_000e8053:\n"
        "movl imp_ri, %ebx\n" /* line 1362 */
        "movl $str_00225410, 4(%esp)\n" /* "
-if-- " */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        "movl $g_platform_name, %esi\n"
        "movl $g_platform_name+8, %edi\n"
        ".Lfe7e74_000e8074:\n"
        "movl (%esi), %eax\n" /* line 1365 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00216058, 4(%esp)\n" /* "%s" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        "addl $4, %esi\n"
        "cmpl %esi, %edi\n" /* line 1364 */
        "jne .Lfe7e74_000e8074\n"
        "movl $str_00225418, 4(%esp)\n" /* line 1367 */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        "movl -0x20b0(%ebp), %eax\n" /* line 1369 | imageList */
        "testl %eax, %eax\n"
        "jle .Lfe7e74_000e8277\n"
        "movl $0, -0x20d8(%ebp)\n" /* i */
        "movl -0x20d8(%ebp), %ecx\n" /* i */
        ".Lfe7e74_000e80c1:\n"
        "movl -0x20ac(%ebp, %ecx, 4), %ecx\n" /* line 1371 */
        "movl %ecx, -0x20d4(%ebp)\n" /* image */
        "movl (%ecx), %eax\n" /* line 1373 */
        "cmpl $4, %eax\n"
        "je .Lfe7e74_000e80fd\n"
        "cmpl $5, %eax\n"
        "je .Lfe7e74_000e8450\n"
        "cmpl $3, %eax\n"
        "je .Lfe7e74_000e848b\n"
        /* } scope */
        "addl $0x20fc, %esp\n" /* line 1500 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfe7e74_000e80f2:\n"
        "movl -0x20b0(%ebp), %edx\n" /* imageList */
        "jmp .Lfe7e74_000e7f47\n"
        /* { scope 1 */
        ".Lfe7e74_000e80fd:\n"
        "movl 4(%ecx), %eax\n" /* line 1389 */
        "movl (%eax), %ecx\n"
        "leal -0x3c(%ebp), %edx\n" /* volumeDesc */
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x44(%ecx)\n"
        "movl -0x3c(%ebp), %eax\n" /* line 1390 | volumeDesc */
        ".Lfe7e74_000e811a:\n"
        "cmpl $0x32, %eax\n" /* line 1398 */
        "je .Lfe7e74_000e815a\n"
        "jg .Lfe7e74_000e8412\n"
        "cmpl $0x16, %eax\n"
        "je .Lfe7e74_000e8534\n"
        "jle .Lfe7e74_000e84c4\n"
        "cmpl $0x17, %eax\n"
        "je .Lfe7e74_000e856a\n"
        "cmpl $0x1c, %eax\n"
        "jne .Lfe7e74_000e8170\n"
        "movl $str_00225444, 4(%esp)\n" /* line 1413 */
        "movl $0, (%esp)\n"
        "movl imp_ri, %eax\n"
        "calll *(%eax)\n"
        "jmp .Lfe7e74_000e8170\n"
        ".Lfe7e74_000e815a:\n"
        "movl $str_0022544c, 4(%esp)\n" /* line 1417 */
        "movl $0, (%esp)\n"
        "movl imp_ri, %eax\n"
        "calll *(%eax)\n"
        ".Lfe7e74_000e8170:\n"
        "movl imp_ri, %ebx\n" /* line 1452 */
        "movl -0x20d4(%ebp), %edx\n" /* image */
        "movzbl 0xc(%edx), %eax\n"
        "movl imageTypeName(, %eax, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0022547c, 4(%esp)\n" /* "  %s" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        "cmpb $0, -0x20c9(%ebp)\n" /* listAllImages */
        "jne .Lfe7e74_000e85a0\n"
        "movl -0x20d4(%ebp), %ebx\n" /* line 1499 | image */
        "xorl %esi, %esi\n"
        ".Lfe7e74_000e81b1:\n"
        "leal 0x10(%ebx), %edi\n" /* line 1318 */
        "cvtsi2ssl 0x10(%ebx), %xmm0\n" /* line 1457 */
        "mulss lit4_002ed60c, %xmm0\n" /* 0.0009765625f */
        "movl imp_ri, %eax\n" /* line 1458 */
        "movl (%eax), %eax\n"
        "cvtss2sd %xmm0, %xmm1\n"
        "ucomiss lit4_002ed6b4, %xmm0\n" /* 10.0f */
        "jp .Lfe7e74_000e81db\n"
        "jb .Lfe7e74_000e8478\n"
        ".Lfe7e74_000e81db:\n"
        "movl $str_0022548c, %edx\n" /* line 1467 */
        ".Lfe7e74_000e81e0:\n"
        "movsd %xmm1, 8(%esp)\n" /* line 1458 */
        "movl %edx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll *%eax\n"
        "movl (%edi), %edx\n" /* line 1459 */
        "movl -0x20d4(%ebp), %ecx\n" /* line 1462 | image */
        "movzbl 0xc(%ecx), %eax\n"
        "leal (%esi, %eax, 2), %eax\n"
        "addl %edx, -0xac(%ebp, %eax, 4)\n"
        "cmpb $4, 0xc(%ecx)\n" /* line 170 */
        "ja .Lfe7e74_000e8482\n"
        "movl -0x20d4(%ebp), %eax\n" /* image */
        "movsbl 0xc(%eax), %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "testb $0x13, %al\n"
        "je .Lfe7e74_000e8482\n"
        ".Lfe7e74_000e822c:\n"
        "addl $1, %esi\n" /* line 1455 */
        "addl $4, %ebx\n"
        "cmpl $2, %esi\n"
        "jne .Lfe7e74_000e81b1\n"
        ".Lfe7e74_000e823b:\n"
        "movl -0x20d4(%ebp), %edx\n" /* line 1470 | image */
        "movl 0x20(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002182fc, 4(%esp)\n" /* "  %s
" */
        "movl $0, (%esp)\n"
        "movl imp_ri, %eax\n"
        "calll *(%eax)\n"
        "addl $1, -0x20d8(%ebp)\n" /* line 1369 | i */
        "movl -0x20d8(%ebp), %ecx\n" /* i */
        "cmpl -0x20b0(%ebp), %ecx\n" /* imageList */
        "jl .Lfe7e74_000e80c1\n"
        ".Lfe7e74_000e8277:\n"
        "movl imp_ri, %ebx\n" /* line 1472 */
        "movl $str_00225494, 4(%esp)\n" /* " ---------
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        "movl -0x20b0(%ebp), %eax\n" /* line 1473 | imageList */
        "movl %eax, 8(%esp)\n"
        "movl $str_002254a0, 4(%esp)\n" /* " %i total images
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        "xorl %esi, %esi\n"
        "leal -0x20(%ebp), %edi\n" /* total */
        ".Lfe7e74_000e82ae:\n"
        "movl g_platform_name(%esi), %eax\n" /* line 1476 */
        "movl %eax, 0x10(%esp)\n"
        "cvtsi2ssl (%esi, %edi), %xmm0\n"
        "mulss lit4_002ed820, %xmm0\n" /* 9.5367431640625e-07f */
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $str_002254b4, 4(%esp)\n" /* " %5.1f MB %s total image size
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        "addl $4, %esi\n"
        "cmpl $8, %esi\n" /* line 1475 */
        "jne .Lfe7e74_000e82ae\n"
        "movl $str_002160e8, 4(%esp)\n" /* line 1479 */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        "movl $str_002254d4, 4(%esp)\n" /* line 1481 */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        "movl $g_platform_name, %ebx\n"
        "movl imp_ri, %esi\n"
        ".Lfe7e74_000e8315:\n"
        "movl (%ebx), %eax\n" /* line 1484 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00216058, 4(%esp)\n" /* "%s" */
        "movl $0, (%esp)\n"
        "calll *(%esi)\n"
        "addl $4, %ebx\n"
        "cmpl $g_platform_name+8, %ebx\n" /* line 1483 */
        "jne .Lfe7e74_000e8315\n"
        "movl $str_002160e8, 4(%esp)\n" /* line 1486 */
        "movl $0, (%esp)\n"
        "calll *(%esi)\n"
        "xorl %edi, %edi\n"
        "movl $imageTypeName, -0x20bc(%ebp)\n"
        "movl imp_ri, %eax\n"
        "movl %eax, -0x20dc(%ebp)\n"
        "movl %eax, %ecx\n"
        "jmp .Lfe7e74_000e8369\n"
        ".Lfe7e74_000e8363:\n"
        "movl -0x20dc(%ebp), %ecx\n"
        ".Lfe7e74_000e8369:\n"
        "movl -0x20bc(%ebp), %edx\n" /* line 1490 */
        "movl (%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002254dc, 4(%esp)\n" /* "%s:" */
        "movl $0, (%esp)\n"
        "calll *(%ecx)\n"
        "leal -0xac(%ebp, %edi, 8), %ebx\n"
        "movl $2, %esi\n"
        ".Lfe7e74_000e8392:\n"
        "cvtsi2ssl (%ebx), %xmm0\n" /* line 1493 */
        "mulss lit4_002ed820, %xmm0\n" /* 9.5367431640625e-07f */
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $str_002254e0, 4(%esp)\n" /* "  %5.1f" */
        "movl $0, (%esp)\n"
        "movl imp_ri, %eax\n"
        "calll *(%eax)\n"
        "addl $4, %ebx\n"
        "subl $1, %esi\n" /* line 1492 */
        "jne .Lfe7e74_000e8392\n"
        "movl $str_002254e8, 4(%esp)\n" /* line 1495 */
        "movl $0, (%esp)\n"
        "movl imp_ri, %edx\n"
        "calll *(%edx)\n"
        "addl $1, %edi\n" /* line 1488 */
        "addl $4, -0x20bc(%ebp)\n"
        "cmpl $0xa, %edi\n"
        "jne .Lfe7e74_000e8363\n"
        "movl $str_002254f0, 4(%esp)\n" /* line 1499 */
        "movl $0, (%esp)\n"
        "movl imp_ri, %ecx\n"
        "calll *(%ecx)\n"
        /* } scope */
        "addl $0x20fc, %esp\n" /* line 1500 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe7e74_000e8412:\n"
        "cmpl $0x31545844, %eax\n" /* line 1398 */
        "je .Lfe7e74_000e8519\n"
        "jle .Lfe7e74_000e8497\n"
        "cmpl $0x33545844, %eax\n"
        "je .Lfe7e74_000e854f\n"
        "cmpl $0x35545844, %eax\n"
        "jne .Lfe7e74_000e8170\n"
        "movl $str_00225464, 4(%esp)\n" /* line 1429 */
        "movl $0, (%esp)\n"
        "movl imp_ri, %eax\n"
        "calll *(%eax)\n"
        "jmp .Lfe7e74_000e8170\n"
        ".Lfe7e74_000e8450:\n"
        "movl -0x20d4(%ebp), %edx\n" /* line 1383 | image */
        "movl 4(%edx), %eax\n"
        ".Lfe7e74_000e8459:\n"
        "movl (%eax), %ecx\n"
        "leal -0x5c(%ebp), %edx\n" /* surfaceDesc */
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x44(%ecx)\n"
        "movl -0x5c(%ebp), %eax\n" /* line 1384 | surfaceDesc */
        "jmp .Lfe7e74_000e811a\n"
        ".Lfe7e74_000e8478:\n"
        "movl $str_00225484, %edx\n" /* line 170 */
        "jmp .Lfe7e74_000e81e0\n"
        ".Lfe7e74_000e8482:\n"
        "addl %edx, -0x20(%ebp, %esi, 4)\n" /* line 1467 */
        "jmp .Lfe7e74_000e822c\n"
        ".Lfe7e74_000e848b:\n"
        "movl 4(%ecx), %eax\n" /* line 1377 */
        "jmp .Lfe7e74_000e8459\n"
        /* { scope 2: __last */
        /* { scope 3 */
        ".Lfe7e74_000e8490:\n"
        "xorb %al, %al\n" /* line 2253 */
        "jmp .Lfe7e74_000e7f83\n"
        /* } scope */
        /* } scope */
        ".Lfe7e74_000e8497:\n"
        "cmpl $0x33, %eax\n" /* line 1398 */
        "je .Lfe7e74_000e8585\n"
        "cmpl $0x72, %eax\n"
        "jne .Lfe7e74_000e8170\n"
        "movl $str_00225474, 4(%esp)\n" /* line 1443 */
        "movl $0, (%esp)\n"
        "movl imp_ri, %eax\n"
        "calll *(%eax)\n"
        "jmp .Lfe7e74_000e8170\n"
        ".Lfe7e74_000e84c4:\n"
        "cmpl $0x15, %eax\n" /* line 1398 */
        "jne .Lfe7e74_000e8170\n"
        "movl $str_00225434, 4(%esp)\n" /* line 1405 */
        "movl $0, (%esp)\n"
        "movl imp_ri, %eax\n"
        "calll *(%eax)\n"
        "jmp .Lfe7e74_000e8170\n"
        ".Lfe7e74_000e84e8:\n"
        "movl $1, (%esp)\n" /* line 1338 */
        "calll *0x104(%ebx)\n"
        "movl $str_0022540c, 4(%esp)\n" /* "all" */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lfe7e74_000e7e95\n"
        "movb $1, -0x20c9(%ebp)\n" /* listAllImages */
        "jmp .Lfe7e74_000e7e9c\n"
        ".Lfe7e74_000e8519:\n"
        "movl $str_00225454, 4(%esp)\n" /* line 1421 */
        "movl $0, (%esp)\n"
        "movl imp_ri, %eax\n"
        "calll *(%eax)\n"
        "jmp .Lfe7e74_000e8170\n"
        ".Lfe7e74_000e8534:\n"
        "movl $str_0022542c, 4(%esp)\n" /* line 1401 */
        "movl $0, (%esp)\n"
        "movl imp_ri, %eax\n"
        "calll *(%eax)\n"
        "jmp .Lfe7e74_000e8170\n"
        ".Lfe7e74_000e854f:\n"
        "movl $str_0022545c, 4(%esp)\n" /* line 1425 */
        "movl $0, (%esp)\n"
        "movl imp_ri, %eax\n"
        "calll *(%eax)\n"
        "jmp .Lfe7e74_000e8170\n"
        ".Lfe7e74_000e856a:\n"
        "movl $str_0022546c, 4(%esp)\n" /* line 1439 */
        "movl $0, (%esp)\n"
        "movl imp_ri, %eax\n"
        "calll *(%eax)\n"
        "jmp .Lfe7e74_000e8170\n"
        ".Lfe7e74_000e8585:\n"
        "movl $str_0022543c, 4(%esp)\n" /* line 1409 */
        "movl $0, (%esp)\n"
        "movl imp_ri, %eax\n"
        "calll *(%eax)\n"
        "jmp .Lfe7e74_000e8170\n"
        ".Lfe7e74_000e85a0:\n"
        "movl -0x20d4(%ebp), %esi\n" /* line 1452 | image */
        "movl $0, -0x20d0(%ebp)\n" /* platform */
        "leal -0x20(%ebp), %edi\n" /* total */
        ".Lfe7e74_000e85b3:\n"
        "cvtsi2ssl 0x10(%esi), %xmm1\n" /* line 1457 */
        "mulss lit4_002ed60c, %xmm1\n" /* 0.0009765625f */
        "movl (%ebx), %ecx\n" /* line 1458 */
        "movl $str_00225484, %edx\n" /* "%7.1f" */
        "movss lit4_002ed6b4, %xmm0\n" /* 10.0f */
        "ucomiss %xmm1, %xmm0\n"
        "movl $str_0022548c, %eax\n" /* "%7.0f" */
        "cmovbel %eax, %edx\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "movsd %xmm1, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll *%ecx\n"
        "movl 0x10(%esi), %edx\n" /* line 1459 */
        "movl -0x20d4(%ebp), %ecx\n" /* line 1462 | image */
        "movzbl 0xc(%ecx), %eax\n"
        "movl -0x20d0(%ebp), %ecx\n" /* platform */
        "leal (%ecx, %eax, 2), %eax\n"
        "addl %edx, -0xac(%ebp, %eax, 4)\n"
        "addl %edx, (%edi)\n" /* line 1467 */
        "addl $1, %ecx\n" /* line 1455 */
        "movl %ecx, -0x20d0(%ebp)\n" /* platform */
        "addl $4, %edi\n"
        "addl $4, %esi\n"
        "cmpl $2, %ecx\n"
        "jne .Lfe7e74_000e85b3\n"
        "jmp .Lfe7e74_000e823b\n"
    );
}
#endif /* original naked R_ImageList_f */

/* line 881 */
extern GfxImage * Image_Load(const char *name, int semantic, int imageTrack);

GfxImage * Image_Register(const char *imageName, int semantic, int imageTrack)
{
    int hash;
    GfxImage *image;
    int isProg;

    /* Look up in hash table */
    hash = R_HashAssetName(imageName) & 0x7ff;
    image = (GfxImage *)imageGlobals[hash];

    while (image) {
        if (strcmp(image->name, imageName) == 0)
            break;
        hash = (hash + 1) & 0x7ff;
        image = (GfxImage *)imageGlobals[hash];
    }

    /* Check if found image is a prog image (internal) */
    isProg = ((char *)image >= (char *)g_imageProgs &&
              (char *)image < (char *)g_imageProgs + 432);

    /* Return found image if it's a prog image, or if not found but non-null */
    if (!isProg && image)
        return image;

    /* Load the image from disk */
    image = Image_Load(imageName, (byte)semantic, imageTrack);
    if (!image) {
        R_Error(1, "failed to load image '%s'", imageName);
    }

    return image;
}

/* line 1272 */
extern void RB_InitImages(void);

void R_InitImages(void)
{
    byte *rgp = (byte *)imp_rgp;
    int rendererType;
    int hash;
    GfxImage *rawImage;

    R_SetPicmip();

    /* Register built-in images */
    ((r_global_permanent_t *)rgp)->whiteImage = Image_Register("$white", 1, 0);
    rgp = (byte *)imp_rgp;
    ((r_global_permanent_t *)rgp)->blackImage = Image_Register("$black", 1, 0);

    rendererType = (*(const dvar_t **)imp_r_rendererInUse)->current.integer;
    if (rendererType == 2) {
        /* Dx7 path */
        ((r_global_permanent_t *)rgp)->waterColorImage = Image_Register("$watercolor", 1, 0);
    } else {
        /* Non-Dx7 path */
        ((r_global_permanent_t *)rgp)->identityNormalMapImage = Image_Register("$identitynormalmap", 1, 0);
        ((r_global_permanent_t *)rgp)->specularityImage = Image_Register("$specularity", 1, 0);
        ((r_global_permanent_t *)rgp)->lightGridWeightsImage[0] = Image_Register("$lightgridweights0", 1, 0);
        ((r_global_permanent_t *)rgp)->lightGridWeightsImage[1] = Image_Register("$lightgridweights1", 1, 0);
        ((r_global_permanent_t *)rgp)->lightmapWeightsImage = Image_Register("$lightmapweights", 1, 0);
    }

    RB_InitImages();

    /* Initialize raw image prog (index 11 = offset 396 in g_imageProgs) */
    rawImage = &g_imageProgs[11];
    rawImage->name = g_imageProgNames[11];
    rawImage->category = 4;  /* category */
    /* rawImage->semantic = 0 (zero-initialized) */
    rawImage->track = 0;  /* track */

    /* Insert into hash table */
    hash = R_HashAssetName(g_imageProgNames[11]) & 0x7ff;
    while (imageGlobals[hash] != 0)
        hash = (hash + 1) & 0x7ff;
    imageGlobals[hash] = (int)rawImage;

    /* Set up rgp raw image references */
    rgp = (byte *)imp_rgp;
    ((r_global_permanent_t *)rgp)->rawImage = rawImage;
    ((r_global_permanent_t *)rgp)->rawTexdef.samplerState = 0x32;
    ((r_global_permanent_t *)rgp)->rawTexdef.semantic = 0;
    ((r_global_permanent_t *)rgp)->rawTexdef.u.image = rawImage;
}

/* line 715 */
void Image_SetupRenderTarget(GfxImage *image, int width, int height, D3DFORMAT imageFormat)
{
    unsigned short w = (unsigned short)width;
    unsigned short h = (unsigned short)height;
    void *device;
    void **vtable;
    HRESULT hr;

    image->width = w;
    image->height = h;
    image->depth = 1;
    image->mapType = 3;

    /* CreateTexture: Levels=1, Usage=D3DUSAGE_RENDERTARGET(1), Pool=D3DPOOL_DEFAULT(0) */
    device = ((DxGlobals *)imp_dx)->device;
    if (!device) { image->texture.map = NULL; return 0; }
    vtable = *(void ***)device;
    hr = ((HRESULT (*)(void *, UINT, UINT, UINT, DWORD, DWORD, DWORD, void **, void *))(vtable[0x5C / 4]))(
        device, w, h, 1, 1, imageFormat, 0, (void **)&image->texture.map, NULL);

    if (hr < 0) {
        R_Error(1, "Create2DTexture( %s, %i, %i, %i, %i ) failed: %08x = %s",
            image->name, (int)w, (int)h, 0, (int)imageFormat,
            (int)hr, R_ErrorDescription(hr));
    }

    Image_TrackTexture(image, 3, imageFormat, w, h, 1);
}

/* line 733 */
void Image_SetupSystem(GfxImage *image, int width, int height, D3DFORMAT imageFormat)
{
    unsigned short w = (unsigned short)width;
    unsigned short h = (unsigned short)height;
    void *device;
    void **vtable;
    HRESULT hr;

    image->width = w;
    image->height = h;
    image->depth = 1;
    image->mapType = 3;

    /* CreateTexture: Levels=1, Usage=D3DUSAGE_DYNAMIC(0x200), Pool=D3DPOOL_SYSTEMMEM(2) */
    device = ((DxGlobals *)imp_dx)->device;
    if (!device) { image->texture.map = NULL; return 0; }
    vtable = *(void ***)device;
    hr = ((HRESULT (*)(void *, UINT, UINT, UINT, DWORD, DWORD, DWORD, void **, void *))(vtable[0x5C / 4]))(
        device, w, h, 1, 0x200, imageFormat, 2, (void **)&image->texture.map, NULL);

    if (hr < 0) {
        R_Error(1, "Create2DTexture( %s, %i, %i, %i, %i ) failed: %08x = %s",
            image->name, (int)w, (int)h, 0, (int)imageFormat,
            (int)hr, R_ErrorDescription(hr));
    }

    Image_TrackTexture(image, 3, imageFormat, w, h, 1);
}

/* line 976 */
extern void RB_UnbindImage(const GfxImage *image);
extern void Image_BuildSpecularityMap(float shift, byte *pic);
extern void Image_UploadData(GfxImage *image, D3DFORMAT format, int face, int mipLevel, const byte *src);

void Image_RebuildCosinePowerMap(float shift)
{
    byte *rgp;
    GfxImage *image;
    void *texture;
    void **vtable;
    byte pic[0x2000]; /* 32*256*1 pixel buffer */

    /* Dx7 renderer has no specularity map */
    if ((*(const dvar_t **)imp_r_rendererInUse)->current.integer == 2)
        return;

    rgp = (byte *)imp_rgp;
    image = ((r_global_permanent_t *)rgp)->specularityImage;
    RB_UnbindImage(image);

    /* Release existing texture */
    do {
        texture = image->texture.map;
        vtable = *(void ***)texture;
        ((ULONG (*)(void *))(vtable[8 / 4]))(texture);
        image->texture.map = NULL;
    } while (*(volatile int *)imp_alwaysfails);

    /* Recreate as 32x256 D3DFMT_L8(0x32) texture */
    image = ((r_global_permanent_t *)rgp)->specularityImage;
    Image_Create2DTexture(image, 32, 256, 1, 0, 0x32, 1);

    /* Build and upload specularity data */
    Image_BuildSpecularityMap(shift, pic);
    Image_UploadData(((r_global_permanent_t *)rgp)->specularityImage, 0x32, 0, 0, pic);
}

/* line 599 */
extern void RB_UnbindAllImages(void);

void R_ShutdownImages(void)
{
    GfxImage *savedImages[2048];
    int savedImageCount = 0;
    int i;
    int hash;

    RB_UnbindAllImages();

    /* Pass 1: release all images, saving prog images for re-insertion */
    for (i = 0; i < 2048; i++) {
        GfxImage *image = (GfxImage *)imageGlobals[i];
        int isProg;

        if (!image)
            continue;

        /* Check if this is a g_imageProgs image */
        isProg = ((char *)image >= (char *)g_imageProgs &&
                  (char *)image < (char *)g_imageProgs + 432);

        if (isProg) {
            /* Save prog images — don't release them */
            savedImages[savedImageCount++] = image;
            continue;
        }

        /* Release non-prog image (inlined Image_Release with vtable NULL check) */
        {
            signed char mapType = (signed char)image->track;
            if ((byte)mapType > 4 || !((1 << mapType) & 0x13)) {
                int j;
                for (j = 0; j < 2; j++)
                    imageGlobals[0x200c / 4 + j] -= image->cardMemory.platform[j];
            }

            {
                void *texture = image->texture.map;
                if (texture) {
                    void **vtable = *(void ***)texture;
                    if (vtable && vtable[8 / 4]) {
                        ((ULONG (*)(void *))(vtable[8 / 4]))(texture);
                        image->texture.map = NULL;
                        image->cardMemory.platform[0] = 0;
                        image->cardMemory.platform[1] = 0;
                    }
                }
            }
            image->mapType = 0;
        }
    }

    /* Clear hash table */
    memset(imageGlobals, 0, 0x2000);

    /* Re-insert saved prog images into the cleared hash table */
    for (i = 0; i < savedImageCount; i++) {
        GfxImage *image = savedImages[i];
        const char *name = image->name;

        hash = R_HashAssetName(name) & 0x7ff;
        while (imageGlobals[hash] != 0)
            hash = (hash + 1) & 0x7ff;
        imageGlobals[hash] = (int)image;
    }
}

/* line 915 */
void R_ReleaseLostImages(void)
{
    int i;

    for (i = 0; i < 2048; i++) {
        GfxImage *image = (GfxImage *)imageGlobals[i];

        if (!image)
            continue;

        /* Only release images with category > 4 */
        if (image->category <= 4)
            continue;

        Image_Release(image);
    }
}

/* line 1019 */
extern void Image_GetPicmip(const GfxImage *image, Picmip *picmip);

void Image_UpdatePicmip(GfxImage *image)
{
    Picmip picmip;

    Image_GetPicmip(image, &picmip);

    /* If picmip level hasn't changed, nothing to do */
    if (image->picmip.platform[0] == picmip.platform[0])
        return;

    /* Release current texture and reload with new picmip */
    Image_Release(image);

    /* Set new picmip value (copy 2 bytes) */
    image->picmip = picmip;

    if (!Image_LoadFromFile(image)) {
        R_Error(1, "failed to load image '%s'",
            image->name);
    }
}

/* line 1037 */

void Image_Reload(GfxImage *image)
{
    Image_Release(image);

    if (!Image_LoadFromFile(image)) {
        R_Error(1, "failed to load image '%s'",
            image->name);
    }
}

/* line 273 */
/* std::__adjust_heap for GfxImage** — heap sift-down + push-up (for make_heap/sort_heap) */
void ZSt13__adjust_heapIPP8GfxImageiS1_PFiS1_S1_EEvT_T0_S6_T1_T2_(
    GfxImage **first, int holeIndex, int len, GfxImage *value, GfxImageCompFunc comp)
{
    int topIndex = holeIndex;
    int secondChild = 2 * holeIndex + 2;

    /* Sift down: move the larger child up until we reach a leaf */
    while (secondChild < len) {
        if (comp(first[secondChild], first[secondChild - 1]))
            secondChild--;
        first[holeIndex] = first[secondChild];
        holeIndex = secondChild;
        secondChild = 2 * secondChild + 2;
    }

    /* Handle odd-length case: only left child exists */
    if (secondChild == len) {
        first[holeIndex] = first[len - 1];
        holeIndex = len - 1;
    }

    /* Push up: sift value up from holeIndex */
    while (holeIndex > topIndex) {
        int parent = (holeIndex - 1) / 2;
        if (!comp(first[parent], value))
            break;
        first[holeIndex] = first[parent];
        holeIndex = parent;
    }
    first[holeIndex] = value;
}

/* line 2152 */
/* std::__insertion_sort for GfxImage** — insertion sort with comparator */
void ZSt16__insertion_sortIPP8GfxImagePFiS1_S1_EEvT_S5_T0_(
    GfxImage **first, GfxImage **last, GfxImageCompFunc comp)
{
    GfxImage **i;
    if (first == last) return;
    for (i = first + 1; i != last; i++) {
        GfxImage *val = *i;
        if (comp(val, *first)) {
            /* val belongs before first — shift entire prefix right via memmove */
            unsigned int n = (unsigned int)((char *)i - (char *)first) & ~3u;
            memmove(first + 1, first, n);
            *first = val;
        } else {
            /* Shift elements right until insertion point found */
            GfxImage **prev = i - 1;
            GfxImage **hole = i;
            while (comp(val, *prev)) {
                *hole = *prev;
                hole = prev;
                prev--;
            }
            *hole = val;
        }
    }
}

/* line 2514 */
/* std::__introsort_loop for GfxImage** — introsort with heapsort fallback.
 * Partitions ranges > 16 elements using median-of-3 pivot, recurses on right
 * half, loops on left. Falls back to heapsort when depth_limit exhausted. */
void ZSt16__introsort_loopIPP8GfxImageiPFiS1_S1_EEvT_S5_T0_T1_(
    GfxImage **first, GfxImage **last, int depth_limit, GfxImageCompFunc comp)
{
    while ((char *)last - (char *)first > 64) { /* > 16 elements */
        if (depth_limit == 0) {
            /* Heapsort fallback: make_heap then sort_heap */
            int n = (int)(last - first);
            int half = (n - 2) / 2;
            int i;
            GfxImage **end;

            /* make_heap */
            for (i = half; i >= 0; i--)
                ZSt13__adjust_heapIPP8GfxImageiS1_PFiS1_S1_EEvT_T0_S6_T1_T2_(
                    first, i, n, first[i], comp);

            /* sort_heap */
            for (end = last - 1; end - first > 0; end--) {
                GfxImage *value = *end;
                *end = *first;
                ZSt13__adjust_heapIPP8GfxImageiS1_PFiS1_S1_EEvT_T0_S6_T1_T2_(
                    first, 0, (int)(end - first), value, comp);
            }
            return;
        }

        depth_limit--;

        /* Median-of-3 pivot selection */
        {
            int n = (int)(last - first);
            int mid = n / 2;
            GfxImage **midPtr = first + mid;
            GfxImage **pivotPtr;
            GfxImage *pivot;
            GfxImage **lo, **hi;

            /* Find median of first, mid, last-1 */
            if (comp(*first, *midPtr)) {
                if (comp(*midPtr, *(last - 1))) {
                    pivotPtr = midPtr;
                } else if (comp(*first, *(last - 1))) {
                    pivotPtr = last - 1;
                } else {
                    pivotPtr = first;
                }
            } else {
                if (comp(*first, *(last - 1))) {
                    pivotPtr = first;
                } else if (comp(*(last - 1), *midPtr)) {
                    pivotPtr = midPtr;
                } else {
                    pivotPtr = last - 1;
                }
            }

            pivot = *pivotPtr;
            lo = first;
            hi = last;

            /* Partition */
            for (;;) {
                while (!comp(pivot, *lo))
                    lo++;
                hi--;
                while (!comp(*hi, pivot))
                    hi--;
                if (lo >= hi)
                    break;
                /* Swap */
                {
                    GfxImage *tmp = *lo;
                    *lo = *hi;
                    *hi = tmp;
                }
                lo++;
            }

            /* Recurse on right partition, loop on left */
            ZSt16__introsort_loopIPP8GfxImageiPFiS1_S1_EEvT_S5_T0_T1_(
                lo, last, depth_limit, comp);
            last = lo;
        }
    }
}

#if 0 /* original naked — replaced above */
{
    __asm__ __volatile__ (
        ".Lf2bfe18_002bfe18:\n"
        "pushl %ebp\n" /* line 2514 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 2519 | __last */
        "subl 8(%ebp), %eax\n" /* __first */
        "cmpl $0x43, %eax\n"
        "jle .Lf2bfe18_002bfeec\n"
        /* { scope 2 */
        "movl 0x10(%ebp), %edi\n" /* line 2521 | __depth_limit */
        "testl %edi, %edi\n"
        "jne .Lf2bfe18_002bfef4\n"
        /* { scope 3 */
        /* { scope 4 */
        ".Lf2bfe18_002bfe3b:\n"
        "cmpl $7, %eax\n" /* line 397 */
        "jle .Lf2bfe18_002bfeec\n"
        "sarl $2, %eax\n" /* line 400 */
        "movl %eax, -0x24(%ebp)\n"
        "movl %eax, %edx\n" /* line 2514 */
        "subl $2, %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "leal (%eax, %edx), %esi\n"
        "sarl $1, %esi\n"
        "movl 8(%ebp), %edi\n" /* __first */
        "leal (%edi, %esi, 4), %ebx\n"
        "xorl %edi, %edi\n"
        "jmp .Lf2bfe18_002bfe66\n"
        ".Lf2bfe18_002bfe63:\n"
        "addl $1, %edi\n" /* line 406 */
        ".Lf2bfe18_002bfe66:\n"
        "movl 0x14(%ebp), %eax\n" /* line 404 | __comp */
        "movl %eax, 0x10(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x24(%ebp), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl %esi, %eax\n"
        "subl %edi, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* __first */
        "movl %eax, (%esp)\n"
        "calll ZSt13__adjust_heapIPP8GfxImageiS1_PFiS1_S1_EEvT_T0_S6_T1_T2_\n"
        "subl $4, %ebx\n"
        "cmpl %esi, %edi\n" /* line 406 */
        "jne .Lf2bfe18_002bfe63\n"
        /* } scope */
        /* } scope */
        "movl 0xc(%ebp), %ecx\n" /* line 2521 | __last */
        "movl %ecx, %edi\n" /* line 2514 */
        "subl 8(%ebp), %edi\n" /* __first */
        "movl %edi, -0x2c(%ebp)\n"
        "movl %edi, %esi\n"
        "subl $4, %esi\n"
        ".Lf2bfe18_002bfea4:\n"
        "leal -4(%ecx), %ebx\n"
        /* { scope 3 */
        "movl -4(%ecx), %edx\n" /* line 330 | __value */
        /* { scope 4 */
        /* { scope 5 */
        "movl 8(%ebp), %edi\n" /* line 301 | __first */
        "movl (%edi), %eax\n"
        "movl %eax, -4(%ecx)\n"
        "movl 0x14(%ebp), %eax\n" /* line 302 | __comp */
        "movl %eax, 0x10(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %esi, %eax\n"
        "sarl $2, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll ZSt13__adjust_heapIPP8GfxImageiS1_PFiS1_S1_EEvT_T0_S6_T1_T2_\n"
        "movl %ebx, %ecx\n"
        "subl $4, %esi\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "movl %edi, %eax\n" /* line 457 */
        "subl 0xc(%ebp), %eax\n" /* __last */
        "addl -0x2c(%ebp), %eax\n"
        "leal 4(%eax, %esi), %eax\n"
        "cmpl $7, %eax\n"
        "jg .Lf2bfe18_002bfea4\n"
        /* } scope */
        /* } scope */
        ".Lf2bfe18_002bfeec:\n"
        "addl $0x4c, %esp\n" /* line 2538 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2bfe18_002bfef4:\n"
        "movl 0x10(%ebp), %edx\n" /* line 457 | __depth_limit */
        "movl %edx, -0x1c(%ebp)\n"
        "movl $0, -0x20(%ebp)\n"
        "movl 0xc(%ebp), %esi\n" /* __last */
        ".Lf2bfe18_002bff04:\n"
        "subl $1, -0x1c(%ebp)\n" /* line 2526 */
        "movl %eax, %edx\n"
        "sarl $2, %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "movl 8(%ebp), %edi\n" /* __first */
        "leal (%edi, %eax, 4), %ebx\n"
        "subl $4, %esi\n"
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 124 */
        "movl %eax, 4(%esp)\n"
        "movl (%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testl %eax, %eax\n"
        "je .Lf2bfe18_002bfffd\n"
        "movl 0xc(%ebp), %edx\n" /* line 125 | __last */
        "movl -4(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testl %eax, %eax\n"
        "je .Lf2bfe18_002bff9c\n"
        ".Lf2bfe18_002bff4b:\n"
        "movl %ebx, %esi\n" /* line 133 */
        /* } scope */
        ".Lf2bfe18_002bff4d:\n"
        "movl (%esi), %edi\n" /* line 2536 | __b, __pivot */
        "movl 8(%ebp), %esi\n" /* __first, __b */
        "movl 0xc(%ebp), %ebx\n" /* __last */
        /* { scope 2 */
        ".Lf2bfe18_002bff55:\n"
        "movl %edi, 4(%esp)\n" /* line 2056 */
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testl %eax, %eax\n"
        "jne .Lf2bfe18_002bff97\n"
        ".Lf2bfe18_002bff65:\n"
        "subl $4, %ebx\n" /* line 2060 */
        "movl (%ebx), %eax\n" /* line 2059 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testl %eax, %eax\n"
        "jne .Lf2bfe18_002bff65\n"
        "cmpl %ebx, %esi\n" /* line 2061 */
        "jae .Lf2bfe18_002bffba\n"
        /* { scope 3 */
        /* { scope 4 */
        "movl (%esi), %edx\n" /* line 97 | __tmp */
        "movl (%ebx), %eax\n" /* line 98 */
        "movl %eax, (%esi)\n"
        "movl %edx, (%ebx)\n" /* line 99 */
        /* } scope */
        /* } scope */
        "addl $4, %esi\n" /* line 2064 */
        "movl %edi, 4(%esp)\n" /* line 2056 */
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testl %eax, %eax\n"
        "je .Lf2bfe18_002bff65\n"
        ".Lf2bfe18_002bff97:\n"
        "addl $4, %esi\n" /* line 2057 */
        "jmp .Lf2bfe18_002bff55\n"
        /* } scope */
        /* { scope 2 */
        ".Lf2bfe18_002bff9c:\n"
        "movl 0xc(%ebp), %edi\n" /* line 127 | __last */
        "movl -4(%edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* __first */
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testl %eax, %eax\n"
        "jne .Lf2bfe18_002bff4d\n"
        ".Lf2bfe18_002bffb5:\n"
        "movl 8(%ebp), %esi\n" /* line 133 | __first */
        "jmp .Lf2bfe18_002bff4d\n"
        /* } scope */
        ".Lf2bfe18_002bffba:\n"
        "movl 0x14(%ebp), %edi\n" /* line 2537 | __comp, __pivot */
        "movl %edi, 0xc(%esp)\n" /* __pivot */
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* __last */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* __b */
        "calll ZSt16__introsort_loopIPP8GfxImageiPFiS1_S1_EEvT_S5_T0_T1_\n"
        /* } scope */
        "movl %esi, %eax\n" /* line 2519 */
        "subl 8(%ebp), %eax\n" /* __first */
        "cmpl $0x43, %eax\n"
        "jle .Lf2bfe18_002bfeec\n"
        "addl $1, -0x20(%ebp)\n"
        "movl %esi, 0xc(%ebp)\n" /* __last */
        /* { scope 1 */
        "movl -0x20(%ebp), %edx\n" /* line 2521 */
        "cmpl %edx, 0x10(%ebp)\n" /* __depth_limit */
        "jne .Lf2bfe18_002bff04\n"
        "jmp .Lf2bfe18_002bfe3b\n"
        /* { scope 2 */
        ".Lf2bfe18_002bfffd:\n"
        "movl 0xc(%ebp), %edi\n" /* line 131 | __last */
        "movl -4(%edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* __first */
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testl %eax, %eax\n"
        "jne .Lf2bfe18_002bffb5\n"
        "movl -4(%edi), %eax\n" /* line 133 */
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testl %eax, %eax\n"
        "jne .Lf2bfe18_002bff4d\n"
        "jmp .Lf2bfe18_002bff4b\n"
    );
}
#endif /* original naked __introsort_loop */
