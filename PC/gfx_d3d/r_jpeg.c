/* Converted to C from ASM: r_jpeg.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_jpeg.cpp */

#include "common_types.h"
#include "imports.h"

extern void * jpeg_std_error(void *jerr, void (*exitFunc)(void), void (*printFunc)(char *));
extern void jpeg_CreateCompress(void *cinfo, int version, int structsize);
extern void jpeg_set_defaults(void *cinfo);
extern void jpeg_set_quality(void *cinfo, int quality, int force_baseline);
extern void jpeg_start_compress(void *cinfo, int write_all_tables);
extern void jpeg_write_scanlines(void *cinfo, byte **scanlines, int num_lines);
extern void jpeg_finish_compress(void *cinfo);
extern void jpeg_destroy_compress(void *cinfo);
extern void jpeg_CreateDecompress(void *cinfo, int version, int structsize);
extern void jpeg_memory_src(void *cinfo, byte *data, int size);
extern int jpeg_read_header(void *cinfo, int require_image);
extern void jpeg_start_decompress(void *cinfo);
extern void jpeg_read_scanlines(void *cinfo, byte **scanlines, int num_lines);
extern void jpeg_finish_decompress(void *cinfo);
extern void jpeg_destroy_decompress(void *cinfo);

extern byte *r_sys_ptr;     /* imp_ri - renderer system vtable */
extern byte *r_limits_ptr;  /* imp_vidConfig - renderer limits */

static int hackSize; /* hackSize */

static void init_destination(j_compress_ptr cinfo);
boolean empty_output_buffer(j_compress_ptr cinfo);
static void term_destination(j_compress_ptr cinfo);
static void * Z_MallocJpeg(size_t size);
static void Z_FreeJpeg(void *ptr, size_t size);
static void ExitJpeg(void);
static void PrintfJpeg(char *message);
void R_SaveJpg(const char *filename, int quality, int image_width, int image_height, unsigned char *image_buffer);
void R_LoadJpg(const char *filepath, byte * *file, byte * *pic, int *width, int *height, D3DFORMAT *imageFormat);

/* line 23 */
static void init_destination(j_compress_ptr cinfo)
{
    byte *cb = (byte *)cinfo;
    byte *dest = *(byte **)(cb + 0x20);

    *(int *)dest = *(int *)(dest + 0x14);       /* dest->next_output_byte = dest->buffer */
    *(int *)(dest + 4) = *(int *)(dest + 0x18); /* dest->free_in_buffer = dest->bufsize */
}

/* line 55 */
boolean empty_output_buffer(j_compress_ptr cinfo)
{
    return 1;
}

/* line 72 */
static void term_destination(j_compress_ptr cinfo)
{
    byte *cb = (byte *)cinfo;
    byte *dest = *(byte **)(cb + 0x20);

    hackSize = *(int *)(dest + 0x18) - *(int *)(dest + 4);
}

/* line 111 */
static void * Z_MallocJpeg(size_t size)
{
    byte *sys = *(byte **)r_sys_ptr;
    void *(*mallocFunc)(size_t) = *(void *(**)(size_t))(sys + 0x14);
    return mallocFunc(size);
}

/* line 117 */
static void Z_FreeJpeg(void *ptr, size_t size)
{
    byte *sys = *(byte **)r_sys_ptr;
    void (*freeFunc)(void *, size_t) = *(void (**)(void *, size_t))(sys + 0x18);
    freeFunc(ptr, size);
}

/* line 123 */
static void ExitJpeg(void)
{
    byte *sys = *(byte **)r_sys_ptr;
    void (*errFunc)(int, const char *) = *(void (**)(int, const char *))(sys + 4);
    errFunc(0, "jpeg internal error");
}

/* line 129 */
static void PrintfJpeg(char *message)
{
    byte *sys = *(byte **)r_sys_ptr;
    void (*printFunc)(int, const char *, ...) = *(void (**)(int, const char *, ...))(sys);
    printFunc(0, "%s\n", message);
}

/* line 135 */
void R_SaveJpg(const char *filename, int quality, int image_width, int image_height, unsigned char *image_buffer)
{
    byte cinfo_buf[0x16c + 0x48];
    byte jerr[0xa8];
    byte *cinfo = cinfo_buf;
    byte *out;
    int bufSize;
    byte *row_pointer;
    byte *sys;
    byte *dest;

    jpeg_std_error(jerr, ExitJpeg, PrintfJpeg);
    *(void **)(cinfo) = jerr;  /* cinfo.err */
    *(void **)(cinfo + 0x18) = Z_MallocJpeg;
    *(void **)(cinfo + 0x1c) = Z_FreeJpeg;

    jpeg_CreateCompress(cinfo, 0x3e, 0x16c);

    /* Allocate output buffer: width * height * 3 */
    bufSize = image_width * image_height * 3;
    sys = *(byte **)r_sys_ptr;
    out = ((byte *(*)(int))*(void **)(sys + 0x10))(bufSize);

    /* Setup destination manager */
    dest = *(byte **)(cinfo + 0x20);
    if (dest == NULL) {
        /* Allocate destination struct */
        void *(*allocFunc)(void *, int, int) = *(void *(**)(void *, int, int))(*(byte **)(cinfo + 4));
        dest = (byte *)allocFunc(cinfo, 0, 0x1c);
        *(byte **)(cinfo + 0x20) = dest;
    }
    *(void **)(dest + 8) = init_destination;
    *(void **)(dest + 0xc) = empty_output_buffer;
    *(void **)(dest + 0x10) = term_destination;
    *(void **)(dest + 0x14) = out;
    *(int *)(dest + 0x18) = bufSize;

    /* Set image parameters */
    *(int *)(cinfo + 0x24) = image_width;
    *(int *)(cinfo + 0x28) = image_height;
    *(int *)(cinfo + 0x2c) = 3;  /* num_components = 3 (RGB) */
    *(int *)(cinfo + 0x30) = 2;  /* color_space = JCS_RGB */

    jpeg_set_defaults(cinfo);
    jpeg_set_quality(cinfo, quality, 1);
    jpeg_start_compress(cinfo, 1);

    /* Write scanlines */
    {
        int row_stride = image_width * 3;
        while (*(unsigned int *)(cinfo + 0xd4) < *(unsigned int *)(cinfo + 0x28)) {
            row_pointer = image_buffer + *(int *)(cinfo + 0xd4) * row_stride;
            jpeg_write_scanlines(cinfo, &row_pointer, 1);
        }
    }

    jpeg_finish_compress(cinfo);

    /* Write file and free buffer */
    sys = *(byte **)r_sys_ptr;
    ((void (*)(const char *, byte *, int))*(void **)(sys + 0x140))(filename, out, hackSize);
    ((void (*)(byte *))*(void **)(sys + 0x30))(out);

    jpeg_destroy_compress(cinfo);
}

/* line 248 */
void R_LoadJpg(const char *filepath, byte * *file, byte * *pic, int *width, int *height, D3DFORMAT *imageFormat)
{
    byte cinfo_buf[0x1b4 + 0x48];
    byte jerr[0xa8];
    byte *cinfo = cinfo_buf;
    byte *fbuffer;
    int filesize;
    byte *sys;
    byte *limits;
    int maxSize;
    byte *buf;
    int row_stride;
    int output_width;
    int output_height;
    int num_components;
    byte *row_ptr;
    int x;

    sys = *(byte **)r_sys_ptr;
    filesize = ((int (*)(const char *, byte **))*(void **)(sys + 0x128))(filepath, &fbuffer);

    if (fbuffer == NULL)
        return;

    jpeg_std_error(jerr, ExitJpeg, PrintfJpeg);
    *(void **)(cinfo) = jerr;
    *(void **)(cinfo + 0x18) = Z_MallocJpeg;
    *(void **)(cinfo + 0x1c) = Z_FreeJpeg;

    jpeg_CreateDecompress(cinfo, 0x3e, 0x1b4);
    jpeg_memory_src(cinfo, fbuffer, filesize);
    jpeg_read_header(cinfo, 1);
    jpeg_start_decompress(cinfo);

    output_width = *(int *)(cinfo + 0x68);
    output_height = *(int *)(cinfo + 0x6c);

    /* Check max texture size */
    limits = *(byte **)r_limits_ptr;
    maxSize = *(int *)(limits + 0x18);
    if (output_width > maxSize || output_height > maxSize) {
        ((void (*)(int, const char *, ...))*(void **)(sys))(2, "WARNING: image '%s' is larger than %i on at least one side\n", filepath, maxSize);
        jpeg_destroy_decompress(cinfo);
        ((void (*)(byte *))*(void **)(sys + 0x12c))(fbuffer);
        return;
    }

    /* Check color space */
    num_components = *(int *)(cinfo + 0x74);
    if (num_components != 3) {
        sys = *(byte **)r_sys_ptr;
        ((void (*)(int, const char *, ...))*(void **)(sys))(2, "WARNING: jpeg image '%s' is not RGB\n", filepath);
        jpeg_destroy_decompress(cinfo);
        ((void (*)(byte *))*(void **)((*(byte **)r_sys_ptr) + 0x12c))(fbuffer);
        return;
    }

    *width = output_width;
    *height = output_height;
    *imageFormat = (D3DFORMAT)0x15;

    /* Allocate RGBA buffer */
    sys = *(byte **)r_sys_ptr;
    buf = ((byte *(*)(int))*(void **)(sys + 0x10))(output_width * output_height * 4);
    *pic = buf;

    row_stride = output_width * 4;
    *file = fbuffer;

    /* Read and convert scanlines from RGB to RGBA */
    while (output_height > *(int *)(cinfo + 0x84)) {
        row_ptr = buf;
        jpeg_read_scanlines(cinfo, &row_ptr, 1);

        /* Convert RGB to RGBA in reverse order to avoid overwriting */
        output_width = *(int *)(cinfo + 0x68);
        for (x = output_width - 1; x >= 0; x--) {
            int srcOffset = x * num_components;
            buf[x * 4 + 3] = 0xff;
            buf[x * 4 + 2] = buf[srcOffset + 2];
            buf[x * 4 + 1] = buf[srcOffset + 1];
            buf[x * 4 + 0] = buf[srcOffset + 0];
        }

        buf += row_stride;
    }

    jpeg_finish_decompress(cinfo);
    jpeg_destroy_decompress(cinfo);
}
