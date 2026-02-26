/* Converted to C from ASM: g_load_utils.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game/g_load_utils.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

extern unsigned int SL_GetString(const char *str, int user);
extern void Com_Error(int level, const char *fmt, ...);
extern qboolean SV_GetEntityToken(char *buffer, int bufferSize);
extern void Com_sprintf(char *dest, int size, const char *fmt, ...);

static int index_00fea280; /* 0xfea280 */
static char str[8][32]; /* 0xfea180 */

qboolean G_SpawnStringInternal(SpawnVar *spawnVar, const char *key, const char *defaultString, const char * *out);
unsigned int G_NewString(const char *string);
char * vtos(const vec_t *v);
qboolean G_ParseSpawnVars(SpawnVar *spawnVar);

/* line 92 */
qboolean G_SpawnStringInternal(SpawnVar *spawnVar, const char *key, const char *defaultString, const char **out)
{
    int i;

    for (i = 0; i < spawnVar->numSpawnVars; i++) {
        if (strcmp(spawnVar->spawnVars[i][0], key) == 0) {
            *out = spawnVar->spawnVars[i][1];
            return 1;
        }
    }

    *out = defaultString;
    return 0;
}

/* line 120 */
unsigned int G_NewString(const char *string)
{
    char strbuf[0x4000];
    int len;
    int i;
    char *p;

    /* strlen(string) + 1 (includes null terminator) */
    len = strlen(string) + 1;

    if (len > 0x4000) {
        Com_Error(1, "G_NewString: len = %i > %i\n", len, 0x4000);
    }

    p = strbuf;
    for (i = 0; i < len; i++) {
        if (string[i] == '\\' && i < len - 1) {
            i++;
            if (string[i] == 'n') {
                *p++ = '\n';
            } else {
                *p++ = '\\';
            }
        } else {
            *p++ = string[i];
        }
    }

    return SL_GetString(strbuf, 0);
}

/* line 165 */
char *vtos(const vec_t *v)
{
    char *s;

    s = str[index_00fea280];
    index_00fea280 = (index_00fea280 + 1) & 7;

    Com_sprintf(s, 32, "(%i %i %i)", (int)v[0], (int)v[1], (int)v[2]);

    return s;
}

/* line 41 */
qboolean G_ParseSpawnVars(SpawnVar *spawnVar)
{
    char com_token[1024];
    char keyname[1024];
    int idx;
    int l;
    char *dest;

    spawnVar->spawnVarsValid = 0;
    spawnVar->numSpawnVars = 0;
    spawnVar->numSpawnVarChars = 0;

    /* Get first token - must be '{' */
    if (!SV_GetEntityToken(com_token, 0x400))
        return 0;

    if (com_token[0] != '{') {
        Com_Error(1, "G_ParseSpawnVars: found %s when expecting {", com_token);
    }

    /* Parse key/value pairs */
    for (;;) {
        /* Get key */
        if (!SV_GetEntityToken(keyname, 0x400)) {
            Com_Error(1, "G_GetEntityToken: unexpected end of entity string");
        }

        if (keyname[0] == '}')
            break;

        /* Get value */
        if (!SV_GetEntityToken(com_token, 0x400)) {
            Com_Error(1, "G_GetEntityToken: unexpected end of entity string");
        }

        if (com_token[0] == '}') {
            Com_Error(1, "G_ParseSpawnVars: closing brace without data");
        }

        if (spawnVar->numSpawnVars == 64) {
            Com_Error(1, "G_ParseSpawnVars: MAX_SPAWN_VARS");
        }

        idx = spawnVar->numSpawnVars;

        /* Add key token to spawnVarChars */
        l = strlen(keyname);
        if (spawnVar->numSpawnVarChars + l + 1 > 2048) {
            Com_Error(1, "G_AddSpawnVarToken: spawn vars too long");
        }
        dest = spawnVar->spawnVarChars + spawnVar->numSpawnVarChars;
        memcpy(dest, keyname, l + 1);
        spawnVar->numSpawnVarChars += l + 1;
        spawnVar->spawnVars[idx][0] = dest;

        /* Add value token to spawnVarChars */
        l = strlen(com_token);
        if (spawnVar->numSpawnVarChars + l + 1 > 2048) {
            Com_Error(1, "G_AddSpawnVarToken: spawn vars too long");
        }
        dest = spawnVar->spawnVarChars + spawnVar->numSpawnVarChars;
        memcpy(dest, com_token, l + 1);
        spawnVar->numSpawnVarChars += l + 1;
        spawnVar->spawnVars[idx][1] = dest;

        spawnVar->numSpawnVars++;
    }

    spawnVar->spawnVarsValid = 1;
    return 1;
}
