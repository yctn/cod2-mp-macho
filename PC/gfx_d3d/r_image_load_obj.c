/* ASM dump from: r_image_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_image_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/gfx_d3d/r_image.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/com_vector.h"
 */

extern void Image_Setup(GfxImage *image, int width, int height, int depth, int semantic, int flags, int imageFormat);
extern int Image_CubemapFace(int face);
extern void Image_UploadData(GfxImage *image, int imageFormat, int face, int mipLevel, byte *pixels);
extern void Image_Create2DTexture(GfxImage *image, int width, int height, int depth, int flags, int format, int unused);
extern float Vec3NormalizeTo(const vec_t *src, vec_t *dst);
extern float Vec3Normalize(vec_t *v);
extern float floorf(float x);
extern float FresnelTerm(float ior0, float ior1, float cosIncident);
extern void AxisTransformVector(const void *matrix, float x, float y, float z, vec_t *out);
extern int Vec3MajorAxis(const vec_t *v);
extern void *Hunk_AllocateTempMemoryInternal(int size);
extern void Hunk_FreeTempMemory(void *buf);
extern void R_LoadJpg(const char *filepath, void **file, byte **pic, int *width, int *height, int *imageFormat);
extern void R_GenerateOutdoorImage(GfxImage *image);
extern void Image_BuildSpecularityMap(int unused, byte *pic);
/* strcmp and memcmp from system headers */
extern GfxImage * Image_Alloc(const char *name, int category, int semantic, int imageTrack);
static vec3_t lightGridLookupMatrix[3]; /* lightGridLookupMatrix */
static const int faceAxis[6][3]; /* faceAxis */

void Image_Generate2D(GfxImage *image, byte *pixels, int width, int height, int imageFormat);
void Image_Generate3D(GfxImage *image, byte *pixels, int width, int height, int depth, D3DFORMAT imageFormat);
void Image_BuildWaterMap(GfxImage *image);
static jpeg_alloc Image_LoadBitmap(GfxImage *image, const GfxImageFileHeader *fileHeader, const byte *data, D3DFORMAT format, int bytesPerPixel);
static jpeg_alloc Image_LoadDxtc(GfxImage *image, const GfxImageFileHeader *fileHeader, const byte *data, D3DFORMAT format, int bytesPerBlock);
#ifndef __EMSCRIPTEN__
static jpeg_alloc Image_LoadWavelet(GfxImage *image, const byte *data, D3DFORMAT format, int bytesPerPixel);
#endif
jpeg_alloc Image_LoadFromData(GfxImage *image, GfxImageFileHeader *fileHeader, const byte *srcData);
static void Image_GetSunHalfAngleForVector(const vec_t *facePos, int ignored, byte *pixel);
static void Image_GetWaterColorForVector(const vec_t *facePos, int packedColor, byte *pixel);
static void Image_GetLightGridWeightsForVector(const vec_t *facePos, int subMap, byte *pixel);
Bool Image_LoadFromFile(GfxImage *image);
GfxImage * R_CreateWaterMap(char *name, int imageWidth, int imageHeight);
typedef void (*CubemapPixelCallback)(const vec_t *facePos, int userData, byte *pixel);
static void Image_GenerateCubemapFunction(GfxImage *image, byte *pic, int res, int userData, CubemapPixelCallback Callback);
Bool Image_LoadRaw(GfxImage *image, const char *filepath, int imageTrack);
static jpeg_alloc Image_LoadLightmapWeights(GfxImage *image);
GfxImage * Image_Load(const char *name, int semantic, int imageTrack);

/* Compute mip level count: smallest power of 2 >= max(w, h, d), return log2 */
static int Image_ComputeMipCount(int w, int h, int d)
{
    int mips = 1, size = 1;
    while (size < w || size < h || size < d) {
        size <<= 1;
        mips++;
    }
    return mips - 1;
}

/* line 560 */
void Image_Generate2D(GfxImage *image, byte *pixels, int width, int height, int imageFormat)
{
    int face;
    Image_Setup(image, width, height, 1, 3, 0, imageFormat);
    face = Image_CubemapFace(0);
    Image_UploadData(image, imageFormat, face, 0, pixels);
}

/* line 598 */
void Image_Generate3D(GfxImage *image, byte *pixels, int width, int height, int depth, D3DFORMAT imageFormat)
{
    int face;
    Image_Setup(image, width, height, depth, 0xb, 0, imageFormat);
    face = Image_CubemapFace(0);
    Image_UploadData(image, imageFormat, face, 0, pixels);
}

/* line 1180 */
void Image_BuildWaterMap(GfxImage *image)
{
    if (*(int *)((char *)(*(void **)imp_r_rendererInUse) + 8) == 2) {
        Image_Create2DTexture(image, *(unsigned short *)((char *)image + 0x18), *(unsigned short *)((char *)image + 0x1a), 1, 0x200, 0x16, 0);
    } else {
        Image_Create2DTexture(image, *(unsigned short *)((char *)image + 0x18), *(unsigned short *)((char *)image + 0x1a), 0, 0x200, 0x32, 0);
    }
}

/* line 195 */
/* line 195 */
static jpeg_alloc Image_LoadBitmap_impl(GfxImage *image, const GfxImageFileHeader *fileHeader, const byte *data, D3DFORMAT format, int bytesPerPixel)
{
    byte *img = (byte *)image;
    const byte *hdr = (const byte *)fileHeader;
    int faceCount, mipLevel, maxMip;
    byte *expandedData = NULL;
    const byte *srcPtr = data;

    /* Setup image dimensions and format */
    Image_Setup(image, *(short *)(hdr + 6), *(short *)(hdr + 8), *(short *)(hdr + 0xa),
                hdr[5], 0, format);

    /* Cubemap: 6 faces if image type == 5, else 1 */
    faceCount = (*(int *)img == 5) ? 6 : 1;

    /* Allocate temp buffer for BGR→ARGB expansion if needed */
    if (format == 0x16) { /* D3DFMT_A8R8G8B8 */
        int pixelCount = *(unsigned short *)(img + 0x18) * *(unsigned short *)(img + 0x1a);
        expandedData = (byte *)Hunk_AllocateTempMemoryInternal(pixelCount * 4);
    }

    /* Compute max mip level */
    if (hdr[5] & 2) {
        mipLevel = 0; /* hasMips flag set: start from 0 */
    } else {
        mipLevel = Image_ComputeMipCount(*(short *)(hdr + 6), *(short *)(hdr + 8), *(short *)(hdr + 0xa));
    }

    /* Iterate mip levels from max down to picmip level */
    while (1) {
        maxMip = img[8];
        if (mipLevel < maxMip)
            break;

        {
            int mipW = *(short *)(hdr + 6) >> mipLevel;
            int mipH = *(short *)(hdr + 8) >> mipLevel;
            int face;
            int mipPixels, mipDataSize;

            if (mipW < 1) mipW = 1;
            if (mipH < 1) mipH = 1;
            mipPixels = mipW * mipH;
            mipDataSize = mipPixels * bytesPerPixel;

            for (face = 0; face < faceCount; face++) {
                int uploadMip = mipLevel - maxMip;

                if (format == 0x16) {
                    /* Convert BGR (3 bytes) → ARGB (4 bytes) */
                    int p;
                    byte *dst = expandedData;
                    const byte *src = srcPtr;
                    for (p = 0; p < mipPixels; p++) {
                        dst[0] = 0xFF;     /* alpha */
                        dst[1] = src[2];   /* R */
                        dst[2] = src[1];   /* G */
                        dst[3] = src[0];   /* B */
                        dst += 4;
                        src += 3;
                    }
                    Image_UploadData(image, 0x16, Image_CubemapFace(face), uploadMip, expandedData);
                } else {
                    Image_UploadData(image, format, Image_CubemapFace(face), uploadMip, (byte *)srcPtr);
                }
                srcPtr += mipDataSize;
            }
        }
        mipLevel--;
    }

    /* Free temp expansion buffer */
    if (expandedData)
        Hunk_FreeTempMemory(expandedData);
}

#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
static jpeg_alloc Image_LoadBitmap(GfxImage *image, const GfxImageFileHeader *fileHeader, const byte *data, D3DFORMAT format, int bytesPerPixel)
{
    Image_LoadBitmap_impl(image, fileHeader, data, format, bytesPerPixel);
}
#else
/* Naked trampoline: marshals register args (eax=image, edx=fileHeader, ecx=data)
 * plus stack args (format, bytesPerPixel) to _impl */
static __attribute__((naked))
jpeg_alloc Image_LoadBitmap(GfxImage *image, const GfxImageFileHeader *fileHeader, const byte *data, D3DFORMAT format, int bytesPerPixel)
{
#ifndef __EMSCRIPTEN__
    __asm__ __volatile__ (
        "pushl 0xc(%esp)\n"    /* bytesPerPixel */
        "pushl 0xc(%esp)\n"    /* format */
        "pushl %ecx\n"         /* data */
        "pushl %edx\n"         /* fileHeader */
        "pushl %eax\n"         /* image */
        "calll Image_LoadBitmap_impl\n"
        "addl $20, %esp\n"
        "retl $8\n"
    );
#else
    (void)image; (void)fileHeader; (void)data; (void)format; (void)bytesPerPixel;
#endif
}
#endif

#if 0 /* original Image_LoadBitmap ASM — replaced above */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl %edx, -0x30(%ebp)\n"
        "movl %ecx, -0x34(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* format */
        "movl %eax, -0x38(%ebp)\n" /* format */
        "movl 0xc(%ebp), %edx\n" /* bytesPerPixel */
        "movl %edx, -0x3c(%ebp)\n" /* bytesPerPixel */
        /* { scope 1 */
        "movl %eax, 0x18(%esp)\n" /* line 48 */
        "movl $0, 0x14(%esp)\n"
        "movl -0x30(%ebp), %ecx\n"
        "movzbl 5(%ecx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movswl 0xa(%ecx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movswl 8(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movswl 6(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x2c(%ebp), %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll Image_Setup\n"
        "xorl %eax, %eax\n" /* line 211 */
        "cmpl $5, (%ebx)\n" /* width */
        "sete %al\n"
        "leal 1(%eax, %eax, 4), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* faceCount */
        "cmpl $0x16, -0x38(%ebp)\n" /* line 217 | format */
        "je .Lffc83e_000fca40\n"
        "movl $0, -0x1c(%ebp)\n" /* expandedData */
        /* { scope 2 */
        ".Lffc83e_000fc8b6:\n"
        "movl -0x30(%ebp), %eax\n" /* line 61 */
        "testb $2, 5(%eax)\n"
        "je .Lffc83e_000fca02\n"
        "movl $0, -0x24(%ebp)\n" /* mipLevel */
        /* } scope */
        ".Lffc83e_000fc8ca:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 221 */
        "movzbl 8(%edx), %eax\n"
        "cmpl %eax, -0x24(%ebp)\n" /* mipLevel */
        "jl .Lffc83e_000fc9b2\n"
        ".Lffc83e_000fc8da:\n"
        "movl -0x30(%ebp), %ecx\n" /* line 142 */
        "movswl 6(%ecx), %ebx\n"
        "movzbl -0x24(%ebp), %ecx\n" /* mipLevel */
        "sarl %cl, %ebx\n"
        "movl $1, %eax\n" /* line 154 */
        "movl $1, %edi\n"
        "cmpl %ebx, %edi\n"
        "cmovnsl %eax, %ebx\n"
        "movl -0x30(%ebp), %ecx\n" /* line 142 */
        "movswl 8(%ecx), %edx\n"
        "movzbl -0x24(%ebp), %ecx\n" /* mipLevel */
        "sarl %cl, %edx\n"
        "cmpl %edx, %edi\n" /* line 154 */
        "cmovnsl %eax, %edx\n"
        "movl -0x20(%ebp), %ecx\n" /* line 225 | faceCount */
        "testl %ecx, %ecx\n"
        "jle .Lffc83e_000fc99e\n"
        "movl %ebx, %esi\n" /* width */
        "imull %edx, %esi\n"
        "movl -0x3c(%ebp), %ebx\n" /* line 236 | bytesPerPixel, width */
        "imull %esi, %ebx\n" /* width */
        "movl %ebx, -0x28(%ebp)\n" /* width */
        "xorw %di, %di\n" /* face */
        ".Lffc83e_000fc924:\n"
        "cmpl $0x16, -0x38(%ebp)\n" /* line 227 | format */
        "jne .Lffc83e_000fc9cb\n"
        "movl -0x34(%ebp), %ecx\n"
        "movl -0x1c(%ebp), %edx\n" /* expandedData */
        "xorl %ebx, %ebx\n" /* width */
        ".Lffc83e_000fc936:\n"
        "movb $0xff, (%edx)\n" /* line 85 */
        "movzbl 2(%ecx), %eax\n" /* line 86 */
        "movb %al, 1(%edx)\n"
        "movzbl 1(%ecx), %eax\n" /* line 87 */
        "movb %al, 2(%edx)\n"
        "movzbl (%ecx), %eax\n" /* line 88 */
        "movb %al, 3(%edx)\n"
        "addl $4, %edx\n" /* line 95 */
        "addl $3, %ecx\n" /* line 96 */
        "addl $1, %ebx\n"
        "cmpl %esi, %ebx\n" /* line 81 */
        "jne .Lffc83e_000fc936\n"
        "movl -0x2c(%ebp), %edx\n" /* line 230 */
        "movzbl 8(%edx), %eax\n"
        "movl -0x24(%ebp), %ebx\n" /* mipLevel, width */
        "subl %eax, %ebx\n" /* width */
        "movl %edi, (%esp)\n" /* face */
        "calll Image_CubemapFace\n"
        "movl -0x1c(%ebp), %ecx\n" /* expandedData */
        "movl %ecx, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* width */
        "movl %eax, 8(%esp)\n"
        "movl $0x16, 4(%esp)\n"
        "movl -0x2c(%ebp), %ebx\n" /* width */
        "movl %ebx, (%esp)\n" /* width */
        "calll Image_UploadData\n"
        ".Lffc83e_000fc990:\n"
        "movl -0x28(%ebp), %edx\n" /* line 236 */
        "addl %edx, -0x34(%ebp)\n"
        "addl $1, %edi\n" /* line 225 | face */
        "cmpl %edi, -0x20(%ebp)\n" /* face, faceCount */
        "jne .Lffc83e_000fc924\n"
        ".Lffc83e_000fc99e:\n"
        "subl $1, -0x24(%ebp)\n" /* line 221 | mipLevel */
        "movl -0x2c(%ebp), %ecx\n"
        "movzbl 8(%ecx), %eax\n"
        "cmpl -0x24(%ebp), %eax\n" /* mipLevel */
        "jle .Lffc83e_000fc8da\n"
        ".Lffc83e_000fc9b2:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 240 | expandedData */
        "testl %eax, %eax\n"
        "je .Lffc83e_000fca38\n"
        "movl -0x1c(%ebp), %ebx\n" /* line 241 | expandedData, width */
        "movl %ebx, 8(%ebp)\n" /* width, format */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 242 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Hunk_FreeTempMemory\n" /* line 241 */
        ".Lffc83e_000fc9cb:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 234 */
        "movzbl 8(%edx), %eax\n"
        "movl -0x24(%ebp), %ebx\n" /* mipLevel, width */
        "subl %eax, %ebx\n" /* width */
        "movl %edi, (%esp)\n" /* face */
        "calll Image_CubemapFace\n"
        "movl -0x34(%ebp), %ecx\n"
        "movl %ecx, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* width */
        "movl %eax, 8(%esp)\n"
        "movl -0x38(%ebp), %ebx\n" /* format, width */
        "movl %ebx, 4(%esp)\n" /* width */
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Image_UploadData\n"
        "jmp .Lffc83e_000fc990\n"
        ".Lffc83e_000fca02:\n"
        "movl %eax, %ebx\n" /* width */
        /* { scope 2 */
        "movswl 6(%eax), %ecx\n" /* line 66 */
        "movl $1, %edx\n"
        "movl $1, %eax\n"
        "movswl 0xa(%ebx), %esi\n"
        "movswl 8(%ebx), %ebx\n"
        "jmp .Lffc83e_000fca21\n"
        ".Lffc83e_000fca1c:\n"
        "addl %eax, %eax\n" /* line 68 */
        "addl $1, %edx\n" /* line 69 */
        ".Lffc83e_000fca21:\n"
        "cmpl %ecx, %eax\n" /* line 66 */
        "jl .Lffc83e_000fca1c\n"
        "cmpl %ebx, %eax\n"
        "jl .Lffc83e_000fca1c\n"
        "cmpl %esi, %eax\n"
        "jl .Lffc83e_000fca1c\n"
        "subl $1, %edx\n"
        "movl %edx, -0x24(%ebp)\n" /* mipLevel */
        "jmp .Lffc83e_000fc8ca\n"
        /* } scope */
        /* } scope */
        ".Lffc83e_000fca38:\n"
        "addl $0x5c, %esp\n" /* line 242 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lffc83e_000fca40:\n"
        "movl -0x2c(%ebp), %edi\n" /* line 218 | face */
        "movzwl 0x18(%edi), %eax\n" /* face */
        "movzwl 0x1a(%edi), %edx\n" /* face */
        "imull %edx, %eax\n"
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocateTempMemoryInternal\n"
        "movl %eax, -0x1c(%ebp)\n" /* expandedData */
        "jmp .Lffc83e_000fc8b6\n"
    );
}
#endif

/* line 245 */
/* line 245 */
static jpeg_alloc Image_LoadDxtc_impl(GfxImage *image, const GfxImageFileHeader *fileHeader, const byte *data, D3DFORMAT format, int bytesPerBlock)
{
    byte *img = (byte *)image;
    const byte *hdr = (const byte *)fileHeader;
    int faceCount, mipLevel;
    const byte *srcPtr = data;

    Image_Setup(image, *(short *)(hdr + 6), *(short *)(hdr + 8), *(short *)(hdr + 0xa),
                hdr[5], 0, format);

    faceCount = (*(int *)img == 5) ? 6 : 1;

    if (hdr[5] & 2)
        mipLevel = 0;
    else
        mipLevel = Image_ComputeMipCount(*(short *)(hdr + 6), *(short *)(hdr + 8), *(short *)(hdr + 0xa));

    { static int dxtd = 0; if (dxtd++ < 5) { FILE *f = fopen("/tmp/es_debug.txt","a"); if(f){fprintf(f,"[DXTC] mipLevel=%d maxMip=%d w=%d h=%d faceCount=%d\n", mipLevel, (int)img[8], *(short*)(hdr+6), *(short*)(hdr+8), faceCount);fclose(f);} } }
    while (1) {
        int maxMip = img[8]; /* picmip level — mip levels below this are skipped */
        int mipW, mipH, face, mipDataSize;
        int blocksW, blocksH;

        if (mipLevel < maxMip)
            break;

        mipW = *(short *)(hdr + 6) >> mipLevel;
        mipH = *(short *)(hdr + 8) >> mipLevel;
        if (mipW < 1) mipW = 1;
        if (mipH < 1) mipH = 1;

        /* DXTC: round up to 4x4 blocks */
        blocksW = (mipW + 3) >> 2;
        blocksH = (mipH + 3) >> 2;
        mipDataSize = blocksW * blocksH * bytesPerBlock;

        if (faceCount <= 0) {
            mipLevel--;
            continue;
        }

        for (face = 0; face < faceCount; face++) {
            int uploadMip = mipLevel - maxMip;
            Image_UploadData(image, format, Image_CubemapFace(face), uploadMip, (byte *)srcPtr);
            srcPtr += mipDataSize;
        }
        mipLevel--;
    }
}

#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
static jpeg_alloc Image_LoadDxtc(GfxImage *image, const GfxImageFileHeader *fileHeader, const byte *data, D3DFORMAT format, int bytesPerBlock)
{
    Image_LoadDxtc_impl(image, fileHeader, data, format, bytesPerBlock);
}
#else
static __attribute__((naked))
jpeg_alloc Image_LoadDxtc(GfxImage *image, const GfxImageFileHeader *fileHeader, const byte *data, D3DFORMAT format, int bytesPerBlock)
{
#ifndef __EMSCRIPTEN__
    __asm__ __volatile__ (
        "pushl 0xc(%esp)\n"
        "pushl 0xc(%esp)\n"
        "pushl %ecx\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll Image_LoadDxtc_impl\n"
        "addl $20, %esp\n"
        "retl $8\n"
    );
#else
    (void)image; (void)fileHeader; (void)data; (void)format; (void)bytesPerBlock;
#endif
}
#endif

/* line 102 */
/* line 102 — Wavelet image decompression: iterates mip levels from bottom to top,
 * decompresses each face via Wavelet_DecompressLevel, uploads to D3D texture.
 * Register convention: eax=image, edx=fileHeader, ecx=data, stack=format,bytesPerPixel. */
extern void Wavelet_DecompressLevel(const byte *src, int offset, void *decode);
extern int Image_CubemapFace(int faceIndex);
extern void *__Znam(unsigned int size); /* operator new[] */
extern void __ZdaPv(void *ptr); /* operator delete[] */
static void Image_LoadWavelet_impl(GfxImage *image, const byte *fileHeader,
    const byte *data, D3DFORMAT format, int bytesPerPixel)
{
    int width = *(short *)(fileHeader + 6);
    int height = *(short *)(fileHeader + 8);
    int depth = *(short *)(fileHeader + 10);
    int mipmapCount = *(byte *)(fileHeader + 5);
    int isCubemap = (*(int *)image == 5);
    int faceCount = isCubemap ? 6 : 1;
    int pixelStride = (bytesPerPixel == 3) ? 4 : bytesPerPixel;
    int startLevel;
    int totalSize = width * height * pixelStride;
    byte *hunkBufs[6];
    byte *hunkAddrs[6]; /* absolute address: hunkBufs[face] + current offset */
    WaveletDecode decode;
    int i, level, face;

    Image_Setup(image, width, height, depth, mipmapCount, 0, format);

    /* The D3D mip level offset and loop bound come from the image's applied
     * picmip (at GfxImage offset 8), NOT from the IWi header's mipmapCount.
     * Image_Setup applies picmip to the image dimensions, so:
     *   D3D mip N has size (image->width >> N) x (image->height >> N)
     *   Wavelet level L has size (rawWidth >> L) x (rawHeight >> L)
     * Mapping: D3D mip = waveletLevel - picmip  */
    int picmip = image->picmip.platform[0];

    /* Compute starting mip level */
    if (*(byte *)(fileHeader + 5) & 2) {
        startLevel = 0;
    } else {
        int maxDim = 1, levels = 1;
        while (maxDim < width || maxDim < height || maxDim < depth) {
            maxDim *= 2;
            levels++;
        }
        startLevel = levels - 1;
    }

    /* Initialize decode state */
    decode.value = 0;
    decode.bit = 0;
    decode.data = data;
    decode.width = width;
    decode.height = height;
    decode.channels = bytesPerPixel;
    decode.bpp = pixelStride;
    decode.mipLevel = startLevel;
    decode.dataInitialized = 0;

    /* Allocate temp buffers for each face */
    for (i = 0; i < faceCount; i++) {
        hunkBufs[i] = (byte *)Hunk_AllocateTempMemoryInternal(totalSize);
        hunkAddrs[i] = 0; /* will be computed as absolute addresses */
    }

    /* Process mip levels from bottom to top */
    for (level = startLevel; level >= picmip; level--, decode.mipLevel = level) {
        int mipW = width >> level; if (mipW < 1) mipW = 1;
        int mipH = height >> level; if (mipH < 1) mipH = 1;
        int sizeForLevel = mipW * mipH * pixelStride;

        if (faceCount <= 0)
            continue;

        int allocSize = (sizeForLevel / 4) * 4;

        for (face = 0; face < faceCount; face++) {
            /* Compute new destination address in hunk buffer */
            byte *oldAddr = hunkAddrs[face];
            byte *newAddr = hunkBufs[face] + totalSize - sizeForLevel;
            hunkAddrs[face] = newAddr;

            Wavelet_DecompressLevel((byte *)oldAddr, newAddr, &decode);

            /* Allocate temp, copy decompressed data */
            void *pTemp = __Znam(allocSize);
            memcpy(pTemp, newAddr, sizeForLevel);

            /* Upload to texture */
            int cubeFace = Image_CubemapFace(face);
            Image_UploadData(image, format, cubeFace, level - picmip, (const byte *)pTemp);

            if (pTemp)
                __ZdaPv(pTemp);
        }
    }

    /* Free hunk allocations */
    for (i = faceCount - 1; i >= 0; i--)
        Hunk_FreeTempMemory(hunkBufs[i]);

    return;
}

#ifdef __EMSCRIPTEN__
/* Clean C version for WASM — no register calling convention */
static jpeg_alloc Image_LoadWavelet(GfxImage *image, const byte *fileHeader, const byte *data, D3DFORMAT format, int bytesPerPixel)
{
    Image_LoadWavelet_impl(image, fileHeader, data, format, bytesPerPixel);
}
#else
/* Naked trampoline: eax=image, edx=fileHeader, ecx=data, stack=format,bytesPerPixel */
static __attribute__((naked))
jpeg_alloc Image_LoadWavelet(GfxImage *image, const byte *data, D3DFORMAT format, int bytesPerPixel)
{
    (void)image; (void)data; (void)format; (void)bytesPerPixel;
#ifndef __EMSCRIPTEN__
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl 0xc(%ebp)\n"    /* bytesPerPixel */
        "pushl 8(%ebp)\n"      /* format */
        "pushl %ecx\n"         /* data */
        "pushl %edx\n"         /* fileHeader */
        "pushl %eax\n"         /* image */
        "calll Image_LoadWavelet_impl\n"
        "addl $20, %esp\n"
        "popl %ebp\n"
        "retl\n"
    );
#else
    (void)image; (void)data; (void)format; (void)bytesPerPixel;
#endif
}
#endif

#if 0 /* original naked (253 lines) */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 102 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl %eax, -0x88(%ebp)\n"
        "movl %edx, %esi\n" /* fileHeader */
        "movl %ecx, -0x8c(%ebp)\n"
        /* { scope 1: pTemp */
        "movl 8(%ebp), %eax\n" /* line 48 | format */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movzbl 5(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movswl 0xa(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movswl 8(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movswl 6(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x88(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll Image_Setup\n"
        "movw $0, -0x68(%ebp)\n" /* line 121 | decode */
        "movw $0, -0x66(%ebp)\n" /* line 122 */
        "movswl 6(%esi), %ebx\n" /* line 123 | fileHeader, face */
        "movl %ebx, -0x60(%ebp)\n" /* face */
        "movswl 8(%esi), %edi\n" /* line 124 | fileHeader */
        "movl %edi, -0x5c(%ebp)\n"
        /* { scope 2 */
        "testb $2, 5(%esi)\n" /* line 61 */
        "je .Lffcbcc_000fce3e\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lffcbcc_000fcc49:\n"
        "movl %eax, -0x50(%ebp)\n" /* line 125 */
        "movl 0xc(%ebp), %ecx\n" /* line 126 | bytesPerPixel */
        "movl %ecx, -0x58(%ebp)\n"
        "movb $0, -0x4c(%ebp)\n" /* line 128 */
        "movl $4, %eax\n" /* line 131 */
        "cmpl $3, %ecx\n"
        "cmovnel %ecx, %eax\n"
        "movl %eax, -0x54(%ebp)\n"
        "movl -0x88(%ebp), %esi\n" /* line 133 | fileHeader */
        "xorl %eax, %eax\n"
        "cmpl $5, (%esi)\n" /* fileHeader */
        "sete %al\n"
        "leal 1(%eax, %eax, 4), %eax\n"
        "movl %eax, -0x7c(%ebp)\n" /* faceCount */
        "imull %edi, %ebx\n" /* line 138 | face */
        "movl %ebx, %eax\n" /* face */
        "imull -0x54(%ebp), %eax\n"
        "movl %eax, -0x84(%ebp)\n" /* totalSize */
        "movl -0x7c(%ebp), %ecx\n" /* line 139 | faceCount */
        "testl %ecx, %ecx\n"
        "jg .Lffcbcc_000fce67\n"
        ".Lffcbcc_000fcc93:\n"
        "movl -0x8c(%ebp), %ecx\n" /* line 149 */
        "movl %ecx, -0x64(%ebp)\n"
        "movl -0x50(%ebp), %ecx\n" /* line 150 */
        "movl %ecx, %ebx\n" /* face */
        "movzbl 8(%esi), %eax\n" /* fileHeader */
        "cmpl %ecx, %eax\n"
        "jg .Lffcbcc_000fce10\n"
        "jmp .Lffcbcc_000fccc9\n"
        ".Lffcbcc_000fccaf:\n"
        "leal -1(%ebx), %ecx\n" /* line 183 | face */
        "movl %ecx, %ebx\n" /* face */
        "movl %ecx, -0x50(%ebp)\n"
        "movl -0x88(%ebp), %edx\n" /* line 150 */
        "movzbl 8(%edx), %eax\n"
        "cmpl %ecx, %eax\n"
        "jg .Lffcbcc_000fce10\n"
        ".Lffcbcc_000fccc9:\n"
        "movl -0x60(%ebp), %eax\n" /* line 142 */
        "sarl %cl, %eax\n"
        "movl $1, %edx\n" /* line 154 */
        "movl $1, %esi\n" /* fileHeader */
        "cmpl %eax, %esi\n" /* fileHeader */
        "cmovnsl %edx, %eax\n"
        "movl %eax, -0x80(%ebp)\n" /* sizeForLevel */
        "movl -0x5c(%ebp), %eax\n" /* line 142 */
        "sarl %cl, %eax\n"
        "cmpl %eax, %esi\n" /* line 154 | fileHeader */
        "cmovnsl %edx, %eax\n"
        "imull -0x80(%ebp), %eax\n" /* sizeForLevel */
        "imull -0x54(%ebp), %eax\n"
        "movl %eax, -0x80(%ebp)\n" /* sizeForLevel */
        "movl -0x7c(%ebp), %edx\n" /* line 155 | faceCount */
        "testl %edx, %edx\n"
        "jle .Lffcbcc_000fccaf\n"
        "shrl $2, %eax\n"
        "movl %eax, -0x74(%ebp)\n"
        "shll $2, %eax\n"
        "movl %eax, -0x70(%ebp)\n"
        "movl $0, -0x6c(%ebp)\n"
        "movl -0x6c(%ebp), %eax\n"
        ".Lffcbcc_000fcd12:\n"
        "shll $2, %eax\n" /* line 102 */
        "leal -0x48(%ebp), %edx\n" /* to */
        "addl %eax, %edx\n"
        /* { scope 2 */
        "movl (%edx), %ecx\n" /* line 157 */
        "movl -0x84(%ebp), %ebx\n" /* line 158 | totalSize, face */
        "addl -0x30(%ebp, %eax), %ebx\n" /* face */
        "subl -0x80(%ebp), %ebx\n" /* sizeForLevel, face */
        "movl %ebx, (%edx)\n" /* face */
        "leal -0x68(%ebp), %eax\n" /* line 159 | decode */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* face */
        "movl %ecx, (%esp)\n"
        "calll Wavelet_DecompressLevel\n"
        "movl -0x70(%ebp), %edx\n" /* line 164 */
        "movl %edx, (%esp)\n"
        "calll __Znam\n"
        "movl %eax, -0x78(%ebp)\n" /* pTemp */
        "movl -0x80(%ebp), %ecx\n" /* line 165 | sizeForLevel */
        "movl %ecx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* face */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        /* The original Mac code byte-swapped every pixel after wavelet decompression.
         * Keep that only on big-endian targets; on little-endian Linux the decompressor
         * output already matches the ARGB upload layout used by the rest of the renderer.
         */
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        /* { scope 3 */
        "movl -0x74(%ebp), %eax\n" /* line 166 */
        "testl %eax, %eax\n"
        "je .Lffcbcc_000fcd99\n"
        "xorl %edi, %edi\n" /* i */
        "movl -0x78(%ebp), %esi\n" /* pTemp, fileHeader */
        /* { scope 4 */
        ".Lffcbcc_000fcd6b:\n"
        "movl (%esi), %edx\n" /* line 169 | fileHeader, Pixel */
        "movl %edx, %ebx\n" /* line 174 | face */
        "shrl $0x18, %ebx\n" /* face */
        "movl %edx, %ecx\n"
        "shll $0x18, %ecx\n"
        "movzbl %dh, %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %ecx\n"
        "shrl $8, %edx\n"
        "andl $0xff00, %edx\n"
        "orl %edx, %ecx\n"
        "orl %ecx, %ebx\n" /* face */
        "movl %ebx, (%esi)\n" /* face, fileHeader */
        /* } scope */
        "addl $1, %edi\n" /* line 166 | i */
        "addl $4, %esi\n" /* fileHeader */
        "cmpl -0x74(%ebp), %edi\n" /* i */
        "jne .Lffcbcc_000fcd6b\n"
        /* } scope */
#else
        "jmp .Lffcbcc_000fcd99\n"
#endif
        ".Lffcbcc_000fcd99:\n"
        "movl -0x88(%ebp), %esi\n" /* line 176 | fileHeader */
        "movzbl 8(%esi), %eax\n" /* fileHeader */
        "movl -0x50(%ebp), %ebx\n" /* face */
        "subl %eax, %ebx\n" /* face */
        "movl -0x6c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Image_CubemapFace\n"
        "movl -0x78(%ebp), %edx\n" /* pTemp */
        "movl %edx, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* face */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* format */
        "movl %ecx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* fileHeader */
        "calll Image_UploadData\n"
        "movl -0x78(%ebp), %edi\n" /* line 177 | pTemp, i */
        "testl %edi, %edi\n" /* i */
        "je .Lffcbcc_000fcde3\n"
        "movl -0x78(%ebp), %esi\n" /* pTemp, fileHeader */
        "movl %esi, (%esp)\n" /* fileHeader */
        "calll __ZdaPv\n"
        /* } scope */
        ".Lffcbcc_000fcde3:\n"
        "addl $1, -0x6c(%ebp)\n" /* line 155 */
        "movl -0x6c(%ebp), %eax\n"
        "cmpl %eax, -0x7c(%ebp)\n" /* faceCount */
        "jne .Lffcbcc_000fcd12\n"
        "movl -0x50(%ebp), %ebx\n" /* face */
        "leal -1(%ebx), %ecx\n" /* line 183 | face */
        "movl %ecx, %ebx\n" /* face */
        "movl %ecx, -0x50(%ebp)\n"
        "movl -0x88(%ebp), %edx\n" /* line 150 */
        "movzbl 8(%edx), %eax\n"
        "cmpl %ecx, %eax\n"
        "jle .Lffcbcc_000fccc9\n"
        ".Lffcbcc_000fce10:\n"
        "movl -0x7c(%ebp), %eax\n" /* line 186 | faceCount */
        "subl $1, %eax\n"
        "js .Lffcbcc_000fce33\n"
        "leal -0x30(%ebp, %eax, 4), %ebx\n" /* face */
        "xorl %esi, %esi\n" /* fileHeader */
        ".Lffcbcc_000fce1e:\n"
        "movl (%ebx), %eax\n" /* line 190 | face */
        "movl %eax, (%esp)\n"
        "calll Hunk_FreeTempMemory\n"
        "addl $1, %esi\n" /* fileHeader */
        "subl $4, %ebx\n" /* face */
        "cmpl %esi, -0x7c(%ebp)\n" /* line 186 | fileHeader, faceCount */
        "jne .Lffcbcc_000fce1e\n"
        /* } scope */
        ".Lffcbcc_000fce33:\n"
        "addl $0xac, %esp\n" /* line 192 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: pTemp */
        /* { scope 2 */
        ".Lffcbcc_000fce3e:\n"
        "movl $1, %ecx\n" /* line 66 */
        "movl $1, %eax\n"
        "movswl 0xa(%esi), %edx\n"
        "jmp .Lffcbcc_000fce53\n"
        ".Lffcbcc_000fce4e:\n"
        "addl %eax, %eax\n" /* line 68 */
        "addl $1, %ecx\n" /* line 69 */
        ".Lffcbcc_000fce53:\n"
        "cmpl %ebx, %eax\n" /* line 66 */
        "jl .Lffcbcc_000fce4e\n"
        "cmpl %edi, %eax\n"
        "jl .Lffcbcc_000fce4e\n"
        "cmpl %edx, %eax\n"
        "jl .Lffcbcc_000fce4e\n"
        "leal -1(%ecx), %eax\n"
        "jmp .Lffcbcc_000fcc49\n"
        /* } scope */
        ".Lffcbcc_000fce67:\n"
        "xorl %ebx, %ebx\n" /* line 139 | face */
        ".Lffcbcc_000fce69:\n"
        "movl -0x84(%ebp), %edx\n" /* line 144 | totalSize */
        "movl %edx, (%esp)\n"
        "calll Hunk_AllocateTempMemoryInternal\n"
        "leal (, %ebx, 4), %edx\n"
        "movl %eax, -0x30(%ebp, %edx)\n"
        "movl $0, -0x48(%ebp, %edx)\n" /* line 146 */
        "addl $1, %ebx\n" /* line 139 | face */
        "cmpl %ebx, -0x7c(%ebp)\n" /* face, faceCount */
        "jne .Lffcbcc_000fce69\n"
        "movl -0x88(%ebp), %esi\n" /* fileHeader */
        "jmp .Lffcbcc_000fcc93\n"
    );
}
#endif /* original naked Image_LoadWavelet */

/* line 320 */
/* Helper: call naked Image_LoadWavelet with register calling convention */
static void Image_LoadWavelet_call(GfxImage *image, const void *fileHeader, const byte *data, int format, int bytesPerPixel)
{
#ifndef __EMSCRIPTEN__
    __asm__ __volatile__ (
        "pushl %4\n"
        "pushl %3\n"
        "movl %2, %%ecx\n"
        "movl %1, %%edx\n"
        "movl %0, %%eax\n"
        "calll Image_LoadWavelet\n"
        "addl $8, %%esp\n"
        :: "g"(image), "g"(fileHeader), "g"(data), "g"(format), "g"(bytesPerPixel)
        : "eax", "ecx", "edx", "memory"
    );
#else
    Image_LoadWavelet_impl(image, (const byte *)fileHeader, data, format, bytesPerPixel);
#endif
}

/* line 320 — Dispatch image data to the appropriate loader based on format type. */
jpeg_alloc Image_LoadFromData(GfxImage *image, GfxImageFileHeader *fileHeader, const byte *srcData)
{
    byte *img = (byte *)image;
    const byte *hdr = (const byte *)fileHeader;
    int formatType;

    /* Clear image flags */
    *(int *)(img + 4) = 0;

    formatType = hdr[4];

    switch (formatType) {
    case 1:  Image_LoadBitmap_impl(image, fileHeader, srcData, 0x15, 4); break; /* A8R8G8B8, 4 bpp */
    case 2:  Image_LoadBitmap_impl(image, fileHeader, srcData, 0x16, 3); break; /* X8R8G8B8 (BGR), 3 bpp */
    case 3:  Image_LoadBitmap_impl(image, fileHeader, srcData, 0x33, 2); break; /* A1R5G5B5, 2 bpp */
    case 4:  Image_LoadBitmap_impl(image, fileHeader, srcData, 0x32, 1); break; /* R5G6B5, 1 bpp */
    case 5:  Image_LoadBitmap_impl(image, fileHeader, srcData, 0x1c, 1); break; /* A4R4G4B4, 1 bpp */
    case 6:  Image_LoadWavelet_call(image, fileHeader, srcData, 0x15, 4); break; /* ARGB wavelet */
    case 7:  Image_LoadWavelet_call(image, fileHeader, srcData, 0x16, 3); break; /* BGR wavelet */
    case 8:  Image_LoadWavelet_call(image, fileHeader, srcData, 0x33, 2); break;
    case 9:  Image_LoadWavelet_call(image, fileHeader, srcData, 0x32, 1); break;
    case 10: Image_LoadWavelet_call(image, fileHeader, srcData, 0x1c, 1); break;
    case 11: Image_LoadDxtc_impl(image, fileHeader, srcData, 0x31545844, 8); break;  /* DXT1, 8 bytes/block */
    case 12: Image_LoadDxtc_impl(image, fileHeader, srcData, 0x33545844, 16); break; /* DXT3, 16 bytes/block */
    case 13: Image_LoadDxtc_impl(image, fileHeader, srcData, 0x35545844, 16); break; /* DXT5, 16 bytes/block */
    default: break;
    }
}

/* line 981 */
/* line 981 — Compute sun half-angle direction and store as packed RGBA byte pixel.
 * halfAngle = normalize(sunDir - normalize(facePos)), mapped to [0,255]. */
static void Image_GetSunHalfAngleForVector(const vec_t *facePos, int ignored, byte *pixel)
{
    vec_t dirFromEye[3], halfAngle[3];
    char *drawSurfs;
    const vec_t *sunDir;

    (void)ignored;

    Vec3NormalizeTo(facePos, dirFromEye);

    drawSurfs = *(char **)((char *)imp_rgp + 0x109c);
    sunDir = (const vec_t *)(drawSurfs + 0xb8);

    halfAngle[0] = sunDir[0] - dirFromEye[0];
    halfAngle[1] = sunDir[1] - dirFromEye[1];
    halfAngle[2] = sunDir[2] - dirFromEye[2];
    Vec3Normalize(halfAngle);

    /* Map [-1,1] → [0,255]: val * 0.5 + 0.5, then * 255 + 0.5 for rounding */
    pixel[3] = (byte)(int)floorf(halfAngle[2] * 0.5f * 255.0f + 0.5f * 255.0f + 0.5f);
    pixel[2] = (byte)(int)floorf(halfAngle[1] * 0.5f * 255.0f + 0.5f * 255.0f + 0.5f);
    pixel[1] = (byte)(int)floorf(halfAngle[0] * 0.5f * 255.0f + 0.5f * 255.0f + 0.5f);
    pixel[0] = 0x80;
}

/* line 1026 */
/* line 1026 — Compute water color with Fresnel reflectance in the alpha channel.
 * packedColor provides base RGB, Fresnel term replaces the alpha byte. */
static void Image_GetWaterColorForVector(const vec_t *facePos, int packedColor, byte *pixel)
{
    vec_t dirFromEye[3];
    float fresnel;
    int color;

    Vec3NormalizeTo(facePos, dirFromEye);

    /* FresnelTerm(ior_air=1.0, ior_water=1.333, cosIncident=dirFromEye.y) */
    fresnel = FresnelTerm(1.0f, *(float *)&(int){0x3faa9fbe}, *(float *)&dirFromEye[1]);

    color = packedColor;
    /* Replace alpha byte (byte 0) with Fresnel reflectance */
    ((byte *)&color)[0] = (byte)(int)floorf(fresnel * 255.0f + 0.5f);
    *(int *)pixel = color;
}

/* line 928 */
/* Clamp an int to [0, 255] */
static inline byte ClampByte(int v)
{
    if (v < 0) return 0;
    if (v > 255) return 255;
    return (byte)v;
}

/* Hermite smoothstep: 3t^2 - 2t^3 = t^2 * (3 - 2t) */
static inline float SmoothStep(float t)
{
    return t * t * (3.0f - 2.0f * t);
}

/* line 928 — Compute light grid blend weights for a cubemap face direction.
 * Transforms facePos through lightGridLookupMatrix, normalizes to cube face,
 * applies smoothstep interpolation, and outputs 4-byte blend weights. */
static void Image_GetLightGridWeightsForVector(const vec_t *facePos, int subMap, byte *pixel)
{
    vec_t transformedPos[3];
    float invMajor;
    int majorAxis;
    float u, v, w;
    float su, sv, sw; /* smoothstepped */
    float w00, w01, w10, w11; /* bilinear weights */

    AxisTransformVector(lightGridLookupMatrix, facePos[0], facePos[1], facePos[2], transformedPos);

    majorAxis = Vec3MajorAxis(transformedPos);

    /* Normalize so major axis component = ±1 (project onto cube face) */
    {
        float majorVal = transformedPos[majorAxis];
        /* abs via andps with sign mask — just use fabsf equivalent */
        if (majorVal < 0.0f) majorVal = -majorVal;
        invMajor = 1.0f / majorVal;
    }
    transformedPos[0] *= invMajor;
    transformedPos[1] *= invMajor;
    transformedPos[2] *= invMajor;

    /* Map [-1,1] → [0,1] */
    u = transformedPos[0] * 0.5f + 0.5f;
    v = transformedPos[1] * 0.5f + 0.5f;

    /* Third axis: subMap 0 uses -0.5*z, subMap 1 uses +0.5*z */
    if (subMap == 0)
        w = transformedPos[2] * -0.5f + 0.5f;
    else
        w = transformedPos[2] * 0.5f + 0.5f;

    /* Apply smoothstep for smooth blending */
    su = SmoothStep(u);
    sv = SmoothStep(v);
    sw = SmoothStep(w);

    /* Compute bilinear blend weights */
    w00 = (1.0f - sv) * sw * (1.0f - su); /* pixel[2] */
    w01 = su * sv * sw;                    /* pixel[3] */
    w10 = (1.0f - su) * sv * sw;          /* pixel[1] (not used directly) */
    w11 = (1.0f - su) * (1.0f - sv) * sw; /* pixel[0] (not used directly) */

    /* Actually the original computes:
     * weight0 = (1-su) * (1-sv) * sw   → pixel[2]
     * weight1 = su * (1-sv) * sw       → pixel[1] (stored as xmm3)
     * weight2 = (1-su) * sv * sw       → pixel[0]
     * weight3 = su * sv * sw           → pixel[3]
     */
    {
        float oneMinusSu = 1.0f - su;
        float oneMinusSv = 1.0f - sv;

        float blend_00 = oneMinusSu * oneMinusSv * sw; /* (1-su)*(1-sv)*sw */
        float blend_10 = su * oneMinusSv * sw;         /* su*(1-sv)*sw */
        float blend_01 = oneMinusSu * sv * sw;         /* (1-su)*sv*sw */
        float blend_11 = su * sv * sw;                 /* su*sv*sw */

        pixel[0] = ClampByte((int)floorf(blend_01 * 255.0f + 0.5f));
        pixel[1] = ClampByte((int)floorf(blend_10 * 255.0f + 0.5f));
        pixel[2] = ClampByte((int)floorf(blend_00 * 255.0f + 0.5f));
        pixel[3] = ClampByte((int)floorf(blend_11 * 255.0f + 0.5f));
    }
}

extern int FS_ReadFile(const char *path, void **buf);
extern void FS_FreeFile(void *buf);
extern void Com_Printf(const char *fmt, ...);
extern int Com_sprintf(char *dest, int size, const char *fmt, ...);

/* line 467 */
Bool Image_LoadFromFile(GfxImage *image)
{
    byte *img = (byte *)image;
    char filepath[64];
    void *imageFile;
    const byte *fileData;
    int fileLen;
    int result;

    /* Build filepath: "images/<name>.iwi" */
    result = Com_sprintf(filepath, 0x40, "%s%s%s", "images/", *(const char **)(img + 0x20), ".iwi");
    if (result < 0) {
        Com_Printf("^1ERROR: filename '%s' too long\n", filepath);
        return 0;
    }

    fileLen = FS_ReadFile(filepath, &imageFile);
    if (fileLen < 0) {
        Com_Printf("^1ERROR: image '%s' is missing\n", filepath);
        return 0;
    }
    if (fileLen == 0) {
        Com_Printf("^1ERROR: image '%s' has 0 length\n", filepath);
        FS_FreeFile(imageFile);
        return 0;
    }

    fileData = (const byte *)imageFile;

    /* Check for hasMips flag */
    if (fileData[5] & 3)
        img[0xb] = 1;

    /* Validate IWI magic: first 3 bytes == "IWi" (0x695749) */
    if ((*(int *)fileData & 0x00FFFFFF) != 0x695749) {
        Com_Printf("^1ERROR: image '%s' is not an IW image\n", filepath);
        FS_FreeFile(imageFile);
        return 0;
    }

    /* Check version (byte 3 must be 5) */
    if (fileData[3] != 5) {
        Com_Printf("^1ERROR: image '%s' is version %i but should be version %i\n",
                    filepath, (int)fileData[3], 5);
        FS_FreeFile(imageFile);
        return 0;
    }

    /* Load the image data (header at fileData, pixel data at fileData+0x1c) */
    Image_LoadFromData(image, (GfxImageFileHeader *)fileData, fileData + 0x1c);
    FS_FreeFile(imageFile);
    return 1;
}

#if 0 /* original naked — replaced above */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 467 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x70, %esp\n"
        "movl 8(%ebp), %esi\n" /* image */
        /* { scope 1 */
        "movl $str_00226a2c, 0x14(%esp)\n" /* line 479 */
        "movl 0x20(%esi), %eax\n" /* image */
        "movl %eax, 0x10(%esp)\n"
        "movl $str_00226a34, 0xc(%esp)\n" /* "images/" */
        "movl $str_00226a3c, 8(%esp)\n" /* "%s%s%s" */
        "movl $0x40, 4(%esp)\n"
        "leal -0x4c(%ebp), %ebx\n" /* filepath */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "testl %eax, %eax\n"
        "js .Lffd42c_000fd51d\n"
        "leal -0xc(%ebp), %eax\n" /* line 485 | imageFile */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FS_ReadFile\n"
        "cmpl $0, %eax\n" /* line 486 */
        "jl .Lffd42c_000fd536\n"
        "je .Lffd42c_000fd4cd\n" /* line 492 */
        "movl -0xc(%ebp), %edx\n" /* line 502 | imageFile */
        "leal 0x1c(%edx), %ecx\n"
        "testb $3, 5(%edx)\n" /* line 504 */
        "je .Lffd42c_000fd49b\n"
        "movb $1, 0xb(%esi)\n" /* line 505 | image */
        ".Lffd42c_000fd49b:\n"
        "movl (%edx), %eax\n" /* line 28 */
        "andl $0x00FFFFFF, %eax\n"
        "cmpl $0x695749, %eax\n"
        "je .Lffd42c_000fd4f1\n"
        "movl %ebx, 4(%esp)\n" /* line 30 */
        "movl $str_002269c8, (%esp)\n" /* "^1ERROR: image '%s' is not an IW image
" */
        "calll Com_Printf\n"
        "movl -0xc(%ebp), %edx\n" /* imageFile */
        ".Lffd42c_000fd4bc:\n"
        "movl %edx, (%esp)\n" /* line 509 */
        "calll FS_FreeFile\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lffd42c_000fd4c6:\n"
        "addl $0x70, %esp\n" /* line 518 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lffd42c_000fd4cd:\n"
        "movl %ebx, 4(%esp)\n" /* line 494 */
        "movl $str_00226a64, (%esp)\n" /* "^1ERROR: image '%s' has 0 length
" */
        "calll Com_Printf\n"
        "movl -0xc(%ebp), %eax\n" /* line 495 | imageFile */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x70, %esp\n" /* line 518 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lffd42c_000fd4f1:\n"
        "movzbl 3(%edx), %eax\n" /* line 34 */
        "cmpb $5, %al\n"
        "je .Lffd42c_000fd54d\n"
        "movl $5, 0xc(%esp)\n" /* line 36 */
        "movzbl %al, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $str_002269f0, (%esp)\n" /* "^1ERROR: image '%s' is version %i but should be version %i
" */
        "calll Com_Printf\n"
        "movl -0xc(%ebp), %edx\n" /* imageFile */
        "jmp .Lffd42c_000fd4bc\n"
        ".Lffd42c_000fd51d:\n"
        "movl %ebx, 4(%esp)\n" /* line 481 */
        "movl $str_0021fd24, (%esp)\n" /* "^1ERROR: filename '%s' too long
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x70, %esp\n" /* line 518 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lffd42c_000fd536:\n"
        "movl %ebx, 4(%esp)\n" /* line 488 */
        "movl $str_00226a44, (%esp)\n" /* "^1ERROR: image '%s' is missing
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        "jmp .Lffd42c_000fd4c6\n"
        ".Lffd42c_000fd54d:\n"
        "movl %ecx, 8(%esp)\n" /* line 513 */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* image */
        "calll Image_LoadFromData\n"
        "movl -0xc(%ebp), %eax\n" /* line 515 | imageFile */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        "movl $1, %eax\n"
        "jmp .Lffd42c_000fd4c6\n"
    );
}
#endif

/* line 1202 */
GfxImage * R_CreateWaterMap(char *name, int imageWidth, int imageHeight)
{
    GfxImage *image = Image_Alloc(name, 5, 5, 9);
    image->width = (unsigned short)imageWidth;
    image->height = (unsigned short)imageHeight;

    int *dvar = *(int **)imp_r_rendererInUse;
    if (*(int *)(dvar + 2) == 2)
        Image_Create2DTexture(image, image->width, imageHeight, 1, 0x200, 0x16, 0);
    else
        Image_Create2DTexture(image, image->width, imageHeight, 0, 0x200, 0x32, 0);

    return image;
}

/* line 856 */
/* line 856 — Generate a cubemap by calling a per-pixel callback for each face.
 * faceAxis[6][3] encodes normal/right/up axes: bit0=sign, bits1+=axisIndex.
 * For each face texel, computes world-space direction and calls the callback. */
static void Image_GenerateCubemapFunction(GfxImage *image, byte *pic, int res, int userData, CubemapPixelCallback Callback)
{
    CubemapPixelCallback cb = Callback;
    float invRes = 1.0f / (float)res;
    int pixelIndex = 0;
    int face;

    for (face = 0; face < 6; face++) {
        const int *axes = &faceAxis[face][0];
        vec_t faceOrigin[3] = {0, 0, 0};
        vec_t rightStep[3] = {0, 0, 0};
        vec_t upStep[3] = {0, 0, 0};
        int t, s;

        /* Normal axis: set face origin component */
        {
            int a = axes[0];
            int idx = a >> 1;
            faceOrigin[idx] = (a & 1) ? -1.0f : 1.0f;
        }

        /* Right axis: add to origin + set step vector */
        {
            int a = axes[1];
            int idx = a >> 1;
            if (a & 1) {
                faceOrigin[idx] += 1.0f;
                rightStep[idx] = -2.0f;
            } else {
                faceOrigin[idx] += -1.0f;
                rightStep[idx] = 2.0f;
            }
        }

        /* Up axis: add to origin + set step vector */
        {
            int a = axes[2];
            int idx = a >> 1;
            if (a & 1) {
                faceOrigin[idx] += 1.0f;
                upStep[idx] = -2.0f;
            } else {
                faceOrigin[idx] += -1.0f;
                upStep[idx] = 2.0f;
            }
        }

        /* Scale step vectors by 1/res */
        rightStep[0] *= invRes;  rightStep[1] *= invRes;  rightStep[2] *= invRes;
        upStep[0] *= invRes;     upStep[1] *= invRes;     upStep[2] *= invRes;

        /* Iterate over texels */
        for (t = 0; t < res; t++) {
            /* Start position for this row: origin + (0.5) * rightStep */
            vec_t facePos[3];
            facePos[0] = faceOrigin[0] + 0.5f * rightStep[0];
            facePos[1] = faceOrigin[1] + 0.5f * rightStep[1];
            facePos[2] = faceOrigin[2] + 0.5f * rightStep[2];

            /* Add (t + 0.5) * upStep */
            {
                float tScale = (float)t + 0.5f;
                facePos[0] += tScale * upStep[0];
                facePos[1] += tScale * upStep[1];
                facePos[2] += tScale * upStep[2];
            }

            for (s = 0; s < res; s++) {
                cb(facePos, userData, pic + pixelIndex * 4);
                pixelIndex++;

                /* Advance position by rightStep */
                facePos[0] += rightStep[0];
                facePos[1] += rightStep[1];
                facePos[2] += rightStep[2];
            }
        }
    }

    /* Setup as cubemap and upload each face */
    {
        int faceStride = res * res * 4;
        byte *faceData = pic;

        Image_Setup(image, res, res, 1, 7, 0, 0x15); /* D3DFMT_A8R8G8B8, cubemap */

        for (face = 0; face < 6; face++) {
            Image_UploadData(image, 0x15, Image_CubemapFace(face), 0, faceData);
            faceData += faceStride;
        }
    }
}

#if 0 /* original naked — replaced above */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 856 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        /* { scope 1 */
        "cvtsi2ssl 0x10(%ebp), %xmm0\n" /* line 884 | res */
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        "divss %xmm0, %xmm3\n"
        "xorl %edi, %edi\n" /* pixelIndex */
        "movl $faceAxis, -0x4c(%ebp)\n"
        ".Lffd64a_000fd670:\n"
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, -0x48(%ebp)\n" /* faceVecs */
        "movl %eax, -0x44(%ebp)\n" /* line 184 */
        "movl %eax, -0x40(%ebp)\n" /* line 185 */
        "movl -0x4c(%ebp), %edx\n" /* line 889 */
        "movl (%edx), %eax\n"
        "movl %eax, %edx\n"
        "sarl $1, %edx\n"
        "testb $1, %al\n" /* line 890 */
        "je .Lffd64a_000fd916\n"
        "movl $0xbf800000, %eax\n"
        ".Lffd64a_000fd691:\n"
        "movl %eax, -0x48(%ebp, %edx, 4)\n"
        "movl $0, -0x3c(%ebp)\n" /* line 183 */
        "movl $0, -0x38(%ebp)\n" /* line 184 */
        "movl $0, -0x34(%ebp)\n" /* line 185 */
        "movl -0x4c(%ebp), %edx\n" /* line 893 */
        "movl 4(%edx), %eax\n"
        "movl %eax, %edx\n"
        "sarl $1, %edx\n"
        "testb $1, %al\n" /* line 894 */
        "je .Lffd64a_000fd907\n"
        "movl $0x3f800000, %ecx\n"
        "movl $0xc0000000, %eax\n"
        ".Lffd64a_000fd6c6:\n"
        "movl %ecx, -0x48(%ebp, %edx, 4)\n"
        "movl %eax, -0x3c(%ebp, %edx, 4)\n" /* line 895 */
        "movl $0, -0x30(%ebp)\n" /* line 183 */
        "movl $0, -0x2c(%ebp)\n" /* line 184 */
        "movl $0, -0x28(%ebp)\n" /* line 185 */
        "movl -0x4c(%ebp), %edx\n" /* line 898 */
        "movl 8(%edx), %eax\n"
        "movl %eax, %edx\n"
        "sarl $1, %edx\n"
        "testb $1, %al\n" /* line 899 */
        "je .Lffd64a_000fd8f8\n"
        "movl $0x3f800000, %ecx\n"
        "movl $0xc0000000, %eax\n"
        ".Lffd64a_000fd6ff:\n"
        "movl %ecx, -0x48(%ebp, %edx, 4)\n"
        "movl %eax, -0x30(%ebp, %edx, 4)\n" /* line 900 */
        "movaps %xmm3, %xmm0\n" /* line 272 */
        "mulss -0x3c(%ebp), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "movaps %xmm3, %xmm0\n" /* line 273 */
        "mulss -0x38(%ebp), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "movaps %xmm3, %xmm0\n" /* line 274 */
        "mulss -0x34(%ebp), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "movaps %xmm3, %xmm0\n" /* line 272 */
        "mulss -0x30(%ebp), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "movaps %xmm3, %xmm0\n" /* line 273 */
        "mulss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movaps %xmm3, %xmm0\n" /* line 274 */
        "mulss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "movl 0x10(%ebp), %esi\n" /* line 905 | res, s */
        "testl %esi, %esi\n" /* s */
        "jle .Lffd64a_000fd85f\n"
        "movl $0, -0x50(%ebp)\n" /* t */
        "movss lit4_002ed5d8, %xmm2\n" /* 0.5f */
        ".Lffd64a_000fd76f:\n"
        "movss -0x3c(%ebp), %xmm0\n" /* line 288 */
        "mulss %xmm2, %xmm0\n"
        "addss -0x48(%ebp), %xmm0\n" /* faceVecs */
        "movss %xmm0, -0x24(%ebp)\n" /* facePos */
        "movss -0x38(%ebp), %xmm0\n" /* line 289 */
        "mulss %xmm2, %xmm0\n"
        "addss -0x44(%ebp), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss -0x34(%ebp), %xmm0\n" /* line 290 */
        "mulss %xmm2, %xmm0\n"
        "addss -0x40(%ebp), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "cvtsi2ssl -0x50(%ebp), %xmm1\n" /* line 908 | t, scale */
        "addss %xmm2, %xmm1\n" /* scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x30(%ebp), %xmm0\n"
        "addss -0x24(%ebp), %xmm0\n" /* facePos */
        "movss %xmm0, -0x24(%ebp)\n" /* facePos */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x2c(%ebp), %xmm0\n"
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "mulss -0x28(%ebp), %xmm1\n" /* line 290 */
        "addss -0x1c(%ebp), %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "movl 0xc(%ebp), %eax\n" /* pic */
        "leal (%eax, %edi, 4), %ebx\n"
        "xorl %esi, %esi\n"
        /* } scope */
        ".Lffd64a_000fd7ec:\n"
        "movl %ebx, 8(%esp)\n" /* line 911 */
        "movl 0x14(%ebp), %edx\n" /* userData */
        "movl %edx, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* facePos */
        "movl %eax, (%esp)\n"
        "movss %xmm2, -0x68(%ebp)\n"
        "movss %xmm3, -0x78(%ebp)\n"
        "calll *0x18(%ebp)\n" /* Callback */
        "addl $1, %edi\n" /* line 912 | pixelIndex */
        "movss -0x24(%ebp), %xmm0\n" /* line 240 | facePos */
        "addss -0x3c(%ebp), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* facePos */
        "movss -0x20(%ebp), %xmm0\n" /* line 241 */
        "addss -0x38(%ebp), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 242 */
        "addss -0x34(%ebp), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "addl $1, %esi\n" /* line 909 | s */
        "addl $4, %ebx\n"
        "cmpl %esi, 0x10(%ebp)\n" /* s, res */
        "movss -0x68(%ebp), %xmm2\n"
        "movss -0x78(%ebp), %xmm3\n"
        "jne .Lffd64a_000fd7ec\n"
        "addl $1, -0x50(%ebp)\n" /* line 905 | t */
        "movl -0x50(%ebp), %edx\n" /* t */
        "cmpl %edx, 0x10(%ebp)\n" /* res */
        "jne .Lffd64a_000fd76f\n"
        ".Lffd64a_000fd85f:\n"
        "addl $0xc, -0x4c(%ebp)\n"
        "cmpl $faceAxis+72, -0x4c(%ebp)\n" /* line 886 */
        "jne .Lffd64a_000fd670\n"
        "movl 0x10(%ebp), %eax\n" /* line 918 | res */
        "imull %eax, %eax\n"
        "leal (, %eax, 4), %edi\n" /* faceStride */
        /* { scope 2 */
        /* { scope 3 */
        "movl $0x15, 0x18(%esp)\n" /* line 647 */
        "movl $0, 0x14(%esp)\n"
        "movl $7, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* res */
        "movl %eax, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* image */
        "movl %edx, (%esp)\n"
        "calll Image_Setup\n"
        "xorl %esi, %esi\n" /* faceIndex */
        "movl 0xc(%ebp), %ebx\n" /* pic */
        ".Lffd64a_000fd8b8:\n"
        "movl %esi, (%esp)\n" /* line 651 | faceIndex */
        "calll Image_CubemapFace\n"
        "movl %ebx, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x15, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* image */
        "movl %eax, (%esp)\n"
        "calll Image_UploadData\n"
        "addl $1, %esi\n" /* line 650 | faceIndex */
        "addl %edi, %ebx\n"
        "cmpl $6, %esi\n" /* faceIndex */
        "jne .Lffd64a_000fd8b8\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0x8c, %esp\n" /* line 919 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lffd64a_000fd8f8:\n"
        "movl $0xbf800000, %ecx\n" /* line 899 */
        "movl $0x40000000, %eax\n"
        "jmp .Lffd64a_000fd6ff\n"
        ".Lffd64a_000fd907:\n"
        "movl $0xbf800000, %ecx\n" /* line 894 */
        "movl $0x40000000, %eax\n"
        "jmp .Lffd64a_000fd6c6\n"
        ".Lffd64a_000fd916:\n"
        "movl $0x3f800000, %eax\n" /* line 890 */
        "jmp .Lffd64a_000fd691\n"
    );
}
#endif

/* line 672 */
/* line 672 — Load a raw JPEG image file */
Bool Image_LoadRaw(GfxImage *image, const char *filepath, int imageTrack)
{
    byte *pic = NULL;
    void *file;
    int width, height, imageFormat;

    (void)imageTrack;

    R_LoadJpg(filepath, &file, &pic, &width, &height, &imageFormat);

    if (!pic)
        return 0;

    Image_Setup(image, width, height, 1, 3, 0, imageFormat);
    Image_UploadData(image, imageFormat, Image_CubemapFace(0), 0, pic);

    Hunk_FreeTempMemory(pic);
    FS_FreeFile(file);
    return 1;
}

/* line 771 — Image_LoadLightmapWeights
 * Generates a 32x32 procedural lightmap weights texture.
 * For each texel, computes direction on hemisphere, determines which cubemap faces
 * contribute via angular distance, and encodes blend weights as RGBA bytes.
 * The weight computation uses atan2 for face selection and acos for angular falloff. */
extern float acosf(float x);
extern float floorf(float x);
extern double atan2(double y, double x);
extern float Vec2Normalize(float *v);

static jpeg_alloc Image_LoadLightmapWeights(GfxImage *image)
{
    byte pic[32 * 32 * 4]; /* 32x32 RGBA */
    int t, s;

    for (t = 0; t < 32; t++) {
        float tv = ((float)t + 0.5f) * (1.0f / 32.0f) * 2.0f - 1.0f;

        for (s = 0; s < 32; s++) {
            float sv = ((float)s + 0.5f) * (1.0f / 32.0f) * 2.0f - 1.0f;

            /* Compute z^2 = 1 - sv^2 - tv^2 for hemisphere mapping */
            float zSq = 1.0f - sv * sv - tv * tv;
            float dir[2];
            dir[0] = sv;

            if (zSq < 0.0f) {
                /* Outside hemisphere: normalize 2D direction, set z=0 */
                Vec2Normalize(dir);
                zSq = 0.0f;
            }

            float z = __builtin_sqrtf(zSq);

            /* Convert (sv, tv) to face angle via atan2, scale to [0, 3) range */
            float angle = (float)(atan2((double)sv, (double)tv) * 0.477464829275686 - 0.75);

            /* Wrap angle to [0, 3) */
            if (angle < 0.0f)
                angle += 3.0f;
            if (angle > 3.0f)
                angle -= 3.0f;

            /* Determine face blending weights based on angle region */
            float w0, w1, w2; /* blend weights for 3 adjacent faces */

            if (angle < 1.0f) {
                /* Region 0-1: blend between face 0 and face 1 */
                w2 = 1.0f - angle;
                w1 = 0.0f;
                w0 = 0.0f; /* w0 = 0 (encoded below via separate path) */
            } else if (angle < 2.0f) {
                /* Region 1-2 */
                w1 = angle - 1.0f;
                w0 = 1.0f - w1;
                w2 = 0.0f;
            } else {
                /* Region 2-3 */
                w2 = angle - 2.0f;
                w0 = 1.0f - w2;
                w1 = 0.0f;
            }

            /* Compute angular falloff from hemisphere center */
            float falloff = acosf(z) / -0.9553166031837463f + 1.0f;
            float complement, mainWeight;

            if (falloff < 0.0f) {
                /* Full falloff: all weight goes to main channel */
                mainWeight = 1.0f;
                falloff = 0.0f;
            } else if (falloff > 1.0f) {
                /* No falloff contribution */
                complement = 0.0f;
                mainWeight = 255.0f * falloff; /* note: goes through floor path below */
                goto write_pixel;
            } else {
                complement = 1.0f - falloff;
                mainWeight = 255.0f * falloff;
            }

        write_pixel:;
            byte *pixel = &pic[(t * 32 + s) * 4];
            pixel[0] = (byte)(int)floorf(mainWeight + 0.5f);
            pixel[1] = (byte)(int)floorf(w2 * complement * 255.0f + 0.5f);
            pixel[2] = (byte)(int)floorf(w1 * complement * 255.0f + 0.5f);
            pixel[3] = (byte)(int)floorf(complement * w0 * 255.0f + 0.5f);
        }
    }

    /* Upload as 32x32 2D texture, format 0x15, 1 mip, depth 3 */
    Image_Setup(image, 32, 32, 1, 3, 0, 0x15);
    int face = Image_CubemapFace(0);
    Image_UploadData(image, 0x15, face, 0, pic);
}

/* line 1165 */
/* Helper: create a 1x1 solid-color image */
static GfxImage *Image_CreateSolidColor(const char *name, int semantic, int imageTrack,
                                         byte r, byte g, byte b, byte a)
{
    byte pic[4];
    GfxImage *image = Image_Alloc(name, 1, semantic, imageTrack);
    pic[0] = a; pic[1] = r; pic[2] = g; pic[3] = b;
    Image_Setup(image, 1, 1, 1, 3, 0, 0x15); /* D3DFMT_A8R8G8B8 */
    Image_UploadData(image, 0x15, Image_CubemapFace(0), 0, pic);
    return image;
}

/* line 1165 — Main image loading entry point. Handles both file-based images
 * and built-in procedural images (names starting with '$'). */
GfxImage * Image_Load(const char *name, int semantic, int imageTrack)
{
    GfxImage *image;

    /* Normal file-based image */
    if (name[0] != '$') {
        image = Image_Alloc(name, 3, (byte)semantic, imageTrack);
        if (!Image_LoadFromFile(image))
            return NULL;
        return image;
    }

    /* Built-in procedural images */
    if (!memcmp(name, "$white", 7)) {
        return Image_CreateSolidColor(name, (byte)semantic, imageTrack, 0xFF, 0xFF, 0xFF, 0xFF);
    }
    if (!memcmp(name, "$black", 7)) {
        return Image_CreateSolidColor(name, (byte)semantic, imageTrack, 0x00, 0x00, 0x00, 0xFF);
    }
    if (!memcmp(name, "$identitynormalmap", 19)) {
        /* Identity normal: (0x80, 0x80, 0xFF) with alpha 0x80 */
        return Image_CreateSolidColor(name, (byte)semantic, imageTrack, 0x80, 0x80, 0xFF, 0x80);
    }
    if (!memcmp(name, "$specularity", 13)) {
        byte pic[0x2000]; /* 32x256 specularity map buffer */
        image = Image_Alloc(name, 1, (byte)semantic, imageTrack);
        Image_BuildSpecularityMap(0, pic);
        Image_Setup(image, 0x20, 0x100, 1, 3, 0, 0x32);
        Image_UploadData(image, 0x32, Image_CubemapFace(0), 0, pic);
        return image;
    }
    if (!memcmp(name, "$outdoor", 9)) {
        image = Image_Alloc(name, 1, (byte)semantic, imageTrack);
        R_GenerateOutdoorImage(image);
        return image;
    }
    if (!memcmp(name, "$lightmapweights", 17)) {
        image = Image_Alloc(name, 1, (byte)semantic, imageTrack);
        Image_LoadLightmapWeights(image);
        return image;
    }
    if (!memcmp(name, "$lightgridweights0", 19)) {
        byte pic[0x6000]; /* 6 * 32 * 32 * 4 = 24576 bytes for cubemap */
        image = Image_Alloc(name, 1, (byte)semantic, imageTrack);
        Image_GenerateCubemapFunction(image, pic, 0x20, 0, (CubemapPixelCallback)Image_GetLightGridWeightsForVector);
        return image;
    }
    if (!memcmp(name, "$lightgridweights1", 19)) {
        byte pic[0x6000]; /* 6 * 32 * 32 * 4 = 24576 bytes for cubemap */
        image = Image_Alloc(name, 1, (byte)semantic, imageTrack);
        Image_GenerateCubemapFunction(image, pic, 0x20, 1, (CubemapPixelCallback)Image_GetLightGridWeightsForVector);
        return image;
    }
    if (!memcmp(name, "$watercolor", 12)) {
        byte pic[0x1800]; /* 6 * 16 * 16 * 4 = 6144 bytes for cubemap */
        int waterColor;
        image = Image_Alloc(name, 1, (byte)semantic, imageTrack);
        /* Build packed water color: ARGB = 0x4D004033FF (approx) */
        waterColor = 0;
        ((byte *)&waterColor)[0] = 0xFF;
        ((byte *)&waterColor)[1] = 0x33;
        ((byte *)&waterColor)[2] = 0x40;
        waterColor = (waterColor & 0x00FFFFFF) | 0x4D000000;
        Image_GenerateCubemapFunction(image, pic, 0x10, waterColor,
            (CubemapPixelCallback)Image_GetWaterColorForVector);
        return image;
    }
    if (!memcmp(name, "$sunhalfangle", 14)) {
        byte *pic;
        image = Image_Alloc(name, 1, (byte)semantic, imageTrack);
        pic = (byte *)Hunk_AllocateTempMemoryInternal(0x18000);
        Image_GenerateCubemapFunction(image, pic, 0x40, 0,
            (CubemapPixelCallback)Image_GetSunHalfAngleForVector);
        Hunk_FreeTempMemory(pic);
        return image;
    }

    Com_Printf("ERROR: Unknown built-in image '%s'", name);
    return NULL;
}

#if 0 /* original naked — replaced above */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1165 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x603c, %esp\n"
        "movl $0, -0x6020(%ebp)\n" /* color */
        "movzbl 0xc(%ebp), %eax\n" /* semantic */
        /* { scope 1: semantic */
        "movl 8(%ebp), %edx\n" /* line 1169 | name */
        "cmpb $0x24, (%edx)\n"
        "je .Lffddce_000fde31\n"
        "movl %edx, %ecx\n"
        "movl 0x10(%ebp), %edx\n" /* line 1172 | imageTrack */
        "movl %edx, 0xc(%esp)\n"
        "movzbl %al, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll Image_Alloc\n"
        "movl %eax, %esi\n" /* image */
        "movl %eax, (%esp)\n" /* line 1174 */
        "calll Image_LoadFromFile\n"
        "testb %al, %al\n"
        "movl $0, %eax\n"
        "cmovel %eax, %esi\n" /* image */
        /* } scope */
        ".Lffddce_000fde24:\n"
        "movl %esi, %eax\n" /* line 1177 | image */
        "addl $0x603c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: semantic */
        ".Lffddce_000fde31:\n"
        "movb %al, -0x6019(%ebp)\n" /* line 1169 | semantic */
        /* { scope 2: pic, color */
        "movl $str_00225570, %edi\n" /* line 1078 */
        "movl $7, %ebx\n"
        "cld\n"
        "movl %edx, %esi\n"
        "movl %ebx, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %edx\n"
        "je .Lffddce_000fde59\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lffddce_000fde59:\n"
        "testl %edx, %edx\n"
        "jne .Lffddce_000fdf1b\n"
        "movl 0x10(%ebp), %eax\n" /* line 1080 | imageTrack */
        "movl %eax, 0xc(%esp)\n"
        "movzbl -0x6019(%ebp), %eax\n" /* semantic */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* name */
        "movl %edx, (%esp)\n"
        "calll Image_Alloc\n"
        "movl %eax, %esi\n"
        /* { scope 3 */
        "movb $0xff, -0x6015(%ebp)\n" /* line 843 */
        "movb $0xff, -0x6016(%ebp)\n"
        "movb $0xff, -0x6017(%ebp)\n"
        /* } scope */
        /* { scope 3 */
        ".Lffddce_000fde9d:\n"
        "movb $0xff, -0x6018(%ebp)\n" /* pic */
        ".Lffddce_000fdea4:\n"
        "movl $0x15, 0x18(%esp)\n" /* line 570 */
        "movl $0, 0x14(%esp)\n"
        "movl $3, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Image_Setup\n"
        "movl $0, (%esp)\n" /* line 575 */
        "calll Image_CubemapFace\n"
        "leal -0x6018(%ebp), %edx\n" /* pic */
        "movl %edx, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x15, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Image_UploadData\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "movl %esi, %eax\n" /* line 1177 | image */
        "addl $0x603c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: semantic */
        /* { scope 2: pic, color */
        ".Lffddce_000fdf1b:\n"
        "movl $str_00225578, %edi\n" /* line 1086 */
        "movl $7, %ebx\n"
        "cld\n"
        "movl 8(%ebp), %esi\n" /* name */
        "movl %ebx, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %edx\n"
        "je .Lffddce_000fdf3e\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lffddce_000fdf3e:\n"
        "testl %edx, %edx\n"
        "jne .Lffddce_000fdf83\n"
        "movl 0x10(%ebp), %eax\n" /* line 1088 | imageTrack */
        "movl %eax, 0xc(%esp)\n"
        "movzbl -0x6019(%ebp), %eax\n" /* semantic */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* name */
        "movl %edx, (%esp)\n"
        "calll Image_Alloc\n"
        "movl %eax, %esi\n"
        /* { scope 3 */
        "movb $0, -0x6015(%ebp)\n" /* line 843 */
        "movb $0, -0x6016(%ebp)\n"
        "movb $0, -0x6017(%ebp)\n"
        "jmp .Lffddce_000fde9d\n"
        /* } scope */
        ".Lffddce_000fdf83:\n"
        "movl $str_0022558c, %edi\n" /* line 1094 */
        "movl $0x13, %ebx\n"
        "cld\n"
        "movl 8(%ebp), %esi\n" /* name */
        "movl %ebx, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %edx\n"
        "je .Lffddce_000fdfa6\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lffddce_000fdfa6:\n"
        "testl %edx, %edx\n"
        "je .Lffddce_000fe07f\n"
        "movl $str_002255a0, %edi\n" /* line 1102 */
        "movl $0xd, %ebx\n"
        "cld\n"
        "movl 8(%ebp), %esi\n" /* name */
        "movl %ebx, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %edx\n"
        "je .Lffddce_000fdfd1\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lffddce_000fdfd1:\n"
        "testl %edx, %edx\n"
        "jne .Lffddce_000fe0c7\n"
        "movl 0x10(%ebp), %eax\n" /* line 1104 | imageTrack */
        "movl %eax, 0xc(%esp)\n"
        "movzbl -0x6019(%ebp), %eax\n" /* semantic */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* name */
        "movl %edx, (%esp)\n"
        "calll Image_Alloc\n"
        "movl %eax, %esi\n"
        /* { scope 3 */
        "leal -0x6018(%ebp), %ebx\n" /* line 707 | pic */
        "movl %ebx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Image_BuildSpecularityMap\n"
        "movl $0x32, 0x18(%esp)\n" /* line 570 */
        "movl $0, 0x14(%esp)\n"
        "movl $3, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl $0x100, 8(%esp)\n"
        "movl $0x20, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Image_Setup\n"
        "movl $0, (%esp)\n" /* line 575 */
        "calll Image_CubemapFace\n"
        "movl %ebx, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x32, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Image_UploadData\n"
        "jmp .Lffddce_000fde24\n"
        /* } scope */
        ".Lffddce_000fe07f:\n"
        "movl 0x10(%ebp), %eax\n" /* line 1096 | imageTrack */
        "movl %eax, 0xc(%esp)\n"
        "movzbl -0x6019(%ebp), %eax\n" /* semantic */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* name */
        "movl %edx, (%esp)\n"
        "calll Image_Alloc\n"
        "movl %eax, %esi\n"
        /* { scope 3 */
        "movb $0xff, -0x6015(%ebp)\n" /* line 843 */
        "movb $0x80, -0x6016(%ebp)\n"
        "movb $0x80, -0x6017(%ebp)\n"
        "movb $0x80, -0x6018(%ebp)\n" /* pic */
        "jmp .Lffddce_000fdea4\n"
        /* } scope */
        ".Lffddce_000fe0c7:\n"
        "movl $str_00226a88, %edi\n" /* line 1110 */
        "movl $9, %ebx\n"
        "cld\n"
        "movl 8(%ebp), %esi\n" /* name */
        "movl %ebx, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %edx\n"
        "je .Lffddce_000fe0ea\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lffddce_000fe0ea:\n"
        "testl %edx, %edx\n"
        "jne .Lffddce_000fe122\n"
        "movl 0x10(%ebp), %eax\n" /* line 1112 | imageTrack */
        "movl %eax, 0xc(%esp)\n"
        "movzbl -0x6019(%ebp), %eax\n" /* semantic */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* name */
        "movl %edx, (%esp)\n"
        "calll Image_Alloc\n"
        "movl %eax, %esi\n"
        "movl %eax, (%esp)\n" /* line 1114 */
        "calll R_GenerateOutdoorImage\n"
        "jmp .Lffddce_000fde24\n"
        ".Lffddce_000fe122:\n"
        "movl $str_002255d8, %edi\n" /* line 1118 */
        "movl $0x11, %ebx\n"
        "cld\n"
        "movl 8(%ebp), %esi\n" /* name */
        "movl %ebx, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %edx\n"
        "je .Lffddce_000fe145\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lffddce_000fe145:\n"
        "testl %edx, %edx\n"
        "jne .Lffddce_000fe17d\n"
        "movl 0x10(%ebp), %eax\n" /* line 1120 | imageTrack */
        "movl %eax, 0xc(%esp)\n"
        "movzbl -0x6019(%ebp), %eax\n" /* semantic */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* name */
        "movl %edx, (%esp)\n"
        "calll Image_Alloc\n"
        "movl %eax, %esi\n"
        "movl %eax, (%esp)\n" /* line 1122 */
        "calll Image_LoadLightmapWeights\n"
        "jmp .Lffddce_000fde24\n"
        ".Lffddce_000fe17d:\n"
        "movl $str_002255b0, %edi\n" /* line 1126 */
        "movl $0x13, %ebx\n"
        "cld\n"
        "movl 8(%ebp), %esi\n" /* name */
        "movl %ebx, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %edx\n"
        "je .Lffddce_000fe1a0\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lffddce_000fe1a0:\n"
        "testl %edx, %edx\n"
        "jne .Lffddce_000fe1fa\n"
        "movl 0x10(%ebp), %eax\n" /* line 1128 | imageTrack */
        "movl %eax, 0xc(%esp)\n"
        "movzbl -0x6019(%ebp), %eax\n" /* semantic */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* name */
        "movl %edx, (%esp)\n"
        "calll Image_Alloc\n"
        "movl %eax, %esi\n"
        /* { scope 3 */
        "movl $Image_GetLightGridWeightsForVector, 0x10(%esp)\n" /* line 976 */
        "movl $0, 0xc(%esp)\n"
        /* } scope */
        /* { scope 3 */
        ".Lffddce_000fe1db:\n"
        "movl $0x20, 8(%esp)\n"
        "leal -0x6018(%ebp), %eax\n" /* pic */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Image_GenerateCubemapFunction\n"
        "jmp .Lffddce_000fde24\n"
        /* } scope */
        ".Lffddce_000fe1fa:\n"
        "movl $str_002255c4, %edi\n" /* line 1134 */
        "movl $0x13, %ebx\n"
        "cld\n"
        "movl 8(%ebp), %esi\n" /* name */
        "movl %ebx, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %edx\n"
        "je .Lffddce_000fe21d\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lffddce_000fe21d:\n"
        "testl %edx, %edx\n"
        "jne .Lffddce_000fe25a\n"
        "movl 0x10(%ebp), %eax\n" /* line 1136 | imageTrack */
        "movl %eax, 0xc(%esp)\n"
        "movzbl -0x6019(%ebp), %eax\n" /* semantic */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* name */
        "movl %edx, (%esp)\n"
        "calll Image_Alloc\n"
        "movl %eax, %esi\n"
        /* { scope 3 */
        "movl $Image_GetLightGridWeightsForVector, 0x10(%esp)\n" /* line 976 */
        "movl $1, 0xc(%esp)\n"
        "jmp .Lffddce_000fe1db\n"
        /* } scope */
        ".Lffddce_000fe25a:\n"
        "movl $str_00225580, %edi\n" /* line 1143 */
        "movl $0xc, %ebx\n"
        "cld\n"
        "movl 8(%ebp), %esi\n" /* name */
        "movl %ebx, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %edx\n"
        "je .Lffddce_000fe27d\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lffddce_000fe27d:\n"
        "testl %edx, %edx\n"
        "jne .Lffddce_000fe300\n"
        "movl 0x10(%ebp), %eax\n" /* line 1145 | imageTrack */
        "movl %eax, 0xc(%esp)\n"
        "movzbl -0x6019(%ebp), %eax\n" /* semantic */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* name */
        "movl %edx, (%esp)\n"
        "calll Image_Alloc\n"
        "movl %eax, %esi\n"
        /* { scope 3 */
        "movb $0xff, -0x6020(%ebp)\n" /* line 1061 | color */
        "movl -0x6020(%ebp), %ecx\n" /* color */
        "movb $0x33, %ch\n"
        "andl $0xff00ffff, %ecx\n"
        "orl $0x00400000, %ecx\n"
        "andl $0x00FFFFFF, %ecx\n"
        "movl %ecx, -0x6020(%ebp)\n" /* color */
        "orl $0x4d000000, %ecx\n"
        "movl $Image_GetWaterColorForVector, 0x10(%esp)\n" /* line 1069 */
        "movl %ecx, 0xc(%esp)\n"
        "movl $0x10, 8(%esp)\n"
        "leal -0x6018(%ebp), %eax\n" /* pic */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Image_GenerateCubemapFunction\n"
        "jmp .Lffddce_000fde24\n"
        /* } scope */
        ".Lffddce_000fe300:\n"
        "movl $str_00224af8, %edi\n" /* line 1151 */
        "movl $0xe, %ebx\n"
        "cld\n"
        "movl 8(%ebp), %esi\n" /* name */
        "movl %ebx, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %edx\n"
        "je .Lffddce_000fe323\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lffddce_000fe323:\n"
        "testl %edx, %edx\n"
        "jne .Lffddce_000fe38d\n"
        "movl 0x10(%ebp), %eax\n" /* line 1153 | imageTrack */
        "movl %eax, 0xc(%esp)\n"
        "movzbl -0x6019(%ebp), %eax\n" /* semantic */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* name */
        "movl %edx, (%esp)\n"
        "calll Image_Alloc\n"
        "movl %eax, %esi\n"
        "movl $0x18000, (%esp)\n" /* line 1020 */
        "calll Hunk_AllocateTempMemoryInternal\n"
        "movl %eax, %ebx\n"
        "movl $Image_GetSunHalfAngleForVector, 0x10(%esp)\n" /* line 1021 */
        "movl $0, 0xc(%esp)\n"
        "movl $0x40, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Image_GenerateCubemapFunction\n"
        "movl %ebx, (%esp)\n" /* line 1022 */
        "calll Hunk_FreeTempMemory\n"
        "jmp .Lffddce_000fde24\n"
        ".Lffddce_000fe38d:\n"
        "movl 8(%ebp), %ecx\n" /* line 1160 | name */
        "movl %ecx, 4(%esp)\n"
        "movl $str_00226a94, (%esp)\n" /* "ERROR: Unknown built-in image '%s'" */
        "calll Com_Printf\n"
        "xorl %esi, %esi\n"
        "jmp .Lffddce_000fde24\n"
    );
}
#endif
