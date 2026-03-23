/* ASM dump from: MacFiles.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacFiles.cp */

#include "common_types.h"
#include "imports.h"
#include <unistd.h>

void MacFiles_CleanPath(const char *inPath, char *outPath, int inForHFS);
static void RemoveDirectoryContents(void);
OSStatus MacFiles_RemoveDirectoryA(const char *inPath);
int MacFiles_access(const char *inPath, int inMode);

/* line 183 */
void MacFiles_CleanPath(const char *inPath, char *outPath, int inForHFS)
{
    const char *src;
    char *dst;
    char c;

    src = inPath;
    dst = outPath;

    c = *src;
    while (c != '\0') {
        if (c == '\\') {
            c = inForHFS ? ':' : '/';
        }
        *dst = c;
        dst++;
        src++;
        c = *src;
    }
    *dst = '\0';
}

/* overload skip: MacFiles_CleanPath (0x8d38) */

static void RemoveDirectoryContents(void)
{
}

OSStatus MacFiles_RemoveDirectoryA(const char *inPath)
{
    return 0;
}

/* line 75 */
int MacFiles_access(const char *inPath, int inMode)
{
    char tempPath[1024];
    const char *src;
    char *dst;
    char c;

    src = inPath;
    dst = tempPath;

    c = *src;
    while (c != '\0') {
        if (c == '\\') {
            c = '/';
        }
        *dst = c;
        dst++;
        src++;
        c = *src;
    }
    *dst = '\0';

    return access(tempPath, inMode);
}

