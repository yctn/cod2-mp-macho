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
extern void Com_Printf(const char *fmt, ...);
extern unsigned int FindNextSibling(unsigned int id);
extern unsigned int GetVariableName(unsigned int id);

void DumpCompiledObject(const char *label, unsigned int compiledObj)
{
    unsigned int child;
    unsigned int funcObj;
    unsigned int posVar;
    unsigned int fwdRef;
    int count = 0;

    Com_Printf("--- DumpCompiledObject: %s (obj=%u) ---\n", label, compiledObj);
    child = FindNextSibling(compiledObj);
    while (child != 0) {
        unsigned int name = GetVariableName(child);
        const char *nameStr = SL_ConvertToString(name);
        funcObj = FindObject(child);
        posVar = FindVariable(funcObj, 1);
        fwdRef = FindVariable(funcObj, 0);
        Com_Printf("  [%d] name='%s' (id=%u) obj=%u posVar=%u fwdRef=%u\n",
                   count, nameStr, name, funcObj, posVar, fwdRef);
        count++;
        child = FindNextSibling(child);
        if (count > 20) break;
    }
    Com_Printf("--- total: %d entries ---\n", count);
}
extern byte *TempMalloc(int size);
extern void TempMemoryReset(void);
extern void *Hunk_AllocLowInternal(int size);
extern void *Hunk_AllocInternal(int size);
extern void Hunk_ClearToMark(int mark);
extern int Hunk_SetMark(void);
extern void Hunk_ConvertTempToPermLowInternal(void);

/* Using imp_* import pointers from generated_syms.h (declared as void*) */

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
    byte *scrVarPub = (byte *)imp_scrVarPub;
    byte *scrCompPub = (byte *)imp_scrCompilePub;

    return (unsigned int)(pos - *(const char **)(scrVarPub + 0x48)) < *(unsigned int *)(scrCompPub + 0x30);
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
    byte *scrCompPub = (byte *)imp_scrCompilePub;
    byte *scrVarPub;
    unsigned short *entry;
    unsigned short val;

    SL_TransferRefToUser(stringValue, 2);

    entry = (unsigned short *)(*(byte **)(scrCompPub + 0x18) + stringValue * 2);
    val = *entry;

    if (val != 0)
        return val;

    scrVarPub = (byte *)imp_scrVarPub;
    val = *(unsigned short *)(scrVarPub + 8) + 1;
    *(unsigned short *)(scrVarPub + 8) = val;
    *entry = val;
    return *(unsigned short *)(scrVarPub + 8);
}

/* line 261 */
void Scr_BeginLoadAnimTrees(int user)
{
    byte *scrAnimPub = (byte *)imp_scrAnimPub;
    byte *scrCompPub;

    *(byte *)(scrAnimPub + 0x418) = 1;
    *(int *)(scrAnimPub + 0x40c + user * 4) = 0;
    *(int *)(scrAnimPub + 0xc + (user << 9)) = 0;

    *(int *)scrAnimPub = Scr_AllocArray();
    *(int *)(scrAnimPub + 4) = 0;

    scrCompPub = (byte *)imp_scrCompilePub;
    *(int *)(scrCompPub + 0x28) = 0;
}

/* line 285 */
int Scr_ScanFile(char *buf, int max_size)
{
    byte *g = (byte *)imp_scrCompilePub;
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
    byte *scrCompPub = (byte *)imp_scrCompilePub;
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

    if (!filename) {
        return 0;
    }
    fileId = Scr_CreateCanonicalFilename(filename);

    result = FindVariable(*(unsigned int *)(scrCompPub + 8), fileId);
    if (result != 0) {
        /* Already loaded */
        SL_RemoveRefToString(fileId);
        result = FindVariable(*(unsigned int *)(scrCompPub + 0xc), fileId);
        if (result == 0)
            return 0;
        return FindObject(result);
    }

    /* Not loaded - compile */
    scriptId = GetNewVariable(*(unsigned int *)(scrCompPub + 8), fileId);
    SL_RemoveRefToString(fileId);

    Com_sprintf(extFilename, 0x40, "%s.gsc", SL_ConvertToString(fileId));

    parserPub = (byte *)imp_scrParserPub;
    oldSourceBuf = *(int *)(parserPub + 0xc);

    oldFilename = TempMalloc(0);
    sourceBuf = Scr_AddSourceBuffer(SL_ConvertToString(fileId), extFilename, oldFilename, 1);
    if (sourceBuf == NULL)
        return 0;

    *(int *)((byte *)imp_scrAnimPub + 8) = 0;
    *(int *)(scrCompPub + 4) = 0;

    parserPub = (byte *)imp_scrParserPub;
    savedParserFilename = *(byte **)(parserPub + 8);
    *(byte **)(parserPub + 8) = (byte *)extFilename;

    *(byte **)(scrCompPub + 0x1c) = (byte *)"+";
    *(byte **)(scrCompPub + 0x20) = sourceBuf;

    ScriptParse((byte *)&parseData, 0);

    compiledObj = GetObjectA(GetVariable(*(unsigned int *)(scrCompPub + 0xc), fileId));
    DumpCompiledObject(extFilename, compiledObj);
    ScriptCompile(parseData, compiledObj, scriptId);
    DumpCompiledObject(extFilename, compiledObj);

    parserPub = (byte *)imp_scrParserPub;
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
    extern void DBG_PrintFreeVars(const char *label);
    byte *scrCompPub = (byte *)imp_scrCompilePub;
    byte *scrVarPub = (byte *)imp_scrVarPub;

    DBG_PrintFreeVars("EndLoad:entry");

    *(int *)(scrCompPub + 0x18) = 0;
    Hunk_ClearToMark(*(int *)(scrVarPub + 4));
    SL_ShutdownSystem(2);

    DBG_PrintFreeVars("EndLoad:after SL_Shutdown");

    *(byte *)(scrCompPub + 0x24) = 0;

    Com_Printf("DBG EndLoad: obj8=%u objC=%u obj10=%u obj14=%u\n",
        *(unsigned int *)(scrCompPub + 8),
        *(unsigned int *)(scrCompPub + 0xc),
        *(unsigned int *)(scrCompPub + 0x10),
        *(unsigned int *)(scrCompPub + 0x14));

    ClearObject(*(unsigned int *)(scrCompPub + 8));
    RemoveRefToObject(*(unsigned int *)(scrCompPub + 8));
    *(int *)(scrCompPub + 8) = 0;
    DBG_PrintFreeVars("EndLoad:after clear obj8");

    ClearObject(*(unsigned int *)(scrCompPub + 0xc));
    RemoveRefToObject(*(unsigned int *)(scrCompPub + 0xc));
    *(int *)(scrCompPub + 0xc) = 0;
    DBG_PrintFreeVars("EndLoad:after clear objC");

    ClearObject(*(unsigned int *)(scrCompPub + 0x10));
    RemoveRefToObject(*(unsigned int *)(scrCompPub + 0x10));
    *(int *)(scrCompPub + 0x10) = 0;
    DBG_PrintFreeVars("EndLoad:after clear obj10");

    ClearObject(*(unsigned int *)(scrCompPub + 0x14));
    RemoveRefToObject(*(unsigned int *)(scrCompPub + 0x14));
    *(int *)(scrCompPub + 0x14) = 0;
    DBG_PrintFreeVars("EndLoad:after clear obj14");
}

/* line 444 */
void Scr_PrecacheAnimTrees(Alloc_t Alloc, int user)
{
    byte *scrAnimPub = (byte *)imp_scrAnimPub;
    int count = *(int *)(scrAnimPub + 0x40c + user * 4);
    int i;

    Com_Printf("DBG Scr_PrecacheAnimTrees: user=%d count=%d Alloc=%p\n", user, count, Alloc);

    if (count <= 0)
        return;

    for (i = 1; i <= count; i++) {
        Scr_LoadAnimTreeAtIndex(i, Alloc, user);
    }
}

/* line 453 */
void Scr_EndLoadAnimTrees(void)
{
    byte *scrAnimPub = (byte *)imp_scrAnimPub;
    byte *scrVarPub;

    ClearObject(*(unsigned int *)scrAnimPub);
    RemoveRefToObject(*(unsigned int *)scrAnimPub);
    *(int *)scrAnimPub = 0;

    if (*(int *)(scrAnimPub + 4) != 0)
        RemoveRefToObject(*(unsigned int *)(scrAnimPub + 4));

    SL_ShutdownSystem(2);

    scrVarPub = (byte *)imp_scrVarPub;
    *(int *)(scrVarPub + 0x4c) = (int)Hunk_AllocLowInternal(0);
    *(byte *)(scrAnimPub + 0x418) = 0;
}

/* line 478 */
void Scr_FreeScripts(int sys)
{
    byte *scrCompPub = (byte *)imp_scrCompilePub;
    byte *scrAnimPub;
    byte *scrVarPub;

    if (*(byte *)(scrCompPub + 0x24) != 0) {
        *(byte *)(scrCompPub + 0x24) = 0;
        Scr_EndLoadScripts();
    }

    scrAnimPub = (byte *)imp_scrAnimPub;
    if (*(byte *)(scrAnimPub + 0x418) != 0) {
        *(byte *)(scrAnimPub + 0x418) = 0;
        Scr_EndLoadAnimTrees();
    }

    SL_ShutdownSystem(sys);
    Scr_ShutdownOpcodeLookup();

    /* Only zero code base on full shutdown (sys=0), not during init (sys=1).
       Scr_BeginLoadScripts will set the code base for the next load. */
    if (sys == 0) {
        scrVarPub = (byte *)imp_scrVarPub;
        *(int *)(scrVarPub + 0x48) = 0;
        *(int *)(scrCompPub + 0x30) = 0;
        *(int *)(scrVarPub + 0x4c) = 0;
        *(int *)(scrVarPub + 0x3c) = 0;
    }
}

/* line 67 */
scr_func_t Scr_GetFunctionHandle(const char *filename, const char *name)
{
    byte *scrCompPub = (byte *)imp_scrCompilePub;
    byte *scrVarPub;
    unsigned int nameStr;
    unsigned int fileId;
    unsigned int fileObj;
    unsigned int varId;
    unsigned int obj;
    unsigned int codeVar;
    unsigned int codePos;

    nameStr = Scr_CreateCanonicalFilename(filename);
    fileId = FindVariable(*(unsigned int *)(scrCompPub + 0xc), nameStr);
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

    scrVarPub = (byte *)imp_scrVarPub;
    codePos -= *(unsigned int *)(scrVarPub + 0x48);
    if (codePos >= *(unsigned int *)(scrCompPub + 0x30))
        return 0;

    return (scr_func_t)codePos;
}

/* line 165 */
void Scr_BeginLoadScripts(void)
{
    byte *scrCompPub = (byte *)imp_scrCompilePub;
    byte *scrVarPub;

    *(byte *)(scrCompPub + 0x24) = 1;
    Scr_InitOpcodeLookup();

    *(int *)(scrCompPub + 0x8) = Scr_AllocArray();
    *(int *)(scrCompPub + 0xc) = Scr_AllocArray();
    *(int *)(scrCompPub + 0x10) = Scr_AllocArray();
    *(int *)(scrCompPub + 0x14) = Scr_AllocArray();

    scrVarPub = (byte *)imp_scrVarPub;
    *(int *)(scrVarPub + 0x48) = (int)Hunk_AllocLowInternal(0);
    *(int *)(scrCompPub + 0x30) = 0;
    *(int *)(scrVarPub + 0x4c) = 0;

    *(int *)(scrVarPub + 4) = Hunk_SetMark();
    *(int *)(scrCompPub + 0x18) = (int)Hunk_AllocInternal(0x20000);
    *(short *)(scrVarPub + 8) = 0;

    *(int *)scrVarPub = 0;
    *(int *)scrCompPub = 0;

    Scr_ClearErrorMessage();
    *(int *)(scrCompPub + 0x34) = 0;

    Scr_BeginLoadAnimTrees(1);
    TempMemoryReset();
}

/* line 154 */
unsigned int SL_GetCanonicalString(const char *str)
{
    byte *scrCompPub = (byte *)imp_scrCompilePub;
    byte *table = *(byte **)(scrCompPub + 0x18);
    unsigned int stringValue;
    unsigned short val;

    stringValue = SL_FindString(str);
    val = *(unsigned short *)(table + stringValue * 2);
    if (val != 0)
        return val;

    stringValue = SL_GetString_(str, 0, 0xf);
    return SL_TransferToCanonicalString(stringValue);
}
