/* ASM dump from: l_precomp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/botlib/l_precomp.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>
#include <stdarg.h>

extern void Com_Printf(const char *fmt, ...);
extern void FreeMemory(void *ptr);
extern void FreeScript(void *script);
extern int PS_ReadToken(void *script, token_t *token);
extern int EndOfScript(void *script);

extern int numtokens; /* 0x0 */
extern define_t *globaldefines; /* 0x0 */
extern directive_t directives[20]; /* 0x0 */
extern directive_t dollardirectives[20]; /* 0x0 */
extern source_t * sourceFiles[64]; /* 0x0 */

void SourceError(source_t *source, char *str, ...);
void SourceWarning(source_t *source, char *str, ...);
int PC_StringizeTokens(token_t *tokens, token_t *token);
int PC_OperatorPriority(int op);
int PC_Directive_line(source_t *source);
int PC_SourceFileAndLine(int handle, char *filename, int *line);
int PC_ReadSourceToken(source_t *source, token_t *token);
int PC_Directive_error(source_t *source);
int PC_Directive_else(source_t *source);
int PC_Directive_endif(source_t *source);
int PC_EvaluateTokens(source_t *source, token_t *tokens, long int *intvalue, double *floatvalue, int integer);
void FreeSource(source_t *source);
int PC_FreeSourceHandle(int handle);
int PC_ReadDollarDirective(source_t *source);
int PC_ReadDirective(source_t *source);
int PC_Directive_include(source_t *source);
int PC_ReadDefineParms(source_t *source, define_t *define, token_t * *parms, int maxparms);
int PC_ExpandBuiltinDefine(source_t *source, token_t *deftoken, define_t *define, token_t * *firsttoken, token_t * *lasttoken);
int PC_ExpandDefine(source_t *source, token_t *deftoken, define_t *define, token_t * *firsttoken, token_t * *lasttoken);
int PC_ReadLine(source_t *source, token_t *token);
int PC_ReadLineHandle(int handle, pc_token_t *pc_token);
int PC_Directive_pragma(source_t *source);
int PC_Directive_if_def(source_t *source, int type);
int PC_Directive_ifndef(source_t *source);
int PC_Directive_ifdef(source_t *source);
int PC_Directive_undef(source_t *source);
int PC_ReadToken(source_t *source, token_t *token);
int PC_ReadTokenHandle(int handle, pc_token_t *pc_token);
int PC_Directive_define(source_t *source);
define_t * PC_CopyDefine(source_t *source, define_t *define);
source_t * LoadSourceFile(const char *filename);
int PC_LoadSourceHandle(const char *filename);
int PC_Evaluate(source_t *source, long int *intvalue, double *floatvalue, int integer);
int PC_Directive_evalfloat(source_t *source);
int PC_Directive_eval(source_t *source);
int PC_Directive_if(source_t *source);
int PC_Directive_elif(source_t *source);
int PC_DollarEvaluate(source_t *source, long int *intvalue, double *floatvalue, int integer);
int PC_DollarDirective_evalfloat(source_t *source);
int PC_DollarDirective_evalint(source_t *source);
void StripDoubleQuotes(char *string);

/* line 35 */
void SourceError(source_t *source, char *str, ...) {
    char text[1024];
    va_list ap;
    va_start(ap, str);
    vsnprintf(text, 0x400, str, ap);
    va_end(ap);
    {
        script_t *scriptfile = source->scriptstack;
        Com_Printf((const char *)"^1Error: file %s, line %d: %s\n", scriptfile, scriptfile->line, text);
    }
}

/* line 53 */
void SourceWarning(source_t *source, char *str, ...) {
    char text[1024];
    va_list ap;
    va_start(ap, str);
    vsnprintf(text, 0x400, str, ap);
    va_end(ap);
    {
        script_t *scriptfile = source->scriptstack;
        Com_Printf((const char *)"^3Warning: file %s, line %d: %s\n", scriptfile, scriptfile->line, text);
    }
}

/* line 348 */
int PC_StringizeTokens(token_t *tokens, token_t *token) {
    token_t *t;
    int len;

    token->type = 1;
    token->whitespace_p = NULL;
    token->endwhitespace_p = NULL;
    token->string[0] = '\0';

    len = strlen(token->string);
    token->string[len] = '"';
    token->string[len + 1] = '\0';

    for (t = tokens; t; t = (token_t *)t->next) {
        len = strlen((char *)token);
        strncat((char *)token, (char *)t, 0x400 - len);
    }

    len = strlen((char *)token);
    strncat((char *)token, (const char *)"\"", 0x401 - len);

    return 1;
}

/* line 1490 */
int PC_OperatorPriority(int op) {
    static const int priorities[] = {
    /*  5 */ 7,  6,  12, 12, 11, 11, 0,  0,  0,  0,
    /* 15 */ 0,  0,  0,  0,  0,  0,  13, 13, 0,  0,
    /* 25 */ 0,  15, 15, 15, 14, 14, 0,  10, 8,  9,
    /* 35 */ 16, 16, 12, 12, 0,  0,  0,  5,  5
    };
    int idx = op - 5;
    if (idx < 0 || idx > 38)
        return 0;
    return priorities[idx];
}

/* line 2312 */
int PC_Directive_line(source_t *source)
{
    SourceError(source, "#line directive not supported");
    return 0;
}

/* line 3150 */
int PC_SourceFileAndLine(int handle, char *filename, int *line) {
    source_t *source;

    if ((unsigned)(handle - 1) > 0x3e)
        return 0;
    source = sourceFiles[handle];
    if (!source)
        return 0;

    if (source->scriptstack) {
        strcpy(filename, source->scriptstack->filename);
        *line = source->scriptstack->line;
    } else {
        strcpy(filename, source->filename);
        *line = 0;
    }
    return 1;
}

/* line 180 */
int PC_ReadSourceToken(source_t *source, token_t *token) {
    token_t *tok;
    script_t *script;
    indent_t *indent;

    for (;;) {
        /* Check for queued tokens */
        tok = source->tokens;
        if (tok) {
            memcpy(token, tok, 0x440);
            source->tokens = (token_t *)tok->next;
            FreeMemory(tok);
            numtokens--;
            return 1;
        }

        /* Try reading from current script */
        if (PS_ReadToken(source->scriptstack, token))
            return 1;

        /* Read failed: check if end of script */
        if (EndOfScript(source->scriptstack)) {
            /* Check indentstack for unmatched #if directives */
            indent = source->indentstack;
            if (indent && indent->script == source->scriptstack) {
                SourceWarning(source, "#if directive not terminated");
                /* Free matching indent entries */
                while ((indent = source->indentstack) != NULL) {
                    if (indent->script != source->scriptstack)
                        break;
                    source->indentstack = (indent_t *)indent->next;
                    source->skip -= indent->skip;
                    FreeMemory(indent);
                }
            }
        }

        /* Try to pop to next script in chain */
        script = source->scriptstack;
        {
            script_t *nextScript = (script_t *)script->next;
            if (!nextScript)
                return 0; /* no more scripts */
            source->scriptstack = nextScript;
            FreeScript(script);
        }
    }
}
