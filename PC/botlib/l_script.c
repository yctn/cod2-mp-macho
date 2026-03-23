/* ASM dump from: l_script.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/botlib/l_script.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

extern punctuation_t default_punctuations[53]; /* 0x0 */
extern void FreeMemory(void *ptr);
extern void *GetMemory(unsigned long size);
extern void *GetClearedMemory(unsigned long size);
extern int FS_FOpenFileRead(const char *filename, fileHandle_t *file, qboolean uniqueFILE);
extern int FS_Read(void *buffer, int len, fileHandle_t f);
extern void FS_FCloseFile(fileHandle_t f);
extern int Com_sprintf(char *dest, int size, const char *fmt, ...);
extern int Com_Compress(char *data_p);

void PS_CreatePunctuationTable(script_t *script, punctuation_t *punctuations);
void ScriptError(script_t *script, char *str);
void ScriptWarning(script_t *script, char *str);
int PS_ReadEscapeCharacter(script_t *script, char *ch);
void NumberValue(char *string, int subtype, long unsigned int *intvalue, long double *floatvalue);
int PS_ReadNumber(script_t *script, token_t *token);
void StripDoubleQuotes(char *string);
int EndOfScript(script_t *script);
void FreeScript(script_t *script);
script_t * LoadScriptFile(const char *filename);
int PS_ReadString(script_t *script, token_t *token, int quote);
int PS_ReadToken(script_t *script, token_t *token);

static void Script_SanitizeBuffer(struct script_s *script)
{
    char *p;

    for (p = script->buffer; p < script->end_p; ++p) {
        if (*p == '`')
            *p = ' ';
    }
}

/* line 146 */
void PS_CreatePunctuationTable(script_t *script, punctuation_t *punctuations) {
    int **table;
    byte *p;
    int i;

    if (!script->punctuationtable) {
        script->punctuationtable = GetMemory(0x400);
    }

    table = (int **)script->punctuationtable;
    memset(table, 0, 0x400);

    for (p = (byte *)punctuations; *(char **)p; p += 0xc) {
        char *newStr = *(char **)p;
        int firstChar = (signed char)newStr[0];
        byte *existing = (byte *)table[firstChar];
        int newLen;

        if (!existing) {
            /* no entry for this first char yet */
            *(void **)(p + 8) = 0;
            table[firstChar] = (int *)p;
        } else {
            /* insert sorted by string length (longest first) */
            newLen = strlen(newStr);
            byte *prev = NULL;
            byte *cur = existing;

            while (cur) {
                int curLen = strlen(*(char **)cur);
                if (curLen < newLen) {
                    break;
                }
                prev = cur;
                cur = *(byte **)(cur + 8);
            }

            *(void **)(p + 8) = cur;
            if (prev) {
                *(byte **)(prev + 8) = p;
            } else {
                table[firstChar] = (int *)p;
            }
        }
    }
}
