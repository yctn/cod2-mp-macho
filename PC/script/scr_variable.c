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
extern void Com_Printf(const char *fmt, ...);
extern void SL_AddRefToString(unsigned int stringValue);
extern void SL_RemoveRefToString(unsigned int stringValue);

/*
 * scrVarGlob raw accessor macros.
 * Each VariableValueInternal entry is 16 bytes.
 * Layout per entry (byte offsets):
 *   0-1:  hash.id         (unsigned short)
 *   2-3:  hash.u.prev     (unsigned short) -- also word_8294002[8*i]
 *   4-7:  u (VariableUnion / u.next)        -- also dword_8294004[4*i]
 *   8-11: w.status/type   (unsigned int)    -- also dword_8294008[4*i]
 *  12-13: v.next/index    (unsigned short)
 *  14-15: nextSibling     (unsigned short)  -- also word_829400E[8*i]
 */
#define VG_BASE           ((char *)scrVarGlob)
#define VG_ID(i)          (*(unsigned short *)(VG_BASE + (unsigned int)(i)*16 + 0))
#define VG_PREV(i)        (*(unsigned short *)(VG_BASE + (unsigned int)(i)*16 + 2))
#define VG_U32(i)         (*(unsigned int  *)(VG_BASE + (unsigned int)(i)*16 + 4))
#define VG_U16(i)         (*(unsigned short *)(VG_BASE + (unsigned int)(i)*16 + 4))
#define VG_STATUS(i)      (*(unsigned int  *)(VG_BASE + (unsigned int)(i)*16 + 8))
#define VG_VNEXT(i)       (*(unsigned short *)(VG_BASE + (unsigned int)(i)*16 + 12))
#define VG_SIBLING(i)     (*(unsigned short *)(VG_BASE + (unsigned int)(i)*16 + 14))
/* Free-list head is stored in entry[0].u lower 16 bits: VG_U16(0) */

int GetVarType(unsigned int id);
static int ThreadInfoCompare(const JCOEF *info1, const JCOEF *info2);
unsigned int FindNextSibling(unsigned int id);
JCOEF Scr_DumpScriptVariables(void);
void Var_Init(void);
void Var_ResetAll(void);
static unsigned int AllocVariable(void);
static void FreeVariable(unsigned int id);
unsigned int AllocValue(void);
unsigned int AllocObject(void);
unsigned int Scr_AllocArray(void);
unsigned int AllocThread(unsigned int self);
unsigned int AllocChildThread(unsigned int self, unsigned int parentLocalId);
void FreeChildValue(unsigned int id);
static void RemoveRefToValueInternal(unsigned int type, unsigned int u);
void RemoveRefToObject(unsigned int id);
void RemoveRefToEmptyObject(unsigned int id);
void AddRefToObject(unsigned int id);
void ClearObject(unsigned int id);
static void ClearObjectInternal(unsigned int id);
static void RemoveRefToVector(const float *v);
void Var_FreeTempVariables(void);
void Var_Shutdown(void);
void FreeValue(unsigned int id);
unsigned int Scr_GetNumScriptVars(void);
unsigned int GetVariableKeyObject(unsigned int id);
void AddRefToObject(unsigned int id);
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
void RemoveRefToEmptyObject(unsigned int id);
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
void RemoveRefToObject(unsigned int id);
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
void Var_Shutdown(void);
JCOEF Scr_FreeObjects(void);
JCOEF Scr_EvalBoolNot(VariableValue *value);
JCOEF SetVariableFieldValue(unsigned int id, VariableValue *value);
JCOEF Scr_AllocGameVariable(void);
unsigned int Scr_EvalArrayRef(unsigned int parentId);
JCOEF Scr_StopThread(unsigned int threadId);
void ClearObject(unsigned int parentId);
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
void FreeValue(unsigned int id);
JCOEF SetVariableValue(unsigned int id, VariableValue *value);
JCOEF ClearVariableValue(unsigned int id);
JCOEF ClearArray(unsigned int parentId, VariableValue *value);

/* ============================================================
 * Core variable allocation/free system
 * Translated from reference Linux decompilation (cod2_lnxded_1_0.c)
 * Reference: AllocVariable @ 0807B3A8, FreeVariable @ 0807B4A0, etc.
 * ============================================================ */

extern void Scr_TerminalError(const char *error);

/*
 * Var_ResetAll: initialize the scrVarGlob free-list.
 * Builds a circular doubly-linked free list of all 65534 variable entries.
 * ref: Var_ResetAll @ 0807A29E
 */
void Var_ResetAll(void)
{
    unsigned int v1;
    unsigned int i;

    v1 = 0;
    for (i = 1; i <= 0xFFFD; i++) {
        /* entry[i].w.status = 0 */
        VG_STATUS(i) = 0;
        /* entry[i].hash.id = i */
        VG_ID(i) = (unsigned short)i;
        /* entry[i].v.next = i (self-link initially, will be used as sibling) */
        VG_VNEXT(i) = (unsigned short)i;
        /* entry[v1].u lower 16 = i → free-list: after v1 comes i */
        VG_U16(v1) = (unsigned short)i;
        /* entry[i].hash.prev = v1 */
        VG_PREV(i) = (unsigned short)v1;
        v1 = i;
    }
    /* Post-loop: v1 = 0xFFFD = last entry added to free list.
     * entry[0].u_low was set to 1 during the loop (when i=1, v1=0).
     * So freeHead = entry[0].u_low = 1. We must NOT overwrite entry[0].u here. */

    /* Zero entry[0].w.status (ref: *(_DWORD *)&word_8294000[4] = 0) */
    VG_STATUS(0) = 0;
    /* entry[0].hash.id = 0 */
    VG_ID(0) = 0;
    /* entry[0].v.next = 0 */
    VG_VNEXT(0) = 0;
    /* entry[0xFFFD].u lower 16 = 0 → terminate free-list */
    VG_U16(v1) = 0;
    /* entry[0].hash.prev = 0xFFFD */
    VG_PREV(0) = (unsigned short)v1;
    /* freeHead is now entry[0].u_low which equals 1 (set in loop). */
}

/*
 * Var_Init: initialize the script variable system.
 * ref: Var_Init @ 0807A368
 */
void Var_Init(void)
{
    int i;
    Var_ResetAll();
    for (i = 0; i <= 3; i++) {
        /* Clear entArrayId (offset 2 in scr_classStruct_t) */
        ((scr_classStruct_t *)g_classMap)[i].entArrayId = 0;
        /* Clear id (offset 0 in scr_classStruct_t) */
        ((scr_classStruct_t *)g_classMap)[i].id = 0;
    }
}

/*
 * AllocVariable: remove a variable from the free list and return its index.
 * ref: AllocVariable @ 0807B3A8
 */
static unsigned int AllocVariable(void)
{
    unsigned int v5;
    unsigned short v2;
    unsigned int v4_id;
    unsigned int v3_id;

    /* v5 = freeHead = entry[0].u_low (VG_U16(0)) */
    v5 = (unsigned int)VG_U16(0);
    if (!v5)
        Scr_TerminalError("exceeded maximum number of script variables");

    /* v4_id = entry[v5].hash.id
     * (In ref: v4 = &word_8294000[8*v5]; v4_id refers to the entry index) */
    v4_id = (unsigned int)VG_ID(v5);

    /* v3_id = entry[v4_id].hash.id */
    v3_id = (unsigned int)VG_ID(v4_id);

    /* v2 = entry[v3_id].u_low (ref: v3[2] = short at bytes 4-5 of entry[v3_id]) */
    v2 = VG_U16(v3_id);

    /* If v4 != v3 (different entries) and entry[v5].status bits [6:5] == 0: swap */
    if (v4_id != v3_id && (VG_STATUS(v5) & 0x60) == 0) {
        /* v1 = entry[v5].v.next (ref: v4[6]) */
        unsigned short v1 = VG_VNEXT(v5);
        /* entry[v1].hash.id = entry[v5].hash.id (ref: word_8294000[8*v1] = *v4) */
        VG_ID(v1) = VG_ID(v5);
        /* entry[v5].hash.id = v5 (ref: *v4 = v5) */
        VG_ID(v5) = (unsigned short)v5;
        /* entry[v3].v.next = v1 (ref: v3[6] = v1) */
        VG_VNEXT(v3_id) = v1;
        /* entry[v3].u_low = entry[v5].u_low (ref: v3[2] = v4[2]) */
        VG_U16(v3_id) = VG_U16(v5);
        /* Now use v5 as v3 */
        v3_id = v5;
    }

    /* Update free-list head: entry[0].u_low = v2 (next free entry) */
    VG_U16(0) = v2;
    /* entry[v2].hash.prev = 0 (ref: word_8294002[8*v2] = 0) */
    VG_PREV(v2) = 0;
    /* entry[v3_id].v.next = v5 (ref: v3[6] = v5) */
    VG_VNEXT(v3_id) = (unsigned short)v5;
    /* entry[v3_id].nextSibling = v5 (ref: v3[7] = v5) */
    VG_SIBLING(v3_id) = (unsigned short)v5;
    /* entry[v4_id].hash.prev = v5 (ref: v4[1] = v5) */
    VG_PREV(v4_id) = (unsigned short)v5;
    /* Return entry[v4_id].hash.id (ref: return (unsigned short)*v4) */
    return (unsigned int)VG_ID(v4_id);
}

/*
 * FreeVariable: return a variable to the free list.
 * ref: FreeVariable @ 0807B4A0
 */
static void FreeVariable(unsigned int a1)
{
    unsigned short v2, v3, v4, old_fhead;

    /* v2 = entry[a1].v.next (the "back" link; for freshly allocated = a1 itself) */
    v2 = VG_VNEXT(a1);
    /* v4 = entry[v2].hash.prev */
    v4 = VG_PREV(v2);
    /* v3 = entry[a1].nextSibling */
    v3 = VG_SIBLING(a1);

    /* Unlink a1 from sibling chain: repair the two links on either side */
    VG_PREV(v3) = v4;
    VG_SIBLING(VG_ID(v4)) = v3;

    /* Clear status */
    VG_STATUS(a1) = 0;

    /* Insert a1 at front of free list */
    old_fhead = VG_U16(0);
    VG_U16(a1) = old_fhead;        /* a1's next-free = old head */
    VG_PREV(v2) = 0;               /* v2(=a1).hash.prev = 0 */
    VG_PREV(old_fhead) = v2;       /* old_head's prev = v2(=a1) */
    VG_U16(0) = v2;                /* freeHead = v2(=a1) */
}

/*
 * AllocValue: allocate a value slot (type = 0 = undefined).
 * Sets status bits to 0x60 (refcount = 0, no type).
 * ref: AllocValue @ 0807B562
 */
unsigned int AllocValue(void)
{
    unsigned int result = AllocVariable();
    /* Set status = 0x60 (allocated, no type yet) */
    VG_STATUS(result) = 0x60;
    return result;
}

/*
 * AllocObject: allocate an object variable.
 * ref: AllocObject @ 0807B5A0
 */
unsigned int AllocObject(void)
{
    unsigned int result = AllocVariable();
    VG_STATUS(result) = 0x60;
    VG_STATUS(result) |= 0x13;  /* type = 0x13 = 19 (object with children) */
    VG_U16(result) = 0;
    return result;
}

/*
 * Scr_AllocArray: allocate an array variable.
 * ref: Scr_AllocArray @ 0807B658
 */
unsigned int Scr_AllocArray(void)
{
    unsigned int result = AllocVariable();
    VG_STATUS(result) = 0x60;
    VG_STATUS(result) |= 0x16;  /* type = 0x16 = 22 (array) */
    VG_U16(result) = 0;
    VG_SIBLING(result) = 0;     /* no siblings yet */
    return result;
}

/*
 * AllocThread: allocate a thread variable.
 * ref: AllocThread @ 0807B6AC
 */
unsigned int AllocThread(unsigned int self)
{
    unsigned int result = AllocVariable();
    VG_STATUS(result) = 0x60;
    VG_STATUS(result) |= 0x0F;  /* type = 15 (thread) */
    VG_U16(result) = 0;
    VG_SIBLING(result) = (unsigned short)self;
    return result;
}

/*
 * AllocChildThread: allocate a child thread variable.
 * ref: AllocChildThread @ 0807B700
 */
unsigned int AllocChildThread(unsigned int self, unsigned int parentLocalId)
{
    unsigned int result = AllocVariable();
    VG_STATUS(result) = 0x60;
    VG_STATUS(result) |= 0x12;                         /* type = 18 (child thread) */
    VG_STATUS(result) |= (parentLocalId << 8);
    VG_U16(result) = 0;
    VG_SIBLING(result) = (unsigned short)self;
    return result;
}

/*
 * AddRefToObject: increment object refcount.
 * ref: AddRefToObject @ 0807B7DC... actually @ 0807B7BA
 */
void AddRefToObject(unsigned int id)
{
    VG_U16(id) = (unsigned short)(VG_U16(id) + 1);
}

/*
 * RemoveRefToVector: decrement vector refcount, free if zero.
 * ref: RemoveRefToVector @ 0807B9CA
 * Vectors are MT_Alloc(16) blocks; the count is at ptr-4 (short) and
 * a "permanent" flag at ptr-3 (byte).
 */
static void RemoveRefToVector(const float *v)
{
    char *base = (char *)v - 4;
    if (base[3] == 0) {  /* not permanent */
        unsigned short cnt = *(unsigned short *)base;
        if (cnt) {
            cnt--;
            *(unsigned short *)base = cnt;
            if (cnt == 0)
                MT_Free((void *)base, 16);
        }
    }
}

/*
 * RemoveRefToValueInternal: remove a reference from a typed value.
 * ref: RemoveRefToValueInternal @ 0807BA64
 * type: 1=object, 2-3=string, 4=vector
 */
static void RemoveRefToValueInternal(unsigned int type, unsigned int u)
{
    if (type > 3) {
        if (type == 4)
            RemoveRefToVector((const float *)u);
    } else if (type >= 2) {
        SL_RemoveRefToString(u);
    } else if (type == 1) {
        RemoveRefToObject(u);
    }
}

/*
 * RemoveRefToEmptyObject: remove ref without clearing object contents.
 * ref: RemoveRefToEmptyObject @ 0807B8D4
 */
void RemoveRefToEmptyObject(unsigned int id)
{
    unsigned short cnt = VG_U16(id);
    if (!cnt) {
        FreeVariable(id);
    } else {
        VG_U16(id) = (unsigned short)(cnt - 1);
    }
}

/*
 * ClearObjectInternal: free all children of an object.
 * ref: ClearObjectInternal @ 0807AF2A
 * For now this is a simplified implementation that just calls FreeChildValue
 * on each child in the sibling chain.
 */
static void ClearObjectInternal(unsigned int id)
{
    unsigned int child;
    unsigned int next;

    /* Walk the sibling chain starting from entry[entry[id].nextSibling].hash.id */
    child = (unsigned int)VG_ID(VG_SIBLING(id));
    while (child != id) {
        next = (unsigned int)VG_ID(VG_SIBLING(child));
        FreeChildValue(child);
        child = next;
    }
}

/*
 * ClearObject: clear all children of an object, keeping it alive.
 * ref: ClearObject @ 0807AF82
 */
void ClearObject(unsigned int id)
{
    AddRefToObject(id);
    ClearObjectInternal(id);
    RemoveRefToEmptyObject(id);
}

/*
 * RemoveRefToObject: decrement refcount; free if zero.
 * ref: RemoveRefToObject @ 0807B7DC (simplified path)
 */
void RemoveRefToObject(unsigned int id)
{
    unsigned short cnt = VG_U16(id);
    if (cnt) {
        VG_U16(id) = (unsigned short)(cnt - 1);
        if (VG_U16(id) == 0) {
            unsigned int type = VG_STATUS(id) & 0x1F;
            if (type != 21) {
                /* Not an entity: free the object */
                if ((unsigned int)VG_ID(VG_SIBLING(id)) != id)
                    ClearObject(id);
                FreeVariable(id);
            }
            /* type 21 = entity: handled elsewhere */
        }
    } else {
        /* refcount already 0: just free if no children */
        if ((unsigned int)VG_ID(VG_SIBLING(id)) == id)
            FreeVariable(id);
        else
            ClearObject(id);
    }
}

/*
 * FreeChildValue: free a value variable (remove ref to its value, then free the slot).
 * ref: FreeChildValue @ 0807B778
 */
void FreeChildValue(unsigned int id)
{
    unsigned int type = VG_STATUS(id) & 0x1F;
    unsigned int u    = VG_U32(id);
    RemoveRefToValueInternal(type, u);
    FreeVariable(id);
}

/*
 * Var_FreeTempVariables: free the temp variable allocated during VM init.
 * ref: Var_FreeTempVariables @ 0807F8F6
 */
void Var_FreeTempVariables(void)
{
    struct scrVarPub_t *p = (struct scrVarPub_t *)imp_scrVarPub;
    if (p->tempVariable) {
        FreeChildValue(p->tempVariable);
        p->tempVariable = 0;
    }
}

/*
 * FreeValue: free a value slot. Alias for FreeChildValue.
 * Used by Scr_Shutdown to free the temp variable.
 */
void FreeValue(unsigned int id)
{
    FreeChildValue(id);
}

/*
 * Var_Shutdown: free the game variable on shutdown.
 * ref: Var_Shutdown @ 0807A3B6
 */
void Var_Shutdown(void)
{
    struct scrVarPub_t *p = (struct scrVarPub_t *)imp_scrVarPub;
    if (p->gameId) {
        FreeChildValue(p->gameId);
        p->gameId = 0;
    }
}

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

/* RemoveRefToValue: remove a reference from a VariableValue (type, value pair).
 * ref: 0807BA54 */
JCOEF RemoveRefToValue(int type, VariableUnion u)
{
    RemoveRefToValueInternal((unsigned int)type, *(unsigned int *)&u);
    return 0;
}

/* Scr_FreeThread: release a thread's object reference.
 * ref: 08083B00 */
void Scr_FreeThread(unsigned int threadId)
{
    RemoveRefToObject(threadId);
}

/* Scr_ClearOutParams: clear outgoing parameters.
 * ref: 08082520 */
void Scr_ClearOutParams(void)
{
    extern unsigned char scrVmPub[];
    struct scrVarPub_t *pub = (struct scrVarPub_t *)imp_scrVarPub;
    /* In the reference: while(scrVarPub.outparamcount) { RemoveRefToValue(top); top-=8; outparamcount--; } */
    /* For now, just reset the counter */
    /* TODO: proper implementation */
}

/* ClearVariableValue: clear a variable's value in the pool.
 * ref: 08075384 */
JCOEF ClearVariableValue(unsigned int id)
{
    if (id == 0) return 0;
    VG_STATUS(id) = (VG_STATUS(id) & 0x1F00FFFFu);
    return 0;
}

/* ============================================================
 * Hash table lookup and variable management functions.
 * Translated from reference: CoD2rev_Server/src/script/scr_variable.cpp
 * ============================================================ */

/*
 * Constants mirrored from script_public.h (reference).
 * These are not in common_types.h so we define them locally.
 */
#define SCRVL_VAR_STAT_FREE     0x00u
#define SCRVL_VAR_STAT_MOVABLE  0x20u
#define SCRVL_VAR_STAT_HEAD     0x40u
#define SCRVL_VAR_STAT_EXTERNAL 0x60u
#define SCRVL_VAR_STAT_MASK     0x60u
#define SCRVL_VAR_NAME_BITS     8u
#define SCRVL_VAR_NAME_LOW_MASK 0xFFFFFFu
#define SCRVL_VAR_MASK          0x1Fu
#define SCRVL_VAR_UNDEFINED     0u
#define SCRVL_VAR_POINTER       1u
#define SCRVL_VAR_STRING        2u
#define SCRVL_VAR_ARRAY         22u
#define SCRVL_VARIABLELIST_CHILD_SIZE 0xFFFEu
#define SCRVL_SL_MAX_STRING_INDEX     0x10000u
#define SCRVL_OBJECT_NOTIFY_LIST      0x1FFFEu
/* Offset 6 within a 16-byte entry: ObjectInfo.u.size (array element count) */
#define VG_OBJSIZE(i)   (*(unsigned short *)(VG_BASE + (unsigned int)(i)*16 + 6))

/*
 * FindVariableIndexInternal2: walk the hash chain rooted at bucket `index`
 * looking for an entry whose stored name equals `name`.
 * Returns the bucket index if found, 0 if not found.
 * ref: scr_variable.cpp line 3569
 */
static unsigned int FindVariableIndexInternal2(unsigned int name, unsigned int index)
{
    unsigned int headId;
    unsigned int newIndex;
    unsigned int newHeadId;

    /* entry[index].hash.id is the "value" slot that owns this bucket */
    headId = (unsigned int)VG_ID(index);

    /* If the value slot is not a HEAD, this bucket is empty / unused */
    if ((VG_STATUS(headId) & SCRVL_VAR_STAT_MASK) != SCRVL_VAR_STAT_HEAD)
        return 0;

    /* Check the first entry in the chain */
    if ((VG_STATUS(headId) >> SCRVL_VAR_NAME_BITS) == name)
        return index;

    /* Walk movable collision chain: entry[headId].v.index is the next bucket */
    newIndex = (unsigned int)VG_VNEXT(headId);

    while (newIndex != index) {
        newHeadId = (unsigned int)VG_ID(newIndex);
        /* All chained entries must be MOVABLE */
        if ((VG_STATUS(newHeadId) >> SCRVL_VAR_NAME_BITS) == name)
            return newIndex;
        newIndex = (unsigned int)VG_VNEXT(newHeadId);
    }

    return 0;
}

/*
 * FindVariableIndexInternal: entry point for hash lookup.
 * Computes the canonical bucket for (parentId, name) and calls
 * FindVariableIndexInternal2.
 * ref: scr_variable.cpp line 3702
 */
static unsigned int FindVariableIndexInternal(unsigned int parentId, unsigned int name)
{
    unsigned int bucket;
    bucket = (parentId + name) % (SCRVL_VARIABLELIST_CHILD_SIZE - 1) + 1;
    return FindVariableIndexInternal2(name, bucket);
}

/*
 * FindVariable: find a child variable of parentId by name/index.
 * Returns the child's id (hash.id of the found bucket), or 0 if not found.
 * ref: scr_variable.cpp line 752
 */
unsigned int FindVariable(unsigned int parentId, unsigned int index)
{
    unsigned int bucket = FindVariableIndexInternal(parentId, index);
    if (!bucket)
        return 0;
    return (unsigned int)VG_ID(bucket);
}

/*
 * FindObjectVariable: find a child object variable by object id.
 * Object variables are stored with name = id + SL_MAX_STRING_INDEX.
 * ref: scr_variable.cpp line 742
 */
unsigned int FindObjectVariable(unsigned int parentId, unsigned int id)
{
    unsigned int bucket = FindVariableIndexInternal(parentId,
                              id + SCRVL_SL_MAX_STRING_INDEX);
    if (!bucket)
        return 0;
    return (unsigned int)VG_ID(bucket);
}

/*
 * FindObject: return the pointer value (object id) stored in a POINTER variable.
 * ref: scr_variable.cpp line 194
 */
unsigned int FindObject(unsigned int id)
{
    return VG_U32(id);
}

/*
 * GetVariableName: return the name field stored in a leaf variable's w word.
 * The name occupies bits [31:8] of w.status (i.e. w >> VAR_NAME_BITS).
 * ref: scr_variable.cpp line 212
 */
unsigned int GetVariableName(unsigned int id)
{
    return VG_STATUS(id) >> SCRVL_VAR_NAME_BITS;
}

/*
 * GetNewVariableIndexInternal3: allocate and initialise a hash bucket slot at
 * `index` for a new child variable of `parentId` with the given `name`.
 *
 * This is the core "claim a free or collision slot" routine.  It handles four
 * cases depending on what currently occupies `index`:
 *   FREE     – the slot is on the free list: claim it directly.
 *   HEAD     – the slot already owns a HEAD entry: either steal a free entry
 *              for the new HEAD and demote the existing one to MOVABLE, or
 *              grab a free entry from elsewhere.
 *   MOVABLE/EXTERNAL – the slot is occupied by a movable entry: either move
 *              it aside or grab a fresh free entry.
 *
 * After claiming the slot the function stamps the name into the value entry's
 * w word and, if the parent is an array, increments its size counter and adds
 * a ref to the key value.
 *
 * ref: scr_variable.cpp line 3874
 */
static unsigned int GetNewVariableIndexInternal3(unsigned int parentId,
                                                  unsigned int name,
                                                  unsigned int index)
{
    unsigned int type;
    unsigned int headId;      /* VG_ID(index)  – value slot for current bucket */
    unsigned int newIndex;
    unsigned int newHeadId;
    unsigned int next, prev;
    unsigned int nextSiblingIndex;
    unsigned int prevId;

    headId = (unsigned int)VG_ID(index);
    type = VG_STATUS(headId) & SCRVL_VAR_STAT_MASK;

    switch (type) {

    /* ---- Slot is FREE ---- */
    case SCRVL_VAR_STAT_FREE: {
        newIndex = (unsigned int)VG_VNEXT(headId);
        next     = (unsigned int)VG_U16(headId);
        unsigned int newEntryId;

        if (newIndex == headId ||
            (VG_STATUS(index) & SCRVL_VAR_STAT_MASK) != 0)
        {
            /* Use headId as the value entry directly */
            newEntryId = headId;
        } else {
            /* Displace the entry: point newIndex at headId, reclaim index */
            VG_ID(newIndex) = VG_ID(headId);
            VG_ID(index) = (unsigned short)index;

            VG_VNEXT(headId) = (unsigned short)newIndex;
            VG_U16(headId)   = VG_U16(index);

            newEntryId = index;
        }

        prev = (unsigned int)VG_PREV(index);

        /* Unlink from the free list: list[list[prev].id].u.next = next */
        VG_U16(VG_ID(prev)) = (unsigned short)next;
        VG_PREV(next)        = (unsigned short)prev;

        VG_STATUS(newEntryId) = SCRVL_VAR_STAT_HEAD;
        VG_VNEXT(newEntryId)  = (unsigned short)index;
        break;
    }

    /* ---- Slot holds a HEAD entry ---- */
    case SCRVL_VAR_STAT_HEAD: {
        if (VG_STATUS(index) & SCRVL_VAR_STAT_MASK) {
            /* index's own status bits are non-zero: grab a fresh free entry */
            newIndex = (unsigned int)VG_U16(0);
            if (!newIndex)
                Scr_TerminalError("exceeded maximum number of script variables");

            newHeadId = (unsigned int)VG_ID(newIndex);
            next = (unsigned int)VG_U16(newHeadId);

            VG_U16(0) = (unsigned short)next;
            VG_PREV(next) = 0;

            /* Demote existing HEAD to MOVABLE, chain new entry */
            VG_STATUS(newHeadId) = SCRVL_VAR_STAT_MOVABLE;
            VG_VNEXT(newHeadId)  = VG_VNEXT(headId);
            VG_VNEXT(headId)     = (unsigned short)newIndex;
        } else {
            /* Steal the free entry pointed to by index.v.index */
            unsigned int freeIndex = (unsigned int)VG_VNEXT(index);
            unsigned int freeEntry = &((char *)0)[0]; /* just a placeholder */
            /* Actually: newIndex = entry[index].v.index (= VG_VNEXT(index)) */
            /* wait — v.index and v.next share the same offset (12);
             * VG_VNEXT reads offset 12 which is v.next/index */
            newIndex  = (unsigned int)VG_VNEXT(index); /* = entry[index].v.index */
            newHeadId = (unsigned int)VG_ID(newIndex); /* freeEntry = &list[newIndex] */

            prev = (unsigned int)VG_PREV(newIndex);
            next = (unsigned int)VG_U16(headId); /* entry[headId].u.next */

            /* Unlink newIndex from free list */
            VG_U16(VG_ID(prev)) = (unsigned short)next;
            VG_PREV(next)        = (unsigned short)VG_SIBLING(newIndex); /* prev of next = prevSibling field */

            /* Swap: newIndex takes headId's id, index takes index */
            VG_ID(newIndex) = VG_ID(index);
            VG_ID(index)    = (unsigned short)index;
            VG_PREV(newIndex) = VG_PREV(index); /* copy prevSibling */

            /* Update sibling chain pointers */
            VG_SIBLING(VG_ID(VG_PREV(newIndex))) = (unsigned short)newIndex;
            VG_PREV(VG_SIBLING(headId))           = (unsigned short)newIndex;

            /* Demote headId from HEAD to MOVABLE */
            VG_STATUS(headId) = (VG_STATUS(headId) & ~SCRVL_VAR_STAT_MASK) | SCRVL_VAR_STAT_MOVABLE;

            VG_STATUS(newHeadId) = SCRVL_VAR_STAT_HEAD;
        }
        /* In both sub-cases the new value entry is VG_ID(index) = index */
        /* headId is now the id for this slot */
        break;
    }

    /* ---- Slot holds a MOVABLE or EXTERNAL entry ---- */
    default: {
        /* type is MOVABLE (0x20) or EXTERNAL (0x60) */
        if (VG_STATUS(index) & SCRVL_VAR_STAT_MASK) {
            /* Grab a fresh free entry */
            newIndex = (unsigned int)VG_U16(0);
            if (!newIndex)
                Scr_TerminalError("exceeded maximum number of script variables");

            newHeadId = (unsigned int)VG_ID(newIndex);
            next = (unsigned int)VG_U16(newHeadId);

            VG_U16(0)     = (unsigned short)next;
            VG_PREV(next) = 0;
        } else {
            /* Move the existing entry aside */
            newIndex  = (unsigned int)VG_VNEXT(index);
            newHeadId = (unsigned int)VG_ID(newIndex); /* = index (free-list item) */

            prev = (unsigned int)VG_PREV(newIndex);
            next = (unsigned int)VG_U16(headId);

            VG_U16(VG_ID(prev)) = (unsigned short)next;
            VG_PREV(next)        = (unsigned short)prev;
        }

        /* Update sibling chain: replace index with newIndex */
        nextSiblingIndex = (unsigned int)VG_SIBLING(headId);
        VG_SIBLING(VG_ID(VG_PREV(index))) = (unsigned short)newIndex;
        VG_PREV(nextSiblingIndex)           = (unsigned short)newIndex;

        if (type == SCRVL_VAR_STAT_MOVABLE) {
            /* Walk the HEAD/MOVABLE chain of this object to find who points at index */
            nextSiblingIndex = (unsigned int)VG_VNEXT(index);
            prevId = (unsigned int)VG_ID(nextSiblingIndex);

            while (VG_VNEXT(prevId) != (unsigned short)index) {
                prevId = (unsigned int)VG_ID(VG_VNEXT(prevId));
            }
            VG_VNEXT(prevId) = (unsigned short)newIndex;
        } else {
            /* EXTERNAL: the parent's v.index points directly to the bucket */
            VG_VNEXT(headId) = (unsigned short)newIndex;
        }

        /* Swap ids: newIndex gets the old headId, index gets index */
        VG_PREV(newIndex) = VG_PREV(index);
        {
            unsigned short tmp = VG_ID(newIndex);
            VG_ID(newIndex)    = VG_ID(index);
            VG_ID(index)       = tmp;
        }
        VG_STATUS(VG_ID(index)) = SCRVL_VAR_STAT_HEAD;
        VG_VNEXT(VG_ID(index))  = (unsigned short)index;
        break;
    }
    } /* switch */

    /* Stamp the name into the new value entry's w word (bits [31:8]) */
    {
        unsigned int valId = (unsigned int)VG_ID(index);
        /* Clear upper bits, set name */
        VG_STATUS(valId) = (VG_STATUS(valId) & 0xFFu) | (name << SCRVL_VAR_NAME_BITS);

        /* If the parent is an array, increment its size and addref the key */
        if ((VG_STATUS(parentId) & SCRVL_VAR_MASK) == SCRVL_VAR_ARRAY) {
            VG_OBJSIZE(parentId)++;
            /* AddRef the array key value */
            if (name < SCRVL_SL_MAX_STRING_INDEX) {
                /* String key */
                VariableUnion ku;
                ku.stringValue = (unsigned int)(unsigned short)name;
                AddRefToValue(2 /* VAR_STRING */, ku);
            } else if (name < SCRVL_OBJECT_NOTIFY_LIST) {
                /* Object pointer key */
                VariableUnion ku;
                ku.pointerValue = name - SCRVL_SL_MAX_STRING_INDEX;
                AddRefToValue(1 /* VAR_POINTER */, ku);
            }
            /* else: special sentinel – no ref needed */
        }
    }

    return index;
}

/*
 * GetNewVariableIndexInternal2: claim a slot and link the new child at the
 * FRONT of the parent's sibling chain (normal insertion order).
 * ref: scr_variable.cpp line 4130
 */
static unsigned int GetNewVariableIndexInternal2(unsigned int parentId,
                                                  unsigned int name,
                                                  unsigned int index)
{
    unsigned int siblingId;
    unsigned int entryValId;

    index = GetNewVariableIndexInternal3(parentId, name, index);

    entryValId = (unsigned int)VG_ID(index);
    siblingId  = (unsigned int)VG_SIBLING(parentId);

    /* entry[entryValId].nextSibling = parentId's current first child */
    VG_SIBLING(entryValId) = (unsigned short)siblingId;
    /* child's prev (prevSibling) in the sibling's hash = index */
    VG_PREV(siblingId) = (unsigned short)index;

    /* entry[index].hash.u.prev = parent's v.next (the chain anchor) */
    VG_PREV(index) = VG_VNEXT(parentId);
    /* parent now points to index as first child */
    VG_SIBLING(parentId) = (unsigned short)index;

    return index;
}

/*
 * GetVariableIndexInternal: find an existing child bucket, or create one.
 * ref: scr_variable.cpp line 4162
 */
static unsigned int GetVariableIndexInternal(unsigned int parentId, unsigned int name)
{
    unsigned int bucket;
    bucket = (parentId + name) % (SCRVL_VARIABLELIST_CHILD_SIZE - 1) + 1;

    unsigned int found = FindVariableIndexInternal2(name, bucket);
    if (!found)
        found = GetNewVariableIndexInternal2(parentId, name, bucket);

    return found;
}

/*
 * GetNewVariableIndexInternal: assert the slot doesn't exist, then create it.
 * ref: scr_variable.cpp line 4199
 */
static unsigned int GetNewVariableIndexInternal(unsigned int parentId,
                                                 unsigned int name)
{
    unsigned int bucket;
    bucket = (parentId + name) % (SCRVL_VARIABLELIST_CHILD_SIZE - 1) + 1;
    return GetNewVariableIndexInternal2(parentId, name, bucket);
}

/*
 * GetVariable: find or create a child variable of parentId with the given name.
 * ref: scr_variable.cpp line 1353
 */
unsigned int GetVariable(unsigned int parentId, unsigned int unsignedValue)
{
    return (unsigned int)VG_ID(GetVariableIndexInternal(parentId, unsignedValue));
}

/*
 * GetNewVariable: create a new child variable (must not already exist).
 * ref: scr_variable.cpp line 1343
 */
unsigned int GetNewVariable(unsigned int parentId, unsigned int unsignedValue)
{
    return (unsigned int)VG_ID(GetNewVariableIndexInternal(parentId, unsignedValue));
}

/*
 * GetObjectVariable: find-or-create an object-keyed child of an array.
 * Object variables use name = id + SL_MAX_STRING_INDEX.
 * ref: scr_variable.cpp line 1332
 */
unsigned int GetObjectVariable(unsigned int parentId, unsigned int id)
{
    return (unsigned int)VG_ID(
        GetVariableIndexInternal(parentId, id + SCRVL_SL_MAX_STRING_INDEX));
}

/*
 * GetObjectA: return the pointer value stored in variable `id`, allocating
 * a fresh object if the variable is currently UNDEFINED.
 * ref: scr_variable.cpp line 4973
 */
unsigned int GetObjectA(unsigned int id)
{
    unsigned int type = VG_STATUS(id) & SCRVL_VAR_MASK;

    if (type == SCRVL_VAR_UNDEFINED) {
        /* Set type to POINTER and allocate a new object */
        VG_STATUS(id) = (VG_STATUS(id) & ~SCRVL_VAR_MASK) | SCRVL_VAR_POINTER;
        VG_U32(id) = AllocObject();
    }
    return VG_U32(id);
}

/*
 * GetObject_ (GetObject): same semantics as GetObjectA – kept as alias.
 * ref: scr_variable.cpp line 1285
 */
unsigned int GetObject_(unsigned int id)
{
    return GetObjectA(id);
}
