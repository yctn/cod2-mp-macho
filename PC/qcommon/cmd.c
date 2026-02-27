/* Decompiled from: cmd.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/cmd.cpp */

#include "common_types.h"
#include "imports.h"

#include <string.h>
#include <stdlib.h>

extern void Com_Printf(const char *fmt, ...);
extern void Com_Error(int code, const char *fmt, ...);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern void I_strncat(char *dest, int destsize, const char *src);
extern int I_stricmp(const char *s1, const char *s2);
extern void *Z_MallocInternal(int size);
extern void Z_FreeInternal(void *ptr);
extern char *CopyStringInternal(const char *in);
extern int Dvar_Command(void);
extern qboolean CL_GameCommand(void);
extern qboolean SV_GameCommand(void);
extern void CL_ForwardCommandToServer(const char *text);
extern const char **FS_ListFiles(const char *path, const char *extension, int behavior, int *numfiles, int allocTrackType);
extern int FS_ReadFile(const char *qpath, void **buffer);
extern void FS_FreeFile(void *buffer);
extern int Com_Filter(const char *filter, const char *name, int casesensitive);
extern void Com_DefaultExtension(char *path, int maxSize, const char *extension);
extern dvar_t *Dvar_FindVar(const char *var_name);
extern const char *va(const char *format, ...);

extern int cmd_wait; /* 0x0 */
extern cmd_t cmd_texts[1]; /* 0x0 */
extern cmd_t *cmd_text; /* 0x0 */
static cmd_text_buf_t cmd_text_buf; /* 0x485f00 */
static int cmd_argc; /* 0x483880 */
static char * cmd_argv[512]; /* 0x483080 */
static char cmd_tokenized[8704]; /* 0x483900 */
static cmd_function_t *cmd_functions; /* 0x483000 */
static char cmd_args1[1024]; /* 0x485b00 */

/* forward declarations */
static int Cmd_TokenizeStringInternal(const char *text_in, char **argv, int max_tokens, char *textOut);
static void Cbuf_InsertText(const char *text);
static void Cbuf_ExecuteInternal(void);
static void Cmd_Exec_f(void);
void Cmd_ExecuteString(const char *text);

extern byte *ptr_195ecb4; /* 0x195ecb4 */
extern byte *ptr_195ecbc; /* 0x195ecbc */

/* line 122 */
void Cmd_Wait_f(void)
{
    if (cmd_argc == 2) {
        cmd_wait = atoi(cmd_argv[1]);
    } else {
        cmd_wait = 1;
    }
}

/* line 148 */
void Cbuf_Init(void)
{
    cmd_texts[0].data = (byte *)cmd_text_buf;
    cmd_texts[0].maxsize = 0x10000;
    cmd_texts[0].cmdsize = 0;
}

/* line 174 */
void Cbuf_AddText(const char *text)
{
    int length;

    length = strlen(text);
    if (cmd_text->cmdsize + length >= cmd_text->maxsize) {
        Com_Printf("Cbuf_AddText: overflow\n");
        return;
    }

    memcpy(cmd_text->data + cmd_text->cmdsize, text, length);
    cmd_text->cmdsize += length;
}

/* line 203 - inlined into Cbuf_ExecuteText, Cmd_Vstr_f, Cmd_Exec_f */
static void Cbuf_InsertText(const char *text)
{
    int length;
    int i;

    length = strlen(text) + 1; /* includes the \n we add */
    if (cmd_text->cmdsize + length > cmd_text->maxsize) {
        Com_Printf("Cbuf_InsertText overflowed\n");
        return;
    }

    /* shift existing text forward */
    for (i = cmd_text->cmdsize - 1; i >= 0; i--) {
        cmd_text->data[i + length] = cmd_text->data[i];
    }

    /* copy new text */
    memcpy(cmd_text->data, text, length - 1);
    cmd_text->data[length - 1] = '\n';
    cmd_text->cmdsize += length;
}

/* line 231 */
void Cbuf_ExecuteText(int exec_when, const char *text)
{
    switch (exec_when) {
    case 0:
        if (text && *text != '\0') {
            Cmd_ExecuteString(text);
        }
        Cbuf_ExecuteInternal();
        break;
    case 1:
        Cbuf_InsertText(text);
        break;
    case 2:
        Cbuf_AddText(text);
        break;
    default:
        Com_Error(0, "Cbuf_ExecuteText: bad exec_when");
        break;
    }
}

/* line 429 */
static void Cbuf_ExecuteInternal(void)
{
    int i;
    int quotes;
    char line[4096];

    while (cmd_text->cmdsize > 0) {
        if (cmd_wait) {
            cmd_wait -= 1;
            return;
        }

        /* find a \n or ; line break */
        char *text = (char *)cmd_text->data;
        quotes = 0;
        i = 0;
        for (i = 0; i < cmd_text->cmdsize; i++) {
            if (text[i] == '"') {
                quotes++;
            }
            if (!(quotes & 1) && text[i] == ';') {
                break;
            }
            if (text[i] == '\n' || text[i] == '\r') {
                break;
            }
        }

        if (i > 0xfff) {
            i = 0xfff;
        }

        memcpy(line, text, i);
        line[i] = '\0';

        /* remove the line from the command buffer */
        if (i == cmd_text->cmdsize) {
            cmd_text->cmdsize = 0;
        } else {
            i++;
            cmd_text->cmdsize -= i;
            memmove(text, text + i, cmd_text->cmdsize);
        }

        Cmd_ExecuteString(line);
    }
}

/* line 495 */
void Cbuf_Execute(void)
{
    Cbuf_ExecuteInternal();
}

/* line 549 */
static void Cmd_Exec_f(void)
{
    char filename[64];
    char *text;

    if (cmd_argc != 2) {
        Com_Printf("exec <filename> : execute a script file\n");
        return;
    }

    I_strncpyz(filename, cmd_argv[1], 64);
    Com_DefaultExtension(filename, 64, ".cfg");

    FS_ReadFile(filename, (void **)&text);
    if (!text) {
        Com_Printf("couldn't exec %s\n", cmd_argv[1]);
        return;
    }

    Com_Printf("execing %s\n", filename);

    Cbuf_InsertText(text);

    FS_FreeFile(text);
}

/* line 586 */
void Cmd_Vstr_f(void)
{
    const char *dvarName;
    dvar_t *dvar;
    const char *text;

    if (cmd_argc != 2) {
        Com_Printf("vstr <variablename> : execute a variable command\n");
        return;
    }

    dvarName = cmd_argv[1];
    dvar = Dvar_FindVar(dvarName);
    if (!dvar) {
        Com_Printf("%s doesn't exist\n", dvarName);
        return;
    }

    /* Check if it's a string-based dvar (type 6 or 7) */
    if ((unsigned char)(dvar->type - 6) > 1) {
        Com_Printf("%s is not a string-based dvar\n", dvar->name);
        return;
    }

    text = va("%s\n", dvar->current.string);
    Cbuf_InsertText(text);
}

/* line 649 */
int Cmd_Argc(void)
{
    return cmd_argc;
}

/* line 660 */
int SV_Cmd_Argc(void)
{
    return cmd_argc;
}

/* line 677 */
char * Cmd_Argv(int arg)
{
    if (cmd_argc > arg) {
        return cmd_argv[arg];
    }
    return "";
}

/* line 694 */
char * SV_Cmd_Argv(int arg)
{
    if (cmd_argc > arg) {
        return cmd_argv[arg];
    }
    return "";
}

/* line 726 */
void Cmd_ArgvBuffer(int arg, char *buffer, int bufferLength)
{
    I_strncpyz(buffer, Cmd_Argv(arg), bufferLength);
}

/* line 740 */
void SV_Cmd_ArgvBuffer(int arg, char *buffer, int bufferLength)
{
    I_strncpyz(buffer, SV_Cmd_Argv(arg), bufferLength);
}

/* line 753 */
char * Cmd_Args(int start)
{
    int i;

    cmd_args1[0] = '\0';
    if (start >= cmd_argc) {
        return cmd_args1;
    }

    for (i = start; i < cmd_argc; i++) {
        I_strncat(cmd_args1, 0x400, cmd_argv[i]);
        if (i != cmd_argc - 1) {
            I_strncat(cmd_args1, 0x400, " ");
        }
    }

    return cmd_args1;
}

/* line 782 */
void Cmd_ArgsBuffer(char *buffer, int bufferLength)
{
    int i;

    cmd_args1[0] = '\0';
    if (cmd_argc > 1) {
        for (i = 1; i < cmd_argc; i++) {
            I_strncat(cmd_args1, 0x400, cmd_argv[i]);
            if (i != cmd_argc - 1) {
                I_strncat(cmd_args1, 0x400, " ");
            }
        }
    }

    I_strncpyz(buffer, cmd_args1, bufferLength);
}

/* line 798 */
static int Cmd_TokenizeStringInternal(const char *text_in, char **argv, int max_tokens, char *textOut)
{
    int argc;
    int tokens;

    argc = 0;
    tokens = 0;
    max_tokens -= 1;

    while (1) {
        if (tokens == max_tokens) {
            /* reached token limit: copy rest of string as final token */
            if (*text_in == '\0') {
                break;
            }
            argv[argc] = textOut;
            argc++;
            while (*text_in) {
                *textOut++ = *text_in++;
            }
            *textOut = '\0';
            break;
        }

        /* skip whitespace */
        while (*text_in && *text_in <= ' ') {
            text_in++;
        }
        if (*text_in == '\0') {
            break;
        }

        /* skip // comments */
        if (text_in[0] == '/' && text_in[1] == '/') {
            break;
        }

        /* skip /* comments */
        if (text_in[0] == '/' && text_in[1] == '*') {
            text_in++;
            while (*text_in) {
                if (*text_in == '*' && text_in[1] == '/') {
                    text_in += 2;
                    break;
                }
                text_in++;
            }
            continue;
        }

        /* handle quoted strings */
        if (*text_in == '"') {
            argv[argc] = textOut;
            argc++;
            text_in++;
            while (*text_in) {
                if (*text_in == '"') {
                    break;
                }
                if (*text_in == '\\' && text_in[1] == '"') {
                    text_in += 2;
                } else {
                    *textOut = *text_in;
                    textOut++;
                    text_in++;
                }
            }
            *textOut++ = '\0';
            if (*text_in == '\0') {
                break;
            }
            text_in++;
            if (*text_in == '\0') {
                break;
            }
            if (*text_in <= ' ') {
                text_in++;
            }
            tokens++;
            if (argc == 512) {
                argc = 0;
            }
            continue;
        }

        /* regular token */
        argv[argc] = textOut;
        argc++;
        while (*text_in > ' ') {
            if (*text_in == '"') {
                break;
            }
            if (*text_in == '/') {
                if (text_in[1] == '/' || text_in[1] == '*') {
                    break;
                }
            }
            *textOut = *text_in;
            textOut++;
            text_in++;
        }
        *textOut++ = '\0';
        if (*text_in == '\0') {
            break;
        }
        if (*text_in > ' ') {
            tokens++;
            if (argc == 512) {
                argc = 0;
            }
            continue;
        }
        text_in++;

        tokens++;
        if (argc == 512) {
            argc = 0;
        }
    }

    return argc;
}

/* line 955 */
void Cmd_TokenizeString2(const char *text_in, int max_tokens)
{
    cmd_argc = Cmd_TokenizeStringInternal(text_in, cmd_argv, max_tokens, cmd_tokenized);
}

/* line 985 */
void Cmd_TokenizeString(const char *text_in)
{
    cmd_argc = Cmd_TokenizeStringInternal(text_in, cmd_argv, 0, cmd_tokenized);
}

/* line 991 */
void SV_Cmd_TokenizeString(const char *text_in)
{
    cmd_argc = Cmd_TokenizeStringInternal(text_in, cmd_argv, 0, cmd_tokenized);
}

/* line 1010 */
void Cmd_AddCommand(const char *cmdName, xcommand_t function)
{
    cmd_function_t *cmd;

    /* check if already exists */
    for (cmd = cmd_functions; cmd; cmd = (cmd_function_t *)cmd->next) {
        if (!strcmp(cmdName, cmd->name)) {
            if (function) {
                Com_Printf("Cmd_AddCommand: %s already defined\n", cmdName);
            }
            return;
        }
    }

    cmd = (cmd_function_t *)Z_MallocInternal(0x14);
    cmd->name = CopyStringInternal(cmdName);
    cmd->function = function;
    cmd->next = (int)cmd_functions;
    cmd_functions = cmd;
}

/* line 1035 */
void Cmd_RemoveCommand(const char *cmdName)
{
    cmd_function_t *cmd;
    cmd_function_t **back;

    back = &cmd_functions;
    for (cmd = cmd_functions; cmd; cmd = (cmd_function_t *)cmd->next) {
        if (!strcmp(cmdName, cmd->name)) {
            *back = (cmd_function_t *)cmd->next;
            if (cmd->name) {
                Z_FreeInternal(cmd->name);
            }
            Z_FreeInternal(cmd);
            return;
        }
        back = (cmd_function_t **)&cmd->next;
    }
}

/* line 1063 */
void Cmd_SetAutoComplete(const char *cmdName, const char *dir, const char *ext)
{
    cmd_function_t *cmd;

    for (cmd = cmd_functions; cmd; cmd = (cmd_function_t *)cmd->next) {
        if (!strcmp(cmdName, cmd->name)) {
            break;
        }
    }

    cmd->autoCompleteDir = dir;
    cmd->autoCompleteExt = ext;
}

/* line 1087 */
void Cmd_Shutdown(void)
{
    cmd_function_t *cmd;

    while (cmd_functions) {
        cmd = cmd_functions;
        cmd_functions = (cmd_function_t *)cmd->next;
        Z_FreeInternal(cmd->name);
        Z_FreeInternal(cmd);
    }
}

/* line 1113 */
void Cmd_ForEach(void (*callback)())
{
    cmd_function_t *cmd;

    for (cmd = cmd_functions; cmd; cmd = (cmd_function_t *)cmd->next) {
        callback(cmd->name);
    }
}

/* line 1124 */
const char * * Cmd_GetAutoCompleteFileList(const char *cmdName, int *fileCount, int allocTrackType)
{
    cmd_function_t *cmd;

    *fileCount = 0;

    for (cmd = cmd_functions; cmd; cmd = (cmd_function_t *)cmd->next) {
        if (!strcmp(cmdName, cmd->name)) {
            break;
        }
    }

    if (!cmd->autoCompleteDir || !cmd->autoCompleteExt) {
        return 0;
    }

    return FS_ListFiles(cmd->autoCompleteDir, cmd->autoCompleteExt, 0, fileCount, allocTrackType);
}

/* line 1151 */
void Cmd_ExecuteString(const char *text)
{
    cmd_function_t *cmd;
    cmd_function_t **prev;

    cmd_argc = Cmd_TokenizeStringInternal(text, cmd_argv, 0, cmd_tokenized);
    if (!cmd_argc) {
        return;
    }

    /* search for command */
    prev = &cmd_functions;
    for (cmd = cmd_functions; cmd; cmd = (cmd_function_t *)cmd->next) {
        if (!I_stricmp(cmd_argv[0], cmd->name)) {
            /* move to front of list for faster future lookups */
            *prev = (cmd_function_t *)cmd->next;
            cmd->next = (int)cmd_functions;
            cmd_functions = cmd;

            if (cmd->function) {
                cmd->function();
            }
            return;
        }
        prev = (cmd_function_t **)&cmd->next;
    }

    /* check dvars */
    if (Dvar_Command()) {
        return;
    }

    /* check client game */
    if (*(int *)(*(byte **)ptr_195ecb4 + 4)) {
        if (CL_GameCommand()) {
            return;
        }
    }

    /* check server game */
    if (*(byte **)ptr_195ecbc && *(byte *)(*(byte **)ptr_195ecbc + 8)) {
        if (SV_GameCommand()) {
            return;
        }
    }

    CL_ForwardCommandToServer(text);
}

/* line 1238 */
void SV_Cmd_ExecuteString(const char *text)
{
    Cmd_ExecuteString(text);
}

/* line 1250 */
void Cmd_List_f(void)
{
    cmd_function_t *cmd;
    int i;
    const char *match;

    if (cmd_argc > 1) {
        match = cmd_argv[1];
    } else {
        match = 0;
    }

    i = 0;
    for (cmd = cmd_functions; cmd; cmd = (cmd_function_t *)cmd->next) {
        if (match) {
            if (!Com_Filter(match, cmd->name, 0)) {
                continue;
            }
        }
        Com_Printf("%s\n", cmd->name);
        i++;
    }
    Com_Printf("%i commands\n", i);
}

/* line 1285 */
void Cmd_Init(void)
{
    Cmd_AddCommand("cmdlist", Cmd_List_f);
    Cmd_AddCommand("exec", Cmd_Exec_f);
    Cmd_AddCommand("vstr", Cmd_Vstr_f);
    Cmd_AddCommand("wait", Cmd_Wait_f);
}
