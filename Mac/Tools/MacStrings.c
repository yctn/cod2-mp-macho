/* ASM dump from: MacStrings.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacStrings.cp */

#include "common_types.h"
#include "imports.h"

void MacStrings_CopyAndClean(const char *inSrcString, char *inDstString, int inDstSize);

/* line 33 */
void MacStrings_GetCString(const HFSUniStr255 *inUniStr, char *outCString, int inMaxString)
{
    CFStringRef stringRef;

    *outCString = '\0';

    stringRef = (CFStringRef)CFStringCreateWithCharacters(NULL, (const UniChar *)inUniStr + 1, *(const UInt16 *)inUniStr);
    if (!stringRef)
        return;

    CFStringGetCString(stringRef, outCString, (short)inMaxString, 0);
    CFRelease(stringRef);
}

void MacStrings_CopyAndClean(const char *inSrcString, char *inDstString, int inDstSize)
{
}

