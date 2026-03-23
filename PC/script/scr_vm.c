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
static VariableStackBuffer * VM_ArchiveStack(int size, VariableValue *top, unsigned int localVarCount, unsigned int *pLocalId);
static void VM_TerminateStack(unsigned int endLocalId, unsigned int startLocalId, VariableStackBuffer *stackValue);
static void VM_TrimStack(unsigned int startLocalId, VariableStackBuffer *stackValue, Bool fromEndon);
static void Scr_CancelWaittill(void);
void Scr_CancelNotifyList(unsigned int notifyListOwnerId);
void Scr_FreeThread(int handle);
void Scr_InitSystem(int sys);
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
