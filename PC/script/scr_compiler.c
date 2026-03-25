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

/* ============================================================
 * Opcode definitions (from scr_vm.c)
 * ============================================================ */
#define OP_End                              0x00
#define OP_Return                           0x01
#define OP_GetUndefined                     0x02
#define OP_GetZero                          0x03
#define OP_GetByte                          0x04
#define OP_GetNegByte                       0x05
#define OP_GetUnsignedShort                 0x06
#define OP_GetNegUnsignedShort              0x07
#define OP_GetInteger                       0x08
#define OP_GetFloat                         0x09
#define OP_GetString                        0x0A
#define OP_GetIString                       0x0B
#define OP_GetVector                        0x0C
#define OP_GetLevelObject                   0x0D
#define OP_GetAnimObject                    0x0E
#define OP_GetSelf                          0x0F
#define OP_GetLevel                         0x10
#define OP_GetGame                          0x11
#define OP_GetAnim                          0x12
#define OP_GetAnimation                     0x13
#define OP_GetGameRef                       0x14
#define OP_GetFunction                      0x15
#define OP_CreateLocalVariable              0x16
#define OP_RemoveLocalVariables             0x17
#define OP_EvalLocalVariableCached0         0x18
#define OP_EvalLocalVariableCached1         0x19
#define OP_EvalLocalVariableCached2         0x1A
#define OP_EvalLocalVariableCached3         0x1B
#define OP_EvalLocalVariableCached4         0x1C
#define OP_EvalLocalVariableCached5         0x1D
#define OP_EvalLocalVariableCached          0x1E
#define OP_EvalLocalArrayCached             0x1F
#define OP_EvalArray                        0x20
#define OP_EvalLocalArrayRefCached0         0x21
#define OP_EvalLocalArrayRefCached          0x22
#define OP_EvalArrayRef                     0x23
#define OP_ClearArray                       0x24
#define OP_EmptyArray                       0x25
#define OP_GetSelfObject                    0x26
#define OP_EvalLevelFieldVariable           0x27
#define OP_EvalAnimFieldVariable            0x28
#define OP_EvalSelfFieldVariable            0x29
#define OP_EvalFieldVariable                0x2A
#define OP_EvalLevelFieldVariableRef        0x2B
#define OP_EvalAnimFieldVariableRef         0x2C
#define OP_EvalSelfFieldVariableRef         0x2D
#define OP_EvalFieldVariableRef             0x2E
#define OP_ClearFieldVariable               0x2F
#define OP_SafeCreateVariableFieldCached    0x30
#define OP_SafeSetVariableFieldCached0      0x31
#define OP_SafeSetVariableFieldCached       0x32
#define OP_SafeSetWaittillVariableFieldCached 0x33
#define OP_clearparams                      0x34
#define OP_checkclearparams                 0x35
#define OP_EvalLocalVariableRefCached0      0x36
#define OP_EvalLocalVariableRefCached       0x37
#define OP_SetLevelFieldVariableField       0x38
#define OP_SetVariableField                 0x39
#define OP_SetAnimFieldVariableField        0x3A
#define OP_SetSelfFieldVariableField        0x3B
#define OP_SetLocalVariableFieldCached0     0x3C
#define OP_SetLocalVariableFieldCached      0x3D
#define OP_CallBuiltin0                     0x3E
#define OP_CallBuiltin1                     0x3F
#define OP_CallBuiltin2                     0x40
#define OP_CallBuiltin3                     0x41
#define OP_CallBuiltin4                     0x42
#define OP_CallBuiltin5                     0x43
#define OP_CallBuiltin                      0x44
#define OP_CallBuiltinMethod0               0x45
#define OP_CallBuiltinMethod1               0x46
#define OP_CallBuiltinMethod2               0x47
#define OP_CallBuiltinMethod3               0x48
#define OP_CallBuiltinMethod4               0x49
#define OP_CallBuiltinMethod5               0x4A
#define OP_CallBuiltinMethod                0x4B
#define OP_wait                             0x4C
#define OP_waittillFrameEnd                 0x4D
#define OP_PreScriptCall                    0x4E
#define OP_ScriptFunctionCall2              0x4F
#define OP_ScriptFunctionCall               0x50
#define OP_ScriptFunctionCallPointer        0x51
#define OP_ScriptMethodCall                 0x52
#define OP_ScriptMethodCallPointer          0x53
#define OP_ScriptThreadCall                 0x54
#define OP_ScriptThreadCallPointer          0x55
#define OP_ScriptMethodThreadCall           0x56
#define OP_ScriptMethodThreadCallPointer    0x57
#define OP_DecTop                           0x58
#define OP_CastFieldObject                  0x59
#define OP_EvalLocalVariableObjectCached    0x5A
#define OP_CastBool                         0x5B
#define OP_BoolNot                          0x5C
#define OP_BoolComplement                   0x5D
#define OP_JumpOnFalse                      0x5E
#define OP_JumpOnTrue                       0x5F
#define OP_JumpOnFalseExpr                  0x60
#define OP_JumpOnTrueExpr                   0x61
#define OP_jump                             0x62
#define OP_jumpback                         0x63
#define OP_inc                              0x64
#define OP_dec                              0x65
#define OP_bit_or                           0x66
#define OP_bit_ex_or                        0x67
#define OP_bit_and                          0x68
#define OP_equality                         0x69
#define OP_inequality                       0x6A
#define OP_less                             0x6B
#define OP_greater                          0x6C
#define OP_less_equal                       0x6D
#define OP_greater_equal                    0x6E
#define OP_shift_left                       0x6F
#define OP_shift_right                      0x70
#define OP_plus                             0x71
#define OP_minus                            0x72
#define OP_multiply                         0x73
#define OP_divide                           0x74
#define OP_mod                              0x75
#define OP_size                             0x76
#define OP_waittillmatch                    0x77
#define OP_waittill                         0x78
#define OP_notify                           0x79
#define OP_endon                            0x7A
#define OP_voidCodepos                      0x7B
#define OP_switch                           0x7C
#define OP_endswitch                        0x7D
#define OP_vector                           0x7E
#define OP_NOP                              0x7F
#define OP_abort                            0x80
#define OP_object                           0x81
#define OP_thread_object                    0x82
#define OP_EvalLocalVariable                0x83
#define OP_EvalLocalVariableRef             0x84
#define OP_prof_begin                       0x85
#define OP_prof_end                         0x86
#define OP_breakpoint                       0x87
#define OP_assignmentBreakpoint             0x88
#define OP_manualAndAssignmentBreakpoint    0x89

/* ============================================================
 * ENUM definitions for AST node types
 * From: script_public.h
 * ============================================================ */
#define ENUM_NOP                        0x00
#define ENUM_program                    0x01
#define ENUM_assignment                 0x02
#define ENUM_unknown_variable           0x03
#define ENUM_local_variable             0x04
#define ENUM_local_variable_frozen      0x05
#define ENUM_primitive_expression       0x06
#define ENUM_integer                    0x07
#define ENUM_float                      0x08
#define ENUM_minus_integer              0x09
#define ENUM_minus_float                0x0A
#define ENUM_string                     0x0B
#define ENUM_istring                    0x0C
#define ENUM_array_variable             0x0D
#define ENUM_unknown_field              0x0E
#define ENUM_field_variable             0x0F
#define ENUM_field_variable_frozen      0x10
#define ENUM_variable                   0x11
#define ENUM_function                   0x12
#define ENUM_call_expression            0x13
#define ENUM_local_function             0x14
#define ENUM_far_function               0x15
#define ENUM_function_pointer           0x16
#define ENUM_call                       0x17
#define ENUM_method                     0x18
#define ENUM_call_expression_statement  0x19
#define ENUM_script_call                0x1A
#define ENUM_return                     0x1B
#define ENUM_return2                    0x1C
#define ENUM_wait                       0x1D
#define ENUM_script_thread_call         0x1E
#define ENUM_undefined                  0x1F
#define ENUM_self                       0x20
#define ENUM_self_frozen                0x21
#define ENUM_level                      0x22
#define ENUM_game                       0x23
#define ENUM_anim                       0x24
#define ENUM_if                         0x25
#define ENUM_if_else                    0x26
#define ENUM_while                      0x27
#define ENUM_for                        0x28
#define ENUM_inc                        0x29
#define ENUM_dec                        0x2A
#define ENUM_binary_equals              0x2B
#define ENUM_statement_list             0x2C
#define ENUM_developer_statement_list   0x2D
#define ENUM_expression_list            0x2E
#define ENUM_bool_or                    0x2F
#define ENUM_bool_and                   0x30
#define ENUM_binary                     0x31
#define ENUM_bool_not                   0x32
#define ENUM_bool_complement            0x33
#define ENUM_size_field                 0x34
#define ENUM_self_field                 0x35
#define ENUM_precachetree               0x36
#define ENUM_waittill                   0x37
#define ENUM_waittillmatch              0x38
#define ENUM_waittillFrameEnd           0x39
#define ENUM_notify                     0x3A
#define ENUM_endon                      0x3B
#define ENUM_switch                     0x3C
#define ENUM_case                       0x3D
#define ENUM_default                    0x3E
#define ENUM_break                      0x3F
#define ENUM_continue                   0x40
#define ENUM_expression                 0x41
#define ENUM_empty_array                0x42
#define ENUM_animation                  0x43
/* ENUM_thread etc. already defined above as SCRCOMP_ENUM_thread etc. */
#define ENUM_false                      0x48
#define ENUM_true                       0x49
#define ENUM_animtree                   0x4A
#define ENUM_breakon                    0x4B
#define ENUM_breakpoint                 0x4C
#define ENUM_prof_begin                 0x4D
#define ENUM_prof_end                   0x4E
#define ENUM_vector                     0x4F
#define ENUM_object                     0x50
#define ENUM_thread_object              0x51
#define ENUM_local                      0x52
#define ENUM_statement                  0x53
#define ENUM_bad_expression             0x54
#define ENUM_bad_statement              0x55
#define ENUM_include                    0x56
#define ENUM_argument                   0x57

/* Call types for EmitOpcode */
#define CALL_NONE      0
#define CALL_BUILTIN   1
#define CALL_THREAD    2
#define CALL_FUNCTION  3

/* Abort levels */
#define SCR_ABORT_NONE     0
#define SCR_ABORT_CONTINUE 1
#define SCR_ABORT_BREAK    2
#define SCR_ABORT_RETURN   3
#define SCR_ABORT_MAX      3

/* Source type flags */
#define SOURCE_TYPE_NONE        0
#define SOURCE_TYPE_BREAKPOINT  1
#define SOURCE_TYPE_CALL        2
#define SOURCE_TYPE_THREAD_START 4
#define SOURCE_TYPE_BUILTIN_CALL 8
#define SOURCE_TYPE_NOTIFY      0x10

/* Builtin types */
#define BUILTIN_ANY             0
#define BUILTIN_DEVELOPER_ONLY  1

/* Scope */
#define FUNC_SCOPE_LOCAL 0
#define FUNC_SCOPE_FAR   1

/* Dev statement constants */
#define SCR_DEV_NO       0
#define SCR_DEV_YES      1
#define SCR_DEV_IGNORE   2
#define SCR_DEV_EVALUATE 3

/* Sizes */
#define LOCAL_VAR_STACK_SIZE 64
#define MAX_SWITCH_CASES    1024
#define VALUE_STACK_SIZE    32
#define SCR_FUNC_TABLE_SIZE 1024
#define MAX_VM_OPERAND_STACK 0x800
#define VARIABLELIST_CHILD_SIZE 0xFFFE

/* Additional extern declarations for newly-ported emit functions */
extern char *TempMallocAlign(int len);
extern char *TempMallocAlignStrict(int len);
extern void RemoveOpcodePos(void);
extern unsigned int GetNewVariable(unsigned int parentId, unsigned int name);
extern unsigned short SL_TransferToCanonicalString(unsigned int stringValue);
extern void Scr_EvalBinaryOperator(int op, VariableValue *value1, VariableValue *value2);
extern void Scr_CastBool(VariableValue *value);
extern void Scr_EmitAnimation(char *pos, unsigned int animName, unsigned int sourcePos);
extern int Scr_GetClassnumForCharId(char charId);
extern int IsObjectFree(unsigned int id);
extern int IsValidArrayIndex(unsigned int index);
extern unsigned int GetInternalVariableIndex(unsigned int index);
extern float *Scr_AllocVector(const float *vec);
extern void RemoveRefToVector(const float *vectorValue);
extern void RemoveRefToValue(int type, VariableUnion u);
extern void AddRefToValue(int type, VariableUnion u);
extern void (*Scr_GetFunction(const char **pName, int *type))(void);
extern void (*Scr_GetMethod(const char **pName, int *type))(scr_entref_t);
extern const char *va(const char *format, ...);
extern void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
extern const char *var_typename[];
extern scrParserPub_t scrParserPub;
extern unsigned int Scr_GetSourceBuffer(const char *codePos);

/* Forward declarations for all emit functions */
static void EmitStatementList_new(sval_t val, int lastStatement, unsigned int endSourcePos, scr_block_t *block);
static void EmitStatement_real(sval_t val, int lastStatement, unsigned int endSourcePos, scr_block_t *block);
static void EmitExpression_real(sval_t expr, scr_block_t *block);
static void EmitPrimitiveExpression_real(sval_t expr, scr_block_t *block);
static int EmitOrEvalExpression_real(sval_t expr, VariableCompileValue *constValue, scr_block_t *block);
static int EmitOrEvalPrimitiveExpression_real(sval_t expr, VariableCompileValue *constValue, scr_block_t *block);
static void EmitVariableExpression_real(sval_t expr, scr_block_t *block);
static void EmitVariableExpressionRef_real(sval_t expr, scr_block_t *block);
static void EmitFormalParameterList_real(sval_t exprlist, sval_t sourcePos, scr_block_t *block);
static int EvalExpression_real(sval_t expr, VariableCompileValue *constValue);
static int EvalPrimitiveExpression_real(sval_t expr, VariableCompileValue *constValue);
static void EmitCall_real(sval_t func_name, sval_t params, int bStatement, scr_block_t *block);
static void EmitMethod_real(sval_t expr, sval_t func_name, sval_t params, sval_t methodSourcePos, int bStatement, scr_block_t *block);
static void EmitPrimitiveExpressionFieldObject_real(sval_t expr, sval_t sourcePos, scr_block_t *block);
static void EmitCallExpression_real(sval_t expr, int bStatement, scr_block_t *block);

/* ============================================================
 * Ported emit functions from reference scr_compiler.cpp
 * ============================================================ */

/* --- GetExpressionCount --- */
static int GetExpressionCount_real(sval_t exprlist)
{
    sval_t *node;
    int expr_count = 0;
    for (node = (sval_t *)((sval_t *)exprlist.node)[0].node; node; node = (sval_t *)node[1].node)
        expr_count++;
    return expr_count;
}

/* --- Scr_GetBuiltin --- */
static unsigned int Scr_GetBuiltin_real(sval_t func_name)
{
    sval_t *n = (sval_t *)func_name.node;
    if (n[0].type != ENUM_script_call)
        return 0;
    n = (sval_t *)n[1].node;
    if (n[0].type != ENUM_function)
        return 0;
    n = (sval_t *)n[1].node;
    if (n[0].type != ENUM_local_function)
        return 0;
    n = (sval_t *)n[1].node;
    if (FindVariable(SCRCG->fileId, n[0].idValue))
        return 0;
    return n[0].idValue;
}

/* --- GetSingleParameter --- */
static sval_t *GetSingleParameter_real(sval_t exprlist)
{
    sval_t *first = (sval_t *)((sval_t *)exprlist.node)[0].node;
    if (!first)
        return NULL;
    if ((sval_t *)first[1].node != NULL)
        return NULL;
    return first;
}

/* --- Scr_PopValue --- */
static void Scr_PopValue_real(void)
{
    SCRCP->value_count--;
}

/* --- Scr_PushValue --- */
static void Scr_PushValue_real(VariableCompileValue *constValue)
{
    int valueIndex;
    if (SCRCP->value_count >= VALUE_STACK_SIZE) {
        CompileError(constValue->sourcePos.sourcePosValue, "VALUE_STACK_SIZE exceeded");
        return;
    }
    valueIndex = SCRCP->value_count;
    SCRCG->value_start[valueIndex].value.u = constValue->value.u;
    SCRCG->value_start[valueIndex].value.type = constValue->value.type;
    SCRCG->value_start[valueIndex].sourcePos.sourcePosValue = constValue->sourcePos.sourcePosValue;
    SCRCP->value_count++;
}

/* --- Scr_IsLastStatement --- */
static int Scr_IsLastStatement_real(sval_t *node)
{
    if (!node)
        return 1;
    if (SCRVP->developer_script)
        return 0;
    while (node) {
        if (((sval_t *)node[0].node)[0].type != ENUM_developer_statement_list)
            return 0;
        node = (sval_t *)node[1].node;
    }
    return 1;
}

/* --- IsUndefinedPrimitiveExpression --- */
static int IsUndefinedPrimitiveExpression_real(sval_t expr)
{
    return ((sval_t *)expr.node)[0].type == ENUM_undefined;
}

/* --- IsUndefinedExpression --- */
static int IsUndefinedExpression_real(sval_t expr)
{
    sval_t *n = (sval_t *)expr.node;
    if (n[0].type == ENUM_primitive_expression) {
        if (IsUndefinedPrimitiveExpression_real(n[1]))
            return 1;
    }
    return 0;
}

/* --- Scr_FindLocalVar --- */
static int Scr_FindLocalVar_real(scr_block_t *block, int startIndex, unsigned int name)
{
    int i;
    for (i = startIndex; i < block->localVarsCount; i++) {
        if (block->localVars[i].name == name)
            return i;
    }
    return -1;
}

/* --- Scr_CheckLocalVarsCount --- */
static void Scr_CheckLocalVarsCount_real(int localVarsCount)
{
    if (localVarsCount < LOCAL_VAR_STACK_SIZE)
        return;
    Com_Error(ERR_DROP, "LOCAL_VAR_STACK_SIZE exceeded");
}

/* --- Scr_CheckMaxSwitchCases --- */
static void Scr_CheckMaxSwitchCases_real(int count)
{
    if (count < MAX_SWITCH_CASES)
        return;
    Com_Error(ERR_DROP, "MAX_SWITCH_CASES exceeded");
}

/* --- Scr_CopyBlock --- */
static void Scr_CopyBlock_real(scr_block_t *from, scr_block_t **to)
{
    if (*to == NULL)
        *to = (scr_block_t *)Hunk_AllocateTempMemoryHighInternal(sizeof(scr_block_t));
    **to = *from;
    (*to)->localVarsPublicCount = 0;
}

/* --- Scr_RegisterLocalVar --- */
static void Scr_RegisterLocalVar_real(unsigned int name, sval_t sourcePos, scr_block_t *block)
{
    int i;
    if (block->abortLevel != SCR_ABORT_NONE)
        return;
    for (i = 0; i < block->localVarsCount; i++) {
        if (block->localVars[i].name == name)
            return;
    }
    Scr_CheckLocalVarsCount_real(block->localVarsCount);
    block->localVars[block->localVarsCount].name = name;
    block->localVarsCount++;
}

/* --- Scr_MergeChildBlocks --- */
static void Scr_MergeChildBlocks_real(scr_block_t **childBlocks, int childCount, scr_block_t *block)
{
    scr_block_t *childBlock;
    unsigned int name;
    int childIndex, i, j;

    if (!childCount)
        return;
    if (block->abortLevel != SCR_ABORT_NONE)
        return;

    for (childIndex = 0; childIndex < childCount; childIndex++) {
        childBlock = childBlocks[childIndex];
        childBlock->localVarsPublicCount = block->localVarsCount;
        for (i = 0; i < block->localVarsCount; i++) {
            name = block->localVars[i].name;
            j = Scr_FindLocalVar_real(childBlock, i, name);
            if (j < 0) {
                j = childBlock->localVarsCount;
                Scr_CheckLocalVarsCount_real(j);
                childBlock->localVarsCount++;
            }
            while (j > i) {
                childBlock->localVars[j] = *(scr_localVar_t *)&childBlock->localVarsInitBits[sizeof(scr_localVar_t) * j + sizeof(unsigned int)];
                j--;
            }
            childBlock->localVars[i].name = name;
        }
    }
}

/* --- Scr_AppendChildBlocks --- */
static void Scr_AppendChildBlocks_real(scr_block_t **childBlocks, int childCount, scr_block_t *block)
{
    unsigned int name;
    int childIndex, i;

    if (!childCount)
        return;
    if (block->abortLevel != SCR_ABORT_NONE)
        return;

    for (childIndex = 0; childIndex < childCount; childIndex++)
        childBlocks[childIndex]->abortLevel = SCR_ABORT_NONE;

    for (i = 0; i < childBlocks[0]->localVarsCount; i++) {
        name = childBlocks[0]->localVars[i].name;
        if (Scr_FindLocalVar_real(block, 0, name) >= 0)
            continue;
        for (childIndex = 1; childIndex < childCount; childIndex++) {
            if (Scr_FindLocalVar_real(childBlocks[childIndex], 0, name) < 0)
                goto scr_append_out;
        }
        block->localVars[block->localVarsCount].name = name;
        block->localVarsCount++;
scr_append_out:
        ;
    }
}

/* --- Scr_InitFromChildBlocks --- */
static void Scr_InitFromChildBlocks_real(scr_block_t **childBlocks, int childCount, scr_block_t *block)
{
    int localVarsCreateCount, childIndex, i;
    scr_block_t *childBlock;

    if (!childCount)
        return;

    localVarsCreateCount = childBlocks[0]->localVarsPublicCount;
    for (childIndex = 1; childIndex < childCount; childIndex++) {
        childBlock = childBlocks[childIndex];
        if (childBlock->localVarsPublicCount < localVarsCreateCount)
            localVarsCreateCount = childBlock->localVarsPublicCount;
    }
    block->localVarsCreateCount = localVarsCreateCount;

    for (i = 0; i < localVarsCreateCount; i++) {
        if (!((1 << (i & 7)) & block->localVarsInitBits[i >> 3])) {
            for (childIndex = 0; childIndex < childCount; childIndex++) {
                childBlock = childBlocks[childIndex];
                if (!((1 << (i & 7)) & childBlock->localVarsInitBits[i >> 3]))
                    goto scr_init_out;
            }
            block->localVarsInitBits[i >> 3] |= 1 << (i & 7);
        }
scr_init_out:
        ;
    }
}

/* --- Scr_TransferBlock --- */
static void Scr_TransferBlock_real(scr_block_t *from, scr_block_t *to)
{
    unsigned int name;
    int i, j;

    for (i = 0; i < to->localVarsPublicCount || i < from->localVarsCreateCount; i++) {
        name = from->localVars[i].name;
        j = Scr_FindLocalVar_real(to, i, name);
        if (j < 0) {
            j = to->localVarsCount;
            Scr_CheckLocalVarsCount_real(j);
            to->localVarsCount++;
        }
        if (j >= to->localVarsPublicCount)
            to->localVarsPublicCount++;
        while (j > i) {
            to->localVars[j] = *(scr_localVar_t *)&to->localVarsInitBits[sizeof(scr_localVar_t) * j + sizeof(unsigned int)];
            j--;
        }
        to->localVars[i].name = name;
        if ((1 << (i & 7)) & from->localVarsInitBits[i >> 3])
            to->localVarsInitBits[i >> 3] |= 1 << (i & 7);
    }
    to->localVarsCreateCount = from->localVarsCreateCount;
    to->abortLevel = SCR_ABORT_NONE;
}

/* --- Scr_AddBreakBlock --- */
static void Scr_AddBreakBlock_real(scr_block_t *block)
{
    if (block->abortLevel)
        return;
    if (!SCRCG->breakChildBlocks)
        return;
    Scr_CheckMaxSwitchCases_real(*SCRCG->breakChildCount);
    SCRCG->breakChildBlocks[*SCRCG->breakChildCount] = block;
    (*SCRCG->breakChildCount)++;
}

/* --- Scr_AddContinueBlock --- */
static void Scr_AddContinueBlock_real(scr_block_t *block)
{
    if (block->abortLevel)
        return;
    if (!SCRCG->continueChildBlocks)
        return;
    Scr_CheckMaxSwitchCases_real(*SCRCG->continueChildCount);
    SCRCG->continueChildBlocks[*SCRCG->continueChildCount] = block;
    (*SCRCG->continueChildCount)++;
}

/* --- EmitCodepos --- */
static void EmitCodepos_real(const char *pos)
{
    SCRCG->codePos = (byte *)TempMallocAlign(sizeof(const char *));
    *(const char **)SCRCG->codePos = pos;
}

/* --- EmitShort --- */
static void EmitShort_real(short value)
{
    SCRCG->codePos = (byte *)TempMallocAlign(sizeof(short));
    *(short *)SCRCG->codePos = value;
}

/* --- EmitUnsignedShort --- */
static void EmitUnsignedShort_real(unsigned short value)
{
    SCRCG->codePos = (byte *)TempMallocAlign(sizeof(unsigned short));
    *(unsigned short *)SCRCG->codePos = value;
}

/* --- EmitInteger --- */
static void EmitInteger_real(int value)
{
    SCRCG->codePos = (byte *)TempMallocAlign(sizeof(int));
    *(int *)SCRCG->codePos = value;
}

/* --- EmitFloat --- */
static void EmitFloat_real(float value)
{
    SCRCG->codePos = (byte *)TempMallocAlignStrict(sizeof(float));
    *(float *)SCRCG->codePos = value;
}

/* --- EmitString --- */
static void EmitString_real(unsigned int value)
{
    SCRCG->codePos = (byte *)TempMallocAlign(sizeof(unsigned short));
    *(unsigned short *)SCRCG->codePos = value;
}

/* --- EmitCanonicalString --- */
static void EmitCanonicalString_real(unsigned int stringValue)
{
    SCRCG->codePos = (byte *)TempMallocAlign(sizeof(unsigned short));

    if (SCRCP->developer_statement == SCR_DEV_IGNORE) {
        Scr_CompileRemoveRefToString_new(stringValue);
        return;
    }

    if (SCRCG->bConstRefCount)
        SL_AddRefToString(stringValue);

    *(unsigned short *)SCRCG->codePos = SL_TransferToCanonicalString(stringValue);
}

/* --- EmitCanonicalStringConst --- */
static void EmitCanonicalStringConst_real(unsigned int stringValue)
{
    int bConstRefCount = SCRCG->bConstRefCount;
    SCRCG->bConstRefCount = 1;
    EmitCanonicalString_real(stringValue);
    SCRCG->bConstRefCount = bConstRefCount;
}

/* --- CompileTransferRefToString --- */
static void CompileTransferRefToString_real(unsigned int stringValue, unsigned char user)
{
    if (!stringValue)
        return;
    if (SCRCP->developer_statement == SCR_DEV_IGNORE) {
        Scr_CompileRemoveRefToString_new(stringValue);
        return;
    }
    if (SCRCG->bConstRefCount)
        SL_AddRefToString(stringValue);
    SL_TransferRefToUser(stringValue, user);
}

/* --- AddExpressionListOpcodePos --- */
static void AddExpressionListOpcodePos_real(sval_t exprlist)
{
    sval_t *node;
    if (!SCRVP->developer)
        return;
    for (node = (sval_t *)((sval_t *)exprlist.node)[0].node; node; node = (sval_t *)node[1].node)
        AddOpcodePos(((sval_t *)node[0].node)[1].sourcePosValue, SOURCE_TYPE_NONE);
}

/* --- AddFunction --- */
static int AddFunction_real(int func)
{
    int i;
    for (i = 0; i < SCRCP->func_table_size; i++) {
        if (SCRCP->func_table[i] == func)
            return i;
    }
    if (SCRCP->func_table_size == SCR_FUNC_TABLE_SIZE)
        Com_Error(ERR_DROP, "SCR_FUNC_TABLE_SIZE exceeded");
    SCRCP->func_table[SCRCP->func_table_size] = func;
    SCRCP->func_table_size++;
    return i;
}

/* --- EmitValue --- */
static void EmitValue_real(VariableCompileValue *constValue);

/* --- EmitOpcode --- */
static void EmitOpcode_real(unsigned int op, int offset, int callType)
{
    unsigned int index;
    int value_count, valueIndex;

    if (SCRCP->value_count) {
        value_count = SCRCP->value_count;
        SCRCP->value_count = 0;
        for (valueIndex = 0; valueIndex < value_count; valueIndex++)
            EmitValue_real(&SCRCG->value_start[valueIndex]);
    }

    SCRCP->allowedBreakpoint = 0;

    if (!SCRCG->cumulOffset || callType == CALL_THREAD || callType == CALL_FUNCTION)
        SCRCP->allowedBreakpoint = 1;

    SCRCG->cumulOffset += offset;

    if (SCRCG->maxOffset < SCRCG->cumulOffset)
        SCRCG->maxOffset = SCRCG->cumulOffset;

    if (callType != CALL_NONE && SCRCG->maxCallOffset < SCRCG->cumulOffset)
        SCRCG->maxCallOffset = SCRCG->cumulOffset;

    SCRVP->checksum *= 31;
    SCRVP->checksum += op;

    if (!SCRCP->opcodePos) {
        SCRCG->prevOpcodePos = SCRCP->opcodePos;
        SCRCP->opcodePos = (byte *)TempMalloc(sizeof(byte));
        SCRCG->codePos = SCRCP->opcodePos;
        *SCRCP->opcodePos = op;
        return;
    }

    SCRCG->codePos = SCRCP->opcodePos;

    switch (op) {
    case OP_EvalArray:
        if (*SCRCP->opcodePos == OP_EvalLocalVariableCached) {
            RemoveOpcodePos();
            *SCRCP->opcodePos = OP_EvalLocalArrayCached;
            return;
        }
        index = *SCRCP->opcodePos - OP_EvalLocalVariableCached0;
        if (index > OP_GetNegByte)
            break;
        RemoveOpcodePos();
        *SCRCP->opcodePos = OP_EvalLocalArrayCached;
        EmitByte_new(index);
        return;

    case OP_EvalArrayRef:
        if (*SCRCP->opcodePos == OP_EvalLocalVariableRefCached) {
            RemoveOpcodePos();
            *SCRCP->opcodePos = OP_EvalLocalArrayRefCached;
            return;
        }
        if (*SCRCP->opcodePos != OP_EvalLocalVariableRefCached0)
            break;
        RemoveOpcodePos();
        *SCRCP->opcodePos = OP_EvalLocalArrayRefCached0;
        return;

    case OP_EvalFieldVariable:
        if (*SCRCP->opcodePos == OP_GetSelfObject) {
            *SCRCP->opcodePos = OP_EvalSelfFieldVariable;
            return;
        }
        if (*SCRCP->opcodePos == OP_GetLevelObject) {
            *SCRCP->opcodePos = OP_EvalLevelFieldVariable;
            return;
        }
        if (*SCRCP->opcodePos != OP_GetAnimObject)
            break;
        *SCRCP->opcodePos = OP_EvalAnimFieldVariable;
        return;

    case OP_EvalFieldVariableRef:
        if (*SCRCP->opcodePos == OP_GetSelfObject) {
            *SCRCP->opcodePos = OP_EvalSelfFieldVariableRef;
            return;
        }
        if (*SCRCP->opcodePos == OP_GetLevelObject) {
            *SCRCP->opcodePos = OP_EvalLevelFieldVariableRef;
            return;
        }
        if (*SCRCP->opcodePos != OP_GetAnimObject)
            break;
        *SCRCP->opcodePos = OP_EvalAnimFieldVariableRef;
        return;

    case OP_SafeSetVariableFieldCached0:
        if (*SCRCP->opcodePos != OP_CreateLocalVariable)
            break;
        *SCRCP->opcodePos = OP_SafeCreateVariableFieldCached;
        return;

    case OP_SetVariableField:
        switch (*SCRCP->opcodePos) {
        case OP_EvalLocalVariableRefCached:
            RemoveOpcodePos();
            *SCRCP->opcodePos = OP_SetLocalVariableFieldCached;
            return;
        case OP_EvalLocalVariableRefCached0:
            RemoveOpcodePos();
            *SCRCP->opcodePos = OP_SetLocalVariableFieldCached0;
            return;
        case OP_EvalSelfFieldVariableRef:
            RemoveOpcodePos();
            *SCRCP->opcodePos = OP_SetSelfFieldVariableField;
            return;
        case OP_EvalLevelFieldVariableRef:
            RemoveOpcodePos();
            *SCRCP->opcodePos = OP_SetLevelFieldVariableField;
            return;
        }
        if (*SCRCP->opcodePos != OP_EvalAnimFieldVariableRef)
            break;
        RemoveOpcodePos();
        *SCRCP->opcodePos = OP_SetAnimFieldVariableField;
        return;

    case OP_ScriptFunctionCall:
        if (*SCRCP->opcodePos != OP_PreScriptCall)
            break;
        *SCRCP->opcodePos = OP_ScriptFunctionCall2;
        return;

    case OP_ScriptMethodCall:
        if (*SCRCP->opcodePos != OP_GetSelf)
            break;
        RemoveOpcodePos();
        *SCRCP->opcodePos = OP_ScriptFunctionCall;
        if (*SCRCG->prevOpcodePos != OP_PreScriptCall)
            return;
        TempMemorySetPos((char *)SCRCP->opcodePos);
        --SCRCP->opcodePos;
        SCRCG->prevOpcodePos = NULL;
        SCRCG->codePos = SCRCP->opcodePos;
        *SCRCP->opcodePos = OP_ScriptFunctionCall2;
        return;

    case OP_ScriptMethodThreadCall:
        if (*SCRCP->opcodePos != OP_GetSelf)
            break;
        RemoveOpcodePos();
        *SCRCP->opcodePos = OP_ScriptThreadCall;
        return;

    case OP_CastFieldObject:
        if (*SCRCP->opcodePos == OP_EvalLocalVariableCached) {
            *SCRCP->opcodePos = OP_EvalLocalVariableObjectCached;
            return;
        }
        index = *SCRCP->opcodePos - OP_EvalLocalVariableCached0;
        if (index > OP_GetNegByte)
            break;
        *SCRCP->opcodePos = OP_EvalLocalVariableObjectCached;
        EmitByte_new(index);
        return;

    case OP_JumpOnFalse:
        if (*SCRCP->opcodePos != OP_BoolNot)
            break;
        RemoveOpcodePos();
        *SCRCP->opcodePos = OP_JumpOnTrue;
        return;
    }

    SCRCG->prevOpcodePos = SCRCP->opcodePos;
    SCRCP->opcodePos = (byte *)TempMalloc(sizeof(byte));
    SCRCG->codePos = SCRCP->opcodePos;
    *SCRCP->opcodePos = op;
}

/* --- EmitEnd --- */
static void EmitEnd_real(void)
{
    EmitOpcode_real(OP_End, 0, CALL_NONE);
}

/* --- EmitReturn --- */
static void EmitReturn_real(void)
{
    EmitOpcode_real(OP_Return, -1, CALL_NONE);
}

/* --- Eval* helpers --- */
static void EvalInteger_real(int value, sval_t sourcePos, VariableCompileValue *constValue)
{
    constValue->value.type = 6; /* VAR_INTEGER */
    constValue->value.u.intValue = value;
    constValue->sourcePos = sourcePos;
}

static void EvalFloat_real(float value, sval_t sourcePos, VariableCompileValue *constValue)
{
    constValue->value.type = 8; /* VAR_FLOAT */
    constValue->value.u.floatValue = value;
    constValue->sourcePos = sourcePos;
}

static void EvalString_real(unsigned int value, sval_t sourcePos, VariableCompileValue *constValue)
{
    constValue->value.type = 2; /* VAR_STRING */
    constValue->value.u.stringValue = value;
    constValue->sourcePos = sourcePos;
}

static void EvalIString_real(unsigned int value, sval_t sourcePos, VariableCompileValue *constValue)
{
    constValue->value.type = 3; /* VAR_ISTRING */
    constValue->value.u.stringValue = value;
    constValue->sourcePos = sourcePos;
}

static void EvalUndefined_real(sval_t sourcePos, VariableCompileValue *constValue)
{
    constValue->value.type = 0; /* VAR_UNDEFINED */
    constValue->sourcePos = sourcePos;
}

/* --- EmitGetUndefined --- */
static void EmitGetUndefined_real(sval_t sourcePos)
{
    EmitOpcode_real(OP_GetUndefined, 1, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
}

/* --- EmitGetVector --- */
static void EmitGetVector_real(const float *value, sval_t sourcePos)
{
    int i;
    EmitOpcode_real(OP_GetVector, 1, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
    for (i = 0; i < 3; i++)
        EmitFloat_real(value[i]);
    RemoveRefToVector(value);
}

/* --- EmitGetIString --- */
static void EmitGetIString_real(unsigned int value, sval_t sourcePos)
{
    EmitOpcode_real(OP_GetIString, 1, CALL_NONE);
    AddOpcodePos(sourcePos.stringValue, SOURCE_TYPE_BREAKPOINT);
    EmitString_real(value);
    CompileTransferRefToString_real(value, 1);
}

/* --- EmitGetString --- */
static void EmitGetString_real(unsigned int value, sval_t sourcePos)
{
    EmitOpcode_real(OP_GetString, 1, CALL_NONE);
    AddOpcodePos(sourcePos.stringValue, 1);
    EmitString_real(value);
    CompileTransferRefToString_real(value, 1);
}

/* --- EmitGetFloat --- */
static void EmitGetFloat_real(float value, sval_t sourcePos)
{
    EmitOpcode_real(OP_GetFloat, 1, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
    EmitFloat_real(value);
}

/* --- EmitGetInteger --- */
static void EmitGetInteger_real(int value, sval_t sourcePos)
{
    if (value >= 0) {
        if (value == 0) {
            EmitOpcode_real(OP_GetZero, 1, CALL_NONE);
            AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
            return;
        }
        if (value <= 255) {
            EmitOpcode_real(OP_GetByte, 1, CALL_NONE);
            AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
            EmitByte_new(value);
            return;
        }
        if (value <= 65535) {
            EmitOpcode_real(OP_GetUnsignedShort, 1, CALL_NONE);
            AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
            EmitUnsignedShort_real(value);
            return;
        }
    } else {
        if (value >= -255) {
            EmitOpcode_real(OP_GetNegByte, 1, CALL_NONE);
            AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
            EmitByte_new(-value);
            return;
        }
        if (value >= -65535) {
            EmitOpcode_real(OP_GetNegUnsignedShort, 1, CALL_NONE);
            AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
            EmitUnsignedShort_real(-value);
            return;
        }
    }
    EmitOpcode_real(OP_GetInteger, 1, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
    EmitCodepos_real((const char *)(intptr_t)value);
}

/* --- EmitValue --- */
static void EmitValue_real(VariableCompileValue *constValue)
{
    switch (constValue->value.type) {
    case 0: /* VAR_UNDEFINED */
        EmitGetUndefined_real(constValue->sourcePos);
        break;
    case 2: /* VAR_STRING */
        EmitGetString_real(constValue->value.u.stringValue, constValue->sourcePos);
        break;
    case 3: /* VAR_ISTRING */
        EmitGetIString_real(constValue->value.u.stringValue, constValue->sourcePos);
        break;
    case 4: /* VAR_VECTOR */
        EmitGetVector_real(constValue->value.u.vectorValue, constValue->sourcePos);
        break;
    case 8: /* VAR_FLOAT */
        EmitGetFloat_real(constValue->value.u.floatValue, constValue->sourcePos);
        break;
    case 6: /* VAR_INTEGER */
        EmitGetInteger_real(constValue->value.u.intValue, constValue->sourcePos);
        break;
    default:
        break;
    }
}

/* --- Scr_CreateVector --- */
static void Scr_CreateVector_real(VariableCompileValue *constValue, VariableValue *value)
{
    float vec[3];
    int i;
    for (i = 0; i < 3; i++) {
        switch (constValue[i].value.type) {
        case 8: /* VAR_FLOAT */
            vec[2 - i] = constValue[i].value.u.floatValue;
            break;
        case 6: /* VAR_INTEGER */
            vec[2 - i] = (float)constValue[i].value.u.intValue;
            break;
        default:
            CompileError(constValue[i].sourcePos.sourcePosValue, "type %s is not a float", var_typename[constValue[i].value.type]);
            return;
        }
    }
    value->type = 4; /* VAR_VECTOR */
    value->u.vectorValue = Scr_AllocVector(vec);
}

/* --- EmitDecTop --- */
static void EmitDecTop_real(void)
{
    EmitOpcode_real(OP_DecTop, -1, CALL_NONE);
}

/* --- EmitCastFieldObject --- */
static void EmitCastFieldObject_real(sval_t sourcePos)
{
    EmitOpcode_real(OP_CastFieldObject, -1, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
}

/* --- EmitSetVariableField --- */
static void EmitSetVariableField_real(sval_t sourcePos)
{
    EmitOpcode_real(OP_SetVariableField, -1, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
}

/* --- EmitCastBool --- */
static void EmitCastBool_real(sval_t sourcePos)
{
    EmitOpcode_real(OP_CastBool, 0, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
}

/* --- EmitBoolNot --- */
static void EmitBoolNot_real(sval_t sourcePos)
{
    EmitOpcode_real(OP_BoolNot, 0, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
}

/* --- EmitBoolComplement --- */
static void EmitBoolComplement_real(sval_t sourcePos)
{
    EmitOpcode_real(OP_BoolComplement, 0, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
}

/* --- EmitSelf --- */
static void EmitSelf_real(sval_t sourcePos)
{
    EmitOpcode_real(OP_GetSelf, 1, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
}

/* --- EmitLevel --- */
static void EmitLevel_real(sval_t sourcePos)
{
    EmitOpcode_real(OP_GetLevel, 1, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
}

/* --- EmitGame --- */
static void EmitGame_real(sval_t sourcePos)
{
    EmitOpcode_real(OP_GetGame, 1, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
}

/* --- EmitAnim --- */
static void EmitAnim_real(sval_t sourcePos)
{
    EmitOpcode_real(OP_GetAnim, 1, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
}

/* --- EmitSelfObject --- */
static void EmitSelfObject_real(sval_t sourcePos)
{
    EmitOpcode_real(OP_GetSelfObject, 0, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
}

/* --- EmitLevelObject --- */
static void EmitLevelObject_real(sval_t sourcePos)
{
    EmitOpcode_real(OP_GetLevelObject, 0, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
}

/* --- EmitAnimObject --- */
static void EmitAnimObject_real(sval_t sourcePos)
{
    EmitOpcode_real(OP_GetAnimObject, 0, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
}

/* --- EmitGameRef --- */
static void EmitGameRef_real(sval_t sourcePos)
{
    EmitOpcode_real(OP_GetGameRef, 0, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
}

/* --- EmitEmptyArray --- */
static void EmitEmptyArray_real(sval_t sourcePos)
{
    EmitOpcode_real(OP_EmptyArray, 1, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
}

/* --- EmitSize --- */
static void EmitSize_real(sval_t expr, sval_t sourcePos, scr_block_t *block)
{
    EmitPrimitiveExpression_real(expr, block);
    EmitOpcode_real(OP_size, 0, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
}

/* --- EmitEvalArray --- */
static void EmitEvalArray_real(sval_t sourcePos, sval_t indexSourcePos)
{
    EmitOpcode_real(OP_EvalArray, -1, CALL_NONE);
    AddOpcodePos(indexSourcePos.sourcePosValue, SOURCE_TYPE_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
}

/* --- EmitEvalArrayRef --- */
static void EmitEvalArrayRef_real(sval_t sourcePos, sval_t indexSourcePos)
{
    EmitOpcode_real(OP_EvalArrayRef, -1, CALL_NONE);
    AddOpcodePos(indexSourcePos.sourcePosValue, SOURCE_TYPE_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
}

/* --- EmitClearArray --- */
static void EmitClearArray_real(sval_t sourcePos, sval_t indexSourcePos)
{
    EmitOpcode_real(OP_ClearArray, -1, CALL_NONE);
    AddOpcodePos(indexSourcePos.sourcePosValue, SOURCE_TYPE_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
}

/* --- EmitPreFunctionCall --- */
static void EmitPreFunctionCall_real(sval_t func_name)
{
    if (((sval_t *)func_name.node)[0].type == ENUM_script_call)
        EmitOpcode_real(OP_PreScriptCall, 1, CALL_NONE);
}

/* --- EmitExpressionList --- */
static int EmitExpressionList_real(sval_t exprlist, scr_block_t *block)
{
    sval_t *node;
    int expr_count = 0;
    for (node = (sval_t *)((sval_t *)exprlist.node)[0].node; node; node = (sval_t *)node[1].node) {
        EmitExpression_real(((sval_t *)node[0].node)[0], block);
        expr_count++;
    }
    return expr_count;
}

/* --- EmitGetFunction --- */
static void EmitGetFunction_real(sval_t func, sval_t sourcePos);

/* --- EmitFunction --- */
static void EmitFunction_real(sval_t func, sval_t sourcePos)
{
    unsigned int threadId, valueId, filename, fileId, posId, countId;
    int scope;
    VariableValue value, pos, count;
    int bExists;
    sval_t *fn = (sval_t *)func.node;

    if (SCRCP->developer_statement == SCR_DEV_IGNORE) {
        Scr_CompileRemoveRefToString_new(fn[1].stringValue);
        if (fn[0].type == ENUM_far_function) {
            Scr_CompileRemoveRefToString_new(fn[2].stringValue);
            SCRCP->far_function_count--;
        }
        return;
    }

    threadId = 0;

    if (fn[0].type == ENUM_local_function) {
        scope = FUNC_SCOPE_LOCAL;
        valueId = GetVariable(SCRCG->fileId, fn[1].idValue);
        CompileTransferRefToString_real(fn[1].stringValue, 2);
        threadId = GetObjectA(valueId);
    } else {
        scope = FUNC_SCOPE_FAR;
        filename = Scr_CreateCanonicalFilename(SL_ConvertToString(fn[1].stringValue));
        Scr_CompileRemoveRefToString_new(fn[1].stringValue);

        value = Scr_EvalVariable(FindVariable(SCRCP->loadedscripts, filename));
        bExists = value.type != 0; /* VAR_UNDEFINED */

        fileId = AddFilePrecache_new(filename, sourcePos.sourcePosValue, 0);

        if (bExists) {
            valueId = FindVariable(fileId, fn[2].idValue);
            if (!valueId || GetObjectType(valueId) != SCRCOMP_VAR_POINTER) {
                CompileError(sourcePos.sourcePosValue, "unknown function");
                return;
            }
        } else {
            valueId = GetVariable(fileId, fn[2].idValue);
        }

        CompileTransferRefToString_real(fn[2].stringValue, 2);

        threadId = GetObjectA(valueId);
        posId = FindVariable(threadId, 1);

        if (posId) {
            pos = Scr_EvalVariable(posId);
            if (pos.type == SCRCOMP_VAR_INCLUDE_CODEPOS) {
                CompileError(sourcePos.sourcePosValue, "unknown function");
                return;
            }
            if (pos.u.codePosValue) {
                if (pos.type == SCRCOMP_VAR_CODEPOS || SCRCP->developer_statement != SCR_DEV_NO)
                    EmitCodepos_real(pos.u.codePosValue);
                else
                    CompileError(sourcePos.sourcePosValue, "normal script cannot reference a function in a /# ... #/ comment");
                return;
            }
        }
    }

    EmitCodepos_real((const char *)(intptr_t)scope);

    countId = GetVariable(threadId, 0);
    count = Scr_EvalVariable(countId);

    if (count.type == 0) { /* VAR_UNDEFINED */
        count.type = 6; /* VAR_INTEGER */
        count.u.intValue = 0;
    }

    valueId = GetNewVariable(threadId, count.u.intValue + 2);
    value.u.codePosValue = (const char *)SCRCG->codePos;

    if (SCRCP->developer_statement != SCR_DEV_NO) {
        value.type = SCRCOMP_VAR_DEVELOPER_CODEPOS;
    } else {
        value.type = SCRCOMP_VAR_CODEPOS;
    }

    SetNewVariableValue(valueId, &value);
    count.u.intValue++;
    SetVariableValue(countId, &count);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
}

/* --- EmitGetFunction --- */
static void EmitGetFunction_real(sval_t func, sval_t sourcePos)
{
    EmitOpcode_real(OP_GetFunction, 1, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT | SOURCE_TYPE_CALL);
    EmitFunction_real(func, sourcePos);
}

/* --- EmitAnimation --- */
static void EmitAnimation_real(sval_t anim, sval_t sourcePos)
{
    EmitOpcode_real(OP_GetAnimation, 1, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
    EmitCodepos_real((const char *)0xFFFFFFFF);
    Scr_EmitAnimation((char *)SCRCG->codePos, anim.stringValue, sourcePos.sourcePosValue);
    Scr_CompileRemoveRefToString_new(anim.stringValue);
}

/* --- EmitAnimTree --- */
static void EmitAnimTree_real(sval_t sourcePos)
{
    if (!SCRAP->animTreeIndex) {
        CompileError(sourcePos.sourcePosValue, "#using_animtree was not specified");
        return;
    }
    EmitGetInteger_real(SCRAP->animTreeIndex, sourcePos);
}

/* --- EmitBreakOn --- */
static void EmitBreakOn_real(sval_t expr, sval_t param, sval_t sourcePos)
{
    CompileError(sourcePos.sourcePosValue, "illegal function name");
}

/* --- EmitObject --- */
static void EmitObject_real(sval_t expr, sval_t sourcePos)
{
    int classnum, entnum;
    const char *s;
    unsigned int idValue;

    if (SCRCP->script_loading) {
        CompileError(sourcePos.sourcePosValue, "$ can only be used in the script debugger");
        return;
    }

    s = SL_ConvertToString(expr.stringValue);

    if (s[0] == 't') {
        idValue = atoi(s + 1);
        if (!idValue || idValue >= VARIABLELIST_CHILD_SIZE || IsObjectFree((unsigned short)idValue)) {
            CompileError(sourcePos.sourcePosValue, "bad expression");
            return;
        }
        {
            int type = GetObjectType((unsigned short)idValue);
            if (type != 17 && type != 18 && type != 19 && type != 20 && type != 23) { /* VAR_THREAD, NOTIFY_THREAD, TIME_THREAD, CHILD_THREAD, DEAD_THREAD */
                CompileError(sourcePos.sourcePosValue, "bad expression");
                return;
            }
        }
        EmitOpcode_real(OP_thread_object, 1, CALL_NONE);
        EmitShort_real(idValue);
    } else {
        classnum = Scr_GetClassnumForCharId(s[0]);
        if (classnum < 0) {
            CompileError(sourcePos.sourcePosValue, "bad expression");
            return;
        }
        entnum = atoi(s + 1);
        if (entnum == 0 && s[1] != '0') {
            CompileError(sourcePos.sourcePosValue, "bad expression");
            return;
        }
        EmitOpcode_real(OP_object, 1, CALL_NONE);
        EmitCodepos_real((const char *)(intptr_t)classnum);
        EmitCodepos_real((const char *)(intptr_t)entnum);
    }
}

/* --- Scr_FindLocalVarIndex --- */
static int Scr_FindLocalVarIndex_real(unsigned int name, sval_t sourcePos, int create, scr_block_t *block)
{
    int i;

    if (!block) {
        CompileError(sourcePos.sourcePosValue, "unreachable code");
        return 0;
    }

    for (i = 0; ; i++) {
        if (i >= block->localVarsCount) {
            if (!create || SCRCG->forceNotCreate) {
                CompileError(sourcePos.sourcePosValue, "uninitialised variable '%s'", SL_ConvertToString(name));
                return 0;
            }
            CompileError(sourcePos.sourcePosValue, "unreachable code");
            return 0;
        }
        if (i == block->localVarsCreateCount) {
            block->localVarsCreateCount++;
            EmitOpcode_real(OP_CreateLocalVariable, 0, CALL_NONE);
            EmitCanonicalStringConst_real(block->localVars[i].name);
        }
        if (block->localVars[i].name == name)
            break;
    }

    Scr_CompileRemoveRefToString_new(name);

    if (block->localVarsInitBits[i >> 3] & (1 << (i & 7)))
        return block->localVarsCreateCount - i - 1;

    if (create && !SCRCG->forceNotCreate) {
        block->localVarsInitBits[i >> 3] |= 1 << (i & 7);
        return block->localVarsCreateCount - i - 1;
    }

    if (!create || SCRCG->forceNotCreate) {
        CompileError(sourcePos.sourcePosValue, "uninitialised variable '%s'", SL_ConvertToString(name));
        return 0;
    }

    CompileError(sourcePos.sourcePosValue, "unreachable code");
    return 0;
}

/* --- EmitLocalVariable --- */
static void EmitLocalVariable_real(sval_t expr, sval_t sourcePos, scr_block_t *block)
{
    int index = Scr_FindLocalVarIndex_real(expr.idValue, sourcePos, 0, block);
    if (index > 5) {
        EmitOpcode_real(OP_EvalLocalVariableCached, 1, CALL_NONE);
        EmitByte_new(index);
    } else {
        EmitOpcode_real(OP_EvalLocalVariableCached0 + index, 1, CALL_NONE);
    }
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
}

/* --- EmitLocalVariableRef --- */
static void EmitLocalVariableRef_real(sval_t expr, sval_t sourcePos, scr_block_t *block)
{
    int index = Scr_FindLocalVarIndex_real(expr.idValue, sourcePos, 1, block);
    if (index) {
        EmitOpcode_real(OP_EvalLocalVariableRefCached, 0, CALL_NONE);
        EmitByte_new(index);
    } else {
        EmitOpcode_real(OP_EvalLocalVariableRefCached0, 0, CALL_NONE);
    }
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
}

/* --- EmitFieldVariable --- */
static void EmitFieldVariable_real(sval_t expr, sval_t field, sval_t sourcePos, scr_block_t *block)
{
    EmitPrimitiveExpressionFieldObject_real(expr, sourcePos, block);
    EmitOpcode_real(OP_EvalFieldVariable, 1, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
    EmitCanonicalString_real(field.stringValue);
}

/* --- EmitFieldVariableRef --- */
static void EmitFieldVariableRef_real(sval_t expr, sval_t field, sval_t sourcePos, scr_block_t *block)
{
    EmitPrimitiveExpressionFieldObject_real(expr, sourcePos, block);
    EmitOpcode_real(OP_EvalFieldVariableRef, 0, CALL_NONE);
    EmitCanonicalString_real(field.stringValue);
}

/* --- EmitClearFieldVariable --- */
static void EmitClearFieldVariable_real(sval_t expr, sval_t field, sval_t sourcePos, sval_t rhsSourcePos, scr_block_t *block)
{
    EmitPrimitiveExpressionFieldObject_real(expr, sourcePos, block);
    EmitOpcode_real(OP_ClearFieldVariable, 0, CALL_NONE);
    AddOpcodePos(rhsSourcePos.sourcePosValue, SOURCE_TYPE_NONE);
    EmitCanonicalString_real(field.stringValue);
}

/* --- EmitArrayVariable --- */
static void EmitArrayVariable_real(sval_t expr, sval_t index, sval_t sourcePos, sval_t indexSourcePos, scr_block_t *block)
{
    EmitExpression_real(index, block);
    EmitPrimitiveExpression_real(expr, block);
    EmitEvalArray_real(sourcePos, indexSourcePos);
}

/* --- EmitArrayPrimitiveExpressionRef --- */
static void EmitArrayPrimitiveExpressionRef_real(sval_t expr, sval_t sourcePos, scr_block_t *block)
{
    sval_t *n = (sval_t *)expr.node;
    if (n[0].type == ENUM_variable) {
        EmitVariableExpressionRef_real(n[1], block);
        return;
    }
    if (n[0].type == ENUM_game) {
        EmitGameRef_real(n[1]);
        return;
    }
    CompileError(sourcePos.sourcePosValue, "not an lvalue");
}

/* --- EmitArrayVariableRef --- */
static void EmitArrayVariableRef_real(sval_t expr, sval_t index, sval_t sourcePos, sval_t indexSourcePos, scr_block_t *block)
{
    EmitExpression_real(index, block);
    EmitArrayPrimitiveExpressionRef_real(expr, sourcePos, block);
    EmitEvalArrayRef_real(sourcePos, indexSourcePos);
}

/* --- EmitClearArrayVariable --- */
static void EmitClearArrayVariable_real(sval_t expr, sval_t index, sval_t sourcePos, sval_t indexSourcePos, scr_block_t *block)
{
    EmitExpression_real(index, block);
    EmitArrayPrimitiveExpressionRef_real(expr, sourcePos, block);
    EmitClearArray_real(sourcePos, indexSourcePos);
}

/* --- EmitVariableExpression --- */
static void EmitVariableExpression_real(sval_t expr, scr_block_t *block)
{
    sval_t *n = (sval_t *)expr.node;
    switch (n[0].type) {
    case ENUM_local_variable:
        EmitLocalVariable_real(n[1], n[2], block);
        break;
    case ENUM_array_variable:
        EmitArrayVariable_real(n[1], n[2], n[3], n[4], block);
        break;
    case ENUM_field_variable:
        EmitFieldVariable_real(n[1], n[2], n[3], block);
        break;
    case ENUM_self_field:
        if (SCRCP->script_loading)
            CompileError(n[2].sourcePosValue, "self field can only be used in the script debugger");
        else
            CompileError(n[2].sourcePosValue, "self field in assignment expression not currently supported");
        break;
    case ENUM_object:
        EmitObject_real(n[1], n[2]);
        break;
    }
}

/* --- EmitVariableExpressionRef --- */
static void EmitVariableExpressionRef_real(sval_t expr, scr_block_t *block)
{
    sval_t *n = (sval_t *)expr.node;
    switch (n[0].type) {
    case ENUM_local_variable:
        EmitLocalVariableRef_real(n[1], n[2], block);
        break;
    case ENUM_array_variable:
        EmitArrayVariableRef_real(n[1], n[2], n[3], n[4], block);
        break;
    case ENUM_field_variable:
        EmitFieldVariableRef_real(n[1], n[2], n[3], block);
        break;
    case ENUM_self_field:
    case ENUM_object:
        if (SCRCP->script_loading)
            CompileError(n[2].sourcePosValue, "$ and self field can only be used in the script debugger");
        else
            CompileError(n[2].sourcePosValue, "not an lvalue");
        break;
    }
}

/* --- EmitClearVariableExpression --- */
static int EmitClearVariableExpression_real(sval_t expr, sval_t rhsSourcePos, scr_block_t *block)
{
    sval_t *n = (sval_t *)expr.node;
    switch (n[0].type) {
    case ENUM_local_variable:
        return 0;
    case ENUM_array_variable:
        EmitClearArrayVariable_real(n[1], n[2], n[3], n[4], block);
        return 1;
    case ENUM_field_variable:
        EmitClearFieldVariable_real(n[1], n[2], n[3], rhsSourcePos, block);
        return 1;
    case ENUM_self_field:
    case ENUM_object:
        if (SCRCP->script_loading)
            CompileError(n[2].sourcePosValue, "$ and self field can only be used in the script debugger");
        else
            CompileError(n[2].sourcePosValue, "not an lvalue");
        return 1;
    default:
        return 1;
    }
}

/* --- EmitExpressionListFieldObject --- */
static void EmitExpressionListFieldObject_real(sval_t exprlist, sval_t sourcePos, scr_block_t *block);

/* --- EmitCallExpressionFieldObject --- */
static void EmitCallExpressionFieldObject_real(sval_t expr, scr_block_t *block)
{
    sval_t *n = (sval_t *)expr.node;
    if (n[0].type == ENUM_call) {
        EmitCall_real(n[1], n[2], 0, block);
        EmitCastFieldObject_real(n[3]);
    } else if (n[0].type == ENUM_method) {
        EmitMethod_real(n[1], n[2], n[3], n[4], 0, block);
        EmitCastFieldObject_real(n[5]);
    }
}

/* --- EmitExpressionFieldObject --- */
static void EmitExpressionFieldObject_real(sval_t expr, sval_t sourcePos, scr_block_t *block)
{
    sval_t *n = (sval_t *)expr.node;
    if (n[0].type == ENUM_primitive_expression) {
        EmitPrimitiveExpressionFieldObject_real(n[1], n[2], block);
        return;
    }
    CompileError(sourcePos.sourcePosValue, "not an object");
}

/* --- EmitExpressionListFieldObject --- */
static void EmitExpressionListFieldObject_real(sval_t exprlist, sval_t sourcePos, scr_block_t *block)
{
    sval_t *node = GetSingleParameter_real(exprlist);
    if (node) {
        EmitExpressionFieldObject_real(((sval_t *)node[0].node)[0], ((sval_t *)node[0].node)[1], block);
        return;
    }
    CompileError(sourcePos.sourcePosValue, "not an object");
}

/* --- EmitPrimitiveExpressionFieldObject --- */
static void EmitPrimitiveExpressionFieldObject_real(sval_t expr, sval_t sourcePos, scr_block_t *block)
{
    sval_t *n = (sval_t *)expr.node;
    switch (n[0].type) {
    case ENUM_variable:
        EmitVariableExpression_real(n[1], block);
        EmitCastFieldObject_real(n[2]);
        break;
    case ENUM_call_expression:
        EmitCallExpressionFieldObject_real(n[1], block);
        break;
    case ENUM_self:
        EmitSelfObject_real(n[1]);
        break;
    case ENUM_level:
        EmitLevelObject_real(n[1]);
        break;
    case ENUM_anim:
        EmitAnimObject_real(n[1]);
        break;
    case ENUM_expression_list:
        EmitExpressionListFieldObject_real(n[1], sourcePos, block);
        break;
    default:
        CompileError(sourcePos.sourcePosValue, "not an object");
        break;
    }
}

/* --- EvalBinaryOperatorExpression --- */
static int EvalBinaryOperatorExpression_real(sval_t expr1, sval_t expr2, sval_t opcode, sval_t sourcePos, VariableCompileValue *constValue)
{
    VariableCompileValue constValue1, constValue2;

    if (!EvalExpression_real(expr1, &constValue1))
        return 0;
    if (!EvalExpression_real(expr2, &constValue2))
        return 0;

    AddRefToValue(constValue1.value.type, constValue1.value.u);
    AddRefToValue(constValue2.value.type, constValue2.value.u);

    Scr_EvalBinaryOperator(opcode.type, &constValue1.value, &constValue2.value);

    if (SCRVP->error_message) {
        CompileError(sourcePos.sourcePosValue, "%s", SCRVP->error_message);
        return 0;
    }

    constValue->value.u = constValue1.value.u;
    constValue->value.type = constValue1.value.type;
    constValue->sourcePos = sourcePos;
    return 1;
}

/* --- EvalPrimitiveExpressionList --- */
static int EvalPrimitiveExpressionList_real(sval_t exprlist, sval_t sourcePos, VariableCompileValue *constValue)
{
    VariableCompileValue constValue2[3];
    sval_t *node;
    int i, expr_count;

    expr_count = GetExpressionCount_real(exprlist);

    if (expr_count == 1)
        return EvalExpression_real(((sval_t *)((sval_t *)((sval_t *)exprlist.node)[0].node)[0].node)[0], constValue);

    if (expr_count != 3)
        return 0;

    for (i = 0, node = (sval_t *)((sval_t *)exprlist.node)[0].node; node; node = (sval_t *)node[1].node, i++) {
        if (!EvalExpression_real(((sval_t *)node[0].node)[0], &constValue2[i]))
            return 0;
    }

    Scr_CreateVector_real(constValue2, &constValue->value);
    constValue->sourcePos = sourcePos;
    return 1;
}

/* --- EvalPrimitiveExpression --- */
static int EvalPrimitiveExpression_real(sval_t expr, VariableCompileValue *constValue)
{
    sval_t *n = (sval_t *)expr.node;
    switch (n[0].type) {
    case ENUM_integer:
        EvalInteger_real(n[1].intValue, n[2], constValue);
        return 1;
    case ENUM_float:
        EvalFloat_real(n[1].floatValue, n[2], constValue);
        return 1;
    case ENUM_minus_integer:
        EvalInteger_real(-n[1].intValue, n[2], constValue);
        return 1;
    case ENUM_minus_float:
        EvalFloat_real(-n[1].floatValue, n[2], constValue);
        return 1;
    case ENUM_string:
        EvalString_real(n[1].stringValue, n[2], constValue);
        return 1;
    case ENUM_istring:
        EvalIString_real(n[1].stringValue, n[2], constValue);
        return 1;
    case ENUM_undefined:
        EvalUndefined_real(n[1], constValue);
        return 1;
    case ENUM_expression_list:
        return EvalPrimitiveExpressionList_real(n[1], n[2], constValue);
    case ENUM_false:
        EvalInteger_real(0, n[1], constValue);
        return 1;
    case ENUM_true:
        EvalInteger_real(1, n[1], constValue);
        return 1;
    default:
        return 0;
    }
}

/* --- EvalExpression --- */
static int EvalExpression_real(sval_t expr, VariableCompileValue *constValue)
{
    sval_t *n = (sval_t *)expr.node;
    if (n[0].type == ENUM_primitive_expression)
        return EvalPrimitiveExpression_real(n[1], constValue);
    if (n[0].type == ENUM_binary)
        return EvalBinaryOperatorExpression_real(n[1], n[2], n[3], n[4], constValue);
    return 0;
}

/* --- EmitOrEvalPrimitiveExpressionList --- */
static int EmitOrEvalPrimitiveExpressionList_real(sval_t exprlist, sval_t sourcePos, VariableCompileValue *constValue, scr_block_t *block)
{
    VariableCompileValue constValue2;
    int success;
    sval_t *node;
    int expr_count;

    expr_count = GetExpressionCount_real(exprlist);

    if (expr_count == 1)
        return EmitOrEvalExpression_real(((sval_t *)((sval_t *)((sval_t *)exprlist.node)[0].node)[0].node)[0], constValue, block);

    if (expr_count != 3) {
        CompileError(sourcePos.sourcePosValue, "expression list must have 1 or 3 parameters");
        return 0;
    }

    success = 1;
    for (node = (sval_t *)((sval_t *)exprlist.node)[0].node; node; node = (sval_t *)node[1].node) {
        if (success) {
            success = EmitOrEvalExpression_real(((sval_t *)node[0].node)[0], &constValue2, block);
            if (success)
                Scr_PushValue_real(&constValue2);
        } else {
            EmitExpression_real(((sval_t *)node[0].node)[0], block);
        }
    }

    if (success) {
        SCRCP->value_count -= 3;
        Scr_CreateVector_real(&SCRCG->value_start[SCRCP->value_count], &constValue->value);
        constValue->sourcePos = sourcePos;
        return 1;
    }

    EmitOpcode_real(OP_vector, -2, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
    AddExpressionListOpcodePos_real(exprlist);
    return 0;
}

/* --- EmitOrEvalPrimitiveExpression --- */
static int EmitOrEvalPrimitiveExpression_real(sval_t expr, VariableCompileValue *constValue, scr_block_t *block)
{
    sval_t *n = (sval_t *)expr.node;
    switch (n[0].type) {
    case ENUM_variable:
        EmitVariableExpression_real(n[1], block);
        return 0;
    case ENUM_function:
        EmitGetFunction_real(n[1], n[2]);
        return 0;
    case ENUM_call_expression:
        EmitCallExpression_real(n[1], 0, block);
        return 0;
    case ENUM_self:
        EmitSelf_real(n[1]);
        return 0;
    case ENUM_level:
        EmitLevel_real(n[1]);
        return 0;
    case ENUM_game:
        EmitGame_real(n[1]);
        return 0;
    case ENUM_anim:
        EmitAnim_real(n[1]);
        return 0;
    case ENUM_expression_list:
        return EmitOrEvalPrimitiveExpressionList_real(n[1], n[2], constValue, block);
    case ENUM_size_field:
        EmitSize_real(n[1], n[2], block);
        return 0;
    case ENUM_empty_array:
        EmitEmptyArray_real(n[1]);
        return 0;
    case ENUM_animation:
        EmitAnimation_real(n[1], n[2]);
        return 0;
    case ENUM_animtree:
        EmitAnimTree_real(n[1]);
        return 0;
    case ENUM_breakon:
        EmitBreakOn_real(n[1], n[2], n[3]);
        return 0;
    default:
        return EvalPrimitiveExpression_real(expr, constValue);
    }
}

/* --- EmitOrEvalBinaryOperatorExpression --- */
static int EmitOrEvalBinaryOperatorExpression_real(sval_t expr1, sval_t expr2, sval_t opcode, sval_t sourcePos, VariableCompileValue *constValue, scr_block_t *block)
{
    VariableCompileValue constValue1, constValue2;

    if (!EmitOrEvalExpression_real(expr1, &constValue1, block)) {
        EmitExpression_real(expr2, block);
        EmitOpcode_real(opcode.type, -1, CALL_NONE);
        AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
        return 0;
    }

    Scr_PushValue_real(&constValue1);

    if (!EmitOrEvalExpression_real(expr2, &constValue2, block)) {
        EmitOpcode_real(opcode.type, -1, CALL_NONE);
        AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
        return 0;
    }

    Scr_PopValue_real();
    Scr_EvalBinaryOperator(opcode.intValue, &constValue1.value, &constValue2.value);

    if (SCRVP->error_message) {
        CompileError(sourcePos.sourcePosValue, "%s", SCRVP->error_message);
        return 0;
    }

    constValue->value.u = constValue1.value.u;
    constValue->value.type = constValue1.value.type;
    constValue->sourcePos = sourcePos;
    return 1;
}

/* --- EmitBoolAndExpression --- */
static void EmitBoolAndExpression_real(sval_t expr1, sval_t expr2, sval_t expr1sourcePos, sval_t expr2sourcePos, scr_block_t *block)
{
    const char *nextPos, *pos;
    unsigned int offset;

    EmitExpression_real(expr1, block);
    EmitOpcode_real(OP_JumpOnFalseExpr, -1, CALL_NONE);
    AddOpcodePos(expr1sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
    EmitUnsignedShort_real(0);

    pos = (const char *)SCRCG->codePos;
    nextPos = TempMallocAlignStrict(0);

    EmitExpression_real(expr2, block);
    EmitCastBool_real(expr2sourcePos);

    offset = TempMallocAlignStrict(0) - nextPos;
    *(unsigned short *)pos = offset;
}

/* --- EmitBoolOrExpression --- */
static void EmitBoolOrExpression_real(sval_t expr1, sval_t expr2, sval_t expr1sourcePos, sval_t expr2sourcePos, scr_block_t *block)
{
    const char *nextPos, *pos;
    unsigned int offset;

    EmitExpression_real(expr1, block);
    EmitOpcode_real(OP_JumpOnTrueExpr, -1, CALL_NONE);
    AddOpcodePos(expr1sourcePos.stringValue, SOURCE_TYPE_NONE);
    EmitUnsignedShort_real(0);

    pos = (const char *)SCRCG->codePos;
    nextPos = TempMallocAlignStrict(0);

    EmitExpression_real(expr2, block);
    EmitCastBool_real(expr2sourcePos);

    offset = TempMallocAlignStrict(0) - nextPos;
    *(unsigned short *)pos = offset;
}

/* --- EmitOrEvalExpression --- */
static int EmitOrEvalExpression_real(sval_t expr, VariableCompileValue *constValue, scr_block_t *block)
{
    sval_t *n = (sval_t *)expr.node;
    switch (n[0].type) {
    case ENUM_primitive_expression:
        return EmitOrEvalPrimitiveExpression_real(n[1], constValue, block);
    case ENUM_bool_or:
        EmitBoolOrExpression_real(n[1], n[2], n[3], n[4], block);
        return 0;
    case ENUM_bool_and:
        EmitBoolAndExpression_real(n[1], n[2], n[3], n[4], block);
        return 0;
    case ENUM_binary:
        return EmitOrEvalBinaryOperatorExpression_real(n[1], n[2], n[3], n[4], constValue, block);
    case ENUM_bool_not:
        EmitExpression_real(n[1], block);
        EmitBoolNot_real(n[2]);
        return 0;
    case ENUM_bool_complement:
        EmitExpression_real(n[1], block);
        EmitBoolComplement_real(n[2]);
        return 0;
    default:
        return 0;
    }
}

/* --- EmitExpression --- */
static void EmitExpression_real(sval_t expr, scr_block_t *block)
{
    VariableCompileValue constValue;
    if (EmitOrEvalExpression_real(expr, &constValue, block))
        EmitValue_real(&constValue);
}

/* --- EmitPrimitiveExpression --- */
static void EmitPrimitiveExpression_real(sval_t expr, scr_block_t *block)
{
    VariableCompileValue constValue;
    if (EmitOrEvalPrimitiveExpression_real(expr, &constValue, block))
        EmitValue_real(&constValue);
}

/* --- EmitRemoveLocalVars --- */
static void EmitRemoveLocalVars_real(scr_block_t *block, scr_block_t *outerBlock)
{
    int removeCount;
    if (block->abortLevel != SCR_ABORT_NONE)
        return;
    removeCount = block->localVarsCreateCount - outerBlock->localVarsPublicCount;
    if (!removeCount)
        return;
    EmitOpcode_real(OP_RemoveLocalVariables, 0, CALL_NONE);
    EmitByte_new(removeCount);
    block->localVarsCreateCount = block->localVarsPublicCount;
}

/* --- EmitCreateLocalVars --- */
static void EmitCreateLocalVars_real(scr_block_t *block)
{
    int i;
    if (block->localVarsCreateCount == block->localVarsPublicCount)
        return;
    for (i = block->localVarsCreateCount; i < block->localVarsPublicCount; i++) {
        EmitOpcode_real(OP_CreateLocalVariable, 0, CALL_NONE);
        EmitCanonicalStringConst_real(block->localVars[i].name);
    }
    block->localVarsCreateCount = block->localVarsPublicCount;
}

/* --- ConnectBreakStatements --- */
static void ConnectBreakStatements_real(void)
{
    const char *codePos = (char *)TempMalloc(0);
    BreakStatementInfo *statement;
    for (statement = SCRCG->currentBreakStatement; statement; statement = (BreakStatementInfo *)(intptr_t)statement->next)
        *(int *)statement->codePos = codePos - statement->nextCodePos;
}

/* --- ConnectContinueStatements --- */
static void ConnectContinueStatements_real(void)
{
    const char *codePos = (char *)TempMalloc(0);
    ContinueStatementInfo *statement;
    for (statement = SCRCG->currentContinueStatement; statement; statement = (ContinueStatementInfo *)(intptr_t)statement->next)
        *(int *)statement->codePos = codePos - statement->nextCodePos;
}

/* --- EmitCaseStatementInfo --- */
static void EmitCaseStatementInfo_real(unsigned int name, sval_t sourcePos)
{
    CaseStatementInfo *newCaseStatement;
    if (SCRCP->developer_statement == SCR_DEV_IGNORE)
        return;
    newCaseStatement = (CaseStatementInfo *)Hunk_AllocateTempMemoryHighInternal(sizeof(*newCaseStatement));
    newCaseStatement->name = name;
    newCaseStatement->codePos = (char *)TempMalloc(0);
    newCaseStatement->sourcePos = sourcePos.sourcePosValue;
    newCaseStatement->next = (int)(intptr_t)SCRCG->currentCaseStatement;
    SCRCG->currentCaseStatement = newCaseStatement;
}

/* --- EmitCaseStatement --- */
static void EmitCaseStatement_real(sval_t expr, sval_t sourcePos)
{
    unsigned int name;
    sval_t *n = (sval_t *)expr.node;

    if (n[0].type == ENUM_integer) {
        if (!IsValidArrayIndex(n[1].intValue)) {
            CompileError(sourcePos.sourcePosValue, va("case index %d out of range", n[1].intValue));
            return;
        }
        name = GetInternalVariableIndex(n[1].intValue);
    } else {
        if (n[0].type != ENUM_string) {
            CompileError(sourcePos.sourcePosValue, "case expression must be an int or string");
            return;
        }
        name = n[1].stringValue;
        CompileTransferRefToString_real(name, 1);
    }
    EmitCaseStatementInfo_real(name, sourcePos);
}

/* --- EmitDefaultStatement --- */
static void EmitDefaultStatement_real(sval_t sourcePos)
{
    EmitCaseStatementInfo_real(0, sourcePos);
}

/* --- EmitNOP2 --- */
static void EmitNOP2_real(int lastStatement, unsigned int endSourcePos, scr_block_t *block)
{
    int checksum = SCRVP->checksum;
    if (lastStatement) {
        EmitEnd_real();
        AddOpcodePos(endSourcePos, SOURCE_TYPE_BREAKPOINT);
    } else {
        EmitRemoveLocalVars_real(block, block);
    }
    SCRVP->checksum = checksum + 1;
}

/* --- EmitCallExpression --- */
static void EmitCallExpression_real(sval_t expr, int bStatement, scr_block_t *block)
{
    sval_t *n = (sval_t *)expr.node;
    if (n[0].type == ENUM_call)
        EmitCall_real(n[1], n[2], bStatement, block);
    else if (n[0].type == ENUM_method)
        EmitMethod_real(n[1], n[2], n[3], n[4], bStatement, block);
}

/* --- EmitCallExpressionStatement --- */
static void EmitCallExpressionStatement_real(sval_t expr, scr_block_t *block)
{
    EmitCallExpression_real(expr, 1, block);
}

/* --- EmitCallBuiltinOpcode --- */
static void EmitCallBuiltinOpcode_real(int param_count, sval_t sourcePos)
{
    unsigned int opcode;
    if (param_count > 5)
        opcode = OP_CallBuiltin;
    else
        opcode = OP_CallBuiltin0 + param_count;
    EmitOpcode_real(opcode, 1 - param_count, CALL_BUILTIN);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
    if (opcode == OP_CallBuiltin)
        EmitByte_new(param_count);
}

/* --- EmitCallBuiltinMethodOpcode --- */
static void EmitCallBuiltinMethodOpcode_real(int param_count, sval_t sourcePos)
{
    unsigned int opcode;
    if (param_count > 5)
        opcode = OP_CallBuiltinMethod;
    else
        opcode = OP_CallBuiltinMethod0 + param_count;
    EmitOpcode_real(opcode, -param_count, CALL_BUILTIN);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
    if (opcode == OP_CallBuiltinMethod)
        EmitByte_new(param_count);
}

/* --- Scr_GetUncacheType --- */
static int Scr_GetUncacheType_real(int type)
{
    if (type == SCRCOMP_VAR_CODEPOS)
        return BUILTIN_ANY;
    return BUILTIN_DEVELOPER_ONLY;
}

/* --- Scr_GetCacheType --- */
static int Scr_GetCacheType_real(int type)
{
    if (type == BUILTIN_ANY)
        return SCRCOMP_VAR_CODEPOS;
    return SCRCOMP_VAR_DEVELOPER_CODEPOS;
}

/* --- Scr_BeginDevScript --- */
static void Scr_BeginDevScript_real(int *type, char **savedPos)
{
    if (SCRCP->developer_statement != SCR_DEV_NO) {
        *type = BUILTIN_ANY;
        return;
    }
    if (SCRVP->developer_script) {
        SCRCP->developer_statement = SCR_DEV_YES;
        *type = BUILTIN_DEVELOPER_ONLY;
        return;
    }
    *savedPos = (char *)TempMalloc(0);
    SCRCP->developer_statement = SCR_DEV_IGNORE;
    *type = BUILTIN_DEVELOPER_ONLY;
}

/* --- Scr_EndDevScript --- */
static void Scr_EndDevScript_real(int type, char **savedPos)
{
    if (type != BUILTIN_DEVELOPER_ONLY)
        return;
    SCRCP->developer_statement = SCR_DEV_NO;
    if (SCRVP->developer_script)
        return;
    TempMemorySetPos(*savedPos);
}

/* --- EmitPostScriptFunction --- */
static void EmitPostScriptFunction_real(sval_t func, int param_count, int bMethod, sval_t nameSourcePos)
{
    if (bMethod)
        EmitOpcode_real(OP_ScriptMethodCall, -param_count - 1, CALL_FUNCTION);
    else
        EmitOpcode_real(OP_ScriptFunctionCall, -param_count, CALL_FUNCTION);
    AddOpcodePos(nameSourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT | SOURCE_TYPE_CALL);
    EmitFunction_real(func, nameSourcePos);
}

/* --- EmitPostScriptThread --- */
static void EmitPostScriptThread_real(sval_t func, int param_count, int bMethod, sval_t sourcePos)
{
    if (bMethod)
        EmitOpcode_real(OP_ScriptMethodThreadCall, -param_count, CALL_THREAD);
    else
        EmitOpcode_real(OP_ScriptThreadCall, 1 - param_count, CALL_THREAD);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT | SOURCE_TYPE_CALL);
    EmitFunction_real(func, sourcePos);
    EmitCodepos_real((const char *)(intptr_t)param_count);
}

/* --- EmitPostScriptFunctionPointer --- */
static void EmitPostScriptFunctionPointer_real(sval_t expr, int param_count, int bMethod, sval_t nameSourcePos, sval_t sourcePos, scr_block_t *block)
{
    EmitExpression_real(expr, block);
    if (bMethod)
        EmitOpcode_real(OP_ScriptMethodCallPointer, -param_count - 2, CALL_FUNCTION);
    else
        EmitOpcode_real(OP_ScriptFunctionCallPointer, -param_count - 1, CALL_FUNCTION);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
    AddOpcodePos(nameSourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
}

/* --- EmitPostScriptThreadPointer --- */
static void EmitPostScriptThreadPointer_real(sval_t expr, int param_count, int bMethod, sval_t sourcePos, scr_block_t *block)
{
    EmitExpression_real(expr, block);
    if (bMethod)
        EmitOpcode_real(OP_ScriptMethodThreadCallPointer, -param_count - 1, CALL_THREAD);
    else
        EmitOpcode_real(OP_ScriptThreadCallPointer, -param_count, CALL_THREAD);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
    EmitCodepos_real((const char *)(intptr_t)param_count);
}

/* --- EmitPostScriptFunctionCall --- */
static void EmitPostScriptFunctionCall_real(sval_t func_name, int param_count, int bMethod, sval_t nameSourcePos, scr_block_t *block)
{
    sval_t *n = (sval_t *)func_name.node;
    if (n[0].type == ENUM_function)
        EmitPostScriptFunction_real(n[1], param_count, bMethod, nameSourcePos);
    else if (n[0].type == ENUM_function_pointer)
        EmitPostScriptFunctionPointer_real(n[1], param_count, bMethod, nameSourcePos, n[2], block);
}

/* --- EmitPostScriptThreadCall --- */
static void EmitPostScriptThreadCall_real(sval_t func_name, int param_count, int bMethod, sval_t sourcePos, sval_t nameSourcePos, scr_block_t *block)
{
    sval_t *n = (sval_t *)func_name.node;
    if (n[0].type == ENUM_function)
        EmitPostScriptThread_real(n[1], param_count, bMethod, nameSourcePos);
    else if (n[0].type == ENUM_function_pointer)
        EmitPostScriptThreadPointer_real(n[1], param_count, bMethod, n[2], block);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
}

/* --- EmitPostFunctionCall --- */
static void EmitPostFunctionCall_real(sval_t func_name, int param_count, int bMethod, scr_block_t *block)
{
    sval_t *n = (sval_t *)func_name.node;
    if (n[0].type == ENUM_script_call)
        EmitPostScriptFunctionCall_real(n[1], param_count, bMethod, n[2], block);
    else if (n[0].type == ENUM_script_thread_call)
        EmitPostScriptThreadCall_real(n[1], param_count, bMethod, n[2], n[3], block);
}

/* --- EmitCall --- */
static void EmitCall_real(sval_t func_name, sval_t params, int bStatement, scr_block_t *block)
{
    VariableValue value;
    unsigned int funcId, name;
    char *savedPos = NULL;
    void (*func)(void);
    int type, param_count;
    const char *pName;
    sval_t sourcePos;

    name = Scr_GetBuiltin_real(func_name);

    if (!name) {
        EmitPreFunctionCall_real(func_name);
        param_count = EmitExpressionList_real(params, block);
        EmitPostFunctionCall_real(func_name, param_count, 0, block);
        AddExpressionListOpcodePos_real(params);
        if (bStatement)
            EmitDecTop_real();
        return;
    }

    pName = SL_ConvertToString(name);
    sourcePos = ((sval_t *)func_name.node)[2];

    funcId = FindVariable(SCRCP->builtinFunc, name);
    if (funcId) {
        value = Scr_EvalVariable(funcId);
        type = Scr_GetUncacheType_real(value.type);
        func = (void (*)(void))(intptr_t)value.u.intValue;
    } else {
        type = BUILTIN_ANY;
        func = Scr_GetFunction(&pName, &type);
        funcId = GetNewVariable(SCRCP->builtinFunc, name);
        value.type = Scr_GetCacheType_real(type);
        value.u.intValue = (int)(intptr_t)func;
        SetVariableValue(funcId, &value);
    }

    if (!func) {
        EmitPreFunctionCall_real(func_name);
        param_count = EmitExpressionList_real(params, block);
        EmitPostFunctionCall_real(func_name, param_count, 0, block);
        AddExpressionListOpcodePos_real(params);
        if (bStatement)
            EmitDecTop_real();
        return;
    }

    if (type == BUILTIN_DEVELOPER_ONLY) {
        Scr_BeginDevScript_real(&type, &savedPos);
        if (type == BUILTIN_DEVELOPER_ONLY && !bStatement) {
            CompileError(sourcePos.sourcePosValue, "return value of developer command can not be accessed if not in a /# ... #/ comment");
            return;
        }
    }

    param_count = EmitExpressionList_real(params, block);
    if (param_count > 256) {
        CompileError(sourcePos.stringValue, "parameter count exceeds 256");
        return;
    }

    Scr_CompileRemoveRefToString_new(name);
    EmitCallBuiltinOpcode_real(param_count, sourcePos);
    EmitUnsignedShort_real(AddFunction_real((int)(intptr_t)func));
    AddExpressionListOpcodePos_real(params);

    if (bStatement)
        EmitDecTop_real();
    Scr_EndDevScript_real(type, &savedPos);
}

/* --- EmitMethod --- */
static void EmitMethod_real(sval_t expr, sval_t func_name, sval_t params, sval_t methodSourcePos, int bStatement, scr_block_t *block)
{
    VariableValue value;
    unsigned int methId, name;
    char *savedPos = NULL;
    void (*meth)(scr_entref_t);
    int type, param_count;
    const char *pName;
    sval_t sourcePos;

    name = Scr_GetBuiltin_real(func_name);

    if (!name) {
        EmitPreFunctionCall_real(func_name);
        param_count = EmitExpressionList_real(params, block);
        EmitPrimitiveExpression_real(expr, block);
        EmitPostFunctionCall_real(func_name, param_count, 1, block);
        AddOpcodePos(methodSourcePos.sourcePosValue, SOURCE_TYPE_NONE);
        AddExpressionListOpcodePos_real(params);
        if (bStatement)
            EmitDecTop_real();
        return;
    }

    pName = SL_ConvertToString(name);
    sourcePos = ((sval_t *)func_name.node)[2];

    methId = FindVariable(SCRCP->builtinMeth, name);
    if (methId) {
        value = Scr_EvalVariable(methId);
        type = Scr_GetUncacheType_real(value.type);
        meth = (void (*)(scr_entref_t))(intptr_t)value.u.intValue;
    } else {
        type = BUILTIN_ANY;
        meth = Scr_GetMethod(&pName, &type);
        methId = GetNewVariable(SCRCP->builtinMeth, name);
        value.type = Scr_GetCacheType_real(type);
        value.u.intValue = (int)(intptr_t)meth;
        SetVariableValue(methId, &value);
    }

    if (!meth) {
        EmitPreFunctionCall_real(func_name);
        param_count = EmitExpressionList_real(params, block);
        EmitPrimitiveExpression_real(expr, block);
        EmitPostFunctionCall_real(func_name, param_count, 1, block);
        AddOpcodePos(methodSourcePos.sourcePosValue, SOURCE_TYPE_NONE);
        AddExpressionListOpcodePos_real(params);
        if (bStatement)
            EmitDecTop_real();
        return;
    }

    if (type == BUILTIN_DEVELOPER_ONLY) {
        Scr_BeginDevScript_real(&type, &savedPos);
        if (type == BUILTIN_DEVELOPER_ONLY && !bStatement) {
            CompileError(sourcePos.sourcePosValue, "return value of developer command can not be accessed if not in a /# ... #/ comment");
            return;
        }
    }

    param_count = EmitExpressionList_real(params, block);
    EmitPrimitiveExpression_real(expr, block);
    if (param_count > 256) {
        CompileError(sourcePos.sourcePosValue, "parameter count exceeds 256");
        return;
    }

    Scr_CompileRemoveRefToString_new(name);
    EmitCallBuiltinMethodOpcode_real(param_count, sourcePos);
    EmitUnsignedShort_real(AddFunction_real((int)(intptr_t)meth));
    AddOpcodePos(methodSourcePos.sourcePosValue, SOURCE_TYPE_NONE);
    AddExpressionListOpcodePos_real(params);

    if (bStatement)
        EmitDecTop_real();
    Scr_EndDevScript_real(type, &savedPos);
}

/* --- EmitSafeSetVariableField --- */
static void EmitSafeSetVariableField_real(sval_t expr, sval_t sourcePos, scr_block_t *block)
{
    int index = Scr_FindLocalVarIndex_real(expr.idValue, sourcePos, 1, block);
    if (index) {
        EmitOpcode_real(OP_SafeSetVariableFieldCached, 0, CALL_NONE);
        EmitByte_new(index);
    } else {
        EmitOpcode_real(OP_SafeSetVariableFieldCached0, 0, CALL_NONE);
    }
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
}

/* --- EmitSafeSetWaittillVariableField --- */
static void EmitSafeSetWaittillVariableField_real(sval_t expr, sval_t sourcePos, scr_block_t *block)
{
    byte index = Scr_FindLocalVarIndex_real(expr.idValue, sourcePos, 1, block);
    EmitOpcode_real(OP_SafeSetWaittillVariableFieldCached, 0, CALL_NONE);
    EmitByte_new(index);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
}

/* --- EmitFormalParameterListInternal --- */
static void EmitFormalParameterListInternal_real(sval_t *node, scr_block_t *block)
{
    while (1) {
        node = (sval_t *)node[1].node;
        if (!node)
            break;
        EmitSafeSetVariableField_real(((sval_t *)node[0].node)[0], ((sval_t *)node[0].node)[1], block);
    }
}

/* --- EmitFormalWaittillParameterListRefInternal --- */
static void EmitFormalWaittillParameterListRefInternal_real(sval_t *node, scr_block_t *block)
{
    while (1) {
        node = (sval_t *)node[1].node;
        if (!node)
            break;
        EmitSafeSetWaittillVariableField_real(((sval_t *)node[0].node)[0], ((sval_t *)node[0].node)[1], block);
    }
}

/* --- EmitFormalParameterList --- */
static void EmitFormalParameterList_real(sval_t exprlist, sval_t sourcePos, scr_block_t *block)
{
    EmitFormalParameterListInternal_real((sval_t *)((sval_t *)exprlist.node)[0].node, block);
    EmitOpcode_real(OP_checkclearparams, 0, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
}

/* --- EmitBreakpointStatement --- */
static void EmitBreakpointStatement_real(sval_t sourcePos)
{
    if (!SCRVP->developer_script)
        return;
    EmitOpcode_real(OP_breakpoint, 0, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
}

/* --- EmitProfStatement --- */
static void EmitProfStatement_real(sval_t profileName, sval_t sourcePos, unsigned char op)
{
    if (!SCRVP->developer_script) {
        Scr_CompileRemoveRefToString_new(profileName.stringValue);
        return;
    }
    Scr_CompileRemoveRefToString_new(profileName.stringValue);
    EmitOpcode_real(op, 0, CALL_NONE);
    EmitByte_new(0);
}

/* --- EmitProfBeginStatement --- */
static void EmitProfBeginStatement_real(sval_t profileName, sval_t sourcePos)
{
    EmitProfStatement_real(profileName, sourcePos, OP_prof_begin);
}

/* --- EmitProfEndStatement --- */
static void EmitProfEndStatement_real(sval_t profileName, sval_t sourcePos)
{
    EmitProfStatement_real(profileName, sourcePos, OP_prof_end);
}

/* --- EmitWaittillFrameEnd --- */
static void EmitWaittillFrameEnd_real(sval_t sourcePos)
{
    EmitOpcode_real(OP_waittillFrameEnd, 0, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
}

/* --- EmitAssignmentStatement --- */
static void EmitAssignmentStatement_real(sval_t lhs, sval_t rhs, sval_t sourcePos, sval_t rhsSourcePos, scr_block_t *block)
{
    if (IsUndefinedExpression_real(rhs)) {
        if (EmitClearVariableExpression_real(lhs, rhsSourcePos, block))
            return;
    }
    EmitExpression_real(rhs, block);
    EmitVariableExpressionRef_real(lhs, block);
    EmitSetVariableField_real(sourcePos);
}

/* --- EmitReturnStatement --- */
static void EmitReturnStatement_real(sval_t expr, sval_t sourcePos, scr_block_t *block)
{
    if (block->abortLevel == SCR_ABORT_NONE)
        block->abortLevel = SCR_ABORT_RETURN;
    EmitExpression_real(expr, block);
    EmitReturn_real();
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
}

/* --- EmitEndStatement --- */
static void EmitEndStatement_real(sval_t sourcePos, scr_block_t *block)
{
    if (block->abortLevel == SCR_ABORT_NONE)
        block->abortLevel = SCR_ABORT_RETURN;
    EmitEnd_real();
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
}

/* --- EmitWaitStatement --- */
static void EmitWaitStatement_real(sval_t expr, sval_t sourcePos, sval_t waitSourcePos, scr_block_t *block)
{
    EmitExpression_real(expr, block);
    EmitOpcode_real(OP_wait, -1, CALL_NONE);
    AddOpcodePos(waitSourcePos.sourcePosValue, SOURCE_TYPE_NONE);
    AddOpcodePos(waitSourcePos.sourcePosValue, SOURCE_TYPE_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
}

/* --- EmitWaittillStatement --- */
static void EmitWaittillStatement_real(sval_t obj, sval_t exprlist, sval_t sourcePos, sval_t waitSourcePos, scr_block_t *block)
{
    sval_t *node = (sval_t *)((sval_t *)((sval_t *)exprlist.node)[0].node)[1].node;
    EmitExpression_real(((sval_t *)node[0].node)[0], block);
    EmitPrimitiveExpression_real(obj, block);
    EmitOpcode_real(OP_waittill, -2, CALL_NONE);
    AddOpcodePos(waitSourcePos.sourcePosValue, SOURCE_TYPE_NONE);
    AddOpcodePos(waitSourcePos.sourcePosValue, SOURCE_TYPE_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
    AddOpcodePos(((sval_t *)node[0].node)[1].sourcePosValue, SOURCE_TYPE_NONE);
    EmitFormalWaittillParameterListRefInternal_real(node, block);
    EmitOpcode_real(OP_clearparams, 0, CALL_NONE);
}

/* --- EmitWaittillmatchStatement --- */
static void EmitWaittillmatchStatement_real(sval_t obj, sval_t exprlist, sval_t sourcePos, sval_t waitSourcePos, scr_block_t *block)
{
    sval_t *node;
    int exprCount;

    node = (sval_t *)((sval_t *)((sval_t *)exprlist.node)[0].node)[1].node;

    for (exprCount = 0; ; exprCount++) {
        node = (sval_t *)node[1].node;
        if (!node)
            break;
        EmitExpression_real(((sval_t *)node[0].node)[0], block);
    }

    node = (sval_t *)((sval_t *)((sval_t *)exprlist.node)[0].node)[1].node;

    EmitExpression_real(((sval_t *)node[0].node)[0], block);
    EmitPrimitiveExpression_real(obj, block);

    EmitOpcode_real(OP_waittillmatch, -2 - exprCount, CALL_NONE);
    AddOpcodePos(waitSourcePos.sourcePosValue, SOURCE_TYPE_NONE);
    AddOpcodePos(waitSourcePos.sourcePosValue, SOURCE_TYPE_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
    AddOpcodePos(((sval_t *)node[0].node)[1].sourcePosValue, SOURCE_TYPE_NONE);

    while (1) {
        node = (sval_t *)node[1].node;
        if (!node)
            break;
        AddOpcodePos(((sval_t *)node[0].node)[1].sourcePosValue, SOURCE_TYPE_NONE);
    }

    EmitByte_new(exprCount);
    EmitOpcode_real(OP_clearparams, 0, CALL_NONE);
}

/* --- EmitNotifyStatement --- */
static void EmitNotifyStatement_real(sval_t obj, sval_t exprlist, sval_t sourcePos, sval_t notifySourcePos, scr_block_t *block)
{
    sval_t *node, *start_node;
    int expr_count;

    EmitOpcode_real(OP_voidCodepos, 1, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);

    expr_count = 0;
    start_node = NULL;
    for (node = (sval_t *)((sval_t *)exprlist.node)[0].node; node; node = (sval_t *)node[1].node) {
        start_node = node;
        EmitExpression_real(((sval_t *)node[0].node)[0], block);
        expr_count++;
    }

    EmitPrimitiveExpression_real(obj, block);
    EmitOpcode_real(OP_notify, -expr_count - 2, CALL_NONE);
    AddOpcodePos(notifySourcePos.sourcePosValue, SOURCE_TYPE_NONE);
    AddOpcodePos(((sval_t *)start_node[0].node)[1].sourcePosValue, SOURCE_TYPE_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
}

/* --- EmitEndOnStatement --- */
static void EmitEndOnStatement_real(sval_t obj, sval_t expr, sval_t sourcePos, sval_t exprSourcePos, scr_block_t *block)
{
    EmitExpression_real(expr, block);
    EmitPrimitiveExpression_real(obj, block);
    EmitOpcode_real(OP_endon, -2, CALL_NONE);
    AddOpcodePos(exprSourcePos.sourcePosValue, SOURCE_TYPE_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
}

/* --- EmitBreakStatement --- */
static void EmitBreakStatement_real(sval_t sourcePos, scr_block_t *block)
{
    BreakStatementInfo *newBreakStatement;

    if (!SCRCG->bCanBreak || block->abortLevel != SCR_ABORT_NONE) {
        CompileError(sourcePos.sourcePosValue, "illegal break statement");
        return;
    }

    Scr_AddBreakBlock_real(block);
    EmitRemoveLocalVars_real(block, SCRCG->breakBlock);

    block->abortLevel = SCR_ABORT_BREAK;

    EmitOpcode_real(OP_jump, 0, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
    EmitCodepos_real(0);

    newBreakStatement = (BreakStatementInfo *)Hunk_AllocateTempMemoryHighInternal(sizeof(*newBreakStatement));
    newBreakStatement->codePos = (char *)SCRCG->codePos;
    newBreakStatement->nextCodePos = (char *)TempMalloc(0);
    newBreakStatement->next = (int)(intptr_t)SCRCG->currentBreakStatement;
    SCRCG->currentBreakStatement = newBreakStatement;
}

/* --- EmitContinueStatement --- */
static void EmitContinueStatement_real(sval_t sourcePos, scr_block_t *block)
{
    ContinueStatementInfo *newContinueStatement;

    if (!SCRCG->bCanContinue || block->abortLevel != SCR_ABORT_NONE) {
        CompileError(sourcePos.stringValue, "illegal continue statement");
        return;
    }

    Scr_AddContinueBlock_real(block);
    EmitRemoveLocalVars_real(block, block);

    block->abortLevel = SCR_ABORT_CONTINUE;

    EmitOpcode_real(OP_jump, 0, CALL_NONE);
    AddOpcodePos(sourcePos.stringValue, SOURCE_TYPE_BREAKPOINT);
    EmitCodepos_real(0);

    newContinueStatement = (ContinueStatementInfo *)Hunk_AllocateTempMemoryHighInternal(sizeof(*newContinueStatement));
    newContinueStatement->codePos = (char *)SCRCG->codePos;
    newContinueStatement->nextCodePos = (char *)TempMalloc(0);
    newContinueStatement->next = (int)(intptr_t)SCRCG->currentContinueStatement;
    SCRCG->currentContinueStatement = newContinueStatement;
}

/* --- EmitIncStatement --- */
static void EmitIncStatement_real(sval_t expr, sval_t sourcePos, scr_block_t *block)
{
    SCRCG->forceNotCreate = 1;
    EmitVariableExpressionRef_real(expr, block);
    SCRCG->forceNotCreate = 0;
    EmitOpcode_real(OP_inc, 1, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
    EmitSetVariableField_real(sourcePos);
}

/* --- EmitDecStatement --- */
static void EmitDecStatement_real(sval_t expr, sval_t sourcePos, scr_block_t *block)
{
    SCRCG->forceNotCreate = 1;
    EmitVariableExpressionRef_real(expr, block);
    SCRCG->forceNotCreate = 0;
    EmitOpcode_real(OP_dec, 1, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
    EmitSetVariableField_real(sourcePos);
}

/* --- EmitBinaryEqualsOperatorExpression --- */
static void EmitBinaryEqualsOperatorExpression_real(sval_t lhs, sval_t rhs, sval_t opcode, sval_t sourcePos, scr_block_t *block)
{
    SCRCG->bConstRefCount = 1;
    EmitVariableExpression_real(lhs, block);
    SCRCG->bConstRefCount = 0;
    EmitExpression_real(rhs, block);
    EmitOpcode_real(opcode.type, -1, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
    EmitVariableExpressionRef_real(lhs, block);
    EmitSetVariableField_real(sourcePos);
}

/* --- EmitDeveloperStatementList --- */
static void EmitDeveloperStatementList_real(sval_t val, sval_t sourcePos, scr_block_t *block, sval_t *devStatBlock)
{
    char *savedPos;
    unsigned int savedChecksum;

    if (SCRCP->developer_statement != SCR_DEV_NO) {
        CompileError(sourcePos.sourcePosValue, "cannot recurse /#");
        return;
    }

    savedChecksum = SCRVP->checksum;
    Scr_TransferBlock_real(block, devStatBlock->block);

    if (SCRVP->developer_script) {
        SCRCP->developer_statement = SCR_DEV_YES;
        EmitStatementList_new(val, 0, 0, devStatBlock->block);
        EmitRemoveLocalVars_real(devStatBlock->block, devStatBlock->block);
    } else {
        savedPos = (char *)TempMalloc(0);
        SCRCP->developer_statement = SCR_DEV_IGNORE;
        EmitStatementList_new(val, 0, 0, devStatBlock->block);
        TempMemorySetPos(savedPos);
    }

    SCRCP->developer_statement = SCR_DEV_NO;
    SCRVP->checksum = savedChecksum;
}

/* --- EmitIfStatement --- */
static void EmitIfStatement_real(sval_t expr, sval_t stmt, sval_t sourcePos, int lastStatement, unsigned int endSourcePos, scr_block_t *block, sval_t *ifStatBlock)
{
    const char *pos, *nextPos;
    unsigned int offset;

    EmitExpression_real(expr, block);
    EmitOpcode_real(OP_JumpOnFalse, -1, CALL_NONE);
    AddOpcodePos(sourcePos.stringValue, SOURCE_TYPE_NONE);
    EmitUnsignedShort_real(0);

    pos = (const char *)SCRCG->codePos;
    nextPos = TempMallocAlignStrict(0);

    Scr_TransferBlock_real(block, ifStatBlock->block);

    EmitStatement_real(stmt, lastStatement, endSourcePos, ifStatBlock->block);
    EmitNOP2_real(lastStatement, endSourcePos, ifStatBlock->block);

    offset = TempMallocAlignStrict(0) - nextPos;
    *(unsigned short *)pos = offset;
}

/* --- EmitIfElseStatement --- */
static void EmitIfElseStatement_real(sval_t expr, sval_t stmt1, sval_t stmt2, sval_t sourcePos, sval_t elseSourcePos, int lastStatement, unsigned int endSourcePos, scr_block_t *block, sval_t *ifStatBlock, sval_t *elseStatBlock)
{
    int childCount, checksum;
    scr_block_t *childBlocks[2];
    const char *pos1, *pos2, *nextPos1, *nextPos2;
    unsigned int offset;

    childCount = 0;

    EmitExpression_real(expr, block);
    EmitOpcode_real(OP_JumpOnFalse, -1, CALL_NONE);
    AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
    EmitUnsignedShort_real(0);

    pos1 = (const char *)SCRCG->codePos;
    nextPos1 = (const char *)TempMalloc(0);

    Scr_TransferBlock_real(block, ifStatBlock->block);
    EmitStatement_real(stmt1, lastStatement, endSourcePos, ifStatBlock->block);
    EmitRemoveLocalVars_real(ifStatBlock->block, ifStatBlock->block);

    if (ifStatBlock->block->abortLevel == SCR_ABORT_NONE) {
        childBlocks[0] = ifStatBlock->block;
        childCount = 1;
    }

    checksum = SCRVP->checksum;

    if (lastStatement) {
        EmitEnd_real();
        EmitCodepos_real(0);
        AddOpcodePos(endSourcePos, SOURCE_TYPE_BREAKPOINT);
        pos2 = NULL;
        nextPos2 = NULL;
    } else {
        EmitOpcode_real(OP_jump, 0, CALL_NONE);
        AddOpcodePos(elseSourcePos.sourcePosValue, SOURCE_TYPE_BREAKPOINT);
        EmitCodepos_real(0);
        pos2 = (const char *)SCRCG->codePos;
        nextPos2 = (const char *)TempMalloc(0);
    }

    SCRVP->checksum = checksum + 1;

    offset = TempMallocAlignStrict(0) - nextPos1;
    *(unsigned short *)pos1 = offset;

    Scr_TransferBlock_real(block, elseStatBlock->block);
    EmitStatement_real(stmt2, lastStatement, endSourcePos, elseStatBlock->block);
    EmitNOP2_real(lastStatement, endSourcePos, elseStatBlock->block);

    if (elseStatBlock->block->abortLevel == SCR_ABORT_NONE) {
        childBlocks[childCount] = elseStatBlock->block;
        childCount++;
    }

    if (!lastStatement) {
        offset = TempMallocAlignStrict(0) - nextPos2;
        *(int *)pos2 = offset;
    }

    Scr_InitFromChildBlocks_real(childBlocks, childCount, block);
}

/* --- EmitSwitchStatementList --- */
static void EmitSwitchStatementList_real(sval_t val, int lastStatement, unsigned int endSourcePos, scr_block_t *block)
{
    scr_block_t *oldBreakBlock;
    int *oldBreakChildCount;
    scr_block_t **oldBreakChildBlocks;
    int breakChildCount;
    scr_block_t **breakChildBlocks;
    int hasDefault;
    sval_t *node, *nextNode;

    oldBreakChildBlocks = SCRCG->breakChildBlocks;
    oldBreakChildCount = SCRCG->breakChildCount;
    oldBreakBlock = SCRCG->breakBlock;

    breakChildCount = 0;
    breakChildBlocks = (scr_block_t **)Hunk_AllocateTempMemoryHighInternal(sizeof(scr_block_t *) * MAX_SWITCH_CASES);

    SCRCG->breakChildBlocks = breakChildBlocks;
    SCRCG->breakChildCount = &breakChildCount;

    SCRCG->breakBlock = NULL;
    hasDefault = 0;

    for (node = (sval_t *)((sval_t *)((sval_t *)val.node)[0].node)[1].node; node; node = nextNode) {
        nextNode = (sval_t *)node[1].node;

        if (((sval_t *)node[0].node)[0].type == ENUM_case || ((sval_t *)node[0].node)[0].type == ENUM_default) {
            if (SCRCG->breakBlock) {
                SCRCG->bCanBreak = 0;
                EmitRemoveLocalVars_real(SCRCG->breakBlock, SCRCG->breakBlock);
            }
            if (((sval_t *)node[0].node)[0].type == ENUM_case) {
                SCRCG->breakBlock = ((sval_t *)node[0].node)[3].block;
                EmitCaseStatement_real(((sval_t *)node[0].node)[1], ((sval_t *)node[0].node)[2]);
            } else {
                SCRCG->breakBlock = ((sval_t *)node[0].node)[2].block;
                hasDefault = 1;
                EmitDefaultStatement_real(((sval_t *)node[0].node)[1]);
            }
            Scr_TransferBlock_real(block, SCRCG->breakBlock);
            SCRCG->bCanBreak = 1;
        } else {
            if (!SCRCG->breakBlock) {
                CompileError(endSourcePos, "missing case statement");
                return;
            }
            if (lastStatement && Scr_IsLastStatement_real(nextNode))
                EmitStatement_real(node[0], 1, endSourcePos, SCRCG->breakBlock);
            else
                EmitStatement_real(node[0], 0, endSourcePos, SCRCG->breakBlock);

            if (SCRCG->breakBlock && SCRCG->breakBlock->abortLevel) {
                SCRCG->breakBlock = NULL;
                SCRCG->bCanBreak = 0;
            }
        }
    }

    if (SCRCG->breakBlock) {
        SCRCG->bCanBreak = 0;
        EmitRemoveLocalVars_real(SCRCG->breakBlock, SCRCG->breakBlock);
    }

    if (hasDefault) {
        if (SCRCG->breakBlock)
            Scr_AddBreakBlock_real(SCRCG->breakBlock);
        Scr_InitFromChildBlocks_real(breakChildBlocks, breakChildCount, block);
    }

    SCRCG->breakChildBlocks = oldBreakChildBlocks;
    SCRCG->breakChildCount = oldBreakChildCount;
    SCRCG->breakBlock = oldBreakBlock;
}

/* --- EmitSwitchStatement --- */
static void EmitSwitchStatement_real(sval_t expr, sval_t stmtlist, sval_t sourcePos, int lastStatement, unsigned int endSourcePos, scr_block_t *block)
{
    int num;
    const char *nextPos1, *pos1, *pos2;
    char *pos3;
    BreakStatementInfo *oldBreakStatement;
    int oldbCanIgnoreBreak, oldbCanBreak, oldbCanIgnoreCase;
    CaseStatementInfo *caseStatement, *oldCaseStatement;

    oldbCanIgnoreCase = SCRCG->bCanIgnoreCase;
    oldCaseStatement = SCRCG->currentCaseStatement;
    SCRCG->bCanIgnoreCase = 0;
    oldbCanBreak = SCRCG->bCanBreak;
    oldbCanIgnoreBreak = SCRCG->bCanIgnoreBreak;
    oldBreakStatement = SCRCG->currentBreakStatement;
    SCRCG->bCanBreak = 0;
    SCRCG->bCanIgnoreBreak = 0;

    EmitExpression_real(expr, block);
    EmitOpcode_real(OP_switch, -1, CALL_NONE);
    EmitCodepos_real(0);

    pos1 = (const char *)SCRCG->codePos;
    nextPos1 = (const char *)TempMalloc(0);

    SCRCG->bCanIgnoreCase = SCRCP->developer_statement != SCR_DEV_NO;
    SCRCG->currentCaseStatement = NULL;
    SCRCG->bCanIgnoreBreak = SCRCP->developer_statement != SCR_DEV_NO;
    SCRCG->currentBreakStatement = NULL;

    EmitSwitchStatementList_real(stmtlist, lastStatement, endSourcePos, block);

    SCRCG->bCanIgnoreCase = 0;
    SCRCG->bCanIgnoreBreak = 0;

    EmitOpcode_real(OP_endswitch, 0, CALL_NONE);
    AddOpcodePos(sourcePos.stringValue, SOURCE_TYPE_NONE);
    EmitShort_real(0);

    pos2 = (const char *)SCRCG->codePos;
    *(int *)pos1 = (int)((byte *)SCRCG->codePos - (byte *)nextPos1);
    pos3 = TempMallocAlignStrict(0);

    for (num = 0, caseStatement = SCRCG->currentCaseStatement; caseStatement; caseStatement = (CaseStatementInfo *)(intptr_t)caseStatement->next, num++) {
        EmitCodepos_real((const char *)(intptr_t)caseStatement->name);
        EmitCodepos_real(caseStatement->codePos);
    }

    *(unsigned short *)pos2 = num;
    qsort(pos3, num, 8, (int (*)(const void *, const void *))CompareCaseInfo);

    while (num > 1) {
        if (*(int *)pos3 == *((int *)pos3 + 2)) {
            for (caseStatement = SCRCG->currentCaseStatement; caseStatement; caseStatement = (CaseStatementInfo *)(intptr_t)caseStatement->next) {
                if (caseStatement->name == (unsigned int)(*(int *)pos3)) {
                    CompileError(caseStatement->sourcePos, "duplicate case expression");
                    return;
                }
            }
        }
        --num;
        pos3 += 8;
    }

    ConnectBreakStatements_real();

    SCRCG->bCanIgnoreCase = oldbCanIgnoreCase;
    SCRCG->currentCaseStatement = oldCaseStatement;
    SCRCG->bCanBreak = oldbCanBreak;
    SCRCG->bCanIgnoreBreak = oldbCanIgnoreBreak;
    SCRCG->currentBreakStatement = oldBreakStatement;
}

/* --- EmitWhileStatement --- */
static void EmitWhileStatement_real(sval_t expr, sval_t stmt, sval_t sourcePos, sval_t whileSourcePos, scr_block_t *block, sval_t *whileStatBlock)
{
    scr_block_t *oldBreakBlock, **oldContinueChildBlocks, **breakChildBlocks, **oldBreakChildBlocks;
    int *oldContinueChildCount, *oldBreakChildCount;
    int breakChildCount;
    VariableCompileValue constValue;
    int constConditional, bOldCanIgnoreContinue, bOldCanContinue, bOldCanIgnoreBreak, bOldCanBreak;
    ContinueStatementInfo *oldContinueStatement;
    BreakStatementInfo *oldBreakStatement;
    const char *pos1, *pos2, *nextPos2;
    unsigned int offset;

    bOldCanBreak = SCRCG->bCanBreak;
    bOldCanIgnoreBreak = SCRCG->bCanIgnoreBreak;
    oldBreakStatement = SCRCG->currentBreakStatement;
    SCRCG->bCanBreak = 0;
    SCRCG->bCanIgnoreBreak = 0;

    bOldCanContinue = SCRCG->bCanContinue;
    bOldCanIgnoreContinue = SCRCG->bCanIgnoreContinue;
    oldContinueStatement = SCRCG->currentContinueStatement;
    SCRCG->bCanContinue = 0;
    SCRCG->bCanIgnoreContinue = 0;

    Scr_TransferBlock_real(block, whileStatBlock->block);
    EmitCreateLocalVars_real(whileStatBlock->block);
    block->localVarsCreateCount = whileStatBlock->block->localVarsCreateCount;

    pos1 = (const char *)TempMalloc(0);
    constConditional = 0;

    if (EmitOrEvalExpression_real(expr, &constValue, block)) {
        if (constValue.value.type == 6 || constValue.value.type == 8) { /* VAR_INTEGER, VAR_FLOAT */
            Scr_CastBool(&constValue.value);
            if (!constValue.value.u.intValue)
                CompileError(sourcePos.sourcePosValue, "conditional expression cannot be always false");
            constConditional = 1;
        } else {
            EmitValue_real(&constValue);
        }
    }

    oldBreakChildBlocks = SCRCG->breakChildBlocks;
    oldBreakChildCount = SCRCG->breakChildCount;
    oldBreakBlock = SCRCG->breakBlock;
    oldContinueChildBlocks = SCRCG->continueChildBlocks;
    oldContinueChildCount = SCRCG->continueChildCount;

    breakChildCount = 0;
    SCRCG->continueChildBlocks = 0;
    SCRCG->breakBlock = whileStatBlock->block;

    if (constConditional) {
        pos2 = NULL;
        nextPos2 = NULL;
        breakChildBlocks = (scr_block_t **)Hunk_AllocateTempMemoryHighInternal(sizeof(scr_block_t *) * MAX_SWITCH_CASES);
        SCRCG->breakChildCount = &breakChildCount;
    } else {
        EmitOpcode_real(OP_JumpOnFalse, -1, CALL_NONE);
        AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
        EmitUnsignedShort_real(0);
        pos2 = (const char *)SCRCG->codePos;
        nextPos2 = (const char *)TempMalloc(0);
        breakChildBlocks = NULL;
    }

    SCRCG->breakChildBlocks = breakChildBlocks;
    SCRCG->bCanBreak = 1;
    SCRCG->bCanIgnoreBreak = SCRCP->developer_statement != SCR_DEV_NO;
    SCRCG->currentBreakStatement = 0;
    SCRCG->bCanContinue = 1;
    SCRCG->bCanIgnoreContinue = SCRCP->developer_statement != SCR_DEV_NO;
    SCRCG->currentContinueStatement = 0;

    EmitStatement_real(stmt, 0, 0, whileStatBlock->block);

    if (whileStatBlock->block->abortLevel != SCR_ABORT_RETURN)
        whileStatBlock->block->abortLevel = SCR_ABORT_NONE;

    SCRCG->bCanBreak = 0;
    SCRCG->bCanIgnoreBreak = 0;
    SCRCG->bCanContinue = 0;
    SCRCG->bCanIgnoreContinue = 0;

    ConnectContinueStatements_real();

    EmitOpcode_real(OP_jumpback, 0, CALL_NONE);
    AddOpcodePos(whileSourcePos.sourcePosValue, SOURCE_TYPE_NONE);

    if (((sval_t *)stmt.node)[0].type == ENUM_statement_list)
        AddOpcodePos(((sval_t *)stmt.node)[3].sourcePosValue, SOURCE_TYPE_BREAKPOINT);

    EmitUnsignedShort_real(0);

    offset = TempMallocAlignStrict(0) - pos1;
    *(unsigned short *)SCRCG->codePos = offset;

    if (pos2) {
        offset = TempMallocAlignStrict(0) - nextPos2;
        *(unsigned short *)pos2 = offset;
    }

    ConnectBreakStatements_real();

    SCRCG->bCanBreak = bOldCanBreak;
    SCRCG->bCanIgnoreBreak = bOldCanIgnoreBreak;
    SCRCG->currentBreakStatement = oldBreakStatement;
    SCRCG->bCanContinue = bOldCanContinue;
    SCRCG->bCanIgnoreContinue = bOldCanIgnoreContinue;
    SCRCG->currentContinueStatement = oldContinueStatement;

    if (constConditional)
        Scr_InitFromChildBlocks_real(breakChildBlocks, breakChildCount, block);

    SCRCG->breakChildBlocks = oldBreakChildBlocks;
    SCRCG->breakChildCount = oldBreakChildCount;
    SCRCG->breakBlock = oldBreakBlock;
    SCRCG->continueChildBlocks = oldContinueChildBlocks;
    SCRCG->continueChildCount = oldContinueChildCount;
}

/* --- EmitForStatement --- */
static void EmitForStatement_real(sval_t stmt1, sval_t expr, sval_t stmt2, sval_t stmt, sval_t sourcePos, sval_t forSourcePos, scr_block_t *block, sval_t *forStatBlock, sval_t *forStatPostBlock)
{
    scr_block_t *oldBreakBlock, **oldContinueChildBlocks, **continueChildBlocks, **breakChildBlocks, **oldBreakChildBlocks;
    int *oldContinueChildCount, *oldBreakChildCount;
    int continueChildCount, breakChildCount;
    VariableCompileValue constValue;
    int constConditional, bOldCanIgnoreContinue, bOldCanContinue, bOldCanIgnoreBreak, bOldCanBreak;
    ContinueStatementInfo *oldContinueStatement;
    BreakStatementInfo *oldBreakStatement;
    const char *pos1, *pos2, *nextPos2;
    unsigned int offset;

    bOldCanBreak = SCRCG->bCanBreak;
    bOldCanIgnoreBreak = SCRCG->bCanIgnoreBreak;
    oldBreakStatement = SCRCG->currentBreakStatement;
    SCRCG->bCanBreak = 0;
    SCRCG->bCanIgnoreBreak = 0;

    bOldCanContinue = SCRCG->bCanContinue;
    bOldCanIgnoreContinue = SCRCG->bCanIgnoreContinue;
    oldContinueStatement = SCRCG->currentContinueStatement;
    SCRCG->bCanContinue = 0;
    SCRCG->bCanIgnoreContinue = 0;

    EmitStatement_real(stmt1, 0, 0, block);
    Scr_TransferBlock_real(block, forStatBlock->block);
    EmitCreateLocalVars_real(forStatBlock->block);
    block->localVarsCreateCount = forStatBlock->block->localVarsCreateCount;
    Scr_TransferBlock_real(block, forStatPostBlock->block);

    pos1 = (const char *)TempMalloc(0);

    if (((sval_t *)expr.node)[0].type == ENUM_expression) {
        constConditional = 0;
        if (EmitOrEvalExpression_real(((sval_t *)expr.node)[1], &constValue, block)) {
            if (constValue.value.type == 6 || constValue.value.type == 8) {
                Scr_CastBool(&constValue.value);
                if (!constValue.value.u.intValue)
                    CompileError(sourcePos.sourcePosValue, "conditional expression cannot be always false");
                constConditional = 1;
            } else {
                EmitValue_real(&constValue);
            }
        }
    } else {
        constConditional = 1;
    }

    oldBreakChildBlocks = SCRCG->breakChildBlocks;
    oldBreakChildCount = SCRCG->breakChildCount;
    oldBreakBlock = SCRCG->breakBlock;
    oldContinueChildBlocks = SCRCG->continueChildBlocks;
    oldContinueChildCount = SCRCG->continueChildCount;

    breakChildCount = 0;
    continueChildCount = 0;

    continueChildBlocks = (scr_block_t **)Hunk_AllocateTempMemoryHighInternal(sizeof(scr_block_t *) * MAX_SWITCH_CASES);
    SCRCG->continueChildBlocks = continueChildBlocks;
    SCRCG->continueChildCount = &continueChildCount;

    SCRCG->breakBlock = forStatBlock->block;

    if (constConditional) {
        pos2 = NULL;
        nextPos2 = NULL;
        breakChildBlocks = (scr_block_t **)Hunk_AllocateTempMemoryHighInternal(sizeof(scr_block_t *) * MAX_SWITCH_CASES);
        SCRCG->breakChildCount = &breakChildCount;
    } else {
        EmitOpcode_real(OP_JumpOnFalse, -1, CALL_NONE);
        AddOpcodePos(sourcePos.sourcePosValue, SOURCE_TYPE_NONE);
        EmitUnsignedShort_real(0);
        pos2 = (const char *)SCRCG->codePos;
        nextPos2 = (const char *)TempMalloc(0);
        breakChildBlocks = NULL;
    }

    SCRCG->breakChildBlocks = breakChildBlocks;
    SCRCG->bCanBreak = 1;
    SCRCG->bCanIgnoreBreak = SCRCP->developer_statement != SCR_DEV_NO;
    SCRCG->currentBreakStatement = 0;
    SCRCG->bCanContinue = 1;
    SCRCG->bCanIgnoreContinue = SCRCP->developer_statement != SCR_DEV_NO;
    SCRCG->currentContinueStatement = 0;

    EmitStatement_real(stmt, 0, 0, forStatBlock->block);
    Scr_AddContinueBlock_real(forStatBlock->block);

    SCRCG->bCanBreak = 0;
    SCRCG->bCanIgnoreBreak = 0;
    SCRCG->bCanContinue = 0;
    SCRCG->bCanIgnoreContinue = 0;

    ConnectContinueStatements_real();
    Scr_InitFromChildBlocks_real(continueChildBlocks, continueChildCount, forStatPostBlock->block);

    EmitStatement_real(stmt2, 0, 0, forStatPostBlock->block);
    EmitOpcode_real(OP_jumpback, 0, CALL_NONE);
    AddOpcodePos(forSourcePos.stringValue, SOURCE_TYPE_NONE);

    if (((sval_t *)stmt.node)[0].type == ENUM_statement_list)
        AddOpcodePos(((sval_t *)stmt.node)[3].sourcePosValue, SOURCE_TYPE_BREAKPOINT);

    EmitUnsignedShort_real(0);

    offset = TempMallocAlignStrict(0) - pos1;
    *(unsigned short *)SCRCG->codePos = offset;

    if (pos2) {
        offset = TempMallocAlignStrict(0) - nextPos2;
        *(unsigned short *)pos2 = offset;
    }

    ConnectBreakStatements_real();

    SCRCG->bCanBreak = bOldCanBreak;
    SCRCG->bCanIgnoreBreak = bOldCanIgnoreBreak;
    SCRCG->currentBreakStatement = oldBreakStatement;
    SCRCG->bCanContinue = bOldCanContinue;
    SCRCG->bCanIgnoreContinue = bOldCanIgnoreContinue;
    SCRCG->currentContinueStatement = oldContinueStatement;

    if (constConditional)
        Scr_InitFromChildBlocks_real(breakChildBlocks, breakChildCount, block);

    SCRCG->breakChildBlocks = oldBreakChildBlocks;
    SCRCG->breakChildCount = oldBreakChildCount;
    SCRCG->breakBlock = oldBreakBlock;
    SCRCG->continueChildBlocks = oldContinueChildBlocks;
    SCRCG->continueChildCount = oldContinueChildCount;
}

/* --- EmitStatement --- */
static void EmitStatement_real(sval_t val, int lastStatement, unsigned int endSourcePos, scr_block_t *block)
{
    sval_t *n = (sval_t *)val.node;
    switch (n[0].type) {
    case ENUM_assignment:
        EmitAssignmentStatement_real(n[1], n[2], n[3], n[4], block);
        break;
    case ENUM_call_expression_statement:
        EmitCallExpressionStatement_real(n[1], block);
        break;
    case ENUM_return:
        EmitReturnStatement_real(n[1], n[2], block);
        break;
    case ENUM_return2:
        EmitEndStatement_real(n[1], block);
        break;
    case ENUM_wait:
        EmitWaitStatement_real(n[1], n[2], n[3], block);
        break;
    case ENUM_if:
        EmitIfStatement_real(n[1], n[2], n[3], lastStatement, endSourcePos, block, &n[4]);
        break;
    case ENUM_if_else:
        EmitIfElseStatement_real(n[1], n[2], n[3], n[4], n[5], lastStatement, endSourcePos, block, &n[6], &n[7]);
        break;
    case ENUM_while:
        EmitWhileStatement_real(n[1], n[2], n[3], n[4], block, &n[5]);
        break;
    case ENUM_for:
        EmitForStatement_real(n[1], n[2], n[3], n[4], n[5], n[6], block, &n[7], &n[8]);
        break;
    case ENUM_inc:
        EmitIncStatement_real(n[1], n[2], block);
        break;
    case ENUM_dec:
        EmitDecStatement_real(n[1], n[2], block);
        break;
    case ENUM_binary_equals:
        EmitBinaryEqualsOperatorExpression_real(n[1], n[2], n[3], n[4], block);
        break;
    case ENUM_statement_list:
        EmitStatementList_new(n[1], lastStatement, endSourcePos, block);
        break;
    case ENUM_developer_statement_list:
        EmitDeveloperStatementList_real(n[1], n[2], block, &n[3]);
        break;
    case ENUM_waittill:
        EmitWaittillStatement_real(n[1], n[2], n[3], n[4], block);
        break;
    case ENUM_waittillmatch:
        EmitWaittillmatchStatement_real(n[1], n[2], n[3], n[4], block);
        break;
    case ENUM_waittillFrameEnd:
        EmitWaittillFrameEnd_real(n[1]);
        break;
    case ENUM_notify:
        EmitNotifyStatement_real(n[1], n[2], n[3], n[4], block);
        break;
    case ENUM_endon:
        EmitEndOnStatement_real(n[1], n[2], n[3], n[4], block);
        break;
    case ENUM_switch:
        EmitSwitchStatement_real(n[1], n[2], n[3], lastStatement, endSourcePos, block);
        break;
    case ENUM_case:
        CompileError(n[2].sourcePosValue, "illegal case statement");
        break;
    case ENUM_default:
        CompileError(n[1].sourcePosValue, "illegal default statement");
        break;
    case ENUM_break:
        EmitBreakStatement_real(n[1], block);
        break;
    case ENUM_continue:
        EmitContinueStatement_real(n[1], block);
        break;
    case ENUM_breakpoint:
        EmitBreakpointStatement_real(n[1]);
        break;
    case ENUM_prof_begin:
        EmitProfBeginStatement_real(n[1], n[2]);
        break;
    case ENUM_prof_end:
        EmitProfEndStatement_real(n[1], n[2]);
        break;
    default:
        return;
    }
}

/* --- EmitStatementList --- */
static void EmitStatementList_new(sval_t val, int lastStatement, unsigned int endSourcePos, scr_block_t *block)
{
    sval_t *node, *next_node;
    for (next_node = (sval_t *)((sval_t *)((sval_t *)val.node)[0].node)[1].node; next_node; next_node = node) {
        node = (sval_t *)next_node[1].node;
        if (lastStatement && Scr_IsLastStatement_real(node))
            EmitStatement_real(next_node[0], 1, endSourcePos, block);
        else
            EmitStatement_real(next_node[0], 0, endSourcePos, block);
    }
}

/* ============================================================
 * Scr_CalcLocalVars functions for proper block analysis
 * ============================================================ */

static void Scr_CalcLocalVarsVariableExpressionRef_real(sval_t expr, scr_block_t *block);

static void Scr_CalcLocalVarsSafeSetVariableField_real(sval_t expr, sval_t sourcePos, scr_block_t *block)
{
    Scr_RegisterLocalVar_real(expr.idValue, sourcePos, block);
}

static void Scr_CalcLocalVarsArrayPrimitiveExpressionRef_real(sval_t expr, scr_block_t *block);

static void Scr_CalcLocalVarsArrayVariableRef_real(sval_t expr, scr_block_t *block)
{
    Scr_CalcLocalVarsArrayPrimitiveExpressionRef_real(expr, block);
}

static void Scr_CalcLocalVarsArrayPrimitiveExpressionRef_real(sval_t expr, scr_block_t *block)
{
    if (((sval_t *)expr.node)[0].type != ENUM_variable)
        return;
    Scr_CalcLocalVarsVariableExpressionRef_real(((sval_t *)expr.node)[1], block);
}

static void Scr_CalcLocalVarsVariableExpressionRef_real(sval_t expr, scr_block_t *block)
{
    sval_t *n = (sval_t *)expr.node;
    if (n[0].type == ENUM_local_variable)
        Scr_CalcLocalVarsSafeSetVariableField_real(n[1], n[2], block);
    else if (n[0].type == ENUM_array_variable)
        Scr_CalcLocalVarsArrayVariableRef_real(n[1], block);
}

static void Scr_CalcLocalVarsAssignmentStatement_real(sval_t lhs, sval_t rhs, scr_block_t *block)
{
    Scr_CalcLocalVarsVariableExpressionRef_real(lhs, block);
}

static void Scr_CalcLocalVarsIncStatement_real(sval_t expr, scr_block_t *block)
{
    Scr_CalcLocalVarsVariableExpressionRef_real(expr, block);
}

static void Scr_CalcLocalVarsFormalParameterListInternal_real(sval_t *node, scr_block_t *block)
{
    while (1) {
        node = (sval_t *)node[1].node;
        if (!node)
            break;
        Scr_CalcLocalVarsSafeSetVariableField_real(((sval_t *)node[0].node)[0], ((sval_t *)node[0].node)[1], block);
    }
}

static void Scr_CalcLocalVarsFormalParameterList_real(sval_t exprlist, scr_block_t *block)
{
    Scr_CalcLocalVarsFormalParameterListInternal_real((sval_t *)((sval_t *)exprlist.node)[0].node, block);
}

static void Scr_CalcLocalVarsWaittillStatement_real(sval_t exprlist, scr_block_t *block)
{
    Scr_CalcLocalVarsFormalParameterListInternal_real((sval_t *)((sval_t *)((sval_t *)exprlist.node)[0].node)[1].node, block);
}

static void Scr_CalcLocalVarsStatementList_real(sval_t val, scr_block_t *block);
static void Scr_CalcLocalVarsStatement_real(sval_t val, scr_block_t *block);

static void Scr_CalcLocalVarsIfStatement_real(sval_t stmt, scr_block_t *block, sval_t *ifStatBlock)
{
    Scr_CopyBlock_real(block, &ifStatBlock->block);
    Scr_CalcLocalVarsStatement_real(stmt, ifStatBlock->block);
    Scr_MergeChildBlocks_real(&ifStatBlock->block, 1, block);
}

static void Scr_CalcLocalVarsIfElseStatement_real(sval_t stmt1, sval_t stmt2, scr_block_t *block, sval_t *ifStatBlock, sval_t *elseStatBlock)
{
    int childCount = 0, abortLevel = SCR_ABORT_RETURN;
    scr_block_t *childBlocks[2];

    Scr_CopyBlock_real(block, &ifStatBlock->block);
    Scr_CalcLocalVarsStatement_real(stmt1, ifStatBlock->block);

    if (ifStatBlock->block->abortLevel <= SCR_ABORT_MAX) {
        abortLevel = ifStatBlock->block->abortLevel;
        if (abortLevel == SCR_ABORT_NONE) {
            childBlocks[0] = ifStatBlock->block;
            childCount = 1;
        }
    }

    Scr_CopyBlock_real(block, &elseStatBlock->block);
    Scr_CalcLocalVarsStatement_real(stmt2, elseStatBlock->block);

    if (elseStatBlock->block->abortLevel <= abortLevel) {
        abortLevel = elseStatBlock->block->abortLevel;
        if (abortLevel == SCR_ABORT_NONE) {
            childBlocks[childCount] = elseStatBlock->block;
            childCount++;
        }
    }

    if (block->abortLevel == SCR_ABORT_NONE)
        block->abortLevel = abortLevel;

    Scr_AppendChildBlocks_real(childBlocks, childCount, block);
    Scr_MergeChildBlocks_real(childBlocks, childCount, block);
}

static void Scr_CalcLocalVarsDeveloperStatementList_real(sval_t val, scr_block_t *block, sval_t *devStatBlock)
{
    Scr_CopyBlock_real(block, &devStatBlock->block);
    Scr_CalcLocalVarsStatementList_real(val, devStatBlock->block);
    Scr_MergeChildBlocks_real(&devStatBlock->block, 1, block);
}

static void Scr_CalcLocalVarsSwitchStatement_real(sval_t stmtlist, scr_block_t *block)
{
    int childCount, breakChildCount;
    int abortLevel = SCR_ABORT_RETURN;
    int hasDefault;
    scr_block_t *currentBlock;
    int *oldBreakChildCount;
    scr_block_t **oldBreakChildBlocks, **breakChildBlocks, **childBlocks;
    sval_t *node;

    oldBreakChildBlocks = SCRCG->breakChildBlocks;
    oldBreakChildCount = SCRCG->breakChildCount;

    breakChildCount = 0;
    breakChildBlocks = (scr_block_t **)Hunk_AllocateTempMemoryHighInternal(sizeof(scr_block_t *) * MAX_SWITCH_CASES);
    SCRCG->breakChildBlocks = breakChildBlocks;
    SCRCG->breakChildCount = &breakChildCount;

    childCount = 0;
    currentBlock = NULL;
    hasDefault = 0;
    childBlocks = (scr_block_t **)Hunk_AllocateTempMemoryHighInternal(sizeof(scr_block_t *) * MAX_SWITCH_CASES);

    for (node = (sval_t *)((sval_t *)((sval_t *)stmtlist.node)[0].node)[1].node; node; node = (sval_t *)node[1].node) {
        if (((sval_t *)node[0].node)[0].type == ENUM_case || ((sval_t *)node[0].node)[0].type == ENUM_default) {
            currentBlock = NULL;
            Scr_CopyBlock_real(block, &currentBlock);
            if (((sval_t *)node[0].node)[0].type == ENUM_case)
                ((sval_t *)node[0].node)[3].block = currentBlock;
            else {
                ((sval_t *)node[0].node)[2].block = currentBlock;
                hasDefault = 1;
            }
        } else if (currentBlock) {
            Scr_CalcLocalVarsStatement_real(node[0], currentBlock);
            if (currentBlock->abortLevel != SCR_ABORT_NONE) {
                if (currentBlock->abortLevel == SCR_ABORT_BREAK) {
                    currentBlock->abortLevel = SCR_ABORT_NONE;
                    abortLevel = SCR_ABORT_NONE;
                    Scr_CheckMaxSwitchCases_real(childCount);
                    childBlocks[childCount] = currentBlock;
                    childCount++;
                } else if (currentBlock->abortLevel <= abortLevel) {
                    abortLevel = currentBlock->abortLevel;
                }
                currentBlock = NULL;
            }
        }
    }

    if (hasDefault) {
        if (currentBlock) {
            Scr_AddBreakBlock_real(currentBlock);
            Scr_CheckMaxSwitchCases_real(childCount);
            childBlocks[childCount] = currentBlock;
            childCount++;
        }
        if (block->abortLevel == SCR_ABORT_NONE)
            block->abortLevel = abortLevel;
        Scr_AppendChildBlocks_real(breakChildBlocks, breakChildCount, block);
        Scr_MergeChildBlocks_real(childBlocks, childCount, block);
    }

    SCRCG->breakChildBlocks = oldBreakChildBlocks;
    SCRCG->breakChildCount = oldBreakChildCount;
}

static void Scr_CalcLocalVarsWhileStatement_real(sval_t expr, sval_t stmt, scr_block_t *block, sval_t *whileStatBlock)
{
    scr_block_t **oldContinueChildBlocks, **continueChildBlocks, **breakChildBlocks, **oldBreakChildBlocks;
    int continueChildCount, breakChildCount, i;
    int *oldBreakChildCount, *oldContinueChildCount;
    VariableCompileValue constValue;
    int constConditional;

    constConditional = 0;
    if (EvalExpression_real(expr, &constValue)) {
        if (constValue.value.type == 6 || constValue.value.type == 8) {
            Scr_CastBool(&constValue.value);
            if (constValue.value.u.intValue)
                constConditional = 1;
        }
        RemoveRefToValue(constValue.value.type, constValue.value.u);
    }

    oldBreakChildBlocks = SCRCG->breakChildBlocks;
    oldBreakChildCount = SCRCG->breakChildCount;
    oldContinueChildBlocks = SCRCG->continueChildBlocks;
    oldContinueChildCount = SCRCG->continueChildCount;

    breakChildCount = 0;
    continueChildCount = 0;
    continueChildBlocks = (scr_block_t **)Hunk_AllocateTempMemoryHighInternal(sizeof(scr_block_t *) * MAX_SWITCH_CASES);
    SCRCG->continueChildBlocks = continueChildBlocks;
    SCRCG->continueChildCount = &continueChildCount;

    if (constConditional) {
        breakChildBlocks = (scr_block_t **)Hunk_AllocateTempMemoryHighInternal(sizeof(scr_block_t *) * MAX_SWITCH_CASES);
        SCRCG->breakChildCount = &breakChildCount;
    } else {
        breakChildBlocks = NULL;
    }
    SCRCG->breakChildBlocks = breakChildBlocks;

    Scr_CopyBlock_real(block, &whileStatBlock->block);
    Scr_CalcLocalVarsStatement_real(stmt, whileStatBlock->block);
    Scr_AddContinueBlock_real(whileStatBlock->block);

    for (i = 0; i < continueChildCount; i++)
        Scr_AppendChildBlocks_real(&continueChildBlocks[i], 1, block);

    if (constConditional)
        Scr_AppendChildBlocks_real(breakChildBlocks, breakChildCount, block);

    Scr_MergeChildBlocks_real(&whileStatBlock->block, 1, block);

    SCRCG->breakChildBlocks = oldBreakChildBlocks;
    SCRCG->breakChildCount = oldBreakChildCount;
    SCRCG->continueChildBlocks = oldContinueChildBlocks;
    SCRCG->continueChildCount = oldContinueChildCount;
}

static void Scr_CalcLocalVarsForStatement_real(sval_t stmt1, sval_t expr, sval_t stmt2, sval_t stmt, scr_block_t *block, sval_t *forStatBlock, sval_t *forStatPostBlock)
{
    scr_block_t **oldContinueChildBlocks, **continueChildBlocks, **breakChildBlocks, **oldBreakChildBlocks;
    int continueChildCount, breakChildCount, i;
    int *oldBreakChildCount, *oldContinueChildCount;
    VariableCompileValue constValue;
    int constConditional;

    Scr_CalcLocalVarsStatement_real(stmt1, block);

    if (((sval_t *)expr.node)[0].type == ENUM_expression) {
        constConditional = 0;
        if (EvalExpression_real(((sval_t *)expr.node)[1], &constValue)) {
            if (constValue.value.type == 6 || constValue.value.type == 8) {
                Scr_CastBool(&constValue.value);
                if (constValue.value.u.intValue)
                    constConditional = 1;
            }
            RemoveRefToValue(constValue.value.type, constValue.value.u);
        }
    } else {
        constConditional = 1;
    }

    oldBreakChildBlocks = SCRCG->breakChildBlocks;
    oldBreakChildCount = SCRCG->breakChildCount;
    oldContinueChildBlocks = SCRCG->continueChildBlocks;
    oldContinueChildCount = SCRCG->continueChildCount;

    breakChildCount = 0;
    continueChildCount = 0;
    continueChildBlocks = (scr_block_t **)Hunk_AllocateTempMemoryHighInternal(sizeof(scr_block_t *) * MAX_SWITCH_CASES);
    SCRCG->continueChildBlocks = continueChildBlocks;
    SCRCG->continueChildCount = &continueChildCount;

    if (constConditional) {
        breakChildBlocks = (scr_block_t **)Hunk_AllocateTempMemoryHighInternal(sizeof(scr_block_t *) * MAX_SWITCH_CASES);
        SCRCG->breakChildCount = &breakChildCount;
    } else {
        breakChildBlocks = NULL;
    }
    SCRCG->breakChildBlocks = breakChildBlocks;

    Scr_CopyBlock_real(block, &forStatBlock->block);
    Scr_CopyBlock_real(block, &forStatPostBlock->block);
    Scr_CalcLocalVarsStatement_real(stmt, forStatBlock->block);
    Scr_AddContinueBlock_real(forStatBlock->block);

    for (i = 0; i < continueChildCount; i++)
        Scr_AppendChildBlocks_real(&continueChildBlocks[i], 1, block);

    Scr_CalcLocalVarsStatement_real(stmt2, forStatPostBlock->block);
    Scr_AppendChildBlocks_real(&forStatPostBlock->block, 1, block);
    Scr_MergeChildBlocks_real(&forStatPostBlock->block, 1, block);

    if (constConditional)
        Scr_AppendChildBlocks_real(breakChildBlocks, breakChildCount, block);

    Scr_MergeChildBlocks_real(&forStatBlock->block, 1, block);

    SCRCG->breakChildBlocks = oldBreakChildBlocks;
    SCRCG->breakChildCount = oldBreakChildCount;
    SCRCG->continueChildBlocks = oldContinueChildBlocks;
    SCRCG->continueChildCount = oldContinueChildCount;
}

static void Scr_CalcLocalVarsStatement_real(sval_t val, scr_block_t *block)
{
    sval_t *n = (sval_t *)val.node;
    switch (n[0].type) {
    case ENUM_assignment:
        Scr_CalcLocalVarsAssignmentStatement_real(n[1], n[2], block);
        break;
    case ENUM_return:
    case ENUM_return2:
        if (block->abortLevel == SCR_ABORT_NONE)
            block->abortLevel = SCR_ABORT_RETURN;
        break;
    case ENUM_if:
        Scr_CalcLocalVarsIfStatement_real(n[2], block, &n[4]);
        break;
    case ENUM_if_else:
        Scr_CalcLocalVarsIfElseStatement_real(n[2], n[3], block, &n[6], &n[7]);
        break;
    case ENUM_while:
        Scr_CalcLocalVarsWhileStatement_real(n[1], n[2], block, &n[5]);
        break;
    case ENUM_for:
        Scr_CalcLocalVarsForStatement_real(n[1], n[2], n[3], n[4], block, &n[7], &n[8]);
        break;
    case ENUM_inc:
    case ENUM_dec:
    case ENUM_binary_equals:
        Scr_CalcLocalVarsIncStatement_real(n[1], block);
        break;
    case ENUM_statement_list:
        Scr_CalcLocalVarsStatementList_real(n[1], block);
        break;
    case ENUM_developer_statement_list:
        Scr_CalcLocalVarsDeveloperStatementList_real(n[1], block, &n[3]);
        break;
    case ENUM_waittill:
        Scr_CalcLocalVarsWaittillStatement_real(n[2], block);
        break;
    case ENUM_switch:
        Scr_CalcLocalVarsSwitchStatement_real(n[2], block);
        break;
    case ENUM_break:
        Scr_AddBreakBlock_real(block);
        if (block->abortLevel == SCR_ABORT_NONE)
            block->abortLevel = SCR_ABORT_BREAK;
        break;
    case ENUM_continue:
        Scr_AddContinueBlock_real(block);
        if (block->abortLevel == SCR_ABORT_NONE)
            block->abortLevel = SCR_ABORT_CONTINUE;
        break;
    }
}

static void Scr_CalcLocalVarsStatementList_real(sval_t val, scr_block_t *block)
{
    sval_t *node;
    for (node = (sval_t *)((sval_t *)((sval_t *)val.node)[0].node)[1].node; node; node = (sval_t *)node[1].node)
        Scr_CalcLocalVarsStatement_real(node[0], block);
}

/* --- Scr_CalcLocalVarsThread_new: allocate block for a thread --- */
static void Scr_CalcLocalVarsThread_new(sval_t exprlist, sval_t stmtlist, sval_t *stmttblock)
{
    SCRCG->forceNotCreate = 0;

    stmttblock->block = (scr_block_t *)Hunk_AllocateTempMemoryHighInternal(sizeof(scr_block_t));

    stmttblock->block->abortLevel = SCRCOMP_SCR_ABORT_NONE;
    stmttblock->block->localVarsCreateCount = 0;
    stmttblock->block->localVarsCount = 0;
    stmttblock->block->localVarsPublicCount = 0;
    memset(stmttblock->block->localVarsInitBits, 0, sizeof(stmttblock->block->localVarsInitBits));

    Scr_CalcLocalVarsFormalParameterList_real(exprlist, stmttblock->block);
    Scr_CalcLocalVarsStatementList_real(stmtlist, stmttblock->block);
}

/* --- EmitThreadInternal_new: compile the body of a single thread --- */
static void EmitThreadInternal_new(unsigned int threadId, sval_t val, sval_t sourcePos,
                                    sval_t endSourcePos, scr_block_t *block)
{
    sval_t *vnode = (sval_t *)val.node;

    SCRCG->threadId = threadId;
    AddThreadStartOpcodePos(sourcePos.sourcePosValue);

    SCRCG->cumulOffset = 0;
    SCRCG->maxOffset = 0;
    SCRCG->maxCallOffset = 0;

    CompileTransferRefToString_real(vnode[1].stringValue, 2);

    EmitFormalParameterList_real(vnode[2], sourcePos, block);
    EmitStatementList_new(vnode[3], 1, endSourcePos.sourcePosValue, block);

    EmitEnd_real();

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

extern void Com_Error(int code, const char *fmt, ...);
#define ERR_DROP 1

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
