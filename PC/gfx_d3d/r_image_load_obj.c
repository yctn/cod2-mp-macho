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
extern GfxImage * Image_Alloc(const char *name, int category, int semantic, int imageTrack);
static vec3_t lightGridLookupMatrix[3]; /* lightGridLookupMatrix */
static const int faceAxis[6][3]; /* faceAxis */

jpeg_alloc Image_Generate2D(GfxImage *image, byte *pixels, int width, int height, int imageFormat);
jpeg_alloc Image_Generate3D(GfxImage *image, byte *pixels, int width, int height, int depth, D3DFORMAT imageFormat);
jpeg_alloc Image_BuildWaterMap(GfxImage *image);
static jpeg_alloc Image_LoadBitmap(GfxImage *image, const GfxImageFileHeader *fileHeader, const byte *data, D3DFORMAT format, int bytesPerPixel);
static jpeg_alloc Image_LoadDxtc(GfxImage *image, const GfxImageFileHeader *fileHeader, const byte *data, D3DFORMAT format, int bytesPerBlock);
static jpeg_alloc Image_LoadWavelet(GfxImage *image, const byte *data, D3DFORMAT format, int bytesPerPixel);
jpeg_alloc Image_LoadFromData(GfxImage *image, GfxImageFileHeader *fileHeader, const byte *srcData);
static jpeg_alloc Image_GetSunHalfAngleForVector(const vec_t *facePos, int ignored, byte *pixel);
static jpeg_alloc Image_GetWaterColorForVector(const vec_t *facePos, int packedColor, byte *pixel);
static jpeg_alloc Image_GetLightGridWeightsForVector(const vec_t *facePos, int subMap, byte *pixel);
Bool Image_LoadFromFile(GfxImage *image);
GfxImage * R_CreateWaterMap(char *name, int imageWidth, int imageHeight);
static jpeg_alloc Image_GenerateCubemapFunction(GfxImage *image, byte *pic, int res, int userData, jpeg_alloc (*Callback)());
Bool Image_LoadRaw(GfxImage *image, const char *filepath, int imageTrack);
static jpeg_alloc Image_LoadLightmapWeights(GfxImage *image);
GfxImage * Image_Load(const char *name, int semantic, int imageTrack);

/* line 560 */
jpeg_alloc Image_Generate2D(GfxImage *image, byte *pixels, int width, int height, int imageFormat)
{
    int face;
    Image_Setup(image, width, height, 1, 3, 0, imageFormat);
    face = Image_CubemapFace(0);
    Image_UploadData(image, imageFormat, face, 0, pixels);
}

/* line 598 */
jpeg_alloc Image_Generate3D(GfxImage *image, byte *pixels, int width, int height, int depth, D3DFORMAT imageFormat)
{
    int face;
    Image_Setup(image, width, height, depth, 0xb, 0, imageFormat);
    face = Image_CubemapFace(0);
    Image_UploadData(image, imageFormat, face, 0, pixels);
}

/* line 1180 */
jpeg_alloc Image_BuildWaterMap(GfxImage *image)
{
    if (*(int *)((char *)(*(void **)imp_r_rendererInUse) + 8) == 2) {
        Image_Create2DTexture(image, *(unsigned short *)((char *)image + 0x18), *(unsigned short *)((char *)image + 0x1a), 1, 0x200, 0x16, 0);
    } else {
        Image_Create2DTexture(image, *(unsigned short *)((char *)image + 0x18), *(unsigned short *)((char *)image + 0x1a), 0, 0x200, 0x32, 0);
    }
}

/* line 195 */
static __attribute__((naked))
jpeg_alloc Image_LoadBitmap(GfxImage *image, const GfxImageFileHeader *fileHeader, const byte *data, D3DFORMAT format, int bytesPerPixel)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 195 */
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

/* line 245 */
static __attribute__((naked))
jpeg_alloc Image_LoadDxtc(GfxImage *image, const GfxImageFileHeader *fileHeader, const byte *data, D3DFORMAT format, int bytesPerBlock)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 245 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl %edx, -0x28(%ebp)\n"
        "movl %ecx, -0x2c(%ebp)\n"
        /* { scope 1 */
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
        "movl -0x24(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll Image_Setup\n"
        "movl -0x24(%ebp), %ecx\n" /* line 266 */
        "xorl %eax, %eax\n"
        "cmpl $5, (%ecx)\n"
        "sete %al\n"
        "leal 1(%eax, %eax, 4), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* faceCount */
        /* { scope 2 */
        "movl -0x28(%ebp), %ebx\n" /* line 61 */
        "testb $2, 5(%ebx)\n"
        "je .Lffca62_000fcb9b\n"
        "xorl %edi, %edi\n"
        /* } scope */
        ".Lffca62_000fcacf:\n"
        "movl -0x24(%ebp), %edx\n" /* line 272 */
        "movzbl 8(%edx), %eax\n"
        "cmpl %eax, %edi\n" /* mipLevel */
        "jge .Lffca62_000fcaf1\n"
        "jmp .Lffca62_000fcb93\n"
        ".Lffca62_000fcadf:\n"
        "subl $1, %edi\n" /* mipLevel */
        "movl -0x24(%ebp), %edx\n"
        "movzbl 8(%edx), %eax\n"
        "cmpl %edi, %eax\n" /* mipLevel */
        "jg .Lffca62_000fcb93\n"
        ".Lffca62_000fcaf1:\n"
        "movl -0x28(%ebp), %ecx\n" /* line 142 */
        "movswl 6(%ecx), %ebx\n"
        "movl %edi, %ecx\n"
        "sarl %cl, %ebx\n"
        "movl $1, %eax\n" /* line 154 */
        "movl $1, %edx\n"
        "cmpl %ebx, %edx\n"
        "cmovnsl %eax, %ebx\n"
        "movl -0x28(%ebp), %ecx\n" /* line 142 */
        "movswl 8(%ecx), %edx\n"
        "movl %edi, %ecx\n"
        "sarl %cl, %edx\n"
        "movl $1, %ecx\n" /* line 154 */
        "cmpl %edx, %ecx\n"
        "cmovnsl %eax, %edx\n"
        "movl -0x20(%ebp), %esi\n" /* line 276 | faceCount, face */
        "testl %esi, %esi\n" /* face */
        "jle .Lffca62_000fcadf\n"
        "addl $3, %edx\n"
        "sarl $2, %edx\n"
        "leal 3(%ebx), %eax\n" /* width */
        "sarl $2, %eax\n"
        "imull %eax, %edx\n"
        "imull 0xc(%ebp), %edx\n" /* bytesPerBlock */
        "movl %edx, -0x1c(%ebp)\n"
        "xorl %esi, %esi\n" /* face */
        ".Lffca62_000fcb3f:\n"
        "movl -0x24(%ebp), %ebx\n" /* line 278 | width */
        "movzbl 8(%ebx), %eax\n" /* width */
        "movl %edi, %ebx\n" /* mipLevel, width */
        "subl %eax, %ebx\n" /* width */
        "movl %esi, (%esp)\n" /* face */
        "calll Image_CubemapFace\n"
        "movl -0x2c(%ebp), %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* width */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* format */
        "movl %ecx, 4(%esp)\n"
        "movl -0x24(%ebp), %ebx\n" /* width */
        "movl %ebx, (%esp)\n" /* width */
        "calll Image_UploadData\n"
        "movl -0x1c(%ebp), %eax\n" /* line 279 */
        "addl %eax, -0x2c(%ebp)\n"
        "addl $1, %esi\n" /* line 276 | face */
        "cmpl %esi, -0x20(%ebp)\n" /* face, faceCount */
        "jne .Lffca62_000fcb3f\n"
        "subl $1, %edi\n" /* line 272 | mipLevel */
        "movl -0x24(%ebp), %edx\n"
        "movzbl 8(%edx), %eax\n"
        "cmpl %edi, %eax\n" /* mipLevel */
        "jle .Lffca62_000fcaf1\n"
        /* } scope */
        ".Lffca62_000fcb93:\n"
        "addl $0x4c, %esp\n" /* line 282 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lffca62_000fcb9b:\n"
        "movswl 6(%ebx), %ecx\n" /* line 66 */
        "movl $1, %edx\n"
        "movl $1, %eax\n"
        "movswl 0xa(%ebx), %esi\n"
        "movswl 8(%ebx), %ebx\n"
        "jmp .Lffca62_000fcbb8\n"
        ".Lffca62_000fcbb3:\n"
        "addl %eax, %eax\n" /* line 68 */
        "addl $1, %edx\n" /* line 69 */
        ".Lffca62_000fcbb8:\n"
        "cmpl %ecx, %eax\n" /* line 66 */
        "jl .Lffca62_000fcbb3\n"
        "cmpl %ebx, %eax\n"
        "jl .Lffca62_000fcbb3\n"
        "cmpl %esi, %eax\n"
        "jl .Lffca62_000fcbb3\n"
        "leal -1(%edx), %edi\n"
        "jmp .Lffca62_000fcacf\n"
    );
}

/* line 102 */
static __attribute__((naked))
jpeg_alloc Image_LoadWavelet(GfxImage *image, const byte *data, D3DFORMAT format, int bytesPerPixel)
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

/* line 320 */
__attribute__((naked))
jpeg_alloc Image_LoadFromData(GfxImage *image, GfxImageFileHeader *fileHeader, const byte *srcData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 320 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* image */
        "movl 0xc(%ebp), %edx\n" /* fileHeader */
        "movl 0x10(%ebp), %ecx\n" /* srcData */
        "movl $0, 4(%ebx)\n" /* line 322 | image */
        "movzbl 4(%edx), %eax\n" /* line 324 */
        "cmpl $0xd, %eax\n"
        "ja .Lffce9e_000fcec2\n"
        "jmpl *.Ljt_fce9e_0(, %eax, 4)\n"
        ".Lffce9e_000fcec2:\n"
        "popl %ebx\n" /* line 376 */
        "popl %ebp\n"
        "retl\n"
        ".Lffce9e_000fcec5:\n"
        "movl $4, 0xc(%ebp)\n" /* line 327 | fileHeader */
        "movl $0x15, 8(%ebp)\n" /* image */
        "movl %ebx, %eax\n" /* image */
        "popl %ebx\n" /* line 376 */
        "popl %ebp\n"
        "jmp Image_LoadBitmap\n" /* line 327 */
        ".Lffce9e_000fcedc:\n"
        "movl $3, 0xc(%ebp)\n" /* line 330 | fileHeader */
        "movl $0x16, 8(%ebp)\n" /* image */
        "movl %ebx, %eax\n" /* image */
        "popl %ebx\n" /* line 376 */
        "popl %ebp\n"
        "jmp Image_LoadBitmap\n" /* line 330 */
        ".Lffce9e_000fcef3:\n"
        "movl $2, 0xc(%ebp)\n" /* line 333 | fileHeader */
        "movl $0x33, 8(%ebp)\n" /* image */
        "movl %ebx, %eax\n" /* image */
        "popl %ebx\n" /* line 376 */
        "popl %ebp\n"
        "jmp Image_LoadBitmap\n" /* line 333 */
        ".Lffce9e_000fcf0a:\n"
        "movl $1, 0xc(%ebp)\n" /* line 336 | fileHeader */
        "movl $0x32, 8(%ebp)\n" /* image */
        "movl %ebx, %eax\n" /* image */
        "popl %ebx\n" /* line 376 */
        "popl %ebp\n"
        "jmp Image_LoadBitmap\n" /* line 336 */
        ".Lffce9e_000fcf21:\n"
        "movl $1, 0xc(%ebp)\n" /* line 339 | fileHeader */
        "movl $0x1c, 8(%ebp)\n" /* image */
        "movl %ebx, %eax\n" /* image */
        "popl %ebx\n" /* line 376 */
        "popl %ebp\n"
        "jmp Image_LoadBitmap\n" /* line 339 */
        ".Lffce9e_000fcf38:\n"
        "movl $4, 0xc(%ebp)\n" /* line 343 | fileHeader */
        "movl $0x15, 8(%ebp)\n" /* image */
        "movl %ebx, %eax\n" /* image */
        "popl %ebx\n" /* line 376 */
        "popl %ebp\n"
        "jmp Image_LoadWavelet\n" /* line 343 */
        ".Lffce9e_000fcf4f:\n"
        "movl $3, 0xc(%ebp)\n" /* line 346 | fileHeader */
        "movl $0x16, 8(%ebp)\n" /* image */
        "movl %ebx, %eax\n" /* image */
        "popl %ebx\n" /* line 376 */
        "popl %ebp\n"
        "jmp Image_LoadWavelet\n" /* line 346 */
        ".Lffce9e_000fcf66:\n"
        "movl $2, 0xc(%ebp)\n" /* line 349 | fileHeader */
        "movl $0x33, 8(%ebp)\n" /* image */
        "movl %ebx, %eax\n" /* image */
        "popl %ebx\n" /* line 376 */
        "popl %ebp\n"
        "jmp Image_LoadWavelet\n" /* line 349 */
        ".Lffce9e_000fcf7d:\n"
        "movl $1, 0xc(%ebp)\n" /* line 352 | fileHeader */
        "movl $0x32, 8(%ebp)\n" /* image */
        "movl %ebx, %eax\n" /* image */
        "popl %ebx\n" /* line 376 */
        "popl %ebp\n"
        "jmp Image_LoadWavelet\n" /* line 352 */
        ".Lffce9e_000fcf94:\n"
        "movl $1, 0xc(%ebp)\n" /* line 355 | fileHeader */
        "movl $0x1c, 8(%ebp)\n" /* image */
        "movl %ebx, %eax\n" /* image */
        "popl %ebx\n" /* line 376 */
        "popl %ebp\n"
        "jmp Image_LoadWavelet\n" /* line 355 */
        ".Lffce9e_000fcfab:\n"
        "movl $8, 0xc(%ebp)\n" /* line 359 | fileHeader */
        "movl $0x31545844, 8(%ebp)\n" /* image */
        "movl %ebx, %eax\n" /* image */
        "popl %ebx\n" /* line 376 */
        "popl %ebp\n"
        "jmp Image_LoadDxtc\n" /* line 359 */
        ".Lffce9e_000fcfc2:\n"
        "movl $0x10, 0xc(%ebp)\n" /* line 362 | fileHeader */
        "movl $0x33545844, 8(%ebp)\n" /* image */
        "movl %ebx, %eax\n" /* image */
        "popl %ebx\n" /* line 376 */
        "popl %ebp\n"
        "jmp Image_LoadDxtc\n" /* line 362 */
        ".Lffce9e_000fcfd9:\n"
        "movl $0x10, 0xc(%ebp)\n" /* line 365 | fileHeader */
        "movl $0x35545844, 8(%ebp)\n" /* image */
        "movl %ebx, %eax\n" /* image */
        "popl %ebx\n" /* line 376 */
        "popl %ebp\n"
        "jmp Image_LoadDxtc\n" /* line 365 */
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_fce9e_0:\n"
        ".long .Lffce9e_000fcec2\n"
        ".long .Lffce9e_000fcec5\n"
        ".long .Lffce9e_000fcedc\n"
        ".long .Lffce9e_000fcef3\n"
        ".long .Lffce9e_000fcf0a\n"
        ".long .Lffce9e_000fcf21\n"
        ".long .Lffce9e_000fcf38\n"
        ".long .Lffce9e_000fcf4f\n"
        ".long .Lffce9e_000fcf66\n"
        ".long .Lffce9e_000fcf7d\n"
        ".long .Lffce9e_000fcf94\n"
        ".long .Lffce9e_000fcfab\n"
        ".long .Lffce9e_000fcfc2\n"
        ".long .Lffce9e_000fcfd9\n"
        ".text\n"
    );
}

/* line 981 */
static __attribute__((naked))
jpeg_alloc Image_GetSunHalfAngleForVector(const vec_t *facePos, int ignored, byte *pixel)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 981 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x54, %esp\n"
        "movl 0x10(%ebp), %ebx\n" /* pixel */
        /* { scope 1 */
        "leal -0x14(%ebp), %eax\n" /* line 988 | dirFromEye */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* facePos */
        "movl %eax, (%esp)\n"
        "calll Vec3NormalizeTo\n"
        "fstp %st(0)\n"
        "movl imp_rgp, %eax\n"
        "movl 0x109c(%eax), %eax\n"
        "leal 0xb8(%eax), %edx\n"
        /* { scope 2 */
        "movss 0xb8(%eax), %xmm0\n" /* line 248 */
        "subss -0x14(%ebp), %xmm0\n" /* dirFromEye */
        "movss %xmm0, -0x20(%ebp)\n" /* halfAngle */
        "movss 4(%edx), %xmm0\n" /* line 249 */
        "subss -0x10(%ebp), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movss 8(%edx), %xmm0\n" /* line 250 */
        "subss -0xc(%ebp), %xmm0\n"
        "movss %xmm0, -0x18(%ebp)\n"
        /* } scope */
        "leal -0x20(%ebp), %eax\n" /* line 990 | halfAngle */
        "movl %eax, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movss lit4_002ed5d8, %xmm1\n" /* line 428 | 0.5f */
        "movss -0x18(%ebp), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "movss %xmm1, -0x48(%ebp)\n"
        "calll floorf\n"
        "fstps -0x2c(%ebp)\n"
        "cvttss2si -0x2c(%ebp), %eax\n"
        "movb %al, 3(%ebx)\n"
        "movss -0x48(%ebp), %xmm1\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x30(%ebp)\n"
        "cvttss2si -0x30(%ebp), %eax\n"
        "movb %al, 2(%ebx)\n"
        "movss -0x48(%ebp), %xmm1\n"
        "movss -0x20(%ebp), %xmm0\n" /* halfAngle */
        "mulss %xmm1, %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x34(%ebp)\n"
        "cvttss2si -0x34(%ebp), %eax\n"
        "movb %al, 1(%ebx)\n"
        "movb $0x80, (%ebx)\n" /* line 999 | pixel */
        /* } scope */
        "addl $0x54, %esp\n" /* line 1013 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1026 */
static __attribute__((naked))
jpeg_alloc Image_GetWaterColorForVector(const vec_t *facePos, int packedColor, byte *pixel)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1026 */
        "movl %esp, %ebp\n"
        "subl $0x48, %esp\n"
        /* { scope 1 */
        "leal -0x18(%ebp), %eax\n" /* line 1032 | dirFromEye */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* facePos */
        "movl %eax, (%esp)\n"
        "calll Vec3NormalizeTo\n"
        "fstp %st(0)\n"
        "movl -0x10(%ebp), %eax\n" /* line 1033 */
        "movl %eax, 8(%esp)\n"
        "movl $0x3faa9fbe, 4(%esp)\n"
        "movl $0x3f800000, (%esp)\n"
        "calll FresnelTerm\n"
        "fstps -0x2c(%ebp)\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "movl 0xc(%ebp), %eax\n" /* line 1036 | packedColor */
        "movl %eax, -0xc(%ebp)\n" /* color */
        "mulss lit4_002ed5d4, %xmm0\n" /* line 428 | 255.0f */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x1c(%ebp)\n"
        "cvttss2si -0x1c(%ebp), %eax\n"
        "movb %al, -0xc(%ebp)\n" /* color */
        "movl -0xc(%ebp), %edx\n" /* line 606 | color */
        "movl 0x10(%ebp), %eax\n" /* pixel */
        "movl %edx, (%eax)\n"
        /* } scope */
        "leave\n" /* line 1050 */
        "retl\n"
    );
}

/* line 928 */
static __attribute__((naked))
jpeg_alloc Image_GetLightGridWeightsForVector(const vec_t *facePos, int subMap, byte *pixel)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 928 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl 8(%ebp), %edx\n" /* facePos */
        "movl 0x10(%ebp), %esi\n" /* pixel */
        /* { scope 1 */
        "leal -0x24(%ebp), %ebx\n" /* line 943 | transformedPos */
        "movl %ebx, 0x10(%esp)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl (%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $lightGridLookupMatrix, (%esp)\n"
        "calll AxisTransformVector\n"
        "movl %ebx, (%esp)\n" /* line 944 */
        "calll Vec3MajorAxis\n"
        "movss -0x24(%ebp, %eax, 4), %xmm0\n" /* line 945 */
        "andps lightGridLookupMatrix+48, %xmm0\n"
        "movss lit4_002ed5d0, %xmm7\n" /* 1.0f */
        "movaps %xmm7, %xmm2\n"
        "divss %xmm0, %xmm2\n"
        "movaps %xmm2, %xmm0\n" /* line 272 */
        "mulss -0x24(%ebp), %xmm0\n" /* transformedPos */
        "movss %xmm0, -0x24(%ebp)\n" /* transformedPos */
        "movaps %xmm2, %xmm1\n" /* line 273 */
        "mulss -0x20(%ebp), %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "mulss -0x1c(%ebp), %xmm2\n" /* line 274 */
        "movss %xmm2, -0x1c(%ebp)\n"
        "mulss lit4_002ed5d8, %xmm0\n" /* line 948 | 0.5f, lerp */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f, lerp */
        /* { scope 2 */
        "movaps %xmm0, %xmm5\n" /* line 924 */
        "mulss %xmm0, %xmm5\n"
        "movss lit4_002ed628, %xmm3\n" /* -2.0f */
        "mulss %xmm3, %xmm0\n"
        "movss lit4_002ed720, %xmm6\n" /* 3.0f */
        "addss %xmm6, %xmm0\n"
        "mulss %xmm0, %xmm5\n"
        /* } scope */
        "mulss lit4_002ed5d8, %xmm1\n" /* line 949 | 0.5f, lerp */
        "addss lit4_002ed5d8, %xmm1\n" /* 0.5f, lerp */
        /* { scope 2 */
        "movaps %xmm1, %xmm4\n" /* line 924 */
        "mulss %xmm1, %xmm4\n"
        "mulss %xmm3, %xmm1\n"
        "addss %xmm6, %xmm1\n"
        "mulss %xmm1, %xmm4\n"
        /* } scope */
        "movl 0xc(%ebp), %ebx\n" /* line 950 | subMap */
        "testl %ebx, %ebx\n"
        "jne .Lffd178_000fd3bd\n"
        "movaps %xmm2, %xmm0\n" /* line 951 */
        "mulss lit4_002ed63c, %xmm0\n" /* -0.5f */
        ".Lffd178_000fd262:\n"
        "addss lit4_002ed5d8, %xmm0\n" /* line 953 | 0.5f, lerp */
        /* { scope 2 */
        "movaps %xmm0, %xmm2\n" /* line 924 */
        "mulss %xmm0, %xmm2\n"
        "mulss %xmm3, %xmm0\n"
        "addss %xmm6, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        /* } scope */
        "movaps %xmm7, %xmm0\n" /* line 955 */
        "subss %xmm4, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "movaps %xmm7, %xmm1\n"
        "subss %xmm5, %xmm1\n"
        "movaps %xmm5, %xmm3\n" /* line 956 */
        "mulss %xmm0, %xmm3\n"
        "mulss %xmm4, %xmm2\n" /* line 957 */
        "movaps %xmm1, %xmm4\n"
        "mulss %xmm2, %xmm4\n"
        "movss %xmm4, -0x30(%ebp)\n"
        "mulss %xmm2, %xmm5\n" /* line 958 */
        "movss %xmm5, -0x34(%ebp)\n"
        "mulss %xmm1, %xmm0\n" /* line 428 */
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "movss %xmm3, -0x58(%ebp)\n"
        "calll floorf\n"
        "fstps -0x38(%ebp)\n"
        "cvttss2si -0x38(%ebp), %edx\n"
        "movl %edx, %eax\n" /* line 154 */
        "subl $0xff, %eax\n"
        "movss -0x58(%ebp), %xmm3\n"
        "js .Lffd178_000fd3cd\n"
        "movl $0xff, %edx\n"
        /* { scope 2 */
        ".Lffd178_000fd2f1:\n"
        "movb %dl, -0x29(%ebp)\n"
        /* } scope */
        ".Lffd178_000fd2f4:\n"
        "mulss lit4_002ed5d4, %xmm3\n" /* line 428 | 255.0f */
        "addss lit4_002ed5d8, %xmm3\n" /* 0.5f */
        "movss %xmm3, (%esp)\n"
        "calll floorf\n"
        "fstps -0x3c(%ebp)\n"
        "cvttss2si -0x3c(%ebp), %edx\n"
        "movl %edx, %eax\n" /* line 154 */
        "subl $0xff, %eax\n"
        "js .Lffd178_000fd418\n"
        "movl $0xff, %edx\n"
        /* { scope 2 */
        ".Lffd178_000fd328:\n"
        "movl %edx, %edi\n"
        /* } scope */
        ".Lffd178_000fd32a:\n"
        "movss lit4_002ed5d4, %xmm0\n" /* line 428 | 255.0f */
        "mulss -0x30(%ebp), %xmm0\n"
        "movss lit4_002ed5d8, %xmm4\n" /* 0.5f */
        "addss %xmm0, %xmm4\n"
        "movss %xmm4, (%esp)\n"
        "calll floorf\n"
        "fstps -0x40(%ebp)\n"
        "cvttss2si -0x40(%ebp), %edx\n"
        "movl %edx, %eax\n" /* line 154 */
        "subl $0xff, %eax\n"
        "js .Lffd178_000fd405\n"
        "movl $0xff, %edx\n"
        /* { scope 2 */
        ".Lffd178_000fd367:\n"
        "movl %edx, %ebx\n"
        /* } scope */
        ".Lffd178_000fd369:\n"
        "movss lit4_002ed5d4, %xmm0\n" /* line 428 | 255.0f */
        "mulss -0x34(%ebp), %xmm0\n"
        "movss lit4_002ed5d8, %xmm4\n" /* 0.5f */
        "addss %xmm0, %xmm4\n"
        "movss %xmm4, (%esp)\n"
        "calll floorf\n"
        "fstps -0x44(%ebp)\n"
        "cvttss2si -0x44(%ebp), %edx\n"
        "movl %edx, %eax\n" /* line 154 */
        "subl $0xff, %eax\n"
        "js .Lffd178_000fd3e2\n"
        "movl $0xff, %edx\n"
        /* { scope 2 */
        ".Lffd178_000fd3a2:\n"
        "movl %edx, %eax\n"
        /* } scope */
        "movb %bl, (%esi)\n" /* line 965 | pixel */
        "movl %edi, %edx\n"
        "movb %dl, 1(%esi)\n" /* pixel */
        "movzbl -0x29(%ebp), %edx\n"
        "movb %dl, 2(%esi)\n" /* pixel */
        "movb %al, 3(%esi)\n" /* pixel */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 969 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lffd178_000fd3bd:\n"
        "movaps %xmm2, %xmm0\n" /* line 953 | lerp */
        "mulss lit4_002ed5d8, %xmm0\n" /* 0.5f, lerp */
        "jmp .Lffd178_000fd262\n"
        ".Lffd178_000fd3cd:\n"
        "movl %edx, %eax\n" /* line 154 */
        "negl %eax\n"
        /* { scope 2 */
        "testl %eax, %eax\n"
        "js .Lffd178_000fd2f1\n"
        "movb $0, -0x29(%ebp)\n"
        "jmp .Lffd178_000fd2f4\n"
        /* } scope */
        ".Lffd178_000fd3e2:\n"
        "movl %edx, %eax\n"
        "negl %eax\n"
        /* { scope 2 */
        "testl %eax, %eax\n"
        "js .Lffd178_000fd3a2\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "movb %bl, (%esi)\n" /* line 965 | pixel */
        "movl %edi, %edx\n"
        "movb %dl, 1(%esi)\n" /* pixel */
        "movzbl -0x29(%ebp), %edx\n"
        "movb %dl, 2(%esi)\n" /* pixel */
        "movb %al, 3(%esi)\n" /* pixel */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 969 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lffd178_000fd405:\n"
        "movl %edx, %eax\n" /* line 154 */
        "negl %eax\n"
        /* { scope 2 */
        "testl %eax, %eax\n"
        "js .Lffd178_000fd367\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lffd178_000fd369\n"
        /* } scope */
        ".Lffd178_000fd418:\n"
        "movl %edx, %eax\n"
        "negl %eax\n"
        /* { scope 2 */
        "testl %eax, %eax\n"
        "js .Lffd178_000fd328\n"
        "xorl %edi, %edi\n"
        "jmp .Lffd178_000fd32a\n"
    );
}

/* line 467 */
__attribute__((naked))
Bool Image_LoadFromFile(GfxImage *image)
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
        "andl $g_effectVisArray+4351, %eax\n"
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
static __attribute__((naked))
jpeg_alloc Image_GenerateCubemapFunction(GfxImage *image, byte *pic, int res, int userData, jpeg_alloc (*Callback)())
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

/* line 672 */
__attribute__((naked))
Bool Image_LoadRaw(GfxImage *image, const char *filepath, int imageTrack)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 672 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %edi\n" /* image */
        /* { scope 1 */
        "movl $0, -0x20(%ebp)\n" /* line 680 | pic */
        "leal -0x2c(%ebp), %eax\n" /* line 681 | imageFormat */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* height */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* width */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* pic */
        "movl %eax, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* file */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* filepath */
        "movl %eax, (%esp)\n"
        "calll R_LoadJpg\n"
        "movl -0x20(%ebp), %esi\n" /* line 682 | pic */
        "testl %esi, %esi\n"
        "je .Lffd920_000fd9ec\n"
        "movl -0x2c(%ebp), %ebx\n" /* line 685 | imageFormat */
        /* { scope 2 */
        "movl %ebx, 0x18(%esp)\n" /* line 570 */
        "movl $0, 0x14(%esp)\n"
        "movl $3, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl -0x28(%ebp), %eax\n" /* height */
        "movl %eax, 8(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* width */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll Image_Setup\n"
        "movl $0, (%esp)\n" /* line 575 */
        "calll Image_CubemapFace\n"
        "movl %esi, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll Image_UploadData\n"
        /* } scope */
        "movl -0x20(%ebp), %eax\n" /* line 686 | pic */
        "movl %eax, (%esp)\n"
        "calll Hunk_FreeTempMemory\n"
        "movl -0x1c(%ebp), %eax\n" /* line 687 | file */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 689 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lffd920_000fd9ec:\n"
        "xorl %eax, %eax\n" /* line 682 */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 689 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 771 */
static __attribute__((naked))
jpeg_alloc Image_LoadLightmapWeights(GfxImage *image)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 771 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x108c, %esp\n"
        "leal -0x1024(%ebp), %edi\n" /* pic */
        "movl $0, -0x1034(%ebp)\n" /* t */
        /* { scope 1 */
        ".Lffd9f6_000fda12:\n"
        "cvtsi2ssl -0x1034(%ebp), %xmm0\n" /* line 792 | t */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss lit4_002ed878, %xmm1\n" /* 0.03125f */
        "mulss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "subss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x20(%ebp)\n"
        "xorl %esi, %esi\n" /* s */
        "jmp .Lffd9f6_000fdbe1\n"
        ".Lffd9f6_000fda46:\n"
        "subss lit4_002ed5d0, %xmm1\n" /* line 743 | 1.0f */
        "movss %xmm1, -0x102c(%ebp)\n"
        "movss lit4_002ed5d0, %xmm1\n" /* line 745 | 1.0f */
        "subss -0x102c(%ebp), %xmm1\n"
        "pxor %xmm2, %xmm2\n"
        ".Lffd9f6_000fda6a:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 757 */
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0x1058(%ebp)\n"
        "movss %xmm2, -0x1068(%ebp)\n"
        "calll acosf\n"
        "fstps -0x1074(%ebp)\n"
        "movss -0x1074(%ebp), %xmm0\n"
        "divss lit4_002ed88c, %xmm0\n" /* -0.9553166031837463f */
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        "addss %xmm3, %xmm0\n"
        "pxor %xmm4, %xmm4\n" /* line 759 */
        "ucomiss %xmm0, %xmm4\n"
        "movss -0x1058(%ebp), %xmm1\n"
        "movss -0x1068(%ebp), %xmm2\n"
        "ja .Lffd9f6_000fdcf4\n"
        "ucomiss %xmm3, %xmm0\n" /* line 761 */
        "jbe .Lffd9f6_000fdd04\n"
        "movl $0, -0x1030(%ebp)\n"
        "movss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        ".Lffd9f6_000fdadf:\n"
        "leal (%edi, %esi, 4), %ebx\n" /* line 771 */
        "addss lit4_002ed5d8, %xmm0\n" /* line 428 | 0.5f */
        "movss %xmm0, (%esp)\n"
        "movss %xmm1, -0x1058(%ebp)\n"
        "movss %xmm2, -0x1068(%ebp)\n"
        "calll floorf\n"
        "fstps -0x1038(%ebp)\n"
        "cvttss2si -0x1038(%ebp), %eax\n"
        "movb %al, (%ebx)\n"
        "movss -0x1068(%ebp), %xmm2\n"
        "mulss -0x1030(%ebp), %xmm2\n"
        "mulss lit4_002ed5d4, %xmm2\n" /* 255.0f */
        "addss lit4_002ed5d8, %xmm2\n" /* 0.5f */
        "movss %xmm2, (%esp)\n"
        "calll floorf\n"
        "fstps -0x103c(%ebp)\n"
        "cvttss2si -0x103c(%ebp), %eax\n"
        "movb %al, 1(%ebx)\n"
        "movss -0x1058(%ebp), %xmm1\n"
        "mulss -0x1030(%ebp), %xmm1\n"
        "mulss lit4_002ed5d4, %xmm1\n" /* 255.0f */
        "addss lit4_002ed5d8, %xmm1\n" /* 0.5f */
        "movss %xmm1, (%esp)\n"
        "calll floorf\n"
        "fstps -0x1040(%ebp)\n"
        "cvttss2si -0x1040(%ebp), %eax\n"
        "movb %al, 2(%ebx)\n"
        "movss -0x1030(%ebp), %xmm0\n"
        "mulss -0x102c(%ebp), %xmm0\n"
        "movss lit4_002ed5d4, %xmm1\n" /* 255.0f */
        "mulss %xmm0, %xmm1\n"
        "movss lit4_002ed5d8, %xmm3\n" /* 0.5f */
        "addss %xmm1, %xmm3\n"
        "movss %xmm3, (%esp)\n"
        "calll floorf\n"
        "fstps -0x1044(%ebp)\n"
        "cvttss2si -0x1044(%ebp), %eax\n"
        "movb %al, 3(%ebx)\n"
        "addl $1, %esi\n" /* line 793 | s */
        "cmpl $0x20, %esi\n" /* s */
        "je .Lffd9f6_000fdd3b\n"
        "movss lit4_002ed878, %xmm1\n" /* 0.03125f */
        ".Lffd9f6_000fdbe1:\n"
        "cvtsi2ssl %esi, %xmm0\n" /* line 795 | s */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "mulss %xmm1, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "subss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x24(%ebp)\n" /* dir */
        "movss -0x20(%ebp), %xmm1\n" /* line 126 */
        "mulss %xmm0, %xmm0\n" /* line 796 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "subss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "pxor %xmm3, %xmm3\n" /* line 797 */
        "ucomiss %xmm1, %xmm3\n"
        "ja .Lffd9f6_000fdd25\n"
        ".Lffd9f6_000fdc2f:\n"
        "sqrtss %xmm0, %xmm0\n" /* line 81 */
        "movss %xmm0, -0x1c(%ebp)\n"
        "cvtss2sd -0x24(%ebp), %xmm0\n" /* line 728 | dir */
        "cvtss2sd -0x20(%ebp), %xmm1\n"
        "movsd %xmm0, 8(%esp)\n"
        "movsd %xmm1, (%esp)\n"
        "calll atan2\n"
        "fstpl -0x1070(%ebp)\n"
        "movsd -0x1070(%ebp), %xmm0\n"
        "mulsd lit8_00307cf8, %xmm0\n" /* 0.477464829275686 */
        "subsd lit8_00307d00, %xmm0\n" /* 0.75 */
        "cvtsd2ss %xmm0, %xmm1\n"
        "pxor %xmm0, %xmm0\n" /* line 729 */
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lffd9f6_000fdcea\n"
        "ucomiss lit4_002ed720, %xmm1\n" /* line 731 | 3.0f */
        "jbe .Lffd9f6_000fdc8e\n"
        "subss lit4_002ed720, %xmm1\n" /* line 732 | 3.0f */
        ".Lffd9f6_000fdc8e:\n"
        "movss lit4_002ed5d0, %xmm3\n" /* line 734 | 1.0f */
        "ucomiss %xmm1, %xmm3\n"
        "ja .Lffd9f6_000fdcd4\n"
        "movss lit4_002ed62c, %xmm0\n" /* line 741 | 2.0f */
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lffd9f6_000fda46\n"
        "movaps %xmm1, %xmm2\n" /* line 750 */
        "subss lit4_002ed62c, %xmm2\n" /* 2.0f */
        "movss lit4_002ed5d0, %xmm1\n" /* line 753 | 1.0f */
        "subss %xmm2, %xmm1\n"
        "movss %xmm1, -0x102c(%ebp)\n"
        "pxor %xmm1, %xmm1\n"
        "jmp .Lffd9f6_000fda6a\n"
        ".Lffd9f6_000fdcd4:\n"
        "movaps %xmm3, %xmm2\n" /* line 737 */
        "subss %xmm1, %xmm2\n"
        "movl $0, -0x102c(%ebp)\n"
        "jmp .Lffd9f6_000fda6a\n"
        ".Lffd9f6_000fdcea:\n"
        "addss lit4_002ed720, %xmm1\n" /* line 730 | 3.0f */
        "jmp .Lffd9f6_000fdc8e\n"
        ".Lffd9f6_000fdcf4:\n"
        "movss %xmm3, -0x1030(%ebp)\n" /* line 759 */
        "movaps %xmm4, %xmm0\n"
        "jmp .Lffd9f6_000fdadf\n"
        ".Lffd9f6_000fdd04:\n"
        "movss lit4_002ed5d0, %xmm3\n" /* line 761 | 1.0f */
        "subss %xmm0, %xmm3\n"
        "movss %xmm3, -0x1030(%ebp)\n"
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "jmp .Lffd9f6_000fdadf\n"
        ".Lffd9f6_000fdd25:\n"
        "leal -0x24(%ebp), %eax\n" /* line 799 | dir */
        "movl %eax, (%esp)\n"
        "calll Vec2Normalize\n"
        "fstp %st(0)\n"
        "pxor %xmm0, %xmm0\n"
        "jmp .Lffd9f6_000fdc2f\n"
        ".Lffd9f6_000fdd3b:\n"
        "subl $-0x80, %edi\n" /* line 793 | dest */
        "addl $1, -0x1034(%ebp)\n" /* line 790 | t */
        "cmpl $0x20, -0x1034(%ebp)\n" /* t */
        "jne .Lffd9f6_000fda12\n"
        "movl $0x15, 0x18(%esp)\n" /* line 570 */
        "movl $0, 0x14(%esp)\n"
        "movl $3, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl $0x20, 8(%esp)\n"
        "movl $0x20, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* image */
        "movl %eax, (%esp)\n"
        "calll Image_Setup\n"
        "movl $0, (%esp)\n" /* line 575 */
        "calll Image_CubemapFace\n"
        "leal -0x1024(%ebp), %edx\n" /* pic */
        "movl %edx, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x15, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* image */
        "movl %eax, (%esp)\n"
        "calll Image_UploadData\n"
        /* } scope */
        "addl $0x108c, %esp\n" /* line 831 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1165 */
__attribute__((naked))
GfxImage * Image_Load(const char *name, int semantic, int imageTrack)
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
        "orl $scrMemTreeGlob+39168, %ecx\n"
        "andl $g_effectVisArray+4351, %ecx\n"
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

