/* ASM dump from: r_jpeg.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_jpeg.cpp */

#include "common_types.h"
#include "imports.h"

static int hackSize; /* 0xff1e00 */

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
static __attribute__((naked))
void init_destination(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 23 */
        "movl %esp, %ebp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 25 | cinfo, dest */
        "movl 0x20(%eax), %eax\n" /* dest */
        "movl 0x14(%eax), %edx\n" /* line 27 */
        "movl %edx, (%eax)\n"
        "movl 0x18(%eax), %edx\n" /* line 28 */
        "movl %edx, 4(%eax)\n"
        /* } scope */
        "popl %ebp\n" /* line 29 */
        "retl\n"
    );
}

/* line 55 */
__attribute__((naked))
boolean empty_output_buffer(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 55 */
        "movl %esp, %ebp\n"
        "movl $1, %eax\n" /* line 58 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 72 */
static __attribute__((naked))
void term_destination(j_compress_ptr cinfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 72 */
        "movl %esp, %ebp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 74 | cinfo */
        "movl 0x20(%eax), %edx\n" /* dest */
        "movl 0x18(%edx), %eax\n" /* line 77 */
        "subl 4(%edx), %eax\n"
        "movl %eax, hackSize\n"
        /* } scope */
        "popl %ebp\n" /* line 78 */
        "retl\n"
    );
}

/* line 111 */
static __attribute__((naked))
void * Z_MallocJpeg(size_t size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 111 */
        "movl %esp, %ebp\n"
        "movl 0x195eee0, %eax\n" /* line 113 */
        "movl 0x14(%eax), %ecx\n"
        "popl %ebp\n" /* line 114 */
        "jmpl *%ecx\n" /* line 113 */
    );
}

/* line 117 */
static __attribute__((naked))
void Z_FreeJpeg(void *ptr, size_t size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 117 */
        "movl %esp, %ebp\n"
        "movl 0x195eee0, %eax\n" /* line 119 */
        "movl 0x18(%eax), %ecx\n"
        "popl %ebp\n" /* line 120 */
        "jmpl *%ecx\n" /* line 119 */
    );
}

/* line 123 */
static __attribute__((naked))
void ExitJpeg(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 123 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x2b8de4, 4(%esp)\n" /* line 125 */
        "movl $0, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *4(%eax)\n"
        "leave\n" /* line 126 */
        "retl\n"
    );
}

/* line 129 */
static __attribute__((naked))
void PrintfJpeg(char *message)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 129 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 131 | message */
        "movl %eax, 8(%esp)\n"
        "movl $0x215bbc, 4(%esp)\n" /* "%s
" */
        "movl $0, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *(%eax)\n"
        "leave\n" /* line 132 */
        "retl\n"
    );
}

/* line 135 */
__attribute__((naked))
void R_SaveJpg(const char *filename, int quality, int image_width, int image_height, unsigned char *image_buffer)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 135 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x21c, %esp\n"
        /* { scope 1 */
        "movl $PrintfJpeg, 8(%esp)\n" /* line 167 */
        "movl $ExitJpeg, 4(%esp)\n"
        "leal -0xa8(%ebp), %eax\n" /* jerr */
        "movl %eax, (%esp)\n"
        "calll jpeg_std_error\n"
        "movl %eax, -0x214(%ebp)\n" /* cinfo */
        "movl $Z_MallocJpeg, -0x1fc(%ebp)\n" /* line 168 */
        "movl $Z_FreeJpeg, -0x1f8(%ebp)\n" /* line 169 */
        "movl $0x16c, 8(%esp)\n" /* line 172 */
        "movl $0x3e, 4(%esp)\n"
        "leal -0x214(%ebp), %esi\n" /* cinfo */
        "movl %esi, (%esp)\n"
        "calll jpeg_CreateCompress\n"
        "movl 0x10(%ebp), %eax\n" /* line 182 | image_width */
        "imull 0x14(%ebp), %eax\n" /* image_height */
        "leal (%eax, %eax, 2), %ebx\n"
        "movl %ebx, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *0x10(%eax)\n"
        "movl %eax, %edi\n" /* out */
        /* { scope 2 */
        "movl -0x1f4(%ebp), %eax\n" /* line 97 */
        "testl %eax, %eax\n"
        "je .Lf1e75b0_001e7731\n"
        "movl -0x1f4(%ebp), %eax\n"
        ".Lf1e75b0_001e763d:\n"
        "movl $init_destination, 8(%eax)\n" /* line 103 */
        "movl $empty_output_buffer, 0xc(%eax)\n" /* line 104 */
        "movl $term_destination, 0x10(%eax)\n" /* line 105 */
        "movl %edi, 0x14(%eax)\n" /* line 106 */
        "movl %ebx, 0x18(%eax)\n" /* line 107 */
        /* } scope */
        "movl 0x10(%ebp), %eax\n" /* line 190 | image_width */
        "movl %eax, -0x1f0(%ebp)\n"
        "movl 0x14(%ebp), %eax\n" /* line 191 | image_height */
        "movl %eax, -0x1ec(%ebp)\n"
        "movl $3, -0x1e8(%ebp)\n" /* line 192 */
        "movl $2, -0x1e4(%ebp)\n" /* line 193 */
        "movl %esi, (%esp)\n" /* line 198 */
        "calll jpeg_set_defaults\n"
        "movl $1, 8(%esp)\n" /* line 202 */
        "movl 0xc(%ebp), %eax\n" /* quality */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll jpeg_set_quality\n"
        "movl $1, 4(%esp)\n" /* line 209 */
        "movl %esi, (%esp)\n"
        "calll jpeg_start_compress\n"
        "movl 0x10(%ebp), %eax\n" /* line 219 | image_width */
        "leal (%eax, %eax, 2), %ebx\n"
        "movl -0x140(%ebp), %eax\n" /* line 221 */
        "cmpl -0x1ec(%ebp), %eax\n"
        "jb .Lf1e75b0_001e7701\n"
        ".Lf1e75b0_001e76c1:\n"
        "movl %esi, (%esp)\n" /* line 233 */
        "calll jpeg_finish_compress\n"
        "movl 0x195eee0, %ebx\n" /* line 235 */
        "movl hackSize, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* out */
        "movl 8(%ebp), %eax\n" /* filename */
        "movl %eax, (%esp)\n"
        "calll *0x140(%ebx)\n"
        "movl %edi, (%esp)\n" /* line 237 | out */
        "calll *0x30(%ebx)\n"
        "movl %esi, (%esp)\n" /* line 242 */
        "calll jpeg_destroy_compress\n"
        /* } scope */
        "addl $0x21c, %esp\n" /* line 245 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e75b0_001e7701:\n"
        "imull %ebx, %eax\n" /* line 227 */
        "addl 0x18(%ebp), %eax\n" /* image_buffer */
        "movl %eax, -0x1c(%ebp)\n" /* row_pointer */
        "movl $1, 8(%esp)\n" /* line 228 */
        "leal -0x1c(%ebp), %eax\n" /* row_pointer */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll jpeg_write_scanlines\n"
        "movl -0x140(%ebp), %eax\n" /* line 221 */
        "cmpl -0x1ec(%ebp), %eax\n"
        "jb .Lf1e75b0_001e7701\n"
        "jmp .Lf1e75b0_001e76c1\n"
        /* { scope 2 */
        ".Lf1e75b0_001e7731:\n"
        "movl $0x1c, 8(%esp)\n" /* line 99 */
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "movl -0x210(%ebp), %eax\n"
        "calll *(%eax)\n"
        "movl %eax, -0x1f4(%ebp)\n"
        "jmp .Lf1e75b0_001e763d\n"
    );
}

/* line 248 */
__attribute__((naked))
void R_LoadJpg(const char *filepath, byte * *file, byte * *pic, int *width, int *height, D3DFORMAT *imageFormat)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 248 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x27c, %esp\n"
        "movl 8(%ebp), %edi\n" /* filepath */
        /* { scope 1 */
        "leal -0x1c(%ebp), %eax\n" /* line 287 | fbuffer */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* filepath */
        "movl 0x195eee0, %edx\n"
        "calll *0x128(%edx)\n"
        "movl %eax, %ebx\n" /* filesize */
        "movl -0x1c(%ebp), %edx\n" /* line 288 | fbuffer */
        "testl %edx, %edx\n"
        "je .Lf1e7758_001e785d\n"
        "movl $PrintfJpeg, 8(%esp)\n" /* line 300 */
        "movl $ExitJpeg, 4(%esp)\n"
        "leal -0xac(%ebp), %eax\n" /* jerr */
        "movl %eax, (%esp)\n"
        "calll jpeg_std_error\n"
        "movl %eax, -0x260(%ebp)\n" /* cinfo */
        "movl $Z_MallocJpeg, -0x248(%ebp)\n" /* line 301 */
        "movl $Z_FreeJpeg, -0x244(%ebp)\n" /* line 302 */
        "movl $0x1b4, 8(%esp)\n" /* line 305 */
        "movl $0x3e, 4(%esp)\n"
        "leal -0x260(%ebp), %esi\n" /* cinfo */
        "movl %esi, (%esp)\n"
        "calll jpeg_CreateDecompress\n"
        "movl %ebx, 8(%esp)\n" /* line 309 | filesize */
        "movl -0x1c(%ebp), %eax\n" /* fbuffer */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll jpeg_memory_src\n"
        "movl $1, 4(%esp)\n" /* line 313 */
        "movl %esi, (%esp)\n"
        "calll jpeg_read_header\n"
        "movl %esi, (%esp)\n" /* line 328 */
        "calll jpeg_start_decompress\n"
        "movl -0x1fc(%ebp), %edx\n" /* line 333 */
        "movl 0x195eeec, %eax\n"
        "movl 0x18(%eax), %eax\n"
        "cmpl %eax, %edx\n"
        "ja .Lf1e7758_001e7825\n"
        "cmpl -0x1f8(%ebp), %eax\n"
        "jae .Lf1e7758_001e7868\n"
        ".Lf1e7758_001e7825:\n"
        "movl %eax, 0xc(%esp)\n" /* line 335 */
        "movl %edi, 8(%esp)\n" /* filepath */
        "movl $0x2b8df8, 4(%esp)\n" /* "WARNING: image '%s' is larger than %i on at least one side
" */
        "movl $2, (%esp)\n"
        "movl 0x195eee0, %ecx\n"
        "calll *(%ecx)\n"
        "movl %esi, (%esp)\n" /* line 336 */
        "calll jpeg_destroy_decompress\n"
        "movl -0x1c(%ebp), %eax\n" /* line 337 | fbuffer */
        "movl %eax, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *0x12c(%eax)\n"
        /* } scope */
        ".Lf1e7758_001e785d:\n"
        "addl $0x27c, %esp\n" /* line 414 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e7758_001e7868:\n"
        "cmpl $3, -0x1f0(%ebp)\n" /* line 341 */
        "je .Lf1e7758_001e78b1\n"
        "movl %edi, 8(%esp)\n" /* line 343 | filepath */
        "movl $0x2b8e34, 4(%esp)\n" /* "WARNING: jpeg image '%s' is not RGB
" */
        "movl $2, (%esp)\n"
        "movl 0x195eee0, %edx\n"
        "calll *(%edx)\n"
        "movl %esi, (%esp)\n" /* line 344 */
        "calll jpeg_destroy_decompress\n"
        "movl -0x1c(%ebp), %eax\n" /* line 345 | fbuffer */
        "movl %eax, (%esp)\n"
        "movl 0x195eee0, %ecx\n"
        "calll *0x12c(%ecx)\n"
        /* } scope */
        "addl $0x27c, %esp\n" /* line 414 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e7758_001e78b1:\n"
        "movl 0x14(%ebp), %eax\n" /* line 349 | width */
        "movl %edx, (%eax)\n"
        "movl -0x1f8(%ebp), %eax\n" /* line 350 */
        "movl 0x18(%ebp), %ecx\n" /* height */
        "movl %eax, (%ecx)\n"
        "movl 0x1c(%ebp), %eax\n" /* line 351 | imageFormat */
        "movl $0x15, (%eax)\n"
        "imull -0x1f8(%ebp), %edx\n" /* line 361 */
        "leal (, %edx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "movl 0x195eee0, %edx\n"
        "calll *0x10(%edx)\n"
        "movl %eax, %ebx\n" /* filesize */
        "movl 0x10(%ebp), %ecx\n" /* line 362 | pic */
        "movl %eax, (%ecx)\n"
        "movl -0x1fc(%ebp), %eax\n" /* line 363 */
        "shll $2, %eax\n"
        "movl %eax, -0x26c(%ebp)\n" /* row_stride */
        "movl -0x1c(%ebp), %eax\n" /* line 364 | fbuffer */
        "movl 0xc(%ebp), %edx\n" /* file */
        "movl %eax, (%edx)\n"
        "movl -0x1f8(%ebp), %eax\n" /* line 372 */
        "cmpl -0x1e0(%ebp), %eax\n"
        "ja .Lf1e7758_001e7939\n"
        ".Lf1e7758_001e7910:\n"
        "movl %esi, (%esp)\n" /* line 393 */
        "calll jpeg_finish_decompress\n"
        "movl %esi, (%esp)\n" /* line 401 */
        "calll jpeg_destroy_decompress\n"
        "jmp .Lf1e7758_001e785d\n"
        ".Lf1e7758_001e7925:\n"
        "addl -0x26c(%ebp), %ebx\n" /* line 388 | row_stride, filesize */
        "movl -0x1f8(%ebp), %eax\n" /* line 372 */
        "cmpl -0x1e0(%ebp), %eax\n"
        "jbe .Lf1e7758_001e7910\n"
        ".Lf1e7758_001e7939:\n"
        "movl %ebx, -0x20(%ebp)\n" /* line 378 | filesize, bbuf */
        "movl $1, 8(%esp)\n" /* line 380 */
        "leal -0x20(%ebp), %ecx\n" /* bbuf */
        "movl %ecx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll jpeg_read_scanlines\n"
        "movl -0x1fc(%ebp), %eax\n" /* line 381 */
        "subl $1, %eax\n"
        "js .Lf1e7758_001e7925\n"
        "leal 3(%ebx, %eax, 4), %ecx\n" /* line 248 */
        "movl %eax, %edx\n"
        "movl $0xffffffff, %edi\n" /* filepath */
        ".Lf1e7758_001e7969:\n"
        "movb $0xff, (%ecx)\n" /* line 383 */
        "movl %edx, %eax\n" /* line 384 */
        "imull -0x1f0(%ebp), %eax\n"
        "movzbl 2(%ebx, %eax), %eax\n" /* filesize */
        "movb %al, -1(%ecx)\n"
        "movl %edx, %eax\n" /* line 385 */
        "imull -0x1f0(%ebp), %eax\n"
        "movzbl 1(%ebx, %eax), %eax\n" /* filesize */
        "movb %al, -2(%ecx)\n"
        "movl %edx, %eax\n" /* line 386 */
        "imull -0x1f0(%ebp), %eax\n"
        "movzbl (%ebx, %eax), %eax\n" /* filesize */
        "movb %al, -3(%ecx)\n"
        "subl $1, %edx\n" /* line 381 */
        "subl $4, %ecx\n"
        "cmpl %edi, %edx\n" /* filepath */
        "jne .Lf1e7758_001e7969\n"
        "addl -0x26c(%ebp), %ebx\n" /* line 388 | row_stride, filesize */
        "movl -0x1f8(%ebp), %eax\n" /* line 372 */
        "cmpl -0x1e0(%ebp), %eax\n"
        "ja .Lf1e7758_001e7939\n"
        "jmp .Lf1e7758_001e7910\n"
    );
}

