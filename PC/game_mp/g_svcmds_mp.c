/* Converted to C from ASM: g_svcmds_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_svcmds_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

extern int SV_Cmd_Argc(void);
extern void SV_Cmd_ArgvBuffer(int arg, char *buffer, int bufferLength);
extern void Com_Printf(const char *msg, ...);
extern void Com_sprintf(char *dest, int size, const char *fmt, ...);
extern void Dvar_SetString(void *dvar, const char *value);
extern int I_stricmp(const char *s1, const char *s2);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern const char *SL_ConvertToString(unsigned int stringValue);
extern const char *va(const char *format, ...);
extern char *ConcatArgs(int start);
extern void SV_GameSendServerCommand(int clientNum, int type, const char *text);
extern void Cbuf_ExecuteText(int exec_when, const char *text);

extern byte g_entities_ptr[]; /* imp_g_entities */
extern byte level_ptr[];      /* imp_level */
extern byte *g_banIPs_dvar;  /* imp_g_banIPs */
extern void *imp_g_cheats;  /* import pointer to g_cheats dvar */

static ipFilter_t ipFilters[1024]; /* ipFilters */
static int numIPFilters; /* numIPFilters */

static qboolean StringToFilter(const char *s, ipFilter_t *f);
static void UpdateIPBans(void);
static void AddIP(const char *str);
void Svcmd_RemoveIP_f(void);
void Svcmd_EntityList_f(void);
void G_ProcessIPBans(void);
qboolean ConsoleCommand(void);

/* line 71 - inlined in original as part of AddIP/RemoveIP */
static qboolean StringToFilter(const char *s, ipFilter_t *f)
{
    unsigned char b[4];
    unsigned char m[4];
    char num[0x400];
    int i;
    int j;

    for (i = 0; i < 4; i++) {
        b[i] = 0;
        m[i] = 0;
    }

    for (i = 0; i < 4; i++) {
        if (*s < '0' || *s > '9') {
            Com_Printf("Bad filter address: %s\n", s);
            return 0;
        }

        j = 0;
        while (*s >= '0' && *s <= '9') {
            num[j] = *s;
            j++;
            s++;
        }
        num[j] = '\0';

        b[i] = (unsigned char)atoi(num);
        if (b[i] != 0)
            m[i] = 0xff;

        if (*s == '\0')
            break;
        s++;
    }

    f->mask = *(unsigned int *)m;
    f->compare = *(unsigned int *)b;
    return 1;
}

/* line 118 - inlined in original as part of AddIP/RemoveIP */
static void UpdateIPBans(void)
{
    char iplist[0x400];
    int i;
    int len;
    byte *ip;

    iplist[0] = '\0';

    for (i = 0; i < numIPFilters; i++) {
        if (ipFilters[i].compare == 0xffffffff)
            continue;

        ip = (byte *)&ipFilters[i].compare;
        len = strlen(iplist);
        Com_sprintf(iplist + len, 0x400 - len,
                    "%i.%i.%i.%i ", ip[0], ip[1], ip[2], ip[3]);
    }

    Dvar_SetString(*(void **)&g_banIPs_dvar, iplist);
}

/* line 137 */
static void AddIP(const char *str)
{
    ipFilter_t *f;
    int i;

    /* Find a free slot */
    if (numIPFilters > 0 && ipFilters[0].compare != 0xffffffff) {
        /* Search for a freed slot (compare == -1) starting from index 1 */
        for (i = 1; i < numIPFilters; i++) {
            if (ipFilters[i].compare == 0xffffffff)
                break;
        }
        if (i == numIPFilters) {
            /* No free slot found */
            if (numIPFilters == 1024) {
                Com_Printf("IP filter list is full\n");
                return;
            }
            /* Expand the list */
            i = numIPFilters;
            numIPFilters = numIPFilters + 1;
        }
    } else if (numIPFilters == 0) {
        /* No filters yet, use slot 0 */
        i = 0;
        numIPFilters = 1;
    } else {
        /* ipFilters[0].compare == -1, reuse slot 0 */
        i = 0;
    }

    f = &ipFilters[i];

    if (!StringToFilter(str, f)) {
        /* Bad filter address, invalidate the slot */
        ipFilters[i].compare = 0xffffffff;
    }

    UpdateIPBans();
}

/* line 217 */
void Svcmd_RemoveIP_f(void)
{
    char str[0x400];
    ipFilter_t f;
    int i;

    if (SV_Cmd_Argc() <= 1) {
        Com_Printf("Usage: removeip <ip address>\n");
        return;
    }

    SV_Cmd_ArgvBuffer(1, str, 0x400);

    if (!StringToFilter(str, &f))
        return;

    for (i = 0; i < numIPFilters; i++) {
        if (ipFilters[i].mask == f.mask && ipFilters[i].compare == f.compare) {
            ipFilters[i].compare = 0xffffffff;
            Com_Printf("Removed.\n");
            UpdateIPBans();
            return;
        }
    }

    Com_Printf("Didn't find %s.\n", str);
}

/* line 255 */
void Svcmd_EntityList_f(void)
{
    byte *level;
    byte *ent;
    int numEntities;
    int e;
    int eType;
    unsigned short classname;

    level = (byte *)level_ptr;
    numEntities = *(int *)(level + 0xc);

    for (e = 1; e < numEntities; e++) {
        ent = (byte *)g_entities_ptr + e * 0x230;

        /* Check r.inuse at offset 0xFC */
        if (*(byte *)(ent + 0xfc) == 0)
            continue;

        Com_Printf("%3i:", e);

        /* s.eType at offset 0x04 */
        eType = *(int *)(ent + 0x04);

        switch (eType) {
            case 0: Com_Printf("ET_GENERAL             "); break;
            case 1: Com_Printf("ET_PLAYER              "); break;
            case 2: Com_Printf("ET_CORPSE              "); break;
            case 3: Com_Printf("ET_ITEM                "); break;
            case 4: Com_Printf("ET_MISSILE             "); break;
            case 5: Com_Printf("ET_INVISIBLE           "); break;
            case 6: Com_Printf("ET_SCRIPTMOVER         "); break;
            default: Com_Printf("%3i                  ", eType); break;
        }

        /* classname at offset 0x168 (scr_string_t) */
        classname = *(unsigned short *)(ent + 0x168);
        if (classname != 0)
            Com_Printf("%s", SL_ConvertToString(classname));

        Com_Printf("\n");
    }
}

/* line 166 */
void G_ProcessIPBans(void)
{
    char str[0x400];
    char *s;
    char *t;

    numIPFilters = 0;

    /* Read dvar string value: *(*(dvar_ptr) + 8) */
    I_strncpyz(str, *(const char **)(*(int *)&g_banIPs_dvar + 8), 0x400);

    s = str;
    t = str;

    while (*t != '\0') {
        s = strchr(s, ' ');
        if (s == NULL)
            break;

        /* Strip spaces and null-terminate */
        while (*s == ' ') {
            *s = '\0';
            s++;
        }

        if (*t != '\0') {
            AddIP(t);
            t = s;
        } else {
            t = s;
        }
    }
}

/* line 355 */
qboolean ConsoleCommand(void)
{
    char cmd[0x400];
    char str[0x400];

    SV_Cmd_ArgvBuffer(0, cmd, 0x400);

    if (I_stricmp(cmd, "entitylist") == 0) {
        Svcmd_EntityList_f();
        return 1;
    }

    if (I_stricmp(cmd, "addip") == 0) {
        if (SV_Cmd_Argc() <= 1) {
            Com_Printf("Usage: addip <ip address>\n");
            return 1;
        }
        SV_Cmd_ArgvBuffer(1, str, 0x400);
        AddIP(str);
        return 1;
    }

    if (I_stricmp(cmd, "removeip") == 0) {
        Svcmd_RemoveIP_f();
        return 1;
    }

    if (I_stricmp(cmd, "maprotate") == 0) {
        Cbuf_ExecuteText(1, "vstr nextmap\n");
        return 1;
    }

    /* Check if cheats are enabled: *(*(cheats_dvar) + 8) */
    if (*(int *)(*(int *)imp_g_cheats + 8) == 0)
        return 0;

    if (I_stricmp(cmd, "say") == 0) {
        SV_GameSendServerCommand(-1, 0, va("%c \"%s\"", 'e', ConcatArgs(1)));
        return 1;
    }

    return 0;
}
