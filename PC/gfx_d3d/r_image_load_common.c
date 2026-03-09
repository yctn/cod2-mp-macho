/* Decompiled from: r_image_load_common.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_image_load_common.cpp */

#include "common_types.h"
#include "imports.h"

/* extern declarations for called functions */
extern void Image_PicmipForSemantic(int semantic, Picmip *picmip);
extern void Image_Create2DTexture(GfxImage *image, int width, int height, int mipmapCount, DWORD usage, D3DFORMAT imageFormat, D3DPOOL memPool);
extern void Image_Create3DTexture(GfxImage *image, int width, int height, int depth, int mipmapCount, DWORD usage, D3DFORMAT imageFormat, D3DPOOL memPool);
extern void Image_CreateCubeTexture(GfxImage *image, int edgeLen, int mipmapCount, DWORD usage, D3DFORMAT imageFormat, D3DPOOL memPool);
extern void Image_TrackTexture(GfxImage *image, int imageFlags, D3DFORMAT format, int width, int height, int depth);

/* g_dxIter was imp_alwaysfails, g_dx was imp_dx */

/* Vtable indices for D3D9 texture interfaces (i386 32-bit) */
#define VTABLE_LOCKRECT    19  /* 0x4C / 4 */
#define VTABLE_UNLOCKRECT  20  /* 0x50 / 4 */

typedef int (*LockRectFn)(void *texture, int level, D3DLOCKED_RECT *lockedRect, void *rect, int flags);
typedef int (*LockRectCubeFn)(void *texture, int face, int level, D3DLOCKED_RECT *lockedRect, void *rect, int flags);
typedef int (*LockBoxFn)(void *texture, int level, D3DLOCKED_BOX *lockedBox, void *box, int flags);
typedef int (*UnlockRectFn)(void *texture, int level);
typedef int (*UnlockRectCubeFn)(void *texture, int face, int level);
typedef int (*UnlockBoxFn)(void *texture, int level);

static int Image_Max1(int val)
{
    return val > 1 ? val : 1;
}

/* line 403 */
void Image_GetPicmip(const GfxImage *image, Picmip *picmip)
{
    if (image->noPicmip) {
        *(short *)picmip = 0;
    } else {
        Image_PicmipForSemantic(image->semantic, picmip);
    }
}

/* line 506 */
D3DCUBEMAP_FACES Image_CubemapFace(int face)
{
    return (D3DCUBEMAP_FACES)face;
}

static int Image_FormatMemory(D3DFORMAT format, int width, int height, int depth)
{
    switch (format) {
        case D3DFMT_A8R8G8B8:
        case D3DFMT_X8R8G8B8:
        case D3DFMT_D32:
        case D3DFMT_D24S8:
        case D3DFMT_R32F:
            return width * height * depth * 4;
        case D3DFMT_R5G6B5:
        case D3DFMT_A8L8:
        case D3DFMT_D16:
            return width * height * depth * 2;
        case D3DFMT_L8:
        case D3DFMT_A8:
            return width * height * depth;
        case D3DFMT_DXT1:
            return ((width + 3) / 4) * ((height + 3) / 4) * depth * 8;
        case D3DFMT_DXT3:
        case D3DFMT_DXT5:
            return ((width + 3) / 4) * ((height + 3) / 4) * depth * 16;
        default:
            return 0;
    }
}

/* line 559 */
int Image_GetCardMemoryAmount(int imageFlags, D3DFORMAT format, int width, int height, int depth)
{
    int memory;

    memory = Image_FormatMemory(format, width, height, depth);

    /* Add mipmap chain if not nomipmaps (flag bit 1) */
    if (!(imageFlags & 2)) {
        while (width > 1 || height > 1 || depth > 1) {
            width >>= 1;
            width = Image_Max1(width);
            height >>= 1;
            height = Image_Max1(height);
            depth >>= 1;
            depth = Image_Max1(depth);
            memory += Image_FormatMemory(format, width, height, depth);
        }
    }

    /* Cubemap: multiply by 6 faces */
    if (imageFlags & 4) {
        memory = memory * 6;
    }

    return memory;
}

/* line 420 */
void Image_Setup(GfxImage *image, int width, int height, int depth, int imageFlags, DWORD usage, D3DFORMAT imageFormat)
{
    int minSize;
    int maxDim;
    int i;
    int mipLimit;
    int picmipLevel;
    int w, h, d;
    int mipmapCount;

    /* line 427: set noPicmip based on flags */
    image->noPicmip = (imageFlags & 3) != 0;

    /* line 428: Get picmip for this image (inlined Image_GetPicmip) */
    if (image->noPicmip) {
        *(short *)&image->picmip = 0;
    } else {
        Image_PicmipForSemantic(image->semantic, &image->picmip);
    }

    /* line 368: Determine min block size for DXT formats */
    if (imageFormat == D3DFMT_DXT1 || imageFormat == D3DFMT_DXT3 || imageFormat == D3DFMT_DXT5) {
        minSize = 4;
    } else {
        minSize = 1;
    }

    /* line 391-398: Clamp picmip so image doesn't shrink below minSize */
    maxDim = width;
    if (height > maxDim) {
        maxDim = height;
    }

    mipLimit = 3;
    for (i = 3; i > 0; i--) {
        if ((maxDim >> i) >= minSize) {
            mipLimit = i;
            break;
        }
        mipLimit = i - 1;
    }

    for (i = 0; i < 2; i++) {
        if (image->picmip.platform[i] > (byte)mipLimit) {
            image->picmip.platform[i] = (byte)mipLimit;
        }
    }

    /* line 431-433: Apply picmip and set dimensions */
    picmipLevel = image->picmip.platform[0];
    w = Image_Max1(width >> picmipLevel);
    image->width = (unsigned short)w;
    h = Image_Max1(height >> picmipLevel);
    image->height = (unsigned short)h;
    d = Image_Max1(depth >> picmipLevel);
    image->depth = (unsigned short)d;

    /* line 440: mipmapCount from imageFlags bit 1 */
    mipmapCount = (imageFlags >> 1) & 1;

    /* line 444-454: Create texture based on type */
    if (imageFlags & 4) {
        /* Cubemap */
        Image_CreateCubeTexture(image, w, mipmapCount, usage, imageFormat, 1);
    } else if (imageFlags & 8) {
        /* 3D Volume texture */
        Image_Create3DTexture(image, w, h, d, mipmapCount, usage, imageFormat, 1);
    } else {
        /* 2D texture */
        Image_Create2DTexture(image, w, h, mipmapCount, usage, imageFormat, 1);
    }

    /* line 481: Track texture memory usage */
    Image_TrackTexture(image, imageFlags, imageFormat, width, height, depth);
}

/*
 * Helper to get the source row stride in bytes for a given format and width.
 * Used in the 2D/cube LockRect upload path.
 */
static void Image_GetSrcStrideAndDy(D3DFORMAT format, int srcWidth, int *outStride, int *outDy)
{
    switch (format) {
        case D3DFMT_A8R8G8B8:
        case D3DFMT_X8R8G8B8:
            *outStride = srcWidth * 4;
            *outDy = 1;
            return;
        case D3DFMT_L8:
        case D3DFMT_A8:
            *outStride = srcWidth;
            *outDy = 1;
            return;
        case D3DFMT_R5G6B5:
        case D3DFMT_A8L8:
        case D3DFMT_X8B8G8R8:
            *outStride = srcWidth * 2;
            *outDy = 1;
            return;
        case D3DFMT_DXT1:
            *outStride = ((srcWidth + 3) / 4) * 8;
            *outDy = 4;
            return;
        case D3DFMT_DXT3:
        case D3DFMT_DXT5:
            *outStride = ((srcWidth + 3) / 4) * 16;
            *outDy = 4;
            return;
        default:
            *outStride = 0;
            *outDy = 0;
            return;
    }
}

/*
 * Helper to copy image data from src to locked texture surface.
 * If srcStride matches dstPitch, uses a single memcpy.
 * Otherwise copies row-by-row.
 */
static void Image_CopyToLockedSurface(byte *dst, int dstPitch, const byte *src, int srcStride, int dy, int height)
{
    int y;

    if (srcStride == dstPitch) {
        /* Fast path: single memcpy for entire surface */
        int rows = ((height - 1) / dy) + 1;
        memcpy(dst, src, rows * srcStride);
    } else {
        /* Row-by-row copy */
        if (height > 0) {
            for (y = 0; y < height; y += dy) {
                memcpy(dst, src, srcStride);
                dst += dstPitch;
                src += srcStride;
            }
        }
    }
}

/*
 * Compute per-slice byte size for 3D volume textures.
 */
static int Image_VolumeSlicePitch(D3DFORMAT format, int srcWidth, int srcHeight)
{
    switch (format) {
        case D3DFMT_A8R8G8B8:
        case D3DFMT_D32:
        case D3DFMT_D24S8:
        case D3DFMT_R32F:
            return srcWidth * srcHeight * 4;
        case D3DFMT_X8R8G8B8:
            /* R8G8B8 (3 bytes per pixel) mapped to this case in original code */
            return srcWidth * srcHeight * 3;
        case D3DFMT_R5G6B5:
        case D3DFMT_A8L8:
        case D3DFMT_D16:
            return srcWidth * srcHeight * 2;
        case D3DFMT_L8:
        case D3DFMT_A8:
            return srcWidth * srcHeight;
        case D3DFMT_DXT1:
            return ((srcWidth + 3) / 4) * ((srcHeight + 3) / 4) * 8;
        case D3DFMT_DXT3:
        case D3DFMT_DXT5:
            return ((srcWidth + 3) / 4) * ((srcHeight + 3) / 4) * 16;
        default:
            return 0;
    }
}

/* line 296 */
void Image_UploadData(GfxImage *image, D3DFORMAT format, int face, int mipLevel, const byte *src)
{
    int srcWidth, srcHeight, srcDepth;
    int srcStride, dy;
    int dstPitch;
    byte *dst;
    D3DLOCKED_RECT lockedRect;
    D3DLOCKED_BOX lockedBox;
    int srcRowPitch;
    int sliceIndex;
    void *texture;
    void **vtable;

    /* No D3D device (com_skipRenderer 1) — skip GPU upload.
     * imp_dx = &dx (DxGlobals BSS struct). Device ptr at offset +8.
     * Original decompiler checked *(int *)imp_dx which reads dx.hinst (0 on Linux). */
    if (*(int *)((byte *)imp_dx + 8) == 0 || *(int *)(*(int *)((byte *)imp_dx + 8)) == 0)
        return;

    if (image->mapType == 4) {
        /* TODO: Volume texture upload needs CDirect3DVolumeTexture vtable */
        return;
#if 0 /* disabled until volume texture vtable is populated */
        /* line 298: 3D Volume texture upload */
        srcWidth = Image_Max1(image->width >> mipLevel);
        srcHeight = Image_Max1(image->height >> mipLevel);
        srcDepth = Image_Max1(image->depth >> mipLevel);

        /* Compute per-slice pitch */
        switch (format) {
            case D3DFMT_A8R8G8B8:
            case D3DFMT_D32:
            case D3DFMT_D24S8:
            case D3DFMT_R32F:
                srcRowPitch = srcWidth * srcHeight * 4;
                break;
            case D3DFMT_X8R8G8B8:
                srcRowPitch = srcWidth * srcHeight * 3;
                break;
            case D3DFMT_R5G6B5:
            case D3DFMT_A8L8:
            case D3DFMT_D16:
                srcRowPitch = srcWidth * srcHeight * 2;
                break;
            case D3DFMT_L8:
            case D3DFMT_A8:
                srcRowPitch = srcWidth * srcHeight;
                break;
            case D3DFMT_DXT1:
                srcRowPitch = ((srcWidth + 3) / 4) * ((srcHeight + 3) / 4) * 8;
                break;
            case D3DFMT_DXT3:
            case D3DFMT_DXT5:
                srcRowPitch = ((srcWidth + 3) / 4) * ((srcHeight + 3) / 4) * 16;
                break;
            default:
                srcRowPitch = 0;
                break;
        }

        /* LockBox on IDirect3DVolumeTexture9 */
        do {
            texture = (void *)image->texture.volmap;
            if (!texture || !*(void **)texture) return;
            vtable = *(void ***)texture;
            ((LockBoxFn)vtable[VTABLE_LOCKRECT])(texture, mipLevel, &lockedBox, 0, 0);
        } while (*(volatile int *)imp_alwaysfails);

        dst = (byte *)lockedBox.pBits;

        if (srcDepth > 0) {
            for (sliceIndex = 0; sliceIndex < srcDepth; sliceIndex++) {
                dstPitch = lockedBox.RowPitch;

                /* Compute src stride and dy for this format */
                switch (format) {
                    case D3DFMT_A8R8G8B8:
                    case D3DFMT_X8R8G8B8:
                        srcStride = srcWidth * 4;
                        dy = 1;
                        break;
                    case D3DFMT_L8:
                    case D3DFMT_A8:
                        srcStride = srcWidth;
                        dy = 1;
                        break;
                    case D3DFMT_R5G6B5:
                    case D3DFMT_A8L8:
                    case D3DFMT_X8B8G8R8:
                        srcStride = srcWidth * 2;
                        dy = 1;
                        break;
                    case D3DFMT_DXT1:
                        srcStride = ((srcWidth + 3) / 4) * 8;
                        dy = 4;
                        break;
                    case D3DFMT_DXT3:
                    case D3DFMT_DXT5:
                        srcStride = ((srcWidth + 3) / 4) * 16;
                        dy = 4;
                        break;
                    default:
                        goto volume_slice_done;
                }

                Image_CopyToLockedSurface(dst, dstPitch, src, srcStride, dy, srcHeight);

            volume_slice_done:
                src += srcRowPitch;
                dst += lockedBox.SlicePitch;
            }
        }

        /* UnlockBox on IDirect3DVolumeTexture9 */
        do {
            texture = (void *)image->texture.volmap;
            vtable = *(void ***)texture;
            ((UnlockBoxFn)vtable[VTABLE_UNLOCKRECT])(texture, mipLevel);
        } while (*(volatile int *)imp_alwaysfails);

        return;
#endif
    }

    if (image->mapType == 5) {
        /* line 305: Skip non-zero mip levels if device doesn't support them */
        if (mipLevel != 0 && *(byte *)((byte *)imp_dx + 0x2d7b) == 0) {
            return;
        }
        /* Fall through to default 2D/cube upload path */
    }

    /* Default: 2D texture / cubemap upload */
    srcWidth = Image_Max1(image->width >> mipLevel);
    srcHeight = Image_Max1(image->height >> mipLevel);

    if (image->mapType == 3) {
        /* line 131: 2D texture path - LockRect without face parameter */
        do {
            texture = (void *)image->texture.map;
            if (!texture || !*(void **)texture) return; /* safety: skip if no texture object */
            vtable = *(void ***)texture;
            if (!vtable[VTABLE_LOCKRECT]) return;
            ((LockRectFn)vtable[VTABLE_LOCKRECT])(texture, mipLevel, &lockedRect, 0, 0);
        } while (*(volatile int *)imp_alwaysfails);
    } else {
        /* line 141: Cubemap/default path - LockRect with face parameter */
        do {
            texture = (void *)image->texture.cubemap;
            if (!texture || !*(void **)texture) return; /* safety: skip if no texture object */
            vtable = *(void ***)texture;
            if (!vtable[VTABLE_LOCKRECT]) return;
            ((LockRectCubeFn)vtable[VTABLE_LOCKRECT])(texture, face, mipLevel, &lockedRect, 0, 0);
        } while (*(volatile int *)imp_alwaysfails);
    }

    dst = (byte *)lockedRect.pBits;
    dstPitch = lockedRect.Pitch;

    /* Compute source stride and row step for this format */
    switch (format) {
        case D3DFMT_A8R8G8B8:
        case D3DFMT_X8R8G8B8:
            srcStride = srcWidth * 4;
            dy = 1;
            break;
        case D3DFMT_L8:
        case D3DFMT_A8:
            srcStride = srcWidth;
            dy = 1;
            break;
        case D3DFMT_R5G6B5:
        case D3DFMT_A8L8:
        case D3DFMT_X8B8G8R8:
            srcStride = srcWidth * 2;
            dy = 1;
            break;
        case D3DFMT_DXT1:
            srcStride = ((srcWidth + 3) / 4) * 8;
            dy = 4;
            break;
        case D3DFMT_DXT3:
        case D3DFMT_DXT5:
            srcStride = ((srcWidth + 3) / 4) * 16;
            dy = 4;
            break;
        default:
            goto unlock_2d;
    }

    Image_CopyToLockedSurface(dst, dstPitch, src, srcStride, dy, srcHeight);

unlock_2d:
    if (image->mapType == 3) {
        /* 2D texture UnlockRect */
        do {
            texture = (void *)image->texture.map;
            vtable = *(void ***)texture;
            ((UnlockRectFn)vtable[VTABLE_UNLOCKRECT])(texture, mipLevel);
        } while (*(volatile int *)imp_alwaysfails);
    } else {
        /* Cubemap UnlockRect with face */
        do {
            texture = (void *)image->texture.cubemap;
            vtable = *(void ***)texture;
            ((UnlockRectCubeFn)vtable[VTABLE_UNLOCKRECT])(texture, face, mipLevel);
        } while (*(volatile int *)imp_alwaysfails);
    }
}
