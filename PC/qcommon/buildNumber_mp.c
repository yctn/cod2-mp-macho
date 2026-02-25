/* Converted to C from ASM: buildNumber_mp.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/buildNumber_mp.c */

#include "common_types.h"
#include "imports.h"

extern char buf[128]; /* 0x0 */

char *getBuildNumber(void)
{
    sprintf(buf, "%s %s", "crc6_v1", "Thu Oct 06 2005 07:13:42PM");
    return buf;
}
