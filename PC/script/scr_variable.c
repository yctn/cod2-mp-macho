/* ASM dump from: scr_variable.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/script/scr_variable.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/script/scr_variable.h"
 */

extern const char * var_typename[24]; /* 0x0 */
extern struct scrVarPub_t scrVarPub; /* 0x0 */
extern scr_classStruct_t g_classMap[4]; /* 0x0 */
extern unsigned char scrVarGlob[]; /* scrVarGlob - base of 16-byte variable entries */

/* DBG: allocation counter for debugging script variable exhaustion */
int dbg_alloc_counter = 0;
static const char str_dbg_alloc_fmt[] = "DBG AllocValue exhausted after %d allocations\n";
static const char str_dbg_site_classmap1[] = "DBG exceeded at: Scr_SetClassMap site1\n";
static const char str_dbg_site_classmap2[] = "DBG exceeded at: Scr_SetClassMap site2\n";
static const char str_dbg_site_gamvar1[] = "DBG exceeded at: Scr_AllocGameVariable site1\n";
static const char str_dbg_site_gamvar2[] = "DBG exceeded at: Scr_AllocGameVariable site2\n";
static const char str_dbg_getvar_fmt[] = "DBG GetVariable #%d: parentId=%d name=%d freeHead=%d\n";
int dbg_getvar_counter = 0;

extern void * MT_Alloc(int size, int type);
extern void MT_Free(void *ptr, int type);
extern char * va(const char *format, ...);
extern void Scr_Error(const char *msg);
extern void SL_AddRefToString(unsigned int stringValue);
extern void SL_RemoveRefToString(unsigned int stringValue);

int GetVarType(unsigned int id);
static int ThreadInfoCompare(const JCOEF *info1, const JCOEF *info2);
unsigned int FindNextSibling(unsigned int id);
JCOEF Scr_DumpScriptVariables(void);
JCOEF Var_Init(void);
unsigned int Scr_GetNumScriptVars(void);
unsigned int GetVariableKeyObject(unsigned int id);
JCOEF AddRefToObject(unsigned int id);
void Scr_SetThreadNotifyName(unsigned int startLocalId, unsigned int stringValue);
short unsigned int Scr_GetThreadNotifyName(unsigned int startLocalId);
void Scr_SetThreadWaitTime(unsigned int startLocalId, unsigned int waitTime);
void Scr_ClearWaitTime(unsigned int startLocalId);
unsigned int Scr_GetThreadWaitTime(unsigned int startLocalId);
unsigned int GetParentLocalId(unsigned int threadId);
unsigned int GetSafeParentLocalId(unsigned int threadId);
unsigned int GetStartLocalId(unsigned int threadId);
unsigned int FindObject(unsigned int id);
VariableUnion * GetVariableValueAddress(unsigned int id);
JCOEF RemoveRefToEmptyObject(unsigned int id);
unsigned int Scr_GetSelf(unsigned int threadId);
void RemoveRefToVector(const float *vectorValue);
Bool IsValidArrayIndex(unsigned int unsignedValue);
unsigned int GetInternalVariableIndex(unsigned int unsignedValue);
void SetNewVariableValue(unsigned int id, VariableValue *value);
unsigned int Scr_EvalVariableObject(unsigned int id);
unsigned int GetArraySize(unsigned int id);
unsigned int FindPrevSibling(unsigned int id);
unsigned int GetVariableName(unsigned int id);
Bool IsFieldObject(unsigned int id);
Bool IsVarFree(unsigned int id);
struct scr_entref_t Scr_GetEntityIdRef(unsigned int entId);
unsigned int Scr_FindField(const char *name, int *type);
int Scr_GetClassnumForCharId(int charId);
void Scr_RemoveThreadNotifyName(unsigned int startLocalId);
void AddRefToValue(int type, VariableUnion u);
const float * Scr_AllocVector(const float *v);
int Scr_GetOffset(int classnum, const char *name);
unsigned int FindEntityId(int entnum, int classnum);
unsigned int FindArrayVariable(unsigned int parentId, int intValue);
unsigned int FindVariable(unsigned int parentId, unsigned int unsignedValue);
unsigned int FindObjectVariable(unsigned int parentId, unsigned int id);
JCOEF Scr_AddFields(const char *path, const char *extension);
VariableValue Scr_EvalVariable(unsigned int id);
static unsigned int GetNewVariableIndexInternal3(unsigned int parentId, unsigned int name, unsigned int index);
unsigned int GetNewObjectVariableReverse(unsigned int parentId, unsigned int id);
unsigned int GetNewObjectVariable(unsigned int parentId, unsigned int id);
JCOEF SetVariableEntityFieldValue(unsigned int entId, unsigned int fieldName, VariableValue *value);
JCOEF Scr_AddClassField(int classnum, const char *name, unsigned int offset);
unsigned int GetNewArrayVariable(unsigned int parentId, unsigned int unsignedValue);
unsigned int GetNewVariable(unsigned int parentId, unsigned int unsignedValue);
static float Scr_GetObjectUsage(void);
JCOEF Scr_DumpScriptThreads(void);
unsigned int Scr_GetEntityId(int entnum, int classnum);
unsigned int Scr_EvalArrayIndex(unsigned int parentId, VariableValue *index);
unsigned int Scr_GetVariableField(unsigned int parentId, unsigned int name);
unsigned int GetArrayVariable(unsigned int parentId, unsigned int unsignedValue);
unsigned int GetVariable(unsigned int parentId, unsigned int unsignedValue);
unsigned int GetObjectVariable(unsigned int parentId, unsigned int id);
static JCOEF CopyArray(unsigned int parentId, unsigned int newParentId);
JCOEF Scr_SetClassMap(int classnum);
unsigned int GetArray(unsigned int id);
unsigned int GetObjectA(unsigned int id);
unsigned int AllocValue(void);
unsigned int AllocObject(void);
unsigned int Scr_AllocArray(void);
unsigned int AllocThread(unsigned int self);
unsigned int AllocChildThread(unsigned int self, unsigned int parentLocalId);
static JCOEF MakeVariableExternal(void);
JCOEF RemoveRefToObject(unsigned int id);
JCOEF Scr_FreeValue(unsigned int id);
JCOEF Scr_EvalArray(VariableValue *value, VariableValue *index);
JCOEF Scr_RemoveClassMap(int classnum);
static VariableValue Scr_EvalVariableEntityField(void);
VariableValue Scr_EvalVariableField(unsigned int id);
VariableValue Scr_FindVariableField(unsigned int parentId, unsigned int name);
JCOEF RemoveRefToValue(int type, VariableUnion u);
JCOEF Scr_KillEndonThread(unsigned int threadId);
JCOEF Scr_FreeEntityList(void);
JCOEF SafeRemoveVariable(unsigned int parentId, unsigned int unsignedValue);
JCOEF RemoveNextVariable(unsigned int parentId);
JCOEF RemoveVariable(unsigned int parentId, unsigned int unsignedValue);
static int Scr_MakeValuePrimitive(void);
JCOEF Scr_FreeGameVariable(int bComplete);
JCOEF Scr_FreeEntityNum(int entnum, int classnum);
JCOEF RemoveObjectVariable(unsigned int parentId, unsigned int id);
JCOEF ClearVariableField(unsigned int parentId, unsigned int name, VariableValue *value);
JCOEF Var_Shutdown(void);
JCOEF Scr_FreeObjects(void);
JCOEF Scr_EvalBoolNot(VariableValue *value);
JCOEF SetVariableFieldValue(unsigned int id, VariableValue *value);
JCOEF Scr_AllocGameVariable(void);
unsigned int Scr_EvalArrayRef(unsigned int parentId);
JCOEF Scr_StopThread(unsigned int threadId);
JCOEF ClearObject(unsigned int parentId);
JCOEF Scr_KillThread(unsigned int parentId);
unsigned int Scr_EvalFieldObject(unsigned int tempVariable, VariableValue *value);
Bool Scr_CastString(VariableValue *value);
JCOEF Scr_CastDebugString(VariableValue *value);
JCOEF Scr_UnmatchingTypesError(VariableValue *value1, VariableValue *value2);
JCOEF Scr_EvalMod(VariableValue *value1, VariableValue *value2);
JCOEF Scr_EvalDivide(VariableValue *value1, VariableValue *value2);
JCOEF Scr_EvalPlus(VariableValue *value1, VariableValue *value2);
JCOEF Scr_EvalShiftRight(VariableValue *value1, VariableValue *value2);
JCOEF Scr_EvalShiftLeft(VariableValue *value1, VariableValue *value2);
JCOEF Scr_EvalAnd(VariableValue *value1, VariableValue *value2);
JCOEF Scr_EvalExOr(VariableValue *value1, VariableValue *value2);
JCOEF Scr_EvalOr(VariableValue *value1, VariableValue *value2);
JCOEF Scr_EvalLessEqual(VariableValue *value1, VariableValue *value2);
JCOEF Scr_EvalGreaterEqual(VariableValue *value1, VariableValue *value2);
JCOEF Scr_EvalEquality(VariableValue *value1, VariableValue *value2);
JCOEF Scr_EvalInequality(VariableValue *value1, VariableValue *value2);
JCOEF Scr_EvalLess(VariableValue *value1, VariableValue *value2);
JCOEF Scr_EvalGreater(VariableValue *value1, VariableValue *value2);
JCOEF Scr_EvalMinus(VariableValue *value1, VariableValue *value2);
JCOEF Scr_EvalBinaryOperator(int op, VariableValue *value1, VariableValue *value2);
JCOEF Scr_EvalMultiply(VariableValue *value1, VariableValue *value2);
JCOEF Scr_CastBool(VariableValue *value);
JCOEF Scr_EvalBoolComplement(VariableValue *value);
JCOEF Scr_EvalSizeValue(VariableValue *value);
JCOEF Scr_CastVector(VariableValue *value);
JCOEF FreeValue(unsigned int id);
JCOEF SetVariableValue(unsigned int id, VariableValue *value);
JCOEF ClearVariableValue(unsigned int id);
JCOEF ClearArray(unsigned int parentId, VariableValue *value);

/* line 3584 */
int GetVarType(unsigned int id)
{
    return *(unsigned int *)(((size_t)scrVarGlob + 8) + id * 16) & 0x1f;
}

/* line 361 */
static int ThreadInfoCompare(const JCOEF *info1, const JCOEF *info2) {
    int count1 = *(int *)((byte *)info1 + 0x80); /* JCOEF count at 0x80 */
    int count2 = *(int *)((byte *)info2 + 0x80); /* JCOEF count at 0x80 */
    int i;

    if (count1 <= 0 || count2 <= 0)
        return count1 - count2;

    for (i = 0; i < count1 && i < count2; i++) {
        if (info1[i] != info2[i])
            return info1[i] - info2[i];
    }
    return count1 - count2;
}
