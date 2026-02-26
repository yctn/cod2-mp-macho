/* Converted to C from ASM: scr_main.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/script/scr_main.cpp */

#include "common_types.h"
#include "imports.h"

extern byte *__DefaultRuneLocale;
extern int ___maskrune(int ch, unsigned int mask);

extern void SL_TransferRefToUser(unsigned int stringValue, int user);
extern void SL_RemoveRefToString(unsigned int stringValue);
extern const char *SL_ConvertToString(unsigned int stringValue);
extern unsigned int SL_FindString(const char *str);
extern unsigned int SL_GetString_(const char *str, int user, int flags);
extern unsigned int SL_FindLowercaseString(const char *str);
extern void SL_ShutdownSystem(int user);

extern unsigned int Scr_CreateCanonicalFilename(const char *filename);
extern byte *Scr_AddSourceBuffer(const char *filename, const char *extFilename, byte *oldFilename, int flag);
extern int Scr_AllocArray(void);
extern void Scr_LoadAnimTreeAtIndex(int index, Alloc_t Alloc, int user);
extern void Scr_InitOpcodeLookup(void);
extern void Scr_ShutdownOpcodeLookup(void);
extern void Scr_ClearErrorMessage(void);
extern int Scr_EvalVariable(unsigned int varId);

extern void ScriptParse(byte *parseData, int flag);
extern void ScriptCompile(int parseData, unsigned int compiledObj, unsigned int scriptId);

extern unsigned int FindVariable(unsigned int parent, unsigned int name);
extern unsigned int GetNewVariable(unsigned int parent, unsigned int name);
extern unsigned int GetVariable(unsigned int parent, unsigned int name);
extern unsigned int FindObject(unsigned int varId);
extern unsigned int GetObjectA(unsigned int varId);
extern unsigned int GetVarType(unsigned int varId);
extern void ClearObject(unsigned int objId);
extern void RemoveRefToObject(unsigned int objId);

extern void Com_sprintf(char *dest, int size, const char *fmt, ...);
extern byte *TempMalloc(int size);
extern void TempMemoryReset(void);
extern void *Hunk_AllocLowInternal(int size);
extern void *Hunk_AllocInternal(int size);
extern void Hunk_ClearToMark(int mark);
extern int Hunk_SetMark(void);
extern void Hunk_ConvertTempToPermLowInternal(void);

extern byte *scrCompPub_ptr;    /* 0x195ee58 */
extern byte *scrCompGlob_ptr;   /* 0x195ee5c */
extern byte *scrAnimPub_ptr;    /* 0x195ee54 */
extern byte *scrParserPub_ptr;  /* 0x195ee64 */

int Scr_IsInOpcodeMemory(const char *pos);
Bool Scr_IsIdentifier(const char *token);
unsigned int SL_TransferToCanonicalString(unsigned int stringValue);
void Scr_BeginLoadAnimTrees(int user);
int Scr_ScanFile(char *buf, int max_size);
unsigned int Scr_LoadScript(const char *filename);
void Scr_PostCompileScripts(void);
void Scr_EndLoadScripts(void);
void Scr_PrecacheAnimTrees(Alloc_t Alloc, int user);
void Scr_EndLoadAnimTrees(void);
void Scr_FreeScripts(int sys);
scr_func_t Scr_GetFunctionHandle(const char *filename, const char *name);
void Scr_BeginLoadScripts(void);
unsigned int SL_GetCanonicalString(const char *str);

/* line 22 */
int Scr_IsInOpcodeMemory(const char *pos)
{
    byte *scrCompPub = *(byte **)scrCompPub_ptr;
    byte *scrCompGlob = *(byte **)scrCompGlob_ptr;

    return (unsigned int)(pos - *(const char **)(scrCompPub + 0x48)) < *(unsigned int *)(scrCompGlob + 0x30);
}

/* line 55 */
Bool Scr_IsIdentifier(const char *token)
{
    byte *runeLocale = *(byte **)&__DefaultRuneLocale;
    const char *s = token;
    char ch = *s;

    while (ch) {
        int isAlnum;
        int sch = (signed char)ch;

        if (sch & ~0x7f) {
            isAlnum = ___maskrune(sch, 0x500) != 0;
        } else {
            isAlnum = (*(int *)(runeLocale + 0x34 + sch * 4) & 0x500) != 0;
        }

        if (!isAlnum && ch != '_')
            return 0;

        s++;
        ch = *s;
    }

    return 1;
}

/* line 138 */
unsigned int SL_TransferToCanonicalString(unsigned int stringValue)
{
    byte *scrCompGlob = *(byte **)scrCompGlob_ptr;
    byte *scrCompPub;
    unsigned short *entry;
    unsigned short val;

    SL_TransferRefToUser(stringValue, 2);

    entry = (unsigned short *)(*(byte **)(scrCompGlob + 0x18) + stringValue * 2);
    val = *entry;

    if (val != 0)
        return val;

    scrCompPub = *(byte **)scrCompPub_ptr;
    val = *(unsigned short *)(scrCompPub + 8) + 1;
    *(unsigned short *)(scrCompPub + 8) = val;
    *entry = val;
    return *(unsigned short *)(scrCompPub + 8);
}

/* line 261 */
void Scr_BeginLoadAnimTrees(int user)
{
    byte *scrAnimPub = *(byte **)scrAnimPub_ptr;
    byte *scrCompGlob;

    *(byte *)(scrAnimPub + 0x418) = 1;
    *(int *)(scrAnimPub + 0x40c + user * 4) = 0;
    *(int *)(scrAnimPub + 0xc + (user << 9)) = 0;

    *(int *)scrAnimPub = Scr_AllocArray();
    *(int *)(scrAnimPub + 4) = 0;

    scrCompGlob = *(byte **)scrCompGlob_ptr;
    *(int *)(scrCompGlob + 0x28) = 0;
}

/* line 285 */
int Scr_ScanFile(char *buf, int max_size)
{
    byte *g = *(byte **)scrCompGlob_ptr;
    byte *src;
    char ch;
    int count;

    if (max_size <= 0)
        return 0;

    /* Read first character */
    src = *(byte **)(g + 0x1c);
    ch = *src;
    src++;
    *(byte **)(g + 0x1c) = src;

    if (ch == '\0') {
        count = 0;
        goto source_exhausted;
    }

    if (ch == '\n') {
        buf[0] = '\n';
        return 1;
    }

    count = 0;
    for (;;) {
        buf[count] = ch;
        count++;

        if (count == max_size) {
            if (ch == '\n') {
                buf[count] = '\n';
                return count + 1;
            }
            if (ch != '\0')
                return count;
            goto source_exhausted;
        }

        src = *(byte **)(g + 0x1c);
        ch = *src;
        src++;
        *(byte **)(g + 0x1c) = src;

        if (ch == '\0')
            goto source_exhausted;

        if (ch == '\n') {
            buf[count] = '\n';
            return count + 1;
        }
    }

source_exhausted:
    if (*(byte **)(g + 0x20) != NULL) {
        *(byte **)(g + 0x1c) = *(byte **)(g + 0x20);
        *(byte **)(g + 0x20) = NULL;
    } else {
        *(byte **)(g + 0x1c) -= 1;
    }
    return count;
}

/* line 313 */
unsigned int Scr_LoadScript(const char *filename)
{
    byte *scrCompGlob = *(byte **)scrCompGlob_ptr;
    unsigned int fileId;
    unsigned int scriptId;
    char extFilename[64];
    int parseData;
    byte *parserPub;
    int oldSourceBuf;
    byte *oldFilename;
    byte *sourceBuf;
    byte *savedParserFilename;
    unsigned int compiledObj;
    unsigned int result;

    fileId = Scr_CreateCanonicalFilename(filename);

    result = FindVariable(*(unsigned int *)(scrCompGlob + 8), fileId);
    if (result != 0) {
        /* Already loaded */
        SL_RemoveRefToString(fileId);
        result = FindVariable(*(unsigned int *)(scrCompGlob + 0xc), fileId);
        if (result == 0)
            return 0;
        return FindObject(result);
    }

    /* Not loaded - compile */
    scriptId = GetNewVariable(*(unsigned int *)(scrCompGlob + 8), fileId);
    SL_RemoveRefToString(fileId);

    Com_sprintf(extFilename, 0x40, "%s.gsc", SL_ConvertToString(fileId));

    parserPub = *(byte **)scrParserPub_ptr;
    oldSourceBuf = *(int *)(parserPub + 0xc);

    oldFilename = TempMalloc(0);
    sourceBuf = Scr_AddSourceBuffer(SL_ConvertToString(fileId), extFilename, oldFilename, 1);
    if (sourceBuf == NULL)
        return 0;

    *(int *)(*(byte **)scrAnimPub_ptr + 8) = 0;
    *(int *)(scrCompGlob + 4) = 0;

    parserPub = *(byte **)scrParserPub_ptr;
    savedParserFilename = *(byte **)(parserPub + 8);
    *(byte **)(parserPub + 8) = (byte *)extFilename;

    *(byte **)(scrCompGlob + 0x1c) = (byte *)"+";
    *(byte **)(scrCompGlob + 0x20) = sourceBuf;

    ScriptParse((byte *)&parseData, 0);

    compiledObj = GetObjectA(GetVariable(*(unsigned int *)(scrCompGlob + 0xc), fileId));
    ScriptCompile(parseData, compiledObj, scriptId);

    parserPub = *(byte **)scrParserPub_ptr;
    *(byte **)(parserPub + 8) = savedParserFilename;
    *(int *)(parserPub + 0xc) = oldSourceBuf;

    return compiledObj;
}

/* line 374 */
void Scr_PostCompileScripts(void)
{
    Hunk_ConvertTempToPermLowInternal();
}

/* line 383 */
void Scr_EndLoadScripts(void)
{
    byte *scrCompGlob = *(byte **)scrCompGlob_ptr;
    byte *scrCompPub = *(byte **)scrCompPub_ptr;

    *(int *)(scrCompGlob + 0x18) = 0;
    Hunk_ClearToMark(*(int *)(scrCompPub + 4));
    SL_ShutdownSystem(2);

    *(byte *)(scrCompGlob + 0x24) = 0;

    ClearObject(*(unsigned int *)(scrCompGlob + 8));
    RemoveRefToObject(*(unsigned int *)(scrCompGlob + 8));
    *(int *)(scrCompGlob + 8) = 0;

    ClearObject(*(unsigned int *)(scrCompGlob + 0xc));
    RemoveRefToObject(*(unsigned int *)(scrCompGlob + 0xc));
    *(int *)(scrCompGlob + 0xc) = 0;

    ClearObject(*(unsigned int *)(scrCompGlob + 0x10));
    RemoveRefToObject(*(unsigned int *)(scrCompGlob + 0x10));
    *(int *)(scrCompGlob + 0x10) = 0;

    ClearObject(*(unsigned int *)(scrCompGlob + 0x14));
    RemoveRefToObject(*(unsigned int *)(scrCompGlob + 0x14));
    *(int *)(scrCompGlob + 0x14) = 0;
}

/* line 444 */
void Scr_PrecacheAnimTrees(Alloc_t Alloc, int user)
{
    byte *scrAnimPub = *(byte **)scrAnimPub_ptr;
    int count = *(int *)(scrAnimPub + 0x40c + user * 4);
    int i;

    if (count <= 0)
        return;

    for (i = 1; i <= count; i++) {
        Scr_LoadAnimTreeAtIndex(i, Alloc, user);
    }
}

/* line 453 */
void Scr_EndLoadAnimTrees(void)
{
    byte *scrAnimPub = *(byte **)scrAnimPub_ptr;
    byte *scrCompPub;

    ClearObject(*(unsigned int *)scrAnimPub);
    RemoveRefToObject(*(unsigned int *)scrAnimPub);
    *(int *)scrAnimPub = 0;

    if (*(int *)(scrAnimPub + 4) != 0)
        RemoveRefToObject(*(unsigned int *)(scrAnimPub + 4));

    SL_ShutdownSystem(2);

    scrCompPub = *(byte **)scrCompPub_ptr;
    *(int *)(scrCompPub + 0x4c) = (int)Hunk_AllocLowInternal(0);
    *(byte *)(scrAnimPub + 0x418) = 0;
}

/* line 478 */
void Scr_FreeScripts(int sys)
{
    byte *scrCompGlob = *(byte **)scrCompGlob_ptr;
    byte *scrAnimPub;
    byte *scrCompPub;

    if (*(byte *)(scrCompGlob + 0x24) != 0) {
        *(byte *)(scrCompGlob + 0x24) = 0;
        Scr_EndLoadScripts();
    }

    scrAnimPub = *(byte **)scrAnimPub_ptr;
    if (*(byte *)(scrAnimPub + 0x418) != 0) {
        *(byte *)(scrAnimPub + 0x418) = 0;
        Scr_EndLoadAnimTrees();
    }

    SL_ShutdownSystem(1);
    Scr_ShutdownOpcodeLookup();

    scrCompPub = *(byte **)scrCompPub_ptr;
    *(int *)(scrCompPub + 0x48) = 0;
    *(int *)(scrCompGlob + 0x30) = 0;
    *(int *)(scrCompPub + 0x4c) = 0;
    *(int *)(scrCompPub + 0x3c) = 0;
}

/* line 67 */
scr_func_t Scr_GetFunctionHandle(const char *filename, const char *name)
{
    byte *scrCompGlob = *(byte **)scrCompGlob_ptr;
    byte *scrCompPub;
    unsigned int nameStr;
    unsigned int fileId;
    unsigned int fileObj;
    unsigned int varId;
    unsigned int obj;
    unsigned int codeVar;
    unsigned int codePos;

    nameStr = Scr_CreateCanonicalFilename(filename);
    fileId = FindVariable(*(unsigned int *)(scrCompGlob + 0xc), nameStr);
    SL_RemoveRefToString(nameStr);

    if (fileId == 0)
        return 0;

    fileObj = FindObject(fileId);
    nameStr = SL_FindLowercaseString(name);
    if (nameStr == 0)
        return 0;

    varId = FindVariable(fileObj, nameStr);
    if (varId == 0)
        return 0;

    if (GetVarType(varId) != 1)
        return 0;

    obj = FindObject(varId);
    codeVar = FindVariable(obj, 1);
    codePos = (unsigned int)Scr_EvalVariable(codeVar);

    scrCompPub = *(byte **)scrCompPub_ptr;
    codePos -= *(unsigned int *)(scrCompPub + 0x48);
    if (codePos >= *(unsigned int *)(scrCompGlob + 0x30))
        return 0;

    return (scr_func_t)codePos;
}

/* line 165 */
void Scr_BeginLoadScripts(void)
{
    byte *scrCompGlob = *(byte **)scrCompGlob_ptr;
    byte *scrCompPub;

    *(byte *)(scrCompGlob + 0x24) = 1;
    Scr_InitOpcodeLookup();

    *(int *)(scrCompGlob + 0x8) = Scr_AllocArray();
    *(int *)(scrCompGlob + 0xc) = Scr_AllocArray();
    *(int *)(scrCompGlob + 0x10) = Scr_AllocArray();
    *(int *)(scrCompGlob + 0x14) = Scr_AllocArray();

    scrCompPub = *(byte **)scrCompPub_ptr;
    *(int *)(scrCompPub + 0x48) = (int)Hunk_AllocLowInternal(0);
    *(int *)(scrCompGlob + 0x30) = 0;
    *(int *)(scrCompPub + 0x4c) = 0;

    *(int *)(scrCompPub + 4) = Hunk_SetMark();
    *(int *)(scrCompGlob + 0x18) = (int)Hunk_AllocInternal(0x20000);
    *(short *)(scrCompPub + 8) = 0;

    *(int *)scrCompPub = 0;
    *(int *)scrCompGlob = 0;

    Scr_ClearErrorMessage();
    *(int *)(scrCompGlob + 0x34) = 0;

    Scr_BeginLoadAnimTrees(1);
    TempMemoryReset();
}

/* line 154 */
unsigned int SL_GetCanonicalString(const char *str)
{
    byte *scrCompGlob = *(byte **)scrCompGlob_ptr;
    byte *table = *(byte **)(scrCompGlob + 0x18);
    unsigned int stringValue;
    unsigned short val;

    stringValue = SL_FindString(str);
    val = *(unsigned short *)(table + stringValue * 2);
    if (val != 0)
        return val;

    stringValue = SL_GetString_(str, 0, 0xf);
    return SL_TransferToCanonicalString(stringValue);
}
