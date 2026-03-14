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
extern const char * g_imageProgNames[12]; /* g_imageProgNames */
extern const char * imageTypeName[10]; /* imageTypeName */

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
void ZSt13__adjust_heapIPP8GfxImageiS1_PFiS1_S1_EEvT_T0_S6_T1_T2_(void); /* void std___adjust_heap<GfxImage**, int, GfxImage*, int (*)(GfxImage*, GfxImage*)> */
void ZSt16__insertion_sortIPP8GfxImagePFiS1_S1_EEvT_S5_T0_(void); /* void std___insertion_sort<GfxImage**, int (*)(GfxImage*, GfxImage*)> */
void ZSt16__introsort_loopIPP8GfxImageiPFiS1_S1_EEvT_S5_T0_T1_(void); /* void std___introsort_loop<GfxImage**, int, int (*)(GfxImage*, GfxImage*)> */

/* line 183 */
static void R_AddImageToList(union XAssetHeader header, void *data)
{
    int *list = (int *)data;
    int count = list[0];
    *(int *)((byte *)data + 4 + count * 4) = (int)header.data;
    list[0] = count + 1;
}

/* line 194 */
void R_GetImageList(ImageList *imageList)
{
    *(int *)imageList = 0;
    DB_EnumXAssets(3, R_AddImageToList, imageList, 1);
}

/* line 255 */
int R_GetMinSpecImageMemory(void)
{
    return *(int *)((char *)&imageGlobals + 8208);
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

    *(unsigned short *)(img + 0x18) = (unsigned short)width;
    *(unsigned short *)(img + 0x1a) = (unsigned short)height;
    *(unsigned short *)(img + 0x1c) = 1;
    *(int *)img = 3; /* texture type = 2D */

    /* IDirect3DDevice9::CreateTexture — vtable 0x5C */
    device = *(void **)((char *)imp_dx + 8);
    vtable = *(void ***)device;
    hr = ((HRESULT (*)(void *, UINT, UINT, UINT, DWORD, DWORD, DWORD, void **, void *))(vtable[0x5C / 4]))(
        device, (unsigned short)width, (unsigned short)height,
        mipmapCount, usage, imageFormat, memPool, (void **)(img + 4), NULL);

    if (hr < 0) {
        R_Error(1, "Create2DTexture( %s, %i, %i, %i, %i ) failed: %08x = %s",
            *(const char **)(img + 0x20),
            (int)*(unsigned short *)(img + 0x18),
            (int)*(unsigned short *)(img + 0x1a),
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

    *(unsigned short *)(img + 0x18) = (unsigned short)width;
    *(unsigned short *)(img + 0x1a) = (unsigned short)height;
    *(unsigned short *)(img + 0x1c) = (unsigned short)depth;
    *(int *)img = 4; /* texture type = 3D/volume */

    /* IDirect3DDevice9::CreateVolumeTexture — vtable 0x60 */
    device = *(void **)((char *)imp_dx + 8);
    vtable = *(void ***)device;
    hr = ((HRESULT (*)(void *, UINT, UINT, UINT, UINT, DWORD, DWORD, DWORD, void **, void *))(vtable[0x60 / 4]))(
        device, (unsigned short)width, (unsigned short)height, (unsigned short)depth,
        mipmapCount, usage, imageFormat, memPool, (void **)(img + 4), NULL);

    if (hr < 0) {
        R_Error(1, "Create3DTexture( %s, %i, %i, %i, %i, %i ) failed: %08x = %s",
            *(const char **)(img + 0x20),
            (int)*(unsigned short *)(img + 0x18),
            (int)*(unsigned short *)(img + 0x1a),
            (int)*(unsigned short *)(img + 0x1c),
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

    *(unsigned short *)(img + 0x18) = (unsigned short)edgeLen;
    *(unsigned short *)(img + 0x1a) = (unsigned short)edgeLen;
    *(unsigned short *)(img + 0x1c) = 1;
    *(int *)img = 5; /* texture type = cube */

    /* Check if cubemap mipmaps are supported */
    dx = (byte *)imp_dx;
    if (dx[0x2d7b])
        actualMipCount = mipmapCount;
    else
        actualMipCount = 1;

    /* IDirect3DDevice9::CreateCubeTexture — vtable 0x64 */
    device = *(void **)(dx + 8);
    vtable = *(void ***)device;
    hr = ((HRESULT (*)(void *, UINT, UINT, DWORD, DWORD, DWORD, void **, void *))(vtable[0x64 / 4]))(
        device, (unsigned short)edgeLen, actualMipCount, 0, imageFormat, memPool,
        (void **)(img + 4), NULL);

    if (hr < 0) {
        R_Error(1, "CreateCubeTexture ( %s, %i, %i, %i ) failed: %08x = %s",
            *(const char **)(img + 0x20),
            (int)*(unsigned short *)(img + 0x18),
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
        texture = *(void **)((char *)image + 4);
        vtable = *(void ***)texture;
        ((HRESULT (*)(void *, UINT, IDirect3DSurface9 **))(vtable[0x48 / 4]))(texture, 0, &surface);
    } while (*(volatile int *)imp_alwaysfails);

    return surface;
}

/* line 1130 */
__attribute__((naked))
void R_SetPicmip(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1130 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "calll R_AvailableTextureMemory\n" /* line 1139 */
        "movl %eax, %edi\n" /* texMemInMegs */
        "movl imp_ri, %ebx\n" /* line 1140 */
        "movl $str_00222ab4, (%esp)\n" /* "sys_sysMB" */
        "calll *0xe0(%ebx)\n"
        "movl %eax, %esi\n" /* sysMemInMegs */
        "movl imp_r_picmip_manual, %eax\n" /* line 1143 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfe75e4_000e779f\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 1151 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfe75e4_000e773c\n"
        "movl $str_00225308, 4(%esp)\n" /* line 1184 */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        "movl $2, imageGlobals+8192\n" /* line 1225 */
        "movl $2, imageGlobals+8196\n" /* line 1226 */
        "movl $2, imageGlobals+8200\n" /* line 1227 */
        "cmpl $0x17f, %esi\n" /* line 1230 | sysMemInMegs */
        "ja .Lfe75e4_000e77f6\n"
        "movl $2, %eax\n"
        "cmpl %eax, imageGlobals+8192\n" /* line 1239 */
        "jl .Lfe75e4_000e7790\n"
        ".Lfe75e4_000e7677:\n"
        "xorl %edx, %edx\n"
        ".Lfe75e4_000e7679:\n"
        "cmpl %eax, imageGlobals+8196\n" /* line 1244 */
        "jge .Lfe75e4_000e768b\n"
        "movl %eax, imageGlobals+8196\n" /* line 1246 */
        "movl $1, %edx\n"
        ".Lfe75e4_000e768b:\n"
        "cmpl %eax, imageGlobals+8200\n" /* line 1249 */
        "jge .Lfe75e4_000e77e3\n"
        "movl %eax, imageGlobals+8200\n" /* line 1251 */
        ".Lfe75e4_000e769c:\n"
        "movl %esi, 8(%esp)\n" /* line 1255 | sysMemInMegs */
        "movl $str_00225330, 4(%esp)\n" /* "Reducing texture detail based on total system memory of %i M" */
        "movl $0, (%esp)\n"
        "movl imp_ri, %eax\n"
        "calll *(%eax)\n"
        "movl imp_r_picmip, %edx\n"
        ".Lfe75e4_000e76bc:\n"
        "movl imp_ri, %ebx\n" /* line 1258 */
        "movl imageGlobals+8192, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x98(%ebx)\n"
        "movl imageGlobals+8196, %eax\n" /* line 1259 */
        "movl %eax, 4(%esp)\n"
        "movl imp_r_picmip_bump, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x98(%ebx)\n"
        "movl imageGlobals+8200, %eax\n" /* line 1260 */
        "movl %eax, 4(%esp)\n"
        "movl imp_r_picmip_spec, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x98(%ebx)\n"
        "movl imageGlobals+8200, %eax\n" /* line 1262 */
        "movl %eax, 0x10(%esp)\n"
        "movl imageGlobals+8196, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl imageGlobals+8192, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_00225388, 4(%esp)\n" /* "Using picmip %i on most textures, %i on normal maps, and %i " */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1268 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe75e4_000e773c:\n"
        "movl $str_002252d4, 4(%esp)\n" /* line 1153 */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        "cmpl $0x80, %edi\n" /* line 1163 | texMemInMegs */
        "jbe .Lfe75e4_000e7808\n"
        "movl $1, imageGlobals+8192\n" /* line 1166 */
        "movl $1, imageGlobals+8196\n" /* line 1167 */
        "movl $1, imageGlobals+8200\n" /* line 1168 */
        ".Lfe75e4_000e7777:\n"
        "cmpl $0x17f, %esi\n" /* line 1176 | sysMemInMegs */
        "ja .Lfe75e4_000e77eb\n"
        "movl $1, %eax\n" /* line 1268 */
        ".Lfe75e4_000e7784:\n"
        "cmpl %eax, imageGlobals+8192\n" /* line 1239 */
        "jge .Lfe75e4_000e7677\n"
        ".Lfe75e4_000e7790:\n"
        "movl %eax, imageGlobals+8192\n" /* line 1241 */
        "movl $1, %edx\n"
        "jmp .Lfe75e4_000e7679\n"
        ".Lfe75e4_000e779f:\n"
        "movl $str_002252b8, 4(%esp)\n" /* line 1145 */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        "movl imp_r_picmip, %edx\n" /* line 1146 */
        "movl (%edx), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, imageGlobals+8192\n"
        "movl imp_r_picmip_bump, %eax\n" /* line 1147 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, imageGlobals+8196\n"
        "movl imp_r_picmip_spec, %eax\n" /* line 1148 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, imageGlobals+8200\n"
        "jmp .Lfe75e4_000e76bc\n"
        ".Lfe75e4_000e77e3:\n"
        "testb %dl, %dl\n" /* line 1254 */
        "jne .Lfe75e4_000e769c\n"
        ".Lfe75e4_000e77eb:\n"
        "movl imp_r_picmip, %edx\n"
        "jmp .Lfe75e4_000e76bc\n"
        ".Lfe75e4_000e77f6:\n"
        "cmpl $0x1df, %esi\n" /* line 1232 | sysMemInMegs */
        "ja .Lfe75e4_000e77eb\n"
        "movl $1, %eax\n" /* line 1268 */
        "jmp .Lfe75e4_000e7784\n"
        ".Lfe75e4_000e7808:\n"
        "movl $2, imageGlobals+8192\n" /* line 1172 */
        "movl $2, imageGlobals+8196\n" /* line 1173 */
        "movl $2, imageGlobals+8200\n" /* line 1174 */
        "jmp .Lfe75e4_000e7777\n"
    );
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
__attribute__((naked))
water_t * R_LoadWaterSetup(const water_t *water)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1507 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl imp_rg, %edi\n" /* line 1524 */
        "movl 0x1028(%edi), %edx\n"
        "testl %edx, %edx\n"
        "jg .Lfe785a_000e78a9\n"
        "xorl %ebx, %ebx\n" /* line 1533 | waterMapSetupIndex */
        ".Lfe785a_000e7875:\n"
        "movl %ebx, %eax\n" /* line 1536 | waterMapSetupIndex */
        "shll $6, %eax\n"
        "leal 0x1020(%eax, %ebx, 4), %eax\n"
        "leal 0xc(%eax, %edi), %esi\n"
        "movl %esi, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* waterMapSetupIndex */
        "movl 8(%ebp), %eax\n" /* water */
        "movl %eax, (%esp)\n"
        "calll R_CreateWaterSetup\n"
        "addl $1, 0x1028(%edi)\n" /* line 1538 */
        /* } scope */
        ".Lfe785a_000e789f:\n"
        "movl %esi, %eax\n" /* line 1541 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe785a_000e78a9:\n"
        "xorl %ebx, %ebx\n" /* line 1524 | waterMapSetupIndex */
        "jmp .Lfe785a_000e78b3\n"
        ".Lfe785a_000e78ad:\n"
        "movl imp_rg, %edi\n"
        ".Lfe785a_000e78b3:\n"
        "movl 8(%ebp), %eax\n" /* line 1526 | water */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, %eax\n" /* waterMapSetupIndex */
        "shll $6, %eax\n"
        "leal 0x1020(%eax, %ebx, 4), %eax\n"
        "leal 0xc(%eax, %edi), %esi\n"
        "movl %esi, (%esp)\n"
        "calll R_WatersEquivalent\n"
        "testl %eax, %eax\n"
        "jne .Lfe785a_000e789f\n"
        "addl $1, %ebx\n" /* line 1524 | waterMapSetupIndex */
        "cmpl 0x1028(%edi), %ebx\n" /* waterMapSetupIndex */
        "jl .Lfe785a_000e78ad\n"
        "cmpl $0x10, %ebx\n" /* line 1530 | waterMapSetupIndex */
        "je .Lfe785a_000e78ee\n"
        "movl imp_rg, %edi\n"
        "jmp .Lfe785a_000e7875\n"
        ".Lfe785a_000e78ee:\n"
        "movl $0x10, 4(%esp)\n" /* line 1532 */
        "movl $str_002253d8, (%esp)\n" /* "^1ERROR: map uses more than %i waterMap textures
" */
        "calll Com_Printf\n"
        "xorl %esi, %esi\n"
        "jmp .Lfe785a_000e789f\n"
    );
}

/* line 1566 */
__attribute__((naked))
void R_DownsampleMipMapBilinear(const byte *src, int srcBufferSize, int srcWidth, int srcHeight, int texelPitch, byte *dst, int dstBufferSize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1566 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        "movl 0x10(%ebp), %eax\n" /* srcWidth */
        /* { scope 1 */
        "cmpl $1, %eax\n" /* line 1587 */
        "je .Lfe7906_000e7a6d\n"
        ".Lfe7906_000e791b:\n"
        "movl %eax, %edx\n" /* line 1592 */
        "sarl $1, %edx\n"
        "movl %edx, -0x34(%ebp)\n" /* dstWidth */
        "movl 0x14(%ebp), %edi\n" /* line 1593 | srcHeight */
        "sarl $1, %edi\n"
        "movl %edi, -0x30(%ebp)\n" /* dstHeight */
        "imull 0x18(%ebp), %eax\n" /* line 1594 | texelPitch */
        "movl %eax, -0x24(%ebp)\n" /* srcRowPitch */
        "imull 0x18(%ebp), %edx\n" /* line 1595 | texelPitch */
        "movl %edx, -0x20(%ebp)\n" /* dstRowPitch */
        "movl -0x34(%ebp), %eax\n" /* line 1597 | dstWidth */
        "testl %eax, %eax\n"
        "je .Lfe7906_000e7a04\n"
        "cmpl $0, %edi\n"
        "je .Lfe7906_000e7a04\n"
        "jle .Lfe7906_000e79fc\n" /* line 1613 */
        "movl 0x18(%ebp), %eax\n" /* line 1624 | texelPitch */
        "addl %eax, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl $0, -0x2c(%ebp)\n" /* rowIndex */
        ".Lfe7906_000e7961:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 1615 | rowIndex */
        "imull -0x24(%ebp), %eax\n" /* srcRowPitch */
        "movl 8(%ebp), %edx\n" /* src */
        "leal (%edx, %eax, 2), %edi\n"
        "movl -0x2c(%ebp), %eax\n" /* line 1616 | rowIndex */
        "imull -0x20(%ebp), %eax\n" /* dstRowPitch */
        "addl 0x1c(%ebp), %eax\n" /* dst */
        "movl %eax, -0x10(%ebp)\n"
        "movl -0x34(%ebp), %ebx\n" /* line 1618 | dstWidth, channelIndex */
        "testl %ebx, %ebx\n" /* channelIndex */
        "jle .Lfe7906_000e79ec\n"
        "movl $0, -0x14(%ebp)\n"
        ".Lfe7906_000e7989:\n"
        "movl 0x18(%ebp), %ecx\n" /* line 1620 | texelPitch */
        "testl %ecx, %ecx\n"
        "jle .Lfe7906_000e79d7\n"
        "movl 0x18(%ebp), %eax\n" /* texelPitch */
        "addl -0x24(%ebp), %eax\n" /* srcRowPitch */
        "leal (%edi, %eax), %esi\n" /* dstPos */
        "xorl %ebx, %ebx\n" /* channelIndex */
        ".Lfe7906_000e799b:\n"
        "movzbl (%edi, %ebx), %eax\n" /* line 1621 */
        "movl %eax, -0x40(%ebp)\n"
        "leal (%edi, %ebx), %ecx\n"
        "movl 0x18(%ebp), %eax\n" /* texelPitch */
        "movzbl (%ecx, %eax), %edx\n"
        "addl -0x40(%ebp), %edx\n"
        "movl %edx, -0x40(%ebp)\n"
        "movl -0x24(%ebp), %eax\n" /* srcRowPitch */
        "movzbl (%ecx, %eax), %edx\n"
        "movl -0x40(%ebp), %eax\n"
        "addl %edx, %eax\n"
        "movzbl (%esi), %edx\n" /* dstPos */
        "addl %edx, %eax\n"
        "sarl $2, %eax\n"
        "movl -0x10(%ebp), %edx\n"
        "movb %al, (%edx, %ebx)\n"
        "addl $1, %ebx\n" /* line 1620 | channelIndex */
        "addl $1, %esi\n" /* dstPos */
        "cmpl %ebx, 0x18(%ebp)\n" /* channelIndex, texelPitch */
        "jne .Lfe7906_000e799b\n"
        ".Lfe7906_000e79d7:\n"
        "movl 0x18(%ebp), %eax\n" /* line 1623 | texelPitch */
        "addl %eax, -0x10(%ebp)\n"
        "addl -0x1c(%ebp), %edi\n" /* line 1624 */
        "addl $1, -0x14(%ebp)\n" /* line 1618 */
        "movl -0x14(%ebp), %edx\n"
        "cmpl %edx, -0x34(%ebp)\n" /* dstWidth */
        "jne .Lfe7906_000e7989\n"
        ".Lfe7906_000e79ec:\n"
        "addl $1, -0x2c(%ebp)\n" /* line 1613 | rowIndex */
        "movl -0x2c(%ebp), %edi\n" /* rowIndex */
        "cmpl %edi, -0x30(%ebp)\n" /* dstHeight */
        "jne .Lfe7906_000e7961\n"
        /* } scope */
        ".Lfe7906_000e79fc:\n"
        "addl $0x34, %esp\n" /* line 1628 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe7906_000e7a04:\n"
        "movl -0x34(%ebp), %eax\n" /* line 1600 | dstWidth */
        "addl -0x30(%ebp), %eax\n" /* dstHeight */
        "movl %eax, -0x18(%ebp)\n"
        "testl %eax, %eax\n" /* line 1602 */
        "jle .Lfe7906_000e79fc\n"
        "movl 0x18(%ebp), %edx\n" /* line 1608 | texelPitch */
        "addl %edx, %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "movl 8(%ebp), %edi\n" /* src */
        "movl %edi, -0x3c(%ebp)\n" /* srcPos */
        "movl 0x1c(%ebp), %esi\n" /* dst, dstPos */
        "movl $0, -0x28(%ebp)\n" /* colIndex */
        ".Lfe7906_000e7a29:\n"
        "movl 0x18(%ebp), %edi\n" /* line 1604 | texelPitch */
        "testl %edi, %edi\n"
        "jle .Lfe7906_000e7a50\n"
        "xorl %ebx, %ebx\n" /* line 1608 | channelIndex */
        "movl -0x3c(%ebp), %ecx\n" /* srcPos */
        ".Lfe7906_000e7a35:\n"
        "movzbl (%ecx), %eax\n" /* line 1605 */
        "movl 0x18(%ebp), %edi\n" /* texelPitch */
        "movzbl (%ecx, %edi), %edx\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "movb %al, (%esi, %ebx)\n" /* dstPos */
        "addl $1, %ebx\n" /* line 1604 | channelIndex */
        "addl $1, %ecx\n"
        "cmpl %ebx, %edi\n" /* channelIndex */
        "jne .Lfe7906_000e7a35\n"
        ".Lfe7906_000e7a50:\n"
        "addl 0x18(%ebp), %esi\n" /* line 1607 | texelPitch, dstPos */
        "movl -0x38(%ebp), %eax\n" /* line 1608 */
        "addl %eax, -0x3c(%ebp)\n" /* srcPos */
        "addl $1, -0x28(%ebp)\n" /* line 1602 | colIndex */
        "movl -0x28(%ebp), %edx\n" /* colIndex */
        "cmpl %edx, -0x18(%ebp)\n"
        "jne .Lfe7906_000e7a29\n"
        /* } scope */
        "addl $0x34, %esp\n" /* line 1628 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe7906_000e7a6d:\n"
        "cmpl $1, 0x14(%ebp)\n" /* line 1587 | srcHeight */
        "jne .Lfe7906_000e791b\n"
        "jmp .Lfe7906_000e79fc\n"
    );
}

/* line 276 */
void Image_Release(GfxImage *image)
{
    byte *img = (byte *)image;
    signed char mapType = *(signed char *)(img + 0xc);
    void *texture;
    void **vtable;
    int i;

    /* Check if this image type needs global memory accounting:
     * types > 4, or types 0-4 where (1 << type) & 0x13 == 0 */
    if ((byte)mapType > 4 || !((1 << mapType) & 0x13)) {
        /* Subtract per-platform memory tracking from imageGlobals totals */
        for (i = 0; i < 2; i++) {
            imageGlobals[0x200c / 4 + i] -= *(int *)(img + 0x10 + i * 4);
        }
    }

    /* Release COM texture object if present */
    texture = *(void **)(img + 4);
    if (texture) {
        vtable = *(void ***)texture;
        ((ULONG (*)(void *))(vtable[8 / 4]))(texture); /* Release — vtable 0x08 */
        *(void **)(img + 4) = NULL;
        *(int *)(img + 0x10) = 0;
        *(int *)(img + 0x14) = 0;
    }

    *(int *)img = 0;
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

        category = *(byte *)((char *)image + 0x1e);
        if (category <= 4)
            continue;

        /* Skip images that already have a texture */
        if (*(void **)((char *)image + 4) != NULL)
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
__attribute__((naked))
void Image_TrackTexture(GfxImage *image, int imageFlags, D3DFORMAT format, int width, int height, int depth)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 388 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "testb $1, 0xc(%ebp)\n" /* imageFlags */
        "jne .Lfe7b5a_000e7c1d\n"
        /* { scope 1 */
        "movl 8(%ebp), %esi\n" /* line 416 | image */
        "movl %esi, %edi\n"
        "movl $imageGlobals, -0x1c(%ebp)\n"
        ".Lfe7b5a_000e7b79:\n"
        "movzbl 8(%esi), %ecx\n" /* line 405 */
        "movl 0x14(%ebp), %edx\n" /* width */
        "sarl %cl, %edx\n"
        "movl $1, %eax\n" /* line 154 */
        "cmpl %edx, %eax\n"
        "js .Lfe7b5a_000e7b90\n"
        "movl $1, %edx\n"
        ".Lfe7b5a_000e7b90:\n"
        "movl 0x18(%ebp), %ebx\n" /* line 406 | height, heightUsed */
        "sarl %cl, %ebx\n" /* heightUsed */
        "movl $1, %eax\n" /* line 154 */
        "cmpl %ebx, %eax\n"
        "js .Lfe7b5a_000e7ba3\n"
        "movl $1, %ebx\n"
        ".Lfe7b5a_000e7ba3:\n"
        "movl 0x1c(%ebp), %eax\n" /* line 407 | depth */
        "sarl %cl, %eax\n"
        "movl $1, %ecx\n" /* line 154 */
        "cmpl %eax, %ecx\n"
        "js .Lfe7b5a_000e7bb6\n"
        "movl $1, %eax\n" /* line 412 */
        ".Lfe7b5a_000e7bb6:\n"
        "movl %eax, 0x10(%esp)\n" /* line 409 */
        "movl %ebx, 0xc(%esp)\n" /* heightUsed */
        "movl %edx, 8(%esp)\n"
        "movl 0x10(%ebp), %ecx\n" /* format */
        "movl %ecx, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* imageFlags */
        "movl %eax, (%esp)\n"
        "calll Image_GetCardMemoryAmount\n"
        "movl %eax, 0x10(%edi)\n"
        "movl 8(%ebp), %edx\n" /* line 170 | image */
        "cmpb $4, 0xc(%edx)\n"
        "ja .Lfe7b5a_000e7c12\n"
        "movsbl 0xc(%edx), %ecx\n"
        "movl $1, %edx\n"
        "shll %cl, %edx\n"
        "movl %edx, %ecx\n"
        "andb $0x13, %cl\n"
        "je .Lfe7b5a_000e7c12\n"
        ".Lfe7b5a_000e7bf2:\n"
        "addl $4, -0x1c(%ebp)\n" /* line 154 */
        "addl $4, %edi\n"
        "addl $1, %esi\n"
        "movl $imageGlobals+8, %edx\n" /* line 395 */
        "cmpl -0x1c(%ebp), %edx\n"
        "jne .Lfe7b5a_000e7b79\n"
        /* } scope */
        ".Lfe7b5a_000e7c0a:\n"
        "addl $0x3c, %esp\n" /* line 416 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe7b5a_000e7c12:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 413 */
        "addl %eax, 0x200c(%edx)\n"
        "jmp .Lfe7b5a_000e7bf2\n"
        /* } scope */
        ".Lfe7b5a_000e7c1d:\n"
        "movl 8(%ebp), %ebx\n" /* line 388 | image */
        "movl $imageGlobals, %esi\n"
        "movl $1, %edi\n"
        /* { scope 1 */
        ".Lfe7b5a_000e7c2a:\n"
        "movl 0x1c(%ebp), %eax\n" /* line 409 | depth */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x18(%ebp), %edx\n" /* height */
        "movl %edx, 0xc(%esp)\n"
        "movl 0x14(%ebp), %ecx\n" /* width */
        "movl %ecx, 8(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* format */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* imageFlags */
        "movl %edx, (%esp)\n"
        "calll Image_GetCardMemoryAmount\n"
        "movl %eax, 0x10(%ebx)\n" /* heightUsed */
        "movl 8(%ebp), %ecx\n" /* line 170 | image */
        "cmpb $4, 0xc(%ecx)\n"
        "ja .Lfe7b5a_000e7c6c\n"
        "movsbl 0xc(%ecx), %ecx\n"
        "movl %edi, %edx\n"
        "shll %cl, %edx\n"
        "movl %edx, %ecx\n"
        "andb $0x13, %cl\n"
        "jne .Lfe7b5a_000e7c72\n"
        ".Lfe7b5a_000e7c6c:\n"
        "addl %eax, 0x200c(%esi)\n" /* line 413 */
        ".Lfe7b5a_000e7c72:\n"
        "addl $4, %esi\n"
        "addl $4, %ebx\n" /* heightUsed */
        "movl $imageGlobals+8, %ecx\n" /* line 395 */
        "cmpl %esi, %ecx\n"
        "je .Lfe7b5a_000e7c0a\n"
        "jmp .Lfe7b5a_000e7c2a\n"
    );
}

/* line 362 */
__attribute__((naked))
void Image_TrackFullscreenTexture(GfxImage *image, int picmip, D3DFORMAT format)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 362 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl $0, -0x1c(%ebp)\n" /* platform */
        /* { scope 1 */
        ".Lfe7c84_000e7c94:\n"
        "movl imp_vidConfig, %edx\n" /* line 343 */
        "movl (%edx), %ebx\n"
        "movl -0x1c(%ebp), %eax\n" /* platform */
        "shll $2, %eax\n"
        "leal imageGlobals+8204(%eax), %edi\n"
        "movl 8(%ebp), %ecx\n" /* image */
        "leal 0x10(%eax, %ecx), %esi\n"
        "cmpl $1, -0x1c(%ebp)\n" /* line 350 | platform */
        "je .Lfe7c84_000e7d5f\n"
        "movl 4(%edx), %edx\n" /* line 358 */
        "movl %edx, -0x2c(%ebp)\n" /* screenHeight */
        ".Lfe7c84_000e7cbf:\n"
        "movl %ebx, %eax\n" /* line 142 */
        "movzbl 0xc(%ebp), %ecx\n" /* picmip */
        "sarl %cl, %eax\n"
        /* { scope 2 */
        "movl $1, %ebx\n" /* line 154 */
        "movl $1, %edx\n"
        "cmpl %eax, %ebx\n"
        "cmovnsl %edx, %eax\n"
        "movw %ax, -0x48(%ebp)\n"
        /* } scope */
        "movl -0x2c(%ebp), %eax\n" /* line 142 | screenHeight */
        "sarl %cl, %eax\n"
        /* { scope 2 */
        "cmpl %eax, %ebx\n" /* line 154 */
        "cmovsl %eax, %edx\n"
        /* } scope */
        "movl $1, 0x10(%esp)\n" /* line 376 */
        "movzwl %dx, %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movzwl -0x48(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* format */
        "movl %edx, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll Image_GetCardMemoryAmount\n"
        "addl %eax, (%esi)\n" /* line 378 */
        "movl 8(%ebp), %ecx\n" /* line 170 | image */
        "cmpb $4, 0xc(%ecx)\n"
        "ja .Lfe7c84_000e7d36\n"
        "movsbl 0xc(%ecx), %ecx\n"
        "shll %cl, %ebx\n"
        "andb $0x13, %bl\n"
        "je .Lfe7c84_000e7d36\n"
        "addl $1, -0x1c(%ebp)\n" /* line 371 | platform */
        "cmpl $1, -0x1c(%ebp)\n" /* platform */
        "jle .Lfe7c84_000e7d42\n"
        /* } scope */
        ".Lfe7c84_000e7d2e:\n"
        "addl $0x5c, %esp\n" /* line 385 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe7c84_000e7d36:\n"
        "addl %eax, (%edi)\n" /* line 382 */
        "addl $1, -0x1c(%ebp)\n" /* line 371 | platform */
        "cmpl $1, -0x1c(%ebp)\n" /* platform */
        "jg .Lfe7c84_000e7d2e\n"
        ".Lfe7c84_000e7d42:\n"
        "jne .Lfe7c84_000e7c94\n" /* line 335 */
        "addl $4, %edi\n"
        "addl $4, %esi\n"
        "movl $0x1e0, -0x2c(%ebp)\n" /* screenHeight */
        "movl $0x280, %ebx\n"
        "jmp .Lfe7c84_000e7cbf\n"
        ".Lfe7c84_000e7d5f:\n"
        "movl $0x1e0, -0x2c(%ebp)\n" /* line 350 | screenHeight */
        "jmp .Lfe7c84_000e7cbf\n"
    );
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
    *(const char **)((char *)image + 0x20) = name; /* image->name */
    *((byte *)image + 0x1e) = (byte)category;      /* image->category */
    *((byte *)image + 0x0a) = 0;                    /* image->state */
    *((byte *)image + 0x0c) = 0;                    /* image->mapType */

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
    void *(*hunkAlloc)(int) = *(void *(**)(int))((byte *)imp_ri + 0xc);
    byte *image;
    char *nameDst;
    int hash;

    /* Allocate image struct + name string (0x24 bytes for struct + name) */
    image = (byte *)hunkAlloc(0x24 + nameLen);

    /* Name stored right after the struct */
    nameDst = (char *)(image + 0x24);
    *(char **)(image + 0x20) = nameDst;
    memcpy(nameDst, name, nameLen);

    /* Initialize fields */
    *(byte *)(image + 0x1e) = (byte)category;
    *(byte *)(image + 0x0a) = (byte)semantic;
    *(byte *)(image + 0x0c) = (byte)imageTrack;

    /* Insert into hash table */
    hash = R_HashAssetName(name) & 0x7ff;
    while (imageGlobals[hash] != 0) {
        hash = (hash + 1) & 0x7ff;
    }
    imageGlobals[hash] = (int)image;

    return (GfxImage *)image;
}

/* line 1318 */
__attribute__((naked))
void R_ImageList_f(void)
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

/* line 881 */
__attribute__((naked))
GfxImage * Image_Register(const char *imageName, int semantic, int imageTrack)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 881 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* imageName */
        "movzbl 0xc(%ebp), %eax\n" /* semantic */
        "movb %al, -0x19(%ebp)\n" /* semantic */
        /* { scope 1 */
        /* { scope 2 */
        "movl %edi, (%esp)\n" /* line 270 */
        "calll R_HashAssetName\n"
        "movl %eax, %ebx\n"
        "andl $0x7ff, %ebx\n"
        "movl imageGlobals(, %ebx, 4), %esi\n" /* line 869 */
        "testl %esi, %esi\n" /* line 870 */
        "je .Lfe862a_000e86ca\n"
        ".Lfe862a_000e8658:\n"
        "movl 0x20(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lfe862a_000e86ca\n"
        "addl $1, %ebx\n" /* line 873 | hashIndex */
        "andl $0x7ff, %ebx\n" /* hashIndex */
        "movl imageGlobals(, %ebx, 4), %esi\n" /* line 874 */
        "testl %esi, %esi\n" /* line 870 */
        "jne .Lfe862a_000e8658\n"
        ".Lfe862a_000e867f:\n"
        "xorl %eax, %eax\n" /* line 546 */
        ".Lfe862a_000e8681:\n"
        "testl %eax, %eax\n" /* line 877 */
        "jne .Lfe862a_000e8693\n"
        /* } scope */
        "testl %esi, %esi\n" /* line 886 | image */
        "je .Lfe862a_000e8693\n"
        /* } scope */
        ".Lfe862a_000e8689:\n"
        "movl %esi, %eax\n" /* line 893 | image */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe862a_000e8693:\n"
        "movl 0x10(%ebp), %eax\n" /* line 889 | imageTrack */
        "movl %eax, 8(%esp)\n"
        "movzbl -0x19(%ebp), %eax\n" /* semantic */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* imageName */
        "calll Image_Load\n"
        "movl %eax, %esi\n" /* image */
        "testl %eax, %eax\n" /* line 890 */
        "jne .Lfe862a_000e8689\n"
        "movl %edi, 8(%esp)\n" /* line 891 | imageName */
        "movl $str_00225554, 4(%esp)\n" /* "failed to load image '%s'" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe862a_000e8689\n"
        /* { scope 2 */
        ".Lfe862a_000e86ca:\n"
        "cmpl $g_imageProgs, %esi\n" /* line 546 */
        "jb .Lfe862a_000e867f\n"
        "cmpl $g_imageProgs+432, %esi\n"
        "jae .Lfe862a_000e867f\n"
        "movl $1, %eax\n"
        "jmp .Lfe862a_000e8681\n"
    );
}

/* line 1272 */
__attribute__((naked))
void R_InitImages(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1272 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "calll R_SetPicmip\n" /* line 1282 */
        "movl $0, 8(%esp)\n" /* line 1096 */
        "movl $1, 4(%esp)\n"
        "movl $str_00225570, (%esp)\n" /* "$white" */
        "calll Image_Register\n"
        "movl imp_rgp, %ebx\n"
        "movl %eax, 0x1008(%ebx)\n"
        "movl $0, 8(%esp)\n" /* line 1099 */
        "movl $1, 4(%esp)\n"
        "movl $str_00225578, (%esp)\n" /* "$black" */
        "calll Image_Register\n"
        "movl %eax, 0x100c(%ebx)\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 1103 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfe86e2_000e887a\n"
        "movl $0, 8(%esp)\n" /* line 1111 */
        "movl $1, 4(%esp)\n"
        "movl $str_0022558c, (%esp)\n" /* "$identitynormalmap" */
        "calll Image_Register\n"
        "movl %eax, 0x1010(%ebx)\n"
        "movl $0, 8(%esp)\n" /* line 1115 */
        "movl $1, 4(%esp)\n"
        "movl $str_002255a0, (%esp)\n" /* "$specularity" */
        "calll Image_Register\n"
        "movl %eax, 0x1014(%ebx)\n"
        "movl $0, 8(%esp)\n" /* line 1119 */
        "movl $1, 4(%esp)\n"
        "movl $str_002255b0, (%esp)\n" /* "$lightgridweights0" */
        "calll Image_Register\n"
        "movl %eax, 0x101c(%ebx)\n"
        "movl $0, 8(%esp)\n" /* line 1121 */
        "movl $1, 4(%esp)\n"
        "movl $str_002255c4, (%esp)\n" /* "$lightgridweights1" */
        "calll Image_Register\n"
        "movl %eax, 0x1020(%ebx)\n"
        "movl $0, 8(%esp)\n" /* line 1124 */
        "movl $1, 4(%esp)\n"
        "movl $str_002255d8, (%esp)\n" /* "$lightmapweights" */
        "calll Image_Register\n"
        "movl %eax, 0x1018(%ebx)\n"
        ".Lfe86e2_000e87f3:\n"
        "calll RB_InitImages\n" /* line 1287 */
        "movl g_imageProgNames+44, %eax\n" /* line 485 */
        "movl %eax, g_imageProgs+428\n" /* line 486 */
        "movb $4, g_imageProgs+426\n" /* line 489 */
        "movb $0, g_imageProgs+406\n" /* line 490 */
        "movb $0, g_imageProgs+408\n" /* line 495 */
        "movl %eax, (%esp)\n" /* line 270 */
        "calll R_HashAssetName\n"
        "andl $0x7ff, %eax\n"
        "movl imageGlobals(, %eax, 4), %ecx\n" /* line 435 */
        "testl %ecx, %ecx\n"
        "je .Lfe86e2_000e8842\n"
        ".Lfe86e2_000e882f:\n"
        "addl $1, %eax\n" /* line 438 */
        "andl $0x7ff, %eax\n"
        "movl imageGlobals(, %eax, 4), %edx\n" /* line 435 */
        "testl %edx, %edx\n"
        "jne .Lfe86e2_000e882f\n"
        ".Lfe86e2_000e8842:\n"
        "movl $g_imageProgs+396, imageGlobals(, %eax, 4)\n" /* line 499 */
        "movl imp_rgp, %eax\n" /* line 1084 */
        "movl $g_imageProgs+396, 0x1098(%eax)\n"
        "movb $0x32, 0x10e8(%eax)\n" /* line 1087 */
        "movb $0, 0x10e9(%eax)\n" /* line 1088 */
        "movl $g_imageProgs+396, 0x10ec(%eax)\n" /* line 1089 */
        "addl $0x14, %esp\n" /* line 1292 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfe86e2_000e887a:\n"
        "movl $0, 8(%esp)\n" /* line 1105 */
        "movl $1, 4(%esp)\n"
        "movl $str_00225580, (%esp)\n" /* "$watercolor" */
        "calll Image_Register\n"
        "movl %eax, 0x10a4(%ebx)\n"
        "jmp .Lfe86e2_000e87f3\n"
    );
}

/* line 715 */
__attribute__((naked))
void Image_SetupRenderTarget(GfxImage *image, int width, int height, D3DFORMAT imageFormat)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 715 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %esi\n" /* image */
        "movzwl 0x10(%ebp), %eax\n" /* line 725 | height */
        "movl %eax, -0x1c(%ebp)\n"
        "movzwl 0xc(%ebp), %edi\n" /* width */
        /* { scope 1 */
        "movw %di, 0x18(%esi)\n" /* line 655 */
        "movw %ax, 0x1a(%esi)\n" /* line 656 */
        "movw $1, 0x1c(%esi)\n" /* line 657 */
        "movl $3, (%esi)\n" /* line 659 */
        "movl imp_dx, %eax\n" /* line 661 */
        "movl 8(%eax), %edx\n"
        "movl (%edx), %ecx\n"
        "movl $0, 0x20(%esp)\n"
        "leal 4(%esi), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* imageFormat */
        "movl %eax, 0x14(%esp)\n"
        "movl $1, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x5c(%ecx)\n"
        "movl %eax, %ebx\n" /* hr */
        "testl %eax, %eax\n" /* line 662 */
        "js .Lfe88a2_000e894e\n"
        /* } scope */
        ".Lfe88a2_000e891c:\n"
        "movl $1, 0x14(%esp)\n" /* line 727 */
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* imageFormat */
        "movl %eax, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* image */
        "calll Image_TrackTexture\n"
        "addl $0x4c, %esp\n" /* line 730 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe88a2_000e894e:\n"
        "movl %eax, (%esp)\n" /* line 663 */
        "calll R_ErrorDescription\n"
        "movl %eax, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n" /* hr */
        "movl 0x14(%ebp), %eax\n" /* imageFormat */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movzwl 0x1a(%esi), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movzwl 0x18(%esi), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x20(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0022520c, 4(%esp)\n" /* "Create2DTexture( %s, %i, %i, %i, %i ) failed: %08x = %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe88a2_000e891c\n"
    );
}

/* line 733 */
__attribute__((naked))
void Image_SetupSystem(GfxImage *image, int width, int height, D3DFORMAT imageFormat)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 733 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %esi\n" /* image */
        "movzwl 0x10(%ebp), %eax\n" /* line 743 | height */
        "movl %eax, -0x1c(%ebp)\n"
        "movzwl 0xc(%ebp), %edi\n" /* width */
        /* { scope 1 */
        "movw %di, 0x18(%esi)\n" /* line 655 */
        "movw %ax, 0x1a(%esi)\n" /* line 656 */
        "movw $1, 0x1c(%esi)\n" /* line 657 */
        "movl $3, (%esi)\n" /* line 659 */
        "movl imp_dx, %eax\n" /* line 661 */
        "movl 8(%eax), %edx\n"
        "movl (%edx), %ecx\n"
        "movl $0, 0x20(%esp)\n"
        "leal 4(%esi), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl $2, 0x18(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* imageFormat */
        "movl %eax, 0x14(%esp)\n"
        "movl $0x200, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x5c(%ecx)\n"
        "movl %eax, %ebx\n" /* hr */
        "testl %eax, %eax\n" /* line 662 */
        "js .Lfe899a_000e8a46\n"
        /* } scope */
        ".Lfe899a_000e8a14:\n"
        "movl $1, 0x14(%esp)\n" /* line 745 */
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* imageFormat */
        "movl %eax, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* image */
        "calll Image_TrackTexture\n"
        "addl $0x4c, %esp\n" /* line 748 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe899a_000e8a46:\n"
        "movl %eax, (%esp)\n" /* line 663 */
        "calll R_ErrorDescription\n"
        "movl %eax, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n" /* hr */
        "movl 0x14(%ebp), %eax\n" /* imageFormat */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movzwl 0x1a(%esi), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movzwl 0x18(%esi), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x20(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0022520c, 4(%esp)\n" /* "Create2DTexture( %s, %i, %i, %i, %i ) failed: %08x = %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe899a_000e8a14\n"
    );
}

/* line 976 */
__attribute__((naked))
void Image_RebuildCosinePowerMap(float shift)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 976 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x203c, %esp\n"
        /* { scope 1 */
        "movl imp_r_rendererInUse, %eax\n" /* line 984 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfe8a92_000e8ba5\n"
        "movl imp_rgp, %ebx\n" /* line 1002 */
        "movl 0x1014(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_UnbindImage\n"
        "movl %ebx, %esi\n"
        "movl imp_alwaysfails, %ebx\n"
        ".Lfe8a92_000e8acb:\n"
        "movl 0x1014(%esi), %eax\n" /* line 1008 */
        "movl 4(%eax), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        "movl 0x1014(%esi), %eax\n"
        "movl $0, 4(%eax)\n"
        "movl (%ebx), %edi\n" /* hr */
        "testl %edi, %edi\n" /* hr */
        "jne .Lfe8a92_000e8acb\n"
        "movl 0x1014(%esi), %ebx\n" /* line 1009 | image */
        /* { scope 2 */
        /* { scope 3 */
        "movw $0x20, 0x18(%ebx)\n" /* line 655 */
        "movw $0x100, 0x1a(%ebx)\n" /* line 656 */
        "movw $1, 0x1c(%ebx)\n" /* line 657 */
        "movl $3, (%ebx)\n" /* line 659 */
        "movl imp_dx, %eax\n" /* line 661 */
        "movl 8(%eax), %edx\n"
        "movl (%edx), %ecx\n"
        "movl $0, 0x20(%esp)\n"
        "leal 4(%ebx), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl $1, 0x18(%esp)\n"
        "movl $0x32, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl $0x100, 8(%esp)\n"
        "movl $0x20, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x5c(%ecx)\n"
        "movl %eax, %edi\n" /* hr */
        "testl %eax, %eax\n" /* line 662 */
        "js .Lfe8a92_000e8bb0\n"
        /* } scope */
        /* } scope */
        ".Lfe8a92_000e8b62:\n"
        "leal -0x2018(%ebp), %ebx\n" /* line 1012 | pic, image */
        "movl %ebx, 4(%esp)\n" /* image */
        "movss 8(%ebp), %xmm0\n" /* shift */
        "movss %xmm0, (%esp)\n"
        "calll Image_BuildSpecularityMap\n"
        "movl %ebx, 0x10(%esp)\n" /* line 1013 | image */
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x32, 4(%esp)\n"
        "movl 0x1014(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Image_UploadData\n"
        /* } scope */
        ".Lfe8a92_000e8ba5:\n"
        "addl $0x203c, %esp\n" /* line 1014 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfe8a92_000e8bb0:\n"
        "movl %eax, (%esp)\n" /* line 663 */
        "calll R_ErrorDescription\n"
        "movl %eax, 0x20(%esp)\n"
        "movl %edi, 0x1c(%esp)\n" /* hr */
        "movl $0x32, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movzwl 0x1a(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movzwl 0x18(%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x20(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_0022520c, 4(%esp)\n" /* "Create2DTexture( %s, %i, %i, %i, %i ) failed: %08x = %s" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfe8a92_000e8b62\n"
    );
}

/* line 599 */
__attribute__((naked))
void R_ShutdownImages(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 599 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x202c, %esp\n"
        /* { scope 1 */
        "calll RB_UnbindAllImages\n" /* line 607 */
        "movl $0, -0x201c(%ebp)\n" /* savedImageCount */
        "movl $imageGlobals, %esi\n"
        "jmp .Lfe8c02_000e8c5b\n"
        ".Lfe8c02_000e8c24:\n"
        "cmpl $g_imageProgs+432, %ebx\n" /* line 546 */
        "jae .Lfe8c02_000e8c69\n"
        "movl $1, %eax\n"
        "testl %eax, %eax\n" /* line 615 */
        "je .Lfe8c02_000e8c6f\n"
        ".Lfe8c02_000e8c35:\n"
        "movl -0x201c(%ebp), %eax\n" /* line 617 | savedImageCount */
        "movl %ebx, -0x2018(%ebp, %eax, 4)\n" /* savedImageIndex */
        "addl $1, %eax\n" /* line 618 */
        "movl %eax, -0x201c(%ebp)\n" /* savedImageCount */
        ".Lfe8c02_000e8c4b:\n"
        "addl $4, %esi\n" /* line 312 */
        "movl $imageGlobals+8192, %eax\n" /* line 610 */
        "cmpl %esi, %eax\n"
        "je .Lfe8c02_000e8ce3\n"
        ".Lfe8c02_000e8c5b:\n"
        "movl (%esi), %ebx\n" /* line 612 | savedImageIndex */
        "testl %ebx, %ebx\n" /* line 613 | savedImageIndex */
        "je .Lfe8c02_000e8c4b\n"
        "cmpl $g_imageProgs, %ebx\n" /* line 546 */
        "jae .Lfe8c02_000e8c24\n"
        ".Lfe8c02_000e8c69:\n"
        "xorl %eax, %eax\n"
        "testl %eax, %eax\n" /* line 615 */
        "jne .Lfe8c02_000e8c35\n"
        ".Lfe8c02_000e8c6f:\n"
        "cmpb $4, 0xc(%ebx)\n" /* line 170 */
        "ja .Lfe8c02_000e8c84\n"
        "movsbl 0xc(%ebx), %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "testb $0x13, %al\n"
        "jne .Lfe8c02_000e8ca9\n"
        ".Lfe8c02_000e8c84:\n"
        "movl %ebx, %edx\n" /* line 285 */
        "movl $imageGlobals, %ecx\n"
        "movl $imageGlobals+8, %edi\n"
        ".Lfe8c02_000e8c90:\n"
        "movl 0x200c(%ecx), %eax\n" /* line 288 */
        "subl 0x10(%edx), %eax\n"
        "movl %eax, 0x200c(%ecx)\n"
        "addl $4, %ecx\n"
        "addl $4, %edx\n"
        "cmpl %ecx, %edi\n" /* line 287 */
        "jne .Lfe8c02_000e8c90\n"
        ".Lfe8c02_000e8ca9:\n"
        "movl 4(%ebx), %edx\n" /* line 292 */
        "testl %edx, %edx\n"
        "je .Lfe8c02_000e8ccd\n"
        "movl (%edx), %eax\n" /* line 295 */
        "cmpl $0, 8(%eax)\n" /* fix #153: skip Release if vtable entry is NULL (zeroed vtable) */
        "je .Lfe8c02_000e8ccd\n"
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        "movl $0, 4(%ebx)\n" /* line 298 */
        "movl $0, 0x10(%ebx)\n" /* line 301 */
        "movl $0, 0x14(%ebx)\n"
        ".Lfe8c02_000e8ccd:\n"
        "movl $0, (%ebx)\n" /* line 312 */
        "addl $4, %esi\n"
        "movl $imageGlobals+8192, %eax\n" /* line 610 */
        "cmpl %esi, %eax\n"
        "jne .Lfe8c02_000e8c5b\n"
        ".Lfe8c02_000e8ce3:\n"
        "movl $0x2000, 8(%esp)\n" /* line 624 */
        "movl $0, 4(%esp)\n"
        "movl $imageGlobals, (%esp)\n"
        "calll memset\n"
        "movl -0x201c(%ebp), %ebx\n" /* line 626 | savedImageCount, savedImageIndex */
        "testl %ebx, %ebx\n" /* savedImageIndex */
        "jg .Lfe8c02_000e8d14\n"
        /* } scope */
        ".Lfe8c02_000e8d09:\n"
        "addl $0x202c, %esp\n" /* line 632 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe8c02_000e8d14:\n"
        "xorl %ebx, %ebx\n" /* line 626 | savedImageIndex */
        ".Lfe8c02_000e8d16:\n"
        "movl -0x2018(%ebp, %ebx, 4), %esi\n" /* line 628 */
        "movl 0x20(%esi), %eax\n" /* line 270 */
        "movl %eax, (%esp)\n"
        "calll R_HashAssetName\n"
        "andl $0x7ff, %eax\n"
        "movl imageGlobals(, %eax, 4), %ecx\n" /* line 435 */
        "testl %ecx, %ecx\n"
        "je .Lfe8c02_000e8d4b\n"
        ".Lfe8c02_000e8d38:\n"
        "addl $1, %eax\n" /* line 438 */
        "andl $0x7ff, %eax\n"
        "movl imageGlobals(, %eax, 4), %edx\n" /* line 435 */
        "testl %edx, %edx\n"
        "jne .Lfe8c02_000e8d38\n"
        ".Lfe8c02_000e8d4b:\n"
        "movl %esi, imageGlobals(, %eax, 4)\n" /* line 630 */
        "addl $1, %ebx\n" /* line 626 | savedImageIndex */
        "cmpl -0x201c(%ebp), %ebx\n" /* savedImageCount, savedImageIndex */
        "jne .Lfe8c02_000e8d16\n"
        "jmp .Lfe8c02_000e8d09\n"
    );
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
        if (*(byte *)((char *)image + 0x1e) <= 4)
            continue;

        Image_Release(image);
    }
}

/* line 1019 */
extern void Image_GetPicmip(const GfxImage *image, Picmip *picmip);

void Image_UpdatePicmip(GfxImage *image)
{
    Picmip picmip;
    byte *img = (byte *)image;

    Image_GetPicmip(image, &picmip);

    /* If picmip level hasn't changed, nothing to do */
    if (img[8] == ((byte *)&picmip)[0])
        return;

    /* Release current texture and reload with new picmip */
    Image_Release(image);

    /* Set new picmip value (copy 2 bytes) */
    *(unsigned short *)(img + 8) = *(unsigned short *)&picmip;

    if (!Image_LoadFromFile(image)) {
        R_Error(1, "failed to load image '%s'",
            *(const char **)(img + 0x20));
    }
}

/* line 1037 */

void Image_Reload(GfxImage *image)
{
    Image_Release(image);

    if (!Image_LoadFromFile(image)) {
        R_Error(1, "failed to load image '%s'",
            *(const char **)((char *)image + 0x20));
    }
}

/* line 273 */
__attribute__((naked))
void ZSt13__adjust_heapIPP8GfxImageiS1_PFiS1_S1_EEvT_T0_S6_T1_T2_(void) /* void std___adjust_heap<GfxImage**, int, GfxImage*, int (*)(GfxImage*, GfxImage*)> */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 273 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 276 | __holeIndex */
        "leal 2(%eax, %eax), %ebx\n" /* __secondChild */
        "cmpl 0x10(%ebp), %ebx\n" /* line 277 | __len, __secondChild */
        "jl .Lf2bfc8a_002bfd0d\n"
        "movl 8(%ebp), %edx\n" /* __first */
        "leal (%edx, %eax, 4), %esi\n"
        "movl %eax, %edi\n"
        ".Lf2bfc8a_002bfca7:\n"
        "cmpl %ebx, 0x10(%ebp)\n" /* line 286 | __secondChild, __len */
        "je .Lf2bfc8a_002bfd5f\n"
        ".Lf2bfc8a_002bfcb0:\n"
        "leal -1(%edi), %edx\n" /* line 165 */
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "leal (%eax, %edx), %ebx\n"
        "sarl $1, %ebx\n"
        "cmpl 0xc(%ebp), %edi\n" /* line 166 | __holeIndex */
        "jg .Lf2bfc8a_002bfcec\n"
        ".Lf2bfc8a_002bfcc2:\n"
        "movl 0x14(%ebp), %eax\n" /* line 173 | __value */
        "movl %eax, (%esi)\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 291 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2bfc8a_002bfccf:\n"
        "movl (%esi), %eax\n" /* line 169 */
        "movl 8(%ebp), %edx\n" /* __first */
        "movl %eax, (%edx, %edi, 4)\n"
        "leal -1(%ebx), %edx\n" /* line 171 */
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "cmpl 0xc(%ebp), %ebx\n" /* line 166 | __holeIndex */
        "jle .Lf2bfc8a_002bfcc2\n"
        "movl %ebx, %edi\n"
        "movl %eax, %ebx\n"
        ".Lf2bfc8a_002bfcec:\n"
        "movl 8(%ebp), %eax\n" /* __first */
        "leal (%eax, %ebx, 4), %esi\n"
        "movl 0x14(%ebp), %edx\n" /* __value */
        "movl %edx, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x18(%ebp)\n" /* __comp */
        "testl %eax, %eax\n"
        "jne .Lf2bfc8a_002bfccf\n"
        "movl 8(%ebp), %ecx\n" /* __first */
        "leal (%ecx, %edi, 4), %esi\n"
        "jmp .Lf2bfc8a_002bfcc2\n"
        ".Lf2bfc8a_002bfd0d:\n"
        "movl %eax, -0x1c(%ebp)\n" /* line 277 */
        "movl %ebx, %edi\n" /* __secondChild */
        "jmp .Lf2bfc8a_002bfd37\n"
        ".Lf2bfc8a_002bfd14:\n"
        "leal -1(%ebx), %edi\n" /* line 281 | __secondChild */
        "movl 8(%ebp), %ecx\n" /* __first */
        "leal (%ecx, %edi, 4), %esi\n"
        ".Lf2bfc8a_002bfd1d:\n"
        "movl (%esi), %eax\n" /* line 282 */
        "movl -0x1c(%ebp), %edx\n"
        "movl %eax, (%ecx, %edx, 4)\n"
        "leal 2(%edi, %edi), %ebx\n" /* line 284 | __secondChild */
        "cmpl %ebx, 0x10(%ebp)\n" /* line 277 | __secondChild, __len */
        "jle .Lf2bfc8a_002bfca7\n"
        "movl %edi, -0x1c(%ebp)\n"
        "movl %ebx, %edi\n" /* __secondChild */
        ".Lf2bfc8a_002bfd37:\n"
        "leal (, %ebx, 4), %eax\n" /* line 279 */
        "movl 8(%ebp), %esi\n" /* __first */
        "addl %eax, %esi\n"
        "movl 8(%ebp), %edx\n" /* __first */
        "movl -4(%edx, %eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x18(%ebp)\n" /* __comp */
        "testl %eax, %eax\n"
        "jne .Lf2bfc8a_002bfd14\n"
        "movl 8(%ebp), %ecx\n" /* __first */
        "jmp .Lf2bfc8a_002bfd1d\n"
        ".Lf2bfc8a_002bfd5f:\n"
        "movl 0x10(%ebp), %edx\n" /* line 288 | __len */
        "movl 8(%ebp), %ecx\n" /* __first */
        "movl -4(%ecx, %edx, 4), %eax\n"
        "movl %eax, (%esi)\n"
        "movl %edx, %edi\n" /* line 289 */
        "subl $1, %edi\n"
        "leal (%ecx, %edi, 4), %esi\n"
        "jmp .Lf2bfc8a_002bfcb0\n"
    );
}

/* line 2152 */
__attribute__((naked))
void ZSt16__insertion_sortIPP8GfxImagePFiS1_S1_EEvT_S5_T0_(void) /* void std___insertion_sort<GfxImage**, int (*)(GfxImage*, GfxImage*)> */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2152 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* line 2154 | __last */
        "cmpl %eax, 8(%ebp)\n" /* __first */
        "je .Lf2bfd78_002bfddd\n"
        /* { scope 1 */
        "movl 8(%ebp), %edx\n" /* line 2156 | __first */
        "addl $4, %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* __i */
        "cmpl %edx, %eax\n"
        "je .Lf2bfd78_002bfddd\n"
        /* { scope 2 */
        ".Lf2bfd78_002bfd96:\n"
        "movl (%edx), %edi\n" /* line 2159 | __val */
        "movl 8(%ebp), %edx\n" /* line 2160 | __first */
        "movl (%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* __val */
        "calll *0x10(%ebp)\n" /* __comp */
        "testl %eax, %eax\n"
        "jne .Lf2bfd78_002bfde5\n"
        "movl -0x1c(%ebp), %ebx\n" /* line 2107 | __i */
        "subl $4, %ebx\n"
        "movl -0x1c(%ebp), %esi\n" /* __i */
        "jmp .Lf2bfd78_002bfdbf\n"
        ".Lf2bfd78_002bfdb6:\n"
        "movl (%ebx), %eax\n" /* line 2110 */
        "movl %eax, (%esi)\n"
        "movl %ebx, %esi\n" /* line 2112 */
        "subl $4, %ebx\n"
        ".Lf2bfd78_002bfdbf:\n"
        "movl (%ebx), %eax\n" /* line 2108 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll *0x10(%ebp)\n" /* __comp */
        "testl %eax, %eax\n"
        "jne .Lf2bfd78_002bfdb6\n"
        "movl %edi, (%esi)\n" /* line 2114 */
        "addl $4, -0x1c(%ebp)\n" /* __i */
        "movl -0x1c(%ebp), %edx\n" /* __i */
        /* } scope */
        ".Lf2bfd78_002bfdd8:\n"
        "cmpl %edx, 0xc(%ebp)\n" /* line 2156 | __last */
        "jne .Lf2bfd78_002bfd96\n"
        /* } scope */
        ".Lf2bfd78_002bfddd:\n"
        "addl $0x2c, %esp\n" /* line 2166 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf2bfd78_002bfde5:\n"
        "movl -0x1c(%ebp), %ebx\n" /* line 2162 | __i */
        "addl $4, %ebx\n"
        /* { scope 3 */
        "movl -0x1c(%ebp), %eax\n" /* line 424 | __i */
        "subl 8(%ebp), %eax\n" /* __first */
        "andl $0xfffffffc, %eax\n" /* line 425 */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %edx\n" /* __first */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, %edx\n"
        "subl %eax, %edx\n"
        "movl %edx, (%esp)\n"
        "calll memmove\n"
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 2163 | __first */
        "movl %edi, (%eax)\n" /* __val */
        "movl %ebx, -0x1c(%ebp)\n" /* __i */
        "movl %ebx, %edx\n"
        "jmp .Lf2bfd78_002bfdd8\n"
    );
}

/* line 2514 */
__attribute__((naked))
void ZSt16__introsort_loopIPP8GfxImageiPFiS1_S1_EEvT_S5_T0_T1_(void) /* void std___introsort_loop<GfxImage**, int, int (*)(GfxImage*, GfxImage*)> */
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
