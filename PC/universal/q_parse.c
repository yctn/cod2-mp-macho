/* Converted to C from ASM: q_parse.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/universal/q_parse.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

extern void Com_Printf(const char *fmt, ...);
extern void Com_Error(int level, const char *fmt, ...);
extern void I_strncpyz(char *dest, const char *src, int destsize);

__attribute__((used, aligned(4)))
const char * punctuation[] = {
    "+=", "-=", "*=", "/=",
    "&=", "|=", "++", "--",
    "&&", "||", "<=", ">=",
    "==", "!=", NULL, NULL,
}; /* 0x30f540 */
__attribute__((used, aligned(4)))
UInt32 g_parse[4728]; /* 0x30ab60 */

#define g_parse ((ParseThreadInfo *)g_parse)

int Com_Compress(char *data_p);
void Com_BeginParseSession(const char *filename);
void Com_EndParseSession(void);
void Com_ResetParseSessions(void);
void Com_SetSpaceDelimited(qboolean spaceDelimited);
void Com_SetKeepStringQuotes(qboolean keepStringQuotes);
void Com_SetCSV(qboolean csv);
int Com_GetCurrentParseLine(void);
void Com_SetScriptWarningPrefix(const char *prefix);
void Com_ScriptError(const char *msg, ...);
void Com_ScriptWarning(const char *msg, ...);
void Com_UngetToken(void);
void Com_ParseSetMark(const char * *text, com_parse_mark_t *mark);
void Com_ParseReturnToMark(const char * *text, com_parse_mark_t *mark);
const char * Com_GetLastTokenPos(void);
static char * Com_ParseExt(const char * *data_p, int allowLineBreaks);
const char * Com_Parse(const char * *data_p);
const char * Com_ParseOnLine(const char * *data_p);
void Com_SkipRestOfLine(const char * *data);
qboolean Com_MatchToken(const char * *buf_p, const char *match, qboolean warning);
float Com_ParseFloat(const char * *buf_p);
int Com_ParseInt(const char * *buf_p);
int Com_GetArgCountOnLine(const char * *data_p);

/* line 424 */
int Com_Compress(char *data_p)
{
    char *in, *out;
    int size;
    char c;

    in = data_p;
    out = data_p;
    size = 0;

    while ((c = *in) != '\0') {
        if (c == '\r' || c == '\n') {
            *out++ = c;
            size++;
            in++;
        } else if (c == '/') {
            if (in[1] == '/') {
                /* Line comment: skip to end of line */
                in++;
                while (*in && *in != '\n')
                    in++;
            } else if (in[1] == '*') {
                /* Block comment: skip, preserving newlines */
                in++;
                while (*in) {
                    if (*in == '*' && in[1] == '/') {
                        in += 2;
                        break;
                    }
                    if (*in == '\n') {
                        *out++ = '\n';
                        size++;
                    }
                    in++;
                }
            } else {
                in++;
                *out++ = c;
                size++;
            }
        } else {
            in++;
            *out++ = c;
            size++;
        }
    }

    *out = '\0';
    return size;
}

/* line 137 */
void Com_BeginParseSession(const char *filename)
{
    parseInfo_t *pi;
    int i;

    if (g_parse[0].parseInfoNum == 15) {
        Com_Printf("Already parsing:\n");
        if (g_parse[0].parseInfoNum > 0) {
            for (i = 0; i < g_parse[0].parseInfoNum; i++) {
                Com_Printf("%i. %s\n", i, g_parse[0].parseInfo[i].parseFile);
            }
        }
        Com_Error(0, "Com_BeginParseSession: session overflow trying to parse %s\n", filename);
    }

    g_parse[0].parseInfoNum++;
    pi = &g_parse[0].parseInfo[g_parse[0].parseInfoNum];

    pi->lines = 1;
    pi->ungetToken = 0;
    pi->spaceDelimited = 1;
    pi->keepStringQuotes = 0;
    pi->csv = 0;
    pi->negativeNumbers = 0;
    pi->errorPrefix = "";
    pi->warningPrefix = "";
    pi->backup_lines = 0;
    pi->backup_text = NULL;

    I_strncpyz(pi->parseFile, filename, 64);
}

/* line 164 */
void Com_EndParseSession(void)
{
    if (g_parse[0].parseInfoNum == 0) {
        Com_Error(0, "Com_EndParseSession: session underflow");
    }
    g_parse[0].parseInfoNum--;
}

/* line 176 */
void Com_ResetParseSessions(void)
{
    g_parse[0].parseInfoNum = 0;
}

/* line 186 */
void Com_SetSpaceDelimited(qboolean spaceDelimited)
{
    parseInfo_t *pi = &g_parse[0].parseInfo[g_parse[0].parseInfoNum];
    pi->spaceDelimited = (spaceDelimited != 0);
}

/* line 198 */
void Com_SetKeepStringQuotes(qboolean keepStringQuotes)
{
    parseInfo_t *pi = &g_parse[0].parseInfo[g_parse[0].parseInfoNum];
    pi->keepStringQuotes = (keepStringQuotes != 0);
}

/* line 210 */
void Com_SetCSV(qboolean csv)
{
    parseInfo_t *pi = &g_parse[0].parseInfo[g_parse[0].parseInfoNum];
    pi->csv = (csv != 0);
}

/* line 239 */
int Com_GetCurrentParseLine(void)
{
    parseInfo_t *pi = &g_parse[0].parseInfo[g_parse[0].parseInfoNum];
    return pi->lines;
}

/* line 265 */
void Com_SetScriptWarningPrefix(const char *prefix)
{
    parseInfo_t *pi = &g_parse[0].parseInfo[g_parse[0].parseInfoNum];
    pi->warningPrefix = prefix;
}

/* line 279 */
void Com_ScriptError(const char *msg, ...)
{
    parseInfo_t *pi;
    va_list argptr;
    char string[4096];

    pi = &g_parse[0].parseInfo[g_parse[0].parseInfoNum];

    va_start(argptr, msg);
    vsprintf(string, msg, argptr);
    va_end(argptr);

    if (g_parse[0].parseInfoNum) {
        Com_Error(1, "%sFile %s, line %i: %s", pi->errorPrefix, pi->parseFile, pi->lines, string);
    } else {
        Com_Error(1, "%s", string);
    }
}

/* line 300 */
void Com_ScriptWarning(const char *msg, ...)
{
    parseInfo_t *pi;
    va_list argptr;
    char string[4096];

    pi = &g_parse[0].parseInfo[g_parse[0].parseInfoNum];

    va_start(argptr, msg);
    vsprintf(string, msg, argptr);
    va_end(argptr);

    if (g_parse[0].parseInfoNum) {
        Com_Printf("%sFile %s, line %i: %s", pi->warningPrefix, pi->parseFile, pi->lines, string);
    } else {
        Com_Printf("%s", string);
    }
}

/* line 329 */
void Com_UngetToken(void)
{
    parseInfo_t *pi;

    pi = &g_parse[0].parseInfo[g_parse[0].parseInfoNum];

    if (pi->ungetToken) {
        Com_ScriptError("UngetToken called twice");
    }
    pi->ungetToken = 1;
    g_parse[0].prevTokenPos = g_parse[0].tokenPos;
}

/* line 349 */
void Com_ParseSetMark(const char * *text, com_parse_mark_t *mark)
{
    parseInfo_t *pi;

    pi = &g_parse[0].parseInfo[g_parse[0].parseInfoNum];

    mark->lines = pi->lines;
    mark->text = *text;
    mark->ungetToken = pi->ungetToken;
    mark->backup_lines = pi->backup_lines;
    mark->backup_text = pi->backup_text;
}

/* line 373 */
void Com_ParseReturnToMark(const char * *text, com_parse_mark_t *mark)
{
    parseInfo_t *pi;

    pi = &g_parse[0].parseInfo[g_parse[0].parseInfoNum];

    pi->lines = mark->lines;
    *text = mark->text;
    pi->ungetToken = (mark->ungetToken != 0);
    pi->backup_lines = mark->backup_lines;
    pi->backup_text = mark->backup_text;
}

/* line 499 */
const char * Com_GetLastTokenPos(void)
{
    return g_parse[0].tokenPos;
}

/* line 623 */
static char * Com_ParseExt(const char * *data_p, int allowLineBreaks)
{
    parseInfo_t *pi;
    char *text;
    int c;
    int len;
    int hasNewLines;
    int p;

    pi = &g_parse[0].parseInfo[g_parse[0].parseInfoNum];

    pi->token[0] = '\0';

    text = (char *)*data_p;
    if (!text) {
        *data_p = NULL;
        return pi->token;
    }

    pi->backup_lines = pi->lines;
    pi->backup_text = *data_p;

    if (pi->csv) {
        /* CSV parsing mode */
        pi->token[0] = '\0';

        if (allowLineBreaks) {
            while (*text == '\r' || *text == '\n')
                text++;
        } else {
            if (*text == '\r' || *text == '\n')
                return pi->token;
        }

        g_parse[0].prevTokenPos = g_parse[0].tokenPos;
        g_parse[0].tokenPos = text;

        len = 0;

        while (*text) {
            c = *text;

            if (c == ',') {
                text++;
                *data_p = text;
                pi->token[len] = '\0';
                return pi->token;
            }
            if (c == '\n') {
                *data_p = text;
                pi->token[len] = '\0';
                return pi->token;
            }
            if (c == '\r') {
                text++;
                continue;
            }
            if (c == '"') {
                /* Quoted CSV field */
                text++;
                while (1) {
                    c = *text;
                    if (c == '"') {
                        text++;
                        if (*text == '"') {
                            /* Escaped quote "" */
                            if (len <= 1022)
                                pi->token[len++] = '"';
                            text++;
                            continue;
                        }
                        /* End of quoted field */
                        break;
                    }
                    if (len <= 1022)
                        pi->token[len++] = c;
                    text++;
                }
                continue;
            }

            if (len <= 1022)
                pi->token[len++] = c;
            text++;
        }

        /* End of data */
        *data_p = NULL;
        pi->token[len] = '\0';
        return pi->token;
    }

    /* Normal (non-CSV) parsing */

skip_whitespace:
    hasNewLines = 0;
    while (1) {
        c = (unsigned char)*text;
        if (c > ' ')
            break;
        if (!c) {
            *data_p = NULL;
            return pi->token;
        }
        if (c == '\n') {
            pi->lines++;
            hasNewLines = 1;
        }
        text++;
    }

    if (hasNewLines && !allowLineBreaks) {
        return pi->token;
    }

    /* Check for comments */
    c = *text;
    if (c == '/') {
        if (text[1] == '/') {
            /* Line comment: skip to end of line */
            text += 2;
            while (*text && *text != '\n')
                text++;
            goto skip_whitespace;
        }
        if (text[1] == '*') {
            /* Block comment */
            {
                char *bp = text;
                while (1) {
                    c = bp[1];
                    if (!c) {
                        text = bp + 1;
                        break;
                    }
                    if (c == '*' && bp[2] == '/') {
                        text = bp + 3;
                        break;
                    }
                    if (c == '\n')
                        pi->lines++;
                    bp++;
                }
            }
            goto skip_whitespace;
        }
        /* Just a '/' - fall through to token parsing */
    }

    /* Save token position */
    g_parse[0].prevTokenPos = g_parse[0].tokenPos;
    g_parse[0].tokenPos = text;

    c = *text;

    /* Quoted string */
    if (c == '"') {
        if (pi->keepStringQuotes) {
            pi->token[0] = '"';
            len = 1;
        } else {
            len = 0;
        }

        text++;
        while (1) {
            c = *text;
            text++;

            if (c == '\\') {
                int next = *text;
                if (next == '"' || next == '\\') {
                    c = next;
                    text++;
                }
            } else if (c == '"' || !c) {
                if (pi->keepStringQuotes) {
                    if (len <= 1022)
                        pi->token[len++] = '"';
                }
                pi->token[len] = '\0';
                *data_p = text;
                return pi->token;
            }

            if (*text == '\n')
                pi->lines++;

            if (len <= 1022)
                pi->token[len++] = c;
        }
    }

    /* Space delimited mode */
    if (pi->spaceDelimited) {
        len = 0;
        while (*text > ' ') {
            if (len <= 1022)
                pi->token[len] = *text;
            len++;
            text++;
        }
        if (len == 1024)
            len = 0;
        pi->token[len] = '\0';
        *data_p = text;
        return pi->token;
    }

    /* Number: digit, or '-' followed by digit (if negativeNumbers), or '.' followed by digit */
    if ((c >= '0' && c <= '9') ||
        (pi->negativeNumbers && c == '-' && text[1] >= '0' && text[1] <= '9') ||
        (c == '.' && text[1] >= '0' && text[1] <= '9')) {
        len = 0;
        /* Read mantissa: digits and dots */
        while (1) {
            if (len <= 1022)
                pi->token[len] = *text;
            len++;
            text++;
            c = *text;
            if ((c < '0' || c > '9') && c != '.')
                break;
        }
        /* Check for exponent */
        if (c == 'e' || c == 'E') {
            if (len <= 1022)
                pi->token[len] = c;
            len++;
            text++;
            c = *text;
            if (c == '-' || c == '+') {
                if (len <= 1022)
                    pi->token[len] = c;
                len++;
                text++;
                c = *text;
            }
            while (c >= '0' && c <= '9') {
                if (len <= 1022)
                    pi->token[len] = c;
                len++;
                text++;
                c = *text;
            }
        }
        if (len == 1024)
            len = 0;
        pi->token[len] = '\0';
        *data_p = text;
        return pi->token;
    }

    /* Identifier: starts with a-z, A-Z, _, /, \ */
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
        c == '_' || c == '/' || c == '\\') {
        len = 0;
        while (1) {
            if (len <= 1022)
                pi->token[len] = *text;
            len++;
            text++;
            c = *text;
            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
                  c == '_' || (c >= '0' && c <= '9')))
                break;
        }
        if (len == 1024)
            len = 0;
        pi->token[len] = '\0';
        *data_p = text;
        return pi->token;
    }

    /* Punctuation */
    for (p = 0; punctuation[p]; p++) {
        int plen;
        int j;
        const char *pstr = punctuation[p];

        plen = strlen(pstr);

        if (plen > 0 && pstr[0] != *text)
            continue;

        for (j = 1; j < plen; j++) {
            if (pstr[j] != text[j])
                break;
        }
        if (j == plen) {
            memcpy(pi->token, pstr, plen);
            pi->token[plen] = '\0';
            *data_p = text + plen;
            return pi->token;
        }
    }

    /* Single character token */
    pi->token[0] = *text;
    pi->token[1] = '\0';
    *data_p = text + 1;
    return pi->token;
}

/* line 900 */
const char * Com_Parse(const char * *data_p)
{
    parseInfo_t *pi;

    pi = &g_parse[0].parseInfo[g_parse[0].parseInfoNum];

    if (pi->ungetToken) {
        pi->ungetToken = 0;
        *data_p = pi->backup_text;
        pi->lines = pi->backup_lines;
    }

    return Com_ParseExt(data_p, 1);
}

/* line 923 */
const char * Com_ParseOnLine(const char * *data_p)
{
    parseInfo_t *pi;

    pi = &g_parse[0].parseInfo[g_parse[0].parseInfoNum];

    if (pi->ungetToken) {
        pi->ungetToken = 0;
        if (!pi->spaceDelimited) {
            return pi->token;
        }
        *data_p = pi->backup_text;
        pi->lines = pi->backup_lines;
    }

    return Com_ParseExt(data_p, 0);
}

/* line 1008 */
void Com_SkipRestOfLine(const char * *data)
{
    parseInfo_t *pi;
    char *text;

    pi = &g_parse[0].parseInfo[g_parse[0].parseInfoNum];

    text = (char *)*data;
    if (!text)
        return;

    while (*text) {
        if (*text == '\n') {
            pi->lines++;
            text++;
            break;
        }
        text++;
    }

    *data = text;
}

/* line 948 */
qboolean Com_MatchToken(const char * *buf_p, const char *match, qboolean warning)
{
    const char *token;

    token = Com_Parse(buf_p);

    if (strcmp(token, match) == 0) {
        return 1;
    }

    if (warning) {
        Com_ScriptWarning("MatchToken: %s != %s\n", token, match);
    } else {
        Com_ScriptError("MatchToken: %s != %s\n", token, match);
    }
    return 0;
}

/* line 1088 */
float Com_ParseFloat(const char * *buf_p)
{
    const char *token;

    token = Com_Parse(buf_p);
    return (float)atof(token);
}

/* line 1106 */
int Com_ParseInt(const char * *buf_p)
{
    const char *token;

    token = Com_Parse(buf_p);
    return atoi(token);
}

/* line 1034 */
int Com_GetArgCountOnLine(const char * *data_p)
{
    com_parse_mark_t mark;
    int count;
    const char *token;

    Com_ParseSetMark(data_p, &mark);

    count = 0;
    while (1) {
        token = Com_ParseOnLine(data_p);
        if (*token == '\0')
            break;
        count++;
    }

    Com_ParseReturnToMark(data_p, &mark);
    return count;
}
