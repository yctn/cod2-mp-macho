/* Converted to C from ASM: com_shared.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/universal/com_shared.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>
#include <time.h>

extern void Com_Error(int code, const char *fmt, ...);

int Com_HashKey(char *string, int maxlen)
{
    int hash, i;

    hash = 0;
    for (i = 0; i < maxlen && string[i] != '\0'; i++) {
        hash += (signed char)string[i] * (i + 119);
    }
    return hash ^ (hash >> 10) ^ (hash >> 20);
}

int Com_RealTime(qtime_t *qtime)
{
    time_t t;
    struct tm *tms;

    t = time(NULL);
    if (qtime) {
        tms = localtime(&t);
        if (tms) {
            qtime->tm_sec = tms->tm_sec;
            qtime->tm_min = tms->tm_min;
            qtime->tm_hour = tms->tm_hour;
            qtime->tm_mday = tms->tm_mday;
            qtime->tm_mon = tms->tm_mon;
            qtime->tm_year = tms->tm_year;
            qtime->tm_wday = tms->tm_wday;
            qtime->tm_yday = tms->tm_yday;
            qtime->tm_isdst = tms->tm_isdst;
        }
    }
    return (int)t;
}

long int Com_Memcpy(long int *dest, const long int *src, int count)
{
    /* Guard against writes to shared-library space (0xf0000000+).
       Stale Mac relocations in BSP loader ASM can produce destination
       pointers in dynamic library mappings. */
    unsigned int d = (unsigned int)dest;
    if (d >= 0xf0000000) {
        return (long int)dest;
    }
    return (long int)memcpy(dest, src, count);
}

long int Com_Memset(long int *dest, const int val, int count)
{
    return (long int)memset(dest, val, count);
}

Bool Com_Filter(const char *filter, const char *name, int casesensitive)
{
    char buf[1024];
    int i, found;
    int namelen, buflen, maxpos;

    while (1) {
        switch (*filter) {
        case '\0':
            return 1;

        case '*':
            filter++;
            /* collect literal chars after * into buf */
            i = 0;
            while (*filter && *filter != '*' && *filter != '?') {
                buf[i++] = *filter++;
            }
            buf[i] = '\0';

            if (buf[0] == '\0')
                continue;

            /* search for buf in name */
            namelen = strlen(name);
            buflen = strlen(buf);
            maxpos = namelen - buflen;
            if (maxpos < 0)
                return 0;

            for (i = 0; i <= maxpos; i++) {
                if (casesensitive) {
                    if (!strncmp(name, buf, buflen))
                        break;
                } else {
                    if (!strncasecmp(name, buf, buflen))
                        break;
                }
                name++;
            }
            if (i > maxpos)
                return 0;
            name += buflen;
            continue;

        case '?':
            filter++;
            name++;
            continue;

        case '[':
            filter++;
            if (*filter == '[') {
                /* literal [ */
                continue;
            }
            found = 0;
            while (*filter) {
                if (found) {
                    /* skip to closing ] */
                    if (*filter == ']') {
                        filter++;
                        if (*filter == ']')
                            continue;
                        name++;
                        break;
                    }
                    filter++;
                    continue;
                }
                if (*filter == ']') {
                    /* special case: ] as first char in class */
                    if (filter[1] == ']') {
                        /* empty class */
                        return 0;
                    }
                    if (filter[1] == '-')
                        goto check_range;
                    goto check_single;
                }
                if (filter[1] == '-') {
                check_range:;
                    char range_end = filter[2];
                    if (range_end == '\0' || range_end == ']') {
                        goto check_single;
                    }
                    if (casesensitive) {
                        if (*name >= *filter && *name <= range_end)
                            found = 1;
                    } else {
                        if (toupper(*name) >= toupper(*filter) && toupper(*name) <= toupper(range_end))
                            found = 1;
                    }
                    filter += 3;
                    continue;
                }
            check_single:
                if (casesensitive) {
                    if (*filter == *name)
                        found = 1;
                } else {
                    if (toupper(*filter) == toupper(*name))
                        found = 1;
                }
                filter++;
                continue;
            }
            if (found) {
                filter++;
                name++;
                continue;
            }
            return 0;

        default:
            /* literal character match */
            if (casesensitive) {
                if (*filter != *name)
                    return 0;
            } else {
                if (toupper(*filter) != toupper(*name))
                    return 0;
            }
            filter++;
            name++;
            continue;
        }
    }
}

Bool Com_FilterPath(const char *filter, const char *name, int casesensitive)
{
    char new_filter[64];
    char new_name[64];
    int i;

    for (i = 0; i < 63 && filter[i]; i++) {
        if (filter[i] == '\\' || filter[i] == ':')
            new_filter[i] = '/';
        else
            new_filter[i] = filter[i];
    }
    new_filter[i] = '\0';

    for (i = 0; i < 63 && name[i]; i++) {
        if (name[i] == '\\' || name[i] == ':')
            new_name[i] = '/';
        else
            new_name[i] = name[i];
    }
    new_name[i] = '\0';

    return Com_Filter(new_filter, new_name, casesensitive);
}
