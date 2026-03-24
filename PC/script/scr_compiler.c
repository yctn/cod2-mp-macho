/* ASM dump from: scr_compiler.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/script/scr_compiler.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/script/scr_variable.h"
 */

extern struct scrCompilePub_t scrCompilePub; /* 0x0 */
extern void Z_FreeInternal(void *ptr);
extern unsigned int FindVariable(unsigned int parentId, unsigned int value);
extern VariableValue Scr_EvalVariable(unsigned int id);
/* GetVariableValueAddress returns VariableUnion* (the type field follows at offset 4) */
extern VariableUnion *GetVariableValueAddress(unsigned int id);
extern int GetVarType(unsigned int id);
extern void CompileError2(int codePos, const char *msg);
extern unsigned char scrCompileGlob[];
extern void DumpCompiledObject(const char *label, unsigned int compiledObj);
static const char str_dbg_before_lt[] = "before-LinkThread";

static unsigned int LinkThread(unsigned int threadId, VariableUnion (*pos)[16]);
static unsigned int SpecifyThreadPosition(int type);
int CompareCaseInfo(const unsigned int *elem1, const unsigned int *elem2);
unsigned int Scr_CompileShutdown(void);
static unsigned int Scr_CalcLocalVarsVariableExpressionRef(void);
static Bool EvalPrimitiveExpression(void);
static Bool EvalBinaryOperatorExpression(sval_t opcode, sval_t sourcePos, VariableCompileValue *constValue);
static unsigned int Scr_CalcLocalVarsStatement(scr_block_t *block);
static unsigned int EmitValue(void);
static unsigned int EmitOpcode(unsigned int op, int offset, int callType);
static unsigned int EmitGetInteger(void);
static int Scr_FindLocalVarIndex(unsigned int name, sval_t sourcePos, Bool create, scr_block_t *block);
static unsigned int EmitContinueStatement(void);
static unsigned int EmitBreakStatement(void);
static unsigned int EmitFunction(sval_t sourcePos);
static unsigned int EmitCall(sval_t func_name, sval_t params, Bool bStatement, scr_block_t *block);
static Bool EmitOrEvalPrimitiveExpression(void);
static Bool EmitOrEvalExpression(void);
static unsigned int EmitPostFunctionCall(scr_block_t *block);
static unsigned int EmitMethod(sval_t expr, sval_t func_name, sval_t params, sval_t methodSourcePos, int bStatement, scr_block_t *block);
static unsigned int EmitPrimitiveExpressionFieldObject(void);
static unsigned int EmitVariableExpression(void);
static unsigned int EmitVariableExpressionRef(void);
static unsigned int EmitStatement(scr_block_t *block);
static unsigned int EmitIfStatement(sval_t stmt, int lastStatement, unsigned int endSourcePos, scr_block_t *block, sval_t *ifStatBlock);
static unsigned int EmitIfElseStatement(sval_t stmt1, sval_t stmt2, sval_t sourcePos, sval_t elseSourcePos, int lastStatement, unsigned int endSourcePos, scr_block_t *block, sval_t *ifStatBlock, sval_t *elseStatBlock);
static unsigned int EmitWhileStatement(sval_t expr, sval_t stmt, sval_t sourcePos, sval_t whileSourcePos, scr_block_t *block, sval_t *whileStatBlock);
static unsigned int EmitForStatement(sval_t expr, sval_t stmt2, sval_t stmt, sval_t sourcePos, sval_t forSourcePos, scr_block_t *block, sval_t *forStatBlock, sval_t *forStatPostBlock);
static unsigned int EmitSwitchStatement(sval_t sourcePos, int lastStatement, unsigned int endSourcePos, scr_block_t *block);
static unsigned int EmitThreadInternal(sval_t val, sval_t sourcePos, sval_t endSourcePos, scr_block_t *block);
void ScriptCompile(sval_t val, unsigned int fileId, unsigned int scriptId);
static unsigned int EmitDeveloperStatementList(sval_t val, scr_block_t *block, sval_t *devStatBlock);

/* ============================================================
 * New implementations: ScriptCompile and supporting functions
 * Ported from: CoD2rev_Server/src/script/scr_compiler.cpp
 * ============================================================ */

/* --- Type and constant definitions --- */
#define SCRCOMP_VAR_UNDEFINED       0
#define SCRCOMP_VAR_POINTER         1
#define SCRCOMP_VAR_CODEPOS         7
#define SCRCOMP_VAR_DEVELOPER_CODEPOS 12
#define SCRCOMP_VAR_INCLUDE_CODEPOS 13
#define SCRCOMP_VAR_INTEGER         6

#define SCRCOMP_SCR_DEV_NO          0
#define SCRCOMP_SCR_DEV_YES         1
#define SCRCOMP_SCR_DEV_IGNORE      2

#define SCRCOMP_SCR_ABORT_NONE      0

/* Note: ENUM_thread/begin_dev/end_dev/usingtree match reference (0x44-0x47).
   ENUM_include in OUR binary is 0x55 (reference uses 0x56 - one off due to
   ENUM_bad_statement being absent in the reference enum ordering). */
#define SCRCOMP_ENUM_thread                 0x44
#define SCRCOMP_ENUM_begin_developer_thread 0x45
#define SCRCOMP_ENUM_end_developer_thread   0x46
#define SCRCOMP_ENUM_usingtree              0x47
#define SCRCOMP_ENUM_include                0x55

#define SCRCOMP_FUNC_SCOPE_FAR      1

/* CALL_NONE constant for EmitOpcode */
#define SCRCOMP_CALL_NONE  0

/* SOURCE_TYPE constants for AddOpcodePos */
#define SCRCOMP_SOURCE_TYPE_NONE        0
#define SCRCOMP_SOURCE_TYPE_BREAKPOINT  1

/* OP_End opcode value */
#define SCRCOMP_OP_End  0x00

/* --- Extern declarations for functions used in new code --- */
/* Note: Scr_EvalVariable and GetVariableValueAddress are declared at file top */
/* From scr_variable.c - additional declarations */
extern void SetVariableValue(unsigned int id, VariableValue *value);
extern void SetNewVariableValue(unsigned int id, VariableValue *value);
extern unsigned int GetVariable(unsigned int parentId, unsigned int name);
extern unsigned int GetObjectA(unsigned int varId);
extern unsigned int FindObject(unsigned int varId);
extern unsigned int FindNextSibling(unsigned int id);
extern unsigned int GetVariableName(unsigned int id);
extern unsigned int GetObjectType(unsigned int id);
/* From scr_parser.c */
extern void CompileError(unsigned int sourcePos, const char *msg, ...);
extern void AddOpcodePos(unsigned int sourcePos, int type);
extern void AddThreadStartOpcodePos(unsigned int sourcePos);
/* From scr_main.c / scr_animtree.c */
extern unsigned int Scr_CreateCanonicalFilename(const char *filename);
extern unsigned int Scr_LoadScript(const char *filename);
/* From SL system */
extern const char *SL_ConvertToString(unsigned int stringValue);
extern void SL_RemoveRefToString(unsigned int stringValue);
extern void SL_AddRefToString(unsigned int stringValue);
extern void SL_TransferRefToUser(unsigned int stringValue, int user);
/* Hunk / memory */
extern void *Hunk_AllocateTempMemoryHighInternal(int size);
/* Z memory */
extern void *Z_MallocInternal(int size);
/* imp_ pointers for global structs */
extern void *imp_scrCompileGlob;
extern void *imp_scrCompilePub;
extern void *imp_scrVarPub;
extern void *imp_scrAnimPub;
/* Hunk_ClearTempMemoryHigh via imp_ */
extern void *imp_Hunk_ClearTempMemoryHigh;
/* TempMalloc */
extern byte *TempMalloc(int size);
extern void TempMemorySetPos(char *pos);
/* Scr_UsingTree from scr_animtree.c */
extern void Scr_UsingTree(const char *filename, unsigned int sourcePos);

/* --- Accessor macros for globals --- */
#define SCRCG  ((struct scrCompileGlob_t *)imp_scrCompileGlob)
#define SCRCP  ((struct scrCompilePub_t *)imp_scrCompilePub)
#define SCRVP  ((struct scrVarPub_t *)imp_scrVarPub)
#define SCRAP  ((struct scrAnimPub_t *)imp_scrAnimPub)

/* --- Typedef for Hunk_ClearTempMemoryHigh function pointer --- */
typedef void (*Hunk_ClearTempMemoryHigh_fn)(void);

/* --- Helper: call Hunk_ClearTempMemoryHigh via imp_ pointer --- */
static void call_Hunk_ClearTempMemoryHigh(void)
{
    ((Hunk_ClearTempMemoryHigh_fn)(*(void **)&imp_Hunk_ClearTempMemoryHigh))();
}

/* --- EmitByte: write one byte to temp memory --- */
static void EmitByte_new(byte value)
{
    SCRCG->codePos = (byte *)TempMalloc(sizeof(byte));
    *(byte *)SCRCG->codePos = value;
}

/* --- EmitEnd: emit OP_End opcode --- */
static void EmitEnd_new(void)
{
    /* Simplified: just emit the OP_End byte.
       The full EmitOpcode tracks cumulOffset etc., but for our minimal
       thread initialization we only need the opcode byte emitted. */
    EmitByte_new(SCRCOMP_OP_End);
}

/* --- InitThread: initialize thread state, emit first OP_End separator --- */
static void InitThread_new(int type)
{
    SCRCG->bCanIgnoreCase = 0;
    SCRCG->currentCaseStatement = NULL;
    SCRCG->bCanBreak = 0;
    SCRCG->bCanIgnoreBreak = 0;
    SCRCG->currentBreakStatement = NULL;
    SCRCG->bCanContinue = 0;
    SCRCG->bCanIgnoreContinue = 0;
    SCRCG->currentContinueStatement = NULL;
    SCRCG->breakChildBlocks = NULL;
    SCRCG->continueChildBlocks = NULL;

    if (!SCRCG->firstThread[type])
        return;

    SCRCG->firstThread[type] = 0;
    EmitEnd_new();

    AddOpcodePos(0, SCRCOMP_SOURCE_TYPE_NONE);
    AddOpcodePos(0xFFFFFFFE, SCRCOMP_SOURCE_TYPE_NONE);
}

/* --- SetThreadPosition: set the code position for a thread entry --- */
static void SetThreadPosition_new(unsigned int posId)
{
    VariableUnion *value;
    unsigned int varId;

    varId = FindVariable(posId, 1);
    value = GetVariableValueAddress(varId);
    value->codePosValue = (const char *)TempMalloc(0);
}

/* --- SpecifyThreadPosition_new: register a thread code position --- */
static unsigned int SpecifyThreadPosition_new(unsigned int posId, unsigned int name,
                                               unsigned int sourcePos, int type)
{
    unsigned int id;
    VariableValue pos;

    id = GetVariable(posId, 1);
    pos = Scr_EvalVariable(id);

    if (pos.type == SCRCOMP_VAR_UNDEFINED) {
        pos.type = type;
        pos.u.intValue = 0;
        SetNewVariableValue(id, &pos);
        return id;
    }

    if (pos.u.intValue)
        CompileError(sourcePos, "function '%s' already defined in '%s'",
                     SL_ConvertToString(name), "(unknown)");
    else
        CompileError(sourcePos, "function '%s' already defined",
                     SL_ConvertToString(name));

    return 0;
}

/* --- LinkThread_new: patch all forward references to a thread position ---
   This replaces the ASM-dump LinkThread above for use by ScriptCompile.    */
static void LinkThread_new(unsigned int threadCountId, VariableValue *pos, int allowFarCall)
{
    unsigned int countId, valueId;
    VariableValue count;
    VariableUnion *value;
    int type, i;

    countId = FindVariable(threadCountId, 0);
    if (!countId)
        return;

    count = Scr_EvalVariable(countId);

    for (i = 0; i < count.u.intValue; i++) {
        valueId = FindVariable(threadCountId, i + 2);
        value = GetVariableValueAddress(valueId);
        type = GetObjectType(valueId);

        if (pos->type == SCRCOMP_VAR_DEVELOPER_CODEPOS && type == SCRCOMP_VAR_CODEPOS) {
            CompileError2((int)value->codePosValue,
                          "normal script cannot reference a function in a /# ... #/ comment");
            continue;
        }

        if (pos->type == SCRCOMP_VAR_UNDEFINED) {
            CompileError2((int)value->codePosValue, "unknown function");
            continue;
        }

        if (!allowFarCall && *(intptr_t *)value->codePosValue == SCRCOMP_FUNC_SCOPE_FAR) {
            CompileError2((int)value->codePosValue, "unknown function");
            continue;
        }

        *(const char **)value->codePosValue = pos->u.codePosValue;
    }
}

/* --- Scr_CompileRemoveRefToString_new --- */
static void Scr_CompileRemoveRefToString_new(unsigned int stringValue)
{
    if (!stringValue)
        return;
    if (SCRCG->bConstRefCount)
        return;
    SL_RemoveRefToString(stringValue);
}

/* --- AddFilePrecache_new: register an #include file for later loading --- */
static unsigned int AddFilePrecache_new(unsigned int filename, unsigned int sourcePos, int include)
{
    SL_AddRefToString(filename);
    Scr_CompileRemoveRefToString_new(filename);

    SCRCG->precachescriptList->filename = filename;
    SCRCG->precachescriptList->sourcePos = sourcePos;
    SCRCG->precachescriptList->include = (Bool)include;
    SCRCG->precachescriptList++;

    return GetObjectA(GetVariable(SCRCP->scripts, filename));
}

/* --- EmitInclude_new: process a single #include node --- */
static void EmitInclude_new(sval_t val)
{
    sval_t *node = (sval_t *)val.node;
    unsigned int filename;

    /* val.node[0].type == SCRCOMP_ENUM_include */
    filename = Scr_CreateCanonicalFilename(SL_ConvertToString(node[1].stringValue));
    Scr_CompileRemoveRefToString_new(node[1].stringValue);

    AddFilePrecache_new(filename, node[2].sourcePosValue, 1 /* include=true */);
}

/* --- EmitIncludeList_new: process the #include list at file top ---
   The list structure (from linked_list_end + append_node) is:
     list = {sentinel_ptr, tail_ptr}
     sentinel = {dummy_node0, first_real_node_ptr}
     each real node = {item_value, next_node_ptr (0 if last)}
   We iterate starting from sentinel->next (skipping the dummy head).         */
static void EmitIncludeList_new(sval_t val)
{
    sval_t *node;
    /* val.node = list_ptr; list[0] = sentinel_ptr (as int).
       Skip sentinel: start from sentinel[1] = first_real_item_ptr. */
    sval_t *sentinel = (sval_t *)(((sval_t *)val.node)[0].node);

    for (node = (sval_t *)sentinel[1].node; node; node = (sval_t *)node[1].node) {
        EmitInclude_new(node[0]);
    }
}

/* --- Scr_CalcLocalVarsThread_new: allocate block for a thread --- */
static void Scr_CalcLocalVarsThread_new(sval_t exprlist, sval_t stmtlist, sval_t *stmttblock)
{
    (void)exprlist; (void)stmtlist;
    SCRCG->forceNotCreate = 0;

    stmttblock->block = (scr_block_t *)Hunk_AllocateTempMemoryHighInternal(sizeof(scr_block_t));

    stmttblock->block->abortLevel = SCRCOMP_SCR_ABORT_NONE;
    stmttblock->block->localVarsCreateCount = 0;
    stmttblock->block->localVarsCount = 0;
    stmttblock->block->localVarsPublicCount = 0;
    memset(stmttblock->block->localVarsInitBits, 0, sizeof(stmttblock->block->localVarsInitBits));

    /* Formal param calc and statement local var calc would go here.
       For the minimal stub, the block is allocated and zeroed. */
}

/* --- EmitThreadInternal_new: compile the body of a single thread --- */
static void EmitThreadInternal_new(unsigned int threadId, sval_t val, sval_t sourcePos,
                                    sval_t endSourcePos, scr_block_t *block)
{
    (void)block;
    SCRCG->threadId = threadId;
    AddThreadStartOpcodePos(sourcePos.sourcePosValue);

    SCRCG->cumulOffset = 0;
    SCRCG->maxOffset = 0;
    SCRCG->maxCallOffset = 0;

    /* CompileTransferRefToString(val.node[1].stringValue, 2):
       Transfer name string reference to user 2. */
    {
        sval_t *vnode = (sval_t *)val.node;
        unsigned int stringValue = vnode[1].stringValue;
        if (stringValue) {
            if (SCRCP->developer_statement == SCRCOMP_SCR_DEV_IGNORE) {
                Scr_CompileRemoveRefToString_new(stringValue);
            } else {
                if (SCRCG->bConstRefCount)
                    SL_AddRefToString(stringValue);
                SL_TransferRefToUser(stringValue, 2);
            }
        }
    }

    /* Emit formal parameters, statement list, and OP_End.
       The real EmitFormalParameterList and EmitStatementList are internal
       to the original binary and not yet implemented - stub them out.
       For now, just emit OP_End to produce a valid (empty) function body. */
    EmitEnd_new();

    AddOpcodePos(endSourcePos.sourcePosValue, SCRCOMP_SOURCE_TYPE_BREAKPOINT);
    AddOpcodePos(0xFFFFFFFE, SCRCOMP_SOURCE_TYPE_NONE);
}

/* --- EmitNormalThread_new: emit a normal (non-developer) thread --- */
static void EmitNormalThread_new(sval_t val, sval_t *stmttblock)
{
    unsigned int posId, threadId;
    sval_t *vnode = (sval_t *)val.node;

    InitThread_new(0);

    posId = FindVariable(SCRCG->fileId, vnode[1].idValue);
    threadId = FindObject(posId);

    SetThreadPosition_new(threadId);
    EmitThreadInternal_new(threadId, val, vnode[4], vnode[5], stmttblock->block);
}

/* --- EmitDeveloperThread_new: emit a developer-section thread --- */
static void EmitDeveloperThread_new(sval_t val, sval_t *stmttblock)
{
    unsigned int posId, threadId, savedChecksum;
    char *begin_pos;
    sval_t *vnode = (sval_t *)val.node;

    if (SCRVP->developer_script) {
        SCRCP->developer_statement = SCRCOMP_SCR_DEV_YES;
        InitThread_new(1);

        posId = FindVariable(SCRCG->fileId, vnode[1].sourcePosValue);
        threadId = FindObject(posId);

        SetThreadPosition_new(threadId);
        EmitThreadInternal_new(threadId, val, vnode[4], vnode[5], stmttblock->block);
    } else {
        begin_pos = (char *)TempMalloc(0);
        savedChecksum = SCRVP->checksum;

        SCRCP->developer_statement = SCRCOMP_SCR_DEV_IGNORE;
        InitThread_new(1);

        EmitThreadInternal_new(0, val, vnode[4], vnode[5], stmttblock->block);

        TempMemorySetPos(begin_pos);
        SCRVP->checksum = savedChecksum;
    }

    SCRCP->developer_statement = SCRCOMP_SCR_DEV_NO;
}

/* --- EmitThread_new: dispatch to emit a single thread/function definition --- */
static void EmitThread_new(sval_t val)
{
    sval_t *vnode = (sval_t *)val.node;
    int nodeType = vnode[0].type;

    switch (nodeType) {
    case SCRCOMP_ENUM_thread:
        Scr_CalcLocalVarsThread_new(vnode[2], vnode[3], &vnode[6]);
        if (SCRCG->in_developer_thread)
            EmitDeveloperThread_new(val, &vnode[6]);
        else
            EmitNormalThread_new(val, &vnode[6]);
        break;

    case SCRCOMP_ENUM_begin_developer_thread:
        SCRCG->in_developer_thread = 1;
        break;

    case SCRCOMP_ENUM_end_developer_thread:
        SCRCG->in_developer_thread = 0;
        break;

    case SCRCOMP_ENUM_usingtree:
        if (SCRCG->in_developer_thread) {
            CompileError(vnode[2].sourcePosValue,
                         "cannot put #using_animtree inside /# ... #/ comment");
        } else {
            Scr_UsingTree(SL_ConvertToString(vnode[1].stringValue),
                          vnode[3].sourcePosValue);
            Scr_CompileRemoveRefToString_new(vnode[1].stringValue);
        }
        break;

    default:
        break;
    }
}

/* --- SpecifyThread_new: first pass - allocate positions for all threads --- */
static void SpecifyThread_new(sval_t val)
{
    sval_t *vnode = (sval_t *)val.node;
    unsigned int posId;

    switch (vnode[0].type) {
    case SCRCOMP_ENUM_begin_developer_thread:
        if (SCRCG->in_developer_thread) {
            CompileError(vnode[1].sourcePosValue, "cannot recurse /#");
            return;
        }
        SCRCG->in_developer_thread = 1;
        SCRCG->developer_thread_sourcePos = vnode[1].sourcePosValue;
        break;

    case SCRCOMP_ENUM_end_developer_thread:
        if (!SCRCG->in_developer_thread) {
            CompileError(vnode[1].sourcePosValue, "#/ has no matching /#");
            return;
        }
        SCRCG->in_developer_thread = 0;
        break;

    case SCRCOMP_ENUM_thread:
        if (SCRCG->in_developer_thread && !SCRVP->developer_script)
            return;

        posId = GetObjectA(GetVariable(SCRCG->fileId, vnode[1].idValue));

        if (SCRCG->in_developer_thread)
            SpecifyThreadPosition_new(posId, vnode[1].sourcePosValue,
                                      vnode[4].sourcePosValue,
                                      SCRCOMP_VAR_DEVELOPER_CODEPOS);
        else
            SpecifyThreadPosition_new(posId, vnode[1].sourcePosValue,
                                      vnode[4].sourcePosValue,
                                      SCRCOMP_VAR_CODEPOS);
        break;

    default:
        break;
    }
}

/* --- EmitThreadList_new: process all thread definitions in the file ---
   Same list structure as EmitIncludeList_new.                               */
static void EmitThreadList_new(sval_t val)
{
    sval_t *node;
    sval_t *sentinel = (sval_t *)(((sval_t *)val.node)[0].node);

    SCRCG->in_developer_thread = 0;

    /* First pass: SpecifyThread (allocate positions) */
    for (node = (sval_t *)sentinel[1].node; node; node = (sval_t *)node[1].node) {
        SpecifyThread_new(node[0]);
    }

    if (SCRCG->in_developer_thread) {
        CompileError(SCRCG->developer_thread_sourcePos, "/# has no matching #/");
    }

    SCRCG->firstThread[0] = 1;
    SCRCG->firstThread[1] = 1;

    /* Second pass: EmitThread (compile bodies) */
    for (node = (sval_t *)sentinel[1].node; node; node = (sval_t *)node[1].node) {
        EmitThread_new(node[0]);
    }
}

/* --- LinkFile_new: link all forward references within a file --- */
static void LinkFile_new(unsigned int fileId)
{
    VariableValue pos, emptyValue;
    unsigned int posId, threadCountId, threadCountPtr;

    emptyValue.type = SCRCOMP_VAR_UNDEFINED;
    emptyValue.u.intValue = 0;

    for (threadCountPtr = FindNextSibling(fileId); threadCountPtr;
         threadCountPtr = FindNextSibling(threadCountPtr))
    {
        threadCountId = FindObject(threadCountPtr);

        posId = FindVariable(threadCountId, 1);
        if (!posId) {
            LinkThread_new(threadCountId, &emptyValue, 1);
            continue;
        }

        pos = Scr_EvalVariable(posId);

        if (pos.type == SCRCOMP_VAR_INCLUDE_CODEPOS) {
            SetVariableValue(threadCountPtr, &emptyValue);
            continue;
        }

        LinkThread_new(threadCountId, &pos, 1);
    }
}

/* ============================================================
 * ScriptCompile - main compiler entry point
 * Ref: scr_compiler.cpp lines 132-253
 * Called from scr_main.c as:
 *   ScriptCompile(parseData, compiledObj, scriptId)
 * where parseData is an sval_t node index (int),
 *       compiledObj is the file's variable object id,
 *       scriptId is the script variable id to mark as compiled.
 * ============================================================ */
void ScriptCompile(sval_t val, unsigned int fileId, unsigned int scriptId)
{
    PrecacheEntry *precachescript, *precachescript2, *precachescriptList;
    unsigned int filename, name;
    unsigned int posId, includePosId, includeFilePosId, toThreadCountId;
    VariableValue includePos, value;
    VariableUnion *pos;
    /* val.node = pointer to {include_list_ptr, thread_list_ptr} array (node2_) */
    sval_t *top = (sval_t *)val.node;
    sval_t include_list_val, thread_list_val;
    int i, j, func_count;

    SCRCG->fileId = fileId;
    SCRCG->bConstRefCount = 0;

    SCRAP->animTreeIndex = 0;
    SCRCP->developer_statement = SCRCOMP_SCR_DEV_NO;

    func_count = SCRCP->far_function_count;
    if (func_count > 0) {
        precachescriptList = (PrecacheEntry *)Z_MallocInternal(
            sizeof(*precachescriptList) * func_count);
    } else {
        precachescriptList = NULL;
    }

    SCRCG->precachescriptList = precachescriptList;

    if (precachescriptList) {
        precachescriptList->next = (int)(intptr_t)SCRCG->precachescriptListHead;
        SCRCG->precachescriptListHead = precachescriptList;
    }

    /* Process include list (top[0]) and thread list (top[1]) */
    include_list_val = top[0];
    thread_list_val  = top[1];
    EmitIncludeList_new(include_list_val);
    EmitThreadList_new(thread_list_val);

    /* Record the total program length and free parse-time temp memory */
    SCRCP->programLen = (char *)TempMalloc(0) - SCRVP->programBuffer;
    call_Hunk_ClearTempMemoryHigh();

    func_count = SCRCP->far_function_count;

    for (i = 0; i < func_count; i++) {
        precachescript = &precachescriptList[i];
        filename = precachescript->filename;

        includeFilePosId = Scr_LoadScript(SL_ConvertToString(filename));

        if (!includeFilePosId) {
            CompileError(precachescript->sourcePos,
                         "Could not find script '%s'",
                         SL_ConvertToString(filename));
            return;
        }

        SL_RemoveRefToString(filename);

        if (!precachescript->include)
            continue;

        /* Check for duplicate #include */
        for (j = i + 1; j < func_count; j++) {
            precachescript2 = &precachescriptList[j];
            if (!precachescript2->include)
                break;
            if (precachescript2->filename == filename) {
                CompileError(precachescript2->sourcePos, "Duplicate #include");
                return;
            }
        }

        precachescript->include = 0;

        /* Link included functions into this file's namespace */
        for (includePosId = FindNextSibling(includeFilePosId);
             includePosId;
             includePosId = FindNextSibling(includePosId))
        {
            if (GetObjectType(includePosId) != SCRCOMP_VAR_POINTER)
                continue;

            posId = FindVariable(FindObject(includePosId), 1);
            if (!posId)
                continue;

            includePos = Scr_EvalVariable(posId);

            if (includePos.type == SCRCOMP_VAR_INCLUDE_CODEPOS)
                continue;

            name = GetVariableName(includePosId);
            toThreadCountId = GetObjectA(GetVariable(fileId, name));

            SpecifyThreadPosition_new(toThreadCountId, name,
                                      precachescript->sourcePos,
                                      SCRCOMP_VAR_INCLUDE_CODEPOS);
            pos = (VariableUnion *)GetVariableValueAddress(posId);

            LinkThread_new(toThreadCountId, &includePos, 0);
        }
    }

    if (precachescriptList) {
        SCRCG->precachescriptListHead = (PrecacheEntry *)(intptr_t)precachescriptList->next;
        Z_FreeInternal(precachescriptList);
    }

    LinkFile_new(fileId);

    value.type = SCRCOMP_VAR_INTEGER;
    value.u.intValue = 1;
    SetVariableValue(scriptId, &value);
}

/* ============================================================
 * Stub implementations for Emit* functions not yet ported.
 * These call Com_Error so we can see what gets reached at runtime.
 * ============================================================ */
extern void Com_Error(int code, const char *fmt, ...);
#define ERR_DROP 1

static void EmitStatement_stub(void)
{
    Com_Error(ERR_DROP, "EmitStatement reached - not yet implemented");
}

static void EmitExpression_stub(void)
{
    Com_Error(ERR_DROP, "EmitExpression reached - not yet implemented");
}

static void EmitFormalParameterList_stub(void)
{
    Com_Error(ERR_DROP, "EmitFormalParameterList reached - not yet implemented");
}

static void EmitStatementList_stub(void)
{
    Com_Error(ERR_DROP, "EmitStatementList reached - not yet implemented");
}

/* ============================================================
 * End of new implementations
 * ============================================================ */

/* line 2300 */
static unsigned int LinkThread(unsigned int threadId, VariableUnion (*pos)[16]) {
    /* Note: in native code, ecx=allowFarCall is a hidden register param.
       In the Emscripten path this function is not called, so allowFarCall is unused. */
    unsigned int varId;
    VariableValue evalResult;
    int count, i;
    int allowFarCall = 0;

    varId = FindVariable(threadId, 0);
    if (!varId)
        return 0;

    evalResult = Scr_EvalVariable(varId);
    count = evalResult.u.intValue;
    if (count <= 0)
        return 0;

    for (i = 0; i < count; i++) {
        unsigned int valueId = FindVariable(threadId, i + 2);
        VariableUnion *value = GetVariableValueAddress(valueId);
        int type = GetVarType(valueId);
        int posType = ((int *)pos)[1];

        if (posType == 0xc) {
            if (type == 7) {
                CompileError2((int)(intptr_t)value->codePosValue, "normal script cannot reference a function in a /# ... #/ comment");
                continue;
            }
        } else {
            if (!posType) {
                CompileError2((int)(intptr_t)value->codePosValue, "unknown function");
                continue;
            }
            if (!allowFarCall) {
                int *target = (int *)(intptr_t)value->codePosValue;
                if (*target == 1) {
                    CompileError2((int)(intptr_t)value->codePosValue, "unknown function");
                    continue;
                }
            }
        }

        *(int *)(intptr_t)value->codePosValue = ((int *)pos)[0];
    }
    return 0;
}
