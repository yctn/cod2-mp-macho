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
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
int ThreadInfoCompare(const JCOEF *info1, const JCOEF *info2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 361 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %esi\n" /* info1 */
        "movl 0xc(%ebp), %edi\n" /* info2 */
        /* { scope 1 */
        "movl 0x80(%esi), %ecx\n" /* line 370 | i */
        "testl %ecx, %ecx\n"
        "jg .Lf88a94_00088abf\n"
        "movl 0x80(%edi), %ebx\n" /* info2 */
        ".Lf88a94_00088ab3:\n"
        "movl %ecx, %eax\n" /* line 371 */
        "subl %ebx, %eax\n"
        /* } scope */
        "addl $4, %esp\n" /* line 378 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf88a94_00088abf:\n"
        "movl 0x80(%edi), %ebx\n" /* line 370 | info2 */
        "testl %ebx, %ebx\n"
        "jle .Lf88a94_00088ab3\n"
        "movl (%esi), %edx\n" /* line 372 | i */
        "movl (%edi), %eax\n" /* line 373 | info2 */
        "cmpl %edx, %eax\n" /* line 374 */
        "je .Lf88a94_00088add\n"
        "subl %eax, %edx\n" /* line 375 */
        "movl %edx, %eax\n"
        /* } scope */
        ".Lf88a94_00088ad5:\n"
        "addl $4, %esp\n" /* line 378 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf88a94_00088add:\n"
        "movl %esi, -0x10(%ebp)\n" /* line 374 | i */
        "xorl %esi, %esi\n" /* i */
        ".Lf88a94_00088ae2:\n"
        "addl $1, %esi\n" /* line 376 | i */
        "cmpl %ecx, %esi\n" /* line 370 | i */
        "je .Lf88a94_00088ab3\n"
        "cmpl %ebx, %esi\n" /* i */
        "je .Lf88a94_00088ab3\n"
        "movl -0x10(%ebp), %eax\n" /* line 372 */
        "movl 4(%eax), %edx\n"
        "movl 4(%edi), %eax\n" /* line 373 | info2 */
        "addl $4, -0x10(%ebp)\n"
        "addl $4, %edi\n" /* info2 */
        "cmpl %edx, %eax\n" /* line 374 */
        "je .Lf88a94_00088ae2\n"
        "subl %eax, %edx\n" /* line 375 */
        "movl %edx, %eax\n"
        "jmp .Lf88a94_00088ad5\n"
    );
}

/* line 2647 */
unsigned int FindNextSibling(unsigned int id)
{
    unsigned int nextIdx = *(unsigned short *)(((size_t)scrVarGlob + 14) + id * 16);
    unsigned int sibling = *(unsigned short *)((byte *)&scrVarGlob + nextIdx * 16);
    if (sibling == id || (*(unsigned int *)(((size_t)scrVarGlob + 8) + sibling * 16) & 0x1f) > 0xe)
        return 0;
    return sibling;
}

/* line 618 */
JCOEF Scr_DumpScriptVariables(void)
{
}

/* line 681 */
__attribute__((naked))
JCOEF Var_Init(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 681 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "xorl %esi, %esi\n"
        "movl $1, %ecx\n"
        "jmp .Lf88b4c_00088b5c\n"
        ".Lf88b4c_00088b5a:\n"
        "movl %ebx, %esi\n" /* line 640 */
        ".Lf88b4c_00088b5c:\n"
        "movl %ecx, %eax\n" /* line 642 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl $0, 8(%edx)\n" /* line 644 */
        "movl %ecx, %ebx\n"
        "movw %cx, scrVarGlob(%eax)\n" /* line 646 */
        "movw %cx, 0xc(%edx)\n" /* line 647 */
        "movzwl %si, %eax\n" /* line 648 */
        "shll $4, %eax\n"
        "movw %cx, scrVarGlob+4(%eax)\n"
        "movw %si, 2(%edx)\n" /* line 649 */
        "addl $1, %ecx\n" /* line 640 */
        "cmpl $0xfffe, %ecx\n"
        "jne .Lf88b4c_00088b5a\n"
        "movl $0, scrVarGlob+8\n" /* line 664 */
        "movw $0, scrVarGlob\n" /* line 665 */
        "movw $0, scrVarGlob+12\n" /* line 666 */
        "movzwl %bx, %eax\n" /* line 667 */
        "shll $4, %eax\n"
        "movw $0, scrVarGlob+4(%eax)\n"
        "movw %bx, scrVarGlob+2\n" /* line 668 */
        "movl $g_classMap+2, %eax\n"
        "movl $g_classMap+50, %edx\n"
        ".Lf88b4c_00088bd3:\n"
        "movw $0, (%eax)\n" /* line 689 */
        "movw $0, -2(%eax)\n" /* line 690 */
        "addl $0xc, %eax\n"
        "cmpl %eax, %edx\n" /* line 687 */
        "jne .Lf88b4c_00088bd3\n"
        "popl %ebx\n" /* line 692 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 715 */
unsigned int Scr_GetNumScriptVars(void)
{
    return 0;
}

/* line 725 */
unsigned int GetVariableKeyObject(unsigned int id)
{
    return (*(unsigned int *)(((size_t)scrVarGlob + 8) + id * 16) >> 8) - 0x10000;
}

/* line 1737 */
JCOEF AddRefToObject(unsigned int id)
{
    *(unsigned short *)(((size_t)scrVarGlob + 4) + id * 16) += 1;
}

/* line 1279 */
void Scr_SetThreadNotifyName(unsigned int startLocalId, unsigned int stringValue)
{
    byte *entry = (byte *)&scrVarGlob + startLocalId * 16;
    unsigned int val = *(unsigned int *)(entry + 8);
    val = (val & 0xe0) | 0x10;
    *(unsigned int *)(entry + 8) = val | (stringValue << 8);
}

/* line 1352 */
short unsigned int Scr_GetThreadNotifyName(unsigned int startLocalId)
{
    return *(unsigned short *)(((size_t)scrVarGlob + 9) + startLocalId * 16);
}

/* line 1360 */
void Scr_SetThreadWaitTime(unsigned int startLocalId, unsigned int waitTime)
{
    byte *entry = (byte *)&scrVarGlob + startLocalId * 16;
    *(unsigned int *)(entry + 8) = (*(unsigned int *)(entry + 8) & 0xe0) | 0x11;
    *(unsigned int *)(((size_t)scrVarGlob + 8) + startLocalId * 16) |= (waitTime << 8);
}

/* line 1375 */
void Scr_ClearWaitTime(unsigned int startLocalId)
{
    int *p = (int *)((byte *)&scrVarGlob + startLocalId * 16 + 8);
    *p = (*p & 0xffffffe0) | 0xf;
}

/* line 1387 */
unsigned int Scr_GetThreadWaitTime(unsigned int startLocalId)
{
    return *(unsigned int *)(((size_t)scrVarGlob + 8) + startLocalId * 16) >> 8;
}

/* line 1395 */
unsigned int GetParentLocalId(unsigned int threadId)
{
    return *(unsigned int *)(((size_t)scrVarGlob + 8) + threadId * 16) >> 8;
}

/* line 1403 */
unsigned int GetSafeParentLocalId(unsigned int threadId)
{
    unsigned int val = *(unsigned int *)(((size_t)scrVarGlob + 8) + threadId * 16);
    if ((val & 0x1f) == 0x12)
        return val >> 8;
    return 0;
}

/* line 1411 */
unsigned int GetStartLocalId(unsigned int threadId)
{
    while ((*(unsigned int *)(((size_t)scrVarGlob + 8) + threadId * 16) & 0x1f) == 0x12) {
        threadId = *(unsigned int *)(((size_t)scrVarGlob + 8) + threadId * 16) >> 8;
    }
    return threadId;
}

/* line 2733 */
unsigned int FindObject(unsigned int id)
{
    return *(unsigned int *)(((size_t)scrVarGlob + 4) + id * 16);
}

/* line 2442 */
VariableUnion * GetVariableValueAddress(unsigned int id)
{
    return (VariableUnion *)(((size_t)scrVarGlob + 4) + id * 16);
}

/* line 1802 */
__attribute__((naked))
JCOEF RemoveRefToEmptyObject(unsigned int id)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1802 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* id */
        /* { scope 1 */
        "shll $4, %eax\n" /* line 1806 */
        "leal scrVarGlob(%eax), %edi\n" /* entryValue */
        "movzwl 4(%edi), %eax\n" /* line 1812 | entryValue */
        "testw %ax, %ax\n"
        "je .Lf88d74_00088d9b\n"
        "subl $1, %eax\n" /* line 1821 */
        "movw %ax, 4(%edi)\n" /* entryValue */
        /* } scope */
        "popl %ebx\n" /* line 1826 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf88d74_00088d9b:\n"
        "movzwl 0xc(%edi), %ebx\n" /* line 1578 | index */
        "movzwl %bx, %ecx\n" /* line 1579 | index */
        "shll $4, %ecx\n"
        "addl $scrVarGlob, %ecx\n"
        "movzwl 2(%ecx), %edx\n" /* line 1581 */
        "movzwl 0xe(%edi), %esi\n" /* line 1582 | nextSiblingIndex */
        "movzwl %si, %eax\n" /* line 1583 | nextSiblingIndex */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+2(%eax)\n"
        "shll $4, %edx\n" /* line 1584 */
        "movzwl scrVarGlob(%edx), %eax\n"
        "shll $4, %eax\n"
        "movw %si, scrVarGlob+14(%eax)\n" /* nextSiblingIndex */
        "movl $0, 8(%edi)\n" /* line 1586 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1587 */
        "movw %ax, 4(%edi)\n"
        "movw $0, 2(%ecx)\n" /* line 1588 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1590 */
        "shll $4, %eax\n"
        "movw %bx, scrVarGlob+2(%eax)\n" /* index */
        "movw %bx, scrVarGlob+4\n" /* line 1591 | index */
        /* } scope */
        /* } scope */
        "popl %ebx\n" /* line 1826 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1709 */
unsigned int Scr_GetSelf(unsigned int threadId)
{
    return *(unsigned short *)(((size_t)scrVarGlob + 6) + threadId * 16);
}

/* line 1899 */
void RemoveRefToVector(const float *vectorValue)
{
    unsigned short *refCount;

    if (*((unsigned char *)vectorValue - 1))
        return;

    refCount = (unsigned short *)((byte *)vectorValue - 4);
    if (*refCount == 0) {
        MT_Free(refCount, 0x10);
    } else {
        *refCount -= 1;
    }
}

/* line 1962 */
Bool IsValidArrayIndex(unsigned int unsignedValue)
{
    return (unsignedValue + 0x7e0002) <= 0xfe0001;
}

/* line 1968 */
unsigned int GetInternalVariableIndex(unsigned int unsignedValue)
{
    return (unsignedValue + 0x800000) & 0xffffff;
}

/* line 2422 */
void SetNewVariableValue(unsigned int id, VariableValue *value)
{
    byte *entry = (byte *)&scrVarGlob + id * 16;
    *(int *)(entry + 8) |= *(int *)((byte *)value + 4);
    *(int *)(entry + 4) = *(int *)value;
}

/* line 2529 */
unsigned int Scr_EvalVariableObject(unsigned int id)
{
    byte *entry = (byte *)&scrVarGlob + id * 16;
    unsigned int type = *(unsigned int *)(entry + 8) & 0x1f;
    unsigned int objectId;

    if (type == 1) {
        objectId = *(unsigned int *)(entry + 4);
        type = *(unsigned int *)(((size_t)scrVarGlob + 8) + objectId * 16) & 0x1f;
        if (type <= 0x15)
            return objectId;
    }

    Com_Printf("^3%s is not a field object\n", var_typename[type]); /* non-fatal */
    return 0;
}

/* line 2634 */
unsigned int GetArraySize(unsigned int id)
{
    return *(unsigned short *)(((size_t)scrVarGlob + 6) + id * 16);
}

/* line 2669 */
unsigned int FindPrevSibling(unsigned int id)
{
    unsigned int next, result;

    next = *(unsigned short *)(((size_t)scrVarGlob + 14) + id * 16);      /* nextSibling */
    next = *(unsigned short *)(((size_t)scrVarGlob + 2) + next * 16);     /* hash.u (prevSibling) */
    next = *(unsigned short *)(((size_t)scrVarGlob + 2) + next * 16);     /* hash.u (prevSibling) */
    result = *(unsigned short *)((byte *)&scrVarGlob + next * 16); /* hash.id */

    if ((*(unsigned int *)(((size_t)scrVarGlob + 8) + result * 16) & 0x1f) >= 0xf)
        return 0;
    return result;
}

/* line 2681 */
unsigned int GetVariableName(unsigned int id)
{
    return *(unsigned int *)(((size_t)scrVarGlob + 8) + id * 16) >> 8;
}

/* line 2747 */
Bool IsFieldObject(unsigned int id)
{
    return (*(unsigned int *)(((size_t)scrVarGlob + 8) + id * 16) & 0x1f) <= 0x15;
}

/* line 3578 */
Bool IsVarFree(unsigned int id)
{
    return (*(unsigned char *)(((size_t)scrVarGlob + 8) + id * 16) & 0x60) == 0;
}

/* line 4185 */
__attribute__((naked))
struct scr_entref_t Scr_GetEntityIdRef(unsigned int entId)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4185 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* entId */
        /* { scope 1 */
        "shll $4, %edx\n" /* line 4190 */
        "addl $scrVarGlob, %edx\n"
        "movzwl 9(%edx), %eax\n" /* line 4197 */
        "shll $0x10, %eax\n"
        "andl $0xffff, %ecx\n"
        "orl %eax, %ecx\n"
        "movw 6(%edx), %cx\n"
        /* } scope */
        "movl %ecx, %eax\n" /* line 4198 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 4375 */
__attribute__((naked))
unsigned int Scr_FindField(const char *name, int *type)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4375 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl scrVarPub, %esi\n" /* line 4382 | pos */
        "cmpb $0, (%esi)\n" /* line 4384 | pos */
        "jne .Lf88fc8_00088fe8\n"
        ".Lf88fc8_00088fdc:\n"
        "xorl %edx, %edx\n" /* line 4401 */
        /* } scope */
        ".Lf88fc8_00088fde:\n"
        "movl %edx, %eax\n" /* line 4405 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf88fc8_00088fe8:\n"
        "cld\n" /* line 4386 */
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n" /* pos */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "movl %ecx, %ebx\n"
        "notl %ebx\n"
        "movl %esi, 4(%esp)\n" /* line 4387 | pos */
        "movl 8(%ebp), %eax\n" /* name */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf88fc8_00089019\n"
        "leal (%esi, %ebx), %eax\n" /* line 4389 | pos */
        "leal 3(%eax), %esi\n" /* pos */
        "cmpb $0, 3(%eax)\n" /* line 4384 */
        "jne .Lf88fc8_00088fe8\n"
        "jmp .Lf88fc8_00088fdc\n"
        ".Lf88fc8_00089019:\n"
        "leal (%esi, %ebx), %eax\n" /* line 4393 | pos */
        "movzwl (%eax), %edx\n" /* line 4395 */
        "movsbl 2(%eax), %eax\n" /* line 4398 */
        "movl 0xc(%ebp), %ecx\n" /* type */
        "movl %eax, (%ecx)\n"
        "jmp .Lf88fc8_00088fde\n"
    );
}

/* line 4676 */
int Scr_GetClassnumForCharId(int charId)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        if (*(byte *)((byte *)&g_classMap + i * 12 + 4) == (byte)charId)
            return i;
    }
    return -1;
}

/* line 1321 */
void Scr_RemoveThreadNotifyName(unsigned int startLocalId)
{
    byte *entry = (byte *)&scrVarGlob + startLocalId * 16;
    unsigned int notifyName = *(unsigned short *)(((size_t)scrVarGlob + 9) + startLocalId * 16);

    SL_RemoveRefToString(notifyName);

    /* Clear type bits (low 5) and set to 0xf (free) */
    *(unsigned int *)(entry + 8) = (*(unsigned int *)(entry + 8) & 0xffffffe0) | 0xf;
}

/* line 1926 */
void AddRefToValue(int type, VariableUnion u)
{
    switch (type) {
    case 1: /* object */
        *(unsigned short *)(((size_t)scrVarGlob + 4) + u.intValue * 16) += 1;
        break;
    case 2: /* string */
    case 3: /* localized string */
        SL_AddRefToString(u.intValue);
        break;
    case 4: /* vector */
        if (*((byte *)u.intValue - 1) == 0)
            *(unsigned short *)((byte *)u.intValue - 4) += 1;
        break;
    }
}

/* line 1865 */
const float * Scr_AllocVector(const float *v)
{
    byte *mem = (byte *)MT_Alloc(0x10, 2);
    float *vec = (float *)(mem + 4);

    *(int *)mem = 0; /* refcount = 0 */
    vec[0] = v[0];
    vec[1] = v[1];
    vec[2] = v[2];

    return vec;
}

/* line 3757 */
__attribute__((naked))
int Scr_GetOffset(int classnum, const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3757 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* classnum, name */
        /* { scope 1 */
        "leal (%eax, %eax, 2), %eax\n" /* line 3762 */
        "movzwl g_classMap(, %eax, 4), %ebx\n" /* classId */
        "movl 0xc(%ebp), %eax\n" /* line 3763 | name */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertFromString\n"
        "movl %eax, %esi\n" /* name */
        "addl %eax, %ebx\n" /* line 801 | entryValue */
        "movl $0x80018005, %edx\n"
        "movl %ebx, %eax\n" /* entryValue */
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ebx\n" /* entryValue */
        "addl $1, %ebx\n" /* entryValue */
        "movzwl %bx, %ecx\n" /* entryValue, index */
        /* { scope 2 */
        /* { scope 3 */
        "movl %ecx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edi\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ebx\n" /* entryValue */
        "movl 8(%ebx), %edx\n" /* line 748 | entryValue */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf8910a_0008919b\n"
        ".Lf8910a_00089176:\n"
        "xorl %ecx, %ecx\n" /* line 759 */
        /* } scope */
        /* } scope */
        ".Lf8910a_00089178:\n"
        "shll $4, %ecx\n" /* line 1992 */
        "movzwl scrVarGlob(%ecx), %eax\n"
        "movzwl %ax, %edx\n"
        "testw %ax, %ax\n" /* line 3764 */
        "je .Lf8910a_000891e4\n"
        "shll $4, %edx\n"
        "movl scrVarGlob+4(%edx), %eax\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 3765 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf8910a_0008919b:\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, %esi\n"
        "je .Lf8910a_00089178\n"
        "movzwl 0xc(%ebx), %ecx\n" /* line 757 | entryValue */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, %edi\n" /* line 759 | entry */
        "je .Lf8910a_00089176\n"
        ".Lf8910a_000891b5:\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, %esi\n"
        "je .Lf8910a_00089178\n"
        "movzwl 0xc(%edx), %ecx\n" /* line 771 */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, %edi\n" /* line 759 | entry */
        "jne .Lf8910a_000891b5\n"
        "jmp .Lf8910a_00089176\n"
        /* } scope */
        /* } scope */
        ".Lf8910a_000891e4:\n"
        "movl $0xffffffff, %eax\n" /* line 3764 */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 3765 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3768 */
__attribute__((naked))
unsigned int FindEntityId(int entnum, int classnum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3768 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 0xc(%ebp), %eax\n" /* classnum */
        /* { scope 1 */
        "movl 8(%ebp), %esi\n" /* line 1980 | entnum, name */
        "addl $0x00800000, %esi\n" /* name */
        "andl $0x00FFFFFF, %esi\n" /* name */
        "leal (%eax, %eax, 2), %eax\n" /* line 801 */
        "movzwl g_classMap+2(, %eax, 4), %ecx\n" /* index */
        "addl %esi, %ecx\n" /* name, index */
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n" /* index */
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n" /* index */
        "addl $1, %ecx\n" /* index */
        "movzwl %cx, %ecx\n" /* index */
        /* { scope 2 */
        /* { scope 3 */
        "movl %ecx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edi\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ebx\n" /* entryValue */
        "movl 8(%ebx), %edx\n" /* line 748 | entryValue */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf891f2_0008927f\n"
        ".Lf891f2_0008925d:\n"
        "xorl %ecx, %ecx\n" /* line 759 */
        /* } scope */
        /* } scope */
        ".Lf891f2_0008925f:\n"
        "shll $4, %ecx\n" /* line 1986 */
        "movzwl scrVarGlob(%ecx), %eax\n"
        "movzwl %ax, %edx\n"
        "testw %ax, %ax\n" /* line 3780 */
        "je .Lf891f2_000892c8\n"
        "shll $4, %edx\n" /* line 3788 */
        "movl scrVarGlob+4(%edx), %eax\n"
        /* } scope */
        "popl %ebx\n" /* line 3789 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf891f2_0008927f:\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, %esi\n"
        "je .Lf891f2_0008925f\n"
        "movzwl 0xc(%ebx), %ecx\n" /* line 757 | entryValue */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, %edi\n" /* line 759 | entry */
        "je .Lf891f2_0008925d\n"
        ".Lf891f2_00089299:\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, %esi\n"
        "je .Lf891f2_0008925f\n"
        "movzwl 0xc(%edx), %ecx\n" /* line 771 */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, %edi\n" /* line 759 | entry */
        "jne .Lf891f2_00089299\n"
        "jmp .Lf891f2_0008925d\n"
        /* } scope */
        /* } scope */
        ".Lf891f2_000892c8:\n"
        "xorl %eax, %eax\n" /* line 3780 */
        /* } scope */
        "popl %ebx\n" /* line 3789 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1984 */
__attribute__((naked))
unsigned int FindArrayVariable(unsigned int parentId, int intValue)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1984 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 0xc(%ebp), %esi\n" /* line 1980 | intValue, name */
        "addl $0x00800000, %esi\n" /* name */
        "andl $0x00FFFFFF, %esi\n" /* name */
        "movl 8(%ebp), %ecx\n" /* line 801 | parentId, index */
        "addl %esi, %ecx\n" /* name, index */
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n" /* index */
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n" /* index */
        "addl $1, %ecx\n" /* index */
        "movzwl %cx, %ecx\n" /* index */
        /* { scope 1 */
        /* { scope 2 */
        "movl %ecx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edi\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ebx\n" /* entryValue */
        "movl 8(%ebx), %edx\n" /* line 748 | entryValue */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf892d0_00089341\n"
        ".Lf892d0_00089330:\n"
        "xorl %ecx, %ecx\n" /* line 759 */
        ".Lf892d0_00089332:\n"
        "shll $4, %ecx\n"
        "movzwl scrVarGlob(%ecx), %eax\n"
        /* } scope */
        /* } scope */
        "popl %ebx\n" /* line 1987 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf892d0_00089341:\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, %esi\n"
        "je .Lf892d0_00089332\n"
        "movzwl 0xc(%ebx), %ecx\n" /* line 757 | entryValue */
        "jmp .Lf892d0_0008936c\n"
        ".Lf892d0_0008934e:\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, %esi\n"
        "je .Lf892d0_00089332\n"
        "movzwl 0xc(%edx), %ecx\n" /* line 771 */
        ".Lf892d0_0008936c:\n"
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, %edi\n" /* line 759 | entry */
        "jne .Lf892d0_0008934e\n"
        "jmp .Lf892d0_00089330\n"
    );
}

/* line 1990 */
__attribute__((naked))
unsigned int FindVariable(unsigned int parentId, unsigned int unsignedValue)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1990 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 0xc(%ebp), %esi\n" /* unsignedValue */
        "movl 8(%ebp), %ecx\n" /* line 801 | parentId, index */
        "addl %esi, %ecx\n" /* index */
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n" /* index */
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n" /* index */
        "addl $1, %ecx\n" /* index */
        "movzwl %cx, %ecx\n" /* index */
        /* { scope 1 */
        /* { scope 2 */
        "movl %ecx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edi\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ebx\n" /* entryValue */
        "movl 8(%ebx), %edx\n" /* line 748 | entryValue */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf8937e_000893e3\n"
        ".Lf8937e_000893d2:\n"
        "xorl %ecx, %ecx\n" /* line 759 */
        ".Lf8937e_000893d4:\n"
        "shll $4, %ecx\n"
        "movzwl scrVarGlob(%ecx), %eax\n"
        /* } scope */
        /* } scope */
        "popl %ebx\n" /* line 1993 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf8937e_000893e3:\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, %esi\n"
        "je .Lf8937e_000893d4\n"
        "movzwl 0xc(%ebx), %ecx\n" /* line 757 | entryValue */
        "jmp .Lf8937e_0008940e\n"
        ".Lf8937e_000893f0:\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, %esi\n"
        "je .Lf8937e_000893d4\n"
        "movzwl 0xc(%edx), %ecx\n" /* line 771 */
        ".Lf8937e_0008940e:\n"
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, %edi\n" /* line 759 | entry */
        "jne .Lf8937e_000893f0\n"
        "jmp .Lf8937e_000893d2\n"
    );
}

/* line 1996 */
__attribute__((naked))
unsigned int FindObjectVariable(unsigned int parentId, unsigned int id)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1996 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 0xc(%ebp), %esi\n" /* line 1998 | id, name */
        "addl $0x10000, %esi\n" /* name */
        "movl %esi, %ecx\n" /* line 801 | name, index */
        "addl 8(%ebp), %ecx\n" /* parentId, index */
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n" /* index */
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n" /* index */
        "addl $1, %ecx\n" /* index */
        "movzwl %cx, %ecx\n" /* index */
        /* { scope 1 */
        /* { scope 2 */
        "movl %ecx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edi\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ebx\n" /* entryValue */
        "movl 8(%ebx), %edx\n" /* line 748 | entryValue */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf89420_0008948b\n"
        ".Lf89420_0008947a:\n"
        "xorl %ecx, %ecx\n" /* line 759 */
        ".Lf89420_0008947c:\n"
        "shll $4, %ecx\n"
        "movzwl scrVarGlob(%ecx), %eax\n"
        /* } scope */
        /* } scope */
        "popl %ebx\n" /* line 1999 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf89420_0008948b:\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, %esi\n"
        "je .Lf89420_0008947c\n"
        "movzwl 0xc(%ebx), %ecx\n" /* line 757 | entryValue */
        "jmp .Lf89420_000894b6\n"
        ".Lf89420_00089498:\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, %esi\n"
        "je .Lf89420_0008947c\n"
        "movzwl 0xc(%edx), %ecx\n" /* line 771 */
        ".Lf89420_000894b6:\n"
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, %edi\n" /* line 759 | entry */
        "jne .Lf89420_00089498\n"
        "jmp .Lf89420_0008947a\n"
    );
}

/* line 4507 */
__attribute__((naked))
JCOEF Scr_AddFields(const char *path, const char *extension)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4507 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        /* { scope 1: sourcePos, type, index, f */
        "movl $0xa, 0x10(%esp)\n" /* line 4518 */
        "leal -0x1c(%ebp), %eax\n" /* numFiles */
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* extension */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* path */
        "movl %eax, (%esp)\n"
        "calll FS_ListFiles\n"
        "movl %eax, -0x7c(%ebp)\n" /* files */
        "calll TempMemoryReset\n" /* line 4522 */
        "movl $0, (%esp)\n" /* line 4524 */
        "calll Hunk_AllocLowInternal\n"
        "movl %eax, scrVarPub\n"
        "movb $0, (%eax)\n" /* line 4526 */
        "movl -0x1c(%ebp), %eax\n" /* line 4534 | numFiles */
        "testl %eax, %eax\n"
        "jg .Lf894c8_00089559\n"
        ".Lf894c8_00089520:\n"
        "movl -0x7c(%ebp), %esi\n" /* line 4541 | files, len */
        "testl %esi, %esi\n" /* len */
        "je .Lf894c8_0008953a\n"
        "movl $0xa, 4(%esp)\n" /* line 4542 */
        "movl -0x7c(%ebp), %eax\n" /* files */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFileList\n"
        ".Lf894c8_0008953a:\n"
        "movl $1, (%esp)\n" /* line 4545 */
        "calll TempMalloc\n"
        "movb $0, (%eax)\n" /* line 4546 */
        "calll Hunk_ConvertTempToPermLowInternal\n" /* line 4548 */
        /* } scope */
        "addl $0x9c, %esp\n" /* line 4549 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: sourcePos, type, index, f */
        ".Lf894c8_00089559:\n"
        "movl $0, -0x78(%ebp)\n" /* line 4534 | i */
        "movl -0x78(%ebp), %edx\n" /* i */
        ".Lf894c8_00089563:\n"
        "movl -0x7c(%ebp), %ecx\n" /* line 4536 | files */
        "movl (%ecx, %edx, 4), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 8(%ebp), %eax\n" /* path */
        "movl %eax, 8(%esp)\n"
        "movl $str_00216e18, 4(%esp)\n" /* "%s/%s" */
        "leal -0x64(%ebp), %edx\n" /* filename */
        "movl %edx, (%esp)\n"
        "calll sprintf\n"
        /* { scope 2 */
        "movl $0, 8(%esp)\n" /* line 4439 */
        "leal -0x24(%ebp), %ecx\n" /* f */
        "movl %ecx, 4(%esp)\n"
        "leal -0x64(%ebp), %eax\n" /* filename */
        "movl %eax, (%esp)\n"
        "calll FS_FOpenFileByMode\n"
        "movl %eax, %esi\n" /* len */
        "testl %eax, %eax\n" /* line 4440 */
        "js .Lf894c8_0008983b\n"
        ".Lf894c8_000895ab:\n"
        "leal 1(%esi), %eax\n" /* line 4443 | len */
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocateTempMemoryHighInternal\n"
        "movl %eax, %ebx\n" /* targetPos */
        "movl -0x24(%ebp), %eax\n" /* line 4444 | f */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* len */
        "movl %ebx, (%esp)\n" /* targetPos */
        "calll FS_Read\n"
        "movb $0, (%ebx, %esi)\n" /* line 4445 | targetPos */
        "movl -0x24(%ebp), %eax\n" /* line 4446 | f */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movl %ebx, -0x20(%ebp)\n" /* line 4449 | targetPos, sourcePos */
        "movl $str_0021d374, (%esp)\n" /* line 4451 */
        "calll Com_BeginParseSession\n"
        "leal -0x20(%ebp), %ecx\n" /* line 4455 | sourcePos */
        "movl %ecx, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, %ebx\n" /* targetPos */
        "movl -0x20(%ebp), %eax\n" /* line 4456 | sourcePos */
        "testl %eax, %eax\n"
        "je .Lf894c8_0008970e\n"
        ".Lf894c8_00089601:\n"
        "movl $str_0021d274, %edi\n" /* line 4459 */
        "movl $6, %ecx\n"
        "cld\n"
        "movl %ebx, %esi\n" /* targetPos, len */
        "repe cmpsb %es:(%edi), (%esi)\n" /* len */
        "movl $0, %edx\n"
        "je .Lf894c8_00089621\n"
        "movzbl -1(%esi), %edx\n" /* len */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf894c8_00089621:\n"
        "testl %edx, %edx\n"
        "je .Lf894c8_00089790\n"
        "movl $str_0021d27c, %edi\n" /* line 4461 */
        "movl $4, %ecx\n"
        "movl %ebx, %esi\n" /* targetPos, len */
        "repe cmpsb %es:(%edi), (%esi)\n" /* len */
        "movl $0, %edx\n"
        "je .Lf894c8_00089648\n"
        "movzbl -1(%esi), %edx\n" /* len */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf894c8_00089648:\n"
        "testl %edx, %edx\n"
        "jne .Lf894c8_000897db\n"
        "movl $6, -0x74(%ebp)\n" /* type */
        ".Lf894c8_00089657:\n"
        "leal -0x20(%ebp), %edx\n" /* line 4473 | sourcePos */
        "movl %edx, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, -0x6c(%ebp)\n"
        "movl -0x20(%ebp), %edi\n" /* line 4474 | sourcePos */
        "testl %edi, %edi\n"
        "je .Lf894c8_000897b0\n"
        ".Lf894c8_00089670:\n"
        "movl %eax, %edi\n"
        ".Lf894c8_00089672:\n"
        "cld\n" /* line 4477 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %ecx, -0x80(%ebp)\n"
        "movl %ecx, %eax\n" /* line 4478 */
        "subl $1, %eax\n"
        "js .Lf894c8_000896a7\n"
        "movl -0x6c(%ebp), %ebx\n" /* line 4507 | targetPos */
        "addl %eax, %ebx\n" /* extension, targetPos */
        "xorl %esi, %esi\n" /* len */
        ".Lf894c8_0008968f:\n"
        "movsbl (%ebx), %eax\n" /* line 4479 | targetPos */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "movb %al, (%ebx)\n" /* targetPos */
        "addl $1, %esi\n" /* len */
        "subl $1, %ebx\n" /* targetPos */
        "cmpl %esi, -0x80(%ebp)\n" /* line 4478 | len */
        "jne .Lf894c8_0008968f\n"
        ".Lf894c8_000896a7:\n"
        "movl -0x6c(%ebp), %eax\n" /* line 4481 */
        "movl %eax, (%esp)\n"
        "calll SL_GetCanonicalString\n"
        "movl %eax, -0x70(%ebp)\n" /* index */
        "movl scrVarPub, %esi\n" /* line 4382 */
        "cmpb $0, (%esi)\n" /* line 4384 */
        "jne .Lf894c8_0008973b\n"
        ".Lf894c8_000896c0:\n"
        "movl -0x80(%ebp), %eax\n" /* line 4487 */
        "addl $3, %eax\n"
        "movl %eax, (%esp)\n"
        "calll TempMalloc\n"
        "movl %eax, %ebx\n" /* targetPos */
        "movl -0x6c(%ebp), %eax\n" /* line 4489 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* targetPos */
        "calll strcpy\n"
        "movl -0x80(%ebp), %edx\n" /* line 4490 */
        "leal (%ebx, %edx), %eax\n" /* targetPos */
        "movl -0x70(%ebp), %ecx\n" /* line 4492 | index */
        "movw %cx, (%eax)\n"
        "movzbl -0x74(%ebp), %edx\n" /* line 4495 | type */
        "movb %dl, 2(%eax)\n"
        "movb $0, 3(%eax)\n" /* line 4498 */
        "leal -0x20(%ebp), %ecx\n" /* line 4455 | sourcePos */
        "movl %ecx, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, %ebx\n" /* targetPos */
        "movl -0x20(%ebp), %eax\n" /* line 4456 | sourcePos */
        "testl %eax, %eax\n"
        "jne .Lf894c8_00089601\n"
        ".Lf894c8_0008970e:\n"
        "calll Com_EndParseSession\n" /* line 4501 */
        "calll Hunk_ClearTempMemoryHigh\n" /* line 4503 */
        /* } scope */
        ".Lf894c8_00089718:\n"
        "addl $1, -0x78(%ebp)\n" /* line 4534 | i */
        "movl -0x78(%ebp), %ecx\n" /* i */
        "cmpl -0x1c(%ebp), %ecx\n" /* numFiles */
        "jge .Lf894c8_00089520\n"
        "movl %ecx, %edx\n"
        "jmp .Lf894c8_00089563\n"
        /* { scope 2 */
        ".Lf894c8_0008972f:\n"
        "leal (%ebx, %esi), %eax\n" /* line 4389 */
        "leal 3(%eax), %esi\n"
        "cmpb $0, 3(%eax)\n" /* line 4384 */
        "je .Lf894c8_000896c0\n"
        ".Lf894c8_0008973b:\n"
        "cld\n" /* line 4386 */
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "movl %ecx, %ebx\n"
        "notl %ebx\n"
        "movl %esi, 4(%esp)\n" /* line 4387 */
        "movl -0x6c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf894c8_0008972f\n"
        "cmpw $0, (%ebx, %esi)\n" /* line 4483 | targetPos */
        "je .Lf894c8_000896c0\n"
        "leal -0x64(%ebp), %edx\n" /* line 4484 | filename */
        "movl %edx, 0xc(%esp)\n"
        "movl -0x6c(%ebp), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl $str_0021d3bc, 4(%esp)\n" /* "duplicate key '%s' in '%s'" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf894c8_000896c0\n"
        ".Lf894c8_00089790:\n"
        "movl $5, -0x74(%ebp)\n" /* line 4469 | type */
        "leal -0x20(%ebp), %edx\n" /* line 4473 | sourcePos */
        "movl %edx, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, -0x6c(%ebp)\n"
        "movl -0x20(%ebp), %edi\n" /* line 4474 | sourcePos */
        "testl %edi, %edi\n"
        "jne .Lf894c8_00089670\n"
        ".Lf894c8_000897b0:\n"
        "leal -0x64(%ebp), %ecx\n" /* line 4475 | filename */
        "movl %ecx, 4(%esp)\n"
        "movl $str_0021d3a0, (%esp)\n" /* "missing field name in '%s'" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl -0x6c(%ebp), %edi\n"
        "jmp .Lf894c8_00089672\n"
        ".Lf894c8_000897db:\n"
        "movl $str_0021d250, %edi\n" /* line 4463 */
        "movl $7, %ecx\n"
        "cld\n"
        "movl %ebx, %esi\n" /* targetPos, len */
        "repe cmpsb %es:(%edi), (%esi)\n" /* len */
        "movl $0, %edx\n"
        "je .Lf894c8_000897fb\n"
        "movzbl -1(%esi), %edx\n" /* len */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf894c8_000897fb:\n"
        "testl %edx, %edx\n"
        "jne .Lf894c8_0008980b\n"
        "movl $2, -0x74(%ebp)\n" /* type */
        "jmp .Lf894c8_00089657\n"
        ".Lf894c8_0008980b:\n"
        "movl $str_0021d26c, %edi\n" /* line 4465 */
        "movl $7, %ecx\n"
        "cld\n"
        "movl %ebx, %esi\n" /* targetPos, len */
        "repe cmpsb %es:(%edi), (%esi)\n" /* len */
        "movl $0, %edx\n"
        "je .Lf894c8_0008982b\n"
        "movzbl -1(%esi), %edx\n" /* len */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf894c8_0008982b:\n"
        "testl %edx, %edx\n"
        "jne .Lf894c8_00089863\n"
        "movl $4, -0x74(%ebp)\n" /* type */
        "jmp .Lf894c8_00089657\n"
        ".Lf894c8_0008983b:\n"
        "leal -0x64(%ebp), %edx\n" /* line 4441 | filename */
        "movl %edx, 4(%esp)\n"
        "movl $str_0021d360, (%esp)\n" /* "cannot find '%s'" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf894c8_000895ab\n"
        ".Lf894c8_00089863:\n"
        "leal -0x64(%ebp), %eax\n" /* line 4469 | filename */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* targetPos */
        "movl $str_0021d384, (%esp)\n" /* "unknown type '%s' in '%s'" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf894c8_00089718\n"
    );
}

/* line 2512 */
__attribute__((naked))
VariableValue Scr_EvalVariable(unsigned int id)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2512 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* id */
        /* { scope 1 */
        "shll $4, %eax\n" /* line 2517 */
        "addl $scrVarGlob, %eax\n"
        "movl 8(%eax), %edi\n" /* line 2520 */
        "andl $0x1f, %edi\n"
        "movl 4(%eax), %eax\n" /* line 2521 */
        "movl %eax, -0x1c(%ebp)\n"
        "cmpl $3, %edi\n" /* line 1928 */
        "jg .Lf89890_000898d4\n"
        "cmpl $2, %edi\n"
        "jl .Lf89890_000898fb\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1935 */
        "movl %eax, (%esp)\n"
        "calll SL_AddRefToString\n"
        "movl -0x1c(%ebp), %ebx\n"
        /* } scope */
        ".Lf89890_000898c8:\n"
        "movl %ebx, %eax\n" /* line 2526 | value */
        "movl %edi, %edx\n"
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf89890_000898d4:\n"
        "cmpl $4, %edi\n" /* line 1928 */
        "je .Lf89890_000898e8\n"
        ".Lf89890_000898d9:\n"
        "movl -0x1c(%ebp), %ebx\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 2526 | value */
        "movl %edi, %edx\n"
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf89890_000898e8:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1879 */
        "cmpb $0, -1(%eax)\n"
        "jne .Lf89890_00089913\n"
        "addw $1, -4(%eax)\n" /* line 1894 */
        "movl -0x1c(%ebp), %ebx\n"
        "jmp .Lf89890_000898c8\n"
        ".Lf89890_000898fb:\n"
        "cmpl $1, %edi\n" /* line 1928 */
        "jne .Lf89890_000898d9\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1748 */
        "shll $4, %eax\n"
        "addw $1, scrVarGlob+4(%eax)\n"
        "movl -0x1c(%ebp), %ebx\n"
        "jmp .Lf89890_000898c8\n"
        ".Lf89890_00089913:\n"
        "movl %eax, %ebx\n"
        "jmp .Lf89890_000898c8\n"
    );
}

/* line 805 */
static __attribute__((naked))
unsigned int GetNewVariableIndexInternal3(unsigned int parentId, unsigned int name, unsigned int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 805 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl $0, -0x38(%ebp)\n" /* value */
        "movl $0, -0x34(%ebp)\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl %edx, -0x40(%ebp)\n"
        "movl %ecx, -0x44(%ebp)\n"
        /* { scope 1: value */
        "movl %ecx, %ebx\n" /* line 823 | newIndex */
        "shll $4, %ebx\n" /* newIndex */
        "leal scrVarGlob(%ebx), %esi\n" /* newIndex, entry */
        "movzwl scrVarGlob(%ebx), %eax\n" /* line 824 | newIndex */
        "movw %ax, -0x2e(%ebp)\n"
        "movzwl %ax, %eax\n"
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edi\n" /* entryValue */
        "movl 8(%edi), %edx\n" /* line 827 | entryValue */
        "andl $0x60, %edx\n"
        "movl %edx, -0x28(%ebp)\n" /* type */
        "jne .Lf89918_00089a01\n"
        "movzwl 0xc(%esi), %edx\n" /* line 829 | entry */
        "movzwl 4(%edi), %ecx\n" /* line 830 | entryValue */
        "movw %cx, -0x20(%ebp)\n"
        "cmpw %dx, -0x2e(%ebp)\n" /* line 833 */
        "je .Lf89918_00089bdf\n"
        "testb $0x60, 8(%esi)\n" /* entry */
        "je .Lf89918_00089ab0\n"
        "movl -0x44(%ebp), %eax\n"
        "movw %ax, -0x24(%ebp)\n"
        "movl %edi, %ecx\n" /* entryValue */
        ".Lf89918_00089992:\n"
        "movzwl 2(%esi), %edx\n" /* line 846 | entry */
        "movzwl %dx, %eax\n" /* line 851 */
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %eax\n"
        "shll $4, %eax\n"
        "movl -0x20(%ebp), %ebx\n" /* newIndex */
        "movw %bx, scrVarGlob+4(%eax)\n" /* newIndex */
        "movzwl %bx, %eax\n" /* line 852 | newIndex */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+2(%eax)\n"
        "movl $0x40, 8(%ecx)\n" /* line 854 */
        "movl -0x24(%ebp), %eax\n" /* line 855 */
        "movw %ax, 0xc(%ecx)\n"
        ".Lf89918_000899cb:\n"
        "movzbl 8(%ecx), %eax\n" /* line 992 */
        "movl -0x40(%ebp), %edx\n"
        "shll $8, %edx\n"
        "orl %edx, %eax\n"
        "movl %eax, 8(%ecx)\n"
        "shll $4, -0x3c(%ebp)\n" /* line 1008 */
        "movl -0x3c(%ebp), %edx\n"
        "addl $scrVarGlob, %edx\n"
        "movl 8(%edx), %eax\n" /* line 1012 */
        "andl $0x1f, %eax\n"
        "cmpl $0x16, %eax\n"
        "je .Lf89918_00089bed\n"
        /* } scope */
        ".Lf89918_000899f6:\n"
        "movl -0x44(%ebp), %eax\n" /* line 1020 */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: value */
        ".Lf89918_00089a01:\n"
        "cmpl $0x40, -0x28(%ebp)\n" /* line 859 | type */
        "je .Lf89918_00089b2c\n"
        "testb $0x60, 8(%esi)\n" /* line 912 | entry */
        "jne .Lf89918_00089ae2\n"
        "movzwl 0xc(%esi), %ebx\n" /* line 916 | entry, newIndex */
        "movzwl %bx, %eax\n" /* line 917 | newIndex */
        "shll $4, %eax\n"
        "addl $scrVarGlob, %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* newEntry */
        "movzwl 2(%eax), %ecx\n" /* line 921 */
        "movzwl 4(%esi), %edx\n" /* line 922 | entry */
        "movzwl %cx, %eax\n" /* line 923 */
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %eax\n"
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+4(%eax)\n"
        "shll $4, %edx\n" /* line 924 */
        "movw %cx, scrVarGlob+2(%edx)\n"
        "movl %esi, %ecx\n" /* entry */
        ".Lf89918_00089a52:\n"
        "movzwl 0xe(%edi), %eax\n" /* line 947 | entryValue */
        "movzwl 2(%esi), %edx\n" /* line 948 | entry */
        "shll $4, %edx\n"
        "movzwl scrVarGlob(%edx), %edx\n"
        "shll $4, %edx\n"
        "movw %bx, scrVarGlob+14(%edx)\n" /* newIndex */
        "shll $4, %eax\n" /* line 949 */
        "movw %bx, scrVarGlob+2(%eax)\n" /* newIndex */
        "cmpl $0x20, -0x28(%ebp)\n" /* line 951 | type */
        "je .Lf89918_00089c88\n"
        "movw %bx, 0xc(%edi)\n" /* line 971 | newIndex, entryValue */
        ".Lf89918_00089a86:\n"
        "movzwl 2(%esi), %eax\n" /* line 975 | entry */
        "movl -0x2c(%ebp), %ebx\n" /* newEntry, newIndex */
        "movw %ax, 2(%ebx)\n" /* newIndex */
        "movzwl (%ebx), %edx\n" /* line 978 | newIndex */
        "movzwl (%esi), %eax\n" /* line 979 | entry */
        "movw %ax, (%ebx)\n" /* newIndex */
        "movw %dx, (%esi)\n" /* line 980 | entry */
        "movl $0x40, 8(%ecx)\n" /* line 982 */
        "movl -0x44(%ebp), %eax\n" /* line 983 */
        "movw %ax, 0xc(%ecx)\n"
        "jmp .Lf89918_000899cb\n"
        ".Lf89918_00089ab0:\n"
        "movzwl %dx, %eax\n" /* line 835 */
        "shll $4, %eax\n"
        "movzwl -0x2e(%ebp), %ecx\n"
        "movw %cx, scrVarGlob(%eax)\n"
        "movl -0x44(%ebp), %eax\n" /* line 836 */
        "movw %ax, -0x24(%ebp)\n"
        "movw %ax, scrVarGlob(%ebx)\n" /* newIndex */
        "movw %dx, 0xc(%edi)\n" /* line 837 | entryValue */
        "movzwl 4(%esi), %eax\n" /* line 838 | entry */
        "movw %ax, 4(%edi)\n" /* entryValue */
        "movl %esi, %ecx\n" /* entry */
        "jmp .Lf89918_00089992\n"
        ".Lf89918_00089ae2:\n"
        "movzwl scrVarGlob+4, %ebx\n" /* line 929 | newIndex */
        "testw %bx, %bx\n" /* line 930 | newIndex */
        "je .Lf89918_00089d29\n"
        ".Lf89918_00089af2:\n"
        "movzwl %bx, %eax\n" /* line 933 | newIndex */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl %edx, -0x2c(%ebp)\n" /* newEntry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 934 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movzwl 4(%ecx), %eax\n" /* line 938 */
        "movw %ax, scrVarGlob+4\n" /* line 939 */
        "shll $4, %eax\n" /* line 940 */
        "movw $0, scrVarGlob+2(%eax)\n"
        "jmp .Lf89918_00089a52\n"
        ".Lf89918_00089b2c:\n"
        "testb $0x60, 8(%esi)\n" /* line 862 | entry */
        "jne .Lf89918_00089cd1\n"
        "movzwl 0xc(%esi), %edx\n" /* line 864 | entry */
        "movw %dx, -0x1e(%ebp)\n"
        "movzwl %dx, %ecx\n" /* line 865 */
        "shll $4, %ecx\n"
        "leal scrVarGlob(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movzwl 2(%eax), %edx\n" /* line 869 */
        "movw %dx, -0x22(%ebp)\n"
        "movzwl 4(%esi), %edx\n" /* line 870 | entry */
        "movzwl -0x22(%ebp), %eax\n" /* line 871 */
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %eax\n"
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+4(%eax)\n"
        "shll $4, %edx\n" /* line 872 */
        "movzwl -0x22(%ebp), %eax\n"
        "movw %ax, scrVarGlob+2(%edx)\n"
        "movzwl -0x2e(%ebp), %edx\n" /* line 874 */
        "movw %dx, scrVarGlob(%ecx)\n"
        "movl -0x44(%ebp), %ecx\n" /* line 875 */
        "movw %cx, scrVarGlob(%ebx)\n" /* newIndex */
        "movzwl 2(%esi), %eax\n" /* line 877 | entry */
        "movl -0x1c(%ebp), %ebx\n" /* newIndex */
        "movw %ax, 2(%ebx)\n" /* newIndex */
        "shll $4, %eax\n" /* line 878 */
        "movzwl scrVarGlob(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl -0x1e(%ebp), %edx\n"
        "movw %dx, scrVarGlob+14(%eax)\n"
        "movzwl 0xe(%edi), %eax\n" /* line 879 | entryValue */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+2(%eax)\n"
        "movl 8(%edi), %eax\n" /* line 882 | entryValue */
        "andl $0xffffff9f, %eax\n"
        "orl $0x20, %eax\n"
        "movl %eax, 8(%edi)\n" /* entryValue */
        "movl $0x40, 8(%esi)\n" /* line 884 | entry */
        "movl %esi, %ecx\n" /* entry */
        "jmp .Lf89918_000899cb\n"
        ".Lf89918_00089bdf:\n"
        "movl -0x44(%ebp), %ebx\n" /* line 833 | newIndex */
        "movw %bx, -0x24(%ebp)\n" /* newIndex */
        "movl %edi, %ecx\n" /* entryValue */
        "jmp .Lf89918_00089992\n"
        ".Lf89918_00089bed:\n"
        "addw $1, 6(%edx)\n" /* line 1014 */
        /* { scope 2 */
        "cmpl $0xffff, -0x40(%ebp)\n" /* line 2159 */
        "ja .Lf89918_00089c2d\n"
        "movzwl -0x40(%ebp), %edx\n" /* line 2162 */
        "movl %edx, -0x38(%ebp)\n" /* value */
        "movb $2, %al\n"
        ".Lf89918_00089c04:\n"
        "movl %eax, -0x34(%ebp)\n" /* line 2175 */
        /* } scope */
        "movl %edx, %ecx\n" /* line 246 | u */
        /* { scope 2 */
        "cmpl $3, %eax\n" /* line 1928 */
        "jg .Lf89918_00089c53\n"
        ".Lf89918_00089c0e:\n"
        "cmpl $2, %eax\n"
        "jl .Lf89918_00089d3a\n"
        "movl -0x38(%ebp), %eax\n" /* line 1935 | value */
        "movl %eax, (%esp)\n"
        "calll SL_AddRefToString\n"
        /* } scope */
        /* } scope */
        "movl -0x44(%ebp), %eax\n" /* line 1020 */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: value */
        /* { scope 2 */
        ".Lf89918_00089c2d:\n"
        "cmpl $0x1fffd, -0x40(%ebp)\n" /* line 2164 */
        "ja .Lf89918_00089c70\n"
        "movl -0x40(%ebp), %ecx\n" /* line 2167 */
        "subl $0x10000, %ecx\n"
        "movl %ecx, -0x38(%ebp)\n" /* value */
        "movl $1, %eax\n"
        "movl %ecx, %edx\n"
        "movl %eax, -0x34(%ebp)\n" /* line 2175 */
        /* } scope */
        "movl %edx, %ecx\n" /* line 246 | u */
        /* { scope 2 */
        "cmpl $3, %eax\n" /* line 1928 */
        "jle .Lf89918_00089c0e\n"
        ".Lf89918_00089c53:\n"
        "cmpl $4, %eax\n"
        "jne .Lf89918_000899f6\n"
        "cmpb $0, -1(%edx)\n" /* line 1879 */
        "jne .Lf89918_000899f6\n"
        "addw $1, -4(%edx)\n" /* line 1894 */
        "jmp .Lf89918_000899f6\n"
        /* } scope */
        /* { scope 2 */
        ".Lf89918_00089c70:\n"
        "movl -0x40(%ebp), %ebx\n" /* line 2172 | newIndex */
        "subl $0x00800000, %ebx\n" /* newIndex */
        "movl %ebx, -0x38(%ebp)\n" /* newIndex, value */
        "movl $6, %eax\n"
        "movl %ebx, %edx\n" /* newIndex */
        "jmp .Lf89918_00089c04\n"
        /* } scope */
        ".Lf89918_00089c88:\n"
        "movzwl 0xc(%edi), %eax\n" /* line 958 | entryValue */
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob+12(%eax), %eax\n"
        "cmpl %eax, -0x44(%ebp)\n"
        "je .Lf89918_00089cc2\n"
        ".Lf89918_00089ca7:\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob+12(%eax), %eax\n"
        "cmpl -0x44(%ebp), %eax\n"
        "jne .Lf89918_00089ca7\n"
        ".Lf89918_00089cc2:\n"
        "shll $4, %edx\n" /* line 965 */
        "movw %bx, scrVarGlob+12(%edx)\n" /* newIndex */
        "jmp .Lf89918_00089a86\n"
        ".Lf89918_00089cd1:\n"
        "movzwl scrVarGlob+4, %eax\n" /* line 889 */
        "movzwl %ax, %ecx\n"
        "movl %ecx, -0x44(%ebp)\n"
        "testw %ax, %ax\n" /* line 890 */
        "je .Lf89918_00089d53\n"
        "movl %ecx, %eax\n"
        ".Lf89918_00089ce5:\n"
        "shll $4, %eax\n" /* line 894 */
        "movzwl scrVarGlob(%eax), %eax\n"
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movzwl 4(%ecx), %eax\n" /* line 898 */
        "movw %ax, scrVarGlob+4\n" /* line 899 */
        "shll $4, %eax\n" /* line 900 */
        "movw $0, scrVarGlob+2(%eax)\n"
        "movl $0x20, 8(%ecx)\n" /* line 902 */
        "movzwl 0xc(%edi), %eax\n" /* line 903 | entryValue */
        "movw %ax, 0xc(%ecx)\n"
        "movl -0x44(%ebp), %ebx\n" /* line 904 | newIndex */
        "movw %bx, 0xc(%edi)\n" /* newIndex, entryValue */
        "jmp .Lf89918_000899cb\n"
        ".Lf89918_00089d29:\n"
        "movl $str_0021d3d8, (%esp)\n" /* line 931 */
        "calll Scr_TerminalError\n"
        "jmp .Lf89918_00089af2\n"
        /* { scope 2 */
        ".Lf89918_00089d3a:\n"
        "subl $1, %eax\n" /* line 1928 */
        "jne .Lf89918_000899f6\n"
        "shll $4, %ecx\n" /* line 1748 */
        "addw $1, scrVarGlob+4(%ecx)\n"
        "jmp .Lf89918_000899f6\n"
        /* } scope */
        ".Lf89918_00089d53:\n"
        "movl $str_0021d3d8, (%esp)\n" /* line 891 */
        "calll Scr_TerminalError\n"
        "movl -0x44(%ebp), %eax\n"
        "jmp .Lf89918_00089ce5\n"
    );
}

/* line 2254 */
__attribute__((naked))
unsigned int GetNewObjectVariableReverse(unsigned int parentId, unsigned int id)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2254 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* parentId */
        "movl 0xc(%ebp), %esi\n" /* line 2258 | id, name */
        "addl $0x10000, %esi\n" /* name */
        "leal (%esi, %edi), %ecx\n" /* line 1113 */
        "movl $0x80018005, %eax\n"
        "mull %ecx\n"
        "movl %edx, %ebx\n"
        "shrl $0xf, %ebx\n"
        "movl %ebx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %ebx, %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n"
        "addl $1, %ecx\n"
        /* { scope 1: siblingIndex */
        /* { scope 2 */
        "movl %esi, %edx\n" /* line 1065 */
        "movl %edi, %eax\n" /* parentValue */
        "calll GetNewVariableIndexInternal3\n"
        "movl %eax, -0x1c(%ebp)\n"
        "shll $4, %edi\n" /* line 1067 | parentValue */
        "addl $scrVarGlob, %edi\n" /* parentValue */
        "movzwl 0xe(%edi), %eax\n" /* line 1068 | parentValue */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+2(%eax), %ecx\n"
        "shll $4, %ecx\n"
        "addl $scrVarGlob, %ecx\n"
        "movzwl 2(%ecx), %eax\n" /* line 1070 */
        "movw %ax, -0x1e(%ebp)\n" /* siblingIndex */
        "movzwl %ax, %eax\n" /* line 1071 */
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %eax\n"
        "shll $4, %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl -0x1c(%ebp), %esi\n" /* line 1073 */
        "shll $4, %esi\n"
        "movzwl scrVarGlob(%esi), %eax\n" /* line 1076 */
        "movl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "movzwl 0xc(%edi), %edx\n" /* parentValue */
        "movw %dx, scrVarGlob+14(%ebx)\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1077 */
        "movw %dx, 2(%ecx)\n"
        "movzwl -0x1e(%ebp), %ecx\n" /* line 1079 | siblingIndex */
        "movw %cx, scrVarGlob+2(%esi)\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 1080 */
        "movl -0x24(%ebp), %edx\n"
        "movw %cx, scrVarGlob+14(%edx)\n"
        /* } scope */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 2259 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2246 */
__attribute__((naked))
unsigned int GetNewObjectVariable(unsigned int parentId, unsigned int id)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2246 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xc, %esp\n"
        "movl 8(%ebp), %ebx\n" /* parentId */
        "movl 0xc(%ebp), %edi\n" /* line 2250 | id, name */
        "addl $0x10000, %edi\n" /* name */
        "leal (%edi, %ebx), %ecx\n" /* line 1096 */
        "movl $0x80018005, %eax\n"
        "mull %ecx\n"
        "movl %edx, %esi\n"
        "shrl $0xf, %esi\n"
        "movl %esi, %eax\n"
        "shll $0xe, %eax\n"
        "subl %esi, %eax\n"
        "leal (%esi, %eax, 4), %eax\n"
        "subl %eax, %ecx\n"
        "addl $1, %ecx\n"
        /* { scope 1 */
        /* { scope 2 */
        "movl %edi, %edx\n" /* line 1033 */
        "movl %ebx, %eax\n" /* parentValue */
        "calll GetNewVariableIndexInternal3\n"
        "shll $4, %ebx\n" /* line 1035 | parentValue */
        "addl $scrVarGlob, %ebx\n" /* parentValue */
        "movzwl 0xe(%ebx), %edx\n" /* line 1037 | parentValue */
        "movl %eax, %esi\n" /* line 1040 */
        "shll $4, %esi\n"
        "movzwl scrVarGlob(%esi), %edi\n" /* line 1043 */
        "movl %edi, %ecx\n"
        "shll $4, %ecx\n"
        "movw %dx, scrVarGlob+14(%ecx)\n"
        "shll $4, %edx\n" /* line 1044 */
        "movw %ax, scrVarGlob+2(%edx)\n"
        "movzwl 0xc(%ebx), %edx\n" /* line 1046 | parentValue */
        "movw %dx, scrVarGlob+2(%esi)\n"
        "movw %ax, 0xe(%ebx)\n" /* line 1047 | parentValue */
        /* } scope */
        /* } scope */
        "movl %edi, %eax\n" /* line 2251 | name */
        "addl $0xc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2456 */
__attribute__((naked))
JCOEF SetVariableEntityFieldValue(unsigned int entId, unsigned int fieldName, VariableValue *value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2456 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 2465 | entId */
        "shll $4, %eax\n"
        "addl $scrVarGlob, %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* entValue */
        "movl 8(%eax), %edi\n" /* line 2468 */
        "shrl $8, %edi\n"
        "movl 0xc(%ebp), %esi\n" /* line 1980 | fieldName, name */
        "addl $0x00800000, %esi\n" /* name */
        "andl $0x00FFFFFF, %esi\n" /* name */
        "leal (%edi, %edi, 2), %eax\n" /* line 801 */
        "movzwl g_classMap(, %eax, 4), %ecx\n" /* index */
        "addl %esi, %ecx\n" /* name, index */
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n" /* index */
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n" /* index */
        "addl $1, %ecx\n" /* index */
        "movzwl %cx, %ecx\n" /* index */
        /* { scope 2: entry */
        /* { scope 3 */
        "movl %ecx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ebx\n" /* entryValue */
        "movl 8(%ebx), %edx\n" /* line 748 | entryValue */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf89ea6_00089fef\n"
        ".Lf89ea6_00089f2c:\n"
        "xorl %ecx, %ecx\n" /* line 759 */
        /* } scope */
        /* } scope */
        ".Lf89ea6_00089f2e:\n"
        "shll $4, %ecx\n" /* line 1986 */
        "movzwl scrVarGlob(%ecx), %eax\n"
        "movzwl %ax, %edx\n"
        "testw %ax, %ax\n" /* line 2469 */
        "je .Lf89ea6_00089f6b\n"
        "movl 0x10(%ebp), %ecx\n" /* line 2471 | value */
        "movl %ecx, 0xc(%esp)\n"
        "shll $4, %edx\n"
        "movl scrVarGlob+4(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x20(%ebp), %esi\n" /* entValue, name */
        "movzwl 6(%esi), %eax\n" /* name */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll SetEntityFieldValue\n"
        "testb %al, %al\n"
        "jne .Lf89ea6_00089fe7\n"
        ".Lf89ea6_00089f6b:\n"
        "movl 8(%ebp), %ecx\n" /* line 1096 | entId */
        "addl 0xc(%ebp), %ecx\n" /* fieldName */
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n"
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n"
        "addl $1, %ecx\n"
        /* { scope 2: entry */
        /* { scope 3 */
        "movl 0xc(%ebp), %edx\n" /* line 1033 | fieldName */
        "movl 8(%ebp), %eax\n" /* entId */
        "calll GetNewVariableIndexInternal3\n"
        "movl -0x20(%ebp), %ecx\n" /* line 1037 | entValue */
        "movzwl 0xe(%ecx), %edx\n"
        "movl %eax, %ebx\n" /* line 1040 | entryValue */
        "shll $4, %ebx\n" /* entryValue */
        "movzwl scrVarGlob(%ebx), %ecx\n" /* line 1043 | entryValue */
        "shll $4, %ecx\n"
        "movw %dx, scrVarGlob+14(%ecx)\n"
        "shll $4, %edx\n" /* line 1044 */
        "movw %ax, scrVarGlob+2(%edx)\n"
        "movl -0x20(%ebp), %esi\n" /* line 1046 | entValue, name */
        "movzwl 0xc(%esi), %edx\n" /* name */
        "movw %dx, scrVarGlob+2(%ebx)\n" /* entryValue */
        "movw %ax, 0xe(%esi)\n" /* line 1047 | name */
        /* } scope */
        /* } scope */
        "addl $scrVarGlob, %ecx\n" /* line 2475 */
        "movl 8(%ecx), %eax\n" /* line 2477 */
        "movl 0x10(%ebp), %edx\n" /* value */
        "orl 4(%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movl (%edx), %eax\n" /* line 2478 */
        "movl %eax, 4(%ecx)\n"
        /* } scope */
        ".Lf89ea6_00089fe7:\n"
        "addl $0x2c, %esp\n" /* line 2479 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: entry */
        /* { scope 3 */
        ".Lf89ea6_00089fef:\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, %esi\n"
        "je .Lf89ea6_00089f2e\n"
        "movzwl 0xc(%ebx), %ecx\n" /* line 757 | entryValue */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x1c(%ebp)\n" /* line 759 | entry */
        "je .Lf89ea6_00089f2c\n"
        ".Lf89ea6_0008a012:\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, %esi\n"
        "je .Lf89ea6_00089f2e\n"
        "movzwl 0xc(%edx), %ecx\n" /* line 771 */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x1c(%ebp)\n" /* line 759 | entry */
        "jne .Lf89ea6_0008a012\n"
        "jmp .Lf89ea6_00089f2c\n"
    );
}

/* line 3721 */
__attribute__((naked))
JCOEF Scr_AddClassField(int classnum, const char *name, unsigned int offset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3721 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* classnum */
        "movl 0xc(%ebp), %edi\n" /* name */
        /* { scope 1 */
        "leal (%eax, %eax, 2), %eax\n" /* line 3730 */
        "movzwl g_classMap(, %eax, 4), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* classId */
        "movl %edi, (%esp)\n" /* line 3732 | name */
        "calll SL_GetCanonicalString\n"
        "leal s_debugFrameGlob+57728(%eax), %esi\n" /* line 2014 | name */
        "andl $0x00FFFFFF, %esi\n" /* name */
        "movl -0x1c(%ebp), %ecx\n" /* line 1096 | classId */
        "addl %esi, %ecx\n" /* parentValue */
        "movl $0x80018005, %eax\n"
        "mull %ecx\n"
        "movl %edx, %ebx\n"
        "shrl $0xf, %ebx\n"
        "movl %ebx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %ebx, %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n"
        "addl $1, %ecx\n"
        /* { scope 2 */
        /* { scope 3 */
        "movl %esi, %edx\n" /* line 1033 | parentValue */
        "movl -0x1c(%ebp), %eax\n" /* classId */
        "calll GetNewVariableIndexInternal3\n"
        "movl -0x1c(%ebp), %esi\n" /* line 1035 | classId, parentValue */
        "shll $4, %esi\n" /* parentValue */
        "addl $scrVarGlob, %esi\n" /* parentValue */
        "movzwl 0xe(%esi), %edx\n" /* line 1037 | parentValue */
        "movl %eax, %ebx\n" /* line 1040 */
        "shll $4, %ebx\n"
        "movzwl scrVarGlob(%ebx), %ecx\n" /* line 1043 */
        "shll $4, %ecx\n"
        "movw %dx, scrVarGlob+14(%ecx)\n"
        "shll $4, %edx\n" /* line 1044 */
        "movw %ax, scrVarGlob+2(%edx)\n"
        "movzwl 0xc(%esi), %edx\n" /* line 1046 | parentValue */
        "movw %dx, scrVarGlob+2(%ebx)\n"
        "movw %ax, 0xe(%esi)\n" /* line 1047 | parentValue */
        /* } scope */
        /* } scope */
        "addl $scrVarGlob, %ecx\n" /* line 3738 */
        "movl 8(%ecx), %eax\n" /* line 3740 */
        "andl $0xffffffe0, %eax\n"
        "orl $6, %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movzwl 0x10(%ebp), %eax\n" /* line 3741 | offset */
        "movl %eax, -0x20(%ebp)\n"
        "movl %eax, 4(%ecx)\n"
        "movl $0xf, 8(%esp)\n" /* line 3743 */
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* name */
        "calll SL_GetString_\n"
        "movl %eax, %edi\n" /* name */
        "movl -0x1c(%ebp), %ecx\n" /* line 1096 | classId */
        "addl %eax, %ecx\n"
        "movl $0x80018005, %eax\n"
        "mull %ecx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n"
        "addl $1, %ecx\n"
        /* { scope 2 */
        /* { scope 3 */
        "movl %edi, %edx\n" /* line 1033 */
        "movl -0x1c(%ebp), %eax\n" /* classId */
        "calll GetNewVariableIndexInternal3\n"
        "movzwl 0xe(%esi), %edx\n" /* line 1037 | parentValue */
        "movl %eax, %ecx\n" /* line 1040 */
        "shll $4, %ecx\n"
        "movzwl scrVarGlob(%ecx), %ebx\n" /* line 1043 */
        "shll $4, %ebx\n"
        "movw %dx, scrVarGlob+14(%ebx)\n"
        "shll $4, %edx\n" /* line 1044 */
        "movw %ax, scrVarGlob+2(%edx)\n"
        "movzwl 0xc(%esi), %edx\n" /* line 1046 | parentValue */
        "movw %dx, scrVarGlob+2(%ecx)\n"
        "movw %ax, 0xe(%esi)\n" /* line 1047 | parentValue */
        /* } scope */
        /* } scope */
        "movl %edi, (%esp)\n" /* line 3748 | name */
        "calll SL_RemoveRefToString\n"
        "addl $scrVarGlob, %ebx\n" /* line 3750 */
        "movl 8(%ebx), %eax\n" /* line 3752 */
        "andl $0xffffffe0, %eax\n"
        "orl $6, %eax\n"
        "movl %eax, 8(%ebx)\n"
        "movl -0x20(%ebp), %edx\n" /* line 3753 */
        "movl %edx, 4(%ebx)\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 3754 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2220 */
__attribute__((naked))
unsigned int GetNewArrayVariable(unsigned int parentId, unsigned int unsignedValue)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2220 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xc, %esp\n"
        "movl 8(%ebp), %ebx\n" /* parentId */
        "movl 0xc(%ebp), %edi\n" /* line 2014 | unsignedValue, name */
        "addl $0x00800000, %edi\n" /* name */
        "andl $0x00FFFFFF, %edi\n" /* name */
        "leal (%ebx, %edi), %ecx\n" /* line 1096 | parentValue */
        "movl $0x80018005, %eax\n"
        "mull %ecx\n"
        "movl %edx, %esi\n"
        "shrl $0xf, %esi\n"
        "movl %esi, %eax\n"
        "shll $0xe, %eax\n"
        "subl %esi, %eax\n"
        "leal (%esi, %eax, 4), %eax\n"
        "subl %eax, %ecx\n"
        "addl $1, %ecx\n"
        /* { scope 1 */
        /* { scope 2 */
        "movl %edi, %edx\n" /* line 1033 */
        "movl %ebx, %eax\n" /* parentValue */
        "calll GetNewVariableIndexInternal3\n"
        "shll $4, %ebx\n" /* line 1035 | parentValue */
        "addl $scrVarGlob, %ebx\n" /* parentValue */
        "movzwl 0xe(%ebx), %edx\n" /* line 1037 | parentValue */
        "movl %eax, %esi\n" /* line 1040 */
        "shll $4, %esi\n"
        "movzwl scrVarGlob(%esi), %edi\n" /* line 1043 */
        "movl %edi, %ecx\n"
        "shll $4, %ecx\n"
        "movw %dx, scrVarGlob+14(%ecx)\n"
        "shll $4, %edx\n" /* line 1044 */
        "movw %ax, scrVarGlob+2(%edx)\n"
        "movzwl 0xc(%ebx), %edx\n" /* line 1046 | parentValue */
        "movw %dx, scrVarGlob+2(%esi)\n"
        "movw %ax, 0xe(%ebx)\n" /* line 1047 | parentValue */
        /* } scope */
        /* } scope */
        "movl %edi, %eax\n" /* line 2223 | name */
        "addl $0xc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2232 */
__attribute__((naked))
unsigned int GetNewVariable(unsigned int parentId, unsigned int unsignedValue)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2232 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xc, %esp\n"
        "movl 8(%ebp), %ebx\n" /* parentId */
        "movl 0xc(%ebp), %edi\n" /* unsignedValue */
        "leal (%ebx, %edi), %ecx\n" /* line 1096 | parentValue */
        "movl $0x80018005, %eax\n"
        "mull %ecx\n"
        "movl %edx, %esi\n"
        "shrl $0xf, %esi\n"
        "movl %esi, %eax\n"
        "shll $0xe, %eax\n"
        "subl %esi, %eax\n"
        "leal (%esi, %eax, 4), %eax\n"
        "subl %eax, %ecx\n"
        "addl $1, %ecx\n"
        /* { scope 1 */
        /* { scope 2 */
        "movl %edi, %edx\n" /* line 1033 */
        "movl %ebx, %eax\n" /* parentValue */
        "calll GetNewVariableIndexInternal3\n"
        "shll $4, %ebx\n" /* line 1035 | parentValue */
        "addl $scrVarGlob, %ebx\n" /* parentValue */
        "movzwl 0xe(%ebx), %edx\n" /* line 1037 | parentValue */
        "movl %eax, %esi\n" /* line 1040 */
        "shll $4, %esi\n"
        "movzwl scrVarGlob(%esi), %edi\n" /* line 1043 */
        "movl %edi, %ecx\n"
        "shll $4, %ecx\n"
        "movw %dx, scrVarGlob+14(%ecx)\n"
        "shll $4, %edx\n" /* line 1044 */
        "movw %ax, scrVarGlob+2(%edx)\n"
        "movzwl 0xc(%ebx), %edx\n" /* line 1046 | parentValue */
        "movw %dx, scrVarGlob+2(%esi)\n"
        "movw %ax, 0xe(%ebx)\n" /* line 1047 | parentValue */
        /* } scope */
        /* } scope */
        "movl %edi, %eax\n" /* line 2235 | unsignedValue */
        "addl $0xc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 4313 */
static __attribute__((naked))
float Scr_GetObjectUsage(void)
{
    __asm__ __volatile__ (
        ".Lf8a2a6_0008a2a6:\n"
        "pushl %ebp\n" /* line 4313 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xcc, %esp\n"
        /* { scope 1 */
        "movl %eax, %edx\n" /* line 2654 */
        "shll $4, %edx\n"
        "movzwl scrVarGlob+14(%edx), %edx\n"
        "shll $4, %edx\n"
        "movzwl scrVarGlob(%edx), %edx\n"
        "movzwl %dx, %ebx\n"
        "cmpl %ebx, %eax\n" /* line 2660 */
        "je .Lf8a2a6_0008a431\n"
        "movl %ebx, %eax\n" /* line 2665 */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8a2a6_0008a431\n"
        "testw %dx, %dx\n" /* line 4325 */
        "je .Lf8a2a6_0008a431\n"
        "movss lit4_002ed5d0, %xmm2\n" /* 1.0f */
        "movaps %xmm2, %xmm3\n"
        "movl %ebx, %eax\n" /* line 4326 | id, entryValue */
        "shll $4, %eax\n" /* entryValue */
        "addl $scrVarGlob, %eax\n" /* entryValue */
        /* { scope 2 */
        "movl 4(%eax), %ecx\n" /* line 4292 */
        "movl 8(%eax), %eax\n" /* type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 3 */
        /* { scope 4 */
        "subl $1, %eax\n" /* line 4274 */
        "je .Lf8a2a6_0008a378\n"
        ".Lf8a2a6_0008a316:\n"
        "movaps %xmm3, %xmm0\n" /* line 4281 */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf8a2a6_0008a319:\n"
        "addss %xmm0, %xmm2\n" /* line 4326 */
        "movl %ebx, %eax\n" /* line 2654 */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "movzwl %cx, %edx\n"
        "cmpl %edx, %ebx\n" /* line 2660 */
        "je .Lf8a2a6_0008a439\n"
        "movl %edx, %eax\n" /* line 2665 */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8a2a6_0008a439\n"
        "testw %cx, %cx\n" /* line 4325 */
        "je .Lf8a2a6_0008a439\n"
        "movl %edx, %ebx\n" /* id */
        "movl %ebx, %eax\n" /* line 4326 | id, entryValue */
        "shll $4, %eax\n" /* entryValue */
        "addl $scrVarGlob, %eax\n" /* entryValue */
        /* { scope 2 */
        "movl 4(%eax), %ecx\n" /* line 4292 */
        "movl 8(%eax), %eax\n" /* type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 3 */
        /* { scope 4 */
        "subl $1, %eax\n" /* line 4274 */
        "jne .Lf8a2a6_0008a316\n"
        ".Lf8a2a6_0008a378:\n"
        "movl %ecx, %edx\n" /* line 4277 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %edi\n" /* parentValue */
        "movl 8(%edi), %eax\n" /* line 4281 | parentValue */
        "andl $0x1f, %eax\n"
        "cmpl $0x16, %eax\n"
        "jne .Lf8a2a6_0008a316\n"
        /* { scope 5 */
        "movzwl scrVarGlob+14(%edx), %eax\n" /* line 2654 */
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %edx\n"
        "movzwl %dx, %esi\n"
        "cmpl %esi, %ecx\n" /* line 2660 */
        "je .Lf8a2a6_0008a5ea\n"
        "movl %esi, %eax\n" /* line 2665 */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8a2a6_0008a5ea\n"
        "testw %dx, %dx\n" /* line 4325 */
        "je .Lf8a2a6_0008a5ea\n"
        "movaps %xmm3, %xmm4\n"
        ".Lf8a2a6_0008a3cd:\n"
        "movl %esi, %eax\n" /* line 4326 | id, entryValue */
        "shll $4, %eax\n" /* entryValue */
        "addl $scrVarGlob, %eax\n" /* entryValue */
        /* { scope 6 */
        "movl 4(%eax), %ecx\n" /* line 4292 */
        "movl 8(%eax), %eax\n" /* type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 7: parentValue */
        /* { scope 8: usage */
        "subl $1, %eax\n" /* line 4274 */
        "je .Lf8a2a6_0008a447\n"
        ".Lf8a2a6_0008a3e5:\n"
        "movaps %xmm3, %xmm0\n" /* line 4281 */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf8a2a6_0008a3e8:\n"
        "addss %xmm0, %xmm4\n" /* line 4326 */
        /* { scope 6 */
        "movl %esi, %eax\n" /* line 2654 */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "movzwl %cx, %edx\n"
        "cmpl %edx, %esi\n" /* line 2660 */
        "je .Lf8a2a6_0008a5ed\n"
        "movl %edx, %eax\n" /* line 2665 */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8a2a6_0008a5ed\n"
        /* } scope */
        "testw %cx, %cx\n" /* line 4325 */
        "je .Lf8a2a6_0008a5ed\n"
        "movl %edx, %esi\n" /* id */
        "jmp .Lf8a2a6_0008a3cd\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf8a2a6_0008a431:\n"
        "movss lit4_002ed5d0, %xmm2\n" /* 1.0f */
        /* } scope */
        ".Lf8a2a6_0008a439:\n"
        "movaps %xmm2, %xmm0\n" /* line 4329 */
        "addl $0xcc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        /* { scope 5 */
        /* { scope 6 */
        /* { scope 7: parentValue */
        /* { scope 8: usage */
        ".Lf8a2a6_0008a447:\n"
        "movl %ecx, %eax\n" /* line 4277 */
        "shll $4, %eax\n"
        "movl %eax, -0xcc(%ebp)\n"
        "addl $scrVarGlob, %eax\n"
        "movl %eax, -0x64(%ebp)\n" /* parentValue */
        "movl 8(%eax), %edx\n" /* line 4281 */
        "andl $0x1f, %edx\n"
        "cmpl $0x16, %edx\n"
        "jne .Lf8a2a6_0008a3e5\n"
        /* { scope 9: id */
        "movl -0xcc(%ebp), %edx\n" /* line 2654 */
        "movzwl scrVarGlob+14(%edx), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %edx\n"
        "movzwl %dx, %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* id */
        "cmpl %eax, %ecx\n" /* line 2660 */
        "je .Lf8a2a6_0008a609\n"
        "shll $4, %eax\n" /* line 2665 */
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8a2a6_0008a609\n"
        "testw %dx, %dx\n" /* line 4325 */
        "je .Lf8a2a6_0008a609\n"
        "movss %xmm3, -0x60(%ebp)\n" /* usage */
        "movl -0x1c(%ebp), %eax\n" /* id, parentId */
        ".Lf8a2a6_0008a4b0:\n"
        "shll $4, %eax\n" /* line 4326 | entryValue */
        "addl $scrVarGlob, %eax\n" /* entryValue */
        /* { scope 10 */
        "movl 4(%eax), %ecx\n" /* line 4292 */
        "movl 8(%eax), %eax\n" /* type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 11: parentValue */
        /* { scope 12: usage */
        "subl $1, %eax\n" /* line 4274 */
        "je .Lf8a2a6_0008a51d\n"
        ".Lf8a2a6_0008a4c6:\n"
        "movaps %xmm3, %xmm0\n" /* line 4281 */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf8a2a6_0008a4c9:\n"
        "addss -0x60(%ebp), %xmm0\n" /* line 4326 | usage */
        "movss %xmm0, -0x60(%ebp)\n" /* usage */
        /* { scope 10 */
        "movl -0x1c(%ebp), %eax\n" /* line 2654 | id */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "movzwl %cx, %edx\n"
        "cmpl %edx, -0x1c(%ebp)\n" /* line 2660 | id */
        "je .Lf8a2a6_0008a637\n"
        "movl %edx, %eax\n" /* line 2665 */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8a2a6_0008a630\n"
        /* } scope */
        "testw %cx, %cx\n" /* line 4325 */
        "je .Lf8a2a6_0008a630\n"
        "movl %edx, -0x1c(%ebp)\n" /* id */
        "movl %edx, %eax\n" /* parentId */
        "jmp .Lf8a2a6_0008a4b0\n"
        /* { scope 10 */
        /* { scope 11: parentValue */
        /* { scope 12: usage */
        ".Lf8a2a6_0008a51d:\n"
        "movl %ecx, %edx\n" /* line 4277 */
        "shll $4, %edx\n"
        "movl %edx, -0xcc(%ebp)\n"
        "addl $scrVarGlob, %edx\n"
        "movl %edx, -0x5c(%ebp)\n" /* parentValue */
        "movl 8(%edx), %eax\n" /* line 4281 */
        "andl $0x1f, %eax\n"
        "cmpl $0x16, %eax\n"
        "jne .Lf8a2a6_0008a4c6\n"
        /* { scope 13: id */
        "movl -0xcc(%ebp), %edx\n" /* line 2654 */
        "movzwl scrVarGlob+14(%edx), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %edx\n"
        "movzwl %dx, %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* id */
        "cmpl %eax, %ecx\n" /* line 2660 */
        "je .Lf8a2a6_0008a63c\n"
        "shll $4, %eax\n" /* line 2665 */
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8a2a6_0008a63c\n"
        "testw %dx, %dx\n" /* line 4325 */
        "je .Lf8a2a6_0008a63c\n"
        "movss %xmm3, -0x58(%ebp)\n" /* usage */
        ".Lf8a2a6_0008a584:\n"
        "movl -0x20(%ebp), %eax\n" /* line 4326 | id, entryValue */
        "shll $4, %eax\n" /* entryValue */
        "addl $scrVarGlob, %eax\n" /* entryValue */
        /* { scope 14 */
        "movl 4(%eax), %ecx\n" /* line 4292 */
        "movl 8(%eax), %eax\n" /* type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 15: parentValue */
        /* { scope 16: usage */
        "subl $1, %eax\n" /* line 4274 */
        "je .Lf8a2a6_0008a665\n"
        ".Lf8a2a6_0008a5a1:\n"
        "movaps %xmm3, %xmm0\n" /* line 4281 */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf8a2a6_0008a5a4:\n"
        "addss -0x58(%ebp), %xmm0\n" /* line 4326 | usage */
        "movss %xmm0, -0x58(%ebp)\n" /* usage */
        /* { scope 14 */
        "movl -0x20(%ebp), %eax\n" /* line 2654 | id */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "movzwl %cx, %edx\n"
        "cmpl %edx, -0x20(%ebp)\n" /* line 2660 | id */
        "je .Lf8a2a6_0008a641\n"
        "movl %edx, %eax\n" /* line 2665 */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8a2a6_0008a641\n"
        /* } scope */
        "testw %cx, %cx\n" /* line 4325 */
        "je .Lf8a2a6_0008a641\n"
        "movl %edx, -0x20(%ebp)\n" /* id */
        "jmp .Lf8a2a6_0008a584\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf8a2a6_0008a5ea:\n"
        "movaps %xmm3, %xmm4\n"
        ".Lf8a2a6_0008a5ed:\n"
        "movzwl 4(%edi), %eax\n" /* parentValue, parentId */
        "cvtsi2ssl %eax, %xmm0\n" /* parentId */
        "addss %xmm3, %xmm0\n"
        "divss %xmm0, %xmm4\n"
        "movaps %xmm4, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "jmp .Lf8a2a6_0008a319\n"
        /* { scope 6 */
        /* { scope 7: parentValue */
        /* { scope 8: usage */
        /* { scope 9: id */
        ".Lf8a2a6_0008a609:\n"
        "movss %xmm3, -0x60(%ebp)\n" /* usage */
        "movaps %xmm3, %xmm1\n"
        ".Lf8a2a6_0008a611:\n"
        "movl -0x64(%ebp), %edx\n" /* parentValue */
        "movzwl 4(%edx), %eax\n" /* parentId */
        "cvtsi2ssl %eax, %xmm0\n" /* parentId */
        "addss %xmm3, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "jmp .Lf8a2a6_0008a3e8\n"
        ".Lf8a2a6_0008a630:\n"
        "movss -0x60(%ebp), %xmm1\n" /* usage */
        "jmp .Lf8a2a6_0008a611\n"
        ".Lf8a2a6_0008a637:\n"
        "movaps %xmm0, %xmm1\n"
        "jmp .Lf8a2a6_0008a611\n"
        /* { scope 10 */
        /* { scope 11: parentValue */
        /* { scope 12: usage */
        /* { scope 13: id */
        ".Lf8a2a6_0008a63c:\n"
        "movss %xmm3, -0x58(%ebp)\n" /* usage */
        ".Lf8a2a6_0008a641:\n"
        "movl -0x5c(%ebp), %edx\n" /* parentValue */
        "movzwl 4(%edx), %eax\n" /* parentId */
        "cvtsi2ssl %eax, %xmm0\n" /* parentId */
        "addss %xmm3, %xmm0\n"
        "movss -0x58(%ebp), %xmm1\n" /* usage */
        "divss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "jmp .Lf8a2a6_0008a4c9\n"
        /* { scope 14 */
        /* { scope 15: parentValue */
        /* { scope 16: usage */
        ".Lf8a2a6_0008a665:\n"
        "movl %ecx, %edx\n" /* line 4277 */
        "shll $4, %edx\n"
        "movl %edx, -0xcc(%ebp)\n"
        "addl $scrVarGlob, %edx\n"
        "movl %edx, -0x54(%ebp)\n" /* parentValue */
        "movl 8(%edx), %eax\n" /* line 4281 */
        "andl $0x1f, %eax\n"
        "cmpl $0x16, %eax\n"
        "jne .Lf8a2a6_0008a5a1\n"
        /* { scope 17: id */
        "movl -0xcc(%ebp), %edx\n" /* line 2654 */
        "movzwl scrVarGlob+14(%edx), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %edx\n"
        "movzwl %dx, %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* id */
        "cmpl %eax, %ecx\n" /* line 2660 */
        "je .Lf8a2a6_0008a726\n"
        "shll $4, %eax\n" /* line 2665 */
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8a2a6_0008a726\n"
        "testw %dx, %dx\n" /* line 4325 */
        "je .Lf8a2a6_0008a726\n"
        "movss %xmm3, -0x50(%ebp)\n" /* usage */
        ".Lf8a2a6_0008a6c4:\n"
        "movl -0x24(%ebp), %eax\n" /* line 4326 | id, entryValue */
        "shll $4, %eax\n" /* entryValue */
        "addl $scrVarGlob, %eax\n" /* entryValue */
        /* { scope 18 */
        "movl 4(%eax), %ecx\n" /* line 4292 */
        "movl 8(%eax), %eax\n" /* type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 19: parentValue */
        /* { scope 20: usage */
        "subl $1, %eax\n" /* line 4274 */
        "je .Lf8a2a6_0008a74f\n"
        ".Lf8a2a6_0008a6dd:\n"
        "movaps %xmm3, %xmm0\n" /* line 4281 */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf8a2a6_0008a6e0:\n"
        "addss -0x50(%ebp), %xmm0\n" /* line 4326 | usage */
        "movss %xmm0, -0x50(%ebp)\n" /* usage */
        /* { scope 18 */
        "movl -0x24(%ebp), %eax\n" /* line 2654 | id */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "movzwl %cx, %edx\n"
        "cmpl %edx, -0x24(%ebp)\n" /* line 2660 | id */
        "je .Lf8a2a6_0008a72b\n"
        "movl %edx, %eax\n" /* line 2665 */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8a2a6_0008a72b\n"
        /* } scope */
        "testw %cx, %cx\n" /* line 4325 */
        "je .Lf8a2a6_0008a72b\n"
        "movl %edx, -0x24(%ebp)\n" /* id */
        "jmp .Lf8a2a6_0008a6c4\n"
        ".Lf8a2a6_0008a726:\n"
        "movss %xmm3, -0x50(%ebp)\n" /* usage */
        ".Lf8a2a6_0008a72b:\n"
        "movl -0x54(%ebp), %edx\n" /* parentValue */
        "movzwl 4(%edx), %eax\n" /* parentId */
        "cvtsi2ssl %eax, %xmm0\n" /* parentId */
        "addss %xmm3, %xmm0\n"
        "movss -0x50(%ebp), %xmm1\n" /* usage */
        "divss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "jmp .Lf8a2a6_0008a5a4\n"
        /* { scope 18 */
        /* { scope 19: parentValue */
        /* { scope 20: usage */
        ".Lf8a2a6_0008a74f:\n"
        "movl %ecx, %edx\n" /* line 4277 */
        "shll $4, %edx\n"
        "movl %edx, -0xcc(%ebp)\n"
        "addl $scrVarGlob, %edx\n"
        "movl %edx, -0x4c(%ebp)\n" /* parentValue */
        "movl 8(%edx), %eax\n" /* line 4281 */
        "andl $0x1f, %eax\n"
        "cmpl $0x16, %eax\n"
        "jne .Lf8a2a6_0008a6dd\n"
        /* { scope 21: id */
        "movl -0xcc(%ebp), %edx\n" /* line 2654 */
        "movzwl scrVarGlob+14(%edx), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %edx\n"
        "movzwl %dx, %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* id */
        "cmpl %eax, %ecx\n" /* line 2660 */
        "je .Lf8a2a6_0008a810\n"
        "shll $4, %eax\n" /* line 2665 */
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8a2a6_0008a810\n"
        "testw %dx, %dx\n" /* line 4325 */
        "je .Lf8a2a6_0008a810\n"
        "movss %xmm3, -0x48(%ebp)\n" /* usage */
        ".Lf8a2a6_0008a7ae:\n"
        "movl -0x28(%ebp), %eax\n" /* line 4326 | id, entryValue */
        "shll $4, %eax\n" /* entryValue */
        "addl $scrVarGlob, %eax\n" /* entryValue */
        /* { scope 22 */
        "movl 4(%eax), %ecx\n" /* line 4292 */
        "movl 8(%eax), %eax\n" /* type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 23: parentValue */
        /* { scope 24 */
        "subl $1, %eax\n" /* line 4274 */
        "je .Lf8a2a6_0008a839\n"
        ".Lf8a2a6_0008a7c7:\n"
        "movaps %xmm3, %xmm0\n" /* line 4281 */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf8a2a6_0008a7ca:\n"
        "addss -0x48(%ebp), %xmm0\n" /* line 4326 | usage */
        "movss %xmm0, -0x48(%ebp)\n" /* usage */
        /* { scope 22 */
        "movl -0x28(%ebp), %eax\n" /* line 2654 | id */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "movzwl %cx, %edx\n"
        "cmpl %edx, -0x28(%ebp)\n" /* line 2660 | id */
        "je .Lf8a2a6_0008a815\n"
        "movl %edx, %eax\n" /* line 2665 */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8a2a6_0008a815\n"
        /* } scope */
        "testw %cx, %cx\n" /* line 4325 */
        "je .Lf8a2a6_0008a815\n"
        "movl %edx, -0x28(%ebp)\n" /* id */
        "jmp .Lf8a2a6_0008a7ae\n"
        ".Lf8a2a6_0008a810:\n"
        "movss %xmm3, -0x48(%ebp)\n" /* usage */
        ".Lf8a2a6_0008a815:\n"
        "movl -0x4c(%ebp), %edx\n" /* parentValue */
        "movzwl 4(%edx), %eax\n" /* parentId */
        "cvtsi2ssl %eax, %xmm0\n" /* parentId */
        "addss %xmm3, %xmm0\n"
        "movss -0x48(%ebp), %xmm1\n" /* usage */
        "divss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "jmp .Lf8a2a6_0008a6e0\n"
        /* { scope 22 */
        /* { scope 23: parentValue */
        /* { scope 24 */
        ".Lf8a2a6_0008a839:\n"
        "movl %ecx, %edx\n" /* line 4277 */
        "shll $4, %edx\n"
        "movl %edx, -0xcc(%ebp)\n"
        "addl $scrVarGlob, %edx\n"
        "movl %edx, -0x44(%ebp)\n" /* parentValue */
        "movl 8(%edx), %eax\n" /* line 4281 */
        "andl $0x1f, %eax\n"
        "cmpl $0x16, %eax\n"
        "jne .Lf8a2a6_0008a7c7\n"
        /* { scope 25: id */
        "movl -0xcc(%ebp), %edx\n" /* line 2654 */
        "movzwl scrVarGlob+14(%edx), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %edx\n"
        "movzwl %dx, %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* id */
        "cmpl %eax, %ecx\n" /* line 2660 */
        "je .Lf8a2a6_0008a8f2\n"
        "shll $4, %eax\n" /* line 2665 */
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8a2a6_0008a8f2\n"
        "testw %dx, %dx\n" /* line 4325 */
        "je .Lf8a2a6_0008a8f2\n"
        "movaps %xmm3, %xmm7\n"
        ".Lf8a2a6_0008a896:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 4326 | id, entryValue */
        "shll $4, %eax\n" /* entryValue */
        "addl $scrVarGlob, %eax\n" /* entryValue */
        /* { scope 26 */
        "movl 4(%eax), %ecx\n" /* line 4292 */
        "movl 8(%eax), %eax\n" /* type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 27: parentValue */
        /* { scope 28 */
        "subl $1, %eax\n" /* line 4274 */
        "je .Lf8a2a6_0008a914\n"
        ".Lf8a2a6_0008a8af:\n"
        "movaps %xmm3, %xmm0\n" /* line 4281 */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf8a2a6_0008a8b2:\n"
        "addss %xmm0, %xmm7\n" /* line 4326 */
        /* { scope 26 */
        "movl -0x2c(%ebp), %eax\n" /* line 2654 | id */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "movzwl %cx, %edx\n"
        "cmpl %edx, -0x2c(%ebp)\n" /* line 2660 | id */
        "je .Lf8a2a6_0008a8f5\n"
        "movl %edx, %eax\n" /* line 2665 */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8a2a6_0008a8f5\n"
        /* } scope */
        "testw %cx, %cx\n" /* line 4325 */
        "je .Lf8a2a6_0008a8f5\n"
        "movl %edx, -0x2c(%ebp)\n" /* id */
        "jmp .Lf8a2a6_0008a896\n"
        ".Lf8a2a6_0008a8f2:\n"
        "movaps %xmm3, %xmm7\n"
        ".Lf8a2a6_0008a8f5:\n"
        "movl -0x44(%ebp), %ecx\n" /* parentValue */
        "movzwl 4(%ecx), %eax\n" /* parentId */
        "cvtsi2ssl %eax, %xmm0\n" /* parentId */
        "addss %xmm3, %xmm0\n"
        "divss %xmm0, %xmm7\n"
        "movaps %xmm7, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "jmp .Lf8a2a6_0008a7ca\n"
        /* { scope 26 */
        /* { scope 27: parentValue */
        /* { scope 28 */
        ".Lf8a2a6_0008a914:\n"
        "movl %ecx, %edx\n" /* line 4277 */
        "shll $4, %edx\n"
        "movl %edx, -0xcc(%ebp)\n"
        "addl $scrVarGlob, %edx\n"
        "movl %edx, -0x40(%ebp)\n" /* parentValue */
        "movl 8(%edx), %eax\n" /* line 4281 */
        "andl $0x1f, %eax\n"
        "cmpl $0x16, %eax\n"
        "jne .Lf8a2a6_0008a8af\n"
        /* { scope 29: id */
        "movl -0xcc(%ebp), %edx\n" /* line 2654 */
        "movzwl scrVarGlob+14(%edx), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %edx\n"
        "movzwl %dx, %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* id */
        "cmpl %eax, %ecx\n" /* line 2660 */
        "je .Lf8a2a6_0008a9cd\n"
        "shll $4, %eax\n" /* line 2665 */
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8a2a6_0008a9cd\n"
        "testw %dx, %dx\n" /* line 4325 */
        "je .Lf8a2a6_0008a9cd\n"
        "movaps %xmm3, %xmm6\n"
        ".Lf8a2a6_0008a971:\n"
        "movl -0x30(%ebp), %eax\n" /* line 4326 | id, entryValue */
        "shll $4, %eax\n" /* entryValue */
        "addl $scrVarGlob, %eax\n" /* entryValue */
        /* { scope 30 */
        "movl 4(%eax), %ecx\n" /* line 4292 */
        "movl 8(%eax), %eax\n" /* type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 31: parentValue */
        /* { scope 32 */
        "subl $1, %eax\n" /* line 4274 */
        "je .Lf8a2a6_0008a9ef\n"
        ".Lf8a2a6_0008a98a:\n"
        "movaps %xmm3, %xmm0\n" /* line 4281 */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf8a2a6_0008a98d:\n"
        "addss %xmm0, %xmm6\n" /* line 4326 */
        /* { scope 30 */
        "movl -0x30(%ebp), %eax\n" /* line 2654 | id */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "movzwl %cx, %edx\n"
        "cmpl %edx, -0x30(%ebp)\n" /* line 2660 | id */
        "je .Lf8a2a6_0008a9d0\n"
        "movl %edx, %eax\n" /* line 2665 */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8a2a6_0008a9d0\n"
        /* } scope */
        "testw %cx, %cx\n" /* line 4325 */
        "je .Lf8a2a6_0008a9d0\n"
        "movl %edx, -0x30(%ebp)\n" /* id */
        "jmp .Lf8a2a6_0008a971\n"
        ".Lf8a2a6_0008a9cd:\n"
        "movaps %xmm3, %xmm6\n"
        ".Lf8a2a6_0008a9d0:\n"
        "movl -0x40(%ebp), %edx\n" /* parentValue */
        "movzwl 4(%edx), %eax\n" /* parentId */
        "cvtsi2ssl %eax, %xmm0\n" /* parentId */
        "addss %xmm3, %xmm0\n"
        "divss %xmm0, %xmm6\n"
        "movaps %xmm6, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "jmp .Lf8a2a6_0008a8b2\n"
        /* { scope 30 */
        /* { scope 31: parentValue */
        /* { scope 32 */
        ".Lf8a2a6_0008a9ef:\n"
        "movl %ecx, %edx\n" /* line 4277 */
        "shll $4, %edx\n"
        "movl %edx, -0xcc(%ebp)\n"
        "addl $scrVarGlob, %edx\n"
        "movl %edx, -0x3c(%ebp)\n" /* parentValue */
        "movl 8(%edx), %eax\n" /* line 4281 */
        "andl $0x1f, %eax\n"
        "cmpl $0x16, %eax\n"
        "jne .Lf8a2a6_0008a98a\n"
        /* { scope 33: id */
        "movl -0xcc(%ebp), %edx\n" /* line 2654 */
        "movzwl scrVarGlob+14(%edx), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %edx\n"
        "movzwl %dx, %eax\n"
        "movl %eax, -0x34(%ebp)\n" /* id */
        "cmpl %eax, %ecx\n" /* line 2660 */
        "je .Lf8a2a6_0008aaa8\n"
        "shll $4, %eax\n" /* line 2665 */
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8a2a6_0008aaa8\n"
        "testw %dx, %dx\n" /* line 4325 */
        "je .Lf8a2a6_0008aaa8\n"
        "movaps %xmm3, %xmm5\n"
        ".Lf8a2a6_0008aa4c:\n"
        "movl -0x34(%ebp), %eax\n" /* line 4326 | id, entryValue */
        "shll $4, %eax\n" /* entryValue */
        "addl $scrVarGlob, %eax\n" /* entryValue */
        /* { scope 34 */
        "movl 4(%eax), %edx\n" /* line 4292 */
        "movl 8(%eax), %eax\n" /* type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 35: parentValue */
        /* { scope 36 */
        "subl $1, %eax\n" /* line 4274 */
        "je .Lf8a2a6_0008aaca\n"
        ".Lf8a2a6_0008aa65:\n"
        "movaps %xmm3, %xmm0\n" /* line 4281 */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf8a2a6_0008aa68:\n"
        "addss %xmm0, %xmm5\n" /* line 4326 */
        /* { scope 34 */
        "movl -0x34(%ebp), %eax\n" /* line 2654 | id */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "movzwl %cx, %edx\n"
        "cmpl %edx, -0x34(%ebp)\n" /* line 2660 | id */
        "je .Lf8a2a6_0008aaab\n"
        "movl %edx, %eax\n" /* line 2665 */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8a2a6_0008aaab\n"
        /* } scope */
        "testw %cx, %cx\n" /* line 4325 */
        "je .Lf8a2a6_0008aaab\n"
        "movl %edx, -0x34(%ebp)\n" /* id */
        "jmp .Lf8a2a6_0008aa4c\n"
        ".Lf8a2a6_0008aaa8:\n"
        "movaps %xmm3, %xmm5\n"
        ".Lf8a2a6_0008aaab:\n"
        "movl -0x3c(%ebp), %ecx\n" /* parentValue */
        "movzwl 4(%ecx), %eax\n" /* parentId */
        "cvtsi2ssl %eax, %xmm0\n" /* parentId */
        "addss %xmm3, %xmm0\n"
        "divss %xmm0, %xmm5\n"
        "movaps %xmm5, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "jmp .Lf8a2a6_0008a98d\n"
        /* { scope 34 */
        /* { scope 35: parentValue */
        /* { scope 36 */
        ".Lf8a2a6_0008aaca:\n"
        "movl %edx, %eax\n" /* line 4277 */
        "shll $4, %eax\n"
        "addl $scrVarGlob, %eax\n"
        "movl %eax, -0x38(%ebp)\n" /* parentValue */
        "movl 8(%eax), %eax\n" /* line 4281 */
        "andl $0x1f, %eax\n"
        "cmpl $0x16, %eax\n"
        "jne .Lf8a2a6_0008aa65\n"
        "movl %edx, %eax\n" /* line 4282 */
        "movss %xmm2, -0x78(%ebp)\n"
        "movss %xmm4, -0x88(%ebp)\n"
        "movss %xmm5, -0x98(%ebp)\n"
        "movss %xmm6, -0xa8(%ebp)\n"
        "movss %xmm7, -0xb8(%ebp)\n"
        "calll Scr_GetObjectUsage\n"
        "movl -0x38(%ebp), %edx\n" /* parentValue */
        "movzwl 4(%edx), %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        "addss %xmm3, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "movss -0xb8(%ebp), %xmm7\n"
        "movss -0xa8(%ebp), %xmm6\n"
        "movss -0x98(%ebp), %xmm5\n"
        "movss -0x88(%ebp), %xmm4\n"
        "movss -0x78(%ebp), %xmm2\n"
        "jmp .Lf8a2a6_0008aa68\n"
    );
}

/* line 384 */
__attribute__((naked))
JCOEF Scr_DumpScriptThreads(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 384 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x13c, %esp\n"
        /* { scope 1: endonUsage, i */
        "movl $0x008BFEE8, (%esp)\n" /* line 404 */
        "calll Z_TryMallocInternal\n"
        "movl %eax, -0x108(%ebp)\n" /* infoArray */
        "testl %eax, %eax\n" /* line 405 */
        "je .Lf8ab58_0008b9d3\n"
        "movl $0, -0x104(%ebp)\n" /* line 408 | num */
        "movl $1, -0x10c(%ebp)\n" /* id */
        "movl $scrVarGlob+16, -0x114(%ebp)\n"
        "movl -0x108(%ebp), %eax\n" /* infoArray */
        "movl %eax, -0x118(%ebp)\n"
        "jmp .Lf8ab58_0008abc8\n"
        ".Lf8ab58_0008abaa:\n"
        "addl $1, -0x10c(%ebp)\n" /* line 413 | id */
        "addl $0x10, -0x114(%ebp)\n"
        "cmpl $0xfffe, -0x10c(%ebp)\n" /* id */
        "je .Lf8ab58_0008b051\n"
        ".Lf8ab58_0008abc8:\n"
        "movl -0x114(%ebp), %edx\n" /* line 416 */
        "movl 8(%edx), %eax\n"
        "testb $0x60, %al\n"
        "je .Lf8ab58_0008abaa\n"
        "andl $0x1f, %eax\n" /* line 418 */
        "cmpl $0xa, %eax\n"
        "jne .Lf8ab58_0008abaa\n"
        "movl -0x118(%ebp), %ecx\n" /* line 420 */
        "movl %ecx, -0xb4(%ebp)\n"
        "addl $1, -0x104(%ebp)\n" /* line 421 | num */
        "addl $0x8c, %ecx\n"
        "movl %ecx, -0x118(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 424 */
        "movl %eax, -0xf8(%ebp)\n" /* stackBuf */
        "movzwl 4(%eax), %edx\n" /* line 425 */
        "movw %dx, -0x10e(%ebp)\n"
        "movzwl %dx, %ecx\n"
        "movl %ecx, -0xf4(%ebp)\n" /* size */
        "movl (%eax), %eax\n" /* line 426 */
        "movl %eax, -0xf0(%ebp)\n" /* pos */
        "movl -0xf8(%ebp), %edi\n" /* line 427 | stackBuf, entId */
        "addl $0xb, %edi\n" /* entId */
        "testw %dx, %dx\n" /* line 429 */
        "jne .Lf8ab58_0008b6c6\n"
        "xorl %esi, %esi\n"
        "movl $1, -0xd0(%ebp)\n"
        ".Lf8ab58_0008ac3f:\n"
        "movl -0xf0(%ebp), %ecx\n" /* line 443 | pos */
        "movl %ecx, -0xa4(%ebp, %esi, 4)\n"
        "movl -0xb4(%ebp), %eax\n" /* line 446 */
        "addl $0x88, %eax\n"
        "movl %eax, -0xec(%ebp)\n" /* endonUsage */
        /* { scope 2: buf, usage */
        /* { scope 3 */
        "movl -0xf4(%ebp), %edx\n" /* line 4343 | size */
        "leal (%edx, %edx, 4), %eax\n"
        "addl %eax, %edi\n" /* entry */
        "movl %edi, -0xe4(%ebp)\n" /* entry, buf */
        "movl -0xf8(%ebp), %ecx\n" /* line 4345 | stackBuf */
        "movzwl 8(%ecx), %edx\n"
        "movl %edx, %eax\n" /* line 2654 */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "movzwl %cx, %ebx\n" /* entryValue */
        "cmpl %ebx, %edx\n" /* line 2660 | entryValue */
        "je .Lf8ab58_0008ad9c\n"
        "movl %ebx, %eax\n" /* line 2665 | entryValue */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8ab58_0008ad9c\n"
        "testw %cx, %cx\n" /* line 4325 */
        "je .Lf8ab58_0008ad9c\n"
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        "movss %xmm3, -0xe0(%ebp)\n" /* usage */
        "movl $0x3f800000, %edi\n" /* entry */
        "movl %ebx, %eax\n" /* line 4326 | id, entryValue */
        "shll $4, %eax\n" /* entryValue */
        "addl $scrVarGlob, %eax\n" /* entryValue */
        /* { scope 4: entry */
        "movl 4(%eax), %edx\n" /* line 4292 */
        "movl 8(%eax), %eax\n" /* type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 5 */
        /* { scope 6 */
        "subl $1, %eax\n" /* line 4274 */
        "je .Lf8ab58_0008ad54\n"
        ".Lf8ab58_0008ace6:\n"
        "movaps %xmm3, %xmm0\n" /* line 4281 */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf8ab58_0008ace9:\n"
        "addss -0xe0(%ebp), %xmm0\n" /* line 4326 | usage */
        "movss %xmm0, -0xe0(%ebp)\n" /* usage */
        /* { scope 4: entry */
        "movl %ebx, %eax\n" /* line 2654 | entryValue */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "movzwl %cx, %edx\n"
        "cmpl %edx, %ebx\n" /* line 2660 | entryValue */
        "je .Lf8ab58_0008b755\n"
        "movl %edx, %eax\n" /* line 2665 */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8ab58_0008b72b\n"
        /* } scope */
        "testw %cx, %cx\n" /* line 4325 */
        "je .Lf8ab58_0008b755\n"
        "movl %edx, %ebx\n" /* id */
        "movl %ebx, %eax\n" /* line 4326 | id, entryValue */
        "shll $4, %eax\n" /* entryValue */
        "addl $scrVarGlob, %eax\n" /* entryValue */
        /* { scope 4: entry */
        "movl 4(%eax), %edx\n" /* line 4292 */
        "movl 8(%eax), %eax\n" /* type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 5 */
        /* { scope 6 */
        "subl $1, %eax\n" /* line 4274 */
        "jne .Lf8ab58_0008ace6\n"
        ".Lf8ab58_0008ad54:\n"
        "movl %edx, %eax\n" /* line 4277 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %esi\n" /* parentValue */
        "movl 8(%esi), %eax\n" /* line 4281 | parentValue */
        "andl $0x1f, %eax\n"
        "cmpl $0x16, %eax\n"
        "jne .Lf8ab58_0008ace6\n"
        "movl %edx, %eax\n" /* line 4282 */
        "calll Scr_GetObjectUsage\n"
        "movzwl 4(%esi), %eax\n" /* parentValue */
        "cvtsi2ssl %eax, %xmm1\n"
        "movl %edi, -0x12c(%ebp)\n" /* entry */
        "movss -0x12c(%ebp), %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "jmp .Lf8ab58_0008ace9\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf8ab58_0008ad9c:\n"
        "movss lit4_002ed5d0, %xmm3\n" /* line 4325 | 1.0f */
        "movss %xmm3, -0xe0(%ebp)\n" /* usage */
        ".Lf8ab58_0008adac:\n"
        "leal 0x10000(%edx), %esi\n" /* line 1998 | name */
        "movl %esi, %ecx\n" /* line 801 | name, index */
        "addl scrVarPub+32, %ecx\n" /* index */
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n" /* index */
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n" /* index */
        "addl $1, %ecx\n" /* index */
        "movzwl %cx, %ecx\n" /* index */
        /* { scope 4: entry */
        /* { scope 5 */
        "movl %ecx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edi\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ebx\n" /* entryValue */
        "movl 8(%ebx), %edx\n" /* line 748 | entryValue */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf8ab58_0008b182\n"
        ".Lf8ab58_0008ae04:\n"
        "xorl %ecx, %ecx\n" /* line 759 */
        /* } scope */
        /* } scope */
        ".Lf8ab58_0008ae06:\n"
        "shll $4, %ecx\n" /* line 1998 */
        "movzwl scrVarGlob(%ecx), %eax\n"
        "movzwl %ax, %edx\n"
        /* { scope 4: entry */
        "pxor %xmm2, %xmm2\n" /* line 4325 */
        /* } scope */
        "testw %ax, %ax\n" /* line 4306 */
        "je .Lf8ab58_0008af60\n"
        /* { scope 4: entry */
        "shll $4, %edx\n" /* line 2743 */
        "movl scrVarGlob+4(%edx), %edx\n"
        /* } scope */
        /* { scope 4: entry */
        /* { scope 5 */
        "movl %edx, %eax\n" /* line 2654 */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "movzwl %cx, %ebx\n" /* entryValue */
        "cmpl %ebx, %edx\n" /* line 2660 | entryValue */
        "je .Lf8ab58_0008b723\n"
        "movl %ebx, %eax\n" /* line 2665 | entryValue */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8ab58_0008b723\n"
        /* } scope */
        "testw %cx, %cx\n" /* line 4325 */
        "je .Lf8ab58_0008b723\n"
        "movaps %xmm3, %xmm2\n"
        "movl $0x3f800000, %edi\n" /* entry */
        "movl %ebx, %eax\n" /* line 4326 | id, entryValue */
        "shll $4, %eax\n" /* entryValue */
        "addl $scrVarGlob, %eax\n" /* entryValue */
        /* { scope 5 */
        "movl 4(%eax), %edx\n" /* line 4292 */
        "movl 8(%eax), %eax\n" /* type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 6 */
        /* { scope 7: parentValue */
        "subl $1, %eax\n" /* line 4274 */
        "je .Lf8ab58_0008aeec\n"
        ".Lf8ab58_0008ae8a:\n"
        "movaps %xmm3, %xmm0\n" /* line 4281 */
        /* } scope */
        /* } scope */
        /* } scope */
        "addss %xmm0, %xmm2\n" /* line 4326 */
        /* { scope 5 */
        "movl %ebx, %eax\n" /* line 2654 | entryValue */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "movzwl %cx, %edx\n"
        "cmpl %edx, %ebx\n" /* line 2660 | entryValue */
        "je .Lf8ab58_0008af60\n"
        ".Lf8ab58_0008aeb2:\n"
        "movl %edx, %eax\n" /* line 2665 */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8ab58_0008af60\n"
        /* } scope */
        "testw %cx, %cx\n" /* line 4325 */
        "je .Lf8ab58_0008af60\n"
        "movl %edx, %ebx\n" /* id */
        "movl %ebx, %eax\n" /* line 4326 | id, entryValue */
        "shll $4, %eax\n" /* entryValue */
        "addl $scrVarGlob, %eax\n" /* entryValue */
        /* { scope 5 */
        "movl 4(%eax), %edx\n" /* line 4292 */
        "movl 8(%eax), %eax\n" /* type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 6 */
        /* { scope 7: parentValue */
        "subl $1, %eax\n" /* line 4274 */
        "jne .Lf8ab58_0008ae8a\n"
        ".Lf8ab58_0008aeec:\n"
        "movl %edx, %eax\n" /* line 4277 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %esi\n" /* parentValue */
        "movl 8(%esi), %eax\n" /* line 4281 | parentValue */
        "andl $0x1f, %eax\n"
        "cmpl $0x16, %eax\n"
        "jne .Lf8ab58_0008ae8a\n"
        "movl %edx, %eax\n" /* line 4282 */
        "movss %xmm2, -0x128(%ebp)\n"
        "calll Scr_GetObjectUsage\n"
        "movzwl 4(%esi), %eax\n" /* parentValue */
        "cvtsi2ssl %eax, %xmm1\n"
        "movl %edi, -0x12c(%ebp)\n" /* entry */
        "movss -0x12c(%ebp), %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "movss -0x128(%ebp), %xmm2\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "addss %xmm0, %xmm2\n" /* line 4326 */
        /* { scope 5 */
        "movl %ebx, %eax\n" /* line 2654 | entryValue */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "movzwl %cx, %edx\n"
        "cmpl %edx, %ebx\n" /* line 2660 | entryValue */
        "jne .Lf8ab58_0008aeb2\n"
        /* } scope */
        /* } scope */
        ".Lf8ab58_0008af60:\n"
        "movl -0xec(%ebp), %edx\n" /* line 4346 | endonUsage */
        "movss %xmm2, (%edx)\n"
        "movl -0xf8(%ebp), %ecx\n" /* line 4348 | stackBuf */
        "movzwl 8(%ecx), %edi\n" /* entry */
        "cmpw $0, -0x10e(%ebp)\n" /* line 4350 */
        "je .Lf8ab58_0008afd6\n"
        "movl $0, -0xbc(%ebp)\n"
        ".Lf8ab58_0008af88:\n"
        "movl -0xe4(%ebp), %eax\n" /* line 4353 | buf */
        "movl -4(%eax), %ecx\n"
        "subl $5, %eax\n" /* line 4354 */
        "movl %eax, -0xe4(%ebp)\n" /* buf */
        "movzbl (%eax), %eax\n" /* line 4355 */
        "cmpb $7, %al\n" /* line 4357 */
        "je .Lf8ab58_0008b33e\n"
        /* { scope 4: entry */
        "subb $1, %al\n" /* line 4274 */
        "je .Lf8ab58_0008b1da\n"
        ".Lf8ab58_0008afad:\n"
        "pxor %xmm0, %xmm0\n" /* line 4282 */
        /* } scope */
        ".Lf8ab58_0008afb1:\n"
        "addss -0xe0(%ebp), %xmm0\n" /* line 4359 | usage */
        "movss %xmm0, -0xe0(%ebp)\n" /* usage */
        ".Lf8ab58_0008afc1:\n"
        "addl $1, -0xbc(%ebp)\n" /* line 4365 */
        "movl -0xbc(%ebp), %eax\n" /* line 4350 */
        "cmpl %eax, -0xf4(%ebp)\n" /* size */
        "jne .Lf8ab58_0008af88\n"
        /* } scope */
        /* } scope */
        ".Lf8ab58_0008afd6:\n"
        "movss -0xe0(%ebp), %xmm0\n" /* line 446 | usage */
        "movl -0xb4(%ebp), %edx\n"
        "movss %xmm0, 0x84(%edx)\n"
        "movl -0xd0(%ebp), %eax\n" /* line 447 */
        "movl %eax, 0x80(%edx)\n"
        "movl -0xd0(%ebp), %eax\n" /* line 448 */
        "subl $1, %eax\n"
        "movl -0xd0(%ebp), %edx\n" /* line 449 */
        "testl %edx, %edx\n"
        "jle .Lf8ab58_0008abaa\n"
        "leal -0xa4(%ebp, %eax, 4), %ecx\n"
        "movl -0xb4(%ebp), %edx\n"
        "xorl %ebx, %ebx\n" /* j */
        ".Lf8ab58_0008b01e:\n"
        "movl (%ecx), %eax\n" /* line 450 */
        "movl %eax, (%edx)\n"
        "addl $1, %ebx\n" /* line 449 | j */
        "subl $4, %ecx\n"
        "addl $4, %edx\n"
        "cmpl -0xd0(%ebp), %ebx\n" /* j */
        "jl .Lf8ab58_0008b01e\n"
        "addl $1, -0x10c(%ebp)\n" /* line 413 | id */
        "addl $0x10, -0x114(%ebp)\n"
        "cmpl $0xfffe, -0x10c(%ebp)\n" /* id */
        "jne .Lf8ab58_0008abc8\n"
        ".Lf8ab58_0008b051:\n"
        "movl $ThreadInfoCompare, 0xc(%esp)\n" /* line 453 */
        "movl $0x8c, 8(%esp)\n"
        "movl -0x104(%ebp), %edx\n" /* num */
        "movl %edx, 4(%esp)\n"
        "movl -0x108(%ebp), %ecx\n" /* infoArray */
        "movl %ecx, (%esp)\n"
        "calll qsort\n"
        "movl $str_00217c60, (%esp)\n" /* line 455 */
        "calll Com_Printf\n"
        "movl -0x104(%ebp), %eax\n" /* line 458 | num */
        "testl %eax, %eax\n"
        "jle .Lf8ab58_0008b83b\n"
        "movl $0, -0x100(%ebp)\n" /* i */
        ".Lf8ab58_0008b09d:\n"
        "movl -0x100(%ebp), %eax\n" /* line 460 | i */
        "leal (%eax, %eax, 4), %edx\n"
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "movl -0x108(%ebp), %edx\n" /* infoArray */
        "leal (%edx, %eax, 4), %edi\n" /* entId */
        "movl %edi, -0xc8(%ebp)\n" /* entId */
        "leal 0x8c(%edi), %ecx\n" /* line 384 */
        "movl %ecx, -0xc4(%ebp)\n"
        "movl %ecx, -0xc0(%ebp)\n"
        "movl $0, -0xfc(%ebp)\n" /* count */
        "pxor %xmm0, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        "movl %edi, %eax\n"
        ".Lf8ab58_0008b0e3:\n"
        "addl $1, -0xfc(%ebp)\n" /* line 466 | count */
        "addss 0x84(%eax), %xmm0\n" /* line 467 */
        "addss 0x88(%eax), %xmm1\n" /* line 468 */
        "addl $1, -0x100(%ebp)\n" /* line 469 | i */
        "movl -0x100(%ebp), %edx\n" /* line 464 | i */
        "cmpl %edx, -0x104(%ebp)\n" /* num */
        "jle .Lf8ab58_0008b7dc\n"
        /* { scope 2: buf, usage */
        "movl 0x80(%edi), %esi\n" /* line 370 */
        "testl %esi, %esi\n"
        "jle .Lf8ab58_0008b7a8\n"
        "movl -0xc0(%ebp), %ecx\n"
        "movl 0x80(%ecx), %ecx\n"
        "movl %ecx, -0xb0(%ebp)\n"
        "testl %ecx, %ecx\n"
        "jle .Lf8ab58_0008b7a8\n"
        "movl (%edi), %edx\n" /* line 372 */
        "movl -0xc0(%ebp), %ecx\n" /* line 373 */
        "movl (%ecx), %eax\n"
        "cmpl %eax, %edx\n" /* line 374 */
        "je .Lf8ab58_0008b764\n"
        ".Lf8ab58_0008b14d:\n"
        "subl %eax, %edx\n" /* line 375 */
        "movl %edx, %eax\n"
        "addl $0x8c, -0xc8(%ebp)\n" /* line 370 */
        "addl $0x8c, -0xc4(%ebp)\n"
        "addl $0x8c, -0xc0(%ebp)\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 464 */
        "jne .Lf8ab58_0008b7dc\n"
        ".Lf8ab58_0008b177:\n"
        "movl -0xc8(%ebp), %eax\n"
        "jmp .Lf8ab58_0008b0e3\n"
        /* { scope 2: buf, usage */
        /* { scope 3 */
        /* { scope 4: entry */
        /* { scope 5 */
        ".Lf8ab58_0008b182:\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, %esi\n"
        "je .Lf8ab58_0008ae06\n"
        "movzwl 0xc(%ebx), %ecx\n" /* line 757 | entryValue */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, %edi\n" /* line 759 | entry */
        "je .Lf8ab58_0008ae04\n"
        ".Lf8ab58_0008b1a4:\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %esi, %eax\n"
        "je .Lf8ab58_0008ae06\n"
        "movzwl 0xc(%edx), %ecx\n" /* line 771 */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, %edi\n" /* line 759 | entry */
        "jne .Lf8ab58_0008b1a4\n"
        "jmp .Lf8ab58_0008ae04\n"
        /* } scope */
        /* } scope */
        /* { scope 4: entry */
        ".Lf8ab58_0008b1da:\n"
        "movl %ecx, %edx\n" /* line 4277 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %esi\n" /* parentValue */
        "movl 8(%esi), %eax\n" /* line 4281 | parentValue */
        "andl $0x1f, %eax\n"
        "cmpl $0x16, %eax\n"
        "jne .Lf8ab58_0008afad\n"
        /* { scope 5 */
        "movzwl scrVarGlob+14(%edx), %eax\n" /* line 2654 */
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %edx\n"
        "movzwl %dx, %ebx\n" /* entryValue */
        "cmpl %ebx, %ecx\n" /* line 2660 | entryValue */
        "je .Lf8ab58_0008b73a\n"
        "movl %ebx, %eax\n" /* line 2665 | entryValue */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8ab58_0008b73a\n"
        "testw %dx, %dx\n" /* line 4325 | id */
        "je .Lf8ab58_0008b73a\n"
        "movaps %xmm3, %xmm2\n"
        "movl %ebx, %eax\n" /* line 4326 | id, entryValue */
        "shll $4, %eax\n" /* entryValue */
        "addl $scrVarGlob, %eax\n" /* entryValue */
        /* { scope 6 */
        "movl 4(%eax), %edx\n" /* line 4292 */
        "movl 8(%eax), %eax\n" /* type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 7: parentValue */
        /* { scope 8 */
        "subl $1, %eax\n" /* line 4274 */
        "je .Lf8ab58_0008b2ad\n"
        ".Lf8ab58_0008b24b:\n"
        "movaps %xmm3, %xmm0\n" /* line 4281 */
        /* } scope */
        /* } scope */
        /* } scope */
        "addss %xmm0, %xmm2\n" /* line 4326 */
        /* { scope 6 */
        "movl %ebx, %eax\n" /* line 2654 | entryValue */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "movzwl %cx, %edx\n"
        "cmpl %edx, %ebx\n" /* line 2660 | entryValue */
        "je .Lf8ab58_0008b326\n"
        ".Lf8ab58_0008b273:\n"
        "movl %edx, %eax\n" /* line 2665 */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8ab58_0008b326\n"
        /* } scope */
        "testw %cx, %cx\n" /* line 4325 */
        "je .Lf8ab58_0008b326\n"
        "movl %edx, %ebx\n" /* id */
        "movl %ebx, %eax\n" /* line 4326 | id, entryValue */
        "shll $4, %eax\n" /* entryValue */
        "addl $scrVarGlob, %eax\n" /* entryValue */
        /* { scope 6 */
        "movl 4(%eax), %edx\n" /* line 4292 */
        "movl 8(%eax), %eax\n" /* type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 7: parentValue */
        /* { scope 8 */
        "subl $1, %eax\n" /* line 4274 */
        "jne .Lf8ab58_0008b24b\n"
        ".Lf8ab58_0008b2ad:\n"
        "movl %edx, %eax\n" /* line 4277 */
        "shll $4, %eax\n"
        "addl $scrVarGlob, %eax\n"
        "movl %eax, -0xdc(%ebp)\n" /* parentValue */
        "movl 8(%eax), %eax\n" /* line 4281 */
        "andl $0x1f, %eax\n"
        "cmpl $0x16, %eax\n"
        "jne .Lf8ab58_0008b24b\n"
        "movl %edx, %eax\n" /* line 4282 */
        "movss %xmm2, -0x128(%ebp)\n"
        "calll Scr_GetObjectUsage\n"
        "movl -0xdc(%ebp), %edx\n" /* parentValue */
        "movzwl 4(%edx), %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        "addss %xmm3, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "movss -0x128(%ebp), %xmm2\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "addss %xmm0, %xmm2\n" /* line 4326 */
        /* { scope 6 */
        "movl %ebx, %eax\n" /* line 2654 | entryValue */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "movzwl %cx, %edx\n"
        "cmpl %edx, %ebx\n" /* line 2660 | entryValue */
        "jne .Lf8ab58_0008b273\n"
        /* } scope */
        /* } scope */
        ".Lf8ab58_0008b326:\n"
        "movzwl 4(%esi), %eax\n" /* line 4282 | parentValue */
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "divss %xmm0, %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        "jmp .Lf8ab58_0008afb1\n"
        /* } scope */
        /* { scope 4: entry */
        ".Lf8ab58_0008b33e:\n"
        "shll $4, %edi\n" /* line 1399 | entry */
        "movl scrVarGlob+8(%edi), %edi\n" /* entry */
        "shrl $8, %edi\n" /* entry */
        /* } scope */
        /* { scope 4: entry */
        "movl %edi, %eax\n" /* line 2654 | entry */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %edx\n"
        "movzwl %dx, %ebx\n" /* entryValue */
        "cmpl %ebx, %edi\n" /* line 2660 | entryValue, entry */
        "je .Lf8ab58_0008b6be\n"
        "movl %ebx, %eax\n" /* line 2665 | entryValue */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8ab58_0008b6be\n"
        "testw %dx, %dx\n" /* line 4325 | id */
        "je .Lf8ab58_0008b6be\n"
        "movaps %xmm3, %xmm2\n"
        "movl %ebx, %eax\n" /* line 4326 | id, entryValue */
        "shll $4, %eax\n" /* entryValue */
        "addl $scrVarGlob, %eax\n" /* entryValue */
        /* { scope 5 */
        "movl 4(%eax), %edx\n" /* line 4292 */
        "movl 8(%eax), %eax\n" /* type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 6 */
        /* { scope 7: parentValue */
        "subl $1, %eax\n" /* line 4274 */
        "je .Lf8ab58_0008b408\n"
        ".Lf8ab58_0008b3a6:\n"
        "movaps %xmm3, %xmm0\n" /* line 4281 */
        /* } scope */
        /* } scope */
        /* } scope */
        "addss %xmm0, %xmm2\n" /* line 4326 */
        /* { scope 5 */
        "movl %ebx, %eax\n" /* line 2654 | entryValue */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "movzwl %cx, %edx\n"
        "cmpl %edx, %ebx\n" /* line 2660 | entryValue */
        "je .Lf8ab58_0008b476\n"
        ".Lf8ab58_0008b3ce:\n"
        "movl %edx, %eax\n" /* line 2665 */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8ab58_0008b476\n"
        /* } scope */
        "testw %cx, %cx\n" /* line 4325 */
        "je .Lf8ab58_0008b476\n"
        "movl %edx, %ebx\n" /* id */
        "movl %ebx, %eax\n" /* line 4326 | id, entryValue */
        "shll $4, %eax\n" /* entryValue */
        "addl $scrVarGlob, %eax\n" /* entryValue */
        /* { scope 5 */
        "movl 4(%eax), %edx\n" /* line 4292 */
        "movl 8(%eax), %eax\n" /* type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 6 */
        /* { scope 7: parentValue */
        "subl $1, %eax\n" /* line 4274 */
        "jne .Lf8ab58_0008b3a6\n"
        ".Lf8ab58_0008b408:\n"
        "movl %edx, %eax\n" /* line 4277 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %esi\n" /* parentValue */
        "movl 8(%esi), %eax\n" /* line 4281 | parentValue */
        "andl $0x1f, %eax\n"
        "cmpl $0x16, %eax\n"
        "jne .Lf8ab58_0008b3a6\n"
        "movl %edx, %eax\n" /* line 4282 */
        "movss %xmm2, -0x128(%ebp)\n"
        "calll Scr_GetObjectUsage\n"
        "movzwl 4(%esi), %eax\n" /* parentValue */
        "cvtsi2ssl %eax, %xmm1\n"
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        "addss %xmm3, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "movss -0x128(%ebp), %xmm2\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "addss %xmm0, %xmm2\n" /* line 4326 */
        /* { scope 5 */
        "movl %ebx, %eax\n" /* line 2654 | entryValue */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "movzwl %cx, %edx\n"
        "cmpl %edx, %ebx\n" /* line 2660 | entryValue */
        "jne .Lf8ab58_0008b3ce\n"
        /* } scope */
        /* } scope */
        ".Lf8ab58_0008b476:\n"
        "addss -0xe0(%ebp), %xmm2\n" /* line 4364 | usage */
        "movss %xmm2, -0xe0(%ebp)\n" /* usage */
        "movl -0xec(%ebp), %ecx\n" /* line 4365 | endonUsage */
        "movss (%ecx), %xmm0\n"
        "movss %xmm0, -0xe8(%ebp)\n"
        "leal 0x10000(%edi), %esi\n" /* line 1998 | entry, name */
        "movl %esi, %ecx\n" /* line 801 | name, index */
        "addl scrVarPub+32, %ecx\n" /* index */
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n" /* index */
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n" /* index */
        "addl $1, %ecx\n" /* index */
        "movzwl %cx, %ecx\n" /* index */
        /* { scope 4: entry */
        /* { scope 5 */
        "movl %ecx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl %edx, -0xd8(%ebp)\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ebx\n" /* entryValue */
        "movl 8(%ebx), %edx\n" /* line 748 | entryValue */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf8ab58_0008b65e\n"
        ".Lf8ab58_0008b4f6:\n"
        "xorl %ecx, %ecx\n" /* line 759 */
        /* } scope */
        /* } scope */
        ".Lf8ab58_0008b4f8:\n"
        "shll $4, %ecx\n" /* line 1998 */
        "movzwl scrVarGlob(%ecx), %eax\n"
        "movzwl %ax, %edx\n"
        /* { scope 4: entry */
        "pxor %xmm2, %xmm2\n" /* line 4325 */
        /* } scope */
        "testw %ax, %ax\n" /* line 4306 */
        "je .Lf8ab58_0008b647\n"
        /* { scope 4: entry */
        "shll $4, %edx\n" /* line 2743 */
        "movl scrVarGlob+4(%edx), %edx\n"
        /* } scope */
        /* { scope 4: entry */
        /* { scope 5 */
        "movl %edx, %eax\n" /* line 2654 */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "movzwl %cx, %ebx\n" /* entryValue */
        "cmpl %ebx, %edx\n" /* line 2660 | entryValue */
        "je .Lf8ab58_0008b709\n"
        "movl %ebx, %eax\n" /* line 2665 | entryValue */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8ab58_0008b709\n"
        /* } scope */
        "testw %cx, %cx\n" /* line 4325 */
        "je .Lf8ab58_0008b709\n"
        "movaps %xmm3, %xmm2\n"
        "movl %ebx, %eax\n" /* line 4326 | id, entryValue */
        "shll $4, %eax\n" /* entryValue */
        "addl $scrVarGlob, %eax\n" /* entryValue */
        /* { scope 5 */
        "movl 4(%eax), %edx\n" /* line 4292 */
        "movl 8(%eax), %eax\n" /* type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 6 */
        /* { scope 7: parentValue */
        "subl $1, %eax\n" /* line 4274 */
        "je .Lf8ab58_0008b5d9\n"
        ".Lf8ab58_0008b577:\n"
        "movaps %xmm3, %xmm0\n" /* line 4281 */
        /* } scope */
        /* } scope */
        /* } scope */
        "addss %xmm0, %xmm2\n" /* line 4326 */
        /* { scope 5 */
        "movl %ebx, %eax\n" /* line 2654 | entryValue */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "movzwl %cx, %edx\n"
        "cmpl %edx, %ebx\n" /* line 2660 | entryValue */
        "je .Lf8ab58_0008b647\n"
        ".Lf8ab58_0008b59f:\n"
        "movl %edx, %eax\n" /* line 2665 */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8ab58_0008b647\n"
        /* } scope */
        "testw %cx, %cx\n" /* line 4325 */
        "je .Lf8ab58_0008b647\n"
        "movl %edx, %ebx\n" /* id */
        "movl %ebx, %eax\n" /* line 4326 | id, entryValue */
        "shll $4, %eax\n" /* entryValue */
        "addl $scrVarGlob, %eax\n" /* entryValue */
        /* { scope 5 */
        "movl 4(%eax), %edx\n" /* line 4292 */
        "movl 8(%eax), %eax\n" /* type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 6 */
        /* { scope 7: parentValue */
        "subl $1, %eax\n" /* line 4274 */
        "jne .Lf8ab58_0008b577\n"
        ".Lf8ab58_0008b5d9:\n"
        "movl %edx, %eax\n" /* line 4277 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %esi\n" /* parentValue */
        "movl 8(%esi), %eax\n" /* line 4281 | parentValue */
        "andl $0x1f, %eax\n"
        "cmpl $0x16, %eax\n"
        "jne .Lf8ab58_0008b577\n"
        "movl %edx, %eax\n" /* line 4282 */
        "movss %xmm2, -0x128(%ebp)\n"
        "calll Scr_GetObjectUsage\n"
        "movzwl 4(%esi), %eax\n" /* parentValue */
        "cvtsi2ssl %eax, %xmm1\n"
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        "addss %xmm3, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "movss -0x128(%ebp), %xmm2\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "addss %xmm0, %xmm2\n" /* line 4326 */
        /* { scope 5 */
        "movl %ebx, %eax\n" /* line 2654 | entryValue */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "movzwl %cx, %edx\n"
        "cmpl %edx, %ebx\n" /* line 2660 | entryValue */
        "jne .Lf8ab58_0008b59f\n"
        /* } scope */
        /* } scope */
        ".Lf8ab58_0008b647:\n"
        "addss -0xe8(%ebp), %xmm2\n" /* line 4365 */
        "movl -0xec(%ebp), %ecx\n" /* endonUsage */
        "movss %xmm2, (%ecx)\n"
        "jmp .Lf8ab58_0008afc1\n"
        /* { scope 4: entry */
        /* { scope 5 */
        ".Lf8ab58_0008b65e:\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, %esi\n"
        "je .Lf8ab58_0008b4f8\n"
        "movzwl 0xc(%ebx), %ecx\n" /* line 757 | entryValue */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0xd8(%ebp)\n" /* line 759 | entry */
        "je .Lf8ab58_0008b4f6\n"
        ".Lf8ab58_0008b684:\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, %esi\n"
        "je .Lf8ab58_0008b4f8\n"
        "movzwl 0xc(%edx), %ecx\n" /* line 771 */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0xd8(%ebp)\n" /* line 759 | entry */
        "jne .Lf8ab58_0008b684\n"
        "jmp .Lf8ab58_0008b4f6\n"
        /* } scope */
        /* } scope */
        /* { scope 4: entry */
        ".Lf8ab58_0008b6be:\n"
        "movaps %xmm3, %xmm2\n" /* line 4325 */
        "jmp .Lf8ab58_0008b476\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf8ab58_0008b6c6:\n"
        "movl %edi, %edx\n" /* line 429 | entId */
        "xorl %esi, %esi\n"
        "xorl %ecx, %ecx\n"
        "jmp .Lf8ab58_0008b6d9\n"
        ".Lf8ab58_0008b6ce:\n"
        "addl $1, %ecx\n" /* line 439 */
        "cmpl %ecx, -0xf4(%ebp)\n" /* line 429 | size */
        "je .Lf8ab58_0008b6fb\n"
        ".Lf8ab58_0008b6d9:\n"
        "movzbl (%edx), %eax\n" /* line 432 */
        "movl 1(%edx), %ebx\n" /* line 434 | j */
        "addl $5, %edx\n" /* line 435 */
        "cmpb $7, %al\n" /* line 436 */
        "jne .Lf8ab58_0008b6ce\n"
        "movl %ebx, -0xa4(%ebp, %esi, 4)\n" /* line 438 | j */
        "addl $1, %esi\n" /* line 439 */
        "addl $1, %ecx\n"
        "cmpl %ecx, -0xf4(%ebp)\n" /* line 429 | size */
        "jne .Lf8ab58_0008b6d9\n"
        ".Lf8ab58_0008b6fb:\n"
        "leal 1(%esi), %edx\n"
        "movl %edx, -0xd0(%ebp)\n"
        "jmp .Lf8ab58_0008ac3f\n"
        /* { scope 2: buf, usage */
        /* { scope 3 */
        /* { scope 4: entry */
        ".Lf8ab58_0008b709:\n"
        "movaps %xmm3, %xmm2\n" /* line 4325 */
        /* } scope */
        "addss -0xe8(%ebp), %xmm2\n" /* line 4365 */
        "movl -0xec(%ebp), %ecx\n" /* endonUsage */
        "movss %xmm2, (%ecx)\n"
        "jmp .Lf8ab58_0008afc1\n"
        /* { scope 4: entry */
        ".Lf8ab58_0008b723:\n"
        "movaps %xmm3, %xmm2\n" /* line 4325 */
        "jmp .Lf8ab58_0008af60\n"
        ".Lf8ab58_0008b72b:\n"
        "movl -0xf8(%ebp), %ecx\n" /* stackBuf */
        "movzwl 8(%ecx), %edx\n" /* id */
        "jmp .Lf8ab58_0008adac\n"
        /* } scope */
        /* { scope 4: entry */
        /* { scope 5 */
        ".Lf8ab58_0008b73a:\n"
        "movaps %xmm3, %xmm2\n"
        /* } scope */
        "movzwl 4(%esi), %eax\n" /* line 4282 | parentValue */
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "divss %xmm0, %xmm2\n"
        "movaps %xmm2, %xmm0\n"
        "jmp .Lf8ab58_0008afb1\n"
        ".Lf8ab58_0008b755:\n"
        "movl -0xf8(%ebp), %eax\n" /* stackBuf */
        "movzwl 8(%eax), %edx\n"
        "jmp .Lf8ab58_0008adac\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: buf, usage */
        ".Lf8ab58_0008b764:\n"
        "movl %edi, %ebx\n" /* line 374 */
        "movl -0xc4(%ebp), %ecx\n"
        "movl $0, -0xd4(%ebp)\n" /* i */
        ".Lf8ab58_0008b776:\n"
        "addl $1, -0xd4(%ebp)\n" /* line 376 | i */
        "cmpl %esi, -0xd4(%ebp)\n" /* line 370 | i */
        "je .Lf8ab58_0008b7a8\n"
        "movl -0xb0(%ebp), %eax\n"
        "cmpl %eax, -0xd4(%ebp)\n" /* i */
        "je .Lf8ab58_0008b7a8\n"
        "movl 4(%ebx), %edx\n" /* line 372 */
        "movl 4(%ecx), %eax\n" /* line 373 */
        "addl $4, %ebx\n"
        "addl $4, %ecx\n"
        "cmpl %edx, %eax\n" /* line 374 */
        "je .Lf8ab58_0008b776\n"
        "jmp .Lf8ab58_0008b14d\n"
        ".Lf8ab58_0008b7a8:\n"
        "movl %esi, %eax\n" /* line 371 */
        "movl -0xc4(%ebp), %edx\n"
        "subl 0x80(%edx), %eax\n"
        "addl $0x8c, -0xc8(%ebp)\n" /* line 370 */
        "addl $0x8c, -0xc4(%ebp)\n"
        "addl $0x8c, -0xc0(%ebp)\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 464 */
        "je .Lf8ab58_0008b177\n"
        ".Lf8ab58_0008b7dc:\n"
        "cvttss2si %xmm1, %eax\n" /* line 471 */
        "movl %eax, 0xc(%esp)\n"
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0xfc(%ebp), %eax\n" /* count */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021d46c, (%esp)\n" /* "count: %d, var usage: %d, endon usage: %d
" */
        "calll Com_Printf\n"
        "movl $0, 8(%esp)\n" /* line 473 */
        "movl (%edi), %eax\n" /* entId */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_PrintPrevCodePos\n"
        "cmpl $1, 0x80(%edi)\n" /* line 475 | entId */
        "jg .Lf8ab58_0008b981\n"
        ".Lf8ab58_0008b829:\n"
        "movl -0x100(%ebp), %ecx\n" /* line 458 | i */
        "cmpl %ecx, -0x104(%ebp)\n" /* num */
        "jg .Lf8ab58_0008b09d\n"
        ".Lf8ab58_0008b83b:\n"
        "movl -0x108(%ebp), %eax\n" /* line 482 | infoArray */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        "movl $str_00217c60, (%esp)\n" /* line 484 */
        "calll Com_Printf\n"
        "movl $g_classMap, -0xcc(%ebp)\n"
        ".Lf8ab58_0008b85f:\n"
        "movl -0xcc(%ebp), %edx\n" /* line 488 */
        "movzwl 2(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf8ab58_0008b952\n"
        "movzwl %ax, %edx\n" /* line 493 | id */
        /* { scope 2: buf, usage */
        "movl %edx, %eax\n" /* line 2654 */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "movzwl %cx, %edi\n" /* entry */
        "cmpl %edi, %edx\n" /* line 2660 | entry */
        "je .Lf8ab58_0008b9c2\n"
        "movl %edi, %eax\n" /* line 2665 | entry */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8ab58_0008b9c2\n"
        /* } scope */
        "testw %cx, %cx\n" /* line 493 */
        "je .Lf8ab58_0008b9c2\n"
        "movl $0, -0xac(%ebp)\n"
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0xb8(%ebp)\n"
        ".Lf8ab58_0008b8cc:\n"
        "addl $1, -0xac(%ebp)\n" /* line 495 */
        "movl %edi, %edx\n" /* line 496 | entId */
        "shll $4, %edx\n"
        "movl scrVarGlob+8(%edx), %eax\n"
        "andl $0x1f, %eax\n"
        "subl $1, %eax\n"
        "je .Lf8ab58_0008b9e1\n"
        ".Lf8ab58_0008b8ea:\n"
        "movl %edi, %eax\n" /* line 2654 | entry */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "movzwl %cx, %edx\n"
        "cmpl %edx, %edi\n" /* line 2660 | entry */
        "je .Lf8ab58_0008b923\n"
        "movl %edx, %eax\n" /* line 2665 */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8ab58_0008b923\n"
        "testw %cx, %cx\n" /* line 493 */
        "je .Lf8ab58_0008b923\n"
        "movl %edx, %edi\n" /* id, entId */
        "jmp .Lf8ab58_0008b8cc\n"
        ".Lf8ab58_0008b923:\n"
        "cvttss2si -0xb8(%ebp), %eax\n"
        ".Lf8ab58_0008b92b:\n"
        "movl %eax, 0xc(%esp)\n" /* line 501 */
        "movl -0xac(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0xcc(%ebp), %edx\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021d440, (%esp)\n" /* "ent type '%s'... count: %d, var usage: %d
" */
        "calll Com_Printf\n"
        ".Lf8ab58_0008b952:\n"
        "addl $0xc, -0xcc(%ebp)\n"
        "movl $g_classMap+48, %ecx\n" /* line 486 */
        "cmpl -0xcc(%ebp), %ecx\n"
        "jne .Lf8ab58_0008b85f\n"
        "movl $str_00217c60, (%esp)\n" /* line 504 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf8ab58_0008b976:\n"
        "addl $0x13c, %esp\n" /* line 511 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: endonUsage, i */
        ".Lf8ab58_0008b981:\n"
        "movl %edi, %esi\n" /* line 475 | entId */
        "movl $1, %ebx\n" /* j */
        ".Lf8ab58_0008b988:\n"
        "movl $str_0021d430, (%esp)\n" /* line 477 */
        "calll Com_Printf\n"
        "movl $0, 8(%esp)\n" /* line 478 */
        "movl 4(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Scr_PrintPrevCodePos\n"
        "addl $1, %ebx\n" /* line 475 | j */
        "addl $4, %esi\n"
        "cmpl 0x80(%edi), %ebx\n" /* entId, j */
        "jl .Lf8ab58_0008b988\n"
        "jmp .Lf8ab58_0008b829\n"
        ".Lf8ab58_0008b9c2:\n"
        "movl $0, -0xac(%ebp)\n" /* line 493 */
        "xorl %eax, %eax\n"
        "jmp .Lf8ab58_0008b92b\n"
        ".Lf8ab58_0008b9d3:\n"
        "movl $str_0021d404, (%esp)\n" /* line 407 */
        "calll Com_Printf\n"
        "jmp .Lf8ab58_0008b976\n"
        ".Lf8ab58_0008b9e1:\n"
        "movl scrVarGlob+4(%edx), %edx\n" /* line 498 */
        /* { scope 2: buf, usage */
        /* { scope 3 */
        "movl %edx, %eax\n" /* line 2654 */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "movzwl %cx, %esi\n" /* name */
        "cmpl %esi, %edx\n" /* line 2660 | name */
        "je .Lf8ab58_0008ba7f\n"
        "movl %esi, %eax\n" /* line 2665 | name */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8ab58_0008ba7f\n"
        /* } scope */
        "testw %cx, %cx\n" /* line 4325 */
        "je .Lf8ab58_0008ba7f\n"
        "movss lit4_002ed5d0, %xmm2\n" /* 1.0f */
        "movaps %xmm2, %xmm3\n"
        ".Lf8ab58_0008ba27:\n"
        "movl %esi, %eax\n" /* line 4326 | id, entryValue */
        "shll $4, %eax\n" /* entryValue */
        "addl $scrVarGlob, %eax\n" /* entryValue */
        /* { scope 3 */
        "movl 4(%eax), %edx\n" /* line 4292 */
        "movl 8(%eax), %eax\n" /* type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 4: entry */
        /* { scope 5 */
        "subl $1, %eax\n" /* line 4274 */
        "je .Lf8ab58_0008ba9c\n"
        ".Lf8ab58_0008ba3f:\n"
        "movaps %xmm3, %xmm0\n" /* line 4281 */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf8ab58_0008ba42:\n"
        "addss %xmm0, %xmm2\n" /* line 4326 */
        /* { scope 3 */
        "movl %esi, %eax\n" /* line 2654 | name */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "movzwl %cx, %edx\n"
        "cmpl %edx, %esi\n" /* line 2660 | name */
        "je .Lf8ab58_0008ba87\n"
        "movl %edx, %eax\n" /* line 2665 */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8ab58_0008ba87\n"
        /* } scope */
        "testw %cx, %cx\n" /* line 4325 */
        "je .Lf8ab58_0008ba87\n"
        "movl %edx, %esi\n" /* id */
        "jmp .Lf8ab58_0008ba27\n"
        ".Lf8ab58_0008ba7f:\n"
        "movss lit4_002ed5d0, %xmm2\n" /* 1.0f */
        /* } scope */
        ".Lf8ab58_0008ba87:\n"
        "addss -0xb8(%ebp), %xmm2\n" /* line 498 */
        "movss %xmm2, -0xb8(%ebp)\n"
        "jmp .Lf8ab58_0008b8ea\n"
        /* { scope 2: buf, usage */
        /* { scope 3 */
        /* { scope 4: entry */
        /* { scope 5 */
        ".Lf8ab58_0008ba9c:\n"
        "movl %edx, %eax\n" /* line 4277 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ebx\n" /* parentValue */
        "movl 8(%ebx), %eax\n" /* line 4281 | parentValue */
        "andl $0x1f, %eax\n"
        "cmpl $0x16, %eax\n"
        "jne .Lf8ab58_0008ba3f\n"
        "movl %edx, %eax\n" /* line 4282 */
        "movss %xmm2, -0x128(%ebp)\n"
        "calll Scr_GetObjectUsage\n"
        "movzwl 4(%ebx), %eax\n" /* parentValue */
        "cvtsi2ssl %eax, %xmm1\n"
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        "addss %xmm3, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "movss -0x128(%ebp), %xmm2\n"
        "jmp .Lf8ab58_0008ba42\n"
    );
}

/* line 3792 */
__attribute__((naked))
unsigned int Scr_GetEntityId(int entnum, int classnum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3792 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1: entry, entnum */
        "movl 0xc(%ebp), %edx\n" /* line 3801 | classnum */
        "leal (%edx, %edx, 2), %eax\n"
        "movzwl g_classMap+2(, %eax, 4), %edi\n" /* entArrayId */
        "movl 8(%ebp), %ebx\n" /* line 2006 | entnum, name */
        "addl $0x00800000, %ebx\n" /* name */
        "andl $0x00FFFFFF, %ebx\n" /* name */
        "leal (%edi, %ebx), %ecx\n" /* line 1138 */
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n"
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n"
        "addl $1, %ecx\n"
        /* { scope 2 */
        "movl %ecx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl %edx, -0x24(%ebp)\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %esi\n" /* entryValue */
        "movl 8(%esi), %edx\n" /* line 748 | entryValue */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf8baea_0008bcac\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf8baea_0008bb5d:\n"
        "movl %ebx, %edx\n" /* line 1033 */
        "movl %edi, %eax\n"
        "calll GetNewVariableIndexInternal3\n"
        "movl %eax, %esi\n" /* entryValue */
        "shll $4, %edi\n" /* line 1035 */
        "leal scrVarGlob(%edi), %ecx\n"
        "movzwl 0xe(%ecx), %edx\n" /* line 1037 */
        "movl %eax, %ebx\n" /* line 1040 */
        "shll $4, %ebx\n"
        "movzwl scrVarGlob(%ebx), %eax\n" /* line 1043 */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+14(%eax)\n"
        "shll $4, %edx\n" /* line 1044 */
        "movw %si, scrVarGlob+2(%edx)\n" /* entryValue */
        "movzwl 0xc(%ecx), %eax\n" /* line 1046 */
        "movw %ax, scrVarGlob+2(%ebx)\n"
        "movw %si, 0xe(%ecx)\n" /* line 1047 | entryValue */
        /* } scope */
        /* } scope */
        ".Lf8baea_0008bba4:\n"
        "shll $4, %esi\n" /* line 3806 | entryValue */
        "movzwl scrVarGlob(%esi), %eax\n" /* entryValue */
        "shll $4, %eax\n"
        "addl $scrVarGlob, %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* entryValue */
        "testb $0x1f, 8(%eax)\n" /* line 3809 */
        "je .Lf8baea_0008bbcc\n"
        "movl 4(%eax), %edx\n" /* line 3812 */
        /* } scope */
        "movl %edx, %eax\n" /* line 3822 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: entry, entnum */
        ".Lf8baea_0008bbcc:\n"
        "movl 8(%ebp), %ecx\n" /* line 3812 | entnum */
        "movw %cx, -0x1e(%ebp)\n" /* entnum */
        /* { scope 2 */
        /* { scope 3 */
        "movzwl scrVarGlob+4, %edi\n" /* line 1503 */
        "testw %di, %di\n" /* line 1504 */
        "je .Lf8baea_0008bd31\n"
        ".Lf8baea_0008bbe3:\n"
        "movzwl %di, %ebx\n" /* line 1507 | name */
        "shll $4, %ebx\n" /* name */
        "leal scrVarGlob(%ebx), %esi\n" /* name, entryValue */
        "movzwl scrVarGlob(%ebx), %eax\n" /* line 1508 | name */
        "movw %ax, -0x1c(%ebp)\n"
        "movzwl %ax, %eax\n"
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movzwl 4(%ecx), %edx\n" /* line 1511 */
        "movw %dx, -0x1a(%ebp)\n"
        "cmpl %ecx, %esi\n" /* line 1514 | entryValue */
        "je .Lf8baea_0008bd42\n"
        "testb $0x60, 8(%esi)\n" /* entryValue */
        "jne .Lf8baea_0008bd28\n"
        "movzwl 0xc(%esi), %edx\n" /* line 1518 | entryValue */
        "shll $4, %edx\n"
        "movl -0x1c(%ebp), %eax\n"
        "movw %ax, scrVarGlob(%edx)\n"
        "movw %di, scrVarGlob(%ebx)\n" /* line 1519 | name */
        "movzwl 0xc(%esi), %edx\n" /* line 1520 | entryValue */
        "movw %dx, 0xc(%ecx)\n"
        "movzwl 4(%esi), %eax\n" /* line 1521 | entryValue */
        "movw %ax, 4(%ecx)\n"
        "movl %esi, %ecx\n" /* entryValue */
        "movzwl -0x1a(%ebp), %eax\n"
        ".Lf8baea_0008bc4e:\n"
        "movw %ax, scrVarGlob+4\n" /* line 1526 */
        "movzwl %ax, %eax\n" /* line 1527 */
        "shll $4, %eax\n"
        "movw $0, scrVarGlob+2(%eax)\n"
        "movw %di, 0xc(%ecx)\n" /* line 1529 */
        "movw %di, 0xe(%ecx)\n" /* line 1530 */
        "movw %di, 2(%esi)\n" /* line 1531 | entryValue */
        "movzwl (%esi), %edx\n" /* line 1631 | entryValue */
        "movl %edx, %eax\n" /* line 1632 */
        "shll $4, %eax\n"
        "addl $scrVarGlob, %eax\n"
        "shll $8, 0xc(%ebp)\n" /* line 1637 | classnum */
        "orl $0x75, 0xc(%ebp)\n" /* classnum */
        "movl 0xc(%ebp), %ecx\n" /* classnum */
        "movl %ecx, 8(%eax)\n"
        "movw $0, 4(%eax)\n" /* line 1638 */
        "movzwl -0x1e(%ebp), %ecx\n" /* line 1639 | entnum */
        "movw %cx, 6(%eax)\n"
        /* } scope */
        /* } scope */
        "movl -0x28(%ebp), %eax\n" /* line 3818 | entryValue */
        "orl $1, 8(%eax)\n"
        "movl %edx, 4(%eax)\n" /* line 3819 */
        /* } scope */
        "movl %edx, %eax\n" /* line 3822 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: entry, entnum */
        /* { scope 2 */
        ".Lf8baea_0008bcac:\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, %ebx\n"
        "je .Lf8baea_0008bd49\n"
        "movzwl 0xc(%esi), %esi\n" /* line 757 | entryValue */
        "movl %esi, %edx\n" /* line 758 | entryValue */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x24(%ebp)\n" /* line 759 | entry */
        "je .Lf8baea_0008bb5d\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, %ebx\n"
        "je .Lf8baea_0008bd1b\n"
        ".Lf8baea_0008bce9:\n"
        "movzwl 0xc(%edx), %esi\n" /* line 771 | entryValue */
        "movl %esi, %edx\n" /* line 758 | entryValue */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x24(%ebp)\n" /* line 759 | entry */
        "je .Lf8baea_0008bb5d\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, %ebx\n"
        "jne .Lf8baea_0008bce9\n"
        /* } scope */
        ".Lf8baea_0008bd1b:\n"
        "testl %esi, %esi\n" /* line 1144 | entryValue */
        "jne .Lf8baea_0008bba4\n"
        "jmp .Lf8baea_0008bb5d\n"
        ".Lf8baea_0008bd28:\n"
        "movzwl -0x1a(%ebp), %eax\n"
        "jmp .Lf8baea_0008bc4e\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf8baea_0008bd31:\n"
        "movl $str_0021d3d8, (%esp)\n" /* line 1505 */
        "calll Scr_TerminalError\n"
        "jmp .Lf8baea_0008bbe3\n"
        ".Lf8baea_0008bd42:\n"
        "movl %edx, %eax\n"
        "jmp .Lf8baea_0008bc4e\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf8baea_0008bd49:\n"
        "movl %ecx, %esi\n" /* line 759 | entryValue */
        /* } scope */
        "testl %esi, %esi\n" /* line 1144 | entryValue */
        "jne .Lf8baea_0008bba4\n"
        "jmp .Lf8baea_0008bb5d\n"
    );
}

/* line 3825 */
__attribute__((naked))
unsigned int Scr_EvalArrayIndex(unsigned int parentId, VariableValue *index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3825 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1: entry, entry */
        "movl 0xc(%ebp), %edx\n" /* line 3829 | index */
        "movl 4(%edx), %eax\n"
        "cmpl $6, %eax\n"
        "je .Lf8bd58_0008be62\n"
        "cmpl $2, %eax\n" /* line 3837 */
        "je .Lf8bd58_0008bda0\n"
        "movl var_typename(, %eax, 4), %eax\n" /* line 3844 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021d4b4, (%esp)\n" /* "%s is not an array index" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "xorl %ebx, %ebx\n" /* id */
        /* } scope */
        ".Lf8bd58_0008bd96:\n"
        "movl %ebx, %eax\n" /* line 3846 | id */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: entry, entry */
        ".Lf8bd58_0008bda0:\n"
        "movl 0xc(%ebp), %eax\n" /* line 3839 | index */
        "movl (%eax), %edi\n" /* name */
        "movl 8(%ebp), %edx\n" /* line 1138 | parentId */
        "leal (%edi, %edx), %ecx\n"
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n"
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n"
        "addl $1, %ecx\n"
        /* { scope 2 */
        "movl %ecx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ebx\n" /* entryValue */
        "movl 8(%ebx), %edx\n" /* line 748 | entryValue */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf8bd58_0008bf30\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf8bd58_0008bdf5:\n"
        "movl %edi, %edx\n" /* line 1033 */
        "movl 8(%ebp), %eax\n" /* parentId */
        "calll GetNewVariableIndexInternal3\n"
        "movl %eax, %esi\n"
        "shll $4, 8(%ebp)\n" /* line 1035 | parentId */
        "movl 8(%ebp), %ecx\n" /* parentId */
        "addl $scrVarGlob, %ecx\n"
        "movzwl 0xe(%ecx), %edx\n" /* line 1037 */
        "movl %eax, %ebx\n" /* line 1040 | entryValue */
        "shll $4, %ebx\n" /* entryValue */
        "movzwl scrVarGlob(%ebx), %eax\n" /* line 1043 | entryValue */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+14(%eax)\n"
        "shll $4, %edx\n" /* line 1044 */
        "movw %si, scrVarGlob+2(%edx)\n"
        "movzwl 0xc(%ecx), %eax\n" /* line 1046 */
        "movw %ax, scrVarGlob+2(%ebx)\n" /* entryValue */
        "movw %si, 0xe(%ecx)\n" /* line 1047 */
        "movl 0xc(%ebp), %eax\n" /* index */
        "movl (%eax), %edi\n"
        /* } scope */
        /* } scope */
        ".Lf8bd58_0008be46:\n"
        "shll $4, %esi\n" /* line 2228 | index */
        "movzwl scrVarGlob(%esi), %ebx\n" /* index, entryValue */
        "movl %edi, (%esp)\n" /* line 3840 | name */
        "calll SL_RemoveRefToString\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 3846 | id */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: entry, entry */
        ".Lf8bd58_0008be62:\n"
        "movl (%edx), %edx\n" /* line 3831 */
        "leal vq8+462882(%edx), %eax\n"
        "cmpl $pushed+2177, %eax\n"
        "ja .Lf8bd58_0008bfe7\n"
        "leal s_debugFrameGlob+57728(%edx), %edi\n" /* line 2006 | name */
        "andl $0x00FFFFFF, %edi\n" /* name */
        "movl 8(%ebp), %ecx\n" /* line 1138 | parentId */
        "addl %edi, %ecx\n"
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n"
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n"
        "addl $1, %ecx\n"
        /* { scope 2 */
        "movl %ecx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ebx\n" /* entryValue */
        "movl 8(%ebx), %edx\n" /* line 748 | entryValue */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf8bd58_0008bf86\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf8bd58_0008bed0:\n"
        "movl %edi, %edx\n" /* line 1033 */
        "movl 8(%ebp), %eax\n" /* parentId */
        "calll GetNewVariableIndexInternal3\n"
        "movl %eax, %esi\n"
        "shll $4, 8(%ebp)\n" /* line 1035 | parentId */
        "movl 8(%ebp), %ecx\n" /* parentId */
        "addl $scrVarGlob, %ecx\n"
        "movzwl 0xe(%ecx), %edx\n" /* line 1037 */
        "movl %eax, %ebx\n" /* line 1040 | entryValue */
        "shll $4, %ebx\n" /* entryValue */
        "movzwl scrVarGlob(%ebx), %eax\n" /* line 1043 | entryValue */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+14(%eax)\n"
        "shll $4, %edx\n" /* line 1044 */
        "movw %si, scrVarGlob+2(%edx)\n"
        "movzwl 0xc(%ecx), %eax\n" /* line 1046 */
        "movw %ax, scrVarGlob+2(%ebx)\n" /* entryValue */
        "movw %si, 0xe(%ecx)\n" /* line 1047 */
        /* } scope */
        /* } scope */
        ".Lf8bd58_0008bf1c:\n"
        "shll $4, %esi\n" /* line 2216 | index */
        "movzwl scrVarGlob(%esi), %ebx\n" /* index, entryValue */
        /* } scope */
        "movl %ebx, %eax\n" /* line 3846 | id */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: entry, entry */
        /* { scope 2 */
        ".Lf8bd58_0008bf30:\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, %edi\n"
        "je .Lf8bd58_0008bfd8\n"
        "movzwl 0xc(%ebx), %esi\n" /* line 757 | entryValue */
        "movl %esi, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x1c(%ebp)\n" /* line 759 | entry */
        "je .Lf8bd58_0008bdf5\n"
        ".Lf8bd58_0008bf53:\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, %edi\n"
        "je .Lf8bd58_0008bfda\n"
        "movzwl 0xc(%edx), %esi\n" /* line 771 */
        "movl %esi, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x1c(%ebp)\n" /* line 759 | entry */
        "jne .Lf8bd58_0008bf53\n"
        "jmp .Lf8bd58_0008bdf5\n"
        /* } scope */
        /* { scope 2 */
        ".Lf8bd58_0008bf86:\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, %edi\n"
        "je .Lf8bd58_0008c006\n"
        "movzwl 0xc(%ebx), %esi\n" /* line 757 | entryValue */
        "movl %esi, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x20(%ebp)\n" /* line 759 | entry */
        "je .Lf8bd58_0008bed0\n"
        ".Lf8bd58_0008bfa5:\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %edi, %eax\n"
        "je .Lf8bd58_0008c008\n"
        "movzwl 0xc(%edx), %esi\n" /* line 771 */
        "movl %esi, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x20(%ebp)\n" /* line 759 | entry */
        "jne .Lf8bd58_0008bfa5\n"
        "jmp .Lf8bd58_0008bed0\n"
        /* } scope */
        /* { scope 2 */
        ".Lf8bd58_0008bfd8:\n"
        "movl %ecx, %esi\n"
        /* } scope */
        ".Lf8bd58_0008bfda:\n"
        "testl %esi, %esi\n" /* line 1144 | index */
        "jne .Lf8bd58_0008be46\n"
        "jmp .Lf8bd58_0008bdf5\n"
        ".Lf8bd58_0008bfe7:\n"
        "movl %edx, 4(%esp)\n" /* line 3833 */
        "movl $str_0021d498, (%esp)\n" /* "array index %d out of range" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "xorl %ebx, %ebx\n" /* id */
        "jmp .Lf8bd58_0008bd96\n"
        /* { scope 2 */
        ".Lf8bd58_0008c006:\n"
        "movl %ecx, %esi\n" /* line 759 */
        /* } scope */
        ".Lf8bd58_0008c008:\n"
        "testl %esi, %esi\n" /* line 1144 | index */
        "jne .Lf8bd58_0008bf1c\n"
        "jmp .Lf8bd58_0008bed0\n"
    );
}

/* line 2018 */
__attribute__((naked))
unsigned int Scr_GetVariableField(unsigned int parentId, unsigned int name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2018 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* name */
        /* { scope 1: entry */
        "movl 8(%ebp), %eax\n" /* line 2026 | parentId */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edi\n" /* parentValue */
        "movl 8(%edi), %eax\n" /* line 2027 | parentValue */
        "andl $0x1f, %eax\n"
        "cmpl $0x13, %eax\n" /* line 2029 */
        "jg .Lf8c016_0008c0e5\n"
        "movl 8(%ebp), %ecx\n" /* line 1138 | parentId */
        "addl %esi, %ecx\n"
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n"
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n"
        "addl $1, %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        /* { scope 2 */
        "movl %ecx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movl 8(%ecx), %edx\n" /* line 748 */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf8c016_0008c19a\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf8c016_0008c08f:\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 1033 */
        "movl %esi, %edx\n"
        "movl 8(%ebp), %eax\n" /* parentId */
        "calll GetNewVariableIndexInternal3\n"
        "movl %eax, %ebx\n" /* entryValue */
        "movzwl 0xe(%edi), %edx\n" /* line 1037 | entry */
        "movl %eax, %ecx\n" /* line 1040 */
        "shll $4, %ecx\n"
        "movzwl scrVarGlob(%ecx), %eax\n" /* line 1043 */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+14(%eax)\n"
        "shll $4, %edx\n" /* line 1044 */
        "movw %bx, scrVarGlob+2(%edx)\n" /* entryValue */
        "movzwl 0xc(%edi), %eax\n" /* line 1046 | entry */
        "movw %ax, scrVarGlob+2(%ecx)\n"
        "movw %bx, 0xe(%edi)\n" /* line 1047 | entryValue, entry */
        /* } scope */
        /* } scope */
        ".Lf8c016_0008c0d1:\n"
        "shll $4, %ebx\n" /* line 2228 | index */
        "movzwl scrVarGlob(%ebx), %edx\n" /* index */
        /* } scope */
        ".Lf8c016_0008c0db:\n"
        "movl %edx, %eax\n" /* line 2045 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: entry */
        ".Lf8c016_0008c0e5:\n"
        "cmpl $0x15, %eax\n" /* line 2032 */
        "je .Lf8c016_0008c115\n"
        "movl var_typename(, %eax, 4), %eax\n" /* line 2043 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021d4d0, (%esp)\n" /* "cannot set field of %s" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "xorl %edx, %edx\n"
        /* } scope */
        "movl %edx, %eax\n" /* line 2045 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: entry */
        ".Lf8c016_0008c115:\n"
        "movl 8(%ebp), %ecx\n" /* line 801 | parentId, index */
        "addl %esi, %ecx\n" /* index */
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n" /* index */
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n" /* index */
        "addl $1, %ecx\n" /* index */
        "movzwl %cx, %ecx\n" /* index */
        /* { scope 2 */
        /* { scope 3 */
        "movl %ecx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edi\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ebx\n" /* entryValue */
        "movl 8(%ebx), %edx\n" /* line 748 | entryValue */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf8c016_0008c217\n"
        ".Lf8c016_0008c164:\n"
        "xorl %ecx, %ecx\n" /* line 759 */
        /* } scope */
        /* } scope */
        ".Lf8c016_0008c166:\n"
        "shll $4, %ecx\n" /* line 1992 */
        "movzwl scrVarGlob(%ecx), %eax\n"
        "movzwl %ax, %edx\n"
        "testw %ax, %ax\n" /* line 2035 */
        "jne .Lf8c016_0008c0db\n"
        "movl 8(%ebp), %edx\n" /* line 2038 | parentId */
        "movl %edx, scrVarPub+64\n"
        "movl %esi, scrVarPub+68\n" /* line 2039 | name */
        "movl $0xfffe, %edx\n"
        /* } scope */
        "movl %edx, %eax\n" /* line 2045 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: entry */
        /* { scope 2 */
        ".Lf8c016_0008c19a:\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, %esi\n"
        "je .Lf8c016_0008c207\n"
        "movzwl 0xc(%ecx), %ebx\n" /* line 757 | entryValue */
        "movl %ebx, %edx\n" /* line 758 | entryValue */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x20(%ebp)\n" /* line 759 | entry */
        "je .Lf8c016_0008c08f\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, %esi\n"
        "je .Lf8c016_0008c20a\n"
        ".Lf8c016_0008c1d3:\n"
        "movzwl 0xc(%edx), %ebx\n" /* line 771 | entryValue */
        "movl %ebx, %edx\n" /* line 772 | entryValue */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x20(%ebp)\n" /* line 759 | entry */
        "je .Lf8c016_0008c08f\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %esi, %eax\n"
        "jne .Lf8c016_0008c1d3\n"
        "jmp .Lf8c016_0008c20a\n"
        ".Lf8c016_0008c207:\n"
        "movl -0x1c(%ebp), %ebx\n" /* line 759 | entryValue */
        /* } scope */
        ".Lf8c016_0008c20a:\n"
        "testl %ebx, %ebx\n" /* line 1144 | index */
        "jne .Lf8c016_0008c0d1\n"
        "jmp .Lf8c016_0008c08f\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf8c016_0008c217:\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, %esi\n"
        "je .Lf8c016_0008c166\n"
        "movzwl 0xc(%ebx), %ecx\n" /* line 757 | entryValue */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, %edi\n" /* line 759 | entry */
        "je .Lf8c016_0008c164\n"
        ".Lf8c016_0008c239:\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, %esi\n"
        "je .Lf8c016_0008c166\n"
        "movzwl 0xc(%edx), %ecx\n" /* line 771 */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, %edi\n" /* line 759 | entry */
        "jne .Lf8c016_0008c239\n"
        "jmp .Lf8c016_0008c164\n"
    );
}

/* line 2214 */
__attribute__((naked))
unsigned int GetArrayVariable(unsigned int parentId, unsigned int unsignedValue)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2214 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* parentId */
        "movl 0xc(%ebp), %ebx\n" /* line 2006 | unsignedValue, name */
        "addl $0x00800000, %ebx\n" /* name */
        "andl $0x00FFFFFF, %ebx\n" /* name */
        "leal (%edi, %ebx), %ecx\n" /* line 1138 */
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n"
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n"
        "addl $1, %ecx\n"
        /* { scope 1 */
        "movl %ecx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %esi\n" /* entryValue */
        "movl 8(%esi), %edx\n" /* line 748 | entryValue */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf8c270_0008c32d\n"
        /* } scope */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf8c270_0008c2d4:\n"
        "movl %ebx, %edx\n" /* line 1033 */
        "movl %edi, %eax\n"
        "calll GetNewVariableIndexInternal3\n"
        "movl %eax, %esi\n" /* entryValue */
        "shll $4, %edi\n" /* line 1035 */
        "leal scrVarGlob(%edi), %ecx\n"
        "movzwl 0xe(%ecx), %edx\n" /* line 1037 */
        "movl %eax, %ebx\n" /* line 1040 */
        "shll $4, %ebx\n"
        "movzwl scrVarGlob(%ebx), %eax\n" /* line 1043 */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+14(%eax)\n"
        "shll $4, %edx\n" /* line 1044 */
        "movw %si, scrVarGlob+2(%edx)\n" /* entryValue */
        "movzwl 0xc(%ecx), %eax\n" /* line 1046 */
        "movw %ax, scrVarGlob+2(%ebx)\n"
        "movw %si, 0xe(%ecx)\n" /* line 1047 | entryValue */
        "shll $4, %esi\n" /* entryValue */
        "movzwl scrVarGlob(%esi), %eax\n" /* entryValue */
        /* } scope */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 2217 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf8c270_0008c32d:\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, %ebx\n"
        "je .Lf8c270_0008c3ae\n"
        "movzwl 0xc(%esi), %esi\n" /* line 757 | entryValue */
        "movl %esi, %edx\n" /* line 758 | entryValue */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x1c(%ebp)\n" /* line 759 | entry */
        "je .Lf8c270_0008c2d4\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, %ebx\n"
        "je .Lf8c270_0008c394\n"
        ".Lf8c270_0008c362:\n"
        "movzwl 0xc(%edx), %esi\n" /* line 771 | entryValue */
        "movl %esi, %edx\n" /* line 758 | entryValue */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x1c(%ebp)\n" /* line 759 | entry */
        "je .Lf8c270_0008c2d4\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, %ebx\n"
        "jne .Lf8c270_0008c362\n"
        /* } scope */
        ".Lf8c270_0008c394:\n"
        "testl %esi, %esi\n" /* line 1144 | entryValue */
        "je .Lf8c270_0008c2d4\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf8c270_0008c39c:\n"
        "shll $4, %esi\n" /* line 1047 | entryValue */
        "movzwl scrVarGlob(%esi), %eax\n" /* entryValue */
        /* } scope */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 2217 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf8c270_0008c3ae:\n"
        "movl %ecx, %esi\n" /* line 759 | entryValue */
        /* } scope */
        "testl %esi, %esi\n" /* line 1144 | entryValue */
        "je .Lf8c270_0008c2d4\n"
        "jmp .Lf8c270_0008c39c\n"
    );
}

/* line 2226 */
__attribute__((naked))
unsigned int GetVariable(unsigned int parentId, unsigned int unsignedValue)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2226 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* DBG: count and trace GetVariable calls */
        "addl $1, dbg_getvar_counter\n"
        "cmpl $5, dbg_getvar_counter\n"
        "jbe .Ldbg_getvar_trace\n"
        "movzwl scrVarGlob+4, %eax\n"
        "cmpl $100, %eax\n"
        "ja .Ldbg_getvar_skip\n"
        ".Ldbg_getvar_trace:\n"
        "pushl scrVarGlob+4\n"
        "pushl 0xc(%ebp)\n"
        "pushl 8(%ebp)\n"
        "pushl dbg_getvar_counter\n"
        "pushl $str_dbg_getvar_fmt\n"
        "calll Com_Printf\n"
        "addl $20, %esp\n"
        ".Ldbg_getvar_skip:\n"
        "movl 8(%ebp), %edi\n" /* parentId */
        "movl 0xc(%ebp), %eax\n" /* line 1138 | unsignedValue */
        "leal (%edi, %eax), %ecx\n"
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n"
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n"
        "addl $1, %ecx\n"
        /* { scope 1 */
        "movl %ecx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ebx\n" /* entryValue */
        "movl 8(%ebx), %edx\n" /* line 748 | entryValue */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf8c3ba_0008c46c\n"
        /* } scope */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf8c3ba_0008c412:\n"
        "movl 0xc(%ebp), %edx\n" /* line 1033 | unsignedValue */
        "movl %edi, %eax\n"
        "calll GetNewVariableIndexInternal3\n"
        "movl %eax, %esi\n"
        "shll $4, %edi\n" /* line 1035 */
        "leal scrVarGlob(%edi), %ecx\n"
        "movzwl 0xe(%ecx), %edx\n" /* line 1037 */
        "movl %eax, %ebx\n" /* line 1040 | entryValue */
        "shll $4, %ebx\n" /* entryValue */
        "movzwl scrVarGlob(%ebx), %eax\n" /* line 1043 | entryValue */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+14(%eax)\n"
        "shll $4, %edx\n" /* line 1044 */
        "movw %si, scrVarGlob+2(%edx)\n"
        "movzwl 0xc(%ecx), %eax\n" /* line 1046 */
        "movw %ax, scrVarGlob+2(%ebx)\n" /* entryValue */
        "movw %si, 0xe(%ecx)\n" /* line 1047 */
        "shll $4, %esi\n"
        "movzwl scrVarGlob(%esi), %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 2229 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf8c3ba_0008c46c:\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, 0xc(%ebp)\n" /* unsignedValue */
        "je .Lf8c3ba_0008c4f0\n"
        "movzwl 0xc(%ebx), %esi\n" /* line 757 | entryValue */
        "movl %esi, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x1c(%ebp)\n" /* line 759 | entry */
        "je .Lf8c3ba_0008c412\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, 0xc(%ebp)\n" /* unsignedValue */
        "je .Lf8c3ba_0008c4d6\n"
        ".Lf8c3ba_0008c4a3:\n"
        "movzwl 0xc(%edx), %esi\n" /* line 771 */
        "movl %esi, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x1c(%ebp)\n" /* line 759 | entry */
        "je .Lf8c3ba_0008c412\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, 0xc(%ebp)\n" /* unsignedValue */
        "jne .Lf8c3ba_0008c4a3\n"
        /* } scope */
        ".Lf8c3ba_0008c4d6:\n"
        "testl %esi, %esi\n" /* line 1144 */
        "je .Lf8c3ba_0008c412\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf8c3ba_0008c4de:\n"
        "shll $4, %esi\n" /* line 1047 */
        "movzwl scrVarGlob(%esi), %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 2229 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf8c3ba_0008c4f0:\n"
        "movl %ecx, %esi\n" /* line 759 */
        /* } scope */
        "testl %esi, %esi\n" /* line 1144 */
        "je .Lf8c3ba_0008c412\n"
        "jmp .Lf8c3ba_0008c4de\n"
    );
}

/* line 2238 */
__attribute__((naked))
unsigned int GetObjectVariable(unsigned int parentId, unsigned int id)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2238 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* parentId */
        "movl 0xc(%ebp), %eax\n" /* line 2242 | id */
        "addl $0x10000, %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* name */
        "movl %eax, %ecx\n" /* line 1138 */
        "addl %edi, %ecx\n"
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n"
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n"
        "addl $1, %ecx\n"
        /* { scope 1 */
        "movl %ecx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ebx\n" /* entryValue */
        "movl 8(%ebx), %edx\n" /* line 748 | entryValue */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf8c4fc_0008c5b7\n"
        /* } scope */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf8c4fc_0008c55d:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1033 | name */
        "movl %edi, %eax\n"
        "calll GetNewVariableIndexInternal3\n"
        "movl %eax, %esi\n"
        "shll $4, %edi\n" /* line 1035 */
        "leal scrVarGlob(%edi), %ecx\n"
        "movzwl 0xe(%ecx), %edx\n" /* line 1037 */
        "movl %eax, %ebx\n" /* line 1040 | entryValue */
        "shll $4, %ebx\n" /* entryValue */
        "movzwl scrVarGlob(%ebx), %eax\n" /* line 1043 | entryValue */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+14(%eax)\n"
        "shll $4, %edx\n" /* line 1044 */
        "movw %si, scrVarGlob+2(%edx)\n"
        "movzwl 0xc(%ecx), %eax\n" /* line 1046 */
        "movw %ax, scrVarGlob+2(%ebx)\n" /* entryValue */
        "movw %si, 0xe(%ecx)\n" /* line 1047 */
        "shll $4, %esi\n"
        "movzwl scrVarGlob(%esi), %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 2243 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf8c4fc_0008c5b7:\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, -0x1c(%ebp)\n" /* name */
        "je .Lf8c4fc_0008c63b\n"
        "movzwl 0xc(%ebx), %esi\n" /* line 757 | entryValue */
        "movl %esi, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x20(%ebp)\n" /* line 759 | entry */
        "je .Lf8c4fc_0008c55d\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, -0x1c(%ebp)\n" /* name */
        "je .Lf8c4fc_0008c621\n"
        ".Lf8c4fc_0008c5ee:\n"
        "movzwl 0xc(%edx), %esi\n" /* line 771 */
        "movl %esi, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x20(%ebp)\n" /* line 759 | entry */
        "je .Lf8c4fc_0008c55d\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, -0x1c(%ebp)\n" /* name */
        "jne .Lf8c4fc_0008c5ee\n"
        /* } scope */
        ".Lf8c4fc_0008c621:\n"
        "testl %esi, %esi\n" /* line 1144 */
        "je .Lf8c4fc_0008c55d\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf8c4fc_0008c629:\n"
        "shll $4, %esi\n" /* line 1047 */
        "movzwl scrVarGlob(%esi), %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 2243 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf8c4fc_0008c63b:\n"
        "movl %ecx, %esi\n" /* line 759 */
        /* } scope */
        "testl %esi, %esi\n" /* line 1144 */
        "je .Lf8c4fc_0008c55d\n"
        "jmp .Lf8c4fc_0008c629\n"
    );
}

/* line 2341 */
static __attribute__((naked))
JCOEF CopyArray(unsigned int parentId, unsigned int newParentId)
{
    __asm__ __volatile__ (
        ".Lf8c64a_0008c64a:\n"
        "pushl %ebp\n" /* line 2341 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl %edx, -0x3c(%ebp)\n"
        /* { scope 1: entry */
        "shll $4, %eax\n" /* line 2357 */
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* id */
        "cmpl %eax, -0x38(%ebp)\n" /* line 2358 */
        "je .Lf8c64a_0008c7f0\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl $scrVarGlob, %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* parentValue */
        "movl -0x2c(%ebp), %eax\n" /* id */
        ".Lf8c64a_0008c689:\n"
        "shll $4, %eax\n" /* line 2360 */
        "addl $scrVarGlob, %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* entryValue */
        "movl 8(%eax), %eax\n" /* line 2362 */
        "movl %eax, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl %ecx, -0x34(%ebp)\n" /* type */
        "movl %eax, %esi\n" /* line 2365 | name */
        "shrl $8, %esi\n" /* name */
        "movl -0x3c(%ebp), %eax\n" /* line 1138 */
        "leal (%esi, %eax), %ecx\n"
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n"
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n"
        "leal 1(%ecx), %edi\n"
        /* { scope 2: parentValue */
        "movl %edi, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl %edx, -0x28(%ebp)\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movl 8(%ecx), %edx\n" /* line 748 */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "jne .Lf8c64a_0008c741\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, %esi\n"
        "je .Lf8c64a_0008c7f8\n"
        "movzwl 0xc(%ecx), %ebx\n" /* line 757 */
        "movl %ebx, %edx\n" /* line 772 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x28(%ebp)\n" /* line 759 | entry */
        "je .Lf8c64a_0008c741\n"
        ".Lf8c64a_0008c70f:\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, %esi\n"
        "je .Lf8c64a_0008c7fa\n"
        "movzwl 0xc(%edx), %ebx\n" /* line 771 */
        "movl %ebx, %edx\n" /* line 772 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x28(%ebp)\n" /* line 759 | entry */
        "jne .Lf8c64a_0008c70f\n"
        /* } scope */
        /* { scope 2: parentValue */
        /* { scope 3 */
        ".Lf8c64a_0008c741:\n"
        "movl %edi, %ecx\n" /* line 1033 */
        "movl %esi, %edx\n"
        "movl -0x3c(%ebp), %eax\n"
        "calll GetNewVariableIndexInternal3\n"
        "movl %eax, %ebx\n"
        "movl -0x24(%ebp), %ecx\n" /* line 1037 | parentValue */
        "movzwl 0xe(%ecx), %edx\n"
        "movl %eax, %ecx\n" /* line 1040 */
        "shll $4, %ecx\n"
        "movzwl scrVarGlob(%ecx), %eax\n" /* line 1043 */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+14(%eax)\n"
        "shll $4, %edx\n" /* line 1044 */
        "movw %bx, scrVarGlob+2(%edx)\n"
        "movl -0x24(%ebp), %edx\n" /* line 1046 | parentValue */
        "movzwl 0xc(%edx), %eax\n"
        "movw %ax, scrVarGlob+2(%ecx)\n"
        "movw %bx, 0xe(%edx)\n" /* line 1047 */
        /* } scope */
        /* } scope */
        "shll $4, %ebx\n" /* line 2366 | newEntryValue */
        "movzwl scrVarGlob(%ebx), %eax\n" /* newEntryValue */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ebx\n" /* newEntryValue */
        "movl -0x34(%ebp), %ecx\n" /* line 2371 | type */
        "orl %ecx, 8(%ebx)\n" /* newEntryValue */
        "cmpl $1, %ecx\n" /* line 2373 */
        "je .Lf8c64a_0008c820\n"
        ".Lf8c64a_0008c7a6:\n"
        "movl -0x30(%ebp), %edx\n" /* line 2377 | entryValue */
        "movl 4(%edx), %eax\n"
        "movl %eax, 4(%ebx)\n" /* newEntryValue */
        "movl 4(%edx), %eax\n" /* line 2378 */
        "cmpl $3, %ecx\n" /* line 1928 */
        "jg .Lf8c64a_0008c852\n"
        "cmpl $2, %ecx\n"
        "jl .Lf8c64a_0008c94c\n"
        "movl %eax, (%esp)\n" /* line 1935 */
        "calll SL_AddRefToString\n"
        ".Lf8c64a_0008c7cc:\n"
        "shll $4, -0x2c(%ebp)\n" /* line 2395 | id */
        "movl -0x2c(%ebp), %ecx\n" /* id */
        "movzwl scrVarGlob+14(%ecx), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* id */
        "cmpl %eax, -0x38(%ebp)\n" /* line 2358 */
        "jne .Lf8c64a_0008c689\n"
        /* } scope */
        ".Lf8c64a_0008c7f0:\n"
        "addl $0x4c, %esp\n" /* line 2397 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: entry */
        /* { scope 2: parentValue */
        ".Lf8c64a_0008c7f8:\n"
        "movl %edi, %ebx\n" /* line 759 */
        /* } scope */
        ".Lf8c64a_0008c7fa:\n"
        "testl %ebx, %ebx\n" /* line 1144 */
        "je .Lf8c64a_0008c741\n"
        "shll $4, %ebx\n" /* line 2366 | newEntryValue */
        "movzwl scrVarGlob(%ebx), %eax\n" /* newEntryValue */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ebx\n" /* newEntryValue */
        "movl -0x34(%ebp), %ecx\n" /* line 2371 | type */
        "orl %ecx, 8(%ebx)\n" /* newEntryValue */
        "cmpl $1, %ecx\n" /* line 2373 */
        "jne .Lf8c64a_0008c7a6\n"
        ".Lf8c64a_0008c820:\n"
        "movl -0x30(%ebp), %ecx\n" /* line 2382 | entryValue */
        "movl 4(%ecx), %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0x16, %eax\n"
        "je .Lf8c64a_0008c870\n"
        "movl %edx, 4(%ebx)\n" /* line 2389 | newEntryValue */
        "movl -0x30(%ebp), %edx\n" /* line 2390 | entryValue */
        "movl 4(%edx), %eax\n" /* id */
        /* { scope 2: parentValue */
        ".Lf8c64a_0008c842:\n"
        "shll $4, %eax\n" /* line 1748 */
        "addw $1, scrVarGlob+4(%eax)\n"
        "jmp .Lf8c64a_0008c7cc\n"
        /* } scope */
        ".Lf8c64a_0008c852:\n"
        "cmpl $4, -0x34(%ebp)\n" /* line 1928 | type */
        "jne .Lf8c64a_0008c7cc\n"
        "cmpb $0, -1(%eax)\n" /* line 1879 */
        "jne .Lf8c64a_0008c7cc\n"
        "addw $1, -4(%eax)\n" /* line 1894 */
        "jmp .Lf8c64a_0008c7cc\n"
        ".Lf8c64a_0008c870:\n"
        "movzwl scrVarGlob+4, %eax\n" /* line 1503 */
        "movw %ax, -0x1c(%ebp)\n"
        "testw %ax, %ax\n" /* line 1504 */
        "je .Lf8c64a_0008c960\n"
        ".Lf8c64a_0008c884:\n"
        "movzwl -0x1c(%ebp), %edi\n" /* line 1507 | index */
        "shll $4, %edi\n" /* index */
        "leal scrVarGlob(%edi), %esi\n" /* index, name */
        "movzwl scrVarGlob(%edi), %edx\n" /* line 1508 | index */
        "movw %dx, -0x1e(%ebp)\n"
        "movzwl %dx, %eax\n"
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movzwl 4(%ecx), %eax\n" /* line 1511 */
        "movw %ax, -0x1a(%ebp)\n"
        "cmpl %ecx, %esi\n" /* line 1514 | name */
        "je .Lf8c64a_0008c971\n"
        "testb $0x60, 8(%esi)\n" /* name */
        "jne .Lf8c64a_0008c95a\n"
        "movzwl 0xc(%esi), %edx\n" /* line 1518 | name */
        "shll $4, %edx\n"
        "movzwl -0x1e(%ebp), %eax\n"
        "movw %ax, scrVarGlob(%edx)\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1519 */
        "movw %dx, scrVarGlob(%edi)\n" /* index */
        "movzwl 0xc(%esi), %eax\n" /* line 1520 | name */
        "movw %ax, 0xc(%ecx)\n"
        "movzwl 4(%esi), %eax\n" /* line 1521 | name */
        "movw %ax, 4(%ecx)\n"
        "movl %esi, %ecx\n" /* name */
        "movzwl -0x1a(%ebp), %edx\n"
        ".Lf8c64a_0008c8f4:\n"
        "movw %dx, scrVarGlob+4\n" /* line 1526 */
        "movzwl %dx, %eax\n" /* line 1527 */
        "shll $4, %eax\n"
        "movw $0, scrVarGlob+2(%eax)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1529 */
        "movw %ax, 0xc(%ecx)\n"
        "movw %ax, 0xe(%ecx)\n" /* line 1530 */
        "movw %ax, 2(%esi)\n" /* line 1531 | name */
        "movzwl (%esi), %edx\n" /* line 1657 | name */
        "movl %edx, %eax\n" /* line 1658 */
        "shll $4, %eax\n"
        "addl $scrVarGlob, %eax\n"
        "movl $0x76, 8(%eax)\n" /* line 1661 */
        "movw $0, 4(%eax)\n" /* line 1662 */
        "movw $0, 6(%eax)\n" /* line 1663 */
        "movl %edx, 4(%ebx)\n" /* line 2384 | newEntryValue */
        "movl -0x30(%ebp), %ecx\n" /* line 2385 | entryValue */
        "movl 4(%ecx), %eax\n"
        "calll CopyArray\n"
        "jmp .Lf8c64a_0008c7cc\n"
        ".Lf8c64a_0008c94c:\n"
        "subl $1, %ecx\n" /* line 1928 */
        "jne .Lf8c64a_0008c7cc\n"
        "jmp .Lf8c64a_0008c842\n"
        ".Lf8c64a_0008c95a:\n"
        "movzwl -0x1a(%ebp), %edx\n"
        "jmp .Lf8c64a_0008c8f4\n"
        ".Lf8c64a_0008c960:\n"
        "movl $str_0021d3d8, (%esp)\n" /* line 1505 */
        "calll Scr_TerminalError\n"
        "jmp .Lf8c64a_0008c884\n"
        ".Lf8c64a_0008c971:\n"
        "movl %eax, %edx\n"
        "jmp .Lf8c64a_0008c8f4\n"
    );
}

/* line 3685 */
__attribute__((naked))
JCOEF Scr_SetClassMap(int classnum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3685 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movzwl scrVarGlob+4, %edi\n" /* line 1503 */
        "testw %di, %di\n" /* line 1504 */
        "je .Lf8c978_0008cb1e\n"
        ".Lf8c978_0008c991:\n"
        "movzwl %di, %esi\n" /* line 1507 */
        "shll $4, %esi\n"
        "leal scrVarGlob(%esi), %ebx\n"
        "movzwl scrVarGlob(%esi), %eax\n" /* line 1508 */
        "movw %ax, -0x20(%ebp)\n"
        "movzwl %ax, %eax\n"
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movzwl 4(%ecx), %eax\n" /* line 1511 */
        "movw %ax, -0x1e(%ebp)\n"
        "cmpl %ecx, %ebx\n" /* line 1514 */
        "je .Lf8c978_0008c9ce\n"
        "testb $0x60, 8(%ebx)\n"
        "je .Lf8c978_0008caeb\n"
        "movzwl -0x1e(%ebp), %eax\n"
        ".Lf8c978_0008c9ce:\n"
        "movw %ax, scrVarGlob+4\n" /* line 1526 */
        "movzwl %ax, %eax\n" /* line 1527 */
        "shll $4, %eax\n"
        "movw $0, scrVarGlob+2(%eax)\n"
        "movw %di, 0xc(%ecx)\n" /* line 1529 */
        "movw %di, 0xe(%ecx)\n" /* line 1530 */
        "movw %di, 2(%ebx)\n" /* line 1531 */
        "movzwl (%ebx), %edx\n" /* line 1657 */
        "movl %edx, %eax\n" /* line 1658 */
        "shll $4, %eax\n"
        "addl $scrVarGlob, %eax\n"
        "movl $0x76, 8(%eax)\n" /* line 1661 */
        "movw $0, 4(%eax)\n" /* line 1662 */
        "movw $0, 6(%eax)\n" /* line 1663 */
        "movl 8(%ebp), %ecx\n" /* line 3690 | classnum */
        "leal (%ecx, %ecx, 2), %eax\n"
        "movw %dx, g_classMap+2(, %eax, 4)\n"
        "movzwl scrVarGlob+4, %edi\n" /* line 1503 */
        "testw %di, %di\n" /* line 1504 */
        "je .Lf8c978_0008cb2f\n"
        ".Lf8c978_0008ca2d:\n"
        "movzwl %di, %esi\n" /* line 1507 */
        "shll $4, %esi\n"
        "leal scrVarGlob(%esi), %ebx\n"
        "movzwl scrVarGlob(%esi), %eax\n" /* line 1508 */
        "movw %ax, -0x1c(%ebp)\n"
        "movzwl %ax, %eax\n"
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movzwl 4(%ecx), %eax\n" /* line 1511 */
        "movw %ax, -0x1a(%ebp)\n"
        "cmpl %ecx, %ebx\n" /* line 1514 */
        "je .Lf8c978_0008ca94\n"
        "testb $0x60, 8(%ebx)\n"
        "jne .Lf8c978_0008cb40\n"
        "movzwl 0xc(%ebx), %edx\n" /* line 1518 */
        "shll $4, %edx\n"
        "movl -0x1c(%ebp), %eax\n"
        "movw %ax, scrVarGlob(%edx)\n"
        "movw %di, scrVarGlob(%esi)\n" /* line 1519 */
        "movzwl 0xc(%ebx), %eax\n" /* line 1520 */
        "movw %ax, 0xc(%ecx)\n"
        "movzwl 4(%ebx), %eax\n" /* line 1521 */
        "movw %ax, 4(%ecx)\n"
        "movl %ebx, %ecx\n"
        "movzwl -0x1a(%ebp), %eax\n"
        ".Lf8c978_0008ca94:\n"
        "movw %ax, scrVarGlob+4\n" /* line 1526 */
        "movzwl %ax, %eax\n" /* line 1527 */
        "shll $4, %eax\n"
        "movw $0, scrVarGlob+2(%eax)\n"
        "movw %di, 0xc(%ecx)\n" /* line 1529 */
        "movw %di, 0xe(%ecx)\n" /* line 1530 */
        "movw %di, 2(%ebx)\n" /* line 1531 */
        "movzwl (%ebx), %edx\n" /* line 1657 */
        "movl %edx, %eax\n" /* line 1658 */
        "shll $4, %eax\n"
        "addl $scrVarGlob, %eax\n"
        "movl $0x76, 8(%eax)\n" /* line 1661 */
        "movw $0, 4(%eax)\n" /* line 1662 */
        "movw $0, 6(%eax)\n" /* line 1663 */
        "movl 8(%ebp), %ecx\n" /* line 3695 | classnum */
        "leal (%ecx, %ecx, 2), %eax\n"
        "movw %dx, g_classMap(, %eax, 4)\n"
        "addl $0x2c, %esp\n" /* line 3699 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf8c978_0008caeb:\n"
        "movzwl 0xc(%ebx), %edx\n" /* line 1518 */
        "shll $4, %edx\n"
        "movl -0x20(%ebp), %eax\n"
        "movw %ax, scrVarGlob(%edx)\n"
        "movw %di, scrVarGlob(%esi)\n" /* line 1519 */
        "movzwl 0xc(%ebx), %eax\n" /* line 1520 */
        "movw %ax, 0xc(%ecx)\n"
        "movzwl 4(%ebx), %eax\n" /* line 1521 */
        "movw %ax, 4(%ecx)\n"
        "movl %ebx, %ecx\n"
        "movzwl -0x1e(%ebp), %eax\n"
        "jmp .Lf8c978_0008c9ce\n"
        ".Lf8c978_0008cb1e:\n"
        "pushl $str_dbg_site_classmap1\n"
        "calll Com_Printf\n"
        "addl $4, %esp\n"
        "movl $str_0021d3d8, (%esp)\n" /* line 1505 */
        "calll Scr_TerminalError\n"
        "jmp .Lf8c978_0008c991\n"
        ".Lf8c978_0008cb2f:\n"
        "pushl $str_dbg_site_classmap2\n"
        "calll Com_Printf\n"
        "addl $4, %esp\n"
        "movl $str_0021d3d8, (%esp)\n" /* "exceeded maximum number of script variables" */
        "calll Scr_TerminalError\n"
        "jmp .Lf8c978_0008ca2d\n"
        ".Lf8c978_0008cb40:\n"
        "movzwl -0x1a(%ebp), %eax\n"
        "jmp .Lf8c978_0008ca94\n"
    );
}

/* line 2711 */
__attribute__((naked))
unsigned int GetArray(unsigned int id)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2711 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* id */
        /* { scope 1 */
        "shll $4, %eax\n" /* line 2717 */
        "addl $scrVarGlob, %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* entryValue */
        "movl %eax, %edx\n" /* line 2721 */
        "movl 8(%eax), %eax\n"
        "testb $0x1f, %al\n"
        "jne .Lf8cb4a_0008cc08\n"
        "orl $1, %eax\n" /* line 2724 */
        "movl %eax, 8(%edx)\n"
        "movzwl scrVarGlob+4, %edi\n" /* line 1503 */
        "testw %di, %di\n" /* line 1504 */
        "je .Lf8cb4a_0008cc49\n"
        ".Lf8cb4a_0008cb84:\n"
        "movzwl %di, %esi\n" /* line 1507 */
        "shll $4, %esi\n"
        "leal scrVarGlob(%esi), %ebx\n"
        "movzwl scrVarGlob(%esi), %eax\n" /* line 1508 */
        "movw %ax, -0x1c(%ebp)\n"
        "movzwl %ax, %eax\n"
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movzwl 4(%ecx), %edx\n" /* line 1511 */
        "movw %dx, -0x1a(%ebp)\n"
        "cmpl %ecx, %ebx\n" /* line 1514 */
        "je .Lf8cb4a_0008cc5a\n"
        "testb $0x60, 8(%ebx)\n"
        "je .Lf8cb4a_0008cc16\n"
        "movzwl -0x1a(%ebp), %eax\n"
        ".Lf8cb4a_0008cbc1:\n"
        "movw %ax, scrVarGlob+4\n" /* line 1526 */
        "movzwl %ax, %eax\n" /* line 1527 */
        "shll $4, %eax\n"
        "movw $0, scrVarGlob+2(%eax)\n"
        "movw %di, 0xc(%ecx)\n" /* line 1529 */
        "movw %di, 0xe(%ecx)\n" /* line 1530 */
        "movw %di, 2(%ebx)\n" /* line 1531 */
        "movzwl (%ebx), %edx\n" /* line 1657 */
        "movl %edx, %eax\n" /* line 1658 */
        "shll $4, %eax\n"
        "addl $scrVarGlob, %eax\n"
        "movl $0x76, 8(%eax)\n" /* line 1661 */
        "movw $0, 4(%eax)\n" /* line 1662 */
        "movw $0, 6(%eax)\n" /* line 1663 */
        "movl -0x20(%ebp), %eax\n" /* line 2725 | entryValue */
        "movl %edx, 4(%eax)\n"
        ".Lf8cb4a_0008cc08:\n"
        "movl -0x20(%ebp), %edx\n" /* entryValue */
        "movl 4(%edx), %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 2730 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf8cb4a_0008cc16:\n"
        "movzwl 0xc(%ebx), %edx\n" /* line 1518 */
        "shll $4, %edx\n"
        "movl -0x1c(%ebp), %eax\n"
        "movw %ax, scrVarGlob(%edx)\n"
        "movw %di, scrVarGlob(%esi)\n" /* line 1519 */
        "movzwl 0xc(%ebx), %edx\n" /* line 1520 */
        "movw %dx, 0xc(%ecx)\n"
        "movzwl 4(%ebx), %eax\n" /* line 1521 */
        "movw %ax, 4(%ecx)\n"
        "movl %ebx, %ecx\n"
        "movzwl -0x1a(%ebp), %eax\n"
        "jmp .Lf8cb4a_0008cbc1\n"
        ".Lf8cb4a_0008cc49:\n"
        "movl $str_0021d3d8, (%esp)\n" /* line 1505 */
        "calll Scr_TerminalError\n"
        "jmp .Lf8cb4a_0008cb84\n"
        ".Lf8cb4a_0008cc5a:\n"
        "movl %edx, %eax\n"
        "jmp .Lf8cb4a_0008cbc1\n"
    );
}

/* line 2689 */
__attribute__((naked))
unsigned int GetObjectA(unsigned int id)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2689 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* id */
        /* { scope 1 */
        "shll $4, %eax\n" /* line 2695 */
        "addl $scrVarGlob, %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* entryValue */
        "movl %eax, %edx\n" /* line 2699 */
        "movl 8(%eax), %eax\n"
        "testb $0x1f, %al\n"
        "jne .Lf8cc62_0008cd1a\n"
        "orl $1, %eax\n" /* line 2702 */
        "movl %eax, 8(%edx)\n"
        "movzwl scrVarGlob+4, %edi\n" /* line 1503 */
        "testw %di, %di\n" /* line 1504 */
        "je .Lf8cc62_0008cd58\n"
        ".Lf8cc62_0008cc9c:\n"
        "movzwl %di, %esi\n" /* line 1507 */
        "shll $4, %esi\n"
        "leal scrVarGlob(%esi), %ebx\n"
        "movzwl scrVarGlob(%esi), %eax\n" /* line 1508 */
        "movw %ax, -0x1c(%ebp)\n"
        "movzwl %ax, %eax\n"
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movzwl 4(%ecx), %edx\n" /* line 1511 */
        "movw %dx, -0x1a(%ebp)\n"
        "cmpl %ecx, %ebx\n" /* line 1514 */
        "je .Lf8cc62_0008cd69\n"
        "testb $0x60, 8(%ebx)\n"
        "je .Lf8cc62_0008cd28\n"
        "movzwl -0x1a(%ebp), %eax\n"
        ".Lf8cc62_0008ccd9:\n"
        "movw %ax, scrVarGlob+4\n" /* line 1526 */
        "movzwl %ax, %eax\n" /* line 1527 */
        "shll $4, %eax\n"
        "movw $0, scrVarGlob+2(%eax)\n"
        "movw %di, 0xc(%ecx)\n" /* line 1529 */
        "movw %di, 0xe(%ecx)\n" /* line 1530 */
        "movw %di, 2(%ebx)\n" /* line 1531 */
        "movzwl (%ebx), %edx\n" /* line 1615 */
        "movl %edx, %eax\n" /* line 1616 */
        "shll $4, %eax\n"
        "addl $scrVarGlob, %eax\n"
        "movl $0x73, 8(%eax)\n" /* line 1619 */
        "movw $0, 4(%eax)\n" /* line 1620 */
        "movl -0x20(%ebp), %eax\n" /* line 2703 | entryValue */
        "movl %edx, 4(%eax)\n"
        ".Lf8cc62_0008cd1a:\n"
        "movl -0x20(%ebp), %edx\n" /* entryValue */
        "movl 4(%edx), %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 2708 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf8cc62_0008cd28:\n"
        "movzwl 0xc(%ebx), %edx\n" /* line 1518 */
        "shll $4, %edx\n"
        "movl -0x1c(%ebp), %eax\n"
        "movw %ax, scrVarGlob(%edx)\n"
        "movw %di, scrVarGlob(%esi)\n" /* line 1519 */
        "movzwl 0xc(%ebx), %edx\n" /* line 1520 */
        "movw %dx, 0xc(%ecx)\n"
        "movzwl 4(%ebx), %eax\n" /* line 1521 */
        "movw %ax, 4(%ecx)\n"
        "movl %ebx, %ecx\n"
        "movzwl -0x1a(%ebp), %eax\n"
        "jmp .Lf8cc62_0008ccd9\n"
        ".Lf8cc62_0008cd58:\n"
        "movl $str_0021d3d8, (%esp)\n" /* line 1505 */
        "calll Scr_TerminalError\n"
        "jmp .Lf8cc62_0008cc9c\n"
        ".Lf8cc62_0008cd69:\n"
        "movl %edx, %eax\n"
        "jmp .Lf8cc62_0008ccd9\n"
    );
}

/* line 1595 */
__attribute__((naked))
unsigned int AllocValue(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1595 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movzwl scrVarGlob+4, %edi\n" /* line 1503 */
        "testw %di, %di\n" /* line 1504 */
        "je .Lf8cd70_0008ce27\n"
        ".Lf8cd70_0008cd89:\n"
        "movzwl %di, %esi\n" /* line 1507 */
        "shll $4, %esi\n"
        "leal scrVarGlob(%esi), %ebx\n"
        "movzwl scrVarGlob(%esi), %eax\n" /* line 1508 */
        "movw %ax, -0x1c(%ebp)\n"
        "movzwl %ax, %eax\n"
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movzwl 4(%ecx), %eax\n" /* line 1511 */
        "movw %ax, -0x1a(%ebp)\n"
        "cmpl %ecx, %ebx\n" /* line 1514 */
        "je .Lf8cd70_0008cdec\n"
        "testb $0x60, 8(%ebx)\n"
        "jne .Lf8cd70_0008ce38\n"
        "movzwl 0xc(%ebx), %edx\n" /* line 1518 */
        "shll $4, %edx\n"
        "movl -0x1c(%ebp), %eax\n"
        "movw %ax, scrVarGlob(%edx)\n"
        "movw %di, scrVarGlob(%esi)\n" /* line 1519 */
        "movzwl 0xc(%ebx), %eax\n" /* line 1520 */
        "movw %ax, 0xc(%ecx)\n"
        "movzwl 4(%ebx), %eax\n" /* line 1521 */
        "movw %ax, 4(%ecx)\n"
        "movl %ebx, %ecx\n"
        "movzwl -0x1a(%ebp), %eax\n"
        ".Lf8cd70_0008cdec:\n"
        "movw %ax, scrVarGlob+4\n" /* line 1526 */
        "movzwl %ax, %eax\n" /* line 1527 */
        "shll $4, %eax\n"
        "movw $0, scrVarGlob+2(%eax)\n"
        "movw %di, 0xc(%ecx)\n" /* line 1529 */
        "movw %di, 0xe(%ecx)\n" /* line 1530 */
        "movw %di, 2(%ebx)\n" /* line 1531 */
        "movzwl (%ebx), %eax\n" /* line 1600 */
        "movl %eax, %edx\n" /* line 1601 */
        "shll $4, %edx\n"
        "movl $0x60, scrVarGlob+8(%edx)\n" /* line 1602 */
        "addl $1, dbg_alloc_counter\n" /* DBG: count allocations */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1607 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf8cd70_0008ce27:\n"
        "movl $str_0021d3d8, (%esp)\n" /* line 1505 */
        /* DBG: print allocation count before terminal error */
        "pushl %eax\n"
        "pushl dbg_alloc_counter\n"
        "pushl $str_dbg_alloc_fmt\n"
        "calll Com_Printf\n"
        "addl $8, %esp\n"
        "popl %eax\n"
        "calll Scr_TerminalError\n"
        "jmp .Lf8cd70_0008cd89\n"
        ".Lf8cd70_0008ce38:\n"
        "movzwl -0x1a(%ebp), %eax\n"
        "jmp .Lf8cd70_0008cdec\n"
    );
}

/* line 1610 */
__attribute__((naked))
unsigned int AllocObject(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1610 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movzwl scrVarGlob+4, %edi\n" /* line 1503 */
        "testw %di, %di\n" /* line 1504 */
        "je .Lf8ce3e_0008cf02\n"
        ".Lf8ce3e_0008ce57:\n"
        "movzwl %di, %esi\n" /* line 1507 */
        "shll $4, %esi\n"
        "leal scrVarGlob(%esi), %ebx\n"
        "movzwl scrVarGlob(%esi), %eax\n" /* line 1508 */
        "movw %ax, -0x1c(%ebp)\n"
        "movzwl %ax, %eax\n"
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movzwl 4(%ecx), %eax\n" /* line 1511 */
        "movw %ax, -0x1a(%ebp)\n"
        "cmpl %ecx, %ebx\n" /* line 1514 */
        "je .Lf8ce3e_0008cebe\n"
        "testb $0x60, 8(%ebx)\n"
        "jne .Lf8ce3e_0008cf13\n"
        "movzwl 0xc(%ebx), %edx\n" /* line 1518 */
        "shll $4, %edx\n"
        "movl -0x1c(%ebp), %eax\n"
        "movw %ax, scrVarGlob(%edx)\n"
        "movw %di, scrVarGlob(%esi)\n" /* line 1519 */
        "movzwl 0xc(%ebx), %eax\n" /* line 1520 */
        "movw %ax, 0xc(%ecx)\n"
        "movzwl 4(%ebx), %eax\n" /* line 1521 */
        "movw %ax, 4(%ecx)\n"
        "movl %ebx, %ecx\n"
        "movzwl -0x1a(%ebp), %eax\n"
        ".Lf8ce3e_0008cebe:\n"
        "movw %ax, scrVarGlob+4\n" /* line 1526 */
        "movzwl %ax, %eax\n" /* line 1527 */
        "shll $4, %eax\n"
        "movw $0, scrVarGlob+2(%eax)\n"
        "movw %di, 0xc(%ecx)\n" /* line 1529 */
        "movw %di, 0xe(%ecx)\n" /* line 1530 */
        "movw %di, 2(%ebx)\n" /* line 1531 */
        "movzwl (%ebx), %eax\n" /* line 1615 */
        "movl %eax, %edx\n" /* line 1616 */
        "shll $4, %edx\n"
        "addl $scrVarGlob, %edx\n"
        "movl $0x73, 8(%edx)\n" /* line 1619 */
        "movw $0, 4(%edx)\n" /* line 1620 */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1623 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf8ce3e_0008cf02:\n"
        "movl $str_0021d3d8, (%esp)\n" /* line 1505 */
        "calll Scr_TerminalError\n"
        "jmp .Lf8ce3e_0008ce57\n"
        ".Lf8ce3e_0008cf13:\n"
        "movzwl -0x1a(%ebp), %eax\n"
        "jmp .Lf8ce3e_0008cebe\n"
    );
}

/* line 1645 */
__attribute__((naked))
unsigned int Scr_AllocArray(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1645 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movzwl scrVarGlob+4, %edi\n" /* line 1503 */
        "testw %di, %di\n" /* line 1504 */
        "je .Lf8cf1a_0008cfe4\n"
        ".Lf8cf1a_0008cf33:\n"
        "movzwl %di, %esi\n" /* line 1507 */
        "shll $4, %esi\n"
        "leal scrVarGlob(%esi), %ebx\n"
        "movzwl scrVarGlob(%esi), %eax\n" /* line 1508 */
        "movw %ax, -0x1c(%ebp)\n"
        "movzwl %ax, %eax\n"
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movzwl 4(%ecx), %eax\n" /* line 1511 */
        "movw %ax, -0x1a(%ebp)\n"
        "cmpl %ecx, %ebx\n" /* line 1514 */
        "je .Lf8cf1a_0008cf9a\n"
        "testb $0x60, 8(%ebx)\n"
        "jne .Lf8cf1a_0008cff5\n"
        "movzwl 0xc(%ebx), %edx\n" /* line 1518 */
        "shll $4, %edx\n"
        "movl -0x1c(%ebp), %eax\n"
        "movw %ax, scrVarGlob(%edx)\n"
        "movw %di, scrVarGlob(%esi)\n" /* line 1519 */
        "movzwl 0xc(%ebx), %eax\n" /* line 1520 */
        "movw %ax, 0xc(%ecx)\n"
        "movzwl 4(%ebx), %eax\n" /* line 1521 */
        "movw %ax, 4(%ecx)\n"
        "movl %ebx, %ecx\n"
        "movzwl -0x1a(%ebp), %eax\n"
        ".Lf8cf1a_0008cf9a:\n"
        "movw %ax, scrVarGlob+4\n" /* line 1526 */
        "movzwl %ax, %eax\n" /* line 1527 */
        "shll $4, %eax\n"
        "movw $0, scrVarGlob+2(%eax)\n"
        "movw %di, 0xc(%ecx)\n" /* line 1529 */
        "movw %di, 0xe(%ecx)\n" /* line 1530 */
        "movw %di, 2(%ebx)\n" /* line 1531 */
        "movzwl (%ebx), %eax\n" /* line 1657 */
        "movl %eax, %edx\n" /* line 1658 */
        "shll $4, %edx\n"
        "addl $scrVarGlob, %edx\n"
        "movl $0x76, 8(%edx)\n" /* line 1661 */
        "movw $0, 4(%edx)\n" /* line 1662 */
        "movw $0, 6(%edx)\n" /* line 1663 */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1670 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf8cf1a_0008cfe4:\n"
        "movl $str_0021d3d8, (%esp)\n" /* line 1505 */
        "calll Scr_TerminalError\n"
        "jmp .Lf8cf1a_0008cf33\n"
        ".Lf8cf1a_0008cff5:\n"
        "movzwl -0x1a(%ebp), %eax\n"
        "jmp .Lf8cf1a_0008cf9a\n"
    );
}

/* line 1673 */
__attribute__((naked))
unsigned int AllocThread(unsigned int self)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1673 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movzwl scrVarGlob+4, %edi\n" /* line 1503 */
        "testw %di, %di\n" /* line 1504 */
        "je .Lf8cffc_0008d0c7\n"
        ".Lf8cffc_0008d015:\n"
        "movzwl %di, %esi\n" /* line 1507 */
        "shll $4, %esi\n"
        "leal scrVarGlob(%esi), %ebx\n"
        "movzwl scrVarGlob(%esi), %eax\n" /* line 1508 */
        "movw %ax, -0x1c(%ebp)\n"
        "movzwl %ax, %eax\n"
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movzwl 4(%ecx), %eax\n" /* line 1511 */
        "movw %ax, -0x1a(%ebp)\n"
        "cmpl %ecx, %ebx\n" /* line 1514 */
        "je .Lf8cffc_0008d07c\n"
        "testb $0x60, 8(%ebx)\n"
        "jne .Lf8cffc_0008d0d8\n"
        "movzwl 0xc(%ebx), %edx\n" /* line 1518 */
        "shll $4, %edx\n"
        "movl -0x1c(%ebp), %eax\n"
        "movw %ax, scrVarGlob(%edx)\n"
        "movw %di, scrVarGlob(%esi)\n" /* line 1519 */
        "movzwl 0xc(%ebx), %eax\n" /* line 1520 */
        "movw %ax, 0xc(%ecx)\n"
        "movzwl 4(%ebx), %eax\n" /* line 1521 */
        "movw %ax, 4(%ecx)\n"
        "movl %ebx, %ecx\n"
        "movzwl -0x1a(%ebp), %eax\n"
        ".Lf8cffc_0008d07c:\n"
        "movw %ax, scrVarGlob+4\n" /* line 1526 */
        "movzwl %ax, %eax\n" /* line 1527 */
        "shll $4, %eax\n"
        "movw $0, scrVarGlob+2(%eax)\n"
        "movw %di, 0xc(%ecx)\n" /* line 1529 */
        "movw %di, 0xe(%ecx)\n" /* line 1530 */
        "movw %di, 2(%ebx)\n" /* line 1531 */
        "movzwl (%ebx), %eax\n" /* line 1678 */
        "movl %eax, %edx\n" /* line 1679 */
        "shll $4, %edx\n"
        "addl $scrVarGlob, %edx\n"
        "movl $0x6f, 8(%edx)\n" /* line 1682 */
        "movw $0, 4(%edx)\n" /* line 1683 */
        "movl 8(%ebp), %ecx\n" /* line 1684 | self */
        "movw %cx, 6(%edx)\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1687 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf8cffc_0008d0c7:\n"
        "movl $str_0021d3d8, (%esp)\n" /* line 1505 */
        "calll Scr_TerminalError\n"
        "jmp .Lf8cffc_0008d015\n"
        ".Lf8cffc_0008d0d8:\n"
        "movzwl -0x1a(%ebp), %eax\n"
        "jmp .Lf8cffc_0008d07c\n"
    );
}

/* line 1690 */
__attribute__((naked))
unsigned int AllocChildThread(unsigned int self, unsigned int parentLocalId)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1690 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movzwl scrVarGlob+4, %edi\n" /* line 1503 */
        "testw %di, %di\n" /* line 1504 */
        "je .Lf8d0de_0008d1b4\n"
        ".Lf8d0de_0008d0f7:\n"
        "movzwl %di, %esi\n" /* line 1507 */
        "shll $4, %esi\n"
        "leal scrVarGlob(%esi), %ebx\n"
        "movzwl scrVarGlob(%esi), %eax\n" /* line 1508 */
        "movw %ax, -0x1c(%ebp)\n"
        "movzwl %ax, %eax\n"
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movzwl 4(%ecx), %edx\n" /* line 1511 */
        "movw %dx, -0x1a(%ebp)\n"
        "cmpl %ecx, %ebx\n" /* line 1514 */
        "je .Lf8d0de_0008d1cb\n"
        "testb $0x60, 8(%ebx)\n"
        "jne .Lf8d0de_0008d1c5\n"
        "movzwl 0xc(%ebx), %edx\n" /* line 1518 */
        "shll $4, %edx\n"
        "movl -0x1c(%ebp), %eax\n"
        "movw %ax, scrVarGlob(%edx)\n"
        "movw %di, scrVarGlob(%esi)\n" /* line 1519 */
        "movzwl 0xc(%ebx), %edx\n" /* line 1520 */
        "movw %dx, 0xc(%ecx)\n"
        "movzwl 4(%ebx), %eax\n" /* line 1521 */
        "movw %ax, 4(%ecx)\n"
        "movl %ebx, %ecx\n"
        "movzwl -0x1a(%ebp), %eax\n"
        ".Lf8d0de_0008d162:\n"
        "movw %ax, scrVarGlob+4\n" /* line 1526 */
        "movzwl %ax, %eax\n" /* line 1527 */
        "shll $4, %eax\n"
        "movw $0, scrVarGlob+2(%eax)\n"
        "movw %di, 0xc(%ecx)\n" /* line 1529 */
        "movw %di, 0xe(%ecx)\n" /* line 1530 */
        "movw %di, 2(%ebx)\n" /* line 1531 */
        "movzwl (%ebx), %eax\n" /* line 1695 */
        "movl %eax, %ecx\n" /* line 1696 */
        "shll $4, %ecx\n"
        "addl $scrVarGlob, %ecx\n"
        "shll $8, 0xc(%ebp)\n" /* line 1701 | parentLocalId */
        "orl $0x72, 0xc(%ebp)\n" /* parentLocalId */
        "movl 0xc(%ebp), %edx\n" /* parentLocalId */
        "movl %edx, 8(%ecx)\n"
        "movw $0, 4(%ecx)\n" /* line 1702 */
        "movl 8(%ebp), %edx\n" /* line 1703 | self */
        "movw %dx, 6(%ecx)\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1706 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf8d0de_0008d1b4:\n"
        "movl $str_0021d3d8, (%esp)\n" /* line 1505 */
        "calll Scr_TerminalError\n"
        "jmp .Lf8d0de_0008d0f7\n"
        ".Lf8d0de_0008d1c5:\n"
        "movzwl -0x1a(%ebp), %eax\n"
        "jmp .Lf8d0de_0008d162\n"
        ".Lf8d0de_0008d1cb:\n"
        "movl %edx, %eax\n"
        "jmp .Lf8d0de_0008d162\n"
    );
}

/* line 1148 */
static __attribute__((naked))
JCOEF MakeVariableExternal(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1148 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl $0, -0x28(%ebp)\n" /* value */
        "movl $0, -0x24(%ebp)\n"
        "movl %eax, %esi\n" /* entry */
        /* { scope 1: value */
        "subl $scrVarGlob, %eax\n" /* line 1166 */
        "sarl $4, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movzwl (%esi), %eax\n" /* line 1167 | entry */
        "shll $4, %eax\n"
        "addl $scrVarGlob, %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* entryValue */
        "movl 8(%edx), %eax\n" /* line 1172 */
        "andl $0x1f, %eax\n"
        "cmpl $0x16, %eax\n"
        "je .Lf8d1d0_0008d276\n"
        "movl -0x20(%ebp), %eax\n" /* entryValue */
        "movl 8(%eax), %ebx\n" /* prevSiblingIndex */
        ".Lf8d1d0_0008d213:\n"
        "movl %ebx, %eax\n" /* line 1182 | prevSiblingIndex */
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf8d1d0_0008d2d0\n"
        ".Lf8d1d0_0008d221:\n"
        "movl %esi, %edx\n" /* line 1206 | entry */
        "movl -0x20(%ebp), %eax\n" /* entryValue */
        ".Lf8d1d0_0008d226:\n"
        "movl %edx, %ecx\n" /* line 1219 */
        "movzwl 0xc(%eax), %eax\n" /* line 1221 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movzwl scrVarGlob(%eax), %eax\n" /* line 1222 */
        "shll $4, %eax\n"
        "addl $scrVarGlob, %eax\n"
        "cmpl %edx, %esi\n" /* line 1216 | entry */
        "jne .Lf8d1d0_0008d226\n"
        "movzwl (%ecx), %eax\n" /* line 1225 */
        "shll $4, %eax\n"
        "movl -0x20(%ebp), %ecx\n" /* entryValue */
        "movzwl 0xc(%ecx), %edx\n"
        "movw %dx, scrVarGlob+12(%eax)\n"
        "movl -0x2c(%ebp), %edi\n"
        "movl %ecx, %eax\n"
        ".Lf8d1d0_0008d261:\n"
        "andl $0xffffff9f, %ebx\n" /* line 1231 | prevSiblingIndex */
        "orl $0x60, %ebx\n" /* prevSiblingIndex */
        "movl %ebx, 8(%eax)\n" /* prevSiblingIndex */
        "movw %di, 0xc(%eax)\n" /* line 1232 */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1235 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: value */
        ".Lf8d1d0_0008d276:\n"
        "subw $1, 6(%edx)\n" /* line 1174 */
        "movl -0x20(%ebp), %edx\n" /* line 1177 | entryValue */
        "movl 8(%edx), %ebx\n" /* prevSiblingIndex */
        "movl %ebx, %eax\n" /* prevSiblingIndex */
        "shrl $8, %eax\n"
        /* { scope 2 */
        "cmpl $0xffff, %eax\n" /* line 2159 */
        "ja .Lf8d1d0_0008d390\n"
        "movzwl %ax, %eax\n" /* line 2162 */
        "movl %eax, -0x28(%ebp)\n" /* value */
        "movl $2, %eax\n"
        ".Lf8d1d0_0008d29c:\n"
        "movl %eax, -0x24(%ebp)\n" /* line 2175 */
        /* } scope */
        "cmpl $3, %eax\n" /* line 1946 */
        "jg .Lf8d1d0_0008d3a9\n"
        "cmpl $2, %eax\n"
        "jl .Lf8d1d0_0008d3ef\n"
        "movl -0x28(%ebp), %eax\n" /* line 1953 | value */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movl -0x20(%ebp), %edx\n" /* entryValue */
        "movl 8(%edx), %ebx\n" /* prevSiblingIndex */
        "movl %ebx, %eax\n" /* line 1182 | prevSiblingIndex */
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "jne .Lf8d1d0_0008d221\n"
        ".Lf8d1d0_0008d2d0:\n"
        "movl -0x20(%ebp), %edx\n" /* line 1184 | entryValue */
        "movzwl 0xc(%edx), %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "shll $4, %edx\n" /* line 1185 */
        "movl %edx, -0x30(%ebp)\n"
        "addl $scrVarGlob, %edx\n"
        "movl -0x30(%ebp), %ecx\n" /* line 1186 */
        "movzwl scrVarGlob(%ecx), %eax\n"
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edi\n"
        "cmpl %edx, %esi\n" /* line 1187 | entry */
        "je .Lf8d1d0_0008d40e\n"
        "movl 8(%edi), %eax\n" /* line 1192 */
        "andl $0xffffff9f, %eax\n"
        "orl $0x40, %eax\n"
        "movl %eax, 8(%edi)\n"
        "movzwl 2(%esi), %ebx\n" /* line 1194 | entry, prevSiblingIndex */
        "movl -0x20(%ebp), %eax\n" /* line 1195 | entryValue */
        "movzwl 0xe(%eax), %ecx\n"
        "movzwl 2(%edx), %edx\n" /* line 1196 */
        "movzwl 0xe(%edi), %eax\n" /* line 1199 */
        "shll $4, %eax\n"
        "movl -0x2c(%ebp), %edi\n"
        "movw %di, scrVarGlob+2(%eax)\n"
        "shll $4, %edx\n" /* line 1200 */
        "movzwl scrVarGlob(%edx), %eax\n"
        "shll $4, %eax\n"
        "movw %di, scrVarGlob+14(%eax)\n"
        "movl -0x1c(%ebp), %edi\n" /* line 1201 */
        "shll $4, %ecx\n"
        "movw %di, scrVarGlob+2(%ecx)\n"
        "shll $4, %ebx\n" /* line 1202 | prevSiblingIndex */
        "movzwl scrVarGlob(%ebx), %eax\n" /* prevSiblingIndex */
        "shll $4, %eax\n"
        "movw %di, scrVarGlob+14(%eax)\n"
        "movl (%esi), %edx\n" /* line 1204 | entry */
        "movl -0x30(%ebp), %ecx\n" /* line 1205 */
        "movl scrVarGlob(%ecx), %eax\n"
        "movl %eax, (%esi)\n" /* entry */
        "movl %edx, scrVarGlob(%ecx)\n" /* line 1206 */
        "movl -0x20(%ebp), %eax\n" /* entryValue */
        "movl 8(%eax), %ebx\n" /* prevSiblingIndex */
        "andl $0xffffff9f, %ebx\n" /* line 1231 | prevSiblingIndex */
        "orl $0x60, %ebx\n" /* prevSiblingIndex */
        "movl %ebx, 8(%eax)\n" /* prevSiblingIndex */
        "movw %di, 0xc(%eax)\n" /* line 1232 */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1235 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: value */
        /* { scope 2 */
        ".Lf8d1d0_0008d390:\n"
        "cmpl $0x1fffd, %eax\n" /* line 2164 */
        "ja .Lf8d1d0_0008d3dd\n"
        "subl $0x10000, %eax\n" /* line 2167 */
        "movl %eax, -0x28(%ebp)\n" /* value */
        "movl $1, %eax\n"
        "jmp .Lf8d1d0_0008d29c\n"
        /* } scope */
        ".Lf8d1d0_0008d3a9:\n"
        "cmpl $4, %eax\n" /* line 1946 */
        "jne .Lf8d1d0_0008d213\n"
        "movl -0x28(%ebp), %edx\n" /* line 1956 | value, vectorValue */
        /* { scope 2 */
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf8d1d0_0008d213\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf8d1d0_0008d419\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        "movl -0x20(%ebp), %ecx\n" /* entryValue */
        "movl 8(%ecx), %ebx\n" /* prevSiblingIndex */
        "jmp .Lf8d1d0_0008d213\n"
        /* } scope */
        /* { scope 2 */
        ".Lf8d1d0_0008d3dd:\n"
        "subl $0x00800000, %eax\n" /* line 2172 */
        "movl %eax, -0x28(%ebp)\n" /* value */
        "movl $6, %eax\n"
        "jmp .Lf8d1d0_0008d29c\n"
        /* } scope */
        ".Lf8d1d0_0008d3ef:\n"
        "subl $1, %eax\n" /* line 1946 */
        "jne .Lf8d1d0_0008d213\n"
        "movl -0x28(%ebp), %ecx\n" /* line 1949 | value */
        "movl %ecx, (%esp)\n"
        "calll RemoveRefToObject\n"
        "movl -0x20(%ebp), %edi\n" /* entryValue */
        "movl 8(%edi), %ebx\n" /* prevSiblingIndex */
        "jmp .Lf8d1d0_0008d213\n"
        ".Lf8d1d0_0008d40e:\n"
        "movl -0x2c(%ebp), %edi\n" /* line 1187 */
        "movl -0x20(%ebp), %eax\n" /* entryValue */
        "jmp .Lf8d1d0_0008d261\n"
        /* { scope 2 */
        ".Lf8d1d0_0008d419:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "movl -0x20(%ebp), %edi\n" /* entryValue */
        "movl 8(%edi), %ebx\n" /* prevSiblingIndex */
        "jmp .Lf8d1d0_0008d213\n"
    );
}

/* line 1756 */
__attribute__((naked))
JCOEF RemoveRefToObject(unsigned int id)
{
    __asm__ __volatile__ (
        ".Lf8d434_0008d434:\n"
        "pushl %ebp\n" /* line 1756 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %edx\n" /* line 1763 | id */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* entryValue */
        "movl %eax, %ecx\n" /* line 1768 */
        "movzwl 4(%eax), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf8d434_0008d47c\n"
        "subl $1, %eax\n" /* line 1777 */
        "movw %ax, 4(%ecx)\n"
        "testw %ax, %ax\n" /* line 1780 */
        "jne .Lf8d434_0008d474\n"
        "movl 8(%ecx), %edx\n"
        "movl %edx, %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0x15, %eax\n"
        "je .Lf8d434_0008d6ed\n"
        /* } scope */
        ".Lf8d434_0008d474:\n"
        "addl $0x2c, %esp\n" /* line 1799 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf8d434_0008d47c:\n"
        "movl -0x20(%ebp), %ecx\n" /* line 1796 | entryValue */
        "movzwl 0xe(%ecx), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ebx\n" /* index */
        "cmpl %ebx, 8(%ebp)\n" /* index, id */
        "je .Lf8d434_0008d5ea\n"
        "addw $1, scrVarGlob+4(%edx)\n" /* line 1748 */
        /* { scope 2 */
        "leal scrVarGlob(%eax), %ecx\n" /* line 1249 */
        ".Lf8d434_0008d4a4:\n"
        "movl -0x20(%ebp), %edx\n" /* line 1253 | entryValue */
        "movl %ecx, %eax\n"
        "calll MakeVariableExternal\n"
        "shll $4, %ebx\n" /* line 1254 | nextId */
        "movzwl scrVarGlob+14(%ebx), %eax\n" /* nextId */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movzwl scrVarGlob(%eax), %ebx\n" /* line 1255 | nextId */
        "cmpl %ebx, 8(%ebp)\n" /* line 1251 | nextId, id */
        "jne .Lf8d434_0008d4a4\n"
        "movl -0x20(%ebp), %edx\n" /* line 1258 | entryValue */
        "movzwl 0xe(%edx), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %eax\n"
        "cmpl %eax, 8(%ebp)\n" /* line 1259 | id */
        "jne .Lf8d434_0008d570\n"
        "jmp .Lf8d434_0008d5d3\n"
        /* { scope 3 */
        /* { scope 4 */
        ".Lf8d434_0008d4ec:\n"
        "cmpl $2, %eax\n" /* line 1946 */
        "jl .Lf8d434_0008d661\n"
        "movl %edx, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        /* } scope */
        /* { scope 4 */
        /* { scope 5 */
        ".Lf8d434_0008d4fd:\n"
        "movzwl 0xc(%edi), %ebx\n" /* line 1578 | index */
        "movzwl %bx, %ecx\n" /* line 1579 | index */
        "shll $4, %ecx\n"
        "addl $scrVarGlob, %ecx\n"
        "movzwl 2(%ecx), %edx\n" /* line 1581 */
        "movzwl 0xe(%edi), %esi\n" /* line 1582 | nextSiblingIndex */
        "movzwl %si, %eax\n" /* line 1583 | nextSiblingIndex */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+2(%eax)\n"
        "shll $4, %edx\n" /* line 1584 */
        "movzwl scrVarGlob(%edx), %eax\n"
        "shll $4, %eax\n"
        "movw %si, scrVarGlob+14(%eax)\n" /* nextSiblingIndex */
        "movl $0, 8(%edi)\n" /* line 1586 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1587 */
        "movw %ax, 4(%edi)\n"
        "movw $0, 2(%ecx)\n" /* line 1588 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1590 */
        "shll $4, %eax\n"
        "movw %bx, scrVarGlob+2(%eax)\n" /* index */
        "movw %bx, scrVarGlob+4\n" /* line 1591 | index */
        /* } scope */
        /* } scope */
        /* } scope */
        "movl -0x1c(%ebp), %ecx\n" /* line 1259 */
        "cmpl %ecx, 8(%ebp)\n" /* id */
        "je .Lf8d434_0008d5d0\n"
        "movl %ecx, %eax\n"
        ".Lf8d434_0008d570:\n"
        "movl %eax, %edx\n" /* line 1262 */
        "shll $4, %edx\n"
        "movzwl scrVarGlob+14(%edx), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        /* { scope 3 */
        "leal scrVarGlob(%edx), %edi\n" /* line 1721 | entryValue */
        "movl 4(%edi), %edx\n" /* line 1727 | entryValue */
        "movl 8(%edi), %eax\n" /* entryValue, type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 4 */
        "cmpl $3, %eax\n" /* line 1946 */
        "jle .Lf8d434_0008d4ec\n"
        "cmpl $4, %eax\n"
        "jne .Lf8d434_0008d4fd\n"
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf8d434_0008d4fd\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf8d434_0008d73e\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        "jmp .Lf8d434_0008d4fd\n"
        ".Lf8d434_0008d5d0:\n"
        "movl -0x20(%ebp), %edx\n" /* entryValue */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf8d434_0008d5d3:\n"
        "movzwl 4(%edx), %eax\n" /* line 1812 */
        "testw %ax, %ax\n"
        "je .Lf8d434_0008d677\n"
        "subl $1, %eax\n" /* line 1821 */
        "movw %ax, 4(%edx)\n"
        "movl -0x20(%ebp), %ecx\n" /* entryValue */
        /* { scope 2 */
        ".Lf8d434_0008d5ea:\n"
        "movzwl 0xc(%ecx), %ebx\n" /* line 1578 | index */
        "movzwl %bx, %ecx\n" /* line 1579 | index */
        "shll $4, %ecx\n"
        "addl $scrVarGlob, %ecx\n"
        "movzwl 2(%ecx), %edx\n" /* line 1581 */
        "movl -0x20(%ebp), %eax\n" /* line 1582 | entryValue */
        "movzwl 0xe(%eax), %esi\n" /* nextSiblingIndex */
        "movzwl %si, %eax\n" /* line 1583 | nextSiblingIndex */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+2(%eax)\n"
        "shll $4, %edx\n" /* line 1584 */
        "movzwl scrVarGlob(%edx), %eax\n"
        "shll $4, %eax\n"
        "movw %si, scrVarGlob+14(%eax)\n" /* nextSiblingIndex */
        "movl -0x20(%ebp), %edx\n" /* line 1586 | entryValue */
        "movl $0, 8(%edx)\n"
        "movzwl scrVarGlob+4, %eax\n" /* line 1587 */
        "movw %ax, 4(%edx)\n"
        "movw $0, 2(%ecx)\n" /* line 1588 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1590 */
        "shll $4, %eax\n"
        "movw %bx, scrVarGlob+2(%eax)\n" /* index */
        "movw %bx, scrVarGlob+4\n" /* line 1591 | index */
        /* } scope */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1799 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf8d434_0008d661:\n"
        "subl $1, %eax\n" /* line 1946 */
        "jne .Lf8d434_0008d4fd\n"
        "movl %edx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "jmp .Lf8d434_0008d4fd\n"
        ".Lf8d434_0008d677:\n"
        "movl %edx, %eax\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        "movzwl 0xc(%edx), %ebx\n" /* line 1578 | index */
        "movzwl %bx, %ecx\n" /* line 1579 | index */
        "shll $4, %ecx\n"
        "addl $scrVarGlob, %ecx\n"
        "movzwl 2(%ecx), %edx\n" /* line 1581 */
        "movzwl 0xe(%eax), %esi\n" /* line 1582 | nextSiblingIndex */
        "movzwl %si, %eax\n" /* line 1583 | nextSiblingIndex */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+2(%eax)\n"
        "shll $4, %edx\n" /* line 1584 */
        "movzwl scrVarGlob(%edx), %eax\n"
        "shll $4, %eax\n"
        "movw %si, scrVarGlob+14(%eax)\n" /* nextSiblingIndex */
        "movl -0x20(%ebp), %edx\n" /* line 1586 | entryValue */
        "movl $0, 8(%edx)\n"
        "movzwl scrVarGlob+4, %eax\n" /* line 1587 */
        "movw %ax, 4(%edx)\n"
        "movw $0, 2(%ecx)\n" /* line 1588 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1590 */
        "shll $4, %eax\n"
        "movw %bx, scrVarGlob+2(%eax)\n" /* index */
        "movw %bx, scrVarGlob+4\n" /* line 1591 | index */
        "movl -0x20(%ebp), %ecx\n" /* entryValue */
        "jmp .Lf8d434_0008d5ea\n"
        /* } scope */
        ".Lf8d434_0008d6ed:\n"
        "movzwl 0xe(%ecx), %eax\n" /* line 1780 */
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %eax\n"
        "cmpl %eax, 8(%ebp)\n" /* id */
        "jne .Lf8d434_0008d474\n"
        "movl %edx, %eax\n" /* line 1783 */
        "andl $0xffffffe0, %eax\n"
        "orl $0x14, %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movzwl 6(%ecx), %edx\n" /* line 2318 */
        "addl $0x00800000, %edx\n"
        "andl $0x00FFFFFF, %edx\n"
        "movl %edx, 4(%esp)\n"
        "shrl $8, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movzwl g_classMap+2(, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveVariable\n"
        "jmp .Lf8d434_0008d474\n"
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf8d434_0008d73e:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "jmp .Lf8d434_0008d4fd\n"
    );
}

/* line 4552 */
JCOEF Scr_FreeValue(unsigned int id)
{
    RemoveRefToObject(id);
}

/* line 3882 */
__attribute__((naked))
JCOEF Scr_EvalArray(VariableValue *value, VariableValue *index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3882 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl $0, -0x48(%ebp)\n" /* value */
        "movl $0, -0x44(%ebp)\n"
        "movl 8(%ebp), %esi\n" /* value */
        "movl 0xc(%ebp), %ebx\n" /* index */
        "movl 4(%esi), %eax\n" /* line 3888 | value */
        "cmpl $2, %eax\n"
        "je .Lf8d760_0008d7c7\n"
        "cmpl $4, %eax\n"
        "je .Lf8d760_0008d7fa\n"
        "subl $1, %eax\n"
        "je .Lf8d760_0008d82d\n"
        "movl $1, scrVarPub+20\n" /* line 3955 */
        "movl 4(%esi), %eax\n" /* line 3956 | value */
        "movl var_typename(, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021d574, (%esp)\n" /* "%s is not an array, string, or vector" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        ".Lf8d760_0008d7bf:\n"
        "addl $0x4c, %esp\n" /* line 3957 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf8d760_0008d7c7:\n"
        "movl 4(%ebx), %eax\n" /* line 3891 | index */
        "cmpl $6, %eax\n"
        "je .Lf8d760_0008d874\n"
        "movl var_typename(, %eax, 4), %eax\n" /* line 3914 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021d508, (%esp)\n" /* "%s is not a string index" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "addl $0x4c, %esp\n" /* line 3957 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf8d760_0008d7fa:\n"
        "movl 4(%ebx), %eax\n" /* line 3918 | index */
        "cmpl $6, %eax\n"
        "je .Lf8d760_0008d8c1\n"
        "movl var_typename(, %eax, 4), %eax\n" /* line 3932 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021d544, (%esp)\n" /* "%s is not a vector index" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "addl $0x4c, %esp\n" /* line 3957 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf8d760_0008d82d:\n"
        "movl (%esi), %edx\n" /* line 3936 | value */
        "movl %edx, %edi\n" /* line 3941 | entryValue */
        "shll $4, %edi\n" /* entryValue */
        "movl scrVarGlob+8(%edi), %eax\n" /* entryValue */
        "andl $0x1f, %eax\n"
        "cmpl $0x16, %eax\n"
        "je .Lf8d760_0008d902\n"
        "movl $1, scrVarPub+20\n" /* line 3943 */
        "movl var_typename(, %eax, 4), %eax\n" /* line 3944 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021d560, (%esp)\n" /* "%s is not an array" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "jmp .Lf8d760_0008d7bf\n"
        ".Lf8d760_0008d874:\n"
        "movl (%ebx), %ecx\n" /* line 3893 | index */
        "testl %ecx, %ecx\n"
        "js .Lf8d760_0008d89f\n"
        /* { scope 1: value, entry, entry */
        "movl (%esi), %eax\n" /* line 3898 | value */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, %edx\n"
        "cld\n" /* line 3899 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %edx, %edi\n" /* entryValue */
        "repne scasb %es:(%edi), %al\n" /* entryValue */
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "cmpl %ecx, (%ebx)\n" /* index */
        "jb .Lf8d760_0008da72\n"
        /* } scope */
        ".Lf8d760_0008d89f:\n"
        "movl (%ebx), %eax\n" /* line 3910 | index */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021d4e8, (%esp)\n" /* "string index %d out of range" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "addl $0x4c, %esp\n" /* line 3957 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf8d760_0008d8c1:\n"
        "movl (%ebx), %edx\n" /* line 3920 | index */
        "cmpl $2, %edx\n"
        "ja .Lf8d760_0008daba\n"
        "movl $5, 4(%ebx)\n" /* line 3922 | index */
        "movl (%esi), %eax\n" /* line 3923 | value */
        "movl (%eax, %edx, 4), %eax\n"
        "movl %eax, (%ebx)\n" /* index */
        "movl (%esi), %edx\n" /* line 3924 | value, vectorValue */
        /* { scope 1: value, entry, entry */
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf8d760_0008d7bf\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf8d760_0008dba7\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        "jmp .Lf8d760_0008d7bf\n"
        /* } scope */
        ".Lf8d760_0008d902:\n"
        "movl 4(%ebx), %eax\n" /* line 3853 */
        "cmpl $6, %eax\n"
        "je .Lf8d760_0008dad7\n"
        "cmpl $2, %eax\n" /* line 3862 */
        "je .Lf8d760_0008d991\n"
        "movl var_typename(, %eax, 4), %eax\n" /* line 3869 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021d4b4, (%esp)\n" /* "%s is not an array index" */
        ".Lf8d760_0008d925:\n"
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "addw $1, scrVarGlob+4(%edi)\n" /* line 1748 | entryValue */
        "xorl %edi, %edi\n" /* entryValue */
        /* { scope 1: value, entry, entry */
        /* { scope 2 */
        ".Lf8d760_0008d93c:\n"
        "shll $4, %edi\n" /* line 2517 | entryValue */
        "leal scrVarGlob(%edi), %eax\n" /* entryValue */
        "movl 8(%eax), %edi\n" /* line 2520 | entryValue */
        "andl $0x1f, %edi\n" /* entryValue */
        "movl 4(%eax), %eax\n" /* line 2521 */
        "movl %eax, -0x2c(%ebp)\n"
        "cmpl $3, %edi\n" /* line 1928 | entryValue */
        "jg .Lf8d760_0008da4b\n"
        "cmpl $2, %edi\n" /* entryValue */
        "jl .Lf8d760_0008dbbc\n"
        "movl -0x2c(%ebp), %edx\n" /* line 1935 */
        "movl %edx, (%esp)\n"
        "calll SL_AddRefToString\n"
        "movl -0x2c(%ebp), %edx\n"
        ".Lf8d760_0008d971:\n"
        "movl %edx, -0x48(%ebp)\n" /* line 2525 | value */
        "movl %edi, -0x44(%ebp)\n" /* entryValue */
        /* } scope */
        /* } scope */
        "movl -0x48(%ebp), %eax\n" /* line 3948 | value */
        "movl -0x44(%ebp), %edx\n"
        "movl %eax, (%ebx)\n" /* index */
        "movl %edx, 4(%ebx)\n" /* index */
        "movl (%esi), %eax\n" /* line 3949 | value */
        "movl %eax, (%esp)\n"
        "calll RemoveRefToObject\n"
        "jmp .Lf8d760_0008d7bf\n"
        ".Lf8d760_0008d991:\n"
        "movl (%ebx), %eax\n" /* line 3864 */
        "movl %eax, -0x34(%ebp)\n" /* name */
        "leal (%edx, %eax), %ecx\n" /* line 801 | index */
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n" /* index */
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n" /* index */
        "addl $1, %ecx\n" /* index */
        "movzwl %cx, %ecx\n" /* index */
        /* { scope 1: value, entry, entry */
        /* { scope 2 */
        "movl %ecx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl %edx, -0x30(%ebp)\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edi\n" /* entryValue */
        "movl 8(%edi), %edx\n" /* line 748 | entryValue */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf8d760_0008d9fe\n"
        ".Lf8d760_0008d9e2:\n"
        "xorl %ecx, %ecx\n" /* line 759 */
        /* } scope */
        /* } scope */
        ".Lf8d760_0008d9e4:\n"
        "shll $4, %ecx\n" /* line 1992 */
        "movzwl scrVarGlob(%ecx), %edi\n" /* entryValue */
        "movl -0x34(%ebp), %eax\n" /* line 3865 | name */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "jmp .Lf8d760_0008d93c\n"
        /* { scope 1: value, entry, entry */
        /* { scope 2 */
        ".Lf8d760_0008d9fe:\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, -0x34(%ebp)\n" /* name */
        "je .Lf8d760_0008d9e4\n"
        "movzwl 0xc(%edi), %ecx\n" /* line 757 | entryValue */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x30(%ebp)\n" /* line 759 | entry */
        "je .Lf8d760_0008d9e2\n"
        ".Lf8d760_0008da1a:\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl -0x34(%ebp), %eax\n" /* name */
        "je .Lf8d760_0008d9e4\n"
        "movzwl 0xc(%edx), %ecx\n" /* line 771 */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x30(%ebp)\n" /* line 759 | entry */
        "jne .Lf8d760_0008da1a\n"
        "jmp .Lf8d760_0008d9e2\n"
        /* } scope */
        /* } scope */
        /* { scope 1: value, entry, entry */
        /* { scope 2 */
        ".Lf8d760_0008da4b:\n"
        "cmpl $4, %edi\n" /* line 1928 | entryValue */
        "je .Lf8d760_0008da58\n"
        ".Lf8d760_0008da50:\n"
        "movl -0x2c(%ebp), %edx\n"
        "jmp .Lf8d760_0008d971\n"
        ".Lf8d760_0008da58:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 1879 */
        "cmpb $0, -1(%eax)\n"
        "jne .Lf8d760_0008dbeb\n"
        "addw $1, -4(%eax)\n" /* line 1894 */
        "movl -0x2c(%ebp), %edx\n"
        "jmp .Lf8d760_0008d971\n"
        /* } scope */
        /* } scope */
        /* { scope 1: value, entry, entry */
        ".Lf8d760_0008da72:\n"
        "movl $2, 4(%ebx)\n" /* line 3901 | index */
        "movl (%ebx), %eax\n" /* line 3902 | index */
        "movzbl (%edx, %eax), %eax\n"
        "movb %al, -0x1a(%ebp)\n" /* c */
        "movb $0, -0x19(%ebp)\n" /* line 3903 */
        "movl $0xe, 0xc(%esp)\n" /* line 3904 */
        "movl $2, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0x1a(%ebp), %eax\n" /* c */
        "movl %eax, (%esp)\n"
        "calll SL_GetStringOfLen\n"
        "movl %eax, (%ebx)\n" /* index */
        "movl (%esi), %eax\n" /* line 3905 | value */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "jmp .Lf8d760_0008d7bf\n"
        /* } scope */
        ".Lf8d760_0008daba:\n"
        "movl %edx, 4(%esp)\n" /* line 3928 */
        "movl $str_0021d524, (%esp)\n" /* "vector index %d out of range" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "jmp .Lf8d760_0008d7bf\n"
        ".Lf8d760_0008dad7:\n"
        "movl (%ebx), %ecx\n" /* line 3855 */
        "leal vq8+462882(%ecx), %eax\n"
        "cmpl $pushed+2177, %eax\n"
        "ja .Lf8d760_0008dbdb\n"
        "addl $0x00800000, %ecx\n" /* line 1980 */
        "movl %ecx, -0x3c(%ebp)\n" /* name */
        "andl $0x00FFFFFF, -0x3c(%ebp)\n" /* name */
        "movl -0x3c(%ebp), %eax\n" /* line 801 | name */
        "leal (%edx, %eax), %ecx\n" /* index */
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n" /* index */
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n" /* index */
        "addl $1, %ecx\n" /* index */
        "movzwl %cx, %ecx\n" /* index */
        /* { scope 1: value, entry, entry */
        /* { scope 2 */
        "movl %ecx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl %edx, -0x38(%ebp)\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edi\n" /* entryValue */
        "movl 8(%edi), %edx\n" /* line 748 | entryValue */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf8d760_0008db5a\n"
        ".Lf8d760_0008db49:\n"
        "xorl %ecx, %ecx\n" /* line 759 */
        /* } scope */
        /* } scope */
        ".Lf8d760_0008db4b:\n"
        "shll $4, %ecx\n" /* line 1986 */
        "movzwl scrVarGlob(%ecx), %edi\n" /* entryValue */
        "jmp .Lf8d760_0008d93c\n"
        /* { scope 1: value, entry, entry */
        /* { scope 2 */
        ".Lf8d760_0008db5a:\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, -0x3c(%ebp)\n" /* name */
        "je .Lf8d760_0008db4b\n"
        "movzwl 0xc(%edi), %ecx\n" /* line 757 | entryValue */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x38(%ebp)\n" /* line 759 | entry */
        "je .Lf8d760_0008db49\n"
        ".Lf8d760_0008db76:\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl -0x3c(%ebp), %eax\n" /* name */
        "je .Lf8d760_0008db4b\n"
        "movzwl 0xc(%edx), %ecx\n" /* line 771 */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x38(%ebp)\n" /* line 759 | entry */
        "jne .Lf8d760_0008db76\n"
        "jmp .Lf8d760_0008db49\n"
        /* } scope */
        /* } scope */
        /* { scope 1: value, entry, entry */
        ".Lf8d760_0008dba7:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "jmp .Lf8d760_0008d7bf\n"
        /* } scope */
        /* { scope 1: value, entry, entry */
        /* { scope 2 */
        ".Lf8d760_0008dbbc:\n"
        "cmpl $1, %edi\n" /* line 1928 | entryValue */
        "jne .Lf8d760_0008da50\n"
        "movl -0x2c(%ebp), %eax\n" /* line 1748 */
        "shll $4, %eax\n"
        "addw $1, scrVarGlob+4(%eax)\n"
        "movl -0x2c(%ebp), %edx\n"
        "jmp .Lf8d760_0008d971\n"
        /* } scope */
        /* } scope */
        ".Lf8d760_0008dbdb:\n"
        "movl %ecx, 4(%esp)\n" /* line 3857 */
        "movl $str_0021d498, (%esp)\n" /* "array index %d out of range" */
        "jmp .Lf8d760_0008d925\n"
        ".Lf8d760_0008dbeb:\n"
        "movl %eax, %edx\n"
        "jmp .Lf8d760_0008d971\n"
    );
}

/* line 3702 */
__attribute__((naked))
JCOEF Scr_RemoveClassMap(int classnum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3702 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "cmpb $0, scrVarPub+56\n" /* line 3704 */
        "je .Lf8dbf2_0008dc3b\n"
        "movl 8(%ebp), %eax\n" /* line 3710 | classnum */
        "leal (%eax, %eax, 2), %ebx\n"
        "shll $2, %ebx\n"
        "movzwl g_classMap+2(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RemoveRefToObject\n"
        "movw $0, g_classMap+2(%ebx)\n" /* line 3711 */
        "movzwl g_classMap(%ebx), %eax\n" /* line 3716 */
        "movl %eax, (%esp)\n"
        "calll RemoveRefToObject\n"
        "movw $0, g_classMap(%ebx)\n" /* line 3717 */
        ".Lf8dbf2_0008dc3b:\n"
        "addl $0x14, %esp\n" /* line 3718 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2555 */
static __attribute__((naked))
VariableValue Scr_EvalVariableEntityField(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2555 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "shll $4, %eax\n" /* line 2563 | entId */
        "addl $scrVarGlob, %eax\n" /* entId */
        "movl %eax, -0x28(%ebp)\n" /* entId, entValue */
        "movl 8(%eax), %edi\n" /* line 2566 | entId */
        "shrl $8, %edi\n"
        "leal s_debugFrameGlob+57728(%edx), %esi\n" /* line 1980 | name */
        "andl $0x00FFFFFF, %esi\n" /* name */
        "leal (%edi, %edi, 2), %eax\n" /* line 801 */
        "movzwl g_classMap(, %eax, 4), %ecx\n" /* index */
        "addl %esi, %ecx\n" /* name, index */
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n" /* index */
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n" /* index */
        "addl $1, %ecx\n" /* index */
        "movzwl %cx, %ecx\n" /* index */
        /* { scope 2: entry */
        /* { scope 3 */
        "movl %ecx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl %edx, -0x24(%ebp)\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ebx\n" /* entryValue */
        "movl 8(%ebx), %edx\n" /* line 748 | entryValue */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf8dc42_0008dce0\n"
        ".Lf8dc42_0008dcbe:\n"
        "xorl %ecx, %ecx\n" /* line 759 */
        /* } scope */
        /* } scope */
        ".Lf8dc42_0008dcc0:\n"
        "shll $4, %ecx\n" /* line 1986 */
        "movzwl scrVarGlob(%ecx), %eax\n"
        "movzwl %ax, %edx\n"
        "testw %ax, %ax\n" /* line 2567 | entId */
        "jne .Lf8dc42_0008dd2b\n"
        "xorl %esi, %esi\n" /* line 2588 | name */
        /* } scope */
        ".Lf8dc42_0008dcd4:\n"
        "movl %ebx, %eax\n" /* line 2589 | value, entId */
        "movl %esi, %edx\n" /* name */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: entry */
        /* { scope 3 */
        ".Lf8dc42_0008dce0:\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, %esi\n"
        "je .Lf8dc42_0008dcc0\n"
        "movzwl 0xc(%ebx), %ecx\n" /* line 757 | entryValue */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x24(%ebp)\n" /* line 759 | entry */
        "je .Lf8dc42_0008dcbe\n"
        ".Lf8dc42_0008dcfb:\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, %esi\n"
        "je .Lf8dc42_0008dcc0\n"
        "movzwl 0xc(%edx), %ecx\n" /* line 771 */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x24(%ebp)\n" /* line 759 | entry */
        "jne .Lf8dc42_0008dcfb\n"
        "jmp .Lf8dc42_0008dcbe\n"
        /* } scope */
        /* } scope */
        ".Lf8dc42_0008dd2b:\n"
        "shll $4, %edx\n" /* line 2569 */
        "movl scrVarGlob+4(%edx), %eax\n" /* entId */
        "movl %eax, 8(%esp)\n" /* entId */
        "movl -0x28(%ebp), %edx\n" /* entValue */
        "movzwl 6(%edx), %eax\n" /* entId */
        "movl %eax, 4(%esp)\n" /* entId */
        "movl %edi, (%esp)\n"
        "calll GetEntityFieldValue\n"
        "movl %eax, %ebx\n" /* entId, value */
        "movl %edx, %esi\n" /* name */
        "cmpl $1, %edx\n" /* line 2570 */
        "jne .Lf8dc42_0008dcd4\n"
        "movl %eax, -0x2c(%ebp)\n" /* line 2572 | entId */
        "shll $4, %eax\n" /* entId */
        "leal scrVarGlob(%eax), %edx\n" /* entId */
        "movl 8(%edx), %eax\n" /* line 2573 | entId */
        "andl $0x1f, %eax\n" /* entId */
        "cmpl $0x16, %eax\n" /* entId */
        "jne .Lf8dc42_0008dcd4\n"
        "cmpw $0, 4(%edx)\n" /* line 2576 */
        "jne .Lf8dc42_0008dd80\n"
        "movl $1, %esi\n" /* line 2584 | name */
        "jmp .Lf8dc42_0008dcd4\n"
        ".Lf8dc42_0008dd80:\n"
        "movl %ebx, (%esp)\n" /* line 2579 | value */
        "calll RemoveRefToObject\n"
        "movzwl scrVarGlob+4, %eax\n" /* line 1503 */
        "movw %ax, -0x1c(%ebp)\n"
        "testw %ax, %ax\n" /* line 1504 */
        "je .Lf8dc42_0008de72\n"
        ".Lf8dc42_0008dd9c:\n"
        "movzwl -0x1c(%ebp), %edx\n" /* line 1507 */
        "shll $4, %edx\n"
        "movl %edx, -0x30(%ebp)\n"
        "movl %edx, %edi\n"
        "addl $scrVarGlob, %edi\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 1508 */
        "movw %ax, -0x1e(%ebp)\n"
        "movzwl %ax, %eax\n"
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movzwl 4(%ecx), %edx\n" /* line 1511 */
        "movw %dx, -0x1a(%ebp)\n"
        "cmpl %ecx, %edi\n" /* line 1514 */
        "je .Lf8dc42_0008de83\n"
        "testb $0x60, 8(%edi)\n"
        "jne .Lf8dc42_0008de6c\n"
        "movzwl 0xc(%edi), %edx\n" /* line 1518 */
        "shll $4, %edx\n"
        "movzwl -0x1e(%ebp), %eax\n"
        "movw %ax, scrVarGlob(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1519 */
        "movl -0x30(%ebp), %edx\n"
        "movw %ax, scrVarGlob(%edx)\n"
        "movzwl 0xc(%edi), %edx\n" /* line 1520 */
        "movw %dx, 0xc(%ecx)\n"
        "movzwl 4(%edi), %eax\n" /* line 1521 */
        "movw %ax, 4(%ecx)\n"
        "movl %edi, %ecx\n"
        "movzwl -0x1a(%ebp), %eax\n"
        ".Lf8dc42_0008de14:\n"
        "movw %ax, scrVarGlob+4\n" /* line 1526 */
        "movzwl %ax, %eax\n" /* line 1527 */
        "shll $4, %eax\n"
        "movw $0, scrVarGlob+2(%eax)\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1529 */
        "movw %dx, 0xc(%ecx)\n"
        "movw %dx, 0xe(%ecx)\n" /* line 1530 */
        "movw %dx, 2(%edi)\n" /* line 1531 */
        "movzwl (%edi), %edx\n" /* line 1657 */
        "movl %edx, %eax\n" /* line 1658 */
        "shll $4, %eax\n"
        "addl $scrVarGlob, %eax\n"
        "movl $0x76, 8(%eax)\n" /* line 1661 */
        "movw $0, 4(%eax)\n" /* line 1662 */
        "movw $0, 6(%eax)\n" /* line 1663 */
        "movl %edx, %ebx\n" /* line 2580 | value */
        "movl -0x2c(%ebp), %eax\n" /* line 2581 | entId */
        "calll CopyArray\n"
        "movl $1, %esi\n" /* line 2584 | name */
        "jmp .Lf8dc42_0008dcd4\n"
        ".Lf8dc42_0008de6c:\n"
        "movzwl -0x1a(%ebp), %eax\n" /* entId */
        "jmp .Lf8dc42_0008de14\n"
        ".Lf8dc42_0008de72:\n"
        "movl $str_0021d3d8, (%esp)\n" /* line 1505 */
        "calll Scr_TerminalError\n"
        "jmp .Lf8dc42_0008dd9c\n"
        ".Lf8dc42_0008de83:\n"
        "movl %edx, %eax\n"
        "jmp .Lf8dc42_0008de14\n"
    );
}

/* line 2592 */
__attribute__((naked))
VariableValue Scr_EvalVariableField(unsigned int id)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2592 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* id */
        "cmpl $0xfffe, %eax\n" /* line 2594 */
        "je .Lf8de88_0008def0\n"
        /* { scope 1 */
        "shll $4, %eax\n" /* line 2517 */
        "addl $scrVarGlob, %eax\n"
        "movl 8(%eax), %edi\n" /* line 2520 */
        "andl $0x1f, %edi\n"
        "movl 4(%eax), %eax\n" /* line 2521 */
        "movl %eax, -0x1c(%ebp)\n"
        "cmpl $3, %edi\n" /* line 1928 */
        "jg .Lf8de88_0008ded3\n"
        "cmpl $2, %edi\n"
        "jl .Lf8de88_0008df08\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1935 */
        "movl %eax, (%esp)\n"
        "calll SL_AddRefToString\n"
        "movl -0x1c(%ebp), %ebx\n"
        /* } scope */
        ".Lf8de88_0008dec7:\n"
        "movl %ebx, %eax\n" /* line 2594 | value */
        "movl %edi, %edx\n"
        "addl $0x2c, %esp\n" /* line 2595 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf8de88_0008ded3:\n"
        "cmpl $4, %edi\n" /* line 1928 */
        "je .Lf8de88_0008dedd\n"
        ".Lf8de88_0008ded8:\n"
        "movl -0x1c(%ebp), %ebx\n"
        "jmp .Lf8de88_0008dec7\n"
        ".Lf8de88_0008dedd:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1879 */
        "cmpb $0, -1(%eax)\n"
        "jne .Lf8de88_0008df20\n"
        "addw $1, -4(%eax)\n" /* line 1894 */
        "movl -0x1c(%ebp), %ebx\n"
        "jmp .Lf8de88_0008dec7\n"
        /* } scope */
        ".Lf8de88_0008def0:\n"
        "movl scrVarPub+68, %edx\n" /* line 2594 */
        "movl scrVarPub+64, %eax\n"
        "calll Scr_EvalVariableEntityField\n"
        "addl $0x2c, %esp\n" /* line 2595 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf8de88_0008df08:\n"
        "cmpl $1, %edi\n" /* line 1928 */
        "jne .Lf8de88_0008ded8\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1748 */
        "shll $4, %eax\n"
        "addw $1, scrVarGlob+4(%eax)\n"
        "movl -0x1c(%ebp), %ebx\n"
        "jmp .Lf8de88_0008dec7\n"
        ".Lf8de88_0008df20:\n"
        "movl %eax, %ebx\n"
        "jmp .Lf8de88_0008dec7\n"
    );
}

/* line 2050 */
__attribute__((naked))
VariableValue Scr_FindVariableField(unsigned int parentId, unsigned int name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2050 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl $0, -0x28(%ebp)\n" /* value */
        "movl $0, -0x24(%ebp)\n"
        "movl $0, -0x30(%ebp)\n" /* value */
        "movl $0, -0x2c(%ebp)\n"
        "movl 8(%ebp), %edi\n" /* parentId */
        "movl 0xc(%ebp), %esi\n" /* name */
        /* { scope 1: value */
        "leal (%edi, %esi), %ecx\n" /* line 801 | index */
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n" /* index */
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n" /* index */
        "addl $1, %ecx\n" /* index */
        "movzwl %cx, %ecx\n" /* index */
        /* { scope 2: entry */
        /* { scope 3 */
        "movl %ecx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ebx\n" /* entryValue */
        "movl 8(%ebx), %edx\n" /* line 748 | entryValue */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf8df24_0008e013\n"
        ".Lf8df24_0008df9b:\n"
        "xorl %ecx, %ecx\n" /* line 759 */
        /* } scope */
        /* } scope */
        ".Lf8df24_0008df9d:\n"
        "shll $4, %ecx\n" /* line 1992 */
        "movzwl scrVarGlob(%ecx), %eax\n"
        "movzwl %ax, %edx\n"
        "testw %ax, %ax\n" /* line 2060 */
        "je .Lf8df24_0008dfe7\n"
        /* { scope 2: entry */
        "shll $4, %edx\n" /* line 2517 */
        "leal scrVarGlob(%edx), %eax\n"
        "movl 8(%eax), %ebx\n" /* line 2520 | entryValue */
        "andl $0x1f, %ebx\n" /* entryValue */
        "movl 4(%eax), %esi\n" /* line 2521 | name */
        "cmpl $3, %ebx\n" /* line 1928 | entryValue */
        "jle .Lf8df24_0008e069\n"
        "cmpl $4, %ebx\n" /* entryValue */
        "je .Lf8df24_0008e095\n"
        ".Lf8df24_0008dfd3:\n"
        "movl %esi, -0x30(%ebp)\n" /* line 2525 | name, value */
        "movl %ebx, -0x2c(%ebp)\n" /* entryValue */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 2061 | value */
        "movl -0x2c(%ebp), %edx\n"
        /* } scope */
        ".Lf8df24_0008dfdf:\n"
        "addl $0x3c, %esp\n" /* line 2071 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: value */
        ".Lf8df24_0008dfe7:\n"
        "movl %edi, %eax\n" /* line 2064 | parentId */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0x15, %eax\n"
        "je .Lf8df24_0008e087\n"
        "movl $0, -0x24(%ebp)\n" /* line 2067 */
        "movl -0x28(%ebp), %eax\n" /* value */
        "movl -0x24(%ebp), %edx\n"
        /* } scope */
        ".Lf8df24_0008e00b:\n"
        "addl $0x3c, %esp\n" /* line 2071 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: value */
        /* { scope 2: entry */
        /* { scope 3 */
        ".Lf8df24_0008e013:\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, %esi\n"
        "je .Lf8df24_0008df9d\n"
        "movzwl 0xc(%ebx), %ecx\n" /* line 757 | entryValue */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x1c(%ebp)\n" /* line 759 | entry */
        "je .Lf8df24_0008df9b\n"
        ".Lf8df24_0008e032:\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, %esi\n"
        "je .Lf8df24_0008df9d\n"
        "movzwl 0xc(%edx), %ecx\n" /* line 771 */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x1c(%ebp)\n" /* line 759 | entry */
        "jne .Lf8df24_0008e032\n"
        "jmp .Lf8df24_0008df9b\n"
        /* } scope */
        /* } scope */
        /* { scope 2: entry */
        ".Lf8df24_0008e069:\n"
        "cmpl $2, %ebx\n" /* line 1928 | entryValue */
        "jl .Lf8df24_0008e0a9\n"
        "movl %esi, (%esp)\n" /* line 1935 */
        "calll SL_AddRefToString\n"
        "movl %esi, -0x30(%ebp)\n" /* line 2525 | name, value */
        "movl %ebx, -0x2c(%ebp)\n" /* entryValue */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 2061 | value */
        "movl -0x2c(%ebp), %edx\n"
        "jmp .Lf8df24_0008dfdf\n"
        ".Lf8df24_0008e087:\n"
        "movl %esi, %edx\n" /* line 2070 | name */
        "movl %edi, %eax\n" /* parentId */
        "calll Scr_EvalVariableEntityField\n"
        "jmp .Lf8df24_0008e00b\n"
        /* { scope 2: entry */
        ".Lf8df24_0008e095:\n"
        "cmpb $0, -1(%esi)\n" /* line 1879 */
        "jne .Lf8df24_0008dfd3\n"
        "addw $1, -4(%esi)\n" /* line 1894 */
        "jmp .Lf8df24_0008dfd3\n"
        ".Lf8df24_0008e0a9:\n"
        "cmpl $1, %ebx\n" /* line 1928 | entryValue */
        "jne .Lf8df24_0008dfd3\n"
        "movl %esi, %eax\n" /* line 1748 */
        "shll $4, %eax\n"
        "addw $1, scrVarGlob+4(%eax)\n"
        "jmp .Lf8df24_0008dfd3\n"
    );
}

/* line 1944 */
__attribute__((naked))
JCOEF RemoveRefToValue(int type, VariableUnion u)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1944 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* type */
        "movl 0xc(%ebp), %edx\n" /* u */
        "cmpl $3, %eax\n" /* line 1946 */
        "jg .Lf8e0c4_0008e0e0\n"
        "cmpl $2, %eax\n"
        "jl .Lf8e0c4_0008e102\n"
        "movl %edx, 8(%ebp)\n" /* line 1953 | type */
        "popl %ebp\n" /* line 1959 */
        "jmp SL_RemoveRefToString\n" /* line 1953 */
        ".Lf8e0c4_0008e0e0:\n"
        "cmpl $4, %eax\n" /* line 1946 */
        "je .Lf8e0c4_0008e0e7\n"
        ".Lf8e0c4_0008e0e5:\n"
        "popl %ebp\n" /* line 1959 */
        "retl\n"
        ".Lf8e0c4_0008e0e7:\n"
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf8e0c4_0008e0e5\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf8e0c4_0008e110\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        "popl %ebp\n" /* line 1959 */
        "retl\n"
        ".Lf8e0c4_0008e102:\n"
        "subl $1, %eax\n" /* line 1946 */
        "jne .Lf8e0c4_0008e0e5\n"
        "movl %edx, 8(%ebp)\n" /* line 1949 | type */
        "popl %ebp\n" /* line 1959 */
        "jmp RemoveRefToObject\n" /* line 1949 */
        ".Lf8e0c4_0008e110:\n"
        "movl $0x10, 0xc(%ebp)\n" /* line 1922 | u */
        "movl %ecx, 8(%ebp)\n" /* type */
        "popl %ebp\n" /* line 1959 */
        "jmp MT_Free\n" /* line 1922 */
    );
}

/* line 1473 */
__attribute__((naked))
JCOEF Scr_KillEndonThread(unsigned int threadId)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1473 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* threadId */
        /* { scope 1 */
        "shll $4, %ebx\n" /* line 1477 | parentValue */
        "addl $scrVarGlob, %ebx\n" /* parentValue */
        "movzwl 6(%ebx), %eax\n" /* line 1482 | parentValue */
        "movl %eax, (%esp)\n"
        "calll RemoveRefToObject\n"
        "movl 8(%ebx), %eax\n" /* line 1488 | parentValue */
        "andl $0xffffffe0, %eax\n"
        "orl $0x17, %eax\n"
        "movl %eax, 8(%ebx)\n" /* parentValue */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1489 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3639 */
__attribute__((naked))
JCOEF Scr_FreeEntityList(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3639 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl scrVarPub+48, %eax\n" /* line 3648 */
        "movl %eax, -0x20(%ebp)\n"
        "testl %eax, %eax\n"
        "jne .Lf8e152_0008e186\n"
        /* } scope */
        ".Lf8e152_0008e167:\n"
        "addl $0x2c, %esp\n" /* line 3662 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf8e152_0008e16f:\n"
        "movl -0x20(%ebp), %eax\n" /* line 3660 */
        "movl %eax, (%esp)\n"
        "calll RemoveRefToObject\n"
        "movl scrVarPub+48, %eax\n" /* line 3648 */
        "movl %eax, -0x20(%ebp)\n"
        "testl %eax, %eax\n"
        "je .Lf8e152_0008e167\n"
        ".Lf8e152_0008e186:\n"
        "shll $4, %eax\n" /* line 3651 */
        "leal scrVarGlob(%eax), %esi\n" /* entryValue */
        "movzwl 6(%esi), %eax\n" /* line 3652 | entryValue */
        "movl %eax, scrVarPub+48\n"
        "movw $0, 6(%esi)\n" /* line 3654 | entryValue */
        "movl -0x20(%ebp), %eax\n" /* line 3656 */
        "movl %eax, (%esp)\n"
        "calll Scr_CancelNotifyList\n"
        "movzwl 0xe(%esi), %eax\n" /* line 3657 | entryValue */
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %edx\n"
        "cmpl %edx, -0x20(%ebp)\n"
        "je .Lf8e152_0008e16f\n"
        /* { scope 2 */
        "leal scrVarGlob(%eax), %ecx\n" /* line 1249 */
        "movl %edx, %ebx\n" /* line 1250 | nextId */
        ".Lf8e152_0008e1c4:\n"
        "movl %esi, %edx\n" /* line 1253 */
        "movl %ecx, %eax\n"
        "calll MakeVariableExternal\n"
        "shll $4, %ebx\n" /* line 1254 | nextId */
        "movzwl scrVarGlob+14(%ebx), %eax\n" /* nextId */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movzwl scrVarGlob(%eax), %ebx\n" /* line 1255 | nextId */
        "cmpl %ebx, -0x20(%ebp)\n" /* line 1251 | nextId */
        "jne .Lf8e152_0008e1c4\n"
        "movzwl 0xe(%esi), %eax\n" /* line 1258 */
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %eax\n"
        "cmpl %eax, -0x20(%ebp)\n" /* line 1259 */
        "jne .Lf8e152_0008e28e\n"
        "jmp .Lf8e152_0008e16f\n"
        /* { scope 3 */
        /* { scope 4 */
        ".Lf8e152_0008e208:\n"
        "cmpl $2, %eax\n" /* line 1946 */
        "jl .Lf8e152_0008e2ea\n"
        "movl %edx, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        /* } scope */
        /* { scope 4 */
        /* { scope 5 */
        ".Lf8e152_0008e219:\n"
        "movzwl 0xc(%edi), %ebx\n" /* line 1578 | index */
        "movzwl %bx, %ecx\n" /* line 1579 | index */
        "shll $4, %ecx\n"
        "addl $scrVarGlob, %ecx\n"
        "movzwl 2(%ecx), %edx\n" /* line 1581 */
        "movzwl 0xe(%edi), %esi\n" /* line 1582 | nextSiblingIndex */
        "movzwl %si, %eax\n" /* line 1583 | nextSiblingIndex */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+2(%eax)\n"
        "shll $4, %edx\n" /* line 1584 */
        "movzwl scrVarGlob(%edx), %eax\n"
        "shll $4, %eax\n"
        "movw %si, scrVarGlob+14(%eax)\n" /* nextSiblingIndex */
        "movl $0, 8(%edi)\n" /* line 1586 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1587 */
        "movw %ax, 4(%edi)\n"
        "movw $0, 2(%ecx)\n" /* line 1588 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1590 */
        "shll $4, %eax\n"
        "movw %bx, scrVarGlob+2(%eax)\n" /* index */
        "movw %bx, scrVarGlob+4\n" /* line 1591 | index */
        /* } scope */
        /* } scope */
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 1259 */
        "cmpl %eax, -0x20(%ebp)\n"
        "je .Lf8e152_0008e16f\n"
        ".Lf8e152_0008e28e:\n"
        "movl %eax, %edx\n" /* line 1262 */
        "shll $4, %edx\n"
        "movzwl scrVarGlob+14(%edx), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        /* { scope 3 */
        "leal scrVarGlob(%edx), %edi\n" /* line 1721 | entryValue */
        "movl 4(%edi), %edx\n" /* line 1727 | entryValue */
        "movl 8(%edi), %eax\n" /* entryValue, type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 4 */
        "cmpl $3, %eax\n" /* line 1946 */
        "jle .Lf8e152_0008e208\n"
        "cmpl $4, %eax\n"
        "jne .Lf8e152_0008e219\n"
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf8e152_0008e219\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf8e152_0008e300\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        "jmp .Lf8e152_0008e219\n"
        ".Lf8e152_0008e2ea:\n"
        "subl $1, %eax\n" /* line 1946 */
        "jne .Lf8e152_0008e219\n"
        "movl %edx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "jmp .Lf8e152_0008e219\n"
        ".Lf8e152_0008e300:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "jmp .Lf8e152_0008e219\n"
    );
}

/* line 2322 */
__attribute__((naked))
JCOEF SafeRemoveVariable(unsigned int parentId, unsigned int unsignedValue)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2322 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* parentId */
        "movl 0xc(%ebp), %edi\n" /* unsignedValue */
        /* { scope 1: entry */
        "leal (%esi, %edi), %ecx\n" /* line 801 */
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n"
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n"
        "addl $1, %ecx\n"
        "movzwl %cx, %edx\n"
        /* { scope 2 */
        "movl %edx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movl 8(%ecx), %ebx\n" /* line 748 | newEntryValue */
        "movl %ebx, %eax\n" /* newEntryValue */
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf8e316_0008e379\n"
        /* } scope */
        /* } scope */
        ".Lf8e316_0008e371:\n"
        "addl $0x2c, %esp\n" /* line 2338 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: entry */
        /* { scope 2 */
        ".Lf8e316_0008e379:\n"
        "shrl $8, %ebx\n" /* line 752 | newEntryValue */
        "cmpl %ebx, %edi\n" /* newEntryValue */
        "je .Lf8e316_0008e3cb\n"
        "movzwl 0xc(%ecx), %edx\n" /* line 757 */
        "movl %edx, %ecx\n" /* line 758 */
        "shll $4, %ecx\n"
        "leal scrVarGlob(%ecx), %eax\n"
        "cmpl %eax, -0x1c(%ebp)\n" /* line 759 | entry */
        "je .Lf8e316_0008e371\n"
        "movzwl scrVarGlob(%ecx), %eax\n" /* line 761 */
        "jmp .Lf8e316_0008e3b8\n"
        ".Lf8e316_0008e39d:\n"
        "movzwl 0xc(%ebx), %edx\n" /* line 771 | newEntryValue */
        "movl %edx, %ebx\n" /* line 772 | newEntryValue */
        "shll $4, %ebx\n" /* newEntryValue */
        "leal scrVarGlob(%ebx), %eax\n" /* newEntryValue */
        "cmpl %eax, -0x1c(%ebp)\n" /* line 759 | entry */
        "je .Lf8e316_0008e371\n"
        "movzwl scrVarGlob(%ebx), %eax\n" /* line 761 | newEntryValue */
        ".Lf8e316_0008e3b8:\n"
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ebx\n" /* newEntryValue */
        "movl 8(%ebx), %eax\n" /* line 766 | newEntryValue */
        "shrl $8, %eax\n"
        "cmpl %eax, %edi\n"
        "jne .Lf8e316_0008e39d\n"
        /* } scope */
        ".Lf8e316_0008e3cb:\n"
        "testl %edx, %edx\n" /* line 2329 */
        "je .Lf8e316_0008e371\n"
        "shll $4, %edx\n" /* line 2332 */
        "leal scrVarGlob(%edx), %eax\n"
        "movzwl scrVarGlob(%edx), %ebx\n" /* line 2333 | id */
        "shll $4, %esi\n" /* line 2336 | parentId */
        "leal scrVarGlob(%esi), %edx\n" /* parentId */
        "calll MakeVariableExternal\n"
        /* { scope 2 */
        "shll $4, %ebx\n" /* line 1721 | index */
        "leal scrVarGlob(%ebx), %edi\n" /* index, entryValue */
        "movl 4(%edi), %edx\n" /* line 1727 | entryValue */
        "movl 8(%edi), %eax\n" /* entryValue, type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 3 */
        "cmpl $3, %eax\n" /* line 1946 */
        "jg .Lf8e316_0008e48a\n"
        "cmpl $2, %eax\n"
        "jl .Lf8e316_0008e4ad\n"
        "movl %edx, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        /* } scope */
        /* { scope 3 */
        ".Lf8e316_0008e419:\n"
        "movzwl 0xc(%edi), %ebx\n" /* line 1578 | index */
        "movzwl %bx, %ecx\n" /* line 1579 | index */
        "shll $4, %ecx\n"
        "addl $scrVarGlob, %ecx\n"
        "movzwl 2(%ecx), %edx\n" /* line 1581 */
        "movzwl 0xe(%edi), %esi\n" /* line 1582 | nextSiblingIndex */
        "movzwl %si, %eax\n" /* line 1583 | nextSiblingIndex */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+2(%eax)\n"
        "shll $4, %edx\n" /* line 1584 */
        "movzwl scrVarGlob(%edx), %eax\n"
        "shll $4, %eax\n"
        "movw %si, scrVarGlob+14(%eax)\n" /* nextSiblingIndex */
        "movl $0, 8(%edi)\n" /* line 1586 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1587 */
        "movw %ax, 4(%edi)\n"
        "movw $0, 2(%ecx)\n" /* line 1588 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1590 */
        "shll $4, %eax\n"
        "movw %bx, scrVarGlob+2(%eax)\n" /* index */
        "movw %bx, scrVarGlob+4\n" /* line 1591 | index */
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 2338 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: entry */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf8e316_0008e48a:\n"
        "cmpl $4, %eax\n" /* line 1946 */
        "jne .Lf8e316_0008e419\n"
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf8e316_0008e419\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf8e316_0008e4c3\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        "jmp .Lf8e316_0008e419\n"
        ".Lf8e316_0008e4ad:\n"
        "subl $1, %eax\n" /* line 1946 */
        "jne .Lf8e316_0008e419\n"
        "movl %edx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "jmp .Lf8e316_0008e419\n"
        ".Lf8e316_0008e4c3:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "jmp .Lf8e316_0008e419\n"
    );
}

/* line 2279 */
__attribute__((naked))
JCOEF RemoveNextVariable(unsigned int parentId)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2279 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edx\n" /* parentId */
        /* { scope 1 */
        "shll $4, %edx\n" /* line 2290 */
        "movzwl scrVarGlob+14(%edx), %ecx\n"
        "shll $4, %ecx\n"
        "leal scrVarGlob(%ecx), %eax\n"
        "movzwl scrVarGlob(%ecx), %ebx\n" /* line 2291 | id */
        "addl $scrVarGlob, %edx\n" /* line 2293 */
        "calll MakeVariableExternal\n"
        /* { scope 2 */
        "shll $4, %ebx\n" /* line 1721 | index */
        "leal scrVarGlob(%ebx), %edi\n" /* index, entryValue */
        "movl 4(%edi), %edx\n" /* line 1727 | entryValue */
        "movl 8(%edi), %eax\n" /* entryValue, type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 3 */
        "cmpl $3, %eax\n" /* line 1946 */
        "jg .Lf8e4d8_0008e5a6\n"
        "cmpl $2, %eax\n"
        "jl .Lf8e4d8_0008e5c9\n"
        "movl %edx, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        /* } scope */
        /* { scope 3 */
        ".Lf8e4d8_0008e535:\n"
        "movzwl 0xc(%edi), %ebx\n" /* line 1578 | index */
        "movzwl %bx, %ecx\n" /* line 1579 | index */
        "shll $4, %ecx\n"
        "addl $scrVarGlob, %ecx\n"
        "movzwl 2(%ecx), %edx\n" /* line 1581 */
        "movzwl 0xe(%edi), %esi\n" /* line 1582 | nextSiblingIndex */
        "movzwl %si, %eax\n" /* line 1583 | nextSiblingIndex */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+2(%eax)\n"
        "shll $4, %edx\n" /* line 1584 */
        "movzwl scrVarGlob(%edx), %eax\n"
        "shll $4, %eax\n"
        "movw %si, scrVarGlob+14(%eax)\n" /* nextSiblingIndex */
        "movl $0, 8(%edi)\n" /* line 1586 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1587 */
        "movw %ax, 4(%edi)\n"
        "movw $0, 2(%ecx)\n" /* line 1588 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1590 */
        "shll $4, %eax\n"
        "movw %bx, scrVarGlob+2(%eax)\n" /* index */
        "movw %bx, scrVarGlob+4\n" /* line 1591 | index */
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 2295 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf8e4d8_0008e5a6:\n"
        "cmpl $4, %eax\n" /* line 1946 */
        "jne .Lf8e4d8_0008e535\n"
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf8e4d8_0008e535\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf8e4d8_0008e5df\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        "jmp .Lf8e4d8_0008e535\n"
        ".Lf8e4d8_0008e5c9:\n"
        "subl $1, %eax\n" /* line 1946 */
        "jne .Lf8e4d8_0008e535\n"
        "movl %edx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "jmp .Lf8e4d8_0008e535\n"
        ".Lf8e4d8_0008e5df:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "jmp .Lf8e4d8_0008e535\n"
    );
}

/* line 2262 */
__attribute__((naked))
JCOEF RemoveVariable(unsigned int parentId, unsigned int unsignedValue)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2262 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* parentId */
        "movl 0xc(%ebp), %edi\n" /* unsignedValue */
        /* { scope 1: entry */
        "leal (%esi, %edi), %ecx\n" /* line 801 */
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n"
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n"
        "addl $1, %ecx\n"
        "movzwl %cx, %edx\n"
        /* { scope 2 */
        "movl %edx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movl 8(%ecx), %ebx\n" /* line 748 | newEntryValue */
        "movl %ebx, %eax\n" /* newEntryValue */
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf8e5f4_0008e737\n"
        ".Lf8e5f4_0008e653:\n"
        "xorl %edx, %edx\n" /* line 759 */
        /* } scope */
        ".Lf8e5f4_0008e655:\n"
        "shll $4, %edx\n" /* line 2271 */
        "leal scrVarGlob(%edx), %eax\n"
        "movzwl scrVarGlob(%edx), %ebx\n" /* line 2272 | id */
        "shll $4, %esi\n" /* line 2274 | parentId */
        "leal scrVarGlob(%esi), %edx\n" /* parentId */
        "calll MakeVariableExternal\n"
        /* { scope 2 */
        "shll $4, %ebx\n" /* line 1721 | index */
        "leal scrVarGlob(%ebx), %edi\n" /* index, entryValue */
        "movl 4(%edi), %edx\n" /* line 1727 | entryValue */
        "movl 8(%edi), %eax\n" /* entryValue, type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 3 */
        "cmpl $3, %eax\n" /* line 1946 */
        "jg .Lf8e5f4_0008e710\n"
        "cmpl $2, %eax\n"
        "jl .Lf8e5f4_0008e79a\n"
        "movl %edx, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        /* } scope */
        /* { scope 3 */
        ".Lf8e5f4_0008e69f:\n"
        "movzwl 0xc(%edi), %ebx\n" /* line 1578 | index */
        "movzwl %bx, %ecx\n" /* line 1579 | index */
        "shll $4, %ecx\n"
        "addl $scrVarGlob, %ecx\n"
        "movzwl 2(%ecx), %edx\n" /* line 1581 */
        "movzwl 0xe(%edi), %esi\n" /* line 1582 | nextSiblingIndex */
        "movzwl %si, %eax\n" /* line 1583 | nextSiblingIndex */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+2(%eax)\n"
        "shll $4, %edx\n" /* line 1584 */
        "movzwl scrVarGlob(%edx), %eax\n"
        "shll $4, %eax\n"
        "movw %si, scrVarGlob+14(%eax)\n" /* nextSiblingIndex */
        "movl $0, 8(%edi)\n" /* line 1586 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1587 */
        "movw %ax, 4(%edi)\n"
        "movw $0, 2(%ecx)\n" /* line 1588 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1590 */
        "shll $4, %eax\n"
        "movw %bx, scrVarGlob+2(%eax)\n" /* index */
        "movw %bx, scrVarGlob+4\n" /* line 1591 | index */
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 2276 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: entry */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf8e5f4_0008e710:\n"
        "cmpl $4, %eax\n" /* line 1946 */
        "jne .Lf8e5f4_0008e69f\n"
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf8e5f4_0008e69f\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf8e5f4_0008e7b0\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        "jmp .Lf8e5f4_0008e69f\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf8e5f4_0008e737:\n"
        "shrl $8, %ebx\n" /* line 752 | newEntryValue */
        "cmpl %ebx, %edi\n" /* newEntryValue */
        "je .Lf8e5f4_0008e655\n"
        "movzwl 0xc(%ecx), %edx\n" /* line 757 */
        "movl %edx, %ecx\n" /* line 758 */
        "shll $4, %ecx\n"
        "leal scrVarGlob(%ecx), %eax\n"
        "cmpl %eax, -0x1c(%ebp)\n" /* line 759 | entry */
        "je .Lf8e5f4_0008e653\n"
        "movzwl scrVarGlob(%ecx), %eax\n" /* line 761 */
        "jmp .Lf8e5f4_0008e76a\n"
        ".Lf8e5f4_0008e763:\n"
        "movzwl scrVarGlob(%ebx), %eax\n" /* newEntryValue */
        ".Lf8e5f4_0008e76a:\n"
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ebx\n" /* newEntryValue */
        "movl 8(%ebx), %eax\n" /* line 766 | newEntryValue */
        "shrl $8, %eax\n"
        "cmpl %eax, %edi\n"
        "je .Lf8e5f4_0008e655\n"
        "movzwl 0xc(%ebx), %edx\n" /* line 771 | newEntryValue */
        "movl %edx, %ebx\n" /* line 772 | newEntryValue */
        "shll $4, %ebx\n" /* newEntryValue */
        "leal scrVarGlob(%ebx), %eax\n" /* newEntryValue */
        "cmpl %eax, -0x1c(%ebp)\n" /* line 759 | entry */
        "jne .Lf8e5f4_0008e763\n"
        "jmp .Lf8e5f4_0008e653\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf8e5f4_0008e79a:\n"
        "subl $1, %eax\n" /* line 1946 */
        "jne .Lf8e5f4_0008e69f\n"
        "movl %edx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "jmp .Lf8e5f4_0008e69f\n"
        ".Lf8e5f4_0008e7b0:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "jmp .Lf8e5f4_0008e69f\n"
    );
}

/* line 4559 */
static __attribute__((naked))
int Scr_MakeValuePrimitive(void)
{
    __asm__ __volatile__ (
        ".Lf8e7c6_0008e7c6:\n"
        "pushl %ebp\n" /* line 4559 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl %eax, %esi\n" /* parentId */
        /* { scope 1 */
        "shll $4, %eax\n" /* line 4576 */
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0x16, %eax\n"
        "je .Lf8e7c6_0008e835\n"
        "xorl %eax, %eax\n" /* line 4580 */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 4619 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf8e7c6_0008e7ec:\n"
        "movl %ebx, %eax\n" /* line 2665 */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8e7c6_0008e852\n"
        "testw %dx, %dx\n" /* line 4580 */
        "je .Lf8e7c6_0008e852\n"
        ".Lf8e7c6_0008e804:\n"
        "movl %ebx, %eax\n" /* line 4582 | id */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 4587 */
        "movl %eax, %edi\n" /* name */
        "shrl $8, %edi\n" /* name */
        "andl $0x1f, %eax\n" /* line 4589 */
        "cmpl $1, %eax\n"
        "je .Lf8e7c6_0008e85f\n"
        "jb .Lf8e7c6_0008e86b\n"
        "subl $7, %eax\n"
        "cmpl $4, %eax\n"
        "ja .Lf8e7c6_0008e86b\n"
        ".Lf8e7c6_0008e829:\n"
        "movl %edi, 4(%esp)\n" /* line 4608 | name */
        "movl %esi, (%esp)\n" /* parentId */
        "calll RemoveVariable\n"
        ".Lf8e7c6_0008e835:\n"
        "movl %esi, %eax\n" /* line 2654 */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %edx\n"
        "movzwl %dx, %ebx\n"
        "cmpl %ebx, %esi\n" /* line 2660 */
        "jne .Lf8e7c6_0008e7ec\n"
        ".Lf8e7c6_0008e852:\n"
        "movl $1, %eax\n" /* line 4580 */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 4619 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf8e7c6_0008e85f:\n"
        "movl 4(%edx), %eax\n" /* line 4606 */
        "calll Scr_MakeValuePrimitive\n"
        "testl %eax, %eax\n"
        "je .Lf8e7c6_0008e829\n"
        ".Lf8e7c6_0008e86b:\n"
        "movl %ebx, %eax\n" /* line 2654 */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "movzwl %cx, %edx\n"
        "cmpl %edx, %ebx\n" /* line 2660 */
        "je .Lf8e7c6_0008e852\n"
        "movl %edx, %eax\n" /* line 2665 */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8e7c6_0008e852\n"
        "testw %cx, %cx\n" /* line 4580 */
        "je .Lf8e7c6_0008e852\n"
        "movl %edx, %ebx\n" /* id */
        "jmp .Lf8e7c6_0008e804\n"
    );
}

/* line 4645 */
__attribute__((naked))
JCOEF Scr_FreeGameVariable(int bComplete)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4645 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* line 4651 | bComplete, index */
        "testl %ebx, %ebx\n" /* index */
        "je .Lf8e8a8_0008e98f\n"
        /* { scope 1 */
        "movl scrVarPub+40, %eax\n" /* line 1721 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edi\n" /* entryValue */
        "movl 4(%edi), %edx\n" /* line 1727 | entryValue */
        "movl 8(%edi), %eax\n" /* entryValue, type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 2 */
        "cmpl $3, %eax\n" /* line 1946 */
        "jg .Lf8e8a8_0008e968\n"
        "cmpl $2, %eax\n"
        "jl .Lf8e8a8_0008e9aa\n"
        "movl %edx, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        /* } scope */
        /* { scope 2 */
        ".Lf8e8a8_0008e8ed:\n"
        "movzwl 0xc(%edi), %ebx\n" /* line 1578 | index */
        "movzwl %bx, %ecx\n" /* line 1579 | index */
        "shll $4, %ecx\n"
        "addl $scrVarGlob, %ecx\n"
        "movzwl 2(%ecx), %edx\n" /* line 1581 */
        "movzwl 0xe(%edi), %esi\n" /* line 1582 | nextSiblingIndex */
        "movzwl %si, %eax\n" /* line 1583 | nextSiblingIndex */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+2(%eax)\n"
        "shll $4, %edx\n" /* line 1584 */
        "movzwl scrVarGlob(%edx), %eax\n"
        "shll $4, %eax\n"
        "movw %si, scrVarGlob+14(%eax)\n" /* nextSiblingIndex */
        "movl $0, 8(%edi)\n" /* line 1586 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1587 */
        "movw %ax, 4(%edi)\n"
        "movw $0, 2(%ecx)\n" /* line 1588 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1590 */
        "shll $4, %eax\n"
        "movw %bx, scrVarGlob+2(%eax)\n" /* index */
        "movw %bx, scrVarGlob+4\n" /* line 1591 | index */
        /* } scope */
        /* } scope */
        "movl $0, scrVarPub+40\n" /* line 4654 */
        "addl $0x1c, %esp\n" /* line 4661 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf8e8a8_0008e968:\n"
        "cmpl $4, %eax\n" /* line 1946 */
        "jne .Lf8e8a8_0008e8ed\n"
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf8e8a8_0008e8ed\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf8e8a8_0008e9c0\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        "jmp .Lf8e8a8_0008e8ed\n"
        /* } scope */
        /* } scope */
        ".Lf8e8a8_0008e98f:\n"
        "movl scrVarPub+40, %eax\n" /* line 4660 */
        "shll $4, %eax\n"
        "movl scrVarGlob+4(%eax), %eax\n"
        "calll Scr_MakeValuePrimitive\n"
        "addl $0x1c, %esp\n" /* line 4661 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf8e8a8_0008e9aa:\n"
        "subl $1, %eax\n" /* line 1946 */
        "jne .Lf8e8a8_0008e8ed\n"
        "movl %edx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "jmp .Lf8e8a8_0008e8ed\n"
        ".Lf8e8a8_0008e9c0:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "jmp .Lf8e8a8_0008e8ed\n"
    );
}

/* line 3593 */
__attribute__((naked))
JCOEF Scr_FreeEntityNum(int entnum, int classnum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3593 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %edx\n" /* entnum */
        "movl 0xc(%ebp), %eax\n" /* classnum */
        /* { scope 1 */
        "cmpb $0, scrVarPub+56\n" /* line 3600 */
        "je .Lf8e9d6_0008ea66\n"
        "leal (%eax, %eax, 2), %eax\n" /* line 3603 */
        "movzwl g_classMap+2(, %eax, 4), %eax\n"
        "movl %eax, -0x10(%ebp)\n" /* entArrayId */
        "leal s_debugFrameGlob+57728(%edx), %esi\n" /* line 1980 | name */
        "andl $0x00FFFFFF, %esi\n" /* name */
        "movl %eax, %ecx\n" /* line 801 | index */
        "addl %esi, %ecx\n" /* name, index */
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n" /* index */
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n" /* index */
        "addl $1, %ecx\n" /* index */
        "movzwl %cx, %ecx\n" /* index */
        /* { scope 2 */
        /* { scope 3 */
        "movl %ecx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edi\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ebx\n" /* entryValue */
        "movl 8(%ebx), %edx\n" /* line 748 | entryValue */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf8e9d6_0008eaba\n"
        ".Lf8e9d6_0008ea52:\n"
        "xorl %ecx, %ecx\n" /* line 759 */
        /* } scope */
        /* } scope */
        ".Lf8e9d6_0008ea54:\n"
        "shll $4, %ecx\n" /* line 1986 */
        "movzwl scrVarGlob(%ecx), %eax\n"
        "movzwl %ax, %edx\n"
        "testw %ax, %ax\n" /* line 3607 */
        "jne .Lf8e9d6_0008ea6e\n"
        /* } scope */
        ".Lf8e9d6_0008ea66:\n"
        "addl $4, %esp\n" /* line 3636 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf8e9d6_0008ea6e:\n"
        "shll $4, %edx\n" /* line 2743 */
        "movl scrVarGlob+4(%edx), %ebx\n" /* entryValue */
        "movl %ebx, %edx\n" /* line 3613 | entId */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %ecx\n"
        "movl 8(%ecx), %eax\n" /* line 3620 */
        "andl $0xffffffe0, %eax\n"
        "orl $0x14, %eax\n"
        "movl %eax, 8(%ecx)\n"
        "addw $1, scrVarGlob+4(%edx)\n" /* line 1748 */
        "movl scrVarPub+48, %eax\n" /* line 3623 */
        "movw %ax, 6(%ecx)\n"
        "movl %ebx, scrVarPub+48\n" /* line 3629 | entId */
        "movl %esi, 0xc(%ebp)\n" /* line 2318 | name, classnum */
        "movl -0x10(%ebp), %eax\n" /* entArrayId */
        "movl %eax, 8(%ebp)\n" /* entnum */
        /* } scope */
        "addl $4, %esp\n" /* line 3636 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp RemoveVariable\n" /* line 2318 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf8e9d6_0008eaba:\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, %esi\n"
        "je .Lf8e9d6_0008ea54\n"
        "movzwl 0xc(%ebx), %ecx\n" /* line 757 | entryValue */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, %edi\n" /* line 759 | entry */
        "je .Lf8e9d6_0008ea52\n"
        ".Lf8e9d6_0008ead8:\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, %esi\n"
        "je .Lf8e9d6_0008ea54\n"
        "movzwl 0xc(%edx), %ecx\n" /* line 771 */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, %edi\n" /* line 759 | entry */
        "jne .Lf8e9d6_0008ead8\n"
        "jmp .Lf8e9d6_0008ea52\n"
    );
}

/* line 2298 */
JCOEF RemoveObjectVariable(unsigned int parentId, unsigned int id)
{
    RemoveVariable(parentId, id + 0x10000);
}

/* line 2181 */
__attribute__((naked))
JCOEF ClearVariableField(unsigned int parentId, unsigned int name, VariableValue *value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2181 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* parentId */
        "movl 0xc(%ebp), %edi\n" /* name */
        "movl 0x10(%ebp), %eax\n" /* value */
        "movl %eax, -0x28(%ebp)\n" /* value */
        /* { scope 1: entry */
        "leal (%esi, %edi), %ecx\n" /* line 801 | name, index */
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n" /* index */
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n" /* index */
        "addl $1, %ecx\n" /* index */
        "movzwl %cx, %ebx\n" /* index, entryValue */
        /* { scope 2 */
        "movl %ebx, %eax\n" /* line 745 | entryValue */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movl 8(%ecx), %edx\n" /* line 748 */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf8eb1e_0008ec61\n"
        /* } scope */
        ".Lf8eb1e_0008eb83:\n"
        "shll $4, %esi\n" /* line 2198 | parentId */
        "addl $scrVarGlob, %esi\n" /* parentId */
        "movl %esi, -0x24(%ebp)\n" /* parentId, parentValue */
        "movl 8(%esi), %edx\n" /* line 2199 | parentId */
        "movl %edx, %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0x15, %eax\n"
        "je .Lf8eb1e_0008eba4\n"
        /* } scope */
        ".Lf8eb1e_0008eb9c:\n"
        "addl $0x2c, %esp\n" /* line 2211 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: entry */
        ".Lf8eb1e_0008eba4:\n"
        "shrl $8, %edx\n" /* line 2203 */
        "movl %edx, -0x20(%ebp)\n" /* classnum */
        "leal s_debugFrameGlob+57728(%edi), %esi\n" /* line 1980 | entry, name */
        "andl $0x00FFFFFF, %esi\n" /* name */
        "leal (%edx, %edx, 2), %eax\n" /* line 801 */
        "movzwl g_classMap(, %eax, 4), %ecx\n" /* index */
        "addl %esi, %ecx\n" /* name, index */
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n" /* index */
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n" /* index */
        "addl $1, %ecx\n" /* index */
        "movzwl %cx, %ecx\n" /* index */
        /* { scope 2 */
        /* { scope 3 */
        "movl %ecx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edi\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ebx\n" /* entryValue */
        "movl 8(%ebx), %edx\n" /* line 748 | entryValue */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf8eb1e_0008ece6\n"
        ".Lf8eb1e_0008ec0d:\n"
        "xorl %ecx, %ecx\n" /* line 759 */
        /* } scope */
        /* } scope */
        ".Lf8eb1e_0008ec0f:\n"
        "shll $4, %ecx\n" /* line 1986 */
        "movzwl scrVarGlob(%ecx), %eax\n"
        "movzwl %ax, %edx\n"
        "testw %ax, %ax\n" /* line 2205 */
        "je .Lf8eb1e_0008eb9c\n"
        "movl -0x28(%ebp), %eax\n" /* line 2208 | value */
        "addl $8, %eax\n"
        "movl $0, 4(%eax)\n" /* line 2209 */
        "movl %eax, 0xc(%esp)\n" /* line 2210 */
        "shll $4, %edx\n"
        "movl scrVarGlob+4(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x24(%ebp), %edx\n" /* parentValue */
        "movzwl 6(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x20(%ebp), %eax\n" /* classnum */
        "movl %eax, (%esp)\n"
        "calll SetEntityFieldValue\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 2211 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: entry */
        /* { scope 2 */
        ".Lf8eb1e_0008ec61:\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, %edi\n" /* entry */
        "je .Lf8eb1e_0008eccc\n"
        "movzwl 0xc(%ecx), %ebx\n" /* line 757 | entryValue */
        "movl %ebx, %edx\n" /* line 758 | entryValue */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x1c(%ebp)\n" /* line 759 | entry */
        "je .Lf8eb1e_0008eb83\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, %edi\n" /* entry */
        "je .Lf8eb1e_0008eccc\n"
        ".Lf8eb1e_0008ec9a:\n"
        "movzwl 0xc(%edx), %ebx\n" /* line 771 | entryValue */
        "movl %ebx, %edx\n" /* line 758 | entryValue */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x1c(%ebp)\n" /* line 759 | entry */
        "je .Lf8eb1e_0008eb83\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, %edi\n" /* entry */
        "jne .Lf8eb1e_0008ec9a\n"
        /* } scope */
        ".Lf8eb1e_0008eccc:\n"
        "testl %ebx, %ebx\n" /* line 2192 | index */
        "je .Lf8eb1e_0008eb83\n"
        "movl %edi, 0xc(%ebp)\n" /* line 2194 | name */
        "movl %esi, 8(%ebp)\n" /* parentId */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 2211 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1: entry */
        "jmp RemoveVariable\n" /* line 2194 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf8eb1e_0008ece6:\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, %esi\n"
        "je .Lf8eb1e_0008ec0f\n"
        "movzwl 0xc(%ebx), %ecx\n" /* line 757 | entryValue */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, %edi\n" /* line 759 | entry */
        "je .Lf8eb1e_0008ec0d\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, %esi\n"
        "jne .Lf8eb1e_0008ed45\n"
        "jmp .Lf8eb1e_0008ec0f\n"
        ".Lf8eb1e_0008ed27:\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %esi, %eax\n"
        "je .Lf8eb1e_0008ec0f\n"
        ".Lf8eb1e_0008ed45:\n"
        "movzwl 0xc(%edx), %ecx\n" /* line 771 */
        "movl %ecx, %edx\n" /* line 772 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, %edi\n" /* line 759 | entry */
        "jne .Lf8eb1e_0008ed27\n"
        "jmp .Lf8eb1e_0008ec0d\n"
    );
}

/* line 695 */
__attribute__((naked))
JCOEF Var_Shutdown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 695 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl scrVarPub+40, %eax\n" /* line 697 */
        "testl %eax, %eax\n"
        "je .Lf8ed5e_0008ee13\n"
        /* { scope 1 */
        "shll $4, %eax\n" /* line 1721 */
        "leal scrVarGlob(%eax), %edi\n" /* entryValue */
        "movl 4(%edi), %edx\n" /* line 1727 | entryValue */
        "movl 8(%edi), %eax\n" /* entryValue, type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 2 */
        "cmpl $3, %eax\n" /* line 1946 */
        "jg .Lf8ed5e_0008ee1b\n"
        "cmpl $2, %eax\n"
        "jl .Lf8ed5e_0008ee42\n"
        "movl %edx, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        /* } scope */
        /* { scope 2 */
        ".Lf8ed5e_0008eda0:\n"
        "movzwl 0xc(%edi), %ebx\n" /* line 1578 | index */
        "movzwl %bx, %ecx\n" /* line 1579 | index */
        "shll $4, %ecx\n"
        "addl $scrVarGlob, %ecx\n"
        "movzwl 2(%ecx), %edx\n" /* line 1581 */
        "movzwl 0xe(%edi), %esi\n" /* line 1582 | nextSiblingIndex */
        "movzwl %si, %eax\n" /* line 1583 | nextSiblingIndex */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+2(%eax)\n"
        "shll $4, %edx\n" /* line 1584 */
        "movzwl scrVarGlob(%edx), %eax\n"
        "shll $4, %eax\n"
        "movw %si, scrVarGlob+14(%eax)\n" /* nextSiblingIndex */
        "movl $0, 8(%edi)\n" /* line 1586 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1587 */
        "movw %ax, 4(%edi)\n"
        "movw $0, 2(%ecx)\n" /* line 1588 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1590 */
        "shll $4, %eax\n"
        "movw %bx, scrVarGlob+2(%eax)\n" /* index */
        "movw %bx, scrVarGlob+4\n" /* line 1591 | index */
        /* } scope */
        /* } scope */
        "movl $0, scrVarPub+40\n" /* line 700 */
        ".Lf8ed5e_0008ee13:\n"
        "addl $0x1c, %esp\n" /* line 712 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf8ed5e_0008ee1b:\n"
        "cmpl $4, %eax\n" /* line 1946 */
        "jne .Lf8ed5e_0008eda0\n"
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf8ed5e_0008eda0\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf8ed5e_0008ee58\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        "jmp .Lf8ed5e_0008eda0\n"
        ".Lf8ed5e_0008ee42:\n"
        "subl $1, %eax\n" /* line 1946 */
        "jne .Lf8ed5e_0008eda0\n"
        "movl %edx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "jmp .Lf8ed5e_0008eda0\n"
        ".Lf8ed5e_0008ee58:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "jmp .Lf8ed5e_0008eda0\n"
    );
}

/* line 3665 */
__attribute__((naked))
JCOEF Scr_FreeObjects(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3665 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl $1, -0x24(%ebp)\n" /* id */
        "movl $scrVarGlob, -0x20(%ebp)\n"
        "movl $scrVarGlob+16, -0x28(%ebp)\n"
        "jmp .Lf8ee6e_0008eea7\n"
        /* { scope 1 */
        ".Lf8ee6e_0008ee8e:\n"
        "addl $1, -0x24(%ebp)\n" /* line 3670 | id */
        "addl $0x10, -0x28(%ebp)\n"
        "addl $0x10, -0x20(%ebp)\n"
        "cmpl $0xfffe, -0x24(%ebp)\n" /* id */
        "je .Lf8ee6e_0008f046\n"
        ".Lf8ee6e_0008eea7:\n"
        "movl -0x28(%ebp), %edx\n" /* line 3674 */
        "movl 8(%edx), %eax\n"
        "testb $0x60, %al\n"
        "je .Lf8ee6e_0008ee8e\n"
        "andl $0x1f, %eax\n" /* line 3676 */
        "subl $0x13, %eax\n"
        "cmpl $1, %eax\n"
        "ja .Lf8ee6e_0008ee8e\n"
        "movl -0x24(%ebp), %eax\n" /* line 3679 | id */
        "movl %eax, (%esp)\n"
        "calll Scr_CancelNotifyList\n"
        "movl -0x20(%ebp), %edx\n" /* line 1748 */
        "addw $1, 0x14(%edx)\n"
        /* { scope 2 */
        "movl -0x28(%ebp), %eax\n" /* line 1249 */
        "movzwl 0xe(%eax), %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movzwl scrVarGlob(%eax), %ebx\n" /* line 1250 | nextId */
        "cmpl -0x24(%ebp), %ebx\n" /* line 1251 | id, nextId */
        "je .Lf8ee6e_0008ef1d\n"
        ".Lf8ee6e_0008eeed:\n"
        "movl -0x28(%ebp), %edx\n" /* line 1253 */
        "movl %ecx, %eax\n"
        "calll MakeVariableExternal\n"
        "shll $4, %ebx\n" /* line 1254 | nextId */
        "movzwl scrVarGlob+14(%ebx), %eax\n" /* nextId */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movzwl scrVarGlob(%eax), %ebx\n" /* line 1255 | nextId */
        "cmpl -0x24(%ebp), %ebx\n" /* line 1251 | id, nextId */
        "jne .Lf8ee6e_0008eeed\n"
        "movl -0x28(%ebp), %eax\n"
        "movzwl 0xe(%eax), %edx\n"
        ".Lf8ee6e_0008ef1d:\n"
        "shll $4, %edx\n" /* line 1258 */
        "movzwl scrVarGlob(%edx), %eax\n"
        "cmpl -0x24(%ebp), %eax\n" /* line 1259 | id */
        "jne .Lf8ee6e_0008efba\n"
        "jmp .Lf8ee6e_0008f01a\n"
        /* { scope 3 */
        /* { scope 4 */
        ".Lf8ee6e_0008ef35:\n"
        "cmpl $2, %eax\n" /* line 1946 */
        "jl .Lf8ee6e_0008f04e\n"
        "movl %edx, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        /* } scope */
        /* { scope 4 */
        /* { scope 5 */
        ".Lf8ee6e_0008ef46:\n"
        "movzwl 0xc(%edi), %ebx\n" /* line 1578 | index */
        "movzwl %bx, %ecx\n" /* line 1579 | index */
        "shll $4, %ecx\n"
        "addl $scrVarGlob, %ecx\n"
        "movzwl 2(%ecx), %edx\n" /* line 1581 */
        "movzwl 0xe(%edi), %esi\n" /* line 1582 | nextSiblingIndex */
        "movzwl %si, %eax\n" /* line 1583 | nextSiblingIndex */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+2(%eax)\n"
        "shll $4, %edx\n" /* line 1584 */
        "movzwl scrVarGlob(%edx), %eax\n"
        "shll $4, %eax\n"
        "movw %si, scrVarGlob+14(%eax)\n" /* nextSiblingIndex */
        "movl $0, 8(%edi)\n" /* line 1586 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1587 */
        "movw %ax, 4(%edi)\n"
        "movw $0, 2(%ecx)\n" /* line 1588 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1590 */
        "shll $4, %eax\n"
        "movw %bx, scrVarGlob+2(%eax)\n" /* index */
        "movw %bx, scrVarGlob+4\n" /* line 1591 | index */
        /* } scope */
        /* } scope */
        /* } scope */
        "movl -0x24(%ebp), %edx\n" /* line 1259 | id */
        "cmpl %edx, -0x1c(%ebp)\n"
        "je .Lf8ee6e_0008f01a\n"
        "movl -0x1c(%ebp), %eax\n"
        ".Lf8ee6e_0008efba:\n"
        "movl %eax, %edx\n" /* line 1262 */
        "shll $4, %edx\n"
        "movzwl scrVarGlob+14(%edx), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        /* { scope 3 */
        "leal scrVarGlob(%edx), %edi\n" /* line 1721 | entryValue */
        "movl 4(%edi), %edx\n" /* line 1727 | entryValue */
        "movl 8(%edi), %eax\n" /* entryValue, type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 4 */
        "cmpl $3, %eax\n" /* line 1946 */
        "jle .Lf8ee6e_0008ef35\n"
        "cmpl $4, %eax\n"
        "jne .Lf8ee6e_0008ef46\n"
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf8ee6e_0008ef46\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf8ee6e_0008f0d7\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        "jmp .Lf8ee6e_0008ef46\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf8ee6e_0008f01a:\n"
        "movl -0x28(%ebp), %edx\n" /* line 1812 */
        "movzwl 4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf8ee6e_0008f064\n"
        "subl $1, %eax\n" /* line 1821 */
        "movw %ax, 4(%edx)\n"
        "addl $1, -0x24(%ebp)\n" /* line 3670 | id */
        "addl $0x10, -0x28(%ebp)\n"
        "addl $0x10, -0x20(%ebp)\n"
        "cmpl $0xfffe, -0x24(%ebp)\n" /* id */
        "jne .Lf8ee6e_0008eea7\n"
        /* } scope */
        ".Lf8ee6e_0008f046:\n"
        "addl $0x2c, %esp\n" /* line 3682 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf8ee6e_0008f04e:\n"
        "subl $1, %eax\n" /* line 1946 */
        "jne .Lf8ee6e_0008ef46\n"
        "movl %edx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "jmp .Lf8ee6e_0008ef46\n"
        ".Lf8ee6e_0008f064:\n"
        "movl %edx, %eax\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        "movzwl 0xc(%edx), %ebx\n" /* line 1578 | index */
        "movzwl %bx, %ecx\n" /* line 1579 | index */
        "shll $4, %ecx\n"
        "addl $scrVarGlob, %ecx\n"
        "movzwl 2(%ecx), %edx\n" /* line 1581 */
        "movzwl 0xe(%eax), %esi\n" /* line 1582 | nextSiblingIndex */
        "movzwl %si, %eax\n" /* line 1583 | nextSiblingIndex */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+2(%eax)\n"
        "shll $4, %edx\n" /* line 1584 */
        "movzwl scrVarGlob(%edx), %eax\n"
        "shll $4, %eax\n"
        "movw %si, scrVarGlob+14(%eax)\n" /* nextSiblingIndex */
        "movl -0x28(%ebp), %edx\n" /* line 1586 */
        "movl $0, 8(%edx)\n"
        "movzwl scrVarGlob+4, %eax\n" /* line 1587 */
        "movw %ax, 4(%edx)\n"
        "movw $0, 2(%ecx)\n" /* line 1588 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1590 */
        "shll $4, %eax\n"
        "movw %bx, scrVarGlob+2(%eax)\n" /* index */
        "movw %bx, scrVarGlob+4\n" /* line 1591 | index */
        "jmp .Lf8ee6e_0008ee8e\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf8ee6e_0008f0d7:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "jmp .Lf8ee6e_0008ef46\n"
    );
}

/* line 2774 */
__attribute__((naked))
JCOEF Scr_EvalBoolNot(VariableValue *value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2774 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* value */
        "movl 4(%esi), %ebx\n" /* line 2803 | value */
        "cmpl $6, %ebx\n"
        "je .Lf8f0ec_0008f15c\n"
        "cmpl $5, %ebx\n" /* line 2809 */
        "je .Lf8f0ec_0008f168\n"
        "movl (%esi), %edx\n" /* line 252 */
        "cmpl $3, %ebx\n" /* line 1946 */
        "jle .Lf8f0ec_0008f14d\n"
        "cmpl $4, %ebx\n"
        "je .Lf8f0ec_0008f185\n"
        ".Lf8f0ec_0008f110:\n"
        /* Unhandled types → false */
        "movl $0, (%esi)\n"
        "movl $6, 4(%esi)\n"
        ".Lf8f0ec_0008f136:\n"
        "cmpl $6, 4(%esi)\n" /* line 2777 | value */
        "jne .Lf8f0ec_0008f146\n"
        "xorl %eax, %eax\n" /* line 2778 */
        "cmpl $0, (%esi)\n" /* value */
        "sete %al\n"
        "movl %eax, (%esi)\n" /* value */
        ".Lf8f0ec_0008f146:\n"
        "addl $0x10, %esp\n" /* line 2779 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf8f0ec_0008f14d:\n"
        "cmpl $2, %ebx\n" /* line 1946 */
        "jl .Lf8f0ec_0008f1a3\n"
        "movl %edx, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        "jmp .Lf8f0ec_0008f110\n"
        ".Lf8f0ec_0008f15c:\n"
        "xorl %eax, %eax\n" /* line 2805 */
        "cmpl $0, (%esi)\n" /* value */
        "setne %al\n"
        "movl %eax, (%esi)\n" /* value */
        "jmp .Lf8f0ec_0008f136\n"
        ".Lf8f0ec_0008f168:\n"
        "movl $6, 4(%esi)\n" /* line 2811 | value */
        "pxor %xmm0, %xmm0\n" /* line 2812 */
        "ucomiss (%esi), %xmm0\n" /* value */
        "setne %al\n"
        "setp %dl\n"
        "orb %dl, %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, (%esi)\n" /* value */
        "jmp .Lf8f0ec_0008f136\n"
        ".Lf8f0ec_0008f185:\n"
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf8f0ec_0008f110\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf8f0ec_0008f1b9\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        "jmp .Lf8f0ec_0008f110\n"
        ".Lf8f0ec_0008f1a3:\n"
        "cmpl $1, %ebx\n" /* line 1946 */
        "jne .Lf8f0ec_0008f110\n"
        "movl %edx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "jmp .Lf8f0ec_0008f110\n"
        ".Lf8f0ec_0008f1b9:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "jmp .Lf8f0ec_0008f110\n"
    );
}

/* line 2500 */
__attribute__((naked))
JCOEF SetVariableFieldValue(unsigned int id, VariableValue *value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2500 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* id */
        "movl 0xc(%ebp), %esi\n" /* value */
        "cmpl $0xfffe, %eax\n" /* line 2502 */
        "je .Lf8f1ce_0008f247\n"
        /* { scope 1 */
        "shll $4, %eax\n" /* line 2409 */
        "leal scrVarGlob(%eax), %ebx\n" /* entryValue */
        "movl 4(%ebx), %ecx\n" /* line 2414 | entryValue */
        "movl 8(%ebx), %eax\n" /* entryValue */
        "movl %eax, %edx\n" /* type */
        "andl $0x1f, %edx\n" /* type */
        /* { scope 2 */
        "cmpl $3, %edx\n" /* line 1946 */
        "jg .Lf8f1ce_0008f224\n"
        "cmpl $2, %edx\n"
        "jl .Lf8f1ce_0008f268\n"
        "movl %ecx, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        "movl 8(%ebx), %eax\n"
        /* } scope */
        ".Lf8f1ce_0008f20c:\n"
        "andl $0xffffffe0, %eax\n" /* line 2416 */
        "movl %eax, 8(%ebx)\n" /* entryValue */
        "orl 4(%esi), %eax\n" /* line 2417 */
        "movl %eax, 8(%ebx)\n" /* entryValue */
        "movl (%esi), %eax\n" /* line 2418 */
        "movl %eax, 4(%ebx)\n" /* entryValue */
        /* } scope */
        "addl $0x10, %esp\n" /* line 2509 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf8f1ce_0008f224:\n"
        "cmpl $4, %edx\n" /* line 1946 */
        "jne .Lf8f1ce_0008f20c\n"
        "cmpb $0, -1(%ecx)\n" /* line 1901 */
        "jne .Lf8f1ce_0008f20c\n"
        "leal -4(%ecx), %edx\n" /* line 1916 */
        "movzwl -4(%ecx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf8f1ce_0008f27a\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%ecx)\n"
        "movl 8(%ebx), %eax\n"
        "jmp .Lf8f1ce_0008f20c\n"
        /* } scope */
        /* } scope */
        ".Lf8f1ce_0008f247:\n"
        "movl %esi, 8(%esp)\n" /* line 2508 | value */
        "movl scrVarPub+68, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl scrVarPub+64, %eax\n"
        "movl %eax, (%esp)\n"
        "calll SetVariableEntityFieldValue\n"
        "addl $0x10, %esp\n" /* line 2509 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf8f1ce_0008f268:\n"
        "subl $1, %edx\n" /* line 1946 */
        "jne .Lf8f1ce_0008f20c\n"
        "movl %ecx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "movl 8(%ebx), %eax\n"
        "jmp .Lf8f1ce_0008f20c\n"
        ".Lf8f1ce_0008f27a:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %edx, (%esp)\n"
        "calll MT_Free\n"
        "movl 8(%ebx), %eax\n"
        "jmp .Lf8f1ce_0008f20c\n"
    );
}

/* line 4622 */
__attribute__((naked))
JCOEF Scr_AllocGameVariable(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4622 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl $0, -0x30(%ebp)\n" /* tempValue */
        "movl $0, -0x2c(%ebp)\n"
        "movl scrVarPub+40, %esi\n" /* line 4624 */
        "testl %esi, %esi\n"
        "jne .Lf8f292_0008f409\n"
        "movzwl scrVarGlob+4, %eax\n" /* line 1503 */
        "movw %ax, -0x1e(%ebp)\n"
        "testw %ax, %ax\n" /* line 1504 */
        "je .Lf8f292_0008f477\n"
        ".Lf8f292_0008f2cb:\n"
        "movzwl -0x1e(%ebp), %esi\n" /* line 1507 */
        "shll $4, %esi\n"
        "leal scrVarGlob(%esi), %ebx\n"
        "movzwl scrVarGlob(%esi), %edx\n" /* line 1508 */
        "movw %dx, -0x20(%ebp)\n"
        "movzwl %dx, %eax\n"
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movzwl 4(%ecx), %edi\n" /* line 1511 */
        "cmpl %ecx, %ebx\n" /* line 1514 */
        "je .Lf8f292_0008f301\n"
        "testb $0x60, 8(%ebx)\n"
        "je .Lf8f292_0008f411\n"
        ".Lf8f292_0008f301:\n"
        "movw %di, scrVarGlob+4\n" /* line 1526 */
        "movzwl %di, %esi\n" /* line 1527 */
        "shll $4, %esi\n"
        "movw $0, scrVarGlob+2(%esi)\n"
        "movzwl -0x1e(%ebp), %edx\n" /* line 1529 */
        "movw %dx, 0xc(%ecx)\n"
        "movw %dx, 0xe(%ecx)\n" /* line 1530 */
        "movw %dx, 2(%ebx)\n" /* line 1531 */
        "movzwl (%ebx), %edx\n" /* line 1600 */
        "movl %edx, %eax\n" /* line 1601 */
        "shll $4, %eax\n"
        "addl $scrVarGlob, %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl $0x60, 8(%eax)\n" /* line 1602 */
        "movl %edx, scrVarPub+40\n" /* line 4632 */
        /* { scope 1 */
        "testw %di, %di\n" /* line 1504 */
        "je .Lf8f292_0008f488\n"
        ".Lf8f292_0008f34d:\n"
        "leal scrVarGlob(%esi), %ebx\n" /* line 1507 */
        "movzwl scrVarGlob(%esi), %eax\n" /* line 1508 */
        "movw %ax, -0x1c(%ebp)\n"
        "movzwl %ax, %eax\n"
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movzwl 4(%ecx), %edx\n" /* line 1511 */
        "movw %dx, -0x1a(%ebp)\n"
        "cmpl %ecx, %ebx\n" /* line 1514 */
        "je .Lf8f292_0008f4ca\n"
        "testb $0x60, 8(%ebx)\n"
        "je .Lf8f292_0008f444\n"
        "movzwl -0x1a(%ebp), %eax\n"
        ".Lf8f292_0008f388:\n"
        "movw %ax, scrVarGlob+4\n" /* line 1526 */
        "movzwl %ax, %eax\n" /* line 1527 */
        "shll $4, %eax\n"
        "movw $0, scrVarGlob+2(%eax)\n"
        "movw %di, 0xc(%ecx)\n" /* line 1529 */
        "movw %di, 0xe(%ecx)\n" /* line 1530 */
        "movw %di, 2(%ebx)\n" /* line 1531 */
        "movzwl (%ebx), %edx\n" /* line 1657 */
        "movl %edx, %eax\n" /* line 1658 */
        "shll $4, %eax\n"
        "addl $scrVarGlob, %eax\n"
        "movl $0x76, 8(%eax)\n" /* line 1661 */
        "movw $0, 4(%eax)\n" /* line 1662 */
        "movw $0, 6(%eax)\n" /* line 1663 */
        "movl %edx, -0x30(%ebp)\n" /* line 4180 | tempValue */
        "movl -0x24(%ebp), %edx\n" /* line 2414 | type */
        "movl 4(%edx), %ecx\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, %edx\n" /* type */
        "andl $0x1f, %edx\n" /* type */
        /* { scope 2 */
        "cmpl $3, %edx\n" /* line 1946 */
        "jg .Lf8f292_0008f499\n"
        "cmpl $2, %edx\n"
        "jl .Lf8f292_0008f4d1\n"
        "movl %ecx, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        "movl -0x24(%ebp), %edx\n"
        "movl 8(%edx), %eax\n"
        /* } scope */
        ".Lf8f292_0008f3fa:\n"
        "andl $0xffffffe0, %eax\n" /* line 2417 */
        "orl $1, %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl -0x30(%ebp), %eax\n" /* line 2418 | tempValue */
        "movl %eax, 4(%edx)\n"
        /* } scope */
        ".Lf8f292_0008f409:\n"
        "addl $0x3c, %esp\n" /* line 4642 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf8f292_0008f411:\n"
        "movzwl 0xc(%ebx), %edx\n" /* line 1518 */
        "shll $4, %edx\n"
        "movl -0x20(%ebp), %eax\n"
        "movw %ax, scrVarGlob(%edx)\n"
        "movzwl -0x1e(%ebp), %edx\n" /* line 1519 */
        "movw %dx, scrVarGlob(%esi)\n"
        "movzwl 0xc(%ebx), %eax\n" /* line 1520 */
        "movw %ax, 0xc(%ecx)\n"
        "movzwl 4(%ebx), %eax\n" /* line 1521 */
        "movw %ax, 4(%ecx)\n"
        "movl %ebx, %ecx\n"
        "jmp .Lf8f292_0008f301\n"
        /* { scope 1 */
        ".Lf8f292_0008f444:\n"
        "movzwl 0xc(%ebx), %edx\n" /* line 1518 */
        "shll $4, %edx\n"
        "movl -0x1c(%ebp), %eax\n"
        "movw %ax, scrVarGlob(%edx)\n"
        "movw %di, scrVarGlob(%esi)\n" /* line 1519 */
        "movzwl 0xc(%ebx), %edx\n" /* line 1520 */
        "movw %dx, 0xc(%ecx)\n"
        "movzwl 4(%ebx), %eax\n" /* line 1521 */
        "movw %ax, 4(%ecx)\n"
        "movl %ebx, %ecx\n"
        "movzwl -0x1a(%ebp), %eax\n"
        "jmp .Lf8f292_0008f388\n"
        /* } scope */
        ".Lf8f292_0008f477:\n"
        "pushl $str_dbg_site_gamvar1\n"
        "calll Com_Printf\n"
        "addl $4, %esp\n"
        "movl $str_0021d3d8, (%esp)\n" /* line 1505 */
        "calll Scr_TerminalError\n"
        "jmp .Lf8f292_0008f2cb\n"
        /* { scope 1 */
        ".Lf8f292_0008f488:\n"
        "pushl $str_dbg_site_gamvar2\n"
        "calll Com_Printf\n"
        "addl $4, %esp\n"
        "movl $str_0021d3d8, (%esp)\n" /* "exceeded maximum number of script variables" */
        "calll Scr_TerminalError\n"
        "jmp .Lf8f292_0008f34d\n"
        /* { scope 2 */
        ".Lf8f292_0008f499:\n"
        "cmpl $4, %edx\n" /* line 1946 */
        "je .Lf8f292_0008f4a6\n"
        ".Lf8f292_0008f49e:\n"
        "movl -0x24(%ebp), %edx\n"
        "jmp .Lf8f292_0008f3fa\n"
        ".Lf8f292_0008f4a6:\n"
        "cmpb $0, -1(%ecx)\n" /* line 1901 */
        "jne .Lf8f292_0008f49e\n"
        "leal -4(%ecx), %edx\n" /* line 1916 */
        "movzwl -4(%ecx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf8f292_0008f4e9\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%ecx)\n"
        "movl -0x24(%ebp), %edx\n"
        "movl 8(%edx), %eax\n"
        "jmp .Lf8f292_0008f3fa\n"
        ".Lf8f292_0008f4ca:\n"
        "movl %edx, %eax\n"
        "jmp .Lf8f292_0008f388\n"
        ".Lf8f292_0008f4d1:\n"
        "subl $1, %edx\n" /* line 1946 */
        "jne .Lf8f292_0008f49e\n"
        "movl %ecx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "movl -0x24(%ebp), %edx\n"
        "movl 8(%edx), %eax\n"
        "jmp .Lf8f292_0008f3fa\n"
        ".Lf8f292_0008f4e9:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %edx, (%esp)\n"
        "calll MT_Free\n"
        "movl -0x24(%ebp), %edx\n"
        "movl 8(%edx), %eax\n"
        "jmp .Lf8f292_0008f3fa\n"
    );
}

/* line 3960 */
__attribute__((naked))
unsigned int Scr_EvalArrayRef(unsigned int parentId)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3960 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %eax\n" /* parentId */
        /* { scope 1 */
        "cmpl $0xfffe, %eax\n" /* line 3969 */
        "je .Lf8f504_0008f65f\n"
        "shll $4, %eax\n" /* line 4003 */
        "addl $scrVarGlob, %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* parentValue */
        "movl 8(%eax), %eax\n" /* line 4006 */
        "movl %eax, %ebx\n" /* line 4008 | parentValue */
        "andl $0x1f, %ebx\n" /* parentValue */
        "jne .Lf8f504_0008f609\n"
        "movl -0x30(%ebp), %edx\n" /* parentValue */
        "orl $1, %eax\n" /* line 4012 */
        "movl %eax, 8(%edx)\n"
        "movzwl scrVarGlob+4, %edi\n" /* line 1503 | name */
        "testw %di, %di\n" /* line 1504 | name */
        "je .Lf8f504_0008f805\n"
        ".Lf8f504_0008f54d:\n"
        "movzwl %di, %esi\n" /* line 1507 | name, entryValue */
        "shll $4, %esi\n" /* entryValue */
        "leal scrVarGlob(%esi), %ebx\n" /* entryValue, parentValue */
        "movzwl scrVarGlob(%esi), %eax\n" /* line 1508 | entryValue */
        "movw %ax, -0x22(%ebp)\n"
        "movzwl %ax, %eax\n"
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movzwl 4(%ecx), %edx\n" /* line 1511 */
        "movw %dx, -0x20(%ebp)\n"
        "cmpl %ecx, %ebx\n" /* line 1514 | parentValue */
        "je .Lf8f504_0008f8f0\n"
        "testb $0x60, 8(%ebx)\n" /* parentValue */
        "jne .Lf8f504_0008f773\n"
        "movzwl 0xc(%ebx), %edx\n" /* line 1518 | parentValue */
        "shll $4, %edx\n"
        "movzwl -0x22(%ebp), %eax\n"
        "movw %ax, scrVarGlob(%edx)\n"
        "movw %di, scrVarGlob(%esi)\n" /* line 1519 | name, entryValue */
        "movzwl 0xc(%ebx), %edx\n" /* line 1520 | parentValue */
        "movw %dx, 0xc(%ecx)\n"
        "movzwl 4(%ebx), %eax\n" /* line 1521 | parentValue */
        "movw %ax, 4(%ecx)\n"
        "movl %ebx, %ecx\n" /* parentValue */
        "movl -0x20(%ebp), %eax\n"
        ".Lf8f504_0008f5b8:\n"
        "movw %ax, scrVarGlob+4\n" /* line 1526 */
        "movzwl %ax, %eax\n" /* line 1527 */
        "shll $4, %eax\n"
        "movw $0, scrVarGlob+2(%eax)\n"
        "movw %di, 0xc(%ecx)\n" /* line 1529 | name */
        "movw %di, 0xe(%ecx)\n" /* line 1530 | name */
        "movw %di, 2(%ebx)\n" /* line 1531 | name, parentValue */
        "movzwl (%ebx), %edx\n" /* line 1657 | parentValue */
        "movl %edx, %eax\n" /* line 1658 */
        "shll $4, %eax\n"
        "addl $scrVarGlob, %eax\n"
        "movl $0x76, 8(%eax)\n" /* line 1661 */
        "movw $0, 4(%eax)\n" /* line 1662 */
        "movw $0, 6(%eax)\n" /* line 1663 */
        "movl -0x30(%ebp), %eax\n" /* line 4013 | parentValue */
        "movl %edx, 4(%eax)\n"
        /* } scope */
        ".Lf8f504_0008f5ff:\n"
        "movl %edx, %eax\n" /* line 4067 */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf8f504_0008f609:\n"
        "movl -0x30(%ebp), %edx\n" /* line 4017 | parentValue */
        "movl 4(%edx), %esi\n" /* varValue */
        ".Lf8f504_0008f60f:\n"
        "cmpl $1, %ebx\n" /* line 4021 | parentValue */
        "je .Lf8f504_0008f8c2\n"
        ".Lf8f504_0008f618:\n"
        "movl $1, scrVarPub+20\n" /* line 4025 */
        "cmpl $2, %ebx\n" /* line 4027 | parentValue */
        "je .Lf8f504_0008f8f7\n"
        "cmpl $4, %ebx\n" /* parentValue */
        "je .Lf8f504_0008f88f\n"
        "movl var_typename(, %ebx, 4), %eax\n" /* line 4038 */
        ".Lf8f504_0008f63b:\n"
        "movl %eax, 4(%esp)\n" /* line 4051 */
        "movl $str_0021d560, (%esp)\n" /* "%s is not an array" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "xorl %edx, %edx\n"
        /* } scope */
        "movl %edx, %eax\n" /* line 4067 */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf8f504_0008f65f:\n"
        "movl scrVarPub+64, %ebx\n" /* line 3971 | parentValue */
        "movl %ebx, %eax\n" /* parentValue */
        "shll $4, %eax\n"
        "addl $scrVarGlob, %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* entValue */
        "movl 8(%eax), %eax\n" /* line 3974 */
        "shrl $8, %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl scrVarPub+68, %edx\n" /* line 1980 */
        "movl %edx, -0x40(%ebp)\n"
        "movl %edx, %edi\n" /* name */
        "addl $0x00800000, %edi\n" /* name */
        "andl $0x00FFFFFF, %edi\n" /* name */
        "leal (%eax, %eax, 2), %eax\n" /* line 801 */
        "movzwl g_classMap(, %eax, 4), %ecx\n" /* index */
        "addl %edi, %ecx\n" /* name, index */
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n" /* index */
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n" /* index */
        "addl $1, %ecx\n" /* index */
        "movzwl %cx, %ecx\n" /* index */
        /* { scope 2: entry */
        /* { scope 3 */
        "movl %ecx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl %edx, -0x28(%ebp)\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %esi\n" /* entryValue */
        "movl 8(%esi), %edx\n" /* line 748 | entryValue */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf8f504_0008f816\n"
        ".Lf8f504_0008f6ec:\n"
        "xorl %ecx, %ecx\n" /* line 759 */
        /* } scope */
        /* } scope */
        ".Lf8f504_0008f6ee:\n"
        "shll $4, %ecx\n" /* line 1986 */
        "movzwl scrVarGlob(%ecx), %eax\n"
        "movzwl %ax, %edx\n"
        "testw %ax, %ax\n" /* line 3975 */
        "je .Lf8f504_0008f77b\n"
        "shll $4, %edx\n" /* line 3977 */
        "movl scrVarGlob+4(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x2c(%ebp), %edx\n" /* entValue */
        "movzwl 6(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll GetEntityFieldValue\n"
        "movl %eax, %esi\n" /* varValue */
        "movl %edx, %ebx\n" /* parentValue */
        "testl %edx, %edx\n" /* line 3978 */
        "je .Lf8f504_0008f90a\n"
        "cmpl $1, %edx\n" /* line 3980 */
        "je .Lf8f504_0008f8a2\n"
        "cmpl $3, %edx\n" /* line 1946 */
        "jle .Lf8f504_0008f92e\n"
        "cmpl $4, %edx\n"
        "jne .Lf8f504_0008f93f\n"
        "movl %eax, %edx\n" /* line 1956 | vectorValue */
        /* { scope 2: entry */
        "cmpb $0, -1(%eax)\n" /* line 1901 */
        "jne .Lf8f504_0008f769\n"
        "leal -4(%eax), %ecx\n" /* line 1916 */
        "movzwl -4(%eax), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf8f504_0008fa8d\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        /* } scope */
        /* { scope 2: entry */
        /* { scope 3 */
        ".Lf8f504_0008f769:\n"
        "movl $4, %ebx\n" /* line 766 */
        "jmp .Lf8f504_0008f618\n"
        ".Lf8f504_0008f773:\n"
        "movl -0x20(%ebp), %eax\n"
        "jmp .Lf8f504_0008f5b8\n"
        ".Lf8f504_0008f77b:\n"
        "movl -0x40(%ebp), %ecx\n"
        /* } scope */
        /* } scope */
        ".Lf8f504_0008f77e:\n"
        "addl %ebx, %ecx\n" /* line 1096 | parentValue */
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n"
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n"
        "addl $1, %ecx\n"
        /* { scope 2: entry */
        /* { scope 3 */
        "movl -0x40(%ebp), %edx\n" /* line 1033 */
        "movl %ebx, %eax\n" /* parentValue */
        "calll GetNewVariableIndexInternal3\n"
        "shll $4, %ebx\n" /* line 1035 | parentValue */
        "addl $scrVarGlob, %ebx\n" /* parentValue */
        "movzwl 0xe(%ebx), %edx\n" /* line 1037 | parentValue */
        "movl %eax, %esi\n" /* line 1040 | entryValue */
        "shll $4, %esi\n" /* entryValue */
        "movzwl scrVarGlob(%esi), %ecx\n" /* line 1043 | entryValue */
        "shll $4, %ecx\n"
        "movw %dx, scrVarGlob+14(%ecx)\n"
        "shll $4, %edx\n" /* line 1044 */
        "movw %ax, scrVarGlob+2(%edx)\n"
        "movzwl 0xc(%ebx), %edx\n" /* line 1046 | parentValue */
        "movw %dx, scrVarGlob+2(%esi)\n" /* entryValue */
        "movw %ax, 0xe(%ebx)\n" /* line 1047 | parentValue */
        /* } scope */
        /* } scope */
        "addl $scrVarGlob, %ecx\n" /* line 3998 */
        "movl %ecx, -0x30(%ebp)\n" /* parentValue */
        "movl 8(%ecx), %eax\n"
        "movl %ecx, %edx\n"
        "orl $1, %eax\n" /* line 4012 */
        "movl %eax, 8(%edx)\n"
        "movzwl scrVarGlob+4, %edi\n" /* line 1503 | name */
        "testw %di, %di\n" /* line 1504 | name */
        "jne .Lf8f504_0008f54d\n"
        ".Lf8f504_0008f805:\n"
        "movl $str_0021d3d8, (%esp)\n" /* line 1505 */
        "calll Scr_TerminalError\n"
        "jmp .Lf8f504_0008f54d\n"
        /* { scope 2: entry */
        /* { scope 3 */
        ".Lf8f504_0008f816:\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, %edi\n"
        "je .Lf8f504_0008f6ee\n"
        "movzwl 0xc(%esi), %ecx\n" /* line 757 | entryValue */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x28(%ebp)\n" /* line 759 | entry */
        "je .Lf8f504_0008f6ec\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %edi, %eax\n"
        "jne .Lf8f504_0008f876\n"
        "jmp .Lf8f504_0008f6ee\n"
        ".Lf8f504_0008f858:\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, %edi\n"
        "je .Lf8f504_0008f6ee\n"
        ".Lf8f504_0008f876:\n"
        "movzwl 0xc(%edx), %ecx\n" /* line 771 */
        "movl %ecx, %edx\n" /* line 772 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x28(%ebp)\n" /* line 759 | entry */
        "jne .Lf8f504_0008f858\n"
        "jmp .Lf8f504_0008f6ec\n"
        /* } scope */
        /* } scope */
        ".Lf8f504_0008f88f:\n"
        "movl $str_0021d60c, (%esp)\n" /* line 4034 */
        "calll Scr_Error\n"
        "xorl %edx, %edx\n"
        "jmp .Lf8f504_0008f5ff\n"
        ".Lf8f504_0008f8a2:\n"
        "shll $4, %eax\n" /* line 3982 */
        "cmpw $0, scrVarGlob+4(%eax)\n"
        "je .Lf8f504_0008fa42\n"
        ".Lf8f504_0008f8b3:\n"
        "movl %esi, (%esp)\n" /* line 1949 | entryValue */
        "calll RemoveRefToObject\n"
        "movl $0, -0x30(%ebp)\n" /* parentValue */
        ".Lf8f504_0008f8c2:\n"
        "movl %esi, -0x34(%ebp)\n" /* line 4043 | varValue */
        "movl %esi, %eax\n" /* varValue */
        "shll $4, %eax\n"
        "addl $scrVarGlob, %eax\n"
        "movl 8(%eax), %edx\n" /* line 4048 */
        "andl $0x1f, %edx\n"
        "cmpl $0x16, %edx\n"
        "je .Lf8f504_0008f920\n"
        "movl $1, scrVarPub+20\n" /* line 4050 */
        "movl var_typename(, %edx, 4), %eax\n" /* line 4051 */
        "jmp .Lf8f504_0008f63b\n"
        ".Lf8f504_0008f8f0:\n"
        "movl %edx, %eax\n"
        "jmp .Lf8f504_0008f5b8\n"
        ".Lf8f504_0008f8f7:\n"
        "movl $str_0021d5d8, (%esp)\n" /* line 4030 */
        "calll Scr_Error\n"
        "xorl %edx, %edx\n"
        "jmp .Lf8f504_0008f5ff\n"
        ".Lf8f504_0008f90a:\n"
        "movl scrVarPub+64, %ebx\n" /* parentValue */
        "movl scrVarPub+68, %edx\n"
        "movl %edx, -0x40(%ebp)\n"
        "movl %edx, %ecx\n"
        "jmp .Lf8f504_0008f77e\n"
        ".Lf8f504_0008f920:\n"
        "cmpw $0, 4(%eax)\n" /* line 4055 */
        "jne .Lf8f504_0008f94b\n"
        "movl %esi, %edx\n" /* line 4066 | varValue */
        "jmp .Lf8f504_0008f5ff\n"
        ".Lf8f504_0008f92e:\n"
        "cmpl $2, %edx\n" /* line 1946 */
        "jl .Lf8f504_0008fa67\n"
        "movl %eax, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        ".Lf8f504_0008f93f:\n"
        "movl $0, -0x30(%ebp)\n" /* parentValue */
        "jmp .Lf8f504_0008f60f\n"
        ".Lf8f504_0008f94b:\n"
        "movl %esi, (%esp)\n" /* line 4058 | varValue */
        "calll RemoveRefToObject\n"
        "movzwl scrVarGlob+4, %eax\n" /* line 1503 */
        "movw %ax, -0x1c(%ebp)\n"
        "testw %ax, %ax\n" /* line 1504 */
        "je .Lf8f504_0008fa75\n"
        ".Lf8f504_0008f967:\n"
        "movzwl -0x1c(%ebp), %edx\n" /* line 1507 */
        "shll $4, %edx\n"
        "movl %edx, -0x3c(%ebp)\n"
        "movl %edx, %ebx\n" /* parentValue */
        "addl $scrVarGlob, %ebx\n" /* parentValue */
        "movzwl scrVarGlob(%edx), %eax\n" /* line 1508 */
        "movw %ax, -0x1e(%ebp)\n"
        "movzwl %ax, %eax\n"
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movzwl 4(%ecx), %edx\n" /* line 1511 */
        "movw %dx, -0x1a(%ebp)\n"
        "cmpl %ecx, %ebx\n" /* line 1514 | parentValue */
        "je .Lf8f504_0008fa86\n"
        "testb $0x60, 8(%ebx)\n" /* parentValue */
        "jne .Lf8f504_0008fa3c\n"
        "movzwl 0xc(%ebx), %edx\n" /* line 1518 | parentValue */
        "shll $4, %edx\n"
        "movzwl -0x1e(%ebp), %eax\n"
        "movw %ax, scrVarGlob(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1519 */
        "movl -0x3c(%ebp), %edx\n"
        "movw %ax, scrVarGlob(%edx)\n"
        "movzwl 0xc(%ebx), %edx\n" /* line 1520 | parentValue */
        "movw %dx, 0xc(%ecx)\n"
        "movzwl 4(%ebx), %eax\n" /* line 1521 | parentValue */
        "movw %ax, 4(%ecx)\n"
        "movl %ebx, %ecx\n" /* parentValue */
        "movzwl -0x1a(%ebp), %eax\n"
        ".Lf8f504_0008f9df:\n"
        "movw %ax, scrVarGlob+4\n" /* line 1526 */
        "movzwl %ax, %eax\n" /* line 1527 */
        "shll $4, %eax\n"
        "movw $0, scrVarGlob+2(%eax)\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1529 */
        "movw %dx, 0xc(%ecx)\n"
        "movw %dx, 0xe(%ecx)\n" /* line 1530 */
        "movw %dx, 2(%ebx)\n" /* line 1531 | parentValue */
        "movzwl (%ebx), %ebx\n" /* line 1657 | parentValue */
        "movl %ebx, %eax\n" /* line 1658 | parentValue */
        "shll $4, %eax\n"
        "addl $scrVarGlob, %eax\n"
        "movl $0x76, 8(%eax)\n" /* line 1661 */
        "movw $0, 4(%eax)\n" /* line 1662 */
        "movw $0, 6(%eax)\n" /* line 1663 */
        "movl %ebx, %esi\n" /* line 4059 | parentValue, varValue */
        "movl %ebx, %edx\n" /* line 4060 | parentValue */
        "movl -0x34(%ebp), %eax\n"
        "calll CopyArray\n"
        "movl -0x30(%ebp), %eax\n" /* line 4062 | parentValue */
        "movl %ebx, 4(%eax)\n" /* parentValue */
        "movl %esi, %edx\n" /* line 4066 | varValue */
        "jmp .Lf8f504_0008f5ff\n"
        ".Lf8f504_0008fa3c:\n"
        "movzwl -0x1a(%ebp), %eax\n"
        "jmp .Lf8f504_0008f9df\n"
        ".Lf8f504_0008fa42:\n"
        "movl %esi, (%esp)\n" /* line 1949 | entryValue */
        "calll RemoveRefToObject\n"
        "movl $1, scrVarPub+20\n" /* line 3985 */
        "movl $str_0021d5b4, (%esp)\n" /* line 3986 */
        "calll Scr_Error\n"
        "xorl %edx, %edx\n"
        "jmp .Lf8f504_0008f5ff\n"
        ".Lf8f504_0008fa67:\n"
        "cmpl $1, %edx\n" /* line 1946 */
        "jne .Lf8f504_0008f93f\n"
        "jmp .Lf8f504_0008f8b3\n"
        ".Lf8f504_0008fa75:\n"
        "movl $str_0021d3d8, (%esp)\n" /* line 1505 */
        "calll Scr_TerminalError\n"
        "jmp .Lf8f504_0008f967\n"
        ".Lf8f504_0008fa86:\n"
        "movl %edx, %eax\n"
        "jmp .Lf8f504_0008f9df\n"
        /* { scope 2: entry */
        ".Lf8f504_0008fa8d:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        /* } scope */
        /* { scope 2: entry */
        /* { scope 3 */
        "movl $4, %ebx\n" /* line 766 */
        "jmp .Lf8f504_0008f618\n"
    );
}

/* line 1312 */
__attribute__((naked))
JCOEF Scr_StopThread(unsigned int threadId)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1312 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1299 | threadId */
        "shll $4, %eax\n"
        "addl $scrVarGlob, %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* parentValue */
        "movzwl 0xe(%eax), %eax\n" /* line 1305 */
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %edx\n"
        "cmpl %edx, 8(%ebp)\n" /* threadId */
        "je .Lf8faa8_0008fc04\n"
        /* { scope 2 */
        "leal scrVarGlob(%eax), %ecx\n" /* line 1249 */
        "movl %edx, %ebx\n" /* line 1250 | nextId */
        ".Lf8faa8_0008fade:\n"
        "movl -0x20(%ebp), %edx\n" /* line 1253 | parentValue */
        "movl %ecx, %eax\n"
        "calll MakeVariableExternal\n"
        "shll $4, %ebx\n" /* line 1254 | nextId */
        "movzwl scrVarGlob+14(%ebx), %eax\n" /* nextId */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movzwl scrVarGlob(%eax), %ebx\n" /* line 1255 | nextId */
        "cmpl %ebx, 8(%ebp)\n" /* line 1251 | nextId, threadId */
        "jne .Lf8faa8_0008fade\n"
        "movl -0x20(%ebp), %edx\n" /* line 1258 | parentValue */
        "movzwl 0xe(%edx), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %eax\n"
        "cmpl %eax, 8(%ebp)\n" /* line 1259 | threadId */
        "jne .Lf8faa8_0008fba8\n"
        "jmp .Lf8faa8_0008fc07\n"
        /* { scope 3 */
        /* { scope 4 */
        ".Lf8faa8_0008fb26:\n"
        "cmpl $2, %eax\n" /* line 1946 */
        "jl .Lf8faa8_0008fc39\n"
        "movl %edx, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        /* } scope */
        /* { scope 4 */
        /* { scope 5 */
        ".Lf8faa8_0008fb37:\n"
        "movzwl 0xc(%edi), %ebx\n" /* line 1578 | index */
        "movzwl %bx, %ecx\n" /* line 1579 | index */
        "shll $4, %ecx\n"
        "addl $scrVarGlob, %ecx\n"
        "movzwl 2(%ecx), %edx\n" /* line 1581 */
        "movzwl 0xe(%edi), %esi\n" /* line 1582 | nextSiblingIndex */
        "movzwl %si, %eax\n" /* line 1583 | nextSiblingIndex */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+2(%eax)\n"
        "shll $4, %edx\n" /* line 1584 */
        "movzwl scrVarGlob(%edx), %eax\n"
        "shll $4, %eax\n"
        "movw %si, scrVarGlob+14(%eax)\n" /* nextSiblingIndex */
        "movl $0, 8(%edi)\n" /* line 1586 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1587 */
        "movw %ax, 4(%edi)\n"
        "movw $0, 2(%ecx)\n" /* line 1588 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1590 */
        "shll $4, %eax\n"
        "movw %bx, scrVarGlob+2(%eax)\n" /* index */
        "movw %bx, scrVarGlob+4\n" /* line 1591 | index */
        /* } scope */
        /* } scope */
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 1259 */
        "cmpl %eax, 8(%ebp)\n" /* threadId */
        "je .Lf8faa8_0008fc04\n"
        ".Lf8faa8_0008fba8:\n"
        "movl %eax, %edx\n" /* line 1262 */
        "shll $4, %edx\n"
        "movzwl scrVarGlob+14(%edx), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        /* { scope 3 */
        "leal scrVarGlob(%edx), %edi\n" /* line 1721 | entryValue */
        "movl 4(%edi), %edx\n" /* line 1727 | entryValue */
        "movl 8(%edi), %eax\n" /* entryValue, type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 4 */
        "cmpl $3, %eax\n" /* line 1946 */
        "jle .Lf8faa8_0008fb26\n"
        "cmpl $4, %eax\n"
        "jne .Lf8faa8_0008fb37\n"
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf8faa8_0008fb37\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf8faa8_0008fc4f\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        "jmp .Lf8faa8_0008fb37\n"
        ".Lf8faa8_0008fc04:\n"
        "movl -0x20(%ebp), %edx\n" /* parentValue */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf8faa8_0008fc07:\n"
        "movzwl 6(%edx), %eax\n" /* line 1308 */
        "movl %eax, (%esp)\n"
        "calll RemoveRefToObject\n"
        /* } scope */
        "movl scrVarPub+36, %eax\n" /* line 1316 */
        "shll $4, 8(%ebp)\n" /* threadId */
        "movl 8(%ebp), %edx\n" /* threadId */
        "movw %ax, scrVarGlob+6(%edx)\n"
        "shll $4, %eax\n" /* line 1748 */
        "addw $1, scrVarGlob+4(%eax)\n"
        "addl $0x2c, %esp\n" /* line 1318 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf8faa8_0008fc39:\n"
        "subl $1, %eax\n" /* line 1946 */
        "jne .Lf8faa8_0008fb37\n"
        "movl %edx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "jmp .Lf8faa8_0008fb37\n"
        ".Lf8faa8_0008fc4f:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "jmp .Lf8faa8_0008fb37\n"
    );
}

/* line 1268 */
__attribute__((naked))
JCOEF ClearObject(unsigned int parentId)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1268 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 1748 | parentId */
        "shll $4, %eax\n"
        "addw $1, scrVarGlob+4(%eax)\n"
        /* { scope 1 */
        "addl $scrVarGlob, %eax\n" /* line 1245 */
        "movl %eax, -0x20(%ebp)\n" /* parentValue */
        "movzwl 0xe(%eax), %edx\n" /* line 1249 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movzwl scrVarGlob(%eax), %ebx\n" /* line 1250 | nextId */
        "cmpl %ebx, 8(%ebp)\n" /* line 1251 | nextId, parentId */
        "je .Lf8fc64_0008fcce\n"
        ".Lf8fc64_0008fc9e:\n"
        "movl -0x20(%ebp), %edx\n" /* line 1253 | parentValue */
        "movl %ecx, %eax\n"
        "calll MakeVariableExternal\n"
        "shll $4, %ebx\n" /* line 1254 | nextId */
        "movzwl scrVarGlob+14(%ebx), %eax\n" /* nextId */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movzwl scrVarGlob(%eax), %ebx\n" /* line 1255 | nextId */
        "cmpl %ebx, 8(%ebp)\n" /* line 1251 | nextId, parentId */
        "jne .Lf8fc64_0008fc9e\n"
        "movl -0x20(%ebp), %eax\n" /* parentValue */
        "movzwl 0xe(%eax), %edx\n"
        ".Lf8fc64_0008fcce:\n"
        "shll $4, %edx\n" /* line 1258 */
        "movzwl scrVarGlob(%edx), %eax\n"
        "cmpl %eax, 8(%ebp)\n" /* line 1259 | parentId */
        "jne .Lf8fc64_0008fd6a\n"
        "jmp .Lf8fc64_0008fdca\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf8fc64_0008fce6:\n"
        "cmpl $2, %eax\n" /* line 1946 */
        "jl .Lf8fc64_0008fde5\n"
        "movl %edx, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        /* } scope */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf8fc64_0008fcf7:\n"
        "movzwl 0xc(%edi), %ebx\n" /* line 1578 | index */
        "movzwl %bx, %ecx\n" /* line 1579 | index */
        "shll $4, %ecx\n"
        "addl $scrVarGlob, %ecx\n"
        "movzwl 2(%ecx), %edx\n" /* line 1581 */
        "movzwl 0xe(%edi), %esi\n" /* line 1582 | nextSiblingIndex */
        "movzwl %si, %eax\n" /* line 1583 | nextSiblingIndex */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+2(%eax)\n"
        "shll $4, %edx\n" /* line 1584 */
        "movzwl scrVarGlob(%edx), %eax\n"
        "shll $4, %eax\n"
        "movw %si, scrVarGlob+14(%eax)\n" /* nextSiblingIndex */
        "movl $0, 8(%edi)\n" /* line 1586 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1587 */
        "movw %ax, 4(%edi)\n"
        "movw $0, 2(%ecx)\n" /* line 1588 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1590 */
        "shll $4, %eax\n"
        "movw %bx, scrVarGlob+2(%eax)\n" /* index */
        "movw %bx, scrVarGlob+4\n" /* line 1591 | index */
        /* } scope */
        /* } scope */
        /* } scope */
        "movl -0x1c(%ebp), %edx\n" /* line 1259 */
        "cmpl %edx, 8(%ebp)\n" /* parentId */
        "je .Lf8fc64_0008fdca\n"
        "movl %edx, %eax\n"
        ".Lf8fc64_0008fd6a:\n"
        "movl %eax, %edx\n" /* line 1262 */
        "shll $4, %edx\n"
        "movzwl scrVarGlob+14(%edx), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        /* { scope 2 */
        "leal scrVarGlob(%edx), %edi\n" /* line 1721 | entryValue */
        "movl 4(%edi), %edx\n" /* line 1727 | entryValue */
        "movl 8(%edi), %eax\n" /* entryValue, type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 3 */
        "cmpl $3, %eax\n" /* line 1946 */
        "jle .Lf8fc64_0008fce6\n"
        "cmpl $4, %eax\n"
        "jne .Lf8fc64_0008fcf7\n"
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf8fc64_0008fcf7\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf8fc64_0008fe71\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        "jmp .Lf8fc64_0008fcf7\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf8fc64_0008fdca:\n"
        "movl -0x20(%ebp), %edx\n" /* line 1812 | parentValue */
        "movzwl 4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf8fc64_0008fdfb\n"
        "subl $1, %eax\n" /* line 1821 */
        "movw %ax, 4(%edx)\n"
        "addl $0x2c, %esp\n" /* line 1276 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf8fc64_0008fde5:\n"
        "subl $1, %eax\n" /* line 1946 */
        "jne .Lf8fc64_0008fcf7\n"
        "movl %edx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "jmp .Lf8fc64_0008fcf7\n"
        ".Lf8fc64_0008fdfb:\n"
        "movl %edx, %eax\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1 */
        "movzwl 0xc(%edx), %ebx\n" /* line 1578 | index */
        "movzwl %bx, %ecx\n" /* line 1579 | index */
        "shll $4, %ecx\n"
        "addl $scrVarGlob, %ecx\n"
        "movzwl 2(%ecx), %edx\n" /* line 1581 */
        "movzwl 0xe(%eax), %esi\n" /* line 1582 | nextSiblingIndex */
        "movzwl %si, %eax\n" /* line 1583 | nextSiblingIndex */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+2(%eax)\n"
        "shll $4, %edx\n" /* line 1584 */
        "movzwl scrVarGlob(%edx), %eax\n"
        "shll $4, %eax\n"
        "movw %si, scrVarGlob+14(%eax)\n" /* nextSiblingIndex */
        "movl -0x20(%ebp), %edx\n" /* line 1586 | parentValue */
        "movl $0, 8(%edx)\n"
        "movzwl scrVarGlob+4, %eax\n" /* line 1587 */
        "movw %ax, 4(%edx)\n"
        "movw $0, 2(%ecx)\n" /* line 1588 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1590 */
        "shll $4, %eax\n"
        "movw %bx, scrVarGlob+2(%eax)\n" /* index */
        "movw %bx, scrVarGlob+4\n" /* line 1591 | index */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1276 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf8fc64_0008fe71:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "jmp .Lf8fc64_0008fcf7\n"
    );
}

/* line 1425 */
__attribute__((naked))
JCOEF Scr_KillThread(unsigned int parentId)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1425 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1: name, name */
        "movl 8(%ebp), %eax\n" /* line 1435 | parentId */
        "shll $4, %eax\n"
        "addl $scrVarGlob, %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* parentValue */
        "movzwl 0xe(%eax), %eax\n" /* line 1305 */
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %edx\n"
        "cmpl %edx, 8(%ebp)\n" /* parentId */
        "je .Lf8fe86_0008ffe6\n"
        /* { scope 2: entry */
        "leal scrVarGlob(%eax), %ecx\n" /* line 1249 */
        "movl %edx, %ebx\n" /* line 1250 | nextId */
        ".Lf8fe86_0008febc:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 1253 | parentValue */
        "movl %ecx, %eax\n"
        "calll MakeVariableExternal\n"
        "shll $4, %ebx\n" /* line 1254 | nextId */
        "movzwl scrVarGlob+14(%ebx), %eax\n" /* nextId */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movzwl scrVarGlob(%eax), %ebx\n" /* line 1255 | nextId */
        "cmpl %ebx, 8(%ebp)\n" /* line 1251 | nextId, parentId */
        "jne .Lf8fe86_0008febc\n"
        "movl -0x2c(%ebp), %edx\n" /* line 1258 | parentValue */
        "movzwl 0xe(%edx), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %eax\n"
        "cmpl %eax, 8(%ebp)\n" /* line 1259 | parentId */
        "jne .Lf8fe86_0008ff86\n"
        "jmp .Lf8fe86_0008ffe9\n"
        /* { scope 3 */
        /* { scope 4 */
        ".Lf8fe86_0008ff04:\n"
        "cmpl $2, %eax\n" /* line 1946 */
        "jl .Lf8fe86_00090208\n"
        "movl %edx, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        /* } scope */
        /* { scope 4 */
        /* { scope 5 */
        ".Lf8fe86_0008ff15:\n"
        "movzwl 0xc(%edi), %ebx\n" /* line 1578 | selfNameId, index */
        "movzwl %bx, %ecx\n" /* line 1579 | index */
        "shll $4, %ecx\n"
        "addl $scrVarGlob, %ecx\n"
        "movzwl 2(%ecx), %edx\n" /* line 1581 */
        "movzwl 0xe(%edi), %esi\n" /* line 1582 | selfNameId, nextSiblingIndex */
        "movzwl %si, %eax\n" /* line 1583 | nextSiblingIndex */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+2(%eax)\n"
        "shll $4, %edx\n" /* line 1584 */
        "movzwl scrVarGlob(%edx), %eax\n"
        "shll $4, %eax\n"
        "movw %si, scrVarGlob+14(%eax)\n" /* nextSiblingIndex */
        "movl $0, 8(%edi)\n" /* line 1586 | selfNameId */
        "movzwl scrVarGlob+4, %eax\n" /* line 1587 */
        "movw %ax, 4(%edi)\n" /* selfNameId */
        "movw $0, 2(%ecx)\n" /* line 1588 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1590 */
        "shll $4, %eax\n"
        "movw %bx, scrVarGlob+2(%eax)\n" /* index */
        "movw %bx, scrVarGlob+4\n" /* line 1591 | index */
        /* } scope */
        /* } scope */
        /* } scope */
        "movl -0x1c(%ebp), %eax\n" /* line 1259 */
        "cmpl %eax, 8(%ebp)\n" /* parentId */
        "je .Lf8fe86_0008ffe6\n"
        ".Lf8fe86_0008ff86:\n"
        "movl %eax, %edx\n" /* line 1262 */
        "shll $4, %edx\n"
        "movzwl scrVarGlob+14(%edx), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        /* { scope 3 */
        "leal scrVarGlob(%edx), %edi\n" /* line 1721 | entryValue */
        "movl 4(%edi), %edx\n" /* line 1727 | entryValue */
        "movl 8(%edi), %eax\n" /* entryValue, type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 4 */
        "cmpl $3, %eax\n" /* line 1946 */
        "jle .Lf8fe86_0008ff04\n"
        "cmpl $4, %eax\n"
        "jne .Lf8fe86_0008ff15\n"
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf8fe86_0008ff15\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf8fe86_0009029a\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        "jmp .Lf8fe86_0008ff15\n"
        ".Lf8fe86_0008ffe6:\n"
        "movl -0x2c(%ebp), %edx\n" /* parentValue */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf8fe86_0008ffe9:\n"
        "movzwl 6(%edx), %eax\n" /* line 1308 */
        "movl %eax, (%esp)\n"
        "calll RemoveRefToObject\n"
        "movl 8(%ebp), %eax\n" /* line 1998 | parentId */
        "addl $0x10000, %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* name */
        "movl scrVarPub+32, %esi\n" /* line 801 | entryValue */
        "movl %eax, %ecx\n" /* index */
        "addl %esi, %ecx\n" /* entryValue, index */
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n" /* index */
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n" /* index */
        "addl $1, %ecx\n" /* index */
        "movzwl %cx, %ecx\n" /* index */
        /* { scope 2: entry */
        /* { scope 3 */
        "movl %ecx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edi\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ebx\n" /* entryValue */
        "movl 8(%ebx), %edx\n" /* line 748 | entryValue */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf8fe86_000901ae\n"
        ".Lf8fe86_00090054:\n"
        "xorl %ecx, %ecx\n" /* line 759 */
        /* } scope */
        /* } scope */
        ".Lf8fe86_00090056:\n"
        "shll $4, %ecx\n" /* line 1998 */
        "movzwl scrVarGlob(%ecx), %eax\n"
        "movzwl %ax, %edx\n"
        "testw %ax, %ax\n" /* line 1444 */
        "je .Lf8fe86_00090197\n"
        "shll $4, %edx\n" /* line 2743 */
        "movl scrVarGlob+4(%edx), %edi\n" /* entryValue */
        "movl %edi, %eax\n" /* line 2654 | entryValue */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "cmpl %ecx, %edi\n" /* line 2660 | entryValue */
        "je .Lf8fe86_00090188\n"
        ".Lf8fe86_00090093:\n"
        "movl %ecx, %eax\n" /* line 2665 */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %edx\n"
        "movl %edx, %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0xe, %eax\n"
        "ja .Lf8fe86_00090182\n"
        "testl %ecx, %ecx\n" /* line 1450 */
        "je .Lf8fe86_00090182\n"
        "shrl $8, %edx\n" /* line 1456 */
        "movzwl %dx, %ebx\n" /* threadId */
        "leal 0x10000(%ebx), %edx\n" /* line 1998 | index */
        "movl %edx, -0x24(%ebp)\n" /* name */
        "leal (%edi, %edx), %ecx\n" /* line 801 | entry, index */
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n" /* index */
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n" /* index */
        "addl $1, %ecx\n" /* index */
        "movzwl %cx, %ecx\n" /* index */
        /* { scope 2: entry */
        /* { scope 3 */
        "movl %ecx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %esi\n" /* entryValue */
        "movl 8(%esi), %edx\n" /* line 748 | entryValue */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf8fe86_0009021e\n"
        ".Lf8fe86_00090113:\n"
        "xorl %ecx, %ecx\n" /* line 759 */
        /* } scope */
        /* } scope */
        ".Lf8fe86_00090115:\n"
        "movl %ebx, 4(%esp)\n" /* line 1458 | threadId */
        "shll $4, %ecx\n"
        "movzwl scrVarGlob(%ecx), %eax\n"
        "shll $4, %eax\n"
        "movl scrVarGlob+4(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll VM_CancelNotify\n"
        /* { scope 2: entry */
        "shll $4, %ebx\n" /* line 1477 | parentValue */
        "addl $scrVarGlob, %ebx\n" /* parentValue */
        "movzwl 6(%ebx), %eax\n" /* line 1482 | parentValue */
        "movl %eax, (%esp)\n"
        "calll RemoveRefToObject\n"
        "movl 8(%ebx), %eax\n" /* line 1488 | parentValue */
        "andl $0xffffffe0, %eax\n"
        "orl $0x17, %eax\n"
        "movl %eax, 8(%ebx)\n" /* parentValue */
        /* } scope */
        "movl -0x24(%ebp), %eax\n" /* line 2302 | name */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* entryValue */
        "calll RemoveVariable\n"
        "movl %edi, %eax\n" /* line 2654 | entryValue */
        "shll $4, %eax\n"
        "movzwl scrVarGlob+14(%eax), %eax\n"
        "shll $4, %eax\n"
        "movzwl scrVarGlob(%eax), %ecx\n"
        "cmpl %edi, %ecx\n" /* line 2660 | entryValue */
        "jne .Lf8fe86_00090093\n"
        ".Lf8fe86_00090182:\n"
        "movl scrVarPub+32, %esi\n" /* nextSiblingIndex */
        ".Lf8fe86_00090188:\n"
        "movl -0x28(%ebp), %edx\n" /* line 2302 | name */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* nextSiblingIndex */
        "calll RemoveVariable\n"
        ".Lf8fe86_00090197:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 1469 | parentValue */
        "movl 8(%edx), %eax\n"
        "andl $0xffffffe0, %eax\n"
        "orl $0x17, %eax\n"
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1470 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: name, name */
        /* { scope 2: entry */
        /* { scope 3 */
        ".Lf8fe86_000901ae:\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, -0x28(%ebp)\n" /* name */
        "je .Lf8fe86_00090056\n"
        "movzwl 0xc(%ebx), %ecx\n" /* line 757 | entryValue */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, %edi\n" /* line 759 | entry */
        "je .Lf8fe86_00090054\n"
        ".Lf8fe86_000901d1:\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, -0x28(%ebp)\n" /* name */
        "je .Lf8fe86_00090056\n"
        "movzwl 0xc(%edx), %ecx\n" /* line 771 */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, %edi\n" /* line 759 | entry */
        "jne .Lf8fe86_000901d1\n"
        "jmp .Lf8fe86_00090054\n"
        /* } scope */
        /* } scope */
        /* { scope 2: entry */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf8fe86_00090208:\n"
        "subl $1, %eax\n" /* line 1946 */
        "jne .Lf8fe86_0008ff15\n"
        "movl %edx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "jmp .Lf8fe86_0008ff15\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: entry */
        /* { scope 3 */
        ".Lf8fe86_0009021e:\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, -0x24(%ebp)\n" /* name */
        "je .Lf8fe86_00090115\n"
        "movzwl 0xc(%esi), %ecx\n" /* line 757 | entryValue */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x20(%ebp)\n" /* line 759 | entry */
        "je .Lf8fe86_00090113\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %eax, -0x24(%ebp)\n" /* name */
        "jne .Lf8fe86_00090281\n"
        "jmp .Lf8fe86_00090115\n"
        ".Lf8fe86_00090262:\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl -0x24(%ebp), %eax\n" /* name */
        "je .Lf8fe86_00090115\n"
        ".Lf8fe86_00090281:\n"
        "movzwl 0xc(%edx), %ecx\n" /* line 771 */
        "movl %ecx, %edx\n" /* line 772 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x20(%ebp)\n" /* line 759 | entry */
        "jne .Lf8fe86_00090262\n"
        "jmp .Lf8fe86_00090113\n"
        /* } scope */
        /* } scope */
        /* { scope 2: entry */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf8fe86_0009029a:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "jmp .Lf8fe86_0008ff15\n"
    );
}

/* line 2957 */
__attribute__((naked))
unsigned int Scr_EvalFieldObject(unsigned int tempVariable, VariableValue *value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2957 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl $0, -0x10(%ebp)\n" /* tempValue */
        "movl $0, -0xc(%ebp)\n"
        "movl 0xc(%ebp), %eax\n" /* value */
        /* { scope 1 */
        "movl 4(%eax), %edx\n" /* line 2962 */
        "cmpl $1, %edx\n" /* line 2963 */
        "je .Lf902b0_00090339\n"
        /* { scope 2 */
        "movl %edx, %ebx\n" /* line 2973 | type */
        "movl (%eax), %edx\n"
        /* } scope */
        "cmpl $3, %ebx\n" /* line 1946 */
        "jg .Lf902b0_00090315\n"
        "cmpl $2, %ebx\n"
        "jl .Lf902b0_00090398\n"
        "movl %edx, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        ".Lf902b0_000902eb:\n"
        "movl var_typename(, %ebx, 4), %eax\n" /* line 2978 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021d344, (%esp)\n" /* "%s is not a field object" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Com_Printf\n" /* non-fatal: warn and return 0 */
        "xorl %esi, %esi\n"
        /* } scope */
        "movl %esi, %eax\n" /* line 2980 */
        "addl $0x20, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf902b0_00090315:\n"
        "cmpl $4, %ebx\n" /* line 1946 */
        "jne .Lf902b0_000902eb\n"
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf902b0_000902eb\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf902b0_000903d1\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        "jmp .Lf902b0_000902eb\n"
        ".Lf902b0_00090339:\n"
        "movl (%eax), %esi\n" /* line 2965 */
        "movl %esi, %edx\n"
        "movl %esi, %eax\n"
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %ebx\n" /* type */
        "andl $0x1f, %ebx\n" /* type */
        "cmpl $0x15, %ebx\n" /* line 2966 | type */
        "jg .Lf902b0_000903a1\n"
        "movl %esi, -0x10(%ebp)\n" /* line 2971 | tempValue */
        /* { scope 2 */
        "shll $4, 8(%ebp)\n" /* line 2409 | tempVariable */
        "movl 8(%ebp), %ebx\n" /* tempVariable, entryValue */
        "addl $scrVarGlob, %ebx\n" /* entryValue */
        "movl 4(%ebx), %ecx\n" /* line 2414 | entryValue */
        "movl 8(%ebx), %eax\n" /* entryValue */
        "movl %eax, %edx\n" /* type */
        "andl $0x1f, %edx\n" /* type */
        /* { scope 3 */
        "cmpl $3, %edx\n" /* line 1946 */
        "jg .Lf902b0_000903ae\n"
        "cmpl $2, %edx\n"
        "jl .Lf902b0_000903e6\n"
        "movl %ecx, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        "movl 8(%ebx), %eax\n"
        /* } scope */
        ".Lf902b0_00090380:\n"
        "andl $0xffffffe0, %eax\n" /* line 2417 */
        "orl $1, %eax\n"
        "movl %eax, 8(%ebx)\n" /* entryValue */
        "movl -0x10(%ebp), %eax\n" /* line 2418 | tempValue */
        "movl %eax, 4(%ebx)\n" /* entryValue */
        /* } scope */
        /* } scope */
        "movl %esi, %eax\n" /* line 2980 */
        "addl $0x20, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf902b0_00090398:\n"
        "cmpl $1, %ebx\n" /* line 1946 */
        "jne .Lf902b0_000902eb\n"
        ".Lf902b0_000903a1:\n"
        "movl %edx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "jmp .Lf902b0_000902eb\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf902b0_000903ae:\n"
        "cmpl $4, %edx\n" /* line 1946 */
        "jne .Lf902b0_00090380\n"
        "cmpb $0, -1(%ecx)\n" /* line 1901 */
        "jne .Lf902b0_00090380\n"
        "leal -4(%ecx), %edx\n" /* line 1916 */
        "movzwl -4(%ecx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf902b0_000903f8\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%ecx)\n"
        "movl 8(%ebx), %eax\n"
        "jmp .Lf902b0_00090380\n"
        /* } scope */
        /* } scope */
        ".Lf902b0_000903d1:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "jmp .Lf902b0_000902eb\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf902b0_000903e6:\n"
        "subl $1, %edx\n" /* line 1946 */
        "jne .Lf902b0_00090380\n"
        "movl %ecx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "movl 8(%ebx), %eax\n"
        "jmp .Lf902b0_00090380\n"
        ".Lf902b0_000903f8:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %edx, (%esp)\n"
        "calll MT_Free\n"
        "movl 8(%ebx), %eax\n"
        "jmp .Lf902b0_00090380\n"
    );
}

/* line 2823 */
__attribute__((naked))
Bool Scr_CastString(VariableValue *value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2823 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* value */
        /* { scope 1 */
        "movl 4(%esi), %eax\n" /* line 2827 | value */
        "cmpl $2, %eax\n"
        "je .Lf90410_00090481\n"
        "cmpl $6, %eax\n" /* line 2830 */
        "je .Lf90410_000904e4\n"
        "cmpl $5, %eax\n" /* line 2837 */
        "je .Lf90410_00090503\n"
        "cmpl $4, %eax\n" /* line 2844 */
        "je .Lf90410_000904b1\n"
        /* Unhandled types → return empty string (skip Scr_Error + cleanup) */
        "jmp .Lf90410_00090471\n"
        ".Lf90410_00090471:\n"
        "movl $0, 4(%esi)\n" /* line 2855 | value */
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 2857 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf90410_00090481:\n"
        "movl $1, %eax\n" /* line 2856 */
        /* } scope */
        ".Lf90410_00090486:\n"
        "addl $0x10, %esp\n" /* line 2857 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf90410_0009048d:\n"
        "cmpl $4, %eax\n" /* line 1946 */
        "jne .Lf90410_00090471\n"
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf90410_00090471\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf90410_00090552\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        "jmp .Lf90410_00090471\n"
        /* } scope */
        ".Lf90410_000904b1:\n"
        "movl $2, 4(%esi)\n" /* line 2846 | value */
        "movl (%esi), %ebx\n" /* line 2847 | value, constTempVector */
        "movl %ebx, (%esp)\n" /* line 2848 | constTempVector */
        "calll SL_GetStringForVector\n"
        "movl %eax, (%esi)\n" /* value */
        "cmpb $0, -1(%ebx)\n" /* line 1901 */
        "jne .Lf90410_00090481\n"
        "leal -4(%ebx), %edx\n" /* line 1916 */
        "movzwl -4(%ebx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf90410_00090538\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%ebx)\n"
        "movl $1, %eax\n"
        "jmp .Lf90410_00090486\n"
        ".Lf90410_000904e4:\n"
        "movl $2, 4(%esi)\n" /* line 2832 | value */
        "movl (%esi), %eax\n" /* line 2833 | value */
        "movl %eax, (%esp)\n"
        "calll SL_GetStringForInt\n"
        "movl %eax, (%esi)\n" /* value */
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 2857 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf90410_00090503:\n"
        "movl $2, 4(%esi)\n" /* line 2839 | value */
        "movl (%esi), %eax\n" /* line 2840 | value */
        "movl %eax, (%esp)\n"
        "calll SL_GetStringForFloat\n"
        "movl %eax, (%esi)\n" /* value */
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 2857 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf90410_00090522:\n"
        "subl $1, %eax\n" /* line 1946 */
        "jne .Lf90410_00090471\n"
        "movl %edx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "jmp .Lf90410_00090471\n"
        /* } scope */
        ".Lf90410_00090538:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %edx, (%esp)\n"
        "calll MT_Free\n"
        "movl $1, %eax\n"
        "jmp .Lf90410_00090486\n"
        /* { scope 2 */
        ".Lf90410_00090552:\n"
        "movl $0x10, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "jmp .Lf90410_00090471\n"
    );
}

/* line 2860 */
__attribute__((naked))
JCOEF Scr_CastDebugString(VariableValue *value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2860 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* value */
        /* { scope 1 */
        "movl 4(%esi), %eax\n" /* line 2866 | value */
        "cmpl $0xb, %eax\n"
        "ja .Lf90568_00090582\n"
        "jmpl *.Ljt_90568_0(, %eax, 4)\n"
        ".Lf90568_00090582:\n"
        "movl var_typename(, %eax, 4), %eax\n" /* line 2889 */
        ".Lf90568_00090589:\n"
        "movl $0xe, 8(%esp)\n" /* line 2893 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SL_GetString_\n"
        "movl %eax, %ebx\n" /* stringValue */
        "movl (%esi), %edx\n" /* line 252 */
        "movl 4(%esi), %eax\n" /* type */
        /* { scope 2 */
        "cmpl $3, %eax\n" /* line 1946 */
        "jg .Lf90568_000905ce\n"
        "cmpl $2, %eax\n"
        "jl .Lf90568_00090646\n"
        "movl %edx, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        /* } scope */
        ".Lf90568_000905be:\n"
        "movl $2, 4(%esi)\n" /* line 2895 | value */
        "movl %ebx, (%esi)\n" /* line 2896 | stringValue, value */
        /* } scope */
        "addl $0x10, %esp\n" /* line 2897 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf90568_000905ce:\n"
        "cmpl $4, %eax\n" /* line 1946 */
        "jne .Lf90568_000905be\n"
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf90568_000905be\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf90568_0009065c\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        "jmp .Lf90568_000905be\n"
        /* } scope */
        ".Lf90568_000905ee:\n"
        "movl (%esi), %eax\n" /* line 2880 | value */
        "movzwl %ax, %ebx\n" /* line 2881 | stringValue */
        "shrl $0x10, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Scr_GetAnims\n"
        "movl %ebx, 4(%esp)\n" /* stringValue */
        "movl %eax, (%esp)\n"
        "calll XAnimGetAnimDebugName\n"
        "jmp .Lf90568_00090589\n"
        ".Lf90568_0009060f:\n"
        "movl %esi, (%esp)\n" /* line 2872 | value */
        "calll Scr_CastString\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 2897 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf90568_0009061e:\n"
        "movl $2, 4(%esi)\n" /* line 2876 | value */
        /* } scope */
        "addl $0x10, %esp\n" /* line 2897 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf90568_0009062c:\n"
        "movl (%esi), %eax\n" /* line 2885 | value */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "movl var_typename(, %eax, 4), %eax\n"
        "jmp .Lf90568_00090589\n"
        /* { scope 2 */
        ".Lf90568_00090646:\n"
        "subl $1, %eax\n" /* line 1946 */
        "jne .Lf90568_000905be\n"
        "movl %edx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "jmp .Lf90568_000905be\n"
        ".Lf90568_0009065c:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "jmp .Lf90568_000905be\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_90568_0:\n"
        ".long .Lf90568_00090582\n"
        ".long .Lf90568_0009062c\n"
        ".long .Lf90568_0009060f\n"
        ".long .Lf90568_0009061e\n"
        ".long .Lf90568_0009060f\n"
        ".long .Lf90568_0009060f\n"
        ".long .Lf90568_0009060f\n"
        ".long .Lf90568_00090582\n"
        ".long .Lf90568_00090582\n"
        ".long .Lf90568_00090582\n"
        ".long .Lf90568_00090582\n"
        ".long .Lf90568_000905ee\n"
        ".text\n"
    );
}

/* line 2983 */
__attribute__((naked))
JCOEF Scr_UnmatchingTypesError(VariableValue *value1, VariableValue *value2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2983 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %edi\n" /* value1 */
        "movl 0xc(%ebp), %esi\n" /* value2 */
        /* { scope 1 */
        "movl scrVarPub+16, %eax\n" /* line 2989 */
        "testl %eax, %eax\n"
        "je .Lf90672_0009074c\n"
        "xorl %ebx, %ebx\n" /* error_message */
        ".Lf90672_00090690:\n"
        "movl (%edi), %edx\n" /* line 252 */
        "movl 4(%edi), %eax\n" /* type */
        /* { scope 2 */
        "cmpl $3, %eax\n" /* line 1946 */
        "jg .Lf90672_000906df\n"
        "cmpl $2, %eax\n"
        "jl .Lf90672_00090736\n"
        "movl %edx, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        /* } scope */
        ".Lf90672_000906ab:\n"
        "movl $0, 4(%edi)\n" /* line 3008 | value1 */
        "movl (%esi), %edx\n" /* line 252 */
        "movl 4(%esi), %eax\n" /* type */
        /* { scope 2 */
        "cmpl $3, %eax\n" /* line 1946 */
        "jg .Lf90672_00090703\n"
        "cmpl $2, %eax\n"
        "jl .Lf90672_00090727\n"
        "movl %edx, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        /* } scope */
        ".Lf90672_000906c9:\n"
        "movl $0, 4(%esi)\n" /* line 3010 | value2 */
        "movl %ebx, 8(%ebp)\n" /* line 3012 | error_message, value1 */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 3013 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_Error\n" /* line 3012 */
        /* { scope 2 */
        ".Lf90672_000906df:\n"
        "cmpl $4, %eax\n" /* line 1946 */
        "jne .Lf90672_000906ab\n"
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf90672_000906ab\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf90672_000907d0\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        "jmp .Lf90672_000906ab\n"
        /* } scope */
        /* { scope 2 */
        ".Lf90672_00090703:\n"
        "cmpl $4, %eax\n" /* line 1946 */
        "jne .Lf90672_000906c9\n"
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf90672_000906c9\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf90672_000907bb\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        "jmp .Lf90672_000906c9\n"
        ".Lf90672_00090727:\n"
        "subl $1, %eax\n" /* line 1946 */
        "jne .Lf90672_000906c9\n"
        "movl %edx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "jmp .Lf90672_000906c9\n"
        /* } scope */
        /* { scope 2 */
        ".Lf90672_00090736:\n"
        "subl $1, %eax\n" /* line 1946 */
        "jne .Lf90672_000906ab\n"
        "movl %edx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "jmp .Lf90672_000906ab\n"
        /* } scope */
        ".Lf90672_0009074c:\n"
        "movl 4(%edi), %eax\n" /* line 2991 | value1 */
        "movl %eax, -0x1c(%ebp)\n" /* type1 */
        "movl 4(%esi), %ebx\n" /* line 2992 | value2, error_message */
        "movl %edi, (%esp)\n" /* line 2994 | value1 */
        "calll Scr_CastDebugString\n"
        "movl %esi, (%esp)\n" /* line 2995 | value2 */
        "calll Scr_CastDebugString\n"
        "movl var_typename(, %ebx, 4), %ebx\n" /* line 3000 | error_message */
        "movl %ebx, -0x24(%ebp)\n" /* error_message */
        "movl -0x1c(%ebp), %edx\n" /* type1 */
        "movl var_typename(, %edx, 4), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl (%esi), %eax\n" /* value2 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, %ebx\n" /* error_message */
        "movl (%edi), %eax\n" /* value1 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl -0x24(%ebp), %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "movl -0x20(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* error_message */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021d65c, (%esp)\n" /* "pair '%s' and '%s' has unmatching types '%s' and '%s'" */
        "calll va\n"
        "movl %eax, %ebx\n" /* error_message */
        "jmp .Lf90672_00090690\n"
        /* { scope 2 */
        ".Lf90672_000907bb:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "jmp .Lf90672_000906c9\n"
        /* } scope */
        /* { scope 2 */
        ".Lf90672_000907d0:\n"
        "movl $0x10, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "jmp .Lf90672_000906ab\n"
    );
}

/* line 3489 */
__attribute__((naked))
JCOEF Scr_EvalMod(VariableValue *value1, VariableValue *value2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3489 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ecx\n" /* value1 */
        "movl 0xc(%ebp), %eax\n" /* value2 */
        "cmpl $6, 4(%ecx)\n" /* line 3491 */
        "je .Lf907e6_00090803\n"
        ".Lf907e6_000907f6:\n"
        "movl %eax, 0xc(%ebp)\n" /* line 3503 | value2 */
        "movl %ecx, 8(%ebp)\n" /* value1 */
        "popl %ebx\n" /* line 3504 */
        "popl %ebp\n"
        "jmp Scr_UnmatchingTypesError\n" /* line 3503 */
        ".Lf907e6_00090803:\n"
        "cmpl $6, 4(%eax)\n" /* line 3491 */
        "jne .Lf907e6_000907f6\n"
        "movl (%eax), %edx\n" /* line 3493 */
        "testl %edx, %edx\n"
        "je .Lf907e6_0009081b\n"
        "movl (%ecx), %eax\n" /* line 3495 */
        "movl %edx, %ebx\n"
        "cltd\n"
        "idivl %ebx\n"
        "movl %edx, (%ecx)\n"
        "popl %ebx\n" /* line 3504 */
        "popl %ebp\n"
        "retl\n"
        ".Lf907e6_0009081b:\n"
        "movl $0, (%ecx)\n" /* line 3498 */
        "movl $str_0021d694, 8(%ebp)\n" /* line 3499 | value1 */
        "popl %ebx\n" /* line 3504 */
        "popl %ebp\n"
        "jmp Scr_Error\n" /* line 3499 */
    );
}

/* line 3454 */
__attribute__((naked))
JCOEF Scr_EvalDivide(VariableValue *value1, VariableValue *value2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3454 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* value1 */
        "movl 0xc(%ebp), %esi\n" /* value2 */
        /* { scope 1 */
        "movl 4(%ebx), %eax\n" /* line 3021 */
        "movl 4(%esi), %edx\n" /* line 3022 */
        "cmpl %edx, %eax\n" /* line 3024 */
        "je .Lf90830_00090861\n"
        "cmpl $5, %eax\n" /* line 3027 */
        "je .Lf90830_000908b2\n"
        "cmpl $6, %eax\n" /* line 3035 */
        "je .Lf90830_0009087c\n"
        ".Lf90830_00090852:\n"
        "movl %esi, 4(%esp)\n" /* line 3043 */
        "movl %ebx, (%esp)\n"
        "calll Scr_UnmatchingTypesError\n"
        "movl 4(%ebx), %eax\n"
        /* } scope */
        ".Lf90830_00090861:\n"
        "cmpl $5, %eax\n" /* line 3460 */
        "je .Lf90830_00090890\n"
        "cmpl $6, %eax\n"
        "je .Lf90830_000908cb\n"
        "movl %esi, 0xc(%ebp)\n" /* line 3485 | value2 */
        "movl %ebx, 8(%ebp)\n" /* value1 */
        "addl $0x10, %esp\n" /* line 3486 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp Scr_UnmatchingTypesError\n" /* line 3485 */
        /* { scope 1 */
        ".Lf90830_0009087c:\n"
        "cmpl $5, %edx\n" /* line 3035 */
        "jne .Lf90830_00090852\n"
        "movl $5, 4(%ebx)\n" /* line 3037 */
        "cvtsi2ssl (%ebx), %xmm0\n" /* line 3038 */
        "movss %xmm0, (%ebx)\n"
        /* } scope */
        ".Lf90830_00090890:\n"
        "movss (%esi), %xmm1\n" /* line 3475 | value2 */
        "ucomiss lit4_002ed5e8, %xmm1\n" /* 0.0f */
        "jp .Lf90830_0009089f\n"
        "je .Lf90830_000908ef\n"
        ".Lf90830_0009089f:\n"
        "movss (%ebx), %xmm0\n" /* line 3477 | value1 */
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, (%ebx)\n" /* value1 */
        "addl $0x10, %esp\n" /* line 3486 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf90830_000908b2:\n"
        "cmpl $6, %edx\n" /* line 3027 */
        "jne .Lf90830_00090852\n"
        "movl $5, 4(%esi)\n" /* line 3029 */
        "cvtsi2ssl (%esi), %xmm0\n" /* line 3030 */
        "movss %xmm0, (%esi)\n"
        "movl 4(%ebx), %eax\n"
        "jmp .Lf90830_00090861\n"
        /* } scope */
        ".Lf90830_000908cb:\n"
        "movl $5, 4(%ebx)\n" /* line 3463 | value1 */
        "movl (%esi), %eax\n" /* line 3464 | value2 */
        "testl %eax, %eax\n"
        "je .Lf90830_000908ef\n"
        "cvtsi2ssl (%ebx), %xmm0\n" /* line 3466 | value1 */
        "cvtsi2ssl %eax, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, (%ebx)\n" /* value1 */
        "addl $0x10, %esp\n" /* line 3486 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf90830_000908ef:\n"
        "movl $0, (%ebx)\n" /* line 3480 | value1 */
        "movl $str_0021d694, 8(%ebp)\n" /* line 3481 | value1 */
        "addl $0x10, %esp\n" /* line 3486 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp Scr_Error\n" /* line 3481 */
    );
}

/* line 3339 */
__attribute__((naked))
JCOEF Scr_EvalPlus(VariableValue *value1, VariableValue *value2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3339 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x202c, %esp\n"
        "movl 8(%ebp), %esi\n" /* value1 */
        /* { scope 1 */
        /* { scope 2 */
        "movl 4(%esi), %edx\n" /* line 3053 */
        "movl 0xc(%ebp), %ecx\n" /* line 3054 | value2 */
        "movl 4(%ecx), %eax\n"
        "cmpl %eax, %edx\n" /* line 3056 */
        "je .Lf90908_0009094a\n"
        "jl .Lf90908_00090974\n" /* line 3059 */
        "cmpl $2, %eax\n" /* line 3097 */
        "je .Lf90908_00090a5d\n"
        "cmpl $5, %eax\n"
        "je .Lf90908_00090a78\n"
        ".Lf90908_00090938:\n"
        "movl 0xc(%ebp), %edx\n" /* line 3132 | value2 */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Scr_UnmatchingTypesError\n"
        "movl 4(%esi), %edx\n"
        /* } scope */
        ".Lf90908_0009094a:\n"
        "cmpl $4, %edx\n" /* line 3353 */
        "je .Lf90908_000909b7\n"
        "jg .Lf90908_0009099e\n"
        "cmpl $2, %edx\n"
        "je .Lf90908_00090aef\n"
        ".Lf90908_0009095a:\n"
        "movl 0xc(%ebp), %edx\n" /* line 3396 | value2 */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* value1 */
        "calll Scr_UnmatchingTypesError\n"
        /* } scope */
        ".Lf90908_00090969:\n"
        "addl $0x202c, %esp\n" /* line 3397 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf90908_00090974:\n"
        "cmpl $2, %edx\n" /* line 3061 */
        "je .Lf90908_00090a92\n"
        "cmpl $5, %edx\n"
        "jne .Lf90908_00090938\n"
        ".Lf90908_00090982:\n"
        "cmpl $6, %eax\n" /* line 3085 */
        "jne .Lf90908_00090938\n"
        "movl 0xc(%ebp), %eax\n" /* line 3087 | value2 */
        "movl $5, 4(%eax)\n"
        "cvtsi2ssl (%eax), %xmm0\n" /* line 3088 */
        "movss %xmm0, (%eax)\n"
        "movl 4(%esi), %edx\n"
        "jmp .Lf90908_0009094a\n"
        /* } scope */
        ".Lf90908_0009099e:\n"
        "cmpl $5, %edx\n" /* line 3353 */
        "je .Lf90908_00090ad5\n"
        "cmpl $6, %edx\n"
        "jne .Lf90908_0009095a\n"
        "movl (%esi), %eax\n" /* line 3356 | value1 */
        "movl 0xc(%ebp), %ecx\n" /* value2 */
        "addl (%ecx), %eax\n"
        "movl %eax, (%esi)\n" /* value1 */
        "jmp .Lf90908_00090969\n"
        ".Lf90908_000909b7:\n"
        "movl $2, 4(%esp)\n" /* line 1846 */
        "movl $0x10, (%esp)\n"
        "calll MT_Alloc\n"
        "leal 4(%eax), %ebx\n"
        "movl $0, -4(%ebx)\n" /* line 1848 */
        "movl (%esi), %edx\n" /* line 3387 | value1 */
        "movl 0xc(%ebp), %edi\n" /* value2, tempLen */
        "movl (%edi), %ecx\n" /* tempLen */
        "movss (%edx), %xmm0\n"
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movl (%esi), %eax\n" /* line 3388 | value1 */
        "movl (%edi), %edx\n" /* tempLen */
        "movss 4(%eax), %xmm0\n"
        "addss 4(%edx), %xmm0\n"
        "movss %xmm0, 4(%ebx)\n" /* s1 */
        "movl (%esi), %eax\n" /* line 3389 | value1 */
        "movl (%edi), %edx\n" /* tempLen */
        "movss 8(%eax), %xmm0\n"
        "addss 8(%edx), %xmm0\n"
        "movss %xmm0, 8(%ebx)\n" /* s1 */
        "movl (%esi), %edx\n" /* line 3390 | value1, vectorValue */
        /* { scope 2 */
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf90908_00090a2e\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf90908_00090c2a\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        /* } scope */
        ".Lf90908_00090a2e:\n"
        "movl 0xc(%ebp), %eax\n" /* line 3391 | value2 */
        "movl (%eax), %edx\n" /* vectorValue */
        /* { scope 2 */
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf90908_00090a50\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf90908_00090c3f\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        /* } scope */
        ".Lf90908_00090a50:\n"
        "movl %ebx, (%esi)\n" /* line 3392 | s1, value1 */
        /* } scope */
        ".Lf90908_00090a52:\n"
        "addl $0x202c, %esp\n" /* line 3397 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf90908_00090a5d:\n"
        "cmpl $5, %edx\n" /* line 3100 */
        "je .Lf90908_00090c7a\n"
        "cmpl $6, %edx\n"
        "je .Lf90908_00090c95\n"
        "cmpl $4, %edx\n"
        "je .Lf90908_00090bee\n"
        ".Lf90908_00090a78:\n"
        "cmpl $6, %edx\n" /* line 3121 */
        "jne .Lf90908_00090938\n"
        "movl $5, 4(%esi)\n" /* line 3123 */
        "cvtsi2ssl (%esi), %xmm0\n" /* line 3124 */
        "movss %xmm0, (%esi)\n"
        "jmp .Lf90908_00090ad9\n"
        ".Lf90908_00090a92:\n"
        "cmpl $5, %eax\n" /* line 3064 */
        "je .Lf90908_00090c56\n"
        "cmpl $6, %eax\n"
        "je .Lf90908_00090cb0\n"
        "cmpl $4, %eax\n"
        "jne .Lf90908_00090982\n"
        "movl 0xc(%ebp), %edi\n" /* line 3067 | value2 */
        "movl $2, 4(%edi)\n"
        "movl (%edi), %ebx\n" /* line 3068 */
        "movl %ebx, (%esp)\n" /* line 3069 */
        "calll SL_GetStringForVector\n"
        "movl %eax, (%edi)\n"
        /* { scope 3 */
        "cmpb $0, -1(%ebx)\n" /* line 1901 */
        "je .Lf90908_00090c0b\n"
        ".Lf90908_00090acd:\n"
        "movl 4(%esi), %edx\n"
        "jmp .Lf90908_0009094a\n"
        ".Lf90908_00090ad5:\n"
        "movss (%esi), %xmm0\n"
        /* } scope */
        /* } scope */
        ".Lf90908_00090ad9:\n"
        "movl 0xc(%ebp), %edi\n" /* line 3360 | value2, tempLen */
        "addss (%edi), %xmm0\n" /* tempLen */
        "movss %xmm0, (%esi)\n" /* value1 */
        /* } scope */
        "addl $0x202c, %esp\n" /* line 3397 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf90908_00090aef:\n"
        "movl (%esi), %eax\n" /* line 3364 | value1 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, %ebx\n" /* s1 */
        "movl 0xc(%ebp), %edx\n" /* line 3365 | value2 */
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, -0x201c(%ebp)\n" /* s2 */
        "movl (%esi), %eax\n" /* line 3366 | value1 */
        "movl %eax, (%esp)\n"
        "calll SL_GetStringLen\n"
        "movl %eax, %edi\n" /* tempLen */
        "movl 0xc(%ebp), %ecx\n" /* line 3367 | value2 */
        "movl (%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SL_GetStringLen\n"
        "leal 1(%edi, %eax), %eax\n" /* tempLen */
        "movl %eax, -0x2020(%ebp)\n" /* tempLen2 */
        "cmpl $0x2000, %edi\n" /* line 3368 | tempLen */
        "jg .Lf90908_00090ba2\n"
        "movl %ebx, 4(%esp)\n" /* line 3377 | s1 */
        "leal -0x2018(%ebp), %ebx\n" /* tempString, s1 */
        "movl %ebx, (%esp)\n" /* s1 */
        "calll strcpy\n"
        "movl -0x201c(%ebp), %edx\n" /* line 3378 | s2 */
        "movl %edx, 4(%esp)\n"
        "leal (%ebx, %edi), %eax\n" /* s1 */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl $0xe, 0xc(%esp)\n" /* line 3379 */
        "movl -0x2020(%ebp), %ecx\n" /* tempLen2 */
        "movl %ecx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* s1 */
        "calll SL_GetStringOfLen\n"
        "movl %eax, %ebx\n" /* s1 */
        "movl (%esi), %eax\n" /* line 3380 | value1 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movl 0xc(%ebp), %edi\n" /* line 3381 | value2, tempLen */
        "movl (%edi), %eax\n" /* tempLen */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movl %ebx, (%esi)\n" /* line 3382 | s1, value1 */
        "jmp .Lf90908_00090969\n"
        ".Lf90908_00090ba2:\n"
        "movl (%esi), %eax\n" /* line 3370 | value1 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movl 0xc(%ebp), %edi\n" /* line 3371 | value2, tempLen */
        "movl (%edi), %eax\n" /* tempLen */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movl $0, 4(%esi)\n" /* line 3372 | value1 */
        "movl $0, 4(%edi)\n" /* line 3373 | tempLen */
        "movl -0x201c(%ebp), %eax\n" /* line 3374 | s2 */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* s1 */
        "movl $str_0021d6a0, (%esp)\n" /* "cannot concat "%s" and "%s" - max string length exceeded" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Scr_Error\n"
        "jmp .Lf90908_00090969\n"
        /* { scope 2 */
        ".Lf90908_00090bee:\n"
        "movl $2, 4(%esi)\n" /* line 3103 */
        "movl (%esi), %ebx\n" /* line 3104 | vectorValue */
        "movl %ebx, (%esp)\n" /* line 3105 | vectorValue */
        "calll SL_GetStringForVector\n"
        "movl %eax, (%esi)\n"
        /* { scope 3 */
        "cmpb $0, -1(%ebx)\n" /* line 1901 */
        "jne .Lf90908_00090acd\n"
        ".Lf90908_00090c0b:\n"
        "leal -4(%ebx), %edx\n" /* line 1916 */
        "movzwl -4(%ebx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf90908_00090cce\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%ebx)\n"
        "movl 4(%esi), %edx\n"
        "jmp .Lf90908_0009094a\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf90908_00090c2a:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "jmp .Lf90908_00090a2e\n"
        /* } scope */
        /* { scope 2 */
        ".Lf90908_00090c3f:\n"
        "movl $0x10, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        /* } scope */
        "movl %ebx, (%esi)\n" /* line 3392 | s1, value1 */
        "jmp .Lf90908_00090a52\n"
        /* { scope 2 */
        ".Lf90908_00090c56:\n"
        "movl 0xc(%ebp), %eax\n" /* line 3074 | value2 */
        "movl $2, 4(%eax)\n"
        "movl 0xc(%ebp), %edx\n" /* line 3075 | value2 */
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SL_GetStringForFloat\n"
        "movl 0xc(%ebp), %ecx\n" /* value2 */
        "movl %eax, (%ecx)\n"
        "movl 4(%esi), %edx\n"
        "jmp .Lf90908_0009094a\n"
        ".Lf90908_00090c7a:\n"
        "movl $2, 4(%esi)\n" /* line 3110 */
        "movl (%esi), %eax\n" /* line 3111 */
        "movl %eax, (%esp)\n"
        "calll SL_GetStringForFloat\n"
        "movl %eax, (%esi)\n"
        "movl 4(%esi), %edx\n"
        "jmp .Lf90908_0009094a\n"
        ".Lf90908_00090c95:\n"
        "movl $2, 4(%esi)\n" /* line 3115 */
        "movl (%esi), %eax\n" /* line 3116 */
        "movl %eax, (%esp)\n"
        "calll SL_GetStringForInt\n"
        "movl %eax, (%esi)\n"
        "movl 4(%esi), %edx\n"
        "jmp .Lf90908_0009094a\n"
        ".Lf90908_00090cb0:\n"
        "movl 0xc(%ebp), %edi\n" /* line 3079 | value2 */
        "movl $2, 4(%edi)\n"
        "movl (%edi), %eax\n" /* line 3080 */
        "movl %eax, (%esp)\n"
        "calll SL_GetStringForInt\n"
        "movl %eax, (%edi)\n"
        "movl 4(%esi), %edx\n"
        "jmp .Lf90908_0009094a\n"
        /* { scope 3 */
        ".Lf90908_00090cce:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %edx, (%esp)\n"
        "calll MT_Free\n"
        "movl 4(%esi), %edx\n"
        "jmp .Lf90908_0009094a\n"
    );
}

/* line 3324 */
__attribute__((naked))
JCOEF Scr_EvalShiftRight(VariableValue *value1, VariableValue *value2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3324 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* value1 */
        "movl 0xc(%ebp), %eax\n" /* value2 */
        "cmpl $6, 4(%edx)\n" /* line 3326 */
        "je .Lf90ce6_00090d01\n"
        ".Lf90ce6_00090cf5:\n"
        "movl %eax, 0xc(%ebp)\n" /* line 3332 | value2 */
        "movl %edx, 8(%ebp)\n" /* value1 */
        "popl %ebp\n" /* line 3333 */
        "jmp Scr_UnmatchingTypesError\n" /* line 3332 */
        ".Lf90ce6_00090d01:\n"
        "cmpl $6, 4(%eax)\n" /* line 3326 */
        "jne .Lf90ce6_00090cf5\n"
        "movl (%eax), %ecx\n" /* line 3328 */
        "sarl %cl, (%edx)\n"
        "popl %ebp\n" /* line 3333 */
        "retl\n"
    );
}

/* line 3312 */
__attribute__((naked))
JCOEF Scr_EvalShiftLeft(VariableValue *value1, VariableValue *value2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3312 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* value1 */
        "movl 0xc(%ebp), %eax\n" /* value2 */
        "cmpl $6, 4(%edx)\n" /* line 3314 */
        "je .Lf90d0e_00090d29\n"
        ".Lf90d0e_00090d1d:\n"
        "movl %eax, 0xc(%ebp)\n" /* line 3320 | value2 */
        "movl %edx, 8(%ebp)\n" /* value1 */
        "popl %ebp\n" /* line 3321 */
        "jmp Scr_UnmatchingTypesError\n" /* line 3320 */
        ".Lf90d0e_00090d29:\n"
        "cmpl $6, 4(%eax)\n" /* line 3314 */
        "jne .Lf90d0e_00090d1d\n"
        "movl (%eax), %ecx\n" /* line 3316 */
        "shll %cl, (%edx)\n"
        "popl %ebp\n" /* line 3321 */
        "retl\n"
    );
}

/* line 3160 */
__attribute__((naked))
JCOEF Scr_EvalAnd(VariableValue *value1, VariableValue *value2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3160 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* value1 */
        "movl 0xc(%ebp), %edx\n" /* value2 */
        "cmpl $6, 4(%ecx)\n" /* line 3162 */
        "je .Lf90d36_00090d51\n"
        ".Lf90d36_00090d45:\n"
        "movl %edx, 0xc(%ebp)\n" /* line 3168 | value2 */
        "movl %ecx, 8(%ebp)\n" /* value1 */
        "popl %ebp\n" /* line 3169 */
        "jmp Scr_UnmatchingTypesError\n" /* line 3168 */
        ".Lf90d36_00090d51:\n"
        "cmpl $6, 4(%edx)\n" /* line 3162 */
        "jne .Lf90d36_00090d45\n"
        "movl (%ecx), %eax\n" /* line 3164 */
        "andl (%edx), %eax\n"
        "movl %eax, (%ecx)\n"
        "popl %ebp\n" /* line 3169 */
        "retl\n"
    );
}

/* line 3148 */
__attribute__((naked))
JCOEF Scr_EvalExOr(VariableValue *value1, VariableValue *value2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3148 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* value1 */
        "movl 0xc(%ebp), %edx\n" /* value2 */
        "cmpl $6, 4(%ecx)\n" /* line 3150 */
        "je .Lf90d60_00090d7b\n"
        ".Lf90d60_00090d6f:\n"
        "movl %edx, 0xc(%ebp)\n" /* line 3156 | value2 */
        "movl %ecx, 8(%ebp)\n" /* value1 */
        "popl %ebp\n" /* line 3157 */
        "jmp Scr_UnmatchingTypesError\n" /* line 3156 */
        ".Lf90d60_00090d7b:\n"
        "cmpl $6, 4(%edx)\n" /* line 3150 */
        "jne .Lf90d60_00090d6f\n"
        "movl (%ecx), %eax\n" /* line 3152 */
        "xorl (%edx), %eax\n"
        "movl %eax, (%ecx)\n"
        "popl %ebp\n" /* line 3157 */
        "retl\n"
    );
}

/* line 3136 */
__attribute__((naked))
JCOEF Scr_EvalOr(VariableValue *value1, VariableValue *value2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3136 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* value1 */
        "movl 0xc(%ebp), %edx\n" /* value2 */
        "cmpl $6, 4(%ecx)\n" /* line 3138 */
        "je .Lf90d8a_00090da5\n"
        ".Lf90d8a_00090d99:\n"
        "movl %edx, 0xc(%ebp)\n" /* line 3144 | value2 */
        "movl %ecx, 8(%ebp)\n" /* value1 */
        "popl %ebp\n" /* line 3145 */
        "jmp Scr_UnmatchingTypesError\n" /* line 3144 */
        ".Lf90d8a_00090da5:\n"
        "cmpl $6, 4(%edx)\n" /* line 3138 */
        "jne .Lf90d8a_00090d99\n"
        "movl (%ecx), %eax\n" /* line 3140 */
        "orl (%edx), %eax\n"
        "movl %eax, (%ecx)\n"
        "popl %ebp\n" /* line 3145 */
        "retl\n"
    );
}

/* line 3303 */
__attribute__((naked))
JCOEF Scr_EvalLessEqual(VariableValue *value1, VariableValue *value2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3303 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* value1 */
        "movl 0xc(%ebp), %esi\n" /* value2 */
        /* { scope 1 */
        "movl 4(%ebx), %eax\n" /* line 3021 */
        "movl 4(%esi), %edx\n" /* line 3022 */
        "cmpl %edx, %eax\n" /* line 3024 */
        "je .Lf90db4_00090de9\n"
        "cmpl $5, %eax\n" /* line 3027 */
        "je .Lf90db4_00090e36\n"
        "cmpl $6, %eax\n" /* line 3035 */
        "je .Lf90db4_00090e6c\n"
        ".Lf90db4_00090dda:\n"
        "movl %esi, 4(%esp)\n" /* line 3043 */
        "movl %ebx, (%esp)\n"
        "calll Scr_UnmatchingTypesError\n"
        "movl 4(%ebx), %eax\n"
        /* } scope */
        ".Lf90db4_00090de9:\n"
        "cmpl $5, %eax\n" /* line 3287 */
        "je .Lf90db4_00090e10\n"
        "cmpl $6, %eax\n"
        "je .Lf90db4_00090e4f\n"
        "movl %esi, 4(%esp)\n" /* line 3299 */
        "movl %ebx, (%esp)\n"
        "calll Scr_UnmatchingTypesError\n"
        "xorl %eax, %eax\n" /* line 3308 */
        "cmpl $0, (%ebx)\n" /* value1 */
        "sete %al\n"
        "movl %eax, (%ebx)\n" /* value1 */
        "addl $0x10, %esp\n" /* line 3309 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf90db4_00090e10:\n"
        "movss (%ebx), %xmm0\n" /* value1 */
        ".Lf90db4_00090e14:\n"
        "movl $6, 4(%ebx)\n" /* line 3294 */
        "xorl %eax, %eax\n" /* line 3295 */
        "ucomiss (%esi), %xmm0\n"
        "seta %al\n"
        "movl %eax, (%ebx)\n"
        "xorl %eax, %eax\n" /* line 3308 */
        "cmpl $0, (%ebx)\n" /* value1 */
        "sete %al\n"
        "movl %eax, (%ebx)\n" /* value1 */
        "addl $0x10, %esp\n" /* line 3309 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf90db4_00090e36:\n"
        "cmpl $6, %edx\n" /* line 3027 */
        "jne .Lf90db4_00090dda\n"
        "movl $5, 4(%esi)\n" /* line 3029 */
        "cvtsi2ssl (%esi), %xmm0\n" /* line 3030 */
        "movss %xmm0, (%esi)\n"
        "movl 4(%ebx), %eax\n"
        "jmp .Lf90db4_00090de9\n"
        /* } scope */
        ".Lf90db4_00090e4f:\n"
        "movl (%ebx), %eax\n" /* line 3290 */
        "cmpl (%esi), %eax\n"
        "setg %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, (%ebx)\n"
        "xorl %eax, %eax\n" /* line 3308 */
        "cmpl $0, (%ebx)\n" /* value1 */
        "sete %al\n"
        "movl %eax, (%ebx)\n" /* value1 */
        "addl $0x10, %esp\n" /* line 3309 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf90db4_00090e6c:\n"
        "cmpl $5, %edx\n" /* line 3035 */
        "jne .Lf90db4_00090dda\n"
        "movl $5, 4(%ebx)\n" /* line 3037 */
        "cvtsi2ssl (%ebx), %xmm0\n" /* line 3038 */
        "movss %xmm0, (%ebx)\n"
        "jmp .Lf90db4_00090e14\n"
    );
}

/* line 3272 */
__attribute__((naked))
JCOEF Scr_EvalGreaterEqual(VariableValue *value1, VariableValue *value2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3272 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* value1 */
        "movl 0xc(%ebp), %esi\n" /* value2 */
        /* { scope 1 */
        "movl 4(%ebx), %eax\n" /* line 3021 */
        "movl 4(%esi), %edx\n" /* line 3022 */
        "cmpl %edx, %eax\n" /* line 3024 */
        "je .Lf90e86_00090eb7\n"
        "cmpl $5, %eax\n" /* line 3027 */
        "je .Lf90e86_00090f18\n"
        "cmpl $6, %eax\n" /* line 3035 */
        "je .Lf90e86_00090ede\n"
        ".Lf90e86_00090ea8:\n"
        "movl %esi, 4(%esp)\n" /* line 3043 */
        "movl %ebx, (%esp)\n"
        "calll Scr_UnmatchingTypesError\n"
        "movl 4(%ebx), %eax\n"
        /* } scope */
        ".Lf90e86_00090eb7:\n"
        "cmpl $5, %eax\n" /* line 3256 */
        "je .Lf90e86_00090ef2\n"
        "cmpl $6, %eax\n"
        "je .Lf90e86_00090f31\n"
        "movl %esi, 4(%esp)\n" /* line 3268 */
        "movl %ebx, (%esp)\n"
        "calll Scr_UnmatchingTypesError\n"
        "xorl %eax, %eax\n" /* line 3277 */
        "cmpl $0, (%ebx)\n" /* value1 */
        "sete %al\n"
        "movl %eax, (%ebx)\n" /* value1 */
        "addl $0x10, %esp\n" /* line 3278 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf90e86_00090ede:\n"
        "cmpl $5, %edx\n" /* line 3035 */
        "jne .Lf90e86_00090ea8\n"
        "movl $5, 4(%ebx)\n" /* line 3037 */
        "cvtsi2ssl (%ebx), %xmm0\n" /* line 3038 */
        "movss %xmm0, (%ebx)\n"
        /* } scope */
        ".Lf90e86_00090ef2:\n"
        "movl $6, 4(%ebx)\n" /* line 3263 */
        "movss (%esi), %xmm0\n" /* line 3264 */
        "xorl %eax, %eax\n"
        "ucomiss (%ebx), %xmm0\n"
        "seta %al\n"
        "movl %eax, (%ebx)\n"
        "xorl %eax, %eax\n" /* line 3277 */
        "cmpl $0, (%ebx)\n" /* value1 */
        "sete %al\n"
        "movl %eax, (%ebx)\n" /* value1 */
        "addl $0x10, %esp\n" /* line 3278 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf90e86_00090f18:\n"
        "cmpl $6, %edx\n" /* line 3027 */
        "jne .Lf90e86_00090ea8\n"
        "movl $5, 4(%esi)\n" /* line 3029 */
        "cvtsi2ssl (%esi), %xmm0\n" /* line 3030 */
        "movss %xmm0, (%esi)\n"
        "movl 4(%ebx), %eax\n"
        "jmp .Lf90e86_00090eb7\n"
        /* } scope */
        ".Lf90e86_00090f31:\n"
        "movl (%ebx), %eax\n" /* line 3259 */
        "cmpl (%esi), %eax\n"
        "setl %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, (%ebx)\n"
        "xorl %eax, %eax\n" /* line 3277 */
        "cmpl $0, (%ebx)\n" /* value1 */
        "sete %al\n"
        "movl %eax, (%ebx)\n" /* value1 */
        "addl $0x10, %esp\n" /* line 3278 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3172 */
__attribute__((naked))
JCOEF Scr_EvalEquality(VariableValue *value1, VariableValue *value2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3172 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* value1 */
        "movl 0xc(%ebp), %edi\n" /* value2 */
        /* { scope 1 */
        /* { scope 2 */
        "movl 4(%esi), %eax\n" /* line 3021 */
        "movl 4(%edi), %edx\n" /* line 3022 */
        "cmpl %edx, %eax\n" /* line 3024 */
        "je .Lf90f4e_00090f7d\n"
        "cmpl $5, %eax\n" /* line 3027 */
        "je .Lf90f4e_00090fc5\n"
        "cmpl $6, %eax\n" /* line 3035 */
        "je .Lf90f4e_00090fdb\n"
        ".Lf90f4e_00090f71:\n"
        "movl %edi, 4(%esp)\n" /* line 3043 */
        "movl %esi, (%esp)\n"
        "calll Scr_UnmatchingTypesError\n"
        /* } scope */
        ".Lf90f4e_00090f7d:\n"
        "cmpl $0xb, 4(%esi)\n" /* line 3180 | value1 */
        "ja .Lf90f4e_00090fb3\n"
        "movl 4(%esi), %eax\n" /* value1 */
        "jmpl *.Ljt_90f4e_0(, %eax, 4)\n"
        ".Lf90f4e_00090f8d:\n"
        "movl (%esi), %edx\n" /* line 3214 | value1 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0x16, %eax\n"
        "jne .Lf90f4e_000910ce\n"
        ".Lf90f4e_00090fa6:\n"
        "cmpb $0, scrVarPub+12\n" /* line 3216 */
        "jne .Lf90f4e_000910e5\n"
        ".Lf90f4e_00090fb3:\n"
        "movl %edi, 0xc(%ebp)\n" /* line 3237 | value2 */
        "movl %esi, 8(%ebp)\n" /* value1 */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 3238 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_UnmatchingTypesError\n" /* line 3237 */
        /* { scope 2 */
        ".Lf90f4e_00090fc5:\n"
        "cmpl $6, %edx\n" /* line 3027 */
        "jne .Lf90f4e_00090f71\n"
        "movl $5, 4(%edi)\n" /* line 3029 */
        "cvtsi2ssl (%edi), %xmm0\n" /* line 3030 */
        "movss %xmm0, (%edi)\n"
        "jmp .Lf90f4e_00090f7d\n"
        ".Lf90f4e_00090fdb:\n"
        "cmpl $5, %edx\n" /* line 3035 */
        "jne .Lf90f4e_00090f71\n"
        "movl $5, 4(%esi)\n" /* line 3037 */
        "cvtsi2ssl (%esi), %xmm0\n" /* line 3038 */
        "movss %xmm0, (%esi)\n"
        "jmp .Lf90f4e_00090f7d\n"
        /* } scope */
        ".Lf90f4e_00090ff1:\n"
        "movl $6, 4(%esi)\n" /* line 3232 | value1 */
        ".Lf90f4e_00090ff8:\n"
        "movl (%esi), %eax\n" /* line 3233 | value1 */
        "cmpl (%edi), %eax\n" /* value2 */
        "sete %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, (%esi)\n" /* value1 */
        /* } scope */
        ".Lf90f4e_00091004:\n"
        "addl $0x1c, %esp\n" /* line 3238 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf90f4e_0009100c:\n"
        "movl $6, 4(%esi)\n" /* line 3206 | value1 */
        "movl (%esi), %edx\n" /* line 3207 | value1 */
        "movl (%edi), %ecx\n" /* value2 */
        "movss (%edx), %xmm0\n"
        "ucomiss (%ecx), %xmm0\n"
        "je .Lf90f4e_0009110c\n"
        ".Lf90f4e_00091024:\n"
        "xorl %ebx, %ebx\n" /* tempInt */
        ".Lf90f4e_00091026:\n"
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf90f4e_00091045\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf90f4e_00091146\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        "movl (%edi), %ecx\n"
        ".Lf90f4e_00091045:\n"
        "cmpb $0, -1(%ecx)\n" /* line 1901 */
        "jne .Lf90f4e_00091062\n"
        "leal -4(%ecx), %edx\n" /* line 1916 */
        "movzwl -4(%ecx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf90f4e_0009115d\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%ecx)\n"
        ".Lf90f4e_00091062:\n"
        "movl %ebx, (%esi)\n" /* line 3223 | tempInt, value1 */
        "jmp .Lf90f4e_00091004\n"
        ".Lf90f4e_00091066:\n"
        "movl $6, 4(%esi)\n" /* line 3192 | value1 */
        "movss (%esi), %xmm0\n" /* line 3193 | value1 */
        "subss (%edi), %xmm0\n" /* value2 */
        "andps CorrectSolidDeltas+3440, %xmm0\n"
        "movss lit4_002ed7e8, %xmm1\n" /* 9.999999974752427e-07f */
        "xorl %eax, %eax\n"
        "ucomiss %xmm0, %xmm1\n"
        "seta %al\n"
        "movl %eax, (%esi)\n" /* value1 */
        "jmp .Lf90f4e_00091004\n"
        ".Lf90f4e_00091093:\n"
        "movl $6, 4(%esi)\n" /* line 3183 | value1 */
        "movl $1, (%esi)\n" /* line 3184 | value1 */
        "jmp .Lf90f4e_00091004\n"
        ".Lf90f4e_000910a5:\n"
        "movl $6, 4(%esi)\n" /* line 3198 | value1 */
        "movl (%esi), %eax\n" /* line 3199 | value1 */
        "xorl %ebx, %ebx\n" /* tempInt */
        "cmpl (%edi), %eax\n" /* value2 */
        "sete %bl\n" /* tempInt */
        "movl %eax, (%esp)\n" /* line 3200 */
        "calll SL_RemoveRefToString\n"
        "movl (%edi), %eax\n" /* line 3201 | value2 */
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movl %ebx, (%esi)\n" /* line 3202 | tempInt, value1 */
        "jmp .Lf90f4e_00091004\n"
        ".Lf90f4e_000910ce:\n"
        "movl (%edi), %eax\n" /* line 3214 | value2 */
        "shll $4, %eax\n"
        "movl scrVarGlob+8(%eax), %eax\n"
        "andl $0x1f, %eax\n"
        "cmpl $0x16, %eax\n"
        "je .Lf90f4e_00090fa6\n"
        ".Lf90f4e_000910e5:\n"
        "movl $6, 4(%esi)\n" /* line 3219 | value1 */
        "xorl %ebx, %ebx\n" /* line 3220 | tempInt */
        "cmpl (%edi), %edx\n" /* value2 */
        "sete %bl\n" /* tempInt */
        "movl %edx, (%esp)\n" /* line 3221 */
        "calll RemoveRefToObject\n"
        "movl (%edi), %eax\n" /* line 3222 | value2 */
        "movl %eax, (%esp)\n"
        "calll RemoveRefToObject\n"
        "movl %ebx, (%esi)\n" /* line 3223 | tempInt, value1 */
        "jmp .Lf90f4e_00091004\n"
        ".Lf90f4e_0009110c:\n"
        "jp .Lf90f4e_00091024\n" /* line 3207 */
        "movss 4(%edx), %xmm0\n"
        "ucomiss 4(%ecx), %xmm0\n"
        "jne .Lf90f4e_00091024\n"
        "jp .Lf90f4e_00091024\n"
        "movss 8(%edx), %xmm0\n"
        "ucomiss 8(%ecx), %xmm0\n"
        "jne .Lf90f4e_00091024\n"
        "jp .Lf90f4e_00091024\n"
        "movl $1, %ebx\n" /* tempInt */
        "jmp .Lf90f4e_00091026\n"
        ".Lf90f4e_00091146:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "movl (%edi), %ecx\n"
        "jmp .Lf90f4e_00091045\n"
        ".Lf90f4e_0009115d:\n"
        "movl $0x10, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll MT_Free\n"
        "movl %ebx, (%esi)\n" /* line 3223 | tempInt, value1 */
        "jmp .Lf90f4e_00091004\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_90f4e_0:\n"
        ".long .Lf90f4e_00091093\n"
        ".long .Lf90f4e_00090f8d\n"
        ".long .Lf90f4e_000910a5\n"
        ".long .Lf90f4e_000910a5\n"
        ".long .Lf90f4e_0009100c\n"
        ".long .Lf90f4e_00091066\n"
        ".long .Lf90f4e_00090ff8\n"
        ".long .Lf90f4e_00090fb3\n"
        ".long .Lf90f4e_00090fb3\n"
        ".long .Lf90f4e_00090ff1\n"
        ".long .Lf90f4e_00090fb3\n"
        ".long .Lf90f4e_00090ff1\n"
        ".text\n"
    );
}

/* line 3241 */
__attribute__((naked))
JCOEF Scr_EvalInequality(VariableValue *value1, VariableValue *value2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3241 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* value1 */
        "movl 0xc(%ebp), %eax\n" /* line 3243 | value2 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* value1 */
        "calll Scr_EvalEquality\n"
        "xorl %eax, %eax\n" /* line 3246 */
        "cmpl $0, (%ebx)\n" /* value1 */
        "sete %al\n"
        "movl %eax, (%ebx)\n" /* value1 */
        "addl $0x14, %esp\n" /* line 3247 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3250 */
__attribute__((naked))
JCOEF Scr_EvalLess(VariableValue *value1, VariableValue *value2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3250 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* value1 */
        "movl 0xc(%ebp), %esi\n" /* value2 */
        /* { scope 1 */
        "movl 4(%ebx), %eax\n" /* line 3021 */
        "movl 4(%esi), %edx\n" /* line 3022 */
        "cmpl %edx, %eax\n" /* line 3024 */
        "je .Lf9119e_000911cf\n"
        "cmpl $5, %eax\n" /* line 3027 */
        "je .Lf9119e_0009121a\n"
        "cmpl $6, %eax\n" /* line 3035 */
        "je .Lf9119e_000911ea\n"
        ".Lf9119e_000911c0:\n"
        "movl %esi, 4(%esp)\n" /* line 3043 */
        "movl %ebx, (%esp)\n"
        "calll Scr_UnmatchingTypesError\n"
        "movl 4(%ebx), %eax\n"
        /* } scope */
        ".Lf9119e_000911cf:\n"
        "cmpl $5, %eax\n" /* line 3256 */
        "je .Lf9119e_000911fe\n"
        "cmpl $6, %eax\n"
        "je .Lf9119e_00091233\n"
        "movl %esi, 0xc(%ebp)\n" /* line 3268 | value2 */
        "movl %ebx, 8(%ebp)\n" /* value1 */
        "addl $0x10, %esp\n" /* line 3269 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp Scr_UnmatchingTypesError\n" /* line 3268 */
        /* { scope 1 */
        ".Lf9119e_000911ea:\n"
        "cmpl $5, %edx\n" /* line 3035 */
        "jne .Lf9119e_000911c0\n"
        "movl $5, 4(%ebx)\n" /* line 3037 */
        "cvtsi2ssl (%ebx), %xmm0\n" /* line 3038 */
        "movss %xmm0, (%ebx)\n"
        /* } scope */
        ".Lf9119e_000911fe:\n"
        "movl $6, 4(%ebx)\n" /* line 3263 | value1 */
        "movss (%esi), %xmm0\n" /* line 3264 | value2 */
        "xorl %eax, %eax\n"
        "ucomiss (%ebx), %xmm0\n" /* value1 */
        "seta %al\n"
        "movl %eax, (%ebx)\n" /* value1 */
        "addl $0x10, %esp\n" /* line 3269 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf9119e_0009121a:\n"
        "cmpl $6, %edx\n" /* line 3027 */
        "jne .Lf9119e_000911c0\n"
        "movl $5, 4(%esi)\n" /* line 3029 */
        "cvtsi2ssl (%esi), %xmm0\n" /* line 3030 */
        "movss %xmm0, (%esi)\n"
        "movl 4(%ebx), %eax\n"
        "jmp .Lf9119e_000911cf\n"
        /* } scope */
        ".Lf9119e_00091233:\n"
        "movl (%ebx), %eax\n" /* line 3259 | value1 */
        "cmpl (%esi), %eax\n" /* value2 */
        "setl %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, (%ebx)\n" /* value1 */
        "addl $0x10, %esp\n" /* line 3269 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3281 */
__attribute__((naked))
JCOEF Scr_EvalGreater(VariableValue *value1, VariableValue *value2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3281 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* value1 */
        "movl 0xc(%ebp), %esi\n" /* value2 */
        /* { scope 1 */
        "movl 4(%ebx), %eax\n" /* line 3021 */
        "movl 4(%esi), %edx\n" /* line 3022 */
        "cmpl %edx, %eax\n" /* line 3024 */
        "je .Lf91246_00091277\n"
        "cmpl $5, %eax\n" /* line 3027 */
        "je .Lf91246_000912ae\n"
        "cmpl $6, %eax\n" /* line 3035 */
        "je .Lf91246_000912da\n"
        ".Lf91246_00091268:\n"
        "movl %esi, 4(%esp)\n" /* line 3043 */
        "movl %ebx, (%esp)\n"
        "calll Scr_UnmatchingTypesError\n"
        "movl 4(%ebx), %eax\n"
        /* } scope */
        ".Lf91246_00091277:\n"
        "cmpl $5, %eax\n" /* line 3287 */
        "je .Lf91246_00091292\n"
        "cmpl $6, %eax\n"
        "je .Lf91246_000912c7\n"
        "movl %esi, 0xc(%ebp)\n" /* line 3299 | value2 */
        "movl %ebx, 8(%ebp)\n" /* value1 */
        "addl $0x10, %esp\n" /* line 3300 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp Scr_UnmatchingTypesError\n" /* line 3299 */
        ".Lf91246_00091292:\n"
        "movss (%ebx), %xmm0\n" /* value1 */
        ".Lf91246_00091296:\n"
        "movl $6, 4(%ebx)\n" /* line 3294 | value1 */
        "xorl %eax, %eax\n" /* line 3295 */
        "ucomiss (%esi), %xmm0\n" /* value2 */
        "seta %al\n"
        "movl %eax, (%ebx)\n" /* value1 */
        "addl $0x10, %esp\n" /* line 3300 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf91246_000912ae:\n"
        "cmpl $6, %edx\n" /* line 3027 */
        "jne .Lf91246_00091268\n"
        "movl $5, 4(%esi)\n" /* line 3029 */
        "cvtsi2ssl (%esi), %xmm0\n" /* line 3030 */
        "movss %xmm0, (%esi)\n"
        "movl 4(%ebx), %eax\n"
        "jmp .Lf91246_00091277\n"
        /* } scope */
        ".Lf91246_000912c7:\n"
        "movl (%ebx), %eax\n" /* line 3290 | value1 */
        "cmpl (%esi), %eax\n" /* value2 */
        "setg %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, (%ebx)\n" /* value1 */
        "addl $0x10, %esp\n" /* line 3300 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf91246_000912da:\n"
        "cmpl $5, %edx\n" /* line 3035 */
        "jne .Lf91246_00091268\n"
        "movl $5, 4(%ebx)\n" /* line 3037 */
        "cvtsi2ssl (%ebx), %xmm0\n" /* line 3038 */
        "movss %xmm0, (%ebx)\n"
        "jmp .Lf91246_00091296\n"
    );
}

/* line 3400 */
__attribute__((naked))
JCOEF Scr_EvalMinus(VariableValue *value1, VariableValue *value2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3400 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* value1 */
        "movl 0xc(%ebp), %esi\n" /* value2 */
        /* { scope 1 */
        /* { scope 2 */
        "movl 4(%ebx), %eax\n" /* line 3021 */
        "movl 4(%esi), %edx\n" /* line 3022 */
        "cmpl %edx, %eax\n" /* line 3024 */
        "je .Lf912f0_00091322\n"
        "cmpl $5, %eax\n" /* line 3027 */
        "je .Lf912f0_00091357\n"
        "cmpl $6, %eax\n" /* line 3035 */
        "je .Lf912f0_0009137e\n"
        ".Lf912f0_00091313:\n"
        "movl %esi, 4(%esp)\n" /* line 3043 */
        "movl %ebx, (%esp)\n"
        "calll Scr_UnmatchingTypesError\n"
        "movl 4(%ebx), %eax\n"
        /* } scope */
        ".Lf912f0_00091322:\n"
        "cmpl $5, %eax\n" /* line 3408 */
        "je .Lf912f0_00091343\n"
        "cmpl $6, %eax\n"
        "je .Lf912f0_00091370\n"
        "cmpl $4, %eax\n"
        "je .Lf912f0_00091394\n"
        "movl %esi, 0xc(%ebp)\n" /* line 3429 | value2 */
        "movl %ebx, 8(%ebp)\n" /* value1 */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 3430 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_UnmatchingTypesError\n" /* line 3429 */
        ".Lf912f0_00091343:\n"
        "movss (%ebx), %xmm0\n" /* value1 */
        ".Lf912f0_00091347:\n"
        "subss (%esi), %xmm0\n" /* line 3415 | value2 */
        "movss %xmm0, (%ebx)\n" /* value1 */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 3430 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf912f0_00091357:\n"
        "cmpl $6, %edx\n" /* line 3027 */
        "jne .Lf912f0_00091313\n"
        "movl $5, 4(%esi)\n" /* line 3029 */
        "cvtsi2ssl (%esi), %xmm0\n" /* line 3030 */
        "movss %xmm0, (%esi)\n"
        "movl 4(%ebx), %eax\n"
        "jmp .Lf912f0_00091322\n"
        /* } scope */
        ".Lf912f0_00091370:\n"
        "movl (%ebx), %eax\n" /* line 3411 | value1 */
        "subl (%esi), %eax\n" /* value2 */
        "movl %eax, (%ebx)\n" /* value1 */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 3430 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf912f0_0009137e:\n"
        "cmpl $5, %edx\n" /* line 3035 */
        "jne .Lf912f0_00091313\n"
        "movl $5, 4(%ebx)\n" /* line 3037 */
        "cvtsi2ssl (%ebx), %xmm0\n" /* line 3038 */
        "movss %xmm0, (%ebx)\n"
        "jmp .Lf912f0_00091347\n"
        /* } scope */
        ".Lf912f0_00091394:\n"
        "movl $2, 4(%esp)\n" /* line 1846 */
        "movl $0x10, (%esp)\n"
        "calll MT_Alloc\n"
        "leal 4(%eax), %edi\n"
        "movl $0, -4(%edi)\n" /* line 1848 */
        "movl (%ebx), %edx\n" /* line 3420 | value1 */
        "movl (%esi), %ecx\n" /* value2 */
        "movss (%edx), %xmm0\n"
        "subss (%ecx), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movl (%ebx), %eax\n" /* line 3421 | value1 */
        "movl (%esi), %edx\n" /* value2 */
        "movss 4(%eax), %xmm0\n"
        "subss 4(%edx), %xmm0\n"
        "movss %xmm0, 4(%edi)\n" /* tempVector */
        "movl (%ebx), %eax\n" /* line 3422 | value1 */
        "movl (%esi), %edx\n" /* value2 */
        "movss 8(%eax), %xmm0\n"
        "subss 8(%edx), %xmm0\n"
        "movss %xmm0, 8(%edi)\n" /* tempVector */
        "movl (%ebx), %edx\n" /* line 3423 | value1, vectorValue */
        /* { scope 2 */
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf912f0_00091404\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf912f0_0009143d\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        /* } scope */
        ".Lf912f0_00091404:\n"
        "movl (%esi), %edx\n" /* line 3424 | value2, vectorValue */
        /* { scope 2 */
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf912f0_0009141f\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf912f0_00091429\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        /* } scope */
        ".Lf912f0_0009141f:\n"
        "movl %edi, (%ebx)\n" /* line 3425 | tempVector, value1 */
        /* } scope */
        ".Lf912f0_00091421:\n"
        "addl $0x1c, %esp\n" /* line 3430 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf912f0_00091429:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        /* } scope */
        "movl %edi, (%ebx)\n" /* line 3425 | tempVector, value1 */
        "jmp .Lf912f0_00091421\n"
        /* { scope 2 */
        ".Lf912f0_0009143d:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "jmp .Lf912f0_00091404\n"
    );
}

/* line 3507 */
__attribute__((naked))
JCOEF Scr_EvalBinaryOperator(int op, VariableValue *value1, VariableValue *value2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3507 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* value1 */
        "movl 0x10(%ebp), %ebx\n" /* value2 */
        "movl 8(%ebp), %eax\n" /* line 3509 | op */
        "subl $0x66, %eax\n"
        "cmpl $0xf, %eax\n"
        "ja .Lf91450_000914c3\n"
        "jmpl *.Ljt_91450_0(, %eax, 4)\n"
        /* { scope 1 */
        ".Lf91450_00091470:\n"
        "movl 4(%esi), %eax\n" /* line 3021 */
        "movl 4(%ebx), %edx\n" /* line 3022 */
        "cmpl %edx, %eax\n" /* line 3024 */
        "je .Lf91450_0009149b\n"
        "cmpl $5, %eax\n" /* line 3027 */
        "je .Lf91450_000917d8\n"
        "cmpl $6, %eax\n" /* line 3035 */
        "je .Lf91450_00091741\n"
        ".Lf91450_0009148c:\n"
        "movl %ebx, 4(%esp)\n" /* line 3043 */
        "movl %esi, (%esp)\n"
        "calll Scr_UnmatchingTypesError\n"
        "movl 4(%esi), %eax\n"
        /* } scope */
        ".Lf91450_0009149b:\n"
        "cmpl $5, %eax\n" /* line 3256 */
        "je .Lf91450_00091759\n"
        "cmpl $6, %eax\n"
        "je .Lf91450_00091858\n"
        ".Lf91450_000914ad:\n"
        "movl %ebx, 4(%esp)\n" /* line 3268 */
        "movl %esi, (%esp)\n"
        "calll Scr_UnmatchingTypesError\n"
        ".Lf91450_000914b9:\n"
        "xorl %eax, %eax\n" /* line 3277 */
        "cmpl $0, (%esi)\n"
        "sete %al\n"
        "movl %eax, (%esi)\n"
        ".Lf91450_000914c3:\n"
        "addl $0x10, %esp\n" /* line 3575 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf91450_000914ca:\n"
        "cmpl $6, 4(%esi)\n" /* line 3138 */
        "jne .Lf91450_000914da\n"
        "cmpl $6, 4(%ebx)\n"
        "je .Lf91450_000918c0\n"
        ".Lf91450_000914da:\n"
        "movl %ebx, 0xc(%ebp)\n" /* line 3503 | value1 */
        "movl %esi, 8(%ebp)\n" /* op */
        "addl $0x10, %esp\n" /* line 3575 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp Scr_UnmatchingTypesError\n" /* line 3503 */
        ".Lf91450_000914eb:\n"
        "cmpl $6, 4(%esi)\n" /* line 3314 */
        "jne .Lf91450_000914da\n"
        "cmpl $6, 4(%ebx)\n"
        "jne .Lf91450_000914da\n"
        "movl (%ebx), %ecx\n" /* line 3316 */
        "shll %cl, (%esi)\n"
        "jmp .Lf91450_000914c3\n"
        ".Lf91450_000914fd:\n"
        "movl %ebx, 4(%esp)\n" /* line 3243 */
        "movl %esi, (%esp)\n"
        "calll Scr_EvalEquality\n"
        "xorl %eax, %eax\n" /* line 3246 */
        "cmpl $0, (%esi)\n"
        "sete %al\n"
        "movl %eax, (%esi)\n"
        "jmp .Lf91450_000914c3\n"
        /* { scope 1 */
        ".Lf91450_00091515:\n"
        "movl 4(%esi), %eax\n" /* line 3021 */
        "movl 4(%ebx), %edx\n" /* line 3022 */
        "cmpl %edx, %eax\n" /* line 3024 */
        "je .Lf91450_00091540\n"
        "cmpl $5, %eax\n" /* line 3027 */
        "je .Lf91450_00091818\n"
        "cmpl $6, %eax\n" /* line 3035 */
        "je .Lf91450_0009170f\n"
        ".Lf91450_00091531:\n"
        "movl %ebx, 4(%esp)\n" /* line 3043 */
        "movl %esi, (%esp)\n"
        "calll Scr_UnmatchingTypesError\n"
        "movl 4(%esi), %eax\n"
        /* } scope */
        ".Lf91450_00091540:\n"
        "cmpl $5, %eax\n" /* line 3256 */
        "je .Lf91450_00091727\n"
        "cmpl $6, %eax\n"
        "jne .Lf91450_000914da\n"
        "movl (%esi), %eax\n" /* line 3259 */
        "cmpl (%ebx), %eax\n"
        "setl %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, (%esi)\n"
        "jmp .Lf91450_000914c3\n"
        /* { scope 1 */
        ".Lf91450_0009155f:\n"
        "movl 4(%esi), %eax\n" /* line 3021 */
        "movl 4(%ebx), %edx\n" /* line 3022 */
        "cmpl %edx, %eax\n" /* line 3024 */
        "je .Lf91450_0009158a\n"
        "cmpl $5, %eax\n" /* line 3027 */
        "je .Lf91450_00091838\n"
        "cmpl $6, %eax\n" /* line 3035 */
        "je .Lf91450_00091886\n"
        ".Lf91450_0009157b:\n"
        "movl %ebx, 4(%esp)\n" /* line 3043 */
        "movl %esi, (%esp)\n"
        "calll Scr_UnmatchingTypesError\n"
        "movl 4(%esi), %eax\n"
        /* } scope */
        ".Lf91450_0009158a:\n"
        "cmpl $5, %eax\n" /* line 3287 */
        "je .Lf91450_00091773\n"
        "cmpl $6, %eax\n"
        "jne .Lf91450_000914da\n"
        "movl (%esi), %eax\n" /* line 3290 */
        "cmpl (%ebx), %eax\n"
        "setg %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, (%esi)\n"
        "jmp .Lf91450_000914c3\n"
        ".Lf91450_000915ad:\n"
        "movl %ebx, 0xc(%ebp)\n" /* line 3560 | value2, value1 */
        "movl %esi, 8(%ebp)\n" /* value1, op */
        "addl $0x10, %esp\n" /* line 3575 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp Scr_EvalMinus\n" /* line 3560 */
        ".Lf91450_000915be:\n"
        "cmpl $6, 4(%esi)\n" /* line 3162 */
        "jne .Lf91450_000914da\n"
        "cmpl $6, 4(%ebx)\n"
        "jne .Lf91450_000914da\n"
        "movl (%esi), %eax\n" /* line 3164 */
        "andl (%ebx), %eax\n"
        "movl %eax, (%esi)\n"
        "jmp .Lf91450_000914c3\n"
        ".Lf91450_000915dd:\n"
        "movl %ebx, 0xc(%ebp)\n" /* line 3524 | value2, value1 */
        "movl %esi, 8(%ebp)\n" /* value1, op */
        "addl $0x10, %esp\n" /* line 3575 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp Scr_EvalEquality\n" /* line 3524 */
        ".Lf91450_000915ee:\n"
        "cmpl $6, 4(%esi)\n" /* line 3150 */
        "jne .Lf91450_000914da\n"
        "cmpl $6, 4(%ebx)\n"
        "jne .Lf91450_000914da\n"
        "movl (%esi), %eax\n" /* line 3152 */
        "xorl (%ebx), %eax\n"
        "movl %eax, (%esi)\n"
        "jmp .Lf91450_000914c3\n"
        /* { scope 1 */
        ".Lf91450_0009160d:\n"
        "movl 4(%esi), %eax\n" /* line 3021 */
        "movl 4(%ebx), %edx\n" /* line 3022 */
        "cmpl %edx, %eax\n" /* line 3024 */
        "je .Lf91450_00091638\n"
        "cmpl $5, %eax\n" /* line 3027 */
        "je .Lf91450_000917b8\n"
        "cmpl $6, %eax\n" /* line 3035 */
        "je .Lf91450_000918a3\n"
        ".Lf91450_00091629:\n"
        "movl %ebx, 4(%esp)\n" /* line 3043 */
        "movl %esi, (%esp)\n"
        "calll Scr_UnmatchingTypesError\n"
        "movl 4(%esi), %eax\n"
        /* } scope */
        ".Lf91450_00091638:\n"
        "cmpl $5, %eax\n" /* line 3287 */
        "je .Lf91450_0009178d\n"
        "cmpl $6, %eax\n"
        "jne .Lf91450_000914ad\n"
        "movl (%esi), %eax\n" /* line 3290 */
        "cmpl (%ebx), %eax\n"
        "setg %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, (%esi)\n"
        "jmp .Lf91450_000914b9\n"
        ".Lf91450_0009165b:\n"
        "cmpl $6, 4(%esi)\n" /* line 3326 */
        "jne .Lf91450_000914da\n"
        "cmpl $6, 4(%ebx)\n"
        "jne .Lf91450_000914da\n"
        "movl (%ebx), %ecx\n" /* line 3328 */
        "sarl %cl, (%esi)\n"
        "jmp .Lf91450_000914c3\n"
        ".Lf91450_00091678:\n"
        "movl %ebx, 0xc(%ebp)\n" /* line 3568 | value2, value1 */
        "movl %esi, 8(%ebp)\n" /* value1, op */
        "addl $0x10, %esp\n" /* line 3575 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp Scr_EvalDivide\n" /* line 3568 */
        ".Lf91450_00091689:\n"
        "cmpl $6, 4(%esi)\n" /* line 3491 */
        "jne .Lf91450_000914da\n"
        "cmpl $6, 4(%ebx)\n"
        "jne .Lf91450_000914da\n"
        "movl (%ebx), %edx\n" /* line 3493 */
        "testl %edx, %edx\n"
        "je .Lf91450_000918cb\n"
        "movl (%esi), %eax\n" /* line 3495 */
        "movl %edx, %ecx\n"
        "cltd\n"
        "idivl %ecx\n"
        "movl %edx, (%esi)\n"
        "jmp .Lf91450_000914c3\n"
        /* { scope 1 */
        ".Lf91450_000916b5:\n"
        "movl 4(%esi), %eax\n" /* line 3021 */
        "movl 4(%ebx), %edx\n" /* line 3022 */
        "cmpl %edx, %eax\n" /* line 3024 */
        "je .Lf91450_000916e0\n"
        "cmpl $5, %eax\n" /* line 3027 */
        "je .Lf91450_000917f8\n"
        "cmpl $6, %eax\n" /* line 3035 */
        "je .Lf91450_00091869\n"
        ".Lf91450_000916d1:\n"
        "movl %ebx, 4(%esp)\n" /* line 3043 */
        "movl %esi, (%esp)\n"
        "calll Scr_UnmatchingTypesError\n"
        "movl 4(%esi), %eax\n"
        /* } scope */
        ".Lf91450_000916e0:\n"
        "cmpl $5, %eax\n" /* line 3439 */
        "je .Lf91450_000917a7\n"
        "cmpl $6, %eax\n"
        "jne .Lf91450_000914da\n"
        "movl (%esi), %eax\n" /* line 3442 */
        "imull (%ebx), %eax\n"
        "movl %eax, (%esi)\n"
        "jmp .Lf91450_000914c3\n"
        ".Lf91450_000916fe:\n"
        "movl %ebx, 0xc(%ebp)\n" /* line 3556 | value2, value1 */
        "movl %esi, 8(%ebp)\n" /* value1, op */
        "addl $0x10, %esp\n" /* line 3575 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp Scr_EvalPlus\n" /* line 3556 */
        /* { scope 1 */
        ".Lf91450_0009170f:\n"
        "cmpl $5, %edx\n" /* line 3035 */
        "jne .Lf91450_00091531\n"
        "movl $5, 4(%esi)\n" /* line 3037 */
        "cvtsi2ssl (%esi), %xmm0\n" /* line 3038 */
        "movss %xmm0, (%esi)\n"
        /* } scope */
        ".Lf91450_00091727:\n"
        "movl $6, 4(%esi)\n" /* line 3263 */
        "movss (%ebx), %xmm0\n" /* line 3264 */
        "xorl %eax, %eax\n"
        "ucomiss (%esi), %xmm0\n"
        "seta %al\n"
        "movl %eax, (%esi)\n"
        "jmp .Lf91450_000914c3\n"
        /* { scope 1 */
        ".Lf91450_00091741:\n"
        "cmpl $5, %edx\n" /* line 3035 */
        "jne .Lf91450_0009148c\n"
        "movl $5, 4(%esi)\n" /* line 3037 */
        "cvtsi2ssl (%esi), %xmm0\n" /* line 3038 */
        "movss %xmm0, (%esi)\n"
        /* } scope */
        ".Lf91450_00091759:\n"
        "movl $6, 4(%esi)\n" /* line 3263 */
        "movss (%ebx), %xmm0\n" /* line 3264 */
        "xorl %eax, %eax\n"
        "ucomiss (%esi), %xmm0\n"
        "seta %al\n"
        "movl %eax, (%esi)\n"
        "jmp .Lf91450_000914b9\n"
        ".Lf91450_00091773:\n"
        "movss (%esi), %xmm0\n"
        ".Lf91450_00091777:\n"
        "movl $6, 4(%esi)\n" /* line 3294 */
        "xorl %eax, %eax\n" /* line 3295 */
        "ucomiss (%ebx), %xmm0\n"
        "seta %al\n"
        "movl %eax, (%esi)\n"
        "jmp .Lf91450_000914c3\n"
        ".Lf91450_0009178d:\n"
        "movss (%esi), %xmm0\n"
        ".Lf91450_00091791:\n"
        "movl $6, 4(%esi)\n" /* line 3294 */
        "xorl %eax, %eax\n" /* line 3295 */
        "ucomiss (%ebx), %xmm0\n"
        "seta %al\n"
        "movl %eax, (%esi)\n"
        "jmp .Lf91450_000914b9\n"
        ".Lf91450_000917a7:\n"
        "movss (%esi), %xmm0\n"
        ".Lf91450_000917ab:\n"
        "mulss (%ebx), %xmm0\n" /* line 3446 */
        "movss %xmm0, (%esi)\n"
        "jmp .Lf91450_000914c3\n"
        /* { scope 1 */
        ".Lf91450_000917b8:\n"
        "cmpl $6, %edx\n" /* line 3027 */
        "jne .Lf91450_00091629\n"
        "movl $5, 4(%ebx)\n" /* line 3029 */
        "cvtsi2ssl (%ebx), %xmm0\n" /* line 3030 */
        "movss %xmm0, (%ebx)\n"
        "movl 4(%esi), %eax\n"
        "jmp .Lf91450_00091638\n"
        /* } scope */
        /* { scope 1 */
        ".Lf91450_000917d8:\n"
        "cmpl $6, %edx\n" /* line 3027 */
        "jne .Lf91450_0009148c\n"
        "movl $5, 4(%ebx)\n" /* line 3029 */
        "cvtsi2ssl (%ebx), %xmm0\n" /* line 3030 */
        "movss %xmm0, (%ebx)\n"
        "movl 4(%esi), %eax\n"
        "jmp .Lf91450_0009149b\n"
        /* } scope */
        /* { scope 1 */
        ".Lf91450_000917f8:\n"
        "cmpl $6, %edx\n" /* line 3027 */
        "jne .Lf91450_000916d1\n"
        "movl $5, 4(%ebx)\n" /* line 3029 */
        "cvtsi2ssl (%ebx), %xmm0\n" /* line 3030 */
        "movss %xmm0, (%ebx)\n"
        "movl 4(%esi), %eax\n"
        "jmp .Lf91450_000916e0\n"
        /* } scope */
        /* { scope 1 */
        ".Lf91450_00091818:\n"
        "cmpl $6, %edx\n" /* line 3027 */
        "jne .Lf91450_00091531\n"
        "movl $5, 4(%ebx)\n" /* line 3029 */
        "cvtsi2ssl (%ebx), %xmm0\n" /* line 3030 */
        "movss %xmm0, (%ebx)\n"
        "movl 4(%esi), %eax\n"
        "jmp .Lf91450_00091540\n"
        /* } scope */
        /* { scope 1 */
        ".Lf91450_00091838:\n"
        "cmpl $6, %edx\n" /* line 3027 */
        "jne .Lf91450_0009157b\n"
        "movl $5, 4(%ebx)\n" /* line 3029 */
        "cvtsi2ssl (%ebx), %xmm0\n" /* line 3030 */
        "movss %xmm0, (%ebx)\n"
        "movl 4(%esi), %eax\n"
        "jmp .Lf91450_0009158a\n"
        /* } scope */
        ".Lf91450_00091858:\n"
        "movl (%esi), %eax\n" /* line 3259 */
        "cmpl (%ebx), %eax\n"
        "setl %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, (%esi)\n"
        "jmp .Lf91450_000914b9\n"
        /* { scope 1 */
        ".Lf91450_00091869:\n"
        "cmpl $5, %edx\n" /* line 3035 */
        "jne .Lf91450_000916d1\n"
        "movl $5, 4(%esi)\n" /* line 3037 */
        "cvtsi2ssl (%esi), %xmm0\n" /* line 3038 */
        "movss %xmm0, (%esi)\n"
        "jmp .Lf91450_000917ab\n"
        /* } scope */
        /* { scope 1 */
        ".Lf91450_00091886:\n"
        "cmpl $5, %edx\n" /* line 3035 */
        "jne .Lf91450_0009157b\n"
        "movl $5, 4(%esi)\n" /* line 3037 */
        "cvtsi2ssl (%esi), %xmm0\n" /* line 3038 */
        "movss %xmm0, (%esi)\n"
        "jmp .Lf91450_00091777\n"
        /* } scope */
        /* { scope 1 */
        ".Lf91450_000918a3:\n"
        "cmpl $5, %edx\n" /* line 3035 */
        "jne .Lf91450_00091629\n"
        "movl $5, 4(%esi)\n" /* line 3037 */
        "cvtsi2ssl (%esi), %xmm0\n" /* line 3038 */
        "movss %xmm0, (%esi)\n"
        "jmp .Lf91450_00091791\n"
        /* } scope */
        ".Lf91450_000918c0:\n"
        "movl (%esi), %eax\n" /* line 3140 */
        "orl (%ebx), %eax\n"
        "movl %eax, (%esi)\n"
        "jmp .Lf91450_000914c3\n"
        ".Lf91450_000918cb:\n"
        "movl $0, (%esi)\n" /* line 3498 */
        "movl $str_0021d694, 8(%ebp)\n" /* line 3499 | op */
        "addl $0x10, %esp\n" /* line 3575 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp Scr_Error\n" /* line 3499 */
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_91450_0:\n"
        ".long .Lf91450_000914ca\n"
        ".long .Lf91450_000915ee\n"
        ".long .Lf91450_000915be\n"
        ".long .Lf91450_000915dd\n"
        ".long .Lf91450_000914fd\n"
        ".long .Lf91450_00091515\n"
        ".long .Lf91450_0009155f\n"
        ".long .Lf91450_0009160d\n"
        ".long .Lf91450_00091470\n"
        ".long .Lf91450_000914eb\n"
        ".long .Lf91450_0009165b\n"
        ".long .Lf91450_000916fe\n"
        ".long .Lf91450_000915ad\n"
        ".long .Lf91450_000916b5\n"
        ".long .Lf91450_00091678\n"
        ".long .Lf91450_00091689\n"
        ".text\n"
    );
}

/* line 3433 */
__attribute__((naked))
JCOEF Scr_EvalMultiply(VariableValue *value1, VariableValue *value2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3433 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* value1 */
        "movl 0xc(%ebp), %esi\n" /* value2 */
        /* { scope 1 */
        "movl 4(%ebx), %eax\n" /* line 3021 */
        "movl 4(%esi), %edx\n" /* line 3022 */
        "cmpl %edx, %eax\n" /* line 3024 */
        "je .Lf918e4_00091915\n"
        "cmpl $5, %eax\n" /* line 3027 */
        "je .Lf918e4_00091943\n"
        "cmpl $6, %eax\n" /* line 3035 */
        "je .Lf918e4_0009196a\n"
        ".Lf918e4_00091906:\n"
        "movl %esi, 4(%esp)\n" /* line 3043 */
        "movl %ebx, (%esp)\n"
        "calll Scr_UnmatchingTypesError\n"
        "movl 4(%ebx), %eax\n"
        /* } scope */
        ".Lf918e4_00091915:\n"
        "cmpl $5, %eax\n" /* line 3439 */
        "je .Lf918e4_00091930\n"
        "cmpl $6, %eax\n"
        "je .Lf918e4_0009195c\n"
        "movl %esi, 0xc(%ebp)\n" /* line 3450 | value2 */
        "movl %ebx, 8(%ebp)\n" /* value1 */
        "addl $0x10, %esp\n" /* line 3451 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp Scr_UnmatchingTypesError\n" /* line 3450 */
        ".Lf918e4_00091930:\n"
        "movss (%ebx), %xmm0\n" /* value1 */
        ".Lf918e4_00091934:\n"
        "mulss (%esi), %xmm0\n" /* line 3446 | value2 */
        "movss %xmm0, (%ebx)\n" /* value1 */
        "addl $0x10, %esp\n" /* line 3451 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf918e4_00091943:\n"
        "cmpl $6, %edx\n" /* line 3027 */
        "jne .Lf918e4_00091906\n"
        "movl $5, 4(%esi)\n" /* line 3029 */
        "cvtsi2ssl (%esi), %xmm0\n" /* line 3030 */
        "movss %xmm0, (%esi)\n"
        "movl 4(%ebx), %eax\n"
        "jmp .Lf918e4_00091915\n"
        /* } scope */
        ".Lf918e4_0009195c:\n"
        "movl (%ebx), %eax\n" /* line 3442 | value1 */
        "imull (%esi), %eax\n" /* value2 */
        "movl %eax, (%ebx)\n" /* value1 */
        "addl $0x10, %esp\n" /* line 3451 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf918e4_0009196a:\n"
        "cmpl $5, %edx\n" /* line 3035 */
        "jne .Lf918e4_00091906\n"
        "movl $5, 4(%ebx)\n" /* line 3037 */
        "cvtsi2ssl (%ebx), %xmm0\n" /* line 3038 */
        "movss %xmm0, (%ebx)\n"
        "jmp .Lf918e4_00091934\n"
    );
}

/* line 2799 */
__attribute__((naked))
JCOEF Scr_CastBool(VariableValue *value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2799 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* value */
        "movl 4(%esi), %ebx\n" /* line 2803 | value */
        /* Fix #155: treat undefined (type 0) as false instead of erroring.
           Script threads execute immediately, so level vars like level.xenon
           may be checked before they're set by the parent thread. */
        "testl %ebx, %ebx\n"
        "jz .Lf91980_castbool_undef\n"
        "cmpl $6, %ebx\n"
        "je .Lf91980_000919df\n"
        "cmpl $5, %ebx\n" /* line 2809 */
        "je .Lf91980_000919f0\n"
        "movl (%esi), %edx\n" /* line 252 */
        "cmpl $3, %ebx\n" /* line 1946 */
        "jle .Lf91980_000919d0\n"
        "cmpl $4, %ebx\n"
        "je .Lf91980_00091a12\n"
        ".Lf91980_000919a4:\n"
        /* Unhandled types (thread, removed entity/thread, etc.) → false */
        "movl $0, (%esi)\n"
        "movl $6, 4(%esi)\n"
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf91980_000919d0:\n"
        "cmpl $2, %ebx\n" /* line 1946 */
        "jl .Lf91980_00091a30\n"
        "movl %edx, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        "jmp .Lf91980_000919a4\n"
        ".Lf91980_000919df:\n"
        "xorl %eax, %eax\n" /* line 2805 */
        "cmpl $0, (%esi)\n" /* value */
        "setne %al\n"
        "movl %eax, (%esi)\n" /* value */
        "addl $0x10, %esp\n" /* line 2820 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf91980_000919f0:\n"
        "movl $6, 4(%esi)\n" /* line 2811 | value */
        "pxor %xmm0, %xmm0\n" /* line 2812 */
        "ucomiss (%esi), %xmm0\n" /* value */
        "setne %al\n"
        "setp %dl\n"
        "orb %dl, %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, (%esi)\n" /* value */
        "addl $0x10, %esp\n" /* line 2820 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf91980_00091a12:\n"
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf91980_000919a4\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf91980_00091a46\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        "jmp .Lf91980_000919a4\n"
        ".Lf91980_00091a30:\n"
        "cmpl $1, %ebx\n" /* line 1946 */
        "jne .Lf91980_000919a4\n"
        "movl %edx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "jmp .Lf91980_000919a4\n"
        ".Lf91980_00091a46:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "jmp .Lf91980_000919a4\n"
        /* Fix #155: undefined → false */
        ".Lf91980_castbool_undef:\n"
        "movl $0, (%esi)\n"       /* value = 0 (false) */
        "movl $6, 4(%esi)\n"      /* type = int */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2782 */
__attribute__((naked))
JCOEF Scr_EvalBoolComplement(VariableValue *value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2782 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* value */
        "movl 4(%esi), %ebx\n" /* line 2786 | value */
        "cmpl $6, %ebx\n"
        "je .Lf91a5c_00091acf\n"
        "movl (%esi), %edx\n" /* line 252 */
        "cmpl $3, %ebx\n" /* line 1946 */
        "jg .Lf91a5c_00091aaf\n"
        "cmpl $2, %ebx\n"
        "jl .Lf91a5c_00091ad8\n"
        "movl %edx, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        ".Lf91a5c_00091a83:\n"
        "movl $0, 4(%esi)\n" /* line 2794 | value */
        "movl var_typename(, %ebx, 4), %eax\n" /* line 2795 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021d6dc, (%esp)\n" /* "~ cannot be applied to "%s"" */
        "calll va\n"
        "movl %eax, 8(%ebp)\n" /* value */
        "addl $0x10, %esp\n" /* line 2796 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp Scr_Error\n" /* line 2795 */
        ".Lf91a5c_00091aaf:\n"
        "cmpl $4, %ebx\n" /* line 1946 */
        "jne .Lf91a5c_00091a83\n"
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf91a5c_00091a83\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf91a5c_00091ae7\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        "jmp .Lf91a5c_00091a83\n"
        ".Lf91a5c_00091acf:\n"
        "notl (%esi)\n" /* line 2788 | value */
        "addl $0x10, %esp\n" /* line 2796 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf91a5c_00091ad8:\n"
        "cmpl $1, %ebx\n" /* line 1946 */
        "jne .Lf91a5c_00091a83\n"
        "movl %edx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "jmp .Lf91a5c_00091a83\n"
        ".Lf91a5c_00091ae7:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "jmp .Lf91a5c_00091a83\n"
    );
}

/* line 2598 */
__attribute__((naked))
JCOEF Scr_EvalSizeValue(VariableValue *value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2598 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* value */
        /* { scope 1 */
        "movl 4(%esi), %eax\n" /* line 2605 | value */
        "cmpl $1, %eax\n"
        "je .Lf91afa_00091b80\n"
        "cmpl $2, %eax\n" /* line 2615 */
        "je .Lf91afa_00091bb9\n"
        "movl var_typename(, %eax, 4), %eax\n" /* line 2625 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021d6f8, (%esp)\n" /* "size cannot be applied to %s" */
        "calll va\n"
        "movl %eax, %ebx\n" /* error_message */
        "movl (%esi), %edx\n" /* line 252 */
        "movl 4(%esi), %eax\n" /* type */
        /* { scope 2 */
        "cmpl $3, %eax\n" /* line 1946 */
        "jle .Lf91afa_00091b59\n"
        "cmpl $4, %eax\n"
        "je .Lf91afa_00091bec\n"
        /* } scope */
        ".Lf91afa_00091b43:\n"
        "movl $0, 4(%esi)\n" /* line 2628 | value */
        "movl %ebx, 8(%ebp)\n" /* line 2630 | error_message, value */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 2631 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_Error\n" /* line 2630 */
        /* { scope 2 */
        ".Lf91afa_00091b59:\n"
        "cmpl $2, %eax\n" /* line 1946 */
        "jl .Lf91afa_00091c0e\n"
        "movl %edx, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        /* } scope */
        "movl $0, 4(%esi)\n" /* line 2628 | value */
        "movl %ebx, 8(%ebp)\n" /* line 2630 | error_message, value */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 2631 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_Error\n" /* line 2630 */
        ".Lf91afa_00091b80:\n"
        "movl (%esi), %ecx\n" /* line 2607 | value */
        "movl %ecx, %eax\n" /* line 2608 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl $6, 4(%esi)\n" /* line 2609 | value */
        "movl 8(%edx), %eax\n" /* line 2610 */
        "andl $0x1f, %eax\n"
        "cmpl $0x16, %eax\n"
        "je .Lf91afa_00091c24\n"
        "movl $1, %eax\n"
        ".Lf91afa_00091ba8:\n"
        "movl %eax, (%esi)\n" /* value */
        "movl %ecx, 8(%ebp)\n" /* line 2611 | value */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 2631 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp RemoveRefToObject\n" /* line 2611 */
        ".Lf91afa_00091bb9:\n"
        "movl $6, 4(%esi)\n" /* line 2617 | value */
        "movl (%esi), %ebx\n" /* line 2618 | value, error_message */
        "movl %ebx, (%esp)\n" /* line 2619 | error_message */
        "calll SL_ConvertToString\n"
        "movl %eax, %edi\n"
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, (%esi)\n" /* value */
        "movl %ebx, 8(%ebp)\n" /* line 2620 | error_message, value */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 2631 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp SL_RemoveRefToString\n" /* line 2620 */
        /* { scope 2 */
        ".Lf91afa_00091bec:\n"
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf91afa_00091b43\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf91afa_00091c2d\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        "jmp .Lf91afa_00091b43\n"
        ".Lf91afa_00091c0e:\n"
        "subl $1, %eax\n" /* line 1946 */
        "jne .Lf91afa_00091b43\n"
        "movl %edx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "jmp .Lf91afa_00091b43\n"
        /* } scope */
        ".Lf91afa_00091c24:\n"
        "movzwl 6(%edx), %eax\n" /* line 2610 */
        "jmp .Lf91afa_00091ba8\n"
        /* { scope 2 */
        ".Lf91afa_00091c2d:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "jmp .Lf91afa_00091b43\n"
    );
}

/* line 2925 */
__attribute__((naked))
JCOEF Scr_CastVector(VariableValue *value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2925 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %eax\n" /* value */
        "movl %eax, -0x30(%ebp)\n" /* value */
        "addl $0x10, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl -0x30(%ebp), %edx\n" /* value */
        "addl $0x14, %edx\n"
        "xorl %ebx, %ebx\n"
        "movl $3, %edi\n"
        "leal -0x24(%ebp), %ecx\n" /* vec */
        /* { scope 1 */
        ".Lf91c42_00091c67:\n"
        "movl (%edx), %esi\n" /* line 2933 | type */
        "cmpl $5, %esi\n" /* line 2934 | type */
        "je .Lf91c42_00091cd4\n"
        "cmpl $6, %esi\n" /* line 2939 | type */
        "jne .Lf91c42_00091cdb\n"
        "cvtsi2ssl -4(%edx), %xmm0\n" /* line 2941 */
        "movss %xmm0, (%ecx)\n"
        ".Lf91c42_00091c7c:\n"
        "addl $1, %ebx\n" /* line 2948 */
        "addl $4, %ecx\n"
        "subl $1, %edi\n"
        "subl $8, %edx\n"
        "cmpl $3, %ebx\n" /* line 2931 */
        "jne .Lf91c42_00091c67\n"
        "movl -0x30(%ebp), %eax\n" /* line 2952 | value */
        "movl $4, 4(%eax)\n"
        /* { scope 2 */
        "movl $2, 4(%esp)\n" /* line 1846 */
        "movl $0x10, (%esp)\n"
        "calll MT_Alloc\n"
        "leal 4(%eax), %ecx\n"
        "movl $0, -4(%ecx)\n" /* line 1848 */
        "movl -0x24(%ebp), %edx\n" /* line 1870 | vec */
        "movl %edx, 4(%eax)\n"
        "movl -0x20(%ebp), %eax\n" /* line 1871 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1872 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 2953 | value */
        "movl %ecx, (%eax)\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2954 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf91c42_00091cd4:\n"
        "movl -4(%edx), %eax\n" /* line 2936 */
        "movl %eax, (%ecx)\n"
        "jmp .Lf91c42_00091c7c\n"
        ".Lf91c42_00091cdb:\n"
        "movl %edi, scrVarPub+20\n" /* line 2946 */
        "movl -0x2c(%ebp), %ebx\n"
        "movl $3, %edi\n"
        ".Lf91c42_00091ce9:\n"
        "movl (%ebx), %edx\n" /* line 252 */
        "movl 4(%ebx), %eax\n" /* type */
        /* { scope 2 */
        "cmpl $3, %eax\n" /* line 1946 */
        "jg .Lf91c42_00091d38\n"
        "cmpl $2, %eax\n"
        "jl .Lf91c42_00091d58\n"
        "movl %edx, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        ".Lf91c42_00091d00:\n"
        "subl $8, %ebx\n" /* line 1922 */
        /* } scope */
        "subl $1, %edi\n" /* line 2918 */
        "jne .Lf91c42_00091ce9\n"
        "movl -0x30(%ebp), %eax\n" /* line 2921 | value */
        "movl $0, 4(%eax)\n"
        "movl var_typename(, %esi, 4), %eax\n" /* line 2948 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021cea0, (%esp)\n" /* "type %s is not a float" */
        "calll va\n"
        "movl %eax, 8(%ebp)\n" /* value */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2954 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_Error\n" /* line 2948 */
        /* { scope 2 */
        ".Lf91c42_00091d38:\n"
        "cmpl $4, %eax\n" /* line 1946 */
        "jne .Lf91c42_00091d00\n"
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf91c42_00091d00\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf91c42_00091d67\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        "jmp .Lf91c42_00091d00\n"
        ".Lf91c42_00091d58:\n"
        "subl $1, %eax\n" /* line 1946 */
        "jne .Lf91c42_00091d00\n"
        "movl %edx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "jmp .Lf91c42_00091d00\n"
        ".Lf91c42_00091d67:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "jmp .Lf91c42_00091d00\n"
    );
}

/* line 1717 */
__attribute__((naked))
JCOEF FreeValue(unsigned int id)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1717 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* id */
        /* { scope 1 */
        "shll $4, %eax\n" /* line 1721 */
        "leal scrVarGlob(%eax), %edi\n" /* entryValue */
        "movl 4(%edi), %edx\n" /* line 1727 | entryValue */
        "movl 8(%edi), %eax\n" /* entryValue, type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 2 */
        "cmpl $3, %eax\n" /* line 1946 */
        "jg .Lf91d7a_00091e23\n"
        "cmpl $2, %eax\n"
        "jl .Lf91d7a_00091e46\n"
        "movl %edx, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        /* } scope */
        /* { scope 2 */
        ".Lf91d7a_00091db2:\n"
        "movzwl 0xc(%edi), %ebx\n" /* line 1578 | index */
        "movzwl %bx, %ecx\n" /* line 1579 | index */
        "shll $4, %ecx\n"
        "addl $scrVarGlob, %ecx\n"
        "movzwl 2(%ecx), %edx\n" /* line 1581 */
        "movzwl 0xe(%edi), %esi\n" /* line 1582 | nextSiblingIndex */
        "movzwl %si, %eax\n" /* line 1583 | nextSiblingIndex */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+2(%eax)\n"
        "shll $4, %edx\n" /* line 1584 */
        "movzwl scrVarGlob(%edx), %eax\n"
        "shll $4, %eax\n"
        "movw %si, scrVarGlob+14(%eax)\n" /* nextSiblingIndex */
        "movl $0, 8(%edi)\n" /* line 1586 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1587 */
        "movw %ax, 4(%edi)\n"
        "movw $0, 2(%ecx)\n" /* line 1588 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1590 */
        "shll $4, %eax\n"
        "movw %bx, scrVarGlob+2(%eax)\n" /* index */
        "movw %bx, scrVarGlob+4\n" /* line 1591 | index */
        /* } scope */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 1734 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf91d7a_00091e23:\n"
        "cmpl $4, %eax\n" /* line 1946 */
        "jne .Lf91d7a_00091db2\n"
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf91d7a_00091db2\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf91d7a_00091e5c\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        "jmp .Lf91d7a_00091db2\n"
        ".Lf91d7a_00091e46:\n"
        "subl $1, %eax\n" /* line 1946 */
        "jne .Lf91d7a_00091db2\n"
        "movl %edx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "jmp .Lf91d7a_00091db2\n"
        ".Lf91d7a_00091e5c:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "jmp .Lf91d7a_00091db2\n"
    );
}

/* line 2400 */
__attribute__((naked))
JCOEF SetVariableValue(unsigned int id, VariableValue *value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2400 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* id */
        "movl 0xc(%ebp), %esi\n" /* value */
        /* { scope 1 */
        "shll $4, %eax\n" /* line 2409 */
        "leal scrVarGlob(%eax), %ebx\n" /* entryValue */
        "movl 4(%ebx), %ecx\n" /* line 2414 | entryValue */
        "movl 8(%ebx), %eax\n" /* entryValue */
        "movl %eax, %edx\n" /* type */
        "andl $0x1f, %edx\n" /* type */
        /* { scope 2 */
        "cmpl $3, %edx\n" /* line 1946 */
        "jg .Lf91e72_00091ec1\n"
        "cmpl $2, %edx\n"
        "jl .Lf91e72_00091ee4\n"
        "movl %ecx, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        "movl 8(%ebx), %eax\n"
        /* } scope */
        ".Lf91e72_00091ea9:\n"
        "andl $0xffffffe0, %eax\n" /* line 2416 */
        "movl %eax, 8(%ebx)\n" /* entryValue */
        "orl 4(%esi), %eax\n" /* line 2417 | value */
        "movl %eax, 8(%ebx)\n" /* entryValue */
        "movl (%esi), %eax\n" /* line 2418 | value */
        "movl %eax, 4(%ebx)\n" /* entryValue */
        /* } scope */
        "addl $0x10, %esp\n" /* line 2419 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf91e72_00091ec1:\n"
        "cmpl $4, %edx\n" /* line 1946 */
        "jne .Lf91e72_00091ea9\n"
        "cmpb $0, -1(%ecx)\n" /* line 1901 */
        "jne .Lf91e72_00091ea9\n"
        "leal -4(%ecx), %edx\n" /* line 1916 */
        "movzwl -4(%ecx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf91e72_00091ef6\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%ecx)\n"
        "movl 8(%ebx), %eax\n"
        "jmp .Lf91e72_00091ea9\n"
        ".Lf91e72_00091ee4:\n"
        "subl $1, %edx\n" /* line 1946 */
        "jne .Lf91e72_00091ea9\n"
        "movl %ecx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "movl 8(%ebx), %eax\n"
        "jmp .Lf91e72_00091ea9\n"
        ".Lf91e72_00091ef6:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %edx, (%esp)\n"
        "calll MT_Free\n"
        "movl 8(%ebx), %eax\n"
        "jmp .Lf91e72_00091ea9\n"
    );
}

/* line 2482 */
__attribute__((naked))
JCOEF ClearVariableValue(unsigned int id)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2482 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %eax\n" /* id */
        /* { scope 1 */
        "shll $4, %eax\n" /* line 2488 */
        "leal scrVarGlob(%eax), %ebx\n" /* entryValue */
        "movl 4(%ebx), %ecx\n" /* line 2493 | entryValue */
        "movl 8(%ebx), %edx\n" /* entryValue */
        "movl %edx, %eax\n" /* type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 2 */
        "cmpl $3, %eax\n" /* line 1946 */
        "jg .Lf91f0c_00091f4b\n"
        "cmpl $2, %eax\n"
        "jl .Lf91f0c_00091f6e\n"
        "movl %ecx, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        "movl 8(%ebx), %edx\n"
        /* } scope */
        ".Lf91f0c_00091f3f:\n"
        "andl $0xffffffe0, %edx\n" /* line 2495 */
        "movl %edx, 8(%ebx)\n" /* entryValue */
        /* } scope */
        "addl $0x14, %esp\n" /* line 2497 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf91f0c_00091f4b:\n"
        "cmpl $4, %eax\n" /* line 1946 */
        "jne .Lf91f0c_00091f3f\n"
        "cmpb $0, -1(%ecx)\n" /* line 1901 */
        "jne .Lf91f0c_00091f3f\n"
        "leal -4(%ecx), %edx\n" /* line 1916 */
        "movzwl -4(%ecx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf91f0c_00091f80\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%ecx)\n"
        "movl 8(%ebx), %edx\n"
        "jmp .Lf91f0c_00091f3f\n"
        ".Lf91f0c_00091f6e:\n"
        "subl $1, %eax\n" /* line 1946 */
        "jne .Lf91f0c_00091f3f\n"
        "movl %ecx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "movl 8(%ebx), %edx\n"
        "jmp .Lf91f0c_00091f3f\n"
        ".Lf91f0c_00091f80:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %edx, (%esp)\n"
        "calll MT_Free\n"
        "movl 8(%ebx), %edx\n"
        "jmp .Lf91f0c_00091f3f\n"
    );
}

/* line 4070 */
__attribute__((naked))
JCOEF ClearArray(unsigned int parentId, VariableValue *value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4070 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %eax\n" /* parentId */
        "movl 0xc(%ebp), %edx\n" /* value */
        "movl %edx, -0x3c(%ebp)\n" /* value */
        /* { scope 1 */
        "cmpl $0xfffe, %eax\n" /* line 4079 */
        "je .Lf91f96_00091ffc\n"
        "shll $4, %eax\n" /* line 4113 */
        "addl $scrVarGlob, %eax\n"
        "movl %eax, -0x34(%ebp)\n" /* parentValue */
        "movl 8(%eax), %ebx\n" /* line 4116 | id */
        "andl $0x1f, %ebx\n" /* id */
        "movl 4(%eax), %esi\n" /* line 4117 | varValue */
        ".Lf91f96_00091fc3:\n"
        "cmpl $1, %ebx\n" /* line 4121 | id */
        "je .Lf91f96_000920bd\n"
        ".Lf91f96_00091fcc:\n"
        "movl $1, scrVarPub+20\n" /* line 4126 */
        "movl var_typename(, %ebx, 4), %eax\n" /* line 4127 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021d560, (%esp)\n" /* "%s is not an array" */
        "calll va\n"
        "movl %eax, 8(%ebp)\n" /* parentId */
        /* } scope */
        ".Lf91f96_00091ff0:\n"
        "addl $0x4c, %esp\n" /* line 4172 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_Error\n" /* line 4127 */
        ".Lf91f96_00091ffc:\n"
        "movl scrVarPub+64, %eax\n" /* line 4081 */
        "shll $4, %eax\n"
        "addl $scrVarGlob, %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* entValue */
        "movl 8(%eax), %edi\n" /* line 4084 | parentId */
        "shrl $8, %edi\n" /* parentId */
        "movl scrVarPub+68, %esi\n" /* line 1980 | nextSiblingIndex */
        "addl $0x00800000, %esi\n" /* nextSiblingIndex */
        "andl $0x00FFFFFF, %esi\n" /* nextSiblingIndex */
        "leal (%edi, %edi, 2), %eax\n" /* line 801 | entry */
        "movzwl g_classMap(, %eax, 4), %ecx\n" /* index */
        "addl %esi, %ecx\n" /* name, index */
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n" /* index */
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n" /* index */
        "addl $1, %ecx\n" /* index */
        "movzwl %cx, %ecx\n" /* index */
        /* { scope 2: entry */
        /* { scope 3: name */
        "movl %ecx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl %edx, -0x2c(%ebp)\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ebx\n" /* newEntryValue */
        "movl 8(%ebx), %edx\n" /* line 748 | newEntryValue */
        "movl %edx, %eax\n"
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf91f96_000921a2\n"
        ".Lf91f96_0009207e:\n"
        "xorl %ecx, %ecx\n" /* line 759 */
        /* } scope */
        /* } scope */
        ".Lf91f96_00092080:\n"
        "shll $4, %ecx\n" /* line 1986 */
        "movzwl scrVarGlob(%ecx), %eax\n"
        "movzwl %ax, %edx\n"
        "testw %ax, %ax\n" /* line 4085 */
        "jne .Lf91f96_00092147\n"
        /* { scope 2: entry */
        ".Lf91f96_00092096:\n"
        "xorl %ebx, %ebx\n" /* line 1922 | id */
        "jmp .Lf91f96_00091fcc\n"
        /* } scope */
        ".Lf91f96_0009209d:\n"
        "shll $4, %eax\n" /* line 4092 */
        "cmpw $0, scrVarGlob+4(%eax)\n"
        "je .Lf91f96_000925f3\n"
        ".Lf91f96_000920ae:\n"
        "movl %esi, (%esp)\n" /* line 1949 | nextSiblingIndex */
        "calll RemoveRefToObject\n"
        "movl $0, -0x34(%ebp)\n" /* parentValue */
        ".Lf91f96_000920bd:\n"
        "movl %esi, -0x38(%ebp)\n" /* line 4131 | varValue */
        "movl %esi, %eax\n" /* varValue */
        "shll $4, %eax\n"
        "addl $scrVarGlob, %eax\n"
        "movl 8(%eax), %edx\n" /* line 4136 */
        "andl $0x1f, %edx\n"
        "cmpl $0x16, %edx\n"
        "je .Lf91f96_00092105\n"
        "movl $1, scrVarPub+20\n" /* line 4138 */
        "movl var_typename(, %edx, 4), %eax\n" /* line 4139 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021d560, (%esp)\n" /* "%s is not an array" */
        "calll va\n"
        "movl %eax, 8(%ebp)\n" /* parentId */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 4172 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Scr_Error\n" /* line 4127 */
        ".Lf91f96_00092105:\n"
        "cmpw $0, 4(%eax)\n" /* line 4143 */
        "jne .Lf91f96_000921fc\n"
        ".Lf91f96_00092110:\n"
        "movl -0x3c(%ebp), %edx\n" /* line 4153 | value */
        "movl 4(%edx), %eax\n"
        "cmpl $6, %eax\n"
        "je .Lf91f96_000922e7\n"
        "cmpl $2, %eax\n" /* line 4164 */
        "je .Lf91f96_00092360\n"
        "movl var_typename(, %eax, 4), %eax\n" /* line 4171 */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021d4b4, (%esp)\n" /* "%s is not an array index" */
        "calll va\n"
        "movl %eax, 8(%ebp)\n" /* parentId */
        "jmp .Lf91f96_00091ff0\n"
        ".Lf91f96_00092147:\n"
        "shll $4, %edx\n" /* line 4087 */
        "movl scrVarGlob+4(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x30(%ebp), %ecx\n" /* entValue */
        "movzwl 6(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* parentId */
        "calll GetEntityFieldValue\n"
        "movl %eax, %esi\n" /* varValue */
        "movl %edx, %ebx\n" /* id */
        "testl %edx, %edx\n" /* line 4088 */
        "je .Lf91f96_00092096\n"
        "cmpl $1, %edx\n" /* line 4090 */
        "je .Lf91f96_0009209d\n"
        "cmpl $3, %edx\n" /* line 1946 */
        "jg .Lf91f96_000924d3\n"
        "cmpl $2, %edx\n"
        "jl .Lf91f96_00092611\n"
        "movl %eax, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        ".Lf91f96_00092196:\n"
        "movl $0, -0x34(%ebp)\n" /* parentValue */
        "jmp .Lf91f96_00091fc3\n"
        /* { scope 2: entry */
        /* { scope 3: name */
        ".Lf91f96_000921a2:\n"
        "shrl $8, %edx\n" /* line 752 */
        "cmpl %edx, %esi\n"
        "je .Lf91f96_00092080\n"
        "movzwl 0xc(%ebx), %ecx\n" /* line 757 | newEntryValue */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x2c(%ebp)\n" /* line 759 | entry */
        "je .Lf91f96_0009207e\n"
        ".Lf91f96_000921c5:\n"
        "movzwl scrVarGlob(%edx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edx\n"
        "movl 8(%edx), %eax\n" /* line 766 */
        "shrl $8, %eax\n"
        "cmpl %esi, %eax\n"
        "je .Lf91f96_00092080\n"
        "movzwl 0xc(%edx), %ecx\n" /* line 771 */
        "movl %ecx, %edx\n" /* line 758 */
        "shll $4, %edx\n"
        "leal scrVarGlob(%edx), %eax\n"
        "cmpl %eax, -0x2c(%ebp)\n" /* line 759 | entry */
        "jne .Lf91f96_000921c5\n"
        "jmp .Lf91f96_0009207e\n"
        /* } scope */
        /* } scope */
        ".Lf91f96_000921fc:\n"
        "movl %esi, (%esp)\n" /* line 4146 | varValue */
        "calll RemoveRefToObject\n"
        "movzwl scrVarGlob+4, %eax\n" /* line 1503 */
        "movw %ax, -0x24(%ebp)\n"
        "testw %ax, %ax\n" /* line 1504 */
        "je .Lf91f96_0009250e\n"
        ".Lf91f96_00092218:\n"
        "movzwl -0x24(%ebp), %edx\n" /* line 1507 */
        "shll $4, %edx\n"
        "movl %edx, -0x40(%ebp)\n"
        "movl %edx, %ebx\n" /* newEntryValue */
        "addl $scrVarGlob, %ebx\n" /* newEntryValue */
        "movzwl scrVarGlob(%edx), %ecx\n" /* line 1508 */
        "movw %cx, -0x26(%ebp)\n"
        "movzwl %cx, %eax\n"
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movzwl 4(%ecx), %eax\n" /* line 1511 */
        "movw %ax, -0x22(%ebp)\n"
        "cmpl %ecx, %ebx\n" /* line 1514 | newEntryValue */
        "je .Lf91f96_0009228c\n"
        "testb $0x60, 8(%ebx)\n" /* newEntryValue */
        "jne .Lf91f96_00092505\n"
        "movzwl 0xc(%ebx), %edx\n" /* line 1518 | newEntryValue */
        "shll $4, %edx\n"
        "movzwl -0x26(%ebp), %eax\n"
        "movw %ax, scrVarGlob(%edx)\n"
        "movl -0x24(%ebp), %eax\n" /* line 1519 */
        "movl -0x40(%ebp), %edx\n"
        "movw %ax, scrVarGlob(%edx)\n"
        "movzwl 0xc(%ebx), %edx\n" /* line 1520 | newEntryValue */
        "movw %dx, 0xc(%ecx)\n"
        "movzwl 4(%ebx), %eax\n" /* line 1521 | newEntryValue */
        "movw %ax, 4(%ecx)\n"
        "movl %ebx, %ecx\n" /* newEntryValue */
        "movzwl -0x22(%ebp), %eax\n"
        ".Lf91f96_0009228c:\n"
        "movw %ax, scrVarGlob+4\n" /* line 1526 */
        "movzwl %ax, %eax\n" /* line 1527 */
        "shll $4, %eax\n"
        "movw $0, scrVarGlob+2(%eax)\n"
        "movl -0x24(%ebp), %edx\n" /* line 1529 */
        "movw %dx, 0xc(%ecx)\n"
        "movw %dx, 0xe(%ecx)\n" /* line 1530 */
        "movw %dx, 2(%ebx)\n" /* line 1531 | newEntryValue */
        "movzwl (%ebx), %ebx\n" /* line 1657 | index */
        "movl %ebx, %eax\n" /* line 1658 | index */
        "shll $4, %eax\n"
        "addl $scrVarGlob, %eax\n"
        "movl $0x76, 8(%eax)\n" /* line 1661 */
        "movw $0, 4(%eax)\n" /* line 1662 */
        "movw $0, 6(%eax)\n" /* line 1663 */
        "movl %ebx, %esi\n" /* line 4147 | id, varValue */
        "movl %ebx, %edx\n" /* line 4148 | id */
        "movl -0x38(%ebp), %eax\n"
        "calll CopyArray\n"
        "movl -0x34(%ebp), %ecx\n" /* line 4150 | parentValue */
        "movl %ebx, 4(%ecx)\n" /* id */
        "jmp .Lf91f96_00092110\n"
        ".Lf91f96_000922e7:\n"
        "movl (%edx), %edx\n" /* line 4155 */
        "leal vq8+462882(%edx), %eax\n"
        "cmpl $pushed+2177, %eax\n"
        "ja .Lf91f96_0009251f\n"
        "movl %esi, %edi\n" /* line 4157 | varValue, parentId */
        "leal s_debugFrameGlob+57728(%edx), %esi\n" /* line 2310 | nextSiblingIndex */
        "andl $0x00FFFFFF, %esi\n" /* nextSiblingIndex */
        /* { scope 2: entry */
        /* { scope 3: name */
        "leal (%edi, %esi), %ecx\n" /* line 801 | entry, index */
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n" /* index */
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n" /* index */
        "addl $1, %ecx\n" /* index */
        "movzwl %cx, %edx\n" /* index */
        /* { scope 4: entry */
        /* { scope 5 */
        "movl %edx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movl %ecx, -0x20(%ebp)\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movl 8(%ecx), %ebx\n" /* line 748 | newEntryValue */
        "movl %ebx, %eax\n" /* newEntryValue */
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "je .Lf91f96_00092537\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf91f96_00092358:\n"
        "addl $0x4c, %esp\n" /* line 4172 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf91f96_00092360:\n"
        "movl -0x3c(%ebp), %edx\n" /* line 4166 | value */
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SL_RemoveRefToString\n"
        "movl -0x3c(%ebp), %ecx\n" /* line 4167 | value */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n" /* name */
        /* { scope 2: entry */
        /* { scope 3: name */
        "addl %esi, %ecx\n" /* line 801 | name, index */
        "movl $0x80018005, %edx\n"
        "movl %ecx, %eax\n" /* index */
        "mull %edx\n"
        "shrl $0xf, %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "subl %eax, %ecx\n" /* index */
        "addl $1, %ecx\n" /* index */
        "movzwl %cx, %edx\n" /* index */
        /* { scope 4: entry */
        /* { scope 5 */
        "movl %edx, %eax\n" /* line 745 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %edi\n" /* entry */
        "movzwl scrVarGlob(%eax), %eax\n" /* line 746 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ecx\n"
        "movl 8(%ecx), %ebx\n" /* line 748 | newEntryValue */
        "movl %ebx, %eax\n" /* newEntryValue */
        "andl $0x60, %eax\n"
        "cmpl $0x40, %eax\n"
        "jne .Lf91f96_00092358\n"
        "shrl $8, %ebx\n" /* line 752 | newEntryValue */
        "cmpl %ebx, -0x1c(%ebp)\n" /* newEntryValue, name */
        "je .Lf91f96_00092413\n"
        "movzwl 0xc(%ecx), %edx\n" /* line 757 */
        "movl %edx, %ecx\n" /* line 758 */
        "shll $4, %ecx\n"
        "leal scrVarGlob(%ecx), %eax\n"
        "cmpl %eax, %edi\n" /* line 759 | entry */
        "je .Lf91f96_00092358\n"
        "movzwl scrVarGlob(%ecx), %eax\n" /* line 761 */
        "jmp .Lf91f96_000923ff\n"
        ".Lf91f96_000923e1:\n"
        "movzwl 0xc(%ebx), %edx\n" /* line 771 | newEntryValue */
        "movl %edx, %ebx\n" /* line 772 | newEntryValue */
        "shll $4, %ebx\n" /* newEntryValue */
        "leal scrVarGlob(%ebx), %eax\n" /* newEntryValue */
        "cmpl %eax, %edi\n" /* line 759 | entry */
        "je .Lf91f96_00092358\n"
        "movzwl scrVarGlob(%ebx), %eax\n" /* line 761 | newEntryValue */
        ".Lf91f96_000923ff:\n"
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ebx\n" /* newEntryValue */
        "movl 8(%ebx), %eax\n" /* line 766 | newEntryValue */
        "shrl $8, %eax\n"
        "cmpl %eax, -0x1c(%ebp)\n" /* name */
        "jne .Lf91f96_000923e1\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf91f96_00092413:\n"
        "testl %edx, %edx\n" /* line 2329 */
        "je .Lf91f96_00092358\n"
        "shll $4, %edx\n" /* line 2332 */
        "leal scrVarGlob(%edx), %eax\n"
        "movzwl scrVarGlob(%edx), %ebx\n" /* line 2333 | id */
        "shll $4, %esi\n" /* line 2336 | parentId */
        "leal scrVarGlob(%esi), %edx\n" /* parentId */
        ".Lf91f96_00092434:\n"
        "calll MakeVariableExternal\n"
        /* { scope 3: name */
        "shll $4, %ebx\n" /* line 1721 | index */
        "leal scrVarGlob(%ebx), %edi\n" /* index, entryValue */
        "movl 4(%edi), %edx\n" /* line 1727 | entryValue */
        "movl 8(%edi), %eax\n" /* entryValue, type */
        "andl $0x1f, %eax\n" /* type */
        /* { scope 4: entry */
        "cmpl $3, %eax\n" /* line 1946 */
        "jg .Lf91f96_000925c8\n"
        "cmpl $2, %eax\n"
        "jl .Lf91f96_0009261f\n"
        "movl %edx, (%esp)\n" /* line 1953 */
        "calll SL_RemoveRefToString\n"
        /* } scope */
        /* { scope 4: entry */
        /* { scope 5 */
        ".Lf91f96_00092465:\n"
        "movzwl 0xc(%edi), %ebx\n" /* line 1578 | entry, index */
        "movzwl %bx, %ecx\n" /* line 1579 | index */
        "shll $4, %ecx\n"
        "addl $scrVarGlob, %ecx\n"
        "movzwl 2(%ecx), %edx\n" /* line 1581 */
        "movzwl 0xe(%edi), %esi\n" /* line 1582 | entry, nextSiblingIndex */
        "movzwl %si, %eax\n" /* line 1583 | nextSiblingIndex */
        "shll $4, %eax\n"
        "movw %dx, scrVarGlob+2(%eax)\n"
        "shll $4, %edx\n" /* line 1584 */
        "movzwl scrVarGlob(%edx), %eax\n"
        "shll $4, %eax\n"
        "movw %si, scrVarGlob+14(%eax)\n" /* nextSiblingIndex */
        "movl $0, 8(%edi)\n" /* line 1586 | entry */
        "movzwl scrVarGlob+4, %eax\n" /* line 1587 */
        "movw %ax, 4(%edi)\n" /* entry */
        "movw $0, 2(%ecx)\n" /* line 1588 */
        "movzwl scrVarGlob+4, %eax\n" /* line 1590 */
        "shll $4, %eax\n"
        "movw %bx, scrVarGlob+2(%eax)\n" /* index */
        "movw %bx, scrVarGlob+4\n" /* line 1591 | index */
        "jmp .Lf91f96_00092358\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf91f96_000924d3:\n"
        "cmpl $4, %edx\n" /* line 1946 */
        "jne .Lf91f96_00092196\n"
        "movl %eax, %edx\n" /* line 1956 | vectorValue */
        /* { scope 2: entry */
        "cmpb $0, -1(%eax)\n" /* line 1901 */
        "jne .Lf91f96_000924fb\n"
        "leal -4(%eax), %ecx\n" /* line 1916 */
        "movzwl -4(%eax), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf91f96_00092635\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        /* } scope */
        /* { scope 2: entry */
        /* { scope 3: name */
        /* { scope 4: entry */
        /* { scope 5 */
        ".Lf91f96_000924fb:\n"
        "movl $4, %ebx\n" /* line 766 | newEntryValue */
        "jmp .Lf91f96_00091fcc\n"
        ".Lf91f96_00092505:\n"
        "movzwl -0x22(%ebp), %eax\n"
        "jmp .Lf91f96_0009228c\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf91f96_0009250e:\n"
        "movl $str_0021d3d8, (%esp)\n" /* line 1505 */
        "calll Scr_TerminalError\n"
        "jmp .Lf91f96_00092218\n"
        ".Lf91f96_0009251f:\n"
        "movl %edx, 4(%esp)\n" /* line 4160 */
        "movl $str_0021d498, (%esp)\n" /* "array index %d out of range" */
        "calll va\n"
        "movl %eax, 8(%ebp)\n" /* parentId */
        "jmp .Lf91f96_00091ff0\n"
        /* { scope 2: entry */
        /* { scope 3: name */
        /* { scope 4: entry */
        /* { scope 5 */
        ".Lf91f96_00092537:\n"
        "shrl $8, %ebx\n" /* line 752 | newEntryValue */
        "cmpl %ebx, %esi\n" /* newEntryValue */
        "je .Lf91f96_000925a2\n"
        "movzwl 0xc(%ecx), %edx\n" /* line 757 */
        "movl %edx, %ecx\n" /* line 758 */
        "shll $4, %ecx\n"
        "leal scrVarGlob(%ecx), %eax\n"
        "cmpl %eax, -0x20(%ebp)\n" /* line 759 | entry */
        "je .Lf91f96_00092358\n"
        "movzwl scrVarGlob(%ecx), %eax\n" /* line 761 */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ebx\n" /* newEntryValue */
        "movl 8(%ebx), %eax\n" /* line 766 | newEntryValue */
        "shrl $8, %eax\n"
        "cmpl %eax, %esi\n"
        "je .Lf91f96_000925a2\n"
        ".Lf91f96_00092570:\n"
        "movzwl 0xc(%ebx), %edx\n" /* line 771 | newEntryValue */
        "movl %edx, %ebx\n" /* line 772 | newEntryValue */
        "shll $4, %ebx\n" /* newEntryValue */
        "leal scrVarGlob(%ebx), %eax\n" /* newEntryValue */
        "cmpl %eax, -0x20(%ebp)\n" /* line 759 | entry */
        "je .Lf91f96_00092358\n"
        "movzwl scrVarGlob(%ebx), %eax\n" /* line 761 | newEntryValue */
        "shll $4, %eax\n"
        "leal scrVarGlob(%eax), %ebx\n" /* newEntryValue */
        "movl 8(%ebx), %eax\n" /* line 766 | newEntryValue */
        "shrl $8, %eax\n"
        "cmpl %esi, %eax\n"
        "jne .Lf91f96_00092570\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf91f96_000925a2:\n"
        "testl %edx, %edx\n" /* line 2329 */
        "je .Lf91f96_00092358\n"
        "shll $4, %edx\n" /* line 2332 */
        "leal scrVarGlob(%edx), %eax\n"
        "movzwl scrVarGlob(%edx), %ebx\n" /* line 2333 | id */
        "shll $4, %edi\n" /* line 2336 | parentId */
        "leal scrVarGlob(%edi), %edx\n" /* parentId */
        "jmp .Lf91f96_00092434\n"
        /* } scope */
        /* { scope 2: entry */
        /* { scope 3: name */
        /* { scope 4: entry */
        ".Lf91f96_000925c8:\n"
        "cmpl $4, %eax\n" /* line 1946 */
        "jne .Lf91f96_00092465\n"
        "cmpb $0, -1(%edx)\n" /* line 1901 */
        "jne .Lf91f96_00092465\n"
        "leal -4(%edx), %ecx\n" /* line 1916 */
        "movzwl -4(%edx), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf91f96_0009264f\n"
        "subl $1, %eax\n" /* line 1918 */
        "movw %ax, -4(%edx)\n"
        "jmp .Lf91f96_00092465\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf91f96_000925f3:\n"
        "movl %esi, (%esp)\n" /* line 1949 | nextSiblingIndex */
        "calll RemoveRefToObject\n"
        "movl $1, scrVarPub+20\n" /* line 4095 */
        "movl $str_0021d5b4, 8(%ebp)\n" /* line 4096 | parentId */
        "jmp .Lf91f96_00091ff0\n"
        ".Lf91f96_00092611:\n"
        "cmpl $1, %edx\n" /* line 1946 */
        "jne .Lf91f96_00092196\n"
        "jmp .Lf91f96_000920ae\n"
        /* { scope 2: entry */
        /* { scope 3: name */
        /* { scope 4: entry */
        ".Lf91f96_0009261f:\n"
        "subl $1, %eax\n"
        "jne .Lf91f96_00092465\n"
        "movl %edx, (%esp)\n" /* line 1949 */
        "calll RemoveRefToObject\n"
        "jmp .Lf91f96_00092465\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: entry */
        ".Lf91f96_00092635:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        /* } scope */
        /* { scope 2: entry */
        /* { scope 3: name */
        /* { scope 4: entry */
        /* { scope 5 */
        "movl $4, %ebx\n" /* line 766 | newEntryValue */
        "jmp .Lf91f96_00091fcc\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: entry */
        /* { scope 3: name */
        /* { scope 4: entry */
        ".Lf91f96_0009264f:\n"
        "movl $0x10, 4(%esp)\n" /* line 1922 */
        "movl %ecx, (%esp)\n"
        "calll MT_Free\n"
        "jmp .Lf91f96_00092465\n"
    );
}

#else
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
#endif
