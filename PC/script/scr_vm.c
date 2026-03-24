/* ASM dump from: scr_vm.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/script/scr_vm.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/profile.h"
 *   #include "PC/script/scr_vm.h"
 *   #include "PC/script/scr_variable.h"
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

extern struct scrVmPub_t scrVmPub; /* 0x0 */
extern char g_EndPos; /* 0x0 */
extern jmp_buf g_script_error[33]; /* 0x0 */
extern int g_script_error_level; /* 0x0 */
extern unsigned char scrVmGlob[]; /* scrVmGlob - BSS */

extern void FreeValue(unsigned int value);
extern void Var_Shutdown(void);
extern void SL_Shutdown(void);
extern void Scr_RemoveThreadNotifyName(unsigned int startLocalId);
extern void RemoveObjectVariable(unsigned int parentId, unsigned int id);
extern unsigned int GetArraySize(unsigned int id);
extern void RemoveVariable(unsigned int parentId, unsigned int value);
extern unsigned int FindObject(unsigned int id);
extern unsigned int FindVariable(unsigned int parentId, unsigned int value);
extern unsigned int Scr_GetThreadNotifyName(unsigned int startLocalId);

void Scr_ClearErrorMessage(void);
void Scr_Settings(int developer, int developer_script, int abort_on_error);
void Scr_Shutdown(void);
void Scr_Abort(void);
void Scr_SetLoading(int bLoading);
unsigned int Scr_GetNumScriptThreads(void);
void Scr_ResetTimeout(void);
static void VM_CancelNotifyInternal(unsigned int notifyListOwnerId, unsigned int startLocalId, unsigned int notifyListId, unsigned int notifyNameListId, unsigned int stringValue);
void VM_CancelNotify(unsigned int notifyListOwnerId, unsigned int startLocalId);
static VariableStackBuffer * VM_ArchiveStack(int size, const char *pos, VariableValue *top, unsigned int localVarCount, unsigned int *pLocalId);
static void VM_TerminateStack(unsigned int endLocalId, unsigned int startLocalId, VariableStackBuffer *stackValue);
static void VM_TrimStack(unsigned int startLocalId, VariableStackBuffer *stackValue, Bool fromEndon);
static void Scr_CancelWaittill(void);
void Scr_CancelNotifyList(unsigned int notifyListOwnerId);
void Scr_FreeThread(int handle);
void Scr_VM_Init(void);
void Scr_InitSystem(void);
void Scr_ShutdownSystem(int sys, int bComplete);
int Scr_IsSystemActive(int sys);
unsigned int Scr_GetNumParam(void);
void Scr_AddArray(void);
void Scr_AddArrayStringIndexed(unsigned int stringValue);
unsigned long long __attribute__((regparm(0))) GetEntityFieldValue(unsigned int classnum, int entnum, int offset);
void Scr_SetStructField(unsigned int structId, unsigned int index);
void Scr_Init(void);
void Scr_TraverseScript(const char *pos);
const char * Scr_GetNextCodepos(VariableValue *top, const char *pos, int opcode, int mode, unsigned int *localId);
static void VM_Notify(unsigned int notifyListOwnerId, unsigned int stringValue, VariableValue *top);
void Scr_SetDynamicEntityField(int entnum, int classnum, unsigned int index);
void Scr_MakeArray(void);
void Scr_NotifyNum(int entnum, int classnum, unsigned int stringValue, unsigned int paramcount);
Bool SetEntityFieldValue(unsigned int classnum, int entnum, int offset, VariableValue *value);
void Scr_ObjectError(const char *error);
void Scr_ParamError(unsigned int index, const char *error);
void Scr_TerminalError(const char *error);
int Scr_GetPointerType(unsigned int index);
const char * Scr_GetTypeName(unsigned int index);
int Scr_GetType(unsigned int index);
unsigned int Scr_GetObject(unsigned int index);
struct scr_entref_t Scr_GetEntityRef(unsigned int index);
void Scr_GetVector(unsigned int index, float *vectorValue);
const char * Scr_GetDebugString(unsigned int index);
float Scr_GetFloat(unsigned int index);
int Scr_GetInt(unsigned int index);
static unsigned int VM_Execute(struct function_stack_t fs);
static unsigned int VM_Execute_ext(void);
static void VM_Resume(unsigned int timeId);
void Scr_RunCurrentThreads(void);
void Scr_IncTime(void);
void Scr_AddExecThread(scr_func_t handle, unsigned int paramcount);
scr_thread_t Scr_ExecEntThreadNum(int entnum, int classnum, scr_func_t handle, unsigned int paramcount);
scr_thread_t Scr_ExecThread(scr_func_t handle, unsigned int paramcount);
const char * Scr_GetIString(unsigned int index);
scr_anim_t Scr_GetAnim(unsigned int index, struct XAnimTree_s *tree);
unsigned int Scr_GetConstString(unsigned int index);
unsigned int Scr_GetConstStringIncludeNull(unsigned int index);
const char * Scr_GetString(unsigned int index);
unsigned int Scr_GetConstLowercaseString(unsigned int index);
void Scr_Error(const char *error);
void Scr_AddStruct(void);
void Scr_AddEntityNum(int entnum, int classnum);
void Scr_AddBool(int value);
void Scr_AddInt(int value);
void Scr_AddFloat(float value);
void Scr_AddUndefined(void);
void Scr_AddObject(unsigned int id);
void Scr_AddString(const char *value);
void Scr_AddConstString(unsigned int value);
void Scr_AddVector(const float *value);
extern void RemoveRefToObject(unsigned int id);

/* line 86 */
void Scr_ClearErrorMessage(void)
{
    struct scrVarPub_t *p = (struct scrVarPub_t *)imp_scrVarPub;
    p->error_message = NULL;
    *(int *)((char *)&scrVmGlob + 16) = 0;
    p->error_index = 0;
}

/* line 182 */
void Scr_Settings(int developer, int developer_script, int abort_on_error)
{
    struct scrVarPub_t *p = (struct scrVarPub_t *)imp_scrVarPub;
    p->developer = developer != 0;
    p->developer_script = developer_script != 0;
    *(byte *)((char *)&scrVmPub + 21) = abort_on_error != 0;
}

/* line 192 */
void Scr_Shutdown(void)
{
    struct scrVarPub_t *base = (struct scrVarPub_t *)imp_scrVarPub;
    unsigned int val;

    if (!base->bInited)
        return;

    base->bInited = 0;
    val = base->tempVariable;
    if (val) {
        FreeValue(val);
        base->tempVariable = 0;
    }
    Var_Shutdown();
    SL_Shutdown();
}

/* line 204 */
void Scr_Abort(void)
{
    struct scrVarPub_t *p = (struct scrVarPub_t *)imp_scrVarPub;
    p->timeArrayId = 0;
    p->bInited = 0;
}

/* line 211 */
void Scr_SetLoading(int bLoading)
{
    *(int *)((char *)&scrVmGlob + 20) = bLoading;
}

/* line 267 */
unsigned int Scr_GetNumScriptThreads(void)
{
    return 0;
}

extern unsigned int AllocValue(void);
extern unsigned int AllocObject(void);
extern unsigned int Scr_AllocArray(void);

/*
 * Scr_VM_Init: initialize the script VM state.
 * ref: Scr_VM_Init @ 0807F834
 */
void Scr_VM_Init(void)
{
    struct scrVarPub_t *p = (struct scrVarPub_t *)imp_scrVarPub;
    struct scrVmPub_t  *vm = (struct scrVmPub_t *)imp_scrVmPub;

    /* Set up eval stack pointer: top points to the first stack entry */
    vm->top = &vm->stack[0];
    /* maxstack: upper bound (one past last usable entry) */
    vm->maxstack = &vm->stack[2047];
    /* function frame starts at function_frame_start[0] */
    vm->function_frame = &vm->function_frame_start[0];
    vm->function_count = 0;

    /* localVars: point to scrVmGlob.localVarsStack[0].
     * scrVmGlob layout: eval_stack(16) + dialog_err(4) + loading(4) + starttime(4) + localVarsStack(0...)
     * => localVarsStack[0] is at scrVmGlob + 28 */
    vm->localVars = (unsigned int *)((char *)&scrVmGlob + 28);

    /* Clear flags */
    vm->debugCode = 0;
    vm->terminal_error = 0;
    vm->inparamcount = 0;
    vm->outparamcount = 0;

    /* scrVarPub.evaluate = 0 */
    p->evaluate = 0;

    Scr_ClearErrorMessage();

    /* Allocate the temp variable slot */
    p->tempVariable = AllocValue();

    /* Zero the entity/game/anim array IDs */
    p->timeArrayId   = 0;
    p->pauseArrayId  = 0;
    p->levelId       = 0;
    p->gameId        = 0;
    p->animId        = 0;
    p->freeEntList   = 0;

    /* Clear loading state */
    *(int *)((char *)&scrVmGlob + 20) = 0;  /* scrVmGlob.loading = 0 */
}

/*
 * Scr_InitSystem: allocate the top-level game variable objects.
 * ref: Scr_InitSystem @ 08083E96
 */
void Scr_InitSystem(void)
{
    struct scrVarPub_t *p = (struct scrVarPub_t *)imp_scrVarPub;

    p->timeArrayId  = AllocObject();
    p->pauseArrayId = Scr_AllocArray();
    p->levelId      = AllocObject();
    p->gameId       = AllocObject();

    p->entId        = 0;
    /* g_script_error_level sentinel */
    *(int *)((char *)&scrVmGlob + 20) = 0;   /* loading = 0, repurpose as level sentinel */
    /* The reference also sets dword_8394018 = 0, dword_83D553C = -1.
     * dword_8394018 is not in our scrVarPub_t struct definition but
     * it's BSS-zeroed at startup so we don't need to explicitly zero it. */
}

extern void Com_Error(int code, const char *fmt, ...);

/*
 * Scr_TerminalError: set terminal error flag and abort with a fatal error.
 * ref: Scr_TerminalError @ 0807FAC0 area
 */
void Scr_TerminalError(const char *error)
{
    struct scrVmPub_t *vm = (struct scrVmPub_t *)imp_scrVmPub;
    vm->terminal_error = 1;
    Com_Error(1, "%s", error);
}

/* line 5100 */
void Scr_ResetTimeout(void)
{
    unsigned int tsc_low;
    tsc_low = 0;
    *(unsigned int *)(scrVmGlob + 24) = tsc_low >> 2;
}

/* line 2620 */
static void VM_CancelNotifyInternal(unsigned int notifyListOwnerId, unsigned int startLocalId, unsigned int notifyListId, unsigned int notifyNameListId, unsigned int stringValue) {
    Scr_RemoveThreadNotifyName(startLocalId);
    RemoveObjectVariable(notifyNameListId, startLocalId);
    if (GetArraySize(notifyNameListId))
        return;
    RemoveVariable(notifyListId, stringValue);
    if (GetArraySize(notifyListId))
        return;
    RemoveVariable(notifyListOwnerId, 0x1fffe);
}

/* line 2640 */
void VM_CancelNotify(unsigned int notifyListOwnerId, unsigned int startLocalId) {
    unsigned int notifyListId = FindObject(FindVariable(notifyListOwnerId, 0x1fffe));
    unsigned int stringValue = (unsigned short)Scr_GetThreadNotifyName(startLocalId);
    unsigned int notifyNameListId = FindObject(FindVariable(notifyListId, stringValue));
    VM_CancelNotifyInternal(notifyListOwnerId, startLocalId, notifyListId, notifyNameListId, stringValue);
}

/* Scr_ExecThread: execute a script thread.
 * ref: 0808398E */
extern unsigned int VM_Execute_wrapper(unsigned int localId, const char *pos, unsigned int paramcount);
scr_thread_t Scr_ExecThread(scr_func_t handle, unsigned int numArgs)
{
    extern void Scr_ResetTimeout(void);
    extern void Scr_IsInOpcodeMemory(int addr);
    extern unsigned int AllocThread(unsigned int self);
    extern void AddRefToObject(unsigned int id);
    extern unsigned char scrCompilePub[];

    struct scrVarPub_t *pub = (struct scrVarPub_t *)imp_scrVarPub;
    struct scrVmPub_t *vm = (struct scrVmPub_t *)imp_scrVmPub;
    unsigned int codepos_base = *(unsigned int *)((char *)scrCompilePub + 0);

    const char *pos = (const char *)(codepos_base + handle);

    if (!vm->function_count)
        Scr_ResetTimeout();

    Scr_IsInOpcodeMemory((int)pos);
    AddRefToObject(pub->gameId);
    unsigned int threadId = AllocThread(pub->gameId);

    unsigned int result = VM_Execute_wrapper(threadId, pos, numArgs);

    /* Clean up return value from stack */
    if (vm->top && vm->inparamcount > 0) {
        vm->top->type = 0;
        vm->top--;
        vm->inparamcount--;
    }

    return result;
}

/* Scr_KillThread: kill a running thread.
 * ref: 080832FC */
void Scr_KillThread(unsigned int threadId)
{
    extern void RemoveRefToObject(unsigned int id);
    RemoveRefToObject(threadId);
}

/* =========================================================
 * VM_Execute (5-arg bytecode interpreter)
 * Ported from: CoD2rev_Server/src/script/scr_vm.cpp lines 3023-4861
 * ========================================================= */

/* VariableValue type enum (matches reference script_public.h) */
#define VAR_UNDEFINED        0
#define VAR_POINTER          1
#define VAR_STRING           2
#define VAR_ISTRING          3
#define VAR_VECTOR           4
#define VAR_FLOAT            5
#define VAR_INTEGER          6
#define VAR_CODEPOS          7
#define VAR_PRECODEPOS       8
#define VAR_FUNCTION         9
#define VAR_STACK            10
#define VAR_ANIMATION        11
#define VAR_DEVELOPER_CODEPOS 12
#define VAR_INCLUDE_CODEPOS  13
#define VAR_THREAD_LIST      14
#define VAR_THREAD           15
#define VAR_NOTIFY_THREAD    16
#define VAR_TIME_THREAD      17
#define VAR_CHILD_THREAD     18
#define VAR_OBJECT           19
#define VAR_DEAD_ENTITY      20
#define VAR_ENTITY           21
#define VAR_ARRAY            22
#define VAR_DEAD_THREAD      23

/* Opcode values */
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

/* VM constants */
#define MAX_VM_STACK_DEPTH          32
#define MAX_EMBEDDED_FUNCTION_CALLS (MAX_VM_STACK_DEPTH - 2)
#define OBJECT_NOTIFY_LIST          0x1FFFE
#define VAR_NAME_LOW_MASK           0xFFFFFF
#define INFINITE_LOOP_TIMEOUT       5000
#define WAIT_FRAME_TIME             20

/* Inline read helpers */
static unsigned char vm_read_byte(const char **pos)
{
    unsigned char v = *(const unsigned char *)(*pos);
    *pos += 1;
    return v;
}
static unsigned short vm_read_ushort(const char **pos)
{
    unsigned short v;
    __builtin_memcpy(&v, *pos, 2);
    *pos += 2;
    return v;
}
static unsigned int vm_read_uint(const char **pos)
{
    unsigned int v;
    __builtin_memcpy(&v, *pos, 4);
    *pos += 4;
    return v;
}
static int vm_read_int(const char **pos)
{
    int v;
    __builtin_memcpy(&v, *pos, 4);
    *pos += 4;
    return v;
}
static float vm_read_float(const char **pos)
{
    float v;
    __builtin_memcpy(&v, *pos, 4);
    *pos += 4;
    return v;
}
static const float *vm_read_vector(const char **pos)
{
    const float *v = (const float *)(*pos);
    *pos += 12;
    return v;
}
static const char *vm_read_codepos(const char **pos)
{
    const char *v;
    __builtin_memcpy(&v, *pos, 4);
    *pos += 4;
    return v;
}

/* External function declarations needed by VM_Execute */
extern char *va(const char *fmt, ...);
extern void RemoveRefToValue(VariableValue *value);
extern void AddRefToObject(unsigned int id);
extern void SL_AddRefToString(unsigned int stringValue);
extern void SL_RemoveRefToString(unsigned int stringValue);
extern unsigned int GetNewVariable(unsigned int parentId, unsigned int id);
extern unsigned int GetNewObjectVariable(unsigned int parentId, unsigned int id);
extern unsigned int GetNewObjectVariableReverse(unsigned int parentId, unsigned int id);
extern unsigned int GetObjectVariable(unsigned int parentId, unsigned int id);
extern unsigned int GetVariable(unsigned int parentId, unsigned int id);
extern unsigned int GetArray(unsigned int id);
extern unsigned int FindEntityId(unsigned int entnum, unsigned int classnum);
extern unsigned int Scr_GetSelf(unsigned int localId);
extern unsigned int AllocChildThread(unsigned int selfId, unsigned int localId);
extern unsigned int AllocThread(unsigned int selfId);
extern unsigned int GetSafeParentLocalId(unsigned int localId);
extern unsigned int GetObjectType(unsigned int id);
extern int IsFieldObject(unsigned int id);
extern int IsValidArrayIndex(unsigned int id);
extern unsigned int GetInternalVariableIndex(unsigned int id);
extern unsigned int GetDummyFieldValue(void);
extern unsigned int GetDummyObject(void);
extern unsigned int Scr_EvalArrayRef(unsigned int id);
extern unsigned int Scr_EvalArrayIndex(unsigned int arrayId, VariableValue *index);
extern void ClearArray(unsigned int arrayId, VariableValue *index);
extern VariableValue Scr_EvalVariable(unsigned int id);
extern VariableValue Scr_EvalVariableField(unsigned int id);
extern VariableValue Scr_EvalVariable_s(unsigned int id);
extern unsigned int Scr_EvalVariableObject(unsigned int id);
extern unsigned int Scr_EvalFieldObject(unsigned int tempId, VariableValue *value);
extern void Scr_EvalArray(VariableValue *val, VariableValue *index);
extern VariableValue Scr_FindVariableField(unsigned int objectId, unsigned int fieldId);
extern unsigned int Scr_GetVariableField(unsigned int objectId, unsigned int fieldId);
extern void SetVariableValue(unsigned int id, VariableValue *value);
extern void SetVariableFieldValue(unsigned int id, VariableValue *value);
extern void SetNewVariableValue(unsigned int id, VariableValue *value);
extern void ClearVariableField(unsigned int objectId, unsigned int fieldId, VariableValue *top);
extern void ClearVariableValue(unsigned int id);
extern void RemoveNextVariable(unsigned int id);
extern unsigned int Scr_GetLocalVarAtIndex(unsigned int index);
extern unsigned int Scr_GetLocalVar(const char *pos);
extern void Scr_SetThreadWaitTime(unsigned int localId, unsigned int waitTime);
extern void Scr_SetThreadNotifyName(unsigned int localId, unsigned int stringValue);
extern int Scr_IsInScriptMemory(const char *pos);
/* VM_ArchiveStack: signature from top-of-file declaration */
extern void VM_Notify(unsigned int notifyListOwnerId, unsigned int stringValue, VariableValue *top);
extern void RuntimeError(const char *codePos, unsigned int index, const char *errorMsg, const char *format);
extern void RuntimeErrorInternal(int channel, const char *codePos, unsigned int index, const char *errorMessage);
extern void Scr_PrintPrevCodePos(int channel, const char *pos, unsigned int index);
extern scr_entref_t Scr_GetEntityIdRef(unsigned int objectId);
extern unsigned int Scr_AllocArray(void);
extern void Scr_CastBool(VariableValue *value);
extern void Scr_EvalBoolNot(VariableValue *value);
extern void Scr_EvalBoolComplement(VariableValue *value);
extern void Scr_CastVector(VariableValue *value);
extern void Scr_EvalSizeValue(VariableValue *value);
extern void Scr_EvalOr(VariableValue *a, VariableValue *b);
extern void Scr_EvalExOr(VariableValue *a, VariableValue *b);
extern void Scr_EvalAnd(VariableValue *a, VariableValue *b);
extern void Scr_EvalEquality(VariableValue *a, VariableValue *b);
extern void Scr_EvalInequality(VariableValue *a, VariableValue *b);
extern void Scr_EvalLess(VariableValue *a, VariableValue *b);
extern void Scr_EvalGreater(VariableValue *a, VariableValue *b);
extern void Scr_EvalLessEqual(VariableValue *a, VariableValue *b);
extern void Scr_EvalGreaterEqual(VariableValue *a, VariableValue *b);
extern void Scr_EvalShiftLeft(VariableValue *a, VariableValue *b);
extern void Scr_EvalShiftRight(VariableValue *a, VariableValue *b);
extern void Scr_EvalPlus(VariableValue *a, VariableValue *b);
extern void Scr_EvalMinus(VariableValue *a, VariableValue *b);
extern void Scr_EvalMultiply(VariableValue *a, VariableValue *b);
extern void Scr_EvalDivide(VariableValue *a, VariableValue *b);
extern void Scr_EvalMod(VariableValue *a, VariableValue *b);
extern void Scr_Error(const char *error);
extern const char *var_typename[];
extern unsigned int Sys_Milliseconds(void);
extern int Com_Printf(const char *fmt, ...);
extern void Com_PrintMessage(int channel, const char *msg);
extern void *imp_scrVarPub;
extern void *imp_scrVmPub;
extern void *imp_scrCompilePub;

#define SCR_VAR_PUB  ((struct scrVarPub_t *)imp_scrVarPub)
#define SCR_VM_PUB   ((struct scrVmPub_t *)imp_scrVmPub)
#define SCR_COMP_PUB ((struct scrCompilePub_t *)imp_scrCompilePub)

#define CON_CHANNEL_DONT_FILTER 0

static unsigned int VM_Execute_internal(const char *pos, unsigned int localId, unsigned int localVarCount, VariableValue *top, VariableValue *startTop)
{
    int jumpOffset, entnum, gCaseCount, waitTime;
    unsigned int parentLocalId, builtinIndex, stringValue, id, threadId, classnum, removeCount;
    unsigned int outparamcount, selfId, objectId, fieldValueId, caseValue, currentCaseValue, stackId;
    VariableValue stackValue, tempValue;
    VariableValue *value;
    scr_entref_t entref;
    const char *currentCodePos, *tempCodePos;

    int gOpcode = 0;
    int gParamCount = 0;

    struct scrVarPub_t *scrVarPub = SCR_VAR_PUB;
    struct scrVmPub_t  *scrVmPub  = SCR_VM_PUB;
    struct scrCompilePub_t *scrCompilePub = SCR_COMP_PUB;

    /* silence uninitialized warnings */
    objectId = 0;
    fieldValueId = 0;
    currentCaseValue = 0;
    currentCodePos = 0;

    g_script_error_level++;

    if (setjmp(g_script_error[g_script_error_level]))
    {
        /* error handler */
        switch (gOpcode)
        {
        case OP_EvalLocalArrayRefCached0:
        case OP_EvalLocalArrayRefCached:
        case OP_EvalArrayRef:
        case OP_ClearArray:
        case OP_EvalLocalVariableRef:
            if (scrVarPub->error_index < 0)
                scrVarPub->error_index = 1;
            break;

        case OP_EvalSelfFieldVariable:
        case OP_EvalFieldVariable:
        case OP_ClearFieldVariable:
        case OP_SetVariableField:
        case OP_SetSelfFieldVariableField:
        case OP_inc:
        case OP_dec:
            scrVarPub->error_index = 0;
            break;

        case OP_CallBuiltin0:
        case OP_CallBuiltin1:
        case OP_CallBuiltin2:
        case OP_CallBuiltin3:
        case OP_CallBuiltin4:
        case OP_CallBuiltin5:
        case OP_CallBuiltin:
            if (scrVarPub->error_index > 0)
                scrVarPub->error_index = scrVmPub->outparamcount - scrVarPub->error_index + 1;
            break;

        case OP_CallBuiltinMethod0:
        case OP_CallBuiltinMethod1:
        case OP_CallBuiltinMethod2:
        case OP_CallBuiltinMethod3:
        case OP_CallBuiltinMethod4:
        case OP_CallBuiltinMethod5:
        case OP_CallBuiltinMethod:
            if (scrVarPub->error_index > 0)
                scrVarPub->error_index = scrVmPub->outparamcount - scrVarPub->error_index + 2;
            else if (scrVarPub->error_index < 0)
                scrVarPub->error_index = 1;
            break;

        default:
            break;
        }

        RuntimeError(pos, scrVarPub->error_index, scrVarPub->error_message, *(const char **)((char *)scrVmGlob + 16));
        Scr_ClearErrorMessage();

        switch (gOpcode)
        {
        case OP_EvalLocalArrayCached:
        case OP_EvalArray:
            RemoveRefToValue(top);
            top--;
            RemoveRefToValue(top);
            top->type = VAR_UNDEFINED;
            break;

        case OP_EvalLocalArrayRefCached0:
        case OP_EvalLocalArrayRefCached:
        case OP_EvalArrayRef:
        case OP_EvalLocalVariableRef:
            fieldValueId = GetDummyFieldValue();
            RemoveRefToValue(top);
            top--;
            break;

        case OP_ClearArray:
        case OP_wait:
            RemoveRefToValue(top);
            top--;
            break;

        case OP_GetSelfObject:
            objectId = GetDummyObject();
            break;

        case OP_EvalSelfFieldVariable:
        case OP_EvalFieldVariable:
            top->type = VAR_UNDEFINED;
            break;

        case OP_EvalSelfFieldVariableRef:
        case OP_EvalFieldVariableRef:
            fieldValueId = GetDummyFieldValue();
            break;

        case OP_ClearFieldVariable:
            if (scrVmPub->outparamcount)
            {
                scrVmPub->outparamcount = 0;
            }
            break;

        case OP_checkclearparams:
            while (top->type != VAR_PRECODEPOS)
            {
                RemoveRefToValue(top);
                top--;
            }
            top->type = VAR_CODEPOS;
            break;

        case OP_SetVariableField:
            if (scrVmPub->outparamcount)
            {
                RemoveRefToValue(top);
                scrVmPub->outparamcount = 0;
                top--;
                break;
            }
            top--;
            break;

        case OP_SetSelfFieldVariableField:
            RemoveRefToValue(top);
            scrVmPub->outparamcount = 0;
            top--;
            break;

        case OP_CallBuiltin0:
        case OP_CallBuiltin1:
        case OP_CallBuiltin2:
        case OP_CallBuiltin3:
        case OP_CallBuiltin4:
        case OP_CallBuiltin5:
        case OP_CallBuiltin:
        case OP_CallBuiltinMethod0:
        case OP_CallBuiltinMethod1:
        case OP_CallBuiltinMethod2:
        case OP_CallBuiltinMethod3:
        case OP_CallBuiltinMethod4:
        case OP_CallBuiltinMethod5:
        case OP_CallBuiltinMethod:
            Scr_ClearOutParams();
            top = scrVmPub->top + 1;
            top->type = VAR_UNDEFINED;
            break;

        case OP_ScriptFunctionCall2:
        case OP_ScriptFunctionCall:
        case OP_ScriptMethodCall:
            vm_read_codepos(&pos);
            while (top->type != VAR_PRECODEPOS)
            {
                RemoveRefToValue(top);
                top--;
            }
            top->type = VAR_UNDEFINED;
            break;

        case OP_ScriptFunctionCallPointer:
        case OP_ScriptMethodCallPointer:
            while (top->type != VAR_PRECODEPOS)
            {
                RemoveRefToValue(top);
                top--;
            }
            top->type = VAR_UNDEFINED;
            break;

        case OP_ScriptThreadCall:
        case OP_ScriptMethodThreadCall:
            vm_read_codepos(&pos);
            outparamcount = vm_read_uint(&pos);
            while (outparamcount)
            {
                RemoveRefToValue(top);
                top--;
                outparamcount--;
            }
            top++;
            top->type = VAR_UNDEFINED;
            break;

        case OP_ScriptThreadCallPointer:
        case OP_ScriptMethodThreadCallPointer:
            outparamcount = vm_read_uint(&pos);
            while (outparamcount)
            {
                RemoveRefToValue(top);
                top--;
                outparamcount--;
            }
            top++;
            top->type = VAR_UNDEFINED;
            break;

        case OP_CastFieldObject:
            objectId = GetDummyObject();
            top--;
            break;

        case OP_EvalLocalVariableObjectCached:
            pos++;
            objectId = GetDummyObject();
            break;

        case OP_JumpOnFalse:
        case OP_JumpOnTrue:
        case OP_JumpOnFalseExpr:
        case OP_JumpOnTrueExpr:
            vm_read_ushort(&pos);
            top--;
            break;

        case OP_jumpback:
            jumpOffset = vm_read_ushort(&pos);
            pos -= jumpOffset;
            break;

        case OP_bit_or:
        case OP_bit_ex_or:
        case OP_bit_and:
        case OP_equality:
        case OP_inequality:
        case OP_less:
        case OP_greater:
        case OP_less_equal:
        case OP_greater_equal:
        case OP_shift_left:
        case OP_shift_right:
        case OP_plus:
        case OP_minus:
        case OP_multiply:
        case OP_divide:
        case OP_mod:
            top--;
            break;

        case OP_waittillmatch:
            pos++;
            RemoveRefToValue(top);
            top--;
            RemoveRefToValue(top);
            top--;
            break;

        case OP_waittill:
        case OP_endon:
            RemoveRefToValue(top);
            top--;
            RemoveRefToValue(top);
            top--;
            break;

        case OP_notify:
            while (top->type != VAR_PRECODEPOS)
            {
                RemoveRefToValue(top);
                top--;
            }
            RemoveRefToValue(top);
            top--;
            break;

        case OP_switch:
            while (gCaseCount)
            {
                currentCaseValue = vm_read_uint(&pos);
                currentCodePos = vm_read_codepos(&pos);
                gCaseCount--;
            }
            if (!currentCaseValue)
                pos = currentCodePos;
            RemoveRefToValue(top);
            top--;
            break;

        default:
            break;
        }
    } /* end setjmp error block */

    /* main interpreter loop */
    while (1)
    {
        gOpcode = (int)vm_read_byte(&pos);

        switch (gOpcode)
        {
        case OP_End:
            parentLocalId = GetSafeParentLocalId(localId);
            Scr_KillThread(localId);

            scrVmPub->localVars -= localVarCount;

            while (top->type != VAR_CODEPOS)
            {
                RemoveRefToValue(top);
                top--;
            }

            scrVmPub->function_count--;
            scrVmPub->function_frame--;

            if (!parentLocalId)
            {
                /* top == startTop */
                value = startTop + 1;
                value->type = VAR_UNDEFINED;
                goto thread_return;
            }

            top->type = VAR_UNDEFINED;
            goto vm_end;

        case OP_Return:
            parentLocalId = GetSafeParentLocalId(localId);
            Scr_KillThread(localId);

            scrVmPub->localVars -= localVarCount;

            tempValue.u = top->u;
            tempValue.type = top->type;

            top--;

            while (top->type != VAR_CODEPOS)
            {
                RemoveRefToValue(top);
                top--;
            }

            scrVmPub->function_count--;
            scrVmPub->function_frame--;

            if (!parentLocalId)
            {
                value = top + 1;
                value->u = tempValue.u;
                value->type = tempValue.type;
thread_return:
                if (!gParamCount)
                {
                    g_script_error_level--;
                    return localId;
                }

                gParamCount--;
                RemoveRefToObject(localId);

                pos = scrVmPub->function_frame->fs.pos;
                localId = scrVmPub->function_frame->fs.localId;
                localVarCount = scrVmPub->function_frame->fs.localVarCount;
                top = scrVmPub->function_frame->fs.top;
                startTop = scrVmPub->function_frame->fs.startTop;
                top->type = scrVmPub->function_frame->topType;

                top++;
                continue;
            }

            top->u = tempValue.u;
            top->type = tempValue.type;
vm_end:
            RemoveRefToObject(localId);

            pos = scrVmPub->function_frame->fs.pos;
            localVarCount = scrVmPub->function_frame->fs.localVarCount;
            localId = parentLocalId;
            continue;

        case OP_GetUndefined:
            top++;
            top->type = VAR_UNDEFINED;
            continue;

        case OP_GetZero:
            top++;
            top->type = VAR_INTEGER;
            top->u.intValue = 0;
            continue;

        case OP_GetByte:
            top++;
            top->type = VAR_INTEGER;
            top->u.intValue = (int)vm_read_byte(&pos);
            continue;

        case OP_GetNegByte:
            top++;
            top->type = VAR_INTEGER;
            top->u.intValue = -(int)vm_read_byte(&pos);
            continue;

        case OP_GetUnsignedShort:
            top++;
            top->type = VAR_INTEGER;
            top->u.intValue = (int)vm_read_ushort(&pos);
            continue;

        case OP_GetNegUnsignedShort:
            top++;
            top->type = VAR_INTEGER;
            top->u.intValue = -(int)vm_read_ushort(&pos);
            continue;

        case OP_GetInteger:
            top++;
            top->type = VAR_INTEGER;
            top->u.intValue = vm_read_int(&pos);
            continue;

        case OP_GetFloat:
            top++;
            top->type = VAR_FLOAT;
            top->u.floatValue = vm_read_float(&pos);
            continue;

        case OP_GetString:
            top++;
            top->type = VAR_STRING;
            top->u.stringValue = vm_read_ushort(&pos);
            SL_AddRefToString(top->u.stringValue);
            continue;

        case OP_GetIString:
            top++;
            top->type = VAR_ISTRING;
            top->u.stringValue = vm_read_ushort(&pos);
            SL_AddRefToString(top->u.stringValue);
            continue;

        case OP_GetVector:
            top++;
            top->type = VAR_VECTOR;
            top->u.vectorValue = vm_read_vector(&pos);
            continue;

        case OP_GetLevelObject:
            objectId = scrVarPub->levelId;
            continue;

        case OP_GetAnimObject:
            objectId = scrVarPub->animId;
            continue;

        case OP_GetSelf:
            top++;
            top->type = VAR_POINTER;
            top->u.pointerValue = Scr_GetSelf(localId);
            AddRefToObject(top->u.pointerValue);
            continue;

        case OP_GetLevel:
            top++;
            top->type = VAR_POINTER;
            top->u.pointerValue = scrVarPub->levelId;
            AddRefToObject(scrVarPub->levelId);
            continue;

        case OP_GetGame:
            top++;
            *top = Scr_EvalVariable(scrVarPub->gameId);
            continue;

        case OP_GetAnim:
            top++;
            top->type = VAR_POINTER;
            top->u.pointerValue = scrVarPub->animId;
            AddRefToObject(scrVarPub->animId);
            continue;

        case OP_GetAnimation:
            top++;
            top->type = VAR_ANIMATION;
            top->u.pointerValue = vm_read_uint(&pos);
            continue;

        case OP_GetGameRef:
            fieldValueId = scrVarPub->gameId;
            continue;

        case OP_GetFunction:
            top++;
            top->type = VAR_FUNCTION;
            top->u.codePosValue = vm_read_codepos(&pos);
            continue;

        case OP_CreateLocalVariable:
            scrVmPub->localVars++;
            localVarCount++;
            *scrVmPub->localVars = GetNewVariable(localId, vm_read_ushort(&pos));
            continue;

        case OP_RemoveLocalVariables:
            removeCount = (unsigned int)(unsigned char)*pos++;
            scrVmPub->localVars -= removeCount;
            localVarCount -= removeCount;
            while (removeCount)
            {
                RemoveNextVariable(localId);
                removeCount--;
            }
            continue;

        case OP_EvalLocalVariableCached0:
            top++;
            *top = Scr_EvalVariable(Scr_GetLocalVarAtIndex(0));
            continue;

        case OP_EvalLocalVariableCached1:
            top++;
            *top = Scr_EvalVariable(Scr_GetLocalVarAtIndex(1));
            continue;

        case OP_EvalLocalVariableCached2:
            top++;
            *top = Scr_EvalVariable(Scr_GetLocalVarAtIndex(2));
            continue;

        case OP_EvalLocalVariableCached3:
            top++;
            *top = Scr_EvalVariable(Scr_GetLocalVarAtIndex(3));
            continue;

        case OP_EvalLocalVariableCached4:
            top++;
            *top = Scr_EvalVariable(Scr_GetLocalVarAtIndex(4));
            continue;

        case OP_EvalLocalVariableCached5:
            top++;
            *top = Scr_EvalVariable(Scr_GetLocalVarAtIndex(5));
            continue;

        case OP_EvalLocalVariableCached:
            top++;
            *top = Scr_EvalVariable(Scr_GetLocalVar(pos));
            pos++;
            continue;

        case OP_EvalLocalArrayCached:
            top++;
            *top = Scr_EvalVariable(Scr_GetLocalVar(pos));
            pos++;
            Scr_EvalArray(top, top - 1);
            top--;
            continue;

        case OP_EvalArray:
            Scr_EvalArray(top, top - 1);
            top--;
            continue;

        case OP_EvalLocalArrayRefCached0:
            fieldValueId = Scr_EvalArrayIndex(Scr_EvalArrayRef(Scr_GetLocalVarAtIndex(0)), top);
            top--;
            continue;

        case OP_EvalLocalArrayRefCached:
            fieldValueId = Scr_EvalArrayIndex(Scr_EvalArrayRef(Scr_GetLocalVar(pos++)), top);
            top--;
            continue;

        case OP_EvalArrayRef:
            fieldValueId = Scr_EvalArrayIndex(Scr_EvalArrayRef(fieldValueId), top);
            top--;
            continue;

        case OP_ClearArray:
            ClearArray(fieldValueId, top);
            top--;
            continue;

        case OP_EmptyArray:
            top++;
            top->type = VAR_POINTER;
            top->u.pointerValue = Scr_AllocArray();
            continue;

        case OP_GetSelfObject:
            objectId = Scr_GetSelf(localId);
            if (!IsFieldObject(objectId))
            {
                Scr_Error(va("%s is not an object", var_typename[GetObjectType(objectId)]));
                goto vm_error;
            }
            continue;

        case OP_EvalLevelFieldVariable:
            top++;
            *top = Scr_EvalVariable(FindVariable(scrVarPub->levelId, vm_read_ushort(&pos)));
            continue;

        case OP_EvalAnimFieldVariable:
            top++;
            *top = Scr_EvalVariable(FindVariable(scrVarPub->animId, vm_read_ushort(&pos)));
            continue;

        case OP_EvalSelfFieldVariable:
            objectId = Scr_GetSelf(localId);
            if (!IsFieldObject(objectId))
            {
                top++;
                vm_read_ushort(&pos);
                Scr_Error(va("%s is not an object", var_typename[GetObjectType(objectId)]));
                goto vm_error;
            }
            top++;
            *top = Scr_FindVariableField(objectId, vm_read_ushort(&pos));
            continue;

        case OP_EvalFieldVariable:
            top++;
            *top = Scr_FindVariableField(objectId, vm_read_ushort(&pos));
            continue;

        case OP_EvalLevelFieldVariableRef:
            fieldValueId = Scr_GetVariableField(scrVarPub->levelId, vm_read_ushort(&pos));
            continue;

        case OP_EvalAnimFieldVariableRef:
            fieldValueId = Scr_GetVariableField(scrVarPub->animId, vm_read_ushort(&pos));
            continue;

        case OP_EvalSelfFieldVariableRef:
            fieldValueId = Scr_GetVariableField(Scr_GetSelf(localId), vm_read_ushort(&pos));
            continue;

        case OP_EvalFieldVariableRef:
            fieldValueId = Scr_GetVariableField(objectId, vm_read_ushort(&pos));
            continue;

        case OP_ClearFieldVariable:
            ClearVariableField(objectId, vm_read_ushort(&pos), top);
            continue;

        case OP_SafeCreateVariableFieldCached:
            scrVmPub->localVars++;
            localVarCount++;
            *scrVmPub->localVars = GetNewVariable(localId, vm_read_ushort(&pos));
            if (top->type != VAR_PRECODEPOS)
            {
                SetVariableValue(Scr_GetLocalVarAtIndex(0), top);
                top--;
            }
            continue;

        case OP_SafeSetVariableFieldCached0:
            if (top->type != VAR_PRECODEPOS)
            {
                SetVariableValue(Scr_GetLocalVarAtIndex(0), top);
                top--;
            }
            continue;

        case OP_SafeSetVariableFieldCached:
            if (top->type != VAR_PRECODEPOS)
            {
                SetVariableValue(Scr_GetLocalVar(pos), top);
                pos++;
                top--;
                continue;
            }
            pos++;
            continue;

        case OP_SafeSetWaittillVariableFieldCached:
            if (top->type != VAR_CODEPOS)
            {
                SetVariableValue(Scr_GetLocalVar(pos), top);
                pos++;
                top--;
                continue;
            }
            ClearVariableValue(Scr_GetLocalVar(pos));
            pos++;
            continue;

        case OP_clearparams:
            while (top->type != VAR_CODEPOS)
            {
                RemoveRefToValue(top);
                top--;
            }
            continue;

        case OP_checkclearparams:
            if (top->type != VAR_PRECODEPOS)
            {
                Scr_Error("function called with too many parameters");
                goto vm_error;
            }
            top->type = VAR_CODEPOS;
            continue;

        case OP_EvalLocalVariableRefCached0:
            fieldValueId = Scr_GetLocalVarAtIndex(0);
            continue;

        case OP_EvalLocalVariableRefCached:
            fieldValueId = Scr_GetLocalVar(pos);
            pos++;
            continue;

        case OP_SetLevelFieldVariableField:
            SetVariableValue(GetVariable(scrVarPub->levelId, vm_read_ushort(&pos)), top);
            top--;
            continue;

        case OP_SetVariableField:
            SetVariableFieldValue(fieldValueId, top);
            top--;
            continue;

        case OP_SetAnimFieldVariableField:
            SetVariableValue(GetVariable(scrVarPub->animId, vm_read_ushort(&pos)), top);
            top--;
            continue;

        case OP_SetSelfFieldVariableField:
            fieldValueId = Scr_GetVariableField(Scr_GetSelf(localId), vm_read_ushort(&pos));
            SetVariableFieldValue(fieldValueId, top);
            top--;
            continue;

        case OP_SetLocalVariableFieldCached0:
            SetVariableValue(Scr_GetLocalVarAtIndex(0), top);
            top--;
            continue;

        case OP_SetLocalVariableFieldCached:
            SetVariableValue(Scr_GetLocalVar(pos), top);
            pos++;
            top--;
            continue;

        case OP_CallBuiltin0:
        case OP_CallBuiltin1:
        case OP_CallBuiltin2:
        case OP_CallBuiltin3:
        case OP_CallBuiltin4:
        case OP_CallBuiltin5:
            scrVmPub->outparamcount = gOpcode - OP_CallBuiltin0;
            goto vm_CallBuiltin;

        case OP_CallBuiltin:
            scrVmPub->outparamcount = vm_read_byte(&pos);
vm_CallBuiltin:
            scrVmPub->top = top;
            builtinIndex = vm_read_ushort(&pos);
            scrVmPub->function_frame->fs.pos = pos;
            ((void (*)(void))scrCompilePub->func_table[builtinIndex])();
            goto vm_post_builtin;

        case OP_CallBuiltinMethod0:
        case OP_CallBuiltinMethod1:
        case OP_CallBuiltinMethod2:
        case OP_CallBuiltinMethod3:
        case OP_CallBuiltinMethod4:
        case OP_CallBuiltinMethod5:
            scrVmPub->outparamcount = gOpcode - OP_CallBuiltinMethod0;
            goto vm_CallBuiltinMethod;

        case OP_CallBuiltinMethod:
            scrVmPub->outparamcount = vm_read_byte(&pos);
vm_CallBuiltinMethod:
            scrVmPub->top = top - 1;
            builtinIndex = vm_read_ushort(&pos);

            if (top->type != VAR_POINTER)
            {
                RemoveRefToValue(top);
                scrVarPub->error_index = -1;
                Scr_Error(va("%s is not an entity", var_typename[top->type]));
                goto vm_error;
            }

            objectId = top->u.pointerValue;

            if (GetObjectType(objectId) != VAR_ENTITY)
            {
                RemoveRefToObject(objectId);
                scrVarPub->error_index = -1;
                Scr_Error(va("%s is not an entity", var_typename[GetObjectType(objectId)]));
                goto vm_error;
            }

            entref = Scr_GetEntityIdRef(objectId);
            RemoveRefToObject(objectId);
            scrVmPub->function_frame->fs.pos = pos;
            ((void (*)(scr_entref_t))scrCompilePub->func_table[builtinIndex])(entref);
vm_post_builtin:
            top = scrVmPub->top;
            pos = scrVmPub->function_frame->fs.pos;

            if (scrVmPub->outparamcount)
            {
                outparamcount = scrVmPub->outparamcount;
                scrVmPub->outparamcount = 0;
                scrVmPub->top -= outparamcount;

                do
                {
                    RemoveRefToValue(top);
                    top--;
                    outparamcount--;
                }
                while (outparamcount);
            }

            if (scrVmPub->inparamcount)
            {
                scrVmPub->inparamcount = 0;
            }
            else
            {
                top++;
                top->type = VAR_UNDEFINED;
            }
            continue;

        case OP_wait:
            switch (top->type)
            {
            case VAR_FLOAT:
                if (top->u.floatValue < 0)
                {
                    Scr_Error("negative wait is not allowed");
                    goto vm_error;
                }
                waitTime = (int)(top->u.floatValue * WAIT_FRAME_TIME + 0.5f);
                if (!waitTime)
                    waitTime = (top->u.floatValue != 0) ? 1 : 0;
                break;

            case VAR_INTEGER:
                if (top->u.intValue < 0)
                {
                    Scr_Error("negative wait is not allowed");
                    goto vm_error;
                }
                waitTime = top->u.intValue * WAIT_FRAME_TIME;
                break;

            default:
                scrVarPub->error_index = 2;
                Scr_Error(va("type %s is not a float", var_typename[top->type]));
                goto vm_error;
            }

            if (waitTime > (int)VAR_NAME_LOW_MASK)
            {
                scrVarPub->error_index = 2;
                Scr_Error("wait is too long");
                goto vm_error;
            }

            if (waitTime)
                Scr_ResetTimeout();

            waitTime = (scrVarPub->time + waitTime) & VAR_NAME_LOW_MASK;
            top--;

            stackValue.type = VAR_STACK;
            stackValue.u.stackValue = VM_ArchiveStack(top - startTop, pos, top, localVarCount, &localId);

            stackId = GetNewObjectVariable(GetArray(GetVariable(scrVarPub->timeArrayId, waitTime)), localId);
            SetNewVariableValue(stackId, &stackValue);

            Scr_SetThreadWaitTime(localId, waitTime);
            goto vm_thread_end;

        case OP_waittillFrameEnd:
            stackValue.type = VAR_STACK;
            stackValue.u.stackValue = VM_ArchiveStack(top - startTop, pos, top, localVarCount, &localId);

            stackId = GetNewObjectVariableReverse(GetArray(GetVariable(scrVarPub->timeArrayId, scrVarPub->time)), localId);
            SetNewVariableValue(stackId, &stackValue);

            Scr_SetThreadWaitTime(localId, scrVarPub->time);
            goto vm_thread_end;

        case OP_PreScriptCall:
            top++;
            top->type = VAR_PRECODEPOS;
            continue;

        case OP_ScriptFunctionCall2:
            top++;
            top->type = VAR_PRECODEPOS;
            goto vm_scriptFunctionCall;

        case OP_ScriptFunctionCall:
vm_scriptFunctionCall:
            if (scrVmPub->function_count > MAX_EMBEDDED_FUNCTION_CALLS)
            {
                Scr_Error("script stack overflow (too many embedded function calls)");
                goto vm_error;
            }

            selfId = Scr_GetSelf(localId);
            AddRefToObject(selfId);
            localId = AllocChildThread(selfId, localId);

            scrVmPub->function_frame->fs.pos = pos;
            pos = vm_read_codepos(&scrVmPub->function_frame->fs.pos);
            goto vm_function_call;

        case OP_ScriptFunctionCallPointer:
            if (top->type != VAR_FUNCTION)
            {
                Scr_Error(va("%s is not a function pointer", var_typename[top->type]));
                goto vm_error;
            }

            if (scrVmPub->function_count > MAX_EMBEDDED_FUNCTION_CALLS)
            {
                scrVarPub->error_index = 1;
                Scr_Error("script stack overflow (too many embedded function calls)");
                goto vm_error;
            }

            selfId = Scr_GetSelf(localId);
            AddRefToObject(selfId);
            localId = AllocChildThread(selfId, localId);

            scrVmPub->function_frame->fs.pos = pos;
            pos = top->u.codePosValue;
            top--;
            goto vm_function_call;

        case OP_ScriptMethodCall:
            if (top->type != VAR_POINTER)
            {
                scrVarPub->error_index = 1;
                Scr_Error(va("%s is not an object", var_typename[top->type]));
                goto vm_error;
            }

            if (scrVmPub->function_count > MAX_EMBEDDED_FUNCTION_CALLS)
            {
                Scr_Error("script stack overflow (too many embedded function calls)");
                goto vm_error;
            }

            localId = AllocChildThread(top->u.pointerValue, localId);
            top--;

            scrVmPub->function_frame->fs.pos = pos;
            pos = vm_read_codepos(&scrVmPub->function_frame->fs.pos);
            goto vm_function_call;

        case OP_ScriptMethodCallPointer:
            if (top->type != VAR_FUNCTION)
            {
                RemoveRefToValue(top);
                top--;
                value = top + 1;
                Scr_Error(va("%s is not a function pointer", var_typename[value->type]));
                goto vm_error;
            }

            tempCodePos = top->u.codePosValue;
            top--;

            if (top->type != VAR_POINTER)
            {
                scrVarPub->error_index = 2;
                Scr_Error(va("%s is not an object", var_typename[top->type]));
                goto vm_error;
            }

            if (scrVmPub->function_count > MAX_EMBEDDED_FUNCTION_CALLS)
            {
                scrVarPub->error_index = 1;
                Scr_Error("script stack overflow (too many embedded function calls)");
                goto vm_error;
            }

            localId = AllocChildThread(top->u.pointerValue, localId);
            top--;

            scrVmPub->function_frame->fs.pos = pos;
            pos = tempCodePos;
            goto vm_function_call;

        case OP_ScriptThreadCall:
            if (scrVmPub->function_count > MAX_EMBEDDED_FUNCTION_CALLS)
            {
                scrVarPub->error_index = 1;
                Scr_Error("script stack overflow (too many embedded function calls)");
                goto vm_error;
            }

            selfId = Scr_GetSelf(localId);
            AddRefToObject(selfId);
            localId = AllocThread(selfId);

            scrVmPub->function_frame->fs.pos = pos;
            scrVmPub->function_frame->fs.startTop = startTop;

            pos = vm_read_codepos(&scrVmPub->function_frame->fs.pos);
            startTop = &top[-(int)vm_read_uint(&scrVmPub->function_frame->fs.pos)];
            goto vm_thread_call;

        case OP_ScriptThreadCallPointer:
            if (top->type != VAR_FUNCTION)
            {
                Scr_Error(va("%s is not a function pointer", var_typename[top->type]));
                goto vm_error;
            }

            if (scrVmPub->function_count > MAX_EMBEDDED_FUNCTION_CALLS)
            {
                scrVarPub->error_index = 1;
                Scr_Error("script stack overflow (too many embedded function calls)");
                goto vm_error;
            }

            tempCodePos = top->u.codePosValue;
            top--;

            selfId = Scr_GetSelf(localId);
            AddRefToObject(selfId);
            localId = AllocThread(selfId);

            scrVmPub->function_frame->fs.pos = pos;
            scrVmPub->function_frame->fs.startTop = startTop;

            pos = tempCodePos;
            startTop = &top[-(int)vm_read_uint(&scrVmPub->function_frame->fs.pos)];
            goto vm_thread_call;

        case OP_ScriptMethodThreadCall:
            if (top->type != VAR_POINTER)
            {
                scrVarPub->error_index = 2;
                Scr_Error(va("%s is not an object", var_typename[top->type]));
                goto vm_error;
            }

            if (scrVmPub->function_count > MAX_EMBEDDED_FUNCTION_CALLS)
            {
                scrVarPub->error_index = 1;
                Scr_Error("script stack overflow (too many embedded function calls)");
                goto vm_error;
            }

            localId = AllocThread(top->u.pointerValue);
            top--;

            scrVmPub->function_frame->fs.pos = pos;
            scrVmPub->function_frame->fs.startTop = startTop;

            pos = vm_read_codepos(&scrVmPub->function_frame->fs.pos);
            startTop = &top[-(int)vm_read_uint(&scrVmPub->function_frame->fs.pos)];
            goto vm_thread_call;

        case OP_ScriptMethodThreadCallPointer:
            if (top->type != VAR_FUNCTION)
            {
                RemoveRefToValue(top);
                top--;
                value = top + 1;
                Scr_Error(va("%s is not a function pointer", var_typename[value->type]));
                goto vm_error;
            }

            tempCodePos = top->u.codePosValue;
            top--;

            if (top->type != VAR_POINTER)
            {
                scrVarPub->error_index = 2;
                Scr_Error(va("%s is not an object", var_typename[top->type]));
                goto vm_error;
            }

            if (scrVmPub->function_count > MAX_EMBEDDED_FUNCTION_CALLS)
            {
                scrVarPub->error_index = 1;
                Scr_Error("script stack overflow (too many embedded function calls)");
                goto vm_error;
            }

            localId = AllocThread(top->u.pointerValue);
            top--;

            scrVmPub->function_frame->fs.pos = pos;
            scrVmPub->function_frame->fs.startTop = startTop;

            pos = tempCodePos;
            startTop = &top[-(int)vm_read_uint(&scrVmPub->function_frame->fs.pos)];
            goto vm_thread_call;

        case OP_DecTop:
            RemoveRefToValue(top);
            top--;
            continue;

        case OP_CastFieldObject:
            objectId = Scr_EvalFieldObject(scrVarPub->tempVariable, top);
            top--;
            continue;

        case OP_EvalLocalVariableObjectCached:
            objectId = Scr_EvalVariableObject(Scr_GetLocalVar(pos));
            pos++;
            continue;

        case OP_CastBool:
            Scr_CastBool(top);
            continue;

        case OP_BoolNot:
            Scr_EvalBoolNot(top);
            continue;

        case OP_BoolComplement:
            Scr_EvalBoolComplement(top);
            continue;

        case OP_JumpOnFalse:
            Scr_CastBool(top);
            jumpOffset = (int)vm_read_ushort(&pos);
            if (!top->u.intValue)
                pos += jumpOffset;
            top--;
            continue;

        case OP_JumpOnTrue:
            Scr_CastBool(top);
            jumpOffset = (int)vm_read_ushort(&pos);
            if (top->u.intValue)
                pos += jumpOffset;
            top--;
            continue;

        case OP_JumpOnFalseExpr:
            Scr_CastBool(top);
            jumpOffset = (int)vm_read_ushort(&pos);
            if (top->u.intValue)
            {
                top--;
                continue;
            }
            pos += jumpOffset;
            continue;

        case OP_JumpOnTrueExpr:
            Scr_CastBool(top);
            jumpOffset = (int)vm_read_ushort(&pos);
            if (!top->u.intValue)
            {
                top--;
                continue;
            }
            pos += jumpOffset;
            continue;

        case OP_jump:
            jumpOffset = (int)vm_read_uint(&pos);
            pos += jumpOffset;
            continue;

        case OP_jumpback:
            if ((unsigned int)(Sys_Milliseconds() - *(unsigned int *)((char *)scrVmGlob + 24)) < INFINITE_LOOP_TIMEOUT)
            {
                jumpOffset = (int)vm_read_ushort(&pos);
                pos -= jumpOffset;
                continue;
            }

            if (*(int *)((char *)scrVmGlob + 20)) /* loading */
            {
                Com_Printf("script runtime warning: potential infinite loop in script.\n");
                Scr_PrintPrevCodePos(CON_CHANNEL_DONT_FILTER, pos, 0);
                jumpOffset = (int)vm_read_ushort(&pos);
                pos -= jumpOffset;
                Scr_ResetTimeout();
                continue;
            }

            if (scrVmPub->abort_on_error)
            {
                Scr_TerminalError("potential infinite loop in script");
                goto vm_error;
            }

            Com_Printf("script runtime error: potential infinite loop in script - killing thread.\n");
            Scr_PrintPrevCodePos(CON_CHANNEL_DONT_FILTER, pos, 0);
            Scr_ResetTimeout();

            while (1)
            {
                parentLocalId = GetSafeParentLocalId(localId);
                Scr_KillThread(localId);

                scrVmPub->localVars -= localVarCount;

                while (top->type != VAR_CODEPOS)
                {
                    RemoveRefToValue(top);
                    top--;
                }

                scrVmPub->function_count--;
                scrVmPub->function_frame--;

                if (!parentLocalId)
                    break;

                RemoveRefToObject(localId);

                pos = scrVmPub->function_frame->fs.pos;
                localVarCount = scrVmPub->function_frame->fs.localVarCount;
                localId = parentLocalId;
                top--;
            }

            goto vm_thread_end;

        case OP_inc:
            top++;
            *top = Scr_EvalVariableField(fieldValueId);
            if (top->type != VAR_INTEGER)
            {
                Scr_Error(va("++ must be applied to an int (applied to %s)", var_typename[top->type]));
                goto vm_error;
            }
            top->u.intValue++;
            pos++; /* skip OP_SetVariableField */
            SetVariableFieldValue(fieldValueId, top);
            top--;
            continue;

        case OP_dec:
            top++;
            *top = Scr_EvalVariableField(fieldValueId);
            if (top->type != VAR_INTEGER)
            {
                Scr_Error(va("-- must be applied to an int (applied to %s)", var_typename[top->type]));
                goto vm_error;
            }
            top->u.intValue--;
            pos++; /* skip OP_SetVariableField */
            SetVariableFieldValue(fieldValueId, top);
            top--;
            continue;

        case OP_bit_or:
            Scr_EvalOr(top - 1, top);
            top--;
            continue;

        case OP_bit_ex_or:
            Scr_EvalExOr(top - 1, top);
            top--;
            continue;

        case OP_bit_and:
            Scr_EvalAnd(top - 1, top);
            top--;
            continue;

        case OP_equality:
            Scr_EvalEquality(top - 1, top);
            top--;
            continue;

        case OP_inequality:
            Scr_EvalInequality(top - 1, top);
            top--;
            continue;

        case OP_less:
            Scr_EvalLess(top - 1, top);
            top--;
            continue;

        case OP_greater:
            Scr_EvalGreater(top - 1, top);
            top--;
            continue;

        case OP_less_equal:
            Scr_EvalLessEqual(top - 1, top);
            top--;
            continue;

        case OP_greater_equal:
            Scr_EvalGreaterEqual(top - 1, top);
            top--;
            continue;

        case OP_shift_left:
            Scr_EvalShiftLeft(top - 1, top);
            top--;
            continue;

        case OP_shift_right:
            Scr_EvalShiftRight(top - 1, top);
            top--;
            continue;

        case OP_plus:
            Scr_EvalPlus(top - 1, top);
            top--;
            continue;

        case OP_minus:
            Scr_EvalMinus(top - 1, top);
            top--;
            continue;

        case OP_multiply:
            Scr_EvalMultiply(top - 1, top);
            top--;
            continue;

        case OP_divide:
            Scr_EvalDivide(top - 1, top);
            top--;
            continue;

        case OP_mod:
            Scr_EvalMod(top - 1, top);
            top--;
            continue;

        case OP_size:
            Scr_EvalSizeValue(top);
            continue;

        case OP_waittillmatch:
        case OP_waittill:
            if (top->type != VAR_POINTER)
            {
                scrVarPub->error_index = 2;
                Scr_Error(va("%s is not an object", var_typename[top->type]));
                goto vm_error;
            }

            if (!IsFieldObject(top->u.pointerValue))
            {
                scrVarPub->error_index = 2;
                Scr_Error(va("%s is not an object", var_typename[GetObjectType(top->u.pointerValue)]));
                goto vm_error;
            }

            tempValue.u = top->u;
            top--;

            if (top->type != VAR_STRING)
            {
                top++;
                scrVarPub->error_index = 3;
                Scr_Error("first parameter of waittill must evaluate to a string");
                goto vm_error;
            }

            stringValue = top->u.stringValue;
            top--;

            stackValue.type = VAR_STACK;
            stackValue.u.stackValue = VM_ArchiveStack(top - startTop, pos, top, localVarCount, &localId);

            stackId = GetNewObjectVariable(
                GetArray(GetVariable(GetArray(GetVariable(tempValue.u.pointerValue, OBJECT_NOTIFY_LIST)), stringValue)),
                localId);
            SetNewVariableValue(stackId, &stackValue);

            tempValue.type = VAR_POINTER;
            SetNewVariableValue(
                GetNewObjectVariable(GetArray(GetObjectVariable(scrVarPub->pauseArrayId, Scr_GetSelf(localId))), localId),
                &tempValue);

            Scr_SetThreadNotifyName(localId, stringValue);
            goto vm_thread_end;

        case OP_notify:
            if (top->type != VAR_POINTER)
            {
                scrVarPub->error_index = 2;
                Scr_Error(va("%s is not an object", var_typename[top->type]));
                goto vm_error;
            }

            id = top->u.pointerValue;

            if (!IsFieldObject(id))
            {
                scrVarPub->error_index = 2;
                Scr_Error(va("%s is not an object", var_typename[GetObjectType(id)]));
                goto vm_error;
            }

            top--;

            if (top->type != VAR_STRING)
            {
                top++;
                scrVarPub->error_index = 1;
                Scr_Error("first parameter of notify must evaluate to a string");
                goto vm_error;
            }

            stringValue = top->u.stringValue;
            top--;

            scrVmPub->function_frame->fs.pos = pos;
            VM_Notify(id, stringValue, top);
            pos = scrVmPub->function_frame->fs.pos;

            RemoveRefToObject(id);
            SL_RemoveRefToString(stringValue);

            while (top->type != VAR_PRECODEPOS)
            {
                RemoveRefToValue(top);
                top--;
            }
            top--;
            continue;

        case OP_endon:
            if (top->type != VAR_POINTER)
            {
                scrVarPub->error_index = 1;
                Scr_Error(va("%s is not an object", var_typename[top->type]));
                goto vm_error;
            }

            if (!IsFieldObject(top->u.pointerValue))
            {
                scrVarPub->error_index = 1;
                Scr_Error(va("%s is not an object", var_typename[GetObjectType(top->u.pointerValue)]));
                goto vm_error;
            }

            value = top - 1;
            if (value->type != VAR_STRING)
            {
                Scr_Error("first parameter of endon must evaluate to a string");
                goto vm_error;
            }

            stringValue = value->u.stringValue;
            AddRefToObject(localId);
            threadId = AllocThread(localId);

            GetObjectVariable(GetArray(GetVariable(GetArray(GetVariable(top->u.pointerValue, OBJECT_NOTIFY_LIST)), stringValue)), threadId);
            RemoveRefToObject(threadId);

            tempValue.type = VAR_POINTER;
            tempValue.u = top->u;
            SetNewVariableValue(
                GetNewObjectVariable(GetArray(GetObjectVariable(scrVarPub->pauseArrayId, localId)), threadId),
                &tempValue);
            Scr_SetThreadNotifyName(threadId, stringValue);

            top -= 2;
            continue;

        case OP_voidCodepos:
            top++;
            top->type = VAR_PRECODEPOS;
            continue;

        case OP_switch:
            jumpOffset = (int)vm_read_uint(&pos);
            pos += jumpOffset;

            gCaseCount = (int)vm_read_ushort(&pos);

            switch (top->type)
            {
            case VAR_STRING:
                caseValue = top->u.stringValue;
                SL_RemoveRefToString(caseValue);
                break;

            case VAR_INTEGER:
                if (!IsValidArrayIndex(top->u.pointerValue))
                {
                    Scr_Error(va("switch index %d out of range", top->u.intValue));
                    goto vm_error;
                }
                caseValue = GetInternalVariableIndex(top->u.pointerValue);
                break;

            default:
                Scr_Error(va("cannot switch on %s", var_typename[top->type]));
                goto vm_error;
            }

            if (!gCaseCount)
            {
                top--;
                continue;
            }

            {
                int matched = 0;
                do
                {
                    currentCaseValue = vm_read_uint(&pos);
                    currentCodePos = vm_read_codepos(&pos);

                    if (currentCaseValue == caseValue)
                    {
                        pos = currentCodePos;
                        matched = 1;
                        break;
                    }
                    gCaseCount--;
                }
                while (gCaseCount);

                if (!matched && !currentCaseValue)
                    pos = currentCodePos;
            }

            top--;
            continue;

        case OP_endswitch:
            gCaseCount = (int)vm_read_ushort(&pos);
            pos += 8 * gCaseCount; /* skip 2 * gCaseCount ints */
            continue;

        case OP_vector:
            top -= 2;
            Scr_CastVector(top);
            continue;

        case OP_NOP:
            continue;

        case OP_abort:
            g_script_error_level--;
            return 0;

        case OP_object:
            top++;
            classnum = vm_read_uint(&pos);
            entnum  = (int)vm_read_uint(&pos);
            top->u.pointerValue = FindEntityId(entnum, classnum);
            if (!top->u.pointerValue)
            {
                top->type = VAR_UNDEFINED;
                Scr_Error("unknown object");
                goto vm_error;
            }
            top->type = VAR_POINTER;
            AddRefToObject(top->u.pointerValue);
            continue;

        case OP_thread_object:
            top++;
            top->u.pointerValue = vm_read_ushort(&pos);
            top->type = VAR_POINTER;
            AddRefToObject(top->u.pointerValue);
            continue;

        case OP_EvalLocalVariable:
            top++;
            *top = Scr_EvalVariable(FindVariable(localId, vm_read_ushort(&pos)));
            continue;

        case OP_EvalLocalVariableRef:
            fieldValueId = FindVariable(localId, vm_read_ushort(&pos));
            if (!fieldValueId)
            {
                Scr_Error("cannot create a new local variable in the debugger");
                goto vm_error;
            }
            continue;

        case OP_prof_begin:
            pos++;
            continue;

        case OP_prof_end:
            pos++;
            continue;

        case OP_breakpoint:
        case OP_assignmentBreakpoint:
        case OP_manualAndAssignmentBreakpoint:
            if (scrVarPub->developer)
            {
                Com_PrintMessage(CON_CHANNEL_DONT_FILTER, "\nCode hit debug breakpoint at:\n");
                Scr_PrintPrevCodePos(CON_CHANNEL_DONT_FILTER, pos, 0);
            }
            continue;

        default:
            scrVmPub->terminal_error = 1;
            RuntimeErrorInternal(CON_CHANNEL_DONT_FILTER, pos, 0, va("CODE ERROR: unknown opcode %d", gOpcode));
            continue;
        }

        /* shared function call paths */
vm_function_call:
        scrVmPub->function_frame->fs.localVarCount = localVarCount;
        localVarCount = 0;
        scrVmPub->function_count++;
        scrVmPub->function_frame++;
        scrVmPub->function_frame->fs.localId = localId;
        continue;

vm_thread_call:
        scrVmPub->function_frame->fs.top = startTop;
        scrVmPub->function_frame->topType = startTop->type;
        startTop->type = VAR_PRECODEPOS;
        gParamCount++;
        goto vm_function_call;

vm_thread_end:
        value = startTop + 1;
        value->type = VAR_UNDEFINED;
        g_script_error_level--;
        return localId;

vm_error:
        /* longjmp to error handler at top of function */
        longjmp(g_script_error[g_script_error_level], 1);
        /* unreachable */
        return 0;
    }
}

/*
 * VM_Execute (3-arg wrapper) - ref: scr_vm.cpp line 2946
 * Replaces the stub Scr_ExecThread with a real implementation.
 */
unsigned int VM_Execute_wrapper(unsigned int localId, const char *pos, unsigned int paramcount)
{
    int type;
    VariableValue *startTop;
    struct scrVarPub_t *scrVarPub = SCR_VAR_PUB;
    struct scrVmPub_t  *scrVmPub  = SCR_VM_PUB;

    Scr_ClearOutParams();

    startTop = &scrVmPub->top[-paramcount];
    paramcount = scrVmPub->inparamcount - paramcount;

    /* overflow check */
    if (scrVmPub->function_count >= MAX_EMBEDDED_FUNCTION_CALLS)
    {
        Scr_KillThread(localId);
        scrVmPub->inparamcount = paramcount + 1;

        while (paramcount)
        {
            RemoveRefToValue(scrVmPub->top);
            scrVmPub->top--;
            paramcount--;
        }

        scrVmPub->top++;
        scrVmPub->top->type = VAR_UNDEFINED;

        RuntimeError(pos, 0, "script stack overflow (too many embedded function calls)", NULL);
        return localId;
    }

    if (scrVmPub->function_count)
    {
        scrVmPub->function_count++;
        scrVmPub->function_frame++;
        scrVmPub->function_frame->fs.localId = 0;
    }

    scrVmPub->function_frame->fs.pos = pos;

    scrVmPub->function_count++;
    scrVmPub->function_frame++;

    scrVmPub->function_frame->fs.localId = localId;

    type = startTop->type;
    startTop->type = VAR_PRECODEPOS;

    scrVmPub->inparamcount = 0;

    localId = VM_Execute_internal(pos, localId, 0, scrVmPub->top, startTop);

    startTop->type = type;
    scrVmPub->top = startTop + 1;

    scrVmPub->inparamcount = paramcount + 1;

    ClearVariableValue(scrVarPub->tempVariable);

    if (scrVmPub->function_count)
    {
        scrVmPub->function_count--;
        scrVmPub->function_frame--;
    }

    return localId;
}
