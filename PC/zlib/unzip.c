/* ASM dump from: unzip.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/zlib/unzip.c */

#include "common_types.h"
#include "imports.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
    UNZ_OK = 0,
    UNZ_ERRNO = -1,
    UNZ_END_OF_LIST_OF_FILE = -100,
    UNZ_PARAMERROR = -102,
    UNZ_BADZIPFILE = -103,
    UNZ_INTERNALERROR = -104,
    UNZ_BUFSIZE = 0x4000,
    UNZ_LOCAL_HEADER_SIZE = 0x1e,
    UNZ_SIZECENTRALDIRITEM = 0x2e
};

enum {
    Z_DEFLATED = 8,
    Z_SYNC_FLUSH = 2
};

extern FILE *FS_FileOpen(const char *filename, const char *mode);
extern size_t FS_FileRead(void *ptr, size_t size, size_t nitems, FILE *stream);
extern int FS_FileClose(FILE *stream);
extern int FS_FileSeek(FILE *file, long int offset, int whence);
extern int inflate(z_streamp strm, int flush);
extern int inflateEnd(z_streamp strm);
extern int inflateInit2_(z_streamp strm, int windowBits, const char *version, int stream_size);

unzFile unzReOpen(const char *path, unzFile file);
int unzGetGlobalInfo(unzFile file, unz_global_info *pglobal_info);
int unzGetCurrentFileInfoPosition(unzFile file, long unsigned int *pos);
int unzReadCurrentFile(unzFile file, voidp buf, unsigned int len);
long int unztell(unzFile file);
int unzCloseCurrentFile(unzFile file);
static int __attribute__((regparm(3))) unzlocal_GetCurrentFileInfoInternal(
    unzFile file,
    unz_file_info *pfile_info,
    unz_file_info_internal *pfile_info_internal,
    char *szFileName,
    uLong fileNameBufferSize,
    double *extraField,
    uLong extraFieldBufferSize,
    char *szComment,
    uLong commentBufferSize);
int unzSetCurrentFileInfoPosition(unzFile file, long unsigned int pos);
int unzGoToNextFile(unzFile file);
int unzGoToFirstFile(unzFile file);
int unzGetCurrentFileInfo(unzFile file, unz_file_info *pfile_info, char *szFileName, uLong fileNameBufferSize, double *extraField, uLong extraFieldBufferSize, char *szComment, uLong commentBufferSize);
unzFile unzOpen(const char *path);
int unzClose(unzFile file);
int unzOpenCurrentFile(unzFile file);

static int unzlocal_ReadShort(FILE *file, uLong *value)
{
    unsigned short raw;

    if (FS_FileRead(&raw, sizeof(raw), 1, file) != 1)
        return UNZ_BADZIPFILE;

    *value = raw;
    return UNZ_OK;
}

static int unzlocal_ReadLong(FILE *file, uLong *value)
{
    uLong raw;

    if (FS_FileRead(&raw, sizeof(raw), 1, file) != 1)
        return UNZ_BADZIPFILE;

    *value = raw;
    return UNZ_OK;
}

static int unzlocal_CheckCurrentFileCoherencyHeader(
    unz_s *s,
    uInt *sizeVar,
    uLong *offsetLocalExtrafield,
    uInt *sizeLocalExtrafield)
{
    uLong value;
    uLong flags;
    uLong sizeFilename;
    uLong sizeExtraField;
    int err;

    *sizeVar = 0;
    *offsetLocalExtrafield = 0;
    *sizeLocalExtrafield = 0;

    if (FS_FileSeek(
            s->file,
            s->cur_file_info_internal.offset_curfile + s->byte_before_the_zipfile,
            SEEK_SET) != 0) {
        return UNZ_BADZIPFILE;
    }

    err = unzlocal_ReadLong(s->file, &value);
    if (err != UNZ_OK || value != 0x04034b50)
        return UNZ_BADZIPFILE;

    if (unzlocal_ReadShort(s->file, &value) != UNZ_OK)
        return UNZ_BADZIPFILE;

    if (unzlocal_ReadShort(s->file, &flags) != UNZ_OK)
        return UNZ_BADZIPFILE;

    err = unzlocal_ReadShort(s->file, &value);
    if (err != UNZ_OK || value != s->cur_file_info.compression_method)
        return UNZ_BADZIPFILE;

    if (value != 0 && value != Z_DEFLATED)
        return UNZ_BADZIPFILE;

    if (unzlocal_ReadLong(s->file, &value) != UNZ_OK)
        return UNZ_BADZIPFILE;

    err = unzlocal_ReadLong(s->file, &value);
    if (err != UNZ_OK)
        return UNZ_BADZIPFILE;
    if (value != s->cur_file_info.crc && (flags & 8) == 0)
        return UNZ_BADZIPFILE;

    err = unzlocal_ReadLong(s->file, &value);
    if (err != UNZ_OK)
        return UNZ_BADZIPFILE;
    if (value != s->cur_file_info.compressed_size && (flags & 8) == 0)
        return UNZ_BADZIPFILE;

    err = unzlocal_ReadLong(s->file, &value);
    if (err != UNZ_OK)
        return UNZ_BADZIPFILE;
    if (value != s->cur_file_info.uncompressed_size && (flags & 8) == 0)
        return UNZ_BADZIPFILE;

    err = unzlocal_ReadShort(s->file, &sizeFilename);
    if (err != UNZ_OK || sizeFilename != s->cur_file_info.size_filename)
        return UNZ_BADZIPFILE;

    *sizeVar += (uInt)sizeFilename;

    if (unzlocal_ReadShort(s->file, &sizeExtraField) != UNZ_OK)
        return UNZ_BADZIPFILE;

    *offsetLocalExtrafield = s->cur_file_info_internal.offset_curfile
        + UNZ_LOCAL_HEADER_SIZE
        + sizeFilename;
    *sizeLocalExtrafield = (uInt)sizeExtraField;
    *sizeVar += (uInt)sizeExtraField;
    return UNZ_OK;
}

static uLong unzlocal_SearchCentralDir(FILE *file)
{
    unsigned char *buffer;
    uLong fileSize;
    uLong backRead;
    uLong maxBack;
    uLong posFound;

    if (FS_FileSeek(file, 0, SEEK_END) != 0)
        return 0;

    fileSize = (uLong)ftell(file);
    maxBack = 0xffff;
    if (maxBack > fileSize)
        maxBack = fileSize;

    buffer = (unsigned char *)malloc(0x404);
    if (buffer == NULL)
        return 0;

    posFound = 0;
    backRead = 4;
    while (backRead < maxBack) {
        uLong readPos;
        uLong readSize;
        int i;

        if (backRead + 0x400 > maxBack)
            backRead = maxBack;
        else
            backRead += 0x400;

        readPos = fileSize - backRead;
        readSize = 0x404;
        if (readSize > fileSize - readPos)
            readSize = fileSize - readPos;

        if (FS_FileSeek(file, readPos, SEEK_SET) != 0)
            break;

        if (FS_FileRead(buffer, 1, readSize, file) != readSize)
            break;

        for (i = (int)readSize - 4; i >= 0; --i) {
            if (buffer[i] == 0x50 && buffer[i + 1] == 0x4b &&
                buffer[i + 2] == 0x05 && buffer[i + 3] == 0x06) {
                posFound = readPos + (uLong)i;
                break;
            }
        }

        if (posFound != 0)
            break;
    }

    free(buffer);
    return posFound;
}

/* line 326 */
unzFile unzReOpen(const char *path, unzFile file)
{
    FILE *fin;
    unz_s *reopened;

    fin = FS_FileOpen(path, "rb");
    if (fin == NULL)
        return NULL;

    reopened = (unz_s *)malloc(sizeof(*reopened));
    if (reopened == NULL) {
        FS_FileClose(fin);
        return NULL;
    }

    memcpy(reopened, (const unz_s *)file, sizeof(*reopened));
    reopened->file = fin;
    reopened->pfile_in_zip_read = NULL;
    return (unzFile)reopened;
}

/* line 472 */
int unzGetGlobalInfo(unzFile file, unz_global_info *pglobal_info)
{
    unz_s *s;

    if (file == NULL)
        return UNZ_PARAMERROR;

    s = (unz_s *)file;
    *pglobal_info = s->gi;
    return UNZ_OK;
}

/* line 757 */
int unzGetCurrentFileInfoPosition(unzFile file, long unsigned int *pos)
{
    unz_s *s;

    if (file == NULL)
        return UNZ_PARAMERROR;

    s = (unz_s *)file;
    *pos = s->pos_in_central_dir;
    return UNZ_OK;
}

/* line 1043 */
int unzReadCurrentFile(unzFile file, voidp buf, unsigned int len)
{
    int err;
    unsigned int readCount;
    unz_s *s;
    file_in_zip_read_info_s *readInfo;

    if (file == NULL)
        return UNZ_PARAMERROR;

    s = (unz_s *)file;
    readInfo = s->pfile_in_zip_read;
    if (readInfo == NULL)
        return UNZ_PARAMERROR;

    if (readInfo->read_buffer == NULL)
        return UNZ_END_OF_LIST_OF_FILE;

    if (len == 0)
        return 0;

    readInfo->stream.next_out = (Bytef *)buf;
    readInfo->stream.avail_out = len;
    if (len > readInfo->rest_read_uncompressed)
        readInfo->stream.avail_out = readInfo->rest_read_uncompressed;

    err = UNZ_OK;
    readCount = 0;

    while (readInfo->stream.avail_out > 0) {
        if (readInfo->stream.avail_in == 0 && readInfo->rest_read_compressed > 0) {
            unsigned int readThis = UNZ_BUFSIZE;

            if (readInfo->rest_read_compressed < readThis)
                readThis = readInfo->rest_read_compressed;

            if (FS_FileSeek(
                    readInfo->file,
                    readInfo->pos_in_zipfile + readInfo->byte_before_the_zipfile,
                    SEEK_SET) != 0) {
                return UNZ_ERRNO;
            }

            if (FS_FileRead(readInfo->read_buffer, readThis, 1, readInfo->file) != 1)
                return UNZ_ERRNO;

            readInfo->pos_in_zipfile += readThis;
            readInfo->rest_read_compressed -= readThis;
            readInfo->stream.next_in = (Bytef *)readInfo->read_buffer;
            readInfo->stream.avail_in = readThis;
        }

        if (readInfo->compression_method == 0) {
            unsigned int copyCount = readInfo->stream.avail_out;

            if (copyCount > readInfo->stream.avail_in)
                copyCount = readInfo->stream.avail_in;

            if (copyCount > 0)
                memcpy(readInfo->stream.next_out, readInfo->stream.next_in, copyCount);

            readInfo->rest_read_uncompressed -= copyCount;
            readInfo->stream.avail_in -= copyCount;
            readInfo->stream.avail_out -= copyCount;
            readInfo->stream.next_out += copyCount;
            readInfo->stream.next_in += copyCount;
            readInfo->stream.total_out += copyCount;
            readCount += copyCount;
            continue;
        }

        {
            uLong totalOutBefore = readInfo->stream.total_out;

            err = inflate(&readInfo->stream, Z_SYNC_FLUSH);
            readInfo->rest_read_uncompressed -= readInfo->stream.total_out - totalOutBefore;
            readCount += readInfo->stream.total_out - totalOutBefore;

            if (err == 1)
                return readCount;
            if (err == UNZ_OK)
                continue;
            return err;
        }
    }

    return err == UNZ_OK ? (int)readCount : err;
}

/* line 1174 */
long int unztell(unzFile file)
{
    unz_s *s;
    file_in_zip_read_info_s *readInfo;

    if (file == NULL)
        return UNZ_PARAMERROR;

    s = (unz_s *)file;
    readInfo = s->pfile_in_zip_read;
    if (readInfo == NULL)
        return UNZ_PARAMERROR;

    return readInfo->stream.total_out;
}

/* line 1274 */
int unzCloseCurrentFile(unzFile file)
{
    unz_s *s;
    file_in_zip_read_info_s *readInfo;

    if (file == NULL)
        return UNZ_PARAMERROR;

    s = (unz_s *)file;
    readInfo = s->pfile_in_zip_read;
    if (readInfo == NULL)
        return UNZ_PARAMERROR;

    free(readInfo->read_buffer);
    readInfo->read_buffer = NULL;

    if (readInfo->stream_initialised)
        inflateEnd(&readInfo->stream);

    readInfo->stream_initialised = 0;
    free(readInfo);
    s->pfile_in_zip_read = NULL;
    return UNZ_OK;
}

/* line 522 */
static __attribute__((naked, regparm(3)))
int unzlocal_GetCurrentFileInfoInternal(unzFile file, unz_file_info *pfile_info, unz_file_info_internal *pfile_info_internal, char *szFileName, uLong fileNameBufferSize, double *extraField, uLong extraFieldBufferSize, char *szComment, uLong commentBufferSize)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 522 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl %eax, %ebx\n" /* file */
        "movl %edx, %edi\n" /* pfile_info */
        "movl %ecx, -0x94(%ebp)\n"
        /* { scope 1: v, uSizeRead */
        "testl %eax, %eax\n" /* line 540 */
        "je .Lf27c08_0002810e\n"
        "movl $0, 8(%esp)\n" /* line 543 */
        "movl 0x14(%eax), %eax\n"
        "addl 0xc(%ebx), %eax\n" /* file */
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n" /* file */
        "movl %eax, (%esp)\n"
        "calll FS_FileSeek\n"
        "movl %eax, %esi\n"
        "testl %eax, %eax\n"
        "je .Lf27c08_000280ca\n"
        "movl $0xffffffff, -0x90(%ebp)\n" /* err */
        /* { scope 2 */
        ".Lf27c08_00027c56:\n"
        "movl (%ebx), %eax\n" /* line 120 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "leal -0x1c(%ebp), %edx\n" /* v */
        "movl %edx, (%esp)\n"
        "calll FS_FileRead\n"
        "movswl -0x1c(%ebp), %ecx\n" /* line 124 | v */
        "movl %ecx, -0x34(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 120 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* v */
        "movl %eax, (%esp)\n"
        "calll FS_FileRead\n"
        "movswl -0x1c(%ebp), %edx\n" /* line 124 | v */
        "movl %edx, -0x38(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 120 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "leal -0x1c(%ebp), %ecx\n" /* v */
        "movl %ecx, (%esp)\n"
        "calll FS_FileRead\n"
        "movswl -0x1c(%ebp), %eax\n" /* line 124 | v */
        "movl %eax, -0x3c(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 120 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "leal -0x1c(%ebp), %edx\n" /* v */
        "movl %edx, (%esp)\n"
        "calll FS_FileRead\n"
        "movswl -0x1c(%ebp), %ecx\n" /* line 124 | v */
        "movl %ecx, -0x40(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 162 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* v */
        "movl %eax, (%esp)\n"
        "calll FS_FileRead\n"
        "movl -0x1c(%ebp), %edx\n" /* line 166 | v */
        "movl %edx, -0x44(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "shrl $0x10, %edx\n" /* line 493 */
        "movl %edx, %ecx\n" /* line 494 */
        "andl $0x1f, %ecx\n"
        "movl %ecx, -0x48(%ebp)\n"
        "movl %edx, %eax\n" /* line 495 */
        "andl $0x1e0, %eax\n"
        "shrl $5, %eax\n"
        "subl $1, %eax\n"
        "movl %eax, -0x8c(%ebp)\n"
        "shrl $9, %edx\n" /* line 496 */
        "addl $0x7bc, %edx\n"
        "movl %edx, -0x88(%ebp)\n"
        "movl -0x44(%ebp), %eax\n" /* line 498 */
        "andl $0xf800, %eax\n"
        "shrl $0xb, %eax\n"
        "movl %eax, -0x84(%ebp)\n"
        "movl -0x44(%ebp), %edx\n" /* line 499 */
        "andl $0x7e0, %edx\n"
        "shrl $5, %edx\n"
        "movl %edx, -0x80(%ebp)\n"
        "movl -0x44(%ebp), %eax\n" /* line 500 */
        "andl $0x1f, %eax\n"
        "addl %eax, %eax\n"
        "movl %eax, -0x7c(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 162 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "leal -0x1c(%ebp), %ecx\n" /* v */
        "movl %ecx, (%esp)\n"
        "calll FS_FileRead\n"
        "movl -0x1c(%ebp), %eax\n" /* line 166 | v */
        "movl %eax, -0x4c(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 162 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "leal -0x1c(%ebp), %edx\n" /* v */
        "movl %edx, (%esp)\n"
        "calll FS_FileRead\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 166 | v */
        "movl %ecx, -0x50(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 162 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* v */
        "movl %eax, (%esp)\n"
        "calll FS_FileRead\n"
        "movl -0x1c(%ebp), %edx\n" /* line 166 | v */
        "movl %edx, -0x54(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 120 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "leal -0x1c(%ebp), %ecx\n" /* v */
        "movl %ecx, (%esp)\n"
        "calll FS_FileRead\n"
        "movl -0x1c(%ebp), %eax\n" /* line 124 | v */
        "movw %ax, -0x76(%ebp)\n"
        "movswl %ax, %edx\n"
        "movl %edx, -0x58(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 120 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "leal -0x1c(%ebp), %ecx\n" /* v */
        "movl %ecx, (%esp)\n"
        "calll FS_FileRead\n"
        "movl -0x1c(%ebp), %eax\n" /* line 124 | v */
        "movw %ax, -0x74(%ebp)\n"
        "movswl %ax, %edx\n"
        "movl %edx, -0x5c(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 120 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "leal -0x1c(%ebp), %ecx\n" /* v */
        "movl %ecx, (%esp)\n"
        "calll FS_FileRead\n"
        "movl -0x1c(%ebp), %eax\n" /* line 124 | v */
        "movw %ax, -0x72(%ebp)\n"
        "movswl %ax, %edx\n"
        "movl %edx, -0x60(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 120 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "leal -0x1c(%ebp), %ecx\n" /* v */
        "movl %ecx, (%esp)\n"
        "calll FS_FileRead\n"
        "movswl -0x1c(%ebp), %eax\n" /* line 124 | v */
        "movl %eax, -0x64(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 120 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "leal -0x1c(%ebp), %edx\n" /* v */
        "movl %edx, (%esp)\n"
        "calll FS_FileRead\n"
        "movswl -0x1c(%ebp), %ecx\n" /* line 124 | v */
        "movl %ecx, -0x68(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 162 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* v */
        "movl %eax, (%esp)\n"
        "calll FS_FileRead\n"
        "movl -0x1c(%ebp), %edx\n" /* line 166 | v */
        "movl %edx, -0x6c(%ebp)\n"
        /* } scope */
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 162 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "leal -0x1c(%ebp), %ecx\n" /* v */
        "movl %ecx, (%esp)\n"
        "calll FS_FileRead\n"
        "movl -0x1c(%ebp), %eax\n" /* line 166 | v */
        "movl %eax, -0x30(%ebp)\n"
        /* } scope */
        "movl -0x58(%ebp), %esi\n" /* line 601 */
        "movl -0x90(%ebp), %eax\n" /* line 602 | err */
        "testl %eax, %eax\n"
        "je .Lf27c08_00028031\n"
        ".Lf27c08_00027f23:\n"
        "movl -0x5c(%ebp), %eax\n" /* line 639 */
        "addl %esi, %eax\n" /* uSizeRead */
        ".Lf27c08_00027f28:\n"
        "movl -0x90(%ebp), %ecx\n" /* line 642 | err */
        "testl %ecx, %ecx\n"
        "jne .Lf27c08_00028020\n"
        "movl 0x18(%ebp), %edx\n" /* szComment */
        "testl %edx, %edx\n"
        "je .Lf27c08_00027f83\n"
        /* { scope 2 */
        "movl 0x1c(%ebp), %edx\n" /* line 645 | commentBufferSize */
        "cmpl %edx, -0x60(%ebp)\n"
        "jae .Lf27c08_00027f4f\n"
        "movl 0x18(%ebp), %ecx\n" /* line 647 | szComment */
        "movl -0x60(%ebp), %edx\n"
        "movb $0, (%ecx, %edx)\n"
        ".Lf27c08_00027f4f:\n"
        "movl %edx, %esi\n" /* uSizeRead */
        "testl %eax, %eax\n" /* line 653 */
        "jne .Lf27c08_0002816f\n"
        ".Lf27c08_00027f59:\n"
        "movl $0, -0x90(%ebp)\n" /* line 654 | err */
        ".Lf27c08_00027f63:\n"
        "cmpw $0, -0x72(%ebp)\n" /* line 658 */
        "je .Lf27c08_00027f75\n"
        "movl 0x1c(%ebp), %eax\n" /* commentBufferSize */
        "testl %eax, %eax\n"
        "jne .Lf27c08_0002813a\n"
        /* } scope */
        ".Lf27c08_00027f75:\n"
        "movl -0x90(%ebp), %eax\n" /* line 666 | err */
        "testl %eax, %eax\n"
        "jne .Lf27c08_00028020\n"
        ".Lf27c08_00027f83:\n"
        "testl %edi, %edi\n" /* pfile_info */
        "je .Lf27c08_0002800b\n"
        "movl -0x6c(%ebp), %eax\n" /* line 667 */
        "movl %eax, 0x34(%edi)\n" /* pfile_info */
        "movl -0x68(%ebp), %edx\n"
        "movl %edx, 0x30(%edi)\n" /* pfile_info */
        "movl -0x64(%ebp), %ecx\n"
        "movl %ecx, 0x2c(%edi)\n" /* pfile_info */
        "movl -0x60(%ebp), %eax\n"
        "movl %eax, 0x28(%edi)\n" /* pfile_info */
        "movl -0x5c(%ebp), %edx\n"
        "movl %edx, 0x24(%edi)\n" /* pfile_info */
        "movl -0x58(%ebp), %ecx\n"
        "movl %ecx, 0x20(%edi)\n" /* pfile_info */
        "movl -0x54(%ebp), %eax\n"
        "movl %eax, 0x1c(%edi)\n" /* pfile_info */
        "movl -0x50(%ebp), %edx\n"
        "movl %edx, 0x18(%edi)\n" /* pfile_info */
        "movl -0x4c(%ebp), %ecx\n"
        "movl %ecx, 0x14(%edi)\n" /* pfile_info */
        "movl -0x7c(%ebp), %eax\n"
        "movl %eax, 0x38(%edi)\n" /* pfile_info */
        "movl -0x80(%ebp), %edx\n"
        "movl %edx, 0x3c(%edi)\n" /* pfile_info */
        "movl -0x84(%ebp), %ecx\n"
        "movl %ecx, 0x40(%edi)\n" /* pfile_info */
        "movl -0x88(%ebp), %eax\n"
        "movl %eax, 0x4c(%edi)\n" /* pfile_info */
        "movl -0x8c(%ebp), %edx\n"
        "movl %edx, 0x48(%edi)\n" /* pfile_info */
        "movl -0x48(%ebp), %ecx\n"
        "movl %ecx, 0x44(%edi)\n" /* pfile_info */
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 0x10(%edi)\n" /* pfile_info */
        "movl -0x40(%ebp), %edx\n"
        "movl %edx, 0xc(%edi)\n" /* pfile_info */
        "movl -0x3c(%ebp), %ecx\n"
        "movl %ecx, 8(%edi)\n" /* pfile_info */
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 4(%edi)\n" /* pfile_info */
        "movl -0x34(%ebp), %edx\n"
        "movl %edx, (%edi)\n" /* pfile_info */
        ".Lf27c08_0002800b:\n"
        "movl -0x94(%ebp), %eax\n" /* line 669 */
        "testl %eax, %eax\n"
        "je .Lf27c08_00028020\n"
        "movl -0x30(%ebp), %eax\n" /* line 670 */
        "movl -0x94(%ebp), %ecx\n"
        "movl %eax, (%ecx)\n"
        /* } scope */
        ".Lf27c08_00028020:\n"
        "movl -0x90(%ebp), %eax\n" /* line 673 | err */
        "addl $0x9c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: v, uSizeRead */
        ".Lf27c08_00028031:\n"
        "movl 8(%ebp), %eax\n" /* line 602 | szFileName */
        "testl %eax, %eax\n"
        "je .Lf27c08_00028076\n"
        /* { scope 2 */
        "movl 0xc(%ebp), %edx\n" /* line 605 | fileNameBufferSize */
        "cmpl %edx, %esi\n" /* uSizeRead */
        "jb .Lf27c08_00028129\n"
        "movl %edx, %esi\n" /* uSizeRead */
        ".Lf27c08_00028045:\n"
        "cmpw $0, -0x76(%ebp)\n" /* line 613 */
        "je .Lf27c08_00028057\n"
        "movl 0xc(%ebp), %eax\n" /* fileNameBufferSize */
        "testl %eax, %eax\n"
        "jne .Lf27c08_00028219\n"
        ".Lf27c08_00028057:\n"
        "movl $0, -0x90(%ebp)\n" /* line 614 | err */
        ".Lf27c08_00028061:\n"
        "movl -0x58(%ebp), %ecx\n" /* line 616 */
        "subl %esi, %ecx\n" /* uSizeRead */
        "movl %ecx, %esi\n" /* uSizeRead */
        /* } scope */
        "movl -0x90(%ebp), %eax\n" /* line 620 | err */
        "testl %eax, %eax\n"
        "jne .Lf27c08_00027f23\n"
        ".Lf27c08_00028076:\n"
        "movl 0x10(%ebp), %eax\n" /* extraField */
        "testl %eax, %eax\n"
        "je .Lf27c08_00027f23\n"
        /* { scope 2 */
        "movl 0x14(%ebp), %eax\n" /* line 623 | extraFieldBufferSize */
        "cmpl %eax, -0x5c(%ebp)\n"
        "jae .Lf27c08_0002819c\n"
        "movl -0x5c(%ebp), %edx\n"
        "movl %edx, -0x70(%ebp)\n" /* uSizeRead */
        "movl $0, -0x2c(%ebp)\n"
        ".Lf27c08_0002809a:\n"
        "testl %esi, %esi\n" /* line 628 | uSizeRead */
        "jne .Lf27c08_000281ad\n"
        ".Lf27c08_000280a2:\n"
        "movl $0, -0x90(%ebp)\n" /* line 629 | err */
        "xorl %esi, %esi\n" /* uSizeRead */
        ".Lf27c08_000280ae:\n"
        "cmpw $0, -0x74(%ebp)\n" /* line 633 */
        "je .Lf27c08_000280c0\n"
        "movl 0x14(%ebp), %eax\n" /* extraFieldBufferSize */
        "testl %eax, %eax\n"
        "jne .Lf27c08_000281da\n"
        ".Lf27c08_000280c0:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 636 */
        "addl %esi, %eax\n" /* uSizeRead */
        "jmp .Lf27c08_00027f28\n"
        /* } scope */
        /* { scope 2 */
        ".Lf27c08_000280ca:\n"
        "movl (%ebx), %eax\n" /* line 162 */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* v */
        "movl %eax, (%esp)\n"
        "calll FS_FileRead\n"
        /* } scope */
        "movl $0xffffff99, -0x90(%ebp)\n" /* line 551 | err */
        "cmpl $0x2014b50, -0x1c(%ebp)\n" /* v */
        "cmovnel -0x90(%ebp), %esi\n" /* err */
        "movl %esi, -0x90(%ebp)\n" /* err */
        "jmp .Lf27c08_00027c56\n"
        ".Lf27c08_0002810e:\n"
        "movl $0xffffff9a, -0x90(%ebp)\n" /* line 540 | err */
        /* } scope */
        "movl -0x90(%ebp), %eax\n" /* line 673 | err */
        "addl $0x9c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: v, uSizeRead */
        /* { scope 2 */
        ".Lf27c08_00028129:\n"
        "movl 8(%ebp), %ecx\n" /* line 607 | szFileName */
        "movl -0x58(%ebp), %eax\n"
        "movb $0, (%ecx, %eax)\n"
        "movl %eax, %esi\n" /* uSizeRead */
        "jmp .Lf27c08_00028045\n"
        /* } scope */
        /* { scope 2 */
        ".Lf27c08_0002813a:\n"
        "movl (%ebx), %eax\n" /* line 659 | file */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* uSizeRead */
        "movl 0x18(%ebp), %ecx\n" /* szComment */
        "movl %ecx, (%esp)\n"
        "calll FS_FileRead\n"
        "subl $1, %eax\n"
        "je .Lf27c08_00027f75\n"
        "movl $0xffffffff, -0x90(%ebp)\n" /* err */
        "jmp .Lf27c08_00028020\n"
        ".Lf27c08_0002816f:\n"
        "movl $1, 8(%esp)\n" /* line 654 */
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n" /* file */
        "movl %eax, (%esp)\n"
        "calll FS_FileSeek\n"
        "testl %eax, %eax\n"
        "je .Lf27c08_00027f59\n"
        "movl $0xffffffff, -0x90(%ebp)\n" /* err */
        "jmp .Lf27c08_00027f63\n"
        /* } scope */
        /* { scope 2 */
        ".Lf27c08_0002819c:\n"
        "movl -0x5c(%ebp), %ecx\n" /* line 623 */
        "subl 0x14(%ebp), %ecx\n" /* extraFieldBufferSize */
        "movl %ecx, -0x2c(%ebp)\n"
        "movl %eax, -0x70(%ebp)\n" /* uSizeRead */
        "jmp .Lf27c08_0002809a\n"
        ".Lf27c08_000281ad:\n"
        "movl $1, 8(%esp)\n" /* line 629 */
        "movl %esi, 4(%esp)\n" /* uSizeRead */
        "movl (%ebx), %eax\n" /* file */
        "movl %eax, (%esp)\n"
        "calll FS_FileSeek\n"
        "testl %eax, %eax\n"
        "je .Lf27c08_000280a2\n"
        "movl $0xffffffff, -0x90(%ebp)\n" /* err */
        "jmp .Lf27c08_000280ae\n"
        ".Lf27c08_000281da:\n"
        "movl (%ebx), %eax\n" /* line 634 | file */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl -0x70(%ebp), %edx\n" /* uSizeRead */
        "movl %edx, 4(%esp)\n"
        "movl 0x10(%ebp), %ecx\n" /* extraField */
        "movl %ecx, (%esp)\n"
        "calll FS_FileRead\n"
        "subl $1, %eax\n"
        "movl $0xffffffff, %eax\n"
        "cmovel -0x90(%ebp), %eax\n" /* err */
        "movl %eax, -0x90(%ebp)\n" /* err */
        "movl -0x2c(%ebp), %eax\n" /* line 636 */
        "addl %esi, %eax\n" /* uSizeRead */
        "jmp .Lf27c08_00027f28\n"
        /* } scope */
        /* { scope 2 */
        ".Lf27c08_00028219:\n"
        "movl (%ebx), %eax\n" /* line 614 | file */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* uSizeRead */
        "movl 8(%ebp), %edx\n" /* szFileName */
        "movl %edx, (%esp)\n"
        "calll FS_FileRead\n"
        "subl $1, %eax\n"
        "je .Lf27c08_00028057\n"
        "movl $0xffffffff, -0x90(%ebp)\n" /* err */
        "jmp .Lf27c08_00028061\n"
    );
}

/* line 773 */
int unzSetCurrentFileInfoPosition(unzFile file, long unsigned int pos)
{
    int err;
    unz_s *s;

    if (file == NULL)
        return UNZ_PARAMERROR;

    s = (unz_s *)file;
    s->pos_in_central_dir = pos;
    err = unzlocal_GetCurrentFileInfoInternal(
        file,
        &s->cur_file_info,
        &s->cur_file_info_internal,
        NULL,
        0,
        NULL,
        0,
        NULL,
        0);
    s->current_file_ok = (err == UNZ_OK);
    return UNZ_OK;
}

/* line 729 */
int unzGoToNextFile(unzFile file)
{
    int err;
    unz_s *s;

    if (file == NULL)
        return UNZ_PARAMERROR;

    s = (unz_s *)file;
    if (!s->current_file_ok)
        return UNZ_END_OF_LIST_OF_FILE;

    if (s->num_file + 1 == s->gi.number_entry)
        return UNZ_END_OF_LIST_OF_FILE;

    s->pos_in_central_dir += UNZ_SIZECENTRALDIRITEM
        + s->cur_file_info.size_filename
        + s->cur_file_info.size_file_extra
        + s->cur_file_info.size_file_comment;
    s->num_file++;

    err = unzlocal_GetCurrentFileInfoInternal(
        file,
        &s->cur_file_info,
        &s->cur_file_info_internal,
        NULL,
        0,
        NULL,
        0,
        NULL,
        0);
    s->current_file_ok = (err == UNZ_OK);
    return err;
}

/* line 706 */
int unzGoToFirstFile(unzFile file)
{
    int err;
    unz_s *s;

    if (file == NULL)
        return UNZ_PARAMERROR;

    s = (unz_s *)file;
    s->pos_in_central_dir = s->offset_central_dir;
    s->num_file = 0;
    err = unzlocal_GetCurrentFileInfoInternal(
        file,
        &s->cur_file_info,
        &s->cur_file_info_internal,
        NULL,
        0,
        NULL,
        0,
        NULL,
        0);
    s->current_file_ok = (err == UNZ_OK);
    return err;
}

/* line 686 */
int unzGetCurrentFileInfo(unzFile file, unz_file_info *pfile_info, char *szFileName, uLong fileNameBufferSize, double *extraField, uLong extraFieldBufferSize, char *szComment, uLong commentBufferSize)
{
    return unzlocal_GetCurrentFileInfoInternal(
        file,
        pfile_info,
        NULL,
        szFileName,
        fileNameBufferSize,
        extraField,
        extraFieldBufferSize,
        szComment,
        commentBufferSize);
}

/* line 352 */
unzFile unzOpen(const char *path)
{
    int err;
    uLong centralPos;
    uLong ignored;
    uLong numberDisk;
    uLong numberDiskWithCd;
    uLong numberEntryCd;
    unz_s us;
    unz_s *s;

    memset(&us, 0, sizeof(us));
    us.file = FS_FileOpen(path, "rb");
    if (us.file == NULL)
        return NULL;

    err = UNZ_OK;
    centralPos = unzlocal_SearchCentralDir(us.file);
    if (centralPos == 0)
        err = UNZ_ERRNO;

    if (err == UNZ_OK && FS_FileSeek(us.file, centralPos, SEEK_SET) != 0)
        err = UNZ_ERRNO;

    if (err == UNZ_OK && unzlocal_ReadLong(us.file, &ignored) != UNZ_OK)
        err = UNZ_ERRNO;

    if (err == UNZ_OK && unzlocal_ReadShort(us.file, &numberDisk) != UNZ_OK)
        err = UNZ_ERRNO;

    if (err == UNZ_OK && unzlocal_ReadShort(us.file, &numberDiskWithCd) != UNZ_OK)
        err = UNZ_ERRNO;

    if (err == UNZ_OK && unzlocal_ReadShort(us.file, &us.gi.number_entry) != UNZ_OK)
        err = UNZ_ERRNO;

    if (err == UNZ_OK && unzlocal_ReadShort(us.file, &numberEntryCd) != UNZ_OK)
        err = UNZ_ERRNO;

    if (err == UNZ_OK &&
        (numberEntryCd != us.gi.number_entry || numberDiskWithCd != 0 || numberDisk != 0)) {
        err = UNZ_BADZIPFILE;
    }

    if (err == UNZ_OK && unzlocal_ReadLong(us.file, &us.size_central_dir) != UNZ_OK)
        err = UNZ_ERRNO;

    if (err == UNZ_OK && unzlocal_ReadLong(us.file, &us.offset_central_dir) != UNZ_OK)
        err = UNZ_ERRNO;

    if (err == UNZ_OK && unzlocal_ReadShort(us.file, &us.gi.size_comment) != UNZ_OK)
        err = UNZ_ERRNO;

    if (err == UNZ_OK && centralPos < us.offset_central_dir + us.size_central_dir)
        err = UNZ_BADZIPFILE;

    if (err != UNZ_OK) {
        FS_FileClose(us.file);
        return NULL;
    }

    us.byte_before_the_zipfile = centralPos - (us.offset_central_dir + us.size_central_dir);
    us.central_pos = centralPos;
    us.pfile_in_zip_read = NULL;

    s = (unz_s *)malloc(sizeof(*s));
    if (s == NULL) {
        FS_FileClose(us.file);
        return NULL;
    }

    *s = us;
    unzGoToFirstFile((unzFile)s);
    return (unzFile)s;
}

/* line 451 */
int unzClose(unzFile file)
{
    unz_s *s;

    if (file == NULL)
        return UNZ_PARAMERROR;

    s = (unz_s *)file;
    if (s->pfile_in_zip_read != NULL)
        unzCloseCurrentFile(file);

    FS_FileClose(s->file);
    free(s);
    return UNZ_OK;
}

/* line 941 */
int unzOpenCurrentFile(unzFile file)
{
    int err;
    uInt sizeVar;
    uLong offsetLocalExtrafield;
    uInt sizeLocalExtrafield;
    unz_s *s;
    file_in_zip_read_info_s *readInfo;

    if (file == NULL)
        return UNZ_PARAMERROR;

    s = (unz_s *)file;
    if (!s->current_file_ok)
        return UNZ_PARAMERROR;

    if (s->pfile_in_zip_read != NULL)
        unzCloseCurrentFile(file);

    err = unzlocal_CheckCurrentFileCoherencyHeader(
        s,
        &sizeVar,
        &offsetLocalExtrafield,
        &sizeLocalExtrafield);
    if (err != UNZ_OK)
        return err;

    readInfo = (file_in_zip_read_info_s *)malloc(sizeof(*readInfo));
    if (readInfo == NULL)
        return UNZ_INTERNALERROR;

    memset(readInfo, 0, sizeof(*readInfo));
    readInfo->read_buffer = (char *)malloc(UNZ_BUFSIZE);
    readInfo->offset_local_extrafield = offsetLocalExtrafield;
    readInfo->size_local_extrafield = sizeLocalExtrafield;

    if (readInfo->read_buffer == NULL) {
        free(readInfo);
        return UNZ_INTERNALERROR;
    }

    readInfo->compression_method = s->cur_file_info.compression_method;
    readInfo->file = s->file;
    readInfo->byte_before_the_zipfile = s->byte_before_the_zipfile;
    readInfo->stream.total_out = 0;

    if (readInfo->compression_method != 0) {
        if (inflateInit2_(&readInfo->stream, -15, str_00215d44, sizeof(readInfo->stream)) == UNZ_OK)
            readInfo->stream_initialised = 1;
    }

    readInfo->rest_read_compressed = s->cur_file_info.compressed_size;
    readInfo->rest_read_uncompressed = s->cur_file_info.uncompressed_size;
    readInfo->pos_in_zipfile =
        s->cur_file_info_internal.offset_curfile + UNZ_LOCAL_HEADER_SIZE + sizeVar;
    readInfo->stream.avail_in = 0;

    s->pfile_in_zip_read = readInfo;
    return UNZ_OK;
}
