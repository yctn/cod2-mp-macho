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
        Image_Create2DTexture(image, image->width, image->height, 1, 0x200, 0x16, 0);
    } else {
        Image_Create2DTexture(image, image->width, image->height, 0, 0x200, 0x32, 0);
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
    Image_Setup(image, fileHeader->dimensions[0], fileHeader->dimensions[1], fileHeader->dimensions[2],
                fileHeader->flags, 0, format);

    /* Cubemap: 6 faces if image type == 5, else 1 */
    faceCount = (image->mapType == 5) ? 6 : 1;

    /* Allocate temp buffer for BGR→ARGB expansion if needed */
    if (format == 0x16) { /* D3DFMT_A8R8G8B8 */
        int pixelCount = image->width * image->height;
        expandedData = (byte *)Hunk_AllocateTempMemoryInternal(pixelCount * 4);
    }

    /* Compute max mip level */
    if (fileHeader->flags & 2) {
        mipLevel = 0; /* hasMips flag set: start from 0 */
    } else {
        mipLevel = Image_ComputeMipCount(fileHeader->dimensions[0], fileHeader->dimensions[1], fileHeader->dimensions[2]);
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
                        dst[0] = src[0];   /* B */
                        dst[1] = src[1];   /* G */
                        dst[2] = src[2];   /* R */
                        dst[3] = 0xFF;     /* alpha */
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

/* Clean C version for WASM — no register calling convention */
static jpeg_alloc Image_LoadBitmap(GfxImage *image, const GfxImageFileHeader *fileHeader, const byte *data, D3DFORMAT format, int bytesPerPixel)
{
    Image_LoadBitmap_impl(image, fileHeader, data, format, bytesPerPixel);
}


/* line 245 */
/* line 245 */
static jpeg_alloc Image_LoadDxtc_impl(GfxImage *image, const GfxImageFileHeader *fileHeader, const byte *data, D3DFORMAT format, int bytesPerBlock)
{
    byte *img = (byte *)image;
    const byte *hdr = (const byte *)fileHeader;
    int faceCount, mipLevel;
    const byte *srcPtr = data;

    Image_Setup(image, fileHeader->dimensions[0], fileHeader->dimensions[1], fileHeader->dimensions[2],
                fileHeader->flags, 0, format);

    faceCount = (image->mapType == 5) ? 6 : 1;

    if (fileHeader->flags & 2)
        mipLevel = 0;
    else
        mipLevel = Image_ComputeMipCount(fileHeader->dimensions[0], fileHeader->dimensions[1], fileHeader->dimensions[2]);

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

/* Clean C version for WASM — no register calling convention */
static jpeg_alloc Image_LoadDxtc(GfxImage *image, const GfxImageFileHeader *fileHeader, const byte *data, D3DFORMAT format, int bytesPerBlock)
{
    Image_LoadDxtc_impl(image, fileHeader, data, format, bytesPerBlock);
}

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

/* Clean C version for WASM — no register calling convention */
static jpeg_alloc Image_LoadWavelet(GfxImage *image, const byte *fileHeader, const byte *data, D3DFORMAT format, int bytesPerPixel)
{
    Image_LoadWavelet_impl(image, fileHeader, data, format, bytesPerPixel);
}


/* line 320 */
/* Helper: call naked Image_LoadWavelet with register calling convention */
static void Image_LoadWavelet_call(GfxImage *image, const void *fileHeader, const byte *data, int format, int bytesPerPixel)
{
    Image_LoadWavelet_impl(image, (const byte *)fileHeader, data, format, bytesPerPixel);
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

    {
        GfxWorld *world = ((r_global_permanent_t *)imp_rgp)->world;
        sunDir = world->sunLight.position;
    }

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
    result = Com_sprintf(filepath, 0x40, "%s%s%s", "images/", image->name, ".iwi");
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
    Image_LoadFromData(image, (GfxImageFileHeader *)fileData, fileData + sizeof(GfxImageFileHeader));
    FS_FreeFile(imageFile);
    return 1;
}


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

