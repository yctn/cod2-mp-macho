/* Converted to C from ASM: win_localize.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/win32/win_localize.cpp */

#include "common_types.h"
#include "imports.h"

extern int FS_FileOpen(const char *filename, const char *mode);
extern int FS_FileRead(void *buffer, int size, int count, int fp);
extern void FS_FileClose(int fp);
extern int FS_FileSeek(int fp, int offset, int origin);
extern void SEH_GetLanguageIndexForName(const char *name, language_t *lang);
extern void Com_BeginParseSession(const char *name);
extern void Com_EndParseSession(void);
extern const char *Com_Parse(const char **buf);
extern int strcmp(const char *s1, const char *s2);
extern char *va(const char *fmt, ...);

static char *localization; /* localization */
static char *localized_strings; /* 0x4e9604 */
static char language_buffer[4096]; /* language_buffer */

language_t Win_InitLocalization(void)
{
    int fp;
    int size;
    char *p;
    language_t lang;

    localization = 0;
    localized_strings = 0;

    fp = FS_FileOpen("localization.txt", "r");
    if (!fp)
        return 0;

    FS_FileSeek(fp, 0, 2); /* SEEK_END */
    size = ftell((FILE *)(long)fp);
    FS_FileSeek(fp, 0, 0); /* SEEK_SET */

    localization = language_buffer;
    size = FS_FileRead(language_buffer, 1, size, fp);
    FS_FileClose(fp);

    if (!size) {
        localization = 0;
        return 0;
    }

    localization[size] = '\0';

    lang = 0;
    p = localization;
    while (*p) {
        if (*p == '\n') {
            *p = '\0';
            p++;
            localized_strings = p;
            SEH_GetLanguageIndexForName(localization, &lang);
            break;
        }
        p++;
    }

    return lang;
}

void Win_ShutdownLocalization(void)
{
    localization = 0;
    localized_strings = 0;
}

const char *Win_LocalizeRef(const char *ref)
{
    const char *strings;
    const char *key;
    const char *value;
    int match;

    Com_BeginParseSession("localization");
    strings = localized_strings;

    for (;;) {
        key = Com_Parse(&strings);
        if (*key == '\0')
            break;

        match = strcmp(key, ref);

        value = Com_Parse(&strings);
        if (*value == '\0')
            break;

        if (match == 0) {
            Com_EndParseSession();
            return va("%s", value);
        }
    }

    Com_EndParseSession();
    return va("%s", ref);
}
